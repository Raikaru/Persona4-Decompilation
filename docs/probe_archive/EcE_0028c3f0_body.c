/* Re-measured by EcE: object 400 bytes, retail window 400 bytes, normalized_diff 16.
 * Differing word offsets (relocations masked): 280,284,288,292,296,300,
 * 304,308,312,316,320,324,328,332,336,340.
 * Counts entries in lists 3/1/0xC into a stack array, then scans the table at
 * arg0+0x7A4 for each node's u16 id and calls func_0028c580(arg0,node,match).
 * The count guard and all list traversal, loads, register allocation, and
 * shared call tail match retail. The residual is the slot-search branch shape:
 * retail emits bne $v0,$a3,advance followed by an unconditional b to the
 * shared call tail, whereas MWCC b210 merges the same logic into one beq to
 * the found path (or moves the null path ahead of the body). Goto, break,
 * continue, explicit-label, and both if/else polarity variants all collapse
 * to the same single conditional branch in this shared-tail void function.
 * This is the same recognized MWCC slot-search floor recorded for the
 * cmmCommunity scan family; no source-level branch spelling closed it.
 */
#pragma push
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
void func_0028c3f0(u8 *arg0)
{
    u32 nodes[51];
    s32 count;
    s32 i;
    s32 k;
    s32 table_count;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node;
    u8 *match;
    u32 *slot;
    u32 id;

    count = 0;
    i = 0;
    count += func_00145300(3);
    count += func_00145300(1);
    count += func_00145300(0xC);
    if (count < 0x33) {
        node1 = func_001452b0(3);
        while (node1 != NULL) {
            nodes[i] = (u32)node1;
            i++;
            node1 = *(u8 **)(node1 + 0x138);
        }
        node2 = func_001452b0(1);
        while (node2 != NULL) {
            nodes[i] = (u32)node2;
            i++;
            node2 = *(u8 **)(node2 + 0x138);
        }
        node3 = func_001452b0(0xC);
        while (node3 != NULL) {
            nodes[i] = (u32)node3;
            i++;
            node3 = *(u8 **)(node3 + 0x138);
        }
        i = 0;
        while (i < count) {
            slot = &nodes[i];
            node = (u8 *)*slot;
            id = *(u16 *)node;
            table_count = *(s32 *)(arg0 + 0x7A0);
            k = 0;
inner_test:
            if (k >= table_count) {
                match = NULL;
            } else {
                match = *(u8 **)(*(u8 **)(arg0 + 0x7A4) + k * 4);
                if (*(u16 *)match == id) {
                } else {
                    k++;
                    goto inner_test;
                }
            }
found:
            func_0028c580(arg0, node, match);
            i++;
        }
    }
}
#pragma pop
