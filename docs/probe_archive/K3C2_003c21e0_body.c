/* object 156 bytes, retail window 176 bytes, normalized_diff 90.
   Best source shape used the retail saved-register declaration order, schedule on,
   no_branch_likely on, an explicit body trampoline, >= 1 guard, and an unconditional
   offset increment before the loop guard. The remaining residual is branch/code-layout:
   retail starts with slt v0,zero,s0; bnez and uses slt v0,s2,s0; bnez with a
   separate return trampoline; MWCC emits bgtz/blez and at/beqz for these forms.
   Ruled out direct >0 and <=0 guards, named boolean locals, reordered declarations,
   explicit goto trampolines, >=1, and schedule/no_branch_likely combinations.
*/
u8 *func_003c21e0(u8 *arg0, s32 (*arg1)(s32, s32), s32 arg2) {
    s32 count;
    s32 index;
    s32 offset;

    count = *(s32 *)(arg0 + 0x24);
    index = 0;
    if (count >= 1)
        goto body;
    goto done;
done:
    return arg0;
body:
    offset = 0;
loop:
    if (arg1(*(s32 *)(*(u8 **)(arg0 + 0x20) + offset), arg2) == 0)
        goto done;
    index += 1;
    offset += 4;
    if (index < count)
        goto loop;
    goto done;
}
