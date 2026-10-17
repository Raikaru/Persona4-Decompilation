#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern void sprintf(char *buf, const char *fmt, s32 value);
extern void sdkSndStartChannel(s16 arg0, char *buf);
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 00298130-00298130 */

extern void mtMiscCollectType1Records(u8 *arg0);
extern void mtMiscCollectType2Records(u8 *arg0);
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
// Formats arg1 into a short string with D_0063CB30 and starts sound channel arg2
// with it (sdkSndStartChannel). Always returns 0.
// FUN_00298130
s32 mtMiscPlayFormattedCue(s32 arg0, s32 arg1, s32 arg2) {
    char sp20[0x20];

    sprintf(sp20, D_0063CB30, arg1);
    sdkSndStartChannel((s16)arg2, sp20);
    return 0;
}

