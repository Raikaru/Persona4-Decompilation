# Result-screen particle update and drawing

Owner: `src/Battle/btlResultSimple.c`, `func_0021fa40`.
Native compiler: MWCCPS2 b210, `-O2 -Iinclude`.

The recovered C emits 1,108 bytes for the 1,120-byte retail window. All
seventeen relocations resolve to their retail destinations; the final twelve
bytes are zero alignment. The twelve other owner functions retain their
instruction bytes and relocation meanings. Allocated owner data is unchanged.

The function updates and draws five sprites. Their animation states are
32-byte records at work offset `0x4C0`; their seven-field styles are 28-byte
records at `D_00629560`. These layouts agree with the initializer in
`func_0021ef70`. Each style selects a sprite, a duration interval, an amplitude
interval and one of two motion paths.

## Source reconstruction

The previous guarded draft had several independent differences. The new C
captures the sprite before the trigonometric callback, copies prior positions
as floats, uses unsigned remainder for random durations, and retains the
native association of the coordinate sums and multiply-accumulate expressions.
The phase at GP offset `-0x7C28` is a scalar `iGpffff83d8`; representing it as
the second element of an unrelated array produced an absolute-address load.

The timer update uses the value of its actual halfword compound assignment.
Consequently, a timer of 65535 wraps to zero before the duration comparison.
Reading the field again or narrowing an independent sum gives a different
instruction order. A small arithmetic helper keeps the range-then-sample
order of the amplitude multiplication. The opacity, loop ordinal and sprite
declaration lifetimes reproduce the final saved-register allocation.

The sprite provider is the existing `void (void *, f32, f32, u8, u8, u8, u8)`
interface. The random provider returns `u32`; the blend-state helpers take no
arguments and return `void`. No provider contract, callback effect or frame
update was invented to influence code generation.

## Evidence

The discovery and final source, compiler receipts, resolved instruction proofs,
retail style-record inspection and per-sibling checks are retained under
`build/finish-first-party-20260922/continue-31-result/`.
`typed-timer-complete` is the initial exact candidate. `reviewed-final` adds the
source documentation and explicit blend-helper declarations. The `integration`
directory records installed-source verification. Its initial full build exposed
the missing linker definition for `iGpffff83d8`: the verifier could resolve that
GP name, but the linker rejected the entire owner. The curated and generated
symbol maps now both place it at `0x007614C8`, derived from the retail load and
the configured GP. The `final` directory records the corrected full build and
publication, including preservation of all previously linked first-party C.
