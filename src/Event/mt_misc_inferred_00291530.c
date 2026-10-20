#include "byte_address_internal.h"
#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "evt_movie_internal.h"
#include "evt_record_collection_internal.h"
#include "mdl_attachment_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 resourceId);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];

// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern void mdlDetachSlotModel(u8 *eventWork, s32 model, u8 *slotIndex, s32 entryIndex);
extern u32 yTimeTrackAppendKey(s32 eventWork, s32 model, s32 slotIndex, s32 entryIndex,
                          s32 matrixIndex, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 eventWork, f32, f32, f32,
                          f32, s32 model, s32 slotIndex);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memset(void *eventWork, s32 model, s32 slotIndex);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00291530-00291810 */

// Collects up to 10 type-1 entries of the current scene into the slot block:
// ids from 0x7530, fields copied in order, count kept at +0x5D8.
// FUN_00291530
/* measured probe: preserve local constant with opt_propagation off. */
/* measured: func_00291530 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void mtMiscCollectType1Records(u8 *eventWork)
{
    s32 entryCount;
    s32 recordIndex;
    s32 resourceData;
    s32 value;
    s32 type;
    u8 *record;
    u8 *movie;

    ((EvtTypeOneRecords *)(eventWork + 0x5D8))->count = 0;
    movie = ((EvtEventWork *)eventWork)->sceneSource;
    recordIndex = 0;
    type = 1;
    for (; recordIndex < ((EvtPolygonMovieWork *)movie)->count38; recordIndex++) {
        record = ((EvtPolygonMovieWork *)movie)->unk34;
        record = (u8 *)((u32)record + (recordIndex << 5));
        if (((EvtResourceRecord *)record)->kind != type) {
            continue;
        }
        entryCount = ((EvtTypeOneRecords *)(eventWork + 0x5D8))->count;
        if (entryCount >= 10) {
            break;
        }
        resourceData = (s32)((EvtPolygonMovieWork *)movie)->primary + ((EvtResourceRecord *)record)->offset;
        value = ((EvtResourceRecord *)record)->value;
        ((EvtTypeOneRecords *)(eventWork + entryCount * 2 + 0x5D8))->ids[0] =
            (s16)(entryCount + 0x7530);
        ((EvtTypeOneRecords *)(eventWork + entryCount * 4 + 0x5D8))->data[0] = resourceData;
        ((EvtTypeOneRecords *)(eventWork + 0x5D8))->values[entryCount] = value;
        value = ((EvtTypeOneRecords *)(eventWork + 0x5D8))->count;
        ((EvtTypeOneRecords *)(eventWork + 0x5D8))->count = value + 1;
    }
    func_00440b68(D_0063C8F0, ((EvtTypeOneRecords *)(eventWork + 0x5D8))->count);
}

/* measured probe: close opt_propagation bracket after func_00291530. */
// Attach the model for slotIndex from the selected collection entry. Return 0
// when the index is out of range or the matrix copy fails, 1 once attached.
// FUN_002915F0
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
s32 mtMiscAttachSlotModel(u8 *eventWork, u8 *model, s32 slotIndex, s32 entryIndex, s32 matrixIndex)
{
    extern void mdlDetachSlotModel(u8 *model, s32 slotIndex);
    extern s32 mdlCopyIndexedMatrix(u8 *model, s32 index, u8 *destination);
    extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
    extern void mdlAttachSlotModelFromPair(void *eventWork, u16 model, u32 slotIndex, u16 entryIndex, s32 matrixIndex, s32, u32);
    extern void mdlAttachSlotModelFindOrCreate(void *model, u16 slotIndex, u32 type, u16 id, u32 flags);
    extern void mdlSetAttachedSlotValue(u8 *model, u16 slotIndex, s32 frameId);
    s32 flag;
    u32 lookupType;
    u8 *slot;
    u8 *entry;
    u8 work[0x40];

    if (((EvtTypeOneRecords *)(eventWork + 0x5D8))->count <= entryIndex) {
        return 0;
    }
    if (slotIndex >= 3) {
        return 0;
    }
    flag = 0;
    slot = byteAddressAdd(slotIndex * 0xC, model);
    if ((((MdlWpnSlot *)(slot + 0x28C))->flags & 1) &&
        (((MdlWpnSlot *)(slot + 0x28C))->wpnMdl != 0)) {
        flag = 1;
    }
    if (flag == 1) {
        mdlDetachSlotModel(model, slotIndex & 0xFFFF);
    }
    if (mdlCopyIndexedMatrix(model, matrixIndex, work) == 0) {
        return 0;
    }
    entry = byteAddressAdd(entryIndex * 2, eventWork) + 0x604;
    lookupType = 5;
    if (mdlFindModelObject(lookupType, *(u16 *)entry, 0) == 0) {
        u16 weapon;
        u32 idx4;
        u8 *data;
        idx4 = entryIndex * 4;
        weapon = (u16)slotIndex;
        data = (u8 *)(idx4 + (u32)eventWork);
        mdlAttachSlotModelFromPair(model, weapon, 5, *(u16 *)entry, ((EvtTypeOneRecords *)(data + 0x5D8))->data[0], ((EvtTypeOneRecords *)(data + 0x5D8))->values[0], 1);
    } else {
        mdlAttachSlotModelFindOrCreate(model, (u16)slotIndex, 5, *(u16 *)entry, 0);
    }
    mdlSetAttachedSlotValue(model, (u16)slotIndex, matrixIndex);
    return 1;
}

/* measured: restore propagation for the rest of the unit. */
// Detach slotIndex when its attached flag and value are both set; out-of-range
// slots and a null owner are ignored.
// FUN_00291790
void mtMiscDetachSlotModel(u8 *model, s32 slotIndex)
{
    s32 attached;
    u8 *slot;

    if ((slotIndex < 3) && (slotIndex >= 0) && (model != 0)) {
        attached = 0;
        slot = byteAddressAdd(slotIndex * 0xC, model);
        if ((((MdlWpnSlot *)(slot + 0x28C))->flags & 1) &&
            (((MdlWpnSlot *)(slot + 0x28C))->wpnMdl != 0)) {
            attached = 1;
        }
        if (attached == 1) {
            mdlDetachSlotModel(model, slotIndex & 0xFFFF, slot, attached);
        }
    }
}

// Type-2 counterpart of mtMiscCollectType1Records: up to 5 entries, ids from
// 0x7918, collected into the block at +0x640, count reported by a debug print.
// FUN_00291810
/* measured probe: preserve the retail type constant and close bracket below. */
void mtMiscCollectType2Records(u8 *eventWork)
{
    s32 *type2Records;
    s32 entryCount;
    s32 recordIndex;
    s32 resourceData;
    s32 value;
    s32 type;
    u8 *record;
    u8 *movie;

    type2Records = (s32 *)(eventWork + 0x640);
    memset(type2Records, 0, 0x38);
    movie = ((EvtEventWork *)eventWork)->sceneSource;
    recordIndex = 0;
    type = 2;
    for (; recordIndex < ((EvtPolygonMovieWork *)movie)->count38; recordIndex++) {
        record = ((EvtPolygonMovieWork *)movie)->unk34;
        record = (u8 *)((u32)record + (recordIndex << 5));
        if (((EvtResourceRecord *)record)->kind != type) {
            continue;
        }
        entryCount = ((EvtTypeTwoRecords *)type2Records)->count;
        if (entryCount >= 5) {
            break;
        }
        resourceData = (s32)((EvtPolygonMovieWork *)movie)->primary + ((EvtResourceRecord *)record)->offset;
        value = ((EvtResourceRecord *)record)->value;
        ((EvtTypeTwoRecords *)type2Records)->ids[entryCount] =
            (s16)(entryCount + 0x7918);
        ((EvtTypeTwoRecords *)type2Records)->data[entryCount] = resourceData;
        ((EvtTypeTwoRecords *)type2Records)->values[entryCount] = value;
        value = ((EvtTypeTwoRecords *)type2Records)->count;
        ((EvtTypeTwoRecords *)type2Records)->count = value + 1;
    }
    func_00440b68(D_0063C910, ((EvtTypeTwoRecords *)type2Records)->count);
}

