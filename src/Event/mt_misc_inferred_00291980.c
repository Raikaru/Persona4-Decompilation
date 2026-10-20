#include "byte_address_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
#include "evt_record_collection_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32);


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
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32, f32, f32, f32,
                          f32, s32, s32);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00291980-00291980 */

extern void mtMiscCollectType1Records(u8 *);
extern void mtMiscCollectType2Records(u8 *);
/* measured probe: preserve local constant with opt_propagation off. */
/* measured probe: close opt_propagation bracket after func_00291530. */
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
/* measured: restore propagation for the rest of the unit. */
/* measured probe: preserve the retail type constant and close bracket below. */
/* measured probe: close opt_propagation bracket after func_00291810. */
// Read slotIndex (0-4): write its flag word and resource id through
// the pointers and returns its value field (+0x644). Out-of-range slots return 0.
// FUN_00291980
s32 mtMiscReadSlotValues(u8 *eventWork, s32 slotIndex, s32 *outFlags, s32 *outResourceId) {
    u8 *slot;

    if (slotIndex >= 5 || slotIndex < 0) {
        return 0;
    }
    slot = byteAddressAdd(slotIndex * 4, eventWork);
    *outFlags = ((EvtTypeTwoRecords *)(slot + 0x640))->values[0];
    *outResourceId = (u16)((EvtTypeTwoRecords *)(byteAddressAdd(slotIndex * 2, eventWork) + 0x640))->ids[0];
    return ((EvtTypeTwoRecords *)(slot + 0x640))->data[0];
}

