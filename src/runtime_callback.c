#include "runtime_hooks_internal.h"
#include "runtime_stdio_internal.h"
#include "type.h"

extern u8 D_00761690;


/* Print the registered stream error message, followed by the runtime separator string. */
// FUN_00100dd0
void kwlnPrintStreamError(void* unused, char* value)
{
    func_004244c8(value);
    func_004244c8((const char *)&D_00761690);
}

// FUN_00100e00
void kwlnLogStreamError(void* unused, char* value)
{
    func_00440b68(value);
}
