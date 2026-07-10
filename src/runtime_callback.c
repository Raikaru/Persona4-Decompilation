#include "type.h"

void func_004244c8(void* value);
extern u8 D_00761690;

void func_00440b68(s64 value);

// FUN_00100dd0
void func_00100dd0(s64 unused, void* value)
{
    func_004244c8(value);
    func_004244c8(&D_00761690);
}

// FUN_00100e00
void func_00100e00(s64 unused, s64 value)
{
    func_00440b68(value);
}
