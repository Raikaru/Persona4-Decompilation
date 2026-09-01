/* measured: ee-gcc2.96 -O2 -G0 object 52/56 bytes, normalized_diff 27; reverted to INCLUDE_ASM. */
s32 func_00431ae8(s32 arg0) {
    extern s32 D_008968E0[];
    extern void func_00421670(s32, s32);
    if (arg0 <= 0) {
        return 0x81010016;
    } else {
        func_00421670(D_008968E0[0], arg0);
        return 0;
    }
}
