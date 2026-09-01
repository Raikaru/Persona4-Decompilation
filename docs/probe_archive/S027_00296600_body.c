/* object 288/288 normalized_diff 8 differing_offsets 168,172,176,180,186,190,194,198; classification exact-size four-way transient s16 register rotation; prologue/frame exact (112-byte frame, saved s5/s4/s3/s2/s1/s0, two incoming pointers), old-style block-scope func_00286780 declaration required; ruled out reversed/field-first/combined declarations, reversed load order, direct field-c address, explicit return tail, and recomputing each of field_c/field_e/field_10/field_12 at use site. */
void func_00296600(u8 *arg0, u8 *arg1)
{
    extern u8 *func_00286780();
    extern u8 *func_00286f00(s32 arg0);
    s32 temp_16;
    s32 var_17;
    u8 *temp_19;
    s32 var_18;
    s16 field_c;
    s16 field_e;
    s16 field_10;
    s16 field_12;
    u16 temp_6;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_5;

    temp_19 = func_00286f00(5);
    if (*(s32 *)(*(u8 **)(arg0 + 0x80) + 0x14) < 6) {
        var_17 = *(s32 *)(arg0 + 0xAC);
    } else {
        var_17 = *(s32 *)(arg0 + 0xA8);
    }
    var_18 = 0;
    goto loop_7_test;
loop_7_body:
    temp_5 = *(u8 **)(arg0 + 0xA4);
    temp_16 = var_18 * 0x3C;
    temp_5 += temp_16;
    if (*(u16 *)temp_5 != 5)
        goto loop_7_increment;
    temp_2 = func_00286780(
        ((temp_6 = *(u16 *)(temp_5 + 2)), temp_19), temp_6, arg1);
    temp_3 = *(u8 **)(arg0 + 0xA4) + temp_16;
    field_c = *(s16 *)(temp_3 + 0xC);
    field_e = *(s16 *)(temp_3 + 0xE);
    field_10 = *(s16 *)(temp_3 + 0x10);
    field_12 = *(s16 *)(temp_3 + 0x12);
    *(s16 *)(temp_2 + 8) = field_c;
    *(s16 *)(temp_2 + 0xA) = field_e;
    *(s16 *)(temp_2 + 0xC) = field_10;
    *(s16 *)(temp_2 + 0xE) = field_12;
    temp_3 = *(u8 **)(arg0 + 0xA4) + temp_16;
    *(s16 *)(temp_2 + 0x10) = *(s16 *)(temp_3 + 0x14);
    temp_3 = *(u8 **)(arg0 + 0xA4) + temp_16;
    *(s8 *)(temp_2 + 0x12) = *(s8 *)(temp_3 + 0x16);
loop_7_increment:
    var_18 += 1;
loop_7_test:
    if (var_18 < var_17)
        goto loop_7_body;
    return;
}
