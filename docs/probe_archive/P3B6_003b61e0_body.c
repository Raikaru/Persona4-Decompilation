/* object 396B/window 432B, normalized_diff 284; first differing byte offsets 2,4,5,6,7,10,12,13,14,15,16,18,19,20,21,26 (residual in hundreds; archive immediately). Classification: undersized plain-C reconstruction with large residual. Retail is an explicitly unrolled strided fill: 32 stores in the large loop and four stores in the tail. Corrected arg0 to byte-pointer base/byte stride and arg2+0x7C scalar value; no callees or globals. Tried direct plain C with declaration order dst,stride,value,done and source-level unrolled stores. Ruled out: no conditional-move, COP1 accumulator, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor in retail; no pragma or callee declaration probe performed. Restored fallback after the automatic residual-in-hundreds condition. */
// FUN_003B61E0
void func_003b61e0(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *dst;
    s32 stride;
    s32 value;
    s32 done;

    dst = *(u8 **)arg0;
    stride = *(s32 *)(arg0 + 4);
    value = *(s32 *)(arg2 + 0x7C);
    done = 0;
    if (arg1 > 0) {
        if (arg1 >= 9 && arg1 < 0x7FFFFFFF) {
            do {
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value;
                done += 8;
                dst += stride;
            } while (done < arg1 - 8);
        }
        if (done < arg1) {
            do {
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value; dst += stride;
                *(s32 *)dst = value;
                done += 1;
                dst += stride;
            } while (done < arg1);
        }
    }
}
