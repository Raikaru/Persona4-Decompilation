#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *btlTargetOffsetAddress(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;





extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 D_00609E40[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001ed060-001ed060 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern void btlTargetInitSpring(u8 *, f32);
#pragma push
#pragma pop
/* measured probe: preserve the retail filter branch chain */
#pragma push
/* measured probe: close the filter branch chain */
#pragma pop
/* measured probe: preserve retail conditional branch shape */
#pragma push
/* measured probe: close conditional branch shape */
#pragma pop
/* measured: optimization_level 1 probe for retail GP-load scheduling. */
/* measured: close optimization_level 1 probe for btlAiGetGlobal. */
/* measured: opt_propagation off probe for e320 GP-load order. */
/* measured: closes opt_propagation probe for btlAiSetGlobal. */
/* 1468/1472 bytes; all four call relocations resolve exactly. */
/* measured: third 001ec5e0 probe tests opt_propagation off for FPU-zero placement. */
/* measured: closes opt_propagation probe for btlTargetInitSpring. */
// FUN_001ED060
/* Reject obstacle-edge crossings and active corner-link crossings; shared endpoints are exempt. */
int btlTargetCheckObstacleCrossings(float *first, float *second)
{
    u8 *node;
    int i;

    if ((u8 *)((BtlTargetCorner *)second)->link == (u8 *)first)
    {
        return 1;
    }

    for (node = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles); node != NULL; node = (u8 *)(((BtlTargetObstacle *)node)->next))
    {
        for (i = 0; i < 4; ++i)
        {
            int wrap = (i + 1) & 3;
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next;

            if ((edge == first) || (edge == second))
            {
                continue;
            }
            next = (float *)(node + wrap * 0x130 + 0x08);
            if ((next == first) || (next == second))
            {
                continue;
            }
            else
            {
                int intersects;
                int firstSide = btlTargetCheckSide(edge, next, first);
                int secondSide = btlTargetCheckSide(edge, next, second);
                if (firstSide != secondSide)
                {
                    firstSide = btlTargetCheckSide(first, second, edge);
                    secondSide = btlTargetCheckSide(first, second, next);
                    if (firstSide != secondSide)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }

    {
        u8 *record;
        float *next;
        float *edge;
        u8 *node2;
        int j;
        for (node2 = (u8 *)(((BtlTargetNavigation *)(iGpffffb3ac + 0x318))->obstacles); node2 != NULL; node2 = (u8 *)(((BtlTargetObstacle *)node2)->next))
        for (j = 0; j < 4; ++j)
        {
            record = node2 + j * 0x130;
            edge = (float *)(record + 0x08);

            if (edge == first)
            {
                return 0;
            }
            if ((float)(((BtlTargetObstacle *)record)->corners[0].linkDistance) <= 0.0f)
            {
                continue;
            }
            next = (float *)(((BtlTargetObstacle *)record)->corners[0].link);
            if (next != NULL)
            {
                int intersects;
                int firstSide = btlTargetCheckSide(edge, next, first);
                int secondSide = btlTargetCheckSide(edge, next, second);
                if (firstSide != secondSide)
                {
                    firstSide = btlTargetCheckSide(first, second, edge);
                    secondSide = btlTargetCheckSide(first, second, next);
                    if (firstSide != secondSide)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

