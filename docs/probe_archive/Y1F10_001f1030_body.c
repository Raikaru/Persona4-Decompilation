// FUN_001F1030
s32 func_001f1030(u8 *arg0) {
    s32 var_2;
    s32 var_5;
    s32 var_6;
    u16 temp_5;
    u8 var_16;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_3 = *(u8 **)(arg0 + 0x30);
    var_16 = *(u8 *)(temp_3 + 0xA2);
    if (*(u16 *)(arg0 + 0x1A) & 1) {
        temp_4 = *(u8 **)(temp_3 + 0xA64);
        if ((temp_4 != NULL) && (func_00232710((s32)temp_4, 0x100) != 0)) {
            if (!(var_16 & 0xFF)) { var_2 = 1; } else { var_2 = 0; }
            var_16 = var_2 & 0xFF;
        }
    }
    temp_5 = *(u16 *)(arg0 + 0x6A);
    if ((s32)temp_5 < 2) {
        if (temp_5 == 1) {
            temp_4_2 = *(u8 **)(arg0 + 0x38);
            if (!(*(u16 *)(temp_4_2 + 0x1A) & 1)) return 0;
            if (*(u8 *)(*(u8 **)(temp_4_2 + 0x30) + 0xA2) != (var_16 & 0xFF)) return 0;
            var_5 = 0;
            while ((var_5 & 0xFFFF) < (s32)*(u8 *)(temp_4_2 + 0xD9)) {
                if (*(u16 *)(temp_4_2 + ((var_5 & 0xFFFF) << 5) + 0x10E) & 0x20) return 1;
            }
        }
        return 0;
    }
    var_6 = 0;
    while ((var_6 & 0xFFFF) < (s32)temp_5) {
        temp_3_2 = *(u8 **)(arg0 + ((var_6 & 0xFFFF) * 4) + 0x38);
        if ((*(u16 *)(temp_3_2 + 0x1A) & 1) != 0 && (*(u8 *)(*(u8 **)(temp_3_2 + 0x30) + 0xA2) != (var_16 & 0xFF))) return 0;
        var_6 = (var_6 + 1) & 0xFFFF;
    }
    return 1;
}
