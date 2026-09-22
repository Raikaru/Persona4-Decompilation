# Battle menu 00207320: independent read-only review

Worker-2 reviewed prime's `store-u16-count` candidate and subsequent named live
integration. No source edits or compiler runs were performed for this review.
No blocking issue was found in the reviewed target changes.

The dispatcher `func_00203420` loads a signed work address from node offset
0x28 and invokes the selection callback with `(u8 *, s32, u8 **)`. The menu
initializer `func_00203670` registers `func_00207320` for that callback. The final
signature is `s32 func_00207320(u8 *selection, s32 workAddress, u8 **nextPanel)`.
The local `work` byte pointer is initialized from `(u8 *)(u32)workAddress`
before use. Neither an uninitialized local nor a fabricated argument is used.

Private declarations were checked against the active callees and callbacks,
including the signed 64-bit action selector argument, unsigned persona and
party count returns, signed 16-bit list extents, and the sound interface in
`sdk_snd_internal.h`. The accepted party count is masked after each increment;
its unsigned halfword store at work+0x18c matches retail's `sh` at 002077bc.
The separate `(s16)partyCount` list extent retains the observed sign extension.

The independent check authenticated retained source, object, compiler, flags
and dependency hashes, then reran the complete unmasked proof and sibling
comparison against the retained objects:

* 2008 executable bytes within a 2016-byte window; exactly eight zero suffix
  bytes; all 88 code relocations resolved.
* The entire 32-byte jump table at 0x00747630, including all eight table
  relocations, matches retail.
* All 145 sibling functions retain identical bytes and canonical relocations.
* `allocated_data_equal=false` is fully accounted for: no pre-existing data
  entry is removed or changed, and the sole added entry is the proved jump
  table. It is not an unexplained data mismatch.

The final live source was subsequently read and authenticated against
`build/continue-first-party-20260922/menu207320/integrated/completed.json`.
Its official `tools/verify.py` report records `MATCH` for the target. The final
native object is identical to the independently proved candidate object.

| Artifact | SHA256 |
| --- | --- |
| Reviewed candidate source | `4f1f13fb5e6685992c4ade5030a9c1916b93f48cf11505a6b0f739fa29c45a8a` |
| Final named source at review | `d4fd543c252d850220a4d2bc56edab00df020d465be8b48641daf8ebdaa79121` |
| Candidate and final object | `eb64bb6dedeebe0f403f3e68b48c1babb38eedff6f82efa0a3c441b488f9edd2` |
| Baseline object | `078b948e90d0f117a531485185cd81094831922e03b58c3c48671319e62e089a` |
| Resolved target | `c4ec546816f01697ace816a6253804832a902b2aa788175fc4e8c4e58d400c30` |

Review findings were delivered to prime before and after integration. Prime
retains ownership of `src/promoted/code1_0020.c`; later edits must preserve the
sealed menu proof. This review does not claim a new runtime test or a review of
every unrelated function in that owner.
