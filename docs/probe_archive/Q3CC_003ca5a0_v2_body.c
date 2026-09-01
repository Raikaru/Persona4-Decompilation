/* object_size=264 window=256 normalized_diff=155 differing_offsets=4,6,7,8,10,11,12,13,14,15,18,19,20,22,27,28 classification=object-over-window/global-addressing-and-frame; ruled_out=movz-movn,COP1-MAC,standalone-MMI,framed-tail-jump,sd-saved-register; measured_minutes=1 */
// FUN_003CA5A0
u8 *func_003ca5a0(u8 *arg0, s32 arg1) {
    extern s32 iGpffffaaa8;
    extern s32 iGpffffaaac;
    extern s32 iGpffffaab0;
    extern s32 iGpffffaab4;
    extern u8 D_00886610[];
    extern u8 D_008865E0[];

    iGpffffb718 = (u8 *)arg1;
    *(s32 *)(D_008872E0 + (s32)iGpffffb718) =
        func_003e1220(0x18, iGpffffaaa8, 4, iGpffffaaac,
                      D_00886610, 0x40507);
    if (*(s32 *)(D_008872E0 + (s32)iGpffffb718) == 0)
        return NULL;
    *(s32 *)(D_008872E0 + (s32)iGpffffb718 + 4) =
        func_003e1220(0x18, iGpffffaab0, 4, iGpffffaab4,
                      D_008865E0, 0x40507);
    if (*(s32 *)(D_008872E0 + (s32)iGpffffb718 + 4) != 0) {
        D_008872E8[0] = 1;
        *(s32 *)(D_008872E0 + (s32)iGpffffb718 + 8) = 0;
        iGpffffb71c += 1;
        return arg0;
    }
    func_003e12f0(*(u8 **)(D_008872E0 + (s32)iGpffffb718));
    *(s32 *)(D_008872E0 + (s32)iGpffffb718) = 0;
    return NULL;
}
