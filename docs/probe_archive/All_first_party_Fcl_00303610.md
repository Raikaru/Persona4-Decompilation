# Exact Fcl rule predicate: func_00303610

Recorded by worker-6 on 2026-09-19 in `build/match-next-latest`, after merge
commit `86a85d1` and with `eba2679` at HEAD. This note records the accepted
rule recovery before the pending SDK contract migration. The recovery is in
`src/Event/Fcl/y_fclCombine.c`; the documentation follow-up does not change
either Fcl source owner or their shared header.

`func_00303610` reproduces **1036 executable bytes in its 1040-byte retail
window**, with **eight code relocations resolved** and four zero alignment
bytes. Its compiler-generated **44-byte switch table at `0x00749300`** also
matches retail after resolving all eleven table entries. The function is now
ordinary active C with its NONMATCHING guard and assembly fallback removed.

## Counter lifetimes and preserved behavior

The retained guarded baseline was already 1036 bytes, but had **27 differing
instruction words** after relocation masking. The accepted
`first_search_index_scope` candidate reaches **zero**, then passes the complete
relocation and owned-table proofs. Measurements, C candidates, their complete
translation units, objects, logs and alignments are retained under
`build/all-first-party/fcl/experiments/func_00303610/3fea0ff69ebc/`.

The baseline reused function-wide short counters across independent switch
arms. Cases 1 and 2 now each declare their own `s16 item`; case 6 declares
separate `s16 first` and `s16 second`. The category search in case 5 retains
the distinct function-local `k` outer and `j` inner counters, preserving the
observed lifetimes across calls. The pass counter, signed count and expected
rule values remain short integers; the found flag remains a signed byte.
The existing scoped `opt_loop_invariants on` pragma is retained. No new
optimization pragma, inline assembly, volatile access or incompatible local
prototype was introduced.

Both case 5 loops preserve the original nested search: the outer index visits
ingredients in ascending order, each matching outer ingredient starts a fresh
ascending inner search, and an inner match breaks only that inner search.
There is no new outer early exit or deduplication. The worst-case iteration
count remains O(n^2), and the category-call order and rule loads are unchanged.
Case 6 likewise retains its original nested ID search. The three-pass rule
loop, no-rule `index == -1` success path, and count predicates 3/4/5/6 remain
as in retail.

The retail instruction reference is
`asm/nonmatchings/y_fclCombine/func_00303610.s`. The category provider remains
the existing `u8 func_00109280(s32 personaId)` in `src/g_data/g_data.c`;
the Fcl caller declaration agrees with it. Each rule call still passes an
unsigned 16-bit ID and compares the returned byte with the signed-short rule
value using the existing `& 0xFF` expression.

## API and actual caller buffer contract

The unchanged interface is:

```c
s32 func_00303610(u8 *arg0, s8 arg1, u16 *arg2);
```

`arg1` is the ingredient count. `arg2` supplies **count + 1 initialized
`u16` entries**: the ingredients occupy indices `[0, count)`, and the result
occupies index `count`. Therefore `last = arg2 + count` points to the result
after the ingredients. Cases 3 and 4 deliberately dereference that result;
it is not a reference to the last ingredient or evidence of a short array.

The sole first-party C call site is the unchanged `func_00303a20` in the same
owner. It allocates `u16 buf[7]` and calls
`func_00303610(arg0, p[0x1A], buf)`. Every implemented count arm initializes
the complete required payload:

| Count passed from `p[0x1A]` | Ingredient entries | Result entry | Initialized entries |
| ---: | --- | --- | ---: |
| 2 | `buf[0]` through `buf[1]` | `buf[2]` | 3 |
| 3 | `buf[0]` through `buf[2]` | `buf[3]` | 4 |
| 4 | `buf[0]` through `buf[3]` | `buf[4]` | 5 |
| 5 | `buf[0]` through `buf[4]` | `buf[5]` | 6 |
| 6 | `buf[0]` through `buf[5]` | `buf[6]` | 7 |

For counts 2 and 3 the ingredients come from the current individual selection
slots. For counts 4 through 6 they come from consecutive entries of the
selected group. In every arm the final entry comes from
`func_002e48a0(p[0x2F9], p[0x2FA])`, using the descriptor's ID at byte offset
2. Retail confirms the buffer at `sp + 0x30`, stores through `sp + 0x3C` in
the six-ingredient arm, then loads the signed count and calls the predicate
at `0x00303DB8`. See
`asm/nonmatchings/y_fclCombine/func_00303a20.s`.

This establishes the actual caller's bounded payload for counts 2 through
6. Neither function adds validation for arbitrary counts or an arbitrary
shorter external buffer; no such broader input contract is claimed here.
The caller's bytes and relocations are unchanged by the recovery.

## Independent proof and verification

The worker's fresh current-owner proof is
`build/all-first-party/fcl/rule-current.json`, with object `rule-current.o`.
Prime independently recompiled and checked the integrated source in
`build/all-first-party/verified/fcl-rule/proof.json`. Both prove the same
target and compare against immutable `build/all-first-party/fcl/merged-combine.o`:
all **40 other functions** retain their bytes and canonical relocation
destinations; all **three existing allocated data sections** retain contents,
alignment and relocations. The only added section is the fully proved switch
table. Complete object identity is not claimed because this C recovery adds
that owned table.

The code relocations comprise HI16/LO16 pairs for `D_0063FCA0` at offsets
92/96 and the switch table at offsets 160/164, plus calls to `func_00109280`
at offsets 216, 384, 472 and 520. Each of the eleven table R_MIPS_32 entries
resolves into `func_00303610`; all 44 relocated bytes match retail.

Prime's fresh official report,
`build/all-first-party/verified/fcl-rule/official.json`, records **41
functions: 25 MATCH and 16 ASM**, compared with the previous 24 MATCH and
17 ASM. The worker's corresponding report is
`build/all-first-party/fcl/rule-verify.json`. This is one additional exact C
recovery; the remaining guarded drafts and existing owner/link limitations
are not represented as complete. These are scoped compilation, relocation
and data proofs, not a full-project build or a complete-image result.

## Reproduction and identities

Run from `/persona4-decompilation/build/match-next-latest` with the configured
MWCC PS2 b210 profile. These commands use the retained immutable baseline and
write new proof outputs; they do not rerun the historical candidate sweep:

```powershell
python build/all-first-party/fcl/owner_proof.py src/Event/Fcl/y_fclCombine.c build/all-first-party/fcl/merged-combine.o build/all-first-party/fcl/rule-recheck func_00303610
python build/all-first-party/verify_recoveries.py src/Event/Fcl/y_fclCombine.c build/all-first-party/fcl/merged-combine.o func_00303610 --output build/all-first-party/fcl/rule-independent-recheck --allow-owned-tables
python tools/verify.py src/Event/Fcl/y_fclCombine.c --json build/all-first-party/fcl/rule-official-recheck.json
```

The retained experiment script `build/all-first-party/fcl/rule_lifetimes.py`
describes the preintegration search. Its original baseline is preserved in
the experiment directory; the already-integrated owner is a later source
context and should not be treated as that original 27-word baseline.

SHA-256 identities at this accepted, pre-SDK-migration checkpoint:

```text
src/Event/Fcl/y_fclCombine.c
06d26eb98e7413c2fb5ef5ae2ece74dc53caba9d555b62dd43aa8eaeaeb5b71d
merged-combine.o (immutable baseline)
2ff39ce3de134cf6e188bd72c94bdf6038ef9e77464c1cab6cdffbb45a22f41a
rule-current.o and prime verified/fcl-rule/current.o
af3a63693bb2ef2cf64615109c844a249454cbc46786574697c9387e3e85847c
func_00303610 raw emitted bytes
fcb9f6725c5185316f7a7dcff878917c552f8361b26fcfe48e38174e249e3e7f
func_00303610 fully resolved bytes / retail executable prefix
a4a96f8873a40815a9a1260889f96a3129da3e2e2118c352acdda399067a0a09
44-byte switch table, fully resolved / retail
472456e570774f53d8bf1e348280b2b158508d3e66b0e0c1e3f0455e99fca129
```
