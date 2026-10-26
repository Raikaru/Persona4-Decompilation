#ifndef FCL_BANK_INTERNAL_H
#define FCL_BANK_INTERNAL_H

#include "type.h"

/* Retail bank manager pointer (gp-0x4A78, 0x00764678). */
extern u8 *iGpffffb588;

/* One bank slot: 0x14 bytes, two per record starting at record+4. */
typedef struct FclBankSlot {
    s16 flags;
    s16 state;
    u32 descriptor;
    s16 index;
    u8 unk0a[6];
    s16 fadeTicks;
    u8 unk12[2];
} FclBankSlot;

/* Bank record at manager+0x24: two slots, then the ready word. */
typedef struct FclBankRecord {
    u8 unk00[4];
    FclBankSlot slots[2];
    u32 readyFlags;
} FclBankRecord;

/* Bank manager block at iGpffffb588. */
typedef struct FclBankWork {
    u8 unk00[4];
    void *pendingTail;
    u8 unk08[0x1C];
    FclBankRecord *record;
} FclBankWork;

static inline FclBankWork *fclBankWork(void)
{
    return (FclBankWork *)iGpffffb588;
}

/* Queue compares and stores the packed 32-bit descriptor and returns the
 * appended node. Flags retain their complete incoming register word. The font front-end also evaluates a third
 * key word that the request wrapper does not consume. */
void *fclBankQueueRequest(s32 descriptor, s64 flags);
s64 fclBankTryQueueRequest(s32 descriptor, s64 flags, s64 unusedKey);

#endif
