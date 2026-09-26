/* func_001fd790 (btlEPL.c) draft, 2026-09-26 (campaign g1 round 4): 96 words, obj 2172B vs a 2176B
   window. It uses the committed btlEPL types (BtlEplUnit, BtlEplColor/BtlEplRgba, btlEplRgbaToV4) and
   splices in place of the INCLUDE_ASM.

   Everything else is in place, including the static func_001fc300 callee knowledge (frame 0x20) and
   the 0.5f + 255.0f * v byte conversion with (s32). The residual is FP colouring: retail puts
   inv = 1 - scale in $f2 with scale in $f5, so the conversion temporaries get $f0/$f1 and the
   255/0.5/0 constants get $f4/$f3/$f1. Here inv lands in $f4 (or $f0 when the expression is
   written inline under LICM, 276 words) and everything downstream shifts.
   Tried, none moving inv to $f2: inv as a pre-loop local (97), in the outer-loop body (this file,
   96), in the inner-loop body (411/280), per case (276); a pre-loop mode copy (97); function-scope
   temporaries (180/136); declaration orders (96); a V4-to-byte inline helper (96); constant order
   `255*v + 0.5` (same); the permuter (15 min, nothing). */
typedef struct BtlEplUnitRgbaParam
{
    BtlEplFadeParam fade; // 0x00
    u8 select[4];         // 0x0C, read by func_001fc300
} BtlEplUnitRgbaParam;

// FUN_001FD790
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void func_001fd790(u8 *arg0)
{
    u32 count;
    BtlEplUnitRgbaParam *param;
    u32 total;
    u8 mode;
    f32 scale;
    u32 i;
    BtlEplUnit *node;
    BtlEplRgba rgba;

    param = *(BtlEplUnitRgbaParam **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->fade.total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fade.fadeIn) {
            if (param->fade.fadeIn > 0) {
                scale = (f32)count / (f32)param->fade.fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fade.fadeOut) {
            if (param->fade.fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fade.fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        f32 inv = 1.0f - scale;

        for (node = *(BtlEplUnit **)(D_0072449C + i * 8 + 0x178); node != NULL; node = node->next) {
            if (func_001fc300((u8 *)node, param->select) == 0) {
                continue;
            }
            node->flags |= 4;
            switch (mode) {
            case 0:
                if (count == 0) {
                    rgba.rgba = param->fade.color.rgba;
                    node->rgba = rgba.c;
                }
                break;
            case 1:
                if (count == 0) {
                    node->startRgba = node->rgba;
                }
                rgba.rgba = param->fade.color.rgba;
                {
                    V4 color;
                    V4 start;
                    f32 a0, a1, a2, a3;
                    f32 b0, b1, b2, b3;

                    btlEplRgbaToV4(&color, &rgba.c);
                    btlEplRgbaToV4(&start, &node->startRgba);
                    a0 = start.v[0] * inv;
                    a1 = start.v[1] * inv;
                    a2 = start.v[2] * inv;
                    a3 = start.v[3] * inv;
                    b0 = color.v[0] * scale;
                    b1 = color.v[1] * scale;
                    b2 = color.v[2] * scale;
                    b3 = color.v[3];
                    color.v[0] = a0 + b0;
                    color.v[1] = a1 + b1;
                    color.v[2] = a2 + b2;
                    color.v[3] = a3 + b3 * scale;
                    node->rgba.r = (s32)(0.5f + 255.0f * color.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * color.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * color.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * color.v[3]);
                }
                break;
            case 2:
                if (count == total - param->fade.fadeOut) {
                    node->startRgba = node->rgba;
                }
                {
                    V4 color;
                    V4 start;
                    f32 a0, a1, a2, a3;
                    f32 b0, b1, b2, b3;

                    btlEplRgbaToV4(&color, &D_007641F8);
                    btlEplRgbaToV4(&start, &node->startRgba);
                    a0 = color.v[0] * inv;
                    a1 = color.v[1] * inv;
                    a2 = color.v[2] * inv;
                    a3 = color.v[3] * inv;
                    b0 = start.v[0] * scale;
                    b1 = start.v[1] * scale;
                    b2 = start.v[2] * scale;
                    b3 = start.v[3];
                    color.v[0] = a0 + b0;
                    color.v[1] = a1 + b1;
                    color.v[2] = a2 + b2;
                    color.v[3] = a3 + b3 * scale;
                    node->rgba.r = (s32)(0.5f + 255.0f * color.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * color.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * color.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * color.v[3]);
                }
                break;
            }
        }
    }
}
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off
