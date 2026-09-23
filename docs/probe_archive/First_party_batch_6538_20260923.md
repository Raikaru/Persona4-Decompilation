# First-party recovery checkpoint: 6,538 MATCH / 322 ASM

This batch preserves and publishes 24 first-party C recoveries accumulated after
`42c8c93`. The complete first-party population remains 6,860 functions across
292 native owners. No function is removed or reclassified to obtain the count.

| Owner | Newly recovered functions | Installed first-party result |
| --- | --- | --- |
| `src/cmmRankUp.c` | `00252710`, `00252a60`, `00253850`, `00254a70`, `002566d0`, `00256be0`, `002570f0`, `00257900`, `0025b240` | 26 MATCH / 0 ASM |
| `src/promoted/code1_0015.c` | `001561a0`, `00156800`, `00157310`, `001582f0`, `0015b3e0` | 67 MATCH / 1 ASM |
| `src/promoted/code1_0020.c` | `00202e70`, `00203930`, `00209fa0`, `0020ff00` | 143 MATCH / 3 ASM |
| `src/promoted/code1_0021.c` | `00210c70`, `00212270`, `002142b0`, `00216e60`, `0021be80` | 108 MATCH / 0 ASM |
| `src/promoted/code1_0038.c` | `00389640` | 78 MATCH / 12 ASM |

The rank-up and battle-panel owners are complete. Their recovery includes the
real private interpolation leaf, canonical independent integer/float argument
streams, complete matrix/vector/UV/color objects, animation phases, and native
dispatch tables. Providers and callers were updated together. The four battle
menu functions retain their actual work-buffer, drawing, and callback contracts.
The opacity callback uses the established byte-opacity interface consistently
across its first-party callers.

The field functions retain the original loader states, room-list count, signed
coordinate domains, map-template storage, and recursion behavior. The original
unwritten recursion-depth path in `0015b3e0` is documented in
`First_party_batch_6531_20260922.md`; this result is a native retail match, not a
claim that that original behavior is portable or fully initialized C.

## Native source and linked-image validation

The installed-source checkpoint is
`build/finish-first-party-20260922/continue-13-publication/opacity/installed-closed.json`.
It records every owner's source, compiler, flags, recursive inputs, native
object, and official verifier result. The continuation authenticated all 292
owners and 758 source inputs against the actual current files before publication.
The complete census contains only MATCH and ASM statuses.

All 24 new targets also passed independent full relocation, owned-data, and
zero-tail proofs from those authenticated native objects. The final proofs are
under `build/finish-first-party-20260922/continue-14-publication/proofs/`.
For example, `00252710` is 836/848 bytes with 12 resolved relocation records;
its final 12 retail bytes are zero alignment.

The completed full build is retained under
`build/finish-first-party-20260922/continue-13-publication/full-build-6538/`.
Its source snapshot matches the current source and tooling with no drift. Both
the recorded build and the actual retained output pass:

* Load image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`.
* Complete `SLUS_217.82` SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

All 24 new functions occur in the successful C-link report. Previously linked
first-party functions are preserved; the first-party C-link count increases from
1,825 to 5,801. The remaining difference between source matches and C linkage is
not counted as additional recovery.

## Linker support

GNU ld is the configured backend, with MWLD still selectable. The GNU path can
place separate sections from an original native object around foreign function
ranges, preserving local literal references. Identical shared literal atoms use
validated GNU merge metadata without changing native instruction, data, symbol,
or relocation payloads. Source definitions remain section-backed; fallback
addresses cannot shadow them. See `docs/gnu_linker.md` for the exact checks.

The previously completed 61 linker/build/cache tests match the current tooling
hashes and have no failures or skips. An additional current run passed 62 symbol,
marker, and origin tests. Focused integrity lint passes with advisory warnings.
The earlier 780-test Linux suite's five host-path failures were separately
rerun successfully with corrected paths; its three native compiler skips were
covered by successful native checks. Its report-shape class remains skipped
because no full verifier report was present at its conventional build path.

`continue-14-publication/authenticated.json` and `checks.json` bind these results
to current files, native objects, test logs, output hashes, and the complete
remaining-function inventory. Completed compiler and full-build jobs were not
replayed to recover missing terminal history.
