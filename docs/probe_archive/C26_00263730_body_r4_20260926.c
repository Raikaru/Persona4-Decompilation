#pragma push
#pragma opt_loop_invariants on
// FUN_00263730
void func_00263730(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 blink, u8 *font)
{
    s32 i;
    s32 day;
    s32 dx;
    s32 word;
    u8 fadeOut;
    u8 fadeIn;

    for (i = 0; i < 8; i++) {
        day = date - 1 + i;
        if (day < 0) {
            continue;
        }
        if (blink != 0 && (func_00110c50(day, date) & 0xFFFF) != (func_00110c50(day, date + 1) & 0xFFFF)) {
            fadeOut = 255.0f - (f32)(alpha * func_0043c6a0(x)) / 94.0f;
            dx = x + i * 94 + 15;
            func_00262de0(dx, y + 245, depth, fadeOut, date - 1 + i, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(x + i * 94, y + 295, depth, fadeOut, func_00110c50(date - 1 + i, date) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
            fadeIn = (f32)(alpha * func_0043c6a0(x)) / 94.0f;
            func_00262de0(dx, y + 245, depth, fadeIn, date - 1 + i, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(x + i * 94, y + 295, depth, fadeIn, func_00110c50(date - 1 + i, date + 1) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
        } else {
            dx = x + i * 94 + 15;
            func_00262de0(dx, y + 245, depth, alpha, date - 1 + i, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(x + i * 94, y + 295, depth, alpha, func_00110c50(date - 1 + i, date) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, word, 0);
        }
        if (i == 1) {
            func_00262de0(dx, y + 245, depth, alpha, date - 1 + i, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(x + i * 94, y + 295, depth, alpha, func_00110c50(date - 1 + i, date) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, word, 0);
        } else if (i == 2) {
            func_00262de0(dx, y + 245, depth, alpha, date - 1 + i, 1, 1.0f, 1.0f, 0xB2, 0x5E, *(s32 *)(font + 4), 0);
            word = *(s32 *)(font + 4);
            func_00261560(x + i * 94, y + 295, depth, alpha, func_00110c50(date - 1 + i, date) & 0xFFFF, 1, 1.0f, 1.0f, 0xB2, 0x5E, word, 0);
        }
    }
}
#pragma pop
