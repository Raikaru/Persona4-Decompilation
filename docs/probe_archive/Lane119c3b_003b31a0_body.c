/* func_003b31a0 archive: best current-TU candidate, object 172B/window 160B, normalized_diff 37.
   P3B archive source (build/P3B_003b31a0_nd34.c) with block-scope callee declaration
   hoisted to a top-level extern. Retail-derived scheduler floor: the slt $at,$zero,$a1
   entry guard and pre-guard pointer materialisation do not reproduce from C.
*/
#include "include_asm.h"
#include "type.h"

extern void func_003a4d50(u8 *arg0, u8 *arg1, s32 arg2);

void func_003b31a0(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *src;
    u8 *dst;
    u8 *src_i;
    u8 *dst0;
    u8 *dst1;
    u8 *dst2;
    s32 stride;
    s32 src_stride;
    s32 count;
    s32 value;

    stride = *(s32 *)(arg0 + 4);
    src_stride = *(s32 *)(arg2 + 0x30);
    src = *(u8 **)(arg2 + 0x2C);
    dst = *(u8 **)arg0;
    if (src_stride != stride * 4) {
        count = 0;
        if (arg1 > 0) {
            do {
                src_i = src;
                dst0 = dst + stride;
                value = *(s32 *)src_i;
                dst1 = dst0 + stride;
                count += 1;
                dst2 = dst1 + stride;
                src += src_stride;
                *(s32 *)dst = value;
                value = *(s32 *)(src_i + 4);
                dst = dst2 + stride;
                *(s32 *)dst0 = value;
                value = *(s32 *)(src_i + 8);
                *(s32 *)dst1 = value;
                value = *(s32 *)(src_i + 0xC);
                *(s32 *)dst2 = value;
            } while (count < arg1);
        }
    } else {
        func_003a4d50(dst, src, arg1 * stride * 4);
    }
}
