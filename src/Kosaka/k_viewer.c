/* Whole-file translation unit (functions contiguous in retail). */
#include "sdk_lbox_internal.h"
#include "type.h"
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

extern s32 func_00102980(void);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);

extern s32 FldViewerUpdate(u8 *arg0);
extern void FldViewerDestroy(u8 *arg0);

// FUN_0018F3C0
s32 FldViewerCreate(s32 arg0)
{
    s32 *buf;
    s32 ret;

    chkmemAllocSiteTag(D_005F5990, 0xFB);
    buf = D_008873F4[0](1, 0x10, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F59A0), 0xF, 0, 0, FldViewerUpdate, FldViewerDestroy, (u8 *)(buf));
    FldStepResetTables();
    D_00764304 = 0;
    return ret;
}

// FUN_0018F470
s32 K_Viewer_Update(u8 *arg0)
{
    s32 *p;
    s32 state;
    s32 value;
    s32 sp[2];

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
    {
        KwlnTask *buf;

        buf = sdkLboxCreate((KwlnTask *)arg0, 0xDC, 0xA0);
        *(KwlnTask **)(p + 1) = buf;
        sdkLboxAddDescriptors(buf, D_005F59F0, 6);
        value = D_00764344;
        *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 2) = value;
        value = D_00764348;
        *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 3) = value;
        value = D_0076434C;
        *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 4) = value;
        value = D_00764350;
        *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 5) = value;
        sdkLboxSetState(*(u8 **)(p + 1), 4);
        sdkLboxSetSelection(*(u8 **)(p + 1), 1);
        *(s32 *)p = *(s32 *)p + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            D_00764304 = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 1);
            D_00764344 = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 2);
            D_00764348 = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 3);
            D_0076434C = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 4);
            D_00764350 = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 5);
            sp[0] = *sdkLboxGetValuePtr(*(KwlnTask **)(p + 1), 0);
            sp[1] = 0xFFFF;
            func_001029a0(0xB, sp, 8, 0);
            sdkLboxSetSelection(*(u8 **)(p + 1), 0);
            *(s32 *)p = 2;
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)p = 3;
        }
        break;
    case 2:
        if (func_00102980() == 0) {
            D_00764494 = 0;
            sdkLboxSetSelection(*(u8 **)(p + 1), 1);
            *(s32 *)p = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

// FUN_0018F6D0
void K_Viewer_Destroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018F700
s32 K_Viewer_Create(s32 arg0)
{
    s32 *buf;
    s32 ret;

    chkmemAllocSiteTag(D_005F5990, 0x183);
    buf = D_008873F4[0](1, 0x10, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F5AB0), 0xF, 0, 0, K_Viewer_Update, K_Viewer_Destroy, (u8 *)(buf));
    FldStepResetTables();
    D_00764304 = 0;
    return ret;
}
