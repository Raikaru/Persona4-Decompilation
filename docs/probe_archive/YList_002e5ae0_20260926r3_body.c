/* func_002e5ae0 (src/Yajima/y_list.c), 2026-09-26 round 3.
 * Measured with tools/fndiff.py: 77 reloc-masked differing words, object
 * 1860B in the 1872B window (retail's last 3 words are padding, so the
 * instruction count is exact). The previous in-file draft was 302 words.
 *
 * Rebuilt from the retail listing on the model of the matched sibling
 * func_002e6280 (see YList_002e6280_20260926.md). It uses the same inline
 * helpers, yListEntry and yListContains, which here must be defined before
 * func_002e5ae0. Retail really calls func_002e6230 here: the function is
 * defined later in the file, so it is not inlined. Other features: array
 * indexing of the persona table, s16 lo/hi under opt_loop_invariants on
 * (that gives retail's sq/lq spills of the extended values), and no u16 id
 * local. The range test is spelled `hi >= lvl && lo <= lvl`, and the refill
 * loop ends in `while (count <= 5)`; both give retail's $at branch forms.
 *
 * Residual (all 77 words) is a saved-register permutation:
 *   retail: data s0, level/lo/id s1, slot s2, (s8)level s3, list s4,
 *           i s5, k s6, (s16)i s7, i*14/round fp
 *   ours:   slot s0, i s1, list s2, data s3, lo/id s4, (s8)level s5, ...
 * No declaration order changes it (54 of the 120 orders of data/lo/hi/i/round
 * were measured, and all were 77). A `s32 lv = level` copy also stays at 77.
 * s32 lo/hi costs 407, and a separate counter for the second loop costs 254.
 */
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

static inline s32 yListContains(s8 list, s16 id)
{
    s16 k;

    if (D_00882F70[list] != NULL) {
        for (k = 0; k < *(s32 *)(*(u8 **)(D_00882F70[list] + 0x38) + 8); k++) {
            if (id == *(u16 *)(func_002e48a0(list, k) + 2)) {
                return 1;
            }
        }
    }
    return 0;
}

extern s32 func_002e6230(u16 arg0, u16 *arg1);
#pragma push
#pragma opt_loop_invariants on
// FUN_002E5AE0
void func_002e5ae0(s8 list, u16 *exclude, s8 level)
{
    u8 *data;
    s16 lo;
    s16 hi;
    s16 i;
    s16 round;

    if (D_00882F70[list] == NULL) {
        return;
    }
    data = *(u8 **)(D_00882F70[list] + 0x38);
    func_002e5960(list);
    lo = func_002b2d00(level, 10, 1, 99, 1);
    hi = func_002b2cb0(level, 1, 99, 1, 1);
    for (i = 0; i < 0xC0; i++) {
        if (iGpffffb3d4[i * 0xE + 2] >= 2 && iGpffffb3d4[i * 0xE + 2] < 0x16) {
            if (func_00311d00(i) != 0 && func_00311d60(i) != 0 && func_002e6230(i, exclude) == 0 &&
                yListContains(list, i) == 0 && func_00311e40(i) == 0 &&
                hi >= iGpffffb3d4[i * 0xE + 3] && lo <= iGpffffb3d4[i * 0xE + 3]) {
                memset(yListEntry(list, *(s32 *)(data + 8)), 0, 0x30);
                func_0010cad0(yListEntry(list, *(s32 *)(data + 8)), i);
                *(s32 *)(data + 8) += 1;
            }
        }
    }
    if (level >= 60 && *(s32 *)(data + 8) < 3) {
        func_002e5960(list);
    }
    if (*(s32 *)(data + 8) == 0) {
        round = 0;
        do {
            lo = func_002b2d00(level, round * 5 + 10, 1, 99, 1);
            hi = func_002b2cb0(level, round + 1, 99, 1, 1);
            func_002e5960(list);
            for (i = 0; i < 0xC0; i++) {
                if (iGpffffb3d4[i * 0xE + 2] >= 2 && iGpffffb3d4[i * 0xE + 2] < 0x16) {
                    if (func_00311d00(i) != 0 && func_00311d60(i) != 0 && func_002e6230(i, exclude) == 0 &&
                        yListContains(list, i) == 0 && func_00311e40(i) == 0 &&
                        hi >= iGpffffb3d4[i * 0xE + 3] && lo <= iGpffffb3d4[i * 0xE + 3]) {
                        memset(yListEntry(list, *(s32 *)(data + 8)), 0, 0x30);
                        func_0010cad0(yListEntry(list, *(s32 *)(data + 8)), i);
                        *(s32 *)(data + 8) += 1;
                    }
                }
            }
            round++;
        } while (*(s32 *)(data + 8) <= 5);
    }
}
#pragma pop
