/* object 380 bytes, retail window 368 bytes, normalized_diff 85; differing offsets: 16,24,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,120,124,128,132,136,140,144,148,152,156,160,164,168,172,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,360,368,372,376; levers: M2C control-flow layout, u16/u8 pointer types, block/global lookup declarations, bit local and argument reuse, declaration order/lifetime reuse; oversized archive condition. */
s32 func_00311b90(u16 *arg0, u16 *arg1, s32 arg2, s16 *arg3)
{
    s32 temp_3_2;
    s32 var_2;
    s64 temp_24;
    s64 temp_8;
    s64 temp_8_2;
    s64 var_12;
    s64 var_13;
    s64 var_14;
    s64 var_15;
    u8 var_24;
    u8 *temp_3;
    u8 *temp_9;
    u8 *base;
    u8 *table;

    if (*arg0 == 0) {
        return 0;
    }
    var_15 = 0;
    var_2 = 0;
    base = (u8 *)arg0 + 4;
    var_14 = 0;
    table = iGpffffb3d4;
    arg0 = (u16 *)(u32)1;
    goto outer_test;
outer_body:
    temp_8 = (s64)(s16)var_14;
    temp_3 = base + (temp_8 * 2);
    temp_9 = temp_3 + 4;
    temp_8_2 = *(s16 *)temp_9;
    if (temp_8_2 != 0) {
        var_12 = 0;
        var_13 = 0;
        goto inner_test;
inner_body:
        temp_24 = (s64)(s16)var_13;
        temp_3_2 = (u32)arg0 << temp_24;
        if ((var_2 & temp_3_2) == 0) {
            if ((s64)*(s8 *)(temp_9 + 1) != 0) {
                var_24 = *(u8 *)((u8 *)table
                    + (*(u16 *)((u8 *)arg1 + (temp_24 * 2)) * 14) + 2);
            } else {
                var_24 = *(u16 *)((u8 *)arg1 + (temp_24 * 2));
            }
            if ((var_24 & 0xFFFF) == temp_8_2) {
                var_2 |= temp_3_2;
                var_15 = (s64)(s16)(var_15 + 1);
                var_12 = 1;
                goto inner_done;
            }
        }
inner_next:
        var_13 = (s64)(s16)(var_13 + 1);
inner_test:
        temp_24 = (s64)(s16)var_13;
        if (temp_24 < arg2) {
            goto inner_body;
        }
inner_done:
        if ((s64)*(s8 *)(temp_9 + 1) != 0 &&
            (s64)(s16)var_12 == 0) {
            return 0;
        }
    }
outer_next:
    var_14 = (s64)(s16)(var_14 + 1);
outer_test:
    temp_8 = (s64)(s16)var_14;
    if (temp_8 < 8) {
        goto outer_body;
    }
    if (arg3 != 0) {
        *arg3 = (s16)var_15;
    }
    return var_2;
}
