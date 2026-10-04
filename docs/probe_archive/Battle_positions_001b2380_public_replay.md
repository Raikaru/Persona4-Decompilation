# Battle opening positions: complete production replay

This addendum records the complete gates for the production implementation of
`001b2380` and its coherent packet/equipment prerequisites, based on public
`fa980eedbd5732a5f986d27166c525503b0f94dc`. The accompanying scoped match report
is preserved unchanged. Its private review and resource-census hashes identify
the evidence used during review; they are not links to publicly available files.

Current source and ordinary tests require no unpublished Git objects or private
audit captures. The retained-height argument has the normal-program domain
described in the scoped report: authenticated unchanged UNIT/ENCOUNT resources,
in-bounds inputs, the traced callers and valid allocator/list/packet lifetimes.
The synthetic special/empty/dead-first witness remains rejected before calling
the seed-free implementation. The tests do not replace the resource/history
proof or establish totality for fabricated state or modified game assets.

## Complete checks

- Full verifier: 13,102 rows; 9,578 MATCH and 3,524 ASM. First-party: 6,758 MATCH and 103 remaining
- Only `001b2380` gains MATCH status, adding 4,160 matched code bytes. Its 4,156
  executable bytes include the real return delay slot; the remaining four bytes
  are authentic zero alignment
- All 122 target references and 122 siblings/data preserve. Twenty compiler-local
  reference names renumber across seven unchanged siblings: ten literal references
  and ten HI/LO references. Their instruction offsets, all other reference fields,
  complete data identities and resolved retail addresses are independently equal
- Cold build: 604 C objects plus 54 SDK objects; zero cache hits, with 860 eligibility and 604 link compiles
- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Ordinary suite: 1,059 tests, zero failures and only the two documented absent-middleware skips

The earlier matches `00480940`, `00172e00` and `0031ac10` remain MATCH and
C-linked, alongside the new target. The local linked inventory remains 8,586
functions in 658 translation units. Focused fixtures preserve six positive runs
and 42 negative executions across O0/O2, including the packet-phase, cursor-reset
and caller-precondition controls. These remain controlled-provider checks, not a
whole-battle or hardware-wide floating-point claim.

## Reproduce from current source

Use the repository's documented toolchain and authorized retail input. Complete
the documented setup, splitting and generated fallback assembly preparation,
then run:

```sh
python tools/verify.py --json build/verify_report.json
python tools/build.py --linker-backend gnu --progress-report build/linked_report.json
python -m unittest discover -s tests -v
python tools/gen_decomp_report.py --report build/verify_report.json \
  --linked-report build/linked_report.json --output build/report.json
```

The complete native gate allows only the two existing absent-middleware skips.
A host that cannot execute i386 ELF directly needs an external execution adapter
that preserves arguments, environment, timeouts and failures without changing
source, tests or skip rules. The licensed resource tables, compiler binaries,
machine objects and private captures are not part of this source publication.
