/* IDA recovery: 43 differing words through the normal probe CLI; not installed. */
// FUN_0021ED10
void func_0021ed10(BtlResultWork *work, f32 *position, u32 color, u32 number, s32 grouped)
{
    u8 red = (color & 0xFF000000) >> 24;
    u8 green = (color & 0x00FF0000) >> 16;
    u8 blue = (color & 0x0000FF00) >> 8;
    u8 alpha = color & 0xFF;
    char reverse[64];
    char text[64];
    s32 length;
    s32 groupDigits;
    s32 i;
    s32 digit;

    if (alpha != 0) {
        if (number >= 1000 && grouped != 0) {
            length = 0;
            groupDigits = 0;
            do {
                reverse[length++] = number % 10 + '0';
                number /= 10;
                if (number != 0 && groupDigits == 2) {
                    reverse[length++] = '.';
                }
                groupDigits++;
                if (groupDigits >= 3) {
                    groupDigits = 0;
                }
            } while (number != 0);
            for (i = 0; i < length; i++) {
                text[i] = reverse[length - (i + 1)];
            }
            text[i] = 0;
        } else {
            func_00442088(text, &iGpffffa5b4, number);
        }
        for (i = 0; text[i] != 0; i++) {
            switch (text[i]) {
            case '.':
                func_0034f2e0((void *)work->field414[35], position[0], position[1],
                              red, green, blue, alpha);
                position[0] = position[0] + 8.0f;
                break;
            default:
                digit = text[i] - '0';
                if (digit < 0 || digit >= 10) {
                    func_0046d730(D_00629610, 0x119);
                }
                func_0034f2e0((void *)(&work->field414[25])[digit], position[0], position[1],
                              red, green, blue, alpha);
                position[0] = position[0] + 22.0f;
                break;
            }
        }
    }
}
