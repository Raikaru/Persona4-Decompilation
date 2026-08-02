/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonRing.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern u8 *func_00484490();
extern void func_0046d730();
extern u8 *func_0049a370(u16 arg0, u8 *arg1);
extern u8 D_00713EF0[];
extern void func_004833f0(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void func_0049a570(void *arg0);

extern void func_0044ea90();
extern void func_0043f810(void *dst, void *src, u32 size);
extern u8 *func_00482f70(u32 arg0, u32 arg1, u32 arg2, void *arg3, u32 arg4);
extern f32 func_004bd0b0();
extern u8 D_00713390[];
extern s32 func_0048abd0();
extern void func_004836b0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void func_00483490(void *arg0, u16 arg1);
extern f32 iGpffff8044;
extern void func_0049a610(void *arg0);
extern u8 *func_00482dc0();
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00713330[];
extern LineNovaColor iGpffffbb64;
extern u_long128 D_00713CE0;
extern s32 D_00713F24[];
extern u32 D_00713F14[];
extern u32 D_00713F10[];



// FUN_00498DA0
u8 *func_00498da0(u8 *arg0) {
    u8 *alloc;
    u8 *p2;
    s32 count;
    s32 v44;
    s32 v48;
    s32 v4C;
    u32 i;
    u8 *dst;

    func_0044ea90(D_00713EF0, 0x39);
    alloc = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (alloc == NULL) {
        func_0046d730(D_00713EF0, 0x3A);
    }
    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    p2 = func_00482dc0(*(u16 *)(arg0 + 0x38), D_00713330, 4, 0x48);
    *(u32 *)alloc = (u32)p2;
    count = *(s16 *)(p2 + 8) / 4;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(p2 + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    v4C = *(s32 *)(arg0 + 0x4C);
    i = 0;
    while (i < (u32)count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v48;
        *(s32 *)(dst + 8) = v48;
        *(s32 *)(dst + 0xC) = v4C;
        i++;
        dst += 0x10;
    }
    return alloc;
}
// FUN_00498EC0
void func_00498ec0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}



// FUN_00498F10
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00498f10);

// FUN_004992A0
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_004992a0);

// FUN_00499470
void func_00499470(u8 *arg0) {
    u8 *p8;
    u8 *p3;
    u8 *dst;

    p8 = *(u8 **)(arg0 + 0x3C);
    p3 = *(u8 **)(p8 + 8);
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p3 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p3 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    func_0049a610(*(void **)(p8 + 4));
}

// FUN_00499510
u8 *func_00499510(u8 *arg0) {
    u8 *work;
    u8 *p;
    u32 count;
    u32 stride;
    u32 i;
    u8 *dst;
    s32 v44;
    s32 v48;
    s32 avg;
    f32 f20;
    f32 t;

    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    count = *(u32 *)(arg0 + 0x38);
    func_0044ea90(D_00713EF0, 0x10F);
    stride = count * 4;
    p = (u8 *)(*jtbl_008873E8)(stride + 0x10, 0x40000);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x110);
    }
    work = p + stride;
    *(u32 *)(work + 0) = (u32)p;
    *(u32 *)(work + 0xC) = (u32)p;
    func_0043f810(arg0 + 0x5C, arg0, 0x5C);
    *(u32 *)(work + 4) = (u32)func_0049a370(1, arg0 + 0x5C);
    *(u32 *)(work + 8) = (u32)func_00482f70(count & 0xFFFF, 2, 4, D_00713390, 0x48);
    dst = *(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(work + 8) + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    i = 0;
    avg = (v44 & v48) + (s32)(((u32)(v44 ^ v48) & 0xFEFEFEFE) >> 1);
    while (i < count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v44;
        *(s32 *)(dst + 8) = avg;
        *(s32 *)(dst + 0xC) = v44;
        f20 = *(f32 *)(arg0 + 0xCC);
        t = func_004bd0b0(0);
        *(f32 *)(p + 0) = *(f32 *)(arg0 + 0xC8) * ((1.0f - f20) + f20 * t);
        i++;
        dst += 0x10;
        p += 4;
    }
    return work;
}
// FUN_004996E0
void func_004996e0(u8 *arg0)
{
    func_004833f0(*(void **)(arg0 + 8));
    func_0049a570(*(void **)(arg0 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0xC));
}



// FUN_00499730
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499730);

// FUN_00499A30
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499a30);

// FUN_00499C50
void func_00499c50(u8 *arg0) {
    u8 *p4;
    u8 *dst;

    p4 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    if (iGpffffbb64.c3 != 0xFF) {
        dst = *(u8 **)(p4 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = *(u8 **)(p4 + 0x14);
        *(LineNovaColor *)(dst + 4) = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
}

// FUN_00499CD0
u8 *func_00499cd0(u8 *arg0) {
    u8 *alloc;
    u8 *p2;
    s32 count;
    s32 v44;
    s32 v48;
    s32 v4C;
    u32 i;
    u8 *dst;

    func_0044ea90(D_00713EF0, 0x1E6);
    alloc = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (alloc == NULL) {
        func_0046d730(D_00713EF0, 0x1E7);
    }
    if (*(u32 *)(arg0 + 0x38) < 3) {
        *(u32 *)(arg0 + 0x38) = 3;
    }
    p2 = func_00482dc0(*(u16 *)(arg0 + 0x38), D_00713330, 4, 0x48);
    *(u32 *)alloc = (u32)p2;
    count = *(s16 *)(p2 + 8) / 4;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(p2 + 0x10) + 0x18) + 0x30);
    v44 = *(s32 *)(arg0 + 0x44);
    v48 = *(s32 *)(arg0 + 0x48);
    v4C = *(s32 *)(arg0 + 0x4C);
    i = 0;
    while (i < (u32)count) {
        *(s32 *)(dst + 0) = v44;
        *(s32 *)(dst + 4) = v48;
        *(s32 *)(dst + 8) = v48;
        *(s32 *)(dst + 0xC) = v4C;
        i++;
        dst += 0x10;
    }
    return alloc;
}
// FUN_00499DF0
void func_00499df0(void **arg0)
{
    func_004833f0(*arg0);
    jtbl_008873EC[0](arg0);
}

// FUN_00499E40
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_00499e40);

// FUN_0049A1A0
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_0049a1a0);

/* measured: retail copies the 16-byte global D_00713CE0 with lui+addiu+lq+sq;
   mwcc b210 folds the LO16 address into the lq (lui+lq %lo) whenever the copy
   sits in a register-pressured function, shifting the whole tail by one word
   (nd 39, all rows the same opcodes). Tried: array+direct deref, array+&+cast,
   scalar u_long128+&, quadSrc/quad locals, dstq local, memcpy(...,0x10),
   u64-pair, #pragma optimization_level 3, declaration reorders - every one
   either folds identically (39) or gets worse (40/81/88). This is the
   load-sinking / address-fold family of floors; the sibling effPolygonWind
   func_004a5630 has the identical retail shape and its owner is blocked on
   the same fold. */
// FUN_0049A370
INCLUDE_ASM("asm/nonmatchings/effPolygonRing", func_0049a370);

// FUN_0049A4E0
u8 *func_0049a4e0(u8 *arg0) {
    u8 *p;

    p = func_00484490(arg0);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x2E5);
    }
    p = func_0049a370(*(u16 *)(arg0 + 0xC), p);
    if (p == NULL) {
        func_0046d730(D_00713EF0, 0x2E7);
    }
    return p;
}
