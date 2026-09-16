# First-party matching handoff

## Purpose

This is the operational handoff for continuing the first-party Persona 4 matching campaign. It complements `docs/matching.md`, which is the reusable MWCCPS2 source-shaping catalogue, and `docs/compiler-floors.md`, which records measured compiler limits.

The objective is a clean C replacement for each first-party `INCLUDE_ASM` function. A replacement is accepted only when its current source compiles to the retail executable instructions, every relocation resolves to the retail symbol and addend, any omitted window suffix consists only of retail zero alignment, and the C preserves the observed behavior and ABI.

## Current checkpoint

- Latest published recovery: `func_0020b6d0`, commit `de42a42d`.
- Measured target: 812 emitted bytes in an 816-byte retail window.
- Relocations: 14, all resolved to the retail targets.
- Residual window suffix: one four-byte retail zero word after the candidate body.
- Owner isolation: all other 145 functions in `src/promoted/code1_0020.c` retained identical bytes and relocation metadata.
- Caller isolation: changing `func_0020b6d0`'s fourth parameter declaration from `s32` to the retail `s16` contract changed no bytes or relocations in the 71-function `src/promoted/code1_001a.c` owner.
- Estimated remaining first-party fallbacks after that recovery: 548.

The initial direct proof ran while `tools/mwccgap/mwccgap.py` was absent from
the user working tree, so it used the already-imported `gap.process_c_file`
path plus direct ELF and relocation comparison. After the tool was restored,
this command passed:

```text
python tools/verify.py src/promoted/code1_0020.c src/promoted/code1_001a.c --show-mismatches
```

It scanned 217 first-party functions and reported 186 `MATCH`, 31 healthy
`ASM`, and no failures.

## Non-negotiable acceptance rules

1. Read the complete retail assembly, complete Ghidra body, complete IDA body, current owner section, and existing probe archive before changing source.
2. Treat assembly as authoritative for ABI, loads, stores, branches, delay slots, and relocation targets. Ghidra and IDA are independent hypotheses.
3. Use the configured compiler and flags for the owner. First-party owners normally use MWCCPS2 3.0.1 build 210 at `-O2`, but repository configuration wins.
4. Compile the actual current owner, not a stale private copy, before integration.
5. Resolve relocations. A relocation-masked byte match can still reference the wrong function, global, GP displacement, or local literal.
6. Compare every other function and every local table in the owner before and after the splice. A target match does not license translation-unit regressions.
7. Reject exact candidates that depend on undefined behavior, uninitialized values, incompatible declarations, omitted arguments, fake returns, volatile register forcing, dummy locals, synthetic padding, inline assembly, or compiler/VU intrinsics.
8. Update every real caller and declaration when the recovered ABI changes. Verify each affected owner independently.
9. Missing bytes are acceptable only when the corresponding retail suffix is all zero alignment after the candidate's final executable instruction.
10. Keep a non-exact but semantically faithful floor in `docs/probe_archive/`; keep production on `INCLUDE_ASM`.

## Direct recovery workflow

### 1. Build a target inventory

Start from current first-party `INCLUDE_ASM` rows, excluding SDK/vendor ranges. Record:

- function and address;
- retail window size;
- owner source;
- retail assembly path;
- existing private proof and archive paths;
- best measured emitted size, relocation count, and differing-word offsets;
- known semantic or compiler blocker.

Rank by actionable residual, not just function size. Highest-value targets are ordinary C with a localized register, scheduling, branch-layout, or type residual. Hardware wrappers and already-exhausted compiler floors come last.

Private proof mining must include more than `*.parent_resolved.json`. The successful `func_0020b6d0` candidate was found in a standalone `*.measurement.json` carrying `candidate.normalized_diff_bytes = 0` and `candidate.target_prefix_byte_exact = true`; it was absent from the earlier parent-proof ranking.

Useful proof fields:

- `target` or `symbol`;
- `candidate.owner_source_path` / `candidate_source`;
- emitted and retail sizes;
- normalized differing bytes or words;
- relocation records and unresolved count;
- target prefix exactness;
- non-target owner differences;
- semantic hazards and integration readiness.

Never trust a stored zero blindly. Recompile its named source with the current compiler and include tree. Stale proof artifacts have occurred.

### 2. Read all authoritative evidence

For a target `func_XXXXXXXX`, read:

- `asm/nonmatchings/<owner>/func_XXXXXXXX.s` in full;
- `docs/ghidra_headstart/...` exact function range;
- `docs/ida_headstart/...` exact function range;
- `src/generated/...` candidate when useful;
- `docs/probe_archive/*_XXXXXXXX_body.c` in full;
- the current authoritative owner around the marker;
- any private handoff, measurement, and candidate body.

Before editing an exported symbol, run LSP references. If no C language server is available, use graph search plus literal source search and check indexing coverage for every operated-on path. Read partial or stale-index paths directly.

### 3. Capture an actual-current baseline

Compile a copy of the current owner before editing. Preserve:

- object hash;
- function map;
- per-function bytes;
- per-function relocation metadata;
- local table bytes and relocations;
- target bytes and target relocation list.

This separates target work from unrelated working-tree changes and makes owner-isolation proof possible after the splice.

Normal compiler invocation conceptually matches:

```python
gap.process_c_file(
    source_path,
    object_path,
    c_flags=["-O2", "-I" + str(repo / "include")],
    mwcc_path="/home/raikaru/opt/mwcc-wrapper.sh",
    asm_dir_prefix=repo,
    macro_inc_path=repo / "asm/macro.inc",
    as_march="r5900",
    as_mabi="eabi",
)
```

The workstation path is local configuration, not a repository contract. Use the configured wrapper on another machine.

### 4. Reproduce the best candidate before modifying it

Compile the archived/private source exactly as stored. Compare its target against the retail window with relocation fields masked, then resolve those relocations and compare the resulting bytes.

Record:

```text
candidate emitted bytes / retail window bytes
candidate relocation count
unresolved relocation count
resolved byte equality over emitted prefix
retail suffix bytes after emitted prefix
actual differing word offsets
```

If recompilation disagrees with the stored proof, the proof is stale or its source/object pair is mismatched. Stop using that artifact as evidence.

### 5. Apply the semantic gate before tuning

Read every declaration and provider implicated by unusual argument shaping. Confirm the actual provider definition and all callers. Common false matches:

- old-style `func()` declarations that preserve accidental incoming registers;
- a local prototype with a wider or narrower parameter than the provider;
- an omitted child/context argument;
- an uninitialized local whose stale register happens to reproduce retail;
- an out-of-range C shift that relies on MIPS's masked hardware shift count;
- partially initialized stack data passed to a consumer that reads the full buffer;
- callback addresses staged through a type that loses or changes relocations.

An unsafe exact candidate is a diagnosis, not a recovery. Replace the unsafe construct with the truthful contract and measure the new residual.

### 6. Diagnose the truthful residual instruction by instruction

Disassemble only the differing offsets first. Classify the residual:

- instruction deficit/surplus;
- branch target or branch polarity;
- register-color permutation;
- FPR-color permutation;
- instruction scheduling only;
- operand orientation;
- stack slot/frame mismatch;
- relocation target/addend mismatch;
- zero alignment tail only.

Look for a single consistent mapping. A repeated `$s2`/`$s3` exchange across a region is one allocation problem, not thirteen independent mismatches. A constant/load order swap with an identical instruction multiset is a scheduler problem, not missing logic.

### 7. Run a bounded source-shape experiment

Change one evidence-backed lever at a time. Preserve every variant and measurement privately. Good bounded families include:

- declaration order permutations for the two to four locals participating in a register cycle;
- truthful signed/unsigned and narrow/wide types supported by the provider;
- equivalent `if`, `switch`, or explicit-goto layouts matching retail CFG;
- expression evaluation order where C semantics permit it;
- aggregate versus scalar snapshots for call-crossing values;
- scoped, compiler-recognized optimization pragmas;
- loop initialization and condition placement.

Do not sweep meaningless syntax. Stop a lever family once all variants are neutral or regress. Record the negative result so it is not repeated.

For declaration-order searches, start with the smallest move suggested by the register map. Exhaustive permutation is justified only for a small set of interacting declarations and must be measured automatically. Keep the simplest exact order, not an arbitrary exact permutation.

### 7a. Measured MWCC 3.0.1 b210 `-O2` codegen levers

Each rule below was isolated with a standalone micro-experiment and then
confirmed on a real recovery (`func_001f4e50`, `src/promoted/code1_001f.c`,
425 -> 61 differing words in one session).

- **Callee-saved registers are assigned in reverse declaration order.** The
  last-declared register-resident local takes `$s0`, the next `$s1`, and a
  copied parameter lands after every local. Two functions differing only in
  the order of three declarations produce mirrored `$s0..$s3` maps
  (micro-test `r1`/`r2`). Read the retail map, then order the declarations to
  match; do not chase the permutation with unrelated levers.
- **Call order decides the save set.** A callee result consumed immediately in
  `$v0` costs nothing; hoisting it above an earlier call forces a
  callee-saved register and grows the frame. Reproduce retail's call order
  before tuning anything else.
- **Duplicated arm tails are source-level.** An `if/else if` chain whose arms
  each repeat the same stores compiles to per-arm tails; folding those stores
  into one shared epilogue after the chain removes four instructions per arm.
- **Pointer temp versus direct index selects the addressing form.** Taking an
  element pointer (`p = &tbl[i]; p[0] = ..; p[1] = ..`) emits
  `addiu base,idx,OFF` plus zero/two displacements; a direct indexed store
  (`tbl[i*2] = ..`) folds the frame offset into the store (`sh v0,0x50(v1)`).
  Both forms appear in the same retail function; pick per access site.
- **Globals that are stored through need a materialized pointer.** Retail's
  `addiu v1,v0,OFF` + `sw x,0(v1)` alongside `lw v0,OFF(v0)` comes from a
  pointer local used only by the store, with the load left as a plain
  expression.
- **A redundant `bltz` bound check before a jump table comes from source.**
  `if (v >= 0) { switch (v) { ... } }` emits `bltz` then `sltiu at,v,N`; no
  operand type (`s16`, `s32`, `s64`, `u16`) or opt level produces it on its
  own (micro-tests `f_guard` versus `f_short_local`/`f_int_param`/`f_s64`).

Known wall, recorded so it is not re-explored blindly: MWCC always folds a
second access to an adjacent element onto the first materialized pointer
(`lh v0,2(a0)`), whereas retail occasionally rematerializes it
(`addiu v0,a0,0x52; lh v0,0(v0)`). Fourteen addressing shapes, both compiler
builds, every opt level and the `opt_*` pragmas fold.

### 7b. Census a codegen signature before inventing a source shape

When a residual is a codegen shape rather than a semantic difference, ask
whether any already-matched function reproduces it. Decode the retail bytes of
every `MATCH` row in a verifier JSON and pattern-match the instruction
signature directly (for example: a base register defined from `sp`, then two
`addiu` with distinct constants each feeding a zero-displacement memory op).
A hit gives a proven source shape to copy - `func_0027d800`
(`src/promoted/itfMsgProcedure_Window.c`) and `func_00154be0`
(`src/promoted/k_fldEnvironment.c`) supplied the pointer-temp form this way.
Zero hits across 7942 matched functions is itself a result: the shape is not
reachable from the source forms this tree has proven, so bank the floor
instead of continuing to guess.

### 7c. Callee parameter width controls call-site promotion masks

A `u16`/`u8` local passed to a parameter declared wider forces a promotion
`andi …,0xffff` at the call site, and MWCC will CSE that promoted copy into a
callee-saved register, changing both the register map and the surrounding
schedule. Retail passing the raw register means the retail prototype is the
narrow type. Two conversions came from this single change:

- `func_001de000` (`src/Battle/btlAICommand.c`) reached MATCH by declaring
  `func_001dd1c0`'s count parameter `u16`; the tally then passes raw
  (`$a3 = $s2`) and the guard and table index keep their own `andi` temps.
  The callee's own body is unaffected.
- `func_0012d630` (`src/promoted/code1_0012.c`) went 28 -> 16 differing words
  by declaring `func_0034f320`'s tenth parameter `u16`, which removed the
  promotion that had reordered the entire argument block.

Check the callee's real definition before widening or narrowing: the same
function's argument *order* can be wrong too. `func_00364320` is
`(Vec2f, f32 z, s32 colour, s32 num)`; the `0012d630` draft passed colour and
num swapped, which the register diff exposed as `lbu $a1` versus `lbu $a2`.

### 7d. Measuring a guarded floor

A floor behind `#ifdef NON_MATCHING`/`#ifdef SKIP_ASM` compiles its
`INCLUDE_ASM` arm, so a naive measurement scores the assembly, not the C
body. Both tools now handle this: `verify.py` classifies any conditional
guard carrying the function's `INCLUDE_ASM` as `ASM` (it previously only
recognised `NON_MATCHING`, which is why twenty `SKIP_ASM` floors reported
`STALE_NONMATCHING` with a phantom "already matches"), and
`probe_variants.py` replaces the whole guard with the candidate, so a
candidate score is the real residual and the tracked file is never written.
Extract the body between `#ifdef` and `#else`, pass it as a candidate, and
read the score. Diff rows for a guarded floor come the same way — splice the
candidate into `probe_variants.scratch_source` and call `run_fndiff`.
`fndiff` also no longer counts retail's zero alignment tail, which used to
report a residual on functions `verify.py` calls MATCH.

Comments carrying old `nd` numbers are not trustworthy: a measured sweep of
every first-party floor found notes off by as much as 744 words (one claimed
`nd 0`). Re-measure before planning work, and measure the archive too — a
`docs/probe_archive/` body can be far better than the floor installed beside
it (`R1EE_001d8cb0_body.c` scored 4 against the source floor's 45, and it was
one operand swap from matching).

### 7e. Align the instruction streams, do not read positional diffs

`fndiff` compares word N with word N. A candidate that is one instruction
short therefore reports a few hundred differing words, and the single missing
instruction is invisible. `tools/fnalign.py` aligns the two streams and prints
the edit script instead:

    python tools/fnalign.py src/foo.c func_00123456 --candidate /tmp/body.c

It normalises branch targets to instruction-relative form, drops relocated
jump targets, and reports replacements that differ only in a relocated
immediate separately, so the edit count is the real work remaining. This is
what turned `func_001dd570` from a "159-word floor" into four concrete source
shapes, and it separates the two populations that matter: floors whose streams
already match retail instruction for instruction, where only register names
differ, from floors with genuine inserts, deletes or reordered instructions.
Measured over the 84 guarded first-party floors, exactly one — `func_001dd920`
— is in the first class; the other 83 carry real structural edits, so the
aligner points at actual work in almost every case. The edit distance is also
a much better queue order than `nd`: `func_0020bff0` read as 385 differing
words and was four instructions away, `func_001d8cb0`'s archive read 4 and was
one operand swap away.

For a search, amortise the harness. `verify`/`fndiff` reload the retail ELF and
rescan every marker in `src/` per candidate, about 9s; loading those once and
splicing candidates in-process costs 0.16s, which makes hundreds of
declaration orders or spelling combinations practical in a minute.

### 7f. Defensive C is the most common self-inflicted residual

Three recoveries this pass were blocked by C that was safer than retail's:

- `func_0020bff0`, `func_0020c680`, `func_0020ce60` initialised an `alpha`
  float that retail leaves unwritten on the reset path; the `= 1.0f` added an
  `lui`/`mtc1` pair at the top and shifted the whole object.
- `func_001d8cb0` ordered its nearest-target test `(first != 0) || (d < best)`
  to avoid reading `best` before the first iteration writes it. Retail emits
  the float comparison first, so the source is `(d < best) || (first != 0)`.

Retail routinely reads an uninitialised local on a path where the value is not
consumed, and the original source demonstrably did the same. Match it, and say
so in the note.

### 7g. Narrow the types m2c widened

Every `s64`/`u64` local that is really 32-bit costs a `dsll32`/`dsra32`
normalisation pair per assignment, and every `s16` loop index costs one per
increment. Grep an alignment for object-only `dsll32` runs: fourteen floors
carry that signature. `func_001a2d70` fell from 231 to 25 words on the type
narrowing alone, `func_001d8cb0` from 80 to 45.

### 7h. Pragmas that changed a result, with their signatures

- `opt_propagation off` — retail keeps a fold this build removes (a constant
  increment after a known-zero init, a `beqz` on a register the compiler knows
  is 1). Write masks as `(u16)call()`, not `call() & 0xFFFF`: propagation-off
  lowers the latter as `ori`/`and`.
- `opt_dead_assignments off` — retail materialises a constant in a loop
  preheader that this build rebuilds inside the loop, because the store that
  produced it is dead after loop rotation (`func_001b1020`).
- `opt_common_subs off` — retail reloads an address this build folds
  (`func_001a2d70`).
- `opt_loop_invariants on` — retail hoists a bound or a constant.

Measure the file-wide form before scoping one: `opt_dead_assignments off` for
all of `btlOrder_grouped.c` costs a match, and `-O2,p` for `btlAICommand.c`
costs seventeen.

### 7i. Declaration levers found while reconstructing untried functions

- **A global declared as a scalar lands in small data.** `extern u8 D_008C0000;`
  makes every access gp-relative; retail addresses those pad-snapshot bytes
  absolutely, so they are arrays. Declaring them `extern u8 D_008C0000[];` and
  indexing `[0]` took `func_00452870` from 265 differing words to 15 in one
  edit. Check the addressing mode in retail before trusting an m2c scalar.
- **Switch compare chains are emitted in reverse label order.** Writing
  `case 0: case 1:` produces retail's `beq 1` then `beqz` chain. That, plus
  spelling a two-value test as a switch rather than `||`, is what matched
  `func_00198dd0`; the same reordering cut `func_00154720`'s edit distance
  by a third.
- **A compound assignment evaluates its right side first.**
  `*(s16 *)(p + 0x35A) -= *(s16 *)(p + 0x35C);` loads 0x35C before 0x35A,
  which a staged local cannot reproduce - the compiler sinks the staged
  load. This was the item a previous pass had written off as temp-pool
  colouring on `func_00454640`.
- **Store the narrow result before the test that sign-extends it.** Writing
  the field and then testing the field keeps retail's `subu`, `sh`,
  `dsll32`/`dsra32`, `bgez` order; testing a local first extends early.
- **A `goto` out of a case puts the store on the branch path.**
  `if (state == 3) { p->state = 3; goto do_state3; }` with `do_state3:`
  beside `case 3:` reproduces retail's `bne`, `sw`, `b`; the same store
  written after an `if (state != 3) {...}` block lands after the else arm.

The smallest measured floors after this pass are `00375f00` (2),
`func_001a2d70` (2), `func_00452870` (4), `001130c0`, `001b11c0`,
`00311930`, `0034ddf0` and `func_00454640` (5), `0024be40` (8),
`0012d630` (15) and `004b2a00` (17).

### 8. Re-run the complete proof on the winner

After a candidate reaches an instruction-exact emitted prefix:

1. compile the actual edited owner;
2. resolve every target relocation;
3. compare the resolved target prefix to retail;
4. prove the retail suffix is zero alignment;
5. compare all non-target function bytes;
6. compare all non-target relocation metadata;
7. compare local tables and their relocations;
8. compile every caller owner changed by the ABI cutover;
9. compare those callers before and after;
10. run the repository verifier/link when available.

A proof should name exact counts, not say only "looks exact" or "build passes."

`verify.py` masks relocated fields, so it cannot see which symbol a
relocation names: a body that passes the wrong data symbol to a call still
scores MATCH. Only the link catches it. `func_002938c0` passed `D_0063C990`
where retail passes `D_0063C970` in three of four calls, scored MATCH, and
broke CI two pushes running with `loadable image sha1 ... MISMATCH, first diff
at vram 0x293a94`. Run `python tools/build.py` — about two minutes with a warm
cache, and it prints `loadable image sha1 ... OK` — after any recovery that
introduces, renames or re-points a data symbol, and read the first-diff vram
it prints: it names the exact word.

### 9. Integrate minimally

- Replace only the target `INCLUDE_ASM` marker and required declarations/callers.
- Keep the owner's dominant formatting and pragma state.
- Update the existing probe archive with the accepted source, sizes, relocation count, tail, and decisive compiler lever.
- Remove obsolete mismatch notes and unsafe prototypes.
- Do not edit unrelated formatting or user-owned files.
- Commit only explicit paths and push only after the actual-current proof.

## VU/COP2 recovery handoff

VU/COP2 code has a second interface beside the ordinary EE C ABI. A function
can receive or publish its real value through a vector register even when its
GPR return register looks live. Recover the hardware contract before tuning
the scalar C.

### Read transfers as part of the function signature

Use the retail instructions and the immediate consumers to classify each
transfer:

| Instruction family | Contract to recover |
| --- | --- |
| `lqc2 $vfN, offset(base)` | Load four 32-bit lanes from memory into a VU register |
| `sqc2 $vfN, offset(base)` | Store all four VU-register lanes to memory |
| `qmtc2` / `qmfc2` | Move a complete 128-bit value between an EE GPR and a VU register |
| `vitof*` / `vftoi*` | Lane-wise integer/float conversion with the encoded scale |
| `vmul*`, `vadd*`, `vmove*` | Lane masks and broadcast selectors are observable semantics |

### Do not classify `lqc2` or `sqc2` as an assembly floor

Commit `213e897d` measured instruction reachability over the retail bodies of
first-party functions already reported `MATCH`. Its control set contained 38
matched functions with `lqc2`/`sqc2` and 45 with COP2 macro-mode operations.
Those matches prove that MWCC b210 can emit these instruction classes from C
source already present in this tree. The presence of a VU quadword transfer is
therefore not evidence that inline assembly is required.

Treat the exact C spelling as a source-shaping problem. Start from the value's
real type, extent, alignment, ownership, and live-in/live-out contract; then
measure the generated instruction. Do not replace a truthful candidate with an
inline `lqc2`/`sqc2` solely to force the opcode. A larger VU arithmetic pipeline
may still correspond to an original SDK macro or hardware bridge, but that
judgment requires function-specific evidence. It cannot be inferred from the
load/store opcode.

An `lqc2` immediately before `jr $ra` can be the real output operation. Do not
replace it with a C pointer return:

- `func_0048a460` captures incoming `$vf10` with `sqc2`, computes a projected
  four-lane value in memory, then publishes it with `lqc2 $vf10`. Its observed
  callers consume `$vf10`, not `$v0`. The old candidate returned its local
  array only to keep `$v0` live; that pointer was dangling and the apparent
  eleven-word floor was invalid. The honest function is `void`.
- `func_0048a980` computes a quaternion into a four-float stack object and
  finishes with `lqc2 $vf10`. Its current 584/592-byte C floor has five
  executable FPR-color differences and two zero-tail words. The final transfer
  is part of the output contract, not incidental cleanup.

The converse is also important: callers discarding an ordinary return does not
prove that the return is fake. For `func_00484b30`, IDA preserves the copied
quadword result that Ghidra drops, and retail leaves that quadword live in
`$v0` through return. A truthful `u_long128` return plus the typed quadword copy
is part of the current exact source even though its C callers ignore the value.

### Preserve vector constants and lane semantics

Never replace a hardware value with a scalar value inferred from one lane.
PS2 VU register zero is not an all-zero 128-bit memory constant:

```text
$vf0 = (0.0f, 0.0f, 0.0f, 1.0f)
```

Therefore `sqc2 $vf0` writes three zero lanes and a `1.0f` W lane. The old
`func_00484b30` candidate zeroed all four lanes and was behaviorally wrong even
though most of its initializer looked equivalent. The recovered initializer
keeps four real `$vf0` stores, then overwrites only the fields retail overwrites.

Lane conversion and packing order also matter. The packed-color path in
`func_004865c0` is:

```text
packed bytes -> pextlb/pextlh -> qmtc2 -> vitof0
             -> scaled vmulx -> lane-wise vmul
             -> multiply by 255 -> vftoi0 -> qmfc2 -> ppach/ppacb
```

A scalar color formula is useful as a behavioral oracle, but it is not an
instruction-equivalent replacement for this sequence. Preserve lane masks,
broadcast selectors such as `$vf2x`, conversion scale, truncation, byte
wrapping, and positive-zero output lanes.

### Keep ordinary state and compiler-reachable transfers in C

The current clean-C campaign does not add new assembly as a code-generation
shortcut. `lqc2` and `sqc2` are known compiler-reachable instruction classes,
so first attempt the truthful C type, aggregate, alignment, and ABI shape.
Retain `INCLUDE_ASM` only after the actual-current candidate has a measured
function-specific floor. Existing bridge-based recoveries remain useful for
understanding hardware contracts, not as evidence that the transfer itself
requires assembly.

When auditing those existing bridges:

1. Keep allocation, traversal, callbacks, reloads, scalar arithmetic, and
   object layout in C.
2. Limit assembly to the actual hardware transfer or vector operation.
3. Use compiler-provided address operands. Never encode a literal stack offset
   or assume a local's frame position.
4. Name every C memory input/output touched by the bridge and declare
   `"memory"` plus the exact VU/GPR clobbers.
5. Prefer the established quadword-scratch shape for packed-word transfers.
   Inventing a generic scalar-register convention changed register allocation.
6. Reload callback-mutated list state in C after the bridge; a hardware block
   does not waive ordinary aliasing and mutation rules.

`func_004865c0` demonstrates the boundary: C owns `baseColor`, `childColor`,
the 16-byte-aligned parent snapshot, `packedColor`, list traversal, callback
lookup, and the post-callback next-pointer reload. The bridge names
`packedColor` as its memory output and uses quadword scratch for unpacking.
Naming the actual local removed an extra address materialization; reusing the
established scratch convention closed the remaining register differences.
The result is 276 emitted bytes in a 288-byte window, with an exact executable
prefix and twelve zero-tail bytes.

### Size and align only the hardware operand

`lqc2` and `sqc2` transfer sixteen bytes. Their memory operand must have a real
four-lane extent and 16-byte alignment. Do not widen unrelated data:

- `func_0048a460` uses genuine 12-byte XYZ input and transformed locals.
- Only its four-lane COP2 output is widened and explicitly aligned.
- Every lane loaded by `lqc2` must be initialized; both projection padding
  lanes are positive zero.

This distinction retained the 176-byte projection floor. Widening the XYZ
objects invents storage and changes code generation without strengthening the
hardware contract.

### Measured outcomes and stopped experiments

| Function | Current evidence | Decision |
| --- | --- | --- |
| `func_00484b30` | 120/128 bytes, three relocations, exact executable prefix, eight zero-tail bytes | Existing exact bridge: typed state, four real `$vf0` stores, `u_long128` copy/return, scoped propagation off |
| `func_004865c0` | 276/288 bytes, exact executable prefix, twelve zero-tail bytes | Existing exact bridge with C-owned state and packed-color VU operations |
| `func_0048a460` | 176/176 bytes, fifteen differing instruction words, ten exact relocations | Honest `void` floor; `$vf10` is the output. Production stays ASM because of the measured residual, not because `lqc2` is unreachable from C |
| `func_0048a980` | 584/592 bytes, five executable FPR differences and two zero-tail words | Plain-C quaternion arithmetic with a final `$vf10` load. Production stays ASM because of the measured FPR/code-shape floor, not the terminal `lqc2` |
| `func_004ad030` | Retail contains an interior `qmtc2`/`vitof0`/`vmulx`/`vmul`/`vftoi0`/`qmfc2` pipeline | Requires function-specific recovery; do not infer either C reachability or an assembly requirement from the transfer opcodes alone |

Do not retry already-closed substitutions:

- Replacing `func_00484b30`'s quadword copy with `memcpy` emits a library call
  even with intrinsics enabled and worsens the measured residual.
- Replacing `$vf0` stores with zeroed C aggregates changes W lanes.
- Returning a local array to imitate a live `$v0` is undefined and does not
  reproduce a `$vf10` output contract.
- Scalarizing a VU pipeline may validate arithmetic, but cannot establish an
  instruction match or the vector-register side effects.

### Verify hardware-bearing candidates in two layers

Instruction proof and behavior proof answer different questions:

1. Use `tools/fndiff.py` and `tools/verify.py` to prove the target COP2
   instructions, operands, lane masks, relocations, and accepted zero tail.
2. Run host smoke tests only against the C-owned state and portable boundary
   models. Check complete object images, alignment, spill canaries, callback
   mutation/reloads, lane values, packed-byte truncation, and pointer lifetime.
3. State the boundary explicitly: a native host smoke does not execute COP2,
   certify EE exceptional floating-point behavior, or emulate the VU.
4. For an assembly-backed floor, the retail fallback proves target hardware
   behavior; the archived C and smoke prove only the reconstructed portable
   portion.

Triage rule: a terminal `lqc2` or initial/final `sqc2` is a C source-shaping
target, not an automatic assembly boundary. Recover the vector-register
contract, use the truthful 16-byte type/alignment and lifetime, compile, and
inspect what MWCC emits. Retain ASM only for a measured function-specific
residual. For an interior VU conversion/multiply/pack pipeline, use matched
COP2 functions as reachability controls and test only bounded source or SDK
macro hypotheses; do not declare a floor from opcode class alone.

## Proof record template

Use this structure in a handoff or archive note:

```text
Target:
Owner:
Retail address/window:
Compiler/profile:
Evidence read:
Initial candidate:
Semantic rejection, if any:
Truthful residual:
Decisive source lever:
Candidate emitted/window bytes:
Relocations: count, resolved count, mismatches:
Resolved prefix comparison:
Retail suffix:
Other owner functions:
Other owner relocations:
Owner tables:
Callers/declarations changed:
Caller-owner isolation:
Hardware contract: VF inputs/outputs, transfers, lane masks, alignment:
Hardware proof boundary:
Runtime or semantic smoke boundary:
Repository verifier/link:
Commit:
Remaining caveats:
Private artifacts:
```

## Current high-value queue

The following floors were current immediately after `de42a42d`; remeasure before acting:

| Function | Measured floor | Residual character |
| --- | ---: | --- |
| `func_00375f00` | 156/160, two executable words plus zero tail | Cached base pointer versus recomputed indexed address |
| `func_003627b0` | 1864/1872, four executable words plus zero tail | Narrow-store/type interaction changes comparison code |
| `func_0034ddf0` | 700/704, five executable words plus zero tail | Float conversion destination and FPR coloring |
| `func_001130c0` | 440/448, five executable words plus zero tail | Cached color loads versus alpha arithmetic schedule |
| `func_001b11c0` | 192/192, five executable words | Two-register stable-partition allocation cycle |
| `func_0024be40` | 672/672, eight executable words | Found-pointer/counter saved-register cycle |
| `func_001b1020` | 408/416, seventeen executable words plus tail | Battle-order loop register allocation/layout |
| `func_001fb480` | 1732/1744, seventeen executable words plus zero tail | Two GP float loads scheduled before constant materialization |

Known exact-looking candidates that remain rejected unless a defined, truthful source form is found:

- `func_00277be0`: `1U << index` is undefined for an unproven index of 32 or more; explicit masking changes code generation.
- `func_00458ce0`: exact candidate reads `current` when the loop may execute zero times.
- `func_001d8cb0`: exact operand order compares an uninitialized best distance before the first-entry flag.
- `func_00452870`: retail passes six bytes after initializing only two; the consumer reads all six.
- `func_00486b00`: stored exact proof was invalidated by a current recompilation that produced a different 768-byte object.

The hardware-bound `func_0048a460`, `func_0048a980`, and `func_004ad030`
floors are documented in the VU/COP2 section above. Do not return them to the
ordinary source-shaping queue while the clean-C policy remains in force.

## Resume checklist

1. Refresh the first-party fallback inventory from the current tree.
2. Re-scan standalone measurement/proof artifacts for exact candidates not represented in parent-proof rankings.
3. Recompile every apparent exact source before trusting it.
4. Select the smallest truthful residual that has an untried source-shape lever.
5. Read assembly, Ghidra, IDA, archive, owner, callers, and providers in full.
6. Capture the actual-current owner baseline.
7. Run one bounded experiment family.
8. Apply semantic, relocation, owner-isolation, caller, and linked-image gates.
9. Update the archive, commit explicit files, and push.
