void func_00113e30(Vec2f arg0, f32 fparg0, u8 arg1, void *arg2, s32 arg3) {
    f32 farg;
    s32 color;
    s32 index;
    void *temp;

    farg = fparg0;
    temp = func_00243840(*(u16 *)((u8 *)arg2 + 0xA));
    color = (((arg1 & 0xFF) * 0xFF) / 255U) | ~0xFF;
    index = *((s8 *)((s32)&D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2)));
    func_00275020((f32)(s32)arg0.x,
                  (f32)(s32)arg0.y,
                  farg,
                  color,
                  index,
                  1,
                  temp,
                  8,
                  -1);
}
