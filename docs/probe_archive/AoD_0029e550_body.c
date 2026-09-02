/* Best probe for func_0029e550: 3 differing words / 608-byte object.
 * Retail registers derived from asm/nonmatchings/scrScriptProcess/func_0029e550.s:
 *   $s1 = arg0; $s0 = task; loop n = $a0; slash = $v0;
 *   loop scan pointer and loaded byte = $v1; next pointer = $v0;
 *   clear call length = $a2; call arguments are materialized left-to-right.
 * Requires #pragma opt_propagation off immediately before the function.
 */
s32 func_0029e550(u8 *arg0)
{
    ScrTaskData *task;
    ScrScriptWork *child;
    s32 ret;
    s32 n;
    u8 *scan;
    s32 slash;
    s32 next;
    s32 handle;

    task = *(ScrTaskData **)(arg0 + 0x38);
    switch (task->unk_0C) {
    case 0:
        func_00442088(task->text, &D_007638D0, D_0063E5F0,
                      scrAddOff(func_00442948(D_0063E5F0), (u8 *)task) + 0x10);
        n = func_00442948(task->text) - 1;
        scan = (u8 *)task + n;
        slash = 0x2F;
        while (n > 0) {
            scan = (u8 *)task + n;
            if (slash == *(s8 *)(scan + 0x10)) {
                next = n + 1;
                func_0043f9c8((u8 *)task + next + 0x10, 0, n - 1);
                break;
            }
            n--;
        }
        task->unk_04 = func_00468170(arg0, task->text);
        task->unk_0C = 1;
        task->state = 0;
        break;
    case 1:
        ret = func_0029e040(arg0);
        switch (ret) {
        case 1:
            task->unk_0C = 3;
            break;
        case 2:
            child = (ScrScriptWork *)task->unk_214;
            if (child != NULL) {
                func_00440b68(D_0063E548,
                              child->procedure + (child->index << 5));
                func_004504f0(D_0063E560,
                              child->procedure + (child->index << 5));
                func_0029d1c0(D_00764614, child->msgA);
                handle = child->soundHandle;
                if (handle >= 0) {
                    func_002777f0(handle);
                    func_00440b68(D_0063E580);
                }
                handle = (s32)child->textBuf;
                if (handle != 0) {
                    func_0046a340((void *)handle);
                    func_00440b68(D_0063E5A0);
                }
                func_0029d270(child);
                func_0029d1c0(D_00764610, child);
                task->unk_214 = 0;
            }
            handle = task->unk_210;
            if (handle != 0) {
                func_00454bd0(handle);
                task->unk_210 = 0;
            }
            func_00452080(task->unk_04);
            task->unk_04 = 0;
            task->unk_0C = 0;
            break;
        }
        break;
    case 3:
        func_00440b68(D_0063E600);
        return -1;
    }
    return 0;
}
