/* Tested candidate for func_0032b770; object 596/608, normalized_diff 16. Restored to INCLUDE_ASM because not MATCH. */
void func_0032b770(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s64 spC8, spC0, spB8;
    s32 i, v1, v2;
    u16 w;
    u8 b;
    u8 *obj;
    f32 f21, f20;
    obj = *(u8 **)(arg0 + 0x38);
    func_002b2970(&spC8, 156.0f, 87.0f);
    func_0031e5b0(arg0, spC8, 0, arg3, 0, 1, 1);
    i = 0;
    v1 = (s16)arg1;
    v2 = (s16)arg2;
    while ((s16)i < v2) {
        func_002b2970(&spC0, 162.0f, 111.0f);
        w = *(u16 *)(func_002e48a0(0, i) + 2);
        b = *(u8 *)(func_002e48a0(0, i) + 4);
        func_0031ac10(arg0, spC0, -1, (s8)i, w, b, (s16)((s16)i * v1), arg3, 0, 0x99);
        i = (s16)(i + 1);
    }
    func_003297f0(arg0, 0, arg3, 417.0f, 220.0f);
    func_002b2970(&spB8, 472.0f, 112.0f);
    func_00324f80(arg0, *(FclVec2 *)&spB8, 0, arg3);
    f21 = (f32)(*(s16 *)(obj + 0x11E) - *(s16 *)(obj + 0x120));
    f20 = *(f32 *)(obj + 0x124);
    f20 = *(f32 *)(func_002b6150(0xAA) + 0x3C) + f20 * f21;
    *(f32 *)(func_002b6150(0xB1) + 0x3C) = f20;
    f20 = 52.0f + *(f32 *)(func_002b6150(0xB1) + 0x3C);
    *(f32 *)(func_002b6150(0xB5) + 0x3C) = f20;
}
