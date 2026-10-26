#include "member_access.h"
#include "byte_address_internal.h"
#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw_texture_internal.h"
#include "h_cdvd_internal.h"
#include "field_event_internal.h"
#include "mdl_effect_internal.h"
#include "primitive_queue_internal.h"
#include "kwln_task_internal.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "field_light_internal.h"
#include "resrc_manager_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw/plcore/barenderstate.h"

/* RenderWare sky2/rwcore.h:5683-5747. The compact GS state values are
   carried as pointers; the same entry point also accepts real pointers. */
typedef s32 RwBool;
typedef enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF
} RpSkyRenderState;
extern RwBool RpSkyRenderStateSet(RpSkyRenderState state, void *value);


/* Device callback signatures and the PS2 vertex layout follow badevice.h
   and sky2/rwplcore.h. The owning packet contains seven complete vertices. */
typedef enum RwPrimitiveType {
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST,
    rwPRIMTYPEPOLYLINE,
    rwPRIMTYPETRILIST,
    rwPRIMTYPETRISTRIP,
    rwPRIMTYPETRIFAN,
    rwPRIMTYPEPOINTLIST,
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RadarPrimitive;
typedef struct RwRGBAReal { f32 r, g, b, a; } RadarColorReal;
typedef struct RwSky2DVertexFields {
    RwV3d scrVertex;
    f32 camVertex_z;
    f32 u, v, recipZ, pad1;
    RadarColorReal color;
    RwV3d objNormal;
    f32 pad2;
} RadarVertexFields;
typedef union RwSky2DVertexAlignmentOverlay {
    RadarVertexFields els;
    unsigned __int128 qWords[4];
} RadarVertexOverlay;
typedef struct RwSky2DVertex { RadarVertexOverlay u; } RadarVertex;
typedef s32 (*RadarRenderStateSet)(RwRenderState state, void *value);
typedef s32 (*RadarRenderPrimitive)(RadarPrimitive kind, RadarVertex *vertices, s32 count);

extern RadarRenderStateSet D_00887300_abs[];
extern RadarRenderPrimitive D_00887310_abs[];

typedef struct RwMatrix RwMatrix;

typedef struct {
    f32 x;
    f32 y;
} Float2_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0[3];
    f32 scale;
    f32 pad1;
    u32 color[4];
    u32 pad2[4];
} Quad_0014;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[0x14];
    u32 color[3];
    f32 scale;
    u8 pad1[0x10];
} Packet_0014;
typedef struct {
    u8 pad[0x40];
    u8 arg0[8];
    u8 arg1[8];
    Packet_0014 packet[4];
} Frame_0014;

extern u8 D_005EDA20[];
extern u8 D_005EDEA0[];
extern u8 D_005EE320[];
extern u8 D_005EE7A0[];
extern u8 D_005EEC20[];
extern u8 D_005EF0A0[];
extern u8 D_005EF530[];
extern u8 D_005EF540[];
extern u8 D_005EF548[];
extern u8 D_005EF6C8[];
extern f32 fGpffff8110;


extern u8 D_005EF890[];
extern u8 D_005EF8B0[];
extern u8 D_005EF8D0[];
extern u8 D_005EF8F0[];
extern u8 D_005EF910[];
extern u8 D_005EF930[];
extern u8 D_005EF950[];
extern u8 D_005EF970[];
extern u8 D_005EF820[];
extern u8 D_005EF870[];
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005EF840[];
extern u8 D_005EF858[];
extern void mdlEffectDestroy(s32 model);
extern u8 D_007EF9B0[];
extern s32 kwlnGetCamera(void);
extern u8 D_007E8020[];
extern u8 *func_003e9700(s32);

extern u8 D_005EF7D0[];
extern u8 D_005EF800[];
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 D_008872F8[];
extern f32 fGpffff8198;
extern u8 D_005EF710[];
extern u16 D_008C024E[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern u8 iGpffffba5c;
extern u8 iGpffffba60;
extern u8 iGpffffba64;
extern u8 iGpffffba68;
extern u8 * iGpffff9db0;
extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                          u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                          u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
extern void (*jtbl_008873EC[])(void *);

extern s32 D_00762EA0;

extern s32 mdlEffectCreateFromResource(s32 resource);
extern void mdlEffectStart(u8 *object);
extern s32 mdlEffectClone(s32 effect);
extern void mdlEffectSetChildPositionVec(void *object, f32 *position);

extern s32 D_007642E4;
extern u8 D_005EFB10[];


typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} P4Bytes0014;

typedef FieldRgba8 Rgba8_0014;

extern s32 RwEngineGetMatrixTolerances();
extern s32 RwMatrixOptimize();
extern s32 RwMatrixUpdate();

extern s32 D_007642F0;


extern s32 iGpffff9dd0;
extern s32 iGpffffb1f8;
extern s32 iGpffffb1fc;
extern u8 D_005EFAA0[];
extern u8 D_007E80A0[];
extern u8 D_007E8C00[];
extern u16 D_007D24B0[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u8 D_005EFC18[];
extern u8 D_005EFC28[];
extern u8 iGpffff9de0;
extern u8 iGpffff9de8;
extern s32 FldRc_FileLoadStep(u8 *task);
extern void FldRc_FileLoadDestroy(u8 *task);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 iGpffff9da8;
extern u8 D_005EF7B0[];
extern void strcpy(void *, const char *);
extern u8 D_005EF7C0[];
extern u8 iGpffff9db8;
extern u8 iGpffff9dc0;
extern u8 iGpffff9dc8;
extern RwV3d D_005EFB98;


/* Camp display: grid, labels, radar and corner sprites. Radar callees take u8 opacity because
 * retail passes the narrowed alpha without another mask. */
typedef struct { s32 lo, hi; } CampDisplayWords;
typedef union {
    Float2_0014 xy;
    CampDisplayWords words;
    s64 bits;
} CampDisplayPosition;
typedef struct {
    u8 r, g, b, a;
} CampDisplayRgba;

typedef union {
    CampDisplayRgba rgba;
    u8 bytes[4];
    s32 packed;
} CampDisplayColor;

extern f32 fGpffff854c;

extern u8 D_005EF520[];
extern u8 D_005EF670[];
extern u8 D_005EF6A0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern f32 D_008872F8[];


extern s32 FldEvent_AverageEntryValue(void);
extern u8 *FldEvent_GetGridCellEntry(s32 column, s32 row);
typedef struct {
    f32 gammaCorrection;
    void *fpSystem;
    f32 zBufferNear;
    f32 zBufferFar;
} RwDeviceHead_0014;
typedef struct {
    void *curCamera;
    void *curWorld;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
    RwDeviceHead_0014 dOpenDevice;
} RwGlobalsHead_0014;
extern u32 ourGlobals[];
#define RwIm2DGetNearScreenZ() \
    (((RwGlobalsHead_0014 *)ourGlobals)->dOpenDevice.zBufferNear)
/* Axes work starts with an RW matrix; setters expose its translation,
 * target flag at 0x44 and packed draw color at 0x48. */
typedef struct FldRcAxesWork {
    u8 pad00[0x30];
    SVec3 position;
    u8 pad3C[8];
    s32 targeted;
    Rgba8_0014 color;
} FldRcAxesWork;

/* Transition work is 0x50 bytes; its camera snapshot occupies 0x10..0x4F. */
typedef struct FldRcTransitionWork {
    s32 state, mode, frame;
    u8 *child;
    u8 pad10[0x20];
    SVec3 direction;
    u8 pad3C[4];
    SVec3 position;
    u8 pad4C[4];
} FldRcTransitionWork;

/* The loader allocates 0xFC bytes. Eight parallel clone arrays start at
 * 0x24/0x44/0x64/0x78/0x9C; the final 64 bytes hold the resource path. */
typedef struct FldRcEffectWork {
    s32 state;
    s32 file;
    u32 duration;
    s32 archiveSource;
    s32 primaryActive;
    s32 templateEffect;
    u32 primaryElapsed;
    s16 primaryPriority;
    u8 pad1E[2];
    s32 cloneCount;
    s32 effects[8];
    u32 elapsed[8];
    s16 priority[8];
    s32 primaryLock;
    s32 locks[8];
    s32 primaryHidden;
    s32 hidden[8];
    char path[0x40];
} FldRcEffectWork;

/* Four native sky2 vertices, followed by the texture and UV setup. */
typedef struct FldRcScreenQuad {
    RadarVertex vertices[4];
    s32 texture;
    f32 inverseZ;
    f32 uMin, vMin, uMax, vMax;
    s32 orientation;
} FldRcScreenQuad;

/* Scale all three transition-vector components into the destination. */
static inline void fldTransitionScaleVector(SVec3 *destination, SVec3 *source, f32 scale)
{
    destination->x = source->x * scale;
    destination->y = source->y * scale;
    destination->z = source->z * scale;
}
/* Treat a missing transition child or a positive child state as ready. */
static inline s32 fldTransitionChildReady(u8 *child)
{
    if (child == NULL) return 1;
    if (((FldRcEffectWork *)((KwlnTask *)child)->work)->state > 0) return 1;
    return 0;
}
/* Test whether the indexed field actor has both unit and active state. */
static inline u32 fldTransitionEntryActive(u32 index)
{
    s32 active = 0;
    u8 *entry = D_007EF9B0 + index * 0x750;
    if ((s32)((FldEventActor *)entry)->unit != 0 && (u8 *)(u32)((FldEventActor *)entry)->active != NULL) active = 1;
    return active != 0;
}
extern void fadeBeginTransition(s32 mode, s32 duration);
extern void H_Fade_SetCustomColor(s32 r, s32 g, s32 b);
extern f32 RwV3dNormalize(f32 *destination, f32 *source);
extern u8 iGpffff9dd8[8];
// FUN_0014DCD0
void FldRc_SetAxesTargeted(u8 *task, s32 targeted)
{
    ((FldRcAxesWork *)((KwlnTask *)task)->work)->targeted = targeted;
}

/* Copy the packed RGBA color into the axes task without changing its targeting state. */
// FUN_0014DCE0
void FldRc_SetAxesColor(u8 *task, u8 *color)
{
    u8 *work = ((KwlnTask *)task)->work;

    ((FldRcAxesWork *)work)->color = *(Rgba8_0014 *)color;
}

/* Set the axes matrix translation, then optimize and update its flags using engine tolerances. */
// FUN_0014DD10
void FldRc_SetAxesPosition(u8 *task, u8 *position) {
    f32 tolerances[4];
    u8 *work;

    work = ((KwlnTask *)task)->work;
    ((FldRcAxesWork *)work)->position = *(SVec3 *)position;
    RwEngineGetMatrixTolerances(&tolerances[0]);
    RwMatrixOptimize(work, &tolerances[0]);
    RwMatrixUpdate(work);
}

/* measured: with copy propagation off, retail keeps the separate vtable loads and float stores in
 * FldRc_DrawScreenQuad. */
#pragma opt_propagation off
/* Configure textured screen-quad render state and fill UVs from the stored bounds. The texture
 * pointer is reloaded after the vertex UVs are written, as in retail. */
// FUN_0014DD80
void FldRc_DrawScreenQuad(u8 *context, u8 *quad) {
    FldRcScreenQuad *screenQuad = (FldRcScreenQuad *)quad;
    void (**base)(u32, u32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 0);
    base[0](7, 2);
    base[0](9, 2);
    base[0](0xC, 1);
    base[0](2, 3);
    base[0](0xC, 1);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    if (*(s32 * *)&((FldRcScreenQuad *)quad)->texture != NULL) {
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.u = ((FldRcScreenQuad *)quad)->uMin;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.v = ((FldRcScreenQuad *)quad)->vMin;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.u = ((FldRcScreenQuad *)quad)->uMax;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.v = ((FldRcScreenQuad *)quad)->vMin;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.u = ((FldRcScreenQuad *)quad)->uMin;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.v = ((FldRcScreenQuad *)quad)->vMax;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.u = ((FldRcScreenQuad *)quad)->uMax;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.v = ((FldRcScreenQuad *)quad)->vMax;
        base[0](1, MEMBER(u32, (s32 *)(screenQuad->texture), RwTexture, raster));
        return;
    }
    base[0](1, 0);
}

/* The near Z is RwIm2DGetNearScreenZ(), a member of RenderWare's ourGlobals, reached through the
 * RwGlobals/RwDevice prefix. Fill four screen vertices in the requested orientation and queue their
 * render-state callback. */
// FUN_0014DEF0
void FldRc_QueueScreenQuad(u8 *queue, u8 *quad,
                   f32 left, f32 top, f32 depthOffset, f32 width,
                   f32 height, u8 *color, s32 texture,
                   f32 uMin, f32 vMin, f32 uMax, s32 orientation,
                   f32 vMax)
{
    extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
    f32 z;
    f32 inverse;
    f32 right;
    f32 bottom;
    u8 *entry;

    z = RwIm2DGetNearScreenZ() - depthOffset;
    if (depthOffset == 0.0f) {
        z = RwIm2DGetNearScreenZ() - ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    }
    inverse = 1.0f / z;
    switch (orientation) {
    case 0:
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.x = left;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.z = z;
        right = left + width;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.x = left;
        bottom = top + height;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.z = z;
        break;
    case 1:
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.x = left;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.z = z;
        right = left + width;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.x = left;
        bottom = top + height;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.z = z;
        break;
    case 2:
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.x = left;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.z = z;
        right = left + width;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.x = left;
        bottom = top + height;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.z = z;
        break;
    case 3:
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.x = left;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[2].u.els.scrVertex.z = z;
        right = left + width;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.y = top;
        ((FldRcScreenQuad *)quad)->vertices[0].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.x = left;
        bottom = top + height;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[3].u.els.scrVertex.z = z;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.x = right;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.y = bottom;
        ((FldRcScreenQuad *)quad)->vertices[1].u.els.scrVertex.z = z;
        break;
    }
    ((FldRcScreenQuad *)quad)->vertices[0].u.els.recipZ = inverse;
    ((FldRcScreenQuad *)quad)->vertices[1].u.els.recipZ = inverse;
    ((FldRcScreenQuad *)quad)->vertices[2].u.els.recipZ = inverse;
    ((FldRcScreenQuad *)quad)->vertices[3].u.els.recipZ = inverse;
    {
        s32 i;
        u8 *vertex;

        for (i = 0; i < 4; i++) {
            vertex = quad + (i << 6);
            ((RadarVertex *)vertex)->u.els.color.r = (f32)(u32)color[0];
            ((RadarVertex *)vertex)->u.els.color.g = (f32)(u32)color[1];
            ((RadarVertex *)vertex)->u.els.color.b = (f32)(u32)color[2];
            ((RadarVertex *)vertex)->u.els.color.a = (f32)(u32)color[3];
        }
    }
    ((FldRcScreenQuad *)quad)->texture = texture;
    ((FldRcScreenQuad *)quad)->inverseZ = inverse;
    ((FldRcScreenQuad *)quad)->uMin = uMin;
    ((FldRcScreenQuad *)quad)->vMin = vMin;
    ((FldRcScreenQuad *)quad)->uMax = uMax;
    ((FldRcScreenQuad *)quad)->vMax = vMax;
    ((FldRcScreenQuad *)quad)->orientation = orientation;
    entry = PrimQueueDrawPrimitive(queue, 4, quad, 4);
    ((PrimQueueNode *)entry)->callback = (void *)FldRc_DrawScreenQuad;
    ((PrimQueueNode *)entry)->argument.data = quad;
}

/* Load an effect template, then advance primary and cloned effects until their duration expires. */
// FUN_0014E2A0
s32 FldRc_FileLoadStep(u8 *task) {
    FldRcEffectWork *effectWork;
    extern s32 H_Cdvd_LookupRequest(u8 *pathAddress, s32 *slot);

    extern void mdlEffectFlushWithTable();
    extern void mdlEffectDestroy();
    extern u8 D_005DC7D0[];
    s32 resourceSize;
    u8 *work;
    s32 state;
    s32 primaryActive;
    s32 effect;
    s32 slotIndex;
    u8 *file;
    u8 *slotWork;
    s32 *effectSlot;
    s32 *elapsedSlot;

    work = ((KwlnTask *)task)->work;

    effectWork = (FldRcEffectWork *)work;
    state = ((FldRcEffectWork *)work)->state;
    switch (state) {
    case 0:
        if (((FldRcEffectWork *)work)->archiveSource == 0) {
            if (H_Cdvd_IsFileLoaded((HCdvd *)*(u8 * *)&((FldRcEffectWork *)work)->file) != 0) {
                file = (u8 *)(effectWork->file);
                if (file != NULL) {
                    ((FldRcEffectWork *)work)->templateEffect =
                        mdlEffectCreateFromResource(*(s32 *)&((HCdvd *)file)->fileMemory);
                    H_Cdvd_Destroy((HCdvd *)(u8 *)(effectWork->file));
                    effectWork->file = (s32)NULL;
                }
                goto block_10;
            }
        } else {
            ((FldRcEffectWork *)work)->templateEffect =
                mdlEffectCreateFromResource(H_Cdvd_LookupRequest(work + 0xBC, &resourceSize));
block_10:
            ((FldRcEffectWork *)work)->state = ((FldRcEffectWork *)work)->state + 1;
        }
    case 1:
        goto block_31;
    case 2:
        primaryActive = ((FldRcEffectWork *)work)->primaryActive;
        if ((primaryActive == 0) && (((FldRcEffectWork *)work)->cloneCount == 0)) {
            ((FldRcEffectWork *)work)->state = 1;
        } else {
            if ((primaryActive == 1) &&
                (((FldRcEffectWork *)work)->primaryLock != 1) &&
                (((FldRcEffectWork *)work)->primaryHidden != 1)) {
                if ((u32)((FldRcEffectWork *)work)->primaryElapsed <
                    (u32)((FldRcEffectWork *)work)->duration) {
                    mdlEffectCommitAndAdvance(*(u8 * *)&((FldRcEffectWork *)work)->templateEffect);
                    mdlEffectFlushWithTable(
                        (s32)&D_005DC7D0 +
                        (*(u16 *)&((FldRcEffectWork *)work)->primaryPriority * 0x54),
                        effectWork->templateEffect);
                    effectWork->primaryElapsed =
                        effectWork->primaryElapsed + 1;
                } else {
                    effectWork->primaryActive = 0;
                }
            }
            slotIndex = 0;
            goto loop_test;
loop_body:
            slotWork = work + (slotIndex * 4);
            if ((((FldRcEffectWork *)slotWork)->locks[0] != 1) &&
                (((FldRcEffectWork *)slotWork)->hidden[0] != 1)) {
                effectSlot = (s32 *)(slotWork + 0x24);
                effect = ((FldRcEffectWork *)slotWork)->effects[0];
                if (effect != 0) {
                    elapsedSlot = (s32 *)(slotWork + 0x44);
                    if ((u32)((FldRcEffectWork *)slotWork)->elapsed[0] <
                        (u32)((FldRcEffectWork *)work)->duration) {
                        mdlEffectCommitAndAdvance((u8 *)effect);
                        mdlEffectFlushWithTable(
                            (s32)&D_005DC7D0 +
                            (*(u16 *)&((FldRcEffectWork *)work)->priority[slotIndex] *
                             0x54),
                            *effectSlot);
                        *elapsedSlot = *elapsedSlot + 1;
                    } else {
                        mdlEffectDestroy(effect);
                        *effectSlot = 0;
                        ((FldRcEffectWork *)work)->cloneCount =
                            ((FldRcEffectWork *)work)->cloneCount - 1;
                    }
                }
            }
            slotIndex += 1;
loop_test:
            while (slotIndex < 8) {
                goto loop_body;
            }
            goto block_31;
        }
        goto block_31;
    case 3:
        return -1;
    default:
block_31:
        return 0;
    }
}

/* Destroy all live cloned effects and the template before freeing task work. measured: retail loads
 * the task work pointer untyped around effect destruction, so those accesses stay raw. */
// FUN_0014E540
void FldRc_FileLoadDestroy(u8 *task) {
    KwlnTask *ownerTask = (KwlnTask *)task;
    s32 i;
    u8 *work;
    s32 effect;

    work = ownerTask->work;
    for (i = 0; i < 8; i++) {
        effect = ((FldRcEffectWork *)work)->effects[i];
        if (effect != 0) {
            mdlEffectDestroy(effect);
        }
    }
    effect = ((FldRcEffectWork *)work)->templateEffect;
    if (effect != 0) {
        mdlEffectDestroy(effect);
    }
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create the effect-loader task from a path or an already selected load source. */
// FUN_0014E5E0
s32 FldRc_CreateFileLoadTask(u8 *parent, u8 *path, s32 duration, s32 loadSource) {
    s32 task;
    u8 *work;

    chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
    work = D_008873F4[0](1, 0xFC, 0x40000);
    if (work == NULL) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(work));
    if (loadSource == 0) {
        func_00440b68((const char *)&iGpffff9de8, &iGpffff9de0, 0xD0);
        ((FldRcEffectWork *)work)->file = (s32)H_Cdvd_AcquireDirectory(path, 0);
    } else {
        ((FldRcEffectWork *)work)->file = loadSource;
        ((FldRcEffectWork *)work)->archiveSource = 1;
    }
    *(s32 *)&((FldRcEffectWork *)work)->duration = duration;
    strcpy((u8 *)((FldRcEffectWork *)work)->path, (const char *)path);
    return task;
}

// FUN_0014E710
s32 FldRc_FileLoadIsReady(u8 *task) {
    if (task == NULL) {
        return 1;
    }
    return ((FldRcEffectWork *)((KwlnTask *)task)->work)->state >= 1;
}

/* measured: FldRc_RequestPositionSlot needs optimization level 1 so register allocation matches
 * retail. */
#pragma optimization_level 1
/* Start the primary effect or clone it into a free position slot; return the clone index or -1. */
// FUN_0014E740
s32 FldRc_RequestPositionSlot(u8 *task, f32 *position) {
    s32 slotOffset;
    s32 primaryActive;
    u8 *effectSlot;
    s32 effect;
    s32 priority;
    s32 slotIndex;
    u8 *work;

    work = ((KwlnTask *)task)->work;
    slotIndex = -1;
    if (((FldRcEffectWork *)work)->primaryActive == 1) {
        slotIndex = 0;
        goto loop_test_4;
loop_body_4:
        if (((FldRcEffectWork *)work)->effects[slotIndex] == 0) {
            goto loop_done_4;
        }
        slotIndex += 1;
loop_test_4:
        if (slotIndex < 8) {
            goto loop_body_4;
        }
loop_done_4:
        if (slotIndex >= 8) {
            kAssertFail(&iGpffff9de0, 0x100);
        }
        slotOffset = slotIndex * 4;
        effectSlot = byteAddressAdd(slotOffset, work) + 0x24;
        effect = mdlEffectClone(((FldRcEffectWork *)work)->templateEffect);
        *(s32 *)effectSlot = effect;
        mdlEffectSetChildPositionVec((void *)effect, position);
        ((FldRcEffectWork *)byteAddressAdd(slotOffset, work))->elapsed[0] = 0;
        priority = 1;
        ((FldRcEffectWork *)byteAddressAdd(slotIndex * 2, work))->priority[0] = priority;
        ((FldRcEffectWork *)work)->cloneCount = ((FldRcEffectWork *)work)->cloneCount + 1;
    } else {
        mdlEffectStart((u8 *)(((FldRcEffectWork *)work)->templateEffect));
        mdlEffectSetChildPositionVec(*(void * *)&((FldRcEffectWork *)work)->templateEffect, position);
        *(s32 *)&((FldRcEffectWork *)work)->primaryElapsed = 0;
        primaryActive = 1;
        ((FldRcEffectWork *)work)->primaryActive = primaryActive;
        ((FldRcEffectWork *)work)->primaryPriority = primaryActive;
    }
    ((FldRcEffectWork *)work)->state = 2;
    return slotIndex;
}

/* measured: FldRc_TransitionStep and FldRc_CreateTransitionTask only reproduce retail code at
 * optimization level 2. */
#pragma optimization_level 2
/* measured: indexed clone accesses use integer-address arithmetic as retail does. */
/* Set the draw priority of a position slot in the task's effect work, or the primary priority when
 * slotIndex is negative. An indexed slot only changes if it has an effect. */
// FUN_0014E880
void FldRc_SetPositionSlotPriority(u8 *task, s32 slotIndex, s16 priority) {
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (slotIndex >= 0) {
        if (((FldRcEffectWork *)byteAddressAdd((u32)(slotIndex * 4), work))->effects[0] != 0) {
            ((FldRcEffectWork *)byteAddressAdd((u32)(slotIndex * 2), work))->priority[0] = priority;
        }
    } else {
        ((FldRcEffectWork *)work)->primaryPriority = priority;
    }
}

/* Return the elapsed update count of the primary effect or an indexed clone. The indexed counter is
 * read through the raw integer-address helper, since a typed access changes the output. */
// FUN_0014E8C0
s32 FldRc_GetPositionSlotCount(u8 *task, s32 slotIndex) {
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (slotIndex >= 0) {
        return (s32)(((FldRcEffectWork *)byteAddressAdd((u32)(slotIndex * 4), work))->elapsed[0]);
    }
    return *(s32 *)&((FldRcEffectWork *)work)->primaryElapsed;
}

/* measured: the indexed lock access uses integer-address arithmetic as retail does. */
/* Set the lock flag of a position slot in the task's effect work, or the primary lock when
 * slotIndex is -1. */
// FUN_0014E8F0
void FldRc_SetPositionSlotLock(u8 *task, s32 slotIndex, s32 locked) {
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (slotIndex == -1) {
        ((FldRcEffectWork *)work)->primaryLock = locked;
        return;
    }
    ((FldRcEffectWork *)byteAddressAdd((u32)(slotIndex * 4), work))->locks[0] = locked;
}

/* measured: the indexed visibility access uses integer-address arithmetic as retail does. */
/* Set the hidden flag of a position slot in the task's effect work, or the primary hidden flag when
 * slotIndex is -1. */
// FUN_0014E920
void FldRc_SetPositionSlotVisibility(u8 *task, s32 slotIndex, s32 hidden) {
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (slotIndex == -1) {
        ((FldRcEffectWork *)work)->primaryHidden = hidden;
        return;
    }
    ((FldRcEffectWork *)byteAddressAdd((u32)(slotIndex * 4), work))->hidden[0] = hidden;
}

/* Inline predicates keep the reveal ordering and the frame-41 transition. */
#pragma push
/* measured: child reads and the frame increment stay byte-pointer accesses because retail reloads
 * them around the transition callbacks. */
// FUN_0014E950
/* measured: block lifetimes differ from retail without loop-invariant hoisting enabled. */
#pragma opt_loop_invariants on
s32 FldRc_TransitionStep(u8 *task)
{
    FldRcTransitionWork *transitionWork;
    SVec3 direction;
    SVec3 position;
    u8 color[8];
    u8 *work;
    s32 state;
    u32 i;

    work = ((KwlnTask *)task)->work;

    transitionWork = (FldRcTransitionWork *)work;
    state = *(s32 *)work;
    switch (state) {
        case 0:
        {
            u8 *child = ((FldRcTransitionWork *)work)->child;
            if (fldTransitionChildReady(child)) {
                s32 *source = (s32 *)func_003e9700((s32)((MdlEffectCamera *)(u32)kwlnGetCamera())->frame);
                s32 *destination = (s32 *)(work + 0x10);
                s32 count = 8;
                do {
                    s32 first = source[0];
                    s32 second = source[1];
                    source += 2;
                    count--;
                    destination[0] = first;
                    destination[1] = second;
                    destination += 2;
                } while (count > 0);
                direction = ((FldRcTransitionWork *)work)->direction;
                RwV3dNormalize(&direction.x, &direction.x);
                fldTransitionScaleVector(&direction, &direction, 700.0f);
                position = ((FldRcTransitionWork *)work)->position;
                position.x += direction.x;
                position.y += direction.y;
                position.z += direction.z;
                FldRc_RequestPositionSlot(transitionWork->child, &position.x);
                sdkSndStartStream(1, 0xB, 3, 4);
                ((FldRcTransitionWork *)work)->frame = 0;
                ++*(s32 *)work;
            }
            break;
        }
        case 1:
        {
            s32 frame = ((FldRcTransitionWork *)work)->frame;
            if (frame < 84) {
                if (frame > 40) {
                    for (i = 0; i < 4; i++) {
                        if (fldTransitionEntryActive(i)) {
                            u8 *entry = D_007EF9B0 + i * 0x750;
                            u8 *object = (u8 *)(u32)((FldEventActor *)entry)->active;
                            ((ResrcRecord *)object)->unk28 &= ~2U;
                        }
                    }
                    if (((FldRcTransitionWork *)work)->mode == 1) {
                        s8 *source = (s8 *)iGpffff9dd8;
                        s8 *destination = (s8 *)color;
                        s32 count = 4;
                        do {
                            s8 first = source[0];
                            s8 second = source[1];
                            source += 2;
                            count--;
                            destination[0] = first;
                            destination[1] = second;
                            destination += 2;
                        } while (count > 0);
                        fadeBeginTransition(1, 1);
                        H_Fade_SetCustomColor(color[0], color[1], color[2]);
                        ++*(s32 *)work;
                    }
                }
                ++transitionWork->frame;
            } else {
                *(s32 *)work = state + 1;
            }
            break;
        }
        case 2:
            return -1;
    }
    return 0;
}

#pragma pop
// FUN_0014EC20
void FldRc_TransitionDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create the camera transition controller and its mode-specific effect-loader child. */
// FUN_0014EC50
s32 FldRc_CreateTransitionTask(u8 *parent, s32 mode) {
    extern s32 FldRc_TransitionStep(u8 *task);
    extern s32 H_Cdvd_AcquireDirectory(const void *path, s32 flags);
    extern u8 D_005EFC40[];
    u8 **allocatorTable;
    u8 *effectWork;
    s32 result;
    u8 *work;
    u8 *header;
    chkmemAllocSiteTag(&iGpffff9de0, 0x2DF);
    allocatorTable = (u8 **)D_008873F4;
    work = ((u8 *(*)(s32, s32, s32))allocatorTable[0])(1, 0x50, 0x40000);
    if (work == NULL) {
        return 0;
    }
    header = D_005EFC28;
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(header), 0xF, 0, 0, FldRc_TransitionStep, FldRc_TransitionDestroy, (u8 *)(work));
    ((FldRcTransitionWork *)work)->mode = mode;
    if (mode == 0) {
        chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
        effectWork = ((u8 *(*)(s32, s32, s32))allocatorTable[0])(1, 0xFC, 0x40000);
        if (effectWork == NULL) {
            mode = 0;
        } else {
            mode = (s32)kwlnTaskCreateChild((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(effectWork));
            func_00440b68((const char *)&iGpffff9de8, &iGpffff9de0, 0xD0);
            ((FldRcEffectWork *)effectWork)->file = H_Cdvd_AcquireDirectory(&D_005EFC40, 0);
            *(s32 *)&((FldRcEffectWork *)effectWork)->duration = 0x53;
            strcpy((u8 *)((FldRcEffectWork *)effectWork)->path, (const char *)&D_005EFC40);
        }
        *(s32 *)&((FldRcTransitionWork *)work)->child = mode;
    } else if (mode == 1) {
        chkmemAllocSiteTag(&iGpffff9de0, 0xC2);
        effectWork = ((u8 *(*)(s32, s32, s32))allocatorTable[0])(1, 0xFC, 0x40000);
        if (effectWork == NULL) {
            mode = 0;
        } else {
            mode = (s32)kwlnTaskCreateChild((void *)((u8 *)result), (const void *)(&D_005EFC18), 0xF, 0, 0, FldRc_FileLoadStep, FldRc_FileLoadDestroy, (u8 *)(effectWork));
            func_00440b68((const char *)&iGpffff9de8, &iGpffff9de0, 0xD0);
            ((FldRcEffectWork *)effectWork)->file = H_Cdvd_AcquireDirectory(&D_005EFC40, 0);
            *(s32 *)&((FldRcEffectWork *)effectWork)->duration = 0x32;
            strcpy((u8 *)((FldRcEffectWork *)effectWork)->path, (const char *)&D_005EFC40);
        }
        *(s32 *)&((FldRcTransitionWork *)work)->child = mode;
    }
    return result;
}

// FUN_0014EEC0
s32 FldRc_GetLoadSource(void) {
    return D_007642F0;
}

