/* object 96B, window 96B, normalized_diff 0; retail uses pexew/ppacw MMI instructions, so no plain-C body was retained. */
void func_003cc680(u8 *arg0, f32 arg1) {
    /* Retail sequence: load x/y/z, scale by 0x437F0001, pexew the first
       pair, pexew the second pair, ppacw into the packet, SQ the result, and
       advance the GP packet pointer by 16 bytes. */
}
