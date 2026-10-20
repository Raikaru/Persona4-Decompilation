/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/itfMesManager.c); members 0027b7c0-0027be00 */

#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 itfMesWindowSendRowTransitionEnter(s32 handle);
extern s32 itfMesWindowSendRowTransitionActive(s32 handle);
extern s32 itfMesWindowSendRowTransitionLeave(s32 handle);
/* Unit settings shared by every message-procedure dispatch wrapper. */
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Send op 0 before building a newly bound text row; absent handlers return completion. */
// FUN_0027B7C0
s32 itfMesWindowSendRecordBound(s32 handle)
{
    s32 (*procedure)(s32, s32);

    ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->operation = 0;
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0);
    }
    return 1;
}
/* Dispatch roles below follow manager call sites; implementations remain window-kind specific. */
/* Send op 1 while clearing a manager entry; absent handlers return completion. */
// FUN_0027B830
s32 itfMesWindowSendClear(s32 handle)
{
    u8 *base;
    s32 (*procedure)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(handle);
    ((ItfMesProcedure *)base)->operation = 1;
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 1);
    }
    return 1;
}
/* Send op 2 after setting the styled-open script parameter; absent handlers return completion. */
// FUN_0027B8A0
s32 itfMesWindowSendStyledParameter(s32 handle)
{
    u8 *base;
    s32 (*procedure)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(handle);
    ((ItfMesProcedure *)base)->operation = 2;
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 2);
    }
    return 1;
}
/* Send op 3 before drawing the window lists; absent handlers return completion. */
// FUN_0027B910
s32 itfMesWindowSendDrawLists(s32 handle)
{
    u8 *base;
    s32 (*procedure)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(handle);
    ((ItfMesProcedure *)base)->operation = 3;
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 3);
    }
    return 1;
}
/* Poll op 4 while the main transition group is opening; absent handlers return completion. */
// FUN_0027B980
s32 itfMesWindowSendOpeningStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 4);
    }
    return 1;
}
/* Send op 5 while the main transition group is active; absent handlers return completion. */
// FUN_0027B9E0
s32 itfMesWindowSendActiveStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 5);
    }
    return 1;
}
/* Poll op 6 while the main transition group is closing; absent handlers return completion. */
// FUN_0027BA40
s32 itfMesWindowSendClosingStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 6);
    }
    return 1;
}
/* Send op 7 before requesting row and choice groups to close; absent handlers return completion. */
// FUN_0027BAA0
s32 itfMesWindowSendRelease(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 7);
    }
    return 1;
}
// Intent: Sends window op 8, which places the window's body and text lists for list node handle [inferred]
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BB00
s32 itfMesWindowSendLayoutLists(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, ITF_MES_WINDOW_OP_LAYOUT_LISTS);
    }
    return 1;
}
/* Send op 9 with visible choice count before reading layout parameters; absent handlers return completion. */
// FUN_0027BB60
s32 itfMesWindowSendChoiceMeasure(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 9);
    }
    return 1;
}
/* Send op 10 after creating the choice glyph list; absent handlers return completion. */
// FUN_0027BBC0
s32 itfMesWindowSendChoiceBuilt(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xA);
    }
    return 1;
}
/* Poll op 11 while the choice transition group is opening; absent handlers return completion. */
// FUN_0027BC20
s32 itfMesWindowSendChoiceOpeningStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xB);
    }
    return 1;
}
/* Send op 12 while the choice transition group is active; absent handlers return completion. */
// FUN_0027BC80
s32 itfMesWindowSendChoiceActiveStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xC);
    }
    return 1;
}
/* Poll op 13 while the choice transition group is closing; absent handlers return completion. */
// FUN_0027BCE0
s32 itfMesWindowSendChoiceClosingStep(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xD);
    }
    return 1;
}
/* Poll op 16 in row transition state 1 before advancing to state 2; absent handlers return completion. */
// FUN_0027BD40
s32 itfMesWindowSendRowTransitionEnter(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x10);
    }
    return 1;
}
/* Send op 17 while row transition state 2 is active; absent handlers return completion. */
// FUN_0027BDA0
s32 itfMesWindowSendRowTransitionActive(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x11);
    }
    return 1;
}
/* Poll op 18 in row transition state 3 before clearing that state; absent handlers return completion. */
// FUN_0027BE00
s32 itfMesWindowSendRowTransitionLeave(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x12);
    }
    return 1;
}
