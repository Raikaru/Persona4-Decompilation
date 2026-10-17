#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern s32 FldCharacterAnimSelect(void);
extern s32 FldRoomIsListed(u16 arg0, u16 arg1);
extern u32 RpRandom(void);
extern s32 FldStepIndex(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];



extern s32 FldShadow_DrawProjection(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         f32 farg0, f32 farg1, s32 arg4, u8 *arg5);
extern u8 D_007EFA00[];
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;





/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0017; members 00170120-00170120 */

// FUN_00170120
s32 FldPlayerRandomIdleAnimId(s32 arg0)
{
    u8 *temp_2;
    u8 *temp_4;

    FldCharacterAnimSelect();
    if (arg0 != 1)
        return 1;
    temp_2 = iGpffff9db0;
    if (FldRoomIsListed(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4)) == 1)
        return (RpRandom() % 3U) + 6;
    temp_4 = iGpffff9db0;
    if ((*(s32 *)(temp_4 + 0) == 0x44) &&
        (*(s32 *)(temp_4 + 4) == 1))
        return (RpRandom() % 3U) + 6;
    if (FldStepIndex() != 0)
        return 1;
    return (RpRandom() % 3U) + 6;
}

