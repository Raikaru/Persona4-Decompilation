/* Fully relocated exact:596 executable bytes/608B retail window,36 resolved
 * relocations,zero differences;12B unreachable alignment tail.
 * Reuses sdkChkmem.c ChkMemEntry and the real same-TU static void unlink
 * helper. Per-arm result joins preserve the retail branch chain; removing
 * only W54's two through-u64 pointer casts independently closes that draft.
 * Ten complete bounded EE candidate/retail scenarios pass. Checked allocator,
 * list/unlink and returning diagnostics execute; raw allocation/free/copy and
 * privileged interrupt operations are hooks, not actual heap/OS execution.
 * Preserve retail defects: failed allocation reaches a NULL-header write;
 * copy uses min(request, old header TOTAL), which can exceed payload size.
 * The copy hook reads before writing, so partial-copy fault effects are not
 * established. Existing s32(void*,u32) registration ignores the third hint. */
#pragma push
/* Preserve retail scheduling and the branch join after nested restore. */
#pragma schedule off
s32 func_0044f140(void *arg0, u32 arg1)
{
    u32 copySize;
    s32 block;
    s32 allocationSize;
    s32 allocateLock;
    s32 newBlock;
    s32 newAllocationSize;
    s32 freeLock;
    s32 outerLock;
    s32 resizeLock;
    ChkMemEntry **oldHeaderSlot;
    s32 allocation;
    s32 result;
    ChkMemEntry *oldHeader;

    outerLock = func_0042ba20();
    if (arg0 == NULL) {
        allocateLock = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        allocationSize = (arg1 + 0x37) & ~0xF;
        block = func_0043ece8(allocationSize);
        if (block == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        allocation = func_0044eaa0(block, allocationSize, 0x10, 0);
        if (allocateLock != 0) {
            func_0042ba70();
        }
        result = allocation;
    } else {
        oldHeaderSlot = (ChkMemEntry **)((u8 *)arg0 - 4);
        copySize = (*oldHeaderSlot)->size;
        if (arg1 < copySize) {
            copySize = arg1;
        }
        resizeLock = func_0042ba20();
        if (arg1 == 0) {
            func_0046d730(D_007104E0, 0x653);
        }
        newAllocationSize = (arg1 + 0x37) & ~0xF;
        newBlock = func_0043ece8(newAllocationSize);
        if (newBlock == 0) {
            func_0046d700(D_007104E0, 0x65F, D_007104F0,
                          D_00763D1C->bytes, arg1);
        }
        allocation = func_0044eaa0(newBlock, newAllocationSize, 0x10, 0);
        if (resizeLock != 0) {
            func_0042ba70();
        }
        func_0043f810((void *)allocation, arg0, copySize);
        freeLock = func_0042ba20();
        if (arg0 == NULL) {
            func_0046d730(D_007104E0, 0x670);
        }
        oldHeader = *oldHeaderSlot;
        func_0044e9e0((u8 *)oldHeader);
        func_0043ed08(oldHeader);
        if (freeLock != 0) {
            func_0042ba70();
        }
        result = allocation;
    }
    if (outerLock != 0) {
        func_0042ba70();
    }
    return result;
}
#pragma pop
