/* object 460B, window 480B, normalized_diff 80, differing offsets 0x90 onward, classification raw decompiler control-flow/register residual; initial reconstruction matched prologue and floating setup through 0xEE2DC; rounding guards, stack outputs, callee signature, and global-list tail remain unresolved. */
void func_001ee250(u8 *arg0, u8 *arg1) {
    struct {
        f32 values[3];
        s16 y;
        s16 x;
    } frame;
    f32 scale;
    f32 base;
    f32 x_float;
    f32 y_float;
    s32 x_value;
    s32 y_value;
    s64 x_bucket;
    s64 y_bucket;
    s16 *x_out;
    s16 *y_out;
    u8 *head;
    func_00195850(arg0, frame.values);
    scale = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    base = (f32)(s32)0x6D6;
    x_float = base + frame.values[0];
    y_float = base + frame.values[2];
    x_value = (s32)x_float;
    y_value = (s32)y_float;
    x_bucket = (s16)(x_value / 25);
    y_bucket = (s16)(y_value / 25);
    if (x_value % 25 >= 13)
        x_bucket++;
    if (y_value % 25 >= 13)
        y_bucket++;
    x_out = &frame.x;
    if (x_out != NULL)
        *x_out = (s16)x_bucket;
    y_out = &frame.y;
    if (y_out != NULL)
        *y_out = (s16)y_bucket;
    func_001ec790(arg0, frame.x, frame.y, scale);
    if (arg1 != NULL) {
        *(f32 *)(arg1 + 0) = (f32)(frame.x * 25 - 0x6D6);
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)(frame.y * 25 - 0x6D6);
    }
    *(s16 *)(arg0 + 0x508) = frame.x;
    *(s16 *)(arg0 + 0x50A) = frame.y;
    *(f32 *)(arg0 + 0x50C) = scale;
    *(s32 *)(arg0 + 0x9C) |= 4;
    *(s32 *)(arg0 + 0x9D0) = 0;
    head = *(u8 **)(iGpffffb3ac + 0x318);
    if (head != NULL) {
        *(u8 **)(head + 0x4C8) = arg0 + 0x508;
        *(u8 **)(arg0 + 0x9D4) = *(u8 **)(iGpffffb3ac + 0x318);
    } else {
        *(u8 **)(arg0 + 0x9D4) = NULL;
    }
    *(u8 **)(iGpffffb3ac + 0x318) = arg0 + 0x508;
}
