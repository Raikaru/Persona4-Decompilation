# Model projection depth result: exact recovery, 2026-09-22

`src/Graphics/Model/mdlEffect.c::func_0048a460` is integrated as C and officially
MATCH. The saved 15 differing words at 176/176 bytes disappear when the routine
returns its initialized camera-space depth as `f32` while retaining its existing
VF10 projection result. Native compiler: mwcc b210, owner flags `-O2 -Iinclude`.

## Result and behavior

Retail loads transformed Z into F0 at `0048a4b4`, uses it as the divisor for both
screen coordinates, and preserves it through return. The reconstruction captures
that value after the transform, uses it for both divisions, then returns it by
value. This expresses the actual initialized F0 output and naturally reproduces
the retail FPR/GPR allocation. It does not return the address of local storage.
The existing two genuine COP2 transfers remain the only assembly in this body;
all scalar computation is C.

The sole live caller, `func_0048b220`, calls at retail `0048b2ac` and `0048b2bc`.
Both calls consume VF10 and discard F0. Its local declaration now agrees with the
`f32` definition; neither call nor its arguments changed. Prime authorized this
one declaration edit in `src/promoted/code1_0048.c`. Its inherited particle
forwarding changes were preserved against the supplied source hash below.

The model owner's local transform declaration now agrees with the read-only
`RwV3dTransformPoint` provider: destination-pointer return, const input and
matrix pointers. Its destination is written by the provider's actual point
transform callback. All three owner call sites use compatible pointer types.
No SDK/vendor source, shared header, configuration or compiler tool was edited.

## Validation

Evidence root: `build/first-party-next-20260922/model-effect/`.

* `baseline/official.json`: fresh native baseline, 51 MATCH and 2 ASM.
* `projection-depth-result/official.json`: exact candidate, 52 MATCH and 1 ASM.
* `integration-final/official.json`: both live owners, 112 MATCH and 14 ASM
  across 126 first-party functions. Projection and caller both MATCH.
* `integration-final/func_0048a460-unmasked.json`: 176/176 bytes, all 10
  relocations resolved without masks, no suffix, no owned data references.
  Resolved SHA256: `180838399912617a7b4a8f59ace19bbb7973771d3686194f4fdc6cd837cda97a`.
* `integration-final/func_0048b220-unmasked.json`: 276/288 bytes, all 6 call
  relocations resolved without masks, exactly 12 zero suffix bytes.
* `integration-final/proof.json`: all 52 other model functions and all 73 caller
  owner functions retain identical bytes and canonical relocations; allocated
  data is unchanged in both owners. The entire caller object is byte-identical.
* `integration-final/lint.json`: both first-party files, zero findings.
  Scoped `git diff --check` passed. No whole-repository build/test or publication.

Every native compile has a unique retained source, object, log and hash receipt.
Official checks reused the exact sealed native objects. Historical objects were
not recompiled or overwritten.

## Source and object hashes

| Artifact | SHA256 |
| --- | --- |
| Model source before | `a7e65d5f5bed276a1e7e8e1fa86acfde977a66a114ca71487ef3d78be8d85626` |
| Model source integrated | `21114db6788642d25444d33e13be7616dd99a34e696d47a5b479b4cdf02eea39` |
| Model object before | `8b96e38d14287e159961b733ada19d7cd5d6d38e5c877a99da7b07b6529be224` |
| Model object integrated | `4235b879a38ff4071536e640d6776aa7c0ca0a6f33f58dd6739f38aee7b270c4` |
| Caller source inherited | `a5aea3961315a810fe06ae809646b4f816470241df7b0b2b87fa1535ad4ece93` |
| Caller source integrated | `535a3a1807d25fbfcadd4ff10a2592a319934d028f264a90126a53374f7f2323` |
| Caller object before and after | `8f7c2d8668f792f1808f6423bcc0adb93de8729d3f5aec8df6694bd96560e373` |
| Native b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

## Remaining fallback and retained investigations

`func_004a6e70` remains ASM. Its guarded draft omits actual VF10 projection and
misreconstructs parts of color scaling and camera-depth math. The scratch
`flare-vu-and-lifetimes-v1/` adds genuine VU/MMI operations and repairs those
operations, measuring 2112/2288 bytes and 267 alignment edits, with unchanged
siblings/data. It is not exact and was not integrated. The fresh guarded flare
baseline compiled to 2332 bytes; simple relocation analysis reported unsupported
`R_MIPS_LITERAL` for `@835`, retained in its result receipt.

Projection probes before the depth-result discovery cover true transform
callback/results, caller-owned output scopes, registered shared depth and
initialized aggregates. None improved the void baseline. Four initial aggregate
variants were rejected by native C89 declaration rules and retained; nested-block
versions were new compiles. The wide-literal candidate emitted an unresolved
`fptodp` helper and was rejected. These are recovery evidence, not production
changes. The successful mechanism is the meaningful scalar depth result.

Both edited owners are released after the final receipt and note are sealed.
