# Rules

What every commit keeps true, why, and what catches a violation. The steps
for a pull request are in CONTRIBUTING.md; naming and typing rules are in
`docs/STYLE.md`. `python tools/decomp_lint.py --list` prints the lint rules.

## The executable stays byte-exact

Every commit builds both retail SHA-1s. A function is matching C, an
`INCLUDE_ASM` fallback, or an attempt under `#ifdef NON_MATCHING` with the
fallback in its `#else` branch and `NONMATCHING` on its marker. Live C that
does not match is never committed.

Checked by `tools/build.py` and `tools/verify.py`; lint rules M002, M003 and
M005 check guarded attempts.

## Markers are the denominator

Each `// FUN_XXXXXXXX` marker is in exactly one file. Move a marker only with
its function, and never delete one to remove a failure. Boundary changes go
through `tools/reconcile_function_boundaries.py`, not hand edits to
`tools/slus21782_functions.json`.

Checked by `tests/test_marker_tripwire.py`, `tests/test_verify_markers.py`
and lint M001 and M004.

## Matching C must be honest C

Byte equality does not show that the source is a decompilation. Inline
assembly is limited to instructions C cannot express: `syscall`, `sync`,
`ei`/`di`, `cache`, the COP0 instructions (`mfc0`, `mtc0`, `eret`, `tlbwi`,
`bc0f`, `bc0t`), COP2 transfers (`qmtc2`, `qmfc2`, `lqc2`, `sqc2`, `cfc2`,
`ctc2`) and VU0 macro instructions. A hardware wrapper may include the
register moves those instructions need. Ordinary computation in `asm`, and
empty `asm` statements used to steer register allocation, are errors. A pure
compiler memory barrier is allowed.

Checked by lint H009 and H002. They can be waived only by a rule-specific
comment giving the reason, such as `lint: allow H009 -- <reason>`.
"Measured" is not enough.

## Compiler settings need evidence

Pragmas are legitimate when retail was built that way. Non-baseline settings
(an `optimization_level` other than 2, `schedule off`, `opt_common_subs off`,
`opt_loop_invariants`) raise warning H003 for review; record the
measurement next to them. Use `#pragma push`/`pop` for settings scoped to one
function. `#pragma schedule on` inside a guarded attempt is an error (H010),
because it can shrink the count without matching retail.

MWCC ignores pragmas it does not recognize. `tools/pragma_audit.py` and
`tests/test_pragma_audit.py` reject them. Lint P001 checks push/pop balance.

## The compiler is chosen per unit, in configuration

Each translation unit is compiled by one compiler at one setting, as in the
original build. The choice lives in `config/compiler_units.txt`,
`config/version_flags.txt`, `config/speed_units.txt` and
`config/gcc_units.txt`, never in the source file. A unit that names a
compiler with no configured path fails verification; it does not fall back to
the default. See [The Retail Build](The-Retail-Build).

## Linked C does not silently decrease

`config/link_floor.json` is the minimum number of source units in the link.
Raise it when a unit joins the link. Lowering it needs a reason in the commit
message.

Checked by `tools/build.py`.

## Symbols come from evidence

A new data symbol goes in `config/symbol_data_addrs.txt` with the
instruction that proves its address. A gp-relative name's suffix is the
retail immediate. WRONG SYMBOL and WRONG CALLEE in `tools/verify.py`, and the
full link, check the result.

## Names do not claim more than is known

A neutral name such as `func_00219790` is better than a wrong one. Use the
types in `include/type.h`, and give floats float types. `docs/STYLE.md` has
the details. Lint reports conflicting declarations of one function (H011)
for review.

## Line endings are preserved

A CRLF file stays CRLF. `tools/park.py` preserves line endings; do the same
when editing by hand.
