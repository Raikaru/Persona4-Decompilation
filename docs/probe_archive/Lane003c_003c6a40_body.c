// Candidate archive for func_003c6a40.
// Best probe: explicit bucket/list goto flow with no_branch_likely on; object 456B/window 464B, normalized_diff 90. Schedule on worsened to nd245; residual register/control-flow layout remained.
void func_003c6a40(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_6;
    u8 **temp_6;
    u8 **temp_8_3;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_6_2;
    u8 *temp_6_3;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_7_3;
    u8 *temp_8;
    u8 *temp_8_2;
    u8 *temp_8_4;
    u8 *temp_8_5;
    u8 *temp_9;
    u8 *var_3;

    if (arg2 < 4)
        goto small;
    *(s32 *)(arg0 + 0x18) = 1;
    temp_6 = (u8 **)(arg1 + *(u8 *)(arg0 + 0x20) * 4);
    temp_3 = *temp_6;
    if (temp_3 == arg0)
        goto special_head;
    temp_6_2 = *(u8 **)(arg0 + 0x10);
    if (temp_6_2 != NULL)
        *(u8 **)(temp_6_2 + 0x14) = *(u8 **)(arg0 + 0x14);
    temp_6_3 = *(u8 **)(arg0 + 0x14);
    if (temp_6_3 != NULL)
        *(u8 **)(temp_6_3 + 0x10) = *(u8 **)(arg0 + 0x10);
    var_6 = 0;
loop:
    temp_9 = *(u8 **)(arg0 + (var_6 & 0xFF) * 4 + 4);
    temp_8 = *(u8 **)(temp_9 + 4);
    if (temp_8 == NULL)
        goto right;
    if (temp_8 == arg0)
        goto right;
    if (*(s32 *)(temp_8 + 0x18) != 0)
        goto right;
    var_3 = temp_8;
selected:
    if (var_3 == NULL)
        goto next_index;
    temp_8_3 = (u8 **)(arg1 + *(u8 *)(var_3 + 0x20) * 4);
    temp_7 = *temp_8_3;
    if (temp_7 == var_3)
        goto special_selected;
    temp_8_4 = *(u8 **)(var_3 + 0x10);
    if (temp_8_4 != NULL)
        *(u8 **)(temp_8_4 + 0x14) = *(u8 **)(var_3 + 0x14);
    temp_8_5 = *(u8 **)(var_3 + 0x14);
    if (temp_8_5 != NULL)
        *(u8 **)(temp_8_5 + 0x10) = *(u8 **)(var_3 + 0x10);
after_unlink:
    *(u8 *)(var_3 + 0x20) = *(u8 *)(var_3 + 0x20) - 1;
    *(u8 **)(var_3 + 0x10) =
        *(u8 **)(arg1 + *(u8 *)(var_3 + 0x20) * 4);
    temp_7_3 = *(u8 **)(var_3 + 0x10);
    if (temp_7_3 != NULL)
        *(u8 **)(temp_7_3 + 0x14) = var_3;
    *(u8 **)(arg1 + *(u8 *)(var_3 + 0x20) * 4) = var_3;
    *(u8 **)(var_3 + 0x14) = NULL;
next_index:
    var_6 = (var_6 + 1) & 0xFF;
    if (var_6 < 3)
        goto loop;
    goto return_label;
small:
    *(s32 *)(arg0 + 0x1C) = 1;
    goto return_label;
special_head:
    *temp_6 = *(u8 **)(temp_3 + 0x10);
    temp_3_2 = *(u8 **)(arg1 + *(u8 *)(arg0 + 0x20) * 4);
    if (temp_3_2 != NULL)
        *(u8 **)(temp_3_2 + 0x14) = NULL;
    goto loop;
right:
    temp_8_2 = *(u8 **)(temp_9 + 8);
    if (temp_8_2 == NULL)
        goto selected_zero;
    if (*(s32 *)(temp_8_2 + 0x18) != 0)
        goto selected_zero;
    var_3 = temp_8_2;
    goto selected;
special_selected:
    *temp_8_3 = *(u8 **)(temp_7 + 0x10);
    temp_7_2 = *(u8 **)(arg1 + *(u8 *)(var_3 + 0x20) * 4);
    if (temp_7_2 != NULL)
        *(u8 **)(temp_7_2 + 0x14) = NULL;
    goto after_unlink;
selected_zero:
    var_3 = NULL;
    goto selected;
return_label:
    return;
}
