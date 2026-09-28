# Matching a Function

This is the working loop for one function. CONTRIBUTING.md has the checks to
run before a pull request; [Rules](Rules) lists what the tree must keep true.

## Choosing a target

Start from a fresh verifier report:

```sh
python tools/verify.py --json build/verify_report.json
python tools/floor_census.py --report build/verify_report.json --top 30
make recovery                     # matched files that still read like m2c output
```

`floor_census.py` separates functions nobody has attempted from those with a
recorded floor. Promising targets:

- **Small functions in files that already match.** Getters, setters, flag
  tests, copy loops and cleanup functions usually match sooner than update and
  render code, and the file already carries the types they need.
- **The last functions in an almost-recovered file.** A file with no
  fallbacks left becomes fully linked C.
- **Earlier attempts.** `docs/probe_archive/` and the `#ifdef NON_MATCHING`
  bodies in `src/` record what was tried and how close it got.
  `tools/probe_archive.py` re-measures an archived body;
  `tools/nd_audit.py` re-measures the parked ones.
- **Code shared with Persona 3 FES.**
  `make shared-p3 P3_ROOT=../Persona3-FES-Decompilation` maps P3 functions to
  their P4 counterparts. A P3 match is a strong starting point, not proof
  that P4 has the same types.

Check [Compiler Floors](Compiler-Floors) before you pick a function that
someone has already given up on.

## The loop

```sh
make m2c-setup                                          # once: installs the pinned m2c
make m2c FILE=src/Battle/btlTarget.c FUNC=func_001ec630
python tools/fndiff.py src/Battle/btlTarget.c func_001ec630
```

`make m2c` writes a draft to `build/m2c/<function>.c`, using the owning
file's declarations as context. Replace the `INCLUDE_ASM` line with it and
fix the types before anything else. `tools/ida_headstart.py` and
`tools/ghidra_headstart.py` produce second-opinion drafts;
`docs/ida_headstart/` and `docs/ghidra_headstart/` hold earlier output.

`fndiff.py` compiles the file and prints object and retail words side by
side, with relocations. Rows marked `!` differ. The closing
`differing words (reloc-masked): N` also counts zero padding when the object
is shorter than the window, so a function can be a verifier `MATCH` with a
non-zero count. For a symbol without a marker, pass its retail address with
`--addr`.

Change one thing at a time and measure after each change:

1. **Types.** Width, signedness, pointer or array, `f32` where the code uses
   COP1. Most large differences are type differences.
2. **Control flow.** Branch polarity, which arm falls through, `while` or
   `do`, early return or a shared exit.
3. **Value lifetimes.** Which value is kept in a local, declaration order and
   first use, the order of commutative operands.
4. **Compiler settings, last.** A pragma such as `schedule`,
   `opt_propagation` or `opt_common_subs` can be the real answer. Record the
   measurement beside it; lint flags non-baseline settings for review.

`docs/matching.md` records shapes with the change that fixed each one and the
function where it was measured. Search it for the instructions in your `!`
rows before guessing. `tools/pragma_sweep.py`, `tools/probe_variants.py` and
the `tools/permute*.py` scripts automate parts of the search once the source
is close.

For disassembly with the EE-specific instructions decoded, use
`tools/recon_dis.py <addr>`. It prefers a Ghidra server with the Emotion
Engine extension and falls back to rabbitizer, which prints COP1
multiply-accumulate and VU ops as `.word`.

## Finishing

When the function reports `MATCH`, check the rest of its file: a shared
declaration can change a sibling. Then follow CONTRIBUTING.md.

When it does not match, keep the best body behind `#ifdef NON_MATCHING` with
its `INCLUDE_ASM` fallback in the `#else` branch, and tag the marker
`// FUN_XXXXXXXX NONMATCHING`. `tools/park.py` does this edit. Write down the
remaining difference and what you tried, so the next person does not repeat
it.

Stop when the difference stops moving, not after a fixed number of tries. If
three different changes leave the same differing words, the shape is
probably wrong.

## New data symbols

If the function reads a global the tree does not know, add it to
`config/symbol_data_addrs.txt` with its evidence:

```text
iGpffff9cc8 = 0x00762db8; // type:data evidence: func_0012e9d0 lw $7,-0x6338($28) at 0x0012F558; GP 0x007690F0
```

A gp-relative name's suffix is the 16-bit immediate retail uses, and its
address is `0x007690F0` plus that immediate, sign-extended. An absolute
address comes from the `lui` and `addiu`/`lw` pair. Run
`python tools/recover_symbols.py` to regenerate
`config/symbols_recovered.txt`, which the linker reads. The verifier's WRONG
SYMBOL check then compares the symbol against retail's immediates.
