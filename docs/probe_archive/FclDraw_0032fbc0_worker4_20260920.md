# Fcl grid draw 0032fbc0 — exact recovery and shared ABI closure

Recovered on 2026-09-20 and sealed against the integrated sources on 2026-09-21.
Only `func_0032fbc0` is newly promoted by this package.

## Behavior and source evidence

The complete retail body in
`asm/nonmatchings/y_fclCombineDraw/func_0032fbc0.s` establishes both signed-short
loops, the seven ordered `func_0034ae50` lookups per grid entry, and the real
position/color inputs. The position comes from offset `0x28`, both four-byte
colors from `0x75`, both alpha values from `0x5e`, and depth from offset `4`.
The Ghidra reference at lines 7296–7369 and IDA reference at lines 6679–6765 of
their respective `src/Event/Fcl/y_fclCombineDraw.c` exports were checked against
that complete assembly. The call in guarded `func_00304580` passes the original
task pointer before refreshing the surrounding combine display.

The recovered body constructs the banner position at `(16, 104)` and the row
position at `(16, 128)`. Its heading uses `329 + 23 * row`, two actual
`(0, 0, 0x99, 0xff)` color packets, height 32, and depth 159. It acquires text
resource `0x39` before configuring resource `row + 0x25e`, uses the actual
`iGpffff8504` scale input, constructs both positions for the vertical animation,
and releases the acquired resource after configuring it.

Eight-byte position aggregates and four-byte color aggregates produce the
retail unaligned loads. Seven ordinary pointer locals have the necessary
lifetimes and naturally reproduce the two full-register spills. Direct
signed-short-to-float conversion, scoped coordinate locals, and the fused
multiply/add expression recover the remaining allocation and conversion
differences. No padding, assembly, artificial spills, or new optimization
pragmas are used. Earlier failed integer-packet and artificial-spill experiments
remain archived in `P01C_0032fbc0_body.c`; their obsolete source-floor comment
has been removed from the promoted body.

## Shared contracts

`include/fcl_draw_task.h` now declares the shared contracts for `func_002b83e0`
and `func_002b6af0`. The existing `FclDrawColor` type also supplies the draw
owner's `FclByte4` alias. `fclPacketColor` preserves an existing packed word's
four bytes through a union, following the existing position-packet conversion.

For `0032fbc0`, `002b83e0` receives the draw pointer, position packet, two color
packets, and two alpha values in integer registers `$4` through `$9`; height
and depth use `$f12/$f13`; duration and delay use `$10/$11`; the two signed-byte
modes occupy the stack. Its complete retail body and existing guarded C
definition corroborate these widths and uses. The C declaration places the
floating arguments before duration and delay while preserving both register
sequences. The `002b6af0` declaration similarly places its four floating
arguments after the resource parameter and before mode, duration, and delay.
Its actual provider remains byte-for-byte identical.

All authoritative occurrences are coordinated across
`y_fclCombineDraw.c`, `y_fclCombine.c`, `src/promoted/y_draw.c`, and
`src/promoted/code1_002b.c`. Conflicting local declarations are removed.
The generated candidate sources remain outside the authoritative closure.

Eleven guarded witnesses compile with the coordinated header: draw
`003191c0`, `0031ac10`, `0031e5b0`, `0031fa20`, `00320b80`, `003218a0`, and
`00321e60`; combine `002f0f00` and `00304580`; provider `002b83e0`; and digit
draw `002ba080`. Each preserves its ordered call sequence and all neighboring
functions. These guarded bodies remain unpromoted, with their existing
nonmatching source limitations. All unrelated allocated data is unchanged.
Only the two combine drafts' own switch-table branch offsets change:
100 bytes/25 entries and 84 bytes/21 entries respectively, both with alignment
16 and the same relocation structure. Production tables are unchanged.

## Actual-source verification

Compiler: `D:/mwcps2-3.0.1b210-060308/mwccps2.exe`, configured `-O2 -Iinclude`.
Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

`func_0032fbc0` is exact after all 32 relocations are resolved: 1180 code bytes
in the 1184-byte retail window, followed by four zero bytes. It owns no data.
Resolved SHA-256:
`a81c8290277d94e3edfa328b412b2064a892b46c496692dcdabff5f873a5d1dc`.

The actual source build calls the official verifier and reports:

| Owner | MATCH | ASM | Other functions unchanged |
| --- | ---: | ---: | ---: |
| `src/Event/Fcl/y_fclCombineDraw.c` | 46 | 24 | 69 |
| `src/Event/Fcl/y_fclCombine.c` | 26 | 15 | 41 |
| `src/promoted/y_draw.c` | 54 | 4 | 58 |
| `src/promoted/code1_002b.c` | 72 | 3 | 75 |

All 243 other functions and their relocations compare equal, and every
production allocated-data section compares equal. Ten protected draw targets
also receive fresh complete relocated proofs from these actual objects:
`0031d630`, `0031ddf0`, `0031e320`, `00316470`, `003297f0`, `0032a960`,
`0032b000`, `0032f4d0`, `003233d0`, and `00324410`.
`002b6af0` independently proves exact at 68/80 bytes with twelve zero tail
bytes and two resolved relocations.

The scoped five-file integrity scan passes with zero errors and six existing
H003 optimization-pragma advisories. `git diff --check` passes for the package's
production owners and header. The integrated draw's comment/indentation cleanup
and the provider's removed final blank line are recorded explicitly; their
C tokens and complete code/data remain equal to the reviewed proposals.

## Reproducible artifacts

All artifacts are under
`build/first-party-finish-20260920/fcl-current-work/`.
`delivery-grid/closure-proof.json` and `guarded-callers.json` retain the original
completed jobs. `audit_grid_resume.py` checks their compiler, source, header,
object, relocation, and guarded-data identities without invoking a compiler;
its extended receipt is `delivery-grid/resume-full-audit.json`.

`seal_grid.py` performs the official actual-source verification and writes
`delivery-grid/current/proof.json`. Each of the four owner subdirectories
contains the compiled source, actual object, compile receipt, official results,
and code/data proof. The draw and provider directories additionally contain
the fully relocated binary windows. The scoped lint receipt is
`delivery-grid/current/lint.json`.

The seal reuses completed jobs only after checking source, compiler, flags,
dependency, and object hashes. It refuses to overwrite an unreceipted object.
This recovery does not modify the prime-owned publication worktree.
