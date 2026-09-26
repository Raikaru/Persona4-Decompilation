#pragma push
#pragma opt_loop_invariants on
// FUN_0036AE90
void func_0036ae90(u8 *arg0, u8 *arg1) {
    extern u8 *func_00457120(void);
    extern u8 *func_003e9700(s32 arg0);
    extern u8 *func_003e0f80(void);
    extern void func_0036abd0(void *arg0, void *arg1);
    extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src, const void *matrix);
    extern void func_003e42a0(void *dst, void *src, void *cam);
    extern void RwV3dNormalize(void *dst, void *src);
    extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void func_003e0f40(void *arg0);
    extern RwV3d D_0064E490;
    extern RwV3d D_0064E4A0;
    extern RwV3d D_0064E4B0;
    extern RwV3d D_0064E4C0;
    extern f32 fGpffff83fc;
    RwV3d stack130;
    RwV3d stack120;
    RwV3d stack110;
    RwV3d stack100;
    RwV3d stackF0;
    RwV3d stackE0;
    RwV3d stackD0;
    RwV3d stackC0;
    RwV3d stackB0;
    u8 *cam;
    u8 *mtx;
    u8 *tmp;
    u8 *rgba;
    f32 dot;
    s32 outer;
    s32 limit;
    s32 even;
    f32 fx;
    f32 dot2;
    f32 pow6;
    f32 dot3;
    f32 clamped;
    f32 combined;
    u8 abyte;
    u8 shade;
    f32 af;
    f32 scaled;

    stack130 = D_0064E490;
    tmp = func_00457120();
    mtx = func_003e9700(*(s32 *)(tmp + 4)) + 0x30;
    stackD0 = D_0064E4A0;
    stackC0 = D_0064E4B0;
    stackB0 = D_0064E4C0;
    cam = func_003e0f80();
    func_0036abd0(cam, arg1);
    func_003e4320(&stackD0, &stackD0, cam);
    stackE0 = *(RwV3d *)(arg0 + 0x994);
    if (*(s32 *)(arg1 + 0x38) != 0) {
        func_003e42a0(&stack100, arg1 + 0x20, func_003e9700(*(s32 *)(arg1 + 0x38)));
    } else {
        stack100 = *(RwV3d *)(arg1 + 0x20);
    }
    dot = stackD0.x * (*(f32 *)mtx - stack100.x) + stackD0.y * (*(f32 *)(mtx + 4) - stack100.y) + stackD0.z * (*(f32 *)(mtx + 8) - stack100.z);
    *(s32 *)arg0 &= ~1;
    if (dot < 0.0f) {
        RwMatrixRotate(cam, &stackC0, 1, 180.0f);
        *(s32 *)arg0 |= 1;
    }
    rgba = arg1 + 0x40;
    stack100.x = 0.0f;
    stack100.y = 0.0f;
    stack100.z = 100.0f;
    func_003e42a0(&stack100, &stack100, cam);
    func_003e4320(&stackB0, &stack130, cam);
    RwV3dNormalize(&stackB0, &stackB0);
    {
        u8 *dst = arg0 + 4;
        s32 inner;
        for (outer = 0; outer < 9; outer++) {
            even = ~outer & 1;
            if (even != 0) {
                limit = 8;
            } else {
                limit = 7;
            }
            for (inner = 0; inner < limit; inner++, dst += 0x24) {
                if (even != 0) {
                    if (inner == 0) {
                        fx = 0.0f;
                    } else if (inner == limit - 1) {
                        fx = 6.0f;
                    } else {
                        fx = 0.5f + (f32)(inner - 1);
                    }
                } else {
                    fx = (f32)inner;
                }
                stack100.x = fx - 3.0f;
                stack100.y = fGpffff83fc * ((f32)outer / 8.0f - 0.5f);
                stack100.z = 0.0f;
                func_003e42a0(&stackF0, &stack100, cam);
                stack110.x = stackF0.x - *(f32 *)mtx;
                stack110.y = stackF0.y - *(f32 *)(mtx + 4);
                stack110.z = stackF0.z - *(f32 *)(mtx + 8);
                RwV3dNormalize(&stack110, &stack110);
                stack120.x = stackF0.x - stackE0.x;
                stack120.y = stackF0.y - stackE0.y;
                stack120.z = stackF0.z - stackE0.z;
                RwV3dNormalize(&stack120, &stack120);
                dot2 = stack110.x * stack130.x + stack110.y * stack130.y + stack110.z * stack130.z;
                {
                    f32 t2 = stack130.x * dot2;
                    f32 t3 = stack130.y * dot2;
                    f32 t1 = stack130.z * dot2;
                    f32 u1 = t1 + (t1 - stack110.z);
                    f32 u2 = t2 + (t2 - stack110.x);
                    f32 u3 = t3 + (t3 - stack110.y);
                    f32 v1 = stack120.x * u2 + stack120.y * u3 + stack120.z * u1;
                    if (v1 <= 0.0f) {
                        pow6 = 0.0f;
                    } else {
                        pow6 = v1 * v1 * v1 * v1 * v1 * v1;
                    }
                }
                stack120.x = stackE0.x - stackF0.x;
                stack120.y = stackE0.y - stackF0.y;
                stack120.z = stackE0.z - stackF0.z;
                RwV3dNormalize(&stack120, &stack120);
                dot3 = stack120.x * stackB0.x + stack120.y * stackB0.y + stack120.z * stackB0.z;
                if (dot3 <= 0.0f) {
                    clamped = 0.0f;
                } else {
                    clamped = dot3;
                }
                combined = pow6 * *(f32 *)(arg0 + 0x9A0) + clamped * *(f32 *)(arg0 + 0x9A4);
                if (!(combined <= 1.0f)) {
                    combined = 1.0f;
                }
                abyte = rgba[3];
                af = (f32)(u32)abyte;
                scaled = af * combined;
                shade = scaled;
                dst[0xC] = shade;
                dst[0xD] = shade;
                dst[0xE] = shade;
                dst[0xF] = shade;
            }
        }
    }
    func_003e0f40(cam);
}
#pragma pop
