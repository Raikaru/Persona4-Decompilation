# Exact angular cone emitter: `func_0048ec50`

The actual installed owner `src/promoted/code1_0048.c` verifies **67 MATCH / 6 ASM**.
The angular emitter is **2,308 bytes in its 2,320-byte retail window**, with
**23 resolved references** and twelve zero-alignment bytes. All 72 siblings,
including the preceding exact motion and cone recoveries, remain exact after
reference resolution. The complete owner resolves 589 code references and has
no allocated non-code storage.

## The remaining five-word mismatch

The preceding truthful reconstruction already reproduced the function's 577
instructions, but loaded and converted the signed angular span too early.
Retail first forms the symmetric random phase, then converts the signed span
at parameter offset `0xE8`, then multiplies the two. Naming the real intermediate
phase restores that ordering without a dummy variable or register binding:

```c
b = effMiscRandFloat(0);
ftmp1 = two * (b - half);
transient = angleScale *
    (half * ((f32)*(s32 *)(config + 232) * ftmp1)) - angleOffset;
```

The scalar operations retain their original association and operand order.
The resulting angle is consumed by both `cosf` and `sinf`, whose ordinary float
argument/return contracts are preserved. The independently varied cone spread
sets the X/Z magnitudes and complementary negative Y component before the real
VU normalization and optional basis transform.

Direction and particle snapshots have complete storage. The scale retains the
accepted 16-byte-aligned three-float representation with a native size assertion
and full unsigned-character memory operands. No fourth scalar is invented; the
existing XYZW operations and representation effects remain unchanged. Scalar
RNG logic, traversal, aging, history allocation and integration remain C.

The parent/particle/work contracts are unchanged from the motion/cone family:
32-byte particles, seven-float 28-byte per-particle state, and a complete 16-byte
pre-update snapshot. This variant additionally reads a signed word at `0xE8`,
so its directly accessed parameter extent reaches `0xEC`. The source does not
shrink its parameter backing or add a new input precondition.

## Verification and replay

The interrupted worker's prepared phase body was recovered from disk rather than
regenerated. It was compiled against the current owner with the previous cone
already active. Every relocation was resolved, every sibling and executable
extent checked, and every omitted byte checked as retail zero alignment. The
physical installed owner and its full guarded profile were compiled separately.

The complete GNU image was relinked with the new native owner and 1,221 unchanged,
authenticated inputs. Real definitions and section placement were checked. Both
retail hashes passed:

```text
image:       3d1d3d2b9d6ccb60836db239ab49674223025a78
SLUS_217.82: 4eeec0360cf2715535d9f7e52eb69d786fb0158c
```

`receipt.json` retains the source/tool hashes, all 73 resolved function hashes,
target reference evidence and completed full-link receipt. It contains no native
object or executable. Earlier family receipts remain historical snapshots rather
than silently changing their source bindings. No PS2 gameplay execution or
whole-program independence from unspecified representation bytes is claimed.

With the configured toolchain and authenticated retail executable:

```sh
python docs/probe_archive/Cone_angle_0048ec50_20261005/replay.py --hashes-only
python docs/probe_archive/Cone_angle_0048ec50_20261005/replay.py --output build/cone-angle-replay
```

Native replay requires a new private build directory. Changed source or tools
are rejected rather than presented as the same measured result.
