/* object_size=236 window=240 normalized_diff=164 differing_word_offsets=0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,84,88,92,108,112,120,128,136,140,144,148,152,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228; ruled out mask-CSE alternatives, loop while/for/goto shapes, u16 versus masked target, local declaration order, and opt_common_subs off. Residual is the saved-register/mask-CSE cascade; no compliant exact C body found. */
// FUN_00247DD0 NONMATCHING
s32 func_00247dd0(s32 arg0) {
    s32 i;
    s32 target;
    u8 *base;

    i = 0;
    target = arg0 & 0xFFFF;
    while (i < 0x1F) {
        base = D_00881480[0];
        if ((u32)(i & 0xFFFF) >= *(u32 *)(base + 4)) {
            func_0046d730(D_006359D0, 0x4C);
        }
        if ((*(s32 *)(base + (i & 0xFFFF) * 100 + 0xC) & 4) &&
            (target == (func_002489c0(i & 0xFFFF) & 0xFFFF)) &&
            (func_001077f0(i & 0xFFFF) != 0)) {
            return i & 0xFFFF;
        }
        i += 1;
    }
    return 0;
}
