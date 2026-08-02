/* Consolidated Persona 4 source units. */
/* Original translation unit y_draw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern u8 *iGpffffb574;

typedef struct {
    f32 x, y;
} f2;

typedef struct {
    u8 c0, c1, c2, c3;
} u4;


extern void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5);

extern void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern void func_0048a000(void);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 *D_0076DB7C;

extern void func_002b8270(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);

extern void func_002b8340(u8 *arg0, u8 arg1, s16 arg2, s16 arg3, f32 fparg0, f32 fparg1);

extern void func_002b8370(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5);


// FUN_002B5C90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5c90);

// FUN_002B5DA0
u8 *func_002b5da0(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002B5DB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5db0);

// FUN_002B5E20
void func_002b5e20(u8 *arg0, f32 fparg0) {
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x130) = fparg0;
}

// FUN_002B5E30
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5e30);
// FUN_002B5E90
void func_002b5e90(u8 *arg0, f2 p1, f2 p2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg3;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    *(s16 *)(base + 0x156) = 2;
    base[0x154] = 0;
    base[0x0] = 2;
}

// FUN_002B5EF0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5ef0);

// FUN_002B5FD0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5fd0);

// FUN_002B60F0
void func_002b60f0(u8 *arg0, u8 arg1, u8 arg2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    base[0x178] = arg1;
    base[0x179] = arg2;
    *(s16 *)(base + 0x17A) = 0;
    *(u32 *)(base + 0x17C) = arg3;
    base[0x180] = 1;
}

// FUN_002B6120
void func_002b6120(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x154) = arg1;
}

// FUN_002B6130
void func_002b6130(u8 *arg0, u32 arg1) {
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x188) = arg1;
}

// FUN_002B6140
void func_002b6140(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x184) = arg1;
}

// FUN_002B6150
u8 *func_002b6150(s16 arg0) {
    return (u8 *)((u32)(*(u8 **)(D_0076DB7C + 0x38)) + (u32)((s32)arg0 << 8) + 4);
}
// FUN_002B6180
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6180);

// FUN_002B6260
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6260);

// FUN_002B6340
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6340);

// FUN_002B6560
void func_002b6560(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B6590
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6590);

// FUN_002B67A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b67a0);

// FUN_002B6820
s8 func_002b6820(u8 *arg0, u32 arg1) {
    u32 n = arg1 & 0xFFFF;
    return (s8)((s32)(*(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10) & ((1 << n) & 0xFFFF)) >> n);
}




// FUN_002B6850
s32 func_002b6850(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

// FUN_002B68D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b68d0);

// FUN_002B6970
s16 func_002b6970(s16 arg0, s16 arg1) {
    return (s16)((arg0 & ((1 << arg1) & 0xFFFF)) >> arg1);
}

// FUN_002B69B0
void func_002b69b0(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    func_002b8270(*(u8 **)(arg0 + 0x38) + 0x10, p1, p2, arg3, arg4, arg5);
}

// FUN_002B69F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b69f0);

// FUN_002B6A40
void func_002b6a40(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg5;
    func_002b82d0(base + 0x10, arg1, arg2, arg3, arg4, ext);
}




// FUN_002B6A70
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6a70);

// FUN_002B6AC0
void func_002b6ac0(u8 *arg0, u32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg3;
    func_002b8300(base + 0x10, arg1, arg2, ext, fparg0, fparg1, fparg2, fparg3);
}

/* measured: retail issues both indirections up front (lw gp, then lw 0x38) before touching
   arg0; mwcc b210 sinks the 0x38 load past the shift, which also flips the addu operand
   order. Hoisting the base into a local first does not move it (nd 9 either way). This is
   the load-sinking wall documented in docs/matching.md. */
// FUN_002B6AF0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6af0);

/* measured: same load-sinking wall as func_002b6af0 - retail loads the table base before
   using arg0, mwcc sinks it to its use. nd 9 with and without a hoisted base local. */
// FUN_002B6B40
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b40);

// FUN_002B6B90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b90);

// FUN_002B6BE0
void func_002b6be0(u8 *arg0, f2 p1, u32 arg2, f32 fparg0) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x10) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x14) = fparg0;
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x8) = arg2;
    *(f2 *)(base + 0x38) = p1;
}

// FUN_002B6C30
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6c30);

// FUN_002B6D60
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6d60);

// FUN_002B6DA0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6da0);

// FUN_002B6EA0
void func_002b6ea0(void) {
    func_0048a000();
}

// FUN_002B6EC0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6ec0);

// FUN_002B74C0
void func_002b74c0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B74F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b74f0);

// FUN_002B7750
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7750);

// FUN_002B77D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b77d0);

// FUN_002B7CD0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7cd0);

// FUN_002B7F20
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7f20);

// FUN_002B8120
void func_002b8120(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B8150
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8150);

// FUN_002B81F0
u8 *func_002b81f0(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002B8200
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b8200);

// FUN_002B8270
void func_002b8270(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5) {
    *(f32 *)(arg0 + 0x18) = p1.x;
    *(f32 *)(arg0 + 0x1C) = p1.y;
    *(f32 *)(arg0 + 0x20) = p2.x;
    *(f32 *)(arg0 + 0x24) = p2.y;
    *(f32 *)(arg0 + 0x28) = p1.x;
    *(f32 *)(arg0 + 0x2C) = p1.y;
    *(s16 *)(arg0 + 0x32) = 0;
    *(s16 *)(arg0 + 0x30) = arg4;
    *(s16 *)(arg0 + 0x34) = arg5;
    arg0[0x36] = arg3;
    *(s16 *)(arg0 + 0x0) |= 2;
}

// FUN_002B82D0
void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5) {
    arg0[0x5C] = arg1;
    arg0[0x5D] = arg2;
    arg0[0x5E] = arg1;
    *(s16 *)(arg0 + 0x5A) = 0;
    *(s16 *)(arg0 + 0x58) = arg4;
    *(s16 *)(arg0 + 0x60) = arg5;
    arg0[0x62] = arg3;
    *(s16 *)(arg0 + 0x0) |= 4;
}

// FUN_002B8300
void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    *(f32 *)(arg0 + 0x88) = fparg0;
    *(f32 *)(arg0 + 0x8C) = fparg1;
    *(f32 *)(arg0 + 0x90) = fparg0;
    *(f32 *)(arg0 + 0x94) = fparg2;
    *(f32 *)(arg0 + 0x98) = fparg3;
    *(f32 *)(arg0 + 0x9C) = fparg2;
    *(s16 *)(arg0 + 0x84) = 0;
    *(s16 *)(arg0 + 0x82) = arg2;
    *(s16 *)(arg0 + 0xA0) = arg3;
    arg0[0xA2] = arg1;
    *(s16 *)(arg0 + 0x0) |= 0x10;
}

// FUN_002B8340
void func_002b8340(u8 *arg0, u8 arg1, s16 arg2, s16 arg3, f32 fparg0, f32 fparg1) {
    *(f32 *)(arg0 + 0xB8) = fparg0;
    *(f32 *)(arg0 + 0xBC) = fparg1;
    *(f32 *)(arg0 + 0xC0) = fparg0;
    *(s16 *)(arg0 + 0xC4) = 0;
    *(s16 *)(arg0 + 0xC6) = arg2;
    *(s16 *)(arg0 + 0xC8) = arg3;
    arg0[0xCA] = arg1;
    *(s16 *)(arg0 + 0x0) |= 8;
}

// FUN_002B8370
void func_002b8370(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5) {
    arg0[0x6D] = arg1.c0;
    arg0[0x6E] = arg1.c1;
    arg0[0x6F] = arg1.c2;
    arg0[0x71] = arg2.c0;
    arg0[0x72] = arg2.c1;
    arg0[0x73] = arg2.c2;
    arg0[0x75] = arg1.c0;
    arg0[0x76] = arg1.c1;
    arg0[0x77] = arg1.c2;
    *(s16 *)(arg0 + 0x7A) = arg4;
    *(s16 *)(arg0 + 0x7C) = 0;
    *(s16 *)(arg0 + 0x7E) = arg5;
    arg0[0x80] = arg3;
    *(s16 *)(arg0 + 0x0) |= 0x200;
}

// FUN_002B83E0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b83e0);

// FUN_002B89A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b89a0);

// FUN_002B9AB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9ab0);

// FUN_002B9E10
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9e10);

// FUN_002B9F60
void func_002b9f60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B9F90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9f90);

