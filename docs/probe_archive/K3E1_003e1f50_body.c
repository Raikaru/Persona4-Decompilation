/* object_size=152B window=160B normalized_diff=58 differing_offsets=0x10-0x90; declaration-order probe (list0/list1 swapped) did not improve; ruled out direct linked-list C spelling and declaration-order swap within this readable reconstruction. */
void func_003e1f50(void) {
    u8 *base;
    u8 *list1;
    u8 *list0;
    u8 *node0;
    u8 *node1;
    u8 *tmp;

    base = (u8 *)D_008872E0 + (s32)iGpffffb780;
    list0 = *(u8 **)(base + 0x20);
    node0 = *(u8 **)list0;
    list1 = *(u8 **)(base + 0x24);
    if (node0 != list0) {
        node1 = *(u8 **)list1;
        if (node1 != list1) {
            tmp = *(u8 **)(list1 + 4);
            *(u8 **)tmp = node0;
            *(u8 **)(node0 + 4) = tmp;
            tmp = *(u8 **)(list0 + 4);
            *(u8 **)tmp = list1;
            *(u8 **)(list1 + 4) = tmp;
            *(u8 **)list0 = list0;
            *(u8 **)(list0 + 4) = list0;
        } else {
            *(u8 **)list1 = node0;
            tmp = *(u8 **)list1;
            *(u8 **)(tmp + 4) = list1;
            tmp = *(u8 **)(list0 + 4);
            *(u8 **)(list1 + 4) = tmp;
            tmp = *(u8 **)(list1 + 4);
            *(u8 **)tmp = list1;
            *(u8 **)list0 = list0;
            *(u8 **)(list0 + 4) = list0;
        }
    }
    base = (u8 *)D_008872E0 + (s32)iGpffffb780;
    *(u8 **)(base + 0x24) = list0;
    *(u8 **)(base + 0x20) = list1;
    *(s32 *)(base + 8) = 0;
}
