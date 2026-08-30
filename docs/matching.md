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
