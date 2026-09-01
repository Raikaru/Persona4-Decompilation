/* Closest reconstruction attempt for func_004bc540.
 * lverify LaneCode1Bc540_9: object 1960/window 1968, normalized_diff 11.
 * Remaining difference is the retail scheduler's reversed sll/lw order at offsets 0x30/0x34.
 */
void func_004bc540(u8 *arg0, s32 arg1, u8 *arg2, f32 fparg0)
{
    u8 *temp_5;
    struct {
        u8 *sp8;
        u8 *spC;
    } stack;
    u8 *var_7;
    s32 var_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;

    var_7 = (u8 *)&stack;
    var_3 = 8;
    if (var_7 != NULL) {
        do {
            *var_7 = 0;
            var_7++;
            var_3--;
        } while (var_3 != 0);
    }
    temp_5 = (u8 *)(*(s32 *)(*(u8 **)(arg0 + 0) + 4) + (arg1 = arg1 << 3));
    stack.sp8 = temp_5 + 8;
    stack.spC = temp_5 + 0xC;
    temp_f1 = 1.0f - fparg0;

    if (*(s32 *)(arg0 + 4) & 1) {
        temp_f4 = *(f32 *)(arg0 + 0x34);
        if (temp_f4 > 0.0f) {
            temp_f2 = 1.0f - ((*(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x30)) / temp_f4);
            if (temp_f2 < 0.0f) {
                temp_f2 = 0.0f;
            }
        } else if (temp_f4 == 0.0f) {
            if (*(f32 *)(arg0 + 0x2C) < *(f32 *)(arg0 + 0x30)) {
                goto set_one;
            }
            temp_f2 = 0.0f;
            goto set_progress;
        set_one:
            temp_f2 = 1.0f;
        set_progress:
            ;
        }
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0]);
        arg2[0] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1]);
        arg2[1] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2]);
        arg2[2] = (u8)temp_f3;
        temp_f3 = temp_f2 * (fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3]);
        arg2[3] = (u8)temp_f3;
        return;
    }
    temp_f3 = fparg0 * (f32)stack.spC[0] + temp_f1 * (f32)stack.sp8[0];
    arg2[0] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[1] + temp_f1 * (f32)stack.sp8[1];
    arg2[1] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[2] + temp_f1 * (f32)stack.sp8[2];
    arg2[2] = (u8)temp_f3;
    temp_f3 = fparg0 * (f32)stack.spC[3] + temp_f1 * (f32)stack.sp8[3];
    arg2[3] = (u8)temp_f3;
}
