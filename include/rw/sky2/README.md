# RenderWare Graphics 3.5 - PlayStation 2 (sky2) exported headers

Verbatim copy of `rwsdk/include/sky2` from the RenderWare Graphics 3.5
PlayStation 2 SDK (`source/rwsdk-v3.5-ps2`): 57 `.h`, 52 `.rpe` error
enumerations and 2 `.def` files, unmodified.

## Why these are here

The tree reconstructs RenderWare from the **3.7.0.2 source release**
(`source/rwsrc-v3.7.0.2`), and that release ships `core`, `world`, `collis`
and `toon` but **no platform driver**. Everything under `driver/sky2` - the
PS2 renderer, the DMA packet builders, the VU1 pipeline uploads, the texture
cache - has no source and no declarations anywhere in the tree. The headers
we do have for that layer are the *null* driver's (`include/rw/drvnull`,
`include/rw/p2null`, `include/rw/worldp2null`).

These 3.5 headers are the only declaration of the real PS2 driver surface we
have. `rwcore.h` alone carries 116 `Sky*` names, 11 `skyTexCache*` and 77
`_rwDMA*` where the 3.7 null-driver `include/rw/inc/rwcore.h` carries zero.

## What they are NOT for

**Do not put `include/rw/sky2` on the b119 include path.** Measured: doing so
puts a 3.5 `<rwcore.h>` in front of the 3.7 one and 61 of the 62 matched
`src/renderware/world` functions stop compiling, because 3.5 predates the
memory-hint allocator API that the 3.7 sources call on every allocation -
`rwMEMHINTDUR_FUNCTION`, `rwMEMHINTDUR_GLOBAL` and the extra `RwMalloc`
argument do not exist in 3.5. Retail is 3.7: those hint constants are present
in matched retail code.

So the two sets are not interchangeable, and a sky2 unit written against
these headers will have to reconcile that difference the same way - expect
the 3.7 spelling to be the one retail used.

## What is already known to be right

The PS2 alignment rules in these headers agree with retail and the tree
already models them in `include/rw/ps2/ostypes.h`:

| | 3.5 sky2 | 3.7 `inc/` (null) | retail |
|---|---|---|---|
| `RWALIGN(type, x)` | `__attribute__((aligned(x)))` | `type /* nothing */` | - |
| `rwMATRIXALIGNMENT` | 16 | `sizeof(RwUInt32)` = 4 | - |
| `rwFRAMEALIGNMENT` | 16 | 4 | **16**, the `addiu $6, $0, 0x10` in `_rwFrameOpen` at `0x003E8DC0` |
| `sizeof(RwFrame)` | 176 | 164 | **176**, `frameTKList.sizeOfStruct` at `0x0070B7A0` |

The units under `src/renderware/` reach `ostypes.h` through the per-module
source headers and so already compile at 176/400/16. The eleven
`src/renderware/world` units, though, include `<rwcore.h>`, which only exists
in `include/rw/inc` - so they are compiled against `RwFrame` = 164 and
`rwMATRIXALIGNMENT` = 4 today. That is latent rather than active: the two
layouts differ only in trailing padding, every field sits at the same offset,
and all 62 functions match. It will bite the first function that takes a
`sizeof` of one of those structs or indexes an array of them.

## Local additions outside this directory

These headers were exported for Sony's GCC EE toolchain and need two things
this tree does not otherwise have. Neither file is vendored; both are ours:

- `include/rw/ps2/eetypes.h` - `#include <eetypes.h>` in the `os/sky`
  ostypes block. Only `long128` and `u_long128` are actually reachable from
  these headers, and MWCCPS2 spells that type `__int128` (measured:
  `long128` is not a keyword, `__int128` compiles at 16 bytes).
- `include/rw/gcc/ee/include/string.h` - `#include
  <../gcc/ee/include/string.h>` resolves against each `-I` directory in turn,
  so this is where that relative path lands from `include/rw/sky2`. It
  forwards to the existing `include/rw/std/string.h` shim.

`sizeof(long)` is 8 under this compiler's EABI64, so sky2's
`typedef long RwInt64` is already correct and needs no help.

## Verified usable

```
mwcc b119 -O4 -nosyspath -Iinclude/rw/std -Iinclude/rw/ps2 -Iinclude/rw/sky2
```
compiles a TU that includes `rwcore.h` and `rpworld.h` and takes the size of
eighteen core and world structs, with no errors and no warnings.

## What these headers still do not give you

An exported header describes an API. The driver's own objects - the texture
cache, the raster extension, the DMA packet builders - live in `.c` files
the SDK never shipped, so `rwcore.h` here *casts to* `_SkyRasterExt` and
`_SkyTexCache` without ever defining them. Two more, `rwDMA_flipData` and
`rwDMAReadCircuitOneTag`, are written out but sit behind
`#if (defined(_LIBGRAPH_H) && defined(_EEREGS_H_))`, and this tree has no
Sony `libgraph.h`, so the preprocessor never reaches them.

Those thirteen structures were recovered from DWARF debugging information
instead and live in `include/rw/sky2priv`, which documents the provenance
and the checks against Persona 4 retail.
