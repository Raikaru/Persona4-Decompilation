/* Closest compliant plain-C probe for func_003e2ce0; not an exact match. */
u8 *func_003e2ce0(u8 *arg0, s64 arg1) {
    u8 *result;
    s32 resource;
    struct {
        s32 sp38;
        s32 sp3C;
        s32 sp40;
        s32 sp44;
        s32 sp48;
        s32 sp4C;
    } frame;

    result = arg0;
    if (arg1 == 0) {
        goto done;
    }
    switch (*(s32 *)arg0) {
    case 4:
        result = (((s32 (*)(s32))*(s32 *)(arg0 + 0x18))(
                      *(s32 *)(arg0 + 0x1C)) != 0) ? arg0 : NULL;
        break;
    case 3:
        if (*(s32 *)(arg0 + 0x10) < *(s32 *)(arg0 + 0xC) + (s32)arg1) {
            *(s32 *)(arg0 + 0xC) = *(s32 *)(arg0 + 0x10);
            frame.sp40 = 1;
            frame.sp44 = func_003df590(5);
            func_003df4d0(&frame.sp40);
            result = NULL;
        } else {
            *(s32 *)(arg0 + 0xC) += (s32)arg1;
        }
        break;
    case 1:
    case 2:
        resource = *(s32 *)(arg0 + 0xC);
        if (func_003de020((void *)resource, arg1, 1) != 0 &&
            func_003de100((void *)resource) == 0) {
            frame.sp48 = 1;
            frame.sp4C = func_003df590(5);
            func_003df4d0(&frame.sp48);
            result = NULL;
        }
        break;
    default:
        frame.sp38 = 1;
        frame.sp3C = func_003df590(0xE);
        func_003df4d0(&frame.sp38);
        result = NULL;
        break;
    }
done:
    return result;
}
