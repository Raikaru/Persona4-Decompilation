/* object_size=256 window=240 normalized_diff=154 differing_offsets=16,17,18,19,20,22,25,26,28,29,30,31,32,34,36,37 classification=object-over-window/callee-and-register-declarations; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=unknown */
// FUN_003CBCF0
u8 *func_003cbcf0(u8 *arg0, u8 *arg1) {
    extern s32 iGpffffb710;
    extern void func_003bff30(u8 *arg0, s32 (*arg1)(u8 *, u8 *), u8 *arg2);
    extern void func_003bffc0(u8 *arg0, s32 (*arg1)(u8 *, u8 *), u8 *arg2);
    s32 temp_17;
    s32 temp_8;
    u8 *temp_16;
    u8 *temp_3;
    u8 *temp_7;

    temp_8 = iGpffffb710;
    temp_3 = arg1 + 0x20;
    temp_17 = *(s32 *)(arg1 + 4);
    temp_7 = *(u8 **)(arg0 + 0x2C);
    temp_16 = arg1 + temp_8;
    *(u8 **)(arg1 + 0x20) = temp_7;
    *(u8 **)(arg1 + 0x24) = arg0 + 0x2C;
    *(u8 **)(temp_7 + 4) = temp_3;
    *(u8 **)(arg0 + 0x2C) = temp_3;
    *(s32 *)(arg0 + 0x24) += 1;
    *(u8 **)(temp_16 + 0) = arg0;
    func_003bff30(arg1, func_003cb670, arg0);
    func_003c0050(arg1, func_003cb6a0, arg0);
    func_003bffc0(arg1, func_003cb6d0, arg0);
    if (temp_17 != 0) {
        func_003e03e0((u8 *)(temp_17 + 0x10), NULL);
        func_003e9680((u8 *)temp_17);
    }
    *(s32 *)(temp_16 + 4) =
        *(s32 *)(D_008872E0 + (s32)iGpffffb718 + 8);
    return arg0;
}
