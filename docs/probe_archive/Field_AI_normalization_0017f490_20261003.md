# Field AI: complete normalization objects and float returns

Base: `3686cbd1a9335bc20463f8c24b81127c6eb09e8c`.
Owner: `src/Kosaka/Field/k_fldAI.c`; guarded target: `0017f490`.
The 11,584-byte target remains assembly-backed and `NON_MATCHING`.
This is a bounded contract repair, not a recovered AI controller.

## Provider and caller evidence

The retained draft declared `FUN_003e40b0` as returning `int` and had no
parameter prototype. Ten of its 25 calls numerically converted that inferred
integer to `float`. All 25 passed two copies of an address of a scalar local,
although the provider reads and writes three components.

The actual provider is RenderWare `RwV3dNormalize`, at `003e40b0`:

- Input in a1: floats at offsets 0, 4 and 8
- Output in a0: floats at offsets 0, 4 and 8
- Float length returned in f0: the move from f20 is at `003e4144`
- In-place normalization is supported: x is loaded before its write, and
  writing x does not replace the still-needed y/z input components

The existing SDK declaration in `include/rw/plcore/bavector.h` agrees:
`RwReal RwV3dNormalize(RwV3d *out, const RwV3d *in)`.
The provider's retail body remains unchanged. This repair does not promote
SDK assembly or count it as first-party work.

`audit_normalization.py` reads the hash-validated retail ELF and identifies
all 25 real calls, their a0/a1 address construction and the first float-return
use at each of the ten consumed sites. The calls use 21 distinct in-place
objects; four calls reuse an earlier object. Every complete object is three
floats with no inferred fourth member or explicit alignment padding.

The source now uses the already-defined `FldAIVec3` / `RwV3d` type for these
21 objects. Field names express state and role. The original construction,
component-read and call order is preserved; only each scalar triple's storage,
the provider declaration/name, and the invalid int-to-float return cast change.
The pre-existing scoped `opt_common_subs off` setting is unchanged.

The 2026-09-20 comment claiming the old-style declaration was correct remains
as historical evidence, with a new explicit correction. A historical score
improvement did not establish the calling contract.

## Whole-owner evidence

`capture_owner.py` compiles both the exact base and changed complete owner,
in production and with `NON_MATCHING` enabled. It proves:

- The complete production ELF object is byte-identical
- All 11 production functions, allocated sections and references are unchanged
- All ten non-target guarded function bodies, sizes and references are unchanged
- Every non-target allocated section/reference is unchanged; there are zero
  non-target allocated data bytes in these captures
- The target's complete ordered sequence of 258 reference kinds and symbols is
  unchanged after canonicalizing only `FUN_003e40b0` to `RwV3dNormalize`
- The target-owned 60-byte, 15-entry switch table remains aligned, in-bounds,
  addressed to the same function, and preserves its case-alias groups

The target table offsets change with the guarded body. Its entry-prefix
hashes are recorded, not claimed identical. The guarded controller remains
nonmatching; neither the table audit nor reference preservation proves its
unrepaired state-machine behavior correct.

The machine audit independently checks that the candidate calls pass identical
a0/a1 pointers, that all 21 candidate objects have distinct non-overlapping
12-byte ranges, and that every repeated object retains its identity. All ten
consumed results read f0 before it is overwritten. At those same ten sites,
the base draft instead loses that float return.

Scoped production verification reports:

- Field AI owner: **9 MATCH / 2 ASM**
- Unchanged mixed provider owner `code1_003e.c`: **29 MATCH / 13 ASM**
- Lint: **zero errors**, one pre-existing H011 advisory for `00457120`

## Native contract coverage

The new source-extracted fixture executes every call's actual XYZ construction,
provider declaration, argument pair, result assignment and relevant component
readbacks. Its provider is an explicit boundary recorder, not a simulation of
RenderWare or a gameplay harness. It verifies the complete input vector and
in-place pointer identity, writes all three distinct output components and
returns selected fractional lengths.

At each of `-O0` and `-O2`, **102,400 extracted calls** pass (25 sites × 4,096
seeds), together with **32,768 readback groups**. The ten consumed-return sites
exercise lengths including 0.125, 0.875, 1.5, 3.25, 17.875 and 255.75. Guard
bytes surround fixture storage; production source receives no guard padding.
The native32 runtime uses real four-byte pointers and integer values, strict
boundary diagnostics, UBSan and bounds traps.

Ten runtime negative controls are rejected at both optimizations: integer
return truncation, wrong component, wrong delta origin, lost output z, swapped
input x/y, wrong output alias, wrong input alias, shifted component pointer,
wrong dot component and an undersized object. Two additional controls are
rejected by the strict compiler at both optimizations: integer-return
prototype and passing a component pointer to the complete-object interface.
All six tests pass with **zero skips**.

A separate one-time inverse-transform audit maps the 21 aggregate declarations
and field uses and the 25 canonical calls back to the frozen base token hash.
Every remaining guarded token is identical. This checkpoint-wide proof is kept
outside the long-lived test suite so later independently evidenced repairs can
change other parts of the owner. The unit tests constrain the normalization
family, and do not require generated retail assembly in a clean checkout.

The existing field-shadow and marker suites also pass **21 tests, zero skips**.
These focused checks do not execute the complete unfinished controller.

## Measurements and remaining scope

The guarded target changes from **11,288 bytes** to **11,784 bytes**, compared
with the **11,584-byte retail window**. Its stack frame changes from **0x100**
to **0x1D0**; retail uses **0x2D0**. These are measured allocations of genuine
objects, not padding or a claim that the whole retail frame has been recovered.

`fnalign` reports **2,441 → 2,261 aligned instruction edits** (12 relocation-only
edits in each). Its display trims retail zero tails differently with the
candidate lengths: baseline 2,894 retail / 2,822 object instructions; candidate
2,896 retail / 2,946 object instructions. Raw window sizes above are the stable
size comparison. Masked positional differing-word counts change
**2,619 → 2,639**; positional and aligned scores measure different things.
Neither score is a match verdict.

No full program verifier, linked image build, gameplay run, CI, upload or push
is claimed for this isolated checkpoint. Production object identity is checked
locally; the later combined integration owns aggregate gates.

Known remaining defects include the prologue length call's separate scalar
triple, other providers receiving incomplete local objects, unproven model
pointer declarations, numeric conversions of stored float representations,
and inferred state-machine control flow. No conclusion about full controller
correctness follows from repairing the normalization family.

## Reproduction and inputs

Configure the existing licensed compiler and retail input, then run:

```
bash docs/probe_archive/Field_AI_normalization_0017f490_20261003/replay.sh
```

The replay optionally accepts `P4_NATIVE32_ADAPTER` for the existing external
QEMU adapter; without it, native execution is required and skips fail the replay.
Objects, full captures and temporary candidate text stay under uncommitted
`proof/field-ai/`. Committed receipts contain source, scripts, hashes and bounded
summary evidence only. No compiler, retail executable or object file is included.

The compiler is the configured MWCCPS2 3.0.1 b210, flags `-O2 -Iinclude`, with
its existing owner pragmas. Licensed compiler binary SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
