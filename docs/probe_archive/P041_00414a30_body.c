/* object 324B/window 288B, normalized_diff 252, differing offsets 0x000-0x140 (78 differing words; object oversized); classification: MWCC candidate with wrong declaration/frame/evaluation shape. Retail prologue: addiu $sp,-320; sd $ra,48($sp); sq $s2,32($sp), sq $s1,16($sp), sq $s0,0($sp). Block-scope declarations corrected for jtbl_008873E8/jtbl_008873EC/D_008873A4/D_0070C380/func_00414930. Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; automatic oversized condition stopped further probes. */
// FUN_00414A30
u8 *func_00414a30(u8 **arg0, u32 arg1)
{
    extern u8 *(*jtbl_008873E8[])(u32, u32);
    extern void (*jtbl_008873EC[])(void *);
    extern void (*D_008873A4[])(void *, void *, s32, s32);
    extern u8 D_0070C380[];
    extern s32 func_00414930(u32 *, u32 *, u8 **);
    u8 sp40[0x100];
    s32 total;
    s32 result_total;
    u32 capacity;
    u32 *work;
    u32 *node;
    u32 node_size;
    u8 **list;
    u8 *result;

    capacity = arg1 + 0x60;
    node_size = *(u32 *)arg0;
    if (capacity < node_size)
        capacity = node_size;
    list = arg0;
    work = (u32 *)jtbl_008873E8[0](capacity + 0x8B, 0x01040409);
    result = NULL;
    if (work != NULL) {
        work[0] = ((u32)(u8 *)work + 0xC + 0x7F) & ~0x7F;
        work[1] = capacity;
        work[2] = 0;
    }
    if (work != NULL) {
        if (func_00414930(work, *(u32 **)((u8 *)list + 4), list) == 0) {
            if (work != NULL)
                jtbl_008873EC[0]((void *)work);
            goto block_8;
        }
        *(u32 **)((u8 *)work + 8) = *(u32 **)((u8 *)list + 4);
        *(u32 **)((u8 *)list + 4) = work;
        node = *(u32 **)((u8 *)list + 4);
        result_total = 0;
        if (node != NULL) {
            do {
                total = *(s32 *)((u8 *)node + 4);
                node = *(u32 **)((u8 *)node + 8);
                result_total += total;
            } while (node != NULL);
        }
        D_008873A4[0](&sp40, &D_0070C380[0], result_total - capacity, result_total);
        result = (u8 *)(work[0] + 0x20);
    }
block_8:
    return result;
}
