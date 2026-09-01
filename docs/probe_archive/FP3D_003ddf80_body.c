/* Archived best attempt for func_003ddf80: object 76 bytes, window 80 bytes, normalized_diff 12; schedule off. */
u32 func_003ddf80(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;

    arg2 = arg1 * arg2;
    result = (*(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x30))(arg3, (s32)arg0, arg2);
    return result / arg1;
}
