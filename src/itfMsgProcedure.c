/* Whole-file translation unit: src/itfMsgProcedure.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "itf_mes_objects.h"
#include "message_procedure_api.h"

extern void kAssertFail(const void *file, u32 line);
extern char D_0063BF60[];

/* Read one of the four procedure parameters for a window handle; raw address expressions are kept
 * because typed array indexing changes the address arithmetic order. */
// FUN_0027B6E0
s32 itfMesWindowGetProcedureParam(s32 handle, s32 index)
{
    s32 base;
    s32 address;

    base = itfMesWindowGetSubTable(handle);
    if (index >= 4) {
        kAssertFail(D_0063BF60, 0x1F);
    }
    address = index * 4;
    address += base;
    return ((ItfMesProcedure *)address)->parameters[0];
}

/* Write one of the four procedure parameters for a window handle. */
// FUN_0027B750
void itfMesWindowSetProcedureParam(s32 handle, s32 index, s32 value)
{
    s32 base;
    s32 address;

    base = itfMesWindowGetSubTable(handle);
    if (index >= 4) {
        kAssertFail(D_0063BF60, 0x27);
    }
    address = index * 4;
    address += base;
    ((ItfMesProcedure *)address)->parameters[0] = value;
}
