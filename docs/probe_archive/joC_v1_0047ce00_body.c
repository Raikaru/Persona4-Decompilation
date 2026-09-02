s32 func_0047ce00(u8 *arg0)
{
    s32 ret;
    u8 *obj;
    s32 sp4C;

    obj = *(u8 **)(arg0 + 0x30C);
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    switch (*(u8 *)(obj + 0x3C)) {
    case 0:
        if (*(u8 **)(obj + 0x38) != NULL) {
            if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
                func_00456150(*(u8 **)(obj + 0x38));
            }
            if (func_004553c0(*(u8 **)(obj + 0x38)) == 0) {
                goto ret_label;
            }
            if (*(s32 *)(obj + 0x40) != 0) {
                *(s32 *)(obj + 0x2C) = func_00455ea0(*(u8 **)(obj + 0x38), 0, &sp4C);
                *(s32 *)(obj + 0x30) = sp4C;
                func_0047e450(arg0 + 0x2D0, *(u16 *)(arg0 + 0xD4), *(u16 *)(arg0 + 0xD6), func_00455ea0(*(u8 **)(obj + 0x38), 1, &sp4C), sp4C);
            } else {
                *(s32 *)(obj + 0x2C) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x110);
                *(s32 *)(obj + 0x30) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x118);
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
        if (*(s32 *)(obj + 0) == 0) {
            *(s32 *)(obj + 0) = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 1:
        if (*(u8 *)(obj + 0x3C) == 1) {
c660_again:
            if (func_0047c660(arg0) == 0) {
                goto ret_label;
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 2:
        if (func_0047b0c0(arg0) == 0) {
            *(u8 *)(obj + 0x3C) = 1;
            goto c660_again;
        }
        *(u8 *)(obj + 0x3C) = 3;
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(obj + 0x3C) = 4;
            goto L_after_c3;
        }
    case 3:
        if (func_0047c660(arg0) == 0) {
            goto ret_label;
        }
        *(u8 *)(obj + 0x3C) = 4;
L_after_c3:
    case 4:
        if (*(s32 *)(obj + 0x34) != 0) {
            func_00463250(*(void **)(obj + 0x34));
        }
        func_003e2e40(*(s32 *)(obj + 0), (s32 *)(obj + 0x2C));
        if (*(u8 **)(obj + 0x38) != NULL) {
            func_00454bd0(*(u8 **)(obj + 0x38));
        }
        *(u8 *)(obj + 0x3C) = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}
