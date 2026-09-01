/* object_size=1344B; window=1264B; normalized_diff=595; first_diffs=0x00,0x04,0x08,0x0A,0x0C,0x0E,0x10,0x12,0x14,0x16,0x18,0x1A,0x1C,0x1E,0x20,0x24,0x28,0x2C,0x30; oversized candidate archived immediately. */
/* Reconstructed state machine from retail 0x0035f0c0; object exceeded window by 80 bytes and residual remained large, so source was restored to INCLUDE_ASM. */
s32 func_0035f0c0(u32 *arg0, s32 *arg1, u8 *arg2)
{
    extern void func_0035c830(u8 *arg0);
    extern s32 func_0035cfb0(u8 *arg0);
    extern s32 func_0035dcc0(u8 *arg0);
    extern void func_0035e6a0(u8 *arg0);
    extern s32 func_0035ce10(u8 *arg0, s32 mode);
    extern void func_0035dd40(u8 *arg0);
    extern s32 func_0035cb00(u8 *arg0, s32 mode);
    extern s32 func_0035cab0(u8 *arg0, s32 idx, s32 value);
    extern s32 func_0035cc80(u8 *arg0, s32 mode, s32 value);
    extern void func_00453670(void *buf, s32 a, s32 b, s32 c, s32 d);
    extern void func_004538e0(void *buf, s32 a, s32 b, s32 c, s32 d);
    extern s32 func_00453960(void *buf);
    extern void func_0034f1e0(void);
    extern void func_0034bb20(s32 arg0);
    extern void func_00353fb0(void);
    extern void func_00353fe0(void);
    extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
    extern u16 D_008C024E;
    extern u16 D_008C0276;
    extern f32 D_008872F8;
    extern void (*D_00887300[])(u32, u32);
    extern void (*D_00887310[])(s32, void *, s32);
    u8 work[40];
    s32 result;

    result = 1;
    *arg1 = 1;
    switch (*arg0) {
    case 0:
        *(s32 *)(arg2 + 8) = 0;
        *(s32 *)(arg2 + 0xC) = 0;
        *(u8 *)arg2 = 0xFF;
        func_0035c830(arg2);
        *arg0 = 1;
        *arg1 = 0;
        goto done;
    case 1:
        if (func_0035cfb0(arg2) & func_0034c210()) {
            *arg0 = 3;
            func_0034bb20(33);
        } else {
            *arg1 = 0;
        }
        goto done;
    case 2:
        if (func_0035dcc0(arg2) != 0) {
            func_0035e6a0(arg2);
            return 1;
        }
        goto done;
    case 3:
        if (func_0035dcc0(arg2) == 0) {
            goto done;
        }
        switch (*(s32 *)(arg2 + 0x1C)) {
        case 0:
            func_00353fe0();
            break;
        case 1:
            break;
        default:
            break;
        }
        func_0035ce10(arg2, 2);
        *arg0 = 4;
    case 4:
        if (D_008C024E & 0x40) {
            s32 mode = *(s32 *)(arg2 + 0x30);
            if (mode == 6) {
                func_0035dd40(arg2);
                func_0035ce10(arg2, 1);
                *arg0 = 2;
                func_0034bb20(34);
                switch (*(s32 *)(arg2 + 0x1C)) {
                case 0:
                    func_00353fb0();
                    break;
                case 1:
                    break;
                default:
                    break;
                }
                func_0045af60(0, 0, 0, 1);
            } else if (func_0035cb00(arg2, mode) != 0) {
                func_0045af60(0, 0, 0, 1);
            }
        } else if (D_008C024E & 0x20) {
            func_0035ce10(arg2, 1);
            *arg0 = 2;
            func_0034bb20(34);
            switch (*(s32 *)(arg2 + 0x1C)) {
            case 0:
                func_00353fb0();
                break;
            case 1:
                break;
            default:
                break;
            }
            func_0045af60(0, 0, 0, 2);
        } else if (D_008C024E & 0x10) {
            if (*(s32 *)(arg2 + 0x1C) == 0) {
                func_00354030();
                *(s32 *)(arg2 + 0x14) = 0;
                *arg0 = 5;
            }
        } else {
            func_00453670(work, 7, 7, *(s32 *)(arg2 + 0x30), 0);
            func_004538e0(work, 0x4000, 0x1000, 0, 0);
            if (func_00453960(work) != 0) {
                func_0035cab0(arg2, 0, *(s32 *)(work + 36));
                func_0045af60(0, 1, 0, 0);
            } else if (*(s32 *)(arg2 + 0x30) != 6) {
                result = 0;
                if (D_008C0276 & 0x8000) {
                    result = func_0035cc80(arg2, *(s32 *)(arg2 + 0x30), 1);
                } else if (D_008C0276 & 0x2000) {
                    result = func_0035cc80(arg2, *(s32 *)(arg2 + 0x30), 0);
                }
                if (result != 0) {
                    func_0045af60(0, 0, 0, 1);
                }
            }
        }
        goto done;
    case 5:
        {
            s32 count = *(u16 *)(arg2 + 0x10) + 1;
            f32 value;
            *(u16 *)(arg2 + 0x10) = count;
            if ((u32)count >= 3) {
                goto done;
            }
            if (count >= 0) {
                value = (f32)(u32)count;
            } else {
                value = 2.0f * (f32)(((u32)count >> 1) | (count & 1));
            }
            value = 255.0f * (1.0f - value / 3.0f);
            *(u8 *)arg2 = (u8)value;
            result = 0;
            goto done;
        }
    default:
        goto done;
    }
done:
    if (result != 0) {
        return 0;
    }
    return 2;
}
