/* CRI MPEG delimiter state query at retail 00504A98. */
#include "cri_xpt.h"

typedef struct {
	Uint32 words[5];
} MPV_DLM_STATE;

extern Sint32 func_00507480(void *hn);
extern Sint32 func_00504b18(Sint32 hn, Uint32 code);

// FUN_00504A98
Sint32 func_00504a98(Uint8 *hn, MPV_DLM_STATE *out)
{
	if (func_00507480(hn) != 0) {
		return func_00504b18(0, 0xFF030204);
	}
	*out = *(MPV_DLM_STATE *)(hn + 0x250);
	return 0;
}
