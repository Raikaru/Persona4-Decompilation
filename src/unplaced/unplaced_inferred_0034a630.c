/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0034a630-0034ad40 */

#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
extern s32 (*D_00887300[])(RwRenderState, void *);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern void (*jtbl_008873EC[])(void *);
extern u8 D_00793E80[];
extern s32 fclSpriteUpdateTweens(void *arg0);
extern void memcpy(void *arg0, s32 arg1, s32 arg2);
extern s32 kwlnGetCamera(void);
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern u8 D_00793E80[];
extern void fclCombineDrawPacket(u8 *packet, s32 data, void *callback);
extern f32 fGpffff8504;
extern f32 D_008872F8[];
extern u8 D_0064A6E0[];
extern u8 D_0064A6F0[];
// Intent: Return the combine object's work block pointer [inferred]
// FUN_0034A630
s32 fclCombineGetWork(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
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
void fclCombineSetModel(u8 *arg0, u16 arg1, s64 arg2)
{
    extern void mdlDestroyModelObject(void *arg0);
    extern void datFreeBlock(void *arg0);
    extern u8 *datCloneEntryBlock(s8 arg0);
    extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 fparg0);
    extern void RwMatrixTranslate(void *arg0, void *arg1, s32 arg2);
    extern void kwlnTaskDestroyWithHierarchy(void *arg0);
    extern u8 *cmbCardEffCreateSprite(void *arg0, void *arg1, s32 arg2);
    extern u8 D_0064A700[];
    extern u8 D_0064A720[];
    extern s32 iGpffffb5a0;
    typedef struct {
        s64 whole;
        f32 tail;
    } Pair;
    u8 *obj;
    Pair sp50;
    Pair sp60;
    obj = *(u8 **)(arg0 + 0x38);
    COPY_SCALAR_PAIR_0034(sp50, *(Pair *)D_0064A6E0);
    COPY_SCALAR_PAIR_0034(sp60, *(Pair *)D_0064A6F0);

    if (((*(u16 *)(obj + 8) != (u16)arg1) ||
         (*(s8 *)(obj + 0x28) != (s8)arg2) ||
         (*(s8 *)(obj + 0) == 0)) &&
        ((u16)arg1 != 0) &&
        ((s8)arg2 < 2))
    {
        if ((*(s8 *)(obj + 0) > 0) && (*(s8 *)(obj + 0) <= 2))
            return;
        if (*(u8 **)(obj + 0xC) != NULL) {
            mdlDestroyModelObject(*(u8 **)(obj + 0xC));
            *(u8 **)(obj + 0xC) = NULL;
        }
        if (*(u8 **)(obj + 0x14) != NULL) {
            datFreeBlock(*(u8 **)(obj + 0x14));
            *(u8 **)(obj + 0x14) = NULL;
        }
        *(u16 *)(obj + 8) = arg1;
        *(s8 *)(obj + 0) = 1;
        *(s8 *)(obj + 0x28) = arg2;
        *(s8 *)(obj + 6) = 0;
        *(u8 **)(obj + 0x14) = datCloneEntryBlock(*(s8 *)(obj + 0x28));
        *(s32 *)(obj + 0x10) = *(s32 *)(*(u8 **)(obj + 0x14) + 8);
        RwMatrixRotate(obj + 0x30, &sp60, 0, 180.0f);
        RwMatrixTranslate(obj + 0x30, &sp50, 2);
        iGpffffb5a0 = 0;
        if (*(s8 *)(obj + 0x28) == 0) {
            if (*(u8 **)(obj + 0xEC) != NULL) {
                kwlnTaskDestroyWithHierarchy(*(u8 **)(obj + 0xEC));
                *(u8 **)(obj + 0xEC) = NULL;
            }
            *(u8 **)(obj + 0xEC) = cmbCardEffCreateSprite(arg0, D_0064A700, 0);
            if (*(u8 **)(obj + 0xF0) != NULL) {
                kwlnTaskDestroyWithHierarchy(*(u8 **)(obj + 0xF0));
                *(u8 **)(obj + 0xF0) = NULL;
            }
            *(u8 **)(obj + 0xF0) = cmbCardEffCreateSprite(arg0, D_0064A720, 7);
        }
    }
}
#pragma pop

#undef COPY_SCALAR_PAIR_0034

// Intent: Clear the combine object's first state byte and set its second to 1 [inferred]
// FUN_0034A820
void fclCombineClearState(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 4) = 0;
    *(u8 *)(p + 5) = 1;
}

// Intent: Zero the combine object's view counters and initialise its view state [inferred]
// FUN_0034A840
void fclCombineInitView(u8 *arg0) {
    u8 *work;

    work = (u8 *)(*(u8 **)(arg0 + 0x38));
    *(s32 *)(work + 0xE4) = 0;
    *(s32 *)(work + 0xE0) = 0;
    func_003e8130((u8 *)kwlnGetCamera(), work + 0xE0);
}

// Intent: Mark the combine object ready by setting its sixth state byte [inferred]
// FUN_0034A890
void fclCombineSetReady(u8 *arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 6) = 1;
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
    *(s32 *)((u8 *)data + 0x10) = 0;
    *(s32 *)((u8 *)data + 0x14) = 0;
    *(s32 *)((u8 *)data + 0x50) = 0x3F800000;
    *(s32 *)((u8 *)data + 0x54) = 0;
    *(s32 *)((u8 *)data + 0x90) = 0;
    *(s32 *)((u8 *)data + 0x94) = 0x3F800000;
    *(s32 *)((u8 *)data + 0xD0) = 0x3F800000;
    *(s32 *)((u8 *)data + 0xD4) = 0x3F800000;
    i = 0;
    while ((s64)(s16)i < 4) {
        f32 farZ;
        f32 depth;
        v = (u8 *)data + ((s32)(s64)(s16)(s64)i << 6);
        farZ = *(f32 *)D_008872F8;
        depth = *(f32 *)((u8 *)data + 0x108);
        *(f32 *)(v + 8) = farZ - depth;
        *(f32 *)(v + 0x18) = reciprocal;
        *(f32 *)(v + 0x20) = (f32)(u32)*(u8 *)((u8 *)data + 0x179);
        *(f32 *)(v + 0x24) = (f32)(u32)*(u8 *)((u8 *)data + 0x17A);
        *(f32 *)(v + 0x28) = (f32)(u32)*(u8 *)((u8 *)data + 0x17B);
        *(f32 *)(v + 0x2C) = (f32)(u32)*(u8 *)((u8 *)data + 0x162);
        i = (s64)(s16)(i + 1);
    }
    *(f32 *)((u8 *)data + 0) = *(f32 *)((u8 *)data + 0x12C);
    *(f32 *)((u8 *)data + 4) = *(f32 *)((u8 *)data + 0x130);
    {
        f32 width;
        width = *(f32 *)((u8 *)data + 0x194);
        *(f32 *)((u8 *)data + 0x40) = width * 32.0f + *(f32 *)((u8 *)data + 0x12C);
    }
    *(f32 *)((u8 *)data + 0x44) = *(f32 *)((u8 *)data + 0x130);
    *(f32 *)((u8 *)data + 0x80) = *(f32 *)((u8 *)data + 0x12C);
    *(f32 *)((u8 *)data + 0x84) = *(f32 *)((u8 *)data + 0x1A0) * 32.0f + *(f32 *)((u8 *)data + 0x130);
    *(f32 *)((u8 *)data + 0xC0) = *(f32 *)((u8 *)data + 0x194) * 32.0f + *(f32 *)((u8 *)data + 0x12C);
    *(f32 *)((u8 *)data + 0xC4) = *(f32 *)((u8 *)data + 0x1A0) * 32.0f + *(f32 *)((u8 *)data + 0x130);
    state[0](1, (void *)*raster);
}
#pragma pop

// Ball slot task update: for each slot up to the count at +0x1800 whose flag bit 0 is set, inside its time window, with a nonzero +0x162, queues the slot's draw packet.
// FUN_0034AC00
/* measured: opt_propagation off plus a named local forces the GP global read to its written position, producing retail's field-first/global-second order. */
#pragma push
#pragma opt_propagation off
s32 fclCmbBallSlotsUpdate(u8 *arg0)
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

    base = *(u8 **)(arg0 + 0x38);
    kwlnGetCamera();
    counter = 0;
    while ((s64)(s16)counter < *(u8 *)(base + 0x1800)) {
        entry = base + ((s32)(s64)(s16)(s64)counter << 9);
        sub = entry + 0x104;
        memcpy(sub, fclSpriteUpdateTweens(sub), 0xF0);
        if ((*(s16 *)(entry + 0x104) & 1) == 1) {
            f32 field;
            f32 global;
            field = *(f32 *)(entry + 0x194);
            global = fGpffff8504;
            if ((!(field <= global)) &&
                (*(f32 *)(entry + 0x1A0) > global) &&
                (*(u8 *)(entry + 0x162) > 0)) {
                entry2 = base + ((s32)(s16)counter << 9);
                index = *(s16 *)(entry2 + 0x100);
                offset = index << 1;
                offset += index;
                offset <<= 4;
                packet = PrimQueueDrawPrimitive(D_00793E80 + offset, 4, entry2, 4);
                *(void **)(packet + 8) = (void *)fclCombineDrawPacket;
                *(u8 **)(packet + 0x10) = entry2;
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
void fclCmbBallSlotsDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
