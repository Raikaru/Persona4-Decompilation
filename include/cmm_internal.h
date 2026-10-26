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
    u8 reverseRankLimit;     /* 0x09. Compared against the community rank */
    u16 reverseThreshold;    /* 0x0A. Reverse-progress threshold; zero disables it */
    u16 tierBits;            /* 0x0C. Bit (tier - 1) tested by cmmCommunityHasTierBit */
    u16 category;            /* 0x0E. Category id (cmmCommunityCategory) */
    union {
        u16 rankThreshold[0x2A]; /* 0x10. Points needed for each rank level */
        struct {
            u8 pad10[0x14];
            struct {
                u32 gate;
                union { u32 word; s8 value; } result;
            } eventSlots[8]; /* 0x24. Optional flag gate and event value */
        };
    };
};

/* Earn-scale table: chunk 14 of cmm.bin, returned by cmmEarnScaleTable (chunk +8).
   arcanaMul applies when the roster has the arcana. eventBit and each slot flagBit
   gate their multiplier on a game-flag bit; a zero flagBit means no gate. */
typedef struct CmmEarnScaleSlot CmmEarnScaleSlot;
struct CmmEarnScaleSlot
{
    s32 flagBit;             /* 0x00 */
    f32 mul;                 /* 0x04 */
};

typedef struct CmmEarnScale CmmEarnScale;
struct CmmEarnScale
{
    f32 arcanaMul;           /* 0x00 */
    s32 eventBit;            /* 0x04 */
    f32 eventMul;            /* 0x08 */
    CmmEarnScaleSlot slot[3]; /* 0x0C, stride 8 */
};

CmmEarnScale *cmmEarnScaleTable(void);

/* Chunk 24 of cmm.bin: 72-byte item record (cmmItemInfoRecord). Only the scalar
   fields read by cmmItemInfoShow and cmmRecordGetField are typed; the inline text
   strings at +0x0C and +0x22 and the text-slot ids at +0x10, +0x12 and +0x20 are
   still reached by address. */
typedef struct CmmItemInfoRecord CmmItemInfoRecord;
struct CmmItemInfoRecord
{
    union {
        u8 unk_00[0x04];     /* 0x00: retained byte representation */
        s32 unk00Word;      /* script field selector 3 reads the whole prefix */
    };
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
    s32 frame;              /* 0x04. Per-entry animation timer */
    CmmRankUpEntryStep step; /* 0x08. Run each frame; a nonzero return clears ACTIVE */
    union {
        u8 unk_0c[0x6C];     /* 0x0C */
        s32 spriteKind;      /* first RankUpSpriteState.kind for sprite steps */
    };
};

typedef struct CmmRankUpWork CmmRankUpWork;
struct CmmRankUpWork
{
    CmmRankUpEntry entries[0x10]; /* 0x000 */
    u8 unk_780[0x260];       /* 0x780 */
    u8 *callerArg;           /* 0x9E0. Argument passed to every entry step */
};
/* Card-task work block (0x40 bytes, cmmRankUp.c). cmmRankUpCardTaskUpdate
   (comuTimerSequence_inferred_002519e0.c) allocates it; cmmRankUpCreate stores
   it as CmmRankUpWork.callerArg and the step and draw callbacks read it. Only
   the offsets below are read by those callbacks. [inferred] */
typedef struct CmmRankUpCardTask CmmRankUpCardTask;
struct CmmRankUpCardTask
{
    u32 flags;               /* 0x00 */
    s32 relation;            /* 0x04. Relation id for the panel */
    s32 mode;                /* 0x08. Display mode; 0xA is the maximum-rank panel */
    s32 unk_0c;              /* 0x0C */
    union {
        u8 *sprites;         /* 0x10. Sprite pack (sdkSpritePackCreate); freed by the card-task destroy */
        s32 counter;         /* renderer frame counter */
    } slot10;                /* 0x10 */
    s32 unk_14;              /* 0x14. Portrait-related value (datPortraitValue input) */
    union {
        u16 communityId;     /* 0x18. Community id (cmmCommunityArcana) */
        s32 word;            /* 0x18. Portrait task handle is also stored here by cmmRankUpCardTaskUpdate [inferred] */
    } slot18;                /* 0x18 */
    u8 unk_1c[0x20];         /* 0x1C. Rank-up work handle (cmmRankUpCreate) at 0x1C */
    union {
        s16 ticks;           /* 0x3C. Frame timer that wraps at 120 */
        s8 low;              /* 0x3C. Low byte, passed as a label argument */
    } pulse120;              /* 0x3C */
    s16 pulse45;             /* 0x3E. Frame timer that wraps at 45 */
};

/* Rank-up sequence work block (0x5C bytes, cmmRankUp.c). cmmRankUpSequenceStart
   allocates it and cmmRankUpRender and cmmRankUpSequenceUpdate read it. The
   0x00-0x3F prefix matches CmmRankUpCardTask; the renderer also reads the
   sequence-only fields below. [inferred] */
typedef struct CmmRankUpSequence CmmRankUpSequence;
struct CmmRankUpSequence
{
    u32 flags;               /* 0x00. Bit 0x10 tested by the renderer */
    s32 relation;            /* 0x04. Relation id for the panel */
    s32 mode;                /* 0x08. Display mode; 0xA is the maximum-rank panel */
    s32 unk_0c;              /* 0x0C */
    union {
        u8 *sprites;         /* sprite table passed to shdSpriteDraw* */
        s32 counter;         /* renderer frame counter */
    } slot10;                /* 0x10 */
    s32 unk_14;              /* 0x14. Portrait-related value (datPortraitValue input) */
    union {
        u16 communityId;     /* 0x18. Community id (cmmCommunityArcana) */
        s32 word;
    } slot18;                /* 0x18 */
    s32 animationMode;       /* 0x1C. Rank; selects the renderer branch */
    s32 unk_20;              /* 0x20. Resource id for cmmRankUpAttachResMatrix */
    s32 cardTask;            /* 0x24. Rank-up card child task */
    s32 blurTask;            /* 0x28. Temporary scene blur task */
    s32 portraitIdFirst;     /* 0x2C. Portrait id for the first texture */
    s32 portraitIdSecond;    /* 0x30. Portrait id for the second texture */
    u8 *directory;          /* 0x34. CDVD directory request */
    s32 messageData;        /* 0x38. Message archive entry */
    union {
        s16 ticks;           /* 0x3C. Frame timer that wraps at 120 */
        s8 low;              /* 0x3C. Low byte, passed as a label argument */
    } pulse120;              /* 0x3C */
    s16 pulse45;             /* 0x3E. Frame timer that wraps at 45 */
    s32 unk_40;              /* 0x40 */
    s32 unk_44;              /* 0x44. Complete flag */
    s32 frame45;             /* 0x48. Frame counter that wraps at 45 */
    s32 fadeFrame;          /* 0x4C. Fade ramp, from 0 to 40 */
    u8 *loadRequest;        /* 0x50. Asynchronous resource load request */
    s32 *unk_54;             /* 0x54. Pointer to the portrait value word (renderer reads through it) */
    u8 *unk_58;              /* 0x58. Cast to a palette row (RankUpColor) by the renderer */
};

/* Test the date table using the seed word supplied by the script command. */
s32 cmmDateTableHasEntry(s32 seed);

#endif
