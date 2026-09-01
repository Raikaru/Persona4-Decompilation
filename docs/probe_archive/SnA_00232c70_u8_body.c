/* object_size 260, window 272, normalized_diff 0 for func_00232c70; target body exact.
   u8 return/local and natural narrow expressions emit both retail daddiu words.
   Caller func_002384b0 remains MISMATCH (normalized_diff 482) when calls are
   cast through a u32 function pointer; archive before restoring u32 ABI. */
// FUN_00232C70 NONMATCHING
u8 func_00232c70(u8 *arg0, s32 arg1)
{
    u8 v;
    u8 flag;
    s32 temp_3;

    if (((s32)(arg1 & 0xFFFF) < 0) || ((arg1 & 0xFFFF) >= 5)) {
        func_0046d730(D_00635938, 0x313);
    }
    if ((*(u16 *)arg0 & 4) != 0) {
        v = func_00232b40(arg0, arg1);
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x31A);
        }
        v = func_00109bf0((u8 *)(u32)*(u16 *)(arg0 + 2), arg1);
    }
    flag = (*(s32 *)(arg0 + 0xC) & 0x80) != 0;
    if (!flag) {
        goto no_shift;
    }
    v >>= 1;
no_shift:
    temp_3 = v;
    if (temp_3 > 0) {
        goto clamp_value;
    }
    v = 1;
    goto done_value;
clamp_value:
    if (temp_3 <= 0x63) {
        goto done_value;
    }
    v = 0x63;
done_value:
    return v;
}
