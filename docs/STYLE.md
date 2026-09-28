# Source style and honesty rules

These rules apply to authoritative source under `src/` and `include/`. They
do **not** apply to `src/generated/`, which holds raw m2c drafts
(`M2C_CANDIDATE` markers) outside the authoritative build.

A function is matched when its owning file, compiled with that file's
configured compiler and flags, reproduces the retail instructions and the
C preserves retail behavior and ABI. Most first-party files use MWCCPS2 3.0.1
b210 at `-O2`; the per-file configuration wins. `tools/decomp_lint.py` checks
integrity and flags constructs for review. It does not prove semantic
equivalence.

## Verification

- `MATCH` means `python tools/verify.py <owner.c>` reported `MATCH` for the
  function when the **whole owning file** was compiled. An extracted copy, a
  scratch file or a probe result is a candidate, not a match.
- Every other function in the owner must keep its status and size. Shared
  declarations, literals and pragma state can change a sibling that was not
  edited.
- `verify.py` masks relocation fields. Compare GP-relative and `%hi`/`%lo`
  references with the retail immediates, and run `make build-progress` when a
  change adds or re-points symbols, owned data or declarations. Both retail
  hashes must pass and the changed object must stay C-linked in
  `build/linked_report.json`.
- A changed signature changes every caller. Update and verify every owner
  that declares or calls the function.
- A non-matching attempt stays behind `#ifdef NON_MATCHING`, with
  `INCLUDE_ASM` in the production branch and the marker tagged
  `// FUN_xxxxxxxx NONMATCHING`. It may also be archived in
  `docs/probe_archive/`. Never remove a marker to hide a failure.

## Naming and types

- **Prefer typed structs and meaningful names over decompiler residue.**
  `param_1`/`uVar3` names and address arithmetic are starting points, not
  finished source. Once field offsets are proven, replace pointer casts with
  typed struct access and name fields from evidence.
- **Better unnamed than wrong.** If a name cannot be supported by behavior
  and call relationships, keep the neutral decompiler name. Do not name from
  a constant alone, and do not present a descriptive name as an original
  Atlus symbol.
- **Use the project types** from `include/type.h`: `u8`/`s8`, `u16`/`s16`,
  `u32`/`s32`, `u64`/`s64`, `f32`, `f64`. `bool` is not used in this
  codebase; predicates return `u8`/`u32`/`s32` as the ABI requires.
- **Type floats from the disassembly.** The EE ABI passes integers in `$a0`...
  and floats in `$f12`... from separate counters. Ghidra often shows float
  arguments and returns as `int`/`undefined4`; `mov.s`, `lwc1`, `swc1` and
  `cvt.*` decide the type.
- **One function, one signature.** Narrow or signed parameters must match
  the callee's actual ABI. A callee that masks or extends its own argument on
  entry (`arg & 0xFFFF`, `(u16)arg`) is usually evidence that the real type
  is narrow. Fix the definition and all callers together; do not add a
  conflicting local declaration to force an extension or register. Lint
  H011 reports `func_` declarations whose width, signedness,
  pointer/value, aggregate/scalar, arity or struct return disagrees with the
  active definition. Spelling differences such as `int`/`s32` are ignored.

## Recovered C, not steering

The source must describe what the program does. Rejected even when the
bytes match:

- a fake ABI: omitted or invented arguments, old-style `func()` calls that
  pass whatever is left in a register, incompatible local prototypes, fake
  returns, or a pointer return that only keeps `$v0` live;
- uninitialized reads, dummy locals, synthetic padding, duplicated code to
  fill a window, and undefined behavior such as shifts by the full width;
- `volatile` on ordinary memory to force reloads or ordering;
- inline assembly or `.word` data that transcribes ordinary computation.

Legitimate compiler inputs are allowed:

- **Pragmas.** Optimization and scheduling pragmas recognized by the
  compiler are real source settings. Record the measurement that justifies a
  nonbaseline setting (H003 is a review warning) and prefer scoped
  push/pop for one function. On/off directives set state; they are not pairs
  to balance. `optimization_level 2` may restore a previous setting.
  `tools/pragma_audit.py` checks spellings. `#pragma schedule on` inside a
  guarded body is an error (H010): the first-party build is unscheduled, so
  it only deletes delay-slot `nop`s.
- **`register`** is valid C and is not a violation.
- **`volatile`** for hardware registers, symbolic MMIO and state shared with
  interrupt handlers.
- **Hardware assembly** limited to operations C cannot express: syscalls,
  privileged instructions, and COP2/VU0 operations. Keep allocation,
  traversal, arithmetic and object layout in C. Use compiler-provided
  operands, name every memory input/output and declare exact clobbers. One
  privileged instruction does not justify transcribing the rest of a
  function. Many `lqc2`/`sqc2` transfers are reachable from C; measure the
  truthful type and alignment first.
- A pure compiler memory barrier (`asm volatile("" ::: "memory")`, no
  operands) is allowed; document the ordering it enforces.

## Integrity checks and advisories

`python tools/decomp_lint.py <file.c>` must report no errors for changed
first-party files. `--list` describes every rule.

| Severity | Rules |
| --- | --- |
| Error | M001 malformed or duplicate marker; M002 `NONMATCHING` body without an `INCLUDE_ASM` fallback; M003 guarded body under an untagged marker; M004 comment between a marker and its `INCLUDE_ASM`; M005 `NONMATCHING` marker without a guarded body; P001 pragma push/pop underflow or unclosed push; C001 unterminated block comment; H002 zero-instruction allocation barrier; H009 inline assembly emitting ordinary instructions; H010 `schedule on` in a guarded body |
| Warning | H001 `volatile` without recognized hardware context; H003 nonbaseline optimization pragma; H007 local assigned but never read; H011 declaration disagrees with the definition |

Warnings require review, not automatic rejection. A literal hardware
address is not the only legitimate reason for `volatile`. When addressing
H007, keep any call or other side effect in the assignment.

## Exceptions and measurements

A nearby `measured` comment can explain an advisory. It cannot waive H002
or H009: copied assembly matches by construction. An integrity waiver names
the rule and gives a semantic reason in a real comment:

```c
/* lint: allow H009 -- hardware wrapper unavailable as a compiler intrinsic */
```

Use `:` or `--` before the nonempty reason. Place it at the site or with the
enclosing function's marker; it does not cover neighboring functions. Text
inside string literals is data, never a waiver. M001 and P001 cannot be
waived.

## Comments and provenance

- Keep the `/* Source unit: <original.c> */` comment at the top of files
  that carry it; it records the retail translation unit.
- A function ported from Persona 3 FES records its donor file and function,
  that the donor verified `MATCH`, and any compiler settings carried over.
- Put an exception or unusual source shape next to the code, with the
  reason and measurement. Readers cannot see the disassembly you used.

## Formatting

- Follow the dominant style of the file. `.clang-format` (LLVM base,
  4-space indent, Allman braces, 120 columns) is a guide; the file's
  existing shape matters more than a formatter pass.
- Do not reformat unrelated code or mix a match with whitespace churn.
- Preserve the file's line endings.

## Honesty

- Report only measurements you ran. Label older or cited results with their
  source and date; do not present them as checks of the current tree.
- "Does not match yet; here is the residual" is a good result. A guarded
  attempt with a measured residual is better than a fake match.
