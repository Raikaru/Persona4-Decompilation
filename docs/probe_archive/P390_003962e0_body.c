/* object 188B / window 208B / normalized_diff 147 / differing offsets 4,6,7,8,10,11,12,14,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196; classification: control-flow/register-layout near-miss; current declaration environment remeasurement of archived reconstruction; levers ruled out: direct generated-C structure, positive guard polarity, explicit branch labels, no-branch-likely bracket, block-scope callee declaration, and local count hoisting. */
s32 func_003962e0(u8 *arg0, s32 *arg1)
{
    s32 sp6C;
    s32 *temp_16;
    s32 *var_17;
    s32 var_18;
    extern s32 func_003df1a0(s32 *arg0, s32 *arg1, s32 arg2);

    temp_16 = *(s32 **)(arg0 + 0x10);
    if (*(s32 *)(arg0 + 4) > 0) {
        goto block_2;
    }
block_1:
    return 1;
block_2:
    var_18 = 0;
    var_17 = temp_16;
loop_3:
    if (func_003df1a0(arg1, (s32 *)((u8 *)var_17 + 4), 0x20) == 0) {
        goto block_8;
    }
    sp6C = *var_17 - (s32)temp_16;
    if (func_003df240((s32)arg1, &sp6C, 4) == 0) {
        goto block_8;
    }
    var_18 += 1;
    var_17 = (s32 *)((u8 *)var_17 + 0x24);
    if (var_18 < *(s32 *)(arg0 + 4)) {
        goto loop_3;
    }
    goto block_1;
block_8:
    return 0;
}
