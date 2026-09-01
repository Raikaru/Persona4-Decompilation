// object=336 window=336 normalized_diff=93 differing_offsets=60,64,66,67,68,69,70,71,72,73,74,75,78,79,82,83 classification=exact-size float-load/materialisation scheduling residual; ruled_out=wrong global draw prototype (not measured as best), block-scope old-style draw declaration, no movz/movn, no COP1 accumulator, no standalone MMI, no framed tail-jump; frame=80 bytes with s3=arg0,s2=arg1,s1=arg2,s0=arg2*16
void func_001887f0(u8 *arg0, u8 *arg1, s32 arg2)
{
    extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
    s32 temp_16;

    temp_16 = arg2 * 0x10;
    func_0025ecd0(0x313131, 0xFF, 6, *(s32 *)(arg0 + 0x34), 1, 0, 0, D_00795E60, (f32)(s32)(*(f32 *)arg1 + *(f32 *)((u8 *)D_005F2130 + temp_16)), (f32)(s32)(*(f32 *)(arg1 + 4) + *(f32 *)((u8 *)D_005F2134 + temp_16)), *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
    func_0025ecd0(0xFFFFFF, 0xFF, arg2 + 7, *(s32 *)(arg0 + 0x28), 1, 0, 0, D_00795E60, (f32)(s32)(*(f32 *)arg1 + *(f32 *)((u8 *)D_005F2138 + temp_16)), (f32)(s32)(*(f32 *)(arg1 + 4) + *(f32 *)((u8 *)D_005F213C + temp_16)), *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
}
