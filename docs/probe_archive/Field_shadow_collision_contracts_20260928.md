# Field shadow collision contracts

`src/Kosaka/k_spipe.c` now uses the shared RenderWare collision declarations and
passes a typed `RpAtomic`, `RpIntersection` and `RwAtomicCollisionContext` through
the shadow intersection callback. The local matrix, vector and primitive
declarations now agree with the providers used by this owner.

This corrects the C interface without changing the six recovered functions.
The actual publication owner passes the ordinary verifier with six `MATCH`
results. Its 20 text relocations resolve to the retail instructions; the owner
adds no allocated data. The retained object SHA-256 is
`6ae03ec64aec5f500da3355a33f38b998b110ccce6d8ef27ef7b26c94ec18bbb`.

The complete September 28 verification compiled all 959 owners and checked all
13,102 tracked functions. It reports 9,507 `MATCH` and 3,595 `ASM`, with no
unexpected status, wrong callee, wrong symbol, or source/header input drift.
The affected source also passes the integrity linter without errors.

Local evidence is retained under
`build/publish-first-batch/kspipe-verify.json`,
`build/publish-first-batch/kspipe-lint.json`, and
`build/publication-verification/first-batch/`. The complete verifier's command
and successful exit are recorded in
`build/publication-gates/first-batch-full-verify/result.json`.

This is a declaration repair; it does not add a newly decompiled function.
