/* object 252B / window 256B / normalized_diff 15 / differing offsets 26,29,30,34,36,38,40,42,96,97,98,99,100,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247 / classification register coloring plus global address materialization, callee relocation and positive-count guard shape; ruled out O1, schedule off, opt_propagation off, signed/reordered declarations, and alternate pointer widths. */

s32 func_00396940(s32 arg0, s32 arg1)
{
    s32 temp_2;
    u8 *temp_3;
    s32 var_4;
    s32 var_3;
    s32 temp_count;
    u8 *temp_2_2;
    u32 temp_7;
    u8 *temp_17;
    u8 *temp_16;

    temp_2 = iGpffffb5d8;
    temp_3 = (u8 *)(arg1 + temp_2);
    temp_17 = (u8 *)(arg0 + temp_2);
    temp_16 = *(u8 **)(temp_3 + 4);
    *(s32 *)temp_17 = *(s32 *)temp_3;
    if (temp_16 != NULL) {
        temp_7 = *(u32 *)temp_16;
        if (!(temp_7 & 1)) {
            temp_2_2 = (u8 *)func_00396fb0(*(u32 *)(temp_16 + 4), NULL, NULL,
                temp_7, *(u32 *)(*(u8 **)(temp_16 + 0x20) + 0x20));
            temp_count = *(s32 *)(temp_2_2 + 4);
            if (temp_count > 0) {
                var_4 = 0;
                var_3 = 0;
                do {
                    var_4 += 1;
                    *(s32 *)((u8 *)*(s32 **)(temp_2_2 + 0x10) + var_3 + 0xC) = 0;
                    *(s32 *)((u8 *)*(s32 **)(temp_2_2 + 0x10) + var_3 + 8) =
                        *(s32 *)((u8 *)*(s32 **)(temp_16 + 0x10) + var_3 + 8);
                    *(s32 *)((u8 *)*(s32 **)(temp_2_2 + 0x10) + var_3 + 4) =
                        *(s32 *)((u8 *)*(s32 **)(temp_16 + 0x10) + var_3 + 4);
                    *(s32 *)((u8 *)*(s32 **)(temp_2_2 + 0x10) + var_3) =
                        *(s32 *)((u8 *)*(s32 **)(temp_16 + 0x10) + var_3);
                    var_3 += 0x10;
                } while (var_4 < *(s32 *)(temp_2_2 + 4));
            }
            *(u32 **)(temp_17 + 4) = (u32 *)temp_2_2;
            *(s32 *)((u8 *)temp_2_2 + 0x14) = arg0;
        }
    }
    return arg0;
}
