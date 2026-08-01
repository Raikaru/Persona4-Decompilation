# Source style and honesty rules

These rules apply to authoritative source under `src/`. They do **not** apply
to `src/generated/`, which is raw m2c candidate output (`M2C_CANDIDATE`
markers) and is excluded from the authoritative build.

The bar for a function is exact: it must compile with MWCCPS2 3.0.1 b210 at
`-O2 -Iinclude` and reproduce retail byte-for-byte as reported by
`python tools/verify.py`. Everything below exists to keep that exactness from
turning the source into an unreadable, dishonest pile of steering hacks.

## Naming and types

- **Prefer typed structs and meaningful names over raw decompiler residue.**
  `param_1`/`uVar3`-style names and address arithmetic are accepted starting
  points (m2c output), not finished source. Once struct field offsets are
  proven, replace pointer casts with typed struct access and name fields from
  evidence.
- **Better unnamed than wrong.** If you cannot name something from evidence,
  keep the neutral decompiler name (`param_1`, `uVar3`, `local_8`) rather than
  inventing a name that asserts a meaning you cannot support. Names must follow
  proven behavior and call relationships, not guesses based only on constants.
- **Use the project types** from `include/type.h`: `u8`/`s8`, `u16`/`s16`,
  `u32`/`s32`, `u64`/`s64`, `f32`, `f64`. `bool` is not a valid type in this
  codebase; use `u8`/`u32` for predicate returns.
- **Type floats honestly.** The EE ABI has separate integer (`$a0`...) and
  float (`$f12`...) argument register files, and Ghidra routinely mistypes
  float arguments and returns as `int`. Trust the disassembly (`mov.s`,
  `lwc1`, `swc1`, `cvt.*`) over the decompiler: declare float parameters and
  returns as `float`/`f32`.
- **Typed `short`/`char` in prototypes is a deliberate tool.** Declaring a
  callee as `int f(short)` or `void f(char)` forces per-call sign-extension,
  which retail does; a bare cast in the caller gets CSE'd away. This is a
  source-shaping lever (see `docs/matching.md`), not a license for sloppy
  types.

## Banned constructs

The following are banned in new code. Each exists in the tree today as legacy
debt (the current census: 193 `#pragma optimization_level 3`, 171
`#pragma schedule off`, 3 `#pragma optimization_level 1`, 196 redundant
`#pragma optimization_level 2`, 2 `#pragma opt_loop_invariants`, 4 `volatile`
lines). Do not add new instances. When you touch a function that carries one,
remove it if the function still matches, or convert it to a waiver (below) if
it is genuinely load-bearing.

- `volatile` on non-hardware data. `config/target.json` records that the
  representative retail functions are unscheduled; `volatile` is a compiler
  steering hammer that hides real codegen questions.
- Inline assembly for ordinary computation. (Hardware/ABI-required assembly
  with documented provenance is a separate, acceptable category.)
- Meaningless temporaries — pure register-shuffling locals whose only purpose
  is to nudge allocation.
- `if(1)` and `do {} while (0)` steering wrappers.
- Per-function optimization pragmas: `#pragma optimization_level N`,
  `#pragma schedule off`, `#pragma opt_loop_invariants`. `-O3` in particular
  schedules branch and return delay slots unlike retail P4 functions.
- Dead result stores — assignments to a local that is never read, or a
  "volatile" sink, whose only effect is to keep code alive.
- Duplicated code added to fill a window.
- `register` on ordinary locals.
- Unused locals added to grow a frame.

## The waiver convention

If a banned steering construct is **genuinely load-bearing** — removal
demonstrably breaks the byte match and no honest source form reproduces retail
— it may stay, but only with an annotation that:

1. is placed **above the `// FUN_XXXXXXXX` marker** of the function it steers
   (never inside the body, never below the marker);
2. contains the word **`measured`** (any inflection is accepted; the existing
   annotations use `measures` / `measuring`) recording the **measured cost of
   removing** the construct: the verifier status and normalized diff before and
   after, plus object/window sizes;
3. states why the construct is needed, in one or two sentences.

The measurement procedure: remove the construct, run the scoped verifier
(`python tools/verify.py <file.c>`), record the resulting status and
`normalized_diff`, restore the construct, re-verify `MATCH`, and write the
annotation. A waiver that cannot point at a measured regression is a violation.

### Worked example: `src/Battle/btlTarget.c`

This file contains both a `volatile` and a `#pragma opt_loop_invariants`,
each annotated with its measured removal cost.

The `volatile` annotation directly above the marker:

```c
/* Ported from P3FES src/Battle/btlTarget.c FUN_002d21e0 (verified MATCH there).
 * The `volatile` on `state` is load-bearing and carried over from the donor:
 * removing it measures MATCH nd0 -> nd6 (size 148/160) here, matching the
 * donor's own recorded W170 measurement of nd0 -> nd6. */
// FUN_001EC630
f32 func_001ec630(f32 value, volatile f32* state)
```

This records the measured cost (removal turns `MATCH` into a 6-word
normalized diff, `nd0 -> nd6`), the sizes (148-byte object in a 160-byte
window), and the provenance (carried over from the verified P3 donor, whose
own recorded measurement agrees).

The pragma annotation above the marker:

```c
/* Ported from the P3FES btlTarget donor at 002d1600 (verified MATCH there),
 * which wraps this function in the same pragma. It is load-bearing: without
 * it MWCC rematerializes the loop constant inside the loop (addiu/sllv with
 * swapped operands) instead of hoisting it, measuring nd 28 here. */
#pragma opt_loop_invariants on
// FUN_001EB440
u16 func_001eb440(BtlTarget* target)
```

Here the measured cost is `nd 28` (removal produces 28 differing words), and
the annotation explains the mechanism (the loop-invariant constant stops being
hoisted into the preheader and is rematerialized inside the loop with swapped
operand order).

## Comments and provenance

- Keep the `/* Source unit: <original.c> */` provenance comment at the top of
  files that carry it; it records the original retail translation unit the
  file was recovered from.
- Ported functions record their donor: the P3 file/function and that it was
  verified `MATCH` there, plus any steering carried over (as in the examples
  above).
- Waivers go above the marker (see above). Everything else about *why* a
  function looks the way it does belongs in comments too — future readers
  cannot see the disassembly you are staring at.

## Formatting

- Follow the dominant style of the file you edit. The repository ships a
  `.clang-format` (LLVM base, 4-space indent, Allman braces, 120-column
  limit); matching the file's existing shape matters more than a strict
  formatter pass.
- **Never reformat unrelated code.** A PR that mixes a match with whitespace
  churn is rejected on sight. Keep diffs minimal and reviewable.
- Preserve the file's existing line endings.

## Honesty

- `MATCH` means "I ran `python tools/verify.py` and it said `MATCH`". Never
  claim a match from inspection, from a green exit code alone, or from a
  partial diff.
- Every number in a waiver, a PR, or a comment must come from a command you
  actually ran.
- A truthful "this does not match yet, and here is the residual" is a good
  result. Parking a function as `NONMATCHING` with a documented floor is
  better than shipping a fake match.
- Window filling — growing an object with pragmas, dead stores, or duplicated
  code so the size looks right — is fraud, not decompilation. The banned list
  above exists to make that impossible to do accidentally.
