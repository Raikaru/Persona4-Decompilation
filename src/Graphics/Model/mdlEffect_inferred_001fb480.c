#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
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
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



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






/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001fb480-001fb480 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 btlSoundRollStatusCure(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerReplyVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerAssistVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickRandomPartnerVoice(u8 *arg0);
extern s32 btlVoiceIdPacketUpdate(u8 *arg0);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: close opt_loop_invariants after btlSoundRollStatusCure. */
/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma pop
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
/* measured: opt_propagation off preserves btlSoundPickPartnerCallVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerCallVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerReplyVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerReplyVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerAssistVoice's loop constants. */
/* measured: close opt_propagation after btlSoundPickPartnerAssistVoice probe. */
/* measured: opt_propagation off tested for btlSoundPickRandomPartnerVoice; retains loop constants. */
/* measured: close opt_propagation after btlSoundPickRandomPartnerVoice. */
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
/* measured: close opt_propagation after btlVoiceIdPacketUpdate probe. */
/* Matched: the textured colour-quad Im2D upload (four 0x40-byte vertices).
   Conventions follow the matched code1_004b func_004b2780 (640/448 display
   scales, D_008872FC_abs depth, raw-offset stores) and the (f32)(u32)
   byte-colour idiom.  Levers: `x = a + (-b) * c` contracts to
   adda.s/madd.s; staging each negation as its own local emits lui + neg.s
   instead of a folded negative constant; staging each display-field
   conversion in a float local puts the lwc1 before the divide; the
   float-first signature is ABI-identical to the draft's order and fixes
   the mov.s materialisation order.  The opt_propagation-off bracket is
   load-bearing: without it the D_00887300 base rematerialises per call
   and the frame shrinks from 0x1A0 to 0x190. */
#pragma push
/* measured: func_001fb480 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001FB480
void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
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
    extern u8 *func_00401b80(void);
    extern void (*D_00887310[])(u32 arg0, void *arg1, u32 arg2);
    extern f32 fGpffff82e8;
    extern f32 fGpffff82ec;

    cam = (u8 *)kwlnGetCamera();
    disp = func_00401b80();
    f = (f32)*(s32 *)(disp + 0xC);
    sx = 640.0f / f;
    g = (f32)*(s32 *)(disp + 0x10);
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
    base[0](rwRENDERSTATETEXTUREFILTER, arg3);
    base[0](rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
    base[0](rwRENDERSTATETEXTURERASTER, disp);
    RpSkyRenderStateSet(2, (void *)arg1);
    RpSkyRenderStateSet(3, (void *)arg2);
    z = *(f32 *)D_008872FC_abs;
    inv = 1.0f / *(f32 *)(cam + 0x84);
    *(f32 *)(work.packet + 0x00) = x0;
    *(f32 *)(work.packet + 0x04) = y0;
    *(f32 *)(work.packet + 0x08) = z;
    *(f32 *)(work.packet + 0x20) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x24) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x28) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x2C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x18) = inv;
    *(s32 *)(work.packet + 0x10) = 0;
    *(s32 *)(work.packet + 0x14) = 0;
    *(f32 *)(work.packet + 0x40) = x0;
    *(f32 *)(work.packet + 0x44) = y1;
    *(f32 *)(work.packet + 0x48) = z;
    *(f32 *)(work.packet + 0x60) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0x64) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0x68) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0x6C) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x58) = inv;
    *(s32 *)(work.packet + 0x50) = 0;
    *(f32 *)(work.packet + 0x54) = sy;
    *(f32 *)(work.packet + 0x80) = x1;
    *(f32 *)(work.packet + 0x84) = y0;
    *(f32 *)(work.packet + 0x88) = z;
    *(f32 *)(work.packet + 0xA0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xA4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xA8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xAC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0x98) = inv;
    *(f32 *)(work.packet + 0x90) = sx;
    *(s32 *)(work.packet + 0x94) = 0;
    *(f32 *)(work.packet + 0xC0) = x1;
    *(f32 *)(work.packet + 0xC4) = y1;
    *(f32 *)(work.packet + 0xC8) = z;
    *(f32 *)(work.packet + 0xE0) = (f32)(u32)arg0[0];
    *(f32 *)(work.packet + 0xE4) = (f32)(u32)arg0[1];
    *(f32 *)(work.packet + 0xE8) = (f32)(u32)arg0[2];
    *(f32 *)(work.packet + 0xEC) = (f32)(u32)arg0[3];
    *(f32 *)(work.packet + 0xD8) = inv;
    *(f32 *)(work.packet + 0xD0) = sx;
    *(f32 *)(work.packet + 0xD4) = sy;
    D_00887310[0](4, work.packet, 4);
    base[0](1, 0);
}

