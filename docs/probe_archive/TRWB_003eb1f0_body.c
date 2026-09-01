/* object 432B window 448B nd 315; differing offsets begin 20,22,23,26,27,28,29,30,31,32,33,34,35,36,37,38; deficit 4 instructions; classification exact-frame undersized/body-shape; ruled out: optimization_level 1 (leaked 67 sibling mismatches and was removed), no floor instruction */
s32 func_003eb1f0(s8 *arg0, s32 (*arg1)(s32, s32), s32 (*arg2)(s32, s32))
{
    extern void func_0043f810(s8 *arg0, s8 *arg1, s32 arg2);
    extern void (*D_008873B0[])(s8 *arg0, s8 *arg1, s32 arg2);
    extern s32 (*D_008873C8[])(s32 *arg0, s8 *arg1);
    extern void (*D_008873D8[])(s8 *arg0);
    extern void (*D_008873DC[])(s8 *arg0);
    s8 work[20];
    s32 *node;
    s32 *found;
    void (**copy_table)(s8 *arg0, s8 *arg1, s32 arg2) = D_008873B0;
    s32 (**cmp_table)(s32 *arg0, s8 *arg1);

    work[0] = 46;
    copy_table[0](work + 1, arg0, 18);
    work[19] = 0;
    D_008873DC[0](work);
    cmp_table = D_008873C8;
    found = NULL;
    node = *(s32 **)((u8 *)D_008872E0 + iGpffffb7c0 + 0x21c);
    while (node != NULL && found == NULL) {
        if (cmp_table[0](node, work) == 0) {
            found = node;
        } else {
            node = *(s32 **)(node + 0x30);
        }
    }
    if (found == NULL) {
        found = (s32 *)((s8 *(*)(s32, s32, s32))D_008873F8[0])(
            *(s32 *)((u8 *)D_008872E0 + iGpffffb7c0 + 0x218),
            0x30406, iGpffffb7c0);
        if (found != NULL) {
            func_0043f810((s8 *)found, work, 20);
            *(s8 *)((u8 *)found + 20) = 46;
            copy_table[0]((s8 *)found + 21, arg0, 18);
            *(s8 *)((u8 *)found + 39) = 0;
            D_008873D8[0]((s8 *)found + 20);
            found[10] = 0;
            found[11] = 0;
            found[12] = *(s32 *)((u8 *)D_008872E0 + iGpffffb7c0 + 0x21c);
            *(s32 *)((u8 *)D_008872E0 + iGpffffb7c0 + 0x21c) = (s32)found;
        }
    }
    if (found != NULL) {
        if (arg1 != NULL) {
            found[10] = (s32)arg1;
        }
        if (arg2 != NULL) {
            found[11] = (s32)arg2;
        }
        return 1;
    }
    return 0;
}
