/* object 344B / window 352B / normalized_diff 6. All but four words exact.
   Remaining: two mode_done branch targets at offsets 92/176 (retail routes
   through an intermediate unconditional branch; the compiler folds them
   straight to work_setup), and addu operand order at 284/312.
   Levers that worked: s32 index (removes a redundant zero-extension);
   slot expressed as ((*(work+8)!=0)^1)*4 to get retail's sltu/xori pair.
   Requires externs u8 D_005F2210, D_005F4090, D_005F51E0.
   Prior archive candidate for this function was nd146; this supersedes it.
   IDA and Ghidra agree structurally; Ghidra confirms the 0x1b mode stride. */
void func_0018a010(s32 arg0)
{
    s32 mode;
    s32 *save;
    s32 *entry;
    s32 index;
    u8 *base;
    u8 *work;

    if (*(s32 *)(func_00155280() + 0x30) == 0) {
        goto exit;
    }
    if (arg0 != -1) {
        goto direct;
    }
    mode = func_0015a160();
    if (mode != 0) {
        goto mode_nonzero;
    }
    index = 0;
    save = (s32 *)iGpffff9db0;
    if (*save < 0x28) {
        goto index_in_range;
    }
    base = NULL;
    goto mode_done;
index_in_range:
    entry = (s32 *)(D_005F51E0 + *save * 4);
    if (*entry != 0) {
        index = *(u16 *)((u8 *)*entry + *(save + 1) * 2);
    }
    base = D_005F2210 + index * 0x1A;
    goto mode_done;
mode_nonzero:
    base = D_005F4090 + mode * 0x1B;
mode_done:
    goto work_setup;
direct:
    base = D_005F2210 + arg0 * 0x1A;
work_setup:
    work = *(u8 **)(*(u8 **)(func_00155280() + 0x30) + 0x38);
    *(u8 **)((s32)((( *(s32 *)(work + 8) != 0) ^ 1) * 4) +
             (s32)work + 0x10) = base;
    *(s32 *)((s32)((( *(s32 *)(work + 8) != 0) ^ 1) * 4) +
             (s32)work + 0x18) =
        (s32)0xC3210000;
    *(s32 *)(work + 0xC) = 0;
exit:
    ;
}
