/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*DAT_008873EC[])(void *);
extern s32 (*DAT_008873F4[])(s32, s32, s32);

extern s32 iGpffffb4e8;
extern s32 iGpffffb260;
extern s32 iGpffffb4e4;
extern s32 iGpffffb274;
extern s32 D_00764344;
extern u8 *iGpffff9db0;
extern u8 iGpffff9f28;
extern u8 iGpffff9f29;
extern u8 iGpffff9f2a;
extern u8 iGpffff9f2b;
extern u8 iGpffff9f24;
extern s32 func_0014b870(s32 arg0, s32 arg1);
extern void func_002319c0(s32 arg0);
extern s32 func_0047ae90(s32 arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0043f810(void *arg0, void *arg1, void *arg2);
extern s32 func_001619b0(u16 arg0, u16 arg1, u16 arg2);
extern s32 func_00161a70(u16 arg0, u16 arg1, u16 arg2);
extern void func_00182310(s32 arg0);
extern s32 func_00164570(u32 arg0, s32 arg1);
extern u8 *func_00231630(u32 arg0, s32 arg1, s32 arg2);
extern u8 *func_00163990(u32 arg0, u8 *arg1, s32 arg2);
extern void func_00442088(void *dst, const void *fmt, s32 value);
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern u32 func_003b7060(void);
extern u8 *func_00145270(s32 arg0);
extern s32 func_00145540(s32 arg0, s64 arg1, u8 *arg2);
extern void func_00479940(u8 *arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4);
extern void func_0047aa30(u8 *arg0, u8 *arg1);
extern s32 func_0014c780(void);
extern void func_0017b9a0(s32 arg0, f32 arg1);
extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
extern void func_003e05d0(u8 *arg0);
extern void func_00168de0(s32 arg0, void *arg1, f32 arg2);
extern void func_00168ae0();
extern void func_0014b0c0(s32 arg0, s32 arg1);
extern void func_00168730(s32 arg0, s32 arg1);
extern void func_00168780(s32 arg0, f32 arg1);
extern s32 func_00478750(s32 arg0);
extern f32 func_00168770(s32 arg0);
extern void func_00478e70(u8 *arg0);
extern s32 func_00182220(s32 arg0, u8 *arg1, s32 arg2);
extern s32 func_002319f0(s32 arg0);
extern s32 func_0016fd00(s32 arg0);
extern s32 func_0017e890(s32 arg0, u8 *arg1, u8 *arg2);
extern void func_0017e990(s32 arg0);
extern s32 func_0017d070(s32 arg0);
extern void func_00168c00(s32 arg0);
extern f32 func_003e4180(f32 *arg0);
extern s32 func_00161630(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
extern u8 *func_00164880(s32 arg0, u32 arg1, f32 arg2);
extern u8 *func_0014cef0(s32 arg0, s32 arg1);
extern void func_0014c920(void);
extern s32 func_0014c960(s32 *arg0, s32 *arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_00145ac0(s32 arg0, s32 arg1);
extern u8 *func_00162330(void);
extern s32 func_00231580(s64 arg0);
extern u8 *func_00162680(s32 arg0, s32 arg1, s64 arg2);
extern s32 func_00109400(s64 arg0);
extern s32 func_00104c70(s64 arg0);
extern s32 func_00105ee0(s32 arg0);
extern s32 func_00155280(void);
extern void func_0014a0f0(u16 arg0, s32 arg1);
extern u16 func_00145780(u16 arg0, s32 arg1, s32 arg2);
extern void func_0047a1a0(u8 *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0047a180(void *arg0, f32 *arg1, s32 arg2);
extern s32 func_0018bb20(s32 arg0, void *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];
extern u8 D_007E8C00[];
extern u8 D_007EF9B0[];
extern u8 D_007E8BE0[];
extern u8 D_005F1500[];
extern u8 D_005F1510[];
extern u8 D_005F13C0[];
extern u8 D_005F1340[];
extern u8 D_005F12E0[];
extern u8 D_005F1520[];
extern u8 D_005F1528[];
extern u8 D_005DC920[];
extern u8 D_00756510[];
extern u8 D_005F1530[];
extern u8 D_005F1550[];
extern u8 D_005F1570[];
extern s32 D_007E8BE8;
extern u8 D_007EF9F8[];
extern u8 D_007F16F0[];
extern u8 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 D_007EFB60[];
extern u8 D_007EFB64[];
extern u8 D_007F00D8[];
extern u8 D_005F1590[];
extern u8 D_005F15B0[];
extern u8 D_005F15C0[];
extern u8 D_005F15E0[];
extern u8 D_007E80A0[];

static s32 D_007643D8;
static s32 D_007643C8[2];
static s32 D_007643C0[2];
static u8 D_00763008[4];
static u8 D_00763010[4];
static u8 *D_00762EA0;
static s32 D_00764350;
static s32 D_007643E4;
static f32 D_007613EC;

typedef struct {
    u8 b[4];
} S4;

typedef struct {
    u32 h[2];
} S8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

s32 func_00163c90(s32 arg0);
void func_00164020(u8 *arg0);
void func_00164fa0(s32 arg0);
void func_00165670(u8 *arg0, s32 arg1);
s32 func_00478140(s32 arg0, s32 arg1, s32 arg2);
s32 func_004782b0(s32 arg0);
void func_00440b68(u8 *arg0, u8 *arg1, s32 arg2);
s32 func_00454a60(u8 *arg0, s32 arg1);
s32 func_0014a200(void);
s32 func_0014a270(void);
s32 func_001668e0(u8 *arg0);
void func_0044ea90(u8 *arg0, s32 arg1);
f32 func_0044b7b0(f32 arg0);
u8 *func_0047a250(s32 arg0);
void func_0047a220(s32 arg0, u8 *arg1);
void func_004b14f0(u8 *arg0, u8 *arg1);
void func_004b13f0(u8 *arg0, u8 *arg1);
u8 *func_0047a2f0(s32 arg0);
void func_00146630(u16 arg0);
void func_0047a870(s32 arg0);
void func_004787e0(s32 arg0);
void func_00452080(s32 arg0);
s32 func_00162510(s32 arg0, s32 arg1);
s32 func_0015a160(void);
s32 func_001679d0(u8 *arg0);
u8 *func_001452b0(s32 arg0);
void func_0046d730(u8 *arg0, s32 arg1);
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2);
void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
s32 func_00161b10(u16 arg0, u16 arg1, u16 arg2);
s32 func_0015a320(void);
u8 *func_00161c80(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
s32 func_00451fc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, void (*arg5)(void *), void (*arg6)(void *), s32 arg7);





/* measured: retail schedules the three arg loads of func_0043f810 (arg3 0x118
   first, then arg1 0x734, then arg2 0x110); mwcc b210 always emits them in
   source order (0x734, 0x110, 0x118). Tried: inline loads, preloaded t-local,
   void-star / u32 / s32 prototypes, pointer casts — all give the identical nd 6
   (3 rows). Argument-evaluation-order floor. */
// FUN_00162C30
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162c30);



// FUN_00162E10
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162e10);



/* measured: nd 123 after four attempts. (1) Retail CSEs the slot count
   (lhu off 0x48+2) once but re-issues the 0x48 pointer load inside the
   average loop; mwcc b210 hoists that identical load out of the loop and
   keeps it in $a1 — tried u8-star-star/u32/u16-star-star load spellings,
   q-local, for/while forms, comparison order, all nd >= 122. (2) Retail's func_00231630 call
   reuses the loop-hoisted 0x750 in $5; mwcc rematerializes addiu $a1,0x750 at
   the call site even when 0x750 is a shared local. opt_loop_invariants on
   fixes the search-loop hoist (that part matches). CSE-of-loop-test-load
   floor + constant-materialization floor. */
// FUN_00163990
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00163990);



/* measured: nd 6 after four attempts; all but 2 words match. (1) Retail's
   var_5 = 3 materializes as daddiu $a1, $zero, 3; mwcc b210 emits addiu even
   with var_5 declared s64 — 64-bit-constant-load floor (cf. cmmRankUp
   func_00257820). (2) Retail loads st.a (D_005F1520, ld $v1) then st.b
   (D_005F1528, lwc1 $f0) then stores both; mwcc b210 either interleaves
   load/store (direct member assigns) or hoists the lwc1 first (temp locals,
   both orderings tried) — load-scheduling floor. The S90 struct keeps all
   three v-stores live (no DSE) and the frame/layout match. */
// FUN_00163C90
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00163c90);



// FUN_00163FC0
s32 func_00163fc0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        if (func_00163c90(i) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00164020
void func_00164020(u8 *arg0)
{
    s32 i;
    s32 t48;
    u16 *t54;

    t48 = *(s32 *)(arg0 + 0x48);
    if (t48 != 0) {
        func_002319c0(t48);
        t54 = *(u16 **)(arg0 + 0x54);
        if (t54 != NULL) {
            func_00146630(*t54);
        }
        if ((*(s32 *)(arg0 + 0x50) != 0) &&
            ((*(u16 *)(arg0 + 0x728) == 0) || (*(s32 *)(arg0 + 0x44) == 1))) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(s32 *)(arg0 + 0x50) + i * 0xC + 0x28C) |= 1;
            }
            func_0014b870(*(s32 *)(arg0 + 0x50), 0);
        }
        if (*(s32 *)(arg0 + 0x1B0) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B0));
        }
        if (*(s32 *)(arg0 + 0x734) != 0) {
            DAT_008873EC[0](*(void **)(arg0 + 0x734));
        }
        if (*(s32 *)(arg0 + 0x1B4) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B4));
        }
        if (*(s32 *)(arg0 + 0x1B8) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B8));
        }
        *(s32 *)(arg0 + 0x48) = 0;
        *(s32 *)(arg0 + 0x50) = 0;
        *(s32 *)(arg0 + 0x54) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0;
        *(s32 *)(arg0 + 0x734) = 0;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1B8) = 0;
        if (*(u16 *)(arg0 + 0x1C8) != 0) {
            iGpffffb4e8 -= 1;
        }
    }
}



// FUN_00164170
void func_00164170(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        func_00164020(D_007EF9B0 + i * 0x750);
    }
}



// FUN_001641D0
void func_001641d0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00164020(D_007E8C00 + i * 0x750);
    }
}



/* measured: nd ~128 after many attempts. (1) Loop A register rotation:
   retail keeps var_16 in $s0 (coalesced with temp_2's freed $16) and the
   D_007F16F0 slot pointer in $a0; mwcc b210 gives temp_4 the freed $16 and
   pushes var_16 to $s1, var_5 to $a0 vs retail's $a1 — every declaration
   order tried. Saved-register-rotation floor. (2) temp_21 is s64 for the
   clean andi ($18,& 0xffff) but the D_005F13C0 index wants s32 (retail
   daddu+sll); the (s64)(s16) cast pairs, s64 temp_18_3/andis, func_004787e0
   1-arg call, and the first block all match. */
// FUN_00164230
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164230);



// FUN_00164570
s32 func_00164570(u32 arg0, s32 arg1)
{
    s32 sp6C;
    s32 sp68;
    f32 var_f20;
    s32 temp_3;
    s32 var_17;
    u32 var_2;
    u8 *temp_16;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 0;
    if (D_00764344 == 1) {
        return 0;
    }
    temp_4 = iGpffff9db0;
    temp_3 = *(s32 *)temp_4;
    if ((temp_3 >= 0x28) && (temp_3 < 0x3C) && (*(s32 *)(temp_4 + 4) != 0)) {
        return 0;
    }
    if (arg1 != 0) {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0xBB8)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 2);
            var_17 += 1;
        }
    } else {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0x1770)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 1);
            var_17 += 1;
        }
        var_f20 = (f32)0xBB8;
        if (func_0014a270() == 1) {
            var_f20 = 100.0f;
        }
        while ((temp_2 = func_00164880(var_17, arg0, var_f20)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 0);
            var_17 += 1;
        }
        if ((func_00106330(0x1410) == 0) && (func_00106330(0x1411) == 0)) {
            func_0014c920();
            while (func_0014c960(&sp6C, &sp68) == 1) {
                temp_16 = func_0014cef0(sp6C, sp68);
                if (temp_16 != NULL) {
                    temp_19 = iGpffff9db0;
                    var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
                    if ((var_2 & 0xFFFF) == 0xFFFF) {
                        var_2 = 1;
                    }
                    func_00163990(var_2, temp_16, 0);
                }
            }
        }
    }
    return var_17;
}



// FUN_00164880
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164880);



// FUN_00164F40
s32 func_00164f40(void)
{
    return D_007643D8;
}



// FUN_00164F50
void func_00164f50(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00164fa0(i);
    }
}



/* measured: nd ~26 after four attempts; everything matches except retail's
   three re-issued `mult` recomputations of arg0*0x750 (temp_20_2, D_007F00D8,
   D_007EFB60 sites). mwcc b210 CSEs arg0*0x750 against the temp_17 local
   (kept in $s1 across the calls) and emits addu instead of a fresh mult, in
   every spelling tried: arg0*0x750, 0x750*arg0, (s32)&D_..+arg0*0x750
   int-cast form, (u32)arg0*0x750 (that one also grows the frame to 0x90).
   CSE-of-recomputed-multiply floor (cf. cmmMisc func_00247cb0). sp70[3]
   array, w0/w1 copy loop, and D_007EFA04-between-calls placement all match. */
// FUN_00164FA0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164fa0);



// FUN_00165270
void func_00165270(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0) {
            *(s32 *)(p + 0x50) = func_00478140(8, (u16)(*(u8 *)(p + 0x1CA) + 1), 0);
        }
    }
}



// FUN_00165300
s32 func_00165300(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0 && func_004782b0(*(s32 *)(p + 0x50)) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00165380
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165380);



// FUN_00165670
void func_00165670(u8 *arg0, s32 arg1)
{
    u8 *p = arg0;
    u8 *q;
    u8 *s;
    u8 *d;
    s32 n;
    s32 v;
    s32 i;
    v = *(u32 *)(p + 0x48) != 0 && *(u32 *)(p + 0x54) != 0;
    if (v != 0) {
        q = func_0047a2f0(*(u32 *)(p + 0x50));
        s = q;
        n = 8;
        d = p;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            n--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (n > 0);
        func_00146630(*(u16 *)(*(u32 *)(p + 0x54)));
        *(u32 *)(p + 0x54) = 0;
        if (*(u32 *)(p + 0x50) != 0) {
            func_0047a870(*(u32 *)(p + 0x50));
            func_0047a220(*(u32 *)(p + 0x50), D_00763010);
        }
        if (*(u32 *)(p + 0x50) != 0 && arg1 == 1) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u32 *)(p + 0x50) + i * 12 + 0x28C) |= 1;
            }
            func_004787e0(*(u32 *)(p + 0x50));
            *(u32 *)(p + 0x50) = 0;
        }
        if (*(u32 *)(p + 0x1B0) != 0) {
            func_00452080(*(u32 *)(p + 0x1B0));
            *(u32 *)(p + 0x1B0) = 0;
        }
        if (*(u32 *)(p + 0x1B8) != 0) {
            func_00452080(*(u32 *)(p + 0x1B8));
            *(u32 *)(p + 0x1B8) = 0;
        }
        if (*(u32 *)(p + 0x1B4) != 0) {
            func_00452080(*(u32 *)(p + 0x1B4));
            *(u32 *)(p + 0x1B4) = 0;
        }
    }
}



// FUN_001657E0
void func_001657e0(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00165670(D_007EF9B0 + i * 0x750, 0);
    }
}



// FUN_00165840
void func_00165840(s32 arg0)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00165670(D_007E8C00 + i * 0x750, arg0);
    }
}



// FUN_001658B0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001658b0);



// FUN_00165B00
void func_00165b00(void)
{
    s32 i;
    s32 j = 0;
    for (i = 0; i < 2; i++) {
        u8 *p = D_007E8BE0 + i * 16;
        if (*(s32 *)p != 0) {
            D_007643C8[j] = func_00478140(*(u16 *)(p + 4), *(u16 *)(p + 6), 0);
            func_00440b68(D_00763008, D_005F1500, 0x939);
            D_007643C0[j] = func_00454a60(D_005F13C0 + (*(s32 *)(p + 0xC) << 5), 0);
            j++;
        }
    }
}



/* measured: nd ~140 after many attempts. (1) Retail keeps var_17 in $s1 and
   temp_18/temp_2 in $s2; mwcc b210 assigns them swapped in every spelling
   tried (8 declaration orders, s32/u32 var_17, u16/s32 temp_18, single
   merged variable) — saved-register-rotation floor. (2) The D_007E8BE0 scan
   loop: opt_loop_invariants fixes the base hoist, but retail emits
   addiu $v1,$a1,8 + lw/sw 0($v1) while mwcc folds the +8 into the load and
   allocates $a2/$a1/$v1 vs retail's $a3/$a2/$a0 — 1 word + register shift.
   Everything else (while-assignment loops, mfhi modulo, sp60[3], pragma
   hoist) matches. */
// FUN_00165BE0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165be0);



/* measured: nd 5 after many attempts. Retail's four gp byte copies
   (iGpffff9f28..2b -> temp_6+4..7) load into $a1/$a0/$v1/$v0 in source order;
   mwcc b210 rotates the load/register assignment by one (t0 lands in $v0) in
   every spelling tried: u8/s32/array temps, reversed declarations, reversed
   assignment order, reversed store order, temp_3_2 field local. Only the 4
   sb rows differ (the lbu rows are reloc-masked). Caller-register-rotation
   floor. Everything else (interleaved f32/s32 prototype for func_0047a1a0,
   batched byte loads, temp_4_2 0x16C reuse, func_00145ac0 sh store) matches. */
// FUN_00165FB0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165fb0);



// FUN_001662D0
void func_001662d0(void)
{
    u32 sp6C;
    u32 t17;
    u8 *src;
    u8 *s19;
    u8 *p;
    u8 *slotp;
    s32 i;
    s32 j;
    u16 h0;
    u16 h4;
    u8 *dp;
    u8 *s;
    u8 *d;
    s32 k;

    t17 = func_0015a160();
    if (iGpffffb260 == 1) {
        return;
    }
    func_0043f9c8(D_007E80A0, 0, 0xB40);
    iGpffffb4e4 = 0;
    h0 = *(u16 *)iGpffff9db0;
    h4 = *(u16 *)(iGpffff9db0 + 4);
    s19 = (u8 *)func_00161b10(h0, h4, t17);
    if (s19 == 0) {
        return;
    }
    if (func_0015a320() == 0) {
        return;
    }
    i = 0;
    while ((src = func_00166600(s19, &sp6C, i)) != NULL) {
        h0 = *(u16 *)iGpffff9db0;
        h4 = *(u16 *)(iGpffff9db0 + 4);
        p = func_00161c80(h0, h4, t17, 2);
        if (p == NULL) {
            func_0046d730(D_005F1500, 0xA63);
        }
        slotp = NULL;
        j = 0;
        dp = D_007E80A0;
        for (; j < 8; j++) {
            if (*(s32 *)(dp + j * 0x168) == 0) {
                slotp = dp + j * 0x168;
                break;
            }
        }
        *(s32 *)slotp = 1;
        *(s32 *)(slotp + 0x160) = (s32)p;
        *(s16 *)(slotp + 0xE) = (s16)sp6C;
        d = slotp + 0x10;
        k = 0x2A;
        s = src;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            k--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (k > 0);
        func_00165fb0(slotp, src, 0x3FE - i);
        i++;
    }
}

// FUN_001664A0
void func_001664a0(void)
{
    s32 i;
    s32 k;
    s32 j = 0;
    u8 *node;
    u8 *p;
    if (D_00764350 != 1) {
        for (i = 0; i < 8; i++) {
            p = D_007E80A0 + i * 360;
            if (*(s32 *)p != 0) {
                node = func_001452b0(0x10);
                if (node == 0) {
                    return;
                }
                for (k = 0; k < *(u16 *)(p + 0xE); k++) {
                    node = *(u8 **)(node + 0x138);
                    if (node == 0) {
                        func_0046d730(D_005F1500, 0xA87);
                    }
                }
                {
                    u8 *s;
                    u8 *d;
                    s32 n;
                    d = D_007E80A0 + (u32)i * 360 + 0x10;
                    n = 0x2A;
                    s = node;
                    do {
                        u32 w0 = *(u32 *)s;
                        u32 w1 = *(u32 *)(s + 4);
                        s += 8;
                        n--;
                        *(u32 *)d = w0;
                        *(u32 *)(d + 4) = w1;
                        d += 8;
                    } while (n > 0);
                }
                func_00165fb0(D_007E80A0 + (u32)i * 360, node, 0x3FE - j);
                j++;
            }
        }
    }
}
// FUN_00166600
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2)
{
    V3 pos;
    V3 vec;
    f32 temp_f0;
    f32 var_f22;
    f32 var_f23;
    u8 *var_19;
    u8 *var_18;
    u8 *temp_3;
    s32 var_2;
    s32 var_21;
    s32 var_17;
    s32 var_16;

    var_19 = func_001452b0(0x10);
    var_18 = NULL;
    func_0015a160();
    *arg1 = 0;
    var_16 = 0;
    if (func_0014a200() == 1) {
        if (iGpffffb4e4 < (s32)arg0) {
            var_f22 = 1.1754944e-38f;
            while (var_19 != NULL) {
                pos = *(V3 *)(var_19 + 0x140);
                vec.x = pos.x - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x30);
                vec.y = pos.y - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x34);
                vec.z = pos.z - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x38);
                if (func_003e4180(&vec.x) < 500.0f) {
                    var_19 = *(u8 **)(var_19 + 0x138);
                    var_16 += 1;
                } else {
                    if (iGpffffb4e4 == 0) {
                        return var_19;
                    }
                    var_f23 = 1.1754944e-38f;
                    var_21 = 0;
                    var_17 = 0;
                    while (var_17 < 8) {
                        temp_3 = D_007E80A0 + var_17 * 0x168;
                        if (*(s32 *)temp_3 != 0) {
                            vec.x = pos.x - *(f32 *)(temp_3 + 0x150);
                            vec.y = pos.y - *(f32 *)(temp_3 + 0x154);
                            vec.z = pos.z - *(f32 *)(temp_3 + 0x158);
                            temp_f0 = func_003e4180(&vec.x);
                            if (temp_f0 < 100.0f) {
                                var_21 = 1;
                                break;
                            }
                            var_f23 += temp_f0;
                        }
                        var_17 += 1;
                    }
                    if (var_21 == 1) {
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    } else {
                        if (!(var_f23 <= var_f22)) {
                            var_f22 = var_f23;
                            *arg1 = var_16;
                            var_18 = var_19;
                        }
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    }
                }
            }
        }
    } else if (func_0014a270() == 1) {
        var_2 = 0;
        while (var_19 != NULL) {
            if (var_2 == arg2) {
                *arg1 = arg2;
                var_18 = var_19;
                break;
            }
            var_19 = *(u8 **)(var_19 + 0x138);
            var_2 += 1;
        }
    }
    return var_18;
}






// FUN_001668E0
s32 func_001668e0(u8 *arg0)
{
    s32 temp_3;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_2;
    s32 var_2_2;
    u32 temp_2;
    u32 var_17;
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }
    if (*(s32 *)(temp_16 + 8) == 1) {
        return 0;
    }
    switch (*(s32 *)temp_16) {
    case 0:
        D_007643D8 = 0;
        var_17 = *(u32 *)(temp_16 + 0xC);
        if (var_17 == -1U) {
            temp_17 = iGpffff9db0;
            var_17 = func_001619b0(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        }
        if (func_0014a270() == 1) {
            var_17 = *(u32 *)(temp_16 + 0xC);
            if (var_17 == -1U) {
                var_17 = 0xF;
            }
        }
        func_00164570(var_17, 0);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        var_17_2 = 0;
        while (var_17_2 < 0xF) {
            if (func_00163c90(var_17_2) == 0) {
                var_2 = 0;
                goto out1;
            }
            var_17_2 += 1;
        }
        var_2 = 1;
    out1:
        if (var_2 != 0) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        var_17_3 = 0;
        while (var_17_3 < 0xF) {
            if (func_00163c90(var_17_3) == 0) {
                var_2_2 = 0;
                goto out2;
            }
            var_17_3 += 1;
        }
        var_2_2 = 1;
    out2:
        if (var_2_2 != 0) {
            func_00182310(0);
            *(s32 *)temp_16 += 1;
        }
        break;
    case 3:
        temp_17 = iGpffff9db0;
        temp_2 = func_00161a70(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        if ((u32)D_007643D8 < temp_2 && func_00164570(temp_2, 1) > 0) {
            *(s32 *)temp_16 = 2;
        }
        break;
    }
    return 0;
}

// FUN_00166B10
void func_00166b10(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00166B40
s32 func_00166b40(u8 *arg0, s32 arg1)
{
    s32 r;
    if (func_0014a200() == 0 && func_0014a270() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xB93);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(arg0, D_005F1590, 0xF, 0, 0, (void (*)(void *))func_001668e0, (void (*)(void *))func_00166b10, r);
    *(s32 *)(r + 0xC) = arg1;
}



// FUN_00166C30
u32 func_00166c30(u8 *arg0)
{
    if (arg0 == 0) {
        return 1;
    } else {
        return (*(u32 *)(*(u32 *)(arg0 + 0x38)) ^ 3) < 1;
    }
}



// FUN_00166C60
void func_00166c60(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        *(s32 *)(*(u32 *)(arg0 + 0x38) + 4) = arg1;
    }
}



// FUN_00166C80
s32 func_00166c80(u8 *arg0)
{
    u8 *p;
    u8 *node;
    u8 *q;
    u8 buf1[4];
    u8 buf2[3];
    u8 buf3[3];
    s32 f;
    s32 i;
    p = *(u8 **)(arg0 + 0x38);
    func_0044b7b0(D_007613EC * (f32)(*(s32 *)(p + 8)) / 10.0f);
    q = func_0047a250(*(u32 *)(*(u32 *)(p + 4) + 0x50));
    *(S4 *)buf1 = *(S4 *)q;
    buf1[0] = 0x34;
    buf1[1] = 0x2E;
    buf1[2] = 0x61;
    *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    if (*(s32 *)(p + 8) > 10) {
        *(s32 *)(p + 8) = 0;
    }
    f = *(u8 *)(*(u32 *)(p + 4) + 0x1CA);
    if (f == 0) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        node = *(u8 **)b;
        while (node != NULL) {
            if (*(u8 **)(node + 8) != NULL) {
                func_004b14f0(*(u8 **)(node + 8), buf2);
                buf2[0] = 0xFF;
                buf2[1] = 0xFF;
                buf2[2] = 0xFF;
                func_004b13f0(*(u8 **)(node + 8), buf2);
            }
            node = *(u8 **)(node + 0x10);
        }
    } else if (f == 1) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        u8 *c = *(u8 **)b;
        u8 *d = *(u8 **)(c + 0x10);
        node = *(u8 **)(d + 0x10);
        if (*(u8 **)(node + 8) != NULL) {
            func_004b14f0(*(u8 **)(node + 8), buf3);
            buf3[0] = buf1[0];
            buf3[1] = buf1[1];
            buf3[2] = buf1[2];
            func_004b13f0(*(u8 **)(node + 8), buf3);
        }
    }
    func_0047a220(*(u32 *)(*(u32 *)(p + 4) + 0x50), buf1);
    return 0;
}



/* measured: same three defects as sibling func_00167120 (see its note): (1)
   (u8) conversions emit c.ole.s 0x46010036 vs retail 0x46000036 — 3 words,
   nLine func_0034c500 floor; (2) temp_f20 (func_0044b7b0 result) spilled to
   the stack instead of $f20 — frame 0x40 vs 0x50; (3) the four sp4C-4F byte
   copies interleave lbu/sb. The madd.s (175+70x) and msub.s (37-10x,
   255-200x) fused expressions and the 0x28 store match. */
// FUN_00166E30
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00166e30);



// FUN_00167120
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00167120);



// FUN_001673F0
void func_001673f0(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00167420
s32 func_00167420(u8 *arg0, u8 *arg1)
{
    s32 r;
    func_0044ea90(D_005F1500, 0xD36);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(arg0, D_005F15C0, 0xF, 0, 0, (void (*)(void *))*(void **)(D_005F15B0 + (*(u16 *)(arg1 + 0x1C8) << 2)), (void (*)(void *))func_001673f0, r);
    *(u8 **)(r + 4) = arg1;
    *(s32 *)(r + 0xC) = 0x28;
    *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) |= 0x80;
    if (*(u8 *)(arg1 + 0x1CA) == 1) {
        *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) &= ~0x100;
    }
}

// FUN_00167530
void func_00167530(void)
{
    memset(D_007E8020, 0, 0x40);
}





/* measured: nd ~200 after four attempts. Retail recomputes the slot pointer
   inside the if-branch (temp_2 = D_007E8C00 + var_21*0x750, fresh mult) even
   though the loop head computed the identical value into temp_17; mwcc b210
   CSEs the recomputation and reuses $17, losing 6 words (same
   CSE-of-recomputation floor as func_00164fa0; tried pointer arithmetic,
   (s32)&-int-cast spellings, temp_5/temp_5_2 fresh forms — the int-cast also
   grows the frame to 0x90). Everything else (the (s32) cvt conversions, the
   ±3/±2 comparison chains, the 0xE1F/0xE3C guards, D_007E8020 sw stores)
   matches; only var_21/var_20 and the sltu-on-var_5 check registers remain
   after the CSE issue. */
// FUN_00167560
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00167560);



// FUN_001679D0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001679d0);

// FUN_00167D60
void func_00167d60(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00167D90
s32 func_00167d90(u8 *arg0)
{
    s32 r;
    u32 acc = 0;
    s32 i = 0;
    s32 j = 0;
    while (i < 4) {
        u32 v = *(u32 *)arg0;
        if (v != 0) {
            acc |= (v & 0xFF) << (j * 8);
            j++;
        }
        i++;
        arg0 += 8;
    }
    if (acc == 0) {
        return 0;
    }
    if (func_00162510(*(u16 *)D_00762EA0, *(u16 *)(D_00762EA0 + 4)) == 1 || func_0015a160() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xED8);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x28, 0x40000);
    if (r == 0) {
        return 0;
    }
    func_00451fc0(NULL, D_005F15E0, 0xF, 0, 0, (void (*)(void *))func_001679d0, (void (*)(void *))func_00167d60, r);
    *(s32 *)(r + 4) = acc & 0xFF;
    *(s32 *)(r + 8) = (acc >> 8) & 0xFF;
    *(s32 *)(r + 0xC) = (acc >> 16) & 0xFF;
    *(s32 *)(r + 0x10) = (acc >> 24) & 0xFF;
}
