#include "include_asm.h"
/* Original translation unit evtEffect.c (from __FILE__ assert strings). */
#include "type.h"
#include "scene_event_internal.h"
#include "evt_effect_internal.h"

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void kAssertFail(u8 *file, s32 line);
extern void evtMemAccount(s32 slot, s32 byteCount);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern void mtMiscClearAllSlotRes(u8 *tableAddress);
extern void (*jtbl_008873EC[])(void *);
extern void memset(void *dest, s32 value, s32 size);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00748340[];
extern u8 D_0063C830[];
extern u8 D_0063C840[];
extern u8 D_0063C870[];
extern u8 iGpffffa7b8;
extern void func_00440b68();
extern s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
extern u8 *H_Cdvd_LookupRequest(u8 *pathAddress, u32 *slot);
extern s32 H_Cdvd_AcquireDirectory(u8 *path, s32 flags);


// Allocates a 0x190-byte effect table with its count cleared and accounts the memory.
// FUN_00290F00
u8 *evtEffectTableCreate(void)
{
    u8 *work;

    chkmemAllocSiteTag(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x190, 0x40000);
    evtMemAccount(0xB, 0x190);
    if (work == 0) {
        kAssertFail(D_0063C830, 0x69);
    }
    memset(work, 0, 0x190);
    ((EvtEffectTable *)work)->state = 0;
    return work;
}

// Frees an effect table: destroys its CD requests, releases its sequence and frees the block.
// FUN_00290FA0
void evtEffectTableDestroy(u8 *table)
{
    s32 i;
    u8 *entryBase;

    if (table != NULL) {
        for (i = 0; i < ((EvtEffectTable *)table)->count; i++) {
            entryBase = table + i * 0x2C;
            if (((EvtEffectEntry *)(entryBase + 0x10))->kind == 1) {
                H_Cdvd_Destroy(((EvtEffectEntry *)(entryBase + 0x10))->request);
            }
        }
        mtMiscClearAllSlotRes(table);
        jtbl_008873EC[0](table);
        evtMemAccount(0xB, -0x190);
    }
}
// Resets an effect sequence record to state 1 with an empty entry count.
// FUN_00291060
void evtEffectSequenceReset(u32 *sequence)
{
    ((EvtEffectTable *)sequence)->state = 1;
    ((EvtEffectTable *)sequence)->nextIndex = 0;

    return;
}

// Effect sequence step: advances loading over each entry, either loading directly or waiting for a
// CD file to load and looking up its request.
// FUN_00291080
s32 evtEffectLoadStep(s32 *sequence)
{
    /* Entry fields are read as raw words because typed member access makes the stack frame larger
     * than retail's. */
    u32 requestSize;
    s32 result;
    s32 index;
    s32 offset;
    s32 kind;
    u8 *record;
    u8 *handle;
    s32 request;

    result = 1;
    if (((EvtEffectTable *)sequence)->state != 1) {
        return result;
    }

    index = ((EvtEffectTable *)sequence)->nextIndex;
    if (index == ((EvtEffectTable *)sequence)->count) {
        sequence[0] = 2;
        return result;
    }

    kind = sequence[index * 11 + 4];
    if (kind == 0) {
        func_00440b68(D_0063C840, index);
        sequence[2] += 1;
    } else if (kind == 1) {
        handle = (u8 *)sequence[3];
        if (handle != NULL) {
            if (H_Cdvd_IsFileLoaded(handle) == 1) {
                offset = index * 11;
                record = (u8 *)(sequence + offset + 5);
                sequence[offset + 13] = (s32)H_Cdvd_LookupRequest(record, &requestSize);
                func_00440b68(D_0063C870, index, record);
                sequence[3] = 0;
                sequence[2] += 1;
            }
        } else {
            func_00440b68(&iGpffffa7b8, D_0063C830, 0xB0);
            offset = index * 11;
            record = (u8 *)(sequence + offset + 5);
            request = (s32)H_Cdvd_AcquireDirectory(record, 0);
            sequence[offset + 14] = request;
            sequence[3] = request;
        }
    }

    result = 0;
    return result;
}
