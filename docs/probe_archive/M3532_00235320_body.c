/* Archived high-nd candidate from W8DatCalc.
   Function: func_00235320; retail window 512B; candidate object 496B; nd 361; status MISMATCH.
   Recipe: ported the generated/code1_0023.c M2C candidate, then split the initial threshold into var_17 and var_19 so the loop result can occupy var_17 while the threshold remains live. Kept s64 sign-extension casts, u64 loop counter, direct iGpffffb3c4 table indexing, and the func_002332a0 call.
   Register/prologue map: retail frame 0x60, saved s16(arg0), s17(loop result), s18(temp_18), s19(threshold), s20(loop counter); candidate frame 0x70, saved s16..s21 with arg0 in s21 and an extra live saved value, so the prologue diverges at offset 0.
   Ruled out in this probe: generated candidate unchanged (object 444B, nd 307); threshold split (object 496B, nd 361); no pragma or volatile/alias/inline-asm workaround retained. Restore to bare INCLUDE_ASM above nd 25.
*/
// FUN_00235320
s64 func_00235320(u8 *arg0)
{
    s32 temp_18;
    s32 temp_3;
    s32 temp_4;
    s64 var_17;
    s64 var_19;
    s64 var_2;
    s64 var_2_2;
    u64 var_20;

    var_17 = 3;
    if (*(u16 *)arg0 & 4) {
        if ((s32)*(u16 *)(arg0 + 2) >= 0x150) {
            func_0046d730(D_00635938, 0x6D8);
        }
        if (*(u16 *)(iGpffffb3c4 + *(u16 *)(arg0 + 2) * 0x3C) & 0x1000) {
            var_17 = (s64)((((s64)var_17 << 0x38) >> 0x38) * 2);
        }
    }
    var_19 = (s8)var_17;
    var_20 = 0;
    while (var_20 < 0x10) {
        temp_18 = var_20 & 0xFF;
        if (temp_18 >= 0x18) {
            func_0046d730(D_00635938, 0x4C1);
        }
        if (temp_18 < 0x10) {
            var_2 = (s64)(s32)func_002332a0(arg0, var_20 & 0xFF);
        }
        else {
            var_2 = (s64)((((*(s32 *)(arg0 + 0x14) & (1 << temp_18)) != 0) << 0x38) >> 0x38);
        }
        var_17 = (s8)var_2;
        if (temp_18 >= 0x18) {
            func_0046d730(D_00635938, 0x42A);
        }
        temp_4 = var_20 & 0xFF;
        temp_3 = (temp_4 >> 1) & 0xFFFF;
        if (temp_4 & 1) {
            var_2_2 = (s64)((s64)((s32)*(u8 *)(arg0 + (temp_3 & 0xFFFF) + 0x24) >> 4) << 0x38) >> 0x38;
        }
        else {
            var_2_2 = (s64)((*(u8 *)(arg0 + (temp_3 & 0xFFFF) + 0x24) & 0xF) << 0x38) >> 0x38;
        }
        if (((s64)(var_17 << 0x38) >> 0x38) != 0 &&
            ((s64)(((s64)(var_2_2 << 0x38) >> 0x38) << 0x38) >> 0x38) >=
            ((s64)(var_19 << 0x38) >> 0x38)) {
            return (s64)(var_20 << 0x38) >> 0x38;
        }
        var_20 += 1;
    }
    return -1;
}
