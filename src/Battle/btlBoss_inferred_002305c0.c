#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"

typedef struct BtlPacket BtlPacket;

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;

extern u8 *iGpffffa5f0;
extern void sdkSndResetChannel(s32 arg0, s32 arg1);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);
extern void H_Cdvd_Destroy(u8 *ptr);
extern void func_0045ac90(s32 arg0, s32 arg1, s32 arg2);
extern s32 btlBossLoadEndBgmStep(u8 *work);

extern s32 btlCurrentUnitId(void);
extern s64 datGetDateIndex(void);
extern s32 datGetFlag(s32 arg0);
extern s32 func_00106cd0(s32 arg0, s32 arg1);
extern s32 calGetDayWindowFlags(s16 arg0);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void btlBossResolveNpcModelName(s32 arg0, u16 arg1);
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
extern void mdlAttachSlotModelFromResource(void *model, u16 slot, u32 type, u16 id,
                           void *path, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slot, u32 type, u16 id,
                          u32 flags);
extern char D_006357E0[];
extern char D_00635800[];

/* Source unit: src/promoted/code1_0023.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0023.c; members 002305c0-002308a0 */

extern void btlBossResolveNpcModelName(s32 arg0, u16 arg1);
// FUN_002305C0
BtlPacket *btlBossCreateLoadEndBgmPacket(s32 arg0)
{
    u8 *p;
    u8 *work;

    p = btlPacketAlloc(0xE01, 8);
    *(void **)(p + 0x6C) = (void *)btlBossLoadEndBgmStep;
    work = *(u8 **)(p + 0x78);
    *(s32 *)(work + 0) = arg0;
    *(s32 *)(work + 4) = 0;
    return (BtlPacket *)p;
}

// FUN_00230610
s32 btlBossReleaseEndBgmHandle(void)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0xB94);
    if (p != NULL) {
        H_Cdvd_Destroy(p);
        *(u8 **)(iGpffffb3ac + 0xB94) = NULL;
    }
    return 1;
}

// FUN_00230650
BtlPacket *btlBossCreateReleaseEndBgmPacket(void)
{
    u8 *p;

    p = btlPacketAlloc(0xE02, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)btlBossReleaseEndBgmHandle;
    return (BtlPacket *)p;
}

// FUN_00230690
s32 btlBossStepEndBgmHandle(void)
{
    u8 *p;

    p = *(u8 **)(iGpffffb3ac + 0xB94);
    if (p != NULL) {
        func_0045ac90(2, *(s32 *)(p + 0x110), *(s32 *)(p + 0x118));
    }
    return 1;
}

// FUN_002306D0
BtlPacket *btlBossCreateStepEndBgmPacket(void)
{
    u8 *p;

    p = btlPacketAlloc(0xE03, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)btlBossStepEndBgmHandle;
    return (BtlPacket *)p;
}

// FUN_00230710
s32 btlBossStopEndBgm(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB94) != 0) {
        sdkSndResetChannel(2, 0);
    }
    return 1;
}

// FUN_00230750
BtlPacket *btlBossCreateStopEndBgmPacket(void)
{
    u8 *p;

    p = btlPacketAlloc(0xE04, 0);
    p[0x47] &= 0xFE;
    *(void **)(p + 0x6C) = (void *)btlBossStopEndBgm;
    return (BtlPacket *)p;
}

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

// FUN_002308A0
s32 btlBossResolveModelName(u32 arg0, u16 arg1, char *arg2)
{
    s32 temp_16;
    s32 temp_18;
    u8 temp_20;
    switch (arg0 & 0xFFFF)
    {
    case 1:
        temp_16 = arg1 & 0xFFFF;
        if (temp_16 != 3)
        {
            if (datGetFlag(0x1438) != 0 && temp_16 == 1)
                sprintf(arg2, D_00635690, &D_007636e0, temp_16);
            else if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                sprintf(arg2, D_006356B0, &D_007636e0, temp_16);
            else
                sprintf(arg2, D_006356D0, &D_007636e0, temp_16);
        }
        else
        {
            temp_18 = func_00106cd0(3, 0) & 0xFFFF;
            if (temp_18 >= 0x70 && temp_18 < 0x96)
            {
                if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                    sprintf(arg2, D_006356F0, &D_007636e0, temp_18);
                else
                    sprintf(arg2, D_00635710, &D_007636e0, temp_18);
            }
            else if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1)
                sprintf(arg2, D_006356B0, &D_007636e0, temp_16);
            else
                sprintf(arg2, D_006356D0, &D_007636e0, temp_16);
        }
        break;
    case 2:
        sprintf(arg2, D_00635730, D_00635678, arg1 & 0xFFFF);
        break;
    case 3:
        sprintf(arg2, D_00635750, D_00635678, arg1 & 0xFFFF);
        break;
    case 7:
    case 10:
        sprintf(arg2, D_006356F0, &D_007636e0, arg1 & 0xFFFF);
        break;
    case 8:
        sprintf(arg2, D_00635770, &D_007636e0, arg1 & 0xFFFF);
        break;
    case 9:
        temp_20 = (u8)((arg1 & 0xFFFF) >> 8);
        sprintf(arg2, D_00635790, &D_007636e0,
                      temp_20, arg1 & 0xFF);
        break;
    case 5:
        btlBossResolveNpcModelName((s32)arg2, arg1);
        break;
    case 11:
        sprintf(arg2, D_006357B0, &D_007636e0, arg1 & 0xFFFF);
        break;
    }
    return 1;
}

