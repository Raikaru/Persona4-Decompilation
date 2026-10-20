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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0046; members 00462bf0-00462df0 */

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
/* The destructor walks nine independent lists; every node links at +0x24.
 * Their individual payloads are not inspected by these two entry points. */
typedef union HMaestroListLink {
    s32 value;
    u8 *node;
} HMaestroListLink;
typedef struct HMaestroListNode {
    u8 pad00[0x24];
    s32 next;
} HMaestroListNode;
typedef struct HMaestroListSet {
    s32 active;
    s32 unk04;
    HMaestroListLink lists[9];
} HMaestroListSet;
/* Free every node in each list, then free the containing list set.
 * Keep raw head accesses: typed union heads merge reloads across free and lose MATCH.
 * The nine heads are +8..+0x28 and each node links at +0x24. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 45, 78, 110, 143, 176, 209, 242, 275, 308, 355, 356, 358, 359, 360, 361, 362, 363, 364; retain their original address/alias expressions. */
// FUN_00462BF0
void hMaestroFreeListSet(u8 *listSet)
{
    HMaestroListSet *lists0NodeFields;
    HMaestroListSet *lists0ValueFields;
    HMaestroListSet *lists4NodeFields;
    HMaestroListSet *lists4ValueFields;
    HMaestroListSet *lists5NodeFields;
    HMaestroListSet *lists5ValueFields;
    HMaestroListSet *lists1NodeFields;
    HMaestroListSet *lists1ValueFields;
    HMaestroListSet *lists2NodeFields;
    HMaestroListSet *lists2ValueFields;
    HMaestroListSet *lists6NodeFields;
    HMaestroListSet *lists6ValueFields;
    HMaestroListSet *lists3NodeFields;
    HMaestroListSet *lists3ValueFields;
    HMaestroListSet *lists7NodeFields;
    HMaestroListSet *lists7ValueFields;
    HMaestroListSet *lists8NodeFields;
    HMaestroListSet *lists8ValueFields;

    u8 *current;
    s32 next;

    if (listSet == NULL) {
        return;
    }
    while (((HMaestroListSet *)listSet)->lists[0].value != 0) {
        current = (lists0NodeFields = (HMaestroListSet *)(listSet), lists0NodeFields)->lists[0].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists0ValueFields = (HMaestroListSet *)(listSet), lists0ValueFields)->lists[0].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[4].value != 0) {
        current = (lists4NodeFields = (HMaestroListSet *)(listSet), lists4NodeFields)->lists[4].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists4ValueFields = (HMaestroListSet *)(listSet), lists4ValueFields)->lists[4].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[5].value != 0) {
        current = (lists5NodeFields = (HMaestroListSet *)(listSet), lists5NodeFields)->lists[5].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists5ValueFields = (HMaestroListSet *)(listSet), lists5ValueFields)->lists[5].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[1].value != 0) {
        current = (lists1NodeFields = (HMaestroListSet *)(listSet), lists1NodeFields)->lists[1].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists1ValueFields = (HMaestroListSet *)(listSet), lists1ValueFields)->lists[1].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[2].value != 0) {
        current = (lists2NodeFields = (HMaestroListSet *)(listSet), lists2NodeFields)->lists[2].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists2ValueFields = (HMaestroListSet *)(listSet), lists2ValueFields)->lists[2].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[6].value != 0) {
        current = (lists6NodeFields = (HMaestroListSet *)(listSet), lists6NodeFields)->lists[6].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists6ValueFields = (HMaestroListSet *)(listSet), lists6ValueFields)->lists[6].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[3].value != 0) {
        current = (lists3NodeFields = (HMaestroListSet *)(listSet), lists3NodeFields)->lists[3].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists3ValueFields = (HMaestroListSet *)(listSet), lists3ValueFields)->lists[3].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[7].value != 0) {
        current = (lists7NodeFields = (HMaestroListSet *)(listSet), lists7NodeFields)->lists[7].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists7ValueFields = (HMaestroListSet *)(listSet), lists7ValueFields)->lists[7].value = next;
    }
    while (((HMaestroListSet *)listSet)->lists[8].value != 0) {
        current = (lists8NodeFields = (HMaestroListSet *)(listSet), lists8NodeFields)->lists[8].node;
        next = ((HMaestroListNode *)current)->next;
        jtbl_008873EC[0](current);
        (lists8ValueFields = (HMaestroListSet *)(listSet), lists8ValueFields)->lists[8].value = next;
    }
    jtbl_008873EC[0](listSet);
}

/* Report whether an active set contains any of the seven tested list kinds. */
// FUN_00462DF0
s32 hMaestroListSetHasEntries(u8 *listSet) {
    if (listSet == NULL) {
        return 0;
    }
    if ((((HMaestroListSet *)listSet)->active == 0) ||
        ((((HMaestroListSet *)listSet)->lists[2].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[1].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[3].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[4].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[5].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[7].value == 0) &&
         (((HMaestroListSet *)listSet)->lists[8].value == 0))) {
        return 0;
    }
    return 1;
}

