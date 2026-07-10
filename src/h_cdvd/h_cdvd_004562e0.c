#include "h_cdvd_internal.h"

// FUN_004562E0
void func_004562e0(void* handle, const char* path)
{
    static char uppercasePath[256];
    static char fileName[256];
    static char directory[256];
    void* stream;

    stream = func_004d9020();
    func_00454d20(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);
    func_004d6f78(stream, fileName);
    (void)handle;
}
