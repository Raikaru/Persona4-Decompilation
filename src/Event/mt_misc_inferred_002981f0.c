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

s32 sdkSndFadeOutChannel(s64 arg0, s32 arg1);

extern void sndPlayAreaCue(void);
extern s32 sndRequestAreaTrack();
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];
s32 sdkSndStopChannel(s16 arg0);



extern void sdkSndRequestTrack(s32 arg0);
extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002981f0-00298250 */

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
// Requests sound track arg1 through sdkSndRequestTrack; the first argument is unused.
// FUN_002981F0
s32 mtMiscRequestSoundTrack(s32 unused, s32 arg1) {
    sdkSndRequestTrack(arg1);
    return 0;
}

// Fades out sound channel arg0 through sdkSndFadeOutChannel with a zero second argument.
// FUN_00298220
s32 mtMiscFadeOutSoundChannel(s64 arg0) {
    sdkSndFadeOutChannel((s16) arg0, 0);
    return 0;
}

// Looks up key (arg0 << 16 | arg1) in the 0x86-entry table D_0063CB50 and runs
// the action in the entry's second word: 1 and 2 call sndRequestAreaTrack (then
// sndPlayAreaCue when it returns 0), 3 calls sdkSndFadeOutChannel(3, 0) and
// sdkSndStopChannel(0x1E). Absent keys act as 3. Returns the action code.
// FUN_00298250
s32 mtMiscDispatchKeyAction(s32 arg0, s32 arg1)
{
    s32 key;
    s32 *temp_5;
    s32 *result_5;
    s32 var_4;
    s32 var_16;

    key = (arg0 << 16) | arg1;
    temp_5 = D_0063CB50;
    var_4 = 0;
    result_5 = NULL;
    goto loop_test_98250;
loop_body_98250:
    if (*temp_5 != key) {
        goto advance_98250;
    }
    result_5 = temp_5;
    goto found_98250;
advance_98250:
    temp_5 += 2;
    var_4++;
loop_test_98250:
    if (var_4 < 0x86) {
        goto loop_body_98250;
    }
    result_5 = NULL;
found_98250:
    if (result_5 != NULL) {
        var_16 = result_5[1];
    } else {
        var_16 = 3;
    }
    switch (var_16) {
    case 0:
        break;
    case 1:
    case 2:
        if (sndRequestAreaTrack() == 0) {
            sndPlayAreaCue();
        }
        break;
    case 3:
        sdkSndFadeOutChannel(3, 0);
        sdkSndStopChannel(0x1E);
        break;
    }
    return var_16;
}

