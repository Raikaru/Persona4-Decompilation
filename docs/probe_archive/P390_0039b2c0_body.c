/* object 176B / window 192B / normalized_diff 61 / differing offsets 16,20,44,76,84,92,104,108,112,116,120,124,128,132,140,144,148,152,156,160,164,168,172,176,180; classification: saved-register colouring/source-order near-miss; current declaration environment remeasurement of archived candidate; levers ruled out: block-scope func_0043f9c8(void *, s32, s32), local declaration permutations, result-local preservation, direct parameter/pointer typing, schedule-off (object 200B), optimization_level 1 (object 204B). */
s32 func_0039b2c0(s32 arg0, s32 arg1)
{
    s32 result;
    s32 temp_17;
    u8 *temp_16;
    u8 *temp_4;
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);

    result = arg0;
    temp_16 = (u8 *)(result + iGpffffb5e0);
    temp_4 = *(u8 **)(temp_16 + 8);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
        *(s32 *)temp_16 = 0;
        *(u8 **)(temp_16 + 8) = NULL;
    }
    temp_17 = arg1 * 0x14;
    temp_4 = (u8 *)jtbl_008873E8[0](temp_17, 0x30105);
    *(u8 **)(temp_16 + 8) = temp_4;
    if (temp_4 == NULL) {
        return 0;
    }
    *(s32 *)temp_16 = arg1;
    func_0043f9c8(*(u8 **)(temp_16 + 8), 0, temp_17);
    return result;
}
