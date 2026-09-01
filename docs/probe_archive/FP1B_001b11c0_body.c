/* Best probe for func_001b11c0: object 192B, retail window 192B, normalized_diff 22. */
void func_001b11c0(u32 arg0)
{
    u32 count;
    u32 bound;
    u32 index;
    u32 filter;
    u32 one;
    u32 swapped;
    u8 **scan;
    u8 **list;
    u8 *left;
    u8 *right;

    scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
    count = 0;
    goto count_check;
count_loop:
    if (*scan == NULL) goto count_done;
    scan += 1;
    count += 1;
count_check:
    if (count < 0xC) goto count_loop;
count_done:
    filter = arg0 & 0xFFFF;
    one = 1;
    bound = count - 1;
    do {
        swapped = 0;
        list = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
        index = 0;
        goto sort_check;
sort_loop:
        left = list[0];
        right = list[1];
        if (left != NULL && right != NULL) {
            count = *(u8 *)(*(u8 **)(left + 0x30) + 0xA2);
            if (count != *(u8 *)(*(u8 **)(right + 0x30) + 0xA2) &&
                count != filter) {
                list[0] = right;
                list[1] = left;
                swapped = one;
            }
        }
        index += 1;
        list += 1;
sort_check:
        if (index < bound) goto sort_loop;
    } while (swapped != 0);
}
