/* object 260 / window 256 / normalized_diff 169; differing offsets 0x14-0xfc; oversized 4 bytes: conditional branch orientation, packed s64 value expression, switch case address/materialisation order; classification guard/control-flow plus conversion expression; ruled out initial nested-if and named-value spelling. */
s32 func_0039ab20(s32 arg0, s32 arg1, s32 arg2, s64 arg3)
{
    s32 state;
    s32 mode;
    u8 *base;
    u8 *entry;
    u64 value;

    base = *(u8 **)(arg0 + iGpffffb5e0);
    state = *(s32 *)(base + 0x80);
    if (state == 3) {
        if (arg1 == 2) goto mode_one;
    }
    if (state == 6) goto mode_one;
    mode = 0;
    goto dispatch;
mode_one:
    mode = 1;
dispatch:
    switch (arg2) {
    case 1:
        entry = base + (mode << 6);
        value = (u64)(arg3 & 0xFF) | ((((u64)(arg3 & 0xFF000000) << 32) >> 32) << 8);
        *(u64 *)(entry + 0x28) = value;
        if (arg1 == 4) { *(s32 *)(entry + 4) = 0; *(s32 *)(entry + 8) = 0; }
        return 1;
    case 2:
        *(u64 *)(base + (mode << 6) + 0x30) = (u64)(u32)arg3;
        return 1;
    case 3:
        *(u64 *)(base + (mode << 6) + 0x38) = (u64)(u32)arg3;
        return 1;
    default:
        return 0;
    }
}
