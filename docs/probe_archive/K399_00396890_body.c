/* object 156B / window 176B / normalized_diff 75; differing offsets begin 0x20,0x28-0x3c,0x4c-0x60,0x64-0x9c. */
/* Ruled out: direct m2c field expansion, swapped counter/pointer lifetimes, do-while and explicit goto loop shapes, count >0 / 0<count / count<1 guards, scoped optimization_level 1, and scoped schedule on. */
s32 func_00397120(u8 *arg0);
s32 func_00396890(s32 arg0)
{
    s32 var_3;
    s32 var_5;
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = (u8 *)(arg0 + iGpffffb5d8);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        var_3 = 0;
        var_5 = 0;
        if (*(s32 *)(temp_4 + 4) > 0) {
            do {
                var_3 += 1;
                *(s32 *)(*(u8 **)(temp_4 + 0x10) + var_5 + 0xC) = 0;
                var_5 += 0x10;
            } while (var_3 < *(s32 *)(temp_4 + 4));
        }
        if (*(s32 *)(temp_4 + 0x14) == arg0) {
            func_00397120(temp_4);
        }
        *(u8 **)(temp_16 + 4) = NULL;
    }
    *(s32 *)temp_16 = -1;
    return arg0;
}
