// func_001cb610 attempted body (did not reach MATCH)
// lane: N
// object: 884B
// window: 848B
// differing words (reloc-masked) with this body: 161 in scratch build
// residuals:
// - pDx/pDz allocated to f3/f2 instead of retail f5/f4
// - C0 (B0 + D0 - B0) chain schedule diverges once product registers differ
// - remaining tail (func_003e40b0, scale, clamp, final calls) unverified once C0 off
// levers tried:
// - struct Frame with explicit f32 fields and u8 pad_to_70[0x14] for 0x70 matrix
// - named inner product 'prod' and named constant 'fConst200' under
//   #pragma opt_propagation off / #pragma opt_common_subs off
// - split-chain C0 written as y then x then z using named pDx/pDy/pDz
// - literal 200.0f instead of fConst200 (worse, constant not CSEd)
// - #pragma push / #pragma pop around #pragma opt_common_subs on for products (worse)

void func_001cb610(u8 *arg0)
{
    u8 *self;
    u8 *unit;
    struct {
        f32 sp30;
        f32 sp34;
        f32 sp38;
        f32 sp3C;
        u8 pad_to_4C[0xC];
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        u8 pad_to_70[0x14];
        f32 sp70[4][4];
        struct {
            f32 x;
            f32 y;
            f32 z;
            u8 pad[4];
        } spB0, spC0, spD0;
    } frame;
    f32 prod;
    f32 fConst200;
    f32 pDx;
    f32 pDy;
    f32 pDz;
    f32 fHalf;
    f32 f30;
    f32 fArg;
    f32 scale1;
    f32 scale2;
    extern f32 fGpffff8188;
    extern u8 D_0060A100[];
    extern void func_001959d0(u8 *arg0, f32 *arg1);

    self = arg0;
    unit = *(u8 **)(*(u8 **)(*(u8 **)(self + 0xE0) + 0x38) + 0x30);
    func_001959d0(unit, &frame.spB0.x);
    prod = (*(f32 *)(unit + 0x8C)) * (*(f32 *)(unit + 0x2C));
    frame.spB0.y = 0.0f + frame.spB0.y + fGpffff8188 * prod;
    frame.spB0.y += 10.0f;
    func_003dcb40((s64 *)&frame.spC0.x, (s64 *)D_0060A100, 1, unit + 0x1C);
    fConst200 = 200.0f;
    pDx = fConst200 * frame.spC0.x;
    frame.spD0.x = pDx;
    pDy = fConst200 * frame.spC0.y;
    frame.spD0.y = pDy;
    pDz = fConst200 * frame.spC0.z;
    frame.spD0.z = pDz;
    frame.spC0.y = (frame.spB0.y + pDy + 10.0f) - frame.spB0.y;
    frame.spC0.x = (frame.spB0.x + pDx) - frame.spB0.x;
    frame.spC0.z = (frame.spB0.z + pDz) - frame.spB0.z;
    func_003e40b0(&frame.spC0.x, &frame.spC0.x);
    fHalf = 0.5f;
    f30 = 30.0f;
    fArg = fHalf * -f30;
    func_003e0870(frame.sp70, D_0060A0E0, fArg, 0);
    func_003e4320(&frame.spD0.x, &frame.spC0.x, frame.sp70);
    scale1 = 115.0f / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(self + 0xB8)));
    frame.spD0.x *= scale1;
    frame.spD0.y *= scale1;
    frame.spD0.z *= scale1;
    frame.sp30 = frame.spB0.x + frame.spD0.x;
    frame.sp34 = frame.spB0.y + frame.spD0.y;
    frame.sp38 = frame.spB0.z + frame.spD0.z;
    func_001bd780(&frame.sp3C, &frame.sp30, &frame.spB0.x, D_0060A0E0);
    func_003e0870(frame.sp70, D_0060A0E0, 15.0f, 0);
    func_003e4320(&frame.spD0.x, &frame.spC0.x, frame.sp70);
    scale2 = 165.0f / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(self + 0xB8)));
    frame.spD0.x *= scale2;
    frame.spD0.y *= scale2;
    frame.spD0.z *= scale2;
    frame.sp4C = frame.spB0.x + frame.spD0.x;
    frame.sp50 = frame.spB0.y + frame.spD0.y;
    frame.sp54 = frame.spB0.z + frame.spD0.z;
    func_001bd780(&frame.sp58, &frame.sp4C, &frame.spB0.x, D_0060A0E0);
    if (frame.sp34 < 25.0f) {
        frame.sp34 = 25.0f;
    }
    if (frame.sp50 < 25.0f) {
        frame.sp50 = 25.0f;
    }
    func_001bcd40(*(u8 **)(self + 0xE0), NULL, NULL, 0.0f, 3);
    func_001bac20(self, &frame.sp30, &frame.sp4C, 1);
    func_001bbef0(self, 2.0f);
}
