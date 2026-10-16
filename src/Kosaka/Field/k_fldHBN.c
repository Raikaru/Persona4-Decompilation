#include "mt_scene_internal.h"
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_transition_internal.h"
#include "field_frame_internal.h"

extern u8 *MT_Scene_GetFrameState(void);
extern void FldHbnFreeEntryTable(void);
extern void (*DAT_008873EC[])(void *);
extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *arg0, const char *arg1);
extern void sprintf();
extern s32 H_Cdvd_FileExists(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *H_Cdvd_AcquireDirectory(void *arg0, s32 arg1);
extern char D_005F1108[];
extern char D_005F1118[];
extern char D_005F1130[];
extern char D_005F1150[];
extern char D_005F1170[];
extern char D_005F1190[];
extern char D_005F11B0[];
extern char D_005F11D0[];
extern u8 *iGpffff9db0;
extern char iGpffff9ef0;
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *H_Cdvd_LookupRequest(void *arg0, u32 *arg1);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern void H_Cdvd_Destroy(void *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);

/* Source unit: src/promoted/k_fldHBN.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldHBN.c; members 0015f8e0-001602a0 */

// FUN_0015F8E0
u8 *FldHbnOpenData(s32 arg0, s32 arg1)
{
    char spB0[0x80];
    char sp30[0x80];

    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&spB0, D_005F1118);
        sprintf(&sp30, D_005F1130, arg0 & 0xFFFF, arg1 & 0xFFFF);
        if (H_Cdvd_FileExists(&sp30) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x17D);
        return H_Cdvd_AcquireDirectory(&sp30, 0);
    }
    return (u8 *)1;
}

// FUN_0015F9B0
s32 FldHbnReadData(u8 *arg0, u16 **arg1, s32 arg2, s32 arg3)
{
    u32 sp9C;
    char sp50[0x40];
    u8 *data;
    u16 *buf;

    if (arg0 == NULL)
    {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(arg0) == 0))
    {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        sp9C = *(u32 *)(arg0 + 0x118);
        data = (u8 *)*(u32 **)(arg0 + 0x110);
    }
    else
    {
        sprintf(&sp50, D_005F1150, arg2 & 0xFFFF, arg3 & 0xFFFF);
        data = H_Cdvd_LookupRequest(&sp50, &sp9C);
    }
    if (data != NULL)
    {
        chkmemAllocSiteTag(D_005F1108, 0x1AE);
        buf = (u16 *)D_008873F4[0](1, (s32)(sp9C), 0x40000);
        *arg1 = buf;
        memcpy(buf, data, sp9C);
    }
    if (FldRc_GetLoadSource() == 0)
    {
        H_Cdvd_Destroy(arg0);
    }
    return 1;
}

/* 1052/1056 bytes: field colors are four-byte values passed after the
   three floats. Lifetime analysis preserves the separate cursor/counter
   phases. See docs/probe_archive/HBN_0015fb00_color_value_recovery.md. */
// FUN_0015FB00
#pragma push
/* measured: FldHbnSpawnLights MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
void FldHbnSpawnLights(u8 *arg0, s32 arg1)
{
    extern s32 MT_Scene_CreatePointRes14(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes15(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes16(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes17(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes18(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes19(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 FldMap_IsCurrentInBandA(void);
    extern s32 FldMap_IsCurrentInBandB(void);
    u8 *r13;
    u32 c1;
    u8 *r2;
    u32 c2;
    u32 c3;

    if (arg0 != NULL) {
        if (*(u32 *)(arg0 + 4) == 0x10000) {
            r13 = arg0 + 0x28;
        } else if (*(u32 *)(arg0 + 4) == 0x10001) {
            r13 = arg0 + 0x30;
        } else if (*(u32 *)(arg0 + 4) == 0x10002) {
            r13 = arg0 + 0x38;
        } else {
            r13 = arg0 + 0x48;
        }
        for (c1 = 0; c1 < *(u32 *)(arg0 + 8);) {
            if ((((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (arg1 == 1)) && ((arg1 != 1) || (((*(u16 *)r13 & 0x3FF) != 0x3FE) && ((*(u16 *)r13 & 0x3FF) != 0x3FF)))) {
                MT_Scene_CreateFldHitLight(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 8), *(f32 *)(r13 + 0x14), *(f32 *)(r13 + 0x18), *(f32 *)(r13 + 0x1C), *(FieldRgba8 *)(r13 + 4));
            }
            c1++;
            r13 += 0x20;
        }
        r2 = r13;
        for (c2 = 0; c2 < *(u32 *)(arg0 + 0x10);) {
            if ((((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (arg1 == 1)) && ((arg1 != 1) || ((*(u16 *)r2 & 0x3FF) != 0x3FF))) {
                MT_Scene_CreatePointRes14(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
            }
            c2++;
            r2 += 0x14;
        }
        if (((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (((FldMap_IsCurrentInBandB() == 1) && (arg1 == 1)))) {
            for (c2 = 0; c2 < *(u32 *)(arg0 + 0x18);) {
                MT_Scene_CreatePointRes15(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                c2++;
                r2 += 0x14;
            }
        }
        if (((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (arg1 == 1)) {
            for (c3 = 0; c3 < *(u32 *)(arg0 + 0x20);) {
                MT_Scene_CreatePointRes16(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                c3++;
                r2 += 0x14;
            }
            if (*(u32 *)(arg0 + 4) > 0x10000U) {
                for (c3 = 0; c3 < *(u32 *)(arg0 + 0x28);) {
                    MT_Scene_CreatePointRes17(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                    c3++;
                    r2 += 0x14;
                }
            }
            if (*(u32 *)(arg0 + 4) > 0x10001U) {
                r13 = r2;
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x30);) {
                    MT_Scene_CreateRes21Light(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 8), *(f32 *)(r13 + 0x14), *(f32 *)(r13 + 0x18), *(f32 *)(r13 + 0x1C), *(FieldRgba8 *)(r13 + 4));
                    {
                        u8 *resource = MT_Scene_GetRes(((*(u16 *)r13 & 0x3FF) | 0x5400) & 0xFFFF);
                        *(s32 *)(resource + 0x18C) = *(u16 *)(r13 + 2);
                    }
                    c1++;
                    r13 += 0x20;
                }
            }
            if (*(u32 *)(arg0 + 4) > 0x10002U) {
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x38);) {
                    MT_Scene_CreatePointRes18(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 4), *(f32 *)(r13 + 0x10));
                    c1++;
                    r13 += 0x14;
                }
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x40);) {
                    MT_Scene_CreatePointRes19(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 4), *(f32 *)(r13 + 0x10));
                    c1++;
                    r13 += 0x14;
                }
            }
        }
    }
}

#pragma pop
// FUN_0015FF20
u8 *FldHbnOpenTable(s32 arg0, s32 arg1)
{
    char spB0[0x80];
    char sp30[0x80];
    s32 id;

    id = (u16)arg0;
    if (id == -1)
    {
        return NULL;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&spB0, D_005F1118);
        sprintf(&sp30, D_005F1170, id, arg1 & 0xFFFF);
        if (H_Cdvd_FileExists(&sp30) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x27D);
        return H_Cdvd_AcquireDirectory(&sp30, 0);
    }
    return (u8 *)1;
}

// FUN_00160000
s32 FldHbnLoadEntryTable(u8 *arg0)
{
    u32 sp8C;
    char sp40[0x40];
    u8 *data;
    u8 *temp_2;

    if (arg0 == NULL)
    {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(arg0) == 0))
    {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        sp8C = *(u32 *)(arg0 + 0x118);
        data = *(u8 **)(arg0 + 0x110);
    }
    else
    {
        temp_2 = (u8 *)iGpffff9db0;
        sprintf(&sp40, D_005F1190, *(s32 *)(temp_2 + 0), *(s32 *)(temp_2 + 4));
        data = H_Cdvd_LookupRequest(&sp40, &sp8C);
    }
    if (data != NULL)
    {
        FldHbnFreeEntryTable();
        ((FldFrame *)MT_Scene_GetFrameState())->eventCount = sp8C / 44;
        chkmemAllocSiteTag(D_005F1108, 0x2AD);
        temp_2 = D_008873F4[0](1, (s32)(sp8C), 0x40000);
        ((FldFrame *)MT_Scene_GetFrameState())->eventTable = temp_2;
        memcpy(((FldFrame *)MT_Scene_GetFrameState())->eventTable, data, sp8C);
    }
    if (FldRc_GetLoadSource() == 0)
    {
        H_Cdvd_Destroy(arg0);
    }
    return 1;
}

// FUN_00160180
void FldHbnFreeEntryTable(void)
{
    if (((FldFrame *)MT_Scene_GetFrameState())->eventTable != 0) {
        ((FldFrame *)MT_Scene_GetFrameState())->eventCount = 0;
        (*DAT_008873EC)(((FldFrame *)MT_Scene_GetFrameState())->eventTable);
        ((FldFrame *)MT_Scene_GetFrameState())->eventTable = 0;
    }
}

// FUN_001601E0
u8 *FldHbnOpenScript(s32 arg0)
{
    char spA0[0x80];
    char sp20[0x80];

    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&spA0, D_005F1118);
        sprintf(&sp20, D_005F11B0, arg0 & 0xFFFF);
        if (H_Cdvd_FileExists(&sp20) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x2E0);
        return H_Cdvd_AcquireDirectory(&sp20, 0);
    }
    return (u8 *)1;
}

// FUN_001602A0
s32 FldHbnLoadScriptBuffer(u8 *arg0, s32 arg1)
{
    u32 sp7C;
    char sp30[0x40];
    u8 *buf;
    u8 *data;

    if (arg0 == NULL)
    {
        return 1;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        if (H_Cdvd_IsFileLoaded(arg0) != 0)
        {
            chkmemAllocSiteTag(D_005F1108, 0x2F9);
            buf = D_008873F4[0](1, (s32)(*(u32 *)(arg0 + 0x118)), 0x40000);
            ((FldFrame *)MT_Scene_GetFrameState())->auxBuffer = buf;
            ((FldFrame *)MT_Scene_GetFrameState())->auxSize = *(u32 *)(arg0 + 0x118);
            memcpy(((FldFrame *)MT_Scene_GetFrameState())->auxBuffer, *(void **)(arg0 + 0x110), *(u32 *)(arg0 + 0x118));
            H_Cdvd_Destroy(arg0);
            return 1;
        }
    }
    else
    {
        sprintf(&sp30, D_005F11D0, arg1 & 0xFFFF);
        data = H_Cdvd_LookupRequest(&sp30, &sp7C);
        if (data != NULL)
        {
            chkmemAllocSiteTag(D_005F1108, 0x30C);
            buf = D_008873F4[0](1, (s32)(sp7C), 0x40000);
            ((FldFrame *)MT_Scene_GetFrameState())->auxBuffer = buf;
            ((FldFrame *)MT_Scene_GetFrameState())->auxSize = sp7C;
            memcpy(((FldFrame *)MT_Scene_GetFrameState())->auxBuffer, data, sp7C);
        }
        return 1;
    }
    return 0;
}

