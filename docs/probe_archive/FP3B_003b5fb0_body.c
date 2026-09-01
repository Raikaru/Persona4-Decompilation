/* Best plain-C attempt: object 112B / window 112B / normalized_diff 26 (build/FP3B_5fb0_guard_local.json). Restored to INCLUDE_ASM. */
void func_003b5fb0(u8 *arg0, s32 arg1, u8 *arg2) {
 u8 *dst;
 s32 dst_stride;
 u8 *src;
 s32 src_stride;

 dst = *(u8 **)arg0;
 if (0 < arg1) {
  dst_stride = *(s32 *)(arg0 + 4);
  src = *(u8 **)(arg2 + 0x2C);
  src_stride = *(s32 *)(arg2 + 0x30);
  do {
   *(s32 *)(dst + 0) = *(s32 *)(src + 0);
   *(s32 *)(dst + dst_stride) = *(s32 *)(src + 4);
   *(s32 *)(dst + dst_stride * 2) = *(s32 *)(src + 8);
   *(s32 *)(dst + dst_stride * 3) = *(s32 *)(src + 0xC);
   arg1 -= 1;
   src += src_stride;
   dst += dst_stride * 4;
  } while (0 < arg1);
 }
}
