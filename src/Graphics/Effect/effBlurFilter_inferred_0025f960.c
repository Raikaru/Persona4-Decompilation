/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Graphics/Effect/effBlurFilter.c); members 0025f960-0025fa30 */

#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern u32 kwlnTaskGetWork(void *task);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 TnGetTableBase(void);
extern void TnSetTableBase(s32 arg0);
#pragma push
#pragma opt_propagation on
// Intent: Task update for a blur filter task: advances the direct or copied blur filter and syncs it [inferred]
// FUN_0025F960
s32 effBlurFilterTaskUpdate(u8 *task) {
    s32 var_17;
    s32 *p;
    s32 temp_3;

    p = (s32 *)kwlnTaskGetWork(task);
    if (p[4] != 0) {
        var_17 = TnGetTableBase();
        TnSetTableBase(p[4]);
    }
    temp_3 = p[0];
    switch (temp_3) {
    case 0:
        effBlurFilterDirectAdvanceAndSync((u8 *)p[1]);
        p[2] = p[2] + 1;
        break;
    case 1:
        effBlurFilterCopiedAdvanceAndSync((u8 *)p[1]);
        p[2] = p[2] + 1;
        break;
    }
    if (p[4] != 0) {
        TnSetTableBase(var_17);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Task destroy for a blur filter task: destroys the direct or copied blur filter, then frees the work block [inferred]
// FUN_0025FA30
void effBlurFilterTaskDestroy(u8 *task)
{
    s32 *temp_2;
    s32 temp_3;

    temp_2 = (s32 *)kwlnTaskGetWork(task);
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        effBlurFilterDirectDestroy((void *)temp_2[1]);
        break;
    case 1:
        effBlurFilterCopiedDestroy((void *)temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}
#pragma pop
