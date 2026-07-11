#include "type.h"
#pragma optimization_level 3
// FUN_004D1200
u32 func_004d1200(int object)
{
    *(u8*)(object + 3) = 1;
    return 1;
}
#pragma optimization_level 2
