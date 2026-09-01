// FUN_001D7C60
void func_001d7c60(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4)
{
    typedef signed __int128 s128;
    s128 spA0;
    s32 temp_17;
    s32 temp_4_2;
    s32 temp_4_3;
    u16 var_17;
    u16 var_16;
    u16 var_5;
    u8 temp_4;
    u8 temp_4_4;
    u8 *temp_16;
    u8 *var_21;

    func_0043f9c8(arg1, 0, 0x30);
    *(u16 *)(arg1 + 0x38) = 0;
    *(u16 *)(arg1 + 0x3A) = 0;
    *(u8 *)(arg1 + 0x3C) = 0;
    *(u8 *)(arg1 + 0x3C) |= 1;
    if (arg0 != NULL) {
        temp_4 = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
        switch (temp_4) {
        case 0:
            var_17 = 1;
            var_16 = 2;
            break;
        case 1:
            var_17 = 2;
            var_16 = 1;
            break;
        }
    } else {
        var_17 = 1;
        var_16 = 2;
    }
    var_5 = 0;
    temp_4_2 = arg2 & 0xFF;
    if (temp_4_2 & 1)
        var_5 = (u16)((0 | var_17) & 0xFFFF);
    if (temp_4_2 & 2)
        var_5 = (u16)((var_5 | var_16) & 0xFFFF);
    if (temp_4_2 & 4)
        var_5 = (u16)((var_5 | 4) & 0xFFFF);
    temp_4_3 = arg3 & 0xFF;
    if (temp_4_3 & 1) {
        *(u8 **)(arg1 + 0) = arg0;
        *(u16 *)(arg1 + 0x38) = 1;
        return;
    }
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    temp_17 = var_5;
    spA0 = temp_4_3 & 8;
    while (var_21 != NULL) {
        if ((arg0 == NULL || (*(u16 *)(var_21 + 0x1A) & 8)) &&
            (*(u16 *)(var_21 + 0x1A) & 1) &&
            ((temp_16 = *(u8 **)(var_21 + 0x30),
              temp_4_4 = *(u8 *)(temp_16 + 0xA2),
              temp_4_4 == 2) ||
             (*(s32 *)(temp_16 + 0x9C) & 8)) &&
            (temp_17 & (1 << temp_4_4))) {
            if (!(temp_17 & 4)) {
                if ((!(temp_4_3 & 2) || arg0 != var_21) &&
                    ((temp_4_3 & 4) ||
                     func_002428f0(*(u8 **)(temp_16 + 0xA64), 0) == 0)) {
                    if ((s64)spA0 != 0) {
                        if (func_00232710(
                                *(u8 **)(temp_16 + 0xA64),
                                0x100000) != 0) {
                            goto include;
                        }
                    } else if (
                        arg4 == 0 ||
                        ((*(s32 *)(*(u8 **)(temp_16 + 0xA64) + 0xC) &
                          0xFFEFFFFF) != 0 &&
                         func_00232710(
                             *(u8 **)(temp_16 + 0xA64), arg4) == 0)) {
                        goto include;
                    }
                }
            } else {
include:
                *(u8 **)(arg1 + (u32)*(u16 *)(arg1 + 0x38) * 4) = var_21;
                *(u16 *)(arg1 + 0x38) =
                    (u16)(*(u16 *)(arg1 + 0x38) + 1);
            }
        }
        var_21 = *(u8 **)(var_21 + 0x450);
    }
}
