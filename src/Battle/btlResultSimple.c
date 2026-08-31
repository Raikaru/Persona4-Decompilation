#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultSimple.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0021dda0(void);
extern u16 *func_00452560();
void func_001437b0(void *arg0, s32 arg1, s32 arg2);
s32 func_001b5fd0(void);
void func_0025cbc0(void *arg0, s32 arg1, s32 arg2);
s32 func_0025cc70(void);
s32 func_0046d200(s32 arg0, s32 arg1);
u32 func_003b7060(void);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 D_00629380[];
extern s32 D_006291A0[];
extern s8 D_00629170[];
extern s32 D_00629560[];
extern s32 D_006295F0[];
void func_00454bd0(u8 *ptr);
void func_0046b0d0(void *ptr);
void func_0046d280(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
void func_0044ea90(const void *msg, s32 id);
void func_0043f9c8(void *dst, s32 value, u32 size);
s32 func_00451fc0(s32 window, const void *data, s32 a, s32 b, s32 c,
                  s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern char D_00629628[];
extern char D_006290F0[];
extern char D_00629610[];
extern s64 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
void func_00440b68(void *msg, const void *file, s32 line);
extern u8 *func_00454a60(u8 *param, s32 mode);
void func_0046d730(const void *file, s32 line);
s32 func_0046a770(u32 param);
s32 func_004553c0(u8 *ptr);
s32 func_00455ea0(s32 param, s32 a, s32 b);
s32 func_0046af60(u8 *arg0);
s32 func_0046a750(s32 param);
void func_0021fea0(u8 *work);
void func_002214d0(void);
void func_0034f2e0(void *arg0, f32 arg1, f32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_00442088(void *dst, const void *fmt, s32 value);
void func_00460ac0(void *param, void *work);
extern u32 D_00795F20[];
s32 func_0021f520(u8 *arg0);
s32 func_0021de60(void);
static inline u32 addBase(u32 base, u32 index) { return base + index; }
extern char iGpffffa5b8;
extern u8 *iGpffffa5a0[2];
extern s32 iGpffffa5a8[2];
extern s32 iGpffffa5b0;
extern char iGpffffa5b4;

/* Work buffer handed to the result state machine (see func_002215c0). */
typedef struct BtlResultWork BtlResultWork;
struct BtlResultWork
{
    u16 flags;         // 0x00
    u16 pad02;         // 0x02
    u32 state;         // 0x04
    s32 field08;       // 0x08
    s32 field0C;       // 0x0C
    u8 pad10[0x2C];    // 0x10..0x3B
    u16 field3C;       // 0x3C
    u8 pad3E[0x3C2];   // 0x3E..0x3FF
    s32 field400[3];   // 0x400..0x40B
    u8 pad40C[8];      // 0x40C..0x413
    s32 field414[0x2A];// 0x414..0x4BB
    s32 field4BC;      // 0x4BC
    u8 pad4C0[0xB0];   // 0x4C0..0x56F
    u8 *field570;      // 0x570
};

s32 func_0021f340(BtlResultWork *work);
void func_0021ef70(BtlResultWork *work);
void func_002baac0(s32 param);
void func_002bad10(s32 param);
void func_002bb4e0(void);
s32 func_00353f50(s32 param);
extern s32 func_0021f790(u8 *arg0);

typedef struct BtlResultSubWork BtlResultSubWork;
struct BtlResultSubWork
{
    u8 pad[0x60];
    s32 field60;       // 0x60
    u8 pad64[0x8D0];   // 0x64..0x933
    s32 field934;      // 0x934
};

/* measured 2026-08-03 (wave 14 re-attack, 10 attempts): two lever wins landed,
   then a register-coloring floor remained. LEVER 1: func_0034f2e0's true
   signature is (u8*, f32, f32, u8, u8, u8, u8) — FLOATS-FIRST after the pointer
   (verified from func_0034f320's own prologue: mov.s $f12/$f13/$f14 saved before
   the int args; the old extern had int args first, which WAS the recorded
   "emits int args first" floor). LEVER 5: the walk loop needs switch(buf[i])
   {case 0x2E: dotbody; break; default: digitbody;} — case 0x2E declared FIRST so
   the '.' body is laid out before the digit body (beq->dot, b->digit), exactly
   matching retail; if/else and goto forms lay them out reversed (nd 99-104 vs
   switch's 39). Also: arg3 must be u32 (retail divu + sltiu; s32 emits signed
   div/slti), byte extraction is (arg2 & 0xFF000000)>>24 mask-first (srl, not sra),
   and buf/buf2 must be char[] (signed lb loads). Retail window 608B; best
   discarded body was 600B with nd 39: residual is the no-call
   digit-conversion loop's temp-register coloring (retail k=$t2/j=$t1,
   +0x2E/2/0xA consts hoisted to the preheader; mwcc k=$v1/j=$t0 and sinks the
   0x2E/2 materialisation into the loop) plus one slt-$at-vs-$v0 in the digit
   assert. opt_loop_invariants off/on, block-scoped k/j, f32* arg1, m2c casts:
   unchanged. Register-coloring + const-hoist floor. */
// FUN_0021ED10
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ed10);




/* measured 2026-08-03 (wave 14 re-attack, 3 attempts): full body reconstructed from
   the m2c draft (code1_0021.c) + retail asm — all 4 loops and the final stores
   correct, but the register allocation makes the object 1020B (44B OVER the 976B
   window) with 237 differing words. The m2c draft's u16* arg0 pointer math is
   WRONG (doubles the byte offsets); the real access is u8* byte offsets. The
   half-scaler value must be u32 (retail srl for the >>1, not sra) and the bltz
   test is (s32)scaled<0. Base tables D_006291A0/D_00629380 are hoisted by
   retail to the preheader; mwcc re-materialises them per iteration. Retail
   frame -0x60 with arg0 in $s3 and loop vars in $s0/$s1/$s2 + $f20; mwcc b210
   allocates the loop counters to saved registers and frames -0x70+ (5 saved
   int regs), so the object runs 44B over the window. Block-scoping every loop
   local, hoisted table bases, and separate table pointers all leave the
   allocation unchanged. Frame + register-colouring floor (same family as the
   recorded note). */
// FUN_0021EF70
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ef70);
/* measured 2026-08-07: discarded raw_alias body reached nd 57 with object
   472B vs the 480B window. Retail precomputes the indexed field400 store
   address before func_0046af60; b210 keeps the loop/index colouring in the
   wrong saved registers and recomputes that address after the call. The
   direct, slot-pointer, reload, and add-base spellings all stayed at nd 254+
   or nd 275. Register-colouring/pre-call-hoist floor; leave the marker bare. */
/* measured 2026-08-08: raw u8* alias body reached object 472B / window
   480B but normalized_diff 57, so the body is discarded rather than parked.
   Exact residual fndiff offsets are 40, 44, 52, 60, 64, 68, 72, 76, 84, 88,
   92, 100, 104, 108, 112, 116, 120, 124, 156, 160, 164, 168, 324; first
   differing row is offset 40 (`lw $s2,0x4bc($s1)` vs retail
   `lw $a0,0x4bc($s1)`). The discarded body is archived in
   build/WCBattleUI_btlResultSimple_prepark_validate.c. */
// FUN_0021F340
s32 func_0021f340(BtlResultWork *work)
{
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_16;
    s32 var_18;
    s32 var_18_2;
    u16 temp_3;
    u8 *arg0;
    s32 *dest;

    arg0 = (u8 *)work;
    if (!(*(u16 *)(arg0 + 0) & 0x100)) {
        if (*(s32 *)(arg0 + 0x4BC) != 0 &&
            func_004553c0((u8 *)*(s32 *)(arg0 + 0x4BC)) != 0) {
            var_18 = 0;
            while (var_18 < 3) {
                dest = (s32 *)(arg0 + var_18 * 4 + 0x400);
                *dest = (s32)func_0046af60(
                    (u8 *)func_00455ea0(*(s32 *)(arg0 + 0x4BC), var_18, 0));
                if (*dest == 0) {
                    func_0046d730(&D_00629610, 0x181);
                }
                var_18 += 1;
            }
            *(u16 *)(arg0 + 0) |= 0x100;
        } else {
            return 0;
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x20)) {
        var_18_2 = 0;
        var_16 = 0;
        while (var_18_2 < 3) {
            temp_4_2 = *(s32 *)(arg0 + var_18_2 * 4 + 0x400);
            if (temp_4_2 != 0 && func_0046a750(temp_4_2) != 0) {
                var_16 += 1;
            }
            var_18_2 += 1;
        }
        if (var_16 == 3) {
            *(u16 *)(arg0 + 0) |= 0x20;
            temp_4_3 = *(s32 *)(arg0 + 0x4BC);
            if (temp_4_3 != 0) {
                func_00454bd0((u8 *)temp_4_3);
                *(s32 *)(arg0 + 0x4BC) = 0;
            }
        }
    }
    if (!(*(u16 *)(arg0 + 0) & 0x40)) {
        temp_4_4 = *(s32 *)(*(u8 **)(arg0 + 0x570) + 0x934);
        if (temp_4_4 != 0 && func_004553c0((u8 *)temp_4_4) != 0) {
            *(u16 *)(arg0 + 0) |= 0x40;
        }
    }
    temp_3 = *(u16 *)(arg0 + 0);
    if ((temp_3 & 0x20) && (temp_3 & 0x40)) {
        return 1;
    }
    return 0;
}




// FUN_0021F520
s32 func_0021f520(u8 *arg0) {
    u8 *work;
    u8 *sub;
    u32 state;
    s32 i;
    s32 v;

    work = *(u8 **)(arg0 + 0x38);
    sub = *(u8 **)(work + 0x570);
    state = *(u32 *)(work + 0x38);
    switch (state) {
    case 0:
        v = *(u16 *)(work + 0x3C);
        if (v >= 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0x3C) = v + 1;
        for (i = 0; i < 0x14; i++) {
            switch (*(s32 *)((u8 *)D_00629380 + i * 0x18 + 0x14)) {
            case 0:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 0);
                break;
            case 1:
                func_001437b0(work + i * 0x30 + 0x40, *(u16 *)(work + 0x3C), 1);
                break;
            }
        }
        if (*(u16 *)(work + 0x3C) != 0x1E) {
            goto L;
        }
        *(u16 *)(work + 0) |= 0x10;
        *(u16 *)(work + 0x3C) = 0;
        *(u32 *)(work + 0x38) = 1;
        goto L;
    case 1:
        v = (*(u16 *)(work + 0x3C) += 1);
        if ((v & 0xFFFF) < 4) {
            goto L;
        }
        if (func_001b5fd0() != 0x10) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 2;
        goto L;
    case 2:
        if ((D_008C024E[0] & 0x40) || (D_008C024C[0] & 0x10)) {
            if (*(s16 *)(sub + 0x6F8) > 0) {
                func_002baac0(func_00455ea0(*(s32 *)(sub + 0x934), 0, 0));
                func_002bad10(0x17);
                *(u32 *)(work + 0x38) = 3;
            } else {
                *(u32 *)(work + 0x38) = 5;
            }
        }
        goto L;
    case 3:
        if (func_00353f50(1) != 0) {
            goto L;
        }
        func_002bb4e0();
        func_0025cbc0(arg0, 0, *(s16 *)(sub + 0x6F8));
        *(u32 *)(work + 0x38) = 4;
        goto L;
    case 4:
        if (func_0025cc70() != 0) {
            goto L;
        }
        *(u32 *)(work + 0x38) = 5;
        goto L;
    case 5:
        return 1;
    default:
    L:
        return 0;
    }
}
// FUN_0021F790
s32 func_0021f790(u8 *arg0) {
    BtlResultWork *work;
    u32 state;
    s32 v;

    work = (BtlResultWork *)func_00452560();
    work->field08 = 0;
    work->field0C = 0;
    func_00460ac0(&D_00795F20, &work->field08);
    state = work->state;
    switch (state) {
    case 0:
        work->state = 1;
        goto L;
    case 1:
        v = work->flags;
        if ((v & 1) && (v & 8)) {
            goto case2;
        }
        if ((v & 4) && (func_0021f340(work) != 0)) {
            work->flags &= 0xFFFB;
            work->flags |= 8;
        }
        goto L;
    case 2:
    case2:
        func_0021ef70(work);
        work->flags |= 2;
        work->state = 3;
        goto L;
    case 3:
        if (func_0021f520(arg0) != 0) {
            v = *(s32 *)(work->field570 + 0x60);
            if (v & 2) {
                work->state = 4;
                func_002baac0(func_00455ea0(*(s32 *)(work->field570 + 0x934), 0, 0));
                func_002bad10(2);
            } else if (v & 8) {
                work->state = 4;
                func_002baac0(func_00455ea0(*(s32 *)(work->field570 + 0x934), 0, 0));
                func_002bad10(1);
            } else if (v & 0x10) {
                work->flags &= 0xFFFE;
                work->state = 7;
            } else {
                work->flags &= 0xFFFE;
                work->state = 7;
                work->flags |= 0x80;
            }
        }
        goto L;
    case 4:
        if (func_00353f50(1) == 0) {
            func_002bb4e0();
            work->flags &= 0xFFFE;
            work->state = 7;
        }
        goto L;
    case 5:
        if (func_0021de60() != 0) {
            work->state = 6;
        case 6:
            if (work->flags & 0x80) {
                goto R1;
            }
            v = (work->field3C += 1);
            if ((v & 0xFFFF) < 5) {
                goto L;
            }
        R1:
            work->flags &= 0xFFFD;
            return -1;
        }
        goto L;
    case 7:
        goto L;
    default:
    L:
        return 0;
    }
}
// FUN_0021FA40
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fa40);
/* measured 2026-08-07: a full C reconstruction of the five-entry update
   loop reached nd 1051 but emitted 1420B for the 1120B window. The remaining
   retail path uses COP1 adda.s/madd.s interpolation, the EE three-operand
   mult form, and b210's signed-range conversion/float-register schedule
   differs throughout; discarded rather than leaving an oversized body bare. */

/* measured: 5680B retail window; m2c cannot lower the FPU multiply-accumulate
   idiom (adda.s $f0,$f3 / madd.s $f1,$f2,$f1 fused lerp in the loop_26
   quadword color path) and the body is dominated by dozens of D_00887300
   render-vtable calls, the (f32)(s32) range-guard idiom (0x4F000000 checks),
   bltz floor family, s64 bitwise byte extractions, and 3 nested loops. A
   stub-only probe measured nd 7 but object_size 8B/5680B, a size-deficit
   result rather than a near miss; no body retained at this scale. */
// FUN_0021FEA0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fea0);

/* measured: retail allocates p=$s0, loop-addr=$s1, counter=$s2; mwcc b210
   invariantly allocates the named values to $s1/$s0 and the indexed store
   address temp to $s2 (counter<->addr rotation, nd 12, rest byte-identical).
   Tried: struct-vs-pointer arith for the 0x4BC block, every declaration order
   of p/w/i (8 variants), loop-local addr pointers, shared addr var, u16/u32
   counters; all give the identical 12-word rotation. Register-coloring floor. */
// FUN_002214D0
void func_002214d0(void) {
    BtlResultWork *p;
    s32 i;
    s32 j;

    p = (BtlResultWork *)func_00452560();
    if (p->field4BC != 0) {
        func_00454bd0((void *)p->field4BC);
        p->field4BC = 0;
    }
    for (i = 0; i < 3; i++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(i * 4)) + 0x400);
        if (*el != 0) {
            func_0046b0d0((void *)*el);
            *el = 0;
        }
    }
    for (j = 0; j < 0x2A; j++) {
        s32 *el = (s32 *)(addBase((u32)p, (u32)(j * 4)) + 0x414);
        if (*el != 0) {
            func_0046d280(*el);
            *el = 0;
        }
    }
    jtbl_008873EC[0](p);
}
// FUN_002215C0
s32 func_002215c0(s32 arg0) {
    u8 *buf;
    u16 *q;
    s32 r;

    func_0044ea90(&D_00629628, 0x3A);
    buf = (u8 *)(*jtbl_008873E8)(0x578, 0x40000);
    func_0043f9c8(buf, 0, 0x578);
    r = func_00451fc0(arg0, D_006290F0, 0xF, 0, 0, (s32 (*)(u8 *))func_0021f790,
                      (void (*)(u8 *))func_002214d0, buf);
    q = func_00452560(arg0);
    *(s32 *)(buf + 4) = 0;
    *(u16 **)(buf + 0x570) = q;
    func_0043f9c8(buf + 8, 0, 0x30);
    *(void (**)(u8 *))(buf + 0x10) = func_0021fea0;
    *(u8 **)(buf + 0x18) = buf;
    return r;
}

// FUN_002216B0
void func_002216b0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    *temp_2 |= 1;
}

// FUN_002216E0
void func_002216e0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0] & 0x80) {
        func_0021dda0();
        *(s32 *)(temp_2 + 2) = 5;
        return;
    }
    *(s16 *)((u8 *)temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 2) = 6;
}

// FUN_00221740
u16 func_00221740(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    return temp_2[0] & 1;
}

/* measured 2026-08-14: retail frame 64B with work=$s0, index=$s1, and
   field400 destination=$s2. Complete iGp declarations, a u32 masked result
   local, and the explicit field400 destination expression reproduce the
   368B window exactly. */
// FUN_00221770
void func_00221770(void) {
    s32 *dst;
    s32 i;
    BtlResultWork *work;

    work = (BtlResultWork *)func_00452560();
    {
        u32 r;
        r = (u32)func_00110d60((s16)func_001060b0()) & 1;
        i = (0U < r) ^ 1U;
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1410);
    work->field4BC = (s32)func_00454a60(iGpffffa5a0[i], 1);
    if (work->field4BC == 0) {
        func_0046d730(&D_00629610, 1411);
    }
    i = 3;
    for (; i < 5; i++) {
        dst = (s32 *)((u8 *)work + i * 4 + 0x400);
        *dst = func_0046a770(*(s32 *)((u8 *)iGpffffa5a8 + i * 4 - 12));
        if (*dst == 0) {
            func_0046d730(&D_00629610, 1419);
        }
    }
    func_00440b68(&iGpffffa5b8, &D_00629610, 1423);
    ((BtlResultSubWork *)work->field570)->field934 =
        (s32)func_00454a60((u8 *)iGpffffa5b0, 1);
    if (((BtlResultSubWork *)work->field570)->field934 == 0) {
        func_0046d730(&D_00629610, 1424);
    }
    work->flags |= 4;
}


