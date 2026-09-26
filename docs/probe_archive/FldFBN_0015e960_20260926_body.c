/* func_0015e960 (k_fldFBN.c, window 1696B) -- 2026-09-26 group 0 round 4.
 * Fresh rewrite from the retail listing. It is the same size as retail (1696B),
 * with verify normalized_diff 71 (the old guarded draft was 331 at 1712B).
 * NOT installed. It needs `extern void *func_00478140(u16, u16, u32)`, which
 * is the cross-owner contract already recorded for func_00162680 in
 * F162_00162680_20260926_body.c. With the tree's u32 prototype, the
 * parts-loop call gains one `andi 0xffff` on the CSE'd type value.
 *
 * The file-scope externs this draft assumes, all agreeing with their
 * definitions except func_00478140:
 *   extern s64 func_00110960(s32, u32);   extern s16 func_001060b0(void);
 *   extern u8 func_001060c0(void);        extern u32 datGetFlag(s32);
 *   extern s32 func_001453a0(u16);        extern u16 *func_0015cbe0(s32);
 *   extern void func_0015d100(u8 *, s32); extern u16 *func_0015d2c0(u32);
 *   extern u8 *func_0015d310(u16 *);      extern u32 H_Cdvd_IsFileLoaded(void *);
 *   extern void *func_00477e80(void *, void *, void *, u32);
 *   extern void **iGpffffb2a4;  plus FBN_ENTRY() from func_0015f000.
 *
 * Levers found (each measured):
 * - opt_loop_invariants on (push/pop). It hoists the inner searches' count and
 *   the 4/0xFFFF constants into a2/a0/a1 as retail does. The `num` local
 *   pins the count load.
 * - Shared function-scope counters. j is the anim-entry counter and the
 *   second search's index, and k is the first search's index and the
 *   anim2 counter. This keeps retail's DEAD j increment (s5) in the ae
 *   loop. With block-scoped counters b210 drops it. It also fixes the
 *   s3/s4 parameter colouring that the old note called a floor.
 * - Using `out` as the final loop counter gives retail's s0 there.
 * - The two allocations CSE &D_008873F4 into s0 only through a local
 *   `base = (u8 *)D_008873F4` with a u32-cast call (same shape as the
 *   matched func_0014ec50/func_001684a0). The plain D_008873F4[0], a local
 *   function-pointer copy, and an inline helper do not CSE it.
 * Residual: out (retail s4) swaps with the parts counter i (retail s0) and
 * with the ae/e2 entry pointers (retail s0), and the 001060b0 temp is s0,
 * not s1. Declaration-order sweeps (24 permutations of fbn/p/i/out, ae
 * at 7 positions, all block locals hoisted) did not beat this order.
 */
#pragma push
#pragma opt_loop_invariants on
// FUN_0015E960
s32 func_0015e960(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, s16 arg4)
{
    u32 size;
    SVec3 angles;
    char path[0x40];
    u8 *fbn;
    u8 *p;
    u32 i;
    u32 j;
    u32 k;
    u32 out;

    D_0076439C = 0;
    if (arg0 == NULL) {
        return 1;
    }
    *arg1 = NULL;
    if ((func_0014eec0() == 0) && (H_Cdvd_IsFileLoaded(arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        fbn = *(u8 **)(arg0 + 0x110);
    } else {
        sprintf(path, D_005F10B0, arg2 & 0xFFFF, arg3 & 0xFFFF, arg4);
        fbn = func_00455f70(path, &size);
        if (fbn == NULL) {
            return 1;
        }
        if (fbn == NULL) {
            func_0046d700(D_005F1068, 0x10D, &D_00762FD8, path);
        }
        *arg1 = fbn;
    }
    iGpffffb2a8 = *(u32 *)(fbn + 8);
    if (iGpffffb2a8 != 0) {
        u8 *base;

        func_0044ea90(D_005F1068, 0x117);
        base = (u8 *)D_008873F4;
        iGpffffb2a4 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, *(u32 *)(fbn + 8) * sizeof(void *), 0x40000);
        func_0044ea90(D_005F1068, 0x118);
        iGpffffb2a0 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, *(u32 *)(fbn + 8) * sizeof(FbnEntry), 0x40000);
    }
    p = fbn + 0x18;
    out = 0;
    for (i = 0; i < *(u32 *)(fbn + 8); i++) {
        if ((*(u16 *)(p + 4) == 4) && (*(u16 *)(p + 6) == 0xFFFF)) {
            if (D_00764340 == 1) {
                iGpffffb2a4[out] = func_00477e80((void *)4, (void *)0xFFFF, D_005F10D0, 0);
                FBN_ENTRY(out)->field_8 = i;
                out++;
            }
        } else {
            iGpffffb2a4[out] = func_00478140(*(u16 *)(p + 4), *(u16 *)(p + 6), 0);
            FBN_ENTRY(out)->field_8 = i;
            out++;
        }
        p += *(s32 *)(fbn + 0xC);
    }
    if (D_00764340 == 0) {
        u8 *head = func_0015ca30();

        if (head != NULL) {
            AnimEntry *ae = (AnimEntry *)func_0015cbe0(*(s32 *)(head + 0xC));

            for (j = 0; ae->field_0 != 0xFFFF; j++, ae++) {
                s32 kind;
                u8 *q;
                u32 num;

                if ((ae->field_10 != -1) && (datGetFlag(ae->field_10) == 1)) {
                    continue;
                }
                kind = ae->field_18;
                if (kind == 1) {
                    if ((s8)func_00110960(func_001060b0(), func_001060c0()) % 2 != 0) {
                        continue;
                    }
                } else if (kind == 2) {
                    if ((s8)func_00110960(func_001060b0(), func_001060c0()) % 2 == 0) {
                        continue;
                    }
                }
                q = fbn + 0x18;
                num = *(u32 *)(fbn + 8);
                for (k = 0; k < num; k++, q += *(s32 *)(fbn + 0xC)) {
                    if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF)
                        && (*(u16 *)(q + 8) == (u16)((ae->field_0 & 0x3FF) | 0xC00))) {
                        if ((ae->field_2 != 0) || (ae->field_4 != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = func_00478140(ae->field_2, ae->field_4, 0);
                            FBN_ENTRY(out)->kind = 1;
                            FBN_ENTRY(out)->field_4 = (s32)ae;
                            FBN_ENTRY(out)->field_8 = k;
                            out++;
                        }
                        break;
                    }
                }
            }
        }
        for (k = 0; k < D_00764388; k++) {
            AnimEntry2 *e2 = (AnimEntry2 *)func_0015d310(func_0015d2c0(k));

            if (e2 != NULL) {
                u8 *q = fbn + 0x18;
                u32 num = *(u32 *)(fbn + 8);

                for (j = 0; j < num; j++, q += *(s32 *)(fbn + 0xC)) {
                    if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF)
                        && (*(u16 *)(q + 8) == (u16)((e2->field_0 & 0x3FF) | 0xC00))) {
                        if ((e2->field_68 != 0) || (e2->field_6A != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = func_00478140(e2->field_68, e2->field_6A, 0);
                            FBN_ENTRY(out)->kind = 2;
                            FBN_ENTRY(out)->field_4 = (s32)e2;
                            FBN_ENTRY(out)->field_8 = j;
                            FBN_ENTRY(out)->field_10 = k;
                            func_0015d100((u8 *)FBN_ENTRY(out), k);
                            out++;
                        }
                        break;
                    }
                }
            }
        }
        iGpffffb2a8 = out;
    }
    for (out = 0; out < *(u32 *)(fbn + 0x10); out++) {
        u16 id = func_001453a0(*(u16 *)(p + 0x50) & 0x3FF);

        angles.x = func_0014b660(p + 0x10);
        angles.y = func_0014b5d0(p + 0x10);
        angles.z = func_0014b6f0(p + 0x10);
        func_00146e60(id, p + 0x40, (u8 *)&angles);
        p += 0x60;
    }
    return 1;
}
#pragma pop
