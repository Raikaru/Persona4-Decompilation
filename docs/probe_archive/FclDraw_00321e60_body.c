/* func_00321e60 draft, 2026-09-26 (supersedes the 150-edit body): 24 differing words
   reloc-masked, stack exact, same 1371/1370-instruction shape as before. See
   FclDraw_00321e60_20260926.md for the levers and the residual.

   Keep the static inline helper ABOVE the // FUN_ marker.

   NOTE (hard signature rule, 2026-09-26): the local externs below
   (func_003191c0 with s32 value parameters, func_002b83e0 taking FclVec2,
   func_0031e5b0 with FclVec2) must be reconciled with the real definitions before
   this body can be installed; the earlier notes on why each shape was chosen still
   apply. */
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

// FUN_00321E60
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
    s16 ka;
    u8 *ha;
    s16 ia;
    s16 ja;
    s32 ma;
    u8 *rowa;
    u8 *pa;
    s32 xa;
    s32 acca;
    s16 jb1;
    s16 kb1;
    s32 mb1;
    u8 *rowb1;
    u8 *pb1;
    u8 *hb1;
    s32 xb1;
    s32 accb1;
    s16 jb2;
    s16 kb2;
    u8 *rowb2;
    s16 jc;
    s16 kc;
    u8 *rowc;
    u8 *hc;
    s32 xc;

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
            ia = 0;
            while ((s16)ia < (u16)func_0010b5b0()) {
                func_003191c0(arg0, func_002b2970(16.0f, 128.0f), (s8)ia, *(u16 *)(func_002e48a0(0, ia) + 2),
                              *(u8 *)(func_002e48a0(0, ia) + 4), 0, 1, *(s8 *)(func_002e4870(0) + 8));
                ++ia;
            }
            func_0031e5b0(arg0, func_002b2970(16.0f, 104.0f), 0, 1, 0, 0, 0);
            func_00316e80(arg0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0);
            ja = 0;
            while ((s16)ja < (u16)func_0010b5b0()) {
                ma = ja * 23;
                pa = func_0034ae50(*(u8 **)(t + 0x184), (s8)ja);
                func_002b83e0(pa, func_002b2970((f32)(ma + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                              func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                ka = 0;
                rowa = t + ja * 4;
                acca = ma + 0x7F;
                while ((s16)ka < (u16)func_0010b5b0()) {
                    func_002b83e0(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka),
                                  func_002b2970((f32)(ka * 23 + 0x149), (f32)acca),
                                  *(FclByte4 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 0x75),
                                  *(FclByte4 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 0x75),
                                  *(u8 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 0x5E),
                                  *(u8 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 0x5E),
                                  32.0f, *(f32 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 4), 3, 0, 1, 0);
                    ++ka;
                }
                {
                    s16 normalizedRow = ja;
                    s16 resource = (s16)((u32)normalizedRow + 0x25E);
                    ha = func_0046d200(func_00331560(), 0x39);
                    func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                    func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                    xa = (u32)normalizedRow * 23 + 0x14E;
                    func_002b69f0(resource, func_002b2970((f32)xa, 110.0f),
                                  func_002b2970((f32)xa, 110.0f + func_0046b2f0(ha) / 2.0f), 0, 3, 0);
                    func_0046d280(ha);
                }
                ++ja;
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
                jb1 = 0;
                while ((s16)jb1 < (u16)func_0010b5b0()) {
                    func_0031ac10(arg0, func_002b2970((f32)0x149, 128.0f), *(s8 *)(t + 0x128), (s8)jb1,
                                  *(u16 *)(func_002e48a0(*(s8 *)(t + 0x128) + 1, jb1) + 2),
                                  *(u8 *)(func_002e48a0(*(s8 *)(t + 0x128) + 1, jb1) + 4), 3, 0, 1, 0xCC);
                    mb1 = jb1 * 23;
                    pb1 = func_0034ae50(*(u8 **)(t + 0x184), (s8)jb1);
                    func_002b83e0(pb1, func_002b2970((f32)(mb1 + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                                  func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
                    kb1 = 0;
                    rowb1 = t + jb1 * 4;
                    accb1 = mb1 + 0x7F;
                    while ((s16)kb1 < (u16)func_0010b5b0()) {
                        func_002b83e0(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1),
                                      func_002b2970((f32)(kb1 * 23 + 0x149), (f32)accb1),
                                      *(FclByte4 *)(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1) + 0x75),
                                      *(FclByte4 *)(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1) + 0x75),
                                      *(u8 *)(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1) + 0x5E),
                                      *(u8 *)(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1) + 0x5E),
                                      32.0f, *(f32 *)(func_0034ae50(*(u8 **)(rowb1 + 0x154), (s8)kb1) + 4), 3, 0, 1, 0);
                        ++kb1;
                    }
                    {
                        s16 normalizedRow = jb1;
                        s16 resource = (s16)((u32)normalizedRow + 0x25E);
                        hb1 = func_0046d200(func_00331560(), 0x39);
                        func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                        func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                        xb1 = (u32)normalizedRow * 23 + 0x14E;
                        func_002b69f0(resource, func_002b2970((f32)xb1, 110.0f),
                                      func_002b2970((f32)xb1, 110.0f + func_0046b2f0(hb1) / 2.0f), 0, 3, 0);
                        func_0046d280(hb1);
                        c = *(s8 *)(t + 0x128);
                        if (*(s8 *)(func_002e4870(0) + c * 12 + (u32)normalizedRow + 0x14) > 0) {
                            func_002f9c30(func_002e48a0(*(s8 *)(t + 0x128) + 1, jb1),
                                          func_002e48a0(0, *(s8 *)(t + 0x128)),
                                          func_002e48a0(0, jb1), 0, 0, 0, 0, 2, (s8)(c + 1), (s8)jb1);
                        }
                    }
                    ++jb1;
                }
                func_0031fa20(arg0, func_002b2970((f32)0x149, 104.0f), 3, 0);
                func_003205f0(arg0, 0x94, 0x93);
                func_002b68d0(0x1C7, 2, 1);
                func_0031e320(arg0, (s32)*(s8 *)(t + 0x128));
            } else {
                func_002e4ac0(1, *(s8 *)(t + 0x128));
                func_002b6a70(0x7E, 0xFF, 0, 0, 6, 0);
                *(u8 *)(func_002b6150(0x7E) + 0x47) = 0;
                jb2 = 0;
                while ((s16)jb2 < (u16)func_0010b5b0()) {
                    s16 cur;

                    kb2 = 0;
                    cur = (s16)jb2;
                    m = cur * 12;
                    rowb2 = t + cur * 4;
                    while ((s16)kb2 < (u16)func_0010b5b0()) {
                        if (*(s8 *)((u8 *)addOff(m, (u32)func_002e4870(0)) + kb2 + 0x14) == 0) {
                            if (*(s16 *)(t + 0x11E) == cur) {
                                c21C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                c21C = func_002b2a60(0, 0, 0x99, 0xA5);
                            }
                            alpha = c21C.c3;
                            func_002b83e0(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2),
                                          *(FclVec2 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 0x28),
                                          func_002b2a60(0, 0, 0x99, 0xA5), c21C, alpha, alpha,
                                          32.0f, *(f32 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 4), 6, 0, 1, 1);
                        } else {
                            if (*(s16 *)(t + 0x11E) == cur) {
                                c21C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);
                            } else {
                                c21C = func_002b2a60(0x49, 0x72, 0xFF, 0xCC);
                            }
                            alpha = c21C.c3;
                            func_002b83e0(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2),
                                          *(FclVec2 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 0x28),
                                          func_002b2a60(0, 0, 0x99, 0xCC), c21C, alpha, alpha,
                                          32.0f, *(f32 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 4), 6, 0, 1, 1);
                        }
                        ++kb2;
                    }
                    jb2 = (s16)(jb2 + 1);
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
        jc = 0;
        while ((s16)jc < (u16)func_0010b5b0()) {
            func_003191c0(arg0, func_002b2970(16.0f, 128.0f), (s8)jc, *(u16 *)(func_002e48a0(0, jc) + 2),
                          *(u8 *)(func_002e48a0(0, jc) + 4), 0, 1, *(s8 *)(func_002e4870(0) + 8));
            m = jc * 23;
            func_002b83e0(func_0034ae50(*(u8 **)(t + 0x184), (s8)jc), func_002b2970((f32)(m + 0x149), 104.0f), func_002b2a60(0, 0, 0x99, 0xFF),
                          func_002b2a60(0, 0, 0x99, 0xFF), 0xFF, 0xFF, 32.0f, 159.0f, 2, 0, 1, 0);
            kc = 0;
            rowc = t + jc * 4;
            while ((s16)kc < (u16)func_0010b5b0()) {
                func_002b83e0(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc),
                              *(FclVec2 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x28),
                              *(FclByte4 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x75),
                              *(FclByte4 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x75),
                              *(u8 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x5E),
                              *(u8 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x5E),
                              32.0f, *(f32 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 4), 3, 0, 1, 0);
                ++kc;
            }
            {
                s16 normalizedRow = jc;
                s16 resource = (s16)((u32)normalizedRow + 0x25E);
                hc = func_0046d200(func_00331560(), 0x39);
                func_002b6a70(resource, 0xFF, 0, 0, 3, 0);
                func_002b6af0(resource, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, 0);
                xc = (u32)normalizedRow * 23 + 0x14E;
                func_002b69f0(resource, func_002b2970((f32)xc, 110.0f),
                              func_002b2970((f32)xc, 110.0f + func_0046b2f0(hc) / 2.0f), 0, 3, 0);
                func_0046d280(hc);
            }
            ++jc;
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
