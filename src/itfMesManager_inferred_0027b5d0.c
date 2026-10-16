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
extern void func_0027b5a0(s32 arg0);
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern void itfMesWindowQueueCallback(s32 arg0);
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);

/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027b5d0-0027b5d0 */

/* measured: opt_propagation off probe for 002703d0 register setup. */
/* measured: closes opt_propagation off probe for 002703d0. */
/* measured: opt_rebuildconditionals off reproduces 002704f0 retail conditional-register schedule. */
/* measured: closes opt_rebuildconditionals off for 002704f0. */
/* measured: opt_propagation off probe for 00270780 family add */
/* measured: close opt_propagation off probe for 00270780 family add */
/* measured: opt_propagation off probe for 00270a80 addu order */
/* measured: close opt_propagation off probe for 00270a80 */
/* measured: opt_loop_invariants hoists mask/count/const-1 into preheader */
/* measured: opt_loop_invariants off */
// Intent: Queues the window task's deferred callback with the task argument [inferred]
// FUN_0027B5D0
void itfMesWindowQueueCallback(s32 arg0)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32))(temp_2 + 8) = func_0027b5a0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0(D_007964C0, temp_2);
}

