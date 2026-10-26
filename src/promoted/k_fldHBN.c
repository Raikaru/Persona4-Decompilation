#include "mt_scene_internal.h"
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_transition_internal.h"

extern u8 *MT_Scene_GetFrameState(void);
extern void FldHbnFreeEntryTable(void);
extern void (*DAT_008873EC[])(void *);
extern s32 FldRc_GetLoadSource(void);
extern s32 H_Cdvd_FileExists(void *arg0);
extern u8 *H_Cdvd_AcquireDirectory(void *arg0, s32 arg1);
extern char D_005F1108[];
extern char D_005F1118[];
extern char D_005F1130[];
extern char D_005F1150[];
extern char D_005F1170[];
extern char D_005F1190[];
extern char D_005F11B0[];
extern char D_005F11D0[];
extern u8 *iGpffff9db0;
extern char iGpffff9ef0;
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern u8 *H_Cdvd_LookupRequest(void *arg0, u32 *arg1);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern void H_Cdvd_Destroy(void *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);


#pragma push
#pragma opt_lifetimes on
#pragma pop







