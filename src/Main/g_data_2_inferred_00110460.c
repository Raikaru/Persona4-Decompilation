
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern u8 D_0079BEF4[];
// Returns the saved word at the cleared-state global, which g_data stores as the cleared flag.
// FUN_00110460
u32 datGetClearedWord(void) {
    return *(u32 *)D_0079BEF4;
}
