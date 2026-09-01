/*
 * SUPERSEDED six-word floor: a branch-local `u16 result` with `result = 2`
 * and `result = 1`, plus a `u16` return type, reproduces the retail window.
 * Final object 332B / retail window 336B / normalized_diff 0; the retail
 * daddiu at +0x124 is exact. The body below remains the archived near miss.
 *
 * Archived near miss object 332B / retail window 336B / normalized_diff 6.
 * Residual offsets: 0x2c, 0x30, 0x38, 0x3c (switch register allocation),
 * and 0x124 (retail daddiu versus compiler addiu).
 * Working shape: s32 return, s32 arg1, u16 dispatch local, u8** out,
 * inline offset-first helper p4_002091f0_add((u32)index, base).
 * Ruled out: direct switch/default-1; reordered switch cases; equivalent
 * if-chain; s64 result; #pragma opt_propagation; #pragma optimization_level.
 * Source was reverted to INCLUDE_ASM at archive time because this body did
 * not close; the superseding source body now closes the target.
 */
s32 func_00209870(u8 *arg0, s32 arg1, u8 **arg2)
{
    u16 temp_4;
    u16 var_2;
    u8 **out;
    register u8 *base;
    u8 *temp_2;
    u8 *temp_4_2;

    out = (u8 **)arg2;
    base = (u8 *)(u32)arg1;
    temp_4 = func_00202e70() & 0xFFFF;
    switch (temp_4) {
    case 2:
        temp_2 = *(u8 **)(p4_002091f0_add(
            (u32)(*(s16 *)(arg0 + 4) * 4), base) + 0x17C);
        *(u8 **)(base + 0x190) = temp_2;
        if ((func_00107ac0(func_00247cb0(*(s16 *)(temp_2 + 0xA4)) &
                           0xFFFF) & 0xFFFF) >= 0) {
            var_2 = 5;
        } else {
            var_2 = 4;
        }
        func_00202c60(base + 0x110, 4, (s16)var_2,
                      (void *)func_00209d40, (void *)func_00209dc0,
                      (void *)func_00209f90, (void *)func_0020a5c0, base);
        temp_4_2 = base + 0x110;
        *out = temp_4_2;
        func_00202e60(temp_4_2, (void *)func_00209fa0);
        *(s32 *)(base + 4) &= ~4;
        return 3;
    case 1:
        func_0045af60(0, 0, 0, 4);
        return 2;
    default:
        return temp_4 & 0xFFFF;
    }
}
