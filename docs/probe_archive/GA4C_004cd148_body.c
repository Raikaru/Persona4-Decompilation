/* measured without volatile: object=36 window=40 normalized_diff=6; scoped verify build/GA4C_code1_004c_novolatile.json */
void func_004cd148(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *base0;
    s32 *base1;

    base0 = (s32 *)D_00922E20_abs;
    base1 = (s32 *)D_00922E28_abs;
    base0[1] = arg1;
    base0[0] = arg0;
    base1[1] = arg3;
    base1[0] = arg2;
}
