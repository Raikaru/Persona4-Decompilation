// Candidate archive for func_003c4cf0.
// Explicit duplicate-filtering/serialization loops with schedule and no_branch_likely; object 624B/window 688B, normalized_diff 492. Candidate was reverted to INCLUDE_ASM.
u8 *func_003c4cf0(u8 *arg0, s32 arg1) {
    extern s32 func_003c47c0(s32 arg0);
    extern s32 func_003c4820(s32 arg0, s32 arg1);
    extern s32 func_003deff0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003df240(s32 arg0, void *arg1, s32 arg2);
    s32 sp6C;
    s32 *base;
    s32 *cursor;
    s32 *target;
    s32 temp_count;
    s32 total;
    s32 i;
    s32 offset;
    s32 found;
    s64 wide;

    temp_count = *(s32 *)(arg0 + 4);
    i = 0;
    offset = 0;
    total = temp_count * 4 + 0x10;
    if (temp_count > 0) {
loop_1:
        found = i - 1;
        if (i != 0) {
            base = (s32 *)*(s32 *)(arg0 + 0);
            cursor = (s32 *)((u8 *)base + found * 4);
            target = (s32 *)((u8 *)base + offset);
            do {
                if (*cursor == *target)
                    break;
                cursor = (s32 *)((u8 *)cursor - 4);
                found -= 1;
            } while (found != 0);
        }
        if (found < 0)
            total += func_003c47c0(*(s32 *)((u8 *)*(s32 **)(arg0 + 0) + offset)) + 0xC;
        i += 1;
        offset += 4;
        if (i < *(s32 *)(arg0 + 4))
            goto loop_1;
    }
    if (func_003deff0(arg1, 8, total, 0x37002, 0x37) == 0)
        goto fail;
    if (func_003deff0(arg1, 1, *(s32 *)(arg0 + 4) * 4 + 4, 0x37002, 0x37) == 0)
        goto fail;
    if (func_003df240(arg1, arg0 + 4, 4) == 0)
        goto fail;
    i = 0;
    offset = 0;
    if (*(s32 *)(arg0 + 4) > 0)
        goto loop_2;
    goto loop_3;
loop_2:
    found = i - 1;
    sp6C = found;
    if (i != 0) {
        base = (s32 *)*(s32 *)(arg0 + 0);
        cursor = (s32 *)((u8 *)base + found * 4);
        target = (s32 *)((u8 *)base + offset);
        do {
            if (*cursor == *target)
                break;
            cursor = (s32 *)((u8 *)cursor - 4);
            wide = (s64)((s64)found << 0x20) >> 0x20;
            found = (s32)(wide - 1);
            sp6C = found;
        } while (wide != 0);
    }
    if (func_003df240(arg1, &sp6C, 4) == 0)
        goto fail;
    i += 1;
    offset += 4;
    if (i < *(s32 *)(arg0 + 4))
        goto loop_2;
loop_3:
    i = 0;
    offset = 0;
    if (*(s32 *)(arg0 + 4) <= 0)
        goto done;
loop_4:
    found = i - 1;
    sp6C = found;
    if (i != 0) {
        base = (s32 *)*(s32 *)(arg0 + 0);
        cursor = (s32 *)((u8 *)base + found * 4);
        target = (s32 *)((u8 *)base + offset);
        do {
            if (*cursor == *target)
                break;
            cursor = (s32 *)((u8 *)cursor - 4);
            wide = (s64)((s64)found << 0x20) >> 0x20;
            found = (s32)(wide - 1);
            sp6C = found;
        } while (wide != 0);
    }
    wide = (s64)((s64)found << 0x20) >> 0x20;
    if (wide < 0 &&
        func_003c4820(*(s32 *)((u8 *)*(s32 **)(arg0 + 0) + offset), arg1) == 0)
        goto fail;
    i += 1;
    offset += 4;
    if (i < *(s32 *)(arg0 + 4))
        goto loop_4;
done:
    return arg0;
fail:
    return NULL;
}
