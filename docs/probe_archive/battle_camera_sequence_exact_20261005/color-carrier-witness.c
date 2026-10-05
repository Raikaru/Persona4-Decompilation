/* Target-specific all-bit packed-word transport witness, not production code. */
#include "type.h"
typedef char ColorS32HasFourBytes[(sizeof(s32) == 4) ? 1 : -1];
typedef char ColorU32HasFourBytes[(sizeof(u32) == 4) ? 1 : -1];
s32 colorCarrierFromBits(u32 bits) { return (s32)bits; }
u32 colorCarrierRoundTrip(u32 bits) { return (u32)(s32)bits; }
void colorCarrierStore(u32 bits, s32 *destination) { *destination = (s32)bits; }
u32 colorCarrierWrongRoundTrip(u32 bits) { return (u32)(s32)bits & 0x7fffffffU; }
