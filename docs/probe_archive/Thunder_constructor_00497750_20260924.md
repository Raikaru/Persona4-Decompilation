# Paired thunder color construction — 00497750

The constructor makes the requested segment count odd, allocates the geometry
copies, and writes rows of five packed colors. The fade changes at sample zero
and each odd sample; the following even sample retains the previous fade. The
old guarded draft recalculated every sample and omitted the final minus one in
the falling fade numerator.

Configured MWCCPS2 b210, `-O2 -Iinclude`, emits 1,280 bytes in the 1,280-byte retail
window. All eleven relocations resolve exactly and no allocated data is added.
The two four-byte color snapshots reproduce the two retail groups of four byte
loads followed by four byte stores, including alpha. The scoped loop-invariant
and lifetime settings preserve the initial fade and its use across allocations.
The inner pointer/index declarations belong to their actual loop scope, and the
destination pointer advances before the sample index as in retail.

The geometry builder consumes the low unsigned halfword of its copy count and
an index-data pointer. Its definition and the thunder and ring callers now agree
on `u8 *(u16, void *, s32, s32)`. Native comparison confirms every function and
allocated-data section in the geometry provider and ring owner is unchanged.
A control using the old word-only provider declaration made the recovered
thunder function 1,288 bytes and was rejected. The accepted change coordinates
the provider definition with its callers rather than using a caller-only type.

The retained worker source contained unrelated changes to inactive sibling
drafts. Integration extracts only this constructor into the current owner,
preserving those other drafts, all fifteen sibling function bodies, and data.
Unused outer declarations are removed and the existing complete `Color4` type
is reused. The final source is separately compiled and proved after review.

Discovery and the initial native/semantic evidence are in
`build/finish-first-party-20260922/continue-26-thunder/`.
The current-owner proofs, coordinated provider/caller comparisons, rejected
word-interface control, and final installation/build records are in
`build/finish-first-party-20260922/continue-28-thunder/`.
