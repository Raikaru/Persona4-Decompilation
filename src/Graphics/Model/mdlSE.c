/* Original translation unit mdlSE.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "type.h"
#include "mdl_file_internal.h"
#include "h_cdvd_request_internal.h"

/* The allocator reserves 0x28 bytes; the shared file-object prefix is
 * followed by two asynchronous requests. */
typedef struct MdlSeRecord {
    union {
        MdlFileObject base;
        struct { u8 pad00[0x0E]; s16 id; } identity;
    };
    union {
        struct {
            void *primaryRequest;
            void *secondaryRequest;
        };
        void *requests[2];
    };
    u8 unk1C[0x0C];
} MdlSeRecord;
typedef struct MdlSeCell {
    s8 variants[4];
    s32 flags;
    s16 slotId;
    s16 unk0A;
} MdlSeCell;
typedef struct MdlSeSlot {
    union { s32 signedTick; u32 tick; };
    u16 type;
    u16 id;
} MdlSeSlot;
typedef struct MdlSeBankHeader {
    u8 unk00[0xFC];
    s32 size;
} MdlSeBankHeader;
/* Interior aliases start at the type/id halfword of an eight-byte slot. */
typedef struct MdlSeSlotIdentifier {
    u16 value;
    u8 pad02[6];
} MdlSeSlotIdentifier;

extern void chkmemAllocSiteTag();
extern void memset(void *dest, s32 value, s32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007241D8;
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern s32 iGpffffbb40;
extern u8 D_00922C10[];
extern MdlSeSlotIdentifier D_00922C14[];
extern MdlSeSlotIdentifier D_00922C16[];
extern void memcpy(void *dst, const void *src, u32 size);
extern s32 sdkSndQueueSlotRequest(s32 slotIndex, void *input, u32 inputSize, void *intermediate, u32 intermediateSize, void *output, u32 outputSize);
extern s32 H_Cdvd_IsFileLoaded(void *cdvd);
extern void H_Cdvd_Destroy(void *cdvd);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern s32 hsndSlotIsStarting(s16 slotIndex);
extern u32 RpRandom(void);
extern s32 mdlSeAcquireSlot(u32 type, u16 id);


/* Allocates a 40-byte sound record with references set to 1 and the type, id and kind filled in. */
// FUN_0047DEA0
void *mdlSeCreateRecord(u32 type, u16 id, s32 kind)
{
    void *record;

    chkmemAllocSiteTag(&D_007241D8, 0x2B);
    record = jtbl_008873E8[0](0x28, 0x40000);
    memset(record, 0, 0x28);
    ((MdlSeRecord *)record)->base.references = 1;
    ((MdlSeRecord *)record)->base.type = type;
    ((MdlSeRecord *)record)->identity.id = id;
    ((MdlSeRecord *)record)->base.mode = kind;
    return record;
}

/* Acquires one of three sound slots for (type, id): reuses a slot already holding it, else takes
 * the first slot whose model is not loaded, else evicts the slot with the smallest tick. Returns
 * slot + 3. measured: CSE off keeps the repeated slot addresses and index masks; propagation off
 * keeps the shared sentinel and separate eviction-loop lifetimes. */
// FUN_0047DF40
#pragma push
/* measured: retail recomputes slot addresses and index masks and keeps the eviction-loop values
 * separate. */
#pragma opt_common_subs off
#pragma opt_propagation off
s32 mdlSeAcquireSlot(u32 type, u16 id)
{
    s32 selectedSlot;
    s32 scanIndex;
    u32 slotType;
    s32 slotIndex;
    u32 minimumTick;
    u8* slot;
    s32 byteOffset;
    u32 requestedType;
    u32 requestedId;

    selectedSlot = -1;
    scanIndex = 0;
    requestedType = type & 0xFFFF;
    requestedId = id & 0xFFFF;
    for (; (slotIndex = scanIndex & 0xFFFF) < 3U; scanIndex = (scanIndex + 1) & 0xFFFF)
    {
        slot = (u8*)D_00922C10 + (u16)scanIndex * 8;
        slotType = ((MdlSeSlot *)slot)->type;
        if ((requestedType == slotType) && (requestedId == ((MdlSeSlot *)slot)->id))
        {
            selectedSlot = slotIndex;
            break;
        }
        else if (((s32)slotType < 0xC) &&
                 (mdlFindModelObject(slotType, ((MdlSeSlot *)((u8*)D_00922C10 + (u16)scanIndex * 8))->id, 0) == 0))
        {
            selectedSlot = slotIndex;
            break;
        }
    }
    /* All ones is both the unselected-slot sentinel and the initial unsigned minimum. */
    minimumTick = 0xFFFFFFFFU;
    if ((u32)selectedSlot == minimumTick)
    {
        u32 evictionSlot;
        s32 evictionIndex = 0;
        slot = (u8*)D_00922C10;
        for (; (evictionSlot = evictionIndex & 0xFFFF) < 3; evictionIndex = (evictionIndex + 1) & 0xFFFF)
        {
            u32 tick = ((MdlSeSlot *)(slot + ((evictionIndex & 0xFFFF) * 8)))->tick;
            if (tick <= minimumTick)
            {
                minimumTick = tick;
                selectedSlot = evictionSlot;
            }
        }
    }
    byteOffset = selectedSlot * 8;
    iGpffffbb40 = (u32)iGpffffbb40 + 1;
    ((MdlSeSlot *)((s32)D_00922C10 + byteOffset))->signedTick = iGpffffbb40;
    /* The type and id are written through D_00922C14 and D_00922C16, which point into the slot
     * table at D_00922C10. */
    ((MdlSeSlotIdentifier *)((s32)D_00922C14 + byteOffset))->value = type;
    ((MdlSeSlotIdentifier *)((s32)D_00922C16 + byteOffset))->value = id;
    return selectedSlot + 3;
}
#pragma pop

/* Fills the playback state of one sound entry from its 12-byte (column, row) cell: returns 0 for
 * out-of-range or empty cells, otherwise 1 after writing the mode, selected variant, value and
 * packed flags. func_003b7060 is the no-argument RNG. */
// FUN_0047E0F0
/* measured: retail hoists loop-invariant cell addressing out of the variant scan. */
#pragma opt_loop_invariants on
s32 mdlSeFillEntryState(u8 *state, s32 column, s32 rowIndex, u16 baseSlot)
{
    s16 row;
    u32 colOffL;
    s16 col;
    u8 *entry;
    s16 slotId;
    s16 slotValue;
    s32 writeIndex;
    s32 scanIndex;
    s32 variantIndex;
    s8 variant;
    s8 firstVariant;
    s8 emptyVariant;
    s32 count;
    u16 kind;
    s16 mode;
    s32 flags;
    u8 *owner;
    s8 variants[4];
    MdlSeCell *cell;

    row = (s16)rowIndex;
    if (row >= 0x1B) {
        return 0;
    }
    col = (s16)column;
    if (col >= 8) {
        return 0;
    }
    entry = (u8 *)((col * 3) * 4);
    entry = *(u8 **)&((MdlMotionState *)state)->request + (row * 3) * 32 + (u32)entry;
    cell = (MdlSeCell *)entry;
    slotId = ((MdlSeCell *)entry)->slotId;
    if (slotId == -1) {
        return 0;
    }
    slotValue = (col == 0) ? (s16)(slotId + (baseSlot & 0xFFFF))
                     : (s16)(slotId - ((MdlSeCell *)entry)[-1].slotId);
    firstVariant = -1;
    emptyVariant = -1;
    writeIndex = 0;
    scanIndex = 0;
    while ((variantIndex = scanIndex & 0xFFFF) < 3) {
        variant = ((MdlSeCell *)entry)->variants[variantIndex];
        if (variant != emptyVariant) {
            variants[writeIndex & 0xFFFF] = variant;
            if (firstVariant == emptyVariant) {
                firstVariant = variants[writeIndex & 0xFFFF];
            }
            writeIndex = (writeIndex + 1) & 0xFFFF;
        }
        scanIndex = (scanIndex + 1) & 0xFFFF;
    }
    count = writeIndex & 0xFFFF;
    if (count > 0) {
        kind = ((MdlFileObject *)*(u8 **)state)->type;
        mode = (kind == 1) ? 2 : 3;
        ((MdlMotionState *)state)->channel = mode;
        ((MdlMotionState *)state)->waitTicks = slotValue;
        if ((((MdlMotionState *)state)->flags & 0x40) == 0 || firstVariant == emptyVariant) {
            ((MdlMotionState *)state)->streamFlags = variants[(u32)RpRandom() % (u32)count];
        } else {
            ((MdlMotionState *)state)->streamFlags = firstVariant;
        }
        ((MdlMotionState *)state)->requestValue = **(s32 **)state;
    }
    flags = cell->flags;
    if (flags != -1) {
        owner = *(u8 **)state;
        if (((MdlFileObject *)owner)->type == 1) {
            ((MdlMotionState *)state)->pendingSlot = ((flags & 0x20000000) != 0) ^ 1;
            ((MdlMotionState *)state)->pendingChannel = 11;
            ((MdlMotionState *)state)->pendingTicks = slotValue;
            ((MdlMotionState *)state)->pendingFlags = (cell->flags >> 16) & 0xFFF;
            ((MdlMotionState *)state)->pendingKind = cell->flags;
        } else {
            if ((flags & 0x20000000) != 0) {
                ((MdlMotionState *)state)->pendingSlot = 0;
            } else if ((flags & 0x40000000) != 0) {
                ((MdlMotionState *)state)->pendingSlot = 1;
            } else if ((flags & 0x10000000) != 0) {
                ((MdlMotionState *)state)->pendingSlot = ((MdlFileObject *)owner)->slot;
            }
            switch (((MdlFileObject *)*(u8 **)state)->slot) {
            case 3:
                ((MdlMotionState *)state)->pendingChannel = 1;
                break;
            case 4:
                ((MdlMotionState *)state)->pendingChannel = 2;
                break;
            case 5:
                ((MdlMotionState *)state)->pendingChannel = 3;
                break;
            }
            ((MdlMotionState *)state)->pendingTicks = slotValue;
            ((MdlMotionState *)state)->pendingFlags = (cell->flags >> 16) & 0xFFF;
            ((MdlMotionState *)state)->pendingKind = cell->flags;
        }
    } else if (col == 0) {
        ((MdlMotionState *)state)->pendingTicks = -2;
    }
    ((MdlMotionState *)state)->animation = rowIndex;
    return 1;
}

#pragma opt_loop_invariants off


/* Reports that no sound is loaded for (type, id); the retail body is a constant zero. */
// FUN_0047E440
s32 mdlSeIsLoaded(u32 type, u16 id) {
    return 0;
}


/* Starts loading a sound record into owner: mode 1 copies one payload into a fresh buffer; mode 2
 * splits the payload into three header-prefixed chunks and hands them to the stream player. The
 * record advance is a signed (size + 0x3F) / 64 64, not hand-written shifts. */
// FUN_0047E450
void mdlSeRequestLoad(void **owner, u32 type, u16 id, s32 source, u32 size)
{
    s32 sourceBase = source;
    void ** recordOwner = owner;
    s32 chunkSize;
    u8 bankHeader[0x100];
    void *chunks[3];
    u32 chunkSizes[3];
    void *currentRecord;
    void *record;
    void *payload;
    void *streamingRecord;
    void *copiedRecord;
    void *readyRecord;
    void *queuedRecord;
    void *pendingRecord;
    void *existingRecord;
    s32 kind;
    s32 chunkStart;
    s32 chunkIndex;
    s32 sourceAddress;

    sourceAddress = sourceBase;
    existingRecord = *owner;
    if ((existingRecord == NULL) || ((((MdlSeRecord *)existingRecord)->base.flags & 1) == 0)) {
        kind = (u16)type;
        switch (kind) {
        case 1:
            if (existingRecord == NULL) {
                chkmemAllocSiteTag(&D_007241D8, 0x2B);
                record = jtbl_008873E8[0](0x28, 0x40000);
                memset(record, 0, 0x28);
                ((MdlSeRecord *)record)->base.references = 1;
                ((MdlSeRecord *)record)->base.type = (s16)type;
                ((MdlSeRecord *)record)->identity.id = (s16)id;
                ((MdlSeRecord *)record)->base.mode = 1;
                *owner = record;
            }
            currentRecord = *recordOwner;
            chkmemAllocSiteTag(&D_007241D8, 0x49);
            payload = jtbl_008873E8[0](size, 0x40000);
            ((MdlSeRecord *)currentRecord)->base.data = payload;
            memcpy(payload, (void *)sourceAddress, size);
            copiedRecord = *recordOwner;
            ((MdlSeRecord *)copiedRecord)->base.flags &= 0xFFFD;
            readyRecord = *recordOwner;
            ((MdlSeRecord *)readyRecord)->base.flags |= 1;
            return;
        case 2:
            if (existingRecord == NULL) {
                chkmemAllocSiteTag(&D_007241D8, 0x2B);
                streamingRecord = jtbl_008873E8[0](0x28, 0x40000);
                memset(streamingRecord, 0, 0x28);
                ((MdlSeRecord *)streamingRecord)->base.references = 1;
                ((MdlSeRecord *)streamingRecord)->base.type = (s16)type;
                ((MdlSeRecord *)streamingRecord)->identity.id = (s16)id;
                ((MdlSeRecord *)streamingRecord)->base.mode = 2;
                *owner = streamingRecord;
            }
            *(s32 *)&((MdlSeRecord *)*recordOwner)->primaryRequest = 0;
            ((MdlSeRecord *)*recordOwner)->base.slot = mdlSeAcquireSlot(type, id);
            chunkIndex = 0;
            while (chunkIndex < 3) {
                memcpy(bankHeader, (void *)sourceAddress, 0x100);
                chunkStart = sourceAddress + 0x100;
                chunks[chunkIndex] = (void *)chunkStart;
                chunkSize = ((MdlSeBankHeader *)bankHeader)->size;
                chunkSizes[chunkIndex] = chunkSize;
                sourceAddress = chunkStart + ((chunkSize + 0x3F) / 64) * 64;
                chunkIndex += 1;
            }
            sdkSndQueueSlotRequest((s16)((MdlSeRecord *)*owner)->base.slot, chunks[0], chunkSizes[0], chunks[1], chunkSizes[1], chunks[2], chunkSizes[2]);
            queuedRecord = *recordOwner;
            ((MdlSeRecord *)queuedRecord)->base.flags |= 8;
            pendingRecord = *recordOwner;
            ((MdlSeRecord *)pendingRecord)->base.flags |= 2;
            break;
        }
    }
}


/* measured: inlining the shared copy keeps its locals separate from the callback, matching retail
 * register allocation; bank sizes stay unsigned for argument-load order. Copy a completed
 * asynchronous request into newly allocated sound-record storage. */
static inline void mdlSeCopyLoadedRequest(void **owner, s32 requestIndex)
{
    void *node;
    void *request;
    void *source;
    void *memory;
    u32 fileSize;

    node = *owner;
    /* Copy either of the record's two completed asynchronous requests. */
    request = ((MdlSeRecord *)node)->requests[requestIndex];
    fileSize = ((HCdvdRequest *)request)->size;
    source = ((HCdvdRequest *)request)->data;
    chkmemAllocSiteTag(&D_007241D8, 0x49);
    memory = jtbl_008873E8[0](fileSize, 0x40000);
    *(void **)node = memory;
    memcpy(memory, source, fileSize);
}

/* Per-frame poll for a sound record: returns 1 when the record is finished (loaded, copied or nothing pending) and 0 while a request is still pending. */
// FUN_0047E6F0
s32 mdlSeUpdateRecord(void **owner)
{
    void *current;
    void *request;
    void *record0;
    void *record1;
    void *record2;
    u32 size0;
    u32 size1;
    u32 size2;
    u16 flags;
    u16 mode;

    current = *owner;
    if (current == NULL) {
        return 1;
    }
    flags = ((MdlSeRecord *)current)->base.flags;
    if ((flags & 1) != 0) {
        return 1;
    }
    if ((flags & 2) == 0) {
        return 1;
    }
    mode = ((MdlSeRecord *)current)->base.type;
    switch (mode) {
    case 1:
        if (H_Cdvd_IsFileLoaded(((MdlSeRecord *)current)->primaryRequest) != 0) {
            mdlSeCopyLoadedRequest(owner, 0);
            request = ((MdlSeRecord *)*owner)->primaryRequest;
            if (request != NULL) {
                H_Cdvd_Destroy(request);
                ((MdlSeRecord *)*owner)->primaryRequest = NULL;
            }
            ((MdlSeRecord *)*owner)->base.flags |= 1;
            ((MdlSeRecord *)*owner)->base.flags &= 0xFFFD;
            return 1;
        }
        break;
    case 2:
        request = ((MdlSeRecord *)current)->secondaryRequest;
        if (request != NULL) {
            if (H_Cdvd_IsFileLoaded(request) == 0) {
                return 0;
            }
            mdlSeCopyLoadedRequest(owner, 1);
            H_Cdvd_Destroy(((MdlSeRecord *)*owner)->secondaryRequest);
            ((MdlSeRecord *)*owner)->secondaryRequest = NULL;
        }
        current = *owner;
        if ((((MdlSeRecord *)current)->base.flags & 8) == 0) {
            if (H_Cdvd_IsFileLoaded(((MdlSeRecord *)current)->primaryRequest) == 0) {
                return 0;
            }
            record0 = (void *)H_Cdvd_GetArchiveEntry(((MdlSeRecord *)*owner)->primaryRequest, 0, (s32 *)&size0);
            record1 = (void *)H_Cdvd_GetArchiveEntry(((MdlSeRecord *)*owner)->primaryRequest, 1, (s32 *)&size1);
            record2 = (void *)H_Cdvd_GetArchiveEntry(((MdlSeRecord *)*owner)->primaryRequest, 2, (s32 *)&size2);
            sdkSndQueueSlotRequest(*(s16 *)&((MdlSeRecord *)*owner)->base.slot, record0, size0, record1, size1, record2, size2);
            ((MdlSeRecord *)*owner)->base.flags |= 8;
            break;
        }
        if (hsndSlotIsStarting(*(s16 *)&((MdlSeRecord *)current)->base.slot) == 0) {
            return 0;
        }
        request = ((MdlSeRecord *)*owner)->primaryRequest;
        if (request != NULL) {
            H_Cdvd_Destroy(request);
            ((MdlSeRecord *)*owner)->primaryRequest = NULL;
        }
        ((MdlSeRecord *)*owner)->base.flags |= 1;
        ((MdlSeRecord *)*owner)->base.flags &= 0xFFFD;
        ((MdlSeRecord *)*owner)->base.flags |= 4;
        ((MdlSeRecord *)*owner)->base.flags &= 0xFFF7;
        return 1;
    default:
        return 1;
    }
    return 0;
}
