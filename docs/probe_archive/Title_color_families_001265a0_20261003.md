# Largest Title controller: complete remaining clear/copy color families

Source baseline: `5f3ee52967caa0838cc534a9f1bfdb6ef05dde07`, on public
`862a8d1e` plus the reviewed overlay/color/layer chain. The immediate parent
`278155dd92510bbc280749472ee037cc4d4d36ce` adds the unchanged test-only
cherry-pick of `684baa3c` (strict state-event oracle); its production C is
identical to the source baseline. That fixture strengthening is not new source
work here. Both previous seals stay available separately.

Only guarded `func_001265a0` changes. The controller remains assembly-backed;
no match promotion, whole-controller execution or full image gate is claimed.

## Twenty-four observed families

The two original repaired families already used real four-byte objects and
byte pointer increments. The other **24 families** still advanced f32 * or
M2C_UNK * four times, clearing 16 bytes through a four-byte scalar. Eleven
layer families additionally treated their fourth-byte alpha as an independent
scalar, then numerically converted the source word to float for the copy.

The remaining **13 overlay** and **11 layer** families now use:

- Actual `TitleDrawColor` objects for all 46 distinct source/destination
  objects in this scope, reusing the existing four-byte union
- u8 * clear pointers, advancing one byte for the four actual iterations
- `.bytes[3] = 0xFF` for each of the eleven observed alpha aliases
- The existing `titleCopyValue` representation-preserving union assignment,
  in place of numeric conversion or an inferred floating scalar copy

No new helper, artificial padding, ABI argument or compiler option is added.
The old stack-shaped names are retained as identifiers, not layout requests.
The complete controller now has 26 proven byte-clear/copy families, twelve
alpha aliases and fifty distinct four-byte color objects, including the first
four objects proven in the earlier checkpoint.

The destination `sp6BC` remains one shared object. Three overlay families copy
into it, and other providers also consume its address. Its eight unrelated
float-view assignments keep exactly the same RHS and order, expressed through
`.value` after the type repair. This preserves those old expressions without
claiming they are fully reconstructed. It never creates separate objects for
individual appearances of the shared destination.

## Retail and rebuilt dataflow evidence

`audit_retail.py` locates each actual source/destination load/store pair and
checks the entire preceding byte loop. It verifies all eleven alpha writes
at source+3. It scans the complete 17,616-byte retail function for every direct
memory access or address materialization overlapping these 46 objects,
including accesses beginning outside an object's own extent. Every observed
access is contained in one real four-byte object. The shared destination's
other eight assignments are bound to the unchanged baseline RHS expressions.

`audit_candidate.py` verifies all **26 actual rebuilt byte loops**, raw
LWC1/SWC1 copies and **twelve actual byte-3 alpha stores**, including the two
previous families. It establishes fifty distinct aligned frame-contained
objects and checks every overlapping direct stack operation for accidental
wider storage. Shared uses of sp6BC resolve to one stack address.

The full thirty-site layer argument audit also reruns against the new object,
including float depths and state flags. The overlay calls retain all their
previously accepted canonical expressions; native overlay/provider tests
rerun over their current actual declarations. No call argument is repaired or
reinterpreted by this checkpoint.

## Executed fragments and mutation controls

`test_title_color_families.py` extracts the actual declarations and contiguous
clear/alpha/copy/call blocks for all 24 families. Each of the 46 color objects
has independent canaries. All declarations live in one fixture invocation,
so the three uses of sp6BC really share the same object. After each family,
every unrelated object's bytes and all canaries must remain intact.

At O0 and O2, **49,536 cases** cover every byte value in every channel,
signed zero, infinities and NaN bit patterns, across all 24 families and two
opaque-call mutation modes. A preliminary execution of each exact raw-copy
expression verifies representation preservation before the real clear.

The layer boundary checks the actual two calls, copied rectangle snapshots,
zero depth, state flag zero, source/destination distinction and no recopy
between calls. It can mutate the copied color and rectangle after the first
call; the second must retain the mutated color while receiving the new
rectangle snapshot. The overlay boundary checks the canonical adapter values
and may mutate the copied color. The independent source object stays zero
or alpha-FF throughout. The actual packet and render providers are exercised
by the unchanged overlay/layer suites, not replaced in production.

Eight controls reject wide clear pointers, short clear, numeric copy, short
copy, wrong alpha byte, wrong source, source/destination aliasing and recopying
between opaque calls. The wide-pointer control fails the fixture's element
width check before an undefined overwrite can run.

All four Title suites pass together: **10 tests, no runtime skips**. This
includes the stricter combined render-state event oracle from the test-only
parent and its get/set-swap control. These are source-fragment/provider
contracts, not gameplay or PS2 FPU execution. The rest of the controller and
00126090 remain outside this native coverage.

## Complete preservation and remaining nonmatch

Fresh base/final production and guarded builds preserve the entire production
object byte for byte, all 81 guarded siblings, all 420 non-target allocated
data bytes and all non-target references. The target jump table keeps its
alias groups and first four instructions at each destination; offsets can
move within the still-unmatched target. The three caller/provider owners
remain **148 MATCH / 1 ASM**; lint has zero errors and 32 existing warnings.

The guarded target is **17,236 bytes**, versus 17,192 at the source baseline
and the 17,616-byte retail window. The fresh relocation-masked difference is
**3,967 words**, versus 3,947 at base. These measurements are remaining
nonmatches, not progress credit. Repairing the real object extents and byte
operations is justified by the retail/provider evidence independently of
instruction similarity. Other numeric interpretations, provider declarations,
rectangle snapshots and decompiler expressions still require reconstruction.

## Reproduction

With the existing licensed compiler and hash-validated retail configured:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_color_families_001265a0_20261003/capture_owner.py
python docs/probe_archive/Title_color_families_001265a0_20261003/audit_retail.py
python docs/probe_archive/Title_color_families_001265a0_20261003/audit_candidate.py
python docs/probe_archive/Title_color_families_001265a0_20261003/audit_layer_calls.py
python docs/probe_archive/Title_color_families_001265a0_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_0012.c src/promoted/code1_0045.c src/Main/titleVisual.c
python tools/decomp_lint.py src/promoted/code1_0012.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
```

Omit the runner only on a host with functional direct i386 execution. Skips
are unverified, not passes. Compiler objects and whole disassemblies stay out
of the committed source-only evidence and delivery archives.

## Representation and loop-end coverage follow-up

The subsequent rectangle checkpoint adds negative infinity and six signed
subnormal/normal boundary patterns, increasing the family fixture to 49,872
cases per optimization. It also checks each actual clear pointer ends at
source+4 with a zero counter. This rejects short layer clears independently
of the later alpha write; the original short-clear control otherwise relied
on the overlay cases, while the binary audit established all loop lengths.
No color source expression or prior expectation changes.
