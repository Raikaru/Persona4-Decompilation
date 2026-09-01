/*
 * object_size=432; window=432; normalized_diff=7;
 * differing_offsets=[316,320,328,332,336,340,404].
 * classification=NEAR_MATCH_REGISTER_ALLOCATION;
 * corpus=IDA/Ghidra agree on control flow and field widths.
 * ruled_out=volatile, inline asm, COP1 accumulator chain, addiu-vs-daddiu
 * constant spelling, pragma-only shaping, and alternate switch control flow.
 * Callback argument setup was matched with explicit temporaries/casts; the
 * remaining seven words are the counter sentinel/increment and overflow-store
 * register choices. This is the best measured body before rollback.
 */

static inline void code1_0047_abd0(s16 arg0, s32 arg1, s16 arg2)
{
    func_0045abd0(arg0, arg1, arg2);
}

void func_0047ed60(u8 *arg0)
{
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_4;
    s16 temp_4_2;
    s32 var_16;
    u8 *temp_3;
    s16 call_a0;
    s16 call_a2;
    s32 call_a1;

    func_0047e6f0(arg0);
    temp_3 = *(u8 **)arg0;
    if (temp_3 != NULL && (*(u16 *)(temp_3 + 0x12) & 1) != 0) {
        var_16 = 1;
        temp_3_2 = *(s16 *)(arg0 + 0x16);
        if (temp_3_2 >= 0) {
            if (temp_3_2 == 0) {
                temp_3_3 = ((*(u16 *)(arg0 + 0x10) & 0x20) != 0);
                if (temp_3_3 != 0) {
                    call_a0 = *(s16 *)(arg0 + 0x12);
                    call_a2 = *(s16 *)(arg0 + 0x14);
                    call_a1 = *(s32 *)(arg0 + 0x18);
                    code1_0047_abd0((s16)call_a0, (s32)call_a1, (s16)call_a2);
                }
                *(s16 *)(arg0 + 0x16) = -1;
            } else {
                *(s16 *)(arg0 + 0x16) = temp_3_2 - 1;
                var_16 = 0;
            }
        }
        temp_4 = *(s16 *)(arg0 + 0x24);
        if (temp_4 >= 0) {
            if (temp_4 == 0) {
                call_a0 = *(s16 *)(arg0 + 0x1E);
                call_a2 = *(s16 *)(arg0 + 0x20);
                temp_3_3 = *(s16 *)(arg0 + 0x22);
                func_0045af60(*(s16 *)(arg0 + 0x1C), call_a0, call_a2,
                              temp_3_3);
                *(s16 *)(arg0 + 0x26) = *(s16 *)(arg0 + 0x1C);
                *(s16 *)(arg0 + 0x24) = -1;
            } else {
                *(s16 *)(arg0 + 0x24) = temp_4 - 1;
                var_16 = 0;
            }
        } else if (temp_4 == -2) {
            temp_4_2 = *(s16 *)(arg0 + 0x26);
            if (temp_4_2 >= 0) {
                func_0045aa90(temp_4_2, *(s16 *)(arg0 + 0x1E));
                *(s16 *)(arg0 + 0x26) = -1;
            }
            *(s16 *)(arg0 + 0x24) = -1;
        }
        if (*(s32 *)(arg0 + 0xC) != 0 && var_16 == 1 &&
            *(s16 *)(arg0 + 8) != -1) {
            temp_3_4 = *(s16 *)(arg0 + 8) + 1;
            *(s16 *)(arg0 + 8) = temp_3_4;
            if (temp_3_4 < 8) {
                call_a1 = *(u16 *)(arg0 + 0x06);
                if (func_0047e0f0(arg0, *(s16 *)(arg0 + 0x08),
                                  *(s16 *)(arg0 + 0x04), (u16)call_a1) == 0) {
                    *(s16 *)(arg0 + 8) = -1;
                }
            } else {
                *(s16 *)(arg0 + 8) = -1;
            }
        }
    }
}
