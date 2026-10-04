# Combination-row renderer: production replay, 2026-10-04

The accompanying rank16 comparison and exact-closure reports describe earlier
guarded checkpoints. They remain unchanged as historical evidence. This addition
records the production promotion of `0031ac10` on public parent
`a9d7c7c58e35602a5fea100df12eff31e328e4a5`. Historical research commit IDs in
those reports are provenance; the current source and tests require no unpublished
Git objects, retained source archive, or workspace-specific path.

The promoted function retains its reviewed body and scoped
`push`/`opt_lifetimes`/`pop` pragmas. Independent whole-owner compilations of the
guard-enabled source and actual guard-removal source produced the same object.
All 5,788 executable bytes and 185 resolved references equal retail, followed by
four authentic zero alignment bytes in the 5,792-byte window. The 69 siblings,
owned data, coherent row/level contracts, and other shared-header owners are
preserved. The digit provider remains guarded; it gains no MATCH credit here.

The first capture omitted the scoped pragma and was rejected. The corrected
whole-owner capture preserves that pragma. This was an evidence-capture repair,
not a change to the accepted source semantics.

## Complete production gates

- Full verifier: 13,102 rows; 9,577 MATCH and 3,525 ASM
- First-party progress: 6,757 MATCH and 104 remaining, a gain of one function
  and 5,792 matched code bytes
- `0031ac10` is the sole status/size/code change. Ten compiler-local HI/LO
  symbol names renumber across five unchanged siblings; exact section ordinal,
  offset/size, complete table bytes, data relocations, and all other reference
  fields are preserved
- Build: 604 source C objects plus 54 SDK objects; 8,586 linked functions in
  658 translation units. `0031ac10`, `00172e00`, and `00480940` are C-linked
- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Retail ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- Ordinary suite: 1,053 tests, zero failures, and only the two documented absent-middleware skips

Native checks retain their documented controlled-provider boundaries. They
execute 1,620 trace scenarios and 115,200 signed-coordinate scenarios per
optimization level, with 28 negative controls. They do not establish unrestricted
gameplay, hardware floating-point, or arbitrary provider-allocation guarantees.

## Replay from a current public checkout

Use the repository's documented compiler versions and authorized retail input.
Run setup/splitting and generated fallback assembly preparation as documented
before the complete build. Then run:

```sh
python tools/verify.py --json build/verify_report.json
python tools/build.py --linker-backend gnu --progress-report build/linked_report.json
python -m unittest discover -s tests -v
python tools/gen_decomp_report.py --report build/verify_report.json \
  --linked-report build/linked_report.json --output build/report.json
```

The full native gate used a host-independent i386 execution adapter and allowed
only the two existing absent-middleware skips. A host that executes i386 ELF
directly can use the ordinary command above. An external adapter must preserve
arguments, environment, timeouts and failure results; it must not relax tests or
accept additional skips. Source and tests are identical for both execution paths.
