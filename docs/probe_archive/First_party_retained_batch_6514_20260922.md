# Installed first-party recoveries after b287c53

Four retained proposals are installed and bound to current-source native and
official verification. They advance the first-party source census from
6,510 MATCH / 350 ASM to 6,514 MATCH / 346 ASM. These counts describe compiled
function matches; whole-image source placement is checked separately.

| Function | Emitted / retail window bytes | Resolved code relocations | Recovery |
| --- | ---: | ---: | --- |
| `func_00487c30` | 892 / 896 | 21 | Final particle update |
| `func_001b6120` | 1968 / 1968 | 100 | Battle camera and geometry setup |
| `func_001496c0` | 1504 / 1504 | 14 | Scene resource, clear and fog colors |
| `func_0016abc0` | 1216 / 1216 | 30 | Field sphere contact query |

Every listed instruction and relocation matches retail. The particle update's
four remaining bytes are verified zero alignment; the other three functions
occupy their complete windows. No vendor implementation is changed.

## Particle update

The complete `src/promoted/effParticle.c` owner now reports **17 MATCH / 0 ASM**.
The update uses the real particle cursor, subtype-specific state and checked
matrix/vector storage. The retained proposal includes coherent declarations for
the seven providers it calls. All existing particle functions and all three
owned renderer/dispatch tables retain their bytes and relocation meanings.

The saved proposal predates the newly proved GP linker definitions in b287c53.
Its old installed-source gate therefore correctly rejected that changed proof
input. A new native compile of the actual installed owner and official check
closed the current state without changing the old receipts. The new object is
byte-identical to the previously proved proposal:
`e2b49e4ecae940d7bb60383705a5fb371f4a9f4f6e275588b985b2aa87ddd797`.

Current receipt:
`build/finish-first-party-20260922/continue-particle-installed-01/completed.json`.
Original proposal:
`build/finish-first-party-20260922/particle-next-03/installation/manifest.json`.

## Camera and shared geometry interface

The camera package includes the geometry provider and all affected callers,
using one declaration in `effect_geometry_internal.h`. The two palette users
share complete four-byte objects through `btl_camera_palette_internal.h`.
Actual getter return types and explicit pointer conversions preserve the
already matching callers. The saved eight-owner proposal was authenticated
against current compiler, headers, assembly inputs and object hashes before the
official verifier reused those objects for the installed sources.

Only three frozen input entries needed recorded successor bindings: the two
GP symbol maps proved and linked in b287c53, and the separately closed particle
owner. All other frozen inputs remained checked. The gate retains 15 complete
function proofs and 544 unchanged other functions from the original proposal.

Current receipts:
`build/finish-first-party-20260922/continue-camera-installed-01/successor-inputs.json`
and `scored/completed.json` below that directory.

## Color and sphere family integration

The unsigned byte clear-color setter is reconciled with its actual callers.
The resource-color function now uses the complete four-byte snapshot, the real
four input factors, unsigned float conversions and the original upper clamps.
The sphere query uses the shared collision collector, complete intersection
storage and separate traversal/contact lifetimes.

The old color package included two unrelated damaged UTF-8 comment changes.
Those hunks were omitted. Its code1_001b changes were merged into the newly
closed camera owner instead of replacing that owner with a stale full-file
copy. Nine actual installed owners were compiled and checked; all unaffected
function bytes, relocation meanings and allocated data remained unchanged.
The combined camera function was proved again in the merged owner.

Current preparation and closure:
`build/finish-first-party-20260922/continue-retained-installed-01/manifest.json`
and `completed.json`. Original evidence and complete ABI review remain under
`build/finish-first-party-20260922/retained-worker6-01/`.

## Original retail omissions

The camera's reserved matrix padding and the sphere callback's unused or
unwritten fields retain the directly evidenced retail behavior described in
`Battle_camera_setup_001b6120_20260922_worker7.md` and
`Retained_color_and_sphere_20260922_worker6.md`. These instruction proofs do not
claim those original paths are free of uninitialized C state. No new runtime
invariant or gameplay observation is asserted to exclude them.

The publication census and full-image checks for these installed sources are
recorded under `build/finish-first-party-20260922/continue-batch-6514/`.
