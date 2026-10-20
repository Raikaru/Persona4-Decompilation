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

s32 mtMiscResourceValue(s32);

s32 sdkSndFadeOutChannel(s64, s32);

extern void sndPlayAreaCue(void);
extern s32 sndRequestAreaTrack();
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];
s32 sdkSndStopChannel(s16);



extern void sdkSndRequestTrack(s32);
extern s32 D_0063CB50[]; /* 0x86 packed-key/action pairs */
extern u8 D_0063CFA0[];
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32, f32, f32, f32,
                          f32, s32, s32);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002981f0-00298250 */

extern void mtMiscCollectType1Records(u8 *);
extern void mtMiscCollectType2Records(u8 *);
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
// Request trackId through sdkSndRequestTrack; the first argument is unused.
// FUN_002981F0
s32 mtMiscRequestSoundTrack(s32 unused, s32 trackId) {
    sdkSndRequestTrack(trackId);
    return 0;
}

// Fade out channel through sdkSndFadeOutChannel with a zero second argument.
// FUN_00298220
s32 mtMiscFadeOutSoundChannel(s64 channel) {
    sdkSndFadeOutChannel((s16) channel, 0);
    return 0;
}

// Look up keyHigh << 16 | keyLow in the 0x86-entry table D_0063CB50 and run
// the action in the entry's second word: 1 and 2 call sndRequestAreaTrack (then
// sndPlayAreaCue when it returns 0), 3 calls sdkSndFadeOutChannel(3, 0) and
// sdkSndStopChannel(0x1E). Absent keys act as 3. Returns the action code.
/* measured: a break-based search loses MATCH; the shared exit preserves the
 * explicit not-found assignment without retaining the decompiler loop labels. */
// FUN_00298250
s32 mtMiscDispatchKeyAction(s32 keyHigh, s32 keyLow)
{
    s32 key;
    s32 *entry;
    s32 *foundEntry;
    s32 entryIndex;
    s32 action;

    key = (keyHigh << 16) | keyLow;
    entry = D_0063CB50;
    entryIndex = 0;
    foundEntry = NULL;
    for (; entryIndex < 0x86; entryIndex++) {
        if (*entry == key) {
            foundEntry = entry;
            goto dispatchFound;
        }
        entry += 2;
    }
    foundEntry = NULL;
dispatchFound:
    if (foundEntry != NULL) {
        action = foundEntry[1];
    } else {
        action = 3;
    }
    switch (action) {
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
    return action;
}

