/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00162120-00162680 */

#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007F16F2[];
extern u8 D_007F16F4[];
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
extern s32 FldRoomIsListed(u16 arg0, u16 arg1);
extern s16 datGetPartyId(s32 arg0);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 arg0);
extern s32 calIsCurrentMonthDay(s32 arg0, s32 arg1, s32 arg2);
extern s32 datGetTimeSlot(void);
extern s32 calGetDayEntryByPhase(s16 arg0, s32 arg1);
extern s32 D_005F1350[];
extern void mdlSetColor(void *arg0, void *arg1);
extern void mdlSetLookAtRequested(void *arg0);
extern void mdlAttachSlotModelFromResource(void *arg0, u16 arg1, u32 arg2, u16 arg3,
                           void *arg4, u32 arg5);
extern void mdlSetAttachedSlotValue(u8 *arg0, u16 arg1, s32 arg2);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00162120
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
// FUN_00162200
void FldPartyModelRelease(s32 arg0) {
    s32 saved_arg0;
    s32 temp_18;
    s32 *temp_17;
    u8 *temp_16;
    u8 *temp_3;
    s32 var_6;

    saved_arg0 = arg0;
    if (*(s32 *)(D_007F16F4 + (arg0 * 8)) != 0) {
        var_6 = 0;
        temp_16 = D_007F16F0 + (arg0 * 8);
        goto loop_test;
loop_body:
        temp_3 = (u8 *)(*(s32 *)(temp_16 + 4) + (var_6 * 0xC));
        *(u8 *)(temp_3 + 0x28C) =
            (u8)(*(u8 *)(temp_3 + 0x28C) | 1);
        var_6 += 1;
loop_test:
        if (var_6 < 5) {
            goto loop_body;
        }
        temp_18 = saved_arg0 * 8;
        temp_17 = (s32 *)(D_007F16F4 + temp_18);
        mdlDestroyModelObject(*temp_17);
        *temp_17 = 0;
        *(s16 *)(temp_16 + 0) = 0;
        *(s16 *)(D_007F16F2 + temp_18) = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001622D0
#pragma opt_loop_invariants on
void FldSlotTablesReset(void) {
    s32 i = 0;
    s32 one = 1;
    s32 stride = 0x750;

    while (i < 4) {
        *(s32 *)(D_007EF9B0 + i * stride + 0x44) = one;
        *(s32 *)(D_007F16F0 + i * 8 + 4) = 0;
        *(s16 *)(D_007F16F0 + i * 8) = 0;
        *(s16 *)(D_007F16F0 + i * 8 + 2) = 0;
        i++;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00162330
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldSlotFindFree(void) {
    u8 *r = NULL;
    s32 i = 0;
    u8 *e;

    while (i < 4) {
        e = D_007EF9B0 + i * 0x750;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00162390
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
#pragma opt_loop_invariants on
u8 *FldObjFindFree(void) {
    u8 *r = NULL;
    s32 i = 0;
    s32 stride = 0x750;
    u8 *e;

    while (i < 0xF) {
        e = D_007E8C00 + i * stride;
        if (*(s32 *)(e + 0x48) == 0) {
            r = e;
            break;
        }
        i++;
    }
    return r;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
// FUN_001623F0
s32 FldDayEventActive(void)
{
    u8 *temp_5;
    s32 temp_3;
    s32 var_17;
    s32 var_16;
    s16 temp_18;
    s32 temp_3_2;
    s32 var_2;
    u8 *temp_4;

    var_17 = 0;
    if (calIsCurrentMonthDay((s16)datGetDateIndex(), 3, 0x14) == 1) {
        return 0;
    }
    var_16 = 0;
    goto loop_test;
loop_body:
    temp_5 = iGpffff9db0;
    if ((*(s32 *)(temp_5 + 0) == temp_3) &&
        (*(s32 *)(temp_5 + 4) == *(s32 *)(temp_4 + 4))) {
        temp_18 = (s16)datGetDateIndex();
        temp_3_2 = (s8)calGetDayEntryByPhase(temp_18, datGetTimeSlot() & 0xFF);
        var_2 = temp_3_2 & 1;
        if ((temp_3_2 < 0) && (var_2 != 0)) {
            var_2 -= 2;
        }
        if (var_2 != 0) {
            var_17 = 1;
            goto done;
        }
    }
    var_16 += 1;
loop_test:
    temp_4 = (u8 *)D_005F1350 + (var_16 * 8);
    temp_3 = *(s32 *)(temp_4 + 0);
    if (temp_3 != -1) {
        goto loop_body;
    }
done:
    return var_17;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00162510
s32 FldRoomIsListed(u16 arg0, u16 arg1)
{
    s32 result;

    result = 0;
    if (arg0 == 0x14) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x15) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x16) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x16) {
        if (arg1 == 2) {
            goto success;
        }
    }
    if (arg0 == 0x17) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x18) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x19) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1A) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1B) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1C) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 == 0x1D) {
        if (arg1 == 1) {
            goto success;
        }
    }
    if (arg0 != 0x1E) {
        goto done;
    }
    if (arg1 != 2) {
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
static inline u8 *fldPartyModelCached(s32 slot, u16 type, u16 id)
{
    if (type == *(u16 *)(D_007F16F0 + slot * 8) && id == *(u16 *)(D_007F16F2 + slot * 8)) {
        return *(u8 **)(D_007F16F4 + slot * 8);
    }
    return NULL;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00162680
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
            if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
                }
                mdlDestroyModelObject(*(u8 **)(D_007F16F4 + slot * 8));
                *(u8 **)(D_007F16F4 + slot * 8) = NULL;
            }
            *(u8 **)(D_007F16F4 + slot * 8) = obj;
            *(u16 *)entry = *(u16 *)(obj + 0xD4);
            *(u16 *)(D_007F16F2 + slot * 8) = *(u16 *)(*(u8 **)(D_007F16F4 + slot * 8) + 0xD6);
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
            if (*(u8 **)(D_007F16F4 + slot * 8) != NULL) {
                s32 j;

                for (j = 0; j < 5; j++) {
                    *(u8 *)(*(u8 **)(entry + 4) + j * 0xC + 0x28C) |= 1;
                }
                mdlDestroyModelObject(*(u8 **)(D_007F16F4 + slot * 8));
                *(u8 **)(D_007F16F4 + slot * 8) = NULL;
            }
            *(u8 **)(D_007F16F4 + slot * 8) = obj;
            *(u16 *)entry = *(u16 *)(obj + 0xD4);
            *(u16 *)(D_007F16F2 + slot * 8) = *(u16 *)(*(u8 **)(D_007F16F4 + slot * 8) + 0xD6);
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
