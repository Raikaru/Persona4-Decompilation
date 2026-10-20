#include "Kosaka/k_command_internal.h"
#include "h_fade_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern void mdlEffectSeqStop();
extern s32 iGpffffa7c8;
extern void scrDiscardArgs(void *, ...);

s32 mtMiscResourceValue(s32 resourceId);

s32 sdkSndFadeOutChannel(s64, s32);

extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern void sprintf(char *buf, const char *fmt, s32 value);
extern void sdkSndStartChannel(s16 channelIndex, char *path);
extern char D_0063CB30[];
extern char D_0063D050[];
extern void sdkSndResetChannel(s32, s32);
extern void sdkSndFadeOutChannelFrames(s32 channelIndex, s32 requestValue, s32 fadeFrames);
void mdlEffectSeqStart(s32 duration, s16 sequenceId);
s32 sdkSndPlayCue(s16, s32);
s32 sdkSndStopMainChannel(void);
s32 sdkSndStopChannel(s16 fadeFrames);


extern s64 scrGetParamIntS64(s32);
extern void sdkSndRequestTrack(s32 trackId);
extern void scrCommandFiveOperandNoop(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern s32 D_0063CB50[];
extern void scrCommandAlternateFiveOperandNoop(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern u8 D_0063CFA0[];
// lint: allow H011 -- a u16 prototype breaks func_00291a60, which passes wide id args.
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32 farg0, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 image, f32 x, f32 y, f32 scaleX,
                          f32 scaleY, s32 alphaSubtract, s32 centered);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

extern void mtMiscCollectType1Records(u8 *eventWork);
extern void mtMiscCollectType2Records(u8 *eventWork);
extern void scrCommandFiveOperandNoop(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern void scrCommandAlternateFiveOperandNoop(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern void scrDiscardArgs(void *, ...);
#pragma push
#pragma pop
/* Script command: start an effect sequence on the given model. */
// FUN_002996E0
s32 K_Cmd_MDL_EFFECT_SEQ_START(void) {
    s32 model;

    model = scrGetParamInt(0);
    mdlEffectSeqStart(model, scrGetParamInt(1));
    return 1;
}

/* Stop the active model-effect sequence and complete the script command. */
// FUN_00299740
s32 K_Cmd_MDL_EFFECT_SEQ_STOP(void)
{
    mdlEffectSeqStop();
    return 1;
}

/* Start a stream on channel zero using two signed-halfword script operands. */
// FUN_00299770
s32 K_Cmd_SND_STREAM_START_CH0(void) {
    s32 streamId;
    s32 value;

    streamId = scrGetParamInt(0);
    value = scrGetParamInt(1);
    sdkSndStartStream(0, 0, (s16)streamId, (s16)value);
    return 1;
}

// FUN_002997D0
s32 K_Cmd_SND_STREAM_STOP_CH0(void) {
    sdkSndStopStream(0, 0);
    return 1;
}

/* Start a stream on channel one using two signed-halfword script operands. */
// FUN_00299800
s32 K_Cmd_SND_STREAM_START_CH1(void) {
    s32 streamId;
    s32 value;

    streamId = scrGetParamInt(0);
    value = scrGetParamInt(1);
    sdkSndStartStream(1, 0, (s16)streamId, (s16)value);
    return 1;
}

// FUN_00299860
s32 K_Cmd_SND_STREAM_STOP_CH1(void) {
    sdkSndStopStream(1, 0);
    return 1;
}

// FUN_00299890
/* p4flow Common 0x006F BGM (plays a sound cue with flag 1). */
s32 K_Cmd_BGM(void) {
    sdkSndPlayCue(scrGetParamInt(0), 1);
    return 1;
}

/* Stop the main channel for operand zero, otherwise stop the selected channel. */
// FUN_002998D0
/* p4flow Common 0x0070 BGM_STOP (id 0 stops all, else stops channel). */
s32 K_Cmd_BGM_STOP(void) {
    s32 channel;

    channel = scrGetParamInt(0);
    if (channel == 0) {
        sdkSndStopMainChannel();
    } else {
        sdkSndStopChannel(channel);
    }
    return 1;
}

/* Format the event-sound path from its identifier and start channel two. */
// FUN_00299920
/* p4flow Common 0x0071 EVT_SE_PLAY (numbered SE on channel 2). */
s32 K_Cmd_EVT_SE_PLAY(void) {
    char path[0x20];
    s32 soundId;

    soundId = scrGetParamInt(0);
    sprintf(path, D_0063D050, soundId);
    sdkSndStartChannel(2, path);
    return 1;
}

/* Reset channel two immediately for zero frames, otherwise fade it out over the requested frames. */
// FUN_00299970
/* p4flow Common 0x0072 EVT_SE_STOP (0 stops channel 2, else fades out). */
s32 K_Cmd_EVT_SE_STOP(void) {
    s32 frames;

    frames = scrGetParamInt(0);
    if (frames == 0) {
        sdkSndResetChannel(2, 0);
    } else {
        sdkSndFadeOutChannelFrames(2, 0, frames);
    }
    return 1;
}

// FUN_002999D0
/* p4flow Common 0x0073 EVT_SE_PLAY2 (body requests a sound track). */
s32 K_Cmd_EVT_SE_PLAY2(void) {
    sdkSndRequestTrack(scrGetParamInt(0));
    return 1;
}

/* Consume the legacy operand and request channel-three fade-out. */
// FUN_00299A10
/* p4flow Common 0x0074 EVT_SE_STOP2 (fades out channel 3). */
s32 K_Cmd_EVT_SE_STOP2(void) {
    scrGetParamInt(0);
    sdkSndFadeOutChannel(3, 0);
    return 1;
}

/* Set the custom fade RGB color from byte-truncated operands. */
// FUN_00299A50
s32 scrSetFadeColor(void) {
    s32 red;
    s32 green;
    s32 blue;

    red = scrGetParamInt(0);
    green = scrGetParamInt(1);
    blue = scrGetParamInt(2);
    H_Fade_SetCustomColor(red & 0xFF, green & 0xFF, blue & 0xFF);
    return 1;
}

/* Consume five wide script operands and forward them to the first unused command sink. */
// FUN_00299AC0
s32 scrCommonDiscardWideArgs(void) {
    s64 first;
    s64 second;
    s64 third;
    s64 fourth;
    s64 fifth;

    first = scrGetParamIntS64(0);
    second = scrGetParamIntS64(1);
    third = scrGetParamIntS64(2);
    fourth = scrGetParamIntS64(3);
    fifth = scrGetParamIntS64(4);
    scrCommandFiveOperandNoop(first, second, third, fourth, fifth);
    return 1;
}

/* Consume five wide script operands and forward them to the separate unused command sink. */
// FUN_00299B70
s32 scrCommonIgnoreWideArgs(void) {
    s64 first;
    s64 second;
    s64 third;
    s64 fourth;
    s64 fifth;

    first = scrGetParamIntS64(0);
    second = scrGetParamIntS64(1);
    third = scrGetParamIntS64(2);
    fourth = scrGetParamIntS64(3);
    fifth = scrGetParamIntS64(4);
    scrCommandAlternateFiveOperandNoop(first, second, third, fourth, fifth);
    return 1;
}

/* Consume a string operand through the legacy discard helper and complete the command. */
// FUN_00299C20
s32 K_Cmd_STRING_DISCARD(void)
{
    scrDiscardArgs(&iGpffffa7c8, scrGetParamString(0));
    return 1;
}

