/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/battle.c; members 00103510-001048c0 */

#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "sdk_ot_state_api.h"
extern void strcpy(void *dst, void *src);
extern void func_00440b68();
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern s32 iGpffffb9e8;
extern u8 D_005DD6A0[];
extern u8 D_005DD6C0[];
extern u8 D_005DD610[];
extern u8 D_005DD61C[];
extern u8 D_00796A60[];
extern u8 D_00796A64[];
extern u8 D_00796A68[];
extern u8 D_00796A6C[];
extern u8 D_00796704[];
extern u8 D_00796706[];
extern u8 D_00796708[];
extern u8 D_0079671C[];
extern u8 D_0079671D[];
extern u8 D_0079671E[];
extern u8 D_00796728[];
extern u8 D_0079672C[];
extern u8 D_0079674C[];
extern u8 iGpffff85d0;
extern u8 D_005DD600[];
extern u8 D_00796700[];
extern u8 D_0079671F[];
extern u8 D_00796750[];
extern u8 D_00796754[];
extern u8 D_00796758[];
extern u8 D_0079675C[];
extern void timeLimitTaskCreate(s32 arg0);
extern s32 timeLimitTaskExists(void);
extern void timeLimitTaskDestroy(void);
extern void PrimFreeBatchNode(s32 arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern s32 fclBankTaskUpdate(u8 *arg0);
extern void fclBankTaskDestroy(u8 *arg0);
extern s32 kwlnGetCamera(void);
extern u8 D_005DD680[];
/* RenderWare keeps its engine instance in the `ourGlobals` array
   (retail 0x008872E0) and reaches device state through
   RWSRCGLOBAL(dOpenDevice): the near Z is at +0x18, the render-state and
   Im2D entry points from +0x20.  The prefix of RwGlobals/RwDevice from
   rwplcore.h is what makes a member access address it absolutely with the
   %lo folded into the load, which is retail's loop shape. */
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

extern u8 D_00796460[];
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern u8 iGpffff85d0;
#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Start the time limit task under the root with no parent [inferred]
// FUN_00103510
void timeLimitStart(void) {
    timeLimitTaskCreate(0);
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Report whether the time limit task is running [inferred]
// FUN_00103540
s32 timeLimitIsActive(void) {
    return timeLimitTaskExists() != 0;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Stop the time limit task and its hierarchy [inferred]
// FUN_00103570
void timeLimitStop(void) {
    timeLimitTaskDestroy();
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// FUN_00103590
void fclBankNoop(void) {}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Apply the base render states for a bank slot's sky layer [inferred]
// FUN_001035A0
void fclBankRenderStateBase(void) {
    D_00887300[0](1, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x717FB);
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Apply the full render states for a bank slot's sky layer, including the interpolation mode [inferred]
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
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Bank task update: run the state machine for the slot's current state [inferred]
/* Primitive-node and camera byte-pointer APIs have no shared complete layout here; retain their ABI offsets. */
// FUN_001036D0
s32 fclBankTaskUpdate(u8 *task) {
    extern u8 *PrimAllocBatchNode(void);
    extern void PrimAppendNode(void *list, void *node);
    extern u8 D_005DD5D0[];
    extern u8 D_00793E80[];
    extern s64 iGpffff85c8;
    s32 index;
    u8 *state;
    u8 *slot;

    state = ((struct KwlnTask *)task)->work;
    switch (((FclBankDrawWork *)state)->state) {
    case 0:
        {
            f32 scale;
            f32 inverse;
            s32 forty;
            s32 one;

            scale = *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
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
                *(s16 *)(*(u8 **)slot + 0x18) = 11;
                *(s32 *)(*(u8 **)slot + 0x1C) = 4;
                *(u8 **)(*(u8 **)slot + 0x20) =
                    state + (index << 8) + 0x10;
                *(s32 *)(*(u8 **)slot + 0x24) = 4;
                index++;
            }
            *(void **)(*(u8 **)(state + 4) + 8) = (void *)fclBankRenderStateBase;
            *(s32 *)(*(u8 **)(state + 4) + 0x10) = 0;
            *(void **)(*(u8 **)(state + 8) + 8) = (void *)fclBankRenderStateFull;
            *(s32 *)(*(u8 **)(state + 8) + 0x10) = 0;
            ((FclBankDrawWork *)state)->state = ((FclBankDrawWork *)state)->state + 1;
            break;
        }
    case 1:
        sdkDbprtQueueText(iGpffff85c8, (const char *)D_005DD5D0);
        *(s32 *)(*(u8 **)(state + 4) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 4) + 4) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 0) = 0;
        *(s32 *)(*(u8 **)(state + 8) + 4) = 0;
        PrimAppendNode(D_00793E80, *(u8 **)(state + 4));
        PrimAppendNode(D_00793E80, *(u8 **)(state + 8));
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Bank task destroy: free the slot's batch nodes and release its task memory [inferred]
/* Typed task work accesses changed codegen (nd5); retain task work +0x38 and node pointers +4/+8. */
// FUN_00103980
void fclBankTaskDestroy(u8 *task) {
    u8 *state;

    state = *(u8 **)(task + 0x38);
    PrimFreeBatchNode(*(s32 *)(state + 4));
    PrimFreeBatchNode(*(s32 *)(state + 8));
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Create the bank task with its update and destroy callbacks [inferred]
// FUN_001039E0
void fclBankTaskCreate(void) {
    chkmemAllocSiteTag(D_005DD600, 0xBD);
    (s32)kwlnTaskCreate((const void *)(&iGpffff85d0), 0xF, 0, 0, fclBankTaskUpdate, fclBankTaskDestroy, (u8 *)(D_008873F4[0](1, 0x210, 0x40000)));
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Reset the bank slot table's per-slot flags and counters [inferred]
/* Keep the linker-visible interior table aliases and their byte stride; rebasing them changes relocation targets. */
// FUN_00103A60
void fclBankTableReset(void)
{
    s16 i;
    s16 j;

    for (i = 0; i < 2; ++i) {
        *(s16 *)(D_00796700 + (i * 0x370)) = 0;
        *(s32 *)(D_00796700 + (i * 0x370) + 0x50) = 0;
        for (j = 0; j < 2; ++j) {
            *(s32 *)(D_00796700 + (i * 0x370) + (j * 4) + 0x14) = 0;
        }
    }
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Register the bank resource tables and load each of the two bank slots [inferred]
// FUN_00103B00
void fclBankTableInit(void) {
    extern u8 D_00796460[];
    extern u8 D_00796700[];
    extern void fclBankSlotLoad(u8 *arg0);
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
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Load a bank slot's resources from its archive entries and register them [inferred]
/* Texture and primitive-array cursor casts preserve external resource pointer interfaces. */
/* Typed display-slot accesses changed codegen (nd432); retain the 0x370-byte slot layout: state +0, textures +0x14, archive +0x24, request +0x48. */
// FUN_00103C40
void fclBankSlotLoad(u8 *slot)
{
    extern u8 D_005DD630[];
    extern u8 D_005DD640[];
    extern u8 D_005DD670[];
    extern u32 H_Cdvd_IsFileLoaded(struct HCdvd *archive);
    extern const char *H_Cdvd_ArchiveEntryName(struct HCdvd *archive, s32 index);
    extern u8 *filerEnqueueRequest(s32 kind, const char *name, const char *path,
                            s32 flags, s32 source, s32 buffer, s32 byteCount,
                            const char *cacheName, s32 resultKind, s32 memoryKind);
    extern u8 *filerTakeCompletedRequest(u8 *request, s32 *complete, s32 *size);
    extern s32 func_004672c0(s32 request, u8 *archive);
    extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 mode);
    extern u32 H_Cdvd_Destroy(struct HCdvd *archive);
    extern s32 func_003ef3a0(struct RwTexture *texture);
    extern void fclBankSlotUpdate(u8 *slot);
    extern s32 sprintf(u8 *destination, const u8 *format, ...);
    s32 complete;
    s16 state;
    u8 *texture;
    s32 index;
    u8 *textureSlot;
    u8 *archive;
    u8 *request;
    s32 offset;

    state = *(s16 *)slot;
    switch (state) {
    case 1:
        *(s32 *)(slot + 0x36C) = *(s32 *)(slot + 0x36C) + 1;
        if (H_Cdvd_IsFileLoaded(*(struct HCdvd **)(slot + 0x24)) == 0) {
            break;
        }
        if (H_Cdvd_ArchiveEntryName(*(struct HCdvd **)(slot + 0x24),
                          *(s32 *)(slot + 0x4C)) != NULL) {
            sprintf(slot + 0x60, D_005DD630,
                           H_Cdvd_ArchiveEntryName(*(struct HCdvd **)(slot + 0x24),
                                          *(s32 *)(slot + 0x4C)));
            *(u8 **)(slot + 0x48) =
                filerEnqueueRequest(0, (const char *)slot + 0x60, NULL,
                              0, 0, 0, 0, NULL, 0, 0);
            *(s16 *)slot = 2;
            break;
        }
        H_Cdvd_Destroy(*(struct HCdvd **)(slot + 0x24));
        *(u8 **)(slot + 0x24) = NULL;
        *(s16 *)slot = 3;
        func_00440b68(D_005DD640, *(s16 *)(slot + 4),
                      *(s16 *)(slot + 6), *(s16 *)(slot + 8),
                      *(s32 *)(slot + 0x364), *(s32 *)(slot + 0x368),
                      *(s32 *)(slot + 0x36C));
        break;
    case 2:
        *(s32 *)(slot + 0x368) = *(s32 *)(slot + 0x368) + 1;
        texture = filerTakeCompletedRequest(*(u8 **)(slot + 0x48), &complete, NULL);
        offset = *(s32 *)(slot + 0x4C) * 4;
        *(u8 **)(offset + (u32)slot + 0x14) = texture;
        if (complete != 0) {
            offset = *(s32 *)(slot + 0x4C) * 4;
            texture = *(u8 **)(offset + (u32)slot + 0x14);
            *(u32 *)(texture + 0x50) =
                (*(u32 *)(texture + 0x50) & 0xFFFF00FF) | 0x3300;
            *(u8 **)(slot + 0x48) = NULL;
            *(s32 *)(slot + 0x4C) = *(s32 *)(slot + 0x4C) + 1;
            *(s16 *)slot = 1;
            break;
        }
        break;
    case 4:
        fclBankSlotUpdate(slot);
        break;
    case 5:
    case 6:
        *(s32 *)(slot + 0x364) = *(s32 *)(slot + 0x364) + 1;
        request = *(u8 **)(slot + 0x48);
        if (request != NULL) {
            func_004672c0((s32)request, *(u8 **)(slot + 0x24));
            *(u8 **)(slot + 0x48) = NULL;
            *(u8 **)(slot + 0x24) = NULL;
        } else {
            archive = *(u8 **)(slot + 0x24);
            if (archive != NULL) {
                H_Cdvd_Destroy((struct HCdvd *)archive);
                *(u8 **)(slot + 0x24) = NULL;
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
        if (*(s16 *)slot != 6) {
            *(s16 *)slot = 0;
        } else {
            func_00440b68((u8 *)&iGpffff85d0 + 8, D_005DD670, 0xC5);
            *(u8 **)(slot + 0x24) = H_Cdvd_AcquireDirectory(slot + 0x60, 1);
            *(s16 *)slot = 1;
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
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Advance a bank slot's loading and display state each step [inferred]
/* Camera access and biased vertex cursors retain byte addressing where the external layout is incomplete. */
/* Typed vertex/display accesses changed codegen (nd1156); retain 0x40-byte vertices at +0x160/+0x260 and display fields at their measured offsets. */
// FUN_00103F00
void fclBankSlotUpdate(u8 *display)
{
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
        depth = *(f32 *)(display + 0x20);
        b = display[0x1E];
        g = display[0x1D];
        r = display[0x1C];
        inverse = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
        {
            s32 i;
            u8 *quad;

            for (i = 0; i < 4; i++) {
                quad = display + (i << 6);
                *(f32 *)(quad + 0x180) = (f32)r;
                *(f32 *)(quad + 0x184) = (f32)g;
                *(f32 *)(quad + 0x188) = (f32)b;
                *(f32 *)(quad + 0x18C) = (f32)a;
                *(f32 *)(quad + 0x168) = RwIm2DGetNearScreenZ() - depth;
                *(f32 *)(quad + 0x178) = inverse;
            }
        }
        *(Float2_0010 *)pos = *(Float2_0010 *)(display + 0xC);
        halfWidth = (512.0f * *(f32 *)(display + 0x28)) / 2.0f;
        halfHeight = (256.0f * *(f32 *)(display + 0x2C)) / 2.0f;
        fx = pos[0];
        x0 = 256.0f + fx;
        left = x0 - halfWidth;
        *(f32 *)(display + 0x160) = left;
        fy = pos[1];
        y0 = 128.0f + fy;
        top = y0 - halfHeight;
        *(f32 *)(display + 0x164) = top;
        right = (x0 + halfWidth) - 1.0f;
        *(f32 *)(display + 0x1A0) = right;
        *(f32 *)(display + 0x1A4) = top;
        *(f32 *)(display + 0x1E0) = left;
        bottom = (y0 + halfHeight) - 1.0f;
        *(f32 *)(display + 0x1E4) = bottom;
        *(f32 *)(display + 0x220) = right;
        *(f32 *)(display + 0x224) = bottom;
        kwlnGetCamera();
        *(s32 *)(display + 0x170) = 0;
        *(s32 *)(display + 0x174) = 0;
        *(s32 *)(display + 0x1B0) = 0x3F800000;
        *(s32 *)(display + 0x1B4) = 0;
        *(s32 *)(display + 0x1F0) = 0;
        *(s32 *)(display + 0x1F4) = 0x3F800000;
        *(s32 *)(display + 0x230) = 0x3F800000;
        *(s32 *)(display + 0x234) = 0x3F800000;
        PrimQueueStateSet(D_00796460, 1, **(s32 **)(display + 0x14));
        PrimQueueDrawPrimitive(D_00796460, 4, display + 0x160, 4);
        if (*(s32 *)(display + 0x4C) >= 2) {
            a = display[0x1F];
            if (a == 0xFF && *(s32 *)(display + 0x50) != 0) {
                if (*(s32 *)(display + 0x54) != 0) {
                    depth = *(f32 *)(display + 0x20);
                    b = display[0x1E];
                    g = display[0x1D];
                    r = display[0x1C];
                    inverse = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
                    {
                        s32 i;
                        u8 *quad;

                        for (i = 0; i < 4; i++) {
                            quad = display + (i << 6);
                            *(f32 *)(quad + 0x280) = (f32)r;
                            *(f32 *)(quad + 0x284) = (f32)g;
                            *(f32 *)(quad + 0x288) = (f32)b;
                            *(f32 *)(quad + 0x28C) = (f32)a;
                            *(f32 *)(quad + 0x268) = RwIm2DGetNearScreenZ() - depth;
                            *(f32 *)(quad + 0x278) = inverse;
                        }
                    }
                    offset = (f32)*(s32 *)(display + 0x360);
                    halfWidth = (512.0f * *(f32 *)(display + 0x28)) / 2.0f;
                    halfHeight = (64.0f * *(f32 *)(display + 0x2C)) / 2.0f;
                    fx = pos[0];
                    x0 = 256.0f + fx;
                    left = x0 - halfWidth;
                    *(f32 *)(display + 0x260) = left;
                    fy = pos[1];
                    y0 = 32.0f + fy;
                    top = offset + (y0 - halfHeight);
                    *(f32 *)(display + 0x264) = top;
                    right = (x0 + halfWidth) - 1.0f;
                    *(f32 *)(display + 0x2A0) = right;
                    *(f32 *)(display + 0x2A4) = top;
                    *(f32 *)(display + 0x2E0) = left;
                    bottom = (offset + (y0 + halfHeight)) - 1.0f;
                    *(f32 *)(display + 0x2E4) = bottom;
                    *(f32 *)(display + 0x320) = right;
                    *(f32 *)(display + 0x324) = bottom;
                    kwlnGetCamera();
                    *(s32 *)(display + 0x270) = 0;
                    *(s32 *)(display + 0x274) = 0;
                    *(s32 *)(display + 0x2B0) = 0x3F800000;
                    *(s32 *)(display + 0x2B4) = 0;
                    *(s32 *)(display + 0x2F0) = 0;
                    *(s32 *)(display + 0x2F4) = 0x3F800000;
                    *(s32 *)(display + 0x330) = 0x3F800000;
                    *(s32 *)(display + 0x334) = 0x3F800000;
                    PrimQueueStateSet(D_00796460, 1, **(s32 **)(display + 0x18));
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
                count = *(s32 *)(display + 0x58) - 1;
                *(s32 *)(display + 0x58) = count;
                if (count <= 0) {
                    if (*(s32 *)(display + 0x54) != 0) {
                        *(s32 *)(display + 0x54) = 0;
                    } else {
                        *(s32 *)(display + 0x54) = 1;
                    }
                    index = *(s32 *)(display + 0x5C) + 1;
                    *(s32 *)(display + 0x5C) = index;
                    index = index % 6;
                    *(s32 *)(display + 0x5C) = index;
                    *(s32 *)(display + 0x58) = table[index];
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Mark a bank slot as finished (state 5) [inferred]
/* The state table is an interior linker alias with a 0x370-byte display stride. */
// FUN_001044D0
void fclBankMarkDone(s64 bank) {
    *(s16 *)(D_00796700 + ((s16)bank * 0x370)) = 5;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Configure a bank slot from a three-id descriptor, looking up its table entry; default 0x3E when not found [inferred]
/* Interior data aliases are separate linker symbols; keep byte strides for those stores and the descriptor lookup. */
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
    *(s16 *)(D_00796700 + offset) = 5;
    *(s32 *)(D_0079674C + offset) = 0;
    *(s16 *)(D_00796704 + offset) = firstId;
    *(s16 *)(D_00796706 + offset) = secondId;
    *(s16 *)(D_00796708 + offset) = thirdId;
    sprintf(buf, D_005DD6C0,
                  (s32)firstId, (s32)secondId, (s32)thirdId);
    strcpy(D_00796700 + offset + 0x60, buf);
    *(s16 *)(D_00796700 + offset) = 6;
    *(s32 *)(D_00796A64 + offset) = 0;
    *(s32 *)(D_00796A68 + offset) = 0;
    *(s32 *)(D_00796A6C + offset) = 0;
    *(u8 *)(D_0079671C + offset) = 0xff;
    *(u8 *)(D_0079671E + offset) = 0xff;
    *(u8 *)(D_0079671D + offset) = 0xff;
    *(u8 *)(D_0079671F + offset) = 0xff;
    *(u32 *)(D_00796728 + offset) = 0x3f800000;
    *(u32 *)(D_0079672C + offset) = 0x3f800000;
    i = 0;
    found = 1;
    do {
        entry = D_005DD610 + i * 0x10;
        if (*(s32 *)entry == -1)
            break;
        if ((s32)firstId == *(s32 *)entry &&
            (s32)secondId == *(s32 *)(entry + 4) &&
            (s32)thirdId == *(s32 *)(entry + 8)) {
            *(s32 *)(D_00796A60 + offset) =
                *(s32 *)(D_005DD61C + i * 0x10);
            found = 0;
            break;
        }
        i++;
    } while (1);
    if (found)
        *(s32 *)(D_00796A60 + offset) = 0x3e;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Set the alpha byte of a bank slot [inferred]
/* The alpha table is an interior linker alias; retain its 0x370-byte stride. */
// FUN_00104770
void fclBankSetAlpha(s64 bank, u8 alpha) {
    *(u8 *)(D_0079671F + (((s16)bank) * 0x370)) = alpha;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Set a bank slot's active flag; when set, reset its phase and timers [inferred]
/* These state tables are interior linker aliases, each stepped by the display-slot stride. */
// FUN_001047B0
void fclBankSetActive(s64 bank, s32 active) {
    s32 offset;

    offset = (s16)bank * 0x370;
    *(s32 *)(D_00796750 + offset) = active;
    if (active != 0) {
        *(s32 *)(D_00796754 + offset) = 1;
        *(s32 *)(D_0079675C + offset) = 0;
        *(s32 *)(D_00796758 + offset) = 2;
    }
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Resume a waiting bank slot (state 3 to 4) [inferred]
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
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Return a pointer to the bank slot's position fields [inferred]
// FUN_00104880
u8 *fclBankGetPositionPtr(s64 bank) {
    return D_00796700 + ((s16)bank * 0x370) + 0xC;
}
#pragma pop

#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// Intent: Report whether a bank slot is waiting (state 3) [inferred]
/* The state table is an interior linker alias with a 0x370-byte display stride. */
// FUN_001048C0
s32 fclBankIsWaiting(s64 bank) {
    return *(s16 *)(D_00796700 + ((s16)bank * 0x370)) == 3;
}
#pragma pop
