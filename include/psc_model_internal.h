#ifndef PSC_MODEL_INTERNAL_H
#define PSC_MODEL_INTERNAL_H

#include "type.h"

/* The 0x24-byte vertex stride and 0x90-byte quads are shared by sfl_data,
 * pscLightInitQuad, pscModelDraw and the animated card tile builder. */
typedef struct PscVec
{
    f32 x, y, z;
} PscVec;

typedef struct PscLight
{
    PscVec dir;        /* 0x00: vertex position */
    u8 c[4];           /* 0x0C: RGBA */
    PscVec unused;     /* 0x10 */
    f32 f1c;           /* 0x1C: texture U */
    f32 f20;           /* 0x20: texture V */
} PscLight;

/* Layout shared by the initializers, animation update and draw dispatcher.
 * Mode 0/1 has a selector pair before its quads; modes 2/3 start at 0x170. */
typedef struct PscModel
{
    u32 flags;
    s32 mode;
    u8 pad08[8];
    PscVec rotation;
    f32 scale;
    PscVec position;
    PscVec axisScale;
    void *frame;        /* 0x38: parent frame for the position */
    f32 elapsed;
    u8 color[4];
    s32 transitionTime; /* 0x44: 16.16 frame counter */
    s32 unk48;
    PscLight unk4C[4];  /* Transition quad, uploaded with a 0x24-byte stride. */
    void *unkDC;
    PscLight e0[4];
    union
    {
        struct
        {
            s32 unk170;
            s32 unk174;
            PscLight b0[4];
            PscLight b1[4];
            PscLight b2[4];
            PscLight b3[4];
            PscLight b4[4];
            PscLight b5[4];
            PscLight b6[4];
            PscLight b7[4];
            PscLight b8[4];
        } m01;
        PscLight w170[4];
    } u;
} PscModel;

/* The tile builder traverses 68 vertices (nine alternating 8/7-point rows).
 * Its light source and weights immediately follow that 0x990-byte array. */
typedef struct PscTileMesh
{
    s32 flags;
    PscLight vertices[68];
    PscVec lightPosition;  /* 0x994 */
    f32 specularWeight;
    f32 diffuseWeight;
} PscTileMesh;

#endif
