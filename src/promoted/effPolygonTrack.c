/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonTrack.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void func_00486e10(void *arg0);
extern void func_00494680(void *arg0);
extern void func_00492cd0(u8 *arg0);
extern void func_00492d00(int arg0);
extern void func_00492dd0(int arg0);
extern void func_00492e10(int arg0);
extern void func_00492e30(u16 *arg0);
extern void func_00489f40(void *arg0, u32 color);
extern void (*jtbl_008873EC[])(void *);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, s32 line);
extern void memset(void *dst, s32 value, u32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern char D_00713E20[];
extern char D_00713E30[];
extern u8 *func_00484490(u8 *obj);
extern s32 func_004844d0(u8 *obj);
extern void *func_00486a50(s32 arg0);
extern u8 *func_00483270(u8 *arg0);
extern void func_00487160(void *arg0, void *arg1);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern void func_004941f0(void *arg0, void *arg1);
extern u8 *func_00493e60(u16 arg0, u16 arg1);
extern void func_004938e0(u8 *arg0);
extern void func_004936d0(u8 *arg0, u8 *arg1);
extern void func_00493790(u8 *arg0, u16 arg1, u8 *arg2);
extern void func_00493820(u8 *arg0, u16 arg1, u8 *arg2);
extern void func_00493080(u8 *arg0, u16 arg1, s32 *arg2);
extern void func_00492df0(void *arg0, u32 *arg1);
extern void func_00492db0(void *arg0, u32 *arg1);
extern void func_00484350(void *arg0, void *arg1, void *arg2, f32 arg3);
extern void func_00487fb0(void *arg0, f32 arg1);
extern void func_00495090(void *arg0, u32 arg1);
extern void func_00492d10(void *arg0);
extern s32 func_00494710(void *arg0, u16 arg1);
extern void func_00494740(void *arg0, u16 arg1, void *arg2, f32 arg3);
extern void func_004940d0(void *arg0, u16 arg1, void *arg2);
extern void func_004946f0(void *arg0, u16 arg1);
extern void func_004946d0(void *arg0, u16 arg1);
extern void func_00494f90(void *arg0);
extern void func_00494ff0(void *arg0);
extern u8 *func_00483e10(u16 arg0, u16 arg1, void *arg2, s32 arg3, s32 arg4);
extern u8 *func_00483c40(u16 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern void func_00487650(u8 *arg0, s32 arg1, s32 arg2);
extern void func_004877b0(u8 *arg0, s32 arg1);
extern void func_00487860(u8 *arg0, s32 *arg1);
extern void func_00487710(u8 *arg0, s32 arg1);
extern void func_004878c0(u8 *arg0, void *arg1);
extern void func_00487a30(u8 *arg0, void *arg1);
extern void func_00487ba0(u8 *arg0, s32 *arg1);
extern u8 D_00764C54[4];
extern f32 D_00761134;
extern u8 D_00922D80[];
extern u8 D_00713310[];
extern u8 D_00713420[];


typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern LineNovaColor iGpffffbb64;



// FUN_00492E70
void *func_00492e70(u32 arg0)
{
    u8 *w;

    func_0044ea90(&D_00713E20, 0x171);
    w = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    memset(w, 0, 0x38);
    if (w == NULL) {
        func_0046d730(&D_00713E30, 0x32);
    }
    *(u32 *)(w + 0) = arg0;
    *(u32 *)(w + 4) = -1;
    *(f32 *)(w + 8) = 1.0f;
    *(u16 *)(w + 0x34) = 1;
    return w;
}

/* measured: arg1's u16 load must be emitted before the $a0 move (retail's
   pre-jal order). On the identical call pattern in FUN_00493200 the plain
   read measures nd 5 (lhu/move swapped at both sites) and a shared named
   local nd 62 (spills into $s2); the volatile-anchored read applied here
   first try, nd 0. */
// FUN_00492F20
u8 *func_00492f20(u8 *arg0)
{
    u8 *t;
    u32 var;
    u8 *t2;

    t = func_00484490(arg0);
    if (t == NULL) {
        func_0046d730(D_00713E30, 0x61);
    }
    if (*(u32 *)(t + 0x3C) == 0) {
        var = (u32)(*(s32 *)(t + 0xD4) * *(s32 *)(t + 0x40));
    } else {
        var = (u32)(*(s32 *)(t + 0x3C) * *(s32 *)(t + 0x40));
    }
    if (var > 0x64) {
        var = 0x64;
    }
    func_0044ea90(&D_00713E20, 0x171);
    t2 = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    memset(t2, 0, 0x38);
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x32);
    }
    *(u32 *)(t2 + 0) = var;
    *(u32 *)(t2 + 4) = -1;
    *(f32 *)(t2 + 8) = 1.0f;
    *(u16 *)(t2 + 0x34) = 1;
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x63);
    }
    {
        u16 w = *(volatile u16 *)(arg0 + 0xC);

        func_00493790(t2, w, t);
    }
    func_00493820(t2, *(volatile u16 *)(arg0 + 0xC), t + 0x1C);
    return t2;
}

/* measured: correcting the direct effect-helper declarations and passing the
   selector as func_00487650's third argument keeps arg1&0xFFFF in $a2 across
   the dispatch; object 376B/384B, normalized_diff 0 (jump-table relocations
   are the only fndiff rows). */
// FUN_00493080
void func_00493080(u8 *arg0, u16 arg1, s32 *arg2) {
    u8 *o;

    if (*(u8 **)(arg0 + 0x2C) == NULL) {
        o = func_00486a50(*(s32 *)arg0);
        *(u8 **)(arg0 + 0x2C) = o;
        *(s32 *)(o + 0x4C) = *(s32 *)(arg0 + 0x30);
    }
    switch ((u32)arg1) {
    case 1:
        func_00487650(*(u8 **)(arg0 + 0x2C), *(s32 *)arg0, (s32)arg1);
        func_004877b0(*(u8 **)(arg0 + 0x2C), (s32)arg2);
        break;
    case 2:
        func_00487650(*(u8 **)(arg0 + 0x2C), *(s32 *)arg0, (s32)arg1);
        func_00487860(*(u8 **)(arg0 + 0x2C), arg2);
        break;
    case 4:
        func_00487650(*(u8 **)(arg0 + 0x2C), *(s32 *)arg0, (s32)arg1);
        func_00487710(*(u8 **)(arg0 + 0x2C), *(s32 *)arg2);
        break;
    case 5:
        func_004878c0(*(u8 **)(arg0 + 0x2C), arg2);
        break;
    case 6:
        func_00487a30(*(u8 **)(arg0 + 0x2C), arg2);
        break;
    case 7:
        func_00487650(*(u8 **)(arg0 + 0x2C), *(s32 *)arg0, (s32)arg1);
        func_00487ba0(*(u8 **)(arg0 + 0x2C), arg2);
        break;
    case 0:
    case 3:
    default:
        func_0046d730(D_00713E30, 0xA8);
        break;
    }
    *(s16 *)(*(u8 **)(arg0 + 0x2C) + 0xC) = (s16)arg1;
}
/* measured: same volatile-anchored arg1 read as FUN_00492F20; plain reads
   swap the lhu/move order at both call sites (nd 5), local spills (nd 62). */
// FUN_00493200
u8 *func_00493200(u8 *arg0)
{
    u8 *t;
    u8 *p;
    u32 var;
    u8 *t2;

    t = func_00484490(arg0);
    if (t == NULL) {
        func_0046d730(D_00713E30, 0x61);
    }
    p = t + 0x1C;
    if (*(u32 *)(t + 0x3C) == 0) {
        var = (u32)(*(s32 *)(p + 0xB8) * *(s32 *)(p + 0x24));
    } else {
        var = (u32)(*(s32 *)(t + 0x3C) * *(s32 *)(p + 0x24));
    }
    if (var > 0x64) {
        var = 0x64;
    }
    t2 = func_00492e70(var);
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x63);
    }
    {
        u16 w = *(volatile u16 *)(arg0 + 0xC);

        func_00493790(t2, w, t);
    }
    func_00493820(t2, *(volatile u16 *)(arg0 + 0xC), t + 0x1C);
    {
        s32 *r = (s32 *)func_004844d0(arg0);

        if (r != NULL) {
            func_00493080(t2, *(u16 *)(arg0 + 0x1C), r);
        }
    }
    return t2;
}

// FUN_00493320
void func_00493320(u8 *arg0)
{
    u32 temp_4;
    u32 temp_4_2;
    u8 *temp_4_3;

    temp_4 = *(u32 *)(arg0 + 0x2C);
    if (temp_4 != 0) {
        func_00486e10((void *)temp_4);
    }
    temp_4_2 = *(u32 *)(arg0 + 0x28);
    if (temp_4_2 != 0) {
        func_00494680((void *)temp_4_2);
    }
    temp_4_3 = *(u8 **)(arg0 + 0x30);
    if (temp_4_3 != NULL) {
        func_00492cd0(temp_4_3);
    }
    jtbl_008873EC[0](arg0);
}
/* measured: same volatile-anchored arg1 read as FUN_00492F20 (see its
   note); plain reads swap the lhu/move order at both call sites. */
// FUN_004933A0
u8 *func_004933a0(u8 *arg0)
{
    u8 *t17;
    u32 var;
    u8 *t2;

    if (*(u8 **)(arg0 + 0x30) == NULL) {
        func_0046d730(D_00713E30, 0xE6);
    }
    t17 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x24);
    if (t17 == NULL) {
        func_0046d730(D_00713E30, 0xE8);
    }
    if (*(u32 *)(t17 + 0x20) == 0) {
        var = (u32)(*(s32 *)(t17 + 0xB8) * *(s32 *)(t17 + 0x24));
    } else {
        var = (u32)(*(s32 *)(t17 + 0x20) * *(s32 *)(t17 + 0x24));
    }
    if (var > 0x64) {
        var = 0x64;
    }
    func_0044ea90(&D_00713E20, 0x171);
    t2 = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    memset(t2, 0, 0x38);
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x32);
    }
    *(u32 *)(t2 + 0) = var;
    *(u32 *)(t2 + 4) = -1;
    *(f32 *)(t2 + 8) = 1.0f;
    *(u16 *)(t2 + 0x34) = 1;
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0xEA);
    }
    {
        u16 w = *(volatile u16 *)(*(u8 **)(arg0 + 0x30) + 0);

        func_00493790(t2, w, arg0 + 0xC);
    }
    func_00493820(t2, *(volatile u16 *)(*(u8 **)(arg0 + 0x30) + 0), t17);
    return t2;
}

/* measured: same volatile-anchored arg1 read as FUN_00492F20 (see its
   note); plain reads swap the lhu/move order at both call sites. */
// FUN_00493530
u8 *func_00493530(u8 *arg0)
{
    u8 *t17;
    u32 var;
    u8 *t2;

    if (*(u8 **)(arg0 + 0x30) == NULL) {
        func_0046d730(D_00713E30, 0xFE);
    }
    t17 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x24);
    if (t17 == NULL) {
        func_0046d730(D_00713E30, 0x100);
    }
    if (*(u32 *)(t17 + 0x20) == 0) {
        var = (u32)(*(s32 *)(t17 + 0xB8) * *(s32 *)(t17 + 0x24));
    } else {
        var = (u32)(*(s32 *)(t17 + 0x20) * *(s32 *)(t17 + 0x24));
    }
    if (var > 0x64) {
        var = 0x64;
    }
    func_0044ea90(&D_00713E20, 0x171);
    t2 = (u8 *)(*jtbl_008873E8)(0x38, 0x40000);
    memset(t2, 0, 0x38);
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x32);
    }
    *(u32 *)(t2 + 0) = var;
    *(u32 *)(t2 + 4) = -1;
    *(f32 *)(t2 + 8) = 1.0f;
    *(u16 *)(t2 + 0x34) = 1;
    if (t2 == NULL) {
        func_0046d730(D_00713E30, 0x102);
    }
    {
        u16 w = *(volatile u16 *)(*(u8 **)(arg0 + 0x30) + 0);

        func_00493790(t2, w, arg0 + 0xC);
    }
    func_00493820(t2, *(volatile u16 *)(*(u8 **)(arg0 + 0x30) + 0), t17);
    func_004936d0(t2, arg0);
    return t2;
}

// FUN_004936D0
void func_004936d0(u8 *arg0, u8 *arg1)
{
    u8 *v;

    if (*(u32 *)(arg1 + 0x2C) == 0) {
        func_0046d730(D_00713E30, 0x115);
    }
    if (*(u32 *)(arg0 + 0x2C) == 0) {
        v = func_00486a50(*(s32 *)arg0);
        *(u8 **)(arg0 + 0x2C) = v;
        *(u32 *)(*(u8 **)(arg0 + 0x2C) + 0x4C) =
            *(u32 *)(arg0 + 0x30);
    }
    if (*(u32 *)(*(u8 **)(arg1 + 0x2C) + 0x50) != 0) {
        v = func_00483270(*(u8 **)(*(u8 **)(arg1 + 0x2C) + 0x50));
        *(u8 **)(*(u8 **)(arg0 + 0x2C) + 0x50) = v;
    }
    func_00487160(*(u8 **)(arg0 + 0x2C), *(u8 **)(arg1 + 0x2C));
    *(u16 *)(*(u8 **)(arg0 + 0x2C) + 0xC) =
        *(u16 *)(*(u8 **)(arg1 + 0x2C) + 0xC);
}

// FUN_00493790
void func_00493790(u8 *arg0, u16 arg1, u8 *arg2)
{
    u8 *v;

    memcpy(arg0 + 0xC, arg2, 0x1C);
    if (*(u32 *)(arg0 + 0) != 0) {
        if (*(u32 *)(arg0 + 0x28) != 0) {
            func_00494680((void *)*(u32 *)(arg0 + 0x28));
        }
        v = func_00493e60(*(u16 *)(arg0 + 0), *(u16 *)arg2);
        *(u8 **)(arg0 + 0x28) = v;
        func_004941f0(v, arg2 + 8);
    }
}

// FUN_00493820
void func_00493820(u8 *arg0, u16 arg1, u8 *arg2)
{
    if (*(u32 *)(arg0 + 0x30) != 0) {
        func_00492cd0((u8 *)*(u32 *)(arg0 + 0x30));
    }
    if (*(u32 *)(arg2 + 0xC0) != 0) {
        func_0046d730(&D_00713E30, 0x14E);
    }
    *(u32 *)(arg0 + 0x30) = (u32)func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
}

// FUN_004938B0
void func_004938b0(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x30);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

/* MATCHED.  Three shapes carried it.  `opt_common_subs off` is required: with
   it on, b210 hoists the `andi $a1, $s2, 0xffff` index mask into a saved
   register and moves it to $a1 at each of the six call sites, which costs an
   extra saved register and 0x10 of frame; retail rematerialises the mask at
   every call.  Narrowing the five per-index callees above to `u16 arg1` is
   what makes the mask a parameter promotion rather than a common
   subexpression, and it also removes the double `lwc1 $f20` that
   `opt_common_subs off` alone introduced (152 words -> 98 with exact 171/171
   instruction counts).  The last four words were the `mode == -1 ||
   mode == 0` test: b210 folds it to the range trick `addiu $v0, $v1, 1;
   sltiu $at, $v0, 2; beqz $at`, while retail keeps two explicit compares
   (`addiu $v0, $zero, -1; beq; nop; bnez`), which only the goto form
   reproduces - `opt_rebuildconditionals off` does not.  The COP2 colour
   unpack follows the established idiom in src/Graphics/Effect/effBlurFilter.c;
   the `sw $2, 0x90($sp)` slot and its volatile reload are part of it. */
// FUN_004938E0
void func_004938e0(u8 *arg0)
{
    extern f32 fGpffff8044;
    extern void func_00487c30(void *arg0, f32 arg1);
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    f32 sp80[3];
    u8 sp70[16] __attribute__((aligned(16)));
    s32 *pt;
    f32 scale;
    u8 *track;
    u8 *entry;
    s32 i;
    u8 *owner;
    s32 count;
    s32 mode;

    if (*(s32 *)arg0 == 0) {
        return;
    }
    func_00492d10(*(void **)(arg0 + 0x30));
    track = *(u8 **)(arg0 + 0x30);
    sp98 = *(s32 *)(arg0 + 4);
    pt = &sp98;
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
        :
        : "r"(pt), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(sp70) : "$vf10", "memory");
    entry = *(u8 **)(track + 0x18);
    count = *(s32 *)arg0;
    owner = *(u8 **)(arg0 + 0x28);
    func_00494f90(owner);
    for (i = 0; i < count; i++, entry += 0x20) {
        if (func_00494710(owner, i) != 0) {
            continue;
        }
        mode = *(s32 *)(entry + 0x10);
        if (mode == -2) {
            func_00494740(owner, i, D_00922D80, 0.0f);
            func_004940d0(owner, i, &iGpffffbb64);
            func_004946f0(owner, i);
            continue;
        }
        if (mode == -1) {
            goto clear_entry;
        }
        if (mode != 0) {
            goto draw_entry;
        }
clear_entry:
        func_00494740(owner, i, D_00922D80, 0.0f);
        func_004940d0(owner, i, &iGpffffbb64);
        func_004946d0(owner, i);
        continue;
draw_entry:
        sp80[0] = *(f32 *)(entry + 0);
        sp80[1] = *(f32 *)(entry + 4);
        sp80[2] = *(f32 *)(entry + 8);
        func_00494740(owner, i, sp80, *(f32 *)(entry + 0x18));
        sp94 = *(s32 *)(entry + 0x14);
        pt = &sp94;
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
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "memory");
        __asm__ volatile(
            "lqc2 $vf11, 0(%0)     \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x90($sp)      \n"
            :
            : "r"(sp70)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        /* measured: this volatile read is the COP2 block's OUTPUT PATH, not a
           reload hack on ordinary memory.  The asm above ends in
           `sw $2, 0x90($sp)`, a hard-coded frame offset the compiler cannot
           associate with `sp90`; because `sp90` is a local whose address is
           never taken, b210 correctly concludes no asm can have touched it and
           the "memory" clobber does not reach it, so a plain read is folded
           away.  Three legal alternatives were measured and each LOSES the
           match (19 -> 18 MATCH, 1 MISMATCH in this file): a plain
           `sp9C = sp90;`, declaring the slot as an asm output with
           `"=m"(sp90)` and `sw $2, %0`, and taking the address into a local
           `s32 *slotOut = &sp90;` so the clobber applies.  The cast stays. */
        sp9C = *(volatile s32 *)&sp90;
        func_004940d0(owner, i, &sp9C);
    }
    func_00494ff0(owner);
    if (*(u8 **)(arg0 + 0x2C) == NULL) {
        return;
    }
    if (*(u32 *)(*(u8 **)(arg0 + 0x30) + 0x10) < *(u32 *)(arg0 + 0x10)) {
        return;
    }
    func_00489f40(*(void **)(arg0 + 0x2C), *(u32 *)(arg0 + 4));
    func_00487c30(*(void **)(arg0 + 0x2C), *(f32 *)(arg0 + 0x24) / 10.0f);
}
// FUN_00493B90
void func_00493b90(u8 *arg0)
{
    if (*(u32 *)(arg0 + 0) != 0) {
        s32 n = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x10);

        if (n > 1) {
            u8 *t17 = *(u8 **)(arg0 + 0x28);
            u8 *t16 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x20);

            if (*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xC) & 1) {
                u32 sp50[4];
                u32 sp40[4];

                func_00492df0(*(u8 **)(arg0 + 0x30), sp40);
                func_00492db0(*(u8 **)(arg0 + 0x30), sp50);
                func_00484350((void *)*(u32 *)(t17 + 0x10), sp50, sp40, 1.0f);
                func_00484350((void *)*(u32 *)(t17 + 0x14), sp50, sp40, 1.0f);
            }
            if (*(u32 *)(arg0 + 0x2C) != 0) {
                func_00487fb0(*(u8 **)(arg0 + 0x2C), *(f32 *)(arg0 + 0x24) / 10.0f);
            }
            func_00495090(t17, *(u16 *)(t16 + 0x54));
        }
    }
}

// FUN_00493C90
void func_00493c90(u8 *arg0)
{
    func_004938e0(arg0);
    if (*(u32 *)(arg0 + 0) != 0) {
        s32 n = *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x10);

        if (n > 1) {
            u8 *t17 = *(u8 **)(arg0 + 0x28);
            u8 *t16 = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x20);

            if (*(u32 *)(*(u8 **)(arg0 + 0x30) + 0xC) & 1) {
                u32 sp50[4];
                u32 sp40[4];

                func_00492df0(*(u8 **)(arg0 + 0x30), sp40);
                func_00492db0(*(u8 **)(arg0 + 0x30), sp50);
                func_00484350((void *)*(u32 *)(t17 + 0x10), sp50, sp40, 1.0f);
                func_00484350((void *)*(u32 *)(t17 + 0x14), sp50, sp40, 1.0f);
            }
            if (*(u32 *)(arg0 + 0x2C) != 0) {
                func_00487fb0(*(u8 **)(arg0 + 0x2C), *(f32 *)(arg0 + 0x24) / 10.0f);
            }
            func_00495090(t17, *(u16 *)(t16 + 0x54));
        }
    }
}

// FUN_00493DA0
void func_00493da0(u8 *arg0)
{
    func_00492dd0(*(u32 *)(arg0 + 0x30));
}

// FUN_00493DD0
void func_00493dd0(u8 *arg0)
{
    func_00492e10(*(u32 *)(arg0 + 0x30));
}

// FUN_00493E00
void func_00493e00(u8 *arg0, u32 arg1)
{
    u32 temp_4;

    *(u32 *)(arg0 + 4) = arg1;
    temp_4 = *(u32 *)(arg0 + 0x2C);
    if (temp_4 != 0) {
        func_00489f40((void *)temp_4, arg1);
    }
}

// FUN_00493E30
void func_00493e30(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 8) = fparg0;
    func_00492e30((u16 *)*(u32 *)(arg0 + 0x30));
}

/* Measured: 620/624 bytes, 40 resolved relocations and 4 zero alignment bytes. */
#pragma push
#pragma opt_propagation off
// FUN_00493E60
u8 *func_00493e60(u16 count, u16 segments) {
    s32 size;
    u8 *track;
    u16 count16;
    u32 i;
    s32 index;
    u16 *geometry;
    u16 *ribbon;
    u16 *cap;
    u8 *ribbonEntry;
    s32 opaque;
    s32 maxAlpha;
    u8 *capEntry;

    if ((u16)segments < 2) {
        func_0046d730(&D_00713E30, 0x205);
    }
    count16 = count & 0xFFFF;
    size = (count16 * 2) + 0x1C;
    func_0044ea90(&D_00713E30, 0x20A);
    track = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (track == NULL) {
        func_0046d730(&D_00713E30, 0x20B);
    }
    memset(track, 0, size);
    *(u8 **)(track + 0x18) = track + 0x1C;
    geometry = (u16 *)func_00483e10(count, segments, (void *)D_00713310, 3, 0x48);
    *(u16 **)(track + 0x10) = geometry;
    *geometry &= 0xFFFB;
    geometry = (u16 *)func_00483c40(count, 1, 6, 8, (void *)D_00713420, 0x48);
    *(u16 **)(track + 0x14) = geometry;
    *geometry = *geometry & (u16)0xFFFB;
    i = 0;
    opaque = 0xFF;
    maxAlpha = 0xFE;
    for (; i < count16; i += 1) {
        ribbon = *(u16 **)(track + 0x10);
        if (iGpffffbb64.c3 != opaque) {
            index = (u16)i * 4;
            ribbonEntry = *(u8 **)((u8 *)ribbon + 0x54) + index;
            ribbonEntry = *(u8 **)ribbonEntry;
            *(LineNovaColor *)(ribbonEntry + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = maxAlpha;
            index = (u16)i * 4;
            ribbonEntry = *(u8 **)((u8 *)ribbon + 0x54) + index;
            ribbonEntry = *(u8 **)ribbonEntry;
            *(LineNovaColor *)(ribbonEntry + 4) = iGpffffbb64;
            iGpffffbb64.c3 = opaque;
        }
        cap = *(u16 **)(track + 0x14);
        if (iGpffffbb64.c3 != opaque) {
            capEntry = *(u8 **)((u8 *)cap + 0x54) + index;
            capEntry = *(u8 **)capEntry;
            *(LineNovaColor *)(capEntry + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = maxAlpha;
            capEntry = *(u8 **)((u8 *)cap + 0x54) + index;
            capEntry = *(u8 **)capEntry;
            *(LineNovaColor *)(capEntry + 4) = iGpffffbb64;
            iGpffffbb64.c3 = opaque;
        }
    }
    return track;
}
#pragma pop
