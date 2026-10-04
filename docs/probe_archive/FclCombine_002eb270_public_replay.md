# Combine layout: complete production replay

This addendum records the complete gates for `002eb270`, based on public
`152236fb5194d005feadb25cf6efb921d339c79d`. The accompanying scoped source and
test receipt is preserved unchanged. Its hashes identify the reviewed source;
private object and audit captures are not public downloadable artifacts.
Current source and ordinary tests need no unpublished Git history or assets.

## Complete checks

- Full verifier: 13,102 rows; 9,579 MATCH and 3,523 ASM. First-party: 6,759 MATCH and 102 remaining
- Only `002eb270` gains MATCH status, adding 7,504 matched code bytes. Its 7,500
  executable bytes include the real return delay slot; the final four bytes are
  authentic zero alignment
- All 168 target references, 40 sibling bodies and allocated data preserve.
  Thirty-two HI/LO reference names change for 16 unchanged compiler-local switch
  tables across 14 siblings. Each exact symbol value, section, table bytes and
  data relocation binding is independently equal. Resolving all 209 entries
  reproduces the complete 836 retail table bytes. No other row difference is
  accepted apart from source line numbers
- Cold build: 604 C objects plus 54 SDK objects; zero cache hits, with 860 eligibility and 604 link compiles
- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Ordinary suite: 1,062 tests, zero failures and only the two documented absent-middleware skips

The earlier matches `00480940`, `00172e00`, `0031ac10` and `001b2380` remain
MATCH and C-linked, alongside the new target. The actual linked inventory
remains 8,586 functions in 658 translation units. All 41 functions in
`y_fclCombine.c` now match, completing that 169,200-byte owner. The report's
additive linked category therefore includes the completed owner; the new
matching-code gain is still exactly 7,504 bytes and one function.

The focused fixture executes 46,080 cases at each of O0 and O2 and rejects all
seven controls at both levels. It checks the signed layout byte, every low
transition byte, wider transition words, random boundaries, exact calls,
buffers and post-provider reloads. The transition phases copy a real completed
value, and the final hide predicate retains the incoming signed low byte.
Target/compiler narrowing, initialized task/resource handles and valid resource
dimensions remain the scoped contract. Placement providers are controlled test
boundaries; this does not claim a complete rendering-engine or gameplay run.

## Reproduce from current source

Use the repository's documented toolchain and authorized retail input. Complete
the documented setup, splitting and generated fallback assembly preparation,
then run:

```sh
mkdir -p build
python tools/verify.py --json build/verify_report.json
python tools/build.py --linker-backend gnu --progress-report build/linked_report.json
python -m unittest discover -s tests -v
python tools/gen_decomp_report.py --report build/verify_report.json \
  --linked-report build/linked_report.json --output build/report.json
```

The complete native gate allows only the two existing absent-middleware skips.
A host that cannot execute i386 ELF directly needs an external execution adapter
that preserves arguments, environment, timeouts and failures without changing
source, tests or skip rules. Compiler binaries, retail inputs and object captures
are not included in this source publication.
