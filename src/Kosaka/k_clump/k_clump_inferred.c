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
extern s32 iGpffffba98;
extern s32 iGpffffba9c;
extern u8 D_008E43C0[];
extern u8 D_008E43E4[];
extern s32 D_00922984[];
extern s32 D_00922980[];
extern s32 D_00922988[];
extern s32 D_00922934[];
extern s32 D_00922930[];
extern s32 D_0092293C[];
extern u8 *(*D_008873F8[])();
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])();


extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbae8;
extern s32 iGpffffbaec;
extern u8 D_0070B610[];

extern s32 D_00724BEC;
extern s32 D_00724BF0;

extern u8 *D_00724C08;

extern u8 D_007130E8[];
extern s32 D_00724130;

struct MovieNativeWork;
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern u8 D_00712670[];
extern s32 D_00724BF4;
extern u8 D_00800000[];
extern u16 D_008C0276[];
extern char iGpffffb020[3];
extern char iGpffffb024[2];
extern char iGpffffb028[6];
extern s32 uGpffffb230;
extern s32 D_00724BC8;
extern s32 D_00724BF8;
extern u32 D_00724BFC;
extern u8 *D_00724C00;
extern u8 *D_00724C04;
extern WindowRenderStateSet D_00887300[];
extern s32 (*D_00887304[])(RwRenderState state, void *value);
extern u8 D_008872E0[];
extern s32 iGpffffaf60;
extern void mdlClumpSetEnvMapValue(s32 arg0, s32 arg1);
extern void mdlDrawSkyPass(u8 *arg0);
extern void mdlDrawVisibleAtomics(s32 arg0);
extern void func_00461560(u8 *arg0);
extern void func_00461a40(u8 *arg0);
extern void func_00461be0(u8 *arg0);

extern u32 iGpffffbb14;
extern u32 iGpffffbb10;
extern u32 iGpffffbb0c;
extern u32 iGpffffbb04;
/* sceMc2CheckAsync consumes the two command/result output pointers. */
extern s32 iGpffffba8c;
extern s32 iGpffffb198;
extern s32 iGpffffb194;
extern f32 iGpffffbb20;
extern f32 iGpffffbb1c;
extern f32 iGpffffbb24;
extern s32 func_00457120(void);
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
typedef struct RwMatrixTag RwMatrix;
typedef struct RwV3d RwV3d;
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;
extern RwMatrix *func_003e0680(RwMatrix *matrix, const RwV3d *axis,
                            f32 oneMinusCosine, f32 sine, RwOpCombineType combineOp);
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

/* Source unit: src/promoted/code1_0046.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0046.c; members 00462230-004623a0 */

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
// measured: opt_propagation off preserves the callback table pointer across jal calls while probing func_00462230.
/* measured: func_00462230 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00462230
void func_00462230(u8 *arg0)
{
    u8 *self;
    u8 *work;
    WindowRenderStateSet *table;

    self = arg0;
    work = *(u8 **)(self + 0x1C);
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        mdlClumpSetEnvMapValue(*(s32 *)(work + 0xDC), 1);
    }
    mdlDrawSkyPass(work);
    if ((*(s32 *)(work + 0xE0) == 0) ||
        ((*(s32 *)(work + 0xD8) & 0x800) != 0)) {
        RpSkyRenderStateSet(2, (void *)(*(s32 *)(work + 0xE4)));
        RpSkyRenderStateSet(3, (void *)(*(s32 *)(work + 0xE8)));
        self = (u8 *)D_00887300;
        ((WindowRenderStateSet *)self)[0]((RwRenderState)(6), (void *)(1));
        ((WindowRenderStateSet *)self)[0]((RwRenderState)(8), (void *)(0));
        mdlDrawVisibleAtomics(*(s32 *)(work + 0xDC));
    } else {
        table = D_00887300;
        table[0]((RwRenderState)(6), (void *)(1));
        table[0]((RwRenderState)(8), (void *)(0));
        *(u16 *)(self + 0x1A) |= 2;
        *(s32 *)(self + 0x1C) = *(s32 *)(work + 0xE0);
        func_00461560(self);
        func_00461a40(self);
        func_00461be0(self);
    }
    if ((*(s32 *)(work + 0xD8) & 0x400) != 0) {
        mdlClumpSetEnvMapValue(*(s32 *)(work + 0xDC), 0);
    }
}

// measured: closes opt_propagation around func_00462230.
/* Walks the ordering-table bucket list, calling each node's start callback and then the callback tables D_00887308..D_00887314 for each entry. */
// FUN_004623A0
void sdkOtFlushBuckets(u8 *arg0)
{
    u8 *p;
    s8 sp2C[4];
    s8 *ptr;
    s32 count;
    u16 type;
    void (*start_cb)(u8 *, s32, void *);
    void (*end_cb)(u8 *, s32, void *);
    extern void RwCameraClear(s32, s8 *, s32);
    extern s32 func_003c9d00(u8 *);
    extern void *K_Clump_RenderAtomicIfVisibleCb(void *, void *);
    extern void func_00410420(void *, u32, void *, u32);
    extern void func_004104d0(void);
    extern void func_00410520(u32, void *, u32);
    extern void func_004106a0(s32);
    extern s32 func_00410800(s32, s32, s32);
    extern s32 func_00410930(s32, s32);
    extern void TnDispatchObjectCallback(void *);
    extern void TnDispatchBlurCopied(void *);
    extern void TnDispatchBlurDirect(void *);
    extern void TnDispatchSkyDraw(void *);
    extern void TnDispatchBillboards(void *);
    extern void TnDispatchPairedDraw(void *);
    extern void func_00475cd0(void *);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void (*D_00887314[])(s32, void *, s32, void *, s32);
    extern void (*D_00887308[])(s32, s32, s32, s32);
    extern void (*D_0088730C[])(s32, s32, s32, s32, s32);

    p = arg0;
    while (p != NULL) {
        start_cb = (void (*)(u8 *, s32, void *))*(u32 *)(p + 8);
        if ((start_cb != NULL) && (((*(u16 *)(p + 0x1A) & 1) == 0) || (*(u32 *)p != 0))) {
            start_cb(p + 0x1C, *(s32 *)(p + 0x10), (void *)start_cb);
        }

        type = *(u16 *)(p + 0x18);
        switch (type) {
        case 1:
            ptr = &sp2C[0];
            count = 4;
            if (ptr != NULL) {
                do {
                    *ptr = 0;
                    ptr++;
                    count--;
                } while (count != 0);
            }
            RwCameraClear(func_00457120(), &sp2C[0], *(s32 *)(p + 0x1C));
            break;
        case 2:
            D_00887300[0]((RwRenderState)(*(s32 *)(p + 0x1C)), (void *)(*(s32 *)(p + 0x20)));
            break;
        case 3:
            RpSkyRenderStateSet(*(s32 *)(p + 0x1C), (void *)(*(s32 *)(p + 0x20)));
            break;
        case 4:
            {
                u8 *obj = *(u8 **)(p + 0x1C);
                ((void (*)(u8 *))*(u32 *)((u8 *)obj + 0x48))(obj);
            }
            break;
        case 5:
            func_00461560(p);
            func_00461a40(p);
            func_00461be0(p);
            break;
        case 6:
            func_00461560(p);
            break;
        case 7:
            func_00461a40(p);
            break;
        case 8:
            func_00461be0(p);
            break;
        case 9:
            RpClumpForAllAtomics(*(void **)(p + 0x1C), K_Clump_RenderAtomicIfVisibleCb, NULL);
            break;
        case 10:
            func_003c9d00(*(u8 **)(p + 0x1C));
            break;
        case 11:
            D_00887310[0](*(s32 *)(p + 0x1C), *(void **)(p + 0x20), *(s32 *)(p + 0x24));
            break;
        case 12:
            D_00887314[0](*(s32 *)(p + 0x1C), *(void **)(p + 0x20), *(s32 *)(p + 0x24), *(void **)(p + 0x28), *(s32 *)(p + 0x2C));
            break;
        case 13:
            D_00887308[0](*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28));
            break;
        case 14:
            D_0088730C[0](*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24), *(s32 *)(p + 0x28), *(s32 *)(p + 0x2C));
            break;
        case 15:
            func_00410420(*(void **)(p + 0x1C), *(u32 *)(p + 0x20), *(void **)(p + 0x24), *(u32 *)(p + 0x28));
            break;
        case 16:
            func_004104d0();
            break;
        case 17:
            func_00410930(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20));
            break;
        case 18:
            func_00410800(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x20), *(s32 *)(p + 0x24));
            break;
        case 19:
            func_004106a0(*(s32 *)(p + 0x1C));
            break;
        case 20:
            func_00410520(*(u32 *)(p + 0x1C), *(void **)(p + 0x20), *(u32 *)(p + 0x24));
            break;
        case 21:
            TnDispatchObjectCallback(*(void **)(p + 0x1C));
            break;
        case 22:
            TnDispatchBlurCopied(*(void **)(p + 0x1C));
            break;
        case 23:
            TnDispatchBlurDirect(*(void **)(p + 0x1C));
            break;
        case 24:
            TnDispatchSkyDraw(*(void **)(p + 0x1C));
            break;
        case 25:
            TnDispatchBillboards(*(void **)(p + 0x1C));
            break;
        case 26:
            TnDispatchPairedDraw(*(void **)(p + 0x1C));
            break;
        case 27:
            func_00462230(p);
            break;
        case 28:
            func_00475cd0(*(void **)(p + 0x1C));
            break;
        default:
            break;
        }

        end_cb = (void (*)(u8 *, s32, void *))*(u32 *)(p + 0xC);
        if ((end_cb != NULL) && (((*(u16 *)(p + 0x1A) & 1) == 0) || (*(u32 *)p != 0))) {
            end_cb(p + 0x1C, *(s32 *)(p + 0x14), (void *)end_cb);
        }

        p = *(u8 **)p;
    }
}

