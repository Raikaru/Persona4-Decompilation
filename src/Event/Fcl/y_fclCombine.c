/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclCombine.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;

typedef struct {
    f32 x;
    f32 y;
} FclVec2f;

extern u16 *func_001102e0(void);
extern s32 func_00106330(s32);
extern void func_00145080(void);
extern s32 func_00452380(void *);
extern void func_003315a0(void);
extern void func_00454bd0(void *);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00641BC8[];
extern u32 func_003b7060(void);
extern s8 D_007490F8[];
extern u16 *func_0010ace0(s16);
extern s32 func_0010b6f0(void);
extern u8 func_00109280(s32);
extern s32 func_00331660(void);
extern s8 func_002bab80(void *);
extern void func_002badc0(s8, s32);
extern void func_002bbd80(s8, s32, void *);
extern s32 func_00110140(void);
extern void *func_001067f0(s16);
extern s16 D_00749040[];
extern s16 D_00749060[];
extern s16 D_00749080[];
extern s16 D_007490A0[];
extern s16 D_007490C0[];
extern s16 D_007490E0[];
extern s8 D_00749100[];
extern void func_002bafc0(s8, s32);
extern void func_002bb0a0(s8, s32);
extern void func_002bbf60(void);
extern u16 *func_002e48a0(s8 arg0, s16 arg1);
extern u32 func_0010ceb0(void *);
extern s32 func_0010cf40(void *, s16);
extern u16 *iGpffffb3ec;
extern u8 *iGpffffb594;
extern void func_0010fd40(void *);
extern void func_00106620(s16, s32);
extern s32 func_0010b5b0(void);
extern u8 D_00641BE0[];
extern u8 D_00641C00[];
extern char iGpffffa8c8;
extern s32 func_00451fc0(s32 arg0, void *arg1, s32, s32, s32, void *, void *, void *);
extern void func_00440b68(const void *arg0, const void *arg1, s32 arg2);
extern s32 func_00454a60(void *arg0, s32 arg1);
extern void func_0045aac0(s32, s32, s32);
extern s32 func_00110460(void);
extern void func_00105690(s32, s32);
extern void func_00105fa0(s32);
extern void func_0010b010(s32);
extern void func_002b68d0(s16, s32, s32);
extern void func_003147e0(u8 *arg0, s8, s64, s16, s16, s32);
extern void func_00324f80(u8 *arg0, s64, s32, s32);
extern void func_00330060(u8 *arg0, s32);
extern void func_0045af60(s32, s32, s32, s32);
extern void func_002b2a60(void *arg0, s32, s32, s32, s32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern u16 D_008C024E[];
extern f32 D_00640D78[];
extern void func_00106390(s32, s32);
extern void func_0044ea90(const void *, s32);
extern void func_0043f9c8(void *, s32, u32);
extern void func_0043f810(void *, void *, u32);
extern u8 *func_0010fcb0();
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00641B00[];
extern s32 func_0010b460(void);
extern void func_0010ad80(s32);
extern void func_0010b190(s16 *);
extern void func_0010b300(s32);
extern void func_0010b7f0(void);
extern void func_0010cad0(u16 *arg0, u16 arg1);
extern s64 func_00312c60(u16 *arg0, u8 *arg1, s64 arg2);
extern u8 *func_002e4870(s8 arg0);
extern s32 func_0010ce10(u8 *arg0, u32 arg1);
extern s32 func_00313690(s64 arg0);
extern u8 func_002e78a0(void);
extern u8 func_002e78e0(void);
extern s8 D_00641A60[];
extern s8 D_00749480[];
extern u8 *iGpffffb3d4;
extern u8 *iGpffffb44c;
extern s32 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s8 iGpffffa8a8;
extern u16 func_00107ac0(s32 arg0);
extern u16 *func_0010ac10(s32 arg0);
extern u8 func_00106600(s16 arg0);
extern u8 D_00641880[];
extern u8 D_0063FCA0[];
extern u8 D_006406F0[];
extern s32 func_00110a60(u32 arg0, u32 arg1);
extern s32 func_00303610(u8 *arg0, s8 arg1, u16 *arg2);
extern f32 D_00641660[];
extern u8 D_006417E0[];
extern u8 D_00882FAE[];
extern u8 D_00882FB0[];
extern u8 D_00882FB1[];
extern f32 func_00109190(void);
extern void func_0032f060(u8 *arg0, s32 arg1);
extern void func_0032f4d0(u8 *arg0);
extern void func_003307b0(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_002b2970(s64 *out, f32 x, f32 y);
extern void func_002b6c30(s32 a, s64 b, s32 c, f32 d);
extern void func_002b6a70(s32, s32, s32, s32, s32, s32);
extern void func_002eb270(u8 *arg0, s32 arg1);
extern void func_003205f0(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_002e8410(u8 *arg0);
extern s32 func_00452490(s32 arg0);
extern void func_00122640(s32, s32);
extern s32 func_00122720(void);
extern void func_00122520(s32, s32);
extern s32 func_002bb680(s8 arg0);
extern void func_002bbcf0(s8 arg0);
extern void func_002bb550(s8 arg0);
extern s32 func_004553c0(void *arg0);
extern void func_00144c90(s32, s32);
extern void func_00144e10(s32);
extern s32 func_00104f10(s32);
extern s32 func_0033e120(u8 *arg0, s32, s32);
extern void func_001075d0(s32);
extern s32 func_00144f60(void);
extern u8 *func_001452b0(s32);
extern void func_00479940(s32, s32, s32, s32, s32);
extern u8 *func_00457120(void);
extern f32 func_0014b4d0(void);
extern void func_004577d0(u8 *arg0, f32 arg1);
extern s32 func_0014b450(void);
extern void func_003e9cb0(s32, s32, s32);
extern void func_00331390(void);
extern s32 func_00331580(void);
extern void func_002e7ac0(void);
extern void func_002e82b0(void);
extern void func_00313b50(s32);
extern s32 func_0034a4f0(s32, s32);
extern s32 func_0034ad70(s32, u32, s32);
extern u8 *func_0034ae50(u8 *, s8);
extern s32 func_002b74f0(s32, s32);
extern void func_002b7750(s16, s16);
extern s32 func_0034b740(s32);
extern s32 func_002b8150(s32);
extern void *func_002b5c90(void *, u64);
extern void func_002b29e0(void *, f32, f32);
extern void func_002b5db0(s32, s64, void *);
extern void func_002b5e30(s32, u32);
extern void func_002b5e20(s32, f32);
extern void func_002b6130(s32, u32);
extern void func_002b6140(s32, u8);
extern void func_002b6120(s32, u8);
extern s32 func_0033e3f0(s32);
extern s32 func_002b9f90(s32, s16, s32);
extern s32 func_00331600(void);
extern u8 D_00641B10[];
extern s32 func_003145e0(s32);
extern s32 func_00285b30(u8);
extern s8 *func_0034a630(s32);
extern s8 func_00105f50(u32);
extern s32 func_00452490(s32);
extern void func_00452080(s32);
extern s32 func_00459760(void);
extern void func_0045a3e0(s32, s32);
extern void func_0030f4f0(u8 *, s16 *);
extern s32 func_00314320(u8 *);
extern void func_00320970(u8 *, s32);
extern void func_002b6c30(s32, s64, s32, f32);
extern void func_002b6b40(s32, s32, s32, s32, s32, f32);
extern void func_002b69f0(s32, s64, s64, s32, s32, s32);
extern void func_00315600(u8 *, s32);
extern void func_00316e80(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00302570(u8 *);
extern u8 *iGpffffb440;
extern f32 D_00640C50[];
extern f32 D_00640C58[];
extern u8 D_00641BB0[];
extern void func_00317900(u8 *, s64, s64, s8, s16, s16, s16);
extern u8 D_00640760[];
extern u8 D_00640790[];
extern u8 D_0064079C[];
extern u8 D_006407A8[];
extern u8 D_006407C0[];
extern u16 func_001102d0(void);
extern u16 func_00109470(u16);
extern void func_00110270(u8 *, u16);
extern void func_001102c0(s16);
extern u8 D_00749350[];




/* measured: best nd 12 (10 real + 2 padding). Structure is byte-identical
   to retail except the argument-materialization order at the five
   func_002b5c90 call sites: retail emits `move $a0,$s1` (temp_17) BEFORE
   the `ld $a1, 0xNN($sp)` (s64 vector), mwcc b210 always schedules the
   stack load first. Tried pointer/s32 temp_17, u64/s64 locals, explicit
   (void *) casts, declaration orders — all nd 12. Argument-evaluation
   order floor (also blocked the 0xB0 stack hole: retail frames the five
   16-byte func_002b29e0 outputs at 0x60-0xA0 and the ten s64s at 0xB8+,
   mwcc reproduces that exactly). */
// FUN_002E8410
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e8410);

// FUN_002E90D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002e90d0);

/* measured: attempt aborted — a scripted m2c-draft transform of this
   29.5KB state machine (72 s64 stack locals, ~30 func_00317900 7-arg
   calls) produced 90+ mwcc parse errors; the checked-in draft's
   (s64)(((...))-style paren/cast noise defeats mechanical adaptation and
   no clean measured nd was reached (compile never succeeded). Left as
   INCLUDE_ASM. */
// FUN_002EB270
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002eb270);

/* measured: full body adapted — best nd 31 (obj 1136B == window). (1) All 27
   entry stores: mwcc emits addu $v1,$s0,$v1 (base-first) for
   p + idx*0xA + 0xC4 in every source spelling (inline idx, idx-term-first,
   and the brief's s32-local addu-order recipe, which spilled and scored
   173); retail is addu $v1,$v1,$s0 (scaled-offset-first, canonicalized by
   the retail compiler). (2) D_00641660: mwcc rematerializes lui per lwc1
   and orders addiu $a0,sp first; retail materializes lui/addiu once before
   the stack arg (tried array reads, f32 locals, f32 *q, u32 base — all
   4 words off). addu-operand-order + base-rematerialization floor. */
/* measured wave 14: the base-hoist recipe (wave B) holds (FclVec2f *base =
   (FclVec2f *)D_00641660, base->x/base->y — single lui/addiu + two lwc1s,
   base-before-stack-arg, nd 27). Lever 3 (static inline addOffYFcl(u32
   offset, u32 base) { return (u8*)(offset + base); } at file scope, called
   addOffYFcl(idx*10, (u32)p) for every store) DOES flip the entry-store
   addu to scaled-first (verified: offset 0x8C = addu $v1,$v0,$s0 matches
   retail's scaled-first) — so the old note's "all source orders compile
   base-first" is WRONG for the inline helper. But it cascades: retail
   materializes the store VALUE constant (addiu $a1,0x23) BEFORE the index
   lb + address chain, while the helper form forces index-first and churns
   the address/value registers; best with helper + (s8) RMW p[0xB5]++
   increments nd 170 (vs 27 without helper). The residual is pure
   value-before-index scheduling + address/value register colouring, not
   the addu order. pragma opt_propagation off NOT tried — multi-store
   (27 stores) contraindicated per wave-14 rule. Best measured remains
   nd 27 (no helper). addu-order fixable via lever 3 but blocked by the
   value/index scheduling cascade. */
// FUN_002ECFC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002ecfc0);
// FUN_002ED430
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002ed430);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements when the value is an 8-byte struct passed
   BY VALUE (mechanism 1): take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0)
   compiles ldr $a1,0x38 / ldl $a1,0x3F, byte-identical to retail's 6 pairs
   here (0x28/0x2F + 0x38/0x3F, all 8-aligned, feeding func_002b69f0-style
   calls; the s64 spelling gives plain ld — the old note's 20+ probes never
   tried the struct form). Full body still INCLUDE_ASM: ~6200-line asm state
   machine; the m2c draft needs its M2C_ERROR ldr sites replaced with
   struct-by-value args plus the usual m2c-noise cleanup; no full-body nd
   measured. */
// FUN_002F0F00
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f0f00);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~3100-line
   asm; no full-body nd measured. */
// FUN_002F6CF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f6cf0);

// FUN_002F9C30
void func_002f9c30(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5, u8 *arg6, s32 arg7, s8 arg8, s8 arg9) {
    u8 buf[6][0x30];
    s8 v;

    switch ((s16)arg7) {
    case 0:
        break;
    case 6:
        func_0043f810(buf[5], arg6, 0x30);
        /* fallthrough */
    case 5:
        func_0043f810(buf[4], arg5, 0x30);
        /* fallthrough */
    case 4:
        func_0043f810(buf[3], arg4, 0x30);
        /* fallthrough */
    case 3:
        func_0043f810(buf[2], arg3, 0x30);
        /* fallthrough */
    case 2:
        func_0043f810(buf[1], arg2, 0x30);
        /* fallthrough */
    case 1:
        func_0043f810(buf[0], arg1, 0x30);
        break;
    }
    func_0010cad0(arg0, ((u16 *)arg0)[1]);
    v = (s8)func_00312c60(arg0, buf[0], (s8)arg7);
    *(func_002e4870(arg8) + arg9 + 0x2E4) = v;
}

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~2200-line
   asm; no full-body nd measured. */
// FUN_002F9D90
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002f9d90);

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 8 pairs here, all 8-aligned at
   0x38/0x3F; plain s64 gives ld). Full body still INCLUDE_ASM: ~6800-line
   asm state machine (also carries adda.s/madd.s FPU-MAC chains); no
   full-body nd measured. */
// FUN_002FBEA0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_002fbea0);

// FUN_00302570
s32 func_00302570(u8 *arg0) {
    u8 *p;
    s32 idx;
    s8 i;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0x130) = 0;
    i = 0;
    while ((s32)i < 4) {
        if ((func_00106330((s32)i + 0x1309) == 0) && (func_00110140() >= D_00749100[(s32)i])) {
            *(s8 *)(p + 0x130) = (s8)i;
            *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
            func_002bbd80(*(s8 *)(p + 0xD), 0, func_001067f0((s16)(*(s8 *)(p + 0x130) + 0x464)));
            func_002badc0(*(s8 *)(p + 0xD), *(s8 *)(p + 0x130) + 0x17);
            func_00106390((s32)i + 0x1309, 1);
            func_00106620((s16)(i + 0x464), 1);
            *(u8 *)(p + 1) = 0x97;
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_003026C0
s32 func_003026c0(s32 arg0, s32 arg1)
{
    s16 i;

    func_00109280(arg0);
    for (i = 0; i < 4; i++) {
        if (func_00106330(0x130C - i) != 0) {
            return arg1 - (arg1 / 100) * (0x19 - i * 5);
        }
    }
    return arg1;
}

/* measured (re-tested wave C): the old floor note was STALE — b210 DOES emit
   the pair at 0-mod-8 displacements for an 8-byte struct passed BY VALUE
   (probe: take(0x151, *(FclVec2f *)(p + 0x38), *sp, 1, 4, 0) -> ldr $a1,0x38 /
   ldl $a1,0x3F, byte-identical to retail's 4 pairs here at 0x38/0x3F feeding
   func_002b69f0; plain s64 gives ld). Full body still INCLUDE_ASM: ~950-line
   asm state machine; no full-body nd measured. */
// FUN_00302770
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00302770);

/* wave 14: signature re-checked via the m2c oracle and the retail prologue
   (dsll32 $16,$5,24 / dsra32 = byte sign-extend): arg1 IS s8 (the m2c's
   s64 arg1 is widening noise — the current extern s32 func_00303610(u8 *,
   s8, u16 *) is correct, no lever-1 fix). The residual (case-local loop
   counters j/k in $s5/$s3 + jtbl switch 1-10 + const-1 hoist for case 6's
   flag set) is saved-register rotation + const-hoist; every wave-14 lever
   checked (no global base, no addu-order site, slt uses slti not the $at
   form). Best nd 131 unchanged. */
/* measured: retail allocates case-local loop counters as temps ($a1/$a3)
   and splits j/k across $s5/$s3, hoists the const 1 for case 6's flag set
   (move $s2,$a0), and lands the flag check at 0x3039A8; mwcc b210 keeps j
   in saved $s3 across all cases, swaps j/k to $s3/$s5, re-materializes
   addiu $s2,1 at each flag site, and lands the check 4 bytes earlier
   (every branch target after shifts by 4). Structure verified identical
   (switch 1-10 via jtbl, nested loops, flag=0 reset, i=0/n/tail setup
   order, ++ increments). Best nd 131. Saved-register rotation + const
   hoist floor. */
// FUN_00303610
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303610);

// FUN_00303A20
void func_00303a20(u8 *arg0) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    u16 buf[7];

    switch (p[0x1A]) {
    case 2:
        buf[0] = *(u16 *)(func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[2] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 3:
        buf[0] = *(u16 *)(func_002e48a0(0, p[0x128]) + 1);
        buf[1] = *(u16 *)(func_002e48a0(0, p[0x129]) + 1);
        buf[2] = *(u16 *)(func_002e48a0(0, *(s16 *)(p + 0x11E)) + 1);
        buf[3] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 4:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 5:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    case 6:
        buf[0] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 0) + 1);
        buf[1] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 1) + 1);
        buf[2] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 2) + 1);
        buf[3] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 3) + 1);
        buf[4] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 4) + 1);
        buf[5] = *(u16 *)(func_002e48a0((s8)(*(s16 *)(p + 0x11E) + 1), 5) + 1);
        buf[6] = *(u16 *)(func_002e48a0(p[0x2F9], p[0x2FA]) + 1);
        break;
    }
    func_00303610(arg0, p[0x1A], buf);
}

/* wave 14: the else-branch table store fold (addiu 0x70 into sw vs retail's
   separate addiu) is the SAME stack-table family that broke in func_00308e50
   — but there the fix was the table INITIALIZER (individual stores), not the
   load/store address form, and here the table is filled by genuine stores;
   array spelling retains the fold (nd 132 unchanged). Residual remains the
   saved-register rotation p=$s4,n=$s1,total=$s2,baseA=$s3 vs mine (all
   orders) + the fold. opt_propagation off contraindicated (multi-store
   loops per wave-14 rule). Best nd 132 unchanged. */
/* measured (re-tested wave B): the global-base-hoist recipe WORKS here —
   s8 *baseA = (s8 *)D_0063FCA0 + p[0x2D4]*0x1C and s8 *baseB = (s8 *)
   D_006406F0 + (s8)func_00110a60(...)*0x14 reproduce retail's single
   lui/addiu base registers. Best nd 132 (obj 732B vs window 752B):
   for-loops give retail's pre-jump + bottom-condition shape; inline
   (s16)var_x casts in BOTH condition and body give retail's double
   dsll32/dsra32 per iteration (a body s32 temp gets CSE'd into one ext);
   #pragma opt_loop_invariants on DOES hoist the 0x64 consts into both
   preheaders (nd 147 -> 132; the earlier note's "makes no difference"
   applied to a different source shape). Residual: saved-register rotation
   (p=$s0,n=$s2,total=$s1,baseA=$s4 vs retail p=$s4,n=$s1,total=$s2,
   baseA=$s3, all decl orders probed) + the else-branch table store folds
   addiu $x,0x70 into sw where retail keeps the addiu (stack-table fold
   family); the earlier note's 0x64-remat/r-re-ext claims are both
   source-drivable after all. */
// FUN_00303DE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00303de0);

/* wave 14: signature re-checked via the m2c oracle (m2c says s64 arg1/arg2
   but both are used as 16/8-bit values with (s16)/(s8) casts — the caller is
   an INCLUDE_ASM stub so no extern to fix; the function is only called from
   the asm func_00304580). All wave-14 levers checked: no addu-order site
   (the loops' addressing matches), no global base, no jtbl; residual is the
   documented saved-register rotation + post-loop const-fold. Best nd 100
   unchanged. */
/* measured: full m2c-adapted body tried (copy loop, both rand()%100 slots,
   key loop, 2d00/2cb0 pair, c/j loop, func_003042f0 tail) — best nd 100.
   (1) b210 constant-folds a post-loop `key = 4` across the loop's break path
   (kills the break-path key=(s8)i, folds the call arg to addiu $a1,0,4); the
   break-skipping spellings (key=4 inside the loop, pre-loop default, guarded
   if) cost 110-114. (2) Saved-register rotation in the second half: retail
   v20=$s4,c=$s3,v2=$s1,j=$s5,p=$s2,arg1=$s3 vs all decl-order variants
   v20=$s5,c=$s4,v2=$s2,j=$s1,p=$s3,arg1=$s1. (3) First-loop temps r/v/i land
   in $a1/$a0/$v1 vs retail $a0/$a1/$a2 (declaration swaps don't move them).
   Saved-register rotation + const-propagation floor. */
// FUN_003040D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003040d0);

// FUN_003042F0
s32 func_003042f0(s32 arg0, s32 arg1)
{
    switch ((s8)arg1) {
    case 1:
        return D_00749040[(s8)arg0];
    case 2:
        return D_00749060[(s8)arg0];
    case 3:
        return D_00749080[(s8)arg0];
    case 4:
        return D_007490A0[(s8)arg0];
    case 5:
        return D_007490C0[(s8)arg0];
    case 6:
        return D_007490E0[(s8)arg0];
    }
    return -1;
}

/* measured: full body now MATCH. Retail copies six 8-byte blocks into an
   sp+0x4F0 buffer, fills an sp+0x70 s16 table from the func_00313690 key
   loop, then retries rand()%count until func_0010ce10 succeeds. The copy
   buffer is declared before the table so the stack offsets match, and the
   copy loop uses two s32 load/store temporaries with the counter decrement
   between pointer increment and stores. The random divisor is a separate s32
   local after the sign-extended s64 count; a signed modulo result and named
   s16 *entry table pointer force retail's dsll32/dsra32 remainder and its
   separate addiu 0x70 before lhu. Scoped verify reports byte-exact MATCH. */
// FUN_00304410
u16 func_00304410(u8 *arg0, s64 arg1) {
    u8 copy[0x30];
    s16 table[0x240];
    u8 *src;
    u8 *dst;
    s32 temp_1;
    s32 temp_2;
    s32 copy_count;
    s64 arg1_saved;
    s64 key;
    s64 count;
    s32 j;
    s32 i;
    s64 j_mask;
    s8 retry;
    s32 divisor;
    s16 *entry;
    u16 selected;
    s64 bound;

    arg1_saved = arg1;
    src = arg0;
    dst = copy;
    copy_count = 6;
    do {
        temp_1 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        copy_count -= 1;
        *(s32 *)dst = temp_1;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (copy_count > 0);
    key = (s16)func_00313690(arg1_saved);
    count = (s16)key;
    i = 0;
    retry = 0;
    j = 0;
    bound = (s16)arg1_saved;
    goto scan;
scan_body:
    key = (s16)func_00313690((s16)j);
    if (count == (s16)key && bound != j_mask) {
        table[(s16)i] = (s16)j;
        i = (s16)(i + 1);
    }
    j = (j + 1) & 0xFFFF;
scan:
    j_mask = (u16)j;
    if (j_mask < 0x240) goto scan_body;
    j_mask = (s16)i;
    divisor = (s32)j_mask;
    do {
        entry = table + (s16)(func_003b7060() % (u32)divisor);
        selected = *entry;
        if (func_0010ce10(copy, selected) == -1) {
            retry = 1;
        }
    } while ((s8)retry == 0);
    return selected;
}
// FUN_00304580
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00304580);

/* measured: same stack-lookup-table floor as func_00308e50 — retail loads
   tbl[i] via sll/addu($sp)/addiu(0x48)/lh ($v0); mwcc b210 folds the 0x48
   into the load displacement in every spelling (array-index nd 42,
   byte-offset arithmetic nd 42), shifting all following words by one. */
/* MATCHED wave 14: the stack-table INITIALIZER was the real defect, not the
   load form. A `s16 table[4] = {…}` initializer makes mwcc load the 4
   constants from a gp-relative pool (lh $a2,($gp) x4) instead of retail's
   four addiu/sh pairs; writing `table[0]=0xD; table[1]=0x35; …` as
   individual stores reproduces retail exactly (the sll/addu/sp/addiu(0x48)/
   lhu load shape then matches byte-for-byte). nd 95 -> 1 -> MATCH. Note the
   return type is u16* (returns the raw func_002e48a0 results), and the
   per-iteration args reload p[0x128]/p[0x129] with (s8) hunches. */
// FUN_00308CC0
u16 *func_00308cc0(u8 *arg0) {
    s16 table[4];
    s8 *p = *(s8 **)(arg0 + 0x38);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == func_002e48a0(0, p[0x128])[1]) {
            return func_002e48a0(0, p[0x129]);
        }
        if (table[i] == func_002e48a0(0, p[0x129])[1]) {
            return func_002e48a0(0, p[0x128]);
        }
    }
    return 0;
}
// FUN_00308DC0
s32 func_00308dc0(void)
{
    s16 i;
    s32 temp;
    s8 *p;

    temp = (u8)(func_003b7060() % 100U);
    i = 0;
    p = D_007490F8;
    while (i < 6) {
        if (temp < p[i]) {
            return (s8)i;
        }
        i++;
    }
    return 5;
}
/* measured: retail loads the stack lookup table via sll/addu($sp)/addiu(0x48)
   then lh ($v0); mwcc b210 folds the 0x48 into the load displacement
   (sll/addu/lh 0x48($v0)) no matter the spelling — probed array-index,
   named pointer, byte-offset arithmetic, for-loop, initializer-list, and
   #pragma schedule on (nd 56); best nd 40. Same floor family as func_00308f40. */
/* MATCHED wave 14: same fix as func_00308cc0 — the table INITIALIZER was the
   defect. Individual stores `table[0]=0xD; …` (not the array initializer,
   which pulls the 4 constants from a gp pool) reproduce retail's addiu/sh
   pairs; the sll/addu/sp/addiu(0x48)/lh read immediately matches, and the
   loop/branch layout falls into place (nd 10 -> 1 benign padding -> MATCH).
   Key types: table is s16[4], p is the s8* work at arg0+0x38, table compare
   against func_002e48a0(0, p[0x128])[1] / [0x129] with (s8)i return. */
// FUN_00308E50
s32 func_00308e50(u8 *arg0) {
    s16 table[4];
    s8 *p = *(s8 **)(arg0 + 0x38);
    s16 i;
    table[0] = 0xD;
    table[1] = 0x35;
    table[2] = 0x49;
    table[3] = 0x66;
    for (i = 0; i < 4; i++) {
        if (table[i] == func_002e48a0(0, p[0x128])[1]) return (s8)i;
        if (table[i] == func_002e48a0(0, p[0x129])[1]) return (s8)i;
    }
    return -1;
}
/* floor (above marker kept clear for the verifier): the array-address
   sequence sll/addu(sp)/addiu(0x48) vs mwcc's sll/addiu/addu with swapped
   $v0/$v1 coloring — probed array, pointer, named-temp, separate-locals,
   byte-offset forms and schedule/opt_* pragmas; best nd 4 (scheduling). */
/* measured (wave C retest): full body adapted from the m2c draft — best
   nd 182, obj 1712B == window, every residual row is a saved-register
   swap except one: b210 drops the andi 0xF on the (s8)((x >> 0xC) & 0xF)
   nibble extract (sra 12; dsll32/dsra32, no mask; the other three nibbles
   keep theirs; two-statement and use-site-cast spellings both drop it —
   recorded as a fold floor). Key spellings that DID land: func_00109470
   declared u16-returning so b210 emits the andi 0xFFFF result mask before
   the user's bit-test andi (s32 return folds the chain to one andi); u16
   parameter so the var_20 & 0xFFFF arg mask lands at each call site (an
   explicit & 0xFFFF arg gets CSE-hoisted into a saved register and grows
   the frame to 0x80); (u8) store slots kill the (s8) sign-extension pair
   after the 2b2cb0 andi. Residual rotation: mine temp_17=$s3,temp_16=$s2,
   temp_19=$s0,var_18=$s4,var_20=$s1 vs retail temp_17=$s1,temp_16=$s0,
   temp_19=$s3,var_18=$s2,var_20=$s4 — declaration orders probed, no
   change. The earlier "best nd 4" note was wrong or belonged to another
   source shape; the previous agent's note was inaccurate about the 0x48
   stack table (none exists in this function). */
/* wave 14: re-checked the signature via the m2c oracle
   (void func_00308f40(void) — no args, correct); the nibble-extract fold
   and every residual row are saved-register swaps that resist decl order
   (all probed). No wave-14 lever applies (no global base, no jtbl reload,
   no addu-order site). Best measured nd 182 unchanged. */
// FUN_00308F40
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00308f40);

// FUN_003095F0
s32 func_003095f0(void)
{
    if (func_001102e0()[1] == 0xB3) {
        return 0xBA;
    }
    return 0xB3;
}

// FUN_00309630
s32 func_00309630(u16 arg0)
{
    s16 i;
    s32 key;

    i = 0;
    key = arg0;
    while (i < (u16)func_0010b6f0()) {
        if (key == *(u16 *)((u8 *)func_0010ace0(i) + 2)) {
            return 1;
        }
        i++;
    }
    return 0;
}
// FUN_003096D0
s32 func_003096d0(void)
{
    u32 temp_16;
    u16 *temp_17;
    s32 var_20;
    s32 var_19;
    s16 temp_18;
    u16 temp_16_2;

    var_19 = 0;
    var_20 = 0;
    while ((s16)var_20 < 4) {
        temp_16 = func_0010ceb0(func_001102e0());
        temp_18 = (s16)(func_003b7060() % temp_16);
    loop_2:
        temp_17 = &iGpffffb3ec[(s16)var_19 * 2];
        temp_16_2 = temp_17[0];
        if (temp_16_2 == func_0010cf40(func_001102e0(), temp_18)) {
            return var_19;
        }
        var_19 = (s16)(var_19 + 1);
        if ((temp_16_2 == 0) || (temp_17[1] == 0)) {
            var_20 = (s16)(var_20 + 1);
        } else {
            goto loop_2;
        }
    }
    return -1;
}
// FUN_003097E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_003097e0);

/* wave 14: signature re-checked via the m2c oracle (void func_0030b060(u8 *
   arg0) — correct). All wave-14 levers checked: the function has no global
   base, no jtbl reload, no addu-order site; residuals are the frame-size/saved-
   reg map (retail 0xB0 with a never-used $s6 vs mwcc 0xA0 six-save) and the
   switch/loop register schedule. opt_propagation off not applicable
   (multi-store switch). Best nd ~N/A unchanged. */
/* measured: retail's frame is 0xB0 with 7 saved GPR slots ($s6 saved but
   never used) while mwcc b210 allocates 6 saved regs (frame 0xA0), and the
   whole saved-register map rotates (mine arg0=$s1,p=$s0 vs retail
   arg0=$s5,p=$s2). Structure verified: switch 0xC2/0xC3/0xC4 with
   reversed tests, 4 separate s64 vector locals + 4 FclByte4 color locals,
   26.0f/cvt.s.w int-to-float args, per-call lbu/sb color copies, the
   6-way func_002b6970 guard, bit-flag dispatch chain, e/lim/k loop.
   Frame-size + saved-register rotation floor. */
// FUN_0030B060
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b060);

/* wave 14: signature re-checked via the m2c oracle (void func_0030b7b0(u8 *
   arg0) — correct). All wave-14 levers checked: no global base, no jtbl
   reload; residuals are the arg0/k saved-reg rotation, the (s8) increment-
   before-sb IR ordering, and the lbu/sb-per-byte vs load-all-store-all
   colour copies (FclByte4 struct copies compile 10B larger — struct form
   is the wrong direction). Best nd 295 unchanged. */
/* measured: full m2c-adapted body — obj 3088B == window, best nd 295 (all
   rows are register names + two scheduling patterns). Structural fixes that
   DID land: (s16) cast on the func_002b6970 result (retail sign-extends it),
   flag loads CSE'd into locals across the func_003307b0 calls (retail loads
   D_008C0276/027A/024E once), shared te pointer in the case-0xC3 loop
   (retail keeps &D_00882FB0[k*2] in a saved reg). Residuals: (1) saved-
   register rotation arg0=$s2,k=$s1 vs retail arg0=$s1,k=$s4 — all
   declaration orders probed, no change; (2) the (s8) increment narrowing
   pair is emitted before the sb (5 sites) vs retail store-first — IR
   ordering, schedule on/off and s32/s8 temps don't move it; (3) the 4-byte
   colour copies interleave lbu/sb per byte vs retail load-all-store-all
   (FclByte4 struct copies compile 10B larger); (4) retail materializes a
   te+1 pointer for the [1] reads. Saved-register rotation + scheduling
   floor. */
// FUN_0030B7B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030b7b0);

// FUN_0030C3C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030c3c0);

/* measured (wave 14): reconstructed the full body from retail (two for-loops
   over arg1[i] with a shared pre-header: id = func_0010b460() & 0xFFFF,
   n = p[0x1A] with ==7 -> 0xC, (s16)n bound hoisted). Lever 1 DID land: the
   arg1 parameter is really s16* not u16* — with u16* every element load
   compiled lhu vs retail's lh (extern corrected to s16*). Best of 5 attempts
   nd 66 (obj 344B / window 352B): for-loop with s16 counters gives retail's
   exact pre-jump + bottom-condition + one-ext/iteration shape (offsets
   116-148 match). Residuals, all measured: (1) retail hoists the second
   id mask (andi $s2,$s3,0xffff — the m2c draft has temp_18 = temp_19 &
   0xFFFF as a distinct var) and the (s16)n extension into the pre-header;
   the two-variable spelling (a/c/d) forces those instructions but balloons
   to 6 saved regs + a 0x18 s8-extension in the bound (nd 79, frame 0x80
   vs retail 0x70): the register-pressure interplay of the second mask,
   the n hoist and the 5-saved-reg map cannot be satisfied together in any
   spelling tried (single var 66, two-var 79, s8/s16/s32 n all 66-79).
   (2) saved-register rotation: mine p=$s1,id=$s2,n=$s3,i=$s4 vs retail
   p=$s0,id2=$s2,id=$s3,n=$s1,i=$s4 — all declaration orders probed.
   Saved-register rotation + pre-header hoist floor (previous best nd 47
   not reproducible; 66 is the new measured best). */
// FUN_0030F4F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030f4f0);



/* measured: best nd 654 (obj 3584B vs window 3632B). Complete faithful
   reconstruction verified against retail: switch dispatch order, D2-D7/0x97
   case bodies, nested jump-table switch (cases 2-7), the sp80[16] table,
   all func_002b7750-style call sequences, the 0xC4/0xC6/0xC8 record stores
   and the epilogue all match when aligned. Residual is purely
   argument-materialization ORDER at ~15 call sites (retail loads $a1 before
   $a0 on 2-arg calls and defers the (s8) arg casts to last; mwcc b210 emits
   forward order) plus the D3 sh/dsll32 pair and D5 (s8)-cast placement —
   tried s8-star/u8-star temp_18, (s8)/(u16) casts, pointer locals for the f32
   arrays, declaration orders; all nd ~654. Argument-evaluation-order
   scheduling floor. */
/* wave 14: signature re-checked via m2c oracle (void func_0030f650(u8 *arg0)
   — single-arg, correct); the residual is call-arg evaluation ORDER at ~15
   sites, which mwcc emits forward while retail loads $a1-first; every lever
   1-3 spelling keeps nd ~654. No wave-14 lever applies. Best nd 654
   unchanged. */
// FUN_0030F650
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_0030f650);

// FUN_00310480
s32 func_00310480(void) {
    u16 *p;
    s8 *base;
    s16 i;
    s8 *e;

    if (!(func_00107ac0(0x14) & 0xFFFF)) {
        return 0;
    }
    if ((func_00107ac0(0x14) & 0xFFFF) == 0xA) {
        return 0;
    }
    base = (s8 *)D_00641880 + ((func_00107ac0(0x14) & 0xFFFF) - 1) * 48;
    for (i = 0; i < 4; i++) {
        e = base + i * 12;
        switch (e[0]) {
        case 0:
            p = func_0010ac10(*(u16 *)(e + 4));
            if (p != 0) {
                if (func_0010ce10((u8 *)p, *(u16 *)(e + 8)) == -1) {
                    return 0;
                }
                break;
            }
            return 0;
        case 1:
            if ((func_00106600(*(s16 *)(base + i * 12 + 4)) & 0xFF) < *(s16 *)(base + i * 12 + 8)) {
                return 0;
            }
            break;
        case 2:
            if ((func_00107ac0(*(u16 *)(base + i * 12 + 4)) & 0xFFFF) > *(s16 *)(base + i * 12 + 8)) {
                return 0;
            }
            break;
        case 4:
            if (*(s16 *)(e + 8) == 0) {
                if (func_00106330(*(u32 *)(e + 4)) != 0) {
                    return 0;
                }
                break;
            }
            if (*(s16 *)(e + 8) == 1 && func_00106330(*(u32 *)(e + 4)) == 0) {
                return 0;
            }
            break;
        case 3:
            if (func_00110140() > *(s16 *)(e + 8)) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
// FUN_00310700
void func_00310700(void)
{
    s16 i;
    s16 j;

    func_0044ea90(&D_00641B00[0], 0x2ABD);
    iGpffffb594 = D_008873F4[0](1, 0x3004, 0x40000);
    func_0043f9c8(iGpffffb594, 0, 0x3000);
    i = 0;
    while (i < 0x100) {
        if (func_0010fcb0(i) != 0) {
            j = (s16)i;
            func_0043f810(iGpffffb594 + (s32)j * 0x30, func_0010fcb0(j), 0x30);
        }
        i++;
    }
    i = 0;
    while (i < 4) {
        *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 0;
        if (func_00106330((s16)i + 0x1309) != 0) {
            *(u8 *)(iGpffffb594 + (s16)i + 0x3000) = 1;
        }
        i++;
    }
}

// FUN_00310850
void func_00310850(void)
{
    s16 i;

    if (iGpffffb594 == NULL) {
        return;
    }
    i = 0;
    while (i < 0x100) {
        func_0010fd40(iGpffffb594 + i * 0x30);
        i++;
    }
    i = 0;
    while (i < 4) {
        if (*(s8 *)((u32)iGpffffb594 + i + 0x3000) == 1) {
            func_00106620((s16)(i + 0x464), 1);
            func_00106390(i + 0x1309, 1);
        }
        i++;
    }
    jtbl_008873EC[0](iGpffffb594);
    iGpffffb594 = NULL;
}

// FUN_00310960
void func_00310960(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *p;
    s8 t;

    p = *(u8 **)(arg0 + 0x38);
    *(s8 *)(p + 0xD) = func_002bab80((void *)func_00331660());
    t = *(s8 *)(p + 0xD);
    func_002badc0(t, (s8)arg1);
    if ((s8)arg2 == 1) {
        func_002bafc0(*(s8 *)(p + 0xD), 0);
        func_002bb0a0(*(s8 *)(p + 0xD), 0);
        func_002bbf60();
    }
}
// FUN_00310A10
void func_00310a10(u8 *arg0, s32 arg1) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    s8 *t;
    s32 s0;
    s32 s4;
    s32 s3;
    u8 x;

    s0 = D_00749480[func_002e78a0() & 0xFF] * 100 + (func_002e78e0() & 0xFF);
    x = iGpffffb3d4[(arg1 & 0xFFFF) * 14 + 2];
    t = D_00641A60 + x * 4;
    s4 = D_00749480[t[0]] * 100 + t[1];
    s3 = D_00749480[t[2]] * 100 + t[3];
    p[0xD] = func_002bab80((void *)func_00331660());
    func_002bbd80(p[0xD], 0, iGpffffb44c + (func_00109280(arg1) & 0xFF) * 21);
    if (s0 < s4) {
        func_002badc0(p[0xD], 0x2B);
    } else if (s0 >= s3) {
        func_002badc0(p[0xD], 0x2D);
    } else {
        func_002badc0(p[0xD], 0x2C);
    }
    func_002bafc0(p[0xD], 0);
    func_002bb0a0(p[0xD], 0);
    func_002bbf60();
}

// FUN_00310BF0
s32 func_00310bf0(u8 *arg0) {
    s8 *p = *(s8 **)(arg0 + 0x38);
    u8 *q;
    u8 *t2;
    s32 r2;

    switch (p[0]) {
    case 1:
        p[0] = 2;
        if (*(u32 *)(p + 0x1C) != 0) {
            *(u32 *)(p + 0x1C) = 0;
        }
        *(u32 *)(p + 0x1C) = func_002e8410(arg0);
        break;
    case 2:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            p[0] = 0;
            p[0] = 5;
        }
        break;
    case 3:
        func_00122640(1, 0);
        p[0] = 4;
        /* fallthrough */
    case 4:
        if (func_00122720() != 0) {
            p[0] = 1;
        }
        break;
    case 5:
        func_00122520(1, 0);
        p[0] = 6;
        /* fallthrough */
    case 6:
        if (func_00122720() != 0) {
            return -1;
        }
        break;
    case 7:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
        } else {
            func_002bb550(p[0xD]);
            p[0] = 1;
        }
        break;
    case 8:
        if (func_004553c0(*(u8 **)(p + 0x10)) != 0) {
            if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                if (func_00106330(0x1459) == 0) {
                    func_00144c90(8, 3);
                    func_00144e10(1);
                }
                p[0] = 9;
                return 0;
            }
            if (func_00106330(0x413) == 0 && func_00106330(0x96F) != 0 && (s16)func_00104f10(1) >= 3) {
                if (*(u32 *)(p + 0x1C) != 0) {
                    *(u32 *)(p + 0x1C) = 0;
                }
                *(u32 *)(p + 0x1C) = func_0033e120(arg0, 0x294, 0xA);
                func_00106390(0x413, 1);
                if (!(func_00107ac0(0x14) & 0xFFFF)) {
                    func_001075d0(0x14);
                }
                p[0] = 0xB;
                func_0045a3e0(0x14, 1);
                return 0;
            }
            if (func_00106330(0x1459) == 0) {
                func_00144c90(8, 3);
                func_00144e10(1);
            }
            p[0] = 9;
        }
        break;
    case 9:
        if (func_00144f60() != 0) {
            q = func_001452b0(3);
            while (q != 0) {
                if ((*(u16 *)q & 0x3FF) == 0x38) {
                    func_00479940(*(u32 *)(q + 0x164), 0, 0xD, 0, 1);
                }
                q = *(u8 **)(q + 0x138);
            }
            if (func_00106330(0x1459) == 0) {
                func_004577d0(func_00457120(), func_0014b4d0());
                t2 = func_00457120();
                r2 = func_0014b450();
                func_003e9cb0(*(u32 *)(t2 + 4), r2, 0);
            }
            func_00331390();
            func_0045a3e0(0x14, 1);
            p[0] = 0xA;
        }
        break;
    case 10:
        if (func_00331580() != 0) {
            if ((func_002e78a0() & 0xFF) == 3 && (func_002e78e0() & 0xFF) >= 0x14 && (func_002e78e0() & 0xFF) < 0x20) {
                p[0] = 0;
                p[0] = 3;
            } else if (func_00310480() == 1) {
                if (*(u32 *)(p + 0x1C) != 0) {
                    *(u32 *)(p + 0x1C) = 0;
                }
                *(u32 *)(p + 0x1C) = func_0033e120(arg0, 0x294, 1);
                p[0] = 0xE;
            } else {
                p[0] = 0;
                p[0] = 3;
            }
        }
        break;
    case 11:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            return -1;
        }
        break;
    case 12:
        if (func_00122720() != 0) {
            return -1;
        }
        break;
    case 14:
        if (func_00452490(*(u32 *)(p + 0x1C)) == 0) {
            p[0xD] = func_002bab80((void *)*(u32 *)(*(u8 **)(p + 0x10) + 0x110));
            func_002badc0(p[0xD], (func_00107ac0(0x14) & 0xFFFF) - 2);
            p[0] = 0xF;
        }
        break;
    case 15:
        if (func_002bb680(p[0xD]) != 0) {
            func_002bbcf0(p[0xD]);
        } else {
            func_002bb550(p[0xD]);
            if ((func_00107ac0(0x14) & 0xFFFF) == 0xA) {
                func_00106620(0x4A2, ((func_00106600(0x4A2) & 0xFF) + 1) & 0xFF);
            }
            p[0] = 0;
            p[0] = 1;
        }
        break;
    }
    return 0;
}
// FUN_003111D0
void func_003111d0(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    if (func_00106330(0x1459) == 0) {
        func_00145080();
    }
    if (func_00452380(D_00641BC8) != 0) {
        func_003315a0();
    }
    func_00454bd0(*(void **)(p + 0x10));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* wave 14: signature re-checked via m2c oracle — func_00311260 takes one
   arg (u8 *arg0), returns s32; correct. The slt $at vs $v0 on the
   b5b0>=n test is a cross-confirmed dead end (frFont measured the same
   slt $at pattern against all spellings; only the destination register
   differs). Every wave-14 lever checked: no global base, no jtbl reload,
   no addu-order site, no call-site extern — pure saved-register rotation
   (arg0/found/p/i map) that resists decl order. Best nd 62 unchanged. */
/* measured: retail colors arg0=$s0, found=$s1, p=$s2, i=$s2 and emits the
   slt of the b5b0>=n test into $at; mwcc b210 rotates to p=$s0, arg0=$s1,
   found=$s2, i=$s0 and writes the slt into $v0, in every declaration order
   probed (found-first, n<= and >= forms; best nd 62, all rows register
   names). Structure byte-identical otherwise (s32 loop counter, hoisted
   first found=0, (s8) check via found==0, shared b6f0 bound calls).
   Saved-register rotation floor. */
// FUN_00311260
INCLUDE_ASM("asm/nonmatchings/y_fclCombine", func_00311260);

