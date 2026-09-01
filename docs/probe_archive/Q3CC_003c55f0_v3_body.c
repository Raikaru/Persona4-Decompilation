/* object_size=316 window=272 normalized_diff=240 differing_offsets=4,6,7,8,10,11,12,13,14,15,16,18,20,21,22,23 classification=object-over-window/aggregate-and-indirect-callee-declarations; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=1 */
// FUN_003C55F0
u8 *func_003c55f0(s32 arg0) {
    extern void *(*D_008873F8[])(s32 arg0, s32 arg1);
    extern void (*jtbl_008873E8[])(u8 *arg0, s32 arg1);
    extern s32 func_003df590(s32 arg0, s32 arg1);
    extern void func_003df4d0(s32 *arg0);
    s32 stack[4];
    s32 temp_16;
    u8 *temp_2;

    temp_2 = D_008873F8[0]((s32)iGpffffb6e8, 0x30502);
    if (temp_2 != NULL) {
        *(s32 *)(temp_2 + 4) = 0;
        if (arg0 == 0) {
            *(s32 *)(temp_2 + 8) = 0;
            *(s32 *)(temp_2 + 0) = 0;
            return temp_2;
        }
        temp_16 = arg0 * 0x14;
        *(s32 *)(temp_2 + 8) =
            (s32)((s32 (*)(u8 *, s32))jtbl_008873E8[0])(
                (u8 *)temp_16, 0x01030502);
        if (*(s32 *)(temp_2 + 8) != 0) {
            *(s32 *)(temp_2 + 0) = arg0;
            return temp_2;
        }
        jtbl_008873FC[0](iGpffffb6e8, temp_2);
        stack[2] = 2;
        stack[3] = func_003df590(0x80000013, temp_16);
        func_003df4d0(&stack[2]);
        return NULL;
    }
    stack[0] = 2;
    stack[1] = func_003df590(0x80000013, 0xC);
    func_003df4d0(&stack[0]);
    return NULL;
}
