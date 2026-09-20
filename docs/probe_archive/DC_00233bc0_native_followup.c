/* 2026-09-19, owner src/Main/Battle/Data/datCalc.c at upstream
 * 0ec589932637d637b451882bfbaa479d5f8043a9. Production remains INCLUDE_ASM.
 * This measured complete-owner candidate emits 1256/1280 bytes and differs
 * in 259 positional words; fresh archived-source fnalign reports 41 edits
 * plus 9 relocation-only
 * comparisons. This is not an exact recovery. The previous current-owner
 * draft measured 1244/1280 bytes and 261 positional words.
 *
 * Repairs: case 4 includes retail's +7 table displacement; unsigned byte
 * conversion is expressed as (f32)(u32), without manual dead conversion arms;
 * the branch result is a signed byte before widening; each table branch
 * reloads the table where retail does. The explicit low-five-bit shift
 * count preserves the hardware behavior without an out-of-range C shift.
 * All provider declarations are inherited from the real owner. Valid unit
 * and table storage are required, as in the original function.
 *
 * Fourteen alternatives were compiled in build/match-next/00233bc0. Native
 * conversions alone tie the baseline. The signed-byte result gives 260
 * words/1232B; signed boost predicates give 263/1240B (41 alignment edits);
 * moving table loads into their cases gives this 259/1256B result. Inline
 * flag/selector helpers and propagation/common-subexpression toggles tie it.
 * Full integer subscripts also tie: adding a negative m to a pointer before
 * applying the final +1/+7 could form an invalid intermediate pointer. All
 * five table adjustments below are completed before the pointer addition.
 * The earlier raw-address spelling measured 36 alignment edits; the safe
 * subscripts retain the 259-word score but have 41 alignment edits. The final
 * archived source was separately recompiled with both listed tools.
 * No provider, caller, production source, or symbol metadata was changed.
 * Full target relocation proof, native execution and whole-image validation
 * are not claimed for this nonmatching candidate. Historical DC archive kept.
 *
 * Reproduce from the project root:
 * python tools/probe_variants.py src/Main/Battle/Data/datCalc.c func_00233bc0
 *   --candidate native=docs/probe_archive/DC_00233bc0_native_followup.c
 * python tools/fnalign.py src/Main/Battle/Data/datCalc.c func_00233bc0
 *   --candidate docs/probe_archive/DC_00233bc0_native_followup.c --quiet
 */
f32 func_00233bc0(u8 *arg0, s32 arg1)
{
    s32 disc;
    s8 b;
    s32 t2;
    u32 t4;
    f32 f20;
    f32 f1;
    s32 t3;
    u8 *tbl;
    s32 m;

    disc = arg1 & 0xFF;
    if (disc >= 24) {
        func_0046d730(D_00635938, 1265);
    }
    if (disc >= 24) {
        func_0046d730(D_00635938, 1217);
    }
    if (disc < 16) {
        b = func_002332a0(arg0, arg1);
    } else {
        b = (*(u32 *)(arg0 + 20) & (1U << (disc & 31))) != 0;
    }
    m = b;
    if (m < -1 || m > 1) {
        func_0046d730(D_00635938, 1269);
    }
    t2 = (*(u16 *)arg0 & 4);
    t4 = (t2 != 0) & 0xFFFF;
    f20 = 1.0f;
    switch (disc) {
    case 0:
        tbl = iGpffffb408;
        t3 = tbl[(s32)((t4 & 0xFFFF) * 3) + m + 1];
        f1 = (f32)(u32)t3;
        f20 = f1 / 100.0f;
        if ((s8)((*(u32 *)(arg0 + 20) & 0x40000U) != 0) > 0) {
            f20 = f20 * 2.5f;
        }
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
        break;
    case 1:
        tbl = iGpffffb408;
        t3 = tbl[(s32)((t4 & 0xFFFF) * 3) + m + 1];
        f1 = (f32)(u32)t3;
        f20 = f1 / 100.0f;
        if ((s8)((*(u32 *)(arg0 + 20) & 0x80000U) != 0) > 0) {
            f20 = f20 * 2.5f;
        }
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
        break;
    case 2:
        tbl = iGpffffb408;
        t3 = tbl[(s32)((t4 & 0xFFFF) * 3) + 7 - m];
        f1 = (f32)(u32)t3;
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * 0.75f;
        }
        break;
    case 3:
        tbl = iGpffffb408;
        t3 = tbl[(s32)((t4 & 0xFFFF) * 3) + 1 - m];
        f1 = (f32)(u32)t3;
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * 0.75f;
        }
        break;
    case 4:
        tbl = iGpffffb408;
        t3 = tbl[(s32)((t4 & 0xFFFF) * 3) + m + 7];
        f1 = (f32)(u32)t3;
        f20 = f1 / 100.0f;
        if (t2 == 0 && func_0010a9b0(*(u16 *)(arg0 + 2)) != 0) {
            f20 = f20 * iGpffff8110;
        }
        break;
    case 18:
        if (m > 0) {
            f20 = 2.5f;
        }
        break;
    case 19:
        if (m > 0) {
            f20 = 2.5f;
        }
        break;
    }
    return f20;
}
