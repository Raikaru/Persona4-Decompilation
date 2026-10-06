# Order register allocation: a measured graph diagnosis

`func_001b11c0` remains **192/192 bytes with five resolved instruction-word
differences**. This discovery does not promote the function or modify its
compiler output. Its existing fallback remains authoritative.

A live capture of the configured b210 compiler produced complete code-generation,
pre-allocation, coloring and post-allocation records for the unchanged complete
owner. The instrumented and ordinary compilations produced the same whole object:

```text
17a5fda6d30a58bc726649f2cd5044818b0cfd3a609fac8503102d55b394ced5
```

The target has 48 instructions. The entire mismatch is the masked-key and loop-
index register exchange. The captured virtual roles and hardware colors are:

| Value | Virtual node | Current register | Retail register |
| --- | ---: | --- | --- |
| Masked key | 48 | t1 / 9 | t3 / 11 |
| Array cursor | 38 | t2 / 10 | t2 / 10 |
| Inner index | 37 | t3 / 11 | t1 / 9 |

The actual coloring work list was validated from its links before normalization.
Replaying its order, nodes 63 down through 32, reproduces **all 64 captured
colors**. The current interference graph already permits the retail result:
changing only the relative coloring order of these three nodes to index, cursor,
key exchanges nodes 37 and 48 and changes no other assignment.

This rules out a missing interference edge as a necessary explanation for this
specific residual. It does not identify the original source construct that
produced the retail ordering. A modified coloring order is a mathematical
diagnostic, not an allowed compiler patch, object rewrite or recovery candidate.
The source-level question is how a faithful value lifetime or supported input
produces that order without adding computation or false storage.

`graph.json` contains only integer node IDs, neighbor sets, the captured colors
and validated order. It omits process addresses, compiler instructions and PCode
payloads. Its hash is bound to the original capture and the neutral whole-object
receipt. `replay.py` runs offline using only these committed text files:

```sh
python docs/probe_archive/Order_allocator_001b11c0_20261005/replay.py
```

It verifies the graph digest, reproduces every captured color, and asserts that
the alternative exchanges only the two expected nodes. No compiler, emulator,
native object mutation or source installation is involved. The neighboring
functions, actual GP references, key width and unsigned loop bounds are not
changed by this discovery.
