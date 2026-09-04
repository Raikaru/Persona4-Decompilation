/* Exact reconstruction for func_001104d0.
 * Measured: object 164B, retail window 176B, verify normalized_diff 0.
 * fndiff's only three absent rows are the retail's zero-tail padding words.
 * The signed s32 seed view matches the direct div/mfhi sequence; the local
 * declaration order and explicit bottom-test gotos preserve retail colouring.
 */
void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2)
{
    s32 temp_8;
    s32 temp_9;
    s32 var_12;
    s32 var_11;
    s32 var_10;

    var_11 = arg0 % 0x16D;
    var_12 = 3;
    var_10 = 0;
    goto loop_test;
loop_body:
    temp_9 = var_12 + 1;
    temp_8 = temp_9 - 1;
    if (var_11 < D_005E45E0[(temp_9 - 1) % 0xC]) {
        goto done;
    }
    var_11 = var_11 - D_005E45E0[temp_8 % 0xC];
    var_12 = temp_9;
    if (temp_9 < 0xC) {
        goto loop_increment;
    }
    var_12 = 0;
loop_increment:
    var_10 = var_10 + 1;
loop_test:
    if (var_10 < 0xC) {
        goto loop_body;
    }
done:
    *arg1 = var_12 + 1;
    *arg2 = var_11 + 1;
}
