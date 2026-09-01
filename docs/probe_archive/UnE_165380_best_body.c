/*
 * UnE_165380_v25 best probe for func_00165380.
 * object/window: 648B / 752B; residual: 144 words (reloc-masked).
 * Differing offsets: body diverges from 0x18 (saved-register coloring and
 * loop-head address formation) through 0x284; the retail-only tail is
 * 0x288-0x2ec. Key structural blocks are the repeated slot rematerialization
 * around 0x24-0x2c, 0x90-0x1c0, and the copy/tail transition near 0x1f8.
 * Ruled out: for/while forms, declaration-order permutations, direct versus
 * named pointer expressions, split base/mode-pointer lifetimes, scalar versus
 * f32[3] stack forms, integer-address casts, and opt_common_subs off
 * (measured 756B/752B, 154 words); no prototype or caller changes.
 * Narrow-unsigned rule: mode is u8 and the daddiu 3 materialization matched
 * retail; no directional type change was required.
 */
void func_00165380(void)
{
    s32 i;
    s32 n;
    u8 mode;
    u16 id;
    u8 *f50;
    u8 *f1ca;
    u8 *f54;
    u8 *dst;
    u8 *src;
    f32 vec[3];
    f32 temp_f0;

    for (i = 0; i < 0xF; i++) {
        f54 = D_007E8C00 + i * 0x750;
        if (*(s32 *)(f54 + 0x48) != 0) {
            mode = 0;
            *(s32 *)(f54 + 0x40) &= ~2;
            f1ca = f54 + 0x1CA;
            if (*(u8 *)f1ca == 1) {
                mode = 3;
            }
            f54 = D_007E8C00 + i * 0x750;
            f50 = f54 + 0x50;
            id = (u16)func_00145540((u16)(i + 0x64), mode, *(u8 **)f50);
            *(u8 **)(f54 + 0x54) = func_00145270(id);
            func_0047aa30(*(u8 **)f50, D_005DC920);
            if (*(u8 *)f1ca == 1) {
                func_0017b9a0(
                    *(s32 *)(*(u8 **)(f54 + 0x54) + 0x224),
                    *(f32 *)(D_005F1340 + *(u8 *)(f54 + 0x1CB) * 4));
            }
            f54 = D_007E8C00 + i * 0x750;
            f1ca = f54 + 0x1CA;
            f50 = f54 + 0x50;
            func_0047a1e0(
                *(u8 **)f50,
                D_005F12E0 + *(u8 *)f1ca * 0x30 + *(u8 *)(f1ca + 1) * 0xC,
                2);
            dst = func_0047a2f0(*(s32 *)f50);
            src = f54;
            n = 8;
            do {
                u32 w0 = *(u32 *)src;
                u32 w1 = *(u32 *)(src + 4);
                src += 8;
                n--;
                *(u32 *)dst = w0;
                *(u32 *)(dst + 4) = w1;
                dst += 8;
            } while (n > 0);
            func_003e05d0(func_0047a2f0(*(s32 *)f50));
            func_0014b0c0(*(u16 *)(*(u8 **)(f54 + 0x54)), 1);
            func_00168730(*(s32 *)(*(u8 **)(f54 + 0x54) + 0x220), 0x40000000);
            func_00168c00(*(s32 *)(*(u8 **)(f54 + 0x54) + 0x220));
            func_00168780(*(s32 *)(*(u8 **)(f54 + 0x54) + 0x220), 35.0f);
            *(s32 *)(*(u8 **)(f54 + 0x54) + 0x228) = func_00478750(iGpffffb274);
            temp_f0 = func_00168770(*(s32 *)(*(u8 **)(f54 + 0x54) + 0x220));
            vec[2] = temp_f0;
            vec[1] = temp_f0;
            vec[0] = temp_f0;
            func_0047a1e0(*(u8 **)(f54 + 0x54) + 0x228, vec, 2);
            func_00478e70(*(u8 **)(f54 + 0x54) + 0x228);
            f1ca = f54 + 0x1CA;
            *(s32 *)(f54 + 0x1B0) = func_00182220(0, f54, *(u8 *)f1ca);
            if (*(s32 *)(f54 + 0x1B8) == 0) {
                *(s32 *)(f54 + 0x1B8) = func_00167420(0, D_007E8C00 + i * 0x750);
            }
        }
    }
}
