# CRI middleware: names, layouts and unit split

This directory holds the evidence used to name Persona 4's CRI ADX/Sofdec
functions and assign them to source files. The JSON files are data;
`src/cri/` holds the code.

| file | contents | trust |
|---|---|---|
| `proven_names.json` | 788 Persona 4 address → CRI name pairs, each listing the games that support it | proven by masked-exact code (below) |
| `context_names.json` | 317 proposed names for bodies shared by several reference functions, chosen by call-graph neighbourhood | proposals; not in `config/symbol_names*.txt` |
| `twewy_tu_map.json` | 486 CRI name → translation-unit entries from the Nintendo DS CRIWare tree in [Yotona/twewy](https://github.com/Yotona/twewy) (25 units) | unit membership and API shape only; ARM code never matches |
| `cri_unit_attribution.json` | owner source file for each of the 2,471 former grouped-unit markers | inferred split, not recovered TU boundaries |
| `residual_dispositions.json` | right-size donor candidates that did not become source owners (`libadxe`, `re4` donors) | record of rejections |

The analysis scripts named below (`adx_fid.py`, `adx_port.py`,
`adx_survey.py`, `cri_stabs.py`) were run from the git-ignored `build/`
directory. The results in this directory are committed; the scripts are not.

## Proven names

The reference builds below share many CRI instruction streams with Persona 4.
Their symbol tables name the reference functions. Each was compared with
every same-length Persona 4 window after masking the fields used for
relocated addresses: `j`/`jal` targets, `lui` immediates and paired `%lo`
displacements. Registers, opcodes, branch offsets and every other immediate
still had to match. Matching windows were up to 469 words long:

| game | date | masked-exact |
|---|---|---|
| Onimusha: Dawn of Dreams (SLUS-21362) | 2005-12 | 1420 |
| Devil Kings (SLUS-21297) | 2005-08 | 1146 |
| Resident Evil 4 prototype (SLPS_000.00) | 2005-08 | 864 |
| Resident Evil 4 (SLUS-21134) | 2005-09 | 659 |

Agreement across hundreds of long instruction streams supports shared
compiled library code. A hit alone does not identify the original source
spelling or optimization flags, and short identical bodies can have
different names.

`proven_names.json` keeps only addresses where the address and the name
identify each other uniquely: 788 after removing one same-shape collision
that Persona 4's call graph refutes. 686 are supported by more than one game;
102 have one source. 131 addresses were left undecided instead of guessed.
For names found in several games, the unmasked words differ only in the
relocated fields.

**Audit against the port (2026-09-21).** At the time, 69 CRI markers in
`src/cri` sat at addresses these tables name. 65 used the same name as the
port (94%). The four differences were:

- `SJMEM_Create` versus `sjmem_Create`: spelling.
- `lsc_ClearEntry` versus `LSC_ResetEntry` and `adxf_ReleaseSj` versus
  `adxf_CloseSjStm`: probably renames between CRI versions.
- One remaining same-shape confusion.

All four functions were byte-exact at their addresses, so the address
ownership stood even where the name was wrong. `adx_fid.py` records
ownership separately as `order_ok`.

### Uses

- Name `func_004cxxxx`-style CRI functions.
- Choose between reconstructions that compile identically when their names
  differ (`adx_port.py --names`).
- Confirm or refute that a shape match put a reconstruction at the right
  address.

### Limits

Most ambiguous addresses are small shared bodies. `ADXERR_Init` and
`ADXERR_Finish` compile to the same eight words, and the linker folded them.
RE4's table does not separate those either, because RE4 folded them too: of
40 such addresses it names 2. `context_names.json` proposes names for 317
shared-body windows from their callers and callees. It chooses a name only
when one candidate has a positive score and no tie. Review those names the
same way as mined names before renaming any definition.

## Struct layouts

The RE4 PS2 prototype (`SLPS_000.00`) contains 33 MB of `.mdebug`. It was
built with `-g` against CRI's headers. `cri_stabs.py` reads its STABS type
records and recovers layouts for the types in CRI's **public** headers, with
each member's name and bit offset:

| type | size | members |
|---|---|---|
| `_adx_talk` (ADXT handle) | 196 | 60 |
| `_adx_fs` (ADXF handle) | 68 | 20 |
| `_adxf_ptinfo` | 284 | 9 |
| `MwsfdIf` (player vtable) | 68 | 17 |
| `_sj_vtbl` | 48 | 12 |

`_adx_talk` showed that the tail of `src/cri/re4/adx_t.h` was one word short
starting at `0xA8`. `_adx_fs`, `MwsfdIf` and `_sj_vtbl` confirmed the
existing reconstructions.

Internal structures such as `ADX_BASIC`, `SFD_OBJ` and `ADXSTM_OBJ` are not
in the debug data. CRI shipped prebuilt libraries, so only the public
headers reached Capcom's `-g` units. Recover those layouts from retail
instructions, as `adx_survey.py` does.

## Unit split

`cri_unit_attribution.json` assigns every one of the 2,471 markers from the
former `src/cri/cri_adx_grouped.c` holding unit to an owner source file:

- the original 32 entries named by strings or attributed through TWEWY keep
  their owners;
- 14 soft-float runtime entries go to `src/middleware/soft_float.c`;
- 62 ROFS interface entries go under `src/sce/`;
- the rest go to CRI owners under `src/cri/`.

The five separately compiled wrappers in `src/cri/cri_adx.c` stay separate,
because their original prototypes conflict with the grouped unit's
declarations.

The split does **not** prove 2,471 original CRI translation-unit boundaries.
Named functions, donor source filenames and existing port markers anchor it.
Of the original markers, 1,049 lie between two anchors with the same owner.
The nearest anchor in link order assigned 692 markers at transitions, and
the runtime address region assigned 14. Namespace and similarity evidence
counts for less than a retail filename. Isolated same-shape donor matches
were not used to infer boundaries. The generated owner files keep the old
function bodies, declarations and pragma order. Their filenames are
inferences, not recovered debug data.

A donor cross-check found 52 former grouped addresses whose proven PS2 name
belongs to exactly one TWEWY unit. Their assigned owners agreed in 51 cases.
The exception is `ADXF_Init` at `004c6d10`. The DS tree puts it in
`adx_f.c`, while Persona 4's adjacent `ADXF_Ocbi` (`004c6cf0`) and the
current split put it in `adx_fcch.c`. A cross-platform name-to-unit lookup
cannot decide this boundary, so neither filename is claimed as a recovered
Persona 4 TU.

When the split landed, a scoped before/after verification compared all
2,476 original CRI rows, including the five untouched wrappers. Status and
`normalized_diff` stayed the same. `make build` checks both retail SHA-1
hashes of the linked image.
