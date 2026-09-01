/*
 * Target: func_002b3720
 * Object/window: 576B / 576B
 * normalized_diff: 3 words
 * Differing offsets: 0x48, 0x4C, 0x50 (initial Vec2 copy load/store order)
 * Ruled out: direct field assignments, reversed field order, scalar temporaries,
 * destination/source pointer copies, array copies, comma-expression copies,
 * aggregate assignment (ld/sd), builtin memcpy, and propagation/common-subexpression
 * pragma variants. The successful struct-cast assignment fix is in source;
 * this file preserves the pre-fix near-miss body for provenance.
 * COP1 accumulator chain: reproduced by plain C (both adda.s/madd.s pairs);
 * it was not the residual.
 */
s32 func_002b3720(u8 *arg0)
{
    struct Vec2 {
        f32 x;
        f32 y;
    } out;
    struct Vec2 work;
    f32 *src;
    f32 temp_f20;
    u8 *p;
    s32 color;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&work.x, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    src = &work.x;
    out.x = src[0];
    out.y = src[1];
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s8 *)(p + 0x21) == 1) {
        return 0;
    }
    if (*(s8 *)(p + 0x20) == 0) {
        out.x = out.x + 17.0f;
        out.y = out.y + 264.0f;
        out.x = out.x - 10.0f;
        out.y = out.y - 10.0f;
        out.y = out.y - 2.0f;
    } else if (*(s8 *)(p + 0x20) == 1) {
        temp_f20 = ((f32)func_002b11c0(
                        func_0047a2f0(D_007EFA00[0]) + 0x30) *
                    18.0f) + 172.0f;
        out.x = temp_f20 -
                func_002b1260(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f);
        temp_f20 = ((f32)func_002b1210(
                        func_0047a2f0(D_007EFA00[0]) + 0x30) *
                    18.0f) + 9.0f;
        out.y = temp_f20 -
                func_002b1320(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220),
                              18.0f) - 2.0f;
    }
    color = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    func_002b3ae0(arg0, *(s64 *)&out, 60002.0f, color);
    return 0;
}
