/* object_size=236 window=256 normalized_diff=133 differing_offsets=39,42,43,44,52,53,54,55,56,57,58,59,64,65,66,67 classification=undersized near-miss; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; callee signatures corrected at block scope; Frame aggregate context/result reconstructed but compiler object remains 20 bytes short of retail */
s32 func_003edb30(u8 **arg0, s64 arg1)
{
    typedef struct {
        u8 context[0x4010];
        u8 result[0x400];
    } Frame;
    extern s32 func_003f24a0(void *arg0);
    extern void func_003f07d0(void *arg0, u8 *arg1, f32 fparg0);
    extern s32 func_003f17e0(void *arg0, s32 arg1, void *arg2);
    extern void func_003f1ce0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, u8 *arg5);
    extern void *func_003ea2c0(s32 arg0, s32 arg1, s64 arg2);
    extern s32 func_003ea3e0(void *arg0);
    extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
    extern void func_003ea370(u8 *arg0);
    extern void func_003f26c0(void *arg0);
    Frame frame;
    s64 temp_17;
    void *temp_2;

    if (func_003f24a0(&frame.context) == 0) {
        return 0;
    }
    func_003f07d0(&frame.context, *arg0, 1.0f);
    temp_17 = 1LL << arg1;
    func_003f17e0(frame.result, (s32)((temp_17 << 32) >> 32), &frame.context);
    temp_2 = func_003ea2c0(
        *(s32 *)(*arg0 + 4),
        *(s32 *)(*arg0 + 8),
        arg1);
    if (temp_2 != NULL) {
        func_003ea3e0(temp_2);
        func_003f1ce0(
            *(u8 **)((u8 *)temp_2 + 0x14),
            *(s32 *)((u8 *)temp_2 + 0x10),
            *(s32 *)((u8 *)temp_2 + 0xC),
            0,
            &frame.context,
            *arg0);
        func_0043f810(
            *(void **)((u8 *)temp_2 + 0x18),
            frame.result,
            (s32)((temp_17 * 4 << 32) >> 32));
        func_003ea370(*arg0);
        *arg0 = temp_2;
        func_003f26c0(&frame.context);
        return 1;
    }
    return 0;
}
