/* object 216B / window 208B / normalized_diff 132 / differing offsets 24,25,26,27,28,30,33,34,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207; classification: object-oversized control-flow/layout probe; retail's equality body is an out-of-line forward branch to a shared increment block, but this explicit goto layout grows to 216B; levers ruled out: direct generated-C loop, swapped loop-local declaration order, pointer callee typing, and equality branch placement. */
s32 func_00396680(u8 *arg0, u8 *arg1)
{
    s32 *temp_21;
    s32 temp_20;
    s32 var_17;
    s32 var_16;
    extern s32 func_00397470(u8 *arg0);
    extern u8 *func_003e9680(u8 *arg0);
    extern u8 *func_003e9af0(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2);

    var_17 = 0;
    if (*(s32 *)(arg1 + 4) > 0) {
        var_16 = 0;
loop_1:
        temp_21 = (s32 *)(*(u8 **)(arg1 + 0x10) + var_16);
        temp_20 = *temp_21;
        if (temp_20 == func_00397470(arg0)) {
            goto matched;
        }
advance:
        var_17 += 1;
        var_16 += 0x10;
        if (var_17 < *(s32 *)(arg1 + 4)) {
            goto loop_1;
        }
        goto cleanup;
matched:
        *(s32 *)((u8 *)temp_21 + 0xC) = (s32)arg0;
        goto advance;
    }
cleanup:
    func_003e9680(arg0);
    func_003e9af0(arg0, (s32 (*)(u8 *, s32))func_00396680, (s32)arg1);
    return (s32)arg0;
}
