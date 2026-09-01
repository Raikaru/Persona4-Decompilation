/* candidate: object 396B/window 416B, normalized_diff 294, first differing offsets 4,13,18,22,26,30,34,38; instruction deficit 5; classification control-flow/register coloring; ruled out movz/movn, COP1 MAC, standalone MMI, framed tail-jump, ee-gcc sd/sq floors. Prologue: 0 saved s registers, args (u8 *arg0, s32 arg1); no callees. */
s32 func_001f0dd0(u8 *arg0, s32 arg1)
{
    s32 result;
    s32 one;
    u8 *target;
    s32 innerCount;
    s32 n;
    u16 i;
    u8 *entry;
    u16 j;
    u8 *sub;
    s32 mask;

    result = 0;
    if (arg1 == 0) {
        goto path_zero;
    }
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    one = 1;
    mask = 0x500;
    goto outer_test_one;
outer_one:
    entry = arg0 + ((u16)i * 4);
    target = *(u8 **)(entry + 0x38);
    if (*(s32 *)(target + 0xE4) != 0) {
        result = 0;
        goto done;
    }
    if ((*(u16 *)(target + 0xDC) & mask) != 0) {
        result = 0;
        goto done;
    }
    if (result != 0) {
        goto outer_step_one;
    }
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test_one;
inner_one:
    entry = target + ((u16)j << 5);
    if (*(s32 *)(entry + 0xF0) < 0) {
        result = one;
        goto outer_step_one;
    }
    j = (j + 1) & 0xFFFF;
inner_test_one:
    if ((j & 0xFFFF) < innerCount) {
        goto inner_one;
    }
outer_step_one:
    i = (i + 1) & 0xFFFF;
outer_test_one:
    if ((i & 0xFFFF) < n) {
        goto outer_one;
    }
    goto done;

path_zero:
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test_zero;
outer_zero:
    entry = arg0 + ((u16)i * 4);
    target = *(u8 **)(entry + 0x38);
    if ((*(u16 *)(target + 0xDC) & 0x106) != 0) {
        result = 1;
        goto done;
    }
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test_zero;
inner_zero:
    sub = target + ((u16)j << 5);
    if (*(s32 *)(sub + 0xF0) == 0) {
        if (*(s32 *)(sub + 0xF8) != 0) {
            result = 1;
            goto done;
        }
    } else if (*(s32 *)(sub + 0xF0) < 0) {
        result = 1;
        goto done;
    }
    j = (j + 1) & 0xFFFF;
inner_test_zero:
    if ((j & 0xFFFF) < innerCount) {
        goto inner_zero;
    }
    i = (i + 1) & 0xFFFF;
outer_test_zero:
    if ((i & 0xFFFF) < n) {
        goto outer_zero;
    }

done:
    return result;
}
