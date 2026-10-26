#include "type.h"

void func_004244c8(void* value);
extern u8 D_00761690;

void func_00440b68(s64 value);

/* Print the registered stream error message, followed by the runtime separator string. */
// FUN_00100dd0
void kwlnPrintStreamError(void* unused, void* value)
{
    func_004244c8(value);
    func_004244c8(&D_00761690);
}

// FUN_00100e00
void kwlnLogStreamError(s64 unused, s64 value)
{
    func_00440b68(value);
}
