#include "evt_internal.h"
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
// lint: allow H011 -- callers such as func_00291a60 pass wide id arguments, so a u16 prototype
// changes the output.
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

extern void mtMiscCollectType1Records(u8 *);
extern void mtMiscCollectType2Records(u8 *);
/* measured: with opt_propagation off, retail keeps `weapon` in its own register between the index
 * shift and the base add, and the index locals stay literal. */
#pragma push
#pragma pop
// Request trackId through sdkSndRequestTrack; the first argument is unused.
// FUN_002981F0
s32 mtMiscRequestSoundTrack(s32 unused, s32 trackId, s32 unusedChannel) {
    sdkSndRequestTrack(trackId);
    return 0;
}

// Fade out channel through sdkSndFadeOutChannel with a zero second argument.
// FUN_00298220
s32 mtMiscFadeOutSoundChannel(s64 channel, s32 unusedCue) {
    sdkSndFadeOutChannel((s16) channel, 0);
    return 0;
}

// Look up (keyHigh << 16) | keyLow in the 0x86-entry table D_0063CB50 and run the entry's action:
// 1/2 request the area track (cue on 0), 3 fades and stops. Missing keys act as 3; returns the
// action.
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

