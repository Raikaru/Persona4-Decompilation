#include "field_transition_internal.h"
/* Whole-file translation unit (functions contiguous in retail). */
#include "sdk_lbox_internal.h"
#include "type.h"
#include "sdk_task_registration.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_008C024E[];

extern const KWindowEntryDescriptor D_005F55B0[];
extern u8 D_005F56F0[];
extern u8 D_005F5700[];
extern f32 D_00761624;
extern f32 D_0076151C;

extern void chkmemAllocSiteTag(void *msg, s32 id);
extern void kAssertFail(void *msg, s32 id);
extern s32 kwlnTaskIsLinked(s32 buf);
extern s32 kwlnTaskGetTaskByName(void *buf);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *handle);


extern s32 FldMapTestTaskCreate(u8 *arg0);
extern s32 K_Test_CreateLauncher(u8 *arg0);
extern void K_ReadTexTaskCreate(void);
extern s32 FldRainTaskCreate(f32 f0, u8 *arg0, s32 arg1, f32 f1, f32 f2, f32 f3,
                          s32 arg2, s32 arg3, s32 arg4);
extern s32 FldPlayerIconTaskCreate(u8 *arg0);
extern s32 K_Clump_CreateLoadTask(s32 arg0);
extern s32 K_TexStripBuildTaskCreate(s32 arg0);
extern s32 K_TexStripLoadTaskCreate(s32 arg0);
extern s32 K_TexStripCodeLogTaskCreate(s32 arg0);

// FUN_0018E050
s32 K_TestMenu_Update(u8 *arg0)
{
    u8 *p;
    s32 state;

    p = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)p;
    switch (state) {
    case 0:
    {
        KwlnTask *buf;

        buf = sdkLboxCreate((KwlnTask *)arg0, 0x100, 0x40);
        *(KwlnTask **)(p + 4) = buf;
        sdkLboxAddDescriptors(buf, D_005F55B0, 0xA);
        sdkLboxSetVisibleRows(*(u8 **)(p + 4), 0x14);
        sdkLboxSetState(*(u8 **)(p + 4), 4);
        sdkLboxSetSelection(*(u8 **)(p + 4), 1);
        *(s32 *)p = *(s32 *)p + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            switch (sdkLboxGetSelectedId(*(u8 **)(p + 4))) {
            case 0:
                *(s32 *)(p + 8) = FldMapTestTaskCreate(arg0);
                break;
            case 1:
                *(s32 *)(p + 8) = K_Test_CreateLauncher(arg0);
                break;
            case 2:
                K_ReadTexTaskCreate();
                break;
            case 3:
                *(s32 *)(p + 8) = FldRainTaskCreate(200.0f, arg0, 0, D_00761624,
                                                  D_0076151C, 30.0f, 0x30, 8,
                                                  0xA);
                break;
            case 4:
                *(s32 *)(p + 8) = FldNoiseTaskCreate(arg0);
                break;
            case 5:
                *(s32 *)(p + 8) = FldPlayerIconTaskCreate(arg0);
                break;
            case 6:
                *(s32 *)(p + 8) = K_Clump_CreateLoadTask(0);
                break;
            case 7:
                *(s32 *)(p + 8) = K_TexStripBuildTaskCreate(0);
                break;
            case 8:
                *(s32 *)(p + 8) = K_TexStripLoadTaskCreate(0);
                break;
            case 9:
                *(s32 *)(p + 8) = K_TexStripCodeLogTaskCreate(0);
                break;
            default:
                kAssertFail(D_005F56F0, 0xA1);
                break;
            }
            sdkLboxSetSelection(*(u8 **)(p + 4), 0);
            *(s32 *)p = 2;
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)p = 3;
        }
        break;
    case 2:
        if (kwlnTaskIsLinked(*(s32 *)(p + 8)) != 1) {
            sdkLboxSetSelection(*(u8 **)(p + 4), 1);
            *(s32 *)p = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0018E310
void K_TestMenu_Destroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018E340
void K_TestMenu_Create(void)
{
    chkmemAllocSiteTag(D_005F56F0, 0xCB);
    kwlnTaskCreate((const void *)(D_005F5700), 0xF, 0, 0, K_TestMenu_Update, K_TestMenu_Destroy, (u8 *)(D_008873F4[0](1, 0xC, 0x40000)));
}

// FUN_0018E3C0
s32 K_TestMenu_IsActive(void)
{
    return kwlnTaskGetTaskByName(D_005F5700) != 0;
}

// FUN_0018E3F0
void K_TestMenu_Close(void)
{
    s32 result;

    result = kwlnTaskGetTaskByName(D_005F5700);
    if (result == 0) {
        kAssertFail(D_005F56F0, 0xF2);
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)result);
}
