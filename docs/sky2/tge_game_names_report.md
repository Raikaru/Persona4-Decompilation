# tge-was-taken game-code names: P4 impact report

Source: tge-was-taken's P3FES `config/SLUS_216.21/symbol_addrs.txt` (ref `main`, fetched read-only), game sections only (every section not under `lib/`). Nothing from this list is applied. This report is for the user to decide.

## Method

- Same strict matching as the library port (`tools/port_tge_names.py`): P3 and P4 windows must be relocation-identical, unique on both sides.
- Inputs: 8,379 tge game addresses; 1,930 with a usable single name; 1,929 with a P3 window.
- Result: 260 unique P4 twins. Rejections: 1,286 `no_p4_twin`, 381 `p3_not_unique`, 2 `p4_not_unique`.
- 259 of the 260 twins are first-party (`main`) P4 functions. 1 is in a third-party owner.

## Impact on P4 names

| Category | Count | Meaning |
|---|---|---|
| would name | 140 | P4 address is still `func_XXXXXXXX`. |
| already | 115 | P4 already uses the same name. Independent agreement. |
| would rename | 5 | P4 has a different name. Needs a decision. |
| address already claimed (other name) | 5 | Subset of the rename rows. |
| name already claimed elsewhere | 1 | Name already used at another address. |

`name_in_code` (116) overlaps `already`: the name is already used in P4 code.

Per section (of 260 twins): Graphics 112, Battle 39, Tohyama 36, Main 22, Script 17, Kosaka 14, Kernel 8, Scene 6, datCalendar 2, itfMesManager 1, Event 1, crt0 1.

## Rename candidates (P4 name differs from tge)

These are most likely real disagreements. Check each before accepting any of them.

| P4 addr | P4 current | tge name | tge section |
|---|---|---|---|
| 0x00192790 | btlUpdateDraw2DTask | btlUpdateDraw3DFrontTask | Battle/battle |
| 0x0047A1E0 | mdlScale | mdlManagerMatrixScale | Graphics/Model/mdlManager |
| 0x0029C550 | CodeFunc_Or | CodeFunc_And | Script/scrTraceCode |
| 0x004556B0 | H_Cdvd_StreamGetSlot | H_Cdvd_RtFsPak_Get | Tohyama/h_cdvd |
| 0x001090F0 | datResetTotalBtl | gDataInitTotalBtlCount | Main/g_data_2 |

## Samples: P4 `func_` placeholder would be named (would name)

| P4 addr | tge name | tge section |
|---|---|---|
| 0x00193750 | btlUpdateSetFlagsPacket | Battle/battle |
| 0x0019E520 | btlUnitDestroyLookAtUnitPacket | Battle/btlUnit |
| 0x00273140 | itfMesManagerFontDraw2 | Graphics/Font/frFont |
| 0x002BAA90 | nmCmdListGlobalInit2 | Event/nmCmdList |
| 0x00454E10 | H_Cdvd_SplitPath | Tohyama/h_cdvd |
| 0x004555D0 | H_Cdvd_RtFsPak_Eof | Tohyama/h_cdvd |
| 0x004556F0 | H_Cdvd_RtFsPak_FSClose | Tohyama/h_cdvd |
| 0x00455720 | H_Cdvd_RtFsPak_FExists | Tohyama/h_cdvd |
| 0x00455B70 | H_Cdvd_AddFile | Tohyama/h_cdvd |
| 0x004599A0 | H_Snd_PlayBgm | Tohyama/h_snd |
| 0x00463E60 | uttmxRwStreamOpen | Tohyama/h_maestro |
| 0x00476E90 | mdlManagerLoadMatColors | Graphics/Model/mdlManager |
| 0x00477900 | mdlManagerDoubleMorphTargetBoundingSpheres | Graphics/Model/mdlManager |
| 0x00484490 | mdlEffectGetSubtypeData | Graphics/Model/mdlEffect |
| 0x004938E0 | mdlEffect2Update2 | Graphics/Model/mdlEffect |
| 0x00498C50 | mdlEffect13Update | Graphics/Model/mdlEffect |
| 0x004A5910 | mdlEffect16Init2 | Graphics/Model/mdlEffect |
| 0x004A9690 | mdlEffectScreenEffectType2Update | Graphics/Model/mdlEffect |
| 0x004AD810 | mdlEffect27Init2 | Graphics/Model/mdlEffect |
| 0x004B1100 | mdlEffect29Func28 | Graphics/Model/mdlEffect |

## Not included in this pass

- `mdlEffectDMAOpen*` (two names): these are game code and not behaviour-verified retail names. They were skipped, as requested.
- The mdlEffect names above come from tge only. They are unverified against retail and should not be applied without a check.

## Decision needed

1. Apply the 140 `would name` rows in a later batch, after reviewing the mdlEffect and H_Cdvd groups.
2. Keep the 5 rename rows out until each is checked against the P4 call sites.
