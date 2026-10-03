# Large Battle hit predicates: load values from the retained addresses

Base: `64ca61782d3251142af9cf5e6da62e84a79b4ea1`.
Owner: `src/promoted/code1_001a.c`.
Targets remain guarded `001a59a0` and `001a7720`; this is a bounded semantic
repair, not a C promotion or a complete controller reconstruction.

## Retail evidence and source changes

### Signed motion in 001a7720

The hit loop saves the address of its motion byte, at the current hit base
plus 0x10c. The animation creation call already loaded it correctly after the
preceding animation-contract repair. Two later conditions still compared the
address itself with 9 or -1.

Retail is unambiguous:

- `001AA238..001AA250`: restore the retained address, `lb` its signed byte
  into a1, then call the animation factory
- `001AA308..001AA328`: restore the address, `lb` into v1, compare the byte
  with 9, then call `0023df70` only when all prior gates passed
- `001AA668..001AA6AC`: restore the address and `lb` again, compare against
  -1, check the two unsigned unit-kind bytes when necessary, and then call
  `datCalcChkBadStatus` with mask 0x180001

The local is now `s8 *hitMotion`. The factory and both predicates dereference
that actual pointer at their original source sites. The byte is not cached
across calls. No pointer is compared with an animation ID.

The obsolete local `datCalcChkBadStatus()` declaration is removed, using the
owner's existing `u32 (s32, u32)` contract. The call explicitly transports its
real data pointer as the provider's EE address word. The skill predicate's
local declaration now states its actual `s32 (s32)` signature. Neither
provider nor shared declarations change.

### Added status in 001a59a0

The hit loop retains `&hit->addedStatus`. Its first condition already read the
word, but the later branch tested the numeric address for bit 0x100000.
Retail `001A731C..001A7330` restores the pointer with `lq`, loads the word
through it with `lw`, masks 0x100000, and branches on that result.

The local is now `u32 *addedStatus`, and the later condition reads
`*addedStatus`. Keeping the pointer, rather than caching the word when its
address is assigned, preserves changes made through opaque calls.

## Native predicate and provider tests

The new fixture extracts the actual pointer assignments and three complete
conditional expressions. It also runs the unchanged skill/status providers,
with wrappers recording their invocation counts. No target predicate is
reimplemented in the code under test.

At each of O0 and O2, with real i386 pointers and UB/bounds traps:

- 327,680 motion cases cover every signed byte, all five first-predicate gates,
  skill flag, later-action gate, equal/different unit kinds and five status masks
- The motion byte changes after address retention and again between the two
  checks. The expected predicates and short-circuit provider call counts are
  computed independently; the latter checks specifically require a fresh load
- 262,144 added-status cases exhaust the low halfword and the tested status bit
  at two genuine record addresses whose address bit 0x100000 differs. The word
  is mutated after its address is retained, so address tests and stale values
  cannot accidentally pass
- Six controls reject the two old address comparisons, unsigned motion,
  address-bit status testing, cached motion and cached status

Existing animation-call and hit-selection fixtures were updated only to bind
their same observations to the new real pointer name/type. Their expected
values, return identities, canaries and negative-control behavior remain.
All affected suites, including the existing motion/opening and approach/alias
families, pass: **38 tests, no skips** under the explicit QEMU adapter.
The new suite executes actual predicates and actual simple providers; it does
not execute either complete unfinished controller.

## Complete-owner checks

All eight baseline/final configurations compile: production, each guard alone,
and both guards together. The production object is byte-identical. All 70
unaffected functions in each single-target build and all 69 in the combined
build preserve their bytes and canonical references. All 148 allocated data
bytes and their references are identical in every configuration.

The production verifier retains **69 MATCH / 2 ASM**. Lint has zero errors
and the same 24 pre-existing advisories. The exact source/test fingerprints,
retail instruction assertions and measurements are in the retained verification
receipt; the audit reproduces complete per-function evidence.

| Target | Before / after bytes | Retail window | Before / after differing bytes |
| --- | ---: | ---: | ---: |
| 001a7720 | 17,392 / 17,400 | 17,536 | 12,810 / 12,850 |
| 001a59a0 | 7,600 / 7,604 | 7,536 | 5,610 / 5,678 |

These are normalized differing bytes, not words or accepted matches. The extra
loads are required behavior even though the positional byte scores increase.
Frames remain 0x680 and 0x400. No source shape was chosen to fill a size band.
Both production assembly fallbacks remain; no image build, gameplay run,
publication or remote CI result is claimed.

## Remaining work

Provider-sized stack output objects, the signed timing clamp in 59a0, other
oversized shift expressions and remaining old declarations are still unresolved.
The previous UID, hit-stride and animation-call repairs remain intact.

## Reproduction

After configuring existing licensed tools and hash-validated retail:

```
python tools/regenerate_asm.py
python docs/probe_archive/Large_Battle_hit_predicates_20261003/audit.py proof/predicate-replay
python docs/probe_archive/Large_Battle_hit_predicates_20261003/run_contracts.py --runner qemu-i386
python tools/verify.py src/promoted/code1_001a.c
python tools/decomp_lint.py src/promoted/code1_001a.c
```

Omit `--runner` on a machine that executes i386 directly. The runner rejects
runtime skips. The audit reuses the preceding complete-owner procedure with
this checkpoint's explicit base and adds the decisive predicate instructions,
new fixture fingerprints and independent allocated-data/reference comparison.
