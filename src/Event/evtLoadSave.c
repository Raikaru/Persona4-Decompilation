#include "mt_scene_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Persona 4 USA decompilation - evtLoadSave.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "member_access.h"
#include "scene_event_internal.h"
#include "evt_movie_internal.h"
#include "resrc_manager_internal.h"

typedef struct { s16 a; s16 b; s16 c; s16 d; } S16x4;
typedef struct { f32 x; f32 y; f32 z; f32 pad; } F32x4;
typedef struct { u8 pad[8]; S16x4 coord; F32x4 vec[3]; } StackState;

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
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    EvtChildNode *child = (EvtChildNode *)entry;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
    *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[1];
    coord = &coordThird;
    *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[2];
    coord = &coordFourth;
    *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[3];
    coordinates.a = coordFirst;
    coordinates.b = coordSecond;
    coordinates.c = coordThird;
    coordinates.d = coordFourth;
    *(S16x4 *)&((EvtChildNode *)entry)->unk08 = coordinates;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk00.bytes.first = ((EvtRecordParameters *)payload)->unk00.bytes.first;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk04.word = ((EvtRecordParameters *)payload)->unk04.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk08.word = ((EvtRecordParameters *)payload)->unk08.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk0C.word = ((EvtRecordParameters *)payload)->unk0C.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk10.word = ((EvtRecordParameters *)payload)->unk10.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk14.word = ((EvtRecordParameters *)payload)->unk14.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk18.word = ((EvtRecordParameters *)payload)->unk18.word;
    payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
    ((EvtChildNode *)entry)->recordPayload.unk1C.word = ((EvtRecordParameters *)payload)->unk1C.word;
    parentKind = *(s32 *)&((EvtChildNode *)entry)->kind;
    if (parentKind == 1) {
        ((EvtChildNode *)entry)->recordPayload.unk20.word = 0;
    } else if (parentKind == 0x30) {
        payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
        ((EvtChildNode *)entry)->recordPayload.unk20.word = ((EvtRecordParameters *)payload)->unk20.word;
    }
    sourceKind = ((MtMiscSceneSource *)source)->header->kind;
    if (sourceKind < 0xC) {
        if (child->kind == 1) {
            payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
            ((EvtChildNode *)entry)->recordPayload.unk24.word = ((EvtRecordParameters *)payload)->unk20.word;
        }
    } else {
        payload = evtLoadRecordPayload(source, recordIndex, recordOffset);
        ((EvtChildNode *)entry)->recordPayload.unk24.word = ((EvtRecordParameters *)payload)->unk24.word;
    }
    ((EvtChildNode *)entry)->unk04 = -1;
    switch (child->recordPayload.unk00.bytes.first) {
    case 1:
        switch (child->recordPayload.unk04.bytes.first) {
        case 1:
            blurIndex = ((EvtSceneRecord *)(recordOffset + (s32)(s32)movie->unk98))->value0A;
            evtBlurFilterEnsureBlock(entry);
            if ((s32)((EvtChildNode *)entry)->ownedBlock40 == 0) {
                kAssertFail(D_0063CAB0, 0x726);
            }
            memcpy((u8 *)(child->ownedBlock40), (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk60) + (blurIndex * 0x130)), 0x130);
            break;
        }
        break;
    case 2:
        firstPercent = child->payload.layerChoice.speedPercent;
        if ((firstPercent < 0) || (firstPercent > 0x1F4)) {
            child->payload.layerChoice.speedPercent = 0x64;
        }
        secondPercent = ((EvtChildNode *)entry)->payload.layerChoice.recordSpeedPercent;
        if ((secondPercent < 0) || (secondPercent > 0x1F4)) {
            child->payload.layerChoice.recordSpeedPercent = 0x64;
        }
        break;
    default:
        break;
    }
}

// Intent: Loads each kind-1 record whose count equals recordCount into a new node entry (through evtNodeLoadRecordEntry) [inferred]
// FUN_00294A90
void evtNodeLoadRecordsByCount(u8 *source, u8 *eventWork, u8 *node, u16 recordCount) {
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
                recordKind = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10)))->type;
            } else {
                recordKind = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C)))->type;
            }
            if ((recordKind & 0xFFFF) == 1) {
                recordOffset = i * 0x3C;
                record = (u8 *)((s32)((s32)((EvtPolygonMovieWork *)source)->unk98) + recordOffset);
                if (count == ((EvtSceneRecord *)record)->count08) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + (i * 0x10)))->id;
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
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    EvtEventWork *eventState = (EvtEventWork *)eventWork;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
        ((ResrcRecord *)idx)->slotHandleValue[1] = 0;
        ((EvtEventWork *)eventWork)->cameraResource = MT_Scene_GetRes(resourceId);
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
        ((ResrcRecord *)MT_Scene_GetRes(resourceId))->slotHandleValue[1] = 0;
        evtSetKindExclusiveRes(eventWork, 0);
        cameraResource = eventState->cameraResource;
        if (cameraResource != NULL) {
            dest = (u8 *)evtNodeAllocWithRes(0x21, eventWork, *(u16 *)cameraResource, NULL);
            ((EvtNode *)dest)->unk08 = -1;
            *(EventVector *)&((MtMiscSceneNode *)dest)->unk_38 = *(EventVector *)&stack.vec[2];
            *(EventVector *)&((MtMiscSceneNode *)dest)->unk_44 = *(EventVector *)&stack.vec[0];
            for (idx = 0; idx < ((MtMiscSceneSource *)source)->countAC; idx++) {
                type = ((MtMiscSceneSource *)source)->header->kind;
                if (type == 4) {
                    id = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10)))->type;
                } else {
                    id = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (idx * 0x3C)))->type;
                }
                if ((id & 0xFFFF) == 0x21) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (idx * 0x3C)))->id;
                    }
                    entry = evtNodeCreate(dest, recordId & 0xFFFF, eventWork);
                    off = idx * 0x3C;
                    record = (u8 *)((s32)((EvtPolygonMovieWork *)source)->unk98 + off);
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
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        recordFlags = ((MtMiscSceneRecord16 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + (idx * 0x10)))->unk_04;
                    } else {
                        recordFlags = ((EvtSceneRecord *)((s32)movie->unk98 + off))->unk_04;
                    }
                    ((EvtChildNode *)entry)->unk02 = recordFlags;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk00.word = ((EvtRecordParameters *)payload)->unk00.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk04.word = ((EvtRecordParameters *)payload)->unk04.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk08.word = ((EvtRecordParameters *)payload)->unk08.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk0C.word = ((EvtRecordParameters *)payload)->unk0C.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk10.word = ((EvtRecordParameters *)payload)->unk10.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk14.word = ((EvtRecordParameters *)payload)->unk14.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk18.word = ((EvtRecordParameters *)payload)->unk18.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk1C.word = ((EvtRecordParameters *)payload)->unk1C.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk20.word = ((EvtRecordParameters *)payload)->unk20.word;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (idx * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + off + 0x14);
                    }
                    ((EvtChildNode *)entry)->recordPayload.unk24.word = ((EvtRecordParameters *)payload)->unk24.word;
                }
            }
        }
    }
}

// Intent: Allocates three kind-0x24 slot nodes and loads the kind-0x24 records into them [inferred]
// FUN_002951C0
void evtNodeLoadRecords24(u8 *source, u8 *eventWork) {
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
            id = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10)))->type;
        } else {
            id = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C)))->type;
        }
        if ((id & 0xFFFF) == 0x24) {
            if (type == 4) {
                payloadForSlot = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payloadForSlot = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C) + 0x14);
            }
            idx = (s8)((EvtPayloadKind24 *)payloadForSlot)->unk01;
            if (type == 4) {
                recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C)))->id;
            }
            dest = evtNodeCreate(arr[idx], recordId & 0xFFFF, eventWork);
            recordOffset = i * 0x3C;
            coord = &coordFirst;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[0];
            coord = &coordSecond;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[1];
            coord = &coordThird;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[2];
            coord = &coordFourth;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[3];
            coordinates.a = coordFirst;
            coordinates.b = coordSecond;
            coordinates.c = coordThird;
            coordinates.d = coordFourth;
            *(S16x4 *)&((EvtChildNode *)dest)->unk08 = coordinates;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + (i * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)dest)->recordPayload.unk00.word = ((EvtRecordParameters *)payload)->unk00.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)dest)->recordPayload.unk04.word = ((EvtRecordParameters *)payload)->unk04.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)dest)->recordPayload.unk08.word = ((EvtRecordParameters *)payload)->unk08.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)dest)->recordPayload.unk0C.word = ((EvtRecordParameters *)payload)->unk0C.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)dest)->recordPayload.unk10.word = ((EvtRecordParameters *)payload)->unk10.word;
        }
    }
}

/* measured: address-taken coordinate locals preserve retail's grouped loads and stores; the clamp uses a direct swapped relational guard so b210 emits retail's $at compare. Object 592/592, normalized_diff 0. Committed at nd 0. */
// Intent: Creates a kind-0x2F node, loads its kind-0x2F records and clamps the field at +0x1A to 100 when out of range [inferred]
// FUN_002954F0
void evtNodeLoadRecords2F(u8 *source, u8 *eventWork) {
    EvtChildNode *child;
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
            recordKind = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10)))->type;
        } else {
            recordKind = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (recordIndex * 0x3C)))->type;
        }
        if ((recordKind & 0xFFFF) == 0x2F) {
            if (sourceKind == 4) {
                recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (recordIndex * 0x3C)))->id;
            }
            entry = (u8 *)(evtNodeCreate(node, recordId & 0xFFFF, eventWork));
    child = (EvtChildNode *)entry;
            recordOffset = recordIndex * 0x3C;
            coord = &coordFirst;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[0];
            coord = &coordSecond;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[1];
            coord = &coordThird;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[2];
            coord = &coordFourth;
            *coord = ((EvtSceneRecord *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset))->position[3];
            coordinates.a = coordFirst;
            coordinates.b = coordSecond;
            coordinates.c = coordThird;
            coordinates.d = coordFourth;
            *(S16x4 *)&((EvtChildNode *)entry)->unk08 = coordinates;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payloadWord = (s32 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + (recordIndex * 0x10) + 8);
            } else {
                payloadWord = (s32 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)entry)->recordPayload.unk00.word = ((EvtRecordParameters *)payloadWord)->unk00.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10) + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)entry)->recordPayload.unk04.word = ((EvtRecordParameters *)payload)->unk04.word;
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payloadForClamp = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10) + 8);
            } else {
                payloadForClamp = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            ((EvtChildNode *)entry)->recordPayload.unk08.word = ((EvtRecordParameters *)payloadForClamp)->unk08.word;
            if (child->recordPayload.unk00.bytes.first == 1) {
                if (((EvtChildNode *)entry)->payload.display.speedPercent < 0) {
                    goto clamp_954;
                }
                if (0x1F4 >= ((EvtChildNode *)entry)->payload.display.speedPercent) {
                    goto next_954;
                }
clamp_954:
                child->payload.display.speedPercent = 0x64;
            }
next_954:
            ;
        }
    }
}

// Intent: Creates the entry's model, attaches its owner, creates its NPC shadow resource and copies its colour to the node [inferred]
// FUN_00295740
void evtNodeCreateModel(s32 eventWork, u8 *node) {
    EvtNode *ownerNode = (EvtNode *)node;
    /* measured: typing the remaining node +4 load changes instructions; the flag byte and color copy now use layout members. */
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
            if ((s8)((EvtNode *)node)->pad1F & 1) {
                mdlSetAttachedOwner(model, D_005DC7D0);
            } else {
                mdlSetAttachedOwner(model, D_005DC878);
            }
            resourceId = (u16)(MT_Scene_CreateModelNpcShadowRes((u16)(evtCustomEventResId(((EvtNode *)node)->param04) & 0xFFFF), 0, model) & 0xFFFF);
            MT_Scene_SetResActiveById(resourceId, 1);
            positionOffset = (s32)(ownerNode->param04 * 0x1E);
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
            ((EvtNode *)node)->color = *(EvtColor *)color;
            return;
        }
        evtNodeSetRes(node, 0U, NULL);
    }
}

// Intent: Allocates three kind-0x34 slot nodes and copies the 0x28-byte payload of each kind-0x34 record [inferred]
// FUN_00295B80
void evtNodeLoadRecords34(u8 *source, u8 *eventWork) {
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
            id = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10)))->type;
        } else {
            id = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C)))->type;
        }
        if ((id & 0xFFFF) == 0x34) {
            if (type == 4) {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10) + 8);
            } else {
                payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C) + 0x14);
            }
            if (type == 4) {
                recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (i * 0x10)))->id;
            } else {
                recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (i * 0x3C)))->id;
            }
            idx = (u8)(((EvtPayloadKind34 *)payload)->unk02) >> 4;
            child = evtNodeCreate(arr[idx], recordId & 0xFFFF, eventWork);
            compactOffset = i * 0x10;
            recordOffset = i * 0x3C;
            entry = (u8 *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset);
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
            if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                payload = (u8 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + compactOffset + 8);
            } else {
                payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
            }
            memcpy(child + 0x10, payload, 0x28);
        }
    }
}

// Intent: Allocates eight kind-0x30 slot nodes and loads the kind-0x30 records matching each slot's index, then the table at +0x100 [inferred]
// FUN_00295910
void evtNodeLoadRecords30(u8 *source, u8 *eventWork) {
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    EvtNode *ownerNode;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
    ownerNode = (EvtNode *)node;
        ((EvtNode *)node)->param04 = slotIndex;
        for (recordIndex = 0; recordIndex < ((MtMiscSceneSource *)source)->countAC; recordIndex++) {
            sourceKind = (s32)(((MtMiscSceneSource *)source)->header->kind);
            if (sourceKind == 4) {
                recordKind = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10)))->type;
            } else {
                recordKind = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (recordIndex * 0x3C)))->type;
            }
            if ((recordKind & 0xFFFF) == 0x30) {
                if (sourceKind == 4) {
                    payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10) + 8);
                } else {
                    payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (recordIndex * 0x3C) + 0x14);
                }
                if (ownerNode->param04 == ((EvtRecordParameters *)payload)->unk20.bytes.first) {
                    if (sourceKind == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (recordIndex * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (recordIndex * 0x3C)))->id;
                    }
                    evtNodeLoadRecordEntry(source, evtNodeCreate(node, recordId & 0xFFFF, eventWork), recordIndex);
                }
            }
        }
        if ((s32)((EvtPolygonMovieWork *)source)->unk100 != 0) {
            for (descriptorIndex = 0; descriptorIndex < ((EvtPolygonMovieWork *)source)->count104; descriptorIndex++) {
                off2 = descriptorIndex * 0x14;
                descriptor = (u8 *)((s32)(s32)movie->unk100 + off2);
                if (((EvtNodeDescriptor *)descriptor)->unk02 != -1) {
                    kAssertFail(D_0063CAB0, 0x822);
                    continue;
                }
                if (((s32)((EvtNode *)node)->kind == ((EvtNodeDescriptor *)descriptor)->kind) && (ownerNode->param04 == ((EvtNodeDescriptor *)descriptor)->slot)) {
                    descriptorDest = node + 0x18;
                    wordsLeft = 5;
                    /* Serialized descriptors are copied as five advancing words, including their packed header. */
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
    EvtNode *ownerNode;
    EvtPolygonMovieWork *movie = (EvtPolygonMovieWork *)source;
    /* measured: typed object locals preserve retail reloads; remaining alias-sensitive members use MEMBER. */
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
    ownerNode = (EvtNode *)node;
        ((EvtNode *)node)->param04 = outer;
        for (inner = 0; inner < ((MtMiscSceneSource *)source)->countAC; inner++) {
            type = ((MtMiscSceneSource *)source)->header->kind;
            if (type == 4) {
                id = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10)))->type;
            } else {
                id = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (inner * 0x3C)))->type;
            }
            if ((id & 0xFFFF) == 0xA) {
                if (type == 4) {
                    payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                } else {
                    payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (inner * 0x3C) + 0x14);
                }
                if (outer == ((EvtPayloadKind0A *)payload)->unk08) {
                    if (type == 4) {
                        recordId = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10)))->id;
                    } else {
                        recordId = ((EvtSceneRecord *)(MEMBER(s32, source, EvtPolygonMovieWork, unk98) + (inner * 0x3C)))->id;
                    }
                    child = evtNodeCreate(node, recordId & 0xFFFF, eventWork);
                    recordOffset = inner * 0x3C;
                    record = (u8 *)((s32)((EvtPolygonMovieWork *)source)->unk98 + recordOffset);
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
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payloadFloat = (f32 *)((s32)((EvtPolygonMovieWork *)source)->unk94 + (inner * 0x10) + 8);
                    } else {
                        payloadFloat = (f32 *)((s32)movie->unk98 + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk00 = *payloadFloat;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk04 = ((EvtPayloadKind0A *)payload)->unk04;
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                    } else {
                        payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->payload.kind0A.unk08 = ((EvtPayloadKind0A *)payload)->unk08;
                    type = ((MtMiscSceneHeader *)(s32)movie->secondary)->kind;
                    if (type < 7) {
                        if (type == 4) {
                            payloadHalfwords = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                        } else {
                            payloadHalfwords = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
                        }
                        ((EvtChildNode *)child)->unk02 = ((EvtRecordParameters *)payloadHalfwords)->unk08.halves.second;
                    } else {
                        if (type == 4) {
                            recordFlags = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10)))->unk_04;
                        } else {
                            recordFlags = ((EvtSceneRecord *)((s32)movie->unk98 + recordOffset))->unk_04;
                        }
                        ((EvtChildNode *)child)->unk02 = (s16)recordFlags;
                    }
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        recordValue = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10)))->value06;
                    } else {
                        recordValue = ((EvtSceneRecord *)((s32)movie->unk98 + recordOffset))->value06;
                    }
                    ((EvtChildNode *)child)->unk04 = recordValue;
                    type = ((MtMiscSceneHeader *)(s32)movie->secondary)->kind;
                    if (type < 7) {
                        if (type == 4) {
                            recordFlags = ((MtMiscSceneRecord16 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10)))->unk_04;
                        } else {
                            recordFlags = ((EvtSceneRecord *)((s32)movie->unk98 + recordOffset))->unk_04;
                        }
                        memcpy((u8 *)((EvtChildNode *)child)->ownedBlock48, (u8 *)((s32)((EvtPolygonMovieWork *)source)->unkB8 + ((recordFlags & 0xFFFF) * 0x30)), 0x30);
                    } else {
                        if (type == 4) {
                            payload = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                        } else {
                            payload = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
                        }
                        memcpy((u8 *)((EvtChildNode *)child)->ownedBlock48, (u8 *)((s32)((EvtPolygonMovieWork *)source)->unkB8 + (((EvtRecordParameters *)payload)->unk08.halves.second * 0x30)), 0x30);
                    }
                    if (((MtMiscSceneHeader *)(s32)movie->secondary)->kind == 4) {
                        payloadHalfwords = (u8 *)(MEMBER(s32, source, EvtPolygonMovieWork, unk94) + (inner * 0x10) + 8);
                    } else {
                        payloadHalfwords = (u8 *)((s32)movie->unk98 + recordOffset + 0x14);
                    }
                    ((EvtChildNode *)child)->recordPayload.unk0C.halves.first = ((EvtRecordParameters *)payloadHalfwords)->unk0C.halves.first;
                }
            }
        }
        if ((s32)((EvtPolygonMovieWork *)source)->unk100 != 0) {
            for (recordOffset = 0; recordOffset < ((EvtPolygonMovieWork *)source)->count104; recordOffset++) {
                off2 = recordOffset * 0x14;
                descriptor = (u8 *)(s32 *)movie->unk100;
                descriptor += off2;
                if (((EvtNodeDescriptor *)descriptor)->unk02 != -1) {
                    kAssertFail(D_0063CAB0, 0x822);
                    continue;
                }
                if (((s32)((EvtNode *)node)->kind == ((EvtNodeDescriptor *)descriptor)->kind) &&
                    (ownerNode->param04 == ((EvtNodeDescriptor *)descriptor)->slot)) {
                    descriptorDest = node + 0x18;
                    wordsLeft = 5;
                    /* Serialized descriptors are copied as five advancing words, including their packed header. */
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


