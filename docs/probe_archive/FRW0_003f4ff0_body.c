/* object_size=80 window=80 normalized_diff=5 differing_offsets=4,8,12,16,20; classification=COP2 scheduling residual. Retail begins cfc2 $v1,$vi28 before sd $ra,16($sp), then orders li/lui/ori/stores; hard-register COP2 blocks reproduce all later words and keep the required COP2/VU0 asm policy, but MWCC emits sd before the inline-cfc2 block. */
void func_003f4ff0(void)
{
    extern void func_004176b0(void);
    extern void func_00418f78(s32 arg0);
    volatile s32 *base;

    base = (volatile s32 *)0x10000000;
    __asm__ volatile(
        "cfc2 $v1, $vi28\n"
        "ori $v1, $v1, 0x200"
        : : : "$v1", "memory");
    base[0x3c10 / 4] = 1;
    base[0x3810 / 4] = 1;
    base[0x3000 / 4] = 1;
    __asm__ volatile("ctc2 $v1, $vi28" : : : "$v1", "memory");
    __asm__ volatile(
        "cfc2 $v0, $vi28\n"
        "ori $v0, $v0, 0x2\n"
        "ctc2 $v0, $vi28"
        : : : "$v0", "memory");
    func_004176b0();
    func_00418f78(1);
}
