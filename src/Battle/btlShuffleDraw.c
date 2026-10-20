/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_sprite_loader.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_shuffle_draw_internal.h"
#include "sdk_snd_internal.h"
#include "btl_shuffle_state_internal.h"
#include "btl_shuffle_motion_internal.h"
#include "sdktask.h"
#include "rw_texture_internal.h"
extern s32 btlShuffleDrawFlagA(u8 *task);
extern void datTextSlotRelease();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 datTextSlotLoadStep();

extern void btlShuffleCardQueueDraw(u8 *card);
extern void pscCameraReset(void);
extern s32 kwlnGetCamera(void);
struct RwCamera;
extern void K_View_SetFov(struct RwCamera *camera, f32 fov);
extern s32 btlShuffleDrawCardCreate(void *drawWork);
extern s32 btlShuffleDrawViewCreate(void *drawWork);
extern s32 btlShuffleEffSpawn(void *task);
extern void sdkRenderStateSetDefault(void);
extern void btlShuffleDrawCards(u8 *context);
extern s32 btlShuffleDrawFlagB(u8 *task);
extern s32 btlShuffleDrawFlagC(u8 *task);
extern s32 btlShuffleDrawFlagD(u8 *task);
extern void btlShuffleDrawSetAlpha(u8 *task, u8 alpha);
extern void btlShuffleCalcSetBlend(u8 *, u8 *, u8 *);
extern void btlShuffleCalcStoreTiming(u8 *state, u8 *points, s32 delay, s32 duration);
extern void btlShuffleCalcInitMotion(u8 *state);
extern void btlShuffleCalcInitRotation(u8 *state);
extern void btlShuffleCalcScheduleMove(u8 *state, u16 delay, u16 duration, u8 *start, u8 *target, f32 displacement);
extern void btlShuffleCalcSetKeyframe(u8 *state, u16 delay, u16 duration, u8 *start, u8 *target, u8 *middle);
extern void btlShuffleCalcSetFrameRange(u8 *state, s32 duration, s32 start, s32 target);
extern void btlShuffleCalcSetFrameFlags(u8 *state, s32 delay, s32 stream, s32 channel);

typedef BtlShuffleVec3 ShuffleVec3;
typedef struct { f32 x, y, z, w; } ShuffleVec4;
extern void btlShuffleCalcSetQuat(u8 *state, u16 delay, u16 duration, u8 *start, ShuffleVec4 *target);
#include "rw_types_internal.h"
typedef RtQuat ShuffleQuaternion;
typedef struct { s64 a; f32 b; } ShuffleVec2s;

/* Each card has 0x60 bytes of position-track storage, 0x6C bytes of
 * rotation-track storage, and independent opacity/sound tracks. */
typedef union ShuffleMotion {
    BtlShuffleBezierMotion wander;
    BtlShuffleVectorTrack vector;
    BtlShuffleBezierTrack bezier;
    BtlShuffleOrbitTrack orbit;
    u8 data[0x60];
} ShuffleMotion;
typedef union ShuffleRotation {
    BtlShuffleBezierRotation wander;
    BtlShuffleQuaternionTrack quaternion;
    BtlShuffleAxisRotationTrack axis;
    u8 data[0x6C];
} ShuffleRotation;
typedef struct ShuffleRecord {
    u16 flags, unk02;
    s32 motionState, rotationState;
    ShuffleMotion motion;
    ShuffleRotation rotation;
    BtlShuffleByteTrack opacity;
    BtlShuffleSoundCue sound;
    u8 padE6[2];
} ShuffleRecord;
typedef struct ShuffleContext { u8 preceding[0x1D6A0]; ShuffleRecord records[]; } ShuffleContext;

/* The adopted sprite handle is tested as an address word and passed as a pointer. */
typedef union BtlShuffleSpriteSlot { s32 address; s16 *sprite; } BtlShuffleSpriteSlot;

typedef struct BtlShuffleDrawSettings {
    BtlShuffleContext context;
    f32 fieldOfView;
} BtlShuffleDrawSettings;

typedef RwRGBA TrailRGBA;

typedef union RxColorUnion {
    TrailRGBA preLitColor;
    TrailRGBA color;
} TrailColor;

typedef struct RxObjSpace3DVertex {
    ShuffleVec3 objVertex;
    TrailColor c;
    ShuffleVec3 objNormal;
    f32 u, v;
} TrailVertex;

/* Sixteen-byte sorted draw callback node, allocated by btlShuffleDrawAllocList. */
typedef struct BtlShuffleDrawNode {
    f32 depth;
    void (*callback)(u8 **);
    u8 **payload;
    struct BtlShuffleDrawNode *next;
} BtlShuffleDrawNode;

/* Shared 0x110-byte text texture slot, as used by datTextSlotLoadStep. */
typedef struct DatTextSlot {
    s32 state, resource;
    union { s32 handle; struct HCdvd *node; } request;
    union { s32 handle; RwTexture *texture; } result;
    u8 path[0x100];
} DatTextSlot;

/* The face task allocates 0x240 bytes; each face contains four 0x24-byte vertices. */
typedef struct BtlShuffleFaceWork {
    s32 ready, shaded;
    DatTextSlot textSlot;
    u8 pad118[4];
    u8 color[4];
    TrailVertex front[4], back[4];
} BtlShuffleFaceWork;



extern s32 sprintf(char *buf, const char *fmt, ...);
extern char D_0064EA80[];
extern void datTextSlotSetString(s32 *slotWords, u8 *text);
extern char D_0064EA20[];
extern void kAssertFail(void *file, s32 line);
extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, s32 endFrame, f32 curve);
extern s64 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s16 day);
extern char iGpffffa9d0;
extern s32 iGpffffa9c8;
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
extern void func_00440b68();
extern void btlShuffleCalcRotateVector(u8 *state, f32 frameOffset, u8 *output);
extern void btlShuffleDrawReset(u8 *context);
extern void btlShuffleCalcSetVectors(u8 *, s32, f32 *, f32 *, f32 *);
extern void btlShuffleCalcRotatePointAroundAxis(u8 *, u8 *, u8 *, f32 *, u8 *, f32 fparg0);
extern void sdkSpriteRelease(void *node);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 btlShuffleCalcNormalizeOffset(u8 *point);
extern s32 datGetFlag(s32 bit);
extern void pscResAcquireMiscCardW01(void);
extern void btlShuffleCardInit(u8 *card, u8 *specification);
extern void btlShuffleCardAttachSprite(u8 *card, void *position);
extern void btlShuffleCardBindPacket(u8 *card, void *rotation);
extern void btlShuffleCardBindSlot(u8 *card, void *color);
extern void memset(u8 *, s32, s32);
extern void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 *scale, f32 dst);
extern void btlShuffleCalcFillTable(s32 cardIndex, s32 cardCount, void *screen);

extern void btlShuffleDrawSpriteName(u8 *task, s32 cardIndex);
extern void btlShuffleDrawSetColor(u8 *task, u8 red, u8 green, u8 blue, s32 shaded);
extern char D_0064EA60[];
extern f32 iGpffff83e0;
extern s32 btlShuffleCalcSelectFrame(u8 *state, s32 curve);
extern s32 btlShuffleCalcTimeFromFrame(u8 *state);
extern void btlShuffleCalcStepWanderMotion(u8 *state);
extern s32 btlShuffleCalcAdvanceTrack(u8 *state);
extern s32 btlShuffleCalcFinishTrack(u8 *state);
extern s32 btlShuffleCalcUnitStep(u8 *unit);
extern s32 btlShuffleCalcUnitStepB(u8 *unit);
extern s32 btlShuffleCalcUpdateArc(u8 *state);
extern s32 btlShuffleCalcUpdateCurve(u8 *state);
extern void btlShuffleCalcStepWanderRotation(u8 *state);
extern s32 btlShuffleCalcUpdateBounce(u8 *state);
extern void btlShuffleCalcGetFrameRange(u8 *state);
extern void btlShuffleCalcLoadTable(u8 *state);
extern void btlShuffleDrawSetLayout(u8 *context, s32 cardIndex);
struct HCdvd;
extern u32 H_Cdvd_IsFileLoaded(struct HCdvd *cdvd);
extern u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);
extern void memcpy(s32, s32, s32);
extern void pscResBuildMiscCardW00(u8 *container);
extern u32 hMaestroDecodeIsReady(s16 *state);
extern u32 H_Cdvd_Destroy(struct HCdvd *cdvd);
extern void btlShuffleDrawTrail(u8 *work, s32 cardIndex, s32 mode, f32 length, u8 *rgba);
extern f32 btlShuffleDrawWaveScale(u8 *context, s32 cardIndex);
extern f32 iGpffff8170;
extern void btlShuffleDrawAllocList(f32 **list, void (*callback)(u8 **), u8 **payload, u8 *position);
extern void btlShuffleDrawListAdd(u8 **list, s32 release);
extern void btlShuffleDrawViewReset(u8 *context);
extern void btlShuffleDrawMoveCard(u8 *context, s32 cardIndex, f32 delay, f32 duration, f32 *start, f32 *target);
extern void btlShuffleDrawMoveCardB(u8 *context, s32 cardIndex, f32 *start, f32 *target, f32 delay, f32 duration);
extern void btlShuffleDrawSetQuat(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target);
extern void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
extern f32 btlShuffleCardWidth(u8 *card);
extern f32 btlShuffleCardHeight(u8 *card);
extern BtlShuffleMatrix *func_003e0f80(void);
extern BtlShuffleMatrix *RwMatrixTranslate(BtlShuffleMatrix *matrix, const BtlShuffleVec3 *translation, BtlShuffleCombine mode);
extern BtlShuffleVec3 *func_003e42a0(BtlShuffleVec3 *out, const BtlShuffleVec3 *in, const BtlShuffleMatrix *matrix);
extern s32 btlShuffleCalcUpdateSpeed(u8 *point, u8 *screen);
extern s32 func_003e0f40(BtlShuffleMatrix *matrix);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern f32 D_008872F8[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310[];
extern ShuffleQuaternion *func_003dc740(ShuffleQuaternion *dst,
                                       const ShuffleVec3 *axis,
                                       f32 angle, s32 combine);
extern s64 D_0064EA48[];
extern f32 D_0064EA50[];
extern s64 D_0064EA38[];
extern f32 D_0064EA40[];
extern f32 iGpffff840c;
extern f32 iGpffff81e0;
struct RwFrame;
extern BtlShuffleMatrix *func_003e9700(struct RwFrame *frame);
extern void func_003e0e20(u8 *, void *, s32);
typedef enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7fffffff
} RpSkyRenderState;
extern s32 RpSkyRenderStateSet(RpSkyRenderState state, void *value);
extern s32 pscResGetBaseRaster(void);
struct RxObjSpace3DVertex;
extern void *func_00410420(struct RxObjSpace3DVertex *vertices, u32 count, BtlShuffleMatrix *matrix, u32 flags);
extern s32 func_004106a0(BtlShufflePrimitive primitive);
extern f32 DAT_007613f8;
extern f32 iGpffff8218;
extern void RwMatrixRotate(void *, void *, s32, f32 fparg0);
extern f32 cosf(f32 fparg0);
extern void RwMatrixScale(void *, void *, s32);


/* Store the shuffle pattern, card count, difficulty, and parent task before resetting the draw state. */
// FUN_00373E10
void btlShuffleDrawSetup(u8 *context, s32 parentTask, s32 cardCount, s32 pattern, s32 difficulty) {
    if (cardCount > 8) {
        kAssertFail(D_0064EA20, 0x53);
    }
    if ((pattern < 0) || (pattern > 4)) {
        kAssertFail(D_0064EA20, 0x54);
    }
    ((BtlShuffleContext *)context)->parentTask = parentTask;
    ((BtlShuffleContext *)context)->cardCount = cardCount;
    ((BtlShuffleContext *)context)->pattern = pattern;
    ((BtlShuffleContext *)context)->difficulty = difficulty;
    ((BtlShuffleContext *)context)->unk1F30C = 0;
    btlShuffleDrawReset(context);
}


/* Clear sequence and card tracks, enable the pattern-dependent card count, and select the camera field of view. */
// FUN_00373F00
void btlShuffleDrawReset(u8 *context) {
    s32 count;
    s32 v;
    s32 i;
    ShuffleContext *p;

    BtlShuffleContext *state = (BtlShuffleContext *)context;

    memset(context + 0x1F1D0, 0, 0x40);
    memset(context + 0x1D6A0, 0, 0x1B30);
    state->flags = 0;
    *(s32 *)&state->phase = 0;
    state->elapsed = 0;
    state->pulse = 0;
    state->revealCard = -1;
    count = btlShuffleDrawTableLookup(state->cardCount, state->pattern);
    v = state->pattern;
    switch (v) {
    case 0:
    case 1:
    case 2:
        *(s32 *)&((BtlShuffleDrawSettings *)context)->fieldOfView = 0x42480000;
        break;
    case 3:
    case 4:
        *(s32 *)&((BtlShuffleDrawSettings *)context)->fieldOfView = 0x41200000;
        break;
    default:
        kAssertFail(D_0064EA20, 0x7C);
        break;
    }
    for (i = 0; i < count; i++) {
        p = (ShuffleContext *)(context + i * 0xE8);
        p->records[0].flags |= 2;
    }
}


/* Initialize each card panel from its repeating specification and set its identity quaternion. */
// FUN_003740B0
void btlShuffleDrawTaskInit(u8 *context, s32 cardIndex) {
    s32 count;
    s32 i;
    u8 *p;

    BtlShuffleContext *state = (BtlShuffleContext *)context;

    if ((datGetFlag(0x1403) != 0) && (datGetFlag(0x142B) != 0)) {
        pscResAcquireMiscCardW01();
    }
    count = btlShuffleDrawTableLookup(state->cardCount, state->pattern);
    for (i = 0; i < count; i++) {
        btlShuffleCardInit(context + i * 0xFB0, (u8 *)(cardIndex + (i % state->cardCount) * 8));
        p = (u8 *)(context + i * 0xE8);
        *(s32 *)&((ShuffleContext *)p)->records[0].rotation.quaternion.output.w = 0;
        *(s32 *)&((ShuffleContext *)p)->records[0].rotation.quaternion.output.x = 0;
        *(s32 *)&((ShuffleContext *)p)->records[0].rotation.quaternion.output.y = 0x3F800000;
        *(s32 *)&((ShuffleContext *)p)->records[0].rotation.quaternion.output.z = 0;
    }
}


/* Choose the day-window archive, acquire it asynchronously, and reset the resource-loader phase. */
// FUN_003741F0
void btlShuffleDrawLoadSprites(u8 *context) {
    /* Byte-base cursors preserve embedded variant and resource-slot addressing; typed fields are used where their layout is shared. */
    s32 directoryIndex;
    s32 archive;

    directoryIndex = !(calGetDayWindowFlags((s16)datGetDateIndex()) & 1);
    func_00440b68(&iGpffffa9d0, D_0064EA20, 0xB5);
    /* Keep the scalar GP declaration and its adjacent day-window slot as separate relocation-based storage. */
    archive = (s32)(H_Cdvd_AcquireDirectory(*(u8 **)((u8 *)&iGpffffa9c8 + directoryIndex * 4), 1));
    ((BtlShuffleContext *)context)->archive = archive;
    if (archive == 0) {
        kAssertFail(D_0064EA20, 0xB6);
    }
    ((BtlShuffleContext *)context)->loadPhase = 0;
}


/* measured (b210 -O2, 2026-09-17): if-else dispatch with shared return1 tail
   (Ghidra FUN_003742b0 + retail beq order 2,1,0); for-loop nests with reused
   i/k/tmp/val/p (Ghidra iVar3/iVar4 reuse) give frame 0x70 and 209/212 instrs
   (836B/848B, 1.4% size diff, within 3%). probe_variants 126 words (was 184
   m2c-switch, 176 for-loop-switch, 128 if-else-switch); fnalign 65 edits +10
   reloc-only (was 136+10). Decl order state,i,size,p,val,tmp,k via
   probe_search 300 (126w/65e vs 128w/75e baseline). Levers: Ghidra if-else
   over switch (-42w), hoisted full-address p=arg0+i*4+off after alloc for
   loop1/3, sunk loop2 store (hoist +30w, confirmed load-sinking floor).
   Residual floors: (1) arg-materialisation order before D_008873F4/f43f810
   (lw sp vs constants first); (2) loop2 hoist retail $18-before vs mwcc sink
   as lui $v1,2/sw -0xd54 (tried, +30w); (3) saved-color rotation arg0 $s3 vs
   $s0 + branch-orientation beqz+b vs bnez. Production stays ASM. */
/* 2026-09-18 measurement, not installed: retail materialises
   `arg0 + i * 4 + 0x1F2AC` into a saved register before the two calls in
   the second loop (`sll / addu / lui / ori / addu s2`), where b210 forms it
   at the store.  A pointer local for that store takes the object from three
   instructions short to two (210 vs 212) but costs 126 -> 158 words in
   colouring; doing the same for the later read as well is 176.  Same
   structural-fix-costs-words pattern as func_002e5000 in src/Yajima/
   y_list.c. */
/* The copy and sprite loops keep separate cursors; the sprite destination
   is formed before registration. opt_lifetimes on closes the remaining
   22 register words: 852/864 bytes, every relocation and zero tail proved.
   See docs/probe_archive/Shuffle_003742b0_recovery.md. */
// FUN_003742B0
#pragma push
#pragma opt_lifetimes on
s32 btlShuffleDrawLoadBlob(u8 *work)
{
    s32 copyIndex;
    s32 spriteIndex;
    u8 *source;
    s32 archiveIndex;
    s32 byteCount;
    extern void *memcpy(void *, const void *, size_t);
    BtlShuffleContext *state = (BtlShuffleContext *)work;

    switch (state->loadPhase) {
    case 0:
    {
        if (H_Cdvd_IsFileLoaded((struct HCdvd *)state->archive) == 0) break;
        archiveIndex = 0;
        {
            u8 *val;
            u8 *p;
            for (copyIndex = 0; copyIndex < 9; copyIndex++, archiveIndex++) {
                source = H_Cdvd_GetArchiveEntry((u8 *)(state->archive), archiveIndex, &byteCount);
                chkmemAllocSiteTag(&D_0064EA20, 0x101);
                val = D_008873F4[0](1, byteCount, 0x40000);
                p = work + copyIndex * 4 + 0x1F2B8;
                *(u8 **)p = val;
                if (val == 0) {
                    kAssertFail(&D_0064EA20, 0x102);
                }
                memcpy(*(u8 **)p, source, (size_t)byteCount);
            }
        }
        {
            u8 *p;
            for (spriteIndex = 0; spriteIndex < 3; spriteIndex++, archiveIndex++) {
                p = work + spriteIndex * 4 + 0x1F2AC;
                *(u8 **)p = sdkSpriteAdoptBlob((u32)H_Cdvd_GetArchiveEntry((u8 *)(state->archive), archiveIndex, NULL));
                if (*(u8 **)p == NULL) {
                    kAssertFail(&D_0064EA20, 0x109);
                }
            }
        }
        {
            u8 *val;
            u8 *p;
            for (copyIndex = 0; copyIndex < 3; copyIndex++, archiveIndex++) {
                source = H_Cdvd_GetArchiveEntry((u8 *)(state->archive), archiveIndex, &byteCount);
                chkmemAllocSiteTag(&D_0064EA20, 0x10F);
                val = D_008873F4[0](1, byteCount, 0x40000);
                p = work + copyIndex * 4 + 0x1F2DC;
                *(u8 **)p = val;
                if (val == 0) {
                    kAssertFail(&D_0064EA20, 0x110);
                }
                memcpy(*(u8 **)p, source, (size_t)byteCount);
            }
        }
        pscResBuildMiscCardW00(H_Cdvd_GetArchiveEntry((u8 *)(state->archive), archiveIndex, NULL));
        state->loadPhase = 1;
    }
    case 1:
    {
        s32 val;
        for (spriteIndex = 0; spriteIndex < 3; spriteIndex++) {
            /* measured: preserve work + index*4 before the field displacement; array indexing reverses one addu. */
            val = ((BtlShuffleSpriteSlot *)(work + spriteIndex * 4 + 0x1F2AC))->address;
            if ((val != 0) && (hMaestroDecodeIsReady(((BtlShuffleSpriteSlot *)(work + spriteIndex * 4 + 0x1F2AC))->sprite) == 0)) {
                return 0;
            }
        }
    }
        H_Cdvd_Destroy((struct HCdvd *)state->archive);
        state->archive = 0;
        state->loadPhase = 2;
    case 2:
        return 1;
    }
    return 0;
}

#pragma pop
/* Release copied texture data, sprite handles, and copied model blobs, clearing each owned slot. */
// FUN_00374610
void btlShuffleDrawRelease(u8 *context) {
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    s32 v;

    for (i = 0; i < 3; i++) {
        p = (u8 *)(context + i * 4 + 0x1F2DC);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)(context + j * 4 + 0x1F2AC);
        v = *(s32 *)p;
        if (v != 0) {
            sdkSpriteRelease((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (k = 0; k < 9; k++) {
        p = (u8 *)(context + k * 4 + 0x1F2B8);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
}


/* Arrange the visible cards, initialize position and quaternion tracks, and start the entrance sound if enabled. */
// FUN_00374730
void btlShuffleDrawFrame(u8 *context) {
    f32 screen[2];
    f32 position[3];
    f32 origin[3];
    f32 rotation[6];
    f32 delay;
    s32 cardCount;
    s32 cardIndex;

    BtlShuffleContext *state = (BtlShuffleContext *)context;

    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 0.0f;
    btlShuffleDrawViewReset(context);
    rotation[3] = 0.0f;
    rotation[0] = 0.0f;
    rotation[1] = 1.0f;
    rotation[2] = 0.0f;
    cardIndex = 0;
    goto loop_test;
loop_body:
    btlShuffleCalcFillTable(cardIndex, cardCount, &screen);
    btlShuffleCardScaleVec(context + cardIndex * 0xFB0, screen, position, 84.0f);
    if (state->unk1F30C != 0) {
        delay = (f32)cardIndex * (2.0f - ((f32)(state->cardCount - 3) / 5.0f));
        btlShuffleDrawMoveCardB(context, cardIndex, origin, position, delay, 10.0f + delay);
    } else {
        btlShuffleDrawMoveCard(context, cardIndex, 0.0f, 0.0f, position, position);
    }
    btlShuffleDrawSetQuat(context, cardIndex, 0, 0, rotation, rotation);
    btlShuffleDrawSetFrames(context, cardIndex, 0, 0xFF, 0xFF);
    cardIndex++;
loop_test:
    cardCount = state->cardCount;
    if (cardIndex < cardCount) {
        goto loop_body;
    }
    if (state->unk1F30C != 0) {
        sdkSndStartStream(1, 0, 5, 4);
    }
}


/* Reset the persona-card camera and apply the shuffle field of view. */
// FUN_00374910
void btlShuffleDrawViewReset(u8 *context) {
    pscCameraReset();
    K_View_SetFov((struct RwCamera *)(u32)kwlnGetCamera(), ((BtlShuffleDrawSettings *)context)->fieldOfView);
}


/* Restore the camera and create the card, view, and trail child tasks. */
// FUN_00374960
void btlShuffleDrawViewRestore(u8 *context) {
    BtlShuffleContext *state = (BtlShuffleContext *)context;
    pscCameraReset();
    K_View_SetFov((struct RwCamera *)(u32)kwlnGetCamera(), ((BtlShuffleDrawSettings *)context)->fieldOfView);
    *(s32 *)&state->cardTask = btlShuffleDrawCardCreate((void *)state->parentTask);
    *(s32 *)&state->viewTask = btlShuffleDrawViewCreate((void *)state->parentTask);
    *(s32 *)&state->trailTask = btlShuffleEffSpawn((void *)state->parentTask);
}


/* Advance the card position, rotation, opacity, and sound tracks; restart wandering tracks on a pending reset. */
// FUN_00374A10
void btlShuffleDrawUnitUpdate(u8 *context, s32 cardIndex) {
    u8 *p = (u8 *)(context + cardIndex * 0xE8 + 0x1D6A0);

    ShuffleRecord *record = (ShuffleRecord *)p;

    switch (*(u32 *)&record->motionState) {
    case 0:
        break;
    case 1:
        if (btlShuffleCalcSelectFrame(p + 0xC, 0) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 2:
        if (btlShuffleCalcSelectFrame(p + 0xC, 1) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 3:
        if (btlShuffleCalcSelectFrame(p + 0xC, 2) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 4:
        if (btlShuffleCalcTimeFromFrame(p + 0xC) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 5:
        btlShuffleCalcStepWanderMotion(p + 0xC);
        break;
    case 6:
        if (btlShuffleCalcAdvanceTrack(p + 0xC) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 7:
        if (btlShuffleCalcFinishTrack(p + 0xC) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 8:
        if (btlShuffleCalcUnitStep(p + 0xC) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    case 9:
        if (btlShuffleCalcUnitStepB(p + 0xC) != 0) {
            *(u32 *)&record->motionState = 0;
        }
        break;
    default:
        kAssertFail(D_0064EA20, 0x1F5);
        break;
    }
    switch (record->rotationState) {
    case 0:
        break;
    case 1:
        if (btlShuffleCalcUpdateArc(p + 0x6C) != 0) {
            record->rotationState = 0;
        }
        break;
    case 2:
        if (btlShuffleCalcUpdateCurve(p + 0x6C) != 0) {
            record->rotationState = 0;
        }
        break;
    case 3:
        btlShuffleCalcStepWanderRotation(p + 0x6C);
        break;
    case 4:
        if (btlShuffleCalcUpdateBounce(p + 0x6C) != 0) {
            record->rotationState = 0;
        }
        break;
    default:
        kAssertFail(D_0064EA20, 0x218);
        break;
    }
    btlShuffleCalcGetFrameRange(p + 0xD8);
    btlShuffleCalcLoadTable(p + 0xE0);
    if ((btlShuffleDrawStateA(p) != 0) && (record->flags & 1)) {
        btlShuffleDrawSetLayout(context, cardIndex);
        record->flags &= 0xFFFE;
    }
}


// FUN_00374CF0
void btlShuffleDrawQueueCards(u8 **context) {
    btlShuffleCardQueueDraw(*context);
}


/* 1732/1744 bytes; 37 resolved relocations and twelve zero alignment bytes.
 * The scoped axis initializer binds its twelve-byte object to D_0064EA38.
 * Natural quaternion products, native byte casts, and the u16 pre-increment
 * preserve retail's MAC order, conversion paths, and callback-visible reloads. */
// FUN_00374D20
void btlShuffleDrawCards(u8 *context) {
    /* Byte-base cursors preserve embedded variant and resource-slot addressing; typed fields are used where their layout is shared. */
    ShuffleVec3 translation;
    ShuffleVec4 rotation;
    f32 inv;
    f32 t2;
    f32 t1;
    f32 t0;
    f32 q10;
    f32 q9;
    f32 q8;
    f32 q7;
    f32 q6;
    f32 q5;
    f32 q4;
    f32 q3;
    f32 q2;
    f32 pulseFrame;
    f32 fadeFrame;
    f32 pulseAlpha;
    f32 fadeAlpha;
    f32 progress;
    s32 frontVertices;
    s32 backVertices;
    s32 texture;
    u8 *card;
    s32 camera;
    u32 renderStateBase;
    u8 pulseByte;
    u8 fadeByte;
    u8 *p;
    BtlShuffleMatrix *m;

    BtlShuffleContext *state = (BtlShuffleContext *)context;
    ShuffleRecord *record;

    p = context + state->revealCard * 0xE8 + 0x1D6A0;
    record = (ShuffleRecord *)p;
    translation = *(ShuffleVec3 *)&record->motion.wander.output;
    rotation = *(ShuffleVec4 *)&record->rotation.quaternion.output;
    if (state->flags & 0x40) {
        card = state->alternateCardTask;
    } else {
        card = state->frontCardTask;
    }
    frontVertices = btlShuffleDrawFlagB(card);
    backVertices = btlShuffleDrawFlagC(card);
    texture = btlShuffleDrawFlagD(card);
    m = func_003e0f80();
    /* RwCamera frame link stays an EE address word at the existing matrix-helper ABI boundary. */
    camera = *(s32 *)((u8 *)kwlnGetCamera() + 4);
    inv = 2.0f / (rotation.x * rotation.x + rotation.y * rotation.y + rotation.z * rotation.z +
                  rotation.w * rotation.w);
    t2 = rotation.x * inv;
    t1 = rotation.y * inv;
    t0 = rotation.z * inv;
    q10 = t2 * rotation.w;
    q9 = t1 * rotation.w;
    q8 = t0 * rotation.w;
    q7 = rotation.x * t2;
    q6 = rotation.y * t1;
    q5 = rotation.z * t0;
    q4 = rotation.y * t0;
    q3 = rotation.z * t2;
    q2 = rotation.x * t1;
    m->right.x = 1.0f - (q6 + q5);
    m->right.y = q2 + q8;
    m->right.z = q3 - q9;
    m->up.x = q2 - q8;
    m->up.y = 1.0f - (q5 + q7);
    m->up.z = q4 + q10;
    m->at.x = q3 + q9;
    m->at.y = q4 - q10;
    m->at.z = 1.0f - (q7 + q6);
    *(s32 *)&m->pos.x = 0;
    *(s32 *)&m->pos.y = 0;
    *(s32 *)&m->pos.z = 0;
    *(s32 *)&m->flags = 3;
    RwMatrixTranslate((BtlShuffleMatrix *)m, &translation, rwCOMBINEPOSTCONCAT);
    func_003e0e20((u8 *)m, func_003e9700((struct RwFrame *)camera), 2);
    renderStateBase = (u32)D_00887300;
    (*(BtlShuffleRenderStateSet *)renderStateBase)(6, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(8, 0);
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATECULLMODE, (void *)2);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
    if (state->flags & 0x20) {
        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)pscResGetBaseRaster());
        func_00410420((struct RxObjSpace3DVertex *)backVertices, 4, (BtlShuffleMatrix *)m, 3);
        func_004106a0(4);
    }
    btlShuffleDrawSetAlpha(card, record->opacity.output);
    if (state->flags & 0x80) {
        ShuffleVec3 axis = {0.0f, 0.0f, 1.0f};
        RwMatrixRotate(m, &axis, 1, 180.0f);
    }
    (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATETEXTURERASTER, (void *)(u32)texture);
    func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
    func_004106a0(4);
    if (state->flags & 0x10) {
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        state->pulse = (u16)((state->pulse + 1) % 60);
        pulseFrame = (f32)(u32)state->pulse;
        pulseAlpha = 255.0f * (1.0f - cosf((iGpffff81e0 * pulseFrame) / 60.0f)) / 2.0f;
        pulseByte = (u8)pulseAlpha;
        btlShuffleDrawSetAlpha(card, pulseByte & 0xFF);
        func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
        func_004106a0(4);
    }
    if (state->flags & 0x100) {
        ShuffleVec3 scale;
        fadeFrame = (f32)(u32)++state->pulse;
        progress = btlShuffleCalcWave(fadeFrame, 0.0f, 1, 20.0f);
        if (state->pulse >= 20) {
            state->flags &= 0xFEFF;
        }
        fadeAlpha = 255.0f * (1.0f - progress);
        fadeByte = (u8)fadeAlpha;
        btlShuffleDrawSetAlpha(card, fadeByte & 0xFF);
        scale.x = 1.0f + (f32)(iGpffff840c * progress);
        scale.y = scale.x;
        scale.z = 1.0f;
        RwMatrixScale(m, &scale, 1);
        func_00410420((struct RxObjSpace3DVertex *)frontVertices, 4, (BtlShuffleMatrix *)m, 3);
        func_004106a0(4);
    }
    func_003e0f40(m);
}

/* Native b210 O2: 1016/1024 bytes, thirteen resolved relocations and
 * eight zero alignment bytes. Queue pointers to the complete card
 * slots, then dispatch them before the stack-backed payloads expire.
 * See docs/probe_archive/Shuffle_draw_003753f0_20260923.md. */
// FUN_003753F0
void btlShuffleDrawTaskUpdate(u8 *work) {
    u8 *cardState;
    s32 cardIndex;
    u8 cardColor[4];
    s32 groupCount;
    u8 *queuedCards[30];
    f32 effectScale;
    u8 *transform;
    f32 phase;
    u8 effectColor[4];
    s32 cardCount;
    s32 mode;
    f32 modeScale;
    s32 effectIndex;
    u32 phaseCounter;
    u8 *card;
    BtlShuffleContext *state = (BtlShuffleContext *)work;

    sdkRenderStateSetDefault();
    cardColor[0] = 0xFF;
    cardColor[1] = 0xFF;
    cardColor[2] = 0xFF;
    if (state->flags & 1) {
        cardCount = btlShuffleDrawTableLookup(state->cardCount, state->pattern);
    } else {
        cardCount = state->cardCount;
    }
    for (cardIndex = 0; cardIndex < cardCount; cardIndex++) {
        if (((ShuffleContext *)(work + (u32)cardIndex * 0xE8))->records[0].flags & 2) {
            if ((state->flags & 2) == 0) {
                btlShuffleDrawUnitUpdate(work, cardIndex);
            }
            cardState = work + cardIndex * 0xE8;
            transform = cardState + 0x1D6B8;
            card = work + cardIndex * 0xFB0;
            btlShuffleCardAttachSprite(card, transform);
            btlShuffleCardBindPacket(card, cardState + 0x1D714);
            cardColor[3] = *(cardState + 0x1D778);
            btlShuffleCardBindSlot(card, cardColor);
            if (cardIndex != state->revealCard) {
                queuedCards[cardIndex] = card;
                btlShuffleDrawAllocList((f32 **)(work + 0x1F24C), btlShuffleDrawQueueCards,
                              queuedCards + cardIndex, transform);
            }
        }
    }
    btlShuffleDrawListAdd((u8 **)(work + 0x1F24C), 1);
    effectColor[0] = 0x20;
    effectColor[1] = 0x40;
    effectColor[2] = 0xFF;
    effectColor[3] = 0xFF;
    modeScale = 1.0f;
    groupCount = state->cardCount;
    mode = state->pattern;
    if (mode == 4) {
        goto mode_zero;
    }
    if (mode == 3) {
        goto mode_zero;
    }
    if (mode == 2) {
        goto mode_two;
    }
    if (mode == 1) {
        goto mode_one;
    }
    /* Retail leaves phaseCounter untouched for modes outside 0..4;
     * retain that default path rather than inventing a fallback value. */
    switch (mode) {
    case 0:
        goto mode_zero_value;
    default:
        goto mode_calc;
    }
mode_zero_value:
    phaseCounter = state->sequenceFrames;
    goto mode_calc;
mode_one:
    groupCount /= 2;
    phaseCounter = state->sequenceFrames;
    goto mode_calc;
mode_two:
    groupCount /= 3;
    phaseCounter = state->sequenceFrames;
    modeScale = iGpffff8170;
    goto mode_calc;
mode_zero:
    effectScale = 0.0f;
    goto mode_done;
mode_calc:
    phase = (f32)phaseCounter;
    effectScale = modeScale * ((0.5f * phase) / (f32)groupCount);
mode_done:
    if (!(effectScale <= 0.0f)) {
        for (effectIndex = 0; effectIndex < cardCount; effectIndex++) {
            if (((ShuffleContext *)(work + effectIndex * 0xE8))->records[0].flags & 2) {
                btlShuffleDrawTrail(work, effectIndex, 2, effectScale * btlShuffleDrawWaveScale(work, effectIndex), effectColor);
            }
        }
    }
}

/* Draw the selected model card or its generated front/back faces according to the context flags. */
// FUN_003757F0
void btlShuffleDrawQueueCardsB(u8 *context) {
    BtlShuffleContext *state = (BtlShuffleContext *)context;

    sdkRenderStateSetDefault();
    if (state->flags & 4) {
        btlShuffleCardQueueDraw(context + state->revealCard * 0xFB0);
    }
    if (state->flags & 8) {
        btlShuffleDrawCards(context);
    }
}


/* Enable or disable one card record for drawing. */
// FUN_00375890
void btlShuffleDrawPoll(u8 *context, s32 cardIndex, s32 enabled) {
    if (enabled) {
        ((ShuffleContext *)((u8 *)(cardIndex * 0xE8) + (u32)context))->records[0].flags |= 2;
    } else {
        ((ShuffleContext *)((u8 *)(cardIndex * 0xE8) + (u32)context))->records[0].flags &= 0xFFFD;
    }
}


/* Report when position, rotation, and opacity tracks have all completed. */
// FUN_00375910
s32 btlShuffleDrawStateA(u8 *record) {
    s32 b;

    b = btlShuffleDrawStateB(record) != 0;
    if (b) {
        b = btlShuffleDrawStateC(record) != 0;
    }
    if (b) {
        b = btlShuffleDrawStateD(record) != 0;
    }
    return b;
}


/* Report completion of a position track; idle and wandering tracks do not block. */
// FUN_00375970
s32 btlShuffleDrawStateB(u8 *record) {
    f32 frameValue;
    s32 mode;
    u32 frame;

    mode = ((ShuffleRecord *)record)->motionState;
    switch (mode) {
    case 0:
    case 5:
        return 1;
    default:
        frame = ((ShuffleRecord *)record)->motion.wander.frame;
        if (frame >= 0) {
            frameValue = (f32)frame;
        } else {
            frame = (frame >> 1) | (frame & 1);
            frameValue = (f32)frame;
            frameValue += frameValue;
        }
        return frameValue >= ((ShuffleRecord *)record)->motion.wander.duration;
    }
}


/* Report completion of a rotation track; idle and wandering tracks do not block. */
// FUN_00375A00
s32 btlShuffleDrawStateC(u8 *record) {
    s32 v = ((ShuffleRecord *)record)->rotationState;
    switch (v) {
    case 0:
    case 3:
        return 1;
    default:
        return ((ShuffleRecord *)record)->rotation.wander.frame >= ((ShuffleRecord *)record)->rotation.wander.duration;
    }
}


// FUN_00375A50
s32 btlShuffleDrawStateD(u8 *record) {
    return ((ShuffleRecord *)record)->opacity.frame >= ((ShuffleRecord *)record)->opacity.duration;
}


/* The source call must place the two converted values in f12/f14 around the
   integer argument as func_00373cb0(var_f12, 0.0f, 0, var_f14); O2 CSEs the
   base-address materialization and swaps the resulting argument registers.
   measured: O1 plus that call order gives a byte-exact match, obj 204B of a
   208B window. */
#pragma optimization_level 1
/* Return normalized progress of the card rotation track for trail scaling. */
// FUN_00375A70
f32 btlShuffleDrawWaveScale(u8 *context, s32 cardIndex) {
    f32 frame;
    f32 duration;
    s32 idx;

    idx = cardIndex * 0xE8;
    frame = (f32)(u32)((ShuffleContext *)((u8 *)idx + (u32)context))->records[0].rotation.quaternion.frame;
    duration = (f32)(u32)((ShuffleContext *)((u8 *)idx + (u32)context))->records[0].rotation.quaternion.duration;
    return btlShuffleCalcWave(frame, 0.0f, 0, duration);
}
/* measured: O1 probe for f70 address materialization */
#pragma optimization_level 2


/* 520/528 bytes; ten resolved relocations; eight zero alignment bytes.
 * Load both parts of the twelve-byte axis before storing either part.
 * The typed quaternion dot product retains the retail ACC operand order. */
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pack(4)
typedef struct { s64 xy; f32 z; } ShuffleAxis12;
typedef union { ShuffleAxis12 bits; ShuffleVec3 vector; } ShuffleAxis;
#pragma pop
typedef char ShuffleAxisSizeCheck[sizeof(ShuffleAxis) == 12 ? 1 : -1];
typedef char ShuffleQuatSizeCheck[sizeof(ShuffleQuaternion) == 16 ? 1 : -1];
extern s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern);
/* When the rotation track is idle, compose a half-turn and schedule the resulting quaternion. */
// FUN_00375B40
void btlShuffleDrawSetPose(u8 *context, s32 cardIndex, u16 delay, u16 duration) {
    ShuffleAxis axis;
    s64 bits;
    f32 value;

    ShuffleQuaternion rotation;
    ShuffleVec4 output;
    s32 state;
    s64 active;
    u8 *p;
    ShuffleVec4 *current;

    bits = D_0064EA48[0];
    value = D_0064EA50[0];
    axis.bits.xy = bits;
    axis.bits.z = value;
    if (cardIndex >= btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, ((BtlShuffleContext *)context)->pattern)) {
        kAssertFail(D_0064EA20, 0x3E9);
    }
    p = context + cardIndex * 0xE8 + 0x1D6A0;
    state = ((ShuffleRecord *)p)->rotationState;
    switch (state) {
    case 0:
    case 3:
        active = 1;
        break;
    default:
        if ((s64)((ShuffleRecord *)p)->rotation.wander.frame >= (s64)((ShuffleRecord *)p)->rotation.wander.duration) {
            active = 1;
        } else {
            active = 0;
        }
        break;
    }
    if (active) {
        func_003dc740(&rotation, &axis.vector, 180.0f, 0);
        current = (ShuffleVec4 *)(p + 0x74);
        output.w = current->w * rotation.real
            - ((current->x * rotation.imag.x + current->y * rotation.imag.y)
                + current->z * rotation.imag.z);
        output.x = current->y * rotation.imag.z - current->z * rotation.imag.y;
        output.y = current->z * rotation.imag.x - current->x * rotation.imag.z;
        output.z = current->x * rotation.imag.y - current->y * rotation.imag.x;
        output.x = (0.0f + output.x) + rotation.imag.x * current->w;
        output.y = (0.0f + output.y) + rotation.imag.y * current->w;
        output.z = (0.0f + output.z) + rotation.imag.z * current->w;
        output.x = (0.0f + output.x) + current->x * rotation.real;
        output.y = (0.0f + output.y) + current->y * rotation.real;
        output.z = (0.0f + output.z) + current->z * rotation.real;
        btlShuffleDrawSetQuat(context, cardIndex, delay, duration, 0, (f32 *)&output);
    }
}
#pragma pop

/* Initialize linear movement for one card and select position mode one. */
// FUN_00375D50
void btlShuffleDrawMoveCard(u8 *context, s32 cardIndex, f32 delay, f32 duration, f32 *start, f32 *target) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcSetBlend((u8 *)(context + idx + 0x1D6AC), (u8 *)start, (u8 *)target);
    ((ShuffleContext *)p)->records[0].motionState = 1;
}


/* Initialize sine-eased movement for one card and select position mode two. */
// FUN_00375DD0
void btlShuffleDrawMoveCardB(u8 *context, s32 cardIndex, f32 *start, f32 *target, f32 delay, f32 duration) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcSetBlend((u8 *)(context + idx + 0x1D6AC), (u8 *)start, (u8 *)target);
    ((ShuffleContext *)p)->records[0].motionState = 2;
}


/* Copy four position control points and select cubic movement. */
// FUN_00375E50
void btlShuffleDrawSetTiming(u8 *context, s32 cardIndex, s32 delay, s32 duration, f32 *start) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcStoreTiming((u8 *)(context + idx + 0x1D6AC), (u8 *)start, delay, duration);
    ((ShuffleContext *)p)->records[0].motionState = 4;
}


/* Request that the card restart its wandering position and rotation tracks when idle. */
// FUN_00375EC0
void btlShuffleDrawClearFlags(u8 *context, s32 cardIndex) {
    u8 *p = (u8 *)(cardIndex * 0xE8) + (u32)context;
    ((ShuffleContext *)p)->records[0].flags |= 1;
}


/* Reset one shuffle record: reinitialise its motion and rotation objects and
   set their states to 5 and 3. Each state store forms the record address
   again from the byte offset, as integer arithmetic. Those address
   expressions differ from the pointer's in the frontend, so it keeps
   `arg0`/`idx` live in $s1/$s0. b210's post-colouring CSE then turns each
   recomputed `addu` into a copy of the pointer in $s2, as in retail. */
/* Reinitialize wandering position and quaternion tracks and select their continuous modes. */
// FUN_00375F00
void btlShuffleDrawSetLayout(u8 *context, s32 cardIndex) {
    s32 idx = cardIndex * sizeof(ShuffleRecord);
    ShuffleContext *p = (ShuffleContext *)(context + idx);
    btlShuffleCalcInitMotion((u8 *)&p->records[0].motion);
    ((ShuffleContext *)((u32)context + idx))->records[0].motionState = 5;
    btlShuffleCalcInitRotation((u8 *)&p->records[0].rotation);
    ((ShuffleContext *)(context + (u32)idx))->records[0].rotationState = 3;
}

/* Initialize a card orbit from its axis, center, and point. */
// FUN_00375FA0
void btlShuffleDrawInitCard(u8 *context, s32 cardIndex, s32 delay, u8 *duration, u8 *start, u8 *target) {
    ShuffleVec3 v3;
    ShuffleVec3 v4;
    ShuffleVec3 v5;
    s32 idx;

    v3 = *(ShuffleVec3 *)duration;
    v4 = *(ShuffleVec3 *)start;
    v5 = *(ShuffleVec3 *)target;
    idx = cardIndex * 0xE8;
    btlShuffleCalcSetVectors((u8 *)(context + idx + 0x1D6AC), delay, (f32 *)&v3, (f32 *)&v4, (f32 *)&v5);
    ((ShuffleContext *)((u8 *)idx + (u32)context))->records[0].motionState = 6;
}


/* Schedule the direction-based displaced position curve for one card. */
// FUN_00376070
void btlShuffleDrawSetRange(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target, f32 displacement) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcScheduleMove((u8 *)(context + idx + 0x1D6AC), delay, duration, (u8 *)start, (u8 *)target, displacement);
    ((ShuffleContext *)p)->records[0].motionState = 8;
}


/* Schedule start-to-target quaternion interpolation for one card. */
// FUN_003760F0
void btlShuffleDrawSetQuat(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcSetQuat((u8 *)(context + idx + 0x1D70C), delay, duration, (u8 *)start, (ShuffleVec4 *)target);
    ((ShuffleContext *)p)->records[0].rotationState = 1;
}


/* Schedule quaternion interpolation through a midpoint for one card. */
// FUN_00376170
void btlShuffleDrawSetArc(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target, f32 *middle) {
    s32 idx = cardIndex * 0xE8;
    u8 *p = (u8 *)idx + (u32)context;

    btlShuffleCalcSetKeyframe((u8 *)(context + idx + 0x1D70C), delay, duration, (u8 *)start, (u8 *)target, (u8 *)middle);
    ((ShuffleContext *)p)->records[0].rotationState = 2;
}


/* Schedule axis-angle rotation over the supplied angular range. */
// FUN_003761F0
void btlShuffleDrawSetCurve(u8 *context, s32 cardIndex, u16 delay, u16 duration, const BtlShuffleVec3 *axis, f32 start, f32 end) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *axis;
    idx = cardIndex * 0xE8;
    p = (u8 *)((u32)idx + (u32)context);
    btlShuffleCalcSetCurveSample((u8 *)(context + idx + 0x1D70C), delay, duration, &v, start, end);
    ((ShuffleContext *)p)->records[0].rotationState = 4;
}


// FUN_00376290
void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start) {
    s32 idx = cardIndex * 0xE8;

    btlShuffleCalcSetFrameRange((u8 *)(context + idx + 0x1D778), delay, duration, start);
}


// FUN_003762E0
void btlShuffleDrawSetFrameFlags(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start) {
    s32 idx = cardIndex * 0xE8;

    btlShuffleCalcSetFrameFlags((u8 *)(context + idx + 0x1D780), delay, duration, start);
}


/* Return the endpoint appropriate to the active position-track variant. */
// FUN_00376330
void btlShuffleDrawSetRotate(u8 *context, s32 cardIndex, f32 *output) {
    u8 *p = (u8 *)(context + cardIndex * 0xE8 + 0x1D6A0);
    switch (*(u32 *)&((ShuffleRecord *)p)->motionState) {
    case 0:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.wander.output;
        return;
    case 1:
    case 2:
    case 3:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.vector.target;
        return;
    case 5:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.wander.points.end;
        return;
    case 4:
        *(ShuffleVec3 *)output = ((ShuffleRecord *)p)->motion.bezier.points[3];
        return;
    case 6:
        btlShuffleCalcRotatePointAroundAxis(p + 0x38, p + 0x2C, p + 0x44, output, p, ((ShuffleRecord *)p)->motion.orbit.endAngle);
        return;
    case 7:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.vector.target;
        return;
    case 8:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.vector.target;
    case 9:
        *(ShuffleVec3 *)output = *(ShuffleVec3 *)&((ShuffleRecord *)p)->motion.vector.target;
        return;
    default:
        kAssertFail(D_0064EA20, 0x4DA);
        return;
    }
}


/* measured: retail emits the two saved-register setup moves (mov.s $f20,$f12 then
   move $s1,$a2) with the FP move first; mwcc b210 emits the GPR move first (nd 4).
   Everything else is solved: u8 *arg0, idx/p locals, the full 0-9 case switch, and
   func_00371f40's interleaved prototype (u8*, f32, u8*) which fixes the pre-jal
   materialisation order. Saved-register setup-order scheduling floor. */
/* Sample the orbit position at a fractional frame offset; other movement modes leave the output untouched. */
// FUN_003764B0
/* Case values decoded from jtbl_007529D0 with tools/jtbl.py: only entry 6 has
   a body, entries 0-5 and 7-9 fall straight to the epilogue, and >= 10 hits
   the assert. The empty cases must still be listed or b210 emits a compare
   chain instead of the 10-entry table, and `default` is declared before them
   because b210 lays case bodies out in declaration order.
   The parameter list is interleaved (u8*, s32, f32, u8*), not grouped: the
   float arrives in $f12 between the second and third integer argument, and
   the grouped spelling costs nd 8. */
void btlShuffleDrawSetOffset(u8 *context, s32 cardIndex, f32 frameOffset, u8 *output) {
    u8 *p;

    p = (u8 *)(context + cardIndex * 0xE8 + 0x1D6A0);
    if (output == NULL) {
        kAssertFail(D_0064EA20, 0x4E5);
    }
    switch ((u32)((ShuffleRecord *)p)->motionState) {
    case 6:
        btlShuffleCalcRotateVector(p + 0xC, frameOffset, output);
        break;
    default:
        kAssertFail(D_0064EA20, 0x508);
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
        break;
    }
}

/* Find the card endpoint closest to the camera, optionally returning that point. */
// FUN_00376590
s32 btlShuffleDrawCheck(u8 *context, u8 *output) {
    ShuffleVec3 candidate;
    ShuffleVec3 closest;
    s32 i;
    s32 count;
    s32 best;
    f32 bestf;
    f32 f;

    BtlShuffleContext *state = (BtlShuffleContext *)context;

    count = state->pattern;
    if ((count < 0) || (count > 2)) {
        kAssertFail(D_0064EA20, 0x516);
    }
    count = btlShuffleDrawTableLookup(state->cardCount, state->pattern);
    btlShuffleDrawSetRotate(context, 0, (f32 *)&closest);
    bestf = btlShuffleCalcNormalizeOffset((u8 *)&closest);
    i = 1;
    best = 0;
    while (i < count) {
        btlShuffleDrawSetRotate(context, i, (f32 *)&candidate);
        f = btlShuffleCalcNormalizeOffset((u8 *)&candidate);
        if (f < bestf) {
            bestf = f;
            best = i;
            closest = candidate;
        }
        i++;
    }
    if (output != NULL) {
        *(ShuffleVec3 *)output = closest;
    }
    return best;
}


/* Insert a callback and payload into the descending camera-distance draw list. */
// FUN_003766F0
void btlShuffleDrawAllocList(f32 **list, void (*callback)(u8 **), u8 **payload, u8 *position) {
    BtlShuffleDrawNode **link;
    BtlShuffleDrawNode *node;
    BtlShuffleDrawNode *next;
    f32 key;

    chkmemAllocSiteTag(D_0064EA20, 0x589);
    node = (BtlShuffleDrawNode *)D_008873F4[0](1, 0x10, 0x40000);
    if (node == NULL) {
        kAssertFail(D_0064EA20, 0x58A);
    }
    key = btlShuffleCalcNormalizeOffset(position);
    node->callback = callback;
    node->payload = payload;
    node->depth = key;
    link = (BtlShuffleDrawNode **)list;
    while ((next = *link) != NULL) {
        if (!(node->depth <= next->depth)) break;
        link = &next->next;
    }
    if (next == NULL) {
        *link = node;
        node->next = NULL;
        return;
    }
    node->next = next;
    *link = node;
}


void btlShuffleDrawListFree(u8 **list);

/* Dispatch the sorted draw callbacks and optionally release the list nodes. */
// FUN_00376800
void btlShuffleDrawListAdd(u8 **list, s32 release) {
    BtlShuffleDrawNode *node;

    node = (BtlShuffleDrawNode *)*list;
    while (node != NULL) {
        node->callback(node->payload);
        node = node->next;
    }
    if (release != 0) {
        btlShuffleDrawListFree(list);
    }
}


/* Retail re-loads *arg0 at every use. The fix is simply NOT to cache it: a `cur`
   local lets b210 CSE the load with the loop test and the body comes out two
   instructions short (nd 44), and a for(;;)-with-break shape scores nd 33.
   Dereferencing *arg0 at each use is byte-exact - measured. */
// FUN_00376880
void btlShuffleDrawListFree(u8 **list) {
    u8 *next;

    while (*list != NULL) {
        next = (u8 *)((BtlShuffleDrawNode *)*list)->next;
        jtbl_008873EC[0](*list);
        *list = next;
    }
}


/* Guarded trail recovery: native 4176/4176 bytes and frame 0xF50;
 * 511 fully resolved differing words. Uses 21 samples, two 42-vertex
 * strips, native alpha conversions and finite 4/4/2 render passes.
 * Matrix flags are explicitly initialized; retail's SDK identity
 * macro reads an unwritten flag word. ASM remains the production
 * implementation. See docs/probe_archive/Shuffle_trail_003768e0_20261006.
   2026-10-08: opt_lifetimes on lowers fnalign from 464 to 280 edits.
   Also (2026-10-08): the identity flags are ORed into the uninitialised local (retail lw 0xBC/or) and the render-state table is read through a u32 local kept in $s3, 270 edits. */
/* Card trail draw (three styles). Each style uses its own locals so live
   ranges match retail; time and step are declared before opacity, which puts
   the trail clock in $f24, the step in the length register and opacity in
   $f22 as retail does. */
#pragma push
#pragma opt_lifetimes on
/* Scratch recovery of the three trail styles. The 0x24-byte vertex and
 * position/color setters follow include/rw/sky2/rwcore.h. Matrix flags are
 * defined explicitly: retail's load/OR of an unwritten stack flag word is
 * retained as an unresolved difference, not copied as an uninitialized read. */
typedef char TrailVertexSizeCheck[(sizeof(TrailVertex) == 0x24) ? 1 : -1];

#define TRAIL_POSITION(_vertex, _x, _y, _z) do { \
    ShuffleVec3 packed; \
    packed.x = (_x); \
    packed.y = (_y); \
    packed.z = (_z); \
    (_vertex)->objVertex = packed; \
} while (0)

#define TRAIL_COLOR(_vertex, _r, _g, _b, _a) do { \
    TrailRGBA *const color = &(_vertex)->c.color; \
    color->red = (_r); \
    color->green = (_g); \
    color->blue = (_b); \
    color->alpha = (_a); \
} while (0)

extern ShuffleVec3 D_0060A0E0;
extern f32 iGpffff8400;
extern f32 iGpffff8404;
extern f32 iGpffff8408;
extern f32 iGpffff8308;

#pragma push
#pragma opt_loop_invariants on
// FUN_003768E0
void btlShuffleDrawTrail(u8 *work, s32 cardIndex, s32 mode, f32 length, u8 *rgba)
{
    /* Byte-base cursors preserve embedded variant and resource-slot addressing; typed fields are used where their layout is shared. */
    TrailVertex first[42];
    TrailVertex second[42];
    ShuffleVec3 samples[21];
    BtlShuffleMatrix identity;
    TrailVertex *front;
    TrailVertex * front_s1;
    TrailVertex * front_s2;
    TrailVertex * front_s3;
    TrailVertex * front_s4;
    TrailVertex * front_s5;
    TrailVertex *back;
    TrailVertex * back_s1;
    TrailVertex * back_s2;
    TrailVertex * back_s3;
    TrailVertex * back_s4;
    TrailVertex * back_s5;
    ShuffleVec3 *sample;
    u8 *card;
    u8 *motion;
    s32 kind;
    f32 time;
    f32 step;
    f32 opacity;
    f32 right;
    f32 height;
    f32 left;

    kind = (s8)mode;
    if (kind >= 3) {
        kAssertFail(D_0064EA20, 0x5DE);
    }
    identity.right.x = identity.up.y = identity.at.z = 1.0f;
    identity.right.y = identity.right.z = identity.up.x = 0.0f;
    identity.up.z = identity.at.x = identity.at.y = 0.0f;
    identity.pos.x = identity.pos.y = identity.pos.z = 0.0f;
    /* Retail ORs the identity flags into the uninitialised local (SDK
     * RwMatrixSetIdentity macro); the read is retail behaviour. */
    identity.flags |= 0x20003;
    RpSkyRenderStateSet(2, (void *)0x48);
    RpSkyRenderStateSet(3, (void *)0x71801);
    {
        u32 renderStateBase = (u32)D_00887300;

        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATECULLMODE, (void *)1);
        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATEZTESTENABLE, (void *)1);
        (*(BtlShuffleRenderStateSet *)renderStateBase)(rwRENDERSTATEZWRITEENABLE, NULL);
    }
    motion = work + cardIndex * 0xE8 + 0x1D6A0;
    card = work + cardIndex * 0xFB0;
    if (((ShuffleRecord *)motion)->motionState == 6) {
        opacity = (f32)(u32)rgba[3] * ((f32)(u32)motion[0xD8] / 255.0f);
        switch (kind) {
        case 0:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 fadedOpacity;
                f32 halfWidth;
                f32 halfHeight;
                front = first;
                back = second;
                fadedOpacity = iGpffff8400 * opacity;
                taper = 1.0f;
                time = 0.0f;
                step = length / 21.0f;
                for (point = 0; point < 21; point++, front += 2, back += 2) {
                    btlShuffleDrawSetOffset(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= step;
                    TRAIL_COLOR(&front[0], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    TRAIL_COLOR(&front[1], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[0], rgba[0], rgba[1], rgba[2], (u8)(fadedOpacity * taper));
                    TRAIL_COLOR(&back[1], rgba[0], rgba[1], rgba[2], (u8)(opacity * taper));
                    taper += -0.04761905f;
                }
                halfWidth = 0.5f * btlShuffleCardWidth(card);
                halfHeight = 0.5f * btlShuffleCardHeight(card);
                for (side = 0; side < 4; side++) {
                    front_s1 = first;
                    back_s1 = second;
                    switch (side) {
                    case 0:
                        for (point = 0; point < 21; point++, front_s1 += 2, back_s1 += 2) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front_s1[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front_s1[1], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[0], halfWidth + sample->x, sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[1], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                        }
                        break;
                    case 1:
                        for (point = 0; point < 21; point++, front_s1 += 2, back_s1 += 2) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front_s1[0], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front_s1[1], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[0], sample->x - halfWidth, sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                        }
                        break;
                    case 2:
                        for (point = 0; point < 21; point++, front_s1 += 2, back_s1 += 2) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front_s1[0], halfWidth + sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&front_s1[1], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[0], sample->x, halfHeight + sample->y, sample->z);
                            TRAIL_POSITION(&back_s1[1], sample->x - halfWidth, halfHeight + sample->y, sample->z);
                        }
                        break;
                    case 3:
                        for (point = 0; point < 21; point++, front_s1 += 2, back_s1 += 2) {
                            sample = &samples[point];
                            TRAIL_POSITION(&front_s1[0], halfWidth + sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&front_s1[1], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back_s1[0], sample->x, sample->y - halfHeight, sample->z);
                            TRAIL_POSITION(&back_s1[1], sample->x - halfWidth, sample->y - halfHeight, sample->z);
                        }
                        break;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
                break;
            }
        case 1:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                u8 alpha;
                f32 negativeWidth;
                f32 negativeHeight;
                f32 offsetX;
                f32 offsetY;
                front_s2 = first;
                back_s2 = second;
                alpha = (u8)opacity;
                time = 0.0f;
                step = length / 21.0f;
                for (point = 0; point < 21; point++, front_s2 += 2, back_s2 += 2) {
                    btlShuffleDrawSetOffset(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= step;
                    TRAIL_COLOR(&front_s2[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front_s2[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back_s2[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back_s2[1], rgba[0], rgba[1], rgba[2], 0);
                }
                halfWidth = 0.5f * btlShuffleCardWidth(card);
                halfHeight = 0.5f * btlShuffleCardHeight(card);
                side = 0;
                negativeWidth = -halfWidth;
                negativeHeight = -halfHeight;
                for (; side < 4; side++) {
                    switch (side) {
                    case 0: offsetX = halfWidth; offsetY = halfHeight; break;
                    case 1: offsetX = negativeWidth; offsetY = halfHeight; break;
                    case 2: offsetX = halfWidth; offsetY = negativeHeight; break;
                    case 3: offsetX = negativeWidth; offsetY = negativeHeight; break;
                    }
                    front_s3 = first;
                    back_s3 = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++, front_s3 += 2, back_s3 += 2) {
                        f32 magnitude = 3.0f * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;

                        sample = &samples[point];
                        x = dx + sample->x;
                        y = dy + sample->y;
                        z = dz + sample->z;
                        TRAIL_POSITION(&front_s3[0], x + offsetX, y + offsetY, z);
                        TRAIL_POSITION(&front_s3[1], offsetX + sample->x, offsetY + sample->y, sample->z);
                        x = sample->x - dx;
                        y = sample->y - dy;
                        z = sample->z - dz;
                        TRAIL_POSITION(&back_s3[0], offsetX + sample->x, offsetY + sample->y, sample->z);
                        TRAIL_POSITION(&back_s3[1], x + offsetX, y + offsetY, z);
                        taper += -0.04761905f;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        case 2:
            {
                s32 point;
                s32 side;
                f32 taper;
                f32 halfWidth;
                f32 halfHeight;
                f32 x;
                f32 y;
                f32 z;
                f32 offsetX;
                f32 offsetY;
                u8 alpha;
                /* Only the frame link is consumed; keep SDK camera storage opaque here. */
                func_003e9700(*(struct RwFrame **)((u8 *)kwlnGetCamera() + 4));
                front_s4 = first;
                back_s4 = second;
                alpha = (u8)opacity;
                time = 0.0f;
                step = length / 21.0f;
                for (point = 0; point < 21; point++, front_s4 += 2, back_s4 += 2) {
                    btlShuffleDrawSetOffset(work, cardIndex, time, (u8 *)&samples[point]);
                    time -= step;
                    TRAIL_COLOR(&front_s4[0], rgba[0], rgba[1], rgba[2], 0);
                    TRAIL_COLOR(&front_s4[1], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back_s4[0], rgba[0], rgba[1], rgba[2], alpha);
                    TRAIL_COLOR(&back_s4[1], rgba[0], rgba[1], rgba[2], 0);
                }
                halfWidth = 0.5f * btlShuffleCardWidth(card);
                halfHeight = 0.5f * btlShuffleCardHeight(card);
                side = 0;
                right = iGpffff8218 * halfWidth;
                height = iGpffff8308 * halfHeight;
                left = iGpffff8218 * -halfWidth;
                for (; side < 2; side++) {
                    switch (side) {
                    case 0: offsetX = right; offsetY = height; break;
                    case 1: offsetX = left; offsetY = height; break;
                    }
                    front_s5 = first;
                    back_s5 = second;
                    taper = 1.0f;
                    for (point = 0; point < 21; point++, front_s5 += 2, back_s5 += 2) {
                        f32 magnitude = iGpffff8408 * taper;
                        f32 dx = D_0060A0E0.x * magnitude;
                        f32 dy = D_0060A0E0.y * magnitude;
                        f32 dz = D_0060A0E0.z * magnitude;

                        sample = &samples[point];
                        x = dx + sample->x;
                        y = dy + sample->y;
                        z = dz + sample->z;
                        TRAIL_POSITION(&front_s5[0], x + offsetX, y + offsetY, z);
                        TRAIL_POSITION(&front_s5[1], offsetX + sample->x, offsetY + sample->y, sample->z);
                        x = sample->x - dx;
                        y = sample->y - dy;
                        z = sample->z - dz;
                        TRAIL_POSITION(&back_s5[0], offsetX + sample->x, offsetY + sample->y, sample->z);
                        TRAIL_POSITION(&back_s5[1], x + offsetX, y + offsetY, z);
                        taper += -0.04761905f;
                    }
                    func_00410420((struct RxObjSpace3DVertex *)first, 42, &identity, 2);
                    func_004106a0(4);
                    func_00410420((struct RxObjSpace3DVertex *)second, 42, &identity, 2);
                    func_004106a0(4);
                }
            }
            break;
        }
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
    }
}
#pragma pop
#undef TRAIL_COLOR
#undef TRAIL_POSITION
#pragma pop


/* Build an untextured screen-space quad from the card's position and rotation.
 * The four 64-byte sky2 vertices retain the PS2 screen/color/reciprocal-Z layout.
 * measured b210 -O2: 1236/1248 bytes, complete resolved retail instructions.
 * See docs/probe_archive/Shuffle_00377930_recovery.md. */
static inline u8 *shuffleVertexSource377930(s32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
// FUN_00377930
void btlShuffleDrawCardSprites(u8 *context, s32 cardIndex, const BtlShuffleVec3 *position, u8 *color, s32 restoreAlpha)
{
    /* Byte-base cursors preserve embedded variant and resource-slot addressing; typed fields are used where their layout is shared. */
    extern f32 D_008872F8_abs[];
    typedef char AssertSkyVertexSize[(sizeof(BtlShuffleSkyVertex) == 64) ? 1 : -1];
    f32 datw;
    f32 halfW;
    f32 halfH;
    f32 scale;
    f32 norm;
    f32 n0;
    f32 n1;
    f32 n2;
    f32 xw, yw, zw, xx, yy, zz, yz, zx, xy;
    f32 screen[2];
    BtlShuffleVec3 positionCopy;
    BtlShuffleSkyVertex mat[4];
    BtlShuffleVec3 corners[4];
    ShuffleVec4 rotation;
    u8 *chain;
    u8 *card;
    BtlShuffleMatrix *matrix;
    BtlShuffleSkyFields *slot;
    s32 index;

    datw = D_008872F8_abs[0];
    /* The SDK camera remains opaque here; 0x80 is its verified near-plane scalar. */
    scale = 1.0f / *(f32 *)((u8 *)kwlnGetCamera() + 0x80);
    if (position != 0) {
        positionCopy = *(BtlShuffleVec3 *)position;
    } else {
        chain = shuffleVertexSource377930(cardIndex * 0xE8, context);
        positionCopy = ((ShuffleContext *)chain)->records[0].motion.wander.output;
    }
    chain = shuffleVertexSource377930(cardIndex * 0xE8, context);
    rotation = *(ShuffleVec4 *)&((ShuffleContext *)chain)->records[0].rotation.quaternion.output;
    card = context + cardIndex * 0xFB0;
    halfW = btlShuffleCardWidth(card) / 2.0f;
    halfH = btlShuffleCardHeight(card) / 2.0f;
    matrix = func_003e0f80();
    kwlnGetCamera();
    norm = 2.0f / (rotation.x * rotation.x + rotation.y * rotation.y + rotation.z * rotation.z + rotation.w * rotation.w);
    n0 = rotation.x * norm;
    n1 = rotation.y * norm;
    n2 = rotation.z * norm;
    xw = n0 * rotation.w;
    yw = n1 * rotation.w;
    zw = n2 * rotation.w;
    xx = rotation.x * n0;
    yy = rotation.y * n1;
    zz = rotation.z * n2;
    yz = rotation.y * n2;
    zx = rotation.z * n0;
    xy = rotation.x * n1;
    matrix->right.x = 1.0f - (yy + zz);
    matrix->right.y = xy + zw;
    matrix->right.z = zx - yw;
    matrix->up.x = xy - zw;
    matrix->up.y = 1.0f - (zz + xx);
    matrix->up.z = yz + xw;
    matrix->at.x = zx + yw;
    matrix->at.y = yz - xw;
    matrix->at.z = 1.0f - (xx + yy);
    matrix->pos.x = 0.0f;
    matrix->pos.y = 0.0f;
    matrix->pos.z = 0.0f;
    matrix->flags = 3;
    RwMatrixTranslate(matrix, &positionCopy, 2);
    corners[0].x = halfW;
    corners[0].y = halfH;
    corners[0].z = 0.0f;
    corners[1].x = -halfW;
    corners[1].y = halfH;
    corners[1].z = 0.0f;
    corners[2].x = halfW;
    corners[2].y = -halfH;
    corners[2].z = 0.0f;
    corners[3].x = -halfW;
    corners[3].y = -halfH;
    corners[3].z = 0.0f;
    for (index = 0; index < 4; index++) {
        func_003e42a0(&positionCopy, &corners[index], matrix);
        btlShuffleCalcUpdateSpeed((u8 *)&positionCopy, (u8 *)screen);
        slot = &mat[index].u.els;
        slot->scrVertex.x = screen[0];
        slot->scrVertex.y = screen[1];
        slot->scrVertex.z = datw;
        slot->color.r = (f32)(u32)color[0];
        slot->color.g = (f32)(u32)color[1];
        slot->color.b = (f32)(u32)color[2];
        slot->color.a = (f32)(u32)color[3];
        slot->recipZ = scale;
    }
    D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);
    if (restoreAlpha != 0 && color[3] == 0xFF) {
        shdEnableBlendFlag();
    }
    D_00887310[0](rwPRIMTYPETRISTRIP, mat, 4);
    if (restoreAlpha != 0 && color[3] == 0xFF) {
        shdDisableBlendFlag();
    }
    func_003e0f40(matrix);
}
/* Poll the face texture load until the face task reports ready. */
// FUN_00377E10
s32 btlShuffleDrawTaskDone(u8 *task) {
    s32 *p = (s32 *)((SdkTask *)task)->work;

    if (btlShuffleDrawFlagA(task) == 0) {
        *p = datTextSlotLoadStep((u8 *)p + 8);
    }
    return 0;
}


/* Release the face texture slot and the face task work allocation. */
// FUN_00377E60
void btlShuffleDrawTaskEnd(u8 *task) {
    u8 *p = ((SdkTask *)task)->work;

    datTextSlotRelease(p + 8);
    jtbl_008873EC[0](p);
}


/* The two faces belong to the allocated 0x240-byte work buffer; the
   registered task is retained separately and returned to the caller. Each
   loop snapshots one position before writing a 0x24-byte vertex. Independent
   loop indices and the existing invariant hoist reproduce all 800 bytes.
   Full code/caller/data proof: docs/probe_archive/Shuffle_00377eb0_recovery.md. */
// FUN_00377EB0
#pragma push
#pragma opt_loop_invariants on
s32 btlShuffleDrawSpawn(u8 *parentTask, s32 selectedCard)
{
    struct ShuffleCardPosition { f32 x, y, z; };
    struct ShuffleCardPosition front;
    struct ShuffleCardPosition back;
    struct ShuffleCardPosition positions[4];
    f32 u[4];
    f32 v[4];
    s32 cardIndex;
    u8 *work;
    u8 *task;
    u8 *parent;
    u8 *vertex;
    f32 height;
    f32 halfWidth;

    parent = parentTask;
    cardIndex = selectedCard;
    chkmemAllocSiteTag(D_0064EA20, 0x76C);
    work = D_008873F4[0](1, 0x240, 0x40000);
    if (work == NULL) {
        kAssertFail(D_0064EA20, 0x76D);
    }
    task = (u8 *)(s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064EA60), 0x12, 0, 0, btlShuffleDrawTaskDone, btlShuffleDrawTaskEnd, work);
    if (task == NULL) {
        kAssertFail(D_0064EA20, 0x777);
    }
    btlShuffleDrawSpriteName(task, cardIndex);
    btlShuffleDrawSetColor(task, 0xFF, 0xFF, 0xFF, 0);

    halfWidth = 30.0f;
    positions[0].x = -halfWidth;
    height = iGpffff83e0;
    positions[0].y = height;
    positions[0].z = 0.0f;
    u[0] = 0.9921875f;
    v[0] = 0;
    positions[1].x = halfWidth;
    positions[1].y = height;
    positions[1].z = 0.0f;
    u[1] = 0;
    v[1] = 0;
    positions[2].x = -halfWidth;
    height = -height;
    positions[2].y = height;
    positions[2].z = 0.0f;
    u[2] = 0.9921875f;
    v[2] = 0.64453125f;
    positions[3].x = halfWidth;
    positions[3].y = height;
    positions[3].z = 0.0f;
    u[3] = 0;
    v[3] = 0.64453125f;

    {
        s32 index;
        for (index = 0; index < 4; index++) {
            vertex = (u8 *)&positions[index];
            front.x = ((struct ShuffleCardPosition *)vertex)->x;
            front.y = ((struct ShuffleCardPosition *)vertex)->y;
            front.z = ((struct ShuffleCardPosition *)vertex)->z;
            vertex = work + index * 0x24;
            *(struct ShuffleCardPosition *)&((BtlShuffleFaceWork *)vertex)->front[0].objVertex.x = front;
            ((BtlShuffleFaceWork *)vertex)->front[0].c.color.red = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->front[0].c.color.green = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->front[0].c.color.blue = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->front[0].c.color.alpha = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->front[0].u = u[index];
            ((BtlShuffleFaceWork *)vertex)->front[0].v = v[index];
        }
    }

    halfWidth = 30.0f;
    positions[0].x = halfWidth;
    height = iGpffff83e0;
    positions[0].y = height;
    positions[0].z = 0.0f;
    u[0] = 0.9921875f;
    v[0] = 0;
    positions[1].x = -halfWidth;
    positions[1].y = height;
    positions[1].z = 0.0f;
    u[1] = 0;
    v[1] = 0;
    positions[2].x = halfWidth;
    height = -height;
    positions[2].y = height;
    positions[2].z = 0.0f;
    u[2] = 0.9921875f;
    v[2] = 0.64453125f;
    positions[3].x = -halfWidth;
    positions[3].y = height;
    positions[3].z = 0.0f;
    u[3] = 0;
    v[3] = 0.64453125f;

    {
        s32 index;
        for (index = 0; index < 4; index++) {
            vertex = (u8 *)&positions[index];
            back.x = ((struct ShuffleCardPosition *)vertex)->x;
            back.y = ((struct ShuffleCardPosition *)vertex)->y;
            back.z = ((struct ShuffleCardPosition *)vertex)->z;
            vertex = work + index * 0x24;
            *(struct ShuffleCardPosition *)&((BtlShuffleFaceWork *)vertex)->back[0].objVertex.x = back;
            ((BtlShuffleFaceWork *)vertex)->back[0].c.color.red = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->back[0].c.color.green = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->back[0].c.color.blue = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->back[0].c.color.alpha = 0xFF;
            ((BtlShuffleFaceWork *)vertex)->back[0].u = u[index];
            ((BtlShuffleFaceWork *)vertex)->back[0].v = v[index];
        }
    }
    return (s32)task;
}
#pragma pop
/* Format the selected card texture name, assign its text slot, and mark the face task loading. */
// FUN_003781D0
void btlShuffleDrawSpriteName(u8 *task, s32 cardIndex) {
    char buf[0x100];
    u8 *work;

    work = ((SdkTask *)task)->work;
    sprintf(buf, D_0064EA80, cardIndex & 0xFF);
    datTextSlotSetString((s32 *)(work + 8), (u8 *)buf);
    ((BtlShuffleFaceWork *)work)->ready = 0;
}


// FUN_00378220
s32 btlShuffleDrawFlagA(u8 *task) {
    return *(u32 *)&((BtlShuffleFaceWork *)((SdkTask *)task)->work)->ready != 0;
}


// FUN_00378240
s32 btlShuffleDrawFlagB(u8 *task) {
    return (s32)((SdkTask *)task)->work + 0x120;
}


// FUN_00378250
s32 btlShuffleDrawFlagC(u8 *task) {
    return (s32)((SdkTask *)task)->work + 0x1B0;
}


/* Store the face tint and whether the front face uses corner shading. */
// FUN_00378260
void btlShuffleDrawSetColor(u8 *task, u8 red, u8 green, u8 blue, s32 shaded) {
    u8 *work = ((SdkTask *)task)->work;
    ((BtlShuffleFaceWork *)work)->color[0] = red;
    ((BtlShuffleFaceWork *)work)->color[1] = green;
    ((BtlShuffleFaceWork *)work)->color[2] = blue;
    ((BtlShuffleFaceWork *)work)->shaded = shaded;
}


/* measured: u32->f32 and f32->u8 written as plain (f32)/(u8) casts;
   opt_loop_invariants on hoists the FMA constants and 0x4f00/0xff. */
#pragma push
#pragma opt_loop_invariants on
/* Apply alpha and optional corner shading to front vertices; back vertices remain white. */
// FUN_00378280
void btlShuffleDrawSetAlpha(u8 *task, u8 alpha) {
    u8 *work;
    u8 *vertexBase;
    u8 *color;
    f32 red;
    f32 green;
    f32 blue;
    f32 shade;
    f32 redValue;
    f32 greenValue;
    f32 blueValue;
    f32 horizontalShade;
    f32 verticalShade;
    s32 vertexIndex;
    s32 corner;
    u32 redByte;
    u32 greenByte;
    u32 blueByte;

    work = ((SdkTask *)task)->work;
    ((BtlShuffleFaceWork *)work)->color[3] = alpha;
    if (((BtlShuffleFaceWork *)work)->shaded != 0) {
        horizontalShade = DAT_007613f8;
        verticalShade = iGpffff8218;
    } else {
        horizontalShade = 0.0f;
        verticalShade = 0.0f;
    }
    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++) {
        corner = 3 - vertexIndex;
        shade = (1.0f + 0.0f) - horizontalShade * (f32)(corner % 2) -
            verticalShade * (f32)(corner / 2);

        vertexBase = work + vertexIndex * 0x24;
        color = (u8 *)&((BtlShuffleFaceWork *)vertexBase)->front[0].c.color;

        redByte = ((BtlShuffleFaceWork *)work)->color[0];
        redValue = (f32)redByte;
        red = redValue * shade;
        color[0] = (u8)red;

        greenByte = ((BtlShuffleFaceWork *)work)->color[1];
        greenValue = (f32)greenByte;
        green = greenValue * shade;
        color[1] = (u8)green;

        blueByte = ((BtlShuffleFaceWork *)work)->color[2];
        blueValue = (f32)blueByte;
        blue = blueValue * shade;
        color[2] = (u8)blue;

        color[3] = ((BtlShuffleFaceWork *)work)->color[3];
        ((BtlShuffleFaceWork *)vertexBase)->back[0].c.color.red = 0xFF;
        ((BtlShuffleFaceWork *)vertexBase)->back[0].c.color.green = 0xFF;
        ((BtlShuffleFaceWork *)vertexBase)->back[0].c.color.blue = 0xFF;
        ((BtlShuffleFaceWork *)vertexBase)->back[0].c.color.alpha = ((BtlShuffleFaceWork *)work)->color[3];
    }
}
#pragma pop

/* Return the loaded face texture raster, or zero while its resource is not ready. */
// FUN_00378500
s32 btlShuffleDrawFlagD(u8 *task) {
    u8 *work = ((SdkTask *)task)->work;
    if ((u8)(*(u32 *)&((BtlShuffleFaceWork *)work)->ready != 0) != 0) {
        return (u32)((BtlShuffleFaceWork *)work)->textSlot.result.texture->raster;
    }
    return 0;
}


/* Expand the logical card count for the selected pattern. */
// FUN_00378530
s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern) {
    s32 count;

    switch (pattern) {
    case 0:
        return cardCount;
    case 1:
        return cardCount;
    case 2:
        return cardCount;
    case 3:
        return cardCount * 2;
    case 4:
        if (cardCount < 6) {
            count = cardCount * 6;
        } else {
            count = cardCount * 3;
        }
        return count;
    default:
        kAssertFail(&D_0064EA20, 0x854);
        return 0;
    }
}
