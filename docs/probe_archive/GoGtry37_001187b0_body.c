/* func_001187b0 best candidate, GoGtry37; not a final reconstruction.
 * Retail saved registers: s1 = arg2, s0 = arg0->0x2c0; f23 = fparg0,
 * f22 = arg3 high half, f21 = low-half sum, f20 = high-half sum.
 * Retail frame: 0x60; s64 homes at sp+0x50 and sp+0x58.
 * Tried: s64 arg2 ABI, opt_propagation off, opt_common_subs off, canonical
 * renderer prototypes, unsigned renderer byte parameters, direct conversion
 * expressions, source computation reorder, schedule/common-sub probes.
 * Residual: 616-byte candidate vs 624-byte retail window, first x conversion
 * reload and remaining call/FP setup layout differences.
 */
#pragma push
/* measured: opt_propagation off preserves the independent high-half temporary. */
#pragma opt_propagation off
/* measured: opt_common_subs off keeps repeated y conversions in each call block. */
#pragma opt_common_subs off
void func_001187b0(u8 *arg0, s64 arg1, s64 arg2, s64 arg3, f32 fparg0)
{
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f12;
    s32 temp_16;

    temp_f2 = ((f32 *)&arg1)[1];
    temp_f22 = ((f32 *)&arg3)[1];
    temp_16 = *(s32 *)(arg0 + 0x2C0);
    temp_f21 = ((f32 *)&arg1)[0] + ((f32 *)&arg3)[0];
    temp_f20 = temp_f2 + temp_f22;
    {
        void func_0034f4a0(s32, s32, f32, f32, f32, u8, u8, u8, s64, s64,
                           s32, f32, s16, s16);

        func_0034f4a0(*(s32 *)(arg0 + 0x2C4), 0x1D, temp_f21, temp_f20, 0.0f,
                      0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0,
                      (s16)(((f32 *)&arg3)[0] - temp_f21),
                      (s16)(temp_f22 - temp_f20));
    }
    temp_f12 = 207.0f + temp_f21;
    {
        void func_0034f4a0(s32, s32, f32, f32, f32, u8, u8, u8, s64, s64,
                           s32, f32, s16, s16);

        func_0034f4a0(temp_16, 0xB2, temp_f12, temp_f20, 0.0f,
                      0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0,
                      (s16)(((f32 *)&arg3)[0] - temp_f12),
                      (s16)(temp_f22 - temp_f20));
    }
    temp_f12 = 300.0f + temp_f21;
    {
        void func_0034f4a0(s32, s32, f32, f32, f32, u8, u8, u8, s64, s64,
                           s32, f32, s16, s16);

        func_0034f4a0(temp_16, 0xB3, temp_f12, temp_f20, 0.0f,
                      0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0,
                      (s16)(((f32 *)&arg3)[0] - temp_f12),
                      (s16)(temp_f22 - temp_f20));
    }
    temp_f12 = 314.0f + temp_f21;
    {
        void func_0034f4a0(s32, s32, f32, f32, f32, u8, u8, u8, s64, s64,
                           s32, f32, s16, s16);

        func_0034f4a0(temp_16, 0xB3, temp_f12, temp_f20, 0.0f,
                      0xBD, 0x29, 0, arg2, 0x1000, 0x1000, fparg0,
                      (s16)(((f32 *)&arg3)[0] - temp_f12),
                      (s16)(temp_f22 - temp_f20));
    }
}
#pragma pop
