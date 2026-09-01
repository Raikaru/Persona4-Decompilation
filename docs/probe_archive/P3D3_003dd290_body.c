/* object 288B / window 256B / normalized_diff 207 / differing offsets 16,17,18,19,20,22,25,26,28,29,30,31,33,34,36,37 (first rows; broad residual) / classification oversized automatic archive; block-scope declarations used func_003dd7d0(void), func_003dd990(s32), func_003dd620(u8*,s32), and D_008873AC function-pointer table; direct callback typedef used for arg0+0x14; ruled out movz/movn, COP1 accumulator chain, standalone MMI, framed tail jump, custom COP1 sqrt, rd-form mult floor. Existing source comment records an older unrelated candidate but no body archive was present. */
s32 func_003dd290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 func_003dd7d0(void);
    extern s32 func_003dd990(s32 arg0);
    extern s32 func_003dd620(u8 *arg0, s32 arg1);
    extern void (*D_008873AC[])(void *arg0, void *arg1);
    typedef u8 *(*Dd290Callback)(u8 *arg0, s32 arg1);
    s32 result;
    s32 index;
    u8 *item;
    Dd290Callback callback;

    if (func_003dd7d0() == 0) {
        return 2;
    }
    if (func_003dd990(arg2) != 0) {
        return 6;
    }
    (*D_008873AC)(arg0 + 0x50, (void *)(s32)arg2);
    *(s32 *)(arg0 + 0x4) = arg1;
    index = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    if (arg1 > 0) {
        do {
            callback = *(Dd290Callback *)(arg0 + 0x14);
            item = callback(arg0, index);
            index += 1;
            *(s32 *)(item + 0x38) = 1;
            *(s32 *)(item + 0x30) = *(s32 *)(arg0 + 0x10);
        } while (index < arg1);
    }
    *(s32 *)(arg0 + 0xc) = 0;
    result = func_003dd620(arg0, arg3);
    if (result != 1) {
        return result;
    }
    *(s32 *)(arg0 + 0x8) = 2;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    return 1;
}
