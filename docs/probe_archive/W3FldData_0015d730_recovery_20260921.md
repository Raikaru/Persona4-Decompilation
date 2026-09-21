# Field loader recovery: 0015d730

The complete field-loader callback is now accepted in live
`src/promoted/k_fldData.c`, together with its authorized mipmap parameter repair.
Fresh live-source compilation and complete relocation proofs pass for both
owners. The official live verifier reports **3 MATCH / 3 functions** for each;
combined with the environment recovery, all **17 functions MATCH** and lint
reports **zero findings**. The loader was its owner's remaining assembly fallback.

## Recovery

`FldDataLoadWork` describes the actual 0xF4-byte task work allocation. Its file
members use the existing native `HCdvd` type. The three texture request arrays
contain 30, 2, and 2 pending requests, respectively. A completed file or texture
operation releases the resource and clears its owning slot at the retail point.
Sound setup uses the actual `uGpffffb270` buffer and `iGpffffb26c` child-task
globals, replacing arithmetic beyond an unrelated scalar declaration.

The callback advances through file submission, file completion and texture
submission, texture completion, and mipmap completion. A pending base model
returns through the shared zero-return path; it does not enter the texture
phase. The readiness helper has a genuine `u8` predicate return, preserving the
retail `sltu` normalization before that branch.

Separate allocation and copy extent snapshots preserve the file-size loads
before native call arguments. A scoped `opt_propagation off` setting retains
those lifetimes. Explicit model kind and identifier arguments keep the model
manager's established engine-word interface while reading the source memory
through its actual pointer type. The final source uses native `HCdvd` fields,
the existing `SdkTask.work` field, and typed texture-array accesses throughout.
It adds no assembly, padding, artificial side effects, or out-of-line helpers.

The native declarations follow the actual providers: unsigned file readiness
and destruction returns, the synchronous file wait's void return, memcpy's
pointer return, texture request/completion pointer interfaces, and the sound
and task-presence contracts. The RenderWare allocation callback keeps its
`(size_t, size_t, u32)` signature from `RwMemoryFunctions.rwcalloc`.

## Mipmap dependency

The loader passes its parent task to `func_0018c580`. The previous provider
declared no parameter, while its retail body ignores the incoming argument.
The live provider now restores the unused `u8 *parent` formal. The complete provider
object remains byte-for-byte identical, including its other two functions and
allocated data. No model callback or parent-query provider is changed.

## Evidence and integration package

All paths below are relative to
`build/first-party-finish-20260920/field-current-work/`.

- `live-field-integration-20260921/`: immutable current-input snapshots,
  before/staged/live source copies, objects and compiler logs; fresh complete
  proofs are `k_fldData/live/integration-proof.json` and
  `k_fldMipmap/live/integration-proof.json`. `live-manifest.json` seals the
  accepted owners; `live-verify.json` and `live-decomp_lint.json` record the
  official live checks. `integration.patch` preserves the exact applied change.
  The loader resolves all **269** code relocations; mipmap resolves all **12**.
  `resume_live_20260921.py` checks starting hashes before writing authorized
  owners and checks input/source hashes again after sealing the live proofs.
- `data-recovery-integration-20260921/`: reviewed `k_fldData.c`, reviewed
  `k_fldMipmap.c`, original owners under `base/`, `recovery.patch`, and
  `manifest.json`. The package checks original source hashes, object hashes,
  current headers, line endings, sibling preservation, data preservation, and
  official verification before writing either proposal.
- `data-native-20260921/func_0015d730/reviewed-native-request-array-ownership/`:
  immutable source, object, compiler log, receipt, and full relocation proof.
- `data-native-20260921/official-verify.json` and `official-lint.json`:
  3 MATCH and no lint findings.
- `data-mipmap-provider-20260921/func_0018c580/restore-unused-parent-contract/`:
  provider proposal, object, and preservation proof; the parent directory's
  `official-verify.json` records 3 MATCH.
- Each campaign's `inputs/`, `profile.json`, and `provider-evidence/` preserve
  the input owner, headers, actual native providers, and complete target ASM.
  The integration package also freezes configuration, verification tools,
  relevant native headers, and their hashes.

The configured compiler is MWCCPS2 b210 at `-O2 -Iinclude`, with a frozen include
copy for the comparison receipts. Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.
Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

### Loader proof

The target emits **4196 bytes** in its **4208-byte** retail window, with a
**12-byte zero suffix** and **zero unmasked relocated differences**. Both
neighbors retain identical code and canonical relocations; allocated data is
identical; there are no additional functions.

Original owner SHA-256:
`92c77a3e57e9b0604b35aea6cc1505195d1c910d1bb7cbcb7fc1a47aa4234151`.
Accepted live owner SHA-256 (identical to the saved proposal):
`612b95bf72c3850c8c4e991dc7eb20fca45deabcba29b367b5c83a654cb89164`.
Object SHA-256:
`82ff80da5e5da6d106f6a5ff83984e47e1a3bdeb6e4e661a39f0331317256e7a`.
Resolved target SHA-256:
`b895894289aa8d5a11fe4f83fda4641686d15ffa56e14096f6a05871d0d47662`.

### Mipmap proof

The target emits **140 bytes** in its **144-byte** retail window, with a
**4-byte zero suffix**, zero unmasked differences, both neighbors preserved,
and allocated data preserved.

Original owner SHA-256:
`7e49327e911948956f7400e38ae055982eed20193f0ee6ef5fdef34b5b5fc66f`.
Accepted live owner SHA-256 (identical to the saved proposal):
`87a86f6a71383ec1a844d767f3072980bb36845aade4ff604326b2e47d9f5a51`.
Unchanged object SHA-256:
`b37c9776137890bfb5a590eb15d98cbbe03ab1a5c94af70e4600f0c2a4716d70`.

## Preserved field-unit frontier

`src/promoted/k_fldUnit.c` remains unchanged at
`598680b18cba35486dd273bdd389cee190eac2b21bee83ec508213126d744219`.
A fresh current-header baseline under `native-closure-20260921/` preserves all
42 functions and allocated data, including the protected 40 C matches.
The initializer's native seven-word frontier and the constructor's six-word
frontier remain archived. New enum, consumer-owned predicate, byte-predicate,
typed pair-input, and native caller-lifetime hypotheses did not close them.
Their measured receipts are retained rather than substituted into production.

The original loader frontier, intermediate 14-word argument-order frontier,
pointer-safe three-word model-boundary frontier, and their exact successors
remain available in `data-native-20260921/`. The recipe is
`data_recovery_20260921.py`; `package_data_recovery_20260921.py` creates the
reviewable integration package without editing either live owner.
