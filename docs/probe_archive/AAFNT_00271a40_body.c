/* Archived candidate for func_00271a40; measured normalized_diff 193 (280B object vs 304B window). */
void func_00271a40(void)
{
    s32 i, mask, idx;
    u32 tmp;
    u8 *slot, *par;
    for (i = 0; i < 9; i++) {
        if (*(u32 *)((u8 *)DAT_00881630_abs + i * 0x20 + 0x1c) == 0) continue;
        mask = i & 0xff;
        if (mask >= 9) func_0046d740(D_0063BBB0, D_0063BAE8, 0x319);
        idx = i & 0xff; slot = (u8 *)DAT_00881630_abs + idx * 0x20;
        if (*(u32 *)(slot + 0x1c) == 0) func_0046d730(D_0063BAE8, 0x31D);
        par = (u8 *)DAT_00881630_abs + idx * 4; tmp = *(u32 *)(par + 0x180);
        if (tmp == 0) continue;
        *(u32 *)(par + ((u8)i - idx) * 4 + 0x180) = 0;
        func_00454bd0(tmp); func_00440B68(D_0063BBF0, mask);
        *(u32 *)slot = 0; *(u32 *)(slot + 0x1c) = 0;
    }
}
