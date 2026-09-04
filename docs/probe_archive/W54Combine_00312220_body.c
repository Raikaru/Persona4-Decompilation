/*
 * W54Combine archive for func_00312220 @ 0x00312220.
 * Best measured clean-C floor (kept out of production): object 640B,
 * retail window 640B, normalized_diff 76 (reloc-masked), measured with:
 *   python3 -E -s tools/fndiff.py build/W54Combine_00312220_return_indexed.c func_00312220
 *
 * The probe sequence covered the recovered s128 aggregate-copy idiom for the
 * sq/lq count, s64 outer counter and threshold forms, explicit threshold
 * labels and branch forms, declaration ordering, parameter ABI widths,
 * typed versus old-style helper declarations, key and bottom-pointer lifetime
 * forms, focused optimization pragmas, and indexed versus pointer arithmetic
 * in the final table lookup. The indexed return is the best result (nd76);
 * the otherwise identical pointer-arithmetic return measured nd77. The
 * previous s32-counter source was 648B versus the 640B window, nd97.
 *
 * Real residuals remain in the saved-register coloring and loop layout:
 * MWCC keeps arg2 in $s5 rather than retail $s3 and spills arg3 instead of
 * retaining it in $fp; it places the threshold/key/status in $s7/$fp/$s6
 * rather than $s6/$s7/$s5; it uses $s3 for the outer counter rather than
 * retail $s2; and its threshold, flag-loop, and bottom-loop branch layouts
 * differ. These are ordinary compiler allocation/control-flow differences,
 * not relocation-only noise. Production therefore retains INCLUDE_ASM.
 */
#include "type.h"

extern s32 func_00311b90();
extern s32 func_00106330(s32 id);
extern void func_0010cad0();
extern s32 func_0010cc20();
extern s32 func_0010ce10();
extern void func_0046d730();
extern u8 *iGpffffb3d4;
extern char D_00642F30[];
extern u8 D_006420A0[];
extern u8 D_00642F00[];
extern u8 D_00642F04[];

u8 func_00312220(u16 *arg0, s32 arg1, u16 *arg2, s32 arg3) {
    typedef signed __int128 s128;
    s128 spA0;
    s16 spBE;
    s16 temp_3_2;
    s32 temp_3;
    s32 var_16_2;
    s64 var_18;
    s32 var_21;
    s32 var_2;
    s32 var_3;
    u16 *temp_2;
    u16 *var_17;
    u16 temp_23;
    u16 temp_5;
    u32 var_16;
    u8 *temp_4;
    s64 threshold;

    if ((arg0 == NULL) || (arg2 == NULL) || (arg1 >= 5)) {
        func_0046d730(D_00642F30, 0x17B);
    }
    temp_3 = arg1 * 8;
    var_17 = *(u16 **)(D_00642F00 + temp_3);
    spA0 = (s128)*(s32 *)(D_00642F04 + temp_3);
    var_18 = 0;
    threshold = (s64)(arg1 + 2);
    while (var_18 < (s64)spA0) {
        spBE = 0;
        var_2 = func_00311b90(var_17, arg2, arg3, &spBE);
        if ((s64)spBE < threshold) {
            goto threshold_fail;
        }
        goto threshold_ok;
threshold_fail:
        var_2 = 0;
threshold_ok:
        if (var_2 != 0) {
            temp_23 = *var_17;
            var_21 = 1;
            var_16 = 0;
loop_18:
            if (var_16 >= 0x17U) {
                var_3 = var_21;
            } else {
                temp_4 = D_006420A0 + (var_16 * 8);
                if (temp_23 == *(u16 *)(temp_4 + 4)) {
                    temp_3_2 = *(s16 *)(temp_4 + 6);
                    if (temp_3_2 & 1) {
                        if (func_00106330(*(s32 *)temp_4) == 0) {
                            var_3 = 0;
                        } else {
                            goto block_17;
                        }
                    } else if ((temp_3_2 & 2) &&
                               (var_21 = 0, var_3 = 1,
                                (func_00106330(*(s32 *)temp_4) == 1))) {
                    } else {
                        goto block_17;
                    }
                } else {
block_17:
                    var_16 += 1;
                    goto loop_18;
                }
            }
            if (var_3 != 0) {
                func_0010cad0(arg0, *var_17);
                var_16_2 = 0;
loop_26:
                if (var_16_2 < 4) {
                    temp_2 = &var_17[var_16_2];
                    temp_5 = *(u16 *)((u8 *)temp_2 + 0x18);
                    if ((temp_5 == 0) ||
                        (func_0010ce10(arg0, temp_5) != -1) ||
                        (func_0010cc20(arg0,
                                       *(u16 *)((u8 *)temp_2 + 0x18)) != 0)) {
                        var_16_2 += 1;
                        goto loop_26;
                    }
                }
                return iGpffffb3d4[(*(u16 *)((u8 *)arg0 + 2) * 0xE) + 2];
            }
        }
        var_17 = (u16 *)((u8 *)var_17 + 0x20);
        var_18 += 1;
    }
    return 0;
}
