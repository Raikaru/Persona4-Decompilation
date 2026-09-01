/* object 344B/window 336B/normalized_diff 196; differing offsets 16-20,22,25-31,44-47,...; classification OVERSIZED; no movz/movn, COP1 accumulator, standalone MMI, framed tail jump, or custom COP1 opcode observed. Candidate used signature func_003deea0(s32,u32 *,u32 *,u32 *,u32 *) verified from dF3C0 caller and an aggregate stack frame, but aggregate-addressed fields induced a larger body/frame; archive and restore immediately. */
s32 func_003deea0(s32 arg0, u32 *arg1, u32 *arg2, u32 *arg3, u32 *arg4) {
    extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003ded20(u32 *arg0, u32 *arg1, u32 *arg2);
    extern s32 func_003df590(s32 arg0);
    extern void func_003df4d0(void *arg0);
    struct { u32 first, second, packed, low; s32 result; u32 pad; u32 error; s32 error_result; u32 input[3]; } frame;
    if (func_003e2910((u8 *)arg0, frame.input, 0xC) == 0xC) {
        frame.first = frame.input[0]; frame.second = frame.input[1];
        if ((frame.input[2] & 0xFFFF0000) == 0) { frame.packed = frame.input[2] << 8; frame.low = 0; }
        else { frame.low = frame.input[2] & 0xFFFF; frame.packed = (((frame.input[2] >> 0xE) & 0x3FF00) + 0x30000) | ((frame.input[2] >> 0x10) & 0x3F); }
        frame.result = func_003ded20(&frame.first, &frame.second, &frame.packed);
        if (arg1 != NULL) *arg1 = frame.first;
        if (arg2 != NULL) *arg2 = frame.second;
        if (arg4 != NULL) *arg4 = frame.low;
        if (arg3 != NULL) *arg3 = frame.packed;
        return 1;
    }
    frame.error = 1; frame.error_result = func_003df590(0x8000001A); func_003df4d0(&frame.error); return 0;
}
