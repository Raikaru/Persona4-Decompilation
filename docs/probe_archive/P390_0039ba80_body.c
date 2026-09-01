/* COMPILE_ERROR: verify returned COMPILE_ERROR for all 149 rows while this body was live; no object/window/normalized_diff was produced. Classification: direct generated-C two-pass table initialization candidate; restored fallback immediately without further probing. */
u8 *func_0039ba80(u8 *arg0)
{
    u32 var_17;
    u32 var_17_2;
    u32 var_16;
    u32 var_18;
    u32 var_3;
    u8 *temp_16;
    extern u8 *func_0039bbd0(s32 arg0);
    extern void func_0039b720(u8 *arg0, u8 *arg1);

    var_3 = *(u32 *)(arg0 + 4);
    var_18 = 0;
    if (var_3 != 0) {
        var_17 = 0;
        do {
            temp_16 = (u8 *)(*(u8 **)(arg0 + 0) + var_17);
            if (*(s32 *)(temp_16 + 0xC) == 1) {
                *(u8 **)(temp_16 + 0x10) = func_0039bbd0(*(s32 *)temp_16);
                *(s32 *)(*(u8 **)(temp_16 + 0x10) + 0x30) = *(s32 *)(temp_16 + 8);
            }
            var_3 = *(u32 *)(arg0 + 4);
            var_18 += 1;
            var_17 += 0x14;
        } while (var_18 < var_3);
    }
    var_16 = 0;
    if (var_3 != 0) {
        var_17_2 = 0;
        do {
            func_0039b720((u8 *)(*(u8 **)(arg0 + 0) + var_17_2), arg0);
            var_16 += 1;
            var_17_2 += 0x14;
        } while (var_16 < *(u32 *)(arg0 + 4));
    }
    *(s32 *)(arg0 + 0xC) = 1;
    return arg0;
}
