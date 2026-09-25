/* func_00321e60 draft (2026-09-25): 1371/1370 instructions, frame 0x220, every
   stack slot and every non-register operand at its retail value. fnalign 150 edits;
   with $s register names and relocations ignored the only differences are the
   relocated D_ addresses and the trailing zero word. The remainder is callee-saved
   register colouring (old guarded body: 1406 words, did not compile any more).

   Keep the two static inline helpers ABOVE the // FUN_ marker.

   What each lever fixed:
     - D_008C027A/024E/024C as `extern u16 x[];` (lui/lhu, not gp-relative).
     - Struct-return func_002b2970 and func_002b2a60 nested in the consuming calls,
       with only c21C named. Temporaries are laid out in appearance order (4-byte
       ones from 0x218 down, 8-byte ones from 0x1F0 down), which is retail's frame.
     - The 0x1E4 arrow sprite lives in an inline helper (fclShowCursorArrow). Inline
       bodies get their temporaries after the caller's, which is why retail's 0x1E4
       point is the last slot (0x158). `f32 dx = 60.0f` inside it gives retail's
       x-then-constant load order.
     - Local externs: func_003191c0 with s32 value parameters (forces the lhu/lbu/lb
       right after each func_002e48a0/func_002e4870 call), func_002b83e0 taking
       FclVec2 (lets the struct-return point and *(FclVec2 *)(e + 0x28) pass directly;
       the latter still loads with ldl/ldr), func_0031e5b0/func_0031fa20 taking FclVec2.
     - The per-row cursor block recomputes `normalizedRow * 23 + 0x14E`; writing
       `(u32)normalizedRow` (and the same cast in the 0x14 index and the resource)
       stops b210 reusing the row's `j * 23` across the inner loop, which removed three
       spill slots.
     - k-loops call func_0034ae50 inline in the func_002b83e0 argument list, so the
       first result is a temporary that spills with sq like retail.
     - Arm 0x40 else: block-scope `s16 cur = (s16)j` for the m*12 / row / compare
       values (an s32 cur loses retail's normalisation; a separate s32 counter
       perturbs the whole colouring);
       addOff(m, base) + k for the address; `(s32)` cast on the func_0031e320 argument
       for retail's load-before-move order.

   Residual: register colouring only. Retail has arg1 in $s5 (b210 $s6) and, per arm,
   different $s0/$s2/$s3/$s4 roles for k/row/normalizedRow/resource. Measured without
   effect: 15 placements of the extra local, jj/i/j as the else-arm counter, arg1 as
   s8/s16/s32/u8, arg2/arg3 as s32, no `m`/`acc` locals, row before k, and a permuter run from this body
   (1855 compiles, best 168 = baseline). */
static inline void fclShowCursorArrow(u8 *t)
{
    extern FclVec2 func_002b2970(f32, f32);
    FclVec2 *v = (FclVec2 *)D_00644C90;
    f32 dx = 60.0f;

    func_002b6c30(0x1E4, func_002b2970(v->x + dx, v->y), 103.0f, 0xBC);
    func_002b6a70(0x1E4, 0, 0xFF, 0, 0xA, 0);
    func_002b6b40(0x1E4, 0, 0, 0, 0.0f, 90.0f);
    func_002b6140(*(u8 **)(t + 0x28C), 1);
    func_002b6140(*(u8 **)(t + 0x290), 1);
}

void func_00321e60(u8 *arg0, s64 arg1, u8 arg2, u8 arg3) {
    extern FclVec2 func_002b2970(f32, f32);
    extern void func_002b83e0(u8 *, FclVec2, FclDrawColor, FclDrawColor, u8, u8, f32, f32, s32, s32, s8, s8);
    extern void func_003191c0(u8 *, FclVec2, s32, s32, s32, s32, s32, s32);
    extern void func_0031e5b0(u8 *, FclVec2, s32, s8, s32, s32, s32);
    extern void func_0031fa20(u8 *, FclVec2, s32, s8);
    extern u16 D_008C027A[];
    extern u16 D_008C024E[];
    extern u16 D_008C024C[];
    extern f32 D_00644150[];
    extern void func_002f9c30(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s64, s64);
    extern void func_002e4ac0(s32, s32);
    extern void func_0045af60(s32, s32, s32, s32);
    FclByte4 c21C;
    u8 *t;
    FclVec2 *v;
    s16 i;
    s16 j;
    s16 k;
    s32 m;
    s32 x;
    s32 acc;
    s8 c;
    u8 alpha;
    u8 *p;
    u8 *row;
    u8 *h;

    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0x128) = -1;
    *(s8 *)(t + 0x129) = -1;
    i = 0;
    while ((s16)i < (u16)func_0010b5b0()) {
        func_0031d630(arg0, (s8)i, *(s8 *)(t + 0x128), *(s8 *)(t + 0x129), arg1);
        ++i;
    }
    if (D_008C027A[0] & 0x1000) {
        *(s16 *)(t + 0x11E) = func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, (u16)func_0010b5b0() - 1, 2);
        func_0045af60(0, 0, 0, 0);
        return;
    }
    if (D_008C027A[0] & 0x4000) {
        *(s16 *)(t + 0x11E) = func_002b2cb0(*(s16 *)(t + 0x11E), 1, (u16)func_0010b5b0() - 1, 0, 2);
        func_0045af60(0, 0, 0, 0);
        return;
    }
    if (D_008C024E[0] & 0x80) {
        if (*(s16 *)(t + 0x11E) < *(s32 *)(func_002e4870(0) + 8)) {
            func_0045af60(0, 1, 0, 3);
            i = 0;
            while ((s16)i < (u16)func_0010b5b0()) {
                func_003191c0(arg0, func_002b2970(16.0f, 128.0f), (s8)i, *(u16 *)(func_002e48a0(0, i) + 2),
                              *(u8 *)(func_002e48a0(0, i) + 4), 0, 1, *(s8 *)(func_002e4870(0) + 8));
                ++i;
            }
            func_0031e5b0(arg0, func_002b2970(16.0f, 104.0f), 0, 1, 0, 0, 0);
            func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
            j = 0;
            while ((s16)j < (u16)func_0010b5b0()) {
                m = j * 23;
                p = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
                func_002b83e0(p, func_002b2970((f32)(m + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                              func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                k = 0;
                row = t + j * 4;
                acc = m + 0x7F;
                while ((s16)k < (u16)func_0010b5b0()) {
                    func_002b83e0(func_0034ae50(*(u8 **)(row + 0x154), (s8)k),
                                  func_002b2970((f32)(k * 23 + 0x149), (f32)acc),
                                  *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                                  *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                                  *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                                  *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                                  32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                    ++k;
                }
                {
                    s16 normalizedRow = j;
                    s16 resource = (s16)((u32)normalizedRow + 0x25E);
                    h = func_0046d200(func_00331560(), 0x39);
                    func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                    func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    x = (u32)normalizedRow * 23 + 0x14E;
                    func_002b69f0(resource, func_002b2970((f32)x, 110.0f),
                                  func_002b2970((f32)x, 110.0f + func_0046b2f0(h) / 2.0f), 0, 3, 0);
                    func_0046d280(h);
                }
                ++j;
            }
            fclShowCursorArrow(t);
            if ((s8)arg1 == 0) {
                *(u8 *)(t + 1) = 0x28;
            } else {
                *(u8 *)(t + 1) = 0x3E;
            }
        }
    } else if (D_008C024C[0] & 0x40) {
        if (*(s16 *)(t + 0x11E) < *(s32 *)(func_002e4870(0) + 8)) {
            func_0045af60(0, 0, 0, 1);
            *(s8 *)(t + 0x128) = *(s16 *)(t + 0x11E);
            v = (FclVec2 *)D_00644150;
            func_0031c2b0(arg0, *(s16 *)(t + 0x11E), func_002b2970(-380.0f, v->y), func_002b2970(v->x, v->y));
            if ((s8)arg1 == 0) {
                j = 0;
                while ((s16)j < (u16)func_0010b5b0()) {
                    func_0031ac10(arg0, func_002b2970((f32)0x149, 128.0f), *(s8 *)(t + 0x128), (s8)j,
                                  *(u16 *)(func_002e48a0(*(s8 *)(t + 0x128) + 1, j) + 2),
                                  *(u8 *)(func_002e48a0(*(s8 *)(t + 0x128) + 1, j) + 4), 3, 0, 1, 0xCC);
                    m = j * 23;
                    p = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
                    func_002b83e0(p, func_002b2970((f32)(m + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                                  func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                    k = 0;
                    row = t + j * 4;
                    acc = m + 0x7F;
                    while ((s16)k < (u16)func_0010b5b0()) {
                        func_002b83e0(func_0034ae50(*(u8 **)(row + 0x154), (s8)k),
                                      func_002b2970((f32)(k * 23 + 0x149), (f32)acc),
                                      *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                                      *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                                      *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                                      *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                                      32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                        ++k;
                    }
                    {
                        s16 normalizedRow = j;
                        s16 resource = (s16)((u32)normalizedRow + 0x25E);
                        h = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                        func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        x = (u32)normalizedRow * 23 + 0x14E;
                        func_002b69f0(resource, func_002b2970((f32)x, 110.0f),
                                      func_002b2970((f32)x, 110.0f + func_0046b2f0(h) / 2.0f), 0, 3, 0);
                        func_0046d280(h);
                        c = *(s8 *)(t + 0x128);
                        if (*(s8 *)(func_002e4870(0) + c * 12 + (u32)normalizedRow + 0x14) > 0) {
                            func_002f9c30(func_002e48a0(*(s8 *)(t + 0x128) + 1, j),
                                          func_002e48a0(0, *(s8 *)(t + 0x128)),
                                          func_002e48a0(0, j), 0, 0, 0, 0, 2, (s8)(c + 1), (s8)j);
                        }
                    }
                    ++j;
                }
                func_0031fa20(arg0, func_002b2970((f32)0x149, 104.0f), 3, 0);
                func_003205f0(arg0, 0x94, 0x93);
                func_002b68d0(0x1C7, 2, 1);
                func_0031e320(arg0, (s32)*(s8 *)(t + 0x128));
            } else {
                func_002e4ac0(1, *(s8 *)(t + 0x128));
                func_002b6a70(0x7E, 0xFF, 0, 0, 6, 0);
                *(u8 *)(func_002b6150(0x7E) + 0x47) = 0;
                j = 0;
                while ((s16)j < (u16)func_0010b5b0()) {
                    s16 cur;

                    k = 0;
                    cur = (s16)j;
                    m = cur * 12;
                    row = t + cur * 4;
                    while ((s16)k < (u16)func_0010b5b0()) {
                        if (*(s8 *)((u8 *)addOff(m, (u32)func_002e4870(0)) + k + 0x14) == 0) {
                            if (*(s16 *)(t + 0x11E) == cur) {
                                c21C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                c21C = func_002b2a60(0, 0, 0x99, 0xA5);
                            }
                            alpha = c21C.c3;
                            func_002b83e0(func_0034ae50(*(u8 **)(row + 0x154), (s8)k),
                                          *(FclVec2 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x28),
                                          func_002b2a60(0, 0, 0x99, 0xA5), c21C, alpha, alpha,
                                          32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 6, 0, 1, 1);
                        } else {
                            if (*(s16 *)(t + 0x11E) == cur) {
                                c21C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                c21C = func_002b2a60(0x49, 0x72, 0xFF, 0xCC);
                            }
                            alpha = c21C.c3;
                            func_002b83e0(func_0034ae50(*(u8 **)(row + 0x154), (s8)k),
                                          *(FclVec2 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x28),
                                          func_002b2a60(0, 0, 0x99, 0xCC), c21C, alpha, alpha,
                                          32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 6, 0, 1, 1);
                        }
                        ++k;
                    }
                    j = (s16)(j + 1);
                }
                func_003205f0(arg0, 0x94, 0x93);
                func_0031e320(arg0, (s32)*(s8 *)(t + 0x128));
            }
            *(u8 *)(t + 1) = arg2;
        }
    } else if (D_008C024E[0] & 0x20) {
        func_0045af60(0, 0, 0, 2);
        func_0010b5b0();
        func_0031e5b0(arg0, func_002b2970(16.0f, 104.0f), 0, 1, 0, 0, 0);
        j = 0;
        while ((s16)j < (u16)func_0010b5b0()) {
            func_003191c0(arg0, func_002b2970(16.0f, 128.0f), (s8)j, *(u16 *)(func_002e48a0(0, j) + 2),
                          *(u8 *)(func_002e48a0(0, j) + 4), 0, 1, *(s8 *)(func_002e4870(0) + 8));
            m = j * 23;
            p = func_0034ae50(*(u8 **)(t + 0x184), (s8)j);
            func_002b83e0(p, func_002b2970((f32)(m + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                          func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
            k = 0;
            row = t + j * 4;
            while ((s16)k < (u16)func_0010b5b0()) {
                func_002b83e0(func_0034ae50(*(u8 **)(row + 0x154), (s8)k),
                              *(FclVec2 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x28),
                              *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                              *(FclByte4 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x75),
                              *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                              *(u8 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 0x5E),
                              32.0f, *(f32 *)(func_0034ae50(*(u8 **)(row + 0x154), (s8)k) + 4), 3, 0, 1, 0);
                ++k;
            }
            {
                s16 normalizedRow = j;
                s16 resource = (s16)((u32)normalizedRow + 0x25E);
                h = func_0046d200(func_00331560(), 0x39);
                func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                x = (u32)normalizedRow * 23 + 0x14E;
                func_002b69f0(resource, func_002b2970((f32)x, 110.0f),
                              func_002b2970((f32)x, 110.0f + func_0046b2f0(h) / 2.0f), 0, 3, 0);
                func_0046d280(h);
            }
            ++j;
        }
        if ((s8)arg1 == 1) {
            func_002b6a70(0x7E, 0xFF, 0, 0, 0xA, 0);
            func_002b68d0(0x7E, 0, 0);
        }
        func_00316470(arg0, 1, 1);
        func_00316e80(arg0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
        *(u8 *)(t + 1) = arg3;
    }
}
