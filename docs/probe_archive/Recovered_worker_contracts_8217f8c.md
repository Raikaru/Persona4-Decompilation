# Recovered worker contracts on upstream 8217f8c

The September 20 recovery starts from upstream
`8217f8c0d309a5ad1467295e9a4395decd3ec00a`. Earlier worktrees and their
uncommitted files are preserved. Recovery is assembled separately in
`build/recovered-upstream`, after rebasing the retained Fcl and battle commits.

## Existing matches and missing local corrections

Upstream already contains the earlier C recoveries for `001eca10`, `001c79f0`,
`0025dd30`, `0015d310`, `00152170`, `00242990`, and `003233d0`. Their older
drafts were not substituted for current upstream source. The following saved
contract corrections were still absent and were recovered independently.

### Frame transform and field callbacks

`src/rw/rwcore_grouped.c` now gives `func_003e9cb0` all three of its actual
arguments: frame, transformation matrix, and combine mode. It explicitly
forwards the matrix and mode to `func_003e0e20`, with the frame's matrix at
offset `0x10`. The existing dirty-list updates, flags, and returned frame
remain in order. The old one-argument declaration and call relied on incoming
register contents for the other arguments.

`src/Kosaka/Field/k_fldResource.c` uses the active providers' actual return
types and parameter types for the resource getters, world/light operations,
camera wrappers, frame transform, and render-state setter. Explicit casts
preserve the existing EE word representations. Callback registration order,
light-color copies, the complete matrix copy, and packed unsigned color
shifts are retained.

Fresh configured compilation on the rebased checkout proves complete object
identity against upstream for both files: 223 functions in `rwcore_grouped.c`
and 21 in `k_fldResource.c`, including their symbols and relocations. Separate
unmasked target proofs give:

| Function | Executable/window bytes | Resolved relocations | Unchanged siblings |
| --- | ---: | ---: | ---: |
| `00152170` | 1212/1216 | 60 | 20 |
| `003e9cb0` | 148/160 | 3 | 222 |

The remaining suffixes are retail zero alignment. These corrections do not
claim that every legacy RenderWare declaration in other source files has been
reconciled. They recover the reviewed provider and field-owner changes.

### Rank-up tables and primitive submission

The two 16-entry position tables in `cmmRankUp.c` retain the saved `const
CopyPair` declarations. The submission prototype is reconciled to the active
`sdkPrimitive.c` definition: two `s32` address arguments and an unsigned
vertex count. Both guarded callers explicitly preserve their buffer addresses
through `(s32)(u32)` casts. The earlier saved `const void *` prototype was an
intermediate proposal and is not the accepted declaration.

The active rank-up object remains completely byte-identical across all 26
functions. Separately enabling the two affected guarded drafts produces:

| Draft | Before/after bytes | Changed instruction words |
| --- | ---: | ---: |
| `002561f0` | 576/576 | 7 |
| `00256460` | 612/612 | 7 |

Both retain identical relocation records, call order, and allocated data.
Neither is promoted to C. The changed argument setup reflects the canonical
integer-address declaration; equality of the guarded instruction streams is
not claimed.

### Camera constant symbols

The four saved float aliases are restored in both the curated data-symbol
input and recovered symbol map. Existing aliases remain present.

| Symbol | Address | Retail reference in `001c79f0` |
| --- | --- | --- |
| `fGpffff812c` | `0x0076121c` | `001C7C2C`, GP minus `0x7ED4` |
| `fGpffff8130` | `0x00761220` | `001C7DC0`, GP minus `0x7ED0` |
| `fGpffff8134` | `0x00761224` | `001C7DC4`, GP minus `0x7ECC` |
| `fGpffff8138` | `0x00761228` | `001C7E18` and `001C7E74`, GP minus `0x7EC8` |

The configured GP is `0x007690F0`. Fresh independent resolution proves the
current camera function at 1792/1792 bytes with all 59 relocations resolved,
62 unchanged siblings, and two unchanged allocated data sections. No camera
instructions were edited for this recovery.

## Retained evidence

All new measurements above are under `build/recover-upstream/` in the recovery
checkout. `contracts/<owner>/before.c` and `before.o` preserve the current
baseline. `check_contract_objects.py` records complete-object comparisons;
`rankup_guarded.py` records both dormant callers separately. Individual
unmasked proofs are in `verified/<address>/proof.json`.

`older-final-verify.json` records the official four-owner run: 333 functions,
137 MATCH and 196 ASM, with no unexpected status. Its first-party subset is
83 MATCH and 27 ASM. These are scoped results, not a whole-project build claim.

The older 74-owner SDK-registration proposal and UI parameter-order experiments
remain preserved under `build/match-next-latest/build/all-first-party/`.
Their active-object comparisons alone do not finish the callback and
aggregate-type contract audits, so those broader migrations are not included
in this recovery. The SDK dispatcher still invokes callbacks through its
separate `KwlnTask *` declaration, while the proposal introduces a `u8 *`
transport declaration; no end-to-end callback-type recovery is claimed.
The UI experiment itself records remaining scalar/aggregate declaration debt.

The saved full first-party census contains no additional zero-word candidates.
An NTFS case collision between `KOC_00243a30_body.c` and `KoC_00243a30_body.c`
was kept out of the change set; the original Git blobs and worktree contents
are preserved. The malformed partial archive is not a recovered function.
