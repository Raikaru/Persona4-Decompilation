/* object 148B, retail window 144B, normalized_diff 91; oversized reconstruction archived. */
u8 *func_003d5130(s32 arg0, s32 *arg1) {
    extern s32 func_003df590(s32, ...);
    extern u8 *func_003df4d0(s32 *);
    u8 *entry;
    s32 count;
    s32 index;
    s32 sp18;
    s32 sp1C;

    count = iGpffffb734;
    index = 0;
    if (count <= 0) {
        goto error;
    }
    entry = (u8 *)D_00886E50;
    do {
        if (arg0 == *(s32 *)entry) {
            return (u8 *)D_00886E50 + index * 0x30;
        }
        index += 1;
        entry += 0x30;
    } while (index < count);
error:
    sp18 = 0x1B7;
    sp1C = func_003df590(2);
    func_003df4d0(&sp18);
    return NULL;
}
