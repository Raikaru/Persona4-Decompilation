/* measured: object=92 window=88 normalized_diff=48; reverted to INCLUDE_ASM. */
void func_004e03b0(void) {
    s32 value;

    func_004e0380();
    value = D_0072B678;
    if (value == 0) {
        func_0043f9c8(&D_0072B680, 0, 0x6570);
    }
    D_0072B678 = value + 1;
    func_004e0398();
}
