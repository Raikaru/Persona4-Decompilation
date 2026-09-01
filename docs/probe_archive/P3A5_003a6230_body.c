/* object_size=364 window=384 normalized_diff=253 differing_offsets=0x10,0x18,0x1C,0x20,0x28,0x2C,0x30,0x38,...; classification=automatic archive: residual in the hundreds after callee declaration correction, indicating a different source/register/control-flow shape; ruled_out=movz/movn,COP1-accumulator-MAC,standalone-MMI-H009,framed-tail-jump,sd-saved-register floor; block-scope declaration corrected: func_003a45c0(s64*,s32,s64*); integer-domain pointer arithmetic used; no further probes per hundreds-residual rule. */
void func_003a6230(u8 *arg0, s32 arg1, u8 *arg2)
{
    extern void func_003a45c0(s64 *arg0, s32 arg1, s64 *arg2);
    f32 sp1C;
    f32 sp18;
    s32 temp_14;
    s32 var_24;
    s32 var_3;
    u8 *var_15;
    u8 *temp_10;
    u8 *temp_11;
    u8 *temp_12;
    u8 *temp_4;
    u8 *temp_7;
    u8 *temp_8;
    u8 *temp_9;

    temp_14 = *(s32 *)(arg0 + 4);
    var_15 = *(u8 **)(arg0 + 0);
    if (temp_14 != 8) {
        var_24 = 0;
        if (arg1 > 0) {
            if (arg1 >= 9) {
                var_3 = 0;
                if ((arg1 >= 0) && (arg1 < 0x7FFFFFFF)) {
                    var_3 = 1;
                }
                if (var_3 != 0) {
                    do {
                        temp_12 = (u8 *)((u32)var_15 + (u32)temp_14);
                        temp_11 = (u8 *)((u32)temp_12 + (u32)temp_14);
                        temp_10 = (u8 *)((u32)temp_11 + (u32)temp_14);
                        var_24 += 8;
                        temp_9 = (u8 *)((u32)temp_10 + (u32)temp_14);
                        temp_8 = (u8 *)((u32)temp_9 + (u32)temp_14);
                        temp_7 = (u8 *)((u32)temp_8 + (u32)temp_14);
                        temp_4 = (u8 *)((u32)temp_7 + (u32)temp_14);
                        *(f32 *)(var_15 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(var_15 + 4) = *(f32 *)(arg2 + 0x74);
                        var_15 = (u8 *)((u32)temp_4 + (u32)temp_14);
                        *(f32 *)(temp_12 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_12 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_11 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_11 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_10 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_10 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_9 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_9 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_8 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_8 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_7 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_7 + 4) = *(f32 *)(arg2 + 0x74);
                        *(f32 *)(temp_4 + 0) = *(f32 *)(arg2 + 0x70);
                        *(f32 *)(temp_4 + 4) = *(f32 *)(arg2 + 0x74);
                    } while (var_24 < (arg1 - 8));
                }
            }
            if (var_24 < arg1) {
                do {
                    var_24 += 1;
                    *(f32 *)(var_15 + 0) = *(f32 *)(arg2 + 0x70);
                    *(f32 *)(var_15 + 4) = *(f32 *)(arg2 + 0x74);
                    var_15 = (u8 *)((u32)var_15 + (u32)temp_14);
                } while (var_24 < arg1);
            }
        }
    } else {
        sp18 = *(f32 *)(arg2 + 0x70);
        sp1C = *(f32 *)(arg2 + 0x74);
        func_003a45c0((s64 *)var_15, arg1 * temp_14, (s64 *)&sp18);
    }
}
