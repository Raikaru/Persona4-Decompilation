#include "Kosaka/k_command_internal.h"

extern char* func_00442830(char* destination, const char* source);
extern s32 func_00442088(char* destination, const char* format, ...);
extern char* func_00442428(char* destination, const char* source);

// FUN_00177A10
u32 func_00177a10()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = func_0029cc00(0);
    minorId = func_0029cc00(1);

    if (majorId > -1)
    {
        func_00442830(path, "field/rmd/m");

        func_00442088(buff, "%03d_", majorId);
        func_00442428(path, buff);

        func_00442088(buff, "%03d.RMD", minorId);
        func_00442428(path, buff);
    }
    else
    {
        func_00442830(path, "field/grmd/fobj");
        func_00442088(buff, "%03d.RMD", minorId);
        func_00442428(path, buff);
    }

    mdl = func_00477e80(4, minorId, path, 0);
    func_0029cf50((s32)mdl);

    return true;
}
