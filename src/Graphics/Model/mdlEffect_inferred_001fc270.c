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






extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001fc270-001fc270 */

extern s32 func_001f0ff0(u32);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma pop
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Constant success result; no state is inspected or changed. */
/* Returns the constant success value 1 without changing state. */
// FUN_001FC270
s32 mdlEffectReturnSuccess(void)
{
    return 1;
}

