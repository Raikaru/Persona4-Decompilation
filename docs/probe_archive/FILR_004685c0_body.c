/* object_size=716, window=736, normalized_diff=240; differing offsets: 0x196 onward (79 reloc-masked differing words; first offsets 0x196-0x19a, 0x19e-0x1aa). Levers ruled out: corrected block-scope callee declarations func_0045d6e0(void*,void*,s32,f32), func_00450dd0(s64,s32,s64,f32), func_00450e80(s32,s64,s32,s32); verified retail lw/lwc1/lb widths; tried aggregate stack values and explicit loop forms. Candidate remains undersized and hundreds of normalized residual, so archived per lane stop rule. */
// FUN_004685c0
void func_004685c0(u8 *arg0)
{
    extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 farg0);
    extern void func_00450dd0(s64 arg0, s32 arg1, s64 arg2, f32 farg0);
    extern void func_00450e80(s32 arg0, s64 arg1, s32 arg2, s32 arg3);
    struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } vals;
    union {
        F2 f;
        s64 x;
    } pos;
    u8 color[4];
    s32 var_16;
    color[3] = 0x80;
    color[2] = 0;
    color[0] = 0;
    color[1] = 0;
    vals.x = (s32)*(f32 *)(arg0 + 0x28);
    vals.y = (s32)(*(f32 *)(arg0 + 0x2C) - 12.0f);
    vals.w = 0xF0;
    vals.h = 0xC;
    func_0045d6e0(color, &vals, 1, 0.0f);
    color[3] = 0x80;
    color[2] = 0;
    color[0] = 0;
    color[1] = 0x46;
    vals.x = (s32)*(f32 *)(arg0 + 0x28);
    vals.y = (s32)*(f32 *)(arg0 + 0x2C);
    vals.w = 0x78;
    vals.h = 0x30;
    func_0045d6e0(color, &vals, 1, 0.0f);
    color[3] = 0x80;
    color[2] = 0x50;
    color[0] = 0x50;
    color[1] = 0x50;
    vals.x = (s32)(12.0f * (f32)*(s32 *)(arg0 + 4) + *(f32 *)(arg0 + 0x28));
    vals.y = (s32)(12.0f * (f32)*(s32 *)(arg0 + 8) + *(f32 *)(arg0 + 0x2C));
    vals.w = 0xC;
    vals.h = 0xC;
    func_0045d6e0(color, &vals, 1, 0.0f);

    pos.f.a = *(f32 *)(arg0 + 0x28);
    pos.f.b = *(f32 *)(arg0 + 0x2C);
    var_16 = 0;
    for (;;) {
        func_00450dd0(pos.x, (s32)(u32)&iGpffffb01c,
                      (s64)D_00712AA0[var_16], 0.0f);
        pos.f.b += 12.0f;
        var_16 += 1;
        if (var_16 >= 4) {
            break;
        }
    }

    pos.f.a = *(f32 *)(arg0 + 0x28);
    pos.f.b = *(f32 *)(arg0 + 0x2C) - 12.0f;
    func_00450dd0(pos.x, (s32)(u32)&iGpffffb01c, (s64)(arg0 + 0x10), 0.0f);

    pos.f.a = 12.0f * (f32)*(s32 *)(arg0 + 4) + *(f32 *)(arg0 + 0x28);
    pos.f.b = 12.0f * (f32)*(s32 *)(arg0 + 8) + *(f32 *)(arg0 + 0x2C);
    color[3] = 0x80;
    color[2] = 0;
    color[0] = 0xFF;
    color[1] = 0;
    func_00450e80(*(s32 *)(void *)color, pos.x,
                  (s32)(u32)&iGpffffb01c + 0x14,
                  *(s8 *)(D_00712AA0[*(s32 *)(arg0 + 8)] +
                          *(s32 *)(arg0 + 4)));
}
