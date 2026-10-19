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
extern u8 *MT_Scene_GetRes(s32 arg0);
extern void MT_Scene_DestroyRes(u16 arg0);
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002919e0-00291b30 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
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
// Destroys the three icon resources (ids 0xC00 | ((i + 0x384) & 0x3FF), i = 0..2)
// that are still loaded.
// FUN_002919E0
void mtMiscDestroyIconResources(void) {
    s32 i;
    u16 temp;

    i = 0;
    while (i < 3) {
        temp = (u16)(((i + 0x384) & 0x3ff) | 0xc00);
        if (MT_Scene_GetRes(temp) != 0) {
            MT_Scene_DestroyRes(temp);
        }
        i++;
    }
}

// FUN_00291A60
s32 mtMiscResourceValue(s32 arg0)
{
    s32 temp_4;
    s32 mask;
    u8 *temp_2;

    temp_2 = MT_Scene_GetRes(arg0);
    mask = 0xFFC00;
    temp_4 = (s32)(arg0 & 0xFFFF) & mask;
    temp_4 >>= 0xA;
    switch (temp_4) {
    case 1:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x164);
        }
        break;
    case 2:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x158);
        }
        break;
    case 3:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x164);
        }
        break;
    case 10:
        if (temp_2 != NULL) {
            return (s32)*(s32 *)(temp_2 + 0x144);
        }
        break;
    default:
        break;
    }
    return 0;
}

// FUN_00291B30
s32 mtMiscResourceValueIsZero(s32 arg0, u16 *arg1) {
    return (s32)(mtMiscResourceValue(*arg1) == 0);
}

