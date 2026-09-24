# Thunder geometry constructors — 00495160 and 00496340

Both constructors now use native C in `src/Graphics/Effect/effPolygonThunder.c`.
Under configured MWCCPS2 b210 with `-O2 -Iinclude`, `func_00495160` emits
1,216/1,216 exact bytes and `func_00496340` emits 1,224/1,232 exact bytes with
eight verified zero alignment bytes. Each has eleven fully resolved relocations
and no new allocated data.

Both allocate geometry copies and populate a five-color row for every sample.
Unlike the paired constructor at 00497750, these two recalculate opacity at every
sample and do not require an initial fade value before the outer loop. Their
falling numerator is `sampleCount - sampleIndex`; no extra subtraction or parity
gate is introduced. Their inner sample index advances before the destination
pointer, preserving the original instruction order.

The RGB components and fade endpoint are ordinary unsigned words. Scoped loop
invariant and lifetime controls preserve their values across allocation calls;
the compiler chooses the required spill widths naturally. Complete four-byte
color snapshots preserve all channels and the original load/store grouping.
The first constructor uses sixteen-byte list entries and clears the last word;
the second uses forty-eight-byte entries with a header back-pointer.

The review combines only the two target definitions into the current owner.
It preserves all fourteen other function bodies, including the newly recovered
paired constructor, their relocation meanings, all existing allocated data, and
the previously reconciled geometry-provider contract. The other guarded C
drafts are retained without changes.

The individual native proofs are under
`build/finish-first-party-20260922/continue-29-tc/p51/` and `p63/`.
The joint reviewed source, native object and integration records are under
`build/finish-first-party-20260922/continue-30-batch/`.
