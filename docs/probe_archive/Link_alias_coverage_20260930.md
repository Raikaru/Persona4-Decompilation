# Six recovered aliases restore C linkage

Base: `a988b1dd4e5098431a84057eae7247a99e30f3c4`, confirmed as remote
`main` on 2026-09-30. This patch changes no production C source, header,
function marker, guard, compiler setting, or existing address.

The six definitions are selected verbatim from the maintained
`tools/recover_symbols.py` output. They are inferable from already-matching
code, so they do not need new curated-address exceptions. Unrelated output
churn from full symbol regeneration is intentionally excluded.

| Symbol | Address | Retail GP evidence |
|---|---|---|
| D_007611AC | 0x007611AC | 00117C00: GP - 0x7F44 |
| D_00762FD8 | 0x00762FD8 | 0015EA5C: GP - 0x6118 |
| D_00764340 | 0x00764340 | 0015EB2C, 0015EBE0: GP - 0x4DB0 |
| D_0076439C | 0x0076439C | 0015E994, 0015ED6C, 0015EEA0: GP - 0x4D54 |
| iGpffffa980 | 0x00763A70 | 00362320: GP - 0x5680 |
| iGpffffb528 | 0x00764618 | four GP - 0x4AD8 references in 002A03B0 |

GP is 0x007690F0. All twelve instruction references have zero compiled
addends. `test_link_alias_addresses.py` checks their actual instruction
addresses, GP register fields and signed immediates against the
SHA-1-verified retail ELF. It also tests all six active definitions and
rejects two neighboring-address mutations for each alias. The existing
17 recovered-symbol tests pass unchanged.

The previously unresolved names block four whole translation units:

- `src/promoted/shdPersona.c`: D_007611AC; 102 function windows
- `src/Kosaka/Field/k_fldFBN.c`: D_00762FD8, D_00764340, D_0076439C;
  three windows
- `src/promoted/code1_002a.c`: iGpffffb528; 28 windows
- `src/promoted/code1_0036.c`: iGpffffa980; 34 windows

The four complete owners verify as 165 existing MATCH functions and two
retained ASM fallbacks (`00119E10` and `0015F000`). Those two fallbacks are
not new C matches. No guarded recovery from another checkpoint is included.

## Minimal-tree validation

The isolated patch-on-main build passed both complete retail hashes:

- Loadable image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`
- Rebuilt ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`
- 604 C objects and 54 Sony SDK objects linked; 658 total units
- 8,586 linked function windows, up from 8,419; all 167 additions belong
  to the four owners above, with zero lost windows

The unchanged whole-object selector was also rerun on the actual compiled
minimal-tree objects with the old and new address maps. Only these six
addresses differed: 600 to 604 C objects, 7,933 to 8,100 C-object function
windows, and exactly the same 167 additions. Each missing alias individually
prevents its owner from qualifying. The four source files and all their
project-header dependencies are byte-identical to the base commit.

The new alias suite passed three tests, including twelve retail references
and twelve rejected neighboring-address mutations. All 17 existing
recovered-symbol tests passed. The ordinary repository discovery ran 860
test methods: 847 passed and 13 skipped, with 11 additional class-setup skips
(24 skip records total), zero failures and zero errors. Skips cover unavailable
native-32 execution, optional middleware input and a full-verifier report;
the four relevant whole-owner verifications were run separately and passed
with 165 MATCH and two ASM records. No native behavior was changed by this
address-only patch.

This is C-link coverage recovery, not new function-matching credit.
Publication still requires equipped CI for the exact published commit.

Reproduce with the configured toolchain and verified retail inputs:

```sh
python -m unittest discover -s tests -p test_link_alias_addresses.py -v
python tests/test_recovered_symbols.py
python tools/verify.py src/promoted/shdPersona.c src/Kosaka/Field/k_fldFBN.c \
  src/promoted/code1_002a.c src/promoted/code1_0036.c
make test
make build-progress
```
