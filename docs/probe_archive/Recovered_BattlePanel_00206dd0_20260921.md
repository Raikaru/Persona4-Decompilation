# Battle selection panel: 00206dd0

Recovered `func_00206dd0` in the actual current `src/promoted/code1_0020.c`
with the configured b210 compiler. The integrated function emits 868 bytes
for an 880-byte retail window. All 17 code/data relocations resolve exactly;
the remaining 12 bytes are zero alignment. All 145 other functions retain
their complete bytes and canonical relocations, and allocated data is unchanged.

## Contracts and implementation

The matched callers `func_00208d00` and `func_00209370` already passed the
coordinates before the drawing callback. The retained candidate declared the
callback before the coordinates. `BattleSelectionDraw` now also describes the
callback providers' actual order: work, signed slot, two coordinates, byte
opacity, highlighted flag, detail flag. The callers use the shared declaration
without generic function-pointer casts.

`func_002055d0` already takes byte opacity. The skill provider `func_00205170`
stores its opacity with `sb`, masks it with `andi 0xff` for packed text colors,
and forwards it to byte-color drawing calls. Its declaration and retained
body now use `u8` consistently. Its production ASM and every other production
function remain unchanged.

The state setter is the first function pointer at `D_00887300`. A real
single-entry dispatch view lets the compiler retain that address within each
phase. The base is obtained again after drawing the sliding panel strips.
This removes the first call's redundant absolute-address load and restores
the second phase's base materialization. No state values or calls were added.

The remaining fraction, product, and pixel offset are separate float values.
The copies preserve the retail `sub.s`, `mul.s`, integer-to-float conversion,
and plain `add.s` sequence. This corrects the former assumption that an
unobserved second use of the product was required. No extra arithmetic,
intrinsics, assembly, uninitialized values, volatile accesses, or padding
were used.

## Evidence and reproduction

Read the complete retail window, both retained IDA/Ghidra reconstructions,
both current callers, both callback providers, and the rectangle provider
`func_0045d6e0` before integration. The old floor remains in the frozen input
snapshot at
`build/continuation-20260921/battle-worker6/00206dd0/inputs/src/promoted/code1_0020.c`.

The current-owner proof is
`build/continuation-20260921/battle-worker6/live-00206dd0/current/result-decoded.json`.
Its siblings and allocated-data comparison is also saved as `preservation.json`.
`live-00206dd0/inputs.json`, `current/compile.json`, and `release.json` record
the frozen inputs, exact command, compiler hash, and output hashes. The
baseline object was reused from `campaign-checkpoint/continued-65`, after
checking its source, object, compiler, and current include-dependency hashes.
The manually integrated owner was then compiled afresh.

| Artifact | SHA-256 |
| --- | --- |
| Current owner | `0a1e20bcc30510433289fb0edf45597705c133983245bda128d1e859eba25482` |
| Current whole object | `4bc9ca9617f4318b87819a2b274bac3caee8c19159b94f0c9c1327a84ae1aad7` |
| Resolved function | `05cd81d97c2d3403f28bc304c7b697ba085d47a9374b825a23fbaada33566e86` |
| Retail window | `cd00273399f45ad04b1189c4b7a7b72fce65747e409734f2cfea947220f3ebea` |
| Configured compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

Run `python -S build/continuation-20260921/battle-worker6/prove_panel_live.py`
to recheck the immutable current-owner receipt and exact relocation comparison.
`git diff --check -- src/promoted/code1_0020.c` passed. No commit, push,
rebase, or full-project build was performed.
