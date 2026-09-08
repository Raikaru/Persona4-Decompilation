/* Exact actor skill selector: func_001ebc00, 0x001EBC00..0x001EC1BF.
 * Object 1468/1472 bytes, all four call relocations resolved, nd0;
 * the last retail word is zero alignment after the return delay slot.
 * A real u16 skill-array view, word-sized loaded skill, declaration order,
 * opt_common_subs off and a named low-halfword count snapshot close the floor.
 * All 97 discrete cases remain explicit; the local u16 choices[8] is only
 * prefix-initialized and every selected element has been written.
 * func_0023dfe0 now has the same s32(u8*) contract in its real provider and
 * all active callers, including the formerly narrowed s16 declaration.
 * The provider's real zero-return implementation is unchanged.
 * Five affected owners verify at 504 MATCH / 47 ASM with no mismatches.
 *
 * A freestanding 32-bit native smoke passed all 65,536 possible skill IDs
 * against an independent 97-value oracle decoded from retail comparisons.
 * It executed the real skill getter, eligibility predicate, normal-attack
 * provider and unsigned modulo provider, with deterministic RpRandom.
 * Dense eight-slot, sparse-zero, excluded-hole, duplicate, all-rejected and
 * fast-path/status-precedence cases passed; other command bytes stayed intact.
 * Unexercised persona/cost/assert paths were fail-fast fixture boundaries,
 * not substitute successful implementations. This is not game execution.
 *
 * Pre-integration contracts (line references are from that audit):
 *
 * func_001ebc00 -- current retail 0x001EBC00..0x001EC1BF (0x5C0 bytes)
 *
 * ABI AND OBJECTS
 * - void func_001ebc00(u8 *action, u8 *command). a0/a1 are saved as s5/s4.
 * - action is the existing battle action object. Its +0x30 word is an actor
 *   pointer; actor+0xA64 is a pointer to calculation/unit data. Do not type this
 *   last pointer as an integer. The selector reloads this chain before EACH
 *   eligibility call and again before the fallback call, not once for all uses.
 * - command is NOT a caller-supplied array of candidate skills, nor a count
 *   output. Its only accesses here are writes of two halfwords at +0x34 and
 *   +0x36. The old values of those fields, and all other command bytes, are not
 *   read. Normal callers pass command = action+0x38, so these writes become
 *   action+0x6C (command kind) and action+0x6E (selected skill).
 * - Direct footprint: read action[0x30..0x33], actor[0xA64..0xA67], provider's
 *   skill bytes[0..15]; write command[0x34..0x37]. Providers additionally read
 *   the unit fields and global tables described below. Existing byte-offset
 *   conventions are used without new layouts, filler, or integer pointer ABI.
 *
 * ACTUAL CALLER CAPACITY AND REACHABILITY
 * - The sole direct call found by current ASM literal search is 0x001DE7B4 in
 *   func_001de640. Complete caller ASM is
 *   asm/nonmatchings/btlAICommand/func_001de640.s:1-131. The dispatcher saves its
 *   own second argument in s0; selector call reloads a1=s0 and leaves a0 as the
 *   supplied action. It invokes this target only for normalized code 0x8009.
 *   Codes in the 0x8000 family remain their complete 16-bit value; other codes
 *   normalize to their top nibble. It does not use the selector's v0 afterward.
 * - A concrete reachable source is script helper func_001defa0: positive script
 *   argument 0x8009 is narrowed to u16 and passed to func_001de640(p,p+0x38,...),
 *   with p=func_0029d050(). See its complete ASM, especially 0x001DEFF0..DFFFF.
 *   func_001ea2d0 similarly passes script argument 1 as the command, after
 *   updating the actor via func_0019ef30; q is again p+0x38 (0x001EA320..EA330).
 * - func_001eb1d0 passes the u16 at selected AI entry+2 with q=p+0x38
 *   (0x001EB20C..EB21C). func_001ded30 passes its own q unchanged after
 *   func_001eb3b0(q); its actual parent func_001a2b50 supplies q=p+0x38 at
 *   0x001A2B74..A2B80. func_001eb4a0 passes its own q; its actual parent
 *   func_001a31e0 supplies q=p+0x38 at 0x001A36D0..A36E0. Thus these are the
 *   same embedded command block, not undersized local temporaries.
 * - Physical allocation proof: func_001b0930 allocates 0x458 bytes, zeros all
 *   0x458, then calls func_001eb380(p+0x38). See full retail ASM
 *   asm/nonmatchings/code1_001b/func_001b0930.s:1-84 and current C
 *   src/promoted/code1_001b.c:350-385. The block initializer is current
 *   src/promoted/code1_001e.c:2070-2072: memset(command,0,0x5C).
 *   Therefore the actual embedded command block is 0x5C bytes, wholly within
 *   the 0x458-byte action; this selector requires only through block+0x37.
 *   func_001eb3b0 independently initializes fields through block+0x5B.
 * - No output initialization precondition exists for this selector: it writes
 *   both halfwords on either terminal branch. The initializers above are real
 *   caller evidence, NOT invented initialization in the candidate.
 * - As in retail, callers must supply the live action/actor/unit pointer chain;
 *   neither this function nor its direct dispatcher null-checks those inputs.
 *   Invalid/unbound action lifecycle objects are not repaired or special-cased.
 *
 * SKILL SOURCE AND INPUT EXTENT
 * - func_0023e140 has actual current definition u8 *func_0023e140(u8 *unit)
 *   in src/Main/Battle/Data/datCalc.c:2027-2039; complete current retail listing
 *   asm/nonmatchings/datCalc/func_0023e140.s:1-53.
 * - unit+0 is u16 flags and unit+2 is u16 ID. If !(flags&4), ID>=0xB reports
 *   error line 0xFA5, then calls func_001094e0(ID). The provider at 0x001094E0
 *   is named datPersonaGetSkillsByPcId in current symbols/g_data.c:1485-1490;
 *   it returns func_0010a900(ID)+0xC, confirmed by asm/code1.s:11277-11287.
 *   The current PersonaWork definition has u16 skills[8] at +0xC
 *   (src/g_data/g_data.c:219-228). Thus exactly eight halfwords are real input
 *   storage; not a guessed byte array and not a null/sentinel-terminated list.
 * - If flags&4, ID>=0x150 reports error line 0xFA8, then the result is
 *   iGpffffb3c4 + ID*0x3C + 0xE. The eight consumed halfwords lie at row+0xE
 *   through row+0x1D, strictly within the real 0x3C-byte row stride.
 * - This provider returns a pointer; it does NOT produce a length or allocate,
 *   initialize, fill, or copy candidate storage. Preserve u8 * return matching
 *   its current owner; use a u16 load for each entry.
 * - The unit calculation object initializer func_00231dc0 zeros 0x30 bytes,
 *   sets ID at +2/+4 and initializes +6,+8,+0xA,+0x10. Current datCalc.c:122-131.
 *   Skill storage belongs to the referenced persona/table, not this 0x30-byte
 *   object. Do not fabricate skills from uninitialized local unit storage.
 *
 * COMPLETE SELECTOR CONTROL FLOW
 * - Call skill provider once. Initialize count=0 and index=0.
 * - Iterate exactly eight slots, index 0 through 7, in original order.
 *   index and count are logical u16 counters: update is (old+1)&0xFFFF;
 *   all indexing/loop tests explicitly use their low 16 bits. They reside in
 *   general registers; the candidate uses s32 locals plus the observed masks.
 *   skill is an unsigned halfword (lhu), not an unsigned byte.
 * - Zero entries skip eligibility and append, but do NOT end the scan.
 * - A nonzero entry reaches eligibility iff it is one of these exact 97 values
 *   (the complete retail compare order, no inferred intervals):
 *   AD AC AB A9 A8 A6 A5 A4 A3 A2 A1 A0 9F 9E 9D 9C 9B 9A 99 98
 *   97 96 95 94 93 92 91 90 8F 8E 8C 8B 8A 89 88 87 86 85 84 83
 *   82 81 80 7F 7E 7D 7C 7B 7A 79 78 5F 5E 5D 5C 5B 5A 59 58
 *   56 55 54 53 35 34 33 2D 2C 2B 2A 29 28 27 21 20 1F 1E 1D
 *   1C 1B 1A 15 14 13 12 11 10 0F 0E 08 07 06 05 04 03 02 01.
 *   A7, AA, 8D, 57 and all other omitted values remain excluded.
 * - Append a listed skill only when func_0023ddc0(unit,skill)==0. Duplicates
 *   remain duplicated; there is no sorting, de-duplication, early break, or
 *   external output during the scan.
 * - choices is a real local u16[8], mapped to retail sp+0x70..0x7F inside the
 *   0x80-byte frame. At every append, count<=index<=7, so write index<=7.
 *   On loop exit count<=8. Only choices[0..count-1] have been initialized.
 * - If count==0: store command kind 1 at +0x34, reload unit chain, call
 *   func_0023dfe0(unit), store its low halfword at +0x36. That provider returns
 *   zero in current retail, but the call and reload MUST remain.
 * - Else: store command kind 2 at +0x34 BEFORE the random call, call
 *   func_00231d70(count), store choices[result] at +0x36.
 * - func_00231d70 is u32(u32), current datCalc.c:111-117 and complete retail
 *   asm/chunks/code1_469.s:12-34: reports error if limit==0, then returns
 *   RpRandom()%limit using divu/mfhi. This caller passes 1..8 only; result is
 *   0..count-1, so EVERY local element read has previously been written. No
 *   zero initialization, guessed precondition, or undefined local read needed.
 * - Return is void. Retail leaves fallback provider v0 (zero) or random index
 *   v0 alive incidentally; it does NOT return the selected skill (loaded in v1)
 *   and no actual caller consumes those leftovers.
 *
 * ELIGIBILITY PROVIDER SEMANTICS
 * - Actual definition s32 func_0023ddc0(u8 *unit,s32 skill), datCalc.c:1920-1958;
 *   complete retail asm/nonmatchings/datCalc/func_0023ddc0.s:1-101.
 * - Row = iGpffffb3b8 + (skill&0xFFFF)*0x28; error for skill>=0x240. Every
 *   member admitted by this selector is <=0xAD, also below the delegated cost
 *   provider's 0x1B8 bound, so neither skill-bound error is reachable here.
 * - If row[0x11]==0x10, return 0 immediately (even when status bit below is set).
 * - Otherwise if u32(unit+0xC)&8, return 4 immediately.
 * - Otherwise compute unsigned cost v=func_0023d9b0(unit,skill).
 *   row[3]==1: if !(row[0]&1), return 1 when u16(unit+8)<=v;
 *              if row[0]&1, return 1 when u16(unit+8)<v.
 *   row[3]==2: return 2 when u16(unit+0xA)<v.
 *   All other cases, and sufficient-resource branches, return 0.
 *   This is a zero-means-allowed status code, NOT a positive eligibility bool.
 * - Its cost provider was also read in full (func_0023d9b0.s:1-276). It derives
 *   cost from skill row+4/+6, unit type and the max-resource providers; may
 *   inspect the provider skill list and equipment for half-cost skills 0x20B
 *   (HP) / 0x20A (SP). It returns unsigned cost, and does not populate any
 *   selector local. Keep it delegated; do not reproduce or bypass this logic.
 *
 * SIGNATURE REPAIRS
 * - Replace owner's extern u8 *func_0023e140() with typed u8 *(u8 *).
 * - Add s32 func_0023ddc0(u8 *,s32) matching real provider.
 * - Use existing u32 func_00231d70(u32), not signed or narrowed random return.
 * - Current datCalc.c defines func_0023dfe0(void), but retail callers including
 *   this selector and func_001de640 pass the actual unit pointer. Repair its
 *   definition and live declarations to s32 func_0023dfe0(u8 *unit), body still
 *   return 0. It reads no unit bytes. The passed pointer is real caller ABI,
 *   not an invented consumed input. Align existing btlAICommand.c u32 argument
 *   view to the same byte-pointer convention during Main's integration.
 * - Existing void selector declaration in btlAICommand.c already agrees.
 */

extern u8 *func_0023e140(u8 *unit);
extern s32 func_0023ddc0(u8 *unit, s32 skill);
extern s32 func_0023dfe0(u8 *unit);
extern u32 func_00231d70(u32 limit);

#pragma opt_common_subs off
void func_001ebc00(u8 *action, u8 *command)
{
    u16 choices[8];
    u16 *skills;
    s32 index;
    s32 count;
    u32 skill;
    u32 available;

    skills = (u16 *)func_0023e140(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    count = 0;
    index = 0;
    while ((index & 0xFFFF) < 8) {
        skill = skills[index & 0xFFFF];
        if (skill != 0) {
            switch (skill) {
            case 0x01:
            case 0x02:
            case 0x03:
            case 0x04:
            case 0x05:
            case 0x06:
            case 0x07:
            case 0x08:
            case 0x0E:
            case 0x0F:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x20:
            case 0x21:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA8:
            case 0xA9:
            case 0xAB:
            case 0xAC:
            case 0xAD:
                if (func_0023ddc0(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), skill) == 0) {
                    choices[count & 0xFFFF] = skill;
                    count = (count + 1) & 0xFFFF;
                }
                break;
            }
        }
        index = (index + 1) & 0xFFFF;
    }
    available = count & 0xFFFF;
    if (available == 0) {
        *(u16 *)(command + 0x34) = 1;
        *(u16 *)(command + 0x36) = func_0023dfe0(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
    } else {
        *(u16 *)(command + 0x34) = 2;
        *(u16 *)(command + 0x36) = choices[func_00231d70(available)];
    }
}

#pragma opt_common_subs on

