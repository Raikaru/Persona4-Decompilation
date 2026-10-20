/* Whole-file translation unit: src/Graphics/Effect/effMisc.c */

/* Source unit: src/Graphics/Effect/effMisc_004bce50.c */
#include "include_asm.h"
#include "type.h"

typedef struct RwV4d
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} RwV4d;

extern f32 cosf(f32 x);
extern f32 sinf(f32 x);

typedef struct EffRandState
{
    u32 x[4]; // 0x00
} EffRandState;

extern u32 effMiscRand(EffRandState* state);

static EffRandState sRandState; // 00922de0

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern void effMiscAxisAngleMatrix(f32 angle, const RwV3d* axis, RwMatrix* matrix);



extern void mdlRenderInitializeBuffers(void);
extern f32 D_008872F8_abs[];
extern void (*D_00887300[])();
extern s32 (*D_00887310[])(s32, void *, s32);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887304[])();
extern void (*D_008873EC[])(void *);
typedef struct Code45RenderState {
    s32 state;
    s32 val;
} Code45RenderState;
extern Code45RenderState D_00712490[6];
extern void (*D_008873FC[])(s32 param, u8* arg);
extern s32 kwlnGetCamera(void);

/* RwCamera::nearPlane (+0x80); public layout is documented in rw/core/bacamera.h. */
typedef struct EffMiscCamera {
    u8 pad00[0x80];
    f32 nearPlane;
} EffMiscCamera;
/* Draws a 640-by-448 solid-color screen quad, optionally saving and restoring six render states. */
// FUN_0045C870
void effMiscDrawScreenColor(u8 *colors, s32 enabled)
{
    struct {
        s32 saved[6];
        u8 pad1[8];
        f32 out[64];
    } work;
    f32 depth;
    s32 state;
    f32 inv;
    s32 *p;
    u32 i;
    u32 j;

    if (enabled != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)&work.saved[i]);
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
    }
    depth = D_008872F8_abs[0];
    state = kwlnGetCamera();
    inv = 1.0f / ((EffMiscCamera *)state)->nearPlane;

    work.out[0] = 0.0f;
    work.out[1] = 0.0f;
    work.out[2] = depth;
    work.out[8] = (f32)colors[0];
    work.out[9] = (f32)colors[1];
    work.out[10] = (f32)colors[2];
    work.out[11] = (f32)colors[3];
    work.out[6] = inv;
    work.out[16] = 0.0f;
    work.out[17] = 448.0f;
    work.out[18] = depth;
    work.out[24] = (f32)colors[0];
    work.out[25] = (f32)colors[1];
    work.out[26] = (f32)colors[2];
    work.out[27] = (f32)colors[3];
    work.out[22] = inv;
    work.out[32] = 640.0f;
    work.out[33] = 0.0f;
    work.out[34] = depth;
    work.out[40] = (f32)colors[0];
    work.out[41] = (f32)colors[1];
    work.out[42] = (f32)colors[2];
    work.out[43] = (f32)colors[3];
    work.out[38] = inv;
    work.out[48] = 640.0f;
    work.out[49] = 448.0f;
    work.out[50] = depth;
    work.out[56] = (f32)colors[0];
    work.out[57] = (f32)colors[1];
    work.out[58] = (f32)colors[2];
    work.out[59] = (f32)colors[3];
    work.out[54] = inv;
    D_00887310[0](4, work.out, 4);
    if (enabled != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], work.saved[j]);
        }
    }
    return;
}


/* Multiplies the quaternions in vf10 and vf11, returning the product in vf10. */
// FUN_004BCE50
void effMiscQuatMultiplyVU(void)
{
    __asm__ volatile (
        ".set noreorder               \n"
        "vmul.xyzw vf2, vf10, vf11    \n"
        "vopmula.xyz ACC, vf10, vf11  \n"
        "vmaddaw.xyz ACC, vf11, vf10  \n"
        "vmaddaw.xyz ACC, vf10, vf11  \n"
        "vopmsub.xyz vf10, vf11, vf10 \n"
        "vmulaw.w ACC, vf10, vf11     \n"
        "vmsubax.w ACC, vf0, vf2      \n"
        "vmsubay.w ACC, vf0, vf2      \n"
        "vmsubz.w vf10, vf0, vf2      \n"
        ".set reorder"
        :
        :
        : "vf2", "ACC", "memory"
    );
}



/* Normalizes the four-component vector in vf10 using the VU reciprocal square root. */
// FUN_004BCE80
void effMiscNormalizeVU(void)
{
    __asm__ volatile (
        ".set noreorder            \n"
        "vmul.xyzw vf2, vf10, vf10 \n"
        "vaddax.w ACC, vf2, vf2    \n"
        "vmadday.w ACC, vf0, vf2   \n"
        "vmaddz.w vf3, vf0, vf2    \n"
        "vrsqrt Q, vf0w, vf3w      \n"
        "vwaitq                    \n"
        "vmulq.xyzw vf10, vf10, Q  \n"
        ".set reorder"
        :
        :
        : "vf2", "vf3", "ACC", "Q", "memory"
    );
}



// Builds a rotation basis in vf28 to vf31 from the quaternion in vf10 (VU0 asm body).
// FUN_004BCEB0
void effMiscBuildRotationVU(void)
{
    __asm__ volatile (
        ".set noreorder                              \n"
        "vaddw.xyz vf1, vf0, vf0w                    \n"
        "vadd.xyzw vf2, vf10, vf10                   \n"
        "vmulx.w vf28, vf0, vf0x                     \n"
        "vmulx.w vf29, vf0, vf0x                     \n"
        "vmulx.w vf30, vf0, vf0x                     \n"
        "vmul.xyzw vf3, vf10, vf2                    \n"
        "vmuly.xyzw vf4, vf10, vf2y                  \n"
        "vmulz.xyzw vf5, vf10, vf2z                  \n"
        "vmulx.xyzw vf6, vf10, vf2x                  \n"
        "vaddaw.xyz ACC, vf0, vf0w                   \n"
        "vmsubay.x ACC, vf1, vf3y                    \n"
        "vmsubz.x vf28, vf1, vf3z                    \n"
        "vmsubax.y ACC, vf1, vf3x                    \n"
        "vmsubz.y vf29, vf1, vf3z                    \n"
        "vmsubax.z ACC, vf1, vf3x                    \n"
        "vmsuby.z vf30, vf1, vf3y                    \n"
        "vmulax.y ACC, vf1, vf4x                     \n"
        "vmsubw.y vf28, vf1, vf5w                    \n"
        "vaddw.x vf29, vf4, vf5w                     \n"
        "vsubw.x vf30, vf5, vf4w                     \n"
        "vmulax.z ACC, vf1, vf5x                     \n"
        "vmaddw.z vf28, vf1, vf4w                    \n"
        "vmulay.z ACC, vf1, vf5y                     \n"
        "vmsubw.z vf29, vf1, vf6w                    \n"
        "vaddw.y vf30, vf5, vf6w                     \n"
        "vmove.xyzw vf31, vf0                        \n"
        ".set reorder"
        :
        :
        : "vf1", "vf2", "vf3", "vf4", "vf5", "vf6", "vf28", "vf29", "vf30", "vf31", "ACC", "memory"
    );
}



// Builds a quaternion from three angles (half-angle sines and cosines combined) and loads it into vf10.
// FUN_004BCF20
void effMiscEulerToQuatVU(f32 angleX, f32 angleY, f32 angleZ)
{
    RwV4d quaternion;
    f32 halfAngle;
    f32 cosY;
    f32 sinY;
    f32 cosZ;
    f32 cosX;
    f32 sinX;
    f32 sinZ;

    halfAngle = -angleX * 0.5f;
    cosX = cosf(halfAngle);
    sinX = sinf(halfAngle);
    halfAngle = -angleY * 0.5f;
    cosY = cosf(halfAngle);
    sinY = sinf(halfAngle);
    halfAngle = -angleZ * 0.5f;
    cosZ = cosf(halfAngle);
    sinZ = sinf(halfAngle);
    quaternion.x = cosX * (sinZ * sinY) + sinX * (cosZ * cosY);
    quaternion.y = cosX * (cosZ * sinY) - sinX * (sinZ * cosY);
    quaternion.z = cosX * (sinZ * cosY) + sinX * (cosZ * sinY);
    quaternion.w = cosX * (cosZ * cosY) - sinX * (sinZ * sinY);

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf10, 0(%0)        \n"
        ".set reorder"
        :
        : "r" (&quaternion)
        : "vf10", "memory"
    );
}



/* Advances the four-word XOR/shift generator; NULL selects the shared generator. */
// FUN_004BD050
u32 effMiscRand(EffRandState* state)
{
    u32 x0;
    u32 x1;
    u32 x2;
    u32 x3;
    u32 rand;

    if (state == NULL)
    {
        state = &sRandState;
    }

    x0 = state->x[0];
    x1 = state->x[1];
    x2 = state->x[2];
    x3 = state->x[3];

    rand = ((x1 << 0x02) | (((x0 >> 0x1e)) % 4)) ^ ((x3 << 0x01) | (((x2 >> 0x1f)) % 2));

    state->x[0] = rand;
    state->x[1] = x0;
    state->x[2] = x1;
    state->x[3] = x2;

    return rand;
}



// FUN_004BD0B0
f32 effMiscRandFloat(EffRandState* state)
{
    return (f32)(effMiscRand(state) & 0xFFFFFF) / 16777216.0f;
}



/* Expands the seed into four words using XOR constants and byte rotations. */
// FUN_004BD130
void effMiscRandInit(EffRandState* state, u32 seed)
{
    u32 x;

    if (state == NULL)
    {
        state = &sRandState;
    }

    x = seed ^ 0xAED1A0C;
    state->x[0] = x;

    x = (x << 0x18) | (x >> 0x08);
    state->x[1] = x;

    x = x ^ 0xAA5A02FE;
    x = (x << 0x18) | (x >> 0x08);
    state->x[2] = x;

    x = x ^ 0x11BE81C7;
    state->x[3] = (x << 0x18) | (x >> 0x08);
}



// Builds a rotation about X by angle into a matrix and loads its rows into vf28 to vf31.
// FUN_004BD1A0
void effMiscRotateXVU(f32 angle)
{
    RwMatrix matrix;
    f32 cosine;
    f32 sine;

    cosine = cosf(angle);
    sine = sinf(angle);

    __asm__ volatile (
        ".set noreorder          \n"
        "qmfc2.ni $5, $vf0       \n"
        "pextuw $4, $0, $5       \n"
        "pextuw $2, $0, $4       \n"
        "pextuw $3, $4, $0       \n"
        "sq $2, 0(%0)            \n"
        "sq $3, 16(%0)           \n"
        "sq $4, 32(%0)           \n"
        "sq $5, 48(%0)           \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "$2", "$3", "$4", "$5", "memory"
    );
    matrix.up.y = cosine;
    matrix.up.z = sine;
    matrix.at.y = -sine;
    matrix.at.z = cosine;

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf28, 0(%0)        \n"
        "lqc2 vf29, 16(%0)       \n"
        "lqc2 vf30, 32(%0)       \n"
        "lqc2 vf31, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf28", "vf29", "vf30", "vf31", "memory"
    );
}



// Writes the axis-angle rotation matrix for angle about the normalised axis into matrix; the axis is normalised through VU0 first and the pad words are zeroed.
// FUN_004BD230
void effMiscAxisAngleMatrix(f32 angle, const RwV3d* axis, RwMatrix* matrix)
{
    f32 xSquared;
    f32 ySquared;
    f32 zSquared;
    f32 xz;
    const RwV3d* axis_p;
    RwMatrix* matrix_p;
    f32 angle_p;
    RwV4d normalizedAxis;
    f32 cosine;
    f32 sine;
    f32 oneMinusCosine;
    f32 xy;
    f32 zSine;
    f32 x;
    f32 y;
    f32 z;

    angle_p = angle;
    axis_p = axis;
    matrix_p = matrix;
    cosine = cosf(angle_p);
    sine = sinf(angle_p);

    __asm__ volatile (
        ".set noreorder                              \n"
        "lqc2 vf10, 0(%0)                            \n"
        "vmul.xyz vf2, vf10, vf10                    \n"
        "vmulax.w ACC, vf0, vf2x                     \n"
        "vmadday.w ACC, vf0, vf2y                    \n"
        "vmaddz.w vf2, vf0, vf2z                    \n"
        "vrsqrt Q, vf0w, vf2w                       \n"
        "vwaitq                                      \n"
        "vmulq.xyz vf10, vf10, Q                    \n"
        ".set reorder"
        :
        : "r" (axis_p)
        : "vf2", "vf10", "ACC", "Q", "memory"
    );
    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf10, 0(%0)        \n"
        ".set reorder"
        :
        : "r" (&normalizedAxis)
        : "memory"
    );

    x = normalizedAxis.x;
    y = normalizedAxis.y;
    z = normalizedAxis.z;
    xSquared = x * x;
    matrix_p->right.x = xSquared + (1.0f - xSquared) * cosine;
    xy = x * y;
    oneMinusCosine = 1.0f - cosine;
    zSine = z * sine;
    xy = xy * oneMinusCosine;
    matrix_p->right.y = zSine + xy;
    xz = x * z;
    matrix_p->right.z = xz * (1.0f - cosine) - y * sine;
    matrix_p->flags = 0;

    matrix_p->up.x = xy - zSine;
    ySquared = y * y;
    matrix_p->up.y = ySquared + (1.0f - ySquared) * cosine;
    xSquared = y * z;
    ySquared = x * sine;
    matrix_p->up.z = ySquared + xSquared * (1.0f - cosine);
    matrix_p->pad1 = 0;

    matrix_p->at.x = y * sine + x * z * (1.0f - cosine);
    matrix_p->at.y = y * z * (1.0f - cosine) - x * sine;
    zSquared = z * z;
    matrix_p->at.z = zSquared + (1.0f - zSquared) * cosine;
    matrix_p->pad2 = 0;

    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf0, 0x30(%0)       \n"
        ".set reorder"
        :
        : "r" (matrix_p)
        : "memory"
    );
}
// Builds the axis-angle matrix for angle about axis and loads it into vf28 to vf31.
// FUN_004BD380
void effMiscAxisAngleVU(const RwV3d* axis, f32 angle)
{
    RwMatrix matrix;

    effMiscAxisAngleMatrix(angle, axis, &matrix);
    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf28, 0(%0)        \n"
        "lqc2 vf29, 16(%0)       \n"
        "lqc2 vf30, 32(%0)       \n"
        "lqc2 vf31, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf28", "vf29", "vf30", "vf31", "memory"
    );
}



// Builds a rotation about Y by angle and loads its rows into vf24 to vf27.
// FUN_004BD3C0
void effMiscRotateYVU(f32 angle)
{
    RwMatrix matrix;
    f32 cosine;
    f32 sine;

    cosine = cosf(angle);
    sine = sinf(angle);

    __asm__ volatile (
        ".set noreorder          \n"
        "qmfc2.ni $5, $vf0       \n"
        "pextuw $4, $0, $5       \n"
        "pextuw $2, $0, $4       \n"
        "pextuw $3, $4, $0       \n"
        "sq $2, 0(%0)            \n"
        "sq $3, 16(%0)           \n"
        "sq $4, 32(%0)           \n"
        "sq $5, 48(%0)           \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "$2", "$3", "$4", "$5", "memory"
    );
    matrix.right.x = cosine;
    matrix.right.z = -sine;
    matrix.at.x = sine;
    matrix.at.z = cosine;

    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf24, 0(%0)        \n"
        "lqc2 vf25, 16(%0)       \n"
        "lqc2 vf26, 32(%0)       \n"
        "lqc2 vf27, 48(%0)       \n"
        ".set reorder"
        :
        : "r" (&matrix)
        : "vf24", "vf25", "vf26", "vf27", "memory"
    );
}



// Multiplies the basis in vf28 to vf31 by the matrix in vf24 to vf27 (VU0 asm body).
// FUN_004BD450
void effMiscCombineRotationVU(void)
{
    __asm__ volatile (
        ".set noreorder                              \n"
        "vmulax.xyzw ACC, vf24, vf28x                \n"
        "vmadday.xyzw ACC, vf25, vf28y               \n"
        "vmaddaz.xyzw ACC, vf26, vf28z               \n"
        "vmaddw.xyzw vf28, vf27, vf28w               \n"
        "vmulax.xyzw ACC, vf24, vf29x                \n"
        "vmadday.xyzw ACC, vf25, vf29y               \n"
        "vmaddaz.xyzw ACC, vf26, vf29z               \n"
        "vmaddw.xyzw vf29, vf27, vf29w               \n"
        "vmulax.xyzw ACC, vf24, vf30x                \n"
        "vmadday.xyzw ACC, vf25, vf30y               \n"
        "vmaddaz.xyzw ACC, vf26, vf30z               \n"
        "vmaddw.xyzw vf30, vf27, vf30w               \n"
        "vmulax.xyzw ACC, vf24, vf31x                \n"
        "vmadday.xyzw ACC, vf25, vf31y               \n"
        "vmaddaz.xyzw ACC, vf26, vf31z               \n"
        "vmaddw.xyzw vf31, vf27, vf31w               \n"
        ".set reorder"
        :
        :
        : "vf28", "vf29", "vf30", "vf31", "ACC", "memory"
    );
}
