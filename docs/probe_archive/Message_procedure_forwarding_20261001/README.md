# Explicit message procedure-handle forwarding

Base: `55484acc8a525b07c7faf0e4ebcfec540baea36e`.
This is a narrow current-main projection of independently reviewed contract
repairs. It does not import the archived guarded message-window recovery.

## Changed contract

The actual work getter accepts a signed message handle and obtains procedure
work at message+0x114. Main had 21 omitted arguments to this getter: the first
lookup in all 17 phase dispatchers, two argument accessors, and the userdata
getter/setter. The matched first-word writer also omitted the nested userdata
getter's handle. All 22 forwarding sites now supply the actual handle.

A dedicated `message_procedure_api.h` declares only this work-address getter,
the userdata getter/setter, and the optional userdata first-word writer. The
existing work-address return remains a signed word. Userdata is an opaque
pointer at work+0x18; its getter retains the original uppercase exported name
`func_0027BE60`. The setter's former unused 64-bit parameter is now the actual
signed handle, and getter/setter use consistent pointer values.

Only six source owners include this header. The matched Window controller's
userdata calls explicitly convert its existing pointer-shaped handle to the
signed handle accepted by these APIs. Its broader callback signature and
flags/font declarations remain outside this patch. The first-word writer
uses the signed type already declared by its actual caller.

The 17 dispatchers retain both work lookups, all phase stores, null-callback
behavior and callback returns. The argument accessors retain their existing
address arithmetic and diagnostic. No new branch, padding, pragma, volatile
access, register steering or computation assembly is introduced.

## Scope and domains

- Valid handles select present manager entries 0..63.
- Argument tests use indices 0..3. The retail diagnostic does not make invalid
  indices safe; no clamp or arbitrary-index equivalence claim is added.
- The new tests execute actual providers, dispatchers, argument accessors,
  userdata getter/setter and the first-word helper. They do not execute the
  entire matched Window controller or substitute an invented flags-provider
  ABI to hide its unrelated declaration debt.
- All four guarded Window bodies, including rank5 `0027f6f0`, are text-identical
  to main. Their source hashes are recorded in the preservation receipt.
- The zero-choice division/conversion gate in guarded phases 9/12 remains a
  separate unresolved controller/data-domain issue.

## Native proof

The fixture extracts the actual production bodies. Only the manager getter's
name is changed for a call-count/handle-check wrapper; its body is untouched.
Objects use real 32-bit pointers and independently asserted retail offsets,
with full byte comparisons including neighboring fields and canaries.

At both O0 and O2, **12,800 scenarios** pass:

- 10,880 dispatcher scenarios: every handle, all 17 dispatchers, null/present
  callback, five full-word return values, exact phases and both getter calls
- 1,280 argument scenarios: every handle, all four argument slots and five
  signed values, preserving all other object bytes
- 640 userdata/helper scenarios: every handle, null/present pointer, signed
  word values, full pointer preservation, cross-handle isolation and unchanged
  neighboring words

Every repaired forwarding site has independent wrong-handle runtime and
omitted-handle compile controls: **22 of each at both optimization levels**.
Eight additional runtime controls reject wrong read/write offsets, truncated
pointers, neighboring-word writes, a wrong phase and a removed work lookup.
All 11 unittest methods pass without skips.

## Complete-owner preservation

Fresh whole-owner verification reports **183 MATCH / 4 ASM**, across 187
functions in the six owners, exactly preserving the baseline statuses/sizes.
The independent object audit compares all allocated raw bytes, section layouts
and alignment, including code padding and relocation addends. It then compares
resolved relocation identities, permitting only genuine address aliases such
as the uppercase userdata getter. No code/data region is masked or excluded.

All 2,255 allocated production relocation meanings are preserved; the
all-guards Window comparison additionally covers its 1,447 relocation entries.
Lint reports zero errors (89 retained out-of-scope warnings), all 107 lint
unit tests pass, and `git diff --check` passes.

The audit passes for every production owner and for the complete Window owner
with all four guards active. Every function byte and size is identical to the
base; the guarded bodies and their case-table data also remain identical.
No new matching count is claimed. Full-image hashes and exact C-link membership
have not yet been validated for this projected candidate.

## Reproduce

With the configured compiler and authorized retail inputs available:

```sh
python tools/check_message_procedure_forwarding.py
python tools/verify.py src/promoted/code1_0027.c src/itfMsgProcedure.c src/itfMesManager.c src/Event/Fcl/fclMisc.c src/Yajima/y_misc.c src/promoted/itfMsgProcedure_Window.c
python -m unittest discover -s tests -p 'test_message_procedure_forwarding_contract.py'
python tools/decomp_lint.py src/promoted/code1_0027.c src/itfMsgProcedure.c src/itfMesManager.c src/Event/Fcl/fclMisc.c src/Yajima/y_misc.c src/promoted/itfMsgProcedure_Window.c
```

Use the approved QEMU i386 adapter if the host cannot directly execute the
native32 fixtures. Skipped native fixtures are not accepted as runtime passes.
The sibling JSON records the exact source/object identities and guard hashes.
