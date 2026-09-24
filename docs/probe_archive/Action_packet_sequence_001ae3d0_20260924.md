# Action packet sequence 001ae3d0

The recovered callback in `src/promoted/code1_001a.c` emits all 1,072 bytes
of its retail window with zero differing words. Every code relocation is
resolved against the retail image. All 70 other functions and all three
existing read-only data sections are unchanged.

## Search and iteration

The callback searches four action pointers at battle-context offset `0xC48`;
their halfword count follows at `0xC58`. The search snapshots that count and
uses an unsigned halfword index with a signed promoted comparison. The later
animation loop also uses a halfword index but reloads the context and count
after its packet calls. Each index retains its separate promotion at the test
and indexed load, reproducing both retail loops without a control-flow shim.

The selected table entry is read into a real local before comparison with the
preferred action. That value boundary fixes the branch operand order. A small
inline `actionTargetAt(table, index)` lookup expresses the same table access
for the random fallback. Its parameter order preserves the context reload
before scaling the selected index. Reversing the helper parameters changes
the instructions; no object bytes or relocations are patched.

## Packet storage and providers

The cut-in packet constructor copies ten bytes. The callback therefore owns
a complete ten-byte payload containing the mode, unit ID and six opaque
bytes. Mode 1 consumes only the first two halfwords, as established by
`func_001fa490`; the unused representation is not given invented stores.

The new callback uses the existing typed animation, look-at and camera
packet providers. Their public names are resolved from their source markers,
official native MATCH receipts and actual section-backed definitions in the
previously verified linked image. Their providers are unchanged.

`func_001d15a0` takes no arguments and returns a signed halfword. Its caller
declaration and the related calls now agree with that definition; all native
instructions are preserved. The cut-in constructor in `code1_001f.c` now
accepts the pointer it actually copies. The formation constructors
`func_001d3900` and `func_001d3d00` explicitly return their allocated packets,
which the caller consumes. These repairs preserve every function and all
allocated data in both provider files. Existing unit-pointer callers and the
camera caller in `code1_001a.c` retain their native instructions with the
coherent declarations.

## Evidence

Native sources, compiler receipts, objects, relocation proofs and sibling
comparisons are retained under
`build/finish-first-party-20260922/continue-51-actions/`.
The accepted files are `review-callback-v2`, `cutin-provider` and
`review-formation`. `lookup-base-first` is the original exact discovery.
Installed verification, whole-image validation and publication receipts are
recorded separately under `continue-51-integration`.

The callback's fully resolved SHA-256 is
`bcaab8cbf7595a744eb62f5f310ba6974014dad2eacdcca5bb1c1ef18b0daee9`.
