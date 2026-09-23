#include "include_asm.h"
/* Source unit: src/Kosaka/Field/k_fldFBN.c */
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"

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
extern s32 func_00145780(u16 arg0, u8 arg1, u32 arg2);
extern void func_0014aa80(s32 arg0);
extern void func_0014b0c0(s32 arg0, s32 arg1);
extern u8 *MT_Scene_GetRes(s32 arg0);
extern f32 func_0014b660(u8 *arg0);
extern f32 func_0014b5d0(u8 *arg0);
extern f32 func_0014b6f0(u8 *arg0);
extern void *func_0015ca30(void);
extern void *func_0015cbe0(s32 arg0);
extern void func_0015d100(FbnEntry *arg0, s32 arg1);
extern void *func_0015d1a0(s32 arg0);
extern void func_0015d270(FbnEntry *arg0);
extern s32 func_0015d2c0(s32 arg0);
extern void *func_0015d310(s32 arg0);
extern s32 func_00168780(s32 arg0, f32 arg1);
extern s32 func_0017b9a0(s32 arg0, f32 arg1);
extern s32 func_0018bb20(s32 arg0, void *arg1);
extern s32 RwMatrixUpdate(void *arg0);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void sprintf(void *arg0, const char *arg1, u16 arg2, u16 arg3, s32 arg4);
extern void strcpy(void *arg0, const char *arg1);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern void func_0044ea90(void *arg0, s32 arg1);
extern s32 H_Cdvd_FileExists(void *arg0);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern void H_Cdvd_Destroy(void *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern void func_0046d700(const char *arg0, s32 arg1, char *arg2, void *arg3);
extern u32 func_00477e80(s32 arg0, s32 arg1, const char *arg2, s32 arg3);
extern s32 func_00478140(u16 arg0, u16 arg1, s32 arg2);
extern s32 func_004782b0(u32 arg0);
extern void *func_00478750(s32 arg0);
extern void func_00478e70(void *arg0);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern void *mdlGetMatrix(u32 arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
extern u32 iGpffffb2a8;
extern u32 *iGpffffb2a4;
extern FbnEntry *iGpffffb2a0;
extern s32 D_0076439C;
extern s32 D_00764340;
extern u32 D_00764388;
extern s32 D_0076436C;
extern char D_00762FD0;
extern char D_00762FD8;
extern char D_005F1068[];
extern char D_005F1078[];
extern char D_005F1090[];
extern char D_005F10B0[];
extern char D_005F10D0[];
extern u64 D_005F10E8[];
extern f32 D_005F10F0[];

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


/* 2026-09-17 cold reconstruction from the m2c draft (guarded v1): nd 309 at */
/*   374/381 instrs. All TU externs honest (0047a1a0 arg order corrected to */
/*   (obj,&cfg,float,int); 0018bb20/0015d1a0 taken at true arity; 00146e60-call */
/*   float lanes as 40.0f-style int literals pending). Open: one FPU-saved */
/*   spill (swc1 f20) for the stale case-0 float slot sp+0xC4 that retail keeps */
/*   in memory with per-use lwc1; plus params/saved coloring. Production stays ASM. */
// FUN_0015F000 NONMATCHING
#ifdef NON_MATCHING
s32 func_0015f000(u8 *arg0, u8 *arg1)
{
    extern void func_0046d730(u8 *arg0, s32 arg1);
    extern s32 func_0015d1a0(u8 *arg0);
    extern s32 D_00764364;
    SVec3 angles;
    f32 spB8;
    u64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    s32 n;
    s32 i;
    s32 rid;
    u16 *ntab;
    s32 k;
    s32 t;
    s32 w0;
    s32 w1;
    u8 *rec;
    u8 *dst;
    u8 *src;
    u8 *tmp;
    u8 *blk;
    u8 *var_20;
    u8 *tab;
    u8 mode;

    var_20 = arg1;
    if (arg0 == NULL) {
        return 1;
    }
    for (n = 0; (u32)n < iGpffffb2a8; n++) {
        blk = (u8 *)iGpffffb2a0 + n * 0x1C;
        if (func_0015d1a0(blk) == 0) {
            return 0;
        }
        if (*(u8 *)((u8 *)iGpffffb2a0 + n * 0x1C) == 0 && func_004782b0(*(u8 *)((u8 *)iGpffffb2a4 + n * 4)) == 0) {
            return 0;
        }
    }
    if (func_0014eec0() == 0) {
        var_20 = *(u8 **)(arg0 + 0x110);
    }
    if (var_20 != NULL) {
        for (i = 0; (u32)i < iGpffffb2a8; i++) {
            mode = 3;
            spB0 = D_005F10E8[0];
            spB8 = D_005F10F0[0];
            t = i * 0x1C;
            rec = var_20 + 0x18 + *(s32 *)(var_20 + 0xC) * *(s32 *)((u8 *)iGpffffb2a0 + t + 8);
            if (*(u32 *)(var_20 + 4) >= 0x10001U) {
                mode = *(u8 *)(rec + 0x60);
            }
            rid = (s32)(func_00145780((u16)(*(u16 *)(rec + 8) & 0x3FF), (u8)(mode & 0xFF), *(u8 *)((u8 *)iGpffffb2a4 + i * 4)) & 0xFFFF);
            func_0014aa80(rid);
            func_0014b0c0(rid, 1);
            tmp = MT_Scene_GetRes(rid);
            func_00168780(*(s32 *)(tmp + 0x228), *(f32 *)(rec + 0xC));
            func_0017b9a0(*(s32 *)(tmp + 0x230), 40.0f);
            t = (s32)*(f32 *)(rec + 0xC);
            spA0 = (f32)t;
            spA4 = (f32)t;
            spA8 = (f32)t;
            k = (s32)func_00478750(D_00764364);
            *(s32 *)(tmp + 0x22C) = k;
            func_0047a1a0((void *)k, &spB0, angles.y, 2);
            mdlScale((void *)*(s32 *)(tmp + 0x22C), &spA0, 2);
            if (*(u8 *)(rec + 0xB) & 1) {
                *(s32 *)(tmp + 0x28) |= 0x80000000;
            } else {
                *(s32 *)(tmp + 0x28) = (s32)(((s64)*(s32 *)(tmp + 0x28) << 33) >> 33);
            }
            *(s16 *)(tmp + 0x220) = (s16)*(u8 *)(rec + 0xA);
            *(s32 *)(tmp + 0x224) = *(s32 *)(rec + 0x10);
            *(u8 *)(tmp + 0x222) = *(u8 *)(rec + 0x61);
            *(u16 *)(tmp + 0x298) = *(u16 *)(rec + 0x62);
            memcpy(tmp + 0x29C, rec + 0x74, 0xC0U);
            *(f32 *)(tmp + 0x35C) = *(f32 *)(rec + 0x70);
            t = *((u8 *)((u8 *)iGpffffb2a0 + i * 0x1C));
            *(s32 *)(tmp + 0x234) = t;
            switch (t) {
            case 0:
                func_00478e70((void *)*(s32 *)(tmp + 0x22C));
                src = rec + 0x20;
                dst = mdlGetMatrix(*(u8 *)((u8 *)iGpffffb2a4 + i * 4));
                n = 8;
                do {
                    w0 = *(s32 *)src;
                    w1 = *(s32 *)(src + 4);
                    src += 8;
                    n -= 1;
                    *(s32 *)dst = w0;
                    *(s32 *)(dst + 4) = w1;
                    dst += 8;
                } while (n > 0);
                angles.x = (f32)(s32)(func_0014b660(rec + 0x20));
                angles.y = (f32)(s32)(func_0014b5d0(rec + 0x20));
                angles.z = (f32)(s32)(func_0014b6f0(rec + 0x20));
                func_00146e60(rid, rec + 0x50, (u8 *)&angles);
                RwMatrixUpdate(mdlGetMatrix(*(u8 *)((u8 *)iGpffffb2a4 + i * 4)));
                break;
            case 1:
                *(s32 *)(tmp + 0x280) = *(s32 *)((u8 *)iGpffffb2a0 + t + 4);
                func_0047a180((void *)*(s32 *)(tmp + 0x22C), rec + 0x50, 2);
                func_00478e70((void *)*(s32 *)(tmp + 0x22C));
                *(s32 *)(tmp + 0x28) &= 0xEFFFFFFF;
                src = rec + 0x20;
                dst = tmp + 0x240;
                n = 8;
                do {
                    w0 = *(s32 *)src;
                    w1 = *(s32 *)(src + 4);
                    src += 8;
                    n -= 1;
                    *(s32 *)dst = w0;
                    *(s32 *)(dst + 4) = w1;
                    dst += 8;
                } while (n > 0);
                *(s32 *)(tmp + 0x294) = func_0018bb20(*(s32 *)(tmp + 0x228), tmp);
                break;
            case 2:
                t = i * 0x1C;
                *(s32 *)(tmp + 0x284) = *(s32 *)((u8 *)iGpffffb2a0 + t + 4);
                func_0047a180((void *)*(s32 *)(tmp + 0x22C), rec + 0x50, 2);
                func_00478e70((void *)*(s32 *)(tmp + 0x22C));
                *(s32 *)(tmp + 0x28) &= 0xEFFFFFFF;
                src = rec + 0x20;
                dst = tmp + 0x240;
                n = 8;
                do {
                    w0 = *(s32 *)src;
                    w1 = *(s32 *)(src + 4);
                    src += 8;
                    n -= 1;
                    *(s32 *)dst = w0;
                    *(s32 *)(dst + 4) = w1;
                    dst += 8;
                } while (n > 0);
                *(s32 *)(tmp + 0x294) = func_0018bb20(*(s32 *)(tmp + 0x228), tmp);
                tab = (u8 *)iGpffffb2a0 + t;
                *(u32 *)(tmp + 0x28C) = *(u32 *)(tab + 0x18);
                *(u16 **)(tmp + 0x288) = *(u16 **)(tab + 0x14);
                func_0044ea90(D_005F1068, 0x26F);
                ntab = (u16 *)D_008873F4[0](1, *(u32 *)(tmp + 0x28C), 0x40000);
                *(u16 **)(tmp + 0x288) = ntab;
                memcpy(ntab, *(u8 **)(tab + 0x14), *(u32 *)(tmp + 0x28C));
                func_0015d270((FbnEntry *)tab);
                break;
            }
        }
        t = (s32)iGpffffb2a4;
        if (t != 0) {
            jtbl_008873EC[0]((void *)t);
        }
        t = (s32)iGpffffb2a0;
        if (t != 0) {
            jtbl_008873EC[0]((void *)t);
        }
        iGpffffb2a8 = 0;
        iGpffffb2a4 = (u32 *)0;
        iGpffffb2a0 = (FbnEntry *)0;
        if (func_0014eec0() == 0) {
            H_Cdvd_Destroy(arg0);
        }
        return 1;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFBN", func_0015f000);
#endif
