/* object_size=464 window=464 normalized_diff=10 differing_words=0xFC,0x124,0x148,0x1AC classification=near-miss register/codegen residual (daddiu-vs-addiu constant width and andi-vs-move result materialization); ruled_out=retail window has no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump forwarder, or ee-gcc sd-$sN signature; corrected block-scope callee declarations including func_00105f00 return s16 (retail caller sign-extends 16 bits although definition is s8), direct s16 third argument to func_001f99c0, func_001b0c80 pointer return, func_00194590 s64 return; body measured at v6.
*/
s32 func_00209dc0(u8 *arg0, u8 *arg1)
{
    extern s16 func_00105f00(s16 arg0);
    extern void func_00105e30(s16 arg0, s16 arg1);
    extern u8 *func_001b0c80(s32 arg0);
    extern u8 *func_001f99c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3,
                              s32 arg4);
    extern s64 func_00194590(u8 *arg0, u32 arg1);
    extern s32 func_00202e70(void);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    s16 temp_16;
    u8 *temp_2;
    s32 temp_2_2;
    s32 temp_3;
    s32 var_16;

    var_16 = func_00202e70() & 0xFFFF;
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 !=
            func_00105f00(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4))) {
            func_00105e30(
                *(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4), temp_16);
            temp_2 = func_001b0c80(*(s32 *)(arg1 + 0x190));
            if (temp_2 != NULL) {
                func_00194590(
                    func_001f99c0(temp_2, 2, *(s16 *)(arg0 + 4), 0, 0), 1);
            }
        }
        *(s32 *)(arg1 + 4) &= ~4;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
        func_0045af60(0, 15, 0, 1);
        var_16 = 2;
        break;
    case 1:
        temp_3 = *(s32 *)(arg1 + 4);
        if ((temp_3 & 4) != 0) {
            *(s32 *)(arg1 + 4) = temp_3 & ~4;
            var_16 = 1 & 0xFFFF;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    case 3:
        temp_2_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2_2;
        if ((temp_2_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    default:
        var_16 = 1 & 0xFFFF;
        break;
    }
    return var_16;
}
