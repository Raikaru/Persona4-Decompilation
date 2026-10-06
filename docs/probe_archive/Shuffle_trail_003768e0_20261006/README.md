# Shuffle trail recovery: real vertices, sample history and bounded rendering

This is an **installed guarded repair, not a C match**. `func_003768e0` emits
4,176 bytes in its 4,176-byte retail window and still differs at **511 fully
resolved instruction words**. The relocation-masked screening count is 508.
The native stack frame is the retail `0xF50`. No C match is added, and both
assembly fallbacks remain in the production owner.

`body.c`, `prepare.py`, `replay.py` and `receipt.json` form a self-contained
proposal for `src/Battle/btlShuffleDraw.c`. Prime reviewed the entire source
and provider-contract patch, then released the exact prepared source hash
`edf1656665bc52c90e3302c1753ab20595c25dfab1027e80e98f815893edad6b`
for installation. `installed-receipt.json` and `installed_replay.py` bind the
installed owner to the already sealed native and behavioral evidence.
The prepared owner and completed pre-installation proofs are retained under
`build/finish-20261006/fcl-worker5/render-recovery/sealed-proof/`.
Actual-path verification and native objects are under `installed-proof/`
beside that directory. Normal verification reports **50 MATCH / 2 ASM**.
The installed normal and guarded objects both exactly reproduce the sealed
proposal objects; production code is unchanged. The owner is frozen for
prime's next integration batch. No commit or push was performed by this lane.

## What the recovered C changes

The previous guard had actual reconstruction errors, independently of its
register differences. Six low arms of lowered float-to-byte conversions
assigned zero instead of performing the retail conversion. Sample pointers
already based at `spF0` then added `0xF0` again when reading their coordinates.
Several floating decay/scale globals were converted to integers. The outer
render loops in modes 1 and 2 lacked the retail four- and two-pass bounds.

The proposal uses native byte conversions, reads the same 21 positions that
the sampler wrote, retains floating decay/scale values, and renders 4, 4 or
2 passes according to the mode. Each pass submits two 42-vertex strips.
RGB is read after each sampling callback; opacity is captured before those
callbacks. The outer and inner vertices retain their distinct alpha values.
The dimension calls, optional camera/frame call, state writes and draw calls
keep their retail order. The public five-argument interface is unchanged.

The old artificial stack struct is replaced by actual SDK-shaped objects:

| Object | Extent | Native frame placement |
| --- | ---: | --- |
| Identity matrix | 64 bytes | `sp+0xB0` |
| Sample positions | 21 `RwV3d`, 252 bytes | `sp+0xF0`, naturally rounded to 256 |
| Second strip | 42 vertices, 1,512 bytes | `sp+0x1F0`, naturally rounded to 1,520 |
| First strip | 42 vertices, 1,512 bytes | `sp+0x7E0`, naturally rounded to 1,520 |
| Position setter temporaries | 24 three-float objects | 16-byte compiler slots from `sp+0xDD0` |

`include/rw/sky2/rwcore.h:645-676,783-803` supplies the actual color union,
36-byte vertex and position/color setter pattern. The canonical structure
tags and members are retained. Padding in the SDK matrix is part of its
documented 16-byte row layout; no synthetic function-local padding is used.

## Correct shared objects and provider contracts

The direction is one `RwV3d D_0060A0E0`, also exposed by the Battle camera
sources, rather than three unrelated scalar globals. Treating its components
as scalars produced **six out-of-range GP relocations**. The earlier 617-word
screening result is therefore rejected, not a usable floor. The rejection
record retains their addresses and displacements. The actual vector view
generates full-address loads and all 55 final target references resolve.

The prepared owner corrects its declarations of `RwIm3DTransform`'s address
alias, `RwIm3DRenderPrimitive`'s address alias, `RwFrameGetLTM`'s address alias,
and `RpSkyRenderStateSet` to their actual SDK contracts. Existing sibling
callers use explicit pointer views for their stored integer handles. No
provider or shared header changes are required. Both complete owner profiles
compile, and the production object is byte-identical before and after these
declaration repairs.

## The identity flag word is a retail defect, not a matching technique

At `0x0037698C`, retail loads the matrix flag word from `sp+0xBC` before any
instruction in this function writes that slot. It ORs in `0x20003` and stores
the result. Normal modes reach that load without a preceding call. This
corresponds directly to `RwMatrixSetIdentityMacro` at
`include/rw/plcore/bamatrix.h:185-195`: its vector assignments are followed by
`rwMatrixGetFlags(m) | (rwMATRIXINTERNALIDENTITY | rwMATRIXTYPEORTHONORMAL)`.
The macro expects an already initialized flag word; this local has none.

The matrix is live input. `src/renderware/p2/baim3d.c:252-268` stores its
pointer in `curPool.stash.ltm` and calls the selected transform pipeline.
The generic multiply and invert implementations at
`src/renderware/plcore/bamatrix.c:124-179` read flag words and select identity
or orthonormal paths. The dynamically selected platform pipeline has not
been proved to ignore every other bit. Consequently, neither deadness nor
equality of the old unspecified bits is claimed.

The proposal deliberately assigns the defined value **`0x20003`**, matching
the identity matrix's documented type and identity bits. This is a defined
repair of the observed retail initialization defect. It is not presented as
byte-equivalent to the load/OR of unwritten storage. The complete source
still requires its ASM fallback.

## Native and behavioral proof

The final complete owner proof establishes:

- All 52 production functions, 318 code references, four owned data sections
  and 30 data references match retail; the production object is unchanged.
- All 51 other guarded functions preserve their code and canonical references.
  `00375f00` retains its two differences at `+0x48` and `+0x70`; the other
  50 siblings remain exact. All four owned data sections remain exact.
- The target has 55 resolved references, 28 direct calls in retail order,
  three indirect state calls, and 511 fully resolved differing words. The
  receipt preserves the full offsets and resolved code hash.

The standalone `behavior.py` replay of the archived body passed
**53 cases and 13,440 submitted vertices**, including all three modes, zero
and nonzero opacity, positive/negative/zero trail lengths, non-rendering
states and invalid modes. The sampler changes referenced RGB storage to
check callback-visible reloads. Independent expectations check positions,
alpha, finite pass counts, matrix values and call order. Tests use the actual
eight retail float constants. Host bridges adapt native vertex pointers,
the opaque 32-bit frame handle and integer-valued render-state tokens.
Work storage is allocated and the frame handle has a declared typed field.
This is a stubbed behavioral check, not an
emulator or pixel comparison. Native proof independently binds the formatted,
SDK-corrected proposal to the same compiled target instructions.
`behavior-receipt.json` records this final replay; the earlier vector-view
test embedded in the native receipt is retained as historical evidence.

Scoped lint of the prepared owner reports zero errors and 18 warnings.
All 16 declaration advisories refer to unchanged declarations outside this
repair; the other two advisories concern existing optimization pragmas.
The source/proposal diff passes whitespace checks.

## Replay and handoff

From the worktree root, use a fresh output directory:

```text
python docs/probe_archive/Shuffle_trail_003768e0_20261006/installed_replay.py --output build/shuffle-trail-replay
python docs/probe_archive/Shuffle_trail_003768e0_20261006/behavior.py build/shuffle-trail-behavior
```

`installed_replay.py --hashes-only` authenticates installed inputs.
`--objects DIRECTORY` checks existing `default.o` and `guarded.o` files.
The replay only writes under `build` and never changes the source. It uses
the configured native b210 compiler and checks code, owned data, sibling
preservation and the retained residual. The original `replay.py` and its
receipt remain immutable evidence for the pre-installation source; running
that historical preparation requires its recorded original owner hash.
The behavioral replay additionally uses host GCC and fresh storage under
`build`; it compiles the archived body with the documented ABI bridges.

Exploratory source, measurements, the invalid-scalar rejection and behavioral
test source/receipts remain in the unique `render-recovery` scratch directory.
The original guard's 973-word masked score is historical screening of that
unsafe draft, not a full relocation-valid reference implementation.
