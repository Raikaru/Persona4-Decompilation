/* Best plain-C attempt: object 84B/window 96B, normalized_diff 7 (build/FP3B_3b6da0_archived_probe.json). */
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffb680 = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    D_00885A90[0] = value;
    if (count != 0) {
        factor = 0x10DCD;
        do {
            value *= factor;
            count -= 1;
            *ptr = value;
            ptr += 1;
        } while (count != 0);
    }
}
