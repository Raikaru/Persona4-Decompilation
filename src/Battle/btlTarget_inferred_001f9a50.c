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
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
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

extern void sdkSndFadeOutChannelFrames(s32 arg0, s32 arg1, s32 arg2);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);

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






/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f9a50-001f9ac0 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 btlSoundRollStatusCure(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerReplyVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickPartnerAssistVoice(u8 *arg0, s32 arg1);
extern s32 btlSoundPickRandomPartnerVoice(u8 *arg0);
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
// FUN_001F9A50
void func_001f9a50(s32 arg0, s32 arg1) {
    s32 f = *(u16 *)((u8 *)iGpffffb3ac + 0xB3A);
    func_0045ae10((u16)f, (u16)arg1, (u16)arg0);
}

// FUN_001F9A90
void func_001f9a90(void) {
    sdkSndFadeOutChannelFrames(1, 0, 8);
}

/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
/* measured: btlVoiceIdPacketUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001F9AC0
s32 btlVoiceIdPacketUpdate(u8 *arg0)
{
    s32 value;
    s32 code;
    s32 flag;

    if (*(s32 *)(arg0 + 4) == 0) {
        if (*(u16 *)(arg0 + 8) == 0) {
            value = 0x6C;
        } else {
            value = 0x69;
        }
        code = value & 0xFFFF;
        switch (code) {
        case 0x6C:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 5;
            break;
        case 0x69:
            *(s16 *)(iGpffffb3ac + 0xB3A) = 4;
            break;
        default:
            break;
        }
        *(s32 *)(arg0 + 0) = 0;
        *(s32 *)(arg0 + 4) = 1;
    }
    if (*(s32 *)(arg0 + 0) == 0) {
        goto return_one_a;
    }
    flag = (*(u16 *)(iGpffffb3ac + 0xB38) & 1) != 0;
    if (flag == 0) {
        goto return_zero;
    }
return_one_b:
    return 1;
return_one_a:
    return 1;
return_zero:
    return 0;
}

