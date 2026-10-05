# Track colors: guarded recovery, 2026-10-05, worker 9

`src/promoted/code1_0049.c`, `func_004941f0`, retail `004941F0`.
The guarded C improves from **273 differing words / 1136 bytes** to
**78 differing words / 1168 bytes** in a **1168-byte** window. The fully resolved
residual is 101 bytes. Production retains the `NONMATCHING` marker,
`NON_MATCHING` guard and `INCLUDE_ASM` fallback. This is **not a new C match**.

Only this guarded body and its obsolete explanation were edited in production
source. No shared header, provider, config, progress file, fallback assembly,
other owner, or commit was changed by this lane. All original and interrupted
scratch is retained under `build/resume-model-worker9/`.

## Recovered contracts and storage

Retail, both headstarts, the caller `func_00493790`, and the allocator
`func_00493e60` establish a ribbon and cap with writable geometry color arrays.
The first work object is at `track+0x10`, the cap at `track+0x14`. Each work
object points to an atomic at `+0x10`; its geometry is at `+0x18`, and the color
array is at geometry `+0x30`. The input has four packed RGBA words.

The work row count at `+0x48` and vertex count at `+8` are loaded with `lh` and
then used unsigned. Retail uses `divu` for the vertex-count division by three,
unsigned conversion to float and unsigned loop comparisons. The old signed
draft did not preserve these operations.

Four complete 16-byte `EffectVuVector` objects hold normalized RGBA endpoints.
Their stack slots are `0xC0`, `0xB0`, `0xA0`, and `0x90`. Four packed input words
occupy `0xEC..0xE0`; two packed outputs occupy `0xDC` and `0xD8`. Existing VU
helpers declare the actual memory inputs, outputs and vector clobbers. The two
hardware packing blocks use compiler-allocated GPR outputs, named C output
slots, the binary32 representation of `255.0f`, and explicit clobbers. They
contain only VU conversion and packed-color transport; C performs addressing,
iteration and geometry operations. No uninitialized reads or dummy storage
were introduced.

The third ribbon color and the six repeated cap colors are four-byte aggregate
copies. Their byte-load/store order matches retail. The two mesh replication
loops have independent counters. `RpGeometryLock` and `func_003c22f0` use their
actual pointer-return contracts; the caller discards those returns.

## Measurements and remaining difference

All candidates compiled as the complete owning translation unit, with the
owner's configured MWCCPS2 b210 compiler and `-O2 -Iinclude`. A private source
copy was compiled using `probe_variants._compile_in_context`, preserving the
logical owner and its configuration. Scoped `opt_loop_invariants on` retains
the real vector addresses and packing constant around the gradient loop.

| Retained candidate | Words | Bytes | Alignment edits |
| --- | ---: | ---: | ---: |
| Original guarded baseline | 273 | 1136 | 151 |
| Defined color contracts | 242 | 1184 | 122 |
| Direct named VU outputs | 93 | 1168 | 93 |
| Independent mesh lifetimes, installed behind guard | 78 | 1168 | 78 |
| Staged explicit reuse, archived alternative | 109 | 1168 | 110 |

The 78-word candidate differs in GPR allocation, the first pointer/GP-load
ordering pair, and the loop-entry preheader. The staged alternative reproduces
the complete instruction sequence and branch layout but still changes GPR
allocation. Both remain nonexact. Bounded tests of the real live-value
declarations and separate geometry lifetimes did not close that residual.
No register pinning, invented ABI, or broad syntax permutation sweep was used.

## Whole-owner, relocation and owned-data proof

The fresh production baseline has 43 functions: **39 C MATCH and four ASM**.
The final actual-owner `tools/verify.py` run reports the same result, including
ASM for the target. Both the prepared production branch and the selected C
branch compile with all 43 bodies and canonical relocation targets identical
to their respective proven inputs. The target C compile preserves all
**42 siblings: 39 C functions and three other ASM fallbacks**.

One sibling, `func_00494740`, has a compiler-local literal renamed from `@783`
to `@972` in the selected C object. Its 2120 code bytes are identical, and the
literal remains the same four-byte local object at the same offset and
alignment. Comparing its storage identity resolves the apparent name-only
relocation change.

All seven target code references resolve: two geometry locks, two geometry
unlocks, two `memcpy` calls and the `fGpffff8044` normalization constant. The
normalization load moves by one instruction in the 78-word candidate, so it is
checked against the corresponding retail reference, not asserted positionally
exact. The target defines no data. The complete owner's sole native data
section is a four-byte `.lit4` at **`0x007611B4`**, whose payload matches retail
and is unchanged between the baseline and candidates. Its SHA-256 is
`42cbbe7ad6950d50bb1d8381d7e2d7f9e49ac53d0134e46b5852e49d0cdc66b7`.

The final owner hash is
`b6ed193261568ec8f93f8014d086a71b3756f5fabc9a8e0be002c008c19d1716`.
The before hash is
`9b6bbb1cbffa3a093989ecd72aa43f21dafb00274126a917d13ab2289f980f02`.
The JSON receipt binds the compiler, exact body and object hashes, all target
relocations, sibling names, dependency hashes and native data proof.

## Semantic validation

`track_semantics.py` interprets the actual retail and resolved candidate
instructions for this function's opcode subset. COP1 and VU arithmetic retain
symbolic expression trees, so the check compares their precise operand order
without approximating PS2 float rounding. Addresses and branches execute
concretely. Unsupported instructions and uninitialized register/memory reads
fail the check. Call models discard caller-saved registers and compare all
observable heap writes, copy payloads and call arguments.

Both retained candidates pass **160 scenarios each**: zero and nonzero segment
and row counts, all four ribbon/cap flag combinations, varied RGBA values and
post-unlock flag changes that require the observed reloads. Two negative
controls confirm that changing an input color produces a different trace and
that reading beyond the four input colors is rejected. This is symbolic
dataflow validation with bounded control inputs; it is not a PS2 hardware test,
an arbitrary-callee-side-effect proof, or a universal numeric test.

## Commands actually run

All commands used the pinned `build/venv/Scripts/python.exe` in the designated
worktree. Scratch runners and successful/failed measurements remain intact.

```powershell
& .\build\venv\Scripts\python.exe build/resume-model-worker9/owner_snapshot.py
& .\build\venv\Scripts\python.exe build/resume-model-worker9/track_proof.py direct-mesh-lifetimes staged-gradient-reuse
& .\build\venv\Scripts\python.exe build/resume-model-worker9/track_semantics.py
& .\build\venv\Scripts\python.exe build/resume-model-worker9/check_trace_controls.py
& .\build\venv\Scripts\python.exe build/resume-model-worker9/prepare_guard.py
& .\build\venv\Scripts\python.exe build/resume-model-worker9/install_guard.py
& .\build\venv\Scripts\python.exe tools/verify.py --json build/resume-model-worker9/final-official.json src/promoted/code1_0049.c
& .\build\venv\Scripts\python.exe tools/decomp_lint.py --json build/resume-model-worker9/final-lint.json src/promoted/code1_0049.c
git diff --check -- src/promoted/code1_0049.c
```

Final lint: zero errors, two existing H003 pragma advisories in siblings.
No full link, rebuilt image hash or rebuilt ELF hash was run by this lane.
Prime owns final integration validation. The C candidate cannot be promoted
while any of its 78 instruction-word differences remain.

## Other assigned-owner handoff

The scene-update pair `00485630`/`00485870` retains its independently measured
three-word restoration-register residual; same-run worker7 receipts were read
and their exhausted variants were not rerun. The two primitive floors retain
their documented uninitialized-input blockers. No source changes were made in
either owner.

`mdlManager.c` is also untouched by this lane. Prime reassigned only
`00475cd0` to worker12; direct worker-to-worker messaging is unavailable, so the
unchanged-owner handoff was sent to prime. `0047b0c0` still needs real complete
chunk/effect headers, actual clone arguments and both type-seven request schema
arguments, as described in the existing September 22 archive and confirmed in
the current source/retail windows. Its historical dispatch sweeps were not
repeated. The locally retained P3 counterpart `func_00319970` is itself tagged
NONMATCHING and still uses an eight-byte fragment for the chunk header, so it
does not supply a proven donor closure.

The earlier party-panel lane and its scratch/archive remain unchanged. Its
110-word candidate has the previously recorded retail uninitialized suffix-read
blocker; no new party-panel recovery is claimed here.
