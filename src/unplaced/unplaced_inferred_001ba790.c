/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001ba790-001ba790 */

#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"
#include "operand_order_internal.h"
#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
extern void mdlBlendTranslationRotation(f32 *result, f32 *from, f32 *to, f32 blend);
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern void func_003dcc70(f32 *result, f32 *from, f32 *to);
#include "btl_camera_sequence_internal.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
/* Blend translation and slerp the following quaternion independently.
 * Translation extrapolates, while rotation copies an endpoint outside [0, 1].
 * The sine polynomial and scalar evaluation order mirror the quaternion macros. */
// FUN_001BA790
void mdlBlendTranslationRotation(f32 *result, f32 *from, f32 *to, f32 blend)
{
    struct MdlTransformSlerpCache {
        f32 fromX;
        f32 fromY;
        f32 fromZ;
        f32 fromW;
        f32 toX;
        f32 toY;
        f32 toZ;
        f32 toW;
        f32 omega;
        s32 linear;
    } cache;
    f32 fromWeight;
    f32 angle;
    f32 angleSquared;
    f32 polynomial;
    f32 component;
    f32 fromZWeighted;
    f32 fromYWeighted;

    fromWeight = 1.0f - blend;
    fromYWeighted = from[1] * fromWeight;
    fromZWeighted = from[2] * fromWeight;
    component = to[1] * blend;
    polynomial = to[2] * blend;
    result[0] = (from[0] * fromWeight) + (to[0] * blend);
    result[1] = fromYWeighted + component;
    result[2] = fromZWeighted + polynomial;
    func_003dcc70(from + 3, to + 3, &cache.fromX);
    if (blend <= 0.0f) {
        component = from[3];
        polynomial = from[4];
        angleSquared = from[5];
        angle = from[6];
        result[3] = component;
        result[4] = polynomial;
        result[5] = angleSquared;
        result[6] = angle;
        goto done;
    }
    if (1.0f <= blend) {
        component = to[3];
        polynomial = to[4];
        angleSquared = to[5];
        angle = to[6];
        result[3] = component;
        result[4] = polynomial;
        result[5] = angleSquared;
        result[6] = angle;
        goto done;
    }
    if (cache.linear == 0) {
        angle = fromWeight * cache.omega;
        angleSquared = angle * angle;
        polynomial = fGpffff8104 * angleSquared + fGpffff8054;
        polynomial = angleSquared * polynomial + fGpffff8058;
        polynomial = angleSquared * polynomial + fGpffff805c;
        polynomial = angleSquared * polynomial + fGpffff8060;
        polynomial = angleSquared * polynomial + fGpffff8108;
        fromWeight = angle + operandOrderMultiply(angleSquared * angle, polynomial);
        angle = blend * cache.omega;
        angleSquared = angle * angle;
        polynomial = fGpffff8104 * angleSquared + fGpffff8054;
        polynomial = angleSquared * polynomial + fGpffff8058;
        polynomial = angleSquared * polynomial + fGpffff805c;
        polynomial = angleSquared * polynomial + fGpffff8060;
        polynomial = angleSquared * polynomial + fGpffff8108;
        blend = angle + operandOrderMultiply(angleSquared * angle, polynomial);
    }
    result[3] = cache.fromX * fromWeight;
    result[4] = cache.fromY * fromWeight;
    result[5] = cache.fromZ * fromWeight;
    result[3] = cache.toX * blend + result[3];
    result[4] = cache.toY * blend + result[4];
    result[5] = cache.toZ * blend + result[5];
    result[6] = cache.fromW * fromWeight + cache.toW * blend;
done:
    ;
}
#pragma pop
