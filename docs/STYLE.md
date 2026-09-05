# Source style and honesty rules

These rules apply to authoritative source under `src/`. They do **not** apply
to `src/generated/`, which is raw m2c candidate output (`M2C_CANDIDATE`
markers) and is excluded from the authoritative build.

The bar for a function is exact: it must reproduce retail under its configured
compiler and flags, as reported by `python tools/verify.py`, and preserve the
retail behavior and ABI. Most first-party units use MWCCPS2 b210 at `-O2`;
the per-unit configuration is authoritative. Lint is an integrity check and
review aid, not proof of semantic equivalence.

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
- **Keep callee prototypes consistent.** Narrow parameters are appropriate
  only when supported by the callee's actual ABI. Do not introduce an
  incompatible local declaration merely to force sign-extension or register
  allocation; fix the definition and all callers together when evidence
  establishes a different contract.

## Integrity checks and advisories

`tools/decomp_lint.py` separates structural integrity from source heuristics:

- **Errors:** malformed/duplicate markers (M001), invalid pragma push/pop
  nesting (P001), allocation-only empty assembly barriers (H002), and assembly
  implementing ordinary computation instead of recovered C (H009). Missing
  or unreadable requested inputs also fail the scan.
- **Warnings:** unexplained `volatile` context (H001), optimization provenance
  (H003), and assigned-but-unread locals (H007). These require review, not
  automatic rejection. A literal hardware address is not the only legitimate
  reason for `volatile`; symbolic MMIO and interrupt-shared state also exist.
- `register` is valid C, not a prohibited construct. `optimization_level 2`
  may restore a previous setting and is not diagnosed as redundant.
- Optimization pragmas are valid compiler inputs. Record useful measurements
  and prefer scoped push/pop when changing a setting for one function.
  On/off directives set state; they are not arithmetic balancing pairs.
  `tools/pragma_audit.py` separately checks compiler-recognized spellings.
- Hardware assembly may contain bounded setup/teardown instructions, but one
  privileged instruction does not justify an arbitrary assembly transcription.
  A pure empty compiler memory barrier with no input/output operands and a
  `memory` clobber is legitimate; document the ordering requirement it serves.

## Exceptions and measurements

Measurements should record the compiler/profile, object/window sizes, and
what changed. A nearby `measured` comment may explain an advisory, but matching
bytes cannot waive H002/H009: copied assembly can match by construction.

An exceptional integrity-rule waiver must name its rule and give a semantic
reason in a real comment, for example:

```c
/* lint: allow H009 -- hardware wrapper unavailable as a compiler intrinsic */
```

Use `:` or `--` between the code and its nonempty reason. Bare `lint: allow
H009` is insufficient. Place the comment at the site or with the enclosing
function's marker; it must not license neighboring functions. Text inside
string literals is program data, never a waiver.

An unused assignment can still call a side-effecting function. When addressing
H007, preserve the call or other observable effect rather than deleting the
whole statement mechanically.

## Comments and provenance

- Keep the `/* Source unit: <original.c> */` provenance comment at the top of
  files that carry it; it records the original retail translation unit the
  file was recovered from.
- Ported functions record their donor: the P3 file/function and that it was
  verified `MATCH` there, plus any compiler settings carried over.
- Put exceptions at their site or with the enclosing marker. Explain why
  unusual source is needed; future readers cannot see the disassembly you
  are staring at.

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
- Do not fabricate side effects, duplicate code to fill a window, or count a
  transcription of ordinary assembly as recovered C. Legitimate compiler
  controls and `register` declarations are not inherently dishonest.
