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
extern void itfMesWindowFree(s32 arg0);








/* Source unit: src/promoted/code1_0027.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0027.c; members 0027b690-0027b690 */

/* measured: opt_loop_invariants off */
// Intent: Frees every window in the window list (task destroy callback) [inferred]
// FUN_0027B690
void itfMesWindowFreeAll(u8 *unusedTask)
{
    u8 *temp_16;
    u8 *var_3;

    var_3 = *(u8 **)DAT_008817EC_abs;
    while (var_3 != NULL) {
        temp_16 = *(u8 **)(var_3 + 4);
        itfMesWindowFree(*(s32 *)(var_3 + 8));
        var_3 = temp_16;
    }
}

