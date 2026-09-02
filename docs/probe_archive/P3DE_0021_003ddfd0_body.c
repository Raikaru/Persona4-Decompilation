/* Lane P3DE_0021: func_003ddfd0 under -O2,p. Tried: separate arg0_copy / arg1_copy / product locals with schedule on. Residual: mult instruction scheduled into the jalr delay slot; object 68 vs window 80. */
#pragma push
#pragma schedule on
u32 func_003ddfd0(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;
    s32 arg0_copy;
    u32 arg1_copy;
    s32 product;
    arg0_copy = arg0;
    arg1_copy = arg1;
    product = arg1_copy * arg2;
    result = (*(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x34))(arg3, arg0_copy, product);
    return result / arg1_copy;
}
#pragma pop