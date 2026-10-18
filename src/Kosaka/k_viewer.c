/* Whole-file translation unit (functions contiguous in retail). */
#include "sdk_lbox_internal.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "sdk_task_registration.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_008C024E[];

extern u8 D_005F5990[];
extern u8 D_005F59A0[];
extern const KWindowEntryDescriptor D_005F59F0[];
extern u8 D_005F5AB0[];
extern s32 D_00764304;
extern s32 D_00764344;
extern s32 D_00764348;
extern s32 D_0076434C;
extern s32 D_00764350;
extern s32 D_00764494;

extern void FldStepResetTables(void);
extern void chkmemAllocSiteTag(void *msg, s32 id);

extern s32 kwlnGetCurrentWorkValue(void);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);

extern s32 FldViewerUpdate(u8 *arg0);
extern void FldViewerDestroy(u8 *arg0);

/* Both viewer creators allocate 0x10 bytes; the menu uses the first two words. */
typedef struct ViewerMenuWork
{
    s32 state;
    u8 *listBox;
    u8 pad08[8];
} ViewerMenuWork;

/* Start the field viewer, reset step tables, and clear its selected resource. */
// FUN_0018F3C0
s32 FldViewerCreate(s32 parentTask)
{
    s32 *work;
    s32 viewerTask;

    chkmemAllocSiteTag(D_005F5990, 0xFB);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    viewerTask = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F59A0), 0xF, 0, 0, FldViewerUpdate, FldViewerDestroy, (u8 *)(work));
    FldStepResetTables();
    D_00764304 = 0;
    return viewerTask;
}

/* Edit viewer globals and send the selected resource request; wait for completion. */
// FUN_0018F470
s32 K_Viewer_Update(u8 *task)
{
    ViewerMenuWork *work;
    s32 state;
    s32 value;
    s32 request[2];

    work = (ViewerMenuWork *)((KwlnTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
    {
        KwlnTask *listBox;

        listBox = sdkLboxCreate((KwlnTask *)task, 0xDC, 0xA0);
        *(KwlnTask **)&work->listBox = listBox;
        sdkLboxAddDescriptors(listBox, D_005F59F0, 6);
        value = D_00764344;
        *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 2) = value;
        value = D_00764348;
        *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 3) = value;
        value = D_0076434C;
        *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 4) = value;
        value = D_00764350;
        *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 5) = value;
        sdkLboxSetState(work->listBox, 4);
        sdkLboxSetSelection(work->listBox, 1);
        work->state = work->state + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            D_00764304 = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 1);
            D_00764344 = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 2);
            D_00764348 = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 3);
            D_0076434C = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 4);
            D_00764350 = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 5);
            request[0] = *sdkLboxGetValuePtr(*(KwlnTask **)&work->listBox, 0);
            request[1] = 0xFFFF;
            func_001029a0(0xB, request, 8, 0);
            sdkLboxSetSelection(work->listBox, 0);
            work->state = 2;
        } else if (D_008C024E[0] & 0x20) {
            work->state = 3;
        }
        break;
    case 2:
        if (kwlnGetCurrentWorkValue() == 0) {
            D_00764494 = 0;
            sdkLboxSetSelection(work->listBox, 1);
            work->state = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0018F6D0
void K_Viewer_Destroy(u8 *task)
{
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}

/* Start the viewer menu and reset its shared field-selection state. */
// FUN_0018F700
s32 K_Viewer_Create(s32 parentTask)
{
    s32 *work;
    s32 viewerTask;

    chkmemAllocSiteTag(D_005F5990, 0x183);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    viewerTask = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F5AB0), 0xF, 0, 0, K_Viewer_Update, K_Viewer_Destroy, (u8 *)(work));
    FldStepResetTables();
    D_00764304 = 0;
    return viewerTask;
}
