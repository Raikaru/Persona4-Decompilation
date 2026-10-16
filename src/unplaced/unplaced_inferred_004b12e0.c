/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 004b12e0-004b12e0 */

#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void func_004861f0(void *arg0, f32 *arg1);
extern void func_00486330(u8 *arg0, void *arg1);
extern void effMiscMatrixToQuatVU(f32 *arg0);
// FUN_004B12E0
void func_004b12e0(u8 *arg0, u8 *arg1) {
    struct {
        f32 first[4];
        u8 result[16];
        f32 values[16];
    } work;

    work.first[0] = *(f32 *)(arg1 + 0x30);
    work.first[1] = *(f32 *)(arg1 + 0x34);
    work.first[2] = *(f32 *)(arg1 + 0x38);
    work.first[3] = 0.0f;
    func_004861f0((void *)arg0, work.first);
    work.values[0] = *(f32 *)(arg1 + 0);
    work.values[1] = *(f32 *)(arg1 + 4);
    work.values[2] = *(f32 *)(arg1 + 8);
    work.values[3] = 0.0f;
    work.values[4] = *(f32 *)(arg1 + 0x10);
    work.values[5] = *(f32 *)(arg1 + 0x14);
    work.values[6] = *(f32 *)(arg1 + 0x18);
    work.values[7] = 0.0f;
    work.values[8] = *(f32 *)(arg1 + 0x20);
    work.values[9] = *(f32 *)(arg1 + 0x24);
    work.values[10] = *(f32 *)(arg1 + 0x28);
    work.values[11] = 0.0f;
    work.values[12] = *(f32 *)(arg1 + 0x30);
    work.values[13] = *(f32 *)(arg1 + 0x34);
    work.values[14] = *(f32 *)(arg1 + 0x38);
    work.values[15] = 0.0f;
    effMiscMatrixToQuatVU(work.values);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(work.result) : "memory");
    func_00486330(arg0, work.result);
}
