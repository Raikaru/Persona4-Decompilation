/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 004b18e0-004b18e0 */

#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
extern void func_00481ee0(s32 arg0);
extern void TlpRelease(s32 arg0);
extern void (*jtbl_008873EC[])(void *);
// FUN_004B18E0
void func_004b18e0(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0xA8);
    if (h != 0) {
        TlpRelease(h);
    }
    h = *(s32 *)(arg0 + 0xAC);
    if (h != 0) {
        func_00481ee0(h);
    }
    GeometryBlockDestroy(*(s32 *)(arg0 + 0xA4));
    (*jtbl_008873EC)(arg0);
}
