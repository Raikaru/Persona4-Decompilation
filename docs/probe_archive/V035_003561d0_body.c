/* object_size=116B; window=128B; normalized_diff=15; differing_offsets=0x10,0x18,0x40,0x44,0x48,0x4C,0x50,0x54,0x58. */
/* Best plain-C reconstruction retained for audit; residual is call setup and
   relocation-masked tail. The verified func_00365f00 definition signature
   worsened this mixed-order call, so the local declaration spelling was kept. */
void func_003561d0(s64 arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 dummy, f32 f0, f32 f1)
{
    struct Frame { s64 saved0; s32 saved1; f32 temp; } frame;
    s32 var8;
    u8 sel;
    f32 scaled;
    f32 one;
    f32 shifted;

    frame.saved0 = arg0;
    frame.saved1 = arg1;
    scaled = f0 / iGpffff83d4;
    shifted = iGpffff8544 + f1;
    var8 = arg2;
    frame.temp = *(f32 *)((u8 *)&frame.saved1);
    sel = ((u8 *)&frame.temp)[3];
    if (sel != 0xFF) {
        var8 = 0;
    }
    one = 1.0f;
    func_00365f00(dummy, scaled, shifted, one,
                  *(s64 *)((u8 *)&frame.saved0), frame.saved1,
                  frame.saved1, 4, var8, one);
}
