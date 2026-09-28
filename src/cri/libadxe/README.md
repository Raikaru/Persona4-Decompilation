# CRI ADX source reference

These sources were imported from the MIT-licensed
[Resident Evil Code: Veronica X decompilation](https://github.com/AshfordFamily/recvx-decomp),
under `src/cri/mwlib/ee/lib/libadxe`. They reconstruct ADXT 8.30 (January
2001); Persona 4 uses ADXT 9.44. Treat them as a source reference, not a
version-compatible replacement for Persona 4's library.

The private headers came from the same project. Its public SDK headers came
from the [recvx-decomp-cri](https://github.com/SkeletonPicture/recvx-decomp-cri)
submodule. `include/cri/` preserves that include layout. Do not assume the
reconstruction's license also licenses the original SDK headers.

## Retail versions

Persona 4's CRI banners date the linked libraries to February 28–March 1,
2005:

| Component | Version |
| --- | --- |
| `ADXT/PS2EE` | 9.44 |
| `ADXF/PS2EE` | 7.30 |
| `ADXPS2` | 2.60 |
| `ADXCS/PS2EE` | 1.11 |
| Sofdec (`CRI SFD`, `M2V`, `MPV`) | 1.958 |
| `CRI SFX` | 2.29 |

The tree also carries the CC0 Resident Evil 4 reconstruction under
`src/cri/re4`: ADXT/GC 9.31 and ADXF 7.18, including Sofdec, MPEG and AHX
code. It is closer in version but targets GameCube. The two references have
different strengths; neither establishes a Persona 4 match by itself.

## Import measurements

The original investigation found 249 distinct Persona 4 addresses that
matched CRI's ADXT 8.30 `libadxe.a` byte for byte, including bodies up to
210 words. The archive's `gcc2_compiled.` and `__gnu_compiled_c` markers
identified GCC-built objects. The configured recovery toolchain is ee-gcc
2.96 at `-O2 -G0`, driven by `tools/eegcc_shim.py`, rather than MWCCPS2.

Compiling the 47 imported source files yielded 112 exact function matches
at 73 distinct addresses. Another 21 files were blocked by missing Sony
headers in that setup. Removing ambiguous attributions left 55 candidates;
37 already had C owners, so the initial import took over 18 markers in
11 units. Those units verified 18/18 at that checkpoint.

These figures describe the import, not the current tree. The investigation
used local scripts named `build/rw35_fid.py`, `build/adx_fid.py` and
`build/adx_port.py`; they are not checkout prerequisites.

Small identical bodies need particular care. `ADXERR_Init` and
`ADXERR_Finish`, for example, compiled to the same eight words. Bytes alone
did not distinguish their names or ownership.

## Working on these sources

Use the configured compiler and verify the current owners:

```sh
python tools/verify.py src/cri/libadxe/*.c
```

Do not infer current coverage or linkage from the import totals above.
[CRI attribution](../../../docs/cri/README.md) explains the name ledger,
later owner split and unresolved donor candidates. CRI progress is separate
from Atlus game-code progress.

For another source reference,
[crowded-street/3s-decomp](https://github.com/crowded-street/3s-decomp)
reconstructs ADXT 9.00 / ADXF 7.13 and covers AHX, AC3, SRD and SVM.
Its AGPL-3.0 license requires a separate review before copying code; it is
not interchangeable with the MIT or CC0 imports.
