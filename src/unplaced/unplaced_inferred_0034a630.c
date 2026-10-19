/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0034a630-0034ad40 */

#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"

#include "kwln_task_internal.h"

/* Layouts established by the setters and 0x200-byte ball-slot traversal below. */
typedef struct FclCombineModelWork {
    s8 state;
    u8 pad1[3];
    u8 cleared;
    u8 initialized;
    s8 ready;
    u8 pad7;
    u16 modelId;
    u8 padA[2];
    u8 *model;
    s32 modelData;
    u8 *resource;
    u8 pad18[0x10];
    s8 kind;
    u8 pad29[7];
    u8 matrix[0x40];
    u8 pad70[0x70];
    s32 viewState;
    s32 viewCounter;
    u8 padE8[4];
    u8 *firstSprite;
    u8 *secondSprite;
} FclCombineModelWork;

typedef struct FclBallVertex {
    f32 x, y, z;
    u8 padC[4];
    s32 u, v;
    f32 reciprocal;
    u8 pad1C[4];
    f32 red, green, blue, alpha;
    u8 pad30[0x10];
} FclBallVertex;

typedef struct FclBallSlot {
    FclBallVertex vertices[4];
    s16 order;
    u8 pad102[2];
    s16 flags;
    u8 pad106[2];
    f32 depth;
    u8 pad10C[0x20];
    f32 x, y;
    u8 pad134[0x2E];
    u8 alpha;
    u8 pad163[0x16];
    u8 red, green, blue;
    u8 pad17C[0x18];
    f32 width;
    u8 pad198[8];
    f32 height;
    u8 pad1A4[0x5C];
} FclBallSlot;

typedef struct FclBallSlots {
    FclBallSlot slots[12];
    u8 count;
} FclBallSlots;

typedef struct FclBallPacket {
    u8 pad0[8];
    void *callback;
    u8 padC[4];
    u8 *data;
} FclBallPacket;
extern s32 (*D_00887300[])(RwRenderState, void *);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00793E80[];
extern s32 fclSpriteUpdateTweens(void *object);
extern void memcpy(void *object, s32 value, s32 mode);
extern s32 kwlnGetCamera(void);
extern u8 *PrimQueueDrawPrimitive(void *object, s32 value, void *mode, s32 count);
extern u8 D_00793E80[];
extern void fclCombineDrawPacket(u8 *packet, s32 data, void *callback);
extern f32 fGpffff8504;
extern f32 D_008872F8[];
extern u8 D_0064A6E0[];
extern u8 D_0064A6F0[];
// Intent: Return the combine object's work block pointer [inferred]
// FUN_0034A630
s32 fclCombineGetWork(u8 *task)
{
    return (s32)((KwlnTask *)task)->work;
}

#define COPY_SCALAR_PAIR_0034(dst, src) \
do { \
    s64 copy_s64; \
    f32 copy_f32; \
    copy_s64 = (src).whole; \
    copy_f32 = (src).tail; \
    (dst).whole = copy_s64; \
    (dst).tail = copy_f32; \
} while (0)

// Intent: Set the combine object's model: when its id or kind changes and no fade runs, free the old model, clone the new entry and reset its matrices [inferred]
// FUN_0034A640
/* measured: opt_propagation off preserves scalar Pair-copy source order. */
#pragma push
#pragma opt_propagation off
void fclCombineSetModel(u8 *task, u16 modelId, s64 kind)
{
    extern void mdlDestroyModelObject(void *object);
    extern void datFreeBlock(void *object);
    extern u8 *datCloneEntryBlock(s8 object);
    extern void RwMatrixRotate(void *object, void *value, s32 mode, f32 angle);
    extern void RwMatrixTranslate(void *object, void *value, s32 mode);
    extern void kwlnTaskDestroyWithHierarchy(void *object);
    extern u8 *cmbCardEffCreateSprite(void *object, void *value, s32 mode);
    extern u8 D_0064A700[];
    extern u8 D_0064A720[];
    extern s32 iGpffffb5a0;
    typedef struct {
        s64 whole;
        f32 tail;
    } Pair;
    u8 *modelWork;
    Pair translation;
    Pair rotationAxis;
    modelWork = ((KwlnTask *)task)->work;
    COPY_SCALAR_PAIR_0034(translation, *(Pair *)D_0064A6E0);
    COPY_SCALAR_PAIR_0034(rotationAxis, *(Pair *)D_0064A6F0);
    /* measured: typing modelId/kind changes reloads (492/484 bytes versus 480).
       Pointer-member typing also changes reloads; child slots alone grow to 488 bytes.
       Keep these accesses raw, with their proven offsets documented above. */

    if (((*(u16 *)(modelWork + 8) != (u16)modelId) ||
         (*(s8 *)(modelWork + 0x28) != (s8)kind) ||
         (((FclCombineModelWork *)modelWork)->state == 0)) &&
        ((u16)modelId != 0) &&
        ((s8)kind < 2))
    {
        if ((((FclCombineModelWork *)modelWork)->state > 0) && (((FclCombineModelWork *)modelWork)->state <= 2))
            return;
        if (*(u8 **)(modelWork + 0xC) != NULL) {
            mdlDestroyModelObject(*(u8 **)(modelWork + 0xC));
            *(u8 **)(modelWork + 0xC) = NULL;
        }
        if (*(u8 **)(modelWork + 0x14) != NULL) {
            datFreeBlock(*(u8 **)(modelWork + 0x14));
            *(u8 **)(modelWork + 0x14) = NULL;
        }
        *(u16 *)(modelWork + 8) = modelId;
        ((FclCombineModelWork *)modelWork)->state = 1;
        *(s8 *)(modelWork + 0x28) = kind;
        ((FclCombineModelWork *)modelWork)->ready = 0;
        *(u8 **)(modelWork + 0x14) = datCloneEntryBlock(*(s8 *)(modelWork + 0x28));
        /* The cloned resource header is not otherwise described here; +8 supplies model data. */
        ((FclCombineModelWork *)modelWork)->modelData = *(s32 *)(*(u8 **)(modelWork + 0x14) + 8);
        RwMatrixRotate(modelWork + 0x30, &rotationAxis, 0, 180.0f);
        RwMatrixTranslate(modelWork + 0x30, &translation, 2);
        iGpffffb5a0 = 0;
        if (*(s8 *)(modelWork + 0x28) == 0) {
            if (*(u8 **)(modelWork + 0xEC) != NULL) {
                kwlnTaskDestroyWithHierarchy(*(u8 **)(modelWork + 0xEC));
                *(u8 **)(modelWork + 0xEC) = NULL;
            }
            *(u8 **)(modelWork + 0xEC) = cmbCardEffCreateSprite(task, D_0064A700, 0);
            if (*(u8 **)(modelWork + 0xF0) != NULL) {
                kwlnTaskDestroyWithHierarchy(*(u8 **)(modelWork + 0xF0));
                *(u8 **)(modelWork + 0xF0) = NULL;
            }
            *(u8 **)(modelWork + 0xF0) = cmbCardEffCreateSprite(task, D_0064A720, 7);
        }
    }
}
#pragma pop

#undef COPY_SCALAR_PAIR_0034

// Intent: Clear the combine object's first state byte and set its second to 1 [inferred]
// FUN_0034A820
void fclCombineClearState(u8 *task)
{
    u8 *modelWork;

    modelWork = ((KwlnTask *)task)->work;
    ((FclCombineModelWork *)modelWork)->cleared = 0;
    ((FclCombineModelWork *)modelWork)->initialized = 1;
}

// Intent: Zero the combine object's view counters and initialise its view state [inferred]
// FUN_0034A840
void fclCombineInitView(u8 *task) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)task)->work);
    ((FclCombineModelWork *)work)->viewCounter = 0;
    ((FclCombineModelWork *)work)->viewState = 0;
    /* measured: a typed viewState address is hoisted across kwlnGetCamera (72 versus 80 bytes). */
    func_003e8130((u8 *)kwlnGetCamera(), work + 0xE0);
}

// Intent: Mark the combine object ready by setting its sixth state byte [inferred]
// FUN_0034A890
void fclCombineSetReady(u8 *task)
{
    u8 *modelWork;

    modelWork = ((KwlnTask *)task)->work;
    ((FclCombineModelWork *)modelWork)->ready = 1;
}

// Intent: Draw one combine packet: set the sky render states and the far-plane and tint values, then run the state dispatcher [inferred]
// FUN_0034A8B0
/* Preserve the dispatcher contract and the four retail far-plane observations. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void fclCombineDrawPacket(u8 *packet, s32 data, void *callback)
{
    extern s32 fclCombineGetRaster(void);
    f32 reciprocal;
    s32 *raster;
    s32 (**state)(RwRenderState, void *);
    s32 i;
    u8 *v;

    /* Camera +0x80 is used as the reciprocal divisor; its full layout is not established here. */
    reciprocal = 1.0f / *(f32 *)((u8 *)kwlnGetCamera() + 0x80);
    raster = (s32 *)fclCombineGetRaster();
    state = D_00887300;
    state[0](6, (void *)1);
    state[0](7, (void *)2);
    state[0](8, (void *)1);
    state[0](9, (void *)2);
    state[0](0xC, (void *)1);
    state[0](2, (void *)3);
    state[0](0xB, (void *)6);
    state[0](0xA, (void *)5);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    ((FclBallSlot *)data)->vertices[0].u = 0;
    ((FclBallSlot *)data)->vertices[0].v = 0;
    ((FclBallSlot *)data)->vertices[1].u = 0x3F800000;
    ((FclBallSlot *)data)->vertices[1].v = 0;
    ((FclBallSlot *)data)->vertices[2].u = 0;
    ((FclBallSlot *)data)->vertices[2].v = 0x3F800000;
    ((FclBallSlot *)data)->vertices[3].u = 0x3F800000;
    ((FclBallSlot *)data)->vertices[3].v = 0x3F800000;
    i = 0;
    while ((s64)(s16)i < 4) {
        f32 farZ;
        f32 depth;
        v = (u8 *)data + ((s32)(s64)(s16)(s64)i << 6);
        farZ = *(f32 *)D_008872F8;
        depth = ((FclBallSlot *)data)->depth;
        ((FclBallVertex *)v)->z = farZ - depth;
        ((FclBallVertex *)v)->reciprocal = reciprocal;
        ((FclBallVertex *)v)->red = (f32)(u32)((FclBallSlot *)data)->red;
        ((FclBallVertex *)v)->green = (f32)(u32)((FclBallSlot *)data)->green;
        ((FclBallVertex *)v)->blue = (f32)(u32)((FclBallSlot *)data)->blue;
        ((FclBallVertex *)v)->alpha = (f32)(u32)((FclBallSlot *)data)->alpha;
        i = (s64)(s16)(i + 1);
    }
    ((FclBallSlot *)data)->vertices[0].x = ((FclBallSlot *)data)->x;
    ((FclBallSlot *)data)->vertices[0].y = ((FclBallSlot *)data)->y;
    {
        f32 width;
        width = ((FclBallSlot *)data)->width;
        ((FclBallSlot *)data)->vertices[1].x = width * 32.0f + ((FclBallSlot *)data)->x;
    }
    ((FclBallSlot *)data)->vertices[1].y = ((FclBallSlot *)data)->y;
    ((FclBallSlot *)data)->vertices[2].x = ((FclBallSlot *)data)->x;
    ((FclBallSlot *)data)->vertices[2].y = ((FclBallSlot *)data)->height * 32.0f + ((FclBallSlot *)data)->y;
    ((FclBallSlot *)data)->vertices[3].x = ((FclBallSlot *)data)->width * 32.0f + ((FclBallSlot *)data)->x;
    ((FclBallSlot *)data)->vertices[3].y = ((FclBallSlot *)data)->height * 32.0f + ((FclBallSlot *)data)->y;
    state[0](1, (void *)*raster);
}
#pragma pop

// Ball slot task update: for each slot up to the count at +0x1800 whose flag bit 0 is set, inside its time window, with a nonzero +0x162, queues the slot's draw packet.
// FUN_0034AC00
/* measured: opt_propagation off plus a named local forces the GP global read to its written position, producing retail's field-first/global-second order. */
#pragma push
#pragma opt_propagation off
s32 fclCmbBallSlotsUpdate(u8 *task)
{
    s32 counter;
    s16 bumped;
    u8 *entry;
    u8 *base;
    u8 *sub;
    u8 *entry2;
    s16 index;
    s32 offset;
    u8 *packet;

    base = ((KwlnTask *)task)->work;
    kwlnGetCamera();
    counter = 0;
    while ((s64)(s16)counter < ((FclBallSlots *)base)->count) {
        entry = base + ((s32)(s64)(s16)(s64)counter << 9);
        sub = entry + 0x104;
        memcpy(sub, fclSpriteUpdateTweens(sub), 0xF0);
        if ((((FclBallSlot *)entry)->flags & 1) == 1) {
            f32 field;
            f32 global;
            field = ((FclBallSlot *)entry)->width;
            global = fGpffff8504;
            if ((!(field <= global)) &&
                (((FclBallSlot *)entry)->height > global) &&
                (((FclBallSlot *)entry)->alpha > 0)) {
                entry2 = base + ((s32)(s16)counter << 9);
                index = ((FclBallSlot *)entry2)->order;
                offset = index << 1;
                offset += index;
                offset <<= 4;
                packet = PrimQueueDrawPrimitive(D_00793E80 + offset, 4, entry2, 4);
                ((FclBallPacket *)packet)->callback = (void *)fclCombineDrawPacket;
                ((FclBallPacket *)packet)->data = entry2;
            }
        }
        bumped = counter + 1;
        counter = (s64)(s16)bumped;
    }
    return 0;
}
#pragma pop

// Ball slot task destroy: forwards the state block to jump-table slot 0.
// FUN_0034AD40
void fclCmbBallSlotsDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
