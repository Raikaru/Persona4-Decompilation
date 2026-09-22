# Battle camera setup: func_001b6120

The reviewed source reconstructs the camera snapshot, quaternion conversion,
palette copy, and effect geometry setup at `0x001b6120`. It reproduces all
1,968 retail bytes. This note accompanies a scratch proposal prepared on
`457acdb30c641ac5d68ce03c80e361aa128ec526`; production remained frozen during this review.

The final receipt directory is
`build/finish-first-party-20260922/battle-camera-worker7/proposal-provider-return-03`.

## Native evidence

| Check | Result |
| --- | --- |
| `func_001b6120` | 1,968 bytes / 1,968-byte window; no tail |
| Resolved relocations | 100; every target/address checked |
| Function-owned data | None |
| `func_00482f70` provider | 380 bytes / 384-byte window; four zero tail bytes; six relocations |
| Camera siblings | All 122 retain exact bytes and canonical relocations |
| Whole eight-owner proposal | All 544 other functions and all allocated data preserved |
| Official proposal score | 516 MATCH / 21 ASM first-party; 537 first-party functions |
| Other third-party functions in these owners | One MATCH / seven ASM, unchanged |

The camera source SHA-256 is `c3c07f9a949d92976e7f6078a21986fb5a01e9f8796fafc55b5cb370463df133`.
Its native owner object SHA-256 is `5db9e09394ee859f250a2cc3a79ba13efadd78393cc135afdbaa0da11bbf5498`.
The fully relocated camera function SHA-256 is
`1c4f086a16082c0bc688440e18bc3475ea6e4036a8c86f61aaa1b31692054629`.

The configured compiler is `mwcps2-3.0.1b210-060308/mwccps2.exe`, SHA-256
`286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`, with the owner's actual
`-O2 -Iinclude` profile. The final step compiled this exact UTF-8 camera source
once and reused seven authenticated native owner objects. Sources, compiler,
flags, dependencies, remaining assembly inputs, and object hashes are recorded
in `completed.json` and the individual compile receipts. Official scoring used
those authenticated objects without repeating native compilation.

## Why the retained zero was review-only

The earlier `battle-after-rebase/camera/review-only-geometry-pointer-contract`
candidate changed the camera's local geometry declaration, while the actual
provider still declared its fourth parameter as a signed integer. The saved
worker explicitly withheld installation because the provider and other callers
needed a coordinated contract change.

The later `camera-family` scratch proposal already supplied shared geometry and
palette headers and eight successful native owner compiles. That work was
authenticated and reused. Two saved complete source copies were stale: the
current `code1_001f.c` has the skill-target contract correction, and current
`code1_004b.c` has corrected fishing/model forwarding wrappers. This proposal
preserves both changes and verifies their complete owners.

## Provider and caller contracts

`effect_geometry_internal.h` declares the provider's complete signature:

```c
u8 *func_00482f70(s32 copies, s32 triangles, s32 vertices,
                  const void *indices, s32 flags);
```

The provider in `src/promoted/effGeometry.c` reads three unsigned halfwords per
triangle at offsets 0, 2, and 4, then advances by three halfwords. Its byte
pointer arithmetic now expresses that real index-buffer input. The provider
and all six caller owners include the same declaration. Callers that inspect a
halfword field in the returned effect object explicitly cast the returned byte
pointer; they no longer give the provider incompatible private return types.

All 14 retail calls were matched to their source calls. Each loads a real table
address into the fourth argument. Every index in each used table range is below
the caller's vertex count. The camera uses 118 triangles, 89 vertices, and
354 indices ranging from 0 through 88 at `D_0060A140`. The complete call sites,
table hashes, bounds, and byte-authenticated retail instruction snippets are in
`geometry-contract-audit.json`.

The texture lookup now uses the actual two-argument pointer API:
`RwTexture *func_003ef650(RwTexDictionary *, const char *)`, and its dictionary
getter returns `RwTexDictionary *`. These agree with
`src/renderware/core/batextur.c`. The old integer dictionary return and variadic
lookup declaration are removed.

The current first-party camera/light getters `func_00457120`, `func_004571a0`,
and `func_004571c0` return stored `s32` address words in
`src/promoted/code1_0045.c`. This owner now uses those actual return types and
explicit pointer conversions. All seven uses of the main getter's result,
including already matching siblings, retain their native bytes. The separate
discarded getter call remains unchanged. The scene vector/matrix getters agree
with `src/Kosaka/Field/k_sceneDraw.c` and `src/promoted/code1_0014.c`.

## Complete palette and matrix storage

`btl_camera_palette_internal.h` uses the four-byte `struct RwRGBA` layout from
the SDK. `D_007635C8` names the complete primary palette, and `iGpffffb45c`
names the complete secondary palette. The latter also agrees with the existing
definition of that structure in `code1_0022.c`. The proposal removes the reads
beyond the unrelated scalar `fGpffffb458` and the aggregate read through the
first byte alias of the primary palette. The two panel uses of `D_007635C8` in
`code1_001f.c` take the complete object's address. Existing byte aliases remain
available for individual channel accesses.

The 64-byte, 16-byte-aligned matrix has the SDK's actual four rows: a three-float
vector followed by flags or `pad1`, `pad2`, and `pad3`. Retail writes the twelve
float components and flags, but does not initialize the reserved words at stack
offsets `0xCC`, `0xDC`, and `0xEC`. Instructions `0x001b64f0` through
`0x001b6518` then copy all four 16-byte rows to `D_00922C60`. The source preserves
this directly evidenced retail omission and documents it at the assignment;
it does not invent initial padding values. The SDK layout is recorded in
`include/rw/plcore/bamatrix.h:143-160`.

Control flow also retains retail's resource assumptions: the effect-creation
block tests the texture lookup, then uses the geometry result without adding a
new allocation check. The retail call and immediate use at `0x001b672c` onward
are the evidence for that omission. The scoped `opt_loop_invariants` pragma
retains the UV scale and white color used by the 89-vertex loop and restores the
previous compiler state afterward.

## Review and installation

`review.patch` is the complete atomic proposal: eight source owners, two shared
headers, and this note. `review.diff` is its unified diff; `review-manifest.json`
records every before/after hash. No production files, compiler configuration,
build configuration, or vendor implementations were changed by the worker.

After prime installs the exact reviewed files at an appropriate publication
boundary, `build/finish-first-party-20260922/battle-camera-worker7/verify_installed.py`
can authenticate the current sources and run the official scorer using the
completed native objects. It refuses to run against different source/header
bytes. Until that step is performed, the official result here is a proposal
result and production `func_001b6120` remains ASM. The proposal adds one C MATCH
relative to the authenticated 6506-MATCH baseline; other workers' progress is
left to prime's publication accounting.
