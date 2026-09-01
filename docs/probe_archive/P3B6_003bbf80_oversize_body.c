/* object 484B/window 464B, normalized_diff 300; first differing byte offsets 0,4,8,10,12,14,16,18,20,21,22,23,24,26,28,29 (object exceeds retail window; archive immediately). Classification: oversized plain-C reconstruction; candidate frame 0x60 vs retail frame 0x80 and loop/callback register order differs. Corrected struct field accesses and declared block-scope callbacks D_008873D4, D_008873AC, jtbl_008873E8, func_003bd110, func_0043f810. No global changes. Ruled out: no conditional-move, COP1 accumulator, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor in retail; no pragma probe performed. Restored fallback after automatic object-over-window condition. */
// FUN_003BBF80
void func_003bbf80(u8 *arg0, u8 *arg1) {
    extern s32 (*D_008873D4[])(u8 *arg0);
    extern void (*D_008873AC[])(void *arg0, void *arg1);
    extern void *(*jtbl_008873E8[])(u32 size, u32 align);
    extern s32 func_003bd110(s32 arg0);
    extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
    s32 *out;
    s32 *in;
    s32 *src_entry;
    s32 *dst_entry;
    s32 count;
    s32 size;
    u8 *source;
    u8 *destination;

    out = (s32 *)arg0;
    in = (s32 *)arg1;
    out[1] = in[1];
    out[2] = in[2];
    if (in[0] != 0) {
        out[0] = 0;
        source = (u8 *)in[0];
        if (source != NULL) {
            destination = (u8 *)(*jtbl_008873E8)((u32)((*D_008873D4)(source) + 1), 0x30002);
            out[0] = (s32)destination;
            if (destination != NULL) {
                (*D_008873AC)(destination, source);
            }
        }
    }
    if (in[3] != 0) {
        size = out[2] * func_003bd110(out[1]);
        destination = (u8 *)(*jtbl_008873E8)((u32)size, 0x3011F);
        out[3] = (s32)destination;
        if (out[1] == 3) {
            src_entry = *(s32 **)(arg1 + 0x0C);
            dst_entry = *(s32 **)(arg0 + 0x0C);
            count = 0;
            if (out[2] > 0) {
                do {
                    if (*src_entry != 0) {
                        *dst_entry = 0;
                        source = (u8 *)*src_entry;
                        if (source != NULL) {
                            destination = (u8 *)(*jtbl_008873E8)((u32)((*D_008873D4)(source) + 1), 0x30002);
                            *dst_entry = (s32)destination;
                            if (destination != NULL) {
                                (*D_008873AC)(destination, source);
                            }
                        }
                    } else {
                        *dst_entry = 0;
                    }
                    count += 1;
                    src_entry += 1;
                    dst_entry += 1;
                } while (count < out[2]);
            }
        } else {
            func_0043f810((void *)out[3], (void *)in[3], size);
        }
    }
}
