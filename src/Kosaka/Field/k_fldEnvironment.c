#include "field_transition_internal.h"
#include "sdk_task_registration.h"
/* Original translation unit k_fldEnvironment.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdktask.h"

/* The controller allocates 0x14 bytes; the last four words feed filter entry/type/intensity/duration. */
typedef struct FldFilterWork {
    s32 state;
    s32 index;
    s32 type;
    s32 intensity;
    s32 duration;
} FldFilterWork;


extern void fldFilterBeginTransition(s32 , s32 , s32 );
extern void FldFilterSetIndex(s32 );

extern s16 datGetDateIndex(void);
extern u8 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 , u32 );
extern u32 datGetFlag(s32 );
extern s32 FldMap_IsCurrentInEitherBand(void);

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_005EFE50[];
extern char D_005EFE68[];
extern s32 FldColorCrossfadeUpdate(u8 *unusedTask);
extern void MT_Scene_CallTaskHook(u8 *task);


extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *, const char *);
extern void sprintf();
extern s32 H_Cdvd_FileExists(void *);
extern void func_00440b68(char *, const char *, s32 );
extern u8 *H_Cdvd_AcquireDirectory(void *, s32 );
extern char D_005EFE78[];
extern char D_005EFED0[];
extern char D_005EFE90[];
extern s32 FldMap_IsInBandB();
extern u8 *iGpffff9db0;
extern char iGpffff9e18;
extern char iGpffff9e20;
extern s32 H_Cdvd_IsFileLoaded(u8 *);
extern u8 *H_Cdvd_LookupRequest(void *, void *);
extern void memcpy(void *, void *, u32 );
extern void memset(void *, s32 , u32 );
extern u8 *kwlnGetCamera(void);
extern void K_View_SetFov(void *, f32 );
extern void func_003e9cb0(void *, void *, s32 );
extern s32 *MT_Scene_GetFrameState(void);
extern void FldCameraAdvanceCurve();
extern void FldFrame_SetViewOffset(s32 , void *);
extern void FldFrame_SetViewDistance(s32 , f32 );
extern void fldCameraSetFollowHeight(s32 , f32 );
extern void FldFrame_SetSlotVector(s32 , s32 , void *);
extern u8 *FldFrame_GetSlotBuffer(s32 );
extern void FldCameraUpdateLookAt(s32 );
extern void kAssertFailMsg(const char *, s32 , void *, void *);
extern void H_Cdvd_Destroy(u8 *);
extern char D_005EFEF0[];

typedef struct CmrVec3 {
    f32 x;
    f32 y;
    f32 z;
} CmrVec3;


/* Source unit: src/promoted/k_fldEnvironment.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/k_fldEnvironment.c; members 00153a60-00154be0 */

extern s32 FldStepEntry(void);
/* Use the packed step's environment state when a step record exists. */
/* FldStepEntry returns a packed step record; only its +0x0D environment-state byte is established here. */
static inline s32 fldEnvironmentEventState(s32 state)
{
    u8 *entry;

    entry = (u8 *)FldStepEntry();
    if (entry == NULL) {
        return state;
    }
    state = *(u8 *)(entry + 0xD);
    return state;
}
/* Create a filter controller with default blend type and intensity. */
// FUN_00153A60
s32 FldFilterCreate(s32 parent) {
    u8 *p;
    s32 result;

    chkmemAllocSiteTag(&D_005EFE50[0], 0x58);
    p = D_008873F4[0](1, 0x14, 0x40000);
    if (p == NULL) {
        return 0;
    }
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(&D_005EFE68[0]), 0xF, 0, 0, FldColorCrossfadeUpdate, MT_Scene_CallTaskHook, (u8 *)(p));
    ((FldFilterWork *)p)->type = 1;
    ((FldFilterWork *)p)->intensity = 0xC8;
    return result;
}

/* Select the filter entry and restart the configured transition. */
// FUN_00153B20
void FldFilterSetPrimary(u8 *task, s32 value) {
    u8 *p = (u8 *)((SdkTask *)task)->work;

    ((FldFilterWork *)p)->index = value;
    fldFilterBeginTransition(value, ((FldFilterWork *)p)->type, ((FldFilterWork *)p)->duration);
}

/* Set the filter render type and restart the configured transition. */
// FUN_00153B60
void FldFilterSetSecondary(u8 *task, s32 value)
{
    u8 *work;

    work = (u8 *)((SdkTask *)task)->work;
    ((FldFilterWork *)work)->type = value;
    fldFilterBeginTransition(((FldFilterWork *)work)->index, value, ((FldFilterWork *)work)->duration);
}

/* Set the crossfade duration and restart the transition. */
// FUN_00153B90
void FldFilterSetTertiary(u8 *task, s32 value)
{
    u8 *work;

    work = (u8 *)((SdkTask *)task)->work;
    ((FldFilterWork *)work)->duration = value;
    fldFilterBeginTransition(((FldFilterWork *)work)->index, ((FldFilterWork *)work)->type, value);
}

/* Update the controller intensity and the active global color multiplier. */
// FUN_00153BD0
void FldFilterSetIntensity(u8 *task, s32 value)
{
    u8 *work;

    work = (u8 *)((SdkTask *)task)->work;
    ((FldFilterWork *)work)->intensity = value;
    FldFilterSetIndex(value);
}

/* Request the environment file for the current field and room, accounting for shared field ranges. */
// FUN_00153C00
s32 FldEnvOpenFile(s32 room) {
    char directory[0x80];
    char path[0x80];
    s32 g;

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0) {
        strcpy(&directory, D_005EFE78);
        if (FldMap_IsInBandB(*(u16 *)iGpffff9db0, room & 0xFFFF) != 0) {
            sprintf(&path, D_005EFE90, *(s32 *)iGpffff9db0 - 0x14, room);
        } else {
            sprintf(&path, D_005EFE90, *(s32 *)iGpffff9db0, room);
        }
        g = *(s32 *)iGpffff9db0;
        if ((g >= 0x33) && (g < 0x3B)) {
            sprintf(&path, D_005EFE90, g - 0x1E, 0);
        }
        if (H_Cdvd_FileExists(&path) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x1A1);
        return (s32)H_Cdvd_AcquireDirectory(&path, 0);
    }
    return 1;
}

/* measured: MATCH 0 via tools/probe_variants.py src/promoted/k_fldEnvironment.c FldEnvironmentLoad (fnalign retail 592/object 592 exact, 0 edits; probe 21->7 via opt_loop_invariants on, 7->4 via P-index 0x10001 loop ((u8 **)P)[i+10] for lw-before-sll, 4->0 via P-index 0x68/0x78 loops ((s32 *)P)[i+26/30]; five follow-up rounds R1 index ties except hoisted-row 257 fail, R2 decl-orders tie plus hoisted-count/P 535 fail, R3 pragmas loop_invariants 7 win vs unroll/schedule tie, R4 index-under-pragma 4 win, R5 68/78 P-index 0 MATCH). De-noised m2c 347 plus rw 363 plus types 3-vs-2 into file idiom. Production live. */
/* Install the versioned environment colors, lighting, fog, rain and mipmap parameters. */
/* Raw versioned environment/camera/light fields retained: the typed-record rewrite produced 2440 bytes for a 2368-byte retail window. */
// FUN_00153D60
#pragma push
/* measured: FldEnvironmentLoad MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 FldEnvironmentLoad(u8 *file, s32 room)
{
    extern u8 *MT_Scene_GetResListHead(s32 resourceType);
    extern void resrcMngSetEnvPrimary(s32 value);
    extern void resrcMngSetEnvSecondary(s32 value);
    extern void resrcMngSetEnvTertiary(s32 value);
    extern void resrcMngSetEnvIntensity(s32 value);
    extern u8 *resrcMngGetColorValue(void);
    extern u8 *resrcMngGetColorTarget(void);
    extern u8 *resrcMngGetTransform(void);
    extern void MT_Scene_SetResVector(u8 *resource, u8 *vector);
    extern s32 FldRainTaskCreate(u8 *file, s32 room, f32 , f32 , f32 , f32 , s32 , s32 , s32 );
    extern s32 FldFogTaskCreate(s32 file, s32 room, f32 , f32 , f32 , s16 , s16 , s16 , s16 , s32 , u8 *);
    extern void FldMipmapSetFloatParam(f32 mipmapK);
    extern void FldMipmapSetFixedParam(f32 value);
    extern u8 *func_003e8180(u8 *file, f32 room);
    extern u8 *func_003e81c0(u8 *file, f32 room);
    extern void kwlnTaskDestroyWithHierarchy(void *task);
    extern void kwlnSetColorRgba(u8 file, u8 room, u8 , u8 );
    extern void kwlnSetColorBytes(u8 file, u8 room, u8 , u8 );
    extern void FldRc_SetClumpVector(void *object, void *scale);
    extern void *mdlGetClump(s32 model);
    extern char D_005EFEB0[];
    extern s32 iGpffffba48;
    extern u8 iGpffffba4c;
    extern u8 iGpffffba50;
    extern u8 iGpffffba54;
    extern u8 iGpffffba58;
    extern u8 iGpffffba5c;
    extern u8 iGpffffba60;
    extern u8 iGpffffba64;
    extern u8 iGpffffba68;
    extern f32 iGpffffba6c;
    typedef struct { f32 x; f32 y; f32 z; f32 w; } F4;
    char lookupSize[4];
    char path[0x4C];
    u8 *data;
    u8 *primaryLight;
    u8 *secondaryLight;
    f32 fogDistance;

    if (file == NULL) {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(file) == 0)) {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0) {
        data = *(u8 **)(file + 0x110);
    } else {
        sprintf(&path, D_005EFEB0, *(s32 *)iGpffff9db0, room);
        if (FldMap_IsInBandB(*(u16 *)iGpffff9db0, room & 0xFFFF) != 0) {
            sprintf(&path, D_005EFEB0, *(s32 *)iGpffff9db0 - 0x14, room);
        }
        {
            s32 g = *(s32 *)iGpffff9db0;
            if ((g >= 0x33) && (g < 0x3B)) {
                sprintf(&path, D_005EFEB0, g - 0x1E, 0);
            }
        }
        data = H_Cdvd_LookupRequest(&path, &lookupSize);
        if (data == NULL) {
            return 1;
        }
        if (data == NULL) {
            kAssertFailMsg(D_005EFE50, 0x1E3, &iGpffff9e20, &path);
        }
    }
    primaryLight = MT_Scene_GetResListHead(4);
    secondaryLight = MT_Scene_GetResListHead(5);
    resrcMngSetEnvPrimary(*(u8 *)(data + 8));
    resrcMngSetEnvSecondary(*(u8 *)(data + 9));
    resrcMngSetEnvTertiary(*(u8 *)(data + 0xA));
    resrcMngSetEnvIntensity(*(u8 *)(data + 0xB));
    if (*(u8 *)(data + 0xF) == 1) {
        iGpffffba48 = 1;
    } else {
        iGpffffba48 = 0;
    }
    iGpffffba4c = *(u8 *)(data + 0xC);
    iGpffffba50 = *(u8 *)(data + 0xD);
    iGpffffba54 = *(u8 *)(data + 0xE);
    iGpffffba58 = 0;
    iGpffffba5c = *(u8 *)(data + 0xC);
    iGpffffba60 = *(u8 *)(data + 0xD);
    iGpffffba64 = *(u8 *)(data + 0xE);
    iGpffffba68 = 0;
    kwlnSetColorRgba(*(u8 *)(data + 0xC), *(u8 *)(data + 0xD), *(u8 *)(data + 0xE), 0);
    kwlnSetColorBytes(*(u8 *)(data + 0xC), *(u8 *)(data + 0xD), *(u8 *)(data + 0xE), 0);
    func_003e81c0(kwlnGetCamera(), *(f32 *)(data + 0x14));
    fogDistance = *(f32 *)(data + 0x10);
    *(f32 *)(kwlnGetCamera() + 0x88) = fogDistance;
    kwlnGetCamera();
    if ((u32)*(s32 *)(data + 4) > 0x10003U) {
        if (*(f32 *)(data + 0x18) > 1.0f) {
            func_003e8180(kwlnGetCamera(), *(f32 *)(data + 0x18));
        }
        if (*(f32 *)(data + 0x18) == 50.0f) {
            func_003e8180(kwlnGetCamera(), 100.0f);
        }
        if (*(u8 *)(data + 0x1FF) == 0xFF) {
            kwlnSetColorRgba(*(u8 *)(data + 0x1FC), *(u8 *)(data + 0x1FD), *(u8 *)(data + 0x1FE), 0);
            kwlnSetColorBytes(*(u8 *)(data + 0x1FC), *(u8 *)(data + 0x1FD), *(u8 *)(data + 0x1FE), 0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10004U) {
        iGpffffba6c = *(f32 *)(data + 0x200);
    } else {
        iGpffffba6c = *(f32 *)(data + 0x14);
    }
    {
        u8 *dst = resrcMngGetColorValue();
        *(F4 *)dst = *(F4 *)(data + 0x1C);
    }
    {
        u8 *dst = resrcMngGetColorTarget();
        *(F4 *)dst = *(F4 *)(data + 0x2C);
    }
    {
        u8 *dst = resrcMngGetTransform();
        s32 *src = (s32 *)(data + 0x40);
        s32 count = 8;
        s32 first;
        s32 second;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)dst = first;
            *(s32 *)(dst + 4) = second;
            dst += 8;
        } while (count > 0);
    }
    if (secondaryLight != NULL) {
        *(F4 *)(secondaryLight + 0x140) = *(F4 *)(data + 0x80);
        *(F4 *)(secondaryLight + 0x150) = *(F4 *)(data + 0x90);
        {
            s32 *src = (s32 *)(data + 0xA0);
            u8 *dst = secondaryLight + 0x160;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        *(F4 *)(secondaryLight + 0x1A0) = *(F4 *)(data + 0xE0);
        {
            s32 *src = (s32 *)(data + 0xF0);
            u8 *dst = secondaryLight + 0x1B0;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        if ((u32)*(s32 *)(data + 4) > 0x10002U) {
            *(CmrVec3 *)(secondaryLight + 0x1F0) = *(CmrVec3 *)(data + 0x1F0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10000U) {
        s32 i;
        for (i = 0; i < *(s32 *)(iGpffff9db0 + 0x24); i++) {
            *(CmrVec3 *)(((u8 **)iGpffff9db0)[i + 10] + 0xA24) = *(CmrVec3 *)(data + 0x130);
            MT_Scene_SetResVector(((u8 **)iGpffff9db0)[i + 10], ((u8 **)iGpffff9db0)[i + 10] + 0xA24);
        }
    }
    if (((u32)*(s32 *)(data + 4) > 0x10001U) && (primaryLight != NULL)) {
        *(F4 *)(primaryLight + 0x140) = *(F4 *)(data + 0x13C);
        *(F4 *)(primaryLight + 0x150) = *(F4 *)(data + 0x14C);
        {
            s32 *src = (s32 *)(data + 0x160);
            u8 *dst = primaryLight + 0x160;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        *(F4 *)(primaryLight + 0x1A0) = *(F4 *)(data + 0x1A0);
        {
            s32 *src = (s32 *)(data + 0x1B0);
            u8 *dst = primaryLight + 0x1B0;
            s32 count = 8;
            s32 first;
            s32 second;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)dst = first;
                *(s32 *)(dst + 4) = second;
                dst += 8;
            } while (count > 0);
        }
        if ((u32)*(s32 *)(data + 4) > 0x10002U) {
            *(CmrVec3 *)(primaryLight + 0x1F0) = *(CmrVec3 *)(data + 0x1F0);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10002U) {
        u8 *tmp1 = MT_Scene_GetResListHead(1);
        u8 *tmp3 = MT_Scene_GetResListHead(3);
        s32 i;
        for (i = 0; i < *(s32 *)(iGpffff9db0 + 0x24); i++) {
            u8 *base = *(u8 **)(iGpffff9db0 + i * 4 + 0x28);
            *(CmrVec3 *)(base + 0xA30) = *(CmrVec3 *)(data + 0x1F0);
        }
        while (tmp1 != NULL) {
            FldRc_SetClumpVector(mdlGetClump(*(s32 *)(tmp1 + 0x164)), data + 0x1F0);
            tmp1 = *(u8 **)(tmp1 + 0x138);
        }
        while (tmp3 != NULL) {
            if ((*(u32 *)(tmp3 + 0x28) & 0x10000000) != 0) {
                FldRc_SetClumpVector(mdlGetClump(*(s32 *)(tmp3 + 0x164)), data + 0x1F0);
            }
            tmp3 = *(u8 **)(tmp3 + 0x138);
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10005U) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (((s32 *)iGpffff9db0)[i + 26] != 0) {
                kwlnTaskDestroyWithHierarchy((void *)((s32 *)iGpffff9db0)[i + 26]);
                ((s32 *)iGpffff9db0)[i + 26] = 0;
            }
            {
                u8 *p = data + i * 0x24;
                if (*(s32 *)(p + 0x204) != 0) {
                    ((s32 *)iGpffff9db0)[i + 26] = FldRainTaskCreate(0, *(s32 *)(p + 0x208), *(f32 *)(p + 0x20C), *(f32 *)(p + 0x210), *(f32 *)(p + 0x214), *(f32 *)(p + 0x218), *(s32 *)(p + 0x21C), *(s32 *)(p + 0x220), *(s32 *)(p + 0x224));
                }
            }
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10006U) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (((s32 *)iGpffff9db0)[i + 30] != 0) {
                kwlnTaskDestroyWithHierarchy((void *)((s32 *)iGpffff9db0)[i + 30]);
                ((s32 *)iGpffff9db0)[i + 30] = 0;
            }
            {
                u8 *p = data + i * 0x38;
                if (*(s32 *)(p + 0x294) != 0) {
                    ((s32 *)iGpffff9db0)[i + 30] = FldFogTaskCreate(0, *(s32 *)(p + 0x298), *(f32 *)(p + 0x29C), *(f32 *)(p + 0x2A0), *(f32 *)(p + 0x2A4), *(s16 *)(p + 0x2A8), *(s16 *)(p + 0x2AA), *(s16 *)(p + 0x2AC), *(s16 *)(p + 0x2AE), *(s32 *)(p + 0x2B0), p + 0x2B4);
                }
            }
        }
    }
    if ((u32)*(s32 *)(data + 4) > 0x10007U) {
        FldMipmapSetFloatParam(*(f32 *)(data + 0x374));
        FldMipmapSetFixedParam(*(f32 *)(data + 0x378));
    }
    if (FldRc_GetLoadSource() == 0) {
        H_Cdvd_Destroy(file);
    }
    return 1;
}

#pragma pop
/* Resolve the environment state using the current calendar condition. */
// FUN_001546A0
s32 FldEnvStateFromCalendar(s32 fieldKind, s32 baseState)
{
    return FldEnvResolveState(fieldKind, baseState, (s8)calGetDayEntryByPhase(datGetDateIndex(), datGetTimeSlot() & 0xFF));
}

/* Combine field-specific base-state rules with time-slot and calendar-condition offsets. */
// FUN_00154720
s32 FldEnvResolveState(s32 fieldKind, s32 baseState, s32 condition)
{
    s32 environmentState;
    s32 period;
    s32 result;
    s32 state;
    s32 kind;
    s32 currentPeriod;

    state = (u16)baseState;
    environmentState = state;
    currentPeriod = datGetTimeSlot() & 0xFF;
    kind = (u16)fieldKind;
    if (kind == 0x1C && state == 2) {
        if (datGetFlag(0xF52) == 1) {
            result = 3;
        } else {
            result = 2;
        }
        return result;
    }
    if (kind >= 0x14 && kind < 0x28) {
        return state;
    }
    if ((kind < 0x14 || kind >= 0x28) && FldMap_IsCurrentInEitherBand() == 1) {
        return fldEnvironmentEventState(state);
    }
    /* Only kind 6 clamps the base state; default preserves it. */
    switch (kind) {
    case 4:
        return state;
    case 6:
        if (state < 6) {
            environmentState = 1;
        }
        break;
    case 7:
        if (state != 1) {
            environmentState = 2;
        }
        break;
    case 8:
        if (state == 2) {
            environmentState = 1;
        }
        if ((s32)environmentState > 2 && (s32)environmentState <= 8) {
            return environmentState;
        }
        break;
    case 9:
        if (state != 1 && state != 4) {
            return state;
        }
        break;
    case 10:
        if (state == 4) {
            environmentState = 3;
        }
        break;
    case 11:
        if (state == 2) {
            return state;
        }
        break;
    case 12:
        if (state == 4) {
            return state;
        }
        break;
    case 13:
        if (state != 8) {
            return state;
        }
        break;
    case 14:
    case 15:
    case 16:
        return state;
    case 17:
        if (state == 2) {
            environmentState = 1;
        }
        break;
    default:
        break;
    }
    if (datGetFlag(0x8A) == 1 &&
        (((kind != 7 || state != 2) && (kind != 7 || state != 3)) ||
         (currentPeriod & 0xFF) != 5)) {
        switch (condition) {
        case 0:
        case 2:
            environmentState += 0x320;
            break;
        case 1:
        case 3:
        case 4:
            environmentState += 0x384;
            break;
        }
    } else {
        switch (condition) {
        case 0:
            period = currentPeriod & 0xFF;
            if (period < 4) {
                break;
            }
            if (period < 5) {
                environmentState += 0x64;
            } else if (period == 5) {
                environmentState += 0xC8;
            }
            break;
        case 2:
            period = currentPeriod & 0xFF;
            if (period < 5) {
                environmentState += 0x190;
            } else if (period == 5) {
                environmentState += 0x1F4;
            }
            break;
        case 1:
        case 3:
        case 4:
            period = currentPeriod & 0xFF;
            if (period < 5) {
                environmentState += 0x258;
            } else if (period == 5) {
                environmentState += 0x2BC;
            }
            break;
        }
    }
    return environmentState;
}

/* Request the current field/room camera file when loading from disc. */
/* The scene-global root is not a camera record; its first two words supply field and room for the path. */
// FUN_00154B10
s32 FldCamOpenFile(void) {
    char directory[0x80];
    char path[0x80];

    if (*(s32 *)iGpffff9db0 == -1) {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0) {
        strcpy(&directory, D_005EFE78);
        sprintf(&path, D_005EFED0, *(s32 *)(iGpffff9db0 + 0), *(s32 *)(iGpffff9db0 + 4));
        if (H_Cdvd_FileExists(&path) == 0) {
            return 0;
        }
        func_00440b68(&iGpffff9e18, D_005EFE50, 0x571);
        return (s32)H_Cdvd_AcquireDirectory(&path, 0);
    }
    return 1;
}

/* Read a versioned camera record into caller outputs or apply it directly to the active field camera. */
/* Raw camera record fields retained: the typed-record rewrite produced 1164/1168 bytes but 507 differing instruction bytes. */
// FUN_00154BE0
s32 FldCamReadRecord(u8 *file, u8 *cameraMatrixOut, u8 *slotMatrixOut, f32 *fovOut, s32 *curveOut,
                  u8 *viewOffsetOut, f32 *viewDistanceOut, f32 *cameraValueOut, s32 *slotIdsOut, s32 *slotVectorsOut)
{
    char lookupSize[4];
    char path[0x4C];
    u8 *data;

    if (file == 0) {
        return 1;
    }
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded(file) == 0)) {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0) {
        data = *(u8 **)(file + 0x110);
    } else {
        sprintf(&path, D_005EFEF0,
                      *(s32 *)iGpffff9db0, *(s32 *)(iGpffff9db0 + 4));
        data = H_Cdvd_LookupRequest(&path, &lookupSize);
        if (data == 0) {
            return 1;
        }
        if (data == 0) {
            kAssertFailMsg(D_005EFE50, 0x5A1, &iGpffff9e20, &path);
        }
    }
    if (cameraMatrixOut != 0) {
        s32 *src;
        s32 count;
        s32 first;
        s32 second;

        src = (s32 *)(data + 0x10);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)cameraMatrixOut = first;
            *(s32 *)(cameraMatrixOut + 4) = second;
            cameraMatrixOut += 8;
        } while (count > 0);
        *fovOut = *(f32 *)(data + 8);
        *curveOut = *(u16 *)(data + 0x50);
        *(CmrVec3 *)viewOffsetOut = *(CmrVec3 *)(data + 0x54);
        *viewDistanceOut = *(f32 *)(data + 0x60);
        *cameraValueOut = *(f32 *)(data + 0x64);
        if (*(u32 *)(data + 4) > 0x10000U) {
            memcpy(slotIdsOut, data + 0x68, 0x20);
            memcpy(slotVectorsOut, data + 0x88, 0x180);
        } else {
            memset(slotIdsOut, 0, 0x20);
            memset(slotVectorsOut, 0, 0x180);
        }
        if (*(u32 *)(data + 4) > 0x10001U) {
            src = (s32 *)(data + 0x210);
            count = 8;
            do {
                first = src[0];
                second = src[1];
                src += 2;
                count--;
                *(s32 *)slotMatrixOut = first;
                *(s32 *)(slotMatrixOut + 4) = second;
                slotMatrixOut += 8;
            } while (count > 0);
        } else {
            *(f32 *)(slotMatrixOut + 0x28) = 1.0f;
            *(f32 *)(slotMatrixOut + 0x14) = 1.0f;
            *(f32 *)(slotMatrixOut + 0) = 1.0f;
            *(f32 *)(slotMatrixOut + 0x10) = 0.0f;
            *(f32 *)(slotMatrixOut + 8) = 0.0f;
            *(f32 *)(slotMatrixOut + 4) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x24) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x20) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x18) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x38) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x34) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x30) = 0.0f;
            *(s32 *)(slotMatrixOut + 0xC) |= 0x20003;
        }
    } else {
        s32 i;
        s16 id;
        s32 *src;
        s32 count;
        u8 *dst;
        s32 first;
        s32 second;

        K_View_SetFov(kwlnGetCamera(), *(f32 *)(data + 8));
        func_003e9cb0((void *)*(s32 *)(kwlnGetCamera() + 4),
                      data + 0x10, 0);
        FldCameraAdvanceCurve(MT_Scene_GetFrameState()[1], *(u16 *)(data + 0x50));
        FldFrame_SetViewOffset(MT_Scene_GetFrameState()[1], data + 0x54);
        FldFrame_SetViewDistance(MT_Scene_GetFrameState()[1], *(f32 *)(data + 0x60));
        fldCameraSetFollowHeight(MT_Scene_GetFrameState()[1], *(f32 *)(data + 0x64));
        for (i = 0; i < 0x20; i++) {
            id = *(s8 *)(data + 0x68 + i);
            if (id <= -1) {
                goto CMR_loop_skip;
            }
            FldFrame_SetSlotVector(MT_Scene_GetFrameState()[1], id,
                          data + i * 0xC + 0x88);
CMR_loop_skip:
            ;
        }
        if ((u32)*(s32 *)(data + 4) < 0x10002U) {
            *(f32 *)(slotMatrixOut + 0x28) = 1.0f;
            *(f32 *)(slotMatrixOut + 0x14) = 1.0f;
            *(f32 *)(slotMatrixOut + 0) = 1.0f;
            *(f32 *)(slotMatrixOut + 0x10) = 0.0f;
            *(f32 *)(slotMatrixOut + 8) = 0.0f;
            *(f32 *)(slotMatrixOut + 4) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x24) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x20) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x18) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x38) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x34) = 0.0f;
            *(f32 *)(slotMatrixOut + 0x30) = 0.0f;
            *(s32 *)(slotMatrixOut + 0xC) |= 0x20003;
        }
        dst = FldFrame_GetSlotBuffer(MT_Scene_GetFrameState()[1]);
        src = (s32 *)(data + 0x210);
        count = 8;
        do {
            first = src[0];
            second = src[1];
            src += 2;
            count--;
            *(s32 *)dst = first;
            *(s32 *)(dst + 4) = second;
            dst += 8;
        } while (count > 0);
        FldCameraUpdateLookAt(MT_Scene_GetFrameState()[1]);
    }
    if (FldRc_GetLoadSource() == 0) {
        H_Cdvd_Destroy(file);
    }
    return 1;
}

