/* Lane119d3b measured body for func_003b6f00.
 * Compiled with MWCCPS2 3.0.1 b119 inside src/promoted/code1_003b_cw119.c.
 * Best normalized_diff: 82 words, object 252B vs retail 352B.
 * The retail function uses MMI mult/mult1 alternating and reloads the
 * base pointer from D_008872E0 + iGpffffb618 for each multiply; this body
 * retains the LCG seeding shape and the 0x136 warm-up loop.
 */
#pragma schedule on
void func_003b6f00(s32 arg0, u8 *arg1) {
    u8 **pp;
    u8 *base;
    s32 var_6;
    s32 var_5;
    s32 count;

    pp = (u8 **)(D_008872E0 + iGpffffb618);
    base = pp[0];
    *(s32 *)base = arg0;

    var_6 = 1;
    var_5 = 4;
    do {
        u8 *p;
        var_6 += 6;
        p = base + var_5;
        *(s32 *)(p + 0x00) = *(s32 *)(p - 0x04) * 0x41C64E6D + 0x3039;
        *(s32 *)(p + 0x04) = *(s32 *)(p + 0x00) * 0x41C64E6D + 0x3039;
        *(s32 *)(p + 0x08) = *(s32 *)(p + 0x04) * 0x41C64E6D + 0x3039;
        *(s32 *)(p + 0x0C) = *(s32 *)(p + 0x08) * 0x41C64E6D + 0x3039;
        *(s32 *)(p + 0x10) = *(s32 *)(p + 0x0C) * 0x41C64E6D + 0x3039;
        *(s32 *)(p + 0x14) = *(s32 *)(p + 0x10) * 0x41C64E6D + 0x3039;
        var_5 += 0x18;
    } while (var_6 < 0x1F);

    pp = (u8 **)(D_008872E0 + iGpffffb618);
    base = pp[0];
    pp[1] = base + 0xC;
    pp[2] = base;

    count = 0;
    do {
        func_003b7060();
        count++;
    } while (count < 0x136);
}
#pragma schedule off
