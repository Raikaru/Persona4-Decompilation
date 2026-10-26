#ifndef BTL_AI_INTERNAL_H
#define BTL_AI_INTERNAL_H

#include "type.h"

/* Command work embedded at BtlAction+0x38. The AI script handlers pass this
 * address to btlAICommandSetActionCode; the procedure lifetime code agrees on
 * the active byte and task slot. Target selection clears the full 0x5C bytes,
 * including the three trailing words; plan parameters occupy +0x3E..+0x43. */
typedef struct BtlAiCommandWork {
    u32 targets[12];        /* 0x00: selected BtlAction addresses */
    u8 procedureActive;    /* 0x30 */
    u8 pad31;
    u16 targetCount;       /* 0x32 */
    u16 kind;              /* 0x34 */
    u16 command;           /* 0x36 */
    u16 skill;             /* 0x38 */
    u8 pad3A[4];
    u16 plan;              /* 0x3E */
    u16 planArgument;      /* 0x40 */
    u16 planArgument2;     /* 0x42: fourth ScriptSetActionParams argument */
    u8 pad44[4];
    u16 overrideCommand;   /* 0x48 */
    u8 overrideEnabled;    /* 0x4A */
    u8 pad4B;
    u32 procedureTask;     /* 0x4C */
    u32 unk50;
    u32 unk54;
    u32 unk58;
} BtlAiCommandWork;

typedef char BtlAiCommandWorkSizeCheck[sizeof(BtlAiCommandWork) == 0x5C ? 1 : -1];
typedef char BtlAiCommandWorkPlanOffsetCheck[(u32)&((BtlAiCommandWork *)0)->plan == 0x3E ? 1 : -1];
typedef char BtlAiCommandWorkTaskOffsetCheck[(u32)&((BtlAiCommandWork *)0)->procedureTask == 0x4C ? 1 : -1];

/* Conditions occupy the high byte; the low 24 bits are their argument.
 * Two 0x14-byte rows follow the AI record's four-byte header. */
typedef struct BtlAiConditionRow {
    u32 conditions[3];
    u8 actions[8];
} BtlAiConditionRow;

/* Five weighted commands per table, eight bytes each. */
typedef struct BtlAiWeightedCommand {
    u8 weight;
    u8 unk01;
    u16 command;
    u32 targetCondition;
} BtlAiWeightedCommand;

typedef struct BtlAiRecord {
    u16 unk00;
    u16 procedure;
    BtlAiConditionRow conditionRows[2];
    BtlAiWeightedCommand commands[3][5]; /* 0x2C; record stride 0xA4 */
} BtlAiRecord;

/* The selection callback receives a wide query word; this predicate consumes
 * its signed low halfword as an affinity index. */
s32 btlAICommandNomalStatusCheck(u8 *action, s64 value);

#endif
