# Largest title controller: real overlay argument transport

Base: `f6a8c57a1485a869dc5dbd1cc27a2c5184996f1c`.
Changed owner: `src/promoted/code1_0012.c`.
Main target: guarded `001265a0`, a 17,616-byte retail window.

This checkpoint repairs one real caller contract. The controller remains
`NON_MATCHING` and assembly-backed; it is not a recovered function.

## Actual provider and callers

The matching provider `src/Main/titleVisual.c:func_002aaf20` takes:

```
void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color,
                   f32 width, f32 height, s32 flags, void *parent);
```

Its prologue preserves f12/f13/f14, a0, f15/f16, a1 and a2 in that source
order. It allocates a 28-byte rectangle packet, writes four integer bounds,
float depth, four color bytes and flags, then either draws immediately or
queues the packet through the supplied parent.

All 14 retail calls inside `001265a0` pass x/y zero, width 640.0, height
448.0, flags 0x12 and null parent. Depth is 65535.0 at 13 sites and zero at
`00126D4C`. The source previously passed the apparent integer register list
through an unprototyped declaration. A fresh baseline object demonstrates the
failure: the first call put color/flags/zeros/dimensions in a0..t3 and invoked
`litodp` for the depth, instead of setting f12..f16. The repaired object uses
mtc1/cvt.s.w/mov.s for the actual five float arguments. All 13 obsolete
`litodp` calls disappear. Other unrelated float-promotion helpers remain.

The 14 callsites are `00126B68`, `00126D4C`, `00127048`, `00128314`,
`00128798`, `0012896C`, `00128B24`, `00128D74`, `00128ED8`, `00129084`,
`00129408`, `001295D8`, `00129920`, and `00129AF8`.

The source now uses the existing typed `titleRectangle` adapter, whose
function-local provider declaration agrees with the matching implementation.
The conflicting file-scope declaration is removed, and matching sibling
`00126090` uses the same adapter with its actual 480.0 height. This sibling's
compiled bytes and resolved references remain unchanged. No provider, header,
compiler setting, callback behavior or fallback was modified.

The retail audit hash-validates the ELF, checks the provider's argument-save
instructions, enumerates the 14 target calls plus the matching sibling's call,
and symbolically interprets each immediate setup to verify the GPR/FPR values,
color stack offset and nop delay slot. It does not infer arity from a decompiler.

## Scoped verification

- Production owner: **81 MATCH / 1 ASM**; unchanged provider: **7 MATCH**
- All 82 production functions, all allocated sections and all resolved
  allocated references are preserved exactly
- All 81 guarded sibling functions preserve bytes, sizes and canonical
  references. Compiler-local `@` labels are resolved to the actual section
  index/name/value/size; identical section names alone are not treated as identity
- All 420 non-target allocated data bytes and their references are unchanged
- The target's own 64-byte, 16-entry jump table changes relative case offsets
  as its body grows. Every R_MIPS_32 entry still targets `func_001265a0`, is
  in bounds/aligned, retains its case-alias grouping, and lands on the same
  first four instructions of its prior case entry. This is compiler-generated
  guarded data, not a manual table edit or an exact-retail-table claim
- Lint: zero errors, 32 remaining owner advisories (31 H011 and one H003)

The guarded body changes from **17,072 bytes / 3,941 masked differing words**
to **17,180 bytes / 3,959 masked differing words**, against 17,616 retail bytes.
Its frame remains 0x4d0 versus retail 0x6c0. The larger positional difference
is retained because the old argument transport was wrong; no size band or
register score justified the repair. A shorter candidate is not a match when
the missing retail suffix is nonzero.

## Actual-call and provider fixture

The test extracts all 14 updated call expressions verbatim, their real color
storage declarations, the matching sibling call, the existing adapter and the
actual unchanged `002aaf20` implementation. It runs 30,720 cases at each of
`-O0` and `-O2` using real 32-bit pointers and UB/bounds traps under QEMU on
this host, with no accepted skips.

All four color channels exhaust their byte domain, with unrelated other
channels including floating NaN representations. The color is transported
as four bytes, not numerically converted. Half the cases mutate the pointed-to
color during the real provider's allocation boundary, proving its later copy
is observed. Tests check exact bounds, depth, flags, immediate dispatch,
allocation parameters, all packet guard bytes and the untouched queue node.

Five negative controls fail: zeroed depth, dimension bit patterns passed as
integer values, wrong height, wrong flags and an unrequested parent. A separate
source check verifies the adapter's complete provider declaration matches its
actual definition.

These are extracted-call and actual-provider tests. They do not execute the
entire title controller, whose remaining decompiler buffer/float defects are
not fixed by this patch. No full retail-image build, gameplay run, CI run,
upload or push is claimed. The unchanged production link input does not
replace a fresh aggregate gate after later integration.

## Next meaningful reconstruction

The controller still uses separate scalar locals as if they were adjacent
four-byte colors, vectors, rectangle packets and other output objects. Some
four-iteration clear loops advance `f32 *` or `M2C_UNK *` despite retail byte
clears. Real typed color/rectangle storage and provider-sized output buffers
must be reconstructed from retail before register-allocation work. Other
old-style calls, numeric conversions and accumulator placeholders remain.

## Reproduction

Run from the checkout root after configuring the existing licensed toolchain
and retail input:

```
python tools/regenerate_asm.py
python docs/probe_archive/Title_overlay_contract_001265a0_20261003/audit_retail.py
python docs/probe_archive/Title_overlay_contract_001265a0_20261003/capture_owner.py
python tools/verify.py src/promoted/code1_0012.c src/Main/titleVisual.c
python tools/measure_guarded.py src/promoted/code1_0012.c func_001265a0
python -m unittest discover -s tests -p test_title_overlay_contract.py -v
```

The capture script reads the exact baseline from Git without changing source;
its objects stay under ignored/local `proof/title-owner`. The standard native
runtime needs an execution-capable i386 host or the existing external QEMU
adapter. The saved native log states which runner was actually used.
