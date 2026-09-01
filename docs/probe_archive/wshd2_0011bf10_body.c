/* obj 620B / window 624B / normalized_diff 19 / differing offsets 292,296,300,304,308,312,620(tail); probes: field/constant locals, integer vs 771.0f spellings, split expressions, address-domain forms, thirteen pragma wrappers, declaration and assignment order. */
void func_0011bf10(u8 *arg0)
{
    u8 *w;
    s32 flags;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 state;
    u16 t7;
    Vec2f v2;
    Vec2f v;
    f32 ret;

    w = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(w + 0x534);
    if ((flags & 1) != 0 && (flags & 4) == 0 && (flags & 0x400000) == 0) {
        t1 = flags | 4;
        *(s32 *)(w + 0x534) = t1;
        t2 = t1 & ~2;
        *(s32 *)(w + 0x534) = t2;
        t3 = t2 & ~0x800;
        *(s32 *)(w + 0x534) = t3;
        t4 = t3 & ~0x1000;
        *(s32 *)(w + 0x534) = t4;
        t5 = t4 & ~0x2000;
        *(s32 *)(w + 0x534) = t5;
        t6 = t5 & ~0x4000;
        *(s32 *)(w + 0x534) = t6;
        *(s8 *)(w + 0x88) = -1;
        *(s32 *)(w + 0x444) = 0xC3E10000;
        state = *(s32 *)(w + 0x52C);
        switch (state) {
        case 0:
            func_0045af60(0, 1, 0, 4);
            break;
        case 1:
        case 3:
        case 2:
        case 4:
            break;
        default:
            func_0046d730(D_005E4868, 0xCCC);
            break;
        }
        *(u16 *)(w + 0x508) = 0;
        *(u8 *)(w + 0x504) = *(u8 *)(w + 0x505);
        *(u8 *)(w + 0x506) = 0xFF;
        func_0011aaa0(w, 5);
        v.x = 771.0f + *(f32 *)(w + 0x4FC);
        v.y = -59.0f + *(f32 *)(w + 0x500);
        ret = func_0011de80(*(u8 **)(w + 0x4F8), &v2);
        if (ret == 0.0f || ret == 1.0f) {
            v2.x = 131.0f + *(f32 *)(w + 0x4FC);
            v2.y = -59.0f + *(f32 *)(w + 0x500);
            func_0011e2b0(*(u8 **)(w + 0x4F8), &v2, &v);
            func_0011e370(*(u8 **)(w + 0x4F8));
        } else {
            func_0011e2b0(*(u8 **)(w + 0x4F8), &v2, &v);
        }
        flags = *(s32 *)(w + 0x534);
        if ((flags & 0x80000) != 0) {
            t7 = *(u16 *)(w + 0x458);
            if ((t7 & 2) == 0) {
                if ((t7 & 1) == 0) {
                    *(s32 *)(w + 0x534) = flags & ~0x80000;
                } else {
                    *(u16 *)(w + 0x45A) = 0;
                    *(u16 *)(w + 0x458) |= 2;
                }
            }
        }
    }
}
