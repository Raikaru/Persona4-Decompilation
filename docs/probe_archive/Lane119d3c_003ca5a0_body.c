/* object_size=248 window=256 normalized_diff=59 differing_offsets=88,134,138,142,146,156,164,166,167,168,170,171,174,175,182,183 classification=instruction-scheduling-and-call-argument-order; ruled_out=opt_propagation-off,single-return,local-slot-pointer,expression-swap; measured_compiles=8 */
/* measured: b119 probe for ca5a0; residual is the first failure branch target (0x3ca688 vs 0x3ca690),
   second-call base recompute register (a0/v1 vs a2/v1), success-body store order, and cleanup path
   scheduling. */
#pragma schedule on
// FUN_003CA5A0
u8 *func_003ca5a0(u8 *arg0, s32 arg1) {
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
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
/* measured: close ca5a0 probe. */
#pragma schedule off