# Installed unit RGBA blend: func_001fd790

The approved vector blend is installed in `src/promoted/btlEPL.c`. It remains
behind `NON_MATCHING`, with the retail `INCLUDE_ASM` fallback and marker intact.
No exact C credit is claimed. The original blank line after `#endif` and all
source outside the target's note and guard are preserved.

The active fade cases convert both colors, scale two complete four-component
vectors, and add them. This follows the scale/add operations documented by
`include/rw/plcore/bacolor.h`. Every vector component is initialized before use.
Only fade cases 1 and 2 evaluate `1 - scale`; every path to either case first
initializes `scale`. Constant-color and plateau cases consume no coefficient.

## Measured installed result

Configured MWCCPS2 3.0.1 b210 compiles used the actual authoritative owner as
input, with private outputs and the owner's `-O2 -Iinclude` flags. The guarded
mode adds `-DNON_MATCHING`. The standard `verify_file` entry point reports:

| Mode | C matches | Assembly fallbacks | Nonmatching C | Resolved code references |
| --- | ---: | ---: | ---: | ---: |
| Default | 26 | 1 | 0 | 322 |
| Guarded | 26 | 0 | 1 | 343 |

The guarded target is **2172 bytes in a 2176-byte window**, with **90 fully
resolved differing words / 127 differing bytes**, 22 resolved references, and
four zero suffix bytes. The previous guarded source was 2180 bytes with 276
differing words. All 26 siblings preserve their raw and resolved code; the
default whole object is byte-identical to the pre-installation object, and the
guarded whole object equals the reviewed proposal object.

Both allocated nonexecutable sections match retail and are unchanged: four
bytes of `.sbss` at `0x0076449C`, and four bytes of `.lit4` at `0x0076129C`.
Every allocated executable byte belongs to a known function or verified zero
padding. All code/data relocations, complete storage extents and alignment gaps
are checked. Data placement is anchored by exact siblings, excluding the
nonmatching target. No relocation masking is used for the final verdict.

The first remaining difference is at target offset `0x1BC`: retail assigns the
complement to `f2`, while the C object assigns it to `f0`. Subsequent differences
follow the register rotation `retail f0 -> C f1`, `f1 -> f2`, `f2 -> f0`.
This is a residual diagnosis only; the verifier still records all 90 differing
words. Nothing outside that rotation differs in the resolved operation stream.

Source lint reports zero errors and 11 advisories on unchanged lines outside
the target: ten existing interface declarations and one existing pragma.
The scoped whitespace check passes. No PS2 execution or complete-image linkage
result is asserted by this archive; final integration belongs to prime.

## Evidence and replay

`receipt.json` binds the installed source, source delta, compiler, header/tool
inputs, all default function proofs, guarded target, storage proofs and residual.
It includes the source-hash bridge from the reviewed proposal to the installed
file. `source.patch` is the installed delta. `native.py` resolves references and
checks complete storage; `replay.py` runs the actual installed owner in both
modes and compares the result with the receipt. The archive contains text and
hashes only, without proprietary executable/object contents or machine paths.

From the repository root, with the configured compiler and authenticated retail
ELF available, use a new private output directory:

```sh
build/venv/Scripts/python.exe docs/probe_archive/BtlEpl_vector_blend_worker25_20261005/replay.py --out build/epl-vector-replay
```

On other hosts use the configured Python interpreter. The script reads the
repository's existing compiler and retail configuration; it never modifies
source, global build outputs or configuration. Existing completed modes are
authenticated by source/input/object hashes and reused. Incomplete output is
rejected for inspection rather than silently overwritten or recompiled.

To require reuse of already completed modes:

```sh
build/venv/Scripts/python.exe docs/probe_archive/BtlEpl_vector_blend_worker25_20261005/replay.py --out build/epl-vector-replay --reuse-only
```

## Input and object hashes

SHA-256, installed source:
`8f90e0ff43a8a274aecaef5607ca2202a2f30e5fe8aede71cbfc61d3ca187195`

Default whole object:
`4e5931e137ad15617182f5f169519c110353cb45ba4663810828c3629c55659c`

Guarded whole object:
`c19771f85df33a8028eb11750078cbf5b037c21ed29918a71c42d2a47f4fb6bf`

Resolved guarded target:
`b6f5df613477e82a25dcb51177155300fe3e6635bab2cc858709a6ebcc7aa047`
