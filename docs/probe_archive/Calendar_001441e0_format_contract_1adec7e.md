# Calendar display: exact `func_001441e0`

The prepared recovery replaces the guarded calendar display callback in
`src/promoted/code1_0014.c`. Its complete logical owner was compiled from a
snapshot taken after the SDK task-registration and HBN color-contract changes
on `1adec7e926b81497a86b3a4238ba57edfb780c2b`. Those changes are retained in the
proposal. Worker-3 did not edit production source.

The callback emits **2268 executable bytes in its 2272-byte retail window**.
All **109 relocations** are resolved, every executable byte equals retail,
and the remaining four bytes are zero alignment. This is a resolved-object
proof; the prime owns the subsequent live-source `tools/verify.py` run and
integration.

## State ownership and initialization

The actual creator is **`func_00144af0`**, not `00144b00`. It calls
`D_008873F4[0](1, 0x20, 0x40000)` and registers the returned work pointer with
`func_00451de0`, using `func_001441e0` as its update callback and
`func_00144ac0` as its destructor. The update receives the work pointer at
task offset `0x38`; the destructor frees that same pointer. The existing
`SdkTaskUpdate` declaration is `s32 (*)(u8*)`, which agrees with the recovered
callback.

The allocator is the RenderWare `rwcalloc` slot. In retail `_rwMemoryOpen`,
instructions at `0x003e1ba4..0x003e1bb8` transfer the supplied memory interface's
fourth pointer, at offset `0xC`, to `0x008873f4`. The default arm at
`0x003e1c08..0x003e1c18` installs `HCalloc` at `0x003e1b00` in that slot.
`RwMemoryFunctions` in `include/rw/plcore/bamemory.h` identifies its fourth
member as `rwcalloc` and requires zero-initialized elements. The default
implementation in `src/renderware/plcore/bamemory.c` forwards to `calloc`.
Thus the creator requests one zero-initialized, 32-byte state object; the
`0x40000` argument is the allocation hint, not the source of zeroing.

The recovered layout uses the whole real allocation:

| Bytes | Field | Use |
|---|---|---|
| `0x00..0x03` | `s32 kind` | Initialization state, then display state |
| `0x04..0x11` | `u16 a[7]` | First calendar column |
| `0x12..0x1f` | `u16 b[7]` | Second calendar column |

A union overlays these fields with `u16 words[16]`. During initialization,
`row = st->words + i` retains the row address across the calls, with
`row[2]` and `row[9]` storing the two results. For `i = 0..6`, these accesses
cover word indices `2..8` and `9..15`, all within the allocation. No storage
was added. Mode zero fills both arrays before setting `kind` to one. Mode one
returns `-1` when key bit `0x800` is set, otherwise displays the two columns.
Other modes return zero without initializing or displaying entries.

The three calendar provider declarations match their active definitions:

| Provider | Active definition | Contract |
|---|---|---|
| `func_001060b0` | `src/g_data/g_data.c` | `s16 (void)` |
| `func_00110850` | `src/promoted/code1_0011.c` | `s64 (s32, u32)` |
| `func_00110c50` | `src/promoted/code1_0011.c` | `s32 (s32, s32)` |

All four date queries per row remain. The third query is added to the day
index before the fourth query, matching the retail value lifetime. The first
two weather results retain their explicit signed-byte conversions before
packing into a halfword. The forecast result is stored as a halfword.

## Closing the remaining instructions and print contract

Scoped `opt_lifetimes on` had reduced the previous draft to a 32-word masked
residual. Retaining each row address and computing the third query's indexed
date before the fourth call reduced the fully resolved residual to two words.
Both were the order of the operands in an address addition for a displayed
halfword. Writing the actual 32-bit address as base plus byte offset preserves
the retail order for the two column loads.

An eight-byte position union holds two real `f32` coordinates and their
packed `s64` representation. It replaces the old read of eight bytes through
a pointer to a four-byte member. The columns remain at X coordinates five
and fifteen, with Y coordinates twenty through twenty-six. All fifty switch
arms and their original label mappings remain.

The first zero-word candidate still used a fixed two-argument print
declaration that disagreed with the real variadic provider. That candidate is
retained as a diagnostic only. The accepted proposal instead supplies the
shared declaration in `include/sdk_dbprt.h`:

```c
void func_00450050(s64 position, const char* format, ...);
```

The actual provider in `src/sdkDbprt.c` already interprets its second
parameter as a format pointer and forwards its variable arguments to the
formatting library. Changing that parameter from `s32` to `const char*` and
removing the obsolete cast preserves its complete **416-byte** retail body,
including all five resolved relocations. All source consumers use the same
header: the calendar owner, `src/promoted/code1_0046.c`, and
`src/Script/scrScriptProcess.c`. The latter's former fixed four-argument
declaration is removed. Two guarded `u8` format arrays receive explicit
`const char*` casts. A source search also checked the `H_Dbprt_FmtAt` and
`FUN_00450050` aliases; these four files are the complete authoritative C
owner set for this contract.

Keeping an integer format parameter changed the argument-preparation order
at all fifty calendar print calls. Literal-print inline wrappers, explicit
position snapshots, and aggregate wrappers did not close those differences.
The accepted pointer contract agrees on both sides of each real call and
does not invent arguments or narrow a provider to manipulate allocation.

## Complete-owner verification

The configured MWCCPS2 b210 compiler and each owner's configured flags were
used. Compiler hashes, flags, source hashes, object hashes, header copies,
configuration copies, commands, and logs are retained with the proof.

| Logical owner | Other function images unchanged | Allocated data sections unchanged |
|---|---:|---:|
| `src/sdkDbprt.c` | 7, including the print provider | 5 |
| `src/promoted/code1_0014.c` | 125 | 3 |
| `src/promoted/code1_0046.c` | 59 | 2 |
| `src/Script/scrScriptProcess.c` | 22 | 0 |

All **213 other function images** retain their bytes and canonical
relocations. Every allocated owner data section retains its bytes, size,
alignment, and canonical relocations. The target introduces no owned table
or data allocation: its code relocations refer to external providers,
globals, or label strings. The display switches use comparisons and branches.

Native semantic checks execute the verbatim recovered calendar body and the
verbatim pointer-format print-provider body in separate i386 translation
units. GCC 14.2.0 and Clang both pass **70,407 scenarios, 11,518,554 checks,
and 863 print calls**, with undefined-behavior traps enabled. These cover
4096 initialization inputs and call sequences, every 16-bit display code at
each row, guarded state and task storage, the key-bit exit and invalid
states, 512 variadic integer-and-pointer calls, and newline handling in the
real print provider. The platform type and `va_list` setup are native shims;
date/weather providers and the underlying formatter are modeled. The EE ABI
proof is the separate resolved-object comparison, not native execution.

Lint reports **zero errors and six H003 optimization advisories** across the
five proposed files. The new scoped lifetime setting has the measurements
above. No full project build was run by this worker.

## Artifacts and handoff

The immutable recovery root is
`build/first-party-resume-continue/fresh/worker3/calendar1441e0/format-contract/`.

`integration-native-eol.patch` passes plain `git apply --check` and preserves
the existing source line endings. `proposed-preserve-eol/` contains the same
proposal with those endings. Its text normalizes identically to the compiled
files in `proposed/`; `line-endings.json` records both hashes. The older
`integration.patch` is retained as a receipt: Windows text writing converted
that patch's line endings, so it requires whitespace-tolerant application.
Use the corrected patch for integration.

`proof.json` and `objects/*/comparison.json` contain the unmasked target,
provider, sibling, and allocated-data comparisons. `inputs.json` and
`inputs/` preserve the compilation inputs; their hashes were rechecked.
`contract-audit/` preserves the calendar providers, allocator evidence,
consumer census, and generators. `native/results.json`, native source
receipts, commands, objects, executables, and logs preserve both semantic runs.
`lint-findings.json` and `apply-check.json` record the final integrity checks.

The earlier material-color exploration at `00476e90` remains separately in
`material476e90/`. New material-stage and quantization-boundary probes tied
or regressed its baseline; no material source change is proposed. The HBN and
Y-list targets considered during coordination were released before compiling
or editing their owners.
