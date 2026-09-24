# Formation callback 001d2e20

This callback obtains the action category, chooses normal or paired placement,
and applies the resulting quaternion and position to the actor. Its packet is
created by `func_001d3000`: actor, target action and partner action occupy three
pointer words, followed by the stored unsigned 16-bit action identifier.

Configured MWCCPS2 b210 with `-O2 -Iinclude` emits **444 executable bytes in the
448-byte retail window**, followed by four zero alignment bytes. All **ten
relocations** resolve exactly. The complete owner preserves all 33 other
functions, including the newly recovered `func_001d1f30`, and all allocated data.

The decisive source boundary captures the packet's unsigned halfword before
checking for a partner, then interprets the captured bits as a signed action:

```c
actionBits = work->action;
paired = work->partnerAction != NULL;
mode = (s16)actionBits;
```

With scoped propagation disabled, this reproduces the delayed action copy in
the retail prefix: signed halfword load, partner-pointer load, presence test,
then the saved action copy. The earlier signed-scalar version coalesced that
copy and rotated the saved registers; a union version kept the desired lifetime
but introduced a stack store and extra extension instructions. The accepted
source uses a real scalar storage/interpretation boundary, with no dummy object,
register binding, artificial effect or assembly implementation.

The inline placement helper keeps complete outputs: four float quaternion
components and three float position components. Its declarations agree with
the actual providers: the action query and pair predicate consume a signed-wide
action value, while the placement routine consumes a signed-word category.
The packet creator's unsigned action parameter and store are unchanged.

The candidate, rejected alternatives, compiler identities, exact code and
sibling proofs are retained under
`build/finish-first-party-20260922/continue-26-formation/`.
Reviewed source, final native object, official installed-owner report and build
publication evidence are under `continue-27/formation/` in that campaign.
