#include "model_callbacks_internal.h"
#include "include_asm.h"
/* Source unit: src/Kosaka/Field/k_fldFBN.c */
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_model_internal.h"

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
    u8  pad14[0x3C];
    s32 field_50;  /* 0x50 */
    u8  pad54[0xC];
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

extern s32 func_0014eec0(void);
extern s16 func_001060b0(void);
extern u8 func_001060c0(void);
extern s64 func_00110960(s32 arg0, u32 arg1);
extern u32 datGetFlag(s32 arg0);
extern s32 func_001453a0(u16 arg0);
extern void func_0014aa80(u16 arg0);
extern void func_0014b0c0(u16 arg0, u32 arg1);
extern u8 *MT_Scene_GetRes(u16 arg0);
extern f32 func_0014b660(u8 *arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern f32 func_0014b6f0(u8 *arg0);
extern void *func_0015ca30(void);
extern u16 *func_0015cbe0(s32 arg0);
extern void func_0015d100(u8 *arg0, s32 arg1);
extern s32 func_0015d1a0(u8 *arg0, s32 arg1);
extern void func_0015d270(u8 *arg0);
extern u16 *func_0015d2c0(u32 arg0);
extern u8 *func_0015d310(u16 *arg0);
extern void func_00168780(u8 *arg0, f32 arg1);
extern void func_0017b9a0(u8 *arg0, f32 arg1);
extern s32 func_0018bb20(s32 arg0, s32 arg1);
extern void *RwMatrixUpdate(void *arg0);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern s32 sprintf(char *destination, const char *format, ...);
extern char *strcpy(char *destination, const char *source);
extern s32 func_00440b68(const char *format, ...);
extern void func_0044ea90(void *arg0, s32 arg1);
extern u32 H_Cdvd_FileExists(const char *path);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern u32 H_Cdvd_Destroy(void *arg0);
typedef struct HCdvd HCdvd;
extern u32 H_Cdvd_IsFileLoaded(HCdvd *arg0);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern void func_0046d700(const char *file, s32 line, const char *message, ...);
extern void *func_00477e80(u32 arg0, u16 arg1, void *arg2, u32 arg3);
extern s32 func_004782b0(u8 *arg0);
extern u32 *func_00478750(u8 *arg0);
extern void func_00478e70(u8 *arg0);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern void *mdlGetMatrix(void *arg0);
extern void *func_0047a180(void *matrix, const void *translation, s32 combineOp);
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

// FUN_0015E870
u8 *func_0015e870(s32 arg0, s32 arg1, s16 arg2)
{
    char spC0[0x80];
    char sp40[0x80];

    iGpffffb2a8 = 0;
    iGpffffb2a4 = 0;
    iGpffffb2a0 = 0;
    if (func_0014eec0() == 0)
    {
        strcpy(spC0, D_005F1078);
        sprintf(sp40, D_005F1090, arg0 & 0xFFFF, arg1 & 0xFFFF, arg2);
        if (H_Cdvd_FileExists(sp40) == 0)
        {
            return NULL;
        }
        func_00440b68(&D_00762FD0, D_005F1068, 0xD4);
        return func_00454a60(&sp40, 0);
    }
    return (u8 *)1;
}


/* Entry addresses are offsets in the loaded 28-byte work table. */
#define FBN_ENTRY(i) ((FbnEntry *)((u8 *)iGpffffb2a0 + (i) * sizeof(FbnEntry)))
/* measured: loop invariants retain cached search bounds; the lifetime pass
 * separates the loading count from the later transform index. Together
 * with source-ordered index updates this matches all 424 retail words. */
// FUN_0015E960
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
s32 func_0015e960(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, s32 arg4)
{
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
    if (arg0 == NULL) {
        return 1;
    }
    *arg1 = NULL;
    if ((func_0014eec0() == 0) && (H_Cdvd_IsFileLoaded((HCdvd *)arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        fbn = *(u8 **)(arg0 + 0x110);
    } else {
        sprintf(path, D_005F10B0, arg2 & 0xFFFF, arg3 & 0xFFFF, (s16)arg4);
        fbn = func_00455f70(path, &size);
        if (fbn == NULL) {
            return 1;
        }
        if (fbn == NULL) {
            func_0046d700(D_005F1068, 0x10D, &D_00762FD8, path);
        }
        *arg1 = fbn;
    }
    iGpffffb2a8 = *(u32 *)(fbn + 8);
    if (iGpffffb2a8 != 0) {
        u8 *base;

        func_0044ea90(D_005F1068, 0x117);
        base = (u8 *)D_008873F4;
        iGpffffb2a4 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, *(u32 *)(fbn + 8) * sizeof(void *), 0x40000);
        func_0044ea90(D_005F1068, 0x118);
        iGpffffb2a0 = ((void *(*)(size_t, size_t, u32))*(u32 *)base)(1, *(u32 *)(fbn + 8) * sizeof(FbnEntry), 0x40000);
    }
    p = fbn + 0x18;
    i = 0;
    out = 0;
    for (; i < *(u32 *)(fbn + 8); ) {
        u32 type = *(u16 *)(p + 4);
        if ((type == 4) && (*(u16 *)(p + 6) == 0xFFFF)) {
            if (D_00764340 == 1) {
                iGpffffb2a4[out] = func_00477e80(4, 0xFFFF, D_005F10D0, 0);
                FBN_ENTRY(out)->field_8 = i;
                out++;
            }
        } else {
            iGpffffb2a4[out] = func_00478140(type, *(u16 *)(p + 6), 0);
            FBN_ENTRY(out)->field_8 = i;
            out++;
        }
        i++;
        p += *(s32 *)(fbn + 0xC);
    }
    if (D_00764340 == 0) {
        u8 *head = func_0015ca30();

        if (head != NULL) {
            AnimEntry *ae = (AnimEntry *)func_0015cbe0(*(s32 *)(head + 0xC));

            for (j = 0; ae->field_0 != 0xFFFF; j++, ae++) {
                s32 kind;
                u8 *q;
                u32 num;

                if ((ae->field_10 != -1) && (datGetFlag(ae->field_10) == 1)) {
                    continue;
                }
                kind = ae->field_18;
                if (kind == 1) {
                    if ((s8)func_00110960(func_001060b0(), func_001060c0()) % 2 != 0) {
                        continue;
                    }
                } else if (kind == 2) {
                    if ((s8)func_00110960(func_001060b0(), func_001060c0()) % 2 == 0) {
                        continue;
                    }
                }
                q = fbn + 0x18;
                k = 0;
                num = *(u32 *)(fbn + 8);
                for (; k < num; k++, q += *(s32 *)(fbn + 0xC)) {
                    if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF)
                        && (*(u16 *)(q + 8) == (u16)((ae->field_0 & 0x3FF) | 0xC00))) {
                        if ((ae->field_2 != 0) || (ae->field_4 != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = func_00478140(ae->field_2, ae->field_4, 0);
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
            AnimEntry2 *e2 = (AnimEntry2 *)func_0015d310(func_0015d2c0(k));

            if (e2 != NULL) {
                u8 *q = fbn + 0x18;
                u32 num;

                j = 0;
                num = *(u32 *)(fbn + 8);
                for (; j < num; j++, q += *(s32 *)(fbn + 0xC)) {
                    if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF)
                        && (*(u16 *)(q + 8) == (u16)((e2->field_0 & 0x3FF) | 0xC00))) {
                        if ((e2->field_68 != 0) || (e2->field_6A != 0)) {
                            D_0076439C = 1;
                            iGpffffb2a4[out] = func_00478140(e2->field_68, e2->field_6A, 0);
                            FBN_ENTRY(out)->kind = 2;
                            FBN_ENTRY(out)->field_4 = (s32)e2;
                            FBN_ENTRY(out)->field_8 = j;
                            FBN_ENTRY(out)->field_10 = k;
                            func_0015d100((u8 *)FBN_ENTRY(out), k);
                            out++;
                        }
                        break;
                    }
                }
            }
        }
        iGpffffb2a8 = out;
    }
    for (out = 0; out < *(u32 *)(fbn + 0x10); ) {
        u16 id = func_001453a0(*(u16 *)(p + 0x50) & 0x3FF);

        angles.x = func_0014b660(p + 0x10);
        angles.y = func_0014b5d0(p + 0x10);
        angles.z = func_0014b6f0(p + 0x10);
        func_00146e60(id, p + 0x40, (u8 *)&angles);
        out++;
        p += 0x60;
    }
    return 1;
}
#pragma pop

/* A 64-byte transform record copied between FBN parts and model matrices. */
typedef struct FbnMatrix
{
    s32 m[16];
} FbnMatrix;

/* Retail passes the yaw at sp+0xC4 (0x0015F224) to the four-argument
 * rotation wrapper before the first yaw store at 0x0015F344, so the first
 * iteration passes an uninitialised angle. The C keeps that read of
 * angles.y exactly as retail does; later iterations see the previous
 * kind-0 store. */
// FUN_0015F000
s32 func_0015f000(u8 *arg0, u8 *arg1)
{
    s32 n;
    s32 i;
    u8 *fbn;
    u8 *base;

    if (arg0 == NULL) {
        return 1;
    }
    for (n = 0; n < iGpffffb2a8; n++) {
        if (func_0015d1a0((u8 *)FBN_ENTRY(n), iGpffffb2a0[n].field_10) == 0) {
            return 0;
        }
        if ((FBN_ENTRY(n)->kind == 0) && (func_004782b0((u8 *)iGpffffb2a4[n]) == 0)) {
            return 0;
        }
    }
    if (func_0014eec0() == 0) {
        fbn = *(u8 **)(arg0 + 0x110);
    } else if (arg1 != NULL) {
        fbn = arg1;
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

        rec = &base[*(u32 *)(fbn + 0xC) * FBN_ENTRY(i)->field_8];
        if (*(u32 *)(fbn + 4) > 0x10000) {
            mode = rec[0x60];
        }
        rid = func_00145780(*(u16 *)(rec + 8) & 0x3FF, mode, (s32)iGpffffb2a4[i]);
        func_0014aa80(rid);
        func_0014b0c0(rid, 1);
        res = MT_Scene_GetRes(rid);
        size = (f32 *)(rec + 0xC);
        func_00168780(*(u8 **)(res + 0x228), *size);
        func_0017b9a0(*(u8 **)(res + 0x230), 40.0f);
        scale.z = scale.y = scale.x = *size;
        *(u32 **)(res + 0x22C) = func_00478750((u8 *)D_00764364);
        /* Retail passes the yaw slot before this iteration writes it. */
        func_0047a1a0(*(u32 **)(res + 0x22C), &axis, angles.y, 2);
        mdlScale(*(u32 **)(res + 0x22C), &scale, 2);
        if (rec[0xB] & 1) {
            *(u32 *)(res + 0x28) |= 0x80000000;
        } else {
            *(u32 *)(res + 0x28) &= 0x7FFFFFFF;
        }
        *(s16 *)(res + 0x220) = rec[0xA];
        *(s32 *)(res + 0x224) = *(s32 *)(rec + 0x10);
        res[0x222] = rec[0x61];
        *(u16 *)(res + 0x298) = *(u16 *)(rec + 0x62);
        memcpy(res + 0x29C, rec + 0x74, 0xC0);
        *(f32 *)(res + 0x35C) = *(f32 *)(rec + 0x70);
        kind = FBN_ENTRY(i)->kind;
        *(s32 *)(res + 0x234) = kind;
        if (kind == 0) {
            u8 *mtx;

            func_00478e70(*(u8 **)(res + 0x22C));
            mtx = rec + 0x20;
            *(FbnMatrix *)mdlGetMatrix(iGpffffb2a4[i]) = *(FbnMatrix *)mtx;
            angles.x = func_0014b660(mtx);
            angles.y = func_0014b5d0(mtx);
            angles.z = func_0014b6f0(mtx);
            func_00146e60(rid, rec + 0x50, (u8 *)&angles);
            RwMatrixUpdate(mdlGetMatrix(iGpffffb2a4[i]));
        } else if (kind == 1) {
            *(s32 *)(res + 0x280) = FBN_ENTRY(i)->field_4;
            func_0047a180(*(u8 **)(res + 0x22C), rec + 0x50, 2);
            func_00478e70(*(u8 **)(res + 0x22C));
            *(u32 *)(res + 0x28) &= ~0x10000000;
            *(FbnMatrix *)(res + 0x240) = *(FbnMatrix *)(rec + 0x20);
            *(s32 *)(res + 0x294) = func_0018bb20(*(s32 *)(res + 0x228), (s32)res);
        } else if (kind == 2) {
            *(s32 *)(res + 0x284) = FBN_ENTRY(i)->field_4;
            func_0047a180(*(u8 **)(res + 0x22C), rec + 0x50, 2);
            func_00478e70(*(u8 **)(res + 0x22C));
            *(u32 *)(res + 0x28) &= ~0x10000000;
            *(FbnMatrix *)(res + 0x240) = *(FbnMatrix *)(rec + 0x20);
            *(s32 *)(res + 0x294) = func_0018bb20(*(s32 *)(res + 0x228), (s32)res);
            *(u32 *)(res + 0x28C) = FBN_ENTRY(i)->field_18;
            *(s32 *)(res + 0x288) = FBN_ENTRY(i)->field_14;
            func_0044ea90(D_005F1068, 0x26F);
            *(void **)(res + 0x288) = D_008873F4[0](1, *(u32 *)(res + 0x28C), 0x40000);
            memcpy(*(void **)(res + 0x288), (void *)FBN_ENTRY(i)->field_14, *(u32 *)(res + 0x28C));
            func_0015d270((u8 *)FBN_ENTRY(i));
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
    if (func_0014eec0() == 0) {
        H_Cdvd_Destroy(arg0);
    }
    return 1;
}
