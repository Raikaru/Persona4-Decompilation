/* CRI ADX error reporting (adx_errs.c): the ADXERR_CallErrFunc1/2 entry points every ADX module
 * reports through. Copies the message into adxerr_msg (256 bytes), calls the optional ADX-level
 * callback and always the SVM error callback (the game's ap_mwply_err_func via ADXM_SetCbErr). */
#include "cri_xpt.h"
#include <string.h>

extern void SVM_CallErr(Char8 *fmt, ...);

static void (*adxerr_func)(void *obj, Char8 *msg) = NULL;
static void *adxerr_obj = NULL;
static Char8 adxerr_msg[256];

// Decimal formatter for the two-number error suffixes (dead-stripped; kept for its static buffer).
static void adxerr_itoa(Sint32 val, Char8 *str, Sint32 len)
{
	static Char8 buf[32];
	Sint32 i;
	Sint32 n;
	Sint32 l;

	for (i = 0; i < 32; i++) {
		str[i] = val % 10;
		val /= 10;
		if (val == 0) {
			str[i] = '\0';
			break;
		}
	}
	l = strlen(buf);
	n = len - 1;
	if (l < n) {
		n = l;
	}
	for (i = 0; i < n; i++) {
		str[i] = buf[n - 1 - i];
	}
	str[i] = '\0';
}

// Formats "a b" into `str` (used by the talk server's decoder-information error message).
// FUN_004C6C68
void ADXERR_ItoA2(Sint32 a, Sint32 b, Char8 *str, Sint32 len)
{
	adxerr_itoa(a, str, len);
	strncat(str, " ", len - strlen(str) - 1);
	adxerr_itoa(b, str + strlen(str), 4 - strlen(str));
}

// Reports a two-part error message (code prefix + text) to the ADX error callback and the SVM error
// callback the game installed with ADXM_SetCbErr (ap_mwply_err_func in sofdec.cpp).
// FUN_004C6AF0
void ADXERR_CallErrFunc2(Char8 *msg1, Char8 *msg2)
{
	strncpy(adxerr_msg, msg1, 255);
	strncat(adxerr_msg, msg2, 255);
	if (adxerr_func != NULL) {
		adxerr_func(adxerr_obj, adxerr_msg);
	}
	SVM_CallErr(adxerr_msg);
}

// Reports one error message to the ADX error callback and the SVM error callback.
void ADXERR_CallErrFunc1(Char8 *msg)
{
	strncpy(adxerr_msg, msg, 255);
	if (adxerr_func != NULL) {
		adxerr_func(adxerr_obj, adxerr_msg);
	}
	SVM_CallErr(adxerr_msg);
}

// Clears the message buffer and the callback.
void ADXERR_Finish(void)
{
	memset(adxerr_msg, 0, sizeof(adxerr_msg));
	adxerr_func = NULL;
	adxerr_obj = NULL;
}

// Clears the message buffer and the callback.
void ADXERR_Init(void)
{
	memset(adxerr_msg, 0, sizeof(adxerr_msg));
	adxerr_func = NULL;
	adxerr_obj = NULL;
}
