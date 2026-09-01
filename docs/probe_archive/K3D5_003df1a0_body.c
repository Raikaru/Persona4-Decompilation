/* object 184B, retail window 160B, normalized_diff 139; oversized reconstruction archived. */
s32 *func_003df1a0(s32 *arg0, s32 arg1, u32 arg2) {
    u8 buffer[0x100];
    u32 chunk;

    if (arg2 != 0) {
        do {
            if (arg2 < 0x100U) {
                chunk = arg2;
            } else {
                chunk = 0x100;
            }
            func_0043f810(buffer, (void *)arg1, chunk);
            if (func_003e2ab0(arg0, buffer, chunk) == 0) {
                return NULL;
            }
            arg2 -= chunk;
            arg1 += chunk;
        } while (arg2 != 0);
    }
    return arg0;
}
