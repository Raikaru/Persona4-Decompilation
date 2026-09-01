/* Best candidate for func_001b70c0, retained before rollback to ASM.
 * Object/window: 828B/816B.
 * Normalized residual: 96 words; differing byte offsets: 0, 28, 40, 56, 84, 92, 96, 100, 104, 108, 372, 376, 380, 384, 388, 392, 400, 404, 420, 424, 432, 480, 484, 488, 492, 496, 500, 504, 524, 528, 532, 536, 540, 544, 548, 552, 556, 564, 568, 572, 580, 584, 588, 592, 596, 600, 604, 608, 616, 620, 628, 636, 640, 644, 648, 652, 656, 660, 664, 668, 672, 676, 680, 688, 696, 700, 704, 708, 712, 716, 720, 724, 728, 732, 736, 740, 748, 752, 756, 760, 764, 768, 772, 776, 780, 784, 788, 792, 796, 800, 804, 808, 812, 816, 820, 824.
 * COP1 accumulator chain: reproduced for the first cross-product wave; the
 * second wave remains mismatched in the residual.
 * Ruled out: aggregate Vec3 input versus field loads, raw pointer Vec3 copy,
 * scalar input staging, direct cross-product expressions, reordered accumulator
 * temporaries, and unscoped/alternate pragma placements.
 * No new data references beyond existing retail globals and helper symbols;
 * all D_XXXXXXXX and func_XXXXXXXX references are real, placeable references.
 */
#pragma push
// measured: opt_propagation off probe for func_001b70c0 accumulator/copy ordering.
#pragma opt_propagation off
// FUN_001B70C0
void func_001b70c0(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 v20;
        u32 pad2C;
        Vec3 v30;
        u32 pad3C;
        Vec3 v40;
        u32 pad4C;
        Vec3 v50;
        u32 pad5C;
        Vec3 v60;
        u32 pad6C;
        Vec3 v70;
        u32 pad7C;
        Vec3 v80;
        u32 pad8C;
        Vec3 v90;
        u32 pad9C;
        Vec3 vA0;
    } Frame;
    Frame frame;
    f32 adjusted;
    f32 output_y;
    f32 cross_x;
    f32 cross_y;
    f32 cross_z;
    f32 axis_x;
    f32 axis_y;
    f32 axis_z;
    u64 copy_xy;
    f32 copy_z;
    f32 cross2_y;
    f32 cross2_z;
    f32 cross2_normz;
    f32 cross2_dy;
    u8 mode;

    if (((*(s32 *)(iGpffffb3ac + 0xC) & 2) != 0) &&
        (*(u16 *)(arg0 + 0x9FE) != 0)) {
        mode = *(u8 *)(arg0 + 0xA2);
        switch (mode) {
        case 0:
        case 1: {
            f32 *dstf;
            u32 *src;
            u32 *dst;
            s32 count;
            frame.v70.x = *(f32 *)(arg0 + 0x54);
            frame.v70.y = *(f32 *)(arg0 + 0x58);
            frame.v70.z = *(f32 *)(arg0 + 0x5C);
            func_00195850(arg0, (f32 *)&frame.v60);
            output_y = frame.v60.y;
            adjusted = output_y + 5.0f;
            if (!(adjusted < frame.v70.y)) {
                frame.v70.y = adjusted;
            }
            frame.v50 = frame.v70;
            frame.vA0.x = frame.v60.x - frame.v70.x;
            frame.vA0.y = output_y - frame.v70.y;
            frame.vA0.z = frame.v60.z - frame.v70.z;
            func_003e40b0(&frame.vA0.x, &frame.vA0.x);
            frame.v40 = frame.vA0;
            cross_y = frame.vA0.y;
            axis_z = *(f32 *)D_0060A0E8;
            cross_z = frame.vA0.z;
            axis_y = *(f32 *)D_0060A0E4;
            frame.v90.x = axis_y * cross_z - axis_z * cross_y;
            axis_x = *(f32 *)D_0060A0E0;
            cross_x = frame.vA0.x;
            frame.v90.y = axis_z * cross_x - axis_x * cross_z;
            frame.v90.z = axis_x * cross_y - axis_y * cross_x;
            func_003e40b0(&frame.v90.x, &frame.v90.x);
            *(u64 *)&frame.v20 =
                ((copy_xy = *(u64 *)&frame.v90),
                 (copy_z = frame.v90.z),
                 copy_xy);
            frame.v20.z = copy_z;
            cross2_y = frame.v90.y;
            cross2_z = frame.vA0.z;
            cross2_normz = frame.v90.z;
            cross2_dy = frame.vA0.y;
            frame.v80.x = cross2_dy * cross2_normz -
                          cross2_z * cross2_y;
            frame.v80.y = frame.vA0.z * frame.v90.x -
                          frame.vA0.x * frame.v90.z;
            frame.v80.z = frame.vA0.x * frame.v90.y -
                          frame.vA0.y * frame.v90.x;
            frame.v30 = frame.v80;
            dstf = (f32 *)func_0014a8a0(*(u16 *)(arg0 + 0x9FE));
            dstf[0] = *(f32 *)(arg0 + 0x70);
            dstf[1] = *(f32 *)(arg0 + 0x74);
            dstf[2] = *(f32 *)(arg0 + 0x78);
            dstf[3] = *(f32 *)(arg0 + 0x7C);
            dst = (u32 *)func_0014a990(*(u16 *)(arg0 + 0x9FE));
            src = (u32 *)&frame.v20;
            for (count = 8; count > 0; count--) {
                dst[0] = src[0];
                dst[1] = src[1];
                src += 2;
                dst += 2;
            }
            break;
        }
        case 2: {
            f32 *dstf;
            u32 *src;
            u32 *dst;
            s32 count;

            func_003e0870(&frame.v20, D_0060A0D0, 0, -90.0f);
            dstf = (f32 *)func_0014a5d0(*(u16 *)(arg0 + 0x9FE));
            dstf[0] = *(f32 *)D_005F7290;
            dstf[1] = *(f32 *)D_005F7294;
            dstf[2] = *(f32 *)D_005F7298;
            dstf[3] = *(f32 *)D_005F729C;
            dstf = (f32 *)func_0014a8a0(*(u16 *)(arg0 + 0x9FE));
            dstf[0] = *(f32 *)D_005F72A0;
            dstf[1] = *(f32 *)D_005F72A4;
            dstf[2] = *(f32 *)D_005F72A8;
            dstf[3] = *(f32 *)D_005F72AC;
            dst = (u32 *)func_0014a990(*(u16 *)(arg0 + 0x9FE));
            src = (u32 *)&frame.v20;
            for (count = 8; count > 0; count--) {
                dst[0] = src[0];
                dst[1] = src[1];
                src += 2;
                dst += 2;
            }
            break;
        }
        default:
            break;
        }
    }
}
#pragma pop
