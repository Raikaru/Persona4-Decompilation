# Action readiness 001afb50

The recovered readiness callback emits 1,228 native bytes in its 1,232-byte
retail window. All 36 relocations resolve exactly and the remaining four
bytes are zero alignment. All seventy other functions in
`src/promoted/code1_001a.c` and all existing allocated data are preserved.

The original floor had two pointer-versus-address errors: the unit packet
constructor consumes the pointer at unit offset `0xA0C`, and the level update
consumes the data pointer at `0xA64`. The new source dereferences both fields
at the positions used by retail. The countdown uses the positive signed
promotion of its byte, and clearing the halfword flag uses mask `0x7FFF`.

The normal-work arm precedes the paused-order arm. Its equivalent condition
preserves the two ordered byte checks before considering the saved death
result. This produces retail's original branch layout without changing call
order or adding artificial branches.

Both unit-reset tests snapshot the halfword flags and first test bit 0.
Within that branch, the pointed-to unit is read before bit 4 is tested. Only
then is the unit's bit 1 examined. This is the actual source lifetime
indicated by the retail loads; deferring the pointer load until after both
flag checks changes the generated code. The final predicate uses the same
positive unit-flag branch and boolean result as retail.

All called providers were checked against their definitions. The callback
uses the canonical health, status and action-state APIs, with explicit
argument and result types. Numeric helpers retain the signatures of their
existing providers. Every provider remains unchanged. Canonical names are
resolved from the authenticated source markers and native MATCH receipts;
the final publication gate separately requires actual C linkage.

Native source, object, compiler receipt, full relocation proof and sibling
checks are retained under
`build/finish-first-party-20260922/continue-53-actions/reviewed/`.
`nested-both` records the initial exact discovery and `all-providers` records
closure with the reviewed provider interfaces. The obsolete floor comment
is retained separately as `superseded-floor.txt`.

The resolved target SHA-256 is
`3e7a8d3f4b6c8ce5eb8069375dd92f87fbf0c51132c8ffc0b630bb1aa1641423`.
The initial single-target preparation is retained under `continue-53-integration`.
The combined readiness/status source under `continue-55-actions/reviewed/`
preserves both original target proofs, all 69 remaining functions and allocated
data. Its installed verification and publication evidence are recorded under
`continue-55-integration`.
