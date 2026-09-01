/* object_size=220 window=240 normalized_diff=100 differing_offsets=48,49,50,51,54,55,70,72,74,75,76,77,78,79,94,102 classification=undersized near-miss; ruled_out=movz/movn/COP1 accumulator/MMI/tail-jump floors absent; callback table kept as typed pointer-to-array and D_008873D4 absolute array, raw call sequence reproduced */
s32 func_003eb0d0(s32 arg0, u8 **arg1)
{
    extern s32 func_003de110(s32 arg0);
    extern s32 (*D_008873D4[])(void);
    extern void (*D_008873AC[])(s32 arg0, u8 *arg1);
    extern s32 D_008872E0[];
    void (**callbacks)(s32 arg0, u8 *arg1);
    s32 temp_17;
    u8 *var_18;

    temp_17 = arg0 + D_008873D4[0]();
    var_18 = *(u8 **)((u8 *)D_008872E0 + iGpffffb7c8 + 0x21c);
    if (var_18 != NULL) {
        callbacks = D_008873AC;
        do {
            callbacks[0](temp_17, var_18);
            if (func_003de110(arg0) != 0) {
                *arg1 = var_18;
                return 0;
            }
            callbacks[0](temp_17, var_18 + 0x14);
            if (func_003de110(arg0) != 0) {
                *arg1 = var_18 + 0x14;
                return 0;
            }
            var_18 = *(u8 **)(var_18 + 0x30);
        } while (var_18 != NULL);
    }
    return arg0;
}
