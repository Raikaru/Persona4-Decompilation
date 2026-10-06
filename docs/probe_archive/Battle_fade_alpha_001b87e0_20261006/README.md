# Battle fade alpha: exact C recovery for 001b87e0

The installed `src/Battle/btlMain.c` recovery matches all 2944 bytes of
`func_001b87e0`. The complete owner contains 27 exact C functions. The 26
siblings retain their raw and resolved instruction bytes. All 212 code
references resolve, including the target's 48 references; the owner has no
data relocations. Its four-byte `.lit4` scalar at `0x007612E4` is exact.
Every allocated executable byte belongs to a verified function or zero
alignment gap. Prime reviewed the proposal and authorized installation;
complete-image integration and publication remain prime's responsibility.

## Installed source

`installed.json` binds the installed source to the reviewed proposal hash
`6e37817dada2aac6a544d8caa49a2b52c5e1af2cabe1a7ed123dad5522852754`.
The normal whole-owner verifier reports 27 MATCH / 0 ASM. Installed-source
lint reports zero errors and five existing advisories, and the whitespace
check passes. The saved full native proof was authenticated and reused;
its successful compilation was not repeated for this installation.

The original `receipt.json` preserves the proposal-stage evidence unchanged.
`installed.json` records the later installation and verification, and the
source is frozen for prime's next integration batch. No worker commit or
push was performed.

The functional source change is confined to the alpha interpolation in the
unit-color loop:

```c
secondW = target.w * ratio;
/* RGB assignments remain in their original order. */
tmp.w = firstW + secondW;
```

Previously `secondW` held `target.w`, and the multiplication appeared inside
the final sum. Both versions compute the same two weighted alpha inputs. All
four normalized color components are initialized, and the ratio is evaluated
only while `currentFrame < totalFrames`. The actual callback signature,
constructor's 0x5C work allocation, 0x60 stack frame, and loop behavior remain.
The proposal removes the guard/fallback and moves the canonical marker past
the private type/helper definitions to the actual function.

## Why the 13-word residual disappeared

Read-only GDB captures of the unchanged full owner reproduced the direct
native object byte for byte. The old source's entry PCode seeded an accumulator
with zero while forming the alpha result. Gain 255 and rounding bias 0.5 were
created later. Backend simplification removed that alpha seed's ADDa, but
common-subexpression reuse retained its zero for the subsequent byte
conversions. That zero was therefore hoisted before gain and bias, producing
the observed f4/f3/f2 constant rotation.

Forming both weighted alpha values before addition removes that early seed.
The resulting native multiply-accumulate chain and quantizer constants all
match retail. No register remapping, synthetic use, extra zero term, asm,
volatile, uninitialized value, new pragma, or compiler modification is used.
The previously measured `opt_loop_invariants on` remains scoped.

Four new source cases followed this capture evidence: normalized-alpha
products retained 32 differing words, its inline helper also retained 32,
the complete alpha expression retained 48, and the two explicitly weighted
alpha values reached zero. All emitted 2944 bytes.

## Proof and replay

`source.patch` is the complete reviewable delta. `receipt.json` binds source,
object, compiler, actual include/tool/config inputs, all function hashes,
resolved references, storage, and executable coverage. `native_proof.py`
retains the existing generic full-owner relocation proof, unchanged. The
`.lit4` base is established by nine agreeing target-local literal witnesses;
the native scalar payload and every resolved instruction are compared with
the authenticated retail ELF. No relocated bits are masked for acceptance.

With the configured compiler and retail ELF, from the repository root:

```powershell
build/venv/Scripts/python.exe docs/probe_archive/Battle_fade_alpha_001b87e0_20261006/replay.py --out build/fade-alpha-replay
```

The replay accepts the bound original owner or the installed proposal. It
constructs the proposal in memory and compiles only a temporary whole-owner
copy, writing outputs under `build`. Completed authenticated output can be
reused. `--reuse-object` permits checking an already compiled object against
the pinned hash without repeating compilation. Production and configuration
are never edited. Lint on the final proposal reports zero errors and five
advisories: three measured pragmas and two existing declaration advisories.
`git apply --check` passes for the bound original source. Complete-image
integration remains a separate prime check.

Private capture, candidate, and full detailed proof files are retained under
`build/finish-20261006/battle-worker1-resume`. This archive contains text and
hashes, with no proprietary compiler, executable, or object payloads.
