#include "datCalc_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
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

extern void *memset(void *destination, int value, size_t count);
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



extern u32 datCalcRandomBelow();
extern s32 datCalcEnemyExp(s32 unit);
extern s32 datCalcEnemyMoney(s32 unit);
extern u16 datCalcPickWeightedSkill(u8 *unit, s32 *usedFlaggedSkill);
extern void kAssertFail(void *file, s32 line);
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


extern void datCalcClearStatusBlocked(s32 unitFlags);

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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f1030-001f2f90 */

extern s64 btlTargetSkillEffectCode(s32 skill);
extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
extern s32 btlActionHasNoTargetClass(u32 action);
extern void func_001f9cd0(void);
extern s32 btlConditionMessageId(s32 condition);
extern s32 btlBuffMaskCheckEntries(u8 *action, s32 skillId);
extern s32 btlBuffMaskCheckUnit(u8 *action, s32 skillId);
static inline s32 btlTargetAnySpecialHit(u8 *arg0, s32 n)
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
/* Check the selected targets against the actor group, including confusion and hit-row flags. */
/* measured: remaining target-pointer loads are raw because typed array substitutions changed MATCH. */
// FUN_001F1030
s32 btlTargetGroupStateMatches(u8 *context)
{
    u8 *value;
    s32 i;
    s32 j;
    u16 count;
    u8 state;
    u8 *base;
    u8 *unit;
    u8 *pointer;

    base = (u8 *)((BtlAction *)context)->unit;
    state = ((BtlUnit *)base)->genus;
    if ((((BtlAction *)context)->unk_1a & 1) != 0) {
        pointer = (u8 *)((BtlUnit *)base)->datUnit;
        if (pointer != NULL && datCalcChkBadStatus((DatUnit *)pointer, 0x100) != 0) {
            if ((state & 0xFF) == 0) {
                value = (u8 *)1;
            } else {
                value = NULL;
            }
            state = (u32)value & 0xFF;
        }
    }
    count = ((BtlAction *)context)->unk_6a;
    if ((s32)count < 2) {
        if (count != 1) {
            goto single_done;
        }
        unit = (u8 *)((BtlAction **)((BtlAction *)context)->unk_38)[0];
        if ((((BtlAction *)unit)->unk_1a & 1) == 0) {
            return 0;
        }
        base = (u8 *)((BtlAction *)unit)->unit;
        if (((BtlUnit *)base)->genus != (state & 0xFF)) {
            return 0;
        }
        i = 0;
        goto single_test;
    single_loop:
        if ((((BtlAction *)unit)->targetBlock.hitRows[(u16)i].flags & 0x20) != 0) {
            return 1;
        }
        i = (i + 1) & 0xFFFF;
    single_test:
        if ((i & 0xFFFF) < ((BtlAction *)unit)->targetBlock.hitRowCount) {
            goto single_loop;
        }
    single_done:
        return 0;
    }

    j = 0;
    goto many_test;
many_loop:
    unit = *(u8 **)(context + ((u16)j * 4) + 0x38);
    if ((((BtlAction *)unit)->unk_1a & 1) != 0 &&
        ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus != (state & 0xFF)) {
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
/* Return whether this skill-table entry uses the selectable damage class. */
// FUN_001F11E0
s32 btlTargetIsEntryActive(s16 context) {
    u8 *base;

    base = iGpffffb3b8;
    return (s32)(base[(s16)context * 0x28 + 2] == 1);
}

/* Matched with direct-index and global-address helper spellings. */
/* Check skill class and the unit/persona selection restrictions. */
/* Raw selection-table fields retain independent 0x28/0x58/4-byte strides and the measured offset-first address order. */
// FUN_001F1210
s32 btlTargetCanSelectEntry(u8 *context, s16 value, s32 option)
{
    s32 index;

    index = (s16)value;
    if (*(u8 *)((u32)addOffsetFirst(
        (u32)(index * 0x28),
        (u32)addBaseFirst((u32)iGpffffb3b8, 0)) + 2) != 1) {
        return 0;
    }
    if ((option == 0) ||
        ((*(u16 *)(iGpffffb3e0 + (((BtlUnit *)context)->charId * 0x58)) & 0x10) != 0) ||
        ((*(u16 *)((u32)addOffsetFirst(
            (u32)(index * 4),
            (u32)iGpffffb3bc) + 2) & 1) == 0)) {
        return 0;
    }
    return 1;
}

/* Choose the target reaction from a hit record, outcome, and defeat override. */
/* measured: the two remaining action-unit reloads must stay raw; typed fields changed the instruction comparison. */
// FUN_001F12B0
s8 btlTargetClassifyTargetResult(u8 *action, u8 *hitResult, s32 hitOutcome, s32 unusedSubresult, s32 defeated)
{
    s32 outcome;
    s32 addedStatus;
    s8 reaction;
    s8 outcomeReaction;
    s8 supportReaction;
    s8 defeatReaction;

    reaction = -1;
    addedStatus = ((LargeBattleHitResult *)hitResult)->addedStatus;
    if ((addedStatus != 0) || (((LargeBattleHitResult *)hitResult)->field10 & 0x037C12AA)) {
        reaction = -2;
    }
    if ((addedStatus & 0x100000) != 0) {
        reaction = 9;
    } else if ((*(s32 *)hitResult < 0) || ((addedStatus & 0x80000) != 0)) {
        if ((((LargeBattleHitResult *)hitResult)->flags & 8) == 0) {
            if ((datCalcChkBadStatus((DatUnit *)((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->datUnit,
                               0x100000) != 0) &&
                ((((BtlUnit *)*(u8 **)(action + 0x30))->flags3 & 0x8000) == 0)) {
                reaction = 9;
            } else {
                reaction = 2;
            }
        } else {
            reaction = 2;
        }
    } else if ((((LargeBattleHitResult *)hitResult)->removedStatus & 0x100000) != 0) {
        reaction = 0xB;
    }
    outcome = hitOutcome & 0xFFFF;
    switch (outcome) {
    case 4:
    case 2:
        if ((((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->flags3 & 0x80) != 0) {
            outcomeReaction = 0x17;
        } else {
            outcomeReaction = -4;
        }
        reaction = outcomeReaction;
        break;
    default:
        break;
    }
    if ((((LargeBattleHitResult *)hitResult)->flags & 4) != 0) {
        if ((((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->flags3 & 0x80) != 0) {
            supportReaction = 0x17;
        } else {
            supportReaction = -3;
        }
        reaction = supportReaction;
    }
    if (defeated != 0) {
        if ((((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->flags3 & 0x20) != 0) {
            defeatReaction = 0x13;
        } else {
            defeatReaction = 2;
        }
        reaction = defeatReaction;
    }
    if (((((LargeBattleHitResult *)hitResult)->removedStatus & 0x80000) != 0) &&
        (datCalcChkBadStatus((DatUnit *)((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->datUnit,
                       0x80000) != 0) &&
        ((((BtlUnit *)*(u8 **)(action + 0x30))->flags3 & 0x200) != 0)) {
        reaction = 0x14;
    }
    return reaction;
}

#pragma push
/* measured: normalized result/record snapshots need invariant motion for the retail 0x310 frame. */
/* measured: btlTargetResolveSelectedSkill MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: btlTargetResolveSelectedSkill MATCH -> MISMATCH without this pragma. */
#pragma opt_pulloutconstants off
/* Resolve the selected skill, recording damage, reactions and party follow-ups.
 * Byte/halfword snapshots separate the calculation and record-copy phases. */
/* Resolve the selected skill into per-target hit rows, messages, and party follow-up actions. */
/* measured: remaining action/result reloads stay raw after per-access typing changed MATCH. DatUnit +0x2C is an opaque message slot; action +0x3F4 overlaps the final hit row, and skill +0x1C/+0x20 remain opaque table words. */
// FUN_001F14F0
void btlTargetResolveSelectedSkill(u8 *context)
{
    extern s32 datCalcSkillAmount(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    /* H011: datCalc.c declares the C89-promoted s32 call interface before its K&R definition. */
    extern s32 datCalcResolveSkillHit(u8 *, u8 *, s32, s32);
    /* lint: allow H011 -- retail passes (context, unit, id); the empty callee ignores all arguments. */
    extern void func_001f9cd0(u8 *, u8 *, s32);
    /* lint: allow H011 -- this call supplies a u16 code; the callee dispatches only its low 16 bits. */
    extern s32 btlConditionMessageId(u16);
    /* lint: allow H011 -- retail explicitly loads flags into $a2; the callee leaves that argument unused. */
    extern s32 btlBuffMaskCheckEntries(u8 *, s32, s32);
    /* lint: allow H011 -- retail passes flags as the third argument; the callee leaves it unused. */
    extern s32 btlBuffMaskCheckUnit(u8 *, s32, s32);
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
    u8 *attacker;
    s32 isTen;
    s32 id;
    s8 element;
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
    id = ((BtlAction *)context)->unk_6e;
    ((BtlActionParameters *)((BtlAction *)context)->unk_70)->resolvedSkill = id;
    if (((BtlAction *)context)->unk_6c == 3) {
        flags |= 1;
    }
    off = (u32)(u16)id * 0x28;
    isTen = ((DatSkillEntry *)(u8 *)addOffsetFirst(off, (u32)iGpffffb3b8))->effectKind == 0x10;
    attacker = (u8 *)((BtlUnit *)*(u8 **)(context + 0x30))->datUnit;
    *(u16 *)(attacker + 0x2C) = 0;
    if (*(u16 *)(context + 0x6C) == 3 && *(u16 *)(context + 0x70) > 0) {
        flags |= 1;
    }
    element = (s8)datCalcSkillElement(attacker, id);
    context[0xD9] = 0;
    ((BtlAction *)context)->targetBlock.hitOutcome = 0;
    ((BtlAction *)context)->targetBlock.reactionFlag = 0;
    ((BtlAction *)context)->targetBlock.specialHitFlag = 0;
    context[0xDB] = 0;
    context[0xDA] = 0;
    ((BtlActionResolutionMessage *)((BtlAction *)context)->targetBlock.unk_e8)->blocked = 0;
    ((BtlActionResolutionMessage *)((BtlAction *)context)->targetBlock.unk_e8)->messageCode = 0;
    ((BtlActionResolutionMessage *)((BtlAction *)context)->targetBlock.unk_e8)->unk06 = -1;
    if (!(flags & 1) && datCalcUsesWeaponProperties(id) == 0) {
        switch (datCalcThresholdTrigger(attacker, id)) {
        case 1:
            *(s32 *)(context + 0xE8) = 1;
            *(u16 *)(context + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus == 0 ? 0x36 : 0x37;
            break;
        case 2:
            *(s32 *)(context + 0xE8) = 1;
            *(u16 *)(context + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus == 0 ? 0x38 : 0x39;
            break;
        case 4:
        case 3:
            *(s32 *)(context + 0xE8) = 1;
            *(u16 *)(context + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus == 0 ? 0x3A : 0x3B;
            break;
        }
    }
    if (*(s32 *)(context + 0xE8) == 1) {
        context[0xDB] = 0;
        return;
    }
    {
        u16 n = ((BtlAction *)context)->unk_6a;

        if (n > 1) {
            u16 i;

            for (i = 0; i < n; i++) {
                if (*((u8 **)context + 0xE + i) == context) {
                    break;
                }
            }
            if (i != n) {
                for (; i < *(u16 *)(context + 0x6A) - 1; i++) {
                    *((u8 **)context + 0xE + i) = *(u8 **)(context + i * 4 + 0x3C);
                }
                ((u8 **)(context + 0x38))[i] = context;
            }
        }
    }
    // Persona-owned unit (state 1) using a skill type it cannot use: scale = scale * r, where r = res[+0x2C] / (persona table[+0x14] / 100) clamped to [fGpffff80d4, fGpffff812c]; [inferred].
    if (((BtlUnit *)*(u8 **)(context + 0x30))->genus == 1 && datCalcSkillTypeAllowed(id, 1) == 0) {
        u8 *res = (u8 *)((BtlAction *)context)->unit;
        s32 personaOffset = ((BtlUnit *)res)->charId * 0xE8;
        f32 r = ((BtlUnit *)res)->scale /
                ((f32)(u32)*(u16 *)((u8 *)addOffsetFirst(personaOffset, (u32)iGpffffb3cc) + 0x14) / 100.0f);

        if (!(r <= fGpffff812c)) {
            r = fGpffff812c;
        } else if (r < fGpffff80d4) {
            r = fGpffff80d4;
        }
        scale = scale * r;
    }
    damageOffset = off;
    *(u16 *)(context + 0x3F4) = 0x240;
    status = 0;
    critCount = 0;
    totalSelf = 0;
    ui = 0;
    flags2 = flags | 2;
    idw = (u16)id;
    kindU = (s32)element;
    for (; (s32)ui < *(u16 *)(context + 0x6A); ui++) {
        s32 res;
        s32 selectedSub;
        s32 e4;
        s32 mask;
        s32 mask2;
        u8 *ent;
        s32 m80;
        s32 n80;
        s32 msg;
        unit = *(u8 **)(context + (u32)ui * 4 + 0x38);
        actor = unit;
        uctx = (u8 *)((BtlUnit *)*(u8 **)(unit + 0x30))->datUnit;
        sumA = 0;
        sumB = 0;
        counter = 0;
        hit = 0;

        *(u16 *)(unit + 0x3F4) = 0x240;
        *(u16 *)(uctx + 0x2C) = 0;
        unit[0xD9] = 0;
        ((BtlAction *)unit)->targetBlock.hitOutcome = 0;
        ((BtlAction *)unit)->targetBlock.reactionFlag = 0;
        ((BtlAction *)unit)->targetBlock.specialHitFlag = 0;
        unit[0xDB] = 0;
        unit[0xDA] = 0;
        ((BtlActionResolutionMessage *)((BtlAction *)unit)->targetBlock.unk_e8)->blocked = 0;
        ((BtlActionResolutionMessage *)((BtlAction *)unit)->targetBlock.unk_e8)->messageCode = 0;
        ((BtlActionResolutionMessage *)((BtlAction *)unit)->targetBlock.unk_e8)->unk06 = -1;
        res = datCalcResolveSkillHit(attacker, uctx, id, flags) & 0xFFFF;
        if (res == 0x200) {
            u16 reflectedResult;

            actor = context;
            target = attacker;
            reflectedResult = datCalcResolveSkillHit(attacker, attacker, id, flags2) & 0xFFFF;
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
            selectedSub = datCalcHitResult(attacker, target, id, res, flags);
        }
        sub = selectedSub & 0xFFFF;
        if (datCalcUsesWeaponProperties(id) != 0) {
            cntA = 1;
            datCalcGetCharacterTableKind((u8 *)((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->datUnit);
            cntB = datCalcSkillValueBase(attacker, sub);
        } else {
            cntA = datCalcRollSkillValue(attacker, id, sub);
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
            r1 = datCalcSkillAllowedForMode(attacker, target, id, res, sub, flags);
            r2 = datCalcRollSupportSkillHit(attacker, uctx, id, res, sub, flags);
            if (r1 != 0 || datCalcChkBadStatus((DatUnit *)uctx, 0x100000) != 0) {
                counter = datCalcRollSkillChance(attacker, uctx, id, res, sub, flags);
            }
        } else {
            r1 = 0;
            r2 = 0;
        }
        mask = datCalcStatusEffectResult(id, attacker, target, res, sub, flags);
        mask2 = datCalcSureHitResult(id, attacker, target, res, sub, flags);
        ent = (u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8);
        if (ent[0x18] == 1 && (*(u32 *)(ent + 0x1C) & 0x80000) && ent[0x24] != 9 && !(mask & 0x80000)) {
            r1 = 0;
        }
        if (mask == 0x80000) {
            *(s32 *)(unit + 0xE0) = 1;
        }
        special = btlBuffMaskCheckUnit(unit, idw, flags);
        resw = (u16)res;
        if (resw == 1 && *(s32 *)(unit + 0xE4) == 0 && special == 0) {
            bonus = *(s32 *)((u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8) + 0x20);
        } else {
            bonus = 0;
        }
        *(u16 *)(unit + 0xDC) = res;
        ((BtlAction *)unit)->targetBlock.targetFlags = sub;
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
            va = datCalcSkillAmount(id, attacker, target, 1, res, sub, flags, 1);
            vb = datCalcSkillAmount(id, attacker, target, 1, res, sub, flags, 2);
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
            x = datCalcSkillRoll(id, attacker, target, flags);
            t = ((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->effectKind;
            switch (t) {
            case 0xC:
            case 0xD:
                *pa = func_0043c6a0(va);
                break;
            }
            t = ((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->spEffectKind;
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
            if (actor == context) {
                totalSelf += va;
            }
            switch (((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->kind24) {
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
            if (actor != context) {
                hit = datCalcIsDead((DatUnit *)target, sumA) != 0;
                if (!hit) {
                    hit = m80 != 0;
                    if (hit) {
                        hit = n80 != 0;
                    }
                }
                resultFlags = flagp;
            } else {
                hit = datCalcIsDead((DatUnit *)target, totalSelf) != 0;
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
                } else if (((sumA < 0 || recordResult == 0x100 || recordResult == 0x400) && datCalcChkBadStatus((DatUnit *)target, 0x100000) != 0) ||
                           (*(s32 *)(unit + 0xE4) == 1 && datCalcChkBadStatus((DatUnit *)uctx, 0x100000) != 0)) {
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
                    v = datCalcResolveSkillId((u8 *)((BtlUnit *)(u8 *)((BtlAction *)actor)->unit)->datUnit, id);
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
                    if (context == actor) {
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
                func_001f9cd0(context, unit, id);
            }
            res30 = (u8 *)((BtlAction *)unit)->unit;
            if (res30[0xA2] == 1 && (s32)element < 8 && !(recordResult & 6)) {
                datSetBitmapBit(((BtlUnit *)res30)->charId, kindU);
            }
        }
        if (*(u16 *)(attacker + 0x2C) != 0) {
            lastMsg = *(u16 *)(attacker + 0x2C);
        } else if (*(u16 *)(uctx + 0x2C) != 0) {
            lastMsg = *(u16 *)(uctx + 0x2C);
        }
        if (special != 0) {
            msg = (s16)btlConditionMessageId(special);
            context[0xD8] |= 1;
        } else if (!(recordResult & 6)) {
            msg = (s16)btlTargetSkillEffectCode(idw);
        } else {
            msg = 0;
        }
        if (msg != 0) {
            *(s16 *)(unit + 0xEC) = msg;
        } else if (lastMsg != 0) {
            *(s16 *)(unit + 0xEC) = lastMsg;
        } else if (!hit) {
            if (counter != 0 || (mask & 1)) {
                *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x18 : 0x19;
            } else if (mask != 0) {
                if (mask & 2) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x16 : 0x17;
                } else if (mask & 4) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x14 : 0x15;
                } else if (mask & 8) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x1C : 0x1D;
                } else if (mask & 0x10) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x12 : 0x13;
                } else if (mask & 0x20) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x10 : 0x11;
                } else if (mask & 0x40) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0x1A : 0x1B;
                } else if (mask & 0x80) {
                    *(u16 *)(unit + 0xEC) = ((BtlUnit *)(u8 *)((BtlAction *)unit)->unit)->genus == 0 ? 0xE : 0xF;
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
    if (*(s16 *)(context + 0xEE) == -1) {
        *(s16 *)(context + 0xEE) = func_001f0610(idw);
    }
    if (((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->kind24 == 6) {
        ((BtlAction *)context)->unk_1a |= 0x4000;
    }
    {
        u16 t = btlBuffMaskCheckEntries(context, idw, flags);

        if (t != 0 && *(s32 *)(context + 0xE8) != 1) {
            *(s16 *)(context + 0xEC) = btlConditionMessageId(t);
        }
    }
    context[0xDB] = status;
    party = ((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus;
    if (party == 1 && *(u16 *)(context + 0x6A) == 1 && (u8 *)((BtlAction **)((BtlAction *)context)->unk_38)[0] == ((BtlBattleState *)iGpffffb3ac)->selectedAction &&
        *(s32 *)((u8 *)((BtlAction **)((BtlAction *)context)->unk_38)[0] + 0xE0) == 1) {
        s32 n = *(u16 *)(context + 0x6A);
        s32 found;
        u8 *sum;

        found = btlTargetAnySpecialHit(context, n);
        if (found) {
            goto other;
        }
        sum = func_001efd50(context);
        *(u8 **)(context + 0x88) = sum;
        if (sum == NULL) {
            goto finished;
        }
        {
            s32 totalDamage;
            u8 q;
            s32 flagHit;
            s32 cnt;
            u8 *first = *(u8 **)(context + 0x38);
            sctx = (u8 *)((BtlUnit *)(u8 *)((BtlAction *)sum)->unit)->datUnit;

            if (((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->kind24 == 0xD) {
                ((BtlActionResolutionMessage *)((BtlAction *)sum)->targetBlock.unk_e8)->messageCode = *(s16 *)(first + 0xEC);
            } else {
                ((BtlActionResolutionMessage *)((BtlAction *)sum)->targetBlock.unk_e8)->messageCode = 0;
            }
            context[0xDB] = 0;
            first[0xDB] = 0;
            ((BtlAction *)first)->targetBlock.hitOutcome = 1;
            ((BtlAction *)first)->targetBlock.targetFlags = 1;
            ((BtlAction *)first)->targetBlock.reactionFlag = 0;
            ((BtlAction *)first)->targetBlock.specialHitFlag = 0;
            ((BtlActionResolutionMessage *)((BtlAction *)first)->targetBlock.unk_e8)->blocked = 0;
            ((BtlActionResolutionMessage *)((BtlAction *)first)->targetBlock.unk_e8)->messageCode = 0;
            ((BtlActionResolutionMessage *)((BtlAction *)first)->targetBlock.unk_e8)->unk06 = -1;
            flagHit = 0;
            totalDamage = 0;
            cnt = first[0xD9];
            for (q = 0; q < cnt; q++) {
                u8 inputIndex = q;
                u8 *s = first + inputIndex * sizeof(LargeBattleHitResult);
                s32 v = ((LargeBattleHitResult *)(s + 0xF0))->hpDelta;
                u16 *copiedFlags;
                u8 resetIndex;

                totalDamage += v;
                if (datCalcIsDead((DatUnit *)sctx, totalDamage) != 0 ||
                    ((((LargeBattleHitResult *)(s + 0xF0))->addedStatus & 0x80000) && !(((LargeBattleHitResult *)(s + 0xF0))->removedStatus & 0x80000))) {
                    flagHit = 1;
                }
                resetIndex = q;
                s = first + resetIndex * sizeof(LargeBattleHitResult);
                memset((u8 *)(u32)s + 0xF0, 0, 0x20);
                *(s32 *)((u8 *)(u32)s + 0xF0) = v;
                s[0x10C] = 2;
                copiedFlags = (u16 *)(s + 0x10E);
                *copiedFlags |= 0x200;
                if (((DatSkillEntry *)(u8 *)addOffsetFirst(damageOffset, (u32)iGpffffb3b8))->kind24 == 0xD) {
                    ((LargeBattleHitResult *)(first + 0xF0))[q].addedStatus |= 0x80000;
                    ((LargeBattleHitResult *)(first + 0xF0))[q].removedStatus &= ~0x80000;
                    first[0xD9] = q + 1;
                    return;
                }
                if (flagHit != 0) {
                    ((LargeBattleHitResult *)(first + 0xF0))[q].addedStatus |= 0x80000;
                    *(u16 *)(*(u8 **)(context + 0x88) + 0x3F4) = 0;
                    *copiedFlags |= 0x10;
                    first[0xD9] = q + 1;
                    return;
                }
            }
        }
        return;
    }
other:
    if ((context[0xDB] & 1) && !(((BtlAction *)context)->flags & 4) && party == 0 && *(u16 *)(context + 0x6A) > 0) {
        s16 cnt = 0;
        u16 m;
        u8 *q;
        u8 *p170;

        for (m = 0; m < *(u16 *)(context + 0x6A); m++) {
            u8 *u = *(u8 **)(context + (u32)m * 4 + 0x38);

            if (((BtlAction *)u)->targetBlock.reactionFlag == 1 && datCalcChkBadStatus((DatUnit *)(u8 *)((BtlUnit *)(u8 *)((BtlAction *)u)->unit)->datUnit, 0x100000) == 0) {
                cnt++;
            } else {
                u8 n = 0;
                s32 count = u[0xD9];
                for (; n < count; n++) {
                    if (((BtlUnit *)(u8 *)((BtlAction *)u)->unit)->genus == 1 && (((BtlAction *)u)->targetBlock.hitRows[n].addedStatus & 0x100000)) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        for (q = ((BtlBattleState *)iGpffffb3ac)->actions; q != NULL; q = (u8 *)((BtlAction *)q)->next) {
            if (((BtlAction *)q)->unk_1a & 1) {
                u8 *r = (u8 *)((BtlAction *)q)->unit;

                if (r[0xA2] == 1 && (((BtlUnit *)r)->flags3 & 8) && datCalcIsDead((DatUnit *)(u8 *)((BtlUnit *)r)->datUnit, 0) == 0 &&
                    datCalcChkBadStatus((DatUnit *)(u8 *)((BtlUnit *)*(u8 **)(q + 0x30))->datUnit, 0x100000) == 0) {
                    cnt--;
                }
            }
        }
        p170 = ((BtlBattleState *)iGpffffb3ac)->selectedAction;
        if (p170 != NULL && datCalcChkBadStatus((DatUnit *)(u8 *)((BtlUnit *)(u8 *)((BtlAction *)p170)->unit)->datUnit, 0x100117) != 0) {
            cnt = 1;
        }
        if (cnt != 0) {
            u8 *e = (u8 *)(u32)func_001eff50(context);

            if (e != NULL) {
                u16 n = *(u16 *)(context + 0x6A);

                if (n > 1) {
                    ((BtlActionParameters *)((BtlAction *)e)->unk_70)->supportTarget = ((u8 **)(context + 0x38))[datCalcRandomBelow(n)];
                } else {
                    ((BtlActionParameters *)((BtlAction *)e)->unk_70)->supportTarget = (u8 *)((BtlAction **)((BtlAction *)context)->unk_38)[0];
                }
                if (*(s32 *)(*(u8 **)(e + 0x90) + 0xE0) == 0) {
                    *(u8 **)(context + 0x8C) = e;
                    ((BtlAction *)e)->unk_16 = 0xD;
                    btlActionActiveListPush(e);
                }
            } else if (func_001ef9c0(context) != 0) {
                ((BtlAction *)context)->unk_16 = 0xC;
                btlActionActiveListPush(context);
            }
        }
    }
finished:
    return;
}

#pragma pop
/* measured: the second loop's slot index is `(u16)emptyIndex * 4` (its own mask, not CSE'd
   with the loop test's `& 0xFFFF`) while the stored count is `(emptyIndex & 0xFFFF) + 1`
   (CSE'd with the test, retail's $a0); the counter store address is offset-first
   integer arithmetic `slotOffset + (u32)D_0076449C`. */
/* Account for a defeated enemy once, accumulating rewards and merging up to three drop ids. */
/* measured: remaining action/unit reloads changed MATCH when typed. Reward totals at battle +0xCB0/+0xCB4 are outside the named shared prefix. */
// FUN_001F2CC0
void btlTargetRecordDefeatReward(u8 *action)
{
    s32 dropMode;
    u8 *base;
    u8 *entry;
    u8 *base2;
    u8 *slot;
    s32 dropId;
    s32 slotOffset;
    s32 existingIndex;
    s64 found;
    s32 emptyIndex;
    u16 actionFlags;
    u16 selectedDrop;
    u8 *unit;

    actionFlags = ((BtlAction *)action)->unk_1a;
    if ((actionFlags & 1) != 0) {
        unit = (u8 *)((BtlAction *)action)->unit;
        if (((BtlUnit *)unit)->genus == 1) {
            if (((BtlUnit *)unit)->charId >= 0x150) {
                kAssertFail((void *)D_0060AB08, 0x4F5);
            }
            actionFlags = *(u16 *)(action + 0x1A);
            if ((actionFlags & 0x20) == 0) {
                *(u16 *)(action + 0x1A) = (u16)(actionFlags | 0x20);
                *(s32 *)(D_0076449C + 0xCB0) =
                    *(s32 *)(D_0076449C + 0xCB0) +
                    datCalcEnemyExp((s32)((BtlUnit *)unit)->datUnit);
                *(s32 *)(D_0076449C + 0xCB4) =
                    *(s32 *)(D_0076449C + 0xCB4) +
                    datCalcEnemyMoney(*(s32 *)(unit + 0xA64));
                selectedDrop = (u16)(datCalcPickWeightedSkill(
                    *(u8 **)(unit + 0xA64), &dropMode) & 0xFFFF);
                if ((dropMode != 1) &&
                    (((BtlActionParameters *)((BtlAction *)action)->unk_70)->drop != 0) &&
                    ((s32)(datCalcRandomBelow(0x64) & 0xFF) <
                     (s32)*(u8 *)(action + 0x82))) {
                    selectedDrop = *(u16 *)(action + 0x80);
                }
                dropId = selectedDrop & 0xFFFF;
                if (dropId != 0) {
                    found = 0;
                    existingIndex = 0;
                    base = D_0076449C;
                    while ((existingIndex & 0xFFFF) < 3) {
                        entry = base + ((u16)existingIndex * 4);
                        if (((BtlRewardEntry *)(entry + 0xCD0))->id == dropId) {
                            ((BtlRewardEntry *)(entry + 0xCD0))->count =
                                (s16)(((BtlRewardEntry *)(entry + 0xCD0))->count + 1);
                            found = 1;
                            break;
                        }
                        existingIndex = (existingIndex + 1) & 0xFFFF;
                    }
                    if (found == 0) {
                        emptyIndex = 0;
                        base2 = D_0076449C;
                        while ((emptyIndex & 0xFFFF) < 3) {
                            slotOffset = (u16)emptyIndex * 4;
                            slot = base2 + slotOffset;
                            if (((BtlRewardEntry *)(slot + 0xCD0))->id == 0) {
                                ((BtlRewardEntry *)(slot + 0xCD0))->id = selectedDrop;
                                ((BtlRewardEntry *)(slotOffset + (u32)D_0076449C + 0xCD0))->count = 1;
                                *(s32 *)(D_0076449C + 0xCDC) = (emptyIndex & 0xFFFF) + 1;
                                return;
                            }
                            emptyIndex = (emptyIndex + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
    }
}

/* Apply defeat or survival state to the action unit and clear the corresponding ailments. */
/* measured: remaining DatUnit-pointer reloads changed MATCH when typed; +0x3F4 is the control halfword overlapping the final hit row. */
// FUN_001F2EB0
void btlTargetSetDefeatState(u8 *context, s32 argument)
{
    s32 value;
    u8 *work;

    work = (u8 *)((BtlAction *)context)->unit;
    datCalcClearStatusBlocked((s32)((BtlUnit *)work)->datUnit);
    if (argument == 1) {
        if (*(u16 *)(context + 0x3F4) != 0x154) {
            datCalcSetHp((DatUnit *)*(s32 *)(work + 0xA64), 1);
        }
        datCalcClearBadStatus((DatUnit *)*(s32 *)(work + 0xA64), 0x80000);
        ((BtlUnit *)work)->flags3 |= 0x10;
        return;
    }
    datCalcSetHp((DatUnit *)*(s32 *)(work + 0xA64), 0);
    datCalcClearBadStatus((DatUnit *)*(s32 *)(work + 0xA64), 0xFFFFFF);
    datCalcSetBadStatus((DatUnit *)*(s32 *)(work + 0xA64), 0x80000);
    value = ((BtlUnit *)work)->flags3 | 1;
    ((BtlUnit *)work)->flags3 = value;
    ((BtlUnit *)work)->flags3 = value & ~0x10;
}

/* Reject skill entries whose flags or effect kind prevent this action from continuing. */
// FUN_001F2F90
s32 btlTargetIsSlotAlive(u8 *context) {
    u8 *p;

    p = iGpffffb3b8 + (s16)((BtlAction *)context)->unk_6e * 40;
    if ((p[0] & 2) != 0) {
        return 0;
    }
    return (p[0x24] ^ 6) != 0;
}

