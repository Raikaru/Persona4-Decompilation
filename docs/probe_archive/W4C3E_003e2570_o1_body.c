#pragma optimization_level 1
s32 func_003e2570(s32 arg0, s32 arg1) {
    D_00764878 = arg1;
    *(s32 *)(D_008872E0 + D_00764878) = func_003e1220(0x24, D_00763C54, 4, D_00763C58, D_00887220, 0x40404);
    if (*(s32 *)(D_008872E0 + D_00764878) == 0) {
        return 0;
    }
    D_0076487C += 1;
    return arg0;
}
#pragma optimization_level 2
