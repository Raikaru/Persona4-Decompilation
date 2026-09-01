/* 003b4120: object 248B/window 272B, normalized_diff 129, first differing offsets 14,16,18,28-30,32,34-48; undersized by 24B (retail frame 0x30, ra-only prologue; no saved-$s mismatch). Classification: source/register allocation and loop branch/order residual; opt_rebuildconditionals, schedule/no_branch_likely, opt_common_subs, O1/O3, declaration and pointer/base ordering probes ruled out. */
void func_003b4120(u8 *arg0, s32 arg1, u8 *arg2) {
    extern void func_003a4ab0(u8 *arg0, s32 arg1, u8 *arg2);
    s32 check;

    check = *(s32 *)(arg0 + 4);
    if (check == 8) {
        goto special;
    }
    {
        s32 stride;
        s32 zero;
        s32 i;
        f32 value;
        u8 *src;
        register u8 *base3;
        register u8 *base2;
        register u8 *base1;
        register u8 *base0;
        u8 *temp_7;
        u8 *temp_6;
        u8 *temp_4;

        src = *(u8 **)arg0;
        i = 0;
        zero = 0;
        base1 = arg2 + 0x98;
        base2 = arg2 + 0xA0;
        base3 = arg2 + 0xA8;
        stride = check;
        base0 = arg2 + 0x90;
        if (arg1 <= zero) {
            goto done;
        }
        do {
            value = *(f32 *)base0;
            temp_7 = src + stride;
            temp_6 = temp_7 + stride;
            i += 1;
            temp_4 = temp_6 + stride;
            *(f32 *)(src + 0) = value;
            *(f32 *)(src + 4) = *(f32 *)(base0 + 4);
            src = temp_4 + stride;
            *(f32 *)(temp_7 + 0) = *(f32 *)(base1 + 0);
            *(f32 *)(temp_7 + 4) = *(f32 *)(base1 + 4);
            *(f32 *)(temp_6 + 0) = *(f32 *)(base2 + 0);
            *(f32 *)(temp_6 + 4) = *(f32 *)(base2 + 4);
            *(f32 *)(temp_4 + 0) = *(f32 *)(base3 + 0);
            *(f32 *)(temp_4 + 4) = *(f32 *)(base3 + 4);
        } while (i < arg1);
    }
    goto done;
special:
    {
        f32 stack[8];

        stack[0] = *(f32 *)(arg2 + 0x90);
        stack[1] = *(f32 *)(arg2 + 0x94);
        stack[2] = *(f32 *)(arg2 + 0x98);
        stack[3] = *(f32 *)(arg2 + 0x9C);
        stack[4] = *(f32 *)(arg2 + 0xA0);
        stack[5] = *(f32 *)(arg2 + 0xA4);
        stack[6] = *(f32 *)(arg2 + 0xA8);
        stack[7] = *(f32 *)(arg2 + 0xAC);
        func_003a4ab0(*(u8 **)arg0, *(s32 *)(arg0 + 4) * arg1 * 4, (u8 *)stack);
    }
done:
    return;
}
