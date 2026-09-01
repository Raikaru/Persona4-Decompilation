// Candidate archive for func_003ceeb0.
// Simple C loop probe; object 160B/window 448B, normalized_diff 317. Retail uses an eight-element MMI-unrolled loop; candidate was not retained.
s32 func_003ceeb0(u8 *arg0) {
    s32 var_16;
    u8 *temp_4;
    u8 *var_5;
    u32 temp_3;
    u32 var_6;
    u8 *temp_7;

    var_16 = 0;
    if ((*(s32 *)(func_003c9c20((u32)arg0) + 8) & 0x01000000) != 0) {
        var_16 = 0x10;
        temp_4 = *(u8 **)(arg0 + iGpffffb728);
        temp_3 = *(u32 *)temp_4;
        var_6 = 0;
        var_5 = temp_4;
        if (temp_3 != 0) {
            do {
                temp_7 = *(u8 **)(var_5 + 4);
                var_6 += 1;
                var_5 += 4;
                var_16 += *(s32 *)(temp_7 + 8) -
                           (*(s32 *)(temp_7 + 0x20) - (s32)temp_7) + 8;
            } while (var_6 < temp_3);
        }
    }
    return var_16;
}
