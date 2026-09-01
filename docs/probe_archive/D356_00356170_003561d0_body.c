/* func_00356170: object_size=96 window=96 normalized_diff=8 differing_offsets=0x08,0x10. */
/* func_003561d0: object_size=116 window=128 normalized_diff=15 differing_offsets=0x10,0x18,0x40,0x44,0x48,0x4C (call setup; verify residual extends through 0x58). */
/* Declaration finding: the verified func_00365f00 definition signature is
   (s64, s32, s32, s32, s32, f32, f32, f32, f32, f32). Trying that signature
   at this call site worsened func_00356170 to nd 162 and func_003561d0 to nd
   165. The mixed-order declaration retained in code1_0035.c measures better
   (nd 8 and nd 15), so no declaration correction was shipped. */

void func_00356170(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 f0, f32 f1, f32 f2) {
    s64 saved0[1];
    s32 saved1[1];
    s32 saved2;
    s32 var8;
    u8 sel;
    saved1[0] = arg1;
    saved0[0] = arg0;
    saved2 = arg2;
    var8 = arg3;
    sel = ((u8 *)saved1)[3];
    if (sel != 0xFF)
        var8 = 0;
    func_00365f00(f0, f1, f2, 1.0f, *(s64 *)((u8 *)saved0), *(s32 *)((u8 *)saved1), saved1[0], saved2, var8, 1.0f);
}

void func_003561d0(s64 arg0, s32 arg1, s32 arg2, s32 arg3, f32 dummy, f32 f0, f32 f1)
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
    func_00365f00(dummy, scaled, shifted, 1.0f, *(s64 *)((u8 *)&frame.saved0), frame.saved1, frame.saved1, 4, var8, 1.0f);
}
