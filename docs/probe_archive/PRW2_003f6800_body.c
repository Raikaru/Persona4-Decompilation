/* object_size=152 window=160 normalized_diff=80 differing_offsets=0,12,50,52,54,55,60,61,62,63,64,65,66,67,69,70; classification=near-miss/control-flow layout and float clamp; corrected no global declarations. Ruled out: movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, mixed-unit sd/sq floor; no_branch_likely probe object160/160 nd120. */
/* measured no_branch_likely on around body. */
s32 *func_003f6800(s32 *arg0, f32 fparg0)
{
    s32 temp_6;
    s32 var_3;
    u8 *temp_4;
    u8 *temp_6_2;

    if (arg0 == NULL) {
        goto zero;
    }
    temp_6 = *arg0;
    if (temp_6 == 0) {
        goto zero;
    }
    var_3 = (s32)(16.0f * fparg0);
    if (var_3 < -0x800) {
        var_3 = -0x800;
    } else if (var_3 >= 0x800) {
        var_3 = 0x7FF;
    }
    temp_6_2 = (u8 *)(temp_6 + iGpffffb938);
    *(u16 *)(temp_6_2 + 0x14) &= 0xF000;
    temp_4 = (u8 *)(*arg0 + iGpffffb938);
    *(u16 *)(temp_4 + 0x14) |= var_3 & 0xFFF;
    return arg0;
zero:
    return NULL;
}
