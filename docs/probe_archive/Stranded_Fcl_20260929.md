# Fcl recoveries retained in the September 27 and 28 worktrees

Three completed C recoveries were still local when `a72f5154` was published.
This integration combines their bodies and required interfaces with that
commit's newer sources:

| Address | Owner | Executable bytes | Retail window |
| --- | --- | ---: | ---: |
| `0030c3c0` | `src/Event/Fcl/y_fclCombine.c` | 12,584 | 12,592 |
| `002cdf80` | `src/Event/Fcl/y_fclShopDraw.c` | 13,836 | 13,840 |
| `002b77d0` | `src/promoted/y_draw.c` | 1,280 | 1,280 |

The two shorter functions have only zero alignment bytes after their
executable bodies. Each complete definition equals its retained recovery.
The Combine and Shop sources came from `build/matching-20260927`; the row
transition came from `build/publish-20260928`.

## Interface composition

The skill replacement provider `0010cd70` takes a signed-halfword previous
skill. Its definition and all declarations agree. The selector `00313690`
takes a signed-halfword index and returns the word consumed by its callers.

Color construction has one four-byte aggregate return and unsigned-byte
channel parameters. The animation interfaces declare all four scale values
and retain explicit delay narrowing at their call boundaries. In particular,
`002b6af0` takes an `s16` delay in its definition and both shared headers.
Combining the older row header's `s32` declaration with the Shop recovery
regressed `003191c0`, `0031fa20`, and `003218a0`; the consistent `s16`
contract removes that regression.

The source census compares all 13,102 canonical markers against committed
`a72f5154`, excluding generated candidates. It finds exactly these three
ASM-to-C changes and no reverse change: 9,541 to 9,544 C definitions,
including 6,721 to 6,724 first-party definitions. This comparison uses source
ownership rather than the older committed progress snapshot.

## Behavioral and source checks

The retained actual-source state and animation tests are now tracked as
`tests/test_fcl_state_contracts.py` and
`tests/test_fcl_animation_contracts.py`. All four tests pass without skips.
At each of `-O0` and `-O2`, they cover 591,570 state scenarios, 7,560 animation
transports, 1,024 color cases, and 4,096 flag queries. The separate retained
row fixture executes the current row body and helpers with real 32-bit
pointers and undefined-behavior/bounds traps. Each optimization passes
9,590 cases, 105,490 callbacks, and 115,080 buffer checks.

These fixtures control the external providers. They do not execute the
complete Combine/Shop state machines or the PS2 game engine.

Source lint reports no integrity errors and no new conflicting-declaration
warnings. Seven of the eight affected guarded owners compile with
`NON_MATCHING` enabled. The remaining owner, `y_fclCombineDraw.c`, has the
same 18 pre-existing aggregate/scalar conversion diagnostics on both the
parent and integrated sources; this change adds no guarded diagnostic.

## Publication verification and linkage

The final full verifier compiles all 862 owners carrying canonical markers
and checks all 13,102 functions: 9,544 `MATCH` and 3,558 `ASM`, with no
mismatch or compilation error. First-party code has 6,724 matches and 137
assembly fallbacks. The source, header, fallback assembly, configuration and
tool input hashes are unchanged through that run.

The complete build links 601 compiled C objects and 54 residual Sony SDK
objects. All three recovered functions appear in the final linked report
under their C owners. Their executable sizes remain 12,584, 13,836 and
1,280 bytes respectively, with 347, 462 and 47 relocations. The final
executable and its linked load segment both reproduce retail:

| Output | Verified SHA-1 |
| --- | --- |
| Linked loadable image | `3d1d3d2b9d6ccb60836db239ab49674223025a78` |
| Complete `SLUS_217.82` | `4eeec0360cf2715535d9f7e52eb69d786fb0158c` |

The refreshed progress snapshot reports 4,112 fully C-linked functions.
That measure excludes mixed owners that retain assembly fallbacks; it is
separate from the physical C membership checked for these three recoveries.

The older committed snapshot also predates changes already present at
`a72f5154`. The link-membership differences for `code1_002a.c` and
`code1_0036.c` concern unchanged sources and headers. An independent compile
of the parent's `shdPersona.c` produces the same complete object as the
integrated version: all 102 functions and relocations are preserved, including
the pre-existing unresolved `D_007611AC` that excludes that owner from the
link. These older snapshot differences are not losses introduced by this
recovery. The comparison is retained in `parent-link-snapshot/receipt.json`.

The verifier's whole-owner compilation and comparison run concurrently,
then use its normal report and exit checks. The build uses the repository's
compiler, assembly preparation, placement and linker implementations; a
task-local persistent WSL connection removes repeated tool-launch overhead.
No source matching or final image check is bypassed. Compiler objects reused
for linking are authenticated against the current build action keys and
prepared with the existing `progbitsify` step.

The final reports are `build/stranded-20260929/verify.json`, `linked.json`,
and `final-validation.json`. Compiler-input and per-owner object receipts
are in `parallel-verification/`; the build log and tool identities are in
`build-transport-final.log` and `build-transport-final-receipt.json`.

Validation receipts are retained under
`build/stranded-20260929/worker-native/` and
`build/stranded-20260929/worker-review/audit-v1/` in the publication worktree.
The normal reproduction commands are:

```sh
python -m unittest discover -s tests -p 'test_fcl_*contracts.py' -v
python tools/verify.py --json build/verify_report.json
python tools/build.py --progress-report build/linked_report.json
```
