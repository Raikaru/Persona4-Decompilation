/* object 988B / window 1056B / differing words (reloc-masked): 247
 * classification: COP1 accumulator-chain floor (adda.s/madd.s and mula.s/madd.s
 * are emitted from 0.0f + x + y*z C chains, but saved f-register colouring and
 * branch/gp-rel immediates do not line up with retail).
 * Differing offsets: prologue (f25/f24 vs f24/f23 parks), dot result f23 vs
 * f21, temp/scale in f21 vs f1, branch bc1f/b vs bc1t/b, gp-rel addend 0 vs
 * -0x7ee8, loop body length.
 * Levers tried: named f-regs (f20/f21/f22/f1), inline products, 0.0f +
 * adda/madd chains, while loop with (i & 0xFFFF) indexing; reverted to
 * INCLUDE_ASM to preserve baseline.
 */
void func_001cacd0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    struct {
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        f32 sp78;
        f32 sp7C;
        f32 sp80;
        f32 sp84;
        u8 sp88[0x10];
        f32 sp98;
        f32 sp9C;
        f32 spA0;
        u8 spA4[0x10];
        f32 spB4;
        f32 spB8;
        f32 spBc;
        u8 spC0[0x10];
        u8 spD0[0x40];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        f32 sp11C;
        f32 sp120;
        f32 sp124;
        f32 sp128;
        f32 sp130;
        f32 sp134;
        f32 sp138;
        u8 pad_13C[8];
        f32 sp140;
        f32 sp144;
        f32 sp148;
        f32 sp14C;
        f32 sp150;
        f32 sp154;
        f32 sp158;
        u8 pad_15C[4];
        f32 sp160;
        f32 sp164;
        f32 sp168;
        u8 pad_16C[4];
    } frame;
    u8 *work;
    u8 *s0;
    u8 *s2;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f0;
    f32 f2;
    f32 f3;
    f32 f1;
    s32 i;
    f32 *base;
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_001bb3d0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3,
                              f32 *arg4, u16 arg5);

    work = *(u8 **)(arg0 + 0xE0);
    s0 = *(u8 **)(work + 0x30);
    s2 = *(u8 **)(*(u8 **)(work + 0x38) + 0x30);
    func_001bd560(&frame.sp60, (f32 *)(arg0 + 0x9C));
    f20 = *(f32 *)(s0 + 0x84) * *(f32 *)(s0 + 0x2C);
    func_00195850(s2, &frame.sp120);
    f3 = 0.0f + f20 +
         fGpffff8110 * (*(f32 *)(s0 + 0x8C) * *(f32 *)(s0 + 0x2C));
    f0 = 0.0f + frame.sp124 +
         fGpffff8110 * (*(f32 *)(s2 + 0x8C) * *(f32 *)(s2 + 0x2C));
    f21 = f3 + f0;
    frame.sp124 = 0.0f;
    frame.sp160 = *(f32 *)(s0 + 0xDC) - frame.sp120;
    frame.sp164 = *(f32 *)(s0 + 0xE0) - 0.0f;
    frame.sp168 = *(f32 *)(s0 + 0xE4) - frame.sp128;
    f20 = func_003e40b0(&frame.sp160, &frame.sp160);
    f1 = 0.5f * f20;
    frame.sp150 = frame.sp160 * f1;
    frame.sp154 = frame.sp164 * f1;
    frame.sp158 = frame.sp168 * f1;
    frame.sp150 = frame.sp150 + frame.sp120;
    frame.sp154 = frame.sp154 + frame.sp124;
    frame.sp158 = frame.sp158 + frame.sp128;
    f21 = 0.5f * f21;
    frame.sp154 = f21;
    frame.sp110 = frame.sp168;
    frame.sp114 = -frame.sp160;
    frame.sp118 = frame.sp60 - frame.sp150;
    frame.sp11C = frame.sp68 - frame.sp158;
    func_003e41e0(&frame.sp110, &frame.sp110);
    func_003e41e0(&frame.sp118, &frame.sp118);
    f22 = 0.0f + frame.sp114 * frame.sp11C + frame.sp110 * frame.sp118;
    if (!(f22 < 0.0f)) {
        f1 = fGpffff8110 * f20;
    } else {
        f1 = 0.5f * f20;
    }
    frame.sp150 = frame.sp160 * f1;
    frame.sp154 = frame.sp164 * f1;
    frame.sp158 = frame.sp168 * f1;
    frame.sp150 = frame.sp150 + frame.sp120;
    frame.sp154 = frame.sp154 + frame.sp124;
    frame.sp158 = frame.sp158 + frame.sp128;
    frame.sp154 = f21;
    *(f32 *)(arg0 + 0x10C) = 0.5f * *(f32 *)(s0 + 0xE8);
    *(f32 *)(arg0 + 0x100) = frame.sp150;
    *(f32 *)(arg0 + 0x104) = frame.sp154;
    *(f32 *)(arg0 + 0x108) = frame.sp158;
    frame.sp130 = frame.sp60 - frame.sp150;
    frame.sp134 = frame.sp64 - frame.sp154;
    frame.sp138 = frame.sp68 - frame.sp158;
    f21 = fparg0 / 3.0f;
    f20 = f21;
    i = 1;
    while ((i & 0xFFFF) < 4) {
        if (!(f22 < 0.0f)) {
            func_003e0870(&frame.spD0, D_0060A0E0, f21, 0);
        } else {
            func_003e0870(&frame.spD0, D_0060A0E0, -f21, 0);
        }
        func_003e4320(&frame.sp140, &frame.sp130, &frame.spD0);
        base = &frame.sp60 + (i & 0xFFFF) * 7;
        base[0] = frame.sp140 + frame.sp150;
        base[1] = frame.sp144 + frame.sp154;
        base[2] = frame.sp148 + frame.sp158;
        func_001bd780(base + 3, base, &frame.sp150, D_0060A0E0);
        f21 = f21 + f20;
        i = (i + 1) & 0xFFFF;
    }
    func_001bb3d0(arg0, &frame.sp60, &frame.sp7C, &frame.sp98, &frame.spB4, 1);
    func_001bbef0(arg0, fparg1);
}
