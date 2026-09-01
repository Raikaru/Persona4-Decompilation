/* object_size=144 window=160 normalized_diff=84 differing_offsets=12,14,15,16,18,20,21,22,23,26,27,28,29,30,31,32; classification=near-miss/prologue scheduling, stack-local placement and callback declaration residual; ruled out: movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, mixed-unit sd/sq floor. */
u8 *func_003ef510(u8 *arg0, s8 *arg1)
{
    extern void (*D_008873B0[])(u8 *arg0, s32 arg1);
    extern u32 (*D_008873D4[])(s8 *arg0);
    extern s32 func_003df590();
    extern void func_003df4d0(s32 *arg0);
    s32 sp3C;
    s32 sp38;

    D_008873B0[0](arg0 + 0x30, 0x20);
    if (D_008873D4[0](arg1) >= 0x20U) {
        sp38 = 1;
        sp3C = func_003df590(
            0x8000001E, arg1, (u8 *)0x20, 0x1F, arg1[0x1F]);
        func_003df4d0(&sp38);
        *(s8 *)(arg0 + 0x4F) = 0;
    }
    return arg0;
}
