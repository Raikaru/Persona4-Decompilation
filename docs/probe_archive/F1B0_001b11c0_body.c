/* Current b210 owner floor: 192B/192B, five differing bytes/words, both
 * masked and fully relocation-resolved; no tail or unknown relocations.
 * Key/index swap t1/t3 at +0x34,+0x4c,+0x88,+0x9c,+0xa4.
 * Cursor/entry-state grouping and separate count/sort boundaries do not
 * improve this floor. All ten existing owner C matches remain intact.
 * IDA: docs/ida_headstart/src/promoted/code1_001b.c:221-265.
 *
 * Preserve the 16-bit key, exact predicate short circuit, unsigned count-1
 * bound and fresh global base on each pass. Production remains ASM.
 * Nonempty input is a retail precondition, not a recovered universal caller
 * guarantee. Empty input underflows the bound; no synthetic guard is added.
 * Two-genus input with a key selecting either genus is a stable partition.
 * Arbitrary key/genus combinations are not a general sort: [0,1] with key
 * 0x100 oscillates. Do not narrow the key to hide this behavior.
 *
 * Native32 UB-trap smoke: 262,080 cases across four genus pairs, high key
 * bits, unique/duplicate pointers and every binary sequence of lengths 1..12.
 * Checks exact stable ordering and untouched prefix/sentinel/suffix bytes.
 * Singleton actions need no unit; a guard page after entry twelve proves
 * the full-count scan does not read a thirteenth slot.
 */
#pragma opt_loop_invariants on
void func_001b11c0(s32 arg0)
{
    u8 **count_scan;
    u32 count;
    u32 key;
    s32 changed;
    u32 i;
    u8 **scan;
    u8 *left;
    u8 *right;
    u32 kind;

    count_scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
    count = 0;
    while (count < 0xC) {
        if (*count_scan == NULL) break;
        count_scan++;
        count++;
    }
    key = arg0 & 0xFFFF;
    do {
        changed = 0;
        scan = (u8 **)((u8 *)iGpffffb3ac + 0x29C);
        i = 0;
        while (i < count - 1) {
            left = scan[0];
            right = scan[1];
            if (left != NULL && right != NULL) {
                kind = *(u8 *)(*(u8 **)(left + 0x30) + 0xA2);
                if (kind != *(u8 *)(*(u8 **)(right + 0x30) + 0xA2) && kind != key) {
                    scan[0] = right;
                    scan[1] = left;
                    changed = 1;
                }
            }
            i++;
            scan++;
        }
    } while (changed != 0);
}
#pragma opt_loop_invariants off
