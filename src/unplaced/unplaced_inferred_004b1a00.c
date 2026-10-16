/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 004b1a00-004b1a00 */

#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void func_004b1a00(u8 *arg0, u8 *arg1);
extern s32 func_00481e30(s32 arg0);
extern void func_00481ee0(s32 arg0);
extern void TlpRelease(s32 arg0);
extern s32 TlpAddRef(s32 arg0);
// FUN_004B1A00
void func_004b1a00(u8 *arg0, u8 *arg1) {
    s32 temp_4;
    s32 temp_4_2;

    if (*(s32 *)(arg1 + 0xAC) != 0) {
        temp_4 = *(s32 *)(arg0 + 0xAC);
        if (temp_4 != 0) {
            func_00481ee0(temp_4);
        }
        *(s32 *)(arg0 + 0xAC) = func_00481e30(*(s32 *)(arg1 + 0xAC));
        return;
    }
    if (*(s32 *)(arg1 + 0xA8) != 0) {
        temp_4_2 = *(s32 *)(arg0 + 0xA8);
        if (temp_4_2 != 0) {
            TlpRelease(temp_4_2);
        }
        *(s32 *)(arg0 + 0xA8) = TlpAddRef(*(s32 *)(arg1 + 0xA8));
    }
}
