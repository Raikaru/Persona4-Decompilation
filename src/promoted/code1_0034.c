#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
extern void nLineDrawCurrent();
extern s32 (*D_00887300[])(RwRenderState, void *);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern void sdkSpriteDraw(u8 *arg0, s32 arg1);
extern void kAssertFail(const void *file, s32 line);
extern char D_0064B310[];
extern u32 RpRandom();

extern void (*jtbl_008873EC[])(void *);

void nLineUpdate();
void PrimAppendNode(u8 *arg0, u8 *arg1);
extern u8 D_00793E80[];
extern s32 D_00882FC0[];
extern s32 D_00882FC4[];
extern s32 D_00884670[];
extern s32 D_00884684[];
extern u16 iGpffffb5a4;
extern u8 *sdkSpriteNewNode(s32 arg0, s32 arg1);
extern s32 fclSpriteUpdateTweens(void *arg0);
extern void memcpy(void *arg0, s32 arg1, s32 arg2);
extern s32 kwlnGetCamera(void);
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern u8 D_00793E80[];
extern void fclCombineDrawPacket(u8 *packet, s32 data, void *callback);
extern f32 fGpffff8504;
extern f32 fGpffff8224;
extern void sdkSpriteFreeNode(void *node);
extern f32 D_0088467C[];
extern f32 D_008872F8[];
extern u8 D_0064A6E0[];
extern u8 D_0064A6E8[];
extern u8 D_0064A6F0[];
extern u8 D_0064A6F8[];

// struct passed by value to fclCombineSetSprite (64-bit: two floats in $a1-$a2)
typedef struct {
    f32 x;
    f32 y;
} Svec2f_0034b820;

// struct passed by value to fclCombineSetSprite (32-bit: four bytes in $a3)
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} S4b_0034b820;

void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                   u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0);

void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8);

// FUN_00349340
s32 func_00349340(u8 *unusedTask)
{
    s8 buf[0xC];
    s8 *p;
    s32 count;

    p = buf;
    count = 0xC;
    if (p != NULL)
    {
        do
        {
            *p = 0;
            p += 1;
            count -= 1;
        } while (count != 0);
    }
    return 0;
}
// FUN_00349380
void debugModelDrawDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

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
#undef COPY_SCALAR_PAIR_0034
/* measured: restore pragma state after fclCombineSetModel probe. */
#pragma pop
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
/* measured: restore pragma state after func_0034ac00. */
#pragma pop
// Ball slot task destroy: forwards the state block to jump-table slot 0.
// FUN_0034AD40
void fclCmbBallSlotsDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// Intent: Return the combine object's work block pointer, the same body as fclCombineGetWork [inferred]
// FUN_0034B810
s32 fclCombineGetWorkAlt(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// Intent: Set the combine sprite's position, sprite id, colour and scale, and flag the sprite as changed [inferred]
// FUN_0034B820
void fclCombineSetSprite(u8 *arg0, Svec2f_0034b820 v, s16 s, S4b_0034b820 b, f32 fparg0)
{
    u8 *obj = *(u8 **)(arg0 + 0x38);
    *(Svec2f_0034b820 *)(obj + 0xE38) = v;
    *(f32 *)(obj + 0xE14) = fparg0;
    *(s16 *)(obj + 0x0) = s;
    *(u8 *)(obj + 0xE6E) = b.b3;
    *(u8 *)(obj + 0xE85) = b.b0;
    *(u8 *)(obj + 0xE86) = b.b1;
    *(u8 *)(obj + 0xE87) = b.b2;
    *(s16 *)(obj + 0xE10) |= 1;
}

// Intent: Set the combine's tint bytes and timing and flag the tint as changed [inferred]
// FUN_0034B880
void fclCombineSetTint(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    *(u8 *)(p + 0xE6C) = arg1;
    *(u8 *)(p + 0xE6D) = arg2;
    *(u8 *)(p + 0xE6E) = arg1;
    *(s16 *)(p + 0xE6A) = 0;
    *(s16 *)(p + 0xE68) = arg4;
    *(s16 *)(p + 0xE70) = arg5;
    *(u8 *)(p + 0xE72) = arg3;
    *(s16 *)(p + 0xE10) |= 4;
}
// FUN_0034B8C0
void func_0034b8c0(void)
{
}

// Intent: Refresh the nLine task: when both state flags are set, run the nLine setup and reset its counters [inferred]
// FUN_0034B8D0
s32 nLineRefreshTask(u8 *unusedTask)
{
    if ((D_00884684[0] != 0) && (D_00884670[0] != 0)) {
        nLineUpdate();
        D_00882FC0[0] = 0;
        D_00882FC4[0] = 0;
        PrimAppendNode(D_00793E80 + iGpffffb5a4 * 0x30, (u8 *)D_00882FC0);
    }
    return 0;
}

// Intent: Registered nLine callback that draws the layer at the origin [inferred]
// FUN_0034B950
void nLineDrawOriginCallback(void)
{
    nLineDrawCurrent();
}

/* measured: opt_propagation off caches the D_00887300 base in $s0. */
// Intent: Set the base render states for nLine drawing [inferred]
// FUN_0034EDC0
#pragma opt_propagation off
void nLineSetRenderStateBase(void)
{
    s32 (**base)(RwRenderState, void *);

    base = D_00887300;
    base[0](7, (void *)2);
    base[0](6, (void *)0);
    base[0](8, (void *)0);
    base[0](1, (void *)0);
    base[0](0xE, (void *)0);
    base[0](0xA, (void *)5);
    base[0](0xB, (void *)7);
    base[0](0xC, (void *)1);
}
/* measured: close opt_propagation bracket for nLineSetRenderStateBase. */
#pragma opt_propagation on
// Intent: Draw the three nLine layers, with the middle and right layers faded by the amount [inferred]
// FUN_0034EE90
void nLineDrawLayers(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2)
{
    f32 alpha;
    f32 x;
    f32 delta;
    f32 invScale;
    f32 baseY;
    f32 baseX;
    f32 levelF;
    u8 level;
    u8 *unit;
    u8 *layers;

    level = (u8)((u8)(*(u8 *)(arg0 + 0x994)));
    levelF = (f32)(u32)level;
    alpha = levelF / 255.0f;
    unit = (u8 *)(arg0);
    baseX = fparg0;
    if (!(fparg2 <= 0.0f)) {
        delta = D_008872F8[0] - D_0088467C[0];
        invScale = 1.0f / *(f32 *)((u8 *)kwlnGetCamera() + 0x80);
        layers = unit + 0x790;
        *(s32 *)(unit + 0x990) = 1;
        baseY = 448.0f + fparg1;
        x = baseX - 208.0f;
        x += *(f32 *)(unit + 0x99C);
        nLineSetLayer(layers, x, baseY + *(f32 *)(unit + 0x9A0), delta, invScale, 0xFF, 0xE9, 0x36, 0);
        baseX = 640.0f + (f32)baseX;
        alpha = 51.0f * fparg2 * (f32)alpha;
        nLineSetLayer(layers + 0x40, baseX + *(f32 *)(unit + 0x99C), baseY + *(f32 *)(unit + 0x9A0), delta, invScale, 0xFF, 0xE9, 0x36, (u8)alpha);
        nLineSetLayer(layers + 0x80, baseX + *(f32 *)(unit + 0x99C), fparg1 + *(f32 *)(unit + 0x9A0), delta, invScale, 0xFF, 0xE9, 0x36, 0);
        return;
    }
    *(s32 *)(unit + 0x990) = 0;
}
// Intent: Store one nLine layer's position, scale and colour bytes [inferred]
// FUN_0034F0D0
void nLineSetLayer(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    *(f32 *)(arg0 + 0) = fparg0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg2;
    *(f32 *)(arg0 + 0x18) = fparg3;
    *(f32 *)(arg0 + 0x20) = (f32)arg1;
    *(f32 *)(arg0 + 0x24) = (f32)arg2;
    *(f32 *)(arg0 + 0x28) = (f32)arg3;
    *(f32 *)(arg0 + 0x2C) = (f32)arg4;
}
// Intent: Set the default render states and the sky state values for sprite draws [inferred]
// FUN_0034F1E0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
#pragma opt_propagation off
void sdkRenderStateSetDefault(void)
{
    s32 (**base)(RwRenderState, void *);

    base = D_00887300;
    base[0](6, (void *)0);
    base[0](7, (void *)2);
    base[0](8, (void *)0);
    base[0](9, (void *)2);
    base[0](0xC, (void *)1);
    base[0](0xB, (void *)6);
    base[0](0xA, (void *)5);
    base[0](2, (void *)4);
    base[0](0xE, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
/* measured: closing opt_propagation bracket for sdkRenderStateSetDefault. */
#pragma opt_propagation on
/* Coordinates precede byte color and opacity arguments. The core skips
   transparent sprites and stores inverse opacity in the packet. */
// Intent: Draw a sprite at a position with the given colour and opacity at unit size, skipping transparent sprites [inferred]
// FUN_0034F2E0
void sdkSpriteDrawAt(void *arg0, f32 fparg0, f32 fparg1,
                   u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    sdkSpriteDrawSized(arg0, fparg0, fparg1, 0.0f, arg1, arg2, arg3, arg4,
                  0x1000, 0x1000, 0, 0.0f, 0);
}

// Intent: Set the sprite's position, colour, opacity, size and extra fields, then draw it; a zero opacity or zero size skips the draw [inferred]
// FUN_0034F320
void sdkSpriteDrawSized(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                   u16 arg6, s16 arg7, f32 fparg3, s16 arg_sp0)
{
    u8 temp;

    if (arg0 == NULL)
        kAssertFail(D_0064B310, 0x6C);
    temp = arg4 & 0xFF;
    if ((temp == 0) || ((arg5 & 0xFFFF) == 0) ||
        ((arg6 & 0xFFFF) == 0))
        return;
    *(f32 *)(arg0 + 8) = fparg0;
    *(f32 *)(arg0 + 0xC) = fparg1;
    *(s8 *)(arg0 + 0x28) = arg1;
    *(s8 *)(arg0 + 0x29) = arg2;
    *(s8 *)(arg0 + 0x2A) = arg3;
    *(s8 *)(arg0 + 0x10) = 0;
    *(s8 *)(arg0 + 0x11) = 0xFF - temp;
    *(f32 *)(arg0 + 0x24) = fparg2;
    *(s16 *)(arg0 + 0x20) = arg5;
    *(s16 *)(arg0 + 0x22) = arg6;
    *(s16 *)(arg0 + 0x1C) = arg7;
    *(s16 *)(arg0 + 0x1E) = arg_sp0;
    *(f32 *)(arg0 + 0x18) = fparg3;
    sdkSpriteDraw(arg0, 0);
}
// Intent: Draw one sprite through a temporary node at the given position, with the given colour and opacity [inferred]
// FUN_0034F460
void sdkSpriteDrawOnceAt(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    sdkSpriteDrawOnceScaled(arg0, arg1, fparg0, fparg1, 0.0f, arg2, arg3, arg4, arg5,
                  0x1000, 0x1000, 0.0f, 0, 0);
}

// Intent: Draw one sprite through a temporary node: allocate it, draw with the transform arguments, then free it [inferred]
// FUN_0034F4A0
void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2,
                   u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7,
                   f32 fparg3, s16 arg_sp0, s16 arg_sp8)
{
    u8 *handle;

    if (arg0 == 0)
        kAssertFail(D_0064B310, 0x94);
    handle = sdkSpriteNewNode(arg0, arg1);
    sdkSpriteDrawSized(handle, fparg0, fparg1, fparg2, arg2, arg3, arg4,
                  arg5, arg6, arg7, arg_sp0, fparg3, arg_sp8);
    sdkSpriteFreeNode(handle);
}
/* On countdown expiry, choose a state or -1, then reset the countdown to 2..6.
   Snapshot extent before RNG, but read the other fields after it as retail does.
   measured: direct short decrement, staged remainder and distance <= half with
   propagation disabled match all 336B, including signed-halving branches. */
#pragma opt_propagation off
// Intent: Countdown step for a 0x14-byte entry: when the countdown expires, choose a random state of -1 or 0 to 2 by distance and reset the countdown to 2 to 6 [inferred]
// FUN_0034F5D0
void datCommunityEntryStep(u8 *arg0)
{
    u32 remainder;
    s32 extent;
    u32 random;
    s32 distance;
    s32 half;
    s32 span;
    u32 choice;

    if (--*(s16 *)(arg0 + 2) <= 0) {
        extent = *(s32 *)(arg0 + 12);
        random = RpRandom();
        remainder = random % (u32)(extent / 2 + 1);
        distance = (s32)(extent - *(s32 *)(arg0 + 4) - remainder);
        if (distance < 0) distance = 0;
        half = *(s32 *)(arg0 + 8) / 2;
        if (distance <= half) {
            span = 20 - half * 2 - distance;
            if (span > 0) {
                choice = RpRandom() % (u32)span;
                if (choice < 9U) {
                    *(s16 *)(arg0 + 0) = (s16)(choice % 3U);
                } else {
                    *(s16 *)(arg0 + 0) = -1;
                }
            } else {
                *(s16 *)(arg0 + 0) = (s16)(RpRandom() % 3U);
            }
        } else {
            *(s16 *)(arg0 + 0) = -1;
        }
        *(s16 *)(arg0 + 2) = (s16)(RpRandom() % 5U + 2);
    }
}
/* measured: restore propagation after the exact countdown update. */
#pragma opt_propagation on
// Intent: Fade of a grid cell from its fractions: the product of the two linear interpolations scaled by the third fraction, with range assertions [inferred]
// FUN_0034F720
f32 cmpGridCellFade(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    if ((fparg0 < 0.0f) || !(fparg0 <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD0);
    }
    if ((fparg1 < 0.0f) || !(fparg1 <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD1);
    }
    if ((fparg2 < 0.0f) || !(fparg2 <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD2);
    }
    if ((*(s32 *)(arg0 + 0xC) - 1) <= 0) {
        kAssertFail(D_0064B310, 0xD3);
    }
    if ((*(s32 *)(arg0 + 0x10) - 1) <= 0) {
        kAssertFail(D_0064B310, 0xD4);
    }
    return fparg2 *
           ((f32)(*(s32 *)(arg0 + 4)) *
            ((1.0f - fparg0) / (f32)(*(s32 *)(arg0 + 0xC) - 1)) +
            fparg0) *
           ((f32)(*(s32 *)(arg0 + 8)) *
            ((1.0f - fparg1) / (f32)(*(s32 *)(arg0 + 0x10) - 1)) +
            fparg1);
}
// Intent: Step a 16-bit value one unit toward its target on a timer, re-roll on expiry, and snap when it passes the target [inferred]
// FUN_0034F8F0
void datSmoothTargetStep(u8 *arg0)
{
  s32 temp_3_2;
  s32 var_2;
  *((s16 *) (arg0 + 8)) -= 1;
  if (*((s16 *) (arg0 + 8)) < 0)
  {
    temp_3_2 = (short) ((s64) ((*((s16 *) arg0)) - (*((s16 *) (arg0 + 6)))));
    if (temp_3_2 != 0)
    {
      if (temp_3_2 < 0)
      {
        var_2 = -temp_3_2;
      }
      else
      {
        var_2 = temp_3_2;
      }
      *((s16 *) (arg0 + 6)) += (s16) (temp_3_2 / var_2);
    }
    RpRandom();
    temp_3_2 = 8;
    *((s16 *) (arg0 + temp_3_2)) = 2;
  }
  *((s16 *) (arg0 + 4)) -= 1;
  if (((*((s16 *) (arg0 + 4))) < 0) || ((*((s16 *) (arg0 + 2))) < (*((s16 *) (arg0 + 6)))))
  {
    var_2 = 0;
    *((s16 *) (arg0 + 2)) = *((s16 *) (arg0 + 6));
    *((s16 *) (arg0 + 4)) = var_2;
  }
}
// Intent: Draw the footer sprite group at the position with the given alpha, style and resource [inferred]
// FUN_0034F9D0
void sdkSpriteDrawFooter(Svec2f_0034b820 unused, f32 fparg0, u8 arg1, s32 arg2, s32 arg3) {
    u8 *temp_2;
    u8 *temp_2_100;
    u8 *temp_2_101;
    u8 *temp_2_102;
    u8 *temp_2_103;
    u8 *temp_2_104;
    u8 *temp_2_105;
    u8 *temp_2_106;
    u8 *temp_2_107;
    u8 *temp_2_108;
    u8 *temp_2_109;
    u8 *temp_2_10;
    u8 *temp_2_110;
    u8 *temp_2_111;
    u8 *temp_2_112;
    u8 *temp_2_113;
    u8 *temp_2_114;
    u8 *temp_2_115;
    u8 *temp_2_116;
    u8 *temp_2_117;
    u8 *temp_2_118;
    u8 *temp_2_119;
    u8 *temp_2_11;
    u8 *temp_2_120;
    u8 *temp_2_121;
    u8 *temp_2_122;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_15;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_18;
    u8 *temp_2_19;
    u8 *temp_2_20;
    u8 *temp_2_21;
    u8 *temp_2_22;
    u8 *temp_2_23;
    u8 *temp_2_24;
    u8 *temp_2_25;
    u8 *temp_2_26;
    u8 *temp_2_27;
    u8 *temp_2_28;
    u8 *temp_2_29;
    u8 *temp_2_2;
    u8 *temp_2_30;
    u8 *temp_2_31;
    u8 *temp_2_32;
    u8 *temp_2_33;
    u8 *temp_2_34;
    u8 *temp_2_35;
    u8 *temp_2_36;
    u8 *temp_2_37;
    u8 *temp_2_38;
    u8 *temp_2_39;
    u8 *temp_2_3;
    u8 *temp_2_40;
    u8 *temp_2_41;
    u8 *temp_2_42;
    u8 *temp_2_43;
    u8 *temp_2_44;
    u8 *temp_2_45;
    u8 *temp_2_46;
    u8 *temp_2_47;
    u8 *temp_2_48;
    u8 *temp_2_49;
    u8 *temp_2_4;
    u8 *temp_2_50;
    u8 *temp_2_51;
    u8 *temp_2_52;
    u8 *temp_2_53;
    u8 *temp_2_54;
    u8 *temp_2_55;
    u8 *temp_2_56;
    u8 *temp_2_57;
    u8 *temp_2_58;
    u8 *temp_2_59;
    u8 *temp_2_5;
    u8 *temp_2_60;
    u8 *temp_2_61;
    u8 *temp_2_62;
    u8 *temp_2_63;
    u8 *temp_2_64;
    u8 *temp_2_65;
    u8 *temp_2_66;
    u8 *temp_2_67;
    u8 *temp_2_68;
    u8 *temp_2_69;
    u8 *temp_2_6;
    u8 *temp_2_70;
    u8 *temp_2_71;
    u8 *temp_2_72;
    u8 *temp_2_73;
    u8 *temp_2_74;
    u8 *temp_2_75;
    u8 *temp_2_76;
    u8 *temp_2_77;
    u8 *temp_2_78;
    u8 *temp_2_79;
    u8 *temp_2_7;
    u8 *temp_2_80;
    u8 *temp_2_81;
    u8 *temp_2_82;
    u8 *temp_2_83;
    u8 *temp_2_84;
    u8 *temp_2_85;
    u8 *temp_2_86;
    u8 *temp_2_87;
    u8 *temp_2_88;
    u8 *temp_2_89;
    u8 *temp_2_8;
    u8 *temp_2_90;
    u8 *temp_2_91;
    u8 *temp_2_92;
    u8 *temp_2_93;
    u8 *temp_2_94;
    u8 *temp_2_95;
    u8 *temp_2_96;
    u8 *temp_2_97;
    u8 *temp_2_98;
    u8 *temp_2_99;
    u8 *temp_2_9;

    if (arg3 != 0) {
        switch (arg2) {
        case -1:
            break;
        case 0:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2, 496.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_2 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_2, 510.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_2);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_3 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_3, (f32) 0x227, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_3);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_4 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_4, (f32) 0x235, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_4);
            return;
        case 1:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_5 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_5, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_5);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_6 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_6, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_6);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_7 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_7, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_7);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_8 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_8, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_8);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_9 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_9, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_9);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_10 = (u8 *)(sdkSpriteNewNode(arg3, 0x11));
            sdkSpriteDrawSized(temp_2_10, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_10);
            return;
        case 2:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_11 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_11, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_11);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_12 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_12, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_12);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_13 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_13, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_13);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_14 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_14, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_14);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_15 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_15, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_15);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_16 = (u8 *)(sdkSpriteNewNode(arg3, 0x12));
            sdkSpriteDrawSized(temp_2_16, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_16);
            return;
        case 3:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_17 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_17, (f32) 0x141, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_17);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_18 = (u8 *)(sdkSpriteNewNode(arg3, 0x18));
            sdkSpriteDrawSized(temp_2_18, 374.0f, 406.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_18);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_19 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_19, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_19);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_20 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_20, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_20);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_21 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_21, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_21);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_22 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_22, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_22);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_23 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_23, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_23);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_24 = (u8 *)(sdkSpriteNewNode(arg3, 0x11));
            sdkSpriteDrawSized(temp_2_24, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_24);
            return;
        case 4:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_25 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_25, (f32) 0x141, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_25);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_26 = (u8 *)(sdkSpriteNewNode(arg3, 0x18));
            sdkSpriteDrawSized(temp_2_26, 374.0f, 406.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_26);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_27 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_27, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_27);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_28 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_28, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_28);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_29 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_29, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_29);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_30 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_30, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_30);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_31 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_31, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_31);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_32 = (u8 *)(sdkSpriteNewNode(arg3, 0x12));
            sdkSpriteDrawSized(temp_2_32, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_32);
            return;
        case 5:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_33 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_33, 370.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_33);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_34 = (u8 *)(sdkSpriteNewNode(arg3, 0x18));
            sdkSpriteDrawSized(temp_2_34, 428.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_34);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_35 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_35, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_35);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_36 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_36, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_36);
            return;
        case 6:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_37 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_37, 239.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_37);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_38 = (u8 *)(sdkSpriteNewNode(arg3, 0x18));
            sdkSpriteDrawSized(temp_2_38, (f32) 0x129, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_38);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_39 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_39, (f32) 0x1A3, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_39);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_40 = (u8 *)(sdkSpriteNewNode(arg3, 0x17));
            sdkSpriteDrawSized(temp_2_40, 438.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_40);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_41 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_41, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_41);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_42 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_42, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_42);
            return;
        case 7:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_43 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_43, (f32) 0x1A3, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_43);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_44 = (u8 *)(sdkSpriteNewNode(arg3, 0x17));
            sdkSpriteDrawSized(temp_2_44, 438.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_44);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_45 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_45, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_45);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_46 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_46, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_46);
            return;
        case 8:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_47 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_47, (f32) 0x15F, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_47);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_48 = (u8 *)(sdkSpriteNewNode(arg3, 0x15));
            sdkSpriteDrawSized(temp_2_48, (f32) 0x16D, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_48);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_49 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_49, 420.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_49);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_50 = (u8 *)(sdkSpriteNewNode(arg3, 0x14));
            sdkSpriteDrawSized(temp_2_50, 434.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_50);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_51 = (u8 *)(sdkSpriteNewNode(arg3, 0xC));
            sdkSpriteDrawSized(temp_2_51, (f32) 0x1ED, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_51);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_52 = (u8 *)(sdkSpriteNewNode(arg3, 0x16));
            sdkSpriteDrawSized(temp_2_52, 508.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_52);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_53 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_53, (f32) 0x227, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_53);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_54 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_54, (f32) 0x235, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_54);
            return;
        case 9:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_55 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_55, 144.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_55);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_56 = (u8 *)(sdkSpriteNewNode(arg3, 0x13));
            sdkSpriteDrawSized(temp_2_56, 202.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_56);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_57 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_57, (f32) 0x12F, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_57);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_58 = (u8 *)(sdkSpriteNewNode(arg3, 0x15));
            sdkSpriteDrawSized(temp_2_58, 322.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_58);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_59 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_59, 430.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_59);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_60 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_60, (f32) 0x1C1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_60);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_61 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_61, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_61);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_62 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_62, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_62);
            return;
        case 11:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_63 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_63, (f32) 0x11F, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_63);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_64 = (u8 *)(sdkSpriteNewNode(arg3, 0x13));
            sdkSpriteDrawSized(temp_2_64, (f32) 0x159, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_64);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_65 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_65, 430.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_65);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_66 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_66, (f32) 0x1C1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_66);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_67 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_67, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_67);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_68 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_68, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_68);
            return;
        case 12:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_69 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_69, 224.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_69);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_70 = (u8 *)(sdkSpriteNewNode(arg3, 0x13));
            sdkSpriteDrawSized(temp_2_70, 282.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_70);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_71 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_71, (f32) 0x16F, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_71);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_72 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_72, (f32) 0x183, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_72);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_73 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_73, 430.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_73);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_74 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_74, (f32) 0x1C1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_74);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_75 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_75, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_75);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_76 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_76, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_76);
            return;
        case 13:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_77 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_77, (f32) 0x12F, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_77);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_78 = (u8 *)(sdkSpriteNewNode(arg3, 0x15));
            sdkSpriteDrawSized(temp_2_78, 322.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_78);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_79 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_79, 430.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_79);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_80 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_80, (f32) 0x1C1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_80);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_81 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_81, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_81);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_82 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_82, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_82);
            return;
        case 10:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_83 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_83, 446.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_83);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_84 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_84, (f32) 0x1D1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_84);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_85 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_85, (f32) 0x236, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_85);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_86 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_86, (f32) 0x249, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_86);
            return;
        case 14:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_87 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_87, 250.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_87);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_88 = (u8 *)(sdkSpriteNewNode(arg3, 0x18));
            sdkSpriteDrawSized(temp_2_88, 308.0f, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_88);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_89 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_89, 430.0f, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_89);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_90 = (u8 *)(sdkSpriteNewNode(arg3, 0x1A));
            sdkSpriteDrawSized(temp_2_90, (f32) 0x1C1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_90);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_91 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_91, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_91);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_92 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_92, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_92);
            return;
        case 15:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_93 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_93, (f32) 0x227, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_93);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_94 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_94, (f32) 0x235, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_94);
            return;
        case 16:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_95 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_95, 482.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_95);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_96 = (u8 *)(sdkSpriteNewNode(arg3, 0x19));
            sdkSpriteDrawSized(temp_2_96, 496.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_96);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_97 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_97, (f32) 0x223, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_97);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_98 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_98, (f32) 0x231, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_98);
            return;
        case 17:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_99 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_99, (f32) 0x197, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_99);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_100 = (u8 *)(sdkSpriteNewNode(arg3, 0x1B));
            sdkSpriteDrawSized(temp_2_100, (f32) 0x1D1, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_100);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_101 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_101, (f32) 0x226, 410.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_101);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_102 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_102, (f32) 0x239, 412.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_102);
            return;
        case 18:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_103 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_103, 496.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_103);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_104 = (u8 *)(sdkSpriteNewNode(arg3, 0x1F));
            sdkSpriteDrawSized(temp_2_104, 510.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_104);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_105 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_105, (f32) 0x227, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_105);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_106 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_106, (f32) 0x235, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_106);
            return;
        case 19:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_107 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_107, (f32) 0x13B, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_107);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_108 = (u8 *)(sdkSpriteNewNode(arg3, 0x20));
            sdkSpriteDrawSized(temp_2_108, 366.0f, 406.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_108);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_109 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_109, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_109);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_110 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_110, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_110);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_111 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_111, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_111);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_112 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_112, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_112);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_113 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_113, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_113);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_114 = (u8 *)(sdkSpriteNewNode(arg3, 0x11));
            sdkSpriteDrawSized(temp_2_114, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_114);
            return;
        case 20:
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_115 = (u8 *)(sdkSpriteNewNode(arg3, 0xE));
            sdkSpriteDrawSized(temp_2_115, (f32) 0x13B, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_115);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_116 = (u8 *)(sdkSpriteNewNode(arg3, 0x20));
            sdkSpriteDrawSized(temp_2_116, 366.0f, 406.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_116);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_117 = (u8 *)(sdkSpriteNewNode(arg3, 0xA));
            sdkSpriteDrawSized(temp_2_117, (f32) 0x1AD, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_117);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_118 = (u8 *)(sdkSpriteNewNode(arg3, 0xF));
            sdkSpriteDrawSized(temp_2_118, (f32) 0x1BB, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_118);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_119 = (u8 *)(sdkSpriteNewNode(arg3, 0xB));
            sdkSpriteDrawSized(temp_2_119, 484.0f, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_119);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_120 = (u8 *)(sdkSpriteNewNode(arg3, 0x10));
            sdkSpriteDrawSized(temp_2_120, 498.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_120);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_121 = (u8 *)(sdkSpriteNewNode(arg3, 0xD));
            sdkSpriteDrawSized(temp_2_121, (f32) 0x216, (f32) 0x195, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(temp_2_121);
            if (arg3 == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            temp_2_122 = (u8 *)(sdkSpriteNewNode(arg3, 0x12));
            sdkSpriteDrawSized(temp_2_122, 548.0f, 404.0f, fparg0, 0xFF, 0xFF, 0xFF, arg1, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(temp_2_122);
            return;
        default:
            kAssertFail(D_0064B310, 0x243);
            break;
        }
    }
}
