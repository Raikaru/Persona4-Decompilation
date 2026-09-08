/* classification=BLOCKED_UNDECLARED_INCOMING_S1; retail_window=1184;
 * source_probe=not_run; production=ASM. This is evidence, not a C candidate.
 *
 * Entry saves s1 at 0x0022a748 without defining it. The first list pass only
 * writes s1 at 0x0022a7f8 when an active action/unit has status bit 0x100.
 * The unconditional read at 0x0022a80c therefore depends on incoming s1 if
 * no action matches. A nonzero value later supplies the unit at 0x0022a860.
 * Initializing a last-match pointer to NULL or testing count instead changes
 * retail behavior; an uninitialized C local does not provide a defined fix.
 *
 * func_0022dc70 schedules this initializer on a NONmatching status action
 * (0x0022e23c break, 0x0022e250 test), not proof of any matching action.
 * func_001fac80 calls +0xb40 at 0x001faccc with only the +0xb48 context;
 * it ignores the result and does not establish s1. Reviewed upstream
 * func_001afa50 likewise does not establish s1. The ABI is void(action),
 * unlike the paired integer-returning updater func_0022abd0.
 *
 * Executed evidence: a small decoder ran actual retail instruction bytes
 * with identical empty-list memory, a0 and other registers. Incoming s1=0
 * returned after 33 instructions; s1=0x4000 reached jal 0x001d3700 with
 * a0=2,a1=0xfff after 27. Both set world flags to 0x80000. No external call
 * was executed. This is a scoped MIPS-prefix experiment, not console or
 * whole-game execution, and does not assume empty lists are normal gameplay.
 *
 * Full 1184-byte retail was reviewed. Both passes use active/type/status
 * filters, real task allocation/enqueue order, and full u64 UID/dependency
 * stores. The second pass separately reloads data pointers for three flag
 * clears; a u16 ordinal selects D_00635530 at 12-byte stride. Movement UID
 * is read after its enqueue and the following rotation allocation.
 * Another unresolved prerequisite is func_00196040's unwritten center
 * output when no units qualify; no invented center initialization is added.
 *
 * Required next evidence: a source-level invariant making the incoming-s1
 * read unreachable, or an explicitly authorized reconstruction contract
 * change. No partial body, extra parameter, pinned register or UB is stored.
 *
 * Fresh complete audit confirms a nonempty registration counterexample:
 * one active target, unit flag 8, and datUnit status 0x100 clear passes
 * func_0022dc70's selection but never writes s1 in this initializer.
 * The status provider reads datUnit+0xC; preliminary packet creation does
 * not synchronously set that status. func_0022bd00 only tests root+0xBA0
 * and provides neither a selected target nor the missing status invariant.
 * No new candidate or compiler probe was produced by this audit.
 */
