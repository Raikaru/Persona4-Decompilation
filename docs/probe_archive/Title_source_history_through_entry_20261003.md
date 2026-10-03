# Additional Title audit baselines through callback entry

`Title_source_history_through_entry_20261003.bundle` adds exactly the three
historical baseline commits needed by the palette/model/entry/matrix audit batch:
69799eb8, 81708cc4 and 9bb8b6ad. Its prerequisite bed91675 is supplied by the already
published `Title_source_history_20261003.bundle`. The matrix research commit
c0da65 and all subsequent work are excluded; the current matrix capture reads
before-source at 9bb8 and the integrated candidate source in the working tree.

This is source history only: reviewed Title C, tests and archival text. It
contains no game executable, compiler, compiled object or credential. The
historical entry manifest retains 25 ordinary absolute workspace path strings.
Original commits are immutable and have not been relabeled or sanitized.

## Import into a full public clone

From the repository root, import the existing history first if you have not
already done so, then import this extension:

```sh
git bundle verify docs/probe_archive/Title_source_history_20261003.bundle
git fetch docs/probe_archive/Title_source_history_20261003.bundle HEAD:refs/p4-proof/title-through-bed91675
git bundle verify docs/probe_archive/Title_source_history_through_entry_20261003.bundle
git fetch docs/probe_archive/Title_source_history_through_entry_20261003.bundle HEAD:refs/p4-proof/title-through-entry-9bb8b6ad
```

The old bundle requires public ancestor 862a8d1e. Use a full clone or obtain that
public history first if the clone is shallow. The new proof ref must resolve to
`9bb8b6ad0fafafca04007d67acadff673449bdfa`. These fetches add history objects and
named proof refs without changing the checked-out branch, index or working files.
Existing authorized toolchain and retail inputs remain separate prerequisites.

## Which exact checkpoints to replay

Historical source/capture scripts check their original candidate, not arbitrary
later source. Use a disposable worktree at each corresponding original revision
for palette 69799, model 81708 or entry 9bb8. The matrix report's ordered audit/native
commands apply to the integrated source through c0da65 and compose the prior
bounded machine scopes against that final candidate.

The archive `replay.sh` commands end by running `receipt.py`, which overwrites
historical compact receipts and logs in the archive directory. For a read-only
reproduction of published evidence, run the listed audit/native/provider steps
and omit the final receipt writer, leaving fresh outputs under ignored `proof/`.
Alternatively regenerate receipts only in a disposable worktree and compare them
as fresh evidence; never relabel original checkpoint hashes as the current build.
The historical entry receipt writer also emits absolute archive manifest keys.
The integrated manifest is a separately disclosed relative-path publication copy.

Ordinary unit tests do not import these historical Git objects. They do import
the committed `recovery.py` and `model_recovery.py` helper modules, whose imports
do not execute Git or consume a baseline. Keep those helpers with the source.

## Scope and exact identities

- Bundle bytes: 114474
- Bundle SHA-256: `69e87832ad5e4c8d2bbe90fd80f4043501e58282ca26c60666fa77087f122519`
- Sole prerequisite: `bed91675c50af703b974bd44ede3234eef532590`
- Tip: `9bb8b6ad0fafafca04007d67acadff673449bdfa`
- New history: 3 commits, 21 trees, 90 UTF-8 source/tests/archive blobs
- New absolute-path exposure: 25 ordinary workspace keys in the historical entry manifest

Additional baseline owner snapshots are `src/promoted/code1_0012.c`:

- `69799eb8fe97c414501d20af309688f147e0e5d2`: 208341 bytes, SHA-256 `74b1c9f4960cc7ad2ff43c4ea9b411b64d209cd48013a29275685c07c9d422ec`
- `81708cc4e9e63e3b1eae30f466c069359a8dff70`: 208338 bytes, SHA-256 `05165f28b77b3a137a2e6cd8f64e82854cca3df5fe4ec73b9c5c71819a645397`
- `9bb8b6ad0fafafca04007d67acadff673449bdfa`: 208636 bytes, SHA-256 `bef9fa5dc7b195c83dcbc497d0e8ccecd247929f4e58d9f0f3106af8d146628e`

Entry and matrix source audits also read nine provider/header paths at their
baseline revisions. Those file blobs already equal the public integration
parent; importing these exact commit trees makes their Git lookups resolvable.
No provider or header is changed by this portability addition.
