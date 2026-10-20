#include "operand_order_internal.h"
/* Original translation unit sdkSpr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "type.h"
#include "member_access.h"
#include "rw_camera_internal.h"
#include "h_cdvd.h"
#include "h_cdvd_request_internal.h"

void chkmemAllocSiteTag(void *file, s32 line);
void strcpy(void *, const char *);
void func_00440b68(char *, const char *, s32);
void memcpy(void *, void *, s32);
u8 *H_Cdvd_LookupRequest(void *pathAddress, u32 *slot);
u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
void func_003ec330(void *ptr);
s32 filerEnqueueRequest(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 filerTakeCompletedRequest(s32 request, s32 *completed, s32 resultValue);
void sdkSpriteDraw(u8 *sample, s32 setStates);

/* Sprite dispatcher slot at 0x008873EC (absolute, outside gp window). */
extern void (*jtbl_008873EC[])(void *node);
/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern void *(*D_008873F4[])(size_t, size_t, u32);
/* GP-relative list head at gp -0x44E8 (absolute 0x00764C08). */
extern u8 *iGpffffbb18;
/* GP-relative global at gp -0x4FC8 (absolute 0x00764128). */
extern char iGpffffb038;
extern char D_007130C8[];


/* Sprite-renderer types, shared by the guarded sdkSpriteDraw body. */
#include "rw/plcore/barenderstate.h"

typedef struct RwV2d {
    f32 x, y;
} RwV2d;
#include "rw_types_internal.h"
typedef struct RwMatrixTag RwMatrix;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;

/* RwSky2DVertexFields from the PS2 SDK: the renderer consumes four
 * 16-byte lanes per vertex. Camera/fog and normal fields are not used here. */
typedef struct RwSky2DVertexFields {
    RwV3d screen;
    f32 cameraZ;
    f32 u, v, reciprocalZ, fog;
    struct { f32 red, green, blue, alpha; } color;
    RwV3d normal;
    f32 pad2;
} SdkSpriteVertexFields;
typedef union RwSky2DVertexAlignmentOverlay {
    SdkSpriteVertexFields els;
    unsigned __int128 qWords[4];
} SdkSpriteVertexOverlay;
typedef struct RwSky2DVertex {
    SdkSpriteVertexOverlay u;
} SdkSpriteVertex;
typedef char SdkSpriteVertexSizeCheck[sizeof(SdkSpriteVertex) == 0x40 ? 1 : -1];

/* The callback slots are members of the SDK's RwGlobals.dOpenDevice.
 * Retain that containing object when taking the address of a live slot. */
typedef struct SdkSpriteDevicePrefix {
    f32 gammaCorrection;
    s32 (*system)(s32, void *, void *, s32);
    f32 zBufferNear, zBufferFar;
    s32 (*setState)(RwRenderState, void *);
    s32 (*getState)(RwRenderState, void *);
    s32 (*renderLine)(void *, s32, s32, s32);
    s32 (*renderTriangle)(void *, s32, s32, s32, s32);
    s32 (*renderPrimitive)(s32, void *, s32);
} SdkSpriteDevicePrefix;
typedef struct SdkSpriteGlobalsPrefix {
    void *camera, *world;
    u16 renderFrame, lightFrame, pad[2];
    SdkSpriteDevicePrefix device;
} SdkSpriteGlobalsPrefix;
extern u32 ourGlobals[4096];

extern s32 kwlnGetCamera(void);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern RwMatrix *func_003e0f80(void);
extern RwMatrix *func_003e0680(RwMatrix *, const RwV3d *, f32, f32, RwOpCombineType);
extern RwV3d *func_003e42e0(RwV3d *, const RwV3d *, s32, const RwMatrix *);
extern s32 func_003e0f40(RwMatrix *);
extern void sdkSpriteTransformPoints(u8 *, u8 *);
extern f32 D_008872F8[];
extern u8 D_007130D8[];
extern f32 fGpffff8084;
extern f32 fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060;
extern f32 fGpffff81b0, fGpffff81b4, fGpffff81b8, fGpffff81bc;
extern f32 fGpffff81c0, fGpffff81c4, fGpffff81c8, fGpffff81cc;

/* The loader allocates and copies 0x80 bytes for every sprite record and
 * owns a fixed 32-entry raster array at +0x104 in its 0x240-byte container. */
typedef struct SdkSpriteRecord {
    u8 pad00[0x14];
    s32 rasterIndex;
    u32 flags;
    u8 pad1C[0x10];
    u32 renderFlags;
    u8 pad30[4];
    union {
        struct { s32 topBorder, bottomBorder, leftBorder, rightBorder; };
        s32 borders[4];
    };
    s32 originX, originY;
    u8 pad4C[8];
    s32 left, top, right, bottom;
    u32 colors[4];
    s16 widthOverride, heightOverride;
    u8 pad78[8];
} SdkSpriteRecord;

typedef struct SdkSpriteSample {
    u32 packAddress;
    u32 recordIndex;
    f32 x, y;
    u8 alphaSubtract, fade;
    u8 pad12[2];
    s16 extendX, extendY;
    f32 angle;
    s16 pivotX, pivotY;
    u16 scaleX, scaleY; /* unsigned Q12; zero means unscaled */
    f32 depth;
    u8 red, green, blue, pad2B;
} SdkSpriteSample;

/* Each eight-byte blob-directory entry carries its payload offset in word 1. */
typedef struct SdkSpriteBlobEntry {
    u32 unk00;
    u32 offset;
} SdkSpriteBlobEntry;

/* The blob metadata is copied verbatim into the pack at +0x218. */
typedef struct SdkSpriteBlobHeader {
    u8 unk00[0x14];
    u16 rasterCount, spriteCount;
    u8 unk18[8];
} SdkSpriteBlobHeader;
typedef char SdkSpriteBlobHeaderSizeCheck[sizeof(SdkSpriteBlobHeader) == 0x20 ? 1 : -1];

typedef struct SdkSpritePack {
    s16 state;
    char name[0x102];
    u32 rasters[32];
    u32 rasterRequests[32];
    u32 recordsAddress;
    u32 directoryAddress;
    u32 blobAddress;
    u32 cursor;
    s16 rasterIndex, recordCount;
    SdkSpriteBlobHeader header;
    u8 *next, *prev;
} SdkSpritePack;
typedef char SdkSpriteBlobEntrySizeCheck[sizeof(SdkSpriteBlobEntry) == 8 ? 1 : -1];
typedef char SdkSpriteRecordSizeCheck[sizeof(SdkSpriteRecord) == 0x80 ? 1 : -1];
typedef char SdkSpriteSampleSizeCheck[sizeof(SdkSpriteSample) == 0x2C ? 1 : -1];
typedef char SdkSpritePackSizeCheck[sizeof(SdkSpritePack) == 0x240 ? 1 : -1];
/* Keep the same address-word view used by the attachment transformer.
 * Measured direct field rewrites originally lost MATCH at several sites. Separate
 * typed aliases and named-field byte strides preserve the retail address lifetimes;
 * only the two indexed/table-record helpers still need MEMBER. */
#define SDK_SPRITE_RECORD(sample) \
    ((u8 *)((u32)((SdkSpriteSample *)(sample))->recordIndex * sizeof(SdkSpriteRecord) + \
            (u32)(u8 *)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress))
/* Same address with the table term first. Selected point/extent sites use
 * this expression for their measured load/add order; C does not sequence
 * the two addition operands. */
/* Measured: retain this table-first address order alongside the typed sample alias. */
#define SDK_SPRITE_RECORD_TABLE_FIRST(sample) \
    ((u8 *)(((SdkSpritePack *)(u8 *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress + \
            ((SdkSpriteSample *)(sample))->recordIndex * sizeof(SdkSpriteRecord)))
/* Resolve the record through an unsigned-word addition boundary.
 * measured: direct sums change Draw codegen; pointer-return byteAddressAdd
 * also changes 159 bytes, while operandOrderAddUnsigned retains MATCH. */
#define SDK_SPRITE_RECORD_VIA_ADD(sample) \
    ((u8 *)operandOrderAddUnsigned((u32)((SdkSpriteSample *)(sample))->recordIndex * sizeof(SdkSpriteRecord), \
                        (u32)(u8 *)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress))

/* Measured: retain the pointer-array decay at the render-state argument. */
#define SDK_SPRITE_RASTERS(sample) \
    ((u8 **)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)(sample))->packAddress)->rasters)

/* Same unsigned extent, optional signed override, and Q12 scale as the
 * public width/height queries below. Each call reads the current payload.
 * Overrides use the named field address plus the record byte stride. */
/* Both extents convert the bounds to u32 before the wrapping subtraction;
 * the optional signed override is then converted to the same width. */
/* measured: the signed border address avoids CSE with the unsigned extent
 * reads and preserves their separate offset-first addu (fnalign 11 -> 7). */
/* Border-array order is top, bottom, left, right. */
/* Read a signed sprite-border extent from the selected record. */
/* measured: direct border reads change sdkSpriteDraw load/float-conversion allocation; both inline extent callers require this boundary. */
static inline f32 sdkSpriteBorder(u8 *output, u32 offset, s32 borderIndex)
{
    return (f32)((SdkSpriteRecord *)((s32)offset + (s32)output))->borders[borderIndex];
}

/* Compute the scaled right extent with the optional border and horizontal pivot. */
static inline f32 sdkSpriteRight(u8 *sample, s32 includeBorder)
{
    SdkSpriteSample *spriteSample = (SdkSpriteSample *)sample;
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = spriteSample->recordIndex * 0x80;
    output = (u8 *)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    value = (u32)((SdkSpriteRecord *)((offset) + ((u32)output)))->right -
            (u32)((SdkSpriteRecord *)((offset) + ((u32)output)))->left;
    overrideBase = (u8 *)&((SdkSpriteRecord *)output)->widthOverride;
    if (((s16 *)(overrideBase + offset))[0] != 0) {
        value = ((s16 *)(overrideBase + offset))[0];
    }
    if (spriteSample->scaleX != 0) {
        value = (value * ((SdkSpriteSample *)sample)->scaleX) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = sdkSpriteBorder(output, offset, 3);
        extent -= (f32)spriteSample->pivotX;
        return border + extent;
    }
    extent -= (f32)spriteSample->pivotX;
    return extent;
}

/* Compute the scaled bottom extent with the optional border and vertical pivot. */
static inline f32 sdkSpriteBottom(u8 *sample, s32 includeBorder)
{
    SdkSpriteSample *spriteSample = (SdkSpriteSample *)sample;
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = spriteSample->recordIndex * 0x80;
    output = (u8 *)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    value = (u32)((SdkSpriteRecord *)((offset) + ((u32)output)))->bottom -
            (u32)((SdkSpriteRecord *)((offset) + ((u32)output)))->top;
    overrideBase = (u8 *)&((SdkSpriteRecord *)output)->heightOverride;
    if (((s16 *)(overrideBase + offset))[0] != 0) {
        value = ((s16 *)(overrideBase + offset))[0];
    }
    if (spriteSample->scaleY != 0) {
        value = (value * ((SdkSpriteSample *)sample)->scaleY) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = sdkSpriteBorder(output, offset, 1);
        extent -= (f32)spriteSample->pivotY;
        return border + extent;
    }
    extent -= (f32)spriteSample->pivotY;
    return extent;
}

/* Keep byte-color arithmetic separate from unsigned-to-float conversion. */
static inline void sdkSpriteVertexSetColor(SdkSpriteVertex *vertex,
                                           u8 red, u8 green, u8 blue, u8 alpha)
{
    vertex->u.els.color.red = (f32)red;
    vertex->u.els.color.green = (f32)green;
    vertex->u.els.color.blue = (f32)blue;
    vertex->u.els.color.alpha = (f32)alpha;
}

/* All four vertices of the quad share this transformed XY payload. */
static inline void sdkSpritePositionQuad(SdkSpriteVertex vertex[4], const RwV2d point[4])
{
    vertex[0].u.els.screen.x = point[0].x;
    vertex[0].u.els.screen.y = point[0].y;
    vertex[1].u.els.screen.x = point[1].x;
    vertex[1].u.els.screen.y = point[1].y;
    vertex[2].u.els.screen.x = point[2].x;
    vertex[2].u.els.screen.y = point[2].y;
    vertex[3].u.els.screen.x = point[3].x;
    vertex[3].u.els.screen.y = point[3].y;
}


/* Advance pack loading through header, raster requests, and sprite-record copies. */
// FUN_0046AB90
void sdkSpriteLoadStep(u8 *pack)
{
    SdkSpritePack *spritePack = (SdkSpritePack *)pack;
    u8 rasterEntry[8];
    u8 spriteEntry[8];
    s32 i;
    s32 complete;
    s16 state;

    state = ((SdkSpritePack *)pack)->state;
    switch (state) {
    case 0:
        func_00440b68(&iGpffffb038, D_007130C8, 0xB3);
        ((SdkSpritePack *)pack)->directoryAddress = (u32)H_Cdvd_AcquireDirectory(((SdkSpritePack *)pack)->name, 0);
        ((SdkSpritePack *)pack)->state = 1;
        break;
    case 1:
        if (((SdkSpritePack *)pack)->directoryAddress != 0) {
            if (H_Cdvd_IsFileLoaded((struct HCdvd *)((SdkSpritePack *)pack)->directoryAddress) != 1) {
                break;
            }
            ((SdkSpritePack *)pack)->blobAddress =
                (u32)((HCdvdRequest *)*(u8 **)&spritePack->directoryAddress)->data;
        }
        memcpy(&((SdkSpritePack *)pack)->header, (void *)((SdkSpritePack *)pack)->blobAddress, 0x20);
        ((SdkSpritePack *)pack)->cursor += 0x20;
        ((SdkSpritePack *)pack)->state = 2;
        ((SdkSpritePack *)pack)->rasterIndex = 0;
        if (((SdkSpritePack *)pack)->header.rasterCount == 0) {
            ((SdkSpritePack *)pack)->state = 4;
            break;
        }
    case 2:
        do {
            memcpy(rasterEntry, (void *)(((SdkSpritePack *)pack)->blobAddress +
                                          ((SdkSpritePack *)pack)->cursor), 8);
            spritePack->cursor += 8;
            ((SdkSpritePack *)pack)->rasterRequests[((SdkSpritePack *)pack)->rasterIndex] =
                filerEnqueueRequest(9, 0, 0, 0, 0,
                              spritePack->blobAddress + ((SdkSpriteBlobEntry *)rasterEntry)->offset,
                              0, 0, 0, 0);
            ((SdkSpritePack *)pack)->rasters[spritePack->rasterIndex] = 0;
            spritePack->rasterIndex += 1;
        } while (((SdkSpritePack *)pack)->header.rasterCount !=
                 spritePack->rasterIndex);
        ((SdkSpritePack *)pack)->state = 3;
        break;
    case 3:
        complete = 1;
        for (i = 0; i < ((SdkSpritePack *)pack)->header.rasterCount; i++) {
            u8 *entry = pack + (i << 2);
            u32 *slot = &((SdkSpritePack *)entry)->rasters[0];

            if (*slot == 0) {
                *slot = filerTakeCompletedRequest(((SdkSpritePack *)entry)->rasterRequests[0],
                                      &complete, 0);
                if (complete == 0) {
                    *slot = 0;
                    break;
                }
            }
        }
        if (complete == 0) {
            break;
        }
        ((SdkSpritePack *)pack)->state = 4;
    case 4:
        chkmemAllocSiteTag(D_007130C8, 0xFD);
        ((SdkSpritePack *)pack)->recordsAddress =
            (u32)D_008873F4[0](((SdkSpritePack *)pack)->header.spriteCount, 0x80, 0x40000);
        for (i = 0; i < spritePack->header.spriteCount; i++) {
            memcpy(spriteEntry, (void *)(((SdkSpritePack *)pack)->blobAddress +
                                            ((SdkSpritePack *)pack)->cursor), 8);
            spritePack->cursor += 8;
            memcpy((u8 *)(spritePack->recordsAddress + (i << 7)),
                          (void *)(spritePack->blobAddress + ((SdkSpriteBlobEntry *)spriteEntry)->offset),
                          0x80);
        }
        if (((SdkSpritePack *)pack)->directoryAddress != 0) {
            H_Cdvd_Destroy((struct HCdvd *)((SdkSpritePack *)pack)->directoryAddress);
        }
        spritePack->directoryAddress = 0;
        ((SdkSpritePack *)pack)->recordCount = spritePack->header.spriteCount;
        ((SdkSpritePack *)pack)->state = 5;
        break;
    case 5:
        break;
    }
}

/* Queue a named sprite pack for asynchronous directory loading. */
// FUN_0046AEA0
u8 *sdkSpriteRequestLoad(const char *name)
{
    SdkSpritePack *tail;
    u8 *node;
    u8 *last;

    chkmemAllocSiteTag(D_007130C8, 0x115);
    node = D_008873F4[0](1, 0x240, 0x40000);
    ((SdkSpritePack *)node)->state = 0;
    strcpy(((SdkSpritePack *)node)->name, name);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
    tail = (SdkSpritePack *)last;
        if (((SdkSpritePack *)last)->next == NULL) {
            tail->next = node;
            ((SdkSpritePack *)node)->prev = last;
        } else {
            last = ((SdkSpritePack *)last)->next;
            goto loop;
        }
    }
    return node;
}

/* Queue an already available sprite blob for raster and record loading. */
// FUN_0046AF60
u8 *sdkSpriteAdoptBlob(u32 blobAddress)
{
    SdkSpritePack *tail;
    u8 *node;
    u8 *last;

    chkmemAllocSiteTag(D_007130C8, 0x12D);
    node = D_008873F4[0](1, 0x240, 0x40000);
    ((SdkSpritePack *)node)->state = 1;
    ((SdkSpritePack *)node)->blobAddress = blobAddress;
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
    tail = (SdkSpritePack *)last;
        if (((SdkSpritePack *)last)->next == NULL) {
            tail->next = node;
            ((SdkSpritePack *)node)->prev = last;
        } else {
            last = ((SdkSpritePack *)last)->next;
            goto loop;
        }
    }
    return node;
}

/* Resolve a registered blob by name and append its sprite-pack loader. */
// FUN_0046B000
u8 *sdkSpriteCreateFromName(const char *name)
{
    SdkSpritePack *tail;
    u8 *node;
    u8 *last;
    u32 out;

    chkmemAllocSiteTag(D_007130C8, 0x146);
    node = D_008873F4[0](1, 0x240, 0x40000);
    ((SdkSpritePack *)node)->state = 1;
    strcpy(((SdkSpritePack *)node)->name, name);
    ((SdkSpritePack *)node)->blobAddress = (u32)H_Cdvd_LookupRequest((void *)name, &out);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
    tail = (SdkSpritePack *)last;
        if (((SdkSpritePack *)last)->next == NULL) {
            tail->next = node;
            ((SdkSpritePack *)node)->prev = last;
        } else {
            last = ((SdkSpritePack *)last)->next;
            goto loop;
        }
    }
    return node;
}

/* Unlink a pack and release its rasters, pending directory, and copied records. */
// FUN_0046B0D0
void sdkSpriteRelease(u8 *node)
{
    SdkSpritePack *spritePack = (SdkSpritePack *)node;
    s32 i;

    if (((SdkSpritePack *)node)->prev == NULL) {
        if (((SdkSpritePack *)node)->next == NULL) {
            iGpffffbb18 = NULL;
        } else {
            iGpffffbb18 = ((SdkSpritePack *)node)->next;
            ((SdkSpritePack *)iGpffffbb18)->prev = NULL;
            ((SdkSpritePack *)spritePack->next)->prev = NULL;
        }
    } else {
        ((SdkSpritePack *)((SdkSpritePack *)node)->prev)->next = ((SdkSpritePack *)node)->next;
        if (((SdkSpritePack *)node)->next != NULL) {
            ((SdkSpritePack *)((SdkSpritePack *)node)->next)->prev = spritePack->prev;
        }
    }
    i = 0;
    while (i < 0x20) {
        if (((SdkSpritePack *)node)->rasters[i] != 0) {
            func_003ec330((void *)((SdkSpritePack *)node)->rasters[i]);
            ((SdkSpritePack *)node)->rasters[i] = 0;
        }
        i++;
    }
    if ((u8 *)((SdkSpritePack *)node)->directoryAddress != NULL) {
        H_Cdvd_Destroy((struct HCdvd *)((SdkSpritePack *)node)->directoryAddress);
        * (u8 **)&spritePack->directoryAddress = NULL;
    }
    if (((SdkSpritePack *)node)->recordsAddress != 0) {
        jtbl_008873EC[0]((void *)((SdkSpritePack *)node)->recordsAddress);
        spritePack->recordsAddress = 0;
    }
    jtbl_008873EC[0](node);
}

/* Ported from P3FES h_maestro.c func_001126b0 (blob+index scale variant).
   Donor struct fields map onto P4 offsets: output at 0x204, overrideX at 0x74,
   right/left at 0x5c/0x54. The measured plain sum retains the retail address
   operands here; only Draw's sensitive sites use operandOrderAddUnsigned. */
// FUN_0046B1F0
f32 sdkSpriteEntryWidth(u8 *blob, u32 index)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;

    offset = index * 0x80;
    output = (u8 *)((SdkSpritePack *)blob)->recordsAddress;
    value = ((SdkSpriteRecord *)((offset) + ((u32)output)))->right -
            ((SdkSpriteRecord *)((offset) + ((u32)output)))->left;
    overrideBase = (u8 *)&((SdkSpriteRecord *)output)->widthOverride;
    if (((s16 *)(overrideBase + offset))[0] != 0)
    {
        value = ((s16 *)(overrideBase + offset))[0];
    }
    return (f32)value;
}
/* Return the width with optional signed override and unsigned Q12 scaling. */
// FUN_0046B260
f32 sdkSpriteScaledWidth(u8 *sprite)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = sprite;

    offset = ((SdkSpriteSample *)sample)->recordIndex * 0x80;
    output = (u8 *)((SdkSpritePack *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    value = ((SdkSpriteRecord *)((offset) + ((u32)output)))->right -
            ((SdkSpriteRecord *)((offset) + ((u32)output)))->left;
    overrideBase = (u8 *)&((SdkSpriteRecord *)output)->widthOverride;
    if (((s16 *)(overrideBase + offset))[0] != 0)
    {
        value = ((s16 *)(overrideBase + offset))[0];
    }
    if (((SdkSpriteSample *)sample)->scaleX != 0)
    {
        value = (s32)(((u32)value * ((SdkSpriteSample *)sample)->scaleX) >> 12);
    }
    return (f32)value;
}
/* Return the height with optional signed override and unsigned Q12 scaling. */
// FUN_0046B2F0
f32 sdkSpriteScaledHeight(u8 *sprite)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = (u8 *)sprite;

    offset = ((SdkSpriteSample *)sample)->recordIndex * 0x80;
    output = (u8 *)((SdkSpritePack *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    value = ((SdkSpriteRecord *)((offset) + ((u32)output)))->bottom -
            ((SdkSpriteRecord *)((offset) + ((u32)output)))->top;
    overrideBase = (u8 *)&((SdkSpriteRecord *)output)->heightOverride;
    if (((s16 *)(overrideBase + offset))[0] != 0)
    {
        value = ((s16 *)(overrideBase + offset))[0];
    }
    if (((SdkSpriteSample *)sample)->scaleY != 0)
    {
        value = (s32)(((u32)value * ((SdkSpriteSample *)sample)->scaleY) >> 12);
    }
    return (f32)value;
}
#pragma push
/* measured: without opt_loop_invariants the loop constants are rematerialised
 * in the vertex loop (617 fnalign edits). */
/* measured: baseline removal differs in 4977 bytes; reuse named sprite sample alias; reread sample through original parameter also differ. */
#pragma opt_loop_invariants on
/* Measured: access-site, local, array, and typed-parameter forms lose Draw MATCH. */
/* Resolve a sprite record after reading the sample index before its pack table. */
static inline u8 *sdkSpriteIndexedRecord(u8 *sample)
{
    u32 offset = MEMBER(u32, sample, SdkSpriteSample, recordIndex) * sizeof(SdkSpriteRecord);
    u32 base = ((SdkSpritePack *)(u8 *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    return (u8 *)operandOrderAddUnsigned(offset, base);
}

/* Measured: access-site, local, array, and typed-parameter forms lose Draw MATCH. */
/* Resolve a sprite record after reading the pack table before its sample index. */
static inline u8 *sdkSpriteTableRecord(u8 *sample)
{
    u32 base = ((SdkSpritePack *)(u8 *)((SdkSpriteSample *)sample)->packAddress)->recordsAddress;
    u32 offset = MEMBER(u32, sample, SdkSpriteSample, recordIndex) * sizeof(SdkSpriteRecord);
    return (u8 *)operandOrderAddUnsigned(offset, base);
}

/* Sprite renderer. The raster-less paths read the uv[] and source[].z slots
 * retail leaves unwritten (commented at each site). Each colour arm forms one
 * record pointer that the flags test reuses; the redundant alpha mask
 * reproduces retail's second andi before the fade load. */
// FUN_0046B380
void sdkSpriteDraw(u8 *sample, s32 setStates)
{
    SdkSpriteSample *spriteSample = (SdkSpriteSample *)sample;
    RwV2d verticalLeft;
    RwV2d horizontalTop;
    RwV2d verticalRight;
    RwV2d horizontalBottom;
    SdkSpriteVertex vertices[4];
    RwV3d source[4];
    RwV3d transformed[4];
    RwV2d uv[4];
    RwV2d points[4];
    RwV2d savedPoints[4];
    s32 copyIndex;
    s32 rasterIndex;
    u8 *raster;
    f32 reciprocalZ;
    f32 angle;
    s32 (**states)(RwRenderState, void *);
    s32 (**render)(s32, void *, s32);

    reciprocalZ = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    if (setStates != 0) {
        s32 (**initialStates)(RwRenderState, void *) =
            &((SdkSpriteGlobalsPrefix *)ourGlobals)->device.setState;

        initialStates[0](6, (void *)1);
        initialStates[0](7, (void *)2);
        initialStates[0](8, (void *)1);
        initialStates[0](9, (void *)2);
        initialStates[0](0xC, (void *)1);
        initialStates[0](0xB, (void *)6);
        initialStates[0](0xA, (void *)5);
        initialStates[0](2, (void *)4);
        initialStates[0](0xE, (void *)0);
    }
    rasterIndex = ((SdkSpriteRecord *)sdkSpriteIndexedRecord(sample))->rasterIndex;
    raster = ((u8 **)(u32)((SdkSpritePack *)(u8 *)((SdkSpriteSample *)(sample))->packAddress)->rasters)[rasterIndex]; /* measured: preserve the outer u32 address cast. */
    if (raster != NULL) {
        s32 width = ((RwRaster *)raster)->width;
        s32 height = ((RwRaster *)raster)->height;

        uv[0].x = (f32)((SdkSpriteRecord *)SDK_SPRITE_RECORD(sample))->left;
        uv[0].x /= (f32)width;
        uv[0].y = (f32)((SdkSpriteRecord *)SDK_SPRITE_RECORD(sample))->top;
        uv[0].y /= (f32)height;
        uv[3].x = (f32)(((SdkSpriteRecord *)SDK_SPRITE_RECORD(sample))->right - 1);
        uv[3].x /= (f32)width;
        uv[3].y = (f32)(((SdkSpriteRecord *)SDK_SPRITE_RECORD(sample))->bottom - 1);
        uv[3].y /= (f32)height;
        uv[1].x = uv[3].x;
        uv[2].x = uv[0].x;
        uv[1].y = uv[0].y;
        uv[2].y = uv[3].y;
    }
    if (setStates != 0) {
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->renderFlags & 1) != 0) {
            RpSkyRenderStateSet(2, (void *)0x48);
            RpSkyRenderStateSet(3, (void *)0x71801);
        }
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->renderFlags & 2) != 0) {
            RpSkyRenderStateSet(2, (void *)0x42);
            RpSkyRenderStateSet(3, (void *)0x71801);
        }
    }
    /* With a null initial raster, retail reaches these flips and the later
     * scalar vertex copies without writing uv[] (sp+0xA0..0xBC). An SDK
     * packet lane that the renderer may omit does not define these local
     * float reads. Retain the assembly guard until the input contract is
     * recovered; this is not a defined C implementation of that path. */
    if ((((u32 *)((u8 *)&((SdkSpriteRecord *)((SdkSpritePack *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress)->flags + spriteSample->recordIndex * sizeof(SdkSpriteRecord)))[0] & 2) != 0) {
        verticalLeft = uv[0];
        uv[0] = uv[2];
        uv[2] = verticalLeft;
        verticalRight = uv[1];
        uv[1] = uv[3];
        uv[3] = verticalRight;
    }
    if ((((u32 *)((u8 *)&((SdkSpriteRecord *)((SdkSpritePack *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress)->flags + spriteSample->recordIndex * sizeof(SdkSpriteRecord)))[0] & 1) != 0) {
        horizontalTop = uv[0];
        uv[0] = uv[1];
        uv[1] = horizontalTop;
        horizontalBottom = uv[2];
        uv[2] = uv[3];
        uv[3] = horizontalBottom;
    }

    source[0].x = (f32)-((SdkSpriteSample *)sample)->pivotX;
    source[0].y = (f32)-((SdkSpriteSample *)sample)->pivotY;
    source[3].x = sdkSpriteRight(sample, 0);
    source[3].y = sdkSpriteBottom(sample, 0);
    source[1].x = source[3].x;
    source[1].y = source[0].y;
    source[2].x = source[0].x;
    source[2].y = source[3].y;
    /* Retail leaves source[].z (sp+0xF8, 0x104, 0x110, 0x11C) unwritten.
     * Both VectorMultPoints and the installed vectorASMMultPoints provider
     * read Z into their XYZ arithmetic. A unit-Z rotation axis and unused
     * output Z do not establish an initialized input for these calls. */
    angle = ((SdkSpriteSample *)sample)->angle;
    if (angle != 0.0f) {
        f32 x, x2, polynomial, quadraticProduct, correction;
        f32 oneMinusCosine, sine;
        s32 wrapped;
        RwMatrix *matrix;
        RwMatrix *rotation;

        do {
            s32 notAboveUpper;

            wrapped = 0;
            notAboveUpper = !(angle > 180.0f);
            if (!notAboveUpper) {
                angle -= 360.0f;
                wrapped = 1;
            } else if (angle < -180.0f) {
                angle += 360.0f;
                wrapped = 1;
            }
        } while (wrapped != 0);
        x = (fGpffff8084 * angle) / 180.0f;
        x2 = x * x;
        matrix = func_003e0f80();
        polynomial = fGpffff81b0 * x2 + fGpffff81b4;
        polynomial = x2 * polynomial + fGpffff81b8;
        polynomial = x2 * polynomial + fGpffff81bc;
        polynomial = x2 * polynomial + fGpffff81c0;
        polynomial = x2 * polynomial + fGpffff81c4;
        quadraticProduct = x2 * polynomial;
        correction = 0.5f * x2 - x2 * quadraticProduct;
        oneMinusCosine = 1.0f - (1.0f - correction);
        polynomial = fGpffff81c8 * x2 + fGpffff8054;
        polynomial = x2 * polynomial + fGpffff8058;
        polynomial = x2 * polynomial + fGpffff805c;
        polynomial = x2 * polynomial + fGpffff8060;
        polynomial = x2 * polynomial + fGpffff81cc;
        {
            f32 cubic = x2 * x;
            sine = x + cubic * polynomial;
        }
        rotation = func_003e0680(matrix, (const RwV3d *)D_007130D8,
                               oneMinusCosine, sine, rwCOMBINEREPLACE);
        func_003e42e0(transformed, source, 4, rotation);
        func_003e0f40(rotation);
        for (copyIndex = 0; copyIndex < 4; copyIndex++) {
            source[copyIndex] = transformed[copyIndex];
        }
    }
    {
        s32 pointIndex;
        for (pointIndex = 0; pointIndex < 4; pointIndex++) {
            points[pointIndex].x = ((SdkSpriteSample *)sample)->x +
                ((f32)spriteSample->pivotX + source[pointIndex].x) +
                (f32)((SdkSpriteRecord *)SDK_SPRITE_RECORD_TABLE_FIRST(sample))->originX;
            {
                f32 subtotal = ((SdkSpriteSample *)sample)->y +
                    ((f32)spriteSample->pivotY + source[pointIndex].y);
                subtotal += (f32)((SdkSpriteRecord *)SDK_SPRITE_RECORD_TABLE_FIRST(sample))->originY;
                points[pointIndex].y = subtotal;
            }
        }
    }
    {
        s32 vertexIndex;
        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
            SdkSpriteVertex *vertex = &vertices[vertexIndex];
            RwRGBA color;
            u8 *record;

            vertex->u.els.screen.z = D_008872F8[0] - ((SdkSpriteSample *)sample)->depth;
            vertex->u.els.reciprocalZ = reciprocalZ;
            vertex->u.els.u = uv[vertexIndex].x;
            vertex->u.els.v = uv[vertexIndex].y;
            if (vertexIndex == 2) {
                u32 packed;

                record = SDK_SPRITE_RECORD(sample);
                packed = ((SdkSpriteRecord *)record)->colors[3];
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            } else if (vertexIndex == 3) {
                u32 packed;

                record = SDK_SPRITE_RECORD(sample);
                packed = ((SdkSpriteRecord *)record)->colors[2];
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            } else {
                u32 packed;

                record = SDK_SPRITE_RECORD(sample);
                packed = ((SdkSpriteRecord *)record)->colors[vertexIndex];
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            }
            color.red = color.red * ((SdkSpriteSample *)sample)->red / 255;
            color.green = color.green * ((SdkSpriteSample *)sample)->green / 255;
            color.blue = color.blue * ((SdkSpriteSample *)sample)->blue / 255;
            if ((((SdkSpriteRecord *)record)->flags & 8) == 0) {
                if (color.red > 128) color.red = 255;
                else color.red = color.red * 255 / 128;
                if (color.green > 128) color.green = 255;
                else color.green = color.green * 255 / 128;
                if (color.blue > 128) color.blue = 255;
                else color.blue = color.blue * 255 / 128;
                if (color.alpha > 128) color.alpha = 255;
                else color.alpha = color.alpha * 255 / 128;
            }
            /* Retail masks alpha again at the join (andi t2,t2,0xff) before the fade:
             * the narrowed operand is evaluated ahead of the fade load. */
            color.alpha = (u8)(color.alpha & 0xFF) * (255 - ((SdkSpriteSample *)sample)->fade) / 255;
            if (((SdkSpriteSample *)sample)->alphaSubtract < color.alpha) {
                color.alpha -= ((SdkSpriteSample *)sample)->alphaSubtract;
            } else {
                color.alpha = 0;
            }
            sdkSpriteVertexSetColor(&vertices[vertexIndex], color.red, color.green,
                                   color.blue, color.alpha);
            vertices[vertexIndex].u.els.screen.x = points[vertexIndex].x;
            vertices[vertexIndex].u.els.screen.y = points[vertexIndex].y;
        }
    }
    if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
        states = &((SdkSpriteGlobalsPrefix *)ourGlobals)->device.setState;
        states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
    } else {
        states = &((SdkSpriteGlobalsPrefix *)ourGlobals)->device.setState;
        states[0](1, NULL);
    }
    render = &((SdkSpriteGlobalsPrefix *)ourGlobals)->device.renderPrimitive;
    render[0](4, vertices, 4);
    {
        s32 saveIndex;
        for (saveIndex = 0; saveIndex < 4; saveIndex++) {
            savedPoints[saveIndex] = points[saveIndex];
        }
    }

    if (((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->topBorder != 0) {
        points[0].x = (f32)-spriteSample->pivotX;
        points[0].y = (f32)-(spriteSample->pivotY + ((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->topBorder);
        points[1].x = sdkSpriteRight(sample, 0);
        points[1].y = (f32)-(spriteSample->pivotY + ((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->topBorder);
        points[2].x = (f32)-spriteSample->pivotX;
        points[2].y = (f32)-spriteSample->pivotY;
        points[3].x = sdkSpriteRight(sample, 0);
        points[3].y = (f32)-spriteSample->pivotY;
        sdkSpriteTransformPoints(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[0].x; vertices[0].u.els.v = uv[0].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[0].x; vertices[2].u.els.v = uv[0].y;
        vertices[3].u.els.u = uv[1].x; vertices[3].u.els.v = uv[1].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->bottomBorder != 0) {
        points[0].x = (f32)-spriteSample->pivotX;
        points[0].y = sdkSpriteBottom(sample, 0);
        points[1].x = sdkSpriteRight(sample, 0);
        points[1].y = sdkSpriteBottom(sample, 0);
        points[2].x = (f32)-spriteSample->pivotX;
        points[2].y = sdkSpriteBottom(sample, 1);
        points[3].x = sdkSpriteRight(sample, 0);
        points[3].y = sdkSpriteBottom(sample, 1);
        sdkSpriteTransformPoints(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[2].x; vertices[0].u.els.v = uv[2].y;
        vertices[1].u.els.u = uv[3].x; vertices[1].u.els.v = uv[3].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (((s32 *)((u8 *)&((SdkSpriteRecord *)((SdkSpritePack *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress)->leftBorder + ((SdkSpriteSample *)sample)->recordIndex * sizeof(SdkSpriteRecord)))[0] != 0) {
        points[0].x = (f32)-(((SdkSpriteSample *)sample)->pivotX + ((s32 *)((u8 *)&((SdkSpriteRecord *)((SdkSpritePack *)((SdkSpriteSample *)(sample))->packAddress)->recordsAddress)->leftBorder + ((SdkSpriteSample *)sample)->recordIndex * sizeof(SdkSpriteRecord)))[0]);
        points[0].y = (f32)-((SdkSpriteSample *)sample)->pivotY;
        points[1].x = (f32)-((SdkSpriteSample *)sample)->pivotX;
        points[1].y = (f32)-((SdkSpriteSample *)sample)->pivotY;
        points[2].x = (f32)-(((SdkSpriteSample *)sample)->pivotX + ((SdkSpriteRecord *)SDK_SPRITE_RECORD_VIA_ADD(sample))->leftBorder);
        points[2].y = sdkSpriteBottom(sample, 0);
        points[3].x = (f32)-spriteSample->pivotX;
        points[3].y = sdkSpriteBottom(sample, 0);
        sdkSpriteTransformPoints(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[0].x; vertices[0].u.els.v = uv[0].y;
        vertices[1].u.els.u = uv[0].x; vertices[1].u.els.v = uv[0].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[2].x; vertices[3].u.els.v = uv[2].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (((SdkSpriteRecord *)sdkSpriteIndexedRecord(sample))->rightBorder != 0) {
        points[0].x = sdkSpriteRight(sample, 0);
        points[0].y = (f32)-spriteSample->pivotY;
        points[1].x = sdkSpriteRight(sample, 1);
        points[1].y = (f32)-spriteSample->pivotY;
        points[2].x = sdkSpriteRight(sample, 0);
        points[2].y = sdkSpriteBottom(sample, 0);
        points[3].x = sdkSpriteRight(sample, 1);
        points[3].y = sdkSpriteBottom(sample, 0);
        sdkSpriteTransformPoints(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[1].x; vertices[0].u.els.v = uv[1].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[3].x; vertices[2].u.els.v = uv[3].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    {
        s32 restoreIndex;
        for (restoreIndex = 0; restoreIndex < 4; restoreIndex++) {
            points[restoreIndex] = savedPoints[restoreIndex];
        }
    }
    if (((SdkSpriteSample *)sample)->extendY != 0) {
        vertices[0].u.els.screen.x = points[2].x;
        vertices[0].u.els.screen.y = points[2].y;
        vertices[1].u.els.screen.x = points[3].x;
        vertices[1].u.els.screen.y = points[3].y;
        vertices[2].u.els.screen.x = points[2].x;
        vertices[2].u.els.screen.y = points[2].y + (f32)((SdkSpriteSample *)sample)->extendY;
        vertices[3].u.els.screen.x = points[3].x;
        vertices[3].u.els.screen.y = points[3].y + (f32)((SdkSpriteSample *)sample)->extendY;
        vertices[0].u.els.u = uv[2].x; vertices[0].u.els.v = uv[2].y;
        vertices[1].u.els.u = uv[3].x; vertices[1].u.els.v = uv[3].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    } else if (((SdkSpriteSample *)sample)->extendX != 0) {
        vertices[0].u.els.screen.x = points[1].x;
        vertices[0].u.els.screen.y = points[1].y;
        vertices[1].u.els.screen.x = (f32)((s32)points[1].x + ((SdkSpriteSample *)sample)->extendX);
        vertices[1].u.els.screen.y = points[1].y;
        vertices[2].u.els.screen.x = points[3].x;
        vertices[2].u.els.screen.y = points[3].y;
        vertices[3].u.els.screen.x = (f32)((s32)points[3].x + ((SdkSpriteSample *)sample)->extendX);
        vertices[3].u.els.screen.y = points[3].y;
        vertices[0].u.els.u = uv[1].x; vertices[0].u.els.v = uv[1].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[3].x; vertices[2].u.els.v = uv[3].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((((SdkSpriteRecord *)sdkSpriteTableRecord(sample))->flags & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
}
#pragma pop
#undef SDK_SPRITE_RECORD
#undef SDK_SPRITE_RASTERS

/* Allocate a sprite sample with full RGB modulation and the requested record. */
// FUN_0046D200
u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex)
{
    u8 *node;

    chkmemAllocSiteTag(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    ((SdkSpriteSample *)node)->red = 0xFF;
    ((SdkSpriteSample *)node)->green = 0xFF;
    ((SdkSpriteSample *)node)->blue = 0xFF;
    ((SdkSpriteSample *)node)->packAddress = packAddress;
    ((SdkSpriteSample *)node)->recordIndex = recordIndex;
    return node;
}

// FUN_0046D280
void sdkSpriteFreeNode(void *node)
{
    jtbl_008873EC[0](node);
}

/* Draw and release a temporary sample with position, depth, and alpha subtraction. */
// FUN_0046D2B0
void sdkSpriteDrawOnce(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y, u8 alphaSubtract, f32 z, s32 setStates)
{
    u8 *node;

    chkmemAllocSiteTag(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    ((SdkSpriteSample *)node)->red = 0xFF;
    ((SdkSpriteSample *)node)->green = 0xFF;
    ((SdkSpriteSample *)node)->blue = 0xFF;
    ((SdkSpriteSample *)node)->packAddress = packAddress;
    ((SdkSpriteSample *)node)->recordIndex = recordIndex;
    ((SdkSpriteSample *)node)->depth = z;
    ((SdkSpriteSample *)node)->x = x;
    ((SdkSpriteSample *)node)->y = y;
    ((SdkSpriteSample *)node)->alphaSubtract = alphaSubtract;
    sdkSpriteDraw(node, setStates);
    jtbl_008873EC[0](node);
}

/* Draw a temporary sample with both subtractive and multiplicative alpha fading. */
// FUN_0046D3B0
void sdkSpriteDrawOnceAux(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y, u8 alphaSubtract, u8 fade, f32 z, s32 setStates)
{
    u8 *node;

    chkmemAllocSiteTag(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    ((SdkSpriteSample *)node)->red = 0xFF;
    ((SdkSpriteSample *)node)->green = 0xFF;
    ((SdkSpriteSample *)node)->blue = 0xFF;
    ((SdkSpriteSample *)node)->packAddress = packAddress;
    ((SdkSpriteSample *)node)->recordIndex = recordIndex;
    ((SdkSpriteSample *)node)->depth = z;
    ((SdkSpriteSample *)node)->x = x;
    ((SdkSpriteSample *)node)->y = y;
    ((SdkSpriteSample *)node)->alphaSubtract = alphaSubtract;
    ((SdkSpriteSample *)node)->fade = fade;
    sdkSpriteDraw(node, setStates);
    jtbl_008873EC[0](node);
}

/* Draw a temporary sample with caller RGB modulation, then release it. */
// FUN_0046D4C0
void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y, u8 alphaSubtract, u8 red, u8 green, u8 blue, f32 z, s32 setStates)
{
    u8 *node;

    chkmemAllocSiteTag(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    ((SdkSpriteSample *)node)->red = 0xFF;
    ((SdkSpriteSample *)node)->green = 0xFF;
    ((SdkSpriteSample *)node)->blue = 0xFF;
    ((SdkSpriteSample *)node)->packAddress = packAddress;
    ((SdkSpriteSample *)node)->recordIndex = recordIndex;
    ((SdkSpriteSample *)node)->depth = z;
    ((SdkSpriteSample *)node)->x = x;
    ((SdkSpriteSample *)node)->y = y;
    ((SdkSpriteSample *)node)->alphaSubtract = alphaSubtract;
    ((SdkSpriteSample *)node)->red = red;
    ((SdkSpriteSample *)node)->green = green;
    ((SdkSpriteSample *)node)->blue = blue;
    sdkSpriteDraw(node, setStates);
    jtbl_008873EC[0](node);
}

/* measured: nd 53 with a full C body (object 172B against a 192B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
/* Measured nd 9 (object 176 / window 192); the body matches the allocation, field initialization, callback, and result path but retains nine normalized instruction differences. */
/* Resolve the raster selected by a pack record through a temporary sample. */
// FUN_0046D5F0
s32 sdkSpriteSlotHandle(u8 *pack, s32 recordIndex) {
    s32 raster;
    u8 *sprite;
    u8 *owner;
    u8 *output;
    s32 index;

    chkmemAllocSiteTag(D_007130C8, 0x3AF);
    sprite = D_008873F4[0](1, 0x2C, 0x40000);
    ((SdkSpriteSample *)sprite)->red = 0xFF;
    ((SdkSpriteSample *)sprite)->green = 0xFF;
    ((SdkSpriteSample *)sprite)->blue = 0xFF;
    ((SdkSpriteSample *)sprite)->packAddress = (u32)(pack);
    ((SdkSpriteSample *)sprite)->recordIndex = recordIndex;
    owner = (u8 *)((SdkSpriteSample *)sprite)->packAddress;
    output = (u8 *)((SdkSpritePack *)owner)->recordsAddress;
    output = (u8 *)(((u32)(recordIndex << 7)) + ((u32)output));
    index = ((SdkSpriteRecord *)output)->rasterIndex;
    raster = (s32)((SdkSpritePack *)(((u32)(index << 2)) + ((u32)owner)))->rasters[0];
    jtbl_008873EC[0](sprite);
    return raster;
}
// FUN_0046D6A0
void sdkSpriteNoop(void)
{
}
