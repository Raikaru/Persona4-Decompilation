#ifndef CMM_INTERNAL_H
#define CMM_INTERNAL_H

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

#endif
