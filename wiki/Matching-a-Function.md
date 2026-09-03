# Matching a Function

## Picking a target

The scoring tools tell you where the cheap work is:

```sh
python tools/verify.py --json build/verify_report.json          # everything
python tools/floor_census.py --report build/verify_report.json --top 30
python tools/recovery_quality.py --worst 20
```

Good first targets:

- **Small functions in files that already match.** Getters, setters, flag
  tests, copy loops and destroy/cleanup functions match far more reliably than
  update and render code. `floor_census.py` lists the untried ones by window
  size.
- **Near-complete files.** Closing the last function or two lets the whole
  translation unit into the link.
- **Archived near misses.** `docs/probe_archive/*_<addr>_body.c` holds the
  best candidate for every function someone has attempted, with a header
  saying what was tried and how far it got. `build/archive_sweep.py` re-measures
  an archive against the current toolchain.
- **The Persona 3 FES twin.** `make shared-p3 P3_ROOT=../Persona3-FES-Decompilation`
  maps P3 functions to their P4 counterparts; a P3 `MATCH` body is usually
  within a few words of its P4 twin.

Skip anything listed under [Compiler Floors](Compiler-Floors) unless you have a
new idea; those have been measured to death.

## The loop

```sh
make m2c FILE=src/Battle/btlUnit.c FUNC=func_00195850      # first draft into src/generated/
python tools/fndiff.py src/Battle/btlUnit.c func_00195850  # after installing the draft over the INCLUDE_ASM line
```

`fndiff.py` prints the object and retail words side by side, disassembled,
with relocation annotations. Rows marked `!` are real differences; the
trailing `differing words (reloc-masked): N` also counts zero-padding words
when the object is shorter than the window (a 148-byte object in a 160-byte
window reports 3 and is a `MATCH`).

Then shape the source one lever at a time, re-measuring after each:

1. **Types first.** Widths, signedness, pointer vs array, `f32` where the
   disassembly uses COP1. Most large residuals are type residuals.
2. **Control flow.** Branch polarity, which arm falls through, `while` vs
   `do`, early returns vs joins. `docs/matching.md` has a section per shape.
3. **Register colouring.** Order of declarations and first uses, which value
   is cached in a local, commutative operand order.
4. **Pragmas, last.** `schedule`, `no_branch_likely`, `opt_propagation`,
   `opt_common_subs`, `opt_loop_invariants`, `opt_rebuildconditionals`,
   `optimization_level`, `tailcall` - each with a `/* measured: ... */` note.
   The compiler's real pragma list is 386 spellings; `tools/knob_sweep.py`
   tries them all.

`docs/matching.md` is the catalogue: each entry is a residual pattern, the
lever that fixed it, and the measurement that proved it. Read the section
matching your `!` rows before guessing.

## When to stop

- `MATCH` - run `python tools/decomp_lint.py <file>` and
  `python tools/verify.py <file>` (no WRONG SYMBOL / WRONG CALLEE lines), then
  commit.
- Not `MATCH` after a real attempt - put the bare `INCLUDE_ASM` line back,
  archive the best candidate under `docs/probe_archive/<LANE>_<addr>_body.c`
  with a header stating object/window sizes, differing offsets and every
  lever tried, and move on. Never leave live non-matching C in the tree.
- The residual is a documented floor - same as above; note which floor.

Abandon on measured distance, not on effort: a candidate stuck at the same
`nd` after three different levers is telling you the shape is wrong, not that
it needs a fourth.

## New symbols

A function that reads a global the tree does not know yet needs the symbol
registered in `config/symbol_data_addrs.txt`:

```text
iGpffffb788 = 0x00764878; // type:data evidence: retail func_003e2f60 lw $a2,-0x4878($gp); gp base 0x007690F0
```

then `python tools/recover_symbols.py` regenerates `config/symbols_recovered.txt`
for the linker. For gp-relative names the suffix is the retail immediate and
the address is `0x007690F0 + sign-extended immediate`; for absolute ones the
address comes from the `lui`/`addiu` pair. The verifier's WRONG SYMBOL check
confirms the registration against retail's immediates.
