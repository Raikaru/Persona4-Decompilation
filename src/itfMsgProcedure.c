/* Whole-file translation unit: src/itfMsgProcedure.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "itf_mes_objects.h"
#include "message_procedure_api.h"

extern void kAssertFail(const void *file, u32 line);
extern char D_0063BF60[];

/* Read one of the four procedure parameters for a window handle. */
/* measured: direct procedure.parameters[index] changes addu order (nd 2). */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 2; retain their original address/alias expressions. */
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
    return *(s32 *)(address + 4);
}

/* Write one of the four procedure parameters for a window handle. */
/* measured: direct procedure.parameters[index] changes addu order (nd 2). */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 2; retain their original address/alias expressions. */
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
    *(s32 *)(address + 4) = value;
}
