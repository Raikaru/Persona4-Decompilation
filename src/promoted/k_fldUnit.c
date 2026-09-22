#include "model_motion_internal.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "model_matrix_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"

typedef struct HCdvd HCdvd;
typedef struct Model Model;
typedef struct Resrc Resrc;
typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

extern void (*DAT_008873EC[])(void *);
extern void *(*DAT_008873F4[])(size_t, size_t, u32);

extern s32 iGpffffb2e8;
extern s32 iGpffffb260;
extern s32 iGpffffb2e4;
extern s32 iGpffffb274;
extern u8 *iGpffffb414;
extern s32 D_00764344;
extern s32 D_00724504;
extern u8 *iGpffff9db0;
extern u8 iGpffff9f28;
extern u8 iGpffff9f29;
extern u8 iGpffff9f2a;
extern u8 iGpffff9f2b;
extern u8 iGpffff9f24;
extern s32 func_0014b870(s32 arg0, s32 arg1);
extern void func_002319c0(s32 arg0);
extern s32 func_0047ae90(u8 *arg0, u16 arg1);
extern void func_0047ae10(u8 *arg0, u16 arg1);
extern u32 func_004553c0(HCdvd *arg0);
extern u32 func_00454bd0(HCdvd *arg0);
extern void *func_0043f810(void *arg0, const void *arg1, u32 arg2);
extern s32 func_001619b0(u16 arg0, u16 arg1, u16 arg2);
extern s32 func_00161a70(u16 arg0, u16 arg1, u16 arg2);
extern void func_00182310(s32 arg0);
extern s32 func_00164570(u32 arg0, s32 arg1);
typedef struct DatUnitEc DatUnitEc;
extern DatUnitEc *func_00231630(u16 encountId);
extern u8 *func_00163990(u32 arg0, u8 *arg1, s32 arg2);
extern s32 func_00442088(char *dst, const char *fmt, ...);
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern u32 func_003b7060(void);
extern Resrc *func_00145270(u16 arg0);
extern s32 func_00145540(s32 arg0, u8 arg1, u8 *arg2);
extern void func_0047aa30(u8 *arg0, u8 *arg1);
extern s32 func_0014c780(void);
extern void func_0017b9a0(s32 arg0, f32 arg1);
extern void func_0047a1e0(Model *arg0, const RwV3d *arg1, s32 arg2);
extern void func_003e05d0(u8 *arg0);
extern void func_00168de0(s32 arg0, void *arg1, f32 arg2);
extern void func_00168ae0();
extern void func_0014b0c0(u16 arg0, u32 arg1);
extern void func_00168730(s32 arg0, s32 arg1);
extern void func_00168780(s32 arg0, f32 arg1);
extern u32 *func_00478750(u8 *arg0);
extern f32 func_00168770(s32 arg0);
extern void func_00478e70(u8 *arg0);
extern s32 func_00182220(s32 arg0, u8 *arg1, s32 arg2);
extern s32 func_002319f0(s32 arg0);
extern s32 func_0016fd00(s32 arg0);
extern s32 func_0017e890(s32 arg0, u8 *arg1, u8 *arg2);
extern void func_0017e990(s32 arg0);
extern s32 func_0017d070(u8 *arg0);
extern void func_00168c00(s32 arg0);
extern f32 func_003e4180(f32 *arg0);
extern s32 func_00161630(s32 field, s32 room, s32 encounter, s32 level);
extern u8 *func_00164880(s32 arg0, u32 arg1, f32 arg2);
extern u8 *func_0014cef0(s32 arg0, s32 arg1);
extern void func_0014c920(void);
extern s32 func_0014c960(s32 *arg0, s32 *arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_00145ac0(s32 arg0, s32 arg1);
extern u8 *func_00162330(void);
typedef struct DatUnitPc DatUnitPc;
extern DatUnitPc *func_00231580(u16 arg0);
extern u8 *func_00162680(u16 arg0, u16 arg1, s32 arg2);
extern u8 func_00109400(u16 arg0);
extern s16 func_00105ee0(s32 arg0);
extern s32 func_00104c70(s32 arg0);
extern s32 *func_00155280(void);
extern void func_0014a0f0(u16 arg0, s32 arg1);
extern s32 func_00145780(u16 arg0, s32 arg1, s32 arg2);
extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern s32 func_0018bb20(s32 arg0, s32 arg1);

extern void *memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];
extern u8 D_007E8C00[];
extern u8 D_007EF9B0[];
extern u8 D_007E8BE0[];
extern u8 D_005F1500[];
extern u8 D_005F1510[];
extern u8 D_005F13C0[];
extern u8 D_005F1340[];
extern u8 D_005F12E0[];
extern u8 D_005F1520[];
extern u8 D_005F1528[];
extern u8 D_005DC920[];
extern u8 D_00756510[];
extern u8 D_005F1530[];
extern u8 D_005F1550[];
extern u8 D_005F1570[];
extern s32 D_007E8BE8[];
extern s32 D_00764364;
extern u8 D_007EF9F8[];
extern u8 D_007F16F0[];
extern u8 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 D_007EFB60[];
extern u8 D_007EFB64[];
extern u8 D_007F00D8[];
extern u8 D_005F1590[];
extern SdkTaskUpdate D_005F15B0[];
extern u8 D_005F15C0[];
extern u8 D_005F15E0[];
extern u8 D_007E80A0[];

static s32 D_007643C8[2];
static s32 D_007643C0[2];
extern u8 D_00763008[8];
extern u8 D_00763010[4];
extern u8 *D_00762EA0;
static s32 D_00764350;
extern f32 D_007613EC;

typedef struct {
    u8 b[4];
} S4;

typedef struct {
    u32 h[2];
} S8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

s32 func_00163c90(s32 arg0);
void func_00164020(u8 *arg0);
void func_00164fa0(s32 arg0);
void func_00165670(u8 *arg0, s32 arg1);
void *func_00478140(u32 arg0, u32 arg1, u32 arg2);
s32 func_004782b0(u8 *arg0);
s32 func_00440b68(const char *fmt, ...);
u8 *func_00454a60(u8 *arg0, s32 arg1);
s32 func_0014a200(void);
s32 func_0014a270(void);
s32 func_001668e0(u8 *arg0);
void func_0044ea90(u8 *arg0, s32 arg1);
f32 func_0044b7b0(f32 arg0);
u8 *func_0047a250(s32 arg0);
void func_0047a220(s32 arg0, u8 *arg1);
void func_004b14f0(u8 *arg0, u8 *arg1);
void func_004b13f0(u8 *arg0, u8 *arg1);
void *func_0047a2f0(void *arg0);
void func_00146630(u16 arg0);
void func_0047a870(s32 arg0);
void func_004787e0(u8 *arg0);
void func_00452080(s32 arg0);
s32 func_00162510(u16 arg0, u16 arg1);
s32 func_0015a160(void);
s32 func_001679d0(u8 *arg0);
u8 *func_001452b0(s32 arg0);
void func_0046d730(void *arg0, s32 arg1);
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2);
extern s64 func_001060b0(void);
extern s32 func_001064f0(s32 arg0);
extern s32 func_00110d60(s16 arg0);
extern s32 D_007E8BF8[];
void *func_0043f9c8(void *arg0, s32 arg1, u32 arg2);
s32 func_00161b10(u16 arg0, u16 arg1, u16 arg2);
s32 func_0015a320(void);
u8 *func_00161c80(u16 arg0, u16 arg1, u16 arg2, s32 arg3);






/* measured: disable common-subexpression elimination to preserve the retail
   second unit-base materialization after the allocator call. */
#pragma opt_common_subs off
// FUN_00162C30
s32 func_00162c30(void)
{
    s32 field;
    s32 i;
    s32 j;
    s32 k;
    s32 *v4;
    s32 *v7;
    s32 v9;
    s32 v18;
    s32 resource;

    for (i = 0; i < 4; i++) {
        v4 = ((s32 *)D_007EF9B0) + i * 468;
        if ((v4[18] != 0) && (v4[21] == 0)) {
            if (func_004782b0((u8 *)(v4[20])) == 0) {
                return 0;
            }
            for (j = 0; j < 5; j++) {
                if (func_0047ae90((u8 *)(v4[20]), j) == 0) {
                    return 0;
                }
            }
            if ((v18 = v4[460]) != 0) {
                if (func_004553c0((HCdvd *)(v18)) == 0) {
                    return 0;
                }
                func_0044ea90(D_005F1500, 0x218);
                v7 = ((s32 *)D_007EF9B0) + i * 468;
                field = (s32)(v7 + 460);
                resource = *(s32 *)(v7[460] + 0x118);
                v7[461] = (s32)(*DAT_008873F4)(1, resource, 0x40000);
                v7[462] = *(s32 *)(*(s32 *)field + 0x118);
                resource = *(s32 *)field;
                v9 = *(s32 *)(resource + 0x118);
                func_0043f810((void *)v7[461],
                              (const void *)(*(s32 *)(resource + 0x110)), v9);
                func_00454bd0((HCdvd *)(*(s32 *)field));
                *(s32 *)field = 0;
                for (k = 0; k < 5; k++) {
                    resource = v7[20];
                    v9 = *(s32 *)((s32)resource + k * 0xC + 0x290);
                    if (v9 != 0) {
                        *((s32 *)((s32)v7 + k * 4) + 453) =
                            *(s32 *)(v9 + 0x2FC);
                    }
                }
            }
        }
    }
    return 1;
}
/* measured: restore common-subexpression elimination after func_00162c30. */
#pragma opt_common_subs on
/* measured: floor 639 differing words (reloc-masked), object 2992B vs 2944B window, 748 vs 736 instrs (1.6% over, within 3%), 481 fnalign edits plus 5 reloc-only.
   Honest re-derivation from retail window + build/m2c/func_00162e10.c with file levers: opt_common_subs/propagation off preserves the second D_007EF9B0
   materialization after the allocator call (like func_00162c30); three Frame triples sp90/spA0/spB0 for the 60/35/400/120/200 scaling and normalize live range;
   block-scope 5-iter/8-copy/0x40 counters (stops the counter claiming a callee-saved register where retail uses $a1, per 001679d0 158->153);
   real switch on i; (s16)/(s8) idiom for func_001060b0/func_00110960 like code1_0016 func_001623f0; (u32) float casts for the lbu branchy (u32->f32);
   three func_00155280 calls for the 0x44/0x45/0x59 grid key. v1 687 -> v2/v3 639 via honest (u32) casts (u8 kind, lbu).
   Residual is scheduling/coloring (daddiu vs addiu, $s1/$s2/$s3 rotation, frame 0xB0 vs retail 0xC0) + entry b vs moves. Production stays ASM. */
// FUN_00162E10 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00162e10(void)
{
    extern u8 *func_003e0f80(void);
    extern void func_003e0f40(u8 *arg0);
    extern f32 func_003e40b0(f32 *arg0, f32 *arg1);
    extern s32 func_0014a160(void);
    extern s32 func_001060c0(void);
    extern s32 func_00110680(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_00110960(s16 arg0, s32 arg1);
    extern s32 D_005F1350[];
    extern f32 D_007615DC;
    f32 sp90[3];
    f32 spA0[3];
    f32 spB0[3];
    u8 *mtx;
    s32 i;
    u8 *slot;
    u8 *slot2;
    u8 kind;
    u16 resId;
    u8 *res;
    u8 *node;

    mtx = func_003e0f80();
    for (i = 0; i < 4; i++) {
        kind = 1;
        slot = D_007EF9B0 + i * 0x750;
        if ((*(s32 *)(slot + 0x48) != 0) && (*(s32 *)(slot + 0x54) == 0)) {
            if (func_0015a160() != 0) {
                if (func_00162510(*(u16 *)iGpffff9db0, *(u16 *)(iGpffff9db0 + 4)) == 0) {
                    kind = 3;
                }
            }
            slot2 = D_007EF9B0 + i * 0x750;
            resId = func_00145540(i & 0xFFFF, kind, *(u8 **)(slot2 + 0x50)) & 0xFFFF;
            res = (u8 *)func_00145270(resId);
            *(u8 **)(slot2 + 0x54) = res;
            func_0017b9a0(*(s32 *)(res + 0x224), 60.0f);
            node = func_001452b0(0xE);
            if ((node != NULL) || (*(u16 *)(slot + 0x58) != 0xFFFF)) {
                while (node != NULL) {
                    if ((*(u16 *)node & 0x3FF) == *(u16 *)(slot + 0x58)) {
                        break;
                    }
                    node = *(u8 **)(node + 0x138);
                }
                *(u8 **)(slot + 0x1AC) = node;
            }
            if (i == 0) {
                func_00168780(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), 60.0f);
                if (*(u16 *)(*(u8 **)(slot2 + 0x50) + 0xD4) != 1) {
                    s32 found;
                    s32 k;
                    s32 v;
                    u8 *e;
                    s16 t16;
                    s32 t8;
                    s32 b;

                    found = 0;
                    if (func_00110680((s16)func_001060b0(), 3, 0x14) != 1) {
                        for (k = 0; ; k++) {
                            e = (u8 *)D_005F1350 + k * 8;
                            v = *(s32 *)(e + 0);
                            if (v == -1) {
                                break;
                            }
                            if ((*(s32 *)iGpffff9db0 == v) && (*(s32 *)(iGpffff9db0 + 4) == *(s32 *)(e + 4))) {
                                t16 = (s16)func_001060b0();
                                t8 = (s8)func_00110960(t16, func_001060c0() & 0xFF);
                                b = t8 & 1;
                                if ((t8 < 0) && (b != 0)) {
                                    b -= 2;
                                }
                                if (b != 0) {
                                    found = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (found == 0) {
                        {
                            s32 j;
                            for (j = 0; j < 5; j++) {
                                *(u8 *)(*(u8 **)(slot + 0x50) + j * 0xC + 0x28C) &= (u8)~1;
                            }
                        }
                    } else {
                        {
                            s32 j;
                            for (j = 0; j < 5; j++) {
                                *(u8 *)(*(u8 **)(slot + 0x50) + j * 0xC + 0x28C) |= 1;
                            }
                        }
                    }
                    func_00479940(*(u8 **)(slot2 + 0x50), 0, (s16)func_0016fd00(*(u16 *)(D_007EF9B0 + i * 0x750 + 0x728)), 0, 1);
                }
            } else {
                func_00168780(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), 35.0f);
            }
            {
                u8 *s3 = D_007EF9B0 + i * 0x750;
                *(s32 *)(*(u8 **)(s3 + 0x54) + 0x228) = (s32)func_00478750((u8 *)(iGpffffb274));
                {
                    f32 t = func_00168770(*(s32 *)(*(u8 **)(s3 + 0x54) + 0x220));
                    spA0[0] = t;
                    spA0[1] = t;
                    spA0[2] = t;
                    func_0047a1e0((Model *)(*(u8 **)(*(u8 **)(s3 + 0x54) + 0x228)), (const RwV3d *)(&spA0[0]), 2);
                    func_00478e70(*(u8 **)(*(u8 **)(s3 + 0x54) + 0x228));
                }
            }
            {
                u8 *aux = *(u8 **)(D_007EF9B0 + i * 0x750 + 0x1AC);
                if (aux == NULL) {
                    u8 b44;
                    u8 b45;
                    s32 v;
                    s32 r;
                    u8 *p1;
                    u8 *p2;

                    b44 = *(u8 *)((u8 *)func_00155280() + 0x44);
                    sp90[0] = 1200.0f * (f32)(u32)b44;
                    sp90[1] = 2.0f;
                    b45 = *(u8 *)((u8 *)func_00155280() + 0x45);
                    sp90[2] = 1200.0f * (f32)(u32)b45;
                    p1 = (u8 *)func_00155280() + ((*(u8 *)((u8 *)func_00155280() + 0x45)) << 8);
                    p2 = p1 + ((*(u8 *)((u8 *)func_00155280() + 0x44)) << 4);
                    v = *(u8 *)(p2 + 0x59) + 2;
                    r = v & 3;
                    if ((v < 0) && (r != 0)) {
                        r -= 4;
                    }
                    func_00168de0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), D_00756510, 90.0f * (f32)r);
                    func_00479940(*(u8 **)(slot2 + 0x50), 0, (s16)func_0016fd00(*(u16 *)(D_007EF9B0 + i * 0x750 + 0x728)), 0, 1);
                    {
                        u8 *src = (u8 *)func_0047a2f0(*(void **)(*(u8 **)D_007EFA04 + 0x164));
                        u8 *dst = mtx;
                        s32 n = 8;
                        do {
                            *(s32 *)dst = *(s32 *)src;
                            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
                            src += 8;
                            n -= 1;
                            dst += 8;
                        } while (n > 0);
                    }
                    if ((i == 0) && (func_0014a160() != 0)) {
                        f32 tmp0;
                        f32 tmp1;
                        f32 tmp2;
                        f32 c400;
                        spB0[0] = *(f32 *)(mtx + 0x20);
                        spB0[1] = *(f32 *)(mtx + 0x24);
                        spB0[2] = *(f32 *)(mtx + 0x28);
                        func_003e40b0(&spB0[0], &spB0[0]);
                        c400 = 400.0f;
                        tmp0 = spB0[0] * c400;
                        tmp1 = spB0[1] * c400;
                        tmp2 = spB0[2] * c400;
                        spB0[0] = tmp0;
                        spB0[1] = tmp1;
                        spB0[2] = tmp2;
                        sp90[0] += tmp0;
                        sp90[1] += tmp1;
                        sp90[2] += tmp2;
                    }
                } else {
                    func_00168de0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), D_00756510, *(f32 *)(aux + 0x14C));
                    sp90[0] = *(f32 *)(aux + 0x140);
                    sp90[1] = *(f32 *)(aux + 0x144);
                    sp90[2] = *(f32 *)(aux + 0x148);
                }
            }
            {
                u8 *src = (u8 *)func_0047a2f0(*(void **)(*(u8 **)D_007EFA04 + 0x164));
                u8 *dst = mtx;
                s32 n = 8;
                do {
                    *(s32 *)dst = *(s32 *)src;
                    *(s32 *)(dst + 4) = *(s32 *)(src + 4);
                    src += 8;
                    n -= 1;
                    dst += 8;
                } while (n > 0);
            }
            switch (i) {
            case 0:
                func_00168ae0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), &sp90[0]);
                break;
            case 1:
                {
                    f32 t0;
                    f32 t1;
                    f32 t2;
                    f32 c60a;
                    f32 c60b;
                    spB0[0] = *(f32 *)(mtx + 0x0);
                    spB0[1] = *(f32 *)(mtx + 0x4);
                    spB0[2] = *(f32 *)(mtx + 0x8);
                    func_003e40b0(&spB0[0], &spB0[0]);
                    c60a = 60.0f;
                    t0 = spB0[0] * c60a;
                    t1 = spB0[1] * c60a;
                    t2 = spB0[2] * c60a;
                    spB0[0] = t0;
                    spB0[1] = t1;
                    spB0[2] = t2;
                    *(f32 *)(mtx + 0x30) += t0;
                    *(f32 *)(mtx + 0x34) += t1;
                    *(f32 *)(mtx + 0x38) += t2;
                    spB0[0] = *(f32 *)(mtx + 0x20);
                    spB0[1] = *(f32 *)(mtx + 0x24);
                    spB0[2] = *(f32 *)(mtx + 0x28);
                    func_003e40b0(&spB0[0], &spB0[0]);
                    spB0[0] = -spB0[0];
                    spB0[1] = -spB0[1];
                    spB0[2] = -spB0[2];
                    c60b = 60.0f;
                    t0 = spB0[0] * c60b;
                    t1 = spB0[1] * c60b;
                    t2 = spB0[2] * c60b;
                    spB0[0] = t0;
                    spB0[1] = t1;
                    spB0[2] = t2;
                    *(f32 *)(mtx + 0x30) += t0;
                    *(f32 *)(mtx + 0x34) += t1;
                    *(f32 *)(mtx + 0x38) += t2;
                    func_00168ae0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), mtx + 0x30);
                }
                break;
            case 2:
                {
                    f32 t0;
                    f32 t1;
                    f32 t2;
                    f32 c60c;
                    f32 c120;
                    spB0[0] = *(f32 *)(mtx + 0x0);
                    spB0[1] = *(f32 *)(mtx + 0x4);
                    spB0[2] = *(f32 *)(mtx + 0x8);
                    func_003e40b0(&spB0[0], &spB0[0]);
                    spB0[0] = -spB0[0];
                    spB0[1] = -spB0[1];
                    spB0[2] = -spB0[2];
                    c60c = 60.0f;
                    t0 = spB0[0] * c60c;
                    t1 = spB0[1] * c60c;
                    t2 = spB0[2] * c60c;
                    spB0[0] = t0;
                    spB0[1] = t1;
                    spB0[2] = t2;
                    *(f32 *)(mtx + 0x30) += t0;
                    *(f32 *)(mtx + 0x34) += t1;
                    *(f32 *)(mtx + 0x38) += t2;
                    spB0[0] = *(f32 *)(mtx + 0x20);
                    spB0[1] = *(f32 *)(mtx + 0x24);
                    spB0[2] = *(f32 *)(mtx + 0x28);
                    func_003e40b0(&spB0[0], &spB0[0]);
                    spB0[0] = -spB0[0];
                    spB0[1] = -spB0[1];
                    spB0[2] = -spB0[2];
                    c120 = 120.0f;
                    t0 = spB0[0] * c120;
                    t1 = spB0[1] * c120;
                    t2 = spB0[2] * c120;
                    spB0[0] = t0;
                    spB0[1] = t1;
                    spB0[2] = t2;
                    *(f32 *)(mtx + 0x30) += t0;
                    *(f32 *)(mtx + 0x34) += t1;
                    *(f32 *)(mtx + 0x38) += t2;
                    func_00168ae0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), mtx + 0x30);
                }
                break;
            case 3:
                {
                    f32 t0;
                    f32 t1;
                    f32 t2;
                    f32 c200;
                    spB0[0] = *(f32 *)(mtx + 0x20);
                    spB0[1] = *(f32 *)(mtx + 0x24);
                    spB0[2] = *(f32 *)(mtx + 0x28);
                    func_003e40b0(&spB0[0], &spB0[0]);
                    spB0[0] = -spB0[0];
                    spB0[1] = -spB0[1];
                    spB0[2] = -spB0[2];
                    c200 = 200.0f;
                    t0 = spB0[0] * c200;
                    t1 = spB0[1] * c200;
                    t2 = spB0[2] * c200;
                    spB0[0] = t0;
                    spB0[1] = t1;
                    spB0[2] = t2;
                    *(f32 *)(mtx + 0x30) += t0;
                    *(f32 *)(mtx + 0x34) += t1;
                    *(f32 *)(mtx + 0x38) += t2;
                    func_00168ae0(*(s32 *)(*(u8 **)(slot + 0x54) + 0x220), mtx + 0x30);
                }
                break;
            }
            if (i != 0) {
                u8 *cur = D_007EF9B0 + i * 0x750;
                u8 *prev = D_007EF9B0 + (i - 1) * 0x750;
                *(s32 *)(cur + 0x1B0) = func_0017e890(0, cur, prev);
            }
            {
                u8 *cur = D_007EF9B0 + i * 0x750;
                func_003e05d0((u8 *)func_0047a2f0(*(void **)(cur + 0x50)));
                func_0014b0c0(*(u16 *)(*(u8 **)(cur + 0x54)), 1);
                func_00168730(*(s32 *)(*(u8 **)(cur + 0x54) + 0x220), 0x40000000);
                {
                    s32 j;
                    f32 fv = D_007615DC;
                    for (j = 0; j < 0x40; j++) {
                        *(f32 *)(cur + j * 8 + 0x210) = fv;
                        *(f32 *)(cur + j * 8 + 0x214) = fv;
                    }
                }
                func_0043f9c8(cur + 0x1D0, 0, 0x40);
                func_0043f9c8(cur + 0x410, 0, 0x300);
            }
        }
    }
    func_003e0f40(mtx);
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162e10);
#endif



/* 760/768 bytes, 15 resolved relocations, and eight zero alignment bytes.
 * Loop-invariant motion preserves the slot stride and copy-loop scheduling. */
#pragma push
#pragma opt_loop_invariants on
// FUN_00163990
u8 *func_00163990(u32 encounter, u8 *placement, s32 variant)
{
    u8 message[0x100];
    u32 encounterId;
    s32 category;
    u64 modelVariant;
    s32 slotIndex;
    s32 unitIndex;
    s32 levelSum;
    u16 unitCount;
    u8 *candidate;
    u8 *slot;
    u8 *source;
    u8 *destination;
    s32 copyCount;
    u8 *group;

    slot = NULL;
    for (slotIndex = 0; slotIndex < 0xF; slotIndex++) {
        candidate = D_007E8C00 + (slotIndex * 0x750);
        if (*(s32 *)(candidate + 0x48) == 0) {
            slot = candidate;
            break;
        }
    }
    modelVariant = 0;
    if (slot == NULL) {
        return NULL;
    }
    encounterId = encounter & 0xFFFF;
    *(u8 **)(slot + 0x48) = (u8 *)func_00231630((u16)encounterId);
    *(s32 *)(slot + 0x4C) = (s32)(iGpffffb414 + (encounterId * 0x18));
    *(s16 *)(slot + 0x728) = 0;
    category = (encounter >> 0x10) & 0xFFFF;
    switch (category) {
    case 1:
        *(s16 *)(slot + 0x1C8) = 1;
        break;
    case 2:
        *(s16 *)(slot + 0x1C8) = 2;
        break;
    case 4:
        *(s16 *)(slot + 0x1C8) = 3;
        break;
    default:
        func_00442088((char *)message, (const char *)D_005F1510, encounter);
        func_0046d740(message, D_005F1500, 0x4B6);
        break;
    }
    switch (variant) {
    case 0:
        modelVariant = 0;
        break;
    case 1:
        modelVariant = 1;
        break;
    case 2:
        modelVariant = func_003b7060() & 1;
        break;
    default:
        break;
    }
    if (modelVariant == 0) {
        *(s32 *)(slot + 0x50) = (s32)func_00478140(8U, 1U, 0);
        *(s8 *)(slot + 0x1CA) = 0;
    } else {
        *(s32 *)(slot + 0x50) = (s32)func_00478140(8U, 2U, 0);
        *(s8 *)(slot + 0x1CA) = 1;
    }
    destination = slot + 0x5C;
    copyCount = 0x2A;
    source = placement;
    do {
        s32 word0 = *(s32 *)source;
        s32 word1 = *(s32 *)(source + 4);
        source += 8;
        copyCount -= 1;
        *(s32 *)destination = word0;
        *(s32 *)(destination + 4) = word1;
        destination += 8;
    } while (copyCount > 0);
    *(u8 **)(slot + 0x1AC) = slot + 0x5C;
    *(s16 *)(slot + 0x1CC) = (s16)(s32)((600.0f + *(f32 *)(placement + 0x140)) / 1200.0f);
    *(s16 *)(slot + 0x1CE) = (s16)(s32)((600.0f + *(f32 *)(placement + 0x148)) / 1200.0f);
    unitIndex = 0;
    levelSum = 0;
    unitCount = *(u16 *)(*(u8 **)(slot + 0x48) + 2);
    for (; unitIndex < (s32)unitCount; unitIndex++) {
        /* Step 4: batch protocol record. Baseline 36 MATCH / 6 ASM, this
           function 0 words diff (760B obj / 768B window) with volatile.
           Step 2 plain `*(u8 **)(slot + 0x48)` scores 32 words diff:
           hoists to preheader `lw $a1,0x48($s0)` + loop `lw $v0,4($a1)`,
           retail reloads per iteration `lw $a0,0x48($s0)` + `lw $v0,4($a0)`.
           Step 3 `opt_loop_invariants off` with correct save/restore
           (unit default around function is loop_invariants off / common_subs
           on; function scope is loop_invariants on via push, restored to on
           after the loop) still scores 32 scoped and 25 whole-function off
           (extra andi on the bound), still hoisted. Also scored and kept out:
           scoped common_subs off 32, whole common_subs off 144,
           whole propagation off 169, scoped optimization_level 1 25,
           block-scope group 32, inlined double-deref 32, s32 unitCount 32,
           (s32)slot cast 35. No honest spelling reproduces the reload, so
           volatile is kept to preserve MATCH; H001 remains here. */
        group = *(u8 *volatile *)(slot + 0x48);
        levelSum += *(u8 *)(*(u8 **)(group + 4) + (unitIndex * 0x30) + 6);
    }
    *(s32 *)(slot + 0x1C0) = levelSum / (s32)unitCount;
    iGpffffb2e8 += 1;
    return slot;
}
#pragma pop



/* measured: parked nd 5, object/window 808/816. The control flow, 0x50-byte frame, stack aggregate stores, and 35.0f COP1 call match. Exact fndiff residuals are offsets 0x14, 0x18, 0x1C, 0x20, and 0x24: b210 schedules the D_005F1528 lwc1 before the D_005F1520 ld and colors the ld result $v0 instead of retail $v1. Ruled out assignment/declaration-order swaps, named-local versus direct-store forms, pointer and aggregate S8/S12 forms, comma sequencing, register storage, and pragma wrappers; no prototype or symbol changes. Committed at nd 5. */
// FUN_00163C90
s32 func_00163c90(s32 arg0)
{
  u8 sp40[12];
  f32 sp30[3];
  u8 var_5;
  s64 new_var;
  f32 temp_f0;
  s32 temp_2;
  u8 *temp_16;
  s64 temp_s64;
  f32 temp_stack;
  temp_s64 = (new_var = *((s64 *) D_005F1520));
  temp_stack = *((f32 *) D_005F1528);
  *((s64 *) sp40) = temp_s64;
  *((f32 *) (sp40 + 8)) = temp_stack;
  temp_16 = D_007E8C00 + (arg0 * 0x750);
  if ((*((s32 *) (temp_16 + 0x48))) == 0)
  {
    return 1;
  }
  if ((*((s32 *) (temp_16 + 0x54))) != 0)
  {
    return 1;
  }
  if ((*((s32 *) (temp_16 + 0x50))) == 0)
  {
    return 1;
  }
  if (func_004782b0((u8 *)(*((s32 *) (temp_16 + 0x50)))) == 0)
  {
    return 0;
  }
  var_5 = 0;
  if ((*((u8 *) (temp_16 + 0x1CA))) == 1)
  {
    var_5 = 3;
  }
  *((s32 *) (temp_16 + 0x54)) = (s32) func_00145270(func_00145540((arg0 + 0x64) & 0xFFFF, var_5, *((u8 **) (temp_16 + 0x50))) & 0xFFFF);
  func_00479940(*((u8 **) (temp_16 + 0x50)), 0, 0, 0x10, 1);
  func_0047aa30(*((u8 **) (temp_16 + 0x50)), D_005DC920);
  temp_2 = (*((s32 *) (temp_16 + 0x1C0))) - func_0014c780();
  if (temp_2 < (-3))
  {
    *((u8 *) (temp_16 + 0x1CB)) = 0;
  }
  else
    if (temp_2 < (-1))
  {
    *((u8 *) (temp_16 + 0x1CB)) = 1;
  }
  else
    if (temp_2 < 3)
  {
    *((u8 *) (temp_16 + 0x1CB)) = 2;
  }
  else
    if (temp_2 >= 3)
  {
    *((u8 *) (temp_16 + 0x1CB)) = 3;
  }
  if ((*((u8 *) (temp_16 + 0x1CA))) == 1)
  {
    func_0017b9a0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x224)), *((f32 *) (D_005F1340 + ((*((u8 *) (temp_16 + 0x1CB))) * 4))));
  }
  func_0047a1e0((Model *)(*((void **) (temp_16 + 0x50))), (const RwV3d *)((D_005F12E0 + ((*((u8 *) (temp_16 + 0x1CA))) * 0x30)) + ((*((u8 *) (temp_16 + 0x1CB))) * 0xC)), 2);
  func_003e05d0((u8 *)func_0047a2f0(*((void **)  (temp_16 + 0x50))));
  func_00168de0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), sp40, *((f32 *) ((*((u8 **) (temp_16 + 0x1AC))) + 0x14C)));
  func_00168ae0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), (*((u8 **) (temp_16 + 0x1AC))) + 0x140);
  func_0014b0c0(*((u16 *) (*((u8 **) (0x54 + temp_16)))), 1);
  func_00168730(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), 0x40000000);
  func_00168780(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), 35.0f);
  *((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228)) = (s32)func_00478750((u8 *)(iGpffffb274));
  temp_f0 = func_00168770(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)));
  sp30[2] = temp_f0;
  sp30[1] = temp_f0;
  sp30[0] = temp_f0;
  func_0047a1e0((Model *)((*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228)))), (const RwV3d *)(sp30), 2);
  func_00478e70((u8 *) (*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228))));
  *((s32 *) (temp_16 + 0x1B0)) = func_00182220(0, temp_16, *((u8 *) (temp_16 + 0x1CA)));
  *((s32 *) (temp_16 + 0x1B8)) = func_00167420((u8 *) 0, temp_16);
  return 1;
}











// FUN_00163FC0
s32 func_00163fc0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        if (func_00163c90(i) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00164020
void func_00164020(u8 *arg0)
{
    s32 i;
    s32 t48;
    u16 *t54;

    t48 = *(s32 *)(arg0 + 0x48);
    if (t48 != 0) {
        func_002319c0(t48);
        t54 = *(u16 **)(arg0 + 0x54);
        if (t54 != NULL) {
            func_00146630(*t54);
        }
        if ((*(s32 *)(arg0 + 0x50) != 0) &&
            ((*(u16 *)(arg0 + 0x728) == 0) || (*(s32 *)(arg0 + 0x44) == 1))) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(s32 *)(arg0 + 0x50) + i * 0xC + 0x28C) |= 1;
            }
            func_0014b870(*(s32 *)(arg0 + 0x50), 0);
        }
        if (*(s32 *)(arg0 + 0x1B0) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B0));
        }
        if (*(s32 *)(arg0 + 0x734) != 0) {
            DAT_008873EC[0](*(void **)(arg0 + 0x734));
        }
        if (*(s32 *)(arg0 + 0x1B4) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B4));
        }
        if (*(s32 *)(arg0 + 0x1B8) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B8));
        }
        *(s32 *)(arg0 + 0x48) = 0;
        *(s32 *)(arg0 + 0x50) = 0;
        *(s32 *)(arg0 + 0x54) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0;
        *(s32 *)(arg0 + 0x734) = 0;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1B8) = 0;
        if (*(u16 *)(arg0 + 0x1C8) != 0) {
            iGpffffb2e8 -= 1;
        }
    }
}



// FUN_00164170
void func_00164170(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        func_00164020(D_007EF9B0 + i * 0x750);
    }
}



// FUN_001641D0
void func_001641d0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00164020(D_007E8C00 + i * 0x750);
    }
}



/* Keep cache traversal and signed selection lifetimes separate. Script records
   contain fixed 32-byte paths indexed by the 16-bit PC ID. */
// FUN_00164230
void func_00164230(u16 fieldId, u16 roomId, u16 entryId)
{
    u8 **modelSlot;

    {
        u8 *unit;

        unit = func_00162330();
        if (unit != NULL) {
            *(DatUnitPc **)(unit + 0x48) = func_00231580(1);
            *(u8 **)(unit + 0x50) = func_00162680(fieldId, roomId, 1);
            *(u16 *)(unit + 0x728) = 1;
            *(s32 *)(unit + 0x44) = 0;
            *(s32 *)(unit + 0x1C0) = func_00109400(1) & 0xFF;
            *(s32 *)(unit + 0x1C4) = func_00104c70(1) & 0xFF;
            *(u8 **)(unit + 0x1B4) = (u8 *)func_0017d070(NULL);
            *(u16 *)(unit + 0x58) = entryId;
        }
    }
    if (func_00162510(fieldId, roomId) == 1) {
        s32 i;
        u8 *cache;
        u8 *record;

        i = 0;
        while (i < 3) {
            cache = D_007F16F0 + (u32)i * 8;
            if (*(u8 **)(cache + 12) != NULL) {
                s32 j;

                j = 0;
                while (j < 5) {
                    record = *(u8 **)(cache + 12) + (j * 3) * 4;
                    record[0x28C] = record[0x28C] | 1;
                    j += 1;
                }
                record = D_007F16F0 + i * 8;
                modelSlot = (u8 **)(record + 12);
                func_004787e0(*(u8 **)(record + 12));
                *modelSlot = NULL;
                *(u16 *)(record + 8) = 0;
                *(u16 *)(record + 10) = 0;
            }
            i += 1;
        }
    } else {
        u16 pcId;
        s16 selectedId;
        s32 i;
        s32 modelId;
        u8 *unit;
        u8 *cache;
        u8 *record;

        i = 0;
        while (i < 3) {
            selectedId = (s16)func_00105ee0(i);
            if (selectedId > 0) {
                unit = func_00162330();
                if (unit != NULL) {
                    pcId = (u16)selectedId;
                    *(DatUnitPc **)(unit + 0x48) = func_00231580(pcId);
                    modelId = pcId;
                    *(u8 **)(unit + 0x50) = func_00162680(fieldId, roomId, modelId);
                    *(u16 *)(unit + 0x728) = pcId;
                    *(s32 *)(unit + 0x44) = 0;
                    *(s32 *)(unit + 0x1C0) = func_00109400(pcId) & 0xFF;
                    if (modelId == 1) {
                        *(s32 *)(unit + 0x1C4) = func_00104c70((s16)pcId) & 0xFF;
                        *(u8 **)(unit + 0x1B4) = (u8 *)func_0017d070(NULL);
                    } else {
                        func_00440b68((const char *)D_00763008, D_005F1500, 0x1DD);
                        *(u8 **)(unit + 0x730) =
                            func_00454a60(((u8 (*)[32])D_005F13C0)[pcId], 0);
                    }
                    *(u16 *)(unit + 0x58) = entryId;
                }
            } else {
                cache = D_007F16F0 + (u32)i * 8;
                if (*(u8 **)(cache + 12) != NULL) {
                    s32 j;

                    j = 0;
                    while (j < 5) {
                        record = *(u8 **)(cache + 12) + (j * 3) * 4;
                        record[0x28C] = record[0x28C] | 1;
                        j += 1;
                    }
                    record = D_007F16F0 + i * 8;
                    modelSlot = (u8 **)(record + 12);
                    func_004787e0(*(u8 **)(record + 12));
                    *modelSlot = NULL;
                    *(u16 *)(record + 8) = 0;
                    *(u16 *)(record + 10) = 0;
                }
            }
            i += 1;
        }
    }
}



// FUN_00164570
s32 func_00164570(u32 arg0, s32 arg1)
{
    s32 sp6C;
    s32 sp68;
    f32 var_f20;
    s32 temp_3;
    s32 var_17;
    u32 var_2;
    u8 *temp_16;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 0;
    if (D_00764344 == 1) {
        return 0;
    }
    temp_4 = iGpffff9db0;
    temp_3 = *(s32 *)temp_4;
    if ((temp_3 >= 0x28) && (temp_3 < 0x3C) && (*(s32 *)(temp_4 + 4) != 0)) {
        return 0;
    }
    if (arg1 != 0) {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0xBB8)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 2);
            var_17 += 1;
        }
    } else {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0x1770)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 1);
            var_17 += 1;
        }
        var_f20 = (f32)0xBB8;
        if (func_0014a270() == 1) {
            var_f20 = 100.0f;
        }
        while ((temp_2 = func_00164880(var_17, arg0, var_f20)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 0);
            var_17 += 1;
        }
        if ((func_00106330(0x1410) == 0) && (func_00106330(0x1411) == 0)) {
            func_0014c920();
            while (func_0014c960(&sp6C, &sp68) == 1) {
                temp_16 = func_0014cef0(sp6C, sp68);
                if (temp_16 != NULL) {
                    temp_19 = iGpffff9db0;
                    var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
                    if ((var_2 & 0xFFFF) == 0xFFFF) {
                        var_2 = 1;
                    }
                    func_00163990(var_2, temp_16, 0);
                }
            }
        }
    }
    return var_17;
}



s32 func_0014cfd0(u8 *position);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
/* Keep the random node, its rejection state and the loop count in their
   own selection lifetime. The same vector is reused for each distance test. */
static inline u8 *fldChooseRandomSpawn(V3 *delta)
{
    u32 count;
    s32 rejected;
    u8 *choice;
    u8 *cursor;
    s32 index;
    s32 walked;
    s32 used;
    s32 ready;
    u8 *unit;
    u8 *model;
    void **modelSlot;
    f32 coordinate;

retry:
    count = 0;
    rejected = 0;
    cursor = func_001452b0(0xF);
    goto count_test;
count_body:
    count++;
    cursor = *(u8 **)(cursor + 0x138);
count_test:
    if (cursor != NULL) {
        goto count_body;
    }
    count = func_003b7060() % count;
    choice = func_001452b0(0xF);
    walked = 0;
    goto walk_test;
walk_body:
    choice = *(u8 **)(choice + 0x138);
    walked++;
walk_test:
    if (walked < (s32)count) {
        goto walk_body;
    }
    index = 0;
    goto party_test;
party_body:
    used = 0;
    unit = D_007EF9B0 + index * 0x750;
    if (*(s32 *)(unit + 0x48) != 0 && *(s32 *)(unit + 0x54) != 0) {
        used = 1;
    }
    ready = used != 0;
    if (ready) {
        unit = D_007EF9B0 + index * 0x750;
        modelSlot = (void **)(unit + 0x50);
        model = (u8 *)func_0047a2f0(*(void **)(unit + 0x50));
        coordinate = *(f32 *)(model + 0x30);
        delta->x = *(f32 *)(choice + 0x140) - coordinate;
        model = (u8 *)func_0047a2f0(*modelSlot);
        coordinate = *(f32 *)(model + 0x34);
        delta->y = *(f32 *)(choice + 0x144) - coordinate;
        model = (u8 *)func_0047a2f0(*modelSlot);
        coordinate = *(f32 *)(model + 0x38);
        delta->z = *(f32 *)(choice + 0x148) - coordinate;
        if (func_003e4180(&delta->x) < 3000.0f) {
            goto checked_party;
        }
    }
    index++;
party_test:
    if (index < 4) {
        goto party_body;
    }
checked_party:
    if (index < 4) {
        rejected = 1;
    }
    {
        s32 result;
        s32 yes;

        result = func_0014cfd0(choice + 0x140);
        yes = 1;
        if (result == yes || rejected == yes) {
            goto retry;
        }
    }
    return choice;
}

/* Both field modes use genuine position and difference vectors. The
   selection temporary holds the first mode's saved node and the second
   mode's current node in mutually exclusive paths. */
// FUN_00164880
u8 *func_00164880(s32 unused, u32 limit, f32 minimumDistance)
{
    V3 primaryPosition;
    V3 primaryDelta;
    V3 secondaryPosition;
    V3 secondaryDelta;
    f32 primaryDistance;
    f32 secondaryDistance;
    f32 savedPrimaryDistance;
    f32 savedSecondaryDistance;
    f32 bestDistance;
    f32 positionY;
    f32 positionZ;
    s32 primaryUsed;
    s32 ready;
    s32 secondaryUsed;
    u32 secondaryIndex;
    u8 *savedSecondaryNode;
    u8 *selection;
    u8 *primaryEntry;
    u8 *modelX;
    u8 *source;
    u8 *modelOrEntry;
    u8 *secondarySource;
    u8 *primaryRow;
    u8 *primarySpawned;
    u8 *secondaryRow;
    u8 *secondarySpawned;
    u8 *candidate;
    u32 index;
    u8 *best;

    func_001452b0(0xF);
    best = NULL;
    func_0015a160();
    bestDistance = 1.1754944e-38f;
    if (func_0014a200() == 1) {
        if (func_00164f40() < (s32)limit) {
            candidate = func_001452b0(0xF);
            while (candidate != NULL) {
                primaryPosition = *(V3 *)(candidate + 0x140);
                index = 0;
                positionY = primaryPosition.y;
                positionZ = primaryPosition.z;
                goto primary_party_test;
primary_party_body:
                primaryUsed = 0;
                primaryRow = D_007EF9B0 + index * 0x750;
                if (*(s32 *)(primaryRow + 0x48) != 0 && *(s32 *)(primaryRow + 0x54) != 0) {
                    primaryUsed = 1;
                }
                ready = primaryUsed != 0;
                if (ready) {
                    primaryEntry = D_007EF9B0 + index * 0x750;
                    {
                        u8 *modelSlot = primaryEntry + 0x50;

                        modelX = (u8 *)func_0047a2f0(*(void **)(primaryEntry + 0x50));
                        primaryDelta.x = primaryPosition.x - *(f32 *)(modelX + 0x30);
                        source = (u8 *)func_0047a2f0(*(void **)modelSlot);
                        primaryDelta.y = positionY - *(f32 *)(source + 0x34);
                        modelOrEntry = (u8 *)func_0047a2f0(*(void **)modelSlot);
                        primaryDelta.z = positionZ - *(f32 *)(modelOrEntry + 0x38);
                    }
                    if (func_003e4180(&primaryDelta.x) < 3000.0f) {
                        goto primary_party_checked;
                    }
                }
                index++;
primary_party_test:
                if (index < 4U) {
                    goto primary_party_body;
                }
primary_party_checked:
                if (index < 4U) {
                    candidate = *(u8 **)(candidate + 0x138);
                    continue;
                }
                if (func_00164f40() == 0) {
                    return fldChooseRandomSpawn(&primaryDelta);
                }
                if (func_0014cfd0(candidate + 0x140) == 1) {
                    candidate = *(u8 **)(candidate + 0x138);
                    continue;
                }
                savedPrimaryDistance = bestDistance;
                selection = best;
                index = 0;
                goto primary_neighbor_test;
primary_neighbor_body:
                primarySpawned = D_007E8C00 + index * 0x750;
                if (*(s32 *)(primarySpawned + 0x48) != 0) {
                    source = *(u8 **)(primarySpawned + 0x1AC);
                    primaryDelta.x = primaryPosition.x - *(f32 *)(source + 0x140);
                    primaryDelta.y = positionY - *(f32 *)(source + 0x144);
                    primaryDelta.z = positionZ - *(f32 *)(source + 0x148);
                    primaryDistance = func_003e4180(&primaryDelta.x);
                    if (!(primaryDistance <= bestDistance)) {
                        bestDistance = primaryDistance;
                        best = candidate;
                    }
                    if (primaryDistance < minimumDistance) {
                        bestDistance = savedPrimaryDistance;
                        best = selection;
                        goto next_primary_node;
                    }
                }
                index++;
primary_neighbor_test:
                if (index < 0xFU) {
                    goto primary_neighbor_body;
                }
next_primary_node:
                candidate = *(u8 **)(candidate + 0x138);
            }
            goto done;
        }
    } else if (func_0014a270() == 1 && func_00164f40() < (s32)limit) {
        selection = func_001452b0(0xF);
        goto secondary_node_test;
secondary_node_body:
        secondaryPosition = *(V3 *)(selection + 0x140);
        index = 0;
        positionY = secondaryPosition.y;
        positionZ = secondaryPosition.z;
        goto secondary_party_test;
secondary_party_body:
        secondaryUsed = 0;
        secondaryRow = D_007EF9B0 + index * 0x750;
        if (*(s32 *)(secondaryRow + 0x48) != 0 && *(s32 *)(secondaryRow + 0x54) != 0) {
            secondaryUsed = 1;
        }
        ready = secondaryUsed != 0;
        if (ready) {
            modelOrEntry = D_007EF9B0 + index * 0x750;
            {
                u8 *modelSlot = modelOrEntry + 0x50;

                secondarySource = (u8 *)func_0047a2f0(*(void **)(modelOrEntry + 0x50));
                secondaryDelta.x = secondaryPosition.x - *(f32 *)(secondarySource + 0x30);
                source = (u8 *)func_0047a2f0(*(void **)modelSlot);
                secondaryDelta.y = positionY - *(f32 *)(source + 0x34);
                modelX = (u8 *)func_0047a2f0(*(void **)modelSlot);
                secondaryDelta.z = positionZ - *(f32 *)(modelX + 0x38);
            }
            if (func_003e4180(&secondaryDelta.x) < 3000.0f) {
                goto secondary_party_checked;
            }
        }
        index++;
secondary_party_test:
        if (index < 4U) {
            goto secondary_party_body;
        }
secondary_party_checked:
        if (index < 4U) {
            selection = *(u8 **)(selection + 0x138);
            goto secondary_node_test;
        }
        if (func_00164f40() == 0) {
            return selection;
        }
        savedSecondaryDistance = bestDistance;
        savedSecondaryNode = best;
        secondaryIndex = 0;
        goto secondary_neighbor_test;
secondary_neighbor_body:
        secondarySpawned = D_007E8C00 + secondaryIndex * 0x750;
        if (*(s32 *)(secondarySpawned + 0x48) != 0) {
            secondarySource = *(u8 **)(secondarySpawned + 0x1AC);
            secondaryDelta.x = secondaryPosition.x - *(f32 *)(secondarySource + 0x140);
            secondaryDelta.y = positionY - *(f32 *)(secondarySource + 0x144);
            secondaryDelta.z = positionZ - *(f32 *)(secondarySource + 0x148);
            secondaryDistance = func_003e4180(&secondaryDelta.x);
            if (!(secondaryDistance <= bestDistance)) {
                bestDistance = secondaryDistance;
                best = selection;
            }
            if (secondaryDistance < minimumDistance) {
                bestDistance = savedSecondaryDistance;
                best = savedSecondaryNode;
                goto next_secondary_node;
            }
        }
        secondaryIndex++;
secondary_neighbor_test:
        if (secondaryIndex < 0xFU) {
            goto secondary_neighbor_body;
        }
next_secondary_node:
        selection = *(u8 **)(selection + 0x138);
secondary_node_test:
        if (selection != NULL) {
            goto secondary_node_body;
        }
    }
done:
    return best;
}
#pragma pop


// FUN_00164F40
s32 func_00164f40(void)
{
    return iGpffffb2e8;
}



// FUN_00164F50
void func_00164f50(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00164fa0(i);
    }
}



/* 708/720 bytes; forty resolved relocations; twelve zero alignment bytes.
 * Preserve repeated unit-base multiplies and the link destination lifetime. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00164FA0
void func_00164fa0(s32 arg0)
{
    f32 sp70[3];
    f32 temp_f0;
    s32 *temp_21;
    s32 *link;
    s32 stride;
    s32 temp_17;
    s32 temp_2_2;
    s32 temp_3;
    s32 temp_4;
    u16 actorId;
    u8 **temp_16;
    u8 **temp_20;
    u8 **temp_20_2;
    u8 *temp_18;
    u8 *temp_2;
    u8 *var_2;
    u8 *var_6;
    s32 i;

    temp_17 = arg0 * 0x750;
    temp_21 = (s32 *)(D_007EF9F8 + temp_17);
    if (*temp_21 != 0) {
        temp_16 = (u8 **)(D_007EFA00 + temp_17);
        actorId = func_00145540(arg0 & 0xFFFF, 3, *temp_16) & 0xFFFF;
        temp_20 = (u8 **)(D_007EFA04 + temp_17);
        temp_2 = (u8 *)func_00145270(actorId);
        *temp_20 = temp_2;
        func_0017b9a0(*(s32 *)(temp_2 + 0x224), 60.0f);
        temp_18 = D_007EF9B0 + temp_17;
        var_2 = (u8 *)func_0047a2f0(*temp_16);
        i = 8;
        var_6 = temp_18;
        do {
            temp_4 = *(s32 *)var_6;
            temp_3 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            i -= 1;
            *(s32 *)var_2 = temp_4;
            *(s32 *)(var_2 + 4) = temp_3;
            var_2 += 8;
        } while (i > 0);
        func_003e05d0((u8 *)func_0047a2f0(*temp_16));
        func_0014b0c0(*(u16 *)*temp_20, 1);
        func_00168730(*((s32 *)(*temp_20 + 0x220)), 0x40000000);
        func_00168c00(*((s32 *)(*temp_20 + 0x220)));
        if (arg0 == 0) {
            func_00168780(*((s32 *)(*temp_20 + 0x220)), 60.0f);
        } else {
            func_00168780(*((s32 *)(*temp_20 + 0x220)), 35.0f);
        }
        temp_20_2 = (u8 **)(D_007EFA04 + (arg0 * 0x750));
        *(u8 **)(*temp_20_2 + 0x228) = (u8 *)func_00478750((u8 *)(iGpffffb274));
        temp_f0 = func_00168770(*((s32 *)(*temp_20_2 + 0x220)));
        sp70[0] = sp70[1] = sp70[2] = temp_f0;
        func_0047a1e0((Model *)(*(u8 **)(*temp_20_2 + 0x228)), (const RwV3d *)(&sp70[0]), 2);
        func_00478e70(*(u8 **)(*temp_20_2 + 0x228));
        if (func_002319f0(*temp_21) == 0) {
            func_00479940(*temp_16, 0, (s16)func_0016fd00(*(u16 *)(D_007F00D8 + (arg0 * 0x750))), 0, 1);
        }
        if (arg0 != 0) {
            stride = 0x750;
            link = (s32 *)(D_007EFB60 + arg0 * stride);
            temp_2_2 = func_0017e890(0, temp_18, D_007EF9B0 + ((arg0 - 1) * stride));
            *link = temp_2_2;
            func_0017e990(temp_2_2);
        }
        if (arg0 == 0) {
            *(s32 *)(D_007EFB64 + temp_17) = func_0017d070(0);
        }
    }
}
#pragma pop



// FUN_00165270
void func_00165270(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0) {
            *(s32 *)(p + 0x50) = (s32)func_00478140(8, (u16)(*(u8 *)(p + 0x1CA) + 1), 0);
        }
    }
}



// FUN_00165300
s32 func_00165300(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0 && func_004782b0((u8 *)(*(s32 *)(p + 0x50))) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00165380
/* nd 148 -> 0 (the old "GVN merges the slot address" floor). Each section-local
   `slot = D_007E8C00 + i * 0x750` reassignment (A, B, C, the 0x1CB read, the
   func_00167420 argument) must rematerialise; `slot += 0x54` must stay an addiu
   between the two calls (`t2 = t1 & 0xFFFF` first so the andi precedes it); the
   0x1CB read goes through `p = ...` so its recompute precedes the arg-0 load. */
/* measured: opt_common_subs off rematerialises the slot address per assignment;
   opt_propagation off keeps the pointer bump out of the store offset. */
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00165380(void)
{
    s32 i;
    u8 *slot;
    u8 *f1ca;
    u8 *f50;
    u8 *f54;
    u8 *f1b8;
    u8 *p;
    u8 var_5;
    u8 *src;
    s32 n;
    u8 *dst;
    s32 t1;
    s32 t2;
    f32 sp50[3];
    f32 temp_f0;

    for (i = 0; i < 0xF; i++) {
        slot = D_007E8C00 + i * 0x750;
        if (*(s32 *)(slot + 0x48) != 0) {
            var_5 = 0;
            *(s32 *)(slot + 0x40) &= ~2;
            f1ca = slot + 0x1CA;
            if (*f1ca == 1) {
                var_5 = 3;
            }
            slot = D_007E8C00 + i * 0x750;
            f50 = slot + 0x50;
            t1 = func_00145540((i + 0x64) & 0xFFFF, var_5, *(u8 **)(slot + 0x50));
            t2 = t1 & 0xFFFF;
            slot += 0x54;
            *(s32 *)slot = (s32)func_00145270(t2);
            func_0047aa30(*(u8 **)f50, D_005DC920);
            if (*f1ca == 1) {
                p = D_007E8C00 + i * 0x750;
                func_0017b9a0(*(s32 *)(*(u8 **)slot + 0x224), *(f32 *)(D_005F1340 + *(u8 *)(p + 0x1CB) * 4));
            }
            slot = D_007E8C00 + i * 0x750;
            f1ca = slot + 0x1CA;
            f50 = slot + 0x50;
            func_0047a1e0((Model *)(*(void **)f50), (const RwV3d *)(D_005F12E0 + *f1ca * 0x30 + *(u8 *)(slot + 0x1CB) * 0xC), 2);
            dst = (u8 *)func_0047a2f0(*(void **)f50);
            n = 8;
            src = slot;
            do {
                t1 = *(s32 *)src;
                t2 = *(s32 *)(src + 4);
                src += 8;
                n -= 1;
                *(s32 *)dst = t1;
                *(s32 *)(dst + 4) = t2;
                dst += 8;
            } while (n > 0);
            func_003e05d0((u8 *)func_0047a2f0(*(void **)f50));
            f54 = slot + 0x54;
            func_0014b0c0(*(u16 *)(*(u8 **)f54), 1);
            func_00168730(*(s32 *)(*(u8 **)f54 + 0x220), 0x40000000);
            func_00168c00(*(s32 *)(*(u8 **)f54 + 0x220));
            func_00168780(*(s32 *)(*(u8 **)f54 + 0x220), 35.0f);
            *(s32 *)(*(u8 **)f54 + 0x228) = (s32)func_00478750((u8 *)(iGpffffb274));
            temp_f0 = func_00168770(*(s32 *)(*(u8 **)f54 + 0x220));
            sp50[2] = temp_f0;
            sp50[1] = temp_f0;
            sp50[0] = temp_f0;
            func_0047a1e0((Model *)(*(s32 *)(*(u8 **)f54 + 0x228)), (const RwV3d *)(sp50), 2);
            func_00478e70((u8 *)*(s32 *)(*(u8 **)f54 + 0x228));
            *(s32 *)(slot + 0x1B0) = func_00182220(0, slot, *f1ca);
            f1b8 = slot + 0x1B8;
            if (*(s32 *)f1b8 == 0) {
                *(s32 *)f1b8 = func_00167420((u8 *)0, D_007E8C00 + i * 0x750);
            }
        }
    }
}
/* measured: closes the two brackets above; the file default is on. */
#pragma opt_common_subs on
#pragma opt_propagation on



// FUN_00165670
void func_00165670(u8 *arg0, s32 arg1)
{
    u8 *p = arg0;
    u8 *q;
    u8 *s;
    u8 *d;
    s32 n;
    s32 v;
    s32 i;
    v = *(u32 *)(p + 0x48) != 0 && *(u32 *)(p + 0x54) != 0;
    if (v != 0) {
        q = (u8 *)func_0047a2f0(*(void **)(p + 0x50));
        s = q;
        n = 8;
        d = p;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            n--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (n > 0);
        func_00146630(*(u16 *)(*(u32 *)(p + 0x54)));
        *(u32 *)(p + 0x54) = 0;
        if (*(u32 *)(p + 0x50) != 0) {
            func_0047a870(*(u32 *)(p + 0x50));
            func_0047a220(*(u32 *)(p + 0x50), D_00763010);
        }
        if (*(u32 *)(p + 0x50) != 0 && arg1 == 1) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u32 *)(p + 0x50) + i * 12 + 0x28C) |= 1;
            }
            func_004787e0(*(u8 **)(p + 0x50));
            *(u32 *)(p + 0x50) = 0;
        }
        if (*(u32 *)(p + 0x1B0) != 0) {
            func_00452080(*(u32 *)(p + 0x1B0));
            *(u32 *)(p + 0x1B0) = 0;
        }
        if (*(u32 *)(p + 0x1B8) != 0) {
            func_00452080(*(u32 *)(p + 0x1B8));
            *(u32 *)(p + 0x1B8) = 0;
        }
        if (*(u32 *)(p + 0x1B4) != 0) {
            func_00452080(*(u32 *)(p + 0x1B4));
            *(u32 *)(p + 0x1B4) = 0;
        }
    }
}



// FUN_001657E0
void func_001657e0(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00165670(D_007EF9B0 + i * 0x750, 0);
    }
}



// FUN_00165840
void func_00165840(s32 arg0)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00165670(D_007E8C00 + i * 0x750, arg0);
    }
}



/* Keep the saved halfword and allocator word in the same assignment chain. */
// FUN_001658B0
void func_001658b0(void)
{
    s32 i;
    s32 j;
    u16 code;
    u32 modelCode;
    s32 value;
    s32 count;

    count = 0;
    j = 0;
    func_0043f9c8(D_007E8BE0, 0, 0x20);
    D_007E8BE8[0] = -1;
    D_007E8BF8[0] = -1;
    if (func_0014a200() == 0) {
        goto done;
    }
    if (func_0014a200() != 0) {
        goto loop;
    }
done:
    return;
loop:
    for (i = 0; i < 8; i++) {
        value = func_0015a160();
        if (value == func_001064f0(i + 1)) {
            s32 state;
            s32 parity;
            s32 base;
            base = 10;
            state = func_00110d60((s16)func_001060b0());
            parity = state & 1;
            if (state < 0 && parity != 0) {
                parity -= 2;
            }
            if (parity != 0) {
                base = 20;
            }
            if (i < 6) {
                value = i + 2;
                modelCode = code = (u16)((value << 8) | base);
            } else if (i == 6) {
                modelCode = code = 0x80A;
                value = i + 2;
            } else {
                modelCode = code = 0x120A;
                value = 9;
            }
            if (count >= 2) {
                func_0046d730(D_005F1500, 0x916);
            }
            if (D_007643C8[count] != 0) {
                func_0046d730(D_005F1500, 0x917);
            }
            D_007643C8[count] = (s32)func_00478140(9, modelCode, 0);
            func_00440b68((const char *)D_00763008, D_005F1500, 0x91C);
            D_007643C0[count] =
                (s32)func_00454a60(D_005F13C0 + value * 0x20, 0);
            *(s32 *)(D_007E8BE0 + j * 16) = 1;
            *(u16 *)(D_007E8BE0 + j * 16 + 4) = 9;
            *(u16 *)(D_007E8BE0 + j * 16 + 6) = code;
            *(s32 *)(D_007E8BE0 + j * 16 + 0xC) = value;
            j++;
            count++;
        }
    }
}



// FUN_00165B00
void func_00165b00(void)
{
    s32 i;
    s32 j = 0;
    for (i = 0; i < 2; i++) {
        u8 *p = D_007E8BE0 + i * 16;
        if (*(s32 *)p != 0) {
            D_007643C8[j] = (s32)func_00478140(*(u16 *)(p + 4), *(u16 *)(p + 6), 0);
            func_00440b68((const char *)D_00763008, D_005F1500, 0x939);
            D_007643C0[j] = (s32)func_00454a60(D_005F13C0 + (*(s32 *)(p + 0xC) << 5), 0);
            j++;
        }
    }
}



/* measured: b210 -O2 emits 964 bytes and twelve zero alignment bytes.
 * Loop-invariant motion preserves the active-record comparison. Disabling
 * constant extraction keeps the scale stores inside the creation loop;
 * propagation-off retains the file-slot and selected-index address lifetimes.
 * Readiness uses the two owner handle arrays; D_007E8BE0 holds selection rows.
 * Evidence: build/first-party-continue-live/field/constructor-release/. */
// FUN_00165BE0
#pragma push
#pragma opt_pulloutconstants off
#pragma opt_propagation off
#pragma opt_loop_invariants on
s32 func_00165be0(void)
{
    u8* instance;
    s32 pair;
    u8* node;
    s32 handleOffset;
    u8* modelSlot;
    s32 resourceIndex;
    s32 nodeCount;
    s32* selection;
    s32 modelHandle;
    s32 fileHandle;
    u16 resourceId;
    void* allocation;
    RwV3d scale;

    if (func_0014a200() == 0 || func_0014a200() == 0)
    {
        return 1;
    }
    for (resourceIndex = 0; resourceIndex < 2; resourceIndex++)
    {
        modelHandle = D_007643C8[resourceIndex];
        if (modelHandle != 0 && func_004782b0((u8 *)(modelHandle)) == 0)
        {
            return 0;
        }
        fileHandle = D_007643C0[resourceIndex];
        if (fileHandle != 0 && func_004553c0((HCdvd *)(fileHandle)) == 0)
        {
            return 0;
        }
    }
    {
        u8* cursor = func_001452b0(0x11);
        nodeCount = 0;
        while (cursor != NULL)
        {
            nodeCount++;
            cursor = *(u8**)(cursor + 0x138);
        }
    }
    if (nodeCount == 0)
    {
        return 1;
    }
    if (nodeCount == 0)
    {
        func_0046d730(D_005F1500, 0x965);
    }
    if (nodeCount % 2 != 0)
    {
        func_0046d730(D_005F1500, 0x966);
    }
    pair = (s32)(func_003b7060() % (u32)(nodeCount >> 1));
    {
        typedef struct FldPairSelection
        {
            s32 active;
            u32 field04;
            s32 nodeIndex;
            s32 actorId;
        } FldPairSelection;
        s32 index;
        u8* records;

        index = 0;
        records = D_007E8BE0;
        for (; index < 2; index++)
        {
            FldPairSelection* record = (FldPairSelection*)(records + index * 16);
            if (record->active != 1)
            {
                continue;
            }
            selection = &record->nodeIndex;
            if (*selection >= 0)
            {
                continue;
            }
            *selection = pair + index;
        }
    }
    if (D_007E8BE8[0] >= 0)
    {
        pair = D_007E8BE8[0];
    }
    node = func_001452b0(0x11);
    {
        s32 steps;
        s32 walked;

        walked = 0;
        steps = (s32)((u32)pair * 2U);
        while (walked < steps)
        {
            walked++;
            node = *(u8**)(node + 0x138);
        }
    }
    for (pair = 0; pair < 2; pair++)
    {
        handleOffset = pair * 4;
        modelSlot = (u8*)D_007643C8 + handleOffset;
        modelHandle = *(s32*)modelSlot;
        if (modelHandle == 0)
        {
            continue;
        }
        resourceId = func_00145780((u16)(0x3FF - pair), 3, modelHandle);
        func_0014b0c0(resourceId, 1);
        instance = (u8*)func_00145270(resourceId);
        *(s32*)(instance + 0x234) = 3;
        {
            u8* loaded;
            loaded = (u8*)*(s32*)((u8*)D_007643C0 + handleOffset);
            if (loaded != NULL)
            {
                u8* fileSlot;
                fileSlot = (u8*)&D_007643C0[(u32)pair];
                *(u32*)(instance + 0x28C) = *(u32*)(loaded + 0x118);
                func_0044ea90(D_005F1500, 0x990);
                allocation = DAT_008873F4[0](1, *(u32*)(instance + 0x28C), 0x40000);
                *(void**)(instance + 0x288) = allocation;
                {
                    u8* file = (u8*)*(s32*)fileSlot;
                    func_0043f810(allocation, (const void *)(*(void**)(file + 0x110)), *(u32*)(instance + 0x28C));
                }
                func_00454bd0((HCdvd *)(*(s32*)fileSlot));
                *(s32*)fileSlot = 0;
            }
        }
        {
            s32 model;
            model = (s32)func_00478750((u8 *)(iGpffffb274));
            *(s32*)(instance + 0x22C) = model;
            scale.x = scale.y = scale.z = 30.0f;
            func_0047a1e0((Model *)(*(s32*)(instance + 0x22C)), &scale, 2);
            func_00478e70(*(u8**)(instance + 0x22C));
            func_0047a1a0(*(void**)(instance + 0x164), D_00756510, *(f32*)(node + 0x14C), 2);
            func_0047a180(*(void**)(instance + 0x164), (void*)(node + 0x140), 2);
            *(s32*)(instance + 0x294) = func_0018bb20(*(s32*)(instance + 0x228), (s32)(instance));
            node = *(u8**)(node + 0x138);
            *(s32*)modelSlot = 0;
        }
    }
    return 1;
}
#pragma pop



/* measured: func_00165fb0 is an exact C match (object 796B, window 800B, normalized_diff 0). Retail computes the +4 byte first and keeps it live in $a1 while computing +7 into $v0; reusing the existing temp_4 loop temporary for the +4 assignment reproduces that liveness order and both endpoint stores. */
/* The archived nd2 body had the endpoint temporaries reversed; naming/order probes did not move them. This liveness change preserves the 796B object and closes both prior residual words. */
// FUN_00165FB0
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_17;
    s32 temp_21;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4_2;
    u8 *temp_6;
    u8 *var_18;
    u8 color3;
    u8 color1;
    u8 color2;
    u8 color0;

    if (arg0 != NULL) {
        temp_17 = (s32)(((*(u8 **)(arg0 + 0x160) + 7)[0] & 1) != 0);
        *(u16 *)(arg0 + 0xC) = (u16)func_00145ac0(arg2 & 0xFFFF, (s32)func_00478750((u8 *)(*(s32 *)(func_0015a320()))));
        temp_2 = (u8 *)func_00145270(*(u16 *)(arg0 + 0xC));
        func_0047aa30(*(u8 **)(temp_2 + 0x144), D_005DC920);
        temp_21 = temp_17 * 0xC;
        func_0047a1e0((Model *)(*(u8 **)(temp_2 + 0x144)), (const RwV3d *)(D_005F1530 + temp_21), 2);
        func_0047a1a0(*(u8 **)(temp_2 + 0x144), D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a180((RwMatrix *)*(u8 **)(temp_2 + 0x144), (const RwV3d *)(arg1 + 0x140), 2);
        if (*(s32 *)(arg0 + 8) != 0) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 2, 0, 0);
        } else if (temp_17 == 1) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 3, 0, 0);
        }
        temp_3 = *(u8 **)(temp_2 + 0x144);
        *(s32 *)(temp_3 + 0xD8) |= 0x80;
        temp_3_2 = *(u8 **)(temp_2 + 0x144);
        var_18 = *(u8 **)(*(u8 **)(temp_3_2 + 0x2CC));
        temp_6 = *(u8 **)(temp_3_2 + 0x124);
        temp_4 = iGpffff9f28;
        color1 = iGpffff9f29;
        color2 = iGpffff9f2a;
        color0 = iGpffff9f2b;
        temp_6[4] = temp_4;
        temp_6[5] = color1;
        temp_6[6] = color2;
        temp_6[7] = color0;
        while (var_18 != NULL) {
            temp_4 = *(s32 *)(var_18 + 8);
            if (temp_4 != 0) {
                func_004b13f0((u8 *)temp_4, (u8 *)&iGpffff9f28);
            }
            var_18 = *(u8 **)(var_18 + 0x10);
        }
        if (temp_17 == 1) {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), (u8 *)&iGpffff9f24);
        } else {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), D_005F1570 + ((func_0015a160() / 20U) * 4));
        }
        temp_2_2 = (u8 *)func_00478750((u8 *)(D_00764364));
        *(u8 **)(temp_2 + 0x16C) = temp_2_2;
        func_0047a1a0(temp_2_2, D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a1e0((Model *)(*(u8 **)(temp_2 + 0x16C)), (const RwV3d *)(D_005F1550 + temp_21), 2);
        func_0047a180((RwMatrix *)*(u8 **)(temp_2 + 0x16C), (const RwV3d *)(arg1 + 0x140), 2);
        temp_4_2 = *(u8 **)(temp_2 + 0x16C);
        *(u8 **)(arg0 + 0x164) = temp_4_2;
        func_00478e70(temp_4_2);
        temp_17_2 = (s32)((600.0f + *(f32 *)(arg1 + 0x140)) / 1200.0f);
        temp_18 = (s32)((600.0f + *(f32 *)(arg1 + 0x148)) / 1200.0f);
        *(u8 **)(temp_2 + 0x140) = (u8 *)func_00145270(*(u16 *)((u8 *)func_00155280() + (temp_18 << 8) + (temp_17_2 * 0x10) + 0x56));
        func_0014a0f0(*(u16 *)(arg0 + 0xC), 1);
        iGpffffb2e4 += 1;
    }
}

// FUN_001662D0
void func_001662d0(void)
{
    u32 sp6C;
    u32 t17;
    u8 *src;
    u8 *s19;
    u8 *p;
    u8 *slotp;
    s32 i;
    s32 j;
    u16 h0;
    u16 h4;
    u8 *dp;
    u8 *s;
    u8 *d;
    s32 k;

    t17 = func_0015a160();
    if (iGpffffb260 == 1) {
        return;
    }
    func_0043f9c8(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    h0 = *(u16 *)iGpffff9db0;
    h4 = *(u16 *)(iGpffff9db0 + 4);
    s19 = (u8 *)func_00161b10(h0, h4, t17);
    if (s19 == 0) {
        return;
    }
    if (func_0015a320() == 0) {
        return;
    }
    i = 0;
    while ((src = func_00166600(s19, &sp6C, i)) != NULL) {
        h0 = *(u16 *)iGpffff9db0;
        h4 = *(u16 *)(iGpffff9db0 + 4);
        p = func_00161c80(h0, h4, t17, 2);
        if (p == NULL) {
            func_0046d730(D_005F1500, 0xA63);
        }
        slotp = NULL;
        j = 0;
        dp = D_007E80A0;
        for (; j < 8; j++) {
            if (*(s32 *)(dp + j * 0x168) == 0) {
                slotp = dp + j * 0x168;
                break;
            }
        }
        *(s32 *)slotp = 1;
        *(s32 *)(slotp + 0x160) = (s32)p;
        *(s16 *)(slotp + 0xE) = (s16)sp6C;
        d = slotp + 0x10;
        k = 0x2A;
        s = src;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            k--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (k > 0);
        func_00165fb0(slotp, src, 0x3FE - i);
        i++;
    }
}

// FUN_001664A0
void func_001664a0(void)
{
    s32 i;
    s32 k;
    s32 j = 0;
    u8 *node;
    u8 *p;
    if (D_00764350 != 1) {
        for (i = 0; i < 8; i++) {
            p = D_007E80A0 + i * 360;
            if (*(s32 *)p != 0) {
                node = func_001452b0(0x10);
                if (node == 0) {
                    return;
                }
                for (k = 0; k < *(u16 *)(p + 0xE); k++) {
                    node = *(u8 **)(node + 0x138);
                    if (node == 0) {
                        func_0046d730(D_005F1500, 0xA87);
                    }
                }
                {
                    u8 *s;
                    u8 *d;
                    s32 n;
                    d = D_007E80A0 + (u32)i * 360 + 0x10;
                    n = 0x2A;
                    s = node;
                    do {
                        u32 w0 = *(u32 *)s;
                        u32 w1 = *(u32 *)(s + 4);
                        s += 8;
                        n--;
                        *(u32 *)d = w0;
                        *(u32 *)(d + 4) = w1;
                        d += 8;
                    } while (n > 0);
                }
                func_00165fb0(D_007E80A0 + (u32)i * 360, node, 0x3FE - j);
                j++;
            }
        }
    }
}
// FUN_00166600
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2)
{
    V3 pos;
    V3 vec;
    f32 temp_f0;
    f32 var_f22;
    f32 var_f23;
    u8 *var_19;
    u8 *var_18;
    u8 *temp_3;
    s32 var_2;
    s32 var_21;
    s32 var_17;
    s32 var_16;

    var_19 = func_001452b0(0x10);
    var_18 = NULL;
    func_0015a160();
    *arg1 = 0;
    var_16 = 0;
    if (func_0014a200() == 1) {
        if (iGpffffb2e4 < (s32)arg0) {
            var_f22 = 1.1754944e-38f;
            while (var_19 != NULL) {
                pos = *(V3 *)(var_19 + 0x140);
                vec.x = pos.x - *(f32 *)((u8 *)func_0047a2f0(*(u8 **)D_007EFA00) + 0x30);
                vec.y = pos.y - *(f32 *)((u8 *)func_0047a2f0(*(u8 **)D_007EFA00) + 0x34);
                vec.z = pos.z - *(f32 *)((u8 *)func_0047a2f0(*(u8 **)D_007EFA00) + 0x38);
                if (func_003e4180(&vec.x) < 500.0f) {
                    var_19 = *(u8 **)(var_19 + 0x138);
                    var_16 += 1;
                } else {
                    if (iGpffffb2e4 == 0) {
                        return var_19;
                    }
                    var_f23 = 1.1754944e-38f;
                    var_21 = 0;
                    var_17 = 0;
                    while (var_17 < 8) {
                        temp_3 = D_007E80A0 + var_17 * 0x168;
                        if (*(s32 *)temp_3 != 0) {
                            vec.x = pos.x - *(f32 *)(temp_3 + 0x150);
                            vec.y = pos.y - *(f32 *)(temp_3 + 0x154);
                            vec.z = pos.z - *(f32 *)(temp_3 + 0x158);
                            temp_f0 = func_003e4180(&vec.x);
                            if (temp_f0 < 100.0f) {
                                var_21 = 1;
                                break;
                            }
                            var_f23 += temp_f0;
                        }
                        var_17 += 1;
                    }
                    if (var_21 == 1) {
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    } else {
                        if (!(var_f23 <= var_f22)) {
                            var_f22 = var_f23;
                            *arg1 = var_16;
                            var_18 = var_19;
                        }
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    }
                }
            }
        }
    } else if (func_0014a270() == 1) {
        var_2 = 0;
        while (var_19 != NULL) {
            if (var_2 == arg2) {
                *arg1 = arg2;
                var_18 = var_19;
                break;
            }
            var_19 = *(u8 **)(var_19 + 0x138);
            var_2 += 1;
        }
    }
    return var_18;
}






// FUN_001668E0
s32 func_001668e0(u8 *arg0)
{
    s32 temp_3;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_2;
    s32 var_2_2;
    u32 temp_2;
    u32 var_17;
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }
    if (*(s32 *)(temp_16 + 8) == 1) {
        return 0;
    }
    switch (*(s32 *)temp_16) {
    case 0:
        iGpffffb2e8 = 0;
        var_17 = *(u32 *)(temp_16 + 0xC);
        if (var_17 == -1U) {
            temp_17 = iGpffff9db0;
            var_17 = func_001619b0(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        }
        if (func_0014a270() == 1) {
            var_17 = *(u32 *)(temp_16 + 0xC);
            if (var_17 == -1U) {
                var_17 = 0xF;
            }
        }
        func_00164570(var_17, 0);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        var_17_2 = 0;
        while (var_17_2 < 0xF) {
            if (func_00163c90(var_17_2) == 0) {
                var_2 = 0;
                goto out1;
            }
            var_17_2 += 1;
        }
        var_2 = 1;
    out1:
        if (var_2 != 0) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        var_17_3 = 0;
        while (var_17_3 < 0xF) {
            if (func_00163c90(var_17_3) == 0) {
                var_2_2 = 0;
                goto out2;
            }
            var_17_3 += 1;
        }
        var_2_2 = 1;
    out2:
        if (var_2_2 != 0) {
            func_00182310(0);
            *(s32 *)temp_16 += 1;
        }
        break;
    case 3:
        temp_17 = iGpffff9db0;
        temp_2 = func_00161a70(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        if ((u32)iGpffffb2e8 < temp_2 && func_00164570(temp_2, 1) > 0) {
            *(s32 *)temp_16 = 2;
        }
        break;
    }
    return 0;
}

// FUN_00166B10
void func_00166b10(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00166B40
s32 func_00166b40(u8 *arg0, s32 arg1)
{
    s32 r;
    s32 task;
    if (func_0014a200() == 0 && func_0014a270() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xB93);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F1590), 0xF, 0, 0, func_001668e0, func_00166b10, (u8 *)(r));
    *(s32 *)(r + 0xC) = arg1;
    return task;
}



// FUN_00166C30
u32 func_00166c30(u8 *arg0)
{
    if (arg0 == 0) {
        return 1;
    } else {
        return (*(u32 *)(*(u32 *)(arg0 + 0x38)) ^ 3) < 1;
    }
}



// FUN_00166C60
void func_00166c60(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        *(s32 *)(*(u32 *)(arg0 + 0x38) + 4) = arg1;
    }
}



// FUN_00166C80
s32 func_00166c80(u8 *arg0)
{
    u8 *p;
    u8 *node;
    u8 *q;
    u8 buf1[4];
    u8 buf2[3];
    u8 buf3[3];
    s32 f;
    s32 i;
    p = *(u8 **)(arg0 + 0x38);
    func_0044b7b0(D_007613EC * (f32)(*(s32 *)(p + 8)) / 10.0f);
    q = func_0047a250(*(u32 *)(*(u32 *)(p + 4) + 0x50));
    *(S4 *)buf1 = *(S4 *)q;
    buf1[0] = 0x34;
    buf1[1] = 0x2E;
    buf1[2] = 0x61;
    *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    if (*(s32 *)(p + 8) > 10) {
        *(s32 *)(p + 8) = 0;
    }
    f = *(u8 *)(*(u32 *)(p + 4) + 0x1CA);
    if (f == 0) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        node = *(u8 **)b;
        while (node != NULL) {
            if (*(u8 **)(node + 8) != NULL) {
                func_004b14f0(*(u8 **)(node + 8), buf2);
                buf2[0] = 0xFF;
                buf2[1] = 0xFF;
                buf2[2] = 0xFF;
                func_004b13f0(*(u8 **)(node + 8), buf2);
            }
            node = *(u8 **)(node + 0x10);
        }
    } else if (f == 1) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        u8 *c = *(u8 **)b;
        u8 *d = *(u8 **)(c + 0x10);
        node = *(u8 **)(d + 0x10);
        if (*(u8 **)(node + 8) != NULL) {
            func_004b14f0(*(u8 **)(node + 8), buf3);
            buf3[0] = buf1[0];
            buf3[1] = buf1[1];
            buf3[2] = buf1[2];
            func_004b13f0(*(u8 **)(node + 8), buf3);
        }
    }
    func_0047a220(*(u32 *)(*(u32 *)(p + 4) + 0x50), buf1);
    return 0;
}



/* measured: same three defects as sibling func_00167120 (see its note): (1)
   (u8) conversions emit c.ole.s 0x46010036 vs retail 0x46000036 — 3 words,
   nLine func_0034c500 floor; (2) temp_f20 (func_0044b7b0 result) spilled to
   the stack instead of $f20 — frame 0x40 vs 0x50; (3) the four sp4C-4F byte
   copies interleave lbu/sb. The madd.s (175+70x) and msub.s (37-10x,
   255-200x) fused expressions and the 0x28 store match. */
// FUN_00166E30
s32 func_00166e30(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    s32 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_4;
    u8 *var_17;
    u8 temp_byte0;
    u8 temp_byte1;
    u8 temp_byte2;
    u8 temp_byte3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f20 = func_0044b7b0(D_007613EC *
                             (f32)(*(s32 *)(temp_16 + 8)) /
                             (f32)(*(s32 *)(temp_16 + 0xC)));
    temp_2 = func_0047a250(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50));
    temp_byte0 = *temp_2++;
    temp_byte1 = *temp_2++;
    temp_byte2 = *temp_2++;
    temp_byte3 = *temp_2++;
    sp4C[0] = temp_byte0;
    sp4C[1] = temp_byte1;
    sp4C[2] = temp_byte2;
    sp4C[3] = temp_byte3;
    *(s32 *)(temp_16 + 0xC) = 0x28;
    temp_f1 = (175.0f + 0.0f) + (70.0f * temp_f20);
    sp4C[0] = (u8)temp_f1;
    temp_f1_2 = (37.0f + 0.0f) - (10.0f * temp_f20);
    sp4C[1] = (u8)temp_f1_2;
    temp_f1_3 = (255.0f + 0.0f) - (208.0f * temp_f20);
    sp4C[2] = (u8)temp_f1_3;
    temp_3 = *(s32 *)(temp_16 + 8) + 1;
    *(s32 *)(temp_16 + 8) = temp_3;
    if (*(s32 *)(temp_16 + 0xC) < temp_3) {
        *(s32 *)(temp_16 + 8) = 0;
    }
    temp_4 = *(u8 **)(temp_16 + 4);
    temp_3_2 = *(u8 *)(temp_4 + 0x1CA);
    if (temp_3_2 == 0) {
        var_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        var_17 = *(u8 **)var_17;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)(var_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(var_17 + 8), sp48);
            sp48[0] = 0xFF;
            sp48[1] = 0xFF;
            sp48[2] = 0xFF;
            func_004b13f0(*(u8 **)(var_17 + 8), sp48);
        }
        var_17 = *(u8 **)(var_17 + 0x10);
loop_16_check:
        if (var_17 == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (temp_3_2 == 1) {
        temp_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        temp_17 = *(u8 **)temp_17;
        temp_17 = *(u8 **)(temp_17 + 0x10);
        temp_17 = *(u8 **)(temp_17 + 0x10);
        if (*(s32 *)(temp_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(temp_17 + 8), sp44);
            sp44[0] = sp4C[0];
            sp44[1] = sp4C[1];
            sp44[2] = sp4C[2];
            func_004b13f0(*(u8 **)(temp_17 + 8), sp44);
        }
    }
mode_done:
    func_0047a220(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50), sp4C);
    return 0;
}



/* measured: nd 164 after four attempts. The u8 sp buffer must be ONE array
   (separate u8 locals get dead-store-eliminated — only the address-taken
   byte aliases; cascades into the sp[9]/sp[10] conversions). The saturation
   idiom from gc_model.c (if (x < 2.1474836e9f) {(u8)(s32)x} else {(u8)(s32)
   (x - 2.1474836e9f)}) reproduces the cvt.w.s guard for VARIABLE values
   (blocks 2/3), but: (1) block 1's 255.0f constant still folds the whole
   compare+guard away under mwccgap (real b210 emitted c.ole.s/bc1t for it;
   tried literal, single- and multi-assigned f32 locals — all fold); (2) the
   guard comes out c.olt.s+bc1f with the normal arm inline where retail has
   c.ole.s $f0,$f1 + bc1t with the saturate arm out of line — 2 words per
   block; (3) temp_4_2 lands in $s2 (frame 0x60) where retail keeps it in a
   caller-saved temp (frame 0x50). Everything else (FMA adda.s/madd.s
   198+57*f20, mul.s 100*f20, the f20 spill at 0x0, byte copies, node loops,
   func_0047a220 tail) matches. */
// FUN_00167120
s32 func_00167120(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    f32 byte0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    s32 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_4;
    u8 *var_17;
    u8 temp_byte0;
    u8 temp_byte1;
    u8 temp_byte2;
    u8 temp_byte3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f20 = func_0044b7b0(D_007613EC *
                             (f32)(*(s32 *)(temp_16 + 8)) /
                             (f32)(*(s32 *)(temp_16 + 0xC)));
    temp_2 = func_0047a250(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50));
    temp_byte0 = *temp_2++;
    temp_byte1 = *temp_2++;
    temp_byte2 = *temp_2++;
    temp_byte3 = *temp_2++;
    sp4C[0] = temp_byte0;
    sp4C[1] = temp_byte1;
    sp4C[2] = temp_byte2;
    sp4C[3] = temp_byte3;
    *(s32 *)(temp_16 + 0xC) = 0x14;
    byte0 = 255.0f;
    sp4C[0] = (u8)byte0;
    temp_f1 = (198.0f + 0.0f) + (57.0f * temp_f20);
    sp4C[1] = (u8)temp_f1;
    temp_f1_2 = 100.0f * temp_f20;
    sp4C[2] = (u8)temp_f1_2;
    temp_3 = *(s32 *)(temp_16 + 8) + 1;
    *(s32 *)(temp_16 + 8) = temp_3;
    if (*(s32 *)(temp_16 + 0xC) < temp_3) {
        *(s32 *)(temp_16 + 8) = 0;
    }
    temp_4 = *(u8 **)(temp_16 + 4);
    temp_3_2 = *(u8 *)(temp_4 + 0x1CA);
    if (temp_3_2 == 0) {
        var_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        var_17 = *(u8 **)var_17;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)(var_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(var_17 + 8), sp48);
            sp48[0] = 0xFF;
            sp48[1] = 0xFF;
            sp48[2] = 0xFF;
            func_004b13f0(*(u8 **)(var_17 + 8), sp48);
        }
        var_17 = *(u8 **)(var_17 + 0x10);
loop_16_check:
        if (var_17 == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (temp_3_2 == 1) {
        temp_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        temp_17 = *(u8 **)temp_17;
        temp_17 = *(u8 **)(temp_17 + 0x10);
        temp_17 = *(u8 **)(temp_17 + 0x10);
        if (*(s32 *)(temp_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(temp_17 + 8), sp44);
            sp44[0] = sp4C[0];
            sp44[1] = sp4C[1];
            sp44[2] = sp4C[2];
            func_004b13f0(*(u8 **)(temp_17 + 8), sp44);
        }
    }
mode_done:
    func_0047a220(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50), sp4C);
    return 0;
}



// FUN_001673F0
void func_001673f0(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00167420
s32 func_00167420(u8 *arg0, u8 *arg1)
{
    s32 r;
    s32 task;
    func_0044ea90(D_005F1500, 0xD36);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0((void *)(arg0), (const void *)(D_005F15C0), 0xF, 0, 0, D_005F15B0[*(u16 *)(arg1 + 0x1C8)], func_001673f0, (u8 *)(r));
    *(u8 **)(r + 4) = arg1;
    *(s32 *)(r + 0xC) = 0x28;
    *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) |= 0x80;
    if (*(u8 *)(arg1 + 0x1CA) == 1) {
        *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) &= ~0x100;
    }
    return task;
}

// FUN_00167530
void func_00167530(void)
{
    memset(D_007E8020, 0, 0x40);
}





/* Preserve the per-site unit addresses and the readiness value used by each
   scan. The grid coordinates are signed integers; the second scan shares its
   center and grid size while retaining the original coordinate before addition. */
// FUN_00167560
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00167560(void)
{
    s32 playerCellX;
    s32 playerCellZ;
    s32 unitCellX;
    s32 unitCellZ;
    s32 objectCellX;
    s32 objectCellZ;
    s32 unitIndex;
    s32 objectIndex;
    s32 unitCount;
    s32 objectCount;
    s32 offset;
    s32 ready;
    u8 *unit;
    u8 *object;
    u8 *unitEntry;
    u8 **modelSlot;
    u8 *selectedUnit;
    u8 *selected;
    u8 *objectResource;
    s32 used;

    func_0043f9c8(D_007E8020, 0, 0x40);
    ready = *(u32 *)D_007EF9F8 != 0;
    if (ready) {
        ready = *(u32 *)D_007EFA04 != 0;
    }
    if (ready) {
        playerCellX = (s32)((600.0f + *(f32 *)(
            (u8 *)func_0047a2f0(*(u8 **)D_007EFA00) + 0x30)) / 1200.0f);
        playerCellZ = (s32)((600.0f + *(f32 *)(
            (u8 *)func_0047a2f0(*(u8 **)D_007EFA00) + 0x38)) / 1200.0f);
        unitIndex = 0;
        unitCount = 0;
        while (unitIndex < 0xF) {
            used = 0;
            unit = D_007E8C00 + unitIndex * 0x750;
            if (*(s32 *)(unit + 0x48) != 0 && *(s32 *)(unit + 0x54) != 0) {
                used = 1;
            }
            ready = used != 0;
            if (ready) {
                unitEntry = D_007E8C00 + unitIndex * 0x750;
                modelSlot = (u8 **)(unitEntry + 0x50);
                unitCellX = (s32)((600.0f + *(f32 *)(
                    (u8 *)func_0047a2f0(*modelSlot) + 0x30)) / 1200.0f);
                unitCellZ = (s32)((600.0f + *(f32 *)(
                    (u8 *)func_0047a2f0(*modelSlot) + 0x38)) / 1200.0f);
                selected = (u8 *)func_00145270(*(u16 *)((u8 *)func_00155280() +
                    (unitCellZ << 8) + (unitCellX << 4) + 0x56));
                if (!(unitCellX < playerCellX - 3 || unitCellX > playerCellX + 3 ||
                      unitCellZ < playerCellZ - 3 || unitCellZ > playerCellZ + 3 ||
                      selected == NULL || !(*(s32 *)(selected + 0x28) & 2))) {
                    if (unitCount >= 8) {
                        func_0046d730(D_005F1500, 0xE1F);
                    }
                    selectedUnit = D_007E8C00 + unitIndex * 0x750;
                    *(s32 *)(selectedUnit + 0x40) |= 1;
                    *(u8 **)(D_007E8020 + unitCount * 4) = selectedUnit;
                    unitCount += 1;
                } else {
                    *(s32 *)(unit + 0x40) &= ~1;
                }
            }
            unitIndex += 1;
        }
        objectIndex = 0;
        objectCount = 0;
        while (objectIndex < 8) {
            offset = objectIndex * 0x168;
            object = D_007E80A0 + offset;
            if (*(s32 *)object != 0) {
                f32 center;
                f32 gridSize;
                f32 positionX;
                f32 shiftedX;

                positionX = *(f32 *)(object + 0x150);
                center = 600.0f;
                shiftedX = center + positionX;
                gridSize = 1200.0f;
                objectCellX = (s32)(shiftedX / gridSize);
                objectCellZ = (s32)((center + *(f32 *)(object + 0x158)) / gridSize);
                objectResource = (u8 *)func_00145270(*(u16 *)((u8 *)func_00155280() +
                    (objectCellZ << 8) + (objectCellX << 4) + 0x56));
                if (!(objectCellX < playerCellX - 2 || objectCellX > playerCellX + 2 ||
                      objectCellZ < playerCellZ - 2 || objectCellZ > playerCellZ + 2 ||
                      objectResource == NULL || !(*(s32 *)(objectResource + 0x28) & 2))) {
                    if (objectCount >= 8) {
                        func_0046d730(D_005F1500, 0xE3C);
                    }
                    selected = D_007E80A0 + objectIndex * 0x168;
                    *(s32 *)(selected + 4) |= 1;
                    *(u8 **)(D_007E8020 + 0x20 + objectCount * 4) = selected;
                    objectCount += 1;
                } else {
                    *(s32 *)(object + 4) &= ~1;
                }
            }
            objectIndex += 1;
        }
    }
}
#pragma pop


/* Model replacement waits for all selected units before completing the task.
 * Measured: 904 relocated bytes plus eight zero suffix bytes. The scoped
 * lifetime/reload profile preserves the kind field across model teardown. */
// FUN_001679D0
#pragma push
#pragma opt_lifetimes on
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_001679d0(u8 *task)
{
    u8 *entry;
    s32 index;
    u8 *work;
    u8 *unit;
    u8 *retainedField;
    u8 *field;
    s32 requestIndex;
    s32 attached;
    s32 selectedCount;
    s32 isAttached;
    s32 selectedIndex;
    s32 requestedKind;
    s32 kind;
    u16 fieldId;
    u16 fieldSubId;
    s32 replacementKind;

    work = *(u8 **)(task + 0x38);
    switch (*(s32 *)work) {
    case 0:
        for (index = 0; index < 4; index++) {
            attached = 0;
            unit = D_007EF9B0 + index * 0x750;
            if (*(s32 *)(unit + 0x48) != 0) {
                if (*(s32 *)(unit + 0x54) != 0) {
                    attached = 1;
                }
            }
            isAttached = attached != 0;
            if (isAttached) {
                for (requestIndex = 0; requestIndex < 4; requestIndex++) {
                    requestedKind = *(s32 *)(work + requestIndex * 4 + 4);
                    kind = *(u16 *)(unit + 0x728);
                    if (requestedKind != kind) {
                        continue;
                    }
                    /* The kind address survives model teardown; its value selects the path. */
                    retainedField = unit + 0x728;
                    if (kind == 3) {
                        func_00165670(unit, 0);
                        entry = D_007F16F0 + index * 8;
                        if (*(s32 *)(entry + 4) != 0) {
                            s32 layer;

                            for (layer = 0; layer < 5; layer++) {
                                *(u8 *)(*(s32 *)(entry + 4) + layer * 12 + 0x28C) |= 1;
                            }
                            entry = D_007F16F0 + index * 8;
                            unit = entry + 4;
                            func_004787e0((u8 *)(*(s32 *)(entry + 4)));
                            *(s32 *)unit = 0;
                            *(s16 *)(entry + 0) = 0;
                            *(s16 *)(entry + 2) = 0;
                        }
                        unit = D_007EF9B0 + index * 0x750;
                        /* Load the field context once, then pass both native halfword IDs. */
                        field = iGpffff9db0;
                        fieldId = *(u16 *)field;
                        fieldSubId = *(u16 *)(field + 4);
                        replacementKind = *(u16 *)retainedField;
                        *(u8 **)(unit + 0x50) = func_00162680(fieldId, fieldSubId, replacementKind);
                    } else {
                        s32 layer;

                        for (layer = 0; layer < 5; layer++) {
                            func_0047ae10((u8 *)(*(s32 *)(unit + 0x50)), layer & 0xFFFF);
                        }
                        func_0047d140((void *)(*(s32 *)(unit + 0x50)));
                    }
                    selectedCount = *(s32 *)(work + 0x14);
                    *(s32 *)(work + selectedCount * 4 + 0x18) = index;
                    *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
                    break;
                }
            }
        }
        *(s32 *)work = *(s32 *)work + 1;
        break;
    case 1:
        for (index = 0; (u32)index < (u32)*(s32 *)(work + 0x14); index++) {
            entry = work + index * 4;
            retainedField = entry + 0x18;
            unit = D_007EF9B0 + *(s32 *)(entry + 0x18) * 0x750;
            if (*(u16 *)(unit + 0x728) == 3) {
                if (func_004782b0((u8 *)(*(s32 *)(unit + 0x50))) == 0) {
                    return 0;
                }
                attached = 0;
                selectedIndex = *(s32 *)retainedField;
                unit = D_007EF9B0 + selectedIndex * 0x750;
                if (*(s32 *)(unit + 0x48) != 0) {
                    if (*(s32 *)(unit + 0x54) != 0) {
                        attached = 1;
                    }
                }
                isAttached = attached != 0;
                if (!isAttached) {
                    func_00164fa0(selectedIndex);
                }
            } else {
                s32 layer;

                for (layer = 0; layer < 5; layer++) {
                    if (func_0047ae90((u8 *)(*(s32 *)(D_007EF9B0 + *(s32 *)(entry + 0x18) * 0x750 +
                                     0x50)), layer & 0xFFFF) == 0) {
                        return 0;
                    }
                }
            }
        }
        *(s32 *)work = *(s32 *)work + 1;
        /* fallthrough */
    case 2:
        return -1;
    }
    return 0;
}

#pragma pop
// FUN_00167D60
void func_00167d60(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00167D90
s32 func_00167d90(u8 *arg0)
{
    s32 r;
    s32 task;
    u32 acc = 0;
    s32 i = 0;
    s32 j = 0;
    while (i < 4) {
        u32 v = *(u32 *)arg0;
        if (v != 0) {
            acc |= (v & 0xFF) << (j * 8);
            j++;
        }
        i++;
        arg0 += 8;
    }
    if (acc == 0) {
        return 0;
    }
    if (func_00162510(*(u16 *)D_00762EA0, *(u16 *)(D_00762EA0 + 4)) == 1 || func_0015a160() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xED8);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x28, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0((void *)(NULL), (const void *)(D_005F15E0), 0xF, 0, 0, func_001679d0, func_00167d60, (u8 *)(r));
    *(s32 *)(r + 4) = acc & 0xFF;
    *(s32 *)(r + 8) = (acc >> 8) & 0xFF;
    *(s32 *)(r + 0xC) = (acc >> 16) & 0xFF;
    *(s32 *)(r + 0x10) = (acc >> 24) & 0xFF;
    return task;
}
