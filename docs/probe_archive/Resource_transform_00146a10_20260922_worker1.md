# Resource transform 00146a10, 2026-09-22

`func_00146a10` is integrated as ordinary C in `src/promoted/code1_0014.c`.
The configured native MWCC b210 `-O2 -Iinclude` owner object reports
**121 MATCH / 5 ASM**, including the recovered transform at **1100/1104 bytes**.
All 125 other owner functions retain their complete bytes and canonical
relocations. This is one recovery beyond the owner's preceding 120/6 state.

## Recovered storage and behavior

The four input pointers retain their existing caller contract. A null resource
does nothing. Each non-null position, rotation or scale pointer supplies three
consecutive floats; a null vector pointer retains that resource vector.
The aggregate assignments preserve retail's three loads before its three stores.
The transform selects the existing model/effect handle from the resource type,
keeps the missing-handle diagnostics, and applies Y, X and Z rotations followed
by scale and translation. The effect branch constructs a complete 64-byte
matrix, copies all sixteen words to its complete output matrix and forwards it
to the existing effect provider.

The old draft split float-vector copies into mixed integer/scalar accesses and
represented the initializer storage as an array of padded integer/float pairs.
Its fourth initializer had separate storage from the scale actually passed to
the model. Four genuine `RwV3d` locals reproduce the original initialization:
Y axis `(0,1,0)`, X axis `(1,0,0)`, Z axis `(0,0,1)` and scale `(2,2,2)`.
The same scale local subsequently receives the resource's actual scale.
The initializer values were read from retail; no extra state or side effect
was introduced to obtain registers or stack space.

Each matrix is sixteen `u32` words. Keeping the input/output matrix lifetimes
and copy cursor/count declarations in their measured order restores the
retail stack slots and registers without assembly or allocation barriers.
The existing ascending switch retains retail's descending comparisons and
ascending arm layout. The previous floor notes remain in the retained
`before.c` and the existing V2 archive.

## Contracts and independent references

The current references were inspected at
`docs/ghidra_headstart/src/promoted/code1_0014.c:1011` and
`docs/ida_headstart/src/promoted/code1_0014.c:1088`, together with the complete
retail fallback assembly and `docs/probe_archive/V2_00146a10_body.c`.
Both current decompilers recover the two full 64-byte matrices. IDA retains
all four initializer pairs; Ghidra omits the overwritten scale initialization.
Their inferred wide integer/pointer returns and missing float arguments were
not adopted.

Real first-party contracts were checked in `src/Graphics/Model/mdlManager.c`:
0047a1a0 takes matrix and axis storage, a float angle and a signed combine
operation; 0047a1e0 is `mdlScale(Model *, const RwV3d *, int)`; 0047a180
forwards the matrix translation API. The target's private scale declaration
now agrees with the existing provider. `src/Scene/mt_scene.c:153` and
`include/scene_event_internal.h` establish 00146f50's sixteen-word output and
two three-float inputs. `src/promoted/code1_004b.c:248` establishes 004b12e0's
`s32` effect handle and byte-addressed matrix input; its target-local
declaration now agrees.

Callers in `src/mt_scene/mt_scene.c`, `src/Scene/mt_sceneFunc.c`, and
`src/Event/evtMain.c` pass the corresponding three-float vectors and use the
existing four-pointer signature. No caller, provider, shared header or vendor
implementation was edited. Their observed hashes are retained in
`prepared.json`; validation records any concurrent drift explicitly.

## Measurements and proof

All new experiments are unique destinations below
`build/continue-first-party-20260922/resource-transform/`.

| Native source shape | Differing masked words | Emitted bytes |
| --- | ---: | ---: |
| Retained live census draft | 72 | 1100 |
| Three-float input copies | 57 | 1100 |
| Input copies plus shared scale storage | 52 | 1100 |
| Separate vector lifetimes | 29 | 1100 |
| Correct matrix storage/copy lifetimes | 16 | 1100 |
| True three-float initializer values | 0 | 1100 |
| Cleaned canonical final source | 0 | 1100 |

The final target has **53 resolved code relocations**, **four actual zero
suffix bytes**, and **four 12-byte owned initializer sections**, independently
proved at `005ef990`, `005ef9a0`, `005ef9b0`, and `005ef9c0`.
Every emitted instruction and all 48 owned bytes equal retail after actual
relocation. All original allocated data is preserved. The only additional
allocated sections are those four completely proved vectors.

`final-native/compile.json` binds the exact final source and actual native
owner object. `candidate-official/` and `production-official/` each run the
official verifier against that retained native object with explicit source,
compiler, flags and input checks. Their reuse is recorded; they do not run a
second compiler. The target and all remaining statuses are checked, rather
than treating verifier exit zero alone as evidence.

`final-native/unmasked-proof.json` and `final-native/independent-proof.json`
provide two separately implemented relocation/data checks.
`validation.json` repeats the independent proof on the integrated source and
compares all 125 sibling functions. Lint exits zero with no errors and two
unchanged H003 advisories outside the target. Scoped `git diff --check` passes.
No full build, link, test suite, commit, push or gameplay claim is made.

| Identity | SHA-256 |
| --- | --- |
| Before source | `7a8d29f602423e1c96d5da0b55d27dde79131900a8d8cc792f8969595b000a8c` |
| Final source | `5cecefee83b21efb17cc5c5f5a26df3b98ab2f0e360a394c7e38f3df35e36fa3` |
| Final native owner object | `ffcde68d476ddfb8928bc27bb4ace95ab1810151e7941543c2422c7c2b182c3e` |
| Resolved target bytes | `47622b6b15fb9afd209807e2ce0cd1e49e4bbe1bbcc0ed392d9f00eb2e4ddbd5` |
| Native compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

## Operational record

Completed sessions: source/retail inspection 12131; initial probes 92452;
vector/lifetime probes 31944; cleaned probe 19100; final preparation/official
candidate 22446; integration 24579; production official and validation 9900.
All exited zero. A nonfatal Python pywin32 bootstrap warning precedes native
helper runs. One prime progress message was blocked before dispatch; the
subsequent message succeeded.

The initial generic external-symbol resolver cannot resolve anonymous owned
constants. Its stale rejection flag left `exact:false` in the first two
zero-word exploratory `result.json` files even though their full and
independent owned-data proofs succeeded. Those completed files remain intact.
The corrected helper clears that preliminary diagnostic after full proof;
`reviewed-vectors/` and `final-native/` report zero unmasked words and exact
true. The final accepted evidence is the latter and `production-official/`.
