# Title audit source-history prerequisite, 2026-10-03

The accompanying `Title_source_history_20261003.bundle` contains source history
only: reviewed Title C, tests and archival text evidence. It contains no compiler,
retail executable, disc image, compiled object or credential. Its historical
receipts preserve six original local tool-root path strings; it is not a
sanitized rewrite of those original commits.

The public source integration is based on commit
`53c93aa4525a72d6eeadbe0cfb3b8f8b8e4c34e3`. Historical capture scripts use exact
research commit IDs for their before-source, which a squashed public commit
does not otherwise carry. Import this bounded history before following those
capture instructions; the scripts and immutable evidence need no edits.

## Import into a full public clone

The bundle requires public ancestor `862a8d1e00d9aa26086aef62bfabdc583e1b1851`.
Use a full clone, or obtain that public history first if your clone is shallow.
From the repository root:

```sh
git bundle verify docs/probe_archive/Title_source_history_20261003.bundle
git fetch docs/probe_archive/Title_source_history_20261003.bundle HEAD:refs/p4-proof/title-through-bed91675
```

The imported ref must resolve to
`bed91675c50af703b974bd44ede3234eef532590`. This fetch only adds source-history
objects and the named proof ref; it does not change the checked-out branch,
index or working files. The original frozen checkpoint IDs are preserved.
Continue to use the exact before/candidate revisions documented by each
historical report. The bundle does not make a later controller revision the
candidate for an earlier checkpoint's assertions. The latest sprite-alpha
report's ordered audit commands apply to the integrated source through bed91675.

Existing authorized toolchain and retail inputs are still required for machine
capture/rebuild audits. Follow the repository setup/split/regeneration steps.
Ordinary CI unit tests do not read the research commits or invoke these archive
capture scripts, so this import is for reproducing historical capture evidence.

## Bundle identity and bounded content

- Bytes: 152017
- SHA-256: `29a91aa5208283693bb1f71c3dc978c2593414235e53ddb546914812a5ff49b4`
- Prerequisite: `862a8d1e00d9aa26086aef62bfabdc583e1b1851`
- Tip: `bed91675c50af703b974bd44ede3234eef532590`
- 144 newly included blobs, all checked as UTF-8 Title source, tests or archive text
- Public overlay/color prerequisites and the nine accepted increments through
  sprite alpha are included; ongoing palette work and unrelated owners are excluded

## Exact baseline owner identities

Each baseline is `src/promoted/code1_0012.c`. SHA-256 checks identify the source
bytes, independently of where the Git objects are stored.

- Commit `87ed8afca8b62d80fe72148b10122a596e5996dc`: 214659 bytes, SHA-256 `52770f5aa8a580a7cfaec4e3fb312c94c30536956a22656eb444167f870aed0a`
  - `docs/probe_archive/Title_alpha_aliases_001265a0_20261003/capture_owner.py`
- Commit `5f3ee52967caa0838cc534a9f1bfdb6ef05dde07`: 213538 bytes, SHA-256 `46ae7c16d122143107ae8d8d0bc7a8dc69ce16eafc8a5dfaf935d056910ace37`
  - `docs/probe_archive/Title_color_families_001265a0_20261003/audit_retail.py`
  - `docs/probe_archive/Title_color_families_001265a0_20261003/capture_owner.py`
- Commit `fd71083ec6e1a69e27b86f947618e913e5acd20e`: 214671 bytes, SHA-256 `0dff10126bc1852b803110689eedf466ee1abb16b3d69d070975a66741985360`
  - `docs/probe_archive/Title_fade_contract_001265a0_20261003/capture_owner.py`
- Commit `1e0890133eeeb90c482cfbcedd24a6d5ce090645`: 214695 bytes, SHA-256 `9ab109c32063adff134a5bde2911814e92e626678f9eb66f82f8c41239ebbead`
  - `docs/probe_archive/Title_gp_color_transport_001265a0_20261003/audit_gp_colors.py`
  - `docs/probe_archive/Title_gp_color_transport_001265a0_20261003/capture_owner.py`
- Commit `de43968228ce8c80c11ceccb6d19e1c9ff09f5fa`: 213054 bytes, SHA-256 `1163564f1e8e6bc9864dd1bc25e056c028fa08970cbd8771d4a739b6bf6bb6b0`
  - `docs/probe_archive/Title_layer_contract_001265a0_20261003/capture_owner.py`
- Commit `9d485ae870fd8ea6b8986dde35984b71789e6d06`: 214559 bytes, SHA-256 `4b4f028ce15cba8ca90c51608315d84e80127c2885c5be8cd306e19ec4471e75`
  - `docs/probe_archive/Title_rectangle_aliases_001265a0_20261003/capture_owner.py`
- Commit `29758b87c3234fa4f519127c1f61722ca1d087d8`: 214938 bytes, SHA-256 `7120145a1c2cde61b186f95d54e5761867e58e90a2d77640c1511c6927397952`
  - `docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/audit_source.py`
  - `docs/probe_archive/Title_sprite_alpha_contract_001265a0_20261003/capture_owner.py`
