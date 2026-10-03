# Guarded Title controller: seven helper-call contracts

Base: `6807e26bf4896fd803f01b9cb9182ea3df8d3a86`, the frozen layout checkpoint.
This removes two guard-local old-style shadows and repairs their seven calls.
**The NON_MATCHING guard and production assembly fallback remain. No new exact-C
credit, complete controller execution or gameplay correctness is claimed.**

## Bounded source repair

The existing, unchanged same-owner definitions supply the complete signatures:

- `func_00124f70`: `void(s32, s32, s32, s32, u8 *)`
- `func_00125e80`: `void(f32, f32, f32, s32, u8 *)`

The first helper's three calls now pass full `s32(255.0f * temp_f21)` brightness
at the dynamic site, integer modes, and explicit byte views of the shared scene
pointer. The genuine third integer remains 0 dynamically and 255 at both static
sites, even though the provider does not consume it. No argument was erased on
the basis of non-consumption.

The second helper's four calls use the actual floats-first signature, ordering
old arguments 2,3,4,0,1. All three existing pulse-X expressions are retained
verbatim, as is the fourth site's constant 200. Y remains 0 and Z remains 10.
The upstream sine conversions, ignored sine returns and pulse geometry remain
unresolved. Every provider and all other helpers are unchanged. In particular,
`func_00126090` and its extra zero arguments remain untouched; its unused
floating formals are not yet resolved.

An exact whole-source reconstruction accepts only these two declaration
removals and seven replacements. The tracked non-generated C/header census
finds the one definition and all 3/4 callers, with no extra authoritative use.
An authenticated direct-JAL census of every retail function window agrees; it
does not establish absence of indirect calls.

## Fresh evidence on this checkpoint

- Production whole-owner object is byte-identical to the base, SHA-256
  `59e652c8faa507dfb2feae59814a9668abfdbb377ba7eb62c3167eac9a7cc8c5`
- All 81 guarded siblings, their references, all 420 non-target allocated data
  bytes and section properties are exact
- Complete target accounting checks 4,140 retained instructions, every changed
  instruction, all 287 branch destinations and all sixteen switch entries and
  alias groups. Outside the repaired boundaries, register operands and stack
  homes are exact. No opcode/register masking hides a difference
- Every other reference event and addend is preserved. Exactly three runtime
  fptodp calls disappear, **15 → 12 on this layout base**. Nine other float
  promotions at the four repaired calls were folded constants, not nine runtime
  helpers
- All seven actual retail and rebuilt EE call writers execute 11,760 bounded
  cases; 64 mutations of real final-writer instructions are rejected
- Source-extracted native calls pass 560 defined expression cases at both O0
  and O2. At each optimization, 35 independent wrong-field controls and 15
  wrong-order/arity/pointer-type controls fail. Direct float-to-s8 conversion
  at phase .75 produces an actual sanitizer SIGILL, rather than merely a
  recorder mismatch; the corrected s32 conversion passes
- All **44 Title native tests** pass without skips: 39 prior and 5 new tests
- All ten prior machine scopes plus the latest layout machine scope pass on
  the final object. Their explicit historical offset/register mappings are
  composed with this checkpoint's exact instruction map
- Thirteen scoped production owners: **510 MATCH / 63 ASM**. Title retains
  **81 MATCH / 1 ASM**. Both repaired helper providers and excluded 00126090
  retain their matching bytes, including zero-only retail tails
- Lint: **0 errors / 32 existing advisories**

The guarded controller is **16,664 / 17,616 bytes**, with **3,933** position-based
relocation-masked differing words; its layout base was 16,712 bytes / 3,973 words.
These residual counts are not a whole-function semantic proof or an exact match.

## Defined domains and proof limits

Native probes use real 32-bit pointers into two distinct scene arrays and verify
unchanged storage snapshots. They execute the exact extracted call expressions,
with all local inputs initialized. Forty finite input tuples combine ten phases
(-.875 through .999, including .75 and signed zero) with four finite arithmetic
fixtures; indices 1..7 are supplied. The source's float operations use independent
binary32/truncation expectations. No arbitrary phase is asserted reachable
through the unresolved sine producer. Native helpers are typed observers, not
complete renderer providers.

Machine probes use seven indices, two distinct 32-bit scene identities, the same
ten phases, and six supplied X patterns including negative zero and fractional
values. They execute the actual final argument-writing instructions, checking
all five lanes at each call. The three pulse-X outputs are explicitly supplied
after authenticated ACC boundaries. Their producers are neither silently
replaced in native source nor claimed equivalent by machine arithmetic tests.

Retail is SHA-1 authenticated before reading. Provider entry readers, full-width
brightness conversion/OR uses, low-byte pulse brightness mask, scene+0x3c read,
coordinate use and depth forwards are authenticated; complete unchanged provider
objects still compare as matches. No complete provider is executed by the new
helper fixture. EE integer/FPR counters are independent, so the register-bank
contract alone does not uniquely recover original cross-bank textual ordering.
The existing matching definitions supply the coherent C parameter order.

Full repository verification and linked retail hashes passed on the layout
parent, recorded in its committed verification report. They are **inherited
base evidence, not freshly rerun full gates here**. This checkpoint freshly
runs scoped owner verification, whole-owner preservation and every Title
contract. Production raw-object identity establishes no new production-byte
change, but is not reported as a new full link run. No CI, push, upload,
publication, full repository native suite or gameplay run was performed.

Final owner source SHA-256:
`45e251ff335f1ed718c86f120f306abfad93083a61a40ab0e9920d42cc58287f`

## Replay and freeze

From the repository root, with licensed MWCC/retail inputs configured, Clang,
GNU ld and an existing i386 runner:

```sh
bash docs/probe_archive/Title_helper_call_contract_001265a0_20261003/replay.sh
```

The source-only relative-path manifest binds the source, tests, report, audit
scripts and compact receipts. Raw objects, full disassemblies and transient
logs stay in untracked `proof/`; none is committed. After committing,
`freeze.py` writes an external receipt containing the exact commit, tree and
owner source hash and verifies all committed manifest entries.
