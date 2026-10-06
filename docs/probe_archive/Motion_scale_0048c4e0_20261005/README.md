# Motion emitter 0048c4e0 — exact C recovery

`func_0048c4e0` is now ordinary C for its emission, random sampling, state
updates and integration, with VU instructions for the actual hardware vector
operations. The production marker has no `NONMATCHING` guard or assembly
fallback. The complete current owner verifies as **65 MATCH / 8 ASM**.

The native target is **2,164 bytes in its 2,176-byte retail window**. All twelve
suffix bytes are zero alignment. The proof resolves every instruction reference
before comparing bytes: zero target differences, all 72 siblings exact, all
581 owner code relocations resolved, and no allocated non-code sections.
`receipt.json` records the actual source/object hashes and each function's
resolved hash. The included replay uses the existing whole-owner verifier.

## Why the aligned three-component object is faithful

The scale has three initialized float members and an explicit 16-byte alignment
attribute, with a compile-time `sizeof == 16` check. Both `LQC2` operands name
the **complete object representation through an unsigned-character array**.
The fourth word is natural alignment padding, not an uninitialized float
member. The 16-byte extent is required by the hardware load; no extra dummy
field or new W initializer has been introduced to influence allocation.

The implementation retains the real XYZW multiply, store and subsequent
hardware effects. It does not assume the padding is globally unobservable.
Every actual XYZ member is produced before both uses. The underlying emitter
has a 28-byte state record, 32-byte particle/history records and a 224-byte
parameter allocation; the recovered accesses fit those observed allocations.
The recovered type name describes this contract and is not claimed to be an
original SDK typedef.

The read-only semantic audit covered 26 current source inputs and 46 retail
windows, including child dispatch and downstream vector consumers. The Sony
*VU User's Manual*, version 6.0, printed page 236 specifies the 16-byte LQC2
alignment requirement; pages 26 and 39–42 describe the vector number format and
flags. In particular, host IEEE NaN reasoning cannot be substituted for VU
exponent-255 behavior. The primary manual is at
`https://docs.alexrp.com/mips/ee_vu.pdf`. WG14 DR451 discusses the distinction
between indeterminate scalar values and representation padding; it is not by
itself a specification of MWCC inline assembly:
`https://www.open-std.org/jtc1/sc22/wg14/www/docs/dr_451.htm`.

The semantic review found no ordinary C computation over an uninitialized
scalar, invented callback contract, or dummy storage. Native byte identity and
legal object representation are separate checks. No PS2 gameplay run, padding
poison experiment or universal proof that the padding cannot be observed is
claimed.

## Retained evidence and replay

The installed-owner measurement is retained locally in
`build/resume-publication/cos20999-motion-installed/`. The independent current
candidate is in `build/resume-cos20999/motion-scale-current/`; its source differs
from the installation only in status/provenance comments. The detailed semantic
read set and instruction witnesses are in
`build/resume-cos20999/motion-scale-audit/`.

Run from the repository root with the configured MWCCPS2 and retail ELF:

```sh
python docs/probe_archive/Motion_scale_0048c4e0_20261005/replay.py --hashes-only
python docs/probe_archive/Motion_scale_0048c4e0_20261005/replay.py --output build/motion-scale-replay
```

The first command only checks recorded sources and proof metadata. The second
requires a new output directory, compiles the actual current owner and checks
all code and owned data with fully resolved relocations. It stops on source
drift or non-exact bytes. No retail executable, object or disassembly payload is
included in this archive.
