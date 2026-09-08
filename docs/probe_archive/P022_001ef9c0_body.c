/* Exact roster assistance selector, func_001ef9c0.
 * 904/912 bytes, all fifteen relocations resolved, nd0. The final eight
 * retail bytes are alignment. Current canonical owner: 114 MATCH / 6 ASM.
 * Three four-element pointer arrays are real initialized-prefix storage;
 * the rank is an ordinary s32 scalar, not a synthetic s128 spill object.
 * Preferred-or-random conditional expressions recover retail's branch shape;
 * declaring the node before counts closes the remaining register cycle.
 * The status/rank/mapper declarations now match their real provider ABIs,
 * including the existing func_001eff50 pointer argument. Three redundant
 * block-scope status declarations were removed rather than kept as aliases.
 *
 * Freestanding 32-bit native smoke PASSED 46,080 combinations: six rank
 * boundaries (0,4,5,6,7,65535), all 8^3 candidate-status combinations,
 * five preferred-node choices and three unsigned random words. It executed
 * the current real community lookup/rank/mapper, status/flag and modulo
 * providers with a deterministic stateful RpRandom fixture boundary.
 * All six acting-node rejection gates, candidate flags/genus filters,
 * preferred protagonist selection, output resets and untouched action bytes
 * passed. Random state advances only for a required random selection.
 * Error/assert paths are fail-fast, not fake successful implementations.
 * This is native C behavior verification, not game execution.
 *
 * Pre-integration audit (line references refer to that snapshot):
 *
 * TARGET AND ABI
 * func_001ef9c0, retail [0x001EF9C0,0x001EFD50), 0x390/912 bytes.
 * Complete 258-line target ASM was read. body.c is the complete ordinary-C
 * candidate for insertion into src/promoted/code1_001e.c, not a byte-matched
 * claim. No compiler, probe, build, test, formatter, or linter was run.
 *
 * Input: one u8 * action object, not a raw actor or status record.
 * Output: s32 Boolean 0/1. It is NOT an action pointer, community ID, rank,
 * count, mask, or 128-bit object. It always first stores signed halfword -1 at
 * action+0x448, then the null action pointer at action+0x444, even on every
 * rejected input path. Success replaces both fields and returns 1.
 *
 * EXTERNAL FIELD EXTENTS
 * The action object must support reads at +0x14 (u16), +0x30 (32-bit actor
 * pointer), and writes +0x444..0x447 (selected action pointer), +0x448..0x449
 * (s16 assistance kind). Roster actions additionally supply +0x1A (u16 flags)
 * and +0x450..0x453 (next action pointer). The actual allocator func_001b0930
 * allocates and zeroes 0x458 bytes: src/promoted/code1_001b.c:350-384;
 * retail 0x001B094C..0x001B0978. No caller-provided output array exists.
 *
 * Actor objects supply +0xA2 (u8 genus), +0xA4 (ID read u16 for the ID1 check,
 * s16 for the mapper), and +0xA64 (32-bit status-record address). Actual
 * func_0019d210 allocates/zeroes 0xA70 bytes and stores its genus argument at
 * +0xA2 (0x0019D238..0x0019D268). btlActionSetUnit/func_001b0910 stores the
 * actor pointer at action+0x30 and sets action flag1. func_0019f5f0 makes the
 * actor/action pair, binds it, sets action flag8, binds its supplied status
 * record at actor+0xA64, and invokes func_0019ea60 to set actor+0xA4. The
 * party creation call supplies descriptor+4, not an uninitialized stack
 * value. Status records are the battle data records; this target/providers
 * read +0..1 for the 0x200 flag and +0xC..0xF for status masks. No provider
 * here writes into any target-owned stack array.
 *
 * The battle global iGpffffb3ac is a pointer to a 0xE88-byte allocation
 * zeroed by func_00192b90 (src/promoted/code1_0019.c:489-512), containing flags
 * +0xC, preferred/protagonist action +0x170, and action-list head +0x174.
 * The allocator prepends nodes and maintains +0x44C/+0x450 links. The initial
 * head is zero from the battle allocation. func_001b0a60 unlinks released
 * nodes; func_001b0bf0 drains the list during func_00192cd0 teardown.
 *
 * ACTUAL CALLER CHAIN
 * Full aligned retail-image word scan: one J/JAL reference to target,
 * 0x001F2C64 in func_001f14f0; no literal 0x001EF9C0 address word. This is
 * stronger than the incomplete/stale graph, but not a proof against arbitrary
 * runtime-computed addresses.
 *
 * func_001f14f0 saves its input a0 in s4 at 0x001F1520 and never reassigns
 * that register before epilogue. The target call passes that same pointer.
 * It is reached at the assist fallback after func_001eff50(action) returned
 * zero. The relevant terminal path requires action DB flag1, no action+18
 * bit4, the preceding branch's no-extra-effect condition, positive target
 * count at +6A, and the signed tally at 0x001F2BD0 nonzero. Thus there is no
 * missing second argument carried by the target's caller. On target result
 * 1, 0x001F2C74..0x001F2C80 stores action+0x16=12 and queues the SAME action
 * via func_001b0e30. That provider searches 12 slots at global+0x2CC and
 * inserts the action into a free slot; it does not return the target result.
 *
 * The only J/JAL callers of func_001f14f0 are 0x001A492C in func_001a4800
 * and 0x001AECA8 in func_001aec20. Each preserves/forwards its action input.
 * Their literal callbacks are at 0x005F6ED8 and 0x005F6F94 in D_005F6E20,
 * respectively action-state15 update and action-state31 initializer. Current
 * action dispatch in func_001b0a60 forwards the linked-list action pointer to
 * D_005F6E20's initializer/update entry, rather than a truncated subobject.
 * The first caller's jump-table cases 1,2,3,9 reach its call; the second sets
 * up its action's target array then calls. Those surrounding target arrays
 * are not inputs to func_001ef9c0 itself.
 *
 * ROSTER CAPACITY
 * Target locals are THREE arrays of four 32-bit action pointers. Retail
 * slots: status1 list at sp+0xD0, status100000 list at sp+0xC0, status1E list
 * at sp+0xB0; each region is 16 bytes. This is actual selected-element
 * storage, not invented padding. The three counts are s32, initialized with
 * zero and incremented by addiu (no 16-bit narrowing). The other three zeroed
 * callee-saved locals are PREFERRED ACTION POINTERS, not counters.
 *
 * Full retail scan found the only calls to func_001b0930 at 0x0019F648 and
 * 0x0019F6FC, the two genus0/genus1 branches of func_0019f5f0. The only
 * calls to func_0019f5f0 are 0x001B1DD8 (genus0 party), 0x001B1FCC (genus1
 * encounter), and 0x001AC008 (genus1 reinforcement); no literal constructor
 * address words. The party initializer func_001b1d70 uses index0..3 (sltiu
 * 4 at 0x001B1F70), reading battle+0xC74+index*4 and breaking on a null
 * descriptor before calling the genus0 constructor. Its continuation path
 * with battle flag0x20000000 skips party construction. Enemy population is
 * separately capped at six in the same initializer, and reinforcement passes
 * genus1 explicitly. Both are filtered by this target's genus0 test.
 * Consequently a normal four-member initialized party contributes at most
 * four actions, at most three after excluding this genus0 acting node.
 * No candidate array needs widening or a runtime truncation/cap. This proof
 * is for actual battle lifecycle/constructor contracts, not maliciously
 * forged cyclic lists, repeated externally forced initialization, or arbitrary
 * callbacks replacing the roster with invented nodes. Each count is <=3
 * on the normal actor-in-list path and <=4 under the weaker party-only bound.
 * The only callbacks in this target are external provider calls, none of
 * which appends roster actions (status predicates are leaf reads).
 *
 * PROVIDERS: COMPLETE RESULTS, NO GENERIC/FAKE TYPES
 * 1. func_00232710 is retail datCalcChkBadStatus, 0x00232710..0x00232723.
 *    Current owner src/datCalc/datCalc_grouped.c:104-107 defines
 *    u32 datCalcChkBadStatus(int unit, u32 badStatus). It loads the word at
 *    integer-address unit+0xC, ANDs the full u32 mask, returns 0/1 via sltu.
 *    It has no callback or write. Keep the existing integer-address ABI
 *    spelling in this promoted owner, but repair its u32 result/mask types.
 * 2. func_00243e30, retail 0x00243E30..0x00243E43, is s32 func(u16 *unit)
 *    in src/Main/Battle/Data/datCalc.c:2738-2740. It reads *unit & 0x200,
 *    returns exact Boolean 0/1; no output buffer and no callback.
 * 3. func_00247cb0 current definition src/cmmMisc.c:686-730 is
 *    u16 func(s64 actorId), not generic s32 func(s16). Retail extracts the
 *    signed low16 actor ID then switches IDs0..8 via table0x00747DA0.
 *    0,1/default ->0; 2->7; 3->11 or12; 4->5 or6; 5->3 or4;
 *    6->10; 7->14 or15; 8->24. In each paired case first ID is tried by
 *    func_001077f0, fallback chosen if absent. The chosen ID is then checked
 *    by func_001077f0 and replaced with0 if absent. Every path initializes
 *    the return value; no hidden input/output. The target passes a SIGNED
 *    16-bit actor ID, widened to the owner's s64 contract, then masks the
 *    u16 result before the community-rank call.
 * 4. func_001077f0: s32 input masked to u16, rejects/logs >=31, treats0 as
 *    absent, scans 21 entries of 16 bytes at D_00797410 comparing each +4
 *    u16 ID, returns exact0/1 for presence. For all mapper-produced IDs the
 *    assertion path is unreachable: they lie in [0,24].
 * 5. func_00107ac0 current definition src/cmmCommunity.c:556-585 is
 *    u16 func(s32 communityId). Same bounded 21x16-byte slot scan. ID0 or
 *    missing slot ->0. Found slot ->load its unsigned halfword at +6.
 *    Retail [0x00107AC0,0x00107B70) accounts for every path. The target
 *    masks to0xFFFF and stores the VALUE in an ordinary s32 rank local;
 *    numeric range [0,65535]. Do not truncate to u8 or assert rank<=10 as
 *    an unproven input invariant. Both comparisons in target are signed
 *    s32 against5 and7, with the preceding unsigned16 mask.
 * 6. func_00231d70 current definition datCalc.c:111-117 is
 *    u32 func(u32 count). Retail checks count==0, calls RpRandom, divides
 *    unsigned by count, and returns remainder. Target only calls with a
 *    positive initialized candidate count, so result is exactly in
 *    [0,count). No padding, extra state argument, or signed-random repair.
 *
 * EXACT DECISIONS / SIDE EFFECTS
 * - Reject after resetting outputs if acting genus!=0, ID==1, status matches
 *   0x1001FF, battle flag0x1000, action code+0x14==9, or status-record flag
 *   0x200. Status rejection precedes battle/action checks; action code is
 *   skipped when battle flag is already set. Then compute rank once.
 * - Traverse global+0x174 list until null, reloading node+0x450 AFTER each
 *   iteration/provider sequence. A node must have BOTH flags1 and8, must
 *   not equal the acting action, and its actor genus must be0. No actor-ID1
 *   exclusion applies to roster candidates: the preferred protagonist is a
 *   valid target. No extra HP, flags0x80, or status0x1001FF candidate filter.
 * - At rank>=5: status1 adds to highest-priority list. ONLY if status1 is
 *   absent, status0x100000 adds to second list. These are mutually exclusive.
 * - Independently, at rank>=7, status0x1E adds to third list; this may overlap
 *   the first or second list. Do not turn it into the same else-if chain.
 * - Each successful predicate independently reloads global+0x170 and
 *   remembers node if equal. The actor pointer is captured once per node;
 *   its +0xA64 status pointer is reloaded for each predicate call. Initial
 *   actor pointer is reloaded from action+0x30 after relevant call barriers.
 *   The C body deliberately does not hoist these reads across calls.
 * - After traversal, zero counts in order second,third,first ->return0 with
 *   outputs still -1/null. Otherwise choose first list, else second, else
 *   third. Store kind1 for first/second, kind0 for third BEFORE calling RNG.
 *   Prefer remembered global+0x170 node if present; otherwise choose the
 *   initialized array element at bounded RNG index. Store selected pointer
 *   +0x444 and return1. The final zero return is retained even though it is
 *   unreachable after the preceding count guard for valid unchanged locals.
 *
 * OUTPUT MEANING AND CONSUMER
 * +0x444 is an ACTION pointer, not actor or status-data pointer. State12
 * initializer func_001a3840 (literal callback0x005F6EB0) loads it and then
 * loads its +0x30 actor. +0x448 is a signed assistance-kind discriminator:
 * 1 selects status mask0x100001, 0 selects mask0x1E. The consumer builds its
 * own effect descriptor, sets its mask field, and applies it to the selected
 * action via func_001f36e0. It also copies the selected action into the
 * acting action's first target slot +0x38, sets +0x6A=1, and chooses distinct
 * animation/effect paths. Thus do not name kind1 a death/revive value without
 * additional game-status taxonomy proof; the recovered contract is the
 * explicit two-category status-recovery operation. func_001cf070 similarly
 * uses the 0/1 discriminator to choose distinct animation tables. Sentinel
 * -1 never reaches these consumers through the successful chooser path.
 *
 * INITIALIZATION / SPILL AUDIT
 * Every target-owned scalar is defined before use: action argument;
 * initial actor load; rank returned/masked before looping; all three counts
 * and preferred pointers set to0; node loaded from initialized global;
 * flags loaded per iteration; candidate actor set after qualifying flags.
 * Each array element is written at its old count then count increments.
 * An element is read only for a nonzero count and bounded RNG index, so
 * unused elements need no initialization. Preferred-pointer reads are safe
 * because all three pointers are initialized null. No arrays escape.
 *
 * The sq at0x001EFAD0 and lq at0x001EFB30/0x001EFBC0 are compiler-generated
 * rank spill/reloads. Only the ordinary low scalar is tested by slti; no
 * 128-bit arithmetic, vector load semantics, address-taking, high-lane
 * observation, or padding-based output exists. body.c correctly uses s32
 * rank, NOT s128 spA0, an uninitialized vector, or a manually padded object.
 * There is no target-local undefined-input blocker on any executable path
 * within the actual battle-object contracts above.
 *
 * DELIVERY
 * Directory /tmp/P4FreshRosterState contains the four requested artifacts:
 * body.c          Whole legal ordinary-C func_001ef9c0 candidate.
 * declarations.h  Exact external/current-owner contract declarations.
 * contracts.txt   Caller/constructor/provider/output/capacity/init audit.
 * notes.txt       This integration and instruction-coverage record.
 * No repository file was edited. No old candidate was used to infer a path.
 * No compiler probe/build/test/formatter/linter was invoked, per assignment.
 * Main owns source-shaping, compiler measurement, integration, and validation.
 * No exactness or normalized-diff claim is made for this uncompiled body.
 *
 * MAIN-OWNED DECLARATION REPAIRS
 * Current src/promoted/code1_001e.c is the canonical insertion owner; replace
 * its INCLUDE_ASM for this function at the FUN_001EF9C0 marker.
 * Use the existing u8* opaque-object and integer status-address conventions;
 * no new layout type, helper, wrapper, alias, or s128 object is required.
 *
 * At the source snapshot read during this task:
 * - line140: extern s32 func_00107ac0(s32 arg0) -> u16 result, same s32 input.
 *   Canonical definition is src/cmmCommunity.c:556, not the stale graph line.
 * - line143: extern s32 func_00247cb0(s16 arg0) -> u16 result, s64 input.
 *   Canonical current definition src/cmmMisc.c:686 is u16 func(s64).
 *   Existing callers in func_001efd50 and func_001eff50 already read s16
 *   actor IDs; widening those expressions to s64 is the real contract.
 *   Keep their explicit result masks unless Main measures a safe shape.
 * - line142: extern s32 func_00243e30(s32 arg0) -> s32 func(u16 *arg0).
 *   Existing sole C call at line3202 in func_001eff50 must change its
 *   argument from *(s32 *)(temp_16+0xA64) to *(u16 **)(temp_16+0xA64).
 *   body.c uses that same pointer type for the newly recovered call.
 * - line123 and block-scope copies at1395,1460,1500: func_00232710 must
 *   return u32 and accept (s32 unit,u32 mask), matching the current named
 *   datCalcChkBadStatus provider's int-address/u32 ABI. Remove the redundant
 *   block-scope declarations or synchronize all of them, not just line123.
 *   Its existing integer-address call expressions need no pointer migration.
 *   The symbol's function-name mapping already exists; do not create a new
 *   wrapper or parallel provider. Signed/unsigned Boolean result tests are
 *   identical because the real return is0/1, and every mask is a word.
 * - Existing u32 func_00231d70(u32) declarations are already correct.
 * - Keep s32 func_001ef9c0(u8*) result; current direct caller is ASM and
 *   tests zero/nonzero. Do not retag the result as a selected action pointer.
 *
 * SOURCE-SHAPING INFORMATION, NOT A COMPILER RESULT
 * Rank is one s32 scalar holding a masked u16 return. Retail spills that
 * scalar with sq/lq at sp+A0. The three real pointer arrays occupy D0,C0,B0.
 * The declaration order in body.c follows first status group, second status
 * group, third status group. Main may reorder ordinary declarations/control
 * flow to reproduce register allocation; do not add s128 spill/padding or
 * initialize unused array entries to force stack size. The explicit goto
 * check/loop/next structure preserves the initial branch and bottom reload.
 * No fixed-register variables or inline ASM are present.
 *
 * COMPLETE TARGET BASIC-BLOCK ACCOUNTING
 * EF9C0..EF9EC: E0-byte ABI frame, saves, action argument capture.
 * EF9F0..EF9F8: unconditional -1 halfword, then null pointer output reset.
 * EF9FC..EFA14: actor load, genus rejection with common return epilogue.
 * EFA18..EFA30: unsigned ID1 rejection.
 * EFA34..EFA58: status0x1001FF predicate and rejection.
 * EFA5C..EFA88: battle0x1000 OR action code9 rejection, short-circuit order.
 * EFA8C..EFAAC: reload acting actor/status, flag0x200 predicate rejection.
 * EFAB0..EFAD0: reload acting actor ID, signed16 mapper input, u16 community
 *               ID mask, rank provider, u16 rank mask, scalar spill.
 * EFAD4..EFAE8: zero three s32 counts and three preferred pointers.
 * EFAEC..EFAF8: reload battle pointer and roster head; initial loop check.
 * EFAFC..EFB2C: reload node flags, require1 then8; exclude self; capture
 *               actor pointer; require genus0. All failures ->EFC0C.
 * EFB30..EFB3C: rank<5 bypasses first and second categories.
 * EFB40..EFB54: status1 test; false ->EFB84.
 * EFB58..EFB68: successful status1 reloads global preferred node; remember
 *               exact equal candidate, otherwise retain prior initialized ptr.
 * EFB6C..EFB80: append to first array, increment32-bit count; bypass category2.
 * EFB84..EFB98: status0x100000 test; false ->EFBC0.
 * EFB9C..EFBAC: preferred-node handling for category2.
 * EFBB0..EFBBC: append second array, increment32-bit count.
 * EFBC0..EFBCC: rank<7 skips third category (independent of first/second).
 * EFBD0..EFBE4: status0x1E predicate; false ->EFC0C.
 * EFBE8..EFBF8: preferred-node handling for category3.
 * EFBFC..EFC08: append third array, increment32-bit count.
 * EFC0C..EFC14: read node+450 AFTER calls; repeat if non-null.
 * EFC18..EFC38: count2,count3,count1 all-zero guard ->return0.
 * EFC3C..EFC80: category1 priority, store kind1, prefer remembered ptr or
 *               random initialized element, output ptr, return1.
 * EFC84..EFCC8: category2 fallback, same kind1 and preferred/random choice.
 * EFCCC..EFD0C: category3 fallback, kind0 and preferred/random choice.
 * EFD10: final0 result.
 * EFD14..EFD44: common ABI restore, return and delay-slot nop.
 * EFD48..EFD4C: two retail alignment nops, not executable C padding.
 * Every branch, call, count increment, array store/load, and return is covered.
 *
 * RETAIL-IMAGE DISCOVERY EVIDENCE
 * Input orig/SLUS_217.82 is ELF32. Its first PT_LOAD maps file offset0x80
 * to VA0x00100000 for0x838A00 bytes. The aligned fixed-width scan covered
 * that loaded image (including code and data), seeking J/JAL opcodes with
 * exact26-bit target plus literal address words. Positive call sites were
 * resolved against current complete asm/code1.s; no completeness claim was
 * based on graph absence. Important observed lists:
 *   target001EF9C0: J/JAL 001F2C64; literal none.
 *   caller001F14F0: J/JAL 001A492C,001AECA8; literal none.
 *   allocator001B0930: J/JAL 0019F648,0019F6FC; literal none.
 *   constructor0019F5F0: J/JAL 001AC008,001B1DD8,001B1FCC; literal none.
 *   binder001B0910: J/JAL 0019F65C,0019F710; literal none.
 *   actor-ID initializer0019EA60: J/JAL 0019EF6C,0019F754,001AC038,0022B8D0;
 *                             literal none.
 *   teardown001B0BF0: J/JAL00192CDC; literal none.
 *   party-populator001B1D70: J/JAL none; callback literal005F71BC.
 *   action001A4800: J/JAL none; callback literal005F6ED8.
 *   action001AEC20: J/JAL none; callback literal005F6F94.
 *   assistance001A3840: J/JAL none; callback literal005F6EB0.
 *
 * Retail mapper jump table00747DA0 (IDs0..8), all nine words read:
 *   00247D9C 00247D9C 00247CF0 00247CFC 00247D20
 *   00247D44 00247D68 00247D74 00247D98
 * Caller action-kind table00747010 (indices0..12), all thirteen words read:
 *   001A4C14 001A4924 001A4924 001A4924 001A4C14
 *   001A4BEC 001A4A10 001A49F8 001A49F8 001A4928
 *   001A4C04 001A49F8 001A4BD4
 *
 * The shared Eval Python kernel is expected. A generic `words` name was
 * mutated by another active agent while investigating later lifecycle refs;
 * its empty-generator negatives were discarded, not used as evidence. All
 * lists above were rerun from an independently loaded immutable rs_words
 * tuple and rs_* helper namespace. Main and sibling were notified. No
 * shared generic-state negative is retained in these contracts.
 *
 * DISCOVERY/COVERAGE CAVEATS
 * CSP was used first for target/provider/caller discovery, followed by graph
 * search/trace and live search_code. The graph could not trace func_001ef9c0
 * as a function, and its provider source line numbers were stale. Coverage
 * checks for all cited source paths showed metadata_changed; exact target
 * and provider/caller ASM files showed parse_partial. asm/code1.s and the
 * retail orig subtree are excluded from indexing. Therefore current source,
 * complete target ASM and direct retail-word reads, not generated candidate
 * or graph signatures, control this delivery. Known parse-partial scopes
 * were not interpreted as exhaustive negative evidence; full retail scans
 * were used instead. No repository indexing mutation was performed.
 *
 * Tool-output defect reported through xd://report_issue: huge asm/code1.s
 * range reads sometimes give impossible small total-line counts in their
 * footer while displaying correct absolute line numbers. The displayed
 * requested instruction rows, not those footer totals, were used.
 *
 * VALIDATION STATUS
 * The actual target and all five direct-provider contracts were statically
 * recovered; caller-pointer and roster bounds were investigated through
 * current source, callback tables, complete target ASM, and retail image
 * reference scans. This assignment explicitly forbade all compiler/build/
 * test validation, so none is claimed. Main must measure bytes and run its
 * normal integration proof. There is no unresolved target-local undefined
 * input, truncated provider output, or missing executable path in body.c.
 */

/* Merge these declarations into the current owner; do not append conflicting
   declarations. Integer-address status ABI is the existing owner convention. */
extern u8 *iGpffffb3ac;
extern u32 func_00232710(s32 unit, u32 badStatus);
extern s32 func_00243e30(u16 *unit);
extern u16 func_00247cb0(s64 actorId);
extern u16 func_00107ac0(s32 communityId);
extern u32 func_00231d70(u32 count);
s32 func_001ef9c0(u8 *action);

s32 func_001ef9c0(u8 *action)
{
    s32 rank;
    u8 *status1Targets[4];
    u8 *status100000Targets[4];
    u8 *status1eTargets[4];
    u8 *node;
    s32 count1;
    s32 count100000;
    s32 count1e;
    u8 *preferred1;
    u8 *preferred100000;
    u8 *preferred1e;
    u8 *actor;
    u16 flags;

    *(s16 *)(action + 0x448) = -1;
    *(u8 **)(action + 0x444) = NULL;
    actor = *(u8 **)(action + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) {
        return 0;
    }
    if (*(u16 *)(actor + 0xA4) == 1) {
        return 0;
    }
    if (func_00232710(*(s32 *)(actor + 0xA64), 0x1001FF) != 0) {
        return 0;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x1000) ||
        *(u16 *)(action + 0x14) == 9) {
        return 0;
    }
    if (func_00243e30(*(u16 **)(*(u8 **)(action + 0x30) + 0xA64)) != 0) {
        return 0;
    }
    rank = func_00107ac0(func_00247cb0(
        *(s16 *)(*(u8 **)(action + 0x30) + 0xA4)) & 0xFFFF) & 0xFFFF;
    count1 = 0;
    count100000 = 0;
    count1e = 0;
    preferred1 = NULL;
    preferred100000 = NULL;
    preferred1e = NULL;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    goto check;
loop:
    flags = *(u16 *)(node + 0x1A);
    if ((flags & 1) == 0) goto next;
    if ((flags & 8) == 0) goto next;
    if (node == action) goto next;
    actor = *(u8 **)(node + 0x30);
    if (*(u8 *)(actor + 0xA2) != 0) goto next;
    if (rank >= 5) {
        if (func_00232710(*(s32 *)(actor + 0xA64), 1) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1 = node;
            }
            status1Targets[count1] = node;
            count1++;
        } else if (func_00232710(*(s32 *)(actor + 0xA64), 0x100000) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred100000 = node;
            }
            status100000Targets[count100000] = node;
            count100000++;
        }
    }
    if (rank >= 7) {
        if (func_00232710(*(s32 *)(actor + 0xA64), 0x1E) != 0) {
            if (*(u8 **)(iGpffffb3ac + 0x170) == node) {
                preferred1e = node;
            }
            status1eTargets[count1e] = node;
            count1e++;
        }
    }
next:
    node = *(u8 **)(node + 0x450);
check:
    if (node != NULL) goto loop;
    if (count100000 == 0 && count1e == 0 && count1 == 0) {
        return 0;
    }
    if (count1 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred1 = preferred1 != NULL ? preferred1 :
            status1Targets[func_00231d70(count1)];
        *(u8 **)(action + 0x444) = preferred1;
        return 1;
    }
    if (count100000 != 0) {
        *(s16 *)(action + 0x448) = 1;
        preferred100000 = preferred100000 != NULL ? preferred100000 :
            status100000Targets[func_00231d70(count100000)];
        *(u8 **)(action + 0x444) = preferred100000;
        return 1;
    }
    if (count1e != 0) {
        *(s16 *)(action + 0x448) = 0;
        preferred1e = preferred1e != NULL ? preferred1e :
            status1eTargets[func_00231d70(count1e)];
        *(u8 **)(action + 0x444) = preferred1e;
        return 1;
    }
    return 0;
}
