
#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "kwln_task_internal.h"
#include "kwln_view_internal.h"
#include "rw_texture_internal.h"
#include "sdk_ot_state_api.h"

/* Unit settings: propagation, loop-invariant motion and common subexpressions enabled. */
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
extern void strcpy(void *dst, void *src);
extern void func_00440b68();
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffb9e8;
extern u8 D_005DD6A0[];
extern u8 D_005DD6C0[];
extern u8 D_005DD610[];
/* Each declaration starts at the named interior sub-object, not slot +0.
 * The containing display slots are separated by 0x370 bytes. */
typedef struct FclBankId { s16 id; } FclBankId;
typedef struct FclBankChannel { u8 intensity; } FclBankChannel;
typedef struct FclBankScale { u32 bits; } FclBankScale;
typedef struct FclBankEntryIndex { s32 entryIndex; } FclBankEntryIndex;
typedef struct FclBankStrip { s32 stripOffset; } FclBankStrip;
typedef struct FclBankTimer { s32 ticks; } FclBankTimer;
typedef struct FclBankActive { s32 active; } FclBankActive;
typedef struct FclBankPhase { s32 phase; } FclBankPhase;
typedef struct FclBankPhaseIndex { s32 phaseIndex; } FclBankPhaseIndex;
typedef struct FclBankDescriptorStrip { s32 stripOffset; u8 pad04[0xC]; } FclBankDescriptorStrip;
extern FclBankDescriptorStrip D_005DD61C[];
extern FclBankStrip D_00796A60[];
extern FclBankTimer D_00796A64[];
extern FclBankTimer D_00796A68[];
extern FclBankTimer D_00796A6C[];
extern FclBankId D_00796704[];
extern FclBankId D_00796706[];
extern FclBankId D_00796708[];
extern FclBankChannel D_0079671C[];
extern FclBankChannel D_0079671D[];
extern FclBankChannel D_0079671E[];
extern FclBankScale D_00796728[];
extern FclBankScale D_0079672C[];
extern FclBankEntryIndex D_0079674C[];
extern u8 iGpffff85d0;
extern u8 D_005DD600[];
extern u8 D_00796700[];
extern FclBankChannel D_0079671F[];
extern FclBankActive D_00796750[];
extern FclBankPhase D_00796754[];
extern FclBankTimer D_00796758[];
extern FclBankPhaseIndex D_0079675C[];
extern void timeLimitTaskCreate(s32 parent);
extern s32 timeLimitTaskExists(void);
extern void timeLimitTaskDestroy(void);
extern void PrimFreeBatchNode(s32 node);
extern void chkmemAllocSiteTag(void *file, s32 line);
extern void RpSkyRenderStateSet(s32, s32);
extern s32 fclBankTaskUpdate(u8 *task);
extern void fclBankTaskDestroy(u8 *task);
extern s32 kwlnGetCamera(void);
extern u8 D_005DD680[];
/* Prefix of RenderWare's RwGlobals/RwDevice so device fields like the near Z and render-state entry
 * points are addressed absolutely. */
typedef struct {
    f32 gammaCorrection;
    void *fpSystem;
    f32 zBufferNear;
    f32 zBufferFar;
    void *fpRenderStateSet;
    void *fpRenderStateGet;
    void *fpIm2DRenderLine;
    void *fpIm2DRenderTriangle;
    void *fpIm2DRenderPrimitive;
    void *fpIm2DRenderIndexedPrimitive;
} RwDeviceHead_0010;

typedef struct {
    void *curCamera;
    void *curWorld;
    u16 renderFrame;
    u16 lightFrame;
    u16 pad[2];
    RwDeviceHead_0010 dOpenDevice;
} RwGlobalsHead_0010;

extern u32 ourGlobals[];
#define RwIm2DGetNearScreenZ() \
    (((RwGlobalsHead_0010 *)ourGlobals)->dOpenDevice.zBufferNear)

typedef struct {
    f32 x;
    f32 y;
} Float2_0010;


/* Both draw buffers contain four 0x40-byte Im2D vertices. Integer stores
 * initialise IEEE-754 bit patterns, while per-frame updates use floats. */
typedef union FclBankVertexValue {
    s32 word;
    f32 value;
} FclBankVertexValue;
typedef struct FclBankVertex {
    FclBankVertexValue x, y, z;
    u8 pad0c[4];
    FclBankVertexValue u, v, reciprocalZ;
    u8 pad1c[4];
    FclBankVertexValue red, green, blue, alpha;
    u8 pad30[0x10];
} FclBankVertex;
typedef struct FclBankDrawWork {
    s32 state;
    u8 *nodes[2];
    u8 pad0c[4];
    FclBankVertex vertices[2][4];
} FclBankDrawWork;

/* Two resource/display records are stepped by 0x370 bytes in the bank table.
 * Vertex storage is two quads of four 0x40-byte Im2D vertices. */
typedef struct FclBankDisplay {
    s16 state;
    u8 pad02[2];
    s16 firstId, secondId, thirdId;
    u8 pad0a[2];
    Float2_0010 position;
    u8 *textures[2];
    u8 red, green, blue, alpha;
    f32 depth;
    union { u8 *bytes; struct HCdvd *cdvd; } archive;
    f32 scaleX, scaleY;
    u8 pad30[0x18];
    u8 *request;
    s32 entryIndex;
    s32 active, phase, ticks, phaseIndex;
    u8 path[0x100];
    FclBankVertex vertices[2][4];
    s32 stripOffset;
    s32 cleanupTicks, requestTicks, archiveTicks;
} FclBankDisplay;

typedef struct FclBankDescriptorEntry {
    s32 firstId, secondId, thirdId, stripOffset;
} FclBankDescriptorEntry;

/* PrimAllocBatchNode's list links, draw callback and Im2D payload. */
typedef struct PrimBatchNode {
    s32 next, previous;
    void *callback;
    u8 pad0c[4];
    s32 argument;
    u8 pad14[4];
    s16 kind;
    u8 pad1a[2];
    s32 primitive;
    u8 *vertices;
    s32 count;
} PrimBatchNode;

extern u8 D_00796460[];
extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern u8 iGpffff85d0;
#pragma push
#pragma tailcall off
// Start the time limit task under the root with no parent.
// FUN_00103510
void timeLimitStart(void) {
    timeLimitTaskCreate(0);
}
#pragma pop

#pragma push
#pragma tailcall off
// Report whether the time limit task is running.
// FUN_00103540
s32 timeLimitIsActive(void) {
    return timeLimitTaskExists() != 0;
}
#pragma pop

#pragma push
#pragma tailcall off
// Stop the time limit task and its hierarchy.
// FUN_00103570
void timeLimitStop(void) {
    timeLimitTaskDestroy();
}
#pragma pop

#pragma push
#pragma tailcall off
// FUN_00103590
void fclBankNoop(void) {}
#pragma pop

#pragma push
#pragma tailcall off
// Apply the base render states for a bank slot's sky layer.
// FUN_001035A0
void fclBankRenderStateBase(void) {
    D_00887300[0](1, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
}
#pragma pop

#pragma push
#pragma tailcall off
// Apply the full render states for a bank slot's sky layer, including the interpolation mode.
// FUN_00103600
void fclBankRenderStateFull(void)
{
    u8 *fnTable;

    fnTable = (u8 *)D_00887300;
    (*(void (**)(s32, s32))fnTable)(6, 1);
    (*(void (**)(s32, s32))fnTable)(8, 1);
    (*(void (**)(s32, s32))fnTable)(9, 1);
    (*(void (**)(s32, s32))fnTable)(0xC, 1);
    (*(void (**)(s32, s32))fnTable)(7, 2);
    (*(void (**)(s32, s32))fnTable)(1, iGpffffb9e8);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
}
#pragma pop

#pragma push
#pragma tailcall off
// Bank task update: runs the state machine for the slot's current state. Primitive-node and camera
// byte-pointer APIs keep their ABI offsets because no complete shared layout exists.
// FUN_001036D0
s32 fclBankTaskUpdate(u8 *task) {
    FclBankDrawWork *stateFields;
    extern u8 *PrimAllocBatchNode(void);
    extern void PrimAppendNode(void *list, void *node);
    extern u8 D_005DD5D0[];
    extern u8 D_00793E80[];
    extern s64 iGpffff85c8;
    s32 index;
    u8 *state;
    u8 *slot;

    state = ((struct KwlnTask *)task)->work;
    stateFields = (FclBankDrawWork *)state;
    switch (((FclBankDrawWork *)state)->state) {
    case 0:
        {
            f32 scale;
            f32 inverse;
            s32 forty;
            s32 one;

            scale = ((KwlnView *)(u8 *)(u32)kwlnGetCamera())->unk80;
            inverse = 1.0f / scale;
            forty = 0x42800000;
            ((FclBankDrawWork *)state)->vertices[0][0].x.word = forty;
            ((FclBankDrawWork *)state)->vertices[0][0].y.word = forty;
            ((FclBankDrawWork *)state)->vertices[0][0].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[0][1].x.word = 0x43000000;
            ((FclBankDrawWork *)state)->vertices[0][1].y.word = forty;
            ((FclBankDrawWork *)state)->vertices[0][1].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[0][2].x.word = forty;
            ((FclBankDrawWork *)state)->vertices[0][2].y.word = 0x43400000;
            ((FclBankDrawWork *)state)->vertices[0][2].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[0][3].x.word = 0x43000000;
            ((FclBankDrawWork *)state)->vertices[0][3].y.word = 0x43400000;
            ((FclBankDrawWork *)state)->vertices[0][3].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[0][0].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[0][1].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[0][2].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[0][3].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[1][0].x.word = 0x43010000;
            ((FclBankDrawWork *)state)->vertices[1][0].y.word = 0x43010000;
            ((FclBankDrawWork *)state)->vertices[1][0].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[1][1].x.value = (f32)385;
            ((FclBankDrawWork *)state)->vertices[1][1].y.word = 0x43010000;
            ((FclBankDrawWork *)state)->vertices[1][1].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[1][2].x.word = 0x43010000;
            ((FclBankDrawWork *)state)->vertices[1][2].y.value = (f32)385;
            ((FclBankDrawWork *)state)->vertices[1][2].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[1][3].x.value = (f32)385;
            ((FclBankDrawWork *)state)->vertices[1][3].y.value = (f32)385;
            ((FclBankDrawWork *)state)->vertices[1][3].z.value = scale;
            ((FclBankDrawWork *)state)->vertices[1][0].u.word = 0;
            ((FclBankDrawWork *)state)->vertices[1][0].v.word = 0;
            one = 0x3F800000;
            ((FclBankDrawWork *)state)->vertices[1][1].u.word = one;
            ((FclBankDrawWork *)state)->vertices[1][1].v.word = 0;
            ((FclBankDrawWork *)state)->vertices[1][2].u.word = 0;
            ((FclBankDrawWork *)state)->vertices[1][2].v.word = one;
            ((FclBankDrawWork *)state)->vertices[1][3].u.word = one;
            ((FclBankDrawWork *)state)->vertices[1][3].v.word = one;
            ((FclBankDrawWork *)state)->vertices[1][0].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[1][1].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[1][2].reciprocalZ.value = inverse;
            ((FclBankDrawWork *)state)->vertices[1][3].reciprocalZ.value = inverse;

            {
                s32 max = 0x437F0000;
                s32 i;
                i = 0;
                goto loop1_check;
loop1_body:
                ((FclBankDrawWork *)state)->vertices[0][i].red.word = max;
                ((FclBankDrawWork *)state)->vertices[0][i].green.word = 0;
                ((FclBankDrawWork *)state)->vertices[0][i].blue.word = forty;
                ((FclBankDrawWork *)state)->vertices[0][i].alpha.word = max;
                i++;
loop1_check:
                if (i < 4) goto loop1_body;
            }
            {
                s32 max = 0x437F0000;
                s32 i;
                i = 0;
                goto loop2_check;
loop2_body:
                ((FclBankDrawWork *)state)->vertices[1][i].red.word = max;
                ((FclBankDrawWork *)state)->vertices[1][i].green.word = max;
                ((FclBankDrawWork *)state)->vertices[1][i].blue.word = max;
                ((FclBankDrawWork *)state)->vertices[1][i].alpha.word = max;
                i++;
loop2_check:
                if (i < 4) goto loop2_body;
            }
            index = 0;
            while (index < 2) {
                slot = state + (index << 2) + 4;
                *(u8 **)slot = PrimAllocBatchNode();
                ((PrimBatchNode *)*(u8 **)slot)->kind = 11;
                ((PrimBatchNode *)*(u8 **)slot)->primitive = 4;
                ((PrimBatchNode *)*(u8 **)slot)->vertices =
                    state + (index << 8) + 0x10;
                ((PrimBatchNode *)*(u8 **)slot)->count = 4;
                index++;
            }
            ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[0])->callback = (void *)fclBankRenderStateBase;
            ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[0])->argument = 0;
            ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[1])->callback = (void *)fclBankRenderStateFull;
            ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[1])->argument = 0;
            ((FclBankDrawWork *)state)->state = ((FclBankDrawWork *)state)->state + 1;
            break;
        }
    case 1:
        sdkDbprtQueueText(iGpffff85c8, (const char *)D_005DD5D0);
        ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[0])->next = 0;
        ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[0])->previous = 0;
        ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[1])->next = 0;
        ((PrimBatchNode *)((FclBankDrawWork *)state)->nodes[1])->previous = 0;
        PrimAppendNode(D_00793E80, ((FclBankDrawWork *)state)->nodes[0]);
        PrimAppendNode(D_00793E80, stateFields->nodes[1]);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma tailcall off
// Bank task destroy: frees the slot's two batch nodes and releases the task's work memory.
// FUN_00103980
void fclBankTaskDestroy(u8 *task) {
    u8 *state;

    state = ((struct KwlnTask *)task)->work;
    PrimFreeBatchNode((s32)((FclBankDrawWork *)state)->nodes[0]);
    PrimFreeBatchNode((s32)((FclBankDrawWork *)state)->nodes[1]);
    jtbl_008873EC[0](MEMBER(u8 *, task, struct KwlnTask, work));
}
#pragma pop

#pragma push
#pragma tailcall off
// Create the bank task with its update and destroy callbacks.
// FUN_001039E0
void fclBankTaskCreate(void) {
    chkmemAllocSiteTag(D_005DD600, 0xBD);
    (s32)kwlnTaskCreate((const void *)(&iGpffff85d0), 0xF, 0, 0, fclBankTaskUpdate, fclBankTaskDestroy, (u8 *)(D_008873F4[0](1, 0x210, 0x40000)));
}
#pragma pop

#pragma push
#pragma tailcall off
// Reset the bank slot table's per-slot flags and counters. The interior table aliases and their
// byte stride stay as they are because rebasing them changes relocation targets.
// FUN_00103A60
void fclBankTableReset(void)
{
    s16 i;
    s16 j;

    for (i = 0; i < 2; ++i) {
        ((FclBankDisplay *)D_00796700)[i].state = 0;
        ((FclBankDisplay *)D_00796700)[i].active = 0;
        for (j = 0; j < 2; ++j) {
            ((FclBankDisplay *)D_00796700)[i].textures[j] = NULL;
        }
    }
}
#pragma pop

#pragma push
#pragma tailcall off
// Register the bank resource tables and load each of the two bank slots.
// FUN_00103B00
void fclBankTableInit(void) {
    extern u8 D_00796460[];
    extern u8 D_00796700[];
    extern void fclBankSlotLoad(u8 *slot);
    s16 index;

    PrimQueueStateSet(D_00796460, 6, 1);
    PrimQueueStateSet(D_00796460, 7, 2);
    PrimQueueStateSet(D_00796460, 8, 1);
    PrimQueueStateSet(D_00796460, 11, 6);
    PrimQueueStateSet(D_00796460, 10, 5);
    PrimQueueStateSet(D_00796460, 9, 1);
    PrimQueueStateSet(D_00796460, 12, 1);
    PrimQueueStateSet(D_00796460, 2, 4);

    index = 0;
    while (index < 2) {
        fclBankSlotLoad(D_00796700 + (index * 0x370));
        index++;
    }
}
#pragma pop

struct HCdvd;

struct RwTexture;

#pragma push
#pragma tailcall off
// Load a bank slot's resources from its archive entries and register them. The slot is a raw
// 0x370-byte layout: state, textures, archive, request.
// FUN_00103C40
void fclBankSlotLoad(u8 *slot)
{
    FclBankDisplay *slotFields = (FclBankDisplay *)slot;
    extern u8 D_005DD630[];
    extern u8 D_005DD640[];
    extern u8 D_005DD670[];
    extern u32 H_Cdvd_IsFileLoaded(struct HCdvd *cdvd);
    extern const char *H_Cdvd_ArchiveEntryName(struct HCdvd *cdvd, s32 entryIndex);
    extern u8 *filerEnqueueRequest(s32 kind, const char *name, const char *path,
                            s32 flags, s32 source, s32 buffer, s32 byteCount,
                            const char *cacheName, s32 resultKind, s32 memoryKind);
    extern u8 *filerTakeCompletedRequest(u8 *request, s32 *completed, s32 *resultValue);
    extern s32 sdkWrapStreamCloseCreate(s32 stream, u8 *directory);
    extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
    extern u32 H_Cdvd_Destroy(struct HCdvd *cdvd);
    extern s32 func_003ef3a0(struct RwTexture *texture);
    extern void fclBankSlotUpdate(u8 *display);
    extern s32 sprintf(u8 *destination, const u8 *format, ...);
    s32 complete;
    s16 state;
    u8 *texture;
    s32 index;
    u8 *textureSlot;
    u8 *archive;
    u8 *request;
    s32 offset;

    state = ((FclBankDisplay *)slot)->state;
    switch (state) {
    case 1:
        ((FclBankDisplay *)slot)->archiveTicks = ((FclBankDisplay *)slot)->archiveTicks + 1;
        if (H_Cdvd_IsFileLoaded(((FclBankDisplay *)slot)->archive.cdvd) == 0) {
            break;
        }
        if (H_Cdvd_ArchiveEntryName(slotFields->archive.cdvd,
                          ((FclBankDisplay *)slot)->entryIndex) != NULL) {
            sprintf(slot + 0x60, D_005DD630,
                           H_Cdvd_ArchiveEntryName(MEMBER(struct HCdvd *, slot, FclBankDisplay, archive.bytes),
                                          MEMBER(s32, slot, FclBankDisplay, entryIndex)));
            ((FclBankDisplay *)slot)->request =
                filerEnqueueRequest(0, (const char *)slot + 0x60, NULL,
                              0, 0, 0, 0, NULL, 0, 0);
            ((FclBankDisplay *)slot)->state = 2;
            break;
        }
        H_Cdvd_Destroy(MEMBER(struct HCdvd *, slot, FclBankDisplay, archive.bytes));
        MEMBER(u8 *, slot, FclBankDisplay, archive.bytes) = NULL;
        ((FclBankDisplay *)slot)->state = 3;
        func_00440b68(D_005DD640, ((FclBankDisplay *)slot)->firstId,
                      ((FclBankDisplay *)slot)->secondId, ((FclBankDisplay *)slot)->thirdId,
                      ((FclBankDisplay *)slot)->cleanupTicks, ((FclBankDisplay *)slot)->requestTicks,
                      MEMBER(s32, slot, FclBankDisplay, archiveTicks));
        break;
    case 2:
        ((FclBankDisplay *)slot)->requestTicks = ((FclBankDisplay *)slot)->requestTicks + 1;
        texture = filerTakeCompletedRequest(((FclBankDisplay *)slot)->request, &complete, NULL);
        offset = ((FclBankDisplay *)slot)->entryIndex * 4;
        MEMBER(u8 *, offset + (u32)slot, FclBankDisplay, textures[0]) = texture;
        if (complete != 0) {
            offset = MEMBER(s32, slot, FclBankDisplay, entryIndex) * 4;
            texture = MEMBER(u8 *, offset + (u32)slot, FclBankDisplay, textures[0]);
            ((RwTexture *)texture)->filterAddressing =
                (((RwTexture *)texture)->filterAddressing & 0xFFFF00FF) | 0x3300;
            MEMBER(u8 *, slot, FclBankDisplay, request) = NULL;
            MEMBER(s32, slot, FclBankDisplay, entryIndex) = MEMBER(s32, slot, FclBankDisplay, entryIndex) + 1;
            ((FclBankDisplay *)slot)->state = 1;
            break;
        }
        break;
    case 4:
        fclBankSlotUpdate(slot);
        break;
    case 5:
    case 6:
        ((FclBankDisplay *)slot)->cleanupTicks = ((FclBankDisplay *)slot)->cleanupTicks + 1;
        request = ((FclBankDisplay *)slot)->request;
        if (request != NULL) {
            sdkWrapStreamCloseCreate((s32)request, MEMBER(u8 *, slot, FclBankDisplay, archive.bytes));
            MEMBER(u8 *, slot, FclBankDisplay, request) = NULL;
            MEMBER(u8 *, slot, FclBankDisplay, archive.bytes) = NULL;
        } else {
            archive = ((FclBankDisplay *)slot)->archive.bytes;
            if (archive != NULL) {
                H_Cdvd_Destroy((struct HCdvd *)archive);
                MEMBER(u8 *, slot, FclBankDisplay, archive.bytes) = NULL;
            }
        }
        index = 0;
        while (index < 2) {
            textureSlot = slot + (index * 4) + 0x14;
            if (*(struct RwTexture **)textureSlot != NULL) {
                func_003ef3a0(*(struct RwTexture **)textureSlot);
                *(u8 **)textureSlot = NULL;
            }
            index++;
        }
        if (((FclBankDisplay *)slot)->state != 6) {
            ((FclBankDisplay *)slot)->state = 0;
        } else {
            func_00440b68((u8 *)&iGpffff85d0 + 8, D_005DD670, 0xC5);
            ((FclBankDisplay *)slot)->archive.bytes = H_Cdvd_AcquireDirectory(slot + 0x60, 1);
            ((FclBankDisplay *)slot)->state = 1;
        }
        break;
    case 0:
    default:
        break;
    }
}
#pragma pop

#pragma push
#pragma tailcall off
// Advances a bank slot's loading and display state each step. Camera, vertex (0x40-byte vertices at
// 0x160/0x260) and display fields use byte offsets because typed access changed codegen.
// FUN_00103F00
void fclBankSlotUpdate(u8 *display)
{
    FclBankDisplay *displayFields = (FclBankDisplay *)display;
    s32 table[6];
    f32 pos[2];
    f32 depth;
    f32 inverse;
    f32 halfWidth;
    f32 halfHeight;
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
    f32 x0;
    f32 y0;
    f32 fx;
    f32 fy;
    f32 offset;
    u32 r;
    u32 g;
    u32 b;
    u32 a;
    s32 *src;
    s32 *dst;
    s32 lo;
    s32 hi;
    s32 n;
    s32 count;
    s32 index;

    kwlnGetCamera();
    a = display[0x1F];
    if (a != 0) {
        depth = ((FclBankDisplay *)display)->depth;
        b = display[0x1E];
        g = display[0x1D];
        r = display[0x1C];
        inverse = 1.0f / ((KwlnView *)(u8 *)(u32)kwlnGetCamera())->unk80;
        {
            s32 i;
            u8 *quad;

            for (i = 0; i < 4; i++) {
                quad = display + (i << 6);
                ((FclBankVertex *)(quad + 0x160))->red.value = (f32)r;
                ((FclBankVertex *)(quad + 0x160))->green.value = (f32)g;
                ((FclBankVertex *)(quad + 0x160))->blue.value = (f32)b;
                ((FclBankVertex *)(quad + 0x160))->alpha.value = (f32)a;
                ((FclBankVertex *)(quad + 0x160))->z.value = RwIm2DGetNearScreenZ() - depth;
                ((FclBankVertex *)(quad + 0x160))->reciprocalZ.value = inverse;
            }
        }
        *(Float2_0010 *)pos = ((FclBankDisplay *)display)->position;
        halfWidth = (512.0f * ((FclBankDisplay *)display)->scaleX) / 2.0f;
        halfHeight = (256.0f * ((FclBankDisplay *)display)->scaleY) / 2.0f;
        fx = pos[0];
        x0 = 256.0f + fx;
        left = x0 - halfWidth;
        ((FclBankDisplay *)display)->vertices[0][0].x.value = left;
        fy = pos[1];
        y0 = 128.0f + fy;
        top = y0 - halfHeight;
        ((FclBankDisplay *)display)->vertices[0][0].y.value = top;
        right = (x0 + halfWidth) - 1.0f;
        ((FclBankDisplay *)display)->vertices[0][1].x.value = right;
        ((FclBankDisplay *)display)->vertices[0][1].y.value = top;
        ((FclBankDisplay *)display)->vertices[0][2].x.value = left;
        bottom = (y0 + halfHeight) - 1.0f;
        ((FclBankDisplay *)display)->vertices[0][2].y.value = bottom;
        ((FclBankDisplay *)display)->vertices[0][3].x.value = right;
        ((FclBankDisplay *)display)->vertices[0][3].y.value = bottom;
        kwlnGetCamera();
        ((FclBankDisplay *)display)->vertices[0][0].u.word = 0;
        ((FclBankDisplay *)display)->vertices[0][0].v.word = 0;
        ((FclBankDisplay *)display)->vertices[0][1].u.word = 0x3F800000;
        ((FclBankDisplay *)display)->vertices[0][1].v.word = 0;
        ((FclBankDisplay *)display)->vertices[0][2].u.word = 0;
        ((FclBankDisplay *)display)->vertices[0][2].v.word = 0x3F800000;
        ((FclBankDisplay *)display)->vertices[0][3].u.word = 0x3F800000;
        ((FclBankDisplay *)display)->vertices[0][3].v.word = 0x3F800000;
        PrimQueueStateSet(D_00796460, 1, MEMBER(s32, ((FclBankDisplay *)display)->textures[0], RwTexture, raster));
        PrimQueueDrawPrimitive(D_00796460, 4, display + 0x160, 4);
        if (((FclBankDisplay *)display)->entryIndex >= 2) {
            a = display[0x1F];
            if (a == 0xFF && ((FclBankDisplay *)display)->active != 0) {
                if (displayFields->phase != 0) {
                    depth = MEMBER(f32, display, FclBankDisplay, depth);
                    b = display[0x1E];
                    g = display[0x1D];
                    r = display[0x1C];
                    inverse = 1.0f / ((KwlnView *)(u8 *)(u32)kwlnGetCamera())->unk80;
                    {
                        s32 i;
                        u8 *quad;

                        for (i = 0; i < 4; i++) {
                            quad = display + (i << 6);
                            ((FclBankVertex *)(quad + 0x260))->red.value = (f32)r;
                            ((FclBankVertex *)(quad + 0x260))->green.value = (f32)g;
                            ((FclBankVertex *)(quad + 0x260))->blue.value = (f32)b;
                            ((FclBankVertex *)(quad + 0x260))->alpha.value = (f32)a;
                            ((FclBankVertex *)(quad + 0x260))->z.value = RwIm2DGetNearScreenZ() - depth;
                            ((FclBankVertex *)(quad + 0x260))->reciprocalZ.value = inverse;
                        }
                    }
                    offset = (f32)((FclBankDisplay *)display)->stripOffset;
                    halfWidth = (512.0f * MEMBER(f32, display, FclBankDisplay, scaleX)) / 2.0f;
                    halfHeight = (64.0f * MEMBER(f32, display, FclBankDisplay, scaleY)) / 2.0f;
                    fx = pos[0];
                    x0 = 256.0f + fx;
                    left = x0 - halfWidth;
                    ((FclBankDisplay *)display)->vertices[1][0].x.value = left;
                    fy = pos[1];
                    y0 = 32.0f + fy;
                    top = offset + (y0 - halfHeight);
                    ((FclBankDisplay *)display)->vertices[1][0].y.value = top;
                    right = (x0 + halfWidth) - 1.0f;
                    ((FclBankDisplay *)display)->vertices[1][1].x.value = right;
                    ((FclBankDisplay *)display)->vertices[1][1].y.value = top;
                    ((FclBankDisplay *)display)->vertices[1][2].x.value = left;
                    bottom = (offset + (y0 + halfHeight)) - 1.0f;
                    ((FclBankDisplay *)display)->vertices[1][2].y.value = bottom;
                    ((FclBankDisplay *)display)->vertices[1][3].x.value = right;
                    ((FclBankDisplay *)display)->vertices[1][3].y.value = bottom;
                    kwlnGetCamera();
                    ((FclBankDisplay *)display)->vertices[1][0].u.word = 0;
                    ((FclBankDisplay *)display)->vertices[1][0].v.word = 0;
                    ((FclBankDisplay *)display)->vertices[1][1].u.word = 0x3F800000;
                    ((FclBankDisplay *)display)->vertices[1][1].v.word = 0;
                    ((FclBankDisplay *)display)->vertices[1][2].u.word = 0;
                    ((FclBankDisplay *)display)->vertices[1][2].v.word = 0x3F800000;
                    ((FclBankDisplay *)display)->vertices[1][3].u.word = 0x3F800000;
                    ((FclBankDisplay *)display)->vertices[1][3].v.word = 0x3F800000;
                    PrimQueueStateSet(D_00796460, 1, MEMBER(s32, ((FclBankDisplay *)display)->textures[1], RwTexture, raster));
                    PrimQueueDrawPrimitive(D_00796460, 4, display + 0x260, 4);
                }
                src = (s32 *)D_005DD680;
                dst = table;
                n = 3;
                do {
                    lo = src[0];
                    hi = src[1];
                    src += 2;
                    n--;
                    dst[0] = lo;
                    dst[1] = hi;
                    dst += 2;
                } while (n > 0);
                count = ((FclBankDisplay *)display)->ticks - 1;
                ((FclBankDisplay *)display)->ticks = count;
                if (count <= 0) {
                    if (MEMBER(s32, display, FclBankDisplay, phase) != 0) {
                        ((FclBankDisplay *)display)->phase = 0;
                    } else {
                        ((FclBankDisplay *)display)->phase = 1;
                    }
                    index = ((FclBankDisplay *)display)->phaseIndex + 1;
                    ((FclBankDisplay *)display)->phaseIndex = index;
                    index = index % 6;
                    ((FclBankDisplay *)display)->phaseIndex = index;
                    MEMBER(s32, display, FclBankDisplay, ticks) = table[index];
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma tailcall off
// Marks a bank slot as finished (state 5); the state table is an interior linker alias with a
// 0x370-byte display stride.
// FUN_001044D0
void fclBankMarkDone(s64 bank) {
    ((FclBankDisplay *)D_00796700)[(s16)bank].state = 5;
}
#pragma pop

#pragma push
#pragma tailcall off
// Configures a bank slot from a three-id descriptor by looking up its table entry, defaulting to
// 0x3E when not found.
// FUN_00104510
void fclBankSlotConfigure(s16 bank, s16 firstId, s16 secondId, s16 thirdId)
{
    u8 buf[0x100];
    s32 offset;
    s32 i;
    s32 found;
    u8 *entry;

    func_00440b68(D_005DD6A0, bank);
    offset = (bank * 0x38 - bank) * 0x10;
    ((FclBankDisplay *)(D_00796700 + offset))->state = 5;
    ((FclBankEntryIndex *)((u8 *)D_0079674C + offset))->entryIndex = 0;
    ((FclBankId *)((u8 *)D_00796704 + offset))->id = firstId;
    ((FclBankId *)((u8 *)D_00796706 + offset))->id = secondId;
    ((FclBankId *)((u8 *)D_00796708 + offset))->id = thirdId;
    sprintf(buf, D_005DD6C0,
                  (s32)firstId, (s32)secondId, (s32)thirdId);
    strcpy(D_00796700 + offset + 0x60, buf);
    ((FclBankDisplay *)(D_00796700 + offset))->state = 6;
    ((FclBankTimer *)((u8 *)D_00796A64 + offset))->ticks = 0;
    ((FclBankTimer *)((u8 *)D_00796A68 + offset))->ticks = 0;
    ((FclBankTimer *)((u8 *)D_00796A6C + offset))->ticks = 0;
    ((FclBankChannel *)((u8 *)D_0079671C + offset))->intensity = 0xff;
    ((FclBankChannel *)((u8 *)D_0079671E + offset))->intensity = 0xff;
    ((FclBankChannel *)((u8 *)D_0079671D + offset))->intensity = 0xff;
    ((FclBankChannel *)((u8 *)D_0079671F + offset))->intensity = 0xff;
    ((FclBankScale *)((u8 *)D_00796728 + offset))->bits = 0x3f800000;
    ((FclBankScale *)((u8 *)D_0079672C + offset))->bits = 0x3f800000;
    i = 0;
    found = 1;
    do {
        entry = D_005DD610 + i * 0x10;
        if (*(s32 *)entry == -1)
            break;
        if ((s32)firstId == *(s32 *)entry &&
            (s32)secondId == ((FclBankDescriptorEntry *)entry)->secondId &&
            (s32)thirdId == ((FclBankDescriptorEntry *)entry)->thirdId) {
            ((FclBankStrip *)((u8 *)D_00796A60 + offset))->stripOffset =
                D_005DD61C[i].stripOffset;
            found = 0;
            break;
        }
        i++;
    } while (1);
    if (found)
        ((FclBankStrip *)((u8 *)D_00796A60 + offset))->stripOffset = 0x3e;
}
#pragma pop

#pragma push
#pragma tailcall off
// Set the alpha byte of a bank slot; alpha is a byte field reached through its own linked interior
// alias.
// FUN_00104770
void fclBankSetAlpha(s64 bank, u8 alpha) {
    ((FclBankChannel *)((u8 *)D_0079671F + (((s16)bank) * 0x370)))->intensity = alpha;
}
#pragma pop

#pragma push
#pragma tailcall off
// Set a bank slot's active flag; when set, reset its phase and timers. State sub-objects keep their
// original alias-relative display-slot stride.
// FUN_001047B0
void fclBankSetActive(s64 bank, s32 active) {
    s32 offset;

    offset = (s16)bank * 0x370;
    ((FclBankActive *)((u8 *)D_00796750 + offset))->active = active;
    if (active != 0) {
        ((FclBankPhase *)((u8 *)D_00796754 + offset))->phase = 1;
        ((FclBankPhaseIndex *)((u8 *)D_0079675C + offset))->phaseIndex = 0;
        ((FclBankTimer *)((u8 *)D_00796758 + offset))->ticks = 2;
    }
}
#pragma pop

#pragma push
#pragma tailcall off
// Resume a waiting bank slot (state 3 to 4).
// FUN_00104830
void fclBankResume(s64 bank) {
    s16 *entry;

    entry = (s16 *)(D_00796700 + ((s16)bank * 0x370));
    if (*entry == 3) {
        *entry = 4;
    }
}
#pragma pop

#pragma push
#pragma tailcall off
// Return a pointer to the bank slot's position fields.
// FUN_00104880
u8 *fclBankGetPositionPtr(s64 bank) {
    return D_00796700 + ((s16)bank * 0x370) + 0xC;
}
#pragma pop

#pragma push
#pragma tailcall off
// Reports whether a bank slot is waiting (state 3); the state table is an interior linker alias
// indexed by display entry.
// FUN_001048C0
s32 fclBankIsWaiting(s64 bank) {
    return ((FclBankDisplay *)D_00796700)[(s16)bank].state == 3;
}
#pragma pop
