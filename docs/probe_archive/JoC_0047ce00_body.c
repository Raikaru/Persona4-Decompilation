// FUN_0047CE00 archive (wave Jo lane JoC, killed by provider rate limit mid-work; body is the live state at cutoff, COMPILE_ERROR).
extern void func_0047e450(u8 *arg0, u16 arg1, u16 arg2, s32 arg3, u32 arg4);
s32 func_0047ce00(u8 *arg0)
{
    s32 ret;
    u8 *obj;
    s32 sp4C;


    obj = *(u8 **)(arg0 + 0x30C);
    if (obj == NULL) {
        return 1;
    }
    ret = 0;
    case 0:
        if (*(u8 **)(obj + 0x38) != NULL) {
            if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
                func_00456150(*(u8 **)(obj + 0x38));
            }
            if (func_004553c0(*(u8 **)(obj + 0x38)) == 0) {
                goto ret_label;
            }
            if (*(s32 *)(obj + 0x40) == 0) {
                *(s32 *)(obj + 0x2C) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x110);
                *(s32 *)(obj + 0x30) = *(s32 *)(*(u8 **)(obj + 0x38) + 0x118);
            } else {
                *(s32 *)(obj + 0x2C) = func_00455ea0(*(u8 **)(obj + 0x38), 0, &sp4C);
                *(s32 *)(obj + 0x30) = sp4C;
                {
                    s32 idx1 = func_00455ea0(*(u8 **)(obj + 0x38), 1, &sp4C);
                    u16 p1 = *(u16 *)(arg0 + 0xD4);
                    u16 p2 = *(u16 *)(arg0 + 0xD6);
                    u8 *dest = arg0 + 0x2D0;
                    func_0047e450(dest, p1, p2, idx1, sp4C);
                }
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
        if (*(s32 *)(obj + 0) == 0) {
            *(s32 *)(obj + 0) = func_003e2f60(3, 1, (s32 *)(obj + 0x2C));
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 1:
        if (*(u8 *)(obj + 0x3C) == 1) {
c660_again:
            if (func_0047c660(arg0) == 0) {
                goto ret_label;
            }
            *(u8 *)(obj + 0x3C) = 2;
        }
    case 2:
        if (func_0047b0c0(arg0) == 0)
            goto L_case2_fail;
        *(u8 *)(obj + 0x3C) = 3;
        goto L_D8_check;
L_case2_fail:
        *(u8 *)(obj + 0x3C) = 1;
        goto c660_again;
L_D8_check:
        if ((*(s32 *)(arg0 + 0xD8) & 0x4000) != 0) {
            *(u8 *)(obj + 0x3C) = 4;
            goto L_after_c3;
        }
    case 3:
        if (func_0047c660(arg0) == 0) {
            goto ret_label;
        }
        *(u8 *)(obj + 0x3C) = 4;
L_after_c3:
    case 4:
        if (*(s32 *)(obj + 0x34) != 0) {
            func_00463250(*(void **)(obj + 0x34));
        }
        func_003e2e40(*(s32 *)(obj + 0), (s32 *)(obj + 0x2C));
        if (*(u8 **)(obj + 0x38) != NULL) {
            func_00454bd0(*(u8 **)(obj + 0x38));
        }
        *(u8 *)(obj + 0x3C) = 5;
    case 5:
        ret = 1;
    default:
    ret_label:
        return ret;
    }
}
