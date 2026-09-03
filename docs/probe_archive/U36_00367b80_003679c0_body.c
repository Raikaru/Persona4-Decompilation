/* lane U36 drafts (2026-09-03, lane killed): func_00367b80 372/384 nd236; func_003679c0 452/448 nd276. Unfinished. */
void func_00367b80(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    f32 y;
    s32 tex0;
    s32 color;
    u8 value;
    extern int func_00274ed0(f32 x, f32 y, f32 scale, int color, int chr, int id,
                             const char *str, int flags);

    color = (arg1 & 0xFF) | ~0xFF;
    tex0 = func_0046a770(D_005E5810);
    if (tex0 == 0) {
        func_0046d730(D_0064E460, 0x174);
    }
    if (func_0046a770(D_005E5830) == 0) {
        func_0046d730(D_0064E460, 0x176);
    }
    y = *((f32 *)&arg0 + 1);
    func_00274ed0((f32)(s32)(*(f32 *)&arg0), (f32)(s32)y, 0.0f,
                  color, 6, 1, (const char *)*(s32 *)(arg2 + 0x14), 0);
    value = *(u8 *)(arg2 + 0x18);
    if (((s32)value <= 0) || ((s32)value >= 0x20)) {
        func_0046d730(D_0064E460, 0x186);
    }
    func_0046d4c0(0, tex0, (((value & 0xFF) - 1) & 0xFF) + 0x21,
                  *(f32 *)&arg0, 30.0f + y,
                  (u8)(0xFF - (arg1 & 0xFF)), 0xEC, 0x7C, 0, fparg0, 0);
}
void func_003679c0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2)
{
    f32 y;
    s32 tex0;
    s32 tex1;
    f32 xbase;
    s32 value;
    s32 count;

    tex0 = func_0046a770(D_005E5810);
    if (tex0 == 0) {
        func_0046d730(D_0064E460, 0x13D);
    }
    tex1 = func_0046a770(D_005E5830);
    if (tex1 == 0) {
        func_0046d730(D_0064E460, 0x13F);
    }
    y = *((f32 *)&arg0 + 1);
    arg1 = 0xFF - (arg1 & 0xFF);
    func_0046d4c0(0, tex0, 0x39, *(f32 *)&arg0, y,
                  arg1 & 0xFF, 0xFB, 0xA2, 0, fparg0, 0);
    xbase = *(f32 *)&arg0 + 130.0f;
    y += 4.0f;
    value = *(s32 *)(arg2 + 0x10);
    count = value;
    while (count >= 10) {
        xbase += 16.0f;
        count /= 10;
    }
    do {
        func_0046d4c0(0, tex1, (value % 10) + 9, xbase, y,
                      arg1 & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
        value /= 10;
        xbase -= 16.0f;
    } while (value > 0);
}
