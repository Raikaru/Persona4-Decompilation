/* object_size=284 window=240 normalized_diff=169 differing_offsets=24,25,26,27,32,33,34,36,37,38,39,48,49,50,51,52 classification=object-over-window/register-coloring-and-callee-declarations; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=1 */
// FUN_003CC370
s32 func_003cc370(void) {
    extern s32 func_0039b6e0(s32 arg0);
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    u8 *temp_20;
    u8 *temp_2;

    temp_20 = func_003cc2c0();
    temp_17 = func_0039b6e0(4);
    temp_19 = func_0039b6e0(6);
    temp_16 = func_0039b6e0(5);
    temp_18 = func_0039b6e0(7);
    temp_2 = D_008872E0 + iGpffffb9b0;
    *(u8 **)(temp_2 + 0x1C) = temp_20;
    *(s32 *)(temp_2 + 0x20) = temp_19;
    *(s32 *)(temp_2 + 0x24) = temp_19;
    *(s32 *)(temp_2 + 0x28) = temp_19;
    *(s32 *)(temp_2 + 0x2C) = temp_18;
    *(s32 *)(temp_2 + 0x30) = temp_18;
    *(s32 *)(temp_2 + 0x38) = temp_17;
    *(s32 *)(temp_2 + 0x3C) = temp_16;
    func_00410a40((s32)temp_20);
    func_00410ab0(temp_19, 3);
    func_00410ab0(temp_19, 5);
    func_00410ab0(temp_19, 4);
    func_00410ab0(temp_18, 1);
    func_00410ab0(temp_18, 2);
    return 1;
}
