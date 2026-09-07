/* MATCH: src/mt_scene/mt_scene.c, configured MWCCPS2 b210 -O2.
 * 824 executable bytes / 832B retail window, 28 fully resolved relocations,
 * eight zero alignment bytes. Both R_MIPS_LITERAL loads use 0x761514;
 * the two-float initializer owns eight bytes at 0x7637e0.
 * Reuse the owner globals. The adjacent getter and its consumer use the
 * consistent full-register u32(float*) predicate contract.
 * Integrated native i386 source passes 294 amplitude/timing combinations
 * at each of O0/O2, plus delayed transitions, RNG, clamps and callbacks.
 * Host floating-point checks are not EE FPU or graphics execution.
 */
// FUN_0026D440
void func_0026d440(void)
{
    extern u32 func_003b7060(void);
    extern f32 fabsf(f32);
    extern f32 D_00881500[4];
    extern s32 D_00881504[], D_00881508[], D_0088150C[];
    f32 delta[2];
    f32 initial[2] = {0.6f, 0.6f};
    s32 i;
    f32 *output;
    f32 step;
    s32 timing;

    if (*(u16 *)&D_00764580 == 0) {
        D_00881500[0] = 0.0f;
        D_00881504[0] = 0;
        D_00881508[0] = 0;
        D_0088150C[0] = 0;
        return;
    }
    if (*(s16 *)&D_00764584 == 0) {
        *(u16 *)&D_00764580 = 0;
        return;
    }
    delta[0] = 0.01f * (f32)(u32)*(u16 *)&D_00764588;
    delta[1] = 0.01f * (f32)(u32)*(u16 *)&D_0076458C;
    for (i = 0; i < 2; i++) {
        f32 d = delta[i];
        if (d != 0.0f) {
            f32 random = (f32)func_003b7060() / 2147483648.0f;
            f32 amplitude = delta[i];
            step = 0.5f * amplitude + 0.5f * (amplitude * random);
            output = D_00881500 + i;
            if (!(fabsf(*output) < delta[i] * initial[i])) {
                if (*output <= 0.0f) *output += step;
                else *output -= step;
            } else {
                *output = 0.0f + *output + 2.0f * (step * ((f32)func_003b7060() / 2147483648.0f - 0.5f));
            }
            if (*output < -d) *output = -d;
            if (!(*output <= d)) *output = d;
        }
    }
    timing = *(s16 *)&D_00764584;
    if (timing > 0) {
        s32 divisor = timing + 5;
        s32 value = *(u16 *)&D_00764588;
        *(u16 *)&D_00764588 = value - (u16)((s32)value / divisor);
        value = *(u16 *)&D_0076458C;
        *(u16 *)&D_0076458C = value - (u16)((s32)value / divisor);
    }
    if (timing > 0) *(s16 *)&D_00764584 = *(s16 *)&D_00764584 - 1;
}
