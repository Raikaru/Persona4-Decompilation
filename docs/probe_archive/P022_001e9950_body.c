/* P022: retained skill-evaluator investigation, 2026-09-04.
 * Target: 001E9950..001E9F1F, 1488 bytes; production remains INCLUDE_ASM.
 * Preferred fitting probe: current-owner source, 1488/1488 bytes, nd 324,
 * 27 resolved call relocations, frame 0x1A0 matching retail. This is NOT
 * an exact recovery, a register-only floor, or an impossibility claim.
 *
 * Source uses raw s32 skill/count values, a sign-extended s64 affinity
 * lifetime, score-before-best declaration order, and loop-invariant hoisting.
 * The earlier s32 affinity candidate reached 1464/1488, nd 904; a wide
 * zero predicate alone reached 1484/1488, nd 796. Keeping the affinity wide
 * throughout recovers the exact frame and emitted size shown above.
 *
 * Remaining differences include register allocation, narrow return masks,
 * argument normalization, target-ID initialization placement, shared loop
 * projections, and floating-point association/operand order. The compiler
 * reassociates the all-target lethal expression despite its parentheses.
 * Do not claim all remaining differences are register allocation.
 *
 * Further wide-affinity profiles: plain 1480/1024, CSE-off 1500/1048,
 * propagation-off 1544/1145, opt_fp_contract off unchanged at 1488/324.
 * Hoisting targetId=0 reaches 1480/468; distinct branch index/target locals
 * reach 1480/477. Broad historical callsite views reach 1484/785, not an ABI
 * solution. Measurements list emitted bytes / normalized byte differences.
 *
 * Probe integration, NOT a repository ABI cutover: before the owner's first
 * function, merge the declarations below; replace its old s64 func_0023d8e0
 * declaration with s32(u8*,s32), and its stale func_001d7f10 declaration with
 * the current u8(u8*,u8*,u16,u32) provider contract. Declaring the void VM
 * result setter only beside this target fails after earlier implicit-int
 * uses. Reconcile existing provider/caller declarations before promotion;
 * do not paste duplicate conflicting declarations into the production owner.
 *
 * Behavioral reconstruction: callback 0x20FA reads one script argument and
 * returns 1. The real skill-count provider returns 8; candidate zero is the
 * normal attack, followed by eight u16 slots. IDs >=0x1B8 are excluded.
 * Target scratch needs exactly 0x3D bytes, including count at +0x38; no
 * invented 128-bit locals or enlarged output object is used.
 *
 * Damage prediction has eight real arguments. Preserve signed 32-bit
 * wrapping negation, the STRICT hp<damage lethal test, u16 HP/max-HP views,
 * and (score+ratio)+1 association for all-target lethal scores. Unsuitable
 * all-target entries with 0x01000000 are skipped; other unsuitable entries
 * reset score to zero and terminate that candidate. The tie-cost threshold
 * changes only on equal-score cost-kind-2 wins; strict score improvements
 * intentionally do not reset it. Skill zero encodes as command 0x8000.
 *
 * Complete retail/provider/caller reads found no target-local unwritten
 * input requirement. Actual external skill TBL payload contents are not
 * available in the stripped ELF; no game/data-wide safety claim or native
 * gameplay validation is made. Measurements are compile/relocation probes.
 */
#include "type.h"
/* Provider-derived declarations for the isolated probe. Several existing
 * owner callsite views differ; apply the integration substitutions above.
 * The s32 script-argument spelling already exists in the production owner;
 * it is not a new alias introduced here. */
extern u8 *func_0029d050(void);
extern s32 func_0029cc00_s32(s32 index);
extern void func_0029cf50(s32 value);
extern u32 func_0023e130(u8 *unit);
extern u8 *func_0023e140(u8 *unit);
extern s32 func_0023dfe0(u8 *unit);
extern s32 func_0023d8e0(u8 *unit, s32 skill);
extern s32 func_0023d6e0(s16 affinity);
extern s32 func_0023df70(s32 skill);
extern u32 func_00232710(s32 unitAddress, u32 mask);
extern s32 func_0023ddc0(u8 *unit, s32 skill);
extern u8 func_001d7f10(u8 *action, u8 *output, u16 skill, u32 invert);
extern s32 func_001db360(u8 *action, s32 affinity, s32 enabled);
extern s32 func_00235520(s32 skill, u8 *sourceUnit, u8 *targetUnit,
                       u16 count, u16 resultType, u16 multiplier,
                       s32 flags, u8 resource);
extern s32 func_00231ed0(s32 unitAddress);
extern s32 func_00231f80(s32 unitAddress);
extern s32 func_00242800(s32 unitAddress, s32 affinity);
extern u8 func_0023dd90(u8 *unit, s32 skill);
extern u32 func_0023d9b0(u8 *unit, s32 skill);
extern void func_001de640(u8 *action, u8 *command, u16 skill);
extern u8 *func_001b0cc0(s32 id);
extern s32 func_001dbf20(u8 *action, u32 unused);

#pragma push
#pragma opt_loop_invariants on
s32 func_001e9950(void)
{
    u8 *action;
    u8 *actor;
    u16 *skills;
    s32 mode;
    s32 selected;
    s32 selectedTarget;
    s32 tieCost;
    s32 candidateCount;
    u16 candidate;
    s32 skill;
    s64 affinity;
    u8 targets[0x3D];
    s32 targetId;
    f32 score;
    f32 best;
    u16 index;
    u8 *target;
    s32 delta;
    s32 hp;
    s32 maxHp;
    f32 value;
    s32 cost;

    action = func_0029d050();
    mode = func_0029cc00_s32(0);
    actor = *(u8 **)(action + 0x30);
    selectedTarget = 0;
    selected = -1;
    tieCost = 999;
    best = -1.0f;
    candidateCount = (u16)((func_0023e130(*(u8 **)(actor + 0xA64)) & 0xFFFF) + 1);
    skills = (u16 *)func_0023e140(*(u8 **)(actor + 0xA64));
    for (candidate = 0; candidate < (u16)candidateCount; candidate++) {
        if (candidate == 0) {
            skill = (u16)func_0023dfe0(*(u8 **)(actor + 0xA64));
        } else {
            skill = skills[candidate - 1];
            if (skill == 0)
                continue;
        }
        if ((u16)skill >= 0x1B8)
            continue;
        affinity = (s16)func_0023d8e0(*(u8 **)(actor + 0xA64), skill);
        if ((func_0023d6e0(affinity) & 0x7E) == 0)
            continue;
        if ((s64)(s16)affinity == 0) {
            if (mode == 1)
                continue;
        } else if (mode == 2) {
            continue;
        }
        if (func_0023df70(skill) == 0) {
            if (func_00232710(*(s32 *)(actor + 0xA64), 0x80008) != 0)
                continue;
            if (func_0023ddc0(*(u8 **)(actor + 0xA64), skill) != 0)
                continue;
        }
        if ((func_001d7f10(action, targets, skill, 0) & 0xFFFF) == 0) {
            targetId = 0;
            score = 0.0f;
            for (index = 0; index < *(u16 *)(targets + 0x38); index++) {
                target = *(u8 **)(targets + index * 4);
                if (func_001db360(target, (s16)affinity, 1) == 0)
                    continue;
                delta = func_00235520(skill, *(u8 **)(actor + 0xA64),
                    *(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                hp = func_00231ed0(*(s32 *)(*(u8 **)(target + 0x30) + 0xA64)) & 0xFFFF;
                maxHp = func_00231f80(*(s32 *)(*(u8 **)(target + 0x30) + 0xA64)) & 0xFFFF;
                delta = (s32)(0U - (u32)delta);
                if (hp < delta)
                    value = (f32)hp / (f32)maxHp + 1.0f;
                else
                    value = (f32)delta / (f32)maxHp;
                if (score < value) {
                    targetId = *(s32 *)(target + 8);
                    score = value;
                }
            }
        } else {
            targetId = 0;
            score = 0.0f;
            for (index = 0; index < *(u16 *)(targets + 0x38); index++) {
                target = *(u8 **)(targets + index * 4);
                if (func_001db360(target, (s16)affinity, 1) == 0) {
                    if ((func_00242800(*(s32 *)(*(u8 **)(target + 0x30) + 0xA64), affinity) & 0x1000000) != 0)
                        continue;
                    score = 0.0f;
                    break;
                }
                delta = func_00235520(skill, *(u8 **)(actor + 0xA64),
                    *(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                hp = func_00231ed0(*(s32 *)(*(u8 **)(target + 0x30) + 0xA64)) & 0xFFFF;
                maxHp = func_00231f80(*(s32 *)(*(u8 **)(target + 0x30) + 0xA64)) & 0xFFFF;
                delta = (s32)(0U - (u32)delta);
                if (hp < delta)
                    score = (score + (f32)hp / (f32)maxHp) + 1.0f;
                else
                    score += (f32)delta / (f32)maxHp;
            }
        }
        if (best <= score) {
            if (best == score) {
                if ((func_0023dd90(*(u8 **)(actor + 0xA64), skill) & 0xFFFF) != 2)
                    continue;
                cost = (s32)func_0023d9b0(*(u8 **)(actor + 0xA64), skill);
                if (cost >= tieCost)
                    continue;
                selected = (u16)skill;
                selectedTarget = targetId;
                best = score;
                tieCost = cost;
            } else {
                selected = (u16)skill;
                selectedTarget = targetId;
                best = score;
            }
        }
    }
    if (selected != -1) {
        if (selected == 0)
            func_001de640(action, action + 0x38, 0x8000);
        else
            func_001de640(action, action + 0x38, (u16)selected);
        if (selectedTarget != 0) {
            *(u8 **)(action + 0x38) = func_001b0cc0(selectedTarget);
            *(u16 *)(action + 0x6A) = 1;
        } else {
            func_001dbf20(action, 0);
        }
    }
    func_0029cf50(selected);
    return 1;
}

#pragma pop
