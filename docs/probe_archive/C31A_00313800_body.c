/* object 480 bytes, retail window 464 bytes, normalized_diff 100; differing offsets: 0,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,136,140,144,148,152,156,160,168,172,176,180,184,188,192,204,208,212,216,220,224,228,232,236,240,244,248,252,256,268,276,280,284,288,292,296,304,308,316,320,324,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476; levers: canonical block-scope callee prototypes, M2C loop/control-flow reconstruction, saved-local declaration order, table-base preheader, mixed signed-width casts; oversized archive condition. */
void func_00313800(s64 arg0)
{
    extern s32 func_0010ac10(s32 arg0);
    extern u8 *func_002e4870(s8 arg0);
    extern void func_002e55c0(s64 arg0, s32 arg1, s64 arg2);
    extern s32 func_003136b0(u16 arg0);
    u8 *spA0;
    s64 temp_16_2;
    s64 temp_16_3;
    s64 temp_17;
    s64 temp_18;
    s64 temp_22;
    s64 var_19;
    s64 var_20;
    s64 var_21;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_4;
    u8 *table_base;
    var_19 = 0;
    var_21 = 0;
    temp_18 = (s64)(s8)arg0;
    table_base = (u8 *)D_00642F00 + (temp_18 * 8);
    goto outer_test;
outer_body:
    temp_16 = *(u8 **)(table_base - 0x10) + ((s64)(s8)var_21 * 0x20);
    temp_4 = temp_16;
    if (*(u16 *)temp_4 != 0 && func_003136b0(*(u16 *)temp_4) == 1) {
        func_002e55c0(0, *(s16 *)temp_4, 0);
        spA0 = temp_4 + 4;
        temp_16_2 = (s64)(s16)var_19;
        temp_17 = temp_16_2 + 1;
        func_002e4870(0)[0x14] = 1;
        var_20 = 0;
        goto inner_test;
inner_body:
        temp_16_3 = (s64)(s16)var_20;
        temp_2 = spA0 + (temp_16_3 * 2);
        temp_4 = temp_2 + 4;
        temp_18 = (s64)(s8)temp_17;
        func_002e55c0(temp_18, *(s16 *)temp_4, 1);
        *(func_002e4870((s8)temp_17) + temp_16_3) = 0;
        if (func_0010ac10(*(u16 *)temp_4) != 0) {
            temp_18 = 1;
            *(func_002e4870((s8)temp_17) + (s64)(s16)var_20) = temp_18;
        }
        var_20 = (s64)(s16)(var_20 + 1);
inner_test:
        temp_22 = (s64)(s16)var_20;
        if (temp_22 < temp_18) goto inner_body;
        var_19 = (s64)(s16)(var_19 + 1);
    }
outer_next:
    var_21 = (s64)(s16)(var_21 + 1);
outer_test:
    temp_18 = (s64)(s16)var_21;
    if (temp_18 < 6) goto outer_body;
}
