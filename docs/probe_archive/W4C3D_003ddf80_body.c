#pragma schedule off
u32 func_003ddf80(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 result;
    u32 (*fn)(u8 *, s32, s32);

    fn = *(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x30);
    arg2 = arg1 * arg2;
    result = fn(arg3, (s32)arg0, arg2);
    return result / arg1;
}
#pragma schedule on
