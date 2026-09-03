/* Main 2026-09-03: this function needs `schedule on` + `no_branch_likely on` (the unit is schedule-off /
   branch-likely at this point; without them the archive scores nd73-88, with them nd12). The remaining
   12 words are the six-float rotation: retail loads all six (f5..f0) then stores; b210 does two 3-float
   groups (f2..f0 twice) for named temps, V3 struct copies, V3 struct temporaries, array stores, and
   under opt_propagation off. Load-sinking floor for a two-copy sequence. */
/* measured: object 340B, retail window 352B, normalized_diff 12; differing offsets 92,100,108,116,124,128,132,136,140. Shared return label plus null-block ordering fixed all integer/control words and df2a0 branch polarity; remainder is retail deferring f5/f4/f3 loads while this candidate stores f2/f1/f0 early. Tried schedule/no_branch_likely/opt_propagation scopes, declaration and output aggregate forms, alias/raw stack forms, and branch restructurings. */
u8 *func_0038fd30(u8 *arg0)
{
    extern s32 func_003df050(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
    extern s32 func_003e2910(u8 *arg0, void *arg1, s32 arg2);
    extern s32 func_003df2a0(u8 *arg0, void *arg1, s32 arg2);
    struct Input {
        s32 size;
        f32 values[6];
        u16 count1;
        u8 pad7E[2];
        u16 count2;
        u8 padding[8];
    } input;
    struct Output {
        f32 v0;
        f32 v1;
        f32 v2;
        f32 v3;
        f32 v4;
        f32 v5;
        f32 v6;
        f32 v7;
    } output;
    f32 temp_f5;
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    u8 status[4];
    s32 temp_18;
    u16 temp_2_2;
    u8 *temp_2;

    if (func_003df050(arg0, 1, 0, status) != 0) {
        goto read_header;
    }
    return NULL;

read_header:
    if (func_003e2910(arg0, &input, 0x24) == 0x24) {
        goto make_output;
    }
    return NULL;

make_output:
    temp_f5 = input.values[0];
    temp_f4 = input.values[1];
    temp_f3 = input.values[2];
    temp_f2 = input.values[3];
    temp_f1 = input.values[4];
    temp_f0 = input.values[5];
    output.v3 = temp_f5;
    output.v4 = temp_f4;
    output.v5 = temp_f3;
    output.v0 = temp_f2;
    output.v1 = temp_f1;
    output.v2 = temp_f0;
    temp_2 = func_0038f990(input.count1, input.count2,
                            (f32 *)&output.v0, input.size);
    if (temp_2 == NULL) {
        goto result_null;
    }
    temp_2_2 = *(u16 *)(temp_2 + 0x1E);
    if ((s32)temp_2_2 > 0) {
        goto read_data;
    }

check_flags:
    if ((*(s32 *)temp_2 & 1) != 0) {
        goto read_flags;
    }

return_result:
    return temp_2;

result_null:
    return NULL;

read_data:
    temp_18 = temp_2_2 * 0x10;
    if (temp_18 == func_003e2910(arg0, *(void **)(temp_2 + 0x20), temp_18)) {
        goto check_flags;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;

read_flags:
    if (func_003df2a0(arg0, *(void **)(temp_2 + 0x24),
                      *(u16 *)(temp_2 + 0x1C) * 2) != 0) {
        goto return_result;
    }
    jtbl_008873EC[0](temp_2);
    return NULL;
}
