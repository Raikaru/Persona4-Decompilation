/* object 128B/window 112B, normalized_diff 27, differing offsets 4,8,12,16,20,24,32,40,44,48,56,60,64,68,72,76,84,88,92,96,100,104,108,112,116,120,124; casts written: none; levers ruled out: plain-C recheck with no_branch_likely on; object exceeds retail window, archive immediately. */
s32 func_003bd4f0(s32 arg0, s32 arg1, s32 arg2)
{
    s32 result = arg0;

    if (func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x2C, 4) == 0) {
        return 0;
    }
    if (func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x30, 4) == 0) {
        result = 0;
    }
    return result;
}
