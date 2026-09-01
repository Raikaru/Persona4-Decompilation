/* func_003e43c0 best archived attempt: object 84B/window 96B, normalized_diff 19.
 * The opt_propagation-off/schedule-on probe fixed absolute D_008872E0 addressing
 * but callback-address materialization order and the final counter update still
 * differed from retail. Restored to INCLUDE_ASM in the translation unit. */

s32 func_003e43c0(s32 arg0, s32 arg1) {
    u8 *temp_5;

    D_00764890 = arg1;
    temp_5 = (u8 *)D_008872E0 + D_00764890;
    *(void **)(temp_5 + 0x8) = (void *)func_003e3dc0;
    *(void **)(temp_5 + 0xC) = (void *)func_003e3d00;
    *(void **)(temp_5 + 0x10) = (void *)func_003e3f00;
    *(void **)(temp_5 + 0x14) = (void *)func_003e3e60;
    D_0076489C += 1;
    return arg0;
}
