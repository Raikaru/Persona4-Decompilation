#include "include_asm.h"
/* Source unit: src/Battle/btlSound_001f7530.c */
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_packet_create_internal.h"
#include "datCalc_unit_internal.h"
extern u8 *mdlEffectBuildFromResource(u8 *resource);
extern s32 sdkSndStartStream(s16 index, s16 stream, s16 arg2, s16 arg3);
extern s32 btlCond_ESCAPE(u8 *arg0, s32 arg1);

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

extern Battle* iGpffffb3ac;
extern void sdkSndStopMainChannel(void);
extern void sdkSndStopChannel(s32 fadeDuration);

extern void sdkSndFadeOutChannelFrames(s16 channel, s32 unused, s32 fadeFrames);

typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x47];
    u8 unk_47;
    u8 _pad48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 _pad74[4];
    void* workData;
};

extern BtlPacket* btlPacketAlloc(u32 type, u32 workSize);
extern void btlSoundRefreshSlotChannel(void* work);
extern u32 btlSoundSetSlotChannel(void* work);


extern void btlSoundStopChannel(u16* work);
extern u32 btlSoundPlayCue(s16* work);

typedef struct BtlSoundPacketSkillSE BtlSoundPacketSkillSE;
struct BtlSoundPacketSkillSE
{
    u32 timer;
    u16 skillId;
    u16 state;
    void* cdvd;
    u16 flags;
    u8 _pad0e[2];
};
extern void btlSoundSkillSEInit(void* work);
extern u32 btlSoundSkillSEUpdate(void* work);
extern u32 btlSoundRunCueQueue(u16* work);

extern u32 sprintf(void* buffer, const void* format, ...);
extern char sGpffffa500[5];
extern char sGpffffa4F0[7];
extern char sGpffffa4F8[7];
extern char DAT_00624F40[15];
extern char D_00624F20[];
extern char D_00624F30[];
extern u8 sdkSndStartChannel(s16 channelIndex, const char* name);
extern u8 *D_0076449C;

extern void func_00440b68(const char* fmt, const char* file, s32 line);
extern void* H_Cdvd_AcquireDirectory(const char* path, s32 flags);
extern s32 H_Cdvd_IsFileLoaded(void* handle);
extern void H_Cdvd_Destroy(void* handle);
extern u8* H_Cdvd_GetArchiveEntry(u8* handle, s32 index, s32* out);
extern s32 sdkSndQueueSlotRequest(s32 bank, void* file1, u32 size1, void* file2, u32 size2, void* file3, u32 size3);
extern s32 hsndSlotIsStarting(s32 bank);

extern u32 strlen(const char* text);
extern u32 btlSoundLoadStream(u16* work);
extern void strcpy(char* destination, const char* source);
extern u32 btlSoundClearUnitFlag10(void* work);
extern u32 btlSoundSetUnitFlag10(void* work);
extern u32 func_001f9750(void* work);



// FUN_001F7530
void btlSoundStopBgmIfEnabled(void)
{
    if ((iGpffffb3ac->flags & 0x40) != 0)
    {
        sdkSndStopMainChannel();
    }
}



// FUN_001F7570
void btlSoundFadeOutBgm(s16 fadeDuration)
{
    if ((iGpffffb3ac->flags & 0x40) != 0)
    {
        sdkSndStopChannel(fadeDuration);
    }
}



// FUN_001F7620
void btlSoundFadeChannel(s16 channel, s32 fadeFrames)
{
    sdkSndFadeOutChannelFrames(channel, 0, (u16)fadeFrames);
}



// FUN_001F7C20
BtlPacket* btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet;
    u16* work;

    packet = btlPacketAlloc(0x902, 6);
    packet->initFunc = (BtlPacketFunc)btlSoundRefreshSlotChannel;
    packet->updateFunc = btlSoundSetSlotChannel;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
    return packet;
}



// FUN_001F7CA0
void btlSoundStopChannel(u16* work)
{
    sdkSndStopStream(0, (s16)*work);
}



// FUN_001F7CD0
u32 btlSoundPlayCue(s16* work)
{
    u16* values = (u16*)work;

    sdkSndStartStream(0, values[0], values[1], values[2]);
    return 1;
}



// FUN_001F7D10
BtlPacket* btlSoundCreateCuePacket(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet;
    u16* work;

    packet = btlPacketAlloc(0x901, 6);
    packet->initFunc = (BtlPacketFunc)btlSoundStopChannel;
    packet->updateFunc = (BtlPacketFunc)btlSoundPlayCue;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
    return packet;
}



// FUN_001F7D90
void btlSoundSkillSEInit(void* work)
{
    BtlSoundPacketSkillSE* packet;
    char buffer[128];

    packet = (BtlSoundPacketSkillSE*)work;

    if (!(packet->flags & 1))
    {
        sprintf(buffer, D_00624F30, sGpffffa4F8, packet->skillId);
        func_00440b68(sGpffffa4F0, D_00624F20, 0x274);
        packet->cdvd = H_Cdvd_AcquireDirectory(buffer, 0);
    }
    else
    {
        packet->cdvd = NULL;
    }

    packet->state = 1;
    packet->timer = 0;
}

// FUN_001F7E30
u32 btlSoundSkillSEUpdate(void* work)
{
    BtlSoundPacketSkillSE* packet = (BtlSoundPacketSkillSE*)work;
    char buffer[128];
    void* file1;
    void* file2;
    void* file3;
    u32 file1Size;
    u32 file2Size;
    u32 file3Size;
    s32 i;

    if (packet->cdvd == NULL)
    {
        sprintf(buffer, D_00624F30, sGpffffa4F8, packet->skillId);
        func_00440b68(sGpffffa4F0, D_00624F20, 0x2AA);
        packet->cdvd = H_Cdvd_AcquireDirectory(buffer, 0);
    }

    switch (packet->state)
    {
    case 1:
        if (!H_Cdvd_IsFileLoaded(packet->cdvd))
        {
            return 0;
        }

        sdkSndStopStream(2, 4);
        for (i = 5; i <= 9; i++)
        {
            sdkSndStopStream(2, (s16)i);
        }

        file1 = H_Cdvd_GetArchiveEntry(packet->cdvd, 0, (s32*)&file1Size);
        file2 = H_Cdvd_GetArchiveEntry(packet->cdvd, 1, (s32*)&file2Size);
        file3 = H_Cdvd_GetArchiveEntry(packet->cdvd, 2, (s32*)&file3Size);
        sdkSndQueueSlotRequest(2, file1, file1Size, file2, file2Size, file3, file3Size);
        packet->state = 2;
        break;
    case 2:
        if (!hsndSlotIsStarting(2))
        {
            return 0;
        }

        H_Cdvd_Destroy(packet->cdvd);
        return 1;
    }

    packet->timer++;
    return 0;
}
// FUN_001F8000
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = btlPacketAlloc(0x903, sizeof(BtlSoundPacketSkillSE));
    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = (BtlPacketFunc)btlSoundSkillSEInit;
    packet->updateFunc = btlSoundSkillSEUpdate;
    work = (BtlSoundPacketSkillSE*)packet->workData;
    work->skillId = skillId;
    work->flags = flags;
    return packet;
}



// FUN_001F8070
u32 btlSoundRunCueQueue(u16* work)
{
    u16 state;
    u16 channel;
    u8* global;

    state = *work;
    switch (state)
    {
    case 0:
        sdkSndStartStream(2, 4, 0, (s16)state);
        break;
    case 1:
        global = D_0076449C;
        if (*(s8*)(global + 0xaca) == -1)
        {
            channel = *(u16*)(global + 0xac8);
            sdkSndStartStream(2, channel, 0, (s16)state);
            D_0076449C[0xaca] = 0;
            if ((*(u16*)(D_0076449C + 0xac8) += 1) >= 9)
            {
                *(u16*)(D_0076449C + 0xac8) = 5;
            }
        }
        break;
    }
    return 1;
}
// FUN_001F8140
BtlPacket* btlSoundCreateCueQueuePacket(u16 state)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x904, 2);
    packet->updateFunc = (BtlPacketFunc)btlSoundRunCueQueue;
    *(u16*)packet->workData = state;
    return packet;
}



// FUN_001F8190
u32 btlSoundLoadStream(u16* work)
{
    char path[512];

    sprintf(path, sGpffffa500, DAT_00624F40, *(u32*)(work + 2));
    sdkSndStartChannel((s16)*work, path);
    return 1;
}



// FUN_001F81F0
BtlPacket* btlSoundCreateStreamPacket(u16 channel, const char* streamName)
{
    u32 length;
    BtlPacket* packet;
    u8* work;

    length = strlen(streamName);
    packet = btlPacketAlloc(0x905, length + 8);
    packet->updateFunc = (BtlPacketFunc)btlSoundLoadStream;
    work = (u8*)packet->workData;
    *(u16*)work = channel;
    *(char**)(work + 4) = (char*)(work + 8);
    strcpy((char*)work + 8, streamName);
    return packet;
}



// FUN_001F8280
u32 btlSoundClearUnitFlag10(void* work)
{
    u8* unit;

    unit = (u8*)*(struct BtlUnit**)work;
    if ((*(s32*)(unit + 0x98) & 2) != 0)
    {
        *(u16*)(unit + 0x9d8) &= (u16)~0x10;
    }
    return 1;
}
// FUN_001F82B0
BtlPacket* btlSoundCreateUnitFlagClearPacket(struct BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x909, 4);
    packet->updateFunc = btlSoundClearUnitFlag10;
    *(struct BtlUnit**)packet->workData = unit;
    return packet;
}



// FUN_001F8300
u32 btlSoundSetUnitFlag10(void* work)
{
    u8* unit;

    unit = (u8*)*(struct BtlUnit**)work;
    if ((*(s32*)(unit + 0x98) & 2) != 0)
    {
        *(u16*)(unit + 0x9d8) |= 0x10;
    }
    return 1;
}
// FUN_001F8330
BtlPacket* btlSoundCreateUnitFlagSetPacket(struct BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x90A, 4);
    packet->updateFunc = btlSoundSetUnitFlag10;
    *(struct BtlUnit**)packet->workData = unit;
    return packet;
}



// FUN_001F97B0
void btlSoundCreateWaitPacket(void)
{
    BtlPacket* packet;
    u32* work;

    packet = btlPacketAlloc(0xA00, 8);
    packet->unk_47 &= ~(1 << 0);
    packet->updateFunc = func_001f9750;
    work = (u32*)packet->workData;
    work[0] = 0;
    work[1] = 0;
}
extern s32 btlCdvdLoadPoll(void);
extern s32 btlSoundLoadPoll(s32 *arg0);
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}
extern u8 *iGpffffb3b8;
extern s32 btlSoundLoadPoll(s32 *arg0);
extern s32 btlSoundStopStep(void);
extern s32 btlSoundReleaseStep(void);
extern void mdlEffectDestroyWithNodes(s32 arg0);
extern void mdlEffectUpdateChildren(s32 arg0);
extern void taskRecordRequestPrimary(s32 arg0);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 btlCdvdLoadPoll(void);
extern s32 btlUnitStatusWindowShow(u8 *arg0, s16 arg1);
extern s32 btlTaskSlotIsLinked(s32 arg0);
extern s32 btlTaskSlotIsSet(void);
extern s32 taskRecordIsDone(s32 arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerReplyVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerAssistVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickRandomPartnerVoice(u8 *arg0);
extern s32 btlVoiceIdPacketUpdate(u8 *arg0);
#pragma push
#pragma pop
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
/* measured: opt_propagation off preserves btlSoundPickPartnerCallVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerCallVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerReplyVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerReplyVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerAssistVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerAssistVoice probe. */
/* measured: opt_propagation off tested for btlSoundPickRandomPartnerVoice; retains loop constants. */
/* measured: close opt_propagation after btlSoundPickRandomPartnerVoice. */
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
/* measured: close opt_propagation after btlVoiceIdPacketUpdate probe. */
/* Polls the CDVD file load for the battle state at +0xB84. Returns the state-5 task result when the state is 5; once the file is loaded it caches the node at +0x110 into +0xB80 (unless flag 2 is set in +0xB4C), destroys the handle and returns 1. */
// FUN_001FA660
s32 btlCdvdLoadPoll(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = (u8 *)iGpffffb3ac;
    if (*(u16 *)(base + 0xB7C) == 5) {
        return taskRecordIsDone(*(s32 *)(base + 0xB88));
    }
    if (H_Cdvd_IsFileLoaded(*(u8 **)(base + 0xB84)) != 0) {
        base = (u8 *)iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = *(u8 **)(base + 0xB84);
            *(u8 **)((u8 *)iGpffffb3ac + 0xB80) =
                mdlEffectBuildFromResource(*(u8 **)(work + 0x110));
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        H_Cdvd_Destroy(*(u8 **)((u8 *)iGpffffb3ac + 0xB84));
        *(u8 **)((u8 *)iGpffffb3ac + 0xB84) = NULL;
        return 1;
    }
    return 0;
}


#pragma push
#pragma pop
// FUN_001FA720
u8 *btlSoundLoadPacketNew(const void *arg0) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC04, 0xA);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x68) = (void *)func_001fa490;
    *(void **)(temp_2 + 0x6C) = (void *)btlCdvdLoadPoll;
    memcpy(*(s32 **)(temp_2 + 0x78), (void *)arg0, 0xA);
    return temp_2;
}


/* Steps the sound load at +0xB80 with the progress counter arg0. While the load runs it starts the stream on the first step and loads the table at D_005DC8CC, returning 0. When the load finishes it releases the resource and returns 1. */
// FUN_001FA7A0
s32 btlSoundLoadPoll(s32 *arg0)
{
    extern void taskRecordRequestSecondary(s32 arg0);
    extern s32 mdlEffectIsFinished(s32 arg0);
    extern s32 TnGetTableBase(void);
    extern void TnSetTableBase(void *arg0);
    extern void mdlEffectCommitTreeFrame(s32 arg0);
    extern void mdlEffectFlushTreeFrame(u8 *arg0);
    extern void mdlEffectDestroyWithNodes(s32 arg0);
    extern u8 D_005DC8CC[];
    void *temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u8 *temp_4;

    temp_4 = (u8 *)iGpffffb3ac;
    if (*(u16 *)(temp_4 + 0xB7C) == 5) {
        temp_4_2 = *(s32 *)(temp_4 + 0xB88);
        if (temp_4_2 == 0) {
            return 1;
        }
        if (*arg0 == 0) {
            taskRecordRequestSecondary(temp_4_2);
        }
        goto block_12;
    }
    temp_4_3 = *(s32 *)(temp_4 + 0xB80);
    if (temp_4_3 == 0) {
        return 1;
    }
    if (mdlEffectIsFinished(temp_4_3) == 0) {
        if (*arg0 == 0) {
            sdkSndStartStream(1, 0xE, 2, 0x10);
        }
        temp_17 = (void *)TnGetTableBase();
        TnSetTableBase(&D_005DC8CC);
        mdlEffectCommitTreeFrame(*(s32 *)((u8 *)iGpffffb3ac + 0xB80));
        mdlEffectFlushTreeFrame((u8 *)*(s32 *)((u8 *)iGpffffb3ac + 0xB80));
        TnSetTableBase(temp_17);
        *arg0 += 1;
        goto block_12;
    }
    mdlEffectDestroyWithNodes(*(s32 *)((u8 *)iGpffffb3ac + 0xB80));
    *(s32 *)((u8 *)iGpffffb3ac + 0xB80) = 0;
    return 1;
block_12:
        return 0;
}


// FUN_001FA8F0
void btlSoundLoadTaskStart(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC05, 4);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)btlSoundLoadPoll;
    *(s32 **)(*(u8 **)(temp_2 + 0x78)) = NULL;
}


// FUN_001FA940
s32 btlSoundStopStep(void) {
    s32 temp_4;
    s32 temp_4_2;
    u8 *temp_3;

    temp_3 = D_0076449C;
    if (*(s32 *)(temp_3 + 0xB84) != 0) {
        *(s32 *)(temp_3 + 0xB4C) |= 2;
    } else {
        temp_4 = *(s32 *)(temp_3 + 0xB80);
        if (temp_4 != 0) {
            mdlEffectDestroyWithNodes(temp_4);
            *(s32 *)(D_0076449C + 0xB80) = 0;
        }
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        taskRecordRequestPrimary(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}


// FUN_001FA9C0
void btlSoundStopTaskStart(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC06, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)btlSoundStopStep;
}


// FUN_001FAA00
s32 btlSoundReleaseStep(void) {
    s32 temp_4;
    s32 temp_4_2;

    temp_4 = *(s32 *)(D_0076449C + 0xB80);
    if (temp_4 != 0) {
        mdlEffectUpdateChildren(temp_4);
    }
    temp_4_2 = *(s32 *)(D_0076449C + 0xB88);
    if (temp_4_2 != 0) {
        taskRecordRequestPrimary(temp_4_2);
        *(s32 *)(D_0076449C + 0xB88) = 0;
    }
    return 1;
}


// FUN_001FAA60
void btlSoundReleaseTaskStart(void) {
    u8 *temp_2;

    temp_2 = (u8 *)btlPacketAlloc(0xC07, 0);
    temp_2[0x47] &= 0xEE;
    *(void **)(temp_2 + 0x6C) = (void *)btlSoundReleaseStep;
}


/* Shows the battle status window for slot 0 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAAA0
s32 btlStatusWindowShowSlot0(u8 *arg0) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 0);
    }
    return 0;
}


/* Returns whether task slot 0 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAAF0
s32 btlTaskSlotLinkedSlot0(void) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(0);
    }
    return 0;
}


/* Shows the battle status window for slot 1 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAB40
s32 btlStatusWindowShowSlot1(u8 *arg0) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 1);
    }
    return 0;
}


/* Returns whether task slot 1 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAB90
s32 btlTaskSlotLinkedSlot1(void) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(1);
    }
    return 0;
}


/* Shows the battle status window for slot 2 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FABE0
s32 btlStatusWindowShowSlot2(u8 *arg0) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 2);
    }
    return 0;
}


/* Returns whether task slot 2 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAC30
s32 btlTaskSlotLinkedSlot2(void) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(2);
    }
    return 0;
}


/* Slot 3 status window: when the flag is set and no task slot is set, runs the callback at +0xB40 once and returns 1; otherwise shows the window for slot 3. */
// FUN_001FAC80
s32 btlStatusWindowShowSlot3Callback(u8 *arg0)
{
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(base + 0xC) & 0x200000) == 0) {
        goto return_zero;
    }
    if (btlTaskSlotIsSet() == 0) {
        base = (u8 *)iGpffffb3ac;
        if (*(s32 *)(base + 0xB40) != 0) {
            ((void (*)(void *))(*(void **)(base + 0xB40)))(
                *(void **)(base + 0xB48));
            return 1;
        }
    }
    return btlUnitStatusWindowShow(arg0, 3);
return_zero:
    return 0;
}


/* Slot 3 linked check: when the flag is set and no task slot is set, runs the callback at +0xB44 with +0xB48 and clears the three callback fields when it returns 0; then returns whether task slot 3 is linked. */
// FUN_001FAD10
s32 btlTaskSlotLinkedSlot3Callback(void)
{
    s32 (*callback)(s32);
    s32 result;
    u8 *base;

    result = 0;
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        if (btlTaskSlotIsSet() == 0) {
            base = (u8 *)iGpffffb3ac;
            callback = *(s32 (**)(s32))(base + 0xB44);
            if (callback != NULL) {
                result = callback(*(s32 *)(base + 0xB48));
                if (result == 0) {
                    *(s32 *)((u8 *)iGpffffb3ac + 0xB40) = 0;
                    *(s32 *)((u8 *)iGpffffb3ac + 0xB44) = 0;
                    *(s32 *)((u8 *)iGpffffb3ac + 0xB48) = 0;
                }
            }
        }
        if (result == 0) {
            result = btlTaskSlotIsLinked(3);
        }
    }
    return result;
}


/* Shows the battle status window for slot 4 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FADC0
s32 btlStatusWindowShowSlot4(u8 *arg0) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlUnitStatusWindowShow(arg0, 4);
    }
    return 0;
}


/* Returns whether task slot 4 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAE10
s32 btlTaskSlotLinkedSlot4(void) {
    if (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x200000) {
        return btlTaskSlotIsLinked(4);
    }
    return 0;
}


// FUN_001FAE60
void btlEncounterSetSequence(s32 arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(D_0076449C + 0xB40) = arg0;
    *(s32 *)(D_0076449C + 0xB44) = arg1;
    *(s32 *)(D_0076449C + 0xB48) = arg2;
}


// FUN_001FAE80
s32 btlActionEscapeCondition(u8 *arg0, s32 arg1)
{
    extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u8 arg2, u8 arg3,
                              u32 arg4);
    u8 sp30[0x38];
    s32 temp_16;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_16 = arg1 * 0x28;
    temp_3 = (u8 *)((u32)iGpffffb3b8 + temp_16);
    if ((*(u8 *)temp_3 & 8) == 0) {
        return 0;
    }
    btlEffectCollectTargetUnits(arg0, sp30,
                   *(u8 *)(temp_3 + 9),
                   *(u8 *)(temp_3 + 0xA),
                   *(u16 *)(temp_3 + 0xC));
    if (*(u16 *)(sp30 + 0x38) == 0) {
        return 2;
    }
    switch (*(u8 *)((u8 *)addOffsetFirst((u32)temp_16,
                                         (u32)iGpffffb3b8) + 0x24)) {
    case 2:
        if (btlCond_ESCAPE(arg0, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}


// FUN_001FAF70
s32 btlActionBuffCondition(u8 *arg0, s32 arg1, s32 arg2)
{
    extern s32 datCalcSkillEffectFlags(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3);
    s32 temp_18;
    u32 var_21;
    u32 var_20;
    s32 temp_19;
    s32 temp_2;
    s32 var_2;
    u32 var_18;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!( *(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_18 = *(s32 *)(temp_3 + 0x20);
    if ((temp_18 & 0x7F7FFFFF) && !(temp_18 & 0x80800000)) {
        var_21 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_19 = 1 << var_21;
        if (temp_18 & temp_19) {
            var_20 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask(
                    *(DatUnit **)(*(u8 **)(*(u8 **)(arg0 + (var_20 * 4) + 0x38) +
                                      0x30) + 0xA64),
                    temp_19) != 0) {
                var_20 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_20 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_20 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_21 += 1;
loop_outer_test:
        if (var_21 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_21 == 0x20) {
            if (temp_18 & 0x3000) {
                var_2 = 5;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    var_18 = 0;
    goto loop_24_test;
loop_24_body:
    temp_2 = datCalcSkillEffectFlags(
        arg1 & 0xFFFF,
        (u8 *)*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
        (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) +
                            0x30) + 0xA64),
        arg2);
    if (temp_2 != 0 && temp_2 != 0xFFFF) {
        var_18 += 1;
        goto loop_24_test;
    } else {
        goto loop_24_exit;
    }
loop_24_test:
    if (var_18 < *(u16 *)(arg0 + 0x6A)) {
        goto loop_24_body;
    }
loop_24_exit:
    if (var_18 == *(u16 *)(arg0 + 0x6A)) {
        return 4;
    }
    return 0;
}


// Maps a condition code from btlActionEscapeCondition (0, 2, 6), btlActionBuffCondition or btlBuffMaskCheck* (0, 3, 7) to its battle message id: 2 -> 0x8A, 3 -> 0x8B, 4 -> 0x8C, 5 -> 0x8D, 6 -> 0x8E, 7 -> 0x98, anything else -> 0 (no message).
// FUN_001FB170
s32 btlConditionMessageId(s32 arg0) {
    u32 temp_2;

    temp_2 = arg0 & 0xFFFF;
    switch (temp_2) {
    case 2:
        return 0x8A;
    case 3:
        return 0x8B;
    case 4:
        return 0x8C;
    case 5:
        return 0x8D;
    case 6:
        return 0x8E;
    case 7:
        return 0x98;
    default:
        return 0;
    }
}


// FUN_001FB1F0
s32 btlBuffMaskCheckEntries(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    u32 var_19;
    u32 var_18;
    s32 temp_17;
    s32 var_2;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7F7FFFFF) && !(temp_16 & 0x80800000)) {
        var_19 = 0;
        goto loop_outer_test;
loop_outer_body:
        temp_17 = 1 << var_19;
        if (temp_16 & temp_17) {
            var_18 = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask(
                *(DatUnit **)(*(u8 **)(*(u8 **)(arg0 + (var_18 * 4) + 0x38) + 0x30) + 0xA64),
                temp_17) != 0) {
                var_18 += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            if (var_18 < *(u16 *)(arg0 + 0x6A)) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (var_18 != *(u16 *)(arg0 + 0x6A)) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        var_19 += 1;
loop_outer_test:
        if (var_19 < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (var_19 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
done:
        return 0;
}


/* measured: candidate object 284B/window 288B, normalized_diff 1. Committed at nd 1. */
// FUN_001FB360
s32 btlBuffMaskCheckUnit(u8 *arg0, s32 arg1)
{
    s32 temp_16;
    s32 temp_5;
    s32 var_2;
    u32 var_17;
    u8 *temp_3;

    if (arg1 <= 0) {
        return 0;
    }
    temp_3 = iGpffffb3b8 + (arg1 * 0x28);
    if (!(*(u8 *)(temp_3 + 0) & 8)) {
        return 0;
    }
    temp_16 = *(s32 *)(temp_3 + 0x20);
    if ((temp_16 & 0x7C7FFFFF) && !(temp_16 & 0x83800000)) {
        var_17 = 0;
        goto loop_test;
loop_body:
        temp_5 = 1 << var_17;
        if (!(temp_16 & temp_5)) {
            goto loop_increment;
        }
        if (datCalcHasBuffMask(*(DatUnit **)(*(u8 **)(arg0 + 0x30) + 0xA64),
                          temp_5) == 0) {
            goto loop_after_call;
        }
loop_increment:
        var_17 += 1;
loop_test:
        if (var_17 < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (var_17 == 0x20) {
            if (temp_16 & 0x3000) {
                var_2 = 7;
            } else {
                var_2 = 3;
            }
            return var_2;
        }
    }
    return 0;
}


