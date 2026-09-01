/* object_size=200B window=192B normalized_diff=139 differing_offsets=[0,4,6,7,10,11,12,14,15,16,18,20,22,25,28,29] classification=oversized callback/table reconstruction; automatic archive-immediately condition triggered. Corrected block-scope func_003e2800(u8*,s32,s32,s32,s32), D_008873F8(s32,s32,s32) and GP scalar/absolute-array addressing before measurement; object still exceeds window, so no further probe was attempted. */
s32 func_003e2f60(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 *(*D_008873F8[])(s32, s32, s32);
    extern u8 *func_003e2800(u8 *, s32, s32, s32, s32);
    s32 gp;
    u8 *result;

    gp = iGpffffb768;
    result = D_008873F8[0](
        *(s32 *)(D_008872E0 + gp), 0x330404, gp);
    if (func_003e2800(result, 1, arg0, arg1, arg2) == NULL) {
        jtbl_008873FC[0](
            *(u8 **)(D_008872E0 + (s32)iGpffffb768), result);
        result = NULL;
    }
    return (s32)result;
}
