/* PS2 RNA buffer controls. */
#include "cri_xpt.h"

extern Sint32 D_0073A740;
extern Sint32 D_0073A748;
extern void *D_0073A774;

// FUN_004EC9E0
void func_004ec9e0(void *buffer)
{
	if (D_0073A748 != 1 || D_0073A740 > 0) {
		D_0073A774 = buffer;
	}
}

// FUN_004ECA10
void *func_004eca10(void)
{
	if (D_0073A748 == 1 && D_0073A740 <= 0) {
		return NULL;
	}
	return D_0073A774;
}
