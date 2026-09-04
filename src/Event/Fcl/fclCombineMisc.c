/* Original translation unit fclCombineMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
extern s32 func_003124a0();
extern s32 func_003127e0();
extern u32 func_003b7060();
extern s16 func_002e54c0(s8 arg0, s16 arg1);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0046d730(const char *file, s32 line);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0010cad0();
extern u8 *iGpffffb3d4;
extern char D_00642F30[];
extern s32 func_00312220(u16 *arg0, s32 arg1, u16 *arg2, s32 arg3);
extern u8 func_00311ea0(u8 *arg0, u8 *arg1, u8 *arg2);
extern s32 func_003130e0(u32 arg0, s32 arg1, u16 *arg2);
extern s32 func_00106330(s32 id);
extern u8 D_006420A0[];
extern u8 D_00642F00[];
extern u8 D_00642F04[];

/* measured: structure fully recovered (16B ptr[4] zero loop, 3-pair s8 copy
   from iGpffffa8d0 to sp58, 3-iteration bubble sort by ptr[][4] then
   iGpffffb3d4[ptr[][2]*14+2] tiebreak into sp4C, the t18/t16/t17 loads and
   D_00642727/D_00642967 min*24+max lookups) but mwcc b210 allocates the
   s16 sort-loop counter to $a3 (retail $a0) and reorders the D_00642727
   index computation (t17*24 before +t16; retail t16*24 before +t17), and
   the object is 836B vs 896B window (15 words short). Tried s16/s32 loop,
   indexed vs pointer-increment sp58 copy, named sp4C swap temp; nd 193.
   Register-allocation + tail-order floor. */
// FUN_00311EA0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00311ea0);

/* measured: structure fully recovered (s128 aggregate-copy count reload,
   threshold gate, 0x17-entry flag scan, four-entry callback loop, and
   indexed result lookup), but no clean-C probe reaches the retail code.
   Best probe uses typedef signed __int128 for the retail sq/lq count,
   an s64 outer counter and threshold, and an indexed final return:
   object 640B vs the 640B retail window, normalized_diff 76
   (reloc-masked). The prior pointer-arithmetic return was nd77; the
   earlier s32-counter body was 648B vs 640B, nd97.
   Tried scalar s128 storage, threshold and outer-counter width/forms,
   explicit gate labels and branch forms, declaration ordering, parameter
   ABI widths, typed versus old-style helper declarations, key and
   bottom-pointer lifetimes, and focused optimization pragmas. Remaining
   residuals are real saved-register allocation and loop-layout differences:
   MWCC maps arg2 to $s5 rather than retail $s3, spills arg3 instead of
   retaining it in $fp, rotates threshold/key/status across $s7/$fp/$s6
   rather than $s6/$s7/$s5, and uses $s3 for the outer counter rather than
   retail $s2. Production intentionally retains INCLUDE_ASM. */
// FUN_00312220
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312220);

/* measured: structure fully recovered (sp8C/sp8E pair, func_00312220 gate,
   temp_16/temp_20 from iGpffffb3d4+arg*14+2, func_002ac350() branch into
   D_00642147 vs D_00642387 min*24+max lookups, the sp70 zero+pair, the
   (base[arg1*14+3]+base[arg2*14+3])/2 rounding into temp_5_2, and the
   func_003133b0-vs-func_003130e0 dispatch on temp_16==base[arg*14+2]) but
   the measured C probe was 804B vs the 832B retail window (nd 539).
   mwcc b210 keeps temp_21 (arg2*14) in $s6 (retail frame 0x90 vs 0xA0
   candidate) and flips both result-table index add orders. Register-allocation
   + index-order floor; probe discarded. */
// FUN_003124A0
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_003124a0);

// FUN_003127E0
s32 func_003127e0(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u16 sp78[3];
    u8 sp60[0x18];
    s32 t;
    u16 ret;
    u8 *p;

    sp78[0] = *(u16 *)(arg1 + 2);
    sp78[1] = *(u16 *)(arg2 + 2);
    sp78[2] = *(u16 *)(arg3 + 2);
    if (arg0 == NULL || arg1 == NULL || arg2 == NULL || arg3 == NULL) {
        func_0046d730(D_00642F30, 0x1CC);
    }
    if (func_00312220(arg0, 1, sp78, 3) & 0xFF) {
        return 2;
    }
    t = func_00311ea0(arg1, arg2, arg3) & 0xFF;
    if (t == 0) {
        func_0043f9c8(arg0, 0, 0x30);
        return 0;
    }
    func_0043f9c8(sp60, 0, 0x18);
    *(u16 *)&sp60[0] = *(u16 *)(arg1 + 2);
    *(u16 *)&sp60[2] = *(u16 *)(arg2 + 2);
    *(u16 *)&sp60[4] = *(u16 *)(arg3 + 2);
    p = iGpffffb3d4 + 3;
    ret = func_003130e0(t, (((s32)p[*(u16 *)(arg1 + 2) * 0xE] + (s32)p[*(u16 *)(arg2 + 2) * 0xE] + (s32)p[*(u16 *)(arg3 + 2) * 0xE]) / 3 + 5) & 0xFF, (u16 *)sp60) & 0xFFFF;
    if (ret == 0) {
        return 0;
    }
    func_0010cad0(arg0, ret);
    return 1;
}

// FUN_003129B0
s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2) {
    s16 tbl[4];
    s16 i;
    s16 j;
    s32 a1;
    s32 a2;

    tbl[0] = 0xD;
    tbl[1] = 0x35;
    tbl[2] = 0x49;
    tbl[3] = 0x66;
    i = 0;
    a1 = arg1 & 0xFFFF;
    a2 = arg2 & 0xFFFF;
    while (i < 4) {
        if (a1 == tbl[i]) {
            j = 0;
            while (j < 4) {
                if (a2 == tbl[j]) {
                    return 0;
                }
                j++;
            }
        }
        i++;
    }
    j = 0;
    while (j < 4) {
        if (a1 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg2)), 0x30);
            return 1;
        }
        if (a2 == tbl[j]) {
            func_0043f810(arg0, func_002e48a0(0, func_002e54c0(0, (s16)arg1)), 0x30);
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_00312B60
s32 func_00312b60(s32 arg0, s32 arg1, s32 arg2) {
    return func_003124a0(arg0, arg1 & 0xFFFF, arg2 & 0xFFFF) & 0xFF;
}

// FUN_00312B90
s32 func_00312b90(u16 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    return func_003127e0(arg0, arg1, arg2, arg3) & 0xFF;
}

// FUN_00312BC0
#pragma opt_rebuildconditionals off
/* measured: without this, mwcc b210 booleanizes `if (v < 0x40) return 1; return 0;`
   into slti $v0 + unconditional branch (return value = condition); retail keeps
   beqz $at -> shared return-0 + addiu $v0,1. Both branch orientations and the
   if/else forms tried (nd 24); with the pragma the switch body matches exactly. */
s32 func_00312bc0(s8 arg0) {
    s32 v;
    switch (arg0) {
    case 2:
        v = (s32)(func_003b7060() & 0x3F) << 6;
        if (v < 0x40) {
            return 1;
        }
        break;
    case 3:
        v = (s32)(func_003b7060() & 0x1F) << 5;
        if (v < 0x20) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
#pragma opt_rebuildconditionals on

/* measured: raw C reconstruction compiles to 1264B against the 1152B retail
   window with normalized_diff 924. Retail keeps a 0xA0 frame and maps the
   input/table locals to $s3/$fp/$s0/$s6; the straightforward typed loops
   grew a 0xB0 frame and rotated those saved registers. Probe discarded. */
/* Named compiler floor: the typed loop's saved-register/frame allocation grows
   and rotates under b210; keep this body as ASM rather than inflating C with
   artificial locals or pragmas. */
// FUN_00312C60
INCLUDE_ASM("asm/nonmatchings/fclCombineMisc", func_00312c60);

/* measured: retail sq's arg0&0xFF into spA0 (0xA0) and lq's it back in the
   0xC0 i-loop, comparing via raw bne (lq $2,0xA0 / bne $2,$3). The old
   "u_long128 aliased scalar read-back" probe (720B window, nd528, "no legal
   C data-size spelling") was WRONG about the type: `typedef signed __int128
   s128;` (declared locally, see docs/matching.md's corrected "128-bit lq/sq
   aggregate copy" entry and effBlurFilter.c/evtPolygonMovie.c/shdSprite.c
   for the proven pattern) genuinely lowers to lq/sq and reproduces retail's
   exact -0xB0 frame and register coloring for the store/reload; a narrowing
   (s64) cast on the reload is required for the actual bne compare (s128
   itself has no legal == in b210 -- "illegal data size" -- matching that
   retail's bne is not a real 128-bit compare either). Two focused sessions
   with this real type got the residual down from nd528/541 to nd163 (712B
   vs 720B, 63 differing words in the tail/bottom-loop control-flow and
   CSE layout) but not to an exact MATCH. Still a floor for now, but NOT a
   type-spelling floor -- the residual is ordinary register-allocation/
   control-flow shape, the same category as any other near-miss. Worth
   another attempt with fresh eyes on the bottom-loop layout specifically. */
// FUN_003130E0
s32 func_003130e0(u32 arg0, s32 arg1, u16 *arg2) {
    typedef signed __int128 s128;
    extern u8 *DAT_007644c4;
    u16 *input;
    s128 spA0;
    s16 temp_3_2;
    s32 temp_16;
    s32 temp_21;
    s32 temp_23;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_20;
    s32 var_19;
    s32 var_18;
    s32 var_22;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    s32 var_3_2;
    u16 temp_3;
    u32 var_17;
    u8 temp_5;
    u8 *temp_4;
    u8 *temp_4_2;

    var_19 = 0;
    var_18 = 0;
    var_20 = 0;
    input = arg2;
    spA0 = arg0 & 0xFF;
    temp_23 = arg1 & 0xFF;
    for (; (var_20 & 0xFFFF) < 0xC0;
         var_20 = (var_20 + 1) & 0xFFFF) {
        temp_16 = var_20 & 0xFFFF;
        temp_4 = iGpffffb3d4;
        temp_21 = (u16)var_20 * 0xE;
        temp_4 += temp_21;
        if ((s64)spA0 == *(u8 *)(temp_4 + 2)) {
            temp_3 = *(u16 *)temp_4;
            if (temp_3 & 1) {
                var_2 = 0;
            } else if (temp_3 & 2) {
                var_2 = 0;
            } else {
                var_2 = 1;
            }
            if (var_2 != 0) {
                var_22 = 1;
                for (var_17 = 0; var_17 < 0x17U; var_17++) {
                    temp_4_2 = D_006420A0 + (var_17 * 8);
                    if (temp_16 != *(s16 *)(temp_4_2 + 4)) {
                        continue;
                    }
                    temp_3_2 = *(s16 *)(temp_4_2 + 6);
                    if (temp_3_2 & 1) {
                        if (func_00106330(*(s32 *)temp_4_2) != 0) {
                            continue;
                        }
                        var_3 = 0;
                        goto block_16;
                    } else if (temp_3_2 & 2) {
                        var_22 = 0;
                        if (func_00106330(*(s32 *)temp_4_2) != 1) {
                            continue;
                        }
                        var_3 = 1;
                        goto block_16;
                    }
                }
                var_3 = var_22;
block_16:
                if (var_3 != 0) {
                    temp_3_3 = var_18 & 0xFFFF;
                    if ((temp_3_3 == 0) ||
                        ((temp_4_3 = (s32)iGpffffb3d4,
                          (s32)*(u8 *)(temp_4_3 + (temp_3_3 * 0xE) + 3) <
                          (s32)*(u8 *)(temp_4_3 + temp_21 + 3)) != 0)) {
                        temp_16 = temp_16 ^ 0;
                        var_18 = (u32)(u16)var_20;
                    }
                    temp_5 = *(u8 *)(iGpffffb3d4 + temp_21 + 3);
                    if ((s32)temp_5 >= temp_23) {
                        var_3_2 = 0;
                        goto loop_28_cond;
loop_28_body:
                        if (temp_16 == input[var_3_2]) {
                            var_2_2 = 1;
                            goto loop_28_done;
                        }
                        var_3_2 += 1;
loop_28_cond:
                        if (var_3_2 < 0xC) {
                            goto loop_28_body;
                        }
                        var_2_2 = 0;
loop_28_done:
                        if ((var_2_2 == 0) &&
                            ((temp_4_4 = var_19 & 0xFFFF,
                              (temp_4_4 == 0)) ||
                             ((temp_4_3 = (s32)DAT_007644c4,
                               (s32)temp_5 <
                               (s32)*(u8 *)(temp_4_3 + (temp_4_4 * 0xE) + 3)) != 0))) {
                            temp_16 = temp_16 ^ 0;
                            var_19 = (u32)(u16)var_20;
                        }
                    }
                }
            }
        }
    }
    if (!(var_18 & 0xFFFF)) {
        return 0;
    }
    if (!(var_19 & 0xFFFF)) {
        temp_4_3 = (s32)iGpffffb3d4;
        temp_3_4 = var_18 & 0xFFFF;
        temp_4 = (u8 *)(temp_3_4 * 0xE);
        temp_4 += temp_4_3;
        if ((s32)*(u8 *)(temp_4 + 3) < temp_23) {
            var_19 = temp_3_4;
        }
    }
    return var_19;
}

/* measured: identical 128-bit-slot pattern to func_003130e0 (retail sq's
   arg0&0xFF into spA0 at 0xA0 and lq's it back in the 0xC0 i-loop, raw bne
   compare; 736B retail window). The corrected technique from docs/matching.md's
   "128-bit lq/sq aggregate copy" entry closes this target: local
   `typedef signed __int128 s128;`, a narrowing (s64) reload compare, and
   source-shaped continue/masked-u16 updates produce an exact MATCH
   (724B object, relocation-normalized diff 0). */
// FUN_003133B0
s32 func_003133b0(u32 arg0, s32 arg1, u16 *arg2) {
    typedef signed __int128 s128;
    extern u8 *DAT_007644c4;
    u16 *input;
    s128 spA0;
    s16 temp_3_2;
    s32 temp_16;
    s32 temp_21;
    s32 temp_23;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 var_20;
    s32 var_19;
    s32 var_18;
    s32 var_22;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    s32 var_3_2;
    u16 temp_3;
    u32 var_17;
    u8 temp_5;
    u8 *temp_4;
    u8 *temp_4_2;

    var_19 = 0;
    var_18 = 0;
    var_20 = 0;
    input = arg2;
    spA0 = arg0 & 0xFF;
    temp_23 = arg1 & 0xFF;
    for (; (var_20 & 0xFFFF) < 0xC0;
         var_20 = (var_20 + 1) & 0xFFFF) {
        temp_16 = var_20 & 0xFFFF;
        temp_4 = iGpffffb3d4;
        temp_21 = (u16)var_20 * 0xE;
        temp_4 += temp_21;
        if ((s64)spA0 == *(u8 *)(temp_4 + 2)) {
            temp_3 = *(u16 *)temp_4;
            if (temp_3 & 1) {
                var_2 = 0;
            } else if (temp_3 & 2) {
                var_2 = 0;
            } else {
                var_2 = 1;
            }
            if (var_2 != 0) {
                var_22 = 1;
                for (var_17 = 0; var_17 < 0x17U; var_17++) {
                    temp_4_2 = D_006420A0 + (var_17 * 8);
                    if (temp_16 != *(s16 *)(temp_4_2 + 4)) {
                        continue;
                    }
                    temp_3_2 = *(s16 *)(temp_4_2 + 6);
                    if (temp_3_2 & 1) {
                        if (func_00106330(*(s32 *)temp_4_2) != 0) {
                            continue;
                        }
                        var_3 = 0;
                        goto block_16;
                    } else if (temp_3_2 & 2) {
                        var_22 = 0;
                        if (func_00106330(*(s32 *)temp_4_2) != 1) {
                            continue;
                        }
                        var_3 = 1;
                        goto block_16;
                    }
                }
                var_3 = var_22;
block_16:
                if (var_3 != 0) {
                    temp_3_3 = var_18 & 0xFFFF;
                    if ((temp_3_3 == 0) ||
                        ((temp_4_3 = (s32)iGpffffb3d4,
                          (s32)*(u8 *)(temp_4_3 + (temp_3_3 * 0xE) + 3) <
                          (s32)*(u8 *)(temp_4_3 + temp_21 + 3)) != 0)) {
                        temp_16 = temp_16 ^ 0;
                        var_18 = (u32)(u16)var_20;
                    }
                    temp_5 = *(u8 *)(iGpffffb3d4 + temp_21 + 3);
                    if ((s32)temp_5 > temp_23) {
                        continue;
                    }
                    var_3_2 = 0;
                    goto loop_28_cond;
loop_28_body:
                    if (temp_16 == input[var_3_2]) {
                        var_2_2 = 1;
                        goto loop_28_done;
                    }
                    var_3_2 += 1;
loop_28_cond:
                    if (var_3_2 < 0xC) {
                        goto loop_28_body;
                    }
                    var_2_2 = 0;
loop_28_done:
                    if ((var_2_2 == 0) &&
                        ((temp_4_4 = var_19 & 0xFFFF,
                          (temp_4_4 == 0)) ||
                         ((temp_4_3 = (s32)DAT_007644c4,
                           (s32)*(u8 *)(temp_4_3 +
                                        (temp_4_4 * 0xE) + 3) <
                           (s32)temp_5)))) {
                        temp_16 = temp_16 ^ 0;
                        var_19 = (u32)(u16)var_20;
                    }
                }
            }
        }
    }
    if (var_18 == 0) {
        func_0046d730(D_00642F30, 0x43A);
    }
    if (!(var_19 & 0xFFFF)) {
        temp_4_3 = (s32)DAT_007644c4;
        temp_3_4 = var_18 & 0xFFFF;
        temp_4 = (u8 *)(temp_3_4 * 0xE);
        temp_4 += temp_4_3;
        if ((s32)*(u8 *)(temp_4 + 3) < temp_23) {
            var_19 = temp_3_4;
        }
    }
    return var_19;
}

