/* measured: object 432B, retail window 432B, normalized_diff 16 (ptrorder probe); archived on wave stop */
void func_00135520(u8 *arg0,
                   union {
                       s64 raw;
                       f32 f[2];
                   } arg1,
                   u8 arg2, s32 arg3)
{
    f32 temp_f21;
    f32 temp_f20;
    u16 temp_16;
    u8 temp_17;
    u8 temp_18;
    u8 temp_19;
    void *temp_p;
    temp_17 = D_0064B2E8[0];
    temp_18 = D_0064B2E8[1];
    temp_19 = D_0064B2E8[2];
    temp_f21 = code13Add(arg1.f[1], 26.0f);
    arg1.f[1] = temp_f21;
    temp_16 = (u16)arg3;
    if (temp_16 & 2) {
        func_0034f2e0(*(void **)(arg0 + 0x1538),
                      (temp_f20 = arg1.f[0]), temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x153C);
        temp_f20 = 467.0f + arg1.f[0];
        func_0034f2e0(temp_p,
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        temp_p = *(void **)(arg0 + 0x1540);
        temp_f21 += 130.0f;
        func_0034f2e0(temp_p,
                      arg1.f[0], temp_f21,
                      temp_17, temp_18, temp_19, arg2);
        func_0034f2e0(*(void **)(arg0 + 0x1544),
                      temp_f20, temp_f21,
                      temp_17, temp_18, temp_19, arg2);
    }
    if (temp_16 & 1) {
        arg1.f[0] -= 2.0f;
        arg1.f[1] -= 26.0f;
        func_00134f40(arg0, arg1.raw, 1, arg2);
    }
}
