/* Retail ADXT decoder key setters and renderer getter, after ADXT_SetOutputMono. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004c6a98(const Char8 *message);
extern void func_004cec38(void *sjd, const Char8 *key);
extern void func_004cec50(const Char8 *key);
extern Uint32 func_004d6cb8(ADXT adxt);
extern Char8 D_007592E8[];

void adxt_SetKeyString(ADXT adxt, const Char8 *key);
void func_004d6c68(const Char8 *key);

// FUN_004D6BC8
void func_004d6bc8(ADXT adxt, const Char8 *key)
{
	func_004c54d8();
	adxt_SetKeyString(adxt, key);
	func_004c54e0();
}

// FUN_004D6C08
void adxt_SetKeyString(ADXT adxt, const Char8 *key)
{
	if (adxt == NULL) {
		func_004c6a98(D_007592E8);
		return;
	}
	func_004cec38(adxt->sjd, key);
}

// FUN_004D6C38
void func_004d6c38(const Char8 *key)
{
	func_004c54d8();
	func_004d6c68(key);
	func_004c54e0();
}

// FUN_004D6C68
void func_004d6c68(const Char8 *key)
{
	func_004cec50(key);
}

// FUN_004D6C80
Uint32 func_004d6c80(ADXT adxt)
{
	Uint32 rna;

	func_004c54d8();
	rna = func_004d6cb8(adxt);
	func_004c54e0();
	return rna;
}
