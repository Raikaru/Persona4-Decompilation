/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */
/* Original translation unit effPolygonFlash.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

extern void func_004833f0();
extern void (*jtbl_008873EC[])(void *);
extern void (*D_008873ec[])(void *);
extern void func_003c2290(void *, s32);
extern void func_003c22f0(void *);
extern s32 func_00481300(s32);
extern void func_003c42b0(void *, void *);
extern void func_00483970(void *, void *);
extern char D_00713408[];
extern void *func_004844d0(void);
extern void *func_00484490(void *);
extern char D_00714028[];
extern char D_00713CE0[];
extern void func_0043f810(void *, void *, void *);
extern char D_00714014[];
extern char D_00714010[];
extern void *func_004a1660(s32, void *);

extern u8 *(*jtbl_008873E8[])(s32, s32);
extern void func_0044ea90(char *, s32);
extern void func_0046d730(char *, s32);
extern char D_00713FF0[];
extern char D_007133A0[];
extern char D_007133C0[];
extern u8 *func_00482f70(s32, s32, s32, char *, s32);
extern u8 *func_00483270(void *);
extern void func_0049cfc0(u8 *, u8 *);
extern void func_0049ddd0(u8 *, u8 *);
extern void func_0049ebd0(u8 *, u8 *);
extern void func_004a08a0(u8 *, u8 *);

// FUN_0049A900
void *func_0049a900(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x89);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x90);
    mem = jtbl_008873E8[0](id * 24 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x91);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 3, 5, D_007133A0, 0x48);
    return mem;
}




// FUN_0049A9E0
void func_0049a9e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

// FUN_0049AA30
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049aa30);
// FUN_0049B2B0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049b2b0);
// FUN_0049B470
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049b470);
// FUN_0049B560
void *func_0049b560(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x1DE);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x1E5);
    mem = jtbl_008873E8[0](id * 28 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x1E6);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// FUN_0049B640
void func_0049b640(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

// FUN_0049B690
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049b690);
// FUN_0049BFF0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049bff0);
// FUN_0049C1B0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049c1b0);
// FUN_0049C2A0
void *func_0049c2a0(u8 *arg0, s32 arg1)
{
    u32 id;
    u8 *mem;

    if (arg1) {
        func_0046d730(D_00713FF0, 0x349);
    }
    id = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713FF0, 0x350);
    mem = jtbl_008873E8[0](id * 44 + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x351);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// FUN_0049C380
void func_0049c380(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}

// FUN_0049C3D0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049c3d0);
// FUN_0049CD10
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049cd10);
// FUN_0049CED0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049ced0);
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049CFC0
#pragma opt_loop_invariants on
void func_0049cfc0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x4BE);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_0049D100
void *func_0049d100(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x4A4);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    if (*(u32 *)(arg0 + 0x70) == 0) {
        *(u32 *)(arg0 + 0x70) = 1;
    }
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x12));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049cfc0(mem, arg0);
    return mem;
}
// FUN_0049D230
void *func_0049d230(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x4A4);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    if (*(u32 *)(p17 + 0x70) == 0) {
        *(u32 *)(p17 + 0x70) = 1;
    }
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049cfc0(mem, p17);
    return mem;
}
// FUN_0049D310
void func_0049d310(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
// FUN_0049D360
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049d360);
// FUN_0049DB20
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049db20);
// FUN_0049DCE0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049dce0);
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049DDD0
#pragma opt_loop_invariants on
void func_0049ddd0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x65A);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_0049DF10
void *func_0049df10(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x644);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x13));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049ddd0(mem, arg0);
    return mem;
}
// FUN_0049E030
void *func_0049e030(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 24;
    func_0044ea90(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x644);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049ddd0(mem, p17);
    return mem;
}
// FUN_0049E100
void func_0049e100(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
// FUN_0049E150
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049e150);
// FUN_0049E920
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049e920);
// FUN_0049EAE0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049eae0);
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_0049EBD0
#pragma opt_loop_invariants on
void func_0049ebd0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0x803);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_0049ED10
void *func_0049ed10(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 40;
    func_0044ea90(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x7ED);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x12));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_0049ebd0(mem, arg0);
    return mem;
}
// FUN_0049EE30
void *func_0049ee30(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 40;
    func_0044ea90(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x7ED);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_0049ebd0(mem, p17);
    return mem;
}
// FUN_0049EF00
void func_0049ef00(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
// FUN_0049EF50
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049ef50);
// FUN_0049F820
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049f820);
// FUN_0049F9E0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049f9e0);
// FUN_0049FAD0
void *func_0049fad0(u8 *arg0)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 44;
    func_0044ea90(D_00713FF0, 0x98E);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0x98F);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 3, 5, D_007133A0, 0x48);
    return mem;
}
// FUN_0049FBA0
void func_0049fba0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 8));
}
// FUN_0049FBF0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_0049fbf0);
// FUN_004A05F0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a05f0);
// FUN_004A07B0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a07b0);
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// FUN_004A08A0
#pragma opt_loop_invariants on
void func_004a08a0(u8 *arg0, u8 *arg1)
{
    u32 count;
    u8 *p16;
    u8 *p17;
    u32 i;

    count = *(u32 *)(arg1 + 0x38);
    if (count != 0) {
        func_003c2290(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18), 0xFF0);
        p17 = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18) + 0x34);
        if (p17 == NULL) {
            func_0046d730(D_00713FF0, 0xB08);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                *(f32 *)(p17 + 0x00) = 0.0f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 0.5f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.0f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 0.5f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            } else {
                *(f32 *)(p17 + 0x00) = 0.5f;
                *(f32 *)(p17 + 0x04) = 0.0f;
                *(f32 *)(p17 + 0x08) = 1.0f;
                *(f32 *)(p17 + 0x0C) = 0.0f;
                *(f32 *)(p17 + 0x10) = 0.5f;
                *(f32 *)(p17 + 0x14) = 1.0f;
                *(f32 *)(p17 + 0x18) = 1.0f;
                *(f32 *)(p17 + 0x1C) = 1.0f;
            }
            i++;
            p17 += 0x20;
        }
        p17 = *(u8 **)(arg0 + 4);
        p16 = *(u8 **)(*(u8 **)(p17 + 0x10) + 0x18);
        func_003c22f0(p16);
        if (*(u16 *)(p17 + 0) & 4) {
            *(u16 *)(p16 + 0xC) |= 1;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_004A09E0
void *func_004a09e0(u8 *arg0, void *arg1)
{
    u32 size;
    u8 *mem;

    size = *(u32 *)(arg0 + 0x38) * 32;
    func_0044ea90(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0xAF2);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00482f70(*(u16 *)(arg0 + 0x38), 2, 4, D_00713408, 0x4C);
    if (arg1 == NULL) {
        func_003c42b0(*(u8 **)(*(u8 **)(mem + 4) + 0x14), (void *)func_00481300(0x13));
    } else {
        func_00483970(*(u8 **)(mem + 4), arg1);
    }
    func_004a08a0(mem, arg0);
    return mem;
}
// FUN_004A0AF0
void *func_004a0af0(u8 *arg0)
{
    u8 *p16;
    u8 *p17;
    u32 size;
    u8 *mem;

    p16 = *(void **)(arg0 + 0x3C);
    p17 = *(void **)(arg0 + 0x40);
    size = *(u32 *)(p17 + 0x38) * 32;
    func_0044ea90(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        func_0046d730(D_00713FF0, 0xAF2);
    }
    *(u32 *)(mem + 0) = (u32)(mem + 0x10);
    *(u32 *)(mem + 8) = (u32)mem;
    *(u32 *)(mem + 4) = (u32)func_00483270(*(void **)(p16 + 4));
    func_004a08a0(mem, p17);
    return mem;
}




// FUN_004A0BB0
void func_004a0bb0(u8 *arg0) {
    func_004833f0(*(s32 *)(arg0 + 4));
    D_008873ec[0](*(void **)(arg0 + 8));
}

// FUN_004A0C00
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a0c00);
// FUN_004A14A0
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a14a0);
// FUN_004A1660
INCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a1660);

// FUN_004A1780
void *func_004a1780(u8 *arg0)
{
    u8 *p16;
    u8 *p19;
    u8 *p18;
    u8 *p17;
    u32 idx;

    p18 = func_004844d0();
    if (p18 == NULL) {
        func_0046d730(D_00713FF0, 0xD08);
    }
    switch (*(u16 *)(arg0 + 0x1C)) {
    case 1:
        break;
    case 4:
        p18 = NULL;
        break;
    default:
        func_0046d730(D_00713FF0, 0xD11);
        break;
    }
    p19 = func_00484490(arg0);
    if (p19 == NULL) {
        func_0046d730(D_00713FF0, 0xD16);
    }
    p16 = (u8 *)(*(u16 *)(arg0 + 0xC) & 0xFFFF);
    p17 = func_004a1660((s32)p16, p19);
    idx = ((u32)p16 & 0xFFFF) * 28;
    *(u32 *)(p17 + 0x3C) = (u32)((void *(*)(void *, void *))(*(void **)(D_00714014 + idx)))(p19, p18);
    ((void (*)(void *))(*(void **)(D_00714010 + idx)))(p17);
    if (p17 == NULL) {
        func_0046d730(D_00713FF0, 0xD18);
    }
    return p17;
}
