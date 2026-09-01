/* candidate: object 436B/window 432B, normalized_diff 254, instruction surplus 1; classification control-flow/register coloring and aggregate spill; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, ee-gcc sd/sq floors. Prologue: 2 saved s registers ($s1,$s0); arg list (u8 *arg0); declarations block scope: base/unit/pointer/state/value union/count/i. */
// FUN_001F1030
s32 func_001f1030(u8 *arg0)
{
    u8 *base;
    u8 *unit;
    u8 *pointer;
    u8 state;
    union {
        s32 whole;
        u8 byte;
    } value;
    u16 count;
    s32 i;

    base = *(u8 **)(arg0 + 0x30);
    state = *(u8 *)(base + 0xA2);
    if ((*(u16 *)(arg0 + 0x1A) & 1) != 0) {
        pointer = *(u8 **)(base + 0xA64);
        if (pointer != NULL && func_00232710((s32)pointer, 0x100) != 0) {
            if ((state & 0xFF) == 0) {
                value.whole = 1;
            } else {
                value.whole = 0;
            }
            state = value.byte;
        }
    }
    count = *(u16 *)(arg0 + 0x6A);
    if ((s32)count < 2) {
        if (count != 1) {
            return 0;
        }
        unit = *(u8 **)(arg0 + 0x38);
        if ((*(u16 *)(unit + 0x1A) & 1) == 0) {
            return 0;
        }
        base = *(u8 **)(unit + 0x30);
        if (*(u8 *)(base + 0xA2) != (state & 0xFF)) {
            return 0;
        }
        i = 0;
        goto single_test;
    single_loop:
        if ((*(u16 *)(unit + ((u16)i << 5) + 0x10E) & 0x20) != 0) {
            return 1;
        }
        i = (i + 1) & 0xFFFF;
    single_test:
        if ((i & 0xFFFF) < *(u8 *)(unit + 0xD9)) {
            goto single_loop;
        }
        return 0;
    }

    i = 0;
    goto many_test;
many_loop:
    unit = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    if ((*(u16 *)(unit + 0x1A) & 1) != 0 &&
        *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) != (state & 0xFF)) {
        return 0;
    }
    i = (i + 1) & 0xFFFF;
many_test:
    if ((i & 0xFFFF) < count) {
        goto many_loop;
    }
    return 1;
}
