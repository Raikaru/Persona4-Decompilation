/* Retail ADXT locked link-switch setter at 0x004D65B8. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004d65f8(ADXT adxt, Sint32 sw);

// FUN_004D65B8
void func_004d65b8(ADXT adxt, Sint32 sw)
{
	func_004c54d8();
	func_004d65f8(adxt, sw);
	func_004c54e0();
}
