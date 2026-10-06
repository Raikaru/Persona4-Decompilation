# Exact cone emitter: `func_0048e2f0`

The cone emitter is now unguarded C in `src/promoted/code1_0048.c`. Its actual
owning translation unit verifies **66 MATCH / 7 ASM**. The target occupies
**2,244 bytes in a 2,256-byte retail window**, has **20 resolved references**,
and leaves exactly twelve retail zero-alignment bytes. All 72 sibling functions
retain their exact resolved instructions. The full owner has 584 code references
and no allocated non-code storage.

## Source recovery

This recovery reuses the established motion emitter's complete-object contracts,
not its machine instructions. The direction is a real four-lane VU object. The
scale is an explicitly 16-byte-aligned three-float aggregate with a native size
assertion. Both scale loads name its complete representation through unsigned
character arrays. The fourth word is natural alignment padding, not a fourth
uninitialized float member. Existing XYZW hardware operations and their effects
remain intact; no claim is made that the fourth lane is universally unobservable.

The cone direction uses the spread and variation at parameter offsets `0xD0`
and `0xD4`. Its X/Z components are symmetric random samples and its Y component
is the complementary spread. It is normalized and, for the nonlocal-space path,
transformed by the basis produced from the parameter quaternion. Speed uses
`0xD8/0xDC`; acceleration and gravity use `0xE0/0xE4`. Preroll uses the existing
quadratic integration, while live updates retain the linear increment.

One genuine `variation` local is reused at the direction, speed, spread, opacity
and angle stages. Its declaration/lifetime, followed by the existing scalar
constants, recovers the retail floating-point allocation. The variable always
has a real producer before use. No register binding, unused local, fake argument,
compiler patch, ordinary-computation assembly or inserted padding is involved.
Scoped propagation and loop-invariant options are retained as measured compiler
inputs. Allocation, traversal, RNG decisions and scalar integration remain C.

The particle stride is `0x20`, and the separate seven-float state stride is `0x1C`.
The pre-update snapshot owns sixteen bytes; history replication copies an entire
32-byte particle. The highest directly read parameter field ends at `0xE8`.
The existing parent, successful-allocation and count contracts are unchanged.

## Validation and provenance

The private exact candidate was compiled in its complete current owner and then
installed with only a target status-comment/classification change. The physical
installed owner was compiled again. An independent resolver checked every code
reference and sibling against the authenticated executable, including zero tails
and allocated-storage coverage. The owner's full `NON_MATCHING` configuration
also compiles; remaining attempts keep their fallbacks.

The actual GNU linker consumed a newly compiled native owner together with 1,221
authenticated unchanged inputs. Existing real function definitions and placement
selectors were checked, not just the final bytes. The resulting image and rebuilt
executable reproduce both retail SHA-1 values:

```text
image:       3d1d3d2b9d6ccb60836db239ab49674223025a78
SLUS_217.82: 4eeec0360cf2715535d9f7e52eb69d786fb0158c
```

`receipt.json` contains source/tool input hashes, per-function resolved hashes,
target relocation evidence and the completed link receipt. It contains no native
object or retail executable. It records only the tested scope; no PS2 gameplay
execution is claimed. Earlier motion/scene receipts remain dated snapshots and
are not silently rewritten to hide this owner change.

From the repository root, with the configured compiler and authenticated retail
ELF available:

```sh
python docs/probe_archive/Cone_emitter_0048e2f0_20261005/replay.py --hashes-only
python docs/probe_archive/Cone_emitter_0048e2f0_20261005/replay.py --output build/cone-emitter-replay
```

Native replay requires a new private output directory. Hash-only replay does not
compile. Any changed input requires a new proof instead of transferring this
receipt to different source.
