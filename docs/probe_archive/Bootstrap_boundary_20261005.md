# Startup boundary and linker-symbol verification, 2026-10-05

`func_00100008` remains the extracted entry routine. Its source comment now
describes the actual 29 cleared writable general-purpose registers, leaves
`k0` and `k1` untouched, and gives the correct BSS interval
`[0x00764280, 0x00938a00)`. The initial stack does not come from an ordinary C
call: GP is installed at `0x001001c0`, and the result of SetupThread syscall
60 supplies SP at `0x001001cc`. The next syscall receives the BSS end and
size `-1` before runtime initialization, interrupt enable, main and exit.

The comment repair does not alter the complete owning object or claim a new
C match. A future hardware entry wrapper must preserve this actual startup
ABI; moving the reset instructions into an assembly body in a C file would
not recover their C implementation.

The complete actual owner passes native comparison for all 38 functions,
all 611 code relocations and the seven references in its owned data section.
The earlier before/after object comparison is retained in
`build/resume-bare-worker12/startup-comment-receipt.json`. The current source
SHA-256 is
`b122f8d6127297d95eab8e5f42d6d79f7120498b65a4748ce9bae09ce1273a86`.

The shared archive verifier now also reads the repository's actual linker
definitions and rejects conflicts with its other address sources. This is
necessary for `D_938A00`, whose six-digit spelling is explicitly defined in
`undefined_syms_auto.txt`; its address is not inferred from a naming shortcut.
All code and storage bytes still undergo independent retail comparison.

The [replay](Bootstrap_boundary_20261005_replay.py) compiles the actual owner,
resolves its complete code and data, and changes only the BSS-end definition
by four bytes as a negative control. The incorrect definition must fail in
`func_00100008`. This control also passed against the source-bound object
from the combined guard verification. No matcher exclusion or placement
exception is introduced.

```text
python docs/probe_archive/Bootstrap_boundary_20261005_replay.py
```

The replay writes its receipt under `build/bootstrap-boundary-20261005`.
It requires the configured native compiler and retail image and changes no
production source or linker configuration.
