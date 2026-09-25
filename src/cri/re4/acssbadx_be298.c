/* ACSSBAIX_StartMemIdx is unsupported in this retail build. */
#include "cri_xpt.h"

extern Uint8 D_00756B38[];
extern void func_004bd6a0(const void *message);

// FUN_004BE298
void ACSSBAIX_StartMemIdx(void)
{
	func_004bd6a0(D_00756B38);
}
