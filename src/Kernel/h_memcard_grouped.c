/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

extern s32 D_00764B9C;
extern s32 D_00764BC0;

extern s32 D_00764BBC;
extern s32 D_00764BB8;
extern void *D_00764BAC;
extern s32 D_00764BB4;
extern s32 D_00764BA4;
extern s32 memcardPollCommand(s32 *command, s32 *result, s32 *error);
extern s32 sceMc2GetInfoAsync(s32 socket, s32 *status);
extern void sprintf(void *dst, const void *fmt, ...);
extern s32 func_00431d78(s32 socket, const char *name, void *result);
extern void func_00440b68(const void *fmt, ...);
extern s32 func_00431b58(s32 socket);
extern s32 func_00432288(s32 socket, const char *name, const void *data, u32 offset, u32 size);
extern s32 func_004323a8(s32 socket, const char *name);
extern s32 func_004326b8(s32 socket, void *data);
extern void memcpy(void *dst, void *src, s32 size);
extern void memset(void *dst, s32 value, s32 size);
extern void strcpy(void *dst, const void *src);
extern void strcat(void *dst, void *src);
extern s32 H_Cdvd_LookupRequest(s32 arg0, s32 *arg1);
extern char D_007127B0[];
extern char D_007127D0[];
extern char D_00712800[];
extern char D_00712820[];
extern char D_00712840[];
extern char D_00712860[];
extern char D_00712880[];
extern char D_00712890[];
extern char D_007126A0[];
extern char D_007126E0[];
extern char D_00712710[];
extern char D_00712740[];
extern char *D_00712760[];
extern char *D_00712764[];
extern char *D_00712768[];
extern char *D_00712770[];
extern char D_007640F8[8];
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];
extern char D_008E4A20[];
extern char D_008E4900[];
extern char D_008E4410[];
extern s16 D_008E4416[];
extern s32 D_008E441C[];
extern char D_008E4420[];
extern char D_008E4460[];
extern char D_008E4490[];
extern char D_008E44C0[];
extern char D_008E44D0[];
extern char D_008E4514[];
extern char D_008E4554[];
extern char D_008E4594[];
