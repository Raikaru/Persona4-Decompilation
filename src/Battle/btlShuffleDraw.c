/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0036df30(u8 *arg0);
extern void func_0036d8b0(void);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern s32 func_0038cec0(void *arg0);
extern s32 func_00388bd0(void *arg0);
extern s32 func_0038d790(void *arg0);
extern void func_0034f1e0(void);
extern void func_00374d20(u8 *arg0);
extern void func_00371990(u8 *arg0, u8 *arg1, u8 *arg2);
extern void func_00371ba0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern void func_00370410(u8 *arg0);
extern void func_00370a80(u8 *arg0);
extern void func_003723a0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372870(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372c30(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern void func_003730f0(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_003733d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00373590(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef struct { f32 x, y, z; } ShuffleVec3;


// FUN_00373E10
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00373e10);


// FUN_00373F00
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00373f00);


// FUN_003740B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003740b0);


// FUN_003741F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003741f0);


// FUN_003742B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003742b0);


// FUN_00374610
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374610);


// FUN_00374730
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374730);


// FUN_00374910
void func_00374910(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
}


// FUN_00374960
void func_00374960(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
    *(s32 *)(arg0 + 0x1F298) = func_0038cec0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F294) = func_00388bd0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F29C) = func_0038d790((void *)*(s32 *)(arg0 + 0x1F2A8));
}


// FUN_00374A10
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374a10);


// FUN_00374CF0
void func_00374cf0(u8 *arg0) {
    func_0036df30(*(u8 **)arg0);
}


// FUN_00374D20
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374d20);


// FUN_003753F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003753f0);


// FUN_003757F0
void func_003757f0(u8 *arg0) {
    func_0034f1e0();
    if (*(u16 *)(arg0 + 0x1F2F4) & 4) {
        func_0036df30(arg0 + *(s32 *)(arg0 + 0x1F308) * 0xFB0);
    }
    if (*(u16 *)(arg0 + 0x1F2F4) & 8) {
        func_00374d20(arg0);
    }
}


// FUN_00375890
void func_00375890(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2) {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) |= 2;
    } else {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) &= 0xFFFD;
    }
}


// FUN_00375910
s32 func_00375910(u8 *arg0) {
    s32 b;

    b = func_00375970(arg0) != 0;
    if (b) {
        b = func_00375a00(arg0) != 0;
    }
    if (b) {
        b = func_00375a50(arg0) != 0;
    }
    return b;
}


// FUN_00375970
s32 func_00375970(u8 *arg0) {
    f32 var_f1;
    s32 temp_3;
    u32 temp_2;

    temp_3 = *(s32 *)(arg0 + 4);
    switch (temp_3) {
    case 0:
    case 5:
        return 1;
    default:
        temp_2 = *(u16 *)(arg0 + 0xC);
        if (temp_2 >= 0) {
            var_f1 = (f32)temp_2;
        } else {
            temp_2 = (temp_2 >> 1) | (temp_2 & 1);
            var_f1 = (f32)temp_2;
            var_f1 += var_f1;
        }
        return var_f1 >= *(f32 *)(arg0 + 0x10);
    }
}


// FUN_00375A00
s32 func_00375a00(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 8);
    switch (v) {
    case 0:
    case 3:
        return 1;
    default:
        return *(u16 *)(arg0 + 0x6C) >= *(u16 *)(arg0 + 0x6E);
    }
}


// FUN_00375A50
s32 func_00375a50(u8 *arg0) {
    return *(u16 *)(arg0 + 0xDC) >= *(u16 *)(arg0 + 0xDE);
}


// FUN_00375A70
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375a70);


// FUN_00375B40
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375b40);


// FUN_00375D50
void func_00375d50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 1;
}


// FUN_00375DD0
void func_00375dd0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 2;
}


// FUN_00375E50
void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371ba0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg4, arg2, arg3);
    *(s32 *)(p + 0x1D6A4) = 4;
}


// FUN_00375EC0
void func_00375ec0(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg1 * 0xE8) + (u32)arg0;
    *(u16 *)(p + 0x1D6A0) |= 1;
}


// FUN_00375F00
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375f00);


// FUN_00375FA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375fa0);


// FUN_00376070
void func_00376070(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_003723a0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A4) = 8;
}


// FUN_003760F0
void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372870((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A8) = 1;
}


// FUN_00376170
void func_00376170(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372c30((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5, (u8 *)arg6);
    *(s32 *)(p + 0x1D6A8) = 2;
}


// FUN_003761F0
void func_003761f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *(ShuffleVec3 *)arg4;
    idx = arg1 * 0xE8;
    p = (u8 *)idx + (u32)arg0;
    func_003730f0((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, &v);
    *(s32 *)(p + 0x1D6A8) = 4;
}


// FUN_00376290
void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_003733d0((u8 *)(arg0 + idx + 0x1D778), arg2, arg3, arg4);
}


// FUN_003762E0
void func_003762e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_00373590((u8 *)(arg0 + idx + 0x1D780), arg2, arg3, arg4);
}


// FUN_00376330
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376330);


// FUN_003764B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003764b0);


// FUN_00376590
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376590);


// FUN_003766F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003766f0);


// FUN_00376800
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376800);


// FUN_00376880
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376880);


// FUN_003768E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);


// FUN_00377930
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377930);


// FUN_00377E10
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377e10);


// FUN_00377E60
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377e60);


// FUN_00377EB0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377eb0);


// FUN_003781D0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003781d0);


// FUN_00378220
s32 func_00378220(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38)) != 0;
}


// FUN_00378240
s32 func_00378240(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x120;
}


// FUN_00378250
s32 func_00378250(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x1B0;
}


// FUN_00378260
void func_00378260(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    temp[0x11C] = arg1;
    temp[0x11D] = arg2;
    temp[0x11E] = arg3;
    *(s32 *)(temp + 4) = arg4;
}


// FUN_00378280
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00378280);


// FUN_00378500
s32 func_00378500(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    if ((u8)(*(u32 *)temp != 0) != 0) {
        return *(u32 *)(*(u8 **)(temp + 0x14));
    }
    return 0;
}


// FUN_00378530
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00378530);
