/* Original translation unit sdkSpr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "type.h"

void func_0044ea90(void *arg0, s32 arg1);
void strcpy(void *arg0, const char *arg1);
void func_00440b68(char *arg0, const char *arg1, s32 arg2);
void memcpy(void *arg0, void *arg1, s32 arg2);
void H_Cdvd_Destroy(u8 *ptr);
s32 H_Cdvd_IsFileLoaded(u8 *ptr);
u8 *func_00455f70(void *arg0, u32 *arg1);
u8 *func_00454a60(void *arg0, s32 arg1);
void func_003ec330(void *ptr);
s32 func_004667d0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
void func_0046b380(u8 *arg0, s32 arg1);

/* Sprite dispatcher slot at 0x008873EC (absolute, outside gp window). */
extern void (*jtbl_008873EC[])(void *node);
/* Allocator slot at 0x008873F4 (absolute, outside gp window). */
extern void *(*D_008873F4[])(size_t, size_t, u32);
/* GP-relative list head at gp -0x44E8 (absolute 0x00764C08). */
extern u8 *iGpffffbb18;
/* GP-relative global at gp -0x4FC8 (absolute 0x00764128). */
extern char iGpffffb038;
extern char D_007130C8[];

static inline u32 sdkAddOffset(u32 offset, u32 base) { return offset + base; }

/* Sprite-renderer types, shared by the guarded func_0046b380 body. */
#include "rw/plcore/barenderstate.h"

typedef struct RwV2d {
    f32 x, y;
} RwV2d;
typedef struct RwV3d {
    f32 x, y, z;
} RwV3d;
typedef struct RwMatrixTag RwMatrix;
typedef struct RwRGBA {
    u8 red, green, blue, alpha;
} RwRGBA;
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

extern s32 func_00457120(void);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern RwMatrix *func_003e0f80(void);
extern RwMatrix *func_003e0680(RwMatrix *, const RwV3d *, f32, f32, RwOpCombineType);
extern RwV3d *func_003e42e0(RwV3d *, const RwV3d *, s32, const RwMatrix *);
extern s32 func_003e0f40(RwMatrix *);
extern void func_0046a7f0(u8 *, u8 *);
extern f32 D_008872F8[];
extern u8 D_007130D8[];
extern f32 fGpffff8084;
extern f32 fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060;
extern f32 fGpffff81b0, fGpffff81b4, fGpffff81b8, fGpffff81bc;
extern f32 fGpffff81c0, fGpffff81c4, fGpffff81c8, fGpffff81cc;

/* The loader allocates and copies 0x80 bytes for every sprite record and
 * owns a fixed 32-entry raster array at +0x104 in its 0x240-byte container. */
typedef u8 SdkSpriteRecord[0x80];
/* Keep the same address-word view used by the attachment transformer. */
#define SDK_SPRITE_RECORD(sample) \
    ((u8 *)((u32)*(u32 *)((sample) + 4) * sizeof(SdkSpriteRecord) + \
            (u32)*(u8 **)(*(u8 **)(sample) + 0x204)))
/* Same address with the table term first. Selected point/extent sites use
 * this expression for their measured load/add order; C does not sequence
 * the two addition operands. */
#define SDK_SPRITE_RECORD_TABLE_FIRST(sample) \
    ((u8 *)(*(u32 *)(*(u8 **)(sample) + 0x204) + \
            *(u32 *)((sample) + 4) * sizeof(SdkSpriteRecord)))
/* Same address through sdkAddOffset (index term first): the helper's
 * parameter boundary gives retail's index-first addu at the packed-colour
 * reads and the points[2].x extent of func_0046b380. */
#define SDK_SPRITE_RECORD_VIA_ADD(sample) \
    ((u8 *)sdkAddOffset((u32)*(u32 *)((sample) + 4) * sizeof(SdkSpriteRecord), \
                        (u32)*(u8 **)(*(u8 **)(sample) + 0x204)))

#define SDK_SPRITE_RASTERS(sample) \
    (*(u8 *(*)[32])(*(u8 **)(sample) + 0x104))

/* Same unsigned extent, optional signed override, and Q12 scale as the
 * public width/height queries above. Each call reads the current payload. */
/* Both extents convert the bounds to u32 before the wrapping subtraction;
 * the optional signed override is then converted to the same width. */
static inline f32 sdkSpriteBorder(u8 *output, u32 offset, s32 field)
{
    return (f32)*(s32 *)(output + offset + field);
}

static inline f32 sdkSpriteRight(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5C) -
            (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0) {
        value = (value * *(u16 *)(sample + 0x20)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = sdkSpriteBorder(output, offset, 0x40);
        extent -= (f32)*(s16 *)(sample + 0x1C);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1C);
    return extent;
}

static inline f32 sdkSpriteBottom(u8 *sample, s32 includeBorder)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    f32 extent;

    offset = *(u32 *)(sample + 4) * 0x80;
    output = *(u8 **)(*(u8 **)sample + 0x204);
    value = (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            (u32)*(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0) {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0) {
        value = (value * *(u16 *)(sample + 0x22)) >> 12;
    }
    extent = (f32)value;
    if (includeBorder != 0) {
        f32 border = sdkSpriteBorder(output, offset, 0x38);
        extent -= (f32)*(s16 *)(sample + 0x1E);
        return border + extent;
    }
    extent -= (f32)*(s16 *)(sample + 0x1E);
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


// FUN_0046AB90
void func_0046ab90(u8 *arg0)
{
    u8 temp[8];
    u8 temp2[8];
    s32 i;
    s32 complete;
    s16 state;

    state = *(s16 *)arg0;
    switch (state) {
    case 0:
        func_00440b68(&iGpffffb038, D_007130C8, 0xB3);
        *(u32 *)(arg0 + 0x208) = (u32)func_00454a60(arg0 + 2, 0);
        *(s16 *)arg0 = 1;
        break;
    case 1:
        if (*(u32 *)(arg0 + 0x208) != 0) {
            if (H_Cdvd_IsFileLoaded((u8 *)*(u32 *)(arg0 + 0x208)) != 1) {
                break;
            }
            *(u32 *)(arg0 + 0x20C) =
                *(u32 *)(*(u8 **)(arg0 + 0x208) + 0x110);
        }
        memcpy(arg0 + 0x218, (void *)*(u32 *)(arg0 + 0x20C), 0x20);
        *(u32 *)(arg0 + 0x210) += 0x20;
        *(s16 *)arg0 = 2;
        *(s16 *)(arg0 + 0x214) = 0;
        if (*(u16 *)(arg0 + 0x22C) == 0) {
            *(s16 *)arg0 = 4;
            break;
        }
    case 2:
        do {
            memcpy(temp, (void *)(*(u32 *)(arg0 + 0x20C) +
                                          *(u32 *)(arg0 + 0x210)), 8);
            *(u32 *)(arg0 + 0x210) += 8;
            *(u32 *)(arg0 + (*(s16 *)(arg0 + 0x214) << 2) + 0x184) =
                func_004667d0(9, 0, 0, 0, 0,
                              *(u32 *)(arg0 + 0x20C) + *(u32 *)(temp + 4),
                              0, 0, 0, 0);
            *(u32 *)(arg0 + (*(s16 *)(arg0 + 0x214) << 2) + 0x104) = 0;
            *(s16 *)(arg0 + 0x214) += 1;
        } while (*(u16 *)(arg0 + 0x22C) !=
                 *(s16 *)(arg0 + 0x214));
        *(s16 *)arg0 = 3;
        break;
    case 3:
        complete = 1;
        for (i = 0; i < *(u16 *)(arg0 + 0x22C); i++) {
            u8 *entry = arg0 + (i << 2);
            u32 *slot = (u32 *)(entry + 0x104);

            if (*slot == 0) {
                *slot = func_004669d0(*(u32 *)(entry + 0x184),
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
        *(s16 *)arg0 = 4;
    case 4:
        func_0044ea90(D_007130C8, 0xFD);
        *(u32 *)(arg0 + 0x204) =
            (u32)D_008873F4[0](*(u16 *)(arg0 + 0x22E), 0x80, 0x40000);
        for (i = 0; i < *(u16 *)(arg0 + 0x22E); i++) {
            memcpy(temp2, (void *)(*(u32 *)(arg0 + 0x20C) +
                                            *(u32 *)(arg0 + 0x210)), 8);
            *(u32 *)(arg0 + 0x210) += 8;
            memcpy((u8 *)(*(u32 *)(arg0 + 0x204) + (i << 7)),
                          (void *)(*(u32 *)(arg0 + 0x20C) + *(u32 *)(temp2 + 4)),
                          0x80);
        }
        if (*(u32 *)(arg0 + 0x208) != 0) {
            H_Cdvd_Destroy((u8 *)*(u32 *)(arg0 + 0x208));
        }
        *(u32 *)(arg0 + 0x208) = 0;
        *(s16 *)(arg0 + 0x216) = *(u16 *)(arg0 + 0x22E);
        *(s16 *)arg0 = 5;
        break;
    case 5:
        break;
    }
}

// FUN_0046AEA0
u8 *func_0046aea0(const char *name)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x115);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 0;
    strcpy(node + 2, name);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046AF60
u8 *func_0046af60(u32 arg0)
{
    u8 *node;
    u8 *last;

    func_0044ea90(D_007130C8, 0x12D);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    *(u32 *)(node + 0x20C) = arg0;
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046B000
u8 *func_0046b000(const char *name)
{
    u8 *node;
    u8 *last;
    u32 out;

    func_0044ea90(D_007130C8, 0x146);
    node = D_008873F4[0](1, 0x240, 0x40000);
    *(s16 *)node = 1;
    strcpy(node + 2, name);
    *(u32 *)(node + 0x20C) = (u32)func_00455f70((void *)name, &out);
    if (iGpffffbb18 == NULL) {
        iGpffffbb18 = node;
    } else {
        last = iGpffffbb18;
loop:
        if (*(u8 **)(last + 0x238) == NULL) {
            *(u8 **)(last + 0x238) = node;
            *(u8 **)(node + 0x23C) = last;
        } else {
            last = *(u8 **)(last + 0x238);
            goto loop;
        }
    }
    return node;
}

// FUN_0046B0D0
void func_0046b0d0(u8 *node)
{
    s32 i;

    if (*(u8 **)(node + 0x23C) == NULL) {
        if (*(u8 **)(node + 0x238) == NULL) {
            iGpffffbb18 = NULL;
        } else {
            iGpffffbb18 = *(u8 **)(node + 0x238);
            *(u8 **)(iGpffffbb18 + 0x23C) = NULL;
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = NULL;
        }
    } else {
        *(u8 **)(*(u8 **)(node + 0x23C) + 0x238) = *(u8 **)(node + 0x238);
        if (*(u8 **)(node + 0x238) != NULL) {
            *(u8 **)(*(u8 **)(node + 0x238) + 0x23C) = *(u8 **)(node + 0x23C);
        }
    }
    i = 0;
    while (i < 0x20) {
        if (*(u32 *)(node + 0x104 + (i << 2)) != 0) {
            func_003ec330((void *)*(u32 *)(node + 0x104 + (i << 2)));
            *(u32 *)(node + 0x104 + (i << 2)) = 0;
        }
        i++;
    }
    if (*(u8 **)(node + 0x208) != NULL) {
        H_Cdvd_Destroy(*(u8 **)(node + 0x208));
        *(u8 **)(node + 0x208) = NULL;
    }
    if (*(u32 *)(node + 0x204) != 0) {
        jtbl_008873EC[0]((void *)*(u32 *)(node + 0x204));
        *(u32 *)(node + 0x204) = 0;
    }
    jtbl_008873EC[0](node);
}

/* Ported from P3FES h_maestro.c func_001126b0 (blob+index scale variant).
   Donor struct fields map onto P4 offsets: output at 0x204, overrideX at 0x74,
   right/left at 0x5c/0x54. The `sdkAddOffset` inline carries the offset-first
   operand order retail emits (addu $v0,$a1,$a0). */
// FUN_0046B1F0
f32 func_0046b1f0(u8 *blob, u32 index)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;

    offset = index * 0x80;
    output = *(u8 **)(blob + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    return (f32)value;
}
// FUN_0046B260
f32 func_0046b260(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x5c) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x54);
    overrideBase = output + 0x74;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x20) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x20)) >> 12);
    }
    return (f32)value;
}
// FUN_0046B2F0
f32 func_0046b2f0(u8 *param_1)
{
    u32 value;
    u32 offset;
    u8 *output;
    u8 *overrideBase;
    u8 *sample;

    sample = (u8 *)param_1;

    offset = *(u32 *)(sample + 0x4) * 0x80;
    output = *(u8 **)(*(u8 **)(sample + 0x0) + 0x204);
    value = *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x60) -
            *(s32 *)(sdkAddOffset(offset, (u32)output) + 0x58);
    overrideBase = output + 0x76;
    if (*(s16 *)(overrideBase + offset) != 0)
    {
        value = *(s16 *)(overrideBase + offset);
    }
    if (*(u16 *)(sample + 0x22) != 0)
    {
        value = (s32)(((u32)value * *(u16 *)(sample + 0x22)) >> 12);
    }
    return (f32)value;
}
/* 2026-10-09: 830 -> 208: the raster-less paths read the same uninitialised
   uv[] and source[].z slots retail does (documented inline). The raster guards
   around the uv flips and the vertex uv copies and the planar-Z writes are
   gone. fnalign measures this region only with the file's NON_MATCHING support
   block (lines 32-198) prepended to the candidate.
   2026-10-09: 208 -> 202: sdkSpriteVertexSetColor takes u8 channels (the
   RwRGBA bytes), so no andi is re-applied before each unsigned conversion.
 * sdiff 72/200 -> 70/197: raster table base formed before the index (retail addiu +0x104).
 * sdiff 70/197 -> 68/195: the two flip tests read the 0x18 word as (records + 0x18) + index, retail's address order.
 * sdiff 68/195 -> 63/182: third 0x3C read in field-first address order.
 * sdiff 63/182 -> 59/173: first two 0x3C reads field-first (retail addiu +0x3c), third via the record.
 * sdiff 44/102 -> 38/81: three record reads keep the table-first order.
 * fnalign 41 -> 25: packed-colour reads and points[2].x extent use
 * SDK_SPRITE_RECORD_VIA_ADD (index-first addu).
 */
// FUN_0046B380 NONMATCHING
#ifdef NON_MATCHING
/* Diagnostic C only: the whole-owner compile emits 7796/7808 bytes with
 * 25 aligned edits: lone commutative addu orders (record reads at the
 * raster lookup and flip tests, coordinate sums) and the alpha narrowing
 * at the colour multiply. This draft still reads unwritten UV/Z inputs and is not an
 * residual. This draft still reads unwritten UV/Z inputs and is not an
 * eligible C promotion. The defined-input changes in the October 5 archive
 * are absent here. See docs/probe_archive/Sprite_particle_boundaries_20261010.md
 * for the current owner proofs and producer/consumer boundaries. */
#pragma push
#pragma opt_loop_invariants on
void func_0046b380(u8 *sample, s32 setStates)
{
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

    reciprocalZ = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
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
    rasterIndex = *(s32 *)(SDK_SPRITE_RECORD(sample) + 0x14);
    raster = ((u8 **)(u32)(*(u8 **)(sample) + 0x104))[rasterIndex];
    if (raster != NULL) {
        s32 width = *(s32 *)(raster + 0xC);
        s32 height = *(s32 *)(raster + 0x10);

        uv[0].x = (f32)*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x54);
        uv[0].x /= (f32)width;
        uv[0].y = (f32)*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x58);
        uv[0].y /= (f32)height;
        uv[3].x = (f32)(*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x5C) - 1);
        uv[3].x /= (f32)width;
        uv[3].y = (f32)(*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x60) - 1);
        uv[3].y /= (f32)height;
        uv[1].x = uv[3].x;
        uv[2].x = uv[0].x;
        uv[1].y = uv[0].y;
        uv[2].y = uv[3].y;
    }
    if (setStates != 0) {
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x2C) & 1) != 0) {
            RpSkyRenderStateSet(2, (void *)0x48);
            RpSkyRenderStateSet(3, (void *)0x71801);
        }
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x2C) & 2) != 0) {
            RpSkyRenderStateSet(2, (void *)0x42);
            RpSkyRenderStateSet(3, (void *)0x71801);
        }
    }
    /* With a null initial raster, retail reaches these flips and the later
     * scalar vertex copies without writing uv[] (sp+0xA0..0xBC). An SDK
     * packet lane that the renderer may omit does not define these local
     * float reads. Retain the assembly guard until the input contract is
     * recovered; this is not a defined C implementation of that path. */
    if ((*(u32 *)(*(u32 *)(*(u8 **)(sample) + 0x204) + 0x18 + *(u32 *)(sample + 4) * sizeof(SdkSpriteRecord)) & 2) != 0) {
        verticalLeft = uv[0];
        uv[0] = uv[2];
        uv[2] = verticalLeft;
        verticalRight = uv[1];
        uv[1] = uv[3];
        uv[3] = verticalRight;
    }
    if ((*(u32 *)(*(u32 *)(*(u8 **)(sample) + 0x204) + 0x18 + *(u32 *)(sample + 4) * sizeof(SdkSpriteRecord)) & 1) != 0) {
        horizontalTop = uv[0];
        uv[0] = uv[1];
        uv[1] = horizontalTop;
        horizontalBottom = uv[2];
        uv[2] = uv[3];
        uv[3] = horizontalBottom;
    }

    source[0].x = (f32)-*(s16 *)(sample + 0x1C);
    source[0].y = (f32)-*(s16 *)(sample + 0x1E);
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
    angle = *(f32 *)(sample + 0x18);
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
            points[pointIndex].x = *(f32 *)(sample + 8) +
                ((f32)*(s16 *)(sample + 0x1C) + source[pointIndex].x) +
                (f32)*(s32 *)(SDK_SPRITE_RECORD_TABLE_FIRST(sample) + 0x44);
            {
                f32 subtotal = *(f32 *)(sample + 0xC) +
                    ((f32)*(s16 *)(sample + 0x1E) + source[pointIndex].y);
                subtotal += (f32)*(s32 *)(SDK_SPRITE_RECORD_TABLE_FIRST(sample) + 0x48);
                points[pointIndex].y = subtotal;
            }
        }
    }
    {
        s32 vertexIndex;
        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
            SdkSpriteVertex *vertex = &vertices[vertexIndex];
            RwRGBA color;

            vertex->u.els.screen.z = D_008872F8[0] - *(f32 *)(sample + 0x24);
            vertex->u.els.reciprocalZ = reciprocalZ;
            vertex->u.els.u = uv[vertexIndex].x;
            vertex->u.els.v = uv[vertexIndex].y;
            if (vertexIndex == 2) {
                u32 packed = *(u32 *)(SDK_SPRITE_RECORD_VIA_ADD(sample) + 0x70);
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            } else if (vertexIndex == 3) {
                u32 packed = *(u32 *)(SDK_SPRITE_RECORD_VIA_ADD(sample) + 0x6C);
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            } else {
                u32 packed = *(u32 *)(SDK_SPRITE_RECORD_VIA_ADD(sample) + 0x64 + vertexIndex * 4);
                color.red = (packed & 0xFF000000) >> 24;
                color.green = (packed & 0xFF0000) >> 16;
                color.blue = (packed & 0xFF00) >> 8;
                color.alpha = packed & 0xFF;
            }
            color.red = color.red * *(u8 *)(sample + 0x28) / 255;
            color.green = color.green * *(u8 *)(sample + 0x29) / 255;
            color.blue = color.blue * *(u8 *)(sample + 0x2A) / 255;
            if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
                if (color.red > 128) color.red = 255;
                else color.red = color.red * 255 / 128;
                if (color.green > 128) color.green = 255;
                else color.green = color.green * 255 / 128;
                if (color.blue > 128) color.blue = 255;
                else color.blue = color.blue * 255 / 128;
                if (color.alpha > 128) color.alpha = 255;
                else color.alpha = color.alpha * 255 / 128;
            }
            color.alpha = color.alpha * (255 - *(u8 *)(sample + 0x11)) / 255;
            if (*(u8 *)(sample + 0x10) < color.alpha) {
                color.alpha -= *(u8 *)(sample + 0x10);
            } else {
                color.alpha = 0;
            }
            sdkSpriteVertexSetColor(&vertices[vertexIndex], color.red, color.green,
                                   color.blue, color.alpha);
            vertices[vertexIndex].u.els.screen.x = points[vertexIndex].x;
            vertices[vertexIndex].u.els.screen.y = points[vertexIndex].y;
        }
    }
    if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
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

    if (*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x34) != 0) {
        points[0].x = (f32)-*(s16 *)(sample + 0x1C);
        points[0].y = (f32)-(*(s16 *)(sample + 0x1E) + *(s32 *)(SDK_SPRITE_RECORD(sample) + 0x34));
        points[1].x = sdkSpriteRight(sample, 0);
        points[1].y = (f32)-(*(s16 *)(sample + 0x1E) + *(s32 *)(SDK_SPRITE_RECORD(sample) + 0x34));
        points[2].x = (f32)-*(s16 *)(sample + 0x1C);
        points[2].y = (f32)-*(s16 *)(sample + 0x1E);
        points[3].x = sdkSpriteRight(sample, 0);
        points[3].y = (f32)-*(s16 *)(sample + 0x1E);
        func_0046a7f0(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[0].x; vertices[0].u.els.v = uv[0].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[0].x; vertices[2].u.els.v = uv[0].y;
        vertices[3].u.els.u = uv[1].x; vertices[3].u.els.v = uv[1].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (*(s32 *)(SDK_SPRITE_RECORD(sample) + 0x38) != 0) {
        points[0].x = (f32)-*(s16 *)(sample + 0x1C);
        points[0].y = sdkSpriteBottom(sample, 0);
        points[1].x = sdkSpriteRight(sample, 0);
        points[1].y = sdkSpriteBottom(sample, 0);
        points[2].x = (f32)-*(s16 *)(sample + 0x1C);
        points[2].y = sdkSpriteBottom(sample, 1);
        points[3].x = sdkSpriteRight(sample, 0);
        points[3].y = sdkSpriteBottom(sample, 1);
        func_0046a7f0(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[2].x; vertices[0].u.els.v = uv[2].y;
        vertices[1].u.els.u = uv[3].x; vertices[1].u.els.v = uv[3].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (*(s32 *)(*(u32 *)(*(u8 **)(sample) + 0x204) + 0x3C + *(u32 *)(sample + 4) * sizeof(SdkSpriteRecord)) != 0) {
        points[0].x = (f32)-(*(s16 *)(sample + 0x1C) + *(s32 *)(*(u32 *)(*(u8 **)(sample) + 0x204) + 0x3C + *(u32 *)(sample + 4) * sizeof(SdkSpriteRecord)));
        points[0].y = (f32)-*(s16 *)(sample + 0x1E);
        points[1].x = (f32)-*(s16 *)(sample + 0x1C);
        points[1].y = (f32)-*(s16 *)(sample + 0x1E);
        points[2].x = (f32)-(*(s16 *)(sample + 0x1C) + *(s32 *)(SDK_SPRITE_RECORD_VIA_ADD(sample) + 0x3C));
        points[2].y = sdkSpriteBottom(sample, 0);
        points[3].x = (f32)-*(s16 *)(sample + 0x1C);
        points[3].y = sdkSpriteBottom(sample, 0);
        func_0046a7f0(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[0].x; vertices[0].u.els.v = uv[0].y;
        vertices[1].u.els.u = uv[0].x; vertices[1].u.els.v = uv[0].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[2].x; vertices[3].u.els.v = uv[2].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    }
    if (*(s32 *)(SDK_SPRITE_RECORD_TABLE_FIRST(sample) + 0x40) != 0) {
        points[0].x = sdkSpriteRight(sample, 0);
        points[0].y = (f32)-*(s16 *)(sample + 0x1E);
        points[1].x = sdkSpriteRight(sample, 1);
        points[1].y = (f32)-*(s16 *)(sample + 0x1E);
        points[2].x = sdkSpriteRight(sample, 0);
        points[2].y = sdkSpriteBottom(sample, 0);
        points[3].x = sdkSpriteRight(sample, 1);
        points[3].y = sdkSpriteBottom(sample, 0);
        func_0046a7f0(sample, (u8 *)points);
        sdkSpritePositionQuad(vertices, points);
        vertices[0].u.els.u = uv[1].x; vertices[0].u.els.v = uv[1].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[3].x; vertices[2].u.els.v = uv[3].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
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
    if (*(s16 *)(sample + 0x16) != 0) {
        vertices[0].u.els.screen.x = points[2].x;
        vertices[0].u.els.screen.y = points[2].y;
        vertices[1].u.els.screen.x = points[3].x;
        vertices[1].u.els.screen.y = points[3].y;
        vertices[2].u.els.screen.x = points[2].x;
        vertices[2].u.els.screen.y = points[2].y + (f32)*(s16 *)(sample + 0x16);
        vertices[3].u.els.screen.x = points[3].x;
        vertices[3].u.els.screen.y = points[3].y + (f32)*(s16 *)(sample + 0x16);
        vertices[0].u.els.u = uv[2].x; vertices[0].u.els.v = uv[2].y;
        vertices[1].u.els.u = uv[3].x; vertices[1].u.els.v = uv[3].y;
        vertices[2].u.els.u = uv[2].x; vertices[2].u.els.v = uv[2].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
            states[0](1, SDK_SPRITE_RASTERS(sample)[rasterIndex]);
        } else {
            states[0](1, NULL);
        }
        render[0](4, vertices, 4);
    } else if (*(s16 *)(sample + 0x14) != 0) {
        vertices[0].u.els.screen.x = points[1].x;
        vertices[0].u.els.screen.y = points[1].y;
        vertices[1].u.els.screen.x = (f32)((s32)points[1].x + *(s16 *)(sample + 0x14));
        vertices[1].u.els.screen.y = points[1].y;
        vertices[2].u.els.screen.x = points[3].x;
        vertices[2].u.els.screen.y = points[3].y;
        vertices[3].u.els.screen.x = (f32)((s32)points[3].x + *(s16 *)(sample + 0x14));
        vertices[3].u.els.screen.y = points[3].y;
        vertices[0].u.els.u = uv[1].x; vertices[0].u.els.v = uv[1].y;
        vertices[1].u.els.u = uv[1].x; vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = uv[3].x; vertices[2].u.els.v = uv[3].y;
        vertices[3].u.els.u = uv[3].x; vertices[3].u.els.v = uv[3].y;
        if ((*(u32 *)(SDK_SPRITE_RECORD(sample) + 0x18) & 8) == 0) {
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
#else
INCLUDE_ASM("asm/nonmatchings/sdkSpr", func_0046b380);
#endif

// FUN_0046D200
u8 *func_0046d200(u32 arg0, u32 arg1)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    return node;
}

// FUN_0046D280
void func_0046d280(void *node)
{
    jtbl_008873EC[0](node);
}

// FUN_0046D2B0
void func_0046d2b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, f32 z, s32 arg3)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    func_0046b380(node, arg3);
    jtbl_008873EC[0](node);
}

// FUN_0046D3B0
void func_0046d3b0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, f32 z, s32 arg4)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x11) = arg3;
    func_0046b380(node, arg4);
    jtbl_008873EC[0](node);
}

// FUN_0046D4C0
void func_0046d4c0(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6)
{
    u8 *node;

    func_0044ea90(D_007130C8, 0x3AF);
    node = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(node + 0x28) = 0xFF;
    *(u8 *)(node + 0x29) = 0xFF;
    *(u8 *)(node + 0x2A) = 0xFF;
    *(u32 *)node = arg0;
    *(u32 *)(node + 4) = arg1;
    *(f32 *)(node + 0x24) = z;
    *(f32 *)(node + 8) = x;
    *(f32 *)(node + 0xC) = y;
    *(u8 *)(node + 0x10) = arg2;
    *(u8 *)(node + 0x28) = arg3;
    *(u8 *)(node + 0x29) = arg4;
    *(u8 *)(node + 0x2A) = arg5;
    func_0046b380(node, arg6);
    jtbl_008873EC[0](node);
}

/* measured: nd 53 with a full C body (object 172B against a 192B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
/* Measured nd 9 (object 176 / window 192); the body matches the allocation, field initialization, callback, and result path but retains nine normalized instruction differences. */
// FUN_0046D5F0
s32 func_0046d5f0(u8 *arg0, s32 arg1) {
    s32 temp_16;
    u8 *temp_2;
    u8 *temp_5;
    u8 *output;
    s32 index;

    func_0044ea90(D_007130C8, 0x3AF);
    temp_2 = D_008873F4[0](1, 0x2C, 0x40000);
    *(u8 *)(temp_2 + 0x28) = 0xFF;
    *(u8 *)(temp_2 + 0x29) = 0xFF;
    *(u8 *)(temp_2 + 0x2A) = 0xFF;
    *(u8 **)temp_2 = arg0;
    *(s32 *)(temp_2 + 4) = arg1;
    temp_5 = *(u8 **)temp_2;
    output = *(u8 **)(temp_5 + 0x204);
    output = (u8 *)sdkAddOffset((u32)(arg1 << 7), (u32)output);
    index = *(s32 *)(output + 0x14);
    temp_16 = *(s32 *)((u8 *)sdkAddOffset((u32)(index << 2), (u32)temp_5) + 0x104);
    jtbl_008873EC[0](temp_2);
    return temp_16;
}
// FUN_0046D6A0
void func_0046d6a0(void)
{
}
