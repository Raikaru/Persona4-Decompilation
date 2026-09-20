/* Archived proposal, not authoritative source.
 * Configured b210 / -O2 / -Iinclude: 3728/3728 bytes; all 60 code relocations
 * and the complete ten-entry, 40-byte table at 0x00747c10 resolve exactly.
 * The declaration order index-before-count closes the prior ten-word floor.
 * Requires the coherent provider contract s32 func_0023d8e0(u8 *, s32), which
 * preserves the provider's own 208-byte implementation. Existing external
 * callers still need source repairs before this proposal may be integrated.
 * Production keeps func_0023d8e0(u8 *, u16) and the 00238940 assembly guard.
 * datScript's wide-contract repair is now exact; 001138c0, 001da5f0 and
 * 0020b6d0 remain unresolved. Their final residuals are listed in the note.
 * Splice into datCalc.c with its existing PTDatCalc helpers; this is not a
 * standalone translation unit. See DC_worker3_20260920_recoveries.md.
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
    s32 index;
    s32 count;
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
