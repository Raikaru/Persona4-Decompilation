# Rules

The invariants every commit keeps, and the reason each one exists. CI enforces
the mechanical ones.

1. **Nothing non-matching is live.** A function is matching C or an
   `INCLUDE_ASM` line; a near miss goes to `docs/probe_archive/`. The image is
   byte-exact on every commit.
2. **Markers are the denominator.** Never delete, rename or move a
   `// FUN_XXXXXXXX` marker except together with the function it labels, and
   into exactly one other file. Count markers before and after an edit.
3. **Compiler controls are legitimate; evidence still matters.** Record useful
   measurements for unusual settings and use push/pop for function-local
   scopes. On/off directives set state, not balancing pairs. Optimization
   provenance is advisory; `tools/pragma_audit.py` separately rejects spellings
   the compiler ignores.
4. **No assembly transcription counted as C.** Hardware operations may need
   assembly and bounded register plumbing. A pure compiler memory barrier is
   legitimate, but empty allocation barriers and ordinary computation in
   assembly are integrity errors. A generic `measured` note cannot waive them;
   exceptions require a rule-specific comment with a semantic reason.
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
8. **Every commit passes the same gate**: `decomp_lint.py` has no integrity
   errors or scan failures, `verify.py` has no unexpected statuses or WRONG
   lines, `build.py` has both SHA-1s OK, then unit tests, push and green CI.
   Volatile-context, optimization-provenance and dead-store warnings are
   review aids, not automatic failures. `register` is allowed.
9. **Honest names and types** (`docs/STYLE.md`): better a neutral decompiler
   name than a wrong one; project types from `include/type.h`; floats typed
   as floats.
10. **Keep line endings.** CRLF files stay CRLF.
