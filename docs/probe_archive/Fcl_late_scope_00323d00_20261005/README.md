# Keep resource and alpha values in the late draw phase

`src/Event/Fcl/y_fclCombineDraw.c::func_00323d00` now declares `res`, `shown`
and `hidden` in the block that produces and consumes them, after the two
initial row loops. Those loops never reference these values. No local address
escapes: the resource and alpha providers consume their arguments by value.
Declaration order, expression order, calls and branch logic are preserved.

The current native target is 1,800 bytes in a 1,808-byte retail window, with
eight zero alignment bytes and **29 fully resolved differing words**. All 57
target references resolve to the retail addresses and addends. This remains
a guarded improvement; `NON_MATCHING` and `INCLUDE_ASM` are retained and no
exact C credit is awarded.

Both the actual default owner and its complete `NON_MATCHING` version were
compiled after installation. The default object is unchanged and its complete
function windows, references and allocated storage are checked against retail.
In the complete guarded version, the other 69 functions preserve their code
and canonical references. All five data sections and 34 data relocations are
unchanged. The single-target candidate from the interrupted investigation is
authenticated separately from the complete guarded baseline.

The source proof compares the complete target's token stream before and after
the change, excluding only the three moved declarations and the added lexical
braces. Each local's first executable use is its write inside the new block.
Additional private `p` and `count` scope experiments produced the same object
and are omitted from the installed change.

`receipt.json` binds the actual source, compiler, inputs, object hashes,
default proof, guarded siblings, data and resolved target residual. It records
these bounded checks without claiming a complete renderer/game execution.

From the repository root:

```text
python docs/probe_archive/Fcl_late_scope_00323d00_20261005/replay.py --hashes-only
python docs/probe_archive/Fcl_late_scope_00323d00_20261005/replay.py --output build/fcl-scope-replay-new
```

The output directory must be new and under `build/`. To reuse the completed
installed-owner builds without compiling them again, use
`--objects build/resume-publication/resume94-fcl-scope`. The replay shares the
existing owner-preservation proof with the field-cleanup archive and verifies
the Fcl target's fully resolved residual separately.
