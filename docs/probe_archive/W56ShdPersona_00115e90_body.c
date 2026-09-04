/* Measured full verifier: object/window 768/768 bytes, normalized_diff 39.
 * Residual register allocation/scheduling; production uses the assembly fallback. */
#pragma opt_loop_invariants on
void func_00115e90(Vec2f arg0, s32 arg1, s16 *arg2, f32 farg3)
{
    u32 *base;
    f32 y;
    f32 sp78[2];
    s32 sp60[4];
    s32 i;

    y = arg0.y;
    sp60[0] = func_0046a770(D_005E5810);
    sp60[1] = func_0046a770(D_005E5830);
    sp60[2] = func_0046a770(D_005E5850);
    sp60[3] = func_0046a770(D_005E57F0);
    base = (u32 *)D_00887300;
    ((void (**)(u32, u32))base)[0](6, 0);
    ((void (**)(u32, u32))base)[0](7, 2);
    ((void (**)(u32, u32))base)[0](8, 0);
    ((void (**)(u32, u32))base)[0](9, 2);
    ((void (**)(u32, u32))base)[0](0xC, 1);
    ((void (**)(u32, u32))base)[0](0xB, 6);
    ((void (**)(u32, u32))base)[0](0xA, 5);
    ((void (**)(u32, u32))base)[0](2, 4);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    sp78[0] = *(f32 *)&arg0.x;
    sp78[1] = 43.0f + y;
    func_00116190(*(s64 *)sp78, farg3, arg1, (u8 *)&arg2[4], sp60);
    sp78[0] = *(f32 *)&arg0.x - 23.0f;
    sp78[1] = 76.0f + y;
    func_00116610(*(s64 *)sp78, farg3, arg1, (u8 *)&arg2[4], sp60);
    func_001162f0(*(s64 *)sp78, farg3, arg1, (u8 *)&arg2[4], sp60);
    func_001163e0(*(s64 *)sp78, farg3, arg1, (u8 *)&arg2[4], sp60);
    sp78[0] = 305.0f + *(f32 *)&arg0.x;
    sp78[1] = 139.0f + y;
    func_00116820(*(s64 *)sp78, farg3, arg1, (u8 *)&arg2[4], sp60);
    i = 0;
    while (i < 5) {
        sp78[0] = 88.0f + *(f32 *)&arg0.x;
        sp78[1] = 203.0f + y + (f32)(i * 19);
        func_00116d40(*(I64 *)sp78, arg1, *((u8 *)arg2 + i + 0xF), *((u8 *)arg2 + i + 0x14), 0, sp60[0], 0.0f);
        i++;
    }
}

#pragma opt_loop_invariants off
