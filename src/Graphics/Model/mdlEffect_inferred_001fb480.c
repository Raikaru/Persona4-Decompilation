#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"


extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern void mdlEffectDrawScreenTexture(f32 scale, u8 *color, s32 blendMode, s32 testMode, u8 *textureFilter);
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern s32 kwlnGetCamera(void);
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *color, s32 blendMode, s32 testMode);


extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];


extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];


extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];


#pragma push
#pragma pop


extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlSoundRollStatusCure(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *action);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerReplyVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerAssistVoice(u8 *action, s32 variant);
extern s32 btlSoundPickRandomPartnerVoice(u8 *action);
extern s32 btlVoiceIdPacketUpdate(u8 *context);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: retail sets up the loop's shift constant before the branch into the loop test, which
 * needs opt_loop_invariants on. */

#pragma push
#pragma pop
/* measured: without opt_propagation off, retail's D_00887300 base is rematerialised per call and
 * the stack frame shrinks. */
#pragma push
/* measured: retail keeps copy propagation off here; with it on, the draw-buffer base is recomputed
 * per call and the stack frame shrinks. */
#pragma opt_propagation off
/* Draws a display-buffer textured quad, using a centered scaled rectangle or the full screen. */
/* Draws the display-buffer texture over the full screen or a centered scaled quad, tinted by RGBA. */
// FUN_001FB480
void mdlEffectDrawScreenTexture(f32 scale, u8 *color, s32 blendMode, s32 testMode, u8 *textureFilter)
{
    struct {
        u8 packet[0xF0];
        u8 pad[0x10];
    } work;
    f32 sx;
    f32 sy;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 z;
    f32 inv;
    f32 cx;
    f32 cy;
    f32 w320;
    f32 w224;
    f32 n320;
    f32 n224;
    f32 f;
    f32 g;
    BattleRenderStateFunction *base;
    u8 *cam;
    u8 *disp;
    extern u8 *RpSkyGetDisplayBufferRaster(void);
    extern void (*D_00887310[])(u32 color, void *blendMode, u32 testMode);
    extern f32 fGpffff82e8;
    extern f32 fGpffff82ec;

    cam = (u8 *)kwlnGetCamera();
    disp = RpSkyGetDisplayBufferRaster();
    f = (f32)((MdlEffectRaster *)disp)->width;
    sx = 640.0f / f;
    g = (f32)((MdlEffectRaster *)disp)->height;
    sy = 448.0f / g;
    x1 = 640.0f;
    y1 = 448.0f;
    if (scale == 0.0f) {
        x0 = 0.0f;
        y0 = 0.0f;
    } else {
        w320 = 320.0f;
        n320 = -w320;
        cx = fGpffff82e8;
        x0 = cx + n320 * scale;
        w224 = 224.0f;
        n224 = -w224;
        cy = fGpffff82ec;
        y0 = cy + n224 * scale;
        x1 = cx + w320 * scale;
        y1 = cy + w224 * scale;
    }
    base = D_00887300;
    base[0](rwRENDERSTATESHADEMODE, (void *)2);
    base[0](rwRENDERSTATECULLMODE, (void *)1);
    base[0](rwRENDERSTATEFOGENABLE, (void *)0);
    base[0](rwRENDERSTATEZTESTENABLE, (void *)0);
    base[0](rwRENDERSTATEZWRITEENABLE, (void *)0);
    base[0](rwRENDERSTATETEXTUREFILTER, textureFilter);
    base[0](rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
    base[0](rwRENDERSTATETEXTURERASTER, disp);
    RpSkyRenderStateSet(2, (void *)blendMode);
    RpSkyRenderStateSet(3, (void *)testMode);
    z = *(f32 *)D_008872FC_abs;
    inv = 1.0f / ((MdlEffectCamera *)cam)->farPlane;
    ((MdlEffectScreenVertex *)work.packet)[0].x = x0;
    ((MdlEffectScreenVertex *)work.packet)[0].y = y0;
    ((MdlEffectScreenVertex *)work.packet)[0].z = z;
    ((MdlEffectScreenVertex *)work.packet)[0].red = (f32)(u32)color[0];
    ((MdlEffectScreenVertex *)work.packet)[0].green = (f32)(u32)color[1];
    ((MdlEffectScreenVertex *)work.packet)[0].blue = (f32)(u32)color[2];
    ((MdlEffectScreenVertex *)work.packet)[0].alpha = (f32)(u32)color[3];
    ((MdlEffectScreenVertex *)work.packet)[0].reciprocalDepth = inv;
    ((MdlEffectScreenVertex *)work.packet)[0].u.bits = 0;
    ((MdlEffectScreenVertex *)work.packet)[0].v.bits = 0;
    ((MdlEffectScreenVertex *)work.packet)[1].x = x0;
    ((MdlEffectScreenVertex *)work.packet)[1].y = y1;
    ((MdlEffectScreenVertex *)work.packet)[1].z = z;
    ((MdlEffectScreenVertex *)work.packet)[1].red = (f32)(u32)color[0];
    ((MdlEffectScreenVertex *)work.packet)[1].green = (f32)(u32)color[1];
    ((MdlEffectScreenVertex *)work.packet)[1].blue = (f32)(u32)color[2];
    ((MdlEffectScreenVertex *)work.packet)[1].alpha = (f32)(u32)color[3];
    ((MdlEffectScreenVertex *)work.packet)[1].reciprocalDepth = inv;
    ((MdlEffectScreenVertex *)work.packet)[1].u.bits = 0;
    ((MdlEffectScreenVertex *)work.packet)[1].v.value = sy;
    ((MdlEffectScreenVertex *)work.packet)[2].x = x1;
    ((MdlEffectScreenVertex *)work.packet)[2].y = y0;
    ((MdlEffectScreenVertex *)work.packet)[2].z = z;
    ((MdlEffectScreenVertex *)work.packet)[2].red = (f32)(u32)color[0];
    ((MdlEffectScreenVertex *)work.packet)[2].green = (f32)(u32)color[1];
    ((MdlEffectScreenVertex *)work.packet)[2].blue = (f32)(u32)color[2];
    ((MdlEffectScreenVertex *)work.packet)[2].alpha = (f32)(u32)color[3];
    ((MdlEffectScreenVertex *)work.packet)[2].reciprocalDepth = inv;
    ((MdlEffectScreenVertex *)work.packet)[2].u.value = sx;
    ((MdlEffectScreenVertex *)work.packet)[2].v.bits = 0;
    ((MdlEffectScreenVertex *)work.packet)[3].x = x1;
    ((MdlEffectScreenVertex *)work.packet)[3].y = y1;
    ((MdlEffectScreenVertex *)work.packet)[3].z = z;
    ((MdlEffectScreenVertex *)work.packet)[3].red = (f32)(u32)color[0];
    ((MdlEffectScreenVertex *)work.packet)[3].green = (f32)(u32)color[1];
    ((MdlEffectScreenVertex *)work.packet)[3].blue = (f32)(u32)color[2];
    ((MdlEffectScreenVertex *)work.packet)[3].alpha = (f32)(u32)color[3];
    ((MdlEffectScreenVertex *)work.packet)[3].reciprocalDepth = inv;
    ((MdlEffectScreenVertex *)work.packet)[3].u.value = sx;
    ((MdlEffectScreenVertex *)work.packet)[3].v.value = sy;
    D_00887310[0](4, work.packet, 4);
    base[0](1, 0);
}

#pragma pop
