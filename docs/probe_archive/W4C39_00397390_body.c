/* Best loop/callback probe: object 176B, retail window 208B, normalized_diff 39.
 * Prologue/frame and callback call order are recovered; residual is entry guard,
 * register allocation, loop update ordering, and remaining callback/body layout.
 */
u8 *func_00397390(u8 *arg0)
{
    extern void func_003e9680(u8 *arg0);
    extern u8 *func_003e9af0(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2);
    extern s32 func_00397470(u8 *arg0);
    extern s32 func_00396680(s32 arg0, u8 *arg1);
    u8 *temp_18;
    s32 *temp_21;
    s32 temp_20;
    s32 var_17;
    s32 var_16;

    temp_18 = *(u8 **)(arg0 + 0x14);
    var_17 = 0;
    var_16 = 0;
    while (var_17 < *(s32 *)(arg0 + 4)) {
        temp_21 = (s32 *)(*(u8 **)(arg0 + 0x10) + var_16);
        temp_20 = *temp_21;
        if (temp_20 == func_00397470(temp_18))
            temp_21[3] = (s32)temp_18;
        var_17 += 1;
        var_16 += 0x10;
    }
    func_003e9680(temp_18);
    func_003e9af0(temp_18, (s32 (*)(u8 *, s32))func_00396680, (s32)arg0);
    return arg0;
}
