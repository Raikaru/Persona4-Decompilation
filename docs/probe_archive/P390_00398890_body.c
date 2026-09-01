/* object 240B / window 224B / normalized_diff 139 / differing offsets 4,6,7,8,10,11,12,14,16,17,18,19,21,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223; classification: object-oversized error-path reconstruction; retail window is 224B and this direct-C body grows to 240B; levers ruled out: generated-C control flow, explicit return labels, exact df360/df050/df550/df4d0/e6430 callee declarations, and contiguous two-word error storage. */
s32 *func_00398890(s32 *arg0, u8 ***arg1)
{
    s32 sp3C;
    s32 sp30[2];
    extern s32 func_003df050(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
    extern u8 *func_003df550(s32 *arg0);
    extern u8 *func_003df4d0(s32 *arg0);
    extern u8 **func_003e6430(s32 *arg0);

    if (func_003df360((s32)arg0, &sp3C, 4) == 0) {
        goto block_11;
    }
    if (sp3C == 0) {
        *arg1 = NULL;
        goto block_3;
    }
    if (func_003df050(arg0, 6, 0, 0) == 0) {
        goto block_11;
    }
    func_003df550(sp30);
    *arg1 = func_003e6430(arg0);
    if (*arg1 == NULL) {
        func_003df550(sp30);
        if (sp30[1] != (s32)0x80000000 && sp30[1] != 0x16) {
            func_003df4d0(sp30);
            goto block_11;
        }
    }
block_3:
    return arg0;
block_11:
    return NULL;
}
