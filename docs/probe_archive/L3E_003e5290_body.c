/* Closest compliant plain-C probe for func_003e5290; not an exact match. */
u8 *func_003e5290(u8 *arg0, u8 *arg1) {
    s32 offset;
    struct {
        f32 value0;
        f32 value1;
        f32 value2;
        f32 value3;
        f32 value4;
        f32 value5;
        f32 value6;
        s32 value7;
    } frame;

    offset = 0x2C;
    if (func_003deff0((s32)arg1, 5,
                     func_003e3370((u8 *)D_0070B710, (s32)arg0) + 0xC + offset,
                     0x37002, 0x37) == 0) {
        return NULL;
    }
    if (func_003deff0((s32)arg1, 1, 0x20, 0x37002, 0x37) == 0) {
        return NULL;
    }
    frame.value0 = *(f32 *)(arg0 + 0x68);
    frame.value7 = *(s32 *)(arg0 + 0x14);
    frame.value1 = *(f32 *)(arg0 + 0x6C);
    frame.value2 = *(f32 *)(arg0 + 0x78);
    frame.value3 = *(f32 *)(arg0 + 0x7C);
    frame.value4 = *(f32 *)(arg0 + 0x80);
    frame.value5 = *(f32 *)(arg0 + 0x84);
    frame.value6 = *(f32 *)(arg0 + 0x88);
    if (func_003e2ab0(arg1, (u8 *)&frame, 0x20) == 0) {
        return NULL;
    }
    return (func_003e33f0((u8 *)D_0070B710, (s32)arg1,
                          (u8 *(*)(u8 *, u8 *))arg0) == 0) ? NULL : arg0;
}
