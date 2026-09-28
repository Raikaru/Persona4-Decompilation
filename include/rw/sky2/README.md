# RenderWare 3.5 PS2 exported headers

This directory contains the RenderWare Graphics 3.5 PS2 SDK's
`rwsdk/include/sky2` headers: 57 `.h` files, 52 `.rpe` error enumerations
and two `.def` files. They were imported unmodified as a reference for the
PS2 driver API.

The RenderWare 3.7.0.2 source used by this project includes `core`, `world`,
`collis` and `toon`, but not the `driver/sky2` implementation. The 3.5
headers supply declarations absent from the 3.7 null-driver headers,
including `Sky*`, `skyTexCache*` and `_rwDMA*` interfaces.

## Do not replace the 3.7 include path

Putting this directory before `include/rw/inc` makes `<rwcore.h>` resolve to
3.5 instead of 3.7. A recorded test broke compilation of 61 of 62 matched
`src/renderware/world` functions: 3.5 lacks the memory-hint allocator API,
including `rwMEMHINTDUR_FUNCTION`, `rwMEMHINTDUR_GLOBAL` and the additional
`RwMalloc` argument. Matched retail code uses the 3.7 API.

Use these headers to investigate the driver, not as a wholesale substitute
for the headers used by existing 3.7 units.

## Alignment evidence

The PS2 alignment rules agree with retail and are modeled separately in
[`../ps2/ostypes.h`](../ps2/ostypes.h):

| Property | 3.5 sky2 | 3.7 null driver | Retail evidence |
| --- | --- | --- | --- |
| `RWALIGN(type, x)` | Explicit alignment attribute | No attribute | Check each layout. |
| `rwMATRIXALIGNMENT` | 16 | 4 | PS2-specific alignment. |
| `rwFRAMEALIGNMENT` | 16 | 4 | `_rwFrameOpen`, `0x003e8dc0`, passes `0x10`. |
| `sizeof(RwFrame)` | 176 | 164 | `frameTKList.sizeOfStruct` at `0x0070b7a0` is 176. |

A function can match despite using the null-driver layout when the
accessed fields have the same offsets and only trailing padding differs.
That does not validate `sizeof`, array strides or allocation sizes. Check
the header actually selected by a unit before relying on those properties.

## Local support headers

These project shims sit outside the imported directory:

- [`../ps2/eetypes.h`](../ps2/eetypes.h) supplies the EE scalar types.
  MWCCPS2 uses `__int128` for the 16-byte `long128` / `u_long128` types;
  `long128` is not a compiler keyword.
- [`../gcc/ee/include/string.h`](../gcc/ee/include/string.h) resolves the
  SDK's relative string-header include and forwards to the existing shim.

Under the measured MWCCPS2 EABI64 configuration, `long` is 8 bytes, so the
SDK's `typedef long RwInt64` has the required width.

A recorded b119 probe included `rwcore.h` and `rpworld.h` and measured
18 core/world structures without warnings, using these flags:

```text
-O4 -nosyspath -Iinclude/rw/std -Iinclude/rw/ps2 -Iinclude/rw/sky2
```

That header probe is not a substitute for the configured `-O4,p` matching
build.

## Private layouts

The exported API refers to private objects such as `_SkyRasterExt` and
`_SkyTexCache` without defining them. Other definitions require Sony header
guards, so their presence in the text does not make them available to every
translation unit.

[`../sky2priv/`](../sky2priv/README.md) contains layouts recovered from
DWARF in a reference game. Use its provenance and retail checks before
applying a private layout to Persona 4.
