# Runtime and menu symbol corrections

The PC runtime work identified these roles by executing the original ELF and
checking its calls against newlib source. Names describe PS2 entry points,
not native host wrappers. Assembly fallbacks keep their audited address names.

| Retail address | Role |
|---|---|
| 0035f0c0 | `cmpConfigStepInput`: Camp Config input/state machine, not Community detail |
| 0035e820 | `cmpConfigDestroy`: Config task teardown |
| 0035dfb0 | `cmpConfigDrawOnOff`: stock ON/OFF pill/slash widget |
| 00124830 | `titleSelectMenu`: title selector, not a music-stream controller |
| 0043c6b0 | `atoi`: signed base-10 parser result truncated to signed low 32 bits |
| 0043c710 / 0043c738 | `calloc` / `_calloc_r`: current-reent wrapper / zeroed allocation core |
| 0043ece8 / 0043ef80 | `malloc` / `_malloc_r`: current-reent wrapper / allocation core |
| 00441558 / 00441580 | `realloc` / `_realloc_r`: current-reent wrapper / resize core, not `__pool_realloc` |
| 00443fd0 / 00444210 | `_strtol_r` / `strtol`: signed 64-bit long parser / current-reent wrapper |
| 00444240 / 00444458 | `_strtoul_r` / `strtoul`: unsigned 64-bit long parser / current-reent wrapper |
| 00443068 | `_strtod_r`: reentrant binary64 parser |
| 00442100 / 00442188 | `sscanf` / `_sscanf_r`: string FILE scanner entry points |
| 00446108 | `__svfscanf_r`: reentrant scanner core |
| 004447f8 / 00444870 | `vfprintf` / `_vfprintf_r`: FILE formatter / reentrant core |
| 00445dd0 / 0043ca70 | `cvt` / `_dtoa_r`: formatting conversion / decimal digit generator |
| 00446e88 / 00446ed8 / 00446f30 | `vprintf` / `vsprintf` / `_vsprintf_r` (the latter is not dtoa) |
| 0044ba00 | `__floatdidf`: signed64 to binary64 |
| 0044bb60 | `__fixunsdfdi`: binary64 to unsigned64; existing name is correct |
| 0044bc68 | `__fixdfdi`: binary64 to signed64 |
| 0044e830 | `__fixunsdfsi`: binary64 to unsigned32, not unsigned64 |

EE `long` is 64-bit, pointers are 32-bit, and the scanner's `%lx` stores
8-byte destination slots. Native guest-pointer slots and raw binary64 bit
containers are port ABI details, not types to transplant into PS2 source.
The integer parser's end pointer is a `char **` on PS2, not a host pointer
slot. Saturation scans the full digit sequence and sets reentrant errno 34.
`atoi` intentionally discards the parser's high word.

The Config and title names are behavioral inferences. Their matching bodies
are unchanged; PC settings rows, shortcuts, touch input and other extensions
remain exclusively in the port.


## CRI entry-point ownership

| Retail address | Role |
|---|---|
| 004eb318 | `criConfigureVoiceCounts(stereo, mono)`: configure the voice pool, not a lock |
| 004cd470 | `criSetVoiceCounts(stereo, mono)`: forwards both counts |
| 004f1278 | `SVM_TestAndSet`: the actual test-and-set entry |
| 004c3bd0 / 004c3c00 | `ADXB_GetNumChan` / `ADXB_GetFmtBps` |
| 004ceda8 / 004cf018 | `ADXSJD_GetNumChan` / `ADXSJD_GetFmtBps` |
| 004c1c50 / 004c1d10 | `ADXB_SetAhxInSj` / `ADXB_AhxTermSupply` |
| 004f5860 | `RFMAI_CnvU32plusU32toS64`: join the low 32 bits of high/low words |

The unmarked RE4 `MWSFSVM_TestAndSet` convenience wrapper is not the retail
owner of `004cd470`. Channel count and format bits-per-sample similarly have
distinct entries; correcting one must not rename or displace the other.
The word-packing helper returns an explicit `s64`, not a host-dependent `long`.
Its assembly shifts discard both input registers' upper halves, so the source
interface takes two `u32` words. The inverse takes a complete `u64` bit pattern
and two `u32 *` output slots.


The four ADXT metadata APIs have lock/unlock wrappers and distinct inner
getters. Their roles are established by the retail call targets and the
literal error names, not the inherited RE4 marker labels:

| Public wrapper | Inner getter | Role / inner callee |
|---|---|---|
| 004d4bd0 `ADXT_GetSfreq` | 004d4c08 `adxt_GetSfreq` | sample rate, `ADXSJD_GetSfreq` at 004ced90 |
| 004d4c58 `ADXT_GetNumChan` | 004d4c90 `adxt_GetNumChan` | channels, `ADXSJD_GetNumChan` at 004ceda8 |
| 004d4ce0 `ADXT_GetHdrLen` | 004d4d18 `adxt_GetHdrLen` | header bytes, `ADXSJD_GetHdrLen` at 004cf010 |
| 004d4d68 `ADXT_GetFmtBps` | 004d4da0 `adxt_GetFmtBps` | encoded sample width, `ADXSJD_GetFmtBps` at 004cf018 |

The corresponding error literals at 00758cd8, 00758d08, 00758d38 and
00758d68 name these four inner getters in that order. The sample-rate and
header-byte getters must not be interchanged merely because legacy source
names cancelled a wrong address alias. Decoder metadata accessors use their
actual handle and field types rather than a four-GP reconstruction wrapper.


Fresh fallback assembly is canonicalized against `asm_symbol_baseline.txt`,
the same pinned names used by its scratch split. The live recovered-name table
can rename or reuse a symbol, so it cannot safely undo the pinned extraction
spellings. The regression test covers both cases. All audited fallback output
hashes remain required; no checksum or comparison threshold is relaxed.


The SFXZ text metadata reader retains `%lx` and uses eight-byte `Uint64`
destination slots, matching retail `sscanf`. It explicitly consumes the low
words of the decoded data/size fields. The element offset is the signed low
word of the 32-bit multiplication, not an unsigned pointer offset; retail
`0052c244`/`0052c248` sign-extends that word. This preserves negative and
wrapped offsets without changing the format strings to a host workaround.


## Allocation widths and forwarding results

Allocation counts and sizes are unsigned 32-bit words, as are guest pointers.
The malloc/calloc/realloc wrappers load the active reent from `00710070`.
At `0043c748`, `_calloc_r` uses the low word of `mult` as the allocation size;
it does not perform a checked or wide multiply. Zeroing follows the original
chunk's allocator-usable extent. `_realloc_r(NULL, size)` allocates, while size
zero normalizes to a minimum chunk rather than freeing. The cores retain
their audited assembly; a native mspace implementation is not PS2 source.

RenderWare's three default allocator forwarding callbacks now return the real
pointer and state numeric size/count inputs. The boot budget probe and memory
checker use the shared allocator declarations, with explicit address-word
casts where their existing bookkeeping stores a 32-bit allocation address.
All 52 marked functions in the four affected units retain the retail bytes.

Vector normalization returns an `f32` length even at call sites that ignore
it. Eleven existing void declarations now state that result, and one unused
void declaration is removed; their parameter views are unchanged. All 295
marked functions in the twelve affected units retain the retail bytes.


The debug formatter's two register-save-area callers now use the real integer
`vsprintf` result declaration and a shared string-format prototype. Their
existing PS2 argument-list construction is unchanged; host native va_list
adaptation remains a port responsibility. All four marked functions in that
owner retain their retail bytes.

## Word packing and kernel status words

The `004f5860` high/low join now has a real C owner in
`src/sce/rfmai_wordpack.c`, isolated from the mixed original `rofs_mai.c`.
Its unsigned 64-bit shift and addition retain exactly the low 32 bits of
each input and return the full signed 64-bit bit pattern. The original
EE-GCC 2.96 compiler emits retail's five live instructions, including the
addition in the return delay slot. MWCC emits two redundant high-word
extension instructions; a signed-widening cast changes one opcode but does
not remove them. This is compiler ownership, not a reason to widen the public
inputs or keep a duplicate native implementation.

The EE `fstat` stub at `00421f98` takes an ignored signed descriptor, not a
path pointer. Its fixed device-mode word and 64-bit size-zero store are
unchanged. `kill` at `00421fb8` takes a command and a signed status word;
command one forwards the status through `0042c0d8` to syscall `00421400`.
The same status contract belongs to `kwlnExitRuntime`. These declarations
share `sdk_process_internal.h`; they do not describe host POSIX calls.

The complete six-owner witness reports 206 active C matches and 323 unchanged
assembly-backed functions. The word-packing helper is newly active matching C;
the other assembly entries are not claimed as new reconstructions.

