/* object_size=260 window=256 normalized_diff=200 differing_offsets=2,9,12,14,15,16,17,18,19,20,21,22,23,24,25,26 classification=oversized near-miss; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register-floor,COP2/VU0; plain float-to-integer casts used for trunc.w.s/mfc1 path, not a compiler floor; candidate is 4 bytes larger than retail window */
void func_003f0510(u8 *arg0, f32 *arg1)
{
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f7;

    temp_f7 = 1.0f / arg1[0];
    arg0[0] = 0xff;
    temp_f1 = (f32)(s32)(255.99f * (arg1[2] * temp_f7));
    temp_f2 = (f32)(s32)(255.99f * ((arg1[1] * temp_f7) / 0.5093697f));
    temp_f0 = (f32)(s32)(255.99f * (arg1[4] * temp_f7));
    temp_f1_2 = (f32)(s32)(255.99f * ((arg1[3] * temp_f7) / 0.19420783f));
    if ((s32)temp_f2 < 0xff) {
        arg0[0] = (u8)(s32)temp_f2;
    }
    arg0[1] = 0xff;
    if ((s32)temp_f1 < 0xff) {
        arg0[1] = (u8)(s32)temp_f1;
    }
    arg0[2] = 0xff;
    if ((s32)temp_f1_2 < 0xff) {
        arg0[2] = (u8)(s32)temp_f1_2;
    }
    arg0[3] = 0xff;
    if ((s32)temp_f0 < 0xff) {
        arg0[3] = (u8)(s32)temp_f0;
    }
}
