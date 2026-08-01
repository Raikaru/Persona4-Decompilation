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
