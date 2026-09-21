#include "include_asm.h"
#include "sdk_task_registration.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_snd_internal.h"

s32 func_00383720(u8 *arg0);
extern void func_002bb4e0(u8 *arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_002bb7c0(s32 a);
extern s32 func_002bb600(void);
extern void func_002bb1e0(s32 a);
extern void func_002bad10(s32 a);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern void func_0044ea90(const void *msg, s32 id);
extern void func_0046d730(const void *file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064EB60[];
extern u8 D_0064EC70[];

extern s32 func_00382ea0(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3);
extern s32 func_00378530(s32 a, s32 b);
extern void func_0036e000(u8 *arg0);
extern void *func_0036e900(void *arg0);
extern void func_0036f620(u8 *arg0);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00375d50(u8 *ctx, s32 idx, f32 c, f32 d, f32 *a, f32 *b);
extern void func_00374910(u8 *a);
extern s32 func_00375a00(u8 *a);
extern void func_00379090(u8 *ctx, s32 a, s32 b, s32 c);
extern void func_00388d60(s32 a);
extern s32 func_00388de0(s32 a);
extern void func_00388e00(s32 a);
extern s32 func_00388e20(s32 a);
extern void func_0038d310(s32 a);
extern void func_0038d970(s32 a);
extern void func_0038d9f0(s32 a);
extern void func_0038daf0(s32 a, s32 b);
extern void func_0038dcc0(s32 a, s32 b);
extern u32 func_00380d80(u8 *arg0, u32 arg1);
extern s32 func_00380ea0();
extern s32 func_00381a70();
extern s32 func_003816e0();
extern s32 func_00381830();
extern s32 func_00382ba0();
extern u16 *func_0010ace0(s16 a);
extern void func_0010cad0(u8 *dst, u16 id);
extern s32 func_0010b5b0(void);
extern s32 func_0010b460(void);
extern s32 func_00117780(s32 a, s32 b, s32 c, s32 d, s32 e);
extern u8 *func_00109220(u16 id);
extern void func_002bbd20(s32 a, void *text);
extern void func_002baf40(s32 a);
extern void func_002bb050(s32 a);
extern void func_002bbf60(void);
extern s32 func_002bb140(void);
extern void func_0011b480(s32 a, s32 b, u8 *c, s32 d);
extern void func_0011bb90(s32 a);
extern void func_0011bc70(s32 a);
extern void func_0011c180(s32 a, s32 b, u8 *c, s32 d);
extern void func_0011c2c0(s32 a, s32 b, u8 *c, s32 d);
extern void func_0011c630(s32 a);
extern void func_0011c6e0(s32 a, s32 b);
extern void func_0011caf0(s32 a);
extern void func_0011b360(s32 a);
extern void func_00453670(void *buf, s32 a, s32 b);
extern void func_004538e0(void *buf, s32 a, s32 b, s32 c, s32 d);
extern void func_00453860(void *buf, s32 a, s32 b, s32 c, s32 d);
extern void func_00453760(void *buf, s32 a);
extern s32 func_00453960(void *buf);
extern void func_0038d060(s32 a);
extern void func_0038d0d0(s32 a, s32 b);
extern void func_0038d0a0(s32 a);
extern void func_00388d20(s32 a);
extern void func_00388d40(s32 a);
extern void func_0010ad80(s32 a);
extern u8 *func_0010b060(u16 personaId);
extern u16 D_008C024E[];
extern s32 func_00106330(s32 a);
extern s32 func_00107890(s32 a);
extern s32 func_0015a190(void);
extern u8 func_002baac0(u8 *message);
extern void *func_0036e910(void *a);
extern s32 func_00377eb0(u8 *parent, s32 cardIndex);
extern void func_0038d2a0(s32 a);
extern u32 func_003b7060(void);
extern s32 func_00380bd0(u8 *a);
extern u8 D_0064E6E0[];
extern u8 D_0064E700[];
extern u8 iGpffffa9B8;
extern u8 D_0064E72E[];
extern s64 D_0064EC88;
extern f32 D_0064EC90;
extern s32 iGpffffa9E0;
extern s32 iGpffffa9E4;
extern void func_003761f0(u8 *a, s32 b, s32 c, u16 d, void *e, s32 f, f32 g);
extern void func_00375b40(u8 *a, s32 b, s32 c, s32 d);
extern s32 func_00378220(u8 *task);
extern s32 func_00388ec0(s32 a);
extern void func_00388e40(s32 a);
extern void func_00388ee0(s32 a);
extern void func_00388f00(s32 a);
extern void func_003892e0(s32 a);
extern s32 func_00389330(s32 a);
extern void func_00389350(s32 a);
extern void func_003798d0(u8 *a, s32 b);
extern s32 func_00379920(u8 *a);
extern s32 func_00380980(u8 *a);
extern u16 func_0010b6f0(void);
extern u8 *func_0010ac10(s32 a);
extern u8 *func_0010b010(u16 personaId);
extern char *func_002438b0(s32 a);
extern void func_00442830(char *dst, s32 value);
extern void func_00452080(s32 a);
extern void func_00106390(s32 a, s32 b);



/* measured: r3b_u16 271 words (probe_variants), retail 528 instrs vs object 529 */
/* (1 over, 0.2%, banks per 3% rule); fnalign 125 edits +10 reloc-only, */
/* frame 0xA0 vs retail 0xB0. m2c failed (jr without jump table at line 28); */
/* reconstructed from retail + Ghidra/IDA + sibling btlShuffle idiom. */
/* Wins: D_008C024E scalar -> array (absolute lui+lhu, exact count) and */
/* s32 cnt/cur &0xFFFF -> u16 (430->271). */
/* Tried and tied/worse, do not repeat: sum 0x1C+0x20 swap, slot addu */
/* state-first/sum-first casts, slot reuse vs recompute (worse), for vs while, */
/* block-scope counters, s16 i (worse), decl swap, u32 sum, u32 buf, u16 j */
/* (worse), (s16) compare (worse). */
/* Walls: retail hoists case-0 slot-address (sll/addu/addiu -> $s6, 7 saved */
/* regs) above func_0010ace0 jal; b210 sinks to store after (6 regs) in all */
/* spellings; remaining addu rs/rt swaps and loop extra andis are downstream. */
// FUN_00380EA0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00380ea0(u8 *arg0)
{
    u8 *state;
    s32 sum;
    u16 cnt;
    u16 cur;
    s32 i;
    s32 j;
    u16 *slotp;
    u8 buf[0x30];
    s32 res;

    state = arg0 + 0x18;
    sum = *(s32 *)(arg0 + 0x1C) + *(s32 *)(arg0 + 0x20);
    switch (*(s32 *)state) {
    case 0:
        func_0010cad0(state + 0x1C, *(u16 *)(arg0 + 0x10));
        *(u8 **)(state + 0x4C) = state + 0x1C;
        cnt = (u16)func_0010b5b0();
        cur = (u16)func_0010b460();
        j = 1;
        for (i = 0; i < cnt; i++) {
            slotp = func_0010ace0((s16)i);
            *(u16 **)(state + j * 4 + 0x4C) = slotp;
            if (*(u16 *)((u8 *)slotp + 2) != cur) {
                j++;
            }
        }
        res = func_00117780(*(s32 *)(*(u8 **)arg0 + 0x1F290), 0x12, 2, 5, 5);
        *(s32 *)(state + 0x18) = res;
        *(s32 *)(state + 0x0C) = j;
        *(s32 *)state = 1;
        *(s32 *)(state + 0x10) = 0;
        *(s32 *)(state + 0x14) = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)state = 2;
            {
                s32 v;
                v = *(s32 *)(*(u8 **)arg0 + 0x1F298);
                {
                    func_0038d060(v);
                    func_0038d0d0(v, 4);
                }
                func_00388d20(*(s32 *)(*(u8 **)arg0 + 0x1F294));
            }
        }
        break;
    case 2:
        if (*(s32 *)(state + 0x14) == 0) {
            if (D_008C024E[0] & 0x40) {
                u8 *txt;
                txt = func_00109220(*(u16 *)(*(u8 **)(state + sum * 4 + 0x4C) + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
                func_0045af60(0, 4, 0, 1);
            } else if (D_008C024E[0] & 0x80) {
                func_0011b480(*(s32 *)(state + 0x18), 1, *(u8 **)(state + sum * 4 + 0x4C), 0);
                func_0011bb90(*(s32 *)(state + 0x18));
                *(s32 *)state = 3;
            } else {
                func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
                func_004538e0(buf, 0x4000, 0x1000, 0, 0);
                if (func_00453960(buf) != 0) {
                    *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                    *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                    func_0045af60(0, 4, 0, 0);
                }
            }
        }
        break;
    case 3:
        if (D_008C024E[0] & 0x40) {
            func_0011bc70(*(s32 *)(state + 0x18));
            {
                u8 *txt;
                txt = func_00109220(*(u16 *)(*(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C) + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            func_0011bc70(*(s32 *)(state + 0x18));
            *(s32 *)state = 2;
            func_0045af60(0, 4, 0, 4);
        } else if (D_008C024E[0] & 0x80) {
            func_0011c630(*(s32 *)(state + 0x18));
            *(s32 *)state = 4;
        } else {
            func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
            func_00453860(buf, 8, 4, 0, 0);
            func_00453760(buf, 0);
            res = func_00453960(buf);
            if (res > 0) {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                if (res == 2) {
                    func_0011c180(*(s32 *)(state + 0x18), 1, *(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C), 0);
                } else if (res == 1) {
                    func_0011c2c0(*(s32 *)(state + 0x18), 1, *(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C), 0);
                }
            }
        }
        break;
    case 4:
        if ((D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x20)) {
            func_0011c6e0(*(s32 *)(state + 0x18), 1);
            *(s32 *)state = 3;
        } else if (D_008C024E[0] & 0x40) {
            func_0011bc70(*(s32 *)(state + 0x18));
            {
                u8 *txt;
                txt = func_00109220(*(u16 *)(*(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C) + 2));
                func_002bbd20(0, txt);
                func_002bad10(4);
                func_002baf40(5);
                func_002bb050(1);
                func_002bbf60();
                *(s32 *)state = 5;
                func_0045af60(0, 4, 0, 1);
            }
        } else {
            func_00453670(buf, 0xC, *(s32 *)(state + 0x0C));
            func_00453860(buf, 8, 4, 0, 0);
            func_00453760(buf, 0);
            res = func_00453960(buf);
            if (res <= 0) {
                func_0011caf0(*(s32 *)(state + 0x18));
            } else {
                *(s32 *)(state + 4) = *(s32 *)(buf + 0x24);
                *(s32 *)(state + 8) = *(s32 *)(buf + 0x28);
                if (res == 2) {
                    func_0011c180(*(s32 *)(state + 0x18), 1, *(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C), 0);
                } else if (res == 1) {
                    func_0011c2c0(*(s32 *)(state + 0x18), 1, *(u8 **)(state + (*(s32 *)(state + 4) + *(s32 *)(state + 8)) * 4 + 0x4C), 0);
                }
                *(s32 *)state = 3;
            }
        }
        break;
    case 5:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            res = func_002bb140();
            if (res == 1) {
                func_002bb1e0(1);
                *(s32 *)state = 2;
            } else if (res == 0) {
                func_0011b360(*(s32 *)(state + 0x18));
                *(s32 *)(state + 0x18) = 0;
                func_0038d0a0(*(s32 *)(*(u8 **)arg0 + 0x1F298));
                func_00388d40(*(s32 *)(*(u8 **)arg0 + 0x1F294));
                {
                    u8 *slot;
                    u8 *txt;
                    slot = *(u8 **)(state + sum * 4 + 0x4C);
                    txt = func_00109220(*(u16 *)(slot + 2));
                    func_002bbd20(0, txt);
                    func_002bad10(6);
                    *(s32 *)state = 6;
                    if (sum != 0) {
                        func_0010ad80(*(u16 *)(slot + 2));
                        func_0010b060(*(u16 *)(arg0 + 0x10));
                    }
                }
            }
        }
        break;
    case 6:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            return 1;
        }
        break;
    default:
        func_0046d730(D_0064EC70, 0x3F4);
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00380ea0);
#endif

// FUN_003816E0
s32 func_003816e0(u8 *arg0) {
    u8 *p = arg0 + 0x18;
    switch (*(s32 *)(arg0 + 0x18)) {
    case 0:
        *(s32 *)p = 1;
        /* fallthrough */
    case 1:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(u16 *)(arg0 + 4) & 2) {
                func_0043f9c8(arg0 + 0x18, 0, 0xC);
                *(s32 *)(arg0 + 8) = 4;
            } else {
                func_002bad10(8);
                *(s32 *)p = 2;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(u16 *)(arg0 + 4) & 1) {
                func_0043f9c8(p, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                func_002bad10(0xB);
            } else {
                return 1;
            }
        }
        break;
    }
    return 0;
}

/* Two levers, both recorded as impossible by the previous note: the counter
   store lands before the compare mask because the compound assignment's VALUE
   is used (see the measured comment at the site), and the single `return 0`
   after the switch gives retail's one shared zero-return block placed last,
   with the case bodies laid out in ascending declaration order. */
// FUN_00381830
s32 func_00381830(u8 *arg0)
{
    s32 *state = (s32 *)(arg0 + 0x18);
    s32 count;
    s32 i;
    u8 *base;
    s32 bumped;

    switch (*(s32 *)(arg0 + 0x18)) {
    case 0:
        *state = 1;
        /* fallthrough */
    case 1:
        if ((s32)*(u16 *)(arg0 + 6) < 0xA) {
            /* measured: the compound assignment's VALUE keeps the incremented
               counter in one register, so b210 emits the sh before the andi
               exactly as retail does; a separate `cnt = cnt + 1; store;` pair
               masks first. */
            bumped = (*(u16 *)(arg0 + 6) += 1);
            if ((bumped & 0xFFFF) == 0xA) {
                func_0045af60(1, 1, 5, 0xC);
            }
        }
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(u16 *)(arg0 + 4) & 2) {
                func_0043f9c8(arg0 + 0x18, 0, 0xC);
                *(s32 *)(arg0 + 8) = 4;
            } else {
                base = *(u8 **)arg0;
                count = func_00378530(*(s32 *)(base + 0x1F304),
                                      *(s32 *)(base + 0x1F2FC));
                for (i = 0; i < count; i++) {
                    if (i != *(s32 *)(base + 0x1F308)) {
                        if (*(u16 *)(base + (i * 0xE8) + 0x1D6A0) & 2) {
                            func_0046d730(D_0064EC70, 0x8C);
                        }
                        func_0036e000(base + (i * 0xFB0));
                    }
                }
                func_002bad10(0xA);
                *state = 2;
            }
        }
        break;
    case 2:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            func_0036f620((u8 *)func_0036e900(*(void **)(*(u8 **)arg0 + 0x1F2A8)));
            return 1;
        }
        break;
    }
    return 0;
}

/* measured: structure fully recovered from m2c (20-case jump-table state
   machine, case-1 init twin of func_00382ba0 case-0, case-5 with the three
   random chains + decoded FMA chain `1.0f + (1.0f + 20.0f * (rf / 4096.0f))`
   reproducing retail's adda.s/madd.s, cases 7-19 incl. D_0064E72E/
   D_0064EC88/D_0064EC90 lookups and iGpffffa9E0/a9E4 GPREL loads) but nd 989:
   (1) every random chain carries the recorded b210 floors â€” or-fold
   `or $v0,$v1,$v0` vs retail `or $v1,$v1,$v0`, cvt-scratch `cvt.s.w $f0,$f0`
   + `add.s $f1,$f0,$f0` vs retail `cvt.s.w $f1,$f0; add.s $f1,$f1,$f1`,
   guard-polarity bc1f-inline-overflow vs retail bc1t-inline-cvt (same as
   func_00372960/effBlurFilter notes), and the definition-site andi of
   `(f()!=0) & 0xFF` temps sunk to first use; (2) the case-1 stack scalars do
   not land at retail's 0x128/0x12C/0x130/0x138 with the 0x118/0xD0/0x90/0x50
   buffers (mwcc packs sp128 above sp138 at 0x13C â€” same layout family as the
   func_00382ba0 sp38 slot floor); (3) arg0/ctx saved-register swap plus one
   extra saved register ($s4) vs retail's 4 â€” declaration order and
   block-scope old-style decls (func_002bb4e0, func_003816e0) verified as the
   only ways to get retail's no-arg jals. */
/* measured: cold reconstruction from romwright (20-case jtbl_00752BB0 switch 0-19, case-1 twin of func_00382ba0 case-0 with 10.0f/316.0f/211.0f/160.0f, random chains with (f32)(u32 & 0xFFF) and 100.0f*(rf/4096.0f) plus FMA 1.0f+(1.0f+20.0f*(rf/4096.0f)) for adda/madd, D_0064E72E/D_0064EC88/D_0064EC90 and iGpffffa9E0/a9E4). probe 791 words (baseline 825, thrPtr *-form -34), fnalign 298 edits +11 reloc-only, retail 1100 vs object 1126 (+26, +2.36% inside 1067-1133 3% gate). Free pragmas tie/worse in one batch (common_subs 845, peephole 961, loopinv/unroll/schedule/dead 825); subscript E8/FB0 tie 825; address-all 819 worse, near tie; colour swap 793 worse, tmp-first tie. No loops so 7n N/A. Walls: s0/s1/s2 exchange plus stack +0x10 shift (object 0x138/0x13C/0x120 vs retail 0x128/0x12C/0x118), or-fold/cvt-scratch/guard-polarity as prior note. */
// FUN_00381A70 NONMATCHING
#ifdef NON_MATCHING
s32 func_00381a70(u8 *arg0)
{
    void func_002bb4e0(void);
    u8 *ctx;
    s32 *st;
    f32 fsrc[2];
    f32 fdst[4];
    u8 bufD0[72];
    u8 buf90[64];
    u8 buf50[64];
    s64 st88;
    f32 st90;
    s32 tmp;
    s32 tmp2;
    u32 rnd;
    f32 rf;
    s32 chance;
    s32 hit;
    u8 thresh;
    u8 kind;
    u16 cnt;
    u16 cur;
    u16 id;

    ctx = *(u8 **)arg0;
    st = (s32 *)(arg0 + 0x18);
    switch (*st) {
    case 0:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *st = 1;
        }
        break;
    case 1:
        *(f32 *)(ctx + 0x1F310) = 10.0f;
        func_00374910(ctx);
        fsrc[0] = 316.0f;
        fsrc[1] = 211.0f;
        func_0036dc60(ctx + *(s32 *)(ctx + 0x1F308) * 0xFB0, &fsrc[0], &fdst[0], 160.0f);
        func_00375d50(ctx, *(s32 *)(ctx + 0x1F308), 0.0f, 0.0f, &fdst[0], &fdst[0]);
        func_0038d9f0(*(s32 *)(ctx + 0x1F29C));
        func_0038d970(*(s32 *)(ctx + 0x1F29C));
        func_00388e40(*(s32 *)(ctx + 0x1F294));
        func_0038daf0(*(s32 *)(ctx + 0x1F29C), 6);
        *st = 2;
    case 2:
        tmp = func_00378220((u8 *)*(s32 *)(ctx + 0x1F2A0));
        if (tmp != 0) {
            tmp = func_00388ec0(*(s32 *)(ctx + 0x1F294));
            if (tmp != 0) {
                func_00375b40(ctx, *(s32 *)(ctx + 0x1F308), 0, 0x14);
                *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 8);
                *st = 3;
                goto lab_1c60;
            }
        }
        break;
    case 3:
lab_1c60:
        tmp = func_00375a00(ctx + *(s32 *)(ctx + 0x1F308) * 0xE8 + 0x1D6A0);
        if (tmp != 0) {
            *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) & 0xFFFB);
            tmp = func_00106330(0x1434);
            if (tmp == 0) {
                func_002bb4e0();
                func_003798d0(ctx, 4);
                *st = 0x13;
            } else {
                *st = 4;
            }
        }
        break;
    case 4:
        func_002bbd20(0, func_002438b0(*(u8 *)(arg0 + 0x12)));
        func_002bad10(0xC);
        func_002baf40(0xD);
        func_002bb050(0);
        func_002bbf60();
        *st = 5;
        break;
    case 5:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            tmp = func_002bb140();
            if (tmp == 2) {
                func_002bad10(((*(u8 *)(arg0 + 0x12) - 1) & 0xFF) * 4 + 0x15);
                *st = 6;
            } else if (tmp == 1) {
                return 1;
            } else if (tmp == 0) {
                *(u16 *)(arg0 + 0x1C) = 0;
                if (*(u8 *)(arg0 + 0x12) == 1) {
                    *st = 10;
                    *(s32 *)(arg0 + 0x20) = 0;
                    kind = *(u8 *)(arg0 + 0x12);
                    tmp = func_00106330(0x1437);
                    if (tmp == 0) {
                        func_00106390(0x1437, 1);
                        hit = 1;
                    } else {
                        tmp = func_00106330(0x1403);
                        if (tmp == 0) {
                            tmp2 = func_0015a190();
                            thresh = *(D_0064E72E + kind * 2 + (tmp2 != 0));
                        } else {
                            tmp = func_00106330(0x140F);
                            if (tmp == 0) {
                                tmp2 = func_0015a190();
                                thresh = *(D_0064E72E + kind * 2 + (tmp2 != 0));
                            } else {
                                thresh = 0x3C;
                            }
                        }
                        rnd = func_003b7060() & 0xFFF;
                        rf = (f32)rnd;
                        if ((100.0f * (rf / 4096.0f)) < (f32)thresh) {
                            hit = 0;
                        } else {
                            hit = 1;
                        }
                    }
                    *(s32 *)(arg0 + 0x28) = hit;
                    rnd = func_003b7060() & 0xFFF;
                    rf = (f32)rnd;
                    *(u8 *)(arg0 + 0x24) = (u8)(1.0f + (1.0f + 20.0f * (rf / 4096.0f)));
                    *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 0x20);
                    *(s32 *)(ctx + 0x1F2A4) = func_00377eb0(*(u8 **)(ctx + 0x1F2A8), (*(u8 *)(arg0 + 0x24) - 1) & 0xFF);
                } else {
                    *st = 7;
                    *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 0x10);
                    rnd = func_003b7060() & 0xFFF;
                    rf = (f32)rnd;
                    *(s32 *)(arg0 + 0x20) = ((s32)(3.0f * (rf / 4096.0f)) + 5) * 2;
                    kind = *(u8 *)(arg0 + 0x12);
                    tmp = func_00106330(0x1437);
                    if (tmp == 0) {
                        func_00106390(0x1437, 1);
                        hit = 1;
                    } else {
                        tmp = func_00106330(0x1403);
                        if (tmp == 0) {
                            tmp2 = func_0015a190();
                            thresh = *(D_0064E72E + kind * 2 + (tmp2 != 0));
                        } else {
                            tmp = func_00106330(0x140F);
                            if (tmp == 0) {
                                tmp2 = func_0015a190();
                                thresh = *(D_0064E72E + kind * 2 + (tmp2 != 0));
                            } else {
                                thresh = 0x3C;
                            }
                        }
                        rnd = func_003b7060() & 0xFFF;
                        rf = (f32)rnd;
                        if ((100.0f * (rf / 4096.0f)) < (f32)thresh) {
                            hit = 0;
                        } else {
                            hit = 1;
                        }
                    }
                    *(s32 *)(arg0 + 0x28) = hit;
                    if (hit == 0) {
                        *(s32 *)(arg0 + 0x20) = *(s32 *)(arg0 + 0x20) + 1;
                    }
                }
            }
        }
        break;
    case 6:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            func_002bad10(0xC);
            func_002baf40(0xD);
            *st = 5;
        }
        break;
    case 7:
        if (((*(u16 *)(arg0 + 0x1C) += 1) & 0xFFFF) >= 10) {
            *(u16 *)(arg0 + 0x1E) = 1;
            *st = 8;
            func_00388ee0(*(s32 *)(ctx + 0x1F294));
            goto lab_2310;
        }
        return 0;
    case 8:
lab_2310:
        tmp = func_00375a00(ctx + *(s32 *)(ctx + 0x1F308) * 0xE8 + 0x1D6A0);
        if (tmp != 0) {
            st88 = D_0064EC88;
            st90 = D_0064EC90;
            func_003761f0(ctx, *(s32 *)(ctx + 0x1F308), 0, *(u16 *)(arg0 + 0x1E), &st88, 0, 180.0f);
            if (*(u16 *)(arg0 + 0x1E) < 10) {
                *(u16 *)(arg0 + 0x1E) = (u16)(*(u16 *)(arg0 + 0x1E) + 1);
            }
            tmp = *(s32 *)(arg0 + 0x20);
            *(s32 *)(arg0 + 0x20) = tmp - 1;
            if (tmp - 1 < 1) {
                *st = 9;
            }
        }
        break;
    case 9:
        tmp = func_00375a00(ctx + *(s32 *)(ctx + 0x1F308) * 0xE8 + 0x1D6A0);
        if (tmp != 0) {
            if (*(u16 *)(ctx + 0x1F2F4) & 0x10) {
                *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) & 0xFFEF);
                *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 0x100);
                *(u16 *)(ctx + 0x1F2F2) = 0;
            }
            if (*(s32 *)(arg0 + 0x28) == 0) {
                func_0045af60(1, 3, 2, 2);
            } else {
                func_0045af60(1, 3, 2, 1);
            }
            kind = *(u8 *)(arg0 + 0x12);
            if (kind == 1) {
                kind = *(u8 *)(arg0 + 0x24);
            }
            if (*(s32 *)(arg0 + 0x28) == 0) {
                func_00442830((char *)bufD0, iGpffffa9E4);
            } else {
                func_00442830((char *)bufD0, iGpffffa9E0);
            }
            func_002bbd20(0, func_002438b0(kind));
            func_002bbd20(1, bufD0);
            func_002bad10(0xE);
            *st = 0xD;
        }
        break;
    case 10:
        if (((*(u16 *)(arg0 + 0x1C) += 1) & 0xFFFF) > 9) {
            *(u16 *)(arg0 + 0x1E) = 5;
            *st = 0xB;
            func_00388ee0(*(s32 *)(ctx + 0x1F294));
            func_00388f00(*(s32 *)(ctx + 0x1F294));
            func_003892e0(*(s32 *)(ctx + 0x1F294));
        }
        break;
    case 11:
        if (((*(u16 *)(arg0 + 0x1C) += 1) & 0xFFFF) >= 0x3C) {
            tmp = func_00378220((u8 *)*(s32 *)(ctx + 0x1F2A4));
            if (tmp != 0) {
                *st = 0xC;
                func_00389350(*(s32 *)(ctx + 0x1F294));
                goto lab_2600;
            }
        }
        return 0;
    case 12:
lab_2600:
        tmp = func_00389330(*(s32 *)(ctx + 0x1F294));
        if (tmp != 0) {
            if (*(s32 *)(arg0 + 0x28) == 0) {
                *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 0x80);
            }
            *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) | 0x40);
            if (*(void **)(ctx + 0x1F2A0) != 0) {
                func_00452080(*(s32 *)(ctx + 0x1F2A0));
                *(s32 *)(ctx + 0x1F2A0) = 0;
            }
            if (*(s32 *)(arg0 + 0x28) == 0) {
                func_0045af60(1, 3, 2, 2);
            } else {
                func_0045af60(1, 3, 2, 1);
            }
            if (*(s32 *)(arg0 + 0x28) == 0) {
                tmp = 2;
            } else {
                tmp = 1;
            }
            func_002bbd20(0, func_002438b0(*(u8 *)(arg0 + 0x24)));
            func_002bad10(tmp + 0x15);
            *st = 0xD;
        }
        break;
    case 13:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            tmp = func_00106330(0x1403);
            if (tmp == 0) {
                tmp2 = 0;
            } else {
                tmp = func_00106330(0x140E);
                if (tmp == 0) {
                    tmp2 = 0;
                } else if (*(s32 *)(arg0 + 0x28) != 0) {
                    tmp2 = 0;
                } else {
                    *(s32 *)(arg0 + 0x28) = 1;
                    func_00442830((char *)buf90, iGpffffa9E0);
                    func_002bbd20(0, func_002438b0(6));
                    func_002bbd20(1, buf90);
                    func_002bad10(0xF);
                    tmp2 = 1;
                }
            }
            *(s32 *)(arg0 + 0x2C) = tmp2;
            if (tmp2 == 0) {
                tmp = func_00380980(arg0);
                if (tmp == 0) {
                    return 1;
                }
                *st = 0xE;
            } else {
                *st = 0x10;
            }
        }
        break;
    case 14:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            tmp = *(s32 *)(arg0 + 0x30);
            if (tmp == 0) {
                return 1;
            }
            if ((tmp & 0xFFFF) == 0) {
                func_00442830((char *)buf50, iGpffffa9E4);
            } else {
                func_00442830((char *)buf50, iGpffffa9E0);
            }
            func_002bbd20(0, func_002438b0((tmp >> 16) & 0xFF));
            func_002bbd20(1, buf50);
            func_002bad10(0x10);
            *st = 0xF;
        }
        break;
    case 15:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            return 1;
        }
        break;
    case 16:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            if (*(s32 *)(arg0 + 0x2C) == 1) {
                func_002bad10(0x11);
                *st = 0x11;
            } else {
                func_00380980(arg0);
                *st = 8;
            }
        }
        break;
    case 17:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            return 1;
        }
        break;
    case 18:
        tmp = func_00375a00(ctx + *(s32 *)(ctx + 0x1F308) * 0xE8 + 0x1D6A0);
        if (tmp != 0) {
            *(u16 *)(ctx + 0x1F2F4) = (u16)(*(u16 *)(ctx + 0x1F2F4) & 0xFFF7);
            if (*(void **)(ctx + 0x1F2A0) != 0) {
                func_00452080(*(s32 *)(ctx + 0x1F2A0));
                *(s32 *)(ctx + 0x1F2A0) = 0;
            }
            id = *(u16 *)(arg0 + 0x10);
            cnt = func_0010b6f0();
            cur = (u16)func_0010b5b0();
            tmp = (s32)(u16)(u32)func_0010ac10((s32)id);
            if (tmp == 0) {
                if (cnt == cur) {
                    func_0043f9c8(arg0 + 0x18, 0, 0x7C);
                    func_002bbd20(0, func_00109220(id));
                    func_002bad10(3);
                    tmp = 7;
                } else {
                    func_0010b010(id);
                    func_002bbd20(0, func_00109220(id));
                    func_002bad10(1);
                    tmp = 5;
                }
            } else {
                func_002bad10(2);
                tmp = 6;
            }
            *(s32 *)(arg0 + 8) = tmp;
        }
        break;
    case 19:
        tmp = func_00379920(ctx);
        if (tmp != 0) {
            func_00106390(0x1434, 1);
            func_002baac0((u8 *)(*(s32 *)(ctx + 0x1F2DC)));
            *st = 4;
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381a70);
#endif

// FUN_00382BA0
s32 func_00382ba0(u8 *arg0) {
    f32 sp48[2];
    struct {
        u8 pad[8];
        u8 out[16];
    } spbuf;
    s32 temp_3;
    u16 temp_2;
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = arg0 + 0x18;
    temp_17 = *(u8 **)arg0;
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        *(f32 *)(temp_17 + 0x1F310) = 10.0f;
        func_00374910(temp_17);
        sp48[0] = 316.0f;
        sp48[1] = 211.0f;
        func_0036dc60(temp_17 + *(s32 *)(temp_17 + 0x1F308) * 0xFB0, &sp48[0], (f32 *)&spbuf.out[0], 160.0f);
        func_00375d50(temp_17, *(s32 *)(temp_17 + 0x1F308), 0.0f, 0.0f, (f32 *)&spbuf.out[0], (f32 *)&spbuf.out[0]);
        func_0038d9f0(*(s32 *)(temp_17 + 0x1F29C));
        func_0038d970(*(s32 *)(temp_17 + 0x1F29C));
        func_00388d60(*(s32 *)(temp_17 + 0x1F294));
        func_0038daf0(*(s32 *)(temp_17 + 0x1F29C), 7);
        *(s32 *)(temp_17 + 0x1F30C) = 1;
        *(s32 *)temp_16 = 1;
    case 1:
        if (((*(u16 *)(temp_16 + 4) += 1) & 0xFFFF) >= 0xA && func_00388de0(*(s32 *)(temp_17 + 0x1F294)) != 0) {
            func_002bad10(0x12);
            *(s32 *)temp_16 = 2;
        case 2:
            func_002bb7c0(1);
            if (func_002bb600() == 0) {
                func_002bb1e0(1);
                *(s32 *)temp_16 = 3;
                func_00379090(temp_17, *(s32 *)(temp_17 + 0x1F308), 0xA, 1);
                func_00388e00(*(s32 *)(temp_17 + 0x1F294));
                func_0038dcc0(*(s32 *)(temp_17 + 0x1F29C), 7);
                func_0038d310(*(s32 *)(temp_17 + 0x1F298));
            }
        }
        goto block_17;
    case 3:
        if (func_00375a00(temp_17 + *(s32 *)(temp_17 + 0x1F308) * 0xE8 + 0x1D6A0) != 0) {
            *(u16 *)(temp_17 + 0x1F2F4) = (u16)(*(u16 *)(temp_17 + 0x1F2F4) & 0xFFFB);
            *(s32 *)temp_16 = 4;
        case 4:
            if (func_00388e20(*(s32 *)(temp_17 + 0x1F294)) != 0) {
                *(s32 *)(temp_16 + 8) = 2;
                return 1;
            }
            goto block_17;
        }
        goto block_17;
    default:
        func_0046d730(&D_0064EC70, 0x64E);
        goto block_17;
    }
block_17:
    return 0;
}


/* measured: cold recovery from m2c+romwright+Ghidra/IDA (dispatch beq-chain */
/* 3,2,0,-1 via ascending switch, 4 identical chance chains with plain */
/* (u8)(100.0f*(f/4096.0f)) and (f32)(u32 & 0xFFF), D_0064E700 loop with */
/* hoisted basep, block_68 unit loop, cases -1/2/3, iGpffffa9B8 GPREL via */
/* *(&iGpffffa9B8+arg3) and D_0064E6E0/D_0064E700 absolute). Follows 80ea0 */
/* idiom: frame 0x60, slot hoist, u16 flags at work+4/6/0x10 (no s32 win */
/* trap), single shared return via block_68 goto (case -1 direct). Wins: u32 */
/* rnd (497->541, -45 short to -1 inside 3%), loop chance mask drop */
/* (445->434, 52->46 edits), opt_common_subs off (434->396). Neutral, do not */
/* repeat: GPREL/table swap (430 nd but 60 edits, GPREL hoist), schedule / */
/* loopinv singles and pairs tie, for vs while tie. Walls: sltu/andi */
/* definition-site sunk (retail sltu $v0 + andi $sN vs mwcc sltu $sN) and */
/* D_0064E6E0 sll/lui/addu/andi order (2 sites); prior or-fold/cvt-scratch */
/* floors fixed by u32/plain casts. fnalign 72 edits +12 reloc-only, retail */
/* 542 vs object 541 (-1, -0.2% inside 3% gate). Rule-3: no quadword reads. */
// FUN_00382EA0 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_common_subs off
s32 func_00382ea0(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3)
{
    u8 *unit;
    s32 flag0;
    s32 thresh0;
    u32 rnd0;
    f32 f0;
    s32 chance0;
    s32 hit0;
    s32 flag1;
    s32 chance1;
    s32 sum1;
    s32 i1;
    u8 *base1;
    s32 flag2;
    s32 thresh2;
    u32 rnd2;
    f32 f2;
    s32 chance2;
    s32 hit2;
    s32 flag3;
    s32 chance3;
    s32 sum3;
    s32 i3;
    u8 *base3;
    s32 count;
    s32 i;
    u8 *u;

    unit = func_0036e910(arg0);
    *(u8 **)work = unit;
    *(s32 *)(work + 0xC) = arg1;
    *(u16 *)(work + 0x10) = arg2;
    func_002baac0((u8 *)(*(s32 *)(unit + 0x1F2DC)));
    switch (*(s32 *)(work + 0xC)) {
    case -1:
        func_002bad10(8);
        *(s32 *)(work + 8) = 8;
        return 0;
    case 0:
        if ((func_00106330(0x1430) == 0) || (func_00106330(0x11) == 0)) {
            hit0 = 0;
        } else {
            flag0 = (func_0015a190() != 0) & 0xFF;
            if (*(u8 *)(work + 0x12) == 0) {
                thresh0 = (D_0064E6E0[flag0 & 0xFF] + *(&iGpffffa9B8 + arg3)) & 0xFF;
            } else {
                thresh0 = (D_0064E6E0[(func_00107890(*(u8 *)(work + 0x12)) & 0xFF) * 2 + (flag0 & 0xFF)] + *(&iGpffffa9B8 + arg3)) & 0xFF;
            }
            rnd0 = func_003b7060() & 0xFFF;
            f0 = (f32)rnd0;
            chance0 = (u8)(100.0f * (f0 / 4096.0f));
            if ((chance0 & 0xFF) < (thresh0 & 0xFF)) {
                hit0 = 1;
            } else {
                hit0 = 0;
            }
        }
        if (hit0 != 0) {
            flag1 = (func_0015a190() != 0) & 0xFF;
            rnd0 = func_003b7060() & 0xFFF;
            f0 = (f32)rnd0;
            chance1 = (u8)(100.0f * (f0 / 4096.0f));
            sum1 = 0;
            base1 = &D_0064E700[flag1 & 0xFF];
            for (i1 = 0; i1 < 0x15; i1++) {
                sum1 = (sum1 + base1[i1 * 2]) & 0xFF;
                if (chance1 < sum1) {
                    break;
                }
            }
            *(u8 *)(work + 0x12) = (u8)(i1 + 1);
            *(u16 *)(work + 4) = (u16)(*(u16 *)(work + 4) | 1);
            *(s32 *)(unit + 0x1F2A0) = func_00377eb0(*(u8 **)(unit + 0x1F2A8), ((*(u8 *)(work + 0x12) - 1) & 0xFF));
        }
        *(u16 *)(work + 6) = 0;
        func_002bbd20(0, func_00109220(arg2));
        func_002bad10(0);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 0;
        goto block_68;
    case 2:
        if ((func_00106330(0x1430) == 0) || (func_00106330(0x11) == 0)) {
            hit2 = 0;
        } else {
            flag2 = (func_0015a190() != 0) & 0xFF;
            if (*(u8 *)(work + 0x12) == 0) {
                thresh2 = (D_0064E6E0[flag2 & 0xFF] + *(&iGpffffa9B8 + arg3)) & 0xFF;
            } else {
                thresh2 = (D_0064E6E0[(func_00107890(*(u8 *)(work + 0x12)) & 0xFF) * 2 + (flag2 & 0xFF)] + *(&iGpffffa9B8 + arg3)) & 0xFF;
            }
            rnd2 = func_003b7060() & 0xFFF;
            f2 = (f32)rnd2;
            chance2 = (u8)(100.0f * (f2 / 4096.0f));
            if ((chance2 & 0xFF) < (thresh2 & 0xFF)) {
                hit2 = 1;
            } else {
                hit2 = 0;
            }
        }
        if (hit2 != 0) {
            flag3 = (func_0015a190() != 0) & 0xFF;
            rnd2 = func_003b7060() & 0xFFF;
            f2 = (f32)rnd2;
            chance3 = (u8)(100.0f * (f2 / 4096.0f));
            sum3 = 0;
            base3 = &D_0064E700[flag3 & 0xFF];
            for (i3 = 0; i3 < 0x15; i3++) {
                sum3 = (sum3 + base3[i3 * 2]) & 0xFF;
                if (chance3 < sum3) {
                    break;
                }
            }
            *(u8 *)(work + 0x12) = (u8)(i3 + 1);
            *(u16 *)(work + 4) = (u16)(*(u16 *)(work + 4) | 1);
            *(s32 *)(unit + 0x1F2A0) = func_00377eb0(*(u8 **)(unit + 0x1F2A8), ((*(u8 *)(work + 0x12) - 1) & 0xFF));
        } else if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) = (u16)(*(u16 *)(work + 4) | 2);
        }
        func_002bad10(7);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 2;
        goto block_68;
    case 3:
        if (func_00380bd0(work) != 0) {
            *(u16 *)(work + 4) = (u16)(*(u16 *)(work + 4) | 2);
        }
        *(u16 *)(work + 6) = 0;
        func_002bad10(9);
        func_0038d2a0(*(s32 *)(unit + 0x1F298));
        *(s32 *)(work + 8) = 3;
        goto block_68;
    default:
        func_0046d730(D_0064EC70, 0x6C7);
        goto block_68;
    }
block_68:
    if ((*(u16 *)(work + 4) & 2) == 0) {
        u = *(u8 **)work;
        count = func_00378530(*(s32 *)(u + 0x1F304), *(s32 *)(u + 0x1F2FC));
        for (i = 0; i < count; i++) {
            if (i != *(s32 *)(u + 0x1F308)) {
                if (*(u16 *)(u + i * 0xE8 + 0x1D6A0) & 2) {
                    func_0046d730(D_0064EC70, 0x8C);
                }
                func_0036e000(u + i * 0xFB0);
            }
        }
    }
    return 0;
}
#pragma opt_common_subs on
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ea0);
#endif

// FUN_00383720
s32 func_00383720(u8 *arg0) {
    s32 func_00381a70();
    s32 func_003816e0();
    s32 func_00381830();
    s32 func_00382ba0();
    s32 func_00380ea0();
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    u16 temp_2_2;
    u32 temp_2;

    temp_2 = (u32)*(s32 *)(arg0 + 8);
    switch (temp_2) {
    case 0:
        temp_2_2 = *(u16 *)(arg0 + 6);
        if ((s32)temp_2_2 < 0xA) {
            if (((*(u16 *)(arg0 + 6) += 1) & 0xFFFF) == 0xA) {
                func_0045af60(1, 1, 5, 0xA);
            }
        }
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            *(s32 *)(arg0 + 8) = func_00380d80(arg0, *(u16 *)(arg0 + 0x10));
        }
        goto block_39;
    case 1:
        if (func_00381a70() != 0) return 1;
        goto block_39;
    case 2:
        if (func_003816e0() != 0) return 1;
        goto block_39;
    case 3:
        if (func_00381830() != 0) return 1;
        goto block_39;
    case 4:
        if (func_00382ba0() != 0) return *(s32 *)(arg0 + 0x20);
        goto block_39;
    case 5:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            var_2 = 1;
        } else {
            var_2 = 0;
        }
        if (var_2 != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                func_0043f9c8(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                func_002bad10(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 6:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            var_2_2 = 1;
        } else {
            var_2_2 = 0;
        }
        if (var_2_2 != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                func_0043f9c8(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                func_002bad10(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 7:
        if (func_00380ea0() != 0) {
            if (*(u16 *)(arg0 + 4) & 1) {
                func_0043f9c8(arg0 + 0x18, 0, 0x1C);
                *(s32 *)(arg0 + 8) = 1;
                func_002bad10(0xB);
                goto block_39;
            }
            return 1;
        }
        goto block_39;
    case 8:
        func_002bb7c0(1);
        if (func_002bb600() == 0) {
            func_002bb1e0(1);
            var_2_3 = 1;
        } else {
            var_2_3 = 0;
        }
        if (var_2_3 != 0) return 1;
        goto block_39;
    default:
        func_0046d730(&D_0064EC70, 0x72B);
        goto block_39;
    }
block_39:
    return 0;
}

// FUN_00383A40
s32 func_00383a40(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(u16 *)(temp_16 + 4) & 4) {
        return -1;
    }
    if (*(s32 *)(temp_16 + 0x14) == 0) {
        *(s32 *)(temp_16 + 0x14) = func_00383720(temp_16);
    }
    return 0;
}

// FUN_00383AA0
void func_00383aa0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002bb4e0(arg0);
    jtbl_008873EC[0](work);
}

// FUN_00383AE0
s32 func_00383ae0(u8 *arg0, s32 arg1, u16 arg2, s32 arg3) {
    u8 *work;
    s32 ret;

    func_0044ea90(&D_0064EC70, 0x757);
    work = D_008873F4[0](1, 0x94, 0x40000);
    if (work == NULL) {
        func_0046d730(&D_0064EC70, 0x758);
    }
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0064EB60), 0x12, 0, 0, func_00383a40, func_00383aa0, (u8 *)(work));
    if (ret == 0) {
        func_0046d730(&D_0064EC70, 0x762);
    }
    func_00382ea0(work, arg0, arg1, arg2, arg3);
    return ret;
}
