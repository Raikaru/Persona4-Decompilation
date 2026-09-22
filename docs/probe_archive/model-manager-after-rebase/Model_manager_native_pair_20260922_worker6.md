# Model manager: two native closures after the 7387466 rebase

The current first-party owner `src/Graphics/Model/mdlManager.c` has **121 MATCH
/ 5 ASM**, gaining ordinary C for `func_00473b20` and `func_0047c660`.

## Current owner receipt

The authoritative receipt is
`build/continue-first-party-20260922/model-manager-after-rebase/closed-model-two-functions/completed.json`,
completed on 2026-09-22 at 09:25:09 UTC. Its directory also retains the exact
compiled source, complete native object, compiler log, official verifier
report/log, and every resolved target binary. Earlier completed receipts are
historical and have not been replayed or overwritten.

| Binding | SHA-256 |
| --- | --- |
| Current owner source | `e6ed3dfaa8f5b20447738be432e49111ee6e29bb437bd8b2753d8dcc2dcb8527` |
| Complete native object | `d8e7d8e7134eebbdb9f9e12ab94347fc98f5e90ef3cec2ffb827234644956e56` |
| Native b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |
| Original rebased owner source | `3a1232706a3b0b6c876f36e48e7de02b7bdb2a010011d1d5718d2e448d980354` |
| Original rebased object | `78b6c2eba585b4d8aa251bf69210b02d5dd6b5aad3fa4d938d4dde93d664236c` |

The receipt records HEAD `c4388741f9070eaec2b37e3a3af3684886d1a581`, native
`D:\mwcps2-3.0.1b210-060308\mwccps2.exe`, and flags `-O2 -Iinclude`. It binds
all headers, source, remaining ASM inputs, compiler and object. The official
current-owner verifier explicitly reuses this one newly compiled native
object. No full build was run.

| Explicitly proved target | Executable / window | Zero tail | Full relocations |
| --- | ---: | ---: | ---: |
| `func_00473b20` | 1432 / 1440 bytes | 8 bytes | 26 |
| `func_0047c660` | 1944 / 1952 bytes | 8 bytes | 43 |
| `func_00473000` | 312 / 320 bytes | 8 bytes | 22 |
| `func_0047a320` | 372 / 384 bytes | 12 bytes | 7 |

All four have exact unmasked resolved retail proofs. The other 122 functions
preserve their bytes and canonical relocations. Every allocated data section
is unchanged, and none of these targets owns an additional data section.
Separate candidate proofs preserve all 125 siblings for each new target.
All ten rebased `RtAnimInterpolatorSetAnimLoopCallBack` relocations remain
unchanged. `git diff --check` passes.

The first closure's detailed animation-state reasoning and owner-wide
hierarchy contract are retained in
`00473b20_native_closure_20260922_worker6.md`. Its 120 MATCH / 6 ASM count
describes that earlier checkpoint; the receipt above is now current.

## Resource-loader behavior recovered in 0047c660

The first-party load state machine in `src/promoted/code1_0047.c` calls
`0047c660` in its pending stages and advances only after the loader returns
one. The loader polls texture dictionaries, UV animation resources, and the
clump request; constructs missing eight-byte and sixteen-byte table headers;
consumes pending material-animation streams; then applies the two layer maps
and releases each consumed map. All retail calls and all actual arguments
remain in their original order.

The full retail assembly, complete IDA/Ghidra drafts, first-party resource
request/poll providers, texture callback, material-animation providers, clone
providers, and actual caller were inspected. The useful mechanisms were:

* The poll provider returns a real pointer. Its status and stream handle are
  separate signed-word outputs, grouped in one C record. That real pointer
  return naturally produces the retail `sq/lq` spill; no 128-bit dummy local
  or fabricated spill is present.
* Layer offset `0x124` owns pointers to the two list-pointer arrays at
  offsets `0x14` and `0x20`. The old draft incorrectly treated these arrays
  as inline storage. Both clone calls now dereference the actual pointer
  arrays, and their source offset survives both calls as a real value.
* The first 64 bytes of each 80-byte animation entry are an `RwMatrix`.
  Its ordinary value assignment produces retail's paired-word copy loop,
  including loading both source words before either destination write.
  This is the same real matrix-assignment pattern used by matched owner
  functions `0047a510` and `0047aee0`.
* Entry storage is reloaded after matrix/animation writes, resource-pointer
  writes, and callbacks. A table pointer and its current entry storage are
  distinct values. The material-animation list owner is reloaded after
  creating an empty list, preserving the callback boundary.
* Loop counters are full-width unsigned values. Only individual asset
  indices are narrowed to unsigned shorts, while the guarded resource
  lookup retains the retail signed-short comparison. The prior attempt to
  use wrapping `u16` loop counters was incorrect.
* Request offsets, map offsets, and resource-entry offsets are explicit
  real values. Scoped `opt_propagation off` preserves their load order.
  Declaration order for actual allocation, resource, traversal, and loop
  values then closes the saved-register assignments. Two different real
  declaration orders reached the same exact native body.

Every local read has an initialization on its reachable path. The poll is
called only with a nonzero pending request. The relevant request kinds are
2, 7 and 8; the inspected poll provider writes the handle on each successful
kind and writes the status on success or pending failure. An uninitialized
handle is never consumed on a pending path. Matrix source/destination fields
are either the same entry or disjoint 80-byte entries; the C assignment does
not introduce a partially overlapping copy.

## Actual interfaces and complete-owner checks

`func_004667d0` has all ten actual request arguments. `func_004669d0` returns
`u8*` and receives the request pointer plus two signed-word output pointers.
`func_0047f9f0` takes no arguments and returns the newly allocated list-head
pointer. `func_0047d200` and `func_0047dc30` receive `u32**` list-head owners
and return cloned wrapper pointers. Their other active callers in this
owner retain identical native code.

The loader uses the existing opaque `KClumpCallback` interface for the
texture callback's actual two pointer arguments and returned texture
pointer. The first-party callback at `k_clump.c:589` consumes both arguments
and returns its original texture pointer, currently spelled `(s32)arg0` in
that provider's recovered C. This native pointer-return contract and its
provider spelling were reported to prime; no provider file was edited.

Vendor interface headers and name metadata were inspected without reading
or editing vendor implementation. `003ef260` enumerates dictionary textures
and returns the dictionary pointer. `003ef1b0` is dictionary destruction and
returns a signed boolean, as confirmed by `docs/sky2/known_names.json` and
`rw_tu_map.json`; it is not dictionary-current selection. Stream close also
returns a signed boolean. `003d60e0` takes schema and dictionary pointers and
returns the schema pointer, consistent with `rtdict.h`. The memory-fill and
free declarations carry their actual pointer/size interfaces.

The schema object `D_0070B610` is an unsized byte-array declaration, as in
other first-party users. The old single-byte declaration caused an invalid
GP-relative relocation with displacement **-383712**. Full relocation
checking rejected that baseline; it was never scored with a mask. The
correct declaration emits the retail HI16/LO16 pair. The original completed
baseline object and its explicit rejection are retained.

After correcting these owner-wide interfaces and removing the unused
128-bit typedef and unused local, the candidate remained exact with all 125
siblings and allocated data unchanged. The final installed source received
a fresh native compile and the official current-owner gate above.

## Preserved probe evidence and remaining work

The fresh lane is
`build/continue-first-party-20260922/model-manager-after-rebase/`.
The final loader candidate is
`after-owner-contract/loader-reviewed-real-owner-contracts/`.
The earlier exact declaration-order candidates are
`loader-resource-before-allocation-state/` and
`loader-allocation-after-resource-before-table/` in that same subdirectory.
Each directory retains source, compiler/dependency/object identity,
alignment, resolved bytes, sibling/data comparison and full exact proof.

The loader's measured progression was 360 words after correcting only the
schema declaration, then 120 with real map/callback phases, 101 with distinct
poll/resource values, 85 with the `RwMatrix` assignment, 51 with real state
declarations, 44 after preserving explicit index loads, 29 after correcting
outer/inner traversal declarations, and finally zero. The original invalid
GP-relative baseline was compiled once and not replayed.

The preceding cold-probe notes were retained verbatim as
`after-owner-contract/0047c660-preceding-notes.txt`, and complete previous
owner sources remain in the immutable receipts. No old script main or
completed compiler/gate job was rerun.

Five first-party fallbacks remain: `00471370`, `00475cd0`, `00476e90`,
`00479100`, and `0047b0c0`. The new material-lifetime probes remain negative;
`00476e90` reached 67 differing words but was not accepted. The old 18
exhausted `00479100` probes were read and not repeated. No other production
owner, shared header, vendor implementation, or unrelated working-tree
change was modified by this worker.
