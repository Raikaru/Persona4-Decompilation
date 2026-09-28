# Emotion Engine support for Hex-Rays

`ee_mac_lifter.cpp` adds PS2 Emotion Engine handling to IDA/Hex-Rays. It
improves the pseudocode used during source recovery; it does not change the
matching build or make the decompiler's inferred C authoritative.

| Instruction family | Handling |
| --- | --- |
| FPU accumulator (`adda.s`, `madd.s`, etc.) | Lifts accumulator chains; checked at retail `0x0048aff0`. |
| COP0 `bc0f` / `bc0t` | Fixes the stock R5900 decoder's bogus `mfthc1` decoding. |
| MMI `pcpyld` / `pcpyud` | Lifts the supported copies; checked at `func_003a29f0`. |
| Callee-saved `sq` / `lq` pairs | Marks matching stack saves and restores as prologue/epilogue instructions. |

The generic MMI-helper and extended instruction filters are not installed:
previous versions caused decompilation failures. Unsupported instructions
can still appear as `__asm` blocks.

## Building

Use an IDA SDK matching your installed IDA version. The recorded build used
IDA 9.4 and SDK tag `v9.4.0-sdk.1`. From the repository root:

```sh
git clone --depth 1 --branch v9.4.0-sdk.1 https://github.com/HexRaysSA/ida-sdk "$HOME/ida-sdk"
IDASDK="$HOME/ida-sdk/src" cmake -S tools/ida_plugin -B tools/ida_plugin/build \
    -G Ninja -Didasdk_DIR="$HOME/ida-sdk/src/cmake"
cmake --build tools/ida_plugin/build
```

The SDK root is `ida-sdk/src`, not the checkout root. The recorded Linux
build writes `ee_mac_lifter.so` under `$HOME/ida-sdk/src/bin/plugins/`.
Install it into your IDA `plugins/` directory only after the comparison below.

## Acceptance check

Compare the same database and affected function population with and without
the plugin. Require no increase in decompilation failures, not just fewer
assembly blocks in a few examples.

[`ee_lifter_acceptance.py`](ee_lifter_acceptance.py) scans MMI and `sq`/`lq`
functions through idalib. It currently hard-codes a local database path and
historical baseline. Set the database path in a local copy and run it using
your IDA-enabled Python environment:

```sh
/path/to/ida-python /path/to/local/ee_lifter_acceptance.py
```

Use separate copies of the same unmodified database for the two runs. Spill
marks are stored in the database's `$ ignore micro` netnode; removing the
plugin alone does not remove those marks. Compare the printed populations,
failure counts and assembly-block counts. The script's final `PASS` line
uses the old baseline and is not a substitute for that comparison.

Recorded results for `orig/SLUS_217.82`:

| Population | Without plugin | With plugin |
| --- | --- | --- |
| MMI, 153 functions | 153 OK, 0 failures | 153 OK, 0 failures |
| `sq`/`lq`, 5,100 functions | 5,100 OK, 0 failures, 5,099 with assembly blocks | 5,100 OK, 0 failures, 566 with assembly blocks |

These are historical measurements, not a guarantee for a new plugin or IDA
version.

## Why spill pairs are skipped rather than lifted

Hex-Rays analyzes the prologue before running microcode filters. Narrowing a
16-byte spill to an 8-byte microcode operation contradicts the frame model
it has already built. Two earlier filters tried that approach and produced
239 `MERR_INTERR` failures in a 1,725-function batch.

The current implementation recognizes stack-based `sq`/`lq` pairs for
callee-saved registers at the same offset and records `IM_PROLOG` /
`IM_EPILOG` marks. It does not lift those saves as C operations. This is
implemented in `mark_spills_in_func`, not an untried proposal.

The distinction matters: in an earlier 400-function sample with `sq`/`lq`
and no MMI, 260 had assembly blocks in the body rather than only in the
prologue or epilogue. Do not suppress a real body operation merely because
its opcode resembles a spill.

The rejected generic MMI tier constructed helper calls with `mcallinfo_t`.
It reduced a 153-function population from 153 successful decompilations to
82, with 71 failures. Spot checks had missed the regression.

## Companion VU0 disassembler

[`ida-emotionengine.py`](ida-emotionengine.py), from
[oct0xor/ida-emotionengine](https://github.com/oct0xor/ida-emotionengine),
decodes COP2/VU0 instructions. Copy it into the IDA `plugins/` directory
alongside the C++ plugin.

It turns words such as `cop2 0x1EB593C` into readable VU0 mnemonics; it does
not give Hex-Rays a VU0 execution model. Those instructions can therefore
remain assembly blocks in pseudocode. A recorded companion-plugin run had
142 MMI and 5,085 `sq`/`lq` functions, with no decompilation failures; its
population differs from the table above.
