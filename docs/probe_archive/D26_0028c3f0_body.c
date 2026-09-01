/* func_0028c3f0 reconstruction body — D26 lane 2026-08-21.
 * Best result: normalized_diff 107, object 396B / retail window 400B (MISMATCH).
 * Structure fully decoded: counts entries in lists 3/1/0xC into a stack array,
 * then for each entry scans arg0+0x7A4 table for matching u16 id and calls
 * func_0028c580(arg0, 0) on match. Guard: n >= 0x33 returns early.
 * Residual: MWCC colors arg0 in $s0 while retail uses $s3, cascading into the
 * stack-array base landing at $sp+0x80 vs retail $sp+0x40 and shifting every
 * subsequent store/load offset. Probed without improvement: separate node
 * pointers, shared node pointer, count/table/id locals vs inline expressions,
 * statement-order permutations, declaration-order permutations, dedicated
 * sp40[51] vs big sp[67] with [16+i] indexing, cast-expression loads,
 * explicit i-restart, for-init-clause form, minimal-scalar variant.
 */
void func_0028c3f0(u8 *arg0)
{
    u8 *sp[67];
    u8 *node;
    u8 *node2;
    u8 *node3;
    s32 n;
    s32 i;
    s32 k;
    s32 count;
    s32 *table;
    u16 id;

    n = 0;
    i = 0;
    n += func_00145300(3);
    n += func_00145300(1);
    n += func_00145300(0xC);
    if (n >= 0x33) {
        return;
    }
    for (node = func_001452b0(3); node != NULL; node = *(u8 **)(node + 0x138)) {
        sp[16 + i] = node;
        i++;
    }
    for (node2 = func_001452b0(1); node2 != NULL; node2 = *(u8 **)(node2 + 0x138)) {
        sp[16 + i] = node2;
        i++;
    }
    for (node3 = func_001452b0(0xC); node3 != NULL; node3 = *(u8 **)(node3 + 0x138)) {
        sp[16 + i] = node3;
        i++;
    }
    i = 0;
    for (; i < n; i++) {
        id = *(u16 *)sp[16 + i];
        table = *(s32 **)(arg0 + 0x7A4);
        count = *(s32 *)(arg0 + 0x7A0);
        for (k = 0; k < count; k++) {
            if (*(u16 *)(table + k) == id) {
                func_0028c580(arg0, 0);
                break;
            }
        }
    }
}