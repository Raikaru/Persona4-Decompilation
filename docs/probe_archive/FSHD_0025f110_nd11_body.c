/* object 288B / window 288B / normalized_diff 11; differing words at byte offsets 0x18, 0x1c, 0x20, 0x54, 0xdc, 0xe0, 0xe4, 0xe8. Corrected block-scope callee prototypes, result-pointer reuse, persistent tail-index, table-pointer caching, integer-domain addressing, guard/loop/tail forms, declaration order, and compiler lifetime pragmas were measured; residual remains table-pointer and tail reload register coloring. */
s32 func_0025f110(u8 *arg0)
{
    u8 *func_00455f70(s32, s32 *);
    u8 *func_0046af60(u32);
    u8 *func_0046aea0(const char *);
    s32 func_0046a750(s16 *);
    s32 temp;
    s32 index;
    s32 offset;
    u8 *result;

    index = *(s32 *)arg0;
    if (index >= *(s32 *)(*(u8 **)(arg0 + 4) + 4)) {
        return 1;
    }
    for (;;) {
        result = *(u8 **)(arg0 + 8);
        offset = index * 4;
        if (*(u8 **)(result + offset) == NULL) {
            result = func_00455f70(
                (s32)*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4)) + offset),
                &temp);
            if (result != NULL) {
                *(u8 **)(*(u8 **)(arg0 + 8) + offset) =
                    func_0046af60((s32)result);
            } else {
                *(u8 **)(*(u8 **)(arg0 + 8) + offset) =
                    func_0046aea0(
                        (const char *)(*(u8 **)(*(u8 **)
                            (*(u8 **)(arg0 + 4)) + offset)));
            }
        } else {
            if (func_0046a750(
                    (s16 *)*(u8 **)(result + offset)) == 0) {
                goto fail;
            }
            *(s32 *)arg0 = *(s32 *)arg0 + 1;
        }
        {
            s32 tail_index;
            tail_index = *(s32 *)arg0;
            if (tail_index >= *(s32 *)(*(u8 **)(arg0 + 4) + 4)) {
                break;
            }
        }
    }
    return 1;
fail:
    return 0;
}
