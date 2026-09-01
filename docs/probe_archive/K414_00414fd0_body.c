/* object_size=160B window=160B normalized_diff=93; MWCC sq-prologue candidate, global jump-table pointer and saved-local coloring ruled out. */
extern void (*jtbl_008873EC[])(void *ptr);
void func_00414fd0(u32 *arg0) {
    u32 *temp_17;
    u32 *temp_4;
    u32 *var_4;

    if (arg0 != NULL) {
        temp_4 = (u32 *)(*(u32 **)((s8 *)arg0 + 0xC));
        if (temp_4 != NULL) {
            (*jtbl_008873EC)(temp_4);
            *(u32 **)((s8 *)arg0 + 0xC) = NULL;
        }
        var_4 = (u32 *)(*(u32 **)((s8 *)arg0 + 4));
        if (var_4 != NULL) {
            do {
                temp_17 = (u32 *)(*(u32 **)((s8 *)var_4 + 8));
                if (var_4 != NULL) {
                    (*jtbl_008873EC)(var_4);
                }
                var_4 = temp_17;
            } while (temp_17 != NULL);
        }
        (*jtbl_008873EC)(arg0);
    }
}
