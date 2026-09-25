/* Retail ADXT error callback and paused-sample discard at 0x004D6388–0x004D64CC. */
#include "adx_t.h"

extern void func_004c54d8(void);
extern void func_004c54e0(void);
extern void func_004c6a70(void (*func)(), void *obj);
extern Sint32 func_004cd8f0(void *rna, Sint32 nsmpl);
extern void func_004d5b30(void);
extern void adxt_GetTime(ADXT adxt, Sint32 *ncount, Sint32 *tscale);
extern Sint32 adxt_time_mode;
extern Sint32 adxt_time_unit;

Sint32 func_004d63e8(ADXT adxt, Sint32 nsmpl);

// FUN_004D6388
void func_004d6388(void (*func)(), void *obj)
{
	func_004c6a70(func, obj);
}

// FUN_004D63A0
Sint32 func_004d63a0(ADXT adxt, Sint32 nsmpl)
{
	Sint32 n;

	func_004c54d8();
	n = func_004d63e8(adxt, nsmpl);
	func_004c54e0();
	return n;
}

// FUN_004D63E8
Sint32 func_004d63e8(ADXT adxt, Sint32 nsmpl)
{
	Sint32 n;
	Sint32 mode;
	Sint32 ncount;
	Sint32 tscale;

	if (adxt->x72 == 0) {
		return 0;
	}

	n = func_004cd8f0(adxt->rna, nsmpl);
	func_004d5b30();
	mode = adxt_time_mode;
	adxt_time_mode = 0;
	adxt_GetTime(adxt, &ncount, &tscale);
	adxt_time_mode = mode;
	adxt->x9c = (Uint32)(((Float32)ncount / (Float32)tscale) * (Float32)adxt_time_unit);
	adxt->startvsync = adxt_vsync_cnt;
	return n;
}
