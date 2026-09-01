// object=344 window=352 normalized_diff=96 differing_offsets=68,72,74,75,76,77,78,79,80,81,82,83,86,87,90,91 classification=undersized by 8 / second-call scheduling residual; ruled_out=explicit f14 locals (same object, nd103), no movz/movn, no COP1 accumulator, no standalone MMI, no framed tail-jump; frame=80 bytes with s3=arg0,s2=arg1,s1=arg2,s0=arg2*24
void func_00188690(u8 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
    s32 temp_16;

    temp_16 = arg2 * 0x18;
    func_0025ecd0(0xFFFF81, 0xFF, 7, *(s32 *)(arg0 + 0x34), 1, 0, 0, D_00795E60, (f32)(s32)(*(f32 *)arg1 + *(f32 *)((u8 *)D_005F20B8 + temp_16)), (f32)(s32)(*(f32 *)(arg1 + 4) + *(f32 *)((u8 *)D_005F20BC + temp_16)), *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
    func_0025ecd0(0xEC7C00, 0xFF, arg2 + 7, *(s32 *)(arg0 + 0x28), 1, 0, 0, D_00795E60, (f32)(s32)(*(f32 *)arg1 + *(f32 *)((u8 *)D_005F20C0 + temp_16)), (f32)(s32)(*(f32 *)(arg1 + 4) + *(f32 *)((u8 *)D_005F20C4 + temp_16)), *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
}
