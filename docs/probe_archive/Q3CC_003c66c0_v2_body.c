/* object_size=220 window=240 normalized_diff=105 differing_offsets=40,50,54,58,66,78,82,88,89,90,91,94,95,96,97,98 classification=register-coloring-and-call-layout; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=6 */
/* measured: schedule and ordinary branches probe c66c0 prologue and loops. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C66C0
u32 func_003c66c0(u32 arg0, u8 ***arg1, u8 *arg2, u32 *arg3) {
    u8 *next;
    void (**callback_first)(u8 *arg0, u8 *arg1);
    u32 count;
    void (**callback_second)(u8 *arg0, u8 *arg1);
    u32 *items;
    if (arg2 != NULL) {
        callback_first = jtbl_008873FC;
        do {
            next = *(u8 **)(arg2 + 0xC);
            callback_first[0](*(u8 **)(arg1 + 1), arg2);
            arg2 = next;
        } while (arg2 != NULL);
    }
    func_003e12f0(*(u8 **)(arg1 + 1));
    *(u8 **)(arg1 + 1) = NULL;
    count = 0;
    if ((u32)0 < arg0) {
        callback_second = jtbl_008873FC;
        items = arg3;
        do {
            callback_second[0](*(u8 **)(arg1 + 0), *(u8 **)items);
            count += 1;
            *items = 0;
            items += 1;
        } while (count < arg0);
    }
    func_003e12f0(*(u8 **)(arg1 + 0));
    *(u8 **)(arg1 + 0) = NULL;
    jtbl_008873EC[0](arg3);
    return 0;
}
/* measured: close c66c0 scheduling probe. */
#pragma no_branch_likely off
#pragma schedule off
