# Action status response 001adea0

The status-response routine produces all 1,312 executable retail bytes. Its
35 relocations resolve to the original call sites and targets. The standalone
native proposal preserves all 70 other functions and allocated data in
`src/promoted/code1_001a.c`.

The routine processes the HP- and SP-loss status kinds, creates a complete
32-byte result object, and queues the dependent health, display, gauge,
animation, and sound packets. The action identity is captured after the status
query, matching the retail read sequence. The status result and its masked
dispatch value have distinct source lifetimes.

The signed delta comes from the existing `s16 func_001f6d60(u8 *)` provider.
The declaration now agrees with that definition. Animation packet construction
uses `btlUnitCreateAnimPacket` with its existing float speed and integer mode
arguments. Action-state changes use the canonical `btlActionSetState` API.

The state-kind switches retain the retail source ordering of cases 1, 3, and
2. Although every branch selects state 32, the native target contains the
corresponding comparisons. The earlier reconstruction already contained these
branches; they are not additional padding operations.

The original exact reviewed source, object, compilation receipt and complete
relocation proof are retained under
`build/finish-first-party-20260922/continue-54-actions/reviewed/`. The resolved
target SHA-256 is
`bacbfcf025662b0750813cb07a024a587eaea2a04b570d7f06a87928bbf9720a`.

The combined readiness/status proposal is independently compiled under
`continue-55-actions/reviewed/`. Both target proofs are unchanged, all 69
remaining functions retain their bytes and canonical relocations, and allocated
data is unchanged. The final source-formatting proof is retained under
`continue-55-actions/normalized/`; installed verification and publication
evidence are retained under `continue-55-integration/final/`.
