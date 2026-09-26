#pragma push
#pragma opt_loop_invariants on
s32 func_001e9950(void)
{
    extern s32 func_0023d6e0(s16 element);
    extern s32 func_0023df70(u16 skill);
    extern u32 func_0023d9b0(u8 *unit, u16 skill);
    extern u16 func_0023dd90(u8 *unit, u16 skill);
    extern u16 func_001d7f10(u8 *arg0, u8 *arg1, u16 arg2, u32 arg3);
    extern s32 func_001db360(u8 *formation, s32 index, s32 enabled);
    extern s32 func_00235520(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    extern void func_001dbf20(u8 *arg0, u32 arg1);
    extern void func_0029cf50(s32 retVal);
    extern u16 datCalcGetHp(s32 unit);
    extern u16 func_00231f80(u8 *unit);
    extern s32 func_00242800(u8 *unit, s16 element);
    extern s32 func_0023ddc0(u8 *unit, u16 skill);
    extern s32 func_0029cc00(s32 paramIdx);
    struct {
        u8 *entries[14];
        u16 count;
    } targets;
    u16 i;
    u8 *unit;
    u16 *table;
    u8 *entry;
    s32 mode;
    s32 bestSkill;
    s32 bestTarget;
    s32 bestCost;
    s32 target;
    s32 skillId;
    s32 cost;
    s32 dmg;
    s32 hp;
    s32 maxHp;
    u16 count;
    u16 found;
    u16 j;
    u16 skill;
    s16 kind;
    u8 *work;
    f32 score;
    f32 bestScore;
    f32 cur;

    work = func_0029d050();
    mode = func_0029cc00(0);
    unit = *(u8 **)(work + 0x30);
    bestTarget = 0;
    bestSkill = -1;
    bestCost = 999;
    bestScore = -1.0f;
    count = (u16)func_0023e130(*(u8 **)(unit + 0xA64)) + 1;
    table = (u16 *)func_0023e140(*(u8 **)(unit + 0xA64));
    for (i = 0; i < count; i++) {
        if (i == 0) {
            skill = func_0023dfe0(*(u8 **)(unit + 0xA64));
        } else {
            skill = table[i - 1];
            if (skill == 0) {
                continue;
            }
        }
        skillId = skill;
        if (skillId >= 0x1B8) {
            continue;
        }
        kind = func_0023d8e0(*(u8 **)(unit + 0xA64), skill);
        if ((func_0023d6e0(kind) & 0x7E) == 0) {
            continue;
        }
        if (kind == 0) {
            if (mode == 1) {
                continue;
            }
        } else {
            if (mode == 2) {
                continue;
            }
        }
        if (func_0023df70(skill) == 0) {
            if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x80008) != 0) {
                continue;
            }
            if (func_0023ddc0(*(u8 **)(unit + 0xA64), skill) != 0) {
                continue;
            }
        }
        found = func_001d7f10(work, (u8 *)&targets, skill, 0);
        target = 0;
        if (found == 0) {
            score = 0.0f;
            for (j = 0; j < targets.count; j++) {
                entry = targets.entries[j];
                if (func_001db360(entry, kind, 1) != 0) {
                    dmg = func_00235520(skill, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entry + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                    hp = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64));
                    maxHp = func_00231f80(*(u8 **)(*(u8 **)(entry + 0x30) + 0xA64));
                    if (hp < -dmg) {
                        cur = (f32)hp / (f32)maxHp + 1.0f;
                    } else {
                        cur = (f32)-dmg / (f32)maxHp;
                    }
                    if (score < cur) {
                        target = *(s32 *)(entry + 8);
                        score = cur;
                    }
                }
            }
        } else {
            score = 0.0f;
            for (j = 0; j < targets.count; j++) {
                entry = targets.entries[j];
                if (func_001db360(entry, kind, 1) == 0) {
                    if ((func_00242800(*(u8 **)(*(u8 **)(entry + 0x30) + 0xA64), kind) & 0x1000000) == 0) {
                        score = 0.0f;
                        break;
                    }
                } else {
                    dmg = func_00235520(skill, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entry + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                    hp = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64));
                    maxHp = func_00231f80(*(u8 **)(*(u8 **)(entry + 0x30) + 0xA64));
                    if (hp < -dmg) {
                        score += (f32)hp / (f32)maxHp;
                        score += 1.0f;
                    } else {
                        score += (f32)-dmg / (f32)maxHp;
                    }
                }
            }
        }
        if (bestScore <= score) {
            if (bestScore == score) {
                if (func_0023dd90(*(u8 **)(unit + 0xA64), skill) == 2) {
                    cost = func_0023d9b0(*(u8 **)(unit + 0xA64), skill);
                    if (cost < bestCost) {
                        bestSkill = skillId;
                        bestTarget = target;
                        bestScore = score;
                        bestCost = cost;
                    }
                }
            } else {
                bestSkill = skillId;
                bestTarget = target;
                bestScore = score;
            }
        }
    }
    if (bestSkill != -1) {
        if (bestSkill == 0) {
            func_001de640(work, work + 0x38, 0x8000);
        } else {
            func_001de640(work, work + 0x38, bestSkill);
        }
        if (bestTarget != 0) {
            *(u8 **)(work + 0x38) = func_001b0cc0(bestTarget);
            *(u16 *)(work + 0x6A) = 1;
        } else {
            func_001dbf20(work, 0);
        }
    }
    func_0029cf50(bestSkill);
    return 1;
}
#pragma pop
