# Title baseline history through the layout checkpoint

This extension supplies the two exact historical Title baselines required by the
layout and helper-call captures: c0da65b9 (matrix) and 6807e26b (layout). It requires
9bb8b6ad from the preceding public source-history bundle. The current helper
research commit and all later experiments are excluded because current captures
do not read them as historical inputs.

The bundle contains only reviewed Title C, tests and archival text evidence.
There are no game executables, compilers, compiled objects or credentials. All
64 new blobs were checked as UTF-8 with no NUL bytes, credential-pattern hits or
absolute workspace-path strings. Earlier bundles retain their already-disclosed
historical path strings; no historical commit is rewritten.

## Import the bounded history

Use a full public clone, or obtain the required public ancestor history first.
Run from the repository root, skipping a prior import if its proof ref exists:

```sh
git bundle verify docs/probe_archive/Title_source_history_20261003.bundle
git fetch docs/probe_archive/Title_source_history_20261003.bundle HEAD:refs/p4-proof/title-through-bed91675
git bundle verify docs/probe_archive/Title_source_history_through_entry_20261003.bundle
git fetch docs/probe_archive/Title_source_history_through_entry_20261003.bundle HEAD:refs/p4-proof/title-through-entry-9bb8b6ad
git bundle verify docs/probe_archive/Title_source_history_through_layout_20261003.bundle
git fetch docs/probe_archive/Title_source_history_through_layout_20261003.bundle HEAD:refs/p4-proof/title-through-layout-6807e26b
```

The final ref must resolve to `6807e26bf4896fd803f01b9cb9182ea3df8d3a86`.
These fetches add Git objects and proof refs without changing the checked-out
branch, index or working files. The Field AI normalization capture uses public
commit `3686cbd1a9335bc20463f8c24b81127c6eb09e8c`, so it needs no additional
research-history bundle.

Licensed toolchain and retail inputs remain separate setup requirements. Use
historical reports at their exact candidate revisions; a later controller is
not automatically the candidate for an earlier source-transform audit. The final
helper-call audit sequence composes the earlier bounded scopes onto the current
source. Layout's exact source audit also reads its prior palette fixture and four
provider/header files at c0da; the imported tree preserves those lookups.

Archive replay scripts may end with receipt.py, which overwrites historical
compact receipt files. Omit that last writer for read-only reproduction and retain
fresh outputs under ignored proof/, or regenerate only in a disposable worktree.
The four trailing spaces in the helper native-summary.log sanitizer-rejection
lines are exact historical output and are intentionally preserved with its manifest.

## Exact bundle identity

- Bytes: 93023
- SHA-256: `877d56573246626e4c5bb8294f34968454f5483acbd4ff5edd36c6b5206ba9c8`
- Sole prerequisite: `9bb8b6ad0fafafca04007d67acadff673449bdfa`
- Tip: `6807e26bf4896fd803f01b9cb9182ea3df8d3a86`
- Included history: 2 commits, 14 trees, 64 source/tests/archive blobs

Required Title owner snapshots, both at src/promoted/code1_0012.c:

- `c0da65b93e785858dad848163c2482b7b0d533cb`: 208809 bytes, SHA-256 `d66ac8bdfa05fc0e582b916dd8a550cd34ec030c8e20a4f2c8c4146ee6cd8360`
- `6807e26bf4896fd803f01b9cb9182ea3df8d3a86`: 208734 bytes, SHA-256 `a6684ac3ce4e80240fa76651c1de17bd2562e429192ff48bdb577f1df233ee64`
