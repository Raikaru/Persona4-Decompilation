/* object_size=132 window=128 normalized_diff=85 differing_offsets=16,17,18,19,20,21,22,23,28,29,31,32,33,35,36,38,40,41,43,44,45,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,124,125,128; casts_written=none; levers_ruled_out=direct generated loop body is oversized by one instruction and has a loop-exit/epilogue block-layout residual; no pragma or declaration change attempted because size exceeded retail window. */
s32 func_003e3370(u8 *arg0, s32 arg1) {
    s32 (*callback)(s32, s32, s32);
    s32 callback_result;
    s32 total;
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    total = 0;
    if (node != NULL) {
        do {
            callback = *(s32 (**)(s32, s32, s32))(node + 0x14);
            if (callback != NULL) {
                callback_result = callback(arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
                if (callback_result > 0) {
                    total += callback_result + 0xC;
                }
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    return total;
}
