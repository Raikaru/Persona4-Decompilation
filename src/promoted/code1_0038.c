#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *);

extern void (*D_008873ec[])(s32);

void btlShuffleDrawViewRequestStep(u8 *drawWork, u8 input, u8 green, u8 blue);

s32 datGetFlag(u32 bit);

extern u8 *D_007246AC;
void btlShuffleDrawViewRequestWhiteStep(u8 *drawWork);
extern void memset(void *dst, s32 value, u32 size);
extern void nmMesWindowShowCurrentRecord(s32 recordIndex);
extern void nmMesWindowSetCurrentString(s32 variable, void *text);
extern s32 btlShuffleDrawCheck(u8 *context, u8 *output);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void btlShuffleInitWaveStrips(u8 *drawWork);
extern void btlShuffleDrawCardReset(u8 *drawWork);
extern void btlShuffleDrawViewForeground(s32 drawWork, u8 *input);
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern void btlShuffleDrawViewClearFlags(u8 *drawWork);
extern void btlShuffleDrawViewBackground(s32 drawWork, u8 *input);
extern s32 btlShuffleDrawViewStep(u8 *drawWork);
extern void btlShuffleDrawViewDestroy(u8 *drawWork);
extern u8 *iGpffffb5b0;
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void PrimAppendNode(u8 *list, u8 *node);
extern void kAssertFail(void *file, s32 line);
extern void sdkRenderStateSetDefault(void);
extern void btlShuffleDrawRevealBands(u8 *drawWork);
extern void btlShuffleDrawDetailBars(u8 *drawWork);
extern void btlShuffleDrawCountTransition(u8 *drawWork);
extern void btlShuffleDrawCardShadow(u8 *drawWork);
extern void btlShuffleDrawSelectionColumn(u8 *drawWork);

extern f32 D_00761470;
extern f32 D_008872F8[];
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
extern s32 kwlnGetCamera(void);
extern f32 cosf(f32 fparg0);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 hint);
extern s32 func_003df590(s32, ...);
extern u8 *func_003df4d0(s32 *);
extern void btlShuffleDrawBackgroundPulse();
extern void btlShuffleDrawBackgroundRings();
extern void btlShuffleDrawWave();
extern void btlShuffleUpdateRing();
extern void btlShuffleDrawSpriteCues();
extern void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y,
                          f32 depth, u8 red, u8 green, u8 blue, u8 alpha,
                          u16 scaleX, u16 scaleY, f32 angle, s16 pivotX,
                          s16 pivotY);

/* Window frame fade. The 192 alpha is converted to u8 separately at each vertex from a shared
 * product. The work floats are reused across phases: `ratio` holds the interpolation then the width
 * delta, `extent` the start value then the half width. -0.2617994f is -15 degrees in radians. */


/* Persona list panel. The slide-in ease is 2t - t*t, clamped. Every
   position term is written with a (0.0f + K) origin, as the sibling ring
   drawers are. The title x stays in a register and is also stored to
   pos.x. */


/* Animate four sprites with interpolated colors and rotated pixel offsets.
   The timer and random samples are snapshots; angle division precedes
   multiplication, and the second sine result is converted to a signed
   pixel offset after scaling. Opacity crosses the sprite API as a byte. */
typedef union Code38WavePhase {
    Vec2f direction[2];
    Vec2f pair[2];
} Code38WavePhase;

typedef struct Code38WaveWorkspace {
    Vec2f normal[2];
    Code38WavePhase phase;
    BtlShuffleSkyVertex vertices[62];
    /* Retail leaves sp+0x1030..0x1037 unused; this layout places delta at sp+0x1038. */
    u32 pad[2];
    Vec2f delta;
} Code38WaveWorkspace;

/* Ring samples use complete three-component vectors and two vertices per
 * sample. The 65 samples occupy the entire 130-vertex buffer. */
typedef struct Code38RingVertex {
    f32 x, y, z;
    u32 pad0, pad1, pad2;
    f32 reciprocalZ;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Code38RingVertex;


/* D_00761490 is the retail scalar 0xBD872B00, not the rounded -0.066f literal. */
typedef struct Code38RevealWeight {
    f32 value;
} Code38RevealWeight;


typedef struct {
    u16 counter;
    u16 pad;
    f32 x;
    f32 z;
    f32 y;
    f32 w;
} State_0038CAB0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    f32 scale;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} Vertex_0038CAB0;

// Kept here so this multi-run bucket stays link-eligible (has_first_party); see tools/build.py eligible_c_objects.
/* Reset the shuffle draw view, update its effects, then step their work.
 * The child task's work is the 0x50-byte allocation made by btlShuffleEffSpawn;
 * its first word holds the draw view returned by func_0036e910. */
// FUN_0038D660
s32 btlShuffleEffStep(u8 *task) {
    s32 *work;

    work = (s32 *)((SdkTask *)task)->work;
    btlShuffleDrawViewReset(*work);
    btlShuffleEffUpdate(task);
    btlShuffleUpdateRewardEffects(work);
    return 0;
}

/* RenderWare collision layouts from rw/inc/rpcollis.h and rw/core/babbox.h.
 * The legacy aggregate headers require include paths this owner does not use. */
typedef struct RwBBox { RwV3d sup, inf; } RwBBox;
typedef struct RpCollSplit RpCollSplit;
typedef struct RpCollTree {
    u32 flags;
    RwBBox bbox;
    u16 numEntries, numSplits;
    RpCollSplit *splits;
    u16 *map;
} RpCollTree;

#pragma schedule on
#pragma no_branch_likely on
/* Allocate a collision tree with aligned split storage and an optional entry map. */
// FUN_0038F990
u8 *rpCollTreeCreate(u16 entryCount, u16 splitCount, f32 *bounds, s32 flags)
{
    u8 *treeBytes;
    s32 count;
    s32 useMap;
    s32 splitAddress;
    s32 allocationSize;
    u8 *cursor;
    f32 componentY;
    f32 componentX;
    f32 componentZ;
    f32 lowerX;
    s32 failure[2];
    count = splitCount & 0xFFFF;
    allocationSize = 0x28;

    if (count > 0) {
        allocationSize += (count * 0x10) + 0xF;
    }
    goto dispatch_0;

add_0:
    allocationSize += ((entryCount & 0xFFFF) * 2) + 1;

alloc_0:
    cursor = jtbl_008873E8[0](allocationSize, 0x3002C);
    if (cursor == NULL) {
        goto failure_0;
    }
    ((RpCollTree *)cursor)->flags = flags;
    treeBytes = cursor;
    ((RpCollTree *)cursor)->numEntries = entryCount;
    ((RpCollTree *)cursor)->numSplits = splitCount;
    componentX = bounds[0];
    componentY = bounds[1];
    componentZ = bounds[2];
    lowerX = bounds[3];
    ((RpCollTree *)cursor)->bbox.sup.x = componentX;
    ((RpCollTree *)cursor)->bbox.sup.y = componentY;
    ((RpCollTree *)cursor)->bbox.sup.z = componentZ;
    ((RpCollTree *)cursor)->bbox.inf.x = lowerX;
    componentY = ((RwBBox *)bounds)->inf.y;
    componentX = componentY;
    componentY = ((RwBBox *)bounds)->inf.z;
    ((RpCollTree *)cursor)->bbox.inf.y = componentX;
    ((RpCollTree *)cursor)->bbox.inf.z = componentY;
    cursor += 0x28;
    if (count <= 0) {
        goto zero_extra;
    }
    splitAddress = ((s32)(cursor + 0xF)) & ~0xF;
    cursor = (u8 *)(splitAddress + (count * 0x10));
    *(s32 *)&((RpCollTree *)treeBytes)->splits = splitAddress;

pointer_0:
    if (useMap != 0) {
        *(s32 *)&((RpCollTree *)treeBytes)->map = ((s32)(cursor + 1)) & ~1;
    } else {
        *(s32 *)&((RpCollTree *)treeBytes)->map = 0;
    }
    return treeBytes;
dispatch_0:
    useMap = flags & 1;
    switch (useMap) {
    case 0:
        goto alloc_0;
    default:
        goto add_0;
    }

failure_0:
    failure[0] = 0x11D;
    failure[1] = func_003df590(0x80000013, allocationSize);
    func_003df4d0(failure);
    return NULL;
zero_extra:
    *(s32 *)&((RpCollTree *)treeBytes)->splits = 0;
    goto pointer_0;
}
/* measured: restores the unit setting after func_0038f990. */
#pragma schedule off
#pragma no_branch_likely off
// measured: retail adds the 0x30 constant separately in the branch delay slot instead of folding it
// into the split-count multiply.
#pragma schedule on
/* Return serialized collision-tree bytes, including chunk headers and the optional entry map. */
// FUN_0038FB20
s32 rpCollTreeStreamGetSize(u8 *treeBytes) {
    s32 streamSize;

    streamSize = 0x30;
    streamSize += ((RpCollTree *)treeBytes)->numSplits * 0x10;
    if ((s32)((RpCollTree *)treeBytes)->flags & 1) {
        streamSize += ((RpCollTree *)treeBytes)->numEntries * 2;
    }
    return streamSize;
}
// measured: closes the schedule-on bracket above; the function is already compiled, so this only
// keeps the pragma pairs balanced.
#pragma schedule off

/* measured: func_0038fe90 comes out closest to retail with instruction scheduling off; the
 * remaining gap is a larger stack frame and doubled base+offset address math. */
extern u8 *func_0038fe90(u8 *, u32, s32, f32 *, s32 *);
