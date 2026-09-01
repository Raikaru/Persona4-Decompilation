/* current remeasure: object 360B, window 368B, normalized_diff 10; differing byte offsets 6, 7, 10, 11, 12, 13, 14, 16, 18, 19. Classification: exact-size direct comparator with only initial load order differing (retail lh arg0, lh arg1, then global base; candidate lh arg0, global base, lh arg1); reordered assignments, declaration swaps, comma/nested evaluation, direct-global pointer form, and schedule-off probe ruled out; retained s32 vb, s32 va_mask, opt_common_subs off; restored fallback. */
#pragma opt_common_subs off
s32 func_002e6b20(s16 *arg0, s16 *arg1) {
    s16 ia;
    s16 ib;
    u8 *base;
    u8 *pa;
    u8 *pb;
    s32 vb;
    u16 va;
    s32 va_mask;
    ia = *arg0;
    base = *(u8 **)(D_00882F70[0] + 0x38);
    ib = *arg1;
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pa = base + ia * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pa = base + ia * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pa = base + ia * 0x30 + 0x14;
        break;
    }
    va = *(u8 *)(pa + 4);
    switch ((u32)*(s32 *)(base + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        pb = base + ib * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        pb = base + ib * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        pb = base + ib * 0x30 + 0x14;
        break;
    }
    vb = *(u8 *)(pb + 4);
    va_mask = va & 0xFFFF;
    if (vb < va_mask) {
        return 1;
    }
    return -(va_mask < vb);
}
#pragma opt_common_subs on
