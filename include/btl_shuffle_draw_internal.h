#ifndef BTL_SHUFFLE_DRAW_INTERNAL_H
#define BTL_SHUFFLE_DRAW_INTERNAL_H

#include "type.h"
#include "rw/plcore/barenderstate.h"

typedef struct RwV3d {
    f32 x, y, z;
} BtlShuffleVec3;

/* The matrix tags and field layout agree with rw/plcore/bamatrix.h. */
typedef struct RwMatrixTag {
    BtlShuffleVec3 right;
    u32 flags;
    BtlShuffleVec3 up;
    u32 pad1;
    BtlShuffleVec3 at;
    u32 pad2;
    BtlShuffleVec3 pos;
    u32 pad3;
} BtlShuffleMatrix;

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

void func_00377930(u8 *work, s32 cardIndex, const BtlShuffleVec3 *position,
                  u8 *color, s32 restoreAlpha);

#endif
