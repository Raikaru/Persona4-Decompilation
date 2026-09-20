/* Unpromoted worker7 recovery of func_00238940.
 *
 * Saved b210 measurement: 3728/3728B, ten relocation-masked differing words
 * and ten aligned edits. This is NOT an exact recovery or an integration-ready
 * source. The ten remaining instruction differences are in the initial random
 * choice enumeration, around offsets 0xBC..0x114.
 *
 * The measured complete translation unit uses the existing datCalc inline
 * PTDatCalcHasSkill and PTDatCalcOffsetAdd definitions. It ALSO changes BOTH
 * the forward declaration and definition of func_0023d8e0 from
 *     s32 func_0023d8e0(u8 *arg0, u16 arg1)
 * to
 *     s32 func_0023d8e0(u8 *arg0, s32 arg1)
 * while retaining the provider body. The provider masks arg1 to 16 bits and
 * its saved object remains unchanged, but other owners still declare u16.
 * Reconcile the real provider/caller ABI together before any promotion; this
 * archive does not authorize an incompatible local declaration in production.
 *
 * A saved-object check preserves all 79 non-target functions and relocations.
 * The target creates a 40-byte, ten-entry local jump table. Full resolution of
 * that table is still pending: the generic resolver stops at local @1733,
 * HI16 relocation offset 0x418. Neither table placement nor complete target
 * relocation equality has been proved.
 *
 * Original source, complete TU, object and alignment remain under the retained
 * match-next-latest worktree at build/all-first-party/datcalc/
 * owner-eaa4708c2bba/00238940/both_clear_switches.{c,tu.txt,o,align.txt}.
 * Body SHA256: 195b8de2563ffa72c51c33e51c7561de59769d97587442e33350cbed5d6537cc
 * TU SHA256: c0f7e8b0c25fa339d6c27b95449ef5c4e6cff2ef6b6de427eca133b51a84bdfd
 * Object SHA256: 9921c1186edf804f7c415f86d1e13950d0f38024f4dc1b003fea115e1f38f03e
 * See DC_worker7_20260920_recovery_floors.md for the recovery inventory.
 */
#pragma push
#pragma opt_loop_invariants on
s32 func_00238940(s32 skillId, u8 *source, u8 *target, s32 options)
{
    u16 choices[24];
    s32 offset;
    u8 *entry;
    u8 mode;
    u8 kind;
    u32 statuses;
    s32 success;
    s32 count;
    s32 index;
    u32 choiceCount;
    s32 resistance;
    u32 percentage;
    f32 multiplier;
    f32 percent;
    f32 chance;
    s32 death;
    s32 rate;
    s32 element;
    u8 active;
    s16 message;
    extern s32 func_00243e30(u16 *unit);
    extern s32 func_0023d740(s32 skill, s32 mask);

    if ((skillId & 0xFFFF) >= 0x240) {
        func_0046d730(D_00635938, 0xA30);
    }
    offset = (u16)skillId * 0x28;
    entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
    if (entry[0x24] == 13) {
        return 0x80000;
    }
    multiplier = 1.0f;
    success = 0;
    statuses = *(u32 *)(entry + 0x1C) & 0xFFFFFFU;
    if (entry[0x18] == 3) {
        count = 0;
        index = 0;
        while ((index & 0xFFFF) < 24) {
            if (statuses & (1U << (index & 0xFFFF))) {
                choices[count & 0xFFFF] = index;
                count = (count + 1) & 0xFFFF;
            }
            index = (index + 1) & 0xFFFF;
        }
        choiceCount = count & 0xFFFF;
        if (choiceCount == 0) {
            func_0046d730(D_00635938, 0x17);
        }
        statuses = 1U << choices[func_003b7060() % choiceCount];
    }
    if (statuses != 0 &&
        ((entry = iGpffffb3b8, mode = *(u8 *)PTDatCalcOffsetAdd((u32)entry + 0x18U, (u32)offset), mode == 1) || mode == 3)) {
        switch (entry[offset + 0x24]) {
        case 14: {
            if ((u8)(target[0xC] != 0)) {
                goto return_status_0;
            }
            goto return_zero_0;
return_status_0:
            return (s32)statuses;
return_zero_0:
            return 0;
        }
        default:
            break;
        }
        if (func_00243e30((u16 *)target)) {
            return 0;
        }
        kind = iGpffffb3b8[offset + 0x24];
        switch (kind) {
        case 1:
            if ((u8)((*(u32 *)(target + 0xC) & 4) != 0)) {
                return (s32)statuses;
            }
            break;
        case 7:
            if (*(u16 *)target & 0x1000) {
                statuses = 0;
            }
            return (s32)statuses;
        case 8:
            switch (*(u16 *)target & 0x1000) {
            case 0:
                statuses = 0;
                break;
            default:
                break;
            }
            return (s32)statuses;
        case 9:
            if ((u8)((*(u32 *)(target + 0xC) & 1) != 0)) {
                goto return_status_1;
            }
            goto return_zero_1;
return_status_1:
            return (s32)statuses;
return_zero_1:
            return 0;
        default:
            break;
        }
        resistance = func_0023a6b0(target, (s16)func_0023d740((s16)skillId, (s32)statuses));
        if (resistance & 0x27000000) {
            return 0;
        }
        if (statuses & 0x100000) {
            if ((u8)((*(u32 *)(target + 0xC) & 0x100000) != 0)) {
                return 0;
            }
            if (*(u16 *)target & 8) {
                return 0;
            }
        }
        percentage = resistance & 0xFFFF;
        percent = (f32)percentage;
        multiplier = multiplier * (percent / 100.0f);
        if (!(options & 1)) {
            death = statuses & 0x80000;
            if (death == 0 && func_002332a0(target, 7) > 0) {
                multiplier *= 2.0f;
            }
            element = (s16)func_0023d8e0(source, skillId);
            switch (element) {
            case 9:
                if (PTDatCalcHasSkill(source, 0x217)) multiplier *= 1.25f;
                break;
            case 8:
                if (PTDatCalcHasSkill(source, 0x216)) multiplier *= 1.25f;
                break;
            case 10:
                if (PTDatCalcHasSkill(source, 0x21A)) multiplier *= 1.25f;
                break;
            case 6:
                if (PTDatCalcHasSkill(source, 0x21F)) multiplier *= 1.25f;
                break;
            case 7:
                if (PTDatCalcHasSkill(source, 0x220)) multiplier *= 1.25f;
                break;
            case 13:
                if (PTDatCalcHasSkill(source, 0x218)) multiplier *= 1.25f;
                break;
            case 15:
                if (PTDatCalcHasSkill(source, 0x219)) multiplier *= 1.25f;
                break;
            case 11:
                if (PTDatCalcHasSkill(source, 0x21B)) multiplier *= 1.25f;
                break;
            case 14:
                if (PTDatCalcHasSkill(source, 0x21D)) multiplier *= 1.25f;
                break;
            }
            if (death == 0 && PTDatCalcHasSkill(source, 0x21E)) {
                multiplier *= 1.25f;
            }
        }
    }
    if (statuses == 0) {
        return 0;
    }
    if ((s32)iGpffffb3b8[offset + 0x19] >= 100) {
        success = 1;
    } else {
        chance = (f32)func_00244f60(10, source, target, skillId, (s32)statuses);
        chance = chance * multiplier;
        rate = (s32)chance;
        if (rate > 99) {
            rate = 99;
        } else if (rate < 0) {
            rate = 0;
        }
        if ((s32)(func_003b7060() % 100U) < rate) {
            success = 1;
        }
    }
    if (success != 0 && (statuses & 0x80000) != 0 &&
        (s8)(active = (*(u32 *)(target + 0x14) & 0x800000) != 0) > 0) {
        statuses &= ~0x80000U;
        if (*(u16 *)target & 4) {
            message = 0x79;
        } else {
            message = 0x78;
        }
        *(s16 *)(target + 0x2C) = message;
        *(u32 *)(target + 0x18) |= 0x800000;
    }
    switch (success) {
    case 0:
        statuses = 0;
        break;
    default:
        break;
    }
    return (s32)statuses;
}
#pragma pop
