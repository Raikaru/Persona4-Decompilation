#include "rfmai_internal.h"

// FUN_004F5860
s64 RFMAI_CnvU32plusU32toS64(u32 high, u32 low)
{
    return (s64)(((u64)high << 32) + (u64)low);
}
