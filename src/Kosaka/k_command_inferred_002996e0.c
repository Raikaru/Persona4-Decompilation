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
extern void sdkSndStartChannel(s16 channelIndex, char *buf);
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
extern void func_0029e990(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern s32 D_0063CB50[];
extern void func_0029e9a0(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                          s32, f32 farg0, s32, s32,
                          s32);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 image, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 alphaSubtract, s32 centered);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0029; members 002996e0-00299c20 */

extern void mtMiscCollectType1Records(u8 *eventWork);
extern void mtMiscCollectType2Records(u8 *eventWork);
extern void func_0029e990(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern void func_0029e9a0(s64 unusedFirst, s64 unusedSecond, s64 unusedThird, s64 unusedFourth, s64 unusedFifth);
extern void scrDiscardArgs(void *, ...);
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
    func_0029e990(first, second, third, fourth, fifth);
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
    func_0029e9a0(first, second, third, fourth, fifth);
    return 1;
}

/* Consume a string operand through the legacy discard helper and complete the command. */
// FUN_00299C20
s32 K_Cmd_STRING_DISCARD(void)
{
    scrDiscardArgs(&iGpffffa7c8, scrGetParamString(0));
    return 1;
}

