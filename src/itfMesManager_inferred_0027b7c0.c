/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/itfMesManager.c); members 0027b7c0-0027be00 */

#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 func_0027bd40(s32 handle);
extern s32 func_0027bda0(s32 handle);
extern s32 func_0027be00(s32 handle);
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B7C0
s32 func_0027b7c0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->operation = 0;
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// The itfMes op wrappers below stay unnamed: each sends one op number, and op meanings differ across window kinds (see ItfMesWindowOp).
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B830
s32 func_0027b830(s32 handle)
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
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B8A0
s32 func_0027b8a0(s32 handle)
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
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B910
s32 func_0027b910(s32 handle)
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
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B980
s32 func_0027b980(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 4);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027B9E0
s32 func_0027b9e0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 5);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BA40
s32 func_0027ba40(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 6);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BAA0
s32 func_0027baa0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 7);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
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
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BB60
s32 func_0027bb60(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 9);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BBC0
s32 func_0027bbc0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xA);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BC20
s32 func_0027bc20(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xB);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BC80
s32 func_0027bc80(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xC);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BCE0
s32 func_0027bce0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0xD);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BD40
s32 func_0027bd40(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x10);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BDA0
s32 func_0027bda0(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x11);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Invoke the kind-specific procedure; a missing handler completes immediately. */
// FUN_0027BE00
s32 func_0027be00(s32 handle)
{
    s32 (*procedure)(s32, s32);

    itfMesWindowGetSubTable(handle);
    procedure = ((ItfMesProcedure *)itfMesWindowGetSubTable(handle))->callback;
    if (procedure != NULL) {
        return procedure(handle, 0x12);
    }
    return 1;
}
#pragma pop
