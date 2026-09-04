/* lane W38c20 func_00205950 archive.
 * best measured: object 716B/window 720B, normalized_diff 146 (s32-arg1 version).
 * Earlier build/WS02_candidate_00205950.c reports object 468B/window 480B nd132 but
 * uses an s64 arg1 and reorders float parameters; likely an m2c artifact.
 * Differing words (s32 version): mostly saved-register assignment (s1/s4/s0 vs
 * retail) and float move scheduling for f21/f20/fparg1.
 * Levers tried: reordered declarations, u8/u16/s64 casts, split copies,
 * opt_propagation, different arg1 widths for func_0010ace0/func_0010b510.
 * Floor: saved-register allocation and float register colouring are not aligned;
 * would need a systematic local/permutation search.
 */
// FUN_00205950 candidate
void func_00205950(u8 *arg0, s32 arg1, s8 arg2, s32 arg3, f32 fparg0, f32 fparg1)
{
    s32 var_17;
    s32 temp_16;
    s32 temp_lo;
    u8 *temp_18;
    u8 *temp_19;

    temp_19 = func_00452560(*(s32 *)(arg0 + 0x5B0));
    temp_18 = func_0010ace0((s16)arg1);
    if (arg1 == (s16)func_0010b510()) {
        if (arg3 != 0) {
            var_17 = 0x6E;
        } else {
            var_17 = 0x96;
        }
    } else if (arg3 != 0) {
        var_17 = 0x1B;
    } else {
        var_17 = 0xFF;
    }
    func_00201650(temp_19, 0xD, 0x2B, -11.0f + fparg0, 6.0f + fparg1, 0xF3, 0, 0xB, arg2);
    func_00201650(temp_19, 0xD, 0x2A, 33.0f + fparg0, 12.0f + fparg1, var_17, var_17, var_17, arg2);
    temp_16 = func_00109390(temp_18) & 0xFF;
    func_00201650(temp_19, 0xD, (temp_16 % 10) + 0x1D,
                  22.0f + (63.0f + fparg0), 5.0f + fparg1,
                  var_17, var_17, var_17, arg2);
    temp_lo = temp_16 / 10;
    if (temp_lo != 0) {
        func_00201650(temp_19, 0xD, (temp_lo % 10) + 0x1D,
                      63.0f + fparg0, 5.0f + fparg1,
                      var_17, var_17, var_17, arg2);
    }
    func_00272c60(0x40);
    func_00275020(151.0f + fparg0, (4.0f + fparg1) - 1.0f, 50.0f,
                  (arg2 & 0xFF) |
                      (((var_17 & 0xFF) << 8) |
                       (((var_17 & 0xFF) << 0x18) | ((var_17 & 0xFF) << 0x10))),
                  0, 1, (const char *)func_00109220(*(u16 *)(temp_18 + 2)), 0, -1);
    func_00272c80(0x40);
}
