/* Closest plain-C probe archived before restoring INCLUDE_ASM: direct translation of the generated state/update candidate; compiler diagnostics prevented a clean object. */
/* measured: restores opt_propagation after func_002b5120. */
#pragma opt_propagation on
// FUN_002B52A0
s32 func_002b52a0(u8 *arg0)
{
    u8 *work;
    u8 *item;
    u8 *node;
    s8 state;
    u16 active;
    s16 mode;
    s16 frame;
    s32 count;
    s32 half;
    s32 half2;
    s32 value;
    s32 value2;
    s32 color_i;
    s8 byte;
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
    f32 t;
    f32 factor;
    union {
        f32 f;
        s32 i;
    } converted;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(work + 0x154) == 1) {
        return 0;
    }
    state = *(s8 *)work;
    switch (state) {
    case 2:
        active = *(u16 *)(work + 0x182);
        if (active == 0) {
            mode = *(s16 *)(work + 0x156);
            switch (mode) {
            case 0:
                x0 = *(f32 *)(work + 0x13C);
                count = *(s32 *)(work + 0x170);
                half = count >> 1;
                if (count < 0) {
                    half = (count + 1) >> 1;
                }
                *(f32 *)(work + 0x134) = func_002b2aa0(
                    0, 1e-45f, 4e-45f, x0 + (f32)half, x0,
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                x1 = *(f32 *)(work + 0x140);
                count = *(s32 *)(work + 0x174);
                half2 = count >> 1;
                if (count < 0) {
                    half2 = (count + 1) >> 1;
                }
                *(f32 *)(work + 0x138) = func_002b2aa0(
                    0, x1 + (f32)half2, x1,
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x128) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x12C) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                break;
            case 1:
                x0 = *(f32 *)(work + 0x13C);
                count = *(s32 *)(work + 0x160);
                half = count >> 1;
                if (count < 0) {
                    half = (count + 1) >> 1;
                }
                *(f32 *)(work + 0x134) = func_002b2aa0(
                    0, 1e-45f, 4e-45f, x0, x0 + (f32)half,
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                x1 = *(f32 *)(work + 0x140);
                count = *(s32 *)(work + 0x164);
                half2 = count >> 1;
                if (count < 0) {
                    half2 = (count + 1) >> 1;
                }
                *(f32 *)(work + 0x138) = func_002b2aa0(
                    0, x1, x1 + (f32)half2,
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x128) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x12C) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                break;
            case 2:
                *(f32 *)(work + 0x134) = func_002b2aa0(
                    0, 1e-45f, 4e-45f, *(f32 *)(work + 0x13C),
                    *(f32 *)(work + 0x144), (f32)*(s16 *)(work + 0x14C),
                    (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x138) = func_002b2aa0(
                    0, *(f32 *)(work + 0x140), *(f32 *)(work + 0x148),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                break;
            case 3:
            case 4:
                *(f32 *)(work + 0x134) = func_002b2aa0(
                    0, 1e-45f, 4e-45f, *(f32 *)(work + 0x13C),
                    *(f32 *)(work + 0x144), (f32)*(s16 *)(work + 0x14C),
                    (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x138) = func_002b2aa0(
                    0, *(f32 *)(work + 0x140), *(f32 *)(work + 0x148),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x128) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x160), (f32)*(s32 *)(work + 0x170),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                *(f32 *)(work + 0x12C) = func_002b2aa0(
                    0, (f32)*(s32 *)(work + 0x164), (f32)*(s32 *)(work + 0x174),
                    (f32)*(s16 *)(work + 0x14C), (f32)*(s32 *)(work + 0x150));
                break;
            }
            if (*(u8 *)(work + 0x180) == 1) {
                byte0 = *(u8 *)(work + 0x178);
                if ((s8)byte0 >= 0) {
                    x0 = (f32)byte0;
                } else {
                    x0 = 2.0f * (f32)((byte0 >> 1) | (byte0 & 1));
                }
                byte1 = *(u8 *)(work + 0x179);
                if ((s8)byte1 >= 0) {
                    y0 = (f32)byte1;
                } else {
                    y0 = 2.0f * (f32)((byte1 >> 1) | (byte1 & 1));
                }
                converted.f = func_002b2aa0(
                    2, x0, y0, (f32)*(s16 *)(work + 0x17A),
                    (f32)*(s32 *)(work + 0x17C));
                if (!(converted.f >= 2.1474836e9f)) {
                    color_i = converted.i & 0xFF;
                } else {
                    color_i = (converted.i - (s32)0x7F000000) | 0x80000000;
                    color_i &= 0xFF;
                }
                *(u8 *)(work + 0x113) = (u8)color_i;
                value = 1;
                while (value < 4) {
                    *(u8 *)(work + value * 4 + 0x113) =
                        *(u8 *)(work + 0x113);
                    value += 1;
                }
                value = func_002b2cb0(*(s16 *)(work + 0x17A), 1,
                                      *(s32 *)(work + 0x17C), 0, 1);
                *(s16 *)(work + 0x17A) = (s16)value;
                if ((s16)value >= *(s32 *)(work + 0x17C)) {
                    *(u8 *)(work + 0x113) = *(u8 *)(work + 0x179);
                    value = 1;
                    while (value < 4) {
                        *(u8 *)(work + value * 4 + 0x113) =
                            *(u8 *)(work + 0x113);
                        value += 1;
                    }
                    *(u8 *)(work + 0x180) = 0;
                }
            }
            frame = *(s16 *)(work + 0x14C);
            if (frame < *(s32 *)(work + 0x150)) {
                *(s16 *)(work + 0x14C) = frame + 1;
            } else {
                *(s16 *)(work + 0x156) = -1;
                if ((*(s32 *)(work + 0x128) == 0) ||
                    (*(s32 *)(work + 0x12C) == 0)) {
                    *(s8 *)(work + 0x154) = 1;
                }
                if ((*(u8 *)(work + 0x180) == 0) &&
                    (*(s16 *)(work + 0x156) == -1)) {
                    *(s8 *)work = 1;
                }
            }
        }
    case 1:
    case 0:
        factor = 1.0f / *(f32 *)(func_00457120() + 0x80);
        value = 0;
        while (value < 4) {
            item = work + (value << 6);
            *(f32 *)(item + 0x18) =
                D_008872F8 - *(f32 *)(work + 0x130);
            *(f32 *)(item + 0x28) = factor;
            node = work + value * 4;
            byte = *(s8 *)(node + 0x110);
            *(f32 *)(item + 0x30) =
                byte >= 0 ? (f32)(u8)byte :
                2.0f * (f32)(((u8)byte >> 1) | ((u8)byte & 1));
            byte = *(s8 *)(node + 0x111);
            *(f32 *)(item + 0x34) =
                byte >= 0 ? (f32)(u8)byte :
                2.0f * (f32)(((u8)byte >> 1) | ((u8)byte & 1));
            byte = *(s8 *)(node + 0x112);
            *(f32 *)(item + 0x38) =
                byte >= 0 ? (f32)(u8)byte :
                2.0f * (f32)(((u8)byte >> 1) | ((u8)byte & 1));
            byte = *(s8 *)(node + 0x113);
            *(f32 *)(item + 0x3C) =
                byte >= 0 ? (f32)(u8)byte :
                2.0f * (f32)(((u8)byte >> 1) | ((u8)byte & 1));
            value += 1;
        }
        *(f32 *)(work + 0x10) = *(f32 *)(work + 0x134);
        *(f32 *)(work + 0x14) = *(f32 *)(work + 0x138);
        *(f32 *)(work + 0x50) =
            *(f32 *)(work + 0x134) + *(f32 *)(work + 0x128);
        *(f32 *)(work + 0x54) = *(f32 *)(work + 0x138);
        *(f32 *)(work + 0x90) = *(f32 *)(work + 0x134);
        *(f32 *)(work + 0x94) =
            *(f32 *)(work + 0x138) + *(f32 *)(work + 0x12C);
        *(f32 *)(work + 0xD0) =
            *(f32 *)(work + 0x134) + *(f32 *)(work + 0x128);
        *(f32 *)(work + 0xD4) =
            *(f32 *)(work + 0x138) + *(f32 *)(work + 0x12C);
        node = func_00461390(D_00793E80 +
                             (*(s32 *)(work + 0x188) * 0x30),
                             4, work + 0x10, 4);
        *(void (**)(u8 *))(node + 8) = (void (*)(u8 *))func_002b5120;
        *(u8 **)(node + 0x10) = work;
        break;
    default:
        return 0;
    }
    *(u16 *)(work + 0x182) = func_002b2d00(
        *(u16 *)(work + 0x182), 1, 0, 0, 1);
    return 0;
    case 3:
        return -1;
    }
}
