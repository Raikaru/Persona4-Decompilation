# First-party matching handoff

## Purpose

This is the operational handoff for continuing the first-party Persona 4 matching campaign. It complements `docs/matching.md`, which is the reusable MWCCPS2 source-shaping catalogue, and `docs/compiler-floors.md`, which records measured compiler limits.

The objective is a clean C replacement for each first-party `INCLUDE_ASM` function. A replacement is accepted only when its current source compiles to the retail executable instructions, every relocation resolves to the retail symbol and addend, any omitted window suffix consists only of retail zero alignment, and the C preserves the observed behavior and ABI.

## Current checkpoint

- 2026-09-18: **503 first-party `INCLUDE_ASM` left**, 6357 of 6860 MATCH (92.7%).
  Image `3d1d3d2b9d6ccb60836db239ab49674223025a78` and SLUS
  `4eeec0360cf2715535d9f7e52eb69d786fb0158c` byte-exact; 544 tests OK; lint 0 errors.
- MATCHed that day: `func_0027cae0` (itfMsgProcedure_Window), `func_002d3ee0`
  (y_fclShopDraw), `func_0035c040` and `func_00354ba0` (code1_0035),
  `func_0046ec70` (code1_0046).  Four of the five came from the argument
  emission-order rule in 7a-bis; read that section before anything else.
- Floors improved the same day: `func_001c79f0` 9 -> 2, `func_0025dd30` 14 -> 6,
  `func_00365f00` 25 -> 13, `func_00126090` 155 -> 148.
- New tool: `tools/micro_codegen.py` compiles a standalone snippet with the
  project mwcc and prints one function, for isolating a codegen rule in
  seconds instead of re-probing a whole recovery.

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

### 7a-bis. Argument setup is emitted in source-declaration order

Four of the five MATCHes landed on 2026-09-18 came from this one rule, so it is
worth checking before any register-allocation theory.

b210 lays down call-argument setup in the order the parameters appear in the
*callee's declaration*, not in ABI register order. The PS2 EABI gives integer
and float arguments independent register files (`$a0-$a3`/`$t0-$t3` and
`$f12-$f19`), so two declarations that interleave them differently produce the
**same registers** and different **emission order**. That makes the emission
order direct evidence for the real parameter list.

- Read the retail argument block. If `mov.s $f13, $f12` or `mtc1 $zero, $f12`
  sits between `lw $a0, ...` and `move $a1, $zero`, the floats are arguments 2
  and 3, not the trailing pair an m2c reconstruction usually produces.
- Confirm with a five-line micro-experiment (`tools/micro_codegen.py` compiles a
  standalone file with the project's mwcc and prints one function) before
  touching the tree; permuting a prototype there costs a second.
- Then fix *both* sides. Reordering the callee's own parameters is ABI-neutral,
  so a MATCHed definition stays byte-exact - verify it, then keep the two
  spellings consistent instead of leaving a lie in the caller.
- Worked examples: `func_002e0690` in `src/promoted/code1_002e.c` is
  `(u8 *, f32, f32, s8, s16, s64)` and that MATCHed `func_002d3ee0`;
  `func_00364680` is `(f32, s32, f32, f32, f32, f32, f32, f32, s32 *, s32,
  s32)` - the spelling `src/promoted/shdPersona.c` already carried - and that
  MATCHed both `func_0035c040` and `func_00354ba0`.
- `tools`-free scans that find candidates: compare every declaration of a
  callee across the tree and flag conflicting float positions; or look for a
  residual whose moved instructions write an argument register.

**A cast address argument is evaluated before the plain arguments.** Writing
`f(1, 0, 0, (s32)&frame.max, (s32)&frame.min, 1)` emits the two `addiu
$aN, $sp, ...` *first*; declaring those parameters as pointers and dropping the
casts restores retail's left-to-right order. This closed `func_001c79f0` from
7 to 2 words (`func_00196040`'s out-parameters are `f32 *`, exactly as the
MATCHed definition in `src/Battle/btlUnit.c` always said) and MATCHed
`func_0046ec70` (`func_004501f0`/`func_00450340` take a pointer for their
format argument). Grep floors for `(s32)&` inside a call: every hit is a
candidate.

**When a caller and a callee disagree, the caller decides.** Reordering a
callee's own parameter list is ABI-neutral and leaves its body byte-exact, so a
MATCHed definition proves nothing about the order; a MATCHed *caller* does,
because its argument setup is emitted in that order. `func_0045da40` in
`src/sdkPrimitive.c` was declared floats-last and its MATCHed caller
`func_0027d660` in `src/promoted/itfMsgProcedure_Window.c` passes the float
third; rewriting the caller to the definition's order turned it into a
MISMATCH, so the definition was corrected instead. Scan for these by comparing
every declaration of a callee against its live (unguarded) definition and
flagging differing float positions - 67 such disagreements were still open on
2026-09-18.

**K&R declarations are not the same lever and usually break the ABI.** An
unprototyped callee promotes `f32` to `double`; measured 329 differing words on
`func_00354ba0`. Only reach for it when the callee genuinely has no prototype.

### 7a-quinquies. Never expand a float-to-unsigned cast by hand

m2c writes `(u8)f` out as a compare against 2147483648.0f, a subtract, an
`| 0x80000000` and a mask.  b210 generates that same sequence for the plain
cast - and its own version colours the temporaries the way retail does, where
the expanded copy colours them the other way round.  Replacing the expansion
with `(u8)f` / `(u16)f` / `(u32)f` MATCHed `func_00348330`
(`src/promoted/y_CmbCardEff.c`, 15 -> 0) and moved `func_0013fb50` 95 -> 34,
`func_004a4450` 74 -> 66, `func_00263730` 285 -> 274, `func_00130ce0`
307 -> 299 and `func_00347c70` 56 -> 51.  Two more (`func_00266cc0`,
`func_003212e0`) tie on words with materially fewer edit groups, and only
`func_00130680` got worse (300 -> 306).

Grep floors for `| 0x80000000` together with `2147483648.0f` or `2.1474836e9f`;
the expansion appears in at least six different spellings (`<=`, `>=`, `<`,
`!(... <= ...)`, a named 2^31 local, and a one-line form), so match on the
`0x80000000` and read the branch rather than on any one shape.

### 7a-quater. Do not copy a float parameter into a local

m2c routinely emits `var_f22 = fparg0;` at the top of a function.  b210
propagates that copy away and then keeps the value in the argument register
`$f12`/`$f13`, where retail has it in a callee-saved `$f20`-`$f31`.  Using the
parameter directly makes b210 save it the way retail does.  This took
`func_002161d0` from 21 to 18 words and `func_00215c10` from 20 to 18 in
`src/promoted/code1_0021.c`; a two-definition pin on the copies is inert.

Signature to scan for: a `replace` group where retail names `$f2x` and the
object names `$f1x` in otherwise identical instructions.

### 7a-ter. Emission order of straight-line blocks follows definition order

Where a function converts several bytes and stores them (`vertex[8..11] =
(f32)(u32)edge_*`), b210 emits the conversion blocks in the order the locals
were *defined*, not the order the stores are written. `func_00365f00` in
`src/shdMisc.c` had the alpha byte defined first and its red-byte block landed
15 instructions after retail's; defining `edge_r` first took it from 25 to 13
words. Check the definition order before blaming the scheduler.

**Splitting an accumulate into two statements fixes float operand order.**
`x = a * b;` with one operand a constant or a `$gp` load puts the constant in
`rs`; `x = a; x = x * b;` puts `a` there, which is what retail does. Same for
`+`: the four `256.0f + load` adds in `func_0035c040` needed
`tx = *(f32 *)p; tx = tx + 256.0f;`. Commuting the operands in the single
expression is inert - b210 canonicalises it.


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

Parameter width also steers *argument setup order*, not just promotion masks.
`func_0013bcf0` (`src/promoted/code1_0013.c`) sat at 2 differing words over
2224 emitted instructions: at the `func_0013c700` call retail emits the
`daddu $a0, $v0` move before the `lh $a1, 0x34($v1)` load, and the draft
emitted the load first. Declaring that callee's second parameter `s16`
instead of `s32` flipped the order and closed the function. The callee's own
body is `INCLUDE_ASM`, so only the declaration moved. K&R form
(`extern s32 func_0013c700();`), `u32` first parameter, `s32` third parameter
and an `s16` return were all measured and all left the swap in place, so try
the width of the *loaded* argument first when a call's setup pair is
transposed.

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

### 7g. Declare every local at the width retail keeps it at

A `dsll32`/`dsra32` pair in your object that retail does not have is the
compiler telling you a local is declared at the wrong width.  It cuts both
ways, and the direction is read off the alignment, not guessed:

- **Too wide.**  Every `s64`/`u64` local that is really 32-bit costs a
  `dsll32`/`dsra32 0` normalisation per assignment.  `func_001a2d70` fell
  from 231 words to 25 on the narrowing alone, `func_001d8cb0` from 80 to
  45.
- **Too narrow.**  An `s16` or `s8` local holding a 32-bit value costs a
  `dsll32`/`dsra32 0x10` pair per use, and the object comes out *longer*
  than retail rather than shorter — which reads like a structural problem
  and is why this direction was missed for a long time.  `s16 i` to
  `s32 i` took `func_001f3bb0` from twelve instructions long to an exact
  234/234 and 186 words to 147.  Honest `s16`/`s64`/`s32` declarations with
  the matching `(s64)`, `(s64)(s8)` and `(s16)` extends took
  `func_001561a0` from ten long to four and 171 words to 163, and
  `func_003212e0` from 381 instructions to 375 and 331 words to 321.

The tell that a narrow type is *correct* is an `andi ..., 0xffff` or
`andi ..., 0xff` that retail also emits: that is a real mask in the
program.  A `dsll32`/`dsra32` pair with no retail counterpart never is.
Grep every alignment for object-only `dsll32` runs before anything else;
it is a one-line fix and it was worth 39, 24 and 10 words on three
different functions in one afternoon.

### 7h-bis. Two pragmas silently change the float-to-integer temporary

`opt_common_subs off` and `optimization_level 1` make b210 emit the
`(u8)`/`(u32)`-of-float idiom with the conversion writing back into the value
register (`cvt.w.s $f1, $f1`); every other setting, including plain `-O2`,
`opt_propagation off`, `opt_dead_assignments off`, `opt_peephole off`,
`scheduling off`, `opt_loop_invariants on`, `opt_strength_reduction off` and
`opt_unroll_loops off`, writes a fresh register (`cvt.w.s $f0, $f1`) - the
conversion temporary is allocated out of the common-subexpression table.
Confirmed with `tools/micro_codegen.py` on a five-line snippet.

Consequence: a floor whose only residual is that one register, and whose body
carries either pragma, has a **pragma-induced** residual. Do not look for a
source shape for the register; the real work is a source shape that does not
need the pragma. `func_00311930` (`src/promoted/code1_0031.c`, 5 words,
`optimization_level 1`) and `func_004b2a00` (`src/promoted/code1_004b.c`, 15
words, `opt_common_subs off`) are both in that state; measured, dropping the
pragma costs 32 and 240 words respectively, because b210 then hoists
`arg0 & 0xFFFF` into a ninth saved register that retail rematerialises.

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
- `opt_loop_invariants on` — retail hoists a bound or a constant.  The clearest
  signature: retail materialises the constant in the loop *preheader*, right
  after the counter init and before the `b` to the bottom test
  (`addiu $v1, $zero, 4`), while this build rematerialises it inside the body.
  That also swaps the two compare operands (`beq $v0, $v1` retail against
  `beq $v1, $v0` here) and leaves the object two words short, which shifts
  every later branch target.  On `func_0028fc40` the one pragma was worth
  nine words and the whole 8-byte size gap: 14 differing words to 5.  Things
  that do *not* reproduce it, all measured on the same body: an invariant
  `four = 4;` local before the loop, `for (k = 0, four = 4; ...)`,
  `opt_strength_reduction on`, and `opt_propagation on` (that one exploded to
  209 words).
- `tailcall on` — converts `jal X; epilogue; jr $ra` into `epilogue; j X`, but
  it also eliminates the frame.  Only reach for it when retail is frameless
  too.  `func_00512b90` is the counter-example: retail keeps `addiu $sp, -0x10`
  / `sd $ra` / `ld $ra` / `addiu $sp, 0x10` *and* tail-jumps, and no
  combination of `tailcall on` with optimization level 0/1/3,
  `opt_dead_assignments off`, `opt_lifetimes off` or `schedule off` reproduces
  the frame-preserving form.

Measure the file-wide form before scoping one: `opt_dead_assignments off` for
all of `btlOrder_grouped.c` costs a match, and `-O2,p` for `btlAICommand.c`
costs seventeen.

**A guarded body that does not compile is not a floor, and only one gate
catches it.** `verify.py` and `decomp_lint.py` both pass on a broken
guarded arm, because production takes the `#else INCLUDE_ASM` branch.
Compile the owner with `-DNON_MATCHING` after every edit, note-only edits
included.  A sweep of all 68 owners holding first-party floors found one
failure, `func_001dbba0` in `btlAICommand.c`, whose note claimed a measured
nd 204 for a body that had never built.

**A K&R definition does not create a prototype, and that is sometimes
load-bearing.** That same function is called below its definition with
heterogeneous function-pointer arguments; the prototyped form rejects every
one of them with `illegal implicit conversion`, while the K&R form

```c
s32 func_001dbba0(arg0, arg1, arg2, arg3, arg4, arg5)
s32 arg0; s32 arg1; s32 arg2; s32 arg3; s32 arg4; code arg5;
```

compiles and measures 7 differing words at an exact 222/222.  The inclusive
bound (`count > 1` for `count >= 2`) then took it to 2.  When a guarded body
is the only definition in its file and the calls below it pass diverse
types, K&R is not a style choice — it is what retail used and what lets the
unit build.

**"Saved-register rotation" is usually a symptom, not a wall.** A floor on
`func_0047e0f0` (`mdlSE.c`) carried a careful note describing a full cyclic
shift of six callee-saved assignments and listed six source shapes that did
not move it.  `#pragma opt_loop_invariants on` took the same body from 166
differing words to 10 and every saved register snapped onto retail's.  The
rotation was the downstream shadow of one unmeasured pragma.  Before writing
"rotation" in a note, measure all four pragmas on that exact body.

**Give an address-arithmetic temp two definitions to pin it.**  The last two
words of that same function were retail computing `col*12` into `$a0` ahead
of the base load while b210 sank it past.  Eight spellings failed — temps in
either declaration order, `col*12` against `(col*3)*4`, a `u8 (*)[8][12]`
grid, a 12-byte struct row base, `&base[row*96 + col*12]`, forced
parentheses, add-assignment, and hoisting the multiply above the bound
check.  What worked was defeating propagation by assigning the offset
through the destination:

```c
entry = (u8 *)((col * 3) * 4);
entry = *(u8 **)(arg0 + 12) + (row * 3) * 32 + (u32)entry;
```

A single-use temp is folded into the address tree and rescheduled; a
variable with two defs is pinned where it is written.  Reach for it whenever
`fnalign` shows an address chain scheduled after a load retail puts it
before.  With `s8 sb[4]` for retail's `lb` (not `u8`/`lbu`), that closed the
function to an exact 212/212.

**Re-derive an inherited body before you measure it.**  The archived
`func_0047e0f0` body contained a fabricated five-argument call to
`func_003b7060` — the no-argument RNG every other caller in the tree uses,
against an invented 5-arg extern — an index of `entry[writeIndex]` where
retail reads `entry[(u16)i]`, and a `default:` arm the switch does not have.
A wrong body measures a wrong wall, and nothing in the gate set re-checks a
banked body against the disassembly.

**Triage the whole tree before picking a target.** Two tools rank the work:

```
python3 -E -s tools/floorboard.py          # every guarded floor, ranked by words
python3 -E -s tools/opclass.py [owner.c]   # which opcode classes a floor gets wrong
```

`floorboard` recompiles all 214 banked first-party floors in parallel and
sorts them.  Nineteen are under twenty differing words and thirty-two under
fifty; those are the reachable MATCHes, and no amount of reading notes finds
them.  A cold 1500-byte window is a day's work for a three-figure floor.

`opclass` answers what `fnalign` cannot: not *where* a candidate diverges but
*what kind* of instruction it emits that retail never does, which names the
defect.  Surplus `dsll32`/`dsra32` is a local declared too narrow and a
shortfall is one too wide; `lbu` against `lb` and `lhu` against `lh` are
signedness; `cvt.s.w`/`mtc1` is an extern with the wrong return type or an
integer local that should be `f32`; `div` against `divu` is a signed modulo;
`jalr` against `jal` is a call through a pointer where retail calls directly;
a `lui` surplus is a constant retail hoists, so measure
`opt_loop_invariants on`.  Of 214 floors, 133 carry a surplus.

**An opcode-class fix that shrinks the object is not a fix.** This is the
tool's one trap and it caught two of three transplants in its first wave.
`func_0013f720` cleared twenty-one surplus `dsll32`/`dsra32` pairs and went
226 to 199 words with the object becoming size-exact at 267/267 — correct.
`func_00308f40` cleared fifteen pairs and the object fell from 402 emitted
instructions to 378 against retail's 427, eleven percent short, with both
`fnalign` edits and the word score worse; the histogram row looked perfect
because the code that needed those instructions had been deleted rather than
retyped.  A `jal`/`jalr` clear of fourteen on `func_0021fea0` likewise took
the object 560 bytes short.  Read `fnalign`'s header line — it prints retail
and object instruction counts — before and after every opclass change.

**An extern declared with the wrong return type is worth more than any
pragma.** A callee that returns `f32` but is declared `s32`, or declared with
an empty parameter list so the return defaults to `int`, makes MWCC emit an
`mtc1`/`cvt.s.w` round trip at every call site.  One such declaration —
`extern f32 func_0044b868()` where the truth is `(f32)` — cost 171 differing
words on `func_001c5500`, and writing it truthfully took that body from 249
to 78.  When `opclass` shows a `cvt.s.w` surplus, audit every extern the body
calls against the retail callee's actual return register before touching
anything else.

**There are eight cheap pragmas, not four, and pairs are a separate axis.**
`func_001dbba0` sat at two differing words with all four of the usual
pragmas measured on it — `schedule on` 199, `opt_loop_invariants on` 147,
`opt_common_subs off` 193, `opt_propagation off` 191 — and five source
spellings tried on the residual, which was retail evaluating the second
argument of a two-argument call first.  `#pragma opt_dead_assignments off`
alone takes it to zero.  It is live and byte-exact now.  The four that had
never been measured anywhere in this tree are `opt_strength_reduction off`,
`opt_dead_assignments off`, `opt_unroll_loops off` and `peephole off`.

```
python3 -E -s tools/pragma_sweep.py <owner.c> func_<addr>           # all eight
python3 -E -s tools/pragma_sweep.py <owner.c> func_<addr> --pairs   # + 28 pairs
python3 -E -s tools/pragma_sweep.py --board 50                      # every close floor
```

It strips pragma scaffolding already present in the banked body before
testing, so a pair is never silently tripled, and it prints the banked
baseline for comparison.  Sweeping the four new pragmas singly across all
thirty-four floors at or under fifty words produced exactly one win, the one
above — so singles are exhausted in that band and **pairs are the open
ground**.  The win was itself found by a pair sweep and then narrowed to a
single pragma, which is the order to work in.

**The 3% gate is on the instruction count, and it is not a formality.** Three
bodies were banked in one round at 48% short, 16% over and 3.8% over.  A body
emitting 257 instructions against retail's 490 is not a floor with a 428-word
residual, it is half a function: the word score is meaningless and the next
agent will try to grind down a number whose real cause is two hundred missing
instructions.  Over is the same problem mirrored — the object is doing work
retail does not, and every differing word after the first surplus instruction
is displacement noise.  `fnalign`'s header line prints both counts; compute
the percentage before writing the guard.  Outside 3%, leave plain
`INCLUDE_ASM` with a factual note saying how far off it is and what is
missing.  That note has value; a fake floor does not.

**Hand a lane your decode, not your target.** `func_0046ec70` is 400
instructions of debug-overlay text layout with two five-case switches and a
function-pointer dispatch.  Reading the disassembly into prose — the frame
layout, the two `f32` at `sp+0x158` forming an 8-byte pair passed by value as
`ld $a0`, which cases add `ctx + 0x28` and which do not, which use the
unsigned `(f32)(u32)` conversion idiom and which the plain signed one — took
one pass, and a lane then wrote and measured it to **20 differing words at an
exact 400/400** from cold.  The expensive part of a large cold window is the
decode, and it transfers perfectly in text.

**`#pragma optimization_level` is a real third axis, and it is exhausted on
the close floors.** Levels 0, 1, 3 and 4 each compile differently from the -O2
baseline — on a 218-instruction body they produce 253, 228, 179 and 179
instructions respectively, so level 3 is an 18% shrink and is the direction a
candidate that is *over* retail's size needs to move.  `tools/pragma_sweep.py`
measures all four automatically.  Swept across every floor at or under thirty
differing words, **none of them beats the baseline**: twenty-one floors, all
ties.  Record that as settled for the close band and reach for the levels only
on a body whose size is wrong.

**mwcc accepts unknown pragmas silently, with no diagnostic.** `#pragma
bogus_pragma_name on` compiles clean and changes nothing, and so do
`inline_depth(0)` and `optimize_for_size on`, which look plausible but are
ignored by this compiler.  A misspelled pragma is a no-op that is
indistinguishable from a measurement that found nothing.  Verify a new pragma
name changes the object before believing a tie:

```python
import sys, hashlib; sys.path.insert(0, "tools")
import fnalign, verify
body, _ = fnalign._object_for(owner, fn, candidate, verify.load_config())
print(hashlib.sha1(body).hexdigest()[:12], len(body) // 4)
```

`register` is in the same category: mwcc ignores the storage class at -O2,
identical object bytes, so an inherited body carrying it is not tainted.

Also note that a pragma already inside a banked body silently overrides a
leading one added for a probe.  `pragma_sweep` strips existing scaffolding
first; a hand-rolled probe does not, and will report a tie that is really the
inner pragma winning.

**Write `(f32)(u32)x` and let the compiler emit the conversion.** Retail's
`bltz` / `srl 1` / `andi 1` / `or` / `mtc1` / `cvt.s.w` / `add.s` block is
b210's unsigned-to-float idiom.  Hand-writing the halving and doubling
produces ten extra copies of it: `func_00495160`'s `opclass` read
`mtc1 +12, cvt +10, srl +10, andi +10, or +10, add.s +10, b +10, bltz +10`
until the manual sequence was replaced by the cast.

**Sharing one counter across disjoint loops is a live-range bug.** An
m2c-derived body usually declares every temporary at function scope, so a
single `s32 k` reused by three separate five-iteration loops has a live range
spanning the whole function and claims a callee-saved register where retail
uses `$a1`.  Declaring a counter inside each loop took `func_001679d0` from
158 differing words to 153 and removed a saved register from the frame.
Check every function-scope temporary that is written in more than one
unrelated place.

**Compare operand order decides load order.** On the same function,
`*(u16 *)(unit + 0x728) != *(s32 *)(work + j * 4 + 4)` emits the word load
first as retail does; the mirrored spelling emits the halfword first.  When
`fnalign` shows two loads swapped ahead of a `bne`, swap the comparison.

**A real `switch` with fallthrough produces retail's dispatch shape.**  Cases
2, 1, 0 compared in descending order followed by three bodies in ascending
order is what MWCC emits for a `switch`; an if/else chain interleaves compare,
body and branch instead.  `func_001679d0`'s case 1 falls through into case 2's
`return -1`, and writing that literally is what reproduced the chain.

**Banking rule, because it keeps being reinvented.** There is no score
threshold below which a body is worth keeping.  Byte-exact goes live with no
guard; anything that compiles and lands within 3% of retail's emitted
instruction count is banked as a guarded floor whatever it scores; only a body
materially short or materially over is a draft, and then the note says so in
plain terms with no invented numbers.  A 300-word floor in the tree beats a
90-word body in `/var/tmp`, because the floor is what the next agent starts
from and the only thing `floorboard.py` and `opclass.py` can measure.  Ten
compiling bodies were discarded under an invented "nd > 25 gate" in one round,
six of them into `build/`, which is gitignored.

**Sweep the cheap pragmas, never reason about them.** Each of these costs
one compile against a body you already have, so wrapping the guarded body
and re-measuring is strictly cheaper than deciding whether it "should"
apply.  Three sweeps over the 163 first-party guarded floors, run on the
same afternoon, landed 49 improvements between them:

| Pragma | Floors improved | Best single win |
| --- | ---: | --- |
| `opt_common_subs off` | 18 | `func_0045fbe0` 311 → 268 |
| `schedule on` | 18 | `func_00377930` 378 → 340 |
| `opt_loop_invariants on` | 13 | `func_0013fb50` 215 → 95 |

They are independent and they compose with source shapes, so apply them
first and then work the alignment.  The sweep is a dozen lines: lift each
body from between `#ifdef NON_MATCHING` and `#else`, score it bare and
wrapped, and keep the wrapper where the word count drops.  An agent that
skipped `schedule on` on the judgement that "scheduling alone is unlikely"
missed a 38-word win in the file it was working on.


### 7i. Declaration levers found while reconstructing untried functions

- **An index mask retail rematerialises needs both a `u16` parameter and
  `opt_common_subs off`.** Symptom: retail emits `andi $a1, $sN, 0xffff`
  immediately before each of several calls; this build computes it once
  into an extra saved register and emits `move $a1, $sX` at each site.  The
  real cost is the extra saved register: it adds an `sq`/`lq` pair and 0x10
  of frame, so the frame is one slot too big and every stack displacement
  shifts.  Narrowing the callees' index parameter to `u16` makes the mask a
  parameter promotion, which is never treated as a common subexpression;
  `opt_common_subs off` stops the remaining hoist.  Both are needed:
  `opt_common_subs off` alone also duplicates a `lwc1 $fN, <gp>` you wanted
  shared (152 words on `func_004938e0`), and the `u16` prototypes alone
  leave the CSE (109).  Together, 98 words at an exact 171/171 instruction
  count, and then one more shape below took it to MATCH.
- **`x == -1 || x == 0` is folded to a range check; retail keeps two
  compares.** b210 emits `addiu $v0, $v1, 1; sltiu $at, $v0, 2; beqz $at`
  (three instructions) for any pair of adjacent constants; retail emits
  `addiu $v0, $zero, -1; beq $v1, $v0, <body>; nop; bnez $v1, <skip>`
  (four).  `opt_rebuildconditionals off` does not stop the fold.  The only
  source form that reproduces retail is two separate tests with gotos into
  a shared body:

  ```c
  if (x == -1) { goto shared; }
  if (x != 0)  { goto other; }
  shared:
      /* body */
      continue;
  other:
  ```

  That was the last four words of `func_004938e0`.  Any `a == K ||
  a == K + 1` in a condition is a candidate.
- **`slti $at` versus `slti $v0`: spell the bound inclusively.** Retail's
  branch-if-true range tests land the compare in `$at`; this build puts it
  in `$v0`/`$v1` when the bound is written exclusively and in `$at` when it
  is written inclusively.  The emitted `slti ..., $sN, N` is identical
  either way.  `dungeon < 6` gave 2 differing words on `func_0018c7e0` and
  `dungeon <= 5` gave 0; `6 > dungeon`, `!(dungeon >= 6)` and
  `(dungeon < 6) != 0` all keep `$v0`.  The same flip in the other direction
  (`>= 5` to `> 4`, `>= 6` to `> 5`, `>= 3 && < 9` to `> 2 && <= 8`) fixed
  the destination on `func_001dbf20`, `func_001b3a00`, `func_001f3bb0`,
  `func_00383f80` and `func_00154720`.  `< 1U`/`< 2U` is the unsigned form,
  and it took `func_00513380` from 3 words to 2.  Note this does NOT apply
  to the register-to-register `slt $at, $zero, $aN` loop entry guard, which
  has its own cure below.  An automated scan for the pattern is worth
  running over every banked floor: `tools/fnalign.py` output with
  `retail slti $at` against `object slti $v` is a one-lever fix.
- **A trailing dead arm must carry its dead store.** Retail often ends an
  if/else-if chain with a compare whose result nothing consumes
  (`slti $at, $s3, 0xa0` immediately followed by the shared tail).  That is
  NOT an empty `else if (x < N) { }`: b210 deletes an empty arm compare and
  all, which costs the compare plus its `b`/`nop` and shifts every later
  branch displacement, so the object comes out 1-4 instructions short of
  retail with a large word count that is almost entirely cascade.  Write the
  arm with the store that is redundant on that path — `else if (x < 0xA0)
  { res = 0; }` when `res` is already 0 there — and b210 removes the store
  but keeps the compare, which is exactly retail.  That single change was 40
  differing words to 2 on `func_0018c7e0`, and took `func_001fbb50` from
  two instructions short to an exact 405/405 and 336 words to 320.
  `opt_dead_assignments off`, `opt_dead_code off`, `opt_propagation off`,
  `opt_rebuildconditionals off` and optimization levels 1 and 3 all fail to
  reproduce it; only the source shape does.  "Object N instructions short of
  retail" with N in 1..4 is the signature to scan for.
- **`(s64)0 < count` fixes the `slt $at, $zero, $aN` loop entry guard.**
  When retail's loop entry guard is `slt $at, $zero, $aN` followed by
  `beqz` and this build gives `slt $v0`/`slt $v1` or a plain `blez`, write
  the guard with a 64-bit zero on the left and hoist the counter init above
  it so it lands in the branch delay slot.  `func_003bcd50` is the worked
  example in the tree and carries the accompanying `schedule on`,
  `no_branch_likely on`, `opt_rebuildconditionals off`,
  `opt_propagation off` set.  It does not transfer everywhere: measured as a
  regression on `func_003b4230` (2 to 42 words), `func_003bce50`,
  `func_003b31a0` and `func_003bcc80`, so measure before keeping it.
- **A cast at a call site, not the scheduler, is what moves an argument
  load.** On `func_0047ce00` the whole two-word residual was that retail
  ends the argument block with the trailing stack load — `daddu $a3, $v0`
  (the nested call's result) and only then `lw $t0, 0x4c($sp)` — while this
  build hoisted the `lw` one slot earlier. The out-parameter local was
  declared `s32 sp4C` and passed as `(u32)sp4C`; the cast made it a
  conversion expression, which b210 evaluates eagerly. Declaring the local
  with the type the callee actually takes, `u32 sp4C`, and passing it bare
  restored retail's order and matched the function. The `&sp4C`
  out-parameter then needs `(s32 *)&sp4C`, which costs nothing. Generalise:
  when the residual is argument-setup *order*, audit the casts. Reaching
  for the scheduler is actively harmful here — `schedule off` around the
  call took the same body from 2 words to 120, and staging the nested
  call's result in a temp gave 80. A function-local K&R redeclaration of
  the callee and a function-local prototype with a different fifth
  parameter width were both no-ops.
- **The parameter home-move block cannot be reordered from source.** When
  the only residual is the order of the `daddu $sN, $aM, zero` copies, stop.
  On `func_0028fc40` retail emits them in argument order (a0, a1, a2, a3,
  t0) and b210 emits them in allocation order (a2, a3, t0, a0, a1 = s5, s4,
  s3, s1, s0) with the *colouring already identical*. Declaration order,
  initialiser-versus-assignment form, assignment order, K&R definition form
  and direct-parameter-versus-copy-local models were each measured and all
  five give the same five words.
- **A global declared as a scalar lands in small data.** `extern u8 D_008C0000;`
  makes every access gp-relative; retail addresses those pad-snapshot bytes
  absolutely, so they are arrays. Declaring them `extern u8 D_008C0000[];` and
  indexing `[0]` took `func_00452870` from 265 differing words to 15 in one
  edit. Check the addressing mode in retail before trusting an m2c scalar.
- **Switch compare chains are emitted in reverse label order.** Writing
  `case 0: case 1:` produces retail's `beq 1` then `beqz` chain. That, plus
  spelling a two-value test as a switch rather than `||`, is what matched
  `func_00198dd0`; the same reordering cut `func_00154720`'s edit distance
  by a third. The reversal covers the **whole label sequence**, not just
  the groups: on `func_00463930` reversing the groups alone left every
  label inside a group backwards, and reversing both took it from 182
  words to 155. The bodies still come out in source order, so a switch
  whose arms must appear in a particular order cannot also have its
  chain in that order - that conflict is the residual there, where
  retail places the `default` body between the chain and the first case.
- **An outer dispatch that m2c prints as a switch is often an if/else-if
  chain.** The tell in retail is each arm's body sitting inline right
  after its own `bne`, with arms that share a return value falling
  through to one shared `return` instead of each materialising the
  constant. A real jump table looks different: `sltiu` bound check, then
  `lw`/`jr`. On `func_00207320` that distinction was 427 words to 311,
  and `jtbl_` in the retail asm tells the two apart before you write a
  line.
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
- **Integer arguments five through eight arrive in `$t0`-`$t3`.** This is
  the MIPS EABI, not o32: a function whose asm never touches the incoming
  stack can still take eight integer parameters. `func_00256460` reads
  `$4`-`$7` and `$9`/`$10` and forwards `$8` to its callee without ever
  loading it, which is exactly what an argument the body only passes
  through looks like - seven ints and five floats, where m2c printed six.
  Count the `$t` registers read before their first definition.
- **A clamp written `> LITERAL` and one written `>= LITERAL+1` allocate
  differently.** `if (tier > 9)` keeps the compared value in `$v0` with
  the test in `$at`; `if (tier >= 0xA)` moves it to `$v1`. Identical
  semantics, twelve words apart - this was the last edit on
  `func_00245030`.
- **A local array's size sets the next local's stack slot.** An off-by-one
  frame usually means a buffer is larger than the loop that fills it:
  `func_00256460` writes sixteen colour entries but the buffer is
  `u8 [20][4]`, which is what places the position array at `0xC0` and
  makes the frame `0x140`.
- **An 8-byte struct copy through a typed pointer emits `lwc1`/`swc1`.**
  Where retail uses `lw`/`sw`, stage the two words through `u32` locals
  instead of writing `*dst++ = *src++`.
- **An induction variable is zeroed before the invariants beside it.**
  Retail's `for` prologues read `move $s2,$zero` and only then compute the
  row pointer and the row's base coordinate. Writing the invariants as
  plain statements above the loop emits them first and costs a word at
  every nesting level; folding them into the header -
  `for (c = 0, row = shape + r * 5, ry = y + r; c < 5; c++)` - reproduces
  retail's order. This was the last 68 words of `func_00156cf0`.
- **Code reached by falling out of a loop belongs after the function's
  other `return`.** `func_00156cf0`'s second pass runs when the 5x5 scan
  completes; written inside the column loop it forces every failure branch
  to jump over it (248 words of pure displacement), written as a label
  after `return 0` it lands where retail puts it (68).
- **Two passes over the same grid want two counters.** Reusing the scan's
  index for the second pass costs 72 words - and if the reuse is nested,
  it also miscompiles. m2c's `var_19` / `var_19_2` naming is a real
  distinction, not noise.
- **m2c's pointer type scales every stride.** A draft that types the base
  `s16 *` turns a stride of 5 into 10 and 0xC into 0x18. Read one
  `sll`/`addu` pair out of retail before trusting the draft's type: the
  same defect hid `arg2[j]` behind `*(u8 *)(arg2 + j * 2)` in
  `func_00303610`.
- **Loop counters in a block scope allocate after the hoisted temporaries.**
  A function-scope `i` takes `$v0` before MWCC assigns the loop's hoisted
  `lui`, `andi` and pointer temporaries, and every one of them rotates;
  declaring `{ s32 i; u8 *quad; for (...) ... }` inside the block that owns
  the loop puts retail's `lui` in `$v0` and the counter in `$t1`. That was
  58 of 96 alignment edits on `func_00103f00`, with no change in word count
  until the next lever landed. Declaration order at function scope did
  nothing.
- **A struct copied to the stack and read back in two places gets its
  expressions folded across calls.** `Pos pos = *(Pos *)(arg0 + 0xC);`
  followed by `256.0f + pos.x` in two halves of `func_00103f00` kept the
  sum in `$f21` and the y reload in `$f20` across the intervening calls;
  retail reloads both from the slot. `f32 pos[2]` filled by the same 8-byte
  struct copy through a cast reads back as array elements, which MWCC does
  not fold (350 -> 247 words). Read each element into its own local before
  the add when retail loads before it materialises the constant.
- **A RenderWare global is a member of `ourGlobals`, not a scalar.**
  `D_008872F8` is `RWSRCGLOBAL(dOpenDevice).zBufferNear` at
  `ourGlobals + 0x18`; `D_00887300`/`D_00887310` are the render-state and
  Im2D entry points that follow it. Inside a loop the array spelling
  `D_008872F8[0]` hoists the whole load, and the scalar spelling goes
  gp-relative; a member access through a prefix of `RwGlobals`/`RwDevice`
  (see `src/promoted/code1_0010.c`) hoists only the `lui` and keeps
  `lwc1 %lo(...)` in the loop, which is retail's shape and the last words
  of `func_00103f00`.
- **An integer-arithmetic destination moves `addiu $a0` to the head of an
  argument block.** `func_0047ce00` passed `arg0 + 0x2D0` and emitted the
  two `lhu` and the `lw` first; `(u8 *)((u32)arg0 + 0x2D0)` emits retail's
  `addiu $a0` first (5 -> 2 words). The remaining fifth-argument `lw $t0`
  placement resisted every width and nesting.

The smallest measured floors after this pass are `00375f00` (2), `0047ce00` (2),
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

### Next actions, in priority order (2026-09-18)

1. **Finish the parameter-order audit.** 67 declarations still disagree with a
   live definition's float positions (43 files; `src/promoted/shdPersona.c`,
   `src/Battle/btlResultSimple.c` and `src/promoted/code1_0012.c` hold four to
   six each).  Rule: a MATCHed *caller* proves the order, a MATCHed definition
   does not - reordering a definition's own parameters is byte-neutral.  Fix
   each side so they agree, then re-verify the owner; every fix so far has
   been free and four of them produced MATCHes.
2. **Floors whose residual is a displaced argument-register write.** Compile
   each floor, align it with `tools/fnalign.py`, and flag any insert/delete
   group whose moved instructions write `$a0-$a3`, `$t0-$t3` or `$f12-$f19`.
   On 2026-09-18 that flagged 188 floors; the largest are `func_00252710`
   (188 words, 18 moves), `func_0020f730` (194, 16), `func_00126090` (148,
   13) and `func_002afbc0` (199, 10).
3. **Do not grind a residual that a pragma is causing.** See 7h-bis:
   `opt_common_subs off` and `optimization_level 1` change the float-to-integer
   conversion temporary, and 29 floors carry one of them.
4. Remaining sub-20 board after the day's work: `func_00375f00` 2,
   `func_001c79f0` 2, five at 5, `func_0025dd30` 6, `func_0024be40` 8,
   `func_00485870` 10, `func_001eca10` 11, `func_00268230` 12,
   `func_0012d630` 13, `func_00365f00` 13, three at 15, two at 19.


503 first-party functions still fall back to `INCLUDE_ASM`.  Derive the list
authoritatively — do NOT guess from the file path:

```python
import json, sys; sys.path.insert(0, 'tools')
import verify
from pathlib import Path
d = json.load(open('report.json'))           # tools/verify.py --json report.json
asm = [r for r in d['results']
       if r['status'] == 'ASM'
       and verify.code_origin(Path(r['file']), int(r['addr'], 16)) == 'main']
```

`verify.is_third_party(path)` is a *file*-level predicate and disagrees with
the per-function provenance: `code1_0041.c`, `code1_004e.c`, `code1_004f.c`
and `code1_0051.c` all answer "first party" to it while every function in
them is third party.  A batch scoped with the file-level predicate spends its
whole budget off-goal.

Densest owners, first-party ASM count: `y_fclCombineDraw.c` 33,
`code1_001a.c` 18, `y_fclCombine.c` 17, `code1_001b.c` 15, `code1_001c.c` 15,
`y_fclShopDraw.c` 13, `code1_0038.c` 13, `code1_0048.c` 13, `cmmRankUp.c` 11,
`code1_0020.c` 11, `shdPersona.c` 11.

Smallest windows first — these are where a MATCH is still plausible.  The
following floors were current immediately after `de42a42d`; remeasure before
acting:

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

## Triage banked floors by residual signature, not by word count

A floor's differing-word count is a poor priority signal: most of it is
usually branch-displacement cascade from one early divergence.  The useful
signal is the *shape* of the residual, and two shapes each have a known,
cheap cure, so it pays to scan every banked floor for them mechanically
rather than reading notes.

For each `// FUN_<ADDR> NONMATCHING` in the tree, lift the body from between
`#ifdef NON_MATCHING` and `#else`, write it to a scratch file outside the
repo, and run:

```
python3 -E -s tools/fnalign.py <owner.c> func_<addr> --candidate <scratch.c>
```

Then classify the output:

- `retail slti $at` against `object slti $v0`/`$v1` — flip the bound to the
  inclusive form.  One-line fix.
- `retail N instrs  object M instrs` with `N - M` in 1..4 — a trailing dead
  arm whose redundant store must be spelled out.  Also a one-shape fix, and
  it usually collapses the whole cascade: two floors went from two
  instructions short to an exact instruction count this way.
- `retail slt $at, $zero, $aN` — the loop entry guard; try `(s64)0 < count`
  with the counter init hoisted above it, but measure, because it regresses
  as often as it helps.

Three workers over ~290 floors takes about fifteen minutes and returns
roughly forty hits, ordered by `edit instructions:` from the same output.
Work the lowest edit counts first — they are the ones where the residual
really is one shape rather than a pile.

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
