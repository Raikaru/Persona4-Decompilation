# Remove artificial calls from the field-state guard

`src/promoted/code1_0016.c::func_0016bdd0` retains its `NON_MATCHING` guard and
retail assembly fallback. This change removes 22 artificial getter calls,
their `keepS0..keepS21` locals, and the `0x12345678` sink that existed solely
to keep those values live. Those calls do not appear in the corresponding
retail entry path. The real calls and state-dependent operations remain.

The earlier commentary about entering an instruction-count band is replaced
by the current disposition. Instruction-count similarity is not exactness.
This incomplete guarded reconstruction still needs aggregate storage,
lifetimes and provider types recovered; it receives no new C match credit.

## Verified preservation

The native compiler builds the actual installed owning file in default and
`NON_MATCHING` modes. The complete default object remains byte-identical to
the preceding object. All 64 default function windows, their resolved
references and owned storage are checked against the retail executable.

In the complete guarded object, all 64 other emitted functions, including
the existing private helper, preserve their code and canonical relocation
targets. The two sibling switch tables and all canonical data-relocation
targets remain unchanged. The target's own 32-byte switch table is regenerated:
its eight addends address the changed target's native basic blocks. Each entry
is aligned and remains within that function. The cleaned target is 8,828 bytes in a
9,280-byte retail window and still differs; its 196 code relocations are
22 fewer than before. Its earlier 2,069-word score uses relocation masking
and is not an exact or fully resolved matching claim.

`receipt.json` binds the before/after source and native objects, compiler,
effective options, inputs, default proof, guarded siblings and all three
guarded data sections. The earlier worker40 data summary indexed sections only
by name and collapsed duplicate `.rodata` sections. This receipt supersedes
its blanket unchanged-data claim with separate table hashes and offsets.
The interrupted worker40 proof was authenticated before installation and
its successful compilations were preserved. Fresh installed-owner builds
confirm that the actual source reproduces the reviewed objects.

The complete function's runtime behavior is not certified. In particular,
this cleanup does not approve its remaining raw storage or unresolved
reconstruction assumptions. The default assembly-backed build is preserved.

## Replay

From the repository root:

```text
python docs/probe_archive/Field_guard_cleanup_0016bdd0_20261005/replay.py --hashes-only
python docs/probe_archive/Field_guard_cleanup_0016bdd0_20261005/replay.py --output build/field-cleanup-replay-new
```

The output directory must be new and under `build/`. The second command
compiles only this complete owner in its two modes and repeats the proof.
Use `--objects build/resume-publication/resume94-field-guard` to authenticate
and verify retained objects without repeating compilation. The latter uses
temporary private proof output and preserves the retained files.
