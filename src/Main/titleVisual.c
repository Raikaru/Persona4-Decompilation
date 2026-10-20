#include "include_asm.h"
/* Original translation unit titleVisual.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "primitive_queue_internal.h"

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 *PrimAllocQueueNode();
extern void PrimAppendNode(void *list, void *node);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 D_0063EE50[];
extern void titleVisualDraw(void *unusedQueue, void *packet);
extern void titleVisualDrawTintedModel(u8 *model, s8 *color);
extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
extern void RpSkyRenderStateSet(s32, s32);
extern void (*D_00887300[])(u32 state, u32 value);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern void mdlSetColor(void *model, void *color);
extern void mdlApplyColorToAtomics(void *model);
extern void mdlUpdateModelMatrix(void *model);
extern void mdlPrepareItemSlots(void *model);
extern void mdlDrawVisibleAtomics(s32 clump);
extern s32 shdSpriteDrawNow(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
extern void datScreenPointToWorldPosition(void *output, s32 screenX, s32 screenY, f32 distance);
extern void *kwlnGetCamera(void);
extern u8 *func_003e9700(s32);
extern void RwV3dNormalize(void *a, void *b);
extern void RwMatrixUpdate(void *);
extern void RwMatrixScale(void *a0, void *a1, s32 a2);
extern void RwMatrixMultiply(void *a, void *b, void *c);
extern void RwMatrixTranslate(void *dst, void *src, s32 mode);
extern void *mdlGetMatrix(u32 model);
extern void titleVisualDrawSpritePacket(u8 *unused, u8 *packet);
extern void titleVisualDrawModelPacket(void *unused, u8 *packet);

typedef struct { f32 v0, v1, v2, v3; } Float4;
typedef struct { u8 b0, b1, b2, b3; } Byte4;
typedef signed __int128 s128;

/* Packet sizes are established by the three allocators below (0x1C/0x60).
 * Rect bounds preserve integer bits in the original four-float copy transport. */
typedef struct TitleRectPacket
{
    Float4 bounds;
    f32 depth;
    Byte4 color;
    s32 flags;
} TitleRectPacket;

typedef struct TitleSpritePacket
{
    f32 x, y, depth;
    s32 color;
    s32 flags;
    void *resource;
    s32 spriteIndex;
} TitleSpritePacket;

typedef struct TitleModelPacket
{
    u32 color;
    u8 pad04[0xC];
    f32 matrix[16];
    s32 flags;
    u8 *model;
    u8 pad58[8];
} TitleModelPacket;

/* Model prefix agrees with mdlManager.c: flags +0xD8, clump +0xDC.
 * Matrices and the rest of the model remain owned by the mdl API. */
typedef struct Model
{
    u8 pad00[0xD8];
    s32 flags;
    s32 clump;
} Model;

// FUN_002AAF20
/* Allocate a rectangle packet from screen bounds; enqueue it or draw immediately. */
void titleVisualSubmitRect(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *queue) {
    f32 bounds[4];
    u8 *clearCursor;
    s32 bytesRemaining;
    u8 *packet;
    u8 *drawNode;

    chkmemAllocSiteTag(D_0063EE50, 0x91);
    packet = D_008873F4[0](1, 0x1C, 0x40000);
    clearCursor = (u8 *)&bounds[0];
    bytesRemaining = 0x10;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            bytesRemaining -= 1;
        } while (bytesRemaining != 0);
    }
    *(s32 *)&bounds[0] = (s32)x;
    *(s32 *)&bounds[1] = (s32)y;
    *(s32 *)&bounds[2] = (s32)(x + width);
    *(s32 *)&bounds[3] = (s32)(y + height);
    ((TitleRectPacket *)packet)->bounds = *(Float4 *)&bounds[0];
    ((TitleRectPacket *)packet)->depth = depth;
    ((TitleRectPacket *)packet)->color = *(Byte4 *)color;
    ((TitleRectPacket *)packet)->flags = flags;
    if (queue != NULL) {
        drawNode = PrimAllocQueueNode();
        ((PrimQueueNode *)drawNode)->callback = (void *)titleVisualDraw;
        ((PrimQueueNode *)drawNode)->argument.data = packet;
        PrimAppendNode(queue, drawNode);
    } else {
        titleVisualDraw(NULL, packet);
    }
}

/* measured: opt_propagation off preserves retail's cached render-table base. */
#pragma opt_propagation off
// FUN_002AB0E0
/* Draw a sprite packet with its requested blend/depth flags, then free it. */
void titleVisualDrawSpritePacket(u8 *unused, u8 *packet) {
    f32 x;
    f32 y;
    f32 depth;
    u32 packedColor;
    s32 flags;
    void (**render)(u32 state, u32 value);

    packedColor = *(u32 *)&((TitleSpritePacket *)packet)->color;
    x = ((TitleSpritePacket *)packet)->x;
    y = ((TitleSpritePacket *)packet)->y;
    depth = ((TitleSpritePacket *)packet)->depth;
    flags = ((TitleSpritePacket *)packet)->flags;
    render = &D_00887300[0];
    (*render)(10, 5);
    (*render)(11, 6);
    (*render)(14, 0);
    (*render)(12, 1);
    (*render)(7, 2);
    (*render)(9, 2);
    (*render)(2, 4);
    (*render)(20, 1);
    (*render)(6, 0);
    (*render)(8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    (*render)(1, 0);
    if ((flags & 1) != 0) {
        (*render)(6, 1);
    }
    if ((flags & 2) != 0) {
        (*render)(8, 1);
    }
    if ((flags & 4) != 0) {
        RpSkyRenderStateSet(3, 0x5000D);
    }
    if ((flags & 8) != 0) {
        RpSkyRenderStateSet(2, 0x54);
    }
    if ((flags & 0x20) != 0) {
        RpSkyRenderStateSet(2, 0x58);
    }
    if ((flags & 0x40) != 0) {
        shdEnableBlendFlag();
    }
    if ((flags & 0x10) != 0) {
        mdlEffectEmitMaskedTagPair();
    }
    shdSpriteDrawNow(x, y, depth, (s32)(packedColor >> 8), (s32)(packedColor & 0xFF), ((TitleSpritePacket *)packet)->spriteIndex, 0, (u8 *)(*(s32 *)&((TitleSpritePacket *)packet)->resource), 0);
    if ((flags & 0x10) != 0) {
        mdlEffectEmitTagPair();
    }
    if ((flags & 0x40) != 0) {
        shdDisableBlendFlag();
    }
    jtbl_008873EC[0](packet);
}
#pragma opt_propagation on

// FUN_002AB380
/* Build a tinted sprite packet and dispatch it through the optional draw queue. */
void titleVisualSubmitSprite(f32 x, f32 y, f32 depth, s32 rgb, s32 alpha, s32 spriteIndex, void *resource, s32 flags, void *queue) {
    u8 *packet;
    u8 *drawNode;

    chkmemAllocSiteTag(D_0063EE50, 0xE1);
    packet = D_008873F4[0](1, 0x1C, 0x40000);
    ((TitleSpritePacket *)packet)->x = x;
    ((TitleSpritePacket *)packet)->y = y;
    ((TitleSpritePacket *)packet)->depth = depth;
    ((TitleSpritePacket *)packet)->color = (rgb << 8) | alpha;
    ((TitleSpritePacket *)packet)->flags = flags;
    ((TitleSpritePacket *)packet)->resource = resource;
    ((TitleSpritePacket *)packet)->spriteIndex = spriteIndex;
    if (queue != NULL) {
        drawNode = PrimAllocQueueNode();
        ((PrimQueueNode *)drawNode)->callback = (void *)titleVisualDrawSpritePacket;
        ((PrimQueueNode *)drawNode)->argument.data = packet;
        PrimAppendNode(queue, drawNode);
        return;
    }
    titleVisualDrawSpritePacket(NULL, packet);
}

// FUN_002AB4B0
/* Draw a queued model with its saved flags and matrix, restoring the live flags afterward. */
/* Typed Model/TitleModelPacket accesses change b210 register allocation; retain
 * their proven +0xD8/+0xDC and +0x50/+0x54 byte accesses for MATCH. */
void titleVisualDrawModelPacket(void *unused, u8 *packet) {
    s8 color[4];
    u8 *model;
    s32 savedFlags;
    u32 packedColor;

    packedColor = *(u32 *)packet;
    color[0] = (s8)(packedColor >> 24);
    color[1] = (s8)(packedColor >> 16);
    color[2] = (s8)(packedColor >> 8);
    color[3] = (s8)packedColor;
    model = *(u8 **)(packet + 0x54);
    savedFlags = *(s32 *)(model + 0xD8);
    *(s32 *)(model + 0xD8) = *(s32 *)(packet + 0x50);
    mdlApplyModelMatrix(model, packet + 0x10, 0);
    titleVisualDrawTintedModel(model, color);
    *(s32 *)(model + 0xD8) = savedFlags;
    jtbl_008873EC[0](packet);
}

/* measured: opt_propagation off preserves retail's cached render-table base. */
#pragma opt_propagation off
// FUN_002AB550
/* Install the title render state and draw the model with the supplied RGBA color. */
/* Typed Model/TitleModelPacket accesses change b210 register allocation; retain
 * their proven +0xD8/+0xDC and +0x50/+0x54 byte accesses for MATCH. */
void titleVisualDrawTintedModel(u8 *model, s8 *color) {
    void (**render)(u32 state, u32 value);

    render = D_00887300;
    render[0](10, 5);
    render[0](11, 6);
    render[0](14, 0);
    render[0](12, 1);
    render[0](7, 2);
    render[0](9, 2);
    render[0](2, 4);
    render[0](20, 2);
    render[0](6, 0);
    render[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    render[0](1, 0);
    if ((*(s32 *)(model + 0xD8) & 8) != 0) {
        render[0](6, 1);
    }
    if ((*(s32 *)(model + 0xD8) & 0x10) != 0) {
        render[0](8, 1);
    }
    if ((*(s32 *)(model + 0xD8) & 0x40000) != 0) {
        shdEnableBlendFlag();
    }
    if ((*(s32 *)(model + 0xD8) & 0x100000) != 0) {
        mdlEffectEmitMaskedTagPair();
    }
    mdlSetColor(model, color);
    mdlApplyColorToAtomics(model);
    mdlUpdateModelMatrix(model);
    mdlPrepareItemSlots(model);
    mdlDrawVisibleAtomics(*(s32 *)(model + 0xDC));
    if ((*(s32 *)(model + 0xD8) & 0x40000) != 0) {
        shdDisableBlendFlag();
    }
    if ((*(s32 *)(model + 0xD8) & 0x100000) != 0) {
        mdlEffectEmitTagPair();
    }
}
#pragma opt_propagation on

// FUN_002AB790
/* Build a camera-facing scaled model matrix and submit a model packet; immediate drawing restores the live matrix. */
/* Typed Model/TitleModelPacket accesses change b210 register allocation; retain
 * their proven +0xD8/+0xDC and +0x50/+0x54 byte accesses for MATCH. */
void titleVisualSubmitModel(f32 x, f32 y, f32 depth, s32 rgb, s32 alpha, f32 scale, s32 projectPosition, u8 *model, void *queue) {
    s8 color[4];
    f32 translation[3];
    f32 scaleVector[3];
    f32 projectedPosition[3];
    f32 drawMatrix[16];
    f32 combinedMatrix[16];
    void *modelMatrix;
    s32 screenY;
    s32 screenX;
    u8 *cameraMatrixCursor;
    u8 *matrixCopyCursor;
    s32 cameraPairsRemaining;
    s128 *combinedQuadwords;
    s128 *drawQuadwords;
    s32 quadwordsRemaining;
    u8 *packet;
    u8 *drawNode;
    s32 savedFlags;
    u8 *drawModel;
    u32 packedColor;
    u8 *savedMatrixCursor;
    s32 cameraFirstWord;
    s32 cameraSecondWord;
    s32 packetFirstWord;
    s32 packetSecondWord;
    s32 savedFirstWord;
    s32 savedSecondWord;
    s128 matrixQuadword;
    u8 *packetMatrixSource;
    u8 *packetMatrixCursor;
    s32 packetPairsRemaining;
    u8 *restoreMatrixCursor;
    s32 restorePairsRemaining;

    modelMatrix = mdlGetMatrix((u32)(s32)model);
    screenY = (s32)y;
    screenX = (s32)x;
    datScreenPointToWorldPosition(projectedPosition, screenX, screenY, depth);
    cameraMatrixCursor = func_003e9700(*(s32 *)((u8 *)kwlnGetCamera() + 4));
    matrixCopyCursor = (u8 *)drawMatrix;
    cameraPairsRemaining = 8;
    do {
        cameraFirstWord = *(s32 *)(cameraMatrixCursor + 0);
        cameraSecondWord = *(s32 *)(cameraMatrixCursor + 4);
        cameraMatrixCursor += 8;
        cameraPairsRemaining -= 1;
        *(s32 *)(matrixCopyCursor + 0) = cameraFirstWord;
        *(s32 *)(matrixCopyCursor + 4) = cameraSecondWord;
        matrixCopyCursor += 8;
    } while (cameraPairsRemaining > 0);
    drawMatrix[8] = projectedPosition[0] - drawMatrix[12];
    drawMatrix[9] = projectedPosition[1] - drawMatrix[13];
    drawMatrix[10] = projectedPosition[2] - drawMatrix[14];
    RwV3dNormalize(&drawMatrix[8], &drawMatrix[8]);
    drawMatrix[12] -= drawMatrix[12];
    drawMatrix[13] -= drawMatrix[13];
    drawMatrix[14] -= drawMatrix[14];
    RwMatrixUpdate(drawMatrix);
    scaleVector[2] = scale;
    scaleVector[1] = scale;
    scaleVector[0] = scale;
    RwMatrixScale(drawMatrix, scaleVector, 0);
    RwMatrixMultiply(combinedMatrix, drawMatrix, modelMatrix);
    combinedQuadwords = (s128 *)combinedMatrix;
    drawQuadwords = (s128 *)drawMatrix;
    quadwordsRemaining = 4;
    do {
        matrixQuadword = *combinedQuadwords;
        combinedQuadwords += 1;
        quadwordsRemaining -= 1;
        *drawQuadwords = matrixQuadword;
        drawQuadwords += 1;
    } while (quadwordsRemaining > 0);
    if (projectPosition != 0) {
        datScreenPointToWorldPosition(translation, screenX, screenY, depth);
    } else {
        translation[0] = x;
        translation[1] = y;
        translation[2] = depth;
    }
    RwMatrixTranslate(drawMatrix, translation, 2);
    chkmemAllocSiteTag(D_0063EE50, 0x16B);
    packet = D_008873F4[0](1, 0x60, 0x40000);
    *(u32 *)(packet + 0) = (rgb << 8) | alpha;
    *(s32 *)(packet + 0x50) = *(s32 *)(model + 0xD8);
    packetMatrixSource = (u8 *)drawMatrix;
    packetMatrixCursor = packet + 0x10;
    packetPairsRemaining = 8;
    do {
        packetFirstWord = *(s32 *)(packetMatrixSource + 0);
        packetSecondWord = *(s32 *)(packetMatrixSource + 4);
        packetMatrixSource += 8;
        packetPairsRemaining -= 1;
        *(s32 *)(packetMatrixCursor + 0) = packetFirstWord;
        *(s32 *)(packetMatrixCursor + 4) = packetSecondWord;
        packetMatrixCursor += 8;
    } while (packetPairsRemaining > 0);
    *(u8 **)(packet + 0x54) = model;
    if (queue != NULL) {
        drawNode = PrimAllocQueueNode();
        *(void **)(drawNode + 8) = (void *)titleVisualDrawModelPacket;
        *(u8 **)(drawNode + 0x10) = packet;
        PrimAppendNode(queue, drawNode);
    } else {
        savedMatrixCursor = mdlGetMatrix((u32)(s32)model);
        restoreMatrixCursor = (u8 *)drawMatrix;
        restorePairsRemaining = 8;
        do {
            savedFirstWord = *(s32 *)(savedMatrixCursor + 0);
            savedSecondWord = *(s32 *)(savedMatrixCursor + 4);
            savedMatrixCursor += 8;
            restorePairsRemaining -= 1;
            *(s32 *)(restoreMatrixCursor + 0) = savedFirstWord;
            *(s32 *)(restoreMatrixCursor + 4) = savedSecondWord;
            restoreMatrixCursor += 8;
        } while (restorePairsRemaining > 0);
        packedColor = *(u32 *)(packet + 0);
        color[0] = (s8)(packedColor >> 24);
        color[1] = (s8)(packedColor >> 16);
        color[2] = (s8)(packedColor >> 8);
        color[3] = (s8)packedColor;
        drawModel = *(u8 **)(packet + 0x54);
        savedFlags = *(s32 *)(drawModel + 0xD8);
        *(s32 *)(drawModel + 0xD8) = *(s32 *)(packet + 0x50);
        mdlApplyModelMatrix(drawModel, packet + 0x10, 0);
        titleVisualDrawTintedModel(drawModel, color);
        *(s32 *)(drawModel + 0xD8) = savedFlags;
        jtbl_008873EC[0](packet);
        mdlApplyModelMatrix(model, drawMatrix, 0);
    }
}

/* measured: opt_propagation off preserves the retail alloc-table base hoist. */
#pragma opt_propagation off
// FUN_002ABB30
/* Bracket the title model with full-screen rectangle packets to establish and restore the mask. */
void titleVisualDrawMaskedModel(
    f32 x,
    f32 y,
    f32 depth,
    s32 rgb,
    s32 alpha,
    f32 scale,
    s32 projectPosition,
    u8 *model,
    void *queue
) {
    f32 backgroundBounds[4];
    f32 foregroundBounds[4];
    f32 restoreBounds[4];
    f32 clearColor[2];
    u8 *clearCursor;
    s32 count;
    u8 *packet;
    u8 *restorePacket;
    u8 *callback;
    u32 color;
    void *(**alloc)(size_t, size_t, u32);

    clearCursor = (u8 *)&clearColor[0];
    count = 4;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            count -= 1;
        } while (count != 0);
    }
    clearColor[1] = clearColor[0];
    chkmemAllocSiteTag(D_0063EE50, 0x91);
    alloc = D_008873F4;
    packet = alloc[0](1, 0x1C, 0x40000);
    clearCursor = (u8 *)&backgroundBounds[0];
    count = 0x10;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            count -= 1;
        } while (count != 0);
    }
    *(s32 *)&backgroundBounds[0] = 0;
    *(s32 *)&backgroundBounds[1] = 0;
    *(s32 *)&backgroundBounds[2] = 640;
    *(s32 *)&backgroundBounds[3] = 480;
    ((TitleRectPacket *)packet)->bounds = *(Float4 *)&backgroundBounds[0];
    *(s32 *)&((TitleRectPacket *)packet)->depth = 0;
    ((TitleRectPacket *)packet)->color = *(Byte4 *)&clearColor[1];
    ((TitleRectPacket *)packet)->flags = 0x12;
    if (queue != NULL) {
        callback = PrimAllocQueueNode();
        ((PrimQueueNode *)callback)->callback = (void *)titleVisualDraw;
        ((PrimQueueNode *)callback)->argument.data = packet;
        PrimAppendNode(queue, callback);
    } else {
        titleVisualDraw(NULL, packet);
    }
    titleVisualSubmitModel(x, y, depth, rgb, alpha, scale, projectPosition, model, queue);
    color = (u32)((rgb << 8) | alpha);
    ((u8 *)&clearColor[1])[0] = (u8)(color >> 24);
    ((u8 *)&clearColor[1])[1] = (u8)(color >> 16);
    ((u8 *)&clearColor[1])[2] = (u8)(color >> 8);
    ((u8 *)&clearColor[1])[3] = (u8)color;
    chkmemAllocSiteTag(D_0063EE50, 0x91);
    packet = alloc[0](1, 0x1C, 0x40000);
    clearCursor = (u8 *)&foregroundBounds[0];
    count = 0x10;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            count -= 1;
        } while (count != 0);
    }
    *(s32 *)&foregroundBounds[0] = 0;
    *(s32 *)&foregroundBounds[1] = 0;
    *(s32 *)&foregroundBounds[2] = 640;
    *(s32 *)&foregroundBounds[3] = 480;
    ((TitleRectPacket *)packet)->bounds = *(Float4 *)&foregroundBounds[0];
    ((TitleRectPacket *)packet)->depth = 1.0f;
    ((TitleRectPacket *)packet)->color = *(Byte4 *)&clearColor[1];
    ((TitleRectPacket *)packet)->flags = 1;
    if (queue != NULL) {
        callback = PrimAllocQueueNode();
        ((PrimQueueNode *)callback)->callback = (void *)titleVisualDraw;
        ((PrimQueueNode *)callback)->argument.data = packet;
        PrimAppendNode(queue, callback);
    } else {
        titleVisualDraw(NULL, packet);
    }
    chkmemAllocSiteTag(D_0063EE50, 0x91);
    restorePacket = alloc[0](1, 0x1C, 0x40000);
    clearCursor = (u8 *)&restoreBounds[0];
    count = 0x10;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            count -= 1;
        } while (count != 0);
    }
    *(s32 *)&restoreBounds[0] = 0;
    *(s32 *)&restoreBounds[1] = 0;
    *(s32 *)&restoreBounds[2] = 640;
    *(s32 *)&restoreBounds[3] = 480;
    ((TitleRectPacket *)restorePacket)->bounds = *(Float4 *)&restoreBounds[0];
    *(s32 *)&((TitleRectPacket *)restorePacket)->depth = 0;
    ((TitleRectPacket *)restorePacket)->color = *(Byte4 *)&clearColor[1];
    ((TitleRectPacket *)restorePacket)->flags = 8;
    if (queue != NULL) {
        callback = PrimAllocQueueNode();
        ((PrimQueueNode *)callback)->callback = (void *)titleVisualDraw;
        ((PrimQueueNode *)callback)->argument.data = restorePacket;
        PrimAppendNode(queue, callback);
    } else {
        titleVisualDraw(NULL, restorePacket);
    }
}
#pragma opt_propagation on
