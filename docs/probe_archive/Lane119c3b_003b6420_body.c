/* func_003b6420 archive: best current-TU candidate, object 152B/window 160B, normalized_diff 35.
   K3B6 archive body with the early-return guard restored. Residual: retail loop
   register colouring (t8 count, t4 step, t3 stride) and load/store scheduling
   do not reproduce from this source shape.
*/
#include "include_asm.h"
#include "type.h"

void func_003b6420(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *dst;
    u8 *src;
    u8 *dst2;
    u8 *src2;
    u8 *src1;
    u8 *src0;
    u8 *dst1;
    u8 *dst0;
    u8 *src_base;
    s32 count;
    s32 stride;
    s32 step;
    f32 value;

    dst = *(u8 **)arg0;
    step = *(s32 *)(arg0 + 4);
    src = *(u8 **)(arg2 + 0x44);
    stride = *(s32 *)(arg2 + 0x48);
    if (arg1 <= 0)
        return;
    count = 0;
    do {
        src_base = src;
        dst0 = dst + step;
        value = *(f32 *)src_base;
        dst1 = dst0 + step;
        count += 1;
        src0 = src_base + 8;
        src1 = src_base + 16;
        src2 = src_base + 24;
        dst2 = dst1 + step;
        src = src_base + stride;
        *(f32 *)dst = value;
        value = *(f32 *)(src_base + 4);
        *(f32 *)(dst + 4) = value;
        value = *(f32 *)src0;
        dst = dst2 + step;
        *(f32 *)dst0 = value;
        value = *(f32 *)(src0 + 4);
        *(f32 *)(dst0 + 4) = value;
        value = *(f32 *)src1;
        *(f32 *)dst1 = value;
        value = *(f32 *)(src1 + 4);
        *(f32 *)(dst1 + 4) = value;
        value = *(f32 *)src2;
        *(f32 *)dst2 = value;
        value = *(f32 *)(src2 + 4);
        *(f32 *)(dst2 + 4) = value;
    } while (count < arg1);
}
