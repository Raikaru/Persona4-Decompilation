/* object_size=428; window=432; normalized_diff=247; differing_offsets=[32,48,64,72,88,89,90,91,92,94,95,96,98,99,100,102]; classification=LARGE_RESIDUAL_DIFFERENT_SHAPE; ruled_out=retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump forwarder, or sd-saved s-register; corrected callee declarations to func_0045abd0(s16,s32,s16), func_0045af60(s32,s32,s32,s32), func_0045aa90(s16,s16), func_0047e0f0(u8*,s16,s16,u16), func_0047e6f0(u8*); frame=0x30 and s0/s1 count matched; residual remained 247 after corrected declarations, so archived without reordering. */

void func_0047ed60(u8 *arg0)
{
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_4;
    s16 temp_4_2;
    s32 var_16;
    u8 *temp_3;

    func_0047e6f0(arg0);
    temp_3 = *(u8 **)arg0;
    if (temp_3 != NULL && (*(u16 *)(temp_3 + 0x12) & 1) != 0) {
        var_16 = 1;
        temp_3_2 = *(s16 *)(arg0 + 0x16);
        if (temp_3_2 >= 0) {
            if (temp_3_2 == 0) {
                if ((*(u16 *)(arg0 + 0x10) & 0x20) != 0) {
                    func_0045abd0(*(s16 *)(arg0 + 0x12), *(s32 *)(arg0 + 0x18),
                                  *(s16 *)(arg0 + 0x14));
                }
                *(s16 *)(arg0 + 0x16) = -1;
            } else {
                *(s16 *)(arg0 + 0x16) = temp_3_2 - 1;
                var_16 = 0;
            }
        }
        temp_4 = *(s16 *)(arg0 + 0x24);
        switch (temp_4) {
        case -2:
            temp_4_2 = *(s16 *)(arg0 + 0x26);
            if (temp_4_2 >= 0) {
                func_0045aa90(temp_4_2, *(s16 *)(arg0 + 0x1E));
                *(s16 *)(arg0 + 0x26) = -1;
            }
            *(s16 *)(arg0 + 0x24) = -1;
            break;
        case 0:
            func_0045af60(*(s16 *)(arg0 + 0x1C), *(s16 *)(arg0 + 0x1E),
                          *(s16 *)(arg0 + 0x20), *(s16 *)(arg0 + 0x22));
            *(s16 *)(arg0 + 0x26) = *(s16 *)(arg0 + 0x1C);
            *(s16 *)(arg0 + 0x24) = -1;
            break;
        default:
            *(s16 *)(arg0 + 0x24) = temp_4 - 1;
            var_16 = 0;
            break;
        }
        if (*(s32 *)(arg0 + 0xC) != 0 && var_16 == 1 &&
            *(s16 *)(arg0 + 8) != -1) {
            temp_3_4 = *(s16 *)(arg0 + 8) + 1;
            *(s16 *)(arg0 + 8) = temp_3_4;
            if (temp_3_4 < 8) {
                if (func_0047e0f0(arg0, *(s16 *)(arg0 + 8),
                                  *(s16 *)(arg0 + 4), *(u16 *)(arg0 + 6)) == 0) {
                    *(s16 *)(arg0 + 8) = -1;
                }
            } else {
                *(s16 *)(arg0 + 8) = -1;
            }
        }
    }
}
