/* object 236B/window 240B, normalized_diff 150; differing word offsets 4-220 (fndiff: 54 differing words); classification residual in hundreds, archive immediately. Retail custom ABI uses a0-a3/t0-t1 and frame 0x10; the six-argument prototype is correct. No callee or global declarations were needed. Named unsigned outer guard recovered sltu but register/lifetime allocation, guard/body layout, loop scheduling, and epilogue still diverged substantially. Ruled out direct and named unsigned >0 guards, direct pointer parameters (a1/a2 advanced in place), u8/u32 byte spellings, and no movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor was present. */
void func_003b7590(u8 *arg0, u32 *arg1, s32 *arg2, u8 *arg3, u32 *arg4, u32 arg5) {
    s32 *inner;
    u32 outer;
    u32 inner_index;
    u32 shift;
    u32 scan;
    u32 output_count;
    s32 found;
    u8 byte;
    u32 outer_active;

    outer = 0;
    *arg4 = 0;
    outer_active = arg5 > 0U;
    if (outer_active == 0) {
        goto outer_done;
    }
    do {
        if (*(u32 *)(arg0 + 0x10) > 0U) {
            inner = arg2;
            inner_index = 0;
            shift = 0;
            do {
                if (*inner != 0) {
                    byte = (u8)(*arg1 >> shift);
                    found = 1;
                    output_count = *arg4;
                    scan = 0;
                    if (output_count > 0U) {
                        do {
                            if (byte == arg3[scan]) {
                                found = 0;
                                break;
                            }
                            scan += 1;
                        } while (scan < output_count);
                    }
                    if (found != 0) {
                        arg3[output_count] = byte;
                        *arg4 = output_count + 1;
                    }
                }
                inner_index += 1;
                inner += 1;
                shift += 8;
            } while (inner_index < *(u32 *)(arg0 + 0x10));
        }
        outer += 1;
        arg2 += 4;
        arg1 += 1;
    } while (outer < arg5);
outer_done:
    ;
}
