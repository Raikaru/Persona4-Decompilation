#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_packet_create_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_sound_internal.h"
#include "h_cdvd_request_internal.h"
extern u8 *mdlEffectBuildFromResource(u8 *effect);
extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);
extern s32 btlCond_ESCAPE(u8 *action, s32 conditionValue);

extern BtlBattleState* iGpffffb3ac; /* active battle state */
extern void sdkSndStopMainChannel(void);
extern void sdkSndStopChannel(s32 fadeFrames);

extern void sdkSndFadeOutChannelFrames(s16 channelIndex, s32 requestValue, s32 fadeFrames);

extern BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
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
extern u8 sdkSndStartChannel(s16 channelIndex, const char* path);
extern u8 *D_0076449C;

extern void func_00440b68(const char* fmt, const char* file, s32 line);
extern void* H_Cdvd_AcquireDirectory(const char* path, s32 flags);
extern s32 H_Cdvd_IsFileLoaded(void* cdvd);
extern void H_Cdvd_Destroy(void* cdvd);
extern u8* H_Cdvd_GetArchiveEntry(u8* request, s32 entryIndex, s32* size);
extern s32 sdkSndQueueSlotRequest(s32 slotIndex, void* input, u32 inputSize, void* intermediate, u32 intermediateSize, void* output, u32 outputSize);
extern s32 hsndSlotIsStarting(s32 slotIndex);

extern u32 strlen(const char* text);
extern u32 btlSoundLoadStream(u16* work);
extern void strcpy(char* destination, const char* source);
extern u32 btlSoundClearUnitFlag10(void* work);
extern u32 btlSoundSetUnitFlag10(void* work);
extern u32 btlVoiceEnablePlaybackPacketUpdate(void* context);


/* Stop the main battle stream only when the battle-audio flag is enabled. */
// FUN_001F7530
void btlSoundStopBgmIfEnabled(void)
{
    if ((iGpffffb3ac->flags & 0x40) != 0)
    {
        sdkSndStopMainChannel();
    }
}


/* Fade the main battle stream when audio is enabled. */
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


/* Allocate a cue packet that refreshes the cached channel before playback. */
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


/* Start the packet cue on stream group zero and finish the packet immediately. */
// FUN_001F7CD0
u32 btlSoundPlayCue(s16* work)
{
    u16* values = (u16*)work;

    sdkSndStartStream(0, values[0], values[1], values[2]);
    return 1;
}


/* Allocate a cue packet that stops its channel before starting the requested cue. */
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


/* Begin loading the skill sound directory unless the caller requested deferred loading. */
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

/* Load the skill bank, replace its streams and release the archive once the slot starts. */
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
/* Create a skill sound-bank packet and retain its skill ID and loading flags. */
// FUN_001F8000
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = btlPacketAlloc(0x903, sizeof(BtlSoundPacketSkillSE));
    packet->flags &= ~(1 << 0);
    packet->initFunc = (BtlPacketFunc)btlSoundSkillSEInit;
    packet->updateFunc = btlSoundSkillSEUpdate;
    work = (BtlSoundPacketSkillSE*)packet->workData;
    work->skillId = skillId;
    work->flags = flags;
    return packet;
}


/* Play the fixed cue or advance through the available rotating cue channels. */
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
        if (((BtlSoundQueue *)(global + 0xAC8))->frame == -1)
        {
            channel = ((BtlSoundQueue *)(global + 0xAC8))->channel;
            sdkSndStartStream(2, channel, 0, (s16)state);
            ((BtlSoundQueue *)(D_0076449C + 0xAC8))->frame = 0;
            if ((((BtlSoundQueue *)(D_0076449C + 0xAC8))->channel += 1) >= 9)
            {
                ((BtlSoundQueue *)(D_0076449C + 0xAC8))->channel = 5;
            }
        }
        break;
    }
    return 1;
}
/* Create the two-byte work packet that dispatches a queued cue. */
// FUN_001F8140
BtlPacket* btlSoundCreateCueQueuePacket(u16 state)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x904, 2);
    packet->updateFunc = (BtlPacketFunc)btlSoundRunCueQueue;
    *(u16*)packet->workData = state;
    return packet;
}


/* Format the stream path from the packet name and start its channel. */
// FUN_001F8190
u32 btlSoundLoadStream(u16* work)
{
    char path[512];

    sprintf(path, sGpffffa500, DAT_00624F40, *(u32 *)&((BtlSoundStreamWork *)work)->name);
    sdkSndStartChannel((s16)*work, path);
    return 1;
}


/* Create a stream packet with an owned, trailing copy of its name. */
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
    ((BtlSoundStreamWork *)work)->name = (char*)(work + 8);
    strcpy((char*)work + 8, streamName);
    return packet;
}


/* Clear motion flag 0x10 on units with the motion-state flag set. */
// FUN_001F8280
u32 btlSoundClearUnitFlag10(void* work)
{
    u8* unit;

    unit = (u8*)*(struct BtlUnit**)work;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0)
    {
        ((BtlUnit *)unit)->unk_9d8 &= (u16)~0x10;
    }
    return 1;
}
/* Create the packet that clears the unit motion-flag override. */
// FUN_001F82B0
BtlPacket* btlSoundCreateUnitFlagClearPacket(struct BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x909, 4);
    packet->updateFunc = btlSoundClearUnitFlag10;
    *(struct BtlUnit**)packet->workData = unit;
    return packet;
}


/* Set motion flag 0x10 on units with the motion-state flag set. */
// FUN_001F8300
u32 btlSoundSetUnitFlag10(void* work)
{
    u8* unit;

    unit = (u8*)*(struct BtlUnit**)work;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0)
    {
        ((BtlUnit *)unit)->unk_9d8 |= 0x10;
    }
    return 1;
}
/* Create the packet that enables the unit motion-flag override. */
// FUN_001F8330
BtlPacket* btlSoundCreateUnitFlagSetPacket(struct BtlUnit* unit)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x90A, 4);
    packet->updateFunc = btlSoundSetUnitFlag10;
    *(struct BtlUnit**)packet->workData = unit;
    return packet;
}


/* Create the zero-initialized wait packet used by the target-state callback. */
// FUN_001F97B0
void btlSoundCreateWaitPacket(void)
{
    BtlPacket* packet;
    u32* work;

    packet = btlPacketAlloc(0xA00, 8);
    packet->flags &= ~(1 << 0);
    packet->updateFunc = btlVoiceEnablePlaybackPacketUpdate;
    work = (u32*)packet->workData;
    work[0] = 0;
    work[1] = 0;
}
extern s32 btlCdvdLoadPoll(void);
extern s32 btlSoundLoadPoll(s32 *progress);

extern u8 *iGpffffb3b8;
extern s32 btlSoundLoadPoll(s32 *progress);
extern s32 btlSoundStopStep(void);
extern s32 btlSoundReleaseStep(void);
extern void mdlEffectDestroyWithNodes(s32 effect);
extern void mdlEffectUpdateChildren(s32 effect);
extern void taskRecordRequestPrimary(s32 task);
extern void memcpy(void *input, void *value, u32 option);
extern void func_001fa490(void);
extern s32 btlCdvdLoadPoll(void);
extern s32 btlUnitStatusWindowShow(u8 *action, s16 slotIndex);
extern s32 btlTaskSlotIsLinked(s32 slotIndex);
extern s32 btlTaskSlotIsSet(void);
extern s32 taskRecordIsDone(s32 task);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *action);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerReplyVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerAssistVoice(u8 *action, s32 variant);
extern s32 btlSoundPickRandomPartnerVoice(u8 *action);
extern s32 btlVoiceIdPacketUpdate(u8 *context);
#pragma push
#pragma pop
/* measured: retail hoists the loop invariant into the preheader. Polls the battle state's CDVD file
 * load; once loaded, caches the node, destroys the handle and returns 1. */
// FUN_001FA660
s32 btlCdvdLoadPoll(void)
{
    s32 flags;
    u8 *base;
    u8 *work;
    u8 *flag_ptr;

    base = (u8 *)iGpffffb3ac;
    if (((BtlBattleState *)base)->cutinNameKind == 5) {
        return taskRecordIsDone(((BtlBattleState *)base)->cutinNameTask);
    }
    if (H_Cdvd_IsFileLoaded(((BtlBattleState *)base)->cutinNameHandle) != 0) {
        base = (u8 *)iGpffffb3ac;
        flag_ptr = base + 0xB4C;
        flags = *(s32 *)flag_ptr;
        if ((flags & 2) == 0) {
            work = ((BtlBattleState *)base)->cutinNameHandle;
            *(u8 **)&((BtlSoundNameState *)((u8 *)iGpffffb3ac + 0xB7C))->effect =
                mdlEffectBuildFromResource(*(u8 **)&((HCdvdRequest *)work)->data);
        } else {
            *(s32 *)flag_ptr = flags & ~2;
        }
        H_Cdvd_Destroy(((BtlBattleState *)(u8 *)iGpffffb3ac)->cutinNameHandle);
        ((BtlBattleState *)(u8 *)iGpffffb3ac)->cutinNameHandle = NULL;
        return 1;
    }
    return 0;
}


#pragma push
#pragma pop
/* Create a load packet containing the caller-supplied ten-byte request. */
// FUN_001FA720
u8 *btlSoundLoadPacketNew(const void *request) {
    u8 *packetBytes;

    packetBytes = (u8 *)btlPacketAlloc(0xC04, 0xA);
    ((BtlPacket *)packetBytes)->flags &= 0xEE;
    *(void **)&((BtlPacket *)packetBytes)->initFunc = (void *)func_001fa490;
    *(void **)&((BtlPacket *)packetBytes)->updateFunc = (void *)btlCdvdLoadPoll;
    memcpy(*(s32 **)&((BtlPacket *)packetBytes)->workData, (void *)request, 0xA);
    return packetBytes;
}


/* Steps the sound load at +0xB80 with the progress counter arg0. While the load runs it starts the stream on the first step and loads the table at D_005DC8CC, returning 0. When the load finishes it releases the resource and returns 1. */
// FUN_001FA7A0
s32 btlSoundLoadPoll(s32 *progress)
{
    extern void taskRecordRequestSecondary(s32 task);
    extern s32 mdlEffectIsFinished(s32 effect);
    extern s32 TnGetTableBase(void);
    extern void TnSetTableBase(void *table);
    extern void mdlEffectCommitTreeFrame(s32 effect);
    extern void mdlEffectFlushTreeFrame(u8 *effect);
    extern void mdlEffectDestroyWithNodes(s32 effect);
    extern u8 D_005DC8CC[];
    void *savedTable;
    s32 task;
    s32 effect;
    u8 *battle;

    battle = (u8 *)iGpffffb3ac;
    if (((BtlBattleState *)battle)->cutinNameKind == 5) {
        task = ((BtlBattleState *)battle)->cutinNameTask;
        if (task == 0) {
            return 1;
        }
        if (*progress == 0) {
            taskRecordRequestSecondary(task);
        }
        goto block_12;
    }
    effect = ((BtlSoundNameState *)(battle + 0xB7C))->effect;
    if (effect == 0) {
        return 1;
    }
    if (mdlEffectIsFinished(effect) == 0) {
        if (*progress == 0) {
            sdkSndStartStream(1, 0xE, 2, 0x10);
        }
        savedTable = (void *)TnGetTableBase();
        TnSetTableBase(&D_005DC8CC);
        mdlEffectCommitTreeFrame(((BtlSoundNameState *)((u8 *)iGpffffb3ac + 0xB7C))->effect);
        mdlEffectFlushTreeFrame((u8 *)((BtlSoundNameState *)((u8 *)iGpffffb3ac + 0xB7C))->effect);
        TnSetTableBase(savedTable);
        *progress += 1;
        goto block_12;
    }
    mdlEffectDestroyWithNodes(((BtlSoundNameState *)((u8 *)iGpffffb3ac + 0xB7C))->effect);
    ((BtlSoundNameState *)((u8 *)iGpffffb3ac + 0xB7C))->effect = 0;
    return 1;
block_12:
        return 0;
}


/* Create a polling packet with a zeroed sound-load progress counter. */
// FUN_001FA8F0
void btlSoundLoadTaskStart(void) {
    u8 *packetBytes;

    packetBytes = (u8 *)btlPacketAlloc(0xC05, 4);
    ((BtlPacket *)packetBytes)->flags &= 0xEE;
    *(void **)&((BtlPacket *)packetBytes)->updateFunc = (void *)btlSoundLoadPoll;
    /* The typed packet payload is one progress word; this dereference is not an object-offset access. */
    *((s32 *)((BtlPacket *)packetBytes)->workData) = 0;
}


/* Cancel an outstanding cut-in name load or destroy its live effect and task. */
// FUN_001FA940
s32 btlSoundStopStep(void) {
    s32 effect;
    s32 task;
    u8 *battle;

    battle = D_0076449C;
    if (*(s32 *)&((BtlBattleState *)battle)->cutinNameHandle != 0) {
        *(s32 *)&((BtlBattleState *)battle)->cutinFlags |= 2;
    } else {
        effect = ((BtlSoundNameState *)(battle + 0xB7C))->effect;
        if (effect != 0) {
            mdlEffectDestroyWithNodes(effect);
            ((BtlSoundNameState *)(D_0076449C + 0xB7C))->effect = 0;
        }
    }
    task = ((BtlBattleState *)D_0076449C)->cutinNameTask;
    if (task != 0) {
        taskRecordRequestPrimary(task);
        ((BtlBattleState *)D_0076449C)->cutinNameTask = 0;
    }
    return 1;
}


/* Create the packet that stops pending cut-in sound-name work. */
// FUN_001FA9C0
void btlSoundStopTaskStart(void) {
    u8 *packetBytes;

    packetBytes = (u8 *)btlPacketAlloc(0xC06, 0);
    ((BtlPacket *)packetBytes)->flags &= 0xEE;
    *(void **)&((BtlPacket *)packetBytes)->updateFunc = (void *)btlSoundStopStep;
}


/* Update the cut-in name effect and release any outstanding name task. */
// FUN_001FAA00
s32 btlSoundReleaseStep(void) {
    s32 effect;
    s32 task;

    effect = ((BtlSoundNameState *)(D_0076449C + 0xB7C))->effect;
    if (effect != 0) {
        mdlEffectUpdateChildren(effect);
    }
    task = ((BtlBattleState *)D_0076449C)->cutinNameTask;
    if (task != 0) {
        taskRecordRequestPrimary(task);
        ((BtlBattleState *)D_0076449C)->cutinNameTask = 0;
    }
    return 1;
}


/* Create the packet that releases cut-in name work. */
// FUN_001FAA60
void btlSoundReleaseTaskStart(void) {
    u8 *packetBytes;

    packetBytes = (u8 *)btlPacketAlloc(0xC07, 0);
    ((BtlPacket *)packetBytes)->flags &= 0xEE;
    *(void **)&((BtlPacket *)packetBytes)->updateFunc = (void *)btlSoundReleaseStep;
}


/* Shows the battle status window for slot 0 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAAA0
s32 btlStatusWindowShowSlot0(u8 *unit) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlUnitStatusWindowShow(unit, 0);
    }
    return 0;
}


/* Returns whether task slot 0 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAAF0
s32 btlTaskSlotLinkedSlot0(void) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlTaskSlotIsLinked(0);
    }
    return 0;
}


/* Shows the battle status window for slot 1 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAB40
s32 btlStatusWindowShowSlot1(u8 *unit) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlUnitStatusWindowShow(unit, 1);
    }
    return 0;
}


/* Returns whether task slot 1 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAB90
s32 btlTaskSlotLinkedSlot1(void) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlTaskSlotIsLinked(1);
    }
    return 0;
}


/* Shows the battle status window for slot 2 when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FABE0
s32 btlStatusWindowShowSlot2(u8 *unit) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlUnitStatusWindowShow(unit, 2);
    }
    return 0;
}


/* Returns whether task slot 2 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAC30
s32 btlTaskSlotLinkedSlot2(void) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlTaskSlotIsLinked(2);
    }
    return 0;
}


/* Slot 3 status window: when the flag is set and no task slot is set, runs the callback at +0xB40 once and returns 1; otherwise shows the window for slot 3. */
// FUN_001FAC80
s32 btlStatusWindowShowSlot3Callback(u8 *unit)
{
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    if ((*(s32 *)&((BtlBattleState *)base)->flags & 0x200000) == 0) {
        goto return_zero;
    }
    if (btlTaskSlotIsSet() == 0) {
        base = (u8 *)iGpffffb3ac;
        if (((BtlSoundEncounterSequence *)(base + 0xB40))->start != 0) {
            ((void (*)(void *))(*(void **)&((BtlSoundEncounterSequence *)(base + 0xB40))->start))(
                *(void **)&((BtlSoundEncounterSequence *)(base + 0xB40))->argument);
            return 1;
        }
    }
    return btlUnitStatusWindowShow(unit, 3);
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
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        if (btlTaskSlotIsSet() == 0) {
            base = (u8 *)iGpffffb3ac;
            callback = *(s32 (**)(s32))&((BtlSoundEncounterSequence *)(base + 0xB40))->update;
            if (callback != NULL) {
                result = callback(((BtlSoundEncounterSequence *)(base + 0xB40))->argument);
                if (result == 0) {
                    ((BtlSoundEncounterSequence *)((u8 *)iGpffffb3ac + 0xB40))->start = 0;
                    ((BtlSoundEncounterSequence *)((u8 *)iGpffffb3ac + 0xB40))->update = 0;
                    ((BtlSoundEncounterSequence *)((u8 *)iGpffffb3ac + 0xB40))->argument = 0;
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
s32 btlStatusWindowShowSlot4(u8 *unit) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlUnitStatusWindowShow(unit, 4);
    }
    return 0;
}


/* Returns whether task slot 4 is linked when the flag 0x200000 at +0x0C is set; returns 0 otherwise. */
// FUN_001FAE10
s32 btlTaskSlotLinkedSlot4(void) {
    if (*(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) {
        return btlTaskSlotIsLinked(4);
    }
    return 0;
}


/* Store the encounter sequence callbacks and their shared argument. */
// FUN_001FAE60
void btlEncounterSetSequence(s32 start, s32 update, s32 argument)
{
    ((BtlSoundEncounterSequence *)(D_0076449C + 0xB40))->start = start;
    ((BtlSoundEncounterSequence *)(D_0076449C + 0xB40))->update = update;
    ((BtlSoundEncounterSequence *)(D_0076449C + 0xB40))->argument = argument;
}


/* Check escape skill targets and return the corresponding failure condition. */
// FUN_001FAE80
s32 btlActionEscapeCondition(u8 *action, s32 skillId)
{
    extern void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u8 sideFlags, u8 filterFlags,
                              u32 statusMask);
    u8 targetBuffer[0x38];
    s32 skillOffset;
    u8 *skill;

    if (skillId <= 0) {
        return 0;
    }
    skillOffset = skillId * 0x28;
    skill = (u8 *)((u32)iGpffffb3b8 + skillOffset);
    if ((((BtlSoundSkill *)skill)->flags & 8) == 0) {
        return 0;
    }
    btlEffectCollectTargetUnits(action, targetBuffer,
                   ((BtlSoundSkill *)skill)->targetGroup,
                   ((BtlSoundSkill *)skill)->targetMode,
                   ((BtlSoundSkill *)skill)->targetFlags);
    if (((BtlTargetSelection *)targetBuffer)->count == 0) {
        return 2;
    }
    switch (((BtlSoundSkill *)((u8 *)(((u32)skillOffset) + ((u32)iGpffffb3b8))))->condition) {
    case 2:
        if (btlCond_ESCAPE(action, 0) == 0) {
            return 6;
        }
        break;
    default:
        break;
    }
    return 0;
}


/* Reject a buff when every selected target already has its effects or disallows the skill. */
// FUN_001FAF70
s32 btlActionBuffCondition(u8 *action, s32 skillId, s32 targetMode)
{
    BtlAction *actionState = (BtlAction *)(action);
    extern s32 datCalcSkillEffectFlags(s32 skillId, u8 *source, u8 *target, s32 options);
    s32 effectMask;
    u32 bitIndex;
    u32 targetIndex;
    s32 effectBit;
    s32 result;
    s32 condition;
    u32 targetCursor;
    u8 *skill;

    if (skillId <= 0) {
        return 0;
    }
    skill = iGpffffb3b8 + (skillId * 0x28);
    if (!( ((BtlSoundSkill *)skill)->flags & 8)) {
        return 0;
    }
    effectMask = ((BtlSoundSkill *)skill)->effectFlags;
    if ((effectMask & 0x7F7FFFFF) && !(effectMask & 0x80800000)) {
        bitIndex = 0;
        goto loop_outer_test;
loop_outer_body:
        effectBit = 1 << bitIndex;
        if (effectMask & effectBit) {
            targetIndex = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask(
                    /* Resolve the target action, its unit and the unit data separately. */
                    ((BtlUnit *)(u8 *)(((BtlAction *)((BtlAction *)action)->targets[targetIndex])->unit))->datUnit,
                    effectBit) != 0) {
                targetIndex += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            /* measured: the action alias retains the loop-bound reload across target calls. */
            if (targetIndex < actionState->unk_6a) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (targetIndex != ((BtlAction *)action)->unk_6a) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        bitIndex += 1;
loop_outer_test:
        if (bitIndex < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (bitIndex == 0x20) {
            if (effectMask & 0x3000) {
                condition = 5;
            } else {
                condition = 3;
            }
            return condition;
        }
    }
    targetCursor = 0;
    goto loop_24_test;
loop_24_body:
    result = datCalcSkillEffectFlags(
        skillId & 0xFFFF,
        (u8 *)*(s32 *)&((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit,
        (u8 *)*(s32 *)&((BtlUnit *)(u8 *)(((BtlAction *)((BtlAction *)action)->targets[targetCursor])->unit))->datUnit,
        targetMode);
    if (result != 0 && result != 0xFFFF) {
        targetCursor += 1;
        goto loop_24_test;
    } else {
        goto loop_24_exit;
    }
loop_24_test:
    if (targetCursor < actionState->unk_6a) {
        goto loop_24_body;
    }
loop_24_exit:
    if (targetCursor == ((BtlAction *)action)->unk_6a) {
        return 4;
    }
    return 0;
}


// Maps a condition code from btlActionEscapeCondition (0, 2, 6), btlActionBuffCondition or btlBuffMaskCheck* (0, 3, 7) to its battle message id: 2 -> 0x8A, 3 -> 0x8B, 4 -> 0x8C, 5 -> 0x8D, 6 -> 0x8E, 7 -> 0x98, anything else -> 0 (no message).
// FUN_001FB170
s32 btlConditionMessageId(s32 condition) {
    u32 code;

    code = condition & 0xFFFF;
    switch (code) {
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


/* Check whether all selected targets already carry every requested buff bit. */
// FUN_001FB1F0
s32 btlBuffMaskCheckEntries(u8 *action, s32 skillId)
{
    BtlAction *actionState = (BtlAction *)(action);
    s32 effectMask;
    u32 bitIndex;
    u32 targetIndex;
    s32 effectBit;
    s32 condition;
    u8 *skill;

    if (skillId <= 0) {
        return 0;
    }
    skill = iGpffffb3b8 + (skillId * 0x28);
    if (!(((BtlSoundSkill *)skill)->flags & 8)) {
        return 0;
    }
    effectMask = ((BtlSoundSkill *)skill)->effectFlags;
    if ((effectMask & 0x7F7FFFFF) && !(effectMask & 0x80800000)) {
        bitIndex = 0;
        goto loop_outer_test;
loop_outer_body:
        effectBit = 1 << bitIndex;
        if (effectMask & effectBit) {
            targetIndex = 0;
            goto loop_inner_test;
loop_inner_body:
            if (datCalcHasBuffMask(
                /* Resolve the target action, its unit and the unit data separately. */
                ((BtlUnit *)(u8 *)(((BtlAction *)((BtlAction *)action)->targets[targetIndex])->unit))->datUnit,
                effectBit) != 0) {
                targetIndex += 1;
                goto loop_inner_test;
            } else {
                goto loop_inner_exit;
            }
loop_inner_test:
            /* measured: the action alias retains the loop-bound reload across target calls. */
            if (targetIndex < actionState->unk_6a) {
                goto loop_inner_body;
            }
loop_inner_exit:
            if (targetIndex != ((BtlAction *)action)->unk_6a) {
                goto loop_outer_after;
            }
        }
loop_outer_increment:
        bitIndex += 1;
loop_outer_test:
        if (bitIndex < 0x20U) {
            goto loop_outer_body;
        }
loop_outer_after:
        if (bitIndex == 0x20) {
            if (effectMask & 0x3000) {
                condition = 7;
            } else {
                condition = 3;
            }
            return condition;
        }
    }
done:
        return 0;
}


/* Check whether the acting unit already carries every relevant requested buff bit. */
// FUN_001FB360
s32 btlBuffMaskCheckUnit(u8 *action, s32 skillId)
{
    s32 effectMask;
    s32 effectBit;
    s32 condition;
    u32 bitIndex;
    u8 *skill;

    if (skillId <= 0) {
        return 0;
    }
    skill = iGpffffb3b8 + (skillId * 0x28);
    if (!(((BtlSoundSkill *)skill)->flags & 8)) {
        return 0;
    }
    effectMask = ((BtlSoundSkill *)skill)->effectFlags;
    if ((effectMask & 0x7C7FFFFF) && !(effectMask & 0x83800000)) {
        bitIndex = 0;
        goto loop_test;
loop_body:
        effectBit = 1 << bitIndex;
        if (!(effectMask & effectBit)) {
            goto loop_increment;
        }
        if (datCalcHasBuffMask(((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit,
                          effectBit) == 0) {
            goto loop_after_call;
        }
loop_increment:
        bitIndex += 1;
loop_test:
        if (bitIndex < 0x20U) {
            goto loop_body;
        }
loop_after_call:
        if (bitIndex == 0x20) {
            if (effectMask & 0x3000) {
                condition = 7;
            } else {
                condition = 3;
            }
            return condition;
        }
    }
    return 0;
}
