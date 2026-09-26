/* func_00138490 (cmpSkill.c, window 1600B) -- 2026-09-26 group 0 round 4.
 * Fresh rewrite from the retail listing. Object is 1600B against retail's
 * 1592B of code, with 68 aligned instruction edits (the old guarded draft had
 * 309 edits at 1572B in a 0xD0 frame). NOT installed.
 *
 * Shape found:
 * - The work struct has CmpSkillEntry list[96] at 0x100 and s16 count at
 *   0x580 (12-byte rows, copied by value through f0-f3 as retail does),
 *   and s16 source[] at 0xF4 indexed by the s16 at 0x5C.
 * - Separate counters per region (i/j fill, k/l dedup, m/n sort). The
 *   sort's counters must not cross calls, so they stay in temporaries as
 *   retail's do.
 * - `u16 key = list[k].skill` as a named local. Retail spills it (sq 0xB0).
 * - A static inline 0x20A membership helper for both persona checks.
 * - opt_loop_invariants on (push/pop), with the declaration order below
 *   from a 500-step hill-climb.
 * Residual: sel sits in s7 with its sign-extended copy in fp, where retail
 * has sel in fp and spills the copy to 0xC0. The src pointer (retail
 * s6 = s0+0x100) is recomputed from l. Stack slots are 0x10 low, so the frame
 * is 0xF0, not 0x100. The spill set follows from register pressure.
 * Declaration fixes applied with this draft, all matching their definitions
 * (only this function uses them in cmpSkill.c): s32 func_0010b510(void),
 * u16 *func_0010ace0(s16), s32 func_0010b3b0(s32),
 * u16 *datPersonaGetSkills(int),
 * void func_0010fa80(s16, s16, u32, u32, u32, u32, u32).
 */
/* One learnable-skill row: the owning persona slot (-1 for the unit's own
   persona), the skill id and two words the list copies along with it. */
typedef struct CmpSkillEntry {
    s16 persona;
    u16 skill;
    s32 field_4;
    s32 field_8;
} CmpSkillEntry;

typedef struct CmpSkillWork {
    u8 pad0[0x5C];
    s16 page;
    u8 pad5E[0xF4 - 0x5E];
    s16 source[6];
    CmpSkillEntry list[96];
    s16 count;
} CmpSkillWork;

static inline s32 cmpSkillHasSkill(u16 *skills, u16 skill)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        if (skills[i] == skill) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00138490
void func_00138490(void *arg0)
{
    CmpSkillWork *work = arg0;
    s16 mode;
    s32 count;
    u16 *persona;
    s16 sel;
    s32 l;
    s32 k;
    s32 i;
    s32 m;
    s32 n;
    s32 j;
    s32 costA;
    s32 costB;

    sel = -1;
    count = 0;
    mode = work->source[work->page];
    if (mode == 1) {
        sel = func_0010b510();
        for (i = 0; i < func_0010b6f0(); i++) {
            persona = func_0010ace0(i);
            if (persona != NULL) {
                func_0010b3b0((s16)i);
                for (j = 0; j < 8; j++) {
                    if (func_00113520(1, (s32)persona, j, (u8 *)&work->list[count]) != 0) {
                        work->list[count].persona = i;
                        count++;
                    }
                }
            }
        }
    } else {
        persona = func_0010a900(mode);
        for (i = 0; i < 8; i++) {
            if (func_00113520(mode, (s32)persona, i, (u8 *)&work->list[count]) != 0) {
                work->list[count].persona = -1;
                count++;
            }
        }
    }
    for (k = 0; k < count; k++) {
        u16 key = work->list[k].skill;

        for (l = k + 1; l < count; l++) {
            if (key != work->list[l].skill) {
                continue;
            }
            if ((key < 0x1B8) && (sel != -1)
                && !cmpSkillHasSkill(datPersonaGetSkills((s32)func_0010ace0(work->list[k].persona)), 0x20A)) {
                if (cmpSkillHasSkill(datPersonaGetSkills((s32)func_0010ace0(work->list[l].persona)), 0x20A)) {
                    work->list[k] = work->list[l];
                } else {
                    CmpSkillEntry *src = &work->list[l];

                    func_0010b3b0(work->list[k].persona);
                    func_0010fa80(mode, mode, work->list[k].skill, 0, (u32)&costA, 0, 0);
                    func_0010b3b0(src->persona);
                    func_0010fa80(mode, mode, work->list[l].skill, 0, (u32)&costB, 0, 0);
                    if (costA < costB) {
                        work->list[k] = *src;
                    }
                }
            }
            count--;
            work->list[l] = work->list[count];
            l--;
            work->list[count].field_4 = 0;
            work->list[count].field_8 = 0;
            work->list[count].skill = 0;
            work->list[count].persona = -1;
        }
    }
    work->count = count;
    for (m = 0; m < count; m++) {
        CmpSkillEntry a = work->list[m];

        for (n = m + 1; n < count; n++) {
            CmpSkillEntry b = work->list[n];

            if ((b.skill >= 0xC0) && (b.skill < 0x100)) {
                if ((a.skill >= 0xC0) && (a.skill < 0x100)) {
                    if (b.skill < a.skill) {
                        work->list[m] = b;
                        work->list[n] = a;
                        a = b;
                    }
                } else {
                    work->list[m] = b;
                    work->list[n] = a;
                    a = b;
                }
            } else if (!((a.skill >= 0xC0) && (a.skill < 0x100))) {
                if (b.skill < a.skill) {
                    work->list[m] = b;
                    work->list[n] = a;
                    a = b;
                }
            }
        }
    }
    if (sel != -1) {
        func_0010b3b0(sel);
    }
    if (work->count > 0x60) {
        func_0046d730(D_005ED9C0, 0x336);
    }
    func_0013a040((s16 *)work, 1, 0);
    func_0013a040((s16 *)work, 2, 0);
}
#pragma pop
