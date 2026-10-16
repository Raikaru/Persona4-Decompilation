#ifndef CMM_INTERNAL_H
#define CMM_INTERNAL_H
#include "type.h"

/* Bits of the s32 flag word at offset 0 of a community record (cmmCommunity.c).
   REVERSED and BROKEN are evidenced by the p4flow commands CMM_SET_REVERSE (0x3011)
   and CMM_SET_BROKEN (0x3012) and by the cmmCommunitySet{Reverse,Broken}Current
   wrappers in promoted/code1_0027.c. MARKED has no named command yet; its meaning
   is not evidenced, so only the bit value is named. */
enum CmmRecordFlag {
    CMM_RECORD_FLAG_REVERSED = 0x1,
    CMM_RECORD_FLAG_BROKEN = 0x2,
    CMM_RECORD_FLAG_MARKED = 0x4
};

/* One slot of the 21-entry community table at D_00797410. A slot is free when
   id is 0. The counterpart of a community is derived from its id by
   cmmCommunityCounterpart; it is not stored in the record. */
typedef struct CmmCommunityRecord CmmCommunityRecord;
struct CmmCommunityRecord
{
    u32 flags;               /* 0x00. CmmRecordFlag bits */
    u16 id;                  /* 0x04. Community id matched by every table search */
    u16 rank;                /* 0x06. Rank 0 to 10; rank 10 is the maximum */
    u16 points;              /* 0x08. Accumulated points (cmmCommunityAddPoints) */
    u16 reverseProgress;     /* 0x0A. Reverse-progress counter (cmmCommunityTickReverse) */
    u8 unk_0c[0x04];         /* 0x0C */
};

/* Chunk 0 of cmm.bin: one record per community kind. Records start at +8 of the
   chunk and are 100 bytes each. Offsets are from the record pointer returned by
   cmmKindRecord. */
typedef struct CmmKindRecord CmmKindRecord;
struct CmmKindRecord
{
    u8 unk_00[0x04];         /* 0x00 */
    u32 flags;               /* 0x04. Kind flag bits (0x10, 0x20 tested by callers) */
    s8 arcana;               /* 0x08. Arcana byte (cmmCommunityArcana) */
    u8 unk_09[0x03];         /* 0x09 */
    u16 tierBits;            /* 0x0C. Bit (tier - 1) tested by cmmCommunityHasTierBit */
    u16 category;            /* 0x0E. Category id (cmmCommunityCategory) */
    u16 rankThreshold[0x2A]; /* 0x10. Threshold by rank level (indexed by rank * 2) */
};

/* Chunk 24 of cmm.bin: 72-byte item record (cmmItemInfoRecord). Only the scalar
   fields read by cmmItemInfoShow and cmmRecordGetField are typed; the inline text
   strings at +0x0C and +0x22 and the text-slot ids at +0x10, +0x12 and +0x20 are
   still reached by address. */
typedef struct CmmItemInfoRecord CmmItemInfoRecord;
struct CmmItemInfoRecord
{
    u8 unk_00[0x04];         /* 0x00 */
    s32 value;               /* 0x04. Shown as a formatted value by cmmItemInfoShow */
    s8 tableIndexA;          /* 0x08. Index into the first name table, -1 for none */
    s8 valueB;               /* 0x09. Shown as a formatted value */
    s8 tableIndexB;          /* 0x0A. Index into the second name table, -1 for none */
    s8 valueC;               /* 0x0B. Shown as a formatted value */
    u8 unk_0c[0x3C];         /* 0x0C */
};

/* Rank-up work block (cmmRankUp.c): sixteen entries of 0x78 bytes, then the
   caller's argument. The entries are walked by cmmRankUpRunQueue and
   cmmRankUpSetEntryHold. */
enum CmmRankUpEntryFlag {
    CMM_RANKUP_ENTRY_ACTIVE = 0x1,
    CMM_RANKUP_ENTRY_HOLD = 0x2
};

typedef s32 (*CmmRankUpEntryStep)(u8 *work, u8 *entry, u8 *arg);

typedef struct CmmRankUpEntry CmmRankUpEntry;
struct CmmRankUpEntry
{
    u32 flags;               /* 0x00. CmmRankUpEntryFlag bits */
    u8 unk_04[0x04];         /* 0x04 */
    CmmRankUpEntryStep step; /* 0x08. Run each frame; a nonzero return clears ACTIVE */
    u8 unk_0c[0x6C];         /* 0x0C */
};

typedef struct CmmRankUpWork CmmRankUpWork;
struct CmmRankUpWork
{
    CmmRankUpEntry entries[0x10]; /* 0x000 */
    u8 unk_780[0x260];       /* 0x780 */
    u8 *callerArg;           /* 0x9E0. Argument passed to every entry step */
};

#endif
