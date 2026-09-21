# Camp detail renderer `00130ce0`

Recovered on 2026-09-20 in `src/promoted/code1_0013.c` with the configured
MWCC 3.0.1 b210 compiler and the owner's `-O2 -Iinclude` flags. The actual
edited owner reports `MATCH`. No compiler configuration or shared tool changed.

The former guarded body treated adjacent scalar locals as an eight-byte
position, placed the palette in the upper half of an unrelated union, and
reloaded the border height to compensate for discarded conversions. The
recovery gives each position a complete `PackedVec2f` object and each color a
complete four-byte union. Both border draws consume the original height. The
original Y component remains available while the input position's Y component
is adjusted for the border. A single sprite pointer is reused through the draw
pairs, including the final palette draw. These actual object and value lifetimes
reproduce the retail load order without register forcing, volatile accesses,
assembly, fake effects, or reads beyond a declared object.

## Complete interface change

The sole `0012e9d0` caller now passes a `PackedVec2f` member of its existing
eight-byte position union. It uses the shared definition from
`shd_misc_internal.h`; the existing `0012d630` position typedef becomes an alias
of that same `Vec2f`, preserving compatibility with the shared declaration.
Both the default whole owner and a separately activated C `0012e9d0` witness
preserve all 82 function bodies, relocations, and allocated data.

`00112300` is declared with its actual float second parameter. Its remaining
guarded `00135130` call is reordered accordingly. Other defects in that guarded
function remain separate work and are not claimed as recovered here.

The final label call uses the depth-first `002bc4b0` contract consistently in the
provider and both caller owners. The provider retains the item and integer
coordinates as parameters and captures the remaining real inputs before its
metadata queries. Scoped `opt_propagation off` preserves its original entry
sequence. In `002055d0`, explicit `labelX`, `labelY`, and signed `item` values
preserve the original conversions before the depth-first call. The existing
camera changes in `code1_0020.c` remain intact.

## Exactness and preservation

| Evidence | Result |
| --- | --- |
| `00130ce0` resolved code | 1476 exact bytes in a 1488-byte retail window |
| Renderer relocations | All 14 resolved; no masked differences accepted |
| Renderer suffix | 12 zero bytes |
| `002bc4b0` resolved code | 740 exact bytes in a 752-byte retail window |
| Provider relocations | All 27 resolved |
| Provider suffix | 12 zero bytes |
| Provider owned table | All 24 bytes and six relocations at `007488d0` exact |
| Original renderer neighbors | All 42 function bodies and relocation records unchanged |
| Provider owner | All 75 function bodies and relocation records unchanged |
| Position caller owner | All 82 function bodies and relocation records unchanged |
| External label caller owner | All 146 function bodies and relocation records unchanged |
| Allocated owner data | Bytes, sizes, alignments, and canonical relocations unchanged in all four owners |
| Actual current verifier | 346 rows: 320 `MATCH`, 26 `ASM`; no other statuses or wrong symbols |
| Guarded renderer-owner compile | Every `NON_MATCHING` C arm compiles after the declaration changes |

The four earlier Camp matches `0013c700`, `0013ea20`, `0013f720`, and `0013fb50`
remain `MATCH`. The provider table resolves to `002bc528`, `002bc588`,
`002bc5e8`, `002bc648`, `002bc6a8`, and `002bc708`. Its resolved SHA-256 is
`c5f9e36056b85bdf76d282accfddf1526a2182c0b3283b5e1b82401f6723e98a`.

## Reproducible evidence

Private immutable artifacts are under `build/first-party-next/camp/`:

- `inputs.json` and `inputs/`: initial source, compiler, configuration, headers,
  extracted assembly, and retail identities; the existing successful owner
  baseline was reused only after its source hash matched.
- `r21-caller-depth-first/`: first exact renderer; initially rejected until its
  real provider and external caller were also preserved.
- `r23-provider-retained-inputs/retained-prefix/`: exact provider preservation.
- `r24-caller-closure/`: default and activated C position-caller witnesses, plus
  the current camera owner's immutable baseline.
- `r26-caller-label-arguments/`: all 146 external caller-owner functions preserved.
- `r27-resolved-contract/`: renderer, provider, and owned-table unmasked proof.
- `r28-final-source/`: readable final source, complete reviewable patch, source
  identities, final compilation, and successful all-guarded C compilation.
- `r29-official-current/`: actual edited-owner objects, official verifier rows,
  renewed unmasked code/table proof, and complete owner-isolation records.

Compiler SHA-256:
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

Final source SHA-256 values:

| Owner | SHA-256 |
| --- | --- |
| `code1_0013.c` | `e8b3d4a4c9b087cfacc9abd107a99b7726cacd5ec3a138cc91eeeb615b0b6af9` |
| `code1_002b.c` | `bad252d6f8ff315414c44c82da553196e20d257b45889c22bf90c10c394326d2` |
| `code1_0012.c` | `21d913d5eae4f0a0983ae771b535b76024bc1ad75825d0ae1014cd5313498cab` |
| `code1_0020.c` | `d4bbc6bddc4feb734b56562add74cda65adbcc2cbdf237c6ab9b998d1a55307f` |

The renderer's resolved code SHA-256 is
`1b9a37cf7510a005a52f15a51a0171396ed34ad02c2cdc7dc7d6ea9b03fece24`.
The final source produces object SHA-256
`c0454a1e3e5c3feb042129e1d66f5a3d2946f6b9db30d523361fd8081661ce96`.
Object/source/command identities for every additional witness are retained with
the corresponding artifact. The full linked-image and publication gates remain
with the prime; no worker commit or full build was run.

Earlier failed source variants and the old rounds 1–13 remain preserved under
`build/first-party-resume-persist/camp-next/` and the new numbered rounds. Neutral
height/position probes were not replayed. The rejected depth-first provider
changed four entry words; the first external caller migration changed three
conversion-order words. Neither partial match was integrated.
