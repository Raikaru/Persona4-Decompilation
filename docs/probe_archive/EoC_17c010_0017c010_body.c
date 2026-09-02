/* Attempted reconstruction for func_0017c010; not a confirmed MATCH (normalized residual: 14 words). */
/* Retail saved registers: $s2=temp_18, $s1=base (D_00887300), $s0=self (arg1); frame size 0x40. */
/* Rules/probes tried: declaration/register ordering, pointer aliases and casts, early return, typed fields, parameter reuse, zero/comma float locals, and scoped schedule/common-subexpression pragmas. */
void func_0017c010(u8 *arg0, u8 *arg1)
{
    extern void func_0047a220(void *arg0, void *arg1);
    extern s32 func_00178c20(void *arg0, void *arg1,
                             f32 farg0, f32 farg1, f32 farg2, f32 farg3,
                             f32 farg4, f32 farg5);
    extern void func_003e8110(void *arg0);
    extern f32 D_008872F8[];
    extern u8 D_005F18F0[];
    extern u8 D_005F18F4[];
    extern u8 D_005F18F8[];
    extern u8 D_005F18FC[];
    void (**base)(s32, s32);
    u8 *temp_18;
    u8 *self;
    f32 *constant;

    self = arg1;
    temp_18 = *(u8 **)(*(u8 **)(*(u8 **)(self + 0x224) + 0x38) + 0x44);
    func_0047a2f0(*(u8 **)(self + 0x164));
    if (*(s32 *)(*(u8 **)(*(u8 **)(self + 0x224) + 0x38)) > 0) {
        func_0047a220(*(u8 **)(self + 0x164),
                      *(u8 **)(*(u8 **)(self + 0x224) + 0x38) + 0x48);
        base = (void (**)(s32, s32))(void *)D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](8, 0);
        base[0](7, 2);
        base[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        constant = (f32 *)(void *)D_008872F8;
        func_00178c20(D_005F18F0, D_005F18F4,
                      0.0f, 0.0f, 128.0f, 48.0f,
                      *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x3C803);
        func_00178c20(D_005F18F4, D_005F18F8,
                      0.0f, 48.0f, 128.0f, 76.0f,
                      *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_00178c20(D_005F18F8, D_005F18FC,
                      0.0f, 76.0f, 128.0f, 128.0f,
                      *constant, 1.0f / *(f32 *)(temp_18 + 0x80));
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
        base[0](0x14, 2);
        if (iGpffffba48 == 1)
            base[0](0xE, 1);
        func_003e8110(temp_18);
    }
}
