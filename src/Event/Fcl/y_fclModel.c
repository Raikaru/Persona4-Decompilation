/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_matrix_internal.h"

extern void func_0044ea90(u8 *file, s32 line);
extern u8 D_0064A618[];
extern u8 D_0064A630[];
extern u8 D_0064A6B0[];
extern u8 D_0064A6C0[];

/* The two 12-byte vectors retail copies global->stack as ld/sd for the first
   eight bytes plus lwc1/swc1 for the last four. */
typedef struct
{
    s64 xy;
    f32 z;
} FclVec3;
extern u8 D_0064A6D0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);

extern s32 func_00349340(u8 *task);
extern void func_00349380(u8 *arg0);
extern void func_00349440(u8 *arg0, u8 *arg1);
extern void func_004787e0(u8 *arg0);
extern void func_00104a00(u8 *arg0);
extern s32 func_004782b0(u8 *arg0);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern void *func_004571a0(void);
extern void func_003c38b0(void *arg0, void *arg1);
extern void *func_004571b0(void);
extern void func_003e9cb0(s32 arg0, void *arg1, s32 arg2);
extern u8 *func_00104900(s8 arg0);
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 arg3);
extern void func_003e0c90(void *arg0, void *arg1, s32 arg2);
extern s32 func_00349c50(u8 *arg0);
extern u8 *func_00478140(s32, u16, s32);
extern s32 func_00479940(u8* model, u32 layer, s32 animation, s32 frame, s32 flags);
extern s32 func_00106330(s32);
extern s32 func_00348be0(u8 *);
extern s32 func_00348c10(u8 *);
extern u8 *func_001102f0(u8 *, s32, s32, f32);
extern void func_002b2a60(void *, s32, s32, s32, s32);
extern void func_003489c0(u8 *, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00285b30(void);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern s16 func_002b2cb0(s32, s32, s32, s32, s32);
extern void func_00479100(void *, u8 *);
extern void func_0047aa30(u8 *, void *);
extern void func_00452080(u8 *);
extern u8 D_00793E80[];
extern u8 D_005DCA70[];
extern u8 D_005DCA1C[];

// FUN_003493B0
void func_003493b0(s32 arg0)
{
    u8 *work;

    func_0044ea90(D_0064A618, 0x555);
    work = D_008873F4[0](1, 0x1A0, 0x40000);
    (s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A630), 0xF, 0, 0, func_00349340, func_00349380, (u8 *)(work));
}

/* measured: de-noised m2c (TMPDIR /var/tmp/cold349440/m2c.c) into file idiom */
/* (u8 trans/scale/axis/mat arrays as in func_0034a4f0; s64+f32 Pair loads for */
/* the 12B vectors; RwMatrix/RwV3d layout from mdlManager checked for matQ */
/* flags at 0x0C=3 and pos at 0x30=0; s128 lq/sq idiom from fclCombineMisc and */
/* aligned(16) from mdlEffect/k_fldFrame for the 16B/64B copies). Retail 464 */
/* instrs per fnalign; v11 object 462 instrs (-2), GUARDED_SCORE 392 (v10 396, */
/* v9 420, v8 424, v5 539, v2 540, v1 553). FPU accumulator floor */
/* (mula.s/madda.s/madd.s sum-of-squares, M2C_ERROR) is unmatchable; */
/* gp-relative immediates and 12B ld-then-lwc1 order plus float colour remain. */
/* Fixes in order: u32 to s32 for color bytes removed unsigned cvt bloat */
/* (539 to 424, minus 115, 617 to 506 instrs); s128 whole copies for col and */
/* quat plus M64 struct copy (420, 491 instrs); s128 plus aligned(16) for */
/* col/quat/mat (396, 464/464); parent single-expr plus M64 as s128x4 (392, */
/* 462/464, within two). v12 scale-descending 393 (unproductive). Two-arg */
/* (u8*,u8*) signature with a1 as obj as in func_00349b90; first arg unused. */
/* INCLUDE_ASM retained. */
// FUN_00349440 NONMATCHING
#ifdef NON_MATCHING
void func_00349440(u8 *arg0, u8 *arg1)
{
    extern s32 func_004782b0(u8 *a);
    extern void *func_00457120(void);
    extern void *func_004571a0(void);
    extern void *func_004571b0(void);
    extern f32 func_00457850(void *a);
    extern void func_004577d0(void *a, f32 b);
    extern void func_003c38b0(void *a, void *b);
    extern void func_003e9cb0(s32 a, void *b, s32 c);
    extern void func_003e0870(void *a, void *b, s32 c, f32 d);
    extern void func_003e0c90(void *a, void *b, s32 c);
    extern void *func_003e05f0(void *a, void *b, void *c);
    extern void func_0047a1c0(void *a, void *b, s32 c);
    extern void func_0047a1e0(void *a, void *b, s32 c);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern s32 func_00457190(void);
    extern s32 func_004571c0(void);
    extern void func_003cbf30(s32 a, s32 b);
    extern void func_003e8130(void *a, void *b);
    extern u8 D_0064A648[];
    extern u8 D_0064A650[];
    extern u8 D_0064A658[];
    extern u8 D_0064A660[];
    extern u8 D_0064A668[];
    extern u8 D_0064A670[];
    extern u8 D_0064A680[];
    extern u8 D_0064A690[];
    extern u8 D_0064A6A0[];
    typedef signed __int128 s128;
    typedef struct { s32 w[4]; } Q16;
    typedef struct { s128 w[4]; } M64;
    extern f32 iGpffffb5a0;
    extern f32 iGpffff8518;
    u8 trans[12];
    u8 scale[12];
    u8 axisX[12];
    u8 axisY[12];
    u8 mat[64] __attribute__((aligned(16)));
    u8 tmpA[64] __attribute__((aligned(16)));
    s128 colA __attribute__((aligned(16)));
    s128 colB __attribute__((aligned(16)));
    s128 quat __attribute__((aligned(16)));
    u8 pad[12];
    f32 win[2];
    u8 matQ[64] __attribute__((aligned(16)));
    u8 matB[64] __attribute__((aligned(16)));
    u8 *obj;
    u8 *parent;
    (void)arg0;
    obj = arg1;
    {
        u8 *p = trans;
        s32 n = 12;
        if (p != NULL) {
            do {
                *p = 0;
                p += 1;
                n -= 1;
            } while (n != 0);
        }
    }
    {
        s64 xy = *(s64 *)&D_0064A648[0];
        f32 z = *(f32 *)&D_0064A650[0];
        *(s64 *)&scale[0] = xy;
        *(f32 *)&scale[8] = z;
    }
    if ((*(u8 **)(obj + 0xC) == NULL) || (func_004782b0(*(u8 **)(obj + 0xC)) == 0)) {
        return;
    }
    {
        s64 xy = *(s64 *)&D_0064A658[0];
        f32 z = *(f32 *)&D_0064A660[0];
        *(s64 *)&axisX[0] = xy;
        *(f32 *)&axisX[8] = z;
    }
    {
        s64 xy = *(s64 *)&D_0064A668[0];
        f32 z = *(f32 *)&D_0064A670[0];
        *(s64 *)&axisY[0] = xy;
        *(f32 *)&axisY[8] = z;
    }
    parent = *(u8 **)((u8 *)func_00457120() + 4) + 0x10;
    {
        u8 *entry = *(u8 **)(obj + 0x10) + ((s32)*(u16 *)(obj + 8) << 5);
        *(f32 *)&trans[0] += (f32)*(s16 *)(entry + 0);
        *(f32 *)&trans[4] += (f32)*(s16 *)(entry + 2);
        *(f32 *)&trans[8] += (f32)*(s16 *)(entry + 4);
        {
            f32 s = *(f32 *)(entry + 8);
            *(f32 *)&scale[0] = s;
            *(f32 *)&scale[4] = s;
            *(f32 *)&scale[8] = s;
        }
        {
            s32 *sp = (s32 *)(obj + 0x30);
            s32 *dp = (s32 *)mat;
            s32 cnt = 8;
            do {
                s32 a = sp[0];
                s32 b = sp[1];
                sp += 2;
                cnt -= 1;
                dp[0] = a;
                dp[1] = b;
                dp += 2;
            } while (cnt > 0);
        }
        func_003e0870(mat, axisY, 1, *(f32 *)(entry + 0xC));
    }
    func_003e0c90(mat, trans, 2);
    func_003e05f0(tmpA, mat, parent);
    *(M64 *)mat = *(M64 *)tmpA;
    func_0047a1c0(*(u8 **)(obj + 0xC), mat, 0);
    func_0047a1e0(*(u8 **)(obj + 0xC), scale, 1);
    {
        u16 idx = *(u16 *)(obj + 8);
        if (idx == 0x1B) {
            iGpffffb5a0 = 10.0f;
        } else if (idx == 0xA1) {
            iGpffffb5a0 = 7.0f;
        } else if (idx == 0x8D) {
            iGpffffb5a0 = iGpffff8518;
        } else {
            iGpffffb5a0 = 0.0f;
        }
    }
    func_0047a1a0(*(u8 **)(obj + 0xC), axisX, iGpffffb5a0, 1);
    colA = *(s128 *)D_0064A680;
    colB = *(s128 *)D_0064A690;
    quat = *(s128 *)D_0064A6A0;
    {
        u8 *p = pad;
        s32 n = 12;
        if (p != NULL) {
            do {
                *p = 0;
                p += 1;
                n -= 1;
            } while (n != 0);
        }
    }
    parent = *(u8 **)((u8 *)func_00457120() + 4) + 0x10;
    *(f32 *)(obj + 0x70) = func_00457850(func_00457120());
    {
        u8 *cam = (u8 *)func_004571a0();
        *(f32 *)(obj + 0x74) = *(f32 *)(cam + 0x18);
        *(f32 *)(obj + 0x78) = *(f32 *)(cam + 0x1C);
        *(f32 *)(obj + 0x7C) = *(f32 *)(cam + 0x20);
        *(f32 *)(obj + 0x80) = *(f32 *)(cam + 0x24);
    }
    {
        u8 *cam = (u8 *)func_004571b0();
        *(f32 *)(obj + 0x84) = *(f32 *)(cam + 0x18);
        *(f32 *)(obj + 0x88) = *(f32 *)(cam + 0x1C);
        *(f32 *)(obj + 0x8C) = *(f32 *)(cam + 0x20);
        *(f32 *)(obj + 0x90) = *(f32 *)(cam + 0x24);
    }
    {
        u8 *src = *(u8 **)((u8 *)func_004571b0() + 4);
        s32 *sp = (s32 *)(src + 0x10);
        s32 *dp = (s32 *)(obj + 0xA0);
        s32 cnt = 8;
        do {
            s32 a = sp[0];
            s32 b = sp[1];
            sp += 2;
            cnt -= 1;
            dp[0] = a;
            dp[1] = b;
            dp += 2;
        } while (cnt > 0);
    }
    {
        u8 *cam = (u8 *)func_00457120();
        *(f32 *)(obj + 0xE0) = *(f32 *)(cam + 0x78);
        *(f32 *)(obj + 0xE4) = *(f32 *)(cam + 0x7C);
    }
    {
        u8 *entry = *(u8 **)(obj + 0x10) + ((s32)*(u16 *)(obj + 8) << 5);
        s32 c1 = *(s32 *)(entry + 0x14);
        ((f32 *)&colA)[0] = (f32)((c1 >> 24) & 0xFF) / 255.0f;
        ((f32 *)&colA)[1] = (f32)((c1 >> 16) & 0xFF) / 255.0f;
        ((f32 *)&colA)[2] = (f32)((c1 >> 8) & 0xFF) / 255.0f;
        ((f32 *)&colA)[3] = (f32)(c1 & 0xFF) / 255.0f;
        {
            s32 c2 = *(s32 *)(entry + 0x18);
            ((f32 *)&colB)[0] = (f32)((c2 >> 24) & 0xFF) / 255.0f;
            ((f32 *)&colB)[1] = (f32)((c2 >> 16) & 0xFF) / 255.0f;
            ((f32 *)&colB)[2] = (f32)((c2 >> 8) & 0xFF) / 255.0f;
            ((f32 *)&colB)[3] = (f32)(c2 & 0xFF) / 255.0f;
        }
        win[0] = (f32)*(s16 *)(entry + 0x1C) / 640.0f;
        win[1] = (f32)*(s16 *)(entry + 0x1E) / 448.0f;
    }
    func_004577d0(func_00457120(), 40.0f);
    func_003c38b0((u8 *)func_004571a0(), (u8 *)&colA);
    func_003c38b0((u8 *)func_004571b0(), (u8 *)&colB);
    {
        u8 *base = *(u8 **)(obj + 0x10);
        u16 idx2 = *(u16 *)(obj + 8);
        u8 *entry2 = base + ((s32)idx2 << 5);
        s16 qidx = *(s16 *)(entry2 + 0x12);
        if (qidx == -1) {
            func_0043f810((u8 *)&quat, obj + 0x18, 16);
        } else {
            u8 *tbl = *(u8 **)(obj + 0x14);
            if (qidx < *(s32 *)(tbl + 4)) {
                func_0043f810((u8 *)&quat, *(u8 **)(tbl + 0xC) + ((s32)qidx * 16), 16);
            } else {
                func_0043f810((u8 *)&quat, *(u8 **)(tbl + 0xC), 16);
            }
        }
    }
    {
        f32 qx = ((f32 *)&quat)[0];
        f32 qy = ((f32 *)&quat)[1];
        f32 qz = ((f32 *)&quat)[2];
        f32 qw = ((f32 *)&quat)[3];
        f32 sum = qx * qx + qy * qy + qz * qz + qw * qw;
        f32 inv = 2.0f / sum;
        f32 sz = qz * inv;
        f32 sy = qy * inv;
        f32 sx = qx * inv;
        ((f32 *)matQ)[0] = 1.0f - (qy * sy + qz * sz);
        ((f32 *)matQ)[1] = qx * sy + sz * qw;
        ((f32 *)matQ)[2] = qz * sx - sy * qw;
        ((f32 *)matQ)[4] = qx * sy - sz * qw;
        ((f32 *)matQ)[5] = 1.0f - (qz * sz + qx * sx);
        ((f32 *)matQ)[6] = qy * sz + sx * qw;
        ((f32 *)matQ)[8] = qz * sx + sy * qw;
        ((f32 *)matQ)[9] = qy * sz - sx * qw;
        ((f32 *)matQ)[10] = 1.0f - (qx * sx + qy * sy);
        *(s32 *)&matQ[0x30] = 0;
        *(s32 *)&matQ[0x34] = 0;
        *(s32 *)&matQ[0x38] = 0;
        *(s32 *)&matQ[0x0C] = 3;
    }
    func_003e05f0(matB, matQ, parent);
    *(M64 *)matQ = *(M64 *)matB;
    func_003e9cb0(*(s32 *)((u8 *)func_004571b0() + 4), matQ, 0);
    *(u8 *)((u8 *)func_004571b0() + 2) = 3;
    (void)func_004571b0();
    func_003cbf30(func_00457190(), func_004571c0());
    func_003e8130(func_00457120(), win);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349440);
#endif

// FUN_00349B90
void func_00349b90(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg1 + 0xC);
    if ((temp_4 != NULL) && (func_004782b0(temp_4) != 0)) {
        func_004577d0(func_00457120(), *(f32 *)(arg1 + 0x70));
        func_003c38b0(func_004571a0(), arg1 + 0x74);
        func_003c38b0(func_004571b0(), arg1 + 0x84);
        func_003e9cb0(*(s32 *)((u8 *)func_004571b0() + 4), arg1 + 0xA0, 0);
        *(s8 *)((u8 *)func_004571b0() + 2) = 3;
        func_004571b0();
    }
}

/* measured: cold m2c via bulk path (direct m2c_decompile fails: jr without jtbl_00749820;
   combined prepared asm + .word .L targets for 6 entries at 0x749820). De-noised to file
   idiom (u8*+offsets, s8/s16/u16/s32; file-scope 001102f0 to (u8*,s32,s32,f32)->u8* per
   g_data.c and 00285b30 to (void)->s32 per y_CmbCardEff; 300.0f/0.0f/1.0f/700.0f floats;
   s32 (not u32) for sp48/sp4C colors; u8[4] per-byte sp44->sp4C copy for retail lbu/sb).
   probe_variants: v1/v9w 229 best (v3 317/v4 314/v5 317 with explicit case-4 switch+stack
   swaps; v6 if-chain 388; v7 guard+switch 381; v8 lh-split 399). fnalign v1: retail 521
   vs object 521 instrs, edit 67 +16 reloc. Frame 0x50 both. Residuals: missing explicit
   inner c==4 check (3w, explicit guard/5th case triggers jump-table penalty +88); lhu
   $a0 vs $v1 + sll/lw order + lh scheduling; mov.s scheduling; sp28 0x20 vs 0x28 and
   sp44/sp4C swap (stack allocation); sb $a0 reuse vs addiu+sb; branch offsets. Float
   coloring (mov.s) follows count. Floor per matching.md (alloc/sched/order/FPU).
   INCLUDE_ASM retained. */
// FUN_00349C50 NONMATCHING
#ifdef NON_MATCHING
s32 func_00349c50(u8 *arg0)
{
    u8 sp28[16];
    u8 sp38[12];
    u8 sp44[4];
    s32 sp48;
    s32 sp4C;
    u8 *obj;
    obj = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)obj) {
    case 0:
        if (*(s8 *)(obj + 6) == 1) {
            *(s8 *)obj = 4;
        }
        break;
    case 1:
        *(u8 **)(obj + 0xC) = func_00478140(0xB, *(u16 *)(obj + 8), 0);
        *(s8 *)obj = 2;
        break;
    case 2:
        if (func_004782b0(*(u8 **)(obj + 0xC)) != 0) {
            if (*(s8 *)(obj + 0x28) == 1) {
                func_00479940(*(u8 **)(obj + 0xC), 0, 0, 0, 1);
            } else {
                *(s8 *)(obj + 4) = 0;
            }
            *(s16 *)(obj + 2) = 0;
            *(s8 *)obj = 3;
            if (*(s8 *)(obj + 6) == 1) {
                *(s8 *)obj = 4;
            }
        }
        break;
    case 3:
        if (*(s8 *)(obj + 6) == 1) {
            *(s8 *)obj = 4;
            return 0;
        }
        if (*(s8 *)(obj + 1) == 1) {
            return 0;
        }
        if (*(s8 *)(obj + 0x28) == 0) {
            *(s32 *)(obj + 0xE8) = 0x29;
            if (func_00106330(0x1450) == 0) {
                return 0;
            }
            switch (*(s8 *)(obj + 4)) {
            case 0:
                if (func_00348be0(*(u8 **)(obj + 0xEC)) == 0) {
                    return 0;
                }
                if (func_00348be0(*(u8 **)(obj + 0xF0)) == 0) {
                    return 0;
                }
                if (*(s8 *)(obj + 5) == 1) {
                    u16 a = *(u16 *)(obj + 8);
                    if (a == 0x16) {
                        u8 *base = *(u8 **)(obj + 0x10);
                        s16 an = *(s16 *)(base + (a << 5) + 6);
                        func_00479940(*(u8 **)(obj + 0xC), 0, an, 0, 0);
                    } else {
                        u8 *base = *(u8 **)(obj + 0x10);
                        s16 an = *(s16 *)(base + (a << 5) + 6);
                        func_00479940(*(u8 **)(obj + 0xC), 0, an, 10, 0);
                    }
                }
                *(s8 *)(obj + 4) = 1;
                break;
            case 1:
                if (func_00348c10(*(u8 **)(obj + 0xEC)) == 0) {
                    func_001102f0(sp38, 0x140, 0xA5, 300.0f);
                    func_002b2a60(&sp48, 0xFF, 0xFF, 0xFF, 0xFF);
                    func_003489c0(*(u8 **)(obj + 0xEC), sp38, sp48, 0, -1, 0.0f, 0.0f, 0.0f, 1.0f);
                }
                if (func_00348c10(*(u8 **)(obj + 0xF0)) == 0) {
                    func_002b2a60(sp44, 0xFF, 0xFF, 0xFF, 0xFF);
                    ((u8 *)&sp4C)[0] = sp44[0];
                    ((u8 *)&sp4C)[1] = sp44[1];
                    ((u8 *)&sp4C)[2] = sp44[2];
                    ((u8 *)&sp4C)[3] = sp44[3];
                    func_001102f0(sp28, 0x140, 0xA5, 300.0f);
                    switch (*(u16 *)(obj + 8)) {
                    case 0x59:
                        func_002b2a60(&sp4C, 0xFF, 0xFF, 0xFF, 0xCD);
                        break;
                    case 0xA:
                        func_002b2a60(&sp4C, 0xFF, 0xFF, 0xFF, 0xA);
                        break;
                    case 0x5F:
                        func_002b2a60(&sp4C, 0xFF, 0xFF, 0xFF, 0xAA);
                        break;
                    default:
                        break;
                    }
                    func_003489c0(*(u8 **)(obj + 0xF0), sp28, sp4C, 0, -1, 0.0f, 0.0f, 0.0f, 1.0f);
                }
                if (*(s8 *)(obj + 5) == 1) {
                    u16 v = *(u16 *)(obj + 8);
                    if ((v == 4) || (v == 0xB) || (v == 0x16) || (v == 0x2D) || (v == 0x53) ||
                        (v == 0x6B) || (v == 0x9A) || (v == 0x57) || (v == 0xA6) || (v == 0xBA) ||
                        (v == 0xBD) || (v == 0x15) || (v == 0x43) || (v == 0x68) || (v == 0x8D) ||
                        (v == 0x93) || (v == 0x71) || (v == 0x7D) || (v == 0x8A) || (v == 0xA3) ||
                        (v == 0x39)) {
                        *(s8 *)(obj + 4) = 2;
                        *(s8 *)(obj + 5) = 0;
                    } else {
                        *(s8 *)(obj + 4) = 3;
                    }
                } else {
                    *(s8 *)(obj + 4) = 4;
                }
                break;
            case 2:
                if (*(u8 *)(*(u8 **)(obj + 0xC) + 0xEE) == 1) {
                    *(s8 *)(obj + 5) = 0;
                    *(s8 *)(obj + 4) = 4;
                } else if ((f32)func_00285b30() >= 700.0f) {
                    *(s8 *)(obj + 5) = 0;
                    *(s8 *)(obj + 4) = 4;
                }
                break;
            case 3:
                {
                    u8 *mdl = *(u8 **)(obj + 0xC);
                    if (*(u8 *)(mdl + 0xEE) == 1) {
                        func_00479940(mdl, 0, 0, 30, 1);
                        *(s8 *)(obj + 5) = 0;
                        *(s8 *)(obj + 4) = 4;
                    } else if ((f32)func_00285b30() >= 700.0f) {
                        func_00479940(*(u8 **)(obj + 0xC), 0, 0, 30, 1);
                        *(s8 *)(obj + 5) = 0;
                        *(s8 *)(obj + 4) = 4;
                    }
                }
                break;
            default:
                break;
            }
        } else {
            *(s32 *)(obj + 0xE8) = 0xB3;
        }
        {
            void *tmp1 = func_00460990();
            *(void **)((u8 *)tmp1 + 8) = (void *)func_00349440;
            *(u8 **)((u8 *)tmp1 + 0x10) = obj;
            func_00460ac0(&D_00793E80[(*(s32 *)(obj + 0xE8) - 1) * 0x30], tmp1);
            {
                s16 cur = *(s16 *)(obj + 2);
                if (cur < 3) {
                    *(s16 *)(obj + 2) = func_002b2cb0(cur, 1, 3, 0, 1);
                } else {
                    func_00479100(&D_00793E80[(*(s32 *)(obj + 0xE8)) * 0x30], *(u8 **)(obj + 0xC));
                    if (*(s8 *)(obj + 0x28) == 0) {
                        func_0047aa30(*(u8 **)(obj + 0xC), D_005DCA70);
                    } else {
                        func_0047aa30(*(u8 **)(obj + 0xC), D_005DCA1C);
                    }
                }
            }
            {
                void *tmp2 = func_00460990();
                *(void **)((u8 *)tmp2 + 8) = (void *)func_00349b90;
                *(u8 **)((u8 *)tmp2 + 0x10) = obj;
                func_00460ac0(&D_00793E80[(*(s32 *)(obj + 0xE8) + 1) * 0x30], tmp2);
            }
        }
        break;
    case 4:
        {
            u8 *p1 = *(u8 **)(obj + 0xC);
            if (p1 != NULL) {
                func_004787e0(p1);
                *(u8 **)(obj + 0xC) = NULL;
            }
            {
                u8 *p2 = *(u8 **)(obj + 0x14);
                if (p2 != NULL) {
                    func_00104a00(p2);
                    *(u8 **)(obj + 0x14) = NULL;
                }
            }
            if (*(s8 *)(obj + 0x28) == 0) {
                u8 *p3 = *(u8 **)(obj + 0xEC);
                if (p3 != NULL) {
                    func_00452080(p3);
                    *(u8 **)(obj + 0xEC) = NULL;
                }
                {
                    u8 *p4 = *(u8 **)(obj + 0xF0);
                    if (p4 != NULL) {
                        func_00452080(p4);
                        *(u8 **)(obj + 0xF0) = NULL;
                    }
                }
            }
            *(s8 *)(obj + 6) = 0;
            *(s8 *)obj = 0;
        }
        break;
    case 5:
        return -1;
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349c50);
#endif
// FUN_0034A480
void func_0034a480(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 0xC);
    if (temp_4 != NULL) {
        func_004787e0(temp_4);
    }
    temp_4_2 = *(u8 **)(temp_16 + 0x14);
    if (temp_4_2 != NULL) {
        func_00104a00(temp_4_2);
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

/* measured: retail loads the {s64 @0x50, f32 @0x58} and {s64 @0x40, f32 @0x48}
   pairs as ld+lwc1 (load-both-then-store-both). A struct copy of {s64,f32}
   (16B padded) makes b210 copy both fields as 8-byte integer ld/sd (nd 4);
   field-by-field assignment copies the float correctly but interleaves
   load-store-load-store instead of load-load-store-store (nd 9); #pragma
   pack(4) splits the s64 into two lwc1 (nd 70). Mixed s64+f32 struct-copy
   grouping is a b210 floor. */
/* measured: reconstructed from scratch (this function had no note). Now nd 5,
   of which 2 words are window padding, so THREE real words remain -- all in
   the second 12-byte vector copy, where retail loads `ld` then `lwc1` and b210
   emits them the other way round.

   What got it here, in order of effect: (1) copy each 12-byte vector as an
   explicit s64 + f32 pair, NOT as a {s64; f32} struct assignment -- the struct
   pads to 16 and copies the tail as a second ld/sd (nd 22); (2) load both
   halves into temps before storing either, which is the load-both-then-
   store-both shape retail uses, and it fixes the FIRST copy (10 -> 5);
   (3) declaration order `handle, entry, mem` -- with `mem` first the whole
   function rotates $s0/$s1/$s2 against retail (26 vs 10).

   Measured and rejected: separate temps for the second copy (8, worse than
   reusing them); a {s64; f32} struct (22). The two callbacks need casts
   because func_00349c50 and func_0034a480 are declared returning s32/int.
   Body kept below so the last three words can be attacked without redoing
/* SOLVED by tools/permute.py after this was documented at nd 5 following five
   hand attempts. The permuter found the two pragmas; everything else below is
   the hand-built body it started from.

   measured: optimization_level 1 is load-bearing -- with it removed the
   function goes straight back to MISMATCH. `tailcall on` pairs with it. The
   permuter also proposed s32 copies of both parameters; those were noise and
   are dropped, the function still matches without them.

   Keep the 12-byte vector copies as an explicit s64 + f32 pair: a {s64; f32}
   struct assignment pads to 16 and copies the tail as a second ld/sd (nd 22),
   and both callbacks need casts because func_00349c50 and func_0034a480 are
/* SOLVED by tools/permute.py after this was documented at nd 5 following five
   hand attempts. Keep the 12-byte vector copies as an explicit s64 + f32 pair:
   a {s64; f32} struct assignment pads to 16 and copies the tail as a second
   ld/sd (nd 22). Both callbacks need casts because func_00349c50 and
   func_0034a480 are declared returning s32/int. The permuter also proposed
   s32 copies of both parameters; those were noise and are dropped.
   measured: optimization_level 1 is load-bearing here -- removing it puts the
   function straight back to MISMATCH -- and `tailcall on` pairs with it. */
#pragma optimization_level 1
#pragma tailcall on
// FUN_0034A4F0
#pragma tailcall on
s32 func_0034a4f0(s32 arg0, s32 arg1)
{
    u8 sp50[0xC];
    u8 sp40[0xC];
    s32 handle;
    u8 *entry;
    u8 *mem;
    s64 xy;
    f32 z;

    /* measured: the 12-byte vectors are copied as an explicit s64 + f32 pair so
       b210 emits retail's ld/sd plus lwc1/swc1; a {s64; f32} struct assignment
       pads to 16 and copies the tail as a second ld/sd. */
    xy = *(s64 *)&D_0064A6B0[0];
    z = *(f32 *)&D_0064A6B0[8];
    *(s64 *)&sp50[0] = xy;
    *(f32 *)&sp50[8] = z;
    xy = *(s64 *)&D_0064A6C0[0];
    z = *(f32 *)&D_0064A6C0[8];
    *(s64 *)&sp40[0] = xy;
    *(f32 *)&sp40[8] = z;
    func_0044ea90(D_0064A618, 0x7A9);
    mem = D_008873F4[0](1, 0x100, 0x40000);
    handle = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0064A6D0), 0xF, 0, 0, func_00349c50, func_0034a480, (u8 *)(mem));
    *(s8 *)(mem + 0) = 0;
    *(s16 *)(mem + 8) = 0;
    *(s8 *)(mem + 5) = 0;
    entry = func_00104900((s8)arg1);
    *(u8 **)(mem + 0x14) = entry;
    *(s32 *)(mem + 0x10) = *(s32 *)(entry + 8);
    *(s32 *)(mem + 0xE8) = 0xB3;
    func_003e0870(mem + 0x30, &sp40[0], 0, 180.0f);
    func_003e0c90(mem + 0x30, &sp50[0], 2);
    return handle;
}
/* measured: closes the optimization_level 1 + tailcall scope opened above for
   func_0034a4f0; -O2 with tailcall off is the documented baseline. */
#pragma tailcall off
#pragma optimization_level 2
#pragma tailcall off
