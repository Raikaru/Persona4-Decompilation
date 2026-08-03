#include "include_asm.h"
/* Persona 4 USA decompilation - effBlurFilter.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);

/* Defined below in this file; called above its definition. */
extern u8 *func_004ab960(u16 *arg0, s32 arg1);

extern char D_00714380[];
extern u8 D_00714394[];
extern u8 D_00714398[];
extern u8 D_0071439C[];
extern u8 D_007143A0[];
extern char D_00714450[];
extern u8 D_00714464[];
extern u8 D_00714468[];
extern u8 D_0071446C[];
extern u8 D_00714470[];

extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern void func_003f6690(s32 param, void *out);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u32 D_00922D90[];
extern u8 D_00714368[];
extern void func_0048a070(s64 arg);
extern void func_0048a0e0(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_004a7e30(u8 *arg0, void *arg1);
extern void func_004a8250(u8 *arg0, void *arg1);
extern void func_004a8440(u8 *arg0, void *arg1);
extern void func_004a86c0(u8 *arg0, void *arg1);
extern void func_00460ac0(s32 param, void *work);
extern s32 func_004814d0(u16 param);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern f32 fGpffff80f8;
extern void func_004a8a50(u8 *arg0, u8 *arg1);
extern void func_004a8da0(u8 *arg0, u8 *arg1);
extern void func_004a8890(u8 *arg0, s32 *arg1);
extern s32 func_00481390(void *ptr);
extern s32 func_00481300(u16 param);
extern s32 func_00484490(void);
extern u16 *func_004844d0(u8 *obj);
extern u8 D_00714390[];
extern u8 D_007143A4[];
extern u8 D_00714460[];
extern u8 D_00714474[];
extern u8 *func_004aaee0(u32 arg0, s32 arg1);
extern u8 *func_004ab420(u32 arg0, s32 arg1);

typedef struct BlurRefObj {
    s32 f0;
    s32 f4;
} BlurRefObj;

extern void *func_004abb00(BlurRefObj *param_1);
extern void func_004aba70(void *param_1);

extern f32 func_0044b7b0(f32 fparg0);
extern s32 func_0044dcd8(f32 a);
extern s32 func_0044b310(s32 a);
extern s32 func_0044e100(s64 a, s32 b);
extern s32 func_0044e168(s64 a, s32 b);
extern f32 func_0044e7d8(s32 a);
extern f32 fGpffff8084;
extern s64 fGpffff8018;
extern s64 fGpffff8020;
extern s64 fGpffff8010;

extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
extern f32 func_0048aff0(u8 *a, s32 b, s32 c);
extern f32 func_0048a650(f32 a);
extern f32 fGpffff8044;
extern f32 fGpffff80f0;
extern void func_004a8bb0(u8 *a, u8 *b);
extern void func_004a8f90(u8 *a, u8 *b);
extern void func_004a9180(u8 *a, u8 *b);

/* measured: retail's byte->f32 doubling and alpha blocks keep their values in
   $a0 and convert into $f20 (or-dest = the srl scratch); mwcc b210 recompiled
   from equivalent C keeps them in $v1 and converts into $f0, nd 11 (6 rows,
   3 blocks). Tried 5 declaration orders, single/multi-statement forms, temps,
   ternaries, shift/and operand orders - identical result. Scratch-register
   rotation floor. */
// FUN_004A8BB0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a8bb0);

extern u32 func_004bd050(u32 param);
extern f32 func_004bd0b0(u32 param);
extern f32 func_0044b610(f32 param);
extern f32 fGpffff80f4;
extern f32 fGpffff80cc;

/* measured: retail seeds the ACC with mula.s (0.5f*t2) for the second
   var_f23 = cc*var_f20 + 0.5f*var_f23 update and keeps the second sub-chain
   result in $f2; mwcc b210 recompiled from equivalent C precomputes 0.5f*t2
   with mul.s, CSEs cc*var_f20, and fuses madd.s with the wrong multiplier
   (0.5f*(0.5f*t2)), nd 19 (9 rows, one block). Tried summand orders, m2c
   declaration order, explicit temps - identical result. Register/FMA-fusion
   floor. */
// FUN_004A8DA0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a8da0);

/* measured: same byte->f32 doubling/alpha scratch-register floor as
   func_004a8bb0: retail keeps the lbu byte, the srl/or scratch and the
   clamp value in $a0 and converts into $f20 (or-dest = the srl scratch);
   mwcc b210 recompiled from equivalent C uses $v1 and converts into $f0,
   nd 11 (9 rows). Tried s32-lbu local, both branch orders, inline/temp
   doubling, split statements, shared clamp local with & 0xFF - structure
   matches except this rotation. Scratch-register rotation floor. */
// FUN_004A8F90
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a8f90);

/* measured: same byte-doubling floor as func_004a8bb0 (or-dest/cvt-into-f20)
   plus the 1.0f-materialisation order in the madd store (mwcc hoists the x
   load ahead of lui/mtc1 and gains an extra nop), nd 12 (6 rows). Tried
   both summand orders and declaration swaps - identical result. */
// FUN_004A9180
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a9180);

// FUN_004A93D0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a93d0);

// FUN_004A9590
void func_004a9590(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        if (func_004a7e30(base, sp20) != 0) {
            D_00887300[0](1, D_00922D90[0]);
            func_003f6440(3, 0x31001);
            func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
            D_00887314[0](3, sp20, 4, D_00714368, 6);
            func_0048a0e0();
        }
        func_003f6440(3, sp12C);
        D_00887300[0](1, 0);
    }
}

// FUN_004A9690
void func_004a9690(u8 *arg0) {
    f32 vec[4];
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(f32 *)(base + 0x14) = 320.0f;
            *(f32 *)(base + 0x18) = 224.0f;
            *(f32 *)(base + 0x1C) = 320.0f - f;
            *(f32 *)(base + 0x20) = 224.0f - f;
            *(f32 *)(base + 0x24) = 320.0f + f;
            *(f32 *)(base + 0x28) = 224.0f + f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            g = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x14) = vec[0];
            *(f32 *)(base + 0x18) = vec[1];
            *(f32 *)(base + 0x1C) = vec[0] - g;
            *(f32 *)(base + 0x20) = vec[1] - g;
            *(f32 *)(base + 0x24) = vec[0] + g;
            *(f32 *)(base + 0x28) = vec[1] + g;
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp7C = *(s32 *)(arg0 + 0x10);
        pt = &sp7C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp78 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x74($sp)      \n"
            :
            : "r"(&sp78), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 4) = *(volatile s32 *)&sp74;
        *(f32 *)(base + 0x10) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a) + 1.0f;
        *(f32 *)(base + 0xC) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 8) = *(s32 *)(obj + 0x28);
    } else {
        *(s8 *)(base + 7) = 0;
    }
}

typedef struct BlurGsQuad {
    f32 x, y;
    u8 pad0[0x38];
    f32 x1, y1;
    u8 pad1[0x38];
    f32 x2, y2;
    u8 pad2[0x38];
    f32 x3, y3;
    u8 pad3[0x38];
} BlurGsQuad;

/* measured: retail materialises `addiu $a0,1` before `lw $a1,($s0)` for the
   first D_00887300 vtable call; mwcc b210 hoists the register-indirect load
   first (global-load args order fine), nd 3 (2 rows). Direct D_00887300[0]()
   spelling loses the $s1 address hoist (frame -0x10); cached setState pointer
   keeps the hoist but keeps the load-first order. Argument-evaluation-order
   floor. */
// FUN_004A98D0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004a98d0);

// FUN_004A9AA0
u8 *func_004a9aa0(u8 *arg0) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x64)) {
        func_0046d730(D_00714380, 0x169);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x16F);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        func_004a8a50(base, item);
        *(f32 *)(item + 4) = fGpffff80f8;
    }
    return alloc;
}

// FUN_004A9BA0
void func_004a9ba0(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004A9BD0
void func_004a9bd0(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x1C) = 0x43A00000;
            *(s32 *)(base + 0x20) = 0x43600000;
            *(f32 *)(base + 0x24) = f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(f32 *)(base + 0x24) = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x1C) = vec[0];
            *(f32 *)(base + 0x20) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x18) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a8bb0(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}
// FUN_004A9DD0
void func_004a9dd0(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        if (!(count <= 0x64)) {
            func_0046d730(D_00714380, 0x1BA);
        }
        for (i = 0; i < count; i++) {
            if (*(s32 *)list == 0 && *(u8 *)(list + 0xF) > 0) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004A9EA0
void func_004a9ea0(u8 *arg0) {
    u8 *base;
    u32 count;
    u8 *alloc;
    s32 i;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x28)) {
        func_0046d730(D_00714380, 0x292);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x298);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        *(s32 *)(item + 4) = 0;
        *(s32 *)item = 0;
        *(s32 *)(item + 0x10) = *(s32 *)(arg0 + 0xD0);
        *(f32 *)(item + 0x14) = *(f32 *)(arg0 + 0xD4);
        *(f32 *)item = -(*(f32 *)(arg0 + 0xC8) * (f32)i);
    }
}

// FUN_004A9FA0
void func_004a9fa0(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004A9FD0
void func_004a9fd0(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x20) = 0x43A00000;
            *(s32 *)(base + 0x24) = 0x43600000;
            *(s32 *)(base + 0x28) = (s32)f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(s32 *)(base + 0x28) = (s32)func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x20) = vec[0];
            *(f32 *)(base + 0x24) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x1C) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a9180(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}

// FUN_004AA1F0
void func_004aa1f0(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 *table;
    s32 count;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        for (i = 0; i < count; i++) {
            if (!(*(f32 *)list < 0.0f) && (*(u8 *)(list + 0xF) > 0)) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004AA2B0
void func_004aa2b0(u8 *arg0) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    u8 *base;
    u8 *obj;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (b == 0) {
        *(s32 *)(base + 0x10) = 0x43A00000;
        *(s32 *)(base + 0x14) = 0x43600000;
        *(s32 *)(base + 0x18) = 0;
        *(s32 *)(base + 0x1C) = 0;
        *(s32 *)(base + 0x20) = 0x44200000;
        *(s32 *)(base + 0x24) = 0x43E00000;
        *(s32 *)(base + 4) = *(s32 *)(obj + 0x28);
    }
    if (a >= b) {
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp6C = *(s32 *)(arg0 + 0x10);
        pt = &sp6C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp68 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x64($sp)      \n"
            :
            : "r"(&sp68), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)base = *(volatile s32 *)&sp64;
        *(f32 *)(base + 0xC) = 1.0f + func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 8) = func_0048aff0(obj + 0x60, b, a);
    } else {
        *(s8 *)(base + 3) = 0;
    }
}

// FUN_004AA460
void func_004aa460(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    void *setState;
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        func_004a8440(base, sp20);
        setState = (void *)D_00887300;
        (*(void (**)(u32, u32))setState)(1, D_00922D90[0]);
        func_003f6440(3, 0x31001);
        func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
        D_00887314[0](3, sp20, 4, D_00714368, 6);
        func_0048a0e0();
        (*(void (**)(u32, u32))setState)(1, 0);
        func_003f6440(3, sp12C);
    }
}
// FUN_004AA560
u8 *func_004aa560(u8 *arg0) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x64)) {
        func_0046d730(D_00714380, 0x218);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x21E);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        func_004a8da0(base, item);
        *(f32 *)(item + 4) = fGpffff80f8;
    }
    return alloc;
}

// FUN_004AA660
void func_004aa660(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004AA690
void func_004aa690(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x1C) = 0x43A00000;
            *(s32 *)(base + 0x20) = 0x43600000;
            *(f32 *)(base + 0x24) = f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(f32 *)(base + 0x24) = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x1C) = vec[0];
            *(f32 *)(base + 0x20) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x18) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a8f90(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}

// FUN_004AA890
void func_004aa890(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        if (!(count <= 0x64)) {
            func_0046d730(D_00714380, 0x269);
        }
        for (i = 0; i < count; i++) {
            if (*(s32 *)list == 0 && *(u8 *)(list + 0xF) > 0) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004AA960
void func_004aa960(u8 *arg0) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    u8 *obj;
    u8 *base;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (b == 0) {
        *(s32 *)(base + 8) = 0;
        *(s32 *)(base + 0xC) = 0;
        *(s32 *)(base + 0x10) = 0x44200000;
        *(s32 *)(base + 0x14) = 0x43E00000;
        *(s32 *)(base + 4) = *(s32 *)(obj + 0x28);
    }
    if (a >= b) {
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp3C = *(s32 *)(arg0 + 0x10);
        pt = &sp3C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp38 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x34($sp)      \n"
            :
            : "r"(&sp38), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)base = *(volatile s32 *)&sp34;
    } else {
        *(s8 *)(base + 3) = 0;
    }
}
// FUN_004AAA90
void func_004aaa90(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        func_004a86c0(base, sp20);
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31001);
        D_00887314[0](3, sp20, 4, D_00714368, 6);
        func_003f6440(3, sp12C);
    }
}

// FUN_004AAB50
void func_004aab50(u8 *arg0) {
    f32 vec[4];
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(f32 *)(base + 4) = 320.0f;
            *(f32 *)(base + 8) = 224.0f;
            *(f32 *)(base + 0x14) = 320.0f - f;
            *(f32 *)(base + 0x18) = 224.0f - f;
            *(f32 *)(base + 0x1C) = 320.0f + f;
            *(f32 *)(base + 0x20) = 224.0f + f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            g = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 4) = vec[0];
            *(f32 *)(base + 8) = vec[1];
            *(f32 *)(base + 0x14) = vec[0] - g;
            *(f32 *)(base + 0x18) = vec[1] - g;
            *(f32 *)(base + 0x1C) = vec[0] + g;
            *(f32 *)(base + 0x20) = vec[1] + g;
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp7C = *(s32 *)(arg0 + 0x10);
        pt = &sp7C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp78 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x74($sp)      \n"
            :
            : "r"(&sp78), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp74;
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
    } else {
        *(s8 *)(base + 0xF) = 0;
    }
}
// FUN_004AAD30
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004aad30);

/* measured: retail keeps arg0/$s5, arg1/$s4, hoists 0x60 into $s1 (temp_4
   via addu); mwcc b210 recompiled from equivalent C hoists the 0xFFFF mask
   into $s1/$s4 instead and rotates the saved registers (arg0 -> $s2, size/
   alloc swapped), nd 25 (14 rows). Tried 5 declaration orders, u16/u32 arg0,
   fn-pointer and mask temps, both assert cast forms - identical result.
   Saved-register rotation floor. */
// FUN_004AAEE0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004aaee0);
/* measured: same arg-materialisation floor as func_004ab5a0: retail emits
   `daddu $a0,$v0` before `lhu $a1,0x1c($s1)` before the jal func_004ab960;
   mwcc b210 emits the load first, nd 4 (2 rows). Same spellings tried,
   identical result. */
// FUN_004AB060
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004ab060);

/* measured: same arg-materialisation floor as func_004ab060: retail emits
   `daddu $a0,$v0` before `lhu $a1,0x1c($s1)` before the jal func_004ab960;
   mwcc b210 emits the load first, nd 4 (2 rows). Same 8 source spellings
   tried, identical result. */
// FUN_004AB5A0
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004ab5a0);

// FUN_004AB140
void func_004ab140(void *param_1) {
    if (*(void **)((char *)param_1 + 0x20) != 0) {
        ((void (*)(void *))(*(u32 *)(D_00714394 + *(s32 *)((char *)param_1 + 0x18) * 24)))(*(void **)((char *)param_1 + 0x20));
    }
    if (*(void **)((char *)param_1 + 0x28) != 0) {
        func_004aba70(*(void **)((char *)param_1 + 0x28));
    }
    (*jtbl_008873EC)(param_1);
}

// FUN_004AB1C0
u8 *func_004ab1c0(void *param_1) {
    u8 *tmp;

    tmp = func_004aaee0(*(u16 *)((char *)param_1 + 0x18), *(s32 *)((char *)param_1 + 0x24));
    if ((*(void **)((char *)param_1 + 0x28) != 0) && (*(s8 *)(D_007143A0 + *(s32 *)(tmp + 0x18) * 24) != 0)) {
        *(s32 *)(tmp + 0x28) = (s32)func_004abb00(*(void **)((char *)param_1 + 0x28));
    }
    return tmp;
}

// FUN_004AB250
void func_004ab250(void *param_1) {
    *(s32 *)((char *)param_1 + 0x1C) = 0;
}

// FUN_004AB260
void func_004ab260(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_00714398 + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x1C) += 1;
}

// FUN_004AB2C0
void func_004ab2c0(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071439C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
}

// FUN_004AB300
void func_004ab300(u8 *param_1) {
    u8 *p;
    if (*(s32 *)(param_1 + 0x1C) > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB360
void func_004ab360(u8 *param_1) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(*(u32 *)(D_00714398 + *(s32 *)(param_1 + 0x18) * 24)))(param_1);
    count = *(s32 *)(param_1 + 0x1C) + 1;
    *(s32 *)(param_1 + 0x1C) = count;
    if (count > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
typedef signed __int128 s128;

// FUN_004AB3F0
s128 func_004ab3f0(void *param_1, const void *param_2) {
    s128 temp = *(const s128 *)param_2;
    *(s128 *)param_1 = temp;
    return temp;
}

// FUN_004AB400
void func_004ab400(void *param_1, s32 param_2) {
    *(s32 *)((char *)param_1 + 0x10) = param_2;
}

// FUN_004AB410
void func_004ab410(void *param_1, f32 param_2) {
    *(f32 *)((char *)param_1 + 0x14) = param_2;
}

/* measured: identical constant-hoist floor to func_004aaee0: retail hoists
   0x60 into $s1 for the data addu and re-masks arg0 with a fresh andi; mwcc
   hoists 0xFFFF instead, nd 6 (3 rows). Same spellings tried, identical
   result. */
// FUN_004AB420
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004ab420);

// FUN_004AB680
void func_004ab680(void *param_1) {
    if (*(void **)((char *)param_1 + 0x20) != 0) {
        ((void (*)(void *))(*(u32 *)(D_00714464 + *(s32 *)((char *)param_1 + 0x18) * 24)))(*(void **)((char *)param_1 + 0x20));
    }
    if (*(void **)((char *)param_1 + 0x28) != 0) {
        func_004aba70(*(void **)((char *)param_1 + 0x28));
    }
    (*jtbl_008873EC)(param_1);
}

// FUN_004AB700
u8 *func_004ab700(void *param_1) {
    u8 *tmp;

    tmp = func_004ab420(*(u16 *)((char *)param_1 + 0x18), *(s32 *)((char *)param_1 + 0x24));
    if ((*(void **)((char *)param_1 + 0x28) != 0) && (*(s8 *)(D_00714470 + *(s32 *)(tmp + 0x18) * 24) != 0)) {
        *(s32 *)(tmp + 0x28) = (s32)func_004abb00(*(void **)((char *)param_1 + 0x28));
    }
    return tmp;
}

// FUN_004AB790
void func_004ab790(void *param_1) {
    *(s32 *)((char *)param_1 + 0x1C) = 0;
}

// FUN_004AB7A0
void func_004ab7a0(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_00714468 + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x1C) += 1;
}

// FUN_004AB800
void func_004ab800(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071446C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
}

// FUN_004AB840
void func_004ab840(u8 *param_1) {
    u8 *p;
    if (*(s32 *)(param_1 + 0x1C) > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB8A0
void func_004ab8a0(u8 *param_1) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(*(u32 *)(D_00714468 + *(s32 *)(param_1 + 0x18) * 24)))(param_1);
    count = *(s32 *)(param_1 + 0x1C) + 1;
    *(s32 *)(param_1 + 0x1C) = count;
    if (count > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB930
s128 func_004ab930(void *param_1, const void *param_2) {
    s128 temp = *(const s128 *)param_2;
    *(s128 *)param_1 = temp;
    return temp;
}

// FUN_004AB940
void func_004ab940(void *param_1, s32 param_2) {
    *(s32 *)((char *)param_1 + 0x10) = param_2;
}

// FUN_004AB950
void func_004ab950(void *param_1, f32 param_2) {
    *(f32 *)((char *)param_1 + 0x14) = param_2;
}

// FUN_004AB960
u8 *func_004ab960(u16 *arg0, s32 arg1) {
    u8 *tmp;
    s32 t;

    func_0044ea90(D_00714450, 0x171);
    tmp = (u8 *)(*jtbl_008873E8)(0xC, 0x40000);
    func_0043f9c8(tmp, 0, 0xC);
    if (tmp == 0) {
        func_0046d730(D_00714380, 0x7B0);
    }
    t = arg1 & 0xFFFF;
    *(s32 *)(tmp + 0) = t;
    *(s32 *)(tmp + 4) = 1;
    switch (t) {
    case 1:
        *(s32 *)(tmp + 8) = func_00481390(arg0);
        break;
    case 4:
        *(s32 *)(tmp + 8) = func_00481300(*arg0);
        break;
    default:
        func_0046d730(D_00714380, 0x7BC);
        break;
    }
    return tmp;
}

// FUN_004ABA70
void func_004aba70(void *param_1) {
    s32 n;

    if (*(s32 *)((char *)param_1 + 4) == 0) {
        func_0046d730(D_00714380, 0x7C5);
    }
    n = *(s32 *)((char *)param_1 + 4) - 1;
    *(s32 *)((char *)param_1 + 4) = n;
    if (n == 0) {
        if (*(s32 *)((char *)param_1 + 0) != 4) {
            func_003ef3a0(*(void **)((char *)param_1 + 8));
        }
        (*jtbl_008873EC)(param_1);
    }
}

// FUN_004ABB00
void *func_004abb00(BlurRefObj *param_1) {
    if (param_1->f4 == 0) {
        func_0046d730(D_00714380, 0x7D7);
    }
    param_1->f4 += 1;
    return param_1;
}

