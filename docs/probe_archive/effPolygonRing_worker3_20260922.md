# effPolygonRing: three first-party fallbacks recovered

Owner: `src/promoted/effPolygonRing.c`. All three assigned functions are now
unguarded C with their inherited VU hardware operations. The native b210 owner
passes official verification with **16 MATCH**, up from 13 MATCH and 3 ASM.
The owner is released. No commit, push, shared-header/provider change, SDK or
third-party edit, or whole-repository build/test was performed.

The authoritative evidence is under
`build/first-party-next-20260922/polygon-ring/native-owner-v2/`:
`compile.json`, `proof.json`, the three `*-unmasked-proof.json` files,
`official.json`, `official.log`, and `released.json`. Each target's body and
canonical relocations also equal its separately compiled, officially matching
`<address>/clean-exact-candidate/owner.o`.

| Function | Reproduced baseline | Native result | Retail window | Zero suffix | Resolved relocations |
| --- | --- | --- | --- | --- | --- |
| `func_00498f10` | 34 differing words, 900/912 bytes | MATCH, 900 bytes | 912 bytes | 12 bytes | 33 |
| `func_00499730` | 83 differing words, 768/768 bytes | MATCH, 768 bytes | 768 bytes | 0 bytes | 31 |
| `func_00499e40` | 93 differing words, 868/864 bytes | MATCH, 864 bytes | 864 bytes | 0 bytes | 27 |

The last baseline reproduces 93 rather than the assignment's 92 when comparing
the complete native object and retail window. No mismatching candidate was
integrated.

## Source recovery

`00498f10`: ordinary signed division of the 16-bit vertex count by four reduced
the floor from 34 to 23 words. Splitting the initial work-pointer, parameter,
and geometry loads into retail order reduced it to four. Replacing the manually
expanded unsigned conversion with a direct `u32`-to-`f32` cast under scoped
`opt_propagation off` reached zero. Removed the obsolete signed-conversion
temporaries. No hardware instruction or operand changed in this function.

`00499730`: the inherited normalization block claimed a `$22` clobber despite
containing no GPR operation. Its later FPU-to-VU bridge hardcoded `$2`, destroying
the register needed for the live wrap stride. Removed the fictitious clobber
and described the bridge's existing scratch as an actual early-clobber output,
written by its existing `mfc1` before the existing `qmtc2` consumes it. This is
the real scalar bit transfer, not dummy C state. No instruction was added.
Keeping `stmp * 12` at the wrap-pointer use allowed the compiler to hoist it to
retail's location. The remaining 19 words were the source-cursor/counter pair;
reversing those declarations reached zero. Removed the obsolete stride local
and kept loop-invariant optimization within push/pop scope.

`00499e40`: store each trig return into the vector immediately, so the first
return no longer occupies a saved FP register across the second call. Express
the four VU storage slots as aligned quadwords and order the phase/step/zero
locals to match their real lifetimes. Defer the existing middle-vector store
until the independent outer-vector multiplication has finished. The progression
was 93 -> 22 -> 14 -> 6 -> 0 words, with the first change restoring the correct
864-byte body. All hardware instructions were inherited; the store's scheduling
and C operands now describe the retail lifetime.

The retired floor notes and all three `NON_MATCHING` / `INCLUDE_ASM` paths were
removed. New comments document the measured cause. Other source regions were
preserved.

## Behavior and proof review

The APIs, callers, parameter field offsets, signed time guards, unsigned loop
bounds, lock/unlock order, flag updates, vertex layout, and floating-point
arithmetic order are preserved. Signed division is defined for every possible
16-bit input. The wrap count is derived from a signed 16-bit value, so its
multiply by 12 cannot overflow `s32`. The bridge scratch is initialized by the
same transfer that consumes it. Every component of each quadword is written
before the VU loads it. Immediate trig stores target local storage inaccessible
to the second call. The deferred middle-vector store crosses operations on the
independent outer vector and retains its original value.

Each independent candidate preserved all 15 other function bodies and canonical
relocations, plus all allocated data. The final native object preserves all
13 neighboring exact functions and allocated data. All 91 target code
relocations were resolved without masking and compared to retail. The targets
reference zero owned data sections; unchanged owner data was checked separately.
`00498f10` has a proven all-zero 12-byte retail suffix. Both other functions fill
their entire retail windows. Native code and relocation records match the
independent exact candidates.

Targeted `decomp_lint.py --errors-only` reports zero findings for the owner, and
`git diff --check -- src/promoted/effPolygonRing.c` passes. No broad tests or
builds were run. Every new compile has a unique retained scratch destination;
historical objects were not overwritten.

## Recovery identities

- Final source SHA-256:
  `9e5dda3058de4196dcd7507fe42753c067fb6d6c4a10406f134087a6d1502a53`
- Final native object SHA-256:
  `0e5d15ce164bb7ae4c4e2a164c4ef1d02420c5b4b7449893a5a109b3dc778138`
- Inherited source SHA-256:
  `e4af5ca86fa2ce4a778827ba195fce13bd902f4c8da6f11bc94f02810265b313`
- Inherited object SHA-256:
  `c3ec7b930269e97d1332836abc01bf22cf5b73c7439c1f4d7ddebbe625e2b854`
- Compiler: `D:\mwcps2-3.0.1b210-060308\mwccps2.exe`, `-O2 -Iinclude`.
  Compiler SHA-256:
  `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7`.

## Discarded proof and exact tool failures

**Do not use `combined-final/` as C-compilation proof.** Its first harness call
reversed `_compile_in_context(candidate, logical_source, ...)`, compiling the
old authoritative fallback owner. The unchanged baseline object hash exposed
the mistake. `combined-final/INVALID_PROVENANCE.json` invalidates those compile,
proof, and official receipts. Nothing was overwritten to conceal it. The three
independent candidate proofs were unaffected. The corrected `native_owner.py`
uses explicit named arguments and proves every final C body identical to its
separately compiled winner. Only `native-owner-v2/` is the final owner proof.

The Python launcher printed a missing `pywin32_bootstrap` startup warning on
some wrapper invocations, and MWCC warned that `MWCIncludes` was unset; both
compilation and all recorded verification commands exited successfully.
One initial command and one prime-message attempt were blocked with the exact
OpenAI response that it could not determine the safety status of the request.
The initial compile was retried only because the blocked attempt had not run.

Prime-message attempts through `agents` returned
`AGENTS_BUSY: no agent family belongs to this conversation. Other primes and
their workers are isolated.` This is a communication-routing failure, not a
filesystem or compiler restriction. The owner and recovery note are available
for the prime to review and publish; publishing was not attempted here.
