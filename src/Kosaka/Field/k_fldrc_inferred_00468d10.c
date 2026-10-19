/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Event/Fcl/fclBankManager.c; members 00468d10-0046a430 */

#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "sdk_lbox_internal.h"
#include "type.h"
#include "primitive_queue_internal.h"
#include "mdl_effect_internal.h"
#include "kwln_task_internal.h"
#include "rw/plcore/barenderstate.h"
#include "h_cdvd_internal.h"
#include "Kosaka/k_clump_internal.h"
typedef struct {
	s32 mode;               /* 0x00 file type (1: Sofdec, 2: MPEG video only, 3: video-only Sofdec; 2: no additional-info stream) */
	s32 max_bps;            /* 0x04 maximum bit rate */
	s32 max_width;          /* 0x08 */
	s32 max_height;         /* 0x0C */
	s32 max_skip;           /* 0x10 frames mwPlyGetCurFrm may skip to catch up (= decoded frame pool size) */
	s32 nsec;               /* 0x14 seconds of input buffering */
	void *work;                /* 0x18 user work for the component buffers (NULL: malloc/free callbacks) */
	s32 wksize;             /* 0x1C */
	s32 compo;              /* 0x20 requested component layout (0 / 0x101: additional-info sj used) */
	s32 buffmt;             /* 0x24 MwsfdBufFmt */
	s32 x28;
	s32 x2c;
} MWSFD_CRPRM;

struct RwSList;

typedef struct RwRaster RwRaster;

typedef s32 RwBool;

typedef s32 (*WindowRenderStateSet)(RwRenderState state, void *value);

extern s32 iGpffffb034;
extern s32 iGpffffbaf8;
extern s32 D_00922930[];
extern void *memset(void *dst, s32 value, size_t size);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbae8;
extern s32 iGpffffbaec;
extern u8 D_0070B610[];
extern void mwPlyReleaseLp(s32 arg0);
extern void func_005097e8(s32 arg0);
extern RwBool RwRasterDestroy(RwRaster *raster);
extern s32 func_003d5fb0(u8 *arg0);
extern void poolFree(u32 arg0);
extern s32 D_00724BEC;
extern s32 D_00724BF0;
extern void kAssertFail(void *arg0, s32 arg1);
struct MovieNativeWork;

extern void movieNativeTaskUpdate(void *arg0, struct MovieNativeWork *work);
extern void PrimAppendNode(char *name, u8 *task);
extern s32 D_00724BF4;
extern s32 func_0042ba70();
extern s32 func_0042ba20();
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern u8 *H_Calloc(s32 arg0, s32 arg1);
extern s32 mwPlayerUpdate(u8 *arg0);
extern void mwPlayerTaskDestroy(u8 *arg0);
extern u32 iGpffffbb14;
extern u32 iGpffffbb10;
extern u32 iGpffffbb0c;
extern u32 iGpffffbb04;
extern s32 kwlnGetCamera(void);
/* Same RwV3d tag and fields as the ring provider and RenderWare. */
#include "rw_types_internal.h"
struct Data_00712508 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};

extern struct Data_00712508 D_00712508[] __attribute__((aligned(8)));
extern u8 *PrimAllocQueueNode(void);
/* Ten archive requests are driven in parallel; completed payloads are
 * registered through the entry array at 0x38. */
typedef struct FldArchiveLoadNode {
    u8 pad00[4];
    struct FldArchiveLoadNode *next;
    u8 *archive;
    s32 state;
    s32 requests[10];
    s32 *entries;
    s32 firstEntry;
    s32 endEntry;
    s32 cursor;
} FldArchiveLoadNode;

/* Pool metadata precedes the allocation region, in native eight-byte records. */
typedef struct MoviePoolEntry { u32 address; u32 size; } MoviePoolEntry;

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
/* Advance queued archive requests ten slots at a time and register their loaded archive entries. */
/* measured: remaining raw state/entry/request accesses changed codegen even individually (8..488 differing bytes); the archive path remains a byte stream from its native header. */
// FUN_00468D10
void movieLoadStep(void)
{
    extern s32 sdkPakStartEntryLoad(u8 *node, s32 slot);
    extern s32 func_004c9820(ADXF request);
    extern void *memset(void *dst, s32 value, size_t count);
    extern void H_Cdvd_RegisterArchiveEntries(u8 *basePath, u8 *archive, s32 singleEntry);
    u8 *node;
    char *cursor;
    s8 value;
    s32 state;
    s32 slot;
    s32 phase;
    s32 character;
    s32 separator;
    s32 backslash;
    char path[0x100];

    node = (u8 *)D_00922930;
    do {
        state = ((FldArchiveLoadNode *)node)->state;
        switch (state) {
        case 0:
            node = *(u8 * *)&((FldArchiveLoadNode *)node)->next;
            break;
        case 1:
            ((FldArchiveLoadNode *)node)->cursor = 0;
            for (phase = 0; phase < 10; phase++) {
                if (sdkPakStartEntryLoad(node, phase) == 0) {
                    break;
                }
            }
            *(s32 *)(node + 0xC) = 2;
            /* fall through */
        case 2:
            phase = 1;
            for (slot = 0; slot < 10; slot++) {
                if (((FldArchiveLoadNode *)node)->requests[slot] != 0) {
                    if (func_004c9820(*(ADXF *)&((FldArchiveLoadNode *)node)->requests[slot]) == 3) {
                        func_004c8a60(*(ADXF *)(node + 0x10 + slot * 4));
                        *(s32 *)(node + 0x10 + slot * 4) = 0;
                        if (sdkPakStartEntryLoad(node, slot) == 1) {
                            phase = 0;
                        }
                    } else {
                        phase = 0;
                    }
                }
            }
            if (phase != 0) {
                *(s32 *)(node + 0xC) = 3;
            } else {
                node = NULL;
                break;
            }
            /* fall through */
        case 3:
            memset(path, 0, 0x100);
            backslash = 0x5C;
            for (character = 0; character < 0x100; character++) {
                value = *(s8 *)(((FldArchiveLoadNode *)node)->archive + character + 0x118);
                if (value != 0) {
                    path[character] = value;
                } else {
                    for (separator = character - 1;; separator--) {
                        cursor = path + separator;
                        if (cursor[-1] == backslash) {
                            *cursor = 0;
                            break;
                        }
                    }
                }
            }
            for (phase = 0;
                 phase < ((FldArchiveLoadNode *)node)->endEntry - ((FldArchiveLoadNode *)node)->firstEntry;
                 phase++) {
                if ((*(s32 **)(node + 0x38))[phase] != 0) {
                    H_Cdvd_RegisterArchiveEntries((u8 *)path,
                                  (u8 *)(*(s32 **)(node + 0x38))[phase], 1);
                    (((FldArchiveLoadNode *)node)->entries)[phase] += 0x100;
                }
            }
            *(s32 *)(node + 0xC) = 4;
            break;
        case 4:
            node = *(u8 * *)&((FldArchiveLoadNode *)node)->next;
            break;
        }
    } while (node != NULL);
}
#pragma pop

/* Sofdec playback, fade and quad submission. The task dispatcher supplies
 * the opaque first argument and the allocated 0x220-byte movie context.
 * CRI frame storage and sky2 vertex channels retain their native layouts.
 * See docs/probe_archive/Movie_00468ff0_exact_20261006/README.md. */
/* Native PS2 Sofdec frame: see 0050a1c0 / 0050a3c0 / 0050a810. */
typedef struct MovieNativeFrame {
    void *buffer;                 /* 0x00 */
    s32 displayFrame;              /* 0x04: copied from frameNumber by provider */
    s32 bufferFormat;              /* 0x08 */
    s32 width;                     /* 0x0c */
    s32 height;                    /* 0x10 */
    s32 macroblockWidth;           /* 0x14 */
    s32 macroblockHeight;          /* 0x18 */
    s32 pictureType;               /* 0x1c */
    s32 frameRate;                 /* 0x20 */
    s32 frameNumber;               /* 0x24 */
    s32 time;                      /* 0x28 */
    s32 timeUnit;                  /* 0x2c */
    s32 concatenation;             /* 0x30 */
    s32 frameInFile;               /* 0x34 */
    s32 timeInFile;                /* 0x38 */
    s32 errorCount;                /* 0x3c */
    s32 recoveryCount;             /* 0x40 */
    void *pictureUserData;         /* 0x44 */
    s32 pictureUserLength;         /* 0x48 */
    s32 frameType;                 /* 0x4c */
    u64 extension[7];              /* 0x50..0x87: seven native doubleword copies */
    void *supplementalData;        /* 0x88 */
    s32 supplementalLength;        /* 0x8c */
} MovieNativeFrame;

/* SDK sky2/rwplcore.h 4641-4682: real nested Im2D layout. */
typedef unsigned int MovieQuadword __attribute__((mode(TI)));

typedef struct MovieVector3 { f32 x, y, z; } MovieVector3;

typedef struct MovieColorReal { f32 red, green, blue, alpha; } MovieColorReal;

typedef struct MovieVertexFields {
    MovieVector3 scrVertex;
    f32 camVertex_z, u, v, recipZ, pad1;
    MovieColorReal color;
    MovieVector3 objNormal;
    f32 pad2;
} MovieVertexFields;

typedef union MovieVertexOverlay {
    MovieVertexFields els;
    MovieQuadword qWords[4];
} MovieVertexOverlay;

typedef struct MovieSdkVertex { MovieVertexOverlay u; } MovieSdkVertex;

typedef struct MovieNativeWork {
    void *queueNode;                    /* 0x000 */
    void *player;                  /* 0x004 */
    MWSFD_CRPRM parameters;         /* 0x008 */
    s32 playerStatus;              /* 0x038 */
    u32 field03c;
    MovieNativeFrame frame;        /* 0x040 */
    RwRaster *raster;              /* 0x0d0 */
    void *payload;                 /* 0x0d4 */
    s32 usesLoopPlayer;            /* 0x0d8 */
    u32 field0dc;
    MovieSdkVertex vertices[4]; /* 0x0e0 */
    u32 decoderWorkAddress;             /* 0x1e0 */
    s16 state;                     /* 0x1e4 */
    s16 field1e6;
    s16 field1e8;
    s16 movieIndex;                /* 0x1ea */
    s16 field1ec;
    s16 startupTicks;              /* 0x1ee */
    u32 field1f0;
    s32 field1f4;
    u32 field1f8;
    s32 ownsList;                  /* 0x1fc */
    void *imageBuffer;             /* 0x200 */
    s32 fadeOutFrames;             /* 0x204 */
    s32 fadeInFrames;              /* 0x208 */
    u32 field20c;
    s32 width;                     /* 0x210 */
    s32 height;                    /* 0x214 */
    void *path;                    /* 0x218 */
    u32 field21c;
} MovieNativeWork;

typedef struct MovieDevicePrefix {
    f32 gammaCorrection;
    s32 (*system)(s32, void *, void *, s32);
    f32 zBufferNear, zBufferFar;
    WindowRenderStateSet setState;
    s32 (*getState)(RwRenderState, void *);
} MovieDevicePrefix;

typedef struct MovieEnginePrefix {
    void *camera, *world;
    u16 renderFrame, lightFrame, pad[2];
    MovieDevicePrefix device;
} MovieEnginePrefix;

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Queue the movie renderer with the task work and its configured primitive-list name. */
// FUN_00468FA0
s32 mwPlayerUpdate(u8 *owner) {
    u8 *work;
    u8 *queueNode;

    work = ((KwlnTask *)owner)->work;
    queueNode = PrimAllocQueueNode();
    ((PrimQueueNode *)queueNode)->callback = (void *)movieNativeTaskUpdate;
    ((PrimQueueNode *)queueNode)->argument.data = work;
    PrimAppendNode(*(char * *)&((MovieNativeWork *)work)->path, queueNode);
    return 0;
}
#pragma pop

extern u32 ourGlobals[4096];
#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
/* Raw movie-table reads preserve separately linked interior labels and the native 0x28-byte definition stride; rebasing them would change symbol/addend provenance. The primitive-list header is opaque here. */
/* Advance native movie playback, copy decoded frames, apply fades and submit the display quad. */
// FUN_00468FF0
void movieNativeTaskUpdate(void *context, MovieNativeWork *work) {
    extern s32 func_003d5fb0(u8 *context);
    extern s32 func_003d6010(u8 *context);
    extern s32 func_003df860(const struct RwSList *context);
    extern RwBool RwRasterDestroy(RwRaster *raster);
    extern RwRaster *RwRasterCreate(s32 width, s32 height, s32 depth, s32 flags);
    extern RwBool RpSkyTexCacheRasterLock(RwRaster *raster, RwBool locked);
    extern u32 *func_00418f50(s32 channel);
    extern s32 sceDmaSync(u32 *channel, s32 mode, s32 timeout);
    extern void *memcpy(void *dst, const void *src, size_t size);
    extern void *memset(void *dst, s32 val, size_t size);
    extern void chkmemAllocSiteTag(void *context, s32 arg1);
    extern void chkmemSetLock(s32 context);
    extern u8 kwlnTaskDestroyWithHierarchyByName(const char *name);
    extern void H_Cdvd_StartPlayback(void *handle, void *path, s32 sync);
    extern s32 kwlnGetCamera(void);
    extern void kAssertFail(void *context, s32 arg1);
    extern s32 mwPlyCalcWorkCprmSfd(MWSFD_CRPRM *context);
    extern s32 func_00509268(u8 *context);
    extern void func_005097e8(s32 context);
    extern void mwPlySetFrmSync(s32 context, s32 arg1);
    extern void mwPlyGetCurFrm(void *context, void *arg1);
    extern void mwPlyRelCurFrm(s32 context);
    extern s32 func_0050d4d0(s32 context);
    extern void mwPlyReleaseLp(s32 context);
    extern void H_Fade_SetCustomColor(s32 r, s32 g, s32 b);
    extern void gsUploadRasterTiles(RwRaster *raster, u32 owner, s32 t0, s32 t1);
    extern s32 iGpffffbaf0;
    extern s32 iGpffffbaf4;
    extern u8 D_0070B610[];
    extern u8 D_00712C50[];
    extern u8 D_00712C54[];
    extern u8 D_00712C5C[];
    extern u8 D_00712C60[];
    extern u8 D_00712C64[];
    extern u8 D_00712C6C[];
    extern u8 D_00712C70[];
    extern u8 D_00712C72[];
    extern u8 D_00712C74[];
    extern u8 D_00712FF8[];
    extern const char D_00713010[];
    extern const char D_00713030[];
    extern const char D_00713040[];
    extern u8 D_00713050[];
    extern u8 D_00713068[];
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void *(*D_008873F4[])(size_t, size_t, u32);
    extern void *(*jtbl_008873E8[])(size_t, u32);
    extern u16 D_008C024E[];

    MovieNativeFrame frame;
    s32 savedRenderState;
    union { f32 xy[2]; s64 packed; } debugPosition;
    f32 letterboxBottom;
    f32 uMax;
    f32 vMax;
    f32 initialReciprocalZ;
    f32 reciprocalZ;
    struct { f32 x, y; } screenExtent;
    f32 fadeInOpacity;
    f32 fadeOutOpacity;
    s16 rasterKind;
    s32 value;
    s32 movieId;
    s16 fadeOutLength;
    s32 state;
    void (**tblEC)(void *);
    s32 playerHandle;
    s32 playerStatus;
    s32 neededHeight;
    s32 recordOffsetB;
    RwRaster *rasterB;
    s32 playerC;
    RwRaster *rasterC;
    s32 neededWidth;
    s32 fadeInNext;
    s32 playerA;
    RwRaster *rasterA;
    s32 playerB;
    s32 recordOffset;
    s32 fadeOutNext;
    u8 fadeInAlpha;
    s16 fadeInVertex;
    s16 fadeOutVertex;
    s16 vertexIndex;
    u32 decoderWork;
    u32 imageBufAddr;
    u32 decoderB;
    u32 imageB;
    u32 decoderC;
    u32 imageC;
    u32 decoderA;
    u32 imageA;
    u32 imageAddr;
    MWSFD_CRPRM *parameters;
    (void)context;

    state = work->state;
    switch (state) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if (work->ownsList != 0) {
            work->ownsList = 0;
            func_003d5fb0(D_0070B610);
        }
        if (work->field1f4 != 0) {
            work->fadeOutFrames = 0;
            work->fadeInFrames = 0;
            work->state = 2;
        }
    default:                                        /* switch 1 */
        goto movieComplete;
    case 2:                                         /* switch 1 */
        initialReciprocalZ = 1.0f / (((MdlEffectCamera *)kwlnGetCamera())->nearPlane);
        if (++work->startupTicks == 1) {
            work->ownsList = 1;
        }
        if (work->startupTicks == 6) {
            if (func_003df860(*(struct RwSList **)(D_0070B610 + 0x10)) != 0) {
                kAssertFail(D_00712FF8, 0x120);
            }
            func_003d6010(D_0070B610);
        }
        if (work->startupTicks == 0xA) {
            func_00440b68(D_00713010);
            work->usesLoopPlayer = (*(s32 *)(D_00712C64 + (work->movieIndex * 0x28)));
            parameters = &work->parameters;
            memset(parameters, 0, sizeof(*parameters));
            parameters->compo = 0x11;
            parameters->mode = 1;
            parameters->max_bps = 0x4C4B40;
            parameters->max_width = (*(s32 *)(D_00712C5C + (work->movieIndex * 0x28)));
            parameters->max_height = (*(s32 *)(D_00712C60 + (work->movieIndex * 0x28)));
            parameters->max_skip = 2;
            parameters->nsec = 1;
            parameters->buffmt = 2;
            parameters->wksize = mwPlyCalcWorkCprmSfd(parameters);
            chkmemSetLock(1);
            chkmemAllocSiteTag(D_00712FF8, 0x135);
            work->decoderWorkAddress = (u32)jtbl_008873E8[0](parameters->wksize + 0x40, 0x40000);
            chkmemAllocSiteTag(D_00712FF8, 0x136);
            work->imageBuffer = (void *)((u32)(D_008873F4[0](1U, 0x118000, 0x40000)));
            chkmemSetLock(0);
            func_00440b68(D_00713030, work->decoderWorkAddress);
            decoderWork = work->decoderWorkAddress;
            if ((decoderWork == 0) || ((u32)work->imageBuffer == 0)) {
                func_00440b68(D_00713040);
                work->state = 0xB;
                goto movieComplete;
            }
            parameters->work = (void *)decoderWork;
            work->payload = (void *)(decoderWork);
            playerHandle = func_00509268((u8 *)parameters);
            if (playerHandle == 0) {
                tblEC = (void (**)(void *))(u32)jtbl_008873EC;
                tblEC[0]((void *)work->decoderWorkAddress);
                work->decoderWorkAddress = 0U;
                imageBufAddr = (u32)work->imageBuffer;
                if (imageBufAddr != 0) {
                    tblEC[0]((void *)imageBufAddr);
                    work->imageBuffer = 0U;
                    iGpffffbae8 = 0U;
                }
            }
            mwPlySetFrmSync(playerHandle, 0);
            work->player = (void *)(playerHandle);
            if (work->usesLoopPlayer != 0) {
                H_Cdvd_StartPlayback((void *)playerHandle, *(u8 **)(D_00712C54 + (work->movieIndex * 0x28)), 1);
            } else {
                H_Cdvd_StartPlayback((void *)playerHandle, *(u8 **)(D_00712C54 + (work->movieIndex * 0x28)), 0);
            }
            chkmemSetLock(1);
            rasterKind = (*(s16 *)(D_00712C50 + (work->movieIndex * 0x28)));
            switch (rasterKind) {
            case 0:
                work->raster = RwRasterCreate(0x280, 0x1C0, 0x20, 0x584);
                break;
            case 1:
                work->raster = RwRasterCreate(0x280, 0x170, 0x20, 0x584);
                break;
            }
            chkmemSetLock(0);
            if (work->raster == 0) {
                work->state = 0xB;
                goto movieComplete;
            }
            vertexIndex = 0;
            for (; vertexIndex < 4; vertexIndex++) {
                work->vertices[vertexIndex].u.els.scrVertex.z = ((MovieEnginePrefix *)ourGlobals)->device.zBufferNear;
                work->vertices[vertexIndex].u.els.recipZ = initialReciprocalZ;
                if ((*(s32 *)(D_00712C50 + (work->movieIndex * 0x28) + (0x1C))) != 0) {
                    work->vertices[vertexIndex].u.els.color.red = 255.0f;
                    work->vertices[vertexIndex].u.els.color.green = 255.0f;
                    work->vertices[vertexIndex].u.els.color.blue = 255.0f;
                    work->vertices[vertexIndex].u.els.color.alpha = 0.0f;
                    work->field1e6 = (*(s16 *)(D_00712C50 + (work->movieIndex * 0x28) + (0x22)));
                    work->field1e8 = 0;
                    work->state = 3;
                } else {
                    work->vertices[vertexIndex].u.els.color.red = 255.0f;
                    work->vertices[vertexIndex].u.els.color.green = 255.0f;
                    work->vertices[vertexIndex].u.els.color.blue = 255.0f;
                    work->vertices[vertexIndex].u.els.color.alpha = 255.0f;
                    work->state = 3;
                }
            }
            screenExtent.x = (f32)(((MdlEffectRaster *)(u32)((MdlEffectCamera *)kwlnGetCamera())->raster)->width);
            screenExtent.y = (f32)(((MdlEffectRaster *)(u32)((MdlEffectCamera *)kwlnGetCamera())->raster)->height);
            reciprocalZ = 1.0f / (((MdlEffectCamera *)kwlnGetCamera())->nearPlane);
            if ((*(s16 *)(D_00712C50 + (work->movieIndex * 0x28))) == 0) {
                work->vertices[0].u.els.scrVertex.x = 0;
                work->vertices[1].u.els.scrVertex.x = 0;
                work->vertices[2].u.els.scrVertex.x = screenExtent.x;
                work->vertices[3].u.els.scrVertex.x = screenExtent.x;
                work->vertices[0].u.els.scrVertex.y = 0;
                work->vertices[1].u.els.scrVertex.y = screenExtent.y;
                work->vertices[2].u.els.scrVertex.y = 0;
                work->vertices[3].u.els.scrVertex.y = screenExtent.y;
            } else {
                f32 c40;
                work->vertices[0].u.els.scrVertex.x = 0;
                work->vertices[1].u.els.scrVertex.x = 0;
                work->vertices[2].u.els.scrVertex.x = screenExtent.x;
                work->vertices[3].u.els.scrVertex.x = screenExtent.x;
                c40 = 40.0f;
                work->vertices[0].u.els.scrVertex.y = c40;
                letterboxBottom = screenExtent.y - c40;
                work->vertices[1].u.els.scrVertex.y = letterboxBottom;
                work->vertices[2].u.els.scrVertex.y = c40;
                work->vertices[3].u.els.scrVertex.y = letterboxBottom;
            }
            work->vertices[0].u.els.scrVertex.z = ((MovieEnginePrefix *)ourGlobals)->device.zBufferNear;
            work->vertices[1].u.els.scrVertex.z = ((MovieEnginePrefix *)ourGlobals)->device.zBufferNear;
            work->vertices[2].u.els.scrVertex.z = ((MovieEnginePrefix *)ourGlobals)->device.zBufferNear;
            work->vertices[3].u.els.scrVertex.z = ((MovieEnginePrefix *)ourGlobals)->device.zBufferNear;
            {
                s32 textureWidth = 16;
                s32 textureHeight = 16;
            recordOffset = work->movieIndex * 0x28;
            neededWidth = (*(s32 *)(D_00712C5C + recordOffset)) + 1;
            neededHeight = (*(s32 *)(D_00712C60 + recordOffset)) + 1;
            while (neededWidth > textureWidth) {
                textureWidth *= 2;
            }
            while (neededHeight > textureHeight) {
                textureHeight *= 2;
            }
            work->vertices[0].u.els.u = 0;
            work->vertices[1].u.els.u = 0;
            uMax = (f32) neededWidth / (f32) textureWidth;
            work->vertices[2].u.els.u = uMax;
            work->vertices[3].u.els.u = uMax;
            work->vertices[0].u.els.v = 0;
            vMax = (f32) neededHeight / (f32) textureHeight;
            work->vertices[1].u.els.v = vMax;
            work->vertices[2].u.els.v = 0;
            work->vertices[3].u.els.v = vMax;
            work->vertices[0].u.els.recipZ = reciprocalZ;
            work->vertices[1].u.els.recipZ = reciprocalZ;
            work->vertices[2].u.els.recipZ = reciprocalZ;
            work->vertices[3].u.els.recipZ = reciprocalZ;
            }
            goto movieComplete;
        }
        break;
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
        if (state != 3) {
            switch (work->movieIndex) {
            case 0x15:
            case 0x16:
                if (D_008C024E[0] & 0x9FF) {
                    work->state = 6;
                }
                break;
            case 0x11:
                break;
            default:
                if (D_008C024E[0] & 0x800) {
                    work->state = 6;
                }
                break;
            }
        }
        mwPlyGetCurFrm(work->player, &frame);
        if (frame.buffer != 0) {
            iGpffffbaf8 = frame.frameNumber;
            if (work->state == 4) {
                recordOffsetB = work->movieIndex * 0x28;
                if ((*(s32 *)(D_00712C6C + recordOffsetB) != 0) && (frame.frameNumber >= (*(s16 *)(D_00712C70 + recordOffsetB)))) {
                    work->fadeOutFrames = 0;
                    work->state = 5;
                }
            }
            work->width = frame.width;
            work->height = frame.height;
            iGpffffbaf4 = frame.macroblockWidth;
            iGpffffbaf0 = frame.macroblockHeight;
            sceDmaSync(func_00418f50(2), 0, 0);
            memcpy(work->imageBuffer, frame.buffer, (size_t)(work->width * work->height * 4));
            iGpffffbae8 = (u32)((u32) (u32)work->imageBuffer);
            work->frame = frame;
            if (work->state == 3) {
                if ((*(s16 *)(D_00712C74 + (work->movieIndex * 0x28))) == 0) {
                    fadeInAlpha = 0xFF;
                    work->state = 4;
                } else {
                    fadeInNext = work->fadeInFrames + 1;
                    work->fadeInFrames = fadeInNext;
                    movieId = work->movieIndex;
                    if (fadeInNext == (*(s16 *)(D_00712C74 + (movieId * 0x28)))) {
                        switch (movieId) {
                        case 4:
                        case 16:
                            H_Fade_SetCustomColor(0, 0, 0);
                            break;
                        case 5:
                        case 6:
                        case 10:
                        case 11:
                        case 14:
                        case 15:
                        case 21:
                        case 22:
                            H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
                            break;
                        }
                        work->state = 4;
                    }
                    fadeInAlpha = ((work->fadeInFrames * 0xFF) / (*(s16 *)(D_00712C74 + (work->movieIndex * 0x28)))) & 0xFF;
                }
                fadeInVertex = 0;
                for (; fadeInVertex < 4; fadeInVertex++) {
                    work->vertices[fadeInVertex].u.els.color.red = 255.0f;
                    work->vertices[fadeInVertex].u.els.color.green = 255.0f;
                    work->vertices[fadeInVertex].u.els.color.blue = 255.0f;
                    fadeInOpacity = (f32)fadeInAlpha;
                    work->vertices[fadeInVertex].u.els.color.alpha = fadeInOpacity;
                }
            }
            if (work->state == 5) {
                u32 fadeOutAlpha;
                fadeOutNext = work->fadeOutFrames + 1;
                work->fadeOutFrames = fadeOutNext;
                fadeOutLength = (*(s16 *)(D_00712C72 + (work->movieIndex * 0x28)));
                fadeOutAlpha = (0xFF - (((s32) (fadeOutNext * 0xFF) / fadeOutLength) & 0xFF)) & 0xFF;
                if (fadeOutNext >= fadeOutLength) {
                    work->state = 6;
                }
                fadeOutVertex = 0;
                for (; fadeOutVertex < 4; fadeOutVertex++) {
                    work->vertices[fadeOutVertex].u.els.color.red = 255.0f;
                    work->vertices[fadeOutVertex].u.els.color.green = 255.0f;
                    work->vertices[fadeOutVertex].u.els.color.blue = 255.0f;
                    fadeOutOpacity = (f32)(u32)fadeOutAlpha;
                    work->vertices[fadeOutVertex].u.els.color.alpha = fadeOutOpacity;
                }
            }
        }
        mwPlyRelCurFrm((s32)work->player);
        playerStatus = func_0050d4d0((s32)work->player);
        if ((u32) (playerStatus - 3) < 2U) {
            work->state = 6;
            goto movieComplete;
        }
        ((MovieEnginePrefix *)ourGlobals)->device.getState((RwRenderState)(0xE), (void *)(&savedRenderState));
        ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xE), (void *)(0));
        RpSkyTexCacheRasterLock(work->raster, 1);
        imageAddr = iGpffffbae8;
        if (imageAddr != 0) {
            gsUploadRasterTiles(work->raster, imageAddr, iGpffffbaf4, iGpffffbaf0);
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0x14), (void *)(1));
            work->playerStatus = playerStatus;
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(6), (void *)(0));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(7), (void *)(2));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(8), (void *)(0));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xA), (void *)(5));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xB), (void *)(9));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(9), (void *)(1));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xC), (void *)(1));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(2), (void *)(3));
            ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(1), work->raster);
            D_00887310[0](4, (void *)work->vertices, 4);
        }
        RpSkyTexCacheRasterLock(work->raster, 0);
        ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xE), (void *)(savedRenderState));
        goto movieComplete;
    case 6:                                          /* switch 1 */
        if (work->field1f4 != 0) {
            kwlnTaskDestroyWithHierarchyByName((const char *)iGpffffb034);
            goto movieComplete;
        }
        playerA = (s32)work->player;
        if (playerA != 0) {
            if (work->usesLoopPlayer != 0) {
                mwPlyReleaseLp(playerA);
            }
            func_005097e8((s32)work->player);
            work->player = 0;
        }
        decoderA = work->decoderWorkAddress;
        if (decoderA != 0) {
            jtbl_008873EC[0]((void *)decoderA);
            work->decoderWorkAddress = 0U;
        }
        imageA = (u32)work->imageBuffer;
        if (imageA != 0) {
            jtbl_008873EC[0]((void *)imageA);
            work->imageBuffer = 0U;
            iGpffffbae8 = 0U;
        }
        rasterA = work->raster;
        if (rasterA != 0) {
            RwRasterDestroy(rasterA);
            work->raster = 0;
        }
        work->startupTicks = 0;
        work->state = 0;
        goto movieComplete;
    case 7:                                         /* switch 1 */
        work->startupTicks = 0x1E;
        work->state = 8;
        /* fallthrough */
    case 8:                                         /* switch 1 */
        work->state = 9;
        /* fallthrough */
    case 9:                                         /* switch 1 */
        work->state = 0xA;
        /* fallthrough */
    case 10:                                        /* switch 1 */
        if (--work->startupTicks == 0) {
            if (work->field1f4 != 0) {
                kwlnTaskDestroyWithHierarchyByName((const char *)iGpffffb034);
                goto movieComplete;
            }
            playerB = (s32)work->player;
            if (playerB != 0) {
                if (work->usesLoopPlayer != 0) {
                    mwPlyReleaseLp(playerB);
                }
                func_005097e8((s32)work->player);
                work->player = 0;
            }
            decoderB = work->decoderWorkAddress;
            if (decoderB != 0) {
                jtbl_008873EC[0]((void *)decoderB);
                work->decoderWorkAddress = 0U;
            }
            imageB = (u32)work->imageBuffer;
            if (imageB != 0) {
                jtbl_008873EC[0]((void *)imageB);
                work->imageBuffer = 0U;
                iGpffffbae8 = 0U;
            }
            rasterB = work->raster;
            if (rasterB != 0) {
                RwRasterDestroy(rasterB);
                work->raster = 0;
            }
            work->startupTicks = 0;
            work->state = 0;
            goto movieComplete;
        }
        break;
    case 11:                                        /* switch 1 */
        debugPosition.xy[0] = 2.0f;
        debugPosition.xy[1] = 10.0f;
        H_Dbprt_FmtAt(debugPosition.packed, (const char*)D_00713050);
        debugPosition.xy[0] = 2.0f;
        debugPosition.xy[1] = 11.0f;
        H_Dbprt_FmtAt(debugPosition.packed, (const char*)D_00713068);
        if (D_008C024E[0] & 0x800) {
            if (work->field1f4 != 0) {
                kwlnTaskDestroyWithHierarchyByName((const char *)iGpffffb034);
                goto movieComplete;
            }
            playerC = (s32)work->player;
            if (playerC != 0) {
                if (work->usesLoopPlayer != 0) {
                    mwPlyReleaseLp(playerC);
                }
                func_005097e8((s32)work->player);
                work->player = 0;
            }
            decoderC = work->decoderWorkAddress;
            if (decoderC != 0) {
                jtbl_008873EC[0]((void *)decoderC);
                work->decoderWorkAddress = 0U;
            }
            imageC = (u32)work->imageBuffer;
            if (imageC != 0) {
                jtbl_008873EC[0]((void *)imageC);
                work->imageBuffer = 0U;
                iGpffffbae8 = 0U;
            }
            rasterC = work->raster;
            if (rasterC != 0) {
                RwRasterDestroy(rasterC);
                work->raster = 0;
            }
            work->startupTicks = 0;
            work->state = 0;
        }
        break;
    }
movieComplete:
    return;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Release decoder, image and raster resources, then return movie work to its allocation pool. */
/* measured: remaining raw player reads/resource clears changed codegen individually (41..186 differing bytes); keep byte-pointer aliasing across release calls. */
// FUN_0046A020
void mwPlayerTaskDestroy(u8 *task)
{
    u8 *work;

    work = ((KwlnTask *)task)->work;
    if (*(s32 *)&((MovieNativeWork *)work)->player != 0) {
        if (((MovieNativeWork *)work)->usesLoopPlayer != 0) {
            mwPlyReleaseLp(*(s32 *)&((MovieNativeWork *)work)->player);
        }
        func_005097e8(*(s32 *)(work + 4));
        *(s32 *)(work + 4) = 0;
    }
    if (*(s32 *)&((MovieNativeWork *)work)->decoderWorkAddress != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)&((MovieNativeWork *)work)->decoderWorkAddress);
        *(s32 *)(work + 0x1E0) = 0;
    }
    if (*(s32 *)&((MovieNativeWork *)work)->imageBuffer != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)&((MovieNativeWork *)work)->imageBuffer);
        *(s32 *)(work + 0x200) = 0;
        iGpffffbae8 = 0;
    }
    if (*(s32 *)&((MovieNativeWork *)work)->raster != 0) {
        RwRasterDestroy(((MovieNativeWork *)work)->raster);
        *(s32 *)(work + 0xD0) = 0;
    }
    if (((MovieNativeWork *)work)->field1f4 == 0) {
        iGpffffbaec = 0;
    }
    if (((MovieNativeWork *)work)->ownsList != 0) {
        *(s32 *)(work + 0x1FC) = 0;
        func_003d5fb0(D_0070B610);
    }
    poolFree((u32)work);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Allocate movie work and create a playback task with the requested movie and queue name. */
// FUN_0046A110
s32 mwPlayerCreate(s32 parent, s16 movieIndex, s32 queueName) {
    s32 result;
    u8 *work;

    work = H_Calloc(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)((const void *)iGpffffb034), 0xC6, 0, 0, mwPlayerUpdate, mwPlayerTaskDestroy, (u8 *)(work));
    if (result == 0) {
        return 0;
    }
    ((MovieNativeWork *)work)->field1f4 = 1;
    ((MovieNativeWork *)work)->movieIndex = movieIndex;
    *(s32 *)&((MovieNativeWork *)work)->path = queueName;
    iGpffffbaf8 = 0;
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
// FUN_0046A1E0
s32 mwPlayerGetTaskName(void)
{
    return iGpffffb034;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Create a playback task with explicit primitive-list ownership reset. */
// FUN_0046A1F0
s32 mwPlayerCreateReset(s32 parent, s16 movieIndex, s32 queueName) {
    s32 result;
    u8 *work;

    work = H_Calloc(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)((const void *)iGpffffb034), 0xC6, 0, 0, mwPlayerUpdate, mwPlayerTaskDestroy, (u8 *)(work));
    if (result == 0) {
        return 0;
    }
    ((MovieNativeWork *)work)->field1f4 = 1;
    ((MovieNativeWork *)work)->movieIndex = movieIndex;
    ((MovieNativeWork *)work)->ownsList = 0;
    *(s32 *)&((MovieNativeWork *)work)->path = queueName;
    iGpffffbaf8 = 0;
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
// FUN_0046A2C0
s32 mwPlayerGetCurrent(void)
{
    return iGpffffbaf8;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Record the allocation file and line used by pool failure diagnostics. */
// FUN_0046A2D0
void poolSetAllocationSite(s32 allocationFile, s32 allocationLine)
{
    D_00724BEC = allocationFile;
    D_00724BF0 = allocationLine;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Initialize the fixed 500-entry allocation metadata table at the supplied buffer. */
// FUN_0046A2E0
void initEntryTable(u8 *buffer, s32 size) {
    u32 i;

    D_00724C04 = buffer;
    D_00724C00 = buffer + size;
    D_00724BFC = 0x1F4;
    i = 0;
    while (i < D_00724BFC) {
        *(s32 *)&((MoviePoolEntry *)buffer)[i].address = 0;
        *(s32 *)&((MoviePoolEntry *)buffer)[i].size = 0;
        i++;
    }
    D_00724BF8 = 0;
    D_00724BF4 = 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Free external allocations normally or clear the matching in-pool allocation record. */
// FUN_0046A340
void poolFree(u32 address) {
    s32 flag;
    u32 count;
    u32 index;
    u8 *table;
    u8 *entry;

    if (address < iGpffffbb14) {
        (*jtbl_008873EC)((void *)address);
        return;
    }
    if (iGpffffbb10 < address) {
        (*jtbl_008873EC)((void *)address);
        return;
    }
    flag = func_0042ba20();
    table = (u8 *)iGpffffbb14;
    index = 0;
    count = iGpffffbb0c;
    goto loop_test;
loop_body:
    entry = table + (index * 8);
    if (address == *(s32 *)&((MoviePoolEntry *)entry)->address) {
        count = iGpffffbb04;
        iGpffffbb04 = count - *(s32 *)&((MoviePoolEntry *)entry)->size;
        *(s32 *)&((MoviePoolEntry *)entry)->address = 0;
        *(s32 *)&((MoviePoolEntry *)entry)->size = 0;
        goto loop_done;
    }
    index += 1;
loop_test:
    if (index < count) {
        goto loop_body;
    }
loop_done:
    if (flag != 0) {
        func_0042ba70(count);
    }
}
#pragma pop

extern void kwlnTaskDumpAll(void);
extern char *kwlnTaskGetCurrent(void);
extern void kAssertFailMsg(const char *file, s32 line, const char *msg, ...);
extern char D_00713078[], D_00713088[], D_007130A0[];
extern char D_00756758[], D_00756748[], D_00756730[], D_00756720[];
/* Inline overlap search preserves retail's early-return branches.
   The metadata table and count are reloaded on each retry. */
static inline u32 sdkMallocFindOverlap(u32 candidate, u32 size)
{
    u32 i;
    u32 base;
    u32 length;
    u32 finish;
    u32 end;
    u32 count;
    u8 *table;
    u8 *entry;
    table = (u8 *)iGpffffbb14;
    end = candidate + size;
    i = 0;
    count = iGpffffbb0c;
    for (; i < count; i++) {
        entry = table + i * 8;
        length = ((MoviePoolEntry *)entry)->size;
        if (length != 0) {
            base = ((MoviePoolEntry *)entry)->address;
            finish = base + length;
            if (candidate == base) {
                return finish;
            } else if (base < candidate) {
                if (candidate < finish) {
                    return finish;
                }
            } else if (finish < end) {
                return finish;
            } else if (base < end) {
                return finish;
            }
        }
    }
    return candidate;
}

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants reset
/* Allocate aligned pool storage by skipping occupied intervals and claiming an empty metadata entry. */
// FUN_0046A430
u8 *poolAlloc(s32 requestedSize)
{
    s32 lock;
    u32 candidate;
    u32 size;
    u32 finish;
    u32 i;
    u8 *entry;
    u32 *entryLength;
    char *taskName;

    lock = func_0042ba20();
    size = ((u32)requestedSize + 0xF) & ~0xF;
    candidate = iGpffffbb14 + iGpffffbb0c * 8;
retry:
    finish = sdkMallocFindOverlap(candidate, size);
    if (finish == candidate) {
        i = 0;
        while (i < iGpffffbb0c) {
            entry = (u8 *)iGpffffbb14 + i * 8;
            entryLength = &((MoviePoolEntry *)entry)->size;
            if (*entryLength == 0) {
                ((MoviePoolEntry *)entry)->address = finish;
                *entryLength = size;
                iGpffffbb04 += size;
                goto allocated;
            }
            i++;
        }
        func_00440b68(D_00756758);
        taskName = kwlnTaskGetCurrent();
        kAssertFailMsg((const char *)D_00756748, 0xB2,
                      (const char *)D_00756730, iGpffffbb04, size,
                      taskName, D_00724BEC, D_00724BF0);
        kAssertFail(D_00756720, 0xB3);
allocated:
        if (lock != 0) {
            func_0042ba70();
        }
        if (finish + size >= iGpffffbb10) {
            func_00440b68(D_00713078);
            taskName = kwlnTaskGetCurrent();
            kAssertFailMsg((const char *)D_00713088, 0xEC,
                          (const char *)D_007130A0, iGpffffbb04, size,
                          taskName, D_00724BEC, D_00724BF0);
        }
        return (u8 *)finish;
    }
    candidate = finish;
    if (candidate + size >= iGpffffbb10) {
        kwlnTaskDumpAll();
        func_00440b68(D_00713078);
        taskName = kwlnTaskGetCurrent();
        kAssertFailMsg((const char *)D_00713088, 0xFA,
                      (const char *)D_007130A0, iGpffffbb04, size,
                      taskName, D_00724BEC, D_00724BF0);
        kAssertFail(D_00713088, 0xFB);
    }
    goto retry;
}
#pragma pop

extern u32 ourGlobals[4096];
extern void chkmemAllocSiteTag(void *, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
