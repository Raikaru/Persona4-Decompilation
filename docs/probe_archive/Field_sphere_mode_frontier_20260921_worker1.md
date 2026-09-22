# Field sphere mode contract: 24 to 14 differing words

Worker 1, September 21, 2026. This continuation began at
`5a1bcf7e889d9b1fb1560201d686669739014501` after the upstream rebase.
All new compiler outputs and proposals are under
`build/complete-20260921/field`. No production C, header, config or tool file was
edited by this lane. The separately prepared `0016b8a0` ray-query proposal remains
under prime's integration ownership.

## Result and acceptance status

The defined mode-one callback frontier improves from **24 to 14 differing
resolved words**. It emits **1668/1680 bytes**, resolves all **eight relocations**,
and has a twelve-byte retail zero suffix. The improvement is in
`00169a30/facing-normal-y-snapshot`.

`00169a30/defined-sphere-query-frontier` combines that callback with the previously
sealed native `func_0016abc0` query and its provider declarations. The query still
reproduces **1216/1216 bytes and 30 resolved relocations**. The other fourteen
original siblings preserve their bytes and relocation meaning, and allocated
owner data is unchanged. Every sibling of the nonmatching callback has a complete
resolved proof. The callback and query own no target data.

The unchanged standard verifier, using this source-bound completed owner object,
reports **14 MATCH / 1 MISMATCH / 1 ASM**. Only `func_00169a30` is MISMATCH.
This is **not an accepted recovery or an integration-ready patch**. Replacing the
current exact callback with this frontier would regress a native function.
`comparison-only.patch` is retained for review and continuation; do not apply it
to production. The sphere-query acceptance hold remains in effect.

Combined source SHA-256:
`6f68c10902f59643b6e998b3e753351e7ac7fa3125ceacbb91422863537f064d`.
Combined owner object SHA-256:
`8cdab6957205b95409750d4acd1c8090504adece3e8563346395097b0b955854`.

## Source mechanism and residual

Mode-one sphere queries do not initialize the collector's direction. The existing
callback computes a direction projection before checking the mode. Earlier
defined proposals placed the projection under `mode == 0`, but lost the lifetime
of the transformed normal's Y component across that branch.

The new proposal snapshots `ny = normal.y` before mode dispatch. The guarded dot
product and the following independent slope filter both consume that real value.
No call or write to the normal occurs between capture and use. Direction remains
unread in nonzero modes; no initialization, memory barrier, volatile access, fake
side effect or assembly computation was introduced.

This restores the normal-Y load at `+0xE0`, the slope-filter register at `+0x12C`,
and all later instructions. The only remaining differences are the fourteen
consecutive words from **`+0xE4` through `+0x118`**. Both versions perform the same
projection in mode zero, but their machine-code ordering differs:

* Retail loads the direction and computes the float comparison before loading
  and testing mode.
* The defined candidate loads and tests mode before reading the direction and
  computing the float comparison.

The remaining task is to reproduce retail's scheduling from a source form that
does not evaluate an unwritten direction in nonzero modes. Neither a source-level
uninitialized read nor invented query initialization is an acceptable closure.

## Completed measurements

Each row is a new whole-owner compile with immutable source, object, command,
input manifest, comparison and relocation receipts. Completed earlier jobs were
not rerun to recover output.

| Target / label | Emitted/window | Differing words | Alignment edits |
|---|---:|---:|---:|
| `00169a30/facing-conditional-result` | 1696/1680 | 360 | 19 |
| `00169a30/facing-merged-result` | 1688/1680 | 364 | 17 |
| `00169a30/facing-accepted-result` | 1700/1680 | 349 | 19 |
| `00169a30/facing-normal-y-snapshot` | 1668/1680 | 14 | 10 |
| `00169a30/facing-projection-code-motion` | 1700/1680 | 316 | 316 |
| `00169a30/defined-sphere-query-frontier` | 1668/1680 | 14 | 10 |
| `0016a110/pair-projection-register-lifetime` | 2124/2128 | 15 | 16 |
| `0016a110/pair-stop-operation-contract` | 2144/2128 | 61 | 46 |

The code-motion control was discovered in the configured compiler and measured
with unknown-pragma warnings enabled. Its output was worse and is not retained in
the preferred source. `compiler-control-spellings.json` is discovery evidence,
not proof that every listed control is recognized or useful.

The two dynamic-query hypotheses did not improve its existing 12-word frontier.
That result remains `build/finish-current-20260921/field/0016a110/`
`wake-reviewed-native-frontier`: 2124/2128 bytes, 39 resolved relocations, four
zero tail bytes. Its separate complete-work distance reads remain preserved.

## Authentication and review evidence

The current field owner is SHA-256
`ae3f5d2d77c7a9734380152602ac47b84f2e76e07bf5862fc986791ec45b07e8`.
Its transitive includes, effective `-O2 -Iinclude` profile, b210 compiler and
assembly inputs agree with the saved production owner. All sixteen saved owner
functions were resolved again without recompilation. New frozen input manifests
record the rebased tree, including unrelated CRI/GCC profile and header changes;
these are not silently equated to the previous whole-header corpus.

The effective compiler is MWCCPS2 b210, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
`00169a30/production/binding.json` records the reused production object, actual
owner dependencies and the inspected non-owner input changes.

The combined proposal contains `HANDOFF.json`, `compile.json`, `result.json`,
`proofs/`, `official/verify.json`, `lint.json` and `comparison-only.patch`.
`git apply --check --whitespace=error-all` passed. Scoped lint exited zero.
These review checks do not turn the nonmatching callback into an accepted change.
`FINAL_HANDOFF.json` and `run-index.json` in the lane root bind the final artifacts.

No full build, global test suite, commit or other Git mutation was run. Agent
messaging returned `AGENTS_BUSY: no agent family belongs to this conversation`;
the durable handoff provides the result independently of that route.
