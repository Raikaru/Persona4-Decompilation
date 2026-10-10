#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
typedef struct BtlPacket BtlPacket;
extern BtlPacket *func_001d5eb0(u32 formation, const char *text, u16 mode);
typedef struct BtlUnit BtlUnit;
u32 func_00231d70(u32 bound);
typedef struct BtlAction BtlAction;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);
typedef struct RwV3d { f32 x, y, z; } RwV3d;

/* 001f14f0 writes 0x20-byte hit records at action+0xF0. The guarded
   controllers also construct this same provider-sized result payload. */
typedef struct LargeBattleHitResult {
    s32 hpDelta, spDelta;
    u32 addedStatus, removedStatus;
    u32 field10;
    s32 field14;
    s16 hpTransfer, spTransfer;
    s8 motion;
    u8 field1d;
    u16 flags;
} LargeBattleHitResult;

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *func_001f5f70(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)func_001f5f70((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *func_0019a980(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)func_0019a980(unit);
}
extern BtlPacket *func_00202400(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return func_00202400(unit, message);
}
extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 cue, s32 unitId, s32 a, s32 b);
extern void func_00194ff0(u8 *, u8 *, f32 *, f32 *);
extern f32 func_001ec250(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
u8 *func_00193bf0(u64 arg0, u64 arg1);
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void func_001f6cd0(void);

void func_001f14f0(u8 *arg0);
void func_001eb3b0(u8 *arg0);
extern void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
void func_001d8cb0(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void func_001a03b0(s64 *arg0);
void func_001dbf20(void *arg0, s32 arg1);
BtlPacket *func_001d3700(u16 arg0, u16 arg1);
s64 func_00194590(u8 *arg0, u32 arg1);
extern void func_0022db90(u8 *arg0);
extern void func_001f0a40(void *arg0);
extern void func_00212070(u8 *arg0, u8 *arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern void func_001eb4a0(u8 *arg0, u8 *arg1, u32 status);
extern s32 func_001f6930(u8 *arg0);
extern s32 func_001f6bf0(u8 *arg0);
extern s32 func_001f6f60(u8 *arg0);
extern s32 func_001f7140(u8 *arg0);
extern void func_001f62b0(void);
extern s32 func_001f62f0(u8 *arg0);
extern void func_001f86d0(void);
extern void func_001f9a50(s32 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void func_00213bb0(s32 arg0);
extern void func_00213be0(s32 arg0);
extern void func_00218560(u8 *arg0, u8 *arg1);
extern s32 func_00218690(s32 arg0);
extern void func_002186c0(u8 *arg0, s32 arg1);
extern void func_00218700(s32 arg0);
extern void func_00218730(s32 arg0);
extern u8 *func_0019bbe0(u8 *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern u8 *func_0019bd00(u8 *arg0);
extern u8 *func_0019bdd0(u8 *arg0);
extern u16 func_0020ba00(s32 task);
extern u32 func_001d8df0(s32 formation);
extern void func_0020bac0(s32 arg0);
extern u32 func_0020ba90(s32 task);
extern u32 func_0020ba60(s32 task);
extern s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0020ba30(s32 arg0);
extern void func_00203880(s32 arg0, s32 arg1);
extern BtlPacket *func_0019b6a0(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
u32 func_001deeb0(void *arg0);
void func_001ded30();
u32 func_001deee0();
s32 func_0023dfe0(u8 *unit);
u32 func_001d8bc0(void *arg0);
void func_001d8be0(s32 formation, u64 *unit);

extern u8 *iGpffffb3b8;
void func_001d8e50(u8 *arg0, u8 *arg1);
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
extern void func_00212010(s32 task);
void func_0019faf0(u8 *arg0);
u8 func_0023e1f0(u8 *unitData);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *func_0019a0c0(u8 *arg0, s16 arg1);
extern void func_001eb410(u8 *arg0);
extern BtlPacket *btlUnitCreateMoveToUnitPacket(BtlUnit *unit, BtlUnit *target, f32 distance, f32 speed, u32 flags);
extern BtlPacket *func_001d3530(u32 source, u32 target, u16 mode);
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32 arg0);
extern s16 func_001f6d60(u8 *arg0);
extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *func_00202740(u8 *arg0);
extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u8 *func_00194b60(void);
extern BtlPacket *func_001d3900(u16 arg0);
extern u8 *func_0019e9f0(u8 *unit, s16 value);
extern BtlPacket *func_001d3d00(u32 action);
BtlPacket *func_001ba090(s32 arg0);
BtlPacket *func_001d7a10(u16 mode);
u8 *func_00201f20(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 func_00242800(u8 *unit, s32 element);
u8 *func_001fa720(const void *data);
s32 func_001eb860(void);
extern void func_00218420(s32 task, u8 *arg1);
u8 *func_001fa8f0(void);
extern s32 func_002184a0(s32 task);
extern s32 func_002184d0(s32 task);
u8 *func_001faa60(void);
extern void func_00218500(s32 task);
extern void func_00212240(u8 *arg0, s32 arg1);
s32 func_0019ff60(u8 *arg0);
s64 *func_001b1540(void);
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
s32 func_001f01a0(u8 *arg0, u8 *arg1);
s32 func_0023d8e0(u8 *arg0, u16 arg1);
u8 *func_001fa9c0(void);
s32 func_001db5e0(u8 *arg0, s64 arg1);
u32 func_00193cd0(u32 arg0);
u8 *func_001fa110(u8 *arg0);
extern void func_002182c0(u8 *arg0, u8 *arg1);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00194c90(s32 arg0, s32 arg1);
u8 *func_001d65d0(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
extern s32 func_00218360(s32 task);
extern s32 func_00218390(s32 task);
u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *func_001fa320(void);
u8 *func_001fa450(void);
u8 *func_002027e0(void);
extern void func_002183c0(s32 task);
extern void func_00218160(u8 *task, u8 *unit);
extern s32 func_00218200(s32 task);
extern s32 func_00218230(s32 task);
extern void func_00218260(s32 task);
s16 func_001d15a0(void);
void func_001eb7f0(void);
s32 func_001ef720(s32 arg0, s32 arg1);
s32 func_001fabe0(u8 *arg0);
u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
s32 func_00232d80(u8 *arg0);
s64 func_00235320(u8 *arg0);
s32 func_00243e30(u16 *arg0);
s32 func_001f6770(u8 *arg0);
s32 func_001fac30(void);
s32 func_001a3de0(u8 *arg0);

u8 *func_002022e0(u32 arg0, u16 arg1);
s32 func_0010b300(s32 arg0);
extern void func_0019ef30(u8 *arg0, u16 arg1);
extern void func_0010b7f0(void);
extern s32 datGetFlag(s32 arg0);
BtlPacket *func_001d6240(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
BtlPacket *func_001f7c20(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;
s32 func_001fac80(u8 *arg0);
void func_001fad10(void);



// FUN_001A0140
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
#pragma opt_loop_invariants on
s32 func_001a0140(u8 *arg0)
{
    s32 i0;
    u8 temp_3;

    temp_3 = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (temp_3) {
    case 0:
    {
        s32 j0;
        s32 n0;
        s32 count0;
        s32 mask0;
        u8 *target0;

        i0 = 0;
        n0 = *(u16 *)(arg0 + 0x6A);
        mask0 = 0x100000;
        goto outer0_test;
outer0_body:
        target0 = *(u8 **)(arg0 + ((u16)i0 * 4) + 0x38);
        count0 = target0[0xD9];
        j0 = 0;
        goto inner0_test;
inner0_body:
        if ((*(s32 *)(target0 + ((u16)j0 << 5) + 0xF8) & mask0) != 0) {
            return 1;
        }
        j0 = (j0 + 1) & 0xFFFF;
inner0_test:
        if ((j0 & 0xFFFF) < count0) {
            goto inner0_body;
        }
        i0 = (i0 + 1) & 0xFFFF;
outer0_test:
        if ((i0 & 0xFFFF) >= n0) {
            goto block_20;
        }
        goto outer0_body;
    }
    case 1:
    {
        s32 i1;
        s32 j1;
        s32 n1;
        s32 count1;
        u8 *target1;

        i1 = 0;
        n1 = *(u16 *)(arg0 + 0x6A);
        goto outer1_test;
outer1_body:
        target1 = *(u8 **)(arg0 + ((u16)i1 * 4) + 0x38);
        count1 = target1[0xD9];
        j1 = 0;
        goto inner1_test;
inner1_body:
        if ((*(u16 *)(target1 + ((u16)j1 << 5) + 0x10E) & 4) != 0) {
            return 1;
        }
        j1 = (j1 + 1) & 0xFFFF;
inner1_test:
        if ((j1 & 0xFFFF) < count1) {
            goto inner1_body;
        }
        i1 = (i1 + 1) & 0xFFFF;
outer1_test:
        if ((i1 & 0xFFFF) < n1) {
            goto outer1_body;
        }
        goto block_20;
    }
    default:
        goto block_20;
    }
block_20:
    return 0;
}
/* measured: close loop-invariant probe for 001A0140. */
#pragma opt_loop_invariants off
// FUN_001A0290
void func_001a0290(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 temp_5;
    s32 temp_3;
    u8 *temp_4;

    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s16 *)arg2 = 0x24;
        *(s16 *)(arg2 + 2) = -1;
        return;
    }
    *(s16 *)arg2 = 0;
    *(s16 *)(arg2 + 2) = 3;
    temp_5 = (arg1 & 0xFFFF) * 0x28;
    if (*(u8 *)(iGpffffb3b8 + temp_5) & 2) {
        temp_4 = *(u8 **)(arg0 + 0x30);
        if (temp_4[0xA2] == 0) {
            temp_3 = func_0023e1f0(*(u8 **)(temp_4 + 0xA64)) & 0xFF;
            switch (temp_3) {
            case 0:
            case 1:
            case 6:
                *(s16 *)arg2 = 1;
                *(s16 *)(arg2 + 2) = 4;
                return;
            case 5:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                return;
            case 2:
            case 3:
            case 4:
                break;
            }
        } else {
            switch (*(u16 *)(temp_4 + 0xA4)) {
            case 0x109:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                break;
            }
        }
    }
}
// FUN_001A03B0
void func_001a03b0(s64 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *var_16;

    temp_5 = D_0076449C;
    if (*(s32 *)(temp_5 + 0xC) & 0x400000) {
        if (*(u16 *)(temp_5 + 0x18) & 0x20) {
            temp_2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
            *(s64 *)(temp_2 + 0x60) = *arg0;
            func_00194590(temp_2, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 2) {
            temp_2_2 = (u8 *)func_001d3700(3, 0xFFF);
            *(s64 *)(temp_2_2 + 0x60) = *arg0;
            func_00194590(temp_2_2, 0);
        }
        temp_4 = D_0076449C;
        if (*(u16 *)(temp_4 + 0x18) & 1) {
            var_16 = *(u8 **)(temp_4 + 0x174);
            goto loop_test;
loop_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) &&
                datCalcIsDead(*(s32 *)(*(u8 **)(var_16 + 0x30) + 0xA64), 0) == 0) {
                temp_2_3 = func_0019a0c0(*(u8 **)(var_16 + 0x30), 0);
                *(s64 *)(temp_2_3 + 0x60) = *arg0;
                func_00194590(temp_2_3, 0);
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_test:
            if (var_16 != NULL) {
                goto loop_body;
            }
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x10) {
            temp_2_4 = (u8 *)func_001ba090(0);
            *(s64 *)(temp_2_4 + 0x60) = *arg0;
            func_00194590(temp_2_4, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 8) {
            temp_2_5 = (u8 *)func_001d7a10(5);
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 4) {
            temp_2_6 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x24);
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 0);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x40) {
            temp_2_7 = func_00201f20();
            *(s64 *)(temp_2_7 + 0x60) = *arg0;
            func_00194590(temp_2_7, 0);
        }
        *(u16 *)(D_0076449C + 0x18) = 0;
        temp_5_2 = D_0076449C;
        *(s32 *)(temp_5_2 + 0xC) &= 0xFFBFFFFF;
    }
}
// FUN_001A05F0
s32 func_001a05f0(u8 *arg0) {
    u16 temp_5;
    u8 *temp_3;

    temp_5 = *(u16 *)(arg0 + 0x1A);
    if (temp_5 & 1) {
        goto cont1;
    }
    return 0;
cont1:
    temp_3 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA0C);
    if (temp_5 & 0x10) {
        goto cont2;
    }
    return 0;
cont2:
    return (*(s32 *)(temp_3 + 0x98) & 2) != 0;
}



// FUN_001A0640
void func_001a0640(void)
{
}

// FUN_001A0650
void func_001a0650(void)
{
}

// FUN_001A0660
void func_001a0660(void)
{
}

// FUN_001A0670
void func_001a0670(u8 *arg0) {
    s32 temp_5;

    temp_5 = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C);
    if (temp_5 & 0x10) {
        *(s16 *)(arg0 + 0x430) = 1;
        btlActionSetState((BtlAction *)arg0, 0x18);
        return;
    }
    if (temp_5 & 1) {
        btlActionSetState((BtlAction *)arg0, 0x23);
    }
}



// FUN_001A06D0
void func_001a06d0(u8 *arg0) {
    extern void btlActionSetState(u8 *arg0, u16 arg1);
    u8 *var_17;
    s32 var_16;
    u32 temp_4;
    s16 temp_17;
    s32 var_2;

    var_16 = 1;
    if (*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x10) {
        *(s16 *)(arg0 + 0x430) = 2;
        btlActionSetState(arg0, 0x18);
        return;
    }
    var_17 = *(u8 **)(D_0076449C + 0x174);
    while (var_17 != NULL) {
        if ((arg0 != var_17) && (*(u16 *)(var_17 + 0x1A) & 1) &&
            (datCalcIsDead(*(s32 *)(*(u8 **)(var_17 + 0x30) + 0xA64), 0) == 0) &&
            (*(s32 *)(*(u8 **)(var_17 + 0x30) + 0x9C) & 0x10)) {
            var_16 = 0;
            break;
        }
        var_17 = *(u8 **)(var_17 + 0x450);
    }
    func_0022db90(arg0);
    if (*(u16 *)(arg0 + 0x18) & 0x8000) {
        btlActionSetState(arg0, 0x21);
        return;
    }
    func_001f0a40(arg0 + 0xD8);
    if (func_001fabe0(arg0) != 0) {
        *(void **)(arg0 + 0x440) = (void *)&func_001fac30;
        *(s16 *)(arg0 + 0x43C) = 2;
        btlActionSetState(arg0, 0x16);
        return;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        var_2 = 0;
    } else if ((*(s16 *)(iGpffffb3ac + 0xA70) != -1) &&
               (temp_4 = func_001ef720(2, 0x80000) & 0xFFFF,
                (u32)(*(s16 *)(iGpffffb3ac + 0xA72) >> 1) >= temp_4) &&
               ((temp_17 = *(s16 *)(iGpffffb3ac + 0xA70)) != (s16)func_001d15a0())) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if ((var_2 != 0) &&
        (datCalcChkBadStatus((s32)*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180001) == 0)) {
        actionSetDelayBytes(arg0, 4, 1);
        return;
    }
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) {
        var_16 = 0;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    } else {
        *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
        func_001eb7f0();
    }
    if ((s32)*(u8 *)(arg0 + 0x28) > 0) {
        if (!(*(s32 *)(iGpffffb3ac + 0x10) & 0x20)) {
            func_00212070(*(u8 **)(iGpffffb3ac + 0xDD4), arg0);
            func_00194590(func_001f99c0(arg0, 0xE, 0, 0, 0), 1);
        }
    } else {
        *(u16 *)(arg0 + 0x18) |= 0x400;
        *(u16 *)(arg0 + 0x1A) &= 0xFFBF;
    }
    if ((*(u8 *)(arg0 + 0x28) == 0) && (*(u8 *)(arg0 + 0x29) == 0)) {
        *(s32 *)(arg0 + 0x41C) = func_00232d80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    } else {
        *(s32 *)(arg0 + 0x41C) = 0;
    }
    if ((*(s32 *)(arg0 + 0x41C) != 0) ||
        (func_00243e30(*(u16 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) != 0)) {
        var_16 = 0;
    }
    if (var_16 != 0) {
        if ((*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0) &&
            (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4) == 1) &&
            (*(u8 *)(arg0 + 0x28) == 0) && (*(u8 *)(arg0 + 0x29) == 0)) {
            *(s32 *)(iGpffffb3ac + 0x20) += 1;
        }
        if ((s8)func_00235320(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) >= 0) {
            btlActionSetState(arg0, 0xA);
            return;
        }
        if (func_001f6770(arg0) != 0) {
            btlActionSetState(arg0, 0xB);
            return;
        }
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x14));
    }
}
/* P4 initializes and copies the complete 0x20-byte target result. The P3FES
 * state-start donor explains the aggregate mechanism, but its result is 0x1c
 * bytes. Typed action/unit members and u16 casts avoid hoisting field addresses
 * and the mask into saved registers. See the 2026-09-20 donor recovery proof. */
// FUN_001A0B00
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
void func_001a0b00(s64 *arg0) {
    extern void func_001f0a10(u8 *arg0);
    extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *func_00202740(u8 *arg0);
    extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
    typedef struct DatUnit DatUnit;
    typedef struct ActionUnitView {
        u8 unknown00[0xA64];
        DatUnit *data;
    } ActionUnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x28];
        ActionUnitView *unit;
        u8 unknown34[0x3E8];
        u32 passiveFlags;
    } ActionView;
    extern u16 func_00231f80(DatUnit *arg0);
    extern u16 func_00232290(DatUnit *arg0);
    extern BtlPacket *func_001f7c20(u16 channel, u16 cue, u16 variant);
    extern void btlActionSetState(s64 *arg0, u16 arg1);
    typedef struct ActionResult {
        s32 hpDelta;
        s32 spDelta;
        u32 statusFlags;
        u32 otherStatusFlags;
        s32 value10;
        s32 value14;
        u8 fields18[6];
        u16 flags;
    } ActionResult;
    typedef char ActionResultSizeCheck[sizeof(ActionResult) == 0x20 ? 1 : -1];
    ActionResult result;
    ActionView *action;
    s64 var_17;
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;

    action = (ActionView *)arg0;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) == 0 &&
        func_00193cd0(0x700) == 0 && func_00193cd0(0x504) == 0 &&
        func_00193cd0(0x506) == 0 && func_00193cd0(0x301) == 0 &&
        func_00193cd0(0x104) == 0) {
        func_001a03b0(arg0);
        func_001f0a10((u8 *)&result);
        if (func_00243e30((u16 *)action->unit->data) != 0) {
            result.flags |= 0x80;
        }
        if (action->passiveFlags != 0) {
            temp_16 = (u16)func_00231f80(action->unit->data);
            func_00232290(action->unit->data);
            var_17 = 0x16;
            if (action->passiveFlags & 1) {
                result.hpDelta += ((u16)temp_16 * 0x64) / 5000;
            }
            if (action->passiveFlags & 2) {
                result.hpDelta += ((u16)temp_16 * 0x64) / 2500;
            }
            if (action->passiveFlags & 4) {
                result.hpDelta += ((u16)temp_16 * 0x64) / 1666;
            }
            if (action->passiveFlags & 8) {
                result.spDelta += 3;
            }
            if (action->passiveFlags & 0x10) {
                result.spDelta += 5;
            }
            if (action->passiveFlags & 0x20) {
                result.spDelta += 7;
            }
        }
        if ((result.flags != 0) || (result.hpDelta != 0) || (result.spDelta != 0)) {
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                temp_2 = func_00202740((u8 *)action->unit);
                *(s64 *)(temp_2 + 0x60) = action->uid;
                func_00194590(temp_2, 1);
                if ((s16)var_17 != -1) {
                    temp_2_2 = (u8 *)func_001f7c20(0xE, 2, (u16)var_17);
                    *(s64 *)(temp_2_2 + 0x60) = action->uid;
                    func_00194590(temp_2_2, 1);
                }
            }
            temp_2_3 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &result, 1, 1);
            *(s64 *)(temp_2_3 + 0x60) = action->uid;
            func_00194590(temp_2_3, 1);
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                s32 unit;
                unit = (s32)(u8 *)action->unit;
                temp_2_4 = func_00201de0(unit, unit, -1, 0, 0, 0, 1, &result, 8);
                *(s8 *)(temp_2_4 + 0) = 4;
                *(s64 *)(temp_2_4 + 8) = *(s64 *)(temp_2_3 + 0x58);
                *(u8 *)(temp_2_4 + 0x47) &= ~0x20;
                func_00194590(temp_2_4, 3);
                if (result.hpDelta != 0) {
                    temp_2_5 = (u8 *)func_00202590((s32)(u8 *)action->unit, 0, 0);
                    *(s8 *)(temp_2_5 + 0) = 4;
                    *(s64 *)(temp_2_5 + 8) = *(s64 *)(temp_2_3 + 0x58);
                    *(u8 *)(temp_2_5 + 0x47) &= ~0x20;
                    func_00194590(temp_2_5, 3);
                }
            }
        }
        if ((s8)func_00235320((u8 *)action->unit->data) >= 0) {
            btlActionSetState(arg0, 0xA);
        } else if (func_001f6770((u8 *)arg0) != 0) {
            btlActionSetState(arg0, 0xB);
        } else {
            btlActionSetState(arg0, 3);
        }
    }
}
#pragma pop
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
#pragma opt_propagation off
// FUN_001A0F40
void func_001a0f40(s64 *arg0)
{
    extern void btlActionSetState(s64 *arg0, u16 arg1);
    RwV3d sp30;
    s32 temp_7;
    u16 var_5;
    u16 temp_6;
    u8 temp_3;
    u8 *temp_16;
    u8 *temp_2;
    u32 source_offset;
    u32 tbl;
    u32 sum;
    u32 idx4;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) &&
        ((*(u16 *)((u8 *)arg0 + 0x1A) & 1) != 0) &&
        (temp_16[0xA2] == 0)) {
        *(u16 *)((u8 *)arg0 + 0x14) = 9;
    }
    if (func_001b0e90(arg0) != 0) {
        btlActionSetState(arg0, *(u16 *)((u8 *)arg0 + 0x14));
        return;
    }
    func_00194ff0(temp_16, (u8 *)&sp30, 0, NULL);
    if (!(func_001ec250((const RwV3d *)(temp_16 + 4), &sp30) <= 75.0f)) {
        var_5 = 2;
        temp_7 = (u16)(!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2));
        temp_6 = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) + 2);
        temp_3 = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2);
        switch (temp_3) {
        case 0:
            break;
        case 1:
            tbl = (u32)iGpffffb3cc;
            source_offset = (u32)temp_6 * 0xE8;
            sum = source_offset + tbl;
            idx4 = (u16)temp_7 * 4;
            var_5 = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        temp_2 = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)((u8 *)arg0 + 0x30), &sp30, D_005F6D20[var_5 & 0xFFFF], 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        return;
    }
    btlActionSetState(arg0, *(u16 *)((u8 *)arg0 + 0x14));
}
/* measured: restore propagation for the rest of the unit. */
#pragma opt_propagation on
// FUN_001A1450
void func_001a1450(s64 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    } sp40;
    struct Vec3 sp30;
    u16 temp_3;
    u16 temp_3_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *var_16;
    u8 *var_16_2;

    extern void func_001958f0(u8 *arg0, f32 *arg1);
    extern s32 btlUnitIsMoving(u8 *arg0);

    extern void func_00194590(u8 *arg0, s32 arg1);
    extern void func_00203670(s32 arg0, u8 *arg1);
    extern void func_00213c10(s32 task);

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) &&
        (*(u16 *)((u8 *)arg0 + 0x1A) & 1) &&
        (*(u8 **)((u8 *)arg0 + 0x30))[0xA2] == 0) {
        btlActionSetState((BtlAction *)arg0, 9);
        return;
    }
    func_001a03b0(arg0);
    temp_3 = *(u16 *)((u8 *)arg0 + 0x10);
    if ((temp_3 != 0x25) && (temp_3 != 4) && (temp_3 != 6) &&
        (temp_3 != 5) && (*(u16 *)(iGpffffb3ac + 0xF4) != 2)) {
        func_00194ff0(
            *(u8 **)((u8 *)arg0 + 0x30), NULL, 0, (f32 *)&sp40);
        var_16 = *(u8 **)(iGpffffb3ac + 0x17C);
        goto loop_14_test;
loop_14_body:
        if (datCalcChkBadStatus((s32)*(u8 **)(var_16 + 0xA64), 0x100) != 0) {
            func_001958f0(
                *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                (f32 *)&sp30);
        } else {
            sp30 = sp40;
        }
        temp_2 = actionRotatePacketBytes(var_16, &sp30, 2);
        *(s64 *)(temp_2 + 0x60) = *arg0;
        func_00194590(temp_2, 0);
        var_16 = *(u8 **)(var_16 + 0xA68);
loop_14_test:
        if (var_16 != NULL) {
            goto loop_14_body;
        }
        var_16_2 = *(u8 **)(iGpffffb3ac + 0x184);
        goto loop_19_test;
loop_19_body:
        if (btlUnitIsMoving(var_16_2) == 0) {
            func_00194ff0(var_16_2, NULL, 0, (f32 *)&sp40);
            temp_2_2 = actionRotatePacketBytes(var_16_2, &sp40, 2);
            *(s64 *)(temp_2_2 + 0x60) = *arg0;
            func_00194590(temp_2_2, 0);
        }
        var_16_2 = *(u8 **)(var_16_2 + 0xA68);
loop_19_test:
        if (var_16_2 != NULL) {
            goto loop_19_body;
        }
        temp_2_3 = (u8 *)func_001d3700(3, 0x8001);
        *(s64 *)(temp_2_3 + 0x60) = *arg0;
        func_00194590(temp_2_3, 0);
        if (*(u8 *)((u8 *)arg0 + 0x28) == 0) {
            temp_2_4 = actionTargetPacketBytes((u8 *)arg0, 0x1D, 0, 0, 0);
            *(s64 *)(temp_2_4 + 0x60) = *arg0;
            func_00194590(temp_2_4, 1);
        }
    }
    {
        u8 *temp_5;

        temp_5 = *(u8 **)((u8 *)arg0 + 0x30);
        if (temp_5[0xA2] == 0) {
            temp_2_5 = actionLookAtUnit(NULL, temp_5, 2);
            *(s64 *)(temp_2_5 + 0x60) = *arg0;
            func_00194590(temp_2_5, 1);
        } else {
            temp_2_6 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 2);
            *(s64 *)(temp_2_6 + 0x60) = *arg0;
            func_00194590(temp_2_6, 1);
        }
    }
    func_00194590(
        (u8 *)btlUnitCreateLookAtDeactivatePacket(
            (BtlUnit *)*(s32 *)(u8 *)func_001a_add_offset(0x30, (s32)arg0), 0),
        1);
    temp_2_7 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x21);
    *(s64 *)(temp_2_7 + 0x60) = *arg0;
    func_00194590(temp_2_7, 0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    temp_3_2 = *(u16 *)(u8 *)func_001a_add_offset(0x10, (s32)arg0);
    if ((temp_3_2 != 0x25) && (temp_3_2 != 6) && (temp_3_2 != 5)) {
        func_00203670(*(s32 *)(iGpffffb3ac + 0xDD4), (u8 *)arg0);
        func_00213c10(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    func_0019faf0((u8 *)arg0);
    *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
    *(u16 *)((u8 *)arg0 + 0x41C) = 0;
    *(s32 *)((u8 *)arg0 + 0x420) = 0;
}
/* measured 001a17d0: obj 1192B/window 1200B (-8B, -0.7% inside, 2-instr slack); 0 words via `python3 tools/measure_guarded.py src/promoted/code1_001a.c func_001a17d0`, 0 edits (+28 reloc-only) 298/298 via `python3 tools/fnalign.py src/promoted/code1_001a.c func_001a17d0 --candidate /tmp/candF_f32.c --quiet`; Jal 36 both sides. Switch v4 &0xFFFF reverse 2,0/default (compiler checks 0 first, matching retail layout; was if/else with bne losing andi+beq+b); switch v10 numeric 1,2,3,10 (compiler checks 10,3,2,1, matching retail; was reverse 10,3,2/1 checking 1 first); s32 f (was u16, fixes $a0 vs $v1 + extra andi); tail before check9 (was 9 before tail, fixing 37/37 pure hole/lump exactly equal, 294/297 inside hiding swap, edits 120->0). Production MATCH. */
// FUN_001A17D0
void func_001a17d0(u8 *arg0)
{
    extern u8 *btlCameraCreateSetStatePacket(u8 *arg0, s32 arg1);
    extern u16 D_008C024C[];
    s32 v4;
    u16 t;
    u16 v10;
    s32 f;
    s32 bVar;
    s16 sVar2;
    u8 *w;
    u8 *i;

    func_0019fc60();
    func_0019fa40();
    func_00212010(*(s32 *)(iGpffffb3ac + 0xDD4));
    if (*(s32 *)(arg0 + 0x420) == 1) {
        t = *(u16 *)(arg0 + 0x41C);
        if (t == 0) {
            func_002037b0(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(arg0 + 0x420) = 0;
        } else {
            *(u16 *)(arg0 + 0x41C) = t - 1;
        }
        return;
    }
    v4 = func_002037e0(*(s32 *)(iGpffffb3ac + 0xDD4)) & 0xFFFF;
    if ((D_008C024C[0] & 8) != 0 && (v4 & 0xFFFF) == 1 && (*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) == 0) {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000) != 0) {
            if (func_00203810(*(s32 *)(iGpffffb3ac + 0xDD4)) == 1) {
                if (func_00203850(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
                    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) == 0) {
                        func_0020bf60(*(s32 *)(iGpffffb3ac + 0xDD4));
                        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x10000;
                        func_00213b80(*(s32 *)(iGpffffb3ac + 0xDD4));
                        func_00204d90(*(s32 *)(iGpffffb3ac + 0xDD4));
                        w = btlCameraCreateSetStatePacket(arg0, 40);
                        *(s64 *)(w + 0x60) = *(s64 *)arg0;
                        func_00194590(w, 0);
                    }
                    return;
                }
            }
        }
    } else {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x10000) != 0) {
            func_0020bf90(*(s32 *)(iGpffffb3ac + 0xDD4));
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & ~0x10000;
            func_00213b50(*(s32 *)(iGpffffb3ac + 0xDD4));
            func_00204d50(*(s32 *)(iGpffffb3ac + 0xDD4));
            w = btlCameraCreateSetStatePacket(arg0, 33);
            *(s64 *)(w + 0x60) = *(s64 *)arg0;
            func_00194590(w, 0);
        }
    }
    switch (v4 & 0xFFFF) {
    case 2: {
        v10 = *(u16 *)(arg0 + 0x6C);
        switch (v10) {
        case 1:
        case 2:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 0);
            bVar = 1;
            break;
        case 3:
            f = (u16)func_001fae80(arg0, *(u16 *)(arg0 + 0x6E), 1);
            bVar = 1;
            break;
        case 10:
            f = 0;
            bVar = 1;
            break;
        default:
            f = 0;
            bVar = 0;
            break;
        }
        if (bVar != 0) {
            sVar2 = func_001fb170(f);
            if (sVar2 != 0) {
                func_0045af60(0, 15, 0, 8);
                func_002019f0(*(s32 *)(arg0 + 0x30), sVar2);
                *(u16 *)(arg0 + 0x41C) = 6;
                *(s32 *)(arg0 + 0x420) = 1;
                func_00203890(*(s32 *)(iGpffffb3ac + 0xDD4));
                return;
            } else {
                func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
                func_00204d90(*(s32 *)(iGpffffb3ac + 0xDD4));
                btlActionSetState((BtlAction *)arg0, 6);
                return;
            }
        }
        goto tail;
    }
    case 0:
        goto tail;
    default:
        goto check9;
    }
tail:
    *(u16 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0x18) | 2;
    func_00212040(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_00216ca0(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_002038c0(*(s32 *)(iGpffffb3ac + 0xDD4));
    func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
    for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
    }
    btlActionSetState((BtlAction *)arg0, 15);
    return;
check9:
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) {
        func_00212040(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00216ca0(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_002038c0(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00213c40(*(s32 *)(iGpffffb3ac + 0xDD4));
        for (i = *(u8 **)(iGpffffb3ac + 0x174); i != 0; i = *(u8 **)(i + 0x450)) {
        }
        btlActionSetState((BtlAction *)arg0, 9);
    }
    return;
}
// FUN_001A1C80
void func_001a1c80(u8 *arg0)
{
    u8 *var_17;
    s32 var_16;
    u8 temp_3;
    u8 *temp_2;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 4:
        func_001d7c60(arg0, arg0 + 0x98, 2, 0, 0);
        var_16 = func_001a_fix_var(*(u16 *)(arg0 + 0x6E));
        break;
    default:
        var_16 = *(u16 *)(arg0 + 0x6E);
        temp_3 = *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                               (u32)iGpffffb3b8) + 8);
        switch (temp_3) {
        case 1:
        case 2:
            {
                extern void func_001d7c60(
                    u8 *arg0, u8 *arg1, u8 arg2, u8 arg3, u32 arg4);
                func_001d7c60(
                    arg0,
                    arg0 + 0x98,
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 9),
                    *(u8 *)(func_001a_add_offset(var_16 * 0x28,
                                                  (u32)iGpffffb3b8) + 0xA),
                    0);
            }
            break;
        default:
            func_001d7f10(arg0, arg0 + 0x98, var_16 & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    func_001d8cb0(arg0, arg0 + 0x98);
    temp_3 = *(u8 *)(func_001a_add_offset(
        *(u16 *)(arg0 + 0x6E) * 0x28, (u32)iGpffffb3b8) + 8);
    switch (temp_3) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    var_17 = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    func_001d8e50(arg0, arg0 + 0x98);
after_type_1c80:
    func_0020b6d0(
        *(s32 *)(D_0076449C + 0xDD4),
        arg0,
        arg0 + 0x98,
        (s64)(s16)var_16);
    temp_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x22);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    func_00212010(*(s32 *)(D_0076449C + 0xDD4));
    func_0019faf0(arg0);
    if (var_17 != NULL) {
        temp_2 = actionLookAtUnit(NULL, *(u8 **)(var_17 + 0x30), 1);
        func_00194590(temp_2, 1);
        temp_2 = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)*(s32 *)(var_17 + 0x30), 0);
        func_00194590(temp_2, 1);
    }
}
#pragma push
#pragma opt_common_subs on
static inline void actionCopySelectedTarget(u8 *action, const u16 *index)
{
    u8 *slot = action + *index * 4;
    *(u8 **)(slot + 0x38) = *(u8 **)(slot + 0x98);
}

static inline u8 *actionSelectionOffset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}

/* The task helpers explicitly consume their task and return the selected
 * formation entry. Sparse switches preserve retail's separate branch joins;
 * the u16 copy cursor wraps at its stored width. Sequence the count load before
 * reading that cursor so the configured b210 -O2 owner emits all 1528 retail
 * bytes, followed by eight zero alignment bytes. CSE remains at its default. */
// FUN_001A1EA0
void func_001a1ea0(u8 *action) {
    extern u16 D_008C024C[];
    extern void func_0019fa40(void);
    extern void func_0019fc60(void);
    extern s32 func_001fb170(s32 condition);
    extern void func_002019f0(s32 unit, u32 message);
    extern void func_002037b0(s32 task);
    extern void func_002038c0(s32 task);
    extern void func_00204d50(s32 task);
    extern void func_0020bf60(s32 task);
    extern void func_0020bf90(s32 task);
    extern void func_00212040(s32 task);
    extern void func_00213b50(s32 task);
    extern void func_00213b80(s32 task);
    extern void func_00213c10(s32 task);
    extern void func_00213c40(s32 task);
    extern void func_00216ca0(s32 task);
    s32 selectionState;
    s32 selectedAddress;
    s32 battleFlags;
    s32 selectionMode;
    u16 targetIndex;
    s32 condition;
    s32 messageId;
    u16 targetCount;
    u16 actionKind;
    u8 *enterCamera;
    u8 *exitCamera;
    u8 *selectedAction;
    u8 *selectedUnit;
    u8 targetMode;
    u8 *selectionBattle;
    u8 *enteredBattle;
    u8 *exitedBattle;
    u8 *battle;
    u8 *actionCursor;
    u8 *clearCursor;

    func_0019fc60();
    func_0019fa40();
    selectionState = func_0020ba00((s32)(*(u8**)(iGpffffb3ac + 0xDD4))) & 0xFFFF;
    if ((D_008C024C[0] & 8) && !(selectionState & 0xFFFF)) {
        battleFlags = (*(s32*)(iGpffffb3ac + 0xC));
        if (battleFlags & 0x20000) {
            if (!(battleFlags & 0x10000) && ((func_001d8df0((s32)(action + 0x98)) & 0xFFFF) != 1)) {
                func_0020bf60((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                enteredBattle = iGpffffb3ac;
                (*(s32*)(enteredBattle + 0xC)) = (s32) ((*(s32*)(enteredBattle + 0xC)) | 0x10000);
                func_00213b80((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
                enterCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x28);
                (*(s64*)(enterCamera + 0x60)) = (s64) (*(s64*)action);
                func_00194590(enterCamera, 0U);
            }
            return;
        }
        goto select_action;
    }
    battle = iGpffffb3ac;
    if ((*(s32*)(battle + 0xC)) & 0x10000) {
        func_0020bf90((s32)(*(u8**)(battle + 0xDD4)));
        exitedBattle = iGpffffb3ac;
        (*(s32*)(exitedBattle + 0xC)) = (s32) ((*(s32*)(exitedBattle + 0xC)) & 0xFFFEFFFF);
        func_00213b50((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        exitCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x22);
        (*(s64*)(exitCamera + 0x60)) = (s64) (*(s64*)action);
        func_00194590(exitCamera, 0U);
    }
select_action:
    selectionMode = selectionState & 0xFFFF;
    switch (selectionMode) {
    case 0:
        selectionBattle = iGpffffb3ac;
        if ((*(s32*)(selectionBattle + 0xC)) & 0x1000) {
            func_00212040((s32)(*(u8**)(selectionBattle + 0xDD4)));
            func_00216ca0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_002038c0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            actionCursor = (*(u8**)(iGpffffb3ac + 0x174));
            while (actionCursor != NULL) {
                actionCursor = *(u8 **)(actionCursor + 0x450);
            }
            btlActionSetState((BtlAction *)action, 9);
            func_00194590((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
            return;
        }
        selectedAction = (u8 *)func_0020ba90((s32)(*(u8**)(selectionBattle + 0xDD4)));
        if (selectedAction != NULL) {
            selectedUnit = (*(u8**)(selectedAction + 0x30));
            if ((*(u8*)(selectedUnit + 0xA2)) == 1) {
                func_00194590((u8*)actionLookAtUnit(NULL, selectedUnit, 1), 1U);
                func_00194590((u8*)btlUnitCreateLookAtDeactivatePacket(*(BtlUnit **)(selectedAction + 0x30), 0), 1U);
                return;
            }
        }
        func_00194590((u8*)btlUnitCreateLookAtDeactivatePacket(0, 3), 1U);
        return;
    case 1:
        targetMode = *(u8 *)(actionSelectionOffset(*(u16 *)(action + 0x6E) * 0x28, iGpffffb3b8) + 8);
        switch (targetMode) {
        case 1:
        case 2: {
            targetIndex = 0;
            while ((targetCount = *(u16 *)(action + 0xD0), targetIndex < (s32)targetCount)) {
                actionCopySelectedTarget(action, &targetIndex);
                targetIndex++;
            }
            (*(u16*)(action + 0x6A)) = targetCount;
        } break;
        default: {
            selectedAddress = (s32)func_0020ba60((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            (*(u8**)(action + 0x38)) = (u8*)selectedAddress;
            (*(u16*)(action + 0x6A)) = 1U;
            func_001d8be0((s32)(action + 0x98), (u64 *)(u32)selectedAddress);
        } break;
        }
        actionKind = (*(u16*)(action + 0x6C));
        switch (actionKind) {
        case 1:
        case 2:
            condition = func_001faf70(action, (s32) (*(u16*)(action + 0x6E)), 0) & 0xFFFF;
            break;
        case 3:
            condition = func_001faf70(action, (s32) (*(u16*)(action + 0x6E)), 1) & 0xFFFF;
            break;
        default:
            condition = 0;
            break;
        }
        messageId = (s16)func_001fb170(condition);
        if (messageId != 0) {
            func_0045af60(0, 0xF, 0, 8);
            func_002019f0(*(s32 *)(action + 0x30), (u32)messageId);
            func_0020ba30((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            return;
        }
        switch (*(u16 *)(action + 0x6C)) {
        case 4: {
            func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00203880((s32)(*(u8**)(iGpffffb3ac + 0xDD4)), (s32)(*(u8**)(action + 0x38)));
            btlActionSetState((BtlAction *)action, 5);
            return;
        } break;
        default: {
            (*(u16*)(action + 0x18)) = (u16) ((*(u16*)(action + 0x18)) | 2);
            func_00212040((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00216ca0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_002038c0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            func_00213c40((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
            clearCursor = (*(u8**)(iGpffffb3ac + 0x174));
            while (clearCursor != NULL) {
                clearCursor = *(u8 **)(clearCursor + 0x450);
            }
            btlActionSetState((BtlAction *)action, 0xF);
            return;
        } break;
        }
    case 2:
        func_00194590((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
        func_0020bac0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_00213c10(*(s32 *)(iGpffffb3ac + 0xDD4));
        func_00204d50((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        func_002037b0((s32)(*(u8**)(iGpffffb3ac + 0xDD4)));
        btlActionSetState((BtlAction *)action, 5);
        /* fallthrough */
    case 3:
        return;
    }
}

#pragma pop
// FUN_001A24A0
void func_001a24a0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x41c) = 1;
}
/* measured: 1564/1568 bytes, 47 resolved relocations, four zero tail bytes.
 * Loop invariants hoist the first scan's true value and each unsigned wrap
 * bound as retail does. Stored short cursor and widened index stay distinct. */
// FUN_001A24B0
#pragma push
#pragma opt_loop_invariants on
void func_001a24b0(u8 *action)
{
    extern u16 D_008C024C[];
    extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);

    if (func_00193cd0(0x800) != 0) {
        return;
    }
    switch (*(s32 *)(action + 0x41C)) {
    case 1: {
        u8 *openingPacket;
        u8 *iter;
        s32 hasOther;
        u8 *selected;
        s16 index;

        openingPacket = (u8 *)func_001d3700(3, 0xFFF);
        *(s64 *)(openingPacket + 0x60) = *(s64 *)action;
        func_00194590(openingPacket, 0);
        iter = *(u8 **)(D_0076449C + 0x174);
        while (iter != NULL) {
            u8 *packet;
            if (*(u16 *)(iter + 0x1A) & 1) {
                if (action == iter || !(*(u16 *)(iter + 0x1A) & 8)) {
                    packet = func_0019bdd0(*(u8 **)(iter + 0x30));
                } else {
                    packet = func_0019bbe0(*(u8 **)(iter + 0x30), 0xFFFFFF, 8, 0, 4, 0);
                }
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                func_00194590(packet, 0);
            }
            iter = *(u8 **)(iter + 0x450);
        }
        selected = *(u8 **)(action + 0x38);
        func_001d7c60(action, action + 0x98, 2, 0, 0);
        hasOther = 0;
        *(u16 *)(action + 0xD2) = *(u16 *)(action + 0xD0);
        index = 0;
        while ((s16)index < *(u16 *)(action + 0xD0)) {
            u8 **slot = (u8 **)(action + (s16)index * 4 + 0x98);
            if (*slot == selected) {
                *(u16 *)(action + 0xD2) = index;
            }
            if (*(u16 *)(*(u8 **)(*slot + 0x30) + 0xA4) !=
                *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                hasOther = 1;
            }
            index++;
        }
        func_00213be0(*(s32 *)(D_0076449C + 0xDD4));
        func_00218560(*(u8 **)(D_0076449C + 0xDD4), selected);
        if (hasOther) {
            func_00218730(*(s32 *)(D_0076449C + 0xDD4));
        }
        func_001a03b0((s64 *)action);
        {
            u8 *cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)selected, 1);
            *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
            func_00194590(cameraPacket, 0);
        }
        func_001f62b0();
        func_001f86d0();
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
            func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
        }
        *(s32 *)(action + 0x41C) = 2;
        break;
    }
    case 2: {
        if (func_00218690(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            u8 *unit = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
            if (unit != NULL) {
                s32 resource = func_001f62f0(unit);
                if (resource >= 0) {
                    func_001f9a50((u16)resource, 1);
                }
            }
            *(s32 *)(action + 0x41C) = 3;
        }
        break;
    }
    case 3: {
        u16 input = D_008C024C[1];
        if ((input & 8) || (input & 4)) {
            u8 *selected = *(u8 **)(action + 0x38);
            u16 previous = *(u16 *)(action + 0xD2);
            s32 selectedIndex;
            s16 cursor = (s16)previous;
            if (input & 8) {
                s32 count = *(u16 *)(action + 0xD0);
                while ((selectedIndex = (s16)cursor) < count) {
                    u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                    if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                        *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                        break;
                    }
                    cursor++;
                }
                if (count == selectedIndex) {
                    cursor = 0;
                    while ((selectedIndex = (s16)cursor) < (u16)previous) {
                        u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                        if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                            *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                            break;
                        }
                        cursor++;
                    }
                }
            } else {
                while ((selectedIndex = (s16)cursor) >= 0) {
                    u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                    if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                        *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                        break;
                    }
                    cursor--;
                }
                if (selectedIndex < 0) {
                    cursor = *(u16 *)(action + 0xD0) - 1;
                    while ((selectedIndex = (s16)cursor) > (u16)previous) {
                        u8 *candidate = *(u8 **)(action + selectedIndex * 4 + 0x98);
                        if (*(u16 *)(*(u8 **)(candidate + 0x30) + 0xA4) !=
                            *(u16 *)(*(u8 **)(selected + 0x30) + 0xA4)) {
                            break;
                        }
                        cursor--;
                    }
                }
            }
            if ((u16)previous != selectedIndex) {
                func_0045af60(0, 0, 0, 5);
                *(u8 **)(action + 0x38) = *(u8 **)((u8 *)func_001a_add_offset(selectedIndex * 4, (s32)action) + 0x98);
                *(u16 *)(action + 0xD2) = cursor;
                func_002186c0(*(u8 **)(D_0076449C + 0xDD4), *(s32 *)(action + 0x38));
            }
        } else if ((input & 0x40) || (input & 0x20)) {
            func_0045af60(0, 0, 0, 4);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(action + 0x41C) = 4;
        }
        break;
    }
    case 4: {
        u8 *iter;
        u8 *packet;
        func_001f9a90();
        iter = *(u8 **)(D_0076449C + 0x174);
        while (iter != NULL) {
            if ((*(u16 *)(iter + 0x1A) & 1) && !(*(u16 *)(iter + 0x1A) & 0x400)) {
                if (action == iter) {
                    packet = func_0019bd00(*(u8 **)(iter + 0x30));
                } else {
                    packet = func_0019bbe0(*(u8 **)(iter + 0x30), (u32)-1, 0, 0, 3, 0);
                }
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                func_00194590(packet, 0);
            }
            iter = *(u8 **)(iter + 0x450);
        }
        func_00213bb0(*(s32 *)(D_0076449C + 0xDD4));
        func_00218700(*(s32 *)(D_0076449C + 0xDD4));
        btlActionSetState((BtlAction *)action, *(u16 *)(action + 0x14));
        *(s32 *)(action + 0x41C) = 0;
        break;
    }
    }
}
#pragma pop
// FUN_001A2AD0
void func_001a2ad0(u8 *arg0) {
    func_001eb3b0(arg0 + 0x38);
    if ((*(s32 *)(D_0076449C + 0xC) & 0x1000) == 0) {
        return;
    }
    if ((*(u16 *)(arg0 + 0x1A) & 1) == 0) {
        return;
    }
    if (*(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return;
    }
    btlActionSetState((BtlAction *)arg0, 9);
}

// FUN_001A2B50
void func_001a2b50(u8 *arg0)
{
    s32 temp_3;

    if (func_001deeb0(arg0 + 0x38) == 0) {
        func_001ded30(arg0, arg0 + 0x38);
    }
    if (func_001deee0(arg0 + 0x38) != 0) {
        temp_3 = *(s32 *)(D_0076449C + 0xC);
        if ((temp_3 & 0x1000) &&
            (temp_3 & 0x04000000) &&
            (*(u8 **)(arg0 + 0x30))[0xA2] == 1) {
            *(u16 *)(arg0 + 0x18) |= 0x4000;
        }
        *(u16 *)(arg0 + 0x18) |= 2;
        btlActionSetState((BtlAction *)arg0, 0xF);
    }
}
// FUN_001A2C10
void func_001a2c10(s64 *arg0) {
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001d7f10((u8 *)arg0, (u8 *)arg0 + 0x98, 0, 0);
    func_001d8cb0(NULL, arg0 + 0x13);
}



// FUN_001A2C70
void func_001a2c70(u8 *arg0)
{
    u8 *temp_3;

    *(s16 *)(arg0 + 0x6C) = 1;
    *(s16 *)(arg0 + 0x6E) =
        func_0023dfe0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    *(s32 *)(arg0 + 0x38) = func_001d8bc0(arg0 + 0x98);
    *(s16 *)(arg0 + 0x6A) = 1;
    func_001d8be0((s32)(arg0 + 0x98), *(u64 **)(arg0 + 0x38));
    temp_3 = *(u8 **)(arg0 + 0x30);
    if ((temp_3[0xA2] == 0) && (*(u16 *)(temp_3 + 0xA4) == 1)) {
        func_00194590(actionTargetPacketBytes(arg0, 1, 0, 0, 0), 1);
    }
    if (*(s32 *)(D_0076449C + 0xC) & 0x04000000) {
        *(u16 *)(arg0 + 0x18) |= 0x4000;
    }
    *(u16 *)(arg0 + 0x18) |= 2;
    btlActionSetState((BtlAction *)arg0, 0xF);
}
// FUN_001A2D60
void func_001a2d60(void)
{
}
/* MATCHED: 1072 bytes of code and the 64-byte table at 0x00746FD0 resolve
   exactly.  This is D_005f6e20[10].update, a void action callback, so the
   packet UID that func_00194590 returns is discarded here.  The u8
   conversion plus the explicit signed guard reproduce retail's redundant
   `bltz` range check - the two words an earlier pass could not place -
   and opt_propagation off with opt_common_subs off keep that lowering
   together with the repeated `*(u8 **)(unit + 0xA64)` loads that retail
   reloads rather than folding. */
// FUN_001A2D70
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_001a2d70(u8 *arg0) {
    extern void btlActionSetState(u8 *, u16);
    extern u8 *btlCameraCreateSetStatePacket(u8 *, u16);

    s32 state;
    s32 kind;
    u8 *unit;
    u8 *packet;

    void func_00233880(u8 *arg0, s32 arg1);


    if (func_00193cd0(0x506) == 0) {
        unit = *(u8 **)((u8 *)arg0 + 0x30);
        kind = (u8)func_00235320(*(u8 **)(unit + 0xA64));
        if (kind < 0) {
            goto fallback;
        }
        switch (kind) {
        case 0:
        case 1:
            if (unit[0xA2] == 0) {
                state = 30;
            } else {
                state = 31;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 0);
            func_00233880(*(u8 **)(unit + 0xA64), 1);
            break;
        case 2:
        case 4:
            if (unit[0xA2] == 0) {
                state = 32;
            } else {
                state = 33;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 4);
            func_00233880(*(u8 **)(unit + 0xA64), 2);
            break;
        case 3:
            if (unit[0xA2] == 0) {
                state = 34;
            } else {
                state = 35;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 3);
            break;
        case 5:
            if (unit[0xA2] == 0) {
                state = 36;
            } else {
                state = 37;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 5);
            break;
        case 6:
            if (unit[0xA2] == 0) {
                state = 38;
            } else {
                state = 39;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 6);
            break;
        case 7:
            if (unit[0xA2] == 0) {
                state = 40;
            } else {
                state = 41;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 7);
            break;
        case 8:
            if (unit[0xA2] == 0) {
                state = 80;
            } else {
                state = 81;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 8);
            break;
        case 9:
            if (unit[0xA2] == 0) {
                state = 82;
            } else {
                state = 83;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 9);
            break;
        case 10:
            if (unit[0xA2] == 0) {
                state = 84;
            } else {
                state = 85;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 10);
            break;
        case 11:
            if (unit[0xA2] == 0) {
                state = 86;
            } else {
                state = 87;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 11);
            break;
        case 12:
            if (unit[0xA2] == 0) {
                state = 130;
            } else {
                state = 131;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 12);
            break;
        case 13:
            if (unit[0xA2] == 0) {
                state = 132;
            } else {
                state = 133;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 13);
            break;
        case 14:
            if (unit[0xA2] == 0) {
                state = 134;
            } else {
                state = 135;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 14);
            break;
        case 15:
            if (unit[0xA2] == 0) {
                state = 136;
            } else {
                state = 137;
            }
            func_00233880(*(u8 **)(unit + 0xA64), 15);
            break;
        default:
            state = 0;
            break;
        }
        if (state != 0) {
            func_001a03b0((s64 *)arg0);
            packet = btlCameraCreateSetStatePacket((u8 *)arg0, 10);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 0);
            packet = actionMessagePacketBytes(*(s32 *)((u8 *)arg0 + 0x30), (s32)state);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            func_00194590(packet, 3);
        } else {
fallback:
            if (func_001f6770((u8 *)arg0) != 0) {
                btlActionSetState((u8 *)arg0, 11);
            } else {
                btlActionSetState((u8 *)arg0, 3);
            }
        }
    }
}
#pragma pop
// FUN_001A31A0
void func_001a31a0(u8 *arg0)
{
    func_001f6cd0();
    *(s32 *)(arg0 + 0x41C) = 1;
    *(s32 *)(arg0 + 0x420) = 0;
}
#pragma push
/* Recover an incapacitated action or select its next state. The unit status
 * remains a 32-bit word through the low20 selector. Camera and animation
 * packets remain alive until their published UIDs have been consumed. */
// FUN_001A31E0
void func_001a31e0(BtlAction *actionState)
{
    u8 *action = (u8 *)actionState;
    u32 badStatus;
    s32 allowRecovery;
    s32 resultFlags;
    u8 *cameraPacket;
    u8 *animationPacket;
    u16 animationDelay;
    u16 animationDuration;
    f32 animationSpeed;
    f32 rotation[3];
    struct { s32 words[8]; } result;

    if (func_00193cd0(0x506) == 0 && func_00193cd0(0x105) == 0) {
        func_001a03b0((s64 *)action);
        badStatus = datCalcGetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64));
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x100000) != 0 &&
            *(s32 *)(action + 0x420) == 0) {
            allowRecovery = 1;
            if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 1) != 0 &&
                func_001f6bf0(action) == 0) {
                allowRecovery = 0;
            }
            if (allowRecovery != 0) {
                cameraPacket = (u8 *)btlCameraCreateSetStatePacket(actionState, 0x31);
                *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
                func_00194590(cameraPacket, 0);
                if (*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) {
                    u8 *packet;
                    func_00194ff0(*(u8 **)(action + 0x30), NULL, NULL, rotation);
                    packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(action + 0x30),
                                                            (const RwV3d *)rotation, 2);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 0);
                }
                {
                    u32 flags = *(u32 *)(iGpffffb3ac + 0xC);
                    if ((flags & 0x1000) && (flags & 0x04000000)) {
                        animationSpeed = 1.75f;
                        animationDelay = 12;
                        animationDuration = 4;
                    } else {
                        animationSpeed = 1.0f;
                        animationDelay = 30;
                        animationDuration = 8;
                    }
                }
                animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                                               11, 0, animationSpeed, 0);
                animationPacket[0] = 4;
                *(s64 *)(animationPacket + 8) = *(s64 *)(cameraPacket + 0x58);
                *(u16 *)(animationPacket + 0x48) = animationDelay;
                *(s64 *)(animationPacket + 0x60) = *(s64 *)action;
                func_00194590(animationPacket, 0);
                {
                    u8 *packet = (u8 *)btlVoiceCreatePacket(actionState, 3, 0, 0, 0);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    func_00194590(packet, 1);
                }
                func_001f0a10((u8 *)&result);
                result.words[3] = 0x100001;
                {
                    u8 *packet = (u8 *)func_001f36e0((s32)action, (s32)action, &result, 1, 1);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 1);
                }
                {
                    u8 *packet = (u8 *)func_0019a980(*(BtlUnit **)(action + 0x30));
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(u16 *)(packet + 0x4A) = animationDuration;
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 0);
                }
                {
                    u8 *packet = (u8 *)func_001f5f70((u32)action, 0x11, 0, 0, 0);
                    packet[0] = 4;
                    *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 1);
                }
                *(s32 *)(action + 0x41C) = 1;
            } else {
                {
                    u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 0);
                }
                {
                    u8 *packet = (u8 *)func_001f5f70((u32)action, 0x12, 0, 0, 0);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 1);
                }
                {
                    u8 *unit = *(u8 **)(action + 0x30);
                    u8 *packet;
                    s32 message;
                    if (unit[0xA2] == 0) {
                        message = 0x68;
                    } else {
                        message = 0x69;
                    }
                    packet = (u8 *)func_00202400((s32)unit, message);
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 3);
                }
                *(s32 *)(action + 0x41C) = 0;
            }
            func_00194590((u8 *)btlUnitCreateLookAtUnitPacket(NULL, *(BtlUnit **)(action + 0x30), 1), 1);
            func_00194590((u8 *)btlUnitCreateLookAtDeactivatePacket(*(BtlUnit **)(action + 0x30), 0), 1);
            *(u16 *)(action + 0x18) |= 0x200;
            *(s32 *)(action + 0x420) = 1;
            return;
        }
        resultFlags = func_001f6930(action);
        if (resultFlags != 0) {
            s32 message;
            {
                u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                func_00194590(packet, 0);
            }
            func_001f0a10((u8 *)&result);
            result.words[3] = resultFlags;
            {
                u8 *packet = (u8 *)func_001f36e0((s32)action, (s32)action, &result, 1, 1);
                *(u16 *)(packet + 0x48) = 0x12;
                func_00194590(packet, 1);
            }
            message = func_001f7140(action);
            if (message > 0) {
                u8 *packet = (u8 *)func_00202400(*(s32 *)(action + 0x30), message);
                *(s64 *)(packet + 0x60) = *(s64 *)action;
                func_00194590(packet, 3);
            }
            return;
        }
        if (*(s32 *)(action + 0x41C) != 0) {
            if (badStatus & 0x116) {
                s32 message;
                func_001eb4a0(action, action + 0x38, badStatus);
                *(u16 *)(action + 0x18) |= 2;
                message = func_001f6f60(action);
                if (message > 0) {
                    {
                        u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        func_00194590(packet, 0);
                    }
                    {
                        u8 *packet = (u8 *)func_00202400(*(s32 *)(action + 0x30), message);
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        func_00194590(packet, 3);
                    }
                }
                {
                    u8 *packet = (u8 *)func_001f5f70((u32)action, 0x1E, 0, 0, 0);
                    *(u16 *)(packet + 0x48) = 0x18;
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 1);
                }
                btlActionSetState(actionState, 15);
                return;
            }
            btlActionSetStateWithDelay(actionState, 3, 1);
            return;
        }
        func_001eb3b0(action + 0x38);
        *(u16 *)(action + 0x18) &= 0xFFF7;
        if (func_001f68e0(action) != 0) {
            btlActionSetState(actionState, 27);
            return;
        }
        btlActionSetState(actionState, 32);
    }
}

#pragma pop
#pragma push
/* The loader and cleanup visit all 0x30 resource slots at +0xD04. */
typedef struct ActionRecoveryResourceView {
    u8 beforeResources[0xD04];
    u32 resources[0x30];
} ActionRecoveryResourceView;

static inline u32 actionRecoveryResourceAt(
    const ActionRecoveryResourceView *snappedBase, s32 signedSlot)
{
    return snappedBase->resources[signedSlot];
}

/* The mode is established by the action selector before entering this state.
   Movement and target-animation packets are separate dependency owners. */
// FUN_001A3840
void func_001a3840(register BtlAction *actionState)
{
    u8 *action;
    u8 *movementPacket;
    u8 *animationPacket;
    u8 *target;
    s16 mode;
    s32 resultFlags;
    f32 distance;
    struct { s16 slot; } selectedEffect;
    u16 targetFrame;
    u16 targetAnimation;
    u16 sourceAnimation;
    u16 beforeVoice;
    u16 afterVoice;
    u16 formationMode;
    u16 displayMode;
    struct {
        s32 values[8];
    } result;
    s32 delayedFrame;

    action = (u8 *)actionState;
    target = *(u8 **)(action + 0x444);
    mode = *(s16 *)(action + 0x448);
    switch (mode) {
    case 1:
        resultFlags = 0x100001;
        sourceAnimation = 27;
        targetAnimation = 28;
        targetFrame = 0;
        {
            u8 *targetUnit = *(u8 **)(target + 0x30);
            u8 *sourceUnit = *(u8 **)(action + 0x30);
            f32 sourceRadius = *(f32 *)(sourceUnit + 0x90);
            f32 sourceScale = *(f32 *)(sourceUnit + 0x2C);
            f32 targetRadius = *(f32 *)(targetUnit + 0x90);
            f32 targetScale = *(f32 *)(targetUnit + 0x2C);
            distance = 50.0f + (sourceRadius * sourceScale + targetRadius * targetScale);
        }
        selectedEffect.slot = -1;
        displayMode = 14;
        formationMode = 1;
        beforeVoice = 0;
        afterVoice = 12;
        *(u16 *)(action + 0x1A) |= 0x800;
        break;
    case 0:
        resultFlags = 30;
        sourceAnimation = 29;
        targetAnimation = 2;
        targetFrame = (u16)func_001991c0(*(u8 **)(action + 0x30), 29, 1.0f);
        distance = 50.0f + func_00196bd0(*(u8 **)(action + 0x30),
                                        *(u8 **)(target + 0x30), 29);
        displayMode = 15;
        selectedEffect.slot = 40;
        formationMode = 0;
        beforeVoice = 10;
        afterVoice = 11;
        *(u16 *)(action + 0x1A) |= 0x1000;
        break;
    }
    func_001a03b0((s64 *)action);
    func_001eb410(action + 0x38);
    *(u8 **)(action + 0x38) = target;
    *(s16 *)(action + 0x6A) = 1;
    if ((u16)beforeVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, beforeVoice,
                             *(u16 *)(*(u8 **)(target + 0x30) + 0xA4), 0, 0);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            func_00194590(packet, 1);
        }
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        {
            u8 *packet;
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 25);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            func_00194590(packet, 0);
        }
        movementPacket = (u8 *)btlUnitCreateMoveToUnitPacket(*(BtlUnit **)(action + 0x30),
                        *(BtlUnit **)(target + 0x30), distance, fGpffff811c, 10);
        *(s64 *)(movementPacket + 0x60) = *(s64 *)action;
        func_00194590(movementPacket, 0);
    } else {
        movementPacket = func_00194b60();
        *(s64 *)(movementPacket + 0x60) = *(s64 *)action;
        func_00194590(movementPacket, 0);
    }
    {
        u8 *packet;
        packet = func_002022e0(*(u32 *)(action + 0x30), displayMode);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        func_00194590(packet, 3);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001d3530(*(u32 *)(action + 0x30), *(u32 *)(target + 0x30), formationMode);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        func_00194590(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 42);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        func_00194590(packet, 0);
    }
    if ((u16)afterVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, afterVoice,
                             *(u16 *)(*(u8 **)(target + 0x30) + 0xA4), 0, 0);
            packet[0] = 4;
            *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            func_00194590(packet, 1);
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                             (s16)sourceAnimation, 0, 1.0f, 0);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        *(s16 *)(packet + 0x4A) = func_00199500(*(u8 **)(action + 0x30), sourceAnimation, 1.0f);
        func_00194590(packet, 0);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(target + 0x30),
                                                  (s16)targetAnimation, 0, 1.0f, 0);
    animationPacket[0] = 4;
    *(s64 *)(animationPacket + 8) = *(s64 *)(movementPacket + 0x58);
    *(s64 *)(animationPacket + 0x60) = *(s64 *)action;
    delayedFrame = (s16)targetFrame;
    *(s16 *)(animationPacket + 0x48) = targetFrame;
    func_00194590(animationPacket, 0);
    if (selectedEffect.slot != -1) {
        {
            u8 *packet;
            const ActionRecoveryResourceView *resourceBase;
            resourceBase = (const ActionRecoveryResourceView *)iGpffffb3ac;
            packet = (u8 *)func_001d6240(actionRecoveryResourceAt(resourceBase, selectedEffect.slot),
                                        *(u32 *)(action + 0x30), *(u32 *)(target + 0x30), 1, 0);
            packet[0] = 4;
            *(s64 *)(packet + 8) = *(s64 *)(movementPacket + 0x58);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            *(s16 *)(packet + 0x48) = delayedFrame;
            func_00194590(packet, 2);
        }
    }
    func_001f0a10((u8 *)&result);
    result.values[3] = resultFlags;
    {
        u8 *packet;
        packet = (u8 *)func_001f36e0((s32)target, (s32)target, &result, 1, 1);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s16 *)(packet + 0x48) = delayedFrame;
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        func_00194590(packet, 1);
    }
}

#pragma pop
// FUN_001A3D50
void func_001a3d50(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        *(s16 *)((u8 *)arg0 + 0x448) = -1;
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        btlActionSetState((BtlAction *)arg0, 0x20);
    }
}
// FUN_001A3DE0
s32 func_001a3de0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x420);
}

// FUN_001A3DF0
void func_001a3df0(u8 *arg0)
{
    s32 status;
    u8 *iter;
    u8 *temp;
    s64 *current;

    iter = *(u8 **)(D_0076449C + 0x174);
    goto loop_test;
loop_body:
    if (func_001a05f0(iter) != 0) {
        temp = (u8 *)func_0019b6a0(*(BtlUnit **)(*(u8 **)(iter + 0x30) + 0xA0C));
        *(s64 *)(temp + 0x60) = *(s64 *)iter;
        func_00194590(temp, 1);
    }
    iter = *(u8 **)(iter + 0x450);
loop_test:
    if (iter != NULL) {
        goto loop_body;
    }
    status = 1;
    current = func_001b1540();
    if ((*(u16 *)((u8 *)current + 0x18) & 8) != 0 &&
        func_0019ff60((u8 *)current) != 0) {
        status = 0;
    }
    if (status == 1) {
        status = func_001d94d0(
            arg0,
            func_0023d8e0(
                *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64),
                func_001f01a0(arg0, *(u8 **)(arg0 + 0x90)) & 0xFFFF) & 0xFFFF,
            2, 0x80000, 2, func_001db5e0);
    }
    if (status == 0) {
        temp = func_001fa9c0();
        *(s64 *)(temp + 0x60) = *(s64 *)arg0;
        func_00194590(temp, 1);
        btlActionSetState((BtlAction *)arg0, 0x20);
        return;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
    *(s32 *)(arg0 + 0x420) = 0;
}
// FUN_001A3F90
void func_001a3f90(u8 *arg0)
{
    u8 frame[0x10];
    struct {
        u8 pad[0x30];
        s32 field_30;
    } *temp_2;
    s64 *temp_2_4;
    u16 temp_3_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_3;

    if (*(s32 *)(arg0 + 0x41C) == 0) {
        if ((func_00193cd0(0xC00) == 0) && (func_00193cd0(0xC04) == 0)) {
            *(s16 *)(frame + 0) = 2;
            *(u16 *)(frame + 2) =
                *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
            func_00194590(func_001fa110(frame), 1);
            func_001a03b0((s64 *)arg0);
            func_00194590(func_00202850(), 1);
            func_00194590(func_001fa8f0(), 1);
            func_002182c0(*(u8 **)(D_0076449C + 0xDD4), (u8 *)arg0);
            func_00194590((u8 *)func_001d3700(3, 0xFFF), 0);
            temp_2 = (void *)func_001b1540();
            func_00194590(
                btlUnitCreateRotateTowardUnitPacket((u8 *)temp_2->field_30,
                              *(u8 **)(arg0 + 0x30), 2),
                0);
            func_00194590(
                btlUnitCreateRotateTowardUnitPacket(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 2),
                0);
            func_00194590(
                (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)temp_2->field_30, 0),
                1);
            func_00194590(
                actionLookAtUnit(*(u8 **)(arg0 + 0x30),
                              (u8 *)temp_2->field_30, 0),
                1);
            func_00194590((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x30), 0);
            temp_2_2 = func_00194c90((s32)func_001a3de0, (s32)arg0);
            func_00194590(temp_2_2, 1);
            func_00194590(
                func_001d65d0(*(s32 *)(D_0076449C + 0xD90),
                              *(s32 *)(arg0 + 0x30), 0,
                              *(s64 *)(temp_2_2 + 0x58), 0xC000),
                2);
            if (func_001eb860() == 1) {
                *(s32 *)(D_0076449C + 0xC) |= 0x2000;
                func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
            }
            *(s32 *)(arg0 + 0x41C) = 1;
        }
    } else if (*(s32 *)(arg0 + 0x420) == 0) {
        if (func_00218360(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
                func_00194590(func_001f99c0((u8 *)arg0, 8, 0, 0, 0), 1);
                temp_2_3 = func_001fa450();
                *(s8 *)(temp_2_3 + 0) = 0xA;
                *(s16 *)(temp_2_3 + 8) = 0xC00;
                *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_3, 1);
                func_00194590(func_002027e0(), 1);
            }
            func_00194590(func_001faa60(), 1);
            *(s32 *)(arg0 + 0x420) = 1;
            *(u16 *)(arg0 + 0x424) = 6;
        }
    } else {
        temp_3_2 = *(u16 *)(arg0 + 0x424);
        if (temp_3_2 == 0) {
            func_00194590((u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3), 1);
            if (func_00218390(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
                temp_2_4 = func_001b1540();
                func_00194590(func_001f3870((u8 *)temp_2_4, 2), 1);
                *(u16 *)((u8 *)temp_2_4 + 0x18) |= 0x8000;
                btlActionSetState((BtlAction *)arg0, 0xE);
            } else {
                btlActionSetState((BtlAction *)arg0, 0x20);
            }
            func_002183c0(*(s32 *)(D_0076449C + 0xDD4));
            return;
        }
        *(u16 *)(arg0 + 0x424) = temp_3_2 - 1;
    }
}
// FUN_001A4390
void func_001a4390(void)
{
}

/* Recovered action selection. Configured b210 -O2 emits 1092 retail bytes
 * plus 12 zero alignment bytes. The workspace keeps the signed element in
 * actual halfword storage and both twelve-entry target lists at their observed
 * 16-byte alignment. Scalarization is disabled for this storage; propagation
 * is disabled to preserve the unit load before the element's signed-word
 * promotion. The affinity provider retains its canonical s32 input. */
#pragma push
/* Keep the promoted shuffle count and output base at their explicit
 * phase boundaries. The index reference preserves each narrow read. */
#pragma opt_loop_invariants off
static inline u8 *actionReadCandidate(u8 *action, const u16 *index)
{
    return *(u8 **)(action + 0x98 + *index * 4);
}

/* Select eligible targets, preserving the reference action when required,
 * then queue voice, cut-in and dependent formation packets. Both local
 * target lists hold twelve entries; single-target selection requires
 * a nonempty eligible set. */
#pragma opt_scalarize off
#pragma opt_propagation off
// FUN_001A43A0
void func_001a43a0(u8 *action)
{
    extern s8 func_00233a90(u8 *action, s32 arg1);
    extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 kind, s32 id, s32 flags, s32 mode);
    struct {
        s16 element;
        u8 *preferred[12] __attribute__((aligned(16)));
        u8 *other[12] __attribute__((aligned(16)));
    } targets;
    u8 *candidate;
    u8 *referenceAction;
    u16 scanIndex;
    u16 otherCount;
    u16 preferredCount;
    u8 *workspace;
    u16 skill;
    s32 hasReferenceAction;
    u16 targetMode;
    s32 rawElement;
    u8 *task;

    if (func_00193cd0(0xC00) != 0) {
        return;
    }
    referenceAction = *(u8 **)(action + 0x90);
    skill = func_001f01a0(action, referenceAction);
    targetMode = func_001d7f10(action, action + 0x98, skill, 0);
    rawElement = func_0023d8e0(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), skill);
    hasReferenceAction = 0;
    otherCount = 0;
    preferredCount = 0;
    scanIndex = 0;
    targets.element = (s16)rawElement;
    for (; scanIndex < *(u16 *)(action + 0xD0); scanIndex++) {
        candidate = actionReadCandidate(action, &scanIndex);
        if (!(*(u16 *)(candidate + 0x1A) & 1)) {
            continue;
        }
        workspace = *(u8 **)(candidate + 0x30);
        if (datCalcIsDead(*(s32 *)(workspace + 0xA64), 0) != 0) {
            continue;
        }
        if (func_00233a90(*(u8 **)(workspace + 0xA64), 0x10) > 0) {
            continue;
        }
        {
            u8 *affinityUnit = *(u8 **)(workspace + 0xA64);
            s32 affinityElement = targets.element;

            if (func_00242800(affinityUnit, affinityElement) & 0x7000000) {
                continue;
            }
        }
        if (datCalcChkBadStatus(*(s32 *)(workspace + 0xA64), 0x100000) == 0) {
            targets.preferred[preferredCount++] = candidate;
        }
        if (referenceAction != candidate) {
            targets.other[otherCount++] = candidate;
        } else {
            hasReferenceAction = 1;
        }
    }
    func_001eb3b0(action + 0x38);
    *(s16 *)(action + 0x6C) = 2;
    *(u16 *)(action + 0x6E) = skill;
    if (targetMode == 0) {
        if (preferredCount > 0) {
            *(u8 **)(action + 0x38) = targets.preferred[func_00231d70(preferredCount)];
        } else if (hasReferenceAction) {
            *(u8 **)(action + 0x38) = referenceAction;
        } else {
            *(u8 **)(action + 0x38) = targets.other[func_00231d70(otherCount)];
        }
        *(u16 *)(action + 0x6A) = 1;
    } else {
        s32 availableCount;
        s32 shuffleLimit;
        u16 outputStart;
        u16 shuffleIndex;

        shuffleIndex = 0;
        availableCount = otherCount;
        shuffleLimit = availableCount * 3;
        for (; shuffleIndex < shuffleLimit; shuffleIndex++) {
            u16 firstIndex = func_00231d70(availableCount);
            u16 secondIndex = func_00231d70(availableCount);

            if (firstIndex != secondIndex) {
                u8 *savedTarget = targets.other[firstIndex];

                targets.other[firstIndex] = targets.other[secondIndex];
                targets.other[secondIndex] = savedTarget;
            }
        }
        if (hasReferenceAction) {
            *(u8 **)(action + 0x38) = referenceAction;
            *(u16 *)(action + 0x6A) = 1;
            outputStart = 1;
        } else {
            *(u16 *)(action + 0x6A) = 0;
            outputStart = 0;
        }
        if (availableCount > 1) {
            if (availableCount == 2) {
                otherCount = 1;
            } else {
                otherCount = func_00231d70(availableCount - 1) + 1;
            }
        }
        {
            u16 copyIndex;
            u8 *outputBase;
            s32 appendCount;

            copyIndex = 0;
            outputBase = action + outputStart * 4;
            appendCount = otherCount;
            for (; copyIndex < appendCount; copyIndex++) {
                *(u8 **)(outputBase + copyIndex * 4 + 0x38) = targets.other[copyIndex];
            }
        }
        *(u16 *)(action + 0x6A) += otherCount;
    }
    *(u16 *)(action + 0x18) |= 2;
    task = (u8 *)btlVoiceCreatePacket((BtlAction *)action, 9, 0, 0, 0);
    *(u64 *)(task + 0x60) = *(u64 *)action;
    func_00194590(task, 1);
    workspace = func_001fa320();
    *(u64 *)(workspace + 0x60) = *(u64 *)action;
    func_00194590(workspace, 1);
    task = func_002027e0();
    task[0] = 4;
    *(u64 *)(task + 8) = *(u64 *)(workspace + 0x58);
    func_00194590(task, 1);
    btlActionSetState((BtlAction *)action, 0xF);
}
#pragma pop
// FUN_001A47F0
void func_001a47f0(void)
{
}

/* The two fields belong to the same battle-state allocation. Keeping their
 * shared view preserves the single state-pointer load used by retail. */
typedef struct ActionState001a4800 {
    u8 pad0[0x1A];
    u16 kind;
    u8 pad1C[0x290 - 0x1C];
    u16 flags;
} ActionState001a4800;

#pragma push
/* measured: b210 -O2 with this scoped setting emits 1148/1152 exact bytes.
 * The ushort counter wrap and offset-first helper preserve retail's operation
 * order. All 39 code relocations and the 52-byte switch table were resolved. */
#pragma opt_common_subs off
// FUN_001A4800
/* Wait for the participating actions before dispatching the selected action
 * type and submitting its target-state and camera packets. */
void func_001a4800(u8 *arg0)
{
    extern void func_001eb420(u8 *target);
    extern u16 *func_0010a900(u16 personaId);
    extern s32 func_0010ce10(u8 *persona, u16 skillId);
    extern s32 func_0019fc70(u8 *action);
    extern void func_001f5bd0(s32 state);
    extern s32 func_001f68e0(u8 *action);
    extern void func_0022dc70(u8 *action);
    s32 temp_16;
    s32 var_16;
    s32 var_18;
    s32 var_2;
    u16 temp_2;
    u8 *temp_17;
    ActionState001a4800 *temp_4;
    if (((s32)(func_00193cd0(0x506)) == (s32)(0)) && ((s32)(func_00193cd0(0xC05)) == (s32)(0))) {
        var_18 = 0;
        while ((s32)(temp_16 = var_18 & 0xFFFF) < (s32)(*(u16 *)((u8 *)arg0 + 0x6A))) {
            temp_17 = (u8 *)((*(u8 **)((u8 *)(((s32)(arg0) + ((var_18 & 0xFFFF) * 4))) + 0x38)));
            if ((s32)(arg0) == (s32)(temp_17)) {
                goto incr;
            }
            if (!((*(u16 *)((u8 *)(temp_17) + 0x1A)) & 1)) {
                goto incr;
            }
            if (((s32)(datCalcIsDead((*(s32 *)((u8 *)((*(s32 *)((u8 *)(temp_17) + 0x30))) + 0xA64)), 0)) != (s32)(0))) {
                goto incr;
            }
            if ((*(u16 *)((u8 *)(temp_17) + 0xC)) != 1) {
                goto donecheck;
            }
incr:
            var_18 = (var_18 + 1) & 0xFFFF;
        }
donecheck:
        if (temp_16 == (*( u16*)((u8 *)(arg0) + 0x6A))) {
            if (!((*( u16*)((u8 *)(arg0) + 0x18)) & 4)) {
                func_001eb420(arg0 + 0x38);
            }
            (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFFD));
            var_16 = 0;
            temp_2 = (u16)((u16)((*( u16*)((u8 *)(arg0) + 0x6C))));
            switch (temp_2) {
            case 1:
            case 2:
            case 3:
                var_16 = 1;
                /* fallthrough */
            case 9:
                func_001f14f0(arg0);
                if ((*( u8*)((u8 *)(func_001a_add_offset(*(u16 *)(arg0 + 0x6E) * 0x28, (s32)iGpffffb3b8)) + 0x24)) == 5) {
                    btlActionSetState((BtlAction *)arg0, 0x20U);
                } else if ((*( s32*)((u8 *)(arg0) + 0xE8)) == 1) {
                    btlActionSetState((BtlAction *)arg0, 0x17U);
                } else if ((s32)(func_0019fc70(arg0)) != (s32)(0)) {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFEF));
                    btlActionSetState((BtlAction *)arg0, 0x10U);
                } else {
                    (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 0x10));
                    btlActionSetState((BtlAction *)arg0, 0x11U);
                }
                break;
            case 7:
            case 8:
            case 11:
                btlActionSetState((BtlAction *)arg0, 0x19U);
                break;
            case 6:
                if ((s32)((*( u8*)((*( u8**)((u8 *)(arg0) + 0x30)) + 0xA2))) == (s32)(0)) {
                    if ((s32)(datGetFlag(0x38)) != (s32)(0)) {
                        var_2 = 5;
                    } else {
                        var_2 = 8;
                    }
                    if (((s32)(func_0010ce10((u8 *)func_0010a900(var_2 & 0xFFFF), 0x114)) != (s32)(-1)) || ((temp_4 = (ActionState001a4800 *)iGpffffb3ac)->kind == 1 && (temp_4->flags & 2))) {
                        func_00194590(actionTargetPacketBytes(arg0, 8, 0, 0, 3), 1);
                        func_00194590((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 8), 0);
                        actionSetDelayBytes(arg0, 0x1D, 0xC);
                    } else {
                        func_001f5bd0(0);
                        func_00194590(actionTargetPacketBytes(arg0, 3, 0, 0, 2), 1);
                        func_00194590(func_001f3870(arg0, 0U), 1);
                        func_00194590((u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 1), 0);
                        if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
                            actionSetDelayBytes(arg0, 0x1B, 0xC);
                        } else {
                            actionSetDelayBytes(arg0, 0x20, 0xC);
                        }
                    }
                } else {
                    btlActionSetState((BtlAction *)arg0, 0x1DU);
                }
                break;
            case 12:
                btlActionSetState((BtlAction *)arg0, 0x1DU);
                break;
            case 5:
                btlActionSetState((BtlAction *)arg0, 0x1AU);
                break;
            case 10:
                btlActionSetState((BtlAction *)arg0, 7U);
                break;
            }
            if ((var_16 != 0) && ((s32)(func_001a0140(arg0)) != (s32)(0))) {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) | 8));
            } else {
                (*( u16*)((u8 *)(arg0) + 0x18)) = (u16)((u16) ((*( u16*)((u8 *)(arg0) + 0x18)) & 0xFFF7));
            }
            func_0022dc70(arg0);
        }
    }
}
#pragma pop
/* Measured 2026-09-30 with the coherent motion-provider family: 2336 bytes,
 * zero instruction differences. Both motion locals use the provider's u16
 * selector domain; no wide temporary or local ABI override is needed.
 * Scoped lifetime optimization and preserved assignments retain the range
 * predicate and speed-table control flow. Position and rotation providers
 * consume three and four floats respectively. Action actors are kind 0/1,
 * created by 0019f5f0; the selector's other retail cases remain intact. */
// FUN_001A4C80
#pragma push
#pragma opt_lifetimes on
#pragma opt_dead_assignments off
void func_001a4c80(u8 *actionBytes)
{
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void func_00195c50(BtlUnit *unit, BtlUnit *target, RwV3d *out);
    extern void func_001951f0(u8 *subunit, u8 *unit, u8 *target, s32 motion,
                            f32 *position, f32 *rotation, s32 placement);
    extern void func_001ec1c0(u8 *rotation, u8 *from, u8 *to);
    extern f32 RwV3dLength(const RwV3d *vector);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *vector);
    extern s32 func_00243d80(u8 *unitData);
    extern s32 func_001f0a50(u8 *actionBytes);
    extern s32 func_001f0bf0(u8 *actionBytes);
    extern s32 func_001f0ff0(u32 action);
    extern s32 func_0022fb10(void);
    extern u8 *iGpffffb3bc;
    extern f32 fGpffff8360;
    typedef struct UnitView {
        u8 unknown00[8];
        f32 y;
        u8 unknown0C[0x2C - 0x0C];
        f32 scale;
        u8 unknown30[0x90 - 0x30];
        f32 radius;
        u8 unknown94[0xA2 - 0x94];
        u8 kind;
        u8 unknownA3[0xA64 - 0xA3];
        u8 *data;
    } UnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x10];
        u16 flags;
        u8 unknown1A[0x16];
        UnitView *unit;
        u8 unknown34[4];
        struct ActionView *target;
        u8 unknown3C[0x30];
        u16 mode;
        u16 skill;
    } ActionView;
    union { RwV3d vector; f32 values[3]; } destination;
    RwV3d awayDirection;
    RwV3d homeOffset;
    RwV3d unitCenter;
    RwV3d targetCenter;
    f32 rotation[4];
    ActionView *action;
    UnitView *unit;
    UnitView *targetUnit;
    u16 skill;
    s32 skillOffset;
    u8 *subunit;
    s32 proceed;
    s32 reposition;
    s32 inRange;
    s32 canPosition;
    f32 distance;
    f32 speed;

    action = (ActionView *)actionBytes;
    skill = action->skill;
    skillOffset = skill * 4;
    if ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0) {
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x2000) != 0) {
        return;
    }
    proceed = 1;
    inRange = 0;
    reposition = 0;
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtUnitPacket(NULL, (BtlUnit *)action->unit, 3);
        *(s64 *)(packet + 0x60) = action->uid;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)action->unit, 0);
        *(s64 *)(packet + 0x60) = action->uid;
        func_00194590(packet, 1);
    }
    action->flags |= 0x200;
    if ((*(u8 *)(iGpffffb3b8 + skill * 0x28) & 2) != 0) {
        s32 pairedTargets;
        UnitView *predicateUnit;
        pairedTargets = func_001f0bf0((u8 *)action);
        predicateUnit = action->unit;
        do {
            switch (predicateUnit->kind) {
            case 0: {
                u8 *data;
                u16 unitId;
                s32 ranged;
                u32 rangeTable;
                u32 rangeOffset;
                data = predicateUnit->data;
                unitId = *(u16 *)(data + 2);
                ranged = 1;
                switch (predicateUnit->kind) {
                case 0:
                    {
                        s32 classification;
                        classification = func_0023e1f0(data) & 0xFF;
                        if (classification == 5) {
                            ranged = 1;
                        } else if (classification == 3 && ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0 || pairedTargets == 0)) {
                            ranged = 1;
                        } else {
                            goto range_ineligible;
                        }
                    }
                    break;
                case 1:
                    rangeTable = (u32)iGpffffb3cc;
                    rangeOffset = (u32)unitId * 0xE8;
                    if (*(s16 *)(rangeOffset + rangeTable + 0x22) == 1) {
                        ranged = 1;
                    } else {
                        goto range_ineligible;
                    }
                    break;
                default:
range_ineligible:
                    ranged = 0;
                    break;
                }
                if (ranged != 0) {
                    ActionView *rangeTarget;
                    rangeTarget = action->target;
                    unit = action->unit;
                    targetUnit = rangeTarget->unit;
                    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 && unit->kind != targetUnit->kind) {
                        proceed = 0;
                    } else {
                        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                        func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                        if (func_001ec250(&unitCenter, &targetCenter) < 500.0f) {
                            inRange = 1;
                            proceed = 0;
                        } else {
                            distance = 500.0f;
                        }
                    }
                    goto range_done;
                }
            }
            default:
                break;
            }
            {
                u16 motion;
                unit = action->unit;
                if (unit->kind == 0) {
                    if ((*(u16 *)((u32)skillOffset + (u32)iGpffffb3bc + 2) & 0x8000) != 0) {
                        motion = 7;
                    } else if (pairedTargets != 0) {
                        motion = 5;
                    } else {
                        motion = (u16)(func_001f0a50((u8 *)action) != 0 ? 0xC : 4);
                    }
                } else {
                    motion = (u16)(func_001f0a50((u8 *)action) != 0 ? 0xC : 4);
                }
                distance = func_00196bd0((u8 *)action->unit, (u8 *)action->target->unit, motion);
            }
range_done:
            ;
        } while (0);
        if ((action->flags & 0x4000) != 0) {
            reposition = 1;
        }
    } else {
        unit = action->unit;
        switch (unit->kind) {
        case 0:
            {
                s32 paired;
                s32 openingMotion;
                targetUnit = action->target->unit;
                subunit = *(u8 **)((u8 *)unit + 0xA0C);
                paired = func_001f0ff0((u32)action);
                openingMotion = func_00199d00((s32)subunit, (u8 *)unit, (s16)skill, paired) & 0xFFFF;
                canPosition = func_001f1210(subunit, (s16)skill, paired);
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                speed = func_001ec250(&unitCenter, &targetCenter);
                speed = speed - unit->radius * unit->scale;
                speed = speed - targetUnit->radius * targetUnit->scale;
                if (canPosition == 0 || func_0022fb10() == 0 || speed < 300.0f || speed - 300.0f < 200.0f) {
                    action->flags |= 0x10;
                    proceed = 0;
                } else {
                    speed = speed + unit->radius * unit->scale;
                    speed = speed + targetUnit->radius * targetUnit->scale;
                    func_001951f0(subunit, (u8 *)unit, (u8 *)targetUnit, (s16)openingMotion, destination.values, NULL, 2);
                    distance = func_001ec250(&destination.vector, &targetCenter);
                    {
                        f32 limit;
                        limit = 300.0f;
                        limit = limit + unit->radius * unit->scale;
                        limit = limit + targetUnit->radius * targetUnit->scale;
                        if (distance < limit) {
                            distance = limit;
                        }
                    }
                    func_001951f0(subunit, (u8 *)unit, NULL, -1, destination.values, NULL, 0);
                    homeOffset.x = destination.vector.x - unitCenter.x;
                    homeOffset.z = destination.vector.z - unitCenter.z;
                    homeOffset.y = 0.0f;
                    distance = distance + RwV3dLength(&homeOffset);
                    if (speed < distance) {
                        action->flags |= 0x10;
                        proceed = 0;
                    }
                }
            }
            break;
        case 1:
            {
                u16 motion;
                motion = (u16)(func_001f0a50((u8 *)action) != 0 ? 0xC : 4);
                distance = func_00196bd0((u8 *)action->unit, (u8 *)action->target->unit, motion);
            }
            break;
        }
    }
    if (proceed == 0) {
        return;
    }
    func_001a03b0((s64 *)action);
    {
        u16 speedIndex;
        u16 unitId;
        u16 speedVariant;
        u8 kind;
        u32 table;
        u32 offset;
        u32 record;
        u32 selector;
        u8 *packet;
        proceed = 0;
        speedIndex = 2;
        speedVariant = (u16)(!(*(u8 *)(iGpffffb3b8 + action->skill * 0x28) & 2));
        unit = action->unit;
        unitId = *(u16 *)(unit->data + 2);
        kind = unit->kind;
        switch (kind) {
        case 0:
            break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)unitId * 0xE8;
            record = offset + table;
            selector = (u16)speedVariant * 4;
            speedIndex = *(u16 *)(selector + record + 0x24);
            break;
        }
        speed = D_005F6D20[speedIndex];
        if (reposition == 1) {
            if (inRange == 0) {
                targetUnit = action->target->unit;
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                func_00195c50((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                awayDirection.x = unitCenter.x - targetCenter.x;
                awayDirection.z = unitCenter.z - targetCenter.z;
                awayDirection.y = 0.0f;
                RwV3dNormalize(&awayDirection, &awayDirection);
                {
                    f32 span;
                    span = unit->radius * unit->scale;
                    span = span + targetUnit->radius * targetUnit->scale;
                    span = span + distance;
                    span = span + 50.0f;
                    awayDirection.x = awayDirection.x * span;
                    awayDirection.y = awayDirection.y * span;
                    awayDirection.z = awayDirection.z * span;
                }
                destination.vector.x = targetCenter.x + awayDirection.x;
                destination.vector.y = targetCenter.y + awayDirection.y;
                destination.vector.z = targetCenter.z + awayDirection.z;
                destination.vector.y = unit->y;
                func_001ec1c0((u8 *)rotation, (u8 *)destination.values, (u8 *)&targetCenter);
                packet = func_00195730((u8 *)unit, (u8 *)destination.values, (u8 *)rotation, NULL);
                *(s64 *)(packet + 0x60) = action->uid;
                func_00194590(packet, 0);
                speed = speed * fGpffff8360;
                proceed = proceed | 8;
            } else {
                speed = speed * 1.25f;
            }
        }
        if (func_00243d80(action->target->unit->data) == 0) {
            proceed = proceed | 0x40;
        }
        packet = (u8 *)btlUnitCreateMoveToUnitPacket((BtlUnit *)action->unit, (BtlUnit *)action->target->unit, distance, speed, proceed);
        *(s64 *)(packet + 0x60) = action->uid;
        func_00194590(packet, 0);
        if (packet != NULL && inRange == 0) {
            if (reposition == 0) {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x16);
                *(s64 *)(packet + 0x60) = action->uid;
                func_00194590(packet, 0);
            } else {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x17);
                *(s64 *)(packet + 0x60) = action->uid;
                func_00194590(packet, 0);
            }
        }
        action->flags &= 0xFFEF;
    }
}

#pragma pop
// FUN_001A55A0
void func_001a55a0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((BtlAction *)arg0, var_5);
    }
}



/* Measured: 656/656 bytes and 15 resolved relocations match retail.
 * Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_001A5650
void func_001a5650(s64 *arg0)
{
    RwV3d sp30;
    u32 source_offset, sum, idx4;
    f32 speed, scale;
    u16 temp_7;
    u16 temp_3_3;
    u16 var_5;
    u16 var_5_2;
    u16 var_5_3;
    u16 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    temp_4 = D_0076449C;
    if ((*(s32 *)(temp_4 + 0xC) & 0x400000) &&
        (*(u16 *)(temp_4 + 0x18) & 2)) {
        temp_3 = *(u16 *)((u8 *)arg0 + 0x6C);
        switch (temp_3) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((BtlAction *)arg0, var_5);
        return;
    }
    func_00194ff0(temp_16, (u8 *)&sp30, NULL, NULL);
    if (!(func_001ec250((RwV3d *)(temp_16 + 4), &sp30) <= 75.0f)) {
        func_001a03b0(arg0);
        var_5_2 = 2;
        temp_7 = (!(iGpffffb3b8[
            (*(u16 *)((u8 *)arg0 + 0x6E) * 0x28)] & 2)) & 0xFFFF;
        temp_4_2 = *(u8 **)((u8 *)arg0 + 0x30);
        temp_3 = *(u16 *)(*(u8 **)(temp_4_2 + 0xA64) + 2);
        temp_3_2 = *(u8 *)(temp_4_2 + 0xA2);
        switch (temp_3_2) {
        case 0:
            break;
        case 1:
            temp_4 = iGpffffb3cc;
            source_offset = temp_3 * 0xE8;
            sum = source_offset + (u32)temp_4;
            idx4 = temp_7 * 4;
            var_5_2 = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        speed = D_005F6D20[var_5_2];
        scale = D_0076144C;
        temp_2 = (u8 *)btlUnitCreateMovePacket(
            (BtlUnit *)temp_4_2, &sp30,
            speed * scale, 0);
        *(s64 *)(temp_2 + 0x60) = *arg0;
        func_00194590(temp_2, 1);
        temp_2_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x18);
        *(s64 *)(temp_2_2 + 0x60) = *arg0;
        func_00194590(temp_2_2, 0);
        return;
    }
    temp_3_3 = *(u16 *)((u8 *)arg0 + 0x6C);
    switch (temp_3_3) {
    case 1:
        var_5_3 = 0x12;
        break;
    case 2:
    case 3:
        var_5_3 = 0x13;
        break;
    case 9:
        var_5_3 = 0x14;
        break;
    default:
        var_5_3 = 0;
        break;
    }
    btlActionSetState((BtlAction *)arg0, var_5_3);
}
#pragma pop

// FUN_001A58E0
void func_001a58e0(s64 *arg0) {
    u16 var_5;

    if (btlUnitIsMoving(*(u8 **)((u8 *)arg0 + 0x30)) == 0) {
        switch (*(u16 *)((u8 *)arg0 + 0x6C)) {
        case 1:
            var_5 = 0x12;
            break;
        case 2:
        case 3:
            var_5 = 0x13;
            break;
        case 9:
            var_5 = 0x14;
            break;
        default:
            var_5 = 0;
            break;
        }
        btlActionSetState((BtlAction *)arg0, var_5);
    }
}



// FUN_001A5990
void func_001a5990(void)
{
}

/* measured 001a59a0 2026-09-19: object 1929 against retail 1884 (+45, +2.39%, band 1828-1940, 11 instr headroom), 1715 differing words via probe_variants, 905 fnalign edits (+17 reloc-only) via fnalign --candidate, frame retail -0x330 vs object -0x410.
   From m2c transcription: v2 base 2032 (+148, +7.8%, 1830 words), v3 all-s32 narrowing plus byte-arithmetic fix 1953 (+69, +3.6%, 1714 words), v5 GP single-load fix (iGpffffb3ac/b3bc/(s32)b3cc) 1930 (+46, +2.44%, 1707 words), v6 float GP (fGpffff8128/8358, new symbols) 1929 (+45, +2.39%, 1715 words, final).
   Widths: s64 kept only for temp_16/temp_17 (64-bit ld/sd), all other s64/s128 narrowed to s32 (79 instr win v2->v3); GP mapping saves 23 instrs v3->v5; floats save 1 v5->v6. File idiom: s64 *arg0 (retail daddu), local externs with empty prototypes (like 001a7720), explicit field expansions, (u8 *)arg0 byte arithmetic. New data symbols fGpffff8128/8358 added for retail lwc1 sites. */
/* 2026-10-03: canonical motion/animation calls use a real f32 rate and
   signed-halfword results. Retail has six timing queries and four animation
   creations here; the unfinished controller remains ASM-backed. See
   docs/probe_archive/Large_Battle_animation_contracts_20261003.md. */
/* 2026-10-03 storage repair: preserve action/packet UIDs as doublewords
   and select true 0x20-byte hit records. The old narrowing measurements above
   are historical, not type evidence. See Large_Battle_storage_20261003.md.
   2026-10-08: opt_loop_invariants on lowers fnalign from 837 to 752 edits.
 * 2026-10-09: 752 -> 709: the m2c label loops are while loops.
 * 696: range tests in retail's slti $at form.
 * 666: type sweep.
 * 660: swap sweep.
 * 652: type sweep.
 * 651: type sweep.
 * 646: conversion lever (temp_18:(0, 2)).
 * 642: conversion lever (var_6:(0, 2)).
 * 2026-10-10: 642 -> 614 aligned edits by replacing seven undefined or
 * redundant sign-extension shifts with explicit signed-halfword/byte casts.
 * The local 001d15a0 provider returns s16; measured in battle lane scratch.
 * sdiff struct 413 -> 395: arg0 accessed through a u8 * local; the (u8 *)(s64 *) cast at every use made MWCC CSE and spill field addresses.
 */
// FUN_001A59A0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_001a59a0(s64 *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    extern s32 func_00194590();
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern u8 *func_00197cc0();
    extern u8 *btlUnitCreateRotateTowardUnitPacket();
    extern s32 func_001a03b0();
    extern s32 btlActionSetState();
    extern u8 *btlCameraCreateSetStatePacket();
    extern u8 *func_001bccc0();
    extern BtlPacket *func_001d1eb0(u32 source, u32 target, f32 distance, u16 mode);
    extern u8 *func_001d3530();
    extern u8 *func_001d6240();
    extern s32 func_001eb440();
    extern s32 func_001ef720();
    extern s32 func_001f08c0();
    extern void func_001f0a10(u8 *result);
    extern s32 func_001f0b90();
    extern s32 func_001f0dd0();
    extern s32 func_001f0f70();
    extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *func_001f3950();
    extern u8 *func_001f5f70();
    extern s32 func_001f68e0();
    extern s32 func_001f7830();
    extern s32 func_001f7910();
    extern u8 *func_001f7c20();
    extern u8 *func_001f99c0();
    extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *func_00202010();
    extern u8 *func_00202400();
    extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3bc;
    extern u8 *iGpffffb3cc;
    extern f32 fGpffff8128;
    extern f32 fGpffff8358;

    s16 sp32E;
    s16 sp32C;
    /* 001a0290 writes both signed halfword effect indices. */
    s16 effectIndices[2];
    /* The constructor copies ten bytes; mode 3 uses the first four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    u8 *sp2DC;
    u8 *sp2D8;
    u8 *sp2D4;
    s64 sp2C0;
    s32 sp2B0;
    s32 sp2A0;
    s32 sp290;
    s32 sp280;
    s32 sp270;
    u16 sp260;
    s16 sp25C;
    s32 sp258;
    s32 sp254;
    s32 sp250;
    s32 sp240;
    s32 sp230;
    s32 sp22C;
    s32 sp210;
    u32 sp200;
    LargeBattleHitResult *sp1F0;
    u16 sp1E0;
    u16 sp1D0;
    s32 sp1C0;
    s32 sp1B0;
    s32 sp1A0;
    s32 sp190;
    s32 sp180;
    s32 sp170;
    s32 sp160;
    s32 sp150;
    s32 sp140;
    s32 sp130;
    s32 sp120;
    LargeBattleHitResult *hit;
    u32 *addedStatus;
    s32 spF0;
    s32 spE0;
    s32 spD0;
    s32 spC0;
    f32 var_f20;
    s32 timingAdjustment;
    f32 var_f12;
    s32 temp_2;
    s16 temp_2_53;
    s16 temp_5_6;
    s16 temp_5_7;
    s32 var_21;
    s32 var_22_2;
    s32 var_2_3;
    s32 var_2_7;
    s32 var_3;
    LargeBattleHitResult *temp_2_48;
    s32 temp_2_5;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 var_10;
    s32 var_16;
    s32 var_22;
    u16 var_2_6;
    s32 var_2_8;
    s32 var_5;
    s32 var_5_2;
    s32 var_6;
    s64 *temp_18;
    s64 *var_22_3;
    s64 temp_16;
    s64 temp_17;
    s32 temp_2_17;
    u16 temp_2_26;
    s32 temp_2_4;
    s32 temp_3_4;
    s16 temp_4_4;
    s32 var_18;
    s32 var_23;
    s32 var_30;
    s8 temp_2_27;
    u16 temp_3_8;
    u16 temp_5;
    u32 temp_4_7;
    u8 temp_2_10;
    u8 temp_2_8;
    u8 var_2_4;
    u8 *temp_19;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_28;
    u8 *temp_2_29;
    u8 *temp_2_2;
    u8 *temp_2_30;
    u8 *temp_2_31;
    u8 *temp_2_32;
    u8 *temp_2_33;
    u8 *temp_2_34;
    u8 *temp_2_35;
    u8 *temp_2_36;
    u8 *temp_2_37;
    u8 *temp_2_38;
    u8 *temp_2_39;
    u8 *temp_2_3;
    u8 *temp_2_40;
    u8 *temp_2_41;
    u8 *temp_2_42;
    u8 *temp_2_43;
    u8 *temp_2_44;
    u8 *temp_2_45;
    u8 *temp_2_46;
    u8 *temp_2_47;
    u8 *temp_2_49;
    u8 *temp_2_50;
    u8 *temp_2_51;
    u8 *temp_2_52;
    u8 *temp_2_54;
    u8 *temp_2_55;
    u8 *temp_2_56;
    u8 *temp_2_57;
    u8 *temp_2_58;
    u8 *temp_2_59;
    u8 *temp_2_60;
    u8 *temp_2_61;
    u8 *temp_2_62;
    u8 *temp_2_63;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_9;
    u8 *temp_3_5;
    u8 *temp_3_6;
    u8 *temp_3_7;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_8;
    u8 *temp_5_2;
    u8 *temp_5_3;
    u8 *temp_5_4;
    u8 *temp_5_5;
    u8 *temp_8;
    u8 *var_2_2;
    u8 *var_2_5;

    /* var_21 init removed */
    func_001a03b0((s64 *)arg0);
    temp_17 = (s64)((*(s64 *)(arg0 + (0))));
    sp2C0 = 0;
    temp_19 = (u8 *)((*(u8 **)(arg0 + (0x30))));
    temp_2 = (s32)(s32)(((*(u16 *)(arg0 + (0x18))) & 0x4000) != 0);
    sp1C0 = temp_2;
    sp1B0 = (s32)(s32)((*(s64 **)(arg0 + (0x88))) != NULL);
    if (temp_2 != 0) {
        var_f20 = 1.75f;
    } else {
        var_f20 = 1.0f;
    }
    sp290 = 0;
    sp25C = 0;
    sp258 = 0;
    var_22 = 0;
    sp254 = 0;
    sp250 = 0;
    sp22C = 0;
    sp230 = 0;
    func_00194590(func_00202010(temp_19, (*(u16 *)(arg0 + (0x6E)))), 3);
    func_001a0290(arg0, (*(u16 *)(arg0 + (0x6E))), (u8 *)effectIndices);
    if ((*(u16 *)(arg0 + (0x6A))) == 1) {
        temp_2_2 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*(u8 **)(arg0 + (0x30))), (*(u8 **)((u8 *)((*(u8 **)(arg0 + (0x38)))) + (0x30))), 0));
        (*(s64 *)((u8 *)(temp_2_2) + (0x60))) = temp_17;
        func_00194590(temp_2_2, 0);
    } else {
        func_00196040(func_001eb440(arg0 + 0x38) & 0xFFFF, 1, &targetPosition, 0, 0, 1);
        temp_2_3 = (u8 *)(btlUnitCreateRotatePacket((*(BtlUnit **)(arg0 + (0x30))), &targetPosition, 0));
        (*(s64 *)((u8 *)(temp_2_3) + (0x60))) = temp_17;
        func_00194590(temp_2_3, 0);
    }
    var_6 = 0;
    temp_5 = (u16)((*(u16 *)(arg0 + (0x6A))));
    while (((s32)var_6 & 0xFFFF) < (s32) temp_5) {
        temp_4 = (u8 *)((*(u8 **)((u8 *)((arg0 + ((var_6 & 0xFFFF) * 4))) + (0x38))));
        var_10 = 0;
        while ((var_10 & 0xFFFF) < (s32) (*(u8 *)((u8 *)(temp_4) + (0xD9)))) {
            temp_8 = (u8 *)(temp_4 + ((var_10 & 0xFFFF) << 5));
            if ((*(s32 *)((u8 *)(temp_8) + (0xF8))) & 0x100000) {
                var_22 = 1;
            }
            if ((*(u16 *)((u8 *)(temp_8) + (0x10E))) & 4) {
                sp25C = 1;
            }
            var_10 = (var_10 + 1) & 0xFFFF;
        }
        if ((*(s32 *)((u8 *)(temp_4) + (0xE0))) != 0) {
            sp258 = 1;
            sp290 += 1;
        }
        if ((*(s32 *)((u8 *)(temp_4) + (0xE4))) != 0) {
            sp254 = 1;
        }
        if ((*(u16 *)((u8 *)(temp_4) + (0xDE))) & 6) {
            sp250 = 1;
        }
        var_6 = ((s32)var_6 + 1) & 0xFFFF;
    }
    if (sp25C != 0) {
        var_30 = 0xC;
        var_16 = 0;
        sp230 = 1;
    } else if (sp1C0 != 0) {
        var_30 = 4;
        var_16 = 0;
    } else if (sp250 != 0) {
        var_30 = 5;
        var_16 = 2;
        sp230 = 1;
    } else {
        var_30 = 4;
        var_16 = 0;
    }
    if ((var_22 == 1) && (sp1C0 == 0) && (temp_5 == 1) && !((*(s32 *)((u8 *)(iGpffffb3ac) + (0x10))) & 0x2000)) {
        sp22C = 1;
    }
    if (((*(u8 *)((u8 *)(temp_19) + (0xA2))) != 0) || (var_30 == 4) || (var_30 == 0xC)) {
        var_23 = func_001991c0(temp_19, var_30 & 0xFFFF, var_f20);
    } else {
        var_23 = func_001999f0(temp_19, var_30 & 0xFFFF, var_f20, 0);
    }
    temp_2_4 = func_00199500(temp_19, var_30 & 0xFFFF, var_f20);
    sp1A0 = (s32) temp_2_4;
    /* Retail truncates the scaled difference, caps it at 25, then narrows each sum. */
    var_18 = (s16)var_23;
    if (var_23 < temp_2_4) {
        timingAdjustment = (s32)(fGpffff8128 * (f32)(temp_2_4 - var_23));
        if (timingAdjustment > 0x19) {
            timingAdjustment = 25;
        }
        var_18 = (s16)(var_18 + (s16)timingAdjustment);
    }
    if ((sp258 != 0) || (sp254 != 0)) {
        var_18 = (s16)(var_18 + 8);
    }
    if (sp1B0 != 0) {
        temp_2_5 = (func_00199500((*(u8 **)((u8 *)((*(s64 **)(arg0 + (0x88)))) + (0x30))), 0x1A, 1.0f)) - 4;
        if (var_23 < temp_2_5) {
            sp280 = temp_2_5 - var_23;
            sp270 = 0;
        } else {
            sp280 = 0;
            sp270 = var_23 - temp_2_5;
        }
        var_18 = (s16)(var_18 + 0xC);
    } else {
        sp280 = 0;
        sp270 = 0;
    }
    temp_2_6 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)temp_19, (s16)var_30, 0, var_f20, var_16 & 0xFFFF));
    sp2D8 = (u8 *)(temp_2_6);
    (*(s16 *)((u8 *)(temp_2_6) + (0x48))) = (s16) sp280;
    (*(s64 *)((u8 *)(temp_2_6) + (0x60))) = temp_17;
    func_00194590(temp_2_6, 0);
    temp_16 = *(s64 *)(temp_2_6 + 0x58);
    if (sp1B0 == 0) {
        if ((*(u16 *)(arg0 + (0x6A))) == 1) {
            if ((*(u8 *)((u8 *)(temp_19) + (0xA2))) == 0) {
                if (((sp250 == 0) && (var_22 == 0)) || (sp1C0 == 1)) {
                    temp_2_7 = (u8 *)((*(u8 **)(arg0 + (0x30))));
                    temp_4_2 = (u8 *)((*(u8 **)((u8 *)(temp_2_7) + (0xA64))));
                    temp_2_8 = (u8)((*(u8 *)((u8 *)(temp_2_7) + (0xA2))));
                    var_5 = 1;
                    switch (temp_2_8) {             /* switch 1; irregular */
                    case 0:                         /* switch 1 */
                        temp_3 = (s32)(func_0023e1f0(temp_4_2) & 0xFF);
                        if (temp_3 == 5) {
                            var_5 = 1;
                        } else if ((temp_3 == 3) && (((*(u16 *)((u8 *)(iGpffffb3bc) + (2))) & 0x8000) || (sp250 == 0))) {
                            var_5 = 1;
                        } else {
                        default:                    /* switch 1 */
block_69:
                            var_5 = 0;
                        }
                        break;
                    case 1:                         /* switch 1 */
                        if ((*(s16 *)((u8 *)(((((*(u16 *)((u8 *)(temp_4_2) + (2))) & 0xFFFF) * 0xE8) + ((s32)iGpffffb3cc))) + (0x22))) == 1) {

                        } else {
                            goto block_69;
                        }
                        break;
                    }
                    if (var_5 != 0) {
                        var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xC));
                    } else {
                        var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xB));
                    }
                } else {
                    var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x10));
                }
            } else if ((var_22 == 0) || (sp1C0 == 1)) {
                temp_2_9 = (u8 *)((*(u8 **)(arg0 + (0x30))));
                temp_4_3 = (u8 *)((*(u8 **)((u8 *)(temp_2_9) + (0xA64))));
                temp_2_10 = (u8)((*(u8 *)((u8 *)(temp_2_9) + (0xA2))));
                var_5_2 = 1;
                switch (temp_2_10) {                /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    temp_3_2 = (s32)(func_0023e1f0(temp_4_3) & 0xFF);
                    if (temp_3_2 == 5) {
                        var_5_2 = 1;
                    } else if ((temp_3_2 == 3) && (((*(u16 *)((u8 *)(iGpffffb3bc) + (2))) & 0x8000) || (sp250 == 0))) {
                        var_5_2 = 1;
                    } else {
                    default:                        /* switch 2 */
block_87:
                        var_5_2 = 0;
                    }
                    break;
                case 1:                             /* switch 2 */
                    if ((*(s16 *)((u8 *)(((((*(u16 *)((u8 *)(temp_4_3) + (2))) & 0xFFFF) * 0xE8) + ((s32)iGpffffb3cc))) + (0x22))) == 1) {

                    } else {
                        goto block_87;
                    }
                    break;
                }
                if (var_5_2 != 0) {
                    var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xC));
                } else {
                    var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xB));
                }
            } else {
                var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xD));
            }
        } else {
            var_2_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x2C));
        }
        (*(s8 *)((u8 *)(var_2_2) + (0))) = 5;
        (*(s64 *)((u8 *)(var_2_2) + (8))) = temp_16;
        (*(s64 *)((u8 *)(var_2_2) + (0x60))) = temp_17;
        func_00194590(var_2_2, 0);
    }
    if (sp25C != 0) {
        if (var_23 > 6) {
            var_22_2 = var_23 - 6;
        } else {
            var_22_2 = 0;
        }
        sp190 = (s32) (func_00199350(temp_19, var_30 & 0xFFFF, var_f20));
        if ((*(u8 *)((u8 *)(temp_19) + (0xA2))) == 0) {
            temp_2_11 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0xE));
            (*(s8 *)((u8 *)(temp_2_11) + (0))) = 4;
            (*(s64 *)((u8 *)(temp_2_11) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D8) + (0x58)));
            (*(s16 *)((u8 *)(temp_2_11) + (0x48))) = var_22_2;
            (*(s64 *)((u8 *)(temp_2_11) + (0x60))) = temp_17;
            func_00194590(temp_2_11, 0);
        }
        temp_2_12 = (u8 *)(func_001f7c20(0xC, 2, 9));
        (*(s8 *)((u8 *)(temp_2_12) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_12) + (8))) = temp_16;
        if (sp190 > 8) {
            var_2_3 = sp190 - 8;
        } else {
            var_2_3 = 0;
        }
        (*(s16 *)((u8 *)(temp_2_12) + (0x48))) = var_2_3;
        (*(s64 *)((u8 *)(temp_2_12) + (0x60))) = temp_17;
        func_00194590(temp_2_12, 1);
        temp_2_13 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), temp_19, temp_19, 1, 0));
        (*(s8 *)((u8 *)(temp_2_13) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_13) + (8))) = temp_16;
        (*(s16 *)((u8 *)(temp_2_13) + (0x48))) = (s16) sp190;
        (*(s64 *)((u8 *)(temp_2_13) + (0x60))) = temp_17;
        func_00194590(temp_2_13, 2);
        temp_2_14 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD74))), temp_19, temp_19, 1, 0));
        (*(s8 *)((u8 *)(temp_2_14) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_14) + (8))) = temp_16;
        (*(s16 *)((u8 *)(temp_2_14) + (0x48))) = var_22_2;
        (*(s64 *)((u8 *)(temp_2_14) + (0x60))) = temp_17;
        func_00194590(temp_2_14, 2);
        func_001f0a10((u8 *)&result);
        result.addedStatus = 0x100000;
        temp_2_15 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
        (*(s8 *)((u8 *)(temp_2_15) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_15) + (8))) = temp_16;
        temp_4_4 = (s16)sp1A0;
        (*(s16 *)((u8 *)(temp_2_15) + (0x48))) = (s16) (temp_4_4 - (temp_4_4 >> 2));
        (*(s64 *)((u8 *)(temp_2_15) + (0x60))) = temp_17;
        func_00194590(temp_2_15, 1);
        if ((sp1C0 == 0) && ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) == 0)) {
            temp_2_16 = (u8 *)(func_001f5f70(arg0, 0x19, 0, 0, 0));
            (*(s8 *)((u8 *)(temp_2_16) + (0))) = 4;
            (*(s64 *)((u8 *)(temp_2_16) + (8))) = (s64) (*(s64 *)((u8 *)(temp_2_15) + (0x58)));
            (*(s64 *)((u8 *)(temp_2_16) + (0x60))) = temp_17;
            func_00194590(temp_2_16, 1);
        }
    }
    sp1E0 = 0;
    temp_2_17 = (s16)var_18;
    sp180 = (s32) temp_2_17;
    sp170 = temp_2_17 + 0xC;
    while ((spC0 = (s32) sp1E0) < (s32) (*(u16 *)(arg0 + (0x6A)))) {
        temp_18 = (s64 *)((*(s64 **)((u8 *)((arg0 + (sp1E0 * 4))) + (0x38))));
        sp160 = *(u8 *)((u8 *)temp_18 + 0xD9);
        if (sp1C0 != 0) {
            var_2_4 = 1;
        } else {
            var_2_4 = (u8)((*(u8 *)((u8 *)(temp_18) + (0xDA))));
        }
        sp150 = var_2_4;
        sp2B0 = (s32) var_23;
        if (var_23 > 3) {
            var_21 = var_23 - 3;
        } else {
            var_21 = 0;
        }
        if (sp1B0 == 0) {
            temp_2_18 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*(u8 **)((u8 *)((s64 *)(u32)temp_18) + (0x30))), temp_19, 2));
            (*(s8 *)((u8 *)(temp_2_18) + (0))) = 5;
            (*(s64 *)((u8 *)(temp_2_18) + (8))) = temp_16;
            (*(s16 *)((u8 *)(temp_2_18) + (0x48))) = var_21;
            (*(u8 *)((u8 *)(temp_2_18) + (0x47))) = (u8) ((*(u8 *)((u8 *)(temp_2_18) + (0x47))) & 0xDF);
            (*(s64 *)((u8 *)(temp_2_18) + (0x60))) = temp_17;
            func_00194590(temp_2_18, 1);
            if ((*(s32 *)((u8 *)(temp_18) + (0xE4))) != 0) {
                var_22_3 = (s64 *)arg0;
            } else {
                var_22_3 = (s64 *)(temp_18);
            }
        } else {
            var_22_3 = (s64 *)((*(s64 **)(arg0 + (0x88))));
            temp_2_19 = (u8 *)(func_001f99c0(var_22_3, 0xD, 0U, 0, 0));
            (*(s16 *)((u8 *)(temp_2_19) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_19) + (0x60))) = temp_17;
            func_00194590(temp_2_19, 1);
            temp_2_20 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*(u8 **)((u8 *)(temp_18) + (0x30))), temp_19, 2));
            (*(s16 *)((u8 *)(temp_2_20) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_20) + (0x60))) = temp_17;
            func_00194590(temp_2_20, 0);
            temp_2_21 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x11));
            (*(s16 *)((u8 *)(temp_2_21) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_21) + (0x60))) = temp_17;
            (*(s16 *)((u8 *)(temp_2_21) + (0x4A))) = (s16) sp170;
            func_00194590(temp_2_21, 0);
            temp_2_22 = (u8 *)(func_001d3530((*(u8 **)((u8 *)(var_22_3) + (0x30))), (*(u8 **)((u8 *)(temp_18) + (0x30))), 2));
            (*(s16 *)((u8 *)(temp_2_22) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_22) + (0x60))) = temp_17;
            func_00194590(temp_2_22, 0);
            temp_2_23 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*(u8 **)((u8 *)(var_22_3) + (0x30))), 0x1A, 0, 1.0f, 0));
            (*(s16 *)((u8 *)(temp_2_23) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_23) + (0x60))) = temp_17;
            func_00194590(temp_2_23, 0);
            temp_2_24 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*(u8 **)((u8 *)(temp_18) + (0x30))), 0x1A, 0, 1.0f, 2));
            (*(s16 *)((u8 *)(temp_2_24) + (0x48))) = (s16) sp270;
            (*(s64 *)((u8 *)(temp_2_24) + (0x60))) = temp_17;
            func_00194590(temp_2_24, 0);
            sp230 = 1;
        }
        if ((*(u8 *)((u8 *)(temp_19) + (0xA2))) == 0) {
            if ((func_001f08c0(temp_19) != 0) && (temp_4_5 = (*(u8 **)((u8 *)(var_22_3) + (0x30))), ((*(u8 *)((u8 *)(temp_4_5) + (0xA2))) == 1))) {
                sp210 = (s32)(((*(s16 *)((u8 *)((((s32)iGpffffb3cc) + ((*(u16 *)((u8 *)(temp_4_5) + (0xA4))) * 0xE8))) + (0x18))) & 0x40) == 0);
            } else {
                sp210 = 0;
            }
        } else {
            sp210 = 0;
        }
        if ((sp22C == 1) && (spC0 == 0) && ((*(u8 *)((u8 *)(temp_19) + (0xA2))) == 0) && ((*(u16 *)(arg0 + (0x6A))) == 1) && (sp258 == 0)) {
            if (sp210 != 0) {
                var_f12 = fGpffff8358;
            } else {
                var_f12 = 400.0f;
            }
            temp_2_25 = (u8 *)(func_001d1eb0((u32)temp_19, (u32)(*(u8 **)((u8 *)(temp_18) + (0x30))), var_f12, 3));
            (*(s8 *)((u8 *)(temp_2_25) + (0))) = 5;
            (*(s64 *)((u8 *)(temp_2_25) + (8))) = temp_16;
            (*(s64 *)((u8 *)(temp_2_25) + (0x60))) = temp_17;
            func_00194590(temp_2_25, 0);
            sp230 = 1;
        }
        sp1D0 = 0;
        temp_2_26 = (s16)sp150;
        sp140 = (s32) temp_2_26;
        sp130 = temp_2_26 - 1;
        sp120 = (s16)sp160;
        while ((spD0 = (s32) sp1D0) < sp120) {
            sp260 = 0;
            hit = &((LargeBattleHitResult *)((u8 *)temp_18 + 0xF0))[sp1D0];
            while ((s32)(sp200 = (s32) sp260) < sp140) {
                temp_2_27 = hit->motion;
                sp2A0 = (s32) temp_2_27;
                if ((temp_2_27 != 0x13) && (temp_2_27 != 9)) {

                } else if (sp200 != sp130) {
                    sp2A0 = 2;
                }
                if (((*(u16 *)((u8 *)(temp_18) + (0xDC))) & 0x404) || (hit->flags & 4)) {
                    sp240 = 0;
                } else {
                    sp240 = 1;
                }
                temp_2_28 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*(u8 **)((u8 *)(var_22_3) + (0x30))), (s16)sp2A0, 0, 1.0f, 0));
                sp2DC = (u8 *)(temp_2_28);
                (*(s8 *)((u8 *)(temp_2_28) + (0))) = 5;
                (*(s64 *)((u8 *)(temp_2_28) + (8))) = temp_16;
                if (!((sp2A0 != -3) && (sp2A0 != 0x17))) {
                    if (sp2B0 > 6) {
                        var_3 = sp2B0 - 6;
                    } else {
                        var_3 = 0;
                    }
                    (*(s16 *)((u8 *)(sp2DC) + (0x48))) = var_3;
                } else {
                    (*(s16 *)((u8 *)(sp2DC) + (0x48))) = (s16) sp2B0;
                }
                if ((*(s32 *)((u8 *)(temp_18) + (0xE4))) != 0) {
                    (*(s16 *)((u8 *)(sp2DC) + (0x48))) = (s16) ((*(s16 *)((u8 *)(sp2DC) + (0x48))) + 5);
                    var_21 += 5;
                }
                (*(s64 *)((u8 *)(sp2DC) + (0x60))) = temp_17;
                func_00194590(sp2DC, 0);
                sp2C0 = *(s64 *)(sp2DC + 0x58);
                if (((*(u16 *)((u8 *)(temp_18) + (0xDC))) & 4) && (sp25C == 0)) {
                    temp_2_29 = (u8 *)(func_001f7c20(0xD, 1, 0xF));
                    (*(s8 *)((u8 *)(temp_2_29) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_29) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_29) + (0x48))) = (s16) sp2B0;
                    func_00194590(temp_2_29, 1);
                }
                if ((*(s32 *)((u8 *)(temp_18) + (0xE4))) != 0) {
                    temp_2_30 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD28))), temp_19, (*(u8 **)((u8 *)(temp_18) + (0x30))), 1, 0));
                    (*(s8 *)((u8 *)(temp_2_30) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_30) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_30) + (0x48))) = (s16) sp2B0;
                    func_00194590(temp_2_30, 1);
                    temp_2_31 = (u8 *)(func_001f7c20(0xD, 2, 0xB));
                    (*(s8 *)((u8 *)(temp_2_31) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_31) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_31) + (0x48))) = (s16) sp2B0;
                    func_00194590(temp_2_31, 1);
                }
                if ((*(u16 *)((u8 *)(temp_18) + (0xDC))) == 0x400) {
                    temp_2_32 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD2C))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                    (*(s8 *)((u8 *)(temp_2_32) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_32) + (8))) = sp2C0;
                    func_00194590(temp_2_32, 1);
                    temp_2_33 = (u8 *)(func_001f7c20(0xC, 2, 0xC));
                    (*(s8 *)((u8 *)(temp_2_33) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_33) + (8))) = sp2C0;
                    func_00194590(temp_2_33, 1);
                }
                func_001f7830(temp_19, sp200, sp250, &sp32E, &sp32C);
                if ((sp32E >= 0) && (sp32C >= 0)) {
                    temp_2_34 = (u8 *)(func_001f7c20(0xD, sp32E & 0xFFFF, sp32C & 0xFFFF));
                    (*(s8 *)((u8 *)(temp_2_34) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_34) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_34) + (0x48))) = var_21;
                    func_00194590(temp_2_34, 1);
                }
                if (sp240 != 0) {
                    if (((*(u16 *)((u8 *)(temp_18) + (0xDE))) & 6) && (sp1C0 == 0)) {
                        if (sp200 != sp130) {
                            var_2_5 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD1C))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                        } else {
                            var_2_5 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD20))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                        }
                        (*(s8 *)((u8 *)(var_2_5) + (0))) = 5;
                        (*(s64 *)((u8 *)(var_2_5) + (8))) = temp_16;
                        (*(s16 *)((u8 *)(var_2_5) + (0x48))) = var_21;
                        (*(s64 *)((u8 *)(var_2_5) + (0x60))) = temp_17;
                        func_00194590(var_2_5, 2);
                        if (sp200 == sp130) {
                            temp_2_35 = (u8 *)(func_001f7c20(0xC, 0, 9));
                            (*(s8 *)((u8 *)(temp_2_35) + (0))) = 5;
                            (*(s64 *)((u8 *)(temp_2_35) + (8))) = temp_16;
                            (*(s16 *)((u8 *)(temp_2_35) + (0x48))) = var_21;
                            func_00194590(temp_2_35, 1);
                        }
                    }
                    temp_2_36 = (u8 *)(func_001d6240((*(s32 *)((u8 *)((iGpffffb3ac + (effectIndices[0] * 4))) + (0xD04))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                    (*(s8 *)((u8 *)(temp_2_36) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_36) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_36) + (0x48))) = var_21;
                    func_00194590(temp_2_36, 2);
                    if (effectIndices[1] >= 0) {
                        temp_2_37 = (u8 *)(func_001d6240((*(s32 *)((u8 *)((iGpffffb3ac + (effectIndices[1] * 4))) + (0xD04))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                        (*(s8 *)((u8 *)(temp_2_37) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_37) + (8))) = temp_16;
                        (*(s16 *)((u8 *)(temp_2_37) + (0x48))) = var_21;
                        func_00194590(temp_2_37, 2);
                    }
                    if (sp1C0 == 0) {
                        func_001f7910(temp_19, sp200, sp250, &sp32E, &sp32C);
                        if ((sp32E >= 0) && (sp32C >= 0)) {
                            temp_2_38 = (u8 *)(func_001f7c20(0xA, sp32E & 0xFFFF, sp32C & 0xFFFF));
                            (*(s8 *)((u8 *)(temp_2_38) + (0))) = 5;
                            (*(s64 *)((u8 *)(temp_2_38) + (8))) = temp_16;
                            (*(s16 *)((u8 *)(temp_2_38) + (0x48))) = var_21;
                            func_00194590(temp_2_38, 1);
                        }
                        if ((sp200 == sp130) && ((*(s32 *)((u8 *)(temp_18) + (0xE0))) == 0) && (hit->addedStatus & 0x7FFFE)) {
                            temp_2_39 = (u8 *)(func_001f7c20(0xF, 2, 0xF));
                            (*(s8 *)((u8 *)(temp_2_39) + (0))) = 5;
                            (*(s64 *)((u8 *)(temp_2_39) + (8))) = temp_16;
                            (*(s16 *)((u8 *)(temp_2_39) + (0x48))) = var_21;
                            func_00194590(temp_2_39, 1);
                        }
                    } else {
                        temp_2_40 = (u8 *)(func_001f7c20(0xA, 2, 0x14));
                        (*(s8 *)((u8 *)(temp_2_40) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_40) + (8))) = temp_16;
                        (*(s16 *)((u8 *)(temp_2_40) + (0x48))) = var_21;
                        func_00194590(temp_2_40, 1);
                    }
                    temp_2_41 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD24))), temp_19, (*(u8 **)((u8 *)(var_22_3) + (0x30))), 1, 0));
                    (*(s8 *)((u8 *)(temp_2_41) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_41) + (8))) = temp_16;
                    (*(s16 *)((u8 *)(temp_2_41) + (0x48))) = var_21;
                    func_00194590(temp_2_41, 2);
                }
                if (sp200 != sp130) {
                    temp_3_3 = (func_001999f0(temp_19, var_30 & 0xFFFF, var_f20, (sp200 + 1) & 0xFFFF)) - sp2B0;
                    sp2B0 += temp_3_3;
                    var_21 += temp_3_3;
                } else if ((sp22C != 0) && ((*(s32 *)((u8 *)(temp_18) + (0xE0))) == 0)) {
                    if (sp210 != 0) {
                        var_2_6 = 0x1D;
                    } else {
                        var_2_6 = 0x1E;
                    }
                    temp_5_2 = (u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30))));
                    temp_2_42 = (u8 *)(func_001d6240((*(s32 *)((u8 *)((iGpffffb3ac + (var_2_6 * 4))) + (0xD04))), temp_5_2, temp_5_2, 1, 0));
                    sp2D4 = (u8 *)(temp_2_42);
                    (*(s8 *)((u8 *)(temp_2_42) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_42) + (8))) = sp2C0;
                    (*(s16 *)((u8 *)(temp_2_42) + (0x48))) = 1;
                    (*(s64 *)((u8 *)(temp_2_42) + (0x60))) = temp_17;
                    func_00194590(temp_2_42, 2);
                    if (sp210 != 0) {
                        temp_5_3 = (u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30))));
                        temp_2_43 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD84))), temp_5_3, temp_5_3, 1, 0));
                        (*(s8 *)((u8 *)(temp_2_43) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_43) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D4) + (0x58)));
                        (*(s64 *)((u8 *)(temp_2_43) + (0x60))) = temp_17;
                        func_00194590(temp_2_43, 2);
                        temp_5_4 = (u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30))));
                        temp_2_44 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), temp_5_4, temp_5_4, 1, 0));
                        (*(s8 *)((u8 *)(temp_2_44) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_44) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D4) + (0x58)));
                        (*(s16 *)((u8 *)(temp_2_44) + (0x48))) = 0x14;
                        (*(s64 *)((u8 *)(temp_2_44) + (0x60))) = temp_17;
                        func_00194590(temp_2_44, 2);
                        temp_5_5 = (u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30))));
                        temp_2_45 = (u8 *)(func_001d6240((*(s32 *)((u8 *)(iGpffffb3ac) + (0xD80))), temp_5_5, temp_5_5, 1, 0));
                        (*(s8 *)((u8 *)(temp_2_45) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_45) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D4) + (0x58)));
                        (*(s16 *)((u8 *)(temp_2_45) + (0x48))) = 0x1A;
                        (*(s64 *)((u8 *)(temp_2_45) + (0x60))) = temp_17;
                        func_00194590(temp_2_45, 2);
                    } else {
                        temp_2_46 = (u8 *)(func_00197cc0((*(u8 **)((u8 *)(var_22_3) + (0x30))), (s16) (*(u16 *)(arg0 + (0x6E))), 0));
                        (*(s8 *)((u8 *)(temp_2_46) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_46) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D4) + (0x58)));
                        (*(s64 *)((u8 *)(temp_2_46) + (0x60))) = temp_17;
                        func_00194590(temp_2_46, 1);
                        temp_2_47 = (u8 *)(func_001bccc0(0x14, 0x32, 0, 5));
                        (*(s8 *)((u8 *)(temp_2_47) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_47) + (8))) = (s64) (*(s64 *)((u8 *)(sp2D4) + (0x58)));
                        (*(s64 *)((u8 *)(temp_2_47) + (0x60))) = temp_17;
                        func_00194590(temp_2_47, 1);
                    }
                }
                sp260 += 1;
            }
            temp_2_48 = hit;
            sp1F0 = temp_2_48;
            temp_2_49 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(var_22_3), temp_2_48, (*(u16 *)((u8 *)(temp_18) + (0xDC))), (*(u16 *)((u8 *)(temp_18) + (0xDE)))));
            (*(s8 *)((u8 *)(temp_2_49) + (0))) = 5;
            (*(s64 *)((u8 *)(temp_2_49) + (8))) = temp_16;
            (*(s16 *)((u8 *)(temp_2_49) + (0x48))) = var_21;
            (*(s64 *)((u8 *)(temp_2_49) + (0x60))) = temp_17;
            func_00194590(temp_2_49, 1);
            temp_2_50 = (u8 *)(func_00201de0((s32)(temp_19), (s32)((*(u8 **)((u8 *)(var_22_3) + (0x30)))), (*(u16 *)(arg0 + (0x6E))), (*(u16 *)((u8 *)(temp_18) + (0xDC))), (*(u16 *)((u8 *)(temp_18) + (0xDE))), 0, 1, sp1F0, 0));
            (*(s8 *)((u8 *)(temp_2_50) + (0))) = 5;
            (*(s64 *)((u8 *)(temp_2_50) + (8))) = temp_16;
            (*(s16 *)((u8 *)(temp_2_50) + (0x48))) = var_21;
            if (var_21 < sp180) {
                var_2_7 = sp180 - var_21;
            } else {
                var_2_7 = 0;
            }
            (*(s16 *)((u8 *)(temp_2_50) + (0x4A))) = var_2_7;
            (*(s64 *)((u8 *)(temp_2_50) + (0x60))) = temp_17;
            func_00194590(temp_2_50, 3);
            if ((spD0 == 0) && (sp1F0->hpDelta != 0)) {
                temp_2_51 = (u8 *)(func_00202590((s32)((*(u8 **)((u8 *)(var_22_3) + (0x30)))), 0, 0));
                (*(s8 *)((u8 *)(temp_2_51) + (0))) = 5;
                (*(s64 *)((u8 *)(temp_2_51) + (8))) = temp_16;
                (*(s16 *)((u8 *)(temp_2_51) + (0x48))) = var_21;
                (*(u8 *)((u8 *)(temp_2_51) + (0x47))) = (u8) ((*(u8 *)((u8 *)(temp_2_51) + (0x47))) & 0xDF);
                (*(s64 *)((u8 *)(temp_2_51) + (0x60))) = temp_17;
                func_00194590(temp_2_51, 3);
            }
            /* Retail retains this address and reloads its word at the later branch. */
            addedStatus = &hit->addedStatus;
            if ((hit->addedStatus & 0x100000) && ((*(u8 *)((u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30)))) + (0xA2))) == 1)) {
                temp_2_52 = (u8 *)(func_001f7c20(0xD, 2, 8));
                (*(s8 *)((u8 *)(temp_2_52) + (0))) = 5;
                (*(s64 *)((u8 *)(temp_2_52) + (8))) = temp_16;
                (*(s16 *)((u8 *)(temp_2_52) + (0x48))) = var_21;
                (*(s64 *)((u8 *)(temp_2_52) + (0x60))) = temp_17;
                func_00194590(temp_2_52, 1);
            }
            if ((sp1C0 == 0) && ((*(u8 *)((u8 *)((*(u8 **)((u8 *)(var_22_3) + (0x30)))) + (0xA2))) == 1)) {
                if (sp290 > 0) {
                    if ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) == 0) {
                        spF0 = func_001ef720(2, 0x80000) & 0xFFFF;
                        if (((s32) (*(u8 *)(arg0 + (0x28))) <= 0) && ((*(u16 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA4))) != 1) && (func_00231d70(0x64) < 0x32U)) {
                            if ((*(u8 *)((u8 *)((*(u8 **)(arg0 + (0x30)))) + (0xA2))) != 0) {
                                var_2_8 = 0;
                            } else {
                                temp_4_6 = (u8 *)(iGpffffb3ac);
                                if ((*(s16 *)((u8 *)(temp_4_6) + (0xA70))) != -1) {
                                    temp_3_4 = (s16)(spF0 - sp290);
                                    if (temp_3_4 <= 0) {
                                        temp_4_7 = func_001ef720(2, 0x80000) & 0xFFFF;
                                        temp_3_5 = (u8 *)(iGpffffb3ac);
                                        if (((u32) ((s16) (*(s16 *)((u8 *)(temp_3_5) + (0xA72))) >> 1) >= temp_4_7) && (temp_2_53 = (*(s16 *)((u8 *)(temp_3_5) + (0xA70))), spE0 = (s32) temp_2_53, (temp_2_53 != (s16)func_001d15a0()))) {
                                            var_2_8 = 1;
                                        } else {
                                            goto block_222;
                                        }
                                    } else if (((s16) (*(s16 *)((u8 *)(temp_4_6) + (0xA72))) >> 1) >= temp_3_4) {
                                        var_2_8 = 1;
                                    } else {
                                        goto block_222;
                                    }
                                } else {
block_222:
                                    var_2_8 = 0;
                                }
                            }
                            if (var_2_8 != 0) {
                                goto block_224;
                            }
                            temp_2_54 = (u8 *)(func_001f99c0(arg0, 0x10, (u16) sp290, 0, 0));
                            (*(s8 *)((u8 *)(temp_2_54) + (0))) = 4;
                            (*(s64 *)((u8 *)(temp_2_54) + (8))) = sp2C0;
                            func_00194590(temp_2_54, 1);
                        } else {
block_224:
                            temp_2_55 = (u8 *)(func_001f5f70(arg0, 0x13, sp290, 0, 0));
                            (*(s8 *)((u8 *)(temp_2_55) + (0))) = 4;
                            (*(s64 *)((u8 *)(temp_2_55) + (8))) = sp2C0;
                            (*(s64 *)((u8 *)(temp_2_55) + (0x60))) = temp_17;
                            func_00194590(temp_2_55, 1);
                        }
                    }
                } else if (*addedStatus & 0x100000) {
                    temp_2_56 = (u8 *)(func_001f5f70(arg0, 0x18, (s32) (*(u16 *)((u8 *)(temp_18) + (0xDE))), 1, 0));
                    (*(s8 *)((u8 *)(temp_2_56) + (0))) = 5;
                    (*(s64 *)((u8 *)(temp_2_56) + (8))) = sp2C0;
                    (*(s64 *)((u8 *)(temp_2_56) + (0x60))) = temp_17;
                    func_00194590(temp_2_56, 1);
                } else if (sp290 == 0) {
                    if (func_001f0dd0((s64 *)arg0, 1) != 0) {
                        temp_2_57 = (u8 *)(func_001f99c0(arg0, 0xF, 0U, 0, 0));
                        (*(s8 *)((u8 *)(temp_2_57) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_57) + (8))) = sp2C0;
                        func_00194590(temp_2_57, 1);
                    } else if ((func_001f0f70((s64 *)arg0) == 1) && (func_001f0b90(arg0) == 0)) {
                        temp_2_58 = (u8 *)(func_001f99c0(arg0, 0x11, 0U, 0, 0));
                        (*(s8 *)((u8 *)(temp_2_58) + (0))) = 5;
                        (*(s64 *)((u8 *)(temp_2_58) + (8))) = sp2C0;
                        func_00194590(temp_2_58, 1);
                    }
                }
            }
            sp1D0 += 1;
        }
        temp_2_59 = (u8 *)(func_001f3950(temp_18));
        (*(s8 *)((u8 *)(temp_2_59) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_59) + (8))) = temp_16;
        (*(s16 *)((u8 *)(temp_2_59) + (0x48))) = var_21;
        (*(s64 *)((u8 *)(temp_2_59) + (0x60))) = temp_17;
        func_00194590(temp_2_59, 1);
        temp_5_6 = (s16)((*(s16 *)(arg0 + (0xEC))));
        if ((temp_5_6 != 0) && !((*(u8 *)(arg0 + (0xD8))) & 1)) {
            temp_2_60 = (u8 *)(func_00202400((*(u8 **)(arg0 + (0x30))), temp_5_6));
            (*(s8 *)((u8 *)(temp_2_60) + (0))) = 5;
            (*(s64 *)((u8 *)(temp_2_60) + (8))) = temp_16;
            (*(s16 *)((u8 *)(temp_2_60) + (0x48))) = var_21;
            (*(u8 *)((u8 *)(temp_2_60) + (0x47))) = (u8) ((*(u8 *)((u8 *)(temp_2_60) + (0x47))) & 0xDF);
            (*(s64 *)((u8 *)(temp_2_60) + (0x60))) = temp_17;
            func_00194590(temp_2_60, 3);
        } else {
            temp_5_7 = (s16)((*(s16 *)((u8 *)(temp_18) + (0xEC))));
            if (temp_5_7 != 0) {
                temp_2_61 = (u8 *)(func_00202400((*(u8 **)((u8 *)(temp_18) + (0x30))), temp_5_7));
                (*(s8 *)((u8 *)(temp_2_61) + (0))) = 5;
                (*(s64 *)((u8 *)(temp_2_61) + (8))) = temp_16;
                (*(s16 *)((u8 *)(temp_2_61) + (0x48))) = var_21;
                (*(u8 *)((u8 *)(temp_2_61) + (0x47))) = (u8) ((*(u8 *)((u8 *)(temp_2_61) + (0x47))) & 0xDF);
                (*(s64 *)((u8 *)(temp_2_61) + (0x60))) = temp_17;
                func_00194590(temp_2_61, 3);
            }
        }
        sp1E0 += 1;
    }
    temp_2_62 = (u8 *)(func_001f3950(arg0));
    (*(s8 *)((u8 *)(temp_2_62) + (0))) = 5;
    (*(s64 *)((u8 *)(temp_2_62) + (8))) = temp_16;
    (*(s16 *)((u8 *)(temp_2_62) + (0x48))) = var_21;
    (*(s64 *)((u8 *)(temp_2_62) + (0x60))) = temp_17;
    func_00194590(temp_2_62, 1);
    if (!((*(u16 *)(arg0 + (0x18))) & 4)) {
        temp_2_63 = (u8 *)(func_001f3870(arg0, (*(u8 *)(arg0 + (0xDB)))));
        (*(s8 *)((u8 *)(temp_2_63) + (0))) = 5;
        (*(s64 *)((u8 *)(temp_2_63) + (8))) = temp_16;
        (*(s16 *)((u8 *)(temp_2_63) + (0x48))) = var_21;
        (*(s64 *)((u8 *)(temp_2_63) + (0x60))) = temp_17;
        func_00194590(temp_2_63, 1);
    }
    if (sp230 != 0) {
        temp_4_8 = (u8 *)(iGpffffb3ac);
        (*(s32 *)((u8 *)(temp_4_8) + (0xC))) = (s32) ((*(s32 *)((u8 *)(temp_4_8) + (0xC))) | 0x400000);
        temp_3_6 = (u8 *)(iGpffffb3ac);
        (*(u16 *)((u8 *)(temp_3_6) + (0x18))) = (u16) ((*(u16 *)((u8 *)(temp_3_6) + (0x18))) | 0xF);
    }
    temp_3_7 = (u8 *)((*(u8 **)(arg0 + (0x8C))));
    if (temp_3_7 != NULL) {
        cutin.mode = 3;
        cutin.unitId = (u16)((*(u16 *)((u8 *)((*(u8 **)((u8 *)(temp_3_7) + (0x30)))) + (0xA4))));
        func_00194590(func_001fa720(&cutin), 1);
    }
    if (func_001f68e0((s64 *)arg0) != 0) {
        btlActionSetState((s64 *)arg0, 0x1BU);
        return;
    }
    temp_3_8 = (u16)((*(u16 *)(arg0 + (0x6C))));
    if ((temp_3_8 != 2) && (temp_3_8 != 3) && (temp_3_8 != 1)) {

    }
    btlActionSetState((s64 *)arg0, 0x20U);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a59a0);
#endif
// FUN_001A7710
void func_001a7710(void)
{
}

/* measured 001a7720 2026-09-19 (owner, landing Nb0012's draft): object 4498 against retail
   4384 (+2.6%, band 4252-4516, 18 instructions of headroom), 1933 fnalign edits.  4384
   instructions and no body until now - the second largest first-party function in the tree.
   The landing was entirely width selection.  From the all-s32 draft the body is 3929
   (-10.4%, far under); putting twelve s64 temporaries back overshoots to 4541 (+3.6%).
   The variables are wildly unequal in cost: narrowing temp_23_2 alone is worth **556
   instructions** (20 uses, each a dsll32/dsra32 pair), temp_30 is worth 32, temp_22 is
   worth 11, and temp_18_2, sp490, sp470, var_2_12, var_17_3, sp468 and var_2_2 are all
   worth exactly nothing - MWCC had already proved those values fit in 32 bits.
   So the landing set is: the twelve-variable s64 draft, minus temp_22 and temp_30.
   Measured neighbours, for anyone re-tuning: 4541 (v15 base), 4530 (-temp_22), 4529
   (-temp_22 -temp_3_14 / -temp_3_15), 4528 (-temp_22 -temp_3_13), 4498 (this one), 3985
   (-temp_23_2).  There is nothing between 4498 and 3985 because temp_23_2 is the only
   remaining variable with real width cost. */
/* measured 001a7720 (owner, 2026-09-19): fnalign **1933 -> 1931 edits**, count
   4498 -> 4496 against retail 4384, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 001a7720 2026-09-20 (over-length pass, P6): object 4496 -> 4392 against retail
   4384 (+0.18%, band 4252-4516), fnalign 1931 -> 1735 edits (plus 32 reloc-only, was 2).
   Checked cheap cause first: all float literals already carry `f`, but three `fptodp`
   emulation calls remained from `extern s32 func_*();` prototypes promoting `var_f20` /
   `var_f20_2` floats to double. Giving 001991c0/00199350/00199500/00199ee0 `s32` returns
   with `f32` params (s16 returns cost +11 for auto-extension) removes all three `fptodp`
   (4496 -> 4493, -46 edits); `s16` returns tie worse at 4507/1900. Changing the four
   `0x3F800000` sites for 00199500/00199350 to `1.0f` rides along (int->float conversion
   vs direct constant). Then: `var_f1 = (f32)temp_2_97` without the dead `>=0 / else
   2.0f*...` unsigned-conversion branch (-12, the 2752-insert), and `temp_f2` / `var_f1_2`
   without the redundant `(f32)(s32)` double casts (4479/1868). Holding `temp_30+base`
   once in `temp_30_ptr` instead of recomputing at all 17 uses is -51 to 4428/1810 -
   the recompute-vs-hold the brief names. Removing the `(*(u8**)iGpffffb3ac)` extra
   indirection to direct `(iGpffffb3ac+off)` (38 sites, the file's own 001a4c80 pattern)
   plus direct `b3b8/b3cc/b3bc` bases is -36 to this 4392/1735. Inner `loop_385`
   while/goto -> `do/while` measured individually as 4392 -> 4374 (-18) but +50 edits,
   so rejected; the banked outer do/while is left alone. Epilogue empty-if -> if/else
   both calling 0x20 measured +13/-6, rejected for count. Frame stays 0x6f0 vs 0x5b0;
   count is inside with 124 headroom, which is the primary goal. */

/* 2026-10-03: all eleven animation creations use the canonical provider
   signature. The opening query preserves its unused a0 word and narrows its
   result as a signed halfword; the hit animation at 001aa23c is a signed byte.
   Other reconstruction defects remain; keep this controller ASM-backed. */
/* 2026-10-03: audited packet dependencies at +8/+0x18/+0x28 and owner UID
   at +0x60 use retail ld/sd throughout; preserve their full 64-bit values.
   Four saved dependency locals and the 001d65d0 UID formal are wide too.
 * 2026-10-09: 1489 -> 1486: the m2c label loops are while loops.
 * 2026-10-09: 1486 -> 1358: body taken from the parallel cos/finish-first-party-20261009 worktree.
 * 1346: comparison constants in retail's form.
 * 1320: type sweep.
 * 1316: cmp sweep.
 * 1286: type sweep.
 * 1280: type sweep.
 * 1279: cmp sweep.
 * 1267: conversion lever (temp_22_3:(1, 2)).
 * 2026-10-10: 1267 -> 1247 aligned edits by preserving the exclusive
 * main-unit versus fallback-unit hit-packet paths in opposite branch order.
 * The 001d2d90/001d3000 constructors return BtlPacket pointers.
 * sdiff struct 871 -> 652: opt_common_subs off (retail reloads every field; CSE hoisted and spilled field addresses).
 * sp450 stored straight from the s16 field, index reloaded from it; 32-bit flag test at iGpffffb3ac+0xC.
 * sp200/sp1E0 are s32 (retail spills them whole).
 */
// FUN_001A7720 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
void func_001a7720(u8 *arg0) {

    extern s32 btlCreateSetFlagsPacket();
    extern s32 func_00194590();
    extern s32 func_00194b60();
    extern s32 func_00194c90();
    extern s32 func_00195530();
    extern void func_001958f0(BtlUnit *unit, RwV3d *dst);
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern s32 func_00197cc0();
    extern s32 btlUnitCreateRotateTowardUnitPacket();
    extern s32 func_00198810();
    extern s32 func_0019a0c0();
    extern s32 func_0019a980();
    extern s32 func_0019aa70();
    extern BtlPacket *func_0019ac40(BtlUnit *unit, u16 value, f32 speed, u16 mode);
    extern s32 func_0019b550();
    extern s32 func_0019bbe0();
    extern BtlPacket *btlUnitCreateLookAtPacket(BtlUnit *unit, const RwV3d *targetPos, u16 flags);
    extern s32 btlUnitCreateLookAtDeactivatePacket();
    extern s32 func_001a03b0();
    extern s32 btlActionSetState();
    extern s32 func_001b7060();
    extern s32 func_001b7080();
    extern s32 func_001b7090();
    extern s32 func_001b70a0();
    extern s32 func_001b7880();
    extern s32 func_001b7e20();
    extern BtlPacket *func_001b83f0(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    extern s32 func_001b9360();
    extern s32 func_001b9560();
    extern s32 func_001b99a0();
    extern s32 func_001ba090();
    extern s32 btlCameraCreateSetStatePacket();
    extern s32 func_001bccc0();
    extern BtlPacket *func_001d2d90();
    extern BtlPacket *func_001d3000();
    extern s32 func_001d3530();
    extern s32 func_001d3d50();
    extern s32 func_001d3e00();
    extern s32 func_001d43f0();
    extern s32 func_001d6240();
    extern s32 func_001eb440();
    extern s32 func_001ef4a0();
    extern s32 func_001ef720();
    extern void func_001f0a10(u8 *result);
    extern s32 func_001f0af0();
    extern s32 func_001f0b90();
    extern s32 func_001f0c50();
    extern s32 func_001f0d30();
    extern s32 func_001f0dd0();
    extern s32 func_001f0f70();
    extern s32 func_001f0ff0();
    extern s32 func_001f1030();
    extern s32 func_001f2f90();
    extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern s32 func_001f3950();
    extern s32 func_001f3b20();
    extern s32 func_001f5f70();
    extern s32 func_001f68e0();
    extern s32 func_001f7c20();
    extern s32 btlSoundCreateSkillSEPacket();
    extern s32 func_001f83b0();
    extern s32 func_001f8430();
    extern s32 func_001f99c0();
    extern s32 func_001fa110();
    extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern s32 func_00201f20();
    extern s32 func_00202010();
    extern s32 func_00202120();
    extern s32 func_00202400();
    extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
    extern s32 func_00202740();
    extern s32 func_00216da0();
    extern s32 func_0022d200();
    extern s32 func_0022d540();
    extern s32 func_0022e4f0();
    extern s32 func_0022eba0();
    extern s32 func_0022f8b0();
    extern s32 func_0022f950();
    extern s32 func_0022fd30();
    extern s32 func_00230020();
    extern u16 datCalcGetHp(s32 unit);
    extern s32 func_0023df70(s32 skill);
    extern s32 func_0043c6a0();
    extern s32 effMiscRand();
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern u8 *iGpffffb3bc;

    s32 sp5AC;
    s32 sp5A8;
    /* 0022d540 returns the three formation effect handles together. */
    s32 effectHandles[3];
    /* Both cut-in constructors copy ten bytes; modes 3/4 use four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    /* Retail reserves 0x60 bytes for the formatted formation name. */
    char formation[96];
    s32 *sp4E0;
    u8 *sp4D0;
    u8 *sp4CC;
    u8 *sp4C8;
    u8 *sp4C4;
    u8 *sp4C0;
    u8 *sp4BC;
    u8 *sp4B8;
    s32 sp4A0;
    s64 sp490;
    s64 sp480;
    s64 sp470;
    s64 sp468;
    s16 sp450;
    s16 sp440;
    s16 sp430;
    s16 sp420;
    s16 sp410;                                      /* compiler-managed */
    s32 sp400;
    s32 sp3F0;
    s32 sp3E0;
    s32 sp3D0;
    s32 sp3C0;
    u16 sp3B0;
    u16 sp3A0;
    u16 sp390;
    u16 sp380;
    u16 sp370;
    u16 sp360;
    s32 sp350;
    s32 sp340;
    s32 sp33C;
    s32 sp320;
    s32 sp310;
    s32 sp30C;
    s32 sp2F0;
    s32 sp2E0;
    s32 sp2D0;
    s32 sp2C0;
    s32 sp2B0;
    u16 sp2A0;
    s32 sp290;
    u16 sp280;
    s32 sp270;
    s32 sp260;
    s32 sp250;
    s32 *sp240;
    s32 sp230;
    s32 sp220;
    s32 sp210;
    s32 sp200;
    s32 sp1F0;
    s32 sp1E0;
    s32 sp1D0;
    s32 sp1C0;
    s32 sp1B0;
    s32 sp1A0;
    s64 sp190;
    s32 sp180;
    s32 sp170;
    s32 sp160;
    s32 sp150;
    s32 sp140;
    s32 sp130;
    s32 sp120;
    s32 sp110;
    s8 *hitMotion;
    s32 spF0;
    s16 *hpTransfer;
    s16 spD0;
    s32 spC0;
    u16 var_17_5;
    s32 var_30;
    f32 temp_f2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f20;
    f32 var_f20_2;
    s32 temp_2_3;
    s32 temp_2_95;
    s16 temp_21_2;
    s32 temp_2_2;
    s16 temp_3_16;
    s16 temp_5_4;
    s32 var_17;
    u16 var_18_3;
    s32 var_2_14;
    s16 var_2_17;
    s32 var_2_5;
    s32 var_2_6;
    s32 *temp_2_108;
    s32 temp_21;
    s32 temp_22_2;
    s32 temp_2_78;
    s32 temp_30;
    u8 *temp_30_ptr;
    s64 temp_3_6;
    s32 temp_4_13;
    s32 temp_4_14;
    s32 temp_4_15;
    s32 temp_4_4;
    s32 var_21;
    s32 var_2;
    s32 var_2_13;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_7;
    s32 var_2_8;
    s32 *temp_18;
    s32 *temp_22_3;
    s32 *temp_2_57;
    s32 *temp_2_64;
    s32 *var_21_2;
    s32 *var_6;
    s64 temp_16;
    s64 temp_18_2;
    s32 temp_19;
    s16 temp_22;
    s64 temp_23_2;
    s32 temp_2_26;
    s16 temp_3;
    s16 temp_3_13;
    s16 temp_3_14;
    s16 temp_3_15;
    s16 temp_3_17;
    s16 temp_3_5;
    s64 var_17_3;
    s64 var_18;
    s64 var_18_2;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_2;
    s8 temp_23;
    u16 temp_2_97;
    u16 temp_3_21;
    u16 temp_3_2;
    u16 temp_4;
    u32 temp_4_18;
    u8 temp_3_19;
    s32 var_5;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_2_100;
    u8 *temp_2_101;
    u8 *temp_2_102;
    u8 *temp_2_103;
    u8 *temp_2_104;
    u8 *temp_2_105;
    u8 *temp_2_106;
    u8 *temp_2_107;
    u8 *temp_2_109;
    u8 *temp_2_10;
    u8 *temp_2_110;
    u8 *temp_2_111;
    u8 *temp_2_112;
    u8 *temp_2_113;
    u8 *temp_2_114;
    u8 *temp_2_115;
    u8 *temp_2_116;
    u8 *temp_2_117;
    u8 *temp_2_118;
    u8 *temp_2_119;
    u8 *temp_2_11;
    u8 *temp_2_120;
    u8 *temp_2_121;
    u8 *temp_2_122;
    u8 *temp_2_123;
    u8 *temp_2_124;
    u8 *temp_2_125;
    u8 *temp_2_126;
    u8 *temp_2_127;
    u8 *temp_2_128;
    u8 *temp_2_129;
    u8 *temp_2_12;
    u8 *temp_2_130;
    u8 *temp_2_131;
    u8 *temp_2_132;
    u8 *temp_2_133;
    u8 *temp_2_134;
    u8 *temp_2_135;
    u8 *temp_2_136;
    u8 *temp_2_137;
    u8 *temp_2_138;
    u8 *temp_2_139;
    u8 *temp_2_13;
    u8 *temp_2_140;
    u8 *temp_2_141;
    u8 *temp_2_142;
    u8 *temp_2_143;
    u8 *temp_2_144;
    u8 *temp_2_145;
    u8 *temp_2_146;
    u8 *temp_2_147;
    u8 *temp_2_148;
    u8 *temp_2_149;
    u8 *temp_2_14;
    u8 *temp_2_150;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_27;
    u8 *temp_2_28;
    u8 *temp_2_29;
    u8 *temp_2_30;
    u8 *temp_2_31;
    u8 *temp_2_32;
    u8 *temp_2_33;
    u8 *temp_2_34;
    u8 *temp_2_35;
    u8 *temp_2_36;
    u8 *temp_2_37;
    u8 *temp_2_38;
    u8 *temp_2_39;
    u8 *temp_2_40;
    u8 *temp_2_41;
    u8 *temp_2_42;
    u8 *temp_2_43;
    u8 *temp_2_44;
    u8 *temp_2_45;
    u8 *temp_2_46;
    u8 *temp_2_47;
    u8 *temp_2_48;
    u8 *temp_2_49;
    u8 *temp_2_4;
    u8 *temp_2_50;
    u8 *temp_2_51;
    u8 *temp_2_52;
    u8 *temp_2_53;
    u8 *temp_2_54;
    u8 *temp_2_55;
    u8 *temp_2_56;
    u8 *temp_2_58;
    u8 *temp_2_59;
    u8 *temp_2_5;
    u8 *temp_2_60;
    u8 *temp_2_61;
    u8 *temp_2_62;
    u8 *temp_2_63;
    u8 *temp_2_65;
    u8 *temp_2_66;
    u8 *temp_2_67;
    u8 *temp_2_68;
    u8 *temp_2_69;
    u8 *temp_2_6;
    u8 *temp_2_70;
    u8 *temp_2_71;
    u8 *temp_2_72;
    u8 *temp_2_73;
    u8 *temp_2_74;
    u8 *temp_2_75;
    u8 *temp_2_76;
    u8 *temp_2_77;
    u8 *temp_2_79;
    u8 *temp_2_7;
    u8 *temp_2_80;
    u8 *temp_2_81;
    u8 *temp_2_82;
    u8 *temp_2_83;
    u8 *temp_2_84;
    u8 *temp_2_85;
    u8 *temp_2_86;
    u8 *temp_2_87;
    u8 *temp_2_88;
    u8 *temp_2_89;
    u8 *temp_2_8;
    u8 *temp_2_90;
    u8 *temp_2_91;
    u8 *temp_2_92;
    u8 *temp_2_93;
    u8 *temp_2_94;
    u8 *temp_2_96;
    u8 *temp_2_98;
    u8 *temp_2_99;
    u8 *temp_2_9;
    u8 *temp_3_10;
    u8 *temp_3_11;
    u8 *temp_3_12;
    u8 *temp_3_18;
    u8 *temp_3_20;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_7;
    u8 *temp_3_8;
    u8 *temp_3_9;
    u8 *temp_4_10;
    u8 *temp_4_11;
    u8 *temp_4_12;
    u8 *temp_4_16;
    u8 *temp_4_17;
    u8 *temp_4_19;
    u8 *temp_4_20;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_5_3;
    u8 *temp_5_5;
    u8 *var_17_2;
    u8 *var_17_4;
    u8 *var_17_6;
    u8 *var_18_4;
    u8 *var_19;
    u8 *var_19_2;
    u8 *var_22;
    u8 *var_2_10;
    u8 *var_2_9;

    temp_2 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
    temp_23 = (s8)((s8)((*( s8 * )((u8 *)(temp_2) + (0xA2)))));
    sp4D0 = (u8 *)((*( u8 ** )((u8 *)(temp_2) + (0xA0C))));
    sp450 = (s16)((*( s16 * )((u8 *)(arg0) + (0x6E))));
    sp4E0 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x38))));
    sp340 = (s32)((s32)((s32)(((*( u16 * )((u8 *)(arg0) + (0x18))) & 0x4000)) != (s32)(0)));
    sp470 = 0;
    sp468 = 0;
    sp3E0 = 0;
    sp3D0 = 0;
    sp370 = 0;
    sp420 = 0;
    sp3F0 = 0;
    var_21 = 0;
    sp320 = 0;
    sp310 = 0;
    sp30C = 0;
    sp2F0 = 0;
    sp2E0 = 0;
    sp2D0 = 0;
    sp2C0 = 0;
    sp2B0 = 0;
    sp230 = (s32)((s32)(s32)((s32)((*( s32 ** )((u8 *)(arg0) + (0x88)))) != (s32)(0)));
    sp220 = (s32)((s32)(func_001f2f90(arg0)) == (s32)(0));
    sp350 = 6;
    temp_2_2 = sp450;
    sp210 = (s32)((s32)(s32)((s32)((*((u8 *)(((s32)iGpffffb3b8) + (temp_2_2 * 0x28))) & 2)) != (s32)(0)));
    temp_2_3 = (s32)((s32)(s32)((s32)(((*( u16 * )((u8 *)(arg0) + (0x1A))) & 0x10)) != (s32)(0)));
    sp200 = temp_2_3;
    if ((s32)(s32)temp_2_3 != 0) {
        sp200 = (s32)sp210 == 0;
    }
    sp1F0 = (s32)((s32)(s32)((*( u16 * )((u8 *)(arg0) + (0x6C))) == 3));
    sp33C = (s32)((s32)(func_001f0ff0(arg0)));
    sp1E0 = (s32)(func_001f11e0(sp450));
    sp1D0 = (s32)((s32)(s32)((s32)((*( u8 ** )((u8 *)(arg0) + (0x8C)))) != (s32)(0)));
    sp4C4 = 0;
    temp_16 = (s64)((s64)(s64)((*( s64 * )((u8 *)(arg0) + (0)))));
    func_001a03b0(arg0);
    temp_23_2 = (s8)temp_23;
    if ((temp_23_2 == 1) && ((*( s32 * )((u8 *)(iGpffffb3ac) + (0xC))) & 0x200000)) {
        sp340 = 0;
    }
    if (sp340 == 0) {
        sp4A0 = (s32)(func_001d3d50(1));
    } else {
        temp_3 = (s16)func_0023d8e0(NULL, (u16)sp450);
        switch (temp_3) {                           /* switch 1; irregular */
        case 16:                                    /* switch 1 */
            sp4A0 = (s32)((s32)((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD9C)))));
            break;
        case 17:                                    /* switch 1 */
            sp4A0 = (s32)((s32)((*( s32 * )((u8 *)(iGpffffb3ac) + (0xDA0)))));
            break;
        default:                                    /* switch 1 */
            sp4A0 = (s32)((s32)((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD98)))));
            break;
        }
    }
    temp_4 = (u16)((u16)((*( u16 * )((u8 *)(arg0) + (0x1A)))));
    if (!(temp_4 & 1)) {
        var_2 = 0;
    } else if (!(temp_4 & 0x10)) {
        var_2 = 0;
    } else if ((*( s32 * )((u8 *)((*( u8 ** )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA0C)))) + (0x98))) & 2) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if (var_2 != 0) {
        sp2B0 = 1;
    }
    sp1C0 = (s32)((s32)(s32)(func_00230020(arg0)));
    if (temp_23_2 >= 0) {
        if (sp2B0 != 0) {
            var_30 = 0x1002;
        } else {
            var_30 = 0;
        }
        if (sp33C != 0) {
            temp_2_4 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)((*( s32 ** )((u8 *)(arg0) + (0x38)))) + (0x30))), var_30));
            (*( s64 * )((u8 *)(temp_2_4) + (0x60))) = temp_16;
            func_00194590(temp_2_4, 0);
        } else if (temp_23_2 == 0) {
            func_00196040(func_001eb440((s32)(arg0) + 0x38) & 0xFFFF, 1, &targetPosition, 0, 0, 1);
            temp_2_5 = (u8 *)(btlUnitCreateRotatePacket((*( BtlUnit ** )((u8 *)(arg0) + (0x30))), &targetPosition, var_30));
            (*( s64 * )((u8 *)(temp_2_5) + (0x60))) = temp_16;
            func_00194590(temp_2_5, 0);
        } else {
            temp_4_2 = (u8 *)(iGpffffb3ac);
            if ((*( s32 * )((u8 *)(temp_4_2) + (0xC))) & 0x200000) {
                func_001958f0((*( BtlUnit ** )((u8 *)((*( u8 ** )((u8 *)(temp_4_2) + (0x170)))) + (0x30))), &targetPosition);
                temp_2_6 = (u8 *)(btlUnitCreateRotatePacket((*( BtlUnit ** )((u8 *)(arg0) + (0x30))), &targetPosition, var_30));
                (*( s64 * )((u8 *)(temp_2_6) + (0x60))) = temp_16;
                func_00194590(temp_2_6, 0);
            }
        }
        if ((s32)(s32)sp1C0 != 0) {
            temp_2_7 = (u8 *)(actionLookAtUnit(0, (*( u8 ** )((u8 *)(arg0) + (0x30))), 3));
            *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_7, 1);
            temp_2_8 = (u8 *)(btlUnitCreateLookAtDeactivatePacket((*( u8 ** )((u8 *)(arg0) + (0x30))), 0));
            *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_8, 1);
        } else {
            temp_2_9 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            *(s64 *)(temp_2_9 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_9, 1);
        }
        (*( u16 * )((u8 *)(arg0) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(arg0) + (0x18))) | 0x200));
        temp_2_10 = (u8 *)(func_001f3b20(arg0));
        (*( s64 * )((u8 *)(temp_2_10) + (0x60))) = temp_16;
        func_00194590(temp_2_10, 1);
    }
    temp_30 = temp_2_2 * 4;
    temp_30_ptr = (u8 *)(((s32)iGpffffb3bc) + temp_30);
    if ((*( u16 * )(temp_30_ptr + (2))) & 0x100) {
        var_2_2 = 3;
    } else {
        var_2_2 = 1;
    }
    sp1B0 = (s16)var_2_2;
    if ((s32)(s32)sp1F0 == 0) {
        temp_2_11 = (u8 *)(func_00202010((*( u8 ** )((u8 *)(arg0) + (0x30))), (u16) sp450));
        (*( s16 * )((u8 *)(temp_2_11) + (0x48))) = (s16) sp1B0;
        (*( s64 * )((u8 *)(temp_2_11) + (0x60))) = temp_16;
        func_00194590(temp_2_11, 3);
    } else {
        temp_2_12 = (u8 *)(func_00202120((*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u16 * )((u8 *)(arg0) + (0x70)))));
        (*( s16 * )((u8 *)(temp_2_12) + (0x48))) = (s16) sp1B0;
        (*( s64 * )((u8 *)(temp_2_12) + (0x60))) = temp_16;
        func_00194590(temp_2_12, 3);
    }
    if ((s32)(s32)sp200 == 1) {
        if (((s32)(s32)sp1F0 == 0) && ((s32)(s32)sp220 == 0)) {
            if (((s32)(s32)sp1D0 == 0) && (sp2B0 == 0)) {
                if (temp_23_2 == 0) {
                    if (!((*( u16 * )((u8 *)(arg0) + (0x18))) & 0x40) && ((((s32)(func_001f0af0(arg0)) != (s32)(0)) && ((s32)(func_00231d70(0x64U)) < (s32)(0x14U))) || ((*( s32 * )((u8 *)(iGpffffb3ac) + (0x10))) & 0x1000))) {
                        var_21 = 1;
                        (*( u16 * )((u8 *)(arg0) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(arg0) + (0x18))) | 0x40));
                        temp_4_3 = (u8 *)(iGpffffb3ac);
                        (*( s32 * )((u8 *)(temp_4_3) + (0x10))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_3) + (0x10))) & ~0x1000));
                    }
                } else if ((temp_23_2 == 1) && ((*( s64 * )((u8 *)(iGpffffb3ac) + (0x10))) & 0x800)) {
                    temp_3_2 = (u16)((u16)((*( u16 * )((u8 *)(arg0) + (0x18)))));
                    if (!(temp_3_2 & 0x40)) {
                        var_21 = 1;
                        (*( u16 * )((u8 *)(arg0) + (0x18))) = (u16) (temp_3_2 | 0x40);
                    }
                }
            }
            sp280 = sp450;
            sp1A0 = ((s16)func_0023d8e0(NULL, (u16)sp280) == 0x10);
            if ((s32)(func_0022d540(arg0, (u8 *)effectHandles)) == (s32)(0)) {
                temp_3_3 = (u8 *)(iGpffffb3ac);
                effectHandles[0] = (*(s32 *)((u8 *)temp_3_3 + 0xD30));
                effectHandles[1] = (*(s32 *)((u8 *)temp_3_3 + 0xD34));
                effectHandles[2] = (*(s32 *)((u8 *)temp_3_3 + 0xD38));
            }
            if (((s32)(func_001f11e0(sp450)) == (s32)(0)) && ((s32)(func_001f0b90(arg0)) == (s32)(0))) {
                temp_4_4 = (s32)((s32)(func_001eb440((s32)(arg0) + 0x38) & 0xFFFF));
                if ((temp_23_2 == 0) && ((temp_4_4 & 0xFFFF) == 2)) {
                    sp320 = (s32)((s32)((effMiscRand(0) & 1)) != (s32)(0));
                } else if ((temp_23_2 == 1) && ((temp_4_4 & 0xFFFF) == 1)) {
                    sp320 = 1;
                }
            }
            if (((s32)(func_0022f950(arg0, sp4D0)) != (s32)(0)) || ((*( s32 * )((u8 *)(iGpffffb3ac) + (0x10))) & 0x40)) {
                sp320 = 1;
            }
            if ((*( u16 * )(temp_30_ptr + (2))) & 0x4000) {
                sp320 = 1;
                sp3F0 = 2;
            }
            if ((temp_23_2 == 0) && ((s64)(func_001f1030(arg0)) != (s64)(0)) && (temp_2_2 != 0xF4)) {
                sp2D0 = 1;
                sp320 = 1;
                var_21 = 0;
                temp_2_13 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                *(s64 *)(temp_2_13 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_13, 1);
                temp_4_5 = (u8 *)(iGpffffb3ac);
                (*( s32 * )((u8 *)(temp_4_5) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_5) + (0xC))) | 0x400000));
                temp_3_4 = (u8 *)(iGpffffb3ac);
                (*( u16 * )((u8 *)(temp_3_4) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_4) + (0x18))) | 6));
            }
            temp_3_5 = (s16)func_00198810(*(u8 **)(arg0 + 0x30));
            if ((temp_3_5 != 0x11) && (temp_3_5 != 0)) {
                var_18_2 = 6;
            } else {
                var_18_2 = 0;
            }
            if (var_21 != 0) {
                func_00194590((u8 *)func_001f8330((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30)))), 0);
            } else if ((s32)(s32)sp1A0 != 0) {
                func_00194590(func_001f83b0((*( u8 ** )((u8 *)(arg0) + (0x30)))), 0);
            }
            if (sp2B0 != 0) {
                var_17_2 = (u8 *)(func_00194b60());
            } else {
                var_17_2 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), 0xD, var_18_2 & 0xFFFF, 1.0f, 4));
            }
            (*( s64 * )((u8 *)(var_17_2) + (0x60))) = temp_16;
            func_00194590(var_17_2, 0);
            var_17_3 = *(s64 *)(var_17_2 + 0x58);
            if (sp2B0 == 0) {
                var_18_3 = (s16)(func_00199500(*(u8 **)(arg0 + 0x30), 0xD, 1.0f) + (s16)var_18_2);
            } else {
                var_18_3 = 0;
            }
            if (sp2B0 != 0) {
                var_19_2 = (u8 *)(func_00194b60());
            } else {
                if (temp_23_2 == 0) {
                    var_2_3 = 0x14;
                } else {
                    var_2_3 = 0x15;
                }
                var_19_2 = (u8 *)(btlCameraCreateSetStatePacket(arg0, var_2_3 & 0xFFFF));
            }
            (*( s64 * )((u8 *)(var_19_2) + (0x60))) = temp_16;
            func_00194590(var_19_2, 0);
            sp490 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_19_2) + (0x58)))));
            if (var_21 != 0) {
                cutin.mode = 4;
                cutin.unitId = (u16)((u16)((*( u16 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA4)))));
                temp_2_14 = (u8 *)(func_001fa110((u8 *)&cutin));
                (*( s8 * )((u8 *)(temp_2_14) + (0))) = 4;
                *(s64 *)(temp_2_14 + 8) = var_17_3;
                (*( s64 * )((u8 *)(temp_2_14) + (0x60))) = temp_16;
                func_00194590(temp_2_14, 1);
                temp_2_15 = func_001fa320();
                (*( s8 * )((u8 *)(temp_2_15) + (0))) = 4;
                *(s64 *)(temp_2_15 + 8) = *(s64 *)(temp_2_14 + 0x58);
                (*( s64 * )((u8 *)(temp_2_15) + (0x60))) = temp_16;
                func_00194590(temp_2_15, 1);
                temp_2_16 = (u8 *)(func_001f99c0(arg0, 1, (*( u16 * )((u8 *)(sp4D0) + (0xA4))), 0, 1));
                (*( s8 * )((u8 *)(temp_2_16) + (0))) = 5;
                *(s64 *)(temp_2_16 + 8) = *(s64 *)(temp_2_15 + 0x58);
                (*( s64 * )((u8 *)(temp_2_16) + (0x60))) = temp_16;
                func_00194590(temp_2_16, 1);
                temp_2_17 = (u8 *)(func_001f7c20(0xA, 2, 0xB));
                (*( s8 * )((u8 *)(temp_2_17) + (0))) = 5;
                *(s64 *)(temp_2_17 + 8) = *(s64 *)(temp_2_15 + 0x58);
                *(s64 *)(temp_2_17 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_17, 1);
                var_17_3 = *(s64 *)(temp_2_15 + 0x58);
                sp468 = var_17_3;
                var_18_3 = 0;
            }
            temp_2_18 = (u8 *)(func_001d2d90(arg0,(s32)(((*( u16 * )((u8 *)(arg0) + (0x18))) & 0x10)) != (s32)(0), 1));
            (*( s8 * )((u8 *)(temp_2_18) + (0))) = 4;
            *(s64 *)(temp_2_18 + 8) = var_17_3;
            (*( s16 * )((u8 *)(temp_2_18) + (0x48))) = (s16) (var_18_3 - (var_18_3 >> 3));
            (*( s64 * )((u8 *)(temp_2_18) + (0x60))) = temp_16;
            func_00194590(temp_2_18, 0);
            sp470 = (s64)((s64)(s64)((*( s64 * )((u8 *)(temp_2_18) + (0x58)))));
            if (sp33C != 0) {
                var_6 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x38))));
            } else {
                var_6 = 0;
            }
            temp_2_19 = (u8 *)(func_001d3000(sp4D0, arg0, var_6, (u16) sp280));
            (*( s8 * )((u8 *)(temp_2_19) + (0))) = 5;
            (*( s64 * )((u8 *)(temp_2_19) + (8))) = sp470;
            (*( s64 * )((u8 *)(temp_2_19) + (0x60))) = temp_16;
            func_00194590(temp_2_19, 0);
            if (sp2B0 == 0) {
                if (var_21 != 0) {
                    temp_2_20 = (u8 *)(func_0019b550(sp4D0, (*( u16 * )((u8 *)(sp4D0) + (0xA4))), 0x1D));
                    var_17_4 = (u8 *)(temp_2_20);
                    (*( s8 * )((u8 *)(temp_2_20) + (0))) = 5;
                    *(s64 *)(temp_2_20 + 8) = sp468;
                    (*( s8 * )((u8 *)(temp_2_20) + (0x20))) = 5;
                    (*( s64 * )((u8 *)(temp_2_20) + (0x28))) = sp470;
                } else {
                    temp_2_21 = (u8 *)(func_0019b550(sp4D0, (*( u16 * )((u8 *)(sp4D0) + (0xA4))), 0xD));
                    var_17_4 = (u8 *)(temp_2_21);
                    (*( s16 * )((u8 *)(temp_2_21) + (0x48))) = var_18_3;
                }
                (*( s64 * )((u8 *)(var_17_4) + (0x60))) = temp_16;
                func_00194590(var_17_4, 1);
            } else {
                temp_2_22 = (u8 *)(func_00194b60());
                var_17_4 = (u8 *)(temp_2_22);
                (*( s16 * )((u8 *)(temp_2_22) + (0x48))) = var_18_3;
                func_00194590(var_17_4, 0);
            }
            temp_2_23 = (u8 *)(func_00194b60());
            (*( s8 * )((u8 *)(temp_2_23) + (0))) = 4;
            *(s64 *)(temp_2_23 + 8) = *(s64 *)(var_17_4 + 0x58);
            (*( s16 * )((u8 *)(temp_2_23) + (0x48))) = 0xC;
            (*( s64 * )((u8 *)(temp_2_23) + (0x60))) = temp_16;
            func_00194590(temp_2_23, 1);
            temp_2_24 = (u8 *)(func_001d65d0(effectHandles[0], (*(s32 *)(arg0 + 0x30)), 0, (*(s64 *)(temp_2_23 + 0x58)), 0x100));
            (*( s64 * )((u8 *)(temp_2_24) + (0x60))) = temp_16;
            func_00194590(temp_2_24, 2);
            temp_2_25 = (u8 *)(func_001f7c20(0xA, 2, 3));
            (*( s64 * )((u8 *)(temp_2_25) + (0x60))) = temp_16;
            func_00194590(temp_2_25, 1);
            temp_5 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
            temp_22 = (s16)func_00199d00(*(s32 *)(temp_5 + 0xA0C), temp_5, sp450, sp33C);
            temp_2_26 = (s32)(func_001991c0((*( u8 ** )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA0C))), temp_22 & 0xFFFF, 1.0f));
            sp400 = (s32) temp_2_26;
            sp350 = (u16)((u16)(func_001996d0((*( u8 ** )((u8 *)(arg0) + (0x30))), 0x10)));
            var_18 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_17_4) + (0x58)))));
            temp_3_6 = temp_2_26 + 0x12;
            if (sp3F0 < temp_3_6) {
                var_17 = temp_3_6 - sp3F0;
            } else {
                var_17 = 0;
            }
            temp_2_27 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), 0xF, 0, 1.0f, 5));
            (*( s8 * )((u8 *)(temp_2_27) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_27) + (8))) = var_18;
            (*( s64 * )((u8 *)(temp_2_27) + (0x60))) = temp_16;
            func_00194590(temp_2_27, 0);
            if (var_21 != 0) {
                temp_2_28 = (u8 *)(func_001f82b0((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30)))));
                (*( s8 * )((u8 *)(temp_2_28) + (0))) = 4;
                *(s64 *)(temp_2_28 + 8) = *(s64 *)(temp_2_27 + 0x58);
                (*( s64 * )((u8 *)(temp_2_28) + (0x60))) = temp_16;
                func_00194590(temp_2_28, 0);
            } else if ((s32)(s32)sp1A0 != 0) {
                temp_2_29 = (u8 *)(func_001f8430((*( u8 ** )((u8 *)(arg0) + (0x30)))));
                (*( s8 * )((u8 *)(temp_2_29) + (0))) = 4;
                *(s64 *)(temp_2_29 + 8) = *(s64 *)(temp_2_27 + 0x58);
                (*( s64 * )((u8 *)(temp_2_29) + (0x60))) = temp_16;
                func_00194590(temp_2_29, 0);
            }
            temp_19 = (s32)(func_001991c0((*( u8 ** )((u8 *)(arg0) + (0x30))), 0xFU, 1.0f));
            temp_2_30 = (u8 *)(func_001d65d0(effectHandles[1], (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
            (*( s8 * )((u8 *)(temp_2_30) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_30) + (8))) = var_18;
            (*( s16 * )((u8 *)(temp_2_30) + (0x48))) = (s16) temp_19;
            (*( s64 * )((u8 *)(temp_2_30) + (0x60))) = temp_16;
            func_00194590(temp_2_30, 2);
            temp_2_31 = (u8 *)(func_001f7c20(0xC, 2, 4));
            (*( s8 * )((u8 *)(temp_2_31) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_31) + (8))) = var_18;
            (*( s16 * )((u8 *)(temp_2_31) + (0x48))) = (s16)((s16)temp_19 + 2);
            (*( s64 * )((u8 *)(temp_2_31) + (0x60))) = temp_16;
            func_00194590(temp_2_31, 1);
            temp_2_32 = (u8 *)(func_001d65d0(effectHandles[2], (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
            (*( s8 * )((u8 *)(temp_2_32) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_32) + (8))) = var_18;
            (*( s64 * )((u8 *)(temp_2_32) + (0x60))) = temp_16;
            func_00194590(temp_2_32, 2);
            temp_2_33 = (u8 *)(func_0019bbe0((*( u8 ** )((u8 *)(arg0) + (0x30))), 0xFF808080, 0, 0xC, 4, 0));
            (*( s8 * )((u8 *)(temp_2_33) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_33) + (8))) = var_18;
            (*( s64 * )((u8 *)(temp_2_33) + (0x60))) = temp_16;
            func_00194590(temp_2_33, 1);
            temp_2_34 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)sp4D0, temp_22, 0, 1.0f, 2));
            var_19 = (u8 *)(temp_2_34);
            (*( s8 * )((u8 *)(temp_2_34) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_34) + (8))) = var_18;
            (*( s16 * )((u8 *)(temp_2_34) + (0x48))) = 0xF;
            (*( s64 * )((u8 *)(temp_2_34) + (0x60))) = temp_16;
            func_00194590(var_19, 0);
            temp_2_35 = (u8 *)(func_0019bbe0(sp4D0, func_00195530(sp4D0), 8, 0, 3, 1));
            (*( s8 * )((u8 *)(temp_2_35) + (0))) = 4;
            *(s64 *)(temp_2_35 + 8) = *(s64 *)(var_19 + 0x58);
            (*( s64 * )((u8 *)(temp_2_35) + (0x60))) = temp_16;
            func_00194590(temp_2_35, 1);
            temp_2_36 = (u8 *)(func_001f7c20(0xD, 2, 5));
            (*( s8 * )((u8 *)(temp_2_36) + (0))) = 4;
            *(s64 *)(temp_2_36 + 8) = *(s64 *)(var_19 + 0x58);
            (*( s64 * )((u8 *)(temp_2_36) + (0x60))) = temp_16;
            func_00194590(temp_2_36, 1);
            if ((sp320 == 1) && (sp2D0 == 0) && !((*( u16 * )(temp_30_ptr + (2))) & 0x40)) {
                if (temp_23_2 == 0) {
                    var_2_4 = 0x19;
                } else {
                    var_2_4 = 0x1A;
                }
                temp_2_37 = (u8 *)(btlCameraCreateSetStatePacket(arg0, var_2_4 & 0xFFFF));
                (*( s8 * )((u8 *)(temp_2_37) + (0))) = 4;
                *(s64 *)(temp_2_37 + 8) = *(s64 *)(var_19 + 0x58);
                if (sp400 >= sp3F0) {
                    var_2_5 = sp400 - sp3F0;
                } else {
                    var_2_5 = 0;
                }
                (*( s16 * )((u8 *)(temp_2_37) + (0x48))) = var_2_5;
                (*( s64 * )((u8 *)(temp_2_37) + (0x60))) = temp_16;
                func_00194590(temp_2_37, 0);
            }
            sp480 = *(s64 *)(var_19 + 0x58);
        } else if (((s32)(s32)sp1F0 == 1) || ((s32)(s32)sp220 == 1)) {
            if ((temp_23_2 == 0) && ((s64)(func_001f1030(arg0)) != (s64)(0)) && (temp_2_2 != 0xF4)) {
                sp2D0 = 1;
                sp320 = 1;
                temp_2_38 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                *(s64 *)(temp_2_38 + 0x60) = *(s64 *)arg0;
                func_00194590(temp_2_38, 1);
                temp_4_6 = (u8 *)(iGpffffb3ac);
                (*( s32 * )((u8 *)(temp_4_6) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_6) + (0xC))) | 0x400000));
                temp_3_7 = (u8 *)(iGpffffb3ac);
                (*( u16 * )((u8 *)(temp_3_7) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_7) + (0x18))) | 6));
            }
            temp_2_39 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), 0x16, 6, 1.0f, 0));
            var_19 = (u8 *)(temp_2_39);
            (*( s64 * )((u8 *)(temp_2_39) + (0x60))) = temp_16;
            func_00194590(var_19, 0);
            sp490 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_19) + (0x58)))));
                    var_17 = (s16)((func_001991c0((*( u8 ** )((u8 *)(arg0) + (0x30))), 0x16U, 1.0f)) + 6);
            if (!((*( u16 * )(temp_30_ptr + (2))) & 0x40)) {
                if ((s32)(func_001f0ff0(arg0)) == (s32)(1)) {
                    temp_2_40 = (u8 *)(func_001d2d90(arg0, 0, 1));
                    (*( s8 * )((u8 *)(temp_2_40) + (0))) = 4;
                    *(s64 *)(temp_2_40 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_40) + (0x60))) = temp_16;
                    func_00194590(temp_2_40, 0);
                }
                if (sp320 == 0) {
                    temp_2_41 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x19));
                    (*( s8 * )((u8 *)(temp_2_41) + (0))) = 4;
                    *(s64 *)(temp_2_41 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_41) + (0x60))) = temp_16;
                    func_00194590(temp_2_41, 0);
                } else {
                    temp_2_42 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1B));
                    (*( s8 * )((u8 *)(temp_2_42) + (0))) = 4;
                    *(s64 *)(temp_2_42 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_42) + (0x60))) = temp_16;
                    func_00194590(temp_2_42, 0);
                }
            }
            if ((s32)(s32)sp220 == 0) {
                temp_2_43 = (u8 *)(func_001d65d0((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD88))), (*(s32 *)(arg0 + 0x30)), var_17 + 6, 0, 0x100));
                (*( s8 * )((u8 *)(temp_2_43) + (0))) = 4;
                *(s64 *)(temp_2_43 + 8) = *(s64 *)(var_19 + 0x58);
                func_00194590(temp_2_43, 1);
            }
        }
    } else if (((s64)(s64)sp200 == 0) && (temp_23_2 == 1)) {
        sp30C = 1;
        if ((s32)(func_0022f8b0(arg0, temp_2_2)) != (s32)(0)) {
            sp2D0 = 1;
            var_21 = 0;
            temp_2_44 = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            *(s64 *)(temp_2_44 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_44, 1);
            temp_4_7 = (u8 *)(iGpffffb3ac);
            (*( s32 * )((u8 *)(temp_4_7) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_7) + (0xC))) | 0x400000));
            temp_3_8 = (u8 *)(iGpffffb3ac);
            (*( u16 * )((u8 *)(temp_3_8) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_8) + (0x18))) | 6));
        }
        if (sp340 == 0) {
            var_f20 = 1.0f;
        } else {
            var_f20 = 2.0f;
            sp2C0 = 1;
            temp_4_8 = (u8 *)(iGpffffb3ac);
            (*( s32 * )((u8 *)(temp_4_8) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_8) + (0xC))) | 0x400000));
            temp_3_9 = (u8 *)(iGpffffb3ac);
            (*( u16 * )((u8 *)(temp_3_9) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_9) + (0x18))) | 0x47));
        }
        if (((s32)(s32)sp210 == 1) || ((s32)(func_001f11e0(sp450)) != (s32)(0))) {
            sp430 = 4;
            var_17_5 = 2;
        } else {
            sp430 = 8;
            var_17_5 = 3;
        }
        if ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))) == (s32)(1)) {
            if ((s32)(func_0022e4f0(arg0, temp_2_2)) != (s32)(0)) {
                var_17_5 = 2;
                sp30C = 0;
                sp2C0 = 1;
                temp_4_9 = (u8 *)(iGpffffb3ac);
                (*( s32 * )((u8 *)(temp_4_9) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_9) + (0xC))) | 0x400000));
                temp_3_10 = (u8 *)(iGpffffb3ac);
                (*( u16 * )((u8 *)(temp_3_10) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_10) + (0x18))) | 7));
            } else if ((*( s16 * )((u8 *)((((*( u16 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA4))) * 0xE8) + ((s32)iGpffffb3cc))) + (0x18))) & 1) {
                var_17_5 = 0;
                sp2F0 = 1;
                sp30C = 0;
            }
        }
        if (!((*( u16 * )(temp_30_ptr + (2))) & 0x100)) {
            if ((s32)(func_0022fa90(arg0, sp430)) != (s32)(0)) {
                temp_2_45 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), (s32) sp430, 6, var_f20, var_17_5));
                var_19 = (u8 *)(temp_2_45);
                (*( s64 * )((u8 *)(temp_2_45) + (0x60))) = temp_16;
                func_00194590(var_19, 0);
            } else {
                temp_2_46 = (u8 *)(func_00194b60());
                var_19 = (u8 *)(temp_2_46);
                (*( s64 * )((u8 *)(temp_2_46) + (0x60))) = temp_16;
                func_00194590(var_19, 0);
            }
            if ((sp340 == 0) && ((s32)(func_0022fd30(arg0, temp_2_2)) != (s32)(0))) {
                temp_2_47 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x15));
                (*( s8 * )((u8 *)(temp_2_47) + (0))) = 4;
                *(s64 *)(temp_2_47 + 8) = *(s64 *)(var_19 + 0x58);
                (*( s64 * )((u8 *)(temp_2_47) + (0x60))) = temp_16;
                func_00194590(temp_2_47, 0);
            }
        } else {
            temp_2_48 = (u8 *)(func_00194b60());
            var_19 = (u8 *)(temp_2_48);
            (*( s64 * )((u8 *)(temp_2_48) + (0x60))) = temp_16;
            func_00194590(var_19, 0);
        }
        sp490 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_19) + (0x58)))));
            var_17 = (s16)((func_001991c0((*( u8 ** )((u8 *)(arg0) + (0x30))), (u16) sp430, var_f20)) + 6);
        if (!((*( u16 * )(temp_30_ptr + (2))) & 0x40) && (sp2D0 == 0)) {
            temp_2_49 = (u8 *)(func_001d2d90(arg0,(s32)(((*( u16 * )((u8 *)(arg0) + (0x18))) & 0x10)) != (s32)(0), 1));
            (*( s8 * )((u8 *)(temp_2_49) + (0))) = 4;
            *(s64 *)(temp_2_49 + 8) = *(s64 *)(var_19 + 0x58);
            if (sp340 == 0) {
                if (var_17 > 0xc) {
                    var_2_6 = var_17 - 0xC;
                } else {
                    var_2_6 = 0;
                }
                (*( s16 * )((u8 *)(temp_2_49) + (0x48))) = var_2_6;
            }
            (*( s64 * )((u8 *)(temp_2_49) + (0x60))) = temp_16;
            func_00194590(temp_2_49, 0);
            sp470 = (s64)((s64)(s64)((*( s64 * )((u8 *)(temp_2_49) + (0x58)))));
            temp_2_50 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1A));
            (*( s8 * )((u8 *)(temp_2_50) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_50) + (8))) = sp470;
            (*( s64 * )((u8 *)(temp_2_50) + (0x60))) = temp_16;
            func_00194590(temp_2_50, 0);
        }
        if (((s32)(s32)sp210 == 0) && ((s32)(s32)sp220 == 0)) {
            var_2_7 = (s32)((s32)(func_0022d200(arg0)));
            if (var_2_7 == 0) {
                var_2_7 = (s32)((s32)((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD40)))));
            }
            temp_2_51 = (u8 *)(func_001d65d0(var_2_7, (*(s32 *)(arg0 + 0x30)), var_17 + 6, 0, 0x100));
            (*( s8 * )((u8 *)(temp_2_51) + (0))) = 4;
            *(s64 *)(temp_2_51 + 8) = *(s64 *)(var_19 + 0x58);
            func_00194590(temp_2_51, 1);
            temp_2_52 = (u8 *)(func_001f7c20(0xA, 2, 7));
            (*( s8 * )((u8 *)(temp_2_52) + (0))) = 4;
            *(s64 *)(temp_2_52 + 8) = *(s64 *)(var_19 + 0x58);
            func_00194590(temp_2_52, 1);
        }
    } else if (((s64)(s64)sp200 == 0) && (temp_23_2 == 0)) {
        sp2C0 = 1;
        temp_2_53 = (u8 *)(func_001d65d0((*( s32 * )((u8 *)(iGpffffb3ac) + (0xDB8))), (*(s32 *)(arg0 + 0x30)), 0, 0, 0x100));
        (*( s64 * )((u8 *)(temp_2_53) + (0x60))) = temp_16;
        func_00194590(temp_2_53, 2);
        temp_17 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), 6, 0, 1.0f, 2));
        (*( s16 * )((u8 *)(temp_17) + (0x4A))) = (s16)(func_00199500((*( u8 ** )((u8 *)(arg0) + (0x30))), 6, 1.0f));
        (*( s64 * )((u8 *)(temp_17) + (0x60))) = temp_16;
        func_00194590(temp_17, 0);
        temp_2_54 = (u8 *)(func_001f7c20(0xA, 2, 0x11));
        (*( s16 * )((u8 *)(temp_2_54) + (0x48))) = 1;
        (*( s64 * )((u8 *)(temp_2_54) + (0x60))) = temp_16;
        func_00194590(temp_2_54, 1);
        temp_2_55 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x12));
        (*( s64 * )((u8 *)(temp_2_55) + (0x60))) = temp_16;
        func_00194590(temp_2_55, 0);
        temp_2_56 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(arg0) + (0x30))), 7, 6, 1.0f, 2));
        var_19 = (u8 *)(temp_2_56);
        (*( s8 * )((u8 *)(temp_2_56) + (0))) = 4;
        *(s64 *)(temp_2_56 + 8) = *(s64 *)(temp_17 + 0x58);
        (*( s64 * )((u8 *)(temp_2_56) + (0x60))) = temp_16;
        func_00194590(var_19, 0);
        sp490 = 0;
        var_18 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_19) + (0x58)))));
        var_17 = (s16)((func_001991c0((*( u8 ** )((u8 *)(arg0) + (0x30))), 7U, 1.0f)) + 6);
        if ((*( u16 * )((u8 *)(arg0) + (0x6A))) == 1) {
            temp_2_57 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x38))));
            if ((s32)(temp_2_57) != (s32)(0)) {
                temp_2_58 = (u8 *)(func_001d3530((*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(temp_2_57) + (0x30))), 4));
                (*( s8 * )((u8 *)(temp_2_58) + (0))) = 4;
                (*( s64 * )((u8 *)(temp_2_58) + (8))) = var_18;
                (*( s64 * )((u8 *)(temp_2_58) + (0x60))) = temp_16;
                func_00194590(temp_2_58, 0);
            }
        }
        temp_2_59 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x13));
        (*( s8 * )((u8 *)(temp_2_59) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_59) + (8))) = var_18;
        (*( s64 * )((u8 *)(temp_2_59) + (0x60))) = temp_16;
        func_00194590(temp_2_59, 0);
        temp_4_10 = (u8 *)(iGpffffb3ac);
        (*( s32 * )((u8 *)(temp_4_10) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_10) + (0xC))) | 0x400000));
        temp_3_11 = (u8 *)(iGpffffb3ac);
        (*( u16 * )((u8 *)(temp_3_11) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_11) + (0x18))) | 0xF));
    }
    sp270 = sp450;
    func_001b7060((u16) sp270, (u8 *)&sp5AC, (u8 *)&sp5A8);
    temp_2_60 = (u8 *)(func_001b7880(sp5AC, sp5A8, 0x10));
    (*( s8 * )((u8 *)(temp_2_60) + (0))) = 4;
    (*( s64 * )((u8 *)(temp_2_60) + (8))) = sp490;
    (*( s64 * )((u8 *)(temp_2_60) + (0x60))) = temp_16;
    func_00194590(temp_2_60, 1);
    temp_22_2 = (s32)(func_001b7080((u16) sp270));
    func_001b70a0((u16) sp270, (u8 *)&sp5AC, (u8 *)&sp5A8);
    temp_2_61 = (u8 *)(func_001b83f0(temp_22_2, sp5AC, sp5A8, 0x10, ((s32)(((*( u16 * )(temp_30_ptr + (2))) & 2)) != (s32)(0)) & 0xFFFF));
    (*( s8 * )((u8 *)(temp_2_61) + (0))) = 4;
    (*( s64 * )((u8 *)(temp_2_61) + (8))) = sp490;
    (*( s64 * )((u8 *)(temp_2_61) + (0x60))) = temp_16;
    func_00194590(temp_2_61, 1);
    temp_2_62 = (u8 *)(func_001b9560(func_001b7090((u16) sp450), 0x10));
    (*( s8 * )((u8 *)(temp_2_62) + (0))) = 4;
    (*( s64 * )((u8 *)(temp_2_62) + (8))) = sp490;
    (*( s64 * )((u8 *)(temp_2_62) + (0x60))) = temp_16;
    func_00194590(temp_2_62, 1);
    temp_2_63 = (u8 *)(func_001b9de0((BtlAction *)arg0, (u16) sp450, 8));
    (*( s8 * )((u8 *)(temp_2_63) + (0))) = 4;
    (*( s64 * )((u8 *)(temp_2_63) + (8))) = sp490;
    (*( s64 * )((u8 *)(temp_2_63) + (0x60))) = temp_16;
    func_00194590(temp_2_63, 1);
    if ((s32)(s32)sp230 != 0) {
        temp_22_3 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x88))));
        temp_2_64 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x38))));
        sp4E0 = (s32 *)(temp_2_64);
        temp_2_65 = (u8 *)(func_001d3530((*( u8 ** )((u8 *)(temp_22_3) + (0x30))), (*( u8 ** )((u8 *)(temp_2_64) + (0x30))), 2));
        sp4BC = (u8 *)(temp_2_65);
        (*( s8 * )((u8 *)(temp_2_65) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_65) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_65) + (0x48))) = var_17;
        (*( s16 * )((u8 *)(temp_2_65) + (0x4A))) = (s16)((s16) ((func_00199500((*( u8 ** )((u8 *)((s32 *)(u32)temp_22_3) + (0x30))), 0x1A, 1.0f)) - 1));
        (*( s64 * )((u8 *)(temp_2_65) + (0x60))) = temp_16;
        func_00194590(temp_2_65, 0);
        temp_2_66 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1E));
        (*( s8 * )((u8 *)(temp_2_66) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_66) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_66) + (0x48))) = var_17;
        (*( s64 * )((u8 *)(temp_2_66) + (0x60))) = temp_16;
        func_00194590(temp_2_66, 0);
        temp_2_67 = (u8 *)(func_001f99c0((s32 *)(u32)temp_22_3, 0xD, 0U, 0, 0));
        (*( s8 * )((u8 *)(temp_2_67) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_67) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_67) + (0x48))) = var_17;
        (*( s64 * )((u8 *)(temp_2_67) + (0x60))) = temp_16;
        func_00194590(temp_2_67, 1);
        temp_2_68 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(temp_22_3) + (0x30))), 0x1A, 0, 1.0f, 0));
        (*( s8 * )((u8 *)(temp_2_68) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_68) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_68) + (0x48))) = var_17;
        (*( s64 * )((u8 *)(temp_2_68) + (0x60))) = temp_16;
        func_00194590(temp_2_68, 0);
        temp_2_69 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(temp_2_64) + (0x30))), 0x1A, 0, 1.0f, 2));
        (*( s8 * )((u8 *)(temp_2_69) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_69) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_69) + (0x48))) = var_17;
        (*( s64 * )((u8 *)(temp_2_69) + (0x60))) = temp_16;
        func_00194590(temp_2_69, 0);
        var_18 = (s64)((s64)(s64)((*( s64 * )((u8 *)(temp_2_65) + (0x58)))));
        var_17 = 0;
        temp_2_70 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1A));
        (*( s8 * )((u8 *)(temp_2_70) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_70) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_70) + (0x48))) = 0;
        (*( s64 * )((u8 *)(temp_2_70) + (0x60))) = temp_16;
        func_00194590(temp_2_70, 0);
        temp_2_71 = (u8 *)(func_001d3530((*( u8 ** )((u8 *)(temp_22_3) + (0x30))), (*( u8 ** )((u8 *)(temp_2_64) + (0x30))), 3));
        (*( s8 * )((u8 *)(temp_2_71) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_71) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_71) + (0x48))) = 0;
        (*( s64 * )((u8 *)(temp_2_71) + (0x60))) = temp_16;
        func_00194590(temp_2_71, 0);
        temp_2_72 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*( u8 ** )((u8 *)(temp_2_64) + (0x30))), (*( u8 ** )((u8 *)(arg0) + (0x30))), 2));
        (*( s8 * )((u8 *)(temp_2_72) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_72) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_72) + (0x48))) = 0;
        (*( s64 * )((u8 *)(temp_2_72) + (0x60))) = temp_16;
        func_00194590(temp_2_72, 1);
        temp_2_73 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(temp_2_64) + (0x30))), 0xA, 0, 1.0f, 1));
        (*( s8 * )((u8 *)(temp_2_73) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_73) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_73) + (0x48))) = 0;
        (*( s64 * )((u8 *)(temp_2_73) + (0x60))) = temp_16;
        func_00194590(temp_2_73, 0);
        temp_2_74 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*( u8 ** )((u8 *)(temp_22_3) + (0x30))), (*( u8 ** )((u8 *)(arg0) + (0x30))), 2));
        (*( s8 * )((u8 *)(temp_2_74) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_74) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_74) + (0x48))) = 0;
        (*( u8 * )((u8 *)(temp_2_74) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_74) + (0x47))) & 0xDF));
        (*( s64 * )((u8 *)(temp_2_74) + (0x60))) = temp_16;
        func_00194590(temp_2_74, 1);
        temp_4_11 = (u8 *)(iGpffffb3ac);
        (*( s32 * )((u8 *)(temp_4_11) + (0xC))) = (s32)((s32) ((*( s32 * )((u8 *)(temp_4_11) + (0xC))) | 0x400000));
        temp_3_12 = (u8 *)(iGpffffb3ac);
        (*( u16 * )((u8 *)(temp_3_12) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(temp_3_12) + (0x18))) | 0xF));
    }
    func_001d69f0((u16) sp270, formation);
    if (var_21 != 0) {
        temp_2_75 = (u8 *)(func_00194b60());
        (*( s8 * )((u8 *)(temp_2_75) + (0))) = 4;
        (*( s64 * )((u8 *)(temp_2_75) + (8))) = var_18;
        (*( s16 * )((u8 *)(temp_2_75) + (0x48))) = var_17;
        func_00194590(temp_2_75, 1);
        if (sp340 == 0) {
            var_22 = (u8 *)(func_001d5eb0(sp4A0, formation, 1));
        } else {
            var_22 = (u8 *)(func_00194b60());
        }
        (*( s8 * )((u8 *)(var_22) + (0))) = 5;
        *(s64 *)(var_22 + 8) = sp468;
        (*( s8 * )((u8 *)(var_22) + (0x20))) = 5;
        *(s64 *)(var_22 + 0x28) = *(s64 *)(temp_2_75 + 0x58);
        (*( s64 * )((u8 *)(var_22) + (0x60))) = temp_16;
        func_00194590(var_22, 1);
        if (sp340 == 0) {
            sp4CC = (u8 *)(btlSoundCreateSkillSEPacket((u16) sp270, 1));
        } else {
            sp4CC = (u8 *)(func_00194b60());
        }
        (*( s8 * )((u8 *)(sp4CC) + (0))) = 5;
        *(s64 *)(sp4CC + 8) = sp468;
        func_00194590(sp4CC, 1);
    } else {
        if (sp340 == 0) {
            var_22 = (u8 *)(func_001d5eb0(sp4A0, formation, 0));
        } else {
            var_22 = (u8 *)(func_00194b60());
        }
        (*( s8 * )((u8 *)(var_22) + (0))) = 4;
        (*( s64 * )((u8 *)(var_22) + (8))) = var_18;
        (*( s16 * )((u8 *)(var_22) + (0x48))) = var_17;
        (*( s64 * )((u8 *)(var_22) + (0x60))) = temp_16;
        func_00194590(var_22, 1);
        if (sp340 == 0) {
            sp4CC = (u8 *)(btlSoundCreateSkillSEPacket((u16) sp270, 0));
        } else {
            sp4CC = (u8 *)(func_00194b60());
        }
        (*( s8 * )((u8 *)(sp4CC) + (0))) = 4;
        *(s64 *)(sp4CC + 8) = *(s64 *)(var_22 + 0x58);
        func_00194590(sp4CC, 1);
    }
    if ((*( u16 * )((u8 *)(arg0) + (0x6A))) == 1) {
        if ((s32)(s32)sp230 != 0) {
            sp4E0 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x88))));
        }
    } else {
        sp4E0 = (s32 *)(arg0);
    }
    temp_2_76 = (u8 *)(func_001d6240(sp4A0, (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(sp4E0) + (0x30))), 0, 0));
    var_17_6 = (u8 *)(temp_2_76);
    (*( s8 * )((u8 *)(temp_2_76) + (0))) = 4;
    *(s64 *)(temp_2_76 + 8) = *(s64 *)(var_22 + 0x58);
    (*( s8 * )((u8 *)(temp_2_76) + (0x10))) = 4;
    *(s64 *)(temp_2_76 + 0x18) = *(s64 *)(sp4CC + 0x58);
    if ((*( u16 * )(temp_30_ptr + (2))) & 0x80) {
        (*( s64 * )((u8 *)(var_17_6) + (0x60))) = temp_16;
    }
    func_00194590(var_17_6, 2);
    sp190 = *(s64 *)(var_17_6 + 0x58);
    if (sp340 == 0) {
        temp_2_77 = (u8 *)(func_001f8140(0));
        (*( s8 * )((u8 *)(temp_2_77) + (0))) = 5;
        *(s64 *)(temp_2_77 + 8) = *(s64 *)(var_17_6 + 0x58);
        func_00194590(temp_2_77, 1);
    }
    sp4C8 = 0;
    sp440 = 0x18;
    sp380 = 0;
    if (sp340 != 0) {
        var_2_8 = 4;
    } else {
        var_2_8 = (s32)(func_001ef4a0((u16) sp270) & 0xFFFF);
    }
    sp180 = var_2_8 & 0xFFFF;
    sp410 = 0;
    sp3C0 = 0;
    sp290 = (s32) sp450;
    sp2A0 = (u16) sp270;
do {
        sp260 = (s32) sp3C0;
            temp_18 = (s32 *)((*( s32 ** )((u8 *)(((s32)(arg0) + (sp3C0 * 4))) + (0x38))));
            sp3A0 = (u16)((u16) (*( u8 * )((u8 *)(temp_18) + (0xD9))));
            sp390 = 0;
            sp170 = (s32)((s32)(s32)(func_001d43f0((s32)(temp_18) + 0xD8)));
            if ((s32)(s32)sp230 != 0) {
                var_21_2 = (s32 *)((*( s32 ** )((u8 *)(arg0) + (0x88))));
            } else if ((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0) {
                var_21_2 = (s32 *)(arg0);
            } else {
                var_21_2 = (s32 *)(temp_18);
            }
            temp_2_78 = (s32)((s32)((*( s32 * )((u8 *)(temp_18) + (0xE0)))));
            if ((temp_2_78 != 0) && ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))) != (s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30)))) + (0xA2)))))) {
                sp3E0 += 1;
            }
            if ((*( s32 * )((u8 *)(((s32)(temp_18) + (sp3A0 << 5))) + (0xD8))) & 0x100000) {
                sp3D0 += 1;
                sp370 |= (*( u16 * )((u8 *)(temp_18) + (0xDE)));
            }
            temp_4_12 = (u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30))));
            var_5 = (u8)((u8)((*( u8 * )((u8 *)(temp_4_12) + (0xA2)))));
            sp160 = 1;
            if (var_5 == 1) {
                var_5 = *(u16 *)(temp_4_12 + 0xA4) * 0xE8;
                sp160 = (s32)((s32)(s32)((s32)(((*( s16 * )((u8 *)((((s32)iGpffffb3cc) + var_5)) + (0x18))) & 0x40)) == (s32)(0)));
            }
            if ((temp_2_78 != 0) || ((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0)) {
                sp440 = 0x1E;
            }
            temp_2_79 = (u8 *)(func_00202740(temp_4_12, var_5));
            (*( s64 * )((u8 *)(temp_2_79) + (0x60))) = temp_16;
            func_00194590(temp_2_79, 1);
            if (((*( u16 * )((u8 *)(temp_18) + (0xDC))) != 0x400) && ((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 1)) {
                var_17_6 = (u8 *)(func_001d6240(sp4A0, (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(var_21_2) + (0x30))), 1, sp170 | 0x1000));
                if ((s32)(sp4C8) == (s32)(0)) {
                    if (!((*( u16 * )(temp_30_ptr + (2))) & 0x2000)) {
                        (*( s8 * )((u8 *)(var_17_6) + (0))) = 4;
                        *(s64 *)(var_17_6 + 8) = *(s64 *)(var_22 + 0x58);
                        (*( s8 * )((u8 *)(var_17_6) + (0x10))) = 4;
                        *(s64 *)(var_17_6 + 0x18) = *(s64 *)(sp4CC + 0x58);
                    } else {
                        (*( s8 * )((u8 *)(var_17_6) + (0))) = 4;
                        *(s64 *)(var_17_6 + 8) = sp190;
                    }
                    (*( u16 * )((u8 *)(var_17_6) + (0x48))) = sp380;
                } else {
                    (*( s8 * )((u8 *)(var_17_6) + (0))) = 4;
                    *(s64 *)(var_17_6 + 8) = *(s64 *)(sp4C8 + 0x58);
                }
                if ((*( u16 * )(temp_30_ptr + (2))) & 0x80) {
                    (*( s64 * )((u8 *)(var_17_6) + (0x60))) = temp_16;
                }
                func_00194590(var_17_6, 2);
                if (sp340 == 0) {
                    temp_2_80 = (u8 *)(func_001f8140(1));
                    (*( s8 * )((u8 *)(temp_2_80) + (0))) = 5;
                    *(s64 *)(temp_2_80 + 8) = *(s64 *)(var_17_6 + 0x58);
                    func_00194590(temp_2_80, 1);
                } else {
                    temp_3_13 = (s16)func_0023d8e0(NULL, sp2A0);
                    switch (temp_3_13) {                /* switch 2; irregular */
                    case 16:                            /* switch 2 */
                        var_2_9 = (u8 *)(func_001f7c20(0xC, 2, 0x16));
                        break;
                    case 17:                            /* switch 2 */
                        var_2_9 = (u8 *)(func_001f7c20(0xC, 2, 0x19));
                        break;
                    default:                            /* switch 2 */
                        var_2_9 = (u8 *)(func_001f7c20(0xC, 2, 0x15));
                        break;
                    }
                    (*( s8 * )((u8 *)(var_2_9) + (0))) = 5;
                    *(s64 *)(var_2_9 + 8) = *(s64 *)(var_17_6 + 0x58);
                    func_00194590(var_2_9, 1);
                }
            } else {
                temp_2_81 = (u8 *)(func_001d6240(sp4A0, (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(var_21_2) + (0x30))), 1, sp170 | 0xC00));
                var_17_6 = (u8 *)(temp_2_81);
                (*( s8 * )((u8 *)(temp_2_81) + (0))) = 4;
                *(s64 *)(temp_2_81 + 8) = *(s64 *)(var_22 + 0x58);
                (*( s8 * )((u8 *)(temp_2_81) + (0x10))) = 4;
                *(s64 *)(temp_2_81 + 0x18) = *(s64 *)(sp4CC + 0x58);
                (*( u16 * )((u8 *)(temp_2_81) + (0x48))) = sp380;
                if ((*( u16 * )(temp_30_ptr + (2))) & 0x80) {
                    (*( s64 * )((u8 *)(var_17_6) + (0x60))) = temp_16;
                }
                func_00194590(var_17_6, 2);
                if (((*( u16 * )((u8 *)(temp_18) + (0xDC))) != 0x400) && ((*( s32 * )((u8 *)(temp_18) + (0xE4))) == 1) && (sp260 == 0)) {
                    temp_2_82 = (u8 *)(func_001d6240(sp4A0, (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(var_21_2) + (0x30))), 1, sp170 | 0x1000));
                    sp4C0 = (u8 *)(temp_2_82);
                    (*( s8 * )((u8 *)(temp_2_82) + (0))) = 5;
                    *(s64 *)(temp_2_82 + 8) = *(s64 *)(var_17_6 + 0x58);
                    if (((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0) && ((*( u16 * )(temp_30_ptr + (2))) & 8)) {
                        (*( s16 * )((u8 *)(sp4C0) + (0x48))) = 8;
                    }
                    (*( s64 * )((u8 *)(sp4C0) + (0x60))) = temp_16;
                    func_00194590(sp4C0, 2);
                    if (sp340 == 0) {
                        temp_2_83 = (u8 *)(func_001f8140(1));
                        (*( s8 * )((u8 *)(temp_2_83) + (0))) = 5;
                        *(s64 *)(temp_2_83 + 8) = *(s64 *)(sp4C0 + 0x58);
                        func_00194590(temp_2_83, 1);
                    }
                }
            }
            if (sp33C != 0) {
                if ((s32)(s32)sp1C0 != 0) {
                    temp_2_84 = (u8 *)(actionLookAtUnit(0, (*( u8 ** )((u8 *)(var_21_2) + (0x30))), 3));
                    (*( s8 * )((u8 *)(temp_2_84) + (0))) = 5;
                    *(s64 *)(temp_2_84 + 8) = *(s64 *)(var_17_6 + 0x58);
                    *(s64 *)(temp_2_84 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2_84, 1);
                    if ((s32)(var_21_2) != (s32)(arg0)) {
                        temp_2_85 = (u8 *)(actionLookAtUnit((*( u8 ** )((u8 *)(var_21_2) + (0x30))), (*( u8 ** )((u8 *)(arg0) + (0x30))), 0));
                        (*( s8 * )((u8 *)(temp_2_85) + (0))) = 5;
                        *(s64 *)(temp_2_85 + 8) = *(s64 *)(var_17_6 + 0x58);
                        *(s64 *)(temp_2_85 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2_85, 1);
                    } else {
                        temp_2_86 = (u8 *)(btlUnitCreateLookAtDeactivatePacket((*( u8 ** )((u8 *)(var_21_2) + (0x30))), 0));
                        (*( s8 * )((u8 *)(temp_2_86) + (0))) = 5;
                        *(s64 *)(temp_2_86 + 8) = *(s64 *)(var_17_6 + 0x58);
                        *(s64 *)(temp_2_86 + 0x60) = *(s64 *)arg0;
                        func_00194590(temp_2_86, 1);
                    }
                    (*( u16 * )((u8 *)(arg0) + (0x18))) = (u16)((u16) ((*( u16 * )((u8 *)(arg0) + (0x18))) | 0x200));
                }
            } else if ((sp260 == 0) && (temp_23_2 == 0)) {
                temp_4_13 = (s32)((s32)(func_001eb440((s32)(arg0) + 0x38) & 0xFFFF));
                if (temp_4_13 == 2) {
                    func_00196040(temp_4_13, 1, &targetPosition, 0, 0, 1);
                    temp_2_87 = (u8 *)(btlUnitCreateLookAtPacket(0, &targetPosition, 1));
                    (*( s8 * )((u8 *)(temp_2_87) + (0))) = 5;
                    *(s64 *)(temp_2_87 + 8) = *(s64 *)(var_17_6 + 0x58);
                    *(s64 *)(temp_2_87 + 0x60) = *(s64 *)arg0;
                    func_00194590(temp_2_87, 1);
                }
            }
            if (sp2D0 == 1) {
                if ((s32)(sp4C8) == (s32)(0)) {
                    if (((s32)(s32)sp200 == 1) && ((s32)(s32)sp1F0 == 0) && ((s32)(s32)sp220 == 0)) {
                        temp_2_88 = (u8 *)(func_0019bbe0(sp4D0, 0, 0, 0, 4, 0));
                        (*( s8 * )((u8 *)(temp_2_88) + (0))) = 5;
                        *(s64 *)(temp_2_88 + 8) = *(s64 *)(var_17_6 + 0x58);
                        (*( s64 * )((u8 *)(temp_2_88) + (0x60))) = temp_16;
                        func_00194590(temp_2_88, 0);
                    }
                    if (sp2C0 == 0) {
                        if (sp30C == 0) {
                            var_2_10 = (u8 *)(func_0019a0c0((*( u8 ** )((u8 *)(arg0) + (0x30))), sp350));
                        } else {
                            /* Retail 001a9e5c/001ab480/001ab668 pass 1.0f in $f12. */
                            var_2_10 = (u8 *)(func_0019ac40((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
                        }
                        (*( s8 * )((u8 *)(var_2_10) + (0))) = 5;
                        *(s64 *)(var_2_10 + 8) = *(s64 *)(var_17_6 + 0x58);
                        (*( s64 * )((u8 *)(var_2_10) + (0x60))) = temp_16;
                        func_00194590(var_2_10, 0);
                    }
                    temp_2_89 = (u8 *)(func_0019bbe0((*( u8 ** )((u8 *)(arg0) + (0x30))), -1, 0, 0, 3, 0));
                    (*( s8 * )((u8 *)(temp_2_89) + (0))) = 5;
                    *(s64 *)(temp_2_89 + 8) = *(s64 *)(var_17_6 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_89) + (0x60))) = temp_16;
                    func_00194590(temp_2_89, 1);
                }
                if ((s32)(var_21_2) != (s32)(arg0)) {
                    temp_2_90 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*( u8 ** )((u8 *)(var_21_2) + (0x30))), (*( u8 ** )((u8 *)(arg0) + (0x30))), 2));
                    (*( s8 * )((u8 *)(temp_2_90) + (0))) = 5;
                    *(s64 *)(temp_2_90 + 8) = *(s64 *)(var_17_6 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_90) + (0x60))) = temp_16;
                    func_00194590(temp_2_90, 0);
                }
                temp_2_91 = (u8 *)(func_00201f20());
                (*( s8 * )((u8 *)(temp_2_91) + (0))) = 5;
                *(s64 *)(temp_2_91 + 8) = *(s64 *)(var_17_6 + 0x58);
                (*( s64 * )((u8 *)(temp_2_91) + (0x60))) = temp_16;
                func_00194590(temp_2_91, 0);
                temp_2_92 = (u8 *)(btlCameraCreateSetStatePacket(var_21_2, 0x1C));
                sp4C8 = (u8 *)(temp_2_92);
                (*( s8 * )((u8 *)(temp_2_92) + (0))) = 5;
                *(s64 *)(temp_2_92 + 8) = *(s64 *)(var_17_6 + 0x58);
                if (!((*( u16 * )(temp_30_ptr + (2))) & 0x80)) {
                    (*( s8 * )((u8 *)(sp4C8) + (0x20))) = 0xB;
                    *(s64 *)(sp4C8 + 0x28) = *(s64 *)(var_17_6 + 0x58);
                    (*( s16 * )((u8 *)(sp4C8) + (0x4A))) = 0x12;
                } else {
                    (*( s8 * )((u8 *)(sp4C8) + (0x20))) = 4;
                    *(s64 *)(sp4C8 + 0x28) = *(s64 *)(var_17_6 + 0x58);
                }
                (*( s64 * )((u8 *)(sp4C8) + (0x60))) = temp_16;
                func_00194590(sp4C8, 0);
            }
            if ((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0) {
                sp4C4 = (u8 *)(func_001d6240((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD28))), (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(temp_18) + (0x30))), 1, 0));
                if ((*( u16 * )(temp_30_ptr + (2))) & 4) {
                    (*( s8 * )((u8 *)(sp4C4) + (0))) = 0xB;
                    *(s64 *)(sp4C4 + 8) = *(s64 *)(var_17_6 + 0x58);
                } else {
                    (*( s8 * )((u8 *)(sp4C4) + (0))) = 5;
                    *(s64 *)(sp4C4 + 8) = sp190;
                }
                func_00194590(sp4C4, 1);
                temp_2_93 = (u8 *)(func_001f7c20(0xD, 2, 0xB));
                (*( s8 * )((u8 *)(temp_2_93) + (0))) = 5;
                *(s64 *)(temp_2_93 + 8) = *(s64 *)(sp4C4 + 0x58);
                func_00194590(temp_2_93, 1);
            }
            if ((*( u16 * )((u8 *)(temp_18) + (0xDC))) == 0x400) {
                sp4C4 = (u8 *)(func_001d6240((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD2C))), (*( u8 ** )((u8 *)(arg0) + (0x30))), (*( u8 ** )((u8 *)(var_21_2) + (0x30))), 1, 0));
                if ((*( u16 * )(temp_30_ptr + (2))) & 4) {
                    (*( s8 * )((u8 *)(sp4C4) + (0))) = 0xB;
                    *(s64 *)(sp4C4 + 8) = *(s64 *)(var_17_6 + 0x58);
                } else {
                    (*( s8 * )((u8 *)(sp4C4) + (0))) = 5;
                    *(s64 *)(sp4C4 + 8) = sp190;
                }
                func_00194590(sp4C4, 1);
                temp_2_94 = (u8 *)(func_001f7c20(0xC, 2, 0xC));
                (*( s8 * )((u8 *)(temp_2_94) + (0))) = 5;
                *(s64 *)(temp_2_94 + 8) = *(s64 *)(sp4C4 + 0x58);
                func_00194590(temp_2_94, 1);
                sp420 = 0xA;
            }
            sp3B0 = 0;
            sp150 = (s32) sp3A0;
            sp140 = sp3A0 - 1;
            sp130 = sp420 + 0x2B;
            spC0 = (s32) sp3B0;
            while ((s32) sp3B0 < sp150) {
                var_f20_2 = 1.0f;
                temp_2_95 = sp3B0 << 5;
                sp120 = temp_2_95;
                temp_2_96 = (u8 *)((s32)(temp_18) + temp_2_95);
                sp110 = (s32)((s32) temp_2_96);
                /* The two later predicates reload the signed byte after intervening calls. */
                hitMotion = (s8 *)(temp_2_96 + 0x10C);
                if ((*( s8 * )((u8 *)(temp_2_96) + (0x10C))) == 9) {
                    temp_2_97 = (u16)((u16)(func_00199350((*( u8 ** )((u8 *)(var_21_2) + (0x30))), 9, 1.0f)));
                    sp360 = temp_2_97;
                    if (((s32) temp_2_97 > 0) && ((s32) temp_2_97 < 0xA)) {
                        var_f1 = (f32) temp_2_97;
                        var_f20_2 = var_f1 / 10.0f;
                        sp360 = 0xA;
                    }
                }
                temp_2_98 = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)(*( u8 ** )((u8 *)(var_21_2) + (0x30))), *hitMotion, 0, var_f20_2, 0));
                var_19 = (u8 *)(temp_2_98);
                (*( s8 * )((u8 *)(temp_2_98) + (0))) = 0xB;
                *(s64 *)(temp_2_98 + 8) = *(s64 *)(var_17_6 + 0x58);
                (*( u16 * )((u8 *)(temp_2_98) + (0x48))) = sp390;
                if (((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0) && ((*( u16 * )(temp_30_ptr + (2))) & 8)) {
                    (*( u16 * )((u8 *)(var_19) + (0x48))) = (u16)((u16) ((s16) (*( u16 * )((u8 *)(var_19) + (0x48))) + 8));
                }
                (*( s64 * )((u8 *)(var_19) + (0x60))) = temp_16;
                func_00194590(var_19, 0);
                if (((s32)(s32)spC0 == sp140) && ((*( s32 * )((u8 *)(sp110) + (0xF8))) & 0x100000) && (sp340 == 0) && ((s32)(s32)sp160 == 1) && ((*( s32 * )((u8 *)(temp_18) + (0xE0))) == 0) && (*hitMotion == 9) && ((s32)(func_0023df70(sp2A0)) == (s32)(0))) {
                    sp250 = (s32) sp360;
                    if ((s32) sp360 >= 0x19) {
                        var_2_11 = 0;
                    } else {
                        var_2_11 = 0x19 - sp250;
                    }
                    temp_2_99 = (u8 *)(func_00197cc0((*( u8 ** )((u8 *)(var_21_2) + (0x30))), sp450, (s16)var_2_11));
                    (*( s8 * )((u8 *)(temp_2_99) + (0))) = 4;
                    *(s64 *)(temp_2_99 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_99) + (0x60))) = temp_16;
                    func_00194590(temp_2_99, 0);
                    if ((*( u16 * )((u8 *)(arg0) + (0x6A))) == 1) {
                        temp_3_14 = (s16)func_0023d8e0((u8 *)(u32)(*( s64 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA64))), sp2A0);
                        switch (temp_3_14) {            /* switch 3; irregular */
                        case 1:                         /* switch 3 */
                            var_2_12 = 0x29;
                            break;
                        case 2:                         /* switch 3 */
                            var_2_12 = 0x2B;
                            break;
                        case 3:                         /* switch 3 */
                            var_2_12 = 0x2A;
                            break;
                        case 4:                         /* switch 3 */
                            var_2_12 = 0x2C;
                            break;
                        default:                        /* switch 3 */
                            var_2_12 = -1;
                            break;
                        }
                        temp_3_15 = (s16)var_2_12;
                        if (temp_3_15 != -1) {
                            temp_5_2 = (u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30))));
                            temp_2_100 = (u8 *)(func_001d6240((*( s64 * )((u8 *)(((*( u8 ** )iGpffffb3ac) + (temp_3_15 * 4))) + (0xD04))), temp_5_2, temp_5_2, 1, 0));
                            (*( s8 * )((u8 *)(temp_2_100) + (0))) = 4;
                            *(s64 *)(temp_2_100 + 8) = *(s64 *)(var_19 + 0x58);
                            (*( s64 * )((u8 *)(temp_2_100) + (0x60))) = temp_16;
                            func_00194590(temp_2_100, 2);
                        }
                    }
                    if (sp250 > 0x19) {
                        temp_2_101 = (u8 *)(func_0019aa70((*( u8 ** )((u8 *)(var_21_2) + (0x30))), (s16)(sp250 - 0x19)));
                        (*( s8 * )((u8 *)(temp_2_101) + (0))) = 4;
                        *(s64 *)(temp_2_101 + 8) = *(s64 *)(var_19 + 0x58);
                        (*( s64 * )((u8 *)(temp_2_101) + (0x60))) = temp_16;
                        func_00194590(temp_2_101, 0);
                    }
                    temp_5_3 = (u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30))));
                    temp_2_102 = (u8 *)(func_001d6240((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD80))), temp_5_3, temp_5_3, 1, 0));
                    sp4B8 = (u8 *)(temp_2_102);
                    (*( s8 * )((u8 *)(temp_2_102) + (0))) = 4;
                    *(s64 *)(temp_2_102 + 8) = *(s64 *)(var_19 + 0x58);
                    if (sp250 >= 0x19) {
                        sp250 = 0x19;
                    }
                    (*( s16 * )((u8 *)(sp4B8) + (0x48))) = (s16) sp250;
                    (*( s64 * )((u8 *)(sp4B8) + (0x60))) = temp_16;
                    func_00194590(sp4B8, 2);
                    temp_2_103 = (u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30))));
                    temp_f2 = (*( f32 * )((u8 *)(temp_2_103) + (0x2C)));
                    var_f1_2 = (((*( f32 * )((u8 *)(temp_2_103) + (0x90))) * temp_f2 * ((*( f32 * )((u8 *)(temp_2_103) + (0x8C))) * temp_f2)) / (f32) 0x2710);
                    if (var_f1_2 < 2.0f) {
                        var_f1_2 = 2.0f;
                    } else if (!(var_f1_2 <= 5.0f)) {
                        var_f1_2 = 5.0f;
                    }
                    temp_2_104 = (u8 *)(func_001bccc0(0x12, (s16)(s32)((80.0f * var_f1_2) / 5.0f), 0, 6));
                    (*( s8 * )((u8 *)(temp_2_104) + (0))) = 5;
                    *(s64 *)(temp_2_104 + 8) = *(s64 *)(sp4B8 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_104) + (0x60))) = temp_16;
                    func_00194590(temp_2_104, 1);
                    temp_2_105 = (u8 *)(func_0019a980((*( u8 ** )((u8 *)(var_21_2) + (0x30)))));
                    (*( s8 * )((u8 *)(temp_2_105) + (0))) = 5;
                    *(s64 *)(temp_2_105 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s64 * )((u8 *)(temp_2_105) + (0x60))) = temp_16;
                    func_00194590(temp_2_105, 0);
                }
                if ((sp2D0 == 0) && ((*hitMotion != -1) || ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(temp_18) + (0x30)))) + (0xA2)))) != (s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))))) && ((s32)(datCalcChkBadStatus((s32)(*( u8 ** )((u8 *)((*( u8 ** )((u8 *)(temp_18) + (0x30)))) + (0xA64))), 0x180001)) == (s32)(0))) {
                    temp_2_106 = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*( u8 ** )((u8 *)(temp_18) + (0x30))), (*( u8 ** )((u8 *)(arg0) + (0x30))), 2));
                    if (((*( s32 * )((u8 *)(temp_18) + (0xE4))) != 0) && ((s32)(sp4C4) != (s32)(0))) {
                        (*( s8 * )((u8 *)(temp_2_106) + (0))) = 5;
                        *(s64 *)(temp_2_106 + 8) = *(s64 *)(sp4C4 + 0x58);
                    } else {
                        (*( s8 * )((u8 *)(temp_2_106) + (0))) = 5;
                        *(s64 *)(temp_2_106 + 8) = *(s64 *)(var_19 + 0x58);
                    }
                    (*( u8 * )((u8 *)(temp_2_106) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_106) + (0x47))) & 0xDF));
                    (*( s64 * )((u8 *)(temp_2_106) + (0x60))) = temp_16;
                    func_00194590(temp_2_106, 1);
                }
                if ((*( s32 * )((u8 *)(iGpffffb3ac) + (0xC))) & 0x200000) {
                    temp_2_107 = (u8 *)(func_00194c90(func_0022eba0, arg0));
                    (*( s8 * )((u8 *)(temp_2_107) + (0))) = 5;
                    *(s64 *)(temp_2_107 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_107) + (0x48))) = sp420;
                    (*( s64 * )((u8 *)(temp_2_107) + (0x60))) = temp_16;
                    func_00194590(temp_2_107, 1);
                }
                temp_2_108 = (s32 *)(sp110 + 0xF0);
                sp240 = (s32 *)(temp_2_108);
                temp_2_109 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(var_21_2), temp_2_108, (*( u16 * )((u8 *)(temp_18) + (0xDC))), (*( u16 * )((u8 *)(temp_18) + (0xDE)))));
                (*( s8 * )((u8 *)(temp_2_109) + (0))) = 5;
                *(s64 *)(temp_2_109 + 8) = *(s64 *)(var_19 + 0x58);
                (*( s16 * )((u8 *)(temp_2_109) + (0x48))) = sp420;
                (*( s64 * )((u8 *)(temp_2_109) + (0x60))) = temp_16;
                func_00194590(temp_2_109, 1);
                temp_2_110 = (u8 *)(func_001f3950(temp_18));
                (*( s8 * )((u8 *)(temp_2_110) + (0))) = 5;
                *(s64 *)(temp_2_110 + 8) = *(s64 *)(var_19 + 0x58);
                (*( s16 * )((u8 *)(temp_2_110) + (0x48))) = sp420;
                (*( s64 * )((u8 *)(temp_2_110) + (0x60))) = temp_16;
                func_00194590(temp_2_110, 1);
                if (((s32)(sp260) == (s32)(((*( u16 * )((u8 *)(arg0) + (0x6A))) - 1))) && ((s32)(spC0) == (s32)(((*( u8 * )((u8 *)(temp_18) + (0xD9))) - 1)))) {
                    temp_2_111 = (u8 *)(func_001f3950(arg0));
                    (*( s8 * )((u8 *)(temp_2_111) + (0))) = 5;
                    *(s64 *)(temp_2_111 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_111) + (0x48))) = sp420;
                    (*( s64 * )((u8 *)(temp_2_111) + (0x60))) = temp_16;
                    func_00194590(temp_2_111, 1);
                }
                if ((sp260 == 0) && ((s32)(s32)spC0 == 0) && !((*( u16 * )((u8 *)(arg0) + (0x18))) & 4)) {
                    temp_2_112 = (u8 *)(func_001f3870(arg0, (*( u8 * )((u8 *)(arg0) + (0xDB)))));
                    (*( s8 * )((u8 *)(temp_2_112) + (0))) = 5;
                    *(s64 *)(temp_2_112 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_112) + (0x48))) = sp420;
                    (*( s64 * )((u8 *)(temp_2_112) + (0x60))) = temp_16;
                    func_00194590(temp_2_112, 1);
                }
                if ((s32)(spC0) == (s32)(((*( u8 * )((u8 *)(temp_18) + (0xD9))) - 1))) {
                    if (!((((*( s16 * )((u8 *)(arg0) + (0xEC))) != 0) && !((*( u8 * )((u8 *)(arg0) + (0xD8))) & 1)))) {
                        if ((*( s16 * )((u8 *)(temp_18) + (0xEC))) != 0) {
                            temp_4_15 = (*( s32 * )((u8 *)(sp110) + (0x104)));
                            if (temp_4_15 != 0) {
                                func_00216da0((*( s32 * )((u8 *)(iGpffffb3ac) + (0xC60))), func_0043c6a0(temp_4_15));
                            }
                            temp_2_114 = (u8 *)(func_00202400((*( u8 ** )((u8 *)(temp_18) + (0x30))), (*( s16 * )((u8 *)(temp_18) + (0xEC)))));
                            (*( s8 * )((u8 *)(temp_2_114) + (0))) = 5;
                            *(s64 *)(temp_2_114 + 8) = *(s64 *)(var_19 + 0x58);
                            (*( u8 * )((u8 *)(temp_2_114) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_114) + (0x47))) & 0xDF));
                            (*( s64 * )((u8 *)(temp_2_114) + (0x60))) = temp_16;
                            func_00194590(temp_2_114, 3);
                        } else if ((s32)(s32)sp230 != 0) {
                            temp_5_4 = (s16)((s16)((*( s16 * )((u8 *)(var_21_2) + (0xEC)))));
                            if (temp_5_4 != 0) {
                                temp_2_115 = (u8 *)(func_00202400((*( u8 ** )((u8 *)(var_21_2) + (0x30))), temp_5_4));
                                (*( s8 * )((u8 *)(temp_2_115) + (0))) = 5;
                                *(s64 *)(temp_2_115 + 8) = *(s64 *)(var_19 + 0x58);
                                (*( u8 * )((u8 *)(temp_2_115) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_115) + (0x47))) & 0xDF));
                                (*( s64 * )((u8 *)(temp_2_115) + (0x60))) = temp_16;
                                func_00194590(temp_2_115, 3);
                            }
                        }
                    } else {
                        temp_4_14 = (s32)((s32)((*( s32 * )((u8 *)(((s32)(arg0) + sp120)) + (0x104)))));
                        if (temp_4_14 != 0) {
                            func_00216da0((*( s32 * )((u8 *)(iGpffffb3ac) + (0xC60))), func_0043c6a0(temp_4_14));
                        }
                        temp_2_113 = (u8 *)(func_00202400((*( u8 ** )((u8 *)(arg0) + (0x30))), (*( s16 * )((u8 *)(arg0) + (0xEC)))));
                        (*( s8 * )((u8 *)(temp_2_113) + (0))) = 5;
                        *(s64 *)(temp_2_113 + 8) = *(s64 *)(var_19 + 0x58);
                        (*( u8 * )((u8 *)(temp_2_113) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_113) + (0x47))) & 0xDF));
                        (*( s64 * )((u8 *)(temp_2_113) + (0x60))) = temp_16;
                        func_00194590(temp_2_113, 3);
                    }
                }
                if ((s32)(*sp240) != (s32)(0)) {
                    temp_2_116 = (u8 *)(func_00202590((s32)((*( u8 ** )((u8 *)(var_21_2) + (0x30)))), 0, 0));
                    (*( s8 * )((u8 *)(temp_2_116) + (0))) = 5;
                    *(s64 *)(temp_2_116 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_116) + (0x48))) = sp420;
                    (*( u8 * )((u8 *)(temp_2_116) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_116) + (0x47))) & 0xDF));
                    (*( s64 * )((u8 *)(temp_2_116) + (0x60))) = temp_16;
                    func_00194590(temp_2_116, 3);
                }
                if (((*( s32 * )((u8 *)(sp110) + (0xF8))) & 0x100000) && ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(var_21_2) + (0x30)))) + (0xA2)))) == (s32)(1))) {
                    temp_2_117 = (u8 *)(func_001f7c20(0xD, 2, 8));
                    (*( s8 * )((u8 *)(temp_2_117) + (0))) = 5;
                    *(s64 *)(temp_2_117 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_117) + (0x48))) = sp420;
                    (*( s64 * )((u8 *)(temp_2_117) + (0x60))) = temp_16;
                    func_00194590(temp_2_117, 1);
                }
                if ((*( u16 * )((u8 *)(sp110) + (0x10E))) & 0x20) {
                    sp310 = 1;
                    (*( s16 * )((u8 *)(iGpffffb3ac) + (0x1C))) = 3;
                }
                if ((*( u16 * )((u8 *)(sp110) + (0x10E))) & 0x40) {
                    sp2E0 = 1;
                }
                temp_2_118 = (u8 *)((s32)(temp_18) + (sp3B0 << 5));
                spF0 = (s32)((s32) temp_2_118);
                temp_2_119 = (u8 *)(func_00201de0((s32)((*( u8 ** )((u8 *)(arg0) + (0x30)))), (s32)((*( u8 ** )((u8 *)(var_21_2) + (0x30)))), sp290, (*( u16 * )((u8 *)(temp_18) + (0xDC))), (*( u16 * )((u8 *)(temp_18) + (0xDE))), sp3B0, sp3A0, sp240, 0));
                (*( s8 * )((u8 *)(temp_2_119) + (0))) = 5;
                *(s64 *)(temp_2_119 + 8) = *(s64 *)(var_19 + 0x58);
                (*( s16 * )((u8 *)(temp_2_119) + (0x48))) = sp420;
                (*( u8 * )((u8 *)(temp_2_119) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_119) + (0x47))) & 0xDF));
                (*( s64 * )((u8 *)(temp_2_119) + (0x60))) = temp_16;
                func_00194590(temp_2_119, 3);
                hpTransfer = (s16 *)(temp_2_118 + 0x108);
                if (((*( s16 * )((u8 *)(temp_2_118) + (0x108))) > 0) || ((*( s16 * )((u8 *)(sp110) + (0x10A))) > 0)) {
                    spD0 = (s16)sp130;
                    func_001f0a10((u8 *)&result);
                    result.hpDelta = *hpTransfer;
                    result.spDelta = (s32)((s32) (*( s16 * )((u8 *)(((s32)(temp_18) + (sp3B0 << 5))) + (0x10A))));
                    temp_2_120 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
                    (*( s8 * )((u8 *)(temp_2_120) + (0))) = 4;
                    *(s64 *)(temp_2_120 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_120) + (0x48))) = (s16) spD0;
                    (*( s64 * )((u8 *)(temp_2_120) + (0x60))) = temp_16;
                    func_00194590(temp_2_120, 1);
                    temp_4_16 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
                    temp_2_121 = (u8 *)(func_00201de0((s32)(temp_4_16), (s32)(temp_4_16), -1, 1U, 1U, sp3B0, sp3A0, &result, 0));
                    (*( s8 * )((u8 *)(temp_2_121) + (0))) = 4;
                    *(s64 *)(temp_2_121 + 8) = *(s64 *)(var_19 + 0x58);
                    (*( s16 * )((u8 *)(temp_2_121) + (0x48))) = (s16) spD0;
                    (*( s64 * )((u8 *)(temp_2_121) + (0x60))) = temp_16;
                    func_00194590(temp_2_121, 3);
                    if (result.hpDelta != 0) {
                        if ((s32)(s32)spC0 == 0) {
                            temp_2_122 = (u8 *)(func_00202740((*( u8 ** )((u8 *)(arg0) + (0x30)))));
                            (*( s64 * )((u8 *)(temp_2_122) + (0x60))) = temp_16;
                            func_00194590(temp_2_122, 1);
                        }
                        temp_2_123 = (u8 *)(func_00202590((s32)((*( u8 ** )((u8 *)(arg0) + (0x30)))), 0, 0));
                        (*( s8 * )((u8 *)(temp_2_123) + (0))) = 4;
                        *(s64 *)(temp_2_123 + 8) = *(s64 *)(var_19 + 0x58);
                        (*( s16 * )((u8 *)(temp_2_123) + (0x48))) = (s16) spD0;
                        (*( s64 * )((u8 *)(temp_2_123) + (0x60))) = temp_16;
                        func_00194590(temp_2_123, 3);
                    }
                }
                sp390 += 7;
                sp3B0 += 1;
                spC0 = (s32) sp3B0;
            }
            if (sp410 < (s32) sp390) {
                sp410 = sp390;
            }
            sp380 += sp180;
            sp3C0 += 1;
} while ((s32)((s32) sp3C0) < (s32)((s32) (*( u16 * )((u8 *)(arg0) + (0x6A)))));
    temp_18_2 = (s64)((s64)(s64)((*( s64 * )((u8 *)(var_19) + (0x58)))));
    temp_3_16 = (s16)((s16)((*( s16 * )((u8 *)(arg0) + (0xEE)))));
    if (temp_3_16 != -1) {
        temp_2_124 = (u8 *)(func_001f5f70(arg0, temp_3_16 & 0xFFFF, 0, 0, 0));
        (*( s8 * )((u8 *)(temp_2_124) + (0))) = 5;
        (*( s64 * )((u8 *)(temp_2_124) + (8))) = temp_18_2;
        (*( s16 * )((u8 *)(temp_2_124) + (0x48))) = (s16) sp410;
        (*( s64 * )((u8 *)(temp_2_124) + (0x60))) = temp_16;
        func_00194590(temp_2_124, 1);
    } else if (sp3E0 > 0) {
        if (temp_23_2 == 0) {
            temp_21 = (s32)(func_001ef720(2, 0x80000) & 0xFFFF);
            if (((s32)((s32) (*( u8 * )((u8 *)(arg0) + (0x28)))) <= (s32)(0)) && ((s32)((*( u16 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA4)))) != (s32)(1)) && ((s32)(func_00231d70(0x64U)) < (s32)(0x32U))) {
                if ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))) != (s32)(0)) {
                    var_2_13 = 0;
                } else {
                    temp_4_17 = (u8 *)(iGpffffb3ac);
                    if ((*( s16 * )((u8 *)(temp_4_17) + (0xA70))) != -1) {
                        temp_3_17 = (s16)(temp_21 - sp3E0);
                        if (temp_3_17 <= 0) {
                            temp_4_18 = (u32)(func_001ef720(2, 0x80000) & 0xFFFF);
                            temp_3_18 = (u8 *)(iGpffffb3ac);
                            if (((s64)((u32) ((s16) (*( s16 * )((u8 *)(temp_3_18) + (0xA72))) >> 1)) >= (s64)(temp_4_18)) && (temp_21_2 = (*( s16 * )((u8 *)(temp_3_18) + (0xA70))), ((s64)(temp_21_2) != (s64)(s16)func_001d15a0()))) {
                                var_2_13 = 1;
                            } else {
                                goto block_406;
                            }
                        } else if ((s64)(((s16) (*( s16 * )((u8 *)(temp_4_17) + (0xA72))) >> 1)) >= (s64)(temp_3_17)) {
                            var_2_13 = 1;
                        } else {
                            goto block_406;
                        }
                    } else {
block_406:
                        var_2_13 = 0;
                    }
                }
                if (var_2_13 != 0) {
                    goto block_408;
                }
                temp_2_125 = (u8 *)(func_001f99c0(arg0, 0x10, (u16) sp3E0, 0, 0));
                (*( s8 * )((u8 *)(temp_2_125) + (0))) = 5;
                (*( s64 * )((u8 *)(temp_2_125) + (8))) = temp_18_2;
                (*( s16 * )((u8 *)(temp_2_125) + (0x48))) = (s16) sp410;
                func_00194590(temp_2_125, 1);
            } else {
block_408:
                temp_2_126 = (u8 *)(func_001f5f70(arg0, 0x13, sp3E0, 0, 0));
                (*( s8 * )((u8 *)(temp_2_126) + (0))) = 5;
                (*( s64 * )((u8 *)(temp_2_126) + (8))) = temp_18_2;
                (*( s16 * )((u8 *)(temp_2_126) + (0x48))) = (s16) sp410;
                (*( s64 * )((u8 *)(temp_2_126) + (0x60))) = temp_16;
                func_00194590(temp_2_126, 1);
            }
        }
    } else if ((sp3D0 > 0) && (temp_3_19 = (*( u8 * )((u8 *)(arg0) + (0xDB))), ((temp_3_19 & 1) != 0)) && !(temp_3_19 & 2) && ((s64)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))) == (s64)(0))) {
        temp_2_127 = (u8 *)(func_001f5f70(arg0, 0x18, (s32) sp370, sp3D0, 0));
        (*( s8 * )((u8 *)(temp_2_127) + (0))) = 5;
        (*( s64 * )((u8 *)(temp_2_127) + (8))) = temp_18_2;
        (*( s16 * )((u8 *)(temp_2_127) + (0x48))) = (s16) sp410;
        (*( s64 * )((u8 *)(temp_2_127) + (0x60))) = temp_16;
        func_00194590(temp_2_127, 1);
    } else if ((sp33C != 0) && (temp_23_2 == 0) && ((s64)(func_001f0c50(arg0)) != (s64)(0)) && ((s64)(func_001f0d30(arg0)) == (s64)(0))) {
        temp_2_128 = (u8 *)(func_001f99c0((*( s32 ** )((u8 *)(arg0) + (0x38))), 0x12, 0U, 0, 0));
        (*( s8 * )((u8 *)(temp_2_128) + (0))) = 5;
        (*( s64 * )((u8 *)(temp_2_128) + (8))) = temp_18_2;
        (*( s16 * )((u8 *)(temp_2_128) + (0x48))) = (s16) sp410;
        func_00194590(temp_2_128, 1);
    } else if (sp3E0 == 0) {
        if ((s32)(func_001f0dd0(arg0, 1)) != (s32)(0)) {
            temp_2_129 = (u8 *)(func_001f99c0(arg0, 0xF, 0U, 0, 0));
            (*( s8 * )((u8 *)(temp_2_129) + (0))) = 5;
            (*( s64 * )((u8 *)(temp_2_129) + (8))) = temp_18_2;
            (*( s16 * )((u8 *)(temp_2_129) + (0x48))) = (s16) sp410;
            func_00194590(temp_2_129, 1);
        } else if (((s32)(func_001f0f70(arg0)) == (s32)(1)) && ((s32)(func_001f0b90(arg0)) == (s32)(0)) && (sp2E0 == 0)) {
            temp_2_130 = (u8 *)(func_001f99c0(arg0, 0x11, 0U, 0, 0));
            (*( s8 * )((u8 *)(temp_2_130) + (0))) = 5;
            (*( s64 * )((u8 *)(temp_2_130) + (8))) = temp_18_2;
            (*( s16 * )((u8 *)(temp_2_130) + (0x48))) = (s16) sp410;
            func_00194590(temp_2_130, 1);
        }
    }
    if (sp2E0 != 0) {
        if (sp2D0 == 1) {
            temp_2_131 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1B));
            sp4C8 = (u8 *)(temp_2_131);
            (*( s8 * )((u8 *)(temp_2_131) + (0))) = 0xB;
            *(s64 *)(temp_2_131 + 8) = *(s64 *)(var_17_6 + 0x58);
            (*( s16 * )((u8 *)(temp_2_131) + (0x48))) = 0x18;
            (*( s64 * )((u8 *)(temp_2_131) + (0x60))) = temp_16;
            func_00194590(temp_2_131, 0);
        }
        if ((s32)((*( u8 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA2)))) == (s32)(0)) {
            func_001f0a10((u8 *)&result);
            result.hpDelta = 1 - (s32)(datCalcGetHp((*( s32 * )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30)))) + (0xA64)))) & 0xFFFF);
            var_18_4 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
            if (sp2D0 == 1) {
                (*( s8 * )((u8 *)(var_18_4) + (0))) = 4;
                (*( s64 * )((u8 *)(var_18_4) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(sp4C8) + (0x58))));
            } else {
                (*( s8 * )((u8 *)(var_18_4) + (0))) = 0xB;
                (*( s64 * )((u8 *)(var_18_4) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_17_6) + (0x58))));
            }
            (*( s64 * )((u8 *)(var_18_4) + (0x60))) = temp_16;
            func_00194590(var_18_4, 1);
            temp_4_19 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
            temp_2_132 = (u8 *)(func_00201de0((s32)(temp_4_19), (s32)(temp_4_19), -1, 0U, 0U, 0U, 1U, &result, 0));
            (*( s8 * )((u8 *)(temp_2_132) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_132) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( u8 * )((u8 *)(temp_2_132) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_132) + (0x47))) & 0xDF));
            (*( s64 * )((u8 *)(temp_2_132) + (0x60))) = temp_16;
            func_00194590(temp_2_132, 3);
            temp_2_133 = (u8 *)(func_00202590((s32)((*( u8 ** )((u8 *)(arg0) + (0x30)))), 0, 0));
            (*( s8 * )((u8 *)(temp_2_133) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_133) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( u8 * )((u8 *)(temp_2_133) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_133) + (0x47))) & 0xDF));
            (*( s64 * )((u8 *)(temp_2_133) + (0x60))) = temp_16;
            func_00194590(temp_2_133, 3);
        } else {
            func_001f0a10((u8 *)&result);
            result.addedStatus = 0x80000;
            var_18_4 = (u8 *)(func_001f36e0((s32)(arg0), (s32)(arg0), &result, 1U, 1U));
            if (sp2D0 == 1) {
                (*( s8 * )((u8 *)(var_18_4) + (0))) = 4;
                (*( s64 * )((u8 *)(var_18_4) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(sp4C8) + (0x58))));
            } else {
                (*( s8 * )((u8 *)(var_18_4) + (0))) = 0xB;
                (*( s64 * )((u8 *)(var_18_4) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_17_6) + (0x58))));
            }
            (*( s64 * )((u8 *)(var_18_4) + (0x60))) = temp_16;
            func_00194590(var_18_4, 1);
        }
        if (sp2C0 == 0) {
            if (sp2F0 == 0) {
                if (sp30C == 0) {
                    var_19 = (u8 *)(func_0019a0c0((*( u8 ** )((u8 *)(arg0) + (0x30))), sp350));
                } else {
                    var_19 = (u8 *)(func_0019ac40((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
                }
                (*( s8 * )((u8 *)(var_19) + (0))) = 4;
                (*( s64 * )((u8 *)(var_19) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
                (*( s64 * )((u8 *)(var_19) + (0x60))) = temp_16;
                func_00194590(var_19, 0);
            } else {
                temp_2_134 = (u8 *)(func_0019a980((*( u8 ** )((u8 *)(arg0) + (0x30)))));
                var_19 = (u8 *)(temp_2_134);
                (*( s8 * )((u8 *)(temp_2_134) + (0))) = 4;
                (*( s64 * )((u8 *)(temp_2_134) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
                (*( s64 * )((u8 *)(temp_2_134) + (0x60))) = temp_16;
                func_00194590(var_19, 0);
            }
        }
        temp_4_20 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
        if ((*( s32 * )((u8 *)(temp_4_20) + (0x9C))) & 0x20) {
            temp_2_135 = (u8 *)(func_00194b60(temp_4_20));
            (*( s8 * )((u8 *)(temp_2_135) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_135) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( s16 * )((u8 *)(temp_2_135) + (0x4A))) = 0x3C;
            (*( s64 * )((u8 *)(temp_2_135) + (0x60))) = temp_16;
            func_00194590(temp_2_135, 1);
        } else {
            temp_2_136 = (u8 *)(func_0019bbe0(temp_4_20, 0xFFFFFF, 6, 0, 4, 0));
            (*( s8 * )((u8 *)(temp_2_136) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_136) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( s64 * )((u8 *)(temp_2_136) + (0x60))) = temp_16;
            func_00194590(temp_2_136, 1);
            temp_5_5 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
            temp_2_137 = (u8 *)(func_001d6240((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD48))), temp_5_5, temp_5_5, 0, 0));
            (*( s8 * )((u8 *)(temp_2_137) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_137) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( s64 * )((u8 *)(temp_2_137) + (0x60))) = temp_16;
            func_00194590(temp_2_137, 2);
            temp_2_138 = (u8 *)(func_001f7c20(0xA, 2, 0xA));
            (*( s8 * )((u8 *)(temp_2_138) + (0))) = 4;
            (*( s64 * )((u8 *)(temp_2_138) + (8))) = (s64)((s64) (*( s64 * )((u8 *)(var_18_4) + (0x58))));
            (*( s64 * )((u8 *)(temp_2_138) + (0x60))) = temp_16;
            func_00194590(temp_2_138, 1);
            temp_3_20 = (u8 *)((*( u8 ** )((u8 *)(arg0) + (0x30))));
            (*( s64 * )((u8 *)(temp_3_20) + (0x9C))) = (s64)((s64) ((*( s64 * )((u8 *)(temp_3_20) + (0x9C))) | 0x100));
        }
    } else if (sp2C0 == 0) {
        if (sp2F0 == 0) {
            if (sp30C == 0) {
                var_19 = (u8 *)(func_0019a0c0((*( u8 ** )((u8 *)(arg0) + (0x30))), sp350));
            } else {
                var_19 = (u8 *)(func_0019ac40((BtlUnit *)(*( u8 ** )(arg0 + 0x30)), 0, 1.0f, 0));
            }
            (*( s8 * )((u8 *)(var_19) + (0))) = 0xB;
            *(s64 *)(var_19 + 8) = *(s64 *)(var_17_6 + 0x58);
            if (temp_23_2 == 0) {
                (*( s16 * )((u8 *)(var_19) + (0x48))) = sp440;
            } else {
                (*( s16 * )((u8 *)(var_19) + (0x48))) = 8;
                if (sp440 > 8) {
                    var_2_14 = sp440 - 8;
                } else {
                    var_2_14 = 0;
                }
                (*( s16 * )((u8 *)(var_19) + (0x4A))) = var_2_14;
            }
            (*( s64 * )((u8 *)(var_19) + (0x60))) = temp_16;
            func_00194590(var_19, 0);
        } else {
            temp_2_139 = (u8 *)(func_0019a980((*( u8 ** )((u8 *)(arg0) + (0x30)))));
            var_19 = (u8 *)(temp_2_139);
            (*( s8 * )((u8 *)(temp_2_139) + (0))) = 0xB;
            *(s64 *)(temp_2_139 + 8) = *(s64 *)(var_17_6 + 0x58);
            (*( s16 * )((u8 *)(temp_2_139) + (0x48))) = sp440;
            (*( s64 * )((u8 *)(temp_2_139) + (0x60))) = temp_16;
            func_00194590(var_19, 0);
        }
    }
    temp_2_140 = (u8 *)(func_001b7e20(0x10));
    (*( s8 * )((u8 *)(temp_2_140) + (0))) = 4;
    *(s64 *)(temp_2_140 + 8) = *(s64 *)(var_19 + 0x58);
    (*( u8 * )((u8 *)(temp_2_140) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_140) + (0x47))) & 0xDF));
    (*( s64 * )((u8 *)(temp_2_140) + (0x60))) = temp_16;
    func_00194590(temp_2_140, 1);
    if (sp310 != 0) {
        var_2_15 = 2;
    } else {
        var_2_15 = 0;
    }
    temp_2_141 = (u8 *)(func_001b9360(0x10, var_2_15 & 0xFFFF));
    (*( s8 * )((u8 *)(temp_2_141) + (0))) = 4;
    *(s64 *)(temp_2_141 + 8) = *(s64 *)(var_19 + 0x58);
    (*( u8 * )((u8 *)(temp_2_141) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_141) + (0x47))) & 0xDF));
    (*( s64 * )((u8 *)(temp_2_141) + (0x60))) = temp_16;
    func_00194590(temp_2_141, 1);
    temp_2_142 = (u8 *)(func_001b99a0(0x10));
    (*( s8 * )((u8 *)(temp_2_142) + (0))) = 4;
    *(s64 *)(temp_2_142 + 8) = *(s64 *)(var_19 + 0x58);
    (*( u8 * )((u8 *)(temp_2_142) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_142) + (0x47))) & 0xDF));
    (*( s64 * )((u8 *)(temp_2_142) + (0x60))) = temp_16;
    func_00194590(temp_2_142, 1);
    temp_2_143 = (u8 *)(func_001ba090(8));
    (*( s8 * )((u8 *)(temp_2_143) + (0))) = 4;
    *(s64 *)(temp_2_143 + 8) = *(s64 *)(var_17_6 + 0x58);
    (*( u8 * )((u8 *)(temp_2_143) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_143) + (0x47))) & 0xDF));
    (*( s64 * )((u8 *)(temp_2_143) + (0x60))) = temp_16;
    func_00194590(temp_2_143, 0);
    if (((s32)(s32)sp200 == 1) && ((s32)(s32)sp1F0 == 0) && ((s32)(s32)sp220 == 0)) {
        if (sp320 == 0) {
            if (!((*( u16 * )(temp_30_ptr + (2))) & 0x40)) {
                if (temp_23_2 == 0) {
                    var_2_16 = 0x19;
                } else {
                    var_2_16 = 0x1A;
                }
                temp_2_144 = (u8 *)(btlCameraCreateSetStatePacket(arg0, var_2_16 & 0xFFFF));
                (*( s8 * )((u8 *)(temp_2_144) + (0))) = 5;
                (*( s64 * )((u8 *)(temp_2_144) + (8))) = sp470;
                (*( s64 * )((u8 *)(temp_2_144) + (0x60))) = temp_16;
                func_00194590(temp_2_144, 0);
            }
        } else {
            temp_2_145 = (u8 *)(btlCameraCreateSetStatePacket(arg0, 0x1D));
            (*( s8 * )((u8 *)(temp_2_145) + (0))) = 5;
            (*( s64 * )((u8 *)(temp_2_145) + (8))) = sp470;
            (*( s64 * )((u8 *)(temp_2_145) + (0x60))) = temp_16;
            func_00194590(temp_2_145, 0);
        }
        if (sp310 == 0) {
            temp_2_146 = (u8 *)(func_0019bbe0((*( u8 ** )((u8 *)(arg0) + (0x30))), -1, 0, 0xC, 3, 0));
            (*( s8 * )((u8 *)(temp_2_146) + (0))) = 0xB;
            *(s64 *)(temp_2_146 + 8) = *(s64 *)(var_17_6 + 0x58);
            (*( s64 * )((u8 *)(temp_2_146) + (0x60))) = temp_16;
            func_00194590(temp_2_146, 1);
        }
        temp_2_147 = (u8 *)(func_0019bbe0(sp4D0, 0xFFFFFF, 8, 0, 4, 0));
        (*( s8 * )((u8 *)(temp_2_147) + (0))) = 0xB;
        *(s64 *)(temp_2_147 + 8) = *(s64 *)(var_17_6 + 0x58);
        if (sp33C != 0) {
            if ((s32)(s32)sp1E0 == 0) {
                goto block_481;
            }
            var_2_17 = 7;
        } else {
block_481:
            var_2_17 = 0xF;
        }
        (*( s16 * )((u8 *)(temp_2_147) + (0x48))) = var_2_17;
        (*( s64 * )((u8 *)(temp_2_147) + (0x60))) = temp_16;
        func_00194590(temp_2_147, 1);
        temp_2_148 = (u8 *)(func_001d65d0((*( s32 * )((u8 *)(iGpffffb3ac) + (0xD70))), (s32)sp4D0, sp400, 0, 0x2100));
        (*( s8 * )((u8 *)(temp_2_148) + (0))) = 4;
        *(s64 *)(temp_2_148 + 8) = sp480;
        (*( s64 * )((u8 *)(temp_2_148) + (0x60))) = temp_16;
        func_00194590(temp_2_148, 2);
    }
    if (sp310 == 1) {
        temp_2_149 = (u8 *)(btlCreateSetFlagsPacket(0x80));
        (*( s8 * )((u8 *)(temp_2_149) + (0))) = 4;
        *(s64 *)(temp_2_149 + 8) = *(s64 *)(var_17_6 + 0x58);
        (*( s16 * )((u8 *)(temp_2_149) + (0x48))) = 0xC;
        (*( s64 * )((u8 *)(temp_2_149) + (0x60))) = temp_16;
        func_00194590(temp_2_149, 1);
        temp_2_150 = (u8 *)(func_00202850());
        (*( s8 * )((u8 *)(temp_2_150) + (0))) = 4;
        *(s64 *)(temp_2_150 + 8) = *(s64 *)(var_19 + 0x58);
        (*( u8 * )((u8 *)(temp_2_150) + (0x47))) = (u8)((u8) ((*( u8 * )((u8 *)(temp_2_150) + (0x47))) & 0xDF));
        (*( s64 * )((u8 *)(temp_2_150) + (0x60))) = temp_16;
        func_00194590(temp_2_150, 1);
    }
    if (sp340 == 0) {
        func_001d3e00(sp4A0);
    }
    if ((s32)(s32)sp1D0 != 0) {
        cutin.mode = 3;
        cutin.unitId = (u16)((u16)((*( u16 * )((u8 *)((*( u8 ** )((u8 *)((*( u8 ** )((u8 *)(arg0) + (0x8C)))) + (0x30)))) + (0xA4)))));
        func_00194590(func_001fa720((u8 *)&cutin), 1);
    }
    if ((s32)(func_001f68e0(arg0)) != (s32)(0)) {
        btlActionSetState(arg0, 0x1BU);
        return;
    }
    temp_3_21 = (u16)((u16)((*( u16 * )((u8 *)(arg0) + (0x6C)))));
    if ((temp_3_21 != 2) && (temp_3_21 != 3) && (temp_3_21 != 1)) {

    }
    btlActionSetState(arg0, 0x20U);
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_001a", func_001a7720);
#endif
// FUN_001ABBA0
void func_001abba0(void)
{
}
/* Measured 2026-09-28: 2384/2384 bytes, resolved code/data references and
 * all 70 sibling functions unchanged. Packed colors, the halfword skill
 * selector, and packet/ID lifetimes retain the 0x170 frame. The formation
 * filename is a 128-byte string; encounter insertion returns DatUnit*. */
// FUN_001ABBB0
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
void func_001abbb0(s64 *arg0)
{
    typedef struct DatUnit DatUnit;
    typedef struct DatUnitEc DatUnitEc;
    extern s32 func_001d3d50(u32 arg0);
    extern void func_001d3e00(u32 arg0);
    extern BtlPacket *func_00202010(u32 arg0, u16 arg1);
    extern u8 *func_001f3b20(u8 *arg0);
    extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_001b7080(s32 arg0);
    extern s32 func_001b7090(s32 arg0);
    extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
    extern BtlPacket *func_001b7880(u32 arg0, u32 arg1, u32 arg2);
    extern BtlPacket *func_001b83f0(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    extern BtlPacket *func_001b9560(u32 arg0, u32 arg1);
    extern BtlPacket *btlSoundCreateSkillSEPacket(u16 arg0, u16 arg1);
    extern u8 *func_00194b60(void);
    extern u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2);
    extern void func_0019ea60(u8 *arg0, s32 arg1);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern BtlPacket *func_0019c030(BtlUnit *arg0, u16 arg1, u16 arg2);
    extern BtlPacket *func_001b7e20(u32 arg0);
    extern BtlPacket *func_001b9360(s32 arg0, s16 arg1);
    extern BtlPacket *func_001b99a0(s32 arg0);
    extern s32 func_001f68e0(u8 *arg0);
    extern DatUnit *func_002317a0(DatUnitEc *encounter, u16 id);
    extern u8 *iGpffffb3bc;
    typedef struct UnitView {
        u8 unknown00[4];
        RwV3d pos;
        u8 unknown10[0x94 - 0x10];
        s16 value94;
        s16 value96;
        u8 unknown98[0xA64 - 0x98];
        DatUnit *data;
    } UnitView;
    /* Unit APIs consume pointers; formation APIs consume their EE word representation. */
    typedef union UnitReference {
        UnitView *pointer;
        u32 address;
        s32 signedAddress;
    } UnitReference;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x28];
        UnitReference unitRef;
        u8 unknown34[0x38];
        u16 mode;
        s16 aux;
        u8 unknown70[6];
        u16 ids[3];
    } ActionView;
    s32 outHi;
    s32 outLo;
    char workBuf[128];
    s32 firstDone;
    s32 off;
    ActionView *action;
    s64 uid;
    s16 auxRaw;
    u8 *seqPkt;
    s64 evId;
    u16 selector;
    u32 aux;
    s32 handle;
    u8 *evPkt;
    UnitView *unit;
    s64 seqId;
    s32 scaleTmp;
    u8 *holdPkt;
    u8 *tailPkt;
    u32 idx;

    action = (ActionView *)arg0;
    auxRaw = action->aux;
    uid = action->uid;
    func_001a03b0(arg0);
    handle = func_001d3d50(1);
    selector = (u16)auxRaw;
    aux = selector;
    {
        u8 *pkt;
        pkt = (u8 *)func_00202010((u32)action->unitRef.pointer, selector);
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 3);
    }
    {
        u8 *pkt;
        pkt = func_001f3b20((u8 *)action);
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = func_001f3870((u8 *)action, 0);
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    evPkt = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)action->unitRef.pointer, 8, 6, 1.0f, 0);
    *(s64 *)(evPkt + 0x60) = uid;
    func_00194590(evPkt, 0);
    {
        u8 *pkt;
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x15);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(evPkt + 0x58);
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 0);
    }
    evId = *(s64 *)(evPkt + 0x58);
    scaleTmp = func_001991c0((u8 *)action->unitRef.pointer, 8, 1.0f);
    func_001b7060(aux, &outHi, &outLo);
    {
        u8 *pkt;
        pkt = (u8 *)func_001b7880((u32)outHi, (u32)outLo, 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        s32 kind;
        u8 *pkt;
        kind = func_001b7080(aux);
        func_001b70a0(aux, &outHi, &outLo);
        pkt = (u8 *)func_001b83f0(kind, outHi, outLo, 0x10, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001b9560(func_001b7090(aux), 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001b9de0((BtlAction *)action, aux, 0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = evId;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    func_001d69f0(aux, workBuf);
    seqPkt = (u8 *)func_001d5eb0(handle, workBuf, 0);
    *seqPkt = 4;
    *(s64 *)(seqPkt + 8) = 0;
    *(s16 *)(seqPkt + 0x48) = scaleTmp + 6;
    *(s64 *)(seqPkt + 0x60) = uid;
    func_00194590(seqPkt, 1);
    holdPkt = (u8 *)btlSoundCreateSkillSEPacket(selector, 0);
    *holdPkt = 4;
    *(s64 *)(holdPkt + 8) = *(s64 *)(seqPkt + 0x58);
    func_00194590(holdPkt, 1);
    {
        u8 *pkt;
        u8 *next;
        pkt = (u8 *)func_001d6240(handle, action->unitRef.address, action->unitRef.address, 0, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(seqPkt + 0x58);
        *(pkt + 0x10) = 4;
        *(s64 *)(pkt + 0x18) = *(s64 *)(holdPkt + 0x58);
        func_00194590(pkt, 2);
        next = (u8 *)func_001f8140(0);
        *next = 5;
        *(s64 *)(next + 8) = *(s64 *)(pkt + 0x58);
        func_00194590(next, 1);
    }
    seqId = *(s64 *)(seqPkt + 0x58);
    tailPkt = func_00194b60();
    *tailPkt = 4;
    *(s64 *)(tailPkt + 8) = seqId;
    *(s16 *)(tailPkt + 0x48) = 0x18;
    *(s64 *)(tailPkt + 0x60) = uid;
    func_00194590(tailPkt, 1);
    tailPkt = func_001d65d0(*(s32 *)(iGpffffb3ac + 0xD40), action->unitRef.signedAddress, 0, *(s64 *)(tailPkt + 0x58), 0x100);
    *tailPkt = 4;
    *(s64 *)(tailPkt + 8) = *(s64 *)(evPkt + 0x58);
    *(s64 *)(tailPkt + 0x60) = uid;
    func_00194590(tailPkt, 1);
    {
        u8 *pkt;
        pkt = (u8 *)func_001f7c20(10, 2, 7);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(evPkt + 0x58);
        func_00194590(pkt, 1);
    }
    firstDone = 0;
    idx = 0;
    off = (s32)auxRaw * 4;
    for (; (u16)idx < 3; idx = (u16)(idx + 1)) {
        u16 curId;
        u8 *loopPkt;
        curId = action->ids[(u16)idx];
        if (curId == 0) {
            break;
        }
        loopPkt = func_0019f5f0(1, curId, NULL);
        unit = ((UnitReference *)(loopPkt + 0x30))->pointer;
        unit->data = func_002317a0(*(DatUnitEc **)(iGpffffb3ac + 0xC68), curId);
        func_0019ea60((u8 *)unit, curId & 0xFFFF);
        unit->value94 = action->unitRef.pointer->value94;
        unit->value96 = action->unitRef.pointer->value96;
        unit->pos = action->unitRef.pointer->pos;
        if (firstDone == 0) {
            {
                u8 *pkt;
                pkt = (u8 *)func_001d3900(0);
                *pkt = 4;
                *(s64 *)(pkt + 8) = seqId;
                *(s64 *)(pkt + 0x60) = uid;
                func_00194590(pkt, 0);
            }
            {
                u8 *pkt;
                pkt = (u8 *)func_001d3700(1, 0xFFF);
                *pkt = 4;
                *(s64 *)(pkt + 8) = seqId;
                *(s64 *)(pkt + 0x60) = uid;
                func_00194590(pkt, 0);
            }
            if ((*(u16 *)((u32)off + (u32)iGpffffb3bc + 2) & 0x40) == 0) {
                {
                    u8 *pkt;
                    pkt = (u8 *)func_001d7a10(5);
                    *pkt = 4;
                    *(s64 *)(pkt + 8) = seqId;
                    *(s64 *)(pkt + 0x60) = uid;
                    func_00194590(pkt, 0);
                }
                {
                    u8 *pkt;
                    pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x2D);
                    *pkt = 4;
                    *(s64 *)(pkt + 8) = seqId;
                    *(s64 *)(pkt + 0x60) = uid;
                    func_00194590(pkt, 0);
                }
            }
            firstDone = 1;
        }
        {
            u8 *q1;
            u8 *q2;
            u8 *q3;
            q1 = func_0019b550((u8 *)unit, curId, 0x7E);
            *q1 = 4;
            *(s64 *)(q1 + 8) = seqId;
            *(s64 *)(q1 + 0x60) = uid;
            func_00194590(q1, 1);
            q2 = (u8 *)func_0019c030((BtlUnit *)unit, curId, 0x10);
            *q2 = 4;
            *(s64 *)(q2 + 8) = *(s64 *)(q1 + 0x58);
            func_00194590(q2, 1);
            q3 = (u8 *)func_001d6240(handle, action->unitRef.address, ((UnitReference *)(loopPkt + 0x30))->address, 1, 0x100);
            *q3 = 4;
            *(s64 *)(q3 + 8) = *(s64 *)(q2 + 0x58);
            *(q3 + 0x10) = 4;
            *(s64 *)(q3 + 0x18) = *(s64 *)(holdPkt + 0x58);
            *(s64 *)(q3 + 0x60) = uid;
            func_00194590(q3, 2);
            tailPkt = q3;
            {
                u8 *q4;
                q4 = (u8 *)func_001f8140(1);
                *q4 = 5;
                *(s64 *)(q4 + 8) = *(s64 *)(q3 + 0x58);
                func_00194590(q4, 1);
            }
            if (((u16)idx == 0) && (action->ids[1] == 0)) {
                u8 *q5;
                q5 = (u8 *)func_00202400(((UnitReference *)(loopPkt + 0x30))->signedAddress, 0x9F);
                *q5 = 5;
                *(s64 *)(q5 + 8) = *(s64 *)(q3 + 0x58);
                *(s16 *)(q5 + 0x48) = 0x1C;
                func_00194590(q5, 3);
            }
            {
                u8 *q6;
                q6 = func_0019bbe0((u8 *)unit, -1, 0xC, 0, 3, 1);
                *q6 = 4;
                *(s64 *)(q6 + 8) = *(s64 *)(q2 + 0x58);
                *(q6 + 0x10) = 0xB;
                *(s64 *)(q6 + 0x18) = *(s64 *)(q3 + 0x58);
                *(s16 *)(q6 + 0x48) = 1;
                *(s64 *)(q6 + 0x60) = uid;
                func_00194590(q6, 1);
            }
            seqId = *(s64 *)(q2 + 0x58);
        }
    }
    {
        u8 *pkt;
        pkt = (u8 *)actionTargetPacketBytes((u8 *)action, 9, 0, 0, 0);
        *pkt = 0xB;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001b7e20(0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001b9360(0x10, 0);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001b99a0(0x10);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 1);
    }
    {
        u8 *pkt;
        pkt = (u8 *)func_001ba090(8);
        *pkt = 4;
        *(s64 *)(pkt + 8) = *(s64 *)(tailPkt + 0x58);
        *(pkt + 0x47) &= ~0x20;
        *(s64 *)(pkt + 0x60) = uid;
        func_00194590(pkt, 0);
    }
    func_001d3e00(handle);
    if (func_001f68e0((u8 *)action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
    } else {
        u16 nextState;
        switch (action->mode) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}

#pragma pop
// FUN_001AC500
void func_001ac500(s64 *arg0) {
    u8 *temp_2;
    u8 *temp_2_2;

    func_001a03b0(arg0);
    func_001eb3b0((u8 *)arg0 + 0x38);
    func_001dbf20(arg0, 0);
    func_001a03b0(arg0);
    temp_2 = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *arg0;
    func_00194590(temp_2, 0);
    temp_2_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x2C);
    *(s64 *)(temp_2_2 + 0x60) = *arg0;
    func_00194590(temp_2_2, 0);
    *(u16 *)((u8 *)arg0 + 0x18) |= 2;
}



// FUN_001AC5B0
void func_001ac5b0(s64 *arg0) {
    if ((func_00193cd0(0x506) == 0) && (func_00193cd0(0x800) == 0)) {
        *(u16 *)((u8 *)(arg0) + 0x18) = (u16) (*(u16 *)((u8 *)(arg0) + 0x18) | 0x100);
        btlActionSetState((BtlAction *)arg0, 0xFU);
    }
}

// FUN_001AC620
void func_001ac620(void) {
    u8 *p = *(u8 **)(D_0076449C + 0x174);
    u8 *o;

    while (p != NULL) {
        if (func_001a05f0(p) != 0) {
            o = (u8 *)func_0019b6a0(*(BtlUnit **)(*(u8 **)(p + 0x30) + 0xA0C));
            *(s64 *)(o + 0x60) = *(s64 *)p;
            func_00194590(o, 1);
        }
        p = *(u8 **)(p + 0x450);
    }
}

// FUN_001AC6A0
void func_001ac6a0(u8 *arg0) {
    if ((*(s32 (**)(void))(arg0 + 0x440))() == 0) {
        btlActionSetState((BtlAction *)arg0, *(u16 *)(arg0 + 0x43C));
    }
}

// FUN_001AC6F0
void func_001ac6f0(void)
{
}

/* This view covers every resource slot used by this action (through 0x21). */
typedef struct ActionResourcePrefix {
    u8 beforeResources[0xD04];
    s32 resources[0x22];
} ActionResourcePrefix;
static inline s32 actionResourceAt(ActionResourcePrefix *table, u16 index)
{
    return table->resources[index];
}
/* Queue this action's animation, effect, camera and dependent state changes.
 * Native b210 O2: 1036 executable bytes and four zero alignment bytes;
 * all neighboring functions and allocated data remain unchanged.
 * See docs/probe_archive/Action_animation_sequence_001ac700_20260924.md. */
// FUN_001AC700
void func_001ac700(u8 *action) {
    s64 packetIdentity;
    s32 alternateAction;
    s32 animationChoice;
    f32 speed;
    u16 actionKind;
    u8 *animationPacket;

    BtlPacket *func_00202010(u32 action, u16 arg1);
    BtlPacket *func_00202120(u32 action, u16 arg1);
    BtlPacket *func_001b9360(s32 action, s16 mode);
    BtlPacket *func_001b7e20(u32 value);
    BtlPacket *func_001b99a0(s32 action);


    struct {
        u16 resource;
        u16 animation;
        u16 frames;
        u16 cameraState;
    } selection;

    func_001a03b0((s64 *)action);
    alternateAction = (*(u16 *)(action + 0x6C) == 3);
    packetIdentity = *(s64 *)action;
    if (alternateAction == 0) {
        u8 *packet;
        packet = (u8 *)func_00202010(*(s32 *)(action + 0x30),
                               *(u16 *)(action + 0x6E));
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 3);
    } else {
        u8 *packet;
        packet = (u8 *)func_00202120(*(s32 *)(action + 0x30),
                               *(u16 *)(action + 0x70));
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 3);
    }
    if ((*(u8 **)(action + 0x30))[0xA2] == 0) {
        if (alternateAction == 0) {
            selection.animation = (s64)0xD;
            selection.resource = (s64)0xB;
        } else {
            selection.animation = (s64)0x16;
            selection.resource = (s64)0x21;
        }
        selection.cameraState = 0x14;
        selection.frames = func_00199500(*(u8 **)(action + 0x30),
                               selection.animation, 1.0f);
        speed = 1.0f;
    } else {
        if (func_001f11e0(*(s16 *)(action + 0x6E)) != 0) {
            animationChoice = 4;
        } else {
            animationChoice = 8;
        }
        selection.animation = (u16)animationChoice;
        selection.resource = (s64)0xF;
        selection.cameraState = 0x15;
        if (*(u16 *)(action + 0x18) & 0x4000) {
            speed = 2.0f;
        } else {
            speed = 1.0f;
        }
        selection.frames = func_001991c0(*(u8 **)(action + 0x30),
                               selection.animation, speed);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                 (s16)selection.animation, 6, speed, 0);
    *(s64 *)(animationPacket + 0x60) = packetIdentity;
    *(s16 *)(animationPacket + 0x4A) = (s16)((selection.frames & 0xFFFF) + 6);
    func_00194590(animationPacket, 0);
    {
        u8 *packet;
        packet = func_001d65d0(
            actionResourceAt((ActionResourcePrefix *)D_0076449C, (u16)selection.resource),
            *(s32 *)(action + 0x30), 0,
            *(s64 *)(animationPacket + 0x58), 0x100);
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 2);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, selection.cameraState);
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)actionMessagePacketBytes(*(s32 *)(action + 0x30),
                               *(s16 *)(action + 0xEC));
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 3);
    }
    {
        u8 *packet;
        packet = func_001f3870(action, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001b7e20(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001b9360(0x10, 0);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001b99a0(0x10);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)func_001ba090(8);
        *(s8 *)(packet + 0) = 4;
        *(s64 *)(packet + 8) = *(s64 *)(animationPacket + 0x58);
        *(u8 *)(packet + 0x47) &= ~0x20;
        *(s64 *)(packet + 0x60) = packetIdentity;
        func_00194590(packet, 0);
    }
    if (func_001f68e0(action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
        return;
    }
    actionKind = *(u16 *)(action + 0x6C);
    {
        u16 nextState;
        switch (actionKind) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}
// FUN_001ACB10
void func_001acb10(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_5_4;

    temp_5 = *(u16 *)(arg0 + 0x3F4);
    switch (temp_5) {
    case 0x20F:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x400;
        break;
    case 0x210:
        temp_5_4 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp_5_4 = *(u16 *)temp_5_4 | 0x800;
        break;
    }
    if (*(u16 *)(arg0 + 0x3F4) == 0) {
        temp_5_4 = *(u8 **)(arg0 + 0x30);
        *(s32 *)(temp_5_4 + 0x9C) = *(s32 *)(temp_5_4 + 0x9C) & ~0x10;
        btlActionSetState((BtlAction *)arg0, *(u16 *)(arg0 + 0x430));
    }
}
// FUN_001ACBB0
void func_001acbb0(u8 *arg0) {
    s32 sp80[8];
    s32 temp_19;
    s32 temp_2_4;
    s32 temp_4;
    s32 var_17;
    s64 temp_20;
    s64 temp_21;
    s64 var_2;
    s64 var_2_2;
    s64 var_2_3;
    u16 temp_3;
    u8 *temp_16;
    u8 *temp_2_2;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;

    s32 func_00106600(s16 id);
    u8 *btlCreateRemoveFlagsPacket(s32 arg0);
    u8 *func_00194b60(void);
    void func_001f0a10(u8 *arg0);
    extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *func_00201de0(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);

    extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
    void btlActionSetState(u8 *arg0, u16 arg1);
    u8 *func_00202740(u8 *arg0);
    u32 datCalcGetHp(u8 *arg0);
    u32 func_00231f80(u8 *arg0);

    temp_16 = *(u8 **)((u8 *)arg0 + 0x30);
    *(s32 *)(temp_16 + 0x9C) &= ~0x10;
    if (func_00193cd0(0xFF03) == 0) {
        temp_4 = *(s32 *)(D_0076449C + 0xC);
        if (!(temp_4 & 0x80000)) {
            *(s32 *)(D_0076449C + 0xC) = temp_4 | 0x80000;
            var_17 = 1;
        } else {
            var_17 = 0;
        }
        temp_3 = *(u16 *)(arg0 + 0x3F4);
        switch (temp_3) {
        case 0x210:
            if (temp_16[0xA2] == 0) {
                var_2 = 0x3E;
            } else {
                var_2 = 0x3F;
            }
            var_2_2 = (s16)var_2;
            break;
        case 0x154:
            var_2_2 = 0x9B;
            break;
        case 0x231:
            var_2_2 = 0xB4;
            break;
        case 0x232:
            var_2_2 = 0xB6;
            break;
        default:
            if (temp_16[0xA2] == 0) {
                var_2_3 = 0x3C;
            } else {
                var_2_3 = 0x3D;
            }
            var_2_2 = (s16)var_2_3;
            break;
        }
        temp_19 = (s16)var_2_2;
        temp_2_2 = actionMessagePacketBytes((s32)*(u8 **)(arg0 + 0x30),
                                 temp_19);
        *(s16 *)(temp_2_2 + 0x48) = 8;
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 3);
        temp_21 = *(s64 *)(temp_2_2 + 0x58);
        temp_2_2 = func_00194b60();
        *(s16 *)(temp_2_2 + 0x48) = 8;
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2_2, 0);
        temp_20 = *(s64 *)(temp_2_2 + 0x58);
        if (*(u16 *)(arg0 + 0x3F4) == 0x154) {
            temp_2_4 = func_00106600(0x340) & 0xFF;
            if (temp_2_4 > 0) {
                func_00106620(0x340, (temp_2_4 - 1) & 0xFF);
            }
        }
        if (*(u16 *)(arg0 + 0x3F4) == 0x210) {
            func_001f0a10((u8 *)&sp80);
            temp_19 = func_00231f80(*(u8 **)(temp_16 + 0xA64)) & 0xFFFF;
            sp80[0] = temp_19 - (datCalcGetHp(*(u8 **)(temp_16 + 0xA64)) & 0xFFFF);
            temp_2_5 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0,
                                     &sp80, 1, 1);
            *(s8 *)(temp_2_5 + 0) = 4;
            *(s64 *)(temp_2_5 + 8) = temp_20;
            *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_5, 1);
            temp_2_6 = func_00202740(temp_16);
            *(s8 *)(temp_2_6 + 0) = 4;
            *(s64 *)(temp_2_6 + 8) = temp_20;
            *(s64 *)(temp_2_6 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_6, 1);
            temp_2_7 = func_00201de0((s32)temp_16, (s32)temp_16, -1, 0, 0,
                                     0, 1, (u8 *)&sp80, 0);
            *(s8 *)(temp_2_7 + 0) = 4;
            *(s64 *)(temp_2_7 + 8) = temp_20;
            *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_7, 3);
            temp_2_8 = func_00202590((s32)temp_16, 0, 0);
            *(s8 *)(temp_2_8 + 0) = 4;
            *(s64 *)(temp_2_8 + 8) = temp_20;
            *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_8, 3);
        }
        if (var_17 != 0) {
            temp_2_9 = btlCreateRemoveFlagsPacket(0x80000);
            *(s8 *)(temp_2_9 + 0) = 4;
            *(s64 *)(temp_2_9 + 8) = temp_21;
            *(s64 *)(temp_2_9 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2_9, 0);
        }
        btlActionSetState(arg0, *(u16 *)(arg0 + 0x430));
    }
}
// FUN_001ACF40
void func_001acf40(void)
{
}
// FUN_001ACF50
u8 *func_00194b60(void);
s32 func_00198810(u8 *arg0);

void func_001f0a10(u8 *arg0);
extern BtlPacket *func_001f36e0(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
s32 func_001f68e0(u8 *arg0);

void func_001acf50(u8 *arg0) {
    struct {
        s32 sp30;
        u8 pad[0x1A];
        u16 sp4E;
    } locals;
    u16 var_2;
    u8 *temp_2;
    u8 *temp_4;
    void func_001a03b0();
    u8 *var_16;

    switch (*(u16 *)(arg0 + 0x6C)) {
    case 7:
        func_001a03b0();
        temp_2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 0);
        if (*(s16 *)(arg0 + 0xEC) != 0) {
            temp_2 = actionMessagePacketBytes(*(s32 *)(arg0 + 0x30), *(s16 *)(arg0 + 0xEC));
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 3);
        } else {
            temp_4 = *(u8 **)(arg0 + 0x30);
            if ((*(s32 *)(temp_4 + 0x9C) & 0x4000) != 0) {
                var_2 = *(u16 *)(arg0 + 0x6C);
            } else {
                var_2 = 8;
            }
            temp_2 = func_002022e0((u32)temp_4, var_2 & 0xFFFF);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 3);
        }
        temp_2 = func_001f99c0(arg0, 0x16, 0, 0, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x4000) != 0) {
            temp_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x32);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
            if ((s16)func_00198810(*(u8 **)(arg0 + 0x30)) != 0x11) {
                var_16 = actionRecoveryPacketBytes((BtlUnit *)*(u8 **)(arg0 + 0x30));
                *(s64 *)(var_16 + 0x60) = *(s64 *)arg0;
                func_00194590(var_16, 0);
            } else {
                var_16 = func_00194b60();
                *(s64 *)(var_16 + 0x60) = *(s64 *)arg0;
                func_00194590(var_16, 0);
            }
            func_001f0a10((u8 *)&locals.sp30);
            locals.sp4E |= 0x80;
            temp_2 = (u8 *)func_001f36e0((s32)arg0, (s32)arg0, &locals.sp30, 1, 1);
            *(s8 *)(temp_2 + 0) = 4;
            *(s64 *)(temp_2 + 8) = *(s64 *)(var_16 + 0x58);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 1);
            temp_2 = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(arg0 + 0x30), 0x18, 6, 1.0f, 1);
            *(s8 *)(temp_2 + 0) = 4;
            *(s64 *)(temp_2 + 8) = *(s64 *)(var_16 + 0x58);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
        } else {
            temp_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0xA);
            *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
            func_00194590(temp_2, 0);
        }
        break;
    case 8:
    case 11:
        break;
    }
    func_00194590(func_001f3870(arg0, 0), 1);
    if ((func_001f68e0(arg0) != 0) && (*(u16 *)(arg0 + 0x6C) != 8)) {
        btlActionSetState((BtlAction *)arg0, 0x1B);
        return;
    }
    btlActionSetState((BtlAction *)arg0, 0x20);
}
// FUN_001AD280
void func_001ad280(u8 *arg0)
{
    s16 sp20[8];
    u8 *temp_2;

    func_001a03b0((s64 *)arg0);
    temp_2 = actionLookAtUnit(
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        *(u8 **)(arg0 + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    temp_2 = actionLookAtUnit(
        *(u8 **)(arg0 + 0x30),
        *(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30),
        0);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    *(u16 *)(arg0 + 0x18) |= 0x200;
    temp_2 = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    temp_2 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 9);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 0);
    sp20[0] = 5;
    temp_2 = func_001fa720((u8 *)&sp20[0]);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2, 1);
    if (func_001eb860() == 1) {
        *(s32 *)(D_0076449C + 0xC) &= ~0x2000;
        func_00212240(*(u8 **)(D_0076449C + 0xDD4), 0);
    }
    *(s32 *)(arg0 + 0x41C) = 0;
}
// FUN_001AD3E0
void func_001ad3e0(u8 *arg0)
{
    u8 *temp;

    if (*(s32 *)(arg0 + 0x41C) != 0) {
        goto common;
    }
    if (func_00193bf0(*(s64 *)arg0, 0x3FFFFFFFFFFFFFFFLL) != 0) {
        goto done;
    }
    func_00218420(*(s32 *)(D_0076449C + 0xDD4), arg0);
    temp = func_001fa8f0();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    *(s32 *)(arg0 + 0x41C) = 1;
common:
    if (func_002184a0(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
        goto done;
    }
    if (func_001eb860() != 1) {
        goto after_flag;
    }
    *(s32 *)(D_0076449C + 0xC) |= 0x2000;
    func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
after_flag:
    if (func_002184d0(*(s32 *)(D_0076449C + 0xDD4)) != 0) {
        goto alternate;
    }
    btlActionSetState((BtlAction *)arg0, 0x1D);
    goto after_state;
alternate:
    btlActionSetState((BtlAction *)arg0, 0x20);
after_state:
    temp = func_001faa60();
    *(s64 *)(temp + 0x60) = *(s64 *)arg0;
    func_00194590(temp, 1);
    func_00218500(*(s32 *)(D_0076449C + 0xDD4));
done:
    return;
}
// FUN_001AD540
void func_001ad540(void)
{
}
/* Measured: 1580 executable bytes and four zero tail bytes. The 129.6f
 * scale is a compiler literal at 0x00761440; its load follows vector X.
 * Typed action views and local packet lifetimes preserve the retail frame;
 * loop-invariant optimization retains the shared loop bound. */
// FUN_001AD550
#pragma opt_loop_invariants on
void func_001ad550(s64 *arg0)
{
    typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *arg0, RwV3d *arg1);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *quat);
    extern BtlPacket *btlCreateSetFlagsPacket(u32 arg0);
    extern RwV3d D_0060A100;
    extern f32 fGpffff8218;
    typedef struct UnitView {
        u8 unknown00[0xA2];
        u8 kind;
        u8 unknownA3;
        u16 index;
        u8 unknownA6[0xA64 - 0xA6];
        s32 data;
    } UnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x10];
        u16 flags18;
        u16 flags1A;
        u8 unknown1C[0x14];
        UnitView *unit;
        u8 unknown34[0x38];
        u16 mode;
        u8 unknown6E[0x450 - 0x6E];
        struct ActionView *next;
    } ActionView;
    ActionView *action;
    RwV3d outE0;
    RwV3d posD0;
    RwV3d vecC0;
    ActionView *collected[12];
    union {
        RtQuat rotation;
        f32 values[4];
    } quat80;
    u8 *first;
    u8 *stepPkt;
    ActionView *cur;
    ActionView *iter;
    s64 lastId;
    s32 listed;
    s32 spread;
    u16 count;
    u16 idx;

    action = (ActionView *)arg0;
    func_001a03b0(arg0);
    first = func_002022e0((u32)action->unit, 6);
    *(s64 *)(first + 0x60) = action->uid;
    func_00194590(first, 3);
    listed = 0;
    spread = 0;
    count = 0;
    lastId = 0;
    switch (action->unit->kind) {
    case 0:
        if (action->mode != 0xC) {
            *(u16 *)(iGpffffb3ac + 0xC5E) = *(u16 *)(iGpffffb3ac + 0xC5E) + 1;
            spread = 1;
            for (iter = *(ActionView **)(iGpffffb3ac + 0x174); iter != NULL; iter = iter->next) {
                if ((iter->flags1A & 1) != 0) {
                    if (iter->unit->kind == 0) {
                        if (datCalcIsDead(iter->unit->data, 0) == 0) {
                            if (datCalcChkBadStatus(iter->unit->data, 0x100001) == 0) {
                                collected[count] = iter;
                                count++;
                            }
                        }
                    }
                }
            }
            listed = 1;
        } else {
            collected[0] = action;
            count = 1;
            action->flags18 |= 0x20;
            action->flags1A &= 0xFFF7;
        }
        break;
    case 1:
        collected[0] = action;
        count = 1;
        action->flags18 |= 0x20;
        action->flags1A &= 0xFFF7;
        break;
    }
    if (listed == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)collected[0], 0xA);
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 0);
        }
    }
    if (action->unit->kind == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)func_001f7d10(0xF, 2, 0);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
            *(u16 *)(pkt + 0x48) = 0x1A;
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 1);
        }
        if (action->mode == 0xC) {
            {
                u8 *pkt;
                pkt = actionTargetPacketBytes((u8 *)action, 7, 0, 0, 0);
                *(s64 *)(pkt + 0x60) = action->uid;
                func_00194590(pkt, 1);
            }
        } else if (spread == 1) {
            {
                u8 *pkt;
                pkt = func_00202850();
                *pkt = 5;
                *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
                *(u16 *)(pkt + 0x48) = 0x10;
                *(s64 *)(pkt + 0x60) = action->uid;
                func_00194590(pkt, 1);
            }
        }
    } else {
        {
            u8 *pkt;
            pkt = (u8 *)func_001f7c20(0xC, 2, 0xF);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(first + 0x58);
            *(u16 *)(pkt + 0x48) = 0x16;
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 1);
        }
        {
            u8 *pkt;
            pkt = actionTargetPacketBytes((u8 *)action, 6, 0, 0, 0);
            *(u16 *)(pkt + 0x48) = 0xC;
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 1);
        }
    }
    for (idx = 0; idx < count; idx++) {
        cur = collected[idx];
        btlUnitGetSphereWorldCenter((BtlUnit *)cur->unit, &posD0);
        func_00194ff0((u8 *)cur->unit, NULL, quat80.values, NULL);
        RtQuatTransformVectors(&vecC0, &D_0060A100, 1, &quat80.rotation);
        if (action->unit->kind == 0) {
            vecC0.x = vecC0.x * 500.0f;
            vecC0.y = vecC0.y * 500.0f;
            vecC0.z = vecC0.z * 500.0f;
            outE0.x = posD0.x + vecC0.x;
            outE0.y = posD0.y + vecC0.y;
            outE0.z = posD0.z + vecC0.z;
            stepPkt = (u8 *)btlUnitCreateMovePacket((BtlUnit *)cur->unit, &outE0, 0.5f, 0);
        } else {
            if (*(s16 *)(iGpffffb3cc + (u32)cur->unit->index * 0xE8 + 0x22) != 1) {
                vecC0.x = vecC0.x * 129.6f;
                vecC0.y = vecC0.y * 129.6f;
                vecC0.z = vecC0.z * 129.6f;
                outE0.x = posD0.x + vecC0.x;
                outE0.y = posD0.y + vecC0.y;
                outE0.z = posD0.z + vecC0.z;
            } else {
                outE0 = posD0;
            }
            stepPkt = (u8 *)btlUnitCreateMovePacket((BtlUnit *)cur->unit, &outE0, fGpffff8218, 4);
        }
        *stepPkt = 5;
        *(s64 *)(stepPkt + 8) = *(s64 *)(first + 0x58);
        *(u16 *)(stepPkt + 0x48) = 0x10;
        *(s64 *)(stepPkt + 0x60) = action->uid;
        func_00194590(stepPkt, 1);
        {
            u8 *pkt;
            pkt = func_0019bbe0((u8 *)cur->unit, 0xFFFFFF, 8, 0, 4, 0);
            *pkt = 5;
            *(s64 *)(pkt + 8) = *(s64 *)(stepPkt + 0x58);
            *(u16 *)(pkt + 0x48) = 0xC;
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 1);
            lastId = *(s64 *)(pkt + 0x58);
        }
    }
    if (spread != 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCreateSetFlagsPacket(0x80);
            *pkt = 4;
            *(s64 *)(pkt + 8) = lastId;
            *(pkt + 0x10) = 0xA;
            *(u16 *)(pkt + 0x18) = 0x801;
            *(s64 *)(pkt + 0x60) = action->uid;
            func_00194590(pkt, 1);
        }
        *(u16 *)(iGpffffb3ac + 0x1C) = 3;
    }
    {
        u8 *pkt;
        pkt = func_001f3870((u8 *)action, 0);
        *(s64 *)(pkt + 0x60) = action->uid;
        func_00194590(pkt, 1);
    }
    btlActionSetState((BtlAction *)action, 0x20);
}
#pragma opt_loop_invariants off
/* Measured: 644/656 bytes, 22 resolved relocations and 12 zero tail bytes.
 * Packet submissions retain callback-visible unit, UID and global reloads. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_001ADB80
void func_001adb80(s64 *arg0)
{
    u16 person;
    u32 unit;
    s32 var_2;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_6;
    u8 *temp_7;

    temp_4 = *(u16 *)((u8 *)arg0 + 0x1A);
    if ((temp_4 & 1) == 0) {
        var_2 = 0;
    } else {
        temp_6 = *(u8 **)((u8 *)arg0 + 0x30);
        temp_7 = *(u8 **)(temp_6 + 0xA0C);
        if ((temp_4 & 0x10) == 0) {
            var_2 = 0;
        } else if ((*(s32 *)(temp_7 + 0x98) & 2) != 0) {
            var_2 = 1;
        } else {
            var_2 = 0;
        }
    }
    if (var_2 != 0) {
        temp_2 = (u8 *)func_0019b6a0(
            *(BtlUnit **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA0C));
        *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
        func_00194590(temp_2, 1);
    }
    func_001a03b0(arg0);
    temp_2_2 = func_002022e0(
        *(u32 *)((u8 *)arg0 + 0x30),
        *(u16 *)((u8 *)arg0 + 0x6C));
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_2, 3);
    temp_2_3 = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)arg0, 0x1F);
    *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_3, 0);
    temp_2_4 = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)((u8 *)arg0 + 0x30),
                             0x19, 0, 1.0f, 0);
    *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_4, 0);
    temp_2_5 = func_001f99c0((u8 *)arg0, 0x15, 0, 0, 0);
    *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_5, 1);
    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
        func_0010b300(*(u16 *)((u8 *)arg0 + 0x74));
        person = *(u16 *)((u8 *)arg0 + 0x74);
        func_0019ef30(*(u8 **)((u8 *)arg0 + 0x30), person);
        func_0010b7f0();
        if (datGetFlag(0x3C) != 0) {
            temp_2_6 = *(u8 **)((u8 *)arg0 + 0x3F0);
            if (temp_2_6 != NULL) {
                *(s16 *)(temp_2_6 + 6) = 0;
                *(s16 *)(*(u8 **)((u8 *)arg0 + 0x3F0) + 4) = 0;
            }
        }
    }
    unit = *(u32 *)((u8 *)arg0 + 0x30);
    temp_2_7 = (u8 *)func_001d6240(
        *(s32 *)(D_0076449C + 0xD3C),
        unit, unit,
        0, 0);
    *(s16 *)(temp_2_7 + 0x48) = 0xF;
    *(s64 *)(temp_2_7 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_7, 2);
    temp_2_8 = (u8 *)func_001f7c20(0xA, 2, 6);
    *(s8 *)(temp_2_8 + 0) = 5;
    *(s64 *)(temp_2_8 + 8) = *(s64 *)(temp_2_7 + 0x58);
    *(s64 *)(temp_2_8 + 0x60) = *(s64 *)arg0;
    func_00194590(temp_2_8, 1);
    *(s32 *)(D_0076449C + 0xC) |= 0x400000;
    *(u16 *)(D_0076449C + 0x18) |= 5;
}
#pragma pop

// FUN_001ADE10
void func_001ade10(s64 *arg0)
{
    void btlActionSetState(u8 *arg0, u16 arg1);

    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0xA2) == 0) {
            *(u16 *)((u8 *)arg0 + 0x18) &= 0xFBFF;
        }
        btlActionSetState((u8 *)arg0, *(u16 *)((u8 *)arg0 + 0x14));
    }
}
// FUN_001ADE90
void func_001ade90(void)
{
}

/* Queue the status-damage result and dependent display, animation and sound.
 * Native b210 O2: all 1312 bytes and every relocation match retail.
 * The result is a complete 32-byte object; the ID snapshot follows the
 * status query. See docs/probe_archive/Action_status_response_001adea0_20260924.md. */
// FUN_001ADEA0
void func_001adea0(u8 *action)
{
    u32 datCalcGetBadStatus(s32 unit);
    u8 *unit;
    s64 packetIdentity;
    u32 statusKind;
    u32 badStatus;
    struct {
        s32 hpDelta;
        s32 spDelta;
        u8 otherResults[22];
        u16 flags;
    } result;
    s32 delta;
    u8 *resultPacket;
    u8 *healthPacket;
    u8 *displayPacket;
    u8 *gaugePacket;
    u8 *animationPacket;
    u8 *soundPacket;

    if (func_00193cd0(0x700) == 0 && func_00193cd0(0x506) == 0 && func_00193cd0(0x507) == 0) {
        unit = *(u8 **)(action + 48);
        badStatus = datCalcGetBadStatus(*(s32 *)(unit + 2660));
        packetIdentity = *(s64 *)action;
        statusKind = badStatus & 0xFFFFF;
        switch (statusKind) {
        case 0x20:
            {
                func_001f0a10((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)func_001f6d60(action);
                result.hpDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)func_001f36e0((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)(resultPacket + 72) = 12;
                    func_00194590(resultPacket, 1);
                    healthPacket = func_00202740(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)(healthPacket + 8) = *(s64 *)(resultPacket + 88);
                    func_00194590(healthPacket, 1);
                    displayPacket = func_00201de0((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)(displayPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    func_00194590(displayPacket, 3);
                    gaugePacket = func_00202590((s32)unit, 0, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)(gaugePacket + 8) = *(s64 *)(resultPacket + 88);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    func_00194590(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 48), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)(animationPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(animationPacket + 32) = 10;
                    *(s16 *)(animationPacket + 40) = 769;
                    *(s64 *)(animationPacket + 96) = packetIdentity;
                    func_00194590(animationPacket, 0);
                    soundPacket = (u8 *)func_001f7c20(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)(soundPacket + 8) = *(s64 *)(resultPacket + 88);
                    func_00194590(soundPacket, 1);
                }
                {
                    u16 actionKind = *(u16 *)(action + 108);
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        case 0x40:
            {
                func_001f0a10((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)func_001f6d60(action);
                result.spDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)func_001f36e0((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)(resultPacket + 72) = 12;
                    func_00194590(resultPacket, 1);
                    healthPacket = func_00202740(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)(healthPacket + 8) = *(s64 *)(resultPacket + 88);
                    func_00194590(healthPacket, 1);
                    displayPacket = func_00201de0((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)(displayPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    func_00194590(displayPacket, 3);
                    gaugePacket = func_00202590((s32)unit, 1, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)(gaugePacket + 8) = *(s64 *)(resultPacket + 88);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    func_00194590(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 48), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)(animationPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(animationPacket + 32) = 10;
                    *(s16 *)(animationPacket + 40) = 769;
                    *(s64 *)(animationPacket + 96) = packetIdentity;
                    func_00194590(animationPacket, 0);
                    soundPacket = (u8 *)func_001f7c20(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)(soundPacket + 8) = *(s64 *)(resultPacket + 88);
                    func_00194590(soundPacket, 1);
                }
                {
                    u16 actionKind = *(u16 *)(action + 108);
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        default:
            {
                u16 actionKind = *(u16 *)(action + 108);
                u16 nextState;
                switch (actionKind) {
                case 1:
                case 3:
                case 2:
                    nextState = 32;
                    break;
                default:
                    nextState = 32;
                    break;
                }
                btlActionSetState((BtlAction *)action, nextState);
            }
            break;
        }
    }
}

// FUN_001AE3C0
s32 func_001ae3c0(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x428);
}

typedef struct ActionTargetTable {
    u8 beforeTargets[0xC48];
    u8 *targets[4];
    u16 count;
} ActionTargetTable;
static inline u8 *actionTargetAt(ActionTargetTable *table, u16 index)
{
    return table->targets[index];
}
/* Build the return-to-action packet sequence and select an available target.
 * Native b210 O2: 1072/1072 bytes, every relocation resolved; all other
 * owner functions and data preserved. See the 001ae3d0 recovery note. */
// FUN_001AE3D0
void func_001ae3d0(u8 *action)
{
    u8 *currentAction;
    u8 *target;
    u32 flags;
    u8 *targetAction;
    u8 *packet;
    /* The cut-in constructor copies ten bytes. Mode 1 uses only the
     * leading mode and unit ID; the remaining representation is opaque. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    u32 selectedAction;
    s32 changeFormation;
    u32 enemyCount;
    s16 previousFormation;
    u16 targetIndex;

    currentAction = *(u8 **)(iGpffffb3ac + 372);
    while (currentAction != NULL) {
        if (func_001a05f0(currentAction) != 0) {
            packet = (u8 *)func_0019b6a0(*(BtlUnit **)(*(u8 **)(currentAction + 48) + 2572));
            *(s64 *)(packet + 96) = *(s64 *)currentAction;
            func_00194590(packet, 1);
        }
        currentAction = *(u8 **)(currentAction + 1104);
    }
    target = NULL;
    if (*(u8 *)(*(u8 **)(action + 48) + 162) == 0) {
        selectedAction = (u32)action;
    } else {
        selectedAction = (u32)*(u8 **)(action + 56);
    }
    if (selectedAction != 0) {
        u16 i;
        u8 *tableBase;
        s32 count;
        u32 current;
        i = 0;
        tableBase = iGpffffb3ac;
        count = *(u16 *)(tableBase + 3160);
        while ((s32)i < count) {
            current = *(u32 *)(tableBase + (u32)i * 4 + 3144);
            if (current == selectedAction) {
                target = (u8 *)selectedAction;
                break;
            }
            i++;
        }
    }
    if (target == NULL) {
        target = actionTargetAt((ActionTargetTable *)iGpffffb3ac, (func_00231d70(*(u16 *)(iGpffffb3ac + 3160)) & 0xFFFF));
    }
    cutin.mode = 1;
    cutin.unitId = *(u16 *)(*(u8 **)(target + 48) + 164);
    packet = func_001fa720(&cutin);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 1);
    if (*(u8 *)(*(u8 **)(action + 48) + 162) != 0) {
        changeFormation = 0;
    } else if ((*(s16 *)(iGpffffb3ac + 2672) != -1) &&
               (enemyCount = func_001ef720(2, 0x80000) & 0xFFFF,
                (u32)(*(s16 *)(iGpffffb3ac + 2674) >> 1) >= enemyCount) &&
               (previousFormation = *(s16 *)(iGpffffb3ac + 2672),
                previousFormation != (s16)func_001d15a0())) {
        changeFormation = 1;
    } else {
        changeFormation = 0;
    }
    if (changeFormation != 0) {
        packet = (u8 *)func_001d3900(1);
        *(s64 *)(packet + 96) = *(s64 *)action;
        func_00194590(packet, 0);
    }
    packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(*(u8 **)(iGpffffb3ac + 368) + 48), 0, 0, 1.0f, 1);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 0);
    targetIndex = 0;
    while ((s32)targetIndex < *(u16 *)(iGpffffb3ac + 3160)) {
        targetAction = *(u8 **)(iGpffffb3ac + ((u32)targetIndex * 4) + 3144);
        packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(targetAction + 48), 0, 0, 1.0f, 1);
        *(s64 *)(packet + 96) = *(s64 *)action;
        func_00194590(packet, 0);
        targetIndex++;
    }
    packet = (u8 *)func_001d3700(3, 0xFFF);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 0);
    packet = func_0019e9f0(0, 3);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 1);
    packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(NULL, 3);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 1);
    packet = (u8 *)func_001d3d00((u32)action);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 0);
    packet = (u8 *)func_001ba090(0);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 0);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 7);
    *(s64 *)(packet + 96) = *(s64 *)action;
    func_00194590(packet, 0);
    flags = *(u32 *)(iGpffffb3ac + 12);
    flags = flags & 0xFFBFFFFF;
    *(u32 *)(iGpffffb3ac + 12) = flags;
    *(u16 *)(iGpffffb3ac + 24) = 0;
    if (func_001eb860() == 1) {
        flags = *(u32 *)(iGpffffb3ac + 12);
        flags = flags & ~0x2000;
        *(u32 *)(iGpffffb3ac + 12) = flags;
        func_00212240(*(u8 **)(iGpffffb3ac + 3540), 0);
    }
    *(u8 **)(action + 1052) = target;
    *(s32 *)(action + 1056) = 0;
    *(s32 *)(action + 1060) = 0;
    *(s32 *)(action + 1064) = 0;
    *(u16 *)(action + 1068) = 12;
}
// FUN_001AE800
void func_001ae800(u8 *arg0)
{
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u32 loop_i;
    u8 frame[0x10];

    if (*(s32 *)(arg0 + 0x424) == 0) {
        if (func_00193cd0(0xC00) != 0) {
            return;
        }
        if (func_00193cd0(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while ((s32)(loop_i = i) < *(u16 *)(gp2 + 0xC58)) {
            packet1 = *(u8 **)(gp2 + 0xC48 + ((u32)i * 4));
            *(u16 *)(frame + 2 + ((u32)i * 2)) =
                *(u16 *)(*(u8 **)(packet1 + 0x30) + 0xA4);
            i++;
        }
        *(u16 *)(frame + 8) = *(u16 *)(gp2 + 0xC58);
        packet1 = func_001fa110(frame);
        func_00194590(packet1, 1);
        packet2 = func_001fa8f0();
        *(s16 *)(packet2 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet2, 1);
        packet3 = func_00194c90((s32)func_001ae3c0, (s32)arg0);
        *(s16 *)(packet3 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet3, 1);
        packet4 = func_001d65d0(
            *(s32 *)(D_0076449C + 0xD8C),
            *(s32 *)(arg0 + 0x30), 0,
            *(s64 *)(packet3 + 0x58), 0x8000);
        *(s16 *)(packet4 + 0x48) = *(s16 *)(arg0 + 0x42C);
        func_00194590(packet4, 2);
        *(s32 *)(arg0 + 0x424) = 1;
    }

    if (*(s32 *)(arg0 + 0x420) == 0) {
        if (*(s16 *)(arg0 + 0x42C) <= 0) {
            func_00218160(*(u8 **)(D_0076449C + 0xDD4),
                          *(u8 **)(arg0 + 0x41C));
            *(s32 *)(arg0 + 0x420) = 1;
        } else {
            *(s16 *)(arg0 + 0x42C) = *(s16 *)(arg0 + 0x42C) - 1;
        }
    }

    if (func_00193bf0(*(u64 *)arg0,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (*(s32 *)(arg0 + 0x428) == 0) {
        if (func_00218200(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            return;
        }
        if (func_00218230(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            packet1 = func_001f3870(arg0, 2);
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
            *(s32 *)(*(u8 **)(D_0076449C + 0x170) + 0x434) =
                *(s32 *)(arg0 + 0x41C);
            *(s16 *)(*(u8 **)(D_0076449C + 0x170) + 0x16) = 0x1F;
            func_001b0e30(*(s32 *)(D_0076449C + 0x170));
            packet2 = (u8 *)func_001b1540();
            if ((*(u8 *)(*(u8 **)(packet2 + 0x30) + 0xA2) == 0) &&
                (*(u8 *)(packet2 + 0x28) != 0)) {
                *(u16 *)(packet2 + 0x18) |= 0x8000;
            }
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 1, 0, 0), 1);
        } else {
            func_00194590(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 0, 0, 0), 1);
            packet1 = func_001fa450();
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            func_00194590(packet1, 1);
        }

        packet1 = func_001faa60();
        *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
        func_00194590(packet1, 1);
        packet2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 1);
        *(u64 *)(packet2 + 0x60) = *(u64 *)arg0;
        func_00194590(packet2, 1);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) |= 0x2000;
            func_00212240(*(u8 **)(D_0076449C + 0xDD4), 1);
        }
        *(s32 *)(arg0 + 0x428) = 1;
        *(u16 *)(arg0 + 0x42E) = 6;
        return;
    }

    if (*(u16 *)(arg0 + 0x42E) == 0) {
        func_00218260(*(s32 *)(D_0076449C + 0xDD4));
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        btlActionSetState((BtlAction *)arg0, 0x20);
        return;
    }
    *(u16 *)(arg0 + 0x42E) = *(u16 *)(arg0 + 0x42E) - 1;
}
// FUN_001AEC20
void func_001aec20(u8 *arg0)
{
    s32 temp_3_3;
    s32 var_4;
    s32 var_6;
    s32 var_5;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_3_2;

    func_001eb3b0(arg0 + 0x38);
    func_001d7f10(arg0, arg0 + 0x98, 0x100, 0);
    var_4 = 0;
    goto loop_2_test;
loop_2_body:
    temp_3_2 = arg0 + ((u16)var_4 * 4);
    *(s32 *)(temp_3_2 + 0x38) = *(s32 *)(temp_3_2 + 0x98);
    var_4 = (var_4 + 1) & 0xFFFF;
loop_2_test:
    temp_3 = *(u16 *)(arg0 + 0xD0);
    if ((var_4 & 0xFFFF) < temp_3) {
        goto loop_2_body;
    }
    *(u16 *)(arg0 + 0x6A) = temp_3;
    *(s16 *)(arg0 + 0x6C) = 2;
    *(s16 *)(arg0 + 0x6E) = 0x100;
    func_001f14f0(arg0);
    var_6 = 0;
    var_5 = 0;
    temp_4 = *(u16 *)(arg0 + 0x6A);
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)var_5 * 4) + 0x38) + 0xE0) != 0) {
        var_6 = (var_6 + 1) & 0xFFFF;
    }
    var_5 = (var_5 + 1) & 0xFFFF;
loop_7_test:
    if ((var_5 & 0xFFFF) < temp_4) {
        goto loop_7_body;
    }
    temp_3_3 = var_6 & 0xFFFF;
    if (temp_4 == temp_3_3) {
        *(s16 *)(arg0 + 0x6E) = 0x102;
        return;
    }
    if (temp_3_3 != 0) {
        *(s16 *)(arg0 + 0x6E) = 0x100;
        return;
    }
    *(s16 *)(arg0 + 0x6E) = 0x101;
}
/* A hit's result payload is shared by its effect and message packets. */
static inline const void *battleHitPayload(const u8 *record)
{
    return record + 0xF0;
}

/* Native b210/O2: 3196/3200 bytes, all 99 relocations resolved and the four
 * retail tail bytes zero. All 70 siblings and four data sections preserved.
 * Evidence: build/cos20814/resume-battle/aed50-resume27-exact-owner/resolved/
 */
// FUN_001AED50
#pragma push
#pragma opt_loop_invariants on
void func_001aed50(u8 *arg0)
{
    typedef struct PartyActionView {
        u8 unknown00[0x30];
        u8 *unit;
    } PartyActionView;
    typedef struct PartyStateView {
        u8 unknown00[0xC48];
        PartyActionView *members[4];
        u16 count;
    } PartyStateView;
    extern s32 func_001d3d50(u32 arg0);
    extern void func_001d3e00(u32 arg0);
    extern u32 func_001d43f0(s32 arg0);
    extern u8 *func_001d7bf0(u32 arg0, u32 arg1, u32 arg2);
    extern u8 *func_001f3950(u8 *arg0);
    extern s32 func_001ef4a0(s32 arg0);
    extern void func_00230340(u8 *arg0);
    extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
    extern void func_001b7060(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 func_001b7080(s32 arg0);
    extern s32 func_001b7090(s32 arg0);
    extern void func_001b70a0(u32 arg0, s32 *arg1, s32 *arg2);
    extern BtlPacket *func_001b7880(u32 arg0, u32 arg1, u32 arg2);
    extern BtlPacket *func_001b83f0(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    extern BtlPacket *func_001b9560(u32 arg0, u32 arg1);
    extern BtlPacket *func_001b7e20(u32 arg0);
    extern BtlPacket *func_001b9360(s32 arg0, s16 arg1);
    extern BtlPacket *func_001b99a0(s32 arg0);
    extern BtlPacket *func_001f81f0(u16 arg0, const char *arg1);
    extern u8 *func_00202590(s32 unit, s8 kind, s16 value);
    extern u8 D_005F6D38[];
    extern u8 D_005F6D48[];
    extern u8 D_005F6D58[];
    extern u8 *iGpffffb3bc;
    s32 outHi;
    s32 outLo;
    s32 sp1D8[3];
    union { u8 bytes[32]; s32 words[8]; } tmpBuf;
    char workBuf[128];
    u8 *pkt12C;
    u8 *pkt128;
    u32 handle;
    u16 sp110;
    s32 sp100;
    u16 var23;
    u8 *rec;
    u16 var22;
    u8 *setupPacket;
    u8 *unit19;
    u8 *chain;
    u8 *anim;
    u8 *unit17;
    u8 *target;
    s64 uid;
    s32 aux;
    u32 selector;
    s64 cur58;
    u16 frameInterval;
    s32 colorKind;
    u32 formationFlags;
    u16 k;
    u8 *list;

    uid = *(s64 *)arg0;
    handle = func_001d3d50(1);
    for (list = *(u8 **)(iGpffffb3ac + 0x174); list != NULL; list = *(u8 **)(list + 0x450)) {
        if (*(u8 *)(list + 0x28) != 0) {
            u8 *pk;
            pk = func_001f3870(list, 2);
            *(s64 *)(pk + 0x60) = uid;
            func_00194590(pk, 1);
        }
    }
    aux = *(s16 *)(arg0 + 0x6E);
    target = *(u8 **)(arg0 + 0x38);
    for (k = 0; k < ((PartyStateView *)iGpffffb3ac)->count; k++) {
        sp1D8[k] = (s32)((PartyStateView *)iGpffffb3ac)->members[k]->unit;
    }
    for (; k < 3U; k++) {
        sp1D8[k] = 0;
    }
    {
        u8 *pk;
        pk = func_001d7bf0(sp1D8[0], sp1D8[1], sp1D8[2]);
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    setupPacket = func_001fa320();
    *setupPacket = 10;
    *(s16 *)(setupPacket + 8) = 0xC00;
    *(setupPacket + 0x10) = 10;
    *(s16 *)(setupPacket + 0x18) = 0xC05;
    *(s64 *)(setupPacket + 0x60) = uid;
    func_00194590(setupPacket, 1);
    {
        u8 *pk;
        pk = (u8 *)func_001f7c20(0xE, 4, 4);
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(setupPacket + 0x58);
        *(s64 *)(pk + 0x60) = *(s64 *)arg0;
        func_00194590(pk, 1);
    }
    cur58 = *(s64 *)(setupPacket + 0x58);
    {
        u8 *pk;
        pk = func_001f99c0(*(u8 **)(arg0 + 0x434), 7, 0, 0, 0);
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(setupPacket + 0x58);
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = *(s64 *)arg0;
        func_00194590(pk, 1);
    }
    selector = (u16)aux;
    func_001b7060(selector, &outHi, &outLo);
    {
        u8 *pk;
        pk = (u8 *)func_001b7880((u32)outHi, (u32)outLo, 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    colorKind = func_001b7080(selector);
    func_001b70a0(selector, &outHi, &outLo);
    /* Palette entries are four bytes; their flags are the second halfword. */
    sp100 = (s16)aux;
    {
        u8 *pk;
        pk = (u8 *)func_001b83f0(colorKind, outHi, outLo, 0x10, ((((const u16 *)(iGpffffb3bc + 2))[sp100 * 2] & 2) ? 1U : 0U));
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    {
        u8 *pk;
        aux = (u16)aux;
        pk = (u8 *)func_001b9560(func_001b7090(aux), 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)func_001b9de0((BtlAction *)arg0, aux, 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    func_001d69f0(aux, workBuf);
    pkt12C = (u8 *)func_001d5eb0(handle, workBuf, 0);
    *pkt12C = 5;
    *(s64 *)(pkt12C + 8) = cur58;
    *(s16 *)(pkt12C + 0x48) = 0x3C;
    *(s64 *)(pkt12C + 0x60) = uid;
    func_00194590(pkt12C, 1);
    for (unit17 = *(u8 **)(iGpffffb3ac + 0x178); unit17 != NULL; unit17 = *(u8 **)(unit17 + 0xA6C)) {
        if (datCalcChkBadStatus(*(s32 *)(unit17 + 0xA64), 0x100117) != 0 || datCalcIsDead(*(s32 *)(unit17 + 0xA64), 0) != 0) {
            u8 *pk;
            pk = func_0019bbe0(unit17, 0xFFFFFF, 0, 0, 4, 0);
            *pk = 4;
            *(s64 *)(pk + 8) = *(s64 *)(pkt12C + 0x58);
            *(s64 *)(pk + 0x60) = uid;
            func_00194590(pk, 0);
        }
    }
    pkt128 = (u8 *)func_001d6240(handle, *(u32 *)(arg0 + 0x30), *(u32 *)(target + 0x30), 0, 0);
    *pkt128 = 4;
    *(s64 *)(pkt128 + 8) = *(s64 *)(pkt12C + 0x58);
    *(s64 *)(pkt128 + 0x60) = uid;
    func_00194590(pkt128, 2);
    {
        u8 *pk;
        switch (sp100) {
        case 0x100:
            pk = (u8 *)func_001f81f0(2, (const char *)D_005F6D38);
            break;
        case 0x101:
            pk = (u8 *)func_001f81f0(2, (const char *)D_005F6D48);
            break;
        default:
            pk = (u8 *)func_001f81f0(2, (const char *)D_005F6D58);
            break;
        }
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(pkt128 + 0x58);
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    sp110 = 0;
    frameInterval = (u16)func_001ef4a0(selector);
    for (var23 = 0; var23 < *(u16 *)(arg0 + 0x6A); var23++) {
        unit17 = *(u8 **)(arg0 + (u32)var23 * 4 + 0x38);
        func_00230340(unit17);
        formationFlags = func_001d43f0((s32)(unit17 + 0xD8));
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            unit19 = arg0;
        } else {
            unit19 = unit17;
        }
        {
            u8 *pk;
            pk = func_00202740(*(u8 **)(unit19 + 0x30));
            *(s64 *)(pk + 0x60) = uid;
            func_00194590(pk, 1);
        }
        chain = (u8 *)func_001d6240(handle, *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, formationFlags | 0x1000);
        *chain = 4;
        *(s64 *)(chain + 8) = *(s64 *)(pkt12C + 0x58);
        *(s16 *)(chain + 0x48) = sp110;
        *(s64 *)(chain + 0x60) = uid;
        func_00194590(chain, 2);
        {
            u8 *pk;
            pk = (u8 *)func_001f7c20(0xA, 0, 4);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            func_00194590(pk, 1);
        }
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            u8 *pk;
            pk = (u8 *)func_001d6240(*(u32 *)(iGpffffb3ac + 0xD28), *(u32 *)(arg0 + 0x30), *(u32 *)(unit17 + 0x30), 1, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            func_00194590(pk, 1);
        }
        if (*(u16 *)(unit17 + 0xDC) == 0x400) {
            u8 *pk;
            pk = (u8 *)func_001d6240(*(u32 *)(iGpffffb3ac + 0xD2C), *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            func_00194590(pk, 1);
        }
        for (var22 = 0; var22 < *(u8 *)(unit17 + 0xD9); var22++) {
            u16 *flags;
            rec = unit17 + ((u32)var22 << 5);
            anim = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(unit19 + 0x30), (s32)*(s8 *)(rec + 0x10C), 0, 1.0f, 0);
            *anim = 0xB;
            *(s64 *)(anim + 8) = *(s64 *)(chain + 0x58);
            *(s64 *)(anim + 0x60) = uid;
            func_00194590(anim, 0);
            {
                u8 *pk;
                pk = btlUnitCreateRotateTowardUnitPacket(*(u8 **)(unit17 + 0x30), *(u8 **)(arg0 + 0x30), 2);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 1);
            }
            {
                u8 *pk;
                pk = (u8 *)func_001f36e0((s32)arg0, (s32)unit19, battleHitPayload(rec), *(u16 *)(unit17 + 0xDC), *(u16 *)(unit17 + 0xDE));
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 1);
            }
            {
                u8 *pk;
                pk = func_001f3950(unit17);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 1);
            }
            if (var23 == *(u16 *)(arg0 + 0x6A) - 1 && var22 == *(u8 *)(unit17 + 0xD9) - 1) {
                u8 *pk;
                pk = func_001f3950(arg0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 1);
            }
            if (var22 == 0 && *(const s32 *)battleHitPayload(rec) != 0) {
                u8 *pk;
                pk = func_00202590(*(s32 *)(unit19 + 0x30), 0, 0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 3);
            }
            flags = (u16 *)(rec + 0x10E);
            if ((*flags & 1) != 0) {
                u8 *pk;
                func_001f0a10(tmpBuf.bytes);
                tmpBuf.words[3] = 0x100001;
                pk = (u8 *)func_001f36e0((s32)unit17, (s32)unit17, tmpBuf.bytes, 1, 1);
                *pk = 4;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 1);
                if ((*flags & 2) != 0) {
                    u8 *pk2;
                    pk2 = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(unit17 + 0x30), 0xB, 0, 1.0f, 0);
                    *pk2 = 4;
                    *(s64 *)(pk2 + 8) = *(s64 *)(anim + 0x58);
                    *(s64 *)(pk2 + 0x60) = uid;
                    func_00194590(pk2, 0);
                    pk2 = (u8 *)func_0019a980(*(BtlUnit **)(unit17 + 0x30));
                    *pk2 = 4;
                    *(s64 *)(pk2 + 8) = *(s64 *)(anim + 0x58);
                    *(s64 *)(pk2 + 0x60) = uid;
                    func_00194590(pk2, 0);
                }
            }
            {
                u8 *pk;
                pk = func_00201de0(*(s32 *)(arg0 + 0x30), *(s32 *)(unit19 + 0x30), sp100, *(u16 *)(unit17 + 0xDC), *(u16 *)(unit17 + 0xDE), var22, *(u8 *)(unit17 + 0xD9), battleHitPayload(rec), 0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                func_00194590(pk, 3);
            }
        }
        sp110 += frameInterval;
    }
    for (unit17 = *(u8 **)(iGpffffb3ac + 0x178); unit17 != NULL; unit17 = *(u8 **)(unit17 + 0xA6C)) {
        if (datCalcChkBadStatus(*(s32 *)(unit17 + 0xA64), 0x100117) != 0 || datCalcIsDead(*(s32 *)(unit17 + 0xA64), 0) != 0) {
            u8 *pk;
            pk = func_0019bbe0(unit17, -1, 0xC, 0, 3, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            *(s16 *)(pk + 0x48) = 6;
            *(s64 *)(pk + 0x60) = uid;
            func_00194590(pk, 0);
        }
    }
    {
        u8 *pk;
        pk = (u8 *)func_001b7e20(0x10);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)func_001b9360(0x10, 0);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)func_001b99a0(0x10);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)func_001ba090(8);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 0);
    }
    {
        u8 *pk;
        pk = func_001d7bf0(0, 0, 0);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
        *(pk + 0x10) = 4;
        *(s64 *)(pk + 0x18) = *(s64 *)(pkt128 + 0x58);
        *(s64 *)(pk + 0x60) = uid;
        func_00194590(pk, 1);
    }
    func_001d3e00(handle);
    btlActionSetState((BtlAction *)arg0, 0x20);
}
#pragma pop
// FUN_001AF9D0
void func_001af9d0(void)
{
}
// FUN_001AF9E0
void func_001af9e0(s64 *arg0)
{
    if (func_00193bf0(*arg0, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        btlActionSetState((BtlAction *)arg0, 0x21U);
    }
}
// FUN_001AFA50
void func_001afa50(u8 *arg0)
{
    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 6;
        *(u16 *)(arg0 + 0x18) &= 0xBFFF;
    }
    *(u16 *)(arg0 + 0x18) &= 0xFEFF;
    if (*(u16 *)(arg0 + 0x18) & 0x200) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 0x20;
        *(u16 *)(arg0 + 0x18) &= 0xFDFF;
    }
    if (func_001fac80(arg0) != 0) {
        *(void (**)(void))(arg0 + 0x440) = func_001fad10;
        *(s16 *)(arg0 + 0x43C) = 0x21;
        btlActionSetState((BtlAction *)arg0, 0x16);
        return;
    }
    *(u16 *)(arg0 + 0x18) &= 0xC7FF;
}

/* Finish readiness, queued-order and status processing for this action.
 * Native b210 O2: 1228 executable bytes and four zero alignment bytes.
 * This paired recovery preserves the other 69 functions and allocated data.
 * See docs/probe_archive/Action_readiness_001afb50_20260924.md. */
// FUN_001AFB50
void func_001afb50(u8 *action)
{
    s32 func_0019ff60(u8 *action);
    s32 func_00193060(void);
    s32 func_001b0e30(s32 action);
    s32 func_001b0dd0(u8 *action);
    void func_001b13c0(u8 *action);
    void func_001b1450(u8 *action);
    void func_001f5a00(s32 advance);
    void func_00235110(u8 *unit);
    void func_001f2cc0(u8 *action);
    void datCalcSetHp(s32 unit, u16 hp);
    u32 datCalcSetBadStatus(s32 unit, u32 badStatus);

    u16 entryFlags;
    s32 specialOrder;
    s32 restart;
    s32 dead;
    s32 resetUnit;
    u8 *packet;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
        entryFlags = *(u16 *)(action + 0x18);
        specialOrder = (entryFlags & 4) != 0;
        if ((entryFlags & 8) != 0 && func_0019ff60(action) != 0) {
            if (func_00193cd0(0x504) != 0) {
                return;
            }
            if (func_00193cd0(0x506) != 0) {
                return;
            }
            *(s16 *)(action + 0x16) = 30;
            func_001b0e30((s32)action);
            restart = 1;
        } else {
            *(u16 *)(action + 0x18) = *(u16 *)(action + 0x18) & 0xFFF7;
            restart = 0;
        }
        if ((*(u16 *)(action + 0x18) & 0x8000) == 0 && specialOrder == 0) {
            *(s32 *)(action + 0x20) = *(s32 *)(action + 0x20) + 1;
        }
        if (func_00193060() == 0) {
            if ((*(u16 *)(action + 0x18) & 0x8000) == 0 && specialOrder == 0) {
                if (*(action + 0x29) > 0) {
                    if (*(action + 0x28) == 0 && datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0) == 0) {
                        *(action + 0x29) = *(action + 0x29) - 1;
                    } else {
                        *(action + 0x29) = 0;
                    }
                }
                dead = datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
                if ((*(action + 0x28) == 0 && *(action + 0x29) == 0) || dead != 0) {
                    if (dead != 0) {
                        *(action + 0x28) = 0;
                        *(action + 0x29) = 0;
                        func_001b0dd0(action);
                    }
                    {
                        u16 unitFlags = *(u16 *)(action + 0x1A);
                        if ((unitFlags & 1) == 0) {
                            resetUnit = 0;
                        } else {
                            u8 *unit = *(u8 **)(*(u8 **)(action + 0x30) + 0xA0C);
                            if ((unitFlags & 0x10) == 0) {
                                resetUnit = 0;
                            } else {
                                if ((*(u32 *)(unit + 0x98) & 2) != 0) {
                                    resetUnit = 1;
                                } else {
                                    resetUnit = 0;
                                }
                            }
                        }
                    }
                    if (resetUnit != 0) {
                        packet = (u8 *)func_0019b6a0(*(BtlUnit **)(*(u8 **)(action + 0x30) + 0xA0C));
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        func_00194590(packet, 1);
                    }
                    func_00235110(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
                    func_001f5a00(1);
                    func_001b13c0(action);
                } else {
                    func_001b1450(action);
                    func_001f5a00(0);
                }
            } else {
                {
                    u16 unitFlags = *(u16 *)(action + 0x1A);
                    if ((unitFlags & 1) == 0) {
                        resetUnit = 0;
                    } else {
                        u8 *unit = *(u8 **)(*(u8 **)(action + 0x30) + 0xA0C);
                        if ((unitFlags & 0x10) == 0) {
                            resetUnit = 0;
                        } else {
                            if ((*(u32 *)(unit + 0x98) & 2) != 0) {
                                resetUnit = 1;
                            } else {
                                resetUnit = 0;
                            }
                        }
                    }
                }
                if (resetUnit != 0) {
                    packet = (u8 *)func_0019b6a0(*(BtlUnit **)(*(u8 **)(action + 0x30) + 0xA0C));
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    func_00194590(packet, 1);
                }
                func_001b13c0(action);
            }
        } else {
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;

        }
        if (specialOrder == 0) {
            *(u16 *)(action + 0x18) = *(u16 *)(action + 0x18) & 0x7FFF;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
            if (restart != 0) {
                btlActionSetState((BtlAction *)action, 1);
                return;
            }
            if ((*(u16 *)(action + 0x18) & 0x20) == 0) {
                btlActionSetState((BtlAction *)action, 0x22);
                return;
            }
            func_001b0dd0(action);
            if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 1) {
                datCalcSetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x80000);
                datCalcSetHp(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
            }
            if (func_00193060() != 0) {
                *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if ((*(u16 *)(action + 0x18) & 0x20) != 0) {
            func_001b0dd0(action);
            if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 1) {
                datCalcSetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x80000);
                datCalcSetHp(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0) != 0) {
            func_001f2cc0(action);
            btlActionSetState((BtlAction *)action, 1);
        }
        return;
    }
}
