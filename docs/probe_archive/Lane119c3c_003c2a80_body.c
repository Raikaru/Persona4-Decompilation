/* b119 candidate for func_003c2a80 (0x003c2a80), 228B vs 240B,
   differing words (reloc-masked): 53, residual is whole-function
   scheduling/control-flow shape (prologue placement, branch structure,
   delay-slot filling) under b119 schedule on. */
/* measured: schedule on fills the jr $ra delay slot for func_003c2a80. */
#pragma schedule on
// FUN_003C2A80
extern void func_003e1ea0(u8 *arg0);
s32 func_003c2a80(u8 *arg0) {
    u8 *temp;

    if ((*(s16 *)(arg0 + 0xE) - 1) > 0) {
        *(s16 *)(arg0 + 0xE) = *(s16 *)(arg0 + 0xE) - 1;
    } else {
        temp = *(u8 **)(arg0 + 0x58);
        if (temp != NULL) {
            func_003e1ea0(temp);
        }
        *(s16 *)(arg0 + 0xE) = *(s16 *)(arg0 + 0xE) - 1;
        *(s16 *)(arg0 + 0xE) = *(s16 *)(arg0 + 0xE) + 1;
        *(u16 *)(arg0 + 0xC) = *(u16 *)(arg0 + 0xC) | 0xFFF;
        temp = *(u8 **)(arg0 + 0x54);
        if (temp != NULL) {
            func_003c5760(temp);
            *(u8 **)(arg0 + 0x54) = NULL;
        }
        func_003e3c20(D_0070AFB0, arg0);
        temp = *(u8 **)(arg0 + 0x5C);
        if (temp != NULL) {
            jtbl_008873EC[0](temp);
            *(u8 **)(arg0 + 0x5C) = NULL;
        }
        func_003c49a0(arg0 + 0x20);
        *(s16 *)(arg0 + 0xE) = *(s16 *)(arg0 + 0xE) - 1;
        jtbl_008873EC[0](arg0);
    }
    return 1;
}
/* measured: closes the schedule bracket for func_003c2a80. */
#pragma schedule off
