/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0029D900)
/* Source unit: src/Script/scrScriptProcess_0029d900.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;
typedef struct ScrData ScrData;

void* dds3GetProcessWorkData(KwlnTask* task);
void dds3SetProcessWorkData(KwlnTask* task, void* workData);
void scrReleaseScript(ScrData* scr);

// FUN_0029D900
void scrDestroyTask(KwlnTask* scrTask)
{
    ScrData* scr;

    scr = (ScrData*)dds3GetProcessWorkData(scrTask);
    if (scr != NULL)
    {
        scrReleaseScript(scr);
    }

    dds3SetProcessWorkData(scrTask, NULL);
}
#endif /* P4_UNIT_0029D900 */

#if defined(P4_UNIT_0029DE20)
/* Source unit: src/Script/scrScriptProcess_0029de20.c */
#include "type.h"

typedef enum
{
    SCR_CONTENT_TYPE_PROCEDURE,
    SCR_CONTENT_TYPE_LABEL,
    SCR_CONTENT_TYPE_INSTR,
    SCR_CONTENT_TYPE_MSG,
    SCR_CONTENT_TYPE_STRINGS,
    SCR_CONTENT_TYPE_MAX
} ScrContentType;

// 16 bytes
typedef struct
{
    u32 contentType;  // 0x00. See enum 'ScrContentType'
    u32 unk_04;
    s32 elementCount; // 0x08
    u32 offset;       // 0x0c
} ScrContentEntry;

// 112 bytes
typedef struct ScrHeader
{
    s32 unk_00;                                    // 0x00
    u32 scrSize;                                   // 0x04
    char magic[4];                                 // 0x08. "FLW0"
    u32 unk_0c;
    u32 totalEntries;                              // 0x10
    s16 localIntNum;                               // 0x14
    s16 localFloatNum;                             // 0x16
    s32 unk_18;                                    // 0x18
    s32 unk_1c;                                    // 0x1c
    ScrContentEntry entries[SCR_CONTENT_TYPE_MAX]; // 0x20
} ScrHeader;

// 32 bytes. Label or procedure (this name is horrible)
typedef struct
{
    char name[24]; // 0x00
    u32 addr;      // 0x18
    s32 unk_1c;    // 0x1c
} ScrLblPrcd;

int strcmp(const char* s1, const char* s2);

// FUN_0029DE20
s32 scrFindPrcdIdxByName(ScrHeader* header, const char* name)
{
    ScrContentEntry* entries;
    s32 totalEntries;
    s32 i;
    ScrContentEntry* currEntry;
    ScrLblPrcd* prcd;
    s32 j;
    s32 elementCount;

    prcd = NULL;
    if (header == NULL)
    {
        return -1;
    }

    entries = header->entries;
    i = 0;
    totalEntries = header->totalEntries;
    for (; i < totalEntries; i++)
    {
        currEntry = &entries[i];

        if (currEntry->contentType == SCR_CONTENT_TYPE_PROCEDURE)
        {
            prcd = (ScrLblPrcd*)((uintptr_t)header + currEntry->offset);
            break;
        }
    }

    if (prcd == NULL)
    {
        return -1;
    }

    j = 0;
    currEntry = &entries[i];
    for (; j < currEntry->elementCount; j++)
    {
        if (strcmp(prcd[j].name, name) == 0)
        {
            return j;
        }
    }

    return -1;
}
#endif /* P4_UNIT_0029DE20 */
