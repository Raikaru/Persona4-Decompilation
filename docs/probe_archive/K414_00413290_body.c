/* object_size=164B window=192B normalized_diff=79; MWCC frameless candidate. */
u8 *func_00413290(u8 *arg0, u32 *arg1, u8 **arg2) {
    u8 *base;
    s32 index;

    if (arg0 == NULL || *(s32 *)arg0 == 0 || arg1 == NULL || *arg1 != -1 || arg2 == NULL || *(s32 *)arg2 == 0) {
        return NULL;
    }
    base = *(u8 **)(arg0 + 8);
    index = ((u8 *)arg2 - base) / 40;
    if (base + index * 40 != (u8 *)arg2 || (u32)index >= *(u32 *)(arg0 + 4)) {
        return NULL;
    }
    *arg1 = index;
    return arg0;
}
