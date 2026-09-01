/* object_size=532 window=480 normalized_diff=415 differing_offsets=0x0,0x4,0x8,0xA,0xC,0xE,0x10,0x12,0x14,0x16,0x18,0x1A,0x1C,0x1E,... classification=oversized/wrong declaration environment and loop/register shape; ruled_out=retail window has no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; corrected block-scope declarations for func_00106600, func_0010a900, func_0010cf40, func_00202d20, func_00232aa0 and iGpffffb3b8; object exceeded window so archived immediately without further probes.
*/
void func_00207140(u16 *arg0, u8 *arg1)
{
    extern u8 func_00106600(s64 arg0);
    extern s32 func_0010a900(u16 arg0);
    extern u16 func_0010cf40(s32 arg0, s64 arg1);
    extern void func_00202d20(u8 *arg0, s16 arg1, s16 arg2);
    extern s32 func_00232aa0(s32 arg0);
    extern u8 *iGpffffb3b8;
    s16 temp_5;
    s16 var_17;
    s16 var_18_2;
    s32 temp_19;
    s32 temp_4_2;
    s32 var_17_2;
    s64 temp_19_2;
    s64 temp_3_2;
    s64 var_18;
    u8 *temp_19_3;
    u8 *temp_3;
    u8 *temp_4;

    if (func_00106330(0x3C) != 0) {
        temp_3 = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (temp_3 != NULL) {
            func_00202d20((u8 *)arg0, *(s16 *)(temp_3 + 2),
                          *(s16 *)temp_3);
        }
    }
    *arg0 |= 4;
    *arg0 |= 2;
    var_17 = 0;
    temp_4 = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) == 0) {
        temp_19 = func_0010a900(*(u16 *)(temp_4 + 0xA4));
        var_18 = 0;
        while ((var_18 & 0xFFFF) < 8) {
            temp_5 = func_0010cf40(
                          temp_19,
                          (s64)(var_18 << 0x30) >> 0x30) & 0xFFFF;
            if ((temp_5 != 0) && (temp_5 < 0x1B8) &&
                (*(u8 *)(iGpffffb3b8 + temp_5 * 0x28 + 1) & 2)) {
                *(s16 *)(arg1 + (var_17 & 0xFFFF) * 2 + 0x194) = temp_5;
                var_17 = (var_17 + 1) & 0xFFFF;
            }
            var_18 = (var_18 + 1) & 0xFFFF;
        }
    }
    *(s16 *)(arg1 + 0x1A4) = var_17;
    var_18_2 = 0;
    var_17_2 = 0;
    while ((var_17_2 & 0xFFFF) < 0x100) {
        temp_19_2 = (var_17_2 & 0xFFFF) + 0x300;
        if ((func_00106600((s64)(temp_19_2 << 0x30) >> 0x30) != 0) &&
            (func_00232aa0(temp_19_2 & 0xFFFF) != 0)) {
            temp_3_2 = (var_17_2 & 0xFFFF) + 0x300;
            temp_19_3 = arg1 + (var_18_2 & 0xFFFF) * 4;
            *(s16 *)(temp_19_3 + 0x1A6) = (s16)temp_3_2;
            *(s8 *)(temp_19_3 + 0x1A8) =
                func_00106600((s64)(temp_3_2 << 0x30) >> 0x30);
            var_18_2 = (var_18_2 + 1) & 0xFFFF;
        }
        var_17_2 = (var_17_2 + 1) & 0xFFFF;
    }
    *(s16 *)(arg1 + 0x5A6) = var_18_2;
}
