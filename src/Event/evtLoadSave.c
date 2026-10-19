#include "mt_scene_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Persona 4 USA decompilation - evtLoadSave.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "scene_event_internal.h"

typedef struct { u8 c[4]; } Rgba8;
typedef struct { s16 a; s16 b; s16 c; s16 d; } S16x4;
typedef struct { f32 x; f32 y; f32 z; f32 pad; } F32x4;
typedef struct { u8 pad[8]; S16x4 coord; F32x4 vec[3]; } StackState;

/* Serialized per-kind record payload: readers copy words at +4..+0x24;
   the first byte is a signed operation in command records. Interpretations of
   the remaining words depend on the parent node kind. */
typedef struct EvtRecordPayload {
    union { s32 word; s8 operation; } first;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} EvtRecordPayload;

/* Payload of recordIndex: the 0x10-byte table at +0x94 when the scene header
   kind is 4, otherwise the 0x3C-byte table at +0x98 (recordOffset = recordIndex * 0x3C). */
static inline u8 *evtLoadRecordPayload(u8 *source, s32 recordIndex, s32 recordOffset)
{
    MtMiscSceneSource *src = (MtMiscSceneSource *)source;

    if (src->header->kind == 4) {
        return (u8 *)((u8 *)src->records94 + (recordIndex * 0x10) + 8);
    }
    return (u8 *)((u8 *)src->records98 + recordOffset + 0x14);
}


extern s32 MT_Scene_GetResManager(void);
extern u16 MT_Scene_CreateRes07(u16);
extern void MT_Scene_OffsetPointByRotation(f32 *, f32, f32, f32, f32, f32 *);
extern u8 *evtNodeAllocWithRes(s32, u8 *, u16, u8 *);
extern void evtSetKindExclusiveRes(u8 *, s32);
extern u8 *evtNodeCreate(u8 *, u16, u8 *);
extern void evtNodeLoadRecordEntry(u8 *, u8 *, s32);
extern s32 mtMiscReadSlotValues(s32, s32, s32 *, s32 *);
extern void *mdlCreateModelObjectFromMemory(u32, u16, void *, u32, u32);
extern void mdlSetAttachedOwner(s32, u8 *);
extern s32 evtCustomEventResId(s32);
extern void MT_Scene_SetResActiveById(u16, s32);
extern void kAssertFail(u8 *, s32);
extern void evtNodeSetRes(u8 *, u16, u16 *);
extern u8 *mdlGetColor(s32);
extern u8 *evtNodeAlloc(s32, u8 *);
extern void evtBlurFilterEnsureBlock(u8 *);
extern void memcpy(u8 *, u8 *, s32);
extern u8 D_005DC7D0[];
extern u8 D_005DC878[];
extern u8 D_0063CAB0[];
extern s64 D_0063CAE8[];
extern f32 D_0063CAF0[];

// Intent: Copies recordIndex from the source record table into entry: coordinates, kind and the per-kind fields [inferred]
// FUN_00294610
void evtNodeLoadRecordEntry(u8 *source, u8 *entry, s32 recordIndex) {
    /* measured: typed mutable child fields cache addresses and lose MATCH; retain raw stores and aliasing table reloads. */
    S16x4 coordinates;
    s16 *coord;
    s32 recordOffset;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    s32 sourceKind;
    s32 parentKind;
    s32 blurIndex;
    s32 firstPercent;
    s32 secondPercent;
    u8 *payload;

    recordOffset = recordIndex * 0x3C;
    coord = &coordFirst;
    *coord = ((EvtSceneRecord *)((u32)recordOffset + (u32)(s32)((MtMiscSceneSource *)source)->records98))->position[0];
    coord = &coordSecond;
    *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[1];
    coord = &coordThird;
    *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[2];
    coord = &coordFourth;
    *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[3];
    coordinates.a = coordFirst;
    coordinates.b = coordSecond;
    coordinates.c = coordThird;
    coordinates.d = coordFourth;
    *(S16x4 *)&((EvtChildNode *)entry)->unk08 = coordinates;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s8 *)(entry + 0x10) = ((EvtRecordPayload *)payload)->first.operation;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x14) = ((EvtRecordPayload *)payload)->unk04;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x18) = ((EvtRecordPayload *)payload)->unk08;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x1C) = ((EvtRecordPayload *)payload)->unk0C;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x20) = ((EvtRecordPayload *)payload)->unk10;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x24) = ((EvtRecordPayload *)payload)->unk14;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x28) = ((EvtRecordPayload *)payload)->unk18;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    *(s32 *)(entry + 0x2C) = ((EvtRecordPayload *)payload)->unk1C;
    parentKind = *(s32 *)&((EvtChildNode *)entry)->kind;
    if (parentKind == 1) {
        *(s32 *)(entry + 0x30) = 0;
    } else if (parentKind == 0x30) {
        payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
        *(s32 *)(entry + 0x30) = ((EvtRecordPayload *)payload)->unk20;
    }
    sourceKind = ((MtMiscSceneSource *)source)->header->kind;
    if (sourceKind < 0xC) {
        if (*(s32 *)(entry + 0x38) == 1) {
            payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
            *(s32 *)(entry + 0x34) = ((EvtRecordPayload *)payload)->unk20;
        }
    } else {
        payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
        *(s32 *)(entry + 0x34) = ((EvtRecordPayload *)payload)->unk24;
    }
    *(s32 *)(entry + 4) = -1;
    switch (*(s8 *)(entry + 0x10)) {
    case 1:
        switch (*(s8 *)(entry + 0x14)) {
        case 1:
            blurIndex = *(s16 *)(recordOffset + (s32)*(s32 *)(source + 0x98) + 0xA);
            evtBlurFilterEnsureBlock(entry);
            if (*(s32 *)(entry + 0x40) == 0) {
                kAssertFail(D_0063CAB0, 0x726);
            }
            memcpy((u8 *)(*(s32 *)(entry + 0x40)), (u8 *)(*(s32 *)(source + 0x60) + (blurIndex * 0x130)), 0x130);
            break;
        }
        break;
    case 2:
        firstPercent = *(s16 *)(entry + 0x28);
        if ((firstPercent < 0) || (firstPercent > 0x1F4)) {
            *(s16 *)(entry + 0x28) = 0x64;
        }
        secondPercent = *(s16 *)(entry + 0x2A);
        if ((secondPercent < 0) || (secondPercent > 0x1F4)) {
            *(s16 *)(entry + 0x2A) = 0x64;
        }
        break;
    default:
        break;
    }
}

// Intent: Loads each kind-1 record whose count equals recordCount into a new node entry (through evtNodeLoadRecordEntry) [inferred]
// FUN_00294A90
void evtNodeLoadRecordsByCount(u8 *source, u8 *eventWork, u8 *node, u16 recordCount) {
    /* measured: typing the +0x94/+0x98 source pointers loses MATCH; preserve the raw table loads and packed count read. */
    s32 i;
    s32 type;
    u16 recordKind;
    u16 recordId;
    s32 count;
    s32 recordOffset;
    u8 *record;

    if ((source == NULL) || (node == NULL)) {
        return;
    }
    count = recordCount & 0xFFFF;
    if (count != 0) {
        for (i = 0; i < ((MtMiscSceneSource *)source)->countAC; i++) {
            type = ((MtMiscSceneSource *)source)->header->kind;
            if (type == 4) {
                recordKind = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->type;
            } else {
                recordKind = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (i * 0x3C)))->type;
            }
            if ((recordKind & 0xFFFF) == 1) {
                recordOffset = i * 0x3C;
                record = (u8 *)((s32)(*(s32 *)(source + 0x98)) + recordOffset);
                if (count == *(u16 *)(record + 8)) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)record)->id;
                    }
                    evtNodeLoadRecordEntry(source, evtNodeCreate(node, recordId & 0xFFFF, eventWork), i);
                }
            }
        }
    }
}

/* 1496/1504 bytes; twenty resolved relocations and eight zero alignment bytes.
 * Preserve the source-type reloads after object creation, separate resource
 * ID/pointer lifetimes, and the three-float vector copies. Address-taken angle
 * fields retain retail's constant-load and stack-store ordering. */
// Intent: Builds the camera resources (ids 0x1E58 and 0x1E59) and the kind-0x21 node entries from the record table [inferred]
// FUN_00294BE0
void evtNodeLoadCameraRecords(u8 *source, u8 *eventWork) {
    /* measured: typed source/header reloads and mutable child fields lose MATCH; retain their byte-addressed alias boundaries. */
    typedef struct { f32 x; f32 y; f32 z; } EventVector;
    StackState stack;
    s16 *coord;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    s64 *packedAnglesPtr;
    f32 *angleZPtr;
    s64 packedAngles;
    f32 angleZ;
    u8 *zero;
    s32 clearBytes;
    s32 type;
    s32 idx;
    s32 off;
    u16 resourceId;
    u8 *dest;
    u8 *resource;
    u8 *cameraResource;
    u16 id;
    u16 recordId;
    u16 recordFlags;
    u8 *entry;
    u8 *record;
    u8 *payload;
    zero = (u8 *)&stack.vec[1];
    clearBytes = 0xC;
    if (zero != NULL) {
        do {
            *zero = 0;
            zero++;
            clearBytes--;
        } while (clearBytes != 0);
    }
    packedAnglesPtr = &packedAngles;
    *packedAnglesPtr = D_0063CAE8[0];
    angleZPtr = &angleZ;
    *angleZPtr = D_0063CAF0[0];
    *(s64 *)&stack.vec[0] = packedAngles;
    stack.vec[0].z = angleZ;
    if (MT_Scene_GetResManager() != 0) {
        idx = (s32)MT_Scene_GetRes(0x1E58);
        if (idx == 0) {
            resourceId = MT_Scene_CreateRes07(0x258) & 0xFFFF;
            idx = (s32)MT_Scene_GetRes(resourceId);
        } else {
            resourceId = *(u16 *)idx;
        }
        MT_Scene_SetResPlacement(resourceId, (u8 *)&stack.vec[1], (u8 *)&stack.vec[0]);
        /* Resource +0x144 and owner +0x12C are not exposed by the shared scene layouts. */
        *(s32 *)((u8 *)idx + 0x144) = 0;
        *(u8 **)(eventWork + 0x12C) = MT_Scene_GetRes(resourceId);
        MT_Scene_OffsetPointByRotation(&stack.vec[1].x, 900.0f, 45.0f, 0.0f, 0.0f, &stack.vec[2].x);
        MT_Scene_SetResPlacement(resourceId, (u8 *)&stack.vec[2], (u8 *)&stack.vec[0]);
        resource = (u8 *)MT_Scene_GetRes(0x1E59);
        if (resource == NULL) {
            resourceId = MT_Scene_CreateRes07(0x259) & 0xFFFF;
            MT_Scene_GetRes(resourceId);
        } else {
            resourceId = *(u16 *)resource;
        }
        MT_Scene_SetResPlacement(resourceId, (u8 *)&stack.vec[2], (u8 *)&stack.vec[0]);
        *(s32 *)((u8 *)MT_Scene_GetRes(resourceId) + 0x144) = 0;
        evtSetKindExclusiveRes(eventWork, 0);
        cameraResource = *(u8 **)(eventWork + 0x12C);
        if (cameraResource != NULL) {
            dest = (u8 *)evtNodeAllocWithRes(0x21, eventWork, *(u16 *)cameraResource, NULL);
            ((EvtNode *)dest)->unk08 = -1;
            *(EventVector *)&((MtMiscSceneNode *)dest)->unk_38 = *(EventVector *)&stack.vec[2];
            *(EventVector *)&((MtMiscSceneNode *)dest)->unk_44 = *(EventVector *)&stack.vec[0];
            for (idx = 0; idx < ((MtMiscSceneSource *)source)->countAC; idx++) {
                type = ((MtMiscSceneSource *)source)->header->kind;
                if (type == 4) {
                    id = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (idx * 0x10)))->type;
                } else {
                    id = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (idx * 0x3C)))->type;
                }
                if ((id & 0xFFFF) == 0x21) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (idx * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (idx * 0x3C)))->id;
                    }
                    entry = evtNodeCreate(dest, recordId & 0xFFFF, eventWork);
                    off = idx * 0x3C;
                    record = (u8 *)(*(s32 *)(source + 0x98) + off);
                    coord = &coordFirst;
                    *coord = ((EvtSceneRecord *)(record))->position[0];
                    coord = &coordSecond;
                    *coord = ((EvtSceneRecord *)(record))->position[1];
                    coord = &coordThird;
                    *coord = ((EvtSceneRecord *)(record))->position[2];
                    coord = &coordFourth;
                    *coord = ((EvtSceneRecord *)(record))->position[3];
                    stack.coord.a = coordFirst;
                    stack.coord.b = coordSecond;
                    stack.coord.c = coordThird;
                    stack.coord.d = coordFourth;
                    *(S16x4 *)&((EvtChildNode *)entry)->unk08 = stack.coord;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        recordFlags = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (idx * 0x10)))->unk_04;
                    } else {
                        recordFlags = *(u16 *)(*(s32 *)(source + 0x98) + off + 4);
                    }
                    *(u16 *)(entry + 2) = recordFlags;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x10) = ((EvtRecordPayload *)payload)->first.word;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x14) = ((EvtRecordPayload *)payload)->unk04;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x18) = ((EvtRecordPayload *)payload)->unk08;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x1C) = ((EvtRecordPayload *)payload)->unk0C;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x20) = ((EvtRecordPayload *)payload)->unk10;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x24) = ((EvtRecordPayload *)payload)->unk14;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x28) = ((EvtRecordPayload *)payload)->unk18;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x2C) = ((EvtRecordPayload *)payload)->unk1C;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x30) = ((EvtRecordPayload *)payload)->unk20;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + off + 0x14);
                    }
                    *(s32 *)(entry + 0x34) = ((EvtRecordPayload *)payload)->unk24;
                }
            }
        }
    }
}

// Intent: Allocates three kind-0x24 slot nodes and loads the kind-0x24 records into them [inferred]
// FUN_002951C0
void evtNodeLoadRecords24(u8 *source, u8 *eventWork) {
    /* measured: typed source/header reloads and mutable payload stores lose MATCH; retain these raw accesses. */
    u8 *arr[3];
    S16x4 coordinates;
    s16 *coord;
    s32 i;
    s32 type;
    s32 idx;
    u16 id;
    u16 recordId;
    s32 recordOffset;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    u8 *payloadForSlot;
    u8 *dest;
    u8 *payload;

    for (i = 0; i < 3; i++) {
        arr[i] = evtNodeAlloc(0x24, eventWork);
        ((EvtNode *)arr[i])->unk08 = -1;
        *(s32 *)&((EvtNode *)arr[i])->res = 0;
        ((EvtNode *)arr[i])->param04 = i;
    }
    for (i = 0; i < ((MtMiscSceneSource *)source)->countAC; i++) {
        type = ((MtMiscSceneSource *)source)->header->kind;
        if (type == 4) {
            id = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->type;
        } else {
            id = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (i * 0x3C)))->type;
        }
        if ((id & 0xFFFF) == 0x24) {
            if (type == 4) {
                payloadForSlot = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payloadForSlot = (u8 *)(*(s32 *)(source + 0x98) + (i * 0x3C) + 0x14);
            }
            idx = (s8)((EvtPayloadKind24 *)payloadForSlot)->unk01;
            if (type == 4) {
                recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (i * 0x3C)))->id;
            }
            dest = evtNodeCreate(arr[idx], recordId & 0xFFFF, eventWork);
            recordOffset = i * 0x3C;
            coord = &coordFirst;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[0];
            coord = &coordSecond;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[1];
            coord = &coordThird;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[2];
            coord = &coordFourth;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[3];
            coordinates.a = coordFirst;
            coordinates.b = coordSecond;
            coordinates.c = coordThird;
            coordinates.d = coordFourth;
            *(S16x4 *)&((EvtChildNode *)dest)->unk08 = coordinates;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(dest + 0x10) = ((EvtRecordPayload *)payload)->first.word;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(dest + 0x14) = ((EvtRecordPayload *)payload)->unk04;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(dest + 0x18) = ((EvtRecordPayload *)payload)->unk08;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(dest + 0x1C) = ((EvtRecordPayload *)payload)->unk0C;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(dest + 0x20) = ((EvtRecordPayload *)payload)->unk10;
        }
    }
}

/* measured: address-taken coordinate locals preserve retail's grouped loads and stores; the clamp uses a direct swapped relational guard so b210 emits retail's $at compare. Object 592/592, normalized_diff 0. Committed at nd 0. */
// Intent: Creates a kind-0x2F node, loads its kind-0x2F records and clamps the field at +0x1A to 100 when out of range [inferred]
// FUN_002954F0
void evtNodeLoadRecords2F(u8 *source, u8 *eventWork) {
    /* measured: typed source/header reloads and payload stores lose MATCH; retain raw accesses, including the overlapping clamp halfword. */
    u8 *node;
    S16x4 coordinates;
    s16 *coord;
    s32 recordOffset;
    s32 recordIndex;
    s32 sourceKind;
    u16 recordId;
    u16 recordKind;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    u8 *entry;
    u8 *payloadForClamp;
    s32 *payloadWord;
    u8 *payload;
    node = (u8 *)(evtNodeAlloc(0x2F, eventWork));
    for (recordIndex = 0; recordIndex < ((MtMiscSceneSource *)source)->countAC; recordIndex++) {
        sourceKind = (s32)(((MtMiscSceneSource *)source)->header->kind);
        if (sourceKind == 4) {
            recordKind = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10)))->type;
        } else {
            recordKind = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (recordIndex * 0x3C)))->type;
        }
        if ((recordKind & 0xFFFF) == 0x2F) {
            if (sourceKind == 4) {
                recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (recordIndex * 0x3C)))->id;
            }
            entry = (u8 *)(evtNodeCreate(node, recordId & 0xFFFF, eventWork));
            recordOffset = recordIndex * 0x3C;
            coord = &coordFirst;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[0];
            coord = &coordSecond;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[1];
            coord = &coordThird;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[2];
            coord = &coordFourth;
            *coord = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + recordOffset))->position[3];
            coordinates.a = coordFirst;
            coordinates.b = coordSecond;
            coordinates.c = coordThird;
            coordinates.d = coordFourth;
            *(S16x4 *)&((EvtChildNode *)entry)->unk08 = coordinates;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payloadWord = (s32 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10) + 8);
            } else {
                payloadWord = (s32 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(entry + 0x10) = ((EvtRecordPayload *)payloadWord)->first.word;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(entry + 0x14) = ((EvtRecordPayload *)payload)->unk04;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payloadForClamp = (u8 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10) + 8);
            } else {
                payloadForClamp = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            *(s32 *)(entry + 0x18) = ((EvtRecordPayload *)payloadForClamp)->unk08;
            if (*(s8 *)(entry + 0x10) == 1) {
                if (*(s16 *)(entry + 0x1A) < 0) {
                    goto clamp_954;
                }
                if (0x1F4 >= *(s16 *)(entry + 0x1A)) {
                    goto next_954;
                }
clamp_954:
                *(s16 *)(entry + 0x1A) = 0x64;
            }
next_954:
            ;
        }
    }
}

// Intent: Creates the entry's model, attaches its owner, creates its NPC shadow resource and copies its colour to the node [inferred]
// FUN_00295740
void evtNodeCreateModel(s32 eventWork, u8 *node) {
    /* measured: typed node argument loads across model calls lose MATCH; +0x1F remains an unnamed flag byte in the shared layout. */
    s32 modelId;
    u32 modelSize;
    struct {
        f32 x;
        s32 y;
        f32 z;
    } position;
    s32 model;
    s32 modelData;
    s32 positionOffset;
    s8 slot;
    u16 *resource;
    u16 resourceId;
    u8 *color;

    slot = (s8)node[0x1E];
    if (slot >= 0) {
        modelData = mtMiscReadSlotValues(eventWork, slot, (s32 *)&modelSize, (s32 *)&modelId);
        if (modelData != 0) {
            model = (s32)mdlCreateModelObjectFromMemory(5, (u16)modelId, (void *)modelData, modelSize, 1);
            if (*(s8 *)(node + 0x1F) & 1) {
                mdlSetAttachedOwner(model, D_005DC7D0);
            } else {
                mdlSetAttachedOwner(model, D_005DC878);
            }
            resourceId = (u16)(MT_Scene_CreateModelNpcShadowRes((u16)(evtCustomEventResId(*(s32 *)(node + 4)) & 0xFFFF), 0, model) & 0xFFFF);
            MT_Scene_SetResActiveById(resourceId, 1);
            positionOffset = (s32)(*(s32 *)(node + 4) * 0x1E);
            position.x = (f32)positionOffset;
            position.y = 0;
            position.z = (f32)-positionOffset;
            MT_Scene_SetResPlacement(resourceId, (u8 *)&position, 0);
            resource = (u16 *)(MT_Scene_GetRes(resourceId));
            if (resource == NULL) {
                kAssertFail(D_0063CAB0, 0x9C5);
            }
            evtNodeSetRes(node, resourceId, resource);
            color = (u8 *)(mdlGetColor(model));
            *(Rgba8 *)&((EvtNode *)node)->color = *(Rgba8 *)(color);
            return;
        }
        evtNodeSetRes(node, 0U, NULL);
    }
}

// Intent: Allocates three kind-0x34 slot nodes and copies the 0x28-byte payload of each kind-0x34 record [inferred]
// FUN_00295B80
void evtNodeLoadRecords34(u8 *source, u8 *eventWork) {
    /* measured: typed source/header reloads lose MATCH; keep them raw while using typed row and coordinate fields. */
    u8 *arr[3];
    S16x4 coordinates;
    s32 i;
    s32 type;
    u16 id;
    u8 *entry;
    u8 *payload;
    u16 recordId;
    u8 *child;
    s32 compactOffset;
    s32 recordOffset;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    s16 *q;
    s32 idx;

    for (i = 0; i < 3; i++) {
        arr[i] = evtNodeAlloc(0x34, eventWork);
        ((EvtNode *)arr[i])->unk08 = -1;
        *(s32 *)&((EvtNode *)arr[i])->res = 0;
        ((EvtNode *)arr[i])->param04 = i;
    }
    for (i = 0; i < ((MtMiscSceneSource *)source)->countAC; i++) {
        type = ((MtMiscSceneSource *)source)->header->kind;
        if (type == 4) {
            id = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->type;
        } else {
            id = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (i * 0x3C)))->type;
        }
        if ((id & 0xFFFF) == 0x34) {
            if (type == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + (i * 0x3C) + 0x14);
            }
            if (type == 4) {
                recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (i * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (i * 0x3C)))->id;
            }
            idx = (u8)(((EvtPayloadKind34 *)payload)->unk02) >> 4;
            child = evtNodeCreate(arr[idx], recordId & 0xFFFF, eventWork);
            compactOffset = i * 0x10;
            recordOffset = i * 0x3C;
            entry = (u8 *)(*(s32 *)(source + 0x98) + recordOffset);
            q = &coordFirst;
            *q = ((EvtSceneRecord *)entry)->position[0];
            q = &coordSecond;
            *q = ((EvtSceneRecord *)entry)->position[1];
            q = &coordThird;
            *q = ((EvtSceneRecord *)entry)->position[2];
            q = &coordFourth;
            *q = ((EvtSceneRecord *)entry)->position[3];
            coordinates.a = coordFirst;
            coordinates.b = coordSecond;
            coordinates.c = coordThird;
            coordinates.d = coordFourth;
            *(S16x4 *)&((EvtChildNode *)child)->unk08 = coordinates;
            if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                payload = (u8 *)(*(s32 *)(source + 0x94) + compactOffset + 8);
            } else {
                payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
            }
            memcpy(child + 0x10, payload, 0x28);
        }
    }
}

// Intent: Allocates eight kind-0x30 slot nodes and loads the kind-0x30 records matching each slot's index, then the table at +0x100 [inferred]
// FUN_00295910
void evtNodeLoadRecords30(u8 *source, u8 *eventWork) {
    /* measured: typed source pointers/node fields lose MATCH; the raw five-word descriptor copy preserves its advancing cursors. */
    u8 *node;
    u8 *descriptor;
    u8 *descriptorDest;
    s32 sourceKind;
    s32 descriptorWord;
    s32 recordIndex;
    s32 slotIndex;
    s32 descriptorIndex;
    s32 off2;
    s32 wordsLeft;
    u16 recordId;
    u16 recordKind;
    u8 *payload;

    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        node = (u8 *)(evtNodeAlloc(0x30, eventWork));
        *(s32 *)(node + 4) = slotIndex;
        for (recordIndex = 0; recordIndex < ((MtMiscSceneSource *)source)->countAC; recordIndex++) {
            sourceKind = (s32)(((MtMiscSceneSource *)source)->header->kind);
            if (sourceKind == 4) {
                recordKind = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10)))->type;
            } else {
                recordKind = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (recordIndex * 0x3C)))->type;
            }
            if ((recordKind & 0xFFFF) == 0x30) {
                if (sourceKind == 4) {
                    payload = (u8 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10) + 8);
                } else {
                    payload = (u8 *)(*(s32 *)(source + 0x98) + (recordIndex * 0x3C) + 0x14);
                }
                if (*(s32 *)(node + 4) == *(s8 *)(payload + 0x20)) {
                    if (sourceKind == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (recordIndex * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (recordIndex * 0x3C)))->id;
                    }
                    evtNodeLoadRecordEntry(source, evtNodeCreate(node, recordId & 0xFFFF, eventWork), recordIndex);
                }
            }
        }
        if (*(s32 *)(source + 0x100) != 0) {
            for (descriptorIndex = 0; descriptorIndex < *(s32 *)(source + 0x104); descriptorIndex++) {
                off2 = descriptorIndex * 0x14;
                descriptor = (u8 *)((s32)*(s32 *)(source + 0x100) + off2);
                if (*(s16 *)(descriptor + 2) != -1) {
                    kAssertFail(D_0063CAB0, 0x822);
                    continue;
                }
                if ((*(s32 *)(node + 0) == *(u8 *)(descriptor + 0)) && (*(s32 *)(node + 4) == *(u8 *)(descriptor + 1))) {
                    descriptorDest = node + 0x18;
                    wordsLeft = 5;
                    do {
                        descriptorWord = *(s32 *)descriptor;
                        descriptor += 4;
                        wordsLeft -= 1;
                        *(s32 *)descriptorDest = descriptorWord;
                        descriptorDest += 4;
                    } while (wordsLeft > 0);
                    break;
                }
            }
        }
        evtNodeCreateModel((s32)eventWork, node);
    }
}

/* measured: the plain-C reconstruction of the three outer tag-0xA objects,
   nested source dispatch, coordinate copy, and descriptor search matches
   retail (object 1336B against the 1344B retail window). */
// Intent: Allocates three kind-0xA nodes and loads the kind-0xA records matching each node's index [inferred]
// FUN_00295DB0
void evtNodeLoadRecords0A(u8 *source, u8 *eventWork) {
    /* measured: typed source/header reloads and node fields lose MATCH; retain their aliasing and the five-word descriptor copy. */
    S16x4 coordinates;
    s16 *coord;
    s16 coordFirst;
    s16 coordSecond;
    s16 coordThird;
    s16 coordFourth;
    s16 recordValue;
    u8 *node;
    u8 *descriptor;
    u8 *descriptorDest;
    s32 inner;
    s32 outer;
    s32 type;
    s32 recordOffset;
    s32 off2;
    u16 id;
    u16 recordId;
    u16 recordFlags;
    u8 *child;
    u8 *payload;
    u8 *record;
    u8 *payloadHalfwords;
    f32 *payloadFloat;
    s32 wordsLeft;
    s32 descriptorWord;
    for (outer = 0; outer < 3; outer++) {
        node = evtNodeAlloc(0xA, eventWork);
        *(s32 *)(node + 4) = outer;
        for (inner = 0; inner < ((MtMiscSceneSource *)source)->countAC; inner++) {
            type = ((MtMiscSceneSource *)source)->header->kind;
            if (type == 4) {
                id = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (inner * 0x10)))->type;
            } else {
                id = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (inner * 0x3C)))->type;
            }
            if ((id & 0xFFFF) == 0xA) {
                if (type == 4) {
                    payload = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                } else {
                    payload = (u8 *)(*(s32 *)(source + 0x98) + (inner * 0x3C) + 0x14);
                }
                if (outer == ((EvtPayloadKind0A *)payload)->unk08) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (inner * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(*(s32 *)(source + 0x98) + (inner * 0x3C)))->id;
                    }
                    child = evtNodeCreate(node, recordId & 0xFFFF, eventWork);
                    recordOffset = inner * 0x3C;
                    record = (u8 *)(*(s32 *)(source + 0x98) + recordOffset);
                    coord = &coordFirst;
                    *coord = ((EvtSceneRecord *)(record))->position[0];
                    coord = &coordSecond;
                    *coord = ((EvtSceneRecord *)(record))->position[1];
                    coord = &coordThird;
                    *coord = ((EvtSceneRecord *)(record))->position[2];
                    coord = &coordFourth;
                    *coord = ((EvtSceneRecord *)(record))->position[3];
                    coordinates.a = coordFirst;
                    coordinates.b = coordSecond;
                    coordinates.c = coordThird;
                    coordinates.d = coordFourth;
                    *(S16x4 *)&((EvtChildNode *)child)->unk08 = coordinates;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payloadFloat = (f32 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                    } else {
                        payloadFloat = (f32 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk00 = *payloadFloat;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk04 = ((EvtPayloadKind0A *)payload)->unk04;
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payload = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                    } else {
                        payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk08 = ((EvtPayloadKind0A *)payload)->unk08;
                    type = *(s32 *)(*(s32 *)(source + 0x80) + 0x14);
                    if (type < 7) {
                        if (type == 4) {
                            payloadHalfwords = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                        } else {
                            payloadHalfwords = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                        }
                        *(s16 *)(child + 2) = *(s16 *)(payloadHalfwords + 0xA);
                    } else {
                        if (type == 4) {
                            recordFlags = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (inner * 0x10)))->unk_04;
                        } else {
                            recordFlags = *(u16 *)(*(s32 *)(source + 0x98) + recordOffset + 4);
                        }
                        *(s16 *)(child + 2) = (s16)recordFlags;
                    }
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        recordValue = *(s16 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 6);
                    } else {
                        recordValue = *(s16 *)(*(s32 *)(source + 0x98) + recordOffset + 6);
                    }
                    ((EvtChildNode *)child)->unk04 = recordValue;
                    type = *(s32 *)(*(s32 *)(source + 0x80) + 0x14);
                    if (type < 7) {
                        if (type == 4) {
                            recordFlags = ((MtMiscSceneRecord16 *)(*(s32 *)(source + 0x94) + (inner * 0x10)))->unk_04;
                        } else {
                            recordFlags = *(u16 *)(*(s32 *)(source + 0x98) + recordOffset + 4);
                        }
                        memcpy((u8 *)((EvtChildNode *)child)->ownedBlock48, (u8 *)(*(s32 *)(source + 0xB8) + ((recordFlags & 0xFFFF) * 0x30)), 0x30);
                    } else {
                        if (type == 4) {
                            payload = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                        } else {
                            payload = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                        }
                        memcpy((u8 *)((EvtChildNode *)child)->ownedBlock48, (u8 *)(*(s32 *)(source + 0xB8) + (*(s16 *)(payload + 0xA) * 0x30)), 0x30);
                    }
                    if (*(s32 *)(*(s32 *)(source + 0x80) + 0x14) == 4) {
                        payloadHalfwords = (u8 *)(*(s32 *)(source + 0x94) + (inner * 0x10) + 8);
                    } else {
                        payloadHalfwords = (u8 *)(*(s32 *)(source + 0x98) + recordOffset + 0x14);
                    }
                    *(s16 *)(child + 0x1C) = *(s16 *)(payloadHalfwords + 0xC);
                }
            }
        }
        if (*(s32 *)(source + 0x100) != 0) {
            for (recordOffset = 0; recordOffset < *(s32 *)(source + 0x104); recordOffset++) {
                off2 = recordOffset * 0x14;
                descriptor = (u8 *)*(s32 **)(source + 0x100);
                descriptor += off2;
                if (*(s16 *)(descriptor + 2) != -1) {
                    kAssertFail(D_0063CAB0, 0x822);
                    continue;
                }
                if ((*(s32 *)(node + 0) == *(u8 *)(descriptor + 0)) &&
                    (*(s32 *)(node + 4) == *(u8 *)(descriptor + 1))) {
                    descriptorDest = node + 0x18;
                    wordsLeft = 5;
                    do {
                        descriptorWord = *(s32 *)descriptor;
                        descriptor += 4;
                        wordsLeft--;
                        *(s32 *)descriptorDest = descriptorWord;
                        descriptorDest += 4;
                    } while (wordsLeft > 0);
                    break;
                }
            }
        }
    }
}


