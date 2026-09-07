/* Unpromoted: b210 owner profile, 504B/512B, 51 differing words (49 after
 * normalizing two omitted zero-tail words). Seventeen pre-call allocation/
 * selection-use differences and an extra move a0,s1 at offset 352 displace
 * the remaining instructions four bytes. Keep production ASM.
 *
 * Required scratch-owner contracts:
 *   u8 *iGpffffb588;
 *   void func_00104510(s16, s16, s16, s16);
 *   void func_001047b0(s64, s32);
 *   typedef struct NmlistNode NmlistNode;
 *   typedef struct NmlistList NmlistList;
 *   NmlistNode *func_002e2240(NmlistList *, NmlistList *, int *);
 * Existing owner func_002e0dd0 list-call casts must use NmlistList * too.
 * func_002e2240 removes/frees the node, not inserts it. No later node reads.
 * Native32 smoke: 25,600 cases under undefined/function sanitizers, two-slot
 * precedence, failure without writes/calls, descriptor sign boundaries,
 * callback-mutated index/flags/global manager, removal and diagnostic order.
 * Supersedes the old archive's doubled s16-pointer stride, wrong index reload,
 * signed descriptor shift, and incorrectly ruled-out declaration mismatches.
 */
typedef struct FclBankSlot {
    s16 flags;
    s16 unk02;
    u32 descriptor;
    s16 index;
    u8 unk0a[10];
} FclBankSlot;

static inline s16 findUnusedBank(u8 *banks)
{
    s32 i;
    FclBankSlot *slot = (FclBankSlot *)(banks + 4);
    for (i = 0; i < 2; i++) {
        if ((slot->flags & 1) == 0)
            return i;
        slot++;
    }
    return -1;
}

static inline s16 findReusableBank(u8 *banks)
{
    s32 i;
    FclBankSlot *slot = (FclBankSlot *)(banks + 4);
    for (i = 0; i < 2; i++) {
        s16 value = slot->flags;
        if ((value & 1) && !(value & 2) && !(value & 8))
            return i;
        slot++;
    }
    return -1;
}

s16 func_002e1030(int *node)
{
    FclBankSlot *slot;
    s16 selected;
    u8 *banks;
    u8 *payload;

    banks = *(u8 **)(iGpffffb588 + 0x24);
    selected = findUnusedBank(banks);
    if (selected == -1)
        selected = findReusableBank(banks);
    if (selected == -1)
        return -1;
    payload = *(u8 **)((u8 *)node + 0x14);
    slot = (FclBankSlot *)(banks + 4 + selected * 20);
    slot->descriptor = *(u32 *)(payload + 4);
    slot->flags = *(s16 *)payload;
    slot->index = selected;
    func_00104510(selected, (s16)((slot->descriptor & 0xFFFF0000U) >> 16),
                 (s16)((slot->descriptor & 0xFF00) >> 8), (s16)(slot->descriptor & 0xFF));
    func_001047b0(slot->index, 1);
    slot->flags |= 1;
    slot->flags |= 2;
    func_002e2240((NmlistList *)iGpffffb588, (NmlistList *)(iGpffffb588 + 4), node);
    func_00440b68(&iGpffffa890, D_0063FBB0, 0x19D);
    func_002e0ea0((u8 *)D_0063FBC8, slot->index);
    return selected;
}
