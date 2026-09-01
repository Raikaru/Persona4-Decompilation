/* object 660B/window 352B, normalized_diff 522, differing offsets 0x004-0x29C (158 differing words; object oversized and residual in hundreds); classification: MWCC frameless candidate with duplicated small-stride/normal-stride loops. Retail prologue: frameless leaf begins addiu $a1,$a1,-1; beqz $a1,exit; addu $a0,$a0,$a2 in the delay slot; no $s saves. Ruled out: movz/movn, COP1 accumulator MAC, standalone MMI, framed tail-jump, and ee-gcc sd $s-save signature; no callee declarations or globals were involved, and no further probe was made after the automatic oversized/hundreds conditions. */
// FUN_00415580
void func_00415580(s32 *arg0, u32 arg1, u32 arg2, s32 arg3)
{
    u8 *current;
    u8 *left;
    u8 *right;
    u8 *source;
    u8 *target;
    u32 value;
    u32 next;
    u32 words;
    u32 bytes;
    u32 tmp;

    arg1 -= 1;
    current = (u8 *)arg0 + arg2;
    if (arg1 == 0)
        return;
    words = arg2 >> 2;
    if (arg2 < 4) {
        do {
            left = current - arg2;
            right = current + arg3;
            value = *(u32 *)right;
            next = *(u32 *)(left + arg3);
            if (value < next) {
                do {
                    source = left;
                    target = left + arg2;
                    bytes = arg2;
                    if (arg2 >= 4) {
                        if (words >= 9) {
                            do {
                                tmp = *(u32 *)target;
                                *(u32 *)target = *(u32 *)source;
                                *(u32 *)source = tmp;
                                tmp = *(u32 *)(target + 4);
                                *(u32 *)(target + 4) = *(u32 *)(source + 4);
                                *(u32 *)(source + 4) = tmp;
                                tmp = *(u32 *)(target + 8);
                                *(u32 *)(target + 8) = *(u32 *)(source + 8);
                                *(u32 *)(source + 8) = tmp;
                                tmp = *(u32 *)(target + 12);
                                *(u32 *)(target + 12) = *(u32 *)(source + 12);
                                *(u32 *)(source + 12) = tmp;
                                tmp = *(u32 *)(target + 16);
                                *(u32 *)(target + 16) = *(u32 *)(source + 16);
                                *(u32 *)(source + 16) = tmp;
                                tmp = *(u32 *)(target + 20);
                                *(u32 *)(target + 20) = *(u32 *)(source + 20);
                                *(u32 *)(source + 20) = tmp;
                                tmp = *(u32 *)(target + 24);
                                *(u32 *)(target + 24) = *(u32 *)(source + 24);
                                *(u32 *)(source + 24) = tmp;
                                tmp = *(u32 *)(target + 28);
                                *(u32 *)(target + 28) = *(u32 *)(source + 28);
                                *(u32 *)(source + 28) = tmp;
                                bytes -= 32;
                                target += 32;
                                source += 32;
                            } while (bytes >= 36);
                        }
                        if (bytes >= 4) {
                            do {
                                tmp = *(u32 *)target;
                                *(u32 *)target = *(u32 *)source;
                                *(u32 *)source = tmp;
                                bytes -= 4;
                                target += 4;
                                source += 4;
                            } while (bytes >= 4);
                        }
                    }
                    left -= arg2;
                    next = *(u32 *)(left + arg3);
                } while (value < next);
            }
            arg1 -= 1;
            current += arg2;
        } while (arg1 != 0);
    } else {
        do {
            left = current - arg2;
            right = current + arg3;
            value = *(u32 *)right;
            next = *(u32 *)(left + arg3);
            if (value < next) {
                do {
                    source = left;
                    target = left + arg2;
                    bytes = arg2;
                    if (words >= 9) {
                        do {
                            tmp = *(u32 *)target;
                            *(u32 *)target = *(u32 *)source;
                            *(u32 *)source = tmp;
                            tmp = *(u32 *)(target + 4);
                            *(u32 *)(target + 4) = *(u32 *)(source + 4);
                            *(u32 *)(source + 4) = tmp;
                            tmp = *(u32 *)(target + 8);
                            *(u32 *)(target + 8) = *(u32 *)(source + 8);
                            *(u32 *)(source + 8) = tmp;
                            tmp = *(u32 *)(target + 12);
                            *(u32 *)(target + 12) = *(u32 *)(source + 12);
                            *(u32 *)(source + 12) = tmp;
                            tmp = *(u32 *)(target + 16);
                            *(u32 *)(target + 16) = *(u32 *)(source + 16);
                            *(u32 *)(source + 16) = tmp;
                            tmp = *(u32 *)(target + 20);
                            *(u32 *)(target + 20) = *(u32 *)(source + 20);
                            *(u32 *)(source + 20) = tmp;
                            tmp = *(u32 *)(target + 24);
                            *(u32 *)(target + 24) = *(u32 *)(source + 24);
                            *(u32 *)(source + 24) = tmp;
                            tmp = *(u32 *)(target + 28);
                            *(u32 *)(target + 28) = *(u32 *)(source + 28);
                            *(u32 *)(source + 28) = tmp;
                            bytes -= 32;
                            target += 32;
                            source += 32;
                        } while (bytes >= 36);
                    }
                    if (bytes >= 4) {
                        do {
                            tmp = *(u32 *)target;
                            *(u32 *)target = *(u32 *)source;
                            *(u32 *)source = tmp;
                            bytes -= 4;
                            target += 4;
                            source += 4;
                        } while (bytes >= 4);
                    }
                    left -= arg2;
                    next = *(u32 *)(left + arg3);
                } while (value < next);
            }
            arg1 -= 1;
            current += arg2;
        } while (arg1 != 0);
    }
}
