# `func_0020b6d0` exact-match handoff

## Result

`func_0020b6d0` was recovered in portable C and published in commit `de42a42d`.

| Property | Verified result |
| --- | --- |
| Owner | `src/promoted/code1_0020.c` |
| Retail address | `0x0020B6D0` |
| Retail window | 816 bytes |
| Candidate object body | 812 bytes |
| Resolved executable comparison | Exact for all 812 emitted bytes |
| Candidate relocations | 14 |
| Unresolved relocations | 0 |
| Relocation mismatches | 0 |
| Retail suffix | `00 00 00 00` |
| Other target-owner functions | 145, all byte- and relocation-identical |
| Caller owner | `src/promoted/code1_001a.c` |
| Caller-owner functions | 71, all byte-identical after prototype correction |
| Repository verifier | 217 first-party functions: 186 `MATCH`, 31 `ASM`, no failures |
| Published commit | `de42a42d` |

The four-byte size difference is the retail zero alignment word after the candidate's final executable instruction. No padding object, dummy local, or assembly was added.

## Evidence read before source work

- Retail assembly: `asm/nonmatchings/code1_0020/func_0020b6d0.s`, complete function, lines 1-225.
- Ghidra: `docs/ghidra_headstart/src/promoted/code1_0020.c`, `FUN_0020b6d0`, lines 2472-2579.
- IDA: `docs/ida_headstart/src/promoted/code1_0020.c`, `sub_20B6D0`, lines 2886-2988.
- Generated candidate: `src/generated/code1_0020.c`, target beginning near line 5377.
- Historical archive: `docs/probe_archive/E20B_0020b6d0_body.c`.
- Current target owner: `src/promoted/code1_0020.c` around the `FUN_0020B6D0` marker.
- Caller and declaration: `src/promoted/code1_001a.c`, declaration near line 53 and call near lines 611-615.
- Provider definition: `src/Main/Battle/Data/datCalc.c`, `s32 func_00242800(u8 *, s32)`.
- Private measurement: `/home/raikaru/p4_four_resume_20260912T062313/CompactAnimationRecovery/0020b6d0/best_exact_exec.measurement.json`.

The private path is workstation evidence, not a repository dependency.

## How the candidate was found

The first ranking used only `*.parent_resolved.json` files and did not expose this recovery. A second pass searched every private `*.measurement.json` for:

- a target still in the current first-party fallback set;
- a candidate source/owner path;
- `candidate.normalized_diff_bytes == 0`;
- `candidate.target_prefix_byte_exact == true`;
- zero unresolved relocations.

That pass found `best_exact_exec.measurement.json`. Its selected source emitted 812 bytes with an exact prefix and fourteen relocations, but the measurement correctly marked it `integration_ready: false`.

This is the reusable discovery lesson: parent-proof rankings are incomplete. Search standalone measurement, proof, recovery-report, and handoff artifacts, then recompile every apparent exact result.

## The unsafe exact candidate

The private candidate declared:

```c
extern s32 func_00242800();
```

and called it with a sign-extended 64-bit expression. The authoritative provider is:

```c
s32 func_00242800(u8 *unit, s32 index);
```

The empty parameter list allowed MWCC to preserve accidental argument shaping. It was instruction-exact but type-unsafe and incompatible with the real provider contract. It was rejected.

This rejection mattered. Installing the old-style declaration would have violated the repository's ABI rules even though the target bytes matched.

## Truthful-prototype residual

Replacing the old-style declaration with:

```c
extern s32 func_00242800(u8 *arg0, s32 arg1);
```

and initially keeping the explicit 64-bit cast caused a broad regression. Passing the already sign-extended `s32 temp_18` directly reduced the candidate to 812 bytes with thirteen executable differences plus the zero tail.

The thirteen executable differences were one consistent saved-register exchange:

```text
retail                                  candidate
$s3 = status 0/1/2/3                    $s2 = status 0/1/2/3
$s2 = sign-extended command index       $s3 = sign-extended command index
```

Representative offsets:

```text
0x184  daddiu $s3,$zero,3    | daddiu $s2,$zero,3
0x1A4  dsll32 $s2,$v0,16     | dsll32 $s3,$v0,16
0x23C  andi   $v0,$s3,0xffff | andi   $v0,$s2,0xffff
0x24C  move   $a1,$s2        | move   $a1,$s3
0x2B0  dsll32 $a1,$s3,16     | dsll32 $a1,$s2,16
```

No logic, branch, call, or relocation was missing. The residual was a two-local register-color cycle.

## Decisive source lever

The candidate originally declared the command index before the status value:

```c
s32 temp_18;
s32 temp_3;
u16 var_19;
u16 temp_16;
```

A bounded 24-permutation search over these four declarations showed two stable classes:

- 12 orders retained the `$s2`/`$s3` swap and thirteen executable differences;
- 12 orders produced an exact 812-byte executable body.

The smallest readable change was to declare the status value before the command index:

```c
u16 var_19;
s32 temp_18;
s32 temp_3;
u16 temp_16;
```

That single lifetime/declaration-order change restored retail's `$s3` status and `$s2` command-index allocation while retaining the truthful `func_00242800(u8 *, s32)` prototype.

This is the reusable matching lesson: when all residual words express one saved-register permutation, tune the declaration order of only the interacting live ranges. Do not rewrite the loop or alter the ABI.

## Final source contract

The recovered definition is:

```c
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
```

Observed behavior:

1. Store the action and selection pointers and the signed command index in the global battle-work block.
2. Set the active flag and update the selection-mode bit from `func_001d8df0`.
3. Treat commands `0x10B` and `0x110` as forced status 3.
4. For nonnegative commands, probe the configured data group and remember whether the availability path is active.
5. Iterate the selection entries.
6. Derive each entry's status from command metadata and ailment/state checks.
7. When the availability path is active and the status is still zero, call `func_00242800` with the signed command index and classify the returned mask as status 1 or 2.
8. Publish the status through `func_0020bfc0`, optionally refresh through `func_0020bfd0`, and clear the in-progress halfword when complete.

`arg0` is unused in the recovered body, matching retail. No fake read was added.

## Caller cutover

`src/promoted/code1_001a.c` previously declared the fourth parameter as `s32`. Retail passes and the callee stores a signed 16-bit command index. The declaration was corrected to `s16`:

```c
void func_0020b6d0(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
```

The existing call still computes `(s64)(s16)var_16`. The prototype conversion is defined and the compiled caller is unchanged.

Proof:

- baseline `src/promoted/code1_001a.c`: 71 function images;
- corrected declaration: 71 function images;
- differing function bytes: none;
- `func_001a1c80` relocation metadata: identical.

## Relocation proof

The actual-current target object contains these resolved call relocations:

| Offset | Symbol |
| ---: | --- |
| `0x038` | `func_00452560` |
| `0x06C` | `func_001d8df0` |
| `0x0EC` | `func_00106330` |
| `0x110` | `func_0010a900` |
| `0x120` | `func_0010ce10` |
| `0x148` | `func_0010f8c0` |
| `0x19C` | `func_0023d8e0` |
| `0x1B0` | `func_0023d6e0` |
| `0x1E0` | `func_00233a90` |
| `0x218` | `func_00233a90` |
| `0x250` | `func_00242800` |
| `0x264` | `func_001f0950` |
| `0x2BC` | `func_0020bfc0` |
| `0x2D8` | `func_0020bfd0` |

All fourteen resolved. The 812-byte resolved candidate equals retail bytes `0x0020B6D0..0x0020B9FB`. Retail byte range `0x0020B9FC..0x0020B9FF` is `00000000`.

## Owner-isolation proof

The actual current `src/promoted/code1_0020.c` was compiled before and after the splice.

```text
baseline function count: 146
candidate function count: 146
missing or additional functions: 0
non-target function byte differences: 0
non-target relocation metadata differences: 0
target emitted bytes: 812
target retail window: 816
target differing offsets: 0x32C only
0x32C classification: absent retail zero alignment word
```

The target proof used fully resolved bytes, not only relocation masking.

The post-integration repository check also passed:

```text
$ python tools/verify.py src/promoted/code1_0020.c src/promoted/code1_001a.c --show-mismatches
functions scanned: 217
  MATCH              186
  ASM                 31
first-party functions scanned: 217
  MATCH              186 (85.7%)
  ASM                 31
Sony PS2 SDK functions scanned: 0
other third-party functions scanned: 0
```

## Reproduction procedure

When repository tooling is intact, use the configured target build and normal verifier first. For a direct owner proof, the process is:

1. Copy the current owner to a private source path.
2. Compile it with the owner's configured compiler and flags.
3. Save the baseline object and per-function byte/relocation maps.
4. Compile the current integrated owner with the same invocation.
5. Extract `func_0020b6d0` from the candidate object.
6. Resolve all 14 relocations against `config/symbols_recovered.txt` / the retail symbol map.
7. Compare the 812 resolved bytes with the retail ELF at `0x0020B6D0`.
8. Confirm the remaining retail bytes are exactly `00000000`.
9. Compare all 145 non-target function byte strings and relocation lists to the baseline.
10. Compile `src/promoted/code1_001a.c` before and after the prototype correction and compare all 71 function images plus `func_001a1c80` relocations.

Compiler invocation used at this checkpoint:

```python
gap.process_c_file(
    source_path,
    object_path,
    c_flags=["-O2", "-I" + str(repo / "include")],
    mwcc_path="/home/raikaru/opt/mwcc-wrapper.sh",
    asm_dir_prefix=repo,
    macro_inc_path=repo / "asm/macro.inc",
    as_march="r5900",
    as_mabi="eabi",
)
```

The wrapper path is workstation-specific. The compiler identity and owner configuration are the invariant.

## Files changed

- `src/promoted/code1_0020.c`: replaced `INCLUDE_ASM` with the exact C body and truthful helper declarations.
- `src/promoted/code1_001a.c`: corrected the fourth-parameter declaration from `s32` to `s16`.
- `docs/probe_archive/E20B_0020b6d0_body.c`: replaced the historical 904-byte/nd519 candidate with the accepted 812-byte body and decisive declaration-order note.

## Rejected alternatives

- Old-style `func_00242800()` declaration: exact but ABI-unsafe.
- Truthful prototype plus `(s64)(s16)temp_18` at the call: broad register-allocation regression.
- Truthful prototype plus direct `temp_18`, original declaration order: thirteen executable register-color differences.
- Changing the provider to accept `s64`: incompatible with its authoritative `s32` definition and unnecessary.
- Padding the function to 816 bytes: prohibited; the missing word is retail alignment, not logic.

## Resume point

No further work is required for `func_0020b6d0` unless a future full linked-image check reports a regression. If that happens, begin with relocation/addend resolution and the current owner/compiler configuration; do not revert to the old-style helper declaration.
