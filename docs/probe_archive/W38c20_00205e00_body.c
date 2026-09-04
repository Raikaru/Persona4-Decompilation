/* lane W38c20 func_00205e00 archive.
 * best measured: object 488B/window 496B, normalized_diff 2 (fndiff) / 4 (lverify), nd2-ish.
 * Differing offsets: 0x58 (addiu vs daddiu 0x1B), 0x64 (addiu vs daddiu 0xFF).
 * Levers tried: s32/s8/u8/u16/u64 var_16; (u8) casts; (s64) casts; 0x1BLL/0xFFLL;
 *   block-scope extern func_00201650 with u8 arg5-7/s32 arg8; changing func_00201650
 *   parameter types.  Residual: compiler insists on addiu for s32 destination while
 *   retail uses daddiu, likely a source type fact not yet identified.
 * Main follow-up (11 compiles): u8/u16 var_16 gives addiu v0 + andi s0,v0,0xff at the join
 *   (nd 92) regardless of a block-scope u8-parameter prototype for func_00201650; u64 gives
 *   addiu + dsll32; init-then-if changes the frame (0x80 vs 0x70). The daddiu-into-s0-with-no-mask
 *   shape is not reached by any narrow-unsigned local spelling tried.
 */
// FUN_00205E00 candidate
void func_00205e00(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   s32 arg2, s32 arg3, s32 arg4)
{
    extern s32 func_002791f0(f32 fparg0, f32 fparg1, f32 fparg2,
                              s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                              s32 arg4, s32 arg5);
    f32 temp_f21;
    s32 var_16;
    u8 *temp_17;

    temp_17 = (u8 *)func_00452560(*(s32 *)(arg0 + 0x5B0));
    if (arg3 != 0) {
        var_16 = 0x1B;
    } else {
        var_16 = 0xFF;
    }
    temp_f21 = 8.0f + fparg1;
    func_00201650(temp_17, 9, 0x3C,
                  48.0f + fparg0, temp_f21,
                  var_16, var_16, var_16, arg2);
    func_00201650(temp_17, 9, 0x3C,
                  270.0f + fparg0, temp_f21,
                  var_16, var_16, var_16, arg2);
    func_00201650(temp_17, 9, arg1 + 0x3F,
                  71.0f + fparg0, fparg1,
                  var_16, var_16, var_16, arg2);
    if (arg4 != 0) {
        func_00272c60(0x40);
        func_002791f0(
            10.0f + ((2.0f + (42.0f + fparg0)) - 1.0f),
            36.0f + fparg1, 0.0f,
            (arg2 & 0xFF) | ~0xFF, 1, 0, 0,
            *(s32 *)(temp_17 + 0x98), arg1);
        func_00272c80(0x40);
    }
}
