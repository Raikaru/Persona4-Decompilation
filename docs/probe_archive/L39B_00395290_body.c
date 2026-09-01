/* Rejected reconstruction archive: object 476B / window 544B / normalized_diff 339. */
u8 *func_00395290(register s32 arg0)
{
    u32 sp9C;
    u32 sp98;
    u32 sp94;
    u32 sp90;
    u32 sp8C;
    u32 sp88;
    u32 sp84;
    s32 scratch[4];
    u8 *temp_2;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 var_16;

    if (func_003df050(arg0, 1, (s32 *)&sp9C, (s32 *)&sp98) == 0) goto ret0;
    if (func_003df360(arg0, (s32 *)&sp94, 4) == 0) goto ret0;
    if (func_003df360(arg0, (s32 *)&sp90, 4) == 0) goto ret0;
    if (func_003df360(arg0, (s32 *)&sp8C, 4) == 0) goto ret0;
    if (func_003df360(arg0, (s32 *)&sp88, 4) == 0) goto ret0;
    if (sp94 < 0x101) {
        temp_2 = func_00394fd0(sp8C);
        if (temp_2 != NULL) {
            if (sp8C > 0) {
                var_19 = 0;
                var_16 = 0;
outer:
                if (func_003df360(arg0, (s32 *)&sp84, 4) == 0) goto ret0;
                if (sp84 != 0) {
                    if (func_00395100((s32)temp_2, var_19, sp84) == 0) goto ret0;
                    var_18 = *(s32 *)(*(s32 *)(temp_2 + 4) + var_16 + 4);
                    if (sp84 > 0) {
                        var_17 = 0;
inner:
                        if (func_003df300(arg0, var_18, 0x10) == 0) goto ret0;
                        if (func_003df360(arg0, (s32 *)(var_18 + 0x10), 4) == 0) goto ret0;
                        var_17 += 1;
                        if (var_17 < sp84) {
                            var_18 += 0x14;
                            goto inner;
                        }
                    }
                }
                var_19 += 1;
                var_16 += 8;
                if (var_19 < sp8C) goto outer;
            }
            return temp_2;
        }
    } else {
        scratch[2] = 0x122;
        scratch[3] = func_003df590(0x80000004);
        func_003df4d0(&scratch[2]);
    }
ret0:
    return NULL;
}
