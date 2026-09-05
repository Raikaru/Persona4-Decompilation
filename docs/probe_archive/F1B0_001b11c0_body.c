/* MWCCPS2 b210, -O2 -Iinclude; opt_loop_invariants on.
 * Object/window 192B/192B; five differing words, all register coloring:
 * key is t1 instead of t3 at 0x34/0x88; index is t3 instead of t1 at
 * 0x4C/0x9C/0xA4. Explicit bound: 26 words; compiler-hoisted fresh bound:
 * 11 words; declaration-order rotation: 5 words. Reusing/narrowing the key,
 * signed/register induction variables and alternate key hoisting did not
 * close the residual; disabling propagation worsened it.
 * Further bounded probes: block-scoped index 11 words; block-scoped key,
 * for-loop induction, signed key/kind promotions and the canonical
 * D_0076449C pointer base each retain five. No production change.
 * The former u8 filter silently discarded bits 8..15 and is not retained.
 * This body preserves the retail 16-bit key and unsigned count-1 bound;
 * it does not add a non-retail empty-list guard or cache the global base
 * across pointer stores. Production keeps its INCLUDE_ASM fallback.
 * IDA body: docs/ida_headstart/src/promoted/code1_001b.c:221-265.
 * It confirms the 16-bit filter and distinct scan lifetimes. Translating
 * its unsigned address scalars scores 32 words; adding its short-circuit
 * counting-loop form scores 39. Retain these typed pointer scans.
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
