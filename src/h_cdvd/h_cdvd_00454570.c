#include "h_cdvd_internal.h"

// FUN_00454570
u32 func_00454570(const char* path)
{
    char unusedUppercasePath[256];
    char fileName[256];
    char directory[256];
    char uppercasePath[256];
    ADXF adxf;

    func_00440b68(" Exist %s\n", path);
    func_00454d20(path, unusedUppercasePath);
    func_00454d20(path, uppercasePath);
    func_00454e10(uppercasePath, fileName, directory);
    func_00455230(directory);

    adxf = func_004c85a0(fileName, 0);
    if (adxf == NULL)
    {
        func_00440b68(" FALSE \n");
        return false;
    }

    func_004c8a60(adxf);
    func_00440b68(" TRUE \n");
    return true;
}
