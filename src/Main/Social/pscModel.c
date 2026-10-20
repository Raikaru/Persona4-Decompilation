/* Original translation unit pscModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "psc_model_internal.h"

extern f32 D_00761480;
extern f32 D_00761484;


extern void* kwlnGetCamera(void);
extern void kAssertFail(u8 *file, s32 line);
extern u8 D_0064E480[];
extern u16 D_00884690[];
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);

extern void *func_003e0f80(void);
extern void func_003e0f40(void *matrix);
extern void pscBuildModelMatrix(void *output, void *transform);
extern void pscPanelWriteVertexColors(void *work, const u8 *color);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void func_00410420(void *vertices, u32 count, void *matrix, u32 stride);
extern void func_00410520(u32 primitive, void *indices, u32 count);
extern void func_004104d0(void);
extern void (*D_00887300[])(u32 state, u32 value);
extern u16 D_0064E470[];
extern s32 pscResGetArcanaRaster(s32 group, s32 cardIndex);
extern s32 pscResGetPersonaRaster(s32 personaId);
extern s32 pscResGetBaseRaster(void);
extern s32 pscResGetMiscCardW00Raster(void);
extern s32 pscResGetMiscCardW01Raster(void);
extern s32 pscResGetMiscCardW00Texture(s32 textureIndex);
extern s32 pscResGetMiscCardW00SubTexture(s32 textureIndex);
extern void pscPanelDrawGrid(void *work, void *vertices);

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
/* Social-link model draw. Retail behaviour reproduced as is:
   - mode 1 copies the model into its own pointer (m1) only for the first two
     switches; the later mode-1 sections read m0, which is never set for mode 1
     (retail reads $s3 there without a mode-1 copy);
   - every fn/fn2 assignment names D_00887300 itself, so b210 forms the copy
     from the tbl register in the switch cases and reloads it elsewhere, as
     retail does; the unk48 and tail draws call through tbl. */
// Intent: Draws one social-link model: sets up the transform, then uploads per-part colours and fades for its mode (0-3) and issues the draw calls [inferred]
// FUN_003694D0
void pscModelDraw(PscModel *model)
{
    typedef struct { u8 r, g, b, a; } PscColorCopy;
    u8 tint[4];
    void *matrix;
    PscModel *modeZeroModel;
    PscModel *modeOneModel;
    PscModel *modeTwoModel;
    void (**renderStateSet)(u32 state, u32 value);
    void (**gridRenderStateSet)(u32 state, u32 value);
    void (**renderStateTable)(u32 state, u32 value);
    PscLight *lightQuad;
    PscModel *modeThreeModel;
    u32 alpha;
    f32 alphaf;
    f32 f;

    if (model->mode < 0 || model->mode >= 4) {
        kAssertFail(D_0064E480, 0x2F7);
    }
    switch (model->mode) {
    case 1:
        modeOneModel = model;
        lightQuad = model->e0;
        break;
    case 0:
        modeZeroModel = model;
        lightQuad = model->e0;
        break;
    case 2:
        modeTwoModel = model;
        lightQuad = model->e0;
        break;
    case 3:
        modeThreeModel = model;
        lightQuad = model->e0;
        break;
    }
    matrix = func_003e0f80();
    pscBuildModelMatrix(matrix, model);
    if (model->flags & 4) {
        pscPanelWriteVertexColors(lightQuad, model->color);
        switch (model->mode) {
        case 0:
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b0, model->color);
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b1, model->color);
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            alpha = model->color[3];
            alphaf = (f32)alpha;
            f = (30.0f * alphaf) / 100.0f;
            tint[3] = (u8)f;
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b2, tint);
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b3, tint);
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            f = 255.0f * modeZeroModel->u.m01.b8[0].dir.y;
            tint[3] = (u8)f;
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b4, tint);
            if (modeZeroModel->u.m01.unk170 & 1) {
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            tint[0] = 0;
            tint[1] = 0;
            tint[2] = 0;
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b5, tint);
            } else {
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b5, model->color);
            }
            if (modeZeroModel->u.m01.unk170 & 1) {
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            tint[3] = 0;
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b6, tint);
            } else {
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            f = 255.0f * modeZeroModel->u.m01.b8[0].dir.x;
            tint[3] = (u8)f;
            pscPanelWriteVertexColors(modeZeroModel->u.m01.b6, tint);
            }
            break;
        case 1:
            pscPanelWriteVertexColors(modeOneModel->u.m01.b1, model->color);
            pscPanelWriteVertexColors(modeOneModel->u.m01.b0, model->color);
            *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
            tint[0] = 0;
            tint[1] = 0;
            tint[2] = 0;
            alpha = tint[3];
            alphaf = (f32)alpha;
            f = modeOneModel->u.m01.b3[0].dir.y * (alphaf * modeOneModel->u.m01.b3[0].dir.x);
            tint[3] = (u8)f;
            pscPanelWriteVertexColors(modeOneModel->u.m01.b2, tint);
            break;
        case 2:
            pscPanelWriteVertexColors(modeTwoModel->u.w170, model->color);
            break;
        case 3:
            pscPanelWriteVertexColors(modeThreeModel->u.w170, model->color);
            break;
        }
        model->flags &= ~4;
    }
    switch (model->mode) {
    case 0:
        *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
        f = ((255.0f * modeZeroModel->u.m01.b8[0].dir.y * (f32)(u32)model->color[3]) / 255.0f);
        tint[3] = (u8)f;
        pscPanelWriteVertexColors(modeZeroModel->u.m01.b4, tint);
        *(PscColorCopy *)tint = *(PscColorCopy *)model->color;
        if (modeZeroModel->u.m01.unk170 & 1) {
        tint[3] = 0;
        } else {
        f = ((255.0f * modeZeroModel->u.m01.b8[0].dir.x * (f32)(u32)model->color[3]) / 255.0f);
        tint[3] = (u8)f;
        }
        pscPanelWriteVertexColors(modeZeroModel->u.m01.b6, tint);
        break;
    }
    renderStateTable = (void (**)(u32, u32))D_00887300;
    (*renderStateTable)(9, 2);
    (*renderStateTable)(0x14, 2);
    (*renderStateTable)(6, 0);
    switch (model->mode) {
    case 1:
        renderStateSet = (void (**)(u32, u32))D_00887300;
        (*renderStateSet)(8, 1);
        RpSkyRenderStateSet(3, 0x317F3);
        (*renderStateSet)(1, pscResGetArcanaRaster(model->u.m01.unk170, model->u.m01.unk174));
        RpSkyRenderStateSet(2, 0x44);
        func_00410420(model->u.m01.b0, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    case 0:
        modeZeroModel = model;
        renderStateSet = (void (**)(u32, u32))D_00887300;
        (*renderStateSet)(8, 1);
        RpSkyRenderStateSet(3, 0x317F3);
        (*renderStateSet)(3, 1);
        (*renderStateSet)(4, 1);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(0));
        RpSkyRenderStateSet(2, 0x44);
        func_00410420(modeZeroModel->u.m01.b0, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(4));
        func_00410420(modeZeroModel->u.m01.b4, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(3));
        func_00410420(modeZeroModel->u.m01.b3, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(2));
        func_00410420(modeZeroModel->u.m01.b2, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x44);
        (*renderStateSet)(1, pscResGetPersonaRaster((*(u16 *)&model->u.m01.unk174)));
        func_00410420(modeZeroModel->u.m01.b5, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x48);
        (*renderStateSet)(1, pscResGetPersonaRaster((*(u16 *)&model->u.m01.unk174)));
        func_00410420(modeZeroModel->u.m01.b6, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        RpSkyRenderStateSet(2, 0x44);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(1));
        func_00410420(modeZeroModel->u.m01.b1, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        if (model->flags & 2) {
        RpSkyRenderStateSet(2, 0x48);
        (*renderStateSet)(3, 3);
        (*renderStateSet)(4, 3);
        (*renderStateSet)(1, pscResGetMiscCardW00Texture(5));
        func_00410420(modeZeroModel->u.m01.b7, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        }
        break;
    case 2:
        renderStateSet = (void (**)(u32, u32))D_00887300;
        (*renderStateSet)(8, 1);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x317F3);
        (*renderStateSet)(1, pscResGetMiscCardW00Raster());
        func_00410420(model->u.w170, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    case 3:
        renderStateSet = (void (**)(u32, u32))D_00887300;
        (*renderStateSet)(8, 1);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x317F3);
        (*renderStateSet)(1, pscResGetMiscCardW01Raster());
        func_00410420(model->u.w170, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    }
    if ((model->flags & 1) != 0) {
        switch (model->unk48) {
        case 0:
            switch (model->mode) {
            case 1:
                RpSkyRenderStateSet(2, 0x6A);
                (*renderStateTable)(1, pscResGetMiscCardW00Texture(1));
                func_00410420(modeZeroModel->u.m01.b1, 4, matrix, 3);
                func_00410520(3, D_0064E470, 6);
                func_004104d0();
                break;
            }
            RpSkyRenderStateSet(2, 0x58);
            renderStateSet = (void (**)(u32, u32))D_00887300;
            (*renderStateSet)(4, 3);
            (*renderStateSet)(1, pscResGetMiscCardW00Texture(6));
            func_00410420(model->unk4C, 4, matrix, 3);
            func_00410520(3, D_0064E470, 6);
            func_004104d0();
            (*renderStateSet)(4, 1);
            break;
        }
    }
    switch (model->mode) {
    case 1:
        renderStateSet = (void (**)(u32, u32))D_00887300;
        (*renderStateSet)(6, 0);
        (*renderStateSet)(8, 1);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        (*renderStateSet)(1, pscResGetMiscCardW00SubTexture(1));
        func_00410420(model->u.m01.b2, 4, matrix, 3);
        func_00410520(3, D_0064E470, 6);
        func_004104d0();
        break;
    }
    alpha = pscResGetBaseRaster();
    renderStateSet = (void (**)(u32, u32))D_00887300;
    (*renderStateSet)(1, alpha);
    RpSkyRenderStateSet(2, 0x44);
    (*renderStateSet)(6, 0);
    (*renderStateSet)(8, 1);
    func_00410420(lightQuad, 4, matrix, 3);
    func_00410520(3, D_0064E470, 6);
    func_004104d0();
    if (model->flags & 8) {
        if (~*(u32 *)model->unkDC & 1) {
            gridRenderStateSet = (void (**)(u32, u32))D_00887300;
            (*gridRenderStateSet)(6, 0);
            (*gridRenderStateSet)(8, 1);
            RpSkyRenderStateSet(2, 0x6A);
            switch (model->mode) {
            case 0:
                (*renderStateTable)(1, pscResGetMiscCardW00Texture(1));
                func_00410420(model->u.m01.b1, 4, matrix, 3);
                break;
            case 1:
                (*renderStateTable)(1, pscResGetMiscCardW00SubTexture(0));
                func_00410420(model->u.m01.b1, 4, matrix, 3);
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
        pscPanelDrawGrid(model->unkDC, matrix);
    }
    func_003e0f40(matrix);
}





// Intent: Projects a 3D model position to panel screen coordinates using the camera and the viewport size [inferred]
// FUN_0036A6B0
void pscModelScreenPos(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)kwlnGetCamera() + 0x68);
    func_003e8970(size, func_003e89c0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}



// Intent: Returns the panel scale factor for a model, derived from the camera and viewport width [inferred]
// FUN_0036A790
f32 pscModelPanelScale(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)kwlnGetCamera() + 0x68);
    func_003e8970(size, func_003e89c0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}

// FUN_0036A820
/* Select the persona card for a mode-zero panel; other panel modes are rejected. */
void pscModelSetPersonaCard(u8 *model, s16 personaId)
{
    if (((PscModel *)model)->mode != 0) {
        kAssertFail(D_0064E480, 0x524);
    }
    *(u16 *)&((PscModel *)model)->u.m01.unk174 = personaId;
}

// FUN_0036A880
/* Select the arcana group and card index for a mode-one panel. */
void pscModelSetArcanaCard(u8 *model, s32 group, s32 index)
{
    if (((PscModel *)model)->mode != 1) {
        kAssertFail(D_0064E480, 0x52F);
    }
    ((PscModel *)model)->u.m01.unk170 = group;
    ((PscModel *)model)->u.m01.unk174 = index;
}

// FUN_0036A8F0
/* Store the parent-frame address consumed when the tile builder transforms the model position. */
void pscModelSetParentFrame(void* work, u32 value)
{
    *(u32 *)&((PscModel *)work)->frame = value;
}

// Intent: fill a PscLight[4] quad with default corner positions, white colour and fixed fade values (the e0 block of PscModel). [inferred]
// FUN_0036A900
void pscLightInitQuad(PscLight *dst)
{
    PscVec rightUpper;
    PscVec rightLower;
    PscVec leftLower;
    PscVec leftUpper;

    rightUpper.x = 3.0f;
    rightUpper.y = D_00761480;
    rightUpper.z = 0.0f;
    dst[0].dir = rightUpper;
    rightLower.x = 3.0f;
    rightLower.y = D_00761484;
    rightLower.z = 0.0f;
    dst[1].dir = rightLower;
    leftLower.x = -3.0f;
    leftLower.y = D_00761484;
    leftLower.z = 0.0f;
    dst[2].dir = leftLower;
    leftUpper.x = -3.0f;
    leftUpper.y = D_00761480;
    leftUpper.z = 0.0f;
    dst[3].dir = leftUpper;
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
// Intent: Fills the 0x138-entry index table for the 8x6 panel grid: alternating-parity quads with two triangles per cell and an edge row [inferred]
// FUN_0036AA20
void pscBuildGridIndexTable(void)
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
            kAssertFail(D_0064E480, 0x5C8);
        }
    }
    if ((p - D_00884690) != 0x138) {
        kAssertFail(D_0064E480, 0x5CA);
    }
}
