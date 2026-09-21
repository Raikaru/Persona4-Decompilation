# RenderWare sky2 driver-internal layouts, recovered from DWARF

`skypriv.h` is **generated**. It holds the PlayStation 2 driver structures
that no header in this tree declares, recovered from the debugging
information in a retail game that compiled RenderWare from source.

Regenerate with:

```sh
python3 -E -s tools/rw_dwarf.py <reference-elf> \
    --header include/rw/sky2priv/skypriv.h \
    --json   docs/sky2/ballers_structs.json \
    --from-unit driver/sky2 \
    --skip-complete-in rwcore.h \
    --include include/rw/sky2 --include include/cri/ps2 --include include/rw/std
```

## Why it exists

`include/rw/sky2` is the 3.5 SDK's *exported* headers, and an exported
header describes an API, not an implementation. The driver's own objects -
the texture cache, the raster extension, the DMA packet builders - are
declared in `.c` files that the SDK never shipped, so the tree had names for
them (`RASTEREXTFROMRASTER` casts to `_SkyRasterExt`) and no definitions.

Two of them, `rwDMA_flipData` and `rwDMAReadCircuitOneTag`, *are* written out
in `sky2/rwcore.h`, but behind

```c
#if (defined(_LIBGRAPH_H) && defined(_EEREGS_H_)) || defined(DOXYGEN)
```

and this tree has no Sony `libgraph.h` or `eeregs.h` - the July 2005 SDK ISO
is a Wise installer whose payload resists extraction. The preprocessor never
reaches those definitions here, so they are incomplete types in practice and
the generator emits them. That distinction is decided by **compiling** a
`sizeof` probe, not by grepping for a definition; see `complete_types`.

## Where it comes from

NBA Ballers: Phenom (SLUS-21186, 2006-02-09 review build). Its `.debug`
section is 35 MB of DWARF **version 1** - a format binutils dropped long ago,
which is why `tools/rw_dwarf.py` parses it directly. Every one of its 1341
RenderWare compilation units names `MW MIPS C Compiler` as producer, the same
compiler family as this tree's MWCCPS2 3.0.1 b119 RenderWare block, and it
carries the driver sources by path:

```
C:\mwy\BALLER~1\main\Libs\RW\Graphics\rwsdk\driver\sky2\{basky,badma,skyinst,texcache,skyblit,skyconv}.c
```

## Why the layouts are trustworthy here

Ballers is a *different RenderWare release* from Persona 4's - of the 392
RenderWare functions this repo already names, 356 exist in Ballers but only
222 have the same size and only 72 are masked-identical. So its **code** is
not Persona 4's code and nothing here should be transcribed as such.

Its **layouts**, however, were checked against Persona 4 retail directly.
RenderWare records each class's size in a plugin registry, and Persona 4's
registries hold exactly the sizes Ballers reports, at twelve distinct
addresses:

| class | size | Persona 4 registry |
|---|---|---|
| `RwFrame` | 176 | `0x0070B7A0` |
| `RwCamera` | 400 | `0x0070B710` |
| `RwRaster` | 52 | `0x0070B7E0` |
| `RwTexture` | 88 | `0x0070B800` |
| `RpAtomic` | 112 | `0x0070AF70` |
| `RpWorldSector` | 136 | `0x0070B040` |
| `RpMaterial` | 28 | `0x0070B7C0` |
| `RpGeometry` | 96 | `0x0070AFB0` |
| `RpLight` | 64 | `0x0070AFD0` |
| `RpClump` | 44 | `0x0070AF90` |

Twelve of twelve. Note that 176 for `RwFrame` is also the value the tree
independently derived from `frameTKList.sizeOfStruct`, and that
`include/rw/inc` - the 3.7 *null driver* headers - gives 164 instead. On
layout, Ballers describes Persona 4's RenderWare better than the headers the
tree currently compiles against.

The two structures the 3.5 SDK header defines completely and reachably,
`RwSkyVideoMode` and `_SkyCameraExt`, agree with Ballers member for member,
which is a third independent check. They are therefore *omitted* from
`skypriv.h`; the SDK header remains their definition.

## What else came out of the same parse

- `docs/sky2/ballers_structs.json` - all 832 structures, with member names,
  byte offsets and C types.
- `docs/sky2/ballers_sky2_units.json` - 271 driver functions grouped by the
  source file that defines them, with addresses and sizes. **99 are
  file-static**, so no symbol table in any shipped game can name them; debug
  information is the only route to those names.
