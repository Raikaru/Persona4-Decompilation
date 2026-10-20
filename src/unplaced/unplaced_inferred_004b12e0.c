/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 004b12e0-004b12e0 */

#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void func_004861f0(void *effect, f32 *matrix);
extern void func_00486330(u8 *effect, void *matrix);
extern void effMiscMatrixToQuatVU(f32 *matrix);
/* Set effect translation and derive its quaternion from the supplied RenderWare matrix. */
/* Set effect translation and derive its quaternion from a RenderWare matrix. */
/* measured: typing the post-callback translation reloads changes scheduling (normalized_diff 134/135/137); keep those three loads raw. */
// FUN_004B12E0
void mdlEffectSetMatrixPose(u8 *effect, u8 *matrix) {
    struct {
        f32 first[4];
        u8 result[16];
        f32 values[16];
    } work;

    work.first[0] = ((BtlShuffleMatrix *)matrix)->pos.x;
    work.first[1] = ((BtlShuffleMatrix *)matrix)->pos.y;
    work.first[2] = ((BtlShuffleMatrix *)matrix)->pos.z;
    work.first[3] = 0.0f;
    func_004861f0((void *)effect, work.first);
    work.values[0] = ((BtlShuffleMatrix *)matrix)->right.x;
    work.values[1] = ((BtlShuffleMatrix *)matrix)->right.y;
    work.values[2] = ((BtlShuffleMatrix *)matrix)->right.z;
    work.values[3] = 0.0f;
    work.values[4] = ((BtlShuffleMatrix *)matrix)->up.x;
    work.values[5] = ((BtlShuffleMatrix *)matrix)->up.y;
    work.values[6] = ((BtlShuffleMatrix *)matrix)->up.z;
    work.values[7] = 0.0f;
    work.values[8] = ((BtlShuffleMatrix *)matrix)->at.x;
    work.values[9] = ((BtlShuffleMatrix *)matrix)->at.y;
    work.values[10] = ((BtlShuffleMatrix *)matrix)->at.z;
    work.values[11] = 0.0f;
    work.values[12] = *(f32 *)(matrix + 0x30);
    work.values[13] = *(f32 *)(matrix + 0x34);
    work.values[14] = *(f32 *)(matrix + 0x38);
    work.values[15] = 0.0f;
    effMiscMatrixToQuatVU(work.values);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(work.result) : "memory");
    func_00486330(effect, work.result);
}
