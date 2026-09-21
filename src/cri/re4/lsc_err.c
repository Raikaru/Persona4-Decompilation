/* CRI LSC error reporting (lsc_err.c): printf-style messages ("E0003: Illigal parameter lsc=NULL")
 * into a 256-byte buffer and the callback ADXT_Init chains to the ADX error path. */
#include "cri_xpt.h"
#include <stdarg.h>
#include <stdio.h>

static void (*lsc_err_func)(void *obj, Char8 *msg) = NULL;
static void *lsc_err_obj = NULL;
static Char8 lsc_err_msg[256];

// Formats and reports a scheduler error.
void LSC_CallErrFunc(Char8 *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vsprintf(lsc_err_msg, fmt, ap);
	va_end(ap);
	if (lsc_err_func != NULL) {
		lsc_err_func(lsc_err_obj, lsc_err_msg);
	}
}

// Installs (or clears with NULL) the error callback.
void LSC_EntryErrFunc(void (*func)(void *obj, Char8 *msg), void *obj)
{
	if (func == NULL) {
		lsc_err_func = NULL;
		lsc_err_obj = NULL;
	} else {
		lsc_err_func = func;
		lsc_err_obj = obj;
	}
}
