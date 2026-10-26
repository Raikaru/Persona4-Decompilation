/* Original translation unit sdkDbprt.c (from __FILE__ assert strings). */
#include "operand_order_internal.h"
#include "type.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "rw_camera_internal.h"
#include "shd_misc_internal.h"

/* SDK RwImage layout, include/rw/core/baimage.h. */
typedef struct RwImage {
    s32 flags;
    s32 width;
    s32 height;
    s32 depth;
    s32 stride;
    u8 *pixels;
    RwRGBA *palette;
} RwImage;

#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)
typedef struct { u8 b0, b1, b2, b3; } RGBA8;
typedef struct HDbText3D HDbText3D;
struct HDbText3D
{
    HDbText3D* next;
    f32 x;
    f32 y;
    f32 cameraDepth;
    u8 text[256];
    f32 depthOffset;
    union { u8 color[4]; RGBA8 packedColor; };
};


static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
/* These statics are emitted in reverse declaration order, placing queue, camera, image and raster
 * at consecutive words 0x00764ACC through 0x00764AD8. */
static s32 *iGpffffb9e8;    /* gp -0x4618 (0x00764AD8), font raster */
static u8 *iGpffffb9e4;     /* gp -0x461C (0x00764AD4), loaded image */
static void *iGpffffb9e0;   /* gp -0x4620 (0x00764AD0), camera */
static HDbText3D* iGpffffb9dc; /* gp -0x4624 (0x00764ACC), queued text */

extern void* memset(void* destination, s32 value, size_t count);
/* rwGlobals.memFuncs.RwFree slot: indirect call through data. */
extern void (*RwFree_abs[])(void* memory);

/* Absolute debug-assert strings and file resources (0x007105xx region). */
extern char D_00710500[];
extern char D_00710510[];
extern char D_00710530[];
/* Absolute 12x12 font grid (zero-filled .bss). */
extern u8 D_008BF720[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];

/* library / file helpers */
extern void func_00440b68(const char *fmt, ...);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void H_Cdvd_ReadSync(void *cdvd);
extern void H_Cdvd_Destroy(u8 *cdvd);
extern u8 *func_003eaf60(u8 *);
extern s32 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003ec180(u8 *, s32 *);
extern s32 func_003ea370(s32 *);


/* text3d helpers */
extern void chkmemSetLock(s32 );
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void vsprintf(void *buf, const void *fmt, void *va);
extern char iGpffffac30;
extern char iGpffffac38[6]; /* gp -0x53C8: "%s %d" */

typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)


/* Loads the debug font resources, creates its raster and records the camera. */
// FUN_0044F570
void sdkDbprtInit(s32 cameraAddress) {
    u8 *fontRequest;
    u8 *paletteRequest;
    s32 *raster;

    func_00440b68(iGpffffac38, D_00710500, 0x4F);
    fontRequest = H_Cdvd_AcquireDirectory((u8 *)D_00710510, 0);
    H_Cdvd_ReadSync(fontRequest);
    func_00440b68(iGpffffac38, D_00710500, 0x52);
    paletteRequest = H_Cdvd_AcquireDirectory((u8 *)D_00710530, 0);
    H_Cdvd_ReadSync(paletteRequest);
    H_Cdvd_Destroy(paletteRequest);
    iGpffffb9e4 = func_003eaf60((u8 *)D_00710510);
    iGpffffb9e0 = (void *)cameraAddress;
    H_Cdvd_Destroy(fontRequest);
    raster = func_003ec590(((RwImage *)iGpffffb9e4)->width, ((RwImage *)iGpffffb9e4)->height, 4, 0x4504);
    iGpffffb9e8 = raster;
    func_003ec180((u8 *)raster, (s32 *)iGpffffb9e4);
    func_003ea370((s32 *)iGpffffb9e4);
    iGpffffb9e4 = NULL;
    memset(D_008BF720, 0x20, 0x848);
    iGpffffb9dc = NULL;
}

/* Clear the character grid and release every queued text entry. */
// FUN_0044F6B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = iGpffffb9dc;
    iGpffffb9dc = NULL;
    while (1)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree_abs[0](curr);
        curr = next;
    }
}
/* The near-depth field is read through the complete device record, which shapes the vertex-loop
 * preheader. */
#pragma push
/* measured: retail hoists the near depth and white color out of the vertex loop. */
#pragma opt_loop_invariants on
/* The glyph atlas has sixteen columns. Keep this conversion signed so
 * its remainder operation also describes negative input values. */


/* Draws non-space characters from the 53 by 40 debug grid and restores fog state. */
// FUN_0044F720
void sdkDbprtDrawGrid(void)
{
    extern u32 func_003e8120(u32 camera);
    extern u32 func_003e8110(u32 camera);
    extern void sdkDbprtDrawQueuedText(void);
    extern void sdkDbprtDrawOverlay(void);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 (*D_00887304[])(s32 state, void *value);
    extern s32 (*D_00887310[])(s32, void *, s32);
    typedef struct DebugRenderDevice {
        f32 gamma;
        s32 (*system)(s32, void *, void *, s32);
        f32 nearDepth;
        f32 farDepth;
        s32 (*setState)(s32, void *);
        s32 (*getState)(s32, void *);
        /* The eight remaining immediate-mode callbacks occupy address words. */
        u32 renderCallbackAddresses[8];
    } DebugRenderDevice;
    extern DebugRenderDevice D_008872F0;
    f32 textureCoordinates[8];
    typedef struct DebugGlyphVertex {
        f32 position[3];
        f32 cameraZ;
        f32 texcoord[2];
        f32 reciprocal;
        f32 pad1;
        f32 color[4];
        f32 normal[3];
        f32 pad2;
    } DebugGlyphVertex;
    DebugGlyphVertex vertices[4];
    s32 savedFog;
    f32 reciprocalDepth;
    f32 topY;
    f32 bottomY;
    s32 column;
    s32 row;
    struct { s32 (*setState)(s32, void *); } *renderer;
    u8 *characters;

    reciprocalDepth = 1.0f / ((RwCamera *)iGpffffb9e0)->nearPlane;
    if (func_003e8120((u32)iGpffffb9e0) != 0) {
        D_00887304[0](14, &savedFog);
        renderer = (void *)D_00887300;
        renderer->setState(14, (void *)0);
        renderer->setState(6, (void *)1);
        renderer->setState(7, (void *)2);
        renderer->setState(8, (void *)1);
        renderer->setState(9, (void *)1);
        renderer->setState(12, (void *)1);
        renderer->setState(1, iGpffffb9e8);
        {
            s32 vertexIndex;
            vertexIndex = 0;
            for (; vertexIndex < 4; vertexIndex++) {
                DebugGlyphVertex *vertex = &vertices[vertexIndex];
                vertex->reciprocal = reciprocalDepth;
                vertex->color[0] = 255.0f;
                vertex->color[1] = 255.0f;
                vertex->color[2] = 255.0f;
                vertex->color[3] = 255.0f;
                vertex->position[2] = D_008872F0.nearDepth;
            }
        }
        row = 0;
        while (row < 0x28) {
            column = 0;
            characters = (u8 *)sGrid[row];
            topY = 12.0f * (f32)row;
            bottomY = 11.0f + topY;
            for (; column < 0x35; column++) {
                u8 character;
                character = characters[column];
                if (character != 0x20) {
                    u8 glyphIndex;
                    f32 leftX;
                    f32 rightX;
                    s32 tileColumn;
                    f32 leftU;
                    f32 topV;
                    s32 vertexIndex;
                    glyphIndex = character - 0x20;
                    if ((s32)glyphIndex >= 0x80) {
                        glyphIndex = glyphIndex - 0x20;
                    }
                    leftX = 12.0f * (f32)column;
                    vertices[0].position[0] = leftX;
                    vertices[0].position[1] = topY;
                    rightX = 11.0f + leftX;
                    vertices[1].position[0] = rightX;
                    vertices[1].position[1] = topY;
                    vertices[2].position[0] = leftX;
                    vertices[2].position[1] = bottomY;
                    vertices[3].position[0] = rightX;
                    vertices[3].position[1] = bottomY;
                    tileColumn = operandOrderRemainder((s32)glyphIndex, 16);
                    leftU = 0.0625f * (f32)tileColumn;
                    textureCoordinates[0] = leftU;
                    topV = 0.0625f * (f32)(s32)((u32)glyphIndex >> 4);
                    textureCoordinates[1] = topV;
                    textureCoordinates[2] = 0.046875f + leftU;
                    textureCoordinates[3] = topV;
                    textureCoordinates[4] = leftU;
                    textureCoordinates[5] = 0.046875f + topV;
                    textureCoordinates[6] = 0.046875f + leftU;
                    textureCoordinates[7] = 0.046875f + topV;
                    vertexIndex = 0;
                    while (vertexIndex < 4) {
                        DebugGlyphVertex *vertex;
                        f32 *texcoord;
                        texcoord = &textureCoordinates[vertexIndex * 2];
                        vertex = &vertices[vertexIndex];
                        vertex->texcoord[0] = texcoord[0];
                        vertex->texcoord[1] = texcoord[1];
                        vertexIndex += 1;
                    }
                    D_00887310[0](4, vertices, 4);
                }
            }
            row++;
        }
        sdkDbprtDrawQueuedText();
        sdkDbprtDrawOverlay();
        renderer->setState(14, (void *)savedFog);
        func_003e8110((u32)iGpffffb9e0);
    }
}
#pragma pop

/* Draws queued colored text at screen or projected camera depth. The character advance is copied
 * first so its multiply and add stay separate. */
// FUN_0044FA90
void sdkDbprtDrawQueuedText(void) {
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    extern f32 sdkDbprtProjectDepth(f32);
    HDbText3D *node;
    s32 characterIndex;
    f32 reciprocalDepth;
    f32 projectedDepth;
    f32 textureCoordinates[8];
    typedef struct QueueGlyphVertex {
        f32 position[3];
        f32 cameraZ;
        f32 textureCoordinates[2];
        f32 reciprocal;
        f32 pad1;
        f32 color[4];
        f32 normal[3];
        f32 pad2;
    } QueueGlyphVertex;
    QueueGlyphVertex vertices[4];
    f32 nearDepth;
    reciprocalDepth = 1.0f / ((RwCamera *)iGpffffb9e0)->nearPlane;
    node = iGpffffb9dc;
    D_00887300[0](1, iGpffffb9e8);
    while (1) {
        if (node == NULL) break;
        if (node->cameraDepth != 0.0f) {
            projectedDepth = sdkDbprtProjectDepth(node->cameraDepth);
        }
        characterIndex = 0;
        while (characterIndex < 0x100) {
            u8 glyph;
            glyph = *(u8 *)&((HDbText3D *)node)->text[characterIndex];
            if (glyph == 0) {
                break;
            }
            if (glyph != 0x20) {
                if (node->cameraDepth == 0.0f) {
                    f32 leftX;
                    f32 advance;
                    f32 horizontalOffset;
                    f32 topY;
                    f32 rightX;
                    f32 bottomY;
                    s32 atlasColumn;
                    f32 leftU;
                    f32 topV;
                    s32 vertexIndex;
                    glyph = glyph - 0x20;
                    if ((s32)glyph >= 0x80) {
                        glyph = glyph - 0x20;
                    }
                    advance = 12.0f * (f32)characterIndex;
                    horizontalOffset = advance;
                    leftX = node->x + horizontalOffset;
                    vertices[0].position[0] = leftX;
                    topY = node->y;
                    vertices[0].position[1] = topY;
                    rightX = 11.0f + leftX;
                    vertices[1].position[0] = rightX;
                    vertices[1].position[1] = topY;
                    vertices[2].position[0] = leftX;
                    bottomY = 11.0f + topY;
                    vertices[2].position[1] = bottomY;
                    vertices[3].position[0] = rightX;
                    vertices[3].position[1] = bottomY;
                    atlasColumn = operandOrderRemainder(((s32)(glyph & 0xFF)), 16);
                    leftU = 0.0625f * (f32)atlasColumn;
                    textureCoordinates[0] = leftU;
                    topV = 0.0625f * (f32)(s32)((u32)glyph >> 4);
                    textureCoordinates[1] = topV;
                    textureCoordinates[2] = 0.046875f + leftU;
                    textureCoordinates[3] = topV;
                    textureCoordinates[4] = leftU;
                    textureCoordinates[5] = 0.046875f + topV;
                    textureCoordinates[6] = 0.046875f + leftU;
                    textureCoordinates[7] = 0.046875f + topV;
                    vertexIndex = 0;
                    nearDepth = D_008872F8[0];
                    while (vertexIndex < 4) {
                        QueueGlyphVertex *vertex;
                        f32 *texcoord;
                        vertex = &vertices[vertexIndex];
                        vertex->position[2] = nearDepth - node->depthOffset;
                        vertex->color[0] = (f32)(u32)node->color[0];
                        vertex->color[1] = (f32)(u32)node->color[1];
                        vertex->color[2] = (f32)(u32)node->color[2];
                        vertex->color[3] = (f32)(u32)node->color[3];
                        vertex->reciprocal = reciprocalDepth;
                        texcoord = &textureCoordinates[vertexIndex * 2];
                        vertex->textureCoordinates[0] = texcoord[0];
                        vertex->textureCoordinates[1] = texcoord[1];
                        vertexIndex += 1;
                    }
                    D_00887310[0](4, vertices, 4);
                } else {
                    f32 leftX;
                    f32 advance;
                    f32 horizontalOffset;
                    f32 topY;
                    f32 rightX;
                    f32 bottomY;
                    s32 atlasColumn;
                    f32 leftU;
                    f32 topV;
                    s32 vertexIndex;
                    glyph = glyph - 0x20;
                    if ((s32)glyph >= 0x80) {
                        glyph = glyph - 0x20;
                    }
                    advance = 12.0f * (f32)characterIndex;
                    horizontalOffset = advance;
                    leftX = node->x + horizontalOffset;
                    vertices[0].position[0] = leftX;
                    topY = node->y;
                    vertices[0].position[1] = topY;
                    rightX = 11.0f + leftX;
                    vertices[1].position[0] = rightX;
                    vertices[1].position[1] = topY;
                    vertices[2].position[0] = leftX;
                    bottomY = 11.0f + topY;
                    vertices[2].position[1] = bottomY;
                    vertices[3].position[0] = rightX;
                    vertices[3].position[1] = bottomY;
                    atlasColumn = operandOrderRemainder(((s32)(glyph & 0xFF)), 16);
                    leftU = 0.0625f * (f32)atlasColumn;
                    textureCoordinates[0] = leftU;
                    topV = 0.0625f * (f32)(s32)((u32)glyph >> 4);
                    textureCoordinates[1] = topV;
                    textureCoordinates[2] = 0.046875f + leftU;
                    textureCoordinates[3] = topV;
                    textureCoordinates[4] = leftU;
                    textureCoordinates[5] = 0.046875f + topV;
                    textureCoordinates[6] = 0.046875f + leftU;
                    textureCoordinates[7] = 0.046875f + topV;
                    vertexIndex = 0;
                    while (vertexIndex < 4) {
                        QueueGlyphVertex *vertex;
                        f32 *texcoord;
                        vertex = &vertices[vertexIndex];
                        vertex->position[2] = projectedDepth;
                        vertex->color[0] = (f32)(u32)node->color[0];
                        vertex->color[1] = (f32)(u32)node->color[1];
                        vertex->color[2] = (f32)(u32)node->color[2];
                        vertex->color[3] = (f32)(u32)node->color[3];
                        vertex->reciprocal = reciprocalDepth;
                        texcoord = &textureCoordinates[vertexIndex * 2];
                        vertex->textureCoordinates[0] = texcoord[0];
                        vertex->textureCoordinates[1] = texcoord[1];
                        vertexIndex += 1;
                    }
                    D_00887310[0](4, vertices, 4);
                }
            }
            characterIndex += 1;
        }
        node = node->next;
    }
}
/* Format a printf-style string and write it into the debug text grid at the given column and row,
 * starting a new line on each newline. */
// FUN_00450050
void H_Dbprt_FmtAt(s64 position, const char* format, ...) {
    va_list args;
    s8 text[0x100];
    f32 originY;
    s32 characterIndex;
    s32 column;
    s32 row;
    s32 originColumn;
    s8 character;
    s32 characterAddress;
    u8 *characterPointer;

    originY = ((PackedVec2f *)&position)->xy.y;
    va_start(args, format);
    vsprintf(text, format, args);
    column = (s32)(((PackedVec2f *)&position)->xy.x);
    row = (s32)originY;
    characterIndex = 0;
    originColumn = column;
    while (characterIndex < 0x100) {
        if ((((PackedVec2f *)&position)->xy.x < 53.0f) && (originY < 40.0f) && (column < 0x35) && (row < 0x28)) {
            characterAddress = (s32)((u8 *)text + characterIndex);
            characterPointer = (u8 *)characterAddress;
            character = *(s8 *)characterPointer;
            if (character != 0) {
                if (character == 0xA) {
                    column = originColumn;
                    row += 1;
                } else {
                    if ((row == 0x27) && (column >= 0x35)) {
                        func_00440b68((char *)&iGpffffac30 + 0x10, character);
                    } else {
                        D_008BF720[row][column] = character;
                    }
                    column += 1;
                }
                characterIndex += 1;
                continue;
            }
        }
        break;
    }
}

/* Formats colored screen-space text into a newly allocated queue entry. */
/* The RGBA aggregate alias copies the packed color bits in one word; it is not a numeric conversion. */
// FUN_004501F0
void sdkDbprtQueueColoredText(s64 position, s32 color, s32 formatAddress, ...) {
    va_list args;
    u8 *entry;
    HDbText3D *tail;
    HDbText3D *next;
    f32 y;

    y = ((PackedVec2f *)&position)->xy.y;
    chkmemSetLock(1);
    chkmemAllocSiteTag(D_00710500, 0x1EA);
    entry = D_008873F4[0](1, 0x118, 0x40000);
    if (entry != NULL) {
        chkmemSetLock(0);
        va_start(args, formatAddress);
        vsprintf(entry + 0x10, (void *)formatAddress, args);
        ((HDbText3D *)entry)->x = ((PackedVec2f *)&position)->xy.x;
        ((HDbText3D *)entry)->y = y;
        ((HDbText3D *)entry)->cameraDepth = 0.0f;
        ((HDbText3D *)entry)->packedColor = *(RGBA8 *)&color;
        ((HDbText3D *)entry)->depthOffset = 0.0f;
        tail = iGpffffb9dc;
        if (tail == NULL) {
            iGpffffb9dc = (HDbText3D *)entry;
            return;
        }
        do {
            next = tail->next;
            if (next == NULL) {
                tail->next = (HDbText3D *)entry;
                break;
            }
            tail = next;
        } while (1);
    }
}

/* Formats white screen-space text into a newly allocated queue entry. */
// FUN_00450340
void sdkDbprtQueueText(s64 position, const char *format, ...) {
    va_list args;
    u8 *entry;
    HDbText3D *tail;
    HDbText3D *next;
    f32 y;

    y = ((PackedVec2f *)&position)->xy.y;
    chkmemSetLock(1);
    chkmemAllocSiteTag(D_00710500, 0x20A);
    entry = D_008873F4[0](1, 0x118, 0x40000);
    if (entry != NULL) {
        chkmemSetLock(0);
        va_start(args, format);
        vsprintf(entry + 0x10, format, args);
        ((HDbText3D *)entry)->x = ((PackedVec2f *)&position)->xy.x;
        ((HDbText3D *)entry)->y = y;
        ((HDbText3D *)entry)->cameraDepth = 0.0f;
        ((HDbText3D *)entry)->depthOffset = 0.0f;
        ((HDbText3D *)entry)->color[3] = 0xFF;
        ((HDbText3D *)entry)->color[2] = 0xFF;
        ((HDbText3D *)entry)->color[1] = 0xFF;
        ((HDbText3D *)entry)->color[0] = 0xFF;
        tail = iGpffffb9dc;
        if (tail == NULL) {
            iGpffffb9dc = (HDbText3D *)entry;
            return;
        }
        do {
            next = tail->next;
            if (next == NULL) {
                tail->next = (HDbText3D *)entry;
                break;
            }
            tail = next;
        } while (1);
    }
}
