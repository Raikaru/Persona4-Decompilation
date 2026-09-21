/* CRI RNA (renderer) error reporting (rna_err.c): message buffer and callback, chained to the ADX
 * error callback by ADXT_Init. */
#include "cri_xpt.h"
#include <string.h>

static void (*rnaerr_func)(void *obj, Char8 *msg) = NULL;
static void *rnaerr_obj = NULL;
static Char8 rnaerr_msg[256];

// Copies the message and calls the registered callback.
void RNAERR_CallErrFunc(Char8 *msg)
{
	strncpy(rnaerr_msg, msg, 255);
	if (rnaerr_func != NULL) {
		rnaerr_func(rnaerr_obj, rnaerr_msg);
	}
}

// Registers the callback (func(obj, msg)).
void RNAERR_EntryErrFunc(void (*func)(void *obj, Char8 *msg), void *obj)
{
	rnaerr_func = func;
	rnaerr_obj = obj;
}
