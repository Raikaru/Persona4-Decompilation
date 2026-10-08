# Field movement: historical guarded semantic recovery

`src/promoted/k_fldEvent.c:func_00174e10` was **NONMATCHING** with its
production `INCLUDE_ASM` fallback. This is a semantic repair, not a C promotion
or a gameplay-equivalence claim. Measurements below were reproduced on
2026-10-08 against main `1e0ce8a012b3ca8762d19bf14119bf52aa280a5d`.
The adjacent JSON is an unchanged historical machine-readable receipt.
The target was subsequently promoted by `d5183160902dff3559c09048ee98b8e6b4cac2c6`.
All source hashes, residuals, guard and object-identity statements below refer
only to the guarded integration, not the current promoted source.

## Source and scope

The owner SHA-256 is
`0ba2684b49c11e82bb3a8138b2221a8f5cc4b369125225812d67cf5bca91f232`.
It is byte-identical to the independently reviewed 2026-10-07 candidate.
The previous main owner is also identical to that review's baseline.
There is no duplicate source archive: the authoritative source is the owner.

The target now uses complete three-float vectors and 64-byte matrices,
reads heading components from the copied matrix's `right` vector, preserves
the degree-valued camera rounding calculation, and supplies the reviewed
pointer/float/return-value contracts. The idle timeout uses signed
`c148 > 360`. For every representable signed input this is equivalent to
`!(c148 < 361)` without arithmetic on the comparison operand. This proof does
not make the preceding signed increment defined for arbitrary invalid state.

Outside the target, the reviewed delta is exactly:

- Owner-local `func_00168890(u8 *, u8 *)` declaration and the casts at its
  existing `func_00175dc0` call
- Owner-local `RwV3dLength(f32 *)` declaration

These are retained from the accepted provider-contract review, not new shared
ABI changes. No provider definition or header is modified. The target's local
matrix layout is a layout view, not a globally unified type. The reviewed
normalization contract has two matrix pointers and a returned matrix pointer;
rotation has matrix/axis pointers, float angle, and integer combine mode.
The reviewed status wrapper has a signed 16-bit selector and an unsigned
returned status word; obsolete annotations elsewhere remain unresolved.

Global provider/caller closure is explicitly not claimed. Provider analysis
stops at the previously established camera, Field AI, and field-normalization
boundaries. No stopped owner was reopened or inspected for this integration.
No new compiler pragma is added; the separate neutral dead-code experiment
is excluded.

## Historical guarded-tree bounded evidence

- Target-only C enabled in the complete owner: 3976 bytes against 3992 live
  retail bytes, within a 4000-byte configured window; frame `0x130`
- 10 fully resolved word Levenshtein edits; 574 positional word differences
- Calls and GP destination sequences agree with retail; 719 owner references
  resolve, with six rejected target/sibling relocation negative controls
- The repeated candidate object SHA-256 is
  `568520b4ed4af5d075c675c9a1e27d9b381192154a4e1b54b59df94df9a266c1`,
  identical to the independently reviewed object
- Current-main and candidate guard-off C-only objects are byte-identical
- Actual assembly-spliced production objects are byte-identical; all 26
  production functions therefore retain their bytes and relocations
- All 25 non-target siblings in the target-enabled object retain bytes and
  relocations and resolve strictly to their retail windows
- No allocated nontext sections exist in these owner objects; the check
  compares their complete allocated nontext section/relocation census

The accepted residual comprises four branch displacements, four missing
floating-predicate words, and one moved address setup (a deletion/insertion).
These small differences do not constitute a match.

## Reproduction

Use the repository's normal setup with authorized local compiler, assembler,
and hash-valid retail ELF. Generated owner fallbacks must be available through
the normal assembly-generation workflow. Do not commit those private inputs,
objects, executable fixtures, compiler diagnostics, or machine-specific paths.

```sh
# Historical replay: use a separate checkout with the frozen guarded owner.
git worktree add --detach ../field-guarded-replay 75f49b54d11d16c713a9fabbdd11469f26a680ae
cd ../field-guarded-replay
# Configure authorized tools and generate fallbacks in this checkout first.
python tools/replay_field00174e10.py
# --baseline changes only the comparison baseline, never the candidate source.
```

On current main, run the source-bound witnesses and current byte verification:

```sh
python -m unittest discover -s tests -p 'test_field_movement*.py' -v
python tools/verify.py src/promoted/k_fldEvent.c
make verify
make build-progress
```

The bounded witnesses accept both guarded and promoted definition boundaries;
the current-owner regression assertion requires the promoted C lifecycle,
and the existing required-C link policy pins this target to its eligible owner.
Fragment discovery ignores comments and literals; unsupported line splices and
in-body preprocessing directives fail closed rather than selecting an arm.
Comment-shadow and runtime rounding mutations are rejected.
They do not pin the whole owner to a historical hash. Their extracted operations
and mutation controls remain bound to the actual source. The historical replay
fails explicitly on a changed owner, including a promoted one, before compiling.
It does not issue the old NONMATCHING receipt for current source.

The replay uses `P4_MWCC`, `P4_RETAIL_ELF`, and `P4_AS`, honors the owner's
configured flags, and enables only this target, never global `NON_MATCHING`.
It compiles baseline/current production with and without assembly splicing,
compiles the candidate twice, compares object/sibling/data identities, and
resolves references against the repository symbol values and retail windows.
Temporary objects and logs are deleted; stdout contains only the receipt.
It reads this owner and configuration, not provider source bodies.
The whole-owner source hash is checked before compilation; source changes
require a fresh review and an updated source binding rather than silently
reusing this receipt.

Host tests extract the actual source expressions, matrix copies, object
clears, and identity initialization. Only provider-dependent pointer inputs
are replaced with initialized host fixtures; the model-copy expression is
checked before substitution. At each of O0 and O2 with UBSan+bounds:

- 1,065,549 signed-threshold checks pass
- 14,102 semantic checks pass, rejecting 11 legacy-rounding cases
- Separate source mutations reject an incorrect threshold and matrix provider

These tests never execute the full target. Initialized fixture storage avoids
executing the target's inherited indeterminate state, including matrix flag
reads; this does not prove those operations defined in arbitrary game state.
The bounded finite rounding domain does not cover exceptional PS2 floating
inputs. No whole-game or emulator run is claimed.

## Lint and broader qualification

Scoped owner lint passes with zero errors and two unchanged H003 advisories
(`opt_common_subs off` and `opt_loop_invariants on`). Its H011 repository-wide
declaration index is intentionally excluded because it would inspect owners
outside the permitted scope. This is not a global ABI audit or a full lint pass.

The complete production build, full verifier, generated progress report, and
progress validation subsequently passed on this integration. Against commit
`1e0ce8a012b3ca8762d19bf14119bf52aa280a5d`, all verifier records agree apart
from source line numbers; the ordered
eligible-owner list, complete ordered linkage report, and progress report are
identical. The build retains 604 C objects and 54 SDK objects, with 6811
first-party matches and 50 ASM entries. Both retail hashes pass:

- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`

The standard build resumed using previously compiler-produced cache entries:
584 eligibility hits / 276 misses and 235 link hits / 369 misses. This is not
reported as a fully cold build. With generated inputs and the authorized
retail fixture available, 867 tooling tests pass with two existing
absent-middleware skips. These aggregate production gates do not establish
whole-function semantic equivalence or globally close the guarded ABI.
The target remains production ASM and this change adds no C matching progress.

Before publication, the integration was fast-forwarded over the disjoint
changes in `dd1a605f25057ec984d3e62ca16592327414932e`. Target replay against
that exact baseline, both affected owner checks, and a complete cached
production build/full verifier/progress report refresh pass. The resulting
ordered linkage and report remain identical to the baseline above; the
refresh recompiles one eligibility and one linked object (859/603 cache hits).
The four Field-specific tests also pass again after the fast-forward.
