# Rules

The invariants every commit keeps, and the reason each one exists. CI enforces
the mechanical ones.

1. **Nothing non-matching is live.** A function is matching C or an
   `INCLUDE_ASM` line; a near miss goes to `docs/probe_archive/`. The image is
   byte-exact on every commit.
2. **Markers are the denominator.** Never delete, rename or move a
   `// FUN_XXXXXXXX` marker except together with the function it labels, and
   into exactly one other file. Count markers before and after an edit.
3. **Pragmas need a measured reason.** Only the spellings the compiler
   actually implements (`tools/pragma_audit.py` proves it), each `off`
   balanced by its `on`, and a `/* measured: ... */` note within three lines
   saying what it fixed. `#pragma alias` and friends are rejected: MWCC
   ignores unknown pragmas silently, and a function can score `MATCH` while
   the pragma does nothing.
4. **No inline asm for computation.** Only the privileged ops on the linter's
   allow-list (`syscall`, `sync`, `ei`/`di`, `cache`, COP0 moves, `bc0f`/`bc0t`,
   the COP2 transfer ops).
5. **Symbols are checked, not guessed.** A new `iGpffffXXXX` / `D_XXXXXXXX`
   goes into `config/symbol_data_addrs.txt` with its evidence; the suffix must
   equal the retail immediate; the verifier's WRONG SYMBOL / WRONG CALLEE
   checks and the full link catch the rest.
6. **The compiler per unit is configuration, not source.** Which compiler,
   which level, `,p` or not - `config/compiler_units.txt`,
   `config/version_flags.txt`, `config/speed_units.txt`, `config/gcc_units.txt`.
   A unit naming an unconfigured compiler fails verify; it never silently
   falls back.
7. **The link floor only goes up.** `config/link_floor.json` counts the C
   objects in the link; lowering it needs a stated reason in the commit.
8. **Every commit passes the same gate**: `decomp_lint.py` 0 errors,
   `verify.py` 0 unexpected statuses and no WRONG lines, `build.py` with both
   SHA-1s OK, the unit tests, then push and green CI.
9. **Honest names and types** (`docs/STYLE.md`): better a neutral decompiler
   name than a wrong one; project types from `include/type.h`; floats typed
   as floats.
10. **Keep line endings.** CRLF files stay CRLF.
