/* object 192B, retail window 192B, normalized_diff 29; differing byte offsets 0x34, 0x38, 0x3C, 0x40, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64, 0x68, 0x6C, 0x70, 0x74, 0x78, 0x7C, 0x80, 0x84, 0x88, 0x90, 0x94, 0x98, 0x9C, 0xA0, 0xA4, 0xA8, 0xB0, 0xB4; classification: register coloring and source-shape residual; the 0xffff mask is exact when filter is u16, but the t1/t2 list-index and a2/a3 left-right register assignments stay swapped against retail. F1B0 archive tested u8 filter, integer list/left/right locals, and index initialization before list materialization. LaneSingles 2026-09-03 retest: u8 -> u16 filter gives same nd 29. */
void func_001b11c0(u32 arg0)
{
    u32 count;
    u16 filter;
    u32 one;
    s32 bound;
    u32 swapped;
    u32 index;
    u8 **scan;
    s32 *list;
    s32 left;
    s32 right;

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
        index = 0;
        list = (s32 *)((u8 *)iGpffffb3ac + 0x29C);
        goto sort_check;
sort_loop:
        left = *(s32 *)list;
        right = *(s32 *)(list + 1);
        if (left != 0 && right != 0) {
            count = *(u8 *)(*(u8 **)((u8 *)left + 0x30) + 0xA2);
            if (count != *(u8 *)(*(u8 **)((u8 *)right + 0x30) + 0xA2) &&
                count != filter) {
                *(s32 *)list = right;
                *(s32 *)(list + 1) = left;
                swapped = one;
            }
        }
        index += 1;
        list += 1;
sort_check:
        if (index < bound) goto sort_loop;
    } while (swapped != 0);
}
