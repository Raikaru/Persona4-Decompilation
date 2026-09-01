/* Attempted C reconstruction for func_0017c010; not a confirmed MATCH (nd=300+). Archived before restoring INCLUDE_ASM. */
void func_0017c010(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);
    u8 *temp_18;
    u8 *self;
    u8 *work;
    f32 *constant;

    self = arg1;
    temp_18 = *(u8 **)(*(u8 **)(self + 0x224) + 0x38);
    temp_18 = *(u8 **)(temp_18 + 0x44);
    func_0047a2f0(*(u8 **)(self + 0x164));
    work = *(u8 **)(*(u8 **)(self + 0x224) + 0x38);
    if (*(s32 *)work > 0) {
        func_0047a220(*(u8 **)(self + 0x164), work + 0x48);
        base = D_00887300;
        __asm__ volatile("" : : "r"(base));
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](8, 0);
        base[0](7, 2);
        base[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        constant = (f32 *)D_008872F8;
        __asm__ volatile("" : : "r"(constant));
        func_00178c20(D_005F18F0, D_005F18F4, 0.0f, 0.0f, 128.0f, 48.0f, *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x3C803);
        func_00178c20(D_005F18F4, D_005F18F8, 0.0f, 48.0f, 128.0f, 76.0f, *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_00178c20(D_005F18F8, D_005F18FC, 0.0f, 76.0f, 128.0f, 128.0f, *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        base[0](0x14, 2);
        if (iGpffffba48 == 1)
            base[0](0xE, 1);
        func_003e8110(temp_18);
    }
}
