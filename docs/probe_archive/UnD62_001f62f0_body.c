/* Main 2026-09-03: re-probed, nd12 -> 6 words (3 sites): (1) `andi a1` before `lhu a0` for the func_001f0950
   call - retail materialises the (u16)code argument first; u16 callee signatures, a named u16 local,
   `*(u16 *)((u32)arg0 + 0xA4)`, `code & 0xFFFF` do not move it (the callee is defined in-TU with s32,s32);
   (2) two `addu v0,v0,s6` (retail temp-first for `(base + i*2) + offset`; b210 puts the s6 variable first;
   inlining `mode * 0x1E` hoists it into a new saved register, nd170). AST permuter 8k compiles: best 7. */
/* Best candidate for func_001f62f0; reverted because scoped lverify remained MISMATCH.
 * Lane UnD62: object 728B, retail window 736B, normalized_diff 12.
 * Four non-relocation instruction words remained: the func_001f0950 argument
 * evaluation order (retail computes andi before lhu) and two addu operand-order
 * differences for the loop value's invariant offset. The candidate did match
 * the frame, control flow, jump table, calls, and both daddiu constants.
 */
s32 func_001f62f0(u8 *arg0)
{
    extern s32 func_001ef4d0();
    extern s32 func_00231e20();
    extern s32 func_0023a6b0();
    extern u32 func_004bd050(s32 arg0);
    extern s32 func_001f0950();
    s32 code;
    s32 base;
    s32 random;
    u16 mode;
    u16 count;
    s16 i;
    s32 flags;
    s32 offset;
    u16 values[8];

    base = func_00106330(0x38) != 0 ? 0xFA : 0xC8;
    random = func_001ef4d0(2, 0x80000) & 0xFFFF;
    flags = func_00231e20(
        *(s32 *)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) + 0xA64)) &
        0xFF;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        mode = 0;
    } else if ((random - flags) >= 4) {
        mode = 0;
    } else if ((flags - random) >= 4) {
        mode = 2;
    } else {
        mode = 1;
    }
    count = 0;
    i = 0;
    offset = mode * 0x1E;
    for (; i < 7; i++) {
        switch (i) {
        case 0:
            code = 0;
            break;
        case 1:
            code = 1;
            break;
        case 2:
            code = 2;
            break;
        case 3:
            code = 4;
            break;
        case 4:
            code = 3;
            break;
        case 5:
            code = 6;
            break;
        case 6:
            code = 7;
            break;
        default:
            break;
        }
        if ((*(u8 *)(arg0 + 0xA2) != 1) ||
            (func_001f0950(*(u16 *)(arg0 + 0xA4), (u16)code) != 0)) {
            flags = func_0023a6b0(*(s32 *)(arg0 + 0xA64), code);
            if ((flags & 0x08000000) != 0) {
                values[count++] =
                    (u16)(base + (i * 2) + offset + 2 +
                          (func_004bd050(0) & 1));
            } else if ((flags & 0x07000000) != 0) {
                values[count++] =
                    (u16)(base + (i * 2) + offset + 2 +
                          (func_004bd050(0) & 1) + 0xE);
            }
        }
    }
    if (count > 0) {
        return values[func_00231d70(count)];
    }
    return base + (func_004bd050(0) & 1) + offset;
}
