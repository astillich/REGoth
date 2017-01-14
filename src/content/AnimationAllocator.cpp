//
// Created by desktop on 28.07.16.
//

#include "AnimationAllocator.h"
#include <utils/logger.h>

Animations::AnimationAllocator::AnimationAllocator(const VDFS::FileIndex *vdfidx)
{

}

Animations::AnimationAllocator::~AnimationAllocator()
{

}

Handle::AnimationHandle Animations::AnimationAllocator::loadAnimationVDF(const VDFS::FileIndex& idx, const std::string& name)
{
    // Check if this was already loaded
    auto it = m_AnimationsByName.find(name);
    if (it != m_AnimationsByName.end())
        return (*it).second;

	//LogInfo() << "New animation: " << name;

    ZenLoad::zCModelAni zani;
    zani.setScale(1.0f / 100.0f);

    if(!zani.loadMAN(idx, name + ".MAN"))
		return Handle::AnimationHandle::makeInvalidHandle();

    Handle::AnimationHandle h = m_Allocator.createObject();
    Animation& aniObject = m_Allocator.getElement(h);
    aniObject.animation = zani;

    m_AnimationsByName[name] = h;

    return h;
}

Handle::AnimationHandle Animations::AnimationAllocator::loadAnimationVDF(const std::string& name)
{
    if (!m_pVDFSIndex)
        return Handle::AnimationHandle::makeInvalidHandle();

    return loadAnimationVDF(*m_pVDFSIndex, name);
}
