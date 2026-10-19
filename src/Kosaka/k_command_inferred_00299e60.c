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

s32 mtMiscResourceValue(s32 arg0);


extern void datSetFlag();
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
extern void calendarSetMode(s32 arg0);
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
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



extern void mtMiscCollectType1Records(u8 *arg0);
/* measured probe: close opt_propagation bracket after func_00291530. */





#pragma push

#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00299e60-00299ea0 */

// FUN_00299E60
s32 K_Cmd_DATE_DISP(void) {
    calendarSetMode(scrGetParamInt(0) != 0);
    return 1;
}

// FUN_00299EA0
s32 K_Cmd_FLAG_SELECT(void)
{
    s32 temp_16;

    temp_16 = scrGetParamInt(0);
    datSetFlag(0x1203, 0);
    datSetFlag(0x1204, 0);
    datSetFlag(0x1205, 0);
    datSetFlag(0x1206, 0);
    datSetFlag(0x1207, 0);
    switch (temp_16) {
    case 0:
        datSetFlag(0x1203);
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

