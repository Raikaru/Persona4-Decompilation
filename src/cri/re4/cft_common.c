#include "cri_xpt.h"

/* CFT (colour format transform) common state. The functions were dead-stripped by the linker. */

const Char8 *CFT_GetFunctionName(void);

const Char8 *cftcom_function_name = "This CFT function doesn't support the function to get own name";
/* unreferenced pointer to a dead-stripped function: the linker left it zero */
const Char8 *(*cftcom_get_function_name)(void) = CFT_GetFunctionName;
Sint32 cftcom_optimize_speed;
Sint32 cftcom_optimize_size;

// Dead: speed/size optimisation switch.
void CFT_SetOptimizeSpeed(Sint32 sw)
{
	cftcom_optimize_speed = sw;
}

// Dead: speed/size optimisation switch.
void CFT_SetOptimizeSize(Sint32 sw)
{
	cftcom_optimize_size = sw;
}

// Dead: the "doesn't support" name string.
const Char8 *CFT_GetFunctionName(void)
{
	return cftcom_function_name;
}
