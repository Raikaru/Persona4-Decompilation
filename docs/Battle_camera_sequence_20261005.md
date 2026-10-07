# Battle camera sequence and coherent packet contracts

## Result

`func_001b4880` verifies **MATCH** in its complete configured MWCC b210 owner.
The source guard and ASM fallback are removed. The five-owner scope is now
**368 MATCH / 7 ASM**; all 374 other functions preserve their instruction bytes,
canonical bindings and allocated data, including the previously published gains.

- Final owner SHA256: `75db06b98cdf9e507b03af00882488a28844e09d6542382b001aa10d20356360`
- Whole-owner object: `77fcfc50cb13a18c9123b7340a2ecaa8b4775a40a4d0d923c05d1b41e896cb8b`
- Exactly 2688 executable bytes, frame 0x90, zero fully resolved differences
- All 75 references and 47 calls in order agree with retail
- All 122 siblings and the owner's allocated data preserve
- Return at 001b52f8 and its executed delay slot at 001b52fc are included; no tail

Full-project cold-build, retail-image and publication checks are separate gates.
This report does not claim publication or a successful remote CI run.

## Faithful source closure

The final source uses strict integer bounds (`x > n-1`) equivalent to the prior
`x >= n` over the complete unsigned-halfword/masked-count domain. Transition
packet/delay, group packet, movement packet and each traversal have real completed
lifetimes. Every value has its actual producer before use; no dummy use or padding
is introduced. The group packet remains the dependency across optional voice
creation, and callback/group/movement UIDs remain live reads at their real uses.
The initial dead-unit factory freshly reads the node's unit after the predicate.

The color phase first writes all four normalized components, then all four ambient
components, then multiplies matching channels in place. Result and base may alias:
each statement reads its channel before writing it, and later statements use
other channels. The ambient record is distinct. Quantization retains the ordered
normalized-channel product, product-times-255 plus half-step, integer conversion
and byte store. All packed bytes are initialized before whole-word use.

The SDK reciprocal has bits 0x3b808081. Its existing .lit4 binding at 0x7612e4 is
proved through actual unchanged sibling sites and payload bytes, not by value
alone. Palette bytes are 0..255, giving bounded finite normalized values and
products; quantization is within s32 and byte range. Exact final EE instructions
confirm the floating-point/ACC operation graph in addition to source reasoning.
All four palette calls and selected-byte sampling remain. The quaternion copies
retain all four lanes, including W, in a genuinely used aligned 16-byte record.

No fabricated ABI, arbitrary initializer, volatile ordinary memory, ordinary
computation assembly, undefined shift or new compiler pragma is used. Helper/type
names describe recovered behavior; they are not claimed to be original symbols.

## Necessary finite contract repair

The first three `func_001b83f0` inputs are opaque packed words. Its coherent family
is `BtlPacket *(s32,s32,s32,u32,u16)`: signed raw carriers are explicitly converted
to u32 for the existing four-byte interpretation. No whole-word signed arithmetic,
comparison, shift or indexing is performed. Frames remain u32 and flags remain
u16. The return is the actual allocated packet.

Two matched callers use s32 locals produced by the actual s32 getter/output
queries. Their separate unsigned `func_001b7880` boundary retains explicit u32
conversions. This avoids moving the previous three-word argument-order regression
from one matched caller to another. All five actual color callers and declarations
are coherent. Their calls, sampling, flags and allocation behavior are unchanged.

The configured compiler witness preserves every low 32-bit pattern for conversion,
round trip and store. Its sign-bit-clearing negative fails the identity property.
The fresh witness object is byte-identical to the earlier accepted witness. This
is target-specific evidence for C's implementation-defined unsigned-to-signed
mapping, not a portable-C or sampled-all-2^32 claim. Signed-to-unsigned interpretation
is the defined modulo-2^32 conversion.

The three packet factories 001ba530, 001ba710 and 001d3b50 return their genuine
allocator results; the third stores a real action pointer. Each has exactly one
retail direct caller, this controller. Sound-stop 001eb7f0 is coherently void(void)
across six callers because it reads no incoming argument. Removing that unused
argument preserves published 001b2380: its preceding real flag store already leaves
the same pointer in the register. No register-maintaining dummy operation is added.

The five changed owners are btlMain, btlFormation, code1_001a, code1_001b and
code1_001e. Four whole production objects remain byte-identical to public 9938a483.
Only the target and compiler-internal literal naming change in code1_001b.

Precisely admitted sibling reference-name changes are:

- 001ba0e0 offsets 288,356,484,552,680,748,876,944: @1870 to @1310,
  same four bytes 8180803b at 0x7612e4
- 001be990 offsets 1376,1456: @2849 to @3058,
  same four bytes 9a990940 at 0x761220

Every site is individually checked. All other non-target raw reference rows agree;
there is no blanket symbol-name exception.

## Defined boundary and ordinary native tests

The admitted domain has valid initialized work, battle, action and unit records,
bounded terminating lists, successful allocations, complete quaternion inputs in
the SDK's finite numeric domain and actual byte colors. The real packet allocator
clears its complete 0x90 header plus work size. The queue writes complete 64-bit IDs.
The unit constructor clears its complete record and the actual rotation setter
writes all four lanes. The default quaternion and axis are initialized constants.

Exact extracted controller/helpers, allocator, factories, color provider,
sound-stop, wait callback and rotation setter bodies execute in native tests.
Complete packet/work bytes, guards, all flags, untouched work fields, wide IDs,
input routes, timing boundaries and submission order are checked.

Fresh post-recovery tests on the final source pass at O0 and O2, zero skips:

- Controller: 2464 ordinary plus 192 explicitly labeled provider-model cases per
  optimization; 5312 total executions; all 28 mutants reject at both levels
- Packet/sound: 4014 factory calls through the real allocator and 5696 sound-stop
  calls total; all 31 semantic controls reject at both levels
- Color provider: 18564 provider calls and eight real callback smoke paths total;
  all 14 semantic controls reject at both levels
- 29 unittest methods; 154 retained native execution records; 146 ordinary
  assertion rejections; 19 interface records, including 15 compile-negatives
- All three color helpers are included in the finite caller census; 12 inserted
  helper-call controls and four duplicate-definition controls reject

Crashes, sanitizer traps and compilation failures do not count as semantic-control
passes. Exact source strings and retained executable hashes bind the rerun records.

The actual death predicate and palette getter are pure. Mutating node pointers,
live IDs and palette data are separately disclosed provider models for observing
sampling, not claimed normal engine behavior. Quaternion composition, dispatch and
other engine boundaries remain explicit seams. There is no all-assets, complete
SDK numerical or transitive whole-engine definedness claim.

## Recovery and reproduction

An executor reset removed private build artifacts before publication. The final
production owner, all prerequisite owners, header and seven test/fixture files
were recovered byte-for-byte to their pre-reset hashes. All scoped compiler and
native gates were then rerun from restored authenticated tools and retail inputs.
Lost execution artifacts and unrecovered intermediate experiments are not presented
as current evidence. Preserved final source and compact fresh receipts are here.

The production validator uses only public base 9938a483 and current source files.
It rejects a target ASM fallback, checks all 374 other functions strictly, resolves
every target relocation and requires complete 2688-byte equality, including the
return delay slot. Outputs contain private compiled artifacts and must not be
committed:

```
python docs/probe_archive/battle_camera_sequence_exact_20261005/validate_production.py <private-output-dir>
python tools/verify.py src/Battle/btlMain.c src/Battle/btlFormation.c src/promoted/code1_001a.c src/promoted/code1_001b.c src/promoted/code1_001e.c
```

The native contract tests used during this recovery were removed on
2026-10-06; the verifier and full link are the current gates. Scoped lint
has zero errors and 110 inherited owner warnings; none is in the changed target.
Licensed compiler/ELF inputs, objects, executables and full instruction listings
remain private.
