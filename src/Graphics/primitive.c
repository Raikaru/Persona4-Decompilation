/* Whole-file translation unit: src/Graphics/primitive.c */

/* Source unit: src/Graphics/primitive_0045f0b0.c (donor P3 FUN_00358a30 primQuad3D) */
#include "type.h"

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RwRGBA;

typedef struct
{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
} RwRGBAReal;

// 64 bytes
typedef struct
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

// 64 bytes
typedef struct
{
    RwV3d scrVertex;   // 0x00
    f32 camVertex_z;   // 0x0c
    f32 u;             // 0x10
    f32 v;             // 0x14
    f32 recipZ;        // 0x18
    f32 pad1;          // 0x1c
    RwRGBAReal color;  // 0x20
    RwV3d objNormal;   // 0x30
    f32 pad2;          // 0x3c
} RwIm2DVertex;

// minimal camera view (kwlnGetMainCamera): viewMatrix at 0x20, planes at 0x80
typedef struct
{
    u8 pad0[0x20];
    RwMatrix viewMatrix;  // 0x20
    u8 pad1[0x20];
    f32 nearPlane;        // 0x80
    f32 farPlane;         // 0x84
} RwCamera;

typedef enum
{
    rwRENDERSTATETEXTURERASTER = 1,
    rwRENDERSTATEZTESTENABLE = 6,
    rwRENDERSTATESHADEMODE = 7,
    rwRENDERSTATEZWRITEENABLE = 8,
    rwRENDERSTATEVERTEXALPHAENABLE = 12,
    rwRENDERSTATEFOGENABLE = 14,
    rwRENDERSTATECULLMODE = 20,
} RwRenderState;

typedef enum
{
    rwSHADEMODENASHADEMODE,
    rwSHADEMODEFLAT,
    rwSHADEMODEGOURAUD
} RwShadeMode;

typedef enum
{
    rwCULLMODENACULLMODE,
    rwCULLMODECULLNONE,
    rwCULLMODECULLBACK,
    rwCULLMODECULLFRONT
} RwCullMode;

typedef enum
{
    rwPRIMTYPENAPRIMTYPE,
    rwPRIMTYPELINELIST,
    rwPRIMTYPEPOLYLINE,
    rwPRIMTYPETRILIST,
    rwPRIMTYPETRISTRIP,
    rwPRIMTYPETRIFAN,
    rwPRIMTYPEPOINTLIST,
} RwPrimitiveType;

typedef enum
{
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
} RpSkyRenderState;

typedef int (*RwRenderStateSetFunc)(RwRenderState renderState, void* val);
typedef int (*RwRenderStateGetFunc)(RwRenderState renderState, void* val);
typedef int (*RwIm2DRenderPrimitiveFunction)(RwPrimitiveType primType, RwIm2DVertex* vertices, int numVertices);

// rwGlobals lives at 0x008872d8 in P4 retail; device slots:
// zBufferFar 0x20, zBufferNear 0x24, setRenderState 0x28,
// getRenderState 0x2c, fpIm2DRenderPrimitive 0x38.
typedef struct
{
    u8 unkData0[0x10];                             // 0x00
    f32 zBufferFar;                                // 0x10
    f32 zBufferNear;                               // 0x14
    RwRenderStateSetFunc setRenderState;           // 0x18
    RwRenderStateGetFunc getRenderState;           // 0x1c
    u8 unkData1[0x0c];                             // 0x20
    RwIm2DRenderPrimitiveFunction fpIm2DRenderPrimitive; // 0x28
    u8 unkData2[0x10];                             // 0x2c
} RwDevice;

typedef struct
{
    u8 unkData0[0x10];                             // 0x00
    RwDevice device;                               // 0x10
    u8 unkData1[0x04];
} RwGlobals;

extern RwGlobals rwGlobals;

#define PRIM_RENDERSTATE_COUNT 6

// 8 bytes
typedef struct
{
    RwRenderState renderState; // 0x00
    u32 val;                   // 0x04
} PrimRenderState;

// retail data at 0x00712490
static const PrimRenderState sRenderStates[PRIM_RENDERSTATE_COUNT] =
{
    {rwRENDERSTATEFOGENABLE, 0},
    {rwRENDERSTATEVERTEXALPHAENABLE, 1},
    {rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD},
    {rwRENDERSTATECULLMODE, rwCULLMODECULLNONE},
    {rwRENDERSTATEZTESTENABLE, 1},
    {rwRENDERSTATEZWRITEENABLE, 0}
};

// rwGlobals.device fields at their P4 retail addresses
// (see RwGlobals/RwDevice layout above)

extern RwCamera* func_00457120(void);           // kwlnGetMainCamera
extern void func_003e42a0(RwV3d* out, const RwV3d* in, const RwMatrix* matrix); // RwV3dTransformPoint
extern int RpSkyRenderStateSet(int nState, void* pParam); // RpSkyRenderStateSet

// 36 bytes
typedef struct
{
    RwV3d objVertex; // 0x00
    union
    {
        RwRGBA preLitColor;
        RwRGBA color;
    } c;             // 0x0c
    RwV3d objNormal; // 0x10
    f32 u;           // 0x1c
    f32 v;           // 0x20
} RwIm3DVertex;

enum
{
    rwIM3D_VERTEXUV = 1,
    rwIM3D_ALLOPAQUE = 2,
    rwIM3D_NOCLIP = 4,
    rwIM3D_VERTEXXYZ = 8,
    rwIM3D_VERTEXRGBA = 16
};

#define rwMATRIXINTERNALIDENTITY 0x00020000
#define rwMATRIXTYPEORTHONORMAL 0x00000003

#define rwMatrixSetFlags(m, flagsbit) ((m)->flags = (flagsbit))
#define rwMatrixGetFlags(m)           ((m)->flags)

#define RwMatrixSetIdentity(m)                                  \
do                                                              \
{                                                               \
    (m)->right.x = (m)->up.y    = (m)->at.z  = 1.0f;            \
    (m)->right.y = (m)->right.z = (m)->up.x  = 0.0f;            \
    (m)->up.z    = (m)->at.x    = (m)->at.y  = 0.0f;            \
    (m)->pos.x   = (m)->pos.y   = (m)->pos.z = 0.0f;            \
    rwMatrixSetFlags((m),                                       \
                     rwMatrixGetFlags(m) |                      \
                     (rwMATRIXINTERNALIDENTITY |                \
                      rwMATRIXTYPEORTHONORMAL));                \
} while(0)

#define RwIm3DVertexSetPos(_vert, _imx, _imy, _imz) \
    do                                              \
    {                                               \
        RwV3d _packed;                              \
        _packed.x = _imx;                           \
        _packed.y = _imy;                           \
        _packed.z = _imz;                           \
        (_vert)->objVertex = _packed;               \
    } while (0)

#define RwIm3DVertexSetRGBA(_vert, _r, _g, _b, _a) \
    do                                             \
    {                                              \
        RwRGBA * const _col = &(_vert)->c.color;   \
        _col->r = (_r);                            \
        _col->g = (_g);                            \
        _col->b = (_b);                            \
        _col->a = (_a);                            \
    } while(0)

typedef int (*RwRenderStateSetFunc)(RwRenderState renderState, void* val);

// rwGlobals.device fields at their P4 retail addresses
extern RwRenderStateSetFunc D_00887300[4];      // device.setRenderState
extern RwRenderStateGetFunc D_00887304[4];      // device.getRenderState
extern void func_00410420(RwIm3DVertex* pVerts, u32 numVerts, RwMatrix* ltm, u32 flags); // RwIm3DTransform
extern int func_00410930(int vert1, int vert2); // RwIm3DRenderLine

// retail data at 0x007124d0
static const RwV3d sAxisDirs[3] =
{
    {1.0f, 0.0f, 0.0f}, // X
    {0.0f, 1.0f, 0.0f}, // Y
    {0.0f, 0.0f, 1.0f}  // Z
};

// retail data at 0x007124f8
static const RwRGBA sAxisColors[3] =
{
    {255, 0, 0, 255}, // X (red)
    {0, 255, 0, 255}, // Y (green)
    {0, 0, 255, 255}  // Z (blue)
};
extern void primLine3D(const RwV3d* startPos, const RwV3d* endPos, const RwRGBA* color, u32 saveAndRestoreRenderState);

typedef struct
{
    f32 m00;
    f32 m01;
    f32 m02;
    u32 mode;
    f32 m10;
    f32 m11;
    f32 m12;
    u32 pad1;
    f32 m20;
    f32 m21;
    f32 m22;
    u32 unused;
    u32 pad2;
    u32 pad3;
    u32 pad4;
} PrimMatrixData;

extern void* RwMatrixScale(void* matrix, const void* scale, int combineOp); // RwMatrixScale
extern void RwMatrixMultiply(int dst, u8* a, float* b);                        // RwMatrixMultiply

typedef struct
{
    u8 pad0[8];
    struct
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } quat;
    f32 values[6];
    f32 value30;
} PrimInterpData;

// retail data at 0x00761118 (gp-relative float, P3 name fGpffff8028)
extern float fGpffff8028;
extern f32 func_0044b920(f32 param_1); // P3 FUN_0052e9e8 (acosf)
extern f32 sinf(f32 angle);   // P3 FUN_0052e878 (sinf)

extern void func_00480aa0(void* param_2, void* param_3, void* param_4, f32 param_1);

extern int func_003df1a0(u64 stream, void* buf, int size); // P3 FUN_004c1750
extern int func_003df240(u64 stream, void* buf, int size); // P3 FUN_004c17f0

typedef void (*PrimFuncB)(void*, void*, void*, f32);
typedef void (*PrimFuncA)(int, int);
typedef u32 (*PrimFuncC)(int, u64);
typedef u64 (*PrimFuncD)(u64, u64);
typedef void (*PrimFuncE)(void*, void*);
typedef void (*PrimFuncStub)(void);

typedef struct
{
    u32 hash;
    u32 size0;
    u32 size1;
    PrimFuncA funcA;
    PrimFuncB funcB;
    PrimFuncB funcB2;
    PrimFuncStub funcC;
    PrimFuncE funcD;
    PrimFuncD funcE;
    PrimFuncC funcF;
    PrimFuncStub funcG;
    u32 zero;
} PrimDesc;

extern void func_00480940(int param_1, int param_2);
extern void func_00480cd0(void* param_2, void* param_3, void* param_4, f32 param_1);
extern void func_004810c0(void);
extern void func_00480f20(void* param_1, void* param_2);
extern void* func_00480e20(void* param_1, void* param_2);
extern u32 func_00480d50(int param_1, u64 param_2);
extern u32 func_00480f00(void* param_1);
extern int func_003d5000(void* desc); // P3 FUN_004b6680



// FUN_0045F0B0
void primQuad3D(const RwV3d* pos, const RwRGBA* col, f32 size, u32 saveAndRestoreRenderState)
{
    u32 i;
    u32 j;
    const PrimRenderState* currRenderState;
    u32* currSavedRenderState;
    RwRenderStateSetFunc* setRenderState;
    RwV3d cameraPos;
    RwIm2DVertex vertices[4];
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    f32 zBufferNear;
    f32 zBufferFar;
    f32 nearPlane;
    f32 farPlane;
    f32 screenZ;
    f32 recipZ;
    f32 screenX;
    f32 screenY;

    func_003e42a0(&cameraPos, pos, &func_00457120()->viewMatrix);
    zBufferNear = rwGlobals.device.zBufferNear;
    zBufferFar = rwGlobals.device.zBufferFar;
    farPlane = func_00457120()->farPlane;
    nearPlane = func_00457120()->nearPlane;

    if (cameraPos.z > nearPlane && cameraPos.z < farPlane)
    {

        size *= 0.5f;
        screenZ = zBufferNear + (nearPlane / cameraPos.z) *
                                      ((cameraPos.z - farPlane) * ((zBufferFar - zBufferNear) / (nearPlane - farPlane)));
        if (screenZ < 0.0f)
        {
            screenZ = 0.0f;
        }

        recipZ = 1.0f / screenZ;
        screenX = 640.0f * (cameraPos.x / cameraPos.z);
        screenY = 448.0f * (cameraPos.y / cameraPos.z);

        if (saveAndRestoreRenderState)
        {
            for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
            {
                currRenderState = &sRenderStates[i];
                currSavedRenderState = &savedRenderStates[i];
                rwGlobals.device.getRenderState(currRenderState->renderState, (void*)currSavedRenderState);
                rwGlobals.device.setRenderState(currRenderState->renderState, (void*)currRenderState->val);
            }
            setRenderState = &rwGlobals.device.setRenderState;

            (*setRenderState)(rwRENDERSTATEZTESTENABLE, NULL);
            (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
            RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x48);    // SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0)
            RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x71801); // SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3)
        }

        vertices[0].scrVertex.x = screenX - size;
        vertices[0].scrVertex.y = screenY - size;
        vertices[0].scrVertex.z = screenZ;
        vertices[0].recipZ = recipZ;
        vertices[0].color.r = (f32)col->r;
        vertices[0].color.g = (f32)col->g;
        vertices[0].color.b = (f32)col->b;
        vertices[0].color.a = (f32)col->a;

        vertices[1].scrVertex.x = screenX - size;
        vertices[1].scrVertex.y = screenY + size;
        vertices[1].scrVertex.z = screenZ;
        vertices[1].recipZ = recipZ;
        vertices[1].color.r = (f32)col->r;
        vertices[1].color.g = (f32)col->g;
        vertices[1].color.b = (f32)col->b;
        vertices[1].color.a = (f32)col->a;

        vertices[2].scrVertex.x = screenX + size;
        vertices[2].scrVertex.y = screenY - size;
        vertices[2].scrVertex.z = screenZ;
        vertices[2].recipZ = recipZ;
        vertices[2].color.r = (f32)col->r;
        vertices[2].color.g = (f32)col->g;
        vertices[2].color.b = (f32)col->b;
        vertices[2].color.a = (f32)col->a;

        vertices[3].scrVertex.x = screenX + size;
        vertices[3].scrVertex.y = screenY + size;
        vertices[3].scrVertex.z = screenZ;
        vertices[3].recipZ = recipZ;
        vertices[3].color.r = (f32)col->r;
        vertices[3].color.g = (f32)col->g;
        vertices[3].color.b = (f32)col->b;
        vertices[3].color.a = (f32)col->a;

        rwGlobals.device.fpIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);

        if (saveAndRestoreRenderState)
        {
            for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
            {
                rwGlobals.device.setRenderState(sRenderStates[j].renderState, (void*)savedRenderStates[j]);
            }
        }
    }
}



// FUN_0045F790
void primLine3D(const RwV3d* startPos, const RwV3d* endPos, const RwRGBA* color, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32* currSavedRenderState;
    RwIm3DVertex vertices[2];
    RwMatrix identity;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32 j;

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currRenderState = &sRenderStates[i];
            currSavedRenderState = &savedRenderStates[i];
            D_00887304[0](currRenderState->renderState, (void*)currSavedRenderState);
            D_00887300[0](currRenderState->renderState, (void*)currRenderState->val);
        }

        D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);

        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x48);    // SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0)
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x71801); // SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3)
    }

    RwMatrixSetIdentity(&identity);

    RwIm3DVertexSetPos(&vertices[0], startPos->x, startPos->y, startPos->z);
    RwIm3DVertexSetPos(&vertices[1], endPos->x, endPos->y, endPos->z);
    RwIm3DVertexSetRGBA(&vertices[0], color->r, color->g, color->b, color->a);
    RwIm3DVertexSetRGBA(&vertices[1], color->r, color->g, color->b, color->a);

    func_00410420(vertices, 2, &identity, rwIM3D_ALLOPAQUE);
    func_00410930(0, 1);

    if (saveAndRestoreRenderState)
    {
        for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
        {
            D_00887300[0](sRenderStates[j].renderState, (void*)savedRenderStates[j]);
        }
    }
}



// FUN_0045FA00
void primAxisLine3D(const RwMatrix* mat, f32 length, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32 j;
    const RwV3d* currAxisDir;
    RwV3d finalAxisPoint;
    RwV3d axisPoint;

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currRenderState = &sRenderStates[i];
            D_00887304[0](currRenderState->renderState, (void*)&savedRenderStates[i]);
            D_00887300[0](currRenderState->renderState, (void*)currRenderState->val);
        }

        D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);

        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x48);    // SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0)
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x71801); // SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3)
    }

    for (j = 0; j < 3; j++)
    {
        currAxisDir = &sAxisDirs[j];

        axisPoint.x = length * currAxisDir->x;
        axisPoint.y = length * currAxisDir->y;
        axisPoint.z = length * currAxisDir->z;

        func_003e42a0(&finalAxisPoint, &axisPoint, mat);

        primLine3D(&mat->pos, &finalAxisPoint, &sAxisColors[j], 0);
    }

    if (saveAndRestoreRenderState)
    {
        for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
        {
            D_00887300[0](sRenderStates[j].renderState, (void*)savedRenderStates[j]);
        }
    }
}



// FUN_00480940
void func_00480940(int param_1, int param_2)
{
    u8 buffer[64];
    PrimMatrixData matrix;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 yz;
    f32 zx;
    f32 xy;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 value30;
    f32 value34;
    f32 value38;

    x = *(f32*)(param_2 + 8);
    y = *(f32*)(param_2 + 0xc);
    z = *(f32*)(param_2 + 0x10);
    w = *(f32*)(param_2 + 0x14);
    xx = x * x;
    yy = y * y;
    zz = z * z;
    yz = y * z;
    zx = z * x;
    xy = x * y;
    wx = w * x;
    wy = w * y;
    wz = w * z;

    matrix.m00 = 1.0f - (yy + zz) * 2.0f;
    matrix.m01 = (xy + wz) * 2.0f;
    matrix.m02 = (zx - wy) * 2.0f;
    matrix.m10 = (xy - wz) * 2.0f;
    matrix.m11 = 1.0f - (xx + zz) * 2.0f;
    matrix.m12 = (yz + wx) * 2.0f;
    matrix.m20 = (zx + wy) * 2.0f;
    matrix.m21 = (yz - wx) * 2.0f;
    matrix.m22 = 1.0f - (xx + yy) * 2.0f;

    matrix.pad2 = 0;
    matrix.pad3 = 0;
    matrix.pad4 = 0;
    matrix.mode = 3;

    RwMatrixScale((void*)buffer, (const void*)((u8*)param_2 + 0x24), 0);
    RwMatrixMultiply(param_1, buffer, (f32*)&matrix);

    value30 = *(volatile /* Removing this function's qualifier batch loses func_00480940 (MATCH nd0 -> MISMATCH nd6, size 348 -> 348) - measured W170. */ f32*)(param_2 + 0x18);
    value34 = *(volatile /* Removing this function's qualifier batch loses func_00480940 (MATCH nd0 -> MISMATCH nd6, size 348 -> 348) - measured W170. */ f32*)(param_2 + 0x1c);
    value38 = *(volatile /* Removing this function's qualifier batch loses func_00480940 (MATCH nd0 -> MISMATCH nd6, size 348 -> 348) - measured W170. */ f32*)(param_2 + 0x20);
    *(f32*)((int)param_1 + 0x30) = value30;
    *(f32*)((int)param_1 + 0x34) = value34;
    *(f32*)((int)param_1 + 0x38) = value38;
    *(u32*)((int)param_1 + 0xc) = *(u32*)((int)param_1 + 0xc) & 0xfffdffff;
}



// FUN_00480AA0
void func_00480aa0(void* param_2, void* param_3, void* param_4, f32 param_1)
{
    PrimInterpData* out = (PrimInterpData*)param_2;
    const PrimInterpData* first = (const PrimInterpData*)param_3;
    PrimInterpData* second = (PrimInterpData*)param_4;
    f32 dot;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 invSin;

    dot = first->quat.x * second->quat.x +
          first->quat.y * second->quat.y +
          first->quat.z * second->quat.z +
          first->quat.w * second->quat.w;
    if (dot < 0.0f)
    {
        dot = -dot;
        second->quat.x = -second->quat.x;
        second->quat.y = -second->quat.y;
        second->quat.z = -second->quat.z;
        second->quat.w = -second->quat.w;
    }

    firstWeight = 1.0f - param_1;
    secondWeight = param_1;
    if (dot < fGpffff8028)
    {
        angle = func_0044b920(dot);
        invSin = 1.0f / sinf(angle);
        firstWeight = invSin * sinf(firstWeight * angle);
        secondWeight = invSin * sinf(secondWeight * angle);
    }

    out->quat.x = firstWeight * first->quat.x + secondWeight * second->quat.x;
    out->quat.y = firstWeight * first->quat.y + secondWeight * second->quat.y;
    out->quat.z = firstWeight * first->quat.z + secondWeight * second->quat.z;
    out->quat.w = firstWeight * first->quat.w + secondWeight * second->quat.w;

    out->values[0] = secondWeight * (second->values[0] - first->values[0]) + first->values[0];
    out->values[1] = secondWeight * (second->values[1] - first->values[1]) + first->values[1];
    out->values[2] = secondWeight * (second->values[2] - first->values[2]) + first->values[2];
    out->values[3] = secondWeight * (second->values[3] - first->values[3]) + first->values[3];
    out->values[4] = secondWeight * (second->values[4] - first->values[4]) + first->values[4];
    out->values[5] = secondWeight * (second->values[5] - first->values[5]) + first->values[5];
}



// FUN_00480CD0
void func_00480cd0(void* param_2, void* param_3, void* param_4, f32 param_1)
{
    PrimInterpData* out = (PrimInterpData*)param_2;
    const PrimInterpData* first = (const PrimInterpData*)param_3;
    const PrimInterpData* second = (const PrimInterpData*)param_4;
    f32 firstTime;
    f32 secondTime;
    f32 t;

    firstTime = *(const f32*)((const u8*)first + 4);
    secondTime = *(const f32*)((const u8*)second + 4);
    t = (param_1 - firstTime) / (secondTime - firstTime);
    func_00480aa0(out, (void*)first, (void*)second, t);
    out->value30 = first->value30 * second->value30;
}



// FUN_00480D50
u32 func_00480d50(int param_1, u64 param_2)
{
    int iVar1;
    int lVar2;
    int* piVar3;
    int iVar4;
    int iStack_4;

    iVar1 = *(int*)((u8*)param_1 + 0x10);
    iVar4 = 0;
    while (iVar4 < *(int*)((u8*)param_1 + 4))
    {
        piVar3 = (int*)((u8*)iVar1 + iVar4 * 0x34);
        iStack_4 = *piVar3 - iVar1;
        lVar2 = func_003df1a0(param_2, piVar3 + 1, 0x30);
        if ((lVar2 == 0) || ((lVar2 = func_003df240(param_2, &iStack_4, 4), lVar2 == 0)))
        {
            return 0;
        }
        iVar4++;
    }
    return 1;
}



// FUN_00481250
u32 func_00481250(void)
{
    PrimDesc desc;
    int result;

    desc.hash = 0x44a07195;
    desc.size1 = 0x34;
    desc.size0 = 0x34;
    desc.funcA = func_00480940;
    desc.funcB = func_00480aa0;
    desc.funcB2 = func_00480cd0;
    desc.funcC = &func_004810c0;
    desc.funcD = func_00480f20;
    desc.funcE = (u64 (*)(u64, u64))func_00480e20;
    desc.funcF = func_00480d50;
    desc.funcG = (void (*)())func_00480f00;
    desc.zero = 0;

    result = func_003d5000(&desc);
    return result != 0;
}
