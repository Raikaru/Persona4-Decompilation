
#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"

/* Unit settings: propagation and common subexpressions on; loop invariants off. */
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_loop_invariants off

extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern s64 datPersonaNamePart0(s32 unitId);
extern s64 datPersonaNamePart1(s32 unitId);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern void frFontUpdateTextWork(u8 *context);
extern u8 iGpffffa734;
#pragma push
#pragma optimization_level 2
// Formats the first persona name part at index 1 into the active text context; one of three setters
// listed in an unnamed function-pointer table.
// FUN_0026FBA0
s32 frFontAppendFirstPersonaNamePart(s32 unusedCommand, u8 *context)
{
    s8 textBuffer[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)textBuffer, (const char *)&iGpffffa734, datPersonaNamePart0(1));
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)textBuffer, context);
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Format the second name part at index one into the active text context. */
// FUN_0026FC20
s32 frFontAppendSecondPersonaNamePart(s32 unusedCommand, u8 *context)
{
    s8 textBuffer[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)textBuffer, (const char *)&iGpffffa734, datPersonaNamePart1(1));
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)textBuffer, context);
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Append second and first name parts separated by the encoded spacing glyph. */
// FUN_0026FCA0
s32 frFontAppendJoinedPersonaNameParts(s32 unusedCommand, u8 *context)
{
    s8 textBuffer[0x23];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)textBuffer, (const char *)&iGpffffa734, datPersonaNamePart1(1));
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)textBuffer, context);
    textBuffer[0] = -0x7D;
    textBuffer[1] = -0xA;
    textBuffer[2] = 0;
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)textBuffer, context);
    sprintf((char *)textBuffer, (const char *)&iGpffffa734, datPersonaNamePart0(1));
    frFontUpdateTextWork(context);
    frFontLayoutText((u8 *)textBuffer, context);
    return 0;
}
#pragma pop
