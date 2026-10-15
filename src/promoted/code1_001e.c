#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern f32 RwV3dLength(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *RtQuatTransformVectors(void *out, const void *in, s32 count, const void *rotation);
extern f32 sqrtf(f32 arg0);
extern u8 *func_001b0cc0();
extern void *D_00609850[];
extern s32 datCalcMaxHp();
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();
extern u16 datCalcMaxSp();
extern s32 datCalcGetSp();

extern s32 datCalcSkillElement(u8 *unit, u16 skill);
extern u32 datCalcGetTableLength(u8 *arg0);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcAilmentChance(u8 *arg0, s32 arg1);
extern u8 *func_001b1510(void);
extern u8 *func_0029d050();

extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern void func_00213b80(s32 task);
extern void func_00213b50(s32 task);
extern s32 func_001eb860(void);
extern void func_00212240(u8 *arg0, s32 arg1);
extern void func_00212210(s32 task);
extern s32 func_001ef9a0(void);
extern s32 D_00724504;
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern void btlActionFinishPresentation(s32 arg0);
extern BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 *btlCameraCreateSetStatePacket(s32 arg0, s32 arg1);
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
extern u8 *func_001d9280();
extern u8 *func_001d8c00();
extern u8 *btlAICommandPickUnitByHpWeight();
extern s32 btlAICommandCollectSkillCandidates();
extern s32 btlAICommandCollectCommandsOfType();
extern s32 btlSideSelectUnits();
extern s32 btlAICommandAlwaysTrue(void);


extern void btlPacketEnqueue(u8 *arg0, s32 arg1);
extern u8 *btlTargetCreateEmptyPacket(void);
extern u8 *func_001f6030(s32 arg0, s64 arg1);
extern s32 func_00193b70(s64 arg0, s64 arg1);
extern void func_003dc740(void *arg0, void *arg1, f32 arg3, s32 arg2);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u8 *func_001b1560(void);
extern void func_001eb410(u8 *arg0);
extern u32 datCalcRandomBelow(u32 arg0);



extern void btlUnitInitChild(u8 *arg0, u64 arg1);
extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
extern s32 btlAICommandPickTableAction(u8 *arg0);
extern u8 *func_001dea90(u8 *arg0, u32 arg1);
extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 scrGetParamFloat(s32 arg0);
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 *func_001bcb50(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 arg6, f32 arg7);
extern BtlPacket *func_002306d0(void);
extern u8 *func_001f81f0(s32 arg0, void *arg1);
extern void sprintf(void *arg0, void *arg1, s64 arg2);
extern u8 D_00609E40[];
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBattleStat(s32 arg0, s32 arg1);
extern s32 datCalcGetHp(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern s32 datGetFlag(s32 arg0);
extern s32 btlUnitFindInSideById(s32 arg0, s32 arg1);
extern s32 func_001b0c80(s32 arg0);
extern void func_001fae60(s32 initialize, s32 update, s32 packet);
extern void func_0022b120(u8 *action);
extern s32 func_0022b870(u8 *action);
extern void btlAICommandSpawnActionProc(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern u8 *btlPacketAlloc(s32 arg0, s32 arg1);
extern u8 *func_0022ced0(s32 arg0);
extern s32 scrFindPrcdIdxByName(s32 arg0, s32 arg1);
extern s32 btlTargetSpawnActionProc(u8 *arg0);
extern u8 *iGpffffb428;
extern u16 func_00107ac0(s32 arg0);
extern void func_00106550(s32 arg0, s32 arg1);
extern s32 datCalcIsStatusBlocked(u16 *arg0);
extern u16 func_00247cb0(s64 arg0);
extern u8 *iGpffffb42c;
// FUN_001E6B90
s32 func_001e6b90(void) {
    u32 a = scrGetParamIntS32(0);
    u32 b = scrGetParamIntS32(1);
    u8 *p = func_001b0cc0(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x48000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x48000000) & 0xFFFFFF;
    s32 x;

    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}
// FUN_001E6C60
s32 func_001e6c60(void) {
    u8 *temp_2;
    u32 index;

    temp_2 = func_0029d050();
    if ((func_001d7f10(temp_2, 0, *(u16 *)(temp_2 + 0x6E), 0) & 0xFFFF) == 0) {
        index = scrGetParamIntS32(0);
        *(u8 **)(temp_2 + 0x38) = func_001b0cc0(index & 0xFFFFFFF);
        *(s16 *)(temp_2 + 0x6A) = 1;
    } else if (((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0) == 0) {
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_2, 0);
    }
    return 1;
}

// FUN_001E6FA0
s32 func_001e6fa0(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7080
s32 func_001e7080(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7160
s32 func_001e7160(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7240
s32 func_001e7240(void) {
    u16 count;
    u8 *work;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}
// FUN_001E7320
s32 func_001e7320(void)
{
    int count;
    u8 *work;
    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1)
    {
        count = *(u16 *)(work + 0x6A);
        if (count == 1)
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        }
        else
        {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    }
    else
    {
        scrSetReturnInt(-1);
    }
    return 1;
}
#pragma push
#pragma opt_rebuildconditionals off
static inline u16 p4_formation_get_opposing_genus(u32 unit)
{
    u32 side;
    if (*(u8 *)(*(s32 *)(unit + 0x30) + 0xA2) != 0)
        goto nonzero;
    side = 1;
    goto done;
nonzero:
    side = 0;
done:
    return side;
}
#pragma pop













// FUN_001E8BB0
s32 func_001e8bb0(void) {
    u64 temp_16;
    u64 temp_17;
    u8 *temp_19;
    u64 temp_18;

    temp_19 = func_0029d050();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectCommandsOfType(temp_19, func_001b0cc0((u64)(temp_17 << 0x24) >> 0x24), (s16)temp_16, temp_18));
    return 1;
}

// FUN_001E8CD0
s32 func_001e8cd0(void) {
    u64 temp_16;
    u8 *temp_19;
    u64 temp_18;
    u64 temp_17;

    temp_19 = func_0029d050();
    temp_16 = scrGetParamInt(0);
    temp_18 = scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    scrSetReturnInt(btlAICommandCollectSkillCandidates(temp_19, func_001b0cc0((u64)(temp_16 << 0x24) >> 0x24), temp_18, temp_17));
    return 1;
}



// FUN_001EA2D0
s32 func_001ea2d0(void) {
    u64 temp_16;
    u8 *temp_18;
    u64 temp_17;

    temp_18 = func_0029d050();
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    btlUnitInitChild(*(u8 **)(temp_18 + 0x30), temp_17);
    btlAICommandSetActionCode(temp_18, temp_18 + 0x38, temp_16 & 0xFFFF);
    return 1;
}
// FUN_001EA360
s32 func_001ea360(void) {
    u8 *temp;

    temp = func_0029d050();
    *(s16 *)(temp + 0x6C) = 5;
    return 1;
}
// FUN_001EA390
s32 func_001ea390(void)
{
    u8 *work;
    s32 index;

    work = func_0029d050();
    index = scrGetParamIntS32(0);
    if ((iGpffffb3b8[index * 0x28] & 2) == 0) {
        kAssertFail(D_00609E30, 5711);
    }
    *(u16 *)(work + 0x6C) = 1;
    *(u16 *)(work + 0x6E) = index;
    return 1;
}
// FUN_001EA420
s32 func_001ea420(void)
{
    scrSetReturnInt(((*(u32 *)(D_00724504 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18))) & 0x20) != 0);
    return 1;
}

// FUN_001EA470
s32 func_001ea470(void) {
    scrSetReturnInt(*(s16 *)(iGpffffb3ac + 0xC34));
    return 1;
}

// FUN_001EA4A0
s32 func_001ea4a0(void) {
    s32 temp_2;
    s32 temp_2_2;

    if (func_001ef9a0() != 0x20B)
        goto set_flag;
    if (datGetFlag(0x15FF) != 1)
        goto body;
set_flag:
    *(s32 *)(iGpffffb3ac + 0x10) |= 0x10000000;
    goto done;
body:
    if (*(void **)(iGpffffb3ac + 0xB40) == (void *)func_0022b120)
        goto done;
    if (*(void **)(iGpffffb3ac + 0xB44) == (void *)func_0022b870)
        goto done;
    temp_2 = btlUnitFindInSideById(1, 0x10B);
    if (temp_2 == 0)
        goto done;
    temp_2_2 = func_001b0c80(temp_2);
    if (temp_2_2 == 0)
        goto done;
    func_001fae60((s32)func_0022b120, (s32)func_0022b870, temp_2_2);
done:
    return 1;
}
// FUN_001EA580
s32 func_001ea580(void)
{
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket(*(s32 *)(iGpffffb3ac + 0x170), 0x21), 0);
    return 1;
}

// FUN_001EA5F0
s32 func_001ea5f0(void)
{
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(btlCameraCreateSetStatePacket(*(s32 *)(iGpffffb3ac + 0x170), 0x2C), 0);
    return 1;
}


// FUN_001EA660
s32 func_001ea660(void)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } first;
    struct Vec3 first_copy;
    struct Vec3 second;
    struct Vec3 second_copy;
    f32 value;

    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    first.x = scrGetParamFloat(0);
    first.y = scrGetParamFloat(1);
    first.z = scrGetParamFloat(2);
    second.x = scrGetParamFloat(3);
    second.y = scrGetParamFloat(4);
    second.z = scrGetParamFloat(5);
    value = scrGetParamFloat(6);
    first_copy = first;
    second_copy = second;
    btlPacketEnqueue(func_001bcb50(
        *(s32 *)(iGpffffb3ac + 0x170),
        (f32 *)&first,
        (f32 *)&second,
        value,
        (f32 *)&first_copy,
        (f32 *)&second_copy,
        value,
        1.0f), 0);
    return 1;
}
// FUN_001EA780
s32 func_001ea780(void) {
    D_00881420[0] = scrGetParamFloat(0);
    D_00881424[0] = scrGetParamFloat(1);
    D_00881428[0] = scrGetParamFloat(2);
    D_00881400[0] = scrGetParamFloat(3);
    D_00881404[0] = scrGetParamFloat(4);
    D_00881408[0] = scrGetParamFloat(5);
    fGpffffb458 = scrGetParamFloat(6);
    return 1;
}
// FUN_001EA830
s32 func_001ea830(void) {
    D_00881410[0] = scrGetParamFloat(0);
    D_00881414[0] = scrGetParamFloat(1);
    D_00881418[0] = scrGetParamFloat(2);
    D_008813F0[0] = scrGetParamFloat(3);
    D_008813F4[0] = scrGetParamFloat(4);
    D_008813F8[0] = scrGetParamFloat(5);
    fGpffffb454 = scrGetParamFloat(6);
    return 1;
}
// FUN_001EA8E0
s32 func_001ea8e0(void) {
    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
    btlPacketEnqueue(func_001bcb50(
        *(s32 *)(iGpffffb3ac + 0x170),
        &D_00881420[0],
        &D_00881400[0],
        fGpffffb458,
        &D_00881410[0],
        &D_008813F0[0],
        fGpffffb454,
        (f32)scrGetParamIntS32(0) / 30.0f), 0);
    return 1;
}
// FUN_001EAA80
s32 func_001eaa80(void) {
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    }
    return 1;
}
// FUN_001EAAC0
s32 func_001eaac0(void)
{
    u8 *temp_4;

    if (func_001eb860() == 1) {
        temp_4 = iGpffffb3ac;
        *(s32 *)(temp_4 + 0xC) = *(s32 *)(temp_4 + 0xC) & ~0x2000;
        func_001eb7f0();
    }
    return 1;
}

// FUN_001EAB10
s32 func_001eab10(void) {
    func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 1);
    }
    return 1;
}

// FUN_001EAB60
s32 func_001eab60(void) {
    func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (func_001eb860() == 1) {
        func_00212240(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
    }
    return 1;
}

// FUN_001EABC0
s32 func_001eabc0(void) {
    u8 *p = func_001b1510();
    u32 a = scrGetParamIntS32(0) & 0xFFFF;
    u32 b = scrGetParamIntS32(1) & 0xFFFF;
    u32 flag = 1;

    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    scrSetReturnInt(flag != 0);
    return 1;
}
// FUN_001EACA0
/* measured probe: preserve the retail filter branch chain */
#pragma push
#pragma opt_rebuildconditionals off
s32 func_001eaca0(void) {
    extern s32 btlFormationAllocWork(u32 arg0);
    extern void btlFormationCopyRecord(u8 *arg0, u8 *arg1);
    extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
    extern void btlFormationSetPlacement(u8 *arg0);
    extern s32 func_00243ce0(s32 arg0);
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_2;
    u8 *temp_16;
    s32 temp_4;
    u16 temp_3_2;

    temp_16 = (u8 *)btlFormationAllocWork(0);
    temp_4 = scrGetParamIntS32(0) & 0xFFFF;
    temp_4 = temp_4 + 1;
    btlFormationCopyRecord(temp_16, func_0022ced0(temp_4 & 0xFFFF));
    temp_18 = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_17 = *(u8 **)(iGpffffb3ac + 0x180);
    goto loop_test;
loop_body:
    temp_4 = *(s32 *)(var_17 + 0xA64);
    if (temp_4 == 0)
        goto loop_advance;
    if (func_00243ce0(temp_4) == 0)
        goto loop_advance;
    temp_3_2 = *(u16 *)(var_17 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x10F:
    case 0x110:
    case 0x111:
        goto loop_advance;
    default:
        goto selected;
    }
loop_advance:
    var_17 = *(u8 **)(var_17 + 0xA6C);
loop_test:
    if (var_17 != NULL)
        goto loop_body;
selected:
    if (var_17 == NULL)
        var_17 = temp_18;
    temp_2 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_18, (u32)var_17, 0, 0x200);
    btlPacketEnqueue(temp_2, 2);
    *(s64 *)(iGpffffb3ac + 0xBD0) = *(s64 *)(temp_2 + 0x58);
    var_17 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_18, (u32)var_17, 1, 0x200);
    btlPacketEnqueue(var_17, 2);
    *(s64 *)(iGpffffb3ac + 0xBD8) = *(s64 *)(var_17 + 0x58);
    btlFormationSetPlacement(temp_16);
    return 1;
}
/* measured probe: close the filter branch chain */
#pragma pop
// FUN_001EAE30
s32 func_001eae30(void) {
    s64 mask;
    s32 hit;

    mask = 0x3FFFFFFFFFFFFFFFLL;
    if (func_00193b70(*(s64 *)(iGpffffb3ac + 0xBD0), mask) != 0)
        return 0;
    hit = func_00193b70(*(s64 *)(iGpffffb3ac + 0xBD8), mask) != 0;
    return hit ^ 1;
}
// FUN_001EAEC0
s32 func_001eaec0(void)
{
    extern u8 *func_001d9280(s64 arg0, s32 arg1, s32 arg2);
    s64 temp_20;
    s64 temp_19;
    s64 temp_18;
    s64 temp_17;
    s64 temp_16;
    s32 var_2;
    u8 *temp_2;

    temp_20 = scrGetParamInt(0);
    temp_19 = scrGetParamInt(1);
    temp_18 = scrGetParamInt(2);
    temp_17 = scrGetParamInt(3);
    temp_16 = scrGetParamInt(4);
    if (temp_20 == 0) {
        var_2 = 1;
    } else {
        var_2 = 2;
    }
    temp_2 = func_001d9280(temp_19 & 0xFFFF, var_2 & 0xFFFF, 0x80000);
    if (temp_2 != NULL) {
        func_00198920(*(u8 **)(temp_2 + 0x30), (s16)temp_18, (u16)temp_17, 1.0f, (u16)temp_16);
    }
    return 1;
}
// FUN_001EAFB0
/* measured probe: preserve retail conditional branch shape */
#pragma push
#pragma opt_rebuildconditionals off
s32 func_001eafb0(void) {
    extern void btlTargetPositionToCell();
    extern void btlUnitSetPos();
    extern s64 scrGetParamInt();
    extern f32 scrGetParamFloat();
    f32 sp30[3];
    s32 temp_16;
    s32 temp_17;
    s32 var_2;
    s32 var_4;
    u8 *var_17;

    temp_17 = scrGetParamIntS32(0);
    temp_16 = scrGetParamIntS32(1);
    sp30[0] = scrGetParamFloat(2);
    sp30[1] = scrGetParamFloat(3);
    sp30[2] = scrGetParamFloat(4);
    var_4 = 0;
    if (temp_17 != 0)
        goto set_one;
    var_2 = 0;
    goto select_table;
set_one:
    var_2 = 1;
select_table:
    var_17 = *(u8 **)(p4_slot_001eb320((u32)(var_2 * 8), iGpffffb3ac) + 0x17C);
    goto loop_test;
loop_body:
    if (temp_16 == var_4) {
        btlTargetPositionToCell(var_17 + 0x94, var_17 + 0x96, &sp30[0]);
        btlUnitSetPos(var_17, &sp30[0]);
        goto done;
    }
    var_4 += 1;
    var_17 = (u8 *)(*(u8 **)(var_17 + 0xA68));
loop_test:
    if (var_17 != NULL)
        goto loop_body;
done:
    return 1;
}
/* measured probe: close conditional branch shape */
#pragma pop
// FUN_001EB0B0
s32 func_001eb0b0(void) {
    u8 *o;

    btlActionFinishPresentation(*(s32 *)(iGpffffb3ac + 0x170));
    o = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s16 *)(o + 0x48) = 3;
    btlPacketEnqueue(o, 0);
    return 1;
}

/* measured: the typed call view removes the dead s64 narrowing pair; the
   volatile gp load and offset helper reproduce retail's load/shift/addu order. */

// FUN_001EB110
s32 func_001eb110(void) {
    u8 sp20[0x200];
    s64 temp_16;
    s64 temp_2;
    u8 *temp_2_2;

    temp_16 = scrGetParamInt(0);
    temp_2 = scrGetParamInt(1);
    switch (temp_2) {
    case 0:
        temp_2_2 = (u8 *)func_002306d0();
        *(s16 *)(temp_2_2 + 0x48) = 2;
        btlPacketEnqueue(temp_2_2, 1);
        break;
    case 1:
        sprintf(&sp20[0], &D_00609E40[0], temp_16);
        btlPacketEnqueue(func_001f81f0(2, &sp20[0]), 1);
        break;
    }
    return 1;
}

// FUN_001EB2A0
s32 func_001eb2a0(void) {
    s32 temp;

    temp = scrGetParamIntS32(0);
    temp = datCalcRandomBelow(temp);
    scrSetReturnInt(temp);
    return 1;
}

/* measured: optimization_level 1 probe for retail GP-load scheduling. */
#pragma optimization_level 1
// FUN_001EB2E0
s32 func_001eb2e0(void) {
    s32 index;
    u8 *slot;

    index = scrGetParamIntS32(0);
    slot = p4_slot_001eb320((u32)index * 4, iGpffffb3ac);
    scrSetReturnInt(*(s32 *)(slot + 0xDD8));
    return 1;
}
/* measured: close optimization_level 1 probe for func_001eb2e0. */
#pragma optimization_level 2
/* measured: opt_propagation off probe for e320 GP-load order. */
#pragma opt_propagation off
// FUN_001EB320
s32 func_001eb320(void)
{
    s32 idx;
    s32 value;

    idx = scrGetParamIntS32(0);
    value = scrGetParamIntS32(1);
    *(s32 *)(p4_slot_001eb320((u32)idx * 4, iGpffffb3ac) + 0xDD8) = value;
    return 1;
}
/* measured: closes opt_propagation probe for func_001eb320. */
#pragma opt_propagation on

// FUN_001EB370
s32 func_001eb370(void)
{
    return 1;
}

// FUN_001EB380
void func_001eb380(u8 *arg0) {
    memset(arg0, 0, 0x5C);
}

// FUN_001EB3B0
void func_001eb3b0(u8 *arg0) {
    u8 *temp;

    temp = arg0;
    func_001eb410(temp);
    *(s16 *)(temp + 0x36) = 0;
    *(s16 *)(temp + 0x38) = 0;
    *(s16 *)(temp + 0x34) = 0;
    *(s32 *)(temp + 0x50) = 0;
    *(s32 *)(temp + 0x54) = 0;
    *(s32 *)(temp + 0x58) = 0;
    memset(temp + 0x3E, 0, 6);
}
// FUN_001EB410
void func_001eb410(u8 *arg0) {
    *(s16 *)(arg0 + 0x32) = 0;
}
// FUN_001EB4A0
/* measured: u16 state selects the narrow daddiu constants at 0x001eb598 and
   0x001eb5c0; the table-entry scan preserves the retail register-width masks. */
/* The action caller forwards the 32-bit unit-status word. This selector
 * consumes its low20 bits; higher bits have no role in table selection. */
void func_001eb4a0(u8 *arg0, u8 *arg1, u32 status) {
    extern s32 func_00105ed0();
    extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
    extern s32 datCalcRandomBelow(u32 arg0);
    extern void memset(void *arg0, s32 arg1, s32 arg2);
    extern void *D_006098BC[];
    extern void *D_00609934[];
    extern u8 D_00609E50[];
    extern u8 D_00609EF0[];
    extern u8 D_00609F90[];
    extern u8 D_0060A030[];
    extern u8 *iGpffffb3c4;
    extern u8 iGpffffa4d8;
    u8 *table;
    u32 actionWord;
    s32 threshold;
    u16 state;
    s32 index;
    s32 sum;
    s32 cumulative;
    s32 scanIndex;
    u64 mode;
    u8 *current;
    u8 *entry;
    u8 weight;
    u8 *row;
    u8 *unitData;
    u8 *unit;
    s32 (*callback)(u8 *, s64);

    *(u16 *)(arg1 + 0x32) = 0;
    *(u16 *)(arg1 + 0x36) = 0;
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x34) = 0;
    *(u32 *)(arg1 + 0x50) = 0;
    *(u32 *)(arg1 + 0x54) = 0;
    *(u32 *)(arg1 + 0x58) = 0;
    memset(arg1 + 0x3E, 0, 6);
    table = NULL;
    entry = NULL;
    mode = ((u64)status << 44) >> 44;
    switch (mode) {
    case 0x10:
        unit = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unit + 0xA2) == 1) {
            if ((*(u16 *)(iGpffffb3c4 + *(u16 *)(unit + 0xA4) * 0x3C) & 0x2000) == 0 &&
                (*(u16 *)(arg0 + 0x1A) & 0x4000) == 0) {
                state = 0;
            } else {
                state = 2;
            }
        } else if (func_00105ed0() != 0) {
            state = 0;
        } else {
            state = 2;
        }
        if (((s32 (*)(u8 *, s32))D_006098BC[0])(arg0, 1) != 0)
            state++;
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0)
            table = D_00609E50;
        else
            table = D_00609EF0;
        break;
    case 4:
        unitData = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(unitData + 0xA2) == 0 && *(u16 *)(unitData + 0xA4) == 1) {
            state = 1;
        } else {
            state = (u16)(((s32 (*)(u8 *, s32))D_00609934[0])(arg0, 0) != 1);
        }
        table = D_00609F90;
        break;
    case 2:
        entry = (u8 *)&iGpffffa4d8 - 8;
        break;
    case 0x100:
        state = 0;
        table = D_0060A030;
        break;
    }
    if (table != NULL) {
        sum = 0;
        index = 0;
        row = table + (state & 0xFFFF) * 0x28;
        goto eb4a0_sum_test;
eb4a0_sum_body:
        sum = (sum + *(u8 *)(row + ((u16)index * 8))) & 0xFFFF;
        index = (index + 1) & 0xFFFF;
eb4a0_sum_test:
        if ((index & 0xFFFF) < 5)
            goto eb4a0_sum_body;
        entry = NULL;
        threshold = (s32)(datCalcRandomBelow(sum & 0xFFFF) & 0xFFFF);
        cumulative = 0;
        for (scanIndex = 0; (scanIndex & 0xFFFF) < 5;
             scanIndex = (scanIndex + 1) & 0xFFFF) {
            current = row + ((u16)scanIndex * 8);
            weight = *(u8 *)current;
            cumulative = (cumulative + weight) & 0xFFFF;
            if (threshold <= cumulative && weight > 0) {
                entry = current;
                break;
            }
        }
    }
    btlAICommandSetActionCode(arg0, arg1, *(u16 *)(entry + 2));
    actionWord = *(u32 *)(entry + 4);
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 +
                                      (((actionWord & 0xFF000000) >> 24) * 8));
    if (callback(arg0, (s64)((u64)actionWord << 40 >> 40)) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(arg0, 0);
}
// FUN_001EB7F0
void func_001eb7f0(void) {
    s32 temp_4;
    u8 *temp_3;
    u8 *temp_5;

    temp_3 = iGpffffb3ac;
    temp_5 = temp_3 + 0xC;
    temp_4 = *(s32 *)(temp_3 + 0xC);
    if (temp_4 & 0x1000) {
        *(s32 *)temp_5 = temp_4 & ~0x1000;
        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_0045af60(1, 0xF, 2, 0x13);
    }
}
// FUN_001EB860
s32 func_001eb860(void) {
    u8 *temp_3;
    s32 result;

    temp_3 = iGpffffb3ac;
    if (*(s32 *)(temp_3 + 0xC) & 0x80) {
        result = 0;
        goto done;
    }
    if (*(s32 *)(temp_3 + 0xC68) != 0) {
        if (func_001ef9a0() == 0x215) {
            result = 0;
            goto done;
        }
    }
    result = 1;
done:
    return result;
}
// FUN_001EB8D0
void func_001eb8d0(void) {
    extern void func_002121b0(s32 task);
    extern void func_00212210(s32 task);
    extern u16 D_008C024E[];
    s32 flags;
    s32 temp_5;
    s32 var_3;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_4 = iGpffffb3ac;
    if (*(s32 *)(temp_4 + 0xC) & 0x80) {
        var_3 = 0;
    } else if ((*(s32 *)(temp_4 + 0xC68) != 0) &&
               (func_001ef9a0() == 0x215)) {
        var_3 = 0;
    } else {
        var_3 = 1;
    }
    if ((var_3 != 0) &&
        (temp_3 = iGpffffb3ac,
         temp_6 = temp_3 + 0xC,
         flags = *(s32 *)(temp_3 + 0xC),
         ((flags & 0x2000) != 0))) {
        temp_5 = flags & 0x1000;
        if (temp_5 != 0) {
            if (((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20)) &&
                (temp_5 != 0)) {
                *(s32 *)temp_6 = *(s32 *)temp_6 & ~0x1000;
                func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));
                func_0045af60(1, 0xF, 2, 0x13);
            }
        } else if ((D_008C024E[0] & 0x10) && (temp_5 == 0)) {
            *(s32 *)temp_6 = flags | 0x1000;
            func_002121b0(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_0045af60(1, 0xF, 2, 0x12);
        }
    }
}
// FUN_001EBB00
u8 *func_001ebb00(s32 arg0, s32 arg1, u8 *arg2) {
    s32 kind;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = btlPacketAlloc(0xD00, 0x10);
    *(u8 *)(temp_2 + 0x47) &= 0xEE;
    *(s32 *)(temp_2 + 0x6C) = (s32)btlTargetSpawnActionProc;
    temp_16 = *(u8 **)(temp_2 + 0x78);
    kind = arg1 & 0xFFFF;
    switch (kind) {
    case 1:
        *(s32 *)(temp_16 + 0xC) = (s32)iGpffffb428;
        break;
    case 2:
        *(s32 *)(temp_16 + 0xC) = (s32)iGpffffb42c;
        break;
    case 3:
        *(s32 *)(temp_16 + 0xC) = (s32)func_0022ced0(0);
        break;
    }
    *(s32 *)(temp_16 + 0x0) = arg0;
    *(s32 *)(temp_16 + 0x4) = scrFindPrcdIdxByName(*(s32 *)(temp_16 + 0xC), (s32)arg2);
    *(s32 *)(temp_16 + 0x8) = 0;
    return temp_2;
}
// FUN_001EBC00
/* 1468/1472 bytes; all four call relocations resolve exactly. */
#pragma opt_common_subs off
void func_001ebc00(u8 *action, u8 *command)
{
    u16 choices[8];
    u16 *skills;
    s32 index;
    s32 count;
    u32 skill;
    u32 available;

    skills = (u16 *)datCalcSkillList(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    count = 0;
    index = 0;
    while ((index & 0xFFFF) < 8) {
        skill = skills[index & 0xFFFF];
        if (skill != 0) {
            switch (skill) {
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x21:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA8:
            case 0xA9:
            case 0xAB:
            case 0xAC:
            case 0xAD:
                if (datCalcThresholdTrigger(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), skill) == 0) {
                    choices[count & 0xFFFF] = skill;
                    count = (count + 1) & 0xFFFF;
                }
                break;
            }
        }
        index = (index + 1) & 0xFFFF;
    }
    available = count & 0xFFFF;
    if (available == 0) {
        *(u16 *)(command + 0x34) = 1;
        *(u16 *)(command + 0x36) = datCalcDefaultSkillId(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    } else {
        *(u16 *)(command + 0x34) = 2;
        *(u16 *)(command + 0x36) = choices[datCalcRandomBelow(available)];
    }
}
#pragma opt_common_subs on
// FUN_001EC350
f32 func_001ec350(f32 *arg0, f32 *arg1)
{
    f32 zero;
    f32 length;

    zero = 0.0f;
    length = sqrtf(
        arg0[0] * arg0[0] +
        arg0[1] * arg0[1] +
        arg0[2] * arg0[2] +
        arg0[3] * arg0[3]);
    if (zero != length) {
        arg1[0] = arg0[0] / length;
        arg1[1] = arg0[1] / length;
        arg1[2] = arg0[2] / length;
        arg1[3] = arg0[3] / length;
    }
    return length;
}
/* measured: third 001ec5e0 probe tests opt_propagation off for FPU-zero placement. */
#pragma opt_propagation off
// FUN_001EC5E0
void func_001ec5e0(u8 *arg0, f32 arg1)
{
    f32 zero;

    *(f32 *)arg0 = arg1;
    *(f32 *)(arg0 + 4) = arg1;
    zero = 0.0f;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    if (zero != arg1) {
        *(f32 *)(arg0 + 8) = 1.0f / ((arg1 * arg1) / 4.0f);
    }
}
/* measured: closes opt_propagation probe for func_001ec5e0. */
#pragma opt_propagation on
// FUN_001ED060
int func_001ed060(float *param_1, float *param_2)
{
    u8 *node;
    int i;

    if (*(u8 **)((u8 *)param_2 + 0x10) == (u8 *)param_1)
    {
        return 1;
    }

    for (node = *(u8 **)(iGpffffb3ac + 0x318); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            int wrap = (i + 1) & 3;
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next;

            if ((edge == param_1) || (edge == param_2))
            {
                continue;
            }
            next = (float *)(node + wrap * 0x130 + 0x08);
            if ((next == param_1) || (next == param_2))
            {
                continue;
            }
            else
            {
                int intersects;
                int side_a = btlTargetCheckSide(edge, next, param_1);
                int side_b = btlTargetCheckSide(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = btlTargetCheckSide(param_1, param_2, edge);
                    side_b = btlTargetCheckSide(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }

    {
        u8 *record;
        float *next;
        float *edge;
        u8 *node2;
        int j;
        for (node2 = *(u8 **)(iGpffffb3ac + 0x318); node2 != NULL; node2 = *(u8 **)(node2 + 0x4cc))
        for (j = 0; j < 4; ++j)
        {
            record = node2 + j * 0x130;
            edge = (float *)(record + 0x08);

            if (edge == param_1)
            {
                return 0;
            }
            if (*(float *)(record + 0x1c) <= 0.0f)
            {
                continue;
            }
            next = *(float **)(record + 0x18);
            if (next != NULL)
            {
                int intersects;
                int side_a = btlTargetCheckSide(edge, next, param_1);
                int side_b = btlTargetCheckSide(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = btlTargetCheckSide(param_1, param_2, edge);
                    side_b = btlTargetCheckSide(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
typedef struct P4NeighborNode {
    s32 unknown0;
    s32 unknown4;
    f32 x;
    f32 z;
    f32 unknown10;
    f32 active;
    f32 clearance;
    u8 rest[0x114];
} P4NeighborNode;
typedef struct P4NeighborGroup {
    s32 unknown0;
    s32 unknown4;
    P4NeighborNode nodes[4];
    struct P4NeighborGroup *previous;
    struct P4NeighborGroup *next;
} P4NeighborGroup;
extern s32 btlTargetRangeCheck(u8 *first, u8 *second);
extern f32 RwV2dLength(f32 *vector);
typedef struct P4NeighborWorld {
    u8 prefix[0x318];
    P4NeighborGroup *groups;
    P4NeighborNode nodes[4];
    P4NeighborNode start;
    P4NeighborNode goal;
} P4NeighborWorld;

// FUN_001ED3A0
/* 852/864 bytes; all eighteen relocations resolve exactly.
   Array types preserve halfword indexing; local order preserves lifetimes. */
s32 func_001ed3a0(u8 *node, f32 threshold)
{
    f32 linkedDelta[2];
    f32 fixedDelta[2];
    f32 startDelta[2];
    f32 goalDelta[2];
    f32 distance;
    P4NeighborGroup *group;
    s32 count;
    u16 index;
    u8 *neighbor;

    count = 0;
    group = *(P4NeighborGroup **)(iGpffffb3ac + 0x318);
    while (group != 0) {
        for (index = 0; index < 4; index++) {
            neighbor = (u8 *)&group->nodes[index];
            if (neighbor == node)
                continue;
            if (group->nodes[index].active <= 0.0f)
                continue;
            if (group->nodes[index].clearance < threshold)
                continue;
            if (btlTargetRangeCheck(node, neighbor) != 0)
                continue;
            linkedDelta[0] = *(f32 *)(node + 8) - *(f32 *)((u8 *)group + index * 0x130 + 0x10);
            linkedDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)((u8 *)group + index * 0x130 + 0x14);
            distance = RwV2dLength(linkedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
            *(u8 **)(node + (u16)count * 4 + 0x30) = neighbor;
            count = (u16)(count + 1);
        }
        group = group->next;
    }
    for (index = 0; index < 4; index++) {
        if ((u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index] == node)
            continue;
        if (((P4NeighborWorld *)iGpffffb3ac)->nodes[index].active <= 0.0f)
            continue;
        if (btlTargetRangeCheck(node, (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index]) != 0)
            continue;
        fixedDelta[0] = *(f32 *)(node + 8) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].x;
        fixedDelta[1] = *(f32 *)(node + 0xC) - ((P4NeighborWorld *)iGpffffb3ac)->nodes[index].z;
        distance = RwV2dLength(fixedDelta);
        *(f32 *)(node + (u16)count * 4 + 0xB0) = distance;
        *(u8 **)(node + (u16)count * 4 + 0x30) = (u8 *)&((P4NeighborWorld *)iGpffffb3ac)->nodes[index];
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x7DC != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x7DC) == 0) {
        startDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x7E4);
        startDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x7E8);
        distance = RwV2dLength(startDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x7DC;
        count = (u16)(count + 1);
    }
    if (iGpffffb3ac + 0x90C != node && btlTargetRangeCheck(node, iGpffffb3ac + 0x90C) == 0) {
        goalDelta[0] = *(f32 *)(node + 8) - *(f32 *)(iGpffffb3ac + 0x914);
        goalDelta[1] = *(f32 *)(node + 0xC) - *(f32 *)(iGpffffb3ac + 0x918);
        distance = RwV2dLength(goalDelta);
        *(f32 *)(p4_slot_001eb320((u16)count * 4, node) + 0xB0) = distance;
        *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = iGpffffb3ac + 0x90C;
        count = (u16)(count + 1);
    }
    *(u8 **)(p4_slot_001eb320((u16)count * 4, node) + 0x30) = 0;
    return count;
}
/* Field-group corner layout: bounding corners over the group list, then each
 * group corner and each world corner is linked to its nearest neighbour.
 * Matching notes: the bounding loop reuses `group` and the last search reuses
 * `other`; the z of each stack pair is read after the list head
 * (`curZ = cur[1]` / `wposZ = wpos[1]`) so b210 reloads it; tests with the
 * local on the left are spelled `corners[n].x <= tx` (branch through $at);
 * `(float *)(entry += 8)` keeps the advanced pointer in $s7; and a
 * block-scoped `base = iGpffffb3ac` orders the global load before the
 * index arithmetic. The pragmas are measured: without opt_loop_invariants
 * the D_0060A120 row address and the 7000.0f bound are not hoisted (432
 * edits), and without opt_lifetimes the loop locals share registers (205). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_dead_assignments off
// FUN_001ED700
void func_001ed700(f32 radius)
{
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 RwV2dLength(f32 *vec);
    extern f32 D_0060A120[];
    extern f32 fGpffff8330;
    typedef struct { f32 x, z; } FieldPair;
    struct { s16 x; s16 y; } corners[4];
    f32 bounds[4];
    f32 f0;
    u8 *other;
    f32 cur[2];
    f32 norm[2];
    f32 delta[2];
    f32 bestDir[2];
    f32 wpos[2];
    f32 bestH;
    f32 wposZ;
    s32 j;
    u8 *group;
    u8 *best;
    s32 i;
    s32 t;
    s16 tx;
    s16 ty;
    s16 q;
    f32 dist;
    f32 bestDist;
    f32 bestX;
    f32 bestZ;
    f32 curZ;
    s32 first;

    first = 0;
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        if (first == 0) {
            s16 v;

            v = *(s16 *)(group + 0);
            corners[3].x = v;
            corners[2].x = v;
            corners[1].x = v;
            corners[0].x = v;
            v = *(s16 *)(group + 2);
            corners[3].y = v;
            corners[2].y = v;
            corners[1].y = v;
            corners[0].y = v;
            f0 = *(f32 *)(group + 4);
            bounds[3] = f0;
            bounds[2] = f0;
            bounds[1] = f0;
            bounds[0] = f0;
            first = 1;
        } else {
            tx = *(s16 *)(group + 0);
            ty = *(s16 *)(group + 2);
            if ((corners[0].x >= tx) && (corners[0].y >= ty)) {
                corners[0].x = tx;
                corners[0].y = ty;
                bounds[0] = *(f32 *)(group + 4);
            }
            if ((corners[1].x <= tx) && (corners[1].y >= ty)) {
                corners[1].x = tx;
                corners[1].y = ty;
                bounds[1] = *(f32 *)(group + 4);
            }
            if ((corners[2].x <= tx) && (corners[2].y <= ty)) {
                corners[2].x = tx;
                corners[2].y = ty;
                bounds[2] = *(f32 *)(group + 4);
            }
            if ((corners[3].x >= tx) && (corners[3].y <= ty)) {
                corners[3].x = tx;
                corners[3].y = ty;
                bounds[3] = *(f32 *)(group + 4);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        t = (s32)(bounds[i] + 500.0f);
        q = (s16)(t / 25);
        if (t % 25 != 0) {
            q++;
        }
        switch (i) {
        case 0:
            tx = (s16)(corners[i].x - q);
            ty = (s16)(corners[i].y - q);
            if (tx < 0) {
                tx = 0;
            }
            if (ty < 0) {
                ty = 0;
            }
            break;
        case 1:
            tx = (s16)(q + corners[i].x);
            ty = (s16)(corners[i].y - q);
            if (ty < 0) {
                ty = 0;
            }
            break;
        case 2:
            tx = (s16)(q + corners[i].x);
            ty = (s16)(q + corners[i].y);
            break;
        case 3:
            tx = (s16)(corners[i].x - q);
            ty = (s16)(q + corners[i].y);
            if (tx < 0) {
                tx = 0;
            }
            break;
        }
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x31C) = (f32)(tx * 25 - 1750);
        *(f32 *)(iGpffffb3ac + i * 0x130 + 0x320) = (f32)(ty * 25 - 1750);
    }
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            best = NULL;
            bestDist = 7000.0f;
            *(FieldPair *)cur = *(FieldPair *)(group + i * 0x130 + 8);
            other = *(u8 **)(iGpffffb3ac + 0x318);
            curZ = cur[1];
            for (; other != NULL; other = *(u8 **)(other + 0x4CC)) {
                if (group != other) {
                    for (j = 0; j < 4; j++) {
                        u8 *entry = other + j * 0x130;

                        delta[0] = *(f32 *)(entry + 8) - cur[0];
                        delta[1] = *(f32 *)(entry + 12) - curZ;
                        dist = func_003e41e0(norm, delta);
                        if (!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) {
                            if (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(entry += 8)) == 0) {
                                *(s64 *)bestDir = *(s64 *)norm;
                                best = entry;
                                bestDist = dist;
                                bestX = (f32)(*(s16 *)(other + 0) * 25 - 1750);
                                bestZ = (f32)(*(s16 *)(other + 2) * 25 - 1750);
                                bestH = *(f32 *)(other + 4);
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 4; j++) {
                u8 *base = iGpffffb3ac;

                delta[0] = *(f32 *)(base + j * 0x130 + 0x31C) - cur[0];
                delta[1] = *(f32 *)(base + j * 0x130 + 0x320) - curZ;
                dist = func_003e41e0(norm, delta);
                if ((!(norm[0] * D_0060A120[i * 2 + 0] + norm[1] * D_0060A120[i * 2 + 1] <= fGpffff8330) && (dist < bestDist)) && (func_001ed060((float *)(group + i * 0x130 + 8), (float *)(iGpffffb3ac + j * 0x130 + 0x31C)) == 0)) {
                    *(s64 *)bestDir = *(s64 *)norm;
                    best = iGpffffb3ac + j * 0x130 + 0x31C;
                    bestDist = dist;
                    bestX = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x31C);
                    bestZ = *(f32 *)(iGpffffb3ac + j * 0x130 + 0x320);
                    bestH = 0.0f;
                }
            }
            if (best != NULL) {
                f32 half;
                f32 dx;
                half = 0.5f * bestDist;
                dx = bestDir[0] * half;
                bestDir[0] = dx;
                bestDir[1] = bestDir[1] * half;
                *(f32 *)(group + i * 0x130 + 0x10) = cur[0] + dx;
                *(f32 *)(group + i * 0x130 + 0x14) = curZ + bestDir[1];
                *(u8 **)(group + i * 0x130 + 0x18) = best;
                *(f32 *)(group + i * 0x130 + 0x1C) = bestDist;
                delta[0] = (f32)(*(s16 *)(group + 0) * 25 - 1750);
                delta[1] = (f32)(*(s16 *)(group + 2) * 25 - 1750);
                delta[0] = delta[0] - bestX;
                delta[1] = delta[1] - bestZ;
                *(f32 *)(group + i * 0x130 + 0x20) = RwV2dLength(delta) - (*(f32 *)(group + 4) + bestH);            } else {
                *(f32 *)(group + i * 0x130 + 0x1C) = -1.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        best = NULL;
        bestDist = 7000.0f;
        {
            u8 *base = iGpffffb3ac;

            *(FieldPair *)wpos = *(FieldPair *)(base + i * 0x130 + 0x31C);
            other = *(u8 **)(base + 0x318);
        }
        wposZ = wpos[1];
        for (; other != NULL; other = *(u8 **)(other + 0x4CC)) {
            for (j = 0; j < 4; j++) {
                u8 *entry = other + j * 0x130;

                delta[0] = *(f32 *)(entry + 8) - wpos[0];
                delta[1] = *(f32 *)(entry + 12) - wposZ;
                dist = RwV2dLength(delta);
                if (dist < bestDist) {
                    func_003e41e0(bestDir, delta);
                    best = entry + 8;
                    bestDist = dist;
                }
            }
        }
        if (best != NULL) {
            if (*(u8 **)(best + 0x10) != iGpffffb3ac + i * 0x130 + 0x31C) {
                f32 half;
                half = 0.5f * bestDist;
                bestDir[0] = bestDir[0] * half;
                bestDir[1] = bestDir[1] * half;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x324) = wpos[0] + bestDir[0];
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x328) = wposZ + bestDir[1];
                *(u8 **)(iGpffffb3ac + i * 0x130 + 0x32C) = best;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = bestDist;
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x334) = 500.0f;
            } else {
                *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
            }
        } else {
            *(f32 *)(iGpffffb3ac + i * 0x130 + 0x330) = -1.0f;
        }
    }
    for (group = *(u8 **)(iGpffffb3ac + 0x318); group != NULL; group = *(u8 **)(group + 0x4CC)) {
        for (i = 0; i < 4; i++) {
            u8 *corner = group + i * 0x130 + 8;

            if (!(*(f32 *)(corner + 0x14) <= 0.0f) && !(*(f32 *)(corner + 0x18) < radius)) {
                func_001ed3a0(corner, radius);
            } else {
                *(s32 *)(corner + 0x30) = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        u8 *corner = iGpffffb3ac + i * 0x130 + 0x31C;

        if (!(*(f32 *)(corner + 0x14) <= 0.0f)) {
            func_001ed3a0(corner, radius);
        } else {
            *(s32 *)(corner + 0x30) = 0;
        }
    }
    func_001ed3a0(iGpffffb3ac + 0x7DC, radius);
    func_001ed3a0(iGpffffb3ac + 0x90C, radius);
}
#pragma pop
// FUN_001EE1C0
void func_001ee1c0(void) {
    f32 temp_f0;
    f32 temp_f1;

    *(s32 *)(iGpffffb3ac + 0x318) = 0;
    *(s32 *)(iGpffffb3ac + 0x7F0) = 0xBF800000;
    *(s32 *)(iGpffffb3ac + 0x920) = 0xBF800000;
    temp_f1 = (f32)(-0x6D6);
    *(f32 *)(iGpffffb3ac + 0x31C) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x320) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x44C) = temp_f1;
    temp_f0 = (f32)0x6D6;
    *(f32 *)(iGpffffb3ac + 0x450) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x57C) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x580) = temp_f1;
    *(f32 *)(iGpffffb3ac + 0x6AC) = temp_f0;
    *(f32 *)(iGpffffb3ac + 0x6B0) = temp_f0;
}
// FUN_001EE250
void func_001ee250(u8 *arg0, u8 *arg1)
{
    extern void btlTargetSetRadiusArea(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;
    u8 *work;

    btlUnitGetSphereWorldCenter(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    x = (s32)((f32)0x6D6 + coords[0]);
    y = (s32)((f32)0x6D6 + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12)
        rounded_x = (s64)(s16)(rounded_x + 1);
    if ((y % 25) > 12)
        rounded_y = (s64)(s16)(rounded_y + 1);
    if (&out_x != NULL)
        out_x = rounded_x;
    if (&out_y != NULL)
        out_y = rounded_y;
    work = arg0;
    btlTargetSetRadiusArea(work, out_x, out_y, scale);
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32)(out_x * 25 - 0x6D6);
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)(out_y * 25 - 0x6D6);
    }
    *(s16 *)(arg0 + 0x508) = out_x;
    *(s16 *)(arg0 + 0x50A) = out_y;
    *(f32 *)(arg0 + 0x50C) = scale;
    *(s32 *)(arg0 + 0x9C) |= 4;
    *(s32 *)(arg0 + 0x9D0) = 0;
    if (*(u8 **)(iGpffffb3ac + 0x318) == NULL)
        goto ee250_no_head;
    *(u8 **)(*(u8 **)(iGpffffb3ac + 0x318) + 0x4C8) =
        arg0 + 0x508;
    *(u8 **)(arg0 + 0x9D4) =
        *(u8 **)(iGpffffb3ac + 0x318);
    goto ee250_link_done;
ee250_no_head:
    *(u8 **)(arg0 + 0x9D4) = NULL;
ee250_link_done:
    *(u8 **)(iGpffffb3ac + 0x318) = arg0 + 0x508;
}
// FUN_001EE430
void func_001ee430(u8 *arg0) {
    s32 temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;

    temp_5 = *(s32 *)(arg0 + 0x9C);
    if (temp_5 & 4) {
        *(s32 *)(arg0 + 0x9C) = temp_5 & ~4;
        temp_5_2 = *(u8 **)(arg0 + 0x9D4);
        if (temp_5_2 != 0) {
            *(u8 **)(temp_5_2 + 0x4C8) = *(u8 **)(arg0 + 0x9D0);
        }
        temp_5_3 = *(u8 **)(arg0 + 0x9D0);
        if (temp_5_3 != 0) {
            *(u8 **)(temp_5_3 + 0x4CC) = *(u8 **)(arg0 + 0x9D4);
            return;
        }
        *(u8 **)(iGpffffb3ac + 0x318) = *(u8 **)(arg0 + 0x9D4);
    }
}
// FUN_001EE490
s32 func_001ee490(u8 *arg0) {
    extern void btlTargetSetRadiusArea(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
    extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
    f32 coords[3];
    s16 out_x;
    s16 out_y;
    f32 scale;
    f32 base;
    s32 x;
    s32 y;
    s32 rounded_x;
    s32 rounded_y;

    if ((*(s32 *)(arg0 + 0x9C) & 4) == 0) {
        return 0;
    }
    btlUnitGetSphereWorldCenter(arg0, coords);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    base = (f32)1750;
    x = (s32)(base + coords[0]);
    y = (s32)(base + coords[2]);
    rounded_x = (s64)(s16)(x / 25);
    rounded_y = (s64)(s16)(y / 25);
    if ((x % 25) > 12) {
        rounded_x = (s64)(s16)(rounded_x + 1);
    }
    if ((y % 25) > 12) {
        rounded_y = (s64)(s16)(rounded_y + 1);
    }
    if (&out_x != NULL) {
        out_x = (s16)rounded_x;
    }
    if (&out_y != NULL) {
        out_y = (s16)rounded_y;
    }
    if (*(s16 *)(arg0 + 0x508) != out_x ||
        *(s16 *)(arg0 + 0x50A) != out_y ||
        *(f32 *)(arg0 + 0x50C) != scale) {
        btlTargetSetRadiusArea(arg0, out_x, out_y, scale);
        *(s16 *)(arg0 + 0x508) = out_x;
        *(s16 *)(arg0 + 0x50A) = out_y;
        *(f32 *)(arg0 + 0x50C) = scale;
        return 1;
    }
    return 0;
}
extern s32 btlTargetLineClear(f32 *first, f32 *second, f32 margin);
extern void func_001ed700(f32 radius);
extern s32 func_001ee610(u8 *route, f32 radius);

typedef struct RoutePoint {
    f32 x;
    f32 z;
} RoutePoint;

typedef struct RouteNode {
    u8 unknown00[8];
    RoutePoint pos;
    u8 unknown10[0xC];
    f32 g;
    f32 f;
    struct RouteNode *openNext;
    struct RouteNode *closedNext;
    struct RouteNode *parent;
    struct RouteNode *neighbors[32];
    f32 distances[32];
} RouteNode;

/* The first pass through the route loop reads `cur`, `last` and `seg[1]`
   before anything has written them (001ee71c/001ee730); retail uses the
   stack slots as they are. The C keeps those reads of the uninitialised
   locals. opt_loop_invariants hoists &pts[n] (retail $s5) and pts[0].z
   (retail $f20) out of the subdivision loop. */
#pragma push
#pragma opt_loop_invariants on
// FUN_001EE610
s32 func_001ee610(u8 *route, f32 radius)
{
    extern f32 func_003e41e0(f32 *out, f32 *in);
    RoutePoint last;
    RoutePoint tmp;
    RoutePoint cur;
    RoutePoint edge;
    RoutePoint norm[2];
    RoutePoint seg[2];
    RoutePoint ctrl[4];
    RoutePoint pts[128];
    RouteNode *goal;
    RouteNode *node;
    RouteNode *prev;
    u8 *base;
    s32 i;
    s32 n;
    s32 k;
    f32 margin;
    f32 dot;
    f32 segLen;
    f32 prevLen;
    f32 s;

    n = 0;
    base = iGpffffb3ac;
    goal = (RouteNode *)(base + 0x90C);
    margin = 0.5f * radius;
    if (btlTargetLineClear((f32 *)(base + 0x7E4), (f32 *)(base + 0x914), margin) == 0) {
        /* The start is already in reach of the goal: a straight segment. */
        base = iGpffffb3ac;
        pts[0] = ((RouteNode *)(base + 0x90C))->pos;
        pts[1] = ((RouteNode *)(base + 0x7DC))->pos;
        n = 2;
    } else {
        node = goal;
        while (node != NULL) {
            if (n > 0) {
                /* Skip ahead along the parent chain while the last point
                   still reaches the next node. */
                prev = node;
                while (node != NULL) {
                    if (btlTargetLineClear(&cur.x, &node->pos.x, margin) != 0) {
                        break;
                    }
                    prev = node;
                    node = node->parent;
                }
                node = prev;
                cur = prev->pos;
            } else {
                cur = node->pos;
            }
            seg[0] = seg[1];
            seg[1].x = cur.x - last.x;
            seg[1].z = cur.z - last.z;
            dot = seg[0].x * seg[1].x + seg[0].z * seg[1].z;
            if (n > 1 && dot <= 0.173648f) {
                /* Sharp corner: round it with two extra points. */
                segLen = func_003e41e0(&norm[0].x, &seg[1].x);
                prevLen = func_003e41e0(&norm[1].x, &seg[0].x);
                if (segLen < 250.0f && prevLen < 250.0f) {
                    n--;
                } else {
                    s = (1.0f - 0.65f) * segLen;
                    tmp.x = norm[0].x * s;
                    tmp.z = norm[0].z * s;
                    tmp.x = tmp.x + pts[n - 1].x;
                    tmp.z = tmp.z + pts[n - 1].z;
                    pts[n] = tmp;
                    s = 0.65f * prevLen;
                    tmp.x = norm[1].x * s;
                    tmp.z = norm[1].z * s;
                    tmp.x = tmp.x + pts[n - 2].x;
                    tmp.z = tmp.z + pts[n - 2].z;
                    pts[n - 1] = tmp;
                    n++;
                }
                pts[n] = cur;
                n++;
            } else {
                pts[n] = cur;
                n++;
            }
            last = pts[n - 1];
            node = node->parent;
        }
    }
    if (n < 2) {
        return 0;
    }
    if (n < 3) {
        ((RoutePoint *)route)[0] = pts[1];
        ((RoutePoint *)route)[1] = pts[0];
        *(s16 *)(route + 0x400) = 2;
    } else {
        /* Subdivide each span into four points of a cubic spline, with
           phantom points extrapolated past the start. */
        k = 0;
        i = n - 1;
        do {
            RoutePoint *out;

            if (i + 1 >= n) {
                ctrl[0] = pts[n - 1];
            } else {
                ctrl[0] = pts[i + 1];
            }
            ctrl[1] = pts[i];
            if (i - 1 < 0) {
                edge.x = pts[0].x - ctrl[1].x;
                edge.z = pts[0].z - ctrl[1].z;
                func_003e41e0(&edge.x, &edge.x);
                edge.x = edge.x * 300.0f;
                edge.z = edge.z * 300.0f;
                edge.x = edge.x + pts[0].x;
                edge.z = edge.z + pts[0].z;
                ctrl[2] = edge;
            } else {
                ctrl[2] = pts[i - 1];
            }
            if (i - 2 < 0) {
                edge.x = pts[0].x - ctrl[1].x;
                edge.z = pts[0].z - ctrl[1].z;
                func_003e41e0(&edge.x, &edge.x);
                edge.x = edge.x * 500.0f;
                edge.z = edge.z * 500.0f;
                edge.x = edge.x + pts[0].x;
                edge.z = edge.z + pts[0].z;
                ctrl[3] = edge;
            } else {
                ctrl[3] = pts[i - 2];
            }
            out = (RoutePoint *)route + k;
            out[0] = pts[i];
            tmp.x = -0.0703125f * ctrl[0].x + 0.8671875f * ctrl[1].x + 0.2265625f * ctrl[2].x + -0.0234375f * ctrl[3].x;
            tmp.z = -0.0703125f * ctrl[0].z + 0.8671875f * ctrl[1].z + 0.2265625f * ctrl[2].z + -0.0234375f * ctrl[3].z;
            out[1] = tmp;
            tmp.x = -0.0625f * ctrl[0].x + 0.5625f * ctrl[1].x + 0.5625f * ctrl[2].x + -0.0625f * ctrl[3].x;
            tmp.z = -0.0625f * ctrl[0].z + 0.5625f * ctrl[1].z + 0.5625f * ctrl[2].z + -0.0625f * ctrl[3].z;
            out[2] = tmp;
            tmp.x = -0.0234375f * ctrl[0].x + 0.226563f * ctrl[1].x + 0.8671875f * ctrl[2].x + -0.0703125f * ctrl[3].x;
            tmp.z = -0.0234375f * ctrl[0].z + 0.226563f * ctrl[1].z + 0.8671875f * ctrl[2].z + -0.0703125f * ctrl[3].z;
            out[3] = tmp;
            k += 4;
            i--;
        } while (i > 0);
        ((RoutePoint *)route)[k] = pts[0];
        *(s16 *)(route + 0x400) = k + 1;
    }
    return 1;
}
#pragma pop
/* measured: object 172B vs window 176B, normalized_diff 2; the remaining
   residual is the best-node register assignment. Committed at nd 2. */
// FUN_001EEC60
u8 *func_001eec60(void) {
    f32 value;
    f32 max;
    u8 *best;
    u8 *base;
    u8 **headp;
    u8 *scan;
    u8 *current;
    max = (f32)(s32)0x55730;
    base = iGpffffb3ac;
    headp = (u8 **)(base + 0xA3C);
    current = *headp;
    scan = current;
    goto scan_test;
scan_body:
    value = *(f32 *)(scan + 0x20);
    if (max <= value)
        goto scan_next;
    best = (u8 *)scan;
    max = value;
scan_next:
    scan = *(u8 **)(scan + 0x24);
scan_test:
    if (scan != 0)
        goto scan_body;
    scan = 0;
    goto unlink_test;
unlink_body:
    if (current == best)
        goto unlink_done;
    scan = current;
    current = *(u8 **)(current + 0x24);
unlink_test:
    if (current != 0)
        goto unlink_body;
unlink_done:
    if (current == 0)
        goto return_best;
    if (scan != 0) {
        *(u8 **)(scan + 0x24) = *(u8 **)(current + 0x24);
        goto return_best;
    }
    *headp = *(u8 **)(current + 0x24);
return_best:
    return best;
}

/* Retail indexes the neighbour and distance arrays as base + index * 4 + field. */
#define ROUTE_NEIGHBOR(n, i) (*(RouteNode **)((u8 *)(n) + (i) * 4 + 0x30))
#define ROUTE_DISTANCE(n, i) (*(f32 *)((u8 *)(n) + (i) * 4 + 0xB0))

static inline s32 routeInOpenList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->openNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}

static inline s32 routeInClosedList(RouteNode *scan, RouteNode *node)
{
    for (; scan != NULL; scan = scan->closedNext) {
        if (scan == node) {
            return 1;
        }
    }
    return 0;
}

// FUN_001EED10
s32 func_001eed10(u8 *route, f32 *start, f32 *end, f32 radius)
{
    f32 startDelta[2];
    f32 goalDelta[2];
    u8 *world;
    RouteNode *node;
    f32 x;
    f32 z;
    f32 cost;
    u16 index;
    s32 found;
    s32 inOpen;
    s32 inClosed;

    route[0x404] = 1;
    if (btlTargetLineClear(start, end, 0.5f * radius) == 0) {
        x = start[0];
        z = start[1];
        *(f32 *)(route + 0x0) = x;
        *(f32 *)(route + 0x4) = z;
        x = end[0];
        z = end[1];
        *(f32 *)(route + 0x8) = x;
        *(f32 *)(route + 0xC) = z;
        *(u16 *)(route + 0x400) = 2;
        route[0x404] = 2;
        return 1;
    }
    *(u16 *)(route + 0x400) = 0;
    world = iGpffffb3ac;
    x = start[0];
    z = start[1];
    *(f32 *)(world + 0x7E4) = x;
    *(f32 *)(world + 0x7E8) = z;
    x = end[0];
    z = end[1];
    *(f32 *)(world + 0x914) = x;
    *(f32 *)(world + 0x918) = z;
    func_001ed700(radius);
    world = iGpffffb3ac;
    if (*(s32 *)(world + 0x80C) == 0 || *(s32 *)(world + 0x93C) == 0) {
        route[0x404] = 3;
        return 0;
    }
    *(u8 **)(world + 0xA3C) = NULL;
    *(u8 **)(iGpffffb3ac + 0xA40) = NULL;
    *(f32 *)(iGpffffb3ac + 0x7F8) = 0.0f;
    world = iGpffffb3ac;
    startDelta[0] = *(f32 *)(world + 0x7E4) - *(f32 *)(world + 0x914);
    startDelta[1] = *(f32 *)(world + 0x7E8) - *(f32 *)(world + 0x918);
    *(f32 *)(iGpffffb3ac + 0x7FC) = RwV2dLength(startDelta);
    *(u8 **)(iGpffffb3ac + 0x808) = NULL;
    world = iGpffffb3ac;
    *(u8 **)(world + 0x800) = *(u8 **)(world + 0xA3C);
    world = iGpffffb3ac;
    *(u8 **)(world + 0xA3C) = world + 0x7DC;
    found = 0;
    while (*(u8 **)(iGpffffb3ac + 0xA3C) != NULL) {
        node = (RouteNode *)func_001eec60();
        if ((u8 *)node == iGpffffb3ac + 0x90C) {
            found = 1;
            break;
        }
        for (index = 0; ROUTE_NEIGHBOR(node, index) != NULL; index++) {
            cost = node->g + ROUTE_DISTANCE(node, index);
            world = iGpffffb3ac;
            inOpen = routeInOpenList(*(RouteNode **)(world + 0xA3C), ROUTE_NEIGHBOR(node, index));
            inClosed = routeInClosedList(*(RouteNode **)(world + 0xA40), ROUTE_NEIGHBOR(node, index));
            if ((inOpen != 0 || inClosed != 0) && node->g <= cost) {
                continue;
            }
            ROUTE_NEIGHBOR(node, index)->g = cost;
            ROUTE_NEIGHBOR(node, index)->f = cost;
            world = iGpffffb3ac;
            goalDelta[0] = ROUTE_NEIGHBOR(node, index)->pos.x - *(f32 *)(world + 0x914);
            goalDelta[1] = ROUTE_NEIGHBOR(node, index)->pos.z - *(f32 *)(world + 0x918);
            ROUTE_NEIGHBOR(node, index)->f += RwV2dLength(goalDelta);
            ROUTE_NEIGHBOR(node, index)->parent = node;
            if (inClosed != 0) {
                RouteNode **head;
                RouteNode *scanNode;
                RouteNode *prevNode;
                RouteNode *removed;

                removed = ROUTE_NEIGHBOR(node, index);
                prevNode = NULL;
                head = (RouteNode **)(iGpffffb3ac + 0xA40);
                for (scanNode = *head; scanNode != NULL; scanNode = scanNode->closedNext) {
                    if (scanNode == removed) {
                        break;
                    }
                    prevNode = scanNode;
                }
                if (scanNode != NULL) {
                    if (prevNode != NULL) {
                        prevNode->closedNext = scanNode->closedNext;
                    } else {
                        *head = scanNode->closedNext;
                    }
                }
            }
            if (inOpen == 0) {
                ROUTE_NEIGHBOR(node, index)->openNext = *(RouteNode **)(iGpffffb3ac + 0xA3C);
                *(RouteNode **)(iGpffffb3ac + 0xA3C) = ROUTE_NEIGHBOR(node, index);
            }
        }
        node->closedNext = *(RouteNode **)(iGpffffb3ac + 0xA40);
        *(RouteNode **)(iGpffffb3ac + 0xA40) = node;
    }
    if (found != 0) {
        func_001ee610(route, radius);
        route[0x404] = 2;
    } else {
        route[0x404] = 3;
    }
    return found;
}
// FUN_001EF110
/* 904/912 bytes; all eighteen relocations resolve exactly.
   Stage both endpoint loads before either store to preserve overlap. */
#pragma push
#pragma opt_propagation off
s32 func_001ef110(u8 *route, const f32 *startXZ,
                  const f32 *endXZ, const f32 *centerXZ)
{
    P4RouteSlerp_001EF110 interpolation;
    P4Vec4_001EC2B0 rotation;
    P4Vec4_001EC2B0 startRotation;
    P4Vec4_001EC2B0 endRotation;
    f32 center[3];
    f32 endpoint[3];
    f32 direction[3];
    f32 startLength;
    f32 blend;
    f32 lengthDelta;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 square;
    f32 polynomial;
    f32 finalPolynomial;
    f32 length;
    s32 index;

    *(u16 *)(route + 0x400) = 0;
    endpoint[1] = 0.0f;
    center[0] = centerXZ[0];
    center[1] = 0.0f;
    center[2] = centerXZ[1];
    endpoint[0] = startXZ[0];
    endpoint[2] = startXZ[1];
    btlCameraLookAtQuat(&startRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    startLength = RwV3dLength(direction);

    endpoint[0] = endXZ[0];
    endpoint[2] = endXZ[1];
    btlCameraLookAtQuat(&endRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    lengthDelta = RwV3dLength(direction);
    blend = 0.0f;
    func_003dcc70(&startRotation, &endRotation, &interpolation);
    index = 0;
    lengthDelta = lengthDelta - startLength;
    while (index < 7)
    {
        if (blend <= 0.0f)
        {
            rotation = startRotation;
        }
        else if (1.0f <= blend)
        {
            rotation = endRotation;
        }
        else
        {
            firstWeight = 1.0f - blend;
            secondWeight = blend;
            if (interpolation.mode == 0)
            {
                angle = firstWeight * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                firstWeight = polynomial * finalPolynomial + angle;

                angle = blend * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                secondWeight = polynomial * finalPolynomial + angle;
            }
            rotation.x = interpolation.first.x * firstWeight;
            rotation.y = interpolation.first.y * firstWeight;
            rotation.z = interpolation.first.z * firstWeight;
            rotation.x = interpolation.second.x * secondWeight +
                         (0.0f + rotation.x);
            rotation.y = interpolation.second.y * secondWeight +
                         (0.0f + rotation.y);
            rotation.z = interpolation.second.z * secondWeight +
                         (0.0f + rotation.z);
            rotation.w = interpolation.first.w * firstWeight +
                         interpolation.second.w * secondWeight;
        }
        RtQuatTransformVectors(direction, D_0060A0F0, 1, &rotation);
        length = blend * lengthDelta + (0.0f + startLength);
        direction[0] = direction[0] * length;
        direction[1] = direction[1] * length;
        direction[2] = direction[2] * length;
        *(f32 *)(route + index * 8) = center[0] + direction[0];
        *(f32 *)(route + index * 8 + 4) = center[2] + direction[2];
        blend = blend + 0.125f;
        index = index + 1;
    }
    {
        f32 endX = endXZ[0];
        f32 endZ = endXZ[1];
        *(f32 *)(route + 0x38) = endX;
        *(f32 *)(route + 0x3C) = endZ;
    }
    *(u16 *)(route + 0x400) = 8;
    *(u8 *)(route + 0x404) = 2;
    return 1;
}

#pragma pop
// FUN_001EF4A0
s32 func_001ef4a0(s32 arg0)
{
    s32 value;

    value = ((u8 *)iGpffffb3bc)[(arg0 & 0xFFFF) * 4];
    if (value == 0)
    {
        value = 1;
    }
    return value;
}
// FUN_001EF4D0
/* measured: preserve retail count-result branch shape while probing ef4d0. */
#pragma opt_common_subs off
s32 btlSideAverageLevel(s32 arg0, s32 arg1)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg1 == 0) ||
                    (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg1) == 0)) {
                    total = (total +
                             (datCalcGetLevel(*(s32 *)(entry + 0xA64)) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}
/* measured: close ef4d0 branch-shape probe. */
#pragma opt_common_subs on
// FUN_001EF5F0
/* measured: preserve retail count-result branch shape while probing ef5f0. */
#pragma opt_common_subs off
s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg2 == 0) ||
                    (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg2) == 0)) {
                    total = (total +
                             (datCalcGetBattleStat(*(s32 *)(entry + 0xA64), arg1) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0)
        return 1;
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        return 1;
    return value;
}
/* measured: close ef5f0 branch-shape probe. */
#pragma opt_common_subs on
// FUN_001EF720
s32 btlSideCountNotBad(s32 arg0, s32 arg1)
{
    u8 *current;
    s32 count;
    u8 *entry;
    s32 mask;

    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL)
    {
        if ((*(u16 *)(current + 0x1A) & 1) && (*(u16 *)(current + 0x1A) & 8))
        {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) && (datCalcChkBadStatus(*(s32 *)(entry + 0xA64), arg1) == 0))
            {
                count = (count + 1) & 0xFFFF;
            }
        }
        current = *(u8 **)(current + 0x450);
    }

    return count;
}
/* measured: object 224B / window 224B / normalized_diff 0; direct pointer/index locals reproduce retail order. */
// FUN_001EF7E0
s32 func_001ef7e0(void)
{
    s32 *temp_3;
    s32 temp_3_2;
    s32 var_3;
    u16 temp_16;

    temp_3 = (s32 *)((s32)gEncountTbl + func_001ef9a0() * 24);
    if (*(u16 *)(iGpffffb3ac + 0xC5A) == 0) {
        return 0;
    }
    temp_3_2 = *temp_3;
    if ((temp_3_2 & 2) != 0) {
        return 0;
    }
    if ((temp_3_2 & 4) != 0) {
        return 1;
    }
    if (*(u32 *)(iGpffffb3ac + 0x20) == 0) {
        var_3 = 0;
    } else if (*(u32 *)(iGpffffb3ac + 0x20) > 5) {
        var_3 = 4;
    } else {
        var_3 = *(u32 *)(iGpffffb3ac + 0x20) - 1;
    }
    temp_16 = *(&iGpffffa9b0 + var_3);
    return (u32)datCalcRandomBelow(100) < (u32)temp_16;
}
// FUN_001EF8C0
s32 func_001ef8c0(void)
{
    u8 *base;
    u8 *table;
    u16 index;
    s32 flags;
    s64 result;
    u16 flags2;

    base = iGpffffb3ac;
    index = *(u16 *)(*(u8 **)(base + 0xC68) + 8);
    table = iGpffffb414 + index * 0x18;
    if (*(s32 *)(base + 0xC) & 0x20000000)
        return 0;
    flags = *(s32 *)table;
    if (flags & 8)
        return 0;
    if (flags & 0x10)
        return 2;
    if (flags & 0x800)
        return 1;
    flags2 = *(u16 *)(base + 0xC70);
    if (flags2 & 4)
        return 0;
    if (flags2 & 1)
        return 2;
    result = (flags2 & 0x10) != 0;
    return (u16)result;
}
// FUN_001EF9A0
s32 func_001ef9a0(void) {
    return *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
}
// FUN_001EF9C0
/* 904/912 bytes; all fifteen relocations resolve exactly. */
s32 func_001ef9c0(u8 *action)
{
    s32 rank;
    u8 *status1Targets[4];
    u8 *status100000Targets[4];
    u8 *status1eTargets[4];
    u8 *node;
    s32 count1;
    s32 count100000;
    s32 count1e;
    u8 *preferred1;
    u8 *preferred100000;
    u8 *preferred1e;
    u8 *actor;
    u16 flags;

    *(s16 *)(action + 0x448) = -1;
    *(u8 **)(action + 0x444) = NULL;
    actor = *(u8 **)(action + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) {
        return 0;
    }
    if (*(u16 *)(actor + 0xA4) == 1) {
        return 0;
    }
    if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x1001FF) != 0) {
        return 0;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x1000) ||
        *(u16 *)(action + 0x14) == 9) {
        return 0;
    }
    if (datCalcIsStatusBlocked(*(u16 **)(*(u8 **)(action + 0x30) + 0xA64)) != 0) {
        return 0;
    }
    rank = func_00107ac0(func_00247cb0(
        *(s16 *)(*(u8 **)(action + 0x30) + 0xA4)) & 0xFFFF) & 0xFFFF;
    count1 = 0;
    count100000 = 0;
    count1e = 0;
    preferred1 = NULL;
    preferred100000 = NULL;
    preferred1e = NULL;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    flags = *(u16 *)(node + 0x1A);
    if ((flags & 1) == 0) goto next;
    if ((flags & 8) == 0) goto next;
    if (node == action) goto next;
    actor = *(u8 **)(node + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) goto next;
    if (rank >= 5) {
        if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 1) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1 = node;
            }
            status1Targets[count1] = node;
            count1++;
        } else if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x100000) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred100000 = node;
            }
            status100000Targets[count100000] = node;
            count100000++;
        }
    }
    if (rank >= 7) {
        if (datCalcChkBadStatus(*(s32 *)(actor + 0xA64), 0x1E) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1e = node;
            }
            status1eTargets[count1e] = node;
            count1e++;
        }
    }
next:
    node = *(u8 **)(node + 0x450);
check:
    if (node != NULL) goto loop;
    if (count100000 == 0 && count1e == 0 && count1 == 0) {
        return 0;
    }
    if (count1 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred1 = preferred1 != NULL ? preferred1 :
            status1Targets[datCalcRandomBelow(count1)];
        *(u8 **)(action + 0x444) = preferred1;
        return 1;
    }
    if (count100000 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred100000 = preferred100000 != NULL ? preferred100000 :
            status100000Targets[datCalcRandomBelow(count100000)];
        *(u8 **)(action + 0x444) = preferred100000;
        return 1;
    }
    if (count1e != 0) {
        *(s16 *)(action + 0x448) = 0;
        preferred1e = preferred1e != NULL ? preferred1e :
            status1eTargets[datCalcRandomBelow(count1e)];
        *(u8 **)(action + 0x444) = preferred1e;
        return 1;
    }
    return 0;
}
// FUN_001EFD50
u8 *func_001efd50(u8 *arg0)
{
    s16 temp_3;
    u8 *var_19;
    s32 var_18;
    s32 var_17;
    u16 temp_3_2;
    u8 *temp_16;
    s32 candidates[4];

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return NULL;
    }
    var_17 = 0;
    temp_3 = *(s16 *)(arg0 + 0x6E);
    if ((temp_3 < 0x1B8) &&
        ((*(u8 *)(iGpffffb3b8 + (temp_3 * 0x28)) & 0x80) != 0)) {
        var_17 = 1;
    }
    if ((var_17 == 0) &&
        (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
         (*(u16 *)(arg0 + 0x14) == 9))) {
        return NULL;
    }
    var_18 = 0;
    var_19 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_19 != NULL) {
        temp_3_2 = *(u16 *)(var_19 + 0x1A);
        if (((temp_3_2 & 1) != 0) &&
            ((temp_3_2 & 8) != 0) &&
            ((var_17 != 0) || ((temp_3_2 & 0x80) == 0)) &&
            (var_19 != arg0)) {
            temp_16 = *(u8 **)(var_19 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                ((var_17 != 0) ||
                 (datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64), 0x1001FF) == 0)) &&
                (datCalcIsDead(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                ((var_17 != 0) ||
                 ((func_00107ac0((func_00247cb0(*(s16 *)(temp_16 + 0xA4)) &
                                   0xFFFF)) &
                   0xFFFF) > 0))) {
                candidates[var_18] = (s32)var_19;
                var_18 += 1;
            }
        }
        var_19 = *(u8 **)(var_19 + 0x450);
    }
    if (var_18 == 0) {
        return NULL;
    }
    return (u8 *)candidates[datCalcRandomBelow(var_18)];
}
// FUN_001EFF50
s32 func_001eff50(u8 *arg0)
{
    s32 temp_16_2;
    s32 temp_5;
    u8 *var_18;
    s32 var_17;
    u16 temp_3;
    u8 *temp_16;
    s32 candidates[4];

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) ||
        (*(u16 *)(arg0 + 0x14) == 9)) {
        return 0;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x100117) != 0) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x28) < 2) {
        temp_5 = func_001064f0(0x79) -
                 (*(u8 *)(arg0 + 0x28) + 1);
        if (temp_5 > 0) {
            func_00106550(0x79, temp_5);
            return 0;
        }
    }
    var_17 = 0;
    var_18 = *(u8 **)(iGpffffb3ac + 0x174);
    while (var_18 != NULL) {
        temp_3 = *(u16 *)(var_18 + 0x1A);
        if (((temp_3 & 1) != 0) &&
            ((temp_3 & 8) != 0) &&
            (var_18 != arg0)) {
            temp_16 = *(u8 **)(var_18 + 0x30);
            if ((*(u8 *)(temp_16 + 0xA2) == 0) &&
                (*(u16 *)(temp_16 + 0xA4) != 1) &&
                (datCalcChkBadStatus(*(s32 *)(temp_16 + 0xA64),
                                0x1001FF) == 0) &&
                (datCalcIsDead(*(s32 *)(temp_16 + 0xA64), 0) == 0) &&
                (datCalcIsStatusBlocked(*(u16 **)(temp_16 + 0xA64)) == 0) &&
                ((func_00107ac0((func_00247cb0(
                                    *(s16 *)(temp_16 + 0xA4)) &
                                  0xFFFF)) &
                  0xFFFF) >= 3)) {
                temp_16_2 =
                    (datCalcCountSlotsWithValue(*(u8 **)(temp_16 + 0xA64), 0x88) &
                     0xFFFF) *
                    10;
                temp_5 = datCalcRandomBelow(0x64);
                if ((u32)temp_5 > (u32)(temp_16_2 + 0x3C)) {
                } else {
                    candidates[var_17] = (s32)var_18;
                    var_17 += 1;
                }
            }
        }
        var_18 = *(u8 **)(var_18 + 0x450);
    }
    if (var_17 == 0) {
        return 0;
    }
    func_00106550(0x79, datCalcRandomBelow(3) + 3);
    return candidates[datCalcRandomBelow(var_17)];
}
