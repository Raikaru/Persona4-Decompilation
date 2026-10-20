#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"

typedef struct BtlPacket BtlPacket;

/* Cached table header followed by four-byte (model ID, variant flags) rows. */
typedef struct BtlNpcVariantEntry
{
    u16 modelId;
    s16 flags;
} BtlNpcVariantEntry;

typedef struct BtlNpcVariantTable
{
    u32 unk00;
    s32 count;
    BtlNpcVariantEntry entries[1];
} BtlNpcVariantTable;

/* gp - 0x4C54 = 0x007690f0 - 0x4c54 = 0x0076449c */
extern u8 *iGpffffb3ac;

extern u8 *iGpffffa5f0;

extern void btlBuildNpcModelName(s32 *destination, s32 modelId);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s16 day);
extern s32 sprintf(char *buf, char *fmt, ...);
extern void btlBossResolveNpcModelName(s32 destination, u16 modelId);
extern u8 *H_Cdvd_LookupRequest(void *pathAddress, u32 *slot);
extern char D_007636e0;
extern char D_006358D0[];
extern char D_006358F0[];
extern char D_00635910[];
extern char D_00635678[];
extern char D_00635690[];
extern char D_006356B0[];
extern char D_006356D0[];
extern char D_006356F0[];
extern char D_00635710[];
extern char D_00635730[];
extern char D_00635750[];
extern char D_00635770[];
extern char D_00635790[];
extern char D_006357B0[];
extern char D_006357C8[];
extern void mdlAttachSlotModelFromResource(void *model, u16 slotIndex, u32 type, u16 id,
                           void *resource, u32 flags);
extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slotIndex, u32 type, u16 id,
                          u32 flags);
extern char D_006357E0[];
extern char D_00635800[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0023; members 00231380-00231550 */

// Intent: Writes the NPC model file name for a battle model id: the "npc/" or "npc2/" directory, the id and a variant from its table entry and the current flags [inferred]
// FUN_00231380
void btlBuildNpcModelName(s32 *destination, s32 modelId)
{
    u32 fileSize;
    s16 variantFlags;
    s32 variant;
    s32 maskedId;
    s32 entryCount;
    s32 variantGroup;
    s32 entryIndex;
    s64 wideFlags;
    s64 dayFlags;
    u8 *table;
    u8 *entry;
    u8 *entries;

    variant = 0;
    variantFlags = 0;
    table = H_Cdvd_LookupRequest(&D_006358D0, &fileSize);
    entryCount = ((BtlNpcVariantTable *)table)->count;
    entries = table + 8;
    maskedId = modelId & 0xFFFF;
    entryIndex = 0;
    while (entryIndex < entryCount)
    {
        entry = entries + (entryIndex * 4);
        if (maskedId == ((BtlNpcVariantEntry *)entry)->modelId)
            variantFlags = ((BtlNpcVariantEntry *)entry)->flags;
        else
        {
            entryIndex++;
            continue;
        }
        break;
    }
    wideFlags = (s64)variantFlags;
    if (wideFlags > 0)
    {
        dayFlags = (s64)(s16)calGetDayWindowFlags((s16)datGetDateIndex());
        if (!(dayFlags & 1))
        {
            if (wideFlags & 3)
                variantGroup = 0;
            else
                variantGroup = 1;
        }
        else if (wideFlags & 0xC)
            variantGroup = 1;
        else
            variantGroup = 0;
        if (dayFlags & 2)
        {
            if (wideFlags & 0xA)
                variant = (variantGroup * 2) + 2;
            else
                variant = (variantGroup * 2) + 1;
        }
        else if (wideFlags & 5)
            variant = (variantGroup * 2) + 1;
        else
            variant = (variantGroup * 2) + 2;
    }
    if (maskedId < 0xC50)
        sprintf((char *)destination, D_006358F0, &D_007636e0,
                      maskedId, variant);
    else
        sprintf((char *)destination, D_00635910, &D_007636e0,
                      maskedId, variant);
}

// Intent: Boss model name resolver for case 5 (NPC models): forwards to btlBuildNpcModelName [inferred]
// FUN_00231550
void btlBossResolveNpcModelName(s32 destination, u16 modelId)
{
    btlBuildNpcModelName((s32 *)destination, modelId & 0xFFFF);
}

