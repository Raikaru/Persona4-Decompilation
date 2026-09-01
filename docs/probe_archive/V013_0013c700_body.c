/* measured: object 880B, retail window 864B, normalized_diff 177, differing offsets 48-88,100-136,144-180,188-232,240-288,296-344,352-432,440-876; archived immediately because object exceeded retail window; ruled out corrected callee declarations, pointer-vs-array entry staging, state switch shape, and direct generated-loop reconstruction */
s32 func_0013c700(s32 arg0, s16 arg1, u8 *arg2)
{
    extern void func_00106390(s32 arg0, s32 arg1);
    extern void func_0010f770(s16 arg0, s16 arg1, u32 arg2, u32 arg3);
    extern void func_0012e7c0(u8 *arg0);
    extern s32 func_0012ff40(s32 arg0, s32 arg1, s16 arg2);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern u8 D_005ED9D0[];
    extern s32 func_00354010(void);
    s32 state;
    s32 index_count;
    s32 index;
    s16 item;
    s16 item_type;
    s16 entry_index;
    s16 remaining;
    s16 total;
    s16 updated;
    u8 *entry;

    state = 1;
    total = *(s16 *)(arg2 + 0x24) + *(s16 *)(arg2 + 0x22);
    item = *(s16 *)(arg2 + total * 4 + 0x3E);
    item_type = *(u16 *)(func_00106820(item) + 0x24);
    if (item_type == 246) {
        if (func_00354010() != 0) state = 3;
        else state = 0;
    } else if (arg1 == -1) {
        index_count = 0;
        index = 0;
        while (index < *(s16 *)(arg2 + 0x3C)) {
            entry = arg2 + index * 2 + 0x34;
            if (func_0013ca60(arg0, *(s16 *)entry, item_type) != 0) {
                func_0010f770((s16)arg0, *(s16 *)entry, item_type, 1);
                index_count++;
            }
            index++;
        }
        if (index_count == 0) state = 0;
    } else if (func_0013ca60(arg0, arg1, item_type) != 0) {
        func_0010f770((s16)arg0, arg1, item_type, 1);
    } else state = 0;
    if (state > 0) {
        updated = (s16)(func_00106600(item) & 0xff) - 1;
        if (updated < 0) func_0046d730(D_005ED9D0, 0x29c);
        func_00106620(item, updated & 0xff);
        if (state != 3) {
            func_00130430(arg2);
            entry_index = total;
            entry = arg2 + entry_index * 4;
            remaining = *(s16 *)(entry + 0x40) - 1;
            *(s16 *)(entry + 0x40) = remaining;
            if (remaining == 0) {
                func_0012e7c0(arg2);
                total = *(s16 *)(arg2 + 0xc3e);
                if (total < 6) {
                    func_0012ff40((s32)arg2, 1, 0);
                    total = *(s16 *)(arg2 + 0xc3e) - 1;
                    if (total < *(s16 *)(arg2 + 0x22)) func_0012ff40((s32)arg2, 0, total);
                } else {
                    total -= 6;
                    if (total < *(s16 *)(arg2 + 0x24)) func_0012ff40((s32)arg2, 1, total);
                }
                state = 2;
            }
        } else func_00106390(5121, 1);
    }
    if (state == 3) return state;
    if (state == 2 || state == 1) func_0045af60(1, 3, 2, 22);
    else if (state == 0) func_0045af60(0, 0, 0, 8);
    else func_0046d730(D_005ED9D0, 0x2ca);
    return state;
}
