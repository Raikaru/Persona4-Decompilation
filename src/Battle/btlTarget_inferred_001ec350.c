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
extern f32 sqrtf(f32 arg0);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001ec350-001ec350 */

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
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
// FUN_001EC350
f32 func_001ec350(f32 *arg0, f32 *arg1)
{
    f32 zero;
    f32 length;

    zero = 0.0f;
    length = sqrtf(
        arg0[0] * arg0[0] +
        arg0[1] * arg0[1] +
        arg0[2] * arg0[2] +
        arg0[3] * arg0[3]);
    if (zero != length) {
        arg1[0] = arg0[0] / length;
        arg1[1] = arg0[1] / length;
        arg1[2] = arg0[2] / length;
        arg1[3] = arg0[3] / length;
    }
    return length;
}

