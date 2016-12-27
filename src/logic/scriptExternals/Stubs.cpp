//
// Created by andre on 05.06.16.
//

#include <utils/logger.h>
#include "Stubs.h"
#include <daedalus/DaedalusVM.h>

void ::Logic::ScriptExternals::registerStubs(Daedalus::DaedalusVM& vm, bool verbose)
{
    vm.registerExternalFunction("print", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "print";
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;

    });

    vm.registerExternalFunction("printmulti", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "printmulti";
        std::string s4 = vm.popString(); if(verbose) LogInfo() << "s4: " << s4;
        std::string s3 = vm.popString(); if(verbose) LogInfo() << "s3: " << s3;
        std::string s2 = vm.popString(); if(verbose) LogInfo() << "s2: " << s2;
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;

    });

    vm.registerExternalFunction("printdebug", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "printdebug";
        std::string s = vm.popString(); if(verbose) LogInfo() << "s: " << s;

    });

    vm.registerExternalFunction("printscreen", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "printscreen";
        int32_t timesec = vm.popDataValue(); if(verbose) LogInfo() << "timesec: " << timesec;
        std::string font = vm.popString(); if(verbose) LogInfo() << "font: " << font;
        int32_t posy = vm.popDataValue(); if(verbose) LogInfo() << "posy: " << posy;
        int32_t posx = vm.popDataValue(); if(verbose) LogInfo() << "posx: " << posx;
        std::string msg = vm.popString(); if(verbose) LogInfo() << "msg: " << msg;
        int32_t dialognr = vm.popDataValue(); if(verbose) LogInfo() << "dialognr: " << dialognr;

    });

    vm.registerExternalFunction("hlp_random", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_random";
        int32_t n0 = vm.popDataValue(); if(verbose) LogInfo() << "n0: " << n0;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_strcmp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_strcmp";
        std::string s2 = vm.popString(); if(verbose) LogInfo() << "s2: " << s2;
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_isvalidnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_isvalidnpc";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_isvaliditem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_isvaliditem";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_isitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_isitem";
        int32_t instancename = vm.popDataValue(); if(verbose) LogInfo() << "instancename: " << instancename;

        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_getnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_getnpc";
        int32_t instancename = vm.popDataValue(); if(verbose) LogInfo() << "instancename: " << instancename;
        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("hlp_getinstanceid", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_getinstanceid";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("hlp_getinstanceid", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_getinstanceid";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_wait", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_wait";
        float n1 = vm.popFloatValue(); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_getstatetime", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getstatetime";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_setstatetime", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setstatetime";
        int32_t seconds = vm.popDataValue(); if(verbose) LogInfo() << "seconds: " << seconds;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("wld_insertnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_insertnpc";
        std::string spawnpoint = vm.popString(); if(verbose) LogInfo() << "spawnpoint: " << spawnpoint;
        int32_t npcinstance = vm.popDataValue(); if(verbose) LogInfo() << "npcinstance: " << npcinstance;

    });

    vm.registerExternalFunction("wld_insertnpcandrespawn", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_insertnpcandrespawn";
        float spawndelay = vm.popFloatValue(); if(verbose) LogInfo() << "spawndelay: " << spawndelay;
        std::string spawnpoint = vm.popString(); if(verbose) LogInfo() << "spawnpoint: " << spawnpoint;
        int32_t instance = vm.popDataValue(); if(verbose) LogInfo() << "instance: " << instance;

    });

    vm.registerExternalFunction("ai_playani", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_playani";
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_standup", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_standup";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_standupquick", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_standupquick";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_quicklook", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_quicklook";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_lookat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_lookat";
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_lookatnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_lookatnpc";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_stoplookat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_stoplookat";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_pointat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_pointat";
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_pointatnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_pointatnpc";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_stoppointat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_stoppointat";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_takeitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_takeitem";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_dropitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_dropitem";
        int32_t itemid = vm.popDataValue(); if(verbose) LogInfo() << "itemid: " << itemid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_useitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_useitem";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_useitemtostate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_useitemtostate";
        int32_t state = vm.popDataValue(); if(verbose) LogInfo() << "state: " << state;
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_usemob", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_usemob";
        int32_t targetstate = vm.popDataValue(); if(verbose) LogInfo() << "targetstate: " << targetstate;
        std::string schemename = vm.popString(); if(verbose) LogInfo() << "schemename: " << schemename;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_ismobavailable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_ismobavailable";
        std::string schemename = vm.popString(); if(verbose) LogInfo() << "schemename: " << schemename;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_getmobstate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getmobstate";
        std::string schemename = vm.popString(); if(verbose) LogInfo() << "schemename: " << schemename;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_setwalkmode", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_setwalkmode";
        int32_t n0 = vm.popDataValue(); if(verbose) LogInfo() << "n0: " << n0;
        uint32_t arr_n;
        int32_t n = vm.popVar(arr_n); if(verbose) LogInfo() << "n: " << n;

    });

    vm.registerExternalFunction("ai_gotowp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotowp";
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_gotofp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotofp";
        std::string fpname = vm.popString(); if(verbose) LogInfo() << "fpname: " << fpname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_gotonextfp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotonextfp";
        std::string fpname = vm.popString(); if(verbose) LogInfo() << "fpname: " << fpname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_gotonpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotonpc";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_gotoitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotoitem";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_gotosound", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_gotosound";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_teleport", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_teleport";
        std::string waypoint = vm.popString(); if(verbose) LogInfo() << "waypoint: " << waypoint;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_getnearestwp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnearestwp";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn("");
    });

    vm.registerExternalFunction("npc_getnextwp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnextwp";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn("");
    });

    vm.registerExternalFunction("wld_isfpavailable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_isfpavailable";
        std::string fpname = vm.popString(); if(verbose) LogInfo() << "fpname: " << fpname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_isnextfpavailable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_isnextfpavailable";
        std::string fpname = vm.popString(); if(verbose) LogInfo() << "fpname: " << fpname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isonfp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isonfp";
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_iswayblocked", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_iswayblocked";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_turntonpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_turntonpc";
        uint32_t arr_n1;
        int32_t n1 = vm.popVar(arr_n1); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_turnaway", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_turnaway";
        uint32_t arr_n1;
        int32_t n1 = vm.popVar(arr_n1); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_whirlaround", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_whirlaround";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_turntosound", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_turntosound";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_aligntowp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_aligntowp";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_dodge", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_dodge";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;

    });

    vm.registerExternalFunction("mdl_applyoverlaymds", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_applyoverlaymds";
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("mdl_removeoverlaymds", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_removeoverlaymds";
        std::string overlayname = vm.popString(); if(verbose) LogInfo() << "overlayname: " << overlayname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("mdl_applyoverlaymdstimed", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_applyoverlaymdstimed";
        float timeticks = vm.popFloatValue(); if(verbose) LogInfo() << "timeticks: " << timeticks;
        std::string overlayname = vm.popString(); if(verbose) LogInfo() << "overlayname: " << overlayname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("mdl_applyrandomani", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_applyrandomani";
        std::string s2 = vm.popString(); if(verbose) LogInfo() << "s2: " << s2;
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("mdl_applyrandomanifreq", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_applyrandomanifreq";
        float f2 = vm.popFloatValue(); if(verbose) LogInfo() << "f2: " << f2;
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("mdl_startfaceani", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_startfaceani";
        float holdtime = vm.popFloatValue(); if(verbose) LogInfo() << "holdtime: " << holdtime;
        float intensity = vm.popFloatValue(); if(verbose) LogInfo() << "intensity: " << intensity;
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("mdl_applyrandomfaceani", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_applyrandomfaceani";
        float probmin = vm.popFloatValue(); if(verbose) LogInfo() << "probmin: " << probmin;
        float timemaxvar = vm.popFloatValue(); if(verbose) LogInfo() << "timemaxvar: " << timemaxvar;
        float timemax = vm.popFloatValue(); if(verbose) LogInfo() << "timemax: " << timemax;
        float timeminvar = vm.popFloatValue(); if(verbose) LogInfo() << "timeminvar: " << timeminvar;
        float timemin = vm.popFloatValue(); if(verbose) LogInfo() << "timemin: " << timemin;
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_getbodystate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getbodystate";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasbodyflag", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasbodyflag";
        int32_t bodyflag = vm.popDataValue(); if(verbose) LogInfo() << "bodyflag: " << bodyflag;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_playanibs", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_playanibs";
        int32_t bodystate = vm.popDataValue(); if(verbose) LogInfo() << "bodystate: " << bodystate;
        std::string aniname = vm.popString(); if(verbose) LogInfo() << "aniname: " << aniname;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;

    });

    vm.registerExternalFunction("npc_settofistmode", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_settofistmode";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_settofightmode", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_settofightmode";
        int32_t weapon = vm.popDataValue(); if(verbose) LogInfo() << "weapon: " << weapon;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_isinfightmode", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isinfightmode";
        int32_t fmode = vm.popDataValue(); if(verbose) LogInfo() << "fmode: " << fmode;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_drawweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_drawweapon";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_readymeleeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_readymeleeweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_readyrangedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_readyrangedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_removeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_removeweapon";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_getreadiedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getreadiedweapon";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_hasreadiedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasreadiedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasreadiedmeleeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasreadiedmeleeweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasreadiedrangedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasreadiedrangedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasrangedweaponwithammo", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasrangedweaponwithammo";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_gettarget", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_gettarget";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getnexttarget", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnexttarget";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isnexttargetavailable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isnexttargetavailable";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_settarget", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_settarget";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_attack", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_attack";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_finishingmove", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_finishingmove";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_defend", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_defend";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_flee", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_flee";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_aimat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_aimat";
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_attacker;
        int32_t attacker = vm.popVar(arr_attacker); if(verbose) LogInfo() << "attacker: " << attacker;

    });

    vm.registerExternalFunction("ai_shootat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_shootat";
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_attacker;
        int32_t attacker = vm.popVar(arr_attacker); if(verbose) LogInfo() << "attacker: " << attacker;

    });

    vm.registerExternalFunction("ai_stopaim", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_stopaim";
        uint32_t arr_attacker;
        int32_t attacker = vm.popVar(arr_attacker); if(verbose) LogInfo() << "attacker: " << attacker;

    });

    vm.registerExternalFunction("npc_arewestronger", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_arewestronger";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isaiming", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isaiming";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_insertitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_insertitem";
        std::string spawnpoint = vm.popString(); if(verbose) LogInfo() << "spawnpoint: " << spawnpoint;
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;

    });

    vm.registerExternalFunction("ai_lookforitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_lookforitem";
        int32_t instance = vm.popDataValue(); if(verbose) LogInfo() << "instance: " << instance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("wld_removeitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_removeitem";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("createinvitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "createinvitem";
        int32_t n1 = vm.popDataValue(); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("createinvitems", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "createinvitems";
        int32_t n2 = vm.popDataValue(); if(verbose) LogInfo() << "n2: " << n2;
        int32_t n1 = vm.popDataValue(); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_getinvitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getinvitem";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_hasitems", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasitems";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getinvitembyslot", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getinvitembyslot";
        int32_t slotnr = vm.popDataValue(); if(verbose) LogInfo() << "slotnr: " << slotnr;
        int32_t category = vm.popDataValue(); if(verbose) LogInfo() << "category: " << category;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_removeinvitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_removeinvitem";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_owner;
        int32_t owner = vm.popVar(arr_owner); if(verbose) LogInfo() << "owner: " << owner;

    });

    vm.registerExternalFunction("npc_removeinvitems", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_removeinvitems";
        int32_t amount = vm.popDataValue(); if(verbose) LogInfo() << "amount: " << amount;
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_owner;
        int32_t owner = vm.popVar(arr_owner); if(verbose) LogInfo() << "owner: " << owner;

    });

    vm.registerExternalFunction("mob_createitems", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mob_createitems";
        int32_t amount = vm.popDataValue(); if(verbose) LogInfo() << "amount: " << amount;
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        std::string mobname = vm.popString(); if(verbose) LogInfo() << "mobname: " << mobname;

    });

    vm.registerExternalFunction("mob_hasitems", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mob_hasitems";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        std::string mobname = vm.popString(); if(verbose) LogInfo() << "mobname: " << mobname;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("equipitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "equipitem";
        int32_t n1 = vm.popDataValue(); if(verbose) LogInfo() << "n1: " << n1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("ai_equipbestmeleeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_equipbestmeleeweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_equipbestrangedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_equipbestrangedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_equipbestarmor", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_equipbestarmor";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_unequipweapons", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_unequipweapons";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_unequiparmor", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_unequiparmor";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_equiparmor", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_equiparmor";

        uint32_t arr_owner;
        int32_t owner = vm.popVar(arr_owner); if(verbose) LogInfo() << "owner: " << owner;

    });

    vm.registerExternalFunction("npc_getequippedmeleeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getequippedmeleeweapon";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_getequippedrangedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getequippedrangedweapon";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_getequippedarmor", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getequippedarmor";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_hasequippedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasequippedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasequippedmeleeweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasequippedmeleeweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasequippedrangedweapon", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasequippedrangedweapon";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasequippedarmor", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasequippedarmor";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_ownedbynpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_ownedbynpc";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;

        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_ownedbyguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_ownedbyguild";
        int32_t guild = vm.popDataValue(); if(verbose) LogInfo() << "guild: " << guild;

        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isdetectedmobownedbynpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isdetectedmobownedbynpc";
        uint32_t arr_owner;
        int32_t owner = vm.popVar(arr_owner); if(verbose) LogInfo() << "owner: " << owner;
        uint32_t arr_user;
        int32_t user = vm.popVar(arr_user); if(verbose) LogInfo() << "user: " << user;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_giveitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_giveitem";
        uint32_t arr_n2;
        int32_t n2 = vm.popVar(arr_n2); if(verbose) LogInfo() << "n2: " << n2;

        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("npc_startitemreactmodules", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_startitemreactmodules";

        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasoffered", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasoffered";
        int32_t iteminstance = vm.popDataValue(); if(verbose) LogInfo() << "iteminstance: " << iteminstance;
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("doc_open", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_open";
        std::string picname = vm.popString(); if(verbose) LogInfo() << "picname: " << picname;

    });

    vm.registerExternalFunction("doc_font", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_font";
        std::string fontname = vm.popString(); if(verbose) LogInfo() << "fontname: " << fontname;

    });

    vm.registerExternalFunction("doc_print", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_print";
        std::string text = vm.popString(); if(verbose) LogInfo() << "text: " << text;

    });

    vm.registerExternalFunction("doc_mapcoordinates", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_mapcoordinates";
        float pixely2 = vm.popFloatValue(); if(verbose) LogInfo() << "pixely2: " << pixely2;
        float pixelx2 = vm.popFloatValue(); if(verbose) LogInfo() << "pixelx2: " << pixelx2;
        float gamey2 = vm.popFloatValue(); if(verbose) LogInfo() << "gamey2: " << gamey2;
        float gamex2 = vm.popFloatValue(); if(verbose) LogInfo() << "gamex2: " << gamex2;
        float pixely1 = vm.popFloatValue(); if(verbose) LogInfo() << "pixely1: " << pixely1;
        float pixelx1 = vm.popFloatValue(); if(verbose) LogInfo() << "pixelx1: " << pixelx1;
        float gamey1 = vm.popFloatValue(); if(verbose) LogInfo() << "gamey1: " << gamey1;
        float gamex1 = vm.popFloatValue(); if(verbose) LogInfo() << "gamex1: " << gamex1;
        std::string levelname = vm.popString(); if(verbose) LogInfo() << "levelname: " << levelname;

    });

    vm.registerExternalFunction("ai_output", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_output";
        std::string outputname = vm.popString(); if(verbose) LogInfo() << "outputname: " << outputname;
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_outputsvm", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_outputsvm";
        std::string svmname = vm.popString(); if(verbose) LogInfo() << "svmname: " << svmname;
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_outputsvm_overlay", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_outputsvm_overlay";
        std::string svmname = vm.popString(); if(verbose) LogInfo() << "svmname: " << svmname;
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_waittillend", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_waittillend";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_ask", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_ask";


        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_asktext", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_asktext";
        std::string strno = vm.popString(); if(verbose) LogInfo() << "strno: " << strno;
        std::string stryes = vm.popString(); if(verbose) LogInfo() << "stryes: " << stryes;


        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_waitforquestion", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_waitforquestion";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_setrefusetalk", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setrefusetalk";
        int32_t timesec = vm.popDataValue(); if(verbose) LogInfo() << "timesec: " << timesec;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_refusetalk", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_refusetalk";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_memoryentry", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_memoryentry";
        uint32_t arr_victim;
        int32_t victim = vm.popVar(arr_victim); if(verbose) LogInfo() << "victim: " << victim;
        int32_t newsid = vm.popDataValue(); if(verbose) LogInfo() << "newsid: " << newsid;
        uint32_t arr_offender;
        int32_t offender = vm.popVar(arr_offender); if(verbose) LogInfo() << "offender: " << offender;
        int32_t source = vm.popDataValue(); if(verbose) LogInfo() << "source: " << source;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_memoryentryguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_memoryentryguild";
        uint32_t arr_victimguild;
        int32_t victimguild = vm.popVar(arr_victimguild); if(verbose) LogInfo() << "victimguild: " << victimguild;
        int32_t newsid = vm.popDataValue(); if(verbose) LogInfo() << "newsid: " << newsid;
        uint32_t arr_offender;
        int32_t offender = vm.popVar(arr_offender); if(verbose) LogInfo() << "offender: " << offender;
        int32_t source = vm.popDataValue(); if(verbose) LogInfo() << "source: " << source;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_hasnews", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasnews";
        uint32_t arr_victim;
        int32_t victim = vm.popVar(arr_victim); if(verbose) LogInfo() << "victim: " << victim;
        uint32_t arr_offender;
        int32_t offender = vm.popVar(arr_offender); if(verbose) LogInfo() << "offender: " << offender;
        int32_t newsid = vm.popDataValue(); if(verbose) LogInfo() << "newsid: " << newsid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isnewsgossip", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isnewsgossip";
        int32_t newsnumber = vm.popDataValue(); if(verbose) LogInfo() << "newsnumber: " << newsnumber;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getnewswitness", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnewswitness";
        int32_t newsnumber = vm.popDataValue(); if(verbose) LogInfo() << "newsnumber: " << newsnumber;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("npc_getnewsvictim", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnewsvictim";
        int32_t newsnumber = vm.popDataValue(); if(verbose) LogInfo() << "newsnumber: " << newsnumber;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("npc_getnewsoffender", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getnewsoffender";
        int32_t newsnumber = vm.popDataValue(); if(verbose) LogInfo() << "newsnumber: " << newsnumber;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("npc_isdead", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isdead";
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_knowsinfo", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_knowsinfo";
        int32_t infoinstance = vm.popDataValue(); if(verbose) LogInfo() << "infoinstance: " << infoinstance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_checkinfo", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_checkinfo";
        int32_t important = vm.popDataValue(); if(verbose) LogInfo() << "important: " << important;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_giveinfo", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_giveinfo";
        int32_t important = vm.popDataValue(); if(verbose) LogInfo() << "important: " << important;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_checkavailablemission", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_checkavailablemission";
        int32_t important = vm.popDataValue(); if(verbose) LogInfo() << "important: " << important;
        int32_t missionstate = vm.popDataValue(); if(verbose) LogInfo() << "missionstate: " << missionstate;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_checkrunningmission", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_checkrunningmission";
        int32_t important = vm.popDataValue(); if(verbose) LogInfo() << "important: " << important;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_checkoffermission", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_checkoffermission";
        int32_t important = vm.popDataValue(); if(verbose) LogInfo() << "important: " << important;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("mis_setstatus", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mis_setstatus";
        int32_t newstatus = vm.popDataValue(); if(verbose) LogInfo() << "newstatus: " << newstatus;
        int32_t missionname = vm.popDataValue(); if(verbose) LogInfo() << "missionname: " << missionname;

    });

    vm.registerExternalFunction("mis_getstatus", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mis_getstatus";
        int32_t missionname = vm.popDataValue(); if(verbose) LogInfo() << "missionname: " << missionname;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("mis_ontime", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mis_ontime";
        int32_t missionname = vm.popDataValue(); if(verbose) LogInfo() << "missionname: " << missionname;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_stopprocessinfos", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_stopprocessinfos";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;

    });

    vm.registerExternalFunction("npc_isplayer", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isplayer";
        uint32_t arr_player;
        int32_t player = vm.popVar(arr_player); if(verbose) LogInfo() << "player: " << player;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_detectplayer", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_detectplayer";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasdetectednpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasdetectednpc";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isnear", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isnear";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getdisttonpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getdisttonpc";
        uint32_t arr_npc2;
        int32_t npc2 = vm.popVar(arr_npc2); if(verbose) LogInfo() << "npc2: " << npc2;
        uint32_t arr_npc1;
        int32_t npc1 = vm.popVar(arr_npc1); if(verbose) LogInfo() << "npc1: " << npc1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getdisttowp", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getdisttowp";
        std::string wpname = vm.popString(); if(verbose) LogInfo() << "wpname: " << wpname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getdisttoitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getdisttoitem";

        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getdisttoplayer", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getdisttoplayer";
        uint32_t arr_npc1;
        int32_t npc1 = vm.popVar(arr_npc1); if(verbose) LogInfo() << "npc1: " << npc1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("snd_getdisttosource", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "snd_getdisttosource";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_gettrueguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_gettrueguild";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_setattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setattitude";
        int32_t att = vm.popDataValue(); if(verbose) LogInfo() << "att: " << att;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_settempattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_settempattitude";
        int32_t att = vm.popDataValue(); if(verbose) LogInfo() << "att: " << att;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_getattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getattitude";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_settrueguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_settrueguild";
        int32_t guildid = vm.popDataValue(); if(verbose) LogInfo() << "guildid: " << guildid;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_setguildattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_setguildattitude";
        int32_t guild2 = vm.popDataValue(); if(verbose) LogInfo() << "guild2: " << guild2;
        int32_t attitude = vm.popDataValue(); if(verbose) LogInfo() << "attitude: " << attitude;
        int32_t guild1 = vm.popDataValue(); if(verbose) LogInfo() << "guild1: " << guild1;

    });

    vm.registerExternalFunction("wld_getguildattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getguildattitude";
        int32_t guild2 = vm.popDataValue(); if(verbose) LogInfo() << "guild2: " << guild2;
        int32_t guild1 = vm.popDataValue(); if(verbose) LogInfo() << "guild1: " << guild1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getpermattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getpermattitude";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_exchangeguildattitudes", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_exchangeguildattitudes";
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;

    });

    vm.registerExternalFunction("npc_getguildattitude", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getguildattitude";
        uint32_t arr_npc_1;
        int32_t npc_1 = vm.popVar(arr_npc_1); if(verbose) LogInfo() << "npc_1: " << npc_1;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_setknowsplayer", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setknowsplayer";
        uint32_t arr_player;
        int32_t player = vm.popVar(arr_player); if(verbose) LogInfo() << "player: " << player;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_knowsplayer", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_knowsplayer";
        uint32_t arr_player;
        int32_t player = vm.popVar(arr_player); if(verbose) LogInfo() << "player: " << player;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_startstate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_startstate";
        std::string wpname = vm.popString(); if(verbose) LogInfo() << "wpname: " << wpname;
        int32_t statebehaviour = vm.popDataValue(); if(verbose) LogInfo() << "statebehaviour: " << statebehaviour;

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_clearaiqueue", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_clearaiqueue";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_setnpcstostate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_setnpcstostate";
        int32_t radius = vm.popDataValue(); if(verbose) LogInfo() << "radius: " << radius;

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_isinstate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isinstate";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_wasinstate", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_wasinstate";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ta", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta";
        std::string waypoint = vm.popString(); if(verbose) LogInfo() << "waypoint: " << waypoint;

        int32_t stop_h = vm.popDataValue(); if(verbose) LogInfo() << "stop_h: " << stop_h;
        int32_t start_h = vm.popDataValue(); if(verbose) LogInfo() << "start_h: " << start_h;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ta_min", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta_min";
        std::string waypoint = vm.popString(); if(verbose) LogInfo() << "waypoint: " << waypoint;

        int32_t stop_m = vm.popDataValue(); if(verbose) LogInfo() << "stop_m: " << stop_m;
        int32_t stop_h = vm.popDataValue(); if(verbose) LogInfo() << "stop_h: " << stop_h;
        int32_t start_m = vm.popDataValue(); if(verbose) LogInfo() << "start_m: " << start_m;
        int32_t start_h = vm.popDataValue(); if(verbose) LogInfo() << "start_h: " << start_h;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_continueroutine", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_continueroutine";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_isinroutine", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isinroutine";

        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_exchangeroutine", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_exchangeroutine";
        std::string routinename = vm.popString(); if(verbose) LogInfo() << "routinename: " << routinename;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("wld_setobjectroutine", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_setobjectroutine";
        int32_t state = vm.popDataValue(); if(verbose) LogInfo() << "state: " << state;
        std::string objname = vm.popString(); if(verbose) LogInfo() << "objname: " << objname;
        int32_t min1 = vm.popDataValue(); if(verbose) LogInfo() << "min1: " << min1;
        int32_t hour1 = vm.popDataValue(); if(verbose) LogInfo() << "hour1: " << hour1;

    });

    vm.registerExternalFunction("wld_setmobroutine", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_setmobroutine";
        int32_t state = vm.popDataValue(); if(verbose) LogInfo() << "state: " << state;
        std::string objname = vm.popString(); if(verbose) LogInfo() << "objname: " << objname;
        int32_t min1 = vm.popDataValue(); if(verbose) LogInfo() << "min1: " << min1;
        int32_t hour1 = vm.popDataValue(); if(verbose) LogInfo() << "hour1: " << hour1;

    });

    vm.registerExternalFunction("rtn_exchange", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "rtn_exchange";
        std::string newroutine = vm.popString(); if(verbose) LogInfo() << "newroutine: " << newroutine;
        std::string oldroutine = vm.popString(); if(verbose) LogInfo() << "oldroutine: " << oldroutine;

    });

    vm.registerExternalFunction("ta_beginoverlay", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta_beginoverlay";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ta_endoverlay", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta_endoverlay";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ta_removeoverlay", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta_removeoverlay";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("mdl_setmodelscale", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_setmodelscale";
        float z = vm.popFloatValue(); if(verbose) LogInfo() << "z: " << z;
        float y = vm.popFloatValue(); if(verbose) LogInfo() << "y: " << y;
        float x = vm.popFloatValue(); if(verbose) LogInfo() << "x: " << x;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("mdl_setmodelfatness", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "mdl_setmodelfatness";
        float fatness = vm.popFloatValue(); if(verbose) LogInfo() << "fatness: " << fatness;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_changeattribute", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_changeattribute";
        int32_t value = vm.popDataValue(); if(verbose) LogInfo() << "value: " << value;
        int32_t atr = vm.popDataValue(); if(verbose) LogInfo() << "atr: " << atr;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_hastalent", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hastalent";
        int32_t tal = vm.popDataValue(); if(verbose) LogInfo() << "tal: " << tal;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_hasfighttalent", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasfighttalent";
        int32_t tal = vm.popDataValue(); if(verbose) LogInfo() << "tal: " << tal;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_createspell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_createspell";
        int32_t spellnr = vm.popDataValue(); if(verbose) LogInfo() << "spellnr: " << spellnr;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_learnspell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_learnspell";
        int32_t spellnr = vm.popDataValue(); if(verbose) LogInfo() << "spellnr: " << spellnr;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_setteleportpos", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setteleportpos";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_getactivespell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getactivespell";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getactivespellcat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getactivespellcat";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_setactivespellinfo", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setactivespellinfo";
        int32_t i1 = vm.popDataValue(); if(verbose) LogInfo() << "i1: " << i1;
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getactivespelllevel", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getactivespelllevel";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ai_readyspell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_readyspell";
        int32_t investmana = vm.popDataValue(); if(verbose) LogInfo() << "investmana: " << investmana;
        int32_t spellid = vm.popDataValue(); if(verbose) LogInfo() << "spellid: " << spellid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_unreadyspell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_unreadyspell";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_hasspell", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_hasspell";
        int32_t spellid = vm.popDataValue(); if(verbose) LogInfo() << "spellid: " << spellid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_percenable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_percenable";

        int32_t percid = vm.popDataValue(); if(verbose) LogInfo() << "percid: " << percid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_percdisable", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_percdisable";
        int32_t percid = vm.popDataValue(); if(verbose) LogInfo() << "percid: " << percid;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_setperctime", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_setperctime";
        float seconds = vm.popFloatValue(); if(verbose) LogInfo() << "seconds: " << seconds;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("perc_setrange", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "perc_setrange";
        int32_t range = vm.popDataValue(); if(verbose) LogInfo() << "range: " << range;
        int32_t percid = vm.popDataValue(); if(verbose) LogInfo() << "percid: " << percid;

    });

    vm.registerExternalFunction("npc_sendpassiveperc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_sendpassiveperc";
        uint32_t arr_npc3;
        int32_t npc3 = vm.popVar(arr_npc3); if(verbose) LogInfo() << "npc3: " << npc3;
        uint32_t arr_npc2;
        int32_t npc2 = vm.popVar(arr_npc2); if(verbose) LogInfo() << "npc2: " << npc2;
        int32_t perc_type = vm.popDataValue(); if(verbose) LogInfo() << "perc_type: " << perc_type;
        uint32_t arr_npc1;
        int32_t npc1 = vm.popVar(arr_npc1); if(verbose) LogInfo() << "npc1: " << npc1;

    });

    vm.registerExternalFunction("npc_sendsingleperc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_sendsingleperc";
        int32_t percid = vm.popDataValue(); if(verbose) LogInfo() << "percid: " << percid;
        uint32_t arr_target;
        int32_t target = vm.popVar(arr_target); if(verbose) LogInfo() << "target: " << target;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("npc_perceiveall", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_perceiveall";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("wld_detectnpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_detectnpc";
        int32_t guild = vm.popDataValue(); if(verbose) LogInfo() << "guild: " << guild;

        int32_t instance = vm.popDataValue(); if(verbose) LogInfo() << "instance: " << instance;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_detectitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_detectitem";
        int32_t flags = vm.popDataValue(); if(verbose) LogInfo() << "flags: " << flags;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_getdetectedmob", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_getdetectedmob";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn("");
    });

    vm.registerExternalFunction("npc_canseenpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_canseenpc";
        uint32_t arr_npc2;
        int32_t npc2 = vm.popVar(arr_npc2); if(verbose) LogInfo() << "npc2: " << npc2;
        uint32_t arr_npc1;
        int32_t npc1 = vm.popVar(arr_npc1); if(verbose) LogInfo() << "npc1: " << npc1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_canseenpcfreelos", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_canseenpcfreelos";
        uint32_t arr_other;
        int32_t other = vm.popVar(arr_other); if(verbose) LogInfo() << "other: " << other;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_canseeitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_canseeitem";

        uint32_t arr_npc1;
        int32_t npc1 = vm.popVar(arr_npc1); if(verbose) LogInfo() << "npc1: " << npc1;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_canseesource", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_canseesource";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("ta_cs", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ta_cs";
        std::string rolename = vm.popString(); if(verbose) LogInfo() << "rolename: " << rolename;
        std::string csname = vm.popString(); if(verbose) LogInfo() << "csname: " << csname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("ai_playcutscene", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "ai_playcutscene";
        std::string csname = vm.popString(); if(verbose) LogInfo() << "csname: " << csname;
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;

    });

    vm.registerExternalFunction("hlp_cutsceneplayed", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "hlp_cutsceneplayed";
        std::string csname = vm.popString(); if(verbose) LogInfo() << "csname: " << csname;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isincutscene", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isincutscene";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("snd_play", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "snd_play";
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;

    });

    vm.registerExternalFunction("snd_play3d", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "snd_play3d";
        std::string s1 = vm.popString(); if(verbose) LogInfo() << "s1: " << s1;
        uint32_t arr_n0;
        int32_t n0 = vm.popVar(arr_n0); if(verbose) LogInfo() << "n0: " << n0;

    });

    vm.registerExternalFunction("snd_issourcenpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "snd_issourcenpc";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("snd_issourceitem", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "snd_issourceitem";
        uint32_t arr_self;
        int32_t self = vm.popVar(arr_self); if(verbose) LogInfo() << "self: " << self;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_assignroomtoguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_assignroomtoguild";
        int32_t guild = vm.popDataValue(); if(verbose) LogInfo() << "guild: " << guild;
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;

    });

    vm.registerExternalFunction("wld_assignroomtonpc", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_assignroomtonpc";
        uint32_t arr_roomowner;
        int32_t roomowner = vm.popVar(arr_roomowner); if(verbose) LogInfo() << "roomowner: " << roomowner;
        std::string s0 = vm.popString(); if(verbose) LogInfo() << "s0: " << s0;

    });

    vm.registerExternalFunction("wld_getplayerportalowner", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getplayerportalowner";

        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("wld_getplayerportalguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getplayerportalguild";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("wld_getformerplayerportalowner", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getformerplayerportalowner";

        vm.setReturnVar(0);
    });

    vm.registerExternalFunction("wld_getformerplayerportalguild", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "wld_getformerplayerportalguild";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_isplayerinmyroom", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_isplayerinmyroom";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("npc_wasplayerinmyroom", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "npc_wasplayerinmyroom";
        uint32_t arr_npc;
        int32_t npc = vm.popVar(arr_npc); if(verbose) LogInfo() << "npc: " << npc;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("inttostring", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "inttostring";
        int32_t x = vm.popDataValue(); if(verbose) LogInfo() << "x: " << x;
        vm.setReturn("");
    });

    vm.registerExternalFunction("floattoint", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "floattoint";
        float x = vm.popFloatValue(); if(verbose) LogInfo() << "x: " << x;
        vm.setReturn(0);
    });

    vm.registerExternalFunction("inttofloat", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "inttofloat";
        int32_t x = vm.popDataValue(); if(verbose) LogInfo() << "x: " << x;
        vm.setReturn(0.0f);
    });

    vm.registerExternalFunction("concatstrings", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "concatstrings";
        std::string str2 = vm.popString(); if(verbose) LogInfo() << "str2: " << str2;
        std::string str1 = vm.popString(); if(verbose) LogInfo() << "str1: " << str1;
        vm.setReturn("");
    });



    vm.registerExternalFunction("log_createtopic", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "log_createtopic";
        int32_t section = vm.popDataValue(); if(verbose) LogInfo() << "section: " << section;
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;

    });

    vm.registerExternalFunction("log_settopicstatus", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "log_settopicstatus";
        int32_t status = vm.popDataValue(); if(verbose) LogInfo() << "status: " << status;
        std::string name = vm.popString(); if(verbose) LogInfo() << "name: " << name;

    });

    vm.registerExternalFunction("log_addentry", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "log_addentry";
        std::string entry = vm.popString(); if(verbose) LogInfo() << "entry: " << entry;
        std::string topic = vm.popString(); if(verbose) LogInfo() << "topic: " << topic;

    });

    vm.registerExternalFunction("doc_create", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_create";

        vm.setReturn(0);
    });

    vm.registerExternalFunction("doc_setpages", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_setpages";
        int32_t pages = vm.popDataValue(); if(verbose) LogInfo() << "pages: " << pages;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_setpage", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_setpage";
        int32_t vbool = vm.popDataValue(); if(verbose) LogInfo() << "vbool: " << vbool;
        std::string pageimage = vm.popString(); if(verbose) LogInfo() << "pageimage: " << pageimage;
        int32_t page = vm.popDataValue(); if(verbose) LogInfo() << "page: " << page;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_setfont", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_setfont";
        std::string fontname = vm.popString(); if(verbose) LogInfo() << "fontname: " << fontname;
        int32_t page = vm.popDataValue(); if(verbose) LogInfo() << "page: " << page;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_setmargins", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_setmargins";
        int32_t vbool = vm.popDataValue(); if(verbose) LogInfo() << "vbool: " << vbool;
        int32_t bottommargin = vm.popDataValue(); if(verbose) LogInfo() << "bottommargin: " << bottommargin;
        int32_t rightmargin = vm.popDataValue(); if(verbose) LogInfo() << "rightmargin: " << rightmargin;
        int32_t topmargin = vm.popDataValue(); if(verbose) LogInfo() << "topmargin: " << topmargin;
        int32_t leftmargin = vm.popDataValue(); if(verbose) LogInfo() << "leftmargin: " << leftmargin;
        int32_t page = vm.popDataValue(); if(verbose) LogInfo() << "page: " << page;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_printline", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_printline";
        std::string text = vm.popString(); if(verbose) LogInfo() << "text: " << text;
        int32_t page = vm.popDataValue(); if(verbose) LogInfo() << "page: " << page;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_printlines", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_printlines";
        std::string text = vm.popString(); if(verbose) LogInfo() << "text: " << text;
        int32_t page = vm.popDataValue(); if(verbose) LogInfo() << "page: " << page;
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });

    vm.registerExternalFunction("doc_show", [=](Daedalus::DaedalusVM& vm){
        if (verbose) LogInfo() << "doc_show";
        int32_t handle = vm.popDataValue(); if(verbose) LogInfo() << "handle: " << handle;

    });
}


