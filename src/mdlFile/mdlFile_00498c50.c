#include "type.h"

typedef int (*MdlCallback)(...);

typedef struct MdlStridedCallback24 {
    MdlCallback callback;
    u8 next[0x14];
} MdlStridedCallback24;

extern MdlStridedCallback24 D_00713e7c[];
extern MdlStridedCallback24 D_00713e80[];

// FUN_00498C50
void func_00498c50(int object)
{
    int count;
    int address;

    address = object;
    D_00713e7c[*(int *)(address + 0x2c)].callback();
    count = *(int *)(address + 0x28) + 1;
    *(int *)(address + 0x28) = count;
    if (count > 0)
    {
        D_00713e80[*(int *)(address + 0x2c)].callback(object);
    }
}
