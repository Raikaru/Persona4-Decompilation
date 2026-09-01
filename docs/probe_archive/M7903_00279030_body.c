u8 *func_00279030(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    u8 *obj;
    u8 *result;
    u8 *entry;
    u8 *slot;

    obj = D_00881808[arg4].unk0;
    if (obj == NULL)
        func_0046d730(D_0063BE10, 0xBDD);
    slot = (u8 *)(*(s32 *)(obj + 4) + (arg5 << 3) + 0x20);
    if (slot == NULL)
        func_0046d730(D_0063BE10, 0xBE0);
    entry = *(u8 **)(slot + 4);
    if (entry == NULL)
        func_0046d730(D_0063BE10, 0xBE3);
    result = (u8 *)func_00279740((s32)entry, 0);
    if (result == NULL)
        func_0046d730(D_0063BE10, 0xBE6);
    result = (u8 *)func_00274570(
        (s32)(16.0f * fparg0),
        (s32)(8.0f * fparg1),
        (u32)arg1 & 0xFF,
        (u32)arg2 & 0xFF,
        0U,
        0xFFU,
        (u32)result,
        0U
    );
    if (arg3 & 1)
        func_00272b00(result, (u32)arg2 & 0xFF);
    func_00272ba0(result, arg0);
    func_00274a20(result, fparg2);
    return result;
}
