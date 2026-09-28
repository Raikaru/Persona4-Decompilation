# Battle action, item-panel and effect-clone recovery

This batch, based on `d1bf26b`, replaces six assembly fallbacks with C that
matches the configured native compiler and is linked from its source owner:

| Function | Owner | Executable / retail window | Zero tail |
| --- | --- | ---: | ---: |
| `001203a0` | `src/promoted/code1_0012.c` | 1856 / 1856 bytes | 0 bytes |
| `00122a40` | `src/promoted/code1_0012.c` | 3220 / 3232 bytes | 12 bytes |
| `0012e9d0` | `src/promoted/code1_0012.c` | 5148 / 5152 bytes | 4 bytes |
| `001a1ea0` | `src/promoted/code1_001a.c` | 1528 / 1536 bytes | 8 bytes |
| `001a43a0` | `src/promoted/code1_001a.c` | 1092 / 1104 bytes | 12 bytes |
| `00484bb0` | `src/promoted/code1_0048.c` | 2680 / 2688 bytes | 8 bytes |

The item-panel functions use complete color and vector objects, the measured
20-byte cell stride, and the actual drawing/provider interfaces. The battle
changes preserve the target-list buffers and their signed-halfword entries,
correct word-sized task handles, and use the real packet-returning look-at
interface. Signed message identifiers are narrowed directly instead of using
signed shifts with undefined behavior.

`effect_instance_internal.h` describes the effect-constructor callback used by
the retail `0x00713480` table. Its 33 records have a 0x40-byte stride; the
constructor and destructor entries are at offsets 0 and 0x14. The constructor
returns a pointer, and all 41 definitions and 24 direct calls were reconciled.
The clone keeps the retail 0xc0-byte node stride and the observed distinction
between root and sibling copies. Temporarily borrowed pointers are restored.

All 31 installed C owners were freshly compiled. Their resulting objects are
byte-identical to the sealed, fully resolved private proof objects: 1,770
function windows, 1,764 unchanged peers, 16,213 code relocations and 524 data
relocations. The allocated data totals 2,304 bytes, all resolved against retail.
The only verifier status changes are these six ASM-to-MATCH transitions.

The new renderer reads the font pointer `iGpffff9cc8` at `0x00762db8`. Its
native zero-addend `R_MIPS_GPREL16` relocation agrees with the retail instruction
at `0x0012f558`: `lw $7,-0x6338($28)`, with GP `0x007690f0`. The curated and
generated symbol tables now include that evidenced address. An initial link
fell back to assembly for the owner because this definition was absent; the
accepted link includes the actual compiled owner and all six recovered functions.

After the two symbol-table additions, every unchanged native object was
authenticated and all public verifier comparisons and relocation checks were
run again. The final report covers all 13,102 windows: 9,516 MATCH and 3,586 ASM.
First-party matching is 6,696 / 6,861, with 165 remaining assembly fallbacks.

The accepted build links 595 C objects and 54 Sony SDK objects. No previous
physical source membership is lost. Both outputs remain byte-exact:

```
loadable image: 3d1d3d2b9d6ccb60836db239ab49674223025a78
SLUS_217.82:    4eeec0360cf2715535d9f7e52eb69d786fb0158c
```

Progress and the README status table are regenerated together from the final
verifier, link and recovery-quality reports. Native fixtures also exercise the
affinity, action, task and clone behavior, including invalid-implementation
controls; target `0012e9d0` has complete binary proof but no native behavior fixture.

Local evidence is retained in `build/batches/battle-item-clone-v1`,
`build/publication-verification/battle-item-clone-v1`,
`build/publication-verification/battle-item-clone-symbol-v2`, and the associated
`build/publication-gates/battle-item-clone-*` directories. The accepted link
receipt is `linked-v2.json`; `linked.json` records the rejected owner-fallback run.
