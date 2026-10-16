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
#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}

extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern void func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);
#include "btl_camera_sequence_internal.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// FUN_001BA790
void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0)
{
    struct Ba790Local {
        f32 f50;
        f32 f54;
        f32 f58;
        f32 f5C;
        f32 f60;
        f32 f64;
        f32 f68;
        f32 f6C;
        f32 f70;
        s32 flag;
    } local;
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    var_f20 = 1.0f - fparg0;
    temp_f5 = arg1[1] * var_f20;
    temp_f4 = arg1[2] * var_f20;
    temp_f3 = arg2[1] * fparg0;
    temp_f2 = arg2[2] * fparg0;
    arg0[0] = (arg1[0] * var_f20) + (arg2[0] * fparg0);
    arg0[1] = temp_f5 + temp_f3;
    arg0[2] = temp_f4 + temp_f2;
    func_003dcc70(arg1 + 3, arg2 + 3, &local.f50);
    if (fparg0 <= 0.0f) {
        temp_f3 = arg1[3];
        temp_f2 = arg1[4];
        temp_f1 = arg1[5];
        temp_f0 = arg1[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (1.0f <= fparg0) {
        temp_f3 = arg2[3];
        temp_f2 = arg2[4];
        temp_f1 = arg2[5];
        temp_f0 = arg2[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (local.flag == 0) {
        temp_f0 = var_f20 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        var_f20 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
        temp_f0 = fparg0 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        fparg0 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
    }
    arg0[3] = local.f50 * var_f20;
    arg0[4] = local.f54 * var_f20;
    arg0[5] = local.f58 * var_f20;
    arg0[3] = local.f60 * fparg0 + arg0[3];
    arg0[4] = local.f64 * fparg0 + arg0[4];
    arg0[5] = local.f68 * fparg0 + arg0[5];
    arg0[6] = local.f5C * var_f20 + local.f6C * fparg0;
done:
    ;
}
#pragma pop
