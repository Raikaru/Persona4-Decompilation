/* Consolidated Persona 4 source units. */
/* Original translation unit itfMsgProcedure_Window.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

s32 *func_0027be60();
extern s32 func_00452380(void *path);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_0025f110(void *arg);
extern void func_0025f230(u32 arg);
extern void func_00366380(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, void *s1, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_0046a750(void *arg);
extern s32 func_00455f70(char *str, void *out);
extern s32 func_0046af60(void *arg);
extern s32 func_00451fc0(void *a0, char *a1, s32 a2, s32 a3, s32 a4, void *a5, void *a6, void *a7);
extern s32 func_0025ef20(char *str);
extern s32 func_00266b70(void);
extern s32 func_0043f9c8(void *a0, s32 a1, s32 a2);

extern void func_00460b60(void *a0, s32 a1, s32 a2);
extern void func_00460c70(void *a0, s32 a1, s32 a2);
extern void func_00489f80(void);
extern void func_0045da40(float *a0, void *a1, float a2, s32 a3, void *a4);
extern void func_0048a000(void);
extern float func_0044b7b0(float angle);
extern float func_0044b610(float angle);
extern s32 func_0045eb20(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, void *a7, float a8, float a9, float a10, float a11);
extern float D_007612D0;
extern f32 iGpffff81e0;
extern f32 iGpffff8094;
extern f32 iGpffff8198;
extern f32 iGpffff8084;
extern f32 iGpffff81dc;
extern s32 iGpffffb4dc;
extern s32 iGpffffb4d8;
extern u8 D_00796430[];
extern u8 D_00796490[];
extern void func_0027d800(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f0, f32 f1, f32 f2, f32 f3, void *t2);
extern void func_0027d3c0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s16 t2, s16 t3, f32 f0, f32 f1, f32 f2, f32 f3, void *a4);
extern void func_0025ecd0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *t3);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *a0, void *a1);
extern void func_0027bf30(u8 *arg);
extern void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, void *s0, float f0, float f1, float f2, float f3);
extern void func_0027f6a0(void);
extern void func_00283360(void);
extern void func_00278110(void);
extern void func_00278170(void *arg0, u32 arg1);
extern void func_002781e0(void *arg0, u32 arg1);
extern s32 func_0027bec0(void *arg0);
extern s32 func_00278fd0(void *arg0);
extern s32 func_00278fb0(void *arg0);
extern void func_00272a10(void *arg0, f32 f0, f32 f1);
extern void func_002728c0(void *arg0, s32 arg1);
extern void func_00272b00(void *arg0, s32 arg1);
extern void func_00272b50(void *arg0, s32 a1, s32 a2);
extern void func_00272730(void *arg0, s32 arg1);
extern void func_002727a0(void *arg0, s32 arg1);
extern s32 func_0027b6e0(void *arg0, s32 arg1);
extern void func_0027b750(void *arg0, s32 a1, s32 a2);
extern void func_00283490(u8 *arg);
extern u32 D_00882080[];
extern s16 D_00882084[];
extern s16 D_00882088[];
extern u32 D_00882090[];
extern u32 D_00882094[];
extern u32 D_00882040[];
extern s16 D_00882044[];
extern u32 D_00882060[];
extern s16 D_00882064[];
extern s16 D_00882066[];
extern f32 iGpffff81d8;
extern void func_0025ec90(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1, f32 f0, f32 f1, f32 f2);
extern s32 func_00277070(void *arg0);
extern s32 func_00279010(void *arg0);
extern s32 func_002738d0(void *arg0);
extern void func_00272ba0(void *arg0, s32 arg1);
extern void func_0027a490(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_0027a4b0(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_002e0dd0(void);
extern void *(*D_008873F4[])(s32 a0, s32 a1, s32 a2);
extern void (*jtbl_008873EC[])(void *arg0);
extern void func_0027be90(void *arg0, void *arg1);
extern void func_0044ea90(const void *file, s32 line);
extern s32 func_00278ff0(void *arg0);
extern s32 func_002bd1e0(s32 a0);

typedef struct MsgProcWindowWork {
    s16 field0;
    s16 field2;
    u32 field4;
    u32 field8;
} MsgProcWindowWork;

typedef struct MsgProcWindowEntry {
    s32 field0;
    s32 field4;
    f32 field8;
    s32 fieldC;
    s32 field10;
    s32 field14;
} MsgProcWindowEntry;

extern s32 func_0027cae0(MsgProcWindowEntry *arg);

typedef struct MsgProcWindowF2 {
    float x;
    float y;
} MsgProcWindowF2;

typedef struct MsgProcWindowRGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} MsgProcWindowRGBA;

typedef struct MsgProcWindowU32Pair {
    u32 a;
    u32 b;
} MsgProcWindowU32Pair;

typedef struct MsgProcWindowQuad {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} MsgProcWindowQuad;

extern u8 D_007245D0;
extern u32 D_007245D4;
extern MsgProcWindowWork D_00882098;
extern MsgProcWindowEntry D_008820B0[];
extern u32 D_0088209C[];
extern u32 D_007245C8;
extern u32 D_007245CC;
extern char D_00723868;
extern char D_0063BFC0[];
extern char D_0063C180[];
extern char D_0063BFE0[];
extern char D_0063C000[];
extern char D_0063C018[];
extern char D_0063C120[];
extern char D_0063C170[];
extern MsgProcWindowF2 D_0063C030[10];



/* measured: retail's case-6 float->u8 clamp (c.le.s 2^31/cvt.w.s/or 0x80000000
   dance) computes directly into $a1 with andi 0xFF folded into both paths; mwcc b210
   computes it in $v1 and adds a join `andi $a1,$v1,0xff` (one extra word). Case 1-3's
   func_0025ecd0 call: retail materialises f14/f15 (mov.s $f12) before t3's lui/addiu;
   mwcc emits t3 first then both mov.s. All 5 d800 calls (fixed by pointer-last arg
   order), d620/d3c0 calls, adda/madd chains, jtbl, and saved-reg allocation match
   instruction-for-instruction. Tried: (u8)(u32) vs inline (u8) vs u8 local, pointer
   hoisted into locals (regressed to nd 180), 3 declaration orders. nd 65. FPU
   arg-scheduling + float-to-u8 register-join floor (measured nd 65). */
// FUN_0027CAE0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027cae0);

// FUN_0027D230
s32 func_0027d230(void)
{
    s32 i;

    if (D_007245C8 != 0) {
        func_0046a750((void *)D_007245C8);
    }
    if (D_007245CC != 0) {
        func_0046a750((void *)D_007245CC);
    }
    for (i = 0; i < 8; i++) {
        if ((D_008820B0[i].field0 & 1) != 0) {
            if (func_0027cae0(&D_008820B0[i]) != 0) {
                D_008820B0[i].field0 &= ~1;
            }
        }
    }
    return 0;
}

// FUN_0027D2F0
void func_0027d2f0(void *arg0)
{
    s32 local;
    s32 tmp;

    tmp = func_00455f70(D_0063BFE0, &local);
    if (tmp != 0) {
        D_007245C8 = func_0046af60((void *)tmp);
    } else {
        D_007245C8 = 0;
    }
    tmp = func_00455f70(D_0063C000, &local);
    if (tmp != 0) {
        D_007245CC = func_0046af60((void *)tmp);
    } else {
        D_007245CC = 0;
    }
    func_00451fc0(arg0, D_0063C018, 0xF, 0, 0, (void *)func_0027d230, (void *)0, (void *)0);
}

/* Frame 0x2D0, loop, madd chains (adda.s/madd.s), color packing, struct copy
   sp180[i]=sp180[1], and all call args match retail instruction-for-instruction.
   The residual is float-arg scheduling: (1) prologue saves f12->f23 (first
   float param) 3rd in retail but last here; (2) the func_0045eb20 call materialises
   f12 first and t3 (arg_sp0) last in retail, but here t3 first and f12-f15 grouped
   last. Frame fixed vs prior lane (was 0x2E0, wrong func_0045eb20 prototype). Key
   levers: func_0045eb20 arg5/arg6 declared s16 (kills the lh-v0/move-t1 pair) and
   arg7 declared s32 with a (s32) cast at the call (kills the t3-into-ints
   materialisation). Tried schedule on/off (nd 423), optimization_level 3 (nd 429),
   6 local declaration orders, u32/s32 i, union and *(float*)&arg0 bitcasts for the
   raw-bit base (both split the array base and regress). Committed at nd 104. */
// FUN_0027D3C0 NONMATCHING
#ifdef NON_MATCHING
void func_0027d3c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, void *arg_sp0)
{
    MsgProcWindowF2 sp180[42];
    MsgProcWindowRGBA spD0[42];
    s16 spCE;
    s16 spCC;
    u32 i;
    s32 r, g, b, a;
    u32 packed;
    float f24, fsin, f25;
    MsgProcWindowF2 *p;
    MsgProcWindowRGBA *c;

    spCE = arg6;
    spCC = arg7;
    sp180[0].x = (float)arg0;
    sp180[0].y = (float)arg1;
    packed = ((u32)arg3 << 8) | (u32)arg4;
    r = (packed >> 24) & 0xFF;
    spD0[0].r = (u8)(packed >> 24);
    g = (packed >> 16) & 0xFF;
    spD0[0].g = (u8)(packed >> 16);
    b = (packed >> 8) & 0xFF;
    spD0[0].b = (u8)(packed >> 8);
    a = packed & 0xFF;
    spD0[0].a = (u8)packed;
    for (i = 1; i < 0x29; i++) {
        f25 = (D_007612D0 * (float)(s32)(i - 1)) / 40.0f;
        f24 = func_0044b7b0(f25);
        fsin = func_0044b610(f25);
        p = &sp180[i];
        p->x = fparg2 * ((float)arg2 * fsin) + (float)arg0;
        p->y = fparg3 * ((float)arg2 * (-f24)) + (float)arg1;
        c = &spD0[i];
        c->r = (u8)r;
        c->g = (u8)g;
        c->b = (u8)b;
        c->a = (u8)a;
    }
    sp180[i] = sp180[1];
    spD0[i].r = (u8)r;
    spD0[i].g = (u8)g;
    spD0[i].b = (u8)b;
    spD0[i].a = (u8)a;
    func_0045eb20(&spD0[0], &sp180[0], 0x2A, 5, arg5, spCE, spCC, arg_sp0, fparg0, fparg1, fparg2, fparg3);
}
#else
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d3c0);
#endif

// FUN_0027D620
void func_0027d620(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, void *s0, float f0, float f1, float f2, float f3)
{
    func_00366380(a0, a1, a2, a3, t0, t1, 1, t2, t3, s0, f0, f1, f2, f3);
}

// FUN_0027D660
void func_0027d660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, float f0, void *arg4)
{
    float f;
    u32 pad;
    MsgProcWindowQuad q2;
    MsgProcWindowQuad q1;
    u8 *p;
    u32 n;

    p = (u8 *)&pad;
    n = 4;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    f = *(float *)&pad;
    p = (u8 *)&q1;
    n = 0x10;
    if (p != 0) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    q1.a = arg0;
    q1.b = arg1;
    q1.c = arg2;
    q1.d = arg3;
    q2 = q1;
    func_00460b60(arg4, 0x6, 0x1);
    func_00460b60(arg4, 0xE, 0x0);
    func_00460b60(arg4, 0xC, 0x1);
    func_00460b60(arg4, 0x7, 0x2);
    func_00460b60(arg4, 0x9, 0x1);
    func_00460b60(arg4, 0x14, 0x1);
    func_00460b60(arg4, 0x6, 0x0);
    func_00460b60(arg4, 0x8, 0x1);
    func_00460c70(arg4, 0x3, 0x31003);
    func_00460c70(arg4, 0x2, 0x44);
    func_00489f80();
    func_0045da40(&f, &q2, f0, 0, arg4);
    func_0048a000();
}

/* measured: d800's copy loop, float block, color packing and += loop all match
   retail instruction-for-instruction in order; only REGISTER allocation differs.
   Retail's countdown copy loop uses $t5/$t2/$t1/$t0/$v0, keeping $a0-$a3 alive for
   the later mtc1 $a0/$a1 conversions and sll $a2 packing; mwcc b210 allocates my
   loop $a0/$a1/$a2 (free after prologue moves) which cascades: conversions read
   $t1/$t2, and the prologue copies land in $t1/$t2/$t3 vs retail $t4/$v1/$t3.
   Tried: F2/U32Pair/u64 struct copies, pointer vs indexed loops, for vs do-while
   countdown, two-local (lo/hi) copy, 4 declaration-order permutations, src/dst
   statement order, and inline f32Add helpers (all fuse into adda.s/madd.s).
   nd 66, all 66 words are register-name-only diffs. Register-coloring floor. */
// FUN_0027D800
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d800);

// FUN_0027D970
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027d970);

// FUN_0027F560
s32 func_0027f560(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    switch (*(s16 *)&D_007245D0) {
    case 0:
        work->field4 = func_0025ef20(D_0063C120);
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0027F630
void func_0027f630(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (D_007245D4 != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x3D9);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
}

// FUN_0027F6A0
void func_0027f6a0(void)
{
    MsgProcWindowWork *work = (MsgProcWindowWork *)&D_007245D0;

    if (func_00452380(&D_00723868) != 0) {
        work->field2 |= 1;
    }
}

// FUN_0027F6F0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_0027f6f0);
// FUN_002818A0
void func_002818a0(u32 arg0, s32 arg1) {
    s32 *temp_2;

    temp_2 = func_0027be60();
    if (temp_2 != NULL) {
        *temp_2 = arg1;
    }
}

/* measured: all case bodies, FPU chains (adda/madd/msub) and the d3c0/336380/25ecd0
   calls match retail instruction-for-instruction; residual defects: (1) mwcc b210
   tail-merges one pair of the six identical func_0027bec0 case bodies (11-18) -
   retail emits six separate bodies (tried plain calls, dead-assigned results,
   mixed call spellings, case-18 fallthrough, all still merge, nd>=141); (2) the
   func_0025ecd0 t3 address materialises before the f15/f16/f17 mov.s copies in
   both calls (retail: after) - ptr-first and ptr-last prototype orders both fail;
   (3) case-7 scan loop rematerialises &D_008820B0 inside the loop instead of
   hoisting (pragma opt_loop_invariants on did not help); (4) s16 counter temp
   lands in $a0 vs retail $v1, case-8 tests beqz $s1 vs retail $v0. nd 141-152.
   measured: switch-body tail-merge + FPU-arg-scheduling floor. */
// FUN_002818E0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002818e0);

/* measured: every case body, the adda/madd/msub FPU chains, the d3c0-style
   336380/25ec90/25ecd0 calls and the jtbl match retail instruction-for-instruction;
   the ONLY saved-register defect: case 13's temp_17_2 (temp_19_3*0x1E) is pinned to
   $s6 (frame 0xA0 vs retail 0x90) because mwcc b210 never reuses arg1's dead $s1
   slot across the switch, while retail does (tried declaring it first/last, separate
   case-9 temp, inline re-expression: all keep $s6, nd>=882). Also the known
   secondary residuals: case 8/10 test beqz on the saved copy vs retail's $v0, and
   the 25ec90/25ecd0 pointer vs float-arg materialisation order. nd 882 (reloc-
   masked). measured: saved-register-reuse floor. */
// FUN_00282250
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00282250);

// FUN_002831C0
s32 func_002831c0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    switch (*(s16 *)&D_00882098) {
    case 0:
        work->field4 = func_0025ef20(D_0063C170);
        work->field8 = func_00266b70();
        work->field0 = 1;
    case 1:
        if (func_0025f110((void *)work->field4) != 0 && func_0025f110((void *)work->field8) != 0) {
            work->field0 = 2;
        }
        break;
    case 2:
        if ((work->field2 & 1) != 0) {
            work->field0 = 3;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_002832B0
void func_002832b0(void)
{
    MsgProcWindowWork *work = &D_00882098;

    if (D_0088209C[0] != 0) {
        if (func_0025f110((void *)work->field4) == 0) {
            func_0046d730(D_0063BFC0, 0x7AA);
        }
        func_0025f230(work->field4);
        work->field4 = 0;
    }
    if (work->field8 != 0) {
        if (func_0025f110((void *)work->field8) == 0) {
            func_0046d730(D_0063BFC0, 0x7B0);
        }
        func_0025f230(work->field8);
        work->field8 = 0;
    }
}

// FUN_00283360
void func_00283360(void)
{
    u8 *work = (u8 *)&D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        *(s16 *)(work + 2) |= 1;
    }
}

// FUN_002833B0
s32 func_002833b0(s32 arg0)
{
    MsgProcWindowWork *work = &D_00882098;

    if (func_00452380(D_0063C180) != 0) {
        if (work->field0 >= 2) {
            u32 *arr = (u32 *)((u8 *)work + 4);
            return arr[arg0];
        }
    } else if (func_00452380(D_0063C180) == 0) {
        func_0043f9c8(work, 0, 0xC);
        func_00451fc0((void *)0, D_0063C180, 0xF, 0, 0, (void *)func_002831c0, (void *)func_002832b0, (void *)0);
    }
    return 0;
}

// FUN_00283490
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_00283490);

/* measured: every instruction sequence matches retail (jtbl dispatch, case bodies,
   the dsll32/dsra32 s16 sign-extend on D_00882084, the single var_2 join move, the
   case-7 scan loop); the ONLY defect is a 3-way saved-register permutation: mwcc
   b210 pins the work pointer (&D_00882098) to $s0 and the params to ($s3,$s2),
   retail keeps work in $s3 with arg0/arg1 in ($s2,$s0). Tried: work declared
   first/last, K&R-style params, separate item1/item2/item3 locals, inline
   &D_00882098 casts (fixes params to $s2/$s0 but drops the s3 hoist entirely -
   frame shrinks 0x60->0x50, so retail's source must hoist the address), 3 local
   declaration orders, for-loop vs while-loop scan. nd 221 (reloc-masked), all
   rows register-name-only. measured: saved-register-coloring floor. */
// FUN_002848C0
INCLUDE_ASM("asm/nonmatchings/itfMsgProcedure_Window", func_002848c0);
