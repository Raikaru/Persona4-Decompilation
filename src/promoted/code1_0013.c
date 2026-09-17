#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"

extern u32 func_003b7060(void);
extern s32 func_0034c210(void);
extern u8 *func_00106820();
extern u32 func_00106880(s16 arg0);
extern void (*D_00887300[])(u32 state, u32 value);
extern s32 func_0010f930(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
static inline u8 *code13AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
static inline f32 code13Add(f32 left, f32 right) {
    return left + right;
}
extern void func_0046d280(void *node);
extern void func_001400f0(u8 *arg0);
extern void func_00141d10(u8 *arg0);
extern void func_001437b0(void *arg0, s32 arg1, s32 arg2);
extern void func_00105780(s16 arg0);
extern u16 func_0010f8c0(s32 arg0);
extern s32 func_0012ff60(u8 *arg0, u32 arg1);
extern s32 func_0034bb20(s32 arg0);
extern s32 func_0013c6d0(s16 arg0);
extern s32 func_0010f540(s32 arg0);
extern void func_0011d080(u8 *arg0, s32 arg1);
extern void func_0011d0a0(u8 *arg0, s32 arg1);
extern void func_0011d0d0(u8 *arg0, void *arg1);
extern void func_0011d170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00453670();
extern void func_00453760(void *arg0, s32 arg1);
extern void func_004538e0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00453960(void *arg0);
extern void func_00136fa0(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0010ace0(s16 arg0);
extern s32 func_0010a900(s32 arg0);
extern void func_0011c2c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0010b510(void);
extern void func_0010b3b0(s16 arg0);
extern s32 func_0010f6a0(s16 arg0, s32 arg1);
extern void func_0011c180(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0013f620(s16 arg0, s32 arg1, u8 *arg2);
extern void func_0013a040(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0013a530(u8 *arg0, s32 arg1);
extern void func_0013aa00(u8 *arg0);
extern void func_001344b0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00131730(u8 *arg0);
extern void func_00134560(u8 *arg0, s32 arg1);
extern void func_00134a50(u8 *arg0);
extern void func_001349f0(u8 *arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern s32 func_00106600(s16 arg0);
extern void func_00106620(s16 arg0, s32 arg1);
extern void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
extern void func_00134990(u8 *arg0, s16 arg1, s16 arg2);
extern void func_0034f2e0(void *arg0, f32 fparg0, f32 fparg1,
                          u8 arg1, u8 arg2, u8 arg3, u32 arg4);
extern void func_0034f320(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                          u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5,
                          u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);
extern void func_00135520(u8 *arg0, PackedVec2f arg1, u32 arg2, s32 arg3);
extern void func_00112300(s64 arg0, u8 arg1, u8 *arg2, f32 fparg0);
extern void func_002bc4b0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, f32 fparg0);
extern void func_0011fd30(s16 *arg0);
extern void func_0011fd50(s64 arg0, s32 arg1, s16 *arg2, s32 arg3, f32 fparg0);
extern s32 func_00104c70(s32 arg0);
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern void func_00113790(s64 arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4);
extern void func_002bc860(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          f32 fparg0, f32 fparg1, f32 fparg2);
extern void func_0012e2f0(u8 *arg0);
extern s32 func_0012e8b0(u8 *arg0);
extern s32 func_0012ff40(s32 arg0, s32 arg1, s16 arg2);
extern void func_00353fb0(void);
extern void func_00353fe0(void);
extern s32 func_00354030(void);
extern void func_00354080(s32 arg0);
extern void func_0034bd60(s32 arg0);
extern s32 func_0013b9f0(u8 *arg0);
extern s32 func_0013c700(s32 arg0, s16 arg1, u8 *arg2);
extern u16 D_008C024E[];
extern u16 D_008C0252[];
extern void func_0013c5a0(s32 *arg0, u8 *arg1);
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2F4[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
extern u8 D_0064B30C[];
typedef signed __int128 code13S128;
extern void func_001056e0(s32 arg0, s16 arg1);
extern void func_00105730(s32 arg0, s16 arg1);
extern void func_00106390(s32 arg0, s32 arg1);
extern void func_0010f770(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
extern s32 func_00354010(void);
extern void func_0013aa90(u8 *arg0);
extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
extern s16 func_00353c10(s16 *arg0);
extern s16 func_00353b50(s16 *arg0);
extern s32 func_00167d90(u8 *arg0);
extern s32 func_00354a50(s32 arg0, s32 arg1);
extern s32 func_0046a770(void *arg0);
extern s32 func_0046d200(void *arg0, u8 arg1);
extern void func_0046d730(void *arg0, s32 arg1);
extern void func_00141d80(u8 *arg0, u32 arg1);
extern u8 D_005E57F0[];
extern u8 D_005E5810[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005EDEA0[];
extern u8 D_005EDA00[];
extern u8 D_005EF6C8[];
extern u8 D_005ED9E0[];
extern u8 D_005ED9F0[];
typedef struct {
    s32 first;
    s32 second;
} code13Pair;

 

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* measured: donor loop shape requires invariant hoisting for the retail preheader and loop register coloring. */
#pragma opt_loop_invariants on
// FUN_001302D0
void func_001302d0(u8 *arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0x1608) = *(f32 *)(q + 0x1618);
        *(f32 *)(q + 0x160c) = *(f32 *)(q + 0x161c);
        *(u8 *)(q + 0x1620) = *(u8 *)(q + 0x1622);
        *(f32 *)(q + 0x16c8) = *(f32 *)(q + 0x16d8);
        *(f32 *)(q + 0x16cc) = *(f32 *)(q + 0x16dc);
        *(u8 *)(q + 0x16e0) = *(u8 *)(q + 0x16e2);
        if (*(s16 *)(arg0 + 0x26) == i) {
            *(s32 *)(q + 0x1610) = 0x41c80000;
            *(s32 *)(q + 0x16d0) = 0x41c80000;
        } else {
            *(s32 *)(q + 0x1610) = 0;
            *(s32 *)(q + 0x16d0) = 0;
        }
    }
    *(s16 *)(arg0 + 0x1c) = 0;
}
/* measured: close the donor loop's invariant-hoisting bracket. */
#pragma opt_loop_invariants off
// FUN_00130360
void func_00130360(u8 *arg0) {
    f32 f0;
    f32 f1;

    *(u32 *)(arg0 + 0x1ab8) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac0) = 0x435d0000;
    *(u32 *)(arg0 + 0x1ac8) = 0x435d0000;
    *(u8 *)(arg0 + 0x1ad0) = 0xff;
    *(u8 *)(arg0 + 0x1ad2) = 0xff;
    *(u8 *)(arg0 + 0x1ad1) = 0;
    *(u32 *)(arg0 + 0x1af4) = 0;
    if (*(s16 *)(arg0 + 0x24) > *(s16 *)(arg0 + 0x2a)) {
        f0 = 21.0f + *(f32 *)(arg0 + 0x149c);
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = *(f32 *)(arg0 + 0x1acc) - 10.0f;
        *(u32 *)(arg0 + 0x1aec) = 0xc1200000;
    } else {
        f1 = 21.0f + *(f32 *)(arg0 + 0x158c);
        f0 = 170.0f + f1;
        *(f32 *)(arg0 + 0x1acc) = f0;
        *(f32 *)(arg0 + 0x1abc) = f0;
        *(f32 *)(arg0 + 0x1ac4) = 10.0f + *(f32 *)(arg0 + 0x1acc);
        *(u32 *)(arg0 + 0x1aec) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
// FUN_00130430
void func_00130430(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0xC; i++) {
        if (func_003b7060() & 3) {
            p = arg0 + i * 0x30;
            val = (func_003b7060() % 6U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x1880) = f;
            *(f32 *)(p + 0x1878) = f;
            *(u32 *)(p + 0x187C) = 0x43FA0000;
            *(f32 *)(p + 0x188C) = *(f32 *)(p + 0x187C);
            *(s32 *)(p + 0x1884) = 0xC2C80000;
            q = (u32 *)(p + 0x18A0);
            random = func_003b7060() % 10U;
            *q = random;
            *(s32 *)(p + 0x18A4) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x187C) = *(f32 *)(p + 0x1884);
        }
    }
    *(s16 *)(arg0 + 0x1E) = 0;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2
// FUN_00130580
void func_00130580(u8 *arg0) {
    s32 i;
    u8 *p;
    u8 *q;
    s32 temp;

    i = 0;
    while (i < 0x33) {
        q = arg0 + i * 4;
        p = q + 0x1b18;
        temp = *(s32 *)(q + 0x1b18);
        if (temp != 0) {
            func_0046d280((void *)temp);
            *(s32 *)p = 0;
        }
        i++;
    }
    *(s32 *)(arg0 + 0x14) = 0;
}
// FUN_00130600
s32 func_00130600(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x1c);

    while (i < 0x1e) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x1304)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}
/* Model floor (1456B window; obj 1452B). Probe 304 words (verify nd 918),
   fnalign 433 edits plus 7 reloc-only, retail 363/object 363 exact via dead-arm store
   (was 445; shortfall vanished 361-vs-359 -> 363-vs-363).
   WINS this round: spd 12B array (matched func_00367940 tmp[12] idiom;
   208/214/216 exact, +14 layout fixed, dead li+sw/sh kept via alias),
   loop %10 without fresh andi (retail reuses test $2, no extra andi).
   Prior WINS kept: 68cb0 arm-flip (c.le+bc1t small-first, all 3 convs),
   reassign int->float, trunc idiom, 1.0f init, b2 addu order.
   slti check: exclusive <0xA kept ($at wall none; <=0xA neutral at 302).
   WALLS (coloring chaos, ~27 inert probes total): unmerge-wall (b0/b1
   identical RHS merges to s5-sum; retail i21 in s5 + v-temp sums
   + pp s5-reuse), t30 spill (sq/lq@192, s16-narrow), pp2 dup,
   s/f-rotations, f12t offset (220 vs 200), temp-reg names. D_0064 rows
   are reloc phantoms. This round inert: final-reassign, loop-mask alone,
   slti-inclusive, dead else-if, i21/bb orders, decl reorder, b2 order,
   pragmas, unmerge split, pp+4. Re-measured 2026-09-17: cse_off fndiff 300
   verify 888 obj 1508 fnalign 463 retail 364/object 377; +loopinv 300 neutral,
   +schedule 345 worse, +nobl 300 neutral. Resume: declaration-order key for f12t,
   then t30 narrow.
*/
/* measured 00130680: `opt_common_subs off` inside the guard is worth 4 words (304 -> 300); retail rematerialises what b210 hoists. */
// FUN_00130680 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
void func_00130680(u8 *arg0, s32 arg1)
{
    s16 t30;
    s32 b2;
    f32 f24g;
    s32 v23;
    u8 spd[12];
    f32 f22;
    f32 f21;
    s32 tu0;
    f32 fq;
    f32 f23d;
    s32 t3;
    u8 *pb0;
    u8 *pb1;
    u8 *pb2;
    s32 i21;
    u8 *bb;
    f32 f20t;
    f32 f1t;
    s32 tu2;
    f32 fmul2;
    s32 mbyte;
    s32 s3v;
    u8 *pp;
    u8 *pp2;
    f32 f12t;
    f32 f13t;
    s32 dc;
    f32 s3f;
    f32 fmul3;
    s32 vfin;

    b2 = arg1 * 2;
    t30 = *(s16 *)(b2 + (s32)arg0 + 0x34);
    f24g = 1.0f;
    v23 = 0;
    func_0011fd30((s16 *)spd);
    *(s32 *)(spd + 8) = 1;
    *(s16 *)spd = t30;
    f22 = *(f32 *)(arg0 + 4);
    f21 = *(f32 *)(arg0 + 8);
    tu0 = *(u8 *)(arg0 + 0);
    if (tu0 >= 0) {
        fq = (f32)tu0;
    } else {
        tu0 = ((u32)tu0 >> 1) | (tu0 & 1);
        fq = (f32)tu0;
        fq += fq;
    }
    f23d = fq / 255.0f;
    t3 = *(s32 *)(arg0 + 0x14);
    if (((t3 & 0x10) != 0 && *(s16 *)(arg0 + 0x26) == arg1) || ((t3 & 0x20) != 0)) {
        v23 = 1;
        *(s16 *)(spd + 6) = 1;
        pb0 = D_0064B2E8;
        pb1 = &D_0064B2E8[4];
        pb2 = &D_0064B2E8[20];
    } else {
        *(s16 *)(spd + 6) = 0;
        pb0 = D_0064B2E0;
        pb1 = &D_0064B2E0[16];
        pb2 = &D_0064B2E0[40];
        f24g = fGpffff82cc;
    }
    i21 = arg1 * 0x30;
    bb = (u8 *)(i21 + (s32)arg0);
    f12t = 67.0f + (f22 + *(f32 *)(bb + 0x16D8));
    f20t = 75.0f * (f32)arg1;
    f13t = 24.0f + (f21 + *(f32 *)(bb + 0x16DC)) + f20t;
    tu2 = *(u8 *)(bb + 0x16E2);
    if (tu2 >= 0) {
        f1t = (f32)tu2;
    } else {
        tu2 = ((u32)tu2 >> 1) | (tu2 & 1);
        f1t = (f32)tu2;
        f1t += f1t;
    }
    fmul2 = f1t * f23d;
    if (!(2147483648.0f <= fmul2)) {
        mbyte = (s32)(fmul2) & 0xFF;
    } else {
        mbyte = ((s32)(fmul2 - 2147483648.0f)) | 0x80000000;
        mbyte &= 0xFF;
    }
    s3v = mbyte & 0xFF;
    func_0011fd50(*(s64 *)&f12t, mbyte & 0xFF, (s16 *)spd, 0, 0.0f);
    bb = (u8 *)(i21 + (s32)arg0);
    tu2 = *(u8 *)(bb + 0x1622);
    if (tu2 >= 0) {
        f1t = (f32)tu2;
    } else {
        tu2 = ((u32)tu2 >> 1) | (tu2 & 1);
        f1t = (f32)tu2;
        f1t += f1t;
    }
    fmul2 = f1t * f23d;
    if (!(2147483648.0f <= fmul2)) {
        mbyte = (s32)(fmul2) & 0xFF;
    } else {
        mbyte = ((s32)(fmul2 - 2147483648.0f)) | 0x80000000;
        mbyte &= 0xFF;
    }
    s3v = mbyte & 0xFF;
    pp = bb + 0x1618;
    f12t = 60.0f + (f22 + *(f32 *)(bb + 0x1618));
    pp2 = bb + 0x161C;
    f13t = 21.0f + (f21 + *(f32 *)(bb + 0x161C)) + f20t;
    func_0034f2e0(*(void **)(arg0 + 0x1B90), f12t, f13t,
                  pb0[0], pb0[1], pb0[2], s3v);
    if (v23 != 0) {
        f12t = 2.0f + (f22 + *(f32 *)(pp + 0));
        f13t = 27.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
        func_0034f2e0(*(void **)(arg0 + 0x1B94), f12t, f13t,
                      0x4C, 0x4C, 0x4C, s3v);
    }
    dc = func_00104c70(t30) & 0xFF;
    f12t = 43.0f + (f22 + *(f32 *)(pp + 0));
    f13t = 25.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
    if (dc < 0xA) {
        f12t = f12t - 11.0f;
    }
    while ((dc & 0xFF) > 0) {
        func_0034f2e0(*(void **)((s32)arg0 + ((dc % 10) * 4) + 0x1BA4),
                      f12t, f13t, pb1[0], pb1[1], pb1[2], s3v);
        f12t = f12t - 22.0f;
        dc = ((u32)(dc & 0xFF) / 10U) & 0xFF;
    }
    f12t = 37.0f + (f22 + *(f32 *)(pp + 0));
    f13t = 53.0f + (f21 + *(f32 *)(pp2 + 0)) + f20t;
    if (s3v >= 0) {
        s3f = (f32)s3v;
    } else {
        s3f = (f32)(((u32)s3v >> 1) | (s3v & 1));
        s3f += s3f;
    }
    fmul3 = s3f * f24g;
    if (!(2147483648.0f <= fmul3)) {
        vfin = (s32)(fmul3) & 0xFF;
    } else {
        vfin = ((s32)(fmul3 - 2147483648.0f)) | 0x80000000;
        vfin &= 0xFF;
    }
    func_0034f2e0(*(void **)(arg0 + 0x1BE0), f12t, f13t,
                  pb2[0], pb2[1], pb2[2], vfin);
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130680);
#endif
// FUN_00130C30
/* measured: opt_propagation off probe for func_00130c30 ordering. */
#pragma opt_propagation off
void func_00130c30(u8 *arg0, s64 arg1, s32 arg2)
{
    f32 c0;
    s32 p;
    u32 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1b60);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    func_0034f2e0((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    func_0034f2e0(*(void **)(arg0 + 0x1b64),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
/* measured: close opt_propagation for func_00130c30 probe. */
#pragma opt_propagation on
/* Model floor (1488B window; plain obj 1264B fndiff 307 verify 845 fnalign 224
   retail 368/object 316; trunc-idiom, reassign int->float, 30c30 family shapes.
   Open: DSE-wall (dead v10/v10b convs), CSE-wall (fmul conv merged), arm-flip
   (bc1f vs bc1t), s-map rotation, union layout. Dead t3 in 2nd 34f320 kept literal.
   Re-measured 2026-09-17: plain 307 best; cse_off 317 worse, o1 314 worse, loopinv neutral,
   sched/nobl neutral-or-worse on verify; prior 317 now reproduces as cse_off fndiff.
*/
// FUN_00130CE0 NONMATCHING
#ifdef NON_MATCHING
void func_00130ce0(u8 *arg0, s64 arg1, s32 arg2, s16 *arg3)
{
    s64 a1s;
    f32 fa0;
    f32 fa4;
    union {
        f32 f;
        u8 b[8];
    } u;
    s64 t98;
    u8 c5;
    u8 c6;
    u8 c7;
    s32 tu0;
    s32 tu1;
    f32 fq;
    f32 f22;
    f32 f23;
    f32 fhi;
    f32 t204;
    f32 fa2;
    f32 fmul;
    s32 v8;
    s32 v10;
    s32 v10b;
    s32 vfin;

    a1s = arg1;
    fhi = ((f32 *)&a1s)[1];
    tu0 = *(u8 *)(arg0 + 0);
    if (tu0 >= 0) {
        fq = (f32)tu0;
    } else {
        tu0 = ((u32)tu0 >> 1) | (tu0 & 1);
        fq = (f32)tu0;
        fq += fq;
    }
    f22 = fq / 255.0f;
    u.b[4] = 0x14;
    u.b[5] = 0x14;
    u.b[6] = 0x14;
    t204 = 204.0f * f22;
    if (2147483648.0f <= t204) {
        v8 = (((s32)(t204 - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(t204) & 0xFF;
    }
    u.b[7] = v8;
    tu1 = *(u16 *)(arg0 + 0x15FE);
    if (tu1 >= 0) {
        f23 = (f32)tu1;
    } else {
        tu1 = ((u32)tu1 >> 1) | (tu1 & 1);
        f23 = (f32)tu1;
        f23 += f23;
    }
    fa0 = ((f32 *)&a1s)[0] - 1.0f;
    fa4 = 24.0f + fhi;
    if (2147483648.0f <= f23) {
        v10 = (((s32)(f23 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
    } else {
        v10 = (s32)(f23) & 0xFFFF;
    }
    c7 = u.b[7];
    c6 = u.b[6];
    c5 = u.b[5];
    func_0034f320(*(u8 **)(arg0 + 0x1BD4), fa0, fa4, 0.0f,
                  u.b[4], c5, c6, c7,
                  0x1000, 0, 0, 0.0f, 0);
    if (2147483648.0f <= f23) {
        v10b = (((s32)(f23 - 2147483648.0f)) | 0x80000000) & 0xFFFF;
    } else {
        v10b = (s32)(f23) & 0xFFFF;
    }
    func_0034f320(*(u8 **)(arg0 + 0x1BD8), (f32)0x159 + fa0, fa4, 0.0f,
                  u.b[4], c5, c6, c7,
                  0x1000, 0, 0, 0.0f, 0);
    fa0 = 5.0f + ((f32 *)&a1s)[0] + *(f32 *)(arg0 + 0x1858);
    fa4 = 34.0f + fhi + *(f32 *)(arg0 + 0x185C);
    u.b[4] = 0x68;
    u.b[5] = 0x68;
    u.b[6] = 0x68;
    if (arg2 >= 0) {
        fa2 = (f32)arg2;
    } else {
        arg2 = ((u32)arg2 >> 1) | (arg2 & 1);
        fa2 = (f32)arg2;
        fa2 += fa2;
    }
    fmul = fa2 * f22;
    if (2147483648.0f <= fmul) {
        v8 = (((s32)(fmul - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(fmul) & 0xFF;
    }
    u.b[7] = v8;
    c7 = u.b[7];
    c6 = u.b[6];
    c5 = u.b[5];
    func_0034f2e0(*(void **)(arg0 + 0x1BCC), fa0, fa4,
                  u.b[4], c5, c6, c7);
    func_0034f2e0(*(void **)(arg0 + 0x1BD0), 330.0f + fa0, fa4,
                  u.b[4], c5, c6, c7);
    fa0 = ((f32 *)&a1s)[0];
    fa4 = fhi;
    u.b[4] = D_0064B2E8[0];
    u.b[5] = D_0064B2E8[1];
    u.b[6] = D_0064B2E8[2];
    t204 = 255.0f * f22;
    if (2147483648.0f <= t204) {
        v8 = (((s32)(t204 - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        v8 = (s32)(t204) & 0xFF;
    }
    u.b[7] = v8;
    u.f = *(f32 *)&u.b[4];
    t98 = *(s64 *)&fa0;
    c7 = u.b[3];
    c6 = u.b[2];
    c5 = u.b[1];
    func_0034f2e0(*(void **)(arg0 + 0x1B60), *(f32 *)&t98,
                  *((f32 *)&t98 + 1), u.b[0], c5, c6, c7);
    func_0034f2e0(*(void **)(arg0 + 0x1B64), 340.0f + *(f32 *)&t98,
                  *((f32 *)&t98 + 1), u.b[0], c5, c6, c7);
    fa0 = fa0 - 2.0f;
    func_00112300(*(s64 *)&fa0, u.b[7], (u8 *)arg3, 0.0f);
    fa0 = 22.0f + ((f32 *)&a1s)[0];
    fa4 = 54.0f + fhi;
    if (2147483648.0f <= fmul) {
        vfin = (((s32)(fmul - 2147483648.0f)) | 0x80000000) & 0xFF;
    } else {
        vfin = (s32)(fmul) & 0xFF;
    }
    func_002bc4b0(*arg3, (s32)fa0, (s32)fa4, (vfin & 0xFF) | ~0xFF,
                  1, 8, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00130ce0);
#endif
/* measured: second 00134890 probe preserves the retail floating zero and constant materialization. */
#pragma opt_propagation off
// FUN_00134890
void func_00134890(u8 *arg0)
{
    f32 temp_f1;
    f32 temp_f0;

    temp_f1 = 0.0f;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xFF;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13D0) = 0;
    *(u8 *)(arg0 + 0x13E8) = 0xFF;
    *(s8 *)(arg0 + 0x1418) = 0;
    temp_f0 = 122.0f;
    *(s32 *)(arg0 + 0x1430) = 0x42F40000;
    *(s32 *)(arg0 + 0x1438) = 0x42F40000;
    *(s32 *)(arg0 + 0x1440) = 0x42F40000;
    *(u8 *)(arg0 + 0x1448) = 0xFF;
    *(u8 *)(arg0 + 0x144A) = 0xFF;
    *(s8 *)(arg0 + 0x1449) = 0;
    *(s32 *)(arg0 + 0x1490) = 0;
    *(s32 *)(arg0 + 0x1498) = 0;
    *(s32 *)(arg0 + 0x14A0) = 0;
    *(u8 *)(arg0 + 0x14A8) = 0xFF;
    *(u8 *)(arg0 + 0x14AA) = 0xFF;
    *(s8 *)(arg0 + 0x14A9) = 0;
    *(s32 *)(arg0 + 0x146C) = 0;
    if (*(s16 *)(arg0 + 0x2C) > *(s16 *)(arg0 + 0x34)) {
        *(s32 *)(arg0 + 0x1444) = 0x43090000;
        *(s32 *)(arg0 + 0x1434) = 0x43090000;
        *(f32 *)(arg0 + 0x143C) = temp_f0;
        *(f32 *)(arg0 + 0x14A4) = temp_f1;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0xC1A80000;
        *(s32 *)(arg0 + 0x1464) = 0xC1200000;
    } else {
        temp_f0 = (f32)0x111;
        *(f32 *)(arg0 + 0x1444) = temp_f0;
        *(f32 *)(arg0 + 0x1434) = temp_f0;
        *(s32 *)(arg0 + 0x143C) = 0x43950000;
        *(f32 *)(arg0 + 0x1494) = temp_f1;
        *(s32 *)(arg0 + 0x149C) = 0x41A80000;
        *(f32 *)(arg0 + 0x143C) = 10.0f + *(f32 *)(arg0 + 0x1444);
        *(s32 *)(arg0 + 0x1464) = 0x41200000;
    }
    *(s16 *)(arg0 + 0x24) = 0;
}
/* measured: close opt_propagation for func_00134890. */
#pragma opt_propagation on
// FUN_00134990
void func_00134990(u8 *arg0, s16 arg1, s16 arg2) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x1374) = 0;
    *(s32 *)(arg0 + 0x137c) = 0xc1200000;
    *(u8 *)(arg0 + 0x1388) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0x41200000;
    *(s32 *)(arg0 + 0x101c) = 0;
    *(s8 *)(arg0 + 0x1028) = 0;
    *(s16 *)(arg0 + 0xc7a) = arg1;
    *(s16 *)(arg0 + 0xc7c) = arg2;
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_001349F0
void func_001349f0(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0x42480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0xc2480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_00134A50
void func_00134a50(u8 *arg0) {
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s8 *)(arg0 + 0x1388) = 0;
    *(u8 *)(arg0 + 0x1028) = 0xff;
    *(s32 *)(arg0 + 0x1014) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0;
    *(u8 *)(arg0 + 0x13e8) = 0xff;
    *(s8 *)(arg0 + 0x1418) = 0;
    *(s32 *)(arg0 + 0x13d0) = 0xc2480000;
    *(s8 *)(arg0 + 0x13e8) = 0;
    *(s32 *)(arg0 + 0x1400) = 0x42480000;
    *(u8 *)(arg0 + 0x1418) = 0xff;
    *(s16 *)(arg0 + 0xc7e) = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x30) * 2, arg0) + 0x38);
    *(s16 *)(arg0 + 0x20) = 0;
}
// FUN_00134AB0
void func_00134ab0(u8 *arg0) {
    s32 temp;
    s32 var17;
    s32 var18;
    u8 *p;
    u8 *q;

    var18 = 0;
    while (var18 < 0x34) {
        q = arg0 + var18 * 4;
        p = q + 0x14c0;
        temp = *(s32 *)(q + 0x14c0);
        if (temp != 0) {
            func_0046d280((void *)temp);
            *(s32 *)p = 0;
        }
        var18++;
    }
    var17 = 0;
    while (var17 < *(s16 *)(arg0 + 0x48)) {
        func_00105780(*(s16 *)(arg0 + var17 * 2 + 0x38));
        var17++;
    }
    *(s32 *)(arg0 + 0x1c) = 0;
}
// FUN_00134B60
s32 func_00134b60(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 41) {
        if (v < *(s32 *)(arg0 + i * 48 + 0xcac)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}
/* measured: loop-invariant hoisting gives 444B / 448B with only zero tail padding. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00134BE0
s32 func_00134be0(u8 *arg0) {
    struct ChangeRecord {
        s32 id;
        s16 before;
        s16 after;
    };
    s16 party[4];
    struct ChangeRecord changes[4];
    s16 member;
    s32 count;
    s16 id, stat, search;
    s16 partyCount, value;
    s16 *old;
    struct ChangeRecord *change;

    count = 0;
    func_0043f9c8(changes, 0, sizeof(changes));
    partyCount = func_00353b50(party);
    for (member = 0; member < *(s16 *)(arg0 + 0x48); member++) {
        id = *(s16 *)(arg0 + member * 2 + 0x38);
        for (search = 0; search < partyCount && id != party[search]; search++) {}
        if (search != partyCount) {
            for (stat = 0; stat < 3; stat++) {
                value = func_00106cd0(id, stat);
                old = (s16 *)(arg0 + member * 6 + stat * 2 + 0xC48);
                if (*old != value && stat == 0) {
                    change = &changes[count];
                    change->id = id;
                    change->before = *old;
                    change->after = value;
                    count++;
                }
            }
        }
    }
    if (count > 0) *(s32 *)(arg0 + 0x1594) = func_00167d90((u8 *)changes);
    return count > 0;
}
#pragma pop
// FUN_00134DA0
s32 func_00134da0(s32 arg0) {
    s32 result;

    if (arg0 & 0x81) {
        result = 7;
        goto done;
    }
    if (arg0 & 0x102) {
        result = 8;
        goto done;
    }
    if (arg0 & 0x204) {
        result = 9;
        goto done;
    }
    if (arg0 & 0x408) {
        result = 10;
        goto done;
    }
    if (arg0 & 0x810) {
        result = 11;
        goto done;
    }
    if (arg0 & 0x1020) {
        result = 12;
        goto done;
    }
    if (arg0 & 0x2040) {
        result = 13;
    }
done:
    return result;
}
// FUN_00134E50
/* measured: reconstructing the mixed-ABI palette draw pair from the matching 00130C30 shape. */
#pragma opt_propagation off
void func_00134e50(u8 *arg0, s64 arg1, s64 arg2, u32 arg3)
{
    f32 temp_f20;
    s32 p;
    s32 p2;
    u8 *color;

    p = *(s32 *)(arg0 + 0x1580);
    p2 = *(s32 *)(arg0 + 0x1584);
    switch ((s16)arg2) {
    case 0:
        color = D_0064B2E0;
        break;
    case 1:
        color = D_0064B2E8;
        break;
    }
    temp_f20 = ((f32 *)&arg1)[1] - 3.0f;
    func_0034f2e0((void *)p, ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
    func_0034f2e0((void *)p2, 241.0f + ((f32 *)&arg1)[0], temp_f20,
                  color[0], color[1], color[2], arg3);
}
/* measured: close mixed-ABI palette draw pair pragma. */
#pragma opt_propagation on
// FUN_00134F40
/* measured: transfer the neighboring mixed-ABI palette branch shape. */
#pragma opt_propagation off
void func_00134f40(u8 *arg0, s64 arg1, s64 arg2, u32 arg3)
{
    f32 temp_f20;
    s32 p;
    u8 *color;

    switch ((s16)arg2) {
    case 0:
        p = *(s32 *)(arg0 + 0x14C8);
        temp_f20 = ((f32 *)&arg1)[1];
        func_0034f2e0((void *)p,
                      ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1508);
        func_0034f2e0((void *)p,
                      36.0f + ((f32 *)&arg1)[0], 24.0f + temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1500);
        temp_f20 = code13Add(9.0f, temp_f20);
        func_0034f2e0((void *)p,
                      419.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        p = *(s32 *)(arg0 + 0x1504);
        func_0034f2e0((void *)p,
                      473.0f + ((f32 *)&arg1)[0], temp_f20,
                      D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], arg3);
        break;
    case 1:
        color = D_0064B2E8;
        p = *(s32 *)(arg0 + 0x155C);
        temp_f20 = ((f32 *)&arg1)[1];
        func_0034f2e0((void *)p,
                      2.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
        p = *(s32 *)(arg0 + 0x1560);
        func_0034f2e0((void *)p,
                      474.0f + ((f32 *)&arg1)[0], temp_f20,
                      color[0], color[1], color[2], arg3);
        break;
    }
}
/* measured: close neighboring mixed-ABI palette branch pragma. */
#pragma opt_propagation on
/* Model floor (1008B window; plain obj 876B fndiff 227 verify 678, o1 obj 924B
   fndiff 216 verify 664 best via level-1 keep-separate. WINS: 135520 PackedVec2f-union
   call, D_00887300[0] table call, 45d6e0 proto, K&R 1069d0, trunc idiom, int-form 457.0f,
   32/81/179 consts, direct t0, no-a3 112300 shape. WALLS: merged identical D_0064 branch
   arms, f21v-dead coalescing (no $f23 save), bbuf/fa0 layout rotation, dead zd branch
   (DSE wall), temp-reg names, GPREL/absolute display phantoms (relocs ok). Extra
   2026-09-17: cse_off 229 worse, loopinv 227 neutral, sched 230 worse (verify 598 but
   tail penalty), nobl 227 neutral, o1_sched 232 worse; o1 227->216 applied below.
*/
/* measured 00135130: `optimization_level 1` inside the guard is worth 11 words (227 -> 216); level 1 keeps separate what -O2 coalesces. */
// FUN_00135130 NONMATCHING
#ifdef NON_MATCHING
/* measured: -O2 coalesces two values retail keeps in separate registers
   and folds a mask retail re-issues; level 1 does neither. */
#pragma optimization_level 1
void func_00135130(u8 *arg0, s64 arg1, s32 arg2, u8 *arg3)
{
    extern void func_002bc7a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                              s32 arg4, f32 fparg0, f32 fparg1, f32 fparg2);
    extern s32 func_001069d0();
    extern void func_0045d6e0(u8 *arg0, u8 *arg1, s32 arg2, f32 fparg0);
    s32 wbuf[4];
    f32 fa0;
    f32 fa4;
    u8 bbuf[4];
    f32 f20t;
    f32 f21v;
    f32 f23v;
    f32 f22v;
    s32 zd;
    PackedVec2f pv;

    fa0 = 5.0f + ((f32 *)&arg1)[0];
    fa4 = 27.0f + ((f32 *)&arg1)[1];
    if (*(s16 *)(arg3 + 22) == 3) {
        bbuf[0] = D_0064B2E0[0];
        bbuf[1] = D_0064B2E0[1];
        bbuf[2] = D_0064B2E0[2];
    } else {
        bbuf[0] = D_0064B2E0[0];
        bbuf[1] = D_0064B2E0[1];
        bbuf[2] = D_0064B2E0[2];
    }
    bbuf[3] = arg2;
    wbuf[0] = (s32)fa0;
    wbuf[1] = (s32)fa4;
    wbuf[2] = 470;
    wbuf[3] = 39;
    D_00887300[0](1, 0);
    func_0045d6e0(bbuf, (u8 *)wbuf, 0, 0.0f);
    f20t = 4.0f + fa0;
    f21v = 10.0f + fa4;
    func_0034f2e0(*(void **)(arg0 + 0x1548), f20t, f21v, bbuf[0], bbuf[1], bbuf[2], arg2);
    f23v = 41.0f + f21v;
    fa4 = f23v;
    func_0034f2e0(*(void **)(arg0 + 0x154C), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    f22v = 91.0f + f23v;
    func_0034f2e0(*(void **)(arg0 + 0x1550), fa0, f22v, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = (f32)0x1C9 + fa0;
    fa4 = f21v;
    func_0034f2e0(*(void **)(arg0 + 0x1554), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = 40.0f + fa0;
    fa4 = 2.0f + f23v;
    func_0034f2e0(*(void **)(arg0 + 0x1558), fa0, fa4, bbuf[0], bbuf[1], bbuf[2], arg2);
    fa0 = ((f32 *)&arg1)[0];
    fa4 = f20t;
    pv.packed = *(s64 *)&fa0;
    func_00135520(*(u8 **)(arg0 + 0x1560), pv, arg2, 3);
    fa0 = fa0 - 2.0f;
    fa4 = f20t;
    func_00112300(*(s64 *)&fa0, bbuf[0], (u8 *)arg3, 0.0f);
    fa0 = 128.0f + ((f32 *)&arg1)[0];
    fa4 = 32.0f + f20t;
    if ((func_00106880(*(s16 *)arg3) & 0x8000) != 0) {
        zd = 0;
    } else {
        zd = func_001069d0(*(s16 *)arg3) & 0xFFFF;
    }
    arg2 = (arg2 & 0xFF) | ~0xFF;
    func_002bc7a0(*(s32 *)(arg0 + 0x1548), arg2, 1, 6, 3,
                  (f32)(s32)fa0, (f32)(s32)fa4, 0.0f);
    fa0 = 179.0f + ((f32 *)&arg1)[0];
    fa4 = 81.0f + f20t;
    func_002bc4b0(*(s16 *)arg3, (s32)fa0, (s32)fa4, (arg2 & 0xFF) | ~0xFF, 1, 8, 0.0f);
}
/* measured: closes the level 1 scope above at the file's -O2 baseline. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_00135130);
#endif
/* measured: the 130.0f sum is assigned to a different (dead) variable, so mwcc
   emits the constant as the first add.s operand like retail; `temp_f21 +=
   130.0f` keeps the variable first. The 467.0f sum is recomputed for the last
   call, as retail does. */
// FUN_00135520
void func_00135520(u8 *arg0, PackedVec2f arg1, u32 arg2, s32 arg3)
{
    f32 temp_f21;
    f32 temp_f20;
    u16 temp_16;
    u8 temp_17;
    u8 temp_18;
    u8 temp_19;
    void *temp_p;
    temp_17 = D_0064B2E8[0];
    temp_18 = D_0064B2E8[1];
    temp_19 = D_0064B2E8[2];
    temp_f21 = code13Add(arg1.xy.y, 26.0f);
    arg1.xy.y = temp_f21;
    temp_16 = (u16)arg3;
    if (temp_16 & 2) {
        func_0034f2e0(*(void **)(arg0 + 0x1538),
                      (temp_f20 = arg1.xy.x), temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x153C);
        temp_f20 = 467.0f + arg1.xy.x;
        func_0034f2e0(temp_p,
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x1540);
        temp_p = temp_p;
        temp_f20 = temp_f21 + 130.0f;
        func_0034f2e0(temp_p,
                      arg1.xy.x, temp_f20,
                      temp_17, temp_18, temp_19, arg2);
        func_0034f2e0(*(void **)(arg0 + 0x1544),
                      467.0f + arg1.xy.x, temp_f20,
                      temp_17, temp_18, temp_19, arg2);
    }
    if (temp_16 & 1) {
        arg1.xy.x -= 2.0f;
        arg1.xy.y -= 26.0f;
        func_00134f40(arg0, arg1.packed, 1, arg2);
    }
}
/* measured 0013ad40 (banked honest body: palette-table dispatch with ptab, 67/24/60/21/2/27/43/25/37/53 float chains cast-free per 13b420, recipe-A u8->float with f+f doubling, (u8)(u32) checked colour conversions, 11fd50 s64-tail, %10//10 digit loop, 1330 tail): measure_guarded 419 words obj 1836B/window 1584B; opclass mfc1/mtc1/lui/cvt.w.s +8 with c.ole/bc1t/sub +4. Verified against retail: plain lwc1 float loads (not int-convert), col conversion is the checked (u8)(u32) lowering with call-site re-andi, recipe-A uses srl + add.s doubling. Standing questions are per-site checked-vs-plain conversion mix plus frame/scheduling across 1584B. Production stays ASM. */
// FUN_0013AD40 NONMATCHING
#ifdef NON_MATCHING
void func_0013ad40(u8 *arg0, s32 arg1, s32 arg2) {
    s16 spD0;
    s16 spD6;
    s32 spD8;
    f32 spC8;
    f32 spCC;
    f32 f22;
    f32 f21;
    f32 f20;
    f32 fA;
    f32 fB;
    f32 fDiv;
    f32 fProd;
    u8 t0;
    u8 c0;
    u8 c1;
    s32 col;
    s32 colB;
    s32 col8;
    s16 idx0;
    s32 k;
    u8 *pal;
    u8 *palB;
    u8 *ptab;
    u8 *e;
    u8 *e2;
    s32 flag;
    s32 cnt;
    s32 cntB;
    flag = 0;
    fDiv = 1.0f;
    idx0 = *(s16 *)(arg0 + arg1 * 2 + 0xF4);
    f22 = *(f32 *)(arg0 + 4);
    f21 = *(f32 *)(arg0 + 8);
    t0 = *(u8 *)(arg0 + 0);
    func_0011fd30(&spD0);
    spD8 = 1;
    spD0 = idx0;
    if (*(s16 *)(arg0 + arg2 * 2 + 0x5C) == arg1 || (*(s32 *)(arg0 + 0x1C) & 0x100) != 0) {
        if (arg2 == 0 && (*(s32 *)(arg0 + 0x1C) & 0x10) != 0) {
            spD6 = 2;
            pal = D_0064B2F4;
            palB = D_0064B2F0;
            ptab = D_0064B30C;
        } else {
            flag = 1;
            spD6 = 1;
            pal = D_0064B2E8;
            palB = D_0064B2EC;
            ptab = D_0064B2FC;
        }
    } else {
        spD6 = 0;
        pal = D_0064B2E0;
        palB = D_0064B2F0;
        ptab = D_0064B308;
        fDiv = 1.0f;
    }
    if (arg2 == 0) { cnt = 5; cntB = 1; } else { cnt = 0x1C; cntB = 0x18; }
    e = arg0 + (cnt + arg1) * 0x30;
    spC8 = 67.0f + (f22 + *(f32 *)(e + 0x594));
    f20 = 75.0f * (f32)arg1;
    spCC = 24.0f + (f21 + *(f32 *)(e + 0x598)) + f20;
    c0 = e[0x59E];
    if ((s32)c0 >= 0) { fProd = (f32)c0; } else { fProd = (f32)((c0 >> 1) | (c0 & 1)); fProd = fProd + fProd; }
    fProd = fProd * fDiv;
    col = (u8)(u32)fProd;
    func_0011fd50(*(s64 *)&spC8, col & 0xFF, &spD0, 0, 0.0f);
    e2 = arg0 + (cntB + arg1) * 0x30;
    c1 = e2[0x59E];
    if ((s32)c1 >= 0) { fProd = (f32)c1; } else { fProd = (f32)((c1 >> 1) | (c1 & 1)); fProd = fProd + fProd; }
    fProd = fProd * fDiv;
    colB = (u8)(u32)fProd;
    k = colB & 0xFF;
    fA = 60.0f + (f22 + *(f32 *)(e2 + 0x594));
    spC8 = fA;
    fB = 21.0f + (f21 + *(f32 *)(e2 + 0x598)) + f20;
    spCC = fB;
    func_0034f2e0(*(void **)(arg0 + 0x12BC), fA, fB, pal[0], pal[1], pal[2], k);
    if (flag != 0) {
        fA = 2.0f + (f22 + *(f32 *)(e2 + 0x594));
        spC8 = fA;
        fB = 27.0f + (f21 + *(f32 *)(e2 + 0x598)) + f20;
        spCC = fB;
        func_0034f2e0(*(void **)(arg0 + 0x12C0), 0x4C, 0x4C, 0x4C, k, fA, fB);
    }
    fA = 43.0f + (f22 + *(f32 *)(e2 + 0x594));
    spC8 = fA;
    spCC = 25.0f + (f21 + *(f32 *)(e2 + 0x598)) + f20;
    k = (s32)(s8)(func_00104c70(idx0) & 0xFF);
    if (k < 0xA) { spC8 = fA - 11.0f; }
    while (k > 0) {
        func_0034f2e0(*(void **)(arg0 + (k % 10) * 4 + 0x12C4), palB[0], palB[1], palB[2], k, spC8, spCC);
        spC8 = spC8 - 22.0f;
        k = k / 10;
    }
    fA = 37.0f + (f22 + *(f32 *)(e2 + 0x594));
    spC8 = fA;
    spCC = 53.0f + (f21 + *(f32 *)(e2 + 0x598)) + f20;
    if ((s32)k >= 0) { fB = (f32)k; } else { fB = (f32)((k >> 1) | (k & 1)); fB = fB + fB; }
    fB = fB * fDiv;
    col8 = (u8)(u32)fB;
    func_0034f2e0(*(void **)(arg0 + 0x1330), spC8, spCC, ptab[0], ptab[1], ptab[2], col8);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ad40);
#endif
// FUN_0013B370
/* measured: family substitution reuses the exact 176-byte byte-color shape. */
#pragma opt_propagation off
void func_0013b370(u8 *arg0, s64 arg1, s32 arg2)
{
    f32 c0;
    s32 p;
    u32 c1;
    u8 c2;
    u8 c3;

    p = *(s32 *)(arg0 + 0x1288);
    c1 = ((u8 *)&arg2)[3];
    c2 = ((u8 *)&arg2)[2];
    c3 = ((u8 *)&arg2)[1];
    c0 = ((f32 *)&arg1)[1];
    func_0034f2e0((void *)p,
                  ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
    func_0034f2e0(*(void **)(arg0 + 0x128c),
                  340.0f + ((f32 *)&arg1)[0], c0,
                  ((u8 *)&arg2)[0], c3, c2, c1);
}
/* measured: close family opt_propagation bracket. */
#pragma opt_propagation on
/* measured 0013b420 (banked honest body: s64 two-float + s32 colour + s16* tail, recipe-A u8/u16->float, 204/255/24/5/34/325/340/22/54 constants with (f32)0x159 int form, 0034f320 x2 with 0.0f third float + 0034f2e0 x4 + 00113790 s64-tail + 002bc860 clamp-tail): measure_guarded 341 words obj 1364B/window 1488B; fnalign --candidate 304 edits, retail 369 vs object 341 instrs; opclass lbu -16 sb -12 lwc1 -7 swc1 -5 with cvt/mfc1 residue. Two validated findings: float->u8/u16 MUST be (u8/u16)(u32)x (unsigned lowering with the 2.147e9 check; signed form misses 6 checked sequences); the donor's opt_propagation off HURTS here (355 with, 341 without). Standing wall is frame 0xD0+7th saved/5th float vs retail 0xB0/6/4 with spill shift plus scheduling across 369 instrs. Production stays ASM. */
// FUN_0013B420 NONMATCHING
#ifdef NON_MATCHING
void func_0013b420(u8 *arg0, s64 arg1, s32 arg2, s16 *arg3) {
    f32 base2;
    f32 base;
    f32 c0;
    f32 c1;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 fw;
    f32 fw2;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 t0;
    u8 col;
    u16 hcol;
    u16 h1;
    u16 h2;
    u8 c2;
    base2 = ((f32 *)&arg1)[1];
    t0 = *(u8 *)(arg0 + 0);
    if ((s32)t0 >= 0) {
        c0 = (f32)t0;
    } else {
        c0 = 2.0f * (f32)((t0 >> 1) | (t0 & 1));
    }
    c1 = c0 / 255.0f;
    b0 = 0x14;
    b1 = 0x14;
    b2 = 0x14;
    fx = 204.0f * c1;
    col = (u8)(u32)fx;
    b3 = col;
    hcol = *(u16 *)(arg0 + 0xBAA);
    if ((s32)hcol >= 0) {
        fy = (f32)hcol;
    } else {
        fy = 2.0f * (f32)((hcol >> 1) | (hcol & 1));
    }
    base = ((f32 *)&arg1)[0];
    fz = base - 1.0f;
    fw = 24.0f + base2;
    h1 = (u16)(u32)fy;
    func_0034f320(*(u8 **)(arg0 + 0x1324), fz, fw, 0.0f, b0, b1, b2, b3, 0x1000, h1, 0, 0.0f, 0);
    h2 = (u16)(u32)fy;
    func_0034f320(*(u8 **)(arg0 + 0x1328), (f32)0x159 + fz, fw, 0.0f, b0, b1, b2, b3, 0x1000, h2, 0, 0.0f, 0);
    fz = 5.0f + base + *(f32 *)(arg0 + 0xC84);
    fw2 = 34.0f + base2 + *(f32 *)(arg0 + 0xC88);
    b0 = 0x68;
    b1 = 0x68;
    b2 = 0x68;
    if (arg2 >= 0) {
        c0 = (f32)arg2;
    } else {
        c0 = 2.0f * (f32)(((u32)arg2 >> 1) | (arg2 & 1));
    }
    fw = c0 * c1;
    col = (u8)(u32)fw;
    b3 = col;
    func_0034f2e0(*(u8 **)(arg0 + 0x131C), fz, fw2, b0, b1, b2, b3);
    func_0034f2e0(*(u8 **)(arg0 + 0x1320), 325.0f + fz, fw2, b0, b1, b2, b3);
    fz = base;
    b0 = D_0064B2E8[0];
    b1 = D_0064B2E8[1];
    b2 = D_0064B2E8[2];
    fx = 255.0f * c1;
    col = (u8)(u32)fx;
    b3 = col;
    func_0034f2e0(*(u8 **)(arg0 + 0x1288), fz, base2, b0, b1, b2, 0);
    func_0034f2e0(*(u8 **)(arg0 + 0x128C), 340.0f + fz, base2, b0, b1, b2, 0);
    fz = fz - 2.0f;
    func_00113790(*(s64 *)&fz, b3, arg3, 1, 0.0f);
    c2 = (u8)(u32)fw;
    fz = 22.0f + base;
    fw = 54.0f + base2;
    func_002bc860((s32)(0xFFFFFF00 | c2), 1, 8, *(u16 *)(arg3 + 0xA), (f32)(s32)fz, (f32)(s32)fw, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013b420);
#endif
static inline s32 code13GroupBefore(u8 *arg0, s32 index)
{
    u32 selected;
    selected = func_00106880(*(s16 *)(code13AddOff((index - 1) * 4, arg0) + 0x3E));
    index = index - 1;
    while (index > 0) {
        if (func_00106880(*(s16 *)(arg0 + index * 4 + 0x3A)) != selected) break;
        index--;
    }
    return index;
}
static inline s32 code13GroupBeforeOrSame(u8 *arg0, s32 total)
{
    if (total == 0) {
        return total;
    } else {
        return code13GroupBefore(arg0, total);
    }
}
static inline s32 code13GroupAfter(u8 *arg0, s32 total, s32 count, s32 wrap)
{
    s32 index;
    u32 selected;
    selected = func_00106880(*(s16 *)(code13AddOff(total * 4, arg0) + 0x3E));
    index = total + 1;
    while (index < count) {
        if (func_00106880(*(s16 *)(arg0 + index * 4 + 0x3E)) != selected) break;
        index++;
    }
    if (index >= count) index = wrap;
    return index;
}
/* The sum's inline boundary preserves the retail column-before-row loads. */
#pragma opt_propagation off
static inline s32 code13SelectionSum(s32 row, s32 column)
{
    return row + column;
}
// FUN_0013B9F0
s32 func_0013b9f0(u8 *arg0)
{
    s32 count;
    s32 index;
    s32 total;
    s32 low;
    s32 high;

    count = *(s16 *)(arg0 + 0xC3E);
    if (count < 2) return 0;
    {
        s32 column = *(s16 *)(arg0 + 0x24);
        s32 row = *(s16 *)(arg0 + 0x22);
        total = code13SelectionSum(row, column);
    }
    if (D_008C024E[0] & 4) {
        index = total;
        if (total == 0) index = count;
        index = code13GroupBefore(arg0, index);
        goto process;
    }
    if (D_008C024E[0] & 8) {
        index = code13GroupAfter(arg0, total, count, 0);
        goto process;
    }
    if (D_008C0252[0] & 4) {
        index = code13GroupBeforeOrSame(arg0, total);
        goto process;
    }
    if (D_008C0252[0] & 8) {
        index = code13GroupAfter(arg0, total, count, total);
        goto process;
    }
    return 0;
process:
    if (total == index) return 0;
    if (count < 7) {
        low = 0;
        high = (s16)index;
    } else {
        s32 threshold = count - 6;
        if (index >= threshold) {
            low = (s16)threshold;
            high = (s16)(index - low);
        } else {
            low = (s16)index;
            high = 0;
        }
    }
    func_0012ff40((s32)arg0, 0, (s16)high);
    func_0012ff40((s32)arg0, 1, (s16)low);
    return 1;
}
#pragma opt_propagation on
/* Matched.  Same menu-state-machine family as func_0013caa0, func_0013d8b0
   and func_00142f20: `*arg1 = (var_2 = 1)`, a switch on *arg0 whose arms
   break to a shared `return 0`, the fade arm returning 2, and a 0x30-byte
   query buffer.  Cases are written in retail layout order
   0,1,2,3,4,7,8,9,10,5,6,11; numeric order costs 82 words.  The s32 third
   parameter for func_0012ff40 gives retail's word loads (217 -> 2).  The
   party-slot address `(u8 *)((u8 *)(*(s16 *)(arg2 + 0x26) * 2) +
   (u32)arg2) + 0x34` gives retail's index-then-base addu.  The last two
   words were the argument setup order at the func_0013c700 call: with an
   s32 second parameter MWCC schedules the `lh` before the `move`, with
   s16 it emits retail's move-then-load, so the declaration above is
   load-bearing. */
// FUN_0013BCF0
s32 func_0013bcf0(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern s32 func_0012ff40(s32 arg0, s32 arg1, s32 arg2);
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_16;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_2;
    s32 var_3;
    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        *arg1 = 0;
        func_0012e2f0(arg2);
        *arg0 = 1;
        break;
    case 1:
        temp_16 = func_0012e8b0(arg2);
        if (temp_16 & func_0034c210()) {
            *arg0 = 3;
            func_0034bb20(0xB);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (func_00130600(arg2) != 0) {
            func_00130580(arg2);
            return 1;
        }
        break;
    case 3:
        if (func_00130600(arg2) != 0) {
            func_0012ff60(arg2, 3);
            *arg0 = 4;
            func_00353fe0();
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            func_0012ff60(arg2, 1);
            *arg0 = 2;
            func_00353fb0();
            func_0034bb20(0xD);
            func_0045af60(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            func_0013c5a0((s32 *)arg0, arg2);
            *(s32 *)(arg2 + 0xC44) = 0;
        } else if ((D_008C024E[0] & 0x80) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            func_0012ff60(arg2, 8);
            *arg0 = 5;
            *(s32 *)(arg2 + 0xC44) = 1;
            func_0045af60(0, 2, 0, 3);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xB;
        } else if (func_0013b9f0(arg2) != 0) {
            func_0045af60(0, 1, 0, 5);
        } else {
            func_00453670(buf, 6, *(s16 *)(arg2 + 0xC3E), *(s16 *)(arg2 + 0x22), *(s16 *)(arg2 + 0x24));
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_2 = func_00453960(buf)) > 0) {
                func_0012ff40((s32)arg2, 0, *(s32 *)(buf + 0x24));
                func_0012ff40((s32)arg2, 1, *(s32 *)(buf + 0x28));
                if (*(s16 *)(arg2 + 0x24) != *(s16 *)(arg2 + 0x2A)) {
                    func_00130360(arg2);
                }
                func_00354080(temp_2_2);
            }
        }
        break;
    case 7:
        if (func_00130600(arg2) != 0) {
            func_0012ff60(arg2, 6);
            func_001302d0(arg2);
            *arg0 = 8;
        }
        break;
    case 8:
        if (D_008C024E[0] & 0x20) {
            func_0012ff60(arg2, 2);
            *arg0 = 3;
            func_0034bd60(0xB);
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            if (func_0013c700(1, *(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x26) * 2) + (u32)arg2) + 0x34), arg2) == 2) {
                func_0012ff60(arg2, 2);
                *arg0 = 3;
                func_0034bd60(0xB);
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xB;
        } else {
            func_00453670(buf, 4, *(s16 *)(arg2 + 0x3C), *(s16 *)(arg2 + 0x26), 0);
            func_004538e0(buf, 0x4000, 0x1000, 0, 0);
            if (func_00453960(buf) != 0) {
                func_0012ff40((s32)arg2, 2, *(s32 *)(buf + 0x24));
                func_001302d0(arg2);
                func_0045af60(0, 1, 0, 0);
            }
        }
        break;
    case 9:
        if (func_00130600(arg2) != 0) {
            func_0012ff60(arg2, 7);
            *arg0 = 0xA;
        }
        break;
    case 10:
        if (D_008C024E[0] & 0x20) {
            func_0012ff60(arg2, 2);
            *arg0 = 3;
            func_0034bd60(0xB);
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            {
                s32 inner = func_0013c700(1, -1, arg2);
                switch (inner) {
                case 2:
                    func_0012ff60(arg2, 2);
                    *arg0 = 3;
                    func_0034bd60(0xB);
                    break;
                case 3:
                    return 2;
                default:
                    break;
                }
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xB;
        }
        break;
    case 5:
        if (func_00130600(arg2) != 0) {
            func_0012ff60(arg2, 9);
            *arg0 = 6;
        }
        break;
    case 6:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            func_0012ff60(arg2, 2);
            *arg0 = 3;
            func_0045af60(0, 2, 0, 4);
        } else if ((D_008C024E[0] & 0x40) && (*(s16 *)(arg2 + 0xC3E) > 0)) {
            func_0013c5a0((s32 *)arg0, arg2);
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xB;
        } else if (func_0013b9f0(arg2) != 0) {
            func_0045af60(0, 1, 0, 5);
        } else {
            func_00453670(buf, 6, *(s16 *)(arg2 + 0xC3E), *(s16 *)(arg2 + 0x22), *(s16 *)(arg2 + 0x24));
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_3 = func_00453960(buf)) > 0) {
                func_0012ff40((s32)arg2, 0, *(s32 *)(buf + 0x24));
                func_0012ff40((s32)arg2, 1, *(s32 *)(buf + 0x28));
                if (*(s16 *)(arg2 + 0x24) != *(s16 *)(arg2 + 0x2A)) {
                    func_00130360(arg2);
                }
                func_00354080(temp_2_3);
            }
        }
        break;
    case 11:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            var_2 = 1;
        } else {
            temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            var_3 = (u8)temp_f1;
            *(u8 *)arg2 = var_3;
            var_2 = 0;
        }
        if (var_2 != 0) {
            return 2;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_0013C5A0
void func_0013c5a0(s32 *arg0, u8 *arg1) {
    u8 *entry;
    s16 type;

    entry = code13AddOff((*(s16 *)(arg1 + 0x24) + *(s16 *)(arg1 + 0x22)) * 4,
                         arg1) + 0x3E;
    if (func_0013c6d0(*(s16 *)entry) == 0) {
        func_0045af60(0, 0, 0, 8);
        return;
    }
    type = (s16)func_0010f8c0(*(u16 *)(func_00106820(*(s16 *)entry) + 0x24));
    if (type == 0) {
        func_0012ff60(arg1, 4);
        func_001302d0(arg1);
        *arg0 = 7;
    } else {
        if ((type == 2) || (type == 1)) {
            func_0012ff60(arg1, 5);
            *arg0 = 9;
        }
    }
    func_0034bb20(0xC);
    func_0045af60(0, 0, 0, 1);
}
// FUN_0013C6D0
s32 func_0013c6d0(s16 arg0) {
    return func_0010f540(*(u16 *)(func_00106820() + 0x24)) != 0;
}
/* MATCHED: the same menu state machine as func_0013d8b0 beside it.  Nine of
   m2c's call arguments are stale registers - func_001312b0, func_001318c0,
   func_00134b60, func_00134be0, func_0013d5d0, func_0013d470,
   func_00452490 and two func_00134560 sites all take one fewer.  The two
   pick-list tests are `if ((n = func_00453960(buf)) > 0)`: assigning in
   the condition keeps the count in $v0 for the `blez`, where a separate
   statement moves it to a saved register first. */
// FUN_0013CAA0
s32 func_0013caa0(u32 *arg0, s32 *arg1, u8 *arg2) {
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_16;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_2;
    s32 var_3;

    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        *arg1 = 0;
        func_001312b0(arg2);
        *arg0 = 1;
        break;
    default:
        break;
    case 1:
        temp_16 = (s32)(func_001318c0(arg2));
        if (temp_16 & func_0034c210()) {
            *arg0 = 4;
            func_0034bb20(3);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        temp_4 = (s32)(*(s32 *)(arg2 + 0x1594));
        if ((temp_4 == 0) || (func_00452490(temp_4) == 0)) {
            *arg0 = 3;
            func_00134560(arg2, 1);
            func_00353fb0();
            func_0034bb20(7);
        case 3:
            if (func_00134b60(arg2) != 0) {
                func_00134ab0(arg2);
                return 1;
            }
            break;
        }
        break;
    case 4:
        if (func_00134b60(arg2) != 0) {
            func_00353fe0();
            func_00134560(arg2, 2);
            *arg0 = 5;
        }
        break;
    case 5:
        if (func_00134b60(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                *arg0 = 2;
                func_00134be0(arg2);
                func_0045af60(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                func_00134560(arg2, 3);
                *arg0 = 7;
                func_0034bb20(4);
                func_0045af60(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x10) {
                func_00134be0(arg2);
                *(s32 *)(arg2 + 0x10) = func_00354030();
                *arg0 = 0xD;
            } else {
                func_00453670(buf, 8, *(s16 *)(arg2 + 0x48), *(s16 *)(arg2 + 0x28), 0);
                func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                if (func_00453960(buf) != 0) {
                    func_001344b0(arg2, 0, *(s32 *)(buf + 0x24));
                    func_0045af60(0, 1, 0, 0);
                }
            }
        }
        break;
    case 6:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 4);
            *arg0 = 7;
        }
        break;
    case 7:
        if (D_008C024E[0] & 0x20) {
            func_001344b0(arg2, 1, 0);
            func_00134560(arg2, 2);
            *arg0 = 5;
            func_0034bd60(3);
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            func_00134560(arg2, 5);
            *arg0 = 8;
            func_0034bb20(5);
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xD;
        } else {
            func_00453670(buf, 3, 3, *(s16 *)(arg2 + 0x2A), 0);
            func_004538e0(buf, 0x4000, 0x1000, 0, 0);
            if (func_00453960(buf) != 0) {
                func_001344b0(arg2, 1, *(s32 *)(buf + 0x24));
                func_0045af60(0, 1, 0, 0);
            }
        }
        break;
    case 8:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 6);
            *arg0 = 9;
            func_0034bb20(6);
        }
        break;
    case 9:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 7);
            *arg0 = 0xA;
        }
        break;
    case 10:
        if (func_00134b60(arg2) != 0) {
            if (D_008C024E[0] & 0x40) {
                if (*(s16 *)(arg2 + 0xC46) != 0) {
                    func_0013d5d0(arg2);
                }
            } else if (D_008C024E[0] & 0x20) {
                func_001344b0(arg2, 2, 0);
                func_001344b0(arg2, 3, 0);
                func_00134560(arg2, 4);
                *arg0 = 6;
                func_0034bd60(4);
                func_0045af60(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                func_00134be0(arg2);
                *(s32 *)(arg2 + 0x10) = func_00354030();
                *arg0 = 0xD;
            } else if (D_008C024E[0] & 0x80) {
                if (*(s16 *)(arg2 + 0xC46) != 0) {
                    func_00134560(arg2, 8);
                    *arg0 = 0xB;
                    func_0045af60(0, 2, 0, 3);
                }
            } else if (func_0013d470(arg2, arg0) == 0) {
                func_00453670(buf, 5, *(s16 *)(arg2 + 0xC46), *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
                func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
                if ((temp_2_2 = func_00453960(buf)) > 0) {
                    func_001344b0(arg2, 2, *(s32 *)(buf + 0x28));
                    func_001344b0(arg2, 3, *(s32 *)(buf + 0x24));
                    if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                        func_00134890(arg2);
                    }
                    func_00354080(temp_2_2);
                }
            }
        }
        break;
    case 11:
        if (func_00134b60(arg2) != 0) {
            func_00134560(arg2, 9);
            *arg0 = 0xC;
        }
        break;
    case 12:
        if (D_008C024E[0] & 0x40) {
            if (func_0013d5d0(arg2) != 0) {
                *arg0 = 9;
            }
        } else if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            func_00134560(arg2, 7);
            *arg0 = 9;
            func_0045af60(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x10) {
            func_00134be0(arg2);
            *(s32 *)(arg2 + 0x10) = func_00354030();
            *arg0 = 0xD;
        } else if (func_0013d470(arg2, arg0) == 0) {
            func_00453670(buf, 5, *(s16 *)(arg2 + 0xC46), *(s16 *)(arg2 + 0x2E), *(s16 *)(arg2 + 0x2C));
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((temp_2_3 = func_00453960(buf)) > 0) {
                func_001344b0(arg2, 2, *(s32 *)(buf + 0x28));
                func_001344b0(arg2, 3, *(s32 *)(buf + 0x24));
                if (*(s16 *)(arg2 + 0x2C) != *(s16 *)(arg2 + 0x34)) {
                    func_00134890(arg2);
                }
                func_00354080(temp_2_3);
            }
        }
        break;
    case 13:
        temp_4_2 = (s32)(*(s32 *)(arg2 + 0x1594));
        if ((temp_4_2 == 0) || (func_00452490(temp_4_2) == 0)) {
            if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
                var_2 = 1;
            } else {
                temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
                var_3 = (u8)temp_f1;
                *(u8 *)arg2 = var_3;
                var_2 = 0;
            }
            if (var_2 != 0) {
                return 2;
            }
            break;
        }
        break;
    }
    return 0;
}
/* State-machine floor (864B window; P1 obj 852B fndiff 135 fnalign 95 plus 4 reloc-only,
   retail 214/object 213 (1 short, 0.5% within 3%, words+edits improve); P1 lever 2026-09-17:
   correct func_00106620 to truthful (s32,s32) via block extern (g_data.c MATCH), 150->135/98->95.
   Widened s32 base kept (single-narrow sweeps all worse: total 171, remaining 158, entry 157,
   updated 159, index 158, count 159, state 161; itemOnly 153, typeOnly 154, truthful hybrid 153).
   Ruled out: E1 recompute 156, P3 decl 150 neutral, P4 RMW 158 (00215c10 lever does not transfer),
   P5 u16 150 neutral, P2 s16-pair 134 untruthful (true type u16, edits 129 worse). Pragmas on widened:
   schedule 178 worse, cse_off 159 worse, loopinv 177->168 kept. Open: s-reg rotation, index-arith,
   call-sequence alignment. See V013_0013c700_body.c for ruled-out variants. */
/* measured 0013c700: `opt_loop_invariants on` inside the guard is worth 9 words (177 -> 168), the loop-preheader constant hoist. */
// FUN_0013C700 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
/* measured: object 880B, retail window 864B, normalized_diff 177, differing offsets 48-88,100-136,144-180,188-232,240-288,296-344,352-432,440-876; archived immediately because object exceeded retail window; ruled out corrected callee declarations, pointer-vs-array entry staging, state switch shape, and direct generated-loop reconstruction */
s32 func_0013c700(s32 arg0, s16 arg1, u8 *arg2)
{
    extern void func_00106390(s32 arg0, s32 arg1);
    extern void func_0010f770(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
    extern void func_0012e7c0(u8 *arg0);
    extern s32 func_0012ff40(s32 arg0, s32 arg1, s16 arg2);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern u8 D_005ED9D0[];
    extern s32 func_00354010(void);
    extern void func_00106620(s32 arg0, s32 arg1);
    s32 state;
    s32 index_count;
    s32 index;
    s32 item;
    s32 item_type;
    s32 entry_index;
    s32 remaining;
    s32 total;
    s32 updated;
    u8 *entry;

    state = 1;
    total = *(s16 *)(arg2 + 0x24) + *(s16 *)(arg2 + 0x22);
    item = *(s16 *)(arg2 + total * 4 + 0x3E);
    item_type = *(u16 *)(func_00106820(item) + 0x24);
    if (item_type == 246) {
        if (func_00354010() != 0) state = 3;
        else state = 0;
    } else if (arg1 == -1) {
        index_count = 0;
        index = 0;
        while (index < *(s16 *)(arg2 + 0x3C)) {
            entry = arg2 + index * 2 + 0x34;
            if (func_0013ca60(arg0, *(s16 *)entry, item_type) != 0) {
                func_0010f770((s16)arg0, *(s16 *)entry, item_type, 1);
                index_count++;
            }
            index++;
        }
        if (index_count == 0) state = 0;
    } else if (func_0013ca60(arg0, arg1, item_type) != 0) {
        func_0010f770((s16)arg0, arg1, item_type, 1);
    } else state = 0;
    if (state > 0) {
        updated = (s16)(func_00106600(item) & 0xff) - 1;
        if (updated < 0) func_0046d730(D_005ED9D0, 0x29c);
        func_00106620(item, updated & 0xff);
        if (state != 3) {
            func_00130430(arg2);
            entry_index = total;
            entry = arg2 + entry_index * 4;
            remaining = *(s16 *)(entry + 0x40) - 1;
            *(s16 *)(entry + 0x40) = remaining;
            if (remaining == 0) {
                func_0012e7c0(arg2);
                total = *(s16 *)(arg2 + 0xc3e);
                if (total < 6) {
                    func_0012ff40((s32)arg2, 1, 0);
                    total = *(s16 *)(arg2 + 0xc3e) - 1;
                    if (total < *(s16 *)(arg2 + 0x22)) func_0012ff40((s32)arg2, 0, total);
                } else {
                    total -= 6;
                    if (total < *(s16 *)(arg2 + 0x24)) func_0012ff40((s32)arg2, 1, total);
                }
                state = 2;
            }
        } else func_00106390(5121, 1);
    }
    if (state == 3) return state;
    if (state == 2 || state == 1) func_0045af60(1, 3, 2, 22);
    else if (state == 0) func_0045af60(0, 0, 0, 8);
    else func_0046d730(D_005ED9D0, 0x2ca);
    return state;
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013c700);
#endif
// FUN_0013CA60
s32 func_0013ca60(s32 arg0, s32 arg1, s32 arg2) {
    s32 v = 0;

    if (func_0010f930(arg0, arg1, arg2, 1) == 0) {
        v = 1;
    }
    return v;
}
// FUN_0013D470
s32 func_0013d470(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    func_00453670(sp40, 8, *(s16 *)(arg0 + 0x48), *(s16 *)(arg0 + 0x28), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_001344b0(arg0, 0, *(s32 *)(sp40 + 0x24));
        func_001344b0(arg0, 3, 0);
        func_001344b0(arg0, 2, 0);
        func_00131730(arg0);
        func_00134560(arg0, 7);
        *arg1 = 0xA;
        if (temp_2 == 1) {
            func_00134a50(arg0);
        } else if (temp_2 == 2) {
            func_001349f0(arg0);
        }
        func_0045af60(0, 1, 0, 5);
        return 1;
    }
    return 0;
}
// FUN_0013D5D0
s32 func_0013d5d0(u8 *arg0) {
    struct {
        s16 value;
    } temp_16;
    s16 temp_19;
    s16 temp_18;
    s16 temp_2;
    s32 temp_6;
    s32 temp_6_2;
    s16 temp_17;

    temp_18 = *(s16 *)(code13AddOff(*(s16 *)(arg0 + 0x28) * 2, arg0) + 0x38);
    temp_19 = *(s16 *)(code13AddOff((*(s16 *)(arg0 + 0x2C) +
                                     *(s16 *)(arg0 + 0x2E)) * 4, arg0) + 0x4A);
    temp_16.value = *(s16 *)(arg0 + 0x2A);
    temp_17 = (s16)func_00106cd0(temp_18, temp_16.value);
    if (temp_19 == temp_17) {
        func_0045af60(0, 0, 0, 8);
        return 0;
    }
    func_00134560(arg0, 7);
    func_00134990(arg0, temp_17, temp_19);
    if ((func_00106600(temp_17) & 0xFF) != 0x63) {
        func_00106620(temp_17, ((func_00106600(temp_17) & 0xFF) + 1) & 0xFF);
    }
    func_00106d40(temp_18, temp_16.value, temp_19);
    func_00106620(temp_19, ((func_00106600(temp_19) & 0xFF) - 1) & 0xFF);
    func_00131730(arg0);
    temp_2 = *(s16 *)(arg0 + 0xC46);
    if (temp_2 < 5) {
        func_001344b0(arg0, 2, 0);
        temp_6 = *(s16 *)(arg0 + 0xC46) - 1;
        if (temp_6 < *(s16 *)(arg0 + 0x2E)) {
            func_001344b0(arg0, 3, temp_6);
        }
    } else {
        temp_6_2 = temp_2 - 5;
        if (temp_6_2 < *(s16 *)(arg0 + 0x2C)) {
            func_001344b0(arg0, 2, temp_6_2);
        }
    }
    func_0045af60(0, 3, 0, 7);
    return 1;
}
// FUN_0013D7D0
void func_0013d7d0(u8 *arg0, s32 arg1) {
    code13Pair sp0;
    code13Pair sp1;

    switch (arg1) {
    case 0:
        sp0.first = 0x43030000;
        sp0.second = 0xC26C0000;
        func_0011d080(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        func_0011d0d0(*(u8 **)(arg0 + 0x1CB4), &sp0);
        func_0011d170(*(u8 **)(arg0 + 0x1CB4), -1, -0x7F00);
        return;
    case 1:
        sp1.first = 0x43030000;
        sp1.second = 0xC2600000;
        func_0011d0a0(*(u8 **)(arg0 + 0x1CB4), 0x400E0);
        func_0011d0d0(*(u8 **)(arg0 + 0x1CB4), &sp1);
        func_0011d170(*(u8 **)(arg0 + 0x1CB4), -1, 0xFFE92C00);
        return;
    }
}
/* MATCHED: the same menu state machine as func_0035e8b0, func_0035f0c0 and
   func_003627b0 - `*arg1 = (var_2 = 1);`, a switch on *arg0 whose arms break
   to a shared `return 0`, the fade arm returning 2, and a 0x30-byte query
   buffer whose result is read at +0x24.  Two spellings did the rest: the
   party-slot address is `(u8 *)(index * 2) + (u32)arg2`, which gives
   retail's index-then-base `addu`, and the two func_002bb140 switches are
   written `case 0:` before `case 1:` so their compare chains come out
   1-then-0.  m2c's `&jtbl_00746A80` arguments to func_0010b7f0 and
   func_00354030 are stale registers; both take none. */
// FUN_0013D8B0
s32 func_0013d8b0(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern void func_0013e7c0(u8 *arg0, s32 *arg1);
    extern void func_001356d0(u8 *arg0);
    extern s32 func_00135cb0(u8 *arg0);
    extern s32 func_00137dd0(u8 *arg0);
    extern void func_001377e0(u8 *arg0);
    extern void func_001371a0(u8 *arg0, s32 arg1);
    extern void func_00355190(u8 *arg0, s32 arg1);
    extern void func_00137e50(u8 *arg0, s32 a, s32 b, s32 c);
    extern void func_0011b480(u8 *arg0, u32 a, s32 b, s32 c);
    extern void func_001374d0(u8 *arg0);
    extern void func_00137570(u8 *arg0);
    extern void func_001370e0(u8 *arg0);
    extern void func_0011bb90(u8 *arg0);
    extern void func_0013d7d0(u8 *arg0, s32 arg1);
    extern s32 func_0010ace0(s32 arg0);
    extern s32 func_0010a900(s32 arg0);
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s16 temp_17;
    s16 temp_3_2;
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_2;
    s32 var_3;

    *arg1 = (var_2 = 1);
    switch (*arg0) {
    case 0:
        func_001356d0(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        temp_16 = (s32)(func_00135cb0(arg2));
        if (temp_16 & func_0034c210()) {
            *arg0 = 3;
            func_0034bb20(0xE);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (func_00137dd0(arg2) != 0) {
            func_001377e0(arg2);
            return 1;
        }
        break;
    case 3:
        if (func_00137dd0(arg2) != 0) {
            func_001371a0(arg2, 2);
            *arg0 = 4;
            func_00353fe0();
            func_00355190(*(u8 **)(arg2 + 0x1CB8), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24));
            func_00137e50(*(u8 **)(arg2 + 0x1CB8), 0, 1, 0);
            func_0011b480(*(u8 **)(arg2 + 0x1CB4), 0U, 0, 0);
        }
        break;
    case 4:
        if (func_00137dd0(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                func_001371a0(arg2, 1);
                *arg0 = 2;
                func_00353fb0();
                func_0034bb20(0x14);
                func_00137e50(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                func_0045af60(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (*(s16 *)(arg2 + 0x50) == 0) {
                    func_001371a0(arg2, 3);
                    *arg0 = 5;
                    func_00136fa0(arg2, 1, 0);
                    func_001374d0(arg2);
                    func_00137570(arg2);
                    func_001370e0(arg2);
                    func_0034bb20(0xF);
                    func_00137e50(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                    func_0011b480(*(u8 **)(arg2 + 0x1CB4), 1U, func_0010ace0(*(s16 *)(arg2 + 0x52)), 0);
                    func_0013d7d0(arg2, 1);
                    func_0011d0d0(*(u8 **)(arg2 + 0x1CB4), NULL);
                    func_0011d080(*(u8 **)(arg2 + 0x1CB4), 0x40000);
                    func_0045af60(0, 0, 0, 1);
                } else {
                    func_001371a0(arg2, 8);
                    *arg0 = 0xA;
                    func_001374d0(arg2);
                    func_0034bb20(0x11);
                    func_00137e50(*(u8 **)(arg2 + 0x1CB8), 0, 0, 1);
                    func_0013d7d0(arg2, 0);
                    func_0011b480(*(u8 **)(arg2 + 0x1CB4), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24), func_0010a900(*(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24)), 0);
                    func_0011bb90(*(u8 **)(arg2 + 0x1CB4));
                    func_0011d0a0(*(u8 **)(arg2 + 0x1CB4), 0x40000);
                }
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = func_00354030();
                *arg0 = 0x10;
            } else {
                func_00453670(buf, 8, *(s16 *)(arg2 + 0x34), *(s16 *)(arg2 + 0x50), 0);
                func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                if (func_00453960(buf) != 0) {
                    func_00136fa0(arg2, 0, *(s32 *)(buf + 0x24));
                    func_00355190(*(u8 **)(arg2 + 0x1CB8), *(u16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x50) * 2) + (u32)arg2) + 0x24));
                    func_0045af60(0, 1, 0, 0);
                }
            }
        }
        break;
    case 5:
        if (func_00137dd0(arg2) != 0) {
            func_001371a0(arg2, 4);
            *arg0 = 6;
            func_00137570(arg2);
            func_00355190(*(u8 **)(arg2 + 0x1CB8), 0U);
        }
        break;
    case 6:
        if (D_008C024E[0] & 0x20) {
            func_001371a0(arg2, 2);
            *arg0 = 3;
            func_0034bd60(0xE);
            func_0010b7f0();
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x40) {
            func_0010b3b0(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
            func_0045af60(1, 3, 2, 6);
            func_001375f0(arg2);
        } else if (D_008C024E[0] & 0x80) {
            func_0013d7d0(arg2, 0);
            func_0011bb90(*(u8 **)(arg2 + 0x1CB4));
            func_001371a0(arg2, 6);
            func_00137740(arg2);
            *arg0 = 7;
            func_0034bb20(0x10);
        } else if (D_008C024E[0] & 0x10) {
            temp_17 = (s16)(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
            if (temp_17 == func_00105330(1)) {
                func_002bad10(2);
                func_001371a0(arg2, 0xC);
                *arg0 = 0xF;
                func_0045af60(0, 0, 0, 8);
            } else {
                func_002bad10(1);
                func_002baf40(0);
                func_002bb050(1);
                func_002bbf60();
                func_001371a0(arg2, 0xB);
                *arg0 = 0xE;
                func_0045af60(0, 0, 0, 1);
            }
            func_00137570(arg2);
        } else {
            func_00453670(buf, 0xC, *(s16 *)(arg2 + 0x4E), *(s16 *)(arg2 + 0x52), 0);
            func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if (func_00453960(buf) != 0) {
                func_00136fa0(arg2, 1, *(s32 *)(buf + 0x24));
                func_00137570(arg2);
                func_0011b480(*(u8 **)(arg2 + 0x1CB4), 1U, func_0010ace0(*(s16 *)(arg2 + 0x52)), 0);
                func_0045af60(0, 1, 0, 0);
            }
        }
        break;
    case 7:
        if (func_00137dd0(arg2) != 0) {
            *arg0 = 8;
            func_001371a0(arg2, 7);
        }
        break;
    case 8:
        if (func_00137dd0(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                func_001371a0(arg2, 5);
                *arg0 = 5;
                func_00137570(arg2);
                func_0034bd60(0xF);
                func_0011bc70(*(u8 **)(arg2 + 0x1CB4));
                func_0013d7d0(arg2, 1);
            } else if (D_008C024E[0] & 0x40) {
                func_001371a0(arg2, 0xA);
                func_002bad10(3);
                func_002baf40(0);
                func_002bb050(0);
                func_002bbf60();
                *arg0 = 0xD;
                func_0045af60(0, 0, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                func_0011c630(*(u8 **)(arg2 + 0x1CB4));
                *arg0 = 9;
            } else if (D_008C024E[0] & 0x10) {
                func_0010b7f0();
                *(s32 *)(arg2 + 0x10) = func_00354030();
                func_0011b360(*(u8 **)(arg2 + 0x1CB4));
                func_00117580(*(u8 **)(arg2 + 0x1CB4), 0xB1);
                *arg0 = 0x10;
            } else {
                func_0013e7c0(arg2, (s32 *)arg0);
            }
        }
        break;
    case 9:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            func_0011c6e0(*(u8 **)(arg2 + 0x1CB4), 1);
            *arg0 = 8;
        } else if (D_008C024E[0] & 0x40) {
            func_001371a0(arg2, 0xA);
            func_0011c6e0(*(u8 **)(arg2 + 0x1CB4), 0);
            func_002bad10(3);
            func_002baf40(0);
            func_002bb050(0);
            func_002bbf60();
            *arg0 = 0xD;
            func_0045af60(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x10) {
            func_0010b7f0();
            *(s32 *)(arg2 + 0x10) = func_00354030();
            func_0011b360(*(u8 **)(arg2 + 0x1CB4));
            func_00117580(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else {
            func_0011caf0(*(u8 **)(arg2 + 0x1CB4));
            func_0013e7c0(arg2, (s32 *)arg0);
        }
        break;
    case 10:
        if (func_00137dd0(arg2) != 0) {
            *arg0 = 0xB;
            func_001371a0(arg2, 7);
            func_00355190(*(u8 **)(arg2 + 0x1CB8), 0U);
        }
        break;
    case 11:
        if (D_008C024E[0] & 0x20) {
            func_001371a0(arg2, 2);
            *arg0 = 3;
            func_0034bd60(0xE);
            func_0011bc70(*(u8 **)(arg2 + 0x1CB4));
        } else if (D_008C024E[0] & 0x80) {
            func_0011c630(*(u8 **)(arg2 + 0x1CB4));
            *arg0 = 0xC;
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            func_0011b360(*(u8 **)(arg2 + 0x1CB4));
            func_00117580(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else {
            func_0013e8e0(arg2, arg0);
        }
        break;
    case 12:
        if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
            func_0011c6e0(*(u8 **)(arg2 + 0x1CB4), 1);
            *arg0 = 0xB;
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = func_00354030();
            func_0011b360(*(u8 **)(arg2 + 0x1CB4));
            func_00117580(*(u8 **)(arg2 + 0x1CB4), 0xB1);
            *arg0 = 0x10;
        } else if (func_0013e8e0(arg2, arg0) == 0) {
            func_0011caf0(*(u8 **)(arg2 + 0x1CB4));
        }
        break;
    case 13:
        if ((func_00137dd0(arg2) != 0) && (func_00353f50(1) == 0)) {
            temp_2 = func_002bb140();
            switch (temp_2) {
            case 0:
                func_0010b3b0(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
                func_0045af60(1, 3, 2, 6);
                break;
            case 1:
                break;
            default:
                func_0046d730(D_005ED9E0, 0x220);
                break;
            }
            *arg0 = 7;
        }
        break;
    case 14:
        if ((func_00137dd0(arg2) != 0) && (func_00353f50(1) == 0)) {
            temp_2_2 = func_002bb140();
            switch (temp_2_2) {
            case 0:
                func_0010ae30(*(s16 *)((u8 *)((u8 *)(*(s16 *)(arg2 + 0x52) * 2) + (u32)arg2) + 0x36));
                func_00135c10(arg2);
                temp_3_2 = (s16)(*(s16 *)(arg2 + 0x4E));
                if (*(s16 *)(arg2 + 0x52) >= temp_3_2) {
                    func_00136fa0(arg2, 1, temp_3_2 - 1);
                }
                func_0011b480(*(u8 **)(arg2 + 0x1CB4), 1U, func_0010ace0(*(s16 *)(arg2 + 0x52)), 0);
                break;
            case 1:
                break;
            default:
                func_0046d730(D_005ED9E0, 0x244);
                break;
            }
            func_00137570(arg2);
            *arg0 = 5;
        }
        break;
    case 15:
        if (func_00353f50(1) == 0) {
            func_00137570(arg2);
            *arg0 = 5;
        }
        break;
    case 16:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            var_2 = 1;
        } else {
            temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            var_3 = (u8)temp_f1;
            *(u8 *)arg2 = var_3;
            var_2 = 0;
        }
        if (var_2 != 0) {
            return 2;
        }
        break;
    default:
        func_0046d730(D_005ED9E0, 0x25C);
        break;
    }
    return 0;
}
// FUN_0013E7C0
void func_0013e7c0(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;

    func_00453670(sp40, 0xC, *(s16 *)(arg0 + 0x4E), *(s16 *)(arg0 + 0x52), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_00136fa0(arg0, 1, *(s32 *)(sp40 + 0x24));
        *arg1 = 8;
        if (temp_2 == 1) {
            func_0011c2c0(*(s32 *)(arg0 + 0x1CB4), 1, func_0010ace0(*(s16 *)(arg0 + 0x52)), 0);
            return;
        }
        if (temp_2 == 2) {
            func_0011c180(*(s32 *)(arg0 + 0x1CB4), 1, func_0010ace0(*(s16 *)(arg0 + 0x52)), 0);
        }
    }
}
// FUN_0013E8E0
s32 func_0013e8e0(u8 *arg0, s32 *arg1) {
    u8 sp40[0x28];
    s32 temp_2;
    s32 temp_18;

    func_00453670(sp40, 8, *(s16 *)(arg0 + 0x34), *(s16 *)(arg0 + 0x50), 0);
    func_00453760(sp40, 0);
    func_004538e0(sp40, 8, 4, 0, 0);
    temp_2 = func_00453960(sp40);
    if (temp_2 > 0) {
        func_00136fa0(arg0, 0, *(s32 *)(sp40 + 0x24));
        *arg1 = 0xB;
        temp_18 = *(u16 *)(code13AddOff(*(s32 *)(sp40 + 0x24) * 2, arg0) + 0x24);
        if (temp_2 == 1) {
            func_0011c2c0(*(s32 *)(arg0 + 0x1CB4), temp_18, func_0010a900(temp_18), 0);
        } else if (temp_2 == 2) {
            func_0011c180(*(s32 *)(arg0 + 0x1CB4), temp_18, func_0010a900(temp_18), 0);
        }
        return 1;
    }
    return 0;
}
/* Floor: 402 differing words (was 473) over 73 edits plus 12 reloc-only (was 88+12),
   689 emitted against retail 684 (was 693, 9 long now 5 long; obj 2756B/window 2736B
   verify 1260, was 1514/2772). Same menu-state-machine family as func_0013caa0 and
   func_0013d8b0; m2c seven-arg calls are stale registers. Width win 2026-09-17: six s16
   slot/index temps -> s32 deletes 16 spurious dsll/dsra pairs (obj 20->0, retail 4),
   473->402. Pragmas on widened: schedule 554 worse, cse_off 547 worse, loopinv 402 neutral.
   WALL: inner-switch 0/1 arms via shared exit vs direct, $s0/$s1 colour swap on slot indices.
*/
// FUN_0013EA20 NONMATCHING
#ifdef NON_MATCHING
s32 func_0013ea20(u32 *arg0, s32 *arg1, u8 *arg2) {
    extern void func_00137fb0(u8 *arg0);
    extern s32 func_00138ad0(u8 *arg0);
    extern s32 func_0013abb0(u8 *arg0);
    extern void func_0013ab30(u8 *arg0);
    extern void func_0013a8a0(u8 *arg0);
    extern void func_0013a930(u8 *arg0);
    extern void func_0013f4d0(s32 *arg0, s16 arg1, s32 arg2, u8 *arg3);
    u8 buf[0x30];
    f32 temp_f1;
    f32 var_f1;
    s32 temp_17;
    s32 temp_2;
    s32 temp_3;
    s32 temp_7;
    s32 temp_8;
    s32 temp_9;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_10;
    s64 temp_3_2;
    s64 temp_3_3;
    s32 var_3;
    u16 temp_5_3;
    u16 temp_5_4;

    *arg1 = (var_10 = 1);
    temp_7 = (*(s16 *)(arg2 + 0x5C));
    temp_17 = (*(s16 *)(((u8 *)(temp_7 * 2) + (u32)arg2 + 0xF4)));
    temp_9 = (*(s16 *)(arg2 + 0x62));
    temp_3 = (*(s16 *)(((u8 *)(temp_9 * 2) + (u32)arg2 + 0xF4)));
    temp_2 = (*(s16 *)(arg2 + 0x5E));
    temp_8 = (*(s16 *)(arg2 + 0x60));
    temp_16 = temp_8 + temp_2;
    switch (*arg0) {
        case 0:
            *arg1 = 0;
            func_00137fb0(arg2);
            *arg0 = 1;
            break;
        case 1:
            temp_16_2 = (func_00138ad0(arg2));
            if (temp_16_2 & func_0034c210()) {
                *arg0 = 3;
                func_0034bb20(8);
                func_0013a8a0(arg2);
            } else {
                *arg1 = 0;
            }
            break;
        case 2:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                func_0013ab30(arg2);
                return 1;
            }
            break;
        case 3:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                func_00353fe0();
                *arg0 = 4;
                func_0013a530(arg2, 2U);
                func_0013a8a0(arg2);
            }
            break;
        case 4:
            if (D_008C024E[0] & 0x20) {
                func_0013a530(arg2, 1U);
                *arg0 = 2;
                func_00353fb0();
                func_0034bb20(0xA);
                func_0045af60(0, 2, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if ((s32)(func_00105610(temp_17)) != (s32)(0)) {
                    func_0045af60(0, 0, 0, 8);
                } else {
                    func_0013a530(arg2, 3U);
                    *arg0 = 5;
                    func_0045af60(0, 0, 0, 1);
                }
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = (s32)(func_00354030());
                *arg0 = 0xD;
            } else {
                func_00453670(buf, 4, *(s16 *)(arg2 + 0xFC), temp_7, 0, temp_9, 1);
                func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                if ((s32)(func_00453960(buf)) != (s32)(0)) {
                    func_0013a040(arg2, 0, *(s32 *)(buf + 0x24));
                    func_00138490(arg2);
                    func_0013a8a0(arg2);
                    func_0045af60(0, 1, 0, 0);
                }
            }
            break;
        case 5:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                *arg0 = 6;
                func_0013a530(arg2, 4U);
            }
            break;
        case 6:
            if (D_008C024E[0] & 0x20) {
                *arg0 = 3;
                func_0013a530(arg2, 2);
                func_0013a8a0(arg2);
                func_0045af60(0, 0, 0, 2);
            } else {
                temp_5_3 = D_008C024E[0] & 0x40;
                if (temp_5_3 != 0) {
                    func_0013f4d0((s32 *)arg0, temp_17, temp_3, arg2);
                } else if (D_008C024E[0] & 0x80) {
                    func_0013a530(arg2, 9);
                    *arg0 = 0xB;
                    func_0045af60(0, 2, 0, 3);
                } else if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(func_00354030());
                    *arg0 = 0xD;
                } else {
                    func_00453670(buf, 6, *(s16 *)(arg2 + 0x580), temp_2, temp_8, temp_9, 1);
                    func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
                    temp_2_2 = (s32)(func_00453960(buf));
                    if (temp_2_2 > 0) {
                        func_0013a040(arg2, 1, *(s32 *)(buf + 0x24));
                        func_0013a040(arg2, 2, *(s32 *)(buf + 0x28));
                        if (*(s16 *)(arg2 + 0x60) != *(s16 *)(arg2 + 0xAC)) {
                            func_0013a930(arg2);
                        }
                        func_00354080(temp_2_2);
                    }
                }
            }
            break;
        case 7:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                func_0013a530(arg2, 6U);
                func_0013aa00(arg2);
                *arg0 = 8;
            }
            break;
        case 8:
            if (D_008C024E[0] & 0x20) {
                func_0013a530(arg2, 3U);
                *arg0 = 5;
                func_0034bd60(8);
                func_0045af60(0, 0, 0, 2);
                break;
            }
            if (D_008C024E[0] & 0x40) {
                temp_3_2 = (s64)((s64) (func_0013f720(temp_17, temp_3, temp_16, arg2, temp_8, temp_9, 1) << 0x38) >> 0x38);
                switch (temp_3_2) {
                case 0:
                case 1:
                    break;
                case 2:
                    func_0013a530(arg2, 3U);
                    *arg0 = 5;
                    func_0034bd60(8);
                    break;
                case 3:
                    return 2;
                }
            } else {
                if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(func_00354030());
                    *arg0 = 0xD;
                } else {
                    func_00453670(buf, 4, *(s16 *)(arg2 + 0xFC), temp_9, 0, temp_9, 1);
                    func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                    if ((s32)(func_00453960(buf)) != (s32)(0)) {
                        func_0013a040(arg2, 3, *(s32 *)(buf + 0x24));
                        func_0013aa00(arg2);
                        func_0045af60(0, 1, 0, 0);
                    }
                }
                break;
            }
            break;
        case 9:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                func_0013a530(arg2, 8U);
                *arg0 = 0xA;
            }
            break;
        case 10:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                if (D_008C024E[0] & 0x20) {
                    func_0013a530(arg2, 3U);
                    *arg0 = 5;
                    func_0034bd60(8);
                    func_0045af60(0, 0, 0, 2);
                    break;
                }
                if (D_008C024E[0] & 0x40) {
                    temp_3_3 = (s64)((s64) (func_0013f720(temp_17, -1, temp_16, arg2) << 0x38) >> 0x38);
                    switch (temp_3_3) {
                    case 0:
                    case 1:
                        break;
                    case 2:
                        func_0013a530(arg2, 3U);
                        *arg0 = 5;
                        func_0034bd60(8);
                        break;
                    case 3:
                        return 2;
                    }
                } else {
                    if (D_008C024E[0] & 0x10) {
                        *(s32 *)(arg2 + 0x10) = (s32)(func_00354030());
                        *arg0 = 0xD;
                    }
                    break;
                }
            } else {
                break;
            }
            break;
        case 11:
            if ((s32)(func_0013abb0(arg2)) != (s32)(0)) {
                func_0013a530(arg2, 0xAU);
                *arg0 = 0xC;
            }
            break;
        case 12:
            if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80)) {
                func_0013a530(arg2, 3);
                *arg0 = 5;
                func_0045af60(0, 2, 0, 4);
            } else {
                temp_5_4 = D_008C024E[0] & 0x40;
                if (temp_5_4 != 0) {
                    func_0013f4d0((s32 *)arg0, temp_17, temp_3, arg2);
                } else if (D_008C024E[0] & 0x10) {
                    *(s32 *)(arg2 + 0x10) = (s32)(func_00354030());
                    *arg0 = 0xD;
                } else {
                    func_00453670(buf, 6, *(s16 *)(arg2 + 0x580), temp_2, temp_8, temp_9, 1);
                    func_004538e0(buf, 0x4000, 0x1000, 0x2000, 0x8000);
                    temp_2_3 = (s32)(func_00453960(buf));
                    if (temp_2_3 > 0) {
                        func_0013a040(arg2, 1, *(s32 *)(buf + 0x24));
                        func_0013a040(arg2, 2, *(s32 *)(buf + 0x28));
                        if (*(s16 *)(arg2 + 0x60) != *(s16 *)(arg2 + 0xAC)) {
                            func_0013a930(arg2);
                        }
                        func_00354080(temp_2_3);
                    }
                }
            }
            break;
        case 13:
            if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
                var_10 = 1;
            } else {
                temp_f1 = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
                var_3 = (u8)temp_f1;
                *(u8 *)arg2 = var_3;
                var_10 = 0;
            }
            if (var_10 != 0) {
                return 2;
            }
            break;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013ea20);
#endif
// FUN_0013F4D0
void func_0013f4d0(s32 *arg0, s16 arg1, s32 arg2, u8 *arg3) {
    s32 temp_18;
    u16 temp_3;

    temp_18 = *(s16 *)(arg3 + 0x60) + *(s16 *)(arg3 + 0x5E);
    if (func_0013f620(arg1, temp_18, arg3) == 0) {
        func_0045af60(0, 0, 0, 8);
        return;
    }
    temp_3 = func_0010f8c0(*(u16 *)(code13AddOff(temp_18 * 0xC, arg3) + 0x102)) & 0xFFFF;
    if (temp_3 == 0) {
        func_0013a040(arg3, 3, 0);
        func_0013a530(arg3, 5);
        func_0013aa00(arg3);
        if (arg0 != 0) {
            *arg0 = 7;
        }
    } else {
        if ((temp_3 == 2) || (temp_3 == 1)) {
            func_0013a530(arg3, 7);
            if (arg0 != 0) {
                *arg0 = 9;
            }
        }
    }
    func_0034bb20(9);
    func_0045af60(0, 0, 0, 1);
}
// FUN_0013F620
s32 func_0013f620(s16 arg0, s32 arg1, u8 *arg2) {
    s32 var_19;
    s16 var_18;
    s16 temp_17;
    u16 temp_16;
    u8 *temp_2;

    var_19 = 1;
    var_18 = -1;
    temp_2 = code13AddOff(arg1 * 0xC, arg2);
    temp_16 = *(u16 *)(temp_2 + 0x102);
    temp_17 = *(s16 *)(temp_2 + 0x100);
    if (func_0010f540(temp_16) == 0) {
        return 0;
    }
    if (temp_17 != -1) {
        var_18 = (s16)func_0010b510();
        func_0010b3b0(temp_17);
    }
    if (func_0010f6a0(arg0, temp_16) != 0) {
        var_19 = 0;
    }
    if (var_18 != -1) {
        func_0010b3b0(var_18);
    }
    return var_19;
}
/* Model floor (1072B window; plain obj 1172B fndiff 232 verify 766 fnalign 111 plus 6
   reloc-only retail 268/object 293, cse_off obj 1176B fndiff 226 verify 770 fnalign 113
   plus 6 retail 268/object 294 best. WINS: 4-arg s32/s64/s32/u8* sig from retail a0-a3
   use, temp_3 scaled 0xC plus 0x100/0x102 spill, 0xF6/-1 branch cascade, loop_11 goto
   shape, var_19 s8 result switch. WALLS: s0/s1 colour swap on slot indices, addu order
   (base+index vs index+base), inner-switch 0/1 arms via shared exit vs direct, loop-hoist
   remat. Extra 2026-09-17: loopinv 232 neutral, nobl 232 neutral, sched 231/322 worse,
   o1 226 tie; cse_off 232->226 applied below.
*/
/* measured 0013f720: `opt_common_subs off` inside the guard is worth 6 words (232 -> 226); retail rematerialises what b210 hoists. */
/* measured 0013f720 width fix 2026-09-17: opclass dsll32/dsra32 surplus +21/+21 was sixteen
   s64 locals holding 32-bit values (every use re-sign-extended, shift 0x0) plus u16 temp_17 /
   temp_23_2 zero-extended at five call sites retail passes raw (andi +5) plus (s16)arg1 and
   arg0 narrowed at the f770/f6a0 calls retail passes raw. Retyped to s32/s16/u16 naturals,
   arg1 s64 -> s32 (callers already pass s32), f770/f6a0 call-site prototypes widened via
   block-scope externs (their authoritative g_data.c s16 prototypes are MATCH-proven, and the
   file-scope externs are load-bearing for matched func_0013f620). Before: fndiff 226,
   fnalign 113 (+6 reloc-only) retail 268/object 294, opclass dsll32 +21/dsra32 +21/move -15.
   After: fndiff 199, fnalign 23 (+6 reloc-only) retail 267/object 267 size-exact, opclass
   dsll32/dsra32 surplus 0 (floor drops out of the surplus list). Retail's ten pairs
   (8x0x10, 2x0x18) reproduced site-for-site; its three andi 0xFFFF masks kept. */
// FUN_0013F720 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
s32 func_0013f720(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    /* This TU passes 32-bit values where the callees' authoritative
       prototypes are narrower (g_data.c, both MATCH): retail emits a raw
       daddu at these two call sites, so the narrow declaration is scoped
       to this body to avoid re-sign-extending at every call. */
    extern s32 func_0010f6a0(s32 arg0, s32 arg1);
    extern void func_0010f770(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u8 *spC0;
    u8 *spB0;
    u8 *spA0;
    s32 var_19;
    s16 var_18;
    s32 temp_17;
    s16 temp_22;
    s32 temp_23;
    s32 temp_30;
    s32 var_22;
    s32 var_16;
    s32 var_17;
    s32 temp_16;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_3_3;
    s16 var_16_2;
    s16 temp_22_2;
    s32 temp_23_2;
    u8 *temp_3;
    u8 *temp_3_2;

    var_19 = 1;
    var_18 = -1;
    temp_3 = arg3 + arg2 * 0xC;
    spC0 = temp_3 + 0x102;
    temp_17 = *(u16 *)(temp_3 + 0x102);
    spB0 = temp_3 + 0x100;
    temp_22 = *(s16 *)(temp_3 + 0x100);
    temp_23 = *(s32 *)(temp_3 + 0x104);
    temp_30 = *(s32 *)(temp_3 + 0x108);
    if (temp_22 != -1) {
        var_18 = (s16)func_0010b510();
        func_0010b3b0(temp_22);
    }
    if ((temp_17 & 0xFFFF) == 0xF6) {
        if (func_00354010() != 0) {
            var_19 = 3;
        } else {
            var_19 = 0;
        }
    } else if ((s16)arg1 == -1) {
        var_22 = 0;
        var_16 = 0;
loop_11:
        if (var_16 < *(s16 *)(arg3 + 0xFC)) {
            temp_3_2 = arg3 + var_16 * 2;
            spA0 = temp_3_2 + 0xF4;
            if (func_0010f930(arg0, *(s16 *)(temp_3_2 + 0xF4), temp_17, 0) == 0) {
                func_0010f770(arg0, *(s16 *)spA0, temp_17, 0);
                var_22 += 1;
            }
            var_16 += 1;
            goto loop_11;
        }
        if (var_22 == 0) {
            var_19 = 0;
        }
    } else if (func_0010f930(arg0, arg1, temp_17, 0) == 0) {
        func_0010f770(arg0, arg1, temp_17, 0);
    } else {
        var_19 = 0;
    }
    temp_16 = (s8)var_19;
    if (temp_16 > 0) {
        if (temp_23 > 0) {
            temp_17_2 = (func_00104ce0(arg0) & 0xFFFF) - temp_23;
            if (temp_17_2 <= 0) {
                func_0046d730(D_005ED9F0, 0x25B);
            }
            func_001056e0(arg0, (s16)temp_17_2);
        }
        if (temp_30 > 0) {
            temp_17_3 = (func_00104d50(arg0) & 0xFFFF) - temp_30;
            if (temp_17_3 < 0) {
                func_0046d730(D_005ED9F0, 0x261);
            }
            func_00105730(arg0, (s16)temp_17_3);
        }
        if (temp_16 == 3) {
            func_00106390(0x1401, 1);
        } else {
            var_17 = 1;
            var_16_2 = -1;
            temp_23_2 = *(u16 *)spC0;
            temp_22_2 = *(s16 *)spB0;
            if (func_0010f540(temp_23_2) == 0) {
                var_17 = 0;
            } else {
                if (temp_22_2 != -1) {
                    var_16_2 = (s16)func_0010b510();
                    func_0010b3b0(temp_22_2);
                }
                if (func_0010f6a0(arg0, temp_23_2) != 0) {
                    var_17 = 0;
                }
                if (var_16_2 != -1) {
                    func_0010b3b0(var_16_2);
                }
            }
            if (var_17 == 0) {
                var_19 = 2;
            } else {
                func_0013aa90(arg3);
            }
        }
    }
    if (var_18 != -1) {
        func_0010b3b0(var_18);
    }
    temp_3_3 = (s8)var_19;
    switch (temp_3_3) {
    case 3:
        break;
    case 0:
        func_0045af60(0, 0, 0, 8);
        break;
    case 2:
    case 1:
        func_0045af60(1, 3, 2, 0x16);
        break;
    default:
        func_0046d730(D_005ED9F0, 0x28C);
        break;
    }
    return var_19;
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013f720);
#endif
/* Model floor (1072B window, size-exact). Probe nd 215;
   fea0 float->s16 idiom, absolute consts via array decls.
   Open: loop-hoist wall (C/0x8000/base remat per iter),
   s0/s5 arg0-home swap with counter-temp cascade. */
/* measured 0013fb50: `opt_loop_invariants on` inside the guard is worth 120 words (215 -> 95), the loop-preheader constant hoist. */
// FUN_0013FB50 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_0013fb50(u8 *arg0) {
    s16 i;
    s16 j;
    s16 k;
    s32 value;
    f32 f;
    s32 resource0;
    s32 resource1;
    s32 resource2;
    s32 *slot;
    u8 *src;
    u8 *dst;

    func_0043f9c8(arg0, 0, 0x18B0);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)(arg0 + 0) = 0xFF;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = -1;

    i = 0;
    while (i <= 0) {
        *(s16 *)(arg0 + i * 2 + 0x34) = 0;
        i++;
    }

    j = 0;
    while (j < 0x29) {
        src = D_005EDEA0 + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x50) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x54) = *(f32 *)(src + 4);
        f = *(f32 *)(src + 8);
        if (2147483648.0f <= f) {
            value = (((s32)(f - 2147483648.0f)) | 0x80000000) & 0xFFFF;
        } else {
            value = (s32)f & 0xFFFF;
        }
        *(s16 *)(dst + 0x60) = value;
        f = *(f32 *)(src + 0xC);
        if (2147483648.0f <= f) {
            value = (((s32)(f - 2147483648.0f)) | 0x80000000) & 0xFFFF;
        } else {
            value = (s32)f & 0xFFFF;
        }
        *(s16 *)(dst + 0x66) = value;
        *(u8 *)(dst + 0x5A) = *(u8 *)(src + 0x10);
        j++;
    }

    k = 0;
    while (k < 0x6C) {
        slot = (s32 *)(arg0 + k * 0x14 + 0xFA4);
        *slot = k % 9;
        *(s32 *)((u8 *)slot + 8) = 9;
        *(s32 *)((u8 *)slot + 4) = k / 9;
        *(s32 *)((u8 *)slot + 0xC) = 0xC;
        k++;
    }

    *(s16 *)(arg0 + 0x32) = func_00353c10((s16 *)(arg0 + 0x22));
    resource0 = func_0046a770(D_005E5830);
    if (resource0 == 0) {
        func_0046d730(D_005EF6C8, 0x1EB);
    }
    resource1 = func_0046a770(D_005E5850);
    if (resource1 == 0) {
        func_0046d730(D_005EF6C8, 0x1ED);
    }
    resource2 = func_0046a770(D_005E57F0);
    *(s32 *)(arg0 + 0x1874) = resource2;
    if (resource2 == 0) {
        func_0046d730(D_005EF6C8, 0x1EF);
    }
    if (func_0046a770(D_005E5810) == 0) {
        func_0046d730(D_005EF6C8, 0x1F1);
    }

    k = 0;
    while (k < 0x19) {
        if (k < 3) {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource0, *(u8 *)(D_005EDA00 + k));
        } else if (k < 0x18) {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource1, *(u8 *)(D_005EDA00 + k));
        } else {
            slot = (s32 *)(arg0 + k * 4 + 0x1810);
            *slot = func_0046d200((void *)resource2, *(u8 *)(D_005EDA00 + k));
        }
        if (*slot == 0) {
            func_0046d730(D_005EF6C8, 0x1FD);
        }
        k++;
    }
    *(s32 *)(arg0 + 0x3C) = func_00354a50(0, 1);
    func_00141d80(arg0, 0);
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0013", func_0013fb50);
#endif
// FUN_0013FF80
s32 func_0013ff80(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
// FUN_0013FFD0
s32 func_0013ffd0(u8 *arg0) {
    s16 temp;
    s32 i;
    s32 result;
    u8 *p;

    result = 1;
    temp = *(s16 *)(arg0 + 0x20);
    if (temp < 0x64) {
        *(s16 *)(arg0 + 0x20) = temp + 1;
    }
    i = 0;
    goto loop_test;
loop_body:
    if ((i >= 0x1C) || ((i >= 9) && (i < 0x10))) {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0x40, *(s16 *)(arg0 + 0x20), 1);
    } else {
        p = arg0 + i * 0x30;
        func_001437b0(p + 0x40, *(s16 *)(arg0 + 0x20), 0);
    }
    if (*(u8 *)(p + 0x5A) != 0) {
        result = 0;
    }
    i++;
loop_test:
    if (i < 0x29) {
        goto loop_body;
    }
    func_00141d10(arg0);
    func_001400f0(arg0);
    return result;
}
