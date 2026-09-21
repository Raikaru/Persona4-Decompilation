# Resumed first-party campaign: 77 verified recoveries

The interrupted work was authenticated in
`build/finish-current-20260921/initial.json` before changing production files.
All 410 saved compiler objects match their source and object receipts. All
77 additional first-party C functions since `0360227` were independently
relocated again from those objects, including referenced owned data. No
compiler was rerun merely to recover missing terminal output.

The completed `build/campaign-checkpoint/resumed-77` report contains
**6,453 MATCH and 408 ASM first-party functions out of 6,861**. The complete
program report contains 8,223 MATCH and 4,879 ASM functions out of 13,102.
The checked source fingerprint is
`216254b014ead02258913371cafbe8a4ed18adfae27dd00dbc9a491da52fe62a`.
The completed test, lint, and build receipts carry that same fingerprint.

## Fifteen recoveries beyond the previous committed checkpoint

The previously committed first-party campaign ended at 62 additional C
functions. The following fifteen completed recoveries were still present as
uncommitted source when this turn resumed:

| Area | Recovered functions |
| --- | --- |
| Battle camera and formation | `001d07e0`, `001d1680` |
| Field queries | `00169320`, `00169a30`, `00169780` |
| Encounter and field AI | `00161630`, `0017ed40` |
| Battle panel | `00206dd0`, `00205170` |
| Event and Scene | `00288170`, `00288af0`, `0026a020` |
| Fcl drawing | `003212e0`, `00330060`, `002b83e0` |

Their individual source/interface explanations and measured controls are in
the corresponding September 21 recovery notes in this directory. The latest
`002b83e0` integration includes its five-owner/header closure under
`build/next-wave-20260921/integration-77`. The generic owner verifier and the
unmasked proofs both operate on the actual integrated source, not just the
earlier isolated candidates. Unfinished motion, dynamic-field, Event, and Fcl
frontiers are not included in this count.

The required shared-interface changes are retained with their callers. The
EE-GCC support fixes preserve relative header layout, explicitly select the
EE ABI when assembling 64-bit loads/stores, retain 32-bit pointer/arithmetic
pseudo-instructions, and use the existing native/WSL binutils discovery.
Their regression tests and completed compiler receipts are preserved. The
separate CRI server-call correction names the actual retail worker instead
of conflating two different decoder entries.

## Encounter linkage correction

The completed pre-resume build linked 174 C objects and 56 Sony SDK objects,
and both its loadable-image and executable SHA-1 values matched retail.
Comparing its actual linked-owner set with the preceding checkpoint revealed
one hidden regression: `k_fldData.c` became eligible while `k_encount.c`
dropped out. An unchanged total object count and exact retail hashes did not
establish that every recovered owner remained linked from C.

The encounter owner had only one unresolved reference: `iGpffffb418` in the
new `00161630` C body. Retail loads this table pointer at `00161774`,
`001617a4`, `001617d4`, `00161814`, and `00161914`, using GP displacement
`-0x4be8`. With the configured GP `0x007690f0`, the address is `0x00764508`.
All five relocations were independently applied and checked against retail.

The alias is now present in both the curated data-symbol input and recovered
linker symbol map. The saved eligibility proof shows that this one addition
restores all six functions in the encounter owner, with identical executable
bytes, allocated data, and text layout. Actual post-edit assessment confirms
the same result. The private evidence is
`build/finish-current-20260921/link/encounter-alias-proof.json` and
`encounter-actual.json`. The earlier 174-object build receipt remains an
explicit pre-correction result; it is not relabeled as a new full build.

## Preserved inputs and further work

The existing dirty source, headers, tests, and notes were copied under
`build/finish-current-20260921/before` before this turn's edits, with both
working-tree and index patches. Earlier worktrees remain intact. Source and
compiler identities for each resumed target are recorded separately from
its score, and an ASM fallback is never counted as recovered C.

The continuation starts from 408 assembly-backed first-party functions. New
proposals must finish real provider/caller contracts, preserve neighboring
functions and owned tables, and retain C-link eligibility before acceptance.
