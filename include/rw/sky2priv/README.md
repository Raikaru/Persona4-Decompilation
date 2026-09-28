# RenderWare sky2 private layouts

`skypriv.h` is generated from the DWARF 1 debugging information in the
February 9, 2006 review build of *NBA Ballers: Phenom* (`SLUS-21186`). It
supplies PS2 driver structures that the exported SDK headers leave
incomplete, including texture-cache and DMA packet types.

Ballers uses a different RenderWare release. Its layout information is
reference evidence, not permission to assume its code or every private
field matches Persona 4.

## Regeneration

From the repository root, with a privately supplied reference ELF:

```sh
python tools/rw_dwarf.py /path/to/reference-elf \
    --header include/rw/sky2priv/skypriv.h \
    --json docs/sky2/ballers_structs.json \
    --from-unit driver/sky2 \
    --skip-complete-in rwcore.h \
    --include include/rw/sky2 --include include/cri/ps2 --include include/rw/std
```

`--skip-complete-in` compiles `sizeof` probes to find types already complete
in the selected headers. It does not infer completeness from text search.
For example, `rwDMA_flipData` and `rwDMAReadCircuitOneTag` occur in the SDK
header behind this condition:

```c
#if (defined(_LIBGRAPH_H) && defined(_EEREGS_H_)) || defined(DOXYGEN)
```

Without those definitions in the compilation environment, the generator
still needs to emit the types. `RwSkyVideoMode` and `_SkyCameraExt` were
complete in the measured setup and agreed with Ballers member for member;
they were omitted from the generated header.

## Source provenance

Ballers' 35 MB `.debug` section uses DWARF version 1, parsed directly by
`tools/rw_dwarf.py`. Its 1,341 RenderWare compilation units name
`MW MIPS C Compiler` as producer and include paths such as:

```text
C:\mwy\BALLER~1\main\Libs\RW\Graphics\rwsdk\driver\sky2\{basky,badma,skyinst,texcache,skyblit,skyconv}.c
```

This is the same compiler family as Persona 4's MWCCPS2 b119 RenderWare
block, not proof of identical code generation. Of 392 named Persona 4
functions in the original comparison, 356 existed in Ballers, 222 had the
same size and only 72 were relocation-masked identical.

## Checks against Persona 4

The recorded plugin-registry sizes include:

| Class | Size in bytes | Persona 4 registry |
| --- | --- | --- |
| `RwFrame` | 176 | `0x0070b7a0` |
| `RwCamera` | 400 | `0x0070b710` |
| `RwRaster` | 52 | `0x0070b7e0` |
| `RwTexture` | 88 | `0x0070b800` |
| `RpAtomic` | 112 | `0x0070af70` |
| `RpWorldSector` | 136 | `0x0070b040` |
| `RpMaterial` | 28 | `0x0070b7c0` |
| `RpGeometry` | 96 | `0x0070afb0` |
| `RpLight` | 64 | `0x0070afd0` |
| `RpClump` | 44 | `0x0070af90` |

These sizes agree with Ballers. In particular, retail's 176-byte `RwFrame`
agrees with the PS2 layout rather than the 164-byte null-driver definition.
Equal total sizes do not prove every member offset or the layout of an
unrelated private structure; verify the fields used by each recovery.

## Related evidence

- [`ballers_structs.json`](../../../docs/sky2/ballers_structs.json): the
  recorded structure parse, with member names, offsets and C types.
- [`ballers_sky2_units.json`](../../../docs/sky2/ballers_sky2_units.json):
  driver functions grouped by source unit, including file-static functions
  named by debug information rather than exported symbols.
- [Sky2 recovery notes](../../../docs/sky2/README.md): attribution and the
  limits of cross-game name transfer.
