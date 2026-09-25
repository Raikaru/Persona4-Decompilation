/* ADX talk decoder queries and the two no-op boundary calls around handle queries. */
#include "adx_t.h"

extern void *func_004cefb8(void *sjd);
extern void *func_004d5370(ADXT adxt);
extern void func_004c54d8(void);
extern void func_004c54e0(void);
void *func_004d5320(ADXT adxt);

// FUN_004D52E8
void *func_004d52e8(ADXT adxt)
{
	void *result;

	func_004c54d8();
	result = func_004d5320(adxt);
	func_004c54e0();
	return result;
}

// FUN_004D5320
void *func_004d5320(ADXT adxt)
{
	return func_004cefb8(adxt->sjd);
}

// FUN_004D5338
void *func_004d5338(ADXT adxt)
{
	void *result;

	func_004c54d8();
	result = func_004d5370(adxt);
	func_004c54e0();
	return result;
}
