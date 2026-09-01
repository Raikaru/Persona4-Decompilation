#pragma schedule on
s32 func_003e2570(s32 arg0, s32 arg1) {
    s32 *slot;
    s32 result;

    D_00764878 = arg1;
    result = func_003e1220(0x24, D_00763C54, 4, D_00763C58, D_00887220, 0x40404);
    slot = (s32 *)(D_008872E0 + D_00764878);
    *slot = result;
    while (*slot != 0) {
        D_0076487C += 1;
        return arg0;
    }
    return 0;
}
#pragma schedule off
