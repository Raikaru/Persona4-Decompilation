/* measured: object 920B, retail window 896B, normalized_diff 533; first differing offsets 0x0,0x14,0x16,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x22,0x23,0x24,0x26. Retail conversion sites: lhu 70($s2) -> (f32)(u16)temp_2 at both repeated sites; the third site consumes the 8-bit value in $s1 -> (f32)(u8)var_17. Corrected block-scope declarations: func_00222210(u8 *, s8), func_0034c270(s64, u32, s32, f32), func_00354ba0(u8 *), func_00355310(u8 *, u8 *, f32 *, u8 *), func_003553b0(u8 *, f32 *), func_00364680(s32, s32, s32, s32, f32 x7). Ruled out as sole fix: the complete unsigned-cast rewrite at all three sites, callback dummy leading argument, callee ABI declarations above, pointer/address casts, argument staging, guard polarity, local lifetime/overlap, global addressing mode, and measured optimization-level probes. Object exceeded the 896-byte retail window and normalized_diff remained in the hundreds after declarations were corrected, so this candidate is archived per campaign stop condition. */
// FUN_00222D20
void func_00222d20(s32 arg0, u8 *arg1)
{
    typedef struct {
        s32 lo;
        s32 hi;
    } P4Pair;
    u16 temp_4;
    u16 temp_2;
    u8 var_17;
    s32 temp_2_3;
    f32 sp60;
    f32 sp58;
    f32 sp64;
    f32 sp5C;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f1;
    P4Pair pos;
    extern void func_00222210(u8 *arg0, s8 arg1);
    extern void func_0034f1e0(void);
    extern void func_0034c270(s64 arg0, u32 arg1, s32 arg2, f32 arg3);
    extern void func_00354ba0(u8 *arg0);
    extern void func_00355310(u8 *arg0, u8 *arg1, f32 *arg2, u8 *arg3);
    extern void func_003553b0(u8 *arg0, f32 *arg1);
    extern s32 func_00355430(u8 *arg0);
    extern void func_00364680(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                              f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                              f32 arg8, f32 arg9, f32 arg10);
    extern void func_00367210(P4Pair arg0, f32 arg4, s32 arg1, s16 *arg2, s32 arg3);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045aeb0(s32 arg0, void *arg1);
    extern u8 D_00629680[];
    extern f32 fGpffff809c;

    temp_4 = *(u16 *)(arg1 + 0);
    if (temp_4 & 2) {
        if (!(temp_4 & 8)) {
            temp_2 = (u16)(*(u16 *)(arg1 + 0x46) + 1);
            *(u16 *)(arg1 + 0x46) = temp_2;
            if (temp_2 >= 0x36) {
                *(u16 *)(arg1 + 0) = (u16)(*(u16 *)(arg1 + 0) | 8);
            }
            temp_2 = *(u16 *)(arg1 + 0x46);
            var_f12 = (f32)(u16)temp_2;
            temp_f1 = 255.0f * func_00373cb0(var_f12, 0.0f, 5.0f, 1);
            var_17 = (u8)temp_f1;
            if (*(u16 *)(arg1 + 0x46) == 0xE) {
                func_0045aeb0(2, D_00629680);
            }
        } else {
            var_17 = (u8)-1;
        }
        func_0034f1e0();
        pos.lo = 0;
        pos.hi = 0;
        func_0034c270(*(s64 *)&pos, var_17, 0x16, 0.0f);
        func_00222210(arg1, var_17);
        func_00354ba0((u8 *)*(s32 *)(arg1 + 0x4C));
        pos.lo = 0;
        pos.hi = 0;
        temp_2_3 = func_00355430((u8 *)*(s32 *)(arg1 + 0x4C));
        if (temp_2_3 != 0) {
            temp_2 = *(u16 *)(arg1 + 0x46);
            if (temp_2 >= 0x18) {
                var_f12_2 = (f32)(u16)temp_2;
                temp_f20 = func_00373cb0(var_f12_2, 27.0f, 54.0f, 2);
                func_00355310((u8 *)*(s32 *)(arg1 + 0x4C), 0,
                              &sp60, 0);
                func_003553b0((u8 *)*(s32 *)(arg1 + 0x4C), &sp58);
                var_f1 = (f32)(u8)var_17;
                temp_f1_2 = fGpffff809c * var_f1 * (1.0f - temp_f20);
                var_17 = (u8)temp_f1_2;
                func_00364680((s32)var_17 | ~0xFF, temp_2_3, 0, 1, 0,
                              sp60, sp64, sp60, sp64, 256.0f * sp58,
                              512.0f * sp5C);
                func_003f6440(3, 0x717FB);
                func_003f6440(2, 0x44);
            }
        }
        pos.lo = 0;
        pos.hi = 0;
        func_00367210(pos, 0.0f, var_17, (s16 *)(arg1 + 0x58), 0);
    }
}
