/* Lane119c39 2026-09-03 (cw3.0.1b119 unit): object 336B / window 368B,
   57 real differing words. The first allocation and self-pointer store match,
   but the loop body compacts to a single base register (v1) with a0/a1/a2/a3
   for var_7/var_6/var_5/var_4, while retail reloads temp_20->unk10 three times
   and schedules the unconditional 0xC/0x4 stores into branch delay slots.
   Object size is 32 bytes shorter than retail, so the source shape is not the
   one MWCC b119 used here. Not installed. */
extern s32 iGpffffb5dc;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 func_003d5790(s32, s32);

u8 *func_00396fb0(s32 arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 *var_4;
    s32 *var_5;
    s32 var_6;
    s32 var_7;
    u8 *temp_20;
    u8 *temp_2;
    u8 *base;

    temp_20 = (u8 *)jtbl_008873E8[4]((u32)iGpffffb5dc, 0x3011e);
    *(s32 *)(temp_20 + 0x20) = func_003d5790(arg0, arg4);
    *(s32 *)(temp_20 + 0) = arg3;
    *(s32 *)(temp_20 + 4) = arg0;
    *(s32 *)(temp_20 + 0x14) = 0;
    if (arg3 & 2) {
        *(s32 *)(temp_20 + 8) = 0;
        *(u8 **)(temp_20 + 0xC) = NULL;
    } else {
        temp_2 = (u8 *)jtbl_008873E8[0]((arg0 << 6) + 0xF, 0x3011e);
        *(s32 *)(temp_20 + 8) = (s32)(((u32)temp_2 + 0xF) & ~0xF);
        *(u8 **)(temp_20 + 0xC) = temp_2;
    }
    *(u8 **)(temp_20 + 0x10) = (u8 *)jtbl_008873E8[0](arg0 * 0x10, 0x3011e);
    var_7 = 0;
    if (arg0 > 0) {
        var_6 = 0;
        var_5 = arg2;
        var_4 = arg1;
        do {
            base = *(u8 **)(temp_20 + 0x10) + var_6;
            if (arg2 != NULL) {
                *(s32 *)base = *var_5;
            }
            if (arg1 != NULL) {
                *(s32 *)(base + 8) = *var_4;
            }
            *(s32 *)(base + 0xC) = 0;
            *(s32 *)(base + 4) = var_7;
            var_7 += 1;
            var_6 += 0x10;
            var_5 += 1;
            var_4 += 1;
        } while (var_7 < arg0);
    }
    *(u8 **)(temp_20 + 0x18) = temp_20;
    return temp_20;
}
