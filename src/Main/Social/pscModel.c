/* Consolidated Persona 4 source units. */
/* Original translation unit pscModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern f32 D_00761480;
extern f32 D_00761484;

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} PscVec;

typedef struct
{
    /* 0x00 */ PscVec dir;
    /* 0x0C */ u8 c[4];
    /* 0x10 */ PscVec unused;
    /* 0x1C */ f32 f1c;
    /* 0x20 */ f32 f20;
} PscLight;

extern void* func_00457120(void);
extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0064E480[];
extern u16 D_00884690[];
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);
typedef struct
{
    u32 flags;          /* 0x00 */
    s32 mode;           /* 0x04 */
    u8 pad08[0x38];     /* 0x08 */
    u8 color[4];        /* 0x40 */
    u8 pad44[0x04];     /* 0x44 */
    s32 unk48;          /* 0x48 */
    u8 unk4C[0x90];     /* 0x4C draw vertices */
    void *unkDC;        /* 0xDC */
    PscLight e0[4];     /* 0xE0 */
    union
    {
        struct
        {
            s32 unk170;     /* 0x170 */
            s32 unk174;     /* 0x174 */
            PscLight b0[4]; /* 0x178 */
            PscLight b1[4]; /* 0x208 */
            PscLight b2[4]; /* 0x298 */
            PscLight b3[4]; /* 0x328 */
            PscLight b4[4]; /* 0x3B8 */
            PscLight b5[4]; /* 0x448 */
            PscLight b6[4]; /* 0x4D8 */
            PscLight b7[4]; /* 0x568 */
            PscLight b8[4]; /* 0x5F8 */
        } m01;
        PscLight w170[4];   /* 0x170 mode 2/3 work, overlaps unk170..b0 */
    } u;
} PscModel;

extern void *func_003e0f80(void);
extern void func_003e0f40(void *matrix);
extern void func_0036abd0(void *output, void *transform);
extern void func_0036ae00(void *work, const u8 *color);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void func_00410420(void *vertices, u32 count, void *matrix, u32 stride);
extern void func_00410520(u32 primitive, void *indices, u32 count);
extern void func_004104d0(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern u16 D_0064E470[];
extern s32 func_0036bee0(s32 arg0, s32 arg1);
extern s32 func_0036bff0(s32 arg0);
extern s32 func_0036be00(void);
extern s32 func_0036be70(void);
extern s32 func_0036c0d0(void);
extern s32 func_0036d130(s32 arg0);
extern s32 func_0036d1b0(s32 arg0);
extern void func_0036b470(void *work, void *vertices);

/* Floor: 759 differing words, 1099 emitted instructions against retail's
   1142 (4396 bytes in a 4576-byte window), frame -0x90 exact.  The 116
   direct calls and 36 D_00887300 dispatches match retail counts; the
   PscModel layout reuses PscLight[4] for the 0xE0 block and the nine
   0x178..0x5F8 blocks (0x90 stride is four PscLight), the 0x40 color as
   u8[4] like PscLight.c, and the 0x328/0x32C and 0x5F8/0x5FC floats as
   b3/b8 dir fields; the 0x170 mode 2/3 work overlaps unk170..b0 via the
   union.  The six (30*alpha)/100, 255*field and (255*field*alpha)/255
   scalings are single (u8)(u32)float expressions, and the u8->float
   steps are single (f32)(u32)byte casts over u32 temporaries, which
   restores retail's bltz/srl/or/cvt/add.s unsigned sequences (+124
   words over the s32 form, 928->764); D_00887300 is reloaded per
   region (four lui/lo pairs, matching retail).
   WALL: callee-saved allocation shift (e0 in s3 vs s0, mode bases in
   s6/s0/s2/s3 vs s0/s1/s2/s6) and branch polarity (bne vs beq from
   if/else vs irregular-switch layout). */
/* gate: object 1099 against retail 1142, -3.8% - OUTSIDE
   the +-3% band.  Any differing-word score in this note was measured
   against a body of the wrong length and is not comparable to one
   measured inside the gate (handoff 7y).  Fix the count first. */
/* 2026-09-19: frame -0x90 exact. Lui retail 49 vs object 52 (+3 surplus): retail {0x65:17,0x41f0:1,0x42c8:1,0x4f00:6,0x8000:6,0x437f:6,0x88:4,3:4,7:4} vs object {0:26,0x4f00:6,0x8000:6,0x41f0:1,0x42c8:1,0x437f:4,3:4,7:4}; surplus is symbols (+5 zero for 0x65/0x88 D_0064E480/D_00887300, e.g. reloc-only 16:18 lui 0x65 vs 0) minus 2 missing floats (0x437f 6->4, 255.0f scalings in missing arm). Counts fnalign 1099 vs 1142 (-43, -3.8% OUTSIDE gate), words 759, edits 1089 +14 reloc, window 4576B (4396 emitted). Deletes 18 tot 95 retail-only, inserts 7 tot 191 object-only, replaces 82 (525 vs 386 net -139). Delete runs (retail addr = 0x3694D0+idx*4): [90:93] 0x369638 (sb tmp color 3B); [134:135] 0x3696E8 (andi alpha FF); [148:151] 0x369720 (sb tmp 3B); [173:174] 0x369784 (andi FF); [188:191] 0x3697C0 (sb tmp 3B); [209:219] 0x369814 len10 (lbu color 0x40-43 + sb tmp 0x8C-8F + sb zero 0x8F + addiu b5 0x4D8: mode0 b5 color copy/alpha-zero); [227:230] 0x36985C (sb tmp); [252:253] 0x3698C0 (andi); [272:275] 0x369910 (sb tmp); [276:280] 0x369920 len4 (sb zero x3 + lbu alpha: tmp clear/reload); [315:316] 0x3699BC (andi); [391:392] 0x369AEC (andi); [480:531] 0x369C50-0x369D1B len51 (THE hole: dispatch 10 [addiu 2/beq mode2 +294, beqz mode0 +46, addiu1/beq mode1 +4, b end +361] + mode1 arm 39 [8,1 tbl, 3,0x317F3, lw 0x170/0x174 + jal bee0(unk170,unk174), 1,v0 tbl, 2,0x44, 0x178 b0 block, 3,0x65... + jal 410420/10520/jal104d0] + b +322 + 2 moves for mode0 setup); [894:896] 0x36A2C8 (lui 0x88 table base); [932:936] 0x36A360 (b + lui base); [979:981] 0x36A41C (lui base); [1020:1021] 0x36A4C0 (not flags); [1024:1025] 0x36A4D0 (move s0,s2 colour). Collapsed replace [533:779] 0x369D24-0x36A0FB len246 vs object[454:455] len1 is mode0 7-block field group (8,1/3,0x317F3/3,1/4,1/1,d130(0)/2,0x44/0x178 b0/3,0x65../0x3B8 b4/0x328 b3/0x298 b2/lhu174/1,bff0/0x448 b5/0x4D8 b6/2,0x44/1,d130(1)/0x208 b1/flags&2?/2,0x48/3,3/4,3/1,d130(5)/0x568 b7); object has same 208 at 520:728 (colour s0 vs s2, zero relocs), so 38 short here + 51 above = 89 of the 95; rest colour. Inserts 60 at 103:163 (hoisted float 0x328/0x32C mul/div/c.ole + b5/b6 tbl) and 83 at 734:817 + 36 at 1022:1058 are duplicated tails from if/else vs switch layout (WALL). No code change this round (before=after); closing needs switch reorder to retail 1,0,3,2 layout + bee0/b0 fix, time-boxed. */
// FUN_003694D0 NONMATCHING
#ifdef NON_MATCHING
void func_003694d0(PscModel *model)
{
    u8 tmp[4];
    void *mtx;
    PscLight *e0work;
    PscModel *m0;
    PscModel *m1;
    PscModel *m2;
    PscModel *m3;
    void (**tbl)(u32 state, u32 value);
    u32 alpha;
    f32 alphaf;
    f32 f;

    if (model->mode < 0 || model->mode >= 4) {
        func_0046d730(D_0064E480, 0x2F7);
    }
    switch (model->mode) {
    case 1:
        m1 = model;
        e0work = model->e0;
        break;
    case 0:
        m0 = model;
        e0work = model->e0;
        break;
    case 2:
        m2 = model;
        e0work = model->e0;
        break;
    case 3:
        m3 = model;
        e0work = model->e0;
        break;
    }
    mtx = func_003e0f80();
    func_0036abd0(mtx, model);
    if (model->flags & 4) {
        func_0036ae00(e0work, model->color);
        switch (model->mode) {
        case 0:
            func_0036ae00(m0->u.m01.b0, model->color);
            func_0036ae00(m0->u.m01.b1, model->color);
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            alpha = model->color[3];
            alphaf = (f32)alpha;
            f = (30.0f * alphaf) / 100.0f;
            tmp[3] = (u8)(u32)f;
            func_0036ae00(m0->u.m01.b2, tmp);
            func_0036ae00(m0->u.m01.b3, tmp);
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            f = 255.0f * m0->u.m01.b8[0].dir.y;
            tmp[3] = (u8)(u32)f;
            func_0036ae00(m0->u.m01.b4, tmp);
            if (m0->u.m01.unk170 & 1) {
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            tmp[0] = 0;
            tmp[1] = 0;
            tmp[2] = 0;
            func_0036ae00(m0->u.m01.b5, tmp);
            } else {
            func_0036ae00(m0->u.m01.b5, model->color);
            }
            if (m0->u.m01.unk170 & 1) {
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            tmp[3] = 0;
            func_0036ae00(m0->u.m01.b6, tmp);
            } else {
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            f = 255.0f * m0->u.m01.b8[0].dir.x;
            tmp[3] = (u8)(u32)f;
            func_0036ae00(m0->u.m01.b6, tmp);
            }
            break;
        case 1:
            func_0036ae00(m1->u.m01.b1, model->color);
            func_0036ae00(m1->u.m01.b0, model->color);
            tmp[0] = model->color[0];
            tmp[1] = model->color[1];
            tmp[2] = model->color[2];
            tmp[3] = model->color[3];
            tmp[0] = 0;
            tmp[1] = 0;
            tmp[2] = 0;
            alpha = tmp[3];
            alphaf = (f32)alpha;
            f = m1->u.m01.b3[0].dir.y * (alphaf * m1->u.m01.b3[0].dir.x);
            tmp[3] = (u8)(u32)f;
            func_0036ae00(m1->u.m01.b2, tmp);
            break;
        case 2:
            func_0036ae00(m2->u.w170, model->color);
            break;
        case 3:
            func_0036ae00(m3->u.w170, model->color);
            break;
        }
        model->flags &= ~4;
    }
    switch (model->mode) {
    case 0:
        tmp[0] = model->color[0];
        tmp[1] = model->color[1];
        tmp[2] = model->color[2];
        tmp[3] = model->color[3];
        alpha = model->color[3];
        alphaf = (f32)alpha;
        f = ((255.0f * m0->u.m01.b8[0].dir.y * alphaf) / 255.0f);
        tmp[3] = (u8)(u32)f;
        func_0036ae00(m0->u.m01.b4, tmp);
        tmp[0] = model->color[0];
        tmp[1] = model->color[1];
        tmp[2] = model->color[2];
        tmp[3] = model->color[3];
        if (m0->u.m01.unk170 & 1) {
        tmp[3] = 0;
        } else {
        alpha = model->color[3];
        alphaf = (f32)alpha;
        f = ((255.0f * m0->u.m01.b8[0].dir.x * alphaf) / 255.0f);
        tmp[3] = (u8)(u32)f;
        }
        func_0036ae00(m0->u.m01.b6, tmp);
        break;
    }
    tbl = D_00887300;
    (*tbl)(9, 2);
    (*tbl)(0x14, 2);
    (*tbl)(6, 0);
    switch (model->mode) {
    case 1:
        (*tbl)(8, 1);
        RpSkyRenderStateSet(3, 0x317F3);
        (*tbl)(1, func_0036bee0(model->u.m01.unk170, model->u.m01.unk174));
        RpSkyRenderStateSet(2, 0x44);
        func_00410420(m1->u.m01.b0, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    case 0:
        m0 = model;
        (*tbl)(8, 1);
        RpSkyRenderStateSet(3, 0x317F3);
        (*tbl)(3, 1);
        (*tbl)(4, 1);
        (*tbl)(1, func_0036d130(0));
        RpSkyRenderStateSet(2, 0x44);
        func_00410420(m0->u.m01.b0, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*tbl)(1, func_0036d130(4));
        func_00410420(m0->u.m01.b4, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*tbl)(1, func_0036d130(3));
        func_00410420(m0->u.m01.b3, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*tbl)(1, func_0036d130(2));
        func_00410420(m0->u.m01.b2, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x44);
        (*tbl)(1, func_0036bff0((*(u16 *)&model->u.m01.unk174)));
        func_00410420(m0->u.m01.b5, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*tbl)(1, func_0036bff0((*(u16 *)&model->u.m01.unk174)));
        func_00410420(m0->u.m01.b6, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x44);
        (*tbl)(1, func_0036d130(1));
        func_00410420(m0->u.m01.b1, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        if (model->flags & 2) {
        RpSkyRenderStateSet(2, 0x48);
        (*tbl)(3, 3);
        (*tbl)(4, 3);
        (*tbl)(1, func_0036d130(5));
        func_00410420(m0->u.m01.b7, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        }
        break;
    case 2:
        (*tbl)(8, 1);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x317F3);
        (*tbl)(1, func_0036be70());
        func_00410420(model->u.w170, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    case 3:
        (*tbl)(8, 1);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x317F3);
        (*tbl)(1, func_0036c0d0());
        func_00410420(model->u.w170, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    }
    tbl = D_00887300;
    if ((model->flags & 1) != 0 && model->unk48 == 0) {
        switch (model->mode) {
        case 1:
            RpSkyRenderStateSet(2, 0x6A);
            (*tbl)(1, func_0036d130(1));
            func_00410420(m1->u.m01.b1, 4, mtx, 3);
            func_00410520(3, D_0064E470, 6);
            func_004104d0();
            break;
        }
        RpSkyRenderStateSet(2, 0x58);
        (*tbl)(4, 3);
        (*tbl)(1, func_0036d130(6));
        func_00410420(model->unk4C, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        (*tbl)(4, 1);
    }
    switch (model->mode) {
    case 1:
        (*tbl)(6, 0);
        (*tbl)(8, 1);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        (*tbl)(1, func_0036d1b0(1));
        func_00410420(m1->u.m01.b2, 4, mtx, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    }
    tbl = D_00887300;
    (*tbl)(1, func_0036be00());
    RpSkyRenderStateSet(2, 0x44);
    (*tbl)(6, 0);
    (*tbl)(8, 1);
    func_00410420(e0work, 4, mtx, 3);
    func_00410520(3, D_0064E470, 6);
    func_004104d0();
    tbl = D_00887300;
    if (model->flags & 8) {
        if ((*(u32 *)model->unkDC & 1) == 0) {
            (*tbl)(6, 0);
            (*tbl)(8, 1);
            RpSkyRenderStateSet(2, 0x6A);
            switch (model->mode) {
            case 0:
                (*tbl)(1, func_0036d130(1));
                func_00410420(model->u.m01.b1, 4, mtx, 3);
                break;
            case 1:
                (*tbl)(1, func_0036d1b0(0));
                func_00410420(model->u.m01.b1, 4, mtx, 3);
                break;
            case 2:
                RpSkyRenderStateSet(3, 0x71801);
                RpSkyRenderStateSet(2, 0x48);
                break;
            case 3:
                RpSkyRenderStateSet(3, 0x71801);
                RpSkyRenderStateSet(2, 0x48);
                break;
            }
            func_00410520(3, D_0064E470, 6);
            func_004104d0();
            RpSkyRenderStateSet(2, 0x58);
        } else {
            RpSkyRenderStateSet(3, 0x71801);
            RpSkyRenderStateSet(2, 0x48);
        }
        func_0036b470(model->unkDC, mtx);
    }
    func_003e0f40(mtx);
}
#else
INCLUDE_ASM("asm/nonmatchings/pscModel", func_003694d0);
#endif




// FUN_0036A6B0
void func_0036a6b0(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}



// FUN_0036A790
f32 func_0036a790(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}

// FUN_0036A820
void func_0036a820(u8 *arg0, s16 arg1)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        func_0046d730(D_0064E480, 0x524);
    }
    *(u16 *)(arg0 + 0x174) = arg1;
}

// FUN_0036A880
void func_0036a880(u8 *arg0, s32 arg1, s32 arg2)
{
    if (*(s32 *)(arg0 + 4) != 1) {
        func_0046d730(D_0064E480, 0x52F);
    }
    *(s32 *)(arg0 + 0x170) = arg1;
    *(s32 *)(arg0 + 0x174) = arg2;
}
// FUN_0036A900
void func_0036a900(PscLight *dst)
{
    PscVec v0;
    PscVec v1;
    PscVec v2;
    PscVec v3;

    v0.x = 3.0f;
    v0.y = D_00761480;
    v0.z = 0.0f;
    dst[0].dir = v0;
    v1.x = 3.0f;
    v1.y = D_00761484;
    v1.z = 0.0f;
    dst[1].dir = v1;
    v2.x = -3.0f;
    v2.y = D_00761484;
    v2.z = 0.0f;
    dst[2].dir = v2;
    v3.x = -3.0f;
    v3.y = D_00761480;
    v3.z = 0.0f;
    dst[3].dir = v3;
    dst[0].c[0] = 255;
    dst[0].c[1] = 255;
    dst[0].c[2] = 255;
    dst[0].c[3] = 255;
    dst[1].c[0] = 255;
    dst[1].c[1] = 255;
    dst[1].c[2] = 255;
    dst[1].c[3] = 255;
    dst[2].c[0] = 255;
    dst[2].c[1] = 255;
    dst[2].c[2] = 255;
    dst[2].c[3] = 255;
    dst[3].c[0] = 255;
    dst[3].c[1] = 255;
    dst[3].c[2] = 255;
    dst[3].c[3] = 255;
    dst[0].f1c = 0.9921875f;
    dst[1].f1c = 0.9921875f;
    dst[2].f1c = 0.0f;
    dst[3].f1c = 0.0f;
    dst[0].f20 = 0.0f;
    dst[1].f20 = 0.64453125f;
    dst[2].f20 = 0.64453125f;
    dst[3].f20 = 0.0f;
}
// FUN_0036AA20
void func_0036aa20(void)
{
    u16 *p;
    s32 v;
    s32 t1, t2;
    s32 col;
    s32 row;
    s32 parity;
    s32 i;

    v = 0;
    p = D_00884690;
    for (row = 0; row < 8; row++) {
        col = 0;
        parity = ~row & 1;
        for (; col < 6; col++) {
            if (parity != 0) {
                p[0] = v;
                t1 = v + 1;
                p[1] = t1;
                t2 = v + 8;
                p[2] = t2;
                p[3] = t1;
                p[4] = v + 9;
                p[5] = t2;
                p += 6;
                v = t1;
            } else {
                p[0] = v;
                t2 = v + 8;
                p[1] = t2;
                p[2] = v + 7;
                p[3] = v;
                v = v + 1;
                p[4] = v;
                p[5] = t2;
                p += 6;
            }
        }
        if (parity != 0) {
            p[0] = v;
            p[1] = v + 1;
            p[2] = v + 8;
            p += 3;
            v = v + 2;
        } else {
            p[0] = v;
            p[1] = v + 8;
            p[2] = v + 7;
            p += 3;
            v = v + 1;
        }
    }
    for (i = 0; i < 0x138; i++) {
        if (D_00884690[i] >= 0x44) {
            func_0046d730(D_0064E480, 0x5C8);
        }
    }
    if ((p - D_00884690) != 0x138) {
        func_0046d730(D_0064E480, 0x5CA);
    }
}
