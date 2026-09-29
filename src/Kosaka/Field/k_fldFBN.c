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
extern s32 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s16 arg0, s32 arg1);
extern s32 datGetFlag(s32 arg0);
extern s32 func_001453a0(s32 arg0);
extern void func_0014aa80(u16 arg0);
extern void func_0014b0c0(u16 arg0, u32 arg1);
extern u8 *MT_Scene_GetRes(u16 arg0);
extern f32 func_0014b660(u8 *arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern f32 func_0014b6f0(u8 *arg0);
extern void *func_0015ca30(void);
extern void *func_0015cbe0(s32 arg0);
extern void func_0015d100(FbnEntry *arg0, s32 arg1);
extern s32 func_0015d1a0(u8 *arg0, s32 arg1);
extern void func_0015d270(u8 *arg0);
extern s32 func_0015d2c0(s32 arg0);
extern void *func_0015d310(s32 arg0);
extern void func_00168780(u8 *arg0, f32 arg1);
extern void func_0017b9a0(u8 *arg0, f32 arg1);
extern s32 func_0018bb20(s32 arg0, s32 arg1);
extern void *RwMatrixUpdate(void *arg0);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void sprintf(void *arg0, const char *arg1, u16 arg2, u16 arg3, s32 arg4);
extern void strcpy(void *arg0, const char *arg1);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern void func_0044ea90(void *arg0, s32 arg1);
extern s32 H_Cdvd_FileExists(void *arg0);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern u32 H_Cdvd_Destroy(void *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern void func_0046d700(const char *arg0, s32 arg1, char *arg2, void *arg3);
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

/* measured floor (nd 1014): the parameter pair {arg0, arg1} is coloured
 * {s4, s3} where retail uses {s3, s4} (b210's pure-reverse param colouring vs
 * retail's forward-first-two), which cascades through every s3/s4 use, the
 * n/p/entry slot reuses, the kind==1 beqz/branch orientation, and the final
 * loop's address CSE. Retail also maintains a dead loop counter (j, s5) that
 * b210 eliminates (probed: an unused induction variable is DCE'd). */



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
        strcpy(&spC0, D_005F1078);
        sprintf(&sp40, D_005F1090, arg0 & 0xFFFF, arg1 & 0xFFFF, arg2);
        if (H_Cdvd_FileExists(&sp40) == 0)
        {
            return NULL;
        }
        func_00440b68(&D_00762FD0, D_005F1068, 0xD4);
        return func_00454a60(&sp40, 0);
    }
    return (u8 *)1;
}


/* measured: archived faithful reconstruction had the residual recorded in
   the notes above; re-measured for nd_audit coverage.
   Committed at nd 1014. */
/* 2026-09-17 cold reconstruction from the m2c draft (guarded v1): nd 331 at */
/*   428/424 instrs (1712B/1696B, +0.9% within 3% window 1645-1747B). TU globals */
/*   honest via gp base 0x007690F0 (D_0076439C/-0x4D54, D_00764340/-0x4DB0, */
/*   D_00764388/-0x4D68, D_00762FD8/-0x6118 + iGp trio); block-scoped counters, */
/*   sequential < guards, break-on-match inner searches, dual-NULL dead branch */
/*   kept. Paid: correct heap sizes (4/0x1C), FbnEntry kind/ptr/idx + 0015d100. */
/*   Open: s3/s4 param colouring, s2/s4 out colouring, sp+0xB8 vs 0xBC tmp/float */
/*   slots + FPU spill. Production stays ASM. */
// FUN_0015E960 NONMATCHING
#ifdef NON_MATCHING
s32 func_0015e960(u8 *arg0, u8 **arg1, s32 arg2, s32 arg3, s32 arg4)
{
    char buf[0x40];
    SVec3 angles;
    u32 tmp;
    u8 *fbn;
    u8 *p;
    s32 out;

    D_0076439C = 0;
    if (arg0 == NULL) {
        return 1;
    }
    *arg1 = NULL;
    if ((func_0014eec0() == 0) && (H_Cdvd_IsFileLoaded(arg0) == 0)) {
        return 0;
    }
    if (func_0014eec0() == 0) {
        fbn = *(u8 **)(arg0 + 0x110);
    } else {
        sprintf(buf, D_005F10B0, arg2 & 0xFFFF, arg3 & 0xFFFF, (s16)arg4);
        fbn = func_00455f70(buf, &tmp);
        if (fbn == NULL) {
            return 1;
        }
        if (fbn == NULL) {
            func_0046d700(D_005F1068, 0x10D, &D_00762FD8, buf);
        }
        *arg1 = fbn;
    }
    iGpffffb2a8 = *(u32 *)(fbn + 8);
    if (*(u32 *)(fbn + 8) != 0) {
        func_0044ea90(D_005F1068, 0x117);
        iGpffffb2a4 = D_008873F4[0](1, *(u32 *)(fbn + 8) * 4, 0x40000);
        func_0044ea90(D_005F1068, 0x118);
        iGpffffb2a0 = D_008873F4[0](1, *(u32 *)(fbn + 8) * 0x1C, 0x40000);
    }
    p = fbn + 0x18;
    out = 0;
    {
        s32 i;
        for (i = 0; (u32)i < *(u32 *)(fbn + 8); i++) {
            u16 type = *(u16 *)(p + 4);
            u16 flags = *(u16 *)(p + 6);
            if ((type == 4) && (flags == 0xFFFF)) {
                if (D_00764340 == 1) {
                    iGpffffb2a4[out] = func_00477e80(4, 0xFFFF, D_005F10D0, 0);
                    (iGpffffb2a0 + out)->field_8 = i;
                    out++;
                }
            } else {
                iGpffffb2a4[out] = func_00478140(type, flags, 0);
                (iGpffffb2a0 + out)->field_8 = i;
                out++;
            }
            p += *(s32 *)(fbn + 0xC);
        }
    }
    if (D_00764340 == 0) {
        void *head = func_0015ca30();
        if (head != NULL) {
            AnimEntry *ae = func_0015cbe0(*(s32 *)((u8 *)head + 0xC));
            for (; ae->field_0 != 0xFFFF; ae++) {
                s32 fl = ae->field_10;
                if ((fl == -1) || (datGetFlag(fl) != 1)) {
                    s32 kind = ae->field_18;
                    s32 search = 1;
                    if (kind == 1) {
                        s8 r = func_00110960((s16)func_001060b0(), func_001060c0() & 0xFF);
                        if ((r % 2) != 0) {
                            search = 0;
                        }
                    } else if (kind == 2) {
                        s8 r = func_00110960((s16)func_001060b0(), func_001060c0() & 0xFF);
                        if ((r % 2) == 0) {
                            search = 0;
                        }
                    }
                    if (search) {
                        u16 want = (ae->field_0 & 0x3FF) | 0xC00;
                        {
                            s32 j;
                            u8 *q = fbn + 0x18;
                            for (j = 0; (u32)j < *(u32 *)(fbn + 8); j++) {
                                if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF) && (*(u16 *)(q + 8) == want)) {
                                    if ((ae->field_2 != 0) || (ae->field_4 != 0)) {
                                        D_0076439C = 1;
                                        iGpffffb2a4[out] = func_00478140(ae->field_2, ae->field_4, 0);
                                        (iGpffffb2a0 + out)->kind = 1;
                                        (iGpffffb2a0 + out)->field_4 = (s32)ae;
                                        (iGpffffb2a0 + out)->field_8 = j;
                                        out++;
                                    }
                                    break;
                                }
                                q += *(s32 *)(fbn + 0xC);
                            }
                        }
                    }
                }
            }
        }
        {
            s32 k;
            for (k = 0; (u32)k < D_00764388; k++) {
                AnimEntry2 *e2 = func_0015d310(func_0015d2c0(k));
                if (e2 != NULL) {
                    u16 want = (e2->field_0 & 0x3FF) | 0xC00;
                    {
                        s32 j;
                        u8 *q = fbn + 0x18;
                        for (j = 0; (u32)j < *(u32 *)(fbn + 8); j++) {
                            if ((*(u16 *)(q + 4) == 4) && (*(u16 *)(q + 6) == 0xFFFF) && (*(u16 *)(q + 8) == want)) {
                                if ((e2->field_68 != 0) || (e2->field_6A != 0)) {
                                    D_0076439C = 1;
                                    iGpffffb2a4[out] = func_00478140(e2->field_68, e2->field_6A, 0);
                                    (iGpffffb2a0 + out)->kind = 2;
                                    (iGpffffb2a0 + out)->field_4 = (s32)e2;
                                    (iGpffffb2a0 + out)->field_8 = j;
                                    (iGpffffb2a0 + out)->field_10 = k;
                                    func_0015d100(iGpffffb2a0 + out, k);
                                    out++;
                                }
                                break;
                            }
                            q += *(s32 *)(fbn + 0xC);
                        }
                    }
                }
            }
        }
        iGpffffb2a8 = out;
    }
    {
        s32 m;
        for (m = 0; (u32)m < *(u32 *)(fbn + 0x10); m++) {
            s32 id = func_001453a0(*(u16 *)(p + 0x50) & 0x3FF) & 0xFFFF;
            angles.x = func_0014b660(p + 0x10);
            angles.y = func_0014b5d0(p + 0x10);
            angles.z = func_0014b6f0(p + 0x10);
            func_00146e60(id, p + 0x40, (u8 *)&angles);
            p += 0x60;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015e960);
#endif


/* A 64-byte transform record copied between FBN parts and model matrices. */
typedef struct FbnMatrix
{
    s32 m[16];
} FbnMatrix;

/* Entry addresses are formed as byte offsets into the loaded work table. */
#define FBN_ENTRY(i) ((FbnEntry *)((u8 *)iGpffffb2a0 + (i) * sizeof(FbnEntry)))

/* Retail passes the yaw at sp+0xC4 (0x0015F224) to the real four-argument
 * rotation wrapper before the first yaw store at 0x0015F344. The initial
 * value has no established lifetime. Retain assembly rather than an
 * uninitialized C local or an invented initial angle. */
// FUN_0015F000
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015f000);
