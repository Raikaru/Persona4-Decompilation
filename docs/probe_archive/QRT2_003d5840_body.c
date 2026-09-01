/* object 348B vs window 336B, normalized_diff 226, differing offsets first reported 0x10-0x17,0x5a,0x5c-0x5e,0x60-0x64,0x61-0x63; classification oversized candidate/different function; ruled out further reordering after automatic archive threshold. */
/* Candidate attempted explicit callback typedef, self alias for saved-register timing, out-of-line callback/range labels, named condition materialization, and typed pointer temporaries. */

s32 func_003d5840(u8 *arg0, u8 *arg1)
{
    typedef void (*Callback)(u8 *, u8 *, u8 *, s32, f32);
    s32 temp_3_2;
    s32 temp_4;
    u8 *temp_6;
    s32 var_16;
    s32 var_3;
    u8 *var_6;
    s32 var_7;
    u8 *var_8;
    u8 *temp_3;
    u8 *var_5;
    u8 *self;
    s32 positive;

    self = arg0;
    *(u8 **)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 4) = 0;
    temp_3 = *(u8 **)arg1;
    *(s32 *)(arg0 + 0x24) = *(s32 *)(temp_3 + 4);
    *(s32 *)(arg0 + 0x28) = *(s32 *)(temp_3 + 8);
    *(s32 *)(arg0 + 0x3C) = *(s32 *)(temp_3 + 0xC);
    *(s32 *)(arg0 + 0x40) = *(s32 *)(temp_3 + 0x10);
    *(Callback *)(arg0 + 0x44) = *(Callback *)(temp_3 + 0x14);
    *(s32 *)(arg0 + 0x48) = *(s32 *)(temp_3 + 0x18);
    var_7 = *(s32 *)(arg0 + 0x2C);
    var_16 = 0;
    positive = 0 < var_7;
    if (positive != 0) {
        goto callback_entry;
    }
range_entry:
    temp_4 = *(s32 *)(self + 0x28);
    var_5 = self + 0x4C;
    temp_6 = *(u8 **)(arg1 + 0x10);
    var_8 = temp_6;
    var_6 = temp_6 + (positive * var_7 * temp_4);
    positive = 0 < var_7;
    var_3 = 0;
    if (positive == 0) {
        goto final;
    }
range_loop:
    *(u8 **)(var_5 + 0) = var_8;
    var_3 += 1;
    *(u8 **)(var_5 + 4) = var_6;
    temp_4 = *(s32 *)(self + 0x24);
    var_7 = *(s32 *)(self + 0x2C);
    temp_3_2 = *(s32 *)(self + 0x28);
    var_5 += temp_4;
    positive = var_3 < var_7;
    var_8 += temp_3_2;
    var_6 += temp_3_2;
    if (positive != 0) {
        goto range_loop;
    }
    goto final;
callback_entry:
    do {
        temp_4 = *(s32 *)(self + 0x24);
        temp_3_2 = *(s32 *)(self + 0x28);
        temp_6 = *(u8 **)(arg1 + 0x10);
        var_5 = self + (var_16 * temp_4) + 0x4C;
        var_8 = temp_6 + (var_16 * temp_3_2);
        temp_4 = *(s32 *)(arg1 + 0x14);
        (*(Callback *)(self + 0x44))(
            var_5, var_8,
            temp_6 + (temp_3_2 * (var_16 + var_7)),
            temp_4, 0.0f);
        var_7 = *(s32 *)(self + 0x2C);
        var_16 += 1;
        positive = var_16 < var_7;
    } while (positive != 0);
    goto range_entry;
final:
    *(u8 **)(self + 8) =
        var_8 + (var_7 * *(s32 *)(self + 0x28) * 2);
    return 1;
}
