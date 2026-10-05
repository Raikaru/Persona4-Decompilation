# Wave 0048b9e0: actual-domain audit, 2026-10-05

## Result and scope

**The recovered rank56 Wave controller is admissible for caller-only register/allocation diagnostics on the bounded actual constructor → first-dispatch reset → spawn → live-update domain below. No direct local, primary-particle, state, or memcpy-source unwritten read was found.** Preserve all three separate complete 16-byte local objects, the two real W producers, the real providers, and the production NONMATCHING/INCLUDE_ASM guard.

The inherited 0048b340 trail-history hole is real but remains confined to disjoint trail storage, which this controller does not read. This report does not certify the whole effect engine, every resource, every callback replacement, the provider's own C-definedness, or arbitrary fixture-seeded live particles. It does not authorize adding initialization, padding, objects, provider behavior, or guards to improve a score.

Read-only audit: STYLE read; no compilation, test execution, source edit, upload, publication, or MATCH claim. Only this report was written. The reported lost 2652-byte/59-edit/69-masked-word candidate was not recovered or measured by this audit. The source reviewed here is the freshly recovered older rank56 body; source review does not reproduce its historical code-generation score.

## Exact source and retail bindings

Public source baseline: `90f7c9c8321347f7fa6b572183a7edc33205a7de`, inspected with `git show` in `p4-thunder-rows-match-20261004`. Local checkout HEAD is `fa980eedbd5732a5f986d27166c525503b0f94dc`; it is not being mislabeled current90.

Recovered source reviewed:

- `wave-register-review-20261005/recovered/wave-rank56-reconstructed.c`: SHA256 `03da8870eae426622f61640392083211508c674fc597c91ef991a470f824abaf`
- Complete function text, from `void func_0048b9e0(` through the closing brace, excluding the following newline/pragma: 10006 bytes, SHA256 `5d07c7231ee7496e37f3784399efcffd0015ee03b4def8df86317cba5db2d218`
- `recovered/headers/rank56/particle_spawn_internal.h`: SHA256 `02a2a7b22e72c9bfb67e0f397c7ab05a0fbe43461d4ee6dd1feca901a003d126`
- Actual shared `include/effect_vu0_internal.h` used as the helper reference: SHA256 `17950fb770d93dfff1457cbe5684eb281500c1e70d972fd94e4c2622b502e5dc`

Parent's recovery provenance: complete new-text Wave hunk in recovered rank55.patch, plus rank56's precise three-vector declaration-order change. The final report's source conclusions are bound to the bytes above, not a conjectural newer source. Current90's older function text is 10146 bytes, SHA256 `f35c000850467734b0cc1beff0931ce455db78da41f5c5654e3275186ad38c3e`.

Current90 Git blobs inspected:

- STYLE `48da0b49de64d467500d11c2a5cbdb4376fecb5e`
- `src/promoted/code1_0048.c` `62a0720be8e1ded1e7be678a40917302a0db4001`: target, attributes 0048b220, trail 0048b340, general update clients 00489e00/80, scale callback 0048c440
- `src/promoted/code1_0049.c` `10703b64a4589d6cc2c601b70d60036c7c26e807`: constructor 00492b20, free 00492cd0, reset 00492d00, dispatcher 00492d10
- `src/Graphics/Effect/effMisc.c` `4e61bebc6244fb89b4c8e9e2967f219480281cdf`: matrix 004bceb0 and real RNG
- `src/promoted/effParticle.c` `0b496b04884722932d8c19a91975279adb896006`
- `src/promoted/effPolygonTrack.c` `23bdc1fc6fdf7da03a6aa63c7947352dabaf8b23`
- `src/Graphics/Effect/effObjectParticle.c` `28186b77ee0d79e09ff922f240631bd99d8c1071`
- `src/Graphics/Effect/effDistortParticle.c` `fa0471f2e7015d19345f2029405a628b56343f03`
- `src/Graphics/Model/mdlEffect.c` `4b4c08579689c700ab3fe0ca6a75c7072df23ff3`: actual projection 0048a460 and complete position/quaternion getters/setters

Authenticated retail: `p4-recovery-20261003b/private-inputs/SLUS_217.82`, freshly SHA1 `4eeec0360cf2715535d9f7e52eb69d786fb0158c`, SHA256 `f90675b8a38138ddb5dc5cdf641550f41800fcb86bb499c586073e964fb41836`. ELF32 PT_LOAD maps file offset 0x80 to 0x00100000, filesz/memsz 0x838a00. Relevant raw windows were freshly disassembled with the existing PS2-capable objdump.

Fresh window SHA256 bindings:

- Target [0048b9e0,0048c440): `f6e4290c4d449628594bcacb4a080f83185a90542ef2c8c8c44c32170dcc8efc`
- Constructor [00492b20,00492cd0): `bb0740d0a12f29f3f80ee354fa7d9399bd4278138781dfe80b474ed5e8b86698`
- Reset/dispatch [00492d00,00492db0): `703745e262c6acc37be4520ea1049d97a42facc0426c4edb18090ed07c8b87e6`
- Matrix [004bceb0,004bcf20): `055e94f12780b4eb6bbab0c24315015b47c22f4e8627d6ac7908e45f69e035ed`
- RNG pair [004bd050,004bd130): `8543c185f7a76b6c62fc03ab0016d4e6bd366264029b37483a266b4823461a36`
- Attributes [0048b220,0048b340): `9f2ae9c7b8ad1358ed91b3d35654053cf29f17d0d263d2a91de79e951735c29f`
- Trail [0048b340,0048b9e0): `b481e729c3d7f65c3c354b4b3efdb576fc15503037efa019174ee9881727ca76`
- Projection [0048a460,0048a510): `180838399912617a7b4a8f59ace19bbb7973771d3686194f4fdc6cd837cda97a`
- Optimized point transform [00402410,00402470): `6f1731f7faea58ad0057a2cb891c18dd8f19171123aab2bb95171365a967c296`

Retail target frame is 0x140. The symbol window is 2656 bytes: restore SP at 0048c430, `jr ra` at 0048c434, required delay-slot nop at 0048c438, and one padding word at 0048c43c. Its executable extent including the delay slot is **2652 bytes**, not 2648. A score that strips trailing zero words must not silently drop the architectural delay slot.

## Kind-specific objects, capacity, and lifecycle

Fresh dispatch entry at **00713d60, kind 1**, is `[0048b9e0,0048c440,60,240]`, raw bytes `e0b9480040c448003c000000f0000000`, SHA256 `05b95462f73eadf098667f8d6bef1b9688fbc67153fcc59e18912eef358b18ad`.

For primary count P, trailCount C, trailWidth W, and H=C*W, constructor 00492b20 allocates:

`48 + 32*P*(H+1) + 2*240 + 60*P` bytes

The actual order is emitter48; particle array `P*(H+1)` records of32; current parameters240; original parameters240; state `P` records of60. Retail live increments are state+60 at 0048c3cc and particle+32 at 0048c3d0. **Wave state allocation equals its live stride exactly.** Do not reuse Sphere's 232-byte parameter/state-allocation anomaly here.

Recovered layouts match these extents: SpawnParticle is 32 bytes with complete XYZW16, age4, color4, size4, angle4; WaveSpawnState is exactly15 floats/60 bytes; WaveSpawnParameters ends at phaseStepVariation+EC and is240 bytes. Wave's parameter records are both naturally16-aligned because240 is a multiple of16. State only requires scalar4 alignment: +60 does not preserve16 alignment and is not license for full-vector state loads. Emitter unknown02 and unknown2c are not read by Wave and need not be invented producers.

On the installed allocator path cited in the completed Sphere audit, 0044ec60 returns aligned payload: fresh retail 0044ed3c..54 rounds the payload to a16-byte boundary. Its metadata/back-pointer stores do not clear the user allocation; the prior documented malloc/smallbin reuse path is not an implicit zero-fill contract. This audit freshly rechecked the wrapper alignment and metadata and the retained-payload smallbin instructions, rather than assuming freshly allocated particles start zeroed.

Constructor 00492c14..4c installs pointers/counts, flags=0, ticks=0 and accumulator=0, then copies all240 bytes of the caller parameter object twice. It writes full VF0 vectors to current position and quaternion at 00492c7c/80, and derives local-space flag from byte+BC. It does **not** initialize particle payload or state. First dispatcher tick writes age=-1 to all totalCount particles at 00492d44 before invoking Wave. Reset00492d00 only resets ticks, causing the same dispatcher age reset. Free00492cd0 uses the saved allocation pointer+28.

Real general clients 00489e00 and00489e80 use dispatcher00492d10 before the rendering/update work. ObjectParticle004aec80, DistortParticle004b0a80 and PolygonTrack004938e0 similarly dispatch the installed controller. Replacement installer004875d0 frees the old controller first; constructor itself is the owner of this coherent allocation.

General resource constructor00486b00 derives P from emissionDuration-or-lifetime times emissionRate and caps the resulting unsigned value at300; direct00486a50 accepts a supplied count. The cap does not validate the earlier multiplication or parameter byte extent. ObjectParticle/DistortParticle/PolygonTrack installers004ae930/004afb10/00493820 assert when parameter+C0 is nonzero, so their intended ordinary domain has no trails. General004875d0 permits trails. No census establishes which shipped kind1 resources choose positive trail dimensions.

Complete current position/quaternion writes are also provided by actual00492dd0/00492e10, which copy16 bytes from the real caller-supplied object. Thus updates using them require a complete valid16-byte input, not an invented XYZ-only wrapper. The constructor-only path already provides both complete records. Scale callback0048c440 reads initialized original parameter fields and writes selected size/spread/speed/gravity/amplitude fields; it does not supply a missing local/state initializer.

## Direct initialization proof

1. **Entry and skipping:** lifetime is read/tested at0048ba50/54; zero returns before any vector/state use. A constructor-created age=-1 reaches only spawn or skip. -2 entries skip. Zero count reaches no body. An arbitrary externally fabricated live age without the spawn-produced state is outside this proof.
2. **spreadVector16:** retail writes W=0 at0048ba70 (stack+12C) before the loop; XYZ are all written at0048bf40/44/48 before the first full load. Recovered `spreadVector.lane[3]=0.0f` is a real retail operation. Do not remove it or replace the object with XYZ.
3. **direction16:** the world-space up-direction path stores all16 bytes at0048bd7c before scalarXYZ extraction. The local path never reads that old local. Both paths next assign randomized X, zeroY, randomized Z, zeroW at0048bdac/b0/c8/cc before full load0048bdd4. XYZ normalization preserves the supplied W; full store0048be14 defines all lanes for later spawn-position multiplication. Do not narrow this full object or rely on an unwritten W.
4. **state60:** every consumed float is written on spawn: direction[3] at0048bd4c..54 or0048bd84..94; waveDirection[3] at0048be1c/24/2c; speed at0048be5c; amplitude/amplitudeStep at0048beb8/d0; phaseStep at0048bf00; phase/previousSine at0048bf14/20; sizeScale at0048bfbc; angleOffset/angleScale on every mode arm0048bff8..0048c058. The live branch only uses those produced fields. No constructor state-zero assumption is needed.
5. **primary XYZW and age:** full position store0048bf94 initializes16 bytes. Age=0 is stored0048c05c, with valid preroll age replacing it at0048c1c4 when applicable. Subsequent position changes write onlyXYZ and preserve the already initialized W.
6. **previous-position snapshot16:** full 128-bit copies at0048c064/68 and0048c288/8c initialize b220buf before either attribute call. It preserves pre-preroll or pre-live-update position, including W. The provider's eventual XYZ arithmetic does not justify shortening the copy or merging its live storage with direction/spreadVector.
7. **primary32 before memcpy:** actual0048b220 writes color4 at0048b25c, size4 at0048b274, and angle4 on every branch. Wave's size/angle postprocessing reads those outputs. Its only memcpy at0048c25c therefore reads exactly32 fully written bytes from the current primary: XYZW16+age4+color4+size4+angle4, with no padding or unwritten tail. This is an actual-provider proof, not a seeded fixture argument.

Recovered source preserves all these operations. The three named locals are genuine complete nonoverlapping objects, not a frame-shaped union or dummy padding. The corrected recovered `memcpy` declaration returns `void *`, uses const source and u32 size, agreeing with the target ABI; the actual implementation returns destination and copies exactly the requested bytes. The ignored return is not a live-value trick.

## Real provider outputs and live register dependencies

**Quaternion basis:** 004bceb0 consumes full quaternion VF10; it writes all XYZ components of VF28..30 and explicitly writes each W=0 at004bceb8/bc/c0. Constructor identity quaternion is complete `[0,0,0,1]`. Axis00713d30 is a real16-byte read with retail contents `[0,1,0,0]` (SHA256 `6855960ee428276148fc8745625c44bde7ae835a9e2fa181cc917af9bcad0d6a`). Under finite arithmetic, the world-space direction transform therefore has defined W=0. Keep the actual global load and helper, not a folded synthetic substitute.

**RNG:** actual004bd050 mutates only explicit/default RNG state;004bd0b0 masks to24 bits and divides by2^24, producing values in[0,1). The full pair has no COP2 operations and cannot clobber the basis. Its static default state has a real loader producer; the code does not read caller-fabricated scratch bytes. It does not mutate emitter pointers/counts or state/parameters like a fixture callback might. Two sampled horizontal components are not proven nondegenerate for every admissible RNG state; finite nonzero normalization remains a numerical precondition.

**Sine/angle:** retail sinf0044b7b0 uses actual scalar math helpers0044af20/0044a138/0044a5b0; their math reduction helpers use no basis registers. atan2 wrapper0044b950 reaches004494b8; its special COP2 path only uses Q/control registerVI22 and waits, not VF28..30. Code boundaries matter: scalar scaling helper00441f68 ends before the separate unnamed routine at00442018; a symbol-gap scan extending to00442088 is not a call-graph proof for the helper. No arbitrary callback replacement is assumed.

**Attributes/projection:** the complete color/size/angle producer argument from the Sphere audit applies because the same0048b220 body and fields were freshly checked. Mode2 reads current/previous full positions, calls actual projection0048a460 twice, and writes angle from the projected delta or zero. Projection supplies all four output lanes, explicitly writing Z/W=0 at0048a4f0/f4.

The projection's transform003e42a0 is an actual installed provider slot, not an assumed fixture. Retail003e43c0 installs scalar003e3dc0 into slot+8, and successful PS2 setup00401290..004012b0 installs optimized00402410 through003e3f80. Scalar003e3dc0 reads inputXYZ and all twelve matrix XYZ coefficients, then writes complete outputXYZ. Optimized00402410 loads the real64-byte matrix with four quad loads, builds its input from exactly three scalar loads at00402420/24/28, computes XYZ using VF1..5, and writes all three output words00402458/5c/60. Both preserve VF11 and Wave's VF28..30. Valid initialized camera and full actual matrix64 remain prerequisites; no invented inputW or extra input object is needed for this provider.

**Trail and copies:** target's direct trail and attribute providers and the real memcpy do not overwrite primary/state/emitter/parameter storage on the coherent disjoint domain. Actual memcpy0043f810 uses ordinary/MMI loads/stores and preserves the basis. Trail0048b340 and its curve0048a810 use lower working VF registers rather than Wave's VF28..30. No provider is replaced, reinitialized, or made to return a convenient constant.

## Inherited trail hole and caller-only containment

For each primary index i, its allocated trail region is `[P+i*H, P+(i+1)*H)` records, after all primary records[0,P). The target reads **no trail payload or trail attributes**. Its expiration block writes only trail ages; its preroll block copies a complete primary into the first trail slot and writes that slot's age=-1.

Actual0048b340 returns when H=0. At primary age0 it copies only trail slot0 and marks every trail age=-1. Later it shifts H-W full records and explicitly reads source color at0048b4ec, before any age guard. The previously established concrete C=3,W=1 history hole therefore also applies to Wave: after ordinary spawn and the first age0 live update, slot1 payload is unwritten; the following age1 live update copies slot1 to slot2 and reads its color. This is a static missing-producer observation, not execution of an indeterminate C value and not proof of a shipped resource occurrence.

For valid nonnegative dimensions and coherent capacity, every provider destination remains in that same trail group: slot0; shift destinationsW..H-1; optional interpolation slots1..W-1. Every source is within that group's allocated history when a read occurs. Thus the uncertain history cannot flow back into a primary or Wave state/local subsequently consumed by0048b9e0. Even later trace expiration only changes ages. A fabricated callback changing base/count/capacity can invalidate the disjointness proof and is not approved by this audit.

## Necessary input/resource limits and final disposition

The bounded target-only claim needs:

- Correct complete objects, live allocations and minimum extents above;16-byte vector/primary/current-parameter alignment, scalar-aligned state, and a complete initialized240-byte source parameter record
- Nonnegative P,C,W with representable products/sums/offsets and coherent totalCount/capacity; real provider pointers and nonoverlapping primary/trail/state/parameter ranges
- Actual constructor/reset/dispatcher/spawn lifecycle, with initialized live state rather than arbitrary seeded ages
- Finite, representable float-to-integer spawn-budget and preroll-age conversions; defined signed age/tick increments; usable positive lifetime for the usual live domain
- Finite usable amplitude/phase/rate/variation arithmetic and nonzero finite normalization length; valid attribute key/envelope interpolation denominators and representable conversions; valid camera/matrix and nonzero finite projection depth for angleMode2

The target checks lifetime==0, not this whole contract. Constructor's300 cap does not prove all resource arithmetic or all parameter data valid. Do not add guards, clamp values, narrow randomness, replace real providers, or invent allocation initialization to make the contract universal.

**Disposition:** accept the exact recovered rank56 source for caller-only register/allocation diagnostics under this contract. Retain its complete128-bit snapshots and both real W initializations. Keep the inherited trail caveat explicit and production ASM in place. Any new candidate requires a fresh source delta review; no historical or newly measured score, executable-byte match, or universal engine guarantee is claimed here.

## Guarded-retention supplement: last01 source, 2026-10-05 02:01 UTC

**Accept `proof/last01-explicit-live-trail-index.c` for guarded retention within the caller-only domain above.** No new uninitialized read, invented storage, fake ABI, provider change, or unsupported reload assumption was found. This is a focused source/retail review, not a fresh compilation, completed owner audit, completed native test run, or MATCH.

Exact reviewed files under `wave-register-review-20261005/repo/`:

- `proof/baseline.c`: SHA256 `03da8870eae426622f61640392083211508c674fc597c91ef991a470f824abaf`, byte-identical to the previously reviewed recovered rank56 file
- `proof/last01-explicit-live-trail-index.c`: SHA256 `dba6e58be1cf03c4d7b68431c3a470dd139b098ec640471bda72a3dab50863fb`
- Last01 complete function-only text: 10676 bytes, SHA256 `637e58ec48dee14e9d46ba035233981ae49c680d46219bce3a25523bbae42692`
- `include/particle_spawn_internal.h` and `include/effect_vu0_internal.h` retain the exact hashes above

1. **New scalar initialization and exits:** `one`, `half`, and `two` receive actual representable constants at the common post-init block before any loop body; each is used in the real formula/state writes. They are not dummy live values. Lifetime-zero returns before use. Count-zero goes directly to loop exit. -2 and exhausted-budget skips do not evaluate a new spawn-only local. `prerollScale` is initialized in its own emission-variation branch and immediately consumed there. `finalAmplitudeVariation` is loaded immediately before the same RNG call as the former reused `a`, and its only arithmetic use follows that call. Every preroll elapsed/product value is assigned before its first use within the preroll block; no goto enters that block midway.
2. **Complete addressed snapshots:** each block-local `snapshot` pointer is initialized to `&b220buf` and immediately writes the existing full128-bit object from the existing full position. The pointer introduces no additional escaped data object, size, alias promise, or fabricated read. Spawn and live branches still snapshot at exactly the pre-preroll/pre-update points, before the same provider calls. Both vectors and both actual W initialization statements are unchanged.
3. **Live-base trail indices:** `particleIndex` is assigned separately in each nonzero-trail arm, using the current particle address minus the live `emitter->particles` address. Its use is dominated by that assignment, even when the other trail arm has never executed. It is not replaced by the captured loop index. The next statement groups the integer offset `primaryCount + particleIndex*trailLength` before adding it to the live array base; under the existing nonoverflowing coherent-allocation contract this denotes the same allocated record. Expiration still reloads live parameters/count/base at the same point. Preroll still performs those reloads after the actual attribute call and size/angle writes. No call or external-effect boundary occurs between the newly separated index and address statements. Ordinary nonvolatile memory with no concurrent mutation is part of this bounded contract; arbitrary asynchronous mutation is not being licensed.
4. **Branches and provider order:** simplifying `!(emissionDuration == 0)` and reversing the complete local/world and angle-mode arms preserve their full decisions. Local space still omits translation; world space still adds the complete current position. Angle mode2 still writes offset0/scale1 without RNG; other modes retain their RNG sequence and conditional sign multiplication. The source still multiplies by -1.0f, rather than substituting an unreviewed bitwise sign operation. Captured flags/count/lifetime/angleMode/gravity and every provider call keep their original capture/call boundaries. Expiration and skip paths advance particle/state exactly once.
5. **Floating computation stages:** the amplitude formulas are unchanged apart from exact1.0f substitution and naming the final variation independently. Preroll separates elapsed, travelled=`speed*elapsed`, gravityDistance=`gravity*elapsed`, gravitySquaredDistance=`elapsed*gravityDistance`, then `travelled - half*gravitySquaredDistance`. These are real used scalar stages of the retail computation, not stored padding or artificial operations. The already-built last01 object was inspected read-only: offsets+6E0..+6F4 are the same `lwc1 speed; mula.s speed,elapsed; mul.s gravity,elapsed; mul.s elapsed,product; mtc1 zero; msub.s half,product` sequence as retail0048c0c0..0048c0d4. Thus it retains the actual ACC product/subtraction and two intervening scalar product stages, with no added forced round-trip or reassociation to `elapsed*elapsed`. Subsequent XYZ/phase/amplitude update order, sinf call, and unsigned-remainder→float→age conversion remain unchanged. This is a target-toolchain/finite-domain judgment, not a claim about strict per-assignment rounding in every host compiler.

Fresh text comparison confirmed that attribute0048b220, trail0048b340, constructor00492b20, free00492cd0, reset00492d00 and dispatcher00492d10 remain identical to public90. The six separate provider/client owners listed above also remain byte-identical to public90. Therefore the actual primary32/state60 producer proof and the disjoint trail caveat carry over without a new source/provider premise.

Author-run receipt `proof/last01-explicit-live-trail-index.json`, SHA256 `70f198ad8cd87f930a2a441375cfc6b2310f2582946fe63efb06b0bc40b6d486`, reports2652 bytes/frame0x140 and28 original-offset resolved reference payloads all equal. It records exactly one resolved instruction difference: target offset228(decimal,0xE4), candidate `addiu s6,zero,1` versus retail `daddiu s6,zero,1`. Both produce the same consumed true value, but their bytes differ. Receipt and existing object SHA256 `f0bac1d9e3513a8fc4e2e58729f28773f3613dbe3a57cb4c6d4c566c6f613f62` were inspected, not rebuilt. No downstream owner/native result is claimed.

At this review, the owner still contained the baseline function, function SHA256 `5d07c7231ee7496e37f3784399efcffd0015ee03b4def8df86317cba5db2d218`; complete owner SHA256 `88a5a8b717e0f6331cea56d4abffcfe9157ec84fd2592abb43f4b7632d631813`. This supplement does not claim last01 installation. Retention must preserve the NONMATCHING/INCLUDE_ASM production fallback and scoped pragmas. Only this report was appended; no source edit, compilation, test, provider change or domain expansion by the reviewer.

## Final narrow-producer supplement, 2026-10-05 02:24 UTC

**The final source delta is legitimate and preserves the previously approved caller-only behavior.** The actual opaque0048b340 trail qualification, initialized-object/capacity contract, and numeric/resource prerequisites above remain in force. This supplement adds no domain claim or provider assumption.

Exact freeze reviewed: `repo/proof/final-zero.c`, 11287 bytes, SHA256 `a84170bbbefca177e17944f0c3aaff5533eed8c8177709995aba568ecd04c27f`. Its complete function-only text is11020 bytes, SHA256 `15169b28eccad76ced78800d9cdcc93616c4a5f51da942a1d4e1611530819505`. The approved predecessor remains `proof/last01-explicit-live-trail-index.c`, SHA256 `dba6e58be1cf03c4d7b68431c3a470dd139b098ec640471bda72a3dab50863fb`. Both record/VU headers retain their previously recorded hashes.

A fresh whitespace/comment-normalized comparison establishes that the **only semantic text change** from last01 is replacement of `preroll = 1;` by `u8 initialPreroll = 1; preroll = initialPreroll;` inside the already-taken first-tick/preroll-enabled branch.

- Initialization dominates use within the same lexical block. No label or jump enters between the declaration and assignment, and the temporary is not evaluated outside its scope. The true branch executes both statements before its emission-variation decision and goto. Lifetime-zero, exhausted-emission, ordinary-update, zero-count, skip, spawn and live paths retain exactly their preceding flag/value decisions.
- Value1 is exactly representable in the project's unsigned-char `u8` and signed32 `s32`; its ordinary integer promotion yields exactly1. There is no implementation-sensitive narrowing of an external value, signedness-dependent branch change, or altered false value. Other producers still assign0 to the same `preroll` scalar.
- This is a real used scalar producer: its value feeds the existing flag that controls elapsed-time advancement and the preroll trail-copy/age path. It is neither an unused local nor a dead read introduced to fill a frame. It introduces no fabricated object padding, pointer escape, forced store/reload, call, arithmetic side effect or memory/provider dependency. It does not assert an original source variable name.
- Both W initializers, all three complete128-bit locals, provider calls, live parameter/base/count reloads, and all previously reviewed FP product/fusion stages are text-identical after comment removal. Therefore the prior initialized-state and trail-containment proof carries over unchanged.

The cited source precedent was independently checked read-only. Current and captured public0048a980 use `u8 third = 2; selected = third;` for a genuinely used wider selected index. Extracting its symbol bytes from existing `proof/capture/public.o` (object SHA256 `95770a0cb1f1858d32831694b1bfd1e9a08fdec1d0f650ecc3db29d6494f4b74`) gives584 bytes, SHA256 `d1b3df1459ed8596af61fd612125dd1179a82ed0a9c41264e5359b88d6fa9bd2`, freshly equal to retail0048a980 over the entire function. Word+EC is `0x64060002`, `daddiu a2,zero,2`. This is actual compiled-source precedent for a narrow-to-wide live scalar lifetime, not a general Boolean-opcode rule. The earlier focused evidence report `boolean-lowering-review.md` has SHA256 `a8e0f5530d82d2e84cd1c9e51d8386994e90b75a247c0b5966bd05d234c14559`.

Author-run `proof/final-zero.json`, SHA256 `9c359b49929b18b8e2f2e76aef2d18ae439380bd0a68291c8485c407fea1b49e`, now records2652 bytes/frame0x140, zero resolved differing words, and28 reference payloads all equal. Existing final object SHA256 is `d5c0a71af5e289cd0816558a597c0462008fa6fb61f15a2fbe611aa93508237c`. These receipts were inspected, not compiled or rerun by this reviewer. Retail's2652 executable bytes and separate4-byte alignment tail remain the correct extent distinction. Final whole-owner/native rerun completion is not claimed by this supplement.

At review time, `src/promoted/code1_0048.c` still contained the recovered baseline and retained whole-owner SHA256 `88a5a8b717e0f6331cea56d4abffcfe9157ec84fd2592abb43f4b7632d631813`; this review does not claim final-source installation or production promotion. No source or provider was changed, no compiler/test was run, and only this report was appended by the reviewer.

## Production-header scope note

The production successor keeps every reviewed Wave field/type and every used
VU helper unchanged. It removes only unused Orbit declarations and the unused
spawnVuSetY10 helper from the recovered header. Header SHA256 is
`dd5d0f65179da39f39486e125935c7b1251df932fb3f862deb5f5ba823824ea8`.
The complete compiled owner remains byte-identical to the reviewed zero object;
52 fresh b210 size/offset checks pass. This is an author-run scope/evidence note,
not a revision of the independent audit's numerical or provider qualifications.
