/* Archived best attempt for func_003ddfd0: object 76 bytes, window 80 bytes, normalized_diff 12; transferred from 003ddf80 with schedule off. */
u32 func_003ddfd0(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;

    arg2 = arg1 * arg2;
    result = (*(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x34))(arg3, arg0, arg2);
    return result / arg1;
}
