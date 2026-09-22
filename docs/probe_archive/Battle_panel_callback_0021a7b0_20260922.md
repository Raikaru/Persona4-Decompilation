# Battle-panel callback 0021a7b0: exact C recovery

The actual `src/promoted/code1_0021.c` owner compiles natively with MWCCPS2
b210, `-O2 -Iinclude`, and `tools/verify.py` reports `MATCH` for
`func_0021a7b0`: 1,712 emitted bytes in the complete 1,712-byte retail window,
all 21 relocations resolved without masking, and no alignment tail or new
owned data. The owner now has 103 `MATCH` and five `ASM` functions.

## Callback contract and source

`func_00200fd0` registers this callback at work offset `0x988` and stores the
panel-state pointer, `work + 0x8c0`, at `0x990`. The update function
`func_00200cf0` queues the containing node at `work + 0x980` through
`func_00460ac0`. Retail `func_0021a7b0` saves `$a1` as the state pointer and
loads the parent work from `0x10($a1)`; its first callback argument is unused.
The callback returns no value. Its definition and the sole authoritative
external declaration in `code1_0020.c` now agree:

```c
void func_0021a7b0(u8 *task, u8 *state);
```

The recovered body uses six existing `BtlShuffleSkyVertex` values. Their
64-byte stride, position, reciprocal depth, and floating-point color fields
match the retail packet accesses and `0x210` stack frame. The first vertex
cursor preserves the packet byte-address boundary before returning to the
typed vertex view. Subsequent vertices use array elements. The existing
`ws14_add` helper expresses horizontal edge additions, and `PackedVec2f`
provides the two existing position views required by the effect calls.

The change replaces the guarded draft and ASM fallback, removes the obsolete
floor reports and `NONMATCHING` tag, and removes the draft's common-subexpression
pragma. It adds no compiler pragmas, assembly, dummy state, padding, or private
callee contract changes. The historical draft in the probe archive remains a
record of the earlier floor.

## Native and official closure

The checkpoint was `2260985773b9b9c7b7a9aeb487ee0e2aa80f909f`. Before installation,
the retained `callback-ready` candidate was authenticated against its source,
native object, completed official receipt, configured compiler, flags, recursive
header dependencies, and fallback assembly inputs. The current owner matched
the published pair baseline exactly.

Two native full-owner compilations then closed the actual production paths.
Each official `tools/verify.py` run consumed its authenticated native object,
bound to the final source bytes and current compiler profile. Completed jobs
were not rerun to recover output.

| Owner | Official result | Preservation |
| --- | --- | --- |
| `src/promoted/code1_0021.c` | 103 `MATCH`, 5 `ASM` | All 107 existing siblings and their canonical relocations unchanged; all 108 functions equal the clean retained candidate. |
| `src/promoted/code1_0020.c` | 139 `MATCH`, 7 `ASM` | All 146 functions and their canonical relocations unchanged; complete native object unchanged. |

Every allocated data section is identical to its owner baseline. The registration
function `func_00200fd0` was also proved unmasked: 488 emitted bytes in its
496-byte window, eight zero alignment bytes, and 39 resolved relocations.

Artifacts under `build/finish-first-party-20260922/battle-panel/`:

- `callback-live/authenticated.json` and `installed.json`: authenticated
  baseline identities, coordinated contract, and frozen source hashes.
- `callback-live/code1_0021/completed.json` and
  `callback-live/code1_0020/completed.json`: actual-source native compilation,
  target proofs, sibling/data checks, and official reports.
- `callback-live/completed.json`: combined source bindings and explicit
  comparisons of all 146 caller-owner functions and all 108 candidate functions.
- `callback-live/lint.json`: zero errors and nine H003 warnings on existing
  optimization pragmas. `git diff --check` passed.

| Artifact | SHA-256 |
| --- | --- |
| Final `code1_0021.c` | `a8c7e7934ac46828518332073247cad6dc9a5b4052e2185dda6ff84ed22499f5` |
| Final `code1_0020.c` | `6138efd3811c7851d6c511549f9043237718b08df5d738c514ca5d703381aa33` |
| Native `code1_0021` object | `0016bec1a5d3721c3fe9aece09e857d2404b7c7951cc3d5cb91bd3306ddf03a3` |
| Native `code1_0020` object | `4a7834d70d043ad4bf87d8a7591fd47a7b438688965896038a1ba920bf823465` |
| Actual-owner `code1_0021` official report | `e6de64c6fd011797521e428ecd2793740de39d7cd3b4a190b29bb57d23b12f1a` |
| Actual-owner `code1_0020` official report | `2c2fadea04e149a31ae344edac3f694a407653489e3bc3c98497cee7a26b8c74` |
