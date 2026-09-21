# Side-camera frame update: 001c04e0

The saved side-camera delivery was recovered, reviewed and installed after
rebasing the first-party continuation onto upstream `6fce030`. All 873 sealed
artifact hashes, seven live baseline sources and their transitive include
dependencies were checked before applying the patch. The complete historical
delivery is retained in
`build/first-party-resume-persist/side-camera/sealed-seven-owner/`.

## Exact result and preservation

Fresh compilations of the actual seven production owners prove
`func_001c04e0` at **1208/1216 bytes**, with **20 resolved code relocations**
and eight zero alignment bytes. No target-owned data is introduced. The
resolved executable prefix has SHA-256
`99796083e13f2fb71901eb96cd6274766713b3fbc12fe032785c723fb954e2b2`.

All **580 other functions** retain their bytes and canonical relocations.
All **18 allocated data sections** retain their contents, alignment and
relocations. The official seven-owner verifier reports **538 MATCH / 43 ASM
over 581 functions**, with no unexpected status. Scoped lint reports zero
errors and nine inherited optimization advisories in other functions.
`git diff --check` passes.

| Owner | Other functions preserved | Allocated data sections |
| --- | ---: | ---: |
| `src/Battle/btlCamera.c` | 46 | 2 |
| `src/Battle/btlCamera_grouped.c` | 11 | 0 |
| `src/promoted/code1_001b.c` | 123 | 1 |
| `src/promoted/code1_001c.c` | 62 | 2 |
| `src/promoted/code1_001d.c` | 94 | 1 |
| `src/promoted/code1_0020.c` | 146 | 0 |
| `src/promoted/code1_0022.c` | 98 | 12 |

The before/after placement checks preserve all seven owners' existing
ineligibility: their unresolved references and text gaps are unchanged. A
function recovery does not by itself claim a new C-linked owner.

## Recovered source and interfaces

The reconstruction starts from the Persona 3 FES
`btlCameraFrameActionSide` body at `002a6ee0`. That donor is itself marked
NONMATCHING; it is a source-shape reference, not proof of a P3 exact match.
Retail P4 instructions and current P4 providers determine the accepted source.

The work uses genuine three-float vectors, two-float XZ arrays and two
28-byte position/quaternion camera frames. It removes the old artificial
stack gaps. Sphere-center getters initialize both centers, the in-place
normalizers initialize the direction values they consume, and the projection
helper writes both elements of its output array. `func_001bd780` supplies the
frame quaternion; the target assigns the three position components before
passing the complete frame onward.

The actual `001c8e90` retail output writes position at offsets 0, 4 and 8,
and quaternion at offsets 0xC, 0x10, 0x14 and 0x18. The subsequent
`001bab00` provider reads the same three position and four quaternion values.
Its declaration is reconciled to the existing `void (u16 *, f32 *)`
definition. This makes the complete frame storage and API inputs explicit.

The visibility function uses one declaration and definition throughout the
seven owners:

```c
void func_001bcd40(u8 *action, u8 *first, f32 *second,
                  f32 radius, u16 mode);
```

All 86 call sites preserve the same action, endpoints, radius and mode. The
radius precedes the final mode in source order, while the EE integer and
floating-point argument registers retain the retail contract. Two existing
zero-radius callers use a small inline `cameraApplyVisibility` helper so
their complete existing instruction streams remain exact. The helper performs
only the real action load and visibility call.

The target retains both visibility passes. The first uses the camera endpoints
and half the sum of both original radii and center separation. The second
uses both original unit centers and the selected original radius. The unit
chosen for camera positioning is kept separate from those original captures.

## Floating-point comparison evidence

The retained radius helper uses `if (first > second) return first; return
second;`. Under this owner's b210 `-O2` profile it reproduces the exact retail
comparison, branch and register move. The selected word sequence is included
in the full unmasked target proof, not accepted from a float algebra argument.

The alternative `!(first <= second)` spelling was also measured. It gives the
same-sized body but the wrong comparison instruction. These source forms are
not universally equivalent for NaNs, and the recovery makes no such portable
equivalence claim. The accepted evidence is the actual compiler output under
the configured retail profile. No assertion that NaNs are impossible is used
to waive a differing instruction.

## Reproduction and evidence

Current-source dependency fingerprints, compiler output and all neighbor,
data and placement comparisons are in
`build/first-party-next/camera-current/proof.json`. Each owner has its own
`current.o`, compiler log and proof record below that directory. The official
result is `camera-current/official.json`.

```text
python tools/verify.py src/Battle/btlCamera.c src/Battle/btlCamera_grouped.c src/promoted/code1_001b.c src/promoted/code1_001c.c src/promoted/code1_001d.c src/promoted/code1_0020.c src/promoted/code1_0022.c --json build/camera-verify.json
```

`build/first-party-next/camera_current.py` contains the independent seal and
production proof. Its completed output directories are immutable records;
use a new output directory for a later source revision rather than silently
replacing the evidence. Subsequent visibility-provider recovery is a separate
change and must preserve this exact caller and its actual interfaces.
