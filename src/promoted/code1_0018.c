#include "Kosaka/k_clump_internal.h"
#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline s32 code1_0018_shift4(s32 value)
{
    return value << 4;
}
static inline s32 code1_0018_add2(s32 first, s32 second)
{
    return first + second;
}
extern void func_0048a000();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_001852f0(void);
extern void func_003a2760(s32 arg0);
extern void func_003e9390(s32 arg0);
extern void func_003c21e0();
extern void func_004787e0(s32 arg0);
extern void func_003f3eb0(s32 arg0, s32 arg1);
extern void func_00185370();
extern void func_00183b80(u8 *arg0);

extern void (*jtbl_008873EC[])(void *);

extern s32 D_0076428C;
extern s32 iGpffffb27c;
extern u64 iGpffffb8c8;
extern s32 iGpffffb278;
extern s32 func_0029d2e0(void);
extern s32 iGpffffb268;
extern s32 iGpffffb250;
extern s16 iGpffffb390;
extern s16 iGpffffb394;
extern s16 iGpffffb398;
extern s16 iGpffffb39c;
extern s16 iGpffffb3a0;
extern s32 iGpffffb3a4;
extern s32 func_00470250(u8 *window, s32 size, s32 align);
extern void func_00470810(s32 buf, const void *file, s32 flags);
extern s32 *func_00470bd0(s32 buf, s32 id);
extern void func_004703c0(s32 buf, s32 flags);
extern void func_004703d0(s32 buf, s32 flags);
extern void func_00470430(s32 buf, s32 size);
extern void func_00452080(s32 handle);
extern u8 D_005F5830[];
extern u8 D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern f32 iGpffff9fd8;
extern u8 iGpffff9fdc;
extern s32 iGpffffb240;
extern s32 func_00470e20(s32 handle);
extern void func_001582f0(s32 mode, s32 value, s32 arg2);
extern void func_00450340(s64 arg0, s32 arg1, ...);
extern void func_0017d1f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                           f32 arg5, f32 arg6, f32 arg7, s32 arg4);
extern void func_0014def0(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, s32 arg4,
                          f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                          f32 farg4, f32 farg5, f32 farg6, f32 farg7,
                          f32 farg8);
extern void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern u16 D_008C024E[];
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00452490(s32 arg0);

void func_0018e780(s32 arg0);



extern void func_003e0f40(s32 arg0);
extern s32 func_00457a90(u8 *arg0, u8 *arg1);
extern void func_003c42b0(u8 *arg0, s32 arg1);
extern u8 D_005F5438[];
extern u8 *func_00155280(void);
extern void func_0014e8f0(s32 a, s32 b, s32 c);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 a, u8 *b);
extern void func_003f6800(s32 a, f32 fp);
extern u8 D_005F5360[];
extern u8 iGpffffb310;
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern s32 func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern u8 *func_00457120(void);
extern f32 fGpffff8218;
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern s64 func_00479c30(s32 arg0, s32 arg1);
extern u8 *func_0047a2f0(u32 arg0);
extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
extern u8 *func_00457630(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern void func_0018a200(u8 *arg0);
extern s32 func_0015a560(void);
extern f32 func_0044b7b0(f32 arg0);
extern void func_00366380(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                          s16 arg8, void *arg9, f32 farg0, f32 farg1,
                          f32 farg2, f32 farg3);

extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern s32 func_00275680(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern u8 D_005F54D8[];
extern s32 func_00189940(u8 *arg0);
extern void func_0018a010(s32 arg0);
extern u8 D_005F54E8[];
extern s32 func_0018dde0(u8 *arg0);
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern void func_00182bc0(u8 *arg0);
extern s32 func_00451fc0(u8 *window, const void *data, s32 prio, s32 arg3,
                         s32 arg4, void (*init)(u8 *), void (*close)(u8 *),
                         u8 *work);
extern void func_00185850(u8 *arg0);
extern void func_00186610(u8 *arg0);
extern s32 func_0018e810(u8 *arg0);
extern void func_0018ef20(u8 *arg0);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 func_003bfae0();
extern u8 *func_00457120(void);
extern s32 func_003e8200(u8 *arg0, s32 arg1);
extern void func_003f68a0(s32 arg0, s32 arg1);
extern u8 D_007E8C00[];
extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern s64 func_00110960(s32 arg0, u32 arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_0014bdb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0015a160(void);
extern void func_004598e0(s32 arg0);
extern void func_0045a3e0(s16 arg0, s32 arg1);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
extern s32 iGpffffb884;

/* measured: loop-invariant hoisting keeps the retail stride/base preheader for
   the 0x750 slot scan. */
#pragma opt_loop_invariants on
// FUN_00182310
void func_00182310(s32 arg0)
{
    s32 i;
    s32 one;
    s32 stride;
    s32 hit;
    u8 *p;
    u8 *temp;

    i = 0;
    one = 1;
    stride = 0x750;
    while (i < 0xF) {
        hit = 0;
        p = D_007E8C00 + i * stride;
        if (*(s32 *)(p + 0x48) != 0 && *(s32 *)(p + 0x54) != 0) {
            hit = one;
        }
        hit = hit != 0;
        if (hit != 0) {
            temp = *(u8 **)(p + 0x1B0);
            if (temp != NULL) {
                *(s32 *)(*(u8 **)(temp + 0x38) + 4) = arg0;
            }
        }
        i += 1;
    }
}
/* measured: close loop-invariant hoisting around the slot scan. */
#pragma opt_loop_invariants off
// FUN_00182390
void func_00182390(void)
{
    func_0043f9c8(&iGpffffb310, 0, 4);
}
// FUN_001823C0
u8 *func_001823c0(void)
{
    return &iGpffffb310;
}
/* Floor: 342 differing words (reloc-masked) via measure_guarded.py, 210 fnalign
   edits (+13 reloc-only), 481 emitted against retail's 476 (1.1% over, within
   3%). Probes: v1 396, v2 408, v3 343, v4 342, v5 444 (probe_variants).
   Levers that moved it: u8-array D_005F1D00/D_005F1D08 derefs via u64/f32
   temporaries plus LocalFrame with padAC (retail ld+lwc1 with separate luis,
   sd at 0xA0/swc1 at 0xA8, 4-byte gap to spB0 at 0xB0), s64 stat for the
   func_00479c30 mask, u16-masked slot id with (s16) func_0045af60 args, and
   mode==8-first if/else dispatch. Stopped after two unproductive rounds
   (v4 -1 word/+1 instr, v5 +102). WALL: loop-preheader addiu $a2,$sp,0xA0
   scheduling (retail before the D_005F1D00 loads, b210 after the stores),
   lwc1-before-ld order, s64/s32 sign-extension residuals at the stat compares
   (dsll32/dsra32), and saved-register recolouring across the five slot arms. */
// FUN_001823D0 NONMATCHING
#ifdef NON_MATCHING
void func_001823d0(u8 *arg0, s32 arg1, s32 arg2)
{
    extern u8 *func_001452b0(s32 arg0);
    extern s32 func_00168ec0(void *arg0, void *arg1, void *arg2);
    extern s32 func_0016fe80(s32 arg0);
    extern s32 func_0016ffd0(s32 arg0);
    extern s32 func_0014c4c0(u8 *arg0, u8 *arg1, f32 arg2);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern f32 func_0047a080(s32 arg0, s32 arg1);
    extern u32 D_005F08B0[];
    extern u8 D_005F1D00[];
    extern u8 D_005F1D08[];
    extern s32 D_007F1760[];
    typedef struct {
        u64 spA0;
        f32 spA8;
        s32 padAC;
        u8 *spB0;
        u8 *spB4;
        u8 *spB8;
    } LocalFrame;
    LocalFrame frame;
    u64 xy;
    f32 z;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    s32 *slot;
    s64 stat;
    s32 mode;
    s32 index;
    s32 offset;
    s32 entry;
    s32 var_21;
    s32 status;
    u8 *pos;
    u8 *node;
    u8 *mat;

    status = *(u16 *)(arg0 + 0xD4);
    stat = func_00479c30((s32)arg0, 0) & 0xFFFF;
    temp_f20 = func_0047a080((s32)arg0, 0);
    if (*(s32 *)iGpffff9db0 < 0xC8) {
        pos = func_0047a2f0((u32)arg0) + 0x30;
        node = func_001452b0(0x15);
        index = *(s32 *)iGpffff9db0;
        offset = *(s32 *)(iGpffff9db0 + 4);
        entry = *(s32 *)((u8 *)D_005F08B0 + index * 4);
        if (entry == 0) {
            var_21 = 0;
        } else {
            var_21 = *(u8 *)(entry + offset);
        }
        for (; node != NULL; node = *(u8 **)(node + 0x138)) {
            xy = *(u64 *)D_005F1D00;
            z = *(f32 *)D_005F1D08;
            frame.spA0 = xy;
            frame.spA8 = z;
            frame.spB0 = node + 0x15C;
            frame.spB4 = node + 0x168;
            frame.spB8 = node + 0x174;
            if ((func_00168ec0(pos, &frame.spB0, &frame.spA0) == 1) &&
                (temp_f3 = *(f32 *)(frame.spB0 + 4), temp_f2 = *(f32 *)(pos + 4),
                 (temp_f2 < (100.0f + temp_f3))) &&
                !(temp_f2 <= (temp_f3 - 100.0f))) {
                var_21 = *(s32 *)(node + 0x18C);
                break;
            }
            frame.spB0 = node + 0x168;
            frame.spB4 = node + 0x174;
            frame.spB8 = node + 0x180;
            if ((func_00168ec0(pos, &frame.spB0, &frame.spA0) == 1) &&
                (temp_f3 = *(f32 *)(frame.spB0 + 4), temp_f2 = *(f32 *)(pos + 4),
                 (temp_f2 < (100.0f + temp_f3))) &&
                !(temp_f2 <= (temp_f3 - 100.0f))) {
                var_21 = *(s32 *)(node + 0x18C);
                break;
            }
        }
        mode = arg1 & 0xFFFF;
        if (mode == 8) {
            if ((status & 0xFFFF) == 1) {
                mat = func_0047a2f0((u32)arg0);
                if ((func_0014c4c0(mat + 0x30, func_0047a2f0(D_007EFA00[0]) + 0x30, 1600.0f) != 0) &&
                    ((stat & 0xFFFF) == func_0016ffd0(mode)) &&
                    ((!(temp_f20 <= 8.0f) && (temp_f20 < 9.0f)) ||
                     (!(temp_f20 <= 18.0f) && (temp_f20 < 19.0f)))) {
                    {
                        u16 masked = (u16)arg2;
                        s32 id = masked & 0x3FF;
                        s32 value;

                        slot = &D_007F1760[id];
                        func_0045af60(0, (s16)(id + 4), 2, (s16)(*slot + 0x18));
                        value = *slot + 1;
                        *slot = value;
                        if (value >= 4) {
                            *slot = 0;
                            return;
                        }
                    }
                }
            }
        } else if (mode == 1) {
            if ((status & 0xFFFF) == 9) {
                if ((stat & 0xFFFF) == func_0016fe80(mode)) {
                    if ((!(temp_f20 <= 7.0f) && (temp_f20 < 8.0f)) ||
                        (!(temp_f20 <= 21.0f) && (temp_f20 < 22.0f))) {
                        {
                            u16 masked = (u16)arg2;
                            s32 id = masked & 0x3FF;
                            s32 value;

                            slot = &D_007F1760[id];
                            func_0045af60(0, (s16)(id + 4), 1, (s16)(*slot + var_21 * 4));
                            value = *slot + 1;
                            *slot = value;
                            if (value >= 4) {
                                *slot = 0;
                                return;
                            }
                        }
                    }
                } else if (((stat & 0xFFFF) == func_0016ffd0(mode)) &&
                           ((!(temp_f20 <= 9.0f) && (temp_f20 < 10.0f)) ||
                            (!(temp_f20 <= 19.0f) && (temp_f20 < 20.0f)))) {
                    {
                        u16 masked = (u16)arg2;
                        s32 id = masked & 0x3FF;
                        s32 value;

                        slot = &D_007F1760[id];
                        func_0045af60(0, (s16)(id + 4), 1, (s16)(*slot + var_21 * 4));
                        value = *slot + 1;
                        *slot = value;
                        if (value >= 4) {
                            *slot = 0;
                            return;
                        }
                    }
                }
            } else if ((status & 0xFFFF) == 1) {
                if (((stat & 0xFFFF) == func_0016ffd0(mode)) &&
                    ((!(temp_f20 <= 9.0f) && (temp_f20 < 10.0f)) ||
                     (!(temp_f20 <= 19.0f) && (temp_f20 < 20.0f)))) {
                    {
                        u16 masked = (u16)arg2;
                        s32 id = masked & 0x3FF;
                        s32 value;

                        slot = &D_007F1760[id];
                        func_0045af60(0, (s16)(id + 4), 1, (s16)(*slot + var_21 * 4));
                        value = *slot + 1;
                        *slot = value;
                        if (value >= 4) {
                            *slot = 0;
                            return;
                        }
                    }
                }
            }
        } else {
            if ((status & 0xFFFF) == 1) {
                mat = func_0047a2f0((u32)arg0);
                if ((func_0014c4c0(mat + 0x30, func_0047a2f0(D_007EFA00[0]) + 0x30, 1600.0f) != 0) &&
                    ((stat & 0xFFFF) == func_0016ffd0(mode)) &&
                    ((!(temp_f20 <= 8.0f) && (temp_f20 < 9.0f)) ||
                     (!(temp_f20 <= 18.0f) && (temp_f20 < 19.0f)))) {
                    {
                        u16 masked = (u16)arg2;
                        s32 id = masked & 0x3FF;
                        s32 value;

                        slot = &D_007F1760[id];
                        func_0045af60(0, (s16)(id + 4), 2, (s16)(*slot + var_21 * 4));
                        value = *slot + 1;
                        *slot = value;
                        if (value >= 4) {
                            *slot = 0;
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_001823d0);
#endif
/* measured probe: opt_propagation off tests caching the repeated render callback base. */
#pragma opt_propagation off
// FUN_00182B40
void func_00182b40(void)
{
    void (**fn)(s32, s32);

    fn = D_00887300;
    fn[0](7, 2);
    fn[0](6, 1);
    fn[0](8, 0);
    fn[0](0xC, 1);
}
/* measured probe: restore opt_propagation after func_00182b40. */
#pragma opt_propagation on
/* measured: honest first reconstruction per func_001823d0/838d0 idiom (u8* ctx at +0x38, s32 state/status at +0x0/+0x4, Frame182 v80/v90/vA0 + b0/b8 ptr-stride at sp80-BC, (f32)(u32) clamps, plain arithmetic for adda/madd; m2c+romwright into /var/tmp/cold182bc0 (m2c 402 lines + rom 311 lines + raw 282 lines, arity 1 pointer trusted, no jtbl in retail despite pre-fix switch failure); probe_variants v1 731 base (if/else), v2 717 switch (-14 dispatch layout), v3 717 loop-invariants tie, v4 714 (-3 slotp temp), v5/v6 tie (signed mul, decl order); stop after two non-improving rounds per batch; fnalign v4 retail 779/object 771 (8 short, 1.0% within 3%) 421 edits +23 reloc-only; residual is saved-reg colour, hoisted D_008873F4 base, and COP1 madd/msub vs plain C. */
/* 2026-09-19 (func_00182bc0 only; Cd0018 holds 00183b80/0018a200 untouched): frame -0xc0 exact. Lui retail 26 vs object 29 (+3 surplus): retail {0x4000:5,0x5F:5,0x88:1,4:3,0x2008:1,0x3f80:2,2:2,0x80:2,7:1,8:1,0x4080:1,0x79:1,0x18:1} vs object {0x4000:6,0:10,4:3,0x2008:1,0x3f80:2,2:2,0x80:2,7:1,8:1,0x4080:1}; surplus = 1 float (0x4000 2.0f 5->6, candidate has 6x 2.0f) + 2 symbols (0x5F/0x88/0x79/0x18 8->10 zero, e.g. delete 102:104 lui 0x88 base at 0x182D58). Counts fnalign 771 vs 779 (-8, -1.0% inside gate), words 714, edits 421 +23 reloc, window 3120B. Deletes 9 tot 36: [8:9] 0x182BE0 (swc1 spill); [102:104] 0x182D58 len2 (lui 0x88 table base); [384:385] 0x1831C0 (add.s FPU); [486:504] 0x183358-0x18339F len18 THE field group (lwc1 0,4,8,0x10,0x14,0x18,0x20,0x24,0x28 from s3 + swc1 to 0xA0,0xA4,0xA8,0x90,0x94,0x98,0x80,0x84,0x88 stack: 9-float struct spill, object keeps in regs/different layout); [623:627] 0x18357C len4 (add.s+lwc1 madd ordering); [632:636] 0x1835A0 len4 (same); [652:656] 0x1835F0 len4 (lw 0x5C/addu/lw 0xC/addu pointer chase); [767:768] 0x1837BC (move zero); [775:776] 0x1837DC (lwc1 spill). Inserts 11 tot 24 (object hoists, e.g. 4 at 328:332, 5 at 371:376). No single missing arm; residual per prior note (saved-reg colour, hoisted F4 base, madd vs plain C). No code change this round (before=after); coordinated via hub (Bd0024/Hs0037/Hs0046/Hs0038/Hs001f/Bd002a/Hs0019/Hs0035 confirm no overlap, Main confirms Cd0018 has no edits yet). */
// FUN_00182BC0 NONMATCHING
#ifdef NON_MATCHING
void func_00182bc0(u8 *arg0)
{
    extern u8 *func_00457120(void);
    extern u8 *func_003e9700(s32 arg0);
    extern u32 func_003b7060(void);
    extern u8 *func_003a2340(s32 arg0, s32 arg1, s32 arg2);
    extern u8 *func_003e9320(void);
    extern void func_003c1b90(u8 *arg0, u8 *arg1);
    extern void func_003a2950(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 func_003ef6d0(void);
    extern u8 *func_003ef650(s32 arg0, u8 *arg1);
    extern void func_003c42b0(u8 *arg0, u8 *arg1);
    extern void func_0043f810(void *dst, const void *src, u32 size);
    extern u8 *func_003e0f80(u8 *arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_0044ea90(const void *msg, s32 id);
    extern void func_003e40b0(f32 *dst, f32 *src);
    extern void func_003e0a90(void *arg0, void *arg1, s32 arg2);
    extern void func_003a2770(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern void func_003a2920(u8 *arg0);
    extern u8 *func_00460d80(u8 *arg0, u8 *arg1);
    extern void func_00182b40(void);
    extern void *(*D_008873F4[])(size_t, size_t, u32);
    extern u8 D_005F1D80[];
    extern u8 D_005F1D10[];
    extern u8 D_005F1D70[];
    extern u8 D_00794420[];
    extern f32 fGpffff815c;
    extern f32 fGpffff8198;
    extern f32 fGpffff841c;
    extern s32 iGpffffb610;
    typedef struct {
        f32 v80[4];
        f32 v90[4];
        f32 vA0[4];
        u8 *b0_ptr;
        s32 b0_stride;
        u8 *b8_ptr;
        s32 b8_stride;
    } Frame182;
    Frame182 frame;
    u8 *ctx;
    u8 *mat;
    u8 *mtx;
    u8 *entry;
    u8 *found;
    f32 tmpf;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 b0;
    f32 b1;
    f32 b2;
    f32 c0;
    f32 c1;
    f32 c2;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 halfi;
    u32 rnd;
    s32 dir;

    ctx = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(ctx + 4) != 0) {
        return;
    }
    switch (*(s32 *)ctx) {
    case 0:
    {
        u8 *tmp;
        f32 f0;
        tmp = func_00457120();
        *(u8 **)(ctx + 0x44) = tmp + 0x68;
        *(f32 *)(ctx + 0x54) = 2.0f * (*(f32 *)(tmp + 0x68) * *(f32 *)(ctx + 0x18));
        *(f32 *)(ctx + 0x58) = 2.0f * (*(f32 *)(*(u8 **)(ctx + 0x44) + 4) * *(f32 *)(ctx + 0x18));
        *(f32 *)(ctx + 0x48) = *(f32 *)(*(u8 **)(ctx + 0x44)) * *(f32 *)(ctx + 0x18);
        *(f32 *)(ctx + 0x4C) = *(f32 *)(*(u8 **)(ctx + 0x44) + 4) * *(f32 *)(ctx + 0x18) + *(f32 *)(ctx + 0x58) / 2.0f;
        *(f32 *)(ctx + 0x50) = *(f32 *)(ctx + 0x18);
        f0 = *(f32 *)(ctx + 0x54) / *(f32 *)(ctx + 0x20);
        *(s32 *)(ctx + 0x34) = (s32)f0;
        if (!((*(f32 *)(ctx + 0x54) / *(f32 *)(ctx + 0x20)) <= (f32)*(s32 *)(ctx + 0x34))) {
            *(s32 *)(ctx + 0x34) = *(s32 *)(ctx + 0x34) + 1;
        }
        *(s32 *)(ctx + 0x34) = *(s32 *)(ctx + 0x34) + 1;
        *(s32 *)(ctx + 0x40) = *(s32 *)(ctx + 0x34) * 8;
        func_0044b610(fGpffff815c);
        *(s32 *)(ctx + 0x60) = 0;
        *(f32 *)(ctx + 0x64) = *(f32 *)(ctx + 0x1C) * func_0044b7b0(fGpffff815c);
        *(f32 *)(ctx + 0x70) = *(f32 *)(ctx + 0x20);
        *(f32 *)(ctx + 0x6C) = *(f32 *)(ctx + 0x20);
        *(f32 *)(ctx + 0x68) = *(f32 *)(ctx + 0x20);
        func_0044ea90(D_005F1D80, 0x9D);
        *(u8 **)(ctx + 0x5C) = D_008873F4[0](*(s32 *)(ctx + 0x40), 0x10, 0x40000);
        for (i = 0; i < *(s32 *)(ctx + 0x40); i++) {
            u8 *slotp;
            func_0044ea90(D_005F1D80, 0xA2);
            slotp = *(u8 **)(ctx + 0x5C) + i * 0x10;
            *(u8 **)(slotp + 0x0C) = D_008873F4[0](*(s32 *)(ctx + 0x2C), 8, 0x40000);
        }
        func_0044ea90(D_005F1D80, 0xA6);
        *(u8 **)(ctx + 0x38) = D_008873F4[0](*(s32 *)(ctx + 0x34), 4, 0x40000);
        for (i = 0; i < *(s32 *)(ctx + 0x34); i++) {
            *(s32 *)(*(u8 **)(ctx + 0x38) + i * 4) = (s32)(func_003b7060() % (u32)*(s32 *)(ctx + 0x30));
        }
        {
            u32 uv;
            f32 fv;
            uv = *(u32 *)(ctx + 0x30);
            if ((s32)uv >= 0) {
                fv = (f32)uv;
            } else {
                fv = 2.0f * (f32)((uv >> 1) | (uv & 1));
            }
            *(s32 *)(ctx + 0x3C) = (s32)(fGpffff8198 * fv);
            if (*(s32 *)(ctx + 0x3C) == 0) {
                *(s32 *)(ctx + 0x3C) = 1;
            }
        }
        *(u8 **)(ctx + 8) = func_003a2340(*(s32 *)(ctx + 0x40) * *(s32 *)(ctx + 0x2C), 0x2008000A, 0);
        *(u8 **)(ctx + 0x0C) = func_003e9320();
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x38) = 0x3F800000;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x24) = 0x3F800000;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x10) = 0x3F800000;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x20) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x18) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x14) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x34) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x30) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x28) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x48) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x44) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x40) = 0;
        *(s32 *)(*(u8 **)(ctx + 0x0C) + 0x1C) |= 0x20003;
        func_003c1b90(*(u8 **)(ctx + 8), *(u8 **)(ctx + 0x0C));
        *(s32 *)(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610) + 0x40) |= 0x800000;
        *(s32 *)(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610) + 4) = 0;
        *(s32 *)(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610) + 0xB4) = 1;
        func_003a2950(*(u8 **)(ctx + 8), 1, 0x44);
        func_003a2950(*(u8 **)(ctx + 8), 2, 0x717FB);
        {
            u8 *e;
            e = func_003ef650(func_003ef6d0(), D_005F1D10 + *(s32 *)(ctx + 0x28) * 0x18);
            *(s32 *)(e + 0x50) = (*(s32 *)(e + 0x50) & ~0xFF) | 2;
            func_003c42b0(*(u8 **)(*(u8 **)(*(u8 **)(ctx + 8) + 0x18) + 0x20), e);
            func_0043f810(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610) + 0xE0, D_005F1D70, 0x10);
            *(s32 *)(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610) + 0x40) |= 0x80000;
            *(u8 **)(ctx + 0x10) = func_003e0f80(*(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610));
        }
        *(s32 *)ctx = *(s32 *)ctx + 1;
        break;
    }
    case 1:
    {
        mat = func_00457120();
        mtx = func_003e9700(*(s32 *)(mat + 4));
        for (i = 0; i < *(s32 *)(ctx + 0x34); i++) {
            s32 *slot;
            s32 cur;
            slot = (s32 *)(*(u8 **)(ctx + 0x38) + i * 4);
            cur = *slot;
            if (cur > 0) {
                *slot = cur - 1;
            } else {
                s32 n;
                s32 idx;
                found = NULL;
                n = *(s32 *)(ctx + 0x40);
                idx = 0;
                while (idx < n) {
                    u8 *cand;
                    cand = *(u8 **)(ctx + 0x5C) + idx * 0x10;
                    if (*(s32 *)cand != 0) {
                        idx += 1;
                    } else {
                        found = cand;
                        break;
                    }
                }
                if (found != NULL) {
                    f32 fw;
                    f32 fwi;
                    fw = *(f32 *)(ctx + 0x20);
                    halfi = (s32)(fw / 2.0f);
                    *(s32 *)found = 1;
                    *(s32 *)(found + 4) = (s32)(func_003b7060() % (u32)*(s32 *)(ctx + 0x2C)) + 1;
                    fwi = (f32)i;
                    tmpf = (f32)(func_003b7060() % (u32)halfi);
                    *(f32 *)(found + 8) = fwi * fw + tmpf - fw / 4.0f;
                }
                rnd = func_003b7060() % (u32)(*(s32 *)(ctx + 0x3C) + 1);
                if ((func_003b7060() & 1) != 0) {
                    dir = 1;
                } else {
                    dir = -1;
                }
                *(s32 *)(*(u8 **)(ctx + 0x38) + i * 4) = *(s32 *)(ctx + 0x30) + (s32)(rnd * dir);
            }
        }
        func_003a2770(*(u8 **)(ctx + 8), (u8 *)&frame.b8_ptr, 8, 0x40000000);
        func_003a2770(*(u8 **)(ctx + 8), (u8 *)&frame.b0_ptr, 2, 0x40000000);
        *(s32 *)(ctx + 0x74) = 0;
        for (j = 0; j < *(s32 *)(ctx + 0x40); j++) {
            entry = *(u8 **)(ctx + 0x5C) + j * 0x10;
            if (*(s32 *)entry == 0) {
                continue;
            }
            if (*(s32 *)(entry + 4) <= 0) {
                continue;
            }
            for (k = 0; k < *(s32 *)(entry + 4); k++) {
                u8 *dst;
                dst = *(u8 **)(ctx + 0x10);
                *(s32 *)(dst + 0x28) = 0x3F800000;
                *(s32 *)(dst + 0x14) = 0x3F800000;
                *(s32 *)dst = 0x3F800000;
                *(s32 *)(dst + 0x10) = 0;
                *(s32 *)(dst + 8) = 0;
                *(s32 *)(dst + 4) = 0;
                *(s32 *)(dst + 0x24) = 0;
                *(s32 *)(dst + 0x20) = 0;
                *(s32 *)(dst + 0x18) = 0;
                *(s32 *)(dst + 0x38) = 0;
                *(s32 *)(dst + 0x34) = 0;
                *(s32 *)(dst + 0x30) = 0;
                *(s32 *)(dst + 0x0C) |= 0x20003;
                a0 = *(f32 *)(mtx + 0);
                a1 = *(f32 *)(mtx + 4);
                a2 = *(f32 *)(mtx + 8);
                frame.vA0[0] = a0;
                frame.vA0[1] = a1;
                frame.vA0[2] = a2;
                b0 = *(f32 *)(mtx + 0x10);
                b1 = *(f32 *)(mtx + 0x14);
                b2 = *(f32 *)(mtx + 0x18);
                frame.v90[0] = b0;
                frame.v90[1] = b1;
                frame.v90[2] = b2;
                c0 = *(f32 *)(mtx + 0x20);
                c1 = *(f32 *)(mtx + 0x24);
                c2 = *(f32 *)(mtx + 0x28);
                frame.v80[0] = c0;
                frame.v80[1] = c1;
                frame.v80[2] = c2;
                func_003e40b0(frame.vA0, frame.vA0);
                func_003e40b0(frame.v90, frame.v90);
                func_003e40b0(frame.v80, frame.v80);
                {
                    s32 n;
                    u8 *src;
                    u8 *dd;
                    n = 8;
                    src = mtx;
                    dd = dst;
                    while (n > 0) {
                        *(s32 *)dd = *(s32 *)src;
                        *(s32 *)(dd + 4) = *(s32 *)(src + 4);
                        src += 8;
                        dd += 8;
                        n -= 1;
                    }
                }
                func_003e0a90(dst, ctx + 0x68, 2);
                if (k <= 0) {
                    f32 d0;
                    f32 d1;
                    f32 f0;
                    d0 = *(f32 *)(ctx + 0x48) - *(f32 *)(entry + 8);
                    frame.vA0[0] = frame.vA0[0] * d0;
                    frame.vA0[1] = frame.vA0[1] * d0;
                    frame.vA0[2] = frame.vA0[2] * d0;
                    d1 = *(f32 *)(ctx + 0x4C) - *(f32 *)(*(u8 **)(entry + 0x0C) + k * 8 + 4);
                    frame.v90[0] = frame.v90[0] * d1;
                    frame.v90[1] = frame.v90[1] * d1;
                    frame.v90[2] = frame.v90[2] * d1;
                    f0 = *(f32 *)(ctx + 0x18);
                    frame.v80[0] = frame.v80[0] * f0;
                    frame.v80[1] = frame.v80[1] * f0;
                    frame.v80[2] = frame.v80[2] * f0;
                    *(f32 *)(dst + 0x30) = frame.v80[0] + frame.v90[0] + *(f32 *)(mtx + 0x30) + frame.vA0[0];
                    *(f32 *)(dst + 0x34) = frame.v80[1] + frame.v90[1] + *(f32 *)(mtx + 0x34) + frame.vA0[1];
                    *(f32 *)(dst + 0x38) = frame.v80[2] + frame.v90[2] + *(f32 *)(mtx + 0x38) + frame.vA0[2];
                    {
                        f32 *fp;
                        f32 vv;
                        fp = (f32 *)(*(u8 **)(entry + 0x0C) + k * 8);
                        vv = *fp;
                        *(fp + 1) = *(fp + 1) - (*(f32 *)(ctx + 0x64) * vv - *(f32 *)(ctx + 0x14) * vv * vv);
                        *fp = *fp + fGpffff841c;
                    }
                } else {
                    u8 *src;
                    f32 sc;
                    src = frame.b8_ptr - frame.b8_stride * k;
                    *(f32 *)(dst + 0x30) = *(f32 *)(src + 0x30);
                    *(f32 *)(dst + 0x34) = *(f32 *)(src + 0x34);
                    *(f32 *)(dst + 0x38) = *(f32 *)(src + 0x38);
                    sc = (f32)k * 2.0f;
                    frame.v90[0] = frame.v90[0] * sc;
                    frame.v90[1] = frame.v90[1] * sc;
                    frame.v90[2] = frame.v90[2] * sc;
                    *(f32 *)(dst + 0x30) = *(f32 *)(dst + 0x30) + frame.v90[0];
                    *(f32 *)(dst + 0x34) = *(f32 *)(dst + 0x34) + frame.v90[1];
                    *(f32 *)(dst + 0x38) = *(f32 *)(dst + 0x38) + frame.v90[2];
                }
                {
                    s32 n;
                    u8 *ss;
                    u8 *dd;
                    n = 8;
                    ss = dst;
                    dd = frame.b8_ptr;
                    while (n > 0) {
                        *(s32 *)dd = *(s32 *)ss;
                        *(s32 *)(dd + 4) = *(s32 *)(ss + 4);
                        ss += 8;
                        dd += 8;
                        n -= 1;
                    }
                }
                *(u8 *)(frame.b0_ptr + 0) = 0xFF;
                *(u8 *)(frame.b0_ptr + 1) = 0xFF;
                *(u8 *)(frame.b0_ptr + 2) = 0xFF;
                *(u8 *)(frame.b0_ptr + 3) = (u8)(*(s32 *)(ctx + 0x24) - k * 5);
                if ((k == *(s32 *)(entry + 4) - 1) && (*(f32 *)(dst + 0x34) < -*(f32 *)(ctx + 0x20))) {
                    *(s32 *)entry = 0;
                    for (t = 0; t < *(s32 *)(entry + 4); t++) {
                        *(s32 *)(*(u8 **)(entry + 0x0C) + t * 8 + 4) = 0;
                        *(s32 *)(*(u8 **)(entry + 0x0C) + t * 8) = 0;
                    }
                }
                frame.b8_ptr += frame.b8_stride;
                frame.b0_ptr += frame.b0_stride;
                *(s32 *)(ctx + 0x74) = *(s32 *)(ctx + 0x74) + 1;
            }
        }
        {
            u8 *base;
            base = *(u8 **)(*(u8 **)(ctx + 8) + iGpffffb610);
            *(s32 *)(base + 0x40) |= 0x800000;
            *(s32 *)(base + 4) = *(s32 *)(ctx + 0x74);
        }
        func_003a2920(*(u8 **)(ctx + 8));
        {
            u8 *res;
            res = func_00460d80(D_00794420, *(u8 **)(ctx + 8));
            *(void (**)(void))(res + 8) = func_00182b40;
            *(s32 *)(res + 0x10) = 0;
        }
        break;
    }
    default:
        break;
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00182bc0);
#endif
/* measured: propagation off preserves the cached jtbl_008873EC base for
   the post-loop callback sequence. */
// FUN_001837F0
#pragma opt_propagation off
void func_001837f0(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    void (**base)(void *);

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_17 = 0;
    while (var_17 < *(s32 *)(temp_16 + 0x40)) {
        jtbl_008873EC[0](*(u8 **)(*(u8 **)(temp_16 + 0x5C) + var_17 * 0x10 + 0xC));
        var_17 += 1;
    }
    base = jtbl_008873EC;
    base[0](*(u8 **)(temp_16 + 0x5C));
    base[0](*(u8 **)(temp_16 + 0x38));
    func_003a2760(*(s32 *)(temp_16 + 8));
    func_003e9390(*(s32 *)(temp_16 + 0xC));
    if (*(s32 *)(temp_16 + 0x10) != 0) {
        func_003e0f40(*(s32 *)(temp_16 + 0x10));
    }
    base[0](*(u8 **)(arg0 + 0x38));
}
/* measured: closing the single-function callback-base bracket. */
#pragma opt_propagation on
// FUN_001838D0
void func_001838d0(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    func_0044ea90(&D_005F1D80, 0x17B);
    temp_2 = D_008873F4[0](1, 0x78, 0x40000);
    func_00451fc0(arg0, &iGpffff9f60, 0xF, 0, 0, func_00182bc0,
                  func_001837f0, temp_2);
    *(s32 *)(temp_2 + 0x28) = arg1;
    *(f32 *)(temp_2 + 0x18) = fparg0;
    *(f32 *)(temp_2 + 0x14) = fparg1;
    *(f32 *)(temp_2 + 0x1C) = fparg2;
    *(f32 *)(temp_2 + 0x20) = fparg3;
    *(s32 *)(temp_2 + 0x24) = arg2;
    *(s32 *)(temp_2 + 0x2C) = arg3;
    *(s32 *)(temp_2 + 0x30) = arg4;
}
// FUN_001839E0
void func_001839e0(u8 *arg0, u8 *arg1)
{
    u8 *callback;
    s32 state;

    callback = (u8 *)D_00887300;
    (*(void (**)(s32, s32))callback)(0xE, 0);
    (*(void (**)(s32, s32))callback)(6, 0);
    (*(void (**)(s32, s32))callback)(8, 0);
    (*(void (**)(s32, s32))callback)(0xC, 1);
    (*(void (**)(s32, s32))callback)(7, 2);
    (*(void (**)(s32, s32))callback)(9, 2);
    (*(void (**)(s32, s32))callback)(2, 1);
    func_003f6440(3, 0x71801);
    state = *(s32 *)(arg1 + 0x43C);
    switch (state) {
    case 0:
        func_003f6440(2, 0x44);
        break;
    case 1:
        func_003f6440(2, 0x44);
        break;
    case 2:
        func_003f6440(2, 0x71801);
        break;
    case 3:
        func_003f6440(2, 0x42);
        break;
    case 4:
        func_003f6440(2, 6);
        break;
    default:
        break;
    }
    (*(void (**)(s32, s32))callback)(1,
                                      *(s32 *)(*(u8 **)(arg1 + 0x410)));
}
 
// FUN_00183B80 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
void func_00183b80(u8 *arg0)
{
    extern u8 *func_00457120(void);
    extern u32 func_003b7060(void);
    extern s32 func_003ef6d0(void);
    extern s32 func_003ef650(s32 arg0, u8 *arg1);
    extern u8 *func_00460990(void);
    extern void func_00460ac0(void *arg0, void *arg1);
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    extern void func_001839e0(u8 *arg0, u8 *arg1);
    extern u8 D_005F1D10[];
    extern u8 D_00794930[];
    u8 *ctx;
    u8 *base;
    u8 *q;
    u8 *tmp;
    u8 *pkt;
    f32 f21;
    f32 f20;
    f32 fj;
    f32 fj1;
    f32 fhi;
    f32 flo;
    f32 fdiff;
    f32 fhalf;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 half;
    s32 prod;
    s32 iv0;
    s32 iv1;
    s32 iv2;
    s32 iv3;

    ctx = *(u8 **)(arg0 + 0x38);
    tmp = func_00457120();
    f21 = *(f32 *)(tmp + 0x80);
    f20 = 1.0f / f21;
    if (*(s32 *)(ctx + 4) != 0) {
        return;
    }
    if (*(s32 *)ctx == 0) {
        *(f32 *)(ctx + 0x428) = *(f32 *)(ctx + 0x424) * (f32)*(s16 *)(ctx + 0x43A) / (f32)*(s16 *)(ctx + 0x438);
        *(f32 *)(ctx + 0x450) = -*(f32 *)(ctx + 0x424) / 2.0f;
        *(f32 *)(ctx + 0x454) = -*(f32 *)(ctx + 0x428) / 2.0f;
        *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x424) / 2.0f;
        *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x428) / 2.0f;
        if (*(f32 *)(ctx + 0x414) == 0.0f) {
            *(f32 *)(ctx + 0x414) = *(f32 *)(ctx + 0x418) / 5.0f;
            if ((func_003b7060() & 1) != 0) {
                *(f32 *)(ctx + 0x414) = *(f32 *)(ctx + 0x414) * -1.0f;
            }
        }
        if (*(f32 *)(ctx + 0x418) == 0.0f) {
            *(f32 *)(ctx + 0x418) = *(f32 *)(ctx + 0x414) / 5.0f;
            if ((func_003b7060() & 1) != 0) {
                *(f32 *)(ctx + 0x418) = *(f32 *)(ctx + 0x418) * -1.0f;
            }
        }
        for (j = 0; j < 2; j++) {
            base = ctx + (j << 9);
            fj = (f32)j;
            fj1 = (f32)(j + 1);
            for (i = 0; i < 2; i++) {
                q = base + (i << 8);
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = half * i;
                *(f32 *)(q + 0x10) = (f32)*(s16 *)(ctx + 0x434) + (f32)prod;
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = half * j;
                *(f32 *)(q + 0x14) = (f32)*(s16 *)(ctx + 0x436) + (f32)prod;
                *(f32 *)(q + 0x18) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = half * i;
                *(f32 *)(q + 0x50) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)*(s16 *)(ctx + 0x434) + (f32)prod);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = half * j;
                *(f32 *)(q + 0x54) = (f32)*(s16 *)(ctx + 0x436) + (f32)prod;
                *(f32 *)(q + 0x58) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = half * i;
                *(f32 *)(q + 0x90) = (f32)*(s16 *)(ctx + 0x434) + (f32)prod;
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = half * j;
                *(f32 *)(q + 0x94) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)*(s16 *)(ctx + 0x436) + (f32)prod);
                *(f32 *)(q + 0x98) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = half * i;
                *(f32 *)(q + 0xD0) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)*(s16 *)(ctx + 0x434) + (f32)prod);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = half * j;
                *(f32 *)(q + 0xD4) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)*(s16 *)(ctx + 0x436) + (f32)prod);
                *(f32 *)(q + 0xD8) = f21;
                *(f32 *)(q + 0x28) = f20;
                *(f32 *)(q + 0x68) = f20;
                *(f32 *)(q + 0xA8) = f20;
                *(f32 *)(q + 0xE8) = f20;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj * fhalf);
                *(f32 *)(q + 0x30) = (f32)iv0;
                *(f32 *)(q + 0x34) = (f32)iv1;
                *(f32 *)(q + 0x38) = (f32)iv2;
                *(f32 *)(q + 0x3C) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj * fhalf);
                *(f32 *)(q + 0x70) = (f32)iv0;
                *(f32 *)(q + 0x74) = (f32)iv1;
                *(f32 *)(q + 0x78) = (f32)iv2;
                *(f32 *)(q + 0x7C) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj1 * fhalf);
                *(f32 *)(q + 0xB0) = (f32)iv0;
                *(f32 *)(q + 0xB4) = (f32)iv1;
                *(f32 *)(q + 0xB8) = (f32)iv2;
                *(f32 *)(q + 0xBC) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj1 * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj1 * fhalf);
                *(f32 *)(q + 0xF0) = (f32)iv0;
                *(f32 *)(q + 0xF4) = (f32)iv1;
                *(f32 *)(q + 0xF8) = (f32)iv2;
                *(f32 *)(q + 0xFC) = (f32)iv3;
            }
        }
        *(s32 *)(ctx + 0x410) = func_003ef650(func_003ef6d0(), D_005F1D10 + *(s32 *)(ctx + 0x420) * 0x18);
        *(f32 *)(ctx + 0x42C) = (*(f32 *)(ctx + 0x458) - *(f32 *)(ctx + 0x450)) / 2.0f;
        *(f32 *)(ctx + 0x430) = (*(f32 *)(ctx + 0x45C) - *(f32 *)(ctx + 0x454)) / 2.0f;
        *(s32 *)ctx = *(s32 *)ctx + 1;
        return;
    }
    if (*(s32 *)ctx != 1) {
        return;
    }
    pkt = func_00460990();
    *(void (**)(u8 *, u8 *))(pkt + 8) = func_001839e0;
    *(u8 **)(pkt + 0x10) = ctx;
    func_00460ac0(D_00794930, pkt);
    for (m = 0; m < 2; m++) {
        base = ctx + (m << 9);
        for (k = 0; k < 2; k++) {
            f32 v0;
            f32 v1;
            f32 v2;
            f32 v3;
            q = base + (k << 8);
            v0 = *(f32 *)(ctx + 0x42C) * (f32)k + *(f32 *)(ctx + 0x450);
            v1 = *(f32 *)(ctx + 0x430) * (f32)m + *(f32 *)(ctx + 0x454);
            v2 = *(f32 *)(ctx + 0x42C) * (f32)(k + 1) + *(f32 *)(ctx + 0x450);
            v3 = *(f32 *)(ctx + 0x430) * (f32)(m + 1) + *(f32 *)(ctx + 0x454);
            *(f32 *)(q + 0x20) = v0;
            *(f32 *)(q + 0x24) = v1;
            *(f32 *)(q + 0x60) = v2;
            *(f32 *)(q + 0x64) = v1;
            *(f32 *)(q + 0xA0) = v0;
            *(f32 *)(q + 0xA4) = v3;
            *(f32 *)(q + 0xE0) = v2;
            *(f32 *)(q + 0xE4) = v3;
            func_00461390(D_00794930, 4, q + 0x10, 4);
        }
    }
    *(f32 *)(ctx + 0x450) = *(f32 *)(ctx + 0x450) + *(f32 *)(ctx + 0x414);
    *(f32 *)(ctx + 0x454) = *(f32 *)(ctx + 0x454) + *(f32 *)(ctx + 0x418);
    *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x458) + *(f32 *)(ctx + 0x414);
    *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x45C) + *(f32 *)(ctx + 0x418);
    {
        f32 tmp0;
        f32 tmp1;
        tmp0 = -*(f32 *)(ctx + 0x424) / 2.0f;
        tmp1 = *(f32 *)(ctx + 0x450) - tmp0;
        if (tmp1 < 0.0f) {
            tmp1 = -tmp1;
        }
        if (!(tmp1 < 1.0f)) {
            *(f32 *)(ctx + 0x450) = tmp0;
            *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x424) / 2.0f;
        }
        tmp0 = -*(f32 *)(ctx + 0x428) / 2.0f;
        tmp1 = *(f32 *)(ctx + 0x454) - tmp0;
        if (tmp1 < 0.0f) {
            tmp1 = -tmp1;
        }
        if (!(tmp1 < 1.0f)) {
            *(f32 *)(ctx + 0x454) = tmp0;
            *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x428) / 2.0f;
        }
    }
}

#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00183b80);
#endif
// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



/* measured probe: O1 test for target byte-copy register allocation. */
#pragma optimization_level 1
// FUN_00185150
s32 func_00185150(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                  f32 fparg2, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
                  s32 arg6, u8 *arg7)
{
    s32 temp_2;
    u8 *temp_2_2;
    register u8 *dst;
    register u8 byte0;
    register u8 byte1;
    register u8 byte2;
    register u8 byte3;
    register u8 byte4;
    register u8 byte5;
    register u8 byte6;
    register u8 byte7;

    if (arg7[3] == 0 && arg7[7] == 0) {
        return 0;
    }
    func_0044ea90(&D_005F1D80, 0x43A);
    temp_2_2 = D_008873F4[0](1, 0x460, 0x40000);
    temp_2 = func_00451fc0((u8 *)arg0, &D_005F1D90, 0xF, 0, 0,
                           func_00183b80, func_00185120, temp_2_2);
    *(s32 *)(temp_2_2 + 0x420) = arg1;
    *(f32 *)(temp_2_2 + 0x414) = fparg1;
    *(f32 *)(temp_2_2 + 0x418) = fparg2;
    *(f32 *)(temp_2_2 + 0x424) = fparg0;
    *(f32 *)(temp_2_2 + 0x428) = fparg0;
    *(s16 *)(temp_2_2 + 0x434) = arg2;
    *(s16 *)(temp_2_2 + 0x436) = arg3;
    *(s16 *)(temp_2_2 + 0x438) = arg4;
    *(s16 *)(temp_2_2 + 0x43A) = arg5;
    *(s32 *)(temp_2_2 + 0x43C) = arg6;
    dst = temp_2_2 + 0x440;
    byte0 = arg7[0];
    byte1 = arg7[1];
    byte2 = arg7[2];
    byte3 = arg7[3];
    dst[0] = byte0;
    dst[1] = byte1;
    dst[2] = byte2;
    dst[3] = byte3;
    byte4 = arg7[4];
    byte5 = arg7[5];
    byte6 = arg7[6];
    byte7 = arg7[7];
    dst[4] = byte4;
    dst[5] = byte5;
    dst[6] = byte6;
    dst[7] = byte7;
    return temp_2;
}
/* measured probe: restore optimization level after target O1 test. */
#pragma optimization_level 2
/* measured: VU0 MMI builtins and O1 reproduce the target's pcpyld/sq packet. */
#pragma enable_vu0_registers on
/* measured: bind MMI packet registers as in retail. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 preserves the target's packet construction order. */
#pragma optimization_level 1
// FUN_001852F0
void func_001852f0(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb884;
    *packet = packed;
    c = 0x4C;
    b = iGpffffb8c8 | 0xFF00000000000000ULL;
    packed = _pcpyld(c, b);
    packet[1] = packed;
    iGpffffb884 += 0x20;
}
/* measured: restore the file's O2 baseline after the target. */
#pragma optimization_level 2
/* measured: stop binding MMI packet registers after the target. */
#pragma vu0_mmi_reg_binding off
/* measured: stop VU0 register mode after the target. */
#pragma enable_vu0_registers off

/* measured: enable_vu0_registers + vu0_mmi_reg_binding with optimization_level 1
   reproduces the sibling 112-byte pcpyld/sq skeleton; direct _pcpyld on separate
   u64 pairs gives the retail register order and reload. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: optimization_level 1 is required with the VU0 pragmas above;
   at -O2 the packet stores are reordered and the pcpyld pairs are folded. */
#pragma optimization_level 1
// FUN_00185370
void func_00185370(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c, d;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb884;
    *packet = packed;
    c = 0x4C;
    d = iGpffffb8c8;
    packed = _pcpyld(c, d);
    packet[1] = packed;
    iGpffffb884 += 0x20;
}
/* measured: closes the cluster pcpyld pragma scope and restores the file's -O2
   baseline. */
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001853E0
#pragma opt_propagation off
void func_001853e0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C0);
    base[0](1, *value);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001854F0
#pragma opt_propagation off
void func_001854f0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 1);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C4);
    base[0](1, *value);
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_00185620
#pragma opt_propagation off
void func_00185620(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x54);
    base[0](1, *(s32 *)(arg1 + 0x88C8));
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: retail hoists the D_00887300 base across nine indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00185730
#pragma opt_propagation off
void func_00185730(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    base[0](1, 0);
    func_00489f80();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185830
void func_00185830(void)
{
    func_0048a000();
}

/* measured: honest first reconstruction per 00182310/838d0 idiom (u8* ctx at +0x38, s32 state/status at +0x0/+0x4, f32 stores via ((f32*)pi), plain arithmetic for adda/madd 850/750/450/250 +500/300; m2c 455 lines + rom 357 lines + raw 338 lines into /var/tmp/cold185850, arity 1 pointer trusted; probe_variants v1 1074 base (int stores), v2 954 float stores (-120), v3 861 f-suffix+D-float (-93), loopinv 858 (-3 adopted), nounroll 861 tie, sched 861 tie, v4 861 blez tie (<=0), v5 860 switch (-1); fnalign v3 retail 880/object 916 (36 over) 963 edits +3 reloc-only; residual is saved-reg colour + frame 0x90 vs 0x60; stop after one improving round per 7l. */
#pragma opt_loop_invariants on
// FUN_00185850 NONMATCHING
#ifdef NON_MATCHING
void func_00185850(u8 *arg0)
{
    extern u8 D_00794930[];
    extern u8 D_005F1DA0[];
    extern u8 D_005F1DC0[];
    extern u8 D_005F1DE0[];
    extern f32 iGpffff8214;
    extern s32 iGpffff8424;
    extern f32 fGpffff84d4;
    extern f32 fGpffff84d8;
    extern f32 fGpffff84dc;
    extern s32 uGpffffb314;
    extern u32 func_003b7060(void);
    extern s32 func_003ef6d0(void);
    extern s32 func_003ef650(s32 arg0, u8 *arg1);
    extern u8 *func_00401b80(void);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern u8 *func_00460990(void);
    extern void func_00460ac0(void *arg0, void *arg1);
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    extern void func_001853e0(u8 *arg0, u8 *arg1);
    extern void func_001854f0(u8 *arg0, u8 *arg1);
    extern void func_00185600(void);
    extern void func_00185620(u8 *arg0, u8 *arg1);
    extern void func_00185730(void);
    extern void func_00185830(void);
    u8 *tmp;

/* honest baseline from romwright+m2c */
  s32 *piVar1;
  s32 temp_v0;
  u32 temp_v1;
  u8 *pbVar4;
  s32 *piVar5;
  s32 temp_v2;
  s32 temp_v3;
  s32 temp_v4;
  f32 temp_v5;
  f32 temp_v6;
  
  piVar1 = *(s32 **)(arg0 + 0x38);
  if (piVar1[1] == 0) {
    if (*piVar1 == 1) {
      tmp = func_00461390(D_00794930,4,piVar1 + 0x1590,4);
      *(void (**)(void))(tmp + 8) = func_00185730;
      *(s32 **)(tmp + 0x10) = piVar1;
      tmp = func_00461390(D_00794930,4,piVar1 + 0x1e10,0x42);
      *(void (**)(void))(tmp + 8) = func_00185730;
      *(s32 **)(tmp + 0x10) = piVar1;
      *(void (**)(void))(tmp + 0xc) = func_00185830;
      *(s32 **)(tmp + 0x14) = piVar1;
      tmp = func_00461390(D_00794930,4,piVar1 + 0x1548,4);
      *(void (**)(u8 *, u8 *))(tmp + 8) = func_00185620;
      *(s32 **)(tmp + 0x10) = piVar1;
      pbVar4 = (u8 *)func_00460990();
      *(void (**)(void))(pbVar4 + 8) = func_00185600;
      *(s32 **)(pbVar4 + 0x10) = piVar1;
      func_00460ac0(D_00794930,pbVar4);
      tmp = func_00461390(D_00794930,4,piVar1 + 0x1590,4);
      *(void (**)(void))(tmp + 8) = func_00185730;
      *(s32 **)(tmp + 0x10) = piVar1;
      tmp = func_00461390(D_00794930,4,piVar1 + 0x19f0,0x42);
      *(void (**)(void))(tmp + 8) = func_00185730;
      *(s32 **)(tmp + 0x10) = piVar1;
      *(void (**)(void))(tmp + 0xc) = func_00185830;
      *(s32 **)(tmp + 0x14) = piVar1;
      pbVar4 = (u8 *)func_00460990();
      *(void (**)(u8 *, u8 *))(pbVar4 + 8) = func_001854f0;
      *(s32 **)(pbVar4 + 0x10) = piVar1;
      func_00460ac0(D_00794930,pbVar4);
      for (temp_v0 = 0; temp_v0 < 0xe; temp_v0 = temp_v0 + 1) {
        for (temp_v4 = 0; temp_v4 < 1; temp_v4 = temp_v4 + 1) {
          func_00461390(D_00794930,4,piVar1 + temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11c8,4);
        }
      }
      pbVar4 = (u8 *)func_00460990();
      *(void (**)(void))(pbVar4 + 8) = func_00185600;
      *(s32 **)(pbVar4 + 0x10) = piVar1;
      func_00460ac0(D_00794930,pbVar4);
      tmp = func_00461390(D_00794930,4,piVar1 + 0x15d0,0x42);
      *(void (**)(void))(tmp + 0xc) = func_00185830;
      *(s32 **)(tmp + 0x14) = piVar1;
      uGpffffb314 = uGpffffb314 != 0 ^ 1;
      pbVar4 = (u8 *)func_00460990();
      *(void (**)(u8 *, u8 *))(pbVar4 + 8) = func_001853e0;
      *(s32 **)(pbVar4 + 0x10) = piVar1;
      func_00460ac0(D_00794930,pbVar4);
      for (temp_v0 = 0; temp_v0 < 7; temp_v0 = temp_v0 + 1) {
        for (temp_v4 = 0; temp_v4 < 10; temp_v4 = temp_v4 + 1) {
          piVar5 = piVar1 + temp_v0 * 10 + temp_v4 + 2;
          temp_v2 = piVar1[temp_v0 * 10 + temp_v4 + 2];
          for (temp_v3 = 0; temp_v3 < 4; temp_v3 = temp_v3 + 1) {
            if (3 < temp_v2) {
              temp_v2 = 0;
            }
            ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + temp_v3 * 0x10 + 0x4c] =
                 *(f32 *)(D_005F1DA0 + temp_v2 * 8);
            ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + temp_v3 * 0x10 + 0x4d] =
                 *(f32 *)(D_005F1DA0 + temp_v2 * 8 + 4);
            temp_v2 = temp_v2 + 1;
          }
          if (uGpffffb314 != 0) {
            *piVar5 = *piVar5 + 1;
          }
          if (3 < *piVar5) {
            *piVar5 = 0;
          }
          func_00461390(D_00794930,4,piVar1 + temp_v0 * 0x280 + temp_v4 * 0x40 + 0x48,4);
        }
      }
    }
    else if (*piVar1 == 0) {
      temp_v0 = func_003ef6d0();
      temp_v0 = func_003ef650(temp_v0,D_005F1DC0);
      piVar1[0x2230] = temp_v0;
      temp_v0 = func_003ef6d0();
      temp_v0 = func_003ef650(temp_v0,D_005F1DE0);
      piVar1[0x2231] = temp_v0;
      tmp = func_00401b80();
      *(u8 **)(piVar1 + 0x2232) = tmp;
      for (temp_v0 = 0; temp_v0 < 7; temp_v0 = temp_v0 + 1) {
        for (temp_v4 = 0; temp_v4 < 10; temp_v4 = temp_v4 + 1) {
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x48] = (float)(temp_v4 << 6);
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x49] = (float)(temp_v0 << 6);
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x4a] = 0x447a0000;
          temp_v6 = (float)((temp_v4 + 1) * 0x40);
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x58] = temp_v6;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x59] = (float)(temp_v0 << 6);
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x5a] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x68] = (float)(temp_v4 << 6);
          temp_v5 = (float)((temp_v0 + 1) * 0x40);
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x69] = temp_v5;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x6a] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x78] = temp_v6;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x79] = temp_v5;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x7a] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x4e] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x5e] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x6e] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x7e] = iGpffff8214;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x50] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x51] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x52] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x53] = 0x42800000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x60] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x61] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x62] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 99] = 0x42800000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x70] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x71] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x72] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x73] = 0x42800000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x80] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x81] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x82] = 0x437f0000;
          piVar1[temp_v0 * 0x280 + temp_v4 * 0x40 + 0x83] = 0x42800000;
          temp_v1 = func_003b7060();
          piVar1[temp_v0 * 10 + temp_v4 + 2] = temp_v1 & 3;
        }
      }
      for (temp_v0 = 0; temp_v0 < 0xe; temp_v0 = temp_v0 + 1) {
        temp_v6 = (float)((temp_v0 + 1) * 0x20);
        temp_v4 = 0;
        while (temp_v4 < 1) {
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11c8] = (float)(temp_v4 * 0x280);
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11c9] = (float)(temp_v0 << 5);
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ca] = 0x447a0000;
          temp_v5 = (float)((temp_v4 + 1) * 0x280);
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d8] = temp_v5;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d9] = (float)(temp_v0 << 5);
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11da] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e8] = (float)(temp_v4 * 0x280);
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e9] = temp_v6;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ea] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f8] = temp_v5;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f9] = temp_v6;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11fa] = 0x447a0000;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ce] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11de] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ee] = iGpffff8214;
          ((f32 *)piVar1)[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11fe] = iGpffff8214;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d0] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d1] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d2] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11d3] = 0x42000000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e0] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e1] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e2] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11e3] = 0x42000000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f0] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f1] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f2] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11f3] = 0x42000000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x1200] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x1201] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x1202] = 0x437f0000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x1203] = 0x42000000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11cc] = 0;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11cd] = 0;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11dc] = 0x3f800000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11dd] = 0;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ec] = 0;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11ed] = 0x3f800000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11fc] = 0x3f800000;
          piVar1[temp_v0 * 0x40 + temp_v4 * 0x40 + 0x11fd] = 0x3f800000;
          temp_v4 = temp_v4 + 1;
        }
      }
      temp_v6 = 0.0f;
      for (temp_v0 = 0; temp_v0 < 0x42; temp_v0 = temp_v0 + 2) {
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15d0] = (temp_v5 * 850.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15d1] = (temp_v5 * 750.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x15d2] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15d6] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x15d8] = 0;
        piVar1[temp_v0 * 0x10 + 0x15d9] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x15da] = 0;
        piVar1[temp_v0 * 0x10 + 0x15db] = 0x43000000;
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15e0] = (temp_v5 * 450.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15e1] = (temp_v5 * 250.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x15e2] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x15e6] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x15e8] = 0;
        piVar1[temp_v0 * 0x10 + 0x15e9] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x15ea] = 0;
        piVar1[temp_v0 * 0x10 + 0x15eb] = 0;
        temp_v6 = temp_v6 + fGpffff84d4;
      }
      temp_v6 = 0.0f;
      piVar1[0x1590] = 0;
      piVar1[0x1591] = 0;
      piVar1[0x1592] = 0x447a0000;
      piVar1[0x15a0] = 0x44200000;
      piVar1[0x15a1] = 0;
      piVar1[0x15a2] = 0x447a0000;
      piVar1[0x15b0] = 0;
      piVar1[0x15b1] = 0x43e00000;
      piVar1[0x15b2] = 0x447a0000;
      piVar1[0x15c0] = 0x44200000;
      piVar1[0x15c1] = 0x43e00000;
      piVar1[0x15c2] = 0x447a0000;
      ((f32 *)piVar1)[0x1596] = iGpffff8214;
      ((f32 *)piVar1)[0x15a6] = iGpffff8214;
      ((f32 *)piVar1)[0x15b6] = iGpffff8214;
      ((f32 *)piVar1)[0x15c6] = iGpffff8214;
      piVar1[0x1598] = 0x437f0000;
      piVar1[0x1599] = 0x437f0000;
      piVar1[0x159a] = 0x437f0000;
      piVar1[0x159b] = 0;
      piVar1[0x15a8] = 0x437f0000;
      piVar1[0x15a9] = 0x437f0000;
      piVar1[0x15aa] = 0x437f0000;
      piVar1[0x15ab] = 0;
      piVar1[0x15b8] = 0x437f0000;
      piVar1[0x15b9] = 0x437f0000;
      piVar1[0x15ba] = 0x437f0000;
      piVar1[0x15bb] = 0;
      piVar1[0x15c8] = 0x437f0000;
      piVar1[0x15c9] = 0x437f0000;
      piVar1[0x15ca] = 0x437f0000;
      piVar1[0x15cb] = 0;
      for (temp_v0 = 0; temp_v0 < 0x42; temp_v0 = temp_v0 + 2) {
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x19f0] = (temp_v5 * 850.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x19f1] = (temp_v5 * 750.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x19f2] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x19f6] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x19f8] = 0;
        piVar1[temp_v0 * 0x10 + 0x19f9] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x19fa] = 0;
        piVar1[temp_v0 * 0x10 + 0x19fb] = 0x42800000;
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1a00] = (temp_v5 * 500.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1a01] = (temp_v5 * 300.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x1a02] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1a06] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x1a08] = 0;
        piVar1[temp_v0 * 0x10 + 0x1a09] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x1a0a] = 0;
        piVar1[temp_v0 * 0x10 + 0x1a0b] = 0;
        temp_v6 = temp_v6 + fGpffff84d4;
      }
      temp_v6 = 0.0f;
      for (temp_v0 = 0; temp_v0 < 0x42; temp_v0 = temp_v0 + 2) {
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e10] = (temp_v5 * 850.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e11] = (temp_v5 * 750.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x1e12] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e16] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x1e18] = 0;
        piVar1[temp_v0 * 0x10 + 0x1e19] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x1e1a] = 0;
        piVar1[temp_v0 * 0x10 + 0x1e1b] = 0x43700000;
        temp_v5 = (float)func_0044b610(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e20] = (temp_v5 * 450.0f * 0.5f + 320.0f);
        temp_v5 = (float)func_0044b7b0(temp_v6);
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e21] = (temp_v5 * 250.0f * 0.5f + 224.0f);
        piVar1[temp_v0 * 0x10 + 0x1e22] = 0x447a0000;
        ((f32 *)piVar1)[temp_v0 * 0x10 + 0x1e26] = iGpffff8214;
        piVar1[temp_v0 * 0x10 + 0x1e28] = 0;
        piVar1[temp_v0 * 0x10 + 0x1e29] = 0x437f0000;
        piVar1[temp_v0 * 0x10 + 0x1e2a] = 0;
        piVar1[temp_v0 * 0x10 + 0x1e2b] = 0;
        temp_v6 = temp_v6 + fGpffff84d4;
      }
      piVar1[0x1548] = 0;
      piVar1[0x1549] = 0;
      piVar1[0x154a] = 0x447a0000;
      piVar1[0x1558] = 0x44200000;
      piVar1[0x1559] = 0;
      piVar1[0x155a] = 0x447a0000;
      piVar1[0x1568] = 0;
      piVar1[0x1569] = 0x43e00000;
      piVar1[0x156a] = 0x447a0000;
      piVar1[0x1578] = 0x44200000;
      piVar1[0x1579] = 0x43e00000;
      piVar1[0x157a] = 0x447a0000;
      ((f32 *)piVar1)[0x154e] = iGpffff8214;
      ((f32 *)piVar1)[0x155e] = iGpffff8214;
      ((f32 *)piVar1)[0x156e] = iGpffff8214;
      ((f32 *)piVar1)[0x157e] = iGpffff8214;
      piVar1[0x1550] = 0x437f0000;
      piVar1[0x1551] = 0x437f0000;
      piVar1[0x1552] = 0x437f0000;
      piVar1[0x1553] = 0x42c00000;
      piVar1[0x1560] = 0x437f0000;
      piVar1[0x1561] = 0x437f0000;
      piVar1[0x1562] = 0x437f0000;
      piVar1[0x1563] = 0x42c00000;
      piVar1[0x1570] = 0x437f0000;
      piVar1[0x1571] = 0x437f0000;
      piVar1[0x1572] = 0x437f0000;
      piVar1[0x1573] = 0x42c00000;
      piVar1[0x1580] = 0x437f0000;
      piVar1[0x1581] = 0x437f0000;
      piVar1[0x1582] = 0x437f0000;
      piVar1[0x1583] = 0x42c00000;
      ((f32 *)piVar1)[0x158a] = (0.5f / (float)*(int *)(piVar1[0x2232] + 0xc));
      ((f32 *)piVar1)[0x158b] = (0.5f / (float)*(int *)(piVar1[0x2232] + 0x10));
      ((f32 *)piVar1)[0x158c] = (fGpffff84d8 / (float)*(int *)(piVar1[0x2232] + 0xc));
      ((f32 *)piVar1)[0x158d] = (fGpffff84dc / (float)*(int *)(piVar1[0x2232] + 0x10));
      piVar1[0x1589] = iGpffff8424;
      ((f32 *)piVar1)[0x154c] = ((float)piVar1[0x158a] + (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x154d] = ((float)piVar1[0x158b] + (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x155c] = ((float)piVar1[0x158c] - (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x155d] = ((float)piVar1[0x158b] + (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x156c] = ((float)piVar1[0x158a] + (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x156d] = ((float)piVar1[0x158d] - (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x157c] = ((float)piVar1[0x158c] - (float)piVar1[0x1589]);
      ((f32 *)piVar1)[0x157d] = ((float)piVar1[0x158d] - (float)piVar1[0x1589]);
      *piVar1 = *piVar1 + 1;
    }
  }
  return;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00185850);
#endif
/* measured: close loop-invariant hoisting around the 00185850 reconstruction. */
#pragma opt_loop_invariants off
// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00186640
void func_00186640(u8 *arg0)
{
    func_0044ea90(&D_005F1DF8, 0x299);
    func_00451fc0(arg0, &D_005F1E08, 0xF, 0, 0, func_00185850,
                  func_00186610, D_008873F4[0](1, 0x88D0, 0x40000));
}
// FUN_00189600
void func_00189600(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 v32[4];
    f32 v31[4];
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_18;
    u8 *temp_16_2;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    func_00457120();
    temp_4 = *(s32 *)temp_17;
    if ((temp_4 != 1) || (*(s32 *)(temp_17 + 0x30) != arg2)) {
        if (fparg0 != 0.0f) {
            *(s32 *)(temp_17 + 0x2C) = arg1;
            *(s32 *)(temp_17 + 0x30) = arg2;
            temp_16 = arg2 * 0x18;
            v32[0] = *(f32 *)((u8 *)D_005F2190 + temp_16) -
                     *(f32 *)(temp_17 + 4);
            v32[1] = *(f32 *)((u8 *)D_005F2194 + temp_16) -
                     *(f32 *)(temp_17 + 8);
            v32[2] = *(f32 *)((u8 *)D_005F2198 + temp_16) -
                     *(f32 *)(temp_17 + 0xC);
            temp_f20 = func_003e40b0(&v32[0], &v32[0]);
            v31[0] = *(f32 *)((u8 *)D_005F219C + temp_16) -
                     *(f32 *)(temp_17 + 0x10);
            v31[1] = *(f32 *)((u8 *)D_005F21A0 + temp_16) -
                     *(f32 *)(temp_17 + 0x14);
            v31[2] = *(f32 *)((u8 *)D_005F21A4 + temp_16) -
                     *(f32 *)(temp_17 + 0x18);
            temp_f0 = func_003e40b0(&v31[0], &v31[0]);
            if (!(temp_f20 <= temp_f0)) {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f20 / fparg0) + 1;
            } else {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f0 / fparg0) + 1;
            }
            *(f32 *)(temp_17 + 0x1C) =
                temp_f20 / (f32)*(s32 *)(temp_17 + 0x28);
            *(f32 *)(temp_17 + 0x20) =
                temp_f0 / (f32)*(s32 *)(temp_17 + 0x28);
            *(s32 *)(temp_17 + 0x24) = 0;
            *(s32 *)temp_17 = 2;
            return;
        }
        *(s32 *)(temp_17 + 0x30) = arg2;
        temp_3 = arg2 * 0x18;
        temp_18 = (u8 *)D_005F2190 + temp_3;
        *(struct Vec3 *)(temp_17 + 4) = *(struct Vec3 *)temp_18;
        temp_16_2 = (u8 *)D_005F219C + temp_3;
        *(struct Vec3 *)(temp_17 + 0x10) = *(struct Vec3 *)temp_16_2;
        func_00457630(func_00457120(), temp_18, temp_16_2, 0);
    }
}
/* measured: retail hoists the D_00887300 base across seven indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00189870
#pragma opt_propagation off
void func_00189870(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 1);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    base[0](1, 0);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00189940
/* Measured: 1348 executable bytes, 26 resolved relocations, 12 zero tail bytes.
 * Preserve integer-to-float conversions and reloads across rendering callbacks.
 * Indexed addresses stay integer-valued until their final pointer conversion. */
#pragma opt_loop_invariants on
s32 func_00189940(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f1;
    f32 temp_f0;
    s32 i;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }

    switch (*(s32 *)temp_16) {
    case 0:
        temp_f2 = D_008872F8[0] - (f32)58980;
        temp_f3 = 1.0f / temp_f2;
        *(s32 *)(temp_16 + 8) = 0;
        *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f;
        *(f32 *)(temp_16 + 0x20) = 0.0f;
        temp_f1 = (f32)401;
        *(f32 *)(temp_16 + 0x24) = temp_f1;
        *(f32 *)(temp_16 + 0x28) = temp_f2;
        *(f32 *)(temp_16 + 0x60) = 25.0f;
        *(f32 *)(temp_16 + 0x64) = temp_f1;
        *(f32 *)(temp_16 + 0x68) = temp_f2;
        *(f32 *)(temp_16 + 0xA0) = 0.0f;
        temp_f0 = (f32)427;
        *(f32 *)(temp_16 + 0xA4) = temp_f0;
        *(f32 *)(temp_16 + 0xA8) = temp_f2;
        *(f32 *)(temp_16 + 0xE0) = 25.0f;
        *(f32 *)(temp_16 + 0xE4) = temp_f0;
        *(f32 *)(temp_16 + 0xE8) = temp_f2;
        *(f32 *)(temp_16 + 0x120) = 326.0f;
        *(f32 *)(temp_16 + 0x124) = temp_f1;
        *(f32 *)(temp_16 + 0x128) = temp_f2;
        *(f32 *)(temp_16 + 0x160) = 660.0f;
        *(f32 *)(temp_16 + 0x164) = temp_f1;
        *(f32 *)(temp_16 + 0x168) = temp_f2;
        *(f32 *)(temp_16 + 0x1A0) = 326.0f;
        *(f32 *)(temp_16 + 0x1A4) = temp_f0;
        *(f32 *)(temp_16 + 0x1A8) = temp_f2;
        *(f32 *)(temp_16 + 0x1E0) = 660.0f;
        *(f32 *)(temp_16 + 0x1E4) = temp_f0;
        *(f32 *)(temp_16 + 0x1E8) = temp_f2;
        for (i = 0; i < 4; i++) {
            temp_2 = temp_16 + (i << 6);
            *(f32 *)(temp_2 + 0x38) = temp_f3;
            *(f32 *)(temp_2 + 0x138) = temp_f3;
            *(f32 *)(temp_2 + 0x40) = 255.0f;
            *(f32 *)(temp_2 + 0x44) = 0.0f;
            *(f32 *)(temp_2 + 0x48) = 0.0f;
            *(f32 *)(temp_2 + 0x4C) = 0.0f;
            *(f32 *)(temp_2 + 0x140) = 255.0f;
            *(f32 *)(temp_2 + 0x144) = 0.0f;
            *(f32 *)(temp_2 + 0x148) = 0.0f;
            *(f32 *)(temp_2 + 0x14C) = 0.0f;
        }
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        *(f32 *)(temp_16 + 0x22C) = func_0044b7b0((D_00761184 * (f32)*(s32 *)(temp_16 + 0x220)) / 10.0f);
        if (*(s32 *)(temp_16 + 0x220) < 10) {
            *(s32 *)(temp_16 + 0x220) += 1;
        } else {
            *(s32 *)temp_16 += 1;
        }
        *(f32 *)(temp_16 + 0x224) = (-300.0f + 0.0f) + 316.0f * *(f32 *)(temp_16 + 0x22C);
        *(f32 *)(temp_16 + 0x228) = ((f32)371 + 0.0f) + 30.0f * *(f32 *)(temp_16 + 0x22C);
        /* fallthrough */
    case 2:
        func_00366380((s32)*(f32 *)(temp_16 + 0x224), (s32)*(f32 *)(temp_16 + 0x228),
                      301, 26, 0xFAFF20, 255, 1, 150, 13, D_00794C60,
                      (f32)59000, -5.0f, 1.0f, 1.0f);
        func_00366380(25, 401, 301, 26, 0x191919, 255, 1, 150, 13, D_00794C60,
                      (f32)59000, 0.0f, 1.0f, *(f32 *)(temp_16 + 0x22C));
        if (!(*(f32 *)(temp_16 + 0x22C) < 1.0f)) {
            if (*(s32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x10)) != 0) {
                temp_f0 = func_0044b7b0((D_00761184 * (f32)*(s32 *)(temp_16 + 0xC)) / 10.0f);
                *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f + 336.0f * temp_f0;
                *(f32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x18)) = -161.0f + 336.0f * temp_f0;
                if (*(s32 *)(temp_16 + 0xC) < 10) {
                    *(s32 *)(temp_16 + 0xC) += 1;
                } else {
                    *(s32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x10)) = 0;
                    *(s32 *)(temp_16 + 8) = !(u32)*(s32 *)(temp_16 + 8);
                }
            }
            temp_2 = func_00461390(D_00794C60, 4, temp_16 + 0x20, 4);
            *(void (**)(void))(temp_2 + 8) = func_00189870;
            *(s32 *)(temp_2 + 0x10) = 0;
            func_00461390(D_00794C60, 4, temp_16 + 0x120, 4);
            if (*(const char **)(temp_16 + 0x10) != NULL) {
                func_00275680((f32)(s32)*(f32 *)(temp_16 + 0x18), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x10), 8, 0, D_00794C60, -1);
            }
            if (*(const char **)(temp_16 + 0x14) != NULL) {
                func_00275680((f32)(s32)*(f32 *)(temp_16 + 0x1C), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x14), 8, 0, D_00794C60, -1);
            }
        }
        break;
    case 3:
    default:
        break;
    }
    return 0;
}
#pragma opt_loop_invariants off
// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189EC0
void func_00189ec0(void)
{
    u8 *temp_16;
    u8 *temp_2;
    s32 var_16;
    if (*(s32 *)((u8 *)func_00155280() + 0x30) == 0) {
        temp_16 = *(u8 **)func_00155280();
        func_0044ea90(&D_005F5320, 0x17C);
        temp_2 = D_008873F4[0](1, 0x230, 0x40000);
        if (temp_2 == NULL) {
            var_16 = 0;
        } else {
            var_16 = func_00451fc0(temp_16, &D_005F5330, 0xF, 0, 0,
                                   (void (*)(u8 *))func_00189940,
                                   (void (*)(u8 *))func_00189e90, temp_2);
        }
        *(s32 *)((u8 *)func_00155280() + 0x30) = var_16;
        func_0018a010(-1);
    }
}
// FUN_00189FA0
s32 func_00189fa0(void) {
    if (*(s32 *)((u8 *)(func_00155280()) + 0x30) == 0) {
        return 0;
    }
    func_00452080(*(s32 *)((u8 *)(func_00155280()) + 0x30));
    *(s32 *)((u8 *)(func_00155280()) + 0x30) = 0;
    return 1;
}

// FUN_0018A000
void func_0018a000(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4) = arg1;
}

/* measured: the inner mode/index selection assigns a scratch `p` and `base = p`
   follows the if/else: that copy keeps the join block alive so the two inner
   exits branch to it (retail's b -> b trampoline) instead of folding to the
   work setup. `slot` is a named local recomputed per store so the addu keeps
   index-first operand order and retail's repeated load. */
// FUN_0018A010
void func_0018a010(s32 arg0)
{
    extern u8 D_005F2210[];
    extern u8 D_005F4090[];
    extern u8 D_005F51E0[];
    s32 mode;
    s32 *save;
    s32 *entry;
    s32 index;
    u8 *base;
    u8 *work;
    s32 slot;
    u8 *p;

    if (*(s32 *)(func_00155280() + 0x30) == 0) {
        return;
    }
    if (arg0 == -1) {
        mode = func_0015a160();
        if (mode == 0) {
            index = 0;
            save = (s32 *)iGpffff9db0;
            if (*save >= 0x28) {
                p = NULL;
            } else {
                entry = (s32 *)(D_005F51E0 + *save * 4);
                if (*entry != 0) {
                    index = *(u16 *)((u8 *)*entry + *(save + 1) * 2);
                }
                p = D_005F2210 + index * 0x1A;
            }
        } else {
            p = D_005F4090 + mode * 0x1B;
        }
        base = p;
    } else {
        base = D_005F2210 + arg0 * 0x1A;
    }
    work = *(u8 **)(*(u8 **)(func_00155280() + 0x30) + 0x38);
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(u8 **)(slot + (s32)work + 0x10) = base;
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(s32 *)(slot + (s32)work + 0x18) = (s32)0xC3210000;
    *(s32 *)(work + 0xC) = 0;
}
// FUN_0018A170
s32 func_0018a170(s32 arg0, s32 *arg1)
{
    u8 *temp_16;

    func_003bfae0();
    temp_16 = func_00457120();
    if (func_003e8200(temp_16, func_003bfae0(arg0)) != 0) {
        *arg1 = 1;
        return 0;
    }
    return arg0;
}
// FUN_0018A200
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018a200);
// FUN_0018BAD0
void func_0018bad0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018BB20
s32 func_0018bb20(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&D_005F5340, 0x2E6);
    temp_2 = D_008873F4[0](1, 0x58, 0x40000);
    if (temp_2 == NULL)
        return 0;
    temp_17 = func_00451fc0((u8 *)arg0, &D_005F5350, 0xF, 0, 0,
                            func_0018a200, func_0018bad0, temp_2);
    *(s32 *)(temp_2 + 0xC) = arg1;
    *(f32 *)(temp_2 + 0x48) = *(f32 *)(func_00457120() + 0x80);
    return temp_17;
}
// FUN_0018BBF0
s32 func_0018bbf0(u8 *arg0)
{
    u32 value;

    if (arg0 == NULL) {
        return 1;
    }
    value = *(u32 *)(*(u8 **)(arg0 + 0x38));
    return value >= 4;
}
// FUN_0018BC20
/* measured: optimization_level 1 preserves retail's FPU scheduling for this
   vector normalize; -O2 reorders it into a mismatching form. */
#pragma optimization_level 1
void func_0018bc20(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *temp_4;
    f32 *temp_4_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    u8 *temp_16;
    u8 *temp_2;
    void *target;
    s32 zero;
    s32 one;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = func_0047a2f0(*(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164));
    temp_4 = (f32 *)(temp_16 + 0x30);
    *(struct Vec3 *)temp_4 = *(struct Vec3 *)(temp_2 + 0x20);
    func_003e40b0(temp_4, temp_4);
    temp_f20 = *(f32 *)(func_0047a2f0(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x30);
    *(f32 *)(temp_16 + 0x3C) = *(f32 *)(func_0047a2f0(
        D_007EFA00[0]) + 0x30) - temp_f20;
    temp_f20_2 = *(f32 *)(func_0047a2f0(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x34);
    *(f32 *)(temp_16 + 0x40) = *(f32 *)(func_0047a2f0(
        D_007EFA00[0]) + 0x34) - temp_f20_2;
    temp_f20_3 = *(f32 *)(func_0047a2f0(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x38);
    *(f32 *)(temp_16 + 0x44) = *(f32 *)(func_0047a2f0(
        D_007EFA00[0]) + 0x38) - temp_f20_3;
    temp_4_2 = (f32 *)(temp_16 + 0x3C);
    func_003e40b0(temp_4_2, temp_4_2);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) +
        guard38 * guard44 <
        fGpffff8218) {
        *(s32 *)(temp_16 + 0x2C) =
            (s16)func_00479c30(
                *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164), 0);
        target = *(void **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        one = 1;
        func_00479940(target, zero, one, 4, one);
        *(s32 *)temp_16 = 5;
        return;
    }
    func_00479940(
        *(void **)(*(u8 **)(temp_16 + 0xC) + 0x164), 0, 3, 8, 0);
    *(s32 *)temp_16 = 7;
}
#pragma optimization_level 2
/* measured: optimization_level 1 preserves the retail FPU accumulator order. */
#pragma optimization_level 1
// FUN_0018BDD0
void func_0018bdd0(u8 *arg0)
{
    u8 *temp_16;
    u8 *target;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    f32 value30;
    f32 value34;
    f32 value38;
    s32 zero;
    s32 one;

    temp_16 = *(u8 **)(arg0 + 0x38);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) + guard38 * guard44 <
        fGpffff8218) {
        value30 = *(f32 *)(temp_16 + 0x30);
        value34 = *(f32 *)(temp_16 + 0x34);
        value38 = *(f32 *)(temp_16 + 0x38);
        *(f32 *)(temp_16 + 0x3C) = value30;
        *(f32 *)(temp_16 + 0x40) = value34;
        *(f32 *)(temp_16 + 0x44) = value38;
        target = *(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        one = 1;
        func_00479940(target, zero, one, 4, one);
        *(s32 *)temp_16 = 6;
        return;
    }
    func_00479940(*(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164),
                  0, 0, 8, 1);
    *(s32 *)temp_16 = 4;
}
/* measured: close optimization_level 1 FPU accumulator probe. */
#pragma optimization_level 2
/* measured: opt_propagation off probe preserves retail's handle-load/result
   initialization order for the state predicate. */
#pragma opt_propagation off
// FUN_0018BEA0
s32 func_0018bea0(u8 *arg0)
{
    u8 *p;
    s32 r;
    s32 v;

    p = *(u8 **)(arg0 + 0x38);
    r = 0;
    v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    return r;
}
/* measured: opt_propagation on closes the state-predicate probe. */
#pragma opt_propagation on
// FUN_0018BED0
void func_0018bed0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s32 *)(func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34) == 0) {
        return;
    }
    func_0014e8f0(*(s32 *)(func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34),
                  *(s32 *)(p + 0x54), arg1);
}

// FUN_0018BF50
s32 func_0018bf50(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 r = 0;
    s32 v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    if (*(u16 *)(*(u8 **)(p + 0xC) + 0x220) == 3) {
        if (*(s32 *)(p + 0x24) > 0) {
            r = 1;
        }
    }
    return r;
}

// FUN_0018C610
u8 *func_0018c610(u8 *arg0, s32 *arg1) {
    if (func_00457a90(arg0, D_005F5438) != 0) {
        arg1[0] = 1;
        func_003c42b0(arg0, arg1[1]);
    }
    return arg0;
}

// FUN_0018C680
void *func_0018c680(void *object, void *data)
{
    u8 *arg0 = object;
    s32 arg1 = (s32)data;
    func_003c21e0(*(s32 *)(arg0 + 0x18), func_0018c610, arg1);
    return object;
}
// FUN_0018C6C0
s32 func_0018c6c0(u8 *arg0, s32 arg1)
{
    s32 sp[2];

    sp[0] = 0;
    sp[1] = arg1;
    func_003bff30(arg0, func_0018c680, sp);
    return sp[0];
}
// FUN_0018C700
void func_0018c700(f32 fp0) {
    s32 a;
    s32 b;

    a = func_003ef6d0();
    b = func_003ef650(a, D_005F5360);
    func_003f6800(b, fp0);
}

/* At the -O2 file baseline this function is normalized_diff 2: retail reads
   `mfc1 $a1` and `or $a1,$a1,$v1` where -O2 colours both one register lower.
   The bracket is closed back to the -O2 baseline immediately below the body.
   measured: optimization_level 1 for this function alone, plus materialising
   the 2147483648.0f constant into a named local AFTER the func_003ef650 call
   rather than inline, gives object 136B/window 144B, normalized_diff 0. */
#pragma optimization_level 1
// FUN_0018C750
void func_0018c750(f32 fparg0)
{
    s32 temp_2;
    s32 var_5;
    f32 constant;

    temp_2 = func_003ef650(func_003ef6d0(), D_005F5360);
    constant = 2147483648.0f;
    if (constant <= fparg0) {
        goto positive;
    }
    var_5 = (s32)fparg0;
    goto done;
positive:
    var_5 = (s32)(fparg0 - constant);
    var_5 |= (s32)0x80000000;
done:
    func_003f68a0(temp_2, var_5);
}
/* measured: restore optimization level after func_0018c750. */
#pragma optimization_level 2
/* MATCHED from a 40-word reconstruction.  Two source shapes carried it.
   The dungeon chain's dead final arm is `else if (dungeon < 0xA0) { res = 0; }`,
   not an empty arm: b210 drops the redundant store (res is already 0 on that
   path) but keeps the `slti $at, $s3, 0xa0` exactly as retail does, while a
   genuinely empty arm is removed compare and all, which cost three
   instructions and shifted every later branch displacement (40 words).  The
   first arm's range test is spelled `dungeon <= 5`, not `dungeon < 6`: both
   lower to `slti ..., $s3, 6`, but only the `<=` form puts the result in
   $at, which is what retail's branch-if-true uses; `< 6`, `6 > dungeon`,
   `!(dungeon >= 6)` and `(dungeon < 6) != 0` all pick $v0.  The declaration
   of func_00110960 above is also load-bearing - its first argument is a
   32-bit id and its second an unsigned flag word, not the s64/s32 pair m2c
   printed, and the s64 form costs a dsll32/dsra32 pair at every call site in
   this unit. */
// FUN_0018C7E0
s32 func_0018c7e0(void) {
    s32 dungeon;
    s32 date;
    s32 w1;
    s32 phase;
    s32 res;

    dungeon = func_0015a160();
    res = 0;
    date = (s16)func_001060b0();
    w1 = (s8)func_00110960(date, func_001060c0() & 0xFF);
    phase = func_001060c0() & 0xFF;
    if (iGpffffb264 == 1) {
        return 0;
    }
    if (func_00106330(0x3E0) == 1) {
        func_0045a3e0(0x2C, 1);
        return 1;
    }
    if (dungeon == 0) {
        if ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 3)) {
            res = 0x14;
        } else if ((*(s32 *)iGpffff9db0 == 7) && ((*(s32 *)(iGpffff9db0 + 4) == 2) || (*(s32 *)(iGpffff9db0 + 4) == 3))) {
            s32 t;
            t = func_001060c0() & 0xFF;
            if (*(s32 *)(iGpffff9db0 + 4) == 2) {
                if (func_0014bdb0(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            } else if ((*(s32 *)(iGpffff9db0 + 4) == 3) && (((t & 0xFF) == 3) || ((t & 0xFF) == 4))) {
                if (func_0014bdb0(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            }
        } else if (((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 4))) {
            res = 0;
        } else {
            s32 t2;
            s32 w2;
            dungeon = (s16)func_001060b0();
            t2 = func_001060c0() & 0xFF;
            w2 = (s8)func_00110960(dungeon, t2);
            switch (w2) {
            case 0:
                res = 0x16;
                break;
            case 1:
                break;
            case 3:
                break;
            case 2:
                res = 0x17;
                break;
            case 4:
                break;
            }
            if (func_00106330(0x8A) == 1) {
                res = 0x18;
            }
        }
        if (((s8)w1 == 0) && (((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xE)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xF)) || ((*(s32 *)iGpffff9db0 == 7) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 4)) || ((*(s32 *)iGpffff9db0 == 0xB) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xD) && (*(s32 *)(iGpffff9db0 + 4) == 8)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 3)))) {
            if ((func_0014bdb0(7, 0x1B, 8, 0x1F) == 1) && (((phase & 0xFF) == 3) || ((phase & 0xFF) == 4))) {
                res = 0;
            } else if ((phase & 0xFF) == 4) {
                if (func_0014bdb0(9, 1, 9, 7) == 1) {
                    res = 0;
                } else if (func_0014bdb0(9, 8, 0xA, 5) == 1) {
                    res = 0;
                }
            }
        }
    } else if ((dungeon <= 5) || (dungeon == 0x14) || (dungeon == 0x28) || (dungeon == 0x3C) || (dungeon == 0x50) || (dungeon == 0x64) || (dungeon == 0x78) || (dungeon == 0x8C)) {
        res = 0x1B;
    } else if (dungeon < 0x14) {
        res = 0x1C;
    } else if (dungeon < 0x28) {
        res = 0x1D;
    } else if (dungeon < 0x3C) {
        res = 0x1E;
    } else if (dungeon < 0x50) {
        res = 0x1F;
    } else if (dungeon < 0x64) {
        res = 0x20;
    } else if (dungeon < 0x78) {
        res = 0x21;
    } else if (dungeon < 0x8C) {
        res = 0x22;
    } else if (dungeon < 0x9F) {
        res = 0x23;
    } else if (dungeon < 0xA0) {
        res = 0;
    }
    if (res > 0) {
        func_0045a3e0((s16)res, 1);
        return 1;
    }
    func_004598e0(0x1E);
    return 0;
}
/* MATCHED: the dispatch reads the pair at iGpffff9db0 with only the first
   word cached - retail reloads *(s32 *)(ctx + 4) at every test, so the
   long (major, minor) chains are written out rather than staged in a
   local.  The story flag is `s8`, which re-extends on each read the way
   retail does, and the sub-state is `u8`, whose reads carry the andi. */
// FUN_0018CED0
s32 func_0018ced0(void)
{
    extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_0045b2e0(s32 arg0);
    u8 *ctx;
    s32 major;
    s32 result;
    s32 mode;
    s8 kind;
    u8 sub;

    result = 0;
    mode = func_0015a160();
    kind = (s8)func_00110960((s16)func_001060b0(), func_001060c0() & 0xFF);
    sub = (u8)func_001060c0();
    if (func_00106330(0x3E0) == 1) {
        func_0045aac0(3, 0, 0x1E);
        return 0;
    }
    if (mode == 0) {
        ctx = iGpffff9db0;
        major = *(s32 *)ctx;
        if (major == 7 && *(s32 *)(ctx + 4) == 3) {
            if (kind == 1 || kind == 3) {
                result = 0x3D;
            } else if (sub == 0) {
                if (func_0014bdb0(7, 0x1B, 8, 0x1F) == 1) {
                    if (kind == 0) {
                        result = 2;
                    } else if (kind == 2) {
                        result = 6;
                    }
                } else {
                    result = 6;
                }
            } else if (sub == 5) {
                if (func_0014bdb0(7, 0x17, 8, 0x1F) == 1) {
                    result = 0xB;
                } else if (func_0014bdb0(9, 1, 0xA, 0x12) == 1) {
                    result = 4;
                } else {
                    result = 0xA;
                }
            }
        } else if (((major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 4)) &&
                   (kind == 0 || kind == 2) && sub == 0) {
            if (func_0014bdb0(7, 0x1B, 8, 0x1F) == 1) {
                if (kind == 0) {
                    result = 2;
                } else if (kind == 2) {
                    result = 6;
                }
            } else {
                result = 6;
            }
        } else if ((major == 9 && *(s32 *)(ctx + 4) == 1) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 2) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 3) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 4)) {
            result = 0x3F;
        } else if (kind == 1 || kind == 3) {
            if (major == 1 ||
            (major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                result = 8;
            } else if (major == 7 && *(s32 *)(ctx + 4) == 2) {
                result = 0x3D;
            } else if ((major == 4 && *(s32 *)(ctx + 4) == 1) ||
            (major == 4 && *(s32 *)(ctx + 4) == 2) ||
            (major == 4 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 1) ||
            (major == 6 && *(s32 *)(ctx + 4) == 2) ||
            (major == 6 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 4) ||
            (major == 6 && *(s32 *)(ctx + 4) == 5) ||
            (major == 6 && *(s32 *)(ctx + 4) == 6) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xA) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xB) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xC) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xD) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x10) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x11) ||
            (major == 8 && *(s32 *)(ctx + 4) == 5) ||
            (major == 8 && *(s32 *)(ctx + 4) == 7) ||
            (major == 8 && *(s32 *)(ctx + 4) == 8) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 1)) {
                result = 0x3E;
            }
        } else if (kind == 0) {
            if ((major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                if (func_0014bdb0(7, 0x1B, 8, 0x1F) == 1 && (sub == 3 || sub == 4)) {
                    result = 2;
                } else if (sub == 4) {
                    if (func_0014bdb0(9, 1, 9, 7) == 1) {
                        result = 3;
                    } else if (func_0014bdb0(9, 8, 0xA, 5) == 1) {
                        result = 4;
                    }
                }
            }
        }
    } else if (mode == 0x9F) {
        result = 0x15;
    }
    if (result > 0) {
        func_004598e0(0x1E);
        func_0045b2e0(result);
        return 1;
    }
    func_0045aac0(3, 0, 0x1E);
    return 0;
}
/* MATCH: stage the s32 byte count without a conflicting callee prototype.
   Unsigned elapsed subtraction preserves retail timer wrap. 332B/336B,
   normalized_diff 0; only four zero-tail bytes are absent. */
#pragma push
#pragma opt_propagation off
// FUN_0018DDE0
s32 func_0018dde0(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(work + 4) == 1))
        return 0;
    if (func_0029d2e0() > 0)
        return 0;
    state = *(s32 *)(work + 0);
    switch (state) {
    default:
        break;
    case 0:
        *(s32 *)(work + 0xC) = D_0076428C;
        *(s32 *)(work + 0) = *(s32 *)(work + 0) + 1;
        /* fallthrough */
    case 1:
        if (((u32)D_0076428C - (u32)*(s32 *)(work + 0xC)) > (u32)(*(s32 *)(work + 8))) {
            s32 size;

            size = iGpffffb278;
            *(s32 *)(work + 0x10) = func_0029db50(0xF, iGpffffb27c, size, 0);
            *(s32 *)(work + 0) = 2;
            *(u32 *)(work + 8) = 0x384U;
            *(s32 *)(work + 0xC) = D_0076428C;
        }
        break;
    case 2:
        if (func_00452490(*(s32 *)(work + 0x10)) == 1)
            return 0;
        *(s32 *)(work + 0x10) = 0;
        *(s32 *)(work + 0xC) = D_0076428C;
        *(s32 *)(work + 0) = 1;
        break;
    case 3:
        return -1;
    }
    return 0;
}
#pragma pop
// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0018DF60
s32 func_0018df60(s32 arg0)
{
    s32 temp_2;
    u8 *temp_2_2;

    if (func_0015a560() == 0)
        return 0;
    func_0044ea90(&D_005F54D8, 0x91);
    temp_2_2 = D_008873F4[0](1, 0x14, 0x40000);
    if (temp_2_2 == NULL)
        return 0;
    temp_2 = func_00451fc0((u8 *)arg0, &D_005F54E8, 0xF, 0, 0,
                           (void (*)(u8 *))func_0018dde0, func_0018df30, temp_2_2);
    *(s32 *)(temp_2_2 + 8) = 0x1E;
    return temp_2;
}
// FUN_0018E030
void func_0018e030(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}



// FUN_0018E450
s32 func_0018e450(u8 *arg0)
{
    s32 *p;
    s32 state;

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
        func_0018e780(0);
        *p += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}

// FUN_0018E4D0
void func_0018e4d0(u8 *arg0)
{
    s32 value;
    value = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (value != 0) {
        func_004787e0(value);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* Floor: 95 differing words over 42 fnalign edits, 451 emitted against
   retail's 451 (0.0%).  Levers that moved it: pointer-typed state base
   instead of (s32), block-scoped row/column counters, the func_0017d1f0
   prototype above reordered so the trailing s32 follows the three f32s
   (that reorder alone is worth 34 words and is required by the two
   func_0018f950 call sites as well).  WALL: saved-register colour
   rotation across the case 1 / case 4 bodies -- retail keeps the packet
   pointer in s3 and the row cursor in s2 for the whole function while
   b210 recolours them per case, which no source spelling reaches. */
/* 95 -> 89 (2026-09-19): case 1's three inner sites stage the
   func_00470bd0 deref before the state+4 load - retail evaluates
   `*func_00470bd0(h, N)` into a temp (`v0`) first, so the `lw $a0, 4($s2)`
   lands one slot later than b210's in-line order; sequencing all three
   sites through the temp closes the x3 load-scheduling cluster (41 -> 35
   fnalign edits).  Measured and rejected: hoisting `y << 8` to a y-loop
   temp (364 - retail keeps the per-use shifts, massive perturbation).
   Residual is the case-4 addu operand-order x6 + colour rotation wall. */
// FUN_0018E810 NONMATCHING
#ifdef NON_MATCHING
s32 func_0018e810(u8 *arg0)
{
    extern s64 iGpffff9fd0;
    extern f32 iGpffff9fd8;
    extern u8 iGpffff9fdc;
    extern s32 iGpffffb240;
    extern s32 func_00470e20(s32 handle);
    extern void func_001582f0(s32 mode, s32 value, s32 arg2);
    f32 spCC[1];
    u8 *state;
    s32 v0;
    s32 index;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
        *(s32 *)(state + 0x1B438) = func_00470250(arg0, 0x100, 0x40);
        func_00470810(*(s32 *)(state + 0x1B438), D_005F5730, 4);
        func_00470430(*(s32 *)(state + 0x1B438), 0x14);
        func_004703c0(*(s32 *)(state + 0x1B438), 4);
        func_004703d0(*(s32 *)(state + 0x1B438), 1);
        *(u8 **)(state + 0x1B434) = D_007E3720;
        *(s32 *)state += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x40) {
            switch (func_00470e20(*(s32 *)(state + 0x1B438))) {
            case 0:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 2;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 0);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 1:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 0;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 1);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 2:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 1;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 2);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            }
        }
        break;
    case 2:
        *(s32 *)state += 1;
        break;
    case 3:
        *(s32 *)state += 1;
        break;
    case 4:
        if (D_008C024E[0] & 0x8000) {
            *(s32 *)(state + 0x1B430) -= 1;
        } else if (D_008C024E[0] & 0x2000) {
            *(s32 *)(state + 0x1B430) += 1;
        }
        if (*(s32 *)(state + 0x1B430) < 0) {
            *(s32 *)(state + 0x1B430) = 3;
        }
        if (*(s32 *)(state + 0x1B430) > 3) {
            *(s32 *)(state + 0x1B430) = 0;
        }
        if (D_008C024E[0] & 0x40) {
            func_001582f0(*(s32 *)(state + 4), 0, 0);
        }
        func_00450340(iGpffff9fd0, (s32)&iGpffff9fdc, iGpffffb240);
        {
            s32 y;
            s32 x;
            s32 ty;
            u8 *panels;
            s32 colofs;
            s32 type;
            s32 off;
            f32 fx;
            f32 fy;

            for (y = 0; y < 0x18; y++) {
                for (x = 0, ty = y * 0x12, panels = state + y * 0x1200; x < 0x10; x++) {
                    if (*((u8 *)func_00155280() + (y << 8) + x * 0x10 + 0x54) != 0 &&
                        (*((u8 *)func_00155280() + (y << 8) + x * 0x10 + 0x55) & 0xF) == 1) {
                        off = x * 0x10;
                        type = *((u8 *)func_00155280() + (y << 8) + off + 0x58);
                        fx = (f32)(x * 0x12);
                        fy = (f32)ty;
                        func_0017d1f0(D_007966D0, panels + x * 0x120 + 0x10, type, 0,
                                      fx, fy, 0.0f,
                                      *((u8 *)func_00155280() + (y << 8) + off + 0x59));
                    }
                    if (*((u8 *)func_00155280() + (y << 8) + x * 0x10 + 0x54) == 2) {
                        spCC[0] = iGpffff9fd8;
                        func_0014def0(D_007966D0, panels + x * 0x120 + 0x10, spCC, 0, 0,
                                      (f32)(x * 0x12), (f32)ty, 0.0f, 18.0f, 18.0f,
                                      0.0f, 0.0f, 0.0f, 0.0f);
                    }
                }
            }
        }
        if (D_008C024E[0] & 0x20) {
            *(s32 *)state = 0;
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018e810);
#endif
// FUN_0018EF20
void func_0018ef20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0018EF50
void func_0018ef50(s32 arg0)
{
    func_0044ea90(&D_005F57B0, 0x101);
    func_00451fc0((u8 *)arg0, &D_005F57C0, 0xF, 0, 0,
                  (void (*)(u8 *))func_0018e810,
                  func_0018ef20, D_008873F4[0](1, 0x1B440, 0x40000));
}
#pragma opt_propagation off
// FUN_0018EFE0
s32 func_0018efe0(u8 *arg0)
{
    u8 packet[0x20];
    u8 *temp_16;
    s32 temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)temp_16) {
    case 0:
        *(s32 *)(temp_16 + 4) = func_00470250(arg0, 0xDC, 0xA0);
        func_00470810(*(s32 *)(temp_16 + 4), &D_005F5830, 0xB);
        temp_17 = iGpffffb268 != 0;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 5) = temp_17 ^ 1;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 0) = iGpffffb3a0;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 1) = iGpffffb39c;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 2) = iGpffffb398;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 3) = iGpffffb394;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 4) = iGpffffb390;
        *func_00470bd0(*(s32 *)(temp_16 + 4), 6) = iGpffffb250;
        func_00470430(*(s32 *)(temp_16 + 4), 0x14);
        func_004703c0(*(s32 *)(temp_16 + 4), 4);
        func_004703d0(*(s32 *)(temp_16 + 4), 1);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        iGpffffb268 = *func_00470bd0(*(s32 *)(temp_16 + 4), 5) != 1;
        iGpffffb250 = *func_00470bd0(*(s32 *)(temp_16 + 4), 6);
        if (D_008C024E[0] & 0x40) {
            if (*func_00470bd0(*(s32 *)(temp_16 + 4), 8) == -1) {
                *(u16 *)(packet + 0) =
                    (u16)*func_00470bd0(*(s32 *)(temp_16 + 4), 0);
                *(u16 *)(packet + 2) =
                    (u16)*func_00470bd0(*(s32 *)(temp_16 + 4), 1);
                *(u16 *)(packet + 4) =
                    (u16)*func_00470bd0(*(s32 *)(temp_16 + 4), 2);
                *(s16 *)(packet + 6) =
                    (s16)*func_00470bd0(*(s32 *)(temp_16 + 4), 3);
                *(s16 *)(packet + 8) =
                    (s16)*func_00470bd0(*(s32 *)(temp_16 + 4), 4);
                iGpffffb3a0 = *(u16 *)(packet + 0);
                iGpffffb39c = *(u16 *)(packet + 2);
                iGpffffb398 = *(u16 *)(packet + 4);
                iGpffffb394 = *(s16 *)(packet + 6);
                iGpffffb390 = *(s16 *)(packet + 8);
                func_001029a0(9, packet, 0x1C, 0);
                func_004703d0(*(s32 *)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            } else {
                *(s32 *)(packet + 0xC) =
                    *func_00470bd0(*(s32 *)(temp_16 + 4), 8);
                *(s32 *)(packet + 0x10) =
                    *func_00470bd0(*(s32 *)(temp_16 + 4), 9);
                *(s32 *)(packet + 0x14) =
                    *func_00470bd0(*(s32 *)(temp_16 + 4), 0xA);
                func_001029a0(0xA, packet, 0x1C, 0);
                func_004703d0(*(s32 *)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            }
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        if (func_00102980() == 0) {
            iGpffffb3a4 = 0;
            func_004703d0(*(s32 *)(temp_16 + 4), 1);
            *(s32 *)temp_16 = 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma opt_propagation on
// FUN_0018F390
void func_0018f390(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// measured: probe propagation-off code shape with typed 16-bit operands
#pragma opt_propagation off
// FUN_0018F7B0
void func_0018f7b0(u8 *arg0, s16 *arg1, u16 arg2, u16 arg3, s8 arg4)
{
    s32 i;
    s32 j;
    s32 one;
    u8 *data;
    s32 base;
    s32 row;
    s32 flags;
    s32 source_base;
    s32 cell;
    s32 source;

    data = (u8 *)arg1;
    one = (arg4 == arg4);
    base = (arg2) * 0x10 + (((arg3) << 8) + (s32)arg0);
    *(u8 *)(base + 0x2D) = one;
    i = 0;
    while (i < (s32)data[2]) {
        j = 0;
        row = base + (i << 8);
        flags = (s32)data + i * 3;
        source_base = (s32)data + i * 12;
        while (j < (s32)data[1]) {
            cell = row + (j << 4);
            if (*(u8 *)(cell + 0x2C) == 0) {
                *(u8 *)(cell + 0x2C) = one;
                *(u8 *)(cell + 0x2D) |= *(u8 *)(flags + j + 13);
                source = source_base + (j << 2);
                *(u8 *)(cell + 0x36) = *(u8 *)(source + 0x32);
                *(u8 *)(cell + 0x32) = data[1];
                *(u8 *)(cell + 0x33) = data[2];
                *(s8 *)(cell + 0x30) = *(s8 *)data;
                *(u8 *)(cell + 0x31) = arg4;
                *(u8 *)(cell + 0x37) = *(u8 *)(source + 0x33);
            }
            j += 1;
        }
        i += 1;
    }
}
// measured: restore propagation for following functions
#pragma opt_propagation on
// FUN_0018F8A0
void func_0018f8a0(u8 *arg0, u16 arg1, u16 arg2)
{
    s32 var_9;
    s32 var_8;
    u8 *temp_5;
    u8 *temp_6;
    u8 *temp_7;
    u8 *field;

    temp_7 = (u8 *)code1_0018_add2(
        code1_0018_shift4(arg1 & 0xFFFF),
        ((arg2 & 0xFFFF) << 8) + (s32)arg0);
    if (temp_7[0x2C] != 0 && (temp_7[0x2D] & 0xF) != 0) {
        var_9 = 0;
        while (var_9 < (s32)temp_7[0x33]) {
            var_8 = 0;
            temp_6 = temp_7 + (var_9 << 8);
            while (var_8 < (s32)temp_7[0x32]) {
                temp_5 = temp_6 + var_8 * 0x10;
                field = temp_5 + 0x2C;
                if (*field != 0) {
                    *field = 0;
                    temp_5[0x2D] = 0;
                }
                var_8 += 1;
            }
            var_9 += 1;
        }
    }
}
extern u16 D_008C0252[];
extern u16 D_008C0298[];
extern s16 D_005F5AC0[];
extern u8 D_005F5FD0[];
extern f32 iGpffffa020;
extern f32 iGpffffa024;
extern char iGpffffa028;
extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00470280(u8 *window, s32 id, s32 size, s32 flags);
extern void func_00470970(s32 buf, void *rect);
extern void func_00442088(void *dst, const char *fmt, ...);
extern u8 *func_0015c640(u16 w, u16 h);
extern s32 func_0015c6f0(u8 *arg0);
extern void func_0015c730(u8 *arg0);
extern void func_0015c630(u8 *arg0);
extern void func_0043f810(u8 *dst, s32 x, s32 y);
extern void func_00156800(s16 *arg0, s32 mask);
/* Floor: 328 differing words over 156 fnalign edits (160 at baseline),
   460 emitted against retail's 465 (1.1%, within 3%), measured via
   probe_variants/fnalign --candidate (production stays INCLUDE_ASM, so
   verify/fndiff on the file score the fallback, not this body).  Levers
   that landed: the 0x48-byte rect at sp+0xE0 and the 0x2B-entry s16 row
   at sp+0x80 set the frame to 0x130; func_00442088's format string is
   the gp datum at gp-0x5FD8 ("%d-%d" read out of orig/SLUS_217.82) and
   the two colours copied into sp+0x128 and sp+0x12C are gp-0x5FE0 and
   gp-0x5FDC; the trailing adda.s/madd.s pairs m2c could not name are
   `80.0f + 18.0f * x` and `6.0f + 18.0f * y`; the outer loop hoists
   `temp_20 + (y << 8)`, `6.0f + (f32)(y * 0x12)` and `temp_20 + y * 0x1200`
   in that order, which is what puts the row base in a saved register
   and $f20 in the save list.  Typing func_0014def0, func_0017d1f0 and
   func_0017d240 to take pointers instead of s32 is load-bearing: with
   an (s32) cast MWCC treats &D_007966D0 as an arithmetic common
   subexpression and parks it in a sixth saved register, which costs the
   frame 0x10 bytes and blocks the row-base hoist (433 words); passing
   the array unconverted lets it rematerialize per call as retail does.
   Inclusive $at shapes per func_0018c7e0 (read as worked example for
   both shapes: `dungeon <= 5` keeps slti $at where `< 6` picks $v0, and
   the dead final `else if (dungeon < 0xA0) { res = 0; }` keeps its slti
   where an empty arm drops it): `< 0x17` is spelled `<= 0x16`,
   `< 0xF` as `<= 0xE`, `>= 0xF` as `> 0xE`, `>= 4` as `> 3`.  The two
   `>` flips fix slti $at at 0x1D00/0x1AB8 (160 to 157 edits); the two
   `<=` are neutral but keep $at as retail does.  Width fixes that land:
   `*(s16 *)(temp_20 + 0x1AB8)` for the func_0018f7b0 s8 arg gives retail's
   `lh` where `(s8)(s16)*(s32 *)` gave `lb`, and bare `*(s32 *)` for the
   trailing func_0017d1f0 s32 args gives retail's `lw` where `(u8)` gave
   `lbu` (157 to 156 edits).  Dead-arm check: the switch has six arms
   matching retail's sltiu 6 and every if/else-if chain ends without a
   final else matching retail's beqz-to-next; there is no redundant-store
   arm like 0018c7e0's to keep, and the residual is large (156 edits), not
   short, so no dead arm applies.  Top-down remainder is the colour plus
   scheduling wall below; no MATCH, so production stays guarded.
   WALL: saved-register colour rotation - retail holds the state pointer
   in $s4 and the inner index in $s2, this build swaps them, which is 74
   of the differing words on its own.  Declaration order does not steer
   it: temp_20/y/x/cells/panels, temp_20/x/y/cells/panels,
   temp_20/y/x/panels/cells (all 330 words at baseline) plus count/x/y/
   value/temp_20/cell/cells/panels base (328/160), temp_20-first (330/166),
   temp_20-last, cells/panels swap and y/x swap (all 328) stay 328 words.
   Further top-down: image `lw 0x110/0x118` scheduling, row-copy `sh`
   placement, and the trailing-call `addiu $a2` hoists plus five missing
   instructions (460 vs 465) remain. */
// FUN_0018F950 NONMATCHING
#ifdef NON_MATCHING
s32 func_0018f950(u8 *arg0)
{
    f32 sp12C;
    f32 sp128;
    u8 rect[0x48];
    s16 row[0x2B];
    s16 *src;
    s16 *dst;
    s32 count;
    s32 x;
    s32 y;
    s32 value;
    u8 *temp_20;
    u8 *cell;
    u8 *cells;
    u8 *panels;
    f32 fy;
    u8 *image;

    temp_20 = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)temp_20) {
    case 0:
        func_00457140(0, 0x52, 0x76, 0xFF);
        *(s32 *)(temp_20 + 0x1D00) = 1;
        *(s32 *)temp_20 += 1;
        break;
    case 1:
        *(s32 *)(temp_20 + 0x1CD10) = func_00470250(arg0, 0xDC, 0xC8);
        func_00470810(*(s32 *)(temp_20 + 0x1CD10), &D_005F5FD0, 2);
        func_004703d0(*(s32 *)(temp_20 + 0x1CD10), 1);
        *(s32 *)temp_20 += 1;
        break;
    case 2:
        if (D_008C024E[0] & 0x40) {
            *(s16 *)(temp_20 + 0x28) =
                (s16)*func_00470bd0(*(s32 *)(temp_20 + 0x1CD10), 0);
            *(s16 *)(temp_20 + 0x2A) =
                (s16)*func_00470bd0(*(s32 *)(temp_20 + 0x1CD10), 1);
            func_00452080(*(s32 *)(temp_20 + 0x1CD10));
            *(u8 **)(temp_20 + 0x1CD14) =
                func_0015c640(*(u16 *)(temp_20 + 0x28),
                              *(u16 *)(temp_20 + 0x2A));
            *(s32 *)(temp_20 + 0x1CD10) = func_00470280(arg0, 0x22E, 0x28, 2);
            func_00442088(rect, &iGpffffa028, *(u16 *)(temp_20 + 0x28),
                          *(u16 *)(temp_20 + 0x2A));
            func_004703c0(*(s32 *)(temp_20 + 0x1CD10), 1);
            func_00470970(*(s32 *)(temp_20 + 0x1CD10), rect);
            func_004703d0(*(s32 *)(temp_20 + 0x1CD10), 1);
            *(s32 *)temp_20 += 1;
        }
        break;
    case 3:
        if (func_0015c6f0(*(u8 **)(temp_20 + 0x1CD14)) != 0) {
            image = *(u8 **)(temp_20 + 0x1CD14);
            if (image != NULL) {
                func_0043f810(temp_20 + 0x2C, *(s32 *)(image + 0x110) + 4,
                              *(s32 *)(image + 0x118) - 4);
                func_0015c730(*(u8 **)(temp_20 + 0x1CD14));
                *(u8 **)(temp_20 + 0x1CD14) = NULL;
            }
            *(s32 *)temp_20 += 1;
        }
        break;
    case 4:
        if (D_008C0252[0] & 0x1000) {
            if (*(s32 *)(temp_20 + 0x1AB4) > 0) {
                *(s32 *)(temp_20 + 0x1AB4) -= 1;
            }
        } else if (D_008C0252[0] & 0x4000) {
            if (*(s32 *)(temp_20 + 0x1AB4) <= 0x16) {
                *(s32 *)(temp_20 + 0x1AB4) += 1;
            }
        }
        if (D_008C0252[0] & 0x8000) {
            if (*(s32 *)(temp_20 + 0x1AB0) > 0) {
                *(s32 *)(temp_20 + 0x1AB0) -= 1;
            }
        } else if (D_008C0252[0] & 0x2000) {
            if (*(s32 *)(temp_20 + 0x1AB0) <= 0xE) {
                *(s32 *)(temp_20 + 0x1AB0) += 1;
            }
        }
        if (D_008C0252[0] & 1) {
            value = *(s32 *)(temp_20 + 0x1D00) - 1;
            *(s32 *)(temp_20 + 0x1D00) = value;
            if (value <= 0) {
                *(s32 *)(temp_20 + 0x1D00) = 0xE;
            }
        } else if (D_008C0252[0] & 2) {
            value = *(s32 *)(temp_20 + 0x1D00) + 1;
            *(s32 *)(temp_20 + 0x1D00) = value;
            if (value > 0xE) {
                *(s32 *)(temp_20 + 0x1D00) = 1;
            }
        }
        if (D_008C0252[0] & 8) {
            value = *(s32 *)(temp_20 + 0x1AB8) - 1;
            *(s32 *)(temp_20 + 0x1AB8) = value;
            if (value < 0) {
                *(s32 *)(temp_20 + 0x1AB8) = 3;
            }
        } else if (D_008C0252[0] & 4) {
            value = *(s32 *)(temp_20 + 0x1AB8) + 1;
            *(s32 *)(temp_20 + 0x1AB8) = value;
            if (value > 3) {
                *(s32 *)(temp_20 + 0x1AB8) = 0;
            }
        }
        if (D_008C024E[0] & 0x40) {
            src = (s16 *)((s32)&D_005F5AC0 +
                          *(s32 *)(temp_20 + 0x1D00) * 0x56);
            dst = row;
            count = 0x2B;
            do {
                *dst = *src;
                src++;
                count--;
                dst++;
            } while (count > 0);
            func_00156800(row, 1 << *(s32 *)(temp_20 + 0x1AB8));
            func_0018f7b0(temp_20, row, (u16)*(s32 *)(temp_20 + 0x1AB0),
                          (u16)*(s32 *)(temp_20 + 0x1AB4),
                          *(s16 *)(temp_20 + 0x1AB8));
        } else if (D_008C024E[0] & 0x20) {
            func_0018f8a0(temp_20, (u16)*(s32 *)(temp_20 + 0x1AB0),
                          (u16)*(s32 *)(temp_20 + 0x1AB4));
        } else if (D_008C0298[0] & 0x40) {
            func_0015c630(temp_20 + 0x28);
        }
        sp128 = iGpffffa020;
        func_0014def0(D_007966D0, temp_20 + 0x1870, &sp128,
                      0, 0, 80.0f, 6.0f, 0.0f, 288.0f, 432.0f, 0.0f, 0.0f,
                      0.0f, 0.0f);
        sp12C = iGpffffa024;
        func_0014def0(D_007966D0, temp_20 + 0x1BE0, &sp12C,
                      0, 0, 452.0f, 52.0f, 0.0f, 70.0f, 70.0f, 0.0f, 0.0f,
                      0.0f, 0.0f);
        func_0017d240(D_007966D0, temp_20 + 0x1AC0,
                      *(s32 *)(temp_20 + 0x1D00), 0, 0x36, 0x36,
                      *(s32 *)(temp_20 + 0x1AB8), 460.0f, 60.0f, 0.0f);
        for (y = 0; y < 0x18; y++) {
            cells = temp_20 + (y << 8);
            fy = 6.0f + (f32)(y * 0x12);
            panels = temp_20 + y * 0x1200;
            for (x = 0; x < 0x10; x++) {
                cell = cells + x * 0x10;
                if (cell[0x2C] != 0 && (cell[0x2D] & 0xF) == 1) {
                    func_0017d1f0(D_007966D0,
                                  panels + x * 0x120 + 0x1D10,
                                  cell[0x30], 0,
                                  80.0f + (f32)(x * 0x12), fy, 0.0f, cell[0x31]);
                }
            }
        }
        func_0017d1f0(D_007966D0, temp_20 + 0x1990,
                      *(s32 *)(temp_20 + 0x1D00), 0,
                      80.0f + 18.0f * (f32)*(s32 *)(temp_20 + 0x1AB0),
                      6.0f + 18.0f * (f32)*(s32 *)(temp_20 + 0x1AB4), 0.0f,
                      *(s32 *)(temp_20 + 0x1AB8));
        break;
    case 5:
        return -1;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018f950);
#endif
