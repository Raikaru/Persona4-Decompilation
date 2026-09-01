/* object 228B / window 224B / normalized_diff 159 / differing offsets 8,9,10,11,12,18,19,20,22,23,24,26,32,34,36,38 / classification oversized; callback prototype five args (void *,u8 *,s32,s32,u8 *), s64 arg1 cast to s32, s32 work[12] stack slots; no callee/global declaration changes; ruled out: movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor; natural conditionals reduce prior candidate to 228B but preserve arg0 in v1 and evaluate indirect callee after args. */
// FUN_003DE020
s32 func_003de020(u8 *arg0, s64 arg1, s32 arg2) {
    typedef void (*Callback)(void *, u8 *, s32, s32, u8 *);
    u8 *temp_8;
    s32 work[12];

    temp_8 = *(u8 **)(arg0 + 0x50) + 0x28;
    if (*(s32 *)(arg0 + 0x30) != 0) {
        *(s32 *)(arg0 + 0x40) = 4;
        *(s32 *)(arg0 + 0x38) = 3;
    }
    if (arg2 == 0) {
        ((Callback)(*(void **)(temp_8 + 0x10)))(&work[0], arg0, (s32)arg1, 1, temp_8);
        return 0;
    }
    if (arg2 == 2) {
        ((Callback)(*(void **)(temp_8 + 0x10)))(&work[4], arg0, (s32)arg1, 3, temp_8);
        return 0;
    }
    if (arg2 == 1) {
        ((Callback)(*(void **)(temp_8 + 0x10)))(&work[8], arg0, (s32)arg1, 2, temp_8);
        return 0;
    }
    return -1;
}
