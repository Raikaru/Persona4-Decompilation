#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern void *D_00609850[];
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
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
extern void btlTargetInitSpring(u8 *arg0, f32 arg1);
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
int func_001ed060(float *param_1, float *param_2)
{
    u8 *node;
    int i;

    if (*(u8 **)((u8 *)param_2 + 0x10) == (u8 *)param_1)
    {
        return 1;
    }

    for (node = *(u8 **)(iGpffffb3ac + 0x318); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            int wrap = (i + 1) & 3;
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next;

            if ((edge == param_1) || (edge == param_2))
            {
                continue;
            }
            next = (float *)(node + wrap * 0x130 + 0x08);
            if ((next == param_1) || (next == param_2))
            {
                continue;
            }
            else
            {
                int intersects;
                int side_a = btlTargetCheckSide(edge, next, param_1);
                int side_b = btlTargetCheckSide(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = btlTargetCheckSide(param_1, param_2, edge);
                    side_b = btlTargetCheckSide(param_1, param_2, next);
                    if (side_a != side_b)
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
        for (node2 = *(u8 **)(iGpffffb3ac + 0x318); node2 != NULL; node2 = *(u8 **)(node2 + 0x4cc))
        for (j = 0; j < 4; ++j)
        {
            record = node2 + j * 0x130;
            edge = (float *)(record + 0x08);

            if (edge == param_1)
            {
                return 0;
            }
            if (*(float *)(record + 0x1c) <= 0.0f)
            {
                continue;
            }
            next = *(float **)(record + 0x18);
            if (next != NULL)
            {
                int intersects;
                int side_a = btlTargetCheckSide(edge, next, param_1);
                int side_b = btlTargetCheckSide(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = btlTargetCheckSide(param_1, param_2, edge);
                    side_b = btlTargetCheckSide(param_1, param_2, next);
                    if (side_a != side_b)
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

