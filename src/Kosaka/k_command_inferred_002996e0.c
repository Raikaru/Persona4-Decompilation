#include "Kosaka/k_command_internal.h"
#include "h_fade_internal.h"
/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern void func_004b15d0();
extern s32 iGpffffa7c8;
extern s32 scrGetParamString(s32 arg0);
extern void func_0029e9b0(void *arg0, ...);

s32 mtMiscResourceValue(s32 arg0);

s32 sdkSndFadeOutChannel(s64 arg0, s32 arg1);

extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern void sprintf(char *buf, const char *fmt, s32 value);
extern void sdkSndStartChannel(s16 arg0, char *buf);
extern char D_0063CB30[];
extern char D_0063D050[];
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
void func_004b1590(s32 arg0, s16 arg1);
s32 func_0045a3e0(s16 arg0, s32 arg1);
s32 func_00459880(void);
s32 sdkSndStopChannel(s16 arg0);



extern s64 scrGetParamIntS64(s32 arg0);
extern void sdkSndRequestTrack(s32 arg0);
extern void func_0029e990(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern s32 D_0063CB50[];
extern void func_0029e9a0(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void func_0029e9e0(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Source unit: src/promoted/code1_0029.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0029.c; members 002996e0-00299c20 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
extern void func_0029e990(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern void func_0029e9a0(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4);
extern void func_0029e9b0(void *arg0, ...);
/* measured probe: preserve local constant with opt_propagation off. */
/* measured probe: close opt_propagation bracket after func_00291530. */
/* measured: opt_propagation off keeps `weapon` materialised between the index
   shift and the base add (retail sll/andi/addu); with propagation on the CSE'd
   address is finished before any argument. The index/five locals must stay
   literal under this pragma or they take a sixth saved register. Attachment
   helpers retain block-scoped u16 parameters for per-call masks. */
/* measured: restore propagation for the rest of the unit. */
/* measured probe: preserve the retail type constant and close bracket below. */
/* measured probe: close opt_propagation bracket after func_00291810. */
/* measured: O1 float-local register mapping probe for func_00293710. */
/* measured: closes O1 float-local register mapping probe for func_00293710. */
/* Each filtered scan owns its resource and index. With opt_lifetimes on,
 * those local scopes reproduce all 6312 retail code bytes; the 6320-byte
 * function window ends in eight zero alignment bytes. */
#pragma push
#pragma pop
// FUN_002996E0
s32 func_002996e0(void) {
    s32 temp_16;

    temp_16 = scrGetParamInt(0);
    func_004b1590(temp_16, scrGetParamInt(1));
    return 1;
}

// FUN_00299740
s32 func_00299740(void)
{
    func_004b15d0();
    return 1;
}

// FUN_00299770
s32 func_00299770(void) {
    s32 a;
    s32 b;

    a = scrGetParamInt(0);
    b = scrGetParamInt(1);
    func_0045af60(0, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_002997D0
s32 func_002997d0(void) {
    func_0045aa90(0, 0);
    return 1;
}

// FUN_00299800
s32 func_00299800(void) {
    s32 a;
    s32 b;

    a = scrGetParamInt(0);
    b = scrGetParamInt(1);
    func_0045af60(1, 0, (s16)a, (s16)b);
    return 1;
}

// FUN_00299860
s32 func_00299860(void) {
    func_0045aa90(1, 0);
    return 1;
}

// FUN_00299890
s32 func_00299890(void) {
    func_0045a3e0(scrGetParamInt(0), 1);
    return 1;
}

// FUN_002998D0
s32 func_002998d0(void) {
    s32 temp_2;

    temp_2 = scrGetParamInt(0);
    if (temp_2 == 0) {
        func_00459880();
    } else {
        sdkSndStopChannel(temp_2);
    }
    return 1;
}

// FUN_00299920
s32 func_00299920(void) {
    char sp10[0x20];
    s32 v;

    v = scrGetParamInt(0);
    sprintf(sp10, D_0063D050, v);
    sdkSndStartChannel(2, sp10);
    return 1;
}

// FUN_00299970
s32 func_00299970(void) {
    s32 v;

    v = scrGetParamInt(0);
    if (v == 0) {
        func_0045a9a0(2, 0);
    } else {
        func_0045aac0(2, 0, v);
    }
    return 1;
}

// FUN_002999D0
s32 func_002999d0(void) {
    sdkSndRequestTrack(scrGetParamInt(0));
    return 1;
}

// FUN_00299A10
s32 func_00299a10(void) {
    scrGetParamInt(0);
    sdkSndFadeOutChannel(3, 0);
    return 1;
}

// FUN_00299A50
s32 func_00299a50(void) {
    s32 a;
    s32 b;
    s32 c;

    a = scrGetParamInt(0);
    b = scrGetParamInt(1);
    c = scrGetParamInt(2);
    H_Fade_SetCustomColor(a & 0xFF, b & 0xFF, c & 0xFF);
    return 1;
}

// FUN_00299AC0
s32 func_00299ac0(void) {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;

    a = scrGetParamIntS64(0);
    b = scrGetParamIntS64(1);
    c = scrGetParamIntS64(2);
    d = scrGetParamIntS64(3);
    e = scrGetParamIntS64(4);
    func_0029e990(a, b, c, d, e);
    return 1;
}

// FUN_00299B70
s32 func_00299b70(void) {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
    s64 e;

    a = scrGetParamIntS64(0);
    b = scrGetParamIntS64(1);
    c = scrGetParamIntS64(2);
    d = scrGetParamIntS64(3);
    e = scrGetParamIntS64(4);
    func_0029e9a0(a, b, c, d, e);
    return 1;
}

// FUN_00299C20
s32 func_00299c20(void)
{
    func_0029e9b0(&iGpffffa7c8, scrGetParamString(0));
    return 1;
}

