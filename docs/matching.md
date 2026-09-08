# Matching playbook: source-shaping for MWCCPS2

Hard-won, reusable source-shaping tricks for making `mwccps2`
(`mwcps2-3.0.1b210-060308`, `-O2 -Iinclude`) reproduce retail Persona 4 codegen
byte-for-byte. This is the "every reusable source-shaping lever" file the
roadmap points at. Techniques were validated in the Persona 3 FES campaign
(its `docs/matching.md`) and are written up here compiler-general; they apply
to any PS2 MWCCPS2 codebase, not to specific P3 files.

Rules of engagement:

- Every entry must be confirmed on your function by `python tools/verify.py`
  reporting `MATCH` before you trust it. Techniques are **per-function**: the
  same construct that matches one function walls the next.
- Diff a single function with `python tools/fndiff.py <file> <fn>`. Rows
  marked `!` are real reloc-masked differences; the trailing count also counts
  zero-padding tail words when the object is shorter than the retail window, so
  a nonzero count on a `!`-free listing is padding, not a bug.
- If only register allocation, instruction scheduling, evaluation order,
  FPU-register choice, or commutative operand orientation remains after
  exhausting the levers below, it is a compiler floor. Keep production as
  `INCLUDE_ASM`/ASM; do not leave a `NONMATCHING` C body in `src/`. Preserve
  the best semantically faithful C only in the existing `docs/probe_archive/`
  record with its measured result, then move on. Never claim that a floor is
  impossible.

Current lint policy is defined in `docs/STYLE.md`: marker and assembly
integrity, pragma stack structure, and scan failures are hard gates.
Volatile-context, optimization-provenance, and dead-store checks are advisory;
`register` and restoring optimization level 2 are not violations. A generic
measurement note never waives assembly-integrity rules. Historical campaign
notes below describe the policy in force when those experiments were run.

## Operating procedure

Use this six-step loop for every target:

1. **Stage the shape before tuning.** Recover the EE ABI and types/prototypes,
   then match the frame and values live across calls, then reconstruct the
   CFG/branch layout. Only after those agree, try instruction scheduling,
   register coloring, or operand orientation.
   Compare M2C (`src/generated/`) with available IDA
   (`docs/ida_headstart/`) and Ghidra (`docs/ghidra_headstart/`) bodies.
   They are independent references, not authoritative source: resolve
   disagreements against retail assembly. IDA's register annotations can
   clarify lifetimes, but guessed extra arguments and register-width
   pseudo-types are not proof of an ABI.
2. **Reuse the proven catalogue.** Start with the symptom table below and its
   linked technique section. Write one named hypothesis (`H: ...`) and change
   only the source shape that tests it; do not invent a new steering form when
   a measured lever applies.
3. **Probe in isolation.** Use a bounded family against one target:

   ```
   python tools/probe_variants.py SOURCE FUNCTION --candidate NAME=PATH
   python tools/probe_archive.py ARCHIVE SOURCE
   ```

   These are read-only probes: they never write production `SOURCE` on
   success, failure, or interruption, and there is no `--keep` mode. If the
   family yields no new evidence, stop and record a measured floor; do not
   call it impossible.
   Archive notes and pragma brackets are preserved. Marker lookup stops at
   the definition or next marker, not a fixed number of header lines.
4. **Rank for payoff.** Prefer untried ordinary-C targets with a known matched
   analogue, sibling, or TU above hardware-only targets and floor families
   already exhausted by repeated measured probes.
5. **Bound the batch.** Keep at most four independent owners on disjoint
   targets; use no nested workers. Do not poll or send checkpoint chatter, and
   do not run broad validation mid-flight. Finish with one final reproducible
   result for the batch.
6. **Gate before installing.** A low or zero score is only a proposal. Reject
   semantic changes, wrong relocation/addend matches, and forbidden steering
   below. After target and semantic verification, install a winner with a
   separate deliberate source edit. Any TU, declaration, or relocation change
   requires a full `tools/build.py` link and linked-image comparison.

### Symptom → technique → measured anchor

| Symptom | Technique (see) | Measured anchor |
| --- | --- | --- |
| Integer/float arguments land in the wrong registers or order | Independent ABI counters; [Types and the EE ABI](#types-and-the-ee-abi) | `func_0047f4d0`: pointer-first signature puts `$a0` before `$f12` |
| A known helper leaves extra saves or a final scheduling residual | Static helper/caller cluster; [Types and the EE ABI](#types-and-the-ee-abi) | `sdkChkmem`: reuniting `func_0044e8d0`, `func_0044e920`, `func_0044e9e0`, and `func_0044ee70` removed the last store/move residual |
| Private helper removes the spill, but argument setup still swaps a load and move | Stage arguments with scoped `opt_propagation off` | `func_00278d50`: private `func_00278c60` plus staged fixup pointer/size gives 76B matching instructions and a 4B zero tail; helper remains 240B MATCH |
| Call-crossing spills or frame size are too small | Aggregate snapshots; [Types and the EE ABI](#types-and-the-ee-abi) | `func_0047f040`: two `Pair` snapshots produce retail's `0x20` frame (scalar locals produced `0x10`) |
| Saved-register colors are wrong while the body shape is right | Declaration order; [Register allocation and caching](#register-allocation-and-caching) | `frFont func_002739e0`: declaration-order closure, object/window `724/736`, normalized diff `0` |
| Loop bases or constants rematerialize in the body | `opt_loop_invariants on`; [Loops](#loops) | `func_00161bb0` nd `45 → 0`; `func_0045b430` nd `8 → 0` |
| A reloc-masked `MATCH` names the wrong global | Check the retail immediate/addend; [Globals and addressing](#globals-and-addressing) | `func_004a8bb0`/`func_004a8f90` both masked `MATCH` but had wrong GP references; only the linked image exposed it |

### Semantic and target gate

- Reject a candidate that moves an observable load across a call whose
  mutation set is unknown. In `nLine` `func_0034e0b0`, the alpha-last probe
  reached nd23 by moving the alpha field load across `func_00457120`; reject
  it and retain the semantically faithful nd35 body.
- Reject omitted call arguments and incompatible empty-prototype casts even
  at nd0. The `func_0028ad90` archive's apparent two-word register floor
  omitted the child argument to the already-typed `func_00286c60`. Passing
  that child could produce nd0 only while retaining a wrong zero-argument
  cast of the deallocator. With both calls repaired, the faithful candidate
  is 596B against retail's 592B window and stays ASM. Inspect callee bodies
  before calling an argument-register difference an allocation floor.
- Audit apparent register passthrough even in existing matches. Community
  flag helpers `func_00107b70`, `func_00107c80` and `func_00107ea0` had
  zero-argument definitions calling the old-style `func_001070e0()` declaration,
  accidentally leaving the incoming identifier in `$a0`. Explicit `s32`
  parameters and forwarding calls preserve all three 84B/96B matches; the
  lookup remains 152B/160B MATCH with a complete prototype. A consumer smoke
  exercises 192 cases across record IDs, upper-bit masking, absent records
  and flag combinations. Assembly identity does not excuse missing C arguments.
  The model callback `func_00475b10` likewise retains its instruction match
  when it passes the frame to `s32 func_00397470(u8*)` and compares a signed
  ID instead of calling a false `void* (void)` prototype. The original
  callback crashes in a 32-bit consumer smoke; the repaired one passes
  45 cases across plugin offsets, nested/missing matches and signed ID limits.
- Audit missing C returns when retail preserves a callee result in `$v0`.
  Field-task constructors `func_00166b40`, `func_00167420` and
  `func_00167d90` now explicitly return the task created by `func_00451fc0`,
  after initializing its work data. All three retain their instruction
  matches; the complete `k_fldUnit.c` unit remains 34 MATCH / 8 ASM.
  A 32-bit consumer smoke fails the original change-list handle check and
  passes 288 cases after repair, covering returned handles, payloads, packed
  IDs, unit flags, gates, allocation failure and task-creation failure.
  A null constructor result still permits the retail work-data writes;
  do not introduce an early return that skips those writes.
  Their change-list caller `func_00134be0` is now 444B/448B MATCH with
  scoped loop-invariant hoisting, `s16 party[4]`, four eight-byte change
  records and the canonical `s16 func_00106cd0(s16,s16)` declaration.
  Its 32-bit consumer smoke passes 4,608 cases covering membership, signed
  before/after values, zeroed unused records, all three stat-query side
  effects, task-creation failure and preservation of the old handle when
  there are no changes. The retail-sized frame needs no invented padding.
- Recover distinct logical variables before tuning generated register names.
  The old `func_00313800` archive reused the item limit for unrelated values
  and omitted flag offsets. Separate signed row/item/selected counters,
  canonical list-helper parameters and the pointer-returning availability
  getter restore the behavior. Declaring row, item, then selected closes the
  remaining saved-register rotation: 452B/464B MATCH with zero tail padding.
  A 32-bit consumer smoke passes 40,960 cases across row filtering, compacted
  output columns, signed IDs, availability flags and untouched bytes.
  The neighboring date callback `func_00313b50` reaches 464B/464B MATCH by
  sharing the two sentinel-table scans in a private inline helper and
  hoisting loop invariants. Passing the date getters directly to the first
  renderer call avoids an intermediate byte truncation while preserving
  retail call order. Its smoke covers all 65,536 byte pairs against four
  table layouts, plus 2,976 callback cases for rollover, refreshed dates,
  duplicate precedence, signed sentinel bytes and untouched state.
  Consult the corresponding IDA body before further probes. For
  `func_00313d20`, Hex-Rays distinguishes branch-local table/entry pointers
  and a saved mode that the initial reconstruction merged. Its translation
  improves the safe floor from 89 to 84 differing words (644B/656B), still
  ASM. The archived counter now consistently uses the mode-times-two base,
  rather than the mode-times-five flag base mistakenly reused by the old
  body. A native smoke passes 40,960 cases covering both modes, signed
  priorities, first-winner ties, priority-100 flags, counts and untouched bytes.
  The same IDA-first pass improves `func_001130c0` from 54 to seven differing
  words (440B/448B): five cached-color/alpha scheduling differences and two
  zero-tail words. A real 76-byte text buffer plus four-byte color aggregate,
  the by-value position ABI, and canonical variadic formatting preserve the
  complete rendering contract; 1,920 native cases cover signed numbers,
  reversed glyphs, cached colors and post-formatter width reads.
  For `func_00207140`, natural unsigned skill/item loops and canonical helper
  types give a 476B/480B floor of 35 differing words. The superseded signed
  skill temporary incorrectly admitted IDs at or above 0x8000. Its 2,048-case
  native smoke checks those boundaries, eight accepted skills, optional
  actions, repeated quantity queries, ID-store visibility and untouched
  bytes. Neither candidate is promoted.
  The cut-in `func_001f9cf0` IDA body confirms its case-local suffix pointer
  and signed count. The retained body now uses the known four-word
  pointer-first floor with canonical helpers and explicit string pointers.
  A 3,136-case native smoke uses retail format strings and S/W, B/C/D tables
  to check resource paths, the character-11 branch, call order, handle slots
  and untouched bytes. Ordinary C `register` hints on either count-first
  local leave that variant at eight words; production remains ASM.
  For `func_0016b080`, IDA and retail callers recover the output-normal
  pointer rather than an `s64` input. The 460B/480B candidate improves the
  corrected floor from 97 to 93 words and stays ASM. Its 13,440-case
  32-bit smoke checks exact query results and short-circuiting, changed
  global context, unsigned list keys, first-match/fallback precedence,
  float grid boundaries, pointer identities, fraction bits and outputs.
  Multiply signed grid coordinates by their strides instead of left
  shifting negative values; this removes C undefined behavior without
  changing the measured code.
- Give output helpers a complete valid buffer, not adjacent scalar locals.
  `func_001d1310` writes eight bytes; the `func_001d15a0` archive now supplies
  `u16 stats[4]`. The corrected 212B candidate retains nine emitted-word
  index/result register differences against the 224B retail window and stays
  ASM. Its `fndiff` count is 12 words including three absent zero-padding
  words; do not compare that with `verify.py`'s byte-valued `normalized_diff`.
- Reject wrong GP addends and relocation-masked false matches: compare every
  GP-relative or `%hi`/`%lo` reference with the retail immediate, not the
  guessed symbol name, and use the full link when relocation ownership changes.
- Reject ordinary-memory `volatile` and ordinary-CPU inline asm used as
  compiler steering, even when the score is zero. Genuine hardware accesses
  may use the established hardware-only asm pattern, with accurate operands
  and clobbers. Verify the intended target/function owner before installation.
- Preserve hardware register values, not a guessed scalar substitute.
  `sqc2 $vf0` stores `(0,0,0,1)`, not a zero quadword. The former
  `func_00484b30` archive incorrectly cleared four W lanes; the corrected
  four-COP2-store candidate is 120B/128B with six register-color differences
  and two zero tail words. It remains ASM, not a promoted match.
- An address left in `$v0` for a hardware transfer is not proof of a C return.
  The observed callers of `func_0048a460` consume `$vf10`, not `$v0`.
  Removing the archive's unsupported local-array pointer return gives an
  honest `void` projection body at 176B/176B and 15 differing words, rather
  than the misleading 11-word floor. Aligned storage and exact vector memory
  operands describe the genuine COP2 transfers without escaping local storage.
- Check runtime provenance before counting a compiler-floor closure as game
  progress. `func_0044e830` is GCC `fp-bit.c` GOFAST `float_to_usi`, not a
  memory initializer: ee-gcc 2.96 reproduces 156B/160B with only a zero tail.
  The matched C lives in the isolated `src/middleware/gcc_fp.c` ee-gcc unit,
  retaining the upstream GPL notices and linking exceptions; its license is
  alongside it in `COPYING.gcc-runtime`. This is a runtime match, not a
  first-party match. Runtime classification does not remove it from overall
  C-matching work. As with the other configured GCC units, the current
  linker still uses extracted assembly; this increases compiler-verified
  C matching, not C-linked coverage.
  Reproduce with `python tools/verify.py src/middleware/gcc_fp.c`.
- Independently check signedness, truncation and extension at calls and stores;
  aliasing and alignment assumptions; every cross-TU caller before making a
  helper static; and switch tables or other owned data. Record unresolved
  assumptions rather than treating a low instruction score as proof.

### Acceptance levels and evidence

Report these separately; an unmeasured level is **unverified**, not passed:

| Level | Required evidence | Does not prove |
| --- | --- | --- |
| Instruction match | `tools/verify.py` reports `MATCH`; inspect `tools/fndiff.py` residuals and accepted zero-tail padding | Correct relocation targets, data sections, or link eligibility |
| TU link eligibility | `tools/build.py --progress-report` confirms the TU is C-linked with owned sections and resolved relocations accepted | That every other TU is C-linked |
| Retail identity | The complete linked image and rebuilt ELF have the expected retail hashes | That fallback assembly has been replaced with C |

For each installed match or archived floor, retain this record with the existing
archive/comment or batch evidence (do not create a second archive system):

```
Target: source path, function, retail address
Candidate: path and SHA-256; full TU/context SHA-256
Compiler: exact version, flags, relevant scoped pragmas
Commands: exact probe, verify, and build invocations actually run
Instruction result: object/window bytes, normalized diff, residual explanation
TU eligibility: verified C-linked / rejected with reason / unverified
Retail identity: measured image and ELF hashes / unverified
Semantic review: assumptions checked, remaining caveats, rejected alternatives
```

Use `sha256sum SOURCE CANDIDATE` to bind evidence to measured inputs. A later
edit invalidates the recorded measurement until replayed; a command written in
a note but not executed is not evidence.

### Integration baseline and commits

Before starting a new batch, run the tooling tests, full verifier, and full link.
Keep their reports and hash outputs together as the baseline. Account for every
missing canonical owner before changing marker-count expectations. Splat output
can include curated symbols from its input symbol map, so it is not independent
evidence that a curated boundary was discovered automatically.

Commit coherent verified batches: probe tooling separately from matching
closures, and source/TU changes together with their required symbol or data
updates. Record commands and outcomes in the commit message. Do not commit
temporary probes or imply that instruction `MATCH` alone proves retail identity.

## Types and the EE ABI

- **Independent int/float argument register files.** The EE o32-hardfloat ABI
  fills integer args (`$a0`...) and float args (`$f12`...) from *separate*
  counters. `f(void*, float)` puts the pointer in `$a0` and the float in
  `$f12` (not `$a1`). Source argument order controls the *materialization*
  order of the two moves: if retail computes `addiu $a0,...` before
  `mov.s $f12,...`, put the pointer first in the C signature.
- **Keep a known local callee `static` in the caller's translation unit.**
  An `extern` declaration can make b210 preserve every live caller-save value
  across the call, even when the retail compiler knew the callee's narrower
  clobber set. Restoring the exact helper body beside its caller and marking
  it `static` lets register-use analysis retain untouched `$t`/FPU argument
  registers. In `func_0047f4d0`, this removed `$s0`/`$f20`/`$f21` saves and
  shrank the frame from `0x50` to retail's `0x30`; the adjacent pointer-first
  signature rule then ordered `$a0` before `$f12`.
  Do not internalize a helper while another object still references it: move
  the complete helper/caller cluster into the recovered original TU. Reuniting
  `func_0044e8d0`, `func_0044e920`, `func_0044e9e0`, and
  `func_0044ee70` in `sdkChkmem.c` removed the latter's final store/move
  scheduling residual while preserving every helper exactly.
- **Use scoped `auto_inline` when the standalone callee must survive.**
  In `btlOrder_grouped.c`, `auto_inline on` retained `func_001b13c0` while
  inlining its body into `func_001b1450`; plain `inline` removed the standalone
  symbol. Both retail windows are required. The emitted bodies are 132/144B
  and 188/192B respectively, with only zero-filled tail padding; full linkage
  reproduces the retail image and ELF hashes. Restore `auto_inline off`
  after the cluster rather than changing unrelated callers.
  When internalizing helpers, the linker's export set must exclude local
  symbols: only global and weak definitions satisfy references from other
  objects. A same-named local definition must not suppress a required
  canonical address definition.
- **Form destination and source row pointers inside the loop before hoisting.**
  In `func_0034ba30`, explicit `dst = table + i * 84` followed by
  `src = defaults + i * 20`, inside the loop, gives b210 the required
  destination-first address dependencies. Scoped `opt_loop_invariants on`
  then hoists the table bases after the counter initialization. This closes
  the old address-order/register-coloring floor: 212B of exact instructions
  in a 224B window, with 12B of zero padding. Merely declaring both table
  bases before the loop did not reproduce that schedule.
- **Separate equivalent narrowing forms when only masks must escape CSE.**
  `func_00144b80` uses `(u16)arg` at its first predicate call and
  `arg & 0xFFFF` at the second. Both pass the same nonnegative low-16 value
  to the unchanged `s32` parameters. b210 recomputes the masks at each call
  while still sharing the success literal. Disabling CSE globally lost that
  literal sharing; narrowing the predicate signatures instead regressed a
  sibling and introduced cross-TU type conflicts. The ABI-preserving body
  matches 264B in a 272B window, with eight zero-tail bytes.
  The same lever closes `func_00247dd0`: use a cast for the bounds check,
  a mask for the record offset and category-call index, then cast again for
  the eligibility call and return. This keeps the raw counter without an
  extra saved masked-index register. All-cast spelling differs by 55 words;
  the mixed spelling matches 228B plus 12 zero-tail bytes, with no pragma
  or ABI changes.
  For `func_00279030`, pass `(u8)arg2` to the constructor and retain
  `(u32)arg2 & 0xFF` at the later setter call. This removes a cached mask
  across the call. Pair it with the integer-address load of `obj + 4` before
  the unsigned index scale: the complete 448B body then matches.
- **Preserve staged offsets while separating equivalent address forms.**
  In `func_002774d0`, test the slot through an integer address
  `i + (u32)manager + 0x10`, but reload it after the copy call through
  `manager + i + 0x10`. This prevents whole-slot CSE. Also disable propagation
  locally so `i *= 4` stays in its saved register instead of being repeated
  at each use. Neither lever alone matches; together they produce 452B of
  exact instructions plus 12 zero-tail bytes. Retain the post-call reload
  and retail's diagnostic paths rather than replacing them with cached data
  or new bounds checks.
- **Use the allocation header's storage unit before sweeping registers.**
  In `func_0026e010`, a `u32 *base` and `base + 1` represent the four-byte
  header directly. Compared with `u8 *base` and `base + 4`, this closes eleven
  register-rotation words without a pragma. Keep the pointer-value copy call
  and the existing byte-stride helper: the ring has `count + 1` records and
  returns the first record, not the allocation header. All 204 instruction
  bytes match, followed by four zero-tail bytes.
- **Try the equivalent comparison orientation before a register sweep.**
  With propagation disabled in `func_0034f5d0`, `distance <= half`
  closes twelve differing words left by `half >= distance`: the comparison
  temporary and surrounding register allocation change together. Direct
  short predecrement and a separately staged random remainder also preserve
  the required store order and post-call field loads. All 336B match.
- **Let invariant hoisting move natural vertex assignments, not vice versa.**
  In `func_001604a0`, assign left X, top Y, right X, then bottom Y in vertex
  store order. With `opt_loop_invariants on` and `opt_propagation off`,
  b210 moves the row-only Y work out of the inner loop while retaining the
  required float register allocation. Preparing those floats explicitly
  before the inner loop left 14 instruction-word differences.
  The matching body is 252B in a 256B window. Reconstruct coordinates and
  load lifetimes before probing: the obsolete archive used the wrong
  right-edge X and top Y and reloaded depth instead of snapshotting it.
- **Correct pointer types before diagnosing computed-address argument order.**
  `func_00190920` needs the lookup declaration
  `void *func_003ef650(void *, const char *)` and byte-pointer name expressions
  for both lookup and variadic printing. Combined with scoped
  `opt_common_subs off`, these restore first-argument materialization before
  the name's `+0x10` address computation. Pointer types alone did not close
  the floor, nor did disabling CSE with the old integer lookup declaration.
  The result is 196B of exact instructions plus 12B of retail zero padding;
  the caller's existing ABI remains unchanged.
- **Split dependencies before an inline `madd.s` source-order helper.** If a
  direct `0.0f + addend + left * right` has the final two FPU operands
  transposed, pass `(left, right, addend)` to a tiny inline helper containing
  that expression. Compute `left` first and load `addend` into a separate local
  afterward; passing the load expression directly lets b210 hoist it and shifts
  otherwise exact conversion code. This produced retail's final
  `madd.s` operand order in `func_0047f1a0` without inline assembly.
  When the result register aliases `left`, the same source order may commute
  during fusion; a second helper spelling `right * left` closed all three
  `func_0047f5b0` accumulators.
- **Snapshot adjacent globals through a matching aggregate to force exact
  call-crossing spills.** Writing a two-float global pair, then assigning
  `local = *(Pair *)&global` gives b210 one aggregate copy to preserve. In
  `func_0047f040`, two such snapshots produced retail's `0x20` frame and exact
  `sp+0x10..0x1c` stores/loads; scalar locals stayed in FPU registers and
  incorrectly shrank the frame to `0x10`.
- **Ghidra mistypes float returns and args as `int`.** A callee returning
  `float` shows as `undefined4`/`uint`; a `float` parameter shows as
  `undefined4`. Trust the disassembly: `mov.s`, `swc1`, `lwc1`, `cvt.*` mean
  float. Declare `float FUN_x();` and `void FUN_y(void*, float);` accordingly.
- **`bool` is not a valid type here.** Use `u8`/`u32` for predicate returns.
- **Typed `short`/`char` prototype params defeat sign-extension CSE.** Retail
  re-sign-extends a `short`/`char` arg at *every* call site; a bare `(short)`
  cast in the caller gets CSE'd into one extension. Declaring the callee
  `int f(short)` / `void f(char)` forces per-call `dsll32;dsra32` (or `lbu`).
- **`int`, not `char`, for a callee-saved local** whose extension retail
  defers to a `char`-typed callee parameter.
- **`u32`/`int` return, not `u8`,** to drop a spurious `andi 0xff` on the
  return value.
- **`float` constant with a zero low half** (e.g. `100.0f` = `0x42c80000`)
  materializes inline as `lui;mtc1` with no rodata `lwc1`. Pass `100.0f`
  directly to a `float`-typed callee.
- **By-value 2-float struct param** (sd-spill + `lwc1/swc1` copy at the call):
  pass a `typedef struct { f32 x, y; }` by value.
- **12-byte float block copy** (retail loads all three then stores all three:
  `lwc1 f2,f1,f0` / `swc1 f2,f1,f0`) → struct assignment of an existing
  `{ float x, y, z; }` type. Plain per-field float assignments interleave
  `lwc1/swc1` and will not match.
- **u16 field load width.** A direct `*(u16*)((int)p + off)` emits `lhu`;
  `*(short*)` emits `lh`. Only add a `(u16)`/`(short)` cast on the *other*
  operand when retail actually emits `andi`/sign-extend.

- **Address-take incoming stack slots to prevent parameter homing.** When
  retail reloads several stack arguments from their incoming slots after
  calls, declaring the slots as `s64` and reading the needed width through
  their addresses (`*(s32 *)&argN`, `*(u8 *)&argN`) keeps plain `lw`/`lbu`
  reloads at those offsets. Declaring them as `s32`/`u8` parameters can make
  b210 home a reused value into an `$s` register or byte spill at entry,
  shifting both the saved-register set and the frame. This closed
  `k_field.c` `func_00155e10`.
- **Split a narrow branch result from its widened join role.** If two arms
  return an `s8` and retail extends exactly once at their common join, assign
  both arms to an `s8 pick`, then write `s32 cur = pick` after the label.
  Using one `s32` throughout extends in each arm; keeping one `s8` throughout
  re-extends at later comparisons. The two-name spelling closed
  `y_fclCombine.c` `func_003040d0`.

## Control flow and branch polarity

- **Branch polarity is per-`if` and nests.** Retail out-lines the taken block.
  Invert the `if` so the *fall-through* body matches retail's inline body.
  Nested `if`s may each need inverting independently — inverting only the outer
  leaves the inner `bnez`/`beqz` mismatched.
- **Early-return inversion.** `if (cond) { body } return X;` where retail
  out-lines `body` → `if (!cond) return X; body; return X;`.
- **Branch-materialized predicate.** `return (x == 0)` → `if (x != 0) return 0;
  return 1;`.
- **`!(...)` vs `== 0`.** Retail's `sltu $zero,v0; xori 1` needs `!(...)`, not
  `== 0`.
- **`(~x & N) == 0` stays literal** — do not simplify to `(x & N) == N`.
- **Assert `field <= N` vs `field < N+1` flips the `slti` destination
  register.** When the compared value is dead after the test, retail reuses the
  value's own register (`lw $v1,off(base); slti $v1,$v1,4`); mwcc lowers the
  literal `<= N` through the `$at` pseudo. Rewriting as the equivalent
  `< N+1` keeps the value's register. If the value *is* reused after the test,
  retail itself uses `$at` — then keep `<= N`.
- **Switch case test order follows REVERSE written order — SOLVED, it was
  never a floor.** This entry used to say mwcc emits compares in
  numeric-ascending case order and that a higher-case-first retail dispatch
  was unreachable. Measured against b210:

  ```c
  switch (k) { case 0: f0(); break; case 1: f1(); break; }  /* beq (1) first, then beqz (0) */
  switch (k) { case 1: f1(); break; case 0: f0(); break; }  /* beqz (0) first, then beq (1) */
  switch (k) { case 2: ..; case 1: ..; case 0: ..; }        /* tests 0, then 1, then 2 */
  ```

  **The last-written case is tested first.** So retail testing case 1 before
  case 0 means retail's source wrote `case 0` before `case 1` — reorder the
  cases in the source to the reverse of retail's test order. An `if`/`else
  if` chain, by contrast, tests in *written* order and uses `bne`
  fall-throughs rather than the switch's `beq` jumps to bodies; the two
  forms are distinguishable in the object by that. A `default:` written
  between cases does not change the case test order. Numeric value has no
  effect on the order at all; the earlier claim came from functions whose
  source happened to list cases ascending.
- **A matching function body does not prove a matching switch table.**
  `verify.py` masks relocation-owned bytes, including the `R_MIPS_32`
  jump-table entries in `.rodata`, so a permuted table can hide behind an
  byte-identical body. The linker build (`tools/build.py`) only C-links a
  translation unit whose owned data sections (`.rodata`, `.data`, `.sdata`,
  `.sbss`, `.bss`) can be placed byte-exact — direct byte comparison where a
  section carries no relocations, relocation resolution otherwise — so a
  permuted table surfaces as a byte difference in the linked image. Reorder
  the source cases to reproduce retail's table (this changes only the table
  addends and restores retail identity).
- **A switch table behind an INCLUDE_ASM neighbour.** mwld concatenates a
  unit's `.rodata` in function order, so a C switch function that follows an
  INCLUDE_ASM switch function in the same unit lands its table where the
  fallback's table should be, and `tools/build.py` refuses the unit (the
  cldDayChange.c `func_00266690` case: scoped MATCH, unit silently unlinked).
  Give the fallback `.s` its own `.section .rodata` / `.align 4` /
  `dlabel jtbl_XXXXXXXX` block of `.word .Lcase` entries, with `.L` labels
  on the case heads (`asm/nonmatchings/cldDayChange/func_00266050.s`);
  mwccgap transplants it with the declared alignment and the concatenation
  is byte-exact again. Use `#` comment lines in a fallback `.s`: a multi-line
  `/* */` block is counted as instructions by the placeholder scan.
- **A GP-relative symbol name is not evidence; the retail immediate is.**
  Relocation masking makes `iGpffffXXXX` interchangeable with any other GP
  symbol under `verify.py`, so a MATCH body can read the wrong global. Sweep:
  for every `R_MIPS_GPREL16` row in the verify JSON whose symbol is a bare
  `[ifd]GpffffXXXX`, the name suffix must equal `retail_imm` unless the source
  expression carries an explicit offset (`&sym + 8`, `sym[1]`, a struct
  field). A sweep on 2026-09-03 found 26 wrong symbols across 24 MATCH
  functions in 14 unlinked units (strings mistaken for scalars, pi/2 read as
  a different constant, sibling pointers off by one slot). Linked units are
  immune: the full-image SHA1 resolves every relocation. Register the
  corrected name in `config/symbol_data_addrs.txt` from `GP + signed(imm)`.
- **Repeated reloads of the same bytes: `volatile` on the source pointer.**
  `func_0045ed60` copies `arg0[0..3]` into three consecutive 4-byte slots of
  a local array and retail reloads the four bytes each time. A plain `u8 *`
  lets b210 CSE the loads; `opt_common_subs off` restores them but also
  un-CSEs the `3, 3` argument pair that retail materialises as
  `li $a2,3 / move $a3,$a2`. `volatile u8 *arg0` keeps the reloads and
  leaves every other optimisation alone (with `opt_propagation off` to keep
  the destination pointer computed early in `$t1`).
- **A hoisted loop bound is coloured after the body's temporaries.** Retail
  `func_00275a60` keeps the loop limit in `$a0` and the body's next-node
  pointer in `$a1`; every named `limit = count - 1` local is coloured before
  the body and lands in `$a1` (nd 8-9). Writing the bound as the fresh
  expression `i < count - 1` under measured `opt_loop_invariants on` makes
  the compiler hoist it itself, after the body's temporaries have taken
  `$a1`..`$a3`, so the bound gets `$a0`. Without the pragma the fresh bound
  is re-evaluated per iteration (nd 19). Same rule as the second `+=` in
  `func_00455ea0`: what decides `$v0`/`$v1`/`$aN` is the ORDER in which
  values are first allocated, and splitting or hoisting changes that order.
- **`opt_loop_invariants on` is the lever, not the floor, when retail hoists
  table bases and constants ahead of a loop.** `func_00161bb0` (nd 45 -> 0)
  and `func_0045b430` (nd 8 -> 0) both needed it: the file default leaves the
  bases rematerialised per iteration. An `s16` loop counter is what produces
  retail's `dsll32`/`dsra32` sign-extension pairs. The same pragma closed
  `func_002a1fa0` by hoisting its case-zero store constant into the preheader,
  before retail's loop-entry branch.
  `func_0012ff60` also proves that `opt_common_subs off` may cover only the
  first loop and switch, then return `on` before an independently measured
  `opt_loop_invariants on` table loop inside the same function.
- **The signed align-up idiom is `/ 64 * 64`, not hand-written shifts.**
  Retail `addiu $v1,$v0,0x3f / sra $v0,$v1,6 / bgez $v1 / addiu +0x3f / sra`
  is `(size + 0x3F) / 64 * 64` on a signed operand; an explicit negative
  branch with `>> 6` was the archived "register-class" residual in both
  `func_00455ea0` (nd 7) and `func_0047e450` (nd 5).
- **A 12-byte global origin is a `Vec3` struct assignment** (`ld` + `lwc1`
  with separate `lui` pairs, `sd` + `swc1`): `func_00170f60` spelled it as an
  `s64`/`f32` pair through two globals and stalled at nd 8. If the global base
  itself must carry 8-byte alignment, declare it as
  `union { Vec3 value; s64 align; }` and assign its `.value`; three separate
  locals in declaration order produced retail's `0xc0`, `0xb0`, `0xa0`
  stack slots and exact copy sequence in `func_004accc0`.
- **`pcpyld $v0,$zero,$v0` is reachable from C.** `func_003a2950`'s
  `*(u64 *)p &= (u64)-0x10000` emits `lui $v0,0xffff / pcpyld $v0,$zero,$v0`
  exactly; it is how b210 materialises a 64-bit constant whose low word is
  a `lui` immediate. Do not file every MMI opcode as a floor.

- **Converge scan matches at a label immediately before the return.** For a
  byte scanner with several fixed tags, `goto found` from every successful
  compare and one `return count` at `found:` can make the final byte compare
  branch directly to the epilogue instead of materializing a shared boolean.
  In `code1_002b.c` `func_002b3520`, measured
  `opt_loop_invariants on` additionally hoisted all tag bytes into the
  preheader; `uc > 0x80` produced the retail SJIS lead-byte `slti $at` form.

## Loops

- **Bottom-test loop idiom.** A natural `while (cond) { ... }` reproduces
  retail's bottom-test layout (jump to the condition, body, condition at the
  bottom). Prefer it over `while (1) { if (!cond) break; }`.
- **Hoist a loop-invariant mask into an explicit local.** mwcc does *not* LICM
  an `andi`/cast out of a loop at `-O2`. Write `int key = param & 0xffff;`
  (or the cast) *before* the loop and compare against `key`; that reproduces
  retail's single hoisted `andi`. `#pragma optimization_level 3` enables LICM
  but also reschedules the prologue — usually worse, and banned without a
  waiver (see `docs/STYLE.md`).
- **Integer-arithmetic copy loops** (`*(u16*)(p + i*2 + 2)` with `p` as `int`)
  beat the `arr[i+1]` commutative-`addu` form.
- **Raw byte-offset addressing controls `addu` operand order.**
  `*(T*)((int)base + i*4 + off)` computes `base + index` (left-assoc),
  matching retail's `addu base,index`, where the `arr[i+off]` form emits
  `index + base`.
- **...and the mirror image: name the offset in a local to get
  `addu index,base`.** When retail has `addu $v1,$v0,$a0` (index first) but
  mwcc emits `addu $v1,$a0,$v0`, writing `base + i * n` is the problem: mwcc
  canonicalizes the pointer operand to the left. Compute the scaled offset
  into its own `s32` first and add the base to *it*, casting so the addition
  is integer rather than pointer arithmetic:

  ```c
  s32 off = index * 12;
  u8 *p = (u8 *)(off + (s32)base);
  ```

  Verified on `cmpEquip.c` func_001344b0 and `code1_0047.c` func_0047adf0,
  both nd 1 -> 0. The plain `(s16 *)base + index` subscript form does *not*
  do it. This is the one commutative-`addu` case that is source-reachable;
  when both operands are already live in fixed registers it stays a floor.

## Register allocation and caching

- **Cache after the first assert / cache the base pointer.** Functions that
  reuse a global load it once into a saved register. Mirror with an assert on
  the global first, then `work = g; ...use work...`. Setters that reload the
  global for each store also need the cached local. Getters/setters that touch
  the base more than once almost always need this even when Ghidra prints the
  global at each access.
- **Cache a global pointer into a local for indexed RMW stores.** A `static
  T* g;` accessed as `g[i] = g[i] + 1` (indexed read-modify-write) makes mwcc
  precompute the element address (`addiu v1,base,off; sw v0,(v1)`); retail
  keeps the base and uses `sw v0,off(base)`. Assign `T* p = g;` after the
  assert and use `p[0]`/`p[i]` throughout — mwcc then addresses every access
  as base+offset. Writing `g[i]` directly (even with a temp for the value)
  keeps the precomputed-address form.
- **Cache the *cleared* value for a read-modify-test.** When retail clears one
  bit and tests another that the clear does not touch, it reuses the cleared
  register: `uVar1 = *g & ~1; *g = uVar1; if (uVar1 & 2) ...` reproduces
  `andi v1,v1,2`.
- **Use a fresh temp for a final one-shot result.** If a handle lives in a
  callee-saved register across several calls, reassigning that same variable
  for the last call forces a `move s,v0`; assign the last result to a
  *different* short-lived local so it stays in `$v0`.
- **Split one value into two named locals to flip callee-saved colouring.**
  The mirror of the entry above, and it closed two functions in one session,
  so reach for it whenever the *only* residual is a saved-register swap. When
  a value is produced and then used under a second role, giving each role its
  own local changes which physical register the allocator assigns:
  - `code1_0020 func_0020e250` had **19** differing words, every one of them
    `$s0`/`$s1` swapped against retail (the list and the freshly allocated
    node). Writing `allocated = jtbl_008873E8[0](...); new_node = allocated;`
    instead of assigning the call result straight into `new_node` flipped the
    colouring to retail's and took it to MATCH. Nothing else changed.
  - `code1_004b func_004b53c0` needed the same split for a different reason —
    separating `work` from `result` and assigning `result = work` at the tail
    of both arms — see "Shared-tail joins" above.

  The two cases together give the rule: **an intermediate name is a register
  allocation control, not cosmetic.** If retail holds a value in a different
  `$s` register than you do, try both directions — collapse two locals into
  one, or split one into two — before concluding it is a floor.
- **A `volatile` lvalue can delay an address calculation across a call.** When
  retail calls a size helper before materializing the destination address, but
  mwcc hoists the destination arithmetic, cast the final lvalue — not the
  stored value — to `volatile`. This keeps the observable store while
  preventing the compiler from scheduling its address calculation before the
  call. `volatile` is banned by `docs/STYLE.md` unless the function carries a
  `measured` waiver.
- **THE saved-register assignment rule — measured, deterministic, no
  exceptions in 20 probes.** This replaces the earlier "declaration order
  tends to" hint and the "param vs local fight is a floor" claim, both of
  which were symptoms of not knowing the rule. b210 assigns callee-saved GPRs
  like this:

  1. Build one ordered list: **parameters in parameter order, then locals in
     declaration order.**
  2. Drop every value that does not survive a call — those never get an `$s`
     register at all.
  3. Assign from the **highest** `$s` register downward: first in the list
     gets `$s3` (or whatever the top is), last gets `$s0`.

  ```c
  s32 k1(s32 a, s32 b, s32 *p) { s32 x, y; x = p[0]; y = p[1]; call(); ... }
  /*  a -> s3,  b -> s2,  x -> s1,  y -> s0                                */
  s32 k2(s32 a, s32 b, s32 *p) { s32 y, x; x = p[0]; y = p[1]; call(); ... }
  /*  a -> s3,  b -> s2,  y -> s1,  x -> s0     -- only the declaration moved */
  ```

  Things that were measured and do **NOT** affect it: first-use order,
  last-use order, how many calls a value survives, whether it is an `int` or a
  pointer, whether it is declared in an inner block, and whether it comes from
  a load or a call result (a call result is just a local, ranked by where it
  is declared). A local assigned from a parameter (`ca = a;`) is coalesced
  into the parameter's slot and cannot be ranked as a local. A value that dies
  before the first call takes no slot, and a later value can then reuse the
  register it would have had.

  **How to use it.** Read retail's prologue and list which value sits in each
  `$s` register. Then order your declarations so that the value in the
  highest register is declared first, and so on down. That is the whole
  procedure; it is no longer trial and error.

  **What it says about the old "param vs local fight".** Parameters always
  precede locals in the list, so a parameter can never sit *below* a local.
  If retail shows a local in `$s1` and a parameter in `$s0`, retail's source
  did not have that shape: either the "parameter" is dead before the call and
  what you see in `$s0` is something else, or the "local" is really a
  parameter and the signature is wrong, or the parameter is re-read from
  memory after the call rather than preserved. That is a diagnosis, not a
  floor.

  Two entries above still apply within the rule: splitting a value into two
  named locals or collapsing two into one changes *which names are in the
  list*, which is why it moved colouring; and the saved-FPR entry below is the
  same rule for `$f20`–`$f23` (verified: `g1`/`g2`/`g3` probes rank FPRs
  identically, params first then declaration order, highest first).

  **The second clause, and why `opt_propagation off` works.** Under default
  propagation, any local derived from a parameter — `x = a;`, `x = (u16)a;`,
  `x = a & 0xffff;`, even a `u16` parameter itself — is coalesced into the
  parameter's slot: the compiler keeps the parameter in the saved register and
  applies the operation at each use. That is why a local can never outrank a
  parameter. **Under `#pragma opt_propagation off`, the operation is performed
  at the assignment and the result is a genuine local, ranked by its
  declaration position.** Measured:

  ```c
  #pragma opt_propagation off
  s32 p3(s32 a, s32 *p) { s32 m1, m2, m3; s32 i; s32 x;
      m1 = p[0]; m2 = p[1]; m3 = p[2]; i = 1; x = a & 0xffff; call(); ... }
  /*  m1->s4  m2->s3  m3->s2  i->s1 (li s1,1)  x->s0 (andi s0,a0,0xffff)  */
  ```

  That prologue — a masked parameter in the LOWEST saved register with locals
  above it, and a counter initialised with `li` — is exactly the shape of
  `func_002483c0` (nd 7, retail `andi $s2,$a0,0xffff` under `$s3`–`$s6`),
  which was archived as a colouring floor after declaration-order swaps
  "didn't work". They cannot work under default propagation, because the
  masked value is not in the list at all. The recipe for that whole class:
  measured `opt_propagation off` around the function **and** declare the
  parameter-derived local at the position retail's register implies.
  `func_001999f0` is the corresponding narrow-use case: a direct `s64`
  parameter plus propagation off keeps the entry `arg1 & 0xffff` mask
  distinct from later per-use `(u16)arg1` conversions.

  So the pragma is not a blunt instrument here. It changes *which names are
  in the list*, and once you know the list you can place every value.

  **Validated on `func_002483c0` — and it took a third part.** With
  `opt_propagation off` and the declarations ordered to retail's list, mwcc
  produced the intended `$s6`..`$s2` assignment exactly — but also hoisted the
  loop's `0xffff` into a new `$s7` (`ori $s7,0xffff` / `and $v1,$s5,$s7`),
  because under propagation off an explicit `& 0xffff` is a real constant
  that CSE keeps in a register, whereas retail's in-loop masks are `andi`
  immediates. The fix: keep the ENTRY mask as an explicit AND (it is meant
  to materialise, into `$s2`), and replace every OTHER `& 0xffff` with a
  **per-use `u16` conversion temporary** — `u16 call_idx = (u16)var_20;`
  immediately before each masked use. A narrowing has no constant operand to
  hoist, so it stays an `andi` immediate. `$s7` vanished, the frame returned
  to 0x80, and the function closed at 544/544. The recipe for this class is
  therefore three parts, all required:
  1. measured `opt_propagation off` under `push`/`pop`;
  2. declaration order matching retail's `$s` list, highest first;
  3. explicit AND only where retail materialises the mask; `u16` conversions
     everywhere else.

  **Refinement — a local that first becomes live after an intermediate call
  cannot outrank one that is already assigned.** Every probe behind the rule
  had all locals live from before the first call. `func_00106f40` showed the
  boundary: retail has `$s1 = arg0 & 0xffff` and `$s0 = call-result`, with
  `j` initialised only after that call. Declaring `j, mask, result` and
  writing the mask after the call still gave `$s1 = result, $s0 = mask` —
  because at the call site where `result` first needs a register, `mask` is
  not yet live, so `result` takes the higher slot. Initialising `j` before
  the call restored retail's mapping but emitted the `j = 0` at the wrong
  offset. So the list is evaluated per call site over the values live there;
  to place a later value above an earlier one it must already be live at the
  call where the earlier one is assigned. Measured in isolation, declaration
  order still wins whenever both are live at the same first call
  (`q1`/`q2`), so the base rule stands; this is the exception at the edge.

  **Pragma granularity — measured.** `#pragma opt_propagation off` placed
  INSIDE a function body, even in a tight `push`/`pop` bracket around four
  statements, has no effect: the state in force at the function's opening
  brace governs the entire body (`func_0017ea10`, nd 6 unchanged with the
  bracket inside; the same pragma before the function changed the copy
  sequence). So the pair cannot be applied to one expression while leaving
  the rest at default — when it fixes the target words but drifts the frame
  or other code (`func_0017ea10` went to nd 121 whole-function), the drift
  must be closed by the rest of the recipe (declaration order, `u16`
  conversions in place of explicit masks), not by narrowing the bracket.
- **THE caller-saved temporary rule — measured.** After the callee-saved
  rules were applied to the eight best remaining near-misses, six of the
  eight turned out to be register choice among `$v0`/`$v1`/`$a1`–`$a3` — the
  one axis nothing measured. Fourteen probes give the shape:

  1. **Pure computations are sunk to their point of use** under default
     propagation. `s32 v = k * 7; p[0] = p[1] + 1; p[2] = p[3] + 1; return v;`
     emits the two stores first and computes `v` last, so `v` never occupies
     a register across the stores. **`opt_propagation off` stops the sinking**
     and the computation is emitted where written — the same mechanism as
     every other use of that pragma this session.
  2. **The pool fills lowest-free in the order `$v1`, `$v0`, `$a1`, `$a2`,
     `$a3`, `$t0`…** with `$a0`–`$aN` skipped while they still hold live
     parameters. Loads go to `$v1` first; a second simultaneous value to
     `$v0`; a third to `$a1`. `(a + b) * (c + d)` over four loads emits
     `lw v1 / lw v0 / addu a1,v1,v0 / lw v1 / lw v0 / addu v0 / mult v0,a1,v0`.
  3. A binary operation's result lands in its **first operand's** register
     (`mult v1,v1,v0`; `addu v1,v1,v0`).
  4. Commutative expressions are canonicalised before allocation: `a*b + c`
     and `c + a*b` produce identical code, so written order does not choose
     the register there (the documented commutative floor).

  So two temporaries swapped against retail (`sb $a1` / `sb $v0` versus the
  reverse; `$v0`/`$v1` in an align-up; a loop's `$a0`/`$v1`) come from a
  different **number or order of simultaneously live values** at that point,
  not from naming. The levers are the ones that change liveness: sink or
  hoist a computation (write it at its use, or hold it under
  `opt_propagation off`), and split or merge the values live across the
  window. Under propagation off, `u6p` shows the promotion directly: the
  first held value takes `$a1`, the second `$v1`, and the store traffic runs
  in `$v0`. Genuine floors remain where the residual is two *independent*
  adjacent instructions (no liveness difference to change), and the
  float-to-byte conversion tail.
- **Saved-FPR count tells you whether retail cached a float across a call.**
  `f20`–`f23` are only allocated when a float value must survive a call. If
  retail's prologue saves none and yours saves two, the frame-size gap is
  entirely that, and no amount of declaration reordering will close it — the
  difference is dataflow, not spelling. Retail's source held no float in a
  named local across the call: it either passed the expression straight into
  the call, or re-read the value from its struct field / global afterwards.
  Deleting the local and repeating the memory expression, or recomputing a
  product on both sides of the call, looks redundant in source and is exactly
  what produces the no-save frame. Measured on `func_0047f4d0`, where every
  scalar variant retained `f20`–`f23` (frame 0x40/0x50) against retail's
  smaller frame. Count the saved FPRs before probing anything else.
- **THE saved-register COUNT rule — measured.** "Retail saves fewer registers
  than any spelling I can write" is cited by 59 archives. Fourteen probes
  reduce it to one statement: **the count is exactly the number of named C
  values that are live across a call, and a parameter pointer is such a
  value.** What does *not* reduce it, measured:
  - re-reading a field through a parameter pointer after the call
    (`sink(s->b); call(); sink(s->b);`) — the *pointer* survives instead of
    the value, still one register;
  - recomputing an arithmetic result on both sides (`sink(s->b*3); call();
    sink(s->b*3);`) — same, the pointer survives;
  - copying a global pointer into a local first (`S *s = g_p;`) — now the
    local survives.

  What **does** reduce it to zero: accessing through a **global** on both
  sides, so that after the call the value is re-derived from `$gp` and
  nothing needs preserving:

  ```c
  s32 m1(void) { sink(g_s.b);  call(); sink(g_s.b);  }   /* frame 16, no $s */
  s32 m2(void) { sink(g_p->b); call(); sink(g_p->b); }   /* frame 16, no $s */
  s32 m4(S *s) { g_p = s; sink(g_p->b); call(); sink(g_p->b); }  /* no $s */
  s32 m5(S *s) { call(); sink(s->b); sink(s->c); }         /* one $s: the pointer */
  s32 m6(S *s) { s32 b=s->b, c=s->c; call(); sink(b); sink(c); } /* two $s */
  ```

  So when retail's frame is smaller than yours by N saved registers, retail's
  source has N fewer *names* live across that call — and the usual way a
  game function achieves that is by reaching data through a global (a
  singleton pointer, a state struct) rather than a parameter. `m4` is the
  telling case: storing the parameter into a global and reading back through
  the global drops the save entirely. Look for that assignment near the top
  of retail: a `sw $a0, -0x…($gp)` before the first call is the signature.
  Also the mirror of the entry above: `m6` versus `m5` is two names versus
  one, and picking the wrong one costs a register.
- **Float-to-byte conversion tail colouring — SOLVED, six for six.** This
  used to be two entries ("open floor, SIX members" and "`shdPersona.c`
  output-GPR family, FOUR members"): every archive had the conversion result
  landing in `$v1` (or `$v0`) where retail uses `$a0` (or `$v1`), and each
  concluded "allocator-internal next-use pressure". The cause was in the
  archives, not the allocator: every one of them had **hand-expanded** the
  float→unsigned conversion into
  `if (2147483648.0f > acc) n = (s32)acc & 0xFF; else n = ((s32)(acc - 2147483648.0f) | 0x80000000) & 0xFF;`
  (or the goto/ternary equivalents). That makes `n` a real integer local
  with its own live range, and the allocator colours it differently from
  the compiler's own conversion temporary. Write the cast:

  ```c
  *(u8 *)(p + off) = (u8)acc;      /* c.le.s 2^31 / cvt.w.s / mfc1 $a0 / andi / or 0x80000000 / sb — retail's exact tail */
  ```

  mwcc emits the full `c.le.s`/`bc1t`/`sub.s`/`or` sequence itself, and its
  internal temporary takes the register retail has. (`cvt.w.s` in Ghidra is
  the same word binutils prints as `trunc.w.s`, 0x46000824.) Two
  corollaries measured on the way: a **constant** converted at runtime
  (`lui 0x437f; mtc1; c.le.s ...` for 255.0f) is a named `f32` local
  holding the constant — `f32 b = 255.0f; x = (u8)b;` — no union pun
  needed; and the `opt_rebuildconditionals off` several archives carried
  existed only to shape the hand-written branches, so it goes away too.
  Closed: `func_0011ae90`, `func_0011c780`, `func_0011c930`,
  `func_0011ac70` (shdPersona.c; c780/c930 keep the measured
  `opt_propagation off` for the `lh`/`lwc1` prologue order) and
  `func_00166e30`, `func_00167120` (k_fldUnit.c). The archives are left in
  place as the record of the wrong turn.
- **A measured pragma keeps applying to every function below it.** `#pragma X
  off` is file-position scoped, not function scoped, so a lane that opens one
  for its target and never closes it silently changes the codegen of every
  later function in the translation unit. This has bitten once already: an
  `opt_propagation off` was left open across ~14 downstream functions.
  `tools/pragma_scope_audit.py` reports it properly — it simulates
  `#pragma push`/`pop`, so unlike raw `on`/`off` counting it does not
  false-positive on push-scoped flips. It currently lists **125 files ending
  off baseline, 109 of them with functions sitting under an open `off`**.
  Those are NOT presently wrong: every one of those functions verifies, and a
  spot check on `btlBoss.c` closed the trailing `opt_loop_invariants off`
  before its five downstream functions with all 15 still MATCHing, so the
  inherited state is incidental there rather than load-bearing. Do not
  mass-balance them — where the state *is* load-bearing, closing it would
  break a match for no gain.
  The hazard is for new work: **if you add or reconstruct a function, run the
  audit and check whether your target sits under an open flip.** If it does,
  you are not compiling at the `-O2` baseline you think you are, and a pragma
  you then add may be redundant, or its removal may appear to do nothing.
- **THE load-ordering rule for a global versus a field — measured.** The
  "float-load scheduling floor" cited in 29 archives is one rule, and it has
  a source-level fix. Thirty probes against b210:

  | operands | order emitted |
  |---|---|
  | two register-pointer loads, any offsets (`a[7] - b[9]`) | **source order** |
  | two GP globals (`g1 - g2`) | source order |
  | a global vs a field at **offset 0** (`g - p[0]`) | source order |
  | a global vs a field at **any non-zero offset** (`g - p[1]`, `g - p[101]`) | **field first, always** |

  The last row holds for GP-relative and absolute (`lui`/`lwc1`) globals,
  for `+`, `-`, `*`, and every comparison, in both written orders, for
  `int` and `float`, and through a struct member. Eleven comparison
  spellings and `!(a >= b)` all produced the identical field-first sequence.
  Rebasing the pointer (`q = p + 101; g - q[0]`) does not help — mwcc folds
  it back into a `404(a0)` access — and naming the global into a local
  (`f32 g = g_flt;`) is propagated straight back into the expression. So
  under default optimisation the global is deferred behind the field and no
  spelling reaches retail's global-first order.

  **The fix is the same two-part lever as the register rule:** measured
  `opt_propagation off` **and** the global read into a named local.

  ```c
  #pragma opt_propagation off
  f32 p1(f32 *p) { return g_flt - p[101]; }            /* still field first  */
  f32 p2(f32 *p) { f32 g = g_flt; return g - p[101]; } /* lwc1 0(gp) FIRST   */
  ```

  With propagation off, the assignment is honoured as a real load at its
  written position instead of being folded into the use. Either half alone
  does nothing: the pragma without the local leaves the fold in place, and
  the local without the pragma is propagated away. This is precisely
  `func_0034ac00`'s remaining nd 2 (`fGpffff8504` loaded before
  `entry+0x194`, retail the reverse), where the lane reported
  "opt_propagation off no effect" — because it applied the pragma without
  the named local. Also the shape of the `c.ole.s`/`bc1t` scheduling wall
  recorded on `y_draw`. Retry both with the pair.

  **Validated on `func_0034ac00` (closed, nd 2 → 0) and `func_0019df20`
  (closed, nd 0 with the banned `volatile` removed) — and the validation
  generalised the rule.** In `func_0034ac00` the *default* C emitted the GP
  load first and retail wanted the field first: the opposite direction from
  the isolated probe. The pair still closed it, because what it actually
  does is **anchor both loads to their written positions** — `f32 field =
  entry->x; f32 g = fGpffff8504;` under `opt_propagation off` emits those two
  loads in that order, whatever the default schedule would have been. So
  the recipe is not "force the global first"; it is "write the loads as
  named locals in retail's order, under the pragma". One caution measured
  there: naming only the global hoisted its load above an earlier flag test
  and shifted five words — name *both* operands, immediately before the
  expression that consumes them, not earlier.

  `func_0019df20` shows the other use: it had reached a true nd 0 only by
  `*(volatile f32 *)&angle` read-backs forcing two values to spill before a
  call. `volatile` is banned; the pragma plus a named read-back local is the
  legal way to force that spill, and it closed at 520/528 with the casts
  removed.

  Note the distinction from the entry below: that one is two *stack* reloads
  swapping, where neither operand is a global, and the pragma pair was
  measured not to help. This entry is specifically global-versus-field.
- **Adjacent independent loads can swap and no pragma fixes it.**
  `func_001cff00` (code1_001c.c) sits at exactly TWO differing words, object
  and window both 704B, offsets 0x78/0x7c:

  ```
  retail     ld    $v0,0xa0($sp)   then  lwc1  $f0,0xa8($sp)
  candidate  lwc1  $f0,0xa8($sp)   then  ld    $v0,0xa0($sp)
  ```

  No relocation, no HI16/LO16 pair, no literal difference, identical sizes —
  only the order of two independent stack reloads. **The source already names
  the 64-bit value first and mwcc reorders anyway**, so it is not source
  ordering.

  It is tempting to reach for `#pragma schedule off`, and that is wrong:
  measured under `push`/`pop`, tightly scoped, it left the two words
  **unchanged**, as did `no_branch_likely on` and `opt_rebuildconditionals
  off`. `opt_propagation off` shifted the frame and tail and was worse.
  Hoisting the pair into a local ahead of the consuming expression moved the
  load to 0x48, before all the target's math, and produced a large shifted
  residual. So this reordering happens somewhere the `schedule` knob does not
  reach; do not spend budget on that pragma for a pure load-order residual.
  Archive: `docs/probe_archive/PnC_001cff00_body.c`.


## Read-modify-write and flags

- **Chained flag OR → separate statements.** `*p |= a; *p |= b;` (two RMW
  statements on the pointer) reproduces retail's single-load running-value
  chain (`lw; ori a; sw; ori b; sw`). A cached `v = *p; *p = v|a; *p = v|b;`
  gets constant-folded to `ori v0,a` / `ori v0,a|b`. Match whichever the
  disassembly shows.

## Argument materialisation — measured rule

Cited by 71 archives as a residual and worked by trial and error ("float
params ahead of `u8`", "delayed first parameter read"). Twenty-two probes
against b210 reduce it to four clauses.

**1. Arguments materialise strictly left to right in parameter order, with no
exceptions.** Loads from a pointer, GP globals, `lui`/`li` constants, values
preserved in saved registers, and call results all fill `$a0`, `$a1`, `$a2`…
in the order the parameters are declared. A GP global in slot 1 is loaded
between slots 0 and 2 — the global-deferral rule that governs *expressions*
does not apply to argument lists. A call inside an argument is evaluated
first, its result parked in a saved register, and then the remaining
arguments are loaded left to right.

```c
f3(p[0], g_int, p[2]);   /* lw a0,0(a0)  lw a1,0(gp)  lw a2,8(v0)  jal */
f3(g_int, p[1], p[2]);   /* lw a0,0(gp)  lw a1,4(v0)  lw a2,8(v0)  jal */
f2(p[3], 0x40000);       /* lw a0,12(a0) lui a1,0x4               jal */
```

So **if your argument loads come out in the wrong order, the prototype's
parameter order is wrong** — reorder the declaration, not the call site.
That is the whole content of the "float parameters ahead of `u8`" lever.
Where the callee is only declared locally, the order is yours to choose;
where it is a real definition, check every caller by name after changing it.
Do not omit later parameters merely because the call site shows no moves.
In `func_004accc0`, the converted frame index and frame count were already
live in `$a1`/`$a2`; declaring `func_0048aff0` with only its first parameter
let the allocator recolour both and left nd 6. Its correct three-parameter
signature preserved those registers and matched.

**2. A constant that is both stored and passed is materialised once, early,
into the argument register.** `s32 k = 0x40000; *d = k; f2(g_int, k);` emits
`lui a1,0x4` *before* `lw a0,0(gp)`, because the shared constant is built
directly in `$a1` and the store reads it from there. If retail shows the
argument load first and the constant afterwards in a temp (`lw a3,…(gp)`
then `lui v0,4` — `func_00398350`'s nd 6 residual), retail's constant is
**not** shared with the argument: it is a separate literal at the store, and
the argument is a different value or the same value re-derived. Write the
store with its own literal rather than through a local that also feeds the
call.

Statement order is otherwise honoured exactly: a store written before the
call is emitted before the argument loads; written after, it comes after.

**3. Wide calls: stack-passed arguments (slot 9 onward) are stored FIRST,
then registers `$a0`–`$a3`, `$t0`–`$t3` fill left to right.** A call result
in any slot is evaluated before every load and parked in a saved register;
the loads then run left to right and the parked value is `move`d into its
slot at its turn.

**3a. A narrowing lvalue in an argument slot is a conversion and is hoisted
ahead of constants unless the callee parameter has the same narrow type.**
`f(0xFF, ((u8 *)&arg1)[0], g, b)` against `f(s32, s32, s32, s32)` emits
`lbu $a1` BEFORE `addiu $a0,$zero,0xff` - the byte load is a u8->s32
conversion and goes with the computed operands. Declare the slot `u8`
(`f(s32, u8, s32, s32)`) and the load is a plain load, materialised in slot
order after the constant. Measured on `func_002cacd0` (y_fclShopDraw.c,
nd 4 -> 0); `func_002e0100`'s archived "constant-first arg order" floor is
the same thing. Making the OTHER slots `u8` costs `andi` masks on s32
values, so narrow only the slot retail loads narrow.

**3b. Colour bytes from an integer argument: pass it as a 4-byte struct by
value, keep the bytes in `s32` locals.** Retail `sw $a1,0xCC($sp)` then
`lbu $s1,0xCF / lbu $s0,0xCE / lbu $s6,0xCD` and a per-call `lbu $a1,0xCC`
is an `RGBA arg1` parameter (struct { u8 r,g,b,a; }) with `a = arg1.a` etc.
into `s32` locals; `u8` locals for the bytes go through `sq`/`lq` stack
temporaries (+16 words). The per-call byte is `((u8 *)&arg1)[0]`, not
`arg1.r` - the member form is CSE'd into a tenth saved register and spills
something else.

**4. An argument that shares an operand with another argument is computed
early, and the shared loads are hoisted out of order.** `f5(p[0], p[1],
p[2], p[0]*p[1], p[4])` emits `lw a1,4(a0)` / `lw a0,0(a0)` / `mult a3` /
`lw a2` / `lw t0` — slot 3's product is built first from `a0`/`a1` loaded
in reverse, and only then do slots 2 and 4 load. This is the mechanism
behind `func_0033cc40`'s archived "cannot be made byte-exact" claim: retail
fills its 14-argument call as `[3, 8, f12-f14, 1, 2, 4, 5, 6, 7, f15-f17]`,
where 8 is stack-passed (clause 3) and 3 is a derived value sharing operands
with 1 and 2 (clause 4). That order is reachable; the archived candidate had
slot 3 as a plain load. Look at which argument is an expression over the
others.

### A branch-only block at a loop entry is a coalesced copy — measured

Retail sometimes has an outer back-edge land on a block that is only
`b <inner test>`. mwcc threads jump-to-jump for every plain `while`/`for`/
`do`/`for(;;)-break` spelling of a nested loop (six measured, none produce
it). It appears when the inner loop iterates over a **copy** of the outer
variable that the allocator coalesces away:

```c
while ((s0 = *(u8 **)(s2 + 0x4C)) != 0) {
    p = s0;                              /* coalesced: leaves a jump-only block */
    while (*(s32 *)(p + 0x68)) f1(p);
    ...
}
```

The empty assignment keeps its own basic block; the branch into it is not
threaded. Seen in `func_0028ad90` (evtMain.c, archived at nd2: the block is
reproduced, the remaining pair is the inner-test load landing in `$a1`
rather than `$v0`, which no copy/type/declaration variant moved in
isolation — whole-function pressure, still open).

### Parameter parking moves — where they land is the temporary rule

`func_00356170` (nd8, "independent prologue-order floor"): retail spills
`$a0`/`$a1` to the stack and only then parks `$a2` into `$t1`; mwcc parks
`$t1` at entry. A parked caller-saved temp is just a value becoming live,
so name the copy where retail makes it live and stop the copy from being
folded back into the parameter:

```c
#pragma opt_propagation off
saved0[0] = arg0;      /* sd $a0 */
saved1[0] = arg1;      /* sw $a1 */
tmp2 = arg2;           /* move $t1,$a2 -- here, not at entry */
var8 = arg3;           /* move $t0,$a3 */
```

Closed 96/96. It does NOT transfer to a park into a callee-saved register
(`func_00117310`, `move $s0,$t0` before the `$a2`/`$a3` parks): there mwcc
orders the `$sN` parks with `$t0` first regardless of source, and only a
real conversion instruction moves it — see that archive.

## Globals and addressing

- **Absolute globals outside the gp window** (read as `lui;lw` with HI16/LO16
  relocs) → declare `extern T DAT_addr[];` and use `DAT_addr[0]`. A `static`
  would emit GPREL16 and mismatch.
- **Absolute function-pointer slots use the same array idiom.** For a retail
  `lui; lw; jalr` through an address outside the gp window, declare
  `extern void* DAT_addr[];` and call `((Ret (*)(Args...))DAT_addr[0])(...)`.
  Declaring `extern Ret (*DAT_addr)(Args...)` can place the slot in small data
  and emit `lw ..., GPREL16(gp); jalr`, one instruction shorter than retail.
- **A heterogeneous callback table can be declared as `void *` and cast at
  each call.** In `func_00467880`, a single concrete function-pointer type
  distorted calls whose callbacks have different signatures. A `void *`
  table plus an explicit function-pointer cast at each use retained the exact
  argument materialisation without volatile staging.
- **gp base = `0x007690f0`** (recorded in `config/target.json` as `_gp`, also
  in `config/symbols_recovered.txt`). This maps gp-relative offsets (the
  `saved_reg_gp - 0xXXXX` idiom in m2c output) to the absolute addresses they
  alias: absolute = `0x007690f0 - offset`. Use it to avoid declaring a
  duplicate global for the same variable.
- **`#pragma alias` does nothing — b210 does not recognize it.** The compiler
  ignores an unknown `#pragma` silently: no warning, no error, no effect. 109
  `#pragma alias X_abs X` directives across 31 files were verified inert (every
  spelling tried, including the exact `extern code X_abs[];` + pragma form the
  tree used, is flagged under `#pragma warn_illpragma on`) and removed with the
  first-party counts, every object size, and both link sha1s unchanged. What
  actually makes an `_abs` alias work is two things that have nothing to do with
  the pragma: the symbol is registered at the aliased address in
  `config/symbols_recovered.txt`, and the **declaration form** picks the
  addressing mode (array → absolute `lui`/`lw`, scalar or pointer → GPREL16).
  Never credit a match to `#pragma alias`.
- **Validate any new pragma with `tools/pragma_audit.py`.** It collects every
  distinct spelling in `src/` and `include/` (comments stripped, so floor notes
  quoting a pragma at line start are not mistaken for directives) and compiles
  them in one unit under `warn_illpragma`. A typo such as `scheduling off` for
  `schedule off` otherwise compiles clean, does nothing, and still demands a
  `measured` justification from the lint. All 19 remaining spellings pass.

## Commutative-`addu` (frequent wall)

Retail's `addu` operand order for `base + index*scale` is context-dependent
and often not source-reachable. Levers to try, in order:

- The raw byte-offset form (above) flips it in some functions.
- **Named temp for the scaled index**: hoisting `idx = i * 4;` and indexing
  `*(u32*)(idx + base + off)` flips the `addu` where inline `i * 4 + base +
  off` and all its reassociations do not.
- **Pointer-typed base + array index**: `u8* base = ...; base[i * 0x14 + 9]`
  flips the `addu` where the int-arithmetic forms (temp-hoisted or not) stay in
  the wrong order. Also hoists the base load before the index math.
- **Inline pointer copy**: with `mdl = unit->mdl;` cached,
  `(m = mdl)->attachedWpns[i].flags` flips the condition's `addu` to retail's
  `index + base`, while a plain `mdl->attachedWpns[i]` emits `base + index`.
- **Comma struct-copy for load order**: `(0, p[i].unionField).member` copies
  the whole operand word before extracting the member, reproducing retail's
  `lw`-then-`lh` order where plain `.member` access reorders the loads.
- **Scalar-copy macro for float aggregate load order.** A struct assignment is
  not the only aggregate shape, and it is often the wrong one. Borrowed from
  the Silent Hill decomp and measured against b210:

  ```c
  #define COPY_VEC4(dst, src) \
  do { \
      float w, z, y, x; \
      x = (src).x; y = (src).y; z = (src).z; w = (src).w; \
      (dst).x = x; (dst).y = y; (dst).z = z; (dst).w = w; \
  } while (0)
  ```

  Four distinct behaviours are available for the same copy:

  | form | codegen |
  |---|---|
  | `*d = *s` through pointers | batched, loads `f3,f2,f1,f0` from `0,4,8,12` in order |
  | `COPY_VEC4` through pointers | batched, loads from `4,8,12,0` — **rotated** |
  | `g_dst = g_src` on globals | **`lq`/`sq`**, a 128-bit quadword copy |
  | `COPY_VEC4` or field-by-field on globals | interleaved `lwc1`/`swc1`, no `lq` |

  So the macro does two things nothing else does: it **suppresses the `lq`/`sq`
  quadword copy** on globals, forcing scalar float traffic, and through
  pointers it **rotates the load order** by one field relative to a struct
  assignment while leaving the stores in field order. The reversed declaration
  `float w, z, y, x;` is load-bearing — it is what sets that register
  assignment; declaring them `x, y, z, w` gives a different one.

  Reach for it when retail does scalar `lwc1`/`swc1` and your aggregate copy
  emits `lq`/`sq` or a 64-bit `ld`/`sd` pair, or when the loads are batched
  correctly but rotated by one. `func_00153300` is the standing example: nd 4
  at offsets 0x2C/0x34 where retail emits `ld D_005EFE38` then
  `lwc1 D_005EFE40` and the aggregate copy adds a second `ld`/`sd`.

When no order matches after trying these, drop the function. Indexed
getters/setters are the usual victims.

### Commutative `add.s` operand order — measured

`x + c` puts the *variable* first (`add.s $fx,$fx,$f0`) whenever the sum is
assigned back to `x` — `x += c`, `x = x + c`, `x = c + x` all the same.
The constant comes first (`add.s $fd,$f0,$fx`) when the sum is assigned to
a **different** variable, even one that inherits `x`'s register because
`x` is dead: `y = x + 130.0f` (either operand order). So retail
`add.s $f21,$f0,$f21` after a saved `$f21` is a *new* name, not an update.
Closed `func_00135520` (code1_0013.c, nd2 -> 0) by assigning the sum to the
dead `temp_f20` instead of `temp_f21 += 130.0f`; introducing a third float
name instead re-coloured `$f20`/`$f21`, so reuse a dead one.

### Float MAC operands: `madd.s`/`msub.s` yes, `adda.s` no

The commutative-operand floor has been over-applied to the FPU accumulator
family. The two halves behave differently, measured directly against b210:

```c
float m_ab(float a, float b, float c) { return c + a * b; }   /* madd.s $f0,$f12,$f13 */
float m_ba(float a, float b, float c) { return c + b * a; }   /* madd.s $f0,$f13,$f12 */
```

**`madd.s`/`msub.s` operand order follows the source multiply operand order** —
swap `a * b` to `b * a` and the two register fields swap. It is source-reachable
and is NOT a floor.

**`adda.s` operand order is invariant.** Six spellings were tried — operand swap
on the add, `(z + 0.0f)`, `(0.0f + z)`, multiply-first, and both subtract forms —
and it stayed `adda.s $f0,$f14` in every one. That half is a genuine floor.

So when a MAC row differs, read *which* instruction it is before deciding.

**When a source swap does not move a differing `madd.s`, the slot is decided by
which operand is freshly computed at the multiply site, not by written order.**
mwcc puts the value produced right there into `fs`. A source swap changes
nothing because the subexpression is still the fresh one either way. Confirmed
on `func_0035bad0`, which had been declared a commutative floor twice and sat
at nd 2 words for exactly this reason:

```
candidate 0x4602001c = madd.s fd=f0, fs=f0, ft=f2   /* f0 = the subtraction */
retail    0x4600101c = madd.s fd=f0, fs=f2, ft=f0
```

It closed by **inlining the helper calls directly at the multiply sites** so the
call result, not the subtraction, became the freshly-arrived operand. Naming the
call results in locals kept the wrong slot; hoisting the subtraction into a local
ahead of the call was worse (nd 76). The lever is to move *which* operand is
computed last, and inlining a call at the multiply site is the sharpest way.

If the differing `adda.s` registers hold the wrong *values* rather than sitting
in the wrong fields, that is upstream colouring — an ordinary, closable problem
— not the invariant.

## `slt $at` vs `slt $v0` — try `> K-1` for `>= K`

When the only residual is a comparison row where retail names `$at` and we name
`$v0` (`slti $at,$v0,0xB / bnez $at` against our `slti $v0,$v0,0xb / bnez $v0`),
the fix is usually the *operator*, not the register. `x >= K` makes b210
materialize the comparison into a general register; the equivalent `x > K-1`
branches through the assembler temp, which is what retail does. Same semantics,
different branch form.

Measured on `code1_0025 func_0025d7e0`: `>= 0xB` → `> 0xA` took nd 2 → MATCH.
Un-chaining the `&&` into nested `if`s and negating the inner test both stay at
nd 2, so reach for the operator first. It is **per-comparison, not a blanket
rewrite** — applying `>= K` → `> K-1` to all eight other preserved bodies that
contain such a comparison produced no match and made five worse, because the
form has to agree with retail's actual branch at that row. The mirror case is
`x <= K` → `x < K+1`.

**The complete grid, measured (b210, 24 probes).** The register is chosen by
the *spelling* and by whether the emitted branch is the skip-branch of an
`if` or the back-edge of a loop / an early `return`. `!(...)` is folded before
this choice, so `!(x >= k)` behaves as `x < k`. Same table for `slt` with a
register operand (operands swapped for `<=`/`>`) and for `sltiu`/`sltu`:

| written      | `if (...) body`        | loop back-edge, `if (...) return` |
|--------------|------------------------|-----------------------------------|
| `x < k`      | `slti $at` + `beqz`    | `slti $vN` + `bnez`               |
| `x >= k`     | `slti $vN` + `bnez`    | `slti $at` + `beqz`               |
| `x <= k-1`   | `slti $at` + `beqz`    | `slti $at` + `bnez`               |
| `x > k-1`    | `slti $at` + `bnez`    | `slti $at` + `beqz`               |

So `<=`/`>` always go through `$at`; `<`/`>=` go through `$vN` exactly when
the emitted branch is `bnez`. Three of the four register×sense combinations
are reachable by spelling alone; `$vN + beqz` is the only one never
observed. Whether `x` is live afterwards does not change the choice.

**Operand swap is a second, distinct form of the same lever, and is now the
highest-yield single trick in this campaign.** Where `>= K` → `> K-1` changes
the *operator*, this changes the *operand order* while preserving the sense:
write `a < b` as `b > a`, `x >= y` as `y <= x`. That changes which operand
reaches the `slt` first and therefore which register the result is assigned.
It is validated by the `compare_destination` experiment in the mwccps2-debugger
corpus (`~/mwccdbg/experiments/compare_destination/`), which asks exactly this
question of b210 and answers yes.

Measured closures and near-misses from the swap and its relatives:

- `cmmMisc func_002480e0` — rewriting a max test as
  `temp_3 <= (s32)*(u16 *)(var_18 + 6)` took nd 2 → MATCH with no other edit.
- `btlAICommand func_001dea90` — reversing the second-loop test to
  `if (random > total)` made that entire loop exact including `slt $at`,
  taking the function nd 9 → 7.
- `code1_0035 func_00356870` — spelling the range check inclusively as
  `>= lower && <= upper` corrected condition register allocation, nd 10 → 0
  once combined with a direct-field `> 0x168` tail.

As with the operator form, this is **per-comparison**: apply it to the single
comparison feeding the differing row, not across the function.

## Shared-tail joins: assign one result in every arm, return once

A distinct branch-shape residual, and it has a reliable recipe. Symptom: the
conditional branches are present and correct but their *targets* are wrong —
retail branches to an earlier address than the candidate, because retail has a
shared join block that the candidate lacks. Typically the candidate either
duplicates the tail inside each arm (so there is nothing to branch to) or has a
statement between the arms that blocks the merge.

The fix is not a label or a `goto`. Both were tried on `code1_004b
func_004b53c0` and left it at nd 2. What works:

1. Separate the working variable from the returned one (`work` and `result`).
2. Assign `result = work` at the **tail of every arm**.
3. Return `result` exactly once, at the end.

That took `func_004b53c0` nd 2 → MATCH, reproducing retail's `beqz` pair both
targeting the shared join at `0x4b5490`. The diagnostic that pins it down:
putting a `return` inside one arm makes the branch targets correct but adds a
`move` and a `b`. The extra `move` means retail's value is already in the
return register (so both arms must assign the *same* variable), and the extra
`b` means one arm should fall through into the tail rather than jump to it.
When you see that move+b pair appear, the shared-result shape is the answer.

Do not confuse this with the unreachable shared-tail floor recorded under
"Known compiler floors", where retail emits `bne` plus an unconditional `b` to
a shared tail and b210 merges to a single `beq` (`code1_0028 func_0028c3f0`,
`cmmCommunity`). That one is about the *number* of branches and does not yield;
this one is about their targets and does.

## b210 accepts 386 pragmas — sweep them before declaring a floor

This campaign spent a long time using **19** pragma spellings. `mwccps2.exe`
accepts **386**, and an unrecognized one is ignored *silently*, so nobody ever got
told. `tools/knob_sweep.py --list-knobs` discovers the real list: it pulls
identifiers out of the compiler binary and validates each with
`#pragma warn_illpragma on`.

The first sweep paid for itself immediately. **`#pragma no_branch_likely on`**
turned four functions documented as compiler floors into byte-exact matches:
b210 was emitting a branch-likely (`beql`) where retail used a plain `beqz`
(`code1_003b func_003bd560`, `func_003bd680`, `func_003be910` at nd 4 each, and
`code1_003d func_003d81a0` at nd 14).

**Retail does use branch-likely** — 2,216 instructions across 1,061 functions
(`beql` 937, `bnel` 1178, `blezl` 64, `bgtzl` 37) — so this is a per-function
knob, never a global flag. The cheap test for whether it applies: scan the retail
window for opcodes `0x14`–`0x17`; if there are none and our object has one, the
likely form is wrong for that function.

Knobs that look promising and did **not** move their obvious target, so you can
skip them: `cse_hard_reg_gpr off`, `opt_lifetimes off`, `reg_class_allocs off` and
`opt_scalarizeliveranges off` on the absolute-getter register floor;
`opt_strength_reduction off`, `opt_strength_reduction_strict on`,
`optimize_for_size on` and `opt_dospecialmultiplyunpromotion off` on
`code1_0039 func_003963b0`, where b210 lowers `x * 0x24` to `sll/addu/sll` and
retail emits a real `mult`; `opt_rebuildconditionals off`,
`opt_optimizecontrolflow off` and `conditional_move off` on the `beql` case that
`no_branch_likely` did fix.

A knob hit is a **proposal**, not a result. Record what the pragma fixed and
what the residual was. `tools/decomp_lint.py` treats optimization provenance
as advisory: a valid compiler setting is not itself window filling. Semantic
equivalence, scoped verification, and correct linkage remain mandatory.

### Second sweep: 60 additional knobs pulled from the b210 binary, zero closures

`tools/knob_sweep.py` referenced above no longer exists in this tree (either lost
or never ported from the P3 FES campaign); the underlying technique is simple
enough to redo directly: `strings -a mwccps2.exe | grep -E '^[a-z_]{3,40}$'`
finds identifier-shaped strings, then `tools/pragma_audit.py`'s `_compile_probe`
helper (imported directly, not via its CLI) validates each with
`#pragma warn_illpragma on` in a throwaway TU. That found **60 previously-unswept
base names** (120 spellings with `on`/`off`) beyond the 9 base names already
proven in this tree — mostly `opt_*` register/loop/scheduling internals plus
`cse_hard_reg_{gpr,fpr,special,vu0}`, `reg_class_allocs`,
`enable_vu0_registers`, `vu0_mmi_reg_binding`.

All 120 spellings were swept against **eight representative documented floors**,
one per distinct floor pattern (scheduler-residual delay-slot `addu`, 128-bit
`sq`/`lq` slot compare, COP1 `adda`/`madd`/`msub` chains, two independent
saved-register-rotation floors, FPU-accumulator, VU0/COP2 `s128`
canonicalization, register/schedule/quad-shape) — 960 total compiles. **Zero
knobs produced an exact match on any of the eight.** Do not re-run this sweep on
these floor categories; the result is confirmed exhausted for this knob set.

Findings worth keeping so nobody re-discovers them the hard way:

- **`opt_pointer_analysis on` crashes `mwccgap`** (compile exception, not a
  normal diagnostic) on every one of the eight probes. Never use it.
- **`opt_generateconditionalassignments on`** triggers an MWCC *internal
  compiler error* (`InstrSelection.c:3893`) on multiple probes. Never use it.
- **`opt_markcounterloops on`** also hit a compile error on at least one probe.
- **`opt_repositioncode on`** is the only knob that ever *improved*
  `normalized_diff` by a nontrivial amount (-12 to -34 across three of the eight
  probes) — but it also *worsened* three other probes by comparable amounts
  (+20 to +235), and never got closer than 96% of the residual on any of them.
  It is a real, inconsistent effect, not noise, but it is not source-reachable
  as a general lever: treat a positive result on one function as
  function-specific, never assume it generalizes.
- **`opt_dead_code off` / `opt_dead_assignments off`** move `normalized_diff` by
  single-digit-to-tens amounts on most probes, always in the *worse* direction
  except once. Not useful.
- **`opt_rotateloops on`** improved one saved-register-rotation probe
  substantially (-42) and worsened a different one (+93) — same
  inconsistent-per-function pattern as `opt_repositioncode`.
- **`opt_foldconstants off`** gave one small improvement (-6) on the
  register/schedule/quad-shape probe; unchanged everywhere else.
- The other ~53 of the 60 new base names (including every `cse_hard_reg_*`,
  `reg_class_allocs`, `enable_vu0_registers`, `vu0_mmi_reg_binding`,
  `opt_scalarizeliveranges`, `opt_marknonregtemps`, `opt_optimizenonregaccess`,
  `opt_decomposeaggregates`, `opt_recomposeaggregates`, `opt_scalarizebitfields`)
  had **zero measurable effect** on any of the eight probes, in either state.

## A function that cannot be matched may have the wrong WINDOW

Before treating a function as unmatchable, check that its boundary is right. Three
functions in this tree were documented as "Ghidra splits that portable C cannot
express" and were nothing of the sort: spimdisasm had mistaken a rotated loop's
condition check for a second function, so the parent's window stopped mid-loop and
**no body could ever have filled it**. With the boundary corrected all three are
ordinary nested `while` loops and match.

### The reliable detector

An entry whose **first instruction is an unconditional `b`** into **another entry
that nothing references**. Both halves matter:

```python
# a reference is a jal, a j, a data word holding the address, OR a lui/%lo pair
first = words[0]
is_b = (first >> 26) == 4 and ((first >> 21) & 0x1f) == 0 and ((first >> 16) & 0x1f) == 0
```

That found exactly three instances tree-wide (`0x00272B34`, `0x00272BD4`,
`0x0027A350`), all genuine, all now withdrawn in
`reconcile.BRANCH_LANDING_ENTRIES`. The set is **exhausted** — re-running the sweep
finds nothing.

### Detectors that look equivalent and are not

Measured, so they are not retried:

| rule | hits | false positives |
|---|---|---|
| entry with zero `jal`/`j`/data references | 2,495 | **554 already MATCH** |
| …also counting `lui`/`%lo` address forms | 1,078 | 100 already MATCH |
| …and preceded by a non-terminating instruction | 483 | 54 already MATCH |
| window containing no `jr $ra` and no tail `j` | 14 | 5 already MATCH |

Reachability alone is not evidence: plenty of real, matching functions have no
reference this analysis can see. Only the `b`-into-an-unreferenced-entry shape is
safe to act on, because it identifies the *parent* independently.

### Withdrawing safely

`BRANCH_LANDING_ENTRIES` names a `parent` for each withdrawn address and refuses if
that parent is not itself an entry. Withdrawing something genuinely called is what
broke the link once before, when an earlier revision withdrew the *parents* by
mistake and mwldps2 reported `Undefined: func_00272b00`. After any change here,
re-verify with `build/cache/c` deleted — a stale object will happily hide a
regression — and update the boundary total and marker tripwire with the reason.

## Score the m2c drafts before hand-writing anything

`src/generated/` holds an m2c draft for most un-decompiled functions. Applying them
in bulk does not work — an earlier attempt spliced 30 at once and got 242 compile
errors, because a draft freely references symbols its destination file never
declares. `tools/draft_probe.py` splices them **one at a time**, keeps only what
compiles, and ranks the survivors by `normalized_diff`, so the failure mode becomes
a filter.

Over the 150 game-file `INCLUDE_ASM` functions with a draft and a window ≤ 400 B:
80 had a draft free of `M2C_UNK`/`M2C_ERROR`, and **20 compiled cleanly**. None
matched outright, but the ranking is the useful part:

| function | nd | obj/window | file |
|---|---|---|---|
| `func_00288020` | 26 | 324/336 | `evtMain.c` |
| `func_00107bd0` / `00107a00` / `00107dc0` / `00107fe0` | 38 | ~exact | `cmmCommunity.c` |

The four `cmmCommunity` entries are one **family** — the same
"scan 21 records of stride 16 for a matching id" loop as `func_001077f0` — so the
shape is worth solving once. The blocker is that retail exits the loop on a match
with a `bne`-to-advance plus a `b`-to-exit **pair**, where b210 emits a single
`beq`-to-exit. Measured unreachable via: `goto`, `break`, an inverted test with
`continue`, advance-in-`else`, an explicit entry-`goto` mirroring retail's block
order, a `do`/`while` bottom test, a single-case `switch` (which reaches the exact
size but booleanises the compare), and eleven loop/control-flow pragmas including
`opt_rotateloops` both ways. The note on `func_001077f0` records that an in-loop
`return p != NULL;` does reproduce the branch pair, at the cost of duplicating the
`sltu` — that is the shape to start from.

**A draft that scores well is a starting point, not an answer.** m2c gets pointer
arithmetic wrong in ways that still compile: it emitted `s32 *p; p += 0x10`, which
advances 64 bytes where retail advances 16.

## The retail binary is a MIXED-toolchain build — check the compiler first

Two families this file used to list as MWCCPS2 "compiler floors" are **byte-exact
under ee-gcc**, which means they were never Metrowerks code and no amount of source
shaping or pragma work could ever have matched them.

| function | mwccps2 b210 best | ee-gcc |
|---|---|---|
| `code1_004c func_004c3410` (absolute getter) | nd 2, unmoved by 8 spellings, 4 register/lifetime knobs and 9,039 `permute_ast` compiles | **exact** at `-O2`, every 2.9/2.95/2.96 variant |
| `code1_0044 func_0044b8d8` (framed tail jump) | never reaches the 24-byte shape across 18 pragma combinations | **exact** at `ee-gcc2.96 -O2` |

Verified through `tools/decompme.py --try ADDR --source ... --against ...`, which
compiles one function against several compilers on decomp.me and reports each score.

**This does not mean switch compilers.** Plenty of functions are the other way
round: `code1_003b func_003bd560` is byte-exact under b210 (with
`#pragma no_branch_likely on`) and scores 545–765 under every gcc. The two
toolchains are interleaved, so the compiler is a per-TU property to be discovered,
not a global setting.

**Where the gcc code is.** Scanning every window ≤ 64 bytes for two unmistakable
gcc shapes — `lui rX / jr $ra / load rY,off(rX)` with `rX != rY`, and
`addiu $sp,-N / sd $ra / ld $ra / j target / addiu $sp,N` — finds 34 and 265
functions respectively. 281 of those 299 sit in `0x004C0000`–`0x0052FFFF`, and that
region is 91% third-party by scanned function count: 561 `cri_adx_grouped.c`, 93
Sony `rofs_*`, 5 `cri_adx.c`, against 64 first-party placeholder entries. **These
families are middleware, not game code.**

So before grinding a function in the promoted `code1_XXXX` files, ask whether it is
game code at all. A gcc signature plus a high address is strong evidence it belongs
to CRI or the Sony SDK and is out of scope for first-party matching.

**Do not use whole-file address spans to decide this.** `cri_adx_grouped.c` spans
`0x0044db98`–`0x0052d980` but is non-contiguous: 943 game functions from
`mdlManager.c`, `effBlurFilter.c`, `sdkSnd.c`, `sdkTask.c` and others are
interleaved inside it. Attribute by nearest scanned neighbour on both sides
instead. On that test, of 7,705 unscanned windows **2,723 are flanked by
third-party on both sides** (likely middleware), 4,099 are flanked by first-party,
and 883 are mixed and need real attribution.

### ...and a mixed-FLAGS build within MWCC: `-O2` versus `-O2,p`

Retail also mixes MWCCPS2 optimisation *variants* per translation unit. The
`0x390000`–`0x3f0000` block (`code1_0039`..`003e`) was built with the
"optimize for speed" variant, `-O2,p`. Measured 2026-09-02:

- The signature is an **alignment `nop` after a filled back-edge delay
  slot** so that the following forward-branch target is 8-aligned
  (`func_003b4230` +0x9c, `func_003bcd50` +164). Plain `-O2` never emits
  it; no matched function anywhere in the tree has that shape; every
  archive in that block that mentions "one trailing nop retail keeps" was
  looking at it.
- `,p` is command-line state. No `#pragma` reaches it (`optimize_for_size
  off` is recognised but does not reproduce it; every other spelling tried
  is unrecognised), and it **survives** a later `#pragma optimization_level
  N`, so it cannot be bracketed per function — it is carried per unit in
  `config/speed_units.txt` and applied by `tools/verify.py::unit_compile_flags`
  in both verify and build (the same shape as `config/gcc_units.txt`).
- A full verify under a *global* `-O2,p` loses 962 matched functions, while
  the listed units lose zero of their 293 matches and `code1_003c.c` loses
  1 of 105 (`func_003c99f0`, held back until understood). Ordinary game
  units (`code1_001e`, `mdlManager`, `code1_0014`...) lose 20–35% each, so
  this is per-unit, not global.
- With `,p` on, the functions in that block that stalled on the nop are
  re-openable; what remains on `func_003bcd50` is a store-to-load reload
  under CSE (see its archive), and on `func_003b4230` an `s32` counter
  compared against an `s64` parameter without extension.
- Cross-build check (2.4-001213, 3.0.1-020123, 3.0.3-020716, b74, b119,
  b151, b198, b210; all under `-O2,p` and `-O3,p`): none sinks `sd $ra`
  into a branch delay slot (`func_00390290`), none avoids hoisting a load
  over `mult` (`func_003df870`), and none turns an `s64` counter's
  `daddiu` into `addiu` (`func_003b4230`). 2.4 saves `$ra` with `sq`. So
  the block's remaining scheduler-shaped residuals are not a compiler
  version question either; they are source-shape or genuinely open.
  Builds cached under `~/opt/mwcc_all/` for future checks.

### The `lw` before `sd $ra` prologue -- measured 2026-09-03

22 non-matching first-party windows open `addiu $sp / lw $vN,0($aN) / sd $ra`
(6 in `code1_003c`, 5 in `rwcore_grouped`, 4 in `code1_003b`, 2 each in
`code1_0039` and `code1_003e`, one each in `code1_0041`/`0042`/`rt2d`); the
only MATCH with that shape is an ee-gcc unit. `func_003cc250` (nd 4, the rest
of the body exact) was compiled from the same source under every cached MWCC
(2.4, 3.0.1, b74, b119, b151, b198, 3.0.3, b210) at `-O2`, `-O2,p`, `-O3`,
`-O3,p`, `-O4,p`, and under b210 with `-sym on`, `-g`, `-lang c99`, C++ with
and without exceptions/RTTI, `-sdatathreshold 0`, `-once`, every `-inline`
mode and `-opt schedule/nopeephole/speed`: every build saves `$ra` before the
first parameter load. Not a compiler-version or flag question; treat as a
prologue-scheduling floor unless a source shape is found that makes b210
hoist a parameter dereference above the `$ra` store.

### ...and a mixed-COMPILER build: 3.0.1 b210 versus the 2003-2005 builds -- measured 2026-09-03

`movz`/`movn` conditional moves are a compiler-BUILD signature, not a floor.
MWCCPS2 3.0.1 b210 (the project default) and b198 never emit them at any `-O`
level, with or without `,p`, in C or C++; 3.0.1 b74 (2003-08), b119 (2004-09)
and b151 (2005-03) emit them from a plain ternary, and `func_003cb720`'s
`return field ? arg0 : 0;` is byte-exact under all three. 2.4 and 3.0.3 emit
them too but save `$ra` with `sq`/hoist the prologue. Whole-tree verify under
b119 against the b210-tuned sources: 4620 of 7468 kept overall, with ordinary
game units losing 20-85% each (shdPersona 0/88, datPersona 7/51), but the
RenderWare-derived block (`code1_0039`..`003e`, `src/rw/`) keeping 488/529.
So b210 is right for Atlus's code and an older build for the prebuilt
RenderWare objects that the promoted `code1_003x` units interleave with it.

The compiler is now carried per unit: `config/compiler_units.txt` maps a unit
to a version key, `mwcc_versions` in the local verify/build config (or
`P4_MWCC_<KEY>`) maps the key to a binary, and `verify.unit_compiler()` feeds
both verify and build (cache keys include the binary). `code1_003c_cw119.c`
is the first such unit. CI resolves the key through the container: the
Dockerfile installs `/usr/local/bin/mwccps2-cw3.0.1b119.exe` (a wibo wrapper
over `P4_MWCC_CW3_0_1B119_BINARY`, mounted from `cw3.0.1b119/mwccps2.exe` in
the private dependencies repository) and exports `P4_MWCC_CW3_0_1B119` to it;
a unit naming an unconfigured version fails verify outright rather than
scoring against b210. The cw119 units are not link-eligible (their functions
are not contiguous with the unit's first), so the full-link SHA1 never sees
their relocations; `verify.py` now cross-checks every gp-relative and
%hi/%lo relocation of a MATCH function against retail's immediate using the
candidate's addend (`WRONG SYMBOL`, a hard failure). Its first run found
seven latent wrong-symbol matches: three in cw119 units (`iGpffffb680` for
`iGpffffaa7c`, `iGpffffb6f8` for `iGpffffb700` plus `D_008873F8[0x46]` for
`[0]`, `iGpffffb768` for `iGpffffb788`) and three in unlinked b210 units
(btlCamera `DAT_00761188` for `fGpffff8110`, code1_0045 `D_008872F8` for
`fGpffff8200` - 64K out of gp's reach, k_fldUnit a file-static shadowing
`iGpffffb2e8` where one site is `iGpffffb2e4`). Two cautions from the
measurements:

**2026-09-03: the block is RenderWare Graphics 3.7.** `func_003e46e0` is
`_rwChunkGroupOpen` (core/src/plcore/rwgrp.c) line for line; its `0x40412` is
`rwMEMHINTDUR_GLOBAL | rwID_CHUNKGROUPMODULE`, `D_008872E0 + iGpffffXXXX` is
`RWPLUGINOFFSET(RwEngineInstance, module.globalsOffset)`, `D_008873F8[0]` is
`RWSRCGLOBAL(memoryAlloc)`, and the retail ELF carries the 3.7.0.x version word.
The source (rwsrc-v3.7.0.2, checked out beside the repo) ports verbatim: the
rwgrp.c text with RWFUNCTION/RWASSERT/RWRETURN as written is byte-exact under
b119 with schedule on, once RwEngineInstance is the static `ourGlobals` array
(RWGLOBALSIZE) and the module statics are externs at their retail addresses.
Headers are vendored under include/rw (public misc/inc plus the internal
plcore/core/p2/world/driver headers, a PS2 ostypes.h with 16-byte matrix
alignment, and libc shims), reached through config/version_flags.txt for the
b119 units. Lane rules: build/LANE_RULES.md, RenderWare section.

**2026-09-04: the block's build flags are `-O4,p -inline auto -DRWBUILDNUMBER=55`,
and the port is mostly automatic.** At `-O2` b119 inverts a plain `while` into a
bottom-tested loop; retail's are top-tested, and `optimization_level 3`/`4` keep
the verbatim source exact (batkbin.c was the probe). `-inline auto` reproduces
the inlined same-unit callees (WriteDataChunks carries GetSize inline next to the
out-of-line copy), and every chunk header is written with build 55 where the
3.7.0.2 tree defaults to 101. `build/rw_fid.py` compiles the sources with those
flags and fingerprints them against the block (relocation fields masked, equal
length, strictly increasing addresses per source file): 360 byte-exact hits at
`-O4,p` against 259 at `-O3,p` and 130 at `-O2,p`. `build/rw_port.py` turns a
source file into a `src/renderware/<dir>/<file>.c` unit (verbatim text, markers
for the mapped functions, statics to retail-addressed externs, aliases for
unported callees) and keeps only what verifies; `build/rw_dedupe.py` then
arbitrates the identical-body ties (every module's RegisterPluginStream /
GetPluginOffset / Close) by requiring each file static to resolve to one address
from its unique-window functions and every caller's retail `jal` to agree. Result
of the first pass: 45 units, 291 functions, all verbatim. What did not verify is
a short list (RwEngine subsystem getters the PS2 driver overrides, `,p`
alignment shapes, texture/stream functions that changed between build 55 and
build 101) and is worked by hand. `src/renderware/` is classified third-party
like `src/rw/`: the block was never Atlus's code, so the first-party denominator
shrinks as it is ported out of the promoted code1_003x units.

The block is now a vendor address span in `tools/verify.py` (`0x0038F990`, the
first function after ed_res.c and a caller of `_rwerror`/`RwErrorSet`, up to the
CRI span at `0x00417510`), so the whole of it - core, plugins, sky2 driver - is
third-party whatever unit it currently sits in: first-party is 6023/6861
(87.8%) with the block out. The RenderWare 3.5 PS2 SDK (`../rwsdk-v3.5-ps2`,
binary libraries plus the sky2 headers) confirms the layout - its sky2
`rwplcore.h` carries exactly the alignment settings `include/rw/ps2/ostypes.h`
reproduces - and names the driver/plugin functions no source exists for, but
its bytes are a different version and do not fingerprint (build/rw35_fid.json).

- **b119's prologue scheduling is unit-state dependent.** The same
  `func_003cb720` body is nd 0 when compiled inside the whole `code1_003c.c`
  (b119 loses only 7 of that unit's 107 matches) but nd 9 in a fresh unit,
  where b119 hoists `move $a1,$a2` above `sd $ra`. Bisecting the preceding
  content found a flip between two adjacent INCLUDE_ASM fallbacks, yet the
  region from that point on does not reproduce it, and neither pragmas,
  placeholder asm, padding nor function count do. Carving single functions
  into a b119 unit is therefore not reliable; the honest split is whole
  units, which means re-spelling the few b210-only matches (`func_003c9c20`
  nd 10, `func_003cb250` nd 9, five more) before the block can move.
- The `lw` before `sd $ra` prologue (below) is NOT explained by the build:
  every cached build keeps the `$ra` store first for that source.
- Likewise a parameter `move` interleaved between the `sq` saves
  (`func_003c47c0`: retail `sq $s1; move $s1,$a0; sq $s0`, every build
  emits `sq $s1; sq $s0; move`, nd 3): measured 2026-09-03 under b74, b119,
  b151, b198, `-O2,p`, optimization_level 1/3/4, opt_common_subs /
  opt_loop_invariants / opt_rebuildconditionals off, tailcall off, eleven
  spellings (self copy, child local, sum orders, `u8 **` parameter,
  explicit temporaries), inside the whole parent and at every position in
  the cw119 unit. `func_003e8ed0` (nd 17) is the same shape. Not a lever
  question; do not re-probe.

## Known compiler floors (do not fight these)

When the only residual is one of these, the function is a compiler floor:
keep the best source, tag the marker `// FUN_XXXXXXXX NONMATCHING` (with a
short comment recording what was tried), and move on. Retrying exhausted
variants is wasted time.

- **Call-argument setup order before a JAL — SOLVED for the address case.**
  Used to read "a scheduler choice the C argument list cannot always
  reproduce". Measured: a stack-buffer address argument is materialised
  *first* (`addiu $a2,$sp` before the `move $a0/$a1`) when the source casts
  it to an integer (`(s32)buf`, `(s32)p`, `(s32)&buf[0]`) or the callee's
  parameter is integer-typed; it is materialised *last*, after the register
  moves, when `buf` is passed as-is to a **pointer-typed parameter**. The
  cast turns the address into a computed value that goes into the argument
  order first; the plain pointer is a "load-like" operand and follows.
  Closed `func_002782c0` (itfMesManager.c, nd10 -> 0) by retyping
  `func_00278450`'s third parameter `char *` (the callee stayed MATCH; its
  body only passes the value on). `#pragma schedule on` also reorders the
  pair but wrecks everything else. The mirror case — retail materialises an
  argument address *early*, e.g. `addiu $a0,$sp,0x5C` before the store into
  that very slot, or `addiu $a1,$sp,0x40` between two quad stores — is the
  address taken into a pointer local at that point in the source, under
  `opt_propagation off` so it is not folded back to the call:
  `pf = &fbuf; fbuf = ...; ...; a16 = (u_long128 *)&arr[16]; *(u_long128 *)&arr[16] = q; call(pf, a16, ...)`
  (the store itself stays direct so it addresses `$sp`). Closed
  `func_0025b0f0` (cmmRankUp.c, nd24 -> 0). Both members of this entry are
  now closed.
- **Argument masks before or after the loads — the prototype decides.**
  With a prototyped `u16` parameter mwcc emits every conversion (`andi
  $aN,$rX,0xffff`) *before* the memory-operand arguments (`lhu $a0/$a1`),
  and a plain register move after them. Retail `andi $a2,$v0` / `lhu` /
  `lhu` / `andi $a3,$s1` (one mask before, one after) is an **unprototyped
  call**: `extern s32 func_00161630();` with a `u16 b` local (its mask is
  the assignment, allocated straight into `$a2`) and an explicit `(u16)a`
  cast on the last argument (default promotion, emitted in argument order
  after the loads). Both masks written as casts under the old-style
  declaration put the loads first instead. Closed `func_00178870`
  (code1_0017.c, nd4 -> 0); measured in isolation across 22 spellings.
- **Entry parks are emitted in PARAMETER order.** Retail `move $s6,$a0 /
  mov.s $f21,$f12 / mov.s $f20,$f13 / move $v1,$a1 / move $s4,$a2` is not a
  scheduling floor: the floats sit between the GPR parks because the source
  declared them second and third (`(ctx, x, y, text, flag, color)`); the EE
  ABI assigns int and float argument registers independently, so callers are
  byte-identical under either order. Named copies (`context = arg0`) turn a
  park into a statement and lose the position. Closed `func_0020e420`
  (code1_0020.c) together with: unsigned `arg3` (`srl` not `sra`), `(s8)(u8)`
  colour bytes into `u64` locals (dsll32/dsra32), `c = (u8)c` before the loop
  (in-place `andi`), a block-scope `s64`-parameter declaration of the callee
  so the masked values pass with a bare `move`, and `i = 0` written before
  the masks so the index inherits the dead flag's `$s4`.
- **"COP1 accumulator-chain floor" archives are not floors.** 41 archives
  carried that classification with no source probing; the first four opened
  (`func_001bc660` - no COP1 at all, `func_00208870`, `func_0020e420`,
  `func_003a9e50`) all closed. Treat every such archive as a fresh target.
- **The "s64-parameter-normalization floor" (y_fclCombineDraw.c draw family)
  is narrow-type canonicalisation, and it is reachable.** Every `dsll32
  $r,$r,0x18 / dsra32` (or `0x10`) pair in that family is b210 canonicalising
  an `s8` (`s16`) value into its 64-bit register form: an `s8` parameter at
  entry (`dsll32 $s1,$a2,0x18`), an `s16` callee's return value right after
  the `jal` (`dsll32 $a0,$v0,0x10` after `func_002b6970`), or an `s8`
  callee *parameter* being materialised. Closed `func_003146f0` (the file's
  oldest parked entry, 68/80): the late `dsll32/dsra32` into `$a3` is an
  `s8` parameter of `func_0011b480` declared at **block scope** (the
  file-scope prototype stays `s32` for the matched callers), fed by the
  reload of the byte just stored (`*(s8 *)(obj + 0xC)`, store-forwarded from
  the `$v1` park) - that is emitted in argument order, whereas `(s8)arg2` /
  `(s64)arg2` casts of the parameter are hoisted ahead of the loaded
  arguments (nd45). Declaring the callee's parameter `s64` produces the same
  shifts but still hoisted. The 37 remaining functions in that file carry
  "floor" notes written before this was understood; treat them as open.
- **Store-to-load forwarding is a PEEPHOLE: `#pragma peephole off` keeps the
  reload.** Retail's `sw $v0,0xc($s2); lw $s3,0xc($s2)` (and the same on the
  `0x10` field) in the 0039-003e allocator block is not reachable by access
  types, aliases, `opt_propagation off`, `opt_common_subs off`,
  `opt_pointer_analysis off`, `global_optimizer off` or `opt_lifetimes off`
  (all forward the store); `#pragma peephole off` reproduces both reloads
  exactly (`func_003a8500`, now nd12 = saved-register colouring only,
  archived as `Main_003a8500_body.c`). `peephole` is recognised by b210
  (compile-probed) and is function-granular like the other knobs. Cost: the
  same peephole also removes the `dsll32/dsra32` that an `s32`->`s64`
  conversion leaves after a fresh `lw`, so a function that needs both a
  post-store reload and the `slt $at,$zero,$v0` 64-bit guard (`func_003bcd50`)
  cannot have both - with `peephole off` every guard spelling either keeps the
  shifts or folds to `blez`. That one closes only with `volatile` (banned).
  Closed with `peephole off` instead of the banned `volatile` the archives
  had needed: `func_003c3e90`, `func_003e2570`, `func_003e8080` (all the
  `*slot = result; result = *slot;` allocator idiom). `func_003de8c0`'s
  archived volatile turned out unnecessary under the unit's `-O2,p`.
  Also `func_003d5fb0` (84/96; plus a named `self` copy under
  `opt_propagation off` so the flags load is issued from `$a0` before the
  park). Second exclusive case: `func_003d0460` - the same `peephole off`
  that keeps its six `*arg1` reloads removes retail's tail-merge branch into
  the epilogue with `ld $ra` in the delay slot (archived at nd34).
- **A call result used directly as an argument and parked across an inner
  call takes the LOWEST saved register, below declared locals.** Retail
  `obj=$s1, colour=$s0` (`func_0032c480`, y_fclCombineDraw.c) is not reachable
  by declaring `colour` in any order or scope (every permutation gives
  `obj=$s0`); writing `func_00275820(func_002b2a30(0, 0, 0, 0xFF), ...)` with
  the inner `func_002e48a0` call in a later argument parks the result in `$s0`
  under the declared `obj`. Took that function from nd31 to nd13.
- **Loop-invariant constant hoisting into the preheader.** mwcc sometimes
  hoists a constant into the preheader where retail rematerializes it in the
  loop (or the reverse — see the `opt_loop_invariants` waiver in
  `src/Battle/btlTarget.c`, where retail hoists and mwcc rematerializes with
  swapped `addiu/sllv` operands). `opt_loop_invariants on` under push/pop has
  since closed six functions (0012d410, 0012dea0, 00359400, 002b7f20,
  0016f3b0, 00473870) — measure it before calling this a floor.
- **A `base + i*stride` slot address that retail rematerialises several times
  is NOT a GVN floor.** `func_00165380` (k_fldUnit.c, nd 148 -> 0): retail
  recomputes `D_007E8C00 + i*0x750` (mult/lui/addiu/addu) at the head of each
  section and again for a call argument, while mwcc folds every use onto one
  saved register. Write a fresh `slot = D_007E8C00 + i * 0x750;` at the head
  of each section (and the bare expression as the call argument) under
  `opt_common_subs off`; each reassignment then rematerialises. A pointer bump
  that must stay an `addiu $s0,$s0,0x54` between two calls (instead of being
  folded into the store offset) additionally needs `opt_propagation off`, with
  the argument mask computed first (`t2 = t1 & 0xFFFF; slot += 0x54;`) so the
  `andi` precedes it. A recompute that must precede a call's first argument
  load is its own statement (`p = ...;`) before the call.
- **A value written by an asm island must be read back through its
  address.** `func_004adb50` (code1_004a.c, nd 118 -> 0): the VU0 colour-pack
  island ends with `sw $2, 0x134($sp)`; reading it as `color = sp134` leaves
  the compiler free to float the load (the local is uninitialised from its
  point of view), which also flipped the entire saved-register ranking
  (param and loop bound at the bottom). `color = *(s32 *)&sp134;` - the
  effModel.c form - pins the `lw $s5` right after the island and restores
  the documented ranking (params first, locals in declaration order).
- **Saved-register coloring cycles.** A parameter and a surviving local both
  wanting the same callee-saved register (the param-vs-local `s0/s1` fight),
  or a register reused as an unrelated counter on a sibling branch — these are
  allocation cycles the source cannot break.
- **Independent adjacent memory access order.** Two adjacent loads or stores
  from different fields compile in an order the scheduler picks; when it
  disagrees with retail and the two accesses are genuinely independent, no
  source order fixes it (see also the commutative-`addu` section — but those
  levers work only when the order is *dependent* on addressing).
  **Measured exception — 12-byte aggregate copies.** A `ld/lwc1/sd/swc1`
  copy (retail loads the 64-bit half first) is a struct assignment between
  two *struct-typed locals*: `Vec3 d, s; d = s;`. The `ld` appears only
  when mwcc knows the slot is 8-aligned, which it does for top-level locals
  (each gets its own 16-byte slot) and does **not** for a member of a
  packed "frame" struct (type alignment 4 → three `lwc1`). A helper taking
  `(s64 *, f32 *)` pointers gives `lwc1; ld; sd; swc1`; casts on either
  side (`*(V3 *)arr = ...`) give three `lwc1`. Closed `func_001cff00`
  (code1_001c.c, nd2 -> 0) by dissolving the lane's frame struct into
  `Vec3 target; Vec3 source; struct { f32 first[10]; u8 second[0x28]; } fr;`
  — retail's slot spacing (0x90/0xA0 for the two Vec3s, `first`/`second`
  contiguous) is exactly what mwcc's per-local 16-byte slots produce, and
  is how to tell packed-frame locals from separate ones.
  Second closure `func_0017ea10` (k_fldAI.c, nd4 -> 0): the 24-byte slot
  holding two Vec3s is `FldAIVec3 ab[2]`, and `out = ab[0]` (element 0 is the
  local's own aligned address) gives `ld/lwc1/sd/swc1`, while `ab[0] = ab[1]`
  and `ab[1] = out` (0x5c, unaligned) are the three-`lwc1` form — all from
  plain struct assignment. `f32 ab[6]` with `*(FldAIVec3 *)ab` casts blinds
  the alignment (three `lwc1`, nd290); a `{s64; f32}` destination type gives
  scalar order `ld/sd/lwc1/swc1` (nd4).
- **~~Framed tail jump~~ and ~~absolute-getter address register~~ — NOT floors,
  wrong compiler.** Both were listed here for a long time and both are **ee-gcc
  code**; see "The retail binary is a MIXED-toolchain build" above. Kept as a
  warning, because the MWCCPS2 evidence looked airtight and was still the wrong
  conclusion.
  * Framed tail jump (~10 functions in `code1_0043`/`code1_0044`): retail wraps
    `return g(a);` in a frame *and* tail-jumps —
    `addiu $sp,-0x10 / sd $ra,($sp) / ld $ra,($sp) / j g / addiu $sp,0x10`, 24
    bytes. b210 only ever emits 8 bytes (frameless jump), 28 (framed `jal`) or 32
    (unscheduled), across all 18 combinations of `optimization_level` 1/2/3 ×
    `tailcall` on/off × `schedule` on/off/absent. **`ee-gcc2.96 -O2` is exact.**
  * Absolute getter (19 functions, `code1_0039/0041/004c/004d/004e/004f/0050/0051/0052`):
    retail emits `lui $v1,%hi(sym) / jr $ra / lw $v0,%lo(sym)($v1)`; b210 reuses
    `$v0` for the address, nd 2 at 12 bytes against a 16-byte window (the gap is
    trailing padding). Unmoved by 8 source spellings, by
    `cse_hard_reg_gpr`/`opt_lifetimes`/`reg_class_allocs`/`opt_scalarizeliveranges`,
    and by 9,039 `permute_ast` compiles (score 9 → 5, never 0).
    **Every ee-gcc 2.9/2.95/2.96 at `-O2` is exact.** Scratch:
    <https://decomp.me/scratch/r8hUx>.
  * `#pragma schedule on` really is load-bearing for the getter shape under b210 —
    without it the `lw` misses the `jr` delay slot — which is exactly why the
    residual looked like one stubborn register instead of a different toolchain.
- **Commutative operand orientation** — `addu` and `mul.s` operand order when
  both operands are live in fixed registers. For float specifically,
  `fresh * invariant` canonicalizes to invariant-first (`mul.s $f0,$f2,$f0`)
  while retail emits fresh-first (`mul.s $f0,$f0,$f2`); neither source
  operand order changes it. Indexed getters/setters and float math are the
  usual victims.
- **`addiu` vs `daddiu` for small constants — SOLVED: narrow unsigned
  destination.** This entry previously said constant materialisation never
  yields `daddiu` and told you to stop probing. That was wrong. The sweep
  explored *arithmetic* spellings exhaustively but never varied the
  destination's signedness and width together. Measured against b210:

  > A constant that fits a signed 16-bit immediate, assigned to an **unsigned
  > destination narrower than 32 bits**, materialises as `daddiu $rX,$zero,K`.

  | destination | constant | result |
  |---|---|---|
  | `u8`, `u16` | 1 | **`daddiu v0,zero,1`** |
  | `u16` | 0x1234 | **`daddiu v0,zero,4660`** |
  | `u16` | 0xffff | `ori` — exceeds a signed 16-bit immediate |
  | `u32` | 1 | `addiu`/`li` |
  | `s8`, `s16` | 1 | `addiu`/`li` |
  | unsigned bitfield (`u64 NLOOP:15`, `u32 a:15`) | any | **`daddiu`** |

  Unsignedness and narrowness are both required; signed narrow types do not do
  it; bitfields are just the special case. Liveness across a call is NOT
  required — a leaf function with no calls still emits it.

  **Detection:** a repeated `andi $rX,$rY,0xffff` after every arithmetic op is
  the signature of a `u16` local (`0xff` for `u8`). If that masking surrounds
  a `daddiu` you cannot produce, your variable is `u32` or `s32` where retail's
  is `u16`. Reproduced exactly on `func_001e7ab0`: a `u16` loop counter reset
  to 1 inside a branch gives retail's `andi`/`daddiu`/`andi` sequence
  instruction for instruction.

  **Third case — a `u8` return whose callers do not re-mask.** Retail
  `daddiu $v0,$zero,K` straight into the return register with no `andi` at
  the return, while the *matched* caller in the same unit also has no
  `andi` after the `jal`: the definition returns `u8` (constants land in
  `$v0` as `daddiu`, `v >>= 1` on the `u8` avoids the extra re-mask that a
  spelled-out `(u32)v >> 1` adds) but the caller was compiled against the
  32-bit prototype the other units declare (`datScript.c` says `s32`). A
  merged unit reproduces that split with a **block-scope declaration** in
  the caller — `extern u32 func_00232c70(u8 *, s32);` inside the caller's
  body — which b210 accepts silently over the conflicting `u8` file-scope
  prototype and compiles the call without the promotion mask. Closed
  `func_00232c70` (datCalc.c, nd2 -> 0) with `func_002384b0` still MATCH.
  A file-scope `u32` prototype instead re-masks the callee's return
  (`daddiu v1` + `andi v0,v1`); a function-pointer cast at the call is a
  different call shape (nd 482).

  **Second half of the same closure — the fused post-increment.** Retyping the
  counter reaches the `daddiu` but can cost more than it gains: on
  `func_001e7ab0` it went from 1 differing word to 4, because mwcc then CSE'd
  the `0xffff` mask between the array index and the increment, so the
  increment read the masked temp where retail reads the counter register.
  Retail's five-instruction idiom is a subscript post-increment:

  ```
  andi  v0, s1, 0xffff     |   sp60[n++] = value;      /* n is u16 */
  sll   v0, v0, 2          |
  addu  v0, v0, sp         |   masked value feeds ONLY the address;
  sw    s0, 0x60(v0)       |   the increment comes from the unmasked
  addiu v0, s1, 1          |   counter register, then re-narrows
  andi  s1, v0, 0xffff     |
  ```

  Writing it as two statements (`sp60[n] = value; n = n + 1;`) invites the
  reuse; fusing it into `sp60[n++]` does not. `#pragma opt_common_subs off` is
  the wrong instrument — measured, it disabled CSE far too broadly and blew the
  residual out to 64 words at 372B against a 368B window. **If a masked index
  and an increment of the same variable differ only in which register they
  read, fuse them into one post-increment expression.** That pair of levers
  closed the campaign's oldest one-word near-miss.

  **Three spellings of the split, now all proven.** The retype nearly always
  reaches the `daddiu` on first application — it did in all eight functions of
  the first pool wave — and what remains is keeping the masked index apart
  from the increment. Pick by control flow:

  | shape | when |
  |---|---|
  | `sp60[n++] = v;` | increment happens exactly when the store does (`func_001e7ab0`, `func_001932f0`) |
  | `for (...; n++) { ... a[n] = v; }` | increment is unconditional, store is conditional (`func_00477ca0`) — a fused `[n++]` here would skip the increment on the false path, and adding `else n++` duplicates the update (+50 words) |
  | `u16` local **and** `u16` return type | the narrow value is returned; a `u16` local with an `s32` return closed neither `func_00209870` nor `func_00209dc0` |

  A fourth wrinkle from `func_001658b0`: the rule can apply in both directions
  inside one function. Split an `s32` base from a `u16` code so that the two
  constants retail materialises with `daddiu` come from the `u16` and the two it
  materialises with `addiu` come from the `s32`.

  Rebuild the target pool with a scan for opcode `0x19` with `rs == 0`
  (`daddiu $rX,$zero,K`) over the unmatched set: 107 functions, 338
  instructions, at the time of writing.

  Everything the old sweep ruled out stays ruled out, and none of it is a
  substitute: `*p |= 255` on a `u64` gives `ori`, a `u64` local built from
  constants gives `ori`, constants passed to `u64` parameters give neither,
  and `1`/`1LL`/`(long long)1`/`s64` returns/64-bit locals/64-bit stores all
  give `addiu`. A 64-bit add with a live REGISTER operand also emits `daddiu`
  (`long long x; return x + 1;` → `64820001`), but that is a different shape
  from the `$zero`-source constants in the retail family.

  These are PS2 GS/GIF packet structures, so bitfields in 64-bit words are
  what retail's source almost certainly used; reconstructions that build the
  same words with shifts and ORs emit `ori`/`addiu` and miss. **If retail has
  `daddiu` where you have `addiu` and the value is a packed field, write it as
  a bitfield assignment.**

  Members to re-open, all previously archived as unreachable:
  `func_001e7ab0` (nd 1, +0xEC — the campaign's closest near-miss),
  `func_00232c70` (nd 2), `func_00209870` (nd 6), `func_0034ac00` (5 words),
  `func_0038b1c0` (nd 6, whose residuals decode as `daddiu a2,zero,0xff` /
  `a3,zero,0xbe` / `t0,zero,0x5a` / `a2,zero,0x2b` / `a3,zero,0x26` /
  `t0,zero,0x1e` — three-channel colour values in consecutive argument
  registers, exactly what a packed-colour bitfield write produces).
  Full write-up: `docs/open_question_daddiu.md`.
- **Chained-load intermediate register in a delay-slot getter.** The
  `code1_004c`–`code1_0052` getter family: retail is exactly three words,
  `lui $v1,%hi / jr $ra / lw $v0,%lo($v1)` (or `lw $v1,off($a0) / jr $ra /
  lw $v0,off2($v1)`), i.e. the ADDRESS lands in `$v1` and the loaded value in
  `$v0`, with the second load in the `jr` delay slot. b210 always reuses `$v0`
  for the intermediate, giving `lw $v0,off($v0)`. That single word is the whole
  residual — but only after `#pragma schedule on`, which is required in these
  files (scheduling is off at file scope) to fill the delay slot at all;
  without it the object is four words against a three-word window. Measured
  invariant across five source forms: a magic `0x00710000 + off` literal, a
  `u32 *` pointer local, two separate locals for base and value, a scalar
  `extern u32 D_xxxxxxxx;` (which becomes gp-relative and is two words, too
  short), and `extern u32 D_xxxxxxxx[]; return D_xxxxxxxx[0];`. The array-extern
  form is the one to keep: it is the only spelling that both reproduces retail's
  relocated `%hi`/`%lo` pair and avoids inventing a magic address. 19 functions
  sit on this, all at exactly one differing word; `tools/permute_sweep.py`
  scores every one of them 2 and cracks none.

  Measured budget ceiling for the text-level permuter, so nobody re-runs it: a
  60-second-per-function sweep over all 86 functions with a preserved
  `#ifdef NON_MATCHING` body cracked three (`y_fclModel func_0034a4f0`,
  `code1_0017 func_00176220`, `btlResultHeroLvUp func_00221cf0`). A second sweep
  at **420 seconds** over the 35 that had scored 3–60 cracked **none**, and
  every score was identical to the 60-second run. `tools/permute.py` converges
  well inside a minute; more time buys nothing. What is left needs a search that
  RESTRUCTURES code rather than reordering lines and swapping operands — i.e.
  `permute_ast.py` and decomp-permuter's AST passes, not a longer budget.
- **~~128-bit `lq`/`sq` aggregate copy~~ — NOT a floor; `__int128` works.**
  This entry used to claim "no genuine 128-bit type in this repo... reaching
  these needs a real quadword type first" and told people not to retry. That
  was wrong even at the time it was written: `mwccps2.exe` recognizes
  `__int128` as a real type (confirmed by extracting identifier strings from
  the compiler binary and a direct compile probe) and lowers a same-size
  load/store or struct-field copy through it straight to `lq`/`sq` —
  `typedef signed __int128 s128; s128 t = *(s128*)src; *(s128*)dst = t;`
  compiles to exactly `lq $v0,($a1) / sq $v0,($a0) / jr $ra`, byte-for-byte.
  Three functions already MATCH on this exact shape:
  `effBlurFilter.c func_004ab3f0`/`func_004ab930`
  (`typedef signed __int128 s128;` declared locally in the file) and
  `evtPolygonMovie.c` uses the same typedef for a small array of `s128`
  globals. `shdSprite.c` also declares it. Copy this local-typedef pattern
  (do not add it to `include/type.h` — it is file-scoped by convention here)
  into any other file with an `lq`/`sq`-shaped residual.
  **Limitation found by direct probe:** `__int128` supports assignment
  (scalar, array element, struct field, function parameter/return) but NOT
  relational or equality operators — `a == b` on two `__int128` values fails
  to compile with `illegal data size`. This matches what retail actually
  does for a "128-bit compare": it is never a real 128-bit compare. Retail
  uses `lq`/`sq` purely as a fast 16-byte block move (e.g. into a stack
  scratch slot), then compares only the reloaded value's low word with an
  ordinary scalar load and `bne`/`sltu`. Model this in C as: move via
  `s128`, then separately re-read and compare the *narrower* scalar field
  you actually need — do not try to make the comparison itself go through
  the 128-bit type.
  Still genuinely useful before writing off a residual as this floor:
  confirm with `RECON_dis.py` that the retail window truly contains an
  `lq`/`sq` pair and not just a coincidental instruction encoding.
- **Zero padding tail.** A 4–12 byte deficit after retail's last real
  instruction is zero padding, not missing logic. `verify.py` treats an
  all-zero tail as matching (`MATCH`; object 108B in a 112B window, 148B in a
  160B window, etc.), and `fndiff.py` counts those tail words in its summary.
  Do not add code to fill it.
- **Instruction scheduling / subexpression evaluation order** in general;
  and **FPU-register allocation**.
  The **`slti $at` branch-temp idiom** used to be listed here ("the `$at`
  layout is not always reachable while preserving the inline/out-line
  arrangement"). It is reachable: the full spelling grid is under
  "`slt $at` vs `slt $v0`" above — `<=`/`>` always use `$at`, `<`/`>=` use
  `$vN` exactly when the branch is `bnez`, and loops/early-returns invert the
  `if` table. Only `$vN + beqz` is unreachable.
  **u16-mask propagation** used to be listed here as "retail re-masks per
  use, mwcc elides the repeat". Measured against b210, the number of `andi
  $r,$r,0xffff` per loop iteration is a source knob (counter passed to a
  call and compared against a `u16` load):

  ```c
  u16 i; for (i = 0; i < *p; i++) sink(i);            /* TWO: andi s0,v1 (increment) + andi a0,s0 (compare) */
  s32 i; for (i = 0; i < *p; i++) sink((u16)i);       /* ONE: at the use only */
  u16 i = 0; while (i < *p) { sink(i); i = i + 1; }   /* THREE */
  u32 i; ...            sink(i & 0xffff);             /* ONE, and sltu instead of slt */
  ```

  Count retail's `andi` per iteration and note which operands carry them
  (increment result, compare operand, call argument), then pick the counter
  declaration and loop form that emits exactly that.
  Two entries used to sit here and are solved: switch case-order (reverse
  written order, top of this file; closed `func_0019fc70`), and the
  **boolean-result tail layout** — "retail places the 0-materialization
  block after the main body but before the 1-materialization, which mwcc
  never emits". Measured: it emits it whenever the `1` return is a labelled
  block written *after* the `return 0`, reached by `goto`:

  ```c
  for (...) { if (hit) return 1; }  return 0;             /* li v0,1 in-loop; move v0,zero at tail */
  for (...) { if (hit) goto yes; }  return 0; yes: return 1;  /* move v0,zero; b; li v0,1; jr — the "impossible" layout */
  r = 1; for (...) { if (hit) goto out; } r = 0; out: return r;  /* li v0,1 at entry */
  ```

  Block order in the object follows the written order of the labelled
  blocks; `return` inside the loop inlines the constant at the branch site.

## Target selection: measured cost of choosing wrong (four 16-lane waves, zero closures)

Four consecutive 16-lane waves produced no first-party closure. Every failure
traces to target SELECTION, not to lane technique, and each rule below is the
correction:

- **Filter the census with `verify.is_vendor_address`, never by filename.**
  A whole wave was spent on `code1_0042`/`0043`/`0044`/`004c`/`004d`/`0051`,
  which look like the largest never-attempted pools in the tree (291, 236, 226,
  118, 74 rows). They are entirely inside `VENDOR_CODE_RANGES`
  (`0x00417510-0x0044E830`, `0x004BD628-0x0052D8C0`, `0x0070C850-0x0070E140`)
  and score ZERO against the first-party metric. The tell before you dispatch:
  a scoped `verify.py` on the file prints `first-party functions scanned: 0`.
  Correct first-party never-attempted total at 6084/7866: **1778 rows**, and
  the largest pools are `code1_003c` (107), `003e` (97), `003d` (94),
  `003b` (92), `0039` (79), `003a` (64).
- **The tiny-window seam is exhausted.** Exactly four first-party ASM rows have
  a window of 32 bytes or less, and all four are documented floors
  (`00399320`/`00399450` movn; `003df870`/`003df8a0` delay-slot scheduling).
  Anything reading "smallest window first" below 48 bytes will find nothing.
- **Do not re-grind the measured near-miss tail.** A wave that attacked the
  twelve smallest known residuals (nd 5-28: `0011b110` 5, `003d59a0` 5,
  `003de8c0` 6, `0011c930` 7, `0011c780` 8, `003de280` 8, `00396940` 15,
  `0032b770` 16, `0039bb70` 16, `003e3830` 18, `003f2760` 28) ran 8-11 distinct
  hypotheses each — 130 measured source revisions — and moved not one of them.
  Several nd values also re-measured WORSE than their archived note, confirming
  archived nd is not a ranking key.
- **Permuter reach is confirmed exhausted on this tree.** Seeding 4387 m2c
  candidates as `#ifdef NON_MATCHING` bodies and sweeping the 342 first-party
  ones with the text engine at 240s x 20 workers cracked **zero**. This
  reproduces, at 2.6x the seed count, the result already recorded above.

What is left for the first-party metric is 1778 never-attempted functions with
a median window near 400 bytes in units at 40-60% density, plus roughly 100
ground near-misses on documented floors. The productive shape remains a lane
per file in a unit that is ALREADY 90%+ matched, reading its matched
neighbours for struct and callee spellings before writing anything.

## The P3 FES twin port is the seam that still yields

After four zero-yield reconstruction waves, eight functions closed in three
waves by porting from the sibling Persona 3 FES decomp. Build the candidate
list yourself rather than trusting `build/shared_p3.json`, which read the
committed P3 metrics snapshot as **1** matched address instead of 6922:

1. Read both `image.bin` files with their window maps
   (`tools/slus21782_functions.json`, P3 `tools/slus21621_functions.json`,
   load base `0x00100000`).
2. Fingerprint every function as sha1 over MASKED words: SPECIAL and MMI
   (op `0x00`, `0x1C`) kept whole because the registers are the signal; `J`/`JAL`
   reduced to the opcode; branches and every other I-type masked to
   `word & 0xFFFF0000`; COP1/COP2 keep opcode plus sub-opcode.
3. Join on `(window_size, fingerprint)` — exact size equality is required.
4. Keep only donors listed in the P3 checkout's
   `progress/metrics.json` -> `matching.addresses`.
5. Filter P4 rows through BOTH `verify.is_third_party` and
   `verify.is_vendor_address`.

That produced 41 first-party twins, of which 8 closed. Three facts decide the
outcome of each port:

- **The residual is always an IMMEDIATE.** The donor supplies the shape; P4
  supplies every number. Four of the eight closed only after correcting one
  field offset the donor carried over from P3 (`0x18`->`0x1c`, index `[5]`->`[6]`,
  `0x2cc`->`0x318`) and one after loading a field the port passed by address.
  Reconcile differing words one at a time with `tools/fndiff.py`; never rewrite
  the ported body, which scored worse every time it was tried.
- **Roughly a third of donors are `asm __volatile__` bodies** — including both
  `k_vpad` twins, the `mdlEffect` VU matrix builder, and the `rwplcore` pair
  that P3 matched with raw `.word` directives. Classify the donor body FIRST;
  copying it is a policy violation and gains nothing over `INCLUDE_ASM`.
- **An opcode-only re-join adds nothing** (measured: zero extra candidates), and
  broadening the donor set from "P3 verifier-matched" to "P3 body not marked
  NONMATCHING" adds four, all of which are inline asm or `TODO window stub`.
  The twin seam is exhausted at 41.

## Rank the archive corpus by measurement, not by its notes

`archive_to_guard --apply` installs archived bodies as `#ifdef NON_MATCHING`
blocks, which `verify.py` never scores — so a guarded corpus tells you nothing.
Two tools now measure it:

- `build/arch_measure.py` activates each guarded body one at a time
  (`permute_sweep.activate` + `permute.Target.score`) and writes an nd ranking.
  Measured over 726 archives: **520 first-party scored, 30 at nd <= 10, 53 at
  nd <= 20.**
- `build/arch_classify.py` additionally diffs the object against the retail
  window word by word and names the residual class: `immediate` (same opcode and
  registers, only the 16-bit field differs — the mechanically fixable case),
  `width` (`addiu`/`daddiu`, a type fact), `register`, `opcode`, or `size`.

The classification over 686 first-party archives is the campaign's real shape:
**361 `size`** (the body is missing or carrying a whole block — 75 of them
within 4 bytes, 220 within 16), 166 that the permuter harness cannot even
locate, 110 that no longer compile in the current declaration environment, and
only **~45 with a pure word-level residual**. Of those, exactly four are a
single-kind residual, and each was then proven a floor by direct probing:
`001932f0` one `addiu`/`daddiu` word, `00153300` an aggregate `sd` where retail
emits `swc1` (unmoved by field-wise copy, temporaries, statement order, and
every scheduling pragma), `0044ee70` a store/argument transposition, `001ee490`
the `slti $at` versus `slti $v0` branch-temp idiom.

The practical consequence: **stop mining the near-miss tail.** The remaining
first-party work is dominated by `size` rows, i.e. functions whose C is missing
real logic, and those are reconstruction problems, not residual problems.

## Where the remaining 1765 first-party functions actually stand

Every search avenue has now been measured to exhaustion, and the numbers are
worth stating plainly so nobody re-runs them:

| avenue | attempted | closed |
|---|---|---|
| P3 FES twin ports (masked-fingerprint join) | 41 | 8 |
| decomp-permuter, both engines, all seed corpora and score bands | ~1500 sweeps | 8 |
| archive near-miss tail, hand lanes | ~60 | 0 |
| m2c near-miss band, hand lanes | 16 | 0 |
| undersized archives ("missing block"), hand lanes | 32 | 1 |
| never-attempted functions in 89-98% dense units, hand lanes | 16 | 0 |
| P3 twins at +/-4 instructions (`build/twin_nearsize.py`) | 16 | 0 |
| never-archived LEAF functions (no saved registers) | 20 | 0 |
| MWCC command-line flag sweep (`build/flag_sweep*.py`) | 15 flag sets x 128 bodies | 0 |
| reconstruction of never-attempted functions <= 256B | 8 | 3 |
| reconstruction of never-attempted functions > 256B | 12 | 0 |
| reconstruction, file-local siblings, 10 parallel lanes (wave 5) | ~40 | 12 |
| reconstruction, file-local siblings, 10 parallel lanes (wave 6) | ~40 | 5 |
| reconstruction, file-local siblings, 10 parallel lanes (wave 7) | ~50 | 7 |
| reconstruction, file-local siblings, 10 parallel lanes (wave 8) | ~37 | 2 |

### Reconstruction is the only avenue that still pays

Every row above except the first two is residual-polishing: take a body that is
already close and hunt for the source spelling that closes it. Pooled, that is
**1 closure in ~175 hand lanes, 0.6%**. The first reconstruction wave closed
**3 of 13, 23%**. The difference is not luck, it is which defect is being
attacked: polishing can only fix a register or scheduling choice, and most
remaining functions are wrong because their C is missing logic.

Two census errors had hidden this, and both are easy to repeat:

  * **The `code1_0041..0052` and `code2_0070` families are vendor address
    spans** (CRI, the Sony SDK, the C runtime), excluded by
    `verify.is_vendor_address`. They are full of tempting 16-byte accessors and
    tail-call thunks, and closing every one of them would not move the metric
    by a single function. Filter with `is_third_party` AND `is_vendor_address`,
    never by path prefix alone.
  * **Lanes never agreed on an archive filename.** `*_body.c` and
    `*_body.c.txt` are the common forms, but the tree also holds
    `WT17_004140F0.c`, `WLFcl_004555d0_base.c` and others. 137 still-unmatched
    functions carry an attempt recorded under a name the `_body` globs miss,
    and every one was being handed to lanes as "never attempted" -- a wave-4
    lane spent most of its run rediscovering three of them. The rule that
    works is: any `.c`/`.txt` under `build/` whose NAME encodes an address and
    whose CONTENT looks like C. The content test is load-bearing; matching on
    the name alone sweeps in probe drivers, disassembly dumps and scope
    reports and overstates the attempted population badly.

With all three corrected there are **1061 never-attempted first-party
functions**, and the tractable end of that distribution is all but gone:
**0 at a window of 128 bytes or less, 7 at 256 or less**, 56 at 400 or less.
`tools/recon_pool.py --pool fresh` regenerates the list and is the authority;
do not recount it by hand. This number has now been wrong three times in one
session -- 2274, then 1186, then 1061 -- always in the optimistic direction,
and always because the archive-discovery rule was too narrow.

### The 256-byte cliff, and what it leaves to work on

A second wave ran the same method against larger never-attempted functions and
closed **nothing in 16 attempts**. Pooling both waves by retail window size
separates the two results completely:

| window | attempted | matched |
|---|---|---|
| <= 256 B | 8 | 3 |
| 257-400 B | 6 | 0 |
| > 400 B | 6 | 0 |

Every match came from a window of 256 bytes or less. Nothing above it closed.
Cold reconstruction works, but only at a size where the whole function can be
held in one piece; past that the reconstruction is right in outline and wrong
in a dozen small ways at once, and the residual is not attackable.

Wave 4 tested that reading directly: 19 never-attempted targets, every one
under the cliff, four lanes, **0 matches**. So the cliff is real but it is not
sufficient -- being small is necessary for a match, not enough for one. Across
four waves the record is 3 matches in 62 attempts, and all three came from
wave 1.

And the supply below the cliff is now essentially gone: **7 never-attempted
first-party functions at 256 bytes or less, none at all under 128**
(`tools/recon_pool.py --pool fresh --max-window 256`).

### Wave 5 breaks the cliff: parallel lanes at 432-656 bytes, +11

A fifth wave dispatched 10 parallel lanes against `build/recon_queue.json`
(never-attempted functions, size-ascending, filtered to `abs(object -
window) <= 8` to exclude the metric-trap stubs) each restricted to one file.
Each lane was told to re-derive the C from a fresh Ghidra decompile of the
retail function plus its surrounding matched siblings, not to permute an
existing near-miss. Result: **11 of ~40 attempted closed to MATCH**, sizes
432-656 bytes (`func_0018bc20`, `func_0037ed90`, `func_00197d70`,
`func_0037bac0`, `func_0015a350`, `func_001efd50`, `func_00370410`,
`func_001eff50`, `func_00370a80`, `func_001bb9b0`, `func_004669d0`), plus a
twelfth (`func_0036aa20`, 432B) reconstructed by hand ahead of the wave.
**The 256-byte cliff from waves 2-4 does not hold at this file selection**:
every wave-5 target had at least one already-MATCH sibling in the same file
within a few hundred bytes, giving the lane a same-unit struct-layout and
calling-convention anchor that isolated cold targets in wave 4 did not have.
Read the file's existing matched functions before reconstructing a new one;
that context, not size alone, is what predicts a close.

Two of the wave's candidate closures were reverted after the fact for using
banned compiler-steering idioms to force the match (`decomp_lint` H001/H009):
see the "Where `volatile` is actually required" section below and the H009
entry in the pragma-knob section. Net after reverting both: **+11, not
+13**. A lane under schedule pressure will reach for `volatile` or inline
asm before it reaches for re-deriving the logic; the fix is to lint every
lane-touched file before trusting a MATCH claim, not to trust the verify
status alone.

**Waves 6-8 confirm the method but show declining yield as the easy files
run out**: 5 of ~40, 7 of ~50, 2 of ~37 (wave 8's files had fewer already-MATCH
siblings per never-attempted target than the earlier batches -- the
file-local-sibling predictor holding in the other direction too). Running
total after wave 8: **26 closed across 4 waves and ~170 attempts, 15.3%
pooled yield**, against 0.6% for every residual-polishing avenue combined.
Two more process failures were caught by independent post-wave verification
and fixed before committing: a lane silently dropping a `// FUN_xxxxxxxx`
marker comment during an unrelated cut/paste (wave 7 -- caught only by
diffing the full-project scanned-function COUNT, not by any MISMATCH/error
signal), and a lane leaving 3 live MISMATCH bodies behind at report time
(wave 6, `k_fldFrame.c`). Neither is optional to check: run a full
`tools/verify.py` and confirm both the MATCH set and the total scanned count
against the pre-wave baseline before ever committing lane output.

### The recon-queue-rebuild bug, and what full exhaustion looks like

A later continuation of this campaign (waves 22-32, +66 net first-party
matches, 6153 -> 6219) had stalled for many prior waves at 0 closures each
before the actual defect was found: the target-list builder was filtering
out any FILE that had ever been "touched" by an earlier lane, not just the
individual functions that had actually been attempted in it. Since most
files in this tree accumulate matches incrementally over many sessions,
almost every file looked "touched" and got excluded wholesale, even when it
still held several genuinely never-attempted functions. The fix: rebuild the
target list every wave from the FULL `build/recon_queue.json`, filtered only
by a cumulative set of individually-attempted function NAMES (tracked
wave-over-wave, e.g. in a scratch file), never by whole-file exclusion. This
single change turned a run of stalled waves back into 4-19 closures each
until the pool ran out.

**The pool does run out, and it is worth recognizing when it has.** By wave
29 the rebuilt target list was down to single-digit functions per file; by
wave 31 `build/recon_queue.json` had exactly 10 first-party entries left
that were not already individually attempted, and every one of those 10 was
a documented hardware floor (the fromSPR/toSPR DMA family in `code1_003a.c`,
`sdkUttmx.c`'s `func_00463ea0`, `code1_0016.c`'s `func_0016bdd0`). At that
point `recon_queue.json`'s never-attempted-function avenue is exhausted, not
merely thinned, and continuing to rebuild-and-redispatch against it wastes a
wave discovering the same empty result.

**The natural next avenue -- mining source comments for a small recorded
`nd`/`normalized_diff` next to a still-`INCLUDE_ASM` marker -- pays far less
than it looks like it should, for the same reason `tools/recon_pool.py
--measure` already warns about staleness above.** A tight regex scan (marker
immediately followed by `INCLUDE_ASM`, only trusting an `nd`/`normalized_diff`
mention that also names the target's own hex address, filtered against the
VENDOR_CODE_RANGES + THIRD_PARTY_PREFIXES first-party set from a real
`tools/verify.py --json` run rather than a bare `glob` over `src/**/*.c`)
found only 12 candidates at `nd <= 10` out of 1647 true first-party ASM
functions. Dispatching lanes at 5 of them (the clearest, most literally
worded) closed zero: two were confirmed ee-gcc2.96-vs-3.2 compiler-version
floors in a *vendor* translation unit that should never have been in the
candidate pool at all (the regex had matched a comment inside
`code1_004f.c`, one of the five files in `config/gcc_units.txt` --
`tools/verify.py`'s own `is_gcc_unit`/`is_third_party`/`is_vendor_address`
filters exclude these from the first-party count, but a naive `glob` +
text-scan does not know that), and the other three reconfirmed already-
documented floors (an argument-evaluation-order floor, a padding-tail floor,
and a compiler-width floor) with no new lever found. Re-checking the
remaining 7 candidates by hand found every one was either a *misattributed*
comment (the `nd`/`normalized_diff` text belonged to an adjacent function's
bracket-close rationale, not the marked target -- `func_00267800`,
`func_003e4520`/`func_003e45f0`, `func_001f1030` all read this way) or an
explicitly pre-flagged false positive already recorded in-tree
(`y_draw.c`'s `func_002b6ec0`: "fndiff of the INCLUDE_ASM state reads nd 0 by
construction... do not treat this function as matched", dated 2026-08-03).
**Conclusion: at this point in the campaign, both the never-attempted-
function avenue and the naive near-miss-comment-mining avenue are measured
exhausted.** What is left is either a genuine hardware floor, an
already-exhaustively-probed register/scheduling floor with the probe history
recorded in place, or requires the same kind of from-scratch disassembly
re-derivation described in "Reconstruction is the only avenue that still
pays" above -- applied one function at a time, not by batch dispatch against
a generated list.

**A live example of the H001 volatile trap from "Two ways this pool lies to
you" recurring in this later continuation:** a lane closed `code1_0039.c`'s
`func_00399bf0` to a clean-looking MATCH (nd 0, scoped verify green, a
`measured:` comment attached) using `volatile` on an ordinary allocator
struct field (`p + 0x80`, a heap object this same function allocates, not a
hardware address) to force a post-store reload. `decomp_lint`'s textual
waiver check does not distinguish a genuinely justified hardware `volatile`
from a `measured:`-commented one on ordinary data -- exactly the
"FUNCTION-scope waiver licenses a banned construct" trap documented above --
so this passed decomp_lint clean and reported MATCH under scoped verify. It
was caught only by reading the diff for `volatile` by eye per the existing
rule and reverted, with the comment rewritten to document the real
(unresolved) floor and to correct a genuinely misattributed nd44->36->18
probe history that a much earlier session had pasted onto the wrong marker
(it describes the unrelated `00399fd0`/`0039a200` slot-search family; retail
`00399bf0` is an allocator/state-switch routine with no loop at all).

**The other pool is the archived near-misses**, 113 functions still
`INCLUDE_ASM` carrying an archived body with a claimed `0 < nd <= 25` inside a
400-byte window. `tools/recon_pool.py` (default `--pool nearmiss`) regenerates
it, and `--measure` is mandatory before acting on it, for the reason in the
next section. Measured, only about six are genuinely close: nd 1, 1, 4, 4, 5,
and the rest of the top of the list turns out to be nd 30+.

The obvious objection is that "archive near-miss tail, hand lanes" is already a
measured zero in the table above. The distinction is method, and wave 1 proved
it on exactly this kind of target: `func_0028b6b0` had been parked at nd 8 by
an earlier lane and every spelling permutation had failed on it. It closed only
when the logic was re-derived from the retail disassembly, which showed the
doubled `beqz` came from nested ifs and the body-head order came from a table
local. So the pool is not exhausted -- the *permutation* of it is. Re-derive
the logic; do not permute the spelling.

### Where `volatile` is actually required

`volatile` is banned as compiler-steering and required for a real device
access, and that split is only decidable from the retail code.
`tools/hw_access_census.py` decides it: it reads the retail bytes of every
first-party function still on `INCLUDE_ASM` and reports the ones that
dereference a hardware address. **21 functions do.** Three families:

  * **fromSPR/toSPR DMA, 18 functions.** `0x1000D000` `D_CHCR`, `D010` `D_MADR`,
    `D020` `D_QWC`, `D080` `D_SADR`, `0x1000D400` toSPR, `0x1000E010` `D_STAT`,
    paired with scratchpad at `0x70000000`. All of `code1_003a.c`'s and
    `code1_003b.c`'s big transfer routines, plus `sdkUttmx.c`'s
    `func_00463ea0`.
  * **Timer 0 init, 1 function.** `func_00100350` writes `T0_COUNT`, `T0_MODE`,
    `T0_COMP`, `T0_HOLD` at `0x10000000/10/20/30`.
  * **Direct scratchpad, 2 functions.** `func_0016bdd0` and `func_00174e10`
    read `0xBF800004`.

None is under the 256-byte cliff -- the smallest is 608 bytes -- so none is a
near-term target. The point is that when they are attempted, `volatile` there
is correct and must not be argued away.

Two traps the census had to be taught, both of which produced confident wrong
answers first:

  * **Segment masking is mandatory.** EE code reaches devices through KSEG1, so
    the fromSPR channel appears as `lui 0xB000` / `ori 0xD000`. A scan looking
    for literal `0x1000xxxx` finds almost nothing real.
  * **A constant in a register is not an access.** `func_0039c730` looked like
    an `sq` to `0x10000000` and is not: a `lui v0,0x1000` fed an `or` building
    a GIF tag word, then `lw v0,-0x477c(gp)` reloaded `v0` as a packet pointer
    while the scan still credited it the stale upper half. Only a load or store
    whose *base* register holds the address counts. Requiring a real
    dereference cut 34 candidate functions to 21.

And one collision worth knowing in both directions: **`0xBF800000` is `-1.0f`**
as well as the KSEG1 mirror of the scratchpad base. Retail's `func_001774a0`
does `lui v0,0xbf80; mtc1 v0,f1`, which is the float. `decomp_lint` now masks
KSEG0/KSEG1 before its hardware-range test -- without that it rejects genuine
`0xBF800004` scratchpad accesses as H001 -- but it excludes `0xBF800000` and
`0x3F800000` from the mask, because otherwise any line mentioning +/-1.0f
would earn a free `volatile` waiver.

### The fromSPR/toSPR family's real blocker was a missing allowlist entry, not size

Revisited the 21-function hardware census above after wave 12: six of the
18 fromSPR/toSPR functions live in `code1_003a.c` (`func_003a4d50` 1072B,
`func_003a7a30` 1360B, `func_003acb10`/`func_003adc40`/`func_003af990`
~4.4-4.6KB, `func_003aed60` 3120B). Their retail bytes use a hardware
primitive `decomp_lint.py`'s `ASM_ALLOWED` did not know about:
**`bc0f`** (branch on the COP0 condition line). The EE's DMAC channel-drain
arbitration signal is wired into COP0's condition input and is *only*
readable via `bc0f`/`bc0t` -- there is no `mfc0` for it, so unlike
`mfc0 Status` this one genuinely has zero C expression. Added both to the
allowlist (`tools/decomp_lint.py`).

Confirmed empirically via `build/RECON_probe.py` (full round-trip through
`tools/verify.py`, so a real MWCCPS2 compile, not a guess) that b210 accepts
the literal mnemonics `sync.l`, `sync.p`, and `bc0f 1b` inside
`__asm__ volatile(".set noreorder\n" ... ".set reorder" ::: "memory")` --
COMPILE_ERROR would have shown immediately if the spelling were wrong; it
compiled (MISMATCH, as expected for a one-line stub against a 1072-byte
window).

The idiom, read off `func_003a4d50`'s disassembly: writing global register
`D_PCR` (`0x1000E020`) arms a stall-control drain condition; the wait is
`sync.l; sync.p; nop*5; 1: bc0f 1b; nop`. Separately, per-channel busy is an
*ordinary* `volatile` poll -- `while ((*(vu32*)D9_CHCR & 0x100) != 0) {}` --
no asm needed there. Global DMAC register map recovered from the offsets
(`D_CTRL/STAT/PCR/SQWC/RBSR/RBOR/STADR` at `0x1000E000` + 0x10 each) matches
the known SCE map exactly, as do the per-channel bases (`0x1000D000` chan 8
fromSPR, `0x1000D400` chan 9 toSPR, `+0x00 CHCR/+0x10 MADR/+0x20 QWC/+0x80
SADR`), both already partly attested by the existing `0x1000C000`/`0x1000E010`
reads in `code1_0042.c`.

**Attempted, still not closed.** `func_003a4d50`'s retail control flow is
hand-scheduled with backward cross-jumps between wait/poll blocks: every
busy-check is a `bnez` branching *forward into* a cold wait-block placed
after the main body (not a fallthrough `if`), and each wait-block ends
with an unconditional `goto` back into the middle of the main flow --
confirmed by manual disassembly of the full 268-instruction body (there is
no `jal` to a shared subroutine anywhere in it). A goto-per-basic-block C
reconstruction was written mirroring this exactly (14 labels, matched
register mapping `arg0`=dest/`arg1`=src confirmed independently via the
`func_0043f810(dst,src,size)` tail-call argument order, `tail = arg2 - qwc
* 16` confirmed against retail's `subu` rather than `arg2 % 16`'s `andi`
codegen) and reached `MATCH19/MISMATCH1`, object 1136B against a 1072B
window -- *larger* than retail, meaning MWCC duplicated at least one small
block (most likely the `tail_check` label, `goto`'d from three sites) that
a straight assembly source would have shared once. Reverted to bare
`INCLUDE_ASM` per policy. The next attempt should either restructure to
remove the triple-entry label (duplicate the tiny body at each site
explicitly, matching whatever the compiler's own duplication threshold
is) or accept the duplication and instead match its *content* exactly.
Left as a queued, fully-scoped lane target rather than hand-carried to
MATCH in this session: the size (1072-4592 bytes) and control-flow
complexity make it an expensive single function, while the 920-function
never-attempted backlog (see wave 11/12 above) has a much better
match-per-hour rate for lanes right now.

**External precedent confirms the goto approach, not the shape I used.**
`AshfordFamily/recvx-decomp` (Resident Evil Code: Veronica X, confirmed
MWCCPS2 toolchain via its `compile_config.json` pointing at `mwccps2.exe`,
64% matched) has the identical `bc0f`/`bc0t` DMA-wait idiom, marked `// 100%
matching!`, e.g. `ps2_loadtim2.c`'s `D2_SyncTag()`:
```c
if ((DGET_D_PCR() & 0x4))
{
    asm volatile (bc0t label_0f);
label_0b:
    asm volatile { bc0f label_0b; nop }
}
label_0f:
    DPUT_D_PCR(DGET_D_PCR() | tmp);
```
Two things this confirms: (1) MWCC really does let inline-asm `bc0t`/`bc0f`
branch to plain C statement labels, including labels *outside* the
enclosing block -- the goto-shaped technique from the attempt above is the
right one, not a wrong turn; (2) their idiom pairs `bc0t` (skip the wait
entirely if the condition is already true) with `bc0f` (spin while false),
a "check once, then loop" shape -- `func_003a4d50` uses only `bc0f` (no
`bc0t` anywhere in its 268 instructions), so its wait is the simpler
unconditional-entry variant, consistent with the disassembly, not a
contradiction. The same repository's inline-asm-only handling of
`movz`/`movn` (whole functions in raw `asm volatile` blocks, e.g.
`ps2_NaMath.c`) and `pextlw`/`pextlh`/`pcpyld`/`pcpyud` (targeted asm
snippets, e.g. `ps2_NaMatrix.c`, `ps2_Vu1Strip.c`) independently confirms
both floors this campaign already found on its own (movz/movn census
above; the `effPolygonFlash.c` pextlb/pextlh floor wave 15 hit) -- a
second unrelated MWCCPS2 project reached the same walls.

Next attempt at `func_003a4d50` should retry the goto structure with the
check-once-then-loop pairing where retail actually pairs `bc0t`+`bc0f`
(none of its eight wait sites do, per the disassembly, but re-verify per
site) and fix the block-duplication bug from the reverted attempt (the
`tail_check` label reached via three `goto`s) before assuming the
technique itself is wrong.

### Is the rest just C we have not shaped?

Almost entirely, yes -- and that is measurable rather than a matter of faith.
`tools/reachability_census.py` counts each unusual instruction class over
MATCHED and over unmatched first-party functions. The matched column is the
control: a matched function is proof by construction that b210 emits that
instruction from plain C *in this tree*.

| class | in matched | in unmatched | verdict |
|---|---|---|---|
| COP2 (VU0 macro mode) | 45 | 62 | reachable from C |
| MMI (EE multimedia) | 43 | 95 | reachable from C |
| lqc2/sqc2 (VU0 quadword) | 38 | 67 | reachable from C |
| COP0 (mfc0/mtc0/tlb/eret) | 3 | 29 | reachable from C |
| sync | 3 | 29 | reachable from C |
| syscall | 1 | 1 | reachable from C |
| **movz/movn** | **0** | **31** | **never matched** |

So the recurring "VU0 floor" belief is false here: 45 functions we already
match contain COP2 macro-mode instructions. Same for MMI and the quadword
VU0 loads.

`movz`/`movn` is the single exception, and two independent lines of evidence
agree. It appears in zero of 6104 matched functions; and compiling ten
conditional-select idioms -- ternary, if-assign, inverted, `== 0`, named
temporary, unsigned, pointer-indexed, select-or-zero, zero-or-select, float
-- at `-O0/-O1/-O2/-O3/-O4`, with `-inline all`, `-opt speed` and `-opt space`,
produces **no `movz` or `movn` in `.text` at any setting**. Retail's uses of it
therefore did not come from C through this compiler; inline asm in the
original source or an SDK macro is the likely origin.

Beware the obvious way to get this wrong: scanning a whole `.o` for the
opcode pattern reports a confident 14 hits at every optimisation level,
because relocation entries and the symbol table contain matching bytes. Scan
`SHF_EXECINSTR` sections only.

**31 of the 1762 remaining functions contain movz/movn, and 29 have it as
their only unusual content.** The other 1731 -- 98% -- contain nothing that
has not already been produced from C elsewhere in this tree.

That is the honest answer to "is the rest just C we have not shaped yet":
the language is not the obstacle. But "just shaping" understates the
obstacle considerably. This session shaped 43 functions and matched 3. The
work that remains is C-shaped and mostly reachable in principle; what is
scarce is the ability to find the exact shape, and above 256 bytes we have
not found one yet.

### Two ways this pool lies to you

**The nd in an archive note is a claim, not a measurement.** Notes are written
by hand as a lane ends and they go stale as the tree moves. `func_003bcf10` and
`func_003bcfb0` are both recorded at nd 2 and both measure **nd 32** when their
archived bodies are installed today; `func_003b6da0` is recorded at nd 6 and
measures **55**; several archives no longer compile at all. Some quoted `nd 0`
values are worse than stale -- they came from an `INCLUDE_ASM` self-compare
rather than from any compiled body. Rank with `tools/recon_pool.py --measure`,
which installs each archived body, scores it, and restores the file. It costs
about two seconds per target. The claimed and measured columns agreed for six
of the top nine and were wildly wrong for the other three.

**A `measured:` note above a marker waives H001 for the whole function.**
`decomp_lint`'s waiver has FUNCTION scope: a justification in the six lines
above a `// FUN_` marker covers every occurrence of a banned construct inside
that function. So a note written to justify a *pragma* silently licenses a
banned `volatile` in the same body. That is how a wave-3 lane landed a
"MATCH" on `func_0045ed60` that reached nd 0 only by casting a plain `void *`
parameter to `volatile u8 *` to defeat b210's CSE and force retail's twelve
repeated byte loads -- compiler-steering of exactly the kind this campaign
bans alongside inline asm. It was reverted and archived as
`build/NMX_0045ed60_body_REJECTED.c`.

Note also that H001's regex looks for the token `volatile`, and the lane's
construct was a volatile CAST EXPRESSION rather than a declaration; between the
cast form and the function-scope waiver it drew no finding at all. When a lane
reports a match, check its diff for `volatile` by eye rather than trusting a
clean lint run, and require volatile to be justified at the site.

Before rejecting that body I checked whether retail's repeated loads could be
honest aliasing, which would make a legitimate shape possible. They cannot: a
direct `u8 *` cast, a local `u8 *`, a `char *` source, and stores through the
destination local all let b210 collapse the three load groups into one, scoring
nd 59-66 and losing about 44 bytes of object.

### Abandon on measured nd, not on iteration count

The first reconstruction wave spent roughly half its compute on six targets
that finished at nd 42, 51, 71, 107, 144 and 309 -- three of them absorbed 25
to 35 probe variants each. The instruction that failed was "time-box each
function to about a dozen iterations": an iteration count is estimated loosely
and every lane overshot it two- to threefold.

The rule that works is keyed to a measurement. Get one candidate whose
`object_size` is within ~8 bytes of `window`, then read its `normalized_diff`:

  * **nd > 25** -- archive immediately. At that distance the defect is missing
    or wrong logic, and no source spelling closes it. More variants are waste.
  * **nd <= 25** -- worth a probe budget, capped at 12 variants.

On the first wave this rule would have cut about half the runtime at zero cost
in matches.

### Two b210 levers measured during the wave

  * Retail's **doubled `beqz`** comes from **nested `if`s**. b210 CSEs an `&&`
    chain into a single test but does not collapse nested ifs, so the two
    shapes are distinguishable in the object.
  * A **table local declared at the loop-body head** forces retail's
    `sll`-before-`lw` body-head instruction order.

### Reading EE FPU multiply-accumulate out of rabbitizer

rabbitizer does not know the EE's multiply-accumulate opcodes and prints them
as `.word 0x46...` tagged INVALID. Two lanes each burned an hour rediscovering
how to read them, so the rules are recorded here.

  * **In those INVALID words rabbitizer prints float registers using INTEGER
    register names.** `$a2` means `$f6`, and so on by register number. This is
    the detail that wastes the hour.
  * Function field, bits 5-0: `0x18` ADDA.S, `0x19` SUBA.S, `0x1A` MULA.S,
    `0x1C` MADD.S, `0x1D` MSUB.S, `0x1E` MADDA.S, `0x1F` MSUBA.S.
  * Accumulator semantics: `mula`/`adda`/`suba` SET the accumulator and their
    `fd` field is unused; `madd`/`msub` write `fd` from the accumulator
    combined with the product; `madda`/`msuba` accumulate into it.

All of these come from ordinary C float expressions such as `a*a + b*b + c*c`;
none of them justifies inline asm. When b210 compiles such a sum it starts the
accumulator with the SECOND addend, which is why a literal left-to-right
transcription of the retail order does not reproduce it.

### The command-line flag axis, and why a per-UNIT sweep cannot test it

Every verify in this tree compiles with exactly `-O2 -Iinclude`, and that
baseline had never been questioned. `build/flag_sweep.py` sweeps 15 flag sets
per translation unit; `build/flag_sweep_bodies.py` sweeps them per archived
body. Both are committed because the negative needs to stay re-derivable.

Three things came out of it, in order of importance:

- **A per-unit sweep is structurally incapable of finding anything.** An
  unmatched function is an `INCLUDE_ASM` line, so it never reaches the
  compiler; no switch can change bytes that are pasted from retail. The only
  functions a unit-level sweep can move are ones that already MATCH, and there
  a change is a regression. Measured: `btlShuffle.c` keeps 21/21 under every
  neutral flag set, loses 6 at `-O1` and all 21 at `-O3`/`-O4`. That also
  confirms `-O2` is right, and that the flags do reach the compiler.
- **In pragma-heavy units the sweep reads as a flat line** because file-scope
  `#pragma optimization_level` overrides `-O`: `code1_003e.c` (55 such pragmas)
  reports an identical 73 MATCH at `-O1`, `-O2`, `-O3` and `-O4`. Do not read
  that as insensitivity.
- **Per-body, one flag set moved a residual materially**: `func_00311930`
  (`code1_0031`) goes from nd 48 to nd 6 under `-O1` — but its archive already
  documents that exact result under a function-scoped `optimization_level 1`
  bracket, with five residual words confined to FPU destination-register
  choice. The sweep rediscovered a known floor rather than opening one.

One caveat the sweeper cannot fix: `normalized_diff` rewards a SMALLER object,
so a body that compiles to an 8-byte stub against a 1120-byte window scores
better than a real attempt. Two apparent `-O3` wins (`func_001dbf20`,
`func_004667d0`) were exactly this. Always read `object` against `window`
before believing an nd improvement.

### The remaining work is not a toolchain problem

`build/prologue_census.py` applies `config/gcc_units.txt`'s own discriminator —
retail saves callee-saved registers with `sd` under ee-gcc and `sq` under
MWCCPS2 — to every FUNCTION rather than per translation unit, straight from
`image.bin` with no build required. The result settles a question the campaign
had never actually measured:

| verify status | prologue | count |
|---|---|---|
| MATCH | mwcc | 3281 |
| MATCH | leaf (saves nothing) | 2820 |
| ASM | mwcc | 1539 |
| ASM | leaf | 226 |
| **ASM** | **gcc** | **0** |

**Zero** unmatched first-party functions have a GCC prologue. Every one of them
was built by b210 and is therefore reachable in principle with the compiler in
use; nothing is waiting on an ee-gcc split. (The `code1_0041`/`code1_0044` GCC
populations noted in `config/gcc_units.txt` are all above 0x00417510, i.e.
inside the vendor ranges, and score nothing either way.)

That census also isolated the 226 unmatched LEAF functions — no saved registers
at all, so structurally incapable of carrying the saved-register colouring or
rotation residual that walls most of the corpus. 82 had never been archived,
and a 16-lane wave over the 20 smallest closed **zero**. Their residuals were
COP1 accumulator chains (`003e3f00`, `003e4030`, `003963c0`, `00396520`), or
ordinary word-level walls at nd 12-64 on functions of 80-368 bytes. Leaf-ness
does not predict closure either.

### CORRECTION: COP1 accumulator chains ARE emitted by plain C

Several lanes have abandoned targets on the belief that an `adda.s`/`madd.s`/
`msub.s` chain cannot be produced from compliant C. **That is wrong**, and it
was measured directly against b210 at `-O2`:

```c
float c_plain(float acc, int count) { return acc - (float)count * 9.5f; }
```

```
  1c:  460c0018   adda.s  $f0,$f12
  20:  4601101d   msub.s  $f0,$f2,$f1
```

No pragma, no intrinsic, no `+ 0.0f` trick — an ordinary multiply-and-subtract
expression fuses. The `+` form gives `adda.s`/`madd.s`, and a three-operand
`(x + 0.0f) + y * z` fuses as well. b210 forms the accumulator chain whenever a
float multiply feeds an add or subtract.

So when the retail window contains one of these, **do not stop**: write the
arithmetic naturally and the chain appears. What actually walls these functions
is the surrounding code — operand orientation (see the commutative floor),
saved-register colouring, and load scheduling — not the fused instruction.

Where a chain genuinely is unreachable it is because of *which* registers the
accumulator reads, not because the instruction cannot be emitted. Treat
"contains adda.s" as a normal target from now on.

**Confirmed by eight independent reconstructions.** A wave was run against the
reopened pool specifically to test this, and every single lane reproduced the
retail accumulator chain from ordinary C — 4 ops (`func_0035bad0`), 6
(`func_0011c780`), 6 (`func_0026bfc0`), 3 (`func_0047f4d0`), the full
`MULA`/`MSUB`/`MADD` sequence (`func_00208870`), `madd.s` (`func_001bb790`),
the tail chain (`func_004b7300`), and — decisively — **all 25** ops of
`func_00480f20`, the densest accumulator function in the corpus. Not one lane
needed a pragma, an intrinsic or inline asm to emit the chain, and not one
found the chain itself to be the residual. Two closed outright
(`func_004b7300`, `func_0026bfc0`); the rest walled on ordinary causes:
commutative MAC operand order (`madd.s $f0,$f0,$f2` vs retail `$f0,$f2,$f0`),
FPR colouring, and load scheduling.

A scan of the unmatched first-party set found **308 functions containing an
accumulator chain**. Rebuild that list with `insn.itype` in `0x13e..0x144`;
matching on the mnemonic string finds nothing, which is how the pool stayed
invisible. Those 308 are all ordinary targets and are the largest single block
of work reopened this session.

### The reverse case: retail has a plain `add.s` after `mul.s` (no fusion)

When retail shows `mul.s $f1 ... ; mtc1 const,$f0 ; add.s $fd,$f0,$f1` where
plain C would fuse into `adda.s`/`madd.s`, the lever is a copy through a
named local between the product and the add - measured on `func_002b2290`
(y_smap.c, nd 409 -> 0):
```c
t = 108.0f * (f32)j;
y = t;                /* the copy is what blocks the c + a*b fusion */
z = -99.0f + y;       /* fresh name z: constant-first add.s $f20,$f0,$f1 */
```
`y = -99.0f + t` (no copy) fuses; `y = t; y = -99.0f + y` (self-update) is
unfused but variable-first (`add.s $f20,$f1,$f0`, nd 1); `y = t; t = y + c`
coalesces back to the self-update. `opt_propagation off` also unfuses the
plain `y = -99.0f + t` form, but in that function it changed the loop-head
sign-extension sharing and let `opt_loop_invariants` hoist every float
constant, so the copy is the cheaper lever. Doubles are real software
doubles on b210 (`-99.0 + 108.0 * j` grows the object by 60B) - not a way
to dodge fusion.

### Near-size twins are a shape family, not a twin

That row retires an idea worth recording so it is not retried. The exact
twin join demands IDENTICAL window sizes; relaxing it to +/-4 instructions and
scoring masked-instruction alignment finds 57 pairs at ratio >= 0.80, of which
26 are new. They are almost all FALSE POSITIVES: at that tolerance the score
matches a shape FAMILY — the same compiler emitting the same idiom over the
same struct — not the same source function. Lanes reported it directly: the
`func_001a0f40` donor is a 200-byte function against a 448-byte window, the
`func_0047ce00` donor uses a different dispatch (jump table versus chain), and
the `func_001bfc00` donor relies on P3-only `RtQuat` and extended `BtlUnit`
fields. The strictness of the size constraint was doing real work; a twin is
only a twin at ratio 1.000 with equal windows.

The dense-unit row is the other one that changed this week. Fresh functions in
dense units
used to be the reliable seam — it is how most of the campaign was built — and it
has now stopped producing at 16 lanes per wave. What those lanes found is
consistent: the remaining never-attempted functions are large (median window
near 400 bytes, several over 2 KB), and their residuals land on the SAME walls
the ground corpus sits on. `func_00250ad0` (2720 B, the only gap in a 98% unit)
reduces to COP1 `adda.s`/`madd.s` accumulator chains; `func_0036d3e0` (1152 B,
the only gap in a 97% unit) reduces to a callee-saved register rotation at
nd 51; `func_00177120` and `func_001774a0` do NOT respond to the exhaustive
empty-case hypothesis (nd 75 and 348 differing words with cases 2 and 4-9 added
explicitly, so that idea is now retired).

What is left therefore needs one of: a genuinely new source lever, a donor tree
we do not have, or acceptance that a large share of these are compiler floors
under b210. Ranking by window size or by unit density no longer predicts
closure.

## The permuter is seed-limited, not exhausted — and the AST engine works now

An earlier sweep concluded the permuter was spent. That conclusion was about the
SEED POPULATION, not the tool. Re-seeding it after the archive-note fix produced
eight closures across seven sweeps, all in functions no hand wave had ever
ground:

| sweep | seeds | engine | budget | cracked |
|---|---|---|---|---|
| all first-party archives that compile | 461 | text | 200s x 20 | **3** (`003ca430`, `001ee490`, `002e6b20`) |
| the 93 seeds text scored 1-30 | 93 | ast | 300s x 16 | **2** (`00296600`, `0027d800`) |
| the 365 seeds text scored >30 | 365 | ast | 240s x 18 | 0 |
| `src/generated` m2c candidates | 506 | ast | 200s x 18 | 0, and 0 SCORED — pycparser cannot construct them |
| the same m2c candidates | 506 | text | 200s x 20 | 0, 56 scored |
| the 41 seeds text scored 1-12 | 41 | ast | **1200s** x 16 | **1** (`0045aac0`) |
| the 62 seeds text scored 13-40 | 62 | ast | **1200s** x 16 | **2** (`0032b770`, `0011bf10`) |
| the 110 seeds text scored 41-120 | 110 | ast | 1200s x 16 | 0 |

Four things follow, each measured:

- **The AST engine had never actually run here.** It needs `pycparser` and
  `toml`; neither was installed, and both are invisible under
  `PYTHONNOUSERSITE=1`. Install them and run that engine with the variable
  UNSET. It restructures code where the text engine only reorders, which is why
  it cracked `func_00296600` after four hand waves had stalled it at nd 8.
- **Its reach is the low-score tail, and AST budget keeps paying inside it.**
  Zero hits from 365 seeds scored above 30 at 240s, and zero from 110 seeds
  scored 41-120 even at 1200s — but raising the budget to 1200s inside the
  1-40 band produced three more cracks that 200-300s had missed, including
  `func_0045aac0`, which had a header full of exhausted hand probes, and
  `func_0032b770`, a P3 twin port stalled at nd 16. Budget the AST engine
  generously on scores <= 40 and never above it. (Text-engine budget, by
  contrast, was measured to buy nothing.)
- **The m2c seed corpus is closed, and it took a tool fix to prove it.**
  `generated_bodies()` used to prepend the `M2C_` typedef/`#define` prelude to
  the BODY, so an activated seed put typedefs on the line after its `// FUN_`
  marker. `permute.scan_markers` names a marker from the line below it, so the
  marker stayed nameless and every run died with "no `// FUN_` marker for
  func_xxxxxxxx" — silently, as a harness error rather than a compile failure.
  447 of the first-party generated seeds were unusable for that reason alone.
  Hoisting the prelude into the NOTE (above the marker; it is pure text
  substitution, so it cannot change a byte) took the usable first-party seed
  count from 503 to 531 and the SCORED population from 56 to 206. Both engines
  were then run over the unlocked corpus: text at 180s over all 531 cracked
  **zero**, and AST at 1200s over the 26 that scored 1-40 cracked **zero**.
  Seven `match` rows in the classification are all vendor addresses and score
  nothing for the metric. Archives are the seed corpus; m2c candidates are not,
  and this is now measured rather than assumed.
  Hand lanes then attacked the same corpus: 16 lanes over the 16 best-scoring
  m2c near-misses (scores 5-48, several of them EXACT SIZE) closed **zero**.
  So the m2c bodies are not a starting point for hand work either — their
  residuals are the same register-colouring and branch-layout walls the
  archives already sit on, reached from a different direction. What an m2c
  seed IS good for is a measurement and a block map, not a candidate.
- **Re-sweep after anything that makes new archives measurable.** Every crack
  this session came from bodies that had just become visible.

Splice trap, measured: `permute_sweep.splice` replaces marker-to-first-closing-
brace. A target that is still a bare `INCLUDE_ASM` has no brace, so the splice
runs on and swallows the NEXT function, silently deleting markers (209 -> 207).
For those targets replace exactly the marker line plus its `INCLUDE_ASM`/guard
lines, then diff the marker SET against `jj file show -r @-` before believing
any count.

An AST hit is heavily mutated and is not committable as found: re-verify it by
splicing and scoring, then reduce with `tools/permute_min.py` and re-verify
after each round. `func_00296600` reduced from twelve permuter temporaries to
nine and stayed exact; the rest are load-bearing.

## Process

- **Disassemble before modeling any multi-call handler.** Resolve ambiguous
  arg types (`(short)` vs raw, `lhu` vs `andi`, literal-constant reuse,
  `char`/`u8` conversion, float vs int, branch polarity, `-1` width) from the
  real instruction sequence rather than trusting the decompiler.
- **Extend partial modules.** Pick a file that already has matches and harvest
  its unharvested neighbours (getters, flag-checks, cleanups, copy-loops,
  loaders, destroys). These accessors match far more reliably than update or
  render functions.
- **Grep before writing a new file.** Files are whole translation units named
  after their module or original TU; check for an existing file that already
owns your function's addresses before creating anything. A made-up file causes
duplicate definitions.
- **Record waivers per `docs/STYLE.md`** when a steering construct is
  load-bearing: annotation above the marker, containing the word `measured`
  and the measured cost of removal.

## A MATCH does not prove the right global

`tools/verify.py` masks relocations before comparing, because an unlinked
object cannot know where a symbol will land. That is correct for per-function
verification and it has one consequence worth internalising: **a function can
report MATCH while referencing the wrong symbol.** The relocated field is
masked, so any symbol of the right kind compares equal.

Only the linked image catches it. A real example, from the wave that added
`func_004a8bb0` and `func_004a8f90` to `src/Graphics/Effect/effBlurFilter.c`:
both verified MATCH at normalized_diff 0, and both were wrong. They are a
sibling cluster, solved once and transferred, and the transfer silently carried
the first function's global into the second:

    func_004a8bb0 @ 0x004a8cbc   ld $a0, -0x7fe0($gp)   fGpffff8020 = 0x00761110
    func_004a8f90 @ 0x004a909c   ld $a0, -0x7ff0($gp)   fGpffff8010 = 0x00761100

`tools/build.py` reported `first diff at vram 0x4a8cbc` and the image sha1
changed. Nothing else would have.

Practical rules:

- When you transfer a shape between cluster members, diff the retail windows for
  their GLOBAL references specifically. Constants and offsets are obvious;
  a `%hi`/`%lo` or `$gp` displacement pointing at a different datum is not.
- A newly referenced global that no existing source mentions has to be
  registered in `config/symbol_data_addrs.txt` with evidence, or the object
  quietly drops out of the link. It will not fail verification - it will just
  stop being one of the linked translation units, and the only visible symptom
  is the linked-function count falling.
- Derive a `?Gpffff####` address as `gp + (signed 16-bit offset)`, gp base
  `0x007690F0`, and confirm it against the retail instruction that references
  it rather than against the name. The name is a decompiler guess and this
  case proves it can be wrong.

## Targeting: rescan the whole tree by per-file MATCH density, not a fixed queue

A campaign that dispatches lanes only against a pre-built candidate list
(e.g. `build/recon_queue.json`, generated once early on) silently stalls once
that list is exhausted, even though hundreds of legitimately fresh, never-
attempted functions remain — the list was never the full first-party ASM
set, only a snapshot of it. The symptom is several consecutive waves closing
zero functions despite lanes reporting real effort.

The fix that turned a stalled campaign productive again: rebuild the target
list every wave directly from a **fresh full `tools/verify.py --json`
report**, not from any earlier queue file. Group every non-vendor,
non-third-party ASM function by its file, compute each file's MATCH density
(`MATCH / (MATCH + ASM)`), and dispatch lanes at the **highest-density files
first** — a file that is 80%+ MATCH already encodes the local struct
layouts, calling conventions, and GP-relative symbol set a lane needs, so a
fresh Ghidra/retail read of its handful of remaining ASM functions closes at
a much higher rate than the same functions would in isolation. Exclude the
vendor ranges (`config/target.json`'s middleware windows) and third-party
files the same way `tools/verify.py`'s first-party filter does, or the
density numbers are meaningless.

Recipe (Python, run against the latest `postWaveNN.json`):

```python
import json, collections
d = json.load(open('build/postWaveNN.json'))
VENDOR = (...)  # from config/target.json
attempted = set(open('/tmp/attempted.txt').read().split())  # cumulative
byfile = collections.defaultdict(lambda: {'MATCH': 0, 'ASM': 0, 'names': []})
for x in d['results']:
    if is_vendor(x['addr']) or is_third_party(x['file']):
        continue
    e = byfile[x['file']]
    if x['status'] == 'MATCH':
        e['MATCH'] += 1
    elif x['status'] == 'ASM':
        e['ASM'] += 1
        e['names'].append(x['name'])
candidates = sorted(
    ((e['MATCH'] / (e['MATCH'] + e['ASM']), e['ASM'], f,
      [n for n in e['names'] if n not in attempted])
     for f, e in byfile.items()),
    key=lambda c: (-c[0], c[1]))
```

Track cumulative per-function `attempted` names across waves (append after
every wave's dispatch, whether closed or not) so a re-scan does not
re-assign a function a sibling lane already spent budget on the same
session — but re-running the *file* density scan from scratch every wave is
what matters; never filter by "file already touched."

Large low-density files (a single file with 60-100+ remaining ASM
functions) still belong in this method — split the file's remaining target
list into two (or more) disjoint address-range halves and dispatch one lane
per half as siblings on the same file. Sibling lanes on a shared file MUST
coordinate over `hub` before every edit (announce the function about to be
touched) and edit one function at a time with their own scoped `lverify`
immediately after, so a crash or a bad probe from one lane never corrupts
the other's already-landed closures. When one sibling finishes before the
other, it must re-run its own scoped `lverify` after the other's next
closure lands (not just once at first-sight-clean) since the shared file's
content keeps moving.

This method found and closed on the order of 400+ never-before-attempted
first-party functions across roughly a dozen files that a
`recon_queue.json`-driven campaign had never surfaced, entirely because the
queue file predated (and undercounted) the tree's current first-party ASM
set. Once density-scanned files bottom out below roughly 25% MATCH with no
fresh (never-attempted) names left, the remaining ASM in that file is
overwhelmingly genuine floors (register-allocation/scheduling walls, or
documented hardware) rather than untried low-hanging fruit; a repeat pass
with the same method on the same file after such a bottom-out reliably
returns zero closures.

## Salvage the lane drafts: an nd < 40 draft is usually one lever from MATCH

Measured across waves 41-43 (2026-09-02/03). Lanes are budget-limited and the
provider kills them at ~25-30 minutes, often mid-edit; four of six lanes in
one wave died that way with compiling drafts left in the tree at nd 9, 12,
30 and 6. Every one of those under nd 40 closed within 15 minutes of
single-lever probing by Main, and two "documented floors" fell the same way.
So: instruct lanes to leave a compiling draft IN PLACE (not revert) when they
run out of time, and finish the small residuals centrally. The levers that
closed them, all measured against b210 `-O2,p`:

- **Match argument types without incompatible local prototypes.** A
  block-scope declaration that disagrees with the callee is not a valid
  scheduling lever, even if the emitted code happens to use the same low
  word. In `func_00279e90`, an unsigned handle local and unsigned load match
  the canonical `u32` argument and reproduce retail's late load without the
  old signed redeclaration. Keep the other branch's explicit `u32` cast:
  it preserves that branch's earlier load. The 316B body still matches.
  In `func_0018dde0`, stage `iGpffffb278` in an `s32 size` local under
  scoped `opt_propagation off`. This preserves the early third-argument
  load while using the callee's four-`s32` prototype, replacing the old
  incompatible `s64` redeclaration. The 332B body still matches.
- **Return values must survive in C, not just in `$v0`.** The font
  constructors `func_00274570` and `func_002745c0` used to be defined `void`
  despite callers consuming the allocated chain. Declare their `u8 *`
  result consistently and explicitly return the nested constructor result;
  also declare the ASM leaf `func_002740b0` with its pointer return.
  Both wrappers and all live consumers retain their instruction matches.
- **Comparison operand side, with defined elapsed arithmetic.** Compute
  elapsed time as `(u32)elapsed_a - (u32)elapsed_b`, then compare
  `elapsed > (u32)limit` or `(u32)limit < elapsed` to select the `$v0`/`$v1`
  order for `sltu`. Casting a signed subtraction afterward does not prevent
  overflow. `func_0018dde0` retains its exact instructions with the casts
  before subtraction; overflow instrumentation confirms signed-boundary,
  counter-wrap, and strict-threshold behavior.
- **Audit semantics before trusting an archived floor.** `func_00199d00`
  omitted the retail `-1`/`>= 0x1B8` guard and narrowed the ID before passing
  it to the predicate. Keep the full `s64` argument, narrow only the guard
  and table index, and stage an unsigned offset under scoped
  `opt_propagation off`. Removing redundant argument aliases restores the
  saved-register assignment; the complete 336B body matches.
  The old `func_001dea90` archives passed a record pointer where retail
  passes the summed weights; one also read uninitialized locals. Rebuilding
  the five-weight selector with separate locals for its two loops reaches
  a two-word residual. Writing `random <= (s32)total` instead of
  `(s32)total >= random` selects `$at` rather than `$v0` for the branch and
  closes the full 288B window without changing the helper's `u32` ABI.
- **Equivalent masks can survive different optimization passes.**
  In `func_0023dff0`, unsigned `% 0x10000U` at the count, table-index,
  choice-index, and final-count sites survives common-subexpression
  elimination separately from `& 0xFFFF`, then lowers to the same `andi`.
  This allows loop-invariant hoisting of the switch table and constant one
  without losing retail's repeated masks. Keep the comparison's explicit
  `s32` cast, and declare the `u32 selected` counter before `s32 index`.
  The complete 320B body matches; all six retail jump-table entries were
  checked and target the accepted-value block.
- **A leaf reading no arguments does not prove a `(void)` prototype.**
  Retail `func_001e9350` explicitly loads the unit pointer into `$a0`
  immediately before calling the constant-eight helper `func_0023e130`.
  Its C definition now retains that unused pointer parameter, consistently
  with its callers. Do not delete real caller argument setup to fit an
  under-specified leaf definition, or hide the mismatch with an old-style
  declaration.
- **Wide shifts may extract narrow bitfields, not imply wide C locals.**
  `func_00311b90` loads a signed halfword, then shifts left/right by 54 to
  extract a signed ten-bit value. Its two byte-load/shift sequences test
  different flags at bits 14 and 15. Both surviving archives instead used
  the whole halfword and the same byte test twice; neither was a valid
  compiler-floor reference. Native `s16` bitfields, `s32` comparisons and
  shifts, and `s16` counters recover the instructions. Scoped
  `opt_loop_invariants on` hoists the shared one; declaring count before
  outer index and inner index before found flag resolves the two register
  swaps. The 364B body matches the 368B window with four bytes of zero tail
  padding. Retail callers supply list lengths two and three.
- **Recover a reproducible candidate before declaring an unconditional floor.**
  The old `func_004a30e0` note claimed b210 always coalesced two unsigned
  conversion ORs into the wrong operand. Reconstructing the surviving XWND
  archive with native casts, its existing four-byte color aggregate, and
  loop-local invariant products makes both OR/mtc1 pairs exact. The retained
  764B/768B candidate is still nonmatching: nine replication-loop register
  differences plus one tail-padding word. Its copy helper uses the real
  `(void *, const void *, u32)` argument types. The historical nd5 body was
  unavailable; this corrects the coalescing claim, not that recorded score.
- **Loop-counter vs count colouring.** Declaring `i` before `count` swaps
  their `$a2`/`$a3` colouring (`func_001b1280`). Declaration order is the
  lever, not assignment order.
- **Shared trampoline branch targets.** When retail's switch dispatches an
  early-return case through the common `b end` trampoline but the draft
  `beq`s straight to the epilogue, fold the preceding `if (x == 1) return;`
  into the switch as `case 1: default: return;` (`func_001b1280`).
- **`lh v0; move s0,v0` copies.** Loading a field into an *existing* u16
  temp and casting `(s16)` at each of its two uses reproduces the
  load-then-copy retail shape; a fresh s16/s32 local, or passing the field
  expression directly, does not (`func_001f39d0`, together with
  `opt_propagation off`).
- **Field-vs-GP-global float compare load order** (`func_002b9e10`, the
  "RHS-load-first scheduling wall" recorded above in the file — retired).
  Under `opt_propagation off`, copy the field into a local, THEN the global
  into a second local, and compare the locals: mwcc loads the field first as
  retail does. Without the pragma the copy order is ignored.
- **Recomputed `base + i * N`.** Retail often re-derives an entry pointer
  after a call rather than keeping it in a saved register. Spelling the second
  computation `base + (u32)i * N` stops mwcc CSE-ing it with the earlier s32
  form and reproduces the recompute exactly (`func_002b9e10`, nd 15 -> 3).
- **Staged 12-byte copies without `volatile`** (`func_0033fa30`, the
  "scheduler-CSE floor" recorded above — retired). The `[addiu a1][lui][ld]
  [lui][lwc1][sd][swc1]` order comes from `push`/`pop opt_propagation off`
  with plain `s64`/`f32` locals staged through a frame struct
  (`struct { f32 sp30[4]; s64 sp40; f32 sp48; }`). A lane closed it first with
  `volatile` staging plus a packed struct; that body was rejected (H001) and
  the legal spelling scores the same nd 0.
- **32->64 store without `dsll32/dsrl32`** (`func_004555d0`, sdkCdvd.c, the
  "extension-materialisation floor" retired). Store the u32 result to the s32
  field, then reload the field into the s64 slot: the `lw` sign-extension
  feeds `sd`/`lq`/`sq` directly.

- **Unsigned-to-float is a cast, not a hand-written idiom** (`func_003657d0`).
  Retail's `bltz / mtc1+cvt.s.w / srl-andi-or+mtc1+cvt+add.s` sequence is what
  b210 emits for `(f32)(u32)x`; spelling it out in C reproduces the words but
  colours the OR into `$v0` instead of retail's `$v1`. The float-to-int twin
  (`trunc/cvt.w.s`, `lui 0x4f00` compare, `0x80000000` fixup) is `(s32)(u32)f`.
- **Constant-first `mul.s`.** `iGpffff8094 * (f32)i` in ONE expression puts
  the GP constant in the first operand; splitting the cast into a named local
  and multiplying afterwards (either operand order) gives the local first.
- **Recompute-vs-CSE spellings.** `*(s16 *)((u32)p + 8)` is not merged with an
  earlier `*(s16 *)(p + 8)` (`func_0047ed60`: retail re-reads a slot the compare
  already forwarded), exactly as `base + (u32)i * N` is not merged with the s32
  form. Use these when retail repeats a load/address b210 would otherwise CSE.
- **A statement of its own survives propagation-off, not propagation-on**
  (`func_004bc540`): `arg1 = arg1 << 3;` before the address expression keeps the
  sll ahead of the loads only under `opt_propagation off`; with propagation on
  it folds into the address and is emitted after them.

Two floors this pass confirmed rather than broke: `func_003b7ca0`
(rprandom_grouped.c, nd 2) keeps an `lbu`/`sll` pair swapped inside an
OR-assembly expression through 16 association/temp spellings and every
scheduling-relevant pragma — the pre-schedule order is identical for all of
them, so this is a scheduler tie-break; and `func_00396520` (code1_0039.c,
the COP1 chain) now reproduces retail's f1-f8 operand colouring (a zero-valued
f32 local assigned first reserves f0; `+=` products give the `mtc1 zero /
adda.s / madd.s` chain) but the w-product/dot register pair stays swapped
across 120 shapes and a 41k-compile AST-permuter run.

## IDA quaternion recovery: aggregates before register speculation

`func_00480f20` in `src/Graphics/primitive.c` is now MATCH: 408B of
instructions plus eight bytes of retail zero tail. The old JnF archive had
all three cross-product signs reversed; a native reproduction produced
z = -1 where inverse-input times output requires z = +1. IDA and retail
assembly establish the corrected orientation.

Use a shared four-float `PrimQuaternion` for the saved output and inverse,
then conventional x/y/z/w norm and dot expressions. These recover the
snapshot loads, inverse lifetimes and accumulator scheduling without
pragmas or assembly. Retail skips inverse initialization for zero norm;
the reconstruction preserves that undefined path rather than inventing
a fallback. The consumer smoke covers 3,889 positive-norm cases, including
noncommuting rotations, input/output aliasing, six scalar subtractions and
untouched bytes. All 12 functions in the translation unit verify MATCH.
The superseded, sign-inverted archive is removed.

The IDA-backed window constructor `func_0046e850` remains ASM. Its archive
now uses a signed integer rectangle and four-byte color aggregates, with
the actual eight-argument constructor and fresh allocator-table lookup.
The 444B/448B floor is four words: three argument-setup instructions and
one zero-tail word. A 2,704-case native 32-bit smoke covers allocation
failures, null constructor returns, constructor mutation, signed division
boundaries, and untouched bytes. Size calculation uses the first two
rectangle members, not its width/height members.

The next compact IDA replay retained two measured floors:
`func_001d15a0` is 212B/224B with nine index/result register differences
and three zero-tail words; its eight-byte helper buffer passes 9,750
native cases, including unsigned high-bit thresholds and gate values 0/1/2.
`func_0048a460` remains 176B/176B with 15 instruction differences.
A named aligned projection frame ties its prior score; 153 native cases
with VU transfer hooks check transformed coordinates, negative depth,
successive projections, positive-zero lanes and spill canaries.

`func_004865c0` exposed invalid archive evidence: the old 51-word draft
hard-coded stack offsets and ordinary instructions inside purported
hardware-only assembly. It is removed. The retained source-only reference
uses byte aggregates and signed float-to-integer conversion: 396B/288B,
91 differing words, versus the historical scalar record of 860B/211.
Its 65,540-case native smoke covers packed lanes, optional callbacks,
callback mutation, captured parent color/scale and next-pointer reloads.
This proves host arithmetic and control behavior, **not** VU register
effects or PS2 rounding identity. All three functions remain ASM.

## IDA state and interpolation recovery: preserve the source objects

`func_003672d0` is now MATCH at 336B/336B. The IDA body at
`docs/ida_headstart/src/promoted/code1_0036.c:946-988` recovers the
two distinct persona lookups and the signed 16-bit protagonist index.
Its callees needed real contracts: `func_00104f10` returns the signed rank
helper result, and `func_00109440` returns the unsigned next-level EXP.
Both wrappers now return their existing calls; the event caller and
state-update declarations use those same contracts. A 1,310-case native
smoke exercises the actual wrappers, protagonist ranks, distinct lookup
results, wrapping EXP subtraction, negative clamping and untouched bytes.
The obsolete E367 and T36 floor archives are removed.

`func_0035bd20` is also MATCH: 332B of exact code plus four bytes of retail
zero padding. IDA (`docs/ida_headstart/src/promoted/code1_0035.c:2146-2172`)
exposes three packed two-float values, the copied three-float normal and
two in-place normalization calls, but omits the COP1 projection arithmetic.
Read retail alongside it; the apparent constant return is not trustworthy.

Pass the points and origin as existing `Float2` values. Copy the normal as
a three-float aggregate. The private in-place weighted accumulator keeps
the accumulator's source identity through both calls and emits the retail
unit-weight multiply-adds. No register binding, assembly, pragma or
mathematical reassociation is needed. Direct scalar accumulation measured
53 differing words; the by-value weighted helper measured 37; the
in-place helper closes every instruction. A 20,490-case host smoke checks
normalized projection results, input ordering, the captured normal under
helper mutation, negative results and the upper clamp. This is host
normalization/rounding evidence; the PS2 instruction proof is the scoped
verifier, which reports 71 MATCH and nine ASM for the translation unit.

`func_00375f00` stays ASM. Its IDA-backed typed archive retains the 0xE8
record stride, 0x60-byte motion and 0x6C-byte rotation objects. The helper
calls precede the respective state stores of 5 and 3; no final flag OR
belongs to this function. A 576-case native smoke with helper hooks checks
that ordering and adjacent bytes. The floor remains 156B/160B with eight
differing words, including one zero-tail word.

After both promotions, `make build-progress progress lint-errors` reports
6,081 first-party MATCH and 779 ASM, with both retail SHA-1 checks passing
and zero lint findings. The source-linked total remains 1,555; matching
these functions does not yet make their translation units C-linkable.

Filter archive targets through the **current** verification report before
probing. The old W49Code1b and LaneSingles `001b13c0` drafts were stale:
the canonical grouped unit already measures 132B/144B with only zero tail.
Its visible static three-argument removal helper preserves the real `a2`
lifetime, and auto-inlining retains both the standalone body and its
expansion in `001b1450`. Both obsolete drafts are removed. IDA replay of
`00106f40` and `00484b30` leaves their six- and eight-word floors unchanged;
the archives record the tested contracts and helper hypotheses.

## IDA model attachment: preserve snapshots and pointer contracts

`func_00473710` is MATCH: 340B of exact instructions plus 12 bytes of
retail zero tail. Read the complete IDA body at
`docs/ida_headstart/src/Graphics/Model/mdlManager.c:1053-1085` alongside
the retail assembly. Its separate `v7 = v9` snapshot matters: loading the
escaped output slot again after storing the model's hierarchy emits an
extra reload. Named hierarchy, model, animation-source and clump views
also prevent the old raw-offset address-CSE register rotation.

The remaining argument-order difference was a wrong API declaration.
The canonical `RwFrameForAllChildren` in `src/renderware/core/baframe.c`
takes pointer-valued userdata; `RwFrameCallBack` likewise returns a frame
pointer and receives a data pointer. The model unit now uses its existing
opaque-pointer callback convention consistently, without integer userdata
or incompatible callback casts. Both recursive traversal callers migrate.
The constructor declaration now has its real two integer arguments.

Three incomplete C contracts were repaired without changing their retail
instructions: the hierarchy getter receives its frame, the atomic callback
receives and forwards both object and hierarchy, and `func_003d5790`
returns the allocated interpolator. Before these repairs, an instrumented
68-case native consumer reported 80 failures; afterward it reported none.
The old constructor also triggered `-Wreturn-type`.

An additional smoke extracted the promoted production attachment,
callbacks and constructor: **2,304 cases, zero failures**. It exercises
optional traversal, absent source/animation, distinct interpolator
allocations, animation assignment, zero-time setup, flag preservation,
and field reloads when helpers mutate the frame, hierarchy, source,
second interpolator or flags. These are 64-bit host semantic checks with
low-address fixtures, not a PS2 rendering run; retail instruction
identity is checked separately. The superseded PMDL attachment archive
is removed, as is the older YFNT shuffle draft superseded by D375.

The spline replay (`001bb790`) still has 21 instruction differences and
two absent zero-tail words. Its in-place output-object helper ties the
existing JnB archive; it is not another promotion.

Distance selection (`001d8cb0`) exposed unsafe archive evidence. Its old
14-word draft compared an uninitialized best distance before checking
the first-entry flag. The replacement guards that comparison, uses the
actual three-float vectors and typed 12-pointer selection table, and
measures **18 words**: 12 key-loop register differences, four guarded
comparison/branch differences, and two zero-tail words. A 1,092-case
native smoke checks key precedence, duplicate keys, absent actors,
empty tables, nearest selection and first-on-tie behavior. Production
remains ASM; a lower score obtained through undefined C is not a floor
worth retaining.

`make build-progress progress lint-errors` now reports **7,712 MATCH**,
including **6,082 first-party MATCH (88.7%)** and **778 first-party ASM**.
Both retail SHA-1 checks pass; lint reports zero findings. C-linked
functions remain 1,555: this model unit still contains assembly fallbacks.

## Frame lookup and matrix copy: preserve real helper return paths

The attachment repair's pointer-valued traversal API also closes
`func_00475b90`: **312B of exact instructions plus eight zero-tail bytes**.
Its complete IDA body is at
`docs/ida_headstart/src/Graphics/Model/mdlManager.c:1778-1809`.
The cohesive private `mdl_find_frame` helper returns the root immediately
when its ID matches; otherwise it traverses children and returns the
result. Inlining those distinct return paths preserves the retail
`bne` into setup and unconditional branch around it. Flattened if/goto
spellings had removed that branch and disturbed register allocation.

The callback and helper share `MdlFrameSearch { void *frame; s32 id; }`.
This retains the real eight-byte PS2 userdata layout without writing a
pointer through an integer array. Existing public signatures remain
unchanged; recursive frame lookup uses the same callback contract.

`func_0047a510` is likewise MATCH: **440B plus eight zero-tail bytes**.
Read IDA at the same path, lines 2960-3036. Its table has a 16-bit count
and 0x50-byte entries: a 64-byte `RwMatrix`, an ID, a frame ID, and eight
unknown bytes. The shared frame finder closes its search branch.
The private table-path helper preserves the common return block,
including two branch destinations that a flattened implementation had
redirected straight to the epilogue. Scoped `opt_common_subs off` retains
the distinct body/test/found-index masks.

Use `RwMatrix` assignment for the fallback copy. Retail copies eight
**pairs** of words, not eight words; the aggregate assignment emits that
exact load/load/advance/decrement/store/store sequence. The no-table
fallback passes the original unmasked lookup ID, unlike the table path's
16-bit comparison.

A freestanding **32-bit x86** smoke compiled the actual production
callback, both helpers and both public functions without multilib libc:
**1,580 cases, zero failures**. It checks matrix results, zero/missing
table entries, masked IDs, root/direct/deep frame matches, failed search,
unchanged output on failure, and all 64 fallback-copy bytes. Duplicate
deep frame IDs deliberately exercise the callback's existing behavior:
a match in a later subtree can replace an earlier deep match.
This is a real 32-bit host consumer, not a PS2 rendering test.

The model unit now verifies **113 MATCH, 13 ASM**. Superseded mdl/PMDL/
CF_P27/CF_P29 drafts for these functions are removed. The PMDL
`00477ca0` draft was also stale: production already used the exact
16-bit for-loop and pointer-to-array entry view.

The parallel `001b11c0` replay still has its five key/index register
differences at 192B/192B. Actual `BtlAction` typing and narrower key/genus
locals tie that floor; IDA-wide scalars regress. It remains ASM.

Full verification after both promotions reports **7,714 MATCH**, including
**6,084 first-party MATCH (88.7%)** and **776 first-party ASM**. Both retail
SHA-1 checks pass and lint has zero findings. Source linkage remains
1,555 functions across 172 eligible C objects.

## Animation stepping and dispatch: separate callbacks from validation

The complete IDA bodies in
`docs/ida_headstart/src/Graphics/Model/mdlManager.c` precede these recoveries:
`00475820` at lines 1687-1775 and `00479940` at lines 2873-2957.

`func_00475820` now matches **744 instruction bytes plus eight zero-tail
bytes**. The existing `RtAnimInterpolator` layout replaces offset-only
callback access. Private primary/object and secondary helpers retain
separate interpolator lifetimes; the secondary mode-1 path registers a
callback without seeking or copying back its time. Scoped forced inlining
preserves those real helper paths without introducing runtime calls.
Both null-sub callback comparisons remain conjunctive: either sentinel
suppresses the ordinary secondary seek.

`func_00479940` matches **all 752 bytes**. Its validated dispatch helper
retains base-matrix preparation, layer dispatch, attached-animation flags
and the five-child traversal. The matrix copy is a complete `RwMatrix`
assignment; identity fallback preserves padding and ORs the existing flags.
The layer remains a raw `u32` until each documented 16-bit use.

The validator `func_00479d10` still matches **188 bytes plus four zero-tail
bytes**. Its explicit prototype accepts `s32` animation, while its C89
old-style definition declares the promoted parameter as `s16`. This
performs signed-short conversion inside the callee, where retail does it,
instead of inserting narrowing at dispatch's call site. No register
parameters or incompatible function-pointer casts are needed.

Live dispatch declarations use one contract:
`s32 func_00479940(u8*, u32, s32, s32, s32)`.
The caller migration preserves explicit masks already present in source
and replaces integer-address arguments with explicit pointer casts.
Generated reference archives are not live callers.

The complete caller check exposed two conversions previously supplied by
stale narrow prototypes. Command `00176c70` explicitly converts animation
to `s16` and its converted frame to `u16`; scene `00269820` explicitly
narrows the dispatch layer and frame to `u16`. The headstart export omits
these already-matched bodies, so their complete retail assembly supplies
the conversion evidence (`00176d3c`/`00176d44` and `00269944`/`00269950`).
Both regain their instruction matches without narrowing the shared API.
A separate native caller smoke passes **11,952 cases** covering command
branches, high/signed argument bits, scene guards, skip-current behavior,
ordered animation effects and scene-flag preservation. This is post-fix
smoke coverage; the instruction verifier establishes the caller regression
and its repair.

Two freestanding **32-bit x86** consumers compile the actual promoted
source, with instrumented external animation operations:

- **11,340 stepping cases, zero failures**: absent resources/lists, object
  types, zero/nonzero/maximal ticks, both interpolator slots, ordinary and
  special callbacks, each null-sub sentinel, mode-1 behavior, callback
  mutations during registration, restored callbacks after seeking, and
  time propagation across successive objects.
- **7,392 dispatch cases, zero failures**: actual validator execution,
  missing/null/sentinel/valid clips, primary and alternate tables, index
  boundaries and high argument bits, masked layers, matrix bytes and
  padding, blending, attached flags and ordered child effects. Signed
  negative-index cases use backing arrays with valid preceding entries;
  they do not invent a bounds check absent from retail.

These are host semantic checks, not PS2 rendering tests. Separate
fully relocated comparison confirms all three instruction bodies and
their zero tails.

Setup (`00475350`, IDA lines 1542-1684) remains ASM. Its typed resource,
scheme and detach reconstruction improves the historical 245-word draft
to **30 fully relocated instruction differences**, at 1220B/1232B with
12 zero-tail bytes. `docs/probe_archive/IDA_00475350_body.c` retains the
candidate. The successful-loop animation/interpolator allocation still
differs; it is not an accepted promotion.

After the caller corrections, complete verification reports **7,716 MATCH**
and **zero mismatches**, including **6,086 first-party MATCH (88.7%)** and
**774 first-party ASM**. Both retail SHA-1 checks pass; lint reports zero
findings across 333 first-party files. Source linkage remains 1,555
functions across 172 eligible C objects.

## Model cloning: preserve storage stages and the hierarchy ABI

The complete IDA body at `mdlManager.c:2448-2545` and the retail assembly
recover `func_00478410`: **824 instruction bytes plus eight zero-tail bytes**.
The old saved-register-count floor was not intrinsic to the compiler.
Keeping a destination model base plus its layer stride preserves the
resource/hierarchy lifetime. The private attachment-storage constructor
starts with `sizeof(MdlCloneAttachmentTable)` and adds each of the two
appended pointer arrays separately; collapsing those stages into one size
expression changed both instruction selection and saved-register allocation.

The final load/move pair exposed conflicting declarations of
`func_003971d0`. Its retail body retains and returns the allocated hierarchy
pointer (`00397280-0039728c`, `00397320`). The canonical contract is now
`u32* func_003971d0(u8*, s32, s32, s32)`, consistent with the recovered
four-argument implementation. Remove the signed integer declaration and
the block-local unsigned integer workaround rather than introducing
another function-pointer cast. The existing `func_00477ca0` retains its
468-byte instruction match and twelve zero-tail bytes with this contract.

The shared dispatch table gains its observed reference halfword at `0x0a`
without changing its 12-byte target size. Existing dispatch and matrix
views move before their new clone consumer; they are not duplicated.
Attachment counts use a union for the source halfword and destination
word views. Array pointers and loop bounds remain reloadable after clone
callbacks. Both hierarchy branches read the **base destination hierarchy**,
including the second layer; replacing that with the current layer changes
observable behavior.

A freestanding **32-bit x86** consumer extracts the actual production clone
and private constructor unchanged. **1,540 cases pass**, covering missing
and present clumps, independent layer paths, reference-count wrapping,
attachment holes and count widths, callback-mutated arrays and bounds,
resource setup ordering, standalone clone/update, final resource addresses,
and conditional initial dispatch. A deliberate current-layer hierarchy
mutation fails at **case 481, code 23**; restoring the production source
passes all cases again. This is a host semantic check, not a PS2 rendering
test.

Two other complete IDA reconstructions remain compiler floors:

- Layer animation `004740c0`: **1300B/1328B, 215 reloc-masked differing
  words**. Member-first offsets and copy-before-seek branching improve the
  earlier 293-word draft. CSE-off reaches the target size but worsens the
  residual to 284 words.
- Material colors `00476e90`: **996B/976B, 72 reloc-masked differing
  words**. Ordinary unsigned-to-float casts reproduce the conversion CFG;
  scoped CSE/propagation settings retain normalization loads and named
  quantization constants. Accumulator-zero materialization and register
  allocation remain different.

Their source and replay requirements are retained in
`docs/probe_archive/IDA_004740c0_body.c`,
`docs/probe_archive/IDA_00476e90_body.c`, and
`docs/probe_archive/IDA_model_followthrough.json`. These scores are not
fully relocated acceptance proofs; neither floor was promoted or
semantically smoke-tested.

The complete build/progress pipeline reports **7,717 MATCH, zero
mismatches**, with **6,087 first-party MATCH (88.7%)** and **773 first-party
ASM**. Both retail SHA-1 checks pass. Linkage remains 1,555 functions in
172 eligible C objects. Full lint reports **zero errors and 181 advisory
warnings** across 333 first-party files.

## Model callbacks: preserve both argument registers in C

The retail wrappers `00479030` and `0047ddd0` preserve their incoming
second argument when calling model setup and runtime color application.
Their former one-argument C calls depended on that register surviving
incidentally. The promoted source now declares and forwards both arguments:
the model to `func_00478ec0`, and the requested RGBA bytes to
`func_004b5f80`. Opaque declarations use the existing `MdlFlags78ec0`
and `RuntimeWork` struct tags rather than introducing alternate layouts.

A freestanding 32-bit host consumer using the actual callee bodies passes
**1,280 cases**. Compiling the original wrappers against those callee
contracts reproduces both missing-argument errors. This is a host
semantic check, not a PS2 rendering test.

The update reconstruction initially measured **1116B/1088B, 175
reloc-masked differing words** with scoped CSE disabled; separate phase
counters alone did not improve the initial 239-word result. It is now
promoted; see “Recursive model update: cache within call boundaries” below.
Rendering `00479100` remains **1852B/1920B, 409 words**; CSE-off worsened it
to 1968B/436 words and was removed. Its complete candidate remains in
`docs/probe_archive/IDA_00479100_body.c`, with replay requirements in
`docs/probe_archive/IDA_model_followthrough.json`. Rendering has not been
semantically smoke-tested or accepted as matching.

After these callback corrections, `make build verify lint-errors` passes:
both retail SHA-1 checks succeed, all **7,717 instruction matches** remain,
and **6,087 first-party functions match with 773 ASM remaining**. The
errors-only lint gate reports zero errors; this invocation does not
report advisory warning counts.

## Helper-bearing probes: resolve identity from the owning source

Probe normalization removes copied `FUN_` markers. When a candidate has
declarations or private helpers before its target, scanning that synthetic
region can associate the remaining marker with the wrong function.
`run_fndiff` now resolves the requested symbol's retail address from the
logical owning source, then passes that address to `fndiff` while compiling
the isolated candidate with the owning translation unit's settings. This
also supports recovered names without an address embedded in the symbol.

The regression exercises real scoring with a named target behind a helper:
the pre-fix runner fails with a missing-marker diagnostic; the repaired
runner scores the intended function. All ten focused probe tests pass.
The ordinary archive CLI now replays the complete helper-bearing
`IDA_00476e90_body.c` candidate as **996B/976B, 72 differing words**.
The ordinary variant CLI also scores the formation reconstruction without
a custom marker-preserving driver. Neither measurement installs source.

The full `make test` suite passes all 519 tooling tests.

## AI command predicate: preserve both retail forms

`func_001db160` is now **MATCH, 508B/512B, verify normalized_diff 0**.
The last four bytes are zero tail padding. Complete IDA recovery first
reached 58 differing words; replacing its expanded boolean expression with
the existing usability check reached two content differences. Explicit
signed query values and direct rejection guards close those comparisons.

The implementation lives once in private inline `btlCommandUsable`.
Both `func_001daf40` and the recovered predicate use it. Keeping the public
entry is necessary: the retail dispatch table points command `0x3a` at
`func_001daf40` and command `0x3e` at `func_001db160`. Marking only the public
definition inline removed its emitted symbol. The shared implementation
plus real callback entry preserves both retail forms without fake address
references or export pragmas.

The target retains its existing `s32` input ABI. Its signed-16-bit query
values are not a reason to narrow that input. Correct helper declarations
and typed pointer loads also preserve `func_001e64c0` and `func_001e6a50`;
the value-forwarding wrapper keeps its explicit signed-16-bit conversion.
The complete translation unit verifies **257 MATCH, 6 ASM**, with no
mismatched or missing symbols.

A native host smoke run with UBSan trap instrumentation passes **602
cases**: signed query boundaries, count narrowing and unsigned iteration,
post-query command mutation, work-pointer snapshots, data-pointer reloads,
returning diagnostics, short-circuit gating, and both public wrappers.
It uses aligned host pointer members and asserts that address-as-integer
arguments fit 32 bits; this checks callback logic, not EE layout.
Deliberately caching a command before its value query fails case zero:
availability receives the stale command `1` instead of the reloaded `0`.

The other battle recoveries remain assembly: formation `func_001d2e20`
scores **93 differing words**, and result-number `func_0021ed10` scores
**43**, not an improvement on its historical 39-word floor. Their complete
fragments and the accepted AI evidence are retained in
`docs/probe_archive/IDA_battle_recovery.json`; no unmatched candidate was
installed.

The integration gate `make build verify lint-errors` passes: **7718 MATCH**
overall, **6088/6860 first-party MATCH**, **772 first-party ASM**, and no
mismatches. Errors-only lint reports zero errors across 333 first-party
files. The loadable-image SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the rebuilt executable SHA1
remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
Linked C coverage stays at 172 complete objects: the AI unit still has six
assembly functions, so this is an instruction-match gain, not a claim that
the new AI C body is already linked into the retail image.

## AI skill callbacks: return the predicate result explicitly

`btlCond_MYNOMAL` and `func_001db5b0` now return `s32` and accept
`u8 *formation, s32 index`. Retail forwards both input registers and returns
the result of `func_001db360`; the old `void(u64,u16)` declarations did not
express that contract. Both callbacks remain **MATCH, 36B/48B**.

The same recovery corrects this unit's bitmap query to the live
`u32 func_0010f420(u32,u32)` contract and uses pointer loads for both sibling
calls to `func_00242800`. With the correct bitmap declaration,
`func_001db9f0` needs an explicit index preparation and scoped
`opt_propagation off` to retain the retail argument order. It remains
**MATCH, 156B/160B**; `func_001db5e0` remains **MATCH, 64B/64B**.
The complete unit retains **257 MATCH, 6 ASM**.

A native UBSan-instrumented consumer passes **6,144 cases**, using the
actual C callbacks and sibling predicates with the archived reconstruction
and controlled leaf helpers. It covers normal versus relaxed eligibility,
enemy bitmap precedence, status signs, blocked unit flags, all three
excluded skills, empty lists, final masks, and index upper bits. The
original callback signatures fail to compile against that result-consuming
interface. This checks C consumer semantics, not the live PS2 assembly.

The reconstructed `func_001db360` remains assembly-backed. Its replayable
archive improves the historical **19-word** floor to **17**, at
**544B/544B**. An `s32` command removes redundant masks but leaves the final
comparison inverted and the object eight bytes short; `u16` restores the
size without matching those instructions. Neither shape is a match.
`IDA_001db360_body.c` now replays through the normal probe CLI without
private declaration patches; `IDA_battle_recovery.json` records the
remaining offsets, alternatives, callback proof, and semantic limitations.

The final `make build verify lint-errors` gate passes with **7,718 MATCH**
overall and **6,088 first-party MATCH / 772 ASM**. Both retail SHA-1 values
above are unchanged; errors-only lint reports zero errors across 333
first-party files. This callback repair does not claim another C promotion
or an increase in the 172 linked C objects.

## Blur allocators: narrow the lookup, name the header span

`func_004ab420` and `func_004aaee0` are now **MATCH, 372B/384B**.
All 93 executable words in each function match; the remaining three words
are zero tail padding. The complete `effBlurFilter.c` unit verifies
**53 MATCH, no ASM**.

The `004ab420` six-word archive had only three executable differences:
b210 retained `0xFFFF` rather than the retail header size `0x60` in its
saved constant register. Keep the first `type & 0xFFFF`, narrow only the
callback lookup with `(u16)type`, and name the one-use `headerBytes = 0x60`
used to form the copied-data pointer. Together these produce the retail
constant selection without register hints, volatile, or ordinary assembly.
The unsigned size assertion and allocation-before-size declaration order
remain important. Narrowing alone regresses to 90 words; disabling
propagation with the named span leaves 22. The same winning source shape
closes the sibling allocator without changing either public signature.

Preserve the semantic difference: `004ab420` passes the original input to
its initializer, while `004aaee0` reloads the copied-data pointer from
object offset `0x24`. Both look up the initializer after copying.
Separate 32-bit freestanding UBSan-instrumented consumers pass **480 cases
each**, checking the complete allocation image and guards, masked type,
size-assertion boundary, header, payload, callback ordering and results,
and descriptor/callback mutation by controlled leaf helpers. The sibling
also checks pointer reload after a controlled copy-helper mutation.
Only the fixed COP2 VF0 store is adapted for the host; target instruction
identity verifies the real `sqc2`. These smokes use valid allocations and
returning size diagnostics; they do not claim allocation-failure coverage
or execution of the retail game. Four superseded allocator drafts are
removed; the accepted bodies now live in the owning source.

Other concrete levers were measured and parked without adjacent ABI work:
aggregate count/pointer pairing leaves cut-in `001f9cf0` at four words;
typed controller pairs regress `004b5800` from five to six; community
record/index aggregates leave `00106f40` at ten; separate wind phase spans
leave `004a30e0` at ten. These counts include any missing zero tail words.

The full `make build verify lint-errors` gate passes: **7,720 MATCH**
overall, **6,090 first-party MATCH / 770 ASM**, and zero lint errors across
333 first-party files. The 172 linked C objects retain both retail SHA-1s:
loadable image `3d1d3d2b9d6ccb60836db239ab49674223025a78`, executable
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Further bounded low-floor probes

The `00279780` message-initialization candidate initially improved **9 to 3
words**, still **768B/768B**. Named zero origins with scoped
`opt_propagation off` restored the six constructor argument-order words.
The remaining three words materialized `D_00881530` before moving the first
argument at `func_00279dd0`; explicit context and context/address locals did
not change that. This floor is now closed by the binding helper's verified
text-pointer contract; see “Message initialization: preserve the text pointer”
below. The superseded archive is removed.

For `0047f850`, three target/count/dispatch iteration-state aggregate
orders produce byte-identical **412B/416B, 13-word** output: twelve register
differences and one zero-tail word. For `001d15a0`, a named entry stride,
narrowed loop test, or both produce byte-identical **212B/224B, 12-word**
output: nine register differences and three zero-tail words.
The track-dispatch floor is subsequently closed by direct indexed callbacks
and scoped loop-invariant optimization; see [Track dispatch and compatible
callback contracts](#track-dispatch-and-compatible-callback-contracts).

The reported sound `0045c640` floor is not re-certified. Its old final-call
fixed-five-argument cast is not established against `0043c518`'s
variadic-looking register-save contract. That helper copies the fifth
input register into its packet even at a call site preparing only four
arguments. Resolving this contract is a prerequisite, not permission for
another ABI-cleanup batch. No sound source or helper declaration changes.

Named signed/unsigned/byte alpha maxima leave `001130c0` byte-identical at
**7 words**. Named task-construction scalars regress `0046e850` from
**4 to 7**; its parent move still sinks after the global address. Both
original safe archives remain unchanged apart from measured notes.

`0044f140` is re-certified as valid C at **596B/608B, 4 words**: one
threaded branch and three zero-tail words. The old header pointer survives
the void unlink helper in `$v0`; free consumes that pointer, not a return
value. The archive now expresses the two calls separately, without an ABI
change. Removing the empty `else` and disabling branch folding, peephole
optimization or conditional rebuilding leave four words. An early-return
tail with its own outer interrupt restore regresses to **616B, 77 words**.

The `0029e550` script scan is re-certified at **608B/608B, 3 words**.
Removing the overwritten pre-loop scan assignment changes no instructions.
Reversed equality operands give four words; a literal slash gives six;
a signed-byte slash grows to **616B, 103 words**. Its clear-call setup
already matches; no speculative call-argument rewrite is needed.

For `0014be50`, a named automatic normal-parts initializer followed by
aggregate assignment regresses **416B/416B, 4 words** to **468B, 94 words**.
It adds local zeroing and a local aggregate copy; it does not stage both
global loads before the stores. The 8-byte XY and 4-byte Z extents remain
unchanged.

The scoped `optimization_level 1` floor for `00311930` is **596B/608B,
8 raw words**: five FPU destination-register differences and three zero
tail words. The archive's historical `normalized_diff=6` counts **bytes**,
not words. Direct conversion of the table expression, an integer
initializer and a const float initializer all leave the same residual.
Neither conversion semantics nor table lookup order is changed.

`00456530` improves **32 to 18 to 12 raw words**, at **348B/352B**.
The candidate now uses existing helper declarations and a typed four-byte
record-length object. Scoped `opt_propagation off` restores separator
hoisting; expressing signed division as `/ 64` restores all six rounding
words. Explicit unsigned bias addition and multiplication preserve the
retail arithmetic without a signed-overflowing bias or negative left shift.
Eleven loop-register words and one zero-tail word remain. Counter scopes,
moving loop locals/constants and widening the character temporary do not
improve the floor; byte separators regress to **356B, 46 words**.

`0048a980` is re-certified at **584B/592B, 7 raw words**: five FPR
differences and two zero-tail words, or five normalized differing bytes.
Root-local, root-literal, in-place-root, literal-identity and named-identity
forms do not improve it. The archive now includes its required plain-C
inline add helper; the current unit already supplies multiply.

The action-state experiment for `001b0020` stops before compilation:
its five-argument archived declaration conflicts with the matched
four-argument `btlUnitCreateMovePacket`. The `0032c480` draw-argument
experiment likewise stops at incompatible archived declarations. Neither
is permission to change shared APIs merely to replay a historical score.

`00105a50` is re-certified with canonical `datPersonaGetNextExp(int)` calls
at **576B/576B, 34 raw words / 78 normalized bytes**. The original
`D_005DD6DC` table base with index-plus-one leaves the same floor as its
four-byte-shifted `D_005DD6E0` view; signed-word reads address the same
99-entry interval. A single byte induction variable, directly or through
a fully inlined table helper, regresses to **544B, 104 words / 286 bytes**.
Its missing eight words contain executable epilogue code and the final
delay-slot nop, not ignorable tail padding. The original two-counter
archive is retained; no table extent or shared API is changed.

`0027a150` remains **332B/336B, 32 raw words / 34 normalized bytes**.
Initializing `current` at its declaration or using mutable `arg0` is
byte-identical. Disabling propagation for the initializer changes entry
copy order but not coloring, leaving 32 words and 35 differing bytes.
Initializing `remaining` from the incoming lower bound, alone or together
with `current` under the same scoped control, also leaves 32 words.
The floor still has 31 executable differences and one zero-tail word;
the **0x50 frame and s0-s3 save set** already agree. These source levers
are parked, with no production body or signature change.

## Font metrics: native signed division and the real small table

`func_00271d10` in `src/frFont.c` closes at **576B/576B**. Replaying the
retained source gives **42 raw differing words**; replacing seven manual
signed-rounding sequences with native `/ 32` and `/ 128` leaves one.
Writing `-var_8` instead of `(-1 * var_8)` fixes that final multiply operand
order. No arithmetic reassociation, optimizer pragma or helper is needed.

The archive's scalar height declaration was not promotion-ready. Retail
`0x00763808..0x0076380f` contains eight signed bytes:
`32, 28, 26, 24, 22, 12, 32, 32`. The next halfword, `D_00763810`, is an
independently updated flag object, not a ninth height. Both live units now
declare `extern s8 D_00763808[8]` and index the array directly. Its actual
eight-byte size naturally meets b210's default small-data threshold and
retains GP displacement `-0x58e8`; incomplete or diagnostic nine-byte
declarations instead produce **592B, 137 differing words**. No fake bound,
section annotation, alias or compiler flag is introduced.

The existing `func_00275a40` getter retains all seven emitted instructions,
identical to its previous object and retail; its **28B/32B** window differs
only by the retail alignment nop. The glyph slot's header address is read
through its existing `u32` member before pointer conversion, rather than
accessing that word through a pointer lvalue. Removing the unused local and
using this typed load preserve the exact font instructions. Public
signatures and the slot layout are unchanged.

An independent retail-derived oracle passes **1,034,880 cases** against the
final source in a real 32-bit UBSan process. It checks every output and
untouched byte, both output canaries, and slot/header/metric/table
immutability. Coverage includes all eight valid fonts, signed metric
endpoints and rounding boundaries, both special glyphs, zero metrics,
flag/header/limit rejection, positive and fallback sizes, unsigned byte
reloads, modulo-byte stores, and independently enabled scale axes.
The oracle uses 64-bit magnitude quotients, not the archived shift/bias
implementation. This is bounded valid-resource arithmetic coverage, not a
claim about overflow, invalid indices, concurrent mutation or running the
retail game. The final run has no compiler or sanitizer diagnostics.

`make build verify lint-errors` passes: **7,721 MATCH overall**,
**6,091 first-party MATCH / 769 ASM**, zero lint errors across 333
first-party files. Linked C object count remains **172**; both retail
SHA-1s remain exact. The superseded font archive is removed; production
source now holds the accepted body.

## Sound initializer: restore the return and pointer/size contracts

`func_0045a570` in `src/sdkSnd.c` closes at **448B/448B**, with all 112
instruction words matching. The archived seven-argument body omitted the
slot argument to `func_0045a890`, whose actual definition is `u32 (s32)`,
and discarded the initializer's constant success return.

The accepted signature is `s32 (s32, void *, u32, void *, u32, void *, u32)`.
Forwarding the raw slot word, narrowing only at table accesses, and returning
`1` reproduces retail without new compiler controls. A correctly forwarded
but void-returning control remains **448B with 28 differing words**. The
return contract, not forced temporary allocation, closes that floor.
Direct members of the existing `HsndSlotWork` match just as well as the
offset macros and avoid pointer stores through signed-word lvalues.

Both live C callers use the same recovered signature. Updating the
`mdlSE` declaration alone initially reordered six outgoing argument loads,
leaving **12 differing bytes** and tripping the **172-object linkage
floor**. Its two three-element staging arrays now hold their actual types:
`void *` data addresses and `u32` lengths. This restores the caller's
**668B/672B** match; the omitted word is only zero tail padding. The header
length and `(size + 0x3F) / 64 * 64` record advance stay signed. The battle
sound caller retains its **456B/464B** match. No caller is demoted or given
an incompatible declaration to preserve a score.

The SDK unit's diagnostic declaration also agrees with its canonical
`void (void *, s32)` definition; its three existing calls pass the file
pointer directly. Focused verification of the three changed units reports
**48 MATCH / 4 ASM across 52 functions**, with no mismatches.

A throwaway 32-bit UBSan oracle passes **486,000 cases** using the live
slot layout and readiness helper. It covers all six valid slots, eight
signed initial states, three raw upper-word patterns, independent null
and non-null payload pointers, and independent unsigned length endpoints.
An independent byte-addressed store model checks the entire result,
untouched padding, neighboring slots and both guards. It also checks raw
slot forwarding, diagnostic arguments and pre-write timing, and the
constant return. This is bounded initializer coverage, not invalid-slot,
concurrent-mutation or retail-game execution coverage. The obsolete
`S5A57` draft is removed; production holds the accepted body.

`make build verify lint-errors` passes with **7,722 MATCH overall** and
**6,092 first-party MATCH / 768 ASM**. All **172** linked C units and both
retail SHA-1s are retained; lint reports zero findings across 333
first-party files.

## Ratio conversion follow-through: paired group statistics

`func_001f5bd0` is now production C in `src/promoted/code1_001f.c`:
**708B emitted / 720B retail window, MATCH**. Removing five
unsigned-tautology branches and using native unsigned casts first
reproduced the 12-word floor. Keeping the same floating operation tree
in one expression fixed both multiply operand orders, leaving seven
executable words that exchanged the first two saved FPR results and
their division operands.

Grouping the four statistics into two local `{ stat3, stat4 }` records
closes that residual. Both records stay in FPRs; the retail 0x30 frame,
save set, five unsigned-to-float conversions and final unsigned
halfword conversion are unchanged. There is no floating reassociation,
extra aggregate storage or helper ABI change. The remaining three raw
words at `+0x2C4`, `+0x2C8` and `+0x2CC` are zero padding after the
function end label. The superseded FoA and WS05 drafts were removed.

A delegated independent oracle, tightened and rerun during integration,
passed **309,307 cases** on a 32-bit ABI with SSE scalar floating point,
contraction disabled and UBSan: 181,500 small-grid cases, 77,760 cases
around unsigned conversion boundaries, 50,000 deterministic full-word
samples, 15 flag-only cases and 32 flag-preservation cases. Mocks enforce
the four stat-query tuples and `0x80000` mask, followed by exactly one
RNG call with `0xF`; flag-only paths must call neither helper. The
reference reads input words independently and converts through exact
double precision. Halfword-backed storage, whole-buffer comparisons
and surrounding canaries check output and untouched memory, including
initially clear flags. The tested domain is indices 0–15, positive
stat denominators and RNG returns 0–14; this is not EE/FCSR or in-game
validation, nor a claim outside that domain.

The full build/verify/lint gate passed with **7,723 overall MATCH**,
**6,093 first-party MATCH / 767 ASM**, **172 source-linked units**,
both expected retail hashes and zero lint findings. Publication
reports and the README were regenerated and validated.

## Follow-through floor checks

- `func_004b5800`: a local record holding both matrix pointers produces
  the identical **324B/336B, five-word** diff as the retained scalar
  body. The two loop-order words remain; production stays ASM.
- `func_001f9cf0`: canonical whole-unit replay retains **688B/688B,
  four words**. A count/suffix record remains at eight words. Runtime
  aggregate initialization adds stack clearing/storage and grows to
  **736B/688B, 160 words**; it is rejected.
- `func_004a30e0`: separate byte-count locals and inline byte-count
  expressions produce the identical **764B/768B, ten-word** diff.
  The archive's alpha temporary is now unsigned: the original solid-row
  `255 << 24` reproduces a UBSan signed-shift failure, while the unsigned
  spelling emits identical retail-comparison instructions. Eight
  32-bit SSE/UBSan raw-layout cases pass with segments 0/8 and replica
  counts 0/1/2/4, checking lock-replaced buffers, exact copy ranges,
  whole color/coordinate images and surrounding canaries. The harness
  disables strict aliasing for the raw memory views; this is not
  EE/FCSR or in-game validation. The function remains ASM.

## Record extraction: restore the pointer-return contract

`func_00455ea0` in `src/Kernel/sdkCdvd.c` returns `u8 *` and accepts
`(u8 *, s32, s32 *)`. Its live declarations now agree with that definition.
`func_0022ced0` formerly called a void-declared extractor and fell off its
non-void body. It now explicitly returns the selected record pointer;
its cross-unit declaration also returns `u8 *`. The corrected wrapper
retains **48B/48B, zero differing words**.

Unsigned byte-count consumers retain unsigned storage and pass its
corresponding signed type to the extractor. C permits this signed/unsigned
aliasing. Changing the storage itself to signed perturbed
`func_001f7e30` and `func_00477fb0`; keeping their unsigned arithmetic
restored both matches without retaining an incompatible prototype.
Generated, uncompiled reference listings are intentionally unchanged.

The old wrapper reproduces `control reaches end of non-void function`
under GCC's `-Werror=return-type`. A throwaway 32-bit UBSan smoke compiles
the live wrapper and extractor, using native `memcpy` for the header-copy
primitive. It exercises a 65,536-record image, zero-length payloads,
lengths around 64-byte alignment boundaries, guarded size outputs,
null size outputs, negative extractor indices, and wrapper indices with
their upper 16 bits set. This is host-side record-selection coverage,
not EE or in-game execution.

The final smoke passes **115 extractor/wrapper calls**, including
corresponding signed/unsigned output storage. `make build verify
lint-errors` passes with **7,723 overall MATCH**, **6,093 first-party
MATCH / 767 ASM**, **172 source-linked units**, both expected retail
hashes and zero lint findings. No new function is promoted by this repair.

For the pending model-sound callback `func_0047e6f0`, an explicit owner
alias and a one-field owner record both retain the plain draft's
**840B/848B, 45-word** comparison. They do not resolve the saved-register
allocation and are not production candidates.

Callback follow-through: unsigned bank-size locals, with corresponding
signed pointers passed to the extractor, reproduce retail's interleaved
pointer/size argument setup. The plain draft improves **45 to 41 words**;
a local copy-context record improves **39 to 35 words** at the same
**840B/848B** size. Explicit `register` on the owner parameter, grouping
the three bank pointers, and sharing the current/node local each retain
the plain unsigned draft's **41 words**. These are measured source-shape
experiments only; at that stage the callback remained ASM and had not
passed a runtime semantic oracle.

## Model sound callback: separate inline copy lifetimes

`func_0047e6f0` is now production C in `src/Graphics/Model/mdlSE.c`:
**840B emitted / 848B retail window, MATCH**. The two remaining standalone
diff words are zero tail padding. A private inline `copyLoadedRequest`
holds the shared request-to-allocation copy sequence once. Its local
lifetimes reproduce the retail owner/node/size/source saved registers,
closing the preceding 35-word aggregate floor without register forcing,
new runtime calls, or changed load/reload boundaries.

Bank sizes remain unsigned for the consumer, with corresponding signed
output pointers supplied to the record extractor. Live callers now use
the explicit `s32 (void **)` callback declaration instead of byte-pointer,
unprototyped, or implicit declarations. The four affected units verify
**299 MATCH / 22 ASM**, with no mismatches.

A throwaway 32-bit UBSan consumer passes **384 scenarios / 481 calls**.
It runs the accepted callback and the packed-record extractor, actual
heap allocations and byte copies, with controlled readiness, release,
diagnostic and bank-consumer leaves. Checks cover complete guarded node
images, copied payloads, all three extracted bank records, inactive and
already-complete flags, optional secondary requests, pending loads,
bank setup/poll/completion transitions, and preservation of unrelated
flag bits. This is not EE/in-game execution, allocation-failure coverage,
or a callback-induced owner-mutation oracle.

`make build-progress progress lint-errors` passes with **7,724 overall
MATCH**, **6,094 first-party MATCH / 766 ASM**, **172 source-linked
units**, both expected retail hashes and zero lint findings. The
committed progress endpoints and README are regenerated and validated.
Superseded callback drafts and the throwaway smoke are removed; the
unmatched sound dispatcher drafts remain separate.

## Message initialization: preserve the text pointer

`func_00279780` is now production C in `src/itfMesManager.c`:
**768B emitted / 768B retail window, exact MATCH**. The preceding
three-word floor was a parameter-type problem, not a scheduling barrier.
The binding helper is now `void func_00279dd0(u8 *, u8 *)`; its declaration,
definition and initialization call agree. The conversion to the existing
constructor's `u32` payload representation occurs inside that helper.

The pointer interpretation is supported by the consumer: the binding value
passes through `func_00274570` into field `+0x10` of `func_002745c0`'s
descriptor. Retail `func_002740b0` loads that field at `0x002740CC` and
immediately dereferences its first byte at `0x002740D0`. This is a text
address, not an integer identifier. Generated reference declarations remain
unchanged; they are not live callers.

Using a pointer parameter restores the first-argument move before the
global-address materialization. An unsigned integer parameter still leaves
three words. Inline wrappers, grouped operands, named register locals and
array-address expressions also retain that floor; disabling common
subexpressions regresses to 168 words. The existing named zero origins and
scoped `opt_propagation off` remain necessary for constructor argument order.
No fixed-register assignments, assembly barriers or indirect-call casts
are introduced.

The affected message, font and promoted-caller units verify **195 MATCH /
7 ASM**, with no mismatches, including the retyped binding helper.
A throwaway 32-bit GCC/UBSan consumer passes **7,689 scenarios** using the
accepted initializer, binding helper and actual font-flag getter. It uses
native heap allocation and text copying, with controlled font, diagnostic,
selection and setup leaves. Checks cover the complete guarded parent image,
all queried flag combinations, preservation of unrelated bits, signed
index/count boundaries, missing records, allocation failure, empty and
missing list entries, first-match precedence, primary and secondary
replacement, binding-state restoration, and a second lookup after controlled
setup mutations. This is not EE/in-game execution or validation of the font
renderer. Superseded message drafts and the throwaway consumer are removed
after recording the evidence.

The byte-exact build and resumed `make progress lint-errors` gate pass:
**7,725 overall MATCH**, **6,095 first-party MATCH / 765 ASM**, **172
source-linked units**, both expected retail SHA-1s, and zero lint findings.
Progress endpoints and the README are regenerated and validated.

## Recursive model update: cache within call boundaries

`func_00478a30` is now production C in `src/Graphics/Model/mdlManager.c`:
**1080B emitted / 1088B retail window, MATCH**. The two standalone
diff words are trailing zero padding. The existing attachment-table view
now names its RGBA, scale, primary/secondary draw state and unsigned delay
without changing its count union, offsets or 0x34-byte allocation size.
Public function signatures and both ordinary 64-byte matrix assignments
remain unchanged.

The 175-word floor came from repeated field loads with CSE disabled, not
missing callback behavior. Local draw snapshots serve a predicate and its
immediate call. Fields are reloaded after callbacks: pending draw pointers
before final assignment, primary draw between scale and matrix update,
delay after secondary update, and child slots after eligibility and time
setup. A signed local snapshots the unsigned 16-bit delay immediately
before its positive test and decrement, preserving high-bit countdowns.

This reaches four words at 1080B: two argument-order words and two padding
words. Staging the full signed frame ID after the matrix getter, with
scoped propagation disabled, closes the executable residual. CSE remains
disabled to retain per-phase matrix addresses. An independent reviewer
confirmed these load/reload boundaries and that no frame-copy API change
was justified.

The owner and promoted-caller units verify **153 MATCH / 11 ASM**.
A throwaway 32-bit GCC/UBSan consumer passes **582 scenarios**, using the
installed function and actual model, matrix, layer and attachment layouts.
Controlled animation, draw, frame and sound leaves exercise callback-driven
pointer replacement, scale application to the old draw versus matrix
application to its replacement, delays 0/1/2/32768/65535, tick-zero behavior,
all five child slots, eligibility and pre-recursion replacement, two levels
of child recursion, and full guarded model images. Matrix checks preserve
all 64 bytes, including flags/padding, and use noncommuting transforms.
Frame IDs include -1, -2, 5 and 65537. The reviewer identified and checked
the stronger scale, multiplication-order and signed-ID oracles. This is
not EE/in-game execution or validation of the complete rendering engine.

`make build-progress progress lint-errors` passes with **7,726 overall
MATCH**, **6,096 first-party MATCH / 764 ASM**, **172 source-linked units**,
both expected retail SHA-1s and zero lint findings. Progress endpoints and
the README are regenerated and validated. The superseded recursive archive
and throwaway probes are removed; remaining model floors stay unpromoted.

## Layer animation and sound dispatch: repair lifetimes and return contracts

Both functions are now production C, with every relocated instruction
matching retail:

| Function | Owner | Emitted / window | Residual |
| --- | --- | --- | --- |
| `func_004740c0` | `src/Graphics/Model/mdlManager.c` | 1320B / 1328B | Eight zero-tail bytes |
| `func_00459ad0` | `src/sdkSnd.c` | 2316B / 2320B | Four zero-tail bytes |

For layer animation, member-first field bases and a signed promoted
`entryCount` close the former 215-word draft. The existing 80-byte animation
entry now names its control and start-frame pointers; the table remains
12 bytes. Independent byte offsets retain the requested animation across
callbacks and share the attachment-array stride. The existing `addOff`
helper preserves index-first address additions, with the blend fraction
loaded before its immediate destination calculation. CSE and propagation
remain disabled only within this function. Raw control-field writes share
the IEEE-754 representation of `1.0f`, without a synthetic FPU transfer.

An independent semantic review found no target32 blockers. A throwaway
32-bit GCC/UBSan consumer runs the installed source against a separately
structured typed-array transition model: **4,096 scenarios pass**. It checks
guarded layer/control/attachment images, interpolator state and ordered
callback events; signed indices down to -32768 use valid biased backing
arrays. Scenarios cover unsigned counts/ticks, null and sentinel clips,
both lazy interpolators, table/entry/current-index/hierarchy/interpolator
replacement during callbacks, pose-copy versus seek, missing start frames,
shared old/new controls, flag gates, secondary suppression and original
attachment ticks on the immediate-switch path.

The sound review identified the decisive missing contract: the dispatcher
returns **`s32` constant 1 on both exits**, not `void`. Retail sets and
preserves `v0`; the void declaration makes the compiler keep its prior value
live backward through paths without another call, shifting other registers.
Correcting the definition and live forward declaration closes the final
114 instruction differences. Filename helpers now use their authoritative
`void *` handle and `const char *` path signatures. Generated decompiler
references remain unchanged because they are not live callers.

The dispatcher also retains a pre-destructor handle destination and a
40-byte constructor-record view, with scoped dead-assignment elimination
disabled. Destruction does not supply the explicit zero store's value.
Re-enabling dead-assignment elimination after the return repair produces
2308B/2320B with 406 relocation-masked differing words; the scoped pragma
is still required.
A throwaway 32-bit GCC/UBSan consumer passes **1,760 scenarios** against a
separately structured channel/record oracle. It compares complete shared
backing memory, constructor records, ordered helper calls, filenames and
the success return. Coverage includes slots 0-4, all modes and signed
out-of-switch values, special root-track settings, slot-2 handle reuse,
nonzero destructor returns, zero constructor returns, callback changes to
handles/modes/control fields, and final publication.

Both consumers use the target's 32-bit pointer/layout and aliasing
conventions, with controlled external leaves. They are not EE/in-game
execution or validation of the full animation/audio middleware.
The two complete owner units verify **145 MATCH / 8 ASM**, with no
mismatches. The superseded layer draft is removed; the other model floors
remain unpromoted.

`make build-progress progress lint-errors` passes with **7,728 overall
MATCH**, **6,098 first-party MATCH / 762 ASM**, **172 source-linked units**,
both expected retail SHA-1s and zero lint findings. Progress endpoints and
the README are regenerated and validated. Completed layer/dispatcher probes,
the throwaway consumers and their target32 container are removed.

### Renderer follow-through: distinguish allocation gains from size cancellation

The saved `IDA_00479100_body.c` now replays at **1908B / 1920B,
32 relocation-masked differing words**, down from 409. A separate
modulated-alpha lifetime closes the arithmetic coloring through the first
channel conversion; stack order and immediate draw/clump snapshots account
for the earlier gains. CSE-off retains all eight normalization loads without
making the global volatile. The stale volatile requirement in the owner
comment is removed.

This remains rejected. Three redundant accumulator-zero transfer/nop pairs
add 24 bytes, while sharing the colored/uncolored draw call saves 24 bytes.
Duplicating the retail-shaped draw branch instead yields **1932B / 1920B,
180 words**. The apparent instruction-body size agreement is therefore
cancellation, not a match. No renderer runtime acceptance is claimed.

Material quantization remains at the saved **996B / 976B, 72 words**.
Bottom-up/single-pass inlining, narrower helper policies, lifetime controls
and combined quantization expressions do not remove its redundant zero
seeds without other regressions. Integer-batched stores give 980B/67 words
but change scheduling; an explicit shared zero-plus-bias expression adds
arithmetic and gives 1020B/79. The model archive metadata records the rejected
variants rather than promoting a lower score alone.

Battle order `func_001b11c0` remains **192B / 192B, five words**. ANSI and
K&R unsigned parameters, nested sort/count lifetimes, and selected allocator
controls do not close the key/index register exchange. A matched nested
sort in `func_001de370` supplies a real source convention, but transferring
that convention does not improve this target. Production remains ASM for
all three functions.

## Model sound cache: canonical lookup types and eviction lifetimes

`mdlSE.c::func_0047df40` is promoted at **420B / 432B,
normalized_diff=0**. The three words reported by the isolated comparator
are the absent twelve zero-padding bytes; every emitted instruction matches.
The superseded `LaneMdlSE_0047df40_body.c` archive is removed.

The lookup producer already defines
`void *func_00477c40(u32 type, u32 id, u32 flags)`. Active consumer
declarations now use that contract rather than the narrower, integer-returning
reconstruction. The battle-unit consumer also retains the returned address
as a pointer and uses the clone producer's `u32 *func_00478750(u8 *)`
contract. Generated reference drafts are intentionally unchanged.

Four previously matched callers exposed constant/halfword-load scheduling
changes after the prototype correction: `func_004abe80`, `func_004ac640`,
`func_002915f0`, and `func_004abc50`. A named `u32` lookup type under scoped
propagation-off preserves retail's constant-first argument materialization.
The constructors assign that local on each condition evaluation; the existing
loop shapes and lookup side effects remain intact. No incompatible call casts,
old-signature wrappers, or global optimization changes are needed.
The seven-file producer/consumer verification reports **343 MATCH, 19 ASM,
zero mismatches**.

The cache itself needs scoped CSE-off and propagation-off. CSE-off retains
the repeated slot-base and mask calculations. A promoted `u32` slot type,
a shared unsigned all-ones sentinel, and a distinct eviction index remove
unwanted copies. Narrowing the eviction-slot and loaded-tick lifetimes,
with the comparison written `tick <= minimumTick`, closes the remaining
allocation differences. Named locals preserve the recovered policy:
first qualifying slot during the initial scan, otherwise the last slot tied
for the smallest unsigned timestamp. The clock retains defined unsigned wrap.

A throwaway **32-bit native UBSan smoke** executes the installed cache body
and the real linked-list lookup body against independent typed oracles:
**78,848 cache scenarios and 1,536 lookup scenarios pass**. Coverage includes
first-free precedence over later hits, duplicate keys, live/missing entries,
invalid kinds, last-equal eviction ties, unsigned timestamp boundaries and wrap,
key truncation, lookup flags, and complete guarded record/clock images.
Lookup entry is instrumented to record calls, not replaced with a mock.
Strict aliasing is disabled for the raw-layout views; undefined-behavior
sanitization remains enabled. This is native x86 target32 evidence,
**not EE execution or in-game validation**.

### Retained compact-floor evidence

Formation `func_001d2e20` remains ASM. The cleaned
`SFRM_001d2e20_body.c` uses typed work/reference views and canonical helper
contracts, but replays at **440B / 448B, 92 differing words**. Reordered
switch labels recover comparison order without fixing the retained mode copy
or register allocation. Presence-width and optimizer variants increase size
or add instructions; none is promoted.

Shuffle `func_00375f00` remains **156B / 160B, eight words** with dead
assignments disabled. Reusing only the combined pointer instead produces
128B/38 words and loses retail's retained parent/index state.
Material `func_00476e90` remains at the saved **996B / 976B, 72 words**:
scalar-component and helper-definition-only CSE boundaries produce
948B/193 words and fail to retain all eight normalization loads.
These rejected measurements are recorded in their existing archives.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,729 MATCH overall; 6,099 first-party MATCH / 761 ASM; 172 source-linked
C objects**. Both the loadable image SHA-1
`3d1d3d2b9d6ccb60836db239ab49674223025a78` and executable SHA-1
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` remain exact.
Lint reports 333 first-party files and zero findings.

## Game-data scaling: short values in word-sized carriers

`g_data.c::func_00105010` is promoted at **396B / 400B,
normalized_diff=0**. Its isolated comparator reports only the absent
four-byte zero tail. The definition implements the existing caller contract,
`s16 func_00105010(s16 category, f32 scale)`, rather than the old archive's
register-width-derived `s64` signature.

The main lever is separating storage width from narrowing points. `remaining`
and `threshold` are `s32` carriers, with explicit signed-short conversion
where retail wraps or compares them. This prevents redundant threshold
extensions and prevents the subtraction from reusing the comparison's
narrowed temporary. Separate short `baseProgress`, `partialProgress`, and
`progress` stages under scoped propagation-off preserve the integer-chain
order, intermediate truncations, and register lifetimes.

That reaches two differing emitted words. Writing
`threshold > (s16)remaining`, rather than the reversed less-than expression,
selects retail's `$at` comparison/branch pair and closes both.
The final floating multiplication by 100 and the earlier short truncations
remain separate; algebraic cancellation would change rounding or wrapping.
The canonical segment-size helper and existing script caller are unchanged.
Focused verification reports **236 MATCH, six ASM, zero mismatches** across
the owner, helper owner, and caller unit.

A throwaway **32-bit native smoke passes 51,200 scenarios** using the
installed scaling body, the real `func_00246a50` body, and its real address
helper. An independent typed-table oracle rounds each floating stage to
binary32. Cases cover all five categories, one through five lookups,
threshold equality and adjacent values, signed-short subtraction and
progress wrapping, five-step clamping, and positive/negative scaling.
Query order and complete guarded input-table images are checked.
UBSan and float-cast-overflow sanitization remain enabled.

The smoke uses nonzero thresholds/scales and finite, in-range conversions.
It is **not EE execution** and does not validate PS2 exceptional floating-point
conversion behavior. No permanent test or input-special-case branch is added.

Nearby rejected evidence remains in the existing cut-in, projection,
initializer, and message-partition archives. Their production bodies remain
ASM. The b119 comparison changes no compiler profile; it ties the initializer
floor and regresses the projection.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,730 MATCH overall; 6,100 first-party MATCH / 760 ASM** and zero lint
findings across 333 first-party files. Both retail hashes remain exact.
The source-linked object count stays at 172; this match does not yet make
the entire `g_data.c` owner link-eligible. The superseded
`EcC_00105010_body.c` archive and throwaway smoke/probe files are removed.

## Packed-color propagation: VU bridges with C-owned state

`func_004865c0` in `src/promoted/code1_0048.c` is now **MATCH**:
**276B / 288B, normalized_diff 0**, with twelve bytes of zero tail padding.
The prior scalar reference was 396B with 91 differing words.

The recovery keeps the real VU operations instead of replacing them with
scalar floating-point arithmetic. C owns the parent color store, the aligned
parent-vector snapshot, all stack objects, linked-list traversal, callback
lookup, and the post-callback next-pointer reload. The private normalization
helper follows the existing packed-word VU bridge: `$2` is declared quadword
scratch for unpacking and transfer to VF10; the floating-point transfer uses
a compiler-assigned scratch operand.

Two details close the hardware candidate:

- The final packed-word store names the actual C local, `packedColor`, and
  declares its memory output. No literal stack offset is encoded. Using the
  generic memory operand in the instruction instead materializes an extra
  address; naming the compiler-owned slot removes that instruction.
- Reusing the existing quadword-scratch bridge, rather than inventing a
  generic scalar-register convention for the unpack operation, closes the
  remaining allocation differences. The generic candidate falls from 46 to
  15 differing words after the slot change; the established bridge leaves
  only the three absent zero-padding words.

No additional optimization pragma is needed. The producer and active C
consumers use the explicit `void func_004865c0(u8 *, s32)` contract; the
void-pointer and unprototyped declarations in the two external consumer
units are replaced. Focused verification reports **215 MATCH, 28 ASM, zero
mismatches** across the owner and both external consumer units.

A throwaway freestanding **32-bit native smoke passes 65,544 scenarios** with
the installed C body and portable models only at its hardware boundaries.
The 65,536 parent/child byte pairs are covered independently in every lane.
With scale one-half, every multiplication is exactly representable as
binary32, so the oracle uses integer arithmetic:
`((255 * parent_byte * child_byte) / 4) & 255`.
The asymmetric high-bit case `0x80030201` with child `0x04010101` produces
`0x80BF7F3F`, covering truncation and low-byte wrapping.

The remaining cases cover empty lists, null callbacks, unsigned descriptor
indices through `0xFFFF`, preserved parent/scale snapshots despite callback
mutations, clobbered modeled VU registers, link insertion/skipping/termination,
and callback changes to future colors, descriptors, userdata, and table
entries. Complete guarded object images are checked in the exhaustive pass.
UBSan and float-cast-overflow traps are enabled.

This is **not EE execution** or a general VU floating-point emulator.
Instruction identity separately proves the retained hardware sequence.
Two independent read-only reviews found no source-honesty or contract
blockers. The superseded scalar archive is removed; no permanent test or
ordinary-assembly fallback is added.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,731 MATCH overall; 6,101 first-party MATCH / 759 ASM**, and zero lint
findings across 333 first-party files. Source-linked objects remain at 172;
the promoted owner still has fourteen ASM functions and is not wholly
C-linked. The loadable image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete executable remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Line rectangles: aggregate position instead of a packed scalar

`func_0034c500` in `src/promoted/nLine.c` is now **MATCH**:
**436B / 448B, normalized_diff 0**, with twelve zero tail bytes.
The previous scalar-position archive reported normalized_diff 323.

The position is a by-value two-float `Vec2f`, following the existing external
callers' aggregate layout. This makes the compiler own the argument home at
`sp+0x38`; no explicit stack access or extra assembly is needed. Three
source details close the body:

- The aggregate parameter restores the retail prologue and saved registers.
- Capture X and Y before selecting the rectangle dimensions, rather than
  delaying their loads until the packet-builder call.
- Declare the byte color locals in blue/red/green order. Swapping red and
  green leaves eight instruction-register differences.

The aggregate-only probe has 63 differing words. Early coordinate loads
reduce that to eleven; color-local order leaves only three absent zero
padding words. Explicit packet alignment and propagation changes do not
improve the result and are not retained.

`func_0034c270` now receives `Vec2f` directly and reads its X/Y fields;
`func_0034c4a0` clears a `Vec2f` through its byte representation. Both callers
remain MATCH. Converting the former scalar argument through a temporary
union instead adds a store and grows the caller's frame, so that bridge is
not retained. The `func_0034c860` declaration accepts the same aggregate.

Existing external declarations and their integer/floating-point ordering
are intentionally unchanged: they already deliver the same position bits
through the EE register-class ABI. This is not a cross-platform ABI
canonicalization. Focused verification of `nLine.c`, `shdPersona.c`,
`cmpConfig.c`, and `cmpSkill.c` reports **141 MATCH / 23 ASM, zero
mismatches**.

A throwaway native smoke extracts the five installed C bodies: the
renderer, both local callers, rectangle construction, and command dispatch.
Clang ASan, UBSan, and float-cast-overflow checks pass **526 scenarios /
10,520 quads**. Coverage includes all byte alpha values with fractional
truncation, signed palette indices, both dimension choices, optional setup
ordering, nonzero aggregate positions, zero-position construction, and the
caller's depth reset. Dispatch mutations change later coordinates,
dimensions, palette bytes, mode, camera scale, and depth; subsequent draws
observe those changes.

Packet writing, camera access, and auxiliary setup are modeled boundaries.
The smoke is not EE execution and does not establish exceptional-float or
cross-TU native ABI behavior. Alpha inputs stay within the defined C
float-to-byte conversion range. The superseded scalar archive is removed;
no permanent test or new optimization pragma is added.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,732 MATCH overall; 6,102 first-party MATCH / 758 ASM**, and zero lint
findings across 333 first-party files. The rebuilt `nLine.c` object is linked
from source; source-linked objects remain at 172 and C-linked functions rise
to 1,560. Both retail SHA-1 values remain exact:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` for the loadable image and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` for the complete executable.

## Line setup: preserving aggregate and arithmetic lifetimes

`func_0034c860` in `src/promoted/nLine.c` is now **MATCH**:
**1,672B / 1,680B, normalized_diff 0**, with eight zero tail bytes.
The complete retail instruction stream and IDA control flow establish the
eighteen setup choices and the secondary geometry selector.

The by-value `Vec2f` parameter removes the former address-hoisting spill
floor. Its aggregate assignment also reproduces the two floating-point
loads and stores into the owner's position fields. The existing `addF`
inline helper keeps the repeated 448-unit height additions separate rather
than caching their result in an extra saved floating-point register.

One remaining expression lifetime matters in secondary mode 2. The compiler
otherwise delays `(640.0f - extent) - position.x` until after two vertex
callbacks. A private inline `subF` boundary, following the existing `addF`
pattern, keeps that subtraction before the calls. The correctly typed
aggregate/addition candidate has 187 differing words; this final boundary
leaves only the two absent zero-padding words. Both helpers compile away
into the retail scalar arithmetic. No register pinning, stack assembly,
volatile storage, padding object, or optimization pragma is added.

The `func_0034db60` declaration is floats-first to match its four setup-call
sites. Other setup helpers retain their existing contracts. Focused
verification of the owner and existing external consumer units reports
**142 MATCH / 22 ASM, zero mismatches**.

A throwaway smoke executes the installed renderer and arithmetic helpers
under Clang ASan, UBSan, and float-cast-overflow checks:
**4,255 scenarios / 7,420 vertices**. It covers all eighteen setup choices,
secondary modes 0–4, invalid signed selectors, byte narrowing from wide and
negative alpha carriers, signed timing boundaries, and negative-zero
position storage. The oracle checks helper selection, direction, scale,
vertex offsets, geometry, color, and callback order.

Initializer mutations replace the owner/table selector, stored position,
stored alpha, extents, depth, and camera scale. The original by-value
position, alpha, and selected secondary mode remain captured. Easing
mutations affect the later coordinate load; camera mutations preserve the
already captured depth while changing the returned scale. Vertex mutations
do not corrupt the remaining vertices' snapshots.

Setup helpers, easing, camera access, and vertex output are modeled
boundaries, not EE execution or an exceptional-floating-point emulator.
The stale scalar-floor comment and temporary experiments are removed.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,733 MATCH overall; 6,103 first-party MATCH / 757 ASM**, and zero lint
findings across 333 first-party files. The updated renderer is in the rebuilt
source-linked `nLine.c` object. There are 172 source-linked objects and 1,561
C-linked functions. Both retail hashes remain exact:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` (loadable image) and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` (complete executable).

## Translated rectangles: capture alpha before narrowing

`func_0034e0b0` in `src/promoted/nLine.c` is now **MATCH**:
**468B / 480B, normalized_diff 0**, with twelve zero tail bytes.
The faithful archived candidate had 35 reloc-masked differing words.

The alpha read must remain before `func_00457120`; moving it after that
callback changes observable behavior. Capture the byte in a `u32` local,
then narrow it into a separate `u8` after the camera callback. This keeps
the original read timing while reproducing the saved-register allocation
and the later `andi`. The existing `addF` helper preserves each corner
addition and its operand order. No new helper, optimization pragma,
register binding, padding object, or assembly is needed.

All 117 emitted instruction words agree with retail. The isolated fndiff
reports only three absent zero-padding words; owner verification accepts
the retail zero tail. The owner and existing external consumer units report
**143 MATCH / 21 ASM, zero mismatches**. Signatures and callers are unchanged.

A throwaway native smoke runs the installed arithmetic under Clang ASan,
UBSan, and float-cast-overflow checks: **23,040 scenarios / 92,160 vertices**.
It covers every alpha byte, negative and fractional translations, and
negative, zero, fractional, and greater-than-one transition factors.
Camera and vertex callbacks mutate position, alpha, depth, and camera
scale; the remaining vertices retain their captured values.

The oracle also checks the retail distinction between the **480-unit
vertex height** and the **448-unit `func_0034e360` height**. Both later helpers
receive the original translation parameters, not reloaded owner positions.
The returned vertex count is stored as 16 bits before `func_0034ee90`, and
the owner state at `0x990` is left unchanged.

Camera access, vertex output, decoration, and transition helpers are modeled
boundaries. This is not EE execution or exceptional-float emulation.
The superseded floor archive and temporary smoke artifacts are removed.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,734 MATCH overall; 6,104 first-party MATCH / 756 ASM**. The rebuilt
`nLine.c` object is linked from source; there are 172 source-linked objects
and 1,562 C-linked functions. Progress snapshots validate, and lint reports
zero findings across 333 first-party files. Both retail hashes remain exact:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` (loadable image) and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` (complete executable).

## Decoration mesh: preserve the full return counter

`func_0034e360` remains ASM. The measured typed reconstruction is retained
in `docs/probe_archive/VNLN_0034e360_body.c`: **2,648B / 2,656B,
normalized_diff 336**. This is not a padding-only floor. Scalar geometry
scores 339; register hints do not improve either form.

Retail moves its full vertex counter into the return register, without
signed-short narrowing. The canonical declaration in `src/promoted/nLine.c`
now returns `s32`; rectangle callers retain their explicit 16-bit store at
`0x1670`. Owner verification remains **25 MATCH / 3 ASM, zero mismatches**.
A native smoke of the installed translated caller checks nine signed
32-bit boundary values, including negative values and values above 65535:
the low 16 bits are stored before the transition callback.

Decoration styles use 44-byte records: a signed count, five palette
indices, and five floating-point distances. Styles 1–4 emit one initial
triangle and four triangles per subsequent entry; style 5 traverses entries
backwards and emits two triangles per entry.

An independently indexed triangle-mesh oracle passes **16,800 scenarios /
120,960 vertices** under Clang ASan, UBSan, and float-cast-overflow checks.
It covers translated edges, empty edges, custom rectangles for style 5,
nonpositive and positive counts, selected entries, and alpha boundaries.
Mutating callbacks distinguish entry-level alpha and palette-pointer
snapshots from per-vertex RGB reloads; they also check the capture timing
of mode, selected entry, count, depth, and camera reciprocal.

Custom-size styles 1–4 are deliberately excluded: retail leaves direction
values unset on that path. The candidate neither invents initialization nor
adds a guard. Camera, vertex, and diagnostic callbacks are modeled boundaries;
this is not EE execution or exceptional-float emulation.

Full acceptance: `make build-progress progress lint-errors` passes after
the declaration repair. Counts remain **7,734 MATCH overall; 6,104
first-party MATCH / 756 ASM**, with 172 source-linked objects and 1,562
C-linked functions. Both retail hashes remain exact, progress validates,
and lint reports zero findings across 333 first-party files.

## Archive discovery: do not parse lane prefixes as addresses

`recon_pool.py` previously took the first eight hexadecimal characters in
an archive filename. For `UnC001d7c60au_001d7c60_body.c`, that produced
`C001d7c6` instead of `001d7c60`, incorrectly scheduling an archived function
as fresh work.

The parser now recognizes whole eight-digit hexadecimal runs. Ambiguous
or embedded names are resolved against `func_`/`FUN_` symbols that also
occur in the filename; unresolved names are not guessed. Legacy embedded
names, uppercase addresses, `.c.txt` archives, and unambiguous partial
bodies remain supported.

The fresh-pool regression fails before the fix and passes afterward.
The real CLI's first-party pool up to 4,096 bytes changes from 403 to 402:
`func_001d7c60` is excluded, with no previously excluded function becoming
fresh. All **520 Python tests** pass. Fresh means no recognized archived
C body, not proof that a function has never been attempted.

Archive scores remain historical claims. In this pass the purported
four-word `func_0014efc0` floor replays at **836B / 848B, normalized_diff
135** after restoring its archived data declarations. Measure the target
body in its current owner before treating a filename or note as evidence
of a nearly complete match.

## Persona digits: aggregate coordinates and unsigned number fields

`func_00117310` is now source C in `src/promoted/shdPersona.c`:
**388B / 400B, zero differing instruction words**. The three raw fndiff
differences are absent retail zero-tail words. `Vec2f` by value retains the
packed `$a0` coordinates; the float-second parameter remains in `$f12`.
Direct packed-color parameter access, unsigned number/resource locals and
scoped loop invariants reproduce the retail prologue and digit-loop setup.

The caller cutover matters independently. With the new `u32` number
parameter, its former signed number-field load moves ahead of the packed
coordinate setup, changing four instruction words. Reading the existing
field at `persona + 0x38` as `u32` restores the retail argument order.
`func_00116610` now uses a real `Vec2f` local and passes it directly:
**524B / 528B, zero differing instruction words**. The remaining word is
retail zero padding. Full owner verification reports **89 MATCH / 13 ASM,
zero mismatches**. Independent review confirms the C and ASM caller ABI;
the ASM caller is unchanged.

A throwaway native smoke of the installed renderer passes **1,474,560
scenarios / 6,021,120 sprites** under Clang ASan, UBSan and
float-cast-overflow checks. A decimal-string oracle checks least-significant
digit first, zero's single draw, unsigned values through `UINT32_MAX`,
full-width nonzero modes, all alpha bytes, RGB order and inverse alpha.
Finite-coordinate cases include signed zero and magnitudes where repeated
16-unit additions round differently from a multiplied offset. Diagnostic
and drawing callbacks mutate caller-owned inputs; emitted records retain
the original by-value coordinates, number, resource, color and scale.
Renderer and diagnostic helpers are modeled boundaries, not EE execution.

The parallel `func_00311930` recovery remains ASM: **596B / 608B, five
differing instruction words** at `0x70`, `0x74`, `0x88`, `0x8c`, `0x90`,
plus three absent zero-tail words. Only float-to-byte conversion temporary
registers differ. Its retained `C31B_00311930_body.c` archive now has the
reviewed `(u16, u8 *, s8) -> s32` contract. A native smoke passes **42,735
scenarios / 204,435 helper calls**, checking separate rank snapshots,
assignment rather than accumulation, fractional truncation, division order,
late multiplier lookup, narrow scaling flag and an input-only persona
pointer. Semantic equivalence does not qualify this floor for promotion.

The superseded `FPSHD_00117310_body.c` and `EcD_00117310_body.c` archives
remain tracked as historical recovery work. Their hypotheses cannot be
regenerated from the retail ELF; the installed shader body is the canonical
production reconstruction.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,735 MATCH overall; 6,105 first-party MATCH / 755 ASM**. Progress
snapshots validate, and lint reports zero findings across 333 first-party
files. Both retail hashes remain exact:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` (loadable image) and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` (complete executable).
`shdPersona.c` remains outside the source-linked object set: this is an
instruction-match promotion, not newly C-linked code. The linked totals
remain **172 source objects / 1,562 C-linked functions**.

## Retail assembly: prove regeneration before untracking

The fallback audit covers all **11,154 tracked files / 62,635,980 bytes**,
including historical and duplicate copies, not just current `INCLUDE_ASM`
consumers. Every working file matched its Git blob at the start of the audit.
An independent path/SHA-256 inventory agrees with every manifest entry.

`tools/regenerate_asm.py` reconstructs **11,152 files** using the pinned
Python dependencies, validated private retail ELF, fresh scratch split,
tracked symbols and canonical windows. It does not read existing fallbacks,
existing bulk splits or ignored local configurations as generator inputs.
`config/generated_asm.json` retains expected hashes and reconstruction
recipes rather than another copy of the disassembly.

The recipes are 8,822 direct slices, 2,300 canonically named slices and 30
retail-word syntheses using the existing extractor. Compact corrections
preserve eight historical adjacent-nullsub spans, eighteen symbol-spelling
sets, six glabel spellings and one retail-word repair. Unexplained output
drift is a failure, not permission to replace the expected hash.

Two hand-maintained files remain tracked and are never regenerated:

- `asm/nonmatchings/btlVoiceCreatePacket.s`: explicit relocations.
- `asm/nonmatchings/cldDayChange/func_00266050.s`: hand-carried jump table.

Assembler support and C probe archives also remain tracked. Disassembling
the ELF cannot recover C hypotheses, measurements or human decisions.

A separate clean Git checkout of `f9911051` was stripped of every classified
generated fallback before execution. It had only the two retained files,
no private input copy, no previous split and no local build/verify config.
Supplying only the retail ELF and pinned public Python environment recreated
all **11,152 generated files**; all **11,154 final path/hash pairs** equalled
the independent pre-cutover baseline, with no tracked-file drift.

Real CLI refusal scenarios preserved the complete file snapshot when a
generated file was edited, an unclassified handwritten file was present,
or a retained manual file was missing. All **523 Python tests** pass.
The proprietary CI path performs guarded fresh-output regeneration before
building and verifying; its actual successful run is required before
removing any generated file from Git.

The pre-cutover proprietary CI run
[`34070057851`](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34070057851)
passed on `f9911051` while all fallbacks were still tracked. Its log records
11,152 exact regenerated files, two retained files, both retail hashes
unchanged, and **7,735 overall MATCH / 6,105 first-party MATCH / 755 ASM**.
Only after this result are the manifest-generated paths removed from Git's
index, with their local files preserved and the two manual exceptions kept.

## Field resource loader: complete stream descriptors and callback ordering

`func_00150ce0` in `src/Kosaka/Field/k_fldResource.c` matches every emitted
instruction: **988B / 992B**, with four bytes of retail zero tail. The
historical `LFR_00150ce0_body.c` archive remains preserved. Its fresh replay
is **956B / 992B, 219 fndiff words**, not its old four-word claim.

The recovery closes three real source issues:

- `func_003df3c0` writes the complete 20-byte `RwChunkHeaderInfo`, not one
  scalar. Both memory-stream descriptors also require their actual two-word
  storage. The definitions in `rwplcore.h` and `RwStreamReadChunkHeaderInfo`
  corroborate this layout; the stream-open implementation copies both
  descriptor words rather than retaining their stack address.
- A `while` loop places the initial test and backedges correctly. The chunk
  byte length is unsigned, as in RenderWare. Correcting that type closes
  five repeated argument-setup pairs without register pinning.
- Cases 11 and 16 explicitly open the child stream, snapshot the resource
  destination, construct the queued task, then reload the destination's
  index. Cases 22 and 12 explicitly load their destination after construction.
  These statement boundaries preserve the retail ordering without relying
  on the host compiler's assignment-operand evaluation order.

The case-11 descriptor start is intentionally refreshed only when its
existing entry is zero. A later nonzero entry can reuse the previous child
descriptor; unconditional refresh or invented initialization is not equivalent.
Case 35 invokes the texture callback before destroying its dictionary and
does not perform the ordinary chunk skip. Only the outer stream is closed
here; queued child streams are consumed by `sdkWrap.c` and closed later by
`func_001510c0`.

The installed body passes **1,127 consumer scenarios** at real 32-bit pointer
width and the same **1,127 scenarios under Clang ASan/UBSan** with low-address
64-bit host storage. Coverage includes all dispatch cases, unknown chunk
types, full-width unsigned skip lengths, child-open and task-construction
failures, no-data and outer-open failure paths, empty streams, retained
case-11 descriptors, and resource/index mutations across helper calls.
The failure cleanup also reloads the resource after closing its file.
The owner verifies **16 MATCH / 5 ASM**, with no mismatches.

Two parallel recoveries remain deliberately unpromoted:

- `VpadTyped_004b5800_body.c`: **324B / 336B**; two executable `lw`/`sll`
  schedule differences and twelve zero-tail bytes. Its paired matrix IDs
  remain full-width: `func_0047a510` narrows only on one path, while its
  alternate lookup uses all 32 bits. The live `void(u8 *)` boundary is kept.
- `InitTyped_00484b30_body.c`: **120B / 128B**; six executable `v0`/`v1`
  coloring differences and eight zero-tail bytes. All five inspected callers
  discard the initializer result. A fabricated return is not a legitimate
  allocation fix. The four VF0 stores remain genuine hardware bridges;
  scalar defaults and the full quadword copy remain C.

Both typed candidates were independently checked against retail helpers and
callers, then remeasured with their owning translation-unit settings. Their
historical `W47Vpad` and `F480` archives are retained alongside the new evidence.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,736 MATCH overall; 6,106 first-party MATCH / 754 ASM**. Progress snapshots
validate and all 333 first-party files are lint-clean. The source-linked
totals remain **172 objects / 1,562 functions**. Both retail SHA1s are unchanged:
`3d1d3d2b9d6ccb60836db239ab49674223025a78` for the loadable image and
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` for the complete executable.

The published field-loader commit `95b0528a` also passes proprietary CI
[`34073398344`](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34073398344):
11,152 fallbacks regenerate exactly, both manual files remain unchanged,
and the build reproduces both retail hashes and the 6,106/754 first-party count.

## List comparator: signed indices and repeated selector lifetimes

`func_002e6630` in `src/Yajima/y_list.c` matches **640B / 640B**, with no
padding gap. All **44 entries in its four jump tables** also reproduce the
retail function-relative destinations. The existing
`s32(s16 *, s16 *)` comparator ABI needs no migration.

Each signed 16-bit index has a 48-byte entry offset reused across its pair
of selector dispatches. Types 0/2/7/8 use the array at `base+0x14`;
1/5/6/10 use `base+0xA4`; the other cases and out-of-range selectors use
the first array. The key is the unsigned value
`entry[4] + 100 * metadata[14 * entry.u16_at_2 + 2]`, narrowed to 16 bits.
Lower keys sort first and equal keys return zero. Scoped optimization level
1 preserves the retail offset and key lifetimes; level 2 is restored afterward.

The installed comparator passes **118,720 pair checks** and **28 real
`qsort` batches / 615,668 qsort comparator calls** under Clang ASan/UBSan.
The smoke covers all selector cases, signed-index boundaries, byte-valued
key components, equal keys, changed metadata roots, ordering and permutation
preservation. Owner verification is **30 MATCH / 7 ASM**. The exact C
recovery is retained in `ListSort_002e6630_body.c`; the obsolete source note
pointing at a missing build-only predecessor is removed.

The parallel shop-digit recovery is preserved in
`ShopDigits_002caa10_body.c`, but remains ASM: **696B / 704B**, with
**34 executable saved-register differences** and eight zero-tail bytes.
Its caller-backed ABI uses `Vec2f`, depth, value `RGBA`, an unsigned 32-bit
number, a signed-16 base glyph, sprite and style. Digit and comma glyph
offsets are not narrowed again after addition. Natural compiler spills
already reproduce the retail SQ/LQ slots; artificial wide locals or a
combined dummy stack structure are unnecessary.

The actual copied GP string is space plus NUL. Its two-byte declaration
reproduces GP-relative addressing; the destination's `text[16]` bound is
inferred from real stack storage, not uniquely proven. First-use declaration
order, direct initializers and short-width storage do not close the residual.
Combining repeated width-subtraction branches changes the control-flow graph
rather than fixing allocation. The source annotation now records these
measured facts instead of its stale, incorrect parameter order.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,737 MATCH overall; 6,107 first-party MATCH / 753 ASM**. The committed
progress snapshots validate and all 333 first-party files remain lint-clean.
Source-linked totals remain **172 objects / 1,562 functions**; the loadable
SHA1 is `3d1d3d2b9d6ccb60836db239ab49674223025a78` and the complete ELF SHA1
is `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

The published comparator commit `ad5ffd9f` also passes proprietary CI
[34075194170](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34075194170):
11,152 exact fallback regenerations, both manual files unchanged, and the
same retail hashes and 6,107/753 first-party count.

## Relocated model and battle-order floor replay

Neither model candidate is promoted. The material-color routine
`func_00476e90` still emits **996B** against **972 executable retail bytes
plus four zero-tail bytes**. Its 72 fully relocated differences comprise
66 same-offset executable words, one retail padding slot and five words
beyond the window. All actual relocation sites match, including the eight
normalization loads. Four accumulator-zero seeds remain instead of retail's
one. `QuantSeed_00476e90_body.c` preserves the current-owner `RwRGBA` version;
the older private-view archive remains intact.

The renderer `func_00479100` reproduces **1,908 executable bytes / 1,920B
window**, but has **30 fully relocated executable differences**, at every
word from `+0x48c` through `+0x500`, plus three missing zero-tail words.
Its 32-word relocation-masked score is not an acceptance result: masking
hides a candidate `jal func_0047d8a0` where retail has `lw` at `+0x4f4`.
Duplicating the draw branch remains **1,932B / 180 masked words**.
`IDA_model_followthrough.json` now distinguishes these resolved executable
differences from padding. Neither floor has runtime semantic acceptance.

The battle-order routine `func_001b11c0` retains its **192B / 192B,
five-word register-coloring floor**. Parameter-key reuse and reversed filter
comparison tie; scan/index reuse, postincrement and inline predicates are
worse. The retained C body and production ASM fallback are unchanged.

## Community flag rebuilding and indexed font insertion

`func_00106f40` closes the last ASM fallback in `src/cmmCommunity.c`:
**356 executable bytes / 368B retail window**, with all 16 relocations
applied exactly and twelve zero-tail bytes. The inline clear helper owns
the masked ID, its assertion and the 13-iteration loop. That source boundary
produces retail's record/ID/index saved-register allocation without register
pinning. The explicit `s32 func_001077f0(s32)` forward declaration agrees
with its existing definition; the old prototype-regression note is stale.
Owner verification is **39 MATCH / 0 ASM**.

The unchanged recovery passes a real-i386 smoke with **7,680 scenarios /
1,442,432 checks**. It includes the actual flag setter, independent predicate
combinations, low-16 ID boundaries with nonzero/sign-bearing upper bits,
null records, unsigned rank boundaries and rank mutation by the first enable
callback. Final keyed flags, untouched neighbors, record canaries, the
target's two zero-ID diagnostics and clearing before null return are checked.
The rank load must remain after that callback. Lookup, predicates, diagnostic
sink and flag storage are fixtures, not full engine integration.

`func_002739e0` in `src/frFont.c` matches **724 executable bytes / 736B
window**, with all 20 relocations applied exactly and twelve zero-tail bytes.
It reuses the neighboring insertion routine's branch settings and the
existing `FrFontNode`/`FrFontGlyph` layouts. The actual `s8 glyph[3]` array
preserves two-byte glyphs and their terminator without an artificial stack
aggregate. Unsigned left shift followed by target signed right shift retains
the retail byte extraction without signed-left-shift undefined behavior.
The legacy symbol `D_0076380C` resolves to **0x007637FC**, not its
name-derived address. Owner verification is **54 MATCH / 3 ASM**.

Its unchanged recovery passes **10 real-i386 consumer scenarios**: null/empty
strings, ASCII-space substitution, mixed two-byte text, signed spacing,
existing glyph widths, style changes, linking and allocation failure.
Eight are ordinary fixture scenarios; two deliberately return an allocated
empty node and establish behavior under that helper result, not reachability
through the actual retail helper. A separate failed-glyph process reports
diagnostic **1731**, then faults with **SIGSEGV**, preserving retail's lack
of recovery. The null style-transition branch and diagnostic 1691 are not
exercised; no artificial boundary injection was used. These are consumer
smokes, not full font/resource integration or MIPS execution.

Both recoveries pass independent source/retail review. Exact bodies are
retained in `CommunityFlags_00106f40_body.c` and
`FontString_002739e0_body.c`; historical C archives remain intact.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,739 MATCH overall; 6,109 first-party MATCH / 751 ASM**. Progress
snapshots validate and all 333 first-party files remain lint-clean.
Source-linked totals remain **172 objects / 1,562 functions**. The loadable
SHA1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1
remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Published commit `302f1114` passes proprietary CI
[34077512256](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34077512256):
11,152 fallbacks regenerate exactly, both manual files remain unchanged,
and the build reproduces both retail hashes and the 6,109/751 first-party count.

The typed virtual-pad and initializer floors were also replayed in their
current full owners with relocations applied. Virtual pad remains **324B /
336B, two executable `lw`/`sll` differences**; a producer-backed request
layout gives four differences, while an inline request-call boundary gives
320B/62. The initializer remains **120B / 128B, six executable register
differences**. A named quad snapshot ties; SDK byte-channel stores and an
aggregate worsen the result, the latter introducing an unresolved anonymous
literal rather than a legitimate retail match. Separate inline count/sort
boundaries likewise leave battle order at **192B / 192B, five masked words**.
These hypotheses are recorded in the existing archives without replacing
their C bodies or promoting any of these three fallbacks.

## Weighted combination choices and packed battle modifiers

`func_00303de0` in `src/Event/Fcl/y_fclCombine.c` matches **740 executable
bytes / 752B retail window**, with all eight relocations applied and twelve
zero-tail bytes. Its real stack buffers are **five s32 weights and five s8
IDs**. The IDA frame aliases are not additional array entries. A named
compact-store pointer preserves the stack-base addition; `(s16)weights[k]`
produces the retail signed halfword load without type punning.

The selected row is snapshotted in the 32-bit integer address domain before
the month/day/calendar calls. Selector `-1` therefore does not form a
before-table C pointer. The selector is read again afterward, while a
nonnegative-to-nonnegative change still uses the original row address.
Weight-100 choices are appended immediately in encounter order; other
nonzero-ID choices compact into the buffers. RNG is called only when that
weighted count is nonzero. Total and modulo are unsigned; the roll and
cumulative sum retain their signed-16 narrowing. The caller does not consume
a return value, so the recovery does not reproduce IDA's incidental result.

The unchanged source passes **1,363 real-i386 scenarios at each of -O0 and
-O2**, with **28,102 assertions per run**. Checks cover complete weighted
thresholds and modulo wraparound, guaranteed/mixed/empty rows, all five slots,
signed IDs and weights, ignored upper word bytes, selector changes during
each callback, count-reset timing, exact output order and untouched context,
table bytes and canaries. A zero-total sample at selected-row index 66 was
excluded from native execution; the bounded samples do not prove the table's
declared extent or that row's runtime reachability. No host modulo-zero
behavior or protective guard is invented. Owner: **23 MATCH / 18 ASM**.

`func_00233570` in `src/Main/Battle/Data/datCalc.c` matches **784B / 784B**,
including all fifteen relocations and with no tail gap. It retains the
existing `s64(u8*, s32, s64)` contract and pure-C `PTDatCalcOffsetAdd`
convention. The standalone signed-byte promotion at the getter branch
merge closes the last eight register-coloring differences. Index and delta
still use their effective unsigned/signed byte values; the result sign-extends
the signed byte. The packed encoding maps 8..15 to -7..0, clamps updates to
[-1,1], preserves the opposite nibbles and updates only the corresponding
flag and auxiliary nibble. All five retail diagnostic sites remain.

Its unchanged source passes **2,148,352 real-i386 cases**, covering every
encoded nibble, the full byte-delta range, high-bit argument aliases, read-only
queries, clamping and chained transitions. Whole-unit bytes and surrounding
canaries are checked. Flag-only indices 16..23 still set their bit on zero
delta. Index 24 logs 1142 before its defined-width continuation; masked
indices 25..255 are not native-tested, including the signed/oversized-shift
hazards at 31..255. Owner: **68 MATCH / 12 ASM**.

Both recoveries pass independent source/retail review. These native consumer
smokes do not claim full-game or MIPS execution. Exact C bodies are retained
in `ComboWeights_00303de0_body.c` and `BattleNibble_00233570_body.c`.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,741 MATCH overall; 6,111 first-party MATCH / 749 ASM**. Progress
snapshots validate and all 333 first-party files remain lint-clean.
Source-linked totals remain **172 objects / 1,562 functions**. The loadable
SHA1 is `3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1
is `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Commit `b26c588c` also passed
[CI 34079993775](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34079993775).
The proprietary job regenerated 11,152 exact fallbacks, preserved both
hand-maintained files, and reproduced both retail hashes above.

## Filtered record selection and rotated quad drawing

`func_00247900` in `src/cmmMisc.c` matches **796 executable bytes / 800B
retail window**, including all twenty resolved relocations. The remaining
word is unreachable alignment padding. Ordinary `s32` target and threshold
lifetimes reproduce the two compiler-generated `sq/lq` spills; no artificial
wide locals or stack padding are needed. The existing linker binds the
static GP pointer to the runtime table slot at `0x007644C4`.

Count mode (`index == -1`) scans IDs 1..255 without allocation. Eligibility
compares a signed-byte target with an unsigned-byte category, excludes
flags 8/16, and requires unsigned-halfword rank 10 for flag 64. The result
includes all eligible records at or below the byte threshold plus the first
ID at the nearest higher level. Indexed mode recursively counts, allocates,
rescans, exchange-sorts by unsigned level, returns one ID, and frees the
temporary list. Equal-level order is not stable. Allocation failure returns
the count; indexes below -1 remain unchecked. Capacity diagnostics retain
the retail unconditional write afterward rather than inventing a guard.

The integrated source passes **29 real-i386 calls / 47,947 assertions at
each of -O0 and -O2**. Twenty-six distinct scenarios cover filtering,
threshold/rank narrowing, tie ordering, all fixture indexes, allocation
failure and zero-size allocation, callback-visible table replacement and
mutations, both capacity diagnostics, selected-ID loading before free, and
table/surplus canaries. Surplus storage makes diagnostic continuation safe
in the fixture; this is not proof of safe retail heap overflow. Negative
indexes below -1, high-half addresses and exhaustive 255-record occupancy
are not exercised. Owner: **56 MATCH / 1 ASM**.

`func_00364c90` in `src/shdMisc.c` also matches **796 executable bytes /
800B window**, with all twenty-one relocations resolved and one alignment
word. Its position is a two-float value in `a0`; depth, width, height and
angle use `f12`..`f15`, while color and mode use `a1`/`a2`. Real geometry
snapshots `[-0.5,-0.5,+0.5,+0.5]`, scoped loop-invariant optimization and
disabled propagation recover the load/store schedule and FP lifetimes.
The existing four-by-sixteen-float vertex convention is reused.

`include/shd_misc_internal.h` now supplies the shared `Vec2f` and drawing
signature. Both promoted C callers pass that value directly rather than
type-punning it through `s64`; their depth/color argument order is migrated.
The unused legacy declaration in `btlPanelCursor.c` uses the same interface.
All five affected owners verify together: **270 MATCH / 55 ASM**, with no
caller regression. The drawing owner itself is **5 MATCH / 5 ASM**.

The integrated drawing body passes **67 native x86-64 cases / 3,230
assertions at each of -O0 and -O2**, with trapping undefined-behavior checks.
Consumer callbacks inspect only initialized vertex fields and check full
dimensions, vertex order, rotations, runtime depth/reciprocal snapshots,
unsigned color channels, callback replacement and 64-bit state mutations.
The mode/alpha gate clears bit `0x80` afterward, even if initially set; it
does not restore the entry state. High bits and unrelated callback changes
survive. The host fixture uses a float tolerance for XY and does not claim
PS2 accumulator/libm equivalence or graphical acceptance. Its libc-based
i386 build was unavailable because 32-bit headers were missing.

Both bodies passed independent source/retail review. Durable C is retained
in `RecordSelection_00247900_body.c` and `QuadDraw_00364c90_body.c`; these
native consumers do not claim full-game or MIPS execution.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,743 MATCH overall; 6,113 first-party MATCH / 747 ASM**. All 334
first-party files are lint-clean and progress snapshots validate.
Source-linked totals increase to **172 objects / 1,564 functions**.
Both retail identities remain exact: loadable SHA1
`3d1d3d2b9d6ccb60836db239ab49674223025a78`, complete ELF SHA1
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Commit `405c7eb5` passed
[CI 34081495169](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34081495169).
Its proprietary job regenerated all 11,152 exact fallbacks, retained the
two hand-maintained files, and reproduced both retail identities.

## Font pool allocation and render traversal

`func_00270fb0` matches **860 executable bytes / 864B retail window**, with
all **62 relocations** resolved and one unreachable alignment word.
The existing `GslListNode` moves unchanged from function scope to file
scope: six 32-bit data fields, previous pointer at `0x18`, next at `0x1C`,
size `0x20`. It is not a `FrFontNode` or `FrFontGlyph`. Signed global
accesses, disabled propagation and enabled loop invariants recover the
bare-LUI schedule without caching mutable global values.

The routine preserves signed width-times-height division toward zero,
forward-then-reverse circular linking, fixed-point rectangles and optional
per-entry auxiliary slices. A nonzero head and flag reject reinitialization;
otherwise old allocations are not freed first. Auxiliary failure continues
with zero entry pointers. Auxiliary size zero leaves the auxiliary global
stale. Primary failure and the unsigned zero-count linking bound remain
unsafe; no protective fallback or invented cleanup is added.

The integrated source passes **19 safe native-i386 scenarios at each of
-O0 and -O2**, plus two isolated hazard processes per optimization.
The latter observe native SIGSEGV for primary-null allocation and zero
count, not a claimed PS2 fault address or behavior. Across **42 executions**,
the consumer checks 104 circular-node visits, 103,360 complete-buffer bytes,
rectangle/auxiliary layout, guarded second calls, callback/global snapshots
and mutation-visible count/head/allocator-slot loads. Wrapped-address cleanup,
signed overflow, negative counts and negative auxiliary sizes are not
certified by this fixture.

`func_00273170` matches **824 executable bytes / 832B window**, with all
**11 relocations** resolved and two alignment words. A normal `s32` spacing
snapshot retains the signed-byte load across callbacks. Reversing the
five long-lived local declarations closes the saved-register mirrors;
staged raster inputs under disabled propagation close argument scheduling.
The unsigned alpha comparison and unsigned fixed-point shift preserve the
retail operations. Raster evidence identifies byte `0x14` as a palette
index and bytes `0x18`/`0x19` as width/height.

State setup precedes even the null-root return. Root `+0x2C` and node/glyph
`+0x28` links are distinct from the existing node's `next` at `+0x24`.
The callback table address is retained, but its function slot reloads on
each call. Raster arguments see update-helper mutations; alpha reloads
after drawing. Nonzero alpha advances the wrapping 16-bit counter, while
alpha below 255 marks the whole traversal incomplete. Terminal-node wait
codes, input callbacks, signed totals and the late global delay remain intact.

The integrated body and real matched wait helper pass **831 native-i386
scenarios / 3,156 checks at each of -O0 and -O2**. Coverage includes all
256 spacing bytes, high-bit mode aliases, negative advance/coordinates,
counter wrap, callback-swapped links and render slots, 504 wait combinations,
late totals/delay mutations and valid decoy links at the wrong offsets.
The raw-layout fixture disables strict aliasing and does not certify
arbitrary signed arithmetic overflow or PS2 floating-point behavior.

`include/fr_font_internal.h` provides both recovered interfaces. The six
external render-caller translation units now use the owner's established
C signature, replacing incompatible/implicit declarations; integer handles
cross the pointer boundary explicitly. All seven affected owners verify:
**197 MATCH / 16 ASM**, with the font owner now **56 MATCH / 1 ASM**.
Independent review accepts the bodies. Exact C is preserved in
`FontPoolRecovery_00270fb0_body.c` and `FontState_00273170_body.c`.
These consumer experiments do not claim graphical or MIPS execution.

The last common-record fallback, `func_002494c0`, also improves substantially
without promotion. `CommonRecordFinal_002494c0_body.c` emits 432 executable
bytes against retail's 428 plus four alignment bytes. All sixteen
relocations resolve, but an extra `daddu a0,s0,zero` at `+0x2C` causes
96 positional executable differences. Removing that instruction only for
alignment analysis leaves exact bytes; this is not an exact candidate.
The shared null join, strict cap comparison and disabled CSE close the old
flow/address issues. A CSE-enabled inline date wrapper still scores
432B/86 masked words; a CSE-disabled inline update body under an enabled
outer function gives 416B/56. Both hypotheses are rejected, and ASM remains.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,745 MATCH overall; 6,115 first-party MATCH / 745 ASM**. All 335
first-party files are lint-clean and progress snapshots validate.
Source-linked totals remain **172 objects / 1,564 functions**.
Loadable SHA1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
complete ELF SHA1 remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Commit `1070f729` passed
[CI 34083948886](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34083948886):
all 11,152 exact fallbacks regenerated, the two hand-maintained files
remained unchanged, both retail hashes matched, and first-party MATCH
remained 6,115.

## Final font parser and message residuals

`func_002740b0` is fully relocated exact: **1,212 executable bytes /
1,216B window**, **32 resolved relocations**, zero executable differences
and one unreachable alignment NOP. This closes `src/frFont.c` at
**57 MATCH / zero ASM**. The neighboring positive insertion-branch recipe
(`no_branch_likely on`, `opt_rebuildconditionals off`), a natural `u32`
byte temporary and the actual three-byte signed glyph buffer replace the
old 217-word floor. The full `s32` pair retains the `0xC080` threshold and
`0x4000` remapping; the historical M2C draft's `s8` narrowing was wrong.

The retail descriptor table contains **six**, not eight, genuine groups,
with counts **8 / 8 / 8 / 2 / 10 / 14**. The mask still reaches adjacent
data for groups six and seven. Retail diagnoses `count < index`, not
`count <= index`, and tests the entire low command byte, not the masked
handler index. The diagnostic is a no-op; neither check prevents the
following indirect call. No fabricated table entries or protective guards
are added. Handler pointers reload after diagnostics; the cursor reloads
after handlers and receives its command-length adjustment even when a
handler stops parsing.

Native i386 execution of the integrated source passes **166 scenarios /
1,384 assertions at each of -O0 and -O2**. It covers all 44 real-valid
handler indices using substitute callbacks, all sixteen command lengths,
signed callback results, cursor/data/flag mutations, header and newline
predicates, empty-node reuse, allocation/link interactions, mutable style
and coordinate loads, glyph mapping, signed spacing, linked glyph width,
unsigned duration and the returned current node. Guarded synthetic slots
separately exercise invalid indices/groups without claiming retail reachability.

Three isolated invalid-domain processes per optimization observe native
SIGSEGV: a count-equality null callback, a synthetic invalid group-six
descriptor, and failed allocation without an existing node. These are not
PS2 fault claims. All helpers/handlers are observable substitutes; the
link fixture verifies interaction and return consumption, not the actual
helper's linked-chain topology. No MIPS/graphical execution or arbitrary
signed-overflow equivalence is claimed. Independent full-body review
accepts promotion. The direct caller already builds the correct 32-byte
context and forwards the result, so its interface remains unchanged.
The exact body is preserved in `FontParserRecovery_002740b0_body.c`.

`func_00277be0` stays ASM despite **664 instruction-exact bytes / 672B**
and **25 resolved relocations** using ordinary `s32` locals.
`MessagePrepareRecovery_00277be0_body.c` preserves the readable candidate
and explicitly marks its undefined `1U << index` domain. The inspected
MSG loaders and six direct call sites establish no count bound.
An executable-wide signature census finds seven embedded MSG assets with
three kind-one records, all count two; this is not the full resource corpus.
Downstream consumers continue beyond 32 entries with a shifted-to-zero
mask, so mask width is not a valid count proof. A constructed count-33
case demonstrates wrapping's observable effect without asserting shipped
reachability. Preparation's old mask shifts only on its set-bit branch.
UBSan trap-mode experiments reject unbounded indices 32/63/64/32766 and
accept masked boundary cases. Defined masking and unsigned modulo emit
668B/89 masked words; signed modulo gives 688B/92, masked O4 584B/151.
Promotion still needs an authoritative reachability bound or a defined,
allowed compiler expression with the retail instruction stream.

`func_0027a150` also stays ASM: **332 executable bytes / 336B window**,
five resolved relocations, **31 differing executable words / 34 bytes**.
Fourteen declaration/lifetime variants leave the saved-register coloring
floor intact. Reusing the existing `FrFontTreeNode` layout, with and without
disabled propagation, retains 332B/32 masked words including alignment;
reversing declarations gives 340B/80. Caller-grounded signed-halfword
parameters add narrowing instructions: both narrow gives 348B/71, either
alone 340B/67. No candidate improves the baseline.

A bounded R5900 integer interpreter executes fourteen complete retained
retail/relocated-candidate consumer pairs. Return pointers, prefix/suffix
release order, adjacent versus repeated y-groups, retained links, callback
entry snapshots and callback-clobbered released links agree. It does not
execute the release helper itself. The sole observed direct caller passes
two sign-extended halfwords, keeping subtraction in the checked signed
range; full-`s32` overflow equivalence is not claimed. The existing
`SITF_0027a150_body.c` archive remains preserved.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,746 MATCH overall; 6,116 first-party MATCH / 744 ASM (89.2%)**.
All 335 first-party files are lint-clean and progress snapshots validate.
Source-linked totals remain **172 objects / 1,564 functions**.
Both new durable archives compile to their measured instruction scores.
Loadable SHA1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
complete ELF SHA1 remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

Commit `06dc3758` passed
[CI 34085256707](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34085256707):
all 11,152 exact fallbacks regenerated, both hand-maintained files stayed
unchanged, both retail hashes matched, and first-party MATCH remained 6,116.

## Checked reallocation and texture packet construction

`func_0044f140` closes `src/Kernel/sdkChkmem.c` at **13 MATCH / zero ASM**:
**596 executable bytes / 608B window**, **36 fully resolved relocations**
and zero linked-byte differences. The remaining twelve bytes are alignment.
Typed `ChkMemEntry` access and explicit result assignments at the two arm
joins retain the retail branch chain. Independently removing only the two
through-`u64` pointer casts from the historical W54 body also makes that
draft exact in the current owner; its old register-coloring floor is stale.
The same-TU unlink helper remains **static void**. Its actual code preserves
physical `v0`; this does not justify a fictitious pointer-return interface.

The integrated body passes **ten complete candidate-versus-retail bounded
EE scenarios**: fresh allocation, disabled interrupts, shrink, safe growth,
overreading growth, failed new/old allocation, callback-visible pool reload,
zero request and wrapping allocation-size rounding. Checked allocation,
list/unlink helpers and returning diagnostics execute as real machine code.
Raw allocation/free/copy and privileged interrupt operations are explicit
hooks. Returning paths also check saved registers and stack restoration.
The matrix is not exhaustive over all classes, lists, alignments or nested
restore outcomes, and its wrap case deliberately forces allocation failure.

Two retail defects remain intact. Failed allocation is diagnosed and then
reaches a **NULL-header write**, before copying, unlinking, freeing or
restoring interrupts; the old allocation remains unchanged before that
fault. Copy size is unsigned `min(request, old header total size)`, not
payload capacity. An 80-byte old allocation with payload at `+32` and a
request of 100 attempts an 80-byte copy from only 48 readable payload bytes.
The copy hook reads the whole source before writing, so this proves the
overread, not real partial-copy destination effects.

The existing `s32(void *, u32)` registration and dispatch remain unchanged;
RenderWare's third hint is ignored, as in retail. Independent review accepts
promotion with these explicit target-ABI and execution limits. Exact C is
preserved in `CheckedReallocRecovery_0044f140_body.c`.

`func_00143cf0` closes `src/Kernel/h_malloc.c` at **10 MATCH / zero ASM**:
**672 executable bytes**, **eleven resolved calls**, zero differences and
no alignment tail. Despite the owner filename, this is DMA/GIF texture
packet construction, not heap allocation. Ordinary stride locals, saved-Y
lifetime, a final-column flag and separate sequential address additions
replace the oversized historical reconstruction. No wide constructor
locals, artificial padding or raw instructions are needed; the matched
helpers' packed `u64` fields represent actual packet data.

The numeric source-address local is **`u32`**, not `s32`. A signed local
traps when ordinary positive stride advances cross the signed-address
boundary, even with small otherwise-safe dimensions. The same-width
unsigned form retains every retail byte while defining low-32-bit wrapping.
Both signed negative controls trap under signed-integer-overflow UBSan at
`-O0` and `-O2`; the integrated unsigned body passes **137 native-i386
scenarios at each optimization**, including signed-address and unsigned-wrap
boundaries. This is specifically signed-overflow instrumentation, not an
all-undefined-behavior sanitizer claim.

The consumer runs the real matched packed-helper bodies with call-order
instrumentation. An independent serializer checks every byte of its 8,192-byte
buffer, including untouched holes and trailing bounds. Coverage includes
negative/zero widths, 15/16/17 and 63/64/65 boundaries, height 448, skip/gap
segments, final-column EOP, both initial fill patterns and high/low source
address masking. With `N = max(width >> 4, 0)`, the write extent is
`0x48 + 0x60*N`, while `64 + 80*N` bytes are actually written: DMA-tag slots
leave their upper eight bytes untouched.

All eleven arguments and existing wrapper/helper declarations agree with
retail. The existing `0x102` submission reaches the low-byte-two DMA-chain
path; it is not discarded. Source is numeric and never dereferenced here.
The caller's height clamp to 448 does **not** bound width or establish
capacity for unsized `D_007D0F00`. Invalid/misaligned pointers, insufficient
buffers and signed dimension/product/coordinate overflow remain outside
the exercised domain. No MIPS, GS, DMA or graphical execution is claimed.
Independent review accepts the unsigned variant; its exact C is preserved
in `TexturePacketRecovery_00143cf0_body.c`.

The selected owners and registration verify **133 functions: 28 MATCH /
105 ASM**, including **27 first-party MATCH / one ASM**. No caller changes
are required.

The first DMA reconstruction retained `func_00463ea0` as ASM because
ordinary C cannot express its sync/COP0 condition-line waits. Omitting the
waits or substituting CHCR-only polling is not equivalent: delayed-completion
models expose active DMA8 on return, incorrect output or lost arbitration.
The hardware-only replacement below closes this residual under the existing
bounded-assembly policy; `W53Uttmx_00463ea0_body.c` remains historical evidence.

Virtual-pad `func_004b5800` remains at 324B/5 masked words: two reordered
load/shift instructions and three alignment words. Both integer-address
addition orders retain that score; unsigned offset spelling at either
one call loses common reuse and gives 320B/61. These four new source
hypotheses are rejected without changing its production fallback or archive.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,748 MATCH overall; 6,118 first-party MATCH / 742 ASM (89.2%)**.
All 335 first-party files are lint-clean and progress snapshots validate.
Source-linked totals are **172 objects / 1,565 functions**, one additional
C-linked function. Both new durable archives reproduce their measured
instruction streams.
Loadable SHA1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
complete ELF SHA1 remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Scene transition, scratchpad DMA and draw-context ABI

`func_0026d440` closes the scene updater at **824 executable bytes / 832B
window**, with **28 fully resolved relocations** and eight zero alignment
bytes. The two `R_MIPS_LITERAL` loads resolve to the `0.01f` constant at
`0x761514`; the two-float initializer owns eight bytes at `0x7637e0`.
The verifier masks only the literal relocation's 16-bit immediate, preserving
opcode/register differences. Link planning now places and checks `.lit4` and
`.lit8` data, including an interior literal symbol's section-relative offset.
The smoke test rejects changed instruction fields and corrupted pool bytes.

The adjacent getter and its consumer consistently use **`u32(float *)`**,
not a byte-return declaration that adds caller-side masking. The event-side
setter declaration now agrees with **`void(s32, s32)`**. These interface
corrections preserve the affected retail instructions.
Integrated native-i386 execution passes **294 amplitude/timing combinations
at each of `-O0` and `-O2`**, plus delayed disable/clear transitions, helper
cadence, signed indefinite timing, strict thresholds, clamps and callback
ordering. Expiry disables first; the following disabled update clears the
outputs. Host floating-point checks are not EE FPU or graphics validation.
The measured source is preserved in `SceneManagerRecovery_0026d440_body.c`.

`func_00463ea0` closes `src/Kernel/sdkUttmx.c` at **three MATCH / zero ASM**:
**604 executable bytes / 608B window**, two exact call relocations and four
zero alignment bytes. Address arithmetic and volatile DMAC MMIO remain C.
Four bounded hardware-only wait islands retain `sync.l`, `sync.p`, COP0
condition-line polling and explicit **memory clobbers**. This is the hardware
operation exception in `STYLE.md`, not permission to reproduce ordinary
compiler instructions with assembly.

The retail seven-instruction wait loops are retained conservatively. The
[R5900 short-loop discussion](https://www.spinics.net/lists/mips/msg71675.html)
has revision and scheduling conditions; it does not establish five nops as
a universal minimum. The integrated C, compiled-word and retail-word model
passes **280 cases / 79,940 interpreted instructions**, including **1,540
condition polls**, **550 delayed DMA9 polls** and **ten rejected mutations**.
Only byte counts `0..15` issue a final zero-QWC pair; nonzero exact
`0x400`-QWC multiples finish with a full pair. Sub-quadword tails are discarded.
Physical hardware, cache preparation, concurrent DMA activity and high-address
bus mapping remain outside this model. The measured body and its required
loop-invariant pragma are in `DmaHardwareRecovery_00463ea0_body.c`.

The renderer audit also fixes two real C ABI omissions:
`func_004b11d0` and `func_004b1210` now pass their context explicitly to
`func_00481440(void *)`. Retail's callee stores that incoming pointer.
Both bridges remain exact; their containing unit verifies **68 MATCH /
ten ASM**, including **67 first-party MATCH / two ASM**.
The pre-fix native excerpt fails at both `-O0` and `-O2`; the integrated
excerpt passes **32 cases per optimization**, checking context forwarding,
null-context preservation and draw ordering.

The related initializer `func_001fa110` and its caller now consistently use
the **`u8 *` payload contract**; the callback declaration takes the same
pointer type. The initializer remains exact and passes **256 native cases
per optimization**, checking write extent, flags, registration and helper
ordering. Its callback `func_001f9cf0` remains ASM: the readable reconstruction
is **688B / four fully resolved differing words**, all at `+0x6c..+0x78`.
Its **6,048 bounded machine cases** pass, but semantic agreement does not
erase the load/address scheduling floor.

Other completed investigations remain explicit residuals, not promotions:

* `func_00202890`: preferred readable panel callback **696B / 310 masked
  differing words**; best same-window candidate **720B / 229**, after
  **52 hypotheses**. The callback receives the panel at envelope `+0x90`;
  lifecycle checks and exact constructor/initializer companions do not
  make this callback instruction-exact.
* `func_00476e90`: material-color candidate **996B / 976B window**, with
  **72 fully resolved differing words** across executable code, padding
  and overflow. A return-by-value alternative worsens to **1008B / 81**.
  Native checks cover **524,288 calls / 2,097,152 channel results**; the
  accumulator seed and normalization/register schedule still differ.
* `func_00479100`: model-rendering candidate **1908B / 1920B window**,
  **30 fully resolved executable differences at `+0x48c..+0x500`**, and
  **36 relocations**. Semantic checks cover **1,576 scenarios** plus
  **131,072 byte/context executions / 1,570,952 checks**. The accumulator
  and shared draw-path floor remains; only the independently exact bridge
  ABI correction above is installed.

Acceptance: **525 tests pass**; `make build-progress progress lint-errors`
passes with **7,750 MATCH overall / 4,970 ASM**, including **6,120 first-party
MATCH / 740 ASM (89.2%)**. All 335 first-party files are lint-clean and
progress snapshots validate. **C-linked coverage remains 172 objects /
1,565 functions**: these two source matches do not increase linked-C coverage.
Loadable SHA1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
complete ELF SHA1 remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

The literal-mask change also updates the pinned `tools/verify.py` input
hash in `config/generated_asm.json`. With the exact regeneration dependency
versions installed in an isolated environment, `regenerate_asm.py --check`
reproduces **all 11,152 fallback files** and retains both hand-maintained
files unchanged. No expected output hash or reconstruction recipe changes.

Commit `bfeb9ac6` passed
[CI 34094185276](https://github.com/Raikaru/Persona4-Decompilation/actions/runs/34094185276),
including the corrected generator-provenance gate.

## Message line-group trimming and retained compact floors

`func_0027a150` is now **332 executable bytes / 336B window**, with **five
fully resolved relocations**, zero instruction differences and one zero
alignment word. A shared inline detach/release primitive owns the local
traversal pointer, saves the successor before release and advances that
local owner afterward. Declaring the retained endpoints in traversal order,
head before tail, closes the last register swap. No new pragmas are needed.

The public interface remains **`u8 *(u8 *, s32, s32)`**; the inline
pointer-to-pointer interface is private and receives only `&current`.
The message owner's release declaration now agrees with the existing
**`s32 func_00271b70(s32)`** implementation. Its return is deliberately
ignored: a fading detached node may remain alive, but traversal must use
the saved successor, not that return value.

The integrated compiled-C and retail-word consumers pass **98 bounded
pairs**. An independent list oracle checks contiguous-group selection and
prefix-before-suffix release order; callback-entry snapshots, poisoned
caller-saved registers and released-node fields check ownership across
release. Retained boundary links, per-node tail pointers, lower-64 saved
registers and stack restoration agree. Coverage includes repeated
nonadjacent tags, exhaustion, nonpositive skip counts and both extremes of
the observed sign-extended-halfword argument domain.

Only finite, non-null acyclic lists are executed. Release is intercepted,
not executed; arbitrary retained-node mutations, upper EE register halves,
null-path execution and full-`s32` subtraction overflow are not certified.
The complete message owner verifies **84 MATCH / one ASM**. Its remaining
fallback is the separate message-preparation shift-count problem.
`MessageTrimRecovery_0027a150_body.c` preserves the integrated helper/body;
the historical `SITF_0027a150_body.c` remains unchanged.

Two compact investigations still do not justify promotion:

* Battle-order `func_001b11c0` remains **192B / five fully resolved differing
  words**, at `+0x34`, `+0x4c`, `+0x88`, `+0x9c`, `+0xa4`. Shared skip
  continuation and distinct const unit-pointer lifetimes leave the key/index
  register swap unchanged; a byte-sized changed predicate adds masking and
  worsens to **196B / eleven words**. **11,815 bounded cases** cover stable
  key-first partitioning, upper key bits and duplicate action identities.
  Empty or mixed nonkey domains retain their observed fault/nontermination
  hazards; no guard or byte-key truncation is introduced.
* Common-record `func_002494c0` remains **432 executable bytes / 428 retail
  bytes plus four zero alignment bytes**. Correct getter contracts, distinct
  date lifetime and argument-preparation spelling leave the extra copy at
  `+0x2c`; all sixteen relocations resolve, but **96 positional executable
  words differ**. **534 native scenarios** produce 522 matching returns and
  twelve observed null-path faults. The returning diagnostic does not turn
  null paths into safe returns. Host faults are not PS2 fault claims.

A separate minimal quantizer experiment rejects two explanations for the
material/model floor. With CSE and propagation disabled, both b210 and b119
emit **152B with four zero-register seeds**. Enabling CSE only in an inline
callee still emits 152B/four seeds under the disabled caller; enabling it
in the caller emits **128B/one seed**. This is a reduced compiler experiment,
not a newly matching material or model renderer.

Full acceptance: `make build-progress progress lint-errors` passes with
**7,751 MATCH overall / 4,969 ASM**, including **6,121 first-party MATCH /
739 ASM (89.2%)**. All 335 first-party files are lint-clean; progress
snapshots validate. C-linked coverage remains **172 objects / 1,565
functions**. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Sampled-color return contract and typed residual replay

`func_0047f5b0` now explicitly returns its borrowed **`f32 *` work buffer**.
The color row of `D_00713220` installs it in the sample slot; dispatch at
`0x0047f958` consumes `$v0` and forwards that address to each apply callback.
The previous `void` declaration omitted this contract even though its
configured machine code happened to retain the pointer.

A strict native 32-bit typed callback consumer rejects the old declaration.
The corrected consumer passes **720 cases** using the real key sampler and
blend body: one through four keys, first/interior/last/clamped times, RGB
normalization, blending/extrapolation and returned-buffer identity. Times
are at or after the first key; pre-first-key behavior and exceptional PS2
floating-point behavior are not certified. No sampling guard is added.
The target remains **348B / 352B window**, with every emitted byte and
relocation identical to the frozen original. Its unit remains **36 MATCH /
two ASM**; this is an ABI correction, not another matching promotion.

The canonical source archives retain better source representations without
claiming lower instruction floors:

* `W49MdlEffect_0048a460_body.c` now uses genuine **12-byte XYZ locals** for
  input and transformed coordinates. Only the four-lane COP2 output needs
  explicit 16-byte alignment. Standard archive replay remains **176B /
  fifteen differing words**, with all ten relocations exact. **1,010 native
  affine projections** cover capture/getter/transform/restore ordering,
  snapshot-before-getter mutation, negative depth, sequential projections,
  positive-zero output lanes, alignment and spill canaries. Native hooks
  do not execute COP2.
* `EcF_0038f400_body.c` now returns an owned pointer and names the five-word
  **`ed_staff` resource header**. Full unsigned counts still control
  allocation and traversal; only stored ID/count values are narrowed.
  Ordinary generic alignment code retains the mathematically unreachable
  first correction branch. Standard archive replay remains **396B / 400B
  window**, with **sixteen differing emitted words plus one zero-tail
  word** and seven exact relocations. **216 native cases** cover counts
  through 65,537, unsigned lengths, every alignment residue, exact payloads,
  untouched padding and debug/allocate/copy/copy ordering. Valid descriptors
  and successful low-address allocation only; not retail MIPS execution.
* `K1DA_001d15a0_body.c` retains its existing **212B / 224B window** floor:
  **nine register-allocation words plus three zero-tail words**. A complete
  typed threshold record leaves that floor unchanged; **11,464 native
  cases** cover first-hit precedence, independent threshold rejection,
  nonmonotone tables and all four helper output counters. An older CSP
  result reported 240B; the live archive already documented the nine-word
  floor and remains authoritative.

Other fresh structural probes likewise remain residuals: triangle selection
`func_0014be50` retains four aggregate-copy scheduling words; typed track
dispatch `func_0047f850` retains twelve register-allocation words plus one
zero-tail word; shuffle initialization `func_00375f00` retains seven differing
emitted words, totaling twenty differing bytes, plus one zero-tail word.
No approximate body replaces an assembly fallback.
The subsequent track-dispatch recovery below supersedes that routine's floor.

Reduced compiler controls also fail to close a floor: the existing explicit
zero-addend multiply-add expression still emits **152B / four zero seeds**
with CSE and propagation disabled. A standard `memcpy` replacement in
`func_00484b30` emits a library call even with intrinsics enabled and worsens
the masked comparison from **six to 41 differing bytes**.

`make build-progress progress lint-errors` passes: **7,751 overall MATCH /
4,969 ASM**, **6,121 first-party MATCH / 739 ASM**, and **172 C-linked objects /
1,565 functions**. All 335 first-party files are lint-clean; progress
snapshots validate. Both the loadable-image and complete-ELF SHA1 values
remain unchanged from the preceding acceptance result.

## Window creation and constructor contracts

`func_0046e850` now matches in `src/promoted/code1_0046.c`: **444 executable
bytes / 448-byte retail window**, fifteen exact relocations, and four
zero-tail bytes. The previous three argument-setup differences came from
declaring the task name as an integer. Passing `D_00713108` through the
correct pointer domain restores the retail parent/name ordering; no
instruction padding or register pinning is involved. All 58 neighboring
bodies and relocation records are preserved. The unit is **47 MATCH /
twelve ASM**, and `L46_0046e850_body.c` retains the exact source.

The coordinated API correction makes explicit name parameters of
`func_00451fc0` and `func_00451de0` **`const void *`** across live declarations
and definitions. Unrelated parent, result, callback and work contracts are
unchanged; old-style declarations remain old-style rather than inventing
their other argument types. Integer-held name addresses use direct pointer
casts. An unnecessary intermediate `uintptr_t` conversion moved two
argument-setup instructions in each of `func_0046a110` and `func_0046a1f0`;
removing that conversion restores both existing matches.

The shared `SdkTask` prefix also had a genuine layout error: the name is
**24 inline bytes at offset zero**, not a heap pointer at `0x18`. Offset
`0x18` holds the signed-byte name accumulator. A freestanding native 32-bit
consumer using the old header faults while reading a successfully created
task's name. The corrected header passes **960 actual-source cases** covering
signed bytes, name-length boundaries, allocation failure, delayed/immediate
initialization and parent attachment. The retail copy-before-limit ordering,
including the accumulator's low-byte overwrite at the 24-byte boundary, is
preserved rather than silently replaced with a safer string-copy algorithm.

Both formation constructors, `func_001d2d90` and `func_001d3000`, now explicitly
return **`BtlPacket *`**. Retail caller `func_001a7720` immediately consumes
each `$v0` packet. A typed consumer rejects the former `void` definitions;
the corrected actual-source native32 consumer passes **1,024 cases**.
Machine code remains exact at **104B / 112B window** and **144B / 144B**
respectively. These are return-contract repairs, not new matching promotions.

The recovered window body and its real destructor pass **8,192
freestanding native32 cases**: both allocation failures, registration
failure without invented early cleanup, input mutation during registration,
buffer-size mutation during diagnostics, signed division around multiples
of eight, buffer/cursor ownership and buffer-before-work release. External
allocator/task effects are controlled hooks; the game renderer is not run.

Two honest residuals remain archived:

* `SFRM_001d2e20_body.c` uses a genuine **three-float position** and four-float
  rotation. Its owner is the `0xb02` constructor's **16-byte work packet**,
  not the adjacent constructor's twelve-byte payload. Replay retains
  **440B / 448B window, 92 relocation-masked differing words**. The exact
  archived body passes **10,752 native32 lifecycle cases**; the numerical
  placement solver remains a recording boundary. Production stays ASM.
* Typed-table replay of `func_001130c0` retains **440B / 448B window**:
  five scheduling words plus two zero-tail words, with 46 neighbors intact.
  Its **43,008-case** native consumer passes Clang ASan/UBSan. Eventual
  promotion must migrate the caller's packed-s64 spelling to the existing
  `Vec2f` aggregate contract; no approximate callee is installed.

Final `make build-progress progress lint-errors` passes: **7,752 overall
MATCH / 4,968 ASM**, **6,122 first-party MATCH / 738 ASM (89.2%)**, and
**172 C-linked objects / 1,565 functions**. All 335 first-party files are
lint-clean and progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Archive path normalization and defined nearest selection

`func_00456530` now matches in `src/promoted/code1_0045.c`: **348 executable
bytes / 352-byte retail window**. The raw diff counts only the final zero
alignment word. Using literal separators with scoped
`opt_loop_invariants on` and `opt_propagation off` closes the eleven
remaining loop-register differences. Named path buffers and offsets replace
the decompiler temporaries; shared helper declarations and the public
three-argument contract are unchanged. The production unit is **52 MATCH /
eight ASM**. `D456_00456530_body.c` retains the exact source.

The actual recovered body and existing uppercase-path helper pass **3,082
freestanding native32 cases with UBSan traps enabled**. Coverage includes
empty and multiple entries, the exact `singleEntry == 1` stopping rule,
64-byte payload alignment, case/slash conversion, high-bit path bytes,
255-character paths, unchanged input storage and payload-pointer ownership.
Six of those cases exercise additional size bit patterns through
single-entry registration without dereferencing an oversized payload.
The initial signed next-offset addition trapped at size `0x7fffffc0`;
explicit unsigned wrapping removes the undefined overflow without changing
the retail instructions. Registration is a checked external hook, not
retail game execution.

`R1EE_001d8cb0_body.c` improves from eighteen to **six relocation-masked
differing words**, still **312B / 320B window**. The real action UID/unit
prefix and natural `u16` key induction close all twelve key-loop differences.
Four first-entry comparison/branch words and two zero-tail words remain.
The first-entry guard still prevents reading an uninitialized best distance;
the approximate body is not installed in production.

Fresh virtual-pad pointer-domain probes do not improve its five-word floor.
Typed curve snapshots and archive workspace variants also regress rather
than establish matches; no approximate body replaces those fallbacks.

`make build-progress progress lint-errors` passes: **7,753 overall MATCH /
4,967 ASM**, **6,123 first-party MATCH / 737 ASM (89.3%)**, and **172 C-linked
objects / 1,565 functions**. All 335 first-party files are lint-clean and
progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Combination inventory finalization

`func_0030f4f0` now matches in `src/Event/Fcl/y_fclCombine.c`: **348 executable
bytes / 352-byte retail window**, with only four zero alignment bytes beyond
the object body. The unit verifies at **24 MATCH / seventeen ASM**.

The old archive's `s64` bound and separate `id2` cache obscured two independent
levers. Actual halfword counters/bound plus scoped `opt_loop_invariants on`
restore both loops' narrowing and reduce the raw residual from thirty to
fourteen words. Removing `id2` and comparing `(u16)equippedId` directly lets
the compiler generate the cached mask itself, closing the thirteen remaining
saved-register differences. No widened object, pinned register or instruction
padding is involved. `DcF_0030f4f0_body.c` retains the exact named source.

The actual production body passes **81,920 freestanding native32 inventory
cases with UBSan traps enabled**. These cover all signed-byte counts and the
7-to-12 mapping; absent, first, last and duplicate identifiers; zero and
high-bit IDs; signed selector/index arguments; ordered removals, insertion,
equipment selection and finalization; and final inventory membership.
Unsigned equipped ID `0xFFFF` remains distinct from signed material `-1`.

Controlled getter mutations verify that the task's work pointer is captured
before the getter, while the count is read after it. Controlled copy mutations
verify that the cached count survives, but selector/index fields and search
materials are reloaded. Record lookup and inventory helpers
are native boundaries; this is not retail MIPS execution.

Fresh sibling probes do not close their residuals: `func_0021de90` retains
three upper-bound comparison words plus two zero-tail words at **440B /
448B**; `func_002494c0` retains its single redundant argument copy, which
shifts the remaining instructions. Neither approximate body is installed.

`make build-progress progress lint-errors` passes: **7,754 overall MATCH /
4,966 ASM**, **6,124 first-party MATCH / 736 ASM (89.3%)**, and **172 C-linked
objects / 1,565 functions**. All 335 first-party files are lint-clean and
progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Track dispatch and compatible callback contracts

`func_0047f850` now matches in `src/promoted/code1_0047.c`: **412 executable
bytes / 416-byte retail window**, with one zero alignment word beyond the
object body. Direct table indexing under scoped `opt_loop_invariants on`
closes the twelve saved-register differences; retaining an explicit dispatch
pointer did not. `W52Main_0047f850_body.c` retains the exact source.

The recovered target-list prefix contains a pointer array and a `u16` count.
The dispatcher snapshots the list pointer and count once, but reloads its
item array and the current apply callback after callbacks. It passes the
borrowed sample/blend result directly to every target, including when a
callback mutates that buffer. Zero targets still permit sampling; absent
apply callbacks or left-track data skip the row.

The live callback definitions now use compatible C function types:
`func_0047f040`, `func_0047f1a0`, `func_0047f4d0` and `func_0047f5b0` return
borrowed `void *` results with byte-pointer track/default arguments.
`func_0047f4d0` also uses the dispatcher's interleaved pointer/float parameter
order. `func_0047f2c0`, `func_0047f710` and the empty `func_0047f840` accept
opaque result/target pointers. Their value interpretation remains local.
All seven callbacks remain exact; the three affected units verify at
**48 MATCH / one ASM**, including the newly recovered dispatcher.

The actual dispatcher passes **262,160 freestanding native32 mutation
scenarios** under Clang undefined-behavior and function-type sanitizers.
Coverage includes all sixteen masks for left tracks, right tracks and apply
callbacks; counts zero, one, three, seven and `65535`; count/list-pointer
replacement; item-array replacement; apply-callback replacement; and
borrowed-buffer mutation. An independent event digest checks callback order,
selected targets and evolving buffer contents.

The actual scalar/color samplers, blends and apply callbacks pass **25,920
native32 consumer cases** under the same sanitizers: key counts one through
four, interpolation and endpoint times, blend ratios, default colors, borrowed
result identity and target color/alpha updates. The old callback definitions
trap with the function-type sanitizer alone; the corrected definitions pass
without function-pointer casts. Rendering hooks are checked native boundaries,
not retail MIPS execution. Temporary harnesses are not permanent test load.

`make build-progress progress lint-errors` passes: **7,755 overall MATCH /
4,965 ASM**, **6,125 first-party MATCH / 735 ASM (89.3%)**, and **172 C-linked
objects / 1,565 functions**. All 335 first-party files are lint-clean and
progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Signed calendar overrides and the draw ABI boundary

`src/promoted/code1_0011.c` now declares `func_00123ae0` with its actual
`s8` return and `func_00123b10` / `func_00123b40` with their actual `s16`
returns, matching the definitions in `code1_0012.c`. The previous `s64`
declarations conflict when combined with those definitions. Both production
units still verify at **115 MATCH / fourteen ASM**; their instructions are
unchanged.

The actual getters and existing `func_00110960` consumer pass **307,200
freestanding native32 cases** with undefined-behavior/function sanitizers.
These cover null override state, matching and mismatching days/phases,
signed halfword endpoints, all signed-byte values, the `-1` fallback sentinel
and signed fallback results. The old declarations fail the combined
declaration/definition compilation check; the corrected declarations compile
and all consumer cases pass.

`Q011_00110a60_body.c` no longer needs block-scope getter declarations.
Its unpromoted selector remains **488B / 496B window, ten masked differing
words**. Fresh byte-load helper boundaries and source-shaped return paths
do not close the fallback-load/return sequence.

`P020_00204b80_body.c` is replaced with a defined byte-contract candidate:
**460B / 464B window, nine masked differing words**, including one zero-tail
word. It corrects the old draft's initial depth (`50.0f`, not `72.0f`),
counter address and negative-byte remainder handling. Real signed-short
loop variables and an inline counter-update boundary preserve the second
byte load while allowing CSE to share the white RGB arguments.

Changing the candidate opacity parameter to a word closes all executable
differences in the callee, but applying the same declaration to live caller
`func_0020b3a0` reorders three instructions around its opacity load. Source
staging, inline conversions and scoped caller controls do not close that
integration boundary. The byte-contract candidate is retained; neither the
callee nor its matched caller is changed in production.

The recovered byte-contract draw body and actual position/depth/color helpers
pass **262,144 native32 command-stream cases**: all initial counter and
opacity bytes, fifteen draws in the 3x5 grid, counter wrap and callback
mutations, opacity/color updates, state-callback replacement and final reset.
Drawing and render-state hooks are native boundaries, not GPU or retail MIPS
execution. The misleading `iGpffffb474` symbol is not reused for the counter:
its recovered binding is the separate battle pointer at `0x0076449C`, while
the counter is at `0x00764564`.

Fresh bounded probes retain the existing shuffle-initializer eight-word,
defined nearest-selection six-word and battle-order five-word residuals.
No approximate body replaces those assembly fallbacks.

`make build-progress progress lint-errors` passes unchanged at **7,755
overall MATCH / 4,965 ASM**, **6,125 first-party MATCH / 735 ASM (89.3%)**,
and **172 C-linked objects / 1,565 functions**. All 335 first-party files
are lint-clean and progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Exact status-level selection and defined scalar contracts

`func_00235320` in `src/Main/Battle/Data/datCalc.c` is now exact:
**504B / 512B window**, with only the two omitted zero-tail words in
`fndiff`. The complete owner verifies at **69 MATCH / eleven ASM**.
`RDCA_00235320_body.c` contains the installed source and recovery evidence.

The closing levers are the real signed-byte threshold/status/level
boundaries, a promoted local at the level getter's branch merge, the
unsigned-byte boolean boundary in the expanded active getter, and the
independently narrowed `index % 256U` argument. Scoped loop-invariant
hoisting preserves the threshold comparison's lifetime. The existing
`s64` public return remains unchanged; a successful index is narrowed to
`s8` before widening to that return type.

The selector, actual `func_002332a0` status decoder and actual returning
diagnostic stub pass **1,114,112 native32 cases** with undefined-behavior
and function sanitizers. Coverage includes every status/level nibble in
both parities, negative nonzero statuses, inactive packed status `15`,
thresholds `3` and `6`, earlier qualifying entries, index `15`, exclusion
of an otherwise qualifying index `16`, signed `-1`, resource flag masks
and IDs `0`, `0x14F`, `0x150`, `0xFFFF`. An extended in-bounds fixture
table exercises the returning diagnostic paths; disabling resource lookup
sets that table pointer to null.

Field-selection research also exposed a real return-contract defect:
`func_0014a270` was defined `void` and discarded the result of
`func_0014a2a0`, while its consumers require the predicate result.
It now returns that `s32` result. The old definition fails compilation
with the consumer declaration; the corrected wrapper and actual predicate
pass **262,144 native32 cases**, spanning every 16-bit mode and four
secondary-field values. The owning unit remains **114 MATCH / twelve ASM**.

`func_002b2a30` now shifts its high color byte in unsigned 32-bit arithmetic.
The old signed expression traps under the shift sanitizer for alpha `255`.
Changing the mask to `0xFFU` removes that undefined shift without changing
the four `s32` parameters, return contract or retail instructions.
The reproduction and **72,097 native32 packing cases** pass, including
all alpha/red bytes and signed/full-word masking boundaries. Its owner
remains **72 MATCH / three ASM**.

The native checks execute the actual C functions, not retail MIPS code.
No platform-specific smoke scaffolding is retained.

Unpromoted evidence is also refreshed:

- `LFF2_0016b080_body.c`: **476B / 480B, 72 differing words**, down from
  93 after 35 bounded source-shape probes. Typed resource/list prefixes,
  cached guards and lexical float placement improve the candidate.
  Guard folding, FP constant rematerialization and fallback joins remain;
  the declaration/caller migration and pointer-getter contracts must be
  resolved before promotion. The previous 13,440-case smoke belongs to
  the earlier raw-pointer spelling, not this new candidate.
- `FclShopDraw_002e0100_body.c`: **452B / 464B, 37 differing words**, down
  from 45 using the actual float-first draw signature and signed-short
  origin parameters. The color and opacity byte-to-word argument loads
  still materialize too early. Packed-field spellings tie and are not
  retained. Production shop declarations and assembly remain unchanged.

`make build-progress progress lint-errors` passes at **7,756 overall
MATCH / 4,964 ASM**, **6,126 first-party MATCH / 734 ASM (89.3%)**,
and **172 C-linked objects / 1,565 functions**. All 335 first-party
files are lint-clean and progress snapshots validate. Loadable SHA1 is
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 is
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Exact packed status maintenance and bank acquisition evidence

`func_00235110` in `src/Main/Battle/Data/datCalc.c` is now exact:
**524B / 528B**, with one omitted zero-tail word and no differing emitted
instructions. The owner verifies at **70 MATCH / ten ASM**. Its shared
signed-byte level getter and per-branch setter address calculation preserve
the retail merges without new pragmas. `IoD_00235110_body.c` now contains
the installed source rather than the old truncated-shift reconstruction.

The actual maintenance routine, status decoder and private level helpers
pass **1,053,696 native32 cases** under undefined-behavior and function
sanitizers. Cases cover every status/level nibble, both parities, inactive
encodings `0` and `15`, negative nonzero statuses, unchanged neighboring
bytes, exclusion of entries beyond the first sixteen, and repeated
saturation at level `15`.

`QFCL_002e1030_body.c` remains unpromoted at **504B / 512B**, **51 differing
words**, or **49** after zero-tail normalization. The faithful candidate
fixes the old doubled short-pointer stride, slot-index reload, signed
descriptor shift and incorrectly dismissed API mismatches. Its **25,600
native32 cases** pass the same sanitizers: unused-before-reusable priority,
failure without writes/callbacks, signed descriptor halves, callback-mutated
index/flags/manager, node removal and diagnostic ordering. Seventeen
pre-call allocation/selection-use differences and an extra argument move
still prevent exact matching. Production remains ASM.

`make build-progress progress lint-errors` passes at **7,757 overall
MATCH / 4,963 ASM**, **6,127 first-party MATCH / 733 ASM (89.3%)**,
and **172 C-linked objects / 1,565 functions**. All 335 first-party files
are lint-clean and progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Native checks execute C rather
than retail MIPS; their freestanding platform scaffolding is not retained.

## Byte drawing contracts close shop rendering

`func_002e0100` in `src/Event/Fcl/y_fclShopDraw.c` is now exact:
**452B / 464B**, with only three omitted zero-tail words. The apparent
argument-scheduling floor was a contract mismatch, not a backend limit.

`func_002b2a30` takes four `u8` components. `func_0025ecd0` takes the existing
float-first argument sequence with `u8` opacity, signed-short origins and
pointer-valued resource/queue arguments. Its inversion is `255 - opacity`:
retaining the redundant byte mask under the correct signature creates
three operand-order differences. Removing it preserves the exact
**588B / 592B** callee.

The cutover migrates active declarations and callers together:

- `func_0025ec90` uses float-first coordinates and byte opacity.
- `func_0025f500` / `func_0025f540` retain byte opacity end to end; the latter
  has signed-short origins. Their ordering context is a real pointer,
  eliminating the old signed-64 carrier and pointer-punning load. A pointer
  argument still produces the retail `sd` stack argument in the outer wrapper.
- `func_002e0b20` / `func_002e0be0` / `func_002e0ca0` retain their two-float
  aggregate and lexical float position, with byte opacity. Shop declarations
  now agree instead of spelling that aggregate as an integer.
- `func_00330e50` forwards byte opacity; resource fields in the field-map
  callers are loaded as pointers rather than converted from integer locals.
- The existing `func_002cacd0` digit renderer uses byte color locals with the
  byte packer and wrapper. Its **536B / 544B** instructions remain exact.

Scratch compilation preserved **all 516 existing MATCH bodies in fifteen
owners** before integration. The already-canonical `cmmScript.c` declaration
was intentionally unchanged. Historical generated candidates and unpromoted
archives remain snapshots, not active ABI declarations; the canonical
`FclShopDraw_002e0100_body.c` and `L25_0025ecd0_body.c` archives are updated.

The actual C packer, draw callee, callbacks, sprite/resource wrappers,
combination bridge, shop routine and digit renderer pass native32
undefined-behavior/function-sanitized scenarios:

- **66,161 packing cases**: byte truncation, signed/full-word inputs and
  every first/second component byte.
- **39,424 drawing pipeline cases**, including **16,384 shop cases**:
  visibility equality, overlay order, post-preparation positions, all opacity
  bytes, signed frames/origins, metadata and flat resource paths, packet
  contents, queue identity, callback mode and zero-dimension cleanup.
- **16,384 digit cases**: zero through `UINT32_MAX`, decimal grouping,
  signed spacing, glyph/resource selection, all opacity bytes, rendered
  coordinates and callback completion.

These execute C with bounded geometry, not a PS2 display or COP1 emulator.
No native-platform scaffolding is retained.

`make build-progress progress lint-errors` passes at **7,758 overall
MATCH / 4,962 ASM**, **6,128 first-party MATCH / 732 ASM (89.3%)**,
and **172 C-linked objects / 1,566 functions**. All 335 first-party files
are lint-clean and progress snapshots validate. Loadable SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Defined combination loop and honest residual contracts

`func_0032b770` contained an unused expression that dereferenced `new_var`
and read `f20`/`f21` before initialization. MWCC discarded its result, so
the retail instruction match concealed undefined source behavior. Removing
the expression preserves **all 36 existing MATCH bodies** in
`y_fclCombineDraw.c`; the loop remains **596B/608B**, with only three
zero-tail words omitted. Clang's `-Werror=uninitialized` rejects the old
body at all three reads and accepts the corrected body. An actual-source
undefined/function-sanitized consumer passes **216 cases / 798,744 rendered
rows**, checking empty and maximum signed-halfword loop bounds, narrowed
spacing, signed glyph indices, fresh record reads, coordinates, callback
order, final positions and unchanged neighboring bytes.
MemorySanitizer also reports `use-of-uninitialized-value` in the old
function at runtime; the corrected body passes the same 216-case consumer
under MemorySanitizer at `-O0`.

`func_0032c480` is **not promoted**. A private typed task-work getter closes
the final pointer-load scheduling gap: the isolated candidate emits exact
**472B/480B** code under its signed-halfword list-index declaration, leaving
two zero-tail words. But applying that declaration to the whole owner
breaks the existing `0032b770` match: its loop grows to **604B/608B**.
Keeping the existing word-index call contract instead leaves eight emitted
differences in `0032c480`, four `move-a0`/`lh-a1` ordering pairs.
Narrowed loop locals, propagation settings and record/selection helpers
did not reconcile both functions. A conflicting local prototype is not an
acceptable promotion. The isolated candidate and integration blocker now
replace the obsolete archive.

Further integration requires migrating the message queue pointer together
with its float-preserving `002bc7f0` bridge, the model work-pointer getter,
and the list getter's byte/halfword pointer consumers without changing
their offsets. The combination candidate passes **125 native cases** under
Clang undefined/function sanitizers and GCC undefined-behavior traps.
Its pure color packer returns `0x000000FF` for `(0,0,0,255)`; the consumer no
longer relies on a side-effectful color stub or unspecified argument order.
Native pointer layouts are host-adapted; MWCC establishes retail offsets.

`func_0010c750` also remains ASM: **556B/560B**, **20 differing emitted
words** plus one zero-tail word, normalized diff 32. Its archive now uses
the correct coefficient symbols, **`fGpffff8208` at `0x007612F8`** and
**`fGpffff820c` at `0x007612FC`**, rather than the unrelated `8218/821c`
data hidden by the old relocation-masked score. Typed element indexing
retains the same residual without integer-address casts.

The curve candidate passes **93,673 native consumer cases** under
undefined/function sanitizers: low-halfword early returns before pointer
access, level clamps, every growth byte and persona ID, scenario records,
diagnostic continuation and unsigned result wrapping. Diagnostic cases
use valid fixture backing rows. High-bit polynomial levels use zero
coefficients to keep float-to-integer conversion in range; malformed
levels under ordinary coefficients are not claimed safe. This is C
behavior evidence, not an EE COP1 rounding or fused-operation emulator.

The full `make build-progress progress lint-errors` gate passes with
unchanged **7,758 overall MATCH / 4,962 ASM**, **6,128 first-party MATCH /
732 ASM**, and **172 C-linked objects / 1,566 functions**. Progress
snapshots validate; all 335 first-party files are lint-clean. Loadable SHA1
remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`; complete ELF SHA1
remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Native smoke
scaffolding is removed after the evidence is archived.

## Tile opacity floor and calendar fallback boundaries

The current-contract `00204b80` archive improves from eight differing
emitted words to **one**, at **460B/464B**: entry `andi` versus retail's
raw argument copy. An ordinary `s32 alpha = opacity` local replaces the
older inline frame-update helper and extra common-subexpression pragma.
Recompiling the installed archive preserves **all 115 existing MATCH
bodies** in `code1_0020.c`.

The inferred word-opacity API makes every target instruction exact, and
the actual draw callee already owns low-byte truncation. But migrating
both definition and live caller still changes three caller instructions:
the alpha byte load moves before the pointer/FPR moves. Explicit masking,
casts, locals, parameter order and scoped scheduling/propagation options
do not reconcile it. No incompatible local prototype is installed; the
target remains ASM. Promotion also requires registering the real
`D_00764564` byte, not the misleading `iGpffffb474` battle-pointer alias.

Native32 consumers execute the actual position, depth, color and mode
helpers under undefined/function sanitizer traps. The byte contract passes
**524,288 scenarios / 7,864,320 tile emissions**; the word contract passes
**2,097,152 scenarios / 31,457,280 emissions**. Coverage includes every
initial frame and opacity byte, positive/negative opacity high bits,
callback counter mutation and wrap, the 3×5 grid at two scales, callback
replacement and final resets.

`00110a60` remains **488B/496B**, with eight differing emitted words and
two zero-tail words. Its current signed getter contracts are already
correct. Direct typed-record access keeps the same residual count but
moves the field's `+2` from the load into relocation addends; a separate
record pointer retains retail addends without improving the register
floor. The verified fallback byte is **`0x005E3A04 + index * 6`**.
The retained candidate and actual date/override getter bodies pass
**2,682,750 native scenarios** under address/undefined/function sanitizers:
all 365 valid dates, null overrides, signed boundaries, phase selection,
sentinel fallback and short-circuit precedence. Invalid dates are outside
this evidence; no guards or behavior are invented.

These are archive/evidence changes only. Production matching and linking
remain at the preceding verified totals. Native scaffolding is removed.

## Coherent font character contracts and defined text normalization

`func_00105f00` now returns `s16`, matching the existing C consumer and
the signed-halfword normalization in retail `00205c20`, `00209dc0` and
`00209fa0`. It still reads signed-byte storage; the provider remains exact
at **72B/80B**. Combining the old provider with its consumer declaration
reproduces a C type conflict. The actual repaired provider passes
**3,072 cases** under address/undefined/function sanitizers, covering every
stored byte and both special-player and ordinary-table selection.

The font family now shares declarations in `fr_font_internal.h`:

- Creation is `u8 *(u8 *, s32 style, s8 character, s32 spacing, u8 *)`.
  The inherited `s64` style introduced extensions absent from retail.
- The draw helper's unused mode and all eight create/draw wrappers use a
  signed-byte character. Its value reaches glyph byte `+0x14`.
- `00274ed0` accepts the ninth word already passed by retail callers.
  This variant ignores it; its result remains a signed word.
- Live callers use the shared declarations. Obsolete declaration-only
  entries and conflicting local prototypes are removed; existing word
  handles and text buffers have explicit pointer conversions.

Narrowing only one wrapper or only the creator is not a valid cutover.
The coherent creator owner preserves **57/57 MATCH**, and the wrapper owner
preserves **14/14**, with complete relocation resolution. Eleven creator
calls explicitly sequence their character load; two dynamic-style calls
load style first. Style locals are ordinary words rather than inherited
`s64` temporaries. The remaining external callers retain their original
instructions with byte character locals and, in `00113800`, a plain-char
table read that keeps `lb` before the final `f14` move.

`func_00273cc0` also contained an unconditional signed left shift of a
negative encoded-text byte. Its normalization now shifts through `u64`,
as the neighboring line processor already does. The old actual processor
traps on the `0x80` encoded-text boundary under native32 UBSan; the repaired
processor, actual creator and actual glyph constructor pass **57,344
cases**, combining all character bytes with printable and multibyte text.
The creator's separate boundary consumer verifies glyph codes, spacing,
linked-list storage and append behavior.

The actual `00274ed0` wrapper, draw/layout helper, creator and glyph
constructor pass **9,216 native32 cases** under undefined-behavior traps.
Coverage includes all character bytes, word style values with equal low
bytes, finite positions/scales, horizontal alignment precedence, returned
widths, packed colors, ignored ninth arguments and release/retain paths.
This is native state/dispatch evidence, not PS2 raster verification.
Clang reports the pre-existing `&result != 0` tautological check; no
diagnostic is disabled. Removing that retail-preserving source shape
shrinks the provider from 324B to 312B and loses its match.

Two battle callbacks remain ASM:

- `00205c20`: **468B/480B**, **113 masked differing bytes / 47 emitted
  words**, or 49 words after resolving relocations, plus twelve zero-tail
  bytes. Defined unsigned packing replaces the old signed high-byte shift.
  The prior archive remeasures 480B/284 differing bytes under the current
  owner. The new floor preserves all 115 existing owner MATCH bodies.
  Its actual glyph-wrapper consumer passes **3,168 native32 cases**,
  including word-opacity boundaries and observable persona/slot reloads.
- `00207140`: **476B/480B**, **34 masked emitted word differences**, or
  36 fully resolved words, plus four zero-tail bytes. Typed four-byte item
  records tie the raw-address floor. The accepted ID precedes the second
  quantity query, and only the quantity is stored afterwards, preserving
  callback mutations to the ID and padding. **384 native cases / 98,304
  first item queries** cover unsigned skill boundaries, flag rejection,
  all eight accepted skills, all 256 accepted items and the complete work
  buffer under address/undefined/function sanitizers.

The integrated cohort passes `make build-progress progress lint-errors`:
**172 C-linked objects / 1,566 functions**, **6,128 first-party MATCH /
732 ASM**, validated progress artifacts and zero lint findings. Both retail
identities remain unchanged: loadable image
`3d1d3d2b9d6ccb60836db239ab49674223025a78`, executable
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Exact threshold selection and byte-contract drawing

`func_001d15a0` is now C: **212B/224B**, four fully resolved relocations,
zero executable differences and twelve zero-tail bytes. Grouping the
induction index and selected index into a two-`u16` cursor closes all nine
register differences without adding stack storage. Explicitly narrowing
`cursor.index` remains necessary even though both fields are halfwords.
Initializing the cursor before loading the three counters preserves retail
ordering; a structured loop then matches. The helper still receives its
complete four-halfword output buffer.

All **86 existing owner MATCH** bodies remain intact. The actual selector
passes **17,944 native cases** with address/undefined/function sanitizers:
signed gate results, unsigned high-bit counters and thresholds, nonmonotone
tables, first-hit precedence, all result positions and fallback. The fourth
helper counter is written even though selection only consumes the first
three. The historical scalar floor remains archived as such.

`func_002b6340` is now C: **536B/544B**, all 19 relocations resolved, zero
executable differences and eight zero-tail bytes. The canonical byte-color
and float-first/u8-opacity drawing contracts already remove the old
argument-order differences. Only two float loads remain in the current
baseline. The neighboring `002b9e10` pattern—field local, global local,
bounded `opt_propagation off`—puts those loads in retail order.

All **51 existing owner C matches** remain intact. The production callback,
actual color packer, actual sprite-packet constructor and queued state/render
callbacks pass **442,370 native32 scenarios** under undefined-behavior traps.
The fixture supplies frame data through a real byte copy, exercises every
opacity byte, signed state results, scale rejection/equality, both draw
modes, packet cleanup, signed offsets and callback-visible work mutations.
NaN comparisons reach the state gate; those cases stop before the downstream
float-to-integer scale conversion. This verifies packet/state behavior,
not PS2 raster output.

The integrated `make build-progress progress lint-errors` gate passes:
**6,130 first-party MATCH / 730 ASM (89.4%)**, **172 C-linked objects /
1,567 functions**, validated progress artifacts and zero lint findings.
Both retail SHA-1 identities remain unchanged.

## Exact sound start routine and explicit argument forwarding

`func_0045c640` is now C: **552B/560B**, all 32 relocations resolved,
zero executable differences and eight zero-tail bytes. Bounded
`opt_common_subs off` and `opt_propagation off` retain the separately
evaluated pre-stop/post-stop addresses. A scalar `outputHandle`, loaded
after stream activation, precedes both final halfword promotions. The
switch cases `0` then `-0x12B` preserve retail comparison order. No
aggregate scaffold, widened values or instruction barrier is needed.

The RPC declarations are `s32 func_0043c518(s32 handle, ...)` and
`s32 func_0043c5e8(s32 handle, ...)`. Both retail providers save all seven
unnamed argument registers; their packet construction consumes different
prefixes. Stop callers supply four arguments and the start caller supplies
five. The old fixed-five function cast is removed. No fifth stop argument
is invented: the assembly provider captures that register too, but its
downstream significance is not established by this recovery.

The existing `sdkSnd` wrappers declared themselves and their callees as
`(void)`, making no-argument calls that happened to preserve incoming
registers. They now explicitly forward two/four `s16` arguments through
`sdk_snd_internal.h` and still return `1`. Both wrappers retain their exact
**36B/48B** bodies; all 27 existing `sdkSnd` and six existing `sdkSndcom`
matches remain intact. Compiling the old wrappers against the real
contracts produces conflicting-type and too-few-argument errors.

The caller migration covers 38 source files: 30 live callers include the
shared header, while eight declaration-only entries need no replacement
include. Four small source repairs preserve existing instructions:

- `001f7ad0` drops two non-parameter register-liveness operands from the
  two-argument stop call; both discarded expressions were plain locals.
- `001f7cd0` reads the packet creator's three `u16` fields through an
  unsigned-halfword view, narrowing at the sound API boundary.
- `001f8070` reads its channel as `u16`, consistent with the same field's
  unsigned increment/wrap.
- `00108590` loads the duration halfword unsigned, then converts through
  the canonical signed-halfword parameter.

Focused caller comparisons preserve all **1,635 emitted C functions**
across those files. Three compiler-private jump-table names renumber in
`code1_001f`, but their locations, payloads and relocations are identical.
The existing randomized `__FILE__` payload in `code1_0035` remains a
scratch-compilation data difference, not an instruction regression.

The actual repaired wrappers and actual stop/start state machines pass
**112,320 native32 cases** under undefined-behavior traps. Coverage includes
valid slot/stream combinations, state/status rejection, active/inactive
streams, both accepted stop responses, error reporting, signed argument
boundaries, callback-visible handle reloads, activation before dispatch,
returned-handle storage and preservation of callback mutations and adjacent
records. The native backend interprets only arguments actually supplied by
each call. This is C state/ABI evidence, not execution of the PS2 RPC service
or audible-output verification.

A second native run routes **21,600** of those cases through the actual
`001f7cd0` packet callback before the repaired wrapper and start routine.
Unsigned stored argument boundaries retain the intended signed API values.

The integrated `make build-progress progress lint-errors` gate passes:
**6,131 first-party MATCH / 729 ASM (89.4%)**, **172 C-linked objects /
1,568 functions**, validated progress artifacts and zero lint findings
across 336 first-party files. Both retail SHA-1 identities remain unchanged.

## Shuffle initializer floor and order-sort preconditions

`func_00375f00` remains ASM, but its retained C candidate now uses ordinary
typed pointer arithmetic rather than integer-punned pointers. Both calls
share the cached context; state stores independently derive their views.
The current owner improves from 20 to **four differing bytes in two emitted
words**, **156B/160B** with four zero-tail bytes and both call relocations
resolved. At `+0x48/+0x70`, base recomputation still replaces retail's cached
base copies. All **44 existing owner C matches** remain intact.

The initializer with the actual motion/rotation provider bodies passes
**180 native cases under Clang undefined-behavior traps**. Coverage includes
all twelve records, provider mutations, state 5 between calls, state 3
after rotation, real subobject writes and untouched neighboring storage.
The candidate and archive require valid aligned backing storage and an
allocated record index; no range guard or final flag update is invented.

`func_001b11c0` retains its **192B/192B, five-word register-allocation
floor**, fully relocation-resolved, with all ten owner C matches preserved.
Its native32 candidate passes **262,080 UB-trap cases**: every binary
sequence of lengths 1–12 over four genus pairs, either selected genus,
high key bits, unique/duplicate action pointers, stable ordering and
untouched prefix/sentinel/suffix storage. Singleton actions may have a
null unit; full twelve-entry lists terminate before a protected guard page.

This is not a general-purpose sort. Nonempty input is a retail precondition,
not a recovered universal caller guarantee: the unsigned `count - 1`
underflows on empty input. Heterogeneous non-key genera can oscillate:
`[0,1]` with key `0x100` alternates forever. Preserve the 16-bit key and
predicate short circuit rather than adding a guard or narrowing away the
boundary. Both production ASM fallbacks remain in place.

The integrated `make build-progress progress lint-errors` gate retains
**6,131 first-party MATCH / 729 ASM**, **172 C-linked objects / 1,568
functions**, validated progress snapshots and zero lint findings across
336 first-party files. Both retail SHA-1 identities remain unchanged.

## Defined curve and label arithmetic; action transition evidence

These candidates remain ASM. The new evidence does not reduce their
retained instruction residuals or count them as recovered C functions.

`001bb790` now retains ordinary pointer arithmetic and the `RwV3d` seed
copy: **296B/304B**, **59 differing bytes in 21 emitted words**, six
relocations resolved and eight zero-tail bytes. All **22 owner C matches**
are preserved. The seed copy loads all components before output writes;
Y/Z products precede X accumulation. Cursor grouping, coefficient storage
and zero-hoisting variants do not close the scheduling residual.
**15,360 native UB-trap cases** cover valid ring indices, coefficient
boundaries, partial output overlap, seed-object aliasing and whole-buffer
preservation. This is C floating behavior, not an EE COP1 emulator.

`001b05d0` retains **492B/496B**, **42 differing bytes in 36 emitted words**,
nine resolved relocations and four zero-tail bytes. Its old 37-word
fndiff score included the tail. Natural `u16` induction and pointer
identity preserve all **104 owner C matches**. **16,896 native32 UB-trap
cases** cover packet-count deferral without side effects, unattached
actions without unit reads, genus branches, null/mismatching records,
first-table/fallback precedence, pointer reloads and final flag updates.
The real bad-status/death/final-flag operations run behind trace hooks;
reset, camera and destruction are instrumented, not resource-lifetime or
callback-table ABI verification.

The clear mask `0xFFF7FFFF` retains death bit `0x80000`; it does not clear
death. Promotion also requires reconciling existing owner declarations:
`002326f0` is `u32(int,u32)`, not `void(s32,s32)`, and `002428f0` returns
`u32`, not `s32`. Canonical-return probes retain the floor. Production
declarations are intentionally unchanged with the ASM fallback retained.

`00205e00` ties its prior **488B/496B, two-byte/two-word** floor: `addiu`
versus retail `daddiu` at `+0x58/+0x64`. All seven relocations resolve,
the zero tail is eight bytes, and all **115 owner C matches** survive.
The archived signed `index + 63` traps at `INT_MAX` under UBSan; unsigned
wrapping removes that undefined operation without changing the floor.

The corrected candidate passes **115,200 native32 UB-trap cases** through
the actual sprite, font-flag and message-submission providers. Instrumented
packet, allocation, setter and queue backends expose coordinate rounding,
scaled packet fields, low-byte opacity, arbitrary nonzero predicates,
RGB/opacity reset state, late message-handle reload and font bit `0x40`
clearing rather than restoration. Enabled messages use valid fixture
handles/indices. Extreme sprite IDs establish producer arithmetic only,
not texture-bank bounds or PS2 raster output.

The integrated `make build-progress progress lint-errors` gate passes
with unchanged **6,131 first-party MATCH / 729 ASM (89.4%)** and
**172 C-linked objects / 1,568 functions**. Progress snapshots validate,
all 336 first-party files are lint-clean, and both retail SHA-1 identities
remain unchanged.

## Ordinary triangle normal and renderer cache evidence

The retained `0014be50` candidate now uses an ordinary **12-byte normal**
and three `SVec3 *` triangle pointers instead of an inactive-member normal
union. The split constants still supply exactly eight XY bytes and four
Z bytes. Isolated MWCC replay retains **416B/416B**, all eight resolved
relocations, and four executable differences at `+0x60..+0x6C`.
The other 100 instructions and all 114 existing owner C matches are
unchanged. Retail holds XY across the Z load; the compiler stores XY first.
No fourth normal lane, explicit padding or object patch is introduced.
Production remains ASM.

The archived body passes **92,160 native Clang ASan/UBSan caller cases**:
empty and gated lists; head capture before the gate; exact helper result
`1`; first/second-triangle and linked-record precedence; strict height
endpoints, adjacent floats, infinities and NaNs; full unsigned IDs,
including successful ID `0xffff`; untouched failure output and output
aliasing the next link. Instrumented mutable helpers also establish
post-call point/triangle reloads and normal reuse within a record versus
reinitialization at the next record. These are caller-contract checks with
scripted helper outcomes, not execution of the retail triangle-crossing
algorithm or the PS2 floating-point unit.

For `001130c0`, three-field channel caches with alpha first, alpha last,
or unsigned alpha all emit **440B/448B and 15 masked differing words**
when G/B are assigned first. The aggregates do not constrain saved-register
allocation as required. They are discarded; the existing five executable
differences plus eight zero-tail bytes remain the better floor. Its
previously documented native evidence and Vec2f caller-migration
requirement are unchanged. No new MATCH is claimed for either routine.

The integrated `make build-progress progress lint-errors` gate passes:
**6,131 first-party MATCH / 729 ASM**, **172 C-linked objects /
1,568 functions**, validated progress snapshots, and zero lint findings
across 336 first-party files. Both retail SHA-1 identities are unchanged.

## Explicit ending-resource ownership release

The `0038f400` revisit identified a concrete contract defect in its adjacent
release wrapper. `0038f590(void)` invoked an unprototyped callback without
arguments. Its byte match depended on the incoming owner address surviving
in `a0`, not on a C argument being forwarded.

`0038f590(u8 *allocation)` now invokes the existing callback slot through
RenderWare's `void (*)(void *)` signature and passes the allocation.
`ed_res.c` declares the same wrapper signature and explicitly reconstructs
the pointer from `work[3]`. Its ignored copy return is correctly declared
`void *`; allocator parameter names now say `hint`, not `align`.
Provider evidence identifies `0x40000` as `rwMEMHINTDUR_GLOBAL`.

The original wrapper happens to pass a plain native call, but adding
ordinary Clang function-entry instrumentation makes its ownership assertion
fail: an undeclared argument is not preserved across instrumentation.
The repaired wrapper passes the same instrumented reproduction.
The actual release, direct teardown and outer teardown C bodies also pass
**1,536 ASan/UBSan/function-sanitizer lifecycle cases** with instrumentation:
loaded/unloaded flags, null owners, release-before-slot-cleanup order,
owned mapping contents and deallocation, callback global rebinding,
unchanged work records and outer global clearing. Allocation and slot
backends are native fixtures; this does not execute the PS2 heap service.

MWCC retains **40 executable bytes in the 48-byte retail window** for
`0038f590`, with **two resolved relocations, zero executable differences
and eight zero-tail bytes**. All **101 emitted functions** across both
edited owners preserve their bytes; only the wrapper's two relocation
symbol spellings change to the existing typed slot at the same address.
The final callback-prototype cast separately preserves all 95 emitted
functions and relocation records in its owner.

Neither larger candidate is promoted. `001b1020` retains **408B/416B,
17 resolved executable differences and eight zero-tail bytes**, preserving
all ten owner C matches. Four new phase/transition forms reproduce the
scalar candidate exactly and are discarded. `0038f400` retains
**396B/400B, 16 resolved executable differences and four zero-tail bytes**,
preserving all 77 owner C matches. Local layout and region-initializer
forms tie; in-place boundary publication regresses. The retail debug name
is `ed_staff.c`, and eventual promotion still needs a canonical
pointer-return factory/accessor contract.

The integrated `make build-progress progress lint-errors` gate passes:
**6,131 first-party MATCH / 729 ASM**, **172 C-linked objects /
1,568 functions**, validated progress snapshots and zero lint findings
across 336 first-party files. Both retail SHA-1 identities are unchanged.

## Canonical ending-staff accessor pointer contracts

`include/ed_staff_internal.h` now owns the shared release and three
accessor declarations, used by `op_fade_grouped.c`, `ed_scroll.c`,
`ed_res.c` and `code1_0038.c`. `0038f5e0` and `0038f5f0` accept
`const u32 *`, matching their scrolling callers, and read header words
four and one directly. `0038f5c0` uses the caller's unsigned index type.
Packed address/count fields and accessor return values remain `u32`;
the resource layout is unchanged. The accessor migration requirement
above is resolved; the unmatched factory still needs its pointer-return
contract when promoted.

The prior integer-parameter accessor fails through the actual native
`0038ec50` consumer with an owner at `0x90000000`: it reconstructs
`0xffffffff90000010` instead of reading the header at `0x90000010`.
The pointer-parameter accessor passes the same reproduction. This exposes
the incompatible C declarations on a 64-bit host, not an observed PS2
runtime crash.

The actual owner getter, three accessors and three control-stream
consumers pass **6,284 UBSan cases** with low and high-bit 32-bit owner
addresses, plus **6,284 ASan/UBSan cases** at low addresses. The high-bit
mapping overlaps ASan's reserved shadow range, so that run uses UBSan
only. Coverage includes text-entry lookup, full count-word reads,
unsigned command/argument bytes, known-command advancement, unchanged
unknown commands, work-record preservation and untouched resource headers.
Native mappings and type adaptation are fixtures, not PS2 execution.

All **119 object functions** across the four owners preserve bytes and
relative relocations, including their existing assembly fallbacks.
The three accessors separately retain exact executable code:
`0038f5c0` is **24B/32B**, `0038f5e0` and `0038f5f0` are each
**12B/16B**; all missing tail bytes are zero alignment. No new MATCH
is claimed from this contract repair.

The integrated `make build-progress progress lint-errors` gate passes:
**6,131 first-party MATCH / 729 ASM**, **172 C-linked objects /
1,568 functions**, validated progress snapshots and zero lint findings
across 337 first-party files. Both retail SHA-1 identities are unchanged.
The recovery-quality typed count increases from 2,167 to **2,169**.

## Memory-card task forwarding and enemy bitmap boundaries

`mc.c` now declares `00452560` exactly like the existing SDK provider:
`u32 func_00452560(void *task)`. The result is the packed address word
at task offset `0x38`, not an implicit current-task lookup.
`002a4b10`, `002a4cb0` and `002a6510` explicitly forward their task
argument and decode the returned address. The teardown callback now
accepts its previously implicit argument; its constructor binding remains
unchanged. The SDK provider and unrelated task APIs are intentionally
unchanged.

The old update path fails a native instrumented getter assertion because
the task argument was not supplied. The repaired actual update, teardown
and dispatch bodies pass **1,412 ASan/UBSan cases** with two mapped owners:
state transitions, readiness-query order, dispatch precedence, callback
flag mutations and teardown handle reload/order. Native instrumentation
exposes a C forwarding error; it is not evidence of a retail PS2 crash.

`g_data.c`'s `0010f3d0` setter and `0010f420` query now use `1U` for
their bitmap masks. Both old paths trigger UBSan for the valid bit-31
position. Both reproductions pass after repair, along with **43,520
ASan/UBSan cases** across all 2,720 bitmap bits, low-16-bit input aliases,
initial bit patterns, repeated sets and neighboring-word preservation.
The getter still returns the selected mask, not a normalized Boolean.

Independent before/after object comparisons preserve function bytes and
relative relocations for all **31 emitted `mc.c` functions** and all
**137 emitted `g_data.c` functions**. No new MATCH is claimed from either
repair.

## Refreshed AI, rectangle, calendar and clamp residuals

The retained candidates were replayed against the current retail image
with every target relocation resolved. Executable differences below do
not count omitted all-zero alignment:

| Function | Emitted / window | Executable differing words | Zero tail | Relocations |
| --- | ---: | ---: | ---: | ---: |
| `001db360` | 544 / 544 | 10 | 0 | 8 |
| `002a4d10` | 524 / 528 | 59 | 4 | 13 |
| `00110a60` | 488 / 496 | 8 | 8 | 15 |
| `0021de90` | 440 / 448 | 3 | 8 | 5 |

`IDA_001db360_body.c` improves the old 17-word floor by promoting the
loaded `u16` command normally to `s32` and continuing on a short-circuit
nonmatch. Only rejection/increment block order remains. All 257 existing
owner C functions preserve bytes and relocations. The candidate and the
actual repaired bitmap provider pass **15,360 ASan/UBSan cases** covering
bit 31, signed status results, bypass/enable precedence, command rejection
and ordered helper queries. The retail count provider returns eight;
the `u16 i < count` loop also cannot execute a wrapping increment for any
representable `u16` count.

`PoD_002a4d10_body.c` retains a reconstructed RGBA/four-`s32` rectangle
animation with explicit task forwarding. Ordinary 16-byte aggregates
produce `lq`/`sq`; no artificial alignment or 128-bit wrapper is needed.
Both templates are `{0,0,640,0}`. The two colors are RGBA
`{255,233,44,255}` and `{40,40,40,255}`, not floating-point values.
The bounded O1 candidate preserves all 23 existing owner C functions and
passes **1,470 ASan/UBSan cases** for clamp boundaries, color/geometry,
easing-call order, callback-driven frame reloads, cached work ownership
and reset transitions. Easing/drawing are controlled native fixtures,
not a rendered PS2 frame. Scheduling and aggregate stack positions remain
unmatched; the primitive's float-typed rectangle interface still requires
a coordinated correction before promotion.

The calendar and calculation candidates do not improve. Their archive
headers now distinguish eight and three executable residual words from
their respective eight-byte zero tails. Six new calendar join/accessor
forms and two inline calculation boundaries do not close those residuals;
all 46 and 94 existing owner C functions respectively preserve bytes and
relocations. Calendar getter widths remain justified by their providers.
The calculation requires valid tables, a nonzero divisor, safe signed
arithmetic and finite representable intermediate conversions: its final
clamp cannot rescue an earlier invalid float-to-int conversion.

All four routines remain assembly-backed. Neither native source behavior
nor a zero-tail discrepancy is treated as an instruction match.

The integrated `make build-progress progress lint-errors` gate passes:
**6,131 first-party MATCH / 729 ASM**, **172 C-linked objects /
1,568 functions**, validated progress artifacts and zero lint findings
across 337 first-party files. Both the loadable-image and whole-retail-file
SHA-1 identities remain unchanged.

## Exact field raycast and complete hit-point contracts

`func_0016b540` is now C in `k_fldFrame.c`: **560 / 560 bytes**, zero
fully relocated differing words and all **12 relocations resolved**.
Its other 15 emitted owner functions remain unchanged.

The closing source shape snapshots both endpoints before provider calls
and gives each branch its own complete `FldFrameRaycast`. Grid lookup uses
the **start** point's X/Z coordinates, follows the first matching entry
through `+0x1a0`, and stops even when that first entry has no collision
collection. The non-grid branch reloads the root after the mode query.
Ordinary signed multiplication emits the same retail shifts without
undefined left shifts of negative indices. Valid mapped records and
finite, representable coordinate arithmetic remain caller preconditions;
no new guards or artificial alignment were introduced.

`Kosaka/k_fldFrame_internal.h` now owns the shared three-float vector and
raycast declaration. All three C consumers use it. `0014c540` previously
declared an eight-byte `s64` hit member followed by padding, despite the
callback writing X, Y and Z. It now declares a complete vector in the
same stack span. The private `E9F0Vec3` copy in `code1_0016.c` is replaced
by the shared type, not retained as an alias. The direct-hit callback uses
the actual typed raycast state; its **240 emitted bytes** are unchanged.

The retail nearest-distance sentinel at `0x007613a4` is **FLT_MAX**
(`0x7f7fffff`), not 1.0. The consumer fixture exposed that mistaken fixture
assumption before the retail constant was read and used.

## Clump iterator, callback and material metadata cutover

The existing `Kosaka/k_clump_internal.h` already specified a pointer-returning
iterator and `void *callback(void *object, void *data)`. Its `003bff30`
implementation still returned an integer and invoked callbacks through
`int (*)(int, int *)`. The actual model callback reproduces a
**UBSan incorrect-function-type failure** through that old iterator;
the repaired iterator preserves the complete returned pointer and performs
the geometry flag update under ASan/UBSan/function sanitization.

The cutover covers the iterator, its C consumers and 26 callback
definitions across core, field, model and effect owners. Conflicting local
declarations and callback casts are removed. The three recursive clump
userdata callbacks now accept the shared opaque context with typed locals.
The material metadata providers consume their existing shared declarations;
material-array count queries receive their actual material argument.
Animation string queries retain their provider's packed-address return
contract but now declare and pass its real pointer argument.

`00462ae0` accepts a clump object, not a function pointer, and returns its
allocated resource-classification record or null. Its model and field
consumers store that result as a pointer. The resource builder keeps the
retail category priority **0,1,7,8,5,6,9,2,4,3**, list ordering, fog counts
and discard decision. The private `func_003bff30_typed` call/declaration is
removed rather than retained as a compatibility path.

Independent original/final object comparisons preserve **849 existing C
functions**, or **1,076 emitted functions including assembly fallbacks**,
across the 19 affected code owners. Comparison includes every instruction
and function-relative relocation target. Compiler-local constant names
changed in four consumers but retain identical section contents/offsets;
the removed iterator alias and canonical name resolve to the same address.
The new field raycast is checked separately against its complete retail
window, rather than counted as a before/after preserved function.

## Native field and clump behavior evidence

The throwaway executables compile the actual recovered functions and use
controlled external engine providers; they are not a rendered PS2 frame.
Packed-record scenarios run as freestanding 32-bit i386 executables under
`qemu-i386`, avoiding widened host pointers in four-byte tables. The
raycast/iterator scenarios also run on the 64-bit host with address,
undefined-behavior and function-type sanitizers.

| Executed surface | Cases | Observable contracts |
| --- | ---: | --- |
| Raycast and actual collection iterator | 1,249 | Direct hit/miss, signed cell boundaries, start-point lookup, first duplicate, provider mutations, root reload, endpoint snapshot, nearest/equal hits, cached-next detach and early stop |
| All three actual field consumers | 196,728 | Forward/reverse visibility, strict distance thresholds, stable nearest unblocked selection, complete hit vectors, height transitions and companion synchronization |
| Packed model/material animation | 148,224 | Actual iterator and metadata providers, material filtering, three-float colors, first insertion, per-array string deduplication, 16-bit count wrap and adjacent storage preservation |
| Clump resource builder | 25,600 | Actual builder/callbacks, retail category priority, missing geometry, grouped reverse order, fog counts and retained/discarded ownership |

These are **371,801 cases**, with the 1,249 raycast/iterator scenarios
additionally exercised on the other host pointer width. The callback ABI
failure/repaired run is a separate before/after reproduction.

## Primitive rotation residual correction

`Lng_0045e8e0_body.c` and `MnB_0045eb20_body.c` now retain the measured
`PrimBatch` candidates with the actual `iGpffff81d0` conversion cached
across both trigonometric calls. Center X is `s32`; center Y remains `s16`.
Both ordinary C product-seeded `mula`/`madd`/`add` chains are reproducible,
contradicting the old blanket FPU-floor comments.

| Function | Emitted / window | Resolved differing overlap words | Missing executable zero bytes | Missing alignment |
| --- | ---: | ---: | ---: | ---: |
| `0045e8e0` | 560 / 576 | 100 | 4 | 12 |
| `0045eb20` | 568 / 576 | 102 | 4 | 4 |

Both resolve all 14 relocations and preserve the owner's five existing
C functions (3,056 bytes). The raw-register/scheduling residual remains;
this is not an improvement over the historical nd88 score. These are
compiler experiments only, with no new native geometry or rendering
claim. Both retail functions remain assembly-backed.

The recovered symbol inventory was regenerated, removing the retired
iterator alias without changing any retained address. All **14 recovered-symbol
invariant tests** pass. The final `make build-progress progress lint-errors`
gate reports **6,132 first-party MATCH / 728 ASM**, **172 C-linked objects /
1,569 functions**, validated progress artifacts and zero lint findings
across 338 first-party files. The loadable-image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete retail file remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Field dispatcher: one remaining branch target

`LFF2_0016b080_body.c` now retains a **476 / 480-byte** candidate with
**one fully relocated executable-word difference**, down from **78** in
the previous retained body. Both versions have ten relocations and omit
only four zero alignment bytes. The old 72-word figure used relocation
masking; it was not a fully resolved comparison.

The closing source choices are a real early return for a null cached root
and one inline preferred/fallback collection selector reused in both
resource paths. Collection fields are pointers, and both cached and reloaded
root accesses use the same resource-pointer type. Shared floating constants
and signed grid multiplication reproduce the remaining instructions without
register constraints, undefined shifts or artificial padding.

At **+0x134**, retail branches directly to **+0x154**. The candidate instead
branches to **+0x140**, whose branch then reaches **+0x154**. That extra
branch path remains an instruction mismatch: the function stays
`INCLUDE_ASM`. The zero alignment tail is reported separately, not treated
as missing executable code or patched into the object.

Independent full-owner comparison preserves all **15 other emitted
functions**, including the owner's **ten existing C matches**, with identical
instruction bytes and relocation identities.

A native 64-bit **ASan/UBSan/function** scenario passes **1,492,992 cases**:
signed cell boundaries with independently tabulated expected indices;
mode values -1, 0, 1 and 2; null/disabled/cached roots; root replacement
during provider calls; coordinate mutation after index calculation; zero
and high-bit unsigned keys; absent entries; first duplicates with both
nonnull and null collections; preferred/fallback choices; and overlapping
three-float output buffers. Actual collection objects are passed as pointers.
The fixture uses native typed layouts and a packed frame-handle adapter;
this is not a claim of executing retail code or native 32-bit layout testing.

The accompanying independent replays do not close their prior residuals:

| Function | Emitted / window | Resolved executable-word differences | Zero tail |
| --- | ---: | ---: | ---: |
| `0014be50` | 416 / 416 | 4, at +0x60 through +0x6c | 0 |
| `001d8cb0` | 312 / 320 | 4, at +0xd8 through +0xe4 | 8 |

The triangle retains its ordinary 12-byte normal and shared vector type.
The battle selector retains the first-entry short circuit before reading
its best-distance variable; reversing that source order would introduce
an uninitialized read. Neither residual is promoted, and no new native
behavior claim is made for those two replays.

Archive replay succeeds with:

```sh
python tools/probe_archive.py docs/probe_archive/LFF2_0016b080_body.c src/Kosaka/Field/k_fldFrame.c
```

That tool's legacy score is **2**: the branch mismatch plus one omitted
zero-tail word. The fully relocated measurement above separately checks
all ten linker-owned fields.

## Fresh functions instead of repeated compiler floors

`shdScript.c::func_0025c790` is now ordinary C: **996 / 1008 bytes**,
all **45 relocations resolved**, no executable differences, and twelve
zero alignment bytes. One full state-machine reconstruction and one
evidence-led refinement closed it. Keeping rank snapshots promoted until
the actual halfword provider boundaries avoids redundant narrowing;
the bounded comparisons preserve retail's condition temporaries.
Point addition uses unsigned arithmetic before the signed cap comparison,
preserving the retail 32-bit wrap without signed-overflow undefined behavior.

The update and release callbacks receive their task explicitly. The
work getter retains its actual packed-address `u32(void *)` contract;
the scene lookup returns a resource pointer rather than a truth-value
integer. The four previously matching functions retain identical emitted
instructions and relocation identities.

A throwaway native 64-bit ASan/UBSan/function fixture passes **725 cases**
plus two distinct release contexts. It exercises initial field selection,
allocation failure, pending messages, unchanged and changed rank paths,
point-cap and integer-boundary inputs, all five parameter indices,
termination, unknown states, signed slot narrowing, and old/new text
selection. Work and text addresses use an explicit low-address mapping for
the packed retail providers. Other provider behavior is supplied by the
fixture; this is not hardware execution or an end-to-end game-runtime claim.

The two larger fresh reconstructions were measured independently:

| Function | Emitted / retail | Resolved executable differences | Disposition |
| --- | ---: | --- | --- |
| `00155360` | 2192 / 2192 | Three reordered argument-setup words at +0x1b0..+0x1b8 | Retained in `FFS_00155360_body.c`; production ASM |
| `00114460` | 2124 / 2128 | 472 differing words; frame 0x130 versus 0x120 | Production ASM; no near-match body retained |

The field candidate resolves all **112 code relocations** and its complete
**19-entry, 76-byte switch table** exactly apart from the stated three code
words. Its update result is signed: normal/default paths return zero;
state 18 clears the field task handle and returns -1. The owner declaration
now reflects that scheduler-consumed return value. Both existing C owner
functions remain retail matches. Replay:

```sh
python tools/probe_archive.py docs/probe_archive/FFS_00155360_body.c src/Kosaka/Field/k_field.c
```

The skill reconstruction resolves all 37 relocations and omits only four
zero alignment bytes, but its executable allocation and scheduling still
diverge substantially. Neither larger candidate has a new native behavior
claim. These results do not justify another register-permutation sweep.

The full `make build-progress progress lint-errors` gate passes:
**6,133 first-party MATCH / 727 ASM**, **172 C-linked objects / 1,570
functions**, validated progress artifacts, and zero lint findings across
338 first-party files. The loadable-image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete retail file remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Fresh battle dispatchers and truthful provider contracts

Two previously unworked dispatchers are now ordinary matching C in
`src/promoted/code1_0022.c`:

| Function | Emitted / retail window | Resolved evidence |
| --- | ---: | --- |
| `func_0022bd60` | 1744 / 1744 | All 152 relocations and all 22 switch targets exact |
| `func_0022e630` | 1172 / 1184 | All 28 relocations exact; twelve genuine zero alignment bytes |

The setup dispatcher retains the complete 22-case configuration and the
signed-byte sentinel loop. A function-local `opt_loop_invariants on`
bracket reproduces the loop without affecting neighboring functions.
The action dispatcher retains all 19 battle-specific branches, including
four unconditional enqueue attempts for battle `0x215`.

The new consumers exposed existing provider declarations that had relied
on physical register contents instead of valid C contracts:

- `func_0010b010` and `func_0010b060` return persona pointers and carry the
  full input ID through to `func_0010cad0`. The initializer masks the ID
  itself; a false halfword-only declaration is not a substitute.
- `func_00104dc0` returns `u16`; `func_00104e30` returns `u32`.
  Their promoted `s32` ID input is narrowed to signed halfword inside
  each provider, as retail does. Consumers retain their own required
  signed narrowing explicitly.
- `func_00105610` returns the real `u32` death predicate from
  `datCalcIsDead`, rather than declaring a void result that callers use.
- `func_00105d50` forwards the complete `u32` status mask to
  `datCalcClearBadStatus`. The party-revival consumer uses the real
  `datGetPartyId` return and typed predicate/setter contracts.
- The HP-clamping consumer stores the `u16` maximum directly into its
  halfword temporary, avoiding redundant widening at both branch arms.

The corrected owners pass focused verification. One formerly counted
match, `y_fclCombine.c::func_002f9c30`, exposes a real residual when its
initializer declaration is corrected: two argument-setup instructions
are reversed, eight differing bytes in a 348-byte body and a 352-byte
window. Its typed C is preserved under `NON_MATCHING`; production uses
the retail ASM. No narrow-prototype shim, volatile staging, or artificial
instruction was added to keep the old score. Thus two new exact functions
produce a truthful **net gain of one match**.

Throwaway wasm32 executions preserve the target's 32-bit pointer model:

- **252 setup cases** cover all switch entries, out-of-range battle codes,
  prior flag values, repeated lookups, the event flag, and complete state
  preservation outside the required writes.
- **171 action cases** cover the battle branches, persona selection,
  stat boundaries, status masks, queue availability, provider-effect
  ordering, and the four unconditional enqueue attempts.
- **144 status-transition cases** execute the current production wrappers
  with the actual `datCalcIsDead` and `datCalcClearBadStatus` leaves. They
  cover hero/party selection, zero and nonzero HP, death and unrelated
  status bits, zero/selective/full masks, and unchanged neighboring memory.

The first two fixtures supply external provider behavior; the third uses
the actual status leaves. These are source behavior checks, not hardware
execution or an end-to-end game-runtime claim. Exact executable and
relocation comparisons remain the matching proof.

Other full fresh reconstructions remain ASM:

| Function | Emitted / window | Measured residual | Source reference |
| --- | ---: | --- | --- |
| `00268230` | 1596 / 1600 | 13 executable words / 46 bytes at +0x480..+0x4b0 | `FF2_00268230_body.c` |
| `00252710` | 864 / 848 | 203 executable words; 16-byte overrun | `FF2_00252710_body.c` |
| `002232a0` | 1024 / 1040 | 778 overlap bytes, ten switch bytes, six nonzero bytes in missing suffix | `FF2_002232a0_body.c` |

These references live in `docs/probe_archive`; they are not standalone
translation units or installed matching bodies.

The dungeon candidate resolves all **45 relocations**, all fourteen
constant objects, and the complete **1,444-byte entry table**. Its full
0x58-byte node payload and COP1 polynomial accumulator chain match.
Only the entry-pointer recomputation and its lifetime across the first
16-byte copy remain different. The actual task must be passed to the
canonical packed-address work getter at every affected owner consumer.

The rank callback resolves all **24 relocations**. Context is the third
callback argument, not a return from the interpolation leaf:
`func_00252230` returns void. Its resource-handle provider
`func_0025f360` returns a 32-bit value. The candidate still needs an extra
saved register and a 0x100 frame versus retail's 0xf0.

The reward dispatcher resolves all **26 code and nine table relocations**.
The complete position pair and eleven option words are retained.
Future integration requires a `s32(void *task)` callback, the canonical
`u32 func_00452560(void *task)` getter, and recovery of the existing owner's
no-argument getter consumers (`002218e0`, `00221940`, `002231e0`,
`00223240`, `002236c0`, `00223830`, `00223890`, `00223ee0`,
`00224040`, `00224080`). The explicit consumers `002230e0`, `00223730`,
`00223f40`, and `0022bad0` also require contract review. Its candidate does
not imitate retail's uninitialized-register behavior for a corrupted
persona index; equivalence is limited to valid retail state. No matching
or native-behavior claim is made for these three nonmatching candidates.

The complete `make build-progress progress lint-errors` gate passes:
**6,134 / 6,860 first-party matches, 726 ASM fallbacks**, **172 C-linked
objects / 1,570 functions**, validated progress artifacts, and zero lint
findings across 338 first-party files. Both hashes remain unchanged:
loadable image `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
retail file `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Fresh formation followup and the first motion reconstruction

`code1_0022.c::func_0022c430` matched on its first complete reconstruction,
without a refinement: **1,876 executable bytes / 1,888-byte window**,
**123 code relocations**, and the complete **22-entry, 88-byte switch
table** with all 22 table relocations resolved. The twelve omitted bytes
are genuine zero alignment. Every lookup/allocation/set/store sequence
and its post-provider global reload is retained.

The allocation provider `btlFormation.c::func_001d3d50` now explicitly
returns its allocated formation address as `s32`, with the existing
promoted `u32` mode input. It no longer declares a void operation while
callers consume its preserved result register. The five existing compiled
C consumers were located through both source discovery and actual
relocations; their declarations were reconciled. All four affected
owners pass focused verification, including the new dispatcher.

A native non-PIE fixture passes **131,072 scenarios**: every `u16`
selector in stable-global and allocator-rotating-global modes. It checks
call order, distinct allocation handles, linked resources, destination
slots, prior-store visibility, and unchanged state. Provider lookups and
allocation are supplied by the fixture; every native address is asserted
to fit losslessly in the target's 32-bit handle representation.
An additional wasm32 fixture executes the **actual production allocator
and setter** for **18 cases**, covering all mode branches, high input
bits, prior memory contents, returned handles, and subsequent data
attachment. Only heap allocation and diagnostic output are supplied.

`code1_001c.c::func_001c1040` received its first complete C reconstruction.
The old archive contained only an ASM baseline and explicitly recorded
no source probing. Its blanket COP1 limitation was false: ordinary C
emits both `adda.s`/`madd.s` and `adda.s`/`msub.s` pairs. The retail
offsets are +0x564/+0x568 and +0x578/+0x57c.

The closer full candidate is preserved in
`docs/probe_archive/P01C_001c1040_body.c`: **1,876 / 1,888 bytes**,
all **48 relocations resolved**, **899 overlap bytes / 312 executable
word positions differing**, including eight missing executable bytes.
The single aggregate-layout refinement was worse, at 1,908 bytes.
Production remains ASM; no native-behavior claim is made for this
nonmatching body. Its complete poses, bounds output pointers, conditional
byte-state write, real extra normalization, and unordered float
comparison behavior are retained. No compiler-floor sweep follows it.

The complete gate passes at **6,135 first-party MATCH / 725 ASM**.
C-linked coverage remains **172 objects / 1,570 functions**; progress
artifacts validate, and all 338 first-party files have zero lint findings.
The loadable-image and complete-retail SHA-1 hashes remain unchanged.

## Fresh enemy reaction dispatcher

`code1_0022.c::func_0022eba0` is now ordinary C: **2,428 executable bytes
/ 2,432-byte retail window**, with all **115 code relocations resolved
exactly**. These comprise 63 call relocations, 48 GP-relative relocations,
and two HI16/LO16 pairs. The remaining four retail bytes are zero alignment.
No matching pragma, artificial instruction, or padding was added.

The first complete candidate emitted 2,420 bytes: eight executable bytes
were missing, producing 1,798 overlap-byte differences after the shift.
One evidence-led refinement closed the actual source-shape differences:

- Keep the single-case action switch inside the `0x105` mode guard.
- Load the model handle in a preceding statement before each callback;
  do not cache it across callbacks.
- Use the structured linked-list loop rather than a flattened conditional
  goto, preserving the retail backedge polarity.

The integrated aggregate declarations agree with the existing unit
providers. Quaternion construction receives its output, axis, angle, and
mode; rotation receives the complete quaternion, and color is passed by
value. HP mutation, effect removal, and status clearing retain their real
provider contracts. In particular, `datCalcClearBadStatus` complements its
mask: the `0xFFF7FFFF` argument here **preserves only status bit `0x80000`**,
not the other way around.

A throwaway wasm32 execution passes **66,099 scenarios**, using the
integrated dispatcher and five actual production provider bodies:
`func_002325a0`, `func_00233880`, `datCalcClearBadStatus`,
`btlUnitSetRot`, and `btlUnitSetColor`. It exercises all 65,536 selector
values, all signed-byte sentinel representations, early gates, each
transformation phase, event-flag precedence and random selection,
linked-list filtering, guarded rotation, and direct/array target
restoration. Model callbacks replace their handles between calls, exposing
stale caching. Array cases include zero targets and current-target
membership; unrelated targets remain unchanged.

Lookup, maximum-HP lookup, event flags, RNG, quaternion construction,
model callbacks, and engine update/cancel requests are fixture-provided.
This is a source behavior check with genuine 32-bit pointers, not console
or end-to-end game execution. The complete executable and relocation
comparison is the matching proof; the smoke scaffolding is removed.

The complete `make build-progress progress lint-errors` gate passes at
**6,136 first-party MATCH / 724 ASM**, with **172 C-linked objects /
1,570 functions**, validated progress artifacts, and zero findings across
338 first-party files. Both the loadable-image and complete-retail hashes
remain unchanged.

## Fresh reaction setup and start dispatchers

Two previously unattempted helpers in `code1_0022.c` are now ordinary C:

| Function | Executable / retail window | Fully resolved relocations |
| --- | --- | --- |
| `func_0022d600` | 1,412 / 1,424 bytes | 59 code: 27 calls, 18 GP-relative, seven HI16/LO16 pairs |
| `func_0022dc70` | 2,164 / 2,176 bytes | 74 code: eight calls, 38 GP-relative, fourteen HI16/LO16 pairs; 20 jump-table entries |

Both integrated bodies have zero differing executable bytes or words, no
unresolved relocations, no missing instructions, and no window overrun.
Each remaining 12-byte tail is retail zero alignment. The start dispatcher's
complete 80-byte selector table also matches. No artificial padding or
register pinning is used.

The setup helper retains its real, unused source input, affected packet,
and signed HP-delta pointer; `btlTarget.c` now declares that precise contract.
Its unsigned counter update preserves modulo-32-bit arithmetic before the
signed clamp. The start helper's first complete candidate differed in nine
saved-register uses. Declaring the list cursor before the `started` flag
closed all nine differences without changing control flow.

The matrix translation wrapper `func_0047a180` now explicitly forwards all
three inputs to `RwMatrixTranslate` and returns the resulting matrix pointer.
Its consumers retain their original matrix/vector addresses and combine
modes; they no longer depend on a zero-argument C forwarding body.

A throwaway wasm32 setup smoke passes **79 scenarios** using the integrated
dispatcher and six actual provider bodies: `datCalcChkBadStatus`,
`func_002325a0`, `func_001d9740`, `func_001fae60`, `func_0047a180`, and
`mdlScale`. It checks status branches, unsigned counter boundaries, callback
storage, overlapping HP-display thresholds, model-handle replacement between
calls, paired-unit HP clamping and fallthrough, and all three translation
modes with real 32-bit pointers. Whole-state comparisons check unrelated
storage remains unchanged.

Maximum-HP lookup, registries, event/counter storage, material mutation, and
matrix mathematics are fixture services. The real matrix wrapper is executed,
not the canonical RenderWare mathematics implementation. Scheduled callback
bodies are not invoked. This is source-level behavior evidence, not console
or end-to-end game execution.

The start dispatcher separately passes **73,974 wasm32 scenarios**, including
all 65,536 selectors, signed-byte stages, action gates, flag preservation,
list filtering, and both countdowns across `INT_MIN` through `INT_MAX`.
The actual `func_001fae60`, `datCalcChkBadStatus`, and `btlActionSetState`
bodies execute alongside it. Every scenario compares all 24,832 bytes of
fixture state. The independent oracle uses the authenticated retail
jump-table destinations, not the candidate table.

List-node genus and ID are deliberately not filters here; the smoke varies
them to detect invented restrictions. Countdown decrements are guarded by
`> 0`, so even the signed extrema introduce no overflow. Battle/flag inputs,
callback and data identities, and the state-25 engine initializer are fixture
services; registered initializer/updater bodies are not executed. The smoke
checks the real action-state transition and dispatch order, not the external
state-25 initializer's game behavior. Both throwaway smoke fixtures are removed.

The complete `make build-progress progress lint-errors` gate passes at
**6,138 first-party MATCH / 722 ASM**. C-linked coverage remains **172
objects / 1,570 functions**. Progress artifacts validate, all 338 first-party
files have zero lint findings, and both the loadable-image and complete-retail
SHA-1 hashes remain unchanged.

## Fresh task builders and constructor return contracts

`func_00229da0` now has its first complete ordinary-C probe, preserved in
`docs/probe_archive/P022_00229da0_body.c`; production remains ASM. The first
candidate emitted 2,304 bytes against 2,312 executable retail bytes. One
cast/lifetime refinement emits **2,308 / 2,320 window bytes**, with **75
code relocations and nine table relocations resolved**, but still has
**1,481 differing overlap bytes / 458 executable word positions differing**,
including four missing executable bytes. Nine bytes of the 36-byte table
differ. The final eight retail bytes are zero alignment. No further sweep,
padding, register pinning, or fabricated inputs followed the measurement.

The complete two-pass task construction retains 64-bit dependency and action
UIDs, both coordinate outputs, initialized 32-byte configurations, all six
switch arms, callback reloads, and the second pass's otherwise-unused list
walk. This is a measured nonmatch, not a claimed compiler floor or native
behavior match.

`func_0022a730` has a different blocker, recorded in its existing archive.
The first pass assigns `$s1` only after a status match at `0x0022a7f8`,
but `0x0022a80c` reads it even when no match occurred. Reviewed scheduling
and invocation paths establish neither a matching-node invariant nor an
ordinary C input for that register. A decoded retail-prefix experiment with
identical empty-list memory and explicit arguments returns when incoming
`$s1` is zero, but reaches allocation when it is `0x4000`. No external call
was executed; this is not a claim that empty lists are normal gameplay.
Production stays ASM rather than inventing initialization, another argument,
or an undefined C local.

The task-builder review also exposed two real C return-contract errors:
`btlSound.c::func_001f7c20` and `btlEffect.c::func_00202010` were declared
`void` despite callers consuming their allocated packets. Both now explicitly
return `BtlPacket*`. The live `func_001b0300` sound consumer uses the same
declaration; existing ASM consumers need no binary change.

Focused verification keeps both providers and the affected live consumer
matching. A throwaway wasm32 consumer executes the actual constructor bodies,
receives separate writable allocations, and attaches distinct full 64-bit
dependencies without aliasing the other packet. Restoring the previous
`void` bodies makes that C consumer fail to compile; the corrected bodies
compile and execute successfully. Allocation is fixture-provided and engine
callbacks are not executed. The throwaway reproduction is removed.

Complete relocation checks confirm **116 / 128 bytes** for the sound
constructor (five relocations) and **92 / 96 bytes** for the voice constructor
(three relocations), with zero differing bytes or unresolved symbols. Their
12- and four-byte tails are retail zero alignment.

The full gate after these contract fixes passes at **6,138 first-party
MATCH / 722 ASM**, with **172 C-linked objects / 1,570 functions**, validated
progress artifacts, zero findings across 338 first-party files, and both
retail hashes unchanged.

## Fresh status and resource probes; complete packet returns

`func_002240e0` now has a complete ordinary-C reconstruction in
`docs/probe_archive/P022_002240e0_body.c`. Its first candidate was 868 bytes;
contiguous seven-float transform records, separate ordinal traversal and
conditional-result narrowing improve it to **872 / 880 window bytes**.
All **34 relocations resolve**, but **414 bytes / 136 executable word
positions differ**, including four missing executable bytes. The last four
retail bytes are alignment. Rewriting the traversal as an ordinary `for`
loop changes no bytes. Production remains ASM.

`func_0022b120` now has its complete 23-packet reconstruction in
`docs/probe_archive/P022_0022b120_body.c`. It emits **1,860 / 1,872 bytes**
with **67 resolved relocations**: 55 calls, four GP-relative references and
four HI/LO pairs. Ordinary local-declaration ordering removes every saved
register difference, reducing the first candidate's 88 differing bytes in
68 words to **28 bytes in eight words**. Only argument-materialization order
at its two script-constructor calls differs. There is no missing executable
code, overrun or jump table; the last twelve retail bytes are alignment.
The neighboring setup functions' `opt_propagation off` profile produces
identical bytes, so that pragma is not retained. Production remains ASM.

The resource candidate preserves both runtime formation resources, callback
and data pointers, all 64-bit dependencies and action UIDs, both delays,
queue selection and refcount releases. Its resource-start packet deliberately
does not receive an action UID, as in retail. The color source has its actual
four-byte extent. Neither archived candidate is claimed to have passed native
behavior or game execution.

The resource review exposed eleven more real constructors that published
`void` while callers consumed the packet left in `$v0`. Each live definition
now explicitly returns its allocation as `BtlPacket*`. Complete relocation
checks give:

| Constructor | Executable / window bytes | Resolved relocations |
| --- | ---: | ---: |
| `func_001d6240` | 184 / 192 | 9 |
| `func_001d7ab0` | 116 / 128 | 3 |
| `func_001d7b60` | 72 / 80 | 3 |
| `func_001b7e20` | 72 / 80 | 3 |
| `func_001b9360` | 88 / 96 | 3 |
| `func_001b99a0` | 72 / 80 | 3 |
| `func_001ba090` | 72 / 80 | 3 |
| `func_002305c0` | 76 / 80 | 3 |
| `func_00230650` | 64 / 64 | 3 |
| `func_002306d0` | 64 / 64 | 3 |
| `func_00230750` | 64 / 64 | 3 |

Every executable byte matches retail after resolving every relocation, and
all remaining window bytes are zero alignment. Caller declarations and raw
byte-pointer conversions are migrated in `code1_001a`, `code1_001b`,
`code1_001e` and `code1_0022`, including block-local declarations. The
formation constructor keeps its real `(u32, u32, u32, u16, u32)` inputs;
callers do not weaken that contract to manufacture a match. The remaining
`code1_001a` sound-constructor declaration also uses its corrected packet
return.

A throwaway wasm32 consumer fails at all eleven return sites with the old
`void` declarations. With the corrected contracts it compiles with `-Werror`
and executes the eleven verbatim live constructor bodies plus the actual
packet-allocator body. Two calls per constructor produce **22 independent
writable packets**; the consumer checks retained payload boundaries and full
64-bit predecessor/owner UIDs after all allocations. Arena allocation,
memory-fill and diagnostic hooks are fixture-provided; engine callbacks are
not executed. This is target-width C execution, not a PS2 gameplay claim.
The throwaway smoke fixture is removed.

Focused verification caught an 18-byte argument-order regression in
`func_002299b0` during caller migration. Reading its unit handles as the
constructor's actual `u32` inputs restores **644 / 656 bytes, MATCH** without
changing the provider contract. The complete `code1_0022` owner then verifies
at **79 MATCH / 19 ASM**.

The integrated `make build-progress progress lint-errors` gate passes:
**6,138 first-party MATCH / 722 ASM**, **172 C-linked objects / 1,570
functions**, validated progress artifacts, and zero findings across 338
first-party files. Loadable-image SHA1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; retail ELF SHA1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. The API corrections do not claim
additional matching functions.

## Fresh menu reconstruction and task/state argument contracts

`func_002232a0` now has a complete ordinary-C candidate in
`docs/probe_archive/P022_002232a0_body.c`, including all nine verified states,
same-call fallthroughs, the eleven-word message aggregate and two-float
position. Constructor and callback provenance establishes
`0 <= index <= count <= 12`; the candidate does not invent an input for
retail's incoming-`s2` path on corrupted `index > count` work.

The owner-profile probe emits **1,020 / 1,040 bytes**, against **1,036
executable bytes**. All **26 code relocations** and **nine jump-table
relocations** resolve, but **788 overlap bytes / 256 executable word
positions differ**, including **16 missing executable bytes**. All nine
generated table targets differ. Production remains ASM; this is not a match
or game-execution claim. The first input declaration also exposed a genuine
addressing error: standalone halfword declarations selected GP-relative
loads outside the signed-16 range. The candidate now uses the actual
`D_008C0240[]` input block, as `sdkTask.c` does.

`func_00224450` remains ASM for a different reason. Its complete branch map,
provider contracts and exact data are recorded in
`docs/probe_archive/P022_00224450_body.c`. For target mask 2, global flag
`0x400`, effect class 0 and a second battle-id result other than `0x215`,
retail consumes seven unwritten destination-pose floats. The setup helper
writes camera state, not those stack bytes; the actual invoker supplies only
the camera. Battle `0x203` sets flag `0x400`, so the override cannot be assumed
to initialize the pose. No C object or matching score is claimed. A proven
reachability restriction, or permission to repair the retail behavior, is
needed before an honest ordinary-C replacement.

The investigations did repair real live-source contracts:

- `func_0011f580` forwards its child task to `func_00452080` and returns the
  actual `s32` result.
- `func_00353f50` forwards its mode to `func_002bb7c0(s32)`.
- `func_001bc660` forwards its full-width state to `func_0022cdb0(s32)`;
  only table indexing, comparisons and halfword stores narrow the state.
  Keeping a `u16` public input added a pre-call mask and produced 404 bytes
  in the 400-byte window. The real `s32` input restores the retail sequence.
  All live camera callers now use the same state/action declaration.
- Ten `code1_0022` task queries, exit requests and cleanup callbacks now
  accept the task explicitly and use the real `u32 func_00452560(void*)`
  provider. Parent constructors and result-dispatch callers are migrated;
  `func_0021d4a0` also passes its existing task input to its own getter.
  This is a scoped migration, not a claim that every legacy getter
  declaration elsewhere has been converted.

Fully resolved byte comparison, with no relocation masking:

| Function | Object / retail-window bytes | Resolved relocations |
| --- | ---: | ---: |
| `func_0011f580` | 32 / 32 | 1 |
| `func_00353f50` | 88 / 96 | 3 |
| `func_001bc660` | 396 / 400 | 15 |
| `func_002218e0` | 44 / 48 | 1 |
| `func_00221940` | 48 / 48 | 1 |
| `func_002231e0` | 96 / 96 | 2 |
| `func_00223240` | 40 / 48 | 1 |
| `func_002236c0` | 104 / 112 | 4 |
| `func_00223830` | 96 / 96 | 2 |
| `func_00223890` | 40 / 48 | 1 |
| `func_00223ee0` | 88 / 96 | 4 |
| `func_00224040` | 60 / 64 | 2 |
| `func_00224080` | 40 / 48 | 1 |

Every listed comparison has zero differing bytes and only zero retail tail
bytes. These were already classified MATCH; fixing their C contracts does
not increase the matching-function count.

A throwaway wasm32 consumer rejects the pre-fix sources from `7449db63`
against real provider signatures and compiles the corrected sources with
`-Werror`. Runtime execution uses the live camera dispatcher, override
selector, battle-id getter and task-data getter: six camera scenarios cover
the three override tables, disabled and empty-entry fallback, full-width
state input and reentry effects; five task queries and two exit transitions
operate on independent work blocks. External service hooks trap if called;
none executes. Persona release and result-mode wrappers receive compile
and exact-byte proof, not a runtime-service claim. The smoke fixture is
removed after execution.

The final `make build-progress progress lint-errors` gate passes with
**6,138 first-party MATCH / 722 ASM**, **172 C-linked objects / 1,570
functions**, validated progress artifacts and zero findings across 338
first-party files. Both retail hashes remain unchanged.

## Exact camera preparation and descriptor release contracts

`func_002277e0` is now ordinary C in `src/promoted/code1_0022.c`:
**1,620 object bytes / 1,632 retail-window bytes, 50 code relocations,
zero normalized differing bytes and 12 zero tail bytes**. The public
camera pointer is established by the override callback at `0x006352A4`
and its real invoker, `func_001bc660`.

The initial complete reconstruction measured 1,604 bytes / nd1129.
The closing levers were source-level distinctions, not fabricated storage:

- A 32-bit target-loop ordinal with explicit 16-bit wrapping preserves
  the retail induction variable. `opt_common_subs off` retains its
  separate per-use masks.
- A named subordinate predicate preserves the materialized boolean
  before the independent camera-state guard.
- The party search has its own ordinal and a halfword party index.
  Sharing the target-loop variable changed its register lifetime.
- Each of the three pose pairs is exactly two contiguous seven-float
  poses. The direction vector `D_0060A0E0` is exactly twelve bytes.

`func_0019de70` and its live camera callers now agree on
`BtlUnitStateWork *` and the halfword state input. The provider narrows
only at the actual byte store. `func_0046d280` now accepts and forwards
the descriptor pointer to the typed release slot; its live declarations
and callers use the pointer contract rather than an integer or no input.
These provider corrections preserve their existing matching bytes.

A throwaway native consumer compiles the extracted production release
body against libc `free`, with AddressSanitizer enabled. The pre-fix body
is rejected for its conflicting signature and missing release argument.
The corrected body releases one real allocation without poisoning a
second allocation, subsequently releases the second, and accepts NULL.
This is real allocator ownership behavior, not a mock callback echo.

The result-animation investigation instead establishes a concrete blocker
for `func_00222210`: on reachable draw frames 1–6 with flag `0x8` clear,
retail consumes incoming callee-saved `f20` without defining it. Its direct
caller also leaves `f20` undefined before the call. The value reaches the
gold sprite coordinates; neither a substituted phase nor an invented FP
argument is justified. The updated probe archive records the branch,
providers and constructor/update evidence. Production remains ASM.

The preparation comparison also passes with every code relocation fully
resolved and no masked bytes. All seven relocated jump-table entries
equal retail: `00227938`, `00227938`, `0022799C`, `00227A0C`,
`0022799C`, `00227A0C`, `00227BC0`. The corrected state setter measures
36/48 bytes with no relocations; descriptor release measures 40/48 with
two resolved relocations. Both are byte-exact with zero-only tail padding.
Temporary probes and the allocator smoke fixture are removed.

The final `make build-progress progress lint-errors` gate passes:
**6,139 first-party MATCH / 721 ASM**, validated progress artifacts, and
zero findings across 338 first-party files. The C-linked subset remains
**172 objects / 1,570 functions**; the preparation promotion increases
MATCH coverage, not this separately measured linked subset. Loadable
image SHA-1 remains `3d1d3d2b9d6ccb60836db239ab49674223025a78`;
retail ELF SHA-1 remains `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Exact state-0x1A camera initialization

`func_00227e40` now matches in ordinary C on its first full-owner compile:
**1,168/1,168 bytes, 44 code relocations, zero differing bytes and no
tail padding**. No additional compiler pragma is needed. Its callback
record at `0x006352B8` is `D_006350B0 + 0x1A * 0x14`, with words
`{00227E40, 00227770, 1, 1, 0}`. This is the initialization callback;
the per-frame callback is the separate `func_00227770`.

The source preserves the repeated target-mask `0x2` tests through switch
fallthrough, the three distinct 56-byte pose pairs, and unsigned frame
conversion before division by 30. Each pose pair contains two complete
seven-float poses; no compiler frame gap is represented as a source field.
The 44 code relocations also resolve byte-exactly without masking.
All seven relocated table entries equal retail: `002282B4`, `00227ED0`,
`00227ED0`, `00227F18`, `00227EF4`, `00227F18`, `00228064`.

The paired investigation of `func_00225ec0` proves a different blocker:
`002260F8` reads an unwritten point-Y float at `sp+0x134`, then
`0022610C` writes it for the first time. All preceding provider outputs
have disjoint extents. Both direct callers select the side-zero branch
containing that read, so neither a fabricated initial Y nor an invented
argument is justified. The archive now records this concrete state
dependency instead of the old generic COP1 accumulator classification.
An empty eligible group can independently leave further provider outputs
unwritten, but is not needed for the decisive point-Y proof.

The real camera input is now explicit in both existing C callers:

| Caller | Object / retail-window bytes | Resolved relocations |
| --- | ---: | ---: |
| `func_00228d50` | 520 / 528 | 16 |
| `func_00228f60` | 180 / 192 | 8 |

Both remain fully resolved byte-exact with zero-only tail padding.
A throwaway wasm32 compile-contract smoke rejects both pre-fix callers
against the actual one-camera declaration and accepts both corrected
callers. This is compile-contract and retail-byte proof, not an execution
claim for the undefined-stack ASM callee. Production retains that ASM.

The final `make build-progress progress lint-errors` gate passes with
**6,140 first-party MATCH / 720 ASM**, **172 C-linked objects / 1,570
functions**, validated progress artifacts and zero findings across 338
first-party files. Both retail hashes remain unchanged. Temporary
reconstruction probes and the compile-contract fixture are removed.

## Exact enemy camera transition and battle resource selection

Two further helpers now match in ordinary C:

| Function | Object / retail-window bytes | Fully resolved relocations | Zero-only tail |
| --- | ---: | ---: | ---: |
| `func_002258b0` | 800 / 800 | 20 | 0 |
| `func_0022d200` | 824 / 832 | 1 | 8 |

Both have zero differing bytes after resolving every code relocation,
without masking. The camera helper needs `opt_common_subs off` around
its body to preserve the action reload and explicitly wrapping target
ordinal. Its three existing callers remain fully resolved byte-exact:
`func_00225bd0` is 44/48 bytes, `func_00225c00` is 256/256, and
`func_00225d00` is 252/256.

The camera switch selects the actor ID, while its status predicates read
the first target's unit data. The fitting provider receives height scale,
distance scale, distance offset and duration in that order; the first
scalar is not an angular threshold. Each GP-relative constant is a
separately declared float rather than an offset beyond another scalar.
All 19 relocated compiler-generated entries equal retail table
`0x00747820`:

```text
002259E0 002259F4 00225A08 00225A40 00225A54 00225A8C 00225AA0
00225AEC 00225B00 00225B90 00225B38 00225B70 00225B90 00225B90
00225B90 00225AB4 00225B90 00225B90 00225B84
```

The resource selector preserves its ordered outer switch and separate
final default return. Global bit `0x200000`, action bit `1` and actor
genus `1` gate selection. The normal, special and alternate handles come
from global offsets `0xBE0`, `0xBF0` and `0xBF4`; only IDs `0x106` and
`0x10F` with skill `0x172` select the alternate slot. A selected zero
handle remains zero. No compiler pragma is needed.

A throwaway native smoke extracted the actual promoted selector body.
Clang AddressSanitizer and UndefinedBehaviorSanitizer passed **1,507,328
ID/skill selections**: all 65,536 skill values for IDs `0xFF..0x114` and
`0xFFFF`, plus early gates, signed handles and a zero special resource.
This is native selector execution and retail-byte proof, not a claim
that the camera helper or the full game was executed.

The fallback initializer `func_002240e0` remains ASM. Its complete
ordinary-C archive has **872/880 bytes, 344 normalized differing bytes,
34 fully resolved relocations, and 413 differing overlap bytes without
masking**. There are 135 differing executable word positions including
the uncovered instruction. Four executable bytes remain uncovered;
the last four retail-window bytes are alignment zeros. The previous
archive had 414 unmasked differing bytes and 136 differing word positions.
This is a source-shape floor, not the undefined-input blocker found in
the other camera helpers: both seven-float output poses are fully
initialized. The archive records the remaining allocation/narrowing
differences and the failed source-shaping levers.

The final `make build-progress progress lint-errors` gate passes:
**6,142 first-party MATCH / 718 ASM**, **172 C-linked objects / 1,570
functions**, validated progress artifacts and zero findings across 338
first-party files. Loadable image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; retail ELF SHA-1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. The reconstruction probes
and native smoke fixture are removed.

## Exact camera positions and parameterized fitting

Two more camera helpers now match in ordinary C:

| Function | Object / retail-window bytes | Fully resolved code relocations | Zero-only tail |
| --- | ---: | ---: | ---: |
| `func_002249a0` | 1780 / 1792 | 32 | 12 |
| `func_002266b0` | 1420 / 1424 | 21 | 4 |

Both integrated bodies have zero differing code bytes after resolving all
relocations, without masking. The position helper also reproduces all 20
relocated entries of retail table `0x007477D0`:

```text
00224A30 00224A8C 00224AE4 00224B3C 00224BEC 00224C48 00224CA0
00224D54 00224DAC 0022506C 00224E0C 0022506C 0022506C 0022506C
0022506C 00224CFC 00224B94 00224B94 00224E64 00224EBC
```

The position helper needs no pragma. Both sphere-center providers write
exactly XYZ, and every actor/target branch returns a defined framing scale.
The fitting helper needs `opt_scalarize off`: otherwise the compiler
removes the horizontal perpendicular-vector stores and changes the frame.
The source retains real two-component horizontal vectors, staged radius
scaling, X-before-Y dot-product operands, and a scoped table of two-halfword
skill records. Both output poses contain exactly seven initialized floats.
No extra frame fields, invented inputs, inline COP1, or pinned registers
are used. This is compiler-output and relocation proof, not a claim that
the camera code or full game was executed.

The initial `func_002250a0` reconstruction reached **19 normalized differing
bytes**, with **1688/1696 bytes and 36 fully resolved code relocations**.
Seventeen differences were stack offsets around the temporary quaternion
and horizontal vectors; two were `addiu` versus `daddiu` for transition
flags. This floor is now closed by the real geometry workspace and
halfword flag contract described below in “Exact opposing camera and
persona result updater”; its archive now contains the exact source.

The final `make build-progress progress lint-errors` gate passes with
**6,144 first-party MATCH / 716 ASM**, validated progress artifacts and
zero findings across 338 first-party files. The C-linked boundary remains
**172 objects / 1,570 functions**; these two promotions do not make their
mixed owner eligible for whole-object C linking. Loadable image SHA-1 is
still `3d1d3d2b9d6ccb60836db239ab49674223025a78`, and retail ELF SHA-1 is
still `4eeec0360cf2715535d9f7e52eb69d786fb0158c`. The three reconstruction
directories and their temporary compiler experiments are removed.

## Exact group and selection camera dispatchers

`func_00226c40` and `func_00227230` are now ordinary C in
`src/promoted/code1_0022.c`. Both initial owner-context candidates matched;
the actual integrated owner was then compiled and checked with every code
and switch-table relocation resolved against the retail ELF.

| Function | Object / window | Resolved code relocations | Normalized differences | Resolved differing bytes | Zero tail bytes |
| --- | ---: | ---: | ---: | ---: | ---: |
| `func_00226c40` | 1516 / 1520 | 48 | 0 | 0 | 4 |
| `func_00227230` | 1336 / 1344 | 48 | 0 | 0 | 8 |

All seven `R_MIPS_32` entries in each switch table also match:

```text
00747870: 00226D98 00226D98 00226D98 00226E04 00226D98 00226E04 00226FB8
00747890: 0022774C 002272C0 002272E8 002273B0 00227324 002273B0 002274FC
```

The source reuses the exact neighboring dispatchers' real 56-byte
`CameraPosePair`: two 12-byte positions and two 16-byte quaternions. Every
seven-float pose passed to the consumer has its complete position and
quaternion produced on that branch. The old archives' standalone scalar
quaternion outputs were undersized objects, not retail undefined state.
Widening record frames to `u32` before conversion preserves the compiler's
ordinary unsigned-to-float expansion without inventing a negative input.

The group dispatcher uses scoped `opt_common_subs off`, independent
wrapping target/party ordinals and a complete `RwRGBA` passed by value.
States 0/1/2/4 call the generic camera before their count/genus/self guards;
they do not inherit the neighboring dispatcher's selected-pose fallthrough.
The selection dispatcher needs no local pragma and preserves the distinct
case-1, case-2, case-4 and case-3/5 tests and fallthrough paths.
`V022_00226c40_body.c` and `V022_00227230_body.c` now contain the exact
sources and complete provider/caller evidence, replacing the recorded
989- and 839-difference candidates.

Keep the canonical `// FUN_...` marker separate from measured block
comments: block-comment-only headings were omitted by the report scanner.
Restoring the canonical markers and rerunning
`make build-progress progress lint-errors` gives **6,146 first-party MATCH /
714 ASM**, with all **6,860 first-party / 12,720 total** functions scanned,
validated progress artifacts and zero findings across 338 first-party files.
The mixed owner remains outside whole-object C linking: **172 objects /
1,570 functions** are C-linked. Loadable image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; retail ELF SHA-1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. These are compiled-output and
build checks, not game or camera execution.
The two reconstruction directories and their temporary compiler objects
have been removed after archiving the source and contract evidence.

## Formation packet creator return contract

`func_001d3700` in `src/Battle/btlFormation.c` now explicitly returns the
`BtlPacket *` it allocates. Retail retains the allocator's result in `v0`
while writing the callback and the two halfword work fields; callers then
write packet conditions and timing fields through that result. A `void`
source declaration did not express that contract.

The provider remains exact at **88 / 96 bytes**, with all **three code
relocations resolved**, zero differing bytes and eight zero tail bytes.
Declarations and pointer-view casts were migrated in
`src/promoted/code1_001a.c`, `code1_001b.c` and `code1_001e.c`.
Scoped verification covers **349 functions: 296 MATCH / 53 ASM**; every
affected row retains its prior status, object size and relocation count.

A temporary native smoke compiled the real creator body and the real
`func_001eb0b0` consumer body, replacing only allocation and publication.
It confirmed that the consumer publishes the returned packet and writes
its expected timing field. This is an isolated C contract check, not game
execution.

## Exact alternate camera and action sequencing

`func_00229020` and `func_00229da0` are now ordinary C in
`src/promoted/code1_0022.c`. The already matching `func_002299b0` now uses
its real eight-word payload rather than a data-plus-padding holder.
All three were checked again from the actual integrated owner object:

| Function | Object / window | Resolved code relocations | Resolved differing bytes | Zero tail bytes |
| --- | ---: | ---: | ---: | ---: |
| `func_00229020` | 2444 / 2448 | 56 | 0 | 4 |
| `func_002299b0` | 644 / 656 | 29 | 0 | 12 |
| `func_00229da0` | 2312 / 2320 | 75 | 0 | 8 |

The sequence builder's nine `R_MIPS_32` switch entries are also exact:

```text
007478F0: 0022A3FC 0022A3FC 0022A374 0022A38C 0022A3A4
          0022A3FC 0022A3BC 0022A3EC 0022A3D4
```

The alternate camera's old, unprobed accumulator-chain classification was
not a compiler floor. Ordinary expressions emit the retail COP1 chains.
Its geometry workspace contains four real two-float vectors and a complete
56-byte pose pair; there are no padding members. Scoped `opt_scalarize off`
retains their stores. Shared switch defaults, case-label order, explicit
ordinal/address views, mode declaration order and staged floating-point
expressions close the remaining instruction differences.

The camera copy provider writes all seven incoming-pose floats, including
the first quaternion. Quaternion producers and vector providers write
their complete consumed extents. The live-action scheduling chain through
`func_001a4c80` supplies states `0x16` and `0x17`; all three callback tables
contain this initializer at those states. The retail null-action test
does **not** make the callback null-safe: its later unconditional
`action+0x30` load remains. No invented early return was added.

The sequence builder keeps separate packet roles across its phases and
an iteration-local target pointer. Both 32-byte configuration objects
are fully initialized; all action and published-packet identities remain
64-bit. The two target traversals, optional status sequence, six switch
arms, roster walk and publication-dependent identity loads are retained.
Its formation cleanup consumes the corrected `func_001d3700` return.

The followup initializer is registered by `func_0022d600`, not
`func_0022dc70`. Its `u32 payload[8]` is completely initialized by
`func_001f0a10` and copied by `func_001f36e0` before local lifetime ends.
Its existing scoped `opt_propagation off` remains necessary.
The sound provider still requests `strlen+8` work bytes but copies
`strlen+1` bytes at work offset eight. For the retail `EM10F_END.ADX`,
that is a 21-byte request and a 22-byte written extent. Active allocator
rounding has not been established; this is not an unconditional
whole-provider memory-safety claim, and target-local padding is not a fix.

`P022_00229020_body.c`, `P022_002299b0_body.c` and `P022_00229da0_body.c`
archive the exact sources and complete caller/provider evidence. The last
replaces the 2308-byte sequence candidate that omitted four executable
bytes and differed in 1481 resolved bytes.

The full `make build-progress progress lint-errors` gate passes:
**6,148 first-party MATCH / 712 ASM**, **7,778 total MATCH / 4,942 ASM**,
validated progress artifacts, and zero findings across 338 first-party
files. Whole-object C linking remains **172 objects / 1,570 functions**.
Loadable image SHA-1 remains
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; retail ELF SHA-1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
These are compiler, relocation and build checks, not game execution.

## Scripted initializer saved-register blocker

`func_0022a730` remains ASM. A fresh complete audit confirms the existing
`P022_0022a730_body.c` blocker: `0x0022A80C` consumes incoming `s1` unless
the first traversal writes it at `0x0022A7F8`. That write requires status
bit `0x100` to be present; the real registration path in `func_0022dc70`
selects the opposite predicate.

A single active target with unit flag eight and status `0x100` clear can
reach registration without establishing the required write. The callback
dispatcher supplies only the registered action in `a0`, and
`func_0022bd00` supplies no selected-target or status invariant.
Initializing the pointer, deriving it from another input, or reading a
pinned saved register would change the contract or introduce undefined C.
No such candidate was compiled or installed. The center provider's
no-output path remains a secondary, unresolved path-invariant requirement.

The four temporary reconstruction directories and the formation-return
smoke fixtures were removed after their source and evidence were archived.

## Exact opposing camera and persona result updater

Two more ASM bodies in `src/promoted/code1_0022.c` are now ordinary C:

| Function | Object / window | Resolved code relocations | Resolved differing bytes | Zero tail bytes |
| --- | ---: | ---: | ---: | ---: |
| `func_002250a0` | 1688 / 1696 | 36 | 0 | 8 |
| `func_002232a0` | 1036 / 1040 | 26 | 0 | 4 |

The opposing camera uses four real two-float vectors followed by its yaw
quaternion in one geometry workspace. Scoped `opt_scalarize off` preserves
the stores; no padding is introduced. Both seven-float poses are fully
produced before use. The quaternion comparison receives real quaternion
objects through the provider's existing `void *` interface.

`func_001bcd40` masks its incoming transition flags to 16 bits. All six
active owner declarations now use `u16` for that argument while retaining
their existing float/GP order. The local selectors in `func_001bdd80` and
`func_001bdeb0` also needed `u16`; word-sized selectors introduced extra
truncation instructions. Verification of those six owners gives
**406 MATCH / 81 ASM**, with no mismatches.

The persona updater preserves all nine states and the task dispatcher's
`0`/`-1` return contract. Its named reward preserves experience-load order,
and prefix halfword increments preserve wrapping timer comparisons.
Scoped `opt_propagation off` retains the result-area base and later field
reloads. All nine switch entries resolve exactly:

```text
00747750: 00223314 002233A4 00223558 00223560 0022358C
          002235FC 0022362C 00223644 00223688
```

The constructor and transitions establish `0 <= index <= count <= 12`.
On every constructor-reachable path that consumes the persona local, a
loop iteration has produced it. The existing occupied-prefix persona
collection precondition is retained; no corruption fallback or invented
initialization is added. The position output is two floats, and the
message list is exactly eleven initialized words.

`func_0011f410` now takes actual record and message-array pointers in both
its active definition and the new caller. Both affected owners verify at
**180 MATCH / 20 ASM**, with no mismatches. A freestanding 32-bit native
smoke ran the real constructor body: the returned task exposes the record
pointer and an independent copy of all eleven messages even after the
caller's array is overwritten. Only allocation/publication and platform
support were substituted; this is not game execution.

`P022_002250a0_body.c` and `P022_002232a0_body.c` archive the exact sources
and their evidence.

### Result renderer: one opcode byte remains

`func_00222d20` remains ASM. Its complete ordinary-C candidate now covers
**896/896 bytes**, with all **17 code relocations resolved** and just one
differing byte:

```text
00222E5C: addiu s1, zero, 255   | retail: daddiu s1, zero, 255
```

Everything else, including the return delay slot, matches. Direct
float-to-byte casts, fused frame advancement, real two-float arrays,
origin declaration order, staged opacity multiplication and the
float-first quad-renderer declaration close the earlier differences.
The correct overlay scalar is `fGpffff838c` (`0.8f`), and overlay alpha
never overwrites the base alpha passed to descriptor rendering.

Literal, integer-width, narrow-provider and propagation variants did not
close the final byte. The older b119 compiler gives 920 bytes and 629
normalized differences. `P022_00222d20_body.c` records the full candidate,
actual callback ABI, provider extents and remaining integration work.
This measured floor is not a proof that exact C is impossible.
The separate `func_00222210` incoming-`f20` blocker remains unchanged.

The full `make build-progress progress lint-errors` gate passes:
**6,150 first-party MATCH / 710 ASM**, **7,780 total MATCH / 4,940 ASM**,
validated progress artifacts, and zero findings across 338 first-party
files. Whole-object C linking remains **172 objects / 1,570 functions**.
Loadable image SHA-1 is unchanged at
`3d1d3d2b9d6ccb60836db239ab49674223025a78`; retail ELF SHA-1 remains
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
The three reconstruction directories, compiler experiments and native
smoke fixtures were removed after archiving the source and evidence.

## Exact action preparation and camera roster blocker

`func_0022b120` is complete ordinary C: **1860/1872 bytes**, all **67 code
relocations resolved**, no differing bytes, and twelve zero alignment
bytes after the return delay slot. The real script-name pointer closes
argument materialization; declaring `wait1`, `wait0`, then `anchor` closes
the remaining saved-register allocation differences without pragmas.

All 23 packet publications retain their full-width action and predecessor
identities, including reloads after synchronous publication callbacks.
The rotate packet copies exactly one initialized 12-byte `RwV3d`.
Both formation objects are populated before traversal publication and
released in retail order; packet-held references retain their lifetime.
The zero-work `func_002306d0` packet deliberately keeps its constructor's
zero action identity. No synthetic input, local padding or hidden saved
register is used.

`func_001ebb00` now takes the actual `u8 *` script name in its active
definition and both new callsites. The existing word-address resource
resolver boundary is explicit. Its **252/256-byte** body remains MATCH;
both affected owners verify at **204 MATCH / 15 ASM**, with no mismatches.
The initializer/updater declarations also carry their real pointer and
return types. Registration now uses the established three-word address
API, not false no-argument callback types; that owner still verifies
at **112 MATCH / 9 ASM** after this repair.
The actual initializer registration and dispatcher supply only the action
pointer and consume no result. This is compiler/retail-byte verification,
not game execution. `P022_0022b120_body.c` archives the exact source and
complete provider, publication and lifetime contracts.

### Camera roster initializer: an admitted uninitialized-pose path

`func_00224450` remains ASM. Its complete **1312-byte** audit distinguishes
two superficially similar fallbacks:

- Target mask `1`, classification `0`: branch at `0022482C` goes directly
  to the epilogue at `0022494C`; no destination pose is consumed.
- Target mask `2`, battle flag `0x400`, classification `0`: branch at
  `0022466C` goes to `00224888`, then consumes the uninitialized second
  pose unless encounter `0x215` overwrites it.

`func_001bd560` initializes only `[sp+0x60, sp+0x7C)`.
`func_001c8cf0` writes only `camera+0x100..0x107`. Neither supplies the
28 bytes at `[sp+0x7C, sp+0x98)` later consumed by `func_001bab00` or
`func_001bac20`. All three callback tables and the real packet dispatcher
were audited; none supplies another pose or excludes this combination.
Encounter `0x203` setup actually enables both the override table and
flag `0x400`, without the `0x215` repair.

This proves a dispatcher-admitted path, not a captured gameplay trace or
an observed shipped skill record. Recovery still needs an independently
proven runtime-data invariant excluding it; zeroing the pose, enlarging a
provider output or inventing an early return would change retail behavior.
`P022_00224450_body.c` records the complete branch, caller and extent audit,
without a fake candidate definition.

The `func_002240e0` current-contract recheck also remains ASM: **872/880
bytes / 344 normalized differences**, including four uncovered executable
bytes. Word-sized selectors omit eight executable bytes; propagation and
selection-temporary variants do not close the floor. The complete preferred
source and fresh measurements remain in `P022_002240e0_body.c`.

The final `make build-progress progress lint-errors` gate passes:
**6,151 first-party MATCH / 709 ASM**, **7,781 total MATCH / 4,939 ASM**,
validated progress artifacts, and zero findings across 338 first-party
files. C linking remains **172 objects / 1,570 functions**, with unchanged
loadable and retail ELF hashes. Both completed recovery directories and
their compiler probes were removed after archiving the evidence.

## Exact collision segment and actor skill selectors

`func_001ece50` now lives beside its geometry providers in
`src/btlTarget/btlTarget.c`; the promoted-owner ASM marker is removed.
It matches **520/528 bytes**, with six fully resolved relocations and only
eight retail alignment bytes outside the compiler symbol. The existing
orientation leaf is private: all twelve retail calls belong to this unit,
and exposing it forces unnecessary caller saves. Its signed `-1/0/+1`
contract remains intact. `func_001ec8c0` now accepts the actual two-float
coordinate pairs rather than claiming three-component vectors; it still
matches all 336 bytes. `P022_001ece50_body.c` preserves the complete source
and caller/provider audit.

`func_001ebc00` matches **1468/1472 bytes**, with four fully resolved call
relocations and one zero alignment word. All 97 skill IDs remain explicit.
A real `u16` array view, word-sized loaded skill, declaration order and
scoped `opt_common_subs off` preserve the retail narrowing operations.
The fallback provider `func_0023dfe0` now consistently takes its real unit
pointer and returns `s32`; its zero-return body is unchanged.

A freestanding 32-bit native smoke exercised the selector with its real
skill getter, eligibility predicate, fallback and unsigned-modulo providers.
All 65,536 skill IDs agreed with the independent retail case oracle.
Eight-slot selection, duplicate entries, rejection and untouched command
bytes also passed. Unexercised provider branches were fail-fast fixture
boundaries, not successful substitutes. This is not game execution.
`P022_001ebc00_body.c` records the source, contracts and smoke evidence.

The full `make build-progress progress lint-errors` gate passes:
**6,153 first-party MATCH / 707 ASM**, **7,783 total MATCH / 4,937 ASM**,
validated progress artifacts, and zero findings across 338 first-party
files. C linking remains **172 objects / 1,570 functions**; both loadable
and retail ELF hashes are unchanged.

## Exact roster assistance and geometry register floor

`func_001ef9c0` now matches **904/912 bytes**, including all fifteen
relocations. Its rank is an ordinary scalar; the three four-element arrays
are real initialized-prefix pointer storage, not artificial spill padding.
Preferred-or-random conditional expressions reproduce the retail branches,
and declaring the roster node before the counts closes the register cycle.
The owner now uses the real status, rank and actor-community provider
contracts, without redundant block-scope status declarations.

The freestanding 32-bit native smoke passed **46,080 combinations** of
rank boundaries, candidate statuses, preferred nodes and unsigned random
words. It also passed all six acting-node rejection gates, candidate
flags/genus filtering and preferred protagonist selection. The real current
community/status/modulo providers were exercised; the deterministic
`RpRandom` boundary verified that preferred selection leaves RNG state
unchanged. All non-output action bytes remained intact. No game execution
is claimed. Complete source and contracts are in `P022_001ef9c0_body.c`.

The remaining geometry caller, `func_001eca10`, stays ASM. Its complete
candidate reaches **964/976 bytes / 23 normalized differences**, all in
register allocation, with eleven resolved relocations and no missing
executable instructions. Explicit coordinate-pointer lifetimes and scalar
snapshots recover the frame and floating operand order.

Source order is significant: the private orientation definition belongs
after this caller and before the exact `func_001ece50`. Moving it before
the candidate exposes different clobber knowledge and produces only 920
bytes. `P022_001eca10_body.c` records this measured correction to the initial
integration advice, the complete preferred source, and the upstream
adjacency-capacity caveat. No route-wide memory-safety claim is made.
The fresh camera CSE recheck likewise leaves the retained `func_002240e0`
floor at **872/880 bytes / 344 differences**; its archive records the
extra-load and narrowing results.

The full `make build-progress progress lint-errors` gate passes:
**6,154 first-party MATCH / 706 ASM**, **7,784 total MATCH / 4,936 ASM**,
validated progress artifacts, and zero findings across 338 first-party
files. C linking remains **172 objects / 1,570 functions**, with unchanged
loadable and retail ELF hashes.

## Exact eight-point route interpolation

`func_001ef110` now matches **904/912 bytes**, with all eighteen
relocations resolved. Ordinary 16-byte quaternions, a 40-byte interpolation
cache and three-float vectors reproduce the retail frame. Declaration order
closes the stack and long-lived float-register differences.

The last point must reload both endpoint coordinates after the seven-sample
loop and before either output store. An endpoint at `route+0x34` overlaps
the final output: interleaved load/store assignments destroy its second
coordinate. Staging both loads preserves this behavior; scoped
`opt_propagation off` also preserves their exact retail order. The coefficient
at `0x00761430` is now mapped under its actual address.

The native Clang ASan/UBSan smoke passed **3,073 scenarios**: 2,857 nonlinear
and 216 linear cache cases, coincident points, seven samples at
`0,.125,...,.75` plus the explicit endpoint, unchanged cursor/guard bytes,
and overlapping endpoint storage. The unstaged variant fails the overlap
assertion. Four external SDK boundaries use native mathematical models;
this does **not** claim PS2 SDK or game execution.

The complete source and provider extents are archived in
`P022_001ef110_body.c`. Its caller's empty-centroid caveat remains explicit:
without an earlier scratch write, that upstream path does not establish
initialized center inputs. No concrete production chain selecting that
empty arc path was found, and no target-local guard or default was added.

`func_001e9950` remains ASM. Its preferred fitting probe reaches
**1,464/1,488 bytes / 904 normalized differences**, with all 27 calls
resolved but sixteen uncovered executable bytes. Other profiles overrun
the window. `P022_001e9950_body.c` preserves the complete candidate, provider
declaration requirements, projection/lifetime differences and measured
alternatives. This is an ongoing source-shaping result, not a
compiler-impossibility claim.

The full `make build-progress progress lint` gate passes:
**6,155 first-party MATCH / 705 ASM**, **7,785 total MATCH / 4,935 ASM**,
validated progress artifacts, and zero lint errors. Full warning mode
reports 192 review warnings across 338 first-party files. C linking remains
**172 objects / 1,570 functions**, with unchanged loadable and retail ELF
hashes.
