# Persona 3 FES Completion and Persona 4 Synchronization Roadmap

This roadmap defines how the Persona 3 FES matching decompilation reaches a
complete, maintainable state while verified shared functions are carried into
the Persona 4 matching decompilation. The same roadmap is mirrored in both
repositories; the Persona 3 FES copy is the canonical completion plan.

All counts below describe the verified USA executables and the committed
function maps as of 2026-07-10. They are checkpoints, not alternate completion
criteria. Generated progress JSON remains the authoritative live measurement.

## Completion criteria

Persona 3 FES is complete only when all of the following are true:

1. **Canonical coverage:** every one of the 13,591 function windows has an
   intentional source owner, a stable boundary, and no duplicate or nameless
   marker.
2. **Maintainable source:** functions use typed structures, meaningful names
   where evidence permits, explicit ABI quirks, and readable control flow. Raw
   decompiler artifacts are not considered final source merely because they
   compile.
3. **Exact matching:** every canonical function reports `MATCH`. There are no
   `STUB`, `NONMATCHING`, `STALE_NONMATCHING`, `MISMATCH`, `SIZE_MISMATCH`,
   `NO_SYMBOL`, `COMPILE_ERROR`, or `UNKNOWN_ADDR` rows.
4. **Real C linkage:** every fully matching translation unit whose retail range
   is C-owned is selected by the matching build. Section ownership, alignment,
   relocations, and zero-filled data reproduce retail rather than falling back
   silently to the assembly baseline.
5. **Retail identity:** the rebuilt load image and complete ELF retain the
   verified retail SHA-1 values:
   - load image: `9203646d9aa48ff24eb4ba4b328b02df468a9483`
   - ELF: `3929cd7c02be944f25ec6b924e5f1eab9bc5e9cb`
6. **Documented exceptions:** startup, SDK, or compiler-runtime assembly may
   remain only when its provenance and interface are documented and it is not
   concealing unknown game logic. Compiler-codegen walls do not justify leaving
   semantic C incorrect.
7. **Synchronized P4 reuse:** every unique address-normalized P4 counterpart of
   a verifier-matched P3 function is either:
   - ported, independently verified as P4 `MATCH`, and C-linked; or
   - recorded with a concrete blocker such as changed logic, incompatible data
     ownership, ambiguous duplicate bodies, or compiler/codegen divergence.
8. **Reproducible publication:** progress endpoints validate, public badges
   reflect committed reports, tests pass, and a clean checkout can reproduce
   the documented build with user-supplied legal inputs.

These criteria intentionally separate source coverage, byte matching, and
C-linkage. A green whole-image build proves retail identity; only the per-function
verifier proves that a particular C body matches.

## Current verified baseline

### Persona 3 FES

| Metric | Current |
| --- | ---: |
| Canonical functions | 13,591 |
| Exact `MATCH` | 3,033 (22.316%) |
| `NONMATCHING` | 10,558 |
| Matched body bytes | 264,612 |
| C-linked functions | 55 |
| C-linked translation units selected by the latest build | 14 |

The source-marker reconciliation gate currently reports zero duplicate addresses
and zero markers without definitions. The full verifier and matching build pass.

### Persona 4

| Metric | Current |
| --- | ---: |
| Canonical functions | 13,080 |
| Exact `MATCH` | 140 (1.070%) |
| C-linked functions | 140 (1.070%) |
| C-linked translation units | 139 |
| P3-derived matching functions | 140 |

The current P3-derived P4 set spans runtime, Kernel, Kosaka, Scene, gameplay,
CRI, and RenderWare helpers. Both P4 retail hashes and all progress endpoints
are verified.

### Cross-game opportunity map

The reproducible binary mapper currently reports:

| Mapping class | Functions | P4 code bytes |
| --- | ---: | ---: |
| Raw-byte identical | 1,302 | 117,896 |
| Address-normalized identical | 6,445 | 1,187,448 |
| Unique address-normalized mappings | 4,401 | — |
| Unique mappings with verifier-matched P3 source | 525 | 32,240 |
| Ready but not yet P4-matched | 385 | 25,008 |

Address normalization masks only executable-layout fields: J/JAL targets, LUI
immediates, GP-relative immediates, and low halves paired with recent LUI
instructions. Opcodes, register operands, ordinary constants, branch structure,
and instruction order must otherwise agree.

## Operating model

Work proceeds through two continuous lanes with one integration gate.

### P3 completion lane

For each bounded function family or translation unit:

1. Confirm canonical boundaries and current verifier rows.
2. Recover semantics, types, ownership, and call relationships.
3. Replace address arithmetic with typed structures only when offsets are proven.
4. Use focused `fndiff.py` output to classify remaining codegen differences.
5. Apply established MWCC source-shaping rules before invoking the permuter or
   compiler debugger.
6. Remove `NONMATCHING` only after the focused verifier reports `MATCH`.
7. Close the entire translation unit when practical so the work improves both
   matching and C-linked progress.

### P4 synchronization lane

After every committed P3 matching batch:

1. Regenerate `build/shared_p3.json` from pinned P3 and P4 inputs.
2. Select entries with `unique: true` and `verifier_match: true`.
3. Translate calls, callbacks, LUI/low addresses, GP-relative data, and strings
   using report evidence and retail disassembly.
4. Preserve the P3 semantics but use P4 canonical symbols and P4 data ownership.
5. Place noncontiguous functions in independent translation units.
6. Require focused P4 `MATCH`, then require actual C-link selection.
7. Record changed or ambiguous P4 functions as blockers rather than pretending
   they are direct ports.

### Integration gate

A batch lands only after:

- focused verifier evidence for every changed function;
- marker and boundary validation;
- deterministic unit tests for tooling changes;
- complete project verifier output with no unexpected status;
- byte-identical load-image and ELF hashes;
- regenerated and validated progress endpoints;
- pinned input hashes in the cross-game report;
- commits that exclude retail files, compiler outputs, and local scratch data.

Parallel work is capped at five active workers. Workers own disjoint files;
shared headers, symbol maps, progress reports, full builds, commits, and pushes
belong to the integration lane.

## Milestone 1 — Eliminate false work and close near matches

This milestone converts already-understood source into verified progress before
opening more large subsystems.

### P3 priorities

Current normalized-difference distribution among `NONMATCHING` functions:

| Reloc-masked differing words | Functions |
| --- | ---: |
| 0 | 4 |
| 1–5 | 7 |
| 6–20 | 544 |
| 21–50 | 1,858 |
| 51–100 | 2,216 |
| 101–250 | 3,180 |
| 251–500 | 1,476 |
| 501–1,000 | 809 |
| More than 1,000 | 578 |

Actions:

1. Resolve the four zero-diff marker/status cases immediately.
2. Close the seven one-to-five-word functions with direct source inspection.
3. Process the 544 six-to-twenty-word functions by repeated codegen family,
   not as unrelated one-off puzzles.
4. Capture every reusable source-shaping lever in `docs/matching.md` and add a
   compiler-debugger reducer when the responsible pass is unknown.
5. Keep an explicit list of proven compiler walls so already-exhausted variants
   are not retried indefinitely.

### Linkage priorities

Twenty-two P3 files are fully matching, but nine are not yet selected as real C
objects:

- `src/Camp/_h_camp_item.c`
- `src/Kosaka/k_spipe.c`
- `src/Main/Battle/Cmd/bcm_main.c`
- `src/Main/Battle/Cmd/bpm_main.c`
- `src/Main/Battle/Panel/bp_misc.c`
- `src/Main/OpEd/op_res.c`
- `src/Main/Social/sfl_persona.c`
- `src/Scene/resrcManager.c`
- `src/Script/scrCommonCommand.c`

For each, classify the blocker as noncontiguous text, unresolved external symbol,
owned-data placement, conflicting recovered bases, section padding/alignment, or
retail nonzero bytes in a claimed BSS range. Fix the build model or source
ownership at the root; do not suppress eligibility checks.

### Near-complete translation units

Close files with only one remaining function first:

- `src/Script/scrTraceCode.c` — 47/48
- `src/Script/scrComuCommand.c` — 37/38
- `src/Kernel/Kwln/kwlnRoot.c` — 26/27
- `src/Main/Battle/Result/br_res.c` — 16/17
- `src/dds3Process.c` — 14/15
- `src/Main/Battle/Panel/bpp_panel.c` — 10/11
- `src/h_cursor.c` — 7/8
- `src/Main/Battle/Cmd/bp_persona.c` — 6/7
- `src/Main/Battle/Result/br_persona.c` — 6/7
- `src/Main/Battle/Data/datScript.c` — 5/6
- `src/Main/Battle/Cmd/bp_tuta.c` — 4/5

**Exit gate:** no zero-diff `NONMATCHING` rows; every one-to-five-word case is
matched or has a documented compiler-level residual; all fully matching files
are either C-linked or have an explicit, tested linkage blocker.

## Milestone 2 — Finish high-completion engine and script subsystems

Prioritize subsystems where shared types and conventions unlock many callers.

| Subsystem | Match status |
| --- | ---: |
| Script | 111/115 (96.5%) |
| Kernel | 89/138 (64.5%) |
| `h_maestro.c` | 54/95 (56.8%) |
| Kosaka | 348/786 (44.3%) |
| Main | 791/1,807 (43.8%) |
| `h_cdvd.c` | 17/43 (39.5%) |
| Battle | 486/1,506 (32.3%) |
| Scene | 34/129 (26.4%) |

Sequence:

1. Finish Script and its four remaining functions.
2. Finish Kernel task/root helpers and stabilize shared task structures.
3. Close resource manager, scene, CDVD, and command interfaces used across the
   field and battle engines.
4. Complete Kosaka field/runtime families before isolated presentation code.
5. Work Main and Battle by coherent state-machine family: lifecycle, units,
   targeting, action/order, camera, panels, result, then boss-specific logic.
6. Close each translation unit’s data ownership immediately after its functions
   match rather than deferring all linkage to the end.

**Exit gate:** Script and Kernel are fully matching and linkable; shared scene,
resource, task, field, and battle structures have stable sizes and field names;
no second convention exists beside an established subsystem pattern.

## Milestone 3 — Complete game-specific content and presentation

This milestone covers large game-owned regions whose logic is readable but not
yet exact.

| Subsystem | Match status |
| --- | ---: |
| Camp | 65/298 (21.8%) |
| Event | 246/1,273 (19.3%) |
| Graphics | 136/746 (18.2%) |
| Yajima | 46/317 (14.5%) |
| `itfMesManager.c` | 19/113 (16.8%) |
| `itfPanel.c` | 12/77 (15.6%) |

Sequence:

1. Camp data/menu primitives, then state machines and presentation.
2. Event command dispatch, message/effect/menu helpers, then FCL shop/combine
   flows.
3. Model loading, animation cursors, resource dispatch, effects, and primitive
   drawing.
4. Interface message/panel managers and font/tag paths.
5. Yajima runtime/time-limit helpers and remaining presentation systems.
6. Calendar, social, communication, opening/ending, and result UI families.

Large generated-looking functions must be split conceptually during review even
when they remain one retail function. Names should follow proven behavior and
call relationships, not guesses based only on constants.

**Exit gate:** all game-owned gameplay, event, UI, model, and presentation
functions are maintainable and exact; every completed file has a linkage decision.

## Milestone 4 — Close middleware, SDK, and standard-library regions

These regions dominate the remaining function count and require family-based
work rather than manual random selection.

| Region | Match status |
| --- | ---: |
| CRI | 182/3,312 (5.5%) |
| RenderWare | 92/1,682 (5.5%) |
| SCE libraries | 26/451 (5.8%) |
| `libc_core.c` | 1/98 (1.0%) |
| `libcdvd.c` | 0/40 |
| `libm.c` | 0/26 |
| `code2.c` | 0/9 |

Actions:

1. Identify library versions and public SDK signatures before inventing names.
2. Group thin accessors, allocation wrappers, callbacks, and table-driven
   routines into mechanical batches.
3. Recover common structures once and apply them consistently across the
   library, with size/offset assertions where supported.
4. Separate genuine game wrappers from third-party library bodies.
5. Use known upstream source only as evidence; retail bytes and the verifier
   remain authoritative for this build.
6. Document any assembly retained for startup or SDK provenance and verify every
   interface crossing into C.

**Exit gate:** middleware and SDK regions have stable provenance, naming, types,
and exact source; no large raw decompiler dump remains accepted as final merely
because it compiles.

## Milestone 5 — Resolve the hard compiler-codegen tail

The final tail consists of functions whose semantics are already understood but
whose retail scheduling or allocation is difficult to express.

Actions:

1. Classify residual instructions: register allocation, scheduling, FPU
   allocation, signedness/extension, switch lowering, mask propagation,
   commutative operand order, return layout, or delay-slot placement.
2. Apply the established matching catalog before searching new variants.
3. Use the MWCC debugger to locate the first compiler phase where retail and
   candidate behavior diverge.
4. Use bounded text/AST permutation only around the proven source lever.
5. Promote a discovered family rule across every affected function, then verify
   each independently.
6. Reject opaque assembly substitutions that hide incorrect semantics. Any
   unavoidable exact assembly shim must be isolated, explained, and tracked as
   an exception until removed.

**Exit gate:** the complete P3 verifier reports 13,591 `MATCH` rows and no other
status.

## Milestone 6 — Finish C linkage and release verification

Matching and linkage close together throughout the project, but the final gate
is repository-wide.

Actions:

1. Ensure every fully matching C-owned translation unit is selected by the
   matching build.
2. Resolve all data-section base, alignment, padding, relocation, and BSS
   ownership failures.
3. Confirm no linked function is absent from the matching set.
4. Rebuild from a clean checkout with only documented toolchains and legal local
   inputs.
5. Run the complete verifier, complete tests, boundary reconciliation, progress
   validation, and whole-image/ELF comparison.
6. Regenerate and publish matching and linked endpoints from the exact release
   reports.

**Exit gate:** all completion criteria at the top of this document are satisfied.

## Continuous P4 synchronization backlog

P4 synchronization runs during every P3 milestone rather than after P3 is
finished. The current ready-but-unported backlog is 385 functions / 25,008 bytes.
The first source clusters by reusable byte volume are:

| P3 source cluster | Ready P4 functions | P4 bytes |
| --- | ---: | ---: |
| `Battle/btlUnit.c` | 43 | 4,816 |
| `Graphics/Model/mdlFile.c` | 60 | 2,528 |
| `Battle/btlFormation.c` | 25 | 1,552 |
| `cri/cri_adx.c` | 95 | 1,296 |
| `Kosaka/Field/k_shadow.c` | 3 | 1,296 |
| `Script/scrTraceCode.c` | 13 | 800 |
| `comuTimerSequence.c` | 11 | 704 |
| `Graphics/Effect/effMisc.c` | 8 | 688 |
| `Battle/btlTarget.c` | 11 | 672 |
| `Battle/btlAction.c` | 8 | 608 |
| `Main/Battle/Data/datCalc.c` | 14 | 576 |
| `rw/rprandom.c` | 14 | 560 |
| `Battle/btlSound.c` | 7 | 528 |
| `Scene/mt_scene.c` | 5 | 496 |
| `Battle/battle.c` | 7 | 464 |

Priority is not byte volume alone. Prefer a cluster when its shared types and
callees are already established and its functions can become real linked C
objects without claiming unrelated retail data. A recommended order is:

1. `scrTraceCode`, `scrCommonCommand`, and other near-complete script helpers.
2. `effMisc`, `mt_scene`, resource, and small engine utility clusters.
3. Battle unit/target/action/sound families with one shared type contract.
4. Model and field-shadow clusters after graphics structures stabilize.
5. CRI and RenderWare batches after their P3 source is cleaned and library
   provenance is established.

Current direct-port blockers:

- P4 `004d31d8` ← P3 `00547548`: the retail three-instruction nested getter keeps
  the intermediate pointer in `$v1` and the loaded result in `$v0`. Natural C at
  the project compiler settings allocates the intermediate directly to `$v0`;
  the object remains 12 bytes but differs in two register fields. Keep this
  unported until a source-level register-allocation lever is verified.
- P4 `005179e8` ← P3 `0058bd58`: retail preserves `object += 0x1fc`
  and uses the adjusted base for two zero stores. Both `-O1` and `-O3` fold the
  source back into independent `0x200`/`0x1fc` stores, changing the delay slot
  and base register lifetime. Keep it unported until that address-update shape
  is source-reachable.

Each P4 port batch must end with:

- all selected functions reporting P4 `MATCH`;
- every intended object listed as eligible and C-linked;
- unchanged P4 retail hashes;
- updated `progress/metrics.json`, `matching.json`, and `linked.json`;
- successful GitHub Pages endpoint validation.

## Tracking and review

The following artifacts are authoritative:

- P3 canonical windows: `tools/slus21621_functions.json`
- P3 verifier: `tools/verify.py`
- P3 progress: `progress/metrics.json`
- P4 canonical windows: `tools/slus21782_functions.json`
- P4 verifier: `tools/verify.py`
- P4 shared map: `build/shared_p3.json` generated by `make shared-p3`
- P4 progress: `progress/metrics.json`

Every roadmap update must cite regenerated metrics rather than hand-maintained
percentages. When counts change, update the baseline tables and backlog table in
both mirrored roadmap files in the same integration batch.
