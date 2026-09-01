/* Attempted reconstruction for func_001fc300: object 416B, window 416B, normalized_diff 14.
   Differing word offsets: 220, 228, 232, 236, 240, 244, 248, 356, 364, 368, 372, 376, 380, 384.
   Ruled out: plain and generated-style switch/if forms; reversed/equality goto forms;
   zero-before-done and do-while layouts; local/whole opt_rebuildconditionals;
   local opt_loop_invariants off; whole/post-loop opt_propagation off; and redundant gotos.
   The retained near-match uses opt_loop_invariants on for the loop and local
   opt_propagation off around both mode-1 blocks. */
s64 func_001fc300(u8 *arg0, u8 *arg1)
{
    u8 *table;
    s32 temp_8;
    s32 var_10;
    s32 one;
    s64 var_2;
    s64 var_2_2;
    u32 temp_6;
    u8 temp_3;
    u8 temp_3_2;

    if (*(u8 *)(arg1 + 3) != 0) {
        return 1;
    }
    var_10 = 0;
    table = (u8 *)D_00881440_abs;
    one = 1;
    goto loop_test;
loop_body:
    temp_8 = *(s32 *)(table + ((u16)var_10 * 4) + 8);
    if (temp_8 != 0) {
        if ((*(u8 *)(arg1 + 2) & (one << temp_6)) &&
            ((u8 *)temp_8 == arg0)) {
            return 1;
        }
        var_10 = (var_10 + 1) & 0xFFFF;
        goto loop_test;
    }
    goto block_9;
loop_test:
    temp_6 = var_10 & 0xFFFF;
    if (temp_6 < 3U) {
        goto loop_body;
    }
block_9:
    if ((D_00881440_abs[0] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881440_abs[0] + 0xA2))) {
        temp_3 = *(u8 *)(arg1 + 0);
        switch (temp_3) {
        case 0:
            return 0;
#pragma opt_propagation off
        case 1:
            var_2_2 = 1;
            if (D_00881440_abs[0] != (s32)arg0) {
                goto mode1_first_zero;
            }
            goto mode1_first_done;
mode1_first_done:
            return (s64)(var_2_2 << 0x38) >> 0x38;
mode1_first_zero:
            var_2_2 = 0;
            goto mode1_first_done;
#pragma opt_propagation on
        case 2:
            return 1;
        }
    }
    if ((D_00881444_abs[0] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881444_abs[0] + 0xA2))) {
        temp_3_2 = *(u8 *)(arg1 + 1);
        switch (temp_3_2) {
        case 0:
            return 0;
#pragma opt_propagation off
        case 1:
            var_2 = 1;
            if (D_00881444_abs[0] != (s32)arg0) {
                goto mode1_second_zero;
            }
            goto mode1_second_done;
mode1_second_done:
            return (s64)(var_2 << 0x38) >> 0x38;
mode1_second_zero:
            var_2 = 0;
            goto mode1_second_done;
#pragma opt_propagation on
        case 2:
            return 1;
        }
    }
    return 0;
}
