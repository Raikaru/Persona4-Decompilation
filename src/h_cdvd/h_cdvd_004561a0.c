#include "h_cdvd_internal.h"

// FUN_004561A0
void func_004561a0(void* handle, const char* path, s32 synchronous)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];

    func_00454d20(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    if (synchronous)
    {
        func_0050ff20(handle, fileName);
    }
    else
    {
        func_0050c008(handle, fileName);
    }
}
