/* object 156B / window 176B / normalized_diff 97 / differing offsets 16,17,18,19,20,21,22,23,33,38,40,43,45,46,48,50; casts written: (u32)temp_18 for allocator size, (void *) source pointer; levers ruled out: callee declaration corrected block-scope, declaration order, explicit result/local staging, branch polarity/goto, argument staging, O1 probe. */
// FUN_0039AE90
s32 func_0039ae90(s32 arg0, s32 arg1)
{
    extern void func_0043f810(void *dst, void *src, u32 size);
    s32 temp_18;
    s32 temp_2;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_19;
    s32 temp_20;

    temp_2 = iGpffffb5f0;
    temp_16 = (u8 *)(arg1 + temp_2);
    temp_4 = *(s32 *)temp_16;
    temp_17 = (u8 *)(arg0 + temp_2);
    if (temp_4 <= 0) {
        goto block_1;
    }
    temp_18 = temp_4 * 0x14;
    *(u8 **)(temp_17 + 8) = (*jtbl_008873E8)((u32)temp_18, 0x30105);
    if (*(u8 **)(temp_17 + 8) == NULL) {
        return 0;
    }
    temp_20 = *(s32 *)temp_16;
    temp_19 = (u8 *)(*(s32 *)(temp_16 + 8));
    *(s32 *)temp_17 = temp_20;
    func_0043f810(*(u8 **)(temp_17 + 8), temp_19, temp_18);
block_1:
    return arg0;
}
