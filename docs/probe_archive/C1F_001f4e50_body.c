/* Floor: 1888B window, obj 1872B, 61 differing words. Frame (-336,
   sd ra,0x40, sq s0-s3), callee-saved assignment, all 21 calls, both
   arm chains, the guard chain and the switch table match retail.
   WINS: callee-saved regs are assigned in REVERSE declaration order
   (var_18 declared first -> s2, var_17 -> s1, var_16 -> s0, the
   parameter last -> s3; micro-test r1/r2); retail calls 002428f0
   before 001b0c80 and consumes the 001b0c80 result in v0, so nothing
   is hoisted across the call and only four s-regs are saved; every
   arm of both chains repeats its own store tail (a shared
   "if (b != 0)" epilogue collapses the eight arms and loses 92B);
   the constant (code,-1) pairs are written with array indexing
   (sh 0x50/0x52 folded) while the loop's node-id pairs use a pointer
   temp (addiu + sh 0/2); the 0xA6C/0xA68 globals need a materialized
   pointer for the store and a plain expression for the load;
   "if (aux >= 0) switch (aux)" reproduces retail's bltz bound check
   (micro-test f_guard) which no switch operand type alone emits.
   WALL (one instruction): retail rematerializes the id address
   (addiu v0,a0,0x52; lh v0,0(v0)) instead of folding it onto the
   code pointer (lh v0,2(a0)); the 4B shift is the whole residual.
   Fourteen addressing shapes (struct array, 2D, u8 views, dual
   pointers, nested scopes), both compiler builds (b210/b119),
   -O1/-O2/-O2,s/-O2,p/-O4 and the opt_propagation/opt_common_subs/
   opt_dead_code/opt_strength_reduction/opt_lifetimes pragmas all
   fold. A census over all 7942 matched functions finds no in-tree
   precedent for one sp-derived base with two materialized offsets.
   MEASURED, NOT BANKED: spelling the guard `if (aux > -1)` instead of
   `if (aux >= 0)` drops the reloc-masked residual from 57 words to 6, but
   it is not an improvement. That spelling emits `slti $at,$v0,0; bnez $at`
   where retail emits a single `bltz $v0`, and the extra instruction merely
   cancels the one missing `addiu` below, realigning every later branch
   offset. Two cancelling size errors score better than one honest one, so
   the body below keeps the form that matches retail's comparison.
   Resume: that rematerialization lever.
*/
s64 func_001f4e50(u8 *arg0) {
    s16 spbuf[128];
    s16 var_5;
    u8 *var_18;
    s32 var_17;
    s32 var_16;
    s32 temp_4;
    u8 *ac;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    var_17 = 0;
    var_16 = 0;
    ac = iGpffffb3ac;
    var_18 = *(u8 **)(ac + 0x178);
    while (var_18 != NULL) {
        if (func_002428f0(*(u8 **)(var_18 + 0xA64), 0) == 0) {
            u8 *t2 = (u8 *)func_001b0c80((s32)var_18);
            if ((t2 == NULL) || !(*(u16 *)(t2 + 0x18) & 0x20)) {
                if (func_00242930((void *)*(u8 **)(var_18 + 0xA64)) != 0) {
                    s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                    b[0] = 0x8A;
                    b[1] = *(u16 *)(var_18 + 0xA4);
                    var_17 = (var_17 + 1) & 0xFFFF;
                    var_16 = (var_16 + 1) & 0xFFFF;
                }
                if (*(u16 *)(var_18 + 0xA4) != 1) {
                    if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x10) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0x99;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x20) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0x9f;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x4) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xa5;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x2) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xab;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x1) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xb1;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x40) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xb7;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x80) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xbd;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    } else if (func_00232710(*(s32 *)(var_18 + 0xA64), 0x8) != 0) {
                        s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                        b[0] = 0xc3;
                        b[1] = *(u16 *)(var_18 + 0xA4);
                        var_17 = (var_17 + 1) & 0xFFFF;
                    }
                }
                if (func_002340c0(*(s32 *)(var_18 + 0xA64), 0xA) != 0) {
                    s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                    b[0] = 0x6F;
                    b[1] = *(u16 *)(var_18 + 0xA4);
                    var_17 = (var_17 + 1) & 0xFFFF;
                }
                if (func_002340c0(*(s32 *)(var_18 + 0xA64), 0x80) != 0) {
                    s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                    b[0] = 0x76;
                    b[1] = *(u16 *)(var_18 + 0xA4);
                    var_17 = (var_17 + 1) & 0xFFFF;
                }
                if (func_002340c0(*(s32 *)(var_18 + 0xA64), 0x220) != 0) {
                    s16 *b = &spbuf[(var_17 & 0xFFFF) * 2];
                    b[0] = 0x7D;
                    b[1] = *(u16 *)(var_18 + 0xA4);
                    var_17 = (var_17 + 1) & 0xFFFF;
                }
            }
        }
        var_18 = *(u8 **)(var_18 + 0xA6C);
    }
    {
        u8 *t18 = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(t18 + 0xA4) == 1) {
            if (func_00232710(*(s32 *)(t18 + 0xA64), 0x20) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x92;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(t18 + 0xA64), 0x2) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x94;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(t18 + 0xA64), 0x1) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x95;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(t18 + 0xA64), 0x40) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x96;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(t18 + 0xA64), 0x80) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x97;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            } else if (func_00232710(*(s32 *)(t18 + 0xA64), 0x8) != 0) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x98;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            }
        }
    }
    if ((var_16 & 0xFFFF) >= 2) {
        spbuf[(var_17 & 0xFFFF) * 2] = 0x89;
        spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
        var_17 = (var_17 + 1) & 0xFFFF;
    }
    temp_4 = func_001ef720(2, 0x80000) & 0xFFFF;
    {
        u8 *t214 = iGpffffb3ac;
        s16 *pa6c = (s16 *)(t214 + 0xA6C);
        if (*(s16 *)(t214 + 0xA6C) == temp_4) {
            if ((temp_4 < 6) && (temp_4 > 0)) {
                spbuf[(var_17 & 0xFFFF) * 2] = 0x89 - temp_4;
                spbuf[((var_17 & 0xFFFF) * 2) + 1] = -1;
                var_17 = (var_17 + 1) & 0xFFFF;
            }
        } else {
            *pa6c = temp_4;
        }
    }
    if ((var_17 & 0xFFFF) <= 0) {
        return -1;
    }
    {
        s16 *b3 = &spbuf[((func_00231d70(var_17 & 0xFFFF) & 0xFFFF)) * 2];
        s16 aux;
        u8 *t215;
        s32 *pa68;
        var_5 = b3[0];
        t215 = iGpffffb3ac;
        pa68 = (s32 *)(t215 + 0xA68);
        if (*(s32 *)(t215 + 0xA68) == var_5) {
            return -1;
        }
        *pa68 = var_5;
        aux = b3[1];
        if (aux >= 0) {
            switch (aux) {
            case 2:
                var_5 = var_5 + 1;
                break;
            case 3:
                var_5 = var_5 + 2;
                break;
            case 4:
                var_5 = var_5 + 3;
                break;
            case 6:
                var_5 = var_5 + 4;
                break;
            case 7:
                var_5 = var_5 + 5;
                break;
            case 8:
                var_5 = var_5 + 6;
                break;
            }
        }
    }
    return var_5;
}
