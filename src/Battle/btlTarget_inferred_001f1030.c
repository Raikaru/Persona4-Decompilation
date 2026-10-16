#include "btl_hit_result_internal.h"
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
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



extern u32 datCalcRandomBelow();
extern s32 datCalcEnemyExp(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern u16 datCalcPickWeightedSkill(u8 *arg0, s32 *arg1);
extern void kAssertFail(void *arg0, s32 arg1);
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


extern void datCalcClearStatusBlocked(s32 arg0);
extern void datCalcSetHp(s32 arg0, s32 arg1);
extern void datCalcClearBadStatus(s32 arg0, s32 arg1);
extern void datCalcSetBadStatus(s32 arg0, s32 arg1);

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

/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f1030-001f2f90 */

extern s64 func_001f0260(s32 arg0);
extern s32 btlActionAnyTargetHitRowStatus(u8 *arg0);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *arg0);
extern s32 func_001f0d30(u8 *arg0);
extern s32 func_001f0dd0(u8 *arg0, s32 arg1);
extern s32 btlActionHasNoTargetClass(u32 arg0);
extern void func_001f9cd0(void);
extern s32 btlConditionMessageId(s32 arg0);
extern s32 func_001fb1f0(u8 *arg0, s32 arg1);
extern s32 func_001fb360(u8 *arg0, s32 arg1);
static inline s32 btlAnyUnitE4_001f14f0(u8 *arg0, s32 n)
{
    u16 k;

    for (k = 0; k < n; k++) {
        if (*(s32 *)(*((u8 **)arg0 + 0xE + k) + 0xE4) != 0) {
            return 1;
        }
    }
    return 0;
}
#pragma push
#pragma pop
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
/* measured: loop-invariant probe for func_001f0c50's shared true value. */
/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
/* measured: close opt_loop_invariants after func_001f0dd0. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
/* measured: opt_loop_invariants on preserves target loop preheaders and state materialisation. */
/* measured: btlTargetGroupStateMatches MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001F1030
s32 btlTargetGroupStateMatches(u8 *arg0)
{
    u8 *value;
    s32 i;
    s32 j;
    u16 count;
    u8 state;
    u8 *base;
    u8 *unit;
    u8 *pointer;

    base = *(u8 **)(arg0 + 0x30);
    state = *(u8 *)(base + 0xA2);
    if ((*(u16 *)(arg0 + 0x1A) & 1) != 0) {
        pointer = *(u8 **)(base + 0xA64);
        if (pointer != NULL && datCalcChkBadStatus((s32)pointer, 0x100) != 0) {
            if ((state & 0xFF) == 0) {
                value = (u8 *)1;
            } else {
                value = NULL;
            }
            state = (u32)value & 0xFF;
        }
    }
    count = *(u16 *)(arg0 + 0x6A);
    if ((s32)count < 2) {
        if (count != 1) {
            goto single_done;
        }
        unit = *(u8 **)(arg0 + 0x38);
        if ((*(u16 *)(unit + 0x1A) & 1) == 0) {
            return 0;
        }
        base = *(u8 **)(unit + 0x30);
        if (*(u8 *)(base + 0xA2) != (state & 0xFF)) {
            return 0;
        }
        i = 0;
        goto single_test;
    single_loop:
        if ((*(u16 *)(unit + ((u16)i << 5) + 0x10E) & 0x20) != 0) {
            return 1;
        }
        i = (i + 1) & 0xFFFF;
    single_test:
        if ((i & 0xFFFF) < *(u8 *)(unit + 0xD9)) {
            goto single_loop;
        }
    single_done:
        return 0;
    }

    j = 0;
    goto many_test;
many_loop:
    unit = *(u8 **)(arg0 + ((u16)j * 4) + 0x38);
    if ((*(u16 *)(unit + 0x1A) & 1) != 0 &&
        *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) != (state & 0xFF)) {
        return 0;
    }
    j = (j + 1) & 0xFFFF;
many_test:
    if ((j & 0xFFFF) < count) {
        goto many_loop;
    }
    return 1;
}

/* measured: close opt_loop_invariants after btlTargetGroupStateMatches probe. */
// FUN_001F11E0
s32 btlTargetIsEntryActive(s16 arg0) {
    u8 *base;

    base = iGpffffb3b8;
    return (s32)(base[(s16)arg0 * 0x28 + 2] == 1);
}

/* Matched with direct-index and global-address helper spellings. */
// FUN_001F1210
s32 btlTargetCanSelectEntry(u8 *arg0, s16 arg1, s32 arg2)
{
    s32 index;

    index = (s16)arg1;
    if (*(u8 *)((u32)addOffsetFirst(
        (u32)(index * 0x28),
        (u32)addBaseFirst((u32)iGpffffb3b8, 0)) + 2) != 1) {
        return 0;
    }
    if ((arg2 == 0) ||
        ((*(u16 *)(iGpffffb3e0 + (*(u16 *)(arg0 + 0xA4) * 0x58)) & 0x10) != 0) ||
        ((*(u16 *)((u32)addOffsetFirst(
            (u32)(index * 4),
            (u32)iGpffffb3bc) + 2) & 1) == 0)) {
        return 0;
    }
    return 1;
}

// FUN_001F12B0
s8 btlTargetClassifyTargetResult(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_3;
    s32 temp_4;
    s8 var_16;
    s8 var_2;
    s8 var_2_2;
    s8 var_2_3;

    var_16 = -1;
    temp_4 = *(s32 *)(arg1 + 8);
    if ((temp_4 != 0) || (*(s32 *)(arg1 + 0x10) & 0x037C12AA)) {
        var_16 = -2;
    }
    if ((temp_4 & 0x100000) != 0) {
        var_16 = 9;
    } else if ((*(s32 *)arg1 < 0) || ((temp_4 & 0x80000) != 0)) {
        if ((*(u16 *)(arg1 + 0x1E) & 8) == 0) {
            if ((datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                               0x100000) != 0) &&
                ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x8000) == 0)) {
                var_16 = 9;
            } else {
                var_16 = 2;
            }
        } else {
            var_16 = 2;
        }
    } else if ((*(s32 *)(arg1 + 0xC) & 0x100000) != 0) {
        var_16 = 0xB;
    }
    temp_3 = arg2 & 0xFFFF;
    switch (temp_3) {
    case 4:
    case 2:
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2 = 0x17;
        } else {
            var_2 = -4;
        }
        var_16 = var_2;
        break;
    default:
        break;
    }
    if ((*(u16 *)(arg1 + 0x1E) & 4) != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x80) != 0) {
            var_2_2 = 0x17;
        } else {
            var_2_2 = -3;
        }
        var_16 = var_2_2;
    }
    if (arg4 != 0) {
        if ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x20) != 0) {
            var_2_3 = 0x13;
        } else {
            var_2_3 = 2;
        }
        var_16 = var_2_3;
    }
    if (((*(s32 *)(arg1 + 0xC) & 0x80000) != 0) &&
        (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                       0x80000) != 0) &&
        ((*(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) & 0x200) != 0)) {
        var_16 = 0x14;
    }
    return var_16;
}

#pragma push
/* measured: normalized result/record snapshots need invariant motion for the retail 0x310 frame. */
/* measured: btlTargetResolveSelectedSkill MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: btlTargetResolveSelectedSkill MATCH -> MISMATCH without this pragma. */
#pragma opt_pulloutconstants off
/* Resolve the selected skill, recording damage, reactions and party follow-ups.
 * Byte/halfword snapshots separate the calculation and record-copy phases. */
// FUN_001F14F0
void btlTargetResolveSelectedSkill(u8 *arg0)
{
    extern s32 datCalcSkillAmount(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    /* H011: datCalc.c declares the C89-promoted s32 call interface before its K&R definition. */
    extern s32 datCalcResolveSkillHit(u8 *, u8 *, s32, s32);
    /* lint: allow H011 -- retail passes (arg0, unit, id); the empty callee ignores all arguments. */
    extern void func_001f9cd0(u8 *, u8 *, s32);
    /* lint: allow H011 -- this call supplies a u16 code; the callee dispatches only its low 16 bits. */
    extern s32 btlConditionMessageId(u16);
    /* lint: allow H011 -- retail explicitly loads flags into $a2; the callee leaves that argument unused. */
    extern s32 func_001fb1f0(u8 *, s32, s32);
    /* lint: allow H011 -- retail passes flags as the third argument; the callee leaves it unused. */
    extern s32 func_001fb360(u8 *, s32, s32);
    extern s32 datCalcResolveSkillId(u8 *, s32);
    extern s32 datCalcHitResult(u8 *, u8 *, s32, s32, s32);
    /* lint: allow H011 -- retail forwards an already zero-extended skill word; the callee consumes its low 16 bits. */
    extern s32 datCalcSkillElement(u8 *, s32);
    extern u8 *func_001efd50(u8 *);
    /* lint: allow H011 -- both IDs are halfwords here; g_data.c masks both word-formal arguments to 16 bits. */
    extern void datSetBitmapBit(u16, u16);
    extern s32 func_001eff50(u8 *);
    extern u8 *iGpffffb3cc;
    extern f32 fGpffff812c;
    extern f32 fGpffff80d4;
    s32 flags;
    f32 scale;
    u8 *unit;
    u8 *ctx;
    s32 isTen;
    s32 id;
    s8 kind;
    u8 party;
    u8 *actor;
    u8 *uctx;
    u8 *target;
    s32 va;
    s32 vb;
    s32 totalSelf;
    s32 sub;
    s32 sumA;
    s32 sumB;
    s32 bonus;
    u16 critCount;
    u16 special;
    s16 lastMsg __attribute__((aligned(16)));
    u8 j;
    u8 cntA;
    u8 cntB;
    u8 status;
    s32 r1;
    s32 r2;
    s32 counter;
    s32 hit;
    s32 flags2;
    s32 idw;
    u16 kindU;
    s32 off;
    s32 damageOffset;
    u16 *flagp;
    s32 resw;
    s32 recordResult;
    u8 *vals;
    u16 ui;
    u8 *sctx;

    lastMsg = 0;
    flags = 0;
    scale = 1.0f;
    id = *(u16 *)(arg0 + 0x6E);
    *(u16 *)(arg0 + 0x72) = id;
    if (*(u16 *)(arg0 + 0x6C) == 3) {
        flags |= 1;
    }
    off = (u32)(u16)id * 0x28;
    isTen = *(u8 *)((u8 *)addOffsetFirst(off, (u32)iGpffffb3b8) + 0x11) == 0x10;
    ctx = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
    *(u16 *)(ctx + 0x2C) = 0;
    if (*(u16 *)(arg0 + 0x6C) == 3 && *(u16 *)(arg0 + 0x70) > 0) {
        flags |= 1;
    }
    kind = (s8)datCalcSkillElement(ctx, id);
    arg0[0xD9] = 0;
    *(u16 *)(arg0 + 0xDC) = 0;
    *(s32 *)(arg0 + 0xE0) = 0;
    *(s32 *)(arg0 + 0xE4) = 0;
    arg0[0xDB] = 0;
    arg0[0xDA] = 0;
    *(s32 *)(arg0 + 0xE8) = 0;
    *(u16 *)(arg0 + 0xEC) = 0;
    *(s16 *)(arg0 + 0xEE) = -1;
    if (!(flags & 1) && func_0023df70(id) == 0) {
        switch (datCalcThresholdTrigger(ctx, id)) {
        case 1:
            *(s32 *)(arg0 + 0xE8) = 1;
            *(u16 *)(arg0 + 0xEC) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0 ? 0x36 : 0x37;
            break;
        case 2:
            *(s32 *)(arg0 + 0xE8) = 1;
            *(u16 *)(arg0 + 0xEC) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0 ? 0x38 : 0x39;
            break;
        case 4:
        case 3:
            *(s32 *)(arg0 + 0xE8) = 1;
            *(u16 *)(arg0 + 0xEC) = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 0 ? 0x3A : 0x3B;
            break;
        }
    }
    if (*(s32 *)(arg0 + 0xE8) == 1) {
        arg0[0xDB] = 0;
        return;
    }
    {
        u16 n = *(u16 *)(arg0 + 0x6A);

        if (n > 1) {
            u16 i;

            for (i = 0; i < n; i++) {
                if (*((u8 **)arg0 + 0xE + i) == arg0) {
                    break;
                }
            }
            if (i != n) {
                for (; i < *(u16 *)(arg0 + 0x6A) - 1; i++) {
                    *((u8 **)arg0 + 0xE + i) = *(u8 **)(arg0 + i * 4 + 0x3C);
                }
                ((u8 **)(arg0 + 0x38))[i] = arg0;
            }
        }
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1 && datCalcSkillTypeAllowed(id, 1) == 0) {
        u8 *res = *(u8 **)(arg0 + 0x30);
        s32 personaOffset = *(u16 *)(res + 0xA4) * 0xE8;
        f32 r = *(f32 *)(res + 0x2C) /
                ((f32)(u32)*(u16 *)((u8 *)addOffsetFirst(personaOffset, (u32)iGpffffb3cc) + 0x14) / 100.0f);

        if (!(r <= fGpffff812c)) {
            r = fGpffff812c;
        } else if (r < fGpffff80d4) {
            r = fGpffff80d4;
        }
        scale = scale * r;
    }
    damageOffset = off;
    *(u16 *)(arg0 + 0x3F4) = 0x240;
    status = 0;
    critCount = 0;
    totalSelf = 0;
    ui = 0;
    flags2 = flags | 2;
    idw = (u16)id;
    kindU = (s32)kind;
    for (; (s32)ui < *(u16 *)(arg0 + 0x6A); ui++) {
        s32 res;
        s32 selectedSub;
        s32 e4;
        s32 mask;
        s32 mask2;
        u8 *ent;
        s32 m80;
        s32 n80;
        s32 msg;
        unit = *(u8 **)(arg0 + (u32)ui * 4 + 0x38);
        actor = unit;
        uctx = *(u8 **)(*(u8 **)(unit + 0x30) + 0xA64);
        sumA = 0;
        sumB = 0;
        counter = 0;
        hit = 0;

        *(u16 *)(unit + 0x3F4) = 0x240;
        *(u16 *)(uctx + 0x2C) = 0;
        unit[0xD9] = 0;
        *(u16 *)(unit + 0xDC) = 0;
        *(s32 *)(unit + 0xE0) = 0;
        *(s32 *)(unit + 0xE4) = 0;
        unit[0xDB] = 0;
        unit[0xDA] = 0;
        *(s32 *)(unit + 0xE8) = 0;
        *(u16 *)(unit + 0xEC) = 0;
        *(s16 *)(unit + 0xEE) = -1;
        res = datCalcResolveSkillHit(ctx, uctx, id, flags) & 0xFFFF;
        if (res == 0x200) {
            u16 reflectedResult;

            actor = arg0;
            target = ctx;
            reflectedResult = datCalcResolveSkillHit(ctx, ctx, id, flags2) & 0xFFFF;
            switch (reflectedResult) {
            case 0x200:
                reflectedResult = 0x100;
                res = reflectedResult;
                break;
            case 2:
            case 4:
                reflectedResult = 1;
                res = reflectedResult;
                break;
            default:
                res = reflectedResult;
                break;
            }
            *(s32 *)(unit + 0xE4) = 1;
        } else {
            target = uctx;
        }
        if (*(s32 *)(unit + 0xE4) != 0) {
            selectedSub = 1;
        } else {
            selectedSub = datCalcHitResult(ctx, target, id, res, flags);
        }
        sub = selectedSub & 0xFFFF;
        if (func_0023df70(id) != 0) {
            cntA = 1;
            func_0023e1f0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
            cntB = datCalcSkillValueBase(ctx, sub);
        } else {
            cntA = datCalcRollSkillValue(ctx, id, sub);
            cntB = 1;
        }
        e4 = *(s32 *)(unit + 0xE4);
        if (e4 != 0) {
            cntA = 1;
            cntB = 1;
        } else {
            switch ((u16)res) {
            case 0x200:
            case 0x400:
            case 2:
            case 4:
            case 0x100:
                cntA = 1;
                cntB = 1;
                break;
            }
        }
        if (e4 == 0) {
            r1 = datCalcSkillAllowedForMode(ctx, target, id, res, sub, flags);
            r2 = datCalcRollSupportSkillHit(ctx, uctx, id, res, sub, flags);
            if (r1 != 0 || func_00232710(uctx, 0x100000) != 0) {
                counter = datCalcRollSkillChance(ctx, uctx, id, res, sub, flags);
            }
        } else {
            r1 = 0;
            r2 = 0;
        }
        mask = datCalcStatusEffectResult(id, ctx, target, res, sub, flags);
        mask2 = datCalcSureHitResult(id, ctx, target, res, sub, flags);
        ent = (u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8);
        if (ent[0x18] == 1 && (*(u32 *)(ent + 0x1C) & 0x80000) && ent[0x24] != 9 && !(mask & 0x80000)) {
            r1 = 0;
        }
        if (mask == 0x80000) {
            *(s32 *)(unit + 0xE0) = 1;
        }
        special = func_001fb360(unit, idw, flags);
        resw = (u16)res;
        if (resw == 1 && *(s32 *)(unit + 0xE4) == 0 && special == 0) {
            bonus = *(s32 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x20);
        } else {
            bonus = 0;
        }
        *(u16 *)(unit + 0xDC) = res;
        *(u16 *)(unit + 0xDE) = sub;
        recordResult = resw;
        j = 0;
        m80 = mask & 0x80000;
        n80 = !(mask2 & 0x80000);
        while (j < cntA) {
            u16 *resultFlags;
            u16 *pa;
            u16 *pb;
            s32 *pm;
            s32 x;
            u8 t;
            s32 nj;
            flagp = (u16 *)(unit + (j << 5) + 0x10E);
            *flagp = 0;
            pa = (u16 *)(unit + (j << 5) + 0x108);
            *pa = 0;
            pb = (u16 *)(unit + (j << 5) + 0x10A);
            *pb = 0;
            va = datCalcSkillAmount(id, ctx, target, 1, res, sub, flags, 1);
            vb = datCalcSkillAmount(id, ctx, target, 1, res, sub, flags, 2);
            if ((s32)((f32)va * scale) != 0) {
                va = (f32)va * scale;
            }
            {
                f32 value = (f32)vb;
                f32 one = 1.0f;

                if ((s32)(value * one) != 0) {
                    vb = value * one;
                }
            }
            pm = (s32 *)(unit + (j << 5) + 0xF8);
            *pm = mask;
            *(s32 *)(unit + (j << 5) + 0xFC) = mask2;
            x = datCalcSkillRoll(id, ctx, target, flags);
            t = *(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x11);
            switch (t) {
            case 0xC:
            case 0xD:
                *pa = func_0043c6a0(va);
                break;
            }
            t = *(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x14);
            switch (t) {
            case 0xC:
            case 0xD:
                *pb = func_0043c6a0(vb);
                break;
            }
            *(s32 *)(unit + (j << 5) + 0x100) = bonus;
            *(s32 *)(unit + (j << 5) + 0x104) = x;
            vals = unit + (j << 5) + 0xF0;
            *(s32 *)(unit + (j << 5) + 0xF0) = va;
            *(s32 *)(unit + (j << 5) + 0xF4) = vb;
            sumA += va;
            sumB += vb;
            if (actor == arg0) {
                totalSelf += va;
            }
            switch (*(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x24)) {
            case 2:
                *flagp |= 0x20;
                break;
            }
            if (*(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8)) & 1) {
                *flagp |= 0x40;
            }
            if (isTen) {
                *flagp |= 8;
            }
            if (actor != arg0) {
                hit = func_002428f0(target, sumA) != 0;
                if (!hit) {
                    hit = m80 != 0;
                    if (hit) {
                        hit = n80 != 0;
                    }
                }
                resultFlags = flagp;
            } else {
                hit = func_002428f0(target, totalSelf) != 0;
                if (!hit) {
                    hit = m80 != 0;
                    if (hit) {
                        hit = n80 != 0;
                    }
                }
                resultFlags = flagp;
            }
            nj = j + 1;
            if (nj == cntA || hit) {
                if (r1 != 0) {
                    *pm |= 0x100000;
                } else if (((sumA < 0 || recordResult == 0x100 || recordResult == 0x400) && func_00232710(target, 0x100000) != 0) ||
                           (*(s32 *)(unit + 0xE4) == 1 && func_00232710(uctx, 0x100000) != 0)) {
                    *resultFlags |= 1;
                    if (*(s32 *)(unit + 0xE4) == 1 || recordResult == 0x100 || recordResult == 0x400) {
                        *resultFlags |= 2;
                    }
                }
                if (counter != 0 && sumA < 0 && mask == 0) {
                    *pm |= 1;
                } else {
                    counter = 0;
                }
                if (r2 != 0) {
                    *resultFlags |= 4;
                }
                if (recordResult != 1 || *(s32 *)(unit + 0xE4) == 1 || r2 == 1) {
                    status |= 2;
                } else if (r1 != 0) {
                    critCount++;
                }
            }
            if (hit) {
                s32 v;

                if (*(u16 *)(actor + 0x3F4) == 0x240) {
                    v = datCalcResolveSkillId(*(u8 **)(*(u8 **)(actor + 0x30) + 0xA64), id);
                } else {
                    v = (s16)*(u16 *)(actor + 0x3F4);
                }
                if ((s16)v >= 0) {
                    u8 *slot;

                    *(u16 *)(actor + 0x3F4) = (s16)v;
                    slot = unit + (u32)j * sizeof(LargeBattleHitResult);
                    *resultFlags |= 0x10;
                    slot[0x10C] = btlTargetClassifyTargetResult(actor, vals, res, sub, 0);
                } else {
                    u8 *reactionBase = unit + (u32)j * sizeof(LargeBattleHitResult);

                    reactionBase[0x10C] = btlTargetClassifyTargetResult(actor, vals, res, sub, 1);
                    *(s32 *)(unit + 0xE0) = 1;
                    if (arg0 == actor) {
                        *pa = 0;
                    }
                }
                cntA = nj;
                break;
            }
            {
                u8 *reactionBase = unit + (u32)j * sizeof(LargeBattleHitResult);

                reactionBase[0x10C] = btlTargetClassifyTargetResult(actor, vals, res, sub, 0);
            }
            j++;
        }
        e4 = *(s32 *)(unit + 0xE4);
        if (e4 == 1 || (recordResult & 0x700) || sumA != 0 || sumB != 0 || mask != 0 || mask2 != 0) {
            u8 *res30;

            if (e4 == 1 || (recordResult & 0x500)) {
                func_001f9cd0(arg0, unit, id);
            }
            res30 = *(u8 **)(unit + 0x30);
            if (res30[0xA2] == 1 && (s32)kind < 8 && !(recordResult & 6)) {
                datSetBitmapBit(*(u16 *)(res30 + 0xA4), kindU);
            }
        }
        if (*(u16 *)(ctx + 0x2C) != 0) {
            lastMsg = *(u16 *)(ctx + 0x2C);
        } else if (*(u16 *)(uctx + 0x2C) != 0) {
            lastMsg = *(u16 *)(uctx + 0x2C);
        }
        if (special != 0) {
            msg = (s16)btlConditionMessageId(special);
            arg0[0xD8] |= 1;
        } else if (!(recordResult & 6)) {
            msg = (s16)func_001f0260(idw);
        } else {
            msg = 0;
        }
        if (msg != 0) {
            *(s16 *)(unit + 0xEC) = msg;
        } else if (lastMsg != 0) {
            *(s16 *)(unit + 0xEC) = lastMsg;
        } else if (!hit) {
            if (counter != 0 || (mask & 1)) {
                *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x18 : 0x19;
            } else if (mask != 0) {
                if (mask & 2) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x16 : 0x17;
                } else if (mask & 4) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x14 : 0x15;
                } else if (mask & 8) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x1C : 0x1D;
                } else if (mask & 0x10) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x12 : 0x13;
                } else if (mask & 0x20) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x10 : 0x11;
                } else if (mask & 0x40) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0x1A : 0x1B;
                } else if (mask & 0x80) {
                    *(u16 *)(unit + 0xEC) = *(u8 *)(*(u8 **)(unit + 0x30) + 0xA2) == 0 ? 0xE : 0xF;
                }
            }
        }
        unit[0xD9] = cntA;
        unit[0xDA] = cntB;
    }
    if (critCount) {
        status |= 1;
        status &= ~2;
    }
    if (*(s16 *)(arg0 + 0xEE) == -1) {
        *(s16 *)(arg0 + 0xEE) = func_001f0610(idw);
    }
    if (*(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x24) == 6) {
        *(u16 *)(arg0 + 0x1A) |= 0x4000;
    }
    {
        u16 t = func_001fb1f0(arg0, idw, flags);

        if (t != 0 && *(s32 *)(arg0 + 0xE8) != 1) {
            *(s16 *)(arg0 + 0xEC) = btlConditionMessageId(t);
        }
    }
    arg0[0xDB] = status;
    party = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    if (party == 1 && *(u16 *)(arg0 + 0x6A) == 1 && *(u8 **)(arg0 + 0x38) == *(u8 **)(iGpffffb3ac + 0x170) &&
        *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xE0) == 1) {
        s32 n = *(u16 *)(arg0 + 0x6A);
        s32 found;
        u8 *sum;

        found = btlAnyUnitE4_001f14f0(arg0, n);
        if (found) {
            goto other;
        }
        sum = func_001efd50(arg0);
        *(u8 **)(arg0 + 0x88) = sum;
        if (sum == NULL) {
            goto finished;
        }
        {
            s32 totalDamage;
            u8 q;
            s32 flagHit;
            s32 cnt;
            u8 *first = *(u8 **)(arg0 + 0x38);
            sctx = *(u8 **)(*(u8 **)(sum + 0x30) + 0xA64);

            if (*(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x24) == 0xD) {
                *(s16 *)(sum + 0xEC) = *(s16 *)(first + 0xEC);
            } else {
                *(s16 *)(sum + 0xEC) = 0;
            }
            arg0[0xDB] = 0;
            first[0xDB] = 0;
            *(u16 *)(first + 0xDC) = 1;
            *(u16 *)(first + 0xDE) = 1;
            *(s32 *)(first + 0xE0) = 0;
            *(s32 *)(first + 0xE4) = 0;
            *(s32 *)(first + 0xE8) = 0;
            *(u16 *)(first + 0xEC) = 0;
            *(s16 *)(first + 0xEE) = -1;
            flagHit = 0;
            totalDamage = 0;
            cnt = first[0xD9];
            for (q = 0; q < cnt; q++) {
                u8 inputIndex = q;
                u8 *s = first + inputIndex * sizeof(LargeBattleHitResult);
                s32 v = *(s32 *)(s + 0xF0);
                u16 *copiedFlags;
                u8 resetIndex;

                totalDamage += v;
                if (func_002428f0(sctx, totalDamage) != 0 ||
                    ((*(u32 *)(s + 0xF8) & 0x80000) && !(*(u32 *)(s + 0xFC) & 0x80000))) {
                    flagHit = 1;
                }
                resetIndex = q;
                s = first + resetIndex * sizeof(LargeBattleHitResult);
                func_0043f9c8((u8 *)(u32)s + 0xF0, 0, 0x20);
                *(s32 *)((u8 *)(u32)s + 0xF0) = v;
                s[0x10C] = 2;
                copiedFlags = (u16 *)(s + 0x10E);
                *copiedFlags |= 0x200;
                if (*(u8 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x24) == 0xD) {
                    ((LargeBattleHitResult *)(first + 0xF0))[q].addedStatus |= 0x80000;
                    ((LargeBattleHitResult *)(first + 0xF0))[q].removedStatus &= ~0x80000;
                    first[0xD9] = q + 1;
                    return;
                }
                if (flagHit != 0) {
                    ((LargeBattleHitResult *)(first + 0xF0))[q].addedStatus |= 0x80000;
                    *(u16 *)(*(u8 **)(arg0 + 0x88) + 0x3F4) = 0;
                    *copiedFlags |= 0x10;
                    first[0xD9] = q + 1;
                    return;
                }
            }
        }
        return;
    }
other:
    if ((arg0[0xDB] & 1) && !(*(u16 *)(arg0 + 0x18) & 4) && party == 0 && *(u16 *)(arg0 + 0x6A) > 0) {
        s16 cnt = 0;
        u16 m;
        u8 *q;
        u8 *p170;

        for (m = 0; m < *(u16 *)(arg0 + 0x6A); m++) {
            u8 *u = *(u8 **)(arg0 + (u32)m * 4 + 0x38);

            if (*(s32 *)(u + 0xE0) == 1 && func_00232710(*(u8 **)(*(u8 **)(u + 0x30) + 0xA64), 0x100000) == 0) {
                cnt++;
            } else {
                u8 n = 0;
                s32 count = u[0xD9];
                for (; n < count; n++) {
                    if (*(u8 *)(*(u8 **)(u + 0x30) + 0xA2) == 1 && (*(u32 *)(u + ((u32)n << 5) + 0xF8) & 0x100000)) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        for (q = *(u8 **)(iGpffffb3ac + 0x174); q != NULL; q = *(u8 **)(q + 0x450)) {
            if (*(u16 *)(q + 0x1A) & 1) {
                u8 *r = *(u8 **)(q + 0x30);

                if (r[0xA2] == 1 && (*(u32 *)(r + 0x9C) & 8) && func_002428f0(*(u8 **)(r + 0xA64), 0) == 0 &&
                    func_00232710(*(u8 **)(*(u8 **)(q + 0x30) + 0xA64), 0x100000) == 0) {
                    cnt--;
                }
            }
        }
        p170 = *(u8 **)(iGpffffb3ac + 0x170);
        if (p170 != NULL && func_00232710(*(u8 **)(*(u8 **)(p170 + 0x30) + 0xA64), 0x100117) != 0) {
            cnt = 1;
        }
        if (cnt != 0) {
            u8 *e = (u8 *)(u32)func_001eff50(arg0);

            if (e != NULL) {
                u16 n = *(u16 *)(arg0 + 0x6A);

                if (n > 1) {
                    *(u8 **)(e + 0x90) = ((u8 **)(arg0 + 0x38))[datCalcRandomBelow(n)];
                } else {
                    *(u8 **)(e + 0x90) = *(u8 **)(arg0 + 0x38);
                }
                if (*(s32 *)(*(u8 **)(e + 0x90) + 0xE0) == 0) {
                    *(u8 **)(arg0 + 0x8C) = e;
                    *(u16 *)(e + 0x16) = 0xD;
                    btlActionActiveListPush(e);
                }
            } else if (func_001ef9c0(arg0) != 0) {
                *(u16 *)(arg0 + 0x16) = 0xC;
                btlActionActiveListPush(arg0);
            }
        }
    }
finished:
    return;
}

#pragma pop
/* measured: the second loop's slot index is `(u16)var_8_2 * 4` (its own mask, not CSE'd
   with the loop test's `& 0xFFFF`) while the stored count is `(var_8_2 & 0xFFFF) + 1`
   (CSE'd with the test, retail's $a0); the counter store address is offset-first
   integer arithmetic `temp_6_2 + (u32)D_0076449C`. */
// FUN_001F2CC0
void btlTargetRecordDefeatReward(u8 *arg0)
{
    s32 sp3C;
    u8 *base;
    u8 *entry;
    u8 *base2;
    u8 *slot;
    s32 temp_6;
    s32 temp_6_2;
    s32 var_8;
    s64 var_7;
    s32 var_8_2;
    u16 temp_4;
    u16 var_16;
    u8 *temp_16;

    temp_4 = *(u16 *)(arg0 + 0x1A);
    if ((temp_4 & 1) != 0) {
        temp_16 = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(temp_16 + 0xA2) == 1) {
            if (*(u16 *)(temp_16 + 0xA4) >= 0x150) {
                kAssertFail((void *)D_0060AB08, 0x4F5);
            }
            temp_4 = *(u16 *)(arg0 + 0x1A);
            if ((temp_4 & 0x20) == 0) {
                *(u16 *)(arg0 + 0x1A) = (u16)(temp_4 | 0x20);
                *(s32 *)(D_0076449C + 0xCB0) =
                    *(s32 *)(D_0076449C + 0xCB0) +
                    datCalcEnemyExp(*(s32 *)(temp_16 + 0xA64));
                *(s32 *)(D_0076449C + 0xCB4) =
                    *(s32 *)(D_0076449C + 0xCB4) +
                    func_002439c0(*(s32 *)(temp_16 + 0xA64));
                var_16 = (u16)(datCalcPickWeightedSkill(
                    *(u8 **)(temp_16 + 0xA64), &sp3C) & 0xFFFF);
                if ((sp3C != 1) &&
                    (*(u16 *)(arg0 + 0x80) != 0) &&
                    ((s32)(datCalcRandomBelow(0x64) & 0xFF) <
                     (s32)*(u8 *)(arg0 + 0x82))) {
                    var_16 = *(u16 *)(arg0 + 0x80);
                }
                temp_6 = var_16 & 0xFFFF;
                if (temp_6 != 0) {
                    var_7 = 0;
                    var_8 = 0;
                    base = D_0076449C;
                    while ((var_8 & 0xFFFF) < 3) {
                        entry = base + ((u16)var_8 * 4);
                        if (*(u16 *)(entry + 0xCD0) == temp_6) {
                            *(s16 *)(entry + 0xCD2) =
                                (s16)(*(s16 *)(entry + 0xCD2) + 1);
                            var_7 = 1;
                            break;
                        }
                        var_8 = (var_8 + 1) & 0xFFFF;
                    }
                    if (var_7 == 0) {
                        var_8_2 = 0;
                        base2 = D_0076449C;
                        while ((var_8_2 & 0xFFFF) < 3) {
                            temp_6_2 = (u16)var_8_2 * 4;
                            slot = base2 + temp_6_2;
                            if (*(u16 *)(slot + 0xCD0) == 0) {
                                *(u16 *)(slot + 0xCD0) = var_16;
                                *(s16 *)(temp_6_2 + (u32)D_0076449C + 0xCD2) = 1;
                                *(s32 *)(D_0076449C + 0xCDC) = (var_8_2 & 0xFFFF) + 1;
                                return;
                            }
                            var_8_2 = (var_8_2 + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
    }
}

// FUN_001F2EB0
void btlTargetSetDefeatState(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    datCalcClearStatusBlocked(*(s32 *)(work + 0xA64));
    if (arg1 == 1) {
        if (*(u16 *)(arg0 + 0x3F4) != 0x154) {
            datCalcSetHp(*(s32 *)(work + 0xA64), 1);
        }
        datCalcClearBadStatus(*(s32 *)(work + 0xA64), 0x80000);
        *(s32 *)(work + 0x9C) |= 0x10;
        return;
    }
    datCalcSetHp(*(s32 *)(work + 0xA64), 0);
    datCalcClearBadStatus(*(s32 *)(work + 0xA64), 0xFFFFFF);
    datCalcSetBadStatus(*(s32 *)(work + 0xA64), 0x80000);
    value = *(s32 *)(work + 0x9C) | 1;
    *(s32 *)(work + 0x9C) = value;
    *(s32 *)(work + 0x9C) = value & ~0x10;
}

// FUN_001F2F90
s32 btlTargetIsSlotAlive(u8 *arg0) {
    u8 *p;

    p = iGpffffb3b8 + *(s16 *)(arg0 + 0x6E) * 40;
    if ((p[0] & 2) != 0) {
        return 0;
    }
    return (p[0x24] ^ 6) != 0;
}

