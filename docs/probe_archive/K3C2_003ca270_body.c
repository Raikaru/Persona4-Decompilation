/* object 160 bytes, retail window 176 bytes, normalized_diff 92.
   Direct typed loop with declaration order count/index/offset, schedule on, and
   no_branch_likely on reproduced the saved-register assignment and callback delay
   slot, but MWCC still emits blez plus at/beqz while retail uses slt/bnez in the
   initial and loop guards. Ruled out direct >0 and <=0 forms, named boolean and
   explicit trampoline variants (see the c21e0 sibling archive for the measured
   branch-layout family); no file-scope declarations changed.
*/
u8 *func_003ca270(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    s32 count;
    s32 index;
    s32 offset;

    count = *(s32 *)(arg0 + 0x14);
    index = 0;
    if (count > 0) {
        offset = 0;
loop:
        if (arg1(*(s32 *)(*(u8 **)(arg0 + 0x10) + offset), arg2) == 0)
            return arg0;
        index += 1;
        if (index < count) {
            offset += 4;
            goto loop;
        }
    }
    return arg0;
}
