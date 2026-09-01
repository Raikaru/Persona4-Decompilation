// measured: object_size 248, window 256, best normalized_diff 92; differing offsets clustered from table-address materialization and switch/callee control-flow; ruled out m2c direct expansion, s32/s64/s8 result locals, s16/u8 argument widths, callee cast widths, switch/if/goto guard forms, declaration/order variants, named pointer/temp address forms, and u32 address arithmetic. Retail uses a full 256-byte framed function; remaining reconstruction is beyond the wave's polish budget.
s8 func_00110960(s32 arg0, u32 arg1) {
    s32 var_16;
    s8 var_17;
    u32 temp;
    var_16 = 0;
    var_17 = -1;
    if ((arg0 == func_00123b10()) && (arg1 == func_00123b40())) {
        var_17 = func_00123ae0();
    }
    if (var_17 == -1) {
        if (arg1 < 6) {
            switch (arg1) {
            case 0:
            case 1: var_16 = 0; break;
            case 2:
            case 3:
            case 4:
            case 5: var_16 = 1; break;
            }
        }
        temp = (u32)&D_005E3A02 + arg0 * 6;
        temp += var_16 * 2;
        var_17 = *((s8 *)temp);
    }
    return var_17;
}
