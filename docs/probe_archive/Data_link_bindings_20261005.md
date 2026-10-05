# Rain and texture-strip linker data bindings

The public `0549c139bde1338e6441a69bf7c81afeb5ed74fd` snapshot passed the full
production verifier with 6,766 first-party MATCH functions and both retail build
hashes. Its link report nevertheless excluded `src/promoted/code1_0018.c` and
`src/promoted/k_texStrip.c`: seven external data names in the promoted bodies
were absent from the linker's symbol table. The build correctly retained retail
assembly for both owners, so the passing image hashes did not demonstrate that
the new C bodies were linked. Linked inventory fell from 8,586 functions in 658
units to 8,511 functions in 656 units.

The two cached production objects independently passed all function byte checks,
whole-object/text layout checks, and owned-data placement. The only rejection
was the seven unresolved data names. No eligibility check or function body is
changed by this repair.

## Address evidence

All twelve affected native references are zero-addend `R_MIPS_GPREL16` records.
Reading their actual retail instruction operands with the configured and
ELF-confirmed GP `0x007690f0` yields these bindings:

| Symbol | Address | Function and reference offsets | Storage checked |
| --- | --- | --- | --- |
| `fGpffff841c` | `0x0076150c` | `00182bc0`: 2628 | Aligned four-byte float operand |
| `D_00763130` | `0x00763130` | `00190c10`: 1460, 1540 | Seven bytes through the string terminator |
| `D_00763138` | `0x00763138` | `00190c10`: 164 | Two bytes through the string terminator |
| `D_0076313C` | `0x0076313c` | `00190c10`: 188 | Three bytes through the string terminator |
| `D_00763140` | `0x00763140` | `00190c10`: 248 | Five bytes through the string terminator |
| `D_00763148` | `0x00763148` | `00190c10`: 924 | Five bytes through the string terminator |
| `D_00764498` | `0x00764498` | `00190c10`: 956, 1020, 1112, 1220, 2396 | Aligned four-byte descriptor slot in retail zero storage |

Offsets are bytes from the named function's entry. These definitions identify
existing retail storage; they neither allocate replacement storage nor copy
licensed payloads into the repository. The source's documented input and
provider qualifications still apply.

## Bounded regeneration

The stock recovery generator independently recovered all seven values from
matched code. Its full output also refreshes unrelated historical entries, so
this repair retains those existing entries and applies only the seven reviewed
rows. `config/symbol_data_addrs.txt` records their evidence; the scoped replay
checks the generator's output and preserves every other table byte.

With the ordinary licensed compiler and retail inputs configured, use a fresh
split and then:

```sh
python tools/recover_symbols.py --print > build/data-bindings-generated.txt
python docs/probe_archive/Data_link_bindings_20261005_replay.py --generated build/data-bindings-generated.txt
```

The replay verifies an already repaired tree. To reproduce the bounded table
refresh on its parent, run the same replay with `--write`. It fails on a missing,
duplicate or contradictory generator result, or an existing contradictory
binding. It never removes or changes an unrelated entry. A later full stock
regeneration also retains these bindings and checks curated/scanned agreement.

Validation must check the actual linked-function report in addition to the
full verifier and both retail hashes. The original cold report is retained as
failure evidence; its successful image hashes are not relabeled as proof that
these two owners were C-linked.
