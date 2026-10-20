
#include "fcl_object_internal.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
/* Only the returned message handle is established by this accessor. */
typedef struct FclMessageWindow {
    u8 pad00[0x110];
    s32 handle;
} FclMessageWindow;

extern void kwlnSetColorRgba(u8 , u8 , u8 , u8 );
extern s8 iGpffffb59c;
extern u8 *kwlnTaskGetTaskByName(s8 *);
extern s32 mtSceneResListPrepareAll(void);
extern void sequenceRequest(s32 , void *, s32 , s32 );
extern void calendarSetMode(s32 );
extern u8 D_00644E80[];
extern u8 D_00644E98[];
extern u8 D_00644EB0[];
// FUN_00331560
s32 fclCombineGetSpritePool(void)
{
    return fclCombineWork()->spritePool;
}

// FUN_00331580
s32 fclCombineInPreviewState(void)
{
    return fclCombineWork()->f0 == 6;
}

// FUN_003315A0
void fclCombineRequestRefresh(void)
{
    fclCombineWork()->refreshRequested = 1;
}

// FUN_003315C0
s32 fclCombineGetRaster(void)
{
    return fclCombineWork()->raster;
}

// FUN_003315E0
s32 fclCombineGetTexture(void)
{
    return fclCombineWork()->texture;
}

// FUN_00331600
s32 fclCombineGetSpriteList(void)
{
    return fclCombineWork()->spriteList;
}

// FUN_00331620
s32 *fclCombineGetCardTable(void)
{
    return fclCombineWork()->cardTable;
}

// FUN_00331640
s8 fclCombineGetRowCount(void)
{
    return fclCombineWork()->rowCount;
}

// FUN_00331660
s32 fclCombineGetMesWindow(void)
{
    return ((FclMessageWindow *)fclCombineWork()->mesWindow)->handle;
}

/* Prepare scene resources, run system screen 0x16, then restore the calendar. */
// FUN_00331680
s32 fclCombineRunSystemScreen(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            sequenceRequest(0x16, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644E80) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* Run the shop system screen after resource preparation and restore the calendar when its task ends. */
// FUN_00331770
s32 fclShopRunSystemScreen(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            sequenceRequest(0x17, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644E98) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* Run the title system screen after resource preparation and restore the calendar when its task ends. */
// FUN_00331860
s32 fclCombineRunTitleScreen(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            sequenceRequest(0x18, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644EB0) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
