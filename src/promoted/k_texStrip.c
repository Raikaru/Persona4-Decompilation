#include "include_asm.h"
#include "Kosaka/k_clump_property_internal.h"
#include "sdk_task_registration.h"
/* Original translation unit k_texStrip.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_00428618(s32 arg0);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void func_00440b68(const char *fmt, ...);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void *func_003ef650(void *arg0, const char *arg1);
extern void func_003ef610(s32 arg0);
extern void func_003ef5b0(s32 arg0, s32 arg1);

extern s32 func_00468170(void *arg0, const char *arg1);
extern s32 sdkFilerPollResult(s32 arg0, void *arg1);
extern void K_Clump_LogCodeCounts(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern char D_005F6168[];
extern char D_005F6178[];
extern char D_005F6190[];
extern char D_005F61B0[];
extern char D_005F63E0[];
extern char D_005F6490[];
extern char D_005F64A8[];

extern s32 func_003e2f60(s32 a, s32 b, s32 *c);
extern s32 func_003df3c0(s32 a, s32 *b);
extern void func_003e2910(s32 a, void *b, s32 c);
extern void func_003deff0(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_003e2ab0(s32 a, void *b, s32 c);
extern void func_003e2ce0(s32 a, s32 b);
extern void func_003e2e40(s32 a, s32 b);
extern s32 func_003e6a90(s32 a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern s32 func_004288d8(void *a, void *b);
extern u8 *H_Cdvd_AcquireDirectory(void *path, s32 flags);
extern void H_Cdvd_ReadSync(void *handle);
extern void H_Cdvd_Destroy(void *handle);
extern char *strcat(char *dst, const char *src);
extern void func_003ef1b0(s32 arg0);
extern void func_003ef260(s32 arg0, s32 (*arg1)(s32, s32), s32 arg2);
extern void func_003e6870(void *arg0, void *arg1);
extern s32 K_TexStripNameInsert(s32 arg0, s32 arg1);
extern char D_005F63F0[];
extern char D_005F6430[];
extern char D_005F6450[];
extern char D_005F6470[];
extern char D_00763128;
extern char D_00763130;
extern char D_00763138;
extern char D_0076313C;
extern char D_00763140;
extern char D_00763148;
extern char D_00763150;
extern char D_00763158;
extern s32 D_00764498;

extern s32 func_00428550(const char *path);
extern s32 func_00428780(s32 handle, void *out);
extern s32 strcmp(const char *a, const char *b);
extern char *strcpy(char *dst, const char *src);
extern u8 *FldResource_Create(void *path);
extern s32 FldResource_IsFileLoaded(void *hdr);
extern void FldResource_ParseChunks(void *hdr);
extern s32 FldResource_PollLoads(void *hdr);
extern s32 K_Clump_CountIntUsrData(void *object, const char *name);
extern s32 func_00426cf0(void *path, s32 a, s32 b);
extern size_t strlen(const char *buf);
extern s32 sceWrite(s32 fd, void *buf, s32 n);
extern s32 sceRead(s32 fd, void *buf, s32 n);
extern s32 func_00427338(s32 fd, void *buf, s32 n);
extern s32 func_004275a8(s32 fd, void *buf, s32 n);
extern void func_00426f80(s32 fd);
extern void func_00428f08(void *a, s32 b);
extern void FldResource_Destroy(void *hdr);
extern void K_Clump_FreeTextureNameList(void *a);
extern char D_005F61D0[];
extern char D_005F61F8[];
extern char D_005F6210[];
extern char D_005F6230[];
extern char D_005F6250[];
extern char D_005F6270[];
extern char D_005F62A0[];
extern char D_005F62B0[];
extern char D_005F62C0[];
extern char D_005F62D0[];
extern char D_005F6310[];
extern char D_005F6350[];
extern char D_005F6370[];
extern char D_005F63B0[];

s32 K_TexStripLoadRecords(u8 *arg0, void *arg1);
void K_TexStripApplyNames(u8 *arg0, void *arg1, u8 *arg2);
s32 K_TexStripBuildUpdate(u8 *arg0);
s32 K_TexStripRecordCount(u8 *arg0, void *arg1);
s32 K_TexStripLoadUpdate(u8 *arg0);




#pragma opt_common_subs off
/* measured: restore CSE after the exact 00190920 call sequence. */
#pragma opt_common_subs on



#pragma push
#pragma opt_loop_invariants on
#pragma pop








