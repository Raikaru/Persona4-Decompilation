#ifndef SCR_DATA_INTERNAL_H
#define SCR_DATA_INTERNAL_H

#include "type.h"

typedef struct ScrScriptWork ScrScriptWork;

/* The loader and interpreter share this 0x158-byte script work allocation.
 * Union members retain their existing byte-pointer, word, and VM-value views. */
typedef enum
{
    SCR_CONTENT_TYPE_PROCEDURE,
    SCR_CONTENT_TYPE_LABEL,
    SCR_CONTENT_TYPE_INSTR,
    SCR_CONTENT_TYPE_MSG,
    SCR_CONTENT_TYPE_STRINGS,
    SCR_CONTENT_TYPE_MAX
} ScrContentType;

typedef struct ScrContentEntry
{
    u32 contentType;
    u32 unk_04;
    s32 elementCount;
    u32 offset;
} ScrContentEntry;

typedef struct ScrHeader
{
    s32 unk_00;
    u32 scrSize;
    char magic[4];
    u32 unk_0c;
    u32 totalEntries;
    s16 localIntNum;
    s16 localFloatNum;
    s32 unk_18;
    s32 unk_1c;
    ScrContentEntry entries[SCR_CONTENT_TYPE_MAX];
} ScrHeader;

typedef struct ScrLblPrcd
{
    char name[24];
    u32 addr;
    s32 unk_1c;
} ScrLblPrcd;

typedef union ScrValues
{
    s32 iVal;
    f32 fVal;
    char *strVal;
} ScrValues;

typedef union ScrInstruction
{
    struct { s16 opCode, sOperand; } opOperand16;
    s32 iOperand;
    f32 fOperand;
} ScrInstruction;

struct ScrScriptWork
{
    union {
        ScrLblPrcd label;
        struct { char scrName[24]; s32 pc, sp; };
    };
    union { u8 stackTypes[48]; s8 valueTypes[48]; };
    union { u32 stackWords[48]; ScrValues stackValues[48]; };
    union { u8 *header; ScrHeader *scrHeader; };                 /* 0x110 */
    union { u8 *entries; ScrContentEntry *contentEntries; };    /* 0x114 */
    union { u8 *procedure; ScrLblPrcd *proceduresContent; void *procedures; };
    union { u8 *unk_11C; ScrLblPrcd *labelsContent; void *labels; };
    union { u8 *unk_120; ScrInstruction *instrContent; void *instr; };
    union { u8 *unk_124; void *msg; s32 statusCode; };           /* 0x124 */
    union { u8 *unk_128; char *stringsContent; void *strings; };
    s32 index;
    s32 soundHandle;
    union { s32 unk_134; u32 timer; };
    union { s32 unk_138; u32 cmdTimer; };
    u8 *textBuf;
    union { u8 *msgA; s32 *localInt; };
    union { u8 *msgB; f32 *localFloat; };
    union { s32 taskId; void *task; };                          /* 0x148 */
    ScrScriptWork *prev;
    ScrScriptWork *next;
    u8 *proc;
};
typedef char ScrScriptWorkSize[sizeof(ScrScriptWork) == 0x158 ? 1 : -1];

#endif
