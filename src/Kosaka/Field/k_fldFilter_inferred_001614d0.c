/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Kosaka/Field/k_fldFilter.c; members 001614d0-001615a0 */

#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "field_frame_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
extern s32 iGpffff9ef8;
extern s32 iGpffff9f08;
extern void strcpy(void *arg0, const char *arg1);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 H_Cdvd_FileExists(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *H_Cdvd_AcquireDirectory(void *arg0, s32 arg1);
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern void memcpy(void *dst, void *src, u32 size);
extern void H_Cdvd_Destroy(void *arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern s32 iGpffff9f08;
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001614D0
s32 FldFilterGetEntry(void)
{
    return *(s32 *)(iGpffffb2b0 + iGpffffb2b8 * 0x124);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00161500
void FldFilterSetIndex(s32 arg0)
{
    iGpffff9ef8 = arg0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00161510
s32 FldEnemyOpenTable(void)
{
    char sp90[0x80];
    char sp10[0x80];

    strcpy(sp90, D_005F1218);
    sprintf(sp10, D_005F1230);
    if (H_Cdvd_FileExists(sp10) == 0) {
        return 0;
    }
    func_00440b68((char *)&iGpffff9f08, D_005F1248, 0x69);
    return (s32)H_Cdvd_AcquireDirectory(sp10, 0);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
// FUN_001615A0
s32 FldEnemyLoadTable(u8 *arg0)
{
    void *src;
    u32 size;

    if (arg0 == NULL) {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded(arg0) == 0) {
        return 0;
    }
    iGpffffb2c8 = D_007E7B20;
    size = *(u32 *)(arg0 + 0x118);
    src = *(void **)(((u8 *)arg0 + size) - size + 0x110);
    memcpy(iGpffffb2c8, src, size);
    iGpffffb2cc = iGpffffb2c8 + 0x300;
    H_Cdvd_Destroy(arg0);
    return 1;
}
#pragma pop
