# Persona byte-alpha family and task renderer

The coherent byte-alpha interface closes all twelve remaining instruction
differences in `shdPersona.c::func_00119e10`: 3,208 executable bytes in the
3,216-byte retail window, 58 resolved references and eight zero tail bytes.
The two affected owners contain 118 existing C matches; every one retains
its instruction bytes, size and canonical relocations.

## What changed

The ten drawing entrypoints from `00115c40` through `00116d40` consistently
take byte opacity in their declarations and definitions. The Camp consumer's
declaration agrees. No local shadow declaration substitutes a different ABI.

Three source boundaries preserve the previously matching family:

- `001162f0` retains its byte parameter across the diagnostic call and only
  promotes it when constructing the inverse opacity. Prematurely assigning
  it to a word local inserts an extra entry mask.
- `00116d40` converts its byte parameter directly with `(f32)alpha` for the
  pulse. The old `(f32)(u32)alpha` spelling asks for an intervening promotion
  and produces five different register words after narrowing the parameter.
- `00137890` passes its existing `spriteOpacity` byte snapshot to `00115c40`,
  rather than widening and narrowing the equal word local again. Its full
  1,340-byte instruction image remains unchanged.

The task renderer's typed records, callback-visible reloads, counter behavior
and complete coordinate snapshots come from the independently tested rank36
reconstruction. No dummy operation, synthetic branch, extra load, padding,
volatile access or computation assembly was added.

## Why the meter's raw incoming register is a byte

The old meter body really converts the raw saved `$s4` value. That observation
does not establish a general word-valued external input contract. The actual
retail call graph supplies a byte before that register is saved:

- At `0x0011a8b0`, the task renderer calls the meter after an unsigned-byte
  load into `$a1` from channel opacity at work offset `0x39a`.
- At `0x00116154`, the panel renderer passes `$s2`, which captured its incoming
  `$a1` at `0x00115eb4`. Its only caller is the `00115c40` dispatcher, which
  forwards `$a1` unchanged.
- The dispatcher's only caller is `00137890`. It loads both opacity factors
  from byte fields, computes the product, and masks the conversion result.
  `0x00137a34` executes `andi $s3,$v1,0xff`; `$s3` is not redefined before
  `0x00137d7c` forwards it in `$a1`.

The full retail direct-control-flow scan finds sixteen calls to the family,
all in these four routines. There are no absolute family function-address
words in the loadable image. The reviewed nearby address-materialization
scan also finds none. These checks support the existing shipped call graph;
they do not invent a public extension accepting arbitrary word opacities.

The fixtures explicitly demonstrate the distinction: at half pulse the old
wide provider accepts 257 and produces 128, while byte 1 produces zero.
That out-of-domain equivalence is not claimed. All actual producer paths
establish 0..255 before reaching the meter.

## Independent source and execution checks

The baseline reproduces the historical rejected narrow-family result:
target exact, but `001162f0` differs by one word, `00116d40` by five, and
`00137890` by three. The three fixes above close those exact regressions.

Whole-owner object auditing confirms unchanged production bodies, all
allocated sections and their canonical relocations across both owners.
The extracted target preserves all 101 siblings, has unchanged allocated
non-text data, and equals the complete retail window after resolving all
58 references. Independent review reproduced the result.

Native actual-source fixtures use real 32-bit pointers and Clang O0/O2 with
undefined/bounds traps, FP contraction disabled, and an existing i386 runner:

- 2,052 task-renderer cases cover visibility combinations, callback mutation,
  entry gates, counter behavior and an independently checked meter trace
- 129,536 meter/border cases compare actual byte providers against frozen
  pre-closure wide providers: all 256 byte opacities, fill/bonus extremes,
  signed phase boundaries, missing-sprite diagnostics and controlled cosine
  outputs. Integer pulse expectations are checked separately
- The Camp fixture executes the actual producer across all 65,536 byte-factor
  pairs, both with and without callback mutation, checking its captured byte
  opacity against the frozen actual caller
- Original target/provider controls and new pulse, sign, width, border-mask,
  stale-opacity and scaling controls must fail

The cosine and lower drawing operations are bounded fixture providers.
These tests establish finite C control/data contracts, not PS2 floating-point
exceptions, rendering output or gameplay.

An inherited `001171c0` declaration mismatch remains outside this change.
Independent coherent-wide and coherent-byte experiments leave the new task
renderer exact but regress a pre-existing matched family member. No new
mismatch was introduced, and the new target does not depend on that mismatch
for its exact code. Existing source-honesty warnings remain documented debt.

## Reproduction

With the configured authorized toolchain:

```sh
python tools/verify.py src/promoted/shdPersona.c src/Camp/cmpPersona.c
python tools/run_persona_alpha_contracts.py --runner /path/to/existing/qemu-i386
python tools/decomp_lint.py src/promoted/shdPersona.c src/Camp/cmpPersona.c
python tools/build.py --progress-report build/persona-alpha-linked.json
```

Omit `--runner` on a host passing the existing native32 preflight. No compiler
defaults, symbol aliases, target layout or link-selection configuration changes
are part of this recovery. The full-image acceptance receipt is recorded
separately from the focused object/native evidence.

## Main-tree acceptance

The focused projection is integrated on main parent
`01480d7430343d1ce72abc20e336ed3bf7eedb98`. Both the pristine parent and
the promoted tree pass the complete GNU-linked build with 604 C owners and
54 Sony SDK owners. All 8,586 linked function windows and all 658 total
owners are preserved; none is removed or silently replaced by a fallback.

The link map supplies `.text.func_00119e10` from `promoted_shdPersona.c.o`
at `0x00119e10`, with 3,208 bytes followed by eight fill bytes. The owner
now contains no `INCLUDE_ASM` fallback. Both identities are exact:

- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Complete ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`

The final focused verifier reports 119/119 MATCH. The ordinary repository
suite runs 864 tests with 31 reported skips and no failures/errors; the eight
focused contract methods all run successfully with the explicit i386 runner.
Policy lint reports zero errors and 26 inherited warnings across the two
owners. No compiler or linker setting, safeguard, or unrelated guard changes.
