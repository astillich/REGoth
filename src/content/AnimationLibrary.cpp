#include <algorithm>
#include <engine/BaseEngine.h>
#include <engine/World.h>
#include <vdfs/fileIndex.h>
#include <utils/logger.h>
#include <zenload/modelAnimationParser.h>
#include <zenload/modelScriptParser.h>
#include <zenload/zenParser.h>

#include "content/AnimationLibrary.h"

using namespace Animations;
using namespace VDFS;
using namespace ZenLoad;

namespace Animations
{

AnimationLibrary::AnimationLibrary(World::WorldInstance &world)
    : m_World(world)
{
}

Animation &AnimationLibrary::getAnimation(Handle::AnimationHandle h)
{
    return m_World.getAnimationAllocator().getAnimation(h);
}

Handle::AnimationHandle AnimationLibrary::getAnimation(const std::string &qname)
{
    return m_World.getAnimationAllocator().getAnimation(qname);
}

Handle::AnimationHandle AnimationLibrary::getAnimation(const std::string &mesh_lib, const std::string &overlay, const std::string &name)
{
    std::string qname = makeQualifiedName(mesh_lib, overlay, name);
    return getAnimation(qname);
}

AnimationData &AnimationLibrary::getAnimationData(Handle::AnimationDataHandle h)
{
    return m_World.getAnimationDataAllocator().getAnimationData(h);
}

bool AnimationLibrary::loadAnimations()
{
    // both .MDS and .MSB, where .MDS has precedence
    std::map<std::string, bool> msb_loaded; // true = is MDS

    std::string ext_mds = ".MDS";
    std::string ext_msb = ".MSB";

    for (const FileInfo &fi : m_World.getEngine()->getVDFSIndex().getKnownFiles())
    {
        std::string fn = fi.fileName;
        std::transform(fn.begin(), fn.end(), fn.begin(), ::toupper);

        std::string n = fn.substr(0, fn.length() - 4);

        if (std::equal(ext_mds.rbegin(), ext_mds.rend(), fn.rbegin()))
        {
            ZenParser zen(fn, m_World.getEngine()->getVDFSIndex());
            ModelScriptTextParser p(zen);
            p.setStrict(false); // TODO: should be configurable
            if (!loadModelScript(fn, p))
                ; //return false;

            // MDS always overwrites
            msb_loaded[n] = true;

        } else
        if (std::equal(ext_msb.rbegin(), ext_msb.rend(), fn.rbegin()))
        {
            auto it = msb_loaded.find(n);
            if (it != msb_loaded.end() && it->second == true)
            {
                // an MDS was loaded before
                continue;
            }

            ZenParser zen(fn, m_World.getEngine()->getVDFSIndex());
            ModelScriptBinParser p(zen);
            if (!loadModelScript(fn, p))
                ; //return false;

            msb_loaded[n] = false;
        } else
            continue;

    }

    return true;
}

Handle::AnimationDataHandle AnimationLibrary::loadMAN(const std::string &name)
{
    std::string file_name = name + ".MAN";
    std::transform(file_name.begin(), file_name.end(), file_name.begin(), ::toupper);

    Handle::AnimationDataHandle h = m_World.getAnimationDataAllocator().getAnimationData(name);
    if (h.isValid())
        return h;

    const VDFS::FileIndex& idx = m_World.getEngine()->getVDFSIndex();
    if (!idx.hasFile(file_name))
    {
        LogError() << "MAN file " << file_name << " does not exist";
        return Handle::AnimationDataHandle::makeInvalidHandle();
    }

    h = m_World.getAnimationDataAllocator().allocate(name);
    AnimationData &data = m_World.getAnimationDataAllocator().getAnimationData(h);

    ZenParser zen(file_name, idx);
    ModelAnimationParser p(zen);
    p.setScale(1.0f / 100.0f);

    ModelAnimationParser::EChunkType type;
    while ((type = p.parse()) != ModelAnimationParser::CHUNK_EOF)
    {
        switch (type)
        {
        case ModelAnimationParser::CHUNK_HEADER:
            data.m_Header = p.getHeader();
            break;
        case ModelAnimationParser::CHUNK_RAWDATA:
            data.m_NodeIndexList = p.getNodeIndex();
            data.m_Samples = p.getSamples();
            break;
        case ModelAnimationParser::CHUNK_ERROR:
            return Handle::AnimationDataHandle::makeInvalidHandle();
        }
    }

    return h;
}

bool AnimationLibrary::loadModelScript(const std::string &file_name, ModelScriptParser &p)
{
    LogInfo() << "load model script " << file_name;

    ssize_t name_end = file_name.rfind('.');
    std::string name = file_name.substr(0, name_end);

    Animation *anim = nullptr;

    ModelScriptParser::EChunkType type;
    while ((type = p.parse()) != ModelScriptParser::CHUNK_EOF)
    {
        switch (type)
        {
        case ModelScriptParser::CHUNK_ANI:
            {
                std::string qname = name + '-' + p.ani().m_Name;
                auto h = m_World.getAnimationAllocator().allocate(qname);
                anim = &m_World.getAnimationAllocator().getAnimation(h);
                anim->m_Name = p.ani().m_Name;
                anim->m_Layer = p.ani().m_Layer;
                anim->m_NextName = p.ani().m_Next;
                anim->m_BlendIn = p.ani().m_BlendIn;
                anim->m_BlendOut = p.ani().m_BlendOut;
                anim->m_Flags = p.ani().m_Flags;
                anim->m_FirstFrame = p.ani().m_FirstFrame;
                anim->m_LastFrame = p.ani().m_FirstFrame;

                anim->m_Data = loadMAN(qname);
                if (!anim->m_Data.isValid())
                    return false;

                auto &data = m_World.getAnimationDataAllocator().getAnimationData(anim->m_Data);
                anim->m_FpsRate = data.m_Header.fpsRate;
                anim->m_FrameCount = data.m_Header.numFrames;

                LogInfo() << "created animation '" << qname << "' id " << h.index;
            }
            break;
        case ModelScriptParser::CHUNK_ERROR:
            return false;
        }
    }

    return true;
}

std::string AnimationLibrary::makeQualifiedName(const std::string &mesh_lib, const std::string &overlay, const std::string &name)
{
    std::string umesh_lib = mesh_lib, uoverlay = overlay, uname = name;
    std::transform(umesh_lib.begin(), umesh_lib.end(), umesh_lib.begin(), ::toupper);
    std::transform(uoverlay.begin(), uoverlay.end(), uoverlay.begin(), ::toupper);
    std::transform(uname.begin(), uname.end(), uname.begin(), ::toupper);

    std::string qname;
    if (uoverlay.find(umesh_lib) != 0)
    {
        qname = umesh_lib + '_' + uoverlay + '-' + uname;
    } else
        qname = umesh_lib + '-' + uname;

    //LogInfo() << "qname '" << qname << "' '" << umesh_lib << "' '" << uoverlay << "' '" << uname << "'";

    return qname;
}

} // namespace Animations
