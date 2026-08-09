#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb4bc;
extern void func_0026d810();

extern u8 *func_00452560();
extern s32 func_00452490(u8 *arg0);

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(void);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);

extern void func_004b1150(u8 *arg0);

// FUN_00260510
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260510);
// FUN_00260560
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260560);
// FUN_002605A0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_002605a0);
// FUN_00260600
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260600);
// FUN_00260E60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260e60);
// FUN_00261560
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00261560);
// FUN_00262DE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00262de0);
// FUN_00263220
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263220);
// FUN_00263460
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263460);
// FUN_00263730
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263730);
// FUN_00263CB0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263cb0);
// FUN_00264CB0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00264cb0);
// FUN_00264D10
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00264d10);
// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266A90
void func_00266a90(u8 *arg0) {
    u8 *p;

    if (func_00452490(arg0) != 0) {
        p = func_00452560(arg0);
        *(s32 *)(p + 4) |= 2;
    }
}

// FUN_00266AE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266ae0);
// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}



// FUN_00266BA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266ba0);
// FUN_00266CC0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266cc0);
// FUN_002674B0
void func_002674b0(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266cc0;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_00267510
void func_00267510(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0025f230((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00267570
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267570);
// FUN_00267670
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267670);
/* measured: optimization_level 1 and the right-associated first two terms produce the retail FPU chain; exact match nd 0 (obj 88B/window 96B). */
// FUN_002677A0
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
#pragma optimization_level 1
f32 func_002677a0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}
/* measured: closes the optimization_level bracket (nd 0). */
#pragma optimization_level 2

// FUN_00267800
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267800);
// FUN_00267B20
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267b20);
// FUN_00268A70
s32 func_00268a70(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_16 - 1;
    *(s32 *)temp_16 = temp_2;
    if (temp_2 < 0) {
        func_004b1150((u8 *)*(s32 *)(temp_16 + 4));
        *(s32 *)(temp_16 + 4) = 0;
        return -1;
    }
    return 0;
}

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

// FUN_0026CEF0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026cef0);
// FUN_0026DB60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026db60);
// FUN_0026DC30
void func_0026dc30(void)
{
    func_0026d810();
}

// FUN_0026DC50
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026dc50);
// FUN_0026DD60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026dd60);
// FUN_0026DEE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026dee0);
// FUN_0026DF80
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026df80);
// FUN_0026E010
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e010);
// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

// FUN_0026E4C0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e4c0);
// FUN_0026E560
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e560);
// FUN_0026E590
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e590);
// FUN_0026E630
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e630);
// FUN_0026E6D0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e6d0);
// FUN_0026E700
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e700);
// FUN_0026E7F0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e7f0);
// FUN_0026E910
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e910);
// FUN_0026E940
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e940);
// FUN_0026EA50
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ea50);
// FUN_0026EBA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026eba0);
// FUN_0026EBE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ebe0);
// FUN_0026ED00
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ed00);
// FUN_0026EE00
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ee00);
// FUN_0026EF00
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ef00);
// FUN_0026EF60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026ef60);
// FUN_0026F0A0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f0a0);
// FUN_0026F1E0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f1e0);
// FUN_0026F2C0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f2c0);
// FUN_0026F5A0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f5a0);
// FUN_0026F5E0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f5e0);
// FUN_0026F860
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f860);
// FUN_0026FBA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fba0);
// FUN_0026FC20
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fc20);
// FUN_0026FCA0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fca0);
// FUN_0026FD90
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fd90);
// FUN_0026FFF0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fff0);