/* Best candidate: object 276B, window 288B, normalized_diff 5 -- only 3
   genuinely differing words (offsets 228, 232, 252). All in the
   loop_18_branch tail:

     temp_3 = var_4 + temp_7;
     switch (var_10 < temp_3) {
     case 0: var_10 = temp_3; break;
     }
     var_4 = var_10;

   Retail computes `var_4 + temp_7` into a FRESH register ($v1) and compares/
   assigns through it, then only copies into var_4's register at the very
   end. My candidate lets the compiler reuse var_4's own (dying) register for
   the sum, which is a smaller but functionally equivalent choice the
   allocator is free to make and did not.

   switch(bool) is confirmed correct here, not an m2c artifact: replacing it
   with a plain if/if-else regresses to nd 31 (obj 268B) in every form
   tried. So the case-based structure must be kept.

   14 variants tried against this exact site: dropping the harmless m2c
   `+ 0`, swapping the addition's operand order, introducing a fresh named
   local for the sum (worse, nd 12), block-scoping that local (same, nd 12),
   duplicating the final var_4 assignment inside each switch arm instead of
   after (worse, nd 28), assigning var_4 directly from temp_3 in the case
   arm (worse, nd 23), and opt_common_subs/opt_propagation/opt_lifetimes/
   opt_scalarizeliveranges all off (no change, nd 5 exactly). schedule on
   and optimization_level 4 both regress badly (nd 167, object drops to
   220B -- they eliminate/restructure code this function needs). No
   variant beat the original m2c-derived nd 5. */
void func_002b2e70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4, s16 *arg5)
{
    s32 var_4;
    s32 temp_3;
    s32 var_12;
    s32 temp_6;
    s32 var_11;
    s32 var_10;
    s32 temp_7;
    s32 var_7;
    var_4 = arg0;
    var_12 = 0;
    if (arg2 == 0) { *arg4 = 0; *arg5 = 0; return; }
    var_10 = arg2 - 1;
    if (var_4 != var_10) {
        temp_3 = var_4 - arg1;
        temp_7 = (s8)arg3;
        temp_6 = arg2 - (temp_3 + temp_7);
        if (temp_6 <= 0) {
            arg2 = var_4;
            var_11 = 0;
            goto loop_10_test;
loop_10_body:
            arg2 += 1;
            if (var_10 < arg2) arg2 = var_10;
            var_12 += 1;
            if (arg2 >= var_10) { arg1 += var_12; goto loop_10_done; }
            var_11 += 1;
loop_10_test:
            if (var_11 < temp_7) goto loop_10_body;
loop_10_done:
            var_4 += var_12;
        } else {
            if (temp_6 > temp_7) goto loop_18_branch;
            goto loop_17_branch;
loop_17_branch:
            var_7 = 0;
            goto loop_17_test;
            do {
loop_17_body:
                var_4 += 1;
                if (var_10 < var_4) var_4 = var_10;
                var_7 += 1;
loop_17_test: ;
            } while (var_7 < temp_6);
            goto loop_17_done;
loop_18_branch:
            temp_3 = var_4 + temp_7;
            switch (var_10 < temp_3) {
            case 0:
                var_10 = temp_3;
                break;
            }
            var_4 = var_10;
loop_17_done: ;
        }
    }
    *arg4 = var_4;
    *arg5 = arg1;
}
