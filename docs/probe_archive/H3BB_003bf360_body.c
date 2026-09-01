/* func_003bf360 best plain-C attempt: object 100B/window 112B, normalized_diff 43. */
/* Probed with schedule on, opt_common_subs off, and opt_propagation off. */
u8 *func_003bf360(u8 *arg0, s32 *arg1) {
    struct A {
        s32 value;
    };
    struct B {
        s32 value;
    };

    ((struct A *)arg1)->value += 0xC;
    ((struct B *)arg1)->value += 0x1C;
    ((struct B *)arg1)->value += func_003e3370(D_0070AF70, (s32)arg0) + 0xC;
    return arg0;
}
