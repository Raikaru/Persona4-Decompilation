# datCalc recovery, worker 7, September 19, 2026

The current-owner campaign recovered `func_00232d80` and `func_00233bc0` as C.
The combined owner verifies as 75 MATCH and 5 ASM, from 73 MATCH and 7 ASM.
No external provider, header, compiler configuration, or other owner was changed.

## Reproduction and independent evidence

Scratch is `build/all-first-party/datcalc/`. Every measurement uses
`probe_variants._compile_in_context` with the logical datCalc owner and configured
MWCCPS2 b210. `run.py` puts experiments under the current owner SHA256 prefix to
prevent stale-context reuse.

The original measurement context is `owner-ae91591f1086/`. Its immutable
`00232d80/owner-before.o` has SHA256
`93e852af75a61b73ce69107f35832cd86ab08952b35d7c0fa618f54f5d1ac7c5`.
The integrated source SHA256 before the pragma documentation follow-up is
`a052f0b7c5da2880ab5f3a5b1f52f5f4bd717c40f1b152ec87e16158dcf1608b`.

The configured `tools/verify.py` result is retained in
`owner-ae91591f1086/two_matches/integrated_verify.json`. The independent complete
object comparison is `verified/two/current.proof.json`. It resolves all target
relocations, compares emitted bytes to validated retail, verifies omitted tail
bytes are zero, and compares the bytes and canonical relocations of all 78
non-target functions plus both allocated data sections. All comparisons pass.
The errors-only `tools/decomp_lint.py` run reported zero error findings, and
`git diff --check` passes. Prime independently repeated both target proofs and
the official 75 MATCH / 5 ASM verification. The initial unfiltered lint had
zero errors and three H003 pragma-documentation warnings, the same warning
count as the baseline. A factual measurement note was then added above the
new `00232d80` pragma; the two unchanged later restore pragmas remain warnings.

| Function | Emitted / window bytes | Zero tail | Resolved relocations |
| --- | ---: | ---: | ---: |
| `00232d80` | 1304 / 1312 | 8 | 24 |
| `00233bc0` | 1280 / 1280 | 0 | 23 |

## Six skill searches: 00232d80

The flattened draft measured 78 differing words. The repeated retail sequences
are inlined instances of the existing `00232730` search, including its equipment
fallback. Extracting that actual body as `PTDatCalcHasSkill` and calling it six
times restores the loop register allocation. The public `00232730` now calls the
same helper; its emitted bytes and relocations remain identical. The recovered
mask uses the existing scoped `opt_loop_invariants on` policy. There is no
duplicated search implementation, new emitted helper, forced padding, or assembly.

`helper32.py` retains the original helper experiment, and `shared32.py` retains
the shared implementation. Both measured zero differing words; the alignment
tool's two deletion rows are the eight verified retail zero-tail bytes.

## Status multiplier: 00233bc0

The production draft measured 261 differing words; the earlier truthful native
conversion archive measured 259. The recovery uses ordinary unsigned-to-float
casts, unsigned byte intermediates at the signed-byte merge and boost tests, a
signed-halfword to unsigned-halfword predicate boundary, and the existing
`PTDatCalcOffsetAdd` with scoped `opt_propagation off`. Integer address arithmetic
is unsigned; the final address is converted to a pointer only after accumulation.
This avoids an intermediate pointer before the table when status is -1. Case 4
uses the retail `+7` table displacement. All six real callers pass an unused third
argument, now represented in the definition.

The unmasked unsigned shift is justified by the function's accepted status-index
contract, not arbitrary invalid inputs. Retail diagnoses `(arg1 & 255) >= 24`
twice. The complete configured retail image was scanned for incoming direct
control flow, absolute pointers at every byte alignment, possible address
materialization, and branches bypassing the caller's argument setup.

| Retail call address | Caller | Second argument |
| --- | --- | ---: |
| `00235bec` | `00235520` | 0 |
| `00235c04` | `00235520` | 3 |
| `00235c4c` | `00235520` | 1 |
| `00235c64` | `00235520` | 3 |
| `0023f0c0` | `0023e6f0` | 4 |
| `0023f0d8` | `0023e6f0` | 2 |

These are the only incoming direct references to the full `00233bc0..002340c0`
body. Each constant is assigned two instructions before its call, followed by
the third argument setup and a no-op delay slot. There are no setup-bypass edges,
entry-address literals at any byte alignment, aligned literals into the body,
or low-half address-materialization instructions with immediate `0x3bc0`.
Four incidental unaligned interior-address byte patterns occur in record/float
data, not function-pointer slots. Full caller branches were also inspected.
`audit33.py` and `owner-ae91591f1086/00233bc0/retail_reference_audit.json` preserve
the executable scan for retail SHA1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c`.
Thus `1U << index` is defined for the accepted range 0..23; current executable
callers use only 0..4. This evidence does not claim defined behavior for new
callers violating the documented precondition.

The defensive masked control remains as `conditional_signed_selector.c`: it
emits 1284/1280 bytes, with three aligned changes confined to the extra mask and
its branch/register consequences. `contract33.py` preserves the final audited
form, and `audited_status_named.c` has zero aligned instruction differences.

## Remaining initial measurements

Before the two recoveries, `00238940` measured 765 differing words at
3636/3728 bytes, `0023a6b0` measured 2615 at 12312/12336, and `002411a0` measured
473 at 2584/2592. The `00235520` draft failed compilation on existing pointer
casts, spurious third arguments to `00106cd0`, and a conflicting old-style
`0023d6e0` declaration. The `0023e6f0` draft failed on two missing `u16 *` casts
at `00243e30` calls. These are measurements and actionable boundaries, not claims
that further recovery is impossible. Further experiments stay in scratch until
the same exactness and unchanged-owner gates pass.
