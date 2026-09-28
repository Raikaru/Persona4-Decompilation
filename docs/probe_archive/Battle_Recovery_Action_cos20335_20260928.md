# Battle recovery action 001a31e0

`src/promoted/code1_001a.c` now supplies `001a31e0` as C. All 1,632 executable
bytes match its complete retail window under the configured MWCCPS2 b210 `-O2`
build. The change adds one first-party match relative to `4c01ee4`.

The action reads its unit through offset `0x30` and retains the complete 32-bit
status word. Its camera and animation packets have distinct lifetimes: the
animation records the camera packet's queue-assigned UID, and the following
voice, result, recovery and target packets record the animation packet's UID.
Blocked recovery, diagnostic results, status selection, delayed state changes
and ordinary next-state selection retain their retail branch and queue order.

The rotation workspace contains all three floats written by the actual helper.
The result workspace contains all eight words initialized by its actual helper.
Diagnostic values remain signed words. The status selector `001eb4a0` in
`src/promoted/code1_001e.c` accepts the actual `u32` status word supplied by its
sole source caller and selects from its low 20 bits. Its declaration and
definition change together, while its complete native object remains unchanged.
The action uses actual packet and state-setter interfaces; five inline adapters
retain existing byte-view callers without adding calls or storage.

The complete public verifier reports 9,519 MATCH and 3,583 ASM across all 13,102
canonical windows. First-party attribution is 6,699 MATCH and 162 ASM across
6,861 windows. Both affected owners were freshly compiled from publication
sources. Their objects equal the sealed full proofs: all 191 function windows,
2,594 text relocations, 36 data relocations and 160 allocated data bytes are
accounted for. All 190 previous neighbors preserve their raw instructions,
canonical relocations, resolved bytes and destinations. Compiler-local label
renumbering preserves the corresponding symbol identities and addresses.

Retained 32-bit behavioral fixtures exercise the final action and selected real
helpers in 8,192 cases at each of `-O0` and `-O2`. They check branch coverage,
signed diagnostic boundaries, upper status bits, complete buffers, ordered
callbacks and 64-bit queue dependencies. Wrong-dependency, narrowed-diagnostic
and lost-status-bit controls fail as intended. Packet, query, reset and selector
services are controlled fixture boundaries; these checks do not execute the
game. The native fixtures and their 27 provider-signature checks were
authenticated with the final sources. Scoped lint has no errors or added
warnings.

The final link retains all 8,376 previous physical source memberships and
supplies the new body from its recorded C owner. The rebuilt load image has
SHA-1 `3d1d3d2b9d6ccb60836db239ab49674223025a78`; the rebuilt retail executable
has SHA-1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c`. Both equal the configured
retail hashes.

Publication evidence is retained under `build/batches/action31e0-v1`,
`build/publication-verification/action31e0-v1` and
`build/publication-gates/action31e0-*`. The source preimages, reviewed patch,
native objects, complete resolved proofs and behavioral records are retained in
the sibling `build/cos20335-publish-20260928/battle-action-resume/sealed31e0`
package and its referenced original `battle-clone-integration/remaining-action`
lane. Unfinished `001a3840` and other action candidates are excluded.
