/* Re-certified: object 348B / retail window 352B, raw fndiff 12 words:
 * eleven loop-register differences and one absent zero-tail word.
 * Reuse the owning TU's canonical helper declarations and a real s32
 * record-length object. Scoped opt_propagation off restores separator
 * hoisting (32 to 18 words); natural signed division restores all six
 * rounding words (18 to 12). Bias addition wraps explicitly and scaling
 * uses multiplication rather than left-shifting a negative value.
 * Remaining offsets: 0x90,0x94,0xA4,0xA8,0xAC,0xB8,0xC4,0xC8,
 * 0xCC,0xD8,0xE0. The counter already matches; separator, pointer and
 * character registers are exchanged. Counter/local scopes and a wider
 * character local do not improve this. Byte separators give 356B/46 words.
 * Retain ASM; no shared helper ABI is changed. */
#pragma push
#pragma opt_propagation off
void func_00456530(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 recordLength;
    u8 sp240[0x100];
    u8 sp140[0x100];
    u8 sp40[0x100];
    s32 temp_16;
    u8 *temp_3;
    s8 temp_4;
    s32 temp_post_3;
    s32 temp_post_4;
    s32 var_16;
    s32 var_3;
    s32 var_7;

    func_00454d20((s32)arg0, sp240);
    var_16 = 0;
loop_00456530_body:
    func_0043f810(sp40, sp240, 0xFC);
    func_0043f810(sp140, arg1 + var_16, 0xFC);
    if (*(s8 *)sp140 != 0) {
        func_0043f810(&recordLength, arg1 + (var_16 + 0xFC), 4);
        temp_16 = var_16 + 0x100;
        func_00442428(sp40, sp140);
        var_7 = 0;
        {
            s32 temp_2;
            s32 temp_5;
            s8 temp_2_2;
            temp_5 = 0x5C;
            temp_2 = 0x2F;
            while (var_7 < 0xFF) {
                temp_3 = sp40 + var_7;
                temp_4 = *(s8 *)temp_3;
                if ((temp_4 >= 0x61) && (temp_4 < 0x7B)) {
                    *temp_3 = (u8)(temp_4 - 0x20);
                }
                temp_2_2 = *(s8 *)temp_3;
                if (temp_2_2 != 0) {
                    if (temp_2_2 == temp_2) {
                        *temp_3 = (u8)temp_5;
                    }
                    var_7 += 1;
                } else {
                    break;
                }
            }
        }
        func_00456400(arg1, arg1 + temp_16, recordLength, sp40);
        temp_post_4 = (s32)((u32)recordLength + 0x3FU);
        var_3 = temp_post_4 / 64;
        temp_post_3 = var_3 * 64;
        recordLength = temp_post_3;
        var_16 = temp_16 + temp_post_3;
        if (arg2 != 1) {
            goto loop_00456530_body;
        }
    }
}
#pragma pop
