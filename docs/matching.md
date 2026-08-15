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
