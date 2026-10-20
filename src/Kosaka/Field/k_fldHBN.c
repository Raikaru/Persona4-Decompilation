#include "mt_scene_internal.h"
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_transition_internal.h"
#include "field_frame_internal.h"
#include "field_scene_internal.h"

/* Versioned HBN headers add one count/unknown-word pair per new record class.
 * The first record starts at 0x28, 0x30, 0x38 or 0x48 depending on version. */
typedef struct FldHbnHeader {
    u32 magic;
    u32 version;
    u32 lightCount;
    u32 unk0c;
    u32 pointCount;
    u32 unk14;
    u32 pointAltCount;
    u32 unk1c;
    u32 pointExtraCount;
    u32 unk24;
    u32 pointExtendedCount;
    u32 unk2c;
    u32 lightExtendedCount;
    u32 unk34;
    u32 pointLateCount;
    u32 unk3c;
    u32 pointFinalCount;
    u32 unk44;
} FldHbnHeader;
/* SpawnLights advances these packed records by 0x20 and 0x14 respectively. */
typedef struct FldHbnLight {
    u16 id;
    u16 parameter;
    FieldRgba8 color;
    f32 point[3];
    f32 first;
    f32 second;
    f32 third;
} FldHbnLight;
typedef struct FldHbnPoint {
    u16 id;
    u16 unk02;
    f32 point[3];
    f32 value;
} FldHbnPoint;
/* Completed directory requests expose loaded bytes and their byte count. */
typedef struct FldHbnRequest {
    u8 pad00[0x110];
    u8 *data;
    u32 unk114;
    u32 size;
} FldHbnRequest;


extern u8 *MT_Scene_GetFrameState(void);
extern void FldHbnFreeEntryTable(void);
extern void (*DAT_008873EC[])(void *);
extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *, const char *);
extern void sprintf();
extern s32 H_Cdvd_FileExists(void *path);
extern void func_00440b68(char *, const char *, s32);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
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
extern s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
extern u8 *H_Cdvd_LookupRequest(void *pathAddress, u32 *slot);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void memcpy(void *, void *, s32);
extern void H_Cdvd_Destroy(void *cdvd);
extern void *(*D_008873F4[])(size_t, size_t, u32);

/* Source unit: src/promoted/k_fldHBN.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldHBN.c; members 0015f8e0-001602a0 */

/* Open field/room HBN data for the selected load source; packed loading uses sentinel handle 1. */
// FUN_0015F8E0
u8 *FldHbnOpenData(s32 fieldId, s32 roomId)
{
    char directory[0x80];
    char path[0x80];

    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&directory, D_005F1118);
        sprintf(&path, D_005F1130, fieldId & 0xFFFF, roomId & 0xFFFF);
        if (H_Cdvd_FileExists(&path) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x17D);
        return H_Cdvd_AcquireDirectory(&path, 0);
    }
    return (u8 *)1;
}

/* Poll HBN loading, copy completed bytes into owned storage, then release a directory request. */
// FUN_0015F9B0
s32 FldHbnReadData(u8 *request, u16 **destination, s32 fieldId, s32 roomId)
{
    u32 dataSize;
    char path[0x40];
    u8 *data;
    u16 *copy;

    if (request == NULL)
    {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(request) == 0))
    {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        dataSize = ((FldHbnRequest *)request)->size;
        data = ((FldHbnRequest *)request)->data;
    }
    else
    {
        sprintf(&path, D_005F1150, fieldId & 0xFFFF, roomId & 0xFFFF);
        data = H_Cdvd_LookupRequest(&path, &dataSize);
    }
    if (data != NULL)
    {
        chkmemAllocSiteTag(D_005F1108, 0x1AE);
        copy = (u16 *)D_008873F4[0](1, (s32)(dataSize), 0x40000);
        *destination = copy;
        memcpy(copy, data, dataSize);
    }
    if (FldRc_GetLoadSource() == 0)
    {
        H_Cdvd_Destroy(request);
    }
    return 1;
}

/* 1052/1056 bytes: field colors are four-byte values passed after the
   three floats. Lifetime analysis preserves the separate cursor/counter
   phases. See docs/probe_archive/HBN_0015fb00_color_value_recovery.md. */
/* Spawn versioned HBN light/point records, filtering reserved IDs according to field band and mode. */
// FUN_0015FB00
#pragma push
/* measured: FldHbnSpawnLights MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
void FldHbnSpawnLights(u8 *header, s32 mode)
{
    /* Raw accesses retained: the proven request/record layouts above changed whole-file codegen when substituted. */
    extern s32 MT_Scene_CreatePointRes14(u16 header, f32 *mode, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes15(u16 header, f32 *mode, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes16(u16 header, f32 *mode, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes17(u16 header, f32 *mode, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes18(u16 header, f32 *mode, f32 fparg0);
    extern s32 MT_Scene_CreatePointRes19(u16 header, f32 *mode, f32 fparg0);
    extern s32 FldMap_IsCurrentInBandA(void);
    extern s32 FldMap_IsCurrentInBandB(void);
    u8 *lightCursor;
    u32 lightIndex;
    u8 *pointCursor;
    u32 pointIndex;
    u32 extraIndex;

    if (header != NULL) {
        if (*(u32 *)(header + 4) == 0x10000) {
            lightCursor = header + 0x28;
        } else if (*(u32 *)(header + 4) == 0x10001) {
            lightCursor = header + 0x30;
        } else if (*(u32 *)(header + 4) == 0x10002) {
            lightCursor = header + 0x38;
        } else {
            lightCursor = header + 0x48;
        }
        for (lightIndex = 0; lightIndex < *(u32 *)(header + 8);) {
            if ((((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (mode == 1)) && ((mode != 1) || (((*(u16 *)lightCursor & 0x3FF) != 0x3FE) && ((*(u16 *)lightCursor & 0x3FF) != 0x3FF)))) {
                MT_Scene_CreateFldHitLight(*(u16 *)lightCursor & 0x3FF, (f32 *)(lightCursor + 8), *(f32 *)(lightCursor + 0x14), *(f32 *)(lightCursor + 0x18), *(f32 *)(lightCursor + 0x1C), *(FieldRgba8 *)(lightCursor + 4));
            }
            lightIndex++;
            lightCursor += 0x20;
        }
        pointCursor = lightCursor;
        for (pointIndex = 0; pointIndex < *(u32 *)(header + 0x10);) {
            if ((((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (mode == 1)) && ((mode != 1) || ((*(u16 *)pointCursor & 0x3FF) != 0x3FF))) {
                MT_Scene_CreatePointRes14(*(u16 *)pointCursor & 0x3FF, (f32 *)(pointCursor + 4), *(f32 *)(pointCursor + 0x10));
            }
            pointIndex++;
            pointCursor += 0x14;
        }
        if (((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (((FldMap_IsCurrentInBandB() == 1) && (mode == 1)))) {
            for (pointIndex = 0; pointIndex < *(u32 *)(header + 0x18);) {
                MT_Scene_CreatePointRes15(*(u16 *)pointCursor & 0x3FF, (f32 *)(pointCursor + 4), *(f32 *)(pointCursor + 0x10));
                pointIndex++;
                pointCursor += 0x14;
            }
        }
        if (((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0)) || (mode == 1)) {
            for (extraIndex = 0; extraIndex < *(u32 *)(header + 0x20);) {
                MT_Scene_CreatePointRes16(*(u16 *)pointCursor & 0x3FF, (f32 *)(pointCursor + 4), *(f32 *)(pointCursor + 0x10));
                extraIndex++;
                pointCursor += 0x14;
            }
            if (*(u32 *)(header + 4) > 0x10000U) {
                for (extraIndex = 0; extraIndex < *(u32 *)(header + 0x28);) {
                    MT_Scene_CreatePointRes17(*(u16 *)pointCursor & 0x3FF, (f32 *)(pointCursor + 4), *(f32 *)(pointCursor + 0x10));
                    extraIndex++;
                    pointCursor += 0x14;
                }
            }
            if (*(u32 *)(header + 4) > 0x10001U) {
                lightCursor = pointCursor;
                for (lightIndex = 0; lightIndex < *(u32 *)(header + 0x30);) {
                    MT_Scene_CreateRes21Light(*(u16 *)lightCursor & 0x3FF, (f32 *)(lightCursor + 8), *(f32 *)(lightCursor + 0x14), *(f32 *)(lightCursor + 0x18), *(f32 *)(lightCursor + 0x1C), *(FieldRgba8 *)(lightCursor + 4));
                    {
                        u8 *resource = MT_Scene_GetRes(((*(u16 *)lightCursor & 0x3FF) | 0x5400) & 0xFFFF);
                        *(s32 *)(resource + 0x18C) = *(u16 *)(lightCursor + 2);
                    }
                    lightIndex++;
                    lightCursor += 0x20;
                }
            }
            if (*(u32 *)(header + 4) > 0x10002U) {
                for (lightIndex = 0; lightIndex < *(u32 *)(header + 0x38);) {
                    MT_Scene_CreatePointRes18(*(u16 *)lightCursor & 0x3FF, (f32 *)(lightCursor + 4), *(f32 *)(lightCursor + 0x10));
                    lightIndex++;
                    lightCursor += 0x14;
                }
                for (lightIndex = 0; lightIndex < *(u32 *)(header + 0x40);) {
                    MT_Scene_CreatePointRes19(*(u16 *)lightCursor & 0x3FF, (f32 *)(lightCursor + 4), *(f32 *)(lightCursor + 0x10));
                    lightIndex++;
                    lightCursor += 0x14;
                }
            }
        }
    }
}

#pragma pop
// FUN_0015FF20
u8 *FldHbnOpenTable(s32 fieldId, s32 roomId)
{
    char directory[0x80];
    char path[0x80];
    s32 id;

    id = (u16)fieldId;
    if (id == -1)
    {
        return NULL;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&directory, D_005F1118);
        sprintf(&path, D_005F1170, id, roomId & 0xFFFF);
        if (H_Cdvd_FileExists(&path) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x27D);
        return H_Cdvd_AcquireDirectory(&path, 0);
    }
    return (u8 *)1;
}

/* Poll and copy the event table; entries are fixed 44-byte records. */
// FUN_00160000
s32 FldHbnLoadEntryTable(u8 *request)
{
    u32 dataSize;
    char path[0x40];
    u8 *data;
    u8 *sceneOrBuffer;

    if (request == NULL)
    {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(request) == 0))
    {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        dataSize = ((FldHbnRequest *)request)->size;
        data = ((FldHbnRequest *)request)->data;
    }
    else
    {
        sceneOrBuffer = (u8 *)iGpffff9db0;
        sprintf(&path, D_005F1190, ((FieldSceneState *)sceneOrBuffer)->field.value, ((FieldSceneState *)sceneOrBuffer)->room.value);
        data = H_Cdvd_LookupRequest(&path, &dataSize);
    }
    if (data != NULL)
    {
        FldHbnFreeEntryTable();
        ((FldFrame *)MT_Scene_GetFrameState())->eventCount = dataSize / 44;
        chkmemAllocSiteTag(D_005F1108, 0x2AD);
        sceneOrBuffer = D_008873F4[0](1, (s32)(dataSize), 0x40000);
        ((FldFrame *)MT_Scene_GetFrameState())->eventTable = sceneOrBuffer;
        memcpy(((FldFrame *)MT_Scene_GetFrameState())->eventTable, data, dataSize);
    }
    if (FldRc_GetLoadSource() == 0)
    {
        H_Cdvd_Destroy(request);
    }
    return 1;
}

/* Release the owned event table and reset its count and pointer. */
// FUN_00160180
void FldHbnFreeEntryTable(void)
{
    if (((FldFrame *)MT_Scene_GetFrameState())->eventTable != 0) {
        ((FldFrame *)MT_Scene_GetFrameState())->eventCount = 0;
        (*DAT_008873EC)(((FldFrame *)MT_Scene_GetFrameState())->eventTable);
        ((FldFrame *)MT_Scene_GetFrameState())->eventTable = 0;
    }
}

/* Open the field script resource for directory or packed loading. */
// FUN_001601E0
u8 *FldHbnOpenScript(s32 fieldId)
{
    char directory[0x80];
    char path[0x80];

    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(&directory, D_005F1118);
        sprintf(&path, D_005F11B0, fieldId & 0xFFFF);
        if (H_Cdvd_FileExists(&path) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x2E0);
        return H_Cdvd_AcquireDirectory(&path, 0);
    }
    return (u8 *)1;
}

/* Poll and copy the script buffer into frame-owned storage, retaining its exact byte count. */
// FUN_001602A0
s32 FldHbnLoadScriptBuffer(u8 *request, s32 fieldId)
{
    /* Raw accesses retained: the proven request/record layouts above changed whole-file codegen when substituted. */
    u32 dataSize;
    char path[0x40];
    u8 *copy;
    u8 *data;

    if (request == NULL)
    {
        return 1;
    }
    if (FldRc_GetLoadSource() == 0)
    {
        if (H_Cdvd_IsFileLoaded(request) != 0)
        {
            chkmemAllocSiteTag(D_005F1108, 0x2F9);
            copy = D_008873F4[0](1, (s32)(*(u32 *)(request + 0x118)), 0x40000);
            ((FldFrame *)MT_Scene_GetFrameState())->auxBuffer = copy;
            ((FldFrame *)MT_Scene_GetFrameState())->auxSize = *(u32 *)(request + 0x118);
            memcpy(((FldFrame *)MT_Scene_GetFrameState())->auxBuffer, *(void **)(request + 0x110), *(u32 *)(request + 0x118));
            H_Cdvd_Destroy(request);
            return 1;
        }
    }
    else
    {
        sprintf(&path, D_005F11D0, fieldId & 0xFFFF);
        data = H_Cdvd_LookupRequest(&path, &dataSize);
        if (data != NULL)
        {
            chkmemAllocSiteTag(D_005F1108, 0x30C);
            copy = D_008873F4[0](1, (s32)(dataSize), 0x40000);
            ((FldFrame *)MT_Scene_GetFrameState())->auxBuffer = copy;
            ((FldFrame *)MT_Scene_GetFrameState())->auxSize = dataSize;
            memcpy(((FldFrame *)MT_Scene_GetFrameState())->auxBuffer, data, dataSize);
        }
        return 1;
    }
    return 0;
}

