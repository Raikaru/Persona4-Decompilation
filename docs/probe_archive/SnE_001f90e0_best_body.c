/* Best measured body for func_001f90e0 before the u16-count probe.
 * object 472B, window 480B, normalized_diff 32.
 * fndiff differing offsets (bytes): 128, 300, 304, 324, 328, 332, 336,
 * 340, 344, 348, 352, 356, 360, 368, 372, 380, 384, 388, 392, 400,
 * 408, 412, 424.
 * Ruled out: direct M2C spelling, pointer/integer candidate-array swaps,
 * declaration-order swaps, combined/separate null check, explicit work alias;
 * the later u16 count probe was worse (25 fndiff words).
 */
s32 func_001f90e0(u8 *arg0)
{
    s32 five;
    u8 *candidates[12];
    u8 *entry;
    u8 *node;
    s32 count;
    s32 value;
    s32 i;
    u8 *work;

    if (func_0045af90(3) == 1) {
        return -1;
    }
    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(work + 0xA64),
                      0x110) != 0) {
        return -1;
    }
    count = 0;
    node = *(u8 **)(iGpffffb3ac + 0x178);
    while (node != NULL) {
        if ((func_002428f0(*(u8 **)(node + 0xA64), 0) == 0) &&
            (func_00232710(*(s32 *)(node + 0xA64), 0x1001D7) == 0) &&
            (*(u16 *)(node + 0xA4) != 1) &&
            (node != *(u8 **)(arg0 + 0x30))) {
            candidates[count & 0xFFFF] = node;
            count = (count + 1) & 0xFFFF;
        }
        node = *(u8 **)(node + 0xA6C);
    }
    if ((count & 0xFFFF) == 0) {
        return -1;
    }
    if ((entry = candidates[func_00231d70(count & 0xFFFF)]) == NULL) {
        return -1;
    }
    value = 0x32;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(entry + 0xA4))) {
            value += 3;
        }
        i += 1;
    }
    value += D_00624FC0[*(u16 *)(entry + 0xA4)];
    return value + func_00231d70(3);
}
