#include "mt_scene_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Source unit: src/Kosaka/Field/k_fldFBN.c */
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_model_internal.h"
#include "scene_resource_internal.h"
#include "h_cdvd_request_internal.h"
#include "member_access.h"

typedef struct FbnEntry
{
    s32 kind;      /* 0x00 */
    s32 field_4;   /* 0x04 */
    s32 field_8;   /* 0x08 */
    s32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    s32 field_14;  /* 0x14 */
    s32 field_18;  /* 0x18 */
} FbnEntry;

typedef struct FbnMatrix
{
    s32 m[16];
} FbnMatrix;

/* Fixed FBN header; part records use the stride stored at +0x0C. */
typedef struct FbnHeader {
    u32 magic;
    u32 version;
    u32 partCount;
    union { s32 partStride; u32 unsignedPartStride; };
    u32 placementCount;
    u32 unk14;
    u8 parts[1];
} FbnHeader;
typedef struct FbnNpcSelection { u8 pad00[0xC]; s32 entryKey; } FbnNpcSelection;
typedef struct FbnPlacement {
    u8 pad00[0x10];
    FbnMatrix matrix;
    u16 id;
    u8 pad52[0xE];
} FbnPlacement;

typedef struct FldPart
{
    u16 field_0;   /* 0x00 */
    u16 field_2;   /* 0x02 */
    u16 type;      /* 0x04 */
    u16 flags;     /* 0x06 */
    u16 field_8;   /* 0x08 */
    u8  field_A;   /* 0x0A */
    u8  field_B;   /* 0x0B */
    f32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    u8 pad14[0xC];
    union {
        FbnMatrix matrix; /* 0x20: transform copied into the placed model. */
        struct { u8 pad20[0x30]; s32 field_50; u8 pad54[0xC]; };
    };
    u8  field_60;  /* 0x60 */
    u8  field_61;  /* 0x61 */
    u16 field_62;  /* 0x62 */
    u8  pad64[0xC];
    f32 field_70;  /* 0x70 */
} FldPart;

typedef struct AnimEntry
{
    u16 field_0;   /* 0x00 */
    u16 field_2;   /* 0x02 */
    u16 field_4;   /* 0x04 */
    u16 field_6;   /* 0x06 */
    s32 field_8;   /* 0x08 */
    s32 field_C;   /* 0x0C */
    s32 field_10;  /* 0x10 */
    s32 field_14;  /* 0x14 */
    s32 field_18;  /* 0x18 */
    s32 field_1C;  /* 0x1C */
} AnimEntry;

typedef struct AnimEntry2
{
    u16 field_0;   /* 0x00 */
    u8  pad[0x66];
    u16 field_68;  /* 0x68 */
    u16 field_6A;  /* 0x6A */
} AnimEntry2;

/* NPC resources share the scene-character prefix; FBN application proves the tail. */
typedef struct FbnNpcResource {
    SceneCharacterUpdate base;
    u8 pad168[0xB8];
    s16 mode;
    u8 flag222;
    u8 pad223;
    s32 parameter;
    union { u8 *frameTask; s32 frameTaskValue; };
    union { u32 *shadowModel; u8 *shadowModelBytes; };
    u8 *shadowTask;
    s32 kind;
    u8 pad238[8];
    FbnMatrix initialMatrix;
    s32 secondaryEntry;
    s32 sceneEntry;
    union { s32 scriptBufferValue; void *scriptBuffer; };
    u32 scriptSize;
    s32 unk290;
    s32 controller;
    u16 parameter298;
    u8 pad29A[2];
    u8 parameters[0xC0];
    f32 parameter35C;
} FbnNpcResource;

extern s32 FldRc_GetLoadSource(void);
extern s16 datGetDateIndex(void);
extern u8 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 , u32 );
extern u32 datGetFlag(s32 );
extern s32 MT_Scene_CreateRes08(u16 );
extern void SceneDraw_ResetResource(u16 );
extern void SceneDraw_SetResVisibleChecked(u16 , u32 );
extern f32 KDraw_MatrixPitchDeg(u8 *);
extern f32 KDraw_MatrixYawDeg(u8 *);
extern f32 KDraw_MatrixRollDeg(u8 *);
extern void *NpcTable_FindActiveEntry(void);
extern u16 *NpcTable_GetMarkedEntry(s32 );
extern void NpcTable_RequestBlockTable(u8 *, s32 );
extern s32 NpcTable_InstallBlockTable(u8 *, s32 );
extern void FldStepReleaseHandle(u8 *);
extern u16 *FldStepFindEmptySlot(u32 );
extern u8 *fldStepFindEligibleRecord(u16 *);
extern void FldFrameTask_SetHeight(u8 *, f32 );
extern void FldShadow_SetRingParticles(u8 *, f32 );
extern s32 FldNpcControlTaskCreate(s32 , s32 );
extern void *RwMatrixUpdate(void *);
extern void memcpy(void *, void *, u32 );
extern s32 sprintf(char *destination, const char *format, ...);
extern char *strcpy(char *destination, const char *source);
extern s32 func_00440b68(const char *format, ...);
extern void chkmemAllocSiteTag(void *, s32 );
extern u32 H_Cdvd_FileExists(const char *path);
extern u8 *H_Cdvd_AcquireDirectory(void *, s32 );
extern u32 H_Cdvd_Destroy(void *);
typedef struct HCdvd HCdvd;
extern u32 H_Cdvd_IsFileLoaded(HCdvd *);
extern u8 *H_Cdvd_LookupRequest(void *, u32 *);
extern void kAssertFailMsg(const char *file, s32 line, const char *message, ...);
extern void *mdlCreateModelObjectFromData(u32 , u16 , void *, u32 );
extern s32 mdlPrepareModel(u8 *);
extern u32 *mdlCloneModelObject(u8 *);
extern void mdlAdvanceModelFromFlags(u8 *);
extern void mdlScale(void *, void *, s32 );
extern void *mdlGetMatrix(void *);
extern void *mdlTranslateMatrix(void *matrix, const void *translation, s32 combineOp);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb2a8;
extern void **iGpffffb2a4;
extern FbnEntry *iGpffffb2a0;
extern s32 D_0076439C;
extern s32 D_00764340;
extern s32 D_00764364;
extern u32 D_00764388;
extern s32 D_0076436C;
extern char D_00762FD0;
extern char D_00762FD8;
extern char D_005F1068[];
extern char D_005F1078[];
extern char D_005F1090[];
extern char D_005F10B0[];
extern char D_005F10D0[];

/* Reset the FBN work tables and request the selected field/room variant. */
// FUN_0015E870
u8 *FldFbnOpenData(s32 field, s32 room, s16 variant)
{
    char directory[0x80];
    char path[0x80];

    iGpffffb2a8 = 0;
    iGpffffb2a4 = 0;
    iGpffffb2a0 = 0;
    if (FldRc_GetLoadSource() == 0)
    {
        strcpy(directory, D_005F1078);
        sprintf(path, D_005F1090, field & 0xFFFF, room & 0xFFFF, variant);
        if (H_Cdvd_FileExists(path) == 0)
        {
            return NULL;
        }
        func_00440b68(&D_00762FD0, D_005F1068, 0xD4);
        return H_Cdvd_AcquireDirectory(&path, 0);
    }
    return (u8 *)1;
}


/* Entry addresses are offsets in the loaded 28-byte work table. */
#define FBN_ENTRY(i) ((FbnEntry *)((u8 *)iGpffffb2a0 + (i) * sizeof(FbnEntry)))
/* measured: loop invariants retain cached search bounds; the lifetime pass
 * separates the loading count from the later transform index. Together
 * with source-ordered index updates this matches all 424 retail words. */
/* Resolve FBN model references and eligible NPC substitutions, then create placed transform resources. */
/* The FBN header supplies the runtime part stride; the typed NPC tail is separate from the packed part layout. */
// FUN_0015E960
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
s32 FldFbnReadTable(u8 *file, u8 **cachedDataOut, s32 field, s32 room, s32 variant)
{
    FbnHeader *header;
    u32 size;
    SVec3 angles;
    char path[0x40];
    u32 out;
    u8 *fbn;
    u8 *p;
    u32 i;
    u32 j;
    u32 k;

    D_0076439C = 0;
    if (file == NULL) {
        return 1;
    }
    *cachedDataOut = NULL;
    if ((FldRc_GetLoadSource() == 0) && (H_Cdvd_IsFileLoaded((HCdvd *)file) == 0)) {
        return 0;
    }
    if (FldRc_GetLoadSource() == 0) {
        fbn = ((HCdvdRequest *)(file))->data;
    } else {
        sprintf(path, D_005F10B0, field & 0xFFFF, room & 0xFFFF, (s16)variant);
        fbn = H_Cdvd_LookupRequest(path, &size);
        if (fbn == NULL) {
            return 1;
        }
        if (fbn == NULL) {
            kAssertFailMsg(D_005F1068, 0x10D, &D_00762FD8, path);
        }
        *cachedDataOut = fbn;
    }
    iGpffffb2a8 = ((FbnHeader *)(fbn))->partCount;
    if (iGpffffb2a8 != 0) {
        u8 *base;

        chkmemAllocSiteTag(D_005F1068, 0x117);
        base = (u8 *)D_008873F4;
        iGpffffb2a4 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, MEMBER(u32, fbn, FbnHeader, partCount) * sizeof(void *), 0x40000);
        chkmemAllocSiteTag(D_005F1068, 0x118);
        iGpffffb2a0 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, MEMBER(u32, fbn, FbnHeader, partCount) * sizeof(FbnEntry), 0x40000);
    }
    p = fbn + 0x18;
    i = 0;
    out = 0;
    header = (FbnHeader *)fbn;
    for (; i < header->partCount; ) {
        u32 type = ((FldPart *)p)->type;
        if ((type == 4) && (((FldPart *)p)->flags == 0xFFFF)) {
            if (D_00764340 == 1) {
                iGpffffb2a4[out] = mdlCreateModelObjectFromData(4, 0xFFFF, D_005F10D0, 0);
                FBN_ENTRY(out)->field_8 = i;
                out++;
            }
        } else {
            iGpffffb2a4[out] = mdlFindOrCreateModelObject(type, ((FldPart *)p)->flags, 0);
            FBN_ENTRY(out)->field_8 = i;
            out++;
        }
        i++;
        p += ((FbnHeader *)(fbn))->partStride;
    }
    if (D_00764340 == 0) {
        u8 *head = NpcTable_FindActiveEntry();

        if (head != NULL) {
            AnimEntry *ae = (AnimEntry *)NpcTable_GetMarkedEntry(((FbnNpcSelection *)(head))->entryKey);

            for (j = 0; ae->field_0 != 0xFFFF; j++, ae++) {
                s32 kind;
                u8 *q;
                u32 num;

                if ((ae->field_10 != -1) && (datGetFlag(ae->field_10) == 1)) {
                    continue;
                }
                kind = ae->field_18;
                if (kind == 1) {
                    if ((s8)calGetDayEntryByPhase(datGetDateIndex(), datGetTimeSlot()) % 2 != 0) {
                        continue;
                    }
                } else if (kind == 2) {
                    if ((s8)calGetDayEntryByPhase(datGetDateIndex(), datGetTimeSlot()) % 2 == 0) {
                        continue;
                    }
                }
                q = fbn + 0x18;
                k = 0;
                num = MEMBER(u32, fbn, FbnHeader, partCount);
                for (; k < num; k++, q += ((FbnHeader *)(fbn))->partStride) {
                    if ((((FldPart *)q)->type == 4) && (((FldPart *)q)->flags == 0xFFFF)
                        && (((FldPart *)q)->field_8 == (u16)((ae->field_0 & 0x3FF) | 0xC00))) {
                        if ((ae->field_2 != 0) || (ae->field_4 != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = mdlFindOrCreateModelObject(ae->field_2, ae->field_4, 0);
                            FBN_ENTRY(out)->kind = 1;
                            FBN_ENTRY(out)->field_4 = (s32)ae;
                            FBN_ENTRY(out)->field_8 = k;
                            out++;
                        }
                        break;
                    }
                }
            }
        }
        for (k = 0; k < D_00764388; k++) {
            AnimEntry2 *e2 = (AnimEntry2 *)fldStepFindEligibleRecord(FldStepFindEmptySlot(k));

            if (e2 != NULL) {
                u8 *q = fbn + 0x18;
                u32 num;

                j = 0;
                num = MEMBER(u32, fbn, FbnHeader, partCount);
                for (; j < num; j++, q += ((FbnHeader *)(fbn))->partStride) {
                    if ((((FldPart *)q)->type == 4) && (((FldPart *)q)->flags == 0xFFFF)
                        && (((FldPart *)q)->field_8 == (u16)((e2->field_0 & 0x3FF) | 0xC00))) {
                        if ((e2->field_68 != 0) || (e2->field_6A != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = mdlFindOrCreateModelObject(e2->field_68, e2->field_6A, 0);
                            FBN_ENTRY(out)->kind = 2;
                            FBN_ENTRY(out)->field_4 = (s32)e2;
                            FBN_ENTRY(out)->field_8 = j;
                            FBN_ENTRY(out)->field_10 = k;
                            NpcTable_RequestBlockTable((u8 *)FBN_ENTRY(out), k);
                            out++;
                        }
                        break;
                    }
                }
            }
        }
        iGpffffb2a8 = out;
    }
    for (out = 0; out < ((FbnHeader *)(fbn))->placementCount; ) {
        u16 id = MT_Scene_CreateRes08(((FbnPlacement *)(p))->id & 0x3FF);

        angles.x = KDraw_MatrixPitchDeg(p + 0x10);
        angles.y = KDraw_MatrixYawDeg(p + 0x10);
        angles.z = KDraw_MatrixRollDeg(p + 0x10);
        MT_Scene_SetResPlacement(id, p + 0x40, (u8 *)&angles);
        out++;
        p += 0x60;
    }
    return 1;
}
#pragma pop

/* A 64-byte transform record copied between FBN parts and model matrices. */


/* Retail passes the yaw at sp+0xC4 (0x0015F224) to the four-argument
 * rotation wrapper before the first yaw store at 0x0015F344, so the first
 * iteration passes an uninitialised angle. The C keeps that read of
 * angles.y exactly as retail does; later iterations see the previous
 * kind-0 store. */
/* Wait for models and NPC blocks, instantiate their resources, and release the temporary FBN tables. */
/* FBN versions select different part tails; FbnNpcResource describes the distinct runtime resource allocation. */
// FUN_0015F000
s32 FldFbnApplyTable(u8 *file, u8 *cachedData)
{
    s32 n;
    s32 i;
    u8 *fbn;
    u8 *base;

    if (file == NULL) {
        return 1;
    }
    for (n = 0; n < iGpffffb2a8; n++) {
        if (NpcTable_InstallBlockTable((u8 *)FBN_ENTRY(n), iGpffffb2a0[n].field_10) == 0) {
            return 0;
        }
        if ((FBN_ENTRY(n)->kind == 0) && (mdlPrepareModel((u8 *)iGpffffb2a4[n]) == 0)) {
            return 0;
        }
    }
    if (FldRc_GetLoadSource() == 0) {
        fbn = ((HCdvdRequest *)(file))->data;
    } else if (cachedData != NULL) {
        fbn = cachedData;
    } else {
        return 1;
    }
    base = fbn + 0x18;
    for (i = 0; i < iGpffffb2a8; i++) {
        u8 mode = 3;
        SVec3 angles;
        SVec3 axis = { 0.0f, 1.0f, 0.0f };
        SVec3 scale;
        u8 *rec;
        u16 rid;
        u8 *res;
        s32 kind;
        f32 *size;

        rec = &base[((FbnHeader *)(fbn))->unsignedPartStride * FBN_ENTRY(i)->field_8];
        if (((FbnHeader *)(fbn))->version > 0x10000) {
            mode = rec[0x60];
        }
        rid = MT_Scene_CreateModelNpcShadowRes(((FldPart *)rec)->field_8 & 0x3FF, mode, (s32)iGpffffb2a4[i]);
        SceneDraw_ResetResource(rid);
        SceneDraw_SetResVisibleChecked(rid, 1);
        res = MT_Scene_GetRes(rid);
        size = (f32 *)(rec + 0xC);
        FldFrameTask_SetHeight(((FbnNpcResource *)(res))->frameTask, *size);
        FldShadow_SetRingParticles(((FbnNpcResource *)(res))->shadowTask, 40.0f);
        scale.z = scale.y = scale.x = *size;
        ((FbnNpcResource *)(res))->shadowModel = mdlCloneModelObject((u8 *)D_00764364);
        /* Retail passes the yaw slot before this iteration writes it. */
        mdlRotateMatrix(MEMBER(u32 *, res, FbnNpcResource, shadowModel), &axis, angles.y, 2);
        mdlScale(MEMBER(u32 *, res, FbnNpcResource, shadowModel), &scale, 2);
        if (rec[0xB] & 1) {
            ((FbnNpcResource *)(res))->base.base.flags |= 0x80000000;
        } else {
            ((FbnNpcResource *)(res))->base.base.flags &= 0x7FFFFFFF;
        }
        ((FbnNpcResource *)(res))->mode = rec[0xA];
        ((FbnNpcResource *)(res))->parameter = ((FldPart *)rec)->field_10;
        res[0x222] = rec[0x61];
        ((FbnNpcResource *)(res))->parameter298 = ((FldPart *)rec)->field_62;
        memcpy(res + 0x29C, rec + 0x74, 0xC0);
        ((FbnNpcResource *)(res))->parameter35C = ((FldPart *)rec)->field_70;
        kind = FBN_ENTRY(i)->kind;
        ((FbnNpcResource *)(res))->kind = kind;
        if (kind == 0) {
            u8 *mtx;

            mdlAdvanceModelFromFlags(MEMBER(u8 *, res, FbnNpcResource, shadowModelBytes));
            mtx = rec + 0x20;
            *(FbnMatrix *)mdlGetMatrix(iGpffffb2a4[i]) = *(FbnMatrix *)mtx;
            angles.x = KDraw_MatrixPitchDeg(mtx);
            angles.y = KDraw_MatrixYawDeg(mtx);
            angles.z = KDraw_MatrixRollDeg(mtx);
            MT_Scene_SetResPlacement(rid, rec + 0x50, (u8 *)&angles);
            RwMatrixUpdate(mdlGetMatrix(iGpffffb2a4[i]));
        } else if (kind == 1) {
            ((FbnNpcResource *)(res))->secondaryEntry = FBN_ENTRY(i)->field_4;
            mdlTranslateMatrix(MEMBER(u8 *, res, FbnNpcResource, shadowModelBytes), rec + 0x50, 2);
            mdlAdvanceModelFromFlags(MEMBER(u8 *, res, FbnNpcResource, shadowModelBytes));
            MEMBER(u32, res, FbnNpcResource, base.base.flags) &= ~0x10000000;
            ((FbnNpcResource *)(res))->initialMatrix = ((FldPart *)(rec))->matrix;
            ((FbnNpcResource *)(res))->controller = FldNpcControlTaskCreate(MEMBER(s32, res, FbnNpcResource, frameTaskValue), (s32)res);
        } else if (kind == 2) {
            ((FbnNpcResource *)(res))->sceneEntry = FBN_ENTRY(i)->field_4;
            mdlTranslateMatrix(MEMBER(u8 *, res, FbnNpcResource, shadowModelBytes), rec + 0x50, 2);
            mdlAdvanceModelFromFlags(MEMBER(u8 *, res, FbnNpcResource, shadowModelBytes));
            MEMBER(u32, res, FbnNpcResource, base.base.flags) &= ~0x10000000;
            ((FbnNpcResource *)(res))->initialMatrix = ((FldPart *)(rec))->matrix;
            ((FbnNpcResource *)(res))->controller = FldNpcControlTaskCreate(MEMBER(s32, res, FbnNpcResource, frameTaskValue), (s32)res);
            ((FbnNpcResource *)(res))->scriptSize = FBN_ENTRY(i)->field_18;
            ((FbnNpcResource *)(res))->scriptBufferValue = FBN_ENTRY(i)->field_14;
            chkmemAllocSiteTag(D_005F1068, 0x26F);
            MEMBER(void *, res, FbnNpcResource, scriptBuffer) = D_008873F4[0](1, MEMBER(u32, res, FbnNpcResource, scriptSize), 0x40000);
            memcpy(MEMBER(void *, res, FbnNpcResource, scriptBuffer), (void *)FBN_ENTRY(i)->field_14, MEMBER(u32, res, FbnNpcResource, scriptSize));
            FldStepReleaseHandle((u8 *)FBN_ENTRY(i));
        }
    }
    if (iGpffffb2a4 != NULL) {
        jtbl_008873EC[0](iGpffffb2a4);
    }
    if (iGpffffb2a0 != NULL) {
        jtbl_008873EC[0](iGpffffb2a0);
    }
    iGpffffb2a8 = 0;
    iGpffffb2a4 = NULL;
    iGpffffb2a0 = NULL;
    if (FldRc_GetLoadSource() == 0) {
        H_Cdvd_Destroy(file);
    }
    return 1;
}
