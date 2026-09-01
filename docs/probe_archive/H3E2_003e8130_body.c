/* object 76B, window 80B, normalized_diff 24, differing offsets 4,6,7,8,10,11,12,13,14,15,18,19,20,21,23,24; ruled out typed float-pointer parameters, a named first-load temporary, schedule on/off, optimization levels 1/3, and no_branch_likely. */
// FUN_003E8130 NONMATCHING
u8 *func_003e8130(u8 *arg0, const f32 *arg1) {
    s32 temp_4;

    *(f32 *)(arg0 + 0x78) = arg1[0];
    *(f32 *)(arg0 + 0x7C) = arg1[1];
    temp_4 = *(s32 *)(arg0 + 4);
    if (temp_4 != 0) {
        func_003e9680((void *)temp_4);
    }
    return arg0;
}
