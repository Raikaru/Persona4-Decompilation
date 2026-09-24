# File-browser navigation callback 00467bd0

`src/promoted/code1_0046.c` recovers the directory-browser task callback as
ordinary C. MWCCPS2 b210 with the configured `-O2 -Iinclude` flags emits
1,252 bytes in its 1,264-byte retail window. All twenty relocations resolve
exactly, and the final twelve retail bytes are zero alignment. All 57 other
functions and the owner's allocated data retain their original native bytes
and canonical relocations.

## Complete objects and provider contracts

The callback owns a `0x81094`-byte work object, exactly the allocation in
`src/promoted/sdkFiler.c::func_00468170`. Its first 256 bytes hold the current
directory string, followed by 2,000 existing `FilerEntry` records of 264 bytes.
The state, row, page and count halfwords therefore begin at `0x80F80`.
The acceptance word is at `0x80F88`, the 256-byte result string at `0x80F90`,
and the child chooser task pointer at `0x81090`. The former guarded source
mistook large displacements within this object for an unrelated global base.

The temporary navigation record covers the complete 44 bytes cleared by
`func_00453670` and accessed by the other list-state providers. Its row and
page fields are 32-bit values at offsets `0x24` and `0x28`. The provider's
arguments are also 32-bit, matching `src/promoted/sdkListState.c`; the old
local declaration incorrectly narrowed three arguments to halfwords.

`func_00468940` creates the chooser as a child of the incoming browser task.
Its first argument is that task, as confirmed by its call to `func_00451fc0`.
The second argument is the complete packed two-float position `(48, 248)`.
The returned task pointer is stored in the work object, and `func_004688d0`
writes the chooser result into a complete 256-byte local string buffer.

The current path follows the original NUL-terminated, 256-byte directory
string contract. The parent-directory scan retains retail's bounded search
and its assigned length on finding the terminator. It removes the final
component without removing a drive-root slash after `':'`.

## What closed the match

The parent-directory branch is shared by the `".."` directory entry and the
parent-navigation button. Keeping that branch at its first use reproduces
retail's branch order. The state machine retains the original five cases,
including the chooser-wait case, and reloads selected entry fields across
calls instead of caching them through callbacks.

The remaining mismatch was the backward path walk. The condition now retains
its validated signed index in a real local before the character lookup:
`while ((checked = cursor) >= 2)`. The narrow cursor remains the position used
to terminate the path. The unsigned checked-index control is nonmatching;
the signed form recovers the retail comparison and address lifetimes.

Function-scoped `opt_loop_invariants on` is measured and necessary: removing
it from the reviewed source emits 1,256 bytes, with 24 aligned instruction
edits. The setting shares the checked forward-scan index and hoists the slash
constant. The complete layout and the declaration lifetime of the saved
length also restore the retail `0x170`-byte frame and saved-register roles.

The button halfword uses the same array declaration as the list-state
provider. The three small strings have their actual sizes: `".."` (3),
`"."` (2), and `"%s/%s"` (6). Their native references resolve to `0x00764110`,
`0x00764114`, and `0x00764118`; the terminators and surrounding retail bytes
were checked directly.

## Evidence

The exact resolved instruction SHA-256 is
`e636d4fe0d8fff3d892e83775a928421798e18fe5acdb0053eb96becc04c3826`.
Source, compiler receipts, native objects, all relocation proofs, sibling
comparisons and control measurements are under
`build/finish-first-party-20260922/continue-45-filer/`.
`guard-signed-index` is the discovery and `review-final` is the publication
source. The old floor comments are preserved separately in that directory.
Installation and publication checks are retained under `continue-45-integration/`.
