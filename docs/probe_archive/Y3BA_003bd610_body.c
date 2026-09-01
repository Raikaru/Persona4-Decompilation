/* object 136B/window 112B, normalized_diff 29, differing offsets 4,8,12,16,20,24,32,40,44,48,56,60,64,68,72,76,84,88,92,96,100,104,108,112,116,120,124,128,132; casts written: none; levers ruled out: plain-C recheck with s32/s32/u8* signature; object exceeds retail window, archive immediately. */
s32 func_003bd610(s32 arg0, s32 arg1, u8 *arg2) {
    s32 r;

    if (func_003df240(arg0, *(s32 *)(arg2 + 0x7C) + 0x2C, 4) == 0) {
        return 0;
    }
    r = func_003df240(arg0, *(s32 *)(arg2 + 0x7C) + 0x30, 4);
    return r ? arg0 : 0;
}
