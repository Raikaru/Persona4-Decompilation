/* object 128B, window 128B, normalized_diff 9; last attempted shape before reverting
   003e2570 to INCLUDE_ASM. While-nonzero source with slot computed after the call;
   residual is the loop-rotated branch/backedge around store/reload (bnel at bottom
   vs retail bnez at top, plus the initial b to the condition). Schedule on places
   the call arguments. */
#pragma push
#pragma schedule on
// FUN_003E2570
s32 func_003e2570(s32 arg0, s32 arg1) {
    s32 *slot;

    D_00764878 = arg1;
    slot = (s32 *)(D_008872E0 + D_00764878);
    *slot = func_003e1220(0x24, D_00763C54, 4, D_00763C58, D_00887220, 0x40404);
    while (*slot != 0) {
        D_0076487C += 1;
        return arg0;
    }
    return 0;
}
#pragma pop
