# Map update C recovery: func_002add90

The installed `src/promoted/y_smap.c` promotes `func_002add90` to exact C.
It emits 1924 bytes in the 1936-byte retail window; the remaining 12 retail
bytes are zero. All 72 target code relocations resolve to retail. No padding
instructions or altered function boundary are used.

The complete owner now verifies as **34 MATCH / 2 ASM**, previously
33 MATCH / 3 ASM. All 35 other production functions retain their resolved
bytes and sizes. The proof resolves all 613 owner code relocations and all
33 data relocations, including the new eight-entry switch table. The 140
owned data bytes equal retail; the baseline owner had 104 owned data bytes.

## Source contracts and representation

`func_002ac750` takes two byte coordinates. The change updates both its
declaration and its actual guarded definition to `u8, u8`. Every original
parameter use masks to eight bits, and the narrowed provider has identical
guarded machine code and canonical relocations. The nine incoming retail
calls all belong to `func_002add90`; neither an additional caller nor a
callback reference was found. The coordinate conversion routines retain
their actual by-value vector arguments and wide integer returns.

`D_007EFA04` is accessed as pointer-slot storage. Loading its first pointer
before reading offset `0x220` fixes the current owner's address contract.
Declarations for the symbol-task providers, task validity check, and unit
coordinate getters agree with their definitions.

Map fields are read through byte offsets from the complete map allocation.
There is no C row-array indexing in the recovered function. Cells occupy
`0x10` bytes and rows occupy `0x100` bytes; the neighbor displacement is part
of the field offset. Ordinary byte coordinates use unsigned offsets, while
the coordinate promoted for a neighboring position uses signed arithmetic.
Those distinct arithmetic domains preserve the retail offset lifetimes
without introducing a row-boundary violation.

The position provider writes a complete three-float snapshot on every path,
including its zero-vector path when the model is absent. The caller supplies
an aligned `YVec3f` and reads the same object through the provider's byte
interface. The relative-position outputs are also complete vectors. The
visibility mask is a real `u16` value, computed only after the tile-coordinate
bounds check. Actor enumeration and tile iteration have separate counters.

The earlier exact typed-grid candidate is retained only in scratch as
diagnostic evidence. It was not installed because neighbor subscripts could
cross C subarray bounds. Correcting each coordinate's arithmetic domain
produced the exact byte-offset version used here.

## Replay

Run from the repository root with the existing local compiler and retail ELF
configuration:

```text
python docs/probe_archive/Smap_update_002add90_20261006/replay.py --out build/smap-002add90-replay
python tools/verify.py src/promoted/y_smap.c --json build/smap-002add90-verify.json
```

The replay output directory must be new. The replay reads the baseline owner
from commit `4b32b6ccbb935945461838d8981ba508f675358a`, checks both source
hashes, and compiles the entire baseline and installed owners in normal and
`NON_MATCHING` modes. It proves every production function, owned data
section, and relocation, then compares every guarded function. Its helper
is included here; it does not depend on an ignored `build/` Python module.

The replay was executed successfully with output at
`build/finish-20261006/field-worker3/installed-proof`. That directory retains
both full sources, all four objects and compile logs, resolved target bytes,
complete owner relocation records, guarded comparisons, and the source diff.
`receipt.json` here retains the input bindings, target relocation proof,
owned-data proof, sibling summary, and verification results.

The archive distinguishes `baseline_source_inputs` from
`installed_source_inputs`. In the raw replay output, `source_inputs` refers
to the installed owner and its current include closure; the baseline owner
has a separate source hash. The compiler flags are unchanged `-O2 -Iinclude`.

## Remaining work

`func_002ac750` and `func_002ae630` remain ASM in the production build. The
coordinate provider's guarded body is unchanged by its corrected signature.
The constructor's guarded body changes from 3588 to 3596 bytes because its
two accesses to the shared unit-pointer storage are corrected; its masked
byte differences decrease from 2577 to 2460. All other non-target guarded
bodies and canonical relocations are unchanged.

The old `smapUnitPresent` inline helper and its preceding recovery comment
have no remaining caller. They were left untouched after the prime froze
the installed owner for the integrated build. The proof accounts for every
emitted function symbol; this unused helper emits no extra function.

The ordinary verifier exits successfully with 34 MATCH / 2 ASM. Focused lint
reports zero errors and 11 existing warnings outside this recovery, and
`git diff --check` passes. Repository-wide link validation and git operations
are handled by the prime.
