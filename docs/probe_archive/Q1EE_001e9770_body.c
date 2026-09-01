/* object 468B, window 480B, normalized_diff 5, differing offsets 0xE0 0xE4, classification register allocation / unsigned-guard destination; tested recomputed direct loads, explicit probability result local, operand order, declaration order, and guard polarity; retail uses sltu $at while candidate uses sltu $v0, and tail is zero padding. */
s32 func_001e9770(void) {
    extern s32 func_0029cc00(s32 arg0);
    extern void func_0029cf50(s32 arg0);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00231f80(s32 arg0);
    extern s32 func_00232710(s32 arg0, s32 arg1);
    u32 temp_16;
    u32 temp_2;
    s32 temp_30;
    s32 temp_23;
    u8 *var_21;
    u8 *var_20;
    u32 temp_19;
    u32 var_18;
    s32 temp_17;
    u16 temp_3;
    u8 *temp_4;
    s32 temp_22;
    temp_23 = func_0029cc00(0);
    temp_30 = func_0029cc00(1);
    temp_17 = func_0029cc00(2);
    var_20 = NULL;
    var_18 = 0x0FFFFFFF;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    temp_22 = temp_17 & 0x80000;
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) == 0)
        goto loop_next;
    if ((temp_3 & 8) == 0)
        goto loop_next;
    if (*(u8 *)(*(u8 **)(var_21 + 0x30) + 0xA2) != 0)
        goto loop_next;
    if ((temp_22 == 0) &&
        (func_002428f0(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), 0) != 0))
        goto loop_next;
    if (temp_19 < (u32)temp_23)
        goto loop_next;
    temp_4 = *(u8 **)(*(u8 **)(var_21 + 0x30) + 0xA64);
    temp_16 = *(u16 *)(temp_4 + 8);
    temp_2 = (u32)(func_00231f80((s32)temp_4) & 0xFFFF);
    if ((u32)temp_16 * 0x64 > temp_2 * (u32)temp_30)
        goto loop_next;
    if ((temp_17 != 0) &&
        (func_00232710(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), temp_17) == 0))
        goto loop_next;
    if (temp_19 >= var_18)
        goto loop_next;
    var_20 = var_21;
    var_18 = temp_19;
loop_next:
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    if (var_20 != NULL) {
        func_0029cf50(*(s32 *)(var_20 + 8) | 0x80000000);
    } else {
        func_0029cf50(-1);
    }
    return 1;
}
