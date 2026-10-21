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


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern void sprintf(char *buf, const char *fmt, s32 value);
extern void sdkSndStartChannel(s16, char *buf);
extern char D_0063CB30[];
extern char D_0063D050[];


extern s32 D_0063CB50[];
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
#pragma push
#pragma pop
// Format cueId into a short string with D_0063CB30 and start the selected channel
// with it (sdkSndStartChannel). Always returns 0.
// FUN_00298130
s32 mtMiscPlayFormattedCue(s32 unused, s32 cueId, s32 channel) {
    char cueName[0x20];

    sprintf(cueName, D_0063CB30, cueId);
    sdkSndStartChannel((s16)channel, cueName);
    return 0;
}

