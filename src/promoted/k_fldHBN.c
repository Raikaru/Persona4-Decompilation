/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);



// FUN_00160180
void func_00160180(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18DC) != 0) {
        *(s32 *)((u8 *)func_00155280() + 0x18D8) = 0;
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18DC));
        *(s32 *)((u8 *)func_00155280() + 0x18DC) = 0;
    }
}
