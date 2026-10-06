# Map constructor C recovery: func_002ae630

The installed `src/promoted/y_smap.c` promotes `func_002ae630` to exact C.
It emits 3500 bytes in the 3504-byte retail window; the final four retail
bytes are zero. All 125 target code relocations resolve exactly. The
proposal verifies as **35 MATCH / 1 ASM**, compared with 34 MATCH / 2 ASM
at baseline commit `41a2002a50c30d68a08ca07e4a8850348796e13d`.

The complete owner proof resolves all 36 functions, 618 code relocations,
39 data relocations, and 164 owned data bytes. All 35 production siblings
retain their resolved bytes and sizes. Every non-target guarded function
also retains its bytes and canonical relocations. The existing map updater
`func_002add90` is unchanged.

## Source recovery

The multi-cell tile dispatch precedes the simple tile cases, as in retail.
All 43 map queries and nine neighboring-tile constructor calls are retained.
The row offset remains live through its row, while each column offset is
formed at use. Tile and task addresses are byte offsets into their complete
allocations; the source introduces no row-array boundary restrictions. All
nine neighboring task-slot addresses are formed completely in native `u32`
address arithmetic before conversion to a pointer, so a negative row offset
cannot create an intermediate pointer before the allocation.

Neighbor tables contain signed byte displacement pairs. The selected table
pointer has a case-local lifetime. The first orientation table is queried
independently for each field, preserving the original reads. The vertical
coordinate is formed at the constructor call; the horizontal coordinate
also supplies the subsequent task-slot address.

Function-local `opt_propagation off` retains the selected table-pointer
lifetime, and `opt_pulloutconstants off` issues screen constants where they
are used. Both are enclosed in a push/pop pair. They introduce no assembly,
dummy local, padding instruction, or function-boundary change.

The enemy-symbol pass has its own sprite, position-pointer, and index scope.
Its screen position is an initialized `YVec2f`, passed by value through the
actual `func_002b4fe0` contract. Coordinate conversion routines keep their
real by-value vector arguments and wide returns. Frame positions and colors
are complete returned objects, and all four rectangle-task handles are
stored. The scene-node model is passed to `mdlGetMatrix` as a pointer.

The sprite provider declaration now agrees with its definition in
`src/Kernel/sdkSpr.c`: `u8 *func_0046d200(u32, u32)`. Its indexed frame call
in `func_002b2290` reads the handle through the unsigned type corresponding
to its signed storage. That access is permitted by C's signed/unsigned
corresponding-type alias rule and preserves the handle's representation.
The complete sibling remains byte-identical. There is no private conflicting
provider declaration or replacement provider.

The unused `smapUnitPresent` helper and both superseded guarded-recovery
comments are removed. No unaccounted helper function is emitted. Unrelated
comment bytes are preserved exactly from the committed baseline.

## Replay

Run from the repository root with the existing compiler and retail ELF
configuration:

```text
python docs/probe_archive/Smap_constructor_002ae630_20261006/replay.py --out build/smap-constructor-replay
```

The output directory must be new. The replay reads the committed baseline
from git and reconstructs the proposal using `source.patch`, checking every
old patch line and both complete source hashes. It leaves the active owner
unchanged and remains usable after subsequent source edits.

Both complete owners are compiled in normal and `NON_MATCHING` modes with
the owner's unchanged compiler selection and `-O2 -Iinclude` flags. The
replay binds the compiler, retail image, and separate before/after include
closures. It resolves every production function and every owned data
section, compares all guarded functions, and accounts for every emitted
function symbol. The section-aware helper is included here; no ignored
`build/` helper is required.

The replay was executed successfully at
`build/finish-20261006/field-worker3/constructor-native-slot-proof`. Its output
contains four objects and compile logs, both complete sources, resolved
target bytes, the full relocation and data proofs, guarded comparisons,
and a source diff. `receipt.json` retains the target proof, sibling summary,
owned data, and source/compiler/retail bindings.

The ordinary verifier was also run directly on the proposal and reports
35 MATCH / 1 ASM. Focused lint reports zero errors and ten warnings in
existing declarations or other functions. Production installation,
repository-wide link checks, and git operations are coordinated by the
prime.

## Remaining map function

`func_002ac750` remains ASM. Its existing guarded byte-coordinate definition
and code are unchanged by this constructor recovery. The baseline constructor
guard had 3596 bytes and 2460 differing bytes after relocation masking; the
recovered constructor has 3500 bytes and zero differences, confirmed again
after full relocation resolution.

## Installation

After independent source and complete-owner review, the prime released the
revised source for installation. The installed owner hash is
`35d8ab93d63052c1ced899e77da31979df7f5de660b20a01b6a5f5574203c2f6`.
Normal verification of the actual installed path reports 35 MATCH / 1 ASM;
lint reports zero errors and ten existing warnings, and `git diff --check`
passes. The installed reports are recorded in `receipt.json`. The owner is
frozen for the prime's integrated build and git operations.
