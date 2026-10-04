# Field event controller: public replay and final gates

This page describes the complete source now in this checkout. The accompanying
FieldEvent_00172e00_recovery_20261003.md and FieldEvent_00172e00_exact_20261003.md
are frozen historical checkpoint receipts. Their statements about a missing
workspace or pending gates describe those checkpoints, not the current setup.
Their bytes and original meaning are preserved.

The recovery receipt's old workspace hashes identify lost historical results;
they are not links to accessible artifacts. Its recovery recipe and retained
rank14 archive describe provenance, not required public inputs or public
reproduction links. No private recovery script, source-history bundle or lost
workspace file is needed to compile or test the current implementation.

## Reproduce the current source

Configure the licensed compiler/retail inputs and host tools described in the
repository README and Dockerfile. From the repository root:

```sh
python tools/build.py --setup-only
make split
make regenerate-asm
python tools/verify.py --json build/verify_report.json
make build-progress
python tools/gen_decomp_report.py --report build/verify_report.json --linked-report build/linked_report.json --output build/report.json
```

For native fixtures, use a supported host with Clang and working i386 execution
(the repository helper also supports its documented Windows/WSL route):

```sh
PYTHONPATH=tests python -m unittest -v test_field_event_controller test_field_transition_contracts test_field_file_transport test_field_snapshot_extent
python -m unittest discover -s tests -v
```

If the host cannot execute i386, it needs a working execution adapter before
these fixture commands are meaningful. Skipped native fixtures do not count as
passes. The project source, compiler/sanitizer flags, fixture bodies and checks
must remain unchanged. This is a host execution requirement, not a dependency
on the lost recovery workspace.

## Final validated checkpoint

Validated on 2026-10-04 against the frozen production source:

- Full verifier: 13,102 functions, 9,576 MATCH / 3,526 ASM
- First-party: 6,756 MATCH / 105 ASM; exactly 00172e00 gained MATCH
- Target: 6,260 exact instruction bytes, all 285 relocations resolved, followed
  by 12 authentic retail-zero alignment bytes; all 25 owner siblings preserved
- Corrected snapshot object: 112 bytes, alignment 16; provider instructions
  and references remain unchanged
- Complete production build and both retail hashes pass; 00172e00 is present
  in the C-linked event owner, and primitive 00480940 remains matched
- ELF SHA-1: 4eeec0360cf2715535d9f7e52eb69d786fb0158c
- Loadable-image SHA-1: 3d1d3d2b9d6ccb60836db239ab49674223025a78
- Full ordinary suite: 1,051 tests, no failures, only the two explicitly absent
  middleware tests skipped; the focused native suites pass without skips

An initial ordinary run exposed missing local assembler/retail/report fixtures
and was retained as an incomplete setup run. After those inputs were supplied,
the unchanged complete suite passed. No test or skip rule was weakened.

The controller fixture substitutes most external providers; separate fixtures
execute the named actual provider bodies. Tests establish their stated bounded
call, storage, alias and integer contracts, not gameplay execution or a complete
EE hardware floating-point model. The final C instruction stream and canonical
relocations are checked independently against the authenticated retail image.
