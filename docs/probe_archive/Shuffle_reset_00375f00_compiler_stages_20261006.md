# Shuffle reset: paired object contracts and native stage observations

No source is promoted. The complete-owner `func_00375f00` still has **two
fully resolved differing words**, at offsets `0x48` and `0x70`, and emits
156 bytes in a 160-byte retail window. The tail is four zero bytes.

The investigation follows the source and retail evidence retained in
`MATCH_NEXT_0ec5899_worker4.md` rather than repeating its pointer-spelling and
generic compiler-option sweeps. Work is isolated under
`build/finish-20261006/fcl-worker5/reset-contracts/`.

## Provider and caller contracts

The sole active caller is the state update in
`src/Battle/btlShuffleDraw.c:514`. It invokes the reset and then clears its
own flag. The reset invokes `00370410`, writes motion state 5, invokes
`00370a80`, and writes rotation state 3. Both actual initializer definitions
in `src/promoted/code1_0037.c` consume one object pointer and return void.
The motion object ends at `+0x60`; rotation ends at `+0x6C`. The existing
record's corresponding member extents agree.

Two coherent caller/provider variants were measured: typed motion/rotation
parameters with byte views in the actual definitions, then a typed root
context parameter in the reset and its caller. Both preserve all 14 provider
functions and owned data, all 51 caller-owner siblings, all four caller data
sections, and both resolved target call references. Both retain the same
two-word residual. No provider or caller declaration was changed in isolation,
and none of these scratch edits was installed.

## Where the address differences arise

The configured MWCCPS2 b210 binary was observed using the existing
`mwccps2-debugger` schema-1 profile and GDB. No compiler memory or emitted
object was modified. The complete direct and debug objects are identical:

```text
60d8da22940a6a9daeb70b8659f3fe2929e4e9795c4a2598f4edda11bf7745e7
```

The target's code and canonical references also equal the separately
compiled complete owner. All 222 captured stages completed without input
drift or instrumentation error. At reset stage `000109-codegen_entry`, both
store addresses are already independent `addu` expressions using virtual
parent `r32` and byte offset `r34`. The expressions remain at stage
`000110-before_register_allocation`. Stage `000112-after_register_allocation`
shows the same additions, with the expected parent `$s1`, offset `$s0`, and
results `$v1`/`$a0`. Retail instead copies the cached `$s2` base.

This establishes that the current candidate's repeated address additions
precede allocation. A physical-register permutation cannot replace those
additions with copies. It does not establish the transient graph, source
form or optimizer state of the historical retail compiler run.

The generic colorgraph replay has a bounded limitation on this capture:
physical-register aliases `r33`, `r42` and `r46` retain model color `-1`,
where their recorded canonical targets are physical registers 5, 4 and 4.
The other assignments agree, but `match_observed` is false. The record keeps
that failure explicitly; the stage conclusion relies on the captured PCode
and the direct/debug object equality, not on an asserted successful replay.

## Bounded follow-up

The complete-reset helper preserves the actual two inputs, initializer calls
and state stores. Compiling that helper at O2 inside an O1 wrapper retains
two words / 156 bytes; the inverse boundary gives 36 words / 128 bytes. A
complete typed-record helper gives 47 words / 216 bytes and exceeds the
window. These unsuccessful measurements and their sources remain in
`phase-boundary-results.json` and the per-probe directories.

`receipt.json`, `trace-evidence.json`, `colorgraph-replay.json` and the
capture receipt retain source, compiler, profile, object and PCode hashes.
The captured reset experiment used this unmodified owner baseline:

```text
btlShuffleDraw.c cc2577d8b2e62e6d9480d14873037479c05af9f4c09fb85f8858e41acdb3faef
```

The separate `Shuffle_trail_003768e0_20261006` guarded reconstruction for
the other remaining function was subsequently approved and installed by
this lane. Its whole-owner proof preserves this reset's two-word residual.
The reset's source is unchanged; these captures retain their original source
hash and must not be replayed against a later owner without a fresh baseline.
