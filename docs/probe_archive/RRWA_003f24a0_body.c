/* func_003f24a0 object=264 window=288 normalized_diff=197 differing_offsets=6,7,12,14,15,16,17,18,19,21,22,26,27,28,29,30 classification=undersized; ruled_out=saved-s-register-count(1), argument-count(1), GP-offset-declaration-probe */
s32 func_003f24a0(u8 *arg0)
{
    extern s32 func_003e1210(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern s32 iGpffffabd0;
    extern s64 D_0088B400[];
    s32 bit_count, one, limit, mask, bit, index;
    u8 *ptr; s64 *out; s64 packed, value;
    one = 1; bit_count = iGpffffabd0; limit = one << bit_count; mask = 0; out = D_0088B400;
    if (limit != 0) {
        do {
            packed = 0; bit = 0;
            if (bit_count != 0) do {
                if ((mask & (one << bit)) != 0) value = (s64)(one << ((bit_count - 1 - bit) * 4)); else value = 0;
                bit += 1; packed |= (value << 32) >> 32;
            } while (bit < bit_count);
            mask += 1; *out = packed; out += 1;
        } while (mask < limit);
    }
    *(s32 *)(arg0 + 0x4004) = func_003e1210(0x5c, 0x400, 4, 0x30411);
    *(u8 **)(arg0 + 0x4000) = D_008873F8[0](*(u8 **)(arg0 + 0x4004), 0x30411);
    index = 0; ptr = *(u8 **)(arg0 + 0x4000) + 0x1c;
    do {
        *(s32 *)(ptr + 0) = 0; index += 8; *(s32 *)(ptr + 4) = 0; *(s32 *)(ptr + 8) = 0; *(s32 *)(ptr + 0xc) = 0;
        *(s32 *)(ptr + 0x10) = 0; *(s32 *)(ptr + 0x14) = 0; *(s32 *)(ptr + 0x18) = 0; *(s32 *)(ptr + 0x1c) = 0; ptr += 0x20;
    } while (index < 0x10);
    return 1;
}
