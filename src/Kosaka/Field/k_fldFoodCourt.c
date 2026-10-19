#include "field_transition_internal.h"
/* Original translation unit k_fldFoodCourt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"

extern void H_Cdvd_Destroy(void *);
extern void func_003e0f40(void *);
extern void fieldSceneUnload(void);
extern void (*jtbl_008873EC[])(void *ptr);
extern void chkmemAllocSiteTag(const void *msg, s32 id);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5450[];
extern u8 D_005F54C8[];
extern s32 K_FldFoodCourt_Update(u8 *);
extern void K_FldFoodCourt_Destroy(u8 *);
extern u8 D_005F5470[];
extern u8 D_005F5490[];
extern u8 D_005F54B0[];
extern char iGpffff9f90;
extern void *func_003e0f80(void);
extern void fieldSceneLoad(s32 , s32 );
extern void fieldSceneRequestSecondaryRoom(s64 );
extern s32 clndIsDateInRange(s32 , s32 , s32 , s32 );
extern s32 fieldSceneLoadStep(void);
extern s32 mtSceneResListPrepareAll(void);
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s64 , s32 );
extern u8 *MT_Scene_GetCameraResSecond(void);
extern u8 *MT_Scene_GetCameraResFirst(void);
extern u8 *kwlnGetCamera(void);
extern f32 MT_Scene_GetCameraFov(void);
extern void K_View_SetFov(u8 *, f32 );
extern void func_003e9cb0(s32 , u8 *, s32 );
extern s32 scrStartProcedureChecked(s32 , s32 , s32 , s32 );
extern s32 kwlnTaskIsLinked(s32 );
extern s32 sndRequestAreaTrack(void);
extern void sndPlayAreaCue(void);
extern void fadeBeginReturnTransition(s32 , s32 );
extern s32 fadeStatus(void);



/* Load the seasonal food-court script and scene, select its calendar camera, then run entry procedures. */
/* Raw 0x10-byte work fields retained: the typed state/camera/script/task layout changed two functions' b210 matches; matrix copies retain paired-word order. */
// FUN_0018D950
s32 K_FldFoodCourt_Update(u8 *task) {
    s32 secondWord;
    s32 alternateSecondWord;
    s32 firstWord;
    s32 state;
    s64 date;
    u8 *work;
    u8 *camera;
    u8 *startupScript;
    u8 *entryScript;
    u8 *matrixDestination;
    u8 *secondaryMatrix;
    u8 *primaryMatrix;
    s32 pairsRemaining;

    work = ((SdkTask *)task)->work;
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        *(u8 **)(work + 4) = (u8 *)func_003e0f80();
        fieldSceneLoad(9, 1);
        fieldSceneRequestSecondaryRoom((s64)(s16)FldEnvStateFromCalendar(9, 1));
        if (clndIsDateInRange(4, 1, 7, 0x1F) == 1) {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x58);
            *(u8 **)(work + 8) = (u8 *)H_Cdvd_AcquireDirectory(D_005F5470, 0);
        } else if (clndIsDateInRange(8, 1, 0xB, 0x1E) == 1) {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x5C);
            *(u8 **)(work + 8) = (u8 *)H_Cdvd_AcquireDirectory(D_005F5490, 0);
        } else {
            func_00440b68(&iGpffff9f90, D_005F5450, 0x60);
            *(u8 **)(work + 8) = (u8 *)H_Cdvd_AcquireDirectory(D_005F54B0, 0);
        }
        *(s32 *)work += 1;
    case 1:
        if (fieldSceneLoadStep() != 0) {
            if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 8)) == 0) {
                return 0;
            }
            if (mtSceneResListPrepareAll() == 0) {
                return 0;
            }
            date = (s16)datGetDateIndex();
            if ((s8)calGetDayEntryByPhase(date, datGetTimeSlot() & 0xFF) == 1) {
                secondaryMatrix = (u8 *)MT_Scene_GetCameraResSecond();
                matrixDestination = *(u8 **)(work + 4);
                pairsRemaining = 8;
                do {
                    firstWord = *(s32 *)(secondaryMatrix + 0);
                    secondWord = *(s32 *)(secondaryMatrix + 4);
                    secondaryMatrix += 8;
                    pairsRemaining -= 1;
                    *(s32 *)(matrixDestination + 0) = firstWord;
                    *(s32 *)(matrixDestination + 4) = secondWord;
                    matrixDestination += 8;
                } while (pairsRemaining > 0);
            } else {
                primaryMatrix = (u8 *)MT_Scene_GetCameraResFirst();
                matrixDestination = *(u8 **)(work + 4);
                pairsRemaining = 8;
                do {
                    firstWord = *(s32 *)(primaryMatrix + 0);
                    alternateSecondWord = *(s32 *)(primaryMatrix + 4);
                    primaryMatrix += 8;
                    pairsRemaining -= 1;
                    *(s32 *)(matrixDestination + 0) = firstWord;
                    *(s32 *)(matrixDestination + 4) = alternateSecondWord;
                    matrixDestination += 8;
                } while (pairsRemaining > 0);
            }
            camera = (u8 *)kwlnGetCamera();
            K_View_SetFov(camera, MT_Scene_GetCameraFov());
            camera = (u8 *)kwlnGetCamera();
            func_003e9cb0(*(s32 *)(camera + 4), *(u8 **)(work + 4), 0);
            startupScript = *(u8 **)(work + 8);
            *(s32 *)(work + 0xC) =
                scrStartProcedureChecked(0xF, *(s32 *)(startupScript + 0x110), *(s32 *)(startupScript + 0x118), 0);
            *(s32 *)work += 1;
        } else {
            goto done;
        }
    case 2:
        if (kwlnTaskIsLinked(*(s32 *)(work + 0xC)) != 1) {
            if (sndRequestAreaTrack() == 0) {
                sndPlayAreaCue();
            }
            fadeBeginReturnTransition(1, 0);
            *(s32 *)work += 1;
        }
        else {
            goto done;
        }
    case 3:
        if (fadeStatus() != 0) {
            entryScript = *(u8 **)(work + 8);
            *(s32 *)(work + 0xC) =
                scrStartProcedureChecked(0xF, *(s32 *)(entryScript + 0x110), *(s32 *)(entryScript + 0x118), 1);
            *(s32 *)work += 1;
        }
    case 4:
    case 5:
    default:
        goto done;
    }
done:
    return 0;
}

/* Release the seasonal script, camera transform and field scene before freeing the work. */
/* Raw work camera/script fields retained: typing the 0x10-byte controller work changed the owner's b210 instruction selection. */
// FUN_0018DCD0
void K_FldFoodCourt_Destroy(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    H_Cdvd_Destroy(*(void **)(work + 8));
    func_003e0f40(*(void **)(work + 4));
    fieldSceneUnload();
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

/* Create the food-court scene controller with a sixteen-byte work allocation. */
// FUN_0018DD40
s32 K_FldFoodCourt_Create(u8 *parent)
{
    u8 *mem;

    chkmemAllocSiteTag(D_005F5450, 0xBF);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    if (mem == NULL) {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F54C8), 0xF, 0, 0, K_FldFoodCourt_Update, K_FldFoodCourt_Destroy, (u8 *)(mem));
}

