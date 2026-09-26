/* func_001b1d70 (src/promoted/code1_001b.c), 2026-09-26.
 * Measured with tools/fndiff.py: 4 reloc-masked differing words, object
 * 1548B in the 1552B window; fnalign 388/388 instructions. Previous floor
 * was 162 fnalign edits / 196 words.
 *
 * What closed it, all from the retail control flow:
 *  - the flag-0x100 block keeps a pointer to the 0x18-stride table entry and
 *    re-reads `*entry` at each test; bit 0x20 is the first branch, and the
 *    state dispatch is `switch (W->0x1A) { case 0: case 1: case 2: }`
 *    (retail compares 2, 1, 0) with func_001b1020(1) in case 0;
 *  - the two status rolls keep their func_0023d740 results as s32 locals
 *    declared `r1, r2, j` in that order (s16 locals re-extend at each use);
 *  - the reserve-slot read is integer arithmetic
 *    `*(s32 *)((u32)D_0076449C + i * 4 + 0xC74)` (base loaded first, then
 *    base + offset);
 *  - the party loop passes `*(s16 *)(list + 2)` to the u16 parameter, which
 *    puts retail's lhu ahead of the constant first argument.
 *
 * Residual (4 words) is a prototype contract, not codegen: retail passes the
 * u16 `id` to func_00477c40 and func_00145510 without masking, and calls
 * func_0047d170 with the model still in $a0. That needs u16 parameters on
 * func_00477c40 (its body masks both on entry) and func_00145510, and an
 * argument on func_0047d170. The repository definitions are
 * `void *func_00477c40(u32, u32, u32)` (mdlManager.c),
 * `void func_00145510(s32, s32)` (code1_0014.c) and `void func_0047d170(void)`
 * (code1_0047.c). Declaring func_00477c40 with u16 parameters everywhere
 * breaks six matched callers (mdlManager 121->120, mdlSE 6->5, effModel
 * 19->17, code1_0029 63->62, code1_004a 90->89, code1_0023 13->12), so the
 * retail units did not share one prototype. With the local declarations
 * written to agree with those definitions (the body below), the u32/int
 * widening adds `andi` at two calls and func_0047d170() lets the model load
 * go to $v0.
 */
void func_001b1d70(void) {
    extern s32 iGpffffb414;
    extern u8 *func_0019f5f0(s32 arg0, u16 arg1, u16 *arg2);
    extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
    extern void *func_00477c40(u32 arg0, u32 arg1, u32 arg2);
    extern u8 *func_0019b550(u8 *arg0, u16 arg1, s16 arg2);
    extern void func_0014a460(u16 arg0, u32 arg1);
    extern void func_0019d7a0(u8 *arg0, s32 arg1);
    extern void func_001987a0(u8 *arg0);
    extern void func_0047d170(void);
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
                *(u16 *)(unit + 0x9FE) = func_00145510(id, *(u8 **)(unit + 0xA00));
                func_0014a460(*(u16 *)(unit + 0x9FE), 1);
                func_0019d7a0(unit, 1);
                func_00198dd0(unit, 0);
                func_00198920(unit, *(s16 *)(unit + 0x9EC), 0, *(f32 *)(unit + 0x9F0), *(s8 *)(unit + 0x9F4));
                func_001987a0(unit);
                tmp = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(tmp + 0x2D0) == 0) {
                    func_0047d170();
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
