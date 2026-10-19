#include "h_cdvd_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern void mdlDetachSlotModel(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern void memset(void *arg0, s32 arg1, s32 arg2);
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
void mtMiscCollectType1Records(u8 *arg0)
{
    s32 var_6;
    s32 var_9;
    s32 temp_2;
    s32 temp_6;
    s32 type;
    u8 *temp_4;
    u8 *temp_8;

    *(s32 *)(arg0 + 0x5D8) = 0;
    temp_8 = *(u8 **)(arg0 + 4);
    var_9 = 0;
    type = 1;
    goto loop_test_91530;
loop_body_91530:
    temp_4 = *(u8 **)(temp_8 + 0x34);
    temp_4 = (u8 *)((u32)temp_4 + (var_9 << 5));
    if (*(s32 *)(temp_4 + 0x18) != type) {
        goto block_4_91530;
    }
    var_6 = *(s32 *)(arg0 + 0x5D8);
    if (var_6 >= 10) {
        goto done_91530;
    }
    temp_2 = *(s32 *)(temp_8 + 0x10) + *(s32 *)(temp_4 + 0x10);
    temp_6 = *(s32 *)(temp_4 + 0x14);
    *(s16 *)(arg0 + var_6 * 2 + 0x604) =
        (s16)(var_6 + 0x7530);
    *(s32 *)(arg0 + var_6 * 4 + 0x5DC) = temp_2;
    *(s32 *)(arg0 + var_6 * 4 + 0x618) = temp_6;
    temp_6 = *(s32 *)(arg0 + 0x5D8);
    *(s32 *)(arg0 + 0x5D8) = temp_6 + 1;
block_4_91530:
    var_9++;
loop_test_91530:
    if (var_9 < *(s32 *)(temp_8 + 0x38)) {
        goto loop_body_91530;
    }
done_91530:
    func_00440b68(D_0063C8F0, *(s32 *)(arg0 + 0x5D8));
}

/* measured probe: close opt_propagation bracket after func_00291530. */
// Attaches the model for slot arg2 from the table entry at index arg3. Returns 0
// when the index is out of range or the matrix copy fails, 1 once attached.
// FUN_002915F0
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
s32 mtMiscAttachSlotModel(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    extern void mdlDetachSlotModel(u8 *arg0, s32 arg1);
    extern s32 mdlCopyIndexedMatrix(u8 *arg0, s32 arg1, u8 *arg2);
    extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
    extern void mdlAttachSlotModelFromPair(void *arg0, u16 arg1, u32 arg2, u16 arg3, s32 arg4, s32 arg5, u32 arg6);
    extern void mdlAttachSlotModelFindOrCreate(void *arg0, u16 arg1, u32 arg2, u16 arg3, u32 arg4);
    extern void mdlSetAttachedSlotValue(u8 *arg0, u16 arg1, s32 arg2);
    s32 flag;
    u32 lookupType;
    u8 *slot;
    u8 *entry;
    u8 work[0x40];

    if (*(s32 *)(arg0 + 0x5D8) <= arg3) {
        return 0;
    }
    if (arg2 >= 3) {
        return 0;
    }
    flag = 0;
    slot = code29AddOff(arg2 * 0xC, arg1);
    if ((*(u8 *)(slot + 0x28C) & 1) &&
        (*(s32 *)(slot + 0x290) != 0)) {
        flag = 1;
    }
    if (flag == 1) {
        mdlDetachSlotModel(arg1, arg2 & 0xFFFF);
    }
    if (mdlCopyIndexedMatrix(arg1, arg4, work) == 0) {
        return 0;
    }
    entry = code29AddOff(arg3 * 2, arg0) + 0x604;
    lookupType = 5;
    if (mdlFindModelObject(lookupType, *(u16 *)entry, 0) == 0) {
        u16 weapon;
        u32 idx4;
        u8 *data;
        idx4 = arg3 * 4;
        weapon = (u16)arg2;
        data = (u8 *)(idx4 + (u32)arg0);
        mdlAttachSlotModelFromPair(arg1, weapon, 5, *(u16 *)entry, *(s32 *)(data + 0x5DC), *(s32 *)(data + 0x618), 1);
    } else {
        mdlAttachSlotModelFindOrCreate(arg1, (u16)arg2, 5, *(u16 *)entry, 0);
    }
    mdlSetAttachedSlotValue(arg1, (u16)arg2, arg4);
    return 1;
}

/* measured: restore propagation for the rest of the unit. */
// Detaches slot arg1 when its attached flag and value are both set; out-of-range
// slots and a null owner are ignored.
// FUN_00291790
void mtMiscDetachSlotModel(u8 *arg0, s32 arg1)
{
    s32 var_7;
    u8 *temp_6;

    if ((arg1 < 3) && (arg1 >= 0) && (arg0 != 0)) {
        var_7 = 0;
        temp_6 = code29AddOff(arg1 * 0xC, arg0);
        if ((*(u8 *)(temp_6 + 0x28C) & 1) &&
            (*(s32 *)(temp_6 + 0x290) != 0)) {
            var_7 = 1;
        }
        if (var_7 == 1) {
            mdlDetachSlotModel(arg0, arg1 & 0xFFFF, temp_6, var_7);
        }
    }
}

// Type-2 counterpart of mtMiscCollectType1Records: up to 5 entries, ids from
// 0x7918, collected into the block at +0x640, count reported by a debug print.
// FUN_00291810
/* measured probe: preserve the retail type constant and close bracket below. */
void mtMiscCollectType2Records(u8 *arg0)
{
    s32 *temp_16;
    s32 var_6;
    s32 var_9;
    s32 temp_2;
    s32 temp_6;
    s32 type;
    u8 *temp_4;
    u8 *temp_8;

    temp_16 = (s32 *)(arg0 + 0x640);
    memset(temp_16, 0, 0x38);
    temp_8 = *(u8 **)(arg0 + 4);
    var_9 = 0;
    type = 2;
    goto loop_test_91810;
loop_body_91810:
    temp_4 = *(u8 **)(temp_8 + 0x34);
    temp_4 = (u8 *)((u32)temp_4 + (var_9 << 5));
    if (*(s32 *)(temp_4 + 0x18) != type) {
        goto block_4_91810;
    }
    var_6 = *(s32 *)temp_16;
    if (var_6 >= 5) {
        goto done_91810;
    }
    temp_2 = *(s32 *)(temp_8 + 0x10) + *(s32 *)(temp_4 + 0x10);
    temp_6 = *(s32 *)(temp_4 + 0x14);
    *(s16 *)((u8 *)temp_16 + var_6 * 2 + 0x18) =
        (s16)(var_6 + 0x7918);
    *(s32 *)((u8 *)temp_16 + var_6 * 4 + 4) = temp_2;
    *(s32 *)((u8 *)temp_16 + var_6 * 4 + 0x24) = temp_6;
    temp_6 = *(s32 *)temp_16;
    *(s32 *)temp_16 = temp_6 + 1;
block_4_91810:
    var_9++;
loop_test_91810:
    if (var_9 < *(s32 *)(temp_8 + 0x38)) {
        goto loop_body_91810;
    }
done_91810:
    func_00440b68(D_0063C910, *(s32 *)temp_16);
}

