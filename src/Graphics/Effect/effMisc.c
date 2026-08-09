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

extern void func_004bd230(const RwV3d* axis, RwMatrix* matrix, f32 angle);



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



// FUN_004BCEB0
void func_004bceb0(void)
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



// FUN_004BCF20
void func_004bcf20(f32 angleX, f32 angleY, f32 angleZ)
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



// FUN_004BD1A0
void func_004bd1a0(f32 angle)
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



// FUN_004BD230
INCLUDE_ASM("asm/nonmatchings/effMisc", func_004bd230);
// FUN_004BD380
void func_004bd380(const RwV3d* axis, f32 angle)
{
    RwMatrix matrix;

    func_004bd230(axis, &matrix, angle);
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



// FUN_004BD3C0
void func_004bd3c0(f32 angle)
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



// FUN_004BD450
void func_004bd450(void)
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
