/* object 132B / window 144B / normalized_diff 10; residual at 0x44-0x50: global-table address (lui/addiu/addu) is split by saved-field load (lw $s1). First diffs: [72, 73, 74, 75, 78, 79, 80, 81, 82, 83]. */
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039dcc0);
// FUN_0039E740
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039e740);
/* LANE_9F050_D: opt_propagation off + an explicit obj local so arg0 is not coalesced and can sit below temp_17 (s1) in saved-register order. */
/* LANE_9F050_G: schedule on + opt_propagation off + entry local to get call setup and saved-field load order. */
/* LANE_9F050_J: schedule on + opt_propagation off + opt_common_subs off to stop CSE from splitting the table address around temp_17. */
#pragma push
#pragma opt_propagation off
#pragma no_branch_likely on
#pragma schedule on
// FUN_0039F050
void func_0039f050(u8 *arg0)
{
    s32 temp_17;
    u8 *obj;
    s32 temp_5;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_6;
    s32 (*func)(u8 *, s32, u8 *);

    temp_2 = *(u8 **)(*(s32 *)(*(u8 **)(arg0 + 0x2C) + 8) + iGpffffb5e0);
    if (temp_2 != NULL) {
        var_2 = *(s32 *)(temp_2 + 0x80);
    } else {
        var_2 = 0;
    }
    obj = arg0;
    temp_6 = *(u8 **)(obj + 4);
    temp_5 = var_2 * 0x10;
    temp_17 = *(s32 *)(temp_6 + 0x18);
    *(s32 *)(temp_6 + 0x18) = temp_17 + temp_5;
    func = (s32 (*)(u8 *, s32, u8 *))*(void **)((u8 *)D_0064F2B4 + (var_2 * 4));
    func(obj, temp_5, temp_6);
    *(s32 *)(*(u8 **)(obj + 4) + 0x18) = temp_17;
}
#pragma pop
// FUN_0039F0E0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f0e0);
// FUN_0039F160
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f160);
// FUN_0039F9D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f9d0);
