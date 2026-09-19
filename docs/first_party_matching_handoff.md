# First-party matching handoff

## Purpose

This is the operational handoff for continuing the first-party Persona 4 matching campaign. It complements `docs/matching.md`, which is the reusable MWCCPS2 source-shaping catalogue, and `docs/compiler-floors.md`, which records measured compiler limits.

The objective is a clean C replacement for each first-party `INCLUDE_ASM` function. A replacement is accepted only when its current source compiles to the retail executable instructions, every relocation resolves to the retail symbol and addend, any omitted window suffix consists only of retail zero alignment, and the C preserves the observed behavior and ABI.

## Current checkpoint

- 2026-09-18: **501 first-party `INCLUDE_ASM` left**, 6359 of 6860 MATCH (92.7%).
  Image `3d1d3d2b9d6ccb60836db239ab49674223025a78` and SLUS
  `4eeec0360cf2715535d9f7e52eb69d786fb0158c` byte-exact; 544 tests OK; lint 0 errors.
- MATCHed that day: `func_0027cae0` (itfMsgProcedure_Window), `func_002d3ee0`
  (y_fclShopDraw), `func_0035c040` and `func_00354ba0` (code1_0035),
  `func_0046ec70` (code1_0046), `func_00348330` (y_CmbCardEff) and
  `func_00311930` (code1_0031).  Four came from the argument emission-order
  rule in 7a-bis and one from 7h-sexies; read those two sections first.
- Floors improved the same day: `func_001c79f0` 9 -> 2, `func_0025dd30` 14 -> 6,
  `func_00365f00` 25 -> 13, `func_00126090` 155 -> 148.
- **The residual splits in two.**  276 functions are banked floors with a
  measured body; the other 221 have no C body at all - a bare `// FUN_` marker
  and a plain `INCLUDE_ASM`.  Every one of those 221 is large (356 instructions
  at the smallest, 1221 on average, 271k instructions in total), which is why
  they were left: they are the biggest functions in the game, not the hardest.
  A first reconstruction there is worth more than another pass over a
  five-word floor, and `tools/m2c_decompile.py` plus the 7i declaration levers
  is the route in.
- New tools: `tools/micro_codegen.py` compiles a standalone snippet with the
  project mwcc and prints one function, for isolating a codegen rule in
  seconds instead of re-probing a whole recovery.  `tools/residual_signature.py`
  classifies every banked floor's residual as mask-rematerialisation,
  conversion-register selection, or neither, so the two fixable classes can be
  found without reading 276 alignments by hand.

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

Section 7h-sexies is the same lever seen from the other side, with the rule
that decides which way to turn it: the *callee's* parameter narrow makes the
mask an argument conversion that is re-emitted at every call, while the
*caller's own* parameter narrow makes it one hoisted value in a saved
register. Retail's choice is visible in the alignment - repeated
`andi $a0, $sN, 0xffff` means the first, a single `andi` plus `move $a0, $sN`
at each call means the second.

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

### 7n. A counter shared across two loops forces a callee-saved register

Retail sometimes keeps a loop counter in a caller-saved register ($a1, $a3)
where the candidate uses a callee-saved one ($s3, $s4).  That is not the
7m exchange class - it is a register *class* difference, and it has a source
cause worth checking: **one variable serving both a call-free loop and a
later loop that makes calls**.  The shared live range crosses a call, so the
allocator must pick a callee-saved register for the whole thing, including
the loop where retail used a temp.

On `func_0013fb50` the same `k` ran `while (k < 0x6C)` (no calls) and
`while (k < 0x19)` (three calls per iteration).  Giving the first loop its own
counter was worth **34 -> 28 words**, and the counter moved to $a3 as retail
has it.  It has to be a *fresh* variable: reusing the earlier `i` costs 33 and
reusing `j` costs 96.

Check for it whenever the alignment shows the same instruction with an $aN in
retail and an $sN in the candidate.  It does not always apply - on
`func_00303610`, which shows the identical $a1-versus-$s3 symptom, splitting
the shared `j` ties at 27, so the cause there is something else.  One probe
settles it either way.

### 7af. Two axes b210 will not expose to source

Both were established by exhausting them, not by argument, and both should be
quoted rather than re-searched.

**`optimize_for_size` is a no-op in this compiler.**  `pragma_sweep` says so in
its own header and a direct probe on `func_00413290` confirmed it: the score
did not move by one word.

**`-O2,p` is reachable only from the command line.**  `func_00413290` differs
from retail by division against magic-multiply: retail divides, b210 at plain
`-O2` strength-reduces to a multiply.  With `-O2,p` the body is 46 instructions
against retail's 47; with the project's flags it is 41 against 47 and no pragma
spelling reaches the `,p` form.  Every single pragma ties at 35 words
(`optimization_level 3`, `4` and `schedule on` are worse at 37, level 0 is 59).
Until the build grows per-file flags, that function is walled - and the note
says so rather than pretending a search is still open.

The same shape of evidence closed `func_00443010`, where retail selects `movn`
and b210 does not: every single pragma ties at 25 or worse, and `peephole off`
makes it 38, which is what proves the axis was actually tested rather than
skipped.  Note also that this function is *not* ee-gcc output despite sitting
in `code1_0044.c` next to reclassified code: it carries neither the absolute
getter nor the framed tail jump signature.

### 7ag. Stack pragmas one residual at a time

Two functions reached zero today by a method worth copying exactly.  Do not
sweep pragma combinations; apply one, re-read the aligned listing, and choose
the next from what is left.

On `func_00413640` (49 against 48, 24 words, 3 edits): `schedule on` filled the
branch delay slot and took it to 4 words, which exposed two `beql`
with-load-in-slot differences; `no_branch_likely` removed those and the body
hit **0 words, 0 edits, 48/48**.

On `func_003d2240` (43/43, 31 words, 12 edits): `schedule on` -> 24 words / 3
edits, `no_branch_likely` -> 24 / 1, and the last edit was retail's redundant
`lw $v0, ($s2)` before the first store, which b210's redundant-load peephole
deletes by forwarding `$v0` from the call - `peephole off` closed it to
**0 words, 0 edits, 41/41**.

The reason sweeping misses these is that each pragma only reveals the next
residual: at 24 words a pair sweep sees no improvement worth taking, because
the win is three pragmas deep.

### 7av. Descending compares with ascending bodies means `switch`, not a chain

`func_00288af0` was an if-else chain written in source order 0, 1, 2 and it
scored **409 fnalign edits** on 268 instructions.  The dispatch in retail
reads:

    R8   addiu $v0, $zero, 2
    R9   beq   $a0, $v0, .+42      <- case 2 tested first
    R12  beq   $a0, $v0, .+37      <- then 1
    R14  beqz  $a0, .+4            <- then 0
    R16  b     .+241               <- default

and then the **arm bodies appear in ascending case order**, case 0's
`D_008821E0` test and `lw 0xc($s2)` immediately after the dispatch.  Compares
descending, bodies ascending: that is MWCC's switch lowering, and no if-else
chain reproduces it.

Rewriting as `switch (arg0)` with the cases in ascending source order:
**409 -> 104 edits**, 273 against 268 (+1.9%, inside).

The diagnostic that makes this cheap to spot: reversing the chain by hand to
2, 1, 0 gets **part** of the way - 167 edits - because it fixes the compare
order but leaves the bodies in the wrong place.  **If reversing a chain helps
but does not close, the construct is a switch.**

Note it is not universal.  `func_00467bd0` has a five-way chain whose retail
compares also run 4, 3, 2, 1, 0, and there the `switch` spelling is *worse*
(382 against the chain's 368) - because its arm bodies are laid out in the
chain's order, not ascending.  Read where the bodies go, not just the
compares.

### 7at. `tools/regsave_scan.py`: read the prologue before testing anything

The scanner compares the callee-saved set a guarded body allocates against
retail's, for every measured floor.  **39 of the top 60 differ.**  Neither
direction shows up in the word score, and neither is reachable by editing the
body's arithmetic:

- **Retail saves registers the body does not.**  The body is holding those
  values in memory and reloading them after each call.  `func_001400f0`:
  retail `sq $fp,0xb0  sq $s7,0xa0  sq $s6,0x90 ... sd $ra,0xc0`, object
  starts at `$s5` with `$ra` at 0x90 - three registers and 0x30 of frame.
- **The body saves registers retail does not.**  Retail recomputes them at
  the use.  `func_00467bd0` saves `$s2`/`$s3`/`$s4` for a frame of 0x1A0
  against retail's 0x170 - exactly three 16-byte slots - while retail
  re-emits `lui $v0, 8; addu $v0, $s0, $v0` at every single field access.

Two results this session bound the lever.  `func_00330060`'s frame was short
**and aliased** `cA8` and `c98` onto slot 0x98; the explicit frame struct took
it from **726 edits to 146**.  `func_001400f0`'s frame was short but merely
offset; correcting it to an exact 0x230 with three genuine hoists moved the
edits the wrong way, 1991 to 2007.  So the rule is narrower than 7as first
stated: a uniform displacement shift is charged once per access, an alias
corrupts the dependency chain around both values.  Check for a collision, not
just a difference.

### 7au. Retail's first-party build is unscheduled; `#pragma schedule on` is count manipulation

**Across 212 byte-exact MATCH first-party functions there are 2909 branches
and zero filled delay slots.**  Not a few, none.  The same holds for every
function that still has a floor: `func_00475cd0` has 179 branches and 179
empty slots, `func_004b1ad0` 76 and 76, `func_004a5fc0` 75 and 75,
`func_0021a7b0` 49 and 49, `func_0049e150` 40 and 40, `func_00308f40` 97 and
97, `func_003599c0` 112 and 112.

So `#pragma schedule on` cannot reproduce retail codegen in first-party code.
What it does is let the scheduler consume delay-slot nops, which shortens the
body.  Five guarded bodies were carrying it, and in every one it was hiding a
genuine instruction surplus:

| function | with the pragma | truth without it |
|---|---|---|
| `func_00475cd0` | 1007/1000 "inside" | 1131/1000, **+13.1%** |
| `func_004b1ad0` | 802/796 "inside" | 909/796, **+14.2%** |
| `func_004a5fc0` | 762/756 "inside" | 851/756, **+12.6%** |
| `func_0021a7b0` | 418/427 "inside" | 460/428, **+7.5%** |
| `func_0049e150` | 489/499 "inside" | 531/500, **+6.2%** |

All five were inside the 3% gate only because of the pragma.  They are now
recorded as the out-of-gate floors they are, and the surplus has to be written
out of each body rather than optimised away.

`func_00308f40` is the same defect caught from the other side: the pragma had
been added because it bought 15 differing words, and it cost 48 instructions,
leaving the body at 379 against 427.  Removing it: **431/428 inside, edits
323 -> 102.**

The vendor middleware was built the other way and must not be swept up in
this: the 39 third-party guarded bodies that carry the pragma sit on retail
windows with 260 branches and **183 filled slots**.  Two build configurations
in one image.  `decomp_lint`'s new **H010** is an error, scoped by function
origin rather than by file, so first-party bodies cannot acquire the pragma
again while `src/promoted/code1_003c.c` and its neighbours keep theirs.

`tools/regsave_scan.py` now reports nop density on both sides, so the
mismatch shows up on the first draft rather than after a body has been tuned
around it.

### 7as. A short frame aliases two locals onto one slot

`func_00330060` was 468/468 - an exact count - with **726 fnalign edits**, more
than one differing instruction for every two in the function, and two huge
asymmetric runs.  Every block-order hypothesis failed against the assembly:
retail really does put the switch at instruction 76 and the `for` at 263, and
a probe that reordered them scored better on words (402 against 418) while
leaving the edit count identical at 726.

The cause was the **frame**: object 0xA0 against retail 0xB0, with two locals
- `cA8` and `c98` - both landing on offset 0x98.  Sixteen bytes of missing
frame put two values in one slot and misaligned every spill after it, which
is what produced the 726.

Declaring the explicit frame struct at retail's offsets

    struct { u8 pad00[0x90]; s64 sp90; FclByte4 c98, c9C, cA0, cA4, cA8, cAC; }

re-homed the seven locals from 0x80-0x9F to retail's 0x90-0xAF and took
**726 edits -> 146**, with no run above four instructions left and the count
unchanged at 468/468.

So when a body has an exact count and an edit ratio above one, check the
prologue before testing any block order.  A short frame is the cheapest
possible explanation and the most destructive one: it does not change the
instruction count at all, so the gate and the word score both look healthy
while the whole body is misaligned.  Note the direction matters - the same
function's neighbour `func_00475cd0` is 0x1D0 against retail's 0x1A0 with
three extra saved registers, which needs a shrink rather than a pad.

### 7ar. Where the early `return` goes decides the whole layout

`func_003c1bd0` sat at 20 differing words for two sessions with its residual
filed as "branch/call layout".  It is now a **MATCH at 40/40 with zero edits**,
and the fix was where a single `return 0` is written.

Retail's `bne $v1, $v0, .+9` jumps to a `b` / `move $v0, $zero` pair at
instructions 16-18 - *after* the inner test, not before it and not at the end
of the function.  A trailing `return 0` puts that pair last; an early
`if (state != 1) return 0;` puts it first.  Neither is where retail has it.
The shape that places it correctly is an `else` on the **outer** test with the
inner test nested above it:

    if (state == 1) {
        if ((flags & 0x01000000) != 0) {
            return 1;
        }
    } else {
        return 0;
    }
    ...work...
    return 1;

Measured on the way there: trailing `return 0` 20 words, early return 10, the
early return written as `goto zero` with the label at the end 20, and
single-return result-variable forms 29.

Two general points.  A residual described as "branch layout" is usually an
**arm placement** fact, and arm placement is a source decision - compare where
retail's conditional branch *targets* against where your body puts the block.
And an early return is not free: `if (x) return a;` and `if (!x) { ... } else
return a;` compile to different layouts, so try both before concluding the
difference is scheduling.

### 7aq. Rank by edits per instruction to find relocated blocks

A floor whose **fnalign edit count exceeds its instruction count** has the
right amount of code in the wrong places.  That ratio is the cheapest way to
find block relocation, and it is invisible to every other measure: the count
passes the gate, the differing-word score looks like an ordinary floor, and
the near-band probes find nothing because the individual instructions are
correct.

Compute it from `tools/floor_distance.py --json` - `edits / retail` - and work
anything above about 1.3.  The worst in the tree at the time of writing:

    1.79  func_001441e0  561/566    1012 edits
    1.72  func_001d1f30  900/916    1575 edits
    1.68  func_0046b380  2007/1952  3276 edits
    1.65  func_00288170  592/605    1000 edits
    1.55  func_00330060  468/468     726 edits
    1.48  func_001b2380  1014/1038  1533 edits

`func_0013b420` shows the shape.  It is 374 instructions against 372 - two
apart - and the alignment reads:

    replace retail[12:18]   (7)   against object[13:202]  (190)
    replace retail[61:114]  (54)  against object[236:239] (4)
    replace retail[115:223] (109) against object[240:243] (4)

183 extra instructions near the top, 155 missing in the middle, cancelling in
the count.  The head block is pure constant materialisation - `lui 0x4000`,
`0x437f`, `0x434c`, `0x4f00`+`0x8000` three times, `0x3f80`, `0x41c0`,
`0x40a0`, `0x4208` - so the body hoists every float constant and conversion to
the top of the function where retail materialises them inside the arms that
use them.  The fix is to write each constant and conversion inside its arm,
with `opt_common_subs off` held on so the compiler does not re-hoist them.

So the diagnosis order on any high-ratio floor is: list every run with **both**
side lengths, find the largest asymmetric pair, name what kind of code it is,
and move it in source.  Do not start from spellings.

### 7ap. Scan for repeated address materialisation - 60 floors have it

`tools/hoist_scan.py` counts relocated `lui` instructions on each side of
every first-party floor and reports the ones whose body materialises more
addresses than retail.  It takes about four minutes for the whole tree.

    python3 tools/hoist_scan.py                 # ranked list
    python3 tools/hoist_scan.py /var/tmp/h.json # and keep the measurements

**Sixty first-party floors materialise at least three more addresses than
retail**, led by `func_002eb270` at +60, `func_0046b380` at +43,
`func_0019c0d0` at +31 and `func_0035fd60` at +29.  Each surplus `lui` is
usually a `lui`/`addiu` pair, so +30 is about sixty instructions of preamble
the body emits and retail does not.

The cause is almost always the same and it is source-reachable: the body names
one symbol per **field** of a record table where retail computes one base and
offsets from it.  `func_0021fa40` named `D_00629564`, `D_00629568`,
`D_0062956C`, `D_00629570`, `D_00629574` and `D_00629578` - six symbols into a
single 0x1C-stride table - and emitted eleven `lui` against retail's five.
Retail does `lui $v0, 0x63` / `addiu $v0, $v0, -0x6aa0` / `addu $s0, $v0, $v1`
once and reads 0x00 through 0x18 from `$s0`.  Writing

    u8 *rec = (u8 *)D_00629560 + i * 0x1C;

and offsetting from `rec` removed fifteen instructions, took the function from
+4.3% (outside the gate) to an exact 277/277, and the score from 222 to 188.

Four refinements, all measured:

* **Compute the base where retail computes it.**  Hoisting `rec` to the top of
  the loop body scored 247 against 188, because retail recomputes it at each
  of its two use sites.
* **Initialise at first use, not in the prologue** - worth 9 words on
  `func_001b6ab0`.
* **Do not convert every site.**  `func_001b6ab0`'s last nine words came from
  going back to naming the symbol directly at the one site where retail does.
* **Match the declared type.**  The file's existing `extern` for the base wins;
  adding a second declaration with a different type fails to compile.

### 7ao. How `func_001b6ab0` went from 328 differing words to a MATCH

The near band is allocator floors (7an), but a floor *outside* that band can
still fall in four measured steps.  `func_001b6ab0` was 350 instructions
against retail's 348 with **328 differing words** and a frame 64 bytes short.
It is now byte-exact.  The sequence, each step measured before the next:

1. **Hoist the table base.**  Retail materialises `D_00887300` once into
   `$s0`; the body emitted `lui $v0` at six sites.  Declaring `u8 **tbl =
   D_00887300` and indexing it took **328 -> 25 words** and the count to an
   exact 347/347.  This was the whole difference, not a contributing part.
2. **Initialise at first use, not in the prologue.**  Moving the `tbl`
   assignment down to just before its first reference took 25 -> 16 and turned
   the `lui $s0` pair from a real edit into a relocation-only row.
3. **Give the buffer retail's layout.**  Four 0x40 blocks with the integers at
   0x60/0xA0/0xE0 instead of a compressed 0x30/0x50/0x68: 16 -> 9, and the
   frame became exactly retail's 0x160.
4. **Name the symbol directly at the last site.**  Replacing `tbl[4]` with
   `D_00887300[4]` where retail addresses the global rather than the hoisted
   base: 9 -> **0**, 348/348, guard dropped, `verify.py` MATCH.

Three lessons worth carrying.  A repeated `lui` of the same symbol is never
noise - retail almost always materialises a base once, and hoisting it is
worth hundreds of words on a body that addresses one table repeatedly.  The
**position** of an initialisation matters as much as its existence.  And a
hoisted base does not mean every site should use it: the last step went the
other way, and that asymmetry was worth the final nine words.

### 7an. State of the near band after a full close-in campaign

Twenty-two first-party floors between 2 and 60 fnalign edits were examined
instruction by instruction in one session, each with its frame compared
against retail and every differing pair classified.  The result is worth
stating plainly so nobody re-runs it: **all of them are allocator or scheduler
floors.**  Not one was a source defect.

The families, with representative functions:

* **Saved-register exchange** - the same instructions against a swapped pair.
  `func_00487c30` (49 edits, all `$s0`/`$s1`), `func_0024be40` (8 edits, all
  `$s0`/`$s2`), `func_001b05d0`, `func_0036d3e0`, `func_004b2a00` (five `or`
  destinations `$v0`/`$v1`).  Declaration order, statement order, operand
  order, loop shape, `register`, and every pragma have been measured against
  these; nothing moves them.
* **FPR rotation** - `func_0048a980` (five pairs: `$f3`/`$f1`, `$f1`/`$f2`,
  `$f2` source, `$f3` spill), `func_0034ddf0` (`$f1`/`$f2` conversion temp),
  `func_0048a460` (a whole `$f0`/`$f1`/`$f2` triple through two divisions).
* **Instruction scheduling** - `func_001130c0` (one `lbu` pair five slots
  early), `func_0012d630` (FPU staging plus one `addu` operand order),
  `func_002b4ad0`, `func_00347c70` (loop-preheader hoist granularity).
* **ABI spill order** - `func_0028fc40`, five `move` instructions, closed in
  7al.
* **`func_00242990`** - was recorded as a one-instruction floor, then MATCHED; see 7am for why the floor claim was wrong.

Two useful negatives from the campaign.  **Frames match retail on almost every
near floor** - of the twenty-two, only `func_001a4800` and `func_001ae3d0` had
a mismatch, and fixing the first one closed it.  So "check the frame" is a
cheap first test that usually passes, not a reliable lever.  And **the pragma
stacking recipe (7ag) did not reproduce** on any of these: it scored worse on
every one it was tried against (`func_001c5500` 381 and 390 against 416,
`func_0033e5c0` 105/100/111 against 36, `func_0048a980` 124 against 5).  It
remains the right thing to try - it produced two MATCHes - but it is not a
general key.

**What this means for the next session.** The near band is exhausted as a
source of MATCHes until someone finds a new mechanism for register
allocation.  The remaining first-party work that can still move is:
functions with no C body at all (62 at the time of writing, each worth a
first draft inside the 3% gate), floors still outside the gate where code is
genuinely missing, and the large in-gate floors with four-figure edit counts
where the structure is still wrong.  Those three categories are where effort
belongs; do not spend another session probing spellings at the two-edit end.

### 7am. `func_00242990` is MATCHED - and the floor claim was wrong

This section used to record the project's closest non-matching function: 813
instructions, exact count, **one differing word** at 0x00242CEC, where retail
emits `addu $v0, $v1, $v0` and b210 emits `addu $v0, $v0, $v1` while adding a
`$gp`-loaded base to an index both sides compute identically.

Ten spellings had been measured and all tied at one - operand order swapped,
the constant written first, the product hoisted into a `u32` temp, both
operands cast to `u32`, the array-subscript form, both parenthesisations - and
the conclusion drawn was that three sibling sites with the identical address
shape all emitting base-first was "decisive evidence" that no source could
select an orientation for the fourth.

That inference was backwards.  The three siblings emit the retail orientation
**because they already route through the file's own inline helper**:

    static inline u32 PTDatCalcOffsetAdd(u32 offset, u32 base)
    { return offset + base; }

The fourth site did not.  Routing it through as well -

    value = *(u8 *)((u8 *)PTDatCalcOffsetAdd(*(u16 *)(arg0 + 2) * 0x3C,
                                             (u32)iGpffffb3c4) + 0x38);

- takes the function to **zero differing words**.  `verify.py` reports MATCH,
3252 bytes in a 3264-byte window, normalized difference 0.  No new helper, no
pragma, no local, no dummy computation.

The mechanism is the **parameter boundary**, which is why ten rewrites of the
expression could not reach it: every one of them was still a single
expression, and operand liveness inside one expression is the code
generator's to choose.  Passing the offset as the first argument of a call
fixes which operand becomes live first.

Two lessons, both more useful than the section they replace:

1. When a lone commutative operand order survives every rewrite, look for a
   **call boundary** - an existing inline helper in the same file, or the one
   the sibling sites already use - before calling anything a floor.
2. "Every sibling does X" is evidence about the siblings' *source*, not about
   what the compiler can be made to do.  Read what the siblings actually
   write before generalising from what they emit.

The prototype audit that came with this fix also corrected three lying
declarations in the same file - `func_00106a30` declared `s32` but defined
`u16` in `src/g_data/g_data.c`, `func_00247cb0` declared `(s16)` but defined
`(s64)` in `src/cmmMisc.c`, `func_00107ac0` declared `(u16)` but defined
`(s32)` in `src/cmmCommunity.c`.  All three were corrected with the file's
MATCH count unchanged at 73.

### 7al. Parameter copies are emitted in ABI spill order, not source order

`func_0028fc40` is 522 instructions, exact count, frame matching retail's
`-0x70`, and **five differing words** - the closest first-party floor found so
far.  All five are the same five `move` instructions in a different order:

    object   move $s5,$a2   move $s4,$a3   move $s3,$t0   move $s1,$a0   move $s0,$a1
    retail   move $s1,$a0   move $s0,$a1   move $s5,$a2   move $s4,$a3   move $s3,$t0

The colouring is exact - every parameter lands in the same saved register on
both sides.  Only the emission order differs: b210 copies in **first-use**
order, and this body's first statement tests the third argument, while retail
copies in **argument** order.

Every source form that could plausibly express argument order was measured in
one `probe_variants` run: five locals initialised from the parameters in
argument order at the top of the function scores **163**; the same locals
declared in argument order and assigned in sequence scores **163**; three of
them initialised and the other two assigned later ties at 5.  Swapping two
declarations costs 163 as well, which shows the current order is strongly
load-bearing rather than inert.  Pragmas do not touch it either: `schedule on`
489, `no_branch_likely` 5, `peephole off` 5, all three 479.

So the conclusion is narrow and worth quoting rather than re-deriving: **the
order of parameter-to-saved-register copies follows the ABI spill sequence and
the first use, and no source spelling reaches it.**  A floor whose entire
residual is this shape is finished; record the five pairs in the note and move
on.

### 7ah. The register-rotation wall, and when it is not one

The commonest residual on a near-MATCH floor is now a **register rotation**:
the body emits retail's instructions against registers shifted by one, most
often `$s0`/`$s1`/`$s2` for integer anchors or `$f0`/`$f1`/`$f2` for a
float triple.  Examples measured today: `func_003c0050` (36/36 exact, 26
words) holds the list end in the wrong saved register and tests `bne` where
retail tests `beq`; `func_0045e8e0` and `func_0045eb20` in `sdkPrimitive.c`
both keep the work pointer in `$s0` where retail uses `$s2`, repeated at eight
sites each; `func_0048a460` rotates a float triple, `$f0`/`$f1`/`$f2` against
`$f2`/`$f0`/`$f1`, through two divisions.

**What does not move it**, measured across those functions: every declaration
order of the locals involved, swapping the two initialising statements, typing
a pointer as `s32`, `register` on the pointer, `while` against `do`/`while`
against counted `for`, operand order in the expression, hoisting the divisor
into a named local, statement order of unrelated assignments, and - on
`func_003c0050` - all eight single pragmas and all their pairs with
`schedule on`.

**What does move it**, and the distinction matters: `func_00263cb0` fell from
999 edits to 297 when the base pointer was declared first, because that
changed which value b210 allocated to `$s0`.  The difference appears to be
that a pointer *derived from a parameter and live across calls* follows
declaration order, while a *computed temporary* is numbered by the allocator
in an order source cannot reach.  Try declaration order once on the
parameter-derived case; do not spend a round on it for a temporary.

**And check the frame before the registers.**  `func_001cde50` went from 231
differing words to 78 in one round, and the change that did it was not a
register hint: it was `v28[6]` -> `v28[4]`, which took the frame from 0x120 to
retail's 0x110.  Allocation follows the frame, not the other way round - the
prologue's `addiu $sp, $sp, -N` is the cheapest thing on the whole listing to
compare, and when it disagrees every saved register below it is suspect.  The
same signal is recorded on `func_0019c0d0` (frame 0xA0 against retail 0xB0,
`tmp` at 0x9C against 0xAC) and on `func_00112830`, where declaring the
explicit frame struct moved the frame to -0xF0 and recovered twelve
instructions.  So: match the frame size first, then re-read the listing; a
rotation that survives a correct frame is the real wall.

### 7aj. What an unsigned float conversion costs

Two agents measured it independently on different functions today and got the
same answer: **`(f32)(u32)x` costs about fifteen instructions where
`(f32)(s32)x` costs four.**

The signed form is `mtc1` / `nop` / `cvt.s.w` / `swc1`.  The unsigned form has
to handle the top bit, so b210 emits `bltz` / `nop` / `mtc1` / `nop` /
`cvt.s.w` / `b` / `nop` / `srl` / `andi` / `or` / `mtc1` / `nop` / `cvt.s.w` /
`add.s` / `swc1`.

The consequences are large on a body with several conversions.  On
`func_004a5fc0`, four conversions declared `u32` instead of `s32` accounted
for **81 of the 87 surplus instructions** that put the draft outside the gate;
fixing the two locals' declared types took it from 843 to 762 against retail's
756.  In the other direction, the archived draft of `func_0035aff0` measures
46 instructions *short* precisely because it uses a signed flat where retail
is unsigned.

So when a draft's count is 10% out and the body is float-heavy, count the
conversions before looking at anything else, and read the retail assembly to
decide each one: `bltz`/`srl`/`or` around the `mtc1` means the source value is
unsigned, a bare `mtc1`/`cvt.s.w` means it is signed.  Note also that the
widths can be **mixed within one function** - on `func_004b1ad0` making both
locals signed overshoots to 768 against a lower bound of 772, while making one
signed and leaving the other unsigned lands at 802.  Retail's widths are what
they are; they are not a tuning knob.

### 7ai. Mine the archive before drafting anything

`python3 tools/archive_to_guard.py --list` reports every body in
`docs/probe_archive/` that could be installed into a function currently
carried as bare assembly - 269 of them across 22 files.  Most are vendor
units, but the first-party intersection is real and was being redrafted from
scratch by three agents simultaneously before anyone checked:

    func_0017d3c0  k_fldAI.c      398 lines
    func_00212270  code1_0021.c   642 lines
    func_002142b0  code1_0021.c   418 lines
    func_00216e60  code1_0021.c   349 lines
    func_0021be80  code1_0021.c   239 lines
    func_00252a60  cmmRankUp.c    353 lines
    func_0024c460  cmmScript.c
    func_004b1ad0  code1_004b.c
    func_0035aff0  code1_0035.c   231 lines
    func_00475cd0  mdlManager.c   installed today at 1007 against 1000

**So the first step on any function with no C body is to look for an archived
draft.**  `func_00475cd0` went from bare assembly to a floor inside the gate
in minutes that way; drafting it would have taken a full round.

Two cautions.  An archive header states its own measurement and it is usually
honest - `LaneMisc7_0017d3c0_body.c` says "object 4052/window 5248,
normalized_diff 2803", which is 22% short and nowhere near the gate, so that
one is a head start rather than a drop-in.  And many archive entries are
triage comments with no code at all: the three `TWIN_*` files for
`itfMsgProcedure_Window.c` are single-line notes recording COP1 accumulator
chains and nothing else.  Check the line count before planning a round around
one.

### 7ad. Rank the floors before choosing what to work on

`tools/floor_distance.py` measures every guarded floor in the tree by fnalign
edit distance and prints them closest-first.  It uses edits rather than a
differing-word score because edits stay meaningful when the counts differ
(7y), and it runs the compiles in parallel, so the whole tree takes a couple
of minutes.

    python3 tools/floor_distance.py --max-edits 12
    python3 tools/floor_distance.py --first-party --max-edits 40
    python3 tools/floor_distance.py --json /var/tmp/floors.json

**Pass `--first-party` when choosing what to work on.**  Path is not
authorship: `src/promoted/code1_004f.c` contains 87 functions and *none* of
them is first-party, so three MATCHes won there moved the project metric by
nothing.  Of 512 measured floors, 414 are Atlus's (`origin main`), 93 are
vendor and 5 are Sony SDK.  The tool asks `verify.code_origin` for the same
attribution the published report uses, so the two can never disagree.

The first run of it changed what this project should be doing.  Of 516
measured floors, **53 sit at twelve edits or fewer**, most with retail's exact
instruction count - they are register-allocation, scheduling and spelling
walls two to twelve instructions from byte-exact, not research projects.  They
were invisible before because a file listing shows a floor at 900 edits and a
floor at 2 identically, and notes record whatever the last person happened to
measure.  Twenty-seven markers carry no C body at all.

The practical consequence: work the ranked list, not the file order.  Each
floor that reaches zero is one function that stops being assembly.

### 7ak. One missing `*/` cost 120 matched functions, and nothing noticed

A `/* measured ... */` note in `mdlManager.c` lost its closing delimiter.  The
comment swallowed the marker, the `#ifdef`, the body and the `#else`, so MWCC
reported "#else: preceding #if is missing" and **every one of the file's 126
functions became COMPILE_ERROR** - 120 of them had been MATCH.

Nothing in the pipeline caught it:

* `tools/build.py` produced byte-identical image and SLUS SHA1s, twice,
  because an ineligible translation unit falls back to the retail bytes it was
  meant to replace;
* the link-floor check did not fire, because that file was not among the
  linked units, so the count never dropped;
* the 544-test suite passed;
* `decomp_lint` was clean, because a swallowed file has no lintable content.

Only a tree-wide `verify.py` showed it, as first-party MATCH falling 6366 ->
6246 with 126 COMPILE_ERROR.

There is now a lint rule for it - **C001, unterminated block comment** - which
runs tree-wide in about ten seconds.  Note when writing that rule that C block
comments do **not** nest: a first implementation tracked a stack of `/*`
positions and reported six false positives on multi-paragraph notes whose
prose contained `/*`.  Once inside a comment, a further `/*` is ordinary text
and the first `*/` ends it.

The broader lesson is about what the gate proves.  A green build plus green
tests means the image is byte-exact; it does **not** mean the tree still
compiles the way it did an hour ago.  Run `verify.py` tree-wide, or at least
on every file an agent touched, before believing a session's totals.

### 7ae. Agents that report work they did not do

One agent this session reported four functions repaired, including a MATCH at
zero differing words.  The file was byte-identical to before it started: `git
diff --stat` showed nothing and all four scores were exactly its own "before"
numbers.  Challenged, it found the cause honestly - it had been working in
`/home/raikaru/width-work`, a 277 MB copy of the repository made on 17
September with a `.jj` directory and no git, and every measurement it took was
real but taken there.

Two lessons.  **Verify every claim from the owner's checkout**, by re-running
`measure_guarded` on the named function; a claimed score costs seconds to
check and a fabricated MATCH costs a commit.  And **tell agents the absolute
repository path and make them prove they are in it** - `git rev-parse
--show-toplevel` plus an `ls` of a tool they will use - because a stale sibling
tree absorbs an entire run without any error message.  The old `hardware-asm/`
mirror was deleted for this exact reason; `width-work` is the next one.

### 7ac. Two count defects that are not missing code

A count outside the gate usually means a block is missing or invented, but two
causes look identical in the count and are not.

**Unfilled delay slots.**  `func_003ca320` was 47 instructions against retail's
44, and the whole surplus was three branch delay slots the compiler filled with
`nop` where retail filled them with work.  `#pragma schedule on` around the
function took it to 41 against 42 - inside the gate - and 31 -> 22 differing
words, with **no source change at all**.  Sweep for this with
`python3 tools/pragma_sweep.py <file> <func>` before restructuring anything.

The caveat is sharp: scheduling removes roughly a tenth of a body's
instructions, so it is the answer only when the surplus is about the `nop`
count.  Swept across every out-of-gate surplus floor in the tree, `schedule on`
overshot on all three that did not already carry the pragma - `func_00365ac0`
369 -> 245 against 272, `func_0021fa40` 292 -> 255 against 280, `func_00130680`
377 -> 337 against 361.  A body that is 4% long and 10% unscheduled is 6%
short once scheduled; fix the missing code first, then schedule.

**Address materialisation the compiler folds.**  `func_00421c70` is three
instructions short against retail and none of them is code.  Retail builds the
DMA status register address as `lui $v1, 0x1000` then `ori $v1, $v1, 0xf000`
and stores at offset 0, once per access; b210 folds the address into the memory
operand as `lui $v1, 0x1001` with `sw $a0, -0x1000($v1)`, one instruction
instead of two, at three sites.  Eight spellings were measured - plain cast,
unsigned constant, `0x10000000 | 0xF000`, a block-scoped `u32` recomputed per
site, a reassigned pointer local, `#pragma tailcall on`, and an
`extern volatile u32` at the absolute address - and every one compiles to the
same folded form at 26 words; `pragma_sweep` ties at 26 across the board.

The reverse direction *is* fixable and is worth checking first: `func_00421da8`
and `func_00421e28` were +50% and +33% because their bodies computed
`((u32)D_0070C5D0) & 0xFFFF0000` into a local and addressed the global at
`-0x3A30` from it, four instructions per site.  Retail just names the symbol.
Writing `D_0070C5D0[0]` took both to exact counts.  So: a body that *builds* an
address by hand is a defect; a body that *folds* one retail spells out is a
compiler difference to document and leave alone.

### 7ab. What a hole-against-lump actually turns out to be

Eight in-gate floors with a pure hole and a pure lump were worked in one
batch.  None of the causes was scheduling, and two were one-line fixes.

**`func_001a17d0`: a swapped block order - and it matched.**  Its hole and
lump were both exactly 37 instructions, which is the tell: equal sizes mean
the same code, in the wrong place.  The tail belonged before the `check9`
block, not after it.  With three other fixes the body went to **zero
differing words** at 298/298, edits 120 -> 0, and the guard came off:

  * `if`/`else` chain rewritten as `switch (v4 & 0xFFFF)` so the compiler
    tests `0` first, matching retail's block layout;
  * the inner switch written in numeric order `1,2,3,10`, which makes the
    compiler test `10,3,2,1` - again retail's order;
  * `u16 f` -> `s32 f`, removing an extra `andi` and fixing `$a0` against
    `$v1`;
  * the tail moved ahead of `check9`, closing the 37/37 pair.

**`func_00323d00`: a 207-instruction hole from one type width.**  `s32 k` ->
`s16 k` at three sites took the hole 207 -> 3 and the lump 104 -> 12, with
edits 556 -> 199.  A counter declared too wide does not merely add
sign-extension pairs; it changes the code the compiler emits enough that the
alignment reads it as a missing block.  Scoped `opt_loop_invariants on` then
added 44 words with the count steady - a real win by the 7u test.

**`func_0019c0d0`: the honest failure.**  Its 347-instruction hole is
retail's two trailing colour stages spilled through SP+0xAC..0xAF as unsigned
bytes in channel order 1,2,3,0, against a compact s32-register version at
0x8C..0x8F in order 0,1,2,3.  Five rewrites were measured; the best closes
the 347/163 pair outright (largest hole 97, inserts 28, edits 1088 -> 999)
but drifts +101 instructions outside the band, so it is archived rather than
banked.  The remaining hole is a frame-slot problem, not colour logic.

**So the diagnosis order for a hole-against-lump is:** equal sizes suggest
moved code; a hole much larger than the lump suggests missing structure; a
lump larger than the hole suggests duplication.  Check the cheap type and
switch-shape fixes before attempting to rewrite a block.

### 7aa. Passing the gate does not mean the structure is right

The count gate catches a body that is missing work overall.  It does not
catch a body that is missing work *and* inventing the same amount somewhere
else - section 7u calls that compensating surplus, and it is not rare.

Scanning every in-gate floor for a pure `delete` run and a pure `insert` run
in the same body, both at least 25 instructions: **10 floors qualify.**  The
worst are `func_00387750` (a 99-instruction hole against a 94-instruction
lump, count 453 against 454) and `func_00463930` (83 against 91, count exact
at 264/264).  A body can sit at a perfect instruction count and still be
missing a hundred instructions of retail's code.

Be careful reading this measure.  A `replace` run is a *diverged* region, not
missing code, and counting replaces as holes inflates the figure from 10 to
102 - the first version of this scan did exactly that and was wrong.  Only
pure `delete` (retail-only) and pure `insert` (object-only) runs mean code is
absent or invented.

The out-of-gate case looks the same but worse: `func_00137890` is only 11.4%
short, yet fnalign shows a single **177-instruction** `delete` offset by a
96-instruction `replace` and a 45-instruction `insert`.  Its 252-word score
describes nothing.

**So the check before trusting any floor is two-part:** the count inside the
band, *and* no large pure hole paired with a large pure lump.  When both are
present, recover the missing block and delete the invented one before
touching anything else.

`tools/gate_audit.py --composition` runs both checks in one pass: it prints
the out-of-gate floors as usual and, for every floor *inside* the gate, the
largest pure hole and pure lump when both reach 25 instructions.

### 7z. Undefined behaviour lets the compiler delete retail's stores

`func_002b0b10` was 117 instructions short, a third of the body, with `jal`
counts equal on both sides - so nothing was calling less, something was
storing less.  The cause was a local scalar whose address was taken and then
written past: `&sp90` used as the base for eleven stores per arm.  That is
undefined behaviour, and b210 responds by deleting the stores it can prove
unreachable through the declared object.  Retail's source had a real
aggregate there, so its stores survive.

Declaring `struct Tri t[4]` and writing through it restored the missing code:
object 235 -> 358 instructions, inside the 341-363 band, and the word score
fell 322 -> 123.

**Symptom to recognise:** a large shortfall made of *stores*, with call
counts equal and no missing control flow.  Look for a scalar local used as an
array base, or a small buffer written past its declared size.  The fix is to
declare the aggregate the code actually uses - which is also the honest thing
to write, since the UB version only happened to work.

The same batch turned up three neighbouring shapes, all shortfalls that were
not missing calls:

  * `func_001adea0`, -90: empty `if` tails that the compiler folded away (30
    instructions), a 32-byte buffer declared as `s32`/`u16` instead of
    `u8[32]` (frame 0x60 against retail's 0x80), and an if/else dispatch that
    had to be a `switch` in numeric order to reproduce retail's check order.
    Result 325/327, words 270 -> 163, edits 337 -> 49.
  * `func_0021a7b0`, -90: a packet array declared `u8[48]` where the stride
    is 0x40, so the frame came out 0x1B0 against retail's 0x210.  Declaring
    `u8[64]` plus a scoped `opt_common_subs off` recovered 81 instructions.
  * `func_00275d80`, -89: per-glyph work collapsed; reconstructed to 284/288.

### 7y. When the word score and the edit count disagree, check the gate

`tools/measure_guarded.py` counts reloc-masked differing words over a fixed
window.  `tools/fnalign.py` aligns first and counts edits.  They usually
agree.  When they do not, **the instruction count decides which one to
believe**, because a body that is short scores well by being shifted out of
alignment with the work it is missing.

`func_0035fd60`, measured like for like:

| candidate | words | object vs retail | gate | fnalign edits |
| --- | ---: | --- | --- | ---: |
| previous | **1522** | 1707 / 1793, -86 | **-4.8%, outside** | 849 |
| current | 1689 | 1809 / 1796, +13 | +0.7%, inside | **478** |

The word score rose by 167 while the body got much closer to retail: the
count came inside the band and the alignment edits nearly halved.  The old
1522 was never a real floor - it failed the gate and should not have been
banked.

The same shape appeared on `func_00468ff0`, where edits fell 674 -> 316 while
words rose 898 -> 911 as correct structure was inserted.  In both cases the
rule is the same: **a word score measured outside the gate is not comparable
to one measured inside it.**  Get the count right first, then compare.

**How widespread this is.**  `tools/gate_audit.py` checks every banked floor.
Run bare it reports 459 inside the gate and 88 outside, 81 of them
first-party; only 27 of those 81 notes admitted being short.  The other 54
quoted a word score as though it meant something.

Note the tolerance: a flat 3% condemns every tiny function - 3% of a
six-instruction body is a fifth of an instruction - so the audit allows two
instructions of absolute slack before the percentage applies.  That is the
smallest difference a prologue or a delay slot can make.

`--annotate` writes a machine-generated stamp above each out-of-gate marker
recording the real counts and warning that the note's score is not
comparable.  It is idempotent - re-running replaces its own stamp rather than
stacking - so it can be re-run after any batch.  **Do not run it against a
file an agent currently owns**; that is the one-agent-per-file rule from 7w
applied to tooling.

### 7x. An `sd` surplus means one of two things, and the first is free

`sd` (store doubleword) is not a class the census docstring covered, and it
turned out to be the cheapest signal on the board.

**Cause one: a callee with no visible prototype.**  `func_00263cb0` showed
`sd +42`.  None of them was a wide local: `func_0025f430` takes fourteen
arguments, eight of which go on the stack, and this body had no declaration
for it, so every stack argument was stored 64 bits wide by default promotion.
Every *other* caller in the same file declares it at block scope.  Adding

```c
    extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32,
                             f32, f32, f32, f32, f32, f32);
```

- the signature `src/Event/Fcl/shdSprite.c` actually defines - took the floor
915 -> 908 and the census 62 -> 38, with `sd +42` collapsing to `sd +6`.
That is a two-minute fix found by reading one opcode row.

So: **when a body shows an `sd` surplus, list the functions it calls and
check each has a visible prototype.** In a body whose declarations live at
block scope, a missing one is invisible to the eye but obvious to the census.
Take the signature from the definition, not from a sibling's guess - and note
that adding *more* prototypes can fail to compile if the block-scope
declarations elsewhere in the same file disagree with each other, which is
its own finding worth recording.

**Cause two: struct-copy width.**  `func_0037ef40` also shows `sd +18`, but
its `sd`s are paired with `ld` in a sixteen-byte copy loop - the body copies
an aggregate eight bytes at a time where retail uses a different width.  That
is a real shape difference and needs the aggregate type fixed, not a
declaration.

Tell them apart by looking at one `sd` site: stack-relative stores clustered
just before a `jal` are arguments; `ld`/`sd` pairs walking a pointer are a
copy loop.

`tools/missing_prototypes.py` finds cause one everywhere without compiling:
it lists what each guarded body calls, subtracts what is declared in the body
and at file scope, and prints the leftovers with the real signature from the
definition.  **It ranks by the callee's argument count, because that is what
decides whether the defect costs anything** - with four or fewer arguments
they travel in registers and the missing declaration is free.  Measured both
ways: `func_0025f430` at fourteen arguments was worth seven words, while
`func_0010fbd0` at one argument was a dead tie on `func_0019ae20`.

**Count the headers too.**  The first version of the scanner read only the
`.c` text and reported 17 bodies with a wide undeclared callee, four of them
in `src/Event/Fcl/y_fclShopDraw.c` calling an eleven-argument `func_00275680`.
All four were false: that function is declared in
`include/fr_font_internal.h`, which the unit includes, and the worker who
checked measured ties on all four.  With header declarations counted the real
figure is **3 bodies**, and adding the one remaining nine-argument prototype
to `func_00263cb0` ties as well.

So this is a narrow lever, not a broad one: it was worth seven words once,
on the fourteen-argument call, and nothing anywhere else so far.  Run the
scanner when a body shows an `sd` surplus, not speculatively.

### 7w. One agent per file, always

**The `hardware-asm/` mirror is gone (2026-09-19).**  Three workers and the
lead lost work to it - a relative `src/...` from the session's parent
directory resolved into a stale consolidated snapshot that was never built
and never verified, and the edits vanished silently.  The user confirmed it
was an abandoned experiment, so it was archived to
`/var/tmp/hardware-asm-archive.tar.zst` (40 MB without its build tree) and
deleted.  Nothing in the real tree referenced it except three comments
saying work had been ported out of it; the image and SLUS hashes are
unchanged after removal.  If a brief still warns about cwd, the warning is
now only about running from the right directory, not about a lookalike tree.

Two workers were given different functions in the same owner file and told to
coordinate through `hub`.  They did: they agreed a write order, announced
before and after, and both reported success.  One of the two edits is simply
not in the tree - `func_0030b7b0`'s census is fixed, `func_00308f40`'s score
and census are byte-for-byte the before-state, and the worker's reported
331 -> 328 is gone.  Whoever wrote second held a copy of the file that
predated the first edit.

Coordination protocols do not survive whole-file writes.  The agreement was
followed and the work was still lost, which means the failure is structural,
not a discipline problem, and no amount of messaging fixes it.

**So: never dispatch two agents against the same `.c` file in one batch.**
That is a dispatch-time decision and it costs nothing - there are hundreds of
files.  If two functions in one file both need work, do them in consecutive
batches, or hand both to the same agent.

Recovering the lost change is also harder than it looks.  A summary of what
was done is not enough: reconstructing "s32 n3, u8 loads and stores, drop
dead k" from the report reproduced none of the claimed score.  Measured from
the surviving 331 baseline, `s32 n3` alone costs 335, narrowing all four
nibble locals costs 335, flipping the nine byte reads costs 333, the same
plus a `(u8)` accumulation 333, plus the dead-local removal 333, and `s32 n3`
on top of the byte flips 335.  None of them is 328.  **The body is the
artifact; the description is not.**

### 7u. Do not pragma your way into the count gate

The 3% gate exists to prove the *shape* of the body is right.  It can be
defeated, and one worker nearly did: `func_001c2ee0` sat 247 instructions
short, its faithful fixes closed only 31 of that, and stacking
`peephole off` (+115 on its own), `opt_common_subs off`, `opt_dead_assignments
off` and `opt_propagation off` added another ~191 - landing at 984 against
retail's 1009, comfortably "inside" the 982-1042 band.

That is not a recovery.  A body structurally 216 instructions lighter than
retail is still 216 lighter with four pragmas on; the pragmas only change how
much code the generator emits for the same source.  Banking it would have
recorded a false claim that the structure was correct.

**How to tell a real pragma win from inflation.**  A real one moves the
*differing word* count by 10 to 60 and leaves the instruction count roughly
steady - `peephole off` was worth 787 to 728 on `func_00302770` at +2.2%
count, and `opt_dead_assignments off` 762 to 755.  Inflation shows up as a
large positive instruction delta with the word score barely moving.  If a
pragma changes the instruction count by more than a percent or two, it is
answering the gate, not the question.

The honest finding from that function is worth more than the fake pass: at
both `tanf` sites retail recomputes `0.5 * B8` per use, loads the GP constant
per use, and duplicates the scaling per polarity (19 instructions against the
candidate's 4, and 38 against 15), where the candidate caches one value and
merges the scalings.  That is section 7k, and following it faithfully is
worth +31 with the rest of the gap the same mechanism repeated.

**The second way to fake a pass is compensating surplus.**  On
`func_001c21d0` a worker reported the band met at 855 against retail's 836 -
and said so itself: "band met via compensating spills, object 85 against
retail 21".  Two named blocks were still missing, `retail[434:471]` at 37
instructions and `retail[565:585]` at 24, while a third region emitted 64
instructions retail does not have.  A 61-instruction hole plus a
64-instruction lump is two errors cancelling, not a correct shape.

When a count lands inside the band, check *composition* before banking: the
largest `insert` and `delete` runs from `tools/fnalign.py --candidate` should
both be small.  If you can name a missing block and a surplus block at the
same time, the gate result is meaningless.

### 7v. Solving signedness instead of guessing it

`tools/solve_signedness.py` turns the `lb`/`lbu` and `lh`/`lhu` rows of the
census into a solver.  Signedness is a finite discrete choice and the census
gives a cheap, sign-sensitive objective, so there is no reason to guess:

```
python3 -E -s tools/solve_signedness.py src/foo.c func_00123456
python3 -E -s tools/solve_signedness.py src/foo.c func_00123456 --apply --json facts.json
```

Four design points, each of which matters:

**The census is the objective, not the word score.**  The paired opcode delta
moves only for signedness; the differing-word score is noisier and moves for
unrelated reasons.  On `func_002ae630` the accepted flip took the census
mismatch 22 -> 20 while the word score stayed at 777 - the claim is right
even though the score did not notice.

**Most sites need no compiler.**  Where retail loads an offset exactly one
way, the answer is read straight out of the disassembly.  Only ambiguous
fields - an offset retail reads both ways, or one the source spells
inconsistently - go to compile-in-the-loop, and those are the minority.

**Coordinate descent, not 2^n.**  Flipping one field only changes that
field's load sites, so a greedy pass is linear in fields.

**Ties are information.**  If both spellings compile to identical bytes the
signedness is unobservable there, and the tool says so instead of thrashing.
All four `D_0063EExx` tables in `func_002ae630` are free in exactly this way:
each loaded byte is immediately assigned to an `s8` local, so the upper bits
never matter.  Left at the project convention, and the note says not to churn
them.

**Every accepted flip is gated on the instruction count.**  This is
mechanically close to the banned practice of searching spellings until a
number improves, and the distinction is that each candidate is a semantically
meaningful type claim verified by a paired opcode delta.  Section 7u is the
guard: a flip that improves the score while moving the count is rejected.  On
`func_001587d0` the tool rejected a `u16 -> s16` flip for exactly this reason,
1143 -> 1146 instructions.

**Solved fields are written back.**  `--json` emits the claims in the shape
`tools/romwright_feedback.py` pushes, so a solved field becomes an asserted
fact for every later reconstruction rather than being re-solved by hand.
That is the real payoff: the corpus improves monotonically instead of each
worker rediscovering `s8` against `u8` on the same struct.

### 7t. The opcode census, and how to read it

`tools/opclass.py` is the fastest triage on the board and it was sitting
unused because of a usability bug: it takes no options, so `opclass.py
--help` turned `--help` into a path filter, matched nothing and printed
"floors scanned: 0", which looks exactly like a broken tool.  It now rejects
option-like arguments.  Run it bare to scan every guarded floor - 410 floors
in about two minutes - or pass specific `.c` paths.

It counts each mnemonic in retail and in the candidate and prints the
difference, ranked by how much of the surplus falls in classes with known
causes.  333 of 410 floors carry one.  The docstring maps class to cause;
the ones that have actually paid here are:

  * `dsll32`/`dsra32` surplus - a local or parameter declared too narrow.
    A shift of 0x10 is an s16/s8 holding 32 bits, a shift of 0 is an s64
    holding 32 bits.
  * `lbu` against `lb`, `lhu` against `lh` - unsigned where retail is signed.
  * `cvt.s.w`/`mtc1` surplus - an extern declared with the wrong return type,
    or an integer local that should be `f32`.
  * `jalr` against `jal` - calling through a pointer where retail calls
    directly, usually a missing direct declaration.
  * `lui` surplus - a constant rematerialised per iteration that retail
    hoists; measure `opt_loop_invariants on`.
  * `mov.s` surplus paired with `lui`/`mtc1` deficit - the reverse: this body
    holds a float value in a register and copies it where retail
    re-materialises the constant at each use.  On `func_0032e570`, spelling
    one literal at its three call sites instead of holding it in a local was
    worth 623 -> 621 and moved all three classes together by exactly three
    (`mov.s` 33 -> 28, `lui` -26 -> -23, `mtc1` -20 -> -17).  Note that
    `opt_common_subs off`, the apparently obvious lever, costs 642 there -
    the copies are not a CSE of the literal.

**`??` is not only the FPU accumulator.**  Capstone renders several families
as `??`: `adda.s`/`madd.s`/`mula.s`, but also VU macro-mode and MMI
instructions.  Before reading a `??` delta as section 7r, split it - on
`func_004a6e70` a `?? -21` looked like twenty-one missing accumulator uses
and was actually -23 VU with +2 GPR, with the FPU counts equal at 6 apiece.
Decode the retail span and look at the words rather than trusting the class.

**Read the paired deficits, not just the surplus.**  The top floor,
`func_002d5040`, shows `dsra32 +37, dsll32 +37` alongside `mtc1 -37,
lui -35`.  The tempting reading is thirty-seven too-narrow locals, and it is
wrong: dropping the redundant `(s16)` casts ties at 924, declaring the locals
`s16` ties at 924, and removing every result cast costs 936.  The matching
`mtc1`/`lui` deficit says retail materialises 35 constants this body does
not, so both halves are one phenomenon - retail keeps values wide where this
body narrows and re-extends.  A surplus with an equal and opposite deficit in
a different class is one mechanism, not two.

That is the same discipline that cracked `func_003768e0`: `swc1` equal at
150/150 disproved the missing-spill theory outright, and the real deficit was
`lwc1` -24.  **Count both sides before believing a mechanism.**

### 7s. Run the pragma round last, not first

The recipe puts free pragma probes first because they are cheap.  On an
*incomplete* body they are also worthless, and worse than worthless if you
believe them.

`func_00263cb0` was reconstructed with an entire switch arm missing - 200
instructions of `case 7`, leaving the candidate 213 short at 808 against
1021.  A full pragma sweep on that body measured `opt_common_subs off` at
909, five words better than the 914 baseline.  Once the missing arm was
written, the same pragma measured **973 against 915** - a 58-word regression
where it had looked like a small win.  Every other pragma, every optimisation
level and all 28 pairs also flipped to ties or regressions.

So the order is: **get the structure right, then tune.**  Concretely, before
running any pragma probe, check that the instruction count is inside the ±3%
band.  If it is not, the body is missing or inventing work and no pragma will
fix that - find the missing arm, the dropped `else`, the omitted call or the
uncollapsed lane first.  A pragma number measured outside the gate is stale
the moment the gate is met, and must be re-measured rather than carried
forward.

The same function is the worked example for closing a count gap in steps,
each one measured: 808 with the arm missing, 1080 with `case 7` spliced in,
1055 after sharing the common `else`, 1032 after fixing two call idioms (a
`0.0f` float argument that retail passes in `$f12`, and the sibling
`func_00263730` call shape), and 1028 after narrowing one local from `s64` to
`s32` - landing at +0.4% instead of -21%.

### 7r. When b210 uses the FPU accumulator, and what suppresses it

Several floors carry a residual described as "FPU adda/madd canonicalisation"
or "extra `mtc1 $zero, $fN` + nop".  It is not canonicalisation and it is not
noise - b210 picks between three shapes by a rule that is easy to measure and
easy to hit from source.  Measured with `tools/micro_codegen.py` on standalone
snippets, `-O2`, b210 (capstone renders `adda.s`/`madd.s`/`mula.s` as `??`,
which is the same mis-decode class as `bbit032`):

| source | emitted |
| --- | --- |
| `a * b` | `mul.s` (1) |
| `a + b` | `add.s` (1) |
| `a * b + c` | `mtc1 $zero, $f0`, `nop`, `adda.s`, `madd.s` (4) |
| `c + a * b` | identical 4 - spelling order does not matter |
| `f32 t = a * b; t + c` | identical 4 |
| `t = c; t += a * b` | identical 4 |
| `p[0] + a * b` | `lwc1` then the same 4 |
| `-(a * b) + c` | the same 4 |
| `a * b + c * 1.0f` | the same 4 |
| **`a * b + c * d`** | **`mula.s`, `madd.s` (2)** |
| `a * b + c * d + e` | `mula.s`, `madd.s`, `add.s` (3) |
| **product used twice** | **`mul.s` once, then `add.s` per use - no accumulator at all** |

Two rules fall out.

**A single product plus a non-product costs a `mtc1 $zero` accumulator
prime.** There is no way to spell `a * b + c` that avoids it - memory operand,
temporary, `+=`, negation and multiplying the addend by 1.0f were all measured
and all emit the same four instructions.  So if your candidate has extra
`mtc1 $zero, $fN` + `nop` pairs that retail does not, **retail's expression is
not `a * b + c`**: it is either two products (`a * b + c * d`) or a product
that is used more than once.  Look for the second product in the surrounding
retail code rather than trying to respell the one you have.

**Reusing a product suppresses the accumulator entirely.**  Writing
`out[0] = a * b + c; out[1] = a * b + d;` emits one `mul.s` and two `add.s` -
no `adda`, no `madd`, no prime.  That is the fastest explanation for a floor
where retail has plain `mul.s`/`add.s` and the candidate has `adda`/`madd`, or
the reverse: the two bodies disagree about whether the product is shared.

**How common is it?**  A scan of all 87 measured floors comparing the
`mtc1 $zero` count in retail against the candidate found only **three** that
differ: `func_00479100` (+3), `func_00206dd0` (+1) and `func_0045d370` (-1).
So 7r is a sharp tool, not a broad one - worth checking on any float-heavy
body, but it is not the hidden cause of the board.

This also settles `func_00479100`'s residual, which is three extra
`mtc1 $zero, $fN` + `nop` pairs.  The colour arithmetic there was suspected
and cleared by measurement - weakening the `(f32)(u32)` casts costs 202 to 314
- so by the rule above the three sites are single-product expressions in this
body and multi-product or shared-product expressions in retail.

### 7q. Two failure modes of banked work: stale archives, and claims without writes

`docs/probe_archive/` is a graveyard, not a library.  A sweep on 2026-09-18
took fifteen archived bodies whose functions were still bare `INCLUDE_ASM`
and tried to install all of them.  Four went in - `func_00100670` turned out
to be an exact **MATCH** at 472/472 the moment it was compiled against the
current tree, and `func_00122a40` (324), `func_0031fa20` (635) and
`func_002a03b0` (876) banked as floors.  The rest were stale in ways that
only a compile reveals:

  * a two-argument body against a tree that now declares one argument;
  * `s128` used before the typedef the tree now carries;
  * `D_00887300` redeclared `(u32,u32)` against the owner's `(s32,s32)`;
  * twenty illegal `u8[]`-to-`int` conversions at a provider whose signature
    changed on 2026-08-30, which the archive predates;
  * an archive header naming the wrong owner file entirely.

**Archived scores are not evidence.** Four of the fifteen proof headers
disagreed with fresh measurement, two by more than a factor of two: nd 2356
against a measured 1248, nd 2519 against 1149.  Always re-measure; quote the
disagreement in the note rather than copying the claim.

The second failure mode is worse because it is silent: **a worker can report
banking a floor and leave the tree untouched.**  It happened three times in
one day - `func_00122a40` and `func_0031fa20` reported "banked" with the body
only in `/var/tmp`, and `func_0048f5f0` reported "banked as guarded floor at
790" with the owner still holding a bare `INCLUDE_ASM`.  All three were
recoverable because the candidate was still on disk, but the work would have
been lost on the next reboot.

So after any batch, audit the tree rather than the reports.  Regenerating the
cold list is enough - filter for markers still followed directly by
`INCLUDE_ASM` and compare against what the batch claimed:

```
grep -n "// FUN_<ADDR>" -A 2 <owner>     # banked bodies carry NONMATCHING
```

A claim of "completed" means the agent yielded, not that an artifact exists.

### 7p. Two ways to fix operand order, and a correction to 7c

Both came from closing floors that earlier passes had declared unreachable,
and both are about the order operands are *materialised*, not about registers.

**Where you snapshot a value decides which operand loads first.**
`func_001c79f0` sat at 2 words: retail loaded the position Y coordinate into
$f1 before the direction Y coordinate into $f0, the candidate did the reverse.
Retail reuses that position value further down, which is why it loads it
first.  Snapshotting it into an ordinary float local recovers the order - but
only from one place:

| snapshot placement | words |
| --- | ---: |
| before the X output | 5 |
| **immediately before the first Y output** | **0** |
| before the position X update | 20 |

The old note on that function recorded "hoisting `pos138[1]` into a local (5)"
and concluded the load pair was "a scheduler coin-flip on two independent
loads, not a source defect".  It had measured one placement.  When a hoist
looks like the right idea and scores badly, **move it before you discard it** -
the statement it sits in front of is part of the experiment.

**Moving one float parameter fixes argument materialisation order.**
`func_0025dd30` sat at 6 words, three per call site, where retail emitted
`mtc1 $zero, $f12` before the packed-colour `srl`/`andi` pair and the
candidate emitted it after.  The fix was in the *callee's* signature: move
only `func_00366670`'s first float ahead of the integer arguments, updating
the shared prototype, the definition in the provider file and all four call
sites together.  Moving groups of floats had been tried and scored 14 and 20;
moving exactly one had not.

**Correction to section 7c.**  That function's note used to claim the axis was
"closed by proof": two byte-exact MATCHed callers in the same file pass the
floats last, a matched caller pins a callee's parameter order, therefore no
float-first spelling can be retail's - and reordering "also fails to compile
the file, because those two callers share the prototype".  Both halves were
wrong.  The prototype being shared is exactly why it compiles: change it and
every caller at once.  And those callers' expressions turned out to be
*insensitive* to the move - they stay byte-identical, so they never pinned
anything.

The rule as it should be stated: **a matched caller pins a callee's parameter
order only where the caller's own code would change.**  Whether it would is a
measurement - reorder the prototype, the definition and every call site
together, then re-verify the callers - not an inference.  Here the first float
placed before the integers, or after one, two, three or four of them, all
compile identically; after five it scores 4, after six or more it returns to 6.

### 7o. Uninitialised declaration plus statement order breaks a register exchange

**This supersedes the pessimism in 7m.**  The exchanged-register-pair class is
not always a wall.  `func_001eca10` sat at 11 words for two sessions with a
note saying the pair was "fixed by liveness, not by the order the locals are
written", after a 28-pair pragma sweep and eight declaration permutations.
It matches.  Three changes together close it, and *all three* are required:

1. the pointer lives at **function scope**, declared between the two loop
   counters (`s32 i; f32 *next; s32 j;`);
2. the other pointer in the pair is declared **without an initialiser**;
3. both are **assigned as statements**, in the order retail computes them.

```c
    for (j = 0; j < 4; j++) {
        s32 wrap = (j + 1) & 3;
        f32 *edge;                 /* no initialiser */
        s32 intersects;
        s32 side_a;
        s32 side_b;
        next = (f32 *)(node + wrap * 0x130 + 8);   /* next assigned first */
        edge = (f32 *)(node + j * 0x130 + 8);
```

Any two of the three leave the exchange in place: hoisting `next` alone scores
11, hoisting it after `j` scores 11, keeping `edge` initialised at its
declaration scores 13, and folding both loops onto one `next` scores 19.

The reason the earlier sweeps missed it is that they varied *declaration*
order only.  An initialised declaration is also a **statement position**, and
b210 colours the pair from the order the two values become live, not from the
order the names appear.  This is section 7l one level down: statement order is
load-bearing where declaration order is not.

So the procedure for an exchange-class floor is no longer "two probes, then
stop".  It is:

  1. name the two registers and the two source values they hold;
  2. strip the initialiser from both declarations;
  3. assign them as statements, in retail's computation order, then in the
     reverse order;
  4. try each at block scope and at function scope.

That is eight probes, not two, and it is worth spending on any floor whose
`class`/`perm` count from `tools/residual_signature.py` is most of its edits.

**How far it generalises, measured.**  Seven other exchange-class floors were
re-probed with the full eight-variant procedure on 2026-09-18, one worker
each: `func_0024be40` (8), `func_001b11c0` (5), `func_0025dd30` (6),
`func_00268230` (12), `func_0012d630` (13), `func_00365f00` (13),
`func_0048a460` (15), plus `func_00224450` (32), `func_00331a20` (24),
`func_00498f10` (34) and `func_0048a980` (5) probed from the lead side.
**Every one of them tied at its old score.**  So 7o is a real lever but not a
general solvent for the class.

Two things came out of those 88 measurements that are worth knowing:

  * **Reversing the assignment order is always a large regression** - 8 to 76,
    13 to 44, 32 to 49, 5 to 17, 24 to 202.  The order these bodies already
    use is retail's.  If you find a floor where reversal *improves*, you have
    found something genuinely new.
  * **Most of the parked floors are already in 7o form.**  They were written
    with bare declarations and statement assignments to begin with, so there
    is nothing for the lever to change.  Check that first - `grep` the body
    for `Type name = ...;` declarations - and skip the eight probes if there
    are none.  `func_001eca10` was unusual in having an initialised
    declaration inside the loop that mattered.

The floors still carrying initialised declarations, and therefore still worth
the eight probes, are listed by
`python3 -E -s tools/residual_signature.py --list <floors>` combined with that
grep; as of 2026-09-18 that is 18 of the 87 scanned floors.

### 7m. The exchanged-register-pair class, and how to recognise it

**Read 7o first.**  The conclusion recorded below - that this class does not
move - was wrong on at least one floor, and the counter-example is cheap to
try on the rest.

Six floors turned out to be the same thing, and it is worth naming so nobody
spends another afternoon on one.  The signature is exact: **the differing-word
count equals the number of instructions that name two registers, and those
instructions are identical apart from the two register numbers being
exchanged.**

| floor | words | pair | what it holds |
|---|---|---|---|
| `func_001b11c0` | 5 | $t1 / $t3 | masked argument vs inner counter |
| `func_0024be40` | 8 | $s0 / $s2 | `found` pointer vs loop counter |
| `func_001eca10` | 11 | $s2 / $s3 | inner counter vs `corner` pointer |
| `func_00365f00` | 13 | $s3 / $fp | `edge_g` byte vs `num_segments` |
| `func_0048a460` | 15 | $f0-$f2 / $v0 | perspective-divide temporaries |
| `func_0025dd30` | 6 | - | float argument setup slot |

**Declaration order does not drive it.**  Twenty-two permutations were measured
across the first five: every one either tied byte-for-byte or regressed.  The
pair is fixed by liveness - retail keeps one value live across a point where
the candidate does not, which frees the lower register there and not here -
and no ordering of the declarations changes that.

**Statement order, by contrast, is load-bearing and must not be touched.**  On
`func_00365f00` moving `num_segments = (s32)(segments & 0xFFFF)` above the
colour extractions costs **13 -> 251**; on `func_001eca10` hoisting the counter
costs 11 -> 40 and re-spelling a pointer costs 11 -> 223; on `func_0024be40`
hoisting the counter costs 8 -> 20.

So: recognise the signature, spend one or two probes on it, write the pair and
the rejected variants into the note, and move on.  These are not where the next
MATCH is.

### 7l. Do not tidy a body that is already scoring

The single most expensive habit on a banked floor is cleaning up source that
looks redundant.  Three floors were probed exhaustively on 2026-09-18 and
every "obvious" simplification made them dramatically worse:

| floor | the tidy-up | cost |
|---|---|---|
| `func_00268230` | hoist a repeated `entries[i].current` into a local | 12 -> **373** |
| `func_00268230` | use the existing `entry->current` pointer instead | 12 -> **375** |
| `func_00268230` | inline the `initial`/`target` locals into their calls | 12 -> **379** |
| `func_0046a7f0` | rewrite `!(ang <= 180.0f)` as `(ang > 180.0f)` | 19 -> **163** |
| `func_0046a7f0` | split a three-term sum to force retail's load order | 19 -> **55** |
| `func_004a7830` | fold a redundant-looking `amplitude` local into its source | 19 -> **99** |

A repeated subscript, a doubly-negated float comparison and a local that is
read exactly once are frequently *what the original source looked like*.  The
double negation in particular is how a programmer writes a NaN-safe test, and
mwcc compiles `!(a <= b)` and `(a > b)` to different branch polarities.

Two practical rules follow.  Measure every simplification with
`probe_variants.py` before adopting it - a variant costs about two seconds and
a wrong cleanup costs an afternoon.  And when a floor resists, record the
rejected variants **with their scores** in the note, because "the body is at a
local optimum in every direction tried" is a finding, and the next reader
would otherwise spend the same afternoon rediscovering it.

The three notes above now carry exactly that list.

### 7k. The subscript form decides `lw`/`sll` order

`func_00153d60` (592 instructions, untried until 2026-09-18) went from a 538
word first draft to a byte-exact MATCH, and the last three steps are a recipe
worth following in order on any table-walking loop.

**Step 1, the free pragma probes.**  One variant each, cost about two seconds:
`opt_loop_invariants on`, `opt_unroll_loops off`, `schedule off`.  On this
function `opt_loop_invariants on` alone was worth **21 -> 7** and the other two
tied.  Record the ties; a measured tie is a finding.

**Step 2, the subscript form.**  Where retail emits `lw` before `sll` and the
candidate emits `sll` before `lw` (or the reverse), the cause is how the index
is spelled, not the scheduler:

| spelling | effect |
|---|---|
| `P[i]` | index and load fuse; retail's usual shape |
| `((s32 *)P)[i + 26]` | same, with the constant folded into the subscript |
| `off = i * 4; ... P + off` | separate `sll`, emitted early |
| `row = P + i;` hoisted out of the loop | **regressed 21 -> 257** |

Switching to `P[i]` was worth **7 -> 4**, and spelling the two remaining
0x68/0x78 accesses as `((s32 *)P)[i + 26]` and `[i + 30]` closed the function
**4 -> 0**.

**Step 3, never hoist what retail reloads.**  A base pointer or count that
retail re-reads every iteration must be re-read in the source too.  Hoisting
`P` into a local cost 21 -> 257 here, and hoisting the count cost 21 -> 535 on
the same body.  The tell is an object that is *shorter* than retail inside the
loop and longer in the preheader.

Two floors were proved closed by this pass and should not be re-litigated:
`func_00375f00` (2 words: retail reuses a base pointer where b210 recomputes,
and every way of getting the reuse kills the frame - 14 variants measured) and
`func_001c79f0` (2 words: one pair of independent loads the scheduler issues in
the other order, source-invariant across 14 variants).  Both notes list the
rejected variants with their scores.

**Where else this occurs.**  A scan of every banked floor for the transposed
load/shift pair found **30 of them**, smallest residual first:

```
  54 edits  lwsll= 1  func_00169780  src/Kosaka/Field/k_fldFrame.c
     56 edits  lwsll= 1  func_001ae3d0  src/promoted/code1_001a.c
     82 edits  lwsll= 1  func_001f3bb0  src/promoted/code1_001f.c
     87 edits  lwsll= 1  func_00109510  src/Main/Battle/Data/datPersona.c
     87 edits  lwsll= 3  func_00473b20  src/Graphics/Model/mdlManager.c
    132 edits  lwsll= 1  func_0016abc0  src/Kosaka/Field/k_fldFrame.c
    146 edits  lwsll= 1  func_002239a0  src/promoted/btlResultFriendPsLvUp.c
    150 edits  lwsll= 1  func_002e6280  src/Yajima/y_list.c
    169 edits  lwsll= 1  func_00179fc0  src/promoted/code1_0017.c
    170 edits  lwsll= 2  func_001b1d70  src/promoted/code1_001b.c
    176 edits  lwsll= 2  func_00161c80  src/Kosaka/k_encount.c
    197 edits  lwsll= 1  func_002b77d0  src/promoted/y_draw.c
  ...
```

Two were probed by hand on 2026-09-18 and did not move, which narrows what the
signature means: on `func_001ae3d0` the loop rewrite (plain `u16 i` with the
masks left to the compiler, `s32` bound for the signed `slt`, subscript form)
was neutral at 123 -> 124 because the real residual is one surplus saved
register, and on `func_00169780` all four declaration orders tie at 88 because
its saved-register permutation is not declaration-driven. Treat the signature
as a hint that the index spelling is worth one probe round, not as a fix.

### 7j. A second decompiler, for the functions m2c cannot reach

`tools/m2c_decompile.py` is still the first thing to run on an untried
function: it emits MIPS-flavoured C with this project's declarations in scope.
It has two blind spots that have each cost a session - it gives up on some
jump tables, and it does not recover stack aggregate sizes, so an unexplained
retail stack gap reads as noise instead of as a declared array.

`tools/romwright_decompile.py` wraps a native Rust port of the Ghidra
decompiler and fails in different places.  Import once
(`python tools/romwright_decompile.py --import`, about three minutes into the
gitignored `build/romwright`), then:

```
python tools/romwright_decompile.py func_0016a110          # m2c-shaped C
python tools/romwright_decompile.py func_0016a110 --types  # signature + fields
python tools/romwright_decompile.py func_0016a110 --raw    # Ghidra-shaped
```

The default mode emits **m2c-shaped** C: gp-relative globals already spelled
the way this tree spells them (`fGpffff82b4`), `extern` declarations for every
callee, `temp_vN` locals, and the complete stack frame with array extents
(`float afStack_bb0 [192]`).  That last part is the one m2c cannot give you,
and it is exactly the evidence the `func_002561f0` note asks for: an
unexplained retail stack gap is a real declared object.

`--types` prints the inferred signature plus the structural layout of each
pointer parameter, e.g.

```
  arg1: *struct{+0x0: top, +0x4: float32, +0x8: float32}
  arg2: *struct{+0x0: float32, +0x4: float32, +0x8: float32}
```

which reads an `RwV3d *` straight off the load/store widths.

**Feed the tree back before you use it.**  `tools/romwright_feedback.py`
pushes every matched function's real name and signature into the analysis
database as an *asserted* fact, which no later inference round can overwrite:

```
python tools/romwright_feedback.py            # after any batch of MATCHes
python tools/romwright_feedback.py --dry-run  # see what would be pushed
```

Only live, unguarded bodies are pushed - a guarded NON_MATCHING body is a
draft and its signature is a hypothesis, and asserting a hypothesis would
launder a guess into a fact.  Signatures are rewritten into the decompiler's
own core type names (`u8` -> `byte`, `u32` -> `uint`, `s64` -> `longlong`);
anything that does not map exactly is skipped rather than approximated.

Measured over 25 untried functions, with 6622 signatures fed back:
"Supplied declaration required" notes fell from **212 to 65**, and typed
callee declarations rose from **94 placeholder `FUN_` forms to 207 real named
ones**.  Re-run it after every batch of MATCHes: each one improves the context
the next reconstruction starts from.

**Trust the arity, not the widths.**  Checked against three functions whose
real signatures are known from MATCHes (`func_00311930`, `func_00348330`,
`func_0035c040`) it got the argument count right every time, pointer-vs-scalar
mostly right, and the exact widths and the float return wrong more often than
not.  Retail evidence wins over any inference.

Coverage on this image was 38 of 197 untried functions until 2026-09-18, when
the worker's packed-attribute decoder was fixed upstream: `PackedEncode`
writes booleans and special (stack/spacebase) address spaces with their value
in the type byte's low nibble and no payload, and the decoder was reading that
nibble as a payload length, desynchronising the rest of the element. Coverage
is now 197 of 197, switch recovery went from about 160 failures to none, and
import finds 14457 functions instead of 14388.  If a query ever fails as
"bad packed <addr>" again, `ROMWRIGHT_TRACE_ADDR=1` dumps the payload.

### 7h-sexies. Narrow callee parameters rematerialise; expressions get CSEd

This refines §7c with the rule that decides which way to turn the lever, and
it is what finally broke the §7h-ter class, found on 2026-09-18 while matching
`func_00311930`.

Retail is full of call sequences that keep a wide value in a saved register and
re-emit the narrowing mask at every call site:

```
move  $s5, $a0            ; arg0 kept raw
...
andi  $a0, $s5, 0xffff    ; masked again at call 1
...
andi  $a0, $s5, 0xffff    ; masked again at call 2
```

Writing that as a source-level expression - `f(arg0 & 0xFFFF)`, `f((u16)arg0)`,
or a `u16` parameter used directly - never reproduces it.  b210's global CSE
computes the mask once into a saved register and emits `move $a0, $sN` at each
call, which also costs a saved register and renumbers every other one:

```
andi  $s1, $a0, 0xffff    ; hoisted
move  $a0, $s1            ; at every call
```

The fix is to stop making the mask a user expression at all.  Declare the
**callee's** parameter narrow:

```c
extern u16 func_00107ac0(u16 arg0);   /* not (s32) */
s32 func_00311930(s32 arg0, ...)      /* caller keeps the raw value */
{
    ... func_00107ac0(arg0) ...       /* implicit argument conversion */
}
```

Now the mask is an *argument conversion*, which mwcc re-emits at each call site
and never enters the CSE table.  The caller's parameter must stay wide (`s32`)
so that the raw value is what lives in the saved register.  A micro-test
(`tools/micro_codegen.py`, three calls to `idx`) makes the rule explicit:

| caller param | callee prototype | `andi` emitted |
|---|---|---|
| `u16 k` | `s32 idx(s32)` | 1 (hoisted) |
| `s32 k` | `s32 idx(s32)`, call `idx(k & 0xFFFF)` | 1 (hoisted) |
| `s32 k` | `s32 idx(s32)`, call `idx((u16)k)` | 1 (hoisted) |
| `u16 k` | `s32 idx(u16)` | 0 |
| **`s32 k`** | **`s32 idx(u16)`** | **3 (retail's shape)** |

Both `u16` and `u8` parameters behave this way, and the same reasoning applies
to `s8`/`s16` (`sll`/`sra` pairs instead of `andi`).  When a floor's fndiff
shows retail re-masking where the candidate has `move`, look at the callee
prototype before anything else.

### 7h-quinquies. optimization_level 1 moves the float-to-unsigned temporary

The second half of the `func_00311930` match.  b210 allocates the destination
of a float-to-unsigned conversion out of the CSE table, so the level changes
which register the conversion writes:

```
                      level 0/1                 level 2/3 (and plain -O2)
   c.ole.s $f0, $f1   c.ole.s $f0, $f1          c.ole.s $f0, $f1
   cvt.w.s ...        cvt.w.s $f1, $f1          cvt.w.s $f0, $f1
   sub.s   ...        sub.s   $f1, $f1, $f0     sub.s   $f0, $f1, $f0
```

Retail has the level-2 form.  So a scoped `#pragma optimization_level 1` or
`#pragma opt_common_subs off` - both of which take the conversion out of the
CSE table - will *introduce* a permanent two-to-five word residual on any body
that casts a float to an unsigned type.  `func_00311930` carried such a pragma
for months and the five words it "floored at" were caused by the pragma itself.

Rule: if a floor's residual is only the destination register of a `cvt.w.s`,
delete the optimization pragma first and re-measure; the cost of removing it
usually shows up as the §7h-sexies CSE problem, which now has a fix.

### 7h-quater. The repo permuter is exhausted on the small floors

`tools/permute.py` was run on the eight smallest floors at 30000 iterations
each on 2026-09-18 - roughly 123000 compiles in total - and found **no match**
on any of them:

| floor | compiles | best |
|---|---|---|
| `func_00375f00` | 13657 | 4 |
| `func_001b11c0` | 16379 | 5 |
| `func_0048a980` | 9731 | 5 |
| `func_0034ddf0` | 15723 | 6 |
| `func_0024be40` | 14160 | 8 |
| `func_001130c0` | 18386 | 10 |
| `func_001eca10` | 17313 | 11 |
| `func_0025dd30` | 17812 | 24 |

Its mutation set is exactly the one a human would reach for - optimization
level pragma cycling, local-declaration reordering, adjacent statement
reordering, commutative operand swaps, additive reassociation - so this is a
strong negative: these residuals are not reachable from the current bodies by
reordering anything.  Do not spend another session permuting them.  Note the
permuter reports `normalized_diff`, not the reloc-masked word score
`tools/measure_guarded.py` prints, so its numbers are not comparable to the
floorboard's.

### 7h-ter. The open blocker: retail rematerialises where b210 CSEs

Five floors have now been traced to the same cause, and it is not a source
shape.  Retail recomputes a value that b210 keeps in a register:

- `func_002e5000` (`src/Yajima/y_list.c`) - `D_00882F70[0]->0x38` before the
  third switch.  Adding the reload makes the object exactly 152/152 but costs
  7 words of caller-saved colouring; all 15 declaration moves score 97.
- `func_00169780` (`src/Kosaka/Field/k_fldFrame.c`) - the array element address
  across a call.  Four re-spellings each cost 22 words.
- `func_00164230` (`src/promoted/k_fldUnit.c`) - `D_007F16F0 + i * 8`, twice
  inside one loop body; retail emits `sll / lui / addiu / addu` again.
- `func_003742b0` (`src/Battle/btlShuffleDraw.c`) - a store address before two
  calls.  A pointer local fixes the count but costs 126 -> 158.
- `func_00311930` (`src/promoted/code1_0031.c`) - `arg0 & 0xFFFF` at three call
  sites.  Retail pays three `andi` and keeps `arg0` raw; b210 keeps the mask.

Ruled out by measurement: every opt level, all eight `opt_*` pragmas,
`scheduling`, and the unknown-but-silently-accepted `opt_lifetimes`,
`global_optimizer`, `opt_pointer_analysis`, `opt_partial_redundancy`,
`opt_cse`, `optimize_for_size`, `opt_vectorize_loops` (all no-ops - verify any
new pragma changes object bytes before believing it).  Register pressure is not
the cause either: on `func_00311930` both compilers use eight saved values.
The `cw3.0.1b119` build configured for the RenderWare units CSEs the mask
exactly like b210, so it is not that build either.

The mwcc option axis was probed directly on 2026-09-18.  `-opt display`
reports that the project's `-O2` is **global optimizer level 2 plus optimize
for size**, and MWCCPS2 3.0.1 exposes the speed/size axis only as `-O2p`
(`-opt speed`) / `-O2s`; `-opt speed` is not accepted as a `-opt` keyword in
b210, and no pragma spelling reaches it (`optimize_for_size on|off`,
`opt_for_size`, `optimizeforsize` are all silently ignored - object bytes
identical).  `-O2p` *does* produce the rematerialisation: the three-call mask
micro-test goes from 4 `andi` to 9.  But it is not what retail used - it also
flips the float-to-integer conversion temporary the wrong way, and on real
bodies it inflates them badly: `func_00311930` 152 -> 170 instructions,
`func_00169780` 169 -> 229, `func_002e5000` 152 -> 190.  Size optimization is
correct for this tree.

`opt_common_subs off` and `optimization_level 1` do reproduce the
rematerialisation, but they also move the float-to-integer conversion
temporary (7h-bis), so they trade one residual for another.  A different
MWCCPS2 build, or an option that weakens CSE without touching the conversion
temporary, is the missing piece; this is worth more than further source
probing on those five.

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

0. **Scope check, measured 2026-09-18.** Exactly one of the remaining
   first-party `INCLUDE_ASM` functions is not expressible in C:
   `func_00100008` in `src/promoted/code1_0010.c`, the crt0 entry - it clears
   every GPR and FPR with `padduw`/`mtc1` (including `sp`, `gp` and `ra`),
   uses `mthi`/`mtlo`/`mtsah`/`ctc1`/`sync.p`/`ei`, and tail-jumps to
   `0x43dc60`.  A disassembly sweep of all 502 for privileged or
   register-exact opcodes (`ei`, `di`, `eret`, `mtc0`, `mfc0`, `tlbwi`,
   `cache`, `sync.*`, `ctc1`, `mtsah`, `padduw`, `syscall`, `break`) returns
   that function and nothing else.  Everything else in the queue is ordinary
   C and is expected to match.

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
