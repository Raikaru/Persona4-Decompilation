/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00311900-00311e40 */

#include "include_asm.h"
#include "type.h"
#include "shdPersona_internal.h"
#include "datPersona_internal.h"
/* The table indexed by community id has a 14-byte stride. Only its prefix is known here. */
typedef struct CmmCommunityRecord { u16 flags; u8 category; u8 pad03[11]; } CmmCommunityRecord;
typedef struct CmmFlagGate { s32 flag; s16 community; s16 mode; } CmmFlagGate;

extern s32 cmmNameRecord();
extern u8 *iGpffffb3d4;
extern s16 D_006420A0[];
extern s32 datGetFlag(s32 );
extern u16 cmmCommunityRecordValue(u16 );
// FUN_00311900
s32 cmmCommunityName(s64 community)
{
    return cmmNameRecord(community & 0xFFFF);
}

/* Compute the community-scaled Persona experience amount, including fractional-level interpolation and the optional multiplier. */
// FUN_00311930
s32 cmmCommunityExpRemaining(s32 community, u8 *persona, s8 applyMultiplier)
{
    extern s32 shdPersonaCalcExpRemaining(struct DatPersonaRecord *persona, s32 extraLevels);
    extern f32 D_007494D0[];
    extern f32 D_00749500[];
    f32 scale;
    f32 fracScale;
    f32 wholeF;
    s32 whole;
    s32 total;
    s64 frac10;
    s32 i;
    s32 limit;
    s32 fracDelta;

    scale = D_00749500[cmmCommunityRecordValue(community)];
    whole = (u8)scale;
    fracScale = D_00749500[cmmCommunityRecordValue(community)];
    wholeF = (f32)(u32)whole;
    frac10 = (s16)(10.0f * (fracScale - wholeF));
    total = 0;
    i = 0;
    limit = whole & 0xFF;
    while ((s16)(s64)i < limit) {
        total = shdPersonaCalcExpRemaining((struct DatPersonaRecord *)persona, (u8)i);
        i = (s16)(i + 1);
    }
    fracDelta = (s16)frac10;
    if (fracDelta != 0) {
        limit = shdPersonaCalcExpRemaining((struct DatPersonaRecord *)persona, (u8)(limit - 1));
        total += (s32)((s32)fracDelta * 10 * ((shdPersonaCalcExpRemaining((struct DatPersonaRecord *)persona, whole) - limit) / 100));
    }
    if ((s8)applyMultiplier == 0) {
        return total;
    }
    return (s32)((f32)total * D_007494D0[cmmCommunityRecordValue(community)]);
}

#pragma push
#pragma opt_loop_invariants on
/* Match up to eight recipe entries against unused materials; required entries must match and category entries compare arcana. */
// FUN_00311B90
s32 fclCombineRecipeMatchMask(u16 *recipe, u16 *materials, s32 materialCount, s16 *matchedCount)
{
    typedef struct {
        s16 value : 10;
        s16 reserved : 4;
        s16 category : 1;
        s16 required : 1;
    } SelectionEntry;
    s32 result;
    s16 count;
    s16 i;
    s32 value;
    s16 j;
    s16 found;
    s32 bit;
    s32 one;
    u16 candidate;
    u8 *base;
    u8 *table;
    SelectionEntry *entry;

    if (*recipe == 0) {
        return 0;
    }
    count = 0;
    result = 0;
    base = (u8 *)recipe + 4;
    i = 0;
    table = iGpffffb3d4;
    one = 1;
    for (; i < 8; i++) {
        entry = (SelectionEntry *)(base + (i * 2) + 4);
        value = entry->value;
        if (value != 0) {
            found = 0;
            for (j = 0; j < materialCount; j++) {
                bit = (s32)((u32)one << j);
                if ((result & bit) == 0) {
                    if (entry->category != 0) {
                        candidate = ((CmmCommunityRecord *)table)[materials[j]].category;
                    } else {
                        candidate = materials[j];
                    }
                    if ((candidate & 0xFFFF) == value) {
                        result |= bit;
                        count++;
                        found = 1;
                        break;
                    }
                }
            }
            if (entry->required != 0 && found == 0) {
                return 0;
            }
        }
    }
    if (matchedCount != 0) {
        *matchedCount = count;
    }
    return result;
}
#pragma pop

/* Exclude community-table records whose low two flag bits are set. */
// FUN_00311D00
s64 cmmCommunityIsListable(s32 community)
{
    s64 result;
    u16 flags = ((CmmCommunityRecord *)iGpffffb3d4)[community & 0xFFFF].flags;

    if (flags & 1) {
        result = 0;
        goto exit;
    }
    if (flags & 2) {
        result = 0;
        goto exit;
    }
    result = 1;
exit:
    return (s8)result;
}

/* Evaluate required flags and alternative enabling flags for the requested community. */
// FUN_00311D60
s32 cmmCommunityPassesFlagGate(s32 community)
{
    s16 flags;
    u32 index;
    s32 status;
    s32 value;
    u8 *entry;
    s32 result;

    status = 1;
    index = 0;
    value = community & 0xFFFF;
    goto loop_test;
loop_body:
    entry = (u8 *)D_006420A0 + (index * 8);
    if (value != ((CmmFlagGate *)entry)->community) {
        goto block_8;
    }
    flags = ((CmmFlagGate *)entry)->mode;
    if (flags & 1) {
        if (datGetFlag(((CmmFlagGate *)entry)->flag) == 0) {
            result = 0;
            goto done;
        }
    } else {
        if ((flags & 2) == 0) {
            goto block_8;
        }
        status = 0;
        if (datGetFlag(((CmmFlagGate *)entry)->flag) == 1) {
            result = 1;
            goto done;
        }
    }
block_8:
    index += 1;
loop_test:
    if (index < 0x17U) {
        goto loop_body;
    }
    result = status;
done:
    return result;
}

#pragma push
#pragma opt_loop_invariants on
/* Report whether any of the 23 flag-gate records refers to the requested community. */
// FUN_00311E40
s32 cmmCommunityHasFlagGate(s32 community)
{
    u32 i;

    i = 0;
    while (i < 0x17U) {
        if ((community & 0xFFFF) == D_006420A0[i * 4 + 2]) {
            return 1;
        }
        i++;
    }
    return 0;
}
#pragma pop
