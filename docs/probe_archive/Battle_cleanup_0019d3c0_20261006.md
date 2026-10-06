# Explicit battle-unit cleanup input

`src/promoted/code1_0019.c` now expresses the unit argument already consumed by
retail's cleanup function. This repairs an existing C contract and adds no C
promotion: the owner remains **150 MATCH / 1 ASM**.

## Source correction

The old declaration was `extern void func_0019d3c0();`; its K&R definition
declared the parameter separately as `u8 *arg0`. Both are now
`void func_0019d3c0(u8 *arg0)`. The return remains `void`.

`func_0019d4e0` now calls `func_0019d3c0(arg0)`. `func_0019d550` now calls
`func_0019d3c0(temp_17)`, using its saved copy of `arg0`. Previously both calls
omitted the argument. The third caller, `func_0019b640`, already supplied its
unit and required no change.

Retail `0019d3d0` copies incoming `$a0` into `$s0`; the next instruction reads
the unit's halfword at offset `0x9fe`. The two repaired callers enter the
cleanup call with that same unit in `$a0`. Explicitly expressing this input
preserves the generated code and removes reliance on ambient argument-register
contents.

## Completed validation

The full current owner was compiled in its configured native compiler context,
then every physical function and every allocated data section was compared
with the validated retail ELF after resolving relocations. All **151 physical
functions** remained exact; all **722 code references and 33 data references**
resolved; all four allocated storage sections and executable coverage passed.
There were **zero function regressions**.

| Function | Native bytes / retail window | Resolved differing words |
| --- | ---: | ---: |
| `0019d3c0` | 288 / 288 | 0 |
| `0019d4e0` | 112 / 112 | 0 |
| `0019d550` | 288 / 288 | 0 |

`func_0019c0d0` remains the unchanged `INCLUDE_ASM` control. Its exact 3808-byte
physical window is included in the owner proof but earns no C credit. The
generic scratch prover labelled its selected target C; the retained receipt
corrects that metadata to ASM and explicitly records zero new promotions.

The ordinary owner verifier also passed with 150 MATCH / 1 ASM. Source lint
reported zero errors and 34 existing warnings; `git diff --check` passed.

## Retained evidence and replay

`Battle_cleanup_0019d3c0_20261006_receipt.json` retains the source/object hashes,
all 151 per-function code and resolved-code hashes, every resolved code
reference, all storage comparisons and data references, and executable
coverage. Its `reference_fields` array documents the compact reference rows.
It was derived from the completed proof without repeating compilation.

The full local inputs and logs are preserved in
`build/finish-20261006/battle-worker1/0019d3c0-contract/`, with the ordinary
verifier and lint logs in the parent directory. The original complete native
proof's hash is retained in the tracked receipt.

From a configured checkout, the normal source validation can be replayed with:

```text
python tools/verify.py src/promoted/code1_0019.c
python tools/decomp_lint.py src/promoted/code1_0019.c
```

These commands replay the ordinary verifier and lint. The tracked receipt
records the separately completed full relocation/storage proof; it does not
claim that the ordinary verifier performs those additional checks.

The source before this correction was based on
`4b32b6ccbb935945461838d8981ba508f675358a`. Its SHA256 was
`3d5a4e39cf9bc8e64b2d65359592d9dd567519c7e9147dc6b5b2dc21b59cef9c`.
The corrected source SHA256 is
`2875a38fd03fb4deb33e297bab31b1e52cd66784158e079d84d0febc89e290fb`;
the native object SHA256 is
`63a83bab0f6a448d715685c65f672a69f790aee8000ddbf5086f46b3a7c10b29`.
