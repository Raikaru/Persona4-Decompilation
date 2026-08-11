/* Consolidated Persona 4 source units. */
/* Original translation unit cmmRankUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern u8 *func_00460990();
extern void func_00251d80();
extern u8 D_007963D0[];
extern void func_00460ac0();
extern void func_002516f0();

/* Absolute-addressed data (retail emits lui/addiu for these, so they must be
 * array-typed; scalar spelling would switch them to GPREL16). */
extern u8 D_00635CF8[];
extern u8 D_00635D18[];
extern u8 D_006367C0[];
extern u8 D_00636310[];
extern u8 D_00636390[];
extern u8 D_00636410[];
extern u8 D_00636460[];
extern u8 D_00636480[];
extern u8 D_006364D0[];
extern u8 D_006364F0[];
extern u8 D_00636540[];
extern u8 D_00636210[];
extern u8 D_00636230[];
extern s64 D_00636250[];
extern f32 D_00636258[];
extern u8 D_00636260[];
extern u32 D_80000046[];
extern u32 D_8000001E[];
extern f32 D_00761184;
extern f32 D_007613A0;
extern f32 D_007612CC;
extern f32 D_007612D0;
extern f32 D_0076120C;
extern f32 D_00761288;
extern f32 D_0076122C;
extern void (*D_00887300[])(u32, u32);
extern void *(*D_008873F4[])(s32, s32, s32);

void func_0044ea90(void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
extern u8 *func_00145270(s32 size);
extern void func_0047a6d0(s32 arg0, s32 arg1, void *arg2);
extern void func_00189ec0();
extern void func_00268bd0(s32 arg0, s32 arg1);
extern void func_003ef3a0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit object copies (retail lq/sq). */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636560;
extern u_long128 D_00636570;
typedef struct { u32 w0; u32 w1; } CopyPair;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 f18;
    f32 f1C;
    s16 f20;
    s16 f22;
} Sp120;
extern u_long128 D_00636730;
extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 fparg0);
extern void func_0045e6a0(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                          f32 fparg1, f32 fparg2, f32 fparg3);
extern u8 *func_00252230(Sp120 *arg0, Sp120 *arg1, Sp120 *arg2, f32 fparg0);
 extern void func_003e0870(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_003f6440(s32 arg0, s32 arg1);
extern u8 *func_00251570(s32 arg0, s32 arg1);
extern void func_00251850(s32 arg0);
extern s64 func_0025f360(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0035afa0(s32 arg0);
extern s32 func_003b7060();
extern void func_003e05f0(void *arg0, void *arg1, void *arg2);
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern void func_0045db40(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                           f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, s16 arg7, f32 fparg0, s16 arg_sp0,
                          void *arg_sp8, s32 arg_sp10, void *arg_sp18);

/* Old-style: the two callbacks passed here (func_00251e60 takes one s32,
 * func_00251ec0 takes none) do not share a signature, and a typed prototype
 * would force casts at every call site. */
s32 func_00451fc0();

/* Forward declarations for asm-fallback siblings referenced by C bodies. */
void func_00253850();
void func_00254a70();
void func_0025b240();
void func_0025c100();

typedef int (*code)(...);
extern code DAT_008873ec_abs[];



// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.



// FUN_00251D80
void func_00251d80(s32 arg0, s32 *arg1) {
    extern s32 *func_00452560();
    u8 *base;
    s32 i;
    u8 *entry;

    base = (u8 *)func_00452560(arg1);
    entry = base;
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)entry & 1) {
            if (*(void **)(entry + 8) == NULL) {
                func_0046d730(D_00635CF8, 0x289);
            }
            if ((*(s32 (**)(u8 *, u8 *, u8 *))(entry + 8))(base, entry, *(u8 **)(base + 0x9E0)) != 0) {
                *(u32 *)entry &= ~1;
            }
        }
        entry += 0x78;
    }
    func_002516f0(base, *(u8 **)(base + 0x9E0));
}



// FUN_00251E60
s32 func_00251e60(s32 arg0) {
    u8 *p;

    func_00452560();
    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00251d80;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_007963D0, p);
    return 0;
}

// FUN_00251EC0
void func_00251ec0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00251F00
void func_00251f00(s32 arg0, u32 *arg1) {
    u8 *temp_2;

    func_0044ea90(D_00635CF8, 0x277);
    temp_2 = (u8 *)D_008873F4[0](1, 0x9E4, 0x40000);
    *(u8 **)(temp_2 + 0x9E0) = (u8 *)arg1;
    if (temp_2 == NULL) {
        func_0046d730(D_00635CF8, 0x2D5);
    }
    func_00451fc0(arg0, D_00635D18, 0xF, 0, 0, func_00251e60, func_00251ec0, temp_2);
}



/* Seven spellings were tried without this pragma - ~2 / 0xFFFFFFFD / -3
 * literals, mask locals before and after the call, for and while forms,
 * |= and &= operators, and a ternary - all stuck at nd 24.
 * measured: MWCC rematerializes the flag-clear mask (addiu a0,zero,-3) inside
 * the else-branch instead of the loop preheader, shifting every temp register;
 * with the pragma the object is byte-identical (nd 3 = window padding). */
#pragma opt_loop_invariants on

// FUN_00251FC0
void func_00251fc0(s32 arg0, s32 arg1) {
    extern u32 *func_00452560();
    u32 *p;
    u32 temp;
    s32 i;

    p = func_00452560();
    for (i = 0; i < 0x10; i++) {
        temp = *p;
        if (temp & 1) {
            if (arg1 != 0) {
                *p = temp | 2;
            } else {
                *p = temp & ~2;
            }
        }
        p = (u32 *)((u8 *)p + 0x78);
    }
}
/* measured: scope closer for the hoist above - leaving it on changes the
   next functions in this file, so it is turned off immediately after. */
#pragma opt_loop_invariants off

/* Absolute-addressed float data for func_00252050's stack snapshot. */
extern f32 D_00635D28[];
extern f32 D_00635D2C[];
extern f32 D_00635D30[];
extern u8 D_00635D40[];
extern u8 D_00636180[];
extern u8 *func_00251d30(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void *func_002467b0(s32 arg0);
extern s32 func_00106330(s32 flag);
extern s64 func_00248d80(s16 arg0);
extern void func_00279d40(s32 arg0);
extern u8 *func_00279030(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                         s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 *func_002736d0(u8 **arg0, s32 arg1);
extern s32 func_002738d0(u8 *arg0);
extern void func_00272a10(u8 *arg0, f32 fparg0, f32 fparg1);
extern void func_00272ba0(u8 *arg0, s32 arg1);
extern void func_00273170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00271b70(u8 *arg0);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00268cb0(u8 *arg0);
extern void func_00268c20(s32 arg0, s32 arg1);

/* measured: opt_propagation off around func_00252050 batches the D_00635D28/
   2C/30 lwc1 loads before the spFloat stores; plain float temps under the
   default propagation setting interleave each load/store pair. Loop 1's
   value pair and loop 2's counter are value-class locals (v/w/t) so they
   land in $v1/$v0, and loop 2 uses fresh pointer locals so mwcc
   re-allocates $a1/$a2 instead of keeping loop 1's $a2/$a3. */
/* measured: opt_propagation-off bracket pins the retail access-order batch. */
#pragma opt_propagation off
// FUN_00252050
void func_00252050(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 *func_00452560();
    f32 spFloat[3];
    s32 copy2[0x87 * 2];
    s32 copy1[0x1B];
    u8 *src;
    u8 *p;
    u8 *srcp;
    u8 *dstp;
    u8 *srcp2;
    u8 *dstp2;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    s32 temp_18;
    f32 fa;
    f32 fb;
    f32 fc;

    fa = *(f32 *)D_00635D28;
    fb = *(f32 *)D_00635D2C;
    fc = *(f32 *)D_00635D30;
    spFloat[0] = fa;
    spFloat[1] = fb;
    spFloat[2] = fc;

    srcp = D_00635D40;
    dstp = (u8 *)copy2;
    i = 0x87;
    do {
        v = *(s32 *)(srcp + 0);
        w = *(s32 *)(srcp + 4);
        srcp += 8;
        i--;
        *(s32 *)(dstp + 0) = v;
        *(s32 *)(dstp + 4) = w;
        dstp += 8;
    } while (i > 0);

    srcp2 = D_00636180;
    dstp2 = (u8 *)copy1;
    v = 0x1B;
    do {
        t = *(s32 *)(srcp2 + 0);
        srcp2 += 4;
        v--;
        *(s32 *)(dstp2 + 0) = t;
        dstp2 += 4;
    } while (v > 0);

    p = func_00452560(arg0);
    if (arg1 >= 3) {
        func_0046d730(D_00635CF8, 0x329);
    }
    switch (arg1) {
    case 0:
        src = (u8 *)copy2 + arg2 * 0x6C;
        break;
    case 1:
        src = (u8 *)copy1 + arg2 * 0x6C;
        break;
    case 2:
        src = NULL;
        break;
    }
    temp_18 = *(s32 *)&spFloat[arg1];
    p = func_00251d30(p);
    if (p == NULL) {
        func_0046d730(D_00635CF8, 0x2A5);
    }
    func_0043f9c8(p, 0, 0x78);
    *(u32 *)p |= 1;
    *(s32 *)(p + 8) = temp_18;
    if (src != NULL) {
        func_0043f810(p + 0xC, src, 0x6C);
    }
}
/* measured: closes opt_propagation-off bracket for func_00252050. */
#pragma opt_propagation on



/* measured: recipe A (s32 load local + u32 copy + (f32)(s32) cast on the
   OR result + x+x doubling) applied; best nd 49. Float channels and s16
   channels match byte-for-byte ONLY when written through the named locals
   (fa = a->f4; fb = b->f4; out->f4 = fa + t * (fb - fa)) - bare expression
   form rotates the FP regs (nd 144). s16 sites need (f32) casts on both
   operands (bare b-a does integer subu). Clamp needs cvt-arm-then order
   (if (2147483648.0f <= r) { w = (u8)(s32)r; } else { w = sub-arm; }) to put
   the cvt arm inline. Residual 49 = recorded $v1-coloring floor: (1) 8
   doubling sites: mwcc emits or into the ANDI-dest $v1 + cvt through $f0
   scratch + add.s $f2,$f0,$f0 where retail ors into the SRL-dest $a3/$a1 and
   CVTs straight into fa's $f2 with self-add (24 words); (2) clamp: mwcc
   keeps the byte value in $v1 where retail uses $a3/$a1 (mfc1/andi/or/join
   all follow), and emits bc1f where retail emits bc1t (24 words). Tried
   u8/s32 w, ternary, single-statement if, both arm orders, both compare
   polarities (c.ole.s $f0,$f1 vs c.olt.s $f1,$f0 - constant-left wins). */
// FUN_00252230
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252230);


// FUN_00252710
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252710);

// FUN_00252A60
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252a60);

/* measured: not attempted this wave (4640 B); m2c draft is structurally
   complete; its msub.s/adda.s M2C_ERRORs in the func_0025f3f0 args are
   `a - b*c` / `a + b*c` accumulator idioms (verified on mwcc b210 - msub.s/
   madd.s), and the sp110 table reads feed the loop's func_0025f3f0 calls.
   Same family walls as func_00252a60/002566d0/002570f0: (u32)-cast alpha
   sites, D_00887300 base rematerialization, mwcc stack-slot overlap of
   same-type locals + 0x10 alignment of buffers >= 0x10, FP saved-reg
   rotation, and the D_00636290 copy loop + zero-fill loops need the m2c
   two-temp/do-while spellings. gp-0x7F7C/-0x7F6C floats: 0x00761174/
   0x00761184 (GP base 0x007690F0). */
// FUN_00253850
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00253850);

// FUN_00254A70
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00254a70);

// FUN_00255B00
s32 func_00255b00(s32 arg0, s32 *arg1) {
    s32 v;
    s32 rv;

    rv = 0;
    if (arg1[1] < 0x3C || !(arg1[0] & 2)) {
        arg1[1]++;
    }
    v = arg1[1];
    if (v >= 0x78) {
        rv = 1;
    }
    if (v < 0x3D) {
        func_00253850();
    } else {
        func_00254a70();
    }
    return rv;
}



// FUN_00255B90
u8 *func_00255b90(void) {
    u8 *entry;
    s32 count;
    u8 *cnt;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node4;

    count = 0;
    cnt = func_001452b0(1);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(2);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(3);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(0xA);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    func_0044ea90(D_00635CF8, 0x5FA);
    entry = (u8 *)D_008873F4[0](1, (count + 1) * 0x10, 0x40000);
    count = 0;
    node1 = func_001452b0(1);
    while (node1 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node1 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node1);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node1 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node1;
        count++;
        func_0047a0e0(*(u8 **)(node1 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node1 = *(u8 **)(node1 + 0x138);
    }
    node2 = func_001452b0(2);
    while (node2 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node2 + 0x158);
        *(s32 *)(e + 0xC) = func_00268cb0(node2);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node2 + 0x158) + 0xF4);
        *(u8 **)(e + 8) = node2;
        count++;
        func_0047a0e0(*(u8 **)(node2 + 0x158), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node2 = *(u8 **)(node2 + 0x138);
    }
    node3 = func_001452b0(3);
    while (node3 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node3 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node3);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node3 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node3;
        count++;
        func_0047a0e0(*(u8 **)(node3 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node3 + 0), 1);
        node3 = *(u8 **)(node3 + 0x138);
    }
    node4 = func_001452b0(0xA);
    while (node4 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node4 + 0x144);
        *(s32 *)(e + 0xC) = func_00268cb0(node4);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node4 + 0x144) + 0xF4);
        *(u8 **)(e + 8) = node4;
        count++;
        func_0047a0e0(*(u8 **)(node4 + 0x144), 0, 0.0f);
        func_00268c20(*(u16 *)(node4 + 0), 1);
        node4 = *(u8 **)(node4 + 0x138);
    }
    return entry;
}



// FUN_00255ED0
s32 func_00255ed0(s64 arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)func_002467b0((u16)arg0) + 4) & 0x10) != 0 &&
        (arg0 != 0x18 || func_00106330(0x38) != 0)) {
        if ((s16)func_00248d80(arg0) == 3 ||
            (s16)func_00248d80(arg0) == 4) {
            if (arg1 == 3) {
                return 7;
            }
            if (arg1 == 6) {
                return 8;
            }
            if (arg1 == 10) {
                return 9;
            }
        } else {
            if (arg1 == 3) {
                return 2;
            }
            if (arg1 == 7) {
                return 3;
            }
            if (arg1 == 5) {
                return 4;
            }
            if (arg1 == 9) {
                return 5;
            }
            if (arg1 == 1) {
                return 6;
            }
        }
    }
    return 0;
}



// FUN_00256040
void func_00256040(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                   s32 arg7) {
    u8 *spAC;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;

    func_00279d40(arg5);
    spAC = func_00279030((arg0 << 8) | arg1, fparg0, fparg1, fparg2, arg2,
                         arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        var_18 = func_002736d0(&spAC, arg7);
        if (var_18 == NULL) {
            var_18 = spAC;
            spAC = NULL;
        }
        var_17 = var_18;
        var_16 = 0;
        while (var_17 != NULL) {
            var_16 += func_002738d0(var_17);
            var_17 = *(u8 **)(var_17 + 0x24);
        }
        func_00272a10(var_18, fparg0 - ((f32)var_16 / 2.0f), fparg1);
        func_00272ba0(var_18, arg1 | ~0xFF);
        func_00273170(var_18, 1, 0);
        func_00271b70(var_18);
        if (spAC != NULL) {
            func_00271b70(spAC);
        }
    }
}



/* measured: retail frame is -0x140 with ra and $s0-$s5 saved; the two
   arrays are rgba at sp+0x70 and pairs at sp+0xc0, with an unexplained
   sixteen-byte slot at sp+0xb0.  The best complete reconstruction is
   archived in build/WB561_work_gap_pairwalk.json:
   `struct { RGBA rgba[16]; u8 scratch[16]; Pair pairs[16]; } Work`.
   This one aggregate reproduces the frame, saved-register set, and both
   array offsets; its object is 628 bytes against the 624-byte window
   (nd 484).  Its first fndiff row is offset 0x20: the persistent rgba
   base emits `addiu $t7,$sp,0x70` where retail starts the global read.
   Direct indexed variants scalarize the aggregate (frames -0x120/-0x130,
   objects 608-620), while the persistent base pins the gap at the cost
   of that one surplus instruction.  Explicit qword/union/alignment
   variants, separate locals, and branch-local pointer variants were
   ruled out.  General finding: an unexplained retail stack gap is a real
   declared object; declaring the complete frame as one struct in source
   declaration order reproduces offsets that separate locals do not. */
// FUN_002561F0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002561f0);
// FUN_00256460
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256460);



/* measured: nd 303 after four attempts; frame 0x150, prologue, both copy
   loops, func_00252230/003e0870 call shapes and the func_00366c70 arg layout
   (incl. s16 arg7 in $11, s16 stack args, msub.s alpha args) all match.
   Residual: (1) FP saved-reg rotation - retail keeps fparg4/temp_f21/temp_f20
   in $f22/$f21/$f20, mwcc allocates $f21/$f20/$f22 regardless of declaration
   order (tried both orders); (2) the D_00887300 vtable base must be assigned
   to a local JUST BEFORE its calls (retail lui/addiu into $s2 there); assigned
   early mwcc hoists it to the top in $s1 and the whole mid-function shifts.
   Tried: 6- and 9-param signatures (positional float regs confirmed: 3 unused
   leading f32s needed to place fparg3/fparg4 at $f15/$f16), (s16)/(s64) arg
   spellings, named vt local. FP-allocation floor + vtable-hoist placement. */
// FUN_002566D0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002566d0);

/* measured: nd 303 after four attempts; twin of func_002566d0 (same walls):
   frame 0x150, prologue, copy loops and all call shapes match, but (1) FP
   saved-reg rotation (fparg4/temp_f21/temp_f20 in $f22/$f21/$f20 retail vs
   $f21/$f20/$f22 mwcc, both declaration orders tried), (2) GPR rotation: mwcc
   saves the D_00887300 vt base in $s1 with arg2 in $s2 while retail uses $18
   for vt and $s1/$s0 for arg2's halves (vt declared first/last both tried),
   (3) the vt base must be assigned early to force a saved reg at all (late
   assignment makes mwcc rematerialize lui/lw per call and the frame shrinks
   to 0x140). Saved-register rotation + D_00887300 vtable-hoist floors; alpha
   sites need the (u32) cast like func_002570f0. */
// FUN_00256BE0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256be0);

/* measured: nd 189 after four attempts; frame 0x1C0, all stack offsets, both
   copy loops, all zero-fill loops, the struct stores/copies (lq/sq), and the
   func_00252230/003e0870/0045d6e0/0048a000/0045db40 call shapes match. Two
   unreachable residuals: (1) the D_00887300 render-vtable hoist floor - retail
   keeps the base in $s0 and does lw 0($s0)/jalr per call; mwcc b210 emits a
   dead lui/addiu $s0 and rematerializes lui+lw per call (7 calls per half).
   (2) alpha sites: `x & 0xFF >= 0` on an s32 is provably true so mwcc drops
   the branch - the (u32) cast (`(u32)x & 0xFF`) defeats the prover and emits
   the retail andi/bltz exactly (verified on b210 after this was written).
   Also: s16 arg7/stack s16s, s64 vs s32 arg_sp10 (s64 shifts every stack arg
   and is worse). */
// FUN_002570F0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002570f0);

// FUN_00257820
s32 func_00257820(s32 arg0, void *arg1) {
    s32 var_4;
    u8 *var_2;
    u16 var_17;

    var_17 = 0x400;
    var_2 = func_00145270(0x400);
    if (var_2 == NULL) {
        var_17 = ((arg0 & 0x3FF) | 0xC00) & 0xFFFF;
        var_2 = func_00145270(var_17);
    }
    if (var_2 != NULL) {
        var_4 = 0;
        switch ((s32)((var_17 & 0xFFC00) >> 0xA)) {
        case 1:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        case 3:
            var_4 = *(s32 *)(var_2 + 0x164);
            break;
        }
        if (var_4 != 0) {
            func_0047a6d0(var_4, 2, arg1);
            return 1;
        }
    }
    return 0;
}



/* measured: not attempted this wave (14320 B, the file's biggest); m2c draft
   is complete apart from 6 M2C_ERRORs (VU0-free - check them against the
   retail asm before writing). It drives func_00256460/002566d0/00256be0/
   002570f0 and the func_0025f3f0 menu draws. Call-signature facts established
   this wave and needed here: func_002566d0 takes (s32 arg0, s32 arg1, s64
   arg2, s64 arg3, f32 fparg0..fparg4) with floats position-allocated from
   $f12 (3 unused leading floats place fparg3/fparg4 at $f15/$f16);
   func_002570f0 takes (s32, s32, s64, f32 x4); func_00366c70 is (s32 x7, s16,
   f32, s16, void*, s32, void*) with the s16s sign-extended via dsll32/dsra32;
   func_00256460 takes 8 ints + 5 floats (its 6th/7th params are passed to
   func_0045e6a0 with (s16) narrowing). Family walls (see the sibling notes):
   (u32)-cast alpha sites, vt-base rematerialization, stack-slot overlap. */
// FUN_00257900
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00257900);

/* measured: nd 94 with a full C body, object 320B against a 336B window (wave 7
   ran out of turns here and left it uncommitted). The body is undersized, so work
   is missing rather than merely mis-scheduled; re-attempt from the m2c draft. */
static inline void *rankArg0(f32 *p) { return p; }
static inline void *rankArg1(u8 *p) { return p; }

/* measured: nd 24. Retail hoists `addiu $a0,$sp,0x5C` (the &fbuf arg for
   func_0045d6e0) between the fbuf/quad stores and `addiu $a1,$sp,0x40` between
   the two lq/sq copies; mwcc b210 sinks both address materializations to just
   before the jal (24 bytes). Tried: direct &fbuf/&arr[16], address locals,
   `*fp = ...` store-through-pointer, single arr[32] with &arr[16], and
   static-inline arg helpers - all nd 24. Same documented load-sinking floor as
   mc.c func_002a4d10 (nd 62 there). Rest of function matches byte-exact:
   switch jtbl_00747E50 (15 cases, cases 9/10 -> func_00257900), byte-fill
   loop with beqz-pointer guard, (u8)(s32) float conversion with 2^31 arm. Committed at nd 24. */
// FUN_0025B0F0 NONMATCHING
#ifdef NON_MATCHING
void func_0025b0f0(s32 arg0, u8 *arg1) {
    extern u32 *func_00452560();
    u8 *sp;
    u8 *p;
    s32 i;
    f32 fbuf;
    u8 buf[4];
    u8 arr[32];
    u_long128 quad;
    f32 f;

    sp = (u8 *)func_00452560(arg1);
    p = buf;
    i = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
        } while (--i != 0);
    }
    f = (f32)*(s32 *)(sp + 0x4C) * 127.5f / 40.0f;
    buf[3] = (u8)f;
    fbuf = *(f32 *)buf;
    quad = D_00636730;
    *(u_long128 *)&arr[0] = quad;
    *(u_long128 *)&arr[16] = quad;
    func_0045d6e0(&fbuf, &arr[16], 1, 0.0f);
    switch (*(u32 *)(sp + 4)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 9:
    case 10:
        func_00257900(arg1);
        break;
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025b0f0);
#endif
// FUN_0025B240
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025b240);



/* measured: retail hoists the jtbl_008873EC base into $s0 (reusing the dead
 * loop counter) and reloads the element per call; mwcc b210 rematerializes
 * the base at the FIRST call site (lui+lw) even when the base is cached in a
 * local (nd 34 with late assignment, nd 69 with early assignment, nd 28
 * direct). Loop and all other calls match byte-for-byte. Same floor as the
 * confirmed D_00887300 vtable calls. */
// FUN_0025C100
void func_0025c100(void) {
    void (**fp)(void *);
    u8 *p;
    u8 *list;
    s32 i;

    p = (u8 *)func_00452560();
    if (*(s32 *)p & 1) {
        func_00189ec0();
    }
    list = *(u8 **)(p + 0x40);
    i = 0;
    while (*(s32 *)(list + i * 0x10 + 8) != 0) {
        if (*(s32 *)(list + i * 0x10 + 0xC) == 0) {
            func_00268bd0(*(s32 *)(list + i * 0x10 + 8), 0);
        }
        func_0047a0e0(*(u8 **)(list + i * 0x10 + 4), 0, *(f32 *)(list + i * 0x10));
        i++;
    }
    fp = (void (**)(void *))DAT_008873ec_abs;
    (*fp)(list);
    if (*(u32 *)(p + 0x50) != 0) {
        func_0046d730(&D_00635CF8, 0xC2F);
    }
    if (*(u8 **)(p + 0x58) != NULL) {
        (*fp)(*(u8 **)(p + 0x58));
    }
    if (*(u32 *)(p + 0x54) != 0) {
        func_003ef3a0(*(u32 *)(p + 0x54));
    }
    func_00454bd0(*(u32 *)(p + 0x34));
    (*fp)(p);
}
// FUN_0025C230
void func_0025c230(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    if (arg1 == 0) {
        func_0046d730(D_00635CF8, 0xC40);
    }
    func_0044ea90(D_00635CF8, 0xC41);
    p = (u8 *)D_008873F4[0](1, 0x5C, 0x40000);
    *(s32 *)(p + 0x18) = arg1;
    *(s32 *)(p + 0x1C) = arg2;
    *(s32 *)(p + 0x20) = arg3;
    *(s32 *)(p + 0x4) = 0;
    func_00451fc0(arg0, D_006367C0, 0xF, 0, 0, func_0025b240, func_0025c100, p);
}
