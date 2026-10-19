#ifndef BTL_SHUFFLE_DRAW_INTERNAL_H
#define BTL_SHUFFLE_DRAW_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"
#include "rw_camera_internal.h"
#include "rw/plcore/barenderstate.h"

typedef RwV3d BtlShuffleVec3;

/* Share the native matrix declaration with camera users. */
typedef RwMatrixTag BtlShuffleMatrix;

typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} BtlShuffleCombine;

typedef enum RwPrimitiveType {
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST,
    rwPRIMTYPEPOLYLINE,
    rwPRIMTYPETRILIST,
    rwPRIMTYPETRISTRIP,
    rwPRIMTYPETRIFAN,
    rwPRIMTYPEPOINTLIST,
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} BtlShufflePrimitive;

typedef struct RwRGBAReal {
    f32 r, g, b, a;
} BtlShuffleColor;

/* PS2 sky2 vertex layout from P3 include/rw/rwplcore.h, confirmed by the
 * P4 0x40-byte stride and position/reciprocal-Z/color field accesses. */
typedef struct RwSky2DVertexFields {
    BtlShuffleVec3 scrVertex;
    f32 camVertex_z;
    f32 u, v;
    f32 recipZ;
    f32 pad1;
    BtlShuffleColor color;
    BtlShuffleVec3 objNormal;
    f32 pad2;
} BtlShuffleSkyFields;

typedef union {
    BtlShuffleSkyFields els;
    unsigned __int128 qWords[4];
} BtlShuffleSkyOverlay;

typedef struct RwSky2DVertex {
    BtlShuffleSkyOverlay u;
} BtlShuffleSkyVertex;

typedef s32 (*BtlShuffleRenderStateSet)(RwRenderState state, void *value);
typedef s32 (*BtlShuffleRenderPrimitive)(BtlShufflePrimitive primitive,
                                       BtlShuffleSkyVertex *vertices,
                                       s32 count);

void btlShuffleDrawCardSprites(u8 *work, s32 cardIndex, const BtlShuffleVec3 *position,
                  u8 *color, s32 restoreAlpha);

/* The rotation initializer consumes two unsigned 16-bit timing values and
 * explicitly forwards both floating controls to the interpolation state. */
void btlShuffleCalcSetCurveSample(u8 *state, u16 timing0, u16 timing1,
                  const BtlShuffleVec3 *axis, f32 start, f32 end);
void btlShuffleDrawSetCurve(u8 *context, s32 cardIndex, u16 timing0, u16 timing1,
                  const BtlShuffleVec3 *axis, f32 start, f32 end);

/* Bits in a shuffle child task's flag word (work[0]), set by btlShuffleTask* helpers. */
typedef enum BtlShuffleTaskFlag {
    /* Set when the child task is started; cleared by the child when it finishes. */
    BTL_SHUFFLE_FLAG_BUSY = 1,
    /* Set by btlShuffleCancel to request cancellation; the parent waits while it is set. */
    BTL_SHUFFLE_FLAG_CANCEL_REQUESTED = 4,
} BtlShuffleTaskFlag;
/* Bits in the draw view's flag word (view+0x4C). Each names the phase that sets it and the phase that waits on it. */
#define BTL_SHUFFLE_VIEW_FLAG_MENU_BUSY 0x002   /* set at result menu start; cleared with the view's flags */
#define BTL_SHUFFLE_VIEW_FLAG_ACTIVE 0x004      /* set while the view is the active one */
#define BTL_SHUFFLE_VIEW_FLAG_CUE 0x008         /* set by a cue start; the run waits while it is set */
#define BTL_SHUFFLE_VIEW_FLAG_HOLD 0x010        /* set to hold the view during a sequence step */
#define BTL_SHUFFLE_VIEW_FLAG_STEP_PENDING 0x100 /* set by a step request; the seq waits while it is set */
#define BTL_SHUFFLE_VIEW_FLAG_FADE 0x200        /* set by a fade start; cleared when the fade ends */
#define BTL_SHUFFLE_VIEW_FLAG_REVEAL 0x400      /* set at the reveal start; the run waits while it is set */
/* Bit in the draw view's state word (view+0x4), tested by the result menu and run start. */
#define BTL_SHUFFLE_VIEW_STATE_READY 0x001
#endif
