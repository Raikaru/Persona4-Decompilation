/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00162120-00162680 */

#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
typedef struct { u16 id; u8 pad2[6]; } FldPartyCacheIdentity;
extern FldPartyCacheIdentity D_007F16F2[];
typedef struct { u8 *model; u8 pad4[4]; } FldPartyCacheModel;
extern FldPartyCacheModel D_007F16F4[];
extern void mdlDestroyModelObject();
extern u8 D_007E8C00[];
extern void memset(void *dst, s32 value, u32 size);
extern s32 iGpffffb2e8;
extern s32 iGpffffb2e4;
extern s32 iGpffffb2e0;
extern u8 D_007E8BE0[];
extern u8 D_007E8BE8[];
extern u8 D_007E8BF8[];
extern u8 D_007E80A0[];
extern u8 D_007E8060[];
extern u8 D_007E8020[];
extern u8 *iGpffff9db0;
extern s32 FldStepIndex();
extern s32 FldDayEventActive();
extern s32 FldRoomIsListed(u16, u16);
extern s16 datGetPartyId(s32);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32);
extern s32 calIsCurrentMonthDay(s32, s32, s32);
extern s32 datGetTimeSlot(void);
extern s32 calGetDayEntryByPhase(s16, s32);
extern s32 D_005F1350[];
extern void mdlSetColor(void *, void *);
extern void mdlSetLookAtRequested(void *);
extern void mdlAttachSlotModelFromResource(void *, u16, u32, u16,
                           void *, u32);
extern void mdlSetAttachedSlotValue(u8 *, u16, s32);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];
/* Four cached party models use an 8-byte (type, id, model) record. */
typedef struct {
    u16 type, id;
    union { u8 *model; s32 modelAddress; };
} FldPartyModelCache;
typedef struct { s32 field, room; } FldDayEventLocation;
/* Party model identity fields and the five 0xC-byte attachment entries read by this unit. */
typedef struct {
    u8 pad0[0xD4];
    u16 type, id;
    u8 padD8[0x1B4];
    struct { u8 flags; u8 pad1[0xB]; } attachments[5];
} FldPartyModelObject;


#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00162120
/* Clear field actor/cache tables and reset their counters; mark both stored indices absent. */
void FldStateTablesClear(void)
{
    memset(D_007F16F0, 0, 0x20);
    memset(D_007EF9B0, 0, 0x1D40);
    memset(D_007E8C00, 0, 0x6DB0);
    iGpffffb2e8 = 0;
    memset(D_007E8BE0, 0, 0x20);
    *(s32 *)D_007E8BE8 = -1;
    *(s32 *)D_007E8BF8 = -1;
    memset(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    iGpffffb2e0 = 0;
    memset(D_007E8060, 0, 0x40);
    memset(D_007E8020, 0, 0x40);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
/* Release one cached party model after marking its five attached slots for removal. */
// FUN_00162200
/* Cache interior aliases retain their own symbols; attachment flags have stride 0xC. */
void FldPartyModelRelease(s32 slot) {
    s32 savedSlot;
    s32 slotOffset;
    s32 *modelSlot;
    u8 *entry;
    u8 *attachment;
    s32 attachmentIndex;

    savedSlot = slot;
    if (((FldPartyCacheModel *)((u8 *)D_007F16F4 + (slot * 8)))->model != 0) {
        attachmentIndex = 0;
        entry = D_007F16F0 + (slot * 8);
        goto loop_test;
loop_body:
        attachment = (u8 *)(((FldPartyModelCache *)entry)->modelAddress + (attachmentIndex * 0xC));
        ((FldPartyModelObject *)(attachment))->attachments[0].flags =
            (u8)(((FldPartyModelObject *)(attachment))->attachments[0].flags | 1);
        attachmentIndex += 1;
loop_test:
        if (attachmentIndex < 5) {
            goto loop_body;
        }
        slotOffset = savedSlot * 8;
        modelSlot = (s32 *)((u8 *)D_007F16F4 + slotOffset);
        mdlDestroyModelObject(*modelSlot);
        *modelSlot = 0;
        ((FldPartyModelCache *)(entry))->type = 0;
        ((FldPartyCacheIdentity *)((u8 *)D_007F16F2 + slotOffset))->id = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Reset the four party actor slots and invalidate their cached model identities. */
// FUN_001622D0
#pragma opt_loop_invariants on
void FldSlotTablesReset(void) {
    s32 i = 0;
    s32 one = 1;
    s32 stride = 0x750;

    while (i < 4) {
        ((FldEventActor *)(D_007EF9B0 + i * stride))->unknown44 = one;
        ((FldPartyModelCache *)(D_007F16F0 + i * 8))->model = 0;
        ((FldPartyModelCache *)(D_007F16F0 + i * 8))->type = 0;
        ((FldPartyModelCache *)(D_007F16F0 + i * 8))->id = 0;
        i++;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Return the first of four party actor slots without a unit, or NULL. */
// FUN_00162330
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldSlotFindFree(void) {
    u8 *result = NULL;
    s32 slotIndex = 0;
    u8 *entry;

    while (slotIndex < 4) {
        entry = D_007EF9B0 + slotIndex * 0x750;
        if (((FldEventActor *)entry)->unit == 0) {
            result = entry;
            break;
        }
        slotIndex++;
    }
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Return the first of fifteen object actor slots without a unit, or NULL. */
// FUN_00162390
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldObjFindFree(void) {
    u8 *result = NULL;
    s32 slotIndex = 0;
    s32 stride = 0x750;
    u8 *entry;

    while (slotIndex < 0xF) {
        entry = D_007E8C00 + slotIndex * stride;
        if (((FldEventActor *)entry)->unit == 0) {
            result = entry;
            break;
        }
        slotIndex++;
    }
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
/* Test the current location against the day-event table and calendar phase, excluding March 20. */
// FUN_001623F0
s32 FldDayEventActive(void)
{
    u8 *fieldState;
    s32 fieldId;
    s32 active;
    s32 entryIndex;
    s16 date;
    s32 phase;
    s32 parity;
    u8 *entry;

    active = 0;
    if (calIsCurrentMonthDay((s16)datGetDateIndex(), 3, 0x14) == 1) {
        return 0;
    }
    entryIndex = 0;
    goto loop_test;
loop_body:
    fieldState = iGpffff9db0;
    if ((((FldDayEventLocation *)fieldState)->field == fieldId) &&
        (((FldDayEventLocation *)fieldState)->room == ((FldDayEventLocation *)entry)->room)) {
        date = (s16)datGetDateIndex();
        phase = (s8)calGetDayEntryByPhase(date, datGetTimeSlot() & 0xFF);
        parity = phase & 1;
        if ((phase < 0) && (parity != 0)) {
            parity -= 2;
        }
        if (parity != 0) {
            active = 1;
            goto done;
        }
    }
    entryIndex += 1;
loop_test:
    entry = (u8 *)D_005F1350 + (entryIndex * 8);
    fieldId = ((FldDayEventLocation *)entry)->field;
    if (fieldId != -1) {
        goto loop_body;
    }
done:
    return active;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
/* Test the explicit field/room list used to choose party model resources. */
// FUN_00162510
s32 FldRoomIsListed(u16 field, u16 room)
{
    s32 result;

    result = 0;
    if (field == 0x14) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x15) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x16) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x16) {
        if (room == 2) {
            goto success;
        }
    }
    if (field == 0x17) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x18) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x19) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x1A) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x1B) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x1C) {
        if (room == 1) {
            goto success;
        }
    }
    if (field == 0x1D) {
        if (room == 1) {
            goto success;
        }
    }
    if (field != 0x1E) {
        goto done;
    }
    if (room != 2) {
        goto done;
    }
success:
    result = 1;
done:
    return result;
}
#pragma pop

/* measured: MATCH (window 1456B). The slot-cache lookup is a static inline
   helper returning the object or NULL; each switch arm keeps its own copy
   of the refresh code with block-local `entry` and loop counter; the
   default arm narrows `member` into a u16. The cache stores a 16-bit
   type key; the constructor takes a separate integer model kind. */
/* Return the model only when both cached identity halfwords match. */
/* Typed interior aliases retain the id/model relocation symbols of the same cache. */
static inline u8 *fldPartyModelCached(s32 slot, u16 type, u16 id)
{
    if (type == ((FldPartyModelCache *)(D_007F16F0 + slot * 8))->type && id == D_007F16F2[slot].id) {
        return D_007F16F4[slot].model;
    }
    return NULL;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
/* Choose the party member model for this field/calendar context, reusing or replacing its cache slot. */
// FUN_00162680
/* The id/model aliases retain their native symbol-relative loads and stores. */
u8 *FldPartyModelGet(u16 field, u16 room, s32 member)
{
    s32 i;
    u8 *obj;
    s32 slot;
    u16 type;
    u32 modelKind;
    u16 id;

    slot = 0;
    id = 0;
    for (i = 0; i < 3; i++) {
        if (member == datGetPartyId(i)) {
            slot = i + 1;
            break;
        }
    }
    switch (member) {
    case 1: {
        u8 *entry;

        if (FldRoomIsListed(field, room) == 1) {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
            case 2:
                id = 0x103;
                break;
            case 1:
            case 3:
                id = 0x102;
                break;
            }
        } else if (field == 0x44 && room == 1) {
            modelKind = type = 9;
            id = 0x100;
        } else if (FldStepIndex() != 0) {
            modelKind = type = 1;
            id = member;
        } else if ((field == 7 && room == 2) || (field == 7 && room == 3)) {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
                id = 0x10B;
                break;
            case 2:
                id = 0x10D;
                break;
            case 1:
                id = 0x10A;
                break;
            case 3:
                id = 0x10C;
                break;
            }
        } else {
            modelKind = type = 9;
            switch (calGetDayWindowFlags((s16)datGetDateIndex())) {
            case 0:
                id = 0x101;
                break;
            case 2:
                id = 0x105;
                break;
            case 1:
                id = 0x100;
                break;
            case 3:
                id = 0x104;
                break;
            }
        }
        obj = fldPartyModelCached(slot, type, id);
        entry = D_007F16F0 + slot * 8;
        if (obj == NULL) {
            obj = mdlFindOrCreateModelObject(modelKind, id, 0);
            if (type == 1) {
                mdlRunSetupCallback(obj);
            } else {
                mdlAttachSlotModelFromResource(obj, 0, 9, 0x163, D_005F13A0, 0);
                mdlSetAttachedSlotValue(obj, 0, 0x1F4);
            }
            if (((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    ((FldPartyModelObject *)((FldPartyModelCache *)entry)->model)->attachments[j].flags |= 1;
                }
                mdlDestroyModelObject(((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model);
                ((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model = NULL;
            }
            ((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model = obj;
            ((FldPartyModelCache *)entry)->type = ((FldPartyModelObject *)obj)->type;
            ((FldPartyCacheIdentity *)((u8 *)D_007F16F2 + slot * 8))->id = ((FldPartyModelObject *)((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model)->id;
        } else {
            mdlSetColor(obj, &iGpffff9f10);
            mdlSetLookAtRequested(obj);
        }
        break;
    }
    default: {
        u16 m = member;
        u8 *entry;

        obj = fldPartyModelCached(slot, 1, m);
        entry = D_007F16F0 + slot * 8;
        if (obj == NULL) {
            obj = mdlFindOrCreateModelObject(1, m, 0);
            mdlRunSetupCallback(obj);
            if (((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    ((FldPartyModelObject *)((FldPartyModelCache *)entry)->model)->attachments[j].flags |= 1;
                }
                mdlDestroyModelObject(((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model);
                ((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model = NULL;
            }
            ((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model = obj;
            ((FldPartyModelCache *)entry)->type = ((FldPartyModelObject *)obj)->type;
            ((FldPartyCacheIdentity *)((u8 *)D_007F16F2 + slot * 8))->id = ((FldPartyModelObject *)((FldPartyCacheModel *)((u8 *)D_007F16F4 + slot * 8))->model)->id;
        } else {
            mdlSetColor(obj, &iGpffff9f10);
            mdlSetLookAtRequested(obj);
        }
        break;
    }
    }
    return obj;
}
#pragma pop
