/* object_size=164B window=160B normalized_diff=97; MWCC frameless candidate, aggregate stack spelling exceeded the retail window. */
extern s32 func_003d5000();
extern void func_00415ad0();
extern void func_00415bc0();
extern void func_004165a0();
extern void func_00416bc0();
extern void func_00416cf0();
extern void func_00416df0();
extern void func_00416e10();
extern void func_00417310();
s32 func_00417470(void) {
    u32 sp[12];

    sp[0] = 2;
    sp[2] = 0x18;
    sp[1] = 0x24;
    sp[11] = 0x18;
    sp[3] = (u32)(func_00415ad0);
    sp[4] = (u32)(func_004165a0);
    sp[5] = (u32)(func_00415bc0);
    sp[6] = (u32)(func_00417310);
    sp[7] = (u32)(func_00416e10);
    sp[8] = (u32)(func_00416bc0);
    sp[9] = (u32)(func_00416cf0);
    sp[10] = (u32)(func_00416df0);
    return func_003d5000(sp) != 0;
}
