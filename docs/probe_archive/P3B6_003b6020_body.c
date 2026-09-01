/* object 408B/window 448B, normalized_diff 239; first differing byte offsets 2,4,5,6,7,10,14,18,20,22,24,25,26,27,28,30 (residual in hundreds; archive immediately). Classification: undersized plain-C reconstruction with large residual. Retail is an explicitly unrolled strided cyclic fill: 32 stores in the large loop and four stores in the tail. Corrected arg0 to byte-pointer base/byte stride and arg2 fields +0x80/+0x84/+0x88/+0x8C. No callees or globals. Tried direct plain C with declaration order dst,stride,value0..value3,done and source-level unrolled stores. Ruled out: no conditional-move, COP1 accumulator, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor in retail; no pragma or callee declaration probe performed. Restored fallback after automatic residual-in-hundreds condition. */
// FUN_003B6020
void func_003b6020(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *dst;
    s32 stride;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    s32 done;

    dst = *(u8 **)arg0;
    stride = *(s32 *)(arg0 + 4);
    value0 = *(s32 *)(arg2 + 0x80);
    value1 = *(s32 *)(arg2 + 0x84);
    value2 = *(s32 *)(arg2 + 0x88);
    value3 = *(s32 *)(arg2 + 0x8C);
    done = 0;
    if (arg1 > 0) {
        if (arg1 >= 9 && arg1 < 0x7FFFFFFF) {
            do {
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3; dst += stride;
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3;
                done += 8;
                dst += stride;
            } while (done < arg1 - 8);
        }
        if (done < arg1) {
            do {
                *(s32 *)dst = value0; dst += stride;
                *(s32 *)dst = value1; dst += stride;
                *(s32 *)dst = value2; dst += stride;
                *(s32 *)dst = value3;
                done += 1;
                dst += stride;
            } while (done < arg1);
        }
    }
}
