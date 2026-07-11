#include "type.h"

typedef int (*MdlCallback)(...);

typedef struct MdlStridedCallback24 {
    MdlCallback callback;
    u8 next[0x14];
} MdlStridedCallback24;

extern MdlStridedCallback24 D_00713f1c[];
extern MdlStridedCallback24 D_00713f20[];

// FUN_0049A710
void func_0049a710(int object)
{
    int count;
    int address;

    address = object;
    D_00713f1c[*(int *)(address + 0x38)].callback();
    count = *(int *)(address + 0x34) + 1;
    *(int *)(address + 0x34) = count;
    if (count > 0)
    {
        D_00713f20[*(int *)(address + 0x38)].callback(object);
    }
}
