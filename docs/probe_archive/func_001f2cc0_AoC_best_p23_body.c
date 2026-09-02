// Best measured body for func_001f2cc0, AoC001f2cc0p23.
// object_size 496B, window 496B, normalized_diff 12, differing words 9.
// Retail register list: s1=arg0; s0=func_00243a30 result / var_16;
// a3=first-loop found flag then second-loop base; t0=both loop indices;
// a1=first-loop base then second-loop slot; a0=first-loop slot / second-loop counter;
// a2=second-loop byte offset; v1=loop/address/value temporary; sp+0x3c=sp3C.

void func_001f2cc0(u8 *arg0)
{
    s32 sp3C;
    u8 *base;
    u8 *entry;
    u8 *base2;
    u8 *slot;
    u16 temp_4_5;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_8;
    s64 var_7;
    s32 var_8_2;
    u16 temp_4;
    u16 var_16;
    u8 *temp_16;

    temp_4 = *(u16 *)(arg0 + 0x1A);
    if ((temp_4 & 1) != 0) {
        temp_16 = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(temp_16 + 0xA2) == 1) {
            if (*(u16 *)(temp_16 + 0xA4) >= 0x150) {
                func_0046d730((void *)D_0060AB08, 0x4F5);
            }
            temp_4 = *(u16 *)(arg0 + 0x1A);
            if ((temp_4 & 0x20) == 0) {
                *(u16 *)(arg0 + 0x1A) = (u16)(temp_4 | 0x20);
                *(s32 *)(D_0076449C + 0xCB0) =
                    *(s32 *)(D_0076449C + 0xCB0) +
                    func_00243950(*(s32 *)(temp_16 + 0xA64));
                *(s32 *)(D_0076449C + 0xCB4) =
                    *(s32 *)(D_0076449C + 0xCB4) +
                    func_002439c0(*(s32 *)(temp_16 + 0xA64));
                var_16 = (u16)(func_00243a30(
                    *(s32 *)(temp_16 + 0xA64), &sp3C) & 0xFFFF);
                if ((sp3C != 1) &&
                    (*(u16 *)(arg0 + 0x80) != 0) &&
                    ((s32)(func_00231d70(0x64) & 0xFF) <
                     (s32)*(u8 *)(arg0 + 0x82))) {
                    var_16 = *(u16 *)(arg0 + 0x80);
                }
                temp_6 = var_16 & 0xFFFF;
                if (temp_6 != 0) {
                    var_7 = 0;
                    var_8 = 0;
                    base = D_0076449C;
                    while ((var_8 & 0xFFFF) < 3) {
                        entry = base + ((u16)var_8 * 4);
                        if (*(u16 *)(entry + 0xCD0) == temp_6) {
                            *(s16 *)(entry + 0xCD2) =
                                (s16)(*(s16 *)(entry + 0xCD2) + 1);
                            var_7 = 1;
                            break;
                        }
                        var_8 = (var_8 + 1) & 0xFFFF;
                    }
                    if (var_7 == 0) {
                        var_8_2 = 0;
                        base2 = D_0076449C;
                        while ((var_8_2 & 0xFFFF) < 3) {
                            temp_4_5 = var_8_2 & 0xFFFF;
                            temp_6_2 = temp_4_5 * 4;
                            slot = base2 + temp_6_2;
                            if (*(u16 *)(slot + 0xCD0) == 0) {
                                *(u16 *)(slot + 0xCD0) = var_16;
                                *(s16 *)(D_0076449C + temp_6_2 + 0xCD2) = 1;
                                *(s32 *)(D_0076449C + 0xCDC) = temp_4_5 + 1;
                                return;
                            }
                            var_8_2 = (var_8_2 + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
    }
}
