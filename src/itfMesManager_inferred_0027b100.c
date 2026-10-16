#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];



extern s32 D_008815B0[];

static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}

extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027b100-0027b100 */

/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
// Intent: Moves the window's selection cursor one step (wrapping) in the given direction [inferred]
// FUN_0027B100
void itfMesWindowMoveSelection(u8 *arg0, s32 arg1) {
    s32 temp_2;
    s32 var_6;
    u32 var_5;
    s32 var_3;

    temp_2 = (s32)*(s16 *)(arg0 + 0xE);
    if (arg1 < 0) {
        var_6 = temp_2 - 1;
        if (var_6 < 0) {
            var_6 = (s32)*(s16 *)(arg0 + 0x12) - 1;
        }
    } else {
        var_6 = temp_2 + 1;
        if (var_6 >= (s32)*(s16 *)(arg0 + 0x12)) {
            var_6 = 0;
        }
    }
    *(s16 *)(arg0 + 0xE) = (s16)var_6;
    var_5 = *(u32 *)(arg0 + 8);
    var_3 = 0;
    goto loop_test;
loop_body:
    if ((var_5 & 1) == 0) {
        var_6 -= 1;
        if (var_6 < 0) {
            goto loop_exit;
        }
    }
    var_3 += 1;
    var_5 >>= 1;
loop_test:
    if (var_3 < 0x20) {
        goto loop_body;
    }
loop_exit:
    *(s16 *)(arg0 + 0x10) = (s16)var_3;
    func_0045af60(0, 0, 0, 0);
}

