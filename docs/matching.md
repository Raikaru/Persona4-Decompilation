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
  exhausting the levers below, it is a compiler floor — see the list at the
  bottom, tag the marker `// FUN_XXXXXXXX NONMATCHING`, and move on. Never
  keep grinding a proven wall.

## Types and the EE ABI

- **Independent int/float argument register files.** The EE o32-hardfloat ABI
  fills integer args (`$a0`...) and float args (`$f12`...) from *separate*
  counters. `f(void*, float)` puts the pointer in `$a0` and the float in
  `$f12` (not `$a1`). Source argument order controls the *materialization*
  order of the two moves: if retail computes `addiu $a0,...` before
  `mov.s $f12,...`, put the pointer first in the C signature.
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
- **Switch case order is numeric-ascending in the object.** mwcc emits switch
  compares in **numeric-ascending** case order. If retail tests a higher case
  first, no switch or if-chain reproduces it. When retail *does* check the
  lowest case first, `switch (e) { case a: case b: ... }` reproduces its
  `beq → body` dispatch with a deferred default.
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
- **A `volatile` lvalue can delay an address calculation across a call.** When
  retail calls a size helper before materializing the destination address, but
  mwcc hoists the destination arithmetic, cast the final lvalue — not the
  stored value — to `volatile`. This keeps the observable store while
  preventing the compiler from scheduling its address calculation before the
  call. `volatile` is banned by `docs/STYLE.md` unless the function carries a
  `measured` waiver.
- **Declaration order sets callee-saved allocation.** Natural declaration
  order (not reverse) tends to reproduce retail's `s0/s1` assignment. A
  **param vs surviving-local fight over `s0`** is generally a floor, not a
  source problem.

## Read-modify-write and flags

- **Chained flag OR → separate statements.** `*p |= a; *p |= b;` (two RMW
  statements on the pointer) reproduces retail's single-load running-value
  chain (`lw; ori a; sw; ori b; sw`). A cached `v = *p; *p = v|a; *p = v|b;`
  gets constant-folded to `ori v0,a` / `ori v0,a|b`. Match whichever the
  disassembly shows.

## Globals and addressing

- **Absolute globals outside the gp window** (read as `lui;lw` with HI16/LO16
  relocs) → declare `extern T DAT_addr[];` and use `DAT_addr[0]`. A `static`
  would emit GPREL16 and mismatch.
- **Absolute function-pointer slots use the same array idiom.** For a retail
  `lui; lw; jalr` through an address outside the gp window, declare
  `extern void* DAT_addr[];` and call `((Ret (*)(Args...))DAT_addr[0])(...)`.
  Declaring `extern Ret (*DAT_addr)(Args...)` can place the slot in small data
  and emit `lw ..., GPREL16(gp); jalr`, one instruction shorter than retail.
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

When no order matches after trying these, drop the function. Indexed
getters/setters are the usual victims.

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

A knob hit is a **proposal**, not a result. `tools/decomp_lint.py` requires the
literal word `measured` within three lines of the pragma, and a pragma that
changes codegen with no recorded reason is the "window fill" defect this campaign
exists to avoid. Record what the pragma fixed and what the residual was.

## Known compiler floors (do not fight these)

When the only residual is one of these, the function is a compiler floor:
keep the best source, tag the marker `// FUN_XXXXXXXX NONMATCHING` (with a
short comment recording what was tried), and move on. Retrying exhausted
variants is wasted time.

- **Call-argument setup order before a JAL.** The order in which independent
  arguments are materialized (`addiu $a0,...` before `move $a1,...` or vice
  versa) is a scheduler choice; the C argument list cannot always reproduce
  it while keeping the required register assignments.
- **Loop-invariant constant hoisting into the preheader.** mwcc sometimes
  hoists a constant into the preheader where retail rematerializes it in the
  loop (or the reverse — see the `opt_loop_invariants` waiver in
  `src/Battle/btlTarget.c`, where retail hoists and mwcc rematerializes with
  swapped `addiu/sllv` operands). Not always source-reachable.
- **Saved-register coloring cycles.** A parameter and a surviving local both
  wanting the same callee-saved register (the param-vs-local `s0/s1` fight),
  or a register reused as an unrelated counter on a sibling branch — these are
  allocation cycles the source cannot break.
- **Independent adjacent memory access order.** Two adjacent loads or stores
  from different fields compile in an order the scheduler picks; when it
  disagrees with retail and the two accesses are genuinely independent, no
  source order fixes it (see also the commutative-`addu` section — but those
  levers work only when the order is *dependent* on addressing).
- **Framed tail jump.** For a one-line wrapper `return g(a);` retail emits a
  frame *and* a tail jump: `addiu $sp,-0x10 / sd $ra,($sp) / ld $ra,($sp) /
  j g / addiu $sp,0x10 / nop` — 24 bytes, `$ra` saved and restored around a
  jump that never needs it. b210 emits exactly three shapes and none is that
  one: 8 bytes (frameless tail jump), 28 bytes (framed `jal`, tail call
  suppressed), or 32 bytes (the same unscheduled). Measured over all 18
  combinations of `optimization_level` 1/2/3 × `tailcall` on/off × `schedule`
  on/off/absent on `code1_0044 func_0044b8d8`; the size never leaves that set,
  so the shape is not a pragma away. `#pragma tailcall off` is a real pragma
  (checked with `tools/pragma_audit.py`) and does stop the collapse — it just
  overshoots the window by one instruction. Affects the ~10-function wrapper
  family in `code1_0043`/`code1_0044`.
- **Absolute-getter address register (19 functions).** For a one-line global
  getter retail emits `lui $v1,%hi(sym) / jr $ra / lw $v0,%lo(sym)($v1)` — the
  address in `$v1`, the value in `$v0`. b210 reuses `$v0` for both. Shape,
  delay-slot fill and the value register already agree, so the whole residual is
  that one register, nd 2 at 12 bytes against a 16-byte window (the gap is
  trailing zero padding, not a missing instruction).
  `#pragma schedule on` **is** load-bearing — without it the `lw` misses the `jr`
  delay slot and the object really is one instruction short.
  Measured on `code1_004c func_004c3410` across 8 spellings, every one landing on
  `$v0`: const-int base + cast, array extern, scalar extern (goes GPREL16, a
  different shape entirely), pointer local, base-array + scaled index,
  base-pointer-then-deref, two-step pointer, and a result local. `permute_ast`
  then ran **9,039 compiles over 900 s** and improved the score 9 → 5 without ever
  matching. Shared as a decomp.me scratch for anyone who wants a crack at it:
  <https://decomp.me/scratch/r8hUx> (compiler `mwcps2-3.0.1b210-060308`, `-O2`).
  The family is 17 functions with this exact `lui/jr/lw` signature plus 2 more
  using `lbu`/`lb`, all ≤ 24 bytes, across
  `code1_0039/0041/004c/004d/004e/004f/0050/0051/0052`.
- **Commutative operand orientation** — `addu` and `mul.s` operand order when
  both operands are live in fixed registers. For float specifically,
  `fresh * invariant` canonicalizes to invariant-first (`mul.s $f0,$f2,$f0`)
  while retail emits fresh-first (`mul.s $f0,$f0,$f2`); neither source
  operand order changes it. Indexed getters/setters and float math are the
  usual victims.
- **`addiu` vs `daddiu` for small constants.** mwcc may emit the 64-bit
  `daddiu` where retail uses `addiu` (or vice versa) when the operand is a
  small constant; the choice is tied to the surrounding type width and is not
  generally source-reachable.
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
- **128-bit `lq`/`sq` aggregate copy.** Three unscanned windows in
  `code1_004a` are exactly `lq $v0,($a1) / sq $v0,($a0) / jr $ra` -- a single
  16-byte load-store pair. There is no genuine 128-bit type in this repo
  (`include/type.h` has none, and the `u128` in the m2c drafts under
  `src/generated/` is a placeholder `typedef u64 u128`), and no matched source
  anywhere in `src/` emits `lq`/`sq`. A `struct { u32 w[4]; }` assignment
  compiles to FOUR `lwc1`/`swc1` pairs instead -- 40 bytes against a 16-byte
  window. Reaching these needs a real quadword type first; do not retry the
  struct-assignment spelling.
- **Zero padding tail.** A 4–12 byte deficit after retail's last real
  instruction is zero padding, not missing logic. `verify.py` treats an
  all-zero tail as matching (`MATCH`; object 108B in a 112B window, 148B in a
  160B window, etc.), and `fndiff.py` counts those tail words in its summary.
  Do not add code to fill it.
- **Instruction scheduling / subexpression evaluation order** in general;
  **FPU-register allocation**; **u16-mask propagation** (retail re-masks per
  use, mwcc elides the repeat); **switch case-order** (retail testing a higher
  case first); the **`slti $at` branch-temp idiom** (`<` against a small
  constant lowers through the `$at` pseudo, while `>=`/`!(x<k)` materializes
  an explicit `slti $v0` — the `$at` layout is not always reachable while
  preserving the required inline/out-line arrangement); and **boolean-result
  tail layout** (retail sometimes places the 0-materialization block after the
  main body but before the 1-materialization, which mwcc never emits
  regardless of source shape).

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
