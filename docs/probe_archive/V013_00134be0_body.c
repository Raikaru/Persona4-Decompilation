/* measured: object 488B, retail window 448B, normalized_diff 98, differing offsets 0,44-52,60-84,92-112,124-216,236-352,356-396,400-484; archived immediately because object exceeded retail window; ruled out direct structured-loop reconstruction in this lane */
s32 func_00134be0(u8 *arg0)
{
    typedef struct {
        s32 id;
        s16 old_value;
        s16 new_value;
    } Result;
    Result results[4];
    s16 choices[16];
    s16 choice_count;
    s16 outer;
    s16 inner;
    s16 value_index;
    s16 result_count;
    s16 id;
    s16 value;

    func_0043f9c8(choices, 0, 0x20);
    choice_count = func_00353b50(choices);
    result_count = 0;
    outer = 0;
    while (outer < *(s16 *)(arg0 + 0x48)) {
        id = *(s16 *)(arg0 + outer * 2 + 0x38);
        inner = 0;
        while (inner < choice_count && id != choices[inner]) {
            inner++;
        }
        if (inner != choice_count) {
            value_index = 0;
            while (value_index < 3) {
                value = func_00106cd0(id, value_index);
                if (value != *(s16 *)(arg0 + outer * 6 + value_index * 2 + 0xc48) &&
                    value_index == 0) {
                    results[result_count].id = id;
                    results[result_count].old_value =
                        *(s16 *)(arg0 + outer * 6 + value_index * 2 + 0xc48);
                    results[result_count].new_value = value;
                    result_count++;
                }
                value_index++;
            }
        }
        outer++;
    }
    if (result_count > 0) {
        *(s32 *)(arg0 + 0x1594) = func_00167d90(results);
    }
    return result_count > 0;
}
