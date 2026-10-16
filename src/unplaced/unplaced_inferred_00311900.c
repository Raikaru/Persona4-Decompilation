/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00311900-00311e40 */

#include "include_asm.h"
#include "type.h"
#include "shdPersona_internal.h"
#include "datPersona_internal.h"
extern s32 cmmNameRecord();
extern u8 *iGpffffb3d4;
extern s16 D_006420A0[];
extern s32 datGetFlag(s32 arg0);
extern u16 cmmCommunityRecordValue(u16 arg0);
// FUN_00311900
s32 cmmCommunityName(s64 arg0)
{
    return cmmNameRecord(arg0 & 0xFFFF);
}

// FUN_00311930
s32 cmmCommunityExpRemaining(s32 arg0, u8 *arg1, s8 arg2)
{
    extern s32 shdPersonaCalcExpRemaining(struct DatPersonaRecord *arg0, s32 arg1);
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

    scale = D_00749500[cmmCommunityRecordValue(arg0)];
    whole = (u8)scale;
    fracScale = D_00749500[cmmCommunityRecordValue(arg0)];
    wholeF = (f32)(u32)whole;
    frac10 = (s16)(10.0f * (fracScale - wholeF));
    total = 0;
    i = 0;
    limit = whole & 0xFF;
    while ((s16)(s64)i < limit) {
        total = shdPersonaCalcExpRemaining((struct DatPersonaRecord *)arg1, (u8)i);
        i = (s16)(i + 1);
    }
    fracDelta = (s16)frac10;
    if (fracDelta != 0) {
        limit = shdPersonaCalcExpRemaining((struct DatPersonaRecord *)arg1, (u8)(limit - 1));
        total += (s32)((s32)fracDelta * 10 * ((shdPersonaCalcExpRemaining((struct DatPersonaRecord *)arg1, whole) - limit) / 100));
    }
    if ((s8)arg2 == 0) {
        return total;
    }
    return (s32)((f32)total * D_007494D0[cmmCommunityRecordValue(arg0)]);
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00311B90
s32 fclCombineRecipeMatchMask(u16 *arg0, u16 *arg1, s32 arg2, s16 *arg3)
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

    if (*arg0 == 0) {
        return 0;
    }
    count = 0;
    result = 0;
    base = (u8 *)arg0 + 4;
    i = 0;
    table = iGpffffb3d4;
    one = 1;
    for (; i < 8; i++) {
        entry = (SelectionEntry *)(base + (i * 2) + 4);
        value = entry->value;
        if (value != 0) {
            found = 0;
            for (j = 0; j < arg2; j++) {
                bit = (s32)((u32)one << j);
                if ((result & bit) == 0) {
                    if (entry->category != 0) {
                        candidate = *(u8 *)(table
                            + (*(u16 *)((u8 *)arg1 + (j * 2)) * 14) + 2);
                    } else {
                        candidate = *(u16 *)((u8 *)arg1 + (j * 2));
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
    if (arg3 != 0) {
        *arg3 = count;
    }
    return result;
}
#pragma pop

// FUN_00311D00
s64 cmmCommunityIsListable(s32 arg0)
{
    s64 result;
    u16 flags = *(u16 *)(iGpffffb3d4 + ((arg0 & 0xFFFF) * 14));

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

// FUN_00311D60
s32 cmmCommunityPassesFlagGate(s32 arg0)
{
    s16 flags;
    u32 index;
    s32 status;
    s32 value;
    u8 *entry;
    s32 result;

    status = 1;
    index = 0;
    value = arg0 & 0xFFFF;
    goto loop_test;
loop_body:
    entry = (u8 *)D_006420A0 + (index * 8);
    if (value != *(s16 *)(entry + 4)) {
        goto block_8;
    }
    flags = *(s16 *)(entry + 6);
    if (flags & 1) {
        if (datGetFlag(*(s32 *)entry) == 0) {
            result = 0;
            goto done;
        }
    } else {
        if ((flags & 2) == 0) {
            goto block_8;
        }
        status = 0;
        if (datGetFlag(*(s32 *)entry) == 1) {
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
// FUN_00311E40
s32 cmmCommunityHasFlagGate(s32 arg0)
{
    u32 i;

    i = 0;
    while (i < 0x17U) {
        if ((arg0 & 0xFFFF) == D_006420A0[i * 4 + 2]) {
            return 1;
        }
        i++;
    }
    return 0;
}
#pragma pop
