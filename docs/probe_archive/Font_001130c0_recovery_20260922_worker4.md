# Leading font glyph recovery: 001130c0

Worker 4, September 22, 2026. The assigned owner is
`src/promoted/code1_0011.c`. The configured native MWCCPS2 b210 compiler at
`-O2 -Iinclude` now reproduces `func_001130c0`, and the official scoped
verifier reports **46 MATCH / 1 ASM** across all 47 first-party functions in
the owner. The remaining ASM function is `func_00112830`.

## Change and mechanism

The earlier C candidate had five fully resolved differing words. Its color
reloads and inverse-opacity arithmetic were ordered differently from retail.
Moving the color reads earlier made their saved-register assignment worse.

The new private inline `fontDrawLeadingGlyph` performs the existing first
sprite draw. It snapshots blue and green, computes inverse opacity, passes
all eleven original arguments to `func_0046d4c0`, and returns the inverse
opacity consumed by the later digit loop. Keeping that return value live
across the real draw lets the native compiler emit blue and green reloads
before the arithmetic while retaining alpha in `$s2`, blue in `$s1`, and
green in `$s0`.

The helper is fully inlined. No call, side effect, compiler pragma, ordinary
assembly, dummy state, or global data was introduced. The source retains
the genuine 76-byte text buffer followed by its four-byte color object.
The superseded target-floor comments and ASM fallback were replaced; the
entire old target region is retained in the scratch evidence.

## Behavior and interfaces

The target and its caller retain their existing
`(Vec2f, f32, s32, u8 *, s32)` interface. Only the private helper accepts
opacity as `u8`: its conversion gives the same low byte as the original
`arg1 & 0xFF`, and `255 - opacity` stays in the defined range 0 through 255.
Both output pointers refer to distinct initialized scalar caches after
the helper writes them. The helper reads the fully copied color and the
initialized position; no pointer to these stack objects escapes through
the sprite interface.

The first-party sprite provider and its retail assembly establish its
integer, float, and byte argument contract. Its first draw still receives
the same texture, glyph `0x47`, X, Y plus 2, inverse opacity, RGB, depth,
and final mode. The formatter and length calls remain in their original
order. Blue and green are preserved across those calls; the loop keeps
its original red reloads, signed character loads, reverse digit traversal,
and 14-unit X steps. The width-table load remains after formatting.

The retail format at `iGpffff9bec` begins `%d\0`. Its signed 16-bit value
requires at most six characters plus the terminator, within the retained
76-byte buffer. The implementation retains the established input contract
for the external color and position tables; no new claim about arbitrary
out-of-range table indices is needed for this recovery.

Reviewed evidence includes the current caller `func_00112300`, the target,
caller, and sprite-provider retail assembly, the corresponding IDA and
Ghidra exports, `docs/STYLE.md`, and the existing
`docs/probe_archive/HnH_001130c0_body.c` and matching handoff notes.
Earlier Persona caller contracts and shared headers were preserved.

## Native validation

The fresh production baseline reproduced all 47 previously sealed function
bodies and relocation meanings, with all allocated data unchanged.
After the edit, an actual current-owner native compile and a separate
compiler invocation by the official verifier produce the identical object.

| Check | Measured result |
| --- | --- |
| Target code | 440 executable bytes in the 448-byte retail window |
| Unmasked relocations | All nine resolve exactly |
| Retail suffix | Eight true zero alignment bytes |
| Target-owned data | No owned data referenced |
| Siblings | All 46 preserve bytes and relocation meaning |
| Owner allocated data | Unchanged |
| Caller `00112300` | 712/720 bytes, 27 resolved relocations, eight retail zeros |
| Official verifier | 46 MATCH / 1 ASM; target is MATCH |
| Scoped integrity lint | Exit zero; no error findings |

Current source SHA-256:
`08099ce893ec9b74cad562373cf7ebc6e29612a436d0d45ca1ebcf3636e8bd06`.

Current native and official object SHA-256:
`edecbc4627bfdabfda09ad74e1656bab4a69a4fa688b3bdb30c3821609e7db7a`.

Resolved target SHA-256:
`3873ec7a6ac5e0234df4ab50af3269e73a8f1b5575e7666a9e5c216197ee444b`.

Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

## Retained proof and measurements

All new compiler evidence is under
`build/first-party-resume-20260922/font/`.

`integrated/compile.json` binds the actual source, native compiler, flags,
command, object, and inputs. `integrated/proof.json` contains the full
target/caller proof and sibling/data comparison.
`integrated/unmasked-proof.json` records all target relocation resolutions.
`integrated/official.json`, `official-completed.json`, and `official-owner.o`
retain the independent official verification. `integrated/accepted.json`
and `lint.json` record the accepted result and integrity check.

`prepared-owner/source.patch` describes this owner's bounded change;
`prepared-owner/historical-target-block.txt` preserves the superseded notes
and guarded body. `baseline-native/` retains the fresh original owner.
`draw-boundary-position-address/` is the first exact candidate.
Every executed probe retains complete source, object, compiler command,
log, unmasked comparison, and sibling/data evidence.

The new output/return helper hypotheses without the real draw retained five
or more differing words. A local byte-opacity conversion corrected operand
ordering but retained the five-word scheduling group. Parameter-lifetime
and register-hint alternatives did not close that group. Extending the
inline boundary through the first genuine draw produced the exact result;
the remaining planned draw variants were not executed after that success.
No archived exhaustive declaration or pragma sweep was repeated.

Only this owner and this new archive note were changed outside scratch.
No vendor implementation, shared header, compiler configuration, or tool
was edited. No full build, global test suite, commit, push, or Git mutation
was performed. Historical host sanitizer checks in earlier notes were not
rerun or counted as validation for this change. The earlier read-only audit
files remain an immutable snapshot from before this recovery.
