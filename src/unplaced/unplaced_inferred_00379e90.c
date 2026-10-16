/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00379e90-0037bc80 */

#include "include_asm.h"
#include "type.h"
extern void btlShuffleCalcResetPose(u8 *arg0);
extern void btlShuffleDrawInitCard(u8 *arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5,
                           f32 fparg0, f32 fparg1);
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
extern f32 fGpffff80d8;
extern f32 fGpffff83e4;
extern f32 fGpffff837c;
extern void btlShuffleDrawSetTiming(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4);
static inline f32 add_retail_order(f32 a, f32 b) {
    return a + b;
}

static inline u8 *code1_0037_add_offset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}

void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, u8 *arg3);

#pragma push
#pragma opt_propagation off
// FUN_00379E90
void func_00379e90(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 pad4c;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
    } work;
    f32 temp_f2;

    btlShuffleCalcResetPose((u8 *)&work.sp60);
    work.sp64 = work.sp64 - 25.0f;
    work.sp50 = work.sp60;
    work.sp54 = work.sp64;
    temp_f2 = work.sp68;
    work.sp58 = add_retail_order(temp_f2, 200.0f);
    work.sp40 = 0.0f;
    work.sp44 = cosf(fGpffff80d8);
    work.sp48 = -sinf(fGpffff80d8);
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp50, (u8 *)&work.sp40, (u8 *)&work.sp60, 0.0f, (u8 *)arg2);
        return;
    }
    btlShuffleDrawInitCard(arg0, arg1, 0, &work.sp40, &work.sp50, &work.sp60, 0.0f, 0.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// FUN_00379F90
s32 btlShuffleSeq1Run(u8 *arg0) {
    extern s32 btlShuffleSeqPick(u8 *arg0, s32 arg1);
    extern s32 btlShuffleSeqLoadRecord(u8 *arg0);
    extern s32 btlShuffleSeqStep(u8 *arg0);
    extern void btlShuffleDrawCardActivate(u8 *arg0);
    extern void func_0038d0d0(u8 *arg0, s32 arg1);
    extern void func_0038d0a0(u8 *arg0);
    extern s32 btlShuffleDrawStateB(u8 *arg0);
    extern s32 btlShuffleDrawStateA(u8 *arg0);
    extern void btlShuffleDrawSetPose(u8 *arg0, s32 arg1, u16 arg2, u16 arg3);
    extern void btlShuffleDrawPoll(u8 *arg0, s32 arg1, s32 arg2);
    extern void btlShuffleDrawSetFrames(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 btlShuffleDrawCheck(u8 *arg0, u8 *arg1);
    extern void btlShuffleDrawViewClearHold(u8 *arg0);
    extern void btlShuffleDrawViewStartCue(u8 *arg0);
    extern s32 btlShuffleDrawViewIsCueIdle(u8 *arg0);
    extern s32 sdkSndStartStream(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
    extern void kAssertFail(const void *file, u32 line);
    extern char D_0064EAC0[];
    extern u16 D_008C024E[];
    extern s32 datGetFlag(s32 arg0);
    extern void datSetFlag(s32 arg0, s32 arg1);
    extern u16 btlShuffleSeqRoll(void);
    extern s32 btlShuffleSeqRecord(u8 *arg0, s32 arg1, s32 arg2);
    extern void btlShuffleSeqMoveA(u8 *arg0, s32 arg1);
    extern void btlShuffleSeqClearA(u8 *arg0, s32 arg1);
    extern s32 btlShuffleSeqFlag(u8 *arg0);
    extern void btlShuffleSeqReset(u8 *arg0);
    extern s32 btlShuffleSeqStateCheck(u8 *arg0);
    extern s32 btlShuffleSeqCardCount(u8 *arg0, s32 arg1);
    extern s32 btlShuffleSeqDispatch(u8 *arg0);
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        struct Vec3 base;
        struct Vec3 first;
        struct Vec3 second;
        struct Vec3 output;
    } work;
    struct Vec3 v2;
    struct Vec3 v1;
    struct Vec3 v0;
    f32 factor;
    f32 base;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 j;
    s32 offset;
    f32 thirdX;
    s32 k;
    s32 sel;
    s32 m;
    sbase = arg0 + 0x1F1D0;
    mod = (u16)(*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304));
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (*(s32 *)(arg0 + 0x1F30C) != 0) {
            *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
            if (btlShuffleSeqPick(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
                break;
            }
        }
        sbase2 = arg0 + 0x1F1D0;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EAC0, 0x38);
            break;
        }
        *(u16 *)(sbase2 + 2) = *(u16 *)(sbase2 + 2) * (1.0f + factor * (*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f);
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(s32 *)(sbase + 0xC) = -1;
        if (btlShuffleSeqLoadRecord(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                work.base = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6B8);
                func_00379e90(arg0, 0, &work.output.x);
                dx = work.output.x - work.base.x;
                thirdX = work.base.x + dx / 3.0f;
                work.first.x = 150.0f + thirdX;
                dy = work.output.y - work.base.y;
                work.first.y = work.base.y + dy / 3.0f;
                dz = work.output.z - work.base.z;
                work.first.z = work.base.z - dz;
                work.second.x = work.base.x + (2.0f * dx) / 3.0f + 150.0f;
                work.second.y = work.base.y + (2.0f * dy) / 3.0f;
                work.second.z = work.base.z + dz;
                m = (u16)mod * i;
                btlShuffleDrawSetTiming(arg0, i, (u16)m, (u16)(m + 0x14), &work.base.x);
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < *(s32 *)(arg0 + 0x1F304); k++) {
            if (btlShuffleDrawStateB(arg0 + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(arg0, k, 0, 0xA);
                sel = *(s32 *)(sbase + 8);
                offset = ((u16)mod * (*(s32 *)(arg0 + 0x1F304) - sel)) & 0xFFFF;
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    kAssertFail(D_0064EAC0, 0x5F);
                }
                func_00379e90(arg0, k, (f32 *)0);
                v2 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6CC);
                v1 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6D8);
                v0 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6E4);
                btlShuffleDrawInitCard(arg0, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = btlShuffleSeqRoll();
    case 5: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        btlShuffleDrawViewStartCue(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = btlShuffleDrawCheck(arg0, (u8 *)0);
        btlShuffleDrawViewClearHold(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        sdkSndStartStream(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(arg0, *(s32 *)(sbase + 0xC));
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawSetFrames(arg0, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (btlShuffleDrawStateA(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawPoll(arg0, j, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        btlShuffleSeqCardCount(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        kAssertFail(D_0064EAC0, 0x1B6);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleSeqRecord(arg0, j, mod);
            }
        }
    }
    return 0;
}
#pragma pop

void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, u8 *arg3);

#pragma push
#pragma opt_propagation on
// FUN_0037AB50
void func_0037ab50(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 pad6c;
        f32 sp70;
        f32 sp74;
        f32 sp78;
    } work;
    f32 temp_f20;
    f32 temp_f2;
    f32 zero;
    s32 parity;

    btlShuffleCalcResetPose((u8 *)&work.sp70);
    work.sp74 = work.sp74 - 25.0f;
    work.sp60 = work.sp70;
    work.sp64 = work.sp74;
    temp_f2 = work.sp78;
    work.sp68 = add_retail_order(temp_f2, 200.0f);
    parity = arg1 & 1;
    if ((arg1 < 0) && (parity != 0)) {
        parity -= 2;
    }
    if (parity == 0) {
        temp_f20 = -cosf(fGpffff83e4);
        work.sp50 = temp_f20 * sinf(fGpffff837c);
        temp_f20 = -cosf(fGpffff83e4);
        work.sp54 = temp_f20 * cosf(fGpffff837c);
        work.sp58 = sinf(fGpffff83e4);
        zero = 0.0f;
    } else {
        temp_f20 = -cosf(fGpffff83e4);
        work.sp50 = temp_f20 * sinf(fGpffff837c);
        temp_f20 = cosf(fGpffff83e4);
        work.sp54 = temp_f20 * cosf(fGpffff837c);
        work.sp58 = -sinf(fGpffff83e4);
        zero = 0.0f;
    }
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp60, (u8 *)&work.sp50,
                      (u8 *)&work.sp70, zero, (u8 *)arg2);
        return;
    }
    btlShuffleDrawInitCard(arg0, arg1, 0, &work.sp50, &work.sp60,
                  &work.sp70, zero, zero);
}
#pragma pop

extern s32 btlShuffleSeqPick(u8 *arg0, s32 arg1);
extern s32 btlShuffleSeqLoadRecord(u8 *arg0);
extern s32 btlShuffleSeqStep(u8 *arg0);
extern void btlShuffleDrawCardActivate(u8 *arg0);
extern void func_0038d0d0(u8 *arg0, s32 arg1);
extern void func_0038d0a0(u8 *arg0);
extern s32 btlShuffleDrawStateB(u8 *arg0);
extern s32 btlShuffleDrawStateA(u8 *arg0);
extern void btlShuffleDrawSetPose(u8 *arg0, s32 arg1, u16 arg2, u16 arg3);
extern void btlShuffleDrawPoll(u8 *arg0, s32 arg1, s32 arg2);
extern void btlShuffleDrawSetFrames(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 btlShuffleDrawCheck(u8 *arg0, u8 *arg1);
extern void btlShuffleDrawViewClearHold(u8 *arg0);
extern void btlShuffleDrawViewStartCue(u8 *arg0);
extern s32 btlShuffleDrawViewIsCueIdle(u8 *arg0);
extern s32 sdkSndStartStream(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
extern void kAssertFail(const void *file, u32 line);
extern char D_0064EAE0[];
extern char D_0064EB00[];
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 arg0);
extern void datSetFlag(s32 arg0, s32 arg1);
extern u16 btlShuffleSeqRoll(void);
extern s32 btlShuffleSeqRecord(u8 *arg0, s32 arg1, s32 arg2);
extern void btlShuffleSeqMoveA(u8 *arg0, s32 arg1);
extern void btlShuffleSeqClearA(u8 *arg0, s32 arg1);
extern s32 btlShuffleSeqFlag(u8 *arg0);
extern void btlShuffleSeqReset(u8 *arg0);
extern s32 btlShuffleSeqStateCheck(u8 *arg0);
extern s32 btlShuffleSeqCardCount(u8 *arg0, s32 arg1);
extern s32 btlShuffleSeqDispatch(u8 *arg0);
#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
// FUN_0037AD10
s32 btlShuffleSeq2Run(u8 *arg0) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        struct Vec3 base;
        struct Vec3 first;
        struct Vec3 second;
        struct Vec3 output;
    } work;
    struct Vec3 v2;
    struct Vec3 v1;
    struct Vec3 v0;
    f32 factor;
    f32 base;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 j;
    s32 offset;
    f32 xOff;
    f32 thirdY;
    s32 k;
    s32 sel;
    s32 m;
    sbase = arg0 + 0x1F1D0;
    mod = (u16)(*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304));
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (btlShuffleSeqPick(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        sbase2 = arg0 + 0x1F1D0;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EAE0, 0x3A);
            break;
        }
        *(u16 *)(sbase2 + 2) = *(u16 *)(sbase2 + 2) * (1.0f + factor * (*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f);
        *(s32 *)(sbase + 0xC) = -1;
        if (btlShuffleSeqLoadRecord(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                xOff = 150.0f;
                work.base = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6B8);
                func_0037ab50(arg0, 0, &work.output.x);
                if (i % 2 == 0) {
                    xOff = xOff * -1.0f;
                }
                dx = work.output.x - work.base.x;
                work.first.x = xOff + (work.base.x + dx / 3.0f);
                dy = work.output.y - work.base.y;
                thirdY = work.base.y + dy / 3.0f;
                work.first.y = 100.0f + thirdY;
                dz = work.output.z - work.base.z;
                work.first.z = work.base.z + dz;
                work.second.x = xOff + (work.base.x + (2.0f * dx) / 3.0f);
                work.second.y = 100.0f + (work.base.y + (2.0f * dy) / 3.0f);
                work.second.z = work.first.z;
                m = (u16)mod * i;
                btlShuffleDrawSetTiming(arg0, i, (u16)m, (u16)(m + 0x14), &work.base.x);
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < *(s32 *)(arg0 + 0x1F304); k++) {
            if (btlShuffleDrawStateB(arg0 + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(arg0, k, 0, 0xA);
                sel = *(s32 *)(sbase + 8);
                offset = ((u16)mod * (*(s32 *)(arg0 + 0x1F304) - sel)) & 0xFFFF;
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    kAssertFail(D_0064EAE0, 0x6B);
                }
                func_0037ab50(arg0, k, (f32 *)0);
                v2 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6CC);
                v1 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6D8);
                v0 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6E4);
                btlShuffleDrawInitCard(arg0, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = btlShuffleSeqRoll();
    case 5: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        btlShuffleDrawViewStartCue(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = btlShuffleDrawCheck(arg0, (u8 *)0);
        btlShuffleDrawViewClearHold(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        sdkSndStartStream(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(arg0, *(s32 *)(sbase + 0xC));
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawSetFrames(arg0, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (btlShuffleDrawStateA(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawPoll(arg0, j, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        btlShuffleSeqCardCount(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        kAssertFail(D_0064EAE0, 0x19E);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleSeqRecord(arg0, j, mod);
            }
        }
    }
    return 0;
}
#pragma pop

void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, u8 *arg3);

#pragma push
#pragma opt_propagation on
// FUN_0037B8C0
void func_0037b8c0(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 pad6c;
        f32 sp70;
        f32 sp74;
        f32 sp78;
    } work;
    f32 temp_f20;
    s32 phase;

    btlShuffleCalcResetPose((u8 *)&work.sp70);
    work.sp74 = work.sp74 - 25.0f;
    work.sp60 = work.sp70;
    work.sp64 = work.sp74;
    work.sp68 = add_retail_order(work.sp78, 200.0f);
    phase = arg1 % 3;
    switch (phase) {
    case 0:
        work.sp50 = 0.0f;
        work.sp54 = cosf(fGpffff80d8);
        work.sp58 = -sinf(fGpffff80d8);
        break;
    case 1:
        temp_f20 = -cosf(fGpffff80d8);
        work.sp50 = temp_f20 * sinf(fGpffff837c);
        temp_f20 = -cosf(fGpffff80d8);
        work.sp54 = temp_f20 * cosf(fGpffff837c);
        work.sp58 = sinf(fGpffff80d8);
        break;
    case 2:
        temp_f20 = -cosf(fGpffff80d8);
        work.sp50 = temp_f20 * sinf(fGpffff837c);
        temp_f20 = cosf(fGpffff80d8);
        work.sp54 = temp_f20 * cosf(fGpffff837c);
        work.sp58 = -sinf(fGpffff80d8);
        break;
    }
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp60, (u8 *)&work.sp50,
                      (u8 *)&work.sp70, 0.0f, (u8 *)arg2);
        return;
    }
    btlShuffleDrawInitCard(arg0, arg1, 0, &work.sp50, &work.sp60,
                  &work.sp70, 0.0f, 0.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0037BAC0
void btlShuffleCalcSetBezierTiming(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        struct Vec3 base;
        struct Vec3 first;
        struct Vec3 second;
        struct Vec3 output;
    } points;
    f32 x_offset;
    f32 y_offset;
    s32 remainder;

    x_offset = 150.0f;
    y_offset = 100.0f;
    points.base = *(struct Vec3 *)(code1_0037_add_offset(arg1 * 0xE8, arg0) +
                                   0x1D6B8);
    func_0037b8c0(arg0, 0, &points.output.x);
    remainder = arg1 % 3;
    switch (remainder) {
    case 0:
        y_offset = y_offset * (f32)(remainder - remainder);
        break;
    case 1:
        x_offset = x_offset * -1.0f;
        break;
    case 2:
        break;
    }
    points.first.x = x_offset +
                     (points.base.x +
                      (points.output.x - points.base.x) / 3.0f);
    points.first.y = y_offset +
                     (points.base.y +
                      (points.output.y - points.base.y) / 3.0f);
    points.first.z = points.base.z +
                     (points.output.z - points.base.z);
    points.second.x = x_offset +
                      (points.base.x +
                       (2.0f * (points.output.x - points.base.x)) / 3.0f);
    points.second.y = y_offset +
                      (points.base.y +
                       (2.0f * (points.output.y - points.base.y)) / 3.0f);
    points.second.z = points.first.z;
    btlShuffleDrawSetTiming(arg0, arg1, arg2, arg3, &points.base.x);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
// FUN_0037BC80
s32 btlShuffleSeq3Run(u8 *arg0) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec3 v2;
    struct Vec3 v1;
    struct Vec3 v0;
    f32 factor;
    f32 base;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    s32 i;
    s32 j;
    s32 offset;
    s32 k;
    s32 sel;
    s32 m;
    sbase = arg0 + 0x1F1D0;
    mod = (u16)(*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304));
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (btlShuffleSeqPick(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        sbase2 = arg0 + 0x1F1D0;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EB00, 0x3A);
            break;
        }
        *(u16 *)(sbase2 + 2) = *(u16 *)(sbase2 + 2) * (1.0f + factor * (*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f);
        *(s32 *)(sbase + 0xC) = -1;
        if (btlShuffleSeqLoadRecord(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                m = (u16)mod * i;
                btlShuffleCalcSetBezierTiming(arg0, i, (u16)m, (u16)(m + 0x14));
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < *(s32 *)(arg0 + 0x1F304); k++) {
            if (btlShuffleDrawStateB(arg0 + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(arg0, k, 0, 0xA);
                offset = ((u16)mod * (*(s32 *)(arg0 + 0x1F304) - k)) & 0xFFFF;
                sel = *(s32 *)(sbase + 8);
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    kAssertFail(D_0064EB00, 0x72);
                }
                func_0037b8c0(arg0, k, (f32 *)0);
                btlShuffleSeqRecord(arg0, k, offset);
                v2 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6CC);
                v1 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6D8);
                v0 = *(struct Vec3 *)(arg0 + k * 0xE8 + 0x1D6E4);
                btlShuffleDrawInitCard(arg0, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = btlShuffleSeqRoll();
    case 5: {
        if (++*(u16 *)(arg0 + 0x1F2F0) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        btlShuffleDrawViewStartCue(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        btlShuffleDrawCardActivate(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = btlShuffleDrawCheck(arg0, (u8 *)0);
        btlShuffleDrawViewClearHold(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        sdkSndStartStream(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(arg0, *(s32 *)(sbase + 0xC));
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawSetFrames(arg0, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (btlShuffleDrawStateA(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleDrawPoll(arg0, j, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        btlShuffleSeqCardCount(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        kAssertFail(D_0064EB00, 0x1AF);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (j = 0; j < *(s32 *)(arg0 + 0x1F304); j++) {
            if (j != *(s32 *)(sbase + 0xC)) {
                btlShuffleSeqRecord(arg0, j, mod);
            }
        }
    }
    return 0;
}
#pragma pop
