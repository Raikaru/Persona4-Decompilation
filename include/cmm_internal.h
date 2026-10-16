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
    u8 unk_09[0x07];         /* 0x09 */
    u16 rankThreshold[0x2A]; /* 0x10. Threshold by rank level (indexed by rank * 2) */
};

#endif
