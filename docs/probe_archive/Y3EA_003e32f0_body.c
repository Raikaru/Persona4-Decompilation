/* object_size=140 window=128 normalized_diff=108 differing_offsets=6,7,8,10,11,12,13,14,15,16,18,19,20,21,22,23; casts_written=none; levers_ruled_out=plain conditional return emits a 140-byte body larger than retail; retail contains movz $s0,$zero,$v0, a known MWCCPS2 conditional-move floor, and no compliant C source shape was retained. */
u8 *func_003e32f0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 (*callback)(s32, s32, s32);
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
        do {
            if (*(s32 *)(node + 8) == arg1) {
                break;
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    if (node != NULL) {
        callback = *(s32 (**)(s32, s32, s32))(node + 0x1C);
        if (callback != NULL) {
            if (callback(arg2, *(s32 *)(node + 0), *(s32 *)(node + 4)) == 0) {
                return NULL;
            }
            return arg0;
        }
    }
    return NULL;
}
