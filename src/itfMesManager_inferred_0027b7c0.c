/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/itfMesManager.c); members 0027b7c0-0027be00 */

#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 func_0027bd40(s32 arg0);
extern s32 func_0027bda0(s32 arg0);
extern s32 func_0027be00(s32 arg0);
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027B7C0
s32 func_0027b7c0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    *(s32 *)(itfMesWindowGetSubTable(arg0) + 0x14) = 0;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// The itfMes op wrappers below stay unnamed: each sends one op number, and op meanings differ across window kinds (see ItfMesWindowOp).
// FUN_0027B830
s32 func_0027b830(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 1;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 1);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027B8A0
s32 func_0027b8a0(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 2;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 2);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027B910
s32 func_0027b910(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 3;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 3);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027B980
s32 func_0027b980(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 4);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027B9E0
s32 func_0027b9e0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 5);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BA40
s32 func_0027ba40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 6);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BAA0
s32 func_0027baa0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 7);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: Sends window op 8, which places the window's body and text lists for list node arg0 [inferred]
// FUN_0027BB00
s32 itfMesWindowSendLayoutLists(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, ITF_MES_WINDOW_OP_LAYOUT_LISTS);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BB60
s32 func_0027bb60(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 9);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BBC0
s32 func_0027bbc0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xA);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BC20
s32 func_0027bc20(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xB);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BC80
s32 func_0027bc80(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xC);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BCE0
s32 func_0027bce0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xD);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BD40
s32 func_0027bd40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x10);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BDA0
s32 func_0027bda0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x11);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// FUN_0027BE00
s32 func_0027be00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x12);
    }
    return 1;
}
#pragma pop
