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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f0a50-001f0f70 */

#pragma push
#pragma pop
// FUN_001F0A50
s32 btlActionAnyTargetHitRowFlagged(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(u16 *)(target + ((u16)j << 5) + 0x10E) & 4) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: func_001f0af0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001F0AF0
s32 btlActionAnyTargetHitRowStatus(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x100000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xF8) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* measured: closes the invariant-hoist bracket for func_001f0af0. */
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail re-masks
   the counter separately for the index and for the loop bound, and writing
   both as `i & 0xFFFF` lets b210 common-subexpression them into one andi
   (nd 57, one word short). */
s32 btlActionAnyTargetSpecialHit(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xE4) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

// FUN_001F0BF0
/* Mask spelling as in func_001f0b90: `(u16)i` for the index and
   `i & 0xFFFF` for the bound, so b210 does not fold retail's two andi
   instructions into one. */
s32 btlActionAnyTargetFlagged(u8 *arg0) {
    s32 i;
    s32 n;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto test;
loop:
    if ((*(u16 *)(*(u8 **)(arg0 + ((u16)i * 4) + 0x38) + 0xDE) & 6) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

/* measured: loop-invariant probe for func_001f0c50's shared true value. */
// FUN_001F0C50
s32 btlActionSameGenusTargetsHaveDelta(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 n;
    u8 *target;
    s32 j;
    s32 innerCount;
    s32 one;

    result = 0;
    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    one = 0x10000 >> 16;
    while ((i & 0xFFFF) < n) {
        target = *(u8 **)(arg0 + ((u16)i << 2) + 0x38);
        if (target != arg0) {
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) !=
                *(u8 *)(*(u8 **)(target + 0x30) + 0xA2)) {
                return 0;
            }
            if (result == 0) {
                j = 0;
                innerCount = *(u8 *)(target + 0xD9);
                while ((j & 0xFFFF) < innerCount) {
                    if (*(s32 *)(target + ((u16)j << 5) + 0xF0) > 0) {
                        result = one;
                    }
                    if (*(s32 *)(target + ((u16)j << 5) + 0xF4) > 0) {
                        result = one;
                    }
                    if (*(s32 *)(target + ((u16)j << 5) + 0xFC) != 0) {
                        result = one;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            }
        }
        i = (i + 1) & 0xFFFF;
    }
    return result;
}

/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
// FUN_001F0D30
s32 func_001f0d30(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = *(u16 *)(arg0 + 0x6A);
    mask = 0x80000;
    goto outer_test;
outer:
    target = *(u8 **)(arg0 + ((u16)i * 4) + 0x38);
    j = 0;
    innerCount = *(u8 *)(target + 0xD9);
    goto inner_test;
inner:
    if ((*(s32 *)(target + ((u16)j << 5) + 0xFC) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
// FUN_001F0DD0
s32 func_001f0dd0(u8 *arg0, s32 arg1)
{
    s32 result;
    s32 one;
    s32 i_one;
    s32 j_one;
    s32 n;
    u8 *target;
    s32 innerCount;
    u8 *entry;
    s32 i_zero;
    s32 j_zero;

    result = 0;
    if (arg1 == 0) {
        goto path_zero;
    }
i_one = 0;
n = *(u16 *)(arg0 + 0x6A);
one = 1;
while ((i_one & 0xFFFF) < n) {
    target = *(u8 **)(arg0 + ((u16)i_one * 4) + 0x38);
    if (*(s32 *)(target + 0xE4) != 0) {
        result = 0;
        goto done;
    }
    if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
        result = 0;
        goto done;
    }
    if (result == 0) {
        innerCount = *(u8 *)(target + 0xD9);
        j_one = 0;
        goto inner_test_one;
inner_one:
        if (*(s32 *)(target + ((u16)j_one << 5) + 0xF0) < 0) {
            result = one;
            goto outer_step_one;
        }
        j_one = (j_one + 1) & 0xFFFF;
inner_test_one:
        if ((j_one & 0xFFFF) < innerCount) {
            goto inner_one;
        }
    }
outer_step_one:
    i_one = (i_one + 1) & 0xFFFF;
}
goto done;

path_zero:
    i_zero = 0;
    n = *(u16 *)(arg0 + 0x6A);
    goto outer_test_zero;
outer_zero:
    target = *(u8 **)(arg0 + ((u16)i_zero * 4) + 0x38);
    if ((*(u16 *)(target + 0xDC) & 0x106) != 0) {
        result = 1;
        goto done;
    }
    innerCount = *(u8 *)(target + 0xD9);
    j_zero = 0;
    goto inner_test_zero;
inner_zero:
    entry = target + ((u16)j_zero << 5);
    if (*(s32 *)(entry + 0xF0) == 0) {
        if (*(s32 *)(entry + 0xF8) != 0) {
            result = 1;
            goto done;
        }
    } else if (*(s32 *)(entry + 0xF0) < 0) {
        result = 1;
        goto done;
    }
    j_zero = (j_zero + 1) & 0xFFFF;
inner_test_zero:
    if ((j_zero & 0xFFFF) < innerCount) {
        goto inner_zero;
    }
    i_zero = (i_zero + 1) & 0xFFFF;
outer_test_zero:
    if ((i_zero & 0xFFFF) < n) {
        goto outer_zero;
    }
done:
    return result;
}

/* measured: close opt_loop_invariants after func_001f0dd0. */
// FUN_001F0F70
u32 func_001f0f70(u8 *arg0)
{
    u8 *target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = *(u16 *)(arg0 + 0x6A);
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(u8 **)(arg0 + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32 *)(target + 0xE4) != 0) {
            return 1;
        }
        if ((*(u16 *)(target + 0xDC) & 0x500) != 0) {
            return 1;
        }
    }
    return 0;
}

