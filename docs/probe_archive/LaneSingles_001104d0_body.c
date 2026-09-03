/* object 144B, retail window 176B, normalized_diff 40; differing byte offsets 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64, 0x68, 0x6C, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84, 0x88; classification: register-colouring, constant-parking, and loop-shape residual. LaneSingles 2026-09-03 attempts: if+goto no table (this body, nd 40); do-while with table pointer (nd 42); opt_propagation off with table/mod (nd 44); declaration-order swap (nd 43). Retail keeps the 0xC divisor in $a3, the D_005E45E0 base in $a0, the day remainder in $t3, the month in $t4, and the loop test at the bottom; MWCC b210 parks the day in $t1, month in $t0/$t2, and reloads the table base each iteration. */
void func_001104d0(s32 seed, s32 *month, s32 *day)
{
    s32 temp_8;
    s32 temp_9;
    s32 var_10;
    s32 var_11;
    s32 var_12;

    var_11 = seed % 0x16D;
    var_12 = 3;
    var_10 = 0;
loop_5:
    if (var_10 < 0xC) {
        temp_9 = var_12 + 1;
        temp_8 = temp_9 - 1;
        if (var_11 >= D_005E45E0[temp_8 % 12]) {
            var_11 -= D_005E45E0[temp_8 % 12];
            var_12 = temp_9;
            if (temp_9 >= 0xC) {
                var_12 = 0;
            }
            var_10 += 1;
            goto loop_5;
        }
    }
    *month = var_12 + 1;
    *day = var_11 + 1;
}
