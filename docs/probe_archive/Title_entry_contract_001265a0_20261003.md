# Largest Title controller: truthful draw callback entry

Baseline: `81708cc4e9e63e3b1eae30f466c069359a8dff70`, the frozen model-call
checkpoint. This bounded checkpoint repairs the guarded Title callback entry
and its matched updater's declaration/registration type. The NON_MATCHING
guard and assembly fallback remain. **No new exact-C credit or complete Title
or dispatcher-C execution is claimed.**

## Recovered contract

The target is now `void func_001265a0(void *unusedDrawData, void *task)`.
The first input is the real draw-node payload pointer, even though this callback
does not use it. The second input is the task. The entry declares the existing
accessor coherently as `u32 func_00452560(void *task)` and explicitly converts
its address-word result to the existing `u32 *` scene view.

The updater's local declaration and callback-pointer store now use the same
void, two-pointer signature. No invented return, omitted payload, extra third
parameter, changed global old-style accessor declaration, or edits to other
matched accessor callers were used.

`audit_source.py` proves the complete owner differs from the frozen checkpoint
by exactly these five substitutions, including the explanatory entry comment.
The getter provider, sdkOt node owner and dispatcher owner are source-identical
to the baseline.

## Independent retail evidence

The retail ELF is authenticated against SHA-1
`4eeec0360cf2715535d9f7e52eb69d786fb0158c` before inspecting any slice.
Both exact expected words and slice SHA-256 receipts are retained.

- At `0012AA8C`, the updater retains its incoming task in `s3`
- At `0012B620/624`, it stores the callback at node+8 and that task at node+0x10
- At `004623B8`, the dispatcher loads the callback address into `a2`
- At `004623E0/E4`, it supplies node+0x1C in `a0` and node data in `a1`
- At `004623E8`, `jalr a2` calls that address; this register's use as the jump
  target is not evidence of a genuine third callback input
- At `001265D4`, the target forwards incoming `a1` into `a0` before the getter
- At `00452560`, the actual accessor loads and returns the word at task+0x38

The existing sdkOt node has a void two-pointer callback. The immediate
post-callback retail instruction reads the node command independently of
`v0`; this checkpoint does not execute the full command dispatcher. Its current
C's inferred third self-function input remains a separate, explicitly excluded
problem.

## Exact object preservation

Whole-owner production and NON_MATCHING builds were captured before and after.

- Production raw objects are byte-for-byte identical, SHA-256
  `59e652c8faa507dfb2feae59814a9668abfdbb377ba7eb62c3167eac9a7cc8c5`
- All 81 sibling functions retain exact bytes and relocations in both builds,
  including the type-edited updater
- All 420 non-target allocated data bytes, section properties and references
  are unchanged
- Guarded target: 16816 → 16820 bytes. The sole instruction change is insertion
  of `daddu a0,a1,zero` (`0x00A0202D`) at offset +0x44
- Every other target instruction byte is identical. All 376 relocation events
  preserve type, symbol, addend and position under the exact +4 suffix map
- All sixteen switch-table destinations shift by exactly four bytes and retain
  identical instruction prefixes and alias groups
- No branch crosses the inserted prefix: it contains only frame/save setup,
  and all later branch origins/destinations shift together

The archived map is exact, without opcode, register or immediate masking.
This also makes the preserved interior evidence substantially stronger than a
position-based residual count alone.

## Native and machine contracts

`tests/test_title_entry_contract.py` extracts the live callback signature,
getter declaration, work local, first entry assignment, updater declaration,
complete registration block, actual getter definition and sdkOt node layout.
A small two-input dispatch shim represents the independently authenticated
retail boundary. It is not the existing dispatcher C.

- Native i386 tests run at O0 and O2 with real 32-bit pointers, undefined/bounds
  sanitizer traps, exact callback-type assertions and strict pointer diagnostics
- 512 cases per optimization vary all payload-byte values and use two distinct
  task/work pairs. Node, payload, tasks and work views remain distinct
- Canary guards and byte snapshots prove the callback only writes the expected
  registration slots and leaves task/work buffers untouched
- The actual source getter body executes. A test-only observer checks input
  identity before the read, making the wrong-first-input controls well-defined
- Nine behavioral controls reject: first input, swapped dispatch, wrong task
  store, wrong callback/data slots, wrong getter offset, shifted work view,
  bypassed getter and omitted registration
- Two incompatible callback declarations/types fail compilation
- Actual bounded producer/dispatch/entry/getter machine slices execute in 2048
  retail/candidate cases; six independent machine controls reject

All eleven prior native contract modules rerun unchanged: 29 prior tests plus
four entry tests, **33 tests with no skips**. Their limitations remain in force,
including the special geometry placeholders and unexecuted model-provider
matrix-flags path.

Eight prior machine auditors also rerun against the final guarded object:
color extents, layer calls, GP words, palette copies/selections, alpha aliases,
sprite alpha, fade tail and model calls. The replay adapter changes only the
input record path, and composes the proven +4 map for the two older absolute
slice translators. It does not weaken any instruction or semantic assertions.
Auditor hashes and final-source receipts are retained. A SHA-256 manifest binds
the report, test, replay scripts and compact receipts to this checkpoint.

## Final gates and residual

- Ten relevant owners: **342 MATCH / 47 ASM**
- Title owner: **81 MATCH / 1 ASM**
- Updater: **3056/3056 MATCH**
- Actual task getter: **12/16 MATCH**, remaining retail bytes zero
- sdkOt node producer: **284/288 MATCH**
- Existing dispatcher owner function: **992/992 MATCH**; byte-match status is
  not a claim that its inferred third argument is semantically repaired
- Lint: **0 errors, 32 existing advisories**
- Guarded target: **16820/17616 bytes, 3985 position-based masked differing
  words**, versus baseline 16816/17616 and 3955. The shifted metric is not a
  regression in preserved code: the exact single-insertion proof checks it all
- Final source SHA-256:
  `bef9fa5dc7b195c83dcbc497d0e8ccecd247929f4e58d9f0f3106af8d146628e`

The frame and the known matrix/trig/geometry/helper residuals remain outside
this checkpoint. No full renderer/gameplay run, full repository test suite,
full linked-image build, CI, push or publication was performed. Production raw
object identity is proven; no new linkage or end-to-end rendering claim follows.

## Replay

From the repository root, with the configured licensed MWCC/retail inputs,
Clang, GNU ld and an existing native i386 runner:

```sh
bash docs/probe_archive/Title_entry_contract_001265a0_20261003/replay.sh
```

The runner defaults to `qemu-i386`; `P4_NATIVE32_RUNNER` can select another
existing executable. Full object captures and intermediate logs stay in
untracked `proof/`. The committed archive contains only source scripts,
compact receipts, this report and native test output. No retail ELF, proprietary
compiler, generated assembly or full object capture is committed.
