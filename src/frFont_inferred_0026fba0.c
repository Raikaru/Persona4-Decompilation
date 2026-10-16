/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/frFont.c); members 0026fba0-0026fca0 */

#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern s64 datPersonaNamePart0(s32 arg0);
extern s64 datPersonaNamePart1(s32 arg0);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern void frFontUpdateTextWork(u8 *arg0);
extern u8 iGpffffa734;
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_common_subs on
#pragma opt_loop_invariants off
// Left func_: three text setters with one shape (frFontGetMode guard, sprintf of a DAT word from datPersonaNamePart0 or datPersonaNamePart1 at index 1, then frFontLayoutText). Their addresses are entries 0-2 of a function-pointer table at VA 0x63B994 in the retail data, and no source file names that table, so the owner of the index is not established and the words stay unnamed. [inferred]
// FUN_0026FBA0
s32 func_0026fba0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, datPersonaNamePart0(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_common_subs on
#pragma opt_loop_invariants off
// FUN_0026FC20
s32 func_0026fc20(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, datPersonaNamePart1(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_common_subs on
#pragma opt_loop_invariants off
// FUN_0026FCA0
s32 func_0026fca0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x23];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, datPersonaNamePart1(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    sp20[0] = -0x7D;
    sp20[1] = -0xA;
    sp20[2] = 0;
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    sprintf((char *)sp20, (const char *)&iGpffffa734, datPersonaNamePart0(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
#pragma pop
