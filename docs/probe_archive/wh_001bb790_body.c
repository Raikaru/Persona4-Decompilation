extern f32 D_00881430;
extern f32 D_00881434;
extern f32 D_00881438;
void func_001bb790(u8 *arg0, f32 *arg1, f32 fparg0)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 temp_f5;
    u16 index;
    s32 i;
    u8 *p;

    f3 = 1.0f - fparg0;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = fparg0 * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = fparg0 * fparg0;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = fparg0 * f1;
    index = *(u16 *)(arg0 + 0x74);
    arg1[0] = D_00881430;
    arg1[1] = D_00881434;
    arg1[2] = D_00881438;
    i = 0;
    while ((i & 0xFFFF) < 4) {
        temp_f5 = weights[i & 0xFFFF];
        p = (u8 *)((index & 0xFFFF) * 0x1C) + (u32)arg0;
        arg1[0] += *(f32 *)(p + 4) * temp_f5;
        arg1[1] += *(f32 *)(p + 8) * temp_f5;
        arg1[2] += *(f32 *)(p + 0xC) * temp_f5;
        index = (u16)((index + 1) & 0xFFFF);
        if ((s32)index >= 4) {
            index = 0;
        }
        i = (i + 1) & 0xFFFF;
    }
}
