/* object_size=608; window=592; normalized_diff=404; differing_offsets=[0,4,8,10,12,14,16,18,20,21,22,23,24,25,26,27] (report first-diff list); classification=OBJECT_LARGER_THAN_WINDOW+LARGE_RESIDUAL; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; corrected callees to func_003e2e40(s32,s32*), func_003e2f60(s32,s32,s32*), func_00454bd0(u8*), func_004553c0(u8*), func_00455ea0(u8*,s32,s32*), func_00456150(u8*), func_00463250(void*), func_0047b0c0(u8*), func_0047c660(u8*), func_0047e450(u8*,s16,s16,s32,u32); candidate object exceeded window and nd remained 404, so archived immediately. */

s32 func_0047ce00(u8 *arg0)
{
    s32 sp4C;
    s32 temp_4_2;
    s32 var_17;
    u8 temp_2;
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_3;

    temp_16 = *(u8 **)(arg0 + 0x30C);
    if (temp_16 == NULL) {
        return 1;
    }
    var_17 = 0;
    temp_2 = *(u8 *)(temp_16 + 0x3C);
    if (temp_2 >= 6) {
        goto block_30;
    }
    switch (temp_2) {
    case 0:
        temp_4 = *(u8 **)(temp_16 + 0x38);
        if (temp_4 == NULL) {
            goto block_12;
        }
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            func_00456150(temp_4);
        }
        if (func_004553c0(temp_4) == 0) {
            goto block_30;
        }
        if (*(s32 *)(temp_16 + 0x40) == 0) {
            *(s32 *)(temp_16 + 0x2C) = *(s32 *)(*(u8 **)(temp_16 + 0x38) + 0x110);
            *(s32 *)(temp_16 + 0x30) = *(s32 *)(*(u8 **)(temp_16 + 0x38) + 0x118);
            goto block_11;
        }
        *(s32 *)(temp_16 + 0x2C) = func_00455ea0(temp_4, 0, &sp4C);
        *(s32 *)(temp_16 + 0x30) = sp4C;
        temp_4_2 = func_00455ea0(temp_4, 1, &sp4C);
        func_0047e450(arg0 + 0x2D0, *(u16 *)(arg0 + 0xD4),
                      *(u16 *)(arg0 + 0xD6), temp_4_2, sp4C);
block_11:
        *(u8 *)(temp_16 + 0x3C) = 2;
block_12:
        if (*(s32 *)temp_16 == 0) {
            *(s32 *)temp_16 = func_003e2f60(3, 1, (s32 *)(temp_16 + 0x2C));
            *(u8 *)(temp_16 + 0x3C) = 2;
        }
block_14:
    case 1:
        if (*(u8 *)(temp_16 + 0x3C) != 1) {
            goto block_17;
        }
block_15:
        if (func_0047c660(arg0) == 0) {
            goto block_30;
        }
        *(u8 *)(temp_16 + 0x3C) = 2;
block_17:
    case 2:
        if (func_0047b0c0(arg0) != 0) {
            *(u8 *)(temp_16 + 0x3C) = 3;
            goto block_20;
        }
        *(u8 *)(temp_16 + 0x3C) = 1;
        goto block_15;
block_20:
    case 3:
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(temp_16 + 0x3C) = 4;
            goto block_24;
        }
block_22:
        if (func_0047c660(arg0) == 0) {
            goto block_30;
        }
        *(u8 *)(temp_16 + 0x3C) = 4;
block_24:
    case 4:
        temp_4_2 = *(s32 *)(temp_16 + 0x34);
        if (temp_4_2 != 0) {
            func_00463250((void *)temp_4_2);
        }
        func_003e2e40(*(s32 *)temp_16, (s32 *)(temp_16 + 0x2C));
        temp_4_3 = *(u8 **)(temp_16 + 0x38);
        if (temp_4_3 != NULL) {
            func_00454bd0(temp_4_3);
        }
        *(u8 *)(temp_16 + 0x3C) = 5;
    case 5:
        var_17 = 1;
        break;
    }
block_30:
    return var_17;
}
