#include "Kosaka/k_command_internal.h"
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

s32 mtMiscResourceValue(s32 resourceId);


extern void datSetFlag(s32 flagId, s32 enabled);
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];


extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
extern void calendarSetMode(s32 mode);
// lint: allow H011 -- a u16 prototype breaks func_00291a60, which passes wide id args.
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32 farg0, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 image, f32 x, f32 y, f32 scaleX,
                          f32 scaleY, s32 alphaSubtract, s32 centered);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];


extern void mtMiscCollectType1Records(u8 *eventWork);


#pragma push

#pragma pop

// FUN_00299E60
s32 K_Cmd_DATE_DISP(void) {
    calendarSetMode(scrGetParamInt(0) != 0);
    return 1;
}

/* Clear the five selection flags and set the one selected by an operand from zero through four. */
// FUN_00299EA0
s32 K_Cmd_FLAG_SELECT(void)
{
    s32 selection;

    selection = scrGetParamInt(0);
    datSetFlag(0x1203, 0);
    datSetFlag(0x1204, 0);
    datSetFlag(0x1205, 0);
    datSetFlag(0x1206, 0);
    datSetFlag(0x1207, 0);
    switch (selection) {
    case 0:
        datSetFlag(0x1203, 1);
        break;
    case 1:
        datSetFlag(0x1204, 1);
        break;
    case 2:
        datSetFlag(0x1205, 1);
        break;
    case 3:
        datSetFlag(0x1206, 1);
        break;
    case 4:
        datSetFlag(0x1207, 1);
        break;
    }
    return 1;
}

