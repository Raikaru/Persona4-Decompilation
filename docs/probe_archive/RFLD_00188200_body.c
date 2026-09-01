// object=288 window=288 normalized_diff=168 differing_offsets=25,26,27,29,30,31,34,35,36,37,39,40,42,43,44,45 classification=exact-size scheduling/materialisation residual; ruled_out=wrong global draw prototype (object 352/288 nd267), block-scope old-style draw declaration (object 416/288 nd333), no movz/movn, no COP1 accumulator, no standalone MMI, no framed tail-jump; frame=48 bytes with s1/s0 and 2 incoming pointers
void func_00188200(u8 *arg0, u8 *arg1)
{
    extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;

    temp_f1 = -32.0f;
    temp_f0 = *(f32 *)arg1;
    temp_f2 = temp_f1 + temp_f0;
    temp_f1 = *(f32 *)(arg1 + 4);
    temp_f0 = -28.0f;
    temp_f1 = temp_f0 + temp_f1;
    func_0025ecd0(-1, 0xFF, 0, *(s32 *)(arg0 + 0x24), 1, 0, 0, D_00795E60, (f32)(s32)temp_f2, (f32)(s32)temp_f1, *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
    temp_f1 = -32.0f;
    temp_f0 = *(f32 *)arg1;
    temp_f2 = temp_f1 + temp_f0;
    temp_f1 = *(f32 *)(arg1 + 4);
    temp_f0 = -28.0f;
    temp_f1 = temp_f0 + temp_f1;
    func_0025ecd0(-1, 0xFF, 1, *(s32 *)(arg0 + 0x24), 1, 0, 0, D_00795E60, (f32)(s32)temp_f2, (f32)(s32)temp_f1, *(f32 *)(arg1 + 8), 0.0f, 1.0f, 1.0f);
}
