/* object 240B/window 208B, normalized_diff 177; differing offsets 4-24,32-60,76-168,176-184,192-200,208-236; classification: oversized structural reconstruction, not a compiler-floor signature. Retail frame 0x40 saves exactly $s0-$s1 and uses a u32 at sp+0x3c plus s32 pair at sp+0x30; prototypes corrected locally for e2f60(s32,s32,s32), df050(u8*,s32,void*,u32*), e2e40(u8*,s32), and bb210(u8*). Setup-order probe puts result initialization after the e2f60 call, reproducing known nd177; object remains 32B oversized, so fallback restored. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor.
s8 *func_003bba90(s32 arg0) {
    extern u8 *func_003e2f60(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_003df050(u8 *arg0, s32 arg1, void *arg2, u32 *arg3);
    extern void func_003e2e40(u8 *arg0, s32 arg1);
    extern s8 *func_003bb210(u8 *arg0);
    u32 size;
    s32 pair[2];
    u8 *temp_2;
    s8 *result;

    temp_2 = func_003e2f60(2, 1, arg0);
    result = NULL;
    if (temp_2 != NULL) {
        if (func_003df050(temp_2, 0xC, NULL, &size) != 0) {
            if ((size >= 0x35000U) && (size < 0x37003U)) {
                result = func_003bb210(temp_2);
            } else {
                pair[0] = 0x102;
                pair[1] = func_003df590(0x80000004);
                func_003df4d0(pair);
            }
        }
        func_003e2e40(temp_2, 0);
    }
    return result;
}
