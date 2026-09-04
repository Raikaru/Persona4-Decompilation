/* Faithful candidate: object 860B / retail window 848B / normalized diff 206.
 * The source reproduces the 0xf0-byte local layout, copy loop, vtable-base
 * reload shape, unsigned alpha shift, and both render-call argument layouts.
 * The irreducible first divergence is same-TU callee knowledge at the call to
 * func_00252230: retail preserves ctx in $v0 and the special flag in $t0
 * across that leaf call, while the reconstructed extern declaration forces
 * b210 to preserve both in $s registers (four saved GPRs, 0x100-byte frame).
 * Supplying a same-unit C leaf body did not change b210's call-clobber model.
 * Tried the generated return-value interpretation (820B / 848B / nd197), but
 * it is semantically false: retail later reads ctx+0x10, not a callee result.
 * Also tried separate and aggregate stack locals, direct/table function
 * pointers, signed/unsigned alpha shifts, declaration order, and exact
 * load/load/advance/decrement/store/store/advance copy ordering. */
s32 func_00252710(s32 arg0, u8 *work, u8 *ctx)
{
    Sp120 sp120;
    u8 mat[0x40];
    u8 uv[0x20];
    u8 *src;
    u8 *dst;
    s32 count;
    s32 temp_3;
    s32 temp_2;
    s32 rank;
    s32 done;
    s32 special;
    s64 tex;

    done = 0;
    special = 0;
    if (*(s32 *)(ctx + 8) == 0xA) {
        special = 1;
    }
    if (!(*(s32 *)(work + 0) & 2)) {
        *(s32 *)(work + 4) += 1;
    }
    rank = *(s32 *)(work + 4);
    if (rank >= 0x3C) {
        done = 1;
    }
    if (rank >= 0x1F) {
        func_00252230(&sp120, (Sp120 *)(work + 0x30), (Sp120 *)(work + 0x54),
                      (f32)(rank - 0x1E) / 30.0f);
    } else {
        func_00252230(&sp120, (Sp120 *)(work + 0xC), (Sp120 *)(work + 0x30),
                      (f32)rank / 30.0f);
    }
    if (special != 0) {
        if (sp120.f18 == 0xFFE92CFF) {
            *(s32 *)(work + 0xC) = 0;
            sp120.f18 = -1;
        } else {
            sp120.f18 = 0xBFBFBFFF;
        }
    }
    src = D_006361F0;
    dst = uv;
    count = 4;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    tex = func_0025f360(0x18, 0, *(s32 *)(ctx + 0x10));
    func_003e0870(mat, (u8 *)&sp120 + 0xC, sp120.f1C, 0);
    if (*(s32 *)(work + 0xC) == 1) {
        work = (u8 *)D_00887300;
        (*(void (**)(u32, u32))work)(7, 2);
        (*(void (**)(u32, u32))work)(9, 2);
        (*(void (**)(u32, u32))work)(6, 1);
        (*(void (**)(u32, u32))work)(8, 1);
        (*(void (**)(u32, u32))work)(0xC, 1);
        (*(void (**)(u32, u32))work)(2, 4);
        (*(void (**)(u32, u32))work)(0xE, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x48);
        func_00366c70((s32)sp120.f4, (s32)sp120.f8, sp120.f20, sp120.f22,
                      (u32)sp120.f18 >> 8, sp120.f18 & 0xFF, 0,
                      (s16)(sp120.f20 >> 1), 0.0f,
                      (s16)(sp120.f22 >> 1), mat, tex, uv);
    } else {
        func_00366c70((s32)sp120.f4, (s32)sp120.f8, sp120.f20, sp120.f22,
                      (u32)sp120.f18 >> 8, sp120.f18 & 0xFF, 1,
                      (s16)(sp120.f20 >> 1), 0.0f,
                      (s16)(sp120.f22 >> 1), mat, tex, uv);
    }
    return done;
}
