# Model manager 00479100: native recovery checkpoint

Worker-2 released `src/Graphics/Model/mdlManager.c` at prime's request before
the upstream 7387466 merge. All compiler jobs had completed. No production
source, provider, vendor implementation, shared header, configuration, or build
tool was edited by this investigation. Existing working-tree changes remain.

Evidence is retained under
`build/continue-first-party-20260922/model-manager/`. Every compile used a
unique destination containing its complete source, native object, log and
receipt. Completed historical compiles were not overwritten or rerun.

## Fresh measured boundary

The configured mwcc b210 profile is `-O2 -Iinclude`. The fresh activated
`func_00479100` baseline has **30 fully resolved differing words**, 1908 bytes
within a 1920-byte retail window, and 21 alignment edits. The older 29-word
comment describes a different masked metric. All 125 sibling functions and
allocated data remain identical in this fresh baseline comparison.

The residual consists of three extra `mtc1 $zero`/`nop` pairs in color
quantization, an early color-address calculation, and a shared colored/uncolored
draw call where retail has two call sites. The six extra zero-load instructions
offset six instructions removed by sharing the draw path. Consequently, the
matching suffix after those differences does not establish a complete match.
No new model-manager `MATCH` or runtime semantic acceptance is claimed.

## Contract findings

The allocator `func_00460990` returns a zeroed, real 0x30-byte command through
`u8 *`. Queue insertion `func_00460ac0` takes `(u8 *, u8 *)`. Child visibility
`func_0047ae90` is defined as `(u8 *, u16)` in the first-party provider, while
this inherited owner uses a declaration with unspecified arguments.

The owner-local atomic callback `func_004772a0` returns the current object or
NULL and updates its caller-owned predicate. Its inherited signature is
`u32(void *, u32 *)`, cast to the pointer-returning `KClumpCallback`. The
canonical scratch form `void *(void *, void *)`, with a typed predicate access,
preserves that callback's compiled bytes.

The combined `active-game-contracts` probe corrects these interfaces and the
typed color setter declaration without changing providers. It measures 32
words at 1908/1920 bytes. The new target difference is the `u16` child-argument
mask. The global child-provider declaration also changes two already matched
siblings, `func_00479940` and `func_0047a320`; all other 123 siblings and data
remain identical. It is therefore not eligible for integration.

Using a true `u16 childIndex` restores the target's call-argument move but adds
a halfword mask before increment: 49 words, 1912/1920 bytes. The same two
matched siblings still differ. Future canonicalization must preserve their
actual narrow counter lifetimes and native output. The upstream ABI changes
must be read before reusing any of these pre-merge assumptions.

External callers also have inherited signed-address versus pointer queue
declarations in `effModel`, `code1_001d`, and `code1_004a`. No outside-owner
changes were requested or made because no exact target candidate was found.

## Bounded probes and results

All results below are fully relocated word differences, with immutable detailed
alignment and sibling receipts in the named directories.

| Probe | Words | Bytes | Result |
| --- | ---: | ---: | --- |
| `00479100-active-baseline` | 30 | 1908 | 125 siblings/data unchanged |
| `color-register-lifetimes` | 30 | 1908 | Same residual |
| `single-quantized-channel` | 30 | 1908 | Same residual |
| `quantizer-destination-result` | 30 | 1908 | Same residual |
| `quantizer-value-result` | 193 | 1916 | Adds stack result copy |
| `quantized-domain-u8` | 238 | 2148 | Expands unsigned conversion |
| `quantized-domain-u32` | 233 | 2100 | Expands unsigned conversion |
| `grouped-real-color-lifetime` | 30 | 1908 | Same residual |
| `real-color-output-normalizer` | 30 | 1908 | Same residual |
| `local-optimization-color-block` | 431 | 1852 | O1/CSE-on loses required shape |
| `local-optimization-no-cse` | 120 | 1908 | O1/CSE-off changes allocation |
| `local-optimization-distinct-draw` | 427 | 1876 | Does not close both regions |
| `quantized-color-initializer` | 207 | 1952 | Adds aggregate initialization work |
| `quantization-local-cse` | 30 | 1908 | In-function on/off bracket is ineffective |
| `quantization-through-return-cse` | 431 | 1852 | Changes the whole function profile |

The noncanonical operation probes preserve all 125 siblings and allocated data.
They isolate the color/branch mechanism but are not candidates for final ABI
acceptance. No explicit dummy zero, volatile ordinary memory, padding operation,
incompatible substitute provider, or arithmetic assembly was introduced.

The final pragma measurements do not support treating an in-function CSE
bracket as a local quantizer profile. The compiler's native `-help` output was
retained separately; its O1 local/CSE controls did not preserve the required
normalization and branch sequence in the measured variants.

## Recovery hashes

| Artifact | SHA256 |
| --- | --- |
| Inherited owner source before merge | `d2959b8c2d3b5be12c6a4ea1890ba56b95fc31f6809f6d372602ec1ae0863fad` |
| Native guarded-owner object | `4dc872424e4192524a8d74c36f9cb0b2e7f339ad998a6808de09025f0bd3ccc1` |
| Activated baseline source | `8897318ffd36dca07e3d1ff8cd3d6e14cfa50134238f4109da389b60585834df` |
| Activated baseline object | `2ac06e85dbf395ffd35596facac0c1ec715975f6c8c70aeeded1eeb54ee6c2b0` |
| Canonical contract probe source | `9fe6ae4cfb542af701c619e4e34d0ffba2aa5cd4d04ccf46614e951988f3e1e2` |
| Canonical contract probe object | `efc248f8d82d953a1807225705f0cf56a3144bace22554c3a5eec75758e6d2b3` |
| Native b210 compiler | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

After the merge, establish a new source/profile baseline in a new directory;
the existing `before.c`, input identity and receipts belong to the source hash
above. `00476e90` was read as a possible related color target but was not newly
compiled. `mdlEffect` belongs to another worker and was not touched.
