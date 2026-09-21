# Naming Persona 4's CRI middleware

`docs/cri/proven_names.json` maps 789 Persona 4 addresses to CRI function
names. Unlike `docs/sky2/proposed_names.json`, these are not proposals.

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

The file keeps the 789 where the address and the name are mutually unique;
687 of those are corroborated by more than one game, and 87 more were
decided by majority where the games disagreed. 131 addresses were left out
as undecided rather than guessed. The unmasked scores differ only in the
relocated fields, as expected for the same code linked at three different
addresses.

**Measured against this project's own work:** 70 of the CRI markers in
`src/cri` sit at an address these tables name, and 65 agree with the name
the port attributed - 92%. Of the five that differ, `SJMEM_Create` against
`sjmem_Create` is a spelling, `lsc_ClearEntry` against `LSC_ResetEntry` and
`adxf_ReleaseSj` against `adxf_CloseSjStm` look like renames between
versions, and two are genuine same-shape confusions. All five are still
byte-exact at their address, so the ownership stands even where the name is
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
