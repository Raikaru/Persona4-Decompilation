/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00331560-00331860 */

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
extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s8 iGpffffb59c;
extern u8 *kwlnTaskGetTaskByName(s8 *arg0);
extern s32 mtSceneResListPrepareAll(void);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void calendarSetMode(s32 arg0);
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
    return *(s32 *)(fclCombineWork()->mesWindow + 0x110);
}

// FUN_00331680
s32 func_00331680(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x16, 0, 0, 2);
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

// FUN_00331770
s32 fclShopRunSystemScreen(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x17, 0, 0, 2);
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

// FUN_00331860
s32 fclCombineRunTitleScreen(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x18, 0, 0, 2);
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
