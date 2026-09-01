/* object 672B/window 672B, normalized_diff 271, differing offsets 117,158,182,186,190,194,202,205,209,222,233,234,246,290,293,294; deficit/surplus 0 instructions; classification saved-register/lifetime and call-materialisation order; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, EE-gcc sd/sq floor; prologue saved s8/s7/s6/s5/s4/s3/s2/s1/s0 (9), args (s32,s32); s128 count and narrow s16 fields measured, no match. */
// FUN_00277BE0
void func_00277be0(s32 arg0, s32 arg1)
{
    u8 *obj;
    u8 *base;
    u8 *handle;
    u32 bits;
    u32 mask;
    s32 *elem;
    s32 result2;
    s32 i;
    s128 count;
    s32 saved;
    s32 flags;

    obj = D_00881808[arg0].unk0;
    if (obj == NULL)
        func_0046d730(D_0063BE10, 0x686);
    handle = (u8 *)func_00278de0((s32)obj, arg1);
    if (*(s32 *)handle != 1)
        func_0046d730(D_0063BE10, 0x68A);
    base = obj + 0x3C;
    if (*(s32 *)(obj + 0x40) != 0) {
        func_00271b70(*(s32 *)(obj + 0x40));
        *(s32 *)(base + 4) = 0;
    }
    handle = *(u8 **)(handle + 4);
    bits = *(u32 *)(base + 8);
    count = *(s16 *)(handle + 0x1A);
    elem = (s32 *)(handle + 0x20);
    mask = 0;
    i = 0;
    while ((s32)i < (s32)count) {
        if (bits & 1U) {
            bits >>= 1;
        } else {
            func_002748e0(*elem, 2, 0);
            if (func_00274650(8) != 0)
                mask |= 1U << i;
        }
        i++;
        elem++;
    }
    *(u32 *)(base + 8) = *(u32 *)(base + 8) | mask;
    i = func_00279fd0(*(s16 *)(handle + 0x1A), *(u32 *)(base + 8));
    func_0027b750(arg0, 0, i);
    func_0027bb60(arg0);
    bits = func_0027b6e0(arg0, 0);
    mask = func_0027b6e0(arg0, 1);
    result2 = func_0027b6e0(arg0, 2);
    func_00279ce0(obj + 0x94);
    if (*(s32 *)(obj + 8) != 0)
        func_002738a0(*(s32 *)(obj + 8));
    saved = iGpffffb4b0;
    if (saved == 0)
        iGpffffb4b0 = 0x7B;
    *(s32 *)(base + 4) = (s32)func_0027a010(
        (u32 *)(handle + 0x20),
        *(s16 *)(handle + 0x1A),
        *(u32 *)(base + 8),
        bits, mask, *(s32 *)(obj + 0xC), result2, 0);
    iGpffffb4b0 = saved;
    func_0027bbc0(arg0);
    *(s16 *)(base + 0x12) = (s16)i;
    flags = *(s32 *)obj & ~0x38;
    *(s32 *)obj = flags;
    flags |= 0x10;
    *(s32 *)obj = flags;
    flags &= ~0xC00;
    *(s32 *)obj = flags;
    *(s32 *)obj = flags | 0x400;
    *(s16 *)(base + 0xC) = 1;
    *(s32 *)base = arg1;
}
