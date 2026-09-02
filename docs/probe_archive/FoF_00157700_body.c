/* Target func_00157700; best attempted body was FoF11 (740B object,
   688B retail window, normalized_diff 489, MISMATCH). It reproduced the
   -0xC0 frame, saved-register assignment, and two stack sq/lq slots, but
   retained dsll32/dsra32 conversions around the quadword values and did not
   close. Source was reverted to INCLUDE_ASM because a live non-MATCH body is
   not permitted.

   Retail saved registers (declaration/order evidence):
   $fp = arg2, $s7 = arg6, $s6 = arg5, $s5 = arg0, $s4 = arg1,
   $s3 = arg3, $s2 = arg4, $s1 = arg1 << 8, $s0 = arg0 * 0x10.

   Attempts: straightforward scalar body (FoF1), s64 offsets (FoF2), four
   signed/u64 s128 locals (FoF3/FoF4/FoF17), split scalar offsets plus q
   locals (FoF5), direct u64 array (FoF6/FoF7), inner-block q locals (FoF8),
   pointer offsets (FoF9), signed int128 source-shaped body (FoF10/FoF11),
   aggregate source loads (FoF12), addressable u64/signed q locals (FoF13/
   FoF14), propagation-off q body (FoF15), and no-pragma u64 q body (FoF16).
*/

void func_00157700(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                    s32 arg4, s32 *arg5, s32 *arg6)
{
    typedef signed __int128 s128;
    s128 spB0;
    s128 spA0;
    s32 temp_16;
    s32 temp_17;
    s32 temp_30;
    s32 var_19;
    s32 var_7;
    u8 temp_4;

    var_19 = arg3;
    if (var_19 < arg4) {
        temp_17 = arg1 << 8;
        temp_16 = arg0 * 0x10;
        temp_4 = ((u8 *)func_00155280() + temp_17 + temp_16)[0x54];
        if (temp_4 == 1) {
            spB0 = (s128)temp_17;
            spA0 = (s128)temp_16;
            temp_30 = ~arg2 &
                      ((u8 *)func_00155280() + (s32)spB0 + (s32)spA0)[0x5E];
            if (((u8 *)func_00155280() + (s32)spB0 + (s32)spA0)[0x58] == 2) {
                *arg5 = 1;
            }
            if (((u8 *)func_00155280() + temp_17 + temp_16)[0x58] >= 9) {
                *arg6 = 1;
            }
            if (temp_30 & 1) {
                func_00157700(arg0, arg1 - 1, 4, var_19 + 1, arg4, arg5,
                              arg6);
            }
            if (temp_30 & 2) {
                if ((((u8 *)func_00155280() + temp_17 + temp_16)[0x58] == 7 ||
                     ((u8 *)func_00155280() + temp_17 + temp_16)[0x58] == 8) &&
                    arg4 == 4) {
                    var_7 = var_19;
                } else {
                    var_7 = var_19 + 1;
                }
                func_00157700(arg0 - 1, arg1, 8, var_7, arg4, arg5, arg6);
            }
            if (temp_30 & 4) {
                func_00157700(arg0, arg1 + 1, 1, var_19 + 1, arg4, arg5,
                              arg6);
            }
            if (temp_30 & 8) {
                if ((((u8 *)func_00155280() + temp_17 + temp_16)[0x58] == 7 ||
                     ((u8 *)func_00155280() + temp_17 + temp_16)[0x58] == 8) &&
                    arg4 == 4) {
                } else {
                    var_19 += 1;
                }
                func_00157700(arg0 + 1, arg1, 2, var_19, arg4, arg5, arg6);
            }
        }
    }
}
