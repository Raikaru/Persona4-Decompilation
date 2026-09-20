# Recovered Fcl draw results: 0032a960 and 0032b000

Recovered on 2026-09-20 from the saved `build/match-next-latest/build/all-first-party/fcl` results. The integration baseline was `5f35f1606c8cfcc455ca045828148d8a39eb87b1`, rebased on upstream `8217f8c0d309a5ad1467295e9a4395decd3ec00a`. This record describes that captured integration, before the subsequent upstream rebase.

Both functions now use recovered C. Their positions are real `FclVec2` objects initialized by the existing constructor; explicit component snapshots retain the saved load order. The digit path retains signed-byte values. Each function keeps the saved, scoped `opt_propagation off` setting.

The coupled `func_002b6c30` contract accepts a wide resource value and a position aggregate. Its provider explicitly narrows the resource to `s16` before computing the table offset. Existing narrow callers retain their conversions, the existing wide callers retain their input values, and constructor-backed packet locals expose their aggregate member. This removes the incompatible scalar-position declarations without changing the provider's complete object.

## Saved sources and integration

The sources were the saved `draw-contract/typed-guarded/{draw-after.c,combine-after.c}`, `draw-contract/fcl_combine_internal.h`, and `provider-resource/wide-resource.c`, compared with their corresponding before snapshots. All saved main proof source, translation-unit, object, baseline-object, and header hashes were checked. The later typed-guarded proposals change only guarded bodies relative to the saved main exact proof; both target bodies are identical.

| Saved proposal | SHA-256 |
| --- | --- |
| Typed guarded draw owner | `9a619fa977c875fa5480dfad919cda9de8fa33e5393016ea1c0745970cb5df06` |
| Typed guarded combine owner | `19e65dcd36b1c5a9605b31f564294e004c40aec229775ad92472169675860e0e` |
| Shared header | `4e1794b9aee1cef593baaa3edcaa87e70356a3f5c841b555bd1aa3134e1829fc` |
| Provider | `131da1409b239ffcbab75da5596f0a8db5aad61f74741e6cf76f53443367993f` |

Deltas were merged within function-address regions. Current upstream loops and dispatch bodies were retained, including `func_00303610`. Two additional current guarded callers, `func_002f0f00` and `func_0030c3c0`, received the same packet-to-aggregate adaptation using their existing `s64` locals. Their fresh before/after function bytes and relocations are identical. Obsolete failure notes above the two recovered targets were replaced with references to this record.

## Fresh verification

Scratch evidence is under `build/recover-upstream/fcl/`. `baseline/proof.json` records the original source hashes and actual compile commands. `proposal/proof.json` records the saved inputs and merged proposals. `final/proof.json` records actual final includes, source/object hashes, all non-target comparisons, allocated data, and fully resolved target instructions. No expanded-header translation unit was substituted for the final owner compilation.

| Function | Emitted / retail window | Zero tail | Resolved code relocations |
| --- | ---: | ---: | ---: |
| `func_0032a960` | 1684 / 1696 bytes | 12 bytes | 53 |
| `func_0032b000` | 1904 / 1904 bytes | 0 bytes | 54 |
| Protected `func_00303610` | 1036 / 1040 bytes | 4 bytes | 8 |
| Provider `func_002b6c30` | 292 / 304 bytes | 12 bytes | 10 |

The 68 other draw functions, all 41 combine functions, and all 58 provider functions retain their bytes and relocation destinations. Allocated data remains equal in all three owners. The protected rule function's complete 44-byte switch table, including all 11 data relocations, resolves exactly. The provider object is byte-for-byte identical to its fresh baseline. The combine object's anonymous-symbol names change, while its function contents and allocated data do not.

| Final owner | Source SHA-256 | Object SHA-256 |
| --- | --- | --- |
| `y_fclCombineDraw.c` | `0992762767d48654877538465ba79200265f5e063278da8f3bdf99be940e5447` | `06d80847f5b17174c642486fc5469a6b6e0817389e406230d992ab8d93422559` |
| `y_fclCombine.c` | `92a4ceb142e87fb5e53010dc7fe52544088405c87114a0616d5aad34fe8b4d25` | `eadcdae552ad7edc1b3f2f35a4cea98cc3222e876df5dd8a827eb2958c48cbf9` |
| `y_draw.c` | `131da1409b239ffcbab75da5596f0a8db5aad61f74741e6cf76f53443367993f` | `6db4ff010909787bb81e9cbcf0fea70f14e63008b55a716d99a60fb49afb8313` |

The official scoped verifier reported **120 MATCH and 49 ASM**, with no mismatches or compile errors. Scoped lint reported zero errors and five existing H003 pragma advisories in unrelated provider functions.

```text
python -B -S tools/verify.py src/Event/Fcl/y_fclCombine.c src/Event/Fcl/y_fclCombineDraw.c src/promoted/y_draw.c --json build/recover-upstream/fcl/official-verify.json
python -B -S tools/decomp_lint.py src/Event/Fcl/y_fclCombine.c src/Event/Fcl/y_fclCombineDraw.c src/promoted/y_draw.c include/fcl_combine_internal.h --json build/recover-upstream/fcl/lint.json
```

## Guarded callers and remaining differences

All 24 affected current guarded callers compiled before and after the contract change. Fourteen retain identical bytes and relocations, including both additional upstream callers. The call sequence is unchanged in all 24. The ten remaining changed drafts stay guarded with their assembly fallbacks; they are not additional matches.

The difference counts below are **relocation-masked differing bytes**, as returned by `verify.compare`, not differing instruction words. Eight drafts have a larger differing-byte count and two have a smaller count. No additional matching search was performed.

| Guarded function | Emitted bytes, before → after | Differing bytes, before → after |
| --- | ---: | ---: |
| `func_00315600` | 3576 → 3584 | 2469 → 2590 |
| `func_00317900` | 3800 → 3804 | 2627 → 2841 |
| `func_003191c0` | 6904 → 6928 | 4952 → 5212 |
| `func_0031ac10` | 5748 → 5776 | 4210 → 4249 |
| `func_0031e5b0` | 5108 → 5136 | 3862 → 3829 |
| `func_00320b80` | 1888 → 1892 | 1118 → 1178 |
| `func_00323d00` | 1824 → 1836 | 1196 → 1220 |
| `func_00324680` | 2292 → 2304 | 910 → 1096 |
| `func_0032c660` | 7840 → 7892 | 5896 → 5684 |
| `func_00330060` | 1872 → 1876 | 1270 → 1326 |

The complete before/after guarded records, source/header identities, candidate translation units, compiler logs, and objects are retained in `build/recover-upstream/fcl/guarded/`. Later rebases must preserve their newer upstream body changes and obtain new final-owner verification for the resulting source identities.
