/* CRI MPEG delimiter error-state selector at retail 00504B18. */
#include "cri_xpt.h"

typedef struct {
	void (*callback)(void *user);
	void *user;
	Sint32 error;
} MPV_DLM_ERROR;

extern MPV_DLM_ERROR D_00743D38;

extern void func_00504b68(MPV_DLM_ERROR *state, Sint32 error);

// FUN_00504B18
Sint32 func_00504b18(Uint8 *hn, Sint32 error)
{
	if (hn == NULL) {
		func_00504b68(&D_00743D38, error);
	} else {
		func_00504b68((MPV_DLM_ERROR *)(hn + 0x250), error);
	}
	return error;
}
