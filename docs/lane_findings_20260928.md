# Parallel lane findings (2026-09-28)

Eight parallel lanes worked the 158 first-party assembly fallbacks that were left after the
earlier campaigns (the 159th, `func_00100008`, is the crt0 entry stub and stays assembly).
They matched eight functions and moved about twenty more guarded bodies measurably closer.
This page records what they measured. It is a dated snapshot: every claim was measured against
MWCCPS2 3.0.1 b210 `-O2` in that session, on the functions named. Re-measure before relying on
one for a different function, and do not read a rule below as a compiler law.

Matched: `func_00138490`, `func_001c5b80`, `func_002a5630`, `func_002b0250`, `func_002b89a0`,
`func_00349440`, `func_00349c50`, `func_0037ca60`.

Related pages: [`matching.md`](matching.md) (source-shaping reference),
[`first_party_matching_handoff.md`](first_party_matching_handoff.md) (workflow),
[`STYLE.md`](STYLE.md) (acceptance rules).

## A MATCH row is not enough: a new data symbol can drop the whole unit from the link

`func_00349440` matched under `verify.py` while its unit silently left the C link. Its body read
`iGpffff8518`, a GP-relative constant that existed only inside the old guarded body, so no symbol
config defined it. `verify.py` masks relocation fields and still said `MATCH`; both retail hashes
still passed because an ineligible unit falls back to retail bytes; `tools/explain_ineligible.py`
still listed the unit as ELIGIBLE. Only `python tools/build.py --progress-report
build/linked_report.json` showed it: the linked first-party count fell from 6755 to 6749.

Checks that would have caught it, in order of cost:

1. After promoting a function, diff `linked_functions` in `build/linked_report.json` against the
   previous run. Every previously linked address must still be there.
2. If a unit vanished, compile it and look for relocations whose symbol is neither defined by
   the object nor in the symbol maps (`symbols_recovered.txt`, `symbol_addrs.txt`, marker names).
   The unresolved name here was the only one on the unit.
3. Fix by adding the slot to `config/symbol_data_addrs.txt` with its evidence (`gp - offset`,
   the retail instruction address) and to `config/symbols_recovered.txt`. Hand-add the single
   line; regenerating the whole table with `tools/recover_symbols.py` also rewrote about thirty
   unrelated lines in this tree.

The ratchet in `config/link_floor.json` (594) did not fail either: the unit count after the
regression was exactly 594, and it is 595 once the symbol is defined.

## Method that produced most of the gains

- **Structure before colour.** Compare instruction counts, frame size (`addiu $sp`), the
  saved-register set and the stack-slot layout first. Many "floors" were bodies with the wrong
  shape (wrong local, wrong loop form, wrong control flow), where a colouring residual was a
  symptom. Old notes were sometimes stale: `func_00349c50`'s guarded body had regressed to 475
  words and 606 instructions while its note said 229 and 521, and `func_00263730` carried a
  semantic error (retail passes `arg3 - 1 + i` as the date).
- **Count edits, not words.** After one inserted or deleted instruction the positional word count
  stays high although the streams are nearly identical. `tools/fnalign.py` edit counts are the
  useful measure on large functions.
- **A register-masked structural diff separates "wrong shape" from "wrong colours".** One lane
  ran `difflib` over `fnalign.decode` output with every `$sN`/`$vN`/`$fN` replaced by a
  placeholder; a body went 309 -> 148 -> 66 -> 2 structural edits before colouring was touched.
  The script was kept outside the repo.
- **Read retail control flow literally.** `beq; nop; beq; nop; b` is a `switch` with no default
  or an inlined helper with early returns; a lone `beq x,C; nop; b else` around a block is a
  one-case `switch`, not an `if`; `slti v,9; bnez low` with an inline jump table is
  `if (x >= 9) { switch ... } else if ...` (a single switch over the whole range emits a full
  table).
- **Micro tests are cheap and decisive.** Compile a ten-line function with `mwccps2.exe -O2 -c`
  and read `mips-ps2-decompals-objdump -d -M no-aliases` before changing a large body.

## Stack and locals

- **A plain `f32 pos[2]` local is promoted to FPRs; a small named struct local stays in
  memory.** Retail built a two-float result at `0x48($sp)` and copied it out at the join
  (`func_0037ca60`); the struct local plus a struct copy-out reproduced the 0x50 frame and all
  513 instructions.
- **Stack slots follow declaration order in reverse**: first declared gets the highest address,
  scalars sit above aggregates. Disjoint block-scoped locals can share a slot; function-scoped
  ones cannot. A wrong local size (a 12-byte vector declared as one float) shifts the whole
  frame; reordering locals fixed about 30 edits at once in `func_00349440`.
- **`sq`/`lq` slots are ordinary 128-bit register spills**, not `s128` locals. Reproduced by
  `#pragma opt_loop_invariants on` (hoists `(u8)arg2` or `(s16)sel` out of a loop and spills it)
  and by a named pointer used both before and after two calls.
- **Do not cache a field or row pointer that retail reloads.** Naming a `row = base + i*0x30`
  cost a callee-saved register and 0x10 of frame (`func_00361d20`); caching an object pointer
  was wrong in `func_00148280` and `func_002239a0`. Write the field address out at each use and
  let b210 CSE it.
- **Small aggregate copies.** A struct containing a float member copies as `lwc1`/`swc1`; a
  16-byte aggregate splits into scalar copies or folds to `sp`-relative `lq`/`sq`; a 0x90-byte
  struct becomes retail's 9-iteration `ld`/`sd` loop only if it has 8-byte alignment (contains
  an `s64`). `*(V4 *)dst = *(V4 *)src` gives the batched `lwc1`x4/`swc1`x4 form.
- **Struct-by-value arguments**: pass a typed local filled by `x = f(...)` so the hidden return
  pointer is the local itself; casting an `s32` local instead created two byte-copy rounds.

## Register allocation (measured on specific functions; not a universal rule)

- The documented "params first, highest `$s` first" rule held in some functions and failed in
  others. Retail put `arg0` in `$s4` in several battle functions, and in `func_002eb270` and
  `func_002239a0` every declaration permutation tied.
- Lane measurements that refine it (isolation tests plus the real bodies):
  - Call-crossing values passed directly as call arguments, or redefined inside a loop, rank
    above values used only in ALU operations. A value with one plain def and only ALU uses
    (`row = base << 16`) sinks to the lowest registers however often it is used.
  - In `func_001d53e0` nine call-crossing values split into a low group (`$s0`-`$s4`) and a high
    group (`$s5`-`$fp`); declaration order only orders values inside a group, and one extra use
    of a value moves it to the low group.
  - Give each loop its own counter when retail colours them differently; a shared index rotated
    the temporaries of the first loop (`func_0016a110`, `func_00138490`).
  - A value that is really two variables must be split (`func_002a5630`'s `fade`/`alpha`).
  - Caller-saved temporaries colour like callee-saved ones: earlier-declared named locals get
    higher registers, and compiler-made temporaries (hoisted invariants) get the lowest
    (`func_001dbf20`: declaring `tot` before `m` took 16 -> 7 words).
  - Named FP locals are coloured before CSE'd values and pack into `$f0`-`$f2`; float colouring
    follows live-range density more than declaration order.
- **`#pragma opt_lifetimes on` is not in `tools/pragma_sweep.py`'s list.** It closed
  `func_002a5630`, made `func_002a4f20`'s saved registers exact, and cut fnalign edits by
  14-28% on five saved-register-rotation floors (`func_002e3560`, `func_002e2a10`,
  `func_00190c10`, `func_004b8350`, `func_001ed700`; not installed). With it on, declaration
  order matters again. Add it to every colouring sweep.
- **`opt_propagation off` (scoped push/pop around the function) makes statements emit in written
  order**: constants load where written, a named `f32 step = 80.0f;` loads before the int-to-float
  conversion, and a pointer local survives as `addiu` + `0(reg)`. Side effects: it CSEs repeated
  `arg + K` addresses and hoists constants into saved registers, so several lanes found retail
  was built with propagation ON for those functions. A pragma placed inside a body has no effect;
  the state at the opening brace governs the whole function.
- **Other measured pragma facts**: `#pragma auto_inline on` at the callee's definition makes b210
  inline it everywhere later in the unit (this explains `func_002b77d0`'s expanded arms).
  In `func_002b0250`, `opt_loop_invariants on` hoisted at retail's position once `j = 0;` was
  written before the hoisted statement with `for (; j < n; j++)`. On the `mc.c` bodies, `-g`
  produced identical text, `-O1` rewrote the whole body, the b119 compiler was worse and `-O2,p`
  added alignment nops.

## Expressions, floats and argument order

- **Hand-expanded unsigned conversions are the wrong spelling.** `(f32)(u32)x` and `(u8)float`
  make b210 emit exactly retail's `bltz`/`srl`,`andi`,`or`/`cvt.s.w`/`add.s` and the
  `0x4F000000` threshold sequences. `func_002b89a0` matched by replacing an m2c-style
  expansion with plain casts. Grep guarded bodies for `2147483648`, `>> 1) |` and `0x80000000`
  next to `(s32)`; `func_004b36b0` and `func_0021fea0` still contain them.
- **A callee parameter's width decides argument emission order.** A byte loaded into an `s32`
  slot is hoisted before earlier loads; only a `u8` parameter keeps slot order. A callee that
  masks `& 0xFF` on entry can be re-typed `u8`/`u16` and stay MATCH (`func_0011de40`,
  `func_00114e50`). `andi` on every compare of a parameter means the parameter is `u8`.
- **Float parameter order shows in emission order.** When a plain float's `mov.s` is emitted
  after the integer arguments and retail emits it earlier, declare the callee with the floats
  interleaved as retail emits them (`func_002a7920`); the same held for `RwMatrixRotate`.
- **Operand order**: `mul.s` of `(f32)byte * scale` follows the address spelling
  (`*(u8 *)(p + 0x1E2 + i*0x30)` gives byte-first, `p + i*0x30 + 0x1E2` gives scale-first);
  `x*x + y*y + z*z` written in x, y, z order gives the `mula(y)/madda(x)/madd(z)` chain retail
  has; `(u8 *)(idx*2) + (u32)base` gives `addu v0,v0,base` where `base + idx*2` gives
  `addu v0,base,v0`; `1.25f * top` loads the constant first.
- **Fusion**: a single-statement `1.0f + K*x` fuses into `adda.s`/`madd.s` when the constant is
  reused; retail's unfused `mul.s` + `add.s` needs `pulse = K * x; scale = 1.0f + pulse;`.
  `a + b*c` always emits `mtc1 zero; adda.s; madd.s`, so `(0.0f + x) +` prefixes are unnecessary.
- **A call result stored before constants are loaded changes constant order**:
  `t = f(); (u8)(255.0f * (1.0f - t))` loads 255.0 first; inlining the call loads 1.0 first.
- **Loops**: `s16` counters give `dsll32`/`dsra32` pairs; `++*(u16 *)p >= N` in the condition
  gives `addiu; sh; andi` in one register where a `t = *p + 1` local does not; `s32 j` with
  `j = (j + 1) & 0xFFFF` keeps a fresh `andi` in the body where a `u16 j` makes b210 mask the
  test temporary.
- **Switch shapes**: `if (c != 4) switch (c) {0..3}` reproduces "compare 4 first, then 3,2,1,0";
  a literal fifth `case` makes b210 emit a jump table; an `if/else if` chain replaces a small
  switch when retail compares in source order.
- **An inline helper that returns 1 or 0 from inside a loop** reproduces "result in `$v0`,
  `addiu $v0,1; b` on a hit, `move $v0,$zero` after the loop"; a `res = 0; for(...) {res = 1;
  break;}` local cannot.

## Functions still open, with the residual each lane measured

Guarded bodies were left in place; the source notes above each marker carry the same detail.

- Saved-register colouring only: `func_0024be40` (8 words; b210 always coalesces
  `base + idx*6` into `base`'s register, retail does not), `func_001d53e0` (8), `func_001b11c0`
  (5, `$t1`/`$t3`), `func_002eb270` (48), `func_00296850` (455), `func_002a12e0` (49),
  `func_002a5f00` (44).
- FPR numbering only: `func_004a7830` (7), `func_0016a110` (67).
- One or two small unexplained effects: `func_00375f00` (2; retail keeps `arg0 + idx` live and
  copies it), `func_002a03b0` (4; a constant-before-`andi` order and an x/y add order),
  `func_0036f880` (41; `count`/`(s16)i` saved-register order, a `$t3`/`$t4` swap and retail's
  unfolded `addiu 0x72`/`0x70` reads, not reproduced by about 40 spellings), and
  `func_00485870` / `func_00485630` (3 each; the reload temporary is `$v1` where retail has
  `$v0`; a hard-coded `lq $2`/`sq $2` asm block reproduces retail exactly, which suggests the
  original used an asm macro, but that transcribes ordinary computation and is excluded by
  STYLE.md).
- Not reached or blocked: thirteen guarded bodies did not compile at the start of the session
  (`func_001265a0`, `func_00172e00`, `func_0031ac10`, `func_00320b80`, `func_00321e60`,
  `func_00323d00`, `func_00324680`, `func_00356a10`, `func_0047b0c0` and the four battle bodies
  in `code1_001a.c`). The four battle bodies compile again and are now close or under
  investigation (`func_001ad550` 2 words, `func_001abbb0` 55, `func_001a4c80` and
  `func_001aed50` 163 and 122 fnalign edits); the other nine were not reached. The
  `effPolygonFlash` family and most other effect functions are VU0/MMI inline-assembly bodies.

## Tool notes

- `tools/permute_ast.py` preprocesses with `mwcc -E`, which consumes every `#pragma`, so its
  baseline score is wrong for any file whose function depends on pragma state (it reported 103
  words for `func_001b11c0` where `verify.py` says 5). Preprocessing such files with GNU `cpp`
  keeps the pragmas and restored the baseline to 5. The fix is not applied in this tree.
- `tools/floorboard.py`'s origin filter admitted `func_0044e830` (`src/middleware/gcc_fp.c`,
  GCC's libgcc soft-float code), which the committed progress data and `verify.py` classify as
  third-party. Rank against `progress/metrics.json`'s `main` addresses instead.
- `tools/measure_guarded.py` hides compiler diagnostics; splice the guarded body into a scratch
  copy of the unit and compile it directly to see why a body reports "probe failed".
- An ee-gcc unit needs the 32-bit loader (`libc6:i386`) locally; without it `verify.py` reports
  `COMPILE_ERROR` for every ee-gcc function.
