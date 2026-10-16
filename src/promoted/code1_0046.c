#include "include_asm.h"
#include "sdk_dbprt.h"
#include "sdk_task_registration.h"
#include "sdk_lbox_internal.h"
#include "type.h"
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
typedef char MovieParametersSize[sizeof(MWSFD_CRPRM) == 0x30 ? 1 : -1];
struct RwSList;
typedef struct RwRaster RwRaster;
typedef s32 RwBool;

typedef s32 (*WindowRenderStateSet)(RwRenderState state, void *value);
/* Compatible with s32 (RwRenderState, void *) in C89: both arguments retain
 * their types under default promotions. The explicit argument conversions
 * at the save/restore calls retain retail's address-before-load evaluation. */
typedef s32 (*WindowRenderStateCall)();

extern s32 iGpffffb034;
extern s32 iGpffffbaf8;
extern s32 iGpffffbab4;
extern s32 iGpffffbab0;
extern s32 D_008E4B30[];
extern s32 D_008E4B34[];
extern s32 D_008E4B38[];
extern u8 D_008E4800[];
extern u8 D_008E4B50[];
extern u8 D_008E4D30[];
extern void func_0043a978(void);
extern void func_004316a8(s32 arg0);
extern s32 func_00431928(void *a, u8 *b);
extern s32 func_003e1220(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
extern s32 iGpffffba98;
extern s32 iGpffffba9c;
extern u8 D_008E43C0[];
extern u8 D_008E43E4[];
extern void *K_Clump_UpdateObjectCb(void *a0, void *a1);
extern s32 D_00922984[];
extern s32 D_00922980[];
extern s32 D_00922988[];
extern s32 D_00922934[];
extern s32 D_00922930[];
extern s32 D_0092293C[];
extern u8 *(*D_008873F8[])();
extern void *memset(void *dst, s32 value, size_t size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])();

extern void func_00452730(s32 arg0);

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

extern void sdkSpriteLoadStep(u8 *arg0);
extern u8 *D_00724C08;

extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_007130E8[];
extern s32 D_00724130;

extern s32 func_004633f0(u8 *task);
struct MovieNativeWork;
extern void movieNativeTaskUpdate(void *arg0, struct MovieNativeWork *work);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void PrimAppendNode(char *name, u8 *task);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern u8 D_00800000[];
extern u16 D_008C0276[];
extern char iGpffffb020[3];
extern char iGpffffb024[2];
extern char iGpffffb028[6];
extern u8 *func_00468940(u8 *arg0, s64 arg1);
extern void sdkListStateConfigure(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetPrimaryMasks(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 sdkListStateHandleInput(u8 *arg0);
extern s32 func_004688d0(u8 *arg0, s8 *arg1);
extern s32 strcmp(const char *a, const char *b);
extern s32 uGpffffb230;
extern s32 D_00724BC8;
extern s32 func_0042ba70();
extern s32 func_0042ba20();
extern void func_004216e0(s32 handle, s32 *out);
extern void func_00421770(s32 handle);
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern WindowRenderStateSet D_00887300[];
extern s32 (*D_00887304[])(RwRenderState state, void *value);
extern u8 D_008872E0[];
extern s32 iGpffffaf60;
extern void func_003c21e0(s32 arg0, s32 (*callback)(u8 *, s32 *), s32 *result);
extern u8 *func_003bfae0(s32 arg0);
extern s32 RwCameraFrustumTestSphere(s32 arg0, u8 *arg1);
extern void mdlClumpSetEnvMapValue(s32 arg0, s32 arg1);
extern void mdlDrawSkyPass(u8 *arg0);
extern void mdlDrawVisibleAtomics(s32 arg0);
extern void movieNativeDrawPass1(u8 *arg0);
extern void movieNativeDrawPass2(u8 *arg0);
extern void movieNativeDrawPass3(u8 *arg0);
extern u8 *H_Calloc(s32 arg0, s32 arg1);

extern s32 mwPlayerUpdate(u8 *arg0);
extern void mwPlayerTaskDestroy(u8 *arg0);
extern u32 iGpffffbb14;
extern u32 iGpffffbb10;
extern u32 iGpffffbb0c;
extern u32 iGpffffbb04;
/* sceMc2CheckAsync consumes the two command/result output pointers. */
extern s32 func_00432ec0(s32 *command, s32 *result);
extern s32 iGpffffba8c;
extern s32 iGpffffb198;
extern s32 iGpffffb194;
extern f32 iGpffffbb20;
extern f32 iGpffffbb1c;
extern f32 iGpffffbb24;
extern void func_0044f720(void);
extern s32 func_003e23e0(void);
extern void func_003e82e0();
extern void func_003e5510(s32 arg0);
extern s32 kwlnGetCamera(void);
extern void func_00466c60(void);
extern void func_0050cd80(void);
extern void func_00466600(void);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern s32 sceMc2GetInfoAsync(s32 socket, void *out);
extern s32 func_00431d78(s32 socket, void *data, void *result);
extern char D_007127D0[];
extern char D_00712950[];
extern char D_008E4900[];
extern char D_008E4A20[];
extern s32 D_00764BA4;
extern s32 D_00764BB8;
extern s32 D_00764BC0;
extern s32 D_008E4B20[];
extern s32 D_008E4B28[];
extern s32 D_00712490[];
extern s64 D_007615DC;
extern f32 fGpffff82fc;
extern f32 fGpffff84f0;
extern f32 cosf(f32 arg0);
extern f32 sinf(f32 arg0);
extern void primLine3D(void *arg0, void *arg1, void *arg2, s32 arg3);
/* Same RwV3d tag and fields as the ring provider and RenderWare. */
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} Code46RingPoint;
extern void primCircleLine3D(const Code46RingPoint *position, f32 radius,
                         u8 *color, f32 *matrix, s32 setStates);
struct Data_00712508 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};
extern struct Data_00712508 D_00712508[] __attribute__((aligned(8)));
extern f32 fGpffff81f0;
extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
typedef struct RwMatrixTag RwMatrix;
typedef struct RwV3d RwV3d;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;
extern RwMatrix *func_003e0f80(void);
extern RwMatrix *func_003e0680(RwMatrix *matrix, const RwV3d *axis,
                            f32 oneMinusCosine, f32 sine, RwOpCombineType combineOp);
extern RwV3d *func_003e42e0(RwV3d *dst, const RwV3d *src, s32 count, const RwMatrix *matrix);
extern s32 func_003e0f40(RwMatrix *matrix);
extern u8 D_007130B8[];
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8084;
extern f32 fGpffff81b0;
extern f32 fGpffff81b4;
extern f32 fGpffff81b8;
extern f32 fGpffff81bc;
extern f32 fGpffff81c0;
extern f32 fGpffff81c4;
extern f32 fGpffff81c8;
extern f32 fGpffff81cc;








extern u8 *PrimAllocQueueNode(void);













#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on




#pragma opt_loop_invariants on
#pragma opt_loop_invariants reset
typedef struct FilerEntry {
    char name[256];
    s32 type;
    s32 active;
} FilerEntry;

typedef struct FilerTable {
    u8 path[256];
    FilerEntry entries[2000];
} FilerTable;

typedef struct FilerStat {
    u32 mode;
    u32 attr;
    u32 size;
    u8 ctime[8];
    u8 atime[8];
    u8 mtime[8];
    u32 hisize;
    u32 private_0;
    u32 private_1;
    u32 private_2;
    u32 private_3;
    u32 private_4;
    u32 private_5;
} FilerStat;

/* Extended directory entry: 64-byte stat, 256-byte name, trailing word.
 * Layout: PCSX2 IopBios.cpp, revision 9fe8235e, fxio_dirent_t.
 * Natural four-byte alignment, not modern ps2sdk's aligned(64) variant. */
typedef struct FilerDirent {
    FilerStat stat;
    char name[256];
    u32 unknown;
} FilerDirent;


extern void func_004673c0(u8 *work);
extern void func_00467880(u8 *arg0);
#pragma push
#pragma opt_loop_invariants on

#pragma pop




// Note: h_cdvd and code1_0045 declare movieResetSlotFlags with an s32 argument;
// this definition takes void. Extern types left as they are; verify decides.
// FUN_00468A10
void movieResetSlotFlags(void)
{
    D_00922984[0] = 0;
    D_00922980[0] = 0;
    D_00922988[0] = 0;
    D_00922934[0] = 0;
    D_00922930[0] = 0;
    D_0092293C[0] = 0;
}
/* Measured: 652/656 bytes, eight resolved relocations and four zero tail bytes.
 * Request handles and resource tables are reloaded after their callbacks. */
#pragma opt_loop_invariants on
// FUN_00468D10
void movieLoadStep(void)
{
    extern s32 func_00468bf0(u8 *node, s32 slot);
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
        state = *(s32 *)(node + 0xC);
        switch (state) {
        case 0:
            node = *(u8 **)(node + 4);
            break;
        case 1:
            *(s32 *)(node + 0x44) = 0;
            for (phase = 0; phase < 10; phase++) {
                if (func_00468bf0(node, phase) == 0) {
                    break;
                }
            }
            *(s32 *)(node + 0xC) = 2;
            /* fall through */
        case 2:
            phase = 1;
            for (slot = 0; slot < 10; slot++) {
                if (*(s32 *)(node + 0x10 + slot * 4) != 0) {
                    if (func_004c9820(*(ADXF *)(node + 0x10 + slot * 4)) == 3) {
                        func_004c8a60(*(ADXF *)(node + 0x10 + slot * 4));
                        *(s32 *)(node + 0x10 + slot * 4) = 0;
                        if (func_00468bf0(node, slot) == 1) {
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
                value = *(s8 *)(*(u8 **)(node + 8) + character + 0x118);
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
                 phase < *(s32 *)(node + 0x40) - *(s32 *)(node + 0x3C);
                 phase++) {
                if ((*(s32 **)(node + 0x38))[phase] != 0) {
                    H_Cdvd_RegisterArchiveEntries((u8 *)path,
                                  (u8 *)(*(s32 **)(node + 0x38))[phase], 1);
                    (*(s32 **)(node + 0x38))[phase] += 0x100;
                }
            }
            *(s32 *)(node + 0xC) = 4;
            break;
        case 4:
            node = *(u8 **)(node + 4);
            break;
        }
    } while (node != NULL);
}
#pragma opt_loop_invariants reset
// FUN_00468FA0
s32 mwPlayerUpdate(u8 *arg0) {
    u8 *ctx;
    u8 *task;

    ctx = *(u8 **)(arg0 + 0x38);
    task = PrimAllocQueueNode();
    *(void **)(task + 8) = (void *)movieNativeTaskUpdate;
    *(u8 **)(task + 0x10) = ctx;
    PrimAppendNode(*(char **)(ctx + 0x218), task);
    return 0;
}

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
typedef char MovieNativeFrameSize[sizeof(MovieNativeFrame) == 0x90 ? 1 : -1];

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
typedef char MovieSdkVertexSize[sizeof(MovieSdkVertex) == 0x40 ? 1 : -1];
typedef struct MovieNativeWork {
    void *task;                    /* 0x000 */
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
typedef char MovieNativeWorkSize[sizeof(MovieNativeWork) == 0x220 ? 1 : -1];

typedef char MovieAddressWordWidth[sizeof(void *) == sizeof(u32) ? 1 : -1];
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
extern u32 ourGlobals[4096];
typedef char MovieDevicePrefixSize[(sizeof(MovieDevicePrefix) == 0x18) ? 1 : -1];
typedef char MovieEnginePrefixSize[(sizeof(MovieEnginePrefix) == 0x28) ? 1 : -1];

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
// FUN_00468FF0
void movieNativeTaskUpdate(void *arg0, MovieNativeWork *work) {
    extern s32 func_003d5fb0(u8 *arg0);
    extern s32 func_003d6010(u8 *arg0);
    extern s32 func_003df860(const struct RwSList *arg0);
    extern RwBool RwRasterDestroy(RwRaster *raster);
    extern RwRaster *RwRasterCreate(s32 width, s32 height, s32 depth, s32 flags);
    extern RwBool func_0040fcd0(RwRaster *raster, RwBool locked);
    extern u32 *func_00418f50(s32 channel);
    extern s32 func_00419520(u32 *channel, s32 mode, s32 timeout);
    extern void *memcpy(void *dst, const void *src, size_t size);
    extern void *memset(void *dst, s32 val, size_t size);
    extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
    extern void chkmemSetLock(s32 arg0);
    extern u8 kwlnTaskDestroyWithHierarchyByName(const char *name);
    extern void H_Cdvd_StartPlayback(void *handle, void *path, s32 sync);
    extern s32 kwlnGetCamera(void);
    extern void kAssertFail(void *arg0, s32 arg1);
    extern s32 mwPlyCalcWorkCprmSfd(MWSFD_CRPRM *arg0);
    extern s32 func_00509268(u8 *arg0);
    extern void func_005097e8(s32 arg0);
    extern void mwPlySetFrmSync(s32 arg0, s32 arg1);
    extern void mwPlyGetCurFrm(void *arg0, void *arg1);
    extern void mwPlyRelCurFrm(s32 arg0);
    extern s32 func_0050d4d0(s32 arg0);
    extern void mwPlyReleaseLp(s32 arg0);
    extern void H_Fade_SetCustomColor(s32 r, s32 g, s32 b);
    extern void func_00143ba0(RwRaster *raster, u32 owner, s32 t0, s32 t1);
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
    s32 spFC;
    union { f32 xy[2]; s64 packed; } debugPosition;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f20;
    f32 temp_f2;
    struct { f32 x, y; } screenExtent;
    f32 var_f0;
    f32 var_f0_2;
    s16 rasterKind;
    s32 temp_3_5;
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
    (void)arg0;

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
        temp_f20 = 1.0f / (*(f32 *)((u8 *)kwlnGetCamera() + (0x80)));
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
                work->vertices[vertexIndex].u.els.recipZ = temp_f20;
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
            screenExtent.x = (f32)(*(s32 *)((u8 *)(*(u8 **)((u8 *)kwlnGetCamera() + (0x60))) + (0xC)));
            screenExtent.y = (f32)(*(s32 *)((u8 *)(*(u8 **)((u8 *)kwlnGetCamera() + (0x60))) + (0x10)));
            temp_f2 = 1.0f / (*(f32 *)((u8 *)kwlnGetCamera() + (0x80)));
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
                temp_f0 = screenExtent.y - c40;
                work->vertices[1].u.els.scrVertex.y = temp_f0;
                work->vertices[2].u.els.scrVertex.y = c40;
                work->vertices[3].u.els.scrVertex.y = temp_f0;
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
            temp_f0_2 = (f32) neededWidth / (f32) textureWidth;
            work->vertices[2].u.els.u = temp_f0_2;
            work->vertices[3].u.els.u = temp_f0_2;
            work->vertices[0].u.els.v = 0;
            temp_f0_3 = (f32) neededHeight / (f32) textureHeight;
            work->vertices[1].u.els.v = temp_f0_3;
            work->vertices[2].u.els.v = 0;
            work->vertices[3].u.els.v = temp_f0_3;
            work->vertices[0].u.els.recipZ = temp_f2;
            work->vertices[1].u.els.recipZ = temp_f2;
            work->vertices[2].u.els.recipZ = temp_f2;
            work->vertices[3].u.els.recipZ = temp_f2;
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
            func_00419520(func_00418f50(2), 0, 0);
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
                    var_f0 = (f32)fadeInAlpha;
                    work->vertices[fadeInVertex].u.els.color.alpha = var_f0;
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
                    var_f0_2 = (f32)(u32)fadeOutAlpha;
                    work->vertices[fadeOutVertex].u.els.color.alpha = var_f0_2;
                }
            }
        }
        mwPlyRelCurFrm((s32)work->player);
        playerStatus = func_0050d4d0((s32)work->player);
        if ((u32) (playerStatus - 3) < 2U) {
            work->state = 6;
            goto movieComplete;
        }
        ((MovieEnginePrefix *)ourGlobals)->device.getState((RwRenderState)(0xE), (void *)(&spFC));
        ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xE), (void *)(0));
        func_0040fcd0(work->raster, 1);
        imageAddr = iGpffffbae8;
        if (imageAddr != 0) {
            func_00143ba0(work->raster, imageAddr, iGpffffbaf4, iGpffffbaf0);
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
        func_0040fcd0(work->raster, 0);
        ((MovieEnginePrefix *)ourGlobals)->device.setState((RwRenderState)(0xE), (void *)(spFC));
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

// FUN_0046A020
void mwPlayerTaskDestroy(u8 *arg0)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) != 0) {
        if (*(s32 *)(work + 0xD8) != 0) {
            mwPlyReleaseLp(*(s32 *)(work + 4));
        }
        func_005097e8(*(s32 *)(work + 4));
        *(s32 *)(work + 4) = 0;
    }
    if (*(s32 *)(work + 0x1E0) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(work + 0x1E0));
        *(s32 *)(work + 0x1E0) = 0;
    }
    if (*(s32 *)(work + 0x200) != 0) {
        jtbl_008873EC[0]((void *)*(s32 *)(work + 0x200));
        *(s32 *)(work + 0x200) = 0;
        iGpffffbae8 = 0;
    }
    if (*(s32 *)(work + 0xD0) != 0) {
        RwRasterDestroy(*(RwRaster **)(work + 0xD0));
        *(s32 *)(work + 0xD0) = 0;
    }
    if (*(s32 *)(work + 0x1F4) == 0) {
        iGpffffbaec = 0;
    }
    if (*(s32 *)(work + 0x1FC) != 0) {
        *(s32 *)(work + 0x1FC) = 0;
        func_003d5fb0(D_0070B610);
    }
    poolFree((u32)work);
}
// FUN_0046A110
s32 mwPlayerCreate(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = H_Calloc(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)((const void *)iGpffffb034), 0xC6, 0, 0, mwPlayerUpdate, mwPlayerTaskDestroy, (u8 *)(work));
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A1E0
s32 mwPlayerGetTaskName(void)
{
    return iGpffffb034;
}

// FUN_0046A1F0
s32 mwPlayerCreateReset(s32 arg0, s16 arg1, s32 arg2) {
    s32 result;
    u8 *work;

    work = H_Calloc(1, 0x220);
    if (work == NULL) {
        return 0;
    }
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)((const void *)iGpffffb034), 0xC6, 0, 0, mwPlayerUpdate, mwPlayerTaskDestroy, (u8 *)(work));
    if (result == 0) {
        return 0;
    }
    *(s32 *)(work + 0x1F4) = 1;
    *(s16 *)(work + 0x1EA) = arg1;
    *(s32 *)(work + 0x1FC) = 0;
    *(s32 *)(work + 0x218) = arg2;
    iGpffffbaf8 = 0;
    return result;
}
// FUN_0046A2C0
s32 mwPlayerGetCurrent(void)
{
    return iGpffffbaf8;
}

// FUN_0046A2D0
void func_0046a2d0(s32 arg0, s32 arg1)
{
    D_00724BEC = arg0;
    D_00724BF0 = arg1;
}



// FUN_0046A2E0
void initEntryTable(u8 *arg0, s32 arg1) {
    u32 i;

    D_00724C04 = arg0;
    D_00724C00 = arg0 + arg1;
    D_00724BFC = 0x1F4;
    i = 0;
    while (i < D_00724BFC) {
        *(s32 *)(arg0 + i * 8) = 0;
        *(s32 *)(arg0 + i * 8 + 4) = 0;
        i++;
    }
    D_00724BF8 = 0;
    D_00724BF4 = 0;
}

// FUN_0046A340
void poolFree(u32 arg0) {
    s32 flag;
    u32 count;
    u32 index;
    u8 *table;
    u8 *entry;

    if (arg0 < iGpffffbb14) {
        (*jtbl_008873EC)((void *)arg0);
        return;
    }
    if (iGpffffbb10 < arg0) {
        (*jtbl_008873EC)((void *)arg0);
        return;
    }
    flag = func_0042ba20();
    table = (u8 *)iGpffffbb14;
    index = 0;
    count = iGpffffbb0c;
    goto loop_test;
loop_body:
    entry = table + (index * 8);
    if (arg0 == *(s32 *)(entry + 0)) {
        count = iGpffffbb04;
        iGpffffbb04 = count - *(s32 *)(entry + 4);
        *(s32 *)(entry + 0) = 0;
        *(s32 *)(entry + 4) = 0;
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
extern void kwlnTaskDumpAll(void);
extern char *func_004526e0(void);
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
        length = *(u32 *)(entry + 4);
        if (length != 0) {
            base = *(u32 *)entry;
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

/* Measured: 692/704 bytes, 53 resolved relocations and twelve zero
   alignment bytes. Diagnostic arguments reload after the task-name call. */
// FUN_0046A430
u8 *poolAlloc(s32 arg0)
{
    s32 lock;
    u32 candidate;
    u32 size;
    u32 finish;
    u32 i;
    u8 *entry;
    u32 *entry_length;
    char *task_name;

    lock = func_0042ba20();
    size = ((u32)arg0 + 0xF) & ~0xF;
    candidate = iGpffffbb14 + iGpffffbb0c * 8;
retry:
    finish = sdkMallocFindOverlap(candidate, size);
    if (finish == candidate) {
        i = 0;
        while (i < iGpffffbb0c) {
            entry = (u8 *)iGpffffbb14 + i * 8;
            entry_length = (u32 *)(entry + 4);
            if (*entry_length == 0) {
                *(u32 *)entry = finish;
                *entry_length = size;
                iGpffffbb04 += size;
                goto allocated;
            }
            i++;
        }
        func_00440b68(D_00756758);
        task_name = func_004526e0();
        kAssertFailMsg((const char *)D_00756748, 0xB2,
                      (const char *)D_00756730, iGpffffbb04, size,
                      task_name, D_00724BEC, D_00724BF0);
        kAssertFail(D_00756720, 0xB3);
allocated:
        if (lock != 0) {
            func_0042ba70();
        }
        if (finish + size >= iGpffffbb10) {
            func_00440b68(D_00713078);
            task_name = func_004526e0();
            kAssertFailMsg((const char *)D_00713088, 0xEC,
                          (const char *)D_007130A0, iGpffffbb04, size,
                          task_name, D_00724BEC, D_00724BF0);
        }
        return (u8 *)finish;
    }
    candidate = finish;
    if (candidate + size >= iGpffffbb10) {
        kwlnTaskDumpAll();
        func_00440b68(D_00713078);
        task_name = func_004526e0();
        kAssertFailMsg((const char *)D_00713088, 0xFA,
                      (const char *)D_007130A0, iGpffffbb04, size,
                      task_name, D_00724BEC, D_00724BF0);
        kAssertFail(D_00713088, 0xFB);
    }
    goto retry;
}
// FUN_0046A770
/* The list walk is written with an explicit goto loop: retail tests the
   cursor at the TOP of the loop and both early exits are out of line, which
   the natural `while (p != NULL)` form does not reproduce (nd 57). */
u8 *resourceFindByName(char *arg0) {
    u8 *p;

    p = D_00724C08;
loop:
    if (p == NULL) {
        return NULL;
    }
    if (strcmp((char *)(p + 2), arg0) == 0) {
        return p;
    }
    p = *(u8 **)(p + 0x238);
    goto loop;
}

/* measured: b210 -O2 emits 844/848 native bytes with all nineteen
 * relocations resolved and four zero alignment bytes. Keep the negated
 * upper-limit result separate from its branch and the Y subtotal separate
 * from the attachment-table load. Loop invariants retain the retail wrap
 * constants; see docs/probe_archive/Sprite_attachment_0046a7f0_20260924.md. */
// FUN_0046A7F0
#pragma push
#pragma opt_loop_invariants on
void sdkSpriteTransformPoints(u8 *attachment, u8 *points)
{
    RwV3d source[4];
    RwV3d transformed[4];
    s32 copyIndex;
    s32 pointIndex;
    s32 vectorIndex;
    f32 angle;
    f32 x;
    f32 x2;
    f32 polynomial;
    f32 quadraticProduct;
    f32 correction;
    f32 oneMinusCosine;
    f32 sine;
    s32 wrapped;
    RwMatrix *matrix;
    RwMatrix *rotation;

    for (copyIndex = 0; copyIndex < 4; copyIndex++) {
        f32 *s = (f32 *)(points + copyIndex * 8);
        RwV3d *d = &source[copyIndex];

        d->x = s[0];
        d->y = s[1];
        /* Retail leaves the third component unwritten before rotation. */
    }
    angle = *(f32 *)(attachment + 0x18);
    if (angle != 0.0f) {
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
        rotation = func_003e0680(matrix, (const RwV3d *)D_007130B8, oneMinusCosine, sine, rwCOMBINEREPLACE);
        func_003e42e0(transformed, source, 4, rotation);
        func_003e0f40(rotation);
        for (vectorIndex = 0; vectorIndex < 4; vectorIndex++) {
            const RwV3d *s = &transformed[vectorIndex];
            RwV3d *d = &source[vectorIndex];

            *d = *s;
        }
    }
    for (pointIndex = 0; pointIndex < 4; pointIndex++) {
        RwV3d *p = &source[pointIndex];
        f32 *o = (f32 *)(points + pointIndex * 8);

        o[0] = *(f32 *)(attachment + 8) + ((f32)*(s16 *)(attachment + 0x1C) + p->x) +
               (f32)*(s32 *)(*(s32 *)(*(u8 **)attachment + 0x204) + (*(s32 *)(attachment + 4) << 7) + 0x44);
        {
            f32 subtotal;
            subtotal = *(f32 *)(attachment + 0xC) + ((f32)*(s16 *)(attachment + 0x1E) + p->y);
            subtotal += (f32)*(s32 *)(*(s32 *)(*(u8 **)attachment + 0x204) + (*(s32 *)(attachment + 4) << 7) + 0x48);
            o[1] = subtotal;
        }
    }
}

#pragma pop
// FUN_0046AB40
void resourceLoadSprites(void)
{
    u8 *attachment = D_00724C08;
loop_1:
    if (attachment != NULL) {
        sdkSpriteLoadStep(attachment);
        attachment = *(u8 **)(attachment + 0x238);
        goto loop_1;
    }
}




/* RwGlobals.dOpenDevice begins at +0x10, with fpRenderStateSet at +0x20.
 * Use the registered enum/void-pointer callback through the native static
 * instance, following RwRenderStateSetMacro in the PS2 RenderWare headers. */
typedef struct WindowDeviceStatePrefix {
    f32 gammaCorrection;
    s32 (*system)(s32, void *, void *, s32);
    f32 zBufferNear, zBufferFar;
    WindowRenderStateSet setState;
} WindowDeviceStatePrefix;
typedef struct WindowEngineStatePrefix {
    void *camera, *world;
    u16 renderFrame, lightFrame, pad[2];
    WindowDeviceStatePrefix device;
} WindowEngineStatePrefix;
extern u32 ourGlobals[4096];

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes on
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
/* Pointer-valued task name restores retail argument setup.
 * MWCCPS2 b210 -O2: 444 executable bytes / 448-byte retail window.
 * The buffer calculation uses rectangle x/y, not width/height. */
#pragma push
#pragma opt_propagation off
extern s32 sdkWindowUpdate(u8 *);
extern void chkmemAllocSiteTag(void *, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_007130F8[], D_00713108[];
extern u8 *sdkWindowCreate(u8 *parent, void *rect_arg, void *first_arg, void *second_arg);
#pragma pop
#undef sp0
#undef sp4
#undef sp8
#undef spC
/* sdkLbox allocates a 0x190-byte controller. Its four 0x40-byte screen
 * vertices use the RwSky2DVertexFields layout. k_view.c establishes the
 * 0x22C-byte linked entry and its void (void *) selection callback. */
typedef struct { u8 red, green, blue, alpha; } ControllerColor;
typedef struct { s32 x, y, width, height; } ControllerRect;
extern ControllerColor D_00764134;
extern ControllerColor D_00764138;
extern ControllerColor D_0076413C;
extern ControllerColor D_00764140;
extern ControllerColor D_00764144;
extern ControllerColor D_00764148;
extern ControllerColor D_0076414C;
extern ControllerColor D_00764150;
extern ControllerColor D_007641A8;

typedef struct {
    f32 x, y, z, cameraZ;
    f32 u, v, reciprocalZ, fogPad;
    f32 red, green, blue, alpha;
    f32 normalX, normalY, normalZ, alignmentPad;
} ControllerVertex;
typedef struct {
    s32 state, flags, theme, enabled, delay, unknown14;
    ControllerRect rectangle;
    s32 columnWidth, rowHeight;
    ControllerVertex vertices[4];
    u8 *window;
    s32 selectedRow, selectedValue, repeatDelay, visible;
    void *firstEntry, *lastEntry;
    s32 (*update)(s32); s32 updateArgument;
    u8 unknown154[0x10]; u8 input[0x2C];
} ControllerWork;

typedef struct ControllerEntry {
    s32 id, type;
    char name[256], text[256];
    s32 integerValue; f32 realValue;
    s32 minimum, maximum, flags;
    KWindowEntryCallback callback;
    void *argument;
    struct ControllerEntry *previous, *next;
} ControllerEntry;

/* Keep construction and its consuming call together. Native rectangle
 * initialization supplies the retail byte clear; the two RGBA values are
 * complete snapshots, not floating-point colors. */
static inline u8 *controller_create_window(u8 *parent,
    s32 x, s32 y, s32 width, s32 height,
    const ControllerColor *firstSource, const ControllerColor *secondSource)
{
    extern u8 *sdkWindowCreate(u8 *, void *, void *, void *);
    ControllerColor first, second;
    ControllerRect rectangle = { x, y, width, height };
    first = *firstSource;
    second = *secondSource;
    return sdkWindowCreate(parent, &rectangle, &first, &second);
}

#pragma push
#pragma opt_loop_invariants on
#pragma pop
