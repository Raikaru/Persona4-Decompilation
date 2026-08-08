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
extern void func_00489f40(void *arg0, void *arg1);
extern void (*jtbl_008873EC[])(void *);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
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
extern s32 func_00494710(void *arg0, u32 arg1);
extern void func_00494740(void *arg0, u32 arg1, void *arg2, f32 arg3);
extern void func_004940d0(void *arg0, u32 arg1, void *arg2);
extern void func_004946f0(void *arg0, u32 arg1);
extern void func_004946d0(void *arg0, u32 arg1);
extern void func_00494f90(void *arg0);
extern void func_00494ff0(void *arg0);
extern u8 *func_00483e10(u16 arg0, u16 arg1, void *arg2, s32 arg3, s32 arg4);
extern u8 *func_00483c40(u16 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern void func_00487650(void *arg0, void *arg1);
extern void func_004877b0(void *arg0, void *arg1);
extern void func_00487860(void *arg0, void *arg1);
extern void func_00487710(void *arg0, void *arg1);
extern void func_004878c0(void *arg0, void *arg1);
extern void func_00487a30(void *arg0, void *arg1);
extern void func_00487ba0(void *arg0, void *arg1);
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
    func_0043f9c8(w, 0, 0x38);
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
    func_0043f9c8(t2, 0, 0x38);
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

/* measured: masked selector residual remains nd 3, object 376B/384B:
   retail keeps arg1&0xFFFF in $a2 across sltiu and sll, while b210 uses
   $v0. Tried u16/s32/u32 parameter widths, in-place parameter masks before
   and after initialization, no-cast switches, saved-pointer/arg2 reuse,
   selector locals, and explicit assignments; all stayed nd 3 or worsened.
   Committed at nd 3. */
// FUN_00493080 NONMATCHING
#ifdef NON_MATCHING
void func_00493080(u8 *arg0, u16 arg1, s32 *arg2) {
    u8 *o;

    if (*(u8 **)(arg0 + 0x2C) == NULL) {
        o = func_00486a50(*(s32 *)arg0);
        *(u8 **)(arg0 + 0x2C) = o;
        *(s32 *)(o + 0x4C) = *(s32 *)(arg0 + 0x30);
    }
    switch ((u32)arg1) {
    case 1:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_004877b0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 2:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487860(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 4:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487710(*(void **)(arg0 + 0x2C), *(void **)arg2);
        break;
    case 5:
        func_004878c0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 6:
        func_00487a30(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 7:
        func_00487650(*(void **)(arg0 + 0x2C), *(void **)arg0);
        func_00487ba0(*(void **)(arg0 + 0x2C), (void *)arg2);
        break;
    case 0:
    case 3:
    default:
        func_0046d730(D_00713E30, 0xA8);
        break;
    }
    *(s16 *)(*(u8 **)(arg0 + 0x2C) + 0xC) = (s16)arg1;
}
#else
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493080);
#endif
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
    func_0043f9c8(t2, 0, 0x38);
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
    func_0043f9c8(t2, 0, 0x38);
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

/* measured: retail stores the new object into field_2C, loads field_30,
   stores it to +0x4C via the call-result register, then emits a dead
   `move $v0,$v0` (store-forwarding residue) before the next field_2C load;
   mwcc b210 either CSEs the pointer reload away entirely (temp spelling,
   nd 25, missing word) or materializes it as `move $v0,$v0` one slot early
   (chained `*(u8**)(arg0+0x2C)+0x4C` spelling, nd 2 — the sw/move pair
   swapped). #pragma schedule on / optimization_level 3 both worsen it
   (hoisted loads + beql if-conversion). Dead-copy placement floor. */
// FUN_004936D0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004936d0);

// FUN_00493790
void func_00493790(u8 *arg0, u16 arg1, u8 *arg2)
{
    u8 *v;

    func_0043f810(arg0 + 0xC, arg2, 0x1C);
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

// FUN_004938E0
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_004938e0);

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
        func_00489f40((void *)temp_4, (void *)arg1);
    }
}

// FUN_00493E30
void func_00493e30(u8 *arg0, f32 fparg0)
{
    *(f32 *)(arg0 + 8) = fparg0;
    func_00492e30((u16 *)*(u32 *)(arg0 + 0x30));
}

/* measured: retail allocates obj->$s0, t17->$s1, t18->$s2 and runs the
   palette loop with var5 in $a1, 0xFF/0xFE constants hoisted before the
   loop, dst pointers in $t2/$a1; mwcc b210 colors t17->$s0 in every decl
   order tried ([t17,t18,obj] nd 93, [obj,t17,t18] nd 96, [t18,t17,obj]
   nd 93, [t17,obj,t18] nd 96), keeps 0xFF materialization inside the loop,
   and grows the object to 628B vs a 624B window. s-reg + temp-color and
   constant-hoisting floor; struct-field byte copies via iGpffffbb64 all
   match. */
// FUN_00493E60
INCLUDE_ASM("asm/nonmatchings/effPolygonTrack", func_00493e60);
