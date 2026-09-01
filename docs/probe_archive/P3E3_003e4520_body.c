/* object_size=192B window=208B normalized_diff=69 differing_offsets(first_diffs)=[6,14,22,23,26,27,28,30,31,32,33,34,36,37,38,39] fndiff_differing_words=41 classification=source-shape/register-allocation/control-flow near-miss; schedule on + no_branch_likely on retained; no confirmed floor. Ruled out direct M2C field spelling, pointer-vs-u32 base/value types, raw declaration order, explicit link-pointer local, direct arithmetic vs total local, initial guard polarity, explicit out-of-line fallback goto graph, and schedule/no_branch_likely variants. */
void func_003e4520(u8 *arg0) {
    s32 total;
    u8 *value;
    u8 *temp;
    u8 *temp4_4;
    u8 *prev;
    u8 *next;
    u8 *base;

    *(s32 *)(arg0 - 0x10) = 0;
    base = arg0 - 0x20;
    next = *(u8 **)(arg0 - 0x18);
    prev = *(u8 **)(arg0 - 0x1C);
    temp = *(u8 **)(arg0 - 0x20);
    value = *(u8 **)(temp + 4);
    if (value == NULL || (u32)base < (u32)value) {
        *(u8 **)(temp + 4) = base;
    }
    if (next != NULL && ((~*(s32 *)(next + 0x10) & 1) != 0)) {
        *(u8 **)(next + 4) = prev;
        if (prev != NULL) {
            *(u8 **)(prev + 8) = next;
        }
        total = *(s32 *)(next + 0xC) + *(s32 *)(base + 0xC) + 0x20;
        base = next;
        *(s32 *)(next + 0xC) = total;
    }
    if (prev != NULL && ((~*(s32 *)(prev + 0x10) & 1) != 0)) {
        *(u8 **)(base + 4) = *(u8 **)(prev + 4);
        temp4_4 = *(u8 **)(prev + 4);
        if (temp4_4 != NULL) {
            *(u8 **)(temp4_4 + 8) = base;
        }
        *(s32 *)(base + 0xC) =
            *(s32 *)(base + 0xC) + *(s32 *)(prev + 0xC) + 0x20;
    }
}
