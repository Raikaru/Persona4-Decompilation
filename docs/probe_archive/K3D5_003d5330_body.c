/* Current remeasurement: object 164B, retail window 144B, normalized_diff 112; oversized candidate restored to ASM immediately. Prior schedule/no_branch_likely and two-word-tail notes are stale after declaration changes. */
u8 *func_003d5330(s32 arg0) {
    extern s32 *func_003e2f60(s32, s32, s32);
    extern s32 func_003df050(s32 *, s32, s32 *, s32 *);
    extern u8 *func_003d53c0(s32 *);
    extern void func_003e2e40(s32 *, s32);
    s32 *temp_2;
    u8 *temp_17;

    temp_2 = func_003e2f60(2, 1, arg0);
    if (temp_2 != NULL) {
        if (func_003df050(temp_2, 0x1B, NULL, NULL) == 0) {
            return NULL;
        }
        temp_17 = func_003d53c0(temp_2);
        func_003e2e40(temp_2, 0);
        return temp_17;
    }
    return NULL;
}
