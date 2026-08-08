#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

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
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_0064EB60[];
extern u8 D_0064EC70[];
extern s32 func_00451fc0(u8 *window, const void *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), u8 *buf);
extern s32 func_00382ea0(u8 *work, u8 *arg0, s32 arg1, u16 arg2, s32 arg3);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
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
extern void func_0010cad0(void *dst, u16 id);
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
extern void func_0038d0a0(s32 a);
extern void func_00388d20(s32 a);
extern void func_00388d40(s32 a);
extern void func_0010ad80(s32 a);
extern void func_0010b060(u16 a);
extern u16 D_008C024E;
extern s32 func_00106330(s32 a);
extern s32 func_00107890(s32 a);
extern s32 func_0015a190(void);
extern void func_002baac0(s32 a);
extern void *func_0036e910(void *a);
extern s32 func_00377eb0();
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
extern s32 func_00378220(s32 a);
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
extern u8 *func_0010b010(u16 a);
extern char *func_002438b0(s32 a);
extern void func_00442830(char *dst, s32 value);
extern void func_00452080(s32 a);
extern void func_00106390(s32 a, s32 b);



/* measured: retail hoists the case-0 loop's slot-address computation
   (sll/addu/addiu -> $s6, a 7th saved register, frame -0xB0) ABOVE the
   func_0010ace0 jal and stores through $s6 after it; mwcc b210 always sinks
   the address to the store after the call (sll/addu/sw in $v1, 6 saved regs,
   frame -0xA0) no matter the spelling — named slotp local before the call,
   inline store, while/for shapes. Same load-sinking floor family as
   func_00381830; every other byte matched in the 0x840 function (jump-table
   dispatch, arg order, var_20/var_21/temp_18 register assignment, dsll32 /
   dsra32 at the func_0010ace0 call reproduced by the s32->s16 param
   conversion, s64->s32 counter compare with plain slt, spA4/spA8 buffer
   reads at 0xA4/0xA8). nd 387-421. */
// FUN_00380EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00380ea0);

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
// FUN_00381A70
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381a70);

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


/* measured: structure fully recovered (dispatch beq-chain, the 4 identical
   chance chains with the explicit 2.1474836e9f guard, D_0064E700 loop with
   hoisted basep, block_68 unit loop, cases -1/2/3, iGpffffa9B8 GPREL and
   D_0064E6E0/D_0064E700 absolute lookups) but every chain carries the three
   RECORDED b210 floors: (1) or-fold — retail `or $v1,$v1,$v0` (dest = srl
   reg), mwcc `or $v0,$v1,$v0` (dest = andi reg) in the (x>>1)|(x&1) mask;
   (2) cvt-scratch — retail `cvt.s.w $f1,$f0; add.s $f1,$f1,$f1` (value stays
   in $f1), mwcc `cvt.s.w $f0,$f0; add.s $f1,$f0,$f0`; (3) guard polarity —
   retail keeps the cvt body INLINE with bc1t to the overflow body, mwcc b210
   always inlines the overflow (sub.s) body with bc1f (same as effBlurFilter
   func_0034e7e0). Plus the definition-site andi of the `(f()!=0) & 0xFF`
   temps is sunk to the first use (sltu $s4; use-site andi — retail masks at
   definition AND use; u8 typing doesn't help). Tried u16/s32 temps, guard
   both polarities, basep-local loop; nd 440 (dominated by the branch-immediate
   cascade from the 20-byte size deficit: 4 chains x ~5 words of floors).
   Rule-3 typed-alias check: no quadword reads in this function. */
// FUN_00382EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ea0);

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
    ret = func_00451fc0(arg0, D_0064EB60, 0x12, 0, 0, func_00383a40,
                        func_00383aa0, work);
    if (ret == 0) {
        func_0046d730(&D_0064EC70, 0x762);
    }
    func_00382ea0(work, arg0, arg1, arg2, arg3);
    return ret;
}