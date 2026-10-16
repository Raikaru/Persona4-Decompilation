/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Main/g_data.c; members 00110460-00110460 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern u8 D_0079BEF4[];
// Intent: Return the saved word at the cleared-state global; g_data stores it as the cleared flag [inferred]
// FUN_00110460
u32 datGetClearedWord(void) {
    return *(u32 *)D_0079BEF4;
}
