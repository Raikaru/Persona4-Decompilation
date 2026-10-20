#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "btl_effect_internal.h"
#include "h_cdvd_request_internal.h"

typedef struct BtlPacket BtlPacket;

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;

extern u8 *iGpffffa5f0;
extern void sdkSndResetChannel(s32 value, s32 option);
extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern void sdkSndStartMonoBuffer(s32 channelIndex, s32 source, s32 sourceSize);
extern s32 btlBossLoadEndBgmStep(u8 *work);

extern s32 btlCurrentUnitId(void);
extern s64 datGetDateIndex(void);
extern s32 datGetFlag(s32 bit);
extern s32 datGetEquippedItemByUnit(s32 unitId, s32 slotIndex);
extern s32 calGetDayWindowFlags(s16 day);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void btlBossResolveNpcModelName(s32 destination, u16 modelId);
extern char D_007636e0;
extern char D_006358D0[];
extern char D_006358F0[];
extern char D_00635910[];
extern char D_00635678[];
extern char D_00635690[];
extern char D_006356B0[];
extern char D_006356D0[];
extern char D_006356F0[];
extern char D_00635710[];
extern char D_00635730[];
extern char D_00635750[];
extern char D_00635770[];
extern char D_00635790[];
extern char D_006357B0[];
extern char D_006357C8[];
extern void mdlAttachSlotModelFromResource(void *model, u16 slotIndex, u32 type, u16 id,
                           void *resource, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slotIndex, u32 type, u16 id,
                          u32 flags);
extern char D_006357E0[];
extern char D_00635800[];

extern void btlBossResolveNpcModelName(s32 destination, u16 modelId);
/* Allocate the eight-byte end-BGM loader work and install its update callback. */
// FUN_002305C0
BtlPacket *btlBossCreateLoadEndBgmPacket(s32 id)
{
    u8 *packet;
    u8 *work;

    packet = btlPacketAlloc(0xE01, 8);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlBossLoadEndBgmStep;
    work = (u8 *)((BtlPacket *)packet)->workData;
    ((BtlBossEndBgmLoad *)work)->id = id;
    ((BtlBossEndBgmLoad *)work)->state = 0;
    return (BtlPacket *)packet;
}

/* Release and clear the optional boss end-BGM archive handle. */
// FUN_00230610
s32 btlBossReleaseEndBgmHandle(void)
{
    u8 *handle;

    handle = (u8 *)((BtlBattleState *)iGpffffb3ac)->bossEndBgmHandle;
    if (handle != NULL) {
        H_Cdvd_Destroy(handle);
        ((BtlBattleState *)iGpffffb3ac)->bossEndBgmHandle = 0;
    }
    return 1;
}

/* Queue an immediate end-BGM resource-release callback. */
// FUN_00230650
BtlPacket *btlBossCreateReleaseEndBgmPacket(void)
{
    u8 *packet;

    packet = btlPacketAlloc(0xE02, 0);
    ((BtlPacket *)packet)->flags &= 0xFE;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlBossReleaseEndBgmHandle;
    return (BtlPacket *)packet;
}

/* Submit the loaded end-BGM resource to sound channel 2. */
// FUN_00230690
s32 btlBossStepEndBgmHandle(void)
{
    u8 *handle;

    handle = (u8 *)((BtlBattleState *)iGpffffb3ac)->bossEndBgmHandle;
    if (handle != NULL) {
        sdkSndStartMonoBuffer(2, *(s32 *)&((HCdvdRequest *)handle)->data, ((HCdvdRequest *)handle)->signedSize);
    }
    return 1;
}

/* Queue the loaded end-BGM playback callback. */
// FUN_002306D0
BtlPacket *btlBossCreateStepEndBgmPacket(void)
{
    u8 *packet;

    packet = btlPacketAlloc(0xE03, 0);
    ((BtlPacket *)packet)->flags &= 0xFE;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlBossStepEndBgmHandle;
    return (BtlPacket *)packet;
}

/* Reset sound channel 2 only while the end-BGM resource exists. */
// FUN_00230710
s32 btlBossStopEndBgm(void)
{
    if (((BtlBattleState *)iGpffffb3ac)->bossEndBgmHandle != 0) {
        sdkSndResetChannel(2, 0);
    }
    return 1;
}

/* Queue the conditional end-BGM stop callback. */
// FUN_00230750
BtlPacket *btlBossCreateStopEndBgmPacket(void)
{
    u8 *packet;

    packet = btlPacketAlloc(0xE04, 0);
    ((BtlPacket *)packet)->flags &= 0xFE;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlBossStopEndBgm;
    return (BtlPacket *)packet;
}

/* Map supported boss encounter IDs to unit IDs; unsupported encounters return -1. */
// FUN_00230790
s32 btlBossMapUnitIdToEntryId(void)
{
    switch (btlCurrentUnitId()) {
    case 0x200:
        return 0x100;
    case 0x201:
        return 0x101;
    case 0x202:
        return 0x102;
    case 0x203:
        return 0x103;
    case 0x204:
        return -1;
    case 0x205:
        return 0x105;
    case 0x206:
        return 0x106;
    case 0x207:
        return 0x107;
    case 0x208:
        return 0x108;
    case 0x209:
        return -1;
    case 0x20A:
        return 0x10A;
    case 0x20B:
        return 0x10B;
    case 0x215:
        return 0x10E;
    case 0x20C:
        return -1;
    case 0x20D:
        return -1;
    case 0x214:
        return -1;
    default:
        return -1;
    }
}

/* Format a model path by category, calendar window, and selected costume. */
// FUN_002308A0
s32 btlBossResolveModelName(u32 modelKind, u16 modelId, char *path)
{
    s32 characterId;
    s32 costumeId;
    u8 variant;
    switch (modelKind & 0xFFFF)
    {
    case 1:
        characterId = modelId & 0xFFFF;
        if (characterId != 3)
        {
            if (datGetFlag(0x1438) != 0 && characterId == 1)
                sprintf(path, D_00635690, &D_007636e0, characterId);
            else if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                sprintf(path, D_006356B0, &D_007636e0, characterId);
            else
                sprintf(path, D_006356D0, &D_007636e0, characterId);
        }
        else
        {
            costumeId = datGetEquippedItemByUnit(3, 0) & 0xFFFF;
            if (costumeId >= 0x70 && costumeId < 0x96)
            {
                if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                    sprintf(path, D_006356F0, &D_007636e0, costumeId);
                else
                    sprintf(path, D_00635710, &D_007636e0, costumeId);
            }
            else if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                sprintf(path, D_006356B0, &D_007636e0, characterId);
            else
                sprintf(path, D_006356D0, &D_007636e0, characterId);
        }
        break;
    case 2:
        sprintf(path, D_00635730, D_00635678, modelId & 0xFFFF);
        break;
    case 3:
        sprintf(path, D_00635750, D_00635678, modelId & 0xFFFF);
        break;
    case 7:
    case 10:
        sprintf(path, D_006356F0, &D_007636e0, modelId & 0xFFFF);
        break;
    case 8:
        sprintf(path, D_00635770, &D_007636e0, modelId & 0xFFFF);
        break;
    case 9:
        variant = (u8)((modelId & 0xFFFF) >> 8);
        sprintf(path, D_00635790, &D_007636e0,
                      variant, modelId & 0xFF);
        break;
    case 5:
        btlBossResolveNpcModelName((s32)path, modelId);
        break;
    case 11:
        sprintf(path, D_006357B0, &D_007636e0, modelId & 0xFFFF);
        break;
    }
    return 1;
}

