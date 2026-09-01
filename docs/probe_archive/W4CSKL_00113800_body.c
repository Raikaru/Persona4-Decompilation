void func_00113800(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4)
{
    f32 scale;
    s32 color;
    s8 index;
    void *temp;

    scale = arg4;

    temp = func_00243840(*(u16 *)((u8 *)arg2 + 0xA));
    color = -0x100 | (((arg1 & 0xFF) * 0xFF) / 255U);
    index = *(s8 *)((s32)D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2));
    func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, index, 1, temp, 0, 0);
}
