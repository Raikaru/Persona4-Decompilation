/* func_001b1d70 (src/promoted/code1_001b.c), 2026-09-26 round 3 draft.
 * Subsequently installed as matching C after the model ID-plumbing cleanup:
 * 1548B, zero normalized differences in the 1552B window (four-byte zero tail).
 *
 * Round 2 levers (all kept): the flag-0x100 block keeps a pointer to the
 * 0x18-stride table entry and re-reads `*entry` at each test; the state
 * dispatch is `switch (W->0x1A) { case 0: case 1: case 2: }`; the two status
 * rolls keep their func_0023d740 results as s32 locals; the reserve-slot read
 * is `*(s32 *)((u32)D_0076449C + i * 4 + 0xC74)`; the party loop passes
 * `*(s16 *)(list + 2)` to the u16 parameter.
 *
 * Round 3 closed 3 of the 4 words by fixing callee contracts (landed in the
 * same commit as this note, every affected file re-verified, no regressions):
 *  - func_00145510 (code1_0014.c) is `s32 (u16, s32)`: retail passes arg0
 *    straight to func_00145540's u16 parameter without masking and every
 *    caller (btlUnit.c, here) reads the return value. The old definition
 *    `void (s32, s32)` needed a block-scope extern that disagreed with
 *    func_00145540's own definition.
 *  - func_0047d170 (code1_0047.c) is `void (void *model)`: retail leaves $a0
 *    untouched and calls the data callback, which takes the model (sibling
 *    func_0047d140 already had this shape). code1_0019.c's two-argument call
 *    was corrected to one argument (still MATCH; $a1 held that value only by
 *    coincidence).
 *
 * The final round-3 word (offset 196) was an unnecessary `andi` when the u16
 * id entered func_00477c40. The earlier seven-caller claim was wrong: that
 * experiment narrowed the type and flags too. The canonical signature is
 * `void *(u32 type, u16 id, u32 flags)`. Retyping mdlManager's helpers,
 * attachment IDs, callbacks and their providers preserves every prior match
 * and closes this function without a prototype exception. An unprototyped
 * declaration or widening this local ID merely moved the unwanted masks.
 * See Prototype_mismatch_00477c40_00478140_20260926.md for the complete survey
 * and linked-image verification. The active source is authoritative.
 */
void func_001b1d70(void) {
    extern s32 iGpffffb414;
    extern u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2);
    extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
    extern void *func_00477c40(u32 arg0, u16 arg1, u32 arg2);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern s32 func_00145510(u16 arg0, s32 arg1);
    extern void func_0014a460(u16 arg0, u32 arg1);
    extern void func_0019d7a0(u8 *arg0, s32 arg1);
    extern void func_001987a0(u8 *arg0);
    extern void func_0047d170(void *model);
    extern u8 *mdlGetClump(u8 *arg0);
    extern void func_004774e0(u8 *arg0);
    extern s32 func_001ef8c0(void);
    extern void func_001b11c0(s32 arg0);
    extern s32 func_001b0f20(s32 arg0);
    extern s32 func_0023d740(s32 arg0, s32 arg1);
    extern s32 func_0023a6b0(u8 *arg0, s32 arg1);
    extern u32 datCalcSetBadStatus(s32 unit, u32 badStatus);
    extern void func_001d1680(s32 arg0, s32 arg1);
    extern void btlUnitSetPos(u8 *arg0, f32 *arg1);
    u8 *tmp;
    u8 *unit;
    u32 k;
    s16 s1tmp;
    f32 st[3];
    s32 w2;
    u32 *entry;
    u8 *list;
    s64 v1;
    s32 r1;
    s32 r2;
    u8 *j;
    u32 i;
    u8 *pkt;
    u16 id;
    s32 f;

    v1 = 0;
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        i = 0;
        while (i < 4) {
            w2 = *(s32 *)((u32)D_0076449C + i * 4 + 0xC74);
            if (w2 == 0)
                break;
            tmp = *(u8 **)(w2 + 4);
            id = *(u16 *)(tmp + 2);
            pkt = func_0019f5f0(0, id, (u16 *)tmp);
            unit = *(u8 **)(pkt + 0x30);
            datCalcClearBadStatus(*(s32 *)(unit + 0xA64), 0xFFF7FFFF);
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFDF;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFF7;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFEF;
            w2 = (s32)func_00477c40((u16)(*(u8 *)(unit + 0xA2) + 1), id, 0);
            *(s32 *)(unit + 0xA00) = w2;
            if (w2 == 0) {
                pkt = func_0019b550(unit, id, 0x36);
                *pkt = 4;
                *(s64 *)(pkt + 8) = v1;
                func_00194590(pkt, 1);
                v1 = *(s64 *)(pkt + 0x58);
            } else {
                f = *(s32 *)(unit + 0x98) | 2;
                *(s32 *)(unit + 0x98) = f;
                *(s32 *)(unit + 0x98) = f | 8;
                *(u16 *)(unit + 0x9FE) = func_00145510(id, *(s32 *)(unit + 0xA00));
                func_0014a460(*(u16 *)(unit + 0x9FE), 1);
                func_0019d7a0(unit, 1);
                func_00198dd0(unit, 0);
                func_00198920(unit, *(s16 *)(unit + 0x9EC), 0, *(f32 *)(unit + 0x9F0), *(s8 *)(unit + 0x9F4));
                func_001987a0(unit);
                tmp = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(tmp + 0x2D0) == 0) {
                    func_0047d170(tmp);
                }
                func_0019d7a0(unit, 4);
                func_0019d040(unit);
                *(s32 *)(*(u8 **)(unit + 0xA00) + 0xD8) |= 0x400;
                func_004774e0(mdlGetClump(*(u8 **)(unit + 0xA00)));
            }
            i++;
        }
        *(u8 *)(D_0076449C + 0xC64) = (u8)i;
    }
    list = *(u8 **)(*(u8 **)(D_0076449C + 0xC68) + 4);
    k = 0;
    while (k < 6) {
        if (*(u16 *)(list + 2) != 0 && datCalcIsDead((s32)list, 0) == 0) {
            func_0019f5f0(1, *(s16 *)(list + 2), (u16 *)list);
        }
        k++;
        list += 0x30;
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x100) != 0) {
        entry = (u32 *)((u8 *)iGpffffb414 + (u32)*(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18);
        if ((*entry & 0x20) != 0) {
            if ((*entry & 0x10) == 0) {
                *(u16 *)(D_0076449C + 0x1A) = 0;
            }
            func_0022fdc0((u8 *)0);
        } else {
            *(u16 *)(D_0076449C + 0x1A) = func_001ef8c0();
            switch (*(u16 *)(D_0076449C + 0x1A)) {
            case 0:
                func_001b1020(1);
                func_001b1280(1);
                if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) != 0) {
                    func_001b0f20(*(s32 *)(D_0076449C + 0x170));
                }
                break;
            case 1:
                func_001b1020(0);
                func_001b11c0(0);
                func_001b0f20(*(s32 *)(D_0076449C + 0x170));
                *(u16 *)(D_0076449C + 0x290) |= 2;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            case 2:
                func_001b1020(0);
                func_001b11c0(1);
                func_001b1280(1);
                *(u16 *)(D_0076449C + 0x290) |= 4;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            }
        }
        if (((*(u16 *)(D_0076449C + 0xC70) & 8) != 0) && ((*entry & 0x100) == 0) &&
            ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0)) {
            r1 = (s16)func_0023d740(-1, 4);
            r2 = (s16)func_0023d740(-1, 2);
            for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
                if (*(u8 **)(j + 0xA64) != NULL) {
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r2) & 0x27000000) == 0 && (s32)func_00231d70(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(j + 0xA64), 2);
                    }
                    if ((func_0023a6b0(*(u8 **)(j + 0xA64), r1) & 0x27000000) == 0 && (s32)func_00231d70(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(j + 0xA64), 4);
                    }
                }
            }
        }
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        func_001d1680(1, 0);
        return;
    }
    func_001d1680(0, 0);
    st[1] = 0.0f;
    for (j = *(u8 **)(D_0076449C + 0x180); j != NULL; j = *(u8 **)(j + 0xA6C)) {
        st[0] = (f32)(*(s16 *)(j + 0x94) * 0x19 - 0x6D6);
        st[2] = (f32)(*(s16 *)(j + 0x96) * 0x19 - 0x6D6);
        btlUnitSetPos(j, st);
    }
}
