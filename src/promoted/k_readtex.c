/* Original translation unit k_readtex.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);

extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005F60B8[];
extern u8 D_005F6040[];
extern u8 D_005F6060[];
extern u8 D_005F6080[];
extern u8 D_005F60A0[];
extern u8 D_005F60D0[];
extern u8 D_005F60F0[];
extern u8 D_005F6110[];
extern u8 D_005F6130[];
extern u8 D_005F6150[];
extern s32 K_ReadTexUpdate(u8 *arg0);
extern void K_ReadTexDestroy(u8 *arg0);
extern void func_003ef3a0(void *handle);
extern s32 func_003ef6d0(void);
extern void *func_003ef650(s32 owner, const void *name);
extern void *H_Cdvd_AcquireDirectory(const char *path, s32 flags);
extern void H_Cdvd_Destroy(void *handle);
extern s32 filerEnqueueRequest(s32, const void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void filerTakeCompletedRequest(s32 task, s32 *result, s32 flags);
extern s32 iGpffffa030;










