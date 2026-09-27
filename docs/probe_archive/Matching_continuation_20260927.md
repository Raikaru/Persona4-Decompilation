# Upstream matching continuation, 2026-09-27

Rebased continuation branch `work/matching-20260927` onto upstream `7438a83`.
The original dirty checkout remains separate. Its complete saved working-copy
snapshot is retained at `backup/rebase-20260927-working-copy` (`57f81596`).

## Accepted checkpoint

The complete verifier covers **13,102 functions: 9,507 MATCH
and 3,595 ASM**. First-party progress is
**6,687 / 6,861 MATCH (97.464%)**, with
**174 fallbacks**. These are six additional first-party C functions;
every other status and emitted function size is preserved.

| Function | Recovery | Executable bytes / retail window |
| --- | --- | --- |
| `func_00179fc0` | Field shadow projection | 1852 / 1856 |
| `func_0017acc0` | Field shadow construction and state dispatch | 1676 / 1680 |
| `func_0018e810` | Map-test grid, selection and drawing | 1804 / 1808 |
| `func_00313d20` | Date and weekday priority selection | 652 / 656 |
| `func_0034ddf0` | Animated line height and alpha | 700 / 704 |
| `func_0034e360` | Line decoration mesh generation | 2648 / 2656 |

Each omitted suffix consists only of retail zero alignment. All six addresses
are present in the successful source-link report. The complete loadable image
and rebuilt retail ELF remain byte-identical:

- Image SHA-1: `3d1d3d2b9d6ccb60836db239ab49674223025a78`.
- ELF SHA-1: `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.

## Source contracts

The shadow recovery uses complete world/atomic collision callback signatures,
the real render-state table element type, a 24-byte bounds accumulator, and
typed frame/model interfaces. Its `u16` resource ID is maintained through both
external callers without changing their emitted instructions. The map and
shadow owners use the state getter's actual `s32 *` return with explicit byte
views. The debug formatter has one shared declaration for its packed 64-bit
text position and format string.

The map, test menu and viewer share the menu descriptor and task-pointer
contracts with their actual providers. Retail `00470258` sets the inner
constructor's fourth argument to zero; the outer `func_00470250` takes only
three arguments. `func_00470430` explicitly forwards its signed visible-row
capacity to `func_00453fa0`, reads the resulting capacity and refreshes the
window. Retail `0047044c` preserves that incoming argument for the setter.
The seven affected owners retain identical instructions and equivalent
relocation targets across 142 functions.

The shadow and map recoveries introduce five GP data references whose names
were absent from the generated linker table. `recover_symbols.recover` and
`select_symbols` derive these entries from the matched objects and retail
instructions. An authoritative-source scan confirms that both complete owners
contain every reference to the five names. This incremental generated-file
refresh preserves every existing definition; no curated entries are needed.

| Generated data symbol | Retail address |
| --- | --- |
| `fGpffff82bc` | `0x007613ac` |
| `iGpffff9f48` | `0x00763038` |
| `iGpffff9fd0` | `0x007630c0` |
| `iGpffff9fd8` | `0x007630c8` |
| `iGpffff9fdc` | `0x007630cc` |

The original link-eligibility planner accepts both complete owners after the
refresh, restoring their 139 functions to the link. The full build retains all
594 C translation units. A separate map-owner GNU link also reproduces all
62 complete function windows and its owned data without relocation masking.

The date getter returns a byte-normalized value through the selected `s32`
interface; every existing consumer retains its byte view. The line height
helper initializes its output and keeps the measured floating-point lifetime.
The vertex writer and all affected callers share one declaration. Decoration
direction use is bounded by the retail table and both animation setters; see
[the domain audit](nline_direction_domain_20260927.md).

## Validation

The final complete-tree verifier runs the original `verify.main` checks for
all bytes, tails, statuses, named callees and data-symbol relocations. Unchanged
compilation objects are reused only when their source and header fingerprints,
compiler flags and object digests agree with completed verification receipts.
Changed units and missing objects are compiled by the original verifier.
The cache review also records vendor-header and actual toolchain inputs beyond
the ordinary dependency scanner. Configuration, assembly, Python-package and
supplemental input checks bind validation to the checkout; the final report is
published only after the verifier succeeds and its input checks pass again.
Every comparison and relocation gate runs on the resulting objects.
The five-entry generated linker-table change is checked separately as an
additive metadata update; the C compilation inputs remain identical, and all
symbol-binding checks run against the updated table.

The full build retains its original C eligibility, placement, relocation,
link and output-hash gates. A local assembly cache reuses only exact-source
baseline objects with matching tool and macro inputs, retail windows and
object digests. Changed assembly requests are assembled normally. All previously
source-linked functions remain source-linked, along with the six new recoveries.

The complete Python suite passes under WSL: **820 tests, 10 skipped**.
The fourteen installed recovery tests also pass separately in the Windows/WSL
native fixture environment with **zero skips**, exercising the compiler-backed
cases unavailable in the WSL suite environment. Source-honesty lint reports
**zero errors**. Earlier baseline test failures and the corrected extraction
subset are retained; the final full suite uses explicit working compiler and
retail paths.

Actual-source behavior fixtures run at both O0 and O2. Date coverage includes
68,164 selector/getter/caller scenarios and 6,575 consumer views per level;
ten meaningful mutations are rejected. Real 32-bit fixtures cover 49,152 line
height scenarios, 43,336 decoration scenarios, 164 map scenarios, 6,912 shadow
constructor scenarios, four projection scenarios with 187 checks, and 30
callback scenarios per level. Provider-signature assertions and constructor/
height regression controls also pass. These fixtures complement target and
link checks; native execution does not establish the PS2 instruction ABI.
The map fixture additionally executes both corrected menu provider bodies,
checks six signed row-capacity values and independently validates seventeen
renderer, menu and provider signatures.

To reproduce from a configured checkout:

```sh
python tools/verify.py --json build/verify_report.json
python tools/build.py --progress-report build/linked.json
python -m unittest discover -s tests
python tools/decomp_lint.py --summary
```

Local evidence is retained in `build/final-verify.json`, `build/final-linked.json`,
`build/final-linux-tests.*`, `build/final-lint.*`, `build/final-inputs.json`,
`build/checked-verifier-cache/`, `build/recovered-gp-integration/`, and the
`build/*20260927/` probe directories.

## Preserved follow-up work

The bounded AI command investigation leaves `001dbf20` at the existing seven-word
register-allocation residual. The battle fade investigation leaves `001b87e0`
at thirteen words, involving rounding-constant hoisting and multiply-accumulate
use. Their measured attempts are retained locally; neither is counted as C.

Saved `00484bb0` remains a future ABI bundle: the fresh audit found 41 callbacks
in 17 owners, 38 nonuniform definitions, and instance-protocol references in
22 owners. Its historical zero-difference candidate is not accepted without
reconciling those contracts.

The two upstream probe files differing only by `KOC`/`KoC` capitalization are
preserved byte for byte. The interrupted mixed-case file is now named
`KoC_00243a30_interrupted_body.c`, making the checkout usable on Windows without
index skip flags.
