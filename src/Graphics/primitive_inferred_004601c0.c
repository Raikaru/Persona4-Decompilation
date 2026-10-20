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
extern s32 func_003e1220(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
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
extern void *memset(void *dst, s32 value, size_t size);
extern s32 D_00724B88;
extern s32 D_00724B8C;

extern void (*jtbl_008873FC[])();

extern void kwlnTaskRegisterCallback(s32 task);

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
extern s32 RwCameraFrustumTestSphere(s32, u8 *);

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
extern f32 cosf(f32);
extern f32 sinf(f32);
extern void primLine3D(void *startPos, void *endPos, void *color, s32 saveAndRestoreRenderState);
/* Same RwV3d tag and fields as the ring provider and RenderWare. */
#include "rw_types_internal.h"
typedef RwV3d Code46RingPoint;
extern void primCircleLine3D(const Code46RingPoint *center, f32 radius,
                         u8 *inputColors, f32 *inputMatrix, s32 inputPreserveState);
struct Data_00712508 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};
extern struct Data_00712508 D_00712508[] __attribute__((aligned(8)));
extern f32 fGpffff81f0;
extern void RwMatrixRotate(void *, void *, s32, f32 fparg0);
typedef struct RwMatrixTag RwMatrix;
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0046; members 004601c0-00460a80 */

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
/* Frustum-test a sphere and draw nine latitude rings in each of two perpendicular planes. */
// FUN_004601C0
void primSphereLine3D(u8 *center, f32 radius, u8 *color, s32 preserveState) {
    struct Data_00712508 rotationAxis __attribute__((aligned(16)));
    Code46RingPoint ringCenter;
    f32 matrix[4][4];
    s32 savedStates[6];
    f32 sphere[4];
    f32 ringRadius;
    f32 crossRadius;
    f32 sliceValue;
    f32 ringValue;
    u32 arcIndex;
    u32 arcIndexB;
    u32 restoreIndex;
    u32 saveIndex;
    s32 *stateEntry;
    rotationAxis = D_00712508[0];
    sphere[3] = radius;
    sphere[0] = ((RwV3d *)center)->x;
    /* measured: typing either Y or Z snapshot grows 784B to 796B; retain only these raw loads. */
    sphere[1] = *(f32 *)(center + 4);
    sphere[2] = *(f32 *)(center + 8);
    if (RwCameraFrustumTestSphere(*(s32 *)D_008872E0, (u8 *)&sphere[0]) != 0) {
        if (preserveState != 0) {
            for (saveIndex = 0; saveIndex < 6U; saveIndex++) {
                stateEntry = &D_00712490[saveIndex * 2];
                ((WindowRenderStateCall)D_00887304[0])((RwRenderState)(stateEntry[0]), (void *)(&savedStates[saveIndex]));
                D_00887300[0]((RwRenderState)(stateEntry[0]), (void *)(stateEntry[1]));
            }
            D_00887300[0]((RwRenderState)(1), (void *)(0));
            RpSkyRenderStateSet(2, (void *)(0x48));
            RpSkyRenderStateSet(3, (void *)(0x71801));
        }
        matrix[2][2] = 1.0f;
        matrix[1][1] = 1.0f;
        matrix[0][0] = 1.0f;
        ringValue = 0.0f;
        matrix[1][0] = 0.0f;
        matrix[0][2] = 0.0f;
        matrix[0][1] = 0.0f;
        matrix[2][1] = 0.0f;
        matrix[2][0] = 0.0f;
        matrix[1][2] = 0.0f;
        matrix[3][2] = 0.0f;
        matrix[3][1] = 0.0f;
        matrix[3][0] = 0.0f;
        /* Retail's identity macro preserves the unwritten flags word, as in primCircleLine3D. */
        *(s32 *)&matrix[0][3] |= 0x20003;
        for (arcIndex = 0; arcIndex < 9U; arcIndex++) {
            ringValue += fGpffff81f0;
            sliceValue = radius * cosf(ringValue);
            ringRadius = radius * sinf(ringValue);
            ringCenter.x = ((RwV3d *)center)->x;
            ringCenter.y = ((RwV3d *)center)->y + sliceValue;
            ringCenter.z = ((RwV3d *)center)->z;
            primCircleLine3D(&ringCenter, ringRadius, color, &matrix[0][0], 0);
        }
        RwMatrixRotate(&matrix[0][0], &rotationAxis, 2, 90.0f);
        sliceValue = 0.0f;
        for (arcIndexB = 0; arcIndexB < 9U; arcIndexB++) {
            sliceValue += fGpffff81f0;
            ringValue = radius * cosf(sliceValue);
            crossRadius = radius * sinf(sliceValue);
            ringCenter.x = ((RwV3d *)center)->x;
            ringCenter.y = ((RwV3d *)center)->y;
            ringCenter.z = ((RwV3d *)center)->z + ringValue;
            primCircleLine3D(&ringCenter, crossRadius, color, &matrix[0][0], 0);
        }
        if (preserveState != 0) {
            for (restoreIndex = 0; restoreIndex < 6U; restoreIndex++) {
                ((WindowRenderStateCall)D_00887300[0])((RwRenderState)(D_00712490[restoreIndex * 2]), (void *)(savedStates[restoreIndex]));
            }
        }
    }
}

/* Draw a wireframe cylinder using circular slices and paired line endpoints.
 * The ring API takes radius second; all native integer/floating arguments keep
 * that order. b210 -O2: 1076 executable bytes plus twelve zero alignment bytes.
 * See docs/Window_render_contract_recovery_20260920.md for the resolved proof. */
// FUN_004604D0
void primCylinderLine3D(f32 *position, f32 radius, f32 height, u8 *color, s32 setStates) {
    Code46RingPoint circlePosition;
    f32 endpoints[2][3];
    s32 savedStates[6];
    f32 sphere[4];
    f32 sideAngle;
    f32 verticalOffset;
    f32 oppositeAngle;
    f32 x;
    f32 z;
    f32 oppositeX;
    f32 edgeZ;
    f32 oppositeZ;
    f32 scratch;
    f32 angle;
    f32 halfHeight;
    u32 restoreIndex;
    u32 segmentIndex;
    u32 stateIndex;
    s32 *stateEntry;

    if (radius > height) {
        scratch = radius;
    } else {
        scratch = height;
    }
    sphere[3] = scratch;
    sphere[0] = position[0];
    sphere[1] = position[1];
    sphere[2] = position[2];
    if (RwCameraFrustumTestSphere(*(s32 *)D_008872E0, (u8 *)&sphere[0]) != 0) {
        if (setStates != 0) {
            stateIndex = 0;
            for (stateIndex = 0; stateIndex < 6U; stateIndex++) {
                stateEntry = &D_00712490[stateIndex * 2];
                ((WindowRenderStateCall)D_00887304[0])((RwRenderState)(stateEntry[0]), (void *)(&savedStates[stateIndex]));
                D_00887300[0]((RwRenderState)(stateEntry[0]), (void *)(stateEntry[1]));
            }
            D_00887300[0]((RwRenderState)(1), (void *)(0));
            RpSkyRenderStateSet(2, (void *)(0x48));
            RpSkyRenderStateSet(3, (void *)(0x71801));
        }
        verticalOffset = height / 7.0f;
        circlePosition.x = position[0];
        halfHeight = 0.5f * height;
        circlePosition.y = position[1] - halfHeight;
        circlePosition.z = position[2];
        segmentIndex = 0;
        for (; segmentIndex < 8U; segmentIndex++) {
            primCircleLine3D(&circlePosition, radius, color, 0, 0);
            circlePosition.y += verticalOffset;
        }
        sideAngle = 0.0f;
        segmentIndex = 0;
        scratch = -height;
        verticalOffset = 0.5f * scratch;
        for (; segmentIndex < 10U; segmentIndex++) {
            endpoints[0][0] = radius * cosf(sideAngle);
            endpoints[0][1] = verticalOffset;
            edgeZ = radius * sinf(sideAngle);
            endpoints[0][2] = edgeZ;
            endpoints[1][0] = endpoints[0][0];
            endpoints[1][1] = halfHeight;
            endpoints[1][2] = edgeZ;
            endpoints[0][0] = endpoints[0][0] + position[0];
            endpoints[0][1] = endpoints[0][1] + position[1];
            endpoints[0][2] = endpoints[0][2] + position[2];
            endpoints[1][0] = endpoints[0][0];
            endpoints[1][1] = halfHeight + position[1];
            endpoints[1][2] = endpoints[0][2];
            primLine3D(&endpoints[0][0], &endpoints[1][0], color, 0);
            sideAngle += fGpffff84f0;
        }
        angle = 0.0f;
        segmentIndex = 0;
        for (; segmentIndex < 5U; segmentIndex++) {
            x = radius * cosf(angle);
            endpoints[0][0] = x;
            endpoints[0][1] = verticalOffset;
            z = radius * sinf(angle);
            endpoints[0][2] = z;
            oppositeAngle = fGpffff82fc + angle;
            oppositeX = radius * cosf(oppositeAngle);
            endpoints[1][0] = oppositeX;
            endpoints[1][1] = verticalOffset;
            oppositeZ = radius * sinf(oppositeAngle);
            endpoints[1][2] = oppositeZ;
            endpoints[0][0] = endpoints[0][0] + position[0];
            endpoints[0][1] = endpoints[0][1] + position[1];
            endpoints[0][2] = endpoints[0][2] + position[2];
            endpoints[1][0] = endpoints[1][0] + position[0];
            endpoints[1][1] = endpoints[1][1] + position[1];
            endpoints[1][2] = endpoints[1][2] + position[2];
            primLine3D(&endpoints[0][0], &endpoints[1][0], color, 0);
            endpoints[0][1] = endpoints[0][1] + height;
            endpoints[1][1] = endpoints[1][1] + height;
            primLine3D(&endpoints[0][0], &endpoints[1][0], color, 0);
            angle += fGpffff84f0;
        }
        if (setStates != 0) {
            restoreIndex = 0;
            for (restoreIndex = 0; restoreIndex < 6U; restoreIndex++) {
                ((WindowRenderStateCall)D_00887300[0])((RwRenderState)(D_00712490[restoreIndex * 2]), (void *)(savedStates[restoreIndex]));
            }
        }
    }
}

// Creates the queue pool (tag 0x41002) and the batch pool (tag 0x41003) of 0x30-byte nodes; stores the handles in iGpffffba98 and iGpffffba9c.
// FUN_00460910
void PrimCreatePools(s32 queueCount, s32 batchCount)
{
    iGpffffba98 = func_003e1220(0x30, queueCount, 4, 1, D_008E43C0, 0x41002);
    iGpffffba9c = func_003e1220(0x30, batchCount, 4, 1, D_008E43E4, 0x41003);
}

// Takes one zeroed 0x30-byte node from the queue pool (D_00724B88, tag 0x41002).
// FUN_00460990
u8 *PrimAllocQueueNode(void)
{
    u8 *block = D_008873F8[0](D_00724B88, 0x41002);

    memset(block, 0, 0x30);
    return block;
}

// Takes one zeroed 0x30-byte node from the batch pool (D_00724B8C, tag 0x41003).
// FUN_004609F0
u8 *PrimAllocBatchNode(void)
{
    u8 *block = D_008873F8[0](D_00724B8C, 0x41003);

    memset(block, 0, 0x30);
    return block;
}

// Returns one node to the batch pool (D_00724B8C) through its free routine.
// FUN_00460A50
void PrimFreeBatchNode(s32 node)
{
    jtbl_008873FC[0](D_00724B8C, node);
}

// Zeroes arg1 consecutive 0x30-byte nodes at arg0, then calls kwlnTaskRegisterCallback on the queue pool handle (D_00724B88).
// FUN_00460A80
void PrimClearNodes(s32 nodes, s32 count)
{
    memset((void *)nodes, 0, count * 0x30);
    kwlnTaskRegisterCallback(D_00724B88);
}

