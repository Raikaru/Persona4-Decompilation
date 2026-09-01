/* object_size=256 window=272 normalized_diff=77 differing_offsets=46,48,50,66,78,90,102,144,150,154,158,166,167,170,174,175 classification=register-coloring-and-indirect-callee-order; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=4 */
/* measured: schedule-on probe for c65b0's callback and prologue slots. */
#pragma schedule on
/* measured: no_branch_likely keeps c65b0's search branches ordinary. */
#pragma no_branch_likely on
// FUN_003C65B0
void func_003c65b0(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, u32 arg4, u8 *arg5) {
    extern void *(*D_008873F8[])(s32 arg0, s32 arg1);
    u8 *node;
    u8 **slot;
    u32 key2;
    u32 key3;
    u32 type;

    node = *arg1;
    if (node != NULL) {
        key2 = (u32)arg2 & 0xFFFF;
        key3 = (u32)arg3 & 0xFFFF;
        do {
            if ((key2 == *(u16 *)(node + 2)) &&
                (key3 == *(u16 *)(node + 0)) &&
                (*(u8 **)(node + 8) == NULL)) {
                slot = (u8 **)(arg5 + (arg4 * 4));
                *(u8 *)(*(u8 **)(node + 4) + 0x20) += 1;
                *(u8 *)(*slot + 0x20) += 1;
                *(u8 **)(node + 8) = *slot;
                return;
            }
            node = *(u8 **)(node + 0xC);
        } while (node != NULL);
    }
    type = 0x30502;
    node = D_008873F8[0]((s32)arg0, type);
    *(u16 *)(node + 0) = (u16)arg2;
    slot = (u8 **)(arg5 + (arg4 * 4));
    *(u16 *)(node + 2) = (u16)arg3;
    *(u8 **)(node + 4) = *slot;
    *(s32 *)(node + 8) = 0;
    *(u8 **)(node + 0xC) = *arg1;
    *arg1 = node;
}
/* measured: close c65b0 schedule-on probe. */
#pragma no_branch_likely off
#pragma schedule off
