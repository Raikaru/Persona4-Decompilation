// FUN_00213D20
void func_00213d20(u8 *arg0)
{
    u8 *p;
    s16 x;

    p = *(u8 **)(iGpffffa598 + 0x17C);
    while (p != NULL) {
        if (*(s32 *)arg0 & 1) {
            x = *(s16 *)(p + 0xA16);
            if (x >= -1) { x = x - 1; *(s16 *)(p + 0xA16) = x; }
        } else {
            x = *(s16 *)(p + 0xA16);
            if (x < 25) { x = x + 1; *(s16 *)(p + 0xA16) = x; }
        }
        if (!(*(s32 *)arg0 & 2)) {
            x = *(s16 *)(p + 0xA14) - 2;
            *(s16 *)(p + 0xA14) = x;
            if (x < 0) *(s16 *)(p + 0xA14) = 0;
        } else {
            x = *(s16 *)(p + 0xA14);
            if (x < 8) { x = x + 1; *(s16 *)(p + 0xA14) = x; }
        }
        p = *(u8 **)(p + 0xA68);
    }
    if (*(s32 *)arg0 & 4) {
        x = *(s16 *)(arg0 + 4);
        if (x < 10) { x = x + 1; *(s16 *)(arg0 + 4) = x; }
    } else {
        x = *(s16 *)(arg0 + 4);
        if (x > 0) { x = x - 1; *(s16 *)(arg0 + 4) = x; }
    }
}
