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

extern void kAssertFail(void *arg0, s32 arg1);
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
extern s32 sdkListStateHandleInput(u8 *arg0);
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
extern s32 func_00457120(void);
extern s32 sprintf(char *dst, const char *fmt, ...);
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

/* Source unit: src/promoted/code1_0046.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0046.c; members 0046d6b0-0046f2b0 */

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
extern u32 ourGlobals[4096];
extern void kAssertFailMsg(const char *file, s32 line, const char *msg, ...);
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
extern s32 sdkWindowUpdate(u8 *);
extern void chkmemAllocSiteTag(void *, s32);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_007130F8[], D_00713108[];
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
/* Measured: 1252/1264 native bytes, 20 resolved relocations and twelve
 * zero alignment bytes; 57 neighboring functions and data preserved.
 * See docs/probe_archive/Filer_navigation_00467bd0_20260924.md. */
#pragma push
/* measured: share the checked path index and hoist the slash constant. */
#pragma pop
/* Measured: 652/656 bytes, eight resolved relocations and four zero tail bytes.
 * Request handles and resource tables are reloaded after their callbacks. */
#pragma push
#pragma pop
#pragma push
#pragma pop
// FUN_0046D6B0
void sdkSetActiveHandle(s32 arg0)
{
    if (arg0 == 0) {
        kAssertFail(D_007130E8, 0x37);
    }
    D_00724130 = arg0;
}

// FUN_0046D700
void kAssertFailMsg(const char *file, s32 line, const char *msg, ...)
{
}

// Intent: assert-fail reporter for a failed K_ASSERT-style guard; takes the source file and line. Empty in this build. [inferred]
// FUN_0046D730
void kAssertFail(void *arg0, s32 arg1) {}

// FUN_0046D740
void kAssertFailAt(const void *msg, const void *file, u32 line) {}

/* Initialize and animate the border and fill vertices, then submit the
 * enabled window. The function owns its nine-entry state switch table.
 * MWCCPS2 b210: 4244 executable bytes, followed by twelve zero bytes. */
#pragma push
/* measured: sdkWindowUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: sdkWindowUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// FUN_0046D750
s32 sdkWindowUpdate(u8 *arg0) {
    extern u32 func_003e8120(u32 camera);
    extern u32 func_003e8110(u32 camera);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern void sdkWindowSetRect(u8 *arg0, u8 *arg1);
    f32 f2;
    f32 f1;
    s32 i;
    s32 j;
    s32 k;
    u8 *work;
    u8 *g;
    u8 *e;
    s32 state;
    WindowRenderStateSet *tbl00;
    s32 (**tbl10)(s32, void *, s32);

    work = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        f2 = *(f32 *)((u8 *)func_00457120() + 0x80) - 400.0f;
        f1 = 1.0f / f2;
        i = 0;
        goto test0o;
body0o:
        g = work + (i << 8);
        *(s32 *)(g + 0x60) = 0;
        *(s32 *)(g + 0x64) = 0;
        *(f32 *)(g + 0x68) = f2;
        *(s32 *)(g + 0xA0) = 0;
        *(s32 *)(g + 0xA4) = 0;
        *(f32 *)(g + 0xA8) = f2;
        *(s32 *)(g + 0xE0) = 0;
        *(s32 *)(g + 0xE4) = 0;
        *(f32 *)(g + 0xE8) = f2;
        *(s32 *)(g + 0x120) = 0;
        *(s32 *)(g + 0x124) = 0;
        *(f32 *)(g + 0x128) = f2;
        *(f32 *)(g + 0x78) = f1;
        *(f32 *)(g + 0xB8) = f1;
        *(f32 *)(g + 0xF8) = f1;
        *(f32 *)(g + 0x138) = f1;
        j = 0;
        goto test0i;
body0i:
        e = g + (j << 6);
        *(f32 *)(e + 0x80) = (f32)*(u8 *)(work + 0x1C);
        *(f32 *)(e + 0x84) = (f32)*(u8 *)(work + 0x1D);
        *(f32 *)(e + 0x88) = (f32)*(u8 *)(work + 0x1E);
        *(f32 *)(e + 0x8C) = (f32)*(u8 *)(work + 0x1F);
        j++;
test0i:
        if (j < 4) {
            goto body0i;
        }
        i++;
test0o:
        if (i < 4) {
            goto body0o;
        }
        *(f32 *)(work + 0x460) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x464) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x468) = f2;
        *(f32 *)(work + 0x4A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x4A4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x4A8) = f2;
        *(f32 *)(work + 0x4E0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x4E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x4E8) = f2;
        *(f32 *)(work + 0x520) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x524) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x528) = f2;
        *(f32 *)(work + 0x478) = f1;
        *(f32 *)(work + 0x4B8) = f1;
        *(f32 *)(work + 0x4F8) = f1;
        *(f32 *)(work + 0x538) = f1;
        k = 0;
        goto test0k;
body0k:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(s32 *)(e + 0x48C) = 0;
        k++;
test0k:
        if (k < 4) {
            goto body0k;
        }
        *(f32 *)(work + 0x40) = (f32)*(u8 *)(work + 0x23);
        *(u8 *)(work + 0x23) = 0;
        *(s32 *)work = *(s32 *)work + 1;
        *(u8 *)(work + 0x23) = (u8)(*(f32 *)(work + 0x40));
        k = 0;
        goto test0k2;
body0k2:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        k++;
test0k2:
        if (k < 4) {
            goto body0k2;
        }
        *(s32 *)work = 6;
        break;
    case 1:
        if (!(*(f32 *)(work + 0x30) < (f32)*(s32 *)(work + 0x14))) {
            *(f32 *)(work + 0x30) = (f32)*(s32 *)(work + 0x14);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x60) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x64) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0xA0) = (f32)*(s32 *)(work + 0xC) + *(f32 *)(work + 0x30);
        *(f32 *)(work + 0xA4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0xE0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0xE4) = (f32)(*(s32 *)(work + 0x10) + 2);
        *(f32 *)(work + 0x120) = (f32)*(s32 *)(work + 0xC) + *(f32 *)(work + 0x30);
        *(f32 *)(work + 0x124) = (f32)(*(s32 *)(work + 0x10) + 2);
        *(f32 *)(work + 0x30) = *(f32 *)(work + 0x30) + (f32)*(s32 *)(work + 0x14) / 2.0f;
        break;
    case 2:
        if (!(*(f32 *)(work + 0x34) < (f32)*(s32 *)(work + 0x18))) {
            *(f32 *)(work + 0x34) = (f32)*(s32 *)(work + 0x18);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x160) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14) - 2);
        *(f32 *)(work + 0x164) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x1A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x1A4) = (f32)*(s32 *)(work + 0x10);
        *(f32 *)(work + 0x1E0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14) - 2);
        *(f32 *)(work + 0x1E4) = (f32)*(s32 *)(work + 0x10) + *(f32 *)(work + 0x34);
        *(f32 *)(work + 0x220) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x224) = (f32)*(s32 *)(work + 0x10) + *(f32 *)(work + 0x34);
        *(f32 *)(work + 0x34) = *(f32 *)(work + 0x34) + (f32)*(s32 *)(work + 0x18) / 2.0f;
        break;
    case 3:
        if (!(*(f32 *)(work + 0x38) < (f32)*(s32 *)(work + 0x14))) {
            *(f32 *)(work + 0x38) = (f32)*(s32 *)(work + 0x14);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x260) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14)) - *(f32 *)(work + 0x38);
        *(f32 *)(work + 0x264) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18) - 2);
        *(f32 *)(work + 0x2A0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x2A4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18) - 2);
        *(f32 *)(work + 0x2E0) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14)) - *(f32 *)(work + 0x38);
        *(f32 *)(work + 0x2E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x320) = (f32)(*(s32 *)(work + 0xC) + *(s32 *)(work + 0x14));
        *(f32 *)(work + 0x324) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x38) = *(f32 *)(work + 0x38) + (f32)*(s32 *)(work + 0x14) / 2.0f;
        break;
    case 4:
        if (!(*(f32 *)(work + 0x3C) < (f32)*(s32 *)(work + 0x18))) {
            *(f32 *)(work + 0x3C) = (f32)*(s32 *)(work + 0x18);
            *(s32 *)work = *(s32 *)work + 1;
        }
        *(f32 *)(work + 0x360) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x364) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18)) - *(f32 *)(work + 0x3C);
        *(f32 *)(work + 0x3A0) = (f32)(*(s32 *)(work + 0xC) + 2);
        *(f32 *)(work + 0x3A4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18)) - *(f32 *)(work + 0x3C);
        *(f32 *)(work + 0x3E0) = (f32)*(s32 *)(work + 0xC);
        *(f32 *)(work + 0x3E4) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x420) = (f32)(*(s32 *)(work + 0xC) + 2);
        *(f32 *)(work + 0x424) = (f32)(*(s32 *)(work + 0x10) + *(s32 *)(work + 0x18));
        *(f32 *)(work + 0x3C) = *(f32 *)(work + 0x3C) + (f32)*(s32 *)(work + 0x18) / 2.0f;
        break;
    case 5: {
        u8 c;
        c = (u8)(*(f32 *)(work + 0x40));
        if (*(u8 *)(work + 0x23) < c) {
            f32 fb;
            f32 f;
            fb = (f32)*(u8 *)(work + 0x23);
            f = fb + *(f32 *)(work + 0x40) / 8.0f;
            *(u8 *)(work + 0x23) = (u8)f;
        } else {
            *(u8 *)(work + 0x23) = (u8)(*(f32 *)(work + 0x40));
            *(s32 *)work = *(s32 *)work + 1;
        }
        for (k = 0; k < 4; k++) {
            e = work + (k << 6);
            *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
            *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
            *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
            *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        }
        break;
    }
    case 6:
        sdkWindowSetRect(arg0, work + 0xC);
        break;
    case 7:
        if (*(u8 *)(work + 0x23) > 0) {
            *(u8 *)(work + 0x23) = *(u8 *)(work + 0x23) - 1;
        }
        if (*(u8 *)(work + 0x1F) > 0) {
            *(u8 *)(work + 0x1F) = *(u8 *)(work + 0x1F) - 1;
        }
        i = 0;
        goto test7o;
body7o:
        j = 0;
        g = work + (i << 8);
        goto test7i;
body7i:
        e = g + (j << 6);
        *(f32 *)(e + 0x80) = (f32)*(u8 *)(work + 0x1C);
        *(f32 *)(e + 0x84) = (f32)*(u8 *)(work + 0x1D);
        *(f32 *)(e + 0x88) = (f32)*(u8 *)(work + 0x1E);
        *(f32 *)(e + 0x8C) = (f32)*(u8 *)(work + 0x1F);
        j++;
test7i:
        if (j < 4) {
            goto body7i;
        }
        i++;
test7o:
        if (i < 4) {
            goto body7o;
        }
        k = 0;
        goto test7k;
body7k:
        e = work + (k << 6);
        *(f32 *)(e + 0x480) = (f32)*(u8 *)(work + 0x20);
        *(f32 *)(e + 0x484) = (f32)*(u8 *)(work + 0x21);
        *(f32 *)(e + 0x488) = (f32)*(u8 *)(work + 0x22);
        *(f32 *)(e + 0x48C) = (f32)*(u8 *)(work + 0x23);
        k++;
test7k:
        if (k < 4) {
            goto body7k;
        }
        /* Retail tests the same loaded alpha byte twice. */
        if (*(u8 *)(work + 0x23) == 0 && *(u8 *)(work + 0x23) == 0) {
            *(s32 *)work = *(s32 *)work + 1;
        }
        break;
    case 8:
        return -1;
    }
    if (*(s32 *)(work + 4) == 1) {
        if (func_003e8120((u32)func_00457120()) != 0) {
            tbl00 = &((WindowEngineStatePrefix *)ourGlobals)->device.setState;
            tbl00[0]((RwRenderState)(6), (void *)(1));
            tbl00[0]((RwRenderState)(8), (void *)(0));
            tbl00[0]((RwRenderState)(7), (void *)(2));
            tbl00[0]((RwRenderState)(0xC), (void *)(1));
            tbl00[0]((RwRenderState)(1), (void *)(0));
            RpSkyRenderStateSet(2, (void *)(0x44));
            RpSkyRenderStateSet(3, (void *)(0x717FB));
            tbl10 = D_00887310;
            tbl10[0](4, work + 0x460, 4);
            tbl10[0](4, work + 0x60, 4);
            tbl10[0](4, work + 0x160, 4);
            tbl10[0](4, work + 0x260, 4);
            tbl10[0](4, work + 0x360, 4);
        }
        func_003e8110((u32)func_00457120());
    }
    return 0;
}

#pragma pop
// FUN_0046E7F0
/* Keep the table address cached without changing the free callback type. */
#pragma push
/* measured: sdkWindowDestroy MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void sdkWindowDestroy(u8 *arg0)
{
    void (**tbl)(void *) = jtbl_008873EC;
    u8 *work = *(u8 **)(arg0 + 0x38);

    tbl[0](*(u8 **)(work + 0x48));
    tbl[0](*(u8 **)(arg0 + 0x38));
}

#pragma pop
/* Pointer-valued task name restores retail argument setup.
 * MWCCPS2 b210 -O2: 444 executable bytes / 448-byte retail window.
 * The buffer calculation uses rectangle x/y, not width/height. */
#pragma push
/* measured: sdkWindowCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0046E850
u8 *sdkWindowCreate(u8 *parent, void *rect_arg, void *first_arg, void *second_arg)
{
    typedef struct WindowRect { s32 x, y, width, height; } WindowRect;
    typedef struct WindowColor { u8 r, g, b, a; } WindowColor;
    typedef struct WindowWork {
        s32 state, enabled;
        u8 reserved08[4];
        WindowRect rect;
        WindowColor first, second;
        u8 reserved24[32];
        size_t buffer_size;
        u8 *buffer, *cursor;
    } WindowWork;
    WindowRect *rect = (WindowRect *)rect_arg;
    WindowColor *first = (WindowColor *)first_arg;
    WindowColor *second = (WindowColor *)second_arg;
    s32 result;
    WindowWork *work;
    u8 *buffer;
    size_t *size;
    void *(**allocator)(size_t, size_t, u32);

    chkmemAllocSiteTag(D_007130F8, 379);
    allocator = D_008873F4;
    work = (WindowWork *)allocator[0](1, 0x560, 0x40000);
    if (work == NULL) {
        return NULL;
    }
    result = (s32)kwlnTaskCreateChild((void *)((s32)parent), (const void *)(D_00713108), 0x101, 0, 0, sdkWindowUpdate, sdkWindowDestroy, (u8 *)((u8 *)work));
    work->enabled = 1;
    work->rect = *rect;
    work->first = *first;
    work->second = *second;
    size = &work->buffer_size;
    *size = (rect->x / 8) * (rect->y / 8) + 32;
    chkmemAllocSiteTag(D_007130F8, 396);
    buffer = allocator[0](1, *size, 0x40000);
    work->buffer = buffer;
    work->cursor = buffer;
    return (u8 *)result;
}

#pragma pop
// FUN_0046EA10
s32 sdkWindowIsOpen(u8 *arg0)
{
    s32 value = *(s32 *)(*(u8 **)(arg0 + 0x38));

    if ((value == 6) || (value == 8)) {
        return 0;
    }
    return 1;
}

// FUN_0046EA50
void sdkWindowSetCommand(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}

// FUN_0046EA60
void sdkWindowSetRect(u8 *arg0, u8 *arg1)
{
    struct FInput {
        f32 f0;
        f32 f4;
        f32 f8;
        f32 fC;
    };
    union Input {
        struct {
            s32 sp0;
            s32 sp4;
            s32 sp8;
            s32 spC;
        } i;
        struct FInput f;
    } input;
#define sp0 input.i.sp0
#define sp4 input.i.sp4
#define sp8 input.i.sp8
#define spC input.i.spC
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 bottom;
    s32 sum;
    u8 *record;

    input = *(union Input *)arg1;
    record = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(record + 0) == 6) {
        *(struct FInput *)(record + 0xC) = input.f;
        temp_f4 = (f32)sp0;
        *(f32 *)(record + 0x60) = temp_f4;
        temp_f3 = (f32)sp4;
        *(f32 *)(record + 0x64) = temp_f3;
        sum = sp0 + sp8;
        temp_f2 = (f32)sum;
        *(f32 *)(record + 0xA0) = temp_f2;
        *(f32 *)(record + 0xA4) = temp_f3;
        *(f32 *)(record + 0xE0) = temp_f4;
        temp_f0 = (f32)(sp4 + 2);
        *(f32 *)(record + 0xE4) = temp_f0;
        *(f32 *)(record + 0x120) = temp_f2;
        *(f32 *)(record + 0x124) = temp_f0;
        temp_f0_2 = (f32)(sum - 2);
        *(f32 *)(record + 0x160) = temp_f0_2;
        *(f32 *)(record + 0x164) = temp_f3;
        *(f32 *)(record + 0x1A0) = temp_f2;
        *(f32 *)(record + 0x1A4) = temp_f3;
        *(f32 *)(record + 0x1E0) = temp_f0_2;
        bottom = sp4 + spC;
        temp_f1 = (f32)bottom;
        *(f32 *)(record + 0x1E4) = temp_f1;
        *(f32 *)(record + 0x220) = temp_f2;
        *(f32 *)(record + 0x224) = temp_f1;
        *(f32 *)(record + 0x260) = temp_f4;
        temp_f0_3 = (f32)(bottom - 2);
        *(f32 *)(record + 0x264) = temp_f0_3;
        *(f32 *)(record + 0x2A0) = temp_f2;
        *(f32 *)(record + 0x2A4) = temp_f0_3;
        *(f32 *)(record + 0x2E0) = temp_f4;
        *(f32 *)(record + 0x2E4) = temp_f1;
        *(f32 *)(record + 0x320) = temp_f2;
        *(f32 *)(record + 0x324) = temp_f1;
        *(f32 *)(record + 0x360) = temp_f4;
        *(f32 *)(record + 0x364) = temp_f3;
        temp_f0_4 = (f32)(sp0 + 2);
        *(f32 *)(record + 0x3A0) = temp_f0_4;
        *(f32 *)(record + 0x3A4) = temp_f3;
        *(f32 *)(record + 0x3E0) = temp_f4;
        *(f32 *)(record + 0x3E4) = temp_f1;
        *(f32 *)(record + 0x420) = temp_f0_4;
        *(f32 *)(record + 0x424) = temp_f1;
        *(f32 *)(record + 0x460) = (f32)*(s32 *)(record + 0xC);
        *(f32 *)(record + 0x464) = (f32)*(s32 *)(record + 0x10);
        sum = *(s32 *)(record + 0xC) + *(s32 *)(record + 0x14);
        *(f32 *)(record + 0x4A0) = (f32)sum;
        *(f32 *)(record + 0x4A4) = (f32)*(s32 *)(record + 0x10);
        *(f32 *)(record + 0x4E0) = (f32)*(s32 *)(record + 0xC);
        sum = *(s32 *)(record + 0x10) + *(s32 *)(record + 0x18);
        *(f32 *)(record + 0x4E4) = (f32)sum;
        sum = *(s32 *)(record + 0xC) + *(s32 *)(record + 0x14);
        *(f32 *)(record + 0x520) = (f32)sum;
        sum = *(s32 *)(record + 0x10) + *(s32 *)(record + 0x18);
        *(f32 *)(record + 0x524) = (f32)sum;
    }
}

/* MATCHED 2026-09-18.  The last 20 words were `addiu $aN, $gp, ...` emitted
   one slot before the `lw $a1, ...($gp)` that should precede it, at every
   func_004501f0 and func_00450340 call.  Both take a pointer for the format
   argument, not an s32: b210 evaluates a cast address ahead of the plain
   arguments, so `(s32)&iGpffffb0xx` pulled the `addiu` forward.  Declaring
   the parameter `const void *` and dropping the casts restores retail's
   order.  Same lever as func_00196040's out-parameters in code1_001c.c. */
// FUN_0046EC70
void sdkLboxDrawEntries(u8 *arg0) {
    extern char *strcpy(char *dst, const char *src);
    extern s32 strlen(const void *str);
    extern s32 func_0044dcd8(f32 value);
    extern void func_004501f0(s64 arg0, s32 arg1, const void *arg2, ...);
    extern s32 iGpffffb064;
    extern char iGpffffb068;
    extern char iGpffffb06c;
    extern char iGpffffb070;
    extern char iGpffffb078;
    extern char iGpffffb080;
    extern char iGpffffb088;
    extern char iGpffffb090;
    extern char iGpffffb098;
    extern char iGpffffb0a0;
    extern char iGpffffb0a4;
    extern char iGpffffb0a8;
    extern char iGpffffb0b0;
    u8 *ctx;
    u8 *node;
    s32 i;
    s32 w;
    char buf[0x108];
    f32 pos[2];
    ctx = *(u8 **)(arg0 + 0x38);
    node = *(u8 **)(ctx + 0x144);
    pos[0] = (f32)(*(s32 *)(ctx + 0x18) + 2);
    pos[1] = (f32)(*(s32 *)(ctx + 0x1C) + 2);
    for (i = 0; node != NULL; i++) {
        s32 first;
        first = *(s32 *)(ctx + 0x138);
        if (i < first) {
            node = *(u8 **)(node + 0x228);
            continue;
        }
        if (i > first + *(s32 *)(ctx + 0x13C) - 1) {
            return;
        }
        if (*(s32 *)(ctx + 0x154) != 0) {
            ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb068, node + 8);
            switch (*(s32 *)(node + 4)) {
            case 0:
                break;
            case 1: {
                sprintf(buf, &iGpffffb06c, node + 0x108);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(*(s32 *)(ctx + 0x28) + (w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf)));
                ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                break;
            }
            case 2: {
                strcpy(buf, &iGpffffb070);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(*(s32 *)(ctx + 0x28) + (w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf)));
                if (*(s32 *)(node + 0x208) == 1) {
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, &iGpffffb078);
                } else {
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, &iGpffffb080);
                }
                break;
            }
            case 3: {
                if (*(s32 *)(node + 0x218) == 0) {
                    sprintf(buf, &iGpffffb088, *(s32 *)(node + 0x208));
                    w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                    pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                } else {
                    sprintf(buf, &iGpffffb090, *(s32 *)(node + 0x208));
                    w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                    pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                    ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                }
                break;
            }
            case 4: {
                s32 v;
                v = func_0044dcd8(*(f32 *)(node + 0x20C));
                sprintf(buf, &iGpffffb098, v);
                w = *(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2;
                pos[0] = (f32)(w - ((s32 (*)(char *))*(void **)(ctx + 0x158))(buf));
                ((void (*)(f32 *, void *, void *))*(void **)(ctx + 0x154))(pos, &iGpffffb064, buf);
                break;
            }
            }
        } else {
            func_00450340(*(s64 *)pos, &iGpffffb0a0, node + 8);
            switch (*(s32 *)(node + 4)) {
            case 0:
                break;
            case 1: {
                s32 v;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * (strlen(node + 0x108) + 1));
                pos[0] = (f32)(u32)v;
                func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb0a4, node + 0x108);
                break;
            }
            case 2: {
                s32 v;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * (strlen(&iGpffffb0a8) + 1));
                pos[0] = (f32)(u32)v;
                if (*(s32 *)(node + 0x208) == 1) {
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb078);
                } else {
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb080);
                }
                break;
            }
            case 3: {
                if (*(s32 *)(node + 0x218) == 0) {
                    s32 v;
                    v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 9);
                    pos[0] = (f32)v;
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb088, *(s32 *)(node + 0x208));
                } else {
                    s32 v;
                    v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 11);
                    pos[0] = (f32)v;
                    func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb0b0, *(s32 *)(node + 0x208));
                }
                break;
            }
            case 4: {
                s32 v;
                s32 r;
                v = (*(s32 *)(ctx + 0x18) + *(s32 *)(ctx + 0x20) - 2) - (*(s32 *)(ctx + 0x28) * 8);
                pos[0] = (f32)v;
                r = func_0044dcd8(*(f32 *)(node + 0x20C));
                func_004501f0(*(s64 *)pos, iGpffffb064, &iGpffffb098, r);
                break;
            }
            }
        }
        pos[0] = (f32)(*(s32 *)(ctx + 0x18) + 2);
        pos[1] = pos[1] + (f32)*(s32 *)(ctx + 0x2C);
        node = *(u8 **)(node + 0x228);
    }
}

/* Process the debug list window, its live controller input and selection callback.
 * Native rectangle/color construction and scoped loop-invariant extraction
 * reproduce 3928 executable bytes plus the eight-byte retail zero tail. */
#pragma push
/* measured: sdkLboxUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0046F2B0
s32 sdkLboxUpdate(u8 *task)
{
    extern s32 func_00457120(void);
    extern u32 func_003e8120(u32 camera);
    extern u32 func_003e8110(u32 camera);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 sdkListStateHandleInput(u8 *task);
    extern s32 sdkListStateGetScroll(void *task);
    extern s32 sdkListStateGetCursor(void *task);
    extern s32 sdkWindowIsOpen(u8 *task);
    extern void sdkWindowSetRect(u8 *task, u8 *arg1);
    extern void sdkLboxDrawEntries(u8 *task);
    extern void sdkLboxSetOrigin(u8 *task, s32 arg1, s32 arg2);
    extern u8 *sdkLboxFindEntry(u8 *task, s32 arg1);
    extern s32 sdkLboxGetSelectedId(u8 *task);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern u16 D_008C024C[];
    extern u16 D_008C024E[];
    extern u16 D_008C0252[];
    extern u8 D_008C025C[];
    extern u8 D_008C025D[];
    extern f32 D_00761514;

    f32 joystick[3];
    struct { void *value; void *argument; } callbackArgument;
    s32 (*update)(s32);
    KWindowEntryCallback entryCallback;
    u8 *clearByte;
    f32 incrementedReal;
    f32 decrementedReal;
    f32 depth;
    f32 reciprocalDepth;
    f32 redFloat;
    f32 greenFloat;
    f32 blueFloat;
    f32 alphaFloat;
    f32 analogX;
    f32 analogY;
    s32 delay;
    void *actionArgument;
    s32 theme;
    void *textArgument;
    void *realArgument;
    s32 incremented;
    s32 decremented;
    s32 entryType;
    void *integerArgument;
    s32 incrementType;
    s32 decrementType;
    s32 vertexIndex;
    s32 modifier;
    u32 clearCount;
    s32 increment;
    s32 decrement;
    s32 state;
    u32 green;
    u32 red;
    u32 alpha;
    u32 blue;
    ControllerWork *work;
    ControllerEntry *incrementEntry;
    ControllerEntry *decrementEntry;
    ControllerEntry *selectedEntry;
    u8 *vertexBase;

    work = *(ControllerWork **)(task + 0x38);
    modifier = 0;
    state = work->state;
    switch (state) {
    case 0:
        if (work->enabled == 1) {
            work->state = state + 1;
        }
    default:
        goto update_callback;
    case 1:
        depth = *(f32 *)((u8 *)func_00457120() + 0x80);
        reciprocalDepth = 1.0f / depth;
        theme = work->theme;
        switch (theme) {
        case 0:
            work->window = controller_create_window(task,
                work->rectangle.x, work->rectangle.y,
                work->rectangle.width, work->rectangle.height,
                &D_00764134, &D_00764138);
            D_007641A8.red = 0U;
            D_007641A8.green = 0xE3U;
            D_007641A8.blue = 0U;
            D_007641A8.alpha = 0x40U;
            break;
        case 1:
            work->window = controller_create_window(task,
                work->rectangle.x, work->rectangle.y,
                work->rectangle.width, work->rectangle.height,
                &D_0076413C, &D_00764140);
            D_007641A8.red = 0x54U;
            D_007641A8.green = 0U;
            D_007641A8.blue = 0U;
            D_007641A8.alpha = 0x60U;
            break;
        case 2:
            work->window = controller_create_window(task,
                work->rectangle.x, work->rectangle.y,
                work->rectangle.width, work->rectangle.height,
                &D_00764144, &D_00764148);
            D_007641A8.red = 0xE3U;
            D_007641A8.green = 0x4AU;
            D_007641A8.blue = 0U;
            D_007641A8.alpha = 0x60U;
            break;
        case 3:
            work->window = controller_create_window(task,
                work->rectangle.x, work->rectangle.y,
                work->rectangle.width, work->rectangle.height,
                &D_0076414C, &D_00764150);
            D_007641A8.red = 0x80U;
            D_007641A8.green = 0x80U;
            D_007641A8.blue = 0x80U;
            D_007641A8.alpha = 0x60U;
            break;
        }
        vertexIndex = 0;
        red = D_007641A8.red;
        green = D_007641A8.green;
        blue = D_007641A8.blue;
        alpha = D_007641A8.alpha;
        /* SDK vertex stores stay relative to the controller root. This
         * preserves their order while each iteration advances one vertex. */
        for (; vertexIndex < 4; vertexIndex++) {
            vertexBase = (u8 *)work + (vertexIndex << 6);
            *(f32 *)(vertexBase + 0x30) = 0.0f;
            *(f32 *)(vertexBase + 0x34) = 0.0f;
            *(f32 *)(vertexBase + 0x38) = depth;
            *(f32 *)(vertexBase + 0x48) = reciprocalDepth;
            redFloat = (f32) red;
            *(f32 *)(vertexBase + 0x50) = redFloat;
            greenFloat = (f32) green;
            *(f32 *)(vertexBase + 0x54) = greenFloat;
            blueFloat = (f32) blue;
            *(f32 *)(vertexBase + 0x58) = blueFloat;
            alphaFloat = (f32) alpha;
            *(f32 *)(vertexBase + 0x5C) = alphaFloat;
        }
        work->state = work->state + 1;
        goto update_callback;
    case 2:
        if (sdkWindowIsOpen(work->window) != 1) {
            sdkWindowSetRect(work->window, (u8 *)&work->rectangle);
            work->state = work->state + 1;
        }
        goto update_callback;
    case 3:
        if (D_008C024C[0] & 8) {
            modifier = 1;
        } else if (D_008C024C[0] & 4) {
            modifier = 2;
        } else if (D_008C024C[0] & 2) {
            modifier = 3;
        } else if (D_008C024C[0] & 1) {
            modifier = 4;
        }
        if ((D_008C024C[0] & 2) && (D_008C024C[0] & 1)) {
            modifier = 5;
        }
        if ((work->enabled == 1) && (work->visible != 0)) {
            if (!(work->flags & 1)) {
                work->vertices[0].x = (f32) (work->rectangle.x + 2);
                work->vertices[0].y = (f32) (work->rectangle.y + 2 + (work->selectedRow * work->rowHeight));
                work->vertices[1].x = (f32) (work->rectangle.x - 2 + work->rectangle.width);
                work->vertices[1].y = (f32) (work->rectangle.y + 2 + (work->selectedRow * work->rowHeight));
                work->vertices[2].x = (f32) (work->rectangle.x + 2);
                {
                    s32 bottomOffset = (work->rowHeight * (work->selectedRow + 1)) + 2;
                    work->vertices[2].y = (f32)(bottomOffset + work->rectangle.y);
                }
                work->vertices[3].x = (f32) (work->rectangle.x - 2 + work->rectangle.width);
                {
                    s32 bottomOffset = (work->rowHeight * (work->selectedRow + 1)) + 2;
                    work->vertices[3].y = (f32)(bottomOffset + work->rectangle.y);
                }
                if (func_003e8120((u32)func_00457120()) != 0) {
                    WindowRenderStateSet *renderStates = &((WindowEngineStatePrefix *)ourGlobals)->device.setState;
                    renderStates[0]((RwRenderState)(0xE), (void *)(0));
                    renderStates[0]((RwRenderState)(0xC), (void *)(1));
                    renderStates[0]((RwRenderState)(7), (void *)(2));
                    renderStates[0]((RwRenderState)(0x14), (void *)(1));
                    renderStates[0]((RwRenderState)(6), (void *)(0));
                    renderStates[0]((RwRenderState)(8), (void *)(0));
                    renderStates[0]((RwRenderState)(1), (void *)(0));
                    RpSkyRenderStateSet(2, (void *)(0x44));
                    RpSkyRenderStateSet(3, (void *)(0x717FB));
                    D_00887310[0](4, work->vertices, 4);
                }
                func_003e8110((u32)func_00457120());
            }
            func_003e8120((u32)func_00457120());
            sdkLboxDrawEntries(task);
            func_003e8110((u32)func_00457120());
            if (work->flags & 4) {
                clearByte = (u8 *)&joystick;
                clearCount = 0xC;
                if (clearByte != NULL) {
                    do {
                        *clearByte = 0;
                        clearByte += 1;
                        clearCount -= 1U;
                    } while (clearCount != 0);
                }
                analogX = (f32)(u32) D_008C025C[0];
                joystick[0] = analogX - 128.0f;
                analogY = (f32)(u32) D_008C025D[0];
                joystick[2] = analogY - 128.0f;
                if (joystick[0] < -48.0f) {
                    work->rectangle.x = (s32) (work->rectangle.x - 0xA);
                } else if (!(joystick[0] <= 48.0f)) {
                    work->rectangle.x = (s32) (work->rectangle.x + 0xA);
                }
                if (joystick[2] < -48.0f) {
                    work->rectangle.y = (s32) (work->rectangle.y - 0xA);
                } else if (!(joystick[2] <= 48.0f)) {
                    work->rectangle.y = (s32) (work->rectangle.y + 0xA);
                }
                sdkLboxSetOrigin(task, work->rectangle.x, work->rectangle.y);
            }
            if (!(work->flags & 2)) {
                delay = work->delay;
                if (delay > 0) {
                    work->delay = (s32) (delay - 1);
                } else if (sdkListStateHandleInput(work->input) != 0) {
                    work->selectedValue = sdkListStateGetScroll(work->input);
                    work->selectedRow = sdkListStateGetCursor(work->input);
                } else if (D_008C0252[0] & 0x2000) {
                    incrementEntry = (ControllerEntry *)sdkLboxFindEntry(task, sdkLboxGetSelectedId(task));
                    if (incrementEntry != NULL) {
                        incrementType = incrementEntry->type;
                        switch (incrementType) {
                        case 0:
                        case 1:
                            break;
                        case 2:
                            incrementEntry->integerValue = (s32) (incrementEntry->integerValue != 1);
                            break;
                        case 3:
                            increment = 1;
                            if (modifier == 1) {
                                increment = 10;
                            }
                            else if (modifier == 2) {
                                increment = 100;
                            }
                            else if (modifier == 3) {
                                increment = 1000;
                            }
                            else if (modifier == 4) {
                                increment = 10000;
                            }
                            else if (modifier == 5) {
                                increment = 100000;
                            }
                            incremented = (s32)((u32)incrementEntry->integerValue + (u32)increment);
                            incrementEntry->integerValue = incremented;
                            if (incrementEntry->maximum < incremented) {
                                incrementEntry->integerValue = (s32) incrementEntry->minimum;
                            }
                            break;
                        case 4:
                            {
                                s32 realIncrement = 1;
                                if (modifier == 1) {
                                    realIncrement = 10;
                                }
                                else if (modifier == 2) {
                                    realIncrement = 100;
                                }
                                else if (modifier == 3) {
                                    realIncrement = 1000;
                                }
                                else if (modifier == 4) {
                                    realIncrement = 10000;
                                }
                                else if (modifier == 5) {
                                    realIncrement = 100000;
                                }
                                incrementedReal = incrementEntry->realValue + D_00761514 * (f32)realIncrement;
                                incrementEntry->realValue = incrementedReal;
                                if (!(incrementedReal <= (f32)incrementEntry->maximum)) {
                                    incrementEntry->realValue = (f32)incrementEntry->minimum;
                                }
                            }
                            break;
                        }
                    }
                } else if (D_008C0252[0] & 0x8000) {
                    decrementEntry = (ControllerEntry *)sdkLboxFindEntry(task, sdkLboxGetSelectedId(task));
                    if (decrementEntry != NULL) {
                        decrementType = decrementEntry->type;
                        switch (decrementType) {
                        case 0:
                        case 1:
                            break;
                        case 2:
                            decrementEntry->integerValue = (s32) (decrementEntry->integerValue != 1);
                            break;
                        case 3:
                            decrement = 1;
                            if (modifier == 1) {
                                decrement = 10;
                            }
                            else if (modifier == 2) {
                                decrement = 100;
                            }
                            else if (modifier == 3) {
                                decrement = 1000;
                            }
                            else if (modifier == 4) {
                                decrement = 10000;
                            }
                            else if (modifier == 5) {
                                decrement = 100000;
                            }
                            decremented = (s32)((u32)decrementEntry->integerValue - (u32)decrement);
                            decrementEntry->integerValue = decremented;
                            if (decremented < decrementEntry->minimum) {
                                decrementEntry->integerValue = (s32) decrementEntry->maximum;
                            }
                            break;
                        case 4:
                            {
                                s32 realDecrement = 1;
                                if (modifier == 1) {
                                    realDecrement = 10;
                                }
                                else if (modifier == 2) {
                                    realDecrement = 100;
                                }
                                else if (modifier == 3) {
                                    realDecrement = 1000;
                                }
                                else if (modifier == 4) {
                                    realDecrement = 10000;
                                }
                                else if (modifier == 5) {
                                    realDecrement = 100000;
                                }
                                decrementedReal = decrementEntry->realValue - D_00761514 * (f32)realDecrement;
                                decrementEntry->realValue = decrementedReal;
                                if (decrementedReal < (f32)decrementEntry->minimum) {
                                    decrementEntry->realValue = (f32)decrementEntry->maximum;
                                }
                            }
                            break;
                        }
                    }
                } else if (D_008C024E[0] & 0x40) {
                    selectedEntry = (ControllerEntry *)sdkLboxFindEntry(task, sdkLboxGetSelectedId(task));
                    if (selectedEntry != NULL) {
                        entryCallback = selectedEntry->callback;
                        if (entryCallback != NULL) {
                            entryType = selectedEntry->type;
                            switch (entryType) {
                            case 0:
                                actionArgument = selectedEntry->argument;
                                if (actionArgument != 0) {
                                    callbackArgument.value = NULL;
                                    callbackArgument.argument = actionArgument;
                                    entryCallback((void *)&callbackArgument);
                                } else {
                                    entryCallback((void *)NULL);
                                }
                                break;
                            case 1:
                                textArgument = selectedEntry->argument;
                                if (textArgument != 0) {
                                    callbackArgument.value = selectedEntry->text;
                                    callbackArgument.argument = textArgument;
                                    entryCallback((void *)&callbackArgument);
                                } else {
                                    entryCallback((void *)(selectedEntry->text));
                                }
                                break;
                            case 2:
                            case 3:
                                integerArgument = selectedEntry->argument;
                                if (integerArgument != 0) {
                                    callbackArgument.value = &selectedEntry->integerValue;
                                    callbackArgument.argument = integerArgument;
                                    selectedEntry->callback((void *)&callbackArgument);
                                } else {
                                    entryCallback((void *)(&selectedEntry->integerValue));
                                }
                                break;
                            case 4:
                                realArgument = selectedEntry->argument;
                                if (realArgument != 0) {
                                    callbackArgument.value = &selectedEntry->realValue;
                                    callbackArgument.argument = realArgument;
                                    entryCallback((void *)&callbackArgument);
                                } else {
                                    entryCallback((void *)(&selectedEntry->realValue));
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        goto update_callback;
    case 4:
        goto update_callback;
    case 5:
        return -1;
    }
update_callback:
    if (work->state > 2) {
        update = work->update;
        if (update != NULL) {
            update(work->updateArgument);
        }
    }
    return 0;
}

