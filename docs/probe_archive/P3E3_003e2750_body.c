/* object_size=208B window=176B normalized_diff=147 differing_offsets=[4,6,7,8,10,11,12,13,14,15,16,18,19,20,21,22] classification=oversized switch reconstruction; automatic archive-immediately condition triggered. Retail switch/case dispatch, stack error pair and callee declarations were reconstructed; object exceeds the retail window, so no further probe was attempted. */
u8 *func_003e2750(u8 *arg0, s32 arg1, u8 *arg2) {
    extern s32 func_003df590(s32 arg0, ...);
    extern void func_003df4d0(void *arg0);
    u8 *result;
    s32 error[2];

    result = NULL;
    switch (arg1) {
    case 1:
        result = arg0;
        *(s32 *)(arg0 + 0xC) = 0;
        *(s32 *)(arg0 + 0x10) = *(s32 *)(arg2 + 4);
        *(s32 *)(arg0 + 0x14) = *(s32 *)arg2;
        break;
    case 2:
        *(s32 *)(arg0 + 0xC) = 0;
        result = arg0;
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        break;
    case 3:
        *(s32 *)(arg0 + 0xC) = *(s32 *)(arg2 + 4);
        result = arg0;
        *(s32 *)(arg0 + 0x10) = *(s32 *)(arg2 + 4);
        *(s32 *)(arg0 + 0x14) = *(s32 *)arg2;
        break;
    default:
        error[0] = 1;
        error[1] = func_003df590(13);
        func_003df4d0(error);
        break;
    }
    return result;
}
