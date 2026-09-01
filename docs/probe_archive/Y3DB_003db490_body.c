/* measured: object 200B vs 192B window, normalized_diff 111; differing offsets (fndiff first_diffs byte offsets) [16,17,18,19,20,21,22,23,32,33,34,35,36,40,42,43]; casts written: no conversion idiom, only callback/pointer casts; levers ruled out: corrected callback and float helper declarations at block scope, retained direct field loads; automatic archive because object exceeds retail window. */
s32 func_003db490(s32 arg0, u8 *arg1) {
    f32 value;
    s32 count;
    extern u8 *func_003ca320(u8 *arg0, s32 (*arg1)(u8 *, s32), s32 arg2);
    extern s32 func_003db440(s32 arg0, u8 *arg1);
    extern f32 func_0044b968(f32 arg0);
    extern s32 *func_003f6800(s32 *arg0, f32 fparg0);

    *(s32 *)(arg1 + 8) = arg0;
    *(s32 *)(arg1 + 0xC) = 0;
    *(s32 *)(arg1 + 0x10) = 0;
    func_003ca320(*(u8 **)(arg1 + 4),
                  (s32 (*)(u8 *, s32))func_003db440, (s32)arg1);
    count = *(s32 *)(arg1 + 0x10);
    if (count > 0) {
        value = func_0044b968(*(f32 *)(arg1 + 0xC) / (f32)count);
        func_003f6800((s32 *)arg0, -(value / func_0044b968(2.0f)));
    }
    return arg0;
}
