# First-party recovery checkpoint: 52 replacements

The interrupted worker campaign was recovered from its actual source files and
completed compiler receipts. The assembled publication checkout now verifies
**6,428 MATCH and 432 ASM** among 6,860 first-party functions. Relative to the
published `0360227` checkpoint, this is **52 additional exact C functions**.
The complete verifier covers 12,720 functions: 8,063 MATCH and 4,657 ASM.

These counts describe the assembled source based on `076b004`, before its next
upstream rebase. The previous 22-function and 38-function checkpoint reports
remain historical evidence; they were not mistaken for current verification.

## Accepted functions

Each function below was independently compared after applying every code
relocation. Any referenced compiler-owned data was also placed, relocated and
compared in full. Every difference between executable size and retail window
size consists entirely of retail zero alignment.

| Function | Executable/window bytes | Code relocations |
| --- | ---: | ---: |
| `00130ce0` | 1476/1488 | 14 |
| `00135130` | 1008/1008 | 27 |
| `001356d0` | 1332/1344 | 42 |
| `0013b420` | 1480/1488 | 14 |
| `0013c700` | 852/864 | 22 |
| `0013ea20` | 2724/2736 | 94 |
| `0013f720` | 1060/1072 | 30 |
| `0013fb50` | 1060/1072 | 42 |
| `001441e0` | 2268/2272 | 109 |
| `0015fb00` | 1052/1056 | 18 |
| `00164230` | 832/832 | 31 |
| `00164880` | 1728/1728 | 45 |
| `00167560` | 1128/1136 | 39 |
| `001679d0` | 904/912 | 23 |
| `001a0b00` | 1088/1088 | 26 |
| `001a4800` | 1148/1152 | 39 |
| `001bcd40` | 1472/1472 | 22 |
| `001be050` | 2164/2176 | 49 |
| `001be990` | 2564/2576 | 73 |
| `001bf5e0` | 1416/1424 | 29 |
| `001bfc00` | 2256/2256 | 53 |
| `001c04e0` | 1208/1216 | 20 |
| `001c09b0` | 1156/1168 | 37 |
| `001c17a0` | 2000/2000 | 60 |
| `001c5500` | 1664/1664 | 27 |
| `001c6f40` | 1180/1184 | 26 |
| `001c80f0` | 2012/2016 | 54 |
| `001c8e90` | 2228/2240 | 49 |
| `001ca590` | 1852/1856 | 40 |
| `001cb970` | 1540/1552 | 25 |
| `001ccdb0` | 2124/2128 | 80 |
| `001cde50` | 1336/1344 | 34 |
| `00235520` | 12176/12176 | 363 |
| `00238940` | 3728/3728 | 60 |
| `0023a6b0` | 12324/12336 | 254 |
| `0023e6f0` | 10920/10928 | 325 |
| `002411a0` | 2588/2592 | 70 |
| `0028fc40` | 2088/2096 | 16 |
| `002e4090` | 1360/1360 | 33 |
| `002e8410` | 3256/3264 | 148 |
| `00316470` | 2572/2576 | 93 |
| `0031d630` | 1980/1984 | 48 |
| `0031ddf0` | 1328/1328 | 31 |
| `003297f0` | 1604/1616 | 50 |
| `0033e5c0` | 500/512 | 14 |
| `00364fb0` | 2072/2080 | 11 |
| `003742b0` | 852/864 | 30 |
| `00377930` | 1236/1248 | 17 |
| `00377eb0` | 800/800 | 22 |
| `004604d0` | 1076/1088 | 30 |
| `00463930` | 1060/1072 | 8 |
| `0046d750` | 4244/4256 | 14 |

## Current combined verification

`build/campaign-checkpoint/resumed-52/official.json` is the official verifier
report for the assembled publication source. Its compiler wrapper reused 332
completed owner objects only after checking unchanged source, transitive
headers, compiler selection and flags, compilation tooling, and the generated
fallback corpus. The other 41 owners were freshly compiled. Every reused
object was checked against its recorded SHA-256. Relocation comparison and
the independent complete target/data proofs ran against the assembled source
and symbol maps for all 52 recoveries.

The completed verifier command was:

```text
python -B -S build/campaign-checkpoint/verify_delivery.py resumed-52
```

It completed with exit zero. `inputs.json`, `official-completed.json`,
`reuse.json`, `proof.json`, and the per-target `resolved/` records bind the
source, compiler objects, reuse decisions and unmasked comparisons. The
52-target report does not claim that 332 unchanged compiler jobs were rerun.

The newest integrations include the signed Fcl selector and task interfaces,
the model setup callback's real argument, the current-field predicate's
explicit result, and the native unsigned RNG return throughout its reviewed
callers. Their separate owner and guarded-caller comparisons remain under
`build/first-party-finish-20260920/` in the recovery worktree. Detailed source
notes document changes to guarded drafts separately from accepted C functions.

## Remaining work

The 432 remaining first-party entries still use assembly fallbacks. Matching
work continues from the current owners and measured native interfaces. A
scratch candidate with zero instruction differences is not accepted until
its provider/caller contracts and combined-owner code/data proofs are complete.
Older worktrees, candidate bodies, rejected controls and completed receipts
remain preserved; there was no reset or replacement of unrelated local work.
