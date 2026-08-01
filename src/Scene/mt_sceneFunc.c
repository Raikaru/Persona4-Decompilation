/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_002692D0)
/* Source unit: src/Scene/mt_sceneFunc_002692d0.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b89f0 (verified MATCH
 * there). 003b5d10 -> func_00145270, 003b88c0 -> func_00269190. */

typedef struct Resrc Resrc;

extern u32 func_00145270(void);
extern u32 func_00269190(Resrc* param_1, u32 param_2, float param_3, u32 param_4);

// FUN_002692D0
u32 func_002692d0(u32 param_1, u32 param_2, float param_3, u32 param_4)
{
    u32 lVar1;
    u32 uVar2;

    lVar1 = func_00145270();
    if (lVar1 != 0)
    {
        uVar2 = func_00269190((Resrc*)lVar1, param_2, param_3, param_4);
    }
    else
    {
        uVar2 = 0;
    }
    return uVar2;
}
#endif /* P4_UNIT_002692D0 */

#if defined(P4_UNIT_00269620)
/* Source unit: src/Scene/mt_sceneFunc_00269620.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b8e10 (verified MATCH
 * there). 003b5d10 -> func_00145270, 003b8ce0 -> func_002694f0. */

extern u32 func_00145270(void);
extern u64 func_002694f0(u32 param_1, u64 param_2, u64 param_3, u64 param_4);

// FUN_00269620
u64 func_00269620(u64 param_1, u64 param_2, u64 param_3, u64 param_4)
{
    u32 lVar1;
    u64 uVar2;

    lVar1 = func_00145270();
    if (lVar1 != 0)
    {
        uVar2 = func_002694f0(lVar1, param_2, param_3, param_4);
    }
    else
    {
        uVar2 = 0;
    }
    return uVar2;
}
#endif /* P4_UNIT_00269620 */

#if defined(P4_UNIT_0026C680)
/* Source unit: src/Scene/mt_sceneFunc_0026c680.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bb9b0 (verified MATCH there). */
#pragma push
/* Removing this loses FUN_003bb9b0 (MATCH nd0 -> MISMATCH nd143) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0026C680
void func_0026c680(float *param_1)
{
    int iVar2;
    float afStack_10 [4];

    afStack_10[0] = *param_1;
    afStack_10[1] = param_1[1];
    afStack_10[2] = param_1[2];
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
        while (afStack_10[iVar2] >= 360.0f) {
            afStack_10[iVar2] = afStack_10[iVar2] - 360.0f;
        }
        while (afStack_10[iVar2] < 0.0f) {
            afStack_10[iVar2] = afStack_10[iVar2] + 360.0f;
        }
    }

    *param_1 = afStack_10[0];
    param_1[1] = afStack_10[1];
    param_1[2] = afStack_10[2];
    return;
}
#pragma pop
#endif /* P4_UNIT_0026C680 */

#if defined(P4_UNIT_0026C770)
/* Source unit: src/Scene/mt_sceneFunc_0026c770.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbaa0 (verified MATCH
 * there). 003bb9b0 -> func_0026c680. */

extern void func_0026c680(float *param_1);

#pragma push
/* opt_loop_invariants on: measured off nd 95, object 236/240; on nd 0, object 228/240 (MATCH); retain on. */
#pragma opt_loop_invariants on
// FUN_0026C770
void func_0026c770(float *param_1, float *param_2, float *param_3)
{
    int iVar1;
    float delta[4];
    float adjusted[4];
    const float wrap = 360.0f;
    const float limit = 180.0f;

    delta[0] = param_2[0] - param_1[0];
    delta[1] = param_2[1] - param_1[1];
    delta[2] = param_2[2] - param_1[2];
    func_0026c680(delta);
    adjusted[0] = delta[0];
    adjusted[1] = delta[1];
    adjusted[2] = delta[2];
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
        if (adjusted[iVar1] <= limit) {
            continue;
        }
        adjusted[iVar1] = -(wrap - adjusted[iVar1]);
    }
    param_3[0] = adjusted[0];
    param_3[1] = adjusted[1];
    param_3[2] = adjusted[2];
}
#pragma pop
#endif /* P4_UNIT_0026C770 */

#if defined(P4_UNIT_0026C960)
/* Source unit: src/Scene/mt_sceneFunc_0026c960.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbc90 (verified MATCH there). */

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// FUN_0026C960
void func_0026c960(float t, float *x, float *y, float *z, float *outX,
                   float *outY, float *outZ)
{
    float oneMinus = 1.0f - t;
    float oneMinusSquared = oneMinus * oneMinus;
    float w0;
    float w1;
    float w2;
    float w3;
    float tSquared;
    float rx;

    RwV3d result;
    w0 = oneMinus * oneMinusSquared;
    rx = x[0] * w0;
    w1 = t * (3.0f * oneMinusSquared);
    rx += x[1] * w1;
    tSquared = t * t;
    w2 = (3.0f * oneMinus) * tSquared;
    rx += x[2] * w2;
    w3 = t * tSquared;
    rx += x[3] * w3;
    result.x = rx;
    rx = y[0] * w0;
    rx += y[1] * w1;
    rx += y[2] * w2;
    rx += y[3] * w3;
    result.y = rx;
    rx = z[0] * w0;
    rx += z[1] * w1;
    rx += z[2] * w2;
    rx += z[3] * w3;
    result.z = rx;

    *outX = result.x;
    *outY = result.y;
    *outZ = result.z;
}
#endif /* P4_UNIT_0026C960 */

#if defined(P4_UNIT_0026CA10)
/* Source unit: src/Scene/mt_sceneFunc_0026ca10.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbd40 (verified MATCH
 * there). 003bbc90 -> func_0026c960. */

extern void func_0026c960(float param_1, ...);

/* opt_lifetimes on: measured nd 62 -> 0, object 400/400 -> 400/400. */
#pragma opt_lifetimes on
// FUN_0026CA10
void func_0026ca10(float param_1, char *param_2, float *param_3)
{
    char cVar1;
    int iVar2;
    int segmentIndex;
    int iVar3;
    float fVar5;
    float auStack_10 [4];
    float auStack_20 [4];
    float auStack_30 [4];

    cVar1 = *param_2;
    if ('\0' < cVar1) {
        if (!(param_1 < 1.0f)) {
            iVar3 = 0;
            segmentIndex = cVar1 - 1;
            param_2 += segmentIndex * 0x24;
            for (; iVar3 < 4; iVar3 = iVar3 + 1) {
                iVar2 = iVar3 * 0xc;
                auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);
                auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);
                auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);
            }
            func_0026c960(1.0f, auStack_10, auStack_20, auStack_30, param_3, param_3 + 1, param_3 + 2);
        }
        else {
            fVar5 = 1.0f / (float)(int)cVar1;
            segmentIndex = (int)(param_1 / fVar5);
            iVar3 = 0;
            param_2 += segmentIndex * 0x24;
            for (; iVar3 < 4; iVar3 = iVar3 + 1) {
                iVar2 = iVar3 * 0xc;
                auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);
                auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);
                auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);
            }
            while (param_1 > fVar5) {
                param_1 = param_1 - fVar5;
            }
            func_0026c960(param_1 / fVar5, auStack_10, auStack_20, auStack_30, param_3, param_3 + 1, param_3 + 2);
        }
    }
    return;
}
#pragma opt_lifetimes off
#endif /* P4_UNIT_0026CA10 */

#if defined(P4_UNIT_0026CCA0)
/* Source unit: src/Scene/mt_sceneFunc_0026cca0.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbfd0 (verified MATCH
 * there). 003bbc90 -> func_0026c960, 004c6ac0 -> func_003e4180. */

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern void func_0026c960(float param_1, ...);
extern f32 func_003e4180(const RwV3d *vector);

// FUN_0026CCA0
float func_0026cca0(float param_1, float param_2, float *param_3, float *param_4,
                    float *param_5, float *param_6, float *param_7)
{
    RwV3d delta;
    float first_x;
    float second_x;
    float first_y;
    float second_y;
    float first_z;
    float second_z;
    float first_len;

    func_0026c960(param_1, param_3, param_4, param_5, &first_x, &first_y, &first_z);
    func_0026c960(param_2, param_3, param_4, param_5, &second_x, &second_y, &second_z);
    delta.x = second_x - first_x;
    delta.y = second_y - first_y;
    delta.z = second_z - first_z;
    first_len = func_003e4180(&delta);
    *param_6 = first_x;
    param_6[1] = first_y;
    param_6[2] = first_z;
    *param_7 = second_x;
    param_7[1] = second_y;
    param_7[2] = second_z;
    return first_len;
}
#endif /* P4_UNIT_0026CCA0 */

#if defined(P4_UNIT_0026CDB0)
/* Source unit: src/Scene/mt_sceneFunc_0026cdb0.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bc0e0 (verified MATCH
 * there). 007cb0b8 -> D_007614c0, 003bbfd0 -> func_0026cca0. */

extern f32 D_007614c0;
extern float func_0026cca0(float param_1, float param_2, ...);

// FUN_0026CDB0
float func_0026cdb0(char *param_1)
{
    int iVar1;
    int lVar2;
    int iVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float scale;
    float auStack_10 [4];
    float auStack_20 [4];
    float auStack_30 [4];
    float auStack_40 [4];
    float auStack_50 [4];

    fVar5 = 0.0f;
    for (lVar2 = 0; lVar2 < *param_1; lVar2 = lVar2 + 1) {
        {
            char *curve;
            int copyIndex;

            copyIndex = 0;
            curve = param_1 + lVar2 * 0x24;
            for (; copyIndex < 4; copyIndex = copyIndex + 1) {
                iVar1 = copyIndex * 0xc;
                auStack_30[copyIndex] = *(float *)(curve + iVar1 + 4);
                auStack_40[copyIndex] = *(float *)(curve + iVar1 + 8);
                auStack_50[copyIndex] = *(float *)(curve + iVar1 + 0xc);
            }
        }

        fVar6 = 0.0f;
        for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {
            fVar4 = (float)iVar3;
            scale = D_007614c0;
            fVar4 = fVar4 * scale;
            fVar4 = func_0026cca0(fVar4, (float)(iVar3 + 1) * scale,
                                  auStack_30, auStack_40, auStack_50, auStack_10, auStack_20);
            fVar6 = fVar6 + fVar4;
        }
        fVar5 = fVar5 + fVar6;
    }
    return fVar5;
}
#endif /* P4_UNIT_0026CDB0 */

#if defined(P4_UNIT_0026D810)
/* Source unit: src/Scene/mt_sceneFunc_0026d810.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bcc80 (verified MATCH
 * there). 007ce658 -> D_00764580, 003500e0 -> func_004b15d0. */

extern u16 D_00764580;
extern void func_004b15d0(void);

// FUN_0026D810
void func_0026d810(void)
{
    *(u16 *)&D_00764580 = 0;
    func_004b15d0();
    return;
}
#endif /* P4_UNIT_0026D810 */
