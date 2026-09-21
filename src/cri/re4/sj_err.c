/* CRI stream-joint error reporting (sj_err.c): forwards the fixed messages ("E20040902xx : NULL
 * pointer is specified." etc.) to the SVM error callback. */
#include "cri_xpt.h"

extern void SVM_CallErr1(Char8 *msg);

// Reports a stream-joint error message through SVM_CallErr1.
void SJERR_CallErr(Char8 *msg)
{
	SVM_CallErr1(msg);
}
