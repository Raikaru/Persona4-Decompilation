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
  retail's `dsll32`/`dsra32` sign-extension pairs.
- **The signed align-up idiom is `/ 64 * 64`, not hand-written shifts.**
  Retail `addiu $v1,$v0,0x3f / sra $v0,$v1,6 / bgez $v1 / addiu +0x3f / sra`
  is `(size + 0x3F) / 64 * 64` on a signed operand; an explicit negative
  branch with `>> 6` was the archived "register-class" residual in both
  `func_00455ea0` (nd 7) and `func_0047e450` (nd 5).
- **A 12-byte global origin is a `Vec3` struct assignment** (`ld` + `lwc1`
  with separate `lui` pairs, `sd` + `swc1`): `func_00170f60` spelled it as an
  `s64`/`f32` pair through two globals and stalled at nd 8.
- **`pcpyld $v0,$zero,$v0` is reachable from C.** `func_003a2950`'s
  `*(u64 *)p &= (u64)-0x10000` emits `lui $v0,0xffff / pcpyld $v0,$zero,$v0`
  exactly; it is how b210 materialises a 64-bit constant whose low word is
  a `lui` immediate. Do not file every MMI opcode as a floor.

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

A knob hit is a **proposal**, not a result. `tools/decomp_lint.py` requires the
literal word `measured` within three lines of the pragma, and a pragma that
changes codegen with no recorded reason is the "window fill" defect this campaign
exists to avoid. Record what the pragma fixed and what the residual was.

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

- **Argument materialisation order via a block-scope prototype.** A
  `func(s32, s32, s64, s32)` redeclaration inside the caller makes mwcc load
  the third argument (a GP-relative `lw`) before the constant first argument
  and the second `lw`; the callee's real signature is all-s32 and reads only
  the low word (`lw` sign-extends), so nothing changes at run time
  (`func_0018dde0`). Same family as the f32-first reordering already used for
  `func_002b8300` in `code1_002e.c`/`code1_0033.c` (`func_0033d550`).
- **Comparison operand side.** `(u32)(elapsed_a - elapsed_b) > (u32)limit`
  versus `limit < elapsed` picks which operand lands in `$v0`/`$v1` for the
  `sltu`; try both before anything else when the only residual is a swapped
  compare pair.
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
