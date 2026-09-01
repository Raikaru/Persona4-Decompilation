/* measured: object 220B, window 224B, normalized_diff 0. Corrected func_0046d730 declaration to func_0046d730(void *, s32). The untried pre-jump trampoline initializes a named input local before the guard and assigns the loop counter after the guard, reproducing retail's entry branch target. */
void func_00115670(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct {
        f32 v[3];
    } S3f;
    s32 i;
    s32 input;
    u16 count;
    u8 *p;
    u8 *q;

    input = (s64)(s16)arg1;
    if (input < (s32)*(u16 *)(arg0 + 0x224)) {
        goto loop_entry_15670;
    }
    func_0046d730(D_005E4800, 0x4B7);
loop_entry_15670:
    i = input;
    goto loop_test_15670;
loop_body_15670:
    p = (u8 *)(arg0 + i * 12);
    *(S3f *)(p + 0x64) = *(S3f *)(p + 0x70);
    q = (u8 *)(arg0 + i * 2);
    *(u16 *)(q + 0x1E4) = *(u16 *)(q + 0x1E6);
    i += 1;
loop_test_15670:
    count = *(u16 *)(arg0 + 0x224);
    if (i < (s32)(count - 1)) {
        goto loop_body_15670;
    }
    p = shdSkill_addOff(count * 12, arg0);
    *(u16 *)(p + 0x5A) = 0;
    p = shdSkill_addOff(*(u16 *)(arg0 + 0x224) * 2, arg0);
    *(u16 *)(p + 0x1E2) = 0;
    *(u16 *)(arg0 + 0x224) = *(u16 *)(arg0 + 0x224) - 1;
}
