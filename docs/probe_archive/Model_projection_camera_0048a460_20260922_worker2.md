# Model projection camera contract follow-through, 2026-09-22

The camera getter declaration in `src/Graphics/Model/mdlEffect.c` now agrees
with the active first-party provider. `src/promoted/code1_0045.c:1360` defines
`s32 func_00457120(void)` and returns `iGpffffba80`. Retail `00457120` loads that
word with `lw` into V0, then returns. No provider or vendor source was changed.

Both model declarations now use `s32`. All 15 camera results are explicitly
converted with `(u8 *)(u32)` before pointer access or passing the camera base
to `mdlEffect_camera_matrix`. The conversion retains the 32-bit address value;
call count, order, matrix offset and field offsets are unchanged. Four of the
calls belong to the guarded `func_004a6e70` draft.

The previous `integration-final` receipts remain immutable historical evidence.
They established exact projection code but preceded this camera declaration
correction. The new final evidence is in
`build/first-party-next-20260922/model-effect/integration-camera-v2/`.

## Validation

* `official.json` reports 52 MATCH and one ASM across all 53 first-party model
  functions. `func_0048a460` remains MATCH; `func_004a6e70` remains ASM.
* `func_0048a460-unmasked.json` proves all 176/176 bytes, all ten code
  relocations, zero unmatched suffix bytes and no referenced owned data.
  Resolved SHA256 is
  `180838399912617a7b4a8f59ace19bbb7973771d3686194f4fdc6cd837cda97a`.
* `active-preservation.json` compares the candidate against the exact sealed
  historical model object. The target, all 52 siblings, canonical code
  relocations and all allocated data are unchanged. The entire object is
  byte-identical.
* `guard-before/` and `guard-after/` contain fresh, unique native compiles of
  the respective whole owners with the guarded flare C body activated using
  the existing function-region splice helper. `guarded-preservation.json`
  proves identical code, canonical relocations and data for all 53 functions.
  The entire guarded object is byte-identical; the flare C body stays 2332
  bytes. This preserves the inherited draft's behavior, not a new flare match.
* `lint.json` reports zero findings. Scoped `git diff --check` passed.
* `inputs.json` fingerprints every historical `integration-final` artifact.
  The inventory remained unchanged through final validation and release.
  The camera provider and `src/promoted/code1_0048.c` source hashes were also
  checked unchanged. No additional caller-owner edit was needed in this pass.

Native compiler is mwcc b210 with `-O2 -Iinclude`. Each new compiler invocation
has its own source, object, log and hash receipt. Live official verification
reuses the successfully compiled candidate's identical source/object bytes;
`model/compile.json` records that reuse. Historical compiles were not rerun.

## Final hashes

| Artifact | SHA256 |
| --- | --- |
| Model source, camera v2 | `85c7c2f285112adb5a7de4de13b4a3832b191fd2a28efd9b4aef70d7a394ebc8` |
| Model object, unchanged | `4235b879a38ff4071536e640d6776aa7c0ca0a6f33f58dd6739f38aee7b270c4` |
| Guarded owner object, before and after | `c2a1a65de556d7f5acf88c27ccf418a2554ac8e8e250986fb804ab3ecc9bc2e5` |
| Model source, historical integration | `21114db6788642d25444d33e13be7616dd99a34e696d47a5b479b4cdf02eea39` |
| Projection caller source, unchanged | `535a3a1807d25fbfcadd4ff10a2592a319934d028f264a90126a53374f7f2323` |
| Projection caller object, historical receipt | `8f7c2d8668f792f1808f6423bcc0adb93de8729d3f5aec8df6694bd96560e373` |
| Native b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

`mdlEffect.c` is released after sealing `integration-camera-v2/release.json`.
This pass makes no publication or whole-repository build/test claim.
