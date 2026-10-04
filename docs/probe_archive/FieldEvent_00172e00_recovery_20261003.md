# Field event zero-candidate recovery receipt

The execution workspace was replaced at approximately 2026-10-03 23:12 UTC.
The previous worktree and toolchain are currently absent. These instructions
reconstruct the source candidate; every result must be reproduced before promotion.

Prior worktree: p4-field-event-match-20261003
Base: 907ad8b8d0db35785c9ac727143ee6b4083c6627, tree-equivalent to public18c3.
Baseline source: source-checkpoints/patches/rank14.patch from recovered Oct2 archive.
Target: src/promoted/k_fldEvent.c, func_00172e00.
The guarded rank14 baseline was6260 bytes/27 masked words/30 aligned edits.

Replay the rank14 src/include and test changes, preserving newer source context.
The code1_0016.c snapshot hunk required manual contextual application: include
field_event_internal.h, change func0016f630 first formal to FldEventSnapshot*,
and cast that formal to s128* at its existing var17 assignment. Preserve the
newer no-argument camera getter and existing casts elsewhere.

Use recover_zero_candidate.py on the extracted rank14 target body. Compile in
the owner context, which already has opt_common_subs on and opt_loop_invariants
on around the target. Keep the ASM fallback until all review gates pass.

Coherent loader change required, never a conflicting local prototype:
- Add u8 *func_0015ff20(s32 fieldId,s32 roomId) to field_transition_internal.h
- Include that shared header in promoted/k_fldHBN.c
- Change its func0015ff20 first formal fromu16 tos32
- Change only its temp16=arg0 assignment to temp16=(u16)arg0
- Remove the local narrow declaration fromcode1_0015.c andk_fldEvent.c
- Update the controller fixture's loader stub to the same s32 first formal

Authenticated before rollback:
- Final target6260 executable bytes, zero masked words and zero aligned edits
- Retail window6272, remaining12 bytes genuine zero alignment
- Original12 affected owners415 MATCH/8 ASM
- Expanded13 owners includingloader423 MATCH/8 ASM while target stayed guarded
- Coherent narrow-return getter alternative169 MATCH/2 ASM inthree owners,
  but added6 targetdifferences and was reverted; gettersremainwordreturns
- Native controller3458 cases eachO0/O2
- Native getter/environment/area provider293296 scenarios/1302000checks eachO0/O2
- Nine controller andsix provider mutants rejected atO2
- Independent loader ABI review supported wordtransport with explicitlow16 conversion
  for every32-bit input; no authoritativeSDK/header/narrowcallback type exists
- Onlydirectretailcalls001562f8 and00173ff0; no encodeddata pointer

Not yet confirmed/completed:
- New loader full-word fixture last run was interrupted/unconfirmed
- Fully resolved target refs/data and before/after object gates
- Guard removal, whole-repo promotion verification, both full linked hashes
- Frozen commit or source bundle; nothing was published

New loader fixture design: execute the actual func0015ff20 C definition without
rewriting it. Five upperword classes0,0001,7fff,8000,ffff timesall65536lowwords,
three modes(existingfile,missingfile,bypass), plus162crossproductedgecases =
983202invocations peroptimization level. Assert low16field/room sprintfoperands,
callorder,filenamebufferidentity,returnpointer. O2mutants: omitfieldmask,
signextendfield,move-1testbeforemask,omitroommask,invertexistencegate.
Before rollback two compile issues were fixed: entryfunctionnamedmain (not
test_main), and printfstubacceptsvoid*destination thenuseschar*locally for the
provider'sexisting&sp30argument. The final rerun result was not observed.

The frozen report must distinguish semantic halfword IDs from word wire
transport without asserting an original Atlus signature. Remove the obsolete
measurement/Production-stays-ASM paragraph copied into field_event_internal.h.
Controller tests substitute most providers including snapshot; separate tests
execute real getters/environment/area/loader bodies. Positive fixturesO0/O2,
negative mutationcontrolsO2 only.

## Reconstructed source checkpoint

The restored public base is18c3a8d4c1ef76c780c68ebc1f4b110cb559ed18.
The recovered rank14 patch hasSHA256d60dd69d8f7089f1fea0d533eaa20f29b24656bf49d6531cddc476a124ca4493.
All fail-fast transformation anchors succeeded. The recreated target candidate
hasSHA25698043a9d72027a40487bdc138bfcd4646d53fe5b7e76dc4876c192e2608396bb.
At this checkpoint the fallback remains ASM and all post-rollback compiler,
reference, native, and full-link results are pending. This source checkpoint
is not a production match or an integration approval.
