#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// FUN_00263730
void func_00263730(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 blink, u8 *font)
{
    s32 i;
    s32 day;
    s32 cur;
    s32 n;
    s32 px;
    s32 dx;
    s32 word;
    u8 fadeOut;
    u8 fadeIn;

    for (i = 0; i < 8; i++) {
        day = date - 1 + i;
        if (day < 0) {
            continue;
        }
        if (blink != 0 && (cur = func_00110c50(day, date) & 0xFFFF) != (func_00110c50(day, date + 1) & 0xFFFF)) {
            fadeOut = 255.0f - (f32)(alpha * func_0043c6a0(x)) / 94.0f;
            n = date - 1 + i;
            px = x + i * 94;
            dx = px + 15;
            func_00262de0(dx, y + 245, depth, fadeOut, n, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(px, y + 295, depth, fadeOut, func_00110c50(n, date) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
            fadeIn = (f32)(alpha * func_0043c6a0(x)) / 94.0f;
            func_00262de0(dx, y + 245, depth, fadeIn, n, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(px, y + 295, depth, fadeIn, func_00110c50(n, date + 1) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
        } else {
            n = date - 1 + i;
            px = x + i * 94;
            dx = px + 15;
            func_00262de0(dx, y + 245, depth, alpha, n, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(px, y + 295, depth, alpha, func_00110c50(n, date) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
        }
        if (i == 1) {
            n = date - 1 + i;
            px = x + i * 94;
            func_00262de0(dx, y + 245, depth, alpha, n, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(px, y + 295, depth, alpha, func_00110c50(n, date) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, word, 0);
        } else if (i == 2) {
            n = date - 1 + i;
            px = x + i * 94;
            func_00262de0(dx, y + 245, depth, alpha, n, 1, 1.0f, 1.0f, 0xB2, 0x5E, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(px, y + 295, depth, alpha, func_00110c50(n, date) & 0xFFFF, 1, 1.0f, 1.0f, 0xB2, 0x5E, word, 0);
        }
    }
}
#pragma pop
