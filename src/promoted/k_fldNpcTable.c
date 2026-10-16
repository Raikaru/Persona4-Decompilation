#include "include_asm.h"
/* Original translation unit k_fldNpcTable.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *MT_Scene_GetFrameState(void);
extern void (*DAT_008873EC[])(void *);
extern s32 FldRc_GetLoadSource(void);
extern void strcpy(void *arg0, const char *arg1);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 H_Cdvd_FileExists(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2, ...);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern u8 *gMtScene;
extern char D_00762F20;
extern char D_005F0790[];
extern char D_005F07A0[];
extern char D_005F07C0[];
extern char D_005F07D0[];
extern char D_005F07F0[];
extern char D_005F0810[];
extern char D_005F0830[];
extern char D_005F0850[];
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void H_Cdvd_Destroy(void *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 D_00764384;
extern s32 D_00764388;
extern s32 D_0076438C;
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern s32 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern void calSplitDayOfYear(s16 year, s32 *month, s32 *day);
extern s32 datGetFlag(s32 id);
extern s32 clndIsDateInRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3);








extern u16 *NpcTable_GetMarkedEntry(s32 arg0);
#pragma opt_loop_invariants on
/* measured: see annotation above (NpcTable_GetMarkedEntry). */
#pragma opt_loop_invariants off

















extern s32 NpcTable_InstallFixedTable(u8 *arg0);
#pragma opt_loop_invariants on
/* measured: see annotation above (NpcTable_InstallFixedTable). */
#pragma opt_loop_invariants off




