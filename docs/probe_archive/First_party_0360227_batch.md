# First-party recovery batch from 0360227

This batch started from `0360227d0a4194cb84500a5cf63ac554b38a79c2`, whose
complete verifier had 6,376 matching first-party functions and 484 assembly
fallbacks. The older worktrees and their unfinished source were preserved.

## Accepted C recoveries

| Function | Executable / retail window bytes | Resolved code relocations | Verified owned data |
| --- | ---: | ---: | --- |
| `001a4800` | 1148 / 1152 | 39 | Complete 52-byte, 13-entry switch table |
| `002411a0` | 2588 / 2592 | 70 | Existing allocated data unchanged |

Each four-byte suffix is verified zero alignment. Both functions are ordinary
unguarded C in their current owners and have passed the official verifier.
Their unmasked relocation proofs compare against the actual retail executable,
not against an assembly fallback compiled as a candidate.

The action recovery finishes the saved loop/state-access candidate and makes
`001f3870` return its actual allocated packet. Its eleven callers use the same
pointer/unsigned-byte contract. The initializer and destructor now have the
actual byte-pointer callback type used by their dispatchers; the updater's
existing word-returning callback type already agrees. Typed function-pointer
slot stores replace casts through `void *`. The factory and all three concrete
callbacks retain exact instruction bytes. Existing active functions and data
in all five affected owners remain unchanged except for the recovered target.

The battle calculation closes its sixteen-word register residual by moving the
`idx` declaration immediately after `lvl`. Its searches, random calls, arithmetic
and callback order remain unchanged. The full-owner comparison preserves all
79 neighboring functions and allocated data. Its real guarded caller now has
the matching five-argument declaration.

Detailed source/caller evidence and final hashes are in
`Recovered_Action_001a4800_20260920.md` and
`DC_worker3_20260920_recoveries.md`. The former records separately enabled
guarded callers as well: three change instruction streams under their corrected
contracts and remain assembly-backed. Their scores are not counted as new
matches or universal improvements.

## Retained near-match improvement

Camera shake `004a7830` improves from 19 relocation-masked / 20 fully resolved
differing words to seven, at 532/544 bytes. Keeping the random call and both
amplitude reads in the same expression reproduces the retail step calculation.
The remaining differences only select float registers around the magnitude and
sign test. Its real random/camera declarations and two-float output storage were
also corrected; all active owner functions remain unchanged.

The sixteen relocations and complete eight-byte constant pair were independently
resolved. The function still uses its assembly fallback. See
`Shake_004a7830_0360227.md`; the unsuccessful five-word polygon-movie work is
recorded separately in `func_0028fc40.md`.

## Exact instruction candidates still pending integration

`00238940` now has a zero-word 3728-byte candidate, with all sixty code
relocations and the complete forty-byte jump table resolved. Its required
`0023d8e0` provider-width correction still changes three existing caller
contexts: `001da5f0`, `001138c0`, and `0020b6d0`. The datScript `00245030`
caller is solved: a real pointer conversion preserves its complete object,
5152-byte function and 140-byte table under the wider declaration. That source
and proof are archived. Production keeps the original `u16` skill formal and
the status function's assembly fallback. See
`DC_worker3_00238940_exact_pending_callers.c` and
`datScript_00245030_wide_provider_0360227.md`.

The Fcl initializer `002e8410` and five creator return corrections also reproduce
retail in the staged proposal, but the SDK callback API is not closed. Independent
source/ELF inventories account for all 241 direct registrations and 400 callback
roles; 132 roles across 58 owners still have incompatible definitions. The
actual bounds-packet prefix also requires a representation audit. The complete
pending source patch, headers, input hashes and review are preserved in
`Fcl_initializer_002e8410_0360227/`. No partial SDK migration is installed.

The original pending C bodies and their original manifests remain intact.
None of these pending candidates is counted among the two accepted recoveries.

## Verification evidence

Current-source target, callback, caller and data proofs are retained under
`build/first-party-0360227/`, including `action/prime-final/proof.json`,
`action/prime-guarded/proof.json`, `action-callbacks/current-proof.json`,
`datcalc/integrated411/proof.json`, and
`shake/004a7830/integrated/proof.json`. `final/proof-audit.json` checks their
source identities against the final working tree.

The full local retail build passes with **172 C objects and 56 Sony SDK objects
linked**, preserving the previous linked-object count. Its loadable-image SHA-1
is `3d1d3d2b9d6ccb60836db239ab49674223025a78`; the complete executable SHA-1 is
`4eeec0360cf2715535d9f7e52eb69d786fb0158c`. These are exact retail hashes.
The build receipt records unchanged compiler inputs throughout the run.

The full Linux unit suite passes **613 tests with eleven skipped**; the native
Windows probe suite passes all seventeen tests. Configuration, workflow and
13,102-entry objdiff validation pass, as does committed-progress validation.
Repository-wide integrity lint reports zero errors. These checks and their
unchanged-input fingerprints are retained in `final/*-result.json` alongside
their complete logs.
