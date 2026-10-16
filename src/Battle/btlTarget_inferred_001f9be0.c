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

extern void memset(void *destination, s32 value, u32 size);


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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f9be0-001f9ce0 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 func_001f6770(u8 *arg0);
extern s32 func_001f6f60(u8 *arg0);
extern s32 func_001f7140(u8 *arg0);
extern void func_001f72e0(void);
extern s32 func_001f8ea0(u8 *arg0, s32 arg1);
extern s32 func_001f8f40(u8 *arg0, s32 arg1);
extern s32 func_001f8fe0(u8 *arg0, s32 arg1);
extern s32 func_001f90e0(u8 *arg0);
extern s32 btlVoiceIdPacketUpdate(u8 *arg0);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: close opt_loop_invariants after func_001f6770. */
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
/* measured: opt_rebuildconditionals off probe for func_001f6f60 final branch. */
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
/* measured: opt_rebuildconditionals off preserves func_001f7140's positive flag branch. */
/* measured: close opt_rebuildconditionals after func_001f7140. */
/* measured: optimization_level 1 required for exact func_001f72e0 codegen. */
/* measured: opt_loop_invariants off baseline for func_001f72e0. */
/* measured: restore optimization_level 2 after func_001f72e0. */
/* measured: opt_propagation off preserves func_001f8ea0's loop constants. */
/* measured: close opt_propagation after func_001f8ea0 probe. */
/* measured: opt_propagation off preserves func_001f8f40's loop constants. */
/* measured: close opt_propagation after func_001f8f40 probe. */
/* measured: opt_propagation off preserves func_001f8fe0's loop constants. */
/* measured: close opt_propagation after func_001f8fe0 probe. */
/* measured: opt_propagation off tested for func_001f90e0; retains loop constants. */
/* measured: close opt_propagation after func_001f90e0. */
/* measured: opt_propagation off preserves 9ac0's explicit boolean branch. */
/* measured: close opt_propagation after btlVoiceIdPacketUpdate probe. */
// FUN_001F9BE0
void func_001f9be0(void)
{
}

// FUN_001F9BF0
void btlVoiceResetPlaybackState(void) {
    memset(iGpffffb3ac + 0xB2C, 0, 0x14);
    *(s16 *)(iGpffffb3ac + 0xB30) = 3;
    *(s16 *)(iGpffffb3ac + 0xB3A) = 0;
}

// FUN_001F9C40
void btlVoiceFreePlaybackBuffers(void)
{
    if (*(s32 *)(iGpffffb3ac + 0xB34) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB34));
        *(s32 *)(iGpffffb3ac + 0xB34) = 0;
        *(u16 *)(iGpffffb3ac + 0xB2E) &= 0xFFFE;
    }
    if (*(s32 *)(iGpffffb3ac + 0xB3C) != 0) {
        jtbl_008873EC[0](*(void **)(iGpffffb3ac + 0xB3C));
        *(s32 *)(iGpffffb3ac + 0xB3C) = 0;
        *(u16 *)(iGpffffb3ac + 0xB38) &= 0xFFFE;
    }
}

// FUN_001F9CD0
void func_001f9cd0(void)
{
}

// FUN_001F9CE0
s32 func_001f9ce0(void)
{
    return 0;
}

