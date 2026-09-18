/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
static inline u8 *btlCamera_add_index(s32 index, u8 *base)
{
    return (u8 *)(index + (u32)base);
}

/* Canonical grouped function declarations. */
u32 func_001d10d0(void* camera);
void func_00195850(u8* arg0, f32* arg1);
void func_001bcd40(u8* arg0, u8* arg1, f32* arg2, u16 arg3, f32 arg4);
extern s32 func_004bd050(s32 arg0);
extern u8 D_005FE1D0[];
extern u32 func_00231d70(s32 arg0);

/* Source unit: src/Battle/btlCamera_001be8d0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001BE8D0
void btlCameraSetDefaultDistanceA(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d05b0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D05B0
void btlCameraSetDefaultDistanceB(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d0670.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D05E0
void func_001d05e0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0xC1,
                          0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)));
        }
    }
}
// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d10d0.c */

// FUN_001D06A0
void func_001d06a0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0xC1,
                          0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)));
        }
    }
}
// FUN_001D0730
u8 *func_001d0730(s32 arg0, s32 arg1)
{
    if (arg1 != 0) {
        return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + 2) * 0x34));
    }
    return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + (func_004bd050(0) & 1)) * 0x34));
}
/* measured: probe 420 words via probe_variants v3 candidate. */
/* fnalign retail 571 vs object 557 (14 short, 2.5 pct, within 3 pct gate). */
/* 113 edits +8 reloc-only. v1 445-560, v2 433-557, v3 420-557. */
/* Goto switch layout took edits 364 to 113. wscan dsll32 2-2. */
/* Repro: m2c to m2c.c (281 lines) and romwright to rom.c (269 lines). */
/* romwright types short int-voidptr, 492 instrs, plus raw output. */
/* De-noised to file idiom: u8 ptr, f32, s16-u16, Frame 0x70-0x1B0. */
/* Frame pads pad88-A8-17C-18C-19C for 0x1C0 frame, plain f32 vecs. */
/* u64 copy for D_0060A0E0, explicit goto switches for retail layout. */
// FUN_001D07E0 NONMATCHING
#ifdef NON_MATCHING
s32 func_001d07e0(u8 *arg0, u8 *arg1)
{
    extern u32 func_001d10d0(void *camera);
    extern u8 *func_001b0c80(s32 arg0);
    extern void func_00195aa0(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void func_001ec1c0(f32 *out, f32 *a, f32 *b);
    extern void func_003dcb40(f32 *out, f32 *in, s32 count, f32 *rot);
    extern void func_001959d0(u8 *arg0, f32 *arg1);
    extern void func_001bd780(void *out, void *first, void *second, void *config);
    extern void func_003e0870(void *out, void *in, s32 mode, f32 angle);
    extern void func_003e4320(void *out, void *in, void *matrix);
    extern void func_001bac20(u8 *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    extern void func_001bbe80(u8 *arg0, f32 arg1);
    extern void func_001bbef0(u8 *arg0, f32 arg1);
    extern void func_001bbf40(u8 *arg0, f32 arg1);
    extern u8 D_0060A0E0[];
    extern u8 D_0060A0F0[];
    extern u8 D_0060A100[];
    struct Frame {
        f32 f70[6];
        u8 pad88[8];
        f32 f90[6];
        u8 padA8[8];
        f32 quatB0[4];
        f32 quatC0[4];
        f32 matD0[16];
        f32 pos110[3];
        f32 quat11C[4];
        f32 pos12C[3];
        f32 quat138[6];
        f32 tmp150[4];
        f32 tmp160[4];
        f32 vec170[3];
        u8 pad17C[4];
        f32 inB[3];
        u8 pad18C[4];
        f32 inA[3];
        u8 pad19C[4];
        f32 pos1A0[4];
        f32 dir1B0[4];
    } frame;
    u8 *base;
    s16 index;
    s16 next;
    u8 *entry;
    u8 *unit0;
    u8 *unit1;
    u8 *tmpUnit;
    f32 scale;
    f32 angle;
    u16 cntC;
    s16 dur;
    u16 sw1;
    u16 sw2;

    if (func_001d10d0(arg1) == 0) {
        return 0;
    }
    base = *(u8 **)(arg1 + 0x10);
    index = *(s16 *)(arg1 + 0xA);
    if (base == NULL) {
        return 0;
    }
    if (index >= 4) {
        return 0;
    }
    if (index == -1) {
        goto next_entry;
    }
    cntC = *(u16 *)(arg1 + 0xC);
    dur = *(s16 *)(base + index * 0x3C + 4);
    if ((s32)cntC < (s32)dur) {
        goto bump_tick;
    }
next_entry:
    next = (s16)(index + 1);
    if ((s32)next >= (s32)*(u8 *)base) {
        goto clear_flag;
    }
    if (*(u8 **)(arg1 + 0) == NULL) {
        goto clear_flag;
    }
    if (func_001b0c80(*(s32 *)(*(u8 **)(arg1 + 0) + 0x30)) == NULL) {
        goto clear_flag;
    }
    if (*(u8 **)(arg1 + 4) == NULL) {
        goto clear_flag;
    }
    if (func_001b0c80(*(s32 *)(*(u8 **)(arg1 + 4) + 0x30)) == NULL) {
        goto clear_flag;
    }
    entry = base + next * 0x3C + 4;
    unit1 = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
    unit0 = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
    if (unit0 != unit1) {
        if ((*(u16 *)(arg1 + 0xE) & 0x20) == 0) {
            func_001ec1c0(frame.quatC0, (f32 *)(unit0 + 4), (f32 *)(unit1 + 4));
            func_001ec1c0(frame.quatB0, (f32 *)(*(u8 **)(*(u8 **)(arg1 + 4) + 0x30) + 4), (f32 *)(*(u8 **)(*(u8 **)(arg1 + 0) + 0x30) + 4));
        } else {
            func_00195aa0(unit0, unit1, frame.tmp160);
            func_00195aa0(*(u8 **)(*(u8 **)(arg1 + 4) + 0x30), *(u8 **)(*(u8 **)(arg1 + 0) + 0x30), frame.tmp150);
            func_001ec1c0(frame.quatC0, frame.tmp160, frame.tmp150);
            func_001ec1c0(frame.quatB0, frame.tmp150, frame.tmp160);
        }
    } else {
        frame.quatC0[0] = *(f32 *)(unit0 + 0x1C);
        frame.quatC0[1] = *(f32 *)(unit0 + 0x20);
        frame.quatC0[2] = *(f32 *)(unit0 + 0x24);
        frame.quatC0[3] = *(f32 *)(unit0 + 0x28);
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
        frame.quatB0[0] = *(f32 *)(tmpUnit + 0x1C);
        frame.quatB0[1] = *(f32 *)(tmpUnit + 0x20);
        frame.quatB0[2] = *(f32 *)(tmpUnit + 0x24);
        frame.quatB0[3] = *(f32 *)(tmpUnit + 0x28);
    }
    frame.inA[0] = *(f32 *)(entry + 4);
    frame.inA[1] = *(f32 *)(entry + 8);
    frame.inA[2] = *(f32 *)(entry + 12);
    frame.inB[0] = *(f32 *)(entry + 16);
    frame.inB[1] = *(f32 *)(entry + 20);
    frame.inB[2] = *(f32 *)(entry + 24);
    if ((*(u16 *)(arg1 + 0xE) & 2) != 0) {
        frame.inA[0] = frame.inA[0] * -1.0f;
        frame.inB[0] = frame.inB[0] * -1.0f;
    }
    sw1 = *(u16 *)(entry + 2);
    if (sw1 == 2) {
        goto sw1_case2;
    }
    if (sw1 != 1) {
        goto sw1_done;
    }
    goto sw1_case1;
sw1_case1:
    tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
    func_003dcb40(&frame.f90[0], frame.inA, 1, frame.quatC0);
    func_003dcb40(&frame.f90[3], frame.inB, 1, frame.quatC0);
    frame.pos110[0] = *(f32 *)(tmpUnit + 4) + frame.f90[0];
    frame.pos110[1] = *(f32 *)(tmpUnit + 8) + frame.f90[1];
    frame.pos110[2] = *(f32 *)(tmpUnit + 12) + frame.f90[2];
    frame.pos12C[0] = *(f32 *)(tmpUnit + 4) + frame.f90[3];
    frame.pos12C[1] = *(f32 *)(tmpUnit + 8) + frame.f90[4];
    frame.pos12C[2] = *(f32 *)(tmpUnit + 12) + frame.f90[5];
    goto sw1_done;
sw1_case2:
    tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
    func_003dcb40(&frame.f90[0], frame.inA, 1, frame.quatB0);
    func_003dcb40(&frame.f90[3], frame.inB, 1, frame.quatB0);
    frame.pos110[0] = *(f32 *)(tmpUnit + 4) + frame.f90[0];
    frame.pos110[1] = *(f32 *)(tmpUnit + 8) + frame.f90[1];
    frame.pos110[2] = *(f32 *)(tmpUnit + 12) + frame.f90[2];
    frame.pos12C[0] = *(f32 *)(tmpUnit + 4) + frame.f90[3];
    frame.pos12C[1] = *(f32 *)(tmpUnit + 8) + frame.f90[4];
    frame.pos12C[2] = *(f32 *)(tmpUnit + 12) + frame.f90[5];
sw1_done:
    frame.inA[0] = *(f32 *)(entry + 32);
    frame.inA[1] = *(f32 *)(entry + 36);
    frame.inA[2] = *(f32 *)(entry + 40);
    frame.inB[0] = *(f32 *)(entry + 44);
    frame.inB[1] = *(f32 *)(entry + 48);
    frame.inB[2] = *(f32 *)(entry + 52);
    if ((*(u16 *)(arg1 + 0xE) & 2) != 0) {
        frame.inA[0] = frame.inA[0] * -1.0f;
        frame.inB[0] = frame.inB[0] * -1.0f;
    }
    sw2 = *(u16 *)(entry + 28);
    if (sw2 == 3) {
        goto sw2_case3;
    }
    if (sw2 == 2) {
        goto sw2_case2;
    }
    if (sw2 != 1) {
        goto sw2_done;
    }
    goto sw2_case1;
sw2_case1:
    tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
    func_003dcb40(&frame.f90[0], frame.inA, 1, frame.quatC0);
    func_003dcb40(&frame.f90[3], frame.inB, 1, frame.quatC0);
    frame.f70[0] = *(f32 *)(tmpUnit + 4) + frame.f90[0];
    frame.f70[1] = *(f32 *)(tmpUnit + 8) + frame.f90[1];
    frame.f70[2] = *(f32 *)(tmpUnit + 12) + frame.f90[2];
    frame.f70[3] = *(f32 *)(tmpUnit + 4) + frame.f90[3];
    frame.f70[4] = *(f32 *)(tmpUnit + 8) + frame.f90[4];
    frame.f70[5] = *(f32 *)(tmpUnit + 12) + frame.f90[5];
    goto sw2_done;
sw2_case2:
    tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
    func_003dcb40(&frame.f90[0], frame.inA, 1, frame.quatB0);
    func_003dcb40(&frame.f90[3], frame.inB, 1, frame.quatB0);
    frame.f70[0] = *(f32 *)(tmpUnit + 4) + frame.f90[0];
    frame.f70[1] = *(f32 *)(tmpUnit + 8) + frame.f90[1];
    frame.f70[2] = *(f32 *)(tmpUnit + 12) + frame.f90[2];
    frame.f70[3] = *(f32 *)(tmpUnit + 4) + frame.f90[3];
    frame.f70[4] = *(f32 *)(tmpUnit + 8) + frame.f90[4];
    frame.f70[5] = *(f32 *)(tmpUnit + 12) + frame.f90[5];
    goto sw2_done;
sw2_case3:
    tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
    if ((*(u32 *)(tmpUnit + 0x9C) & 0x8000) == 0) {
        func_001959d0(tmpUnit, frame.pos1A0);
    } else {
        func_00195850(tmpUnit, frame.pos1A0);
    }
    func_003dcb40(frame.dir1B0, (f32 *)D_0060A100, 1, frame.quatC0);
    scale = *(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C);
    frame.f70[0] = frame.pos1A0[0] + frame.dir1B0[0] * scale;
    frame.f70[1] = frame.pos1A0[1] + frame.dir1B0[1] * scale;
    frame.f70[2] = frame.pos1A0[2] + frame.dir1B0[2] * scale;
    if (frame.f70[1] < 100.0f) {
        frame.f70[1] = 100.0f;
    } else {
        if ((*(u16 *)(arg1 + 0xE) & 8) != 0) {
            if (frame.f70[1] > 250.0f) {
                frame.f70[1] = 250.0f;
            }
        } else if ((*(u16 *)(arg1 + 0xE) & 0x10) != 0) {
            if (frame.f70[1] > 500.0f) {
                frame.f70[1] = 500.0f;
            }
        } else if (((*(u16 *)(arg1 + 0xE) & 4) != 0) && (frame.f70[1] > 150.0f)) {
            frame.f70[1] = 150.0f;
        }
    }
    frame.f70[3] = frame.f70[0];
    frame.f70[4] = frame.f70[1];
    frame.f70[5] = frame.f70[2];
sw2_done:
    func_001bd780(frame.quat11C, frame.pos110, frame.f70, D_0060A0E0);
    angle = *(f32 *)(entry + 56);
    if (angle != 0.0f) {
        func_003e0870(frame.matD0, D_0060A0F0, 0, angle);
        func_003e4320(frame.vec170, D_0060A0E0, frame.matD0);
    } else {
        *(u64 *)frame.vec170 = *(u64 *)D_0060A0E0;
        frame.vec170[2] = *(f32 *)(D_0060A0E0 + 8);
    }
    func_001bd780(frame.quat138, frame.pos12C, &frame.f70[3], frame.vec170);
    func_001bac20(arg0, frame.pos110, frame.pos12C, 1);
    if (*(s16 *)(base + 2) == 2) {
        goto fin2;
    }
    if (*(s16 *)(base + 2) != 1) {
        if (*(s16 *)(base + 2) != 0) {
            goto fin_done;
        }
        goto fin0;
    }
    goto fin1;
fin0:
    func_001bbf40(arg0, (f32)*(s16 *)entry / 30.0f);
    goto fin_done;
fin1:
    func_001bbe80(arg0, (f32)*(s16 *)entry / 30.0f);
    goto fin_done;
fin2:
    func_001bbef0(arg0, (f32)*(s16 *)entry / 30.0f);
fin_done:
    *(s16 *)(arg1 + 0xA) = (s16)(index + 1);
    *(u16 *)(arg1 + 0xC) = 0;
    goto tick;
clear_flag:
    *(u16 *)(arg1 + 0xE) = (u16)(*(u16 *)(arg1 + 0xE) & 0xFFFE);
    goto tick;
bump_tick:
    *(u16 *)(arg1 + 0xC) = (u16)(*(u16 *)(arg1 + 0xC) + 1);
tick:
    *(u16 *)(arg1 + 0x8) = (u16)(*(u16 *)(arg1 + 0x8) + 1);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlCamera_grouped", func_001d07e0);
#endif
// FUN_001D10D0
u32 func_001d10d0(void* camera)
{
    return (*(u16*)((u8*)camera + 0xE) & 1) != 0;
}

/* Source unit: src/Battle/btlCamera_001d12e0.c */

void FUN_0043f9c8(void* memory, s32 value, u32 size);

// FUN_001D10F0
void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    s32 flags;

    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(u8 **)(arg0 + 0x10) = arg3;
    *(s16 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xA) = -1;
    *(s16 *)(arg0 + 0xC) = 0;
    *(u16 *)(arg0 + 0xE) |= 1;
    *(u16 *)(arg0 + 0xE) &= 0xFFFD;
    flags = arg4 & 0xFFFF;
    if ((flags & 1) && !(arg3[1] & 1) && (func_00231d70(0x64) >= 0x32U)) {
        *(u16 *)(arg0 + 0xE) |= 2;
    }
    if (flags & 2) {
        *(u16 *)(arg0 + 0xE) |= 4;
    }
    if (flags & 4) {
        *(u16 *)(arg0 + 0xE) |= 8;
    }
    if (flags & 8) {
        *(u16 *)(arg0 + 0xE) |= 0x10;
    }
    if (flags & 0x10) {
        *(u16 *)(arg0 + 0xE) |= 0x20;
    }
}
// FUN_001D1200
u8 *func_001d1200(u8 *arg0)
{
    u8 *base;
    s16 index;
    s32 condition;

    if ((*(u16 *)(arg0 + 0xE) & 1) == 0) {
        return 0;
    }
    base = *(u8 **)(arg0 + 0x10);
    index = *(s16 *)(arg0 + 0xA);
    if (base == 0) {
        return 0;
    }
    if (index == -1) {
        goto increment;
    }
    condition = *(u16 *)(arg0 + 0xC) < *(s16 *)(btlCamera_add_index(index * 0x3C, base) + 4);
    if (condition != 0) {
        goto done;
    }
increment:
    index++;
done:
    if (base[0] > index) {
        goto bound_ok;
    }
    return 0;
bound_ok:
    if (index >= 4) {
        return 0;
    }
    return base + index * 0x3C + 4;
}
// FUN_001D12E0
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}
