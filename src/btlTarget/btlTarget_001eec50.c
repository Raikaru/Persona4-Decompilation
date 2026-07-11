#include "type.h"

// FUN_001EEC50
void func_001eec50(void* work)
{
    *(u16*)((u8*)work + 0x400) = 0;
    *(u16*)((u8*)work + 0x402) = 0;
}
