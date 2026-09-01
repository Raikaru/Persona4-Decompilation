/* Closest non-MATCH candidate; reverted before lane completion. */
// FUN_00463930
u8 *func_00463930(u8 *arg0)
{
    u8 *image;
    s32 bit_depth;
    u8 *source;
    s32 i;
    u8 *dst;

    source = arg0 + 0x40;
    if ((*(u8 *)(arg0 + 0) != 2) ||
        (*(u8 *)(arg0 + 1) != 0) ||
        (*(u8 *)(arg0 + 8) != 0x54) ||
        (*(u8 *)(arg0 + 9) != 0x4D) ||
        (*(u8 *)(arg0 + 0xA) != 0x58) ||
        (*(u8 *)(arg0 + 0xB) != 0x30)) {
        return NULL;
    }
    switch (*(u8 *)(arg0 + 0x16)) {
    case 0x2C:
    case 0x24:
    case 0x14:
        bit_depth = 4;
        break;
    case 0x1B:
    case 0x13:
        bit_depth = 8;
        break;
    case 0xA:
    case 2:
        bit_depth = 0x10;
        break;
    case 1:
        bit_depth = 0x18;
        break;
    default:
        if (*(u8 *)(arg0 + 0x16) == 0) {
            bit_depth = 0x20;
        } else {
            bit_depth = 0;
        }
        break;
    }
    if (bit_depth == 0) {
        return NULL;
    }
    if (bit_depth >= 0x10) {
        bit_depth = 0x20;
    }
    image = func_003ea2c0(*(u16 *)(arg0 + 0x12),
                          *(u16 *)(arg0 + 0x14), bit_depth);
    func_003ea3e0(image);
    if (*(u8 *)(arg0 + 0x10) != 0) {
        switch (*(u8 *)(arg0 + 0x11)) {
        case 0xA:
        case 2:
            for (i = 0; i < (1 << *(s32 *)(image + 0xC)); i++) {
                u16 value = *(u16 *)(source + i * 2);
                u8 *entry = image + *(s32 *)(image + 0x18) + i * 4;

                entry[0] = (u8)((value & 0x1F) * 8);
                entry[1] = (u8)(((value >> 5) & 0x1F) * 8);
                entry[2] = (u8)(((value >> 0xA) & 0x1F) * 8);
                if (i == 0) {
                    entry[3] = 0;
                } else {
                    entry[3] = -1;
                }
            }
            break;
        case 0:
            func_004637c0(image, (const u16 *)source);
            break;
        }
        func_00463870(image, bit_depth);
        if (*(u8 *)(arg0 + 0x11) == 0) {
            source += (0x20 * *(u8 *)(arg0 + 0x10) * (1 << bit_depth)) >> 3;
        } else if ((*(u8 *)(arg0 + 0x11) == 0xA) ||
                   (*(u8 *)(arg0 + 0x11) == 2)) {
            source += (0x10 * *(u8 *)(arg0 + 0x10) * (1 << bit_depth)) >> 3;
        }
    }
    switch (*(u8 *)(arg0 + 0x16)) {
    case 0x2C:
    case 0x24:
    case 0x14:
        func_00463740(image, source);
        break;
    case 0x1B:
    case 0x13:
        dst = image + *(s32 *)(image + 0x14);
        for (i = 0; i < *(s32 *)(image + 8); i++) {
            s32 j;

            for (j = 0; j < *(s32 *)(image + 4); j++) {
                dst[j] = *source;
                source++;
            }
            dst += *(s32 *)(image + 0x10);
        }
        break;
    case 0xA:
    case 2:
        func_004636a0(image, source);
        break;
    case 1:
        func_00463620(image, source);
        break;
    default:
        if (*(u8 *)(arg0 + 0x16) == 0) {
            func_00463570(image, source);
        }
        break;
    }
    return image;
}
