/* Lane P3DE_0021: func_003ddf80 under -O2,p. Tried: arg2 = arg1*arg2 with schedule on and all call arguments cast to s32. Residual: mult instruction scheduled into the jalr delay slot; object 68 vs window 80. */
#pragma push
#pragma schedule on
u32 func_003ddf80(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;
    arg2 = arg1 * arg2;
    result = (*(u32 (**)(s32, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x30))((s32)arg3, (s32)arg0, arg2);
    return result / arg1;
}
#pragma pop