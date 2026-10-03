# Largest Title controller: remaining raw GP color and fullscreen transport

Base: `1e0890133eeeb90c482cfbcedd24a6d5ce090645`.
Only guarded `func_001265a0` production-source text changes. The assembly
fallback stays enabled. No matching promotion or full-controller proof is
claimed.

## Six actual color words

The six remaining GP-color loads had numeric float-to-s32-to-float wrappers.
Their retail data are packed RGBA words, not quantities to round:

| GP symbol suffix | Address | Raw word |
|---|---:|---:|
| 9C70 | 00762D60 | FF000000 |
| 9C74 | 00762D64 | FFFFFFFF |
| 9C78 | 00762D68 | FFFFFFFF |
| 9C7C | 00762D6C | FF000000 |
| 9C88 | 00762D78 | FF000000 |
| 9C8C | 00762D7C | FF41EBFF |

The old numeric conversions could not preserve these words and are undefined
C for the actual NaN/out-of-range floating representations. The source now
retains their raw floating-register copies into the existing shared color
union's `.value` member. No byte channel is numerically interpreted during
the copy. The existing backup scalar assignments stay in source; the compiler
elides their unused stores and directly copies each GP word to shared SP+4FC.
This is reported rather than forcing dead stack stores into the output.

The four fullscreen calls also use the actual provider declaration:

```
void func_0045c870(u8 *colors, s32 enabled);
```

Each passes the same shared color and enabled=1. The old s32 return declaration
is removed locally; no return value is invented. The other two GP colors feed
existing layer calls, whose previously accepted canonical arguments remain
unchanged. No provider definition or matching sibling is edited.

The audit validates all six retail constants, GP load/backup/shared-store
chains, candidate immediate raw GP load/shared-store pairs, all four
fullscreen setups and the actual provider's a0/a1 prologue. An exact source
reconstruction accounts for all six removed numeric wrappers, the one local
prototype and the four corresponding pointer casts; no other C edit is hidden.

## Execute actual copy chains and actual draw providers

The fixture extracts each actual three-statement copy chain, declarations and
its associated following fullscreen or layer call expression. It executes
the real fullscreen, layer and vertex providers. Their camera lookup, state
API and draw endpoints are controlled boundaries.

At O0 and O2, **6,234 cases** cover six copy chains, every byte value in every
channel and fifteen special representations, including both infinities,
quiet/signaling NaNs, signed zero and signed normal/subnormal boundaries.
Canaries surround the shared color and each backup scalar. Initial copies
must preserve the complete word and leave the GP input unchanged.

The camera boundary changes one alpha bit in the expected shared object
before the provider reads its channels. Rendering must observe that mutation,
while the equal-byte backup and GP source stay unchanged. A wrong-object
control therefore fails even if the substituted backup initially contains
identical bytes. This is a controlled opaque-call mutation, not a claim that
the actual camera provider changes caller colors.

All defined fullscreen vertex coordinates, depth, inverse scale and RGBA
channels are checked, along with strict interleaved state get/set operations,
Sky settings, draw and restoration. The fullscreen provider intentionally
leaves other vertex words unwritten; the fixture does not inspect those
unspecified fields. Layer geometry uses prepared bounded rectangle inputs;
its separate coordinate-construction proof remains in the prior suites.

Seven controls reject numeric GP conversion, wrong shared copy, disabled
fullscreen state handling, an equal-byte wrong color object, missing alpha,
wrong fullscreen width and swapped get/set order. The numeric-conversion
control rejects a defined tiny positive input before reaching cases where
the old conversion would be undefined.

All current Title suites pass **16 tests without skips**. The earlier alpha
fixture was strengthened in prerequisite test-only commit `9a19df77` with explicit rectangle-pointer identity and
an equal-payload wrong-rectangle control. It now covers the actual dynamic
selection boundary **frame25**, all frames25–85 and controlled sine +1 for
every selected frame: 16,508 call cases plus the same 2,537 conversion cases.
Its original frame26–85 corpus was narrower than that local selector, which
is separately pinned at retail 00129394. No alpha production expression is
changed by this fixture update.

Native source/provider contracts are not actual renderer, trigonometric
library, EE FPU, whole-controller or gameplay execution.

## Complete-owner preservation and intended entry changes

Fresh base/final production and guarded builds preserve the complete
production object byte for byte, all 81 guarded siblings, all 420 non-target
allocated data bytes and all non-target references. All thirty layer argument
setups and the prior fifty-object/26-loop storage proof rerun; the two alpha
objects and expressions are untouched by the exact source edit inventory.

The target table's sixteen entries retain their alias groups. Entries0–3
intentionally change their first instructions because the erroneous numeric
GP conversions are removed there. The proof checks those exact old/new
prefixes: case0 retains its counter reset, cases1/2/3 load the same named GP
symbol and now directly store/pass the raw color. Every other prefix word and
prefix relocation is unchanged. Raw target-prefix identity is not claimed.

Caller/provider owners remain **148 MATCH / 1 ASM**, with zero lint errors
and 32 existing warnings. The guarded body is **17,404 bytes / 3,959 differing
words**, with its unchanged 0x500 frame, versus 17,452 / 3,941 at base and the
17,616-byte retail window. These are still nonmatches, not match credit.
Other callback/type/dataflow and decompiler-expression work remains. No
aggregate image pass, remote CI or push is claimed.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_gp_color_transport_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_gp_color_transport_001265a0_20261003/audit_color_storage.py
python docs/probe_archive/Title_gp_color_transport_001265a0_20261003/audit_layer_calls.py
python docs/probe_archive/Title_gp_color_transport_001265a0_20261003/audit_gp_colors.py
python docs/probe_archive/Title_gp_color_transport_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Omit the explicit runner only for working direct i386 execution. Skips remain
unverified. Whole disassemblies and compiler objects are excluded from the
committed source-only evidence and delivery archives.
