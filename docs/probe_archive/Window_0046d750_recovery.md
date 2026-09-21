# Window task recovery: func_0046d750

The ordinary-C implementation in `src/promoted/code1_0046.c` replaces the
guarded assembly fallback for the window animation task. The immutable
delivery compiled on 2026-09-20 proves 4,244 executable bytes against the
4,256-byte retail window and proves the complete 36-byte, nine-entry switch
table. The twelve omitted bytes are zero alignment after the final return
delay slot. This is an independently resolved owner proof; the prime owns
fresh official verification, whole-tree integration, and publication.

## Source and compiler identities

All paths below are relative to the repository root. The complete source,
object, compile receipt, resolved target bytes, relocation records, sibling
comparison, and proposed patch are retained in
`build/first-party-next/window/delivery-final/`. The owner was checked again
against these identities when this note was written; no completed compile
was repeated.

| Artifact | SHA-256 |
| --- | --- |
| `src/promoted/code1_0046.c` and `delivery-final/code1_0046.c` | `cd5fc3a379ba52d91d8e6f06dcf78273d436023a02f37b8ebc9e1c4d3a3d9bbb` |
| `delivery-final/owner.o` | `90396dfbe534f40e286efd416cbf2e9dfd379cb3b60cac0792fa205a2e2eeed7` |
| `delivery-final/compile.json` | `3b60a5c47de1eef657f81580b184758a8394102ac84f11ff199c12243139e93a` |
| `delivery-final/result.json` | `f19eb0ffec6b36843ad852c52a69e8fd139e239874fa0238e01455d8267ebae2` |
| `delivery-final/proposal.patch` | `74a3ee1c2a7c02661530e0e88cd673b2ce58131394292db71e66d525882743c2` |
| MWCCPS2 3.0.1 build 210 executable | `286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7` |

The configured compiler was `D:/mwcps2-3.0.1b210-060308/mwccps2.exe`.
Logical owner flags were `-O2 -Iinclude`; the actual invocation redirected
the include path to the immutable `build/first-party-next/window/inputs/include`
snapshot. `tools/probe_variants.py` selected the owner's compiler and flags
and held its owner lock. The input manifest records header hashes and compiler
identity. Source-local controls are scoped `opt_propagation off` and
`opt_lifetimes on` around this function.

## Resolved code and owned data

`result.json` contains the complete relocation records. Neither a masked
zero nor an instruction-alignment score is the acceptance test.

| Proof component | Result |
| --- | --- |
| Emitted executable prefix | 4,244 bytes, exact after all 14 code relocations |
| Retail window | 4,256 bytes at `0x0046d750` |
| Omitted suffix | Twelve retail zero bytes; no omitted executable instruction |
| Raw executable SHA-256 | `99002b95f89bd285c524962b27f6c519f29962d20365e9722dc07da883922fee` |
| Resolved executable SHA-256 | `b9e0bd211cdc1372793bc7b15af682c7763b461c52ffa3e9c788c44d668c8e91` |
| Owned switch table | `.rodata`, section index 203 in this object, 36 bytes, alignment 16, retail address `0x00756790` |
| Raw table SHA-256 | `d1bc4332639b818fcc582348d34796cf53c15932aa2b2794af0cdf508a0ade04` |
| Resolved table SHA-256 | `7374cf150379804f1ba51163837f2bfa3f7095657256c6cea34772a215405928` |

All nine table entries have `R_MIPS_32` relocations to the task's corresponding
case offsets. The proof resolves the entire table at its retail address and
compares all 36 bytes. A section index is an identity within this particular
object, not a permanent exclusion for later objects.

The preservation comparison covers all 58 non-target functions, checking
both raw instruction bytes and canonical relocation identities. The original
allocated-data inventory must equal the candidate inventory after excluding
only the newly generated, independently proved target table. This comparison
includes section sizes, alignments, bytes, and relocations. A successful target
proof cannot excuse changes to another function, an existing literal, or
unproved new data.

The protected state-save/restore function `func_004601c0` is separately proved
at 784/784 bytes with no omitted suffix. Its resolved executable SHA-256 is
`8eeba037cb5cad29334f29a248ea74c87ee61aeb787b9ae0ec798eb00e849b6b`.

## Behavior and provider boundaries

The task obtains the work object at `task + 0x38`, animates its border and fill
vertices, and submits five four-vertex primitives when the window is enabled
and the camera begins updating. `func_0046e850` allocates the 0x560-byte work
object and registers this task with the existing `s32 (u8 *)` callback
interface. Case 6 calls `func_0046ea60(task, work + 0x0c)` with the four-word
rectangle required by that helper.

The new task's render-state setter is `s32 (RwRenderState, void *)`, matching
`RwRenderStateSetFunction` in `include/rw/plcore/badevice.h`. It is accessed
through the native static `ourGlobals` device member. The PS2 declarations in
`include/rw/ps2/ostypes.h` and `include/rw/plcore/balibtyp.h` place `RwDevice`
at instance offset 0x10 and its setter at instance offset 0x20. The resulting
address is `0x00887300`, as in retail. This follows the member access used by
`RwRenderStateSetMacro`; it does not reinterpret the callback through an
incompatible function type.

The direct Sky setter is declared `s32 func_003f6440(s32, void *)`. Every call
and declaration of that function in this owner uses the coherent payload
type. The camera begin/end declarations are `u32 (u32)`, matching the existing
providers in `src/rw/rwcore_grouped.c`. The immediate primitive callback keeps
its existing `s32 (s32, void *, s32)` interface. Its five submissions use
`(4, work + offset, 4)` for offsets 0x460, 0x60, 0x160, 0x260, and 0x360.
The audited source, retail assembly, IDA/Ghidra hypotheses, and provider
references are frozen under `delivery-final/evidence/` and indexed by
`delivery-final/audit.json`.

The source changes preserve the retail case-5 loop boundary and the case-7
inner-counter initialization order. The final case-7 condition retains the
two tests of the same loaded alpha byte that appear in retail. The source
uses ordinary C with the documented compiler controls; it adds no synthetic
side effect, volatile/register forcing, instruction padding, or ordinary
inline assembly.

## Related unfinished work

The broader migration of the existing `D_00887300` and `D_00887304` aliases is
separate from this recovery. Changing the setter signature throughout the
owner still moves four words in `func_004601c0` at offsets 0x2ac through
0x2b8. Giving the getter its native signature additionally moves three save
words. Six explicit-load/conversion consumer-boundary experiments completed
in this lane preserve those residuals. They are retained in the
`legacy-get-named-*` and `native-get-named-*` directories, with identities in
`delivery-final/audit.json`. The accepted owner preserves the existing exact
save/restore implementation and uses the native member directly for the new
task.

`func_0046f2b0` remains guarded. The saved follow-up in
`build/first-party-next/window/f2b0/` models its real four 16-byte rectangles,
12-byte analog vector, and eight-byte callback argument descriptor. Retail
clears these objects by bytes; the old draft cleared through word or float
pointers and relied on separate scalar locals being adjacent. The registered
entry callback is `void (void *)`, established by `func_00470a90` in
`src/Kosaka/k_view.c`; the draft supplied an invented second argument. The
initial corrected candidates are not exact and are not included in this
recovery's count. Continue from their saved disassembly and receipts.

`build/first-party-next/window/final_delivery.json` consolidates the accepted
proof and the initial follow-up evidence. The completed owner installation
also passed `git diff --check`. This worker performed no commit, rebase,
provider/header edit, full build, or whole-tree gate for this delivery.
