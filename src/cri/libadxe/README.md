# CRI ADX - reconstructed sources

Persona 4 links CRI's PlayStation 2 middleware as prebuilt vendor libraries.
The image's own banners date the whole set to Feb 28 - Mar 1 2005:

| component | version |
|---|---|
| `ADXT/PS2EE` | 9.44 |
| `ADXF/PS2EE` | 7.30 |
| `ADXPS2` | 2.60 |
| `ADXCS/PS2EE` | 1.11 |
| `CRI SFD` / `M2V` / `MPV` (Sofdec) | 1.958 |
| `CRI SFX` | 2.29 |

`src/cri/cri_adx_grouped.c` holds the block as extracted assembly - 2305
`INCLUDE_ASM` rows at the start of this work, the largest single unmatched
region in the tree.

## Where these files come from

Verbatim from the Resident Evil Code: Veronica X decompilation
(<https://github.com/AshfordFamily/recvx-decomp>, MIT, `src/cri/mwlib/ee/lib/libadxe`),
which reconstructs CRI's library as linked into SLUS-20184. Headers under
`include/cri/` come with them: the private ones from the same repository, the
public SDK ones from its `recvx-decomp-cri` submodule
(<https://github.com/SkeletonPicture/recvx-decomp-cri>), which are genuine CRI
SDK files. `include/cri/` mirrors that project's include root exactly -
including the `recvx-decomp-cri` directory name - so the vendored sources and
headers stay byte-identical to upstream and can be re-synced with a copy.

That reconstruction targets **ADXT 8.30** (Jan 2001) where Persona 4 carries
**9.44**, so it is a starting point, not a drop-in.

## Why it works anyway

Two measurements, both reproducible:

1. CRI's own `libadxe.a` from the 8.30 SDK matches **249 distinct Persona 4
   addresses byte for byte**, functions up to 210 words long
   (`build/rw35_fid.py --archive .../libadxe.a`). The two games link the same
   vendor code and much of it did not change between 8.30 and 9.44.
2. Those library objects carry `gcc2_compiled.` and `__gnu_compiled_c`. CRI
   shipped **GCC-built** libraries, not Metrowerks ones. Every MWCCPS2 build
   on disk - 2.4, 3.0.1, 3.0.3, b74, b119, b151, b198, b210 - produces the
   wrong size at every optimisation level, while ee-gcc 2.96 at `-O2 -G0`,
   the toolchain `config/gcc_units.txt` already pins for vendor units,
   produces retail's bytes.

Compiling the 47 upstream sources with that toolchain and matching every
function symbol against every retail window of equal length
(`build/adx_fid.py`) finds **112 byte-exact functions covering 73 distinct
addresses**, with 21 sources not yet compiling for want of Sony EE SDK
headers (`eekernel.h`, `libcdvd.h`, `sifdev.h`, `libgraph.h`, `mathf.h`).

`build/adx_port.py` then marks only what can be attributed unambiguously.
Several CRI functions share a body - `ADXERR_Init` and `ADXERR_Finish`
compile to the same eight words and the linker folded them - so an address
claimed by more than one function is left alone rather than guessed, the same
rule `build/rw_dedupe.py` applies to RenderWare. 55 of the 112 survive that
filter; 37 of those name addresses whose grouped-unit marker already owns a
decompiled C body, leaving **18 markers** actually taken over here.

## Status

The eleven units in `config/gcc_units.txt` verify 18/18 MATCH:

```
python3 -E -s tools/verify.py src/cri/libadxe/*.c
```

They do **not** appear in the repository's headline metric. `verify.py`
excludes `config/gcc_units.txt` units from its default scan on purpose, so
that a machine with an ee-gcc toolchain and a CI runner without one grade the
same tree identically, and `build.py` links those addresses from extracted
retail assembly rather than compiling them. The image is byte-exact either
way (`3d1d3d2b`, `4eeec036`).

That exclusion was written when GCC units held nothing but `INCLUDE_ASM`.
These are the first that carry real compiled code, so whether the metric
should now count them - and whether CI should require an ee-gcc - is an open
decision, not an oversight.

## Next

- The 21 sources blocked on Sony EE SDK headers are the largest remaining
  slice; the July 2005 SDK ISO on this machine keeps them inside an
  InstallShield payload that `7z` and `cabextract` will not open.
- 3s-decomp (<https://github.com/…/3s-decomp>, AGPL-3.0) reconstructs **ADXT
  9.00 / ADXF 7.13** - much closer to 9.44 than 8.30 - and covers AHX, AC3,
  SRD and SVM as well. Its licence makes it a reference to read rather than
  code to copy into an MIT-adjacent tree.
- Sofdec (`CRI SFD/M2V/MPV 1.958`) has no reconstruction here at all.
