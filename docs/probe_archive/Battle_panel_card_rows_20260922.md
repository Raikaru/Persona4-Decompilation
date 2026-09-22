# Battle-panel card row interpolation: two C matches

The native MWCCPS2 b210 `-O2 -Iinclude` build of
`src/promoted/code1_0021.c` now reports `MATCH` for `func_00215c10` and
`func_002161d0`. The complete owner reports 102 `MATCH` and six `ASM` functions.

| Function | Emitted bytes | Retail window | Zero tail | Resolved relocations |
| --- | ---: | ---: | ---: | ---: |
| `func_00215c10` | 1464 | 1472 | 8 | 11 |
| `func_002161d0` | 1564 | 1568 | 4 | 10 |

## Source mechanism

Both retained candidates differed from retail in 15 unmasked instruction words.
Their parameter saves already matched. The remaining difference came from the
85.0f row-spacing constant being materialized after the unsigned-to-float
conversion, which also exchanged the two floating-point registers.

Use the complete row-position expression directly:

```c
var_f0 = D_007615A8 + 85.0f * (f32)row;
```

The first function's local row copy is `u32`, matching the unsigned conversion
already present in its draft. Its public `s32` parameter and all callers remain
unchanged. The other use of the local row takes its low 16 bits, so the local
type correction preserves that behavior as well.

The direct expression places the constant before the conversion and retains
the retail `adda.s` / `madd.s` sequence. A shared inline helper also reproduced
both functions, but the direct expression needs no additional helper. Keeping
the redundant `(u32)` cast at the conversion site, even with an unsigned local,
left 16 words different in the first function. Separate temporary assignments
also retained the mismatch.

The change removes the two ASM selection guards, their `NONMATCHING` tags,
and superseded floor comments. No additional compiler controls were required.

## Evidence and input bindings

All artifacts are under
`build/finish-first-party-20260922/battle-panel/`:

- `retained/` authenticates and resolves the existing census objects; the
  original compiler jobs were not repeated.
- `probes/row-domain-unsigned-direct-left/` contains the exact pair probe,
  native compile receipt, complete source, unmasked target proofs, and
  sibling/data comparison.
- `pair-ready/` contains the cleaned staged source, review diff, native and
  official verification, and `source-binding.json`.
- `pair-live/completed.json` binds the actual installed owner to its compiler,
  flags, recursive source/header dependencies, fallback ASM inputs, native
  object, full target proofs, and official verifier report.

The final live-owner gate was run with:

```text
python -S build/continue-first-party-20260922/owner_gate.py
  src/promoted/code1_0021.c
  build/first-party-continue-live/census/targets/00215c10/owner.o
  build/finish-first-party-20260922/battle-panel/pair-live
  func_00215c10 func_002161d0
```

The gate natively compiled the complete installed owner, resolved every target
relocation without masking, checked the zero tails, and confirmed all 106
other functions and their canonical relocations were unchanged. Every
allocated data section was identical. It then passed the authenticated native
object to `tools/verify.py`, bound to the exact source and profile, and received
`MATCH` for both functions.

Final source SHA-256:
`72d72f8119d5b5581c5d2a06e6e457ab40a75f6173f385c0720c723fb72b1b11`

Final native object SHA-256:
`11700931efcc3e115897e13b845a5272344581c22411c1974becfc1e6162ee00`

`git diff --check` passed for the owner. `tools/decomp_lint.py` reported zero
errors and four warnings on existing optimization pragmas; this change adds
no pragmas.
