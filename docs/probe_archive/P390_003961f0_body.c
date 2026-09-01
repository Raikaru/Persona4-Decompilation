/* object 212B / window 240B / normalized_diff 139 / differing offsets 40,44,45,46,47,48,49,50,51,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239; classification: arithmetic/control-flow near-miss under the unit's measured O1 scope; O2 probe produced object 228B / normalized_diff 163 and regressed matching sibling func_003963b0, so it was reverted; levers ruled out: byte-pointer field accesses, explicit labels, unsigned division spelling, direct/generated pointer types, and block-scope func_003df300 declaration. */
u8 *func_003961f0(s32 *arg0, u8 *arg1)
{
    u32 sp6C;
    s32 *temp_16;
    s32 *var_17;
    s32 var_18;
    extern s32 func_003df300(s32 *arg0, s32 *arg1, s32 arg2);

    temp_16 = *(s32 **)(arg1 + 0x10);
    var_18 = 0;
    if (*(s32 *)(arg1 + 4) <= 0) {
        goto block_1;
    }
    var_17 = temp_16;
loop_3:
    if (func_003df300(arg0, var_17 + 1, 0x20) == 0) {
        goto block_8;
    }
    if (func_003df360((s32)arg0, (s32 *)&sp6C, 4) == 0) {
        goto block_8;
    }
    var_18 += 1;
    *var_17 = (s32)((u8 *)temp_16 + (sp6C / 36) * 0x24);
    var_17 = (s32 *)((u8 *)var_17 + 0x24);
    if (var_18 >= *(s32 *)(arg1 + 4)) {
        goto block_1;
    }
    goto loop_3;
block_1:
    return arg1;
block_8:
    return NULL;
}
