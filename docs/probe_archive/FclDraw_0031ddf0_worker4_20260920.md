# Fcl selection colors: func_0031ddf0

Recovered ordinary C in `src/Event/Fcl/y_fclCombineDraw.c`. The complete
`0x0031ddf0..0x0031e320` retail window is 1328 bytes. The configured MWCC
3.0.1 b210 `-O2` build reproduces all 1328 bytes after resolving all 31
relocations. There is no suffix and no target-owned data. No assembly,
artificial storage, volatile accesses, or optimization pragmas were added.

## Source evidence

The complete retail assembly, Ghidra and IDA bodies, the current guarded
source, the prior `LaneC_0031ddf0_body.c` and `P01C_0031ddf0_body.c` archives,
and all actual callers were inspected. The prior worker5 recoveries and
the exact neighboring `func_003233d0` color-packet implementation supplied
existing representation patterns.

Each of the nine color constructors has its own value. Descriptor colors
at offsets `0x75` and `0x85` are four individual byte channels. Copies read
the source descriptor after the next lookup, preserving the retail memory
accesses. The two colors passed as a word to `func_002ba970` use a union of
`FclByte4` and `u32`; they do not reinterpret an unaligned descriptor as an
integer pointer.

Each branch derives its two resource identifiers from the signed-byte
slot in 32-bit locals, narrowing only at the resource lookup. The paired
`0x6e` opacity writes are one chained unsigned-byte assignment. This
accounts for the saved `0xff` or `0x66` value and its intermediate mask.
The final packed-color call converts the original slot argument; replacing
that expression with the earlier derived identifier changes its lifetime
and the generated frame.

The final contract is `s32 func_0031ddf0(u8 *, s8, s8, u8)`. The last argument
is an unsigned opacity byte, and the function returns the packed color
from `func_002b2a30`. Retail `func_0031d630` consumes that return value.

## Measurements and immutable artifacts

Scratch root: `build/first-party-finish-20260920/fcl-current-work/`.

The baseline object was reused from
`../fcl-worker5/delivery16470/current/owner.o` only after checking the
source, object, include dependencies, compiler path, and unit flags.
The original owner source SHA-256 was
`e6e1fa81dc713b59595ce2a9d3403ba43f3521f73b60f6052e9d14d634dac06e`.

The retained progression was 271 differing words for the current guarded
body, 188 after branch-local resource lifetimes, 185 with the byte-opacity
formal, 4 with the original slot expression restored at both final color
calls, and 0 after introducing the two packed-color unions. The last four
differences were argument-load order. Short resource locals and a widened
derived slot were measured and rejected; they did not reproduce retail.

`func_0031ddf0/packed-color-contract/resolved-proof.json` records the full
code proof. The linked target SHA-256 is
`53f474e231a00454c8407eeaaf24f6f5bf80ce5c6762517f338527105270abdc`.
`delivery-ddf0/closure-proof.json` records the reviewed full-owner and
caller proofs. All 69 other functions retain identical code and canonical
relocations, and all allocated data remains identical.

## Caller closure

The reviewed package adds the signature to `fcl_combine_internal.h` and
removes the two conflicting block-local `void` declarations in
`y_fclCombine.c`. The prime integrates those coordinated owner changes.
The default combine object is identical before and after that package.
All four guarded caller bodies also retain identical code and relocations:

| Caller | Bytes | Calls to func_0031ddf0 |
| --- | ---: | ---: |
| `func_0031d630` | 1972 | 2 |
| `func_002ed430` | 14772 | 2 |
| `func_002f0f00` | 23428 | 4 |
| `func_00304580` | 17908 | 2 |

The witnesses compare current caller C before and after the contract
correction; they do not claim those still-guarded callers match retail.
Their ordered calls, all other owner functions, and allocated data are
unchanged. Each witness, compiler receipt and source snapshot is retained
under `delivery-ddf0/draw/` or `delivery-ddf0/combine/`.

## Initial live integration proof

After the prime integrated the shared prototype and removed the combine
declarations, `deliver_ddf0.py current` ran the official `verify_file`
path against the actual owner and current headers, retaining its object.
The result is **44 MATCH / 26 ASM**, with no mismatch or compile error.
The same object then passed full relocation and zero-suffix proofs for
`0031ddf0`, `00316470`, `003297f0`, `0032a960`, `0032b000`, `0032f4d0`, and
`003233d0`. All 69 neighboring functions and all allocated data remain
unchanged against the validated pre-promotion baseline.

`delivery-ddf0/current/proof.json` binds the source, object, compiler binary,
unit flags, dependency hashes, sibling comparisons, and seven target
proofs. `official-verify.json` contains the complete official result.

- Current owner SHA-256:
  `b8e2988f5ed2add4e1ea479d9cfa6ff1fe37d5490510eed8e74e14ac75437b26`
- Current object SHA-256:
  `427d2b03b4205f6da8e7bb88014f3398ffa89823fc454a663f31fe68b3db521e`

The completed live command is not a job to restart. Inspect or reuse its
saved receipt after checking the recorded input identity.

## Signed-byte getter closure

Further recovery of `func_0031d630` exposed an inherited declaration
conflict: draw declared `func_0034ae50` with an `s64` slot, while its
provider and combine callers use `s8`. The initial live proof above binds
the earlier declaration state; the final acceptance package uses the
actual signed-byte getter contract.

Changing the slot formals of `func_0031ddf0` and `func_0031e320` to `s8`
preserves both exact bodies under that corrected getter declaration.
`byte-slot-contract/default-owner-closed/closure-summary.json` proves all
70 then-existing draw functions and allocated data unchanged. The new
renderer also reproduces retail with its own consistent shared contract.

`delivery-slots/closure-proof.json` covers the final coordinated draw,
combine, and getter-provider declarations, all existing production
callers, unchanged neighboring code/data, and complete relocation proofs
for `0031ddf0`, `0031e320`, the new renderer, both getter providers, and six
earlier draw promotions. The companion
`FclDraw_0031d630_worker4_20260920.md` records the final ABI and distinguishes
the production caller proof from measurements of unpromoted caller drafts.

The final integrated signed-byte contract is sealed by
`delivery-slots/current/proof.json`. Official current-source verification
reports **45 MATCH / 25 ASM** in the draw owner, and the retained object
reproduces all 1328 bytes and 31 relocations of `func_0031ddf0` again.
The getter providers and all existing production callers also pass their
complete preservation checks. Final draw source SHA-256 is
`31d61a5d5244ad4f980e46f9eca21135b56b55e0a65dedefbab6b8bba4782bed`;
object SHA-256 is
`cc193849eb0b63608f4102bfece02b007a37940bc89adbc3d7c370d7ad5704c3`.
This final seal supersedes the initial wider-slot integration identity.
