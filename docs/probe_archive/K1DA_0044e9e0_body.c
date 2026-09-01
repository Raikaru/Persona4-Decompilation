/* object 176B, retail window 176B, normalized_diff 133; differing offsets 0x0,0x4,0x8-0xF,0x12-0x17; exact size but substantial residual. Corrected call shape: func_0044e920(E8Node *). Tried direct field accesses, SDK-style aliases, generated M2C local aliases, and measured opt_propagation off; compiler retained a saved register/frame shape unlike retail. */
void func_0044e9e0(u8 *arg0) {
    s32 var_5;
    u8 temp_3;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_5_2;
    u8 *temp_7;

    temp_5 = (u8 *)D_00763D1C;
    *(s32 *)(temp_5 + 0x18) = *(s32 *)(temp_5 + 0x18) - 1;
    temp_7 = (u8 *)D_00763D1C;
    var_5 = *(s32 *)(temp_7 + 0x1C);
    *(s32 *)(temp_7 + 0x1C) = var_5 - *(s32 *)arg0;
    temp_3 = *(u8 *)(arg0 + 8);
    if ((s32)temp_3 < 8) {
        temp_5_2 = (u8 *)(temp_3 * 4 + (u32)D_00763D1C);
        *(s32 *)(temp_5_2 + 0x38) =
            *(s32 *)(temp_5_2 + 0x38) - *(s32 *)arg0;
        var_5 = *(s32 *)arg0 - (*(u16 *)(arg0 + 4) + 0x18);
        temp_4 = (u8 *)(*(u8 *)(arg0 + 8) * 4 + (u32)D_00763D1C);
        *(s32 *)(temp_4 + 0x58) = *(s32 *)(temp_4 + 0x58) - var_5;
    }
    func_0044e920((E8Node *)(arg0 + 0xC));
    *(s16 *)(arg0 + 8) = 0;
}
