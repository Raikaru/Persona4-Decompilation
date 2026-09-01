/* object_size=240 window=240 normalized_diff=MMI/COP2 floor; retail contains pcpyld $v0,$v1,$v0, which compliant C cannot emit. No plain-C probe attempted after known-floor rule. */
s32 func_003a14f0(u8 *arg0, u8 *arg1)
{
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    u8 *temp_16;
    u8 *temp_2;

    func_003f3eb0(0, 4);
    temp_16 = (u8 *)iGpffffb730;
    /* Retail builds the following 128-bit value with pcpyld. */
    sp40 = *(f32 *)(arg0 + 0x18);
    sp44 = *(f32 *)(arg0 + 0x1C);
    sp48 = *(f32 *)(arg0 + 0x20);
    sp4C = *(f32 *)(arg0 + 0x24);
    sp40 = *(f32 *)(arg1 + 0x18);
    sp44 = *(f32 *)(arg1 + 0x1C);
    sp48 = *(f32 *)(arg1 + 0x20);
    sp4C = *(f32 *)(arg1 + 0x24);
    temp_2 = func_003e9700(*(s32 *)(arg1 + 4));
    sp50 = *(f32 *)(temp_2 + 0x20);
    sp54 = *(f32 *)(temp_2 + 0x24);
    sp58 = *(f32 *)(temp_2 + 0x28);
    *(u8 **)(iGpffffb730 + 0x40) = temp_16 + 0x40;
    return 1;
}
