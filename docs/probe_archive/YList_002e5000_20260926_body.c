/* func_002e5000 round-2 draft: 97 reloc-masked differing words (608B vs 624B window).
 * Earlier banked YL_002e5000_body.c measured 90; this LICM version is kept for its
 * structure (inline list-head/entry helpers reproduce the retail duplicated switch). */
static inline u8 *yListHead(s8 list)
{
    return *(u8 **)(D_00882F70[list] + 0x38);
}

static inline u8 *yListEntry(s8 list, s16 index)
{
    u8 *p = *(u8 **)(D_00882F70[list] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((index * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((index * 3) * 0x10) + 0xA4;
    default:
        return p + ((index * 3) * 0x10) + 0x14;
    }
}

extern s32 func_003129b0(u8 *arg0, s32 arg1, s32 arg2);
#pragma opt_loop_invariants on
// FUN_002E5000
void func_002e5000(void)
{
    u8 *base;
    u8 *row;
    u8 *flag;
    s16 i;
    s16 j;

    base = yListHead(0);
    for (i = 0; i < *(s32 *)(yListHead(0) + 8); i++) {
        j = 0;
        row = base + i * 12;
        for (; j < *(s32 *)(yListHead(0) + 8); j++) {
            flag = row + 0x14 + j;
            *flag = 0;
            if (func_003129b0(yListEntry((s8)(i + 1), j), *(u16 *)(yListEntry(0, i) + 2),
                              *(u16 *)(yListEntry(0, j) + 2)) == 1) {
                *flag = 1;
            }
        }
    }
}
#pragma opt_loop_invariants off
