# Naming Persona 4's CRI middleware

`docs/cri/proven_names.json` maps 788 Persona 4 addresses to CRI function
names, after removing one same-shape collision refuted by Persona 4's call graph.

## Why they are proof rather than inference

Three PlayStation 2 games link the **same CRI build** Persona 4 does.
Comparing every named function in their symbol tables against every
Persona 4 window of the same length, with only the fields a linker rewrites
masked - `j`/`jal` targets, `lui` immediates and the paired `%lo`
displacements - gives functions that agree in every remaining bit, up to
469 words long:

| game | date | masked-exact |
|---|---|---|
| Onimusha: Dawn of Dreams (SLUS-21362) | 2005-12 | 1420 |
| Devil Kings (SLUS-21297) | 2005-08 | 1146 |
| Resident Evil 4 prototype (SLPS_000.00) | 2005-08 | 864 |
| Resident Evil 4 (SLUS-21134) | 2005-09 | 659 |

Two builds of different games do not produce 659 identical instruction
streams by accident. The masked comparison leaves registers, opcodes,
branch offsets and every non-relocated immediate intact, so a hit means the
same compiler emitted the same source at the same optimisation level.

The file keeps the 788 where the address and the name are mutually unique.
686 are corroborated by more than one game; the remaining 102 have one source
in the ledger. 131 addresses were left out as undecided rather than guessed.
For entries found in multiple games, the unmasked scores differ only in the
relocated fields, as expected for the same code linked at different addresses.

**Measured against this project's own work:** 69 of the CRI markers in
`src/cri` sit at an address these tables name, and 65 agree with the name
the port attributed - 94%. Of the four that differ, `SJMEM_Create` against
`sjmem_Create` is a spelling, while `lsc_ClearEntry` against `LSC_ResetEntry`
and `adxf_ReleaseSj` against `adxf_CloseSjStm` look like renames between
versions; one is a remaining same-shape confusion. All four are still
byte-exact at their addresses, so ownership stands even where the name is
wrong - which is the distinction `build/adx_fid.py` records as `order_ok`.

## What this is good for

- naming `func_004cxxxx`-style CRI functions with confidence
- deciding which of several identically-compiling reconstructions belongs at
  an address, where the name distinguishes them (`build/adx_port.py
  --names`)
- confirming, or refuting, that a reconstruction's function is really the
  one at the address a shape match proposed

## What it does not settle

The ambiguous addresses are mostly small shared bodies - `ADXERR_Init` and
`ADXERR_Finish` compile to the same eight words and the linker folded them -
and RE4's table does not disambiguate those either, because the same folding
happened there. Of 40 such addresses it names 2.

## Struct layouts

`build/cri_stabs.py` reads STABS type records out of the RE4 PS2 prototype
(`SLPS_000.00`, 33 MB of `.mdebug`), which was built with `-g` against CRI's
headers. That gives CRI's own layouts for the types its PUBLIC headers
declare, with every member's name and bit offset:

| type | size | members |
|---|---|---|
| `_adx_talk` (ADXT handle) | 196 | 60 |
| `_adx_fs` (ADXF handle) | 68 | 20 |
| `_adxf_ptinfo` | 284 | 9 |
| `MwsfdIf` (player vtable) | 68 | 17 |
| `_sj_vtbl` | 48 | 12 |

`_adx_talk` corrected the tail of `src/cri/re4/adx_t.h`, which was a word
short from 0x A8. `_adx_fs`, `MwsfdIf` and `_sj_vtbl` confirmed the
reconstructions were already right.

The INTERNAL structures - `ADX_BASIC`, `SFD_OBJ`, `ADXSTM_OBJ` - are not in
there, because CRI shipped its libraries prebuilt and only the public
headers reached Capcom's `-g` units. Those still have to come from retail's
own instructions, the way `build/adx_survey.py` finds them.

## Residual dispositions

`residual_dispositions.json` records every right-size donor candidate that
did not become a source owner, including compiler floors, layout/version
divergence, wrong attributions, and candidates superseded by exact donors.

## Retail holding-unit split

`cri_unit_attribution.json` assigns all 2,471 former
`src/cri/cri_adx_grouped.c` markers to source owners. The original 32
string-named/TWEWY-attributed entries are retained. Fourteen soft-float
runtime entries live in `src/middleware/soft_float.c`; 62 entries belonging
to the ROFS interfaces live under `src/sce/`. The five separately compiled
wrappers in `src/cri/cri_adx.c` stay separate: their original prototypes
conflict with the grouped unit's declarations.

The mapping is **not** a proof of 2,471 original CRI translation-unit
boundaries. Named functions, donor source filenames and existing port markers
anchor the split. Of the original markers, 1,049 lie between same-owner
anchors, while 692 at transitions use the nearest linker-order anchor.
Another 14 are assigned by the runtime address region. Namespace and
similarity evidence is weaker than a retail filename; isolated same-shaped
donor-port matches were excluded from boundary inference. The generated
owner files retain the old function bodies, declarations and pragma order;
they do not claim that their inferred filenames are recovered debug data.

A donor cross-check finds 52 former grouped addresses whose proven PS2
function name has a unique translation unit in the TWEWY source map: 51
agree with the assigned owner. The exception is `ADXF_Init` at `004c6d10`:
the Nintendo DS tree places that name in `adx_f.c`, while Persona 4's
adjacent `ADXF_Ocbi` (`004c6cf0`) and the current split place it in
`adx_fcch.c`. A cross-platform name-to-unit lookup cannot settle that
boundary, so neither filename is asserted as a recovered Persona 4 TU.

The separate `src/middleware/gcc_ee_grouped.c` has 47 toolchain-classified
markers. Masked-exact PS2 donor matches for 13 addresses in the
`004e3dc8`–`004e4648` neighbourhood carry SRD-family names in at least
three reference binaries. Two short bodies match multiple SRD names;
another tiny tail jump at `004460f0` matches unrelated functions, while
33 markers have no exact donor name in those references. This supports an
SRD subsystem neighbourhood, not original vendor/TU boundaries. Leave
the GCC group intact rather than promoting an inferred source filename.

The scoped before/after verifier compares all 2,476 original CRI rows
(including the five untouched wrappers): status and `normalized_diff` did
not change. The full linker build separately checks both retail SHA-1s.
