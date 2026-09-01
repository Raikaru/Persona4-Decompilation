/* TRSL 2026-08-14: object 1048B / window 976B / normalized_diff 662; first differing offsets 33,36,38,39,40,41,42,43,44,45,46,47,48,49,50,51; surplus 18 instructions; classification frame/register-coloring floor (five saved integer registers versus retail four plus f20); ruled out typed byte/float fields, direct table indexing, explicit loop bounds, and signed half-scaler conversion. */
void func_0021ef70(BtlResultWork *work)
{
    u8 *base;
    u8 *row;
    u8 *src;
    s32 *out;
    s32 i;
    s32 value;
    f32 scaled;
    f32 base_value;

    base = (u8 *)work;
    for (i = 0; i < 20; i++) {
        src = (u8 *)D_006291A0 + i * 0x18;
        row = base + i * 0x30;
        *(f32 *)(row + 0x40) = *(f32 *)(src + 0);
        *(f32 *)(row + 0x50) = *(f32 *)(src + 0);
        *(f32 *)(row + 0x44) = *(f32 *)(src + 4);
        *(f32 *)(row + 0x54) = *(f32 *)(src + 4);
        *(u8 *)(row + 0x58) = *(u8 *)(src + 8);
        *(u8 *)(row + 0x5A) = *(u8 *)(src + 8);
        src = (u8 *)D_00629380 + i * 0x18;
        *(f32 *)(row + 0x48) = *(f32 *)(src + 0);
        *(f32 *)(row + 0x4C) = *(f32 *)(src + 4);
        *(u8 *)(row + 0x59) = *(u8 *)(src + 8);
        *(s32 *)(row + 0x68) = *(s32 *)(src + 0xC);
        *(s32 *)(row + 0x6C) = *(s32 *)(src + 0x10);
    }
    for (i = 0; i < 42; i++) {
        out = (s32 *)(base + i * 4 + 0x414);
        if (i < 13) {
            *out = func_0046d200(*(s32 *)(base + 0x400), D_00629170[i]);
        } else if (i < 15) {
            *out = func_0046d200(*(s32 *)(base + 0x404), D_00629170[i]);
        } else if (i < 25) {
            *out = func_0046d200(*(s32 *)(base + 0x40C), D_00629170[i]);
        } else if (i < 36) {
            *out = func_0046d200(*(s32 *)(base + 0x410), D_00629170[i]);
        } else {
            *out = func_0046d200(*(s32 *)(base + 0x408), D_00629170[i]);
        }
        if (*out == 0) {
            func_0046d730(&D_00629610, 345);
        }
    }
    for (i = 0; i < 5; i++) {
        row = base + i * 0x20;
        *(u32 *)(row + 0x4C8) = 0x43560000;
        *(f32 *)(row + 0x4D0) = *(f32 *)(row + 0x4C8);
        value = (s32)((func_003b7060() & 0xFFF) * 214);
        if (value < 0) {
            scaled = (f32)value;
        } else {
            scaled = 2.0f * (f32)(((u32)value >> 1) | (value & 1));
        }
        *(f32 *)(row + 0x4D8) = scaled / 4096.0f;
        src = (u8 *)D_00629560 + i * 0x1C;
        base_value = *(f32 *)(src + 0x14);
        value = func_003b7060() & 0xFFF;
        if (value < 0) {
            scaled = (f32)value;
        } else {
            scaled = 2.0f * (f32)(((u32)value >> 1) | (value & 1));
        }
        *(f32 *)(row + 0x4C4) =
            base_value + ((*(f32 *)(src + 0x18) - base_value) * scaled) /
            4096.0f;
        *(s16 *)(row + 0x4C0) = 0;
        *(s16 *)(row + 0x4C2) = *(s32 *)(src + 8) +
            func_003b7060() % *(u32 *)(src + 0xC);
    }
    for (i = 0; i < 2; i++) {
        row = base + i * 8;
        *(s16 *)(row + 0x564) = 0;
        *(f32 *)(row + 0x560) = *(f32 *)((u8 *)D_006295F0 + i * 0xC + 4);
    }
    *(s16 *)(base + 0x3C) = 0;
    *(s32 *)(base + 0x38) = 0;
}
