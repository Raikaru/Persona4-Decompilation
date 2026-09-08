/* Retail func_00224450 remains ASM: undefined second-pose input.
 * No candidate definition is supplied or authorized by this evidence.
 * This is a dispatcher-admitted path, not a captured gameplay trace.
 *
 * func_00224450 — CURRENT RETAIL AUDIT, NO C DEFINITION AUTHORIZED
 *
 * Authority and method
 * - Complete asm/nonmatchings/code1_0022/func_00224450.s, addresses 00224450–0022496F (0x520 bytes), read without elision.
 * - Current src/promoted/code1_0022.c declarations and its CameraPosePair convention; current provider source plus retail provider instructions read directly.
 * - orig/SLUS_217.82 read as ELF32 LE: PT_LOAD VA 00100000, file offset 0x80, filesz 0x838A00. Raw registered pointers and the decisive branch words were inspected directly. This was binary/source investigation only, not a build, compiler probe, execution test, formatter, or lint run.
 * - Graph/CSP used for discovery; coverage reports are stale/partial for ASM and changed for current C, so no graph absence was used as proof. asm/code1.s and orig are excluded from indexing; direct-source/ELF fallback used.
 *
 * Real ABI and registration
 * - void func_00224450(u8 *camera). a0 alone is consumed. The pointer is the camera-work subobject at battleGlobal+0x24, NOT the outer battle global and NOT a hidden pose argument.
 * - No incoming saved-register state is consumed: s2=a0 at 22446C; s0 assigned on both mode branches; s3=0 and s1=0 before first scan; s4 receives list head before its first use. The saved register stores merely preserve ABI state. gp is the normal global base.
 * - Return is void: all exits restore registers without establishing a consistent v0; dispatcher ignores the callback result. Do not infer return type from the last provider.
 * - Aligned retail address-word scan found target pointers at 00634B58, 00634F58, 00635358 only. These are entry 0x22 (stride 0x14) in tables D_006348B0, D_00634CB0, D_006350B0. All five words are {00224450,00224970,0,1,0}: initializer, update, repeat-init flag, camera flag, final field.
 * - No encoded direct J/JAL to 00224450 was found in the mapped retail image. Actual target invocation is func_001bc660's jalr at 001BC7C4, a0=battleGlobal+0x24 at 001BC7C0.
 * - func_0022cdb0 requires global flags+0x10 bit 0x10. For encounter 0x20B choose D_00634CB0 if global+C40==0, otherwise D_006350B0; encounter 0x215 chooses D_006350B0; every other encounter chooses D_006348B0. Entry zero checks do not reject entry 0x22.
 * - func_001bc660 invokes initialization only on state change (entry+8==0 here). It stores the previous global+F4 state into global+108, new state into +F4, zeros +FC/+100, stores the supplied action at global+104 (=camera+E0), sets global+F8 bit2, optionally calls 001bd300, then invokes the initializer. It does not constrain target genus, skill classification, encounter 0x203, or global flag 0x400.
 * - btlCameraCreateSetStatePacket / retail 001bc920 takes (BtlAction*,u16), allocates 8 bytes of work, writes action at work+0 and state at work+4, and registers btlCameraUpdateSetStatePacket at packet+6C. The update reads those exact fields, calls func_001bc660(state,action,1), and returns 1. No additional pose or saved-register argument exists.
 * - Real requests for state 0x22 occur at 001A1DF8 (func_001a1c80, unconditional after target preparation) and 001A1FF4 (func_001a1ea0, leaving the alternate-selection state when global+C bit0x10000 was set and the earlier input/UI branch permits it). Both supply the action as a0 to 001bc920, copy its UID to packet+60, and enqueue with argument 0. Neither request filters encounter 0x203 or requires nonzero skill classification. The latter has no target-genus test on its 0x22 branch.
 * - Optional 001bd300 traverses global+178/+180 lists and calls 00194fc0(unit,0xF). It never receives the initializer's later stack address and does not initialize its pose locals.
 *
 * Output extents and called providers
 * 1. 00243d80(a0=unit data at rosterNode+A64) -> s32 boolean; no output pointer. Reads u16 unit+0 bit4; if absent returns 0. Otherwise reads u16 unit+2, assertion path for ID>=0x150, then signed halfword at global skill/stat table iGpffffb3cc + ID*0xE8 +0x18; returns whether bit0x80 set. Called only after rosterNode+9C bit8 and nonnull A64.
 * 2. 00232710 / datCalcChkBadStatus(a0=unit,a1=mask) -> boolean. Reads u32 unit+C only, ANDs mask and canonicalizes. Masks here: 0x100000 on the first roster; 0x100 on encounter-0x208 fallback roster. No writes or output extent.
 * 3. 00243e30(a0=unit) -> s32 boolean, reads u16 unit+0 bit0x200. No writes. First roster only after 00243d80 succeeds.
 * 4. 001ef9a0(void) -> encounter ID zero-extended from u16 (*(u8**)(global+C68)+8). No writes. Called first after roster scan, and again at common tail except the targetMask==1/classification==0 early return.
 * 5. 001d8df0(a0=action+98) -> u32 containing a u16 genus mask. Reads u16 list+38 and the first count 4-byte action/target pointers; dereferences each at +30 to a unit, then reads unit+A2 genus. ORs low16 of 1<<genus with u16 wrapping ordinal. No stores. Real count must fit the physical target list and genus must satisfy actual game data contract; no new guard is justified here.
 * 6. 001d7f10(a0=action,a1=NULL,a2=skillId,a3=0) -> u8 classification. With a1==NULL retail skips ALL target-building work and reads exactly iGpffffb3b8 + (u16)skillId*0x28 +8. It does not initialize an output local or derive its result from the target mask. General nonnull a1 path calls 001d7c60, but it is not taken by this target or 001c8cf0.
 * 7. 001bd560(a0=SP+60,a1=camera+9C) -> void. Copies exactly seven f32: offsets 0,4,8,C,10,14,18. Destination extent [SP+60,SP+7C), source extent [camera+9C,camera+B8). This is ONE position+quaternion pose, never a two-pose output. The last store is at SP+78. It does not touch SP+7C.
 * 8. 001c8cf0(a0=camera) -> void. Reads action=camera+E0, calls 001d7f10(action,NULL,action+6E,0), stores low16 at camera+106; calls 001d8df0(action+98), stores low16 at camera+104; stores zero u32 at camera+100. Exact direct write ranges [camera+100,camera+108); no pose output and no access to caller stack. Its providers are read-only on these arguments.
 * 9. 001bd780(a0=SP+88,a1=eye,a2=focus,a3=D_0060A0E0) -> void. Reads one RwV3d (12 bytes) from each of eye/focus/up. Calls 001bd620 with swapped eye/focus into its own RwMatrix storage, then RtQuatConvertFromMatrix. Writes exactly RtQuat [SP+88,SP+98), all four f32. Matrix construction writes each basis vector and position, leaving matrix flag words untouched; conversion reads only the initialized 3x3 elements, not flags/position. Trace-positive converter and all three diagonal branches 003dc490/510/590 write all 4 quaternion components. No caller-SP+7C position write occurs in the provider; target copies the 3 eye floats itself afterward.
 *    Up-vector retail contents at 0060A0E0: (0,1,0). Selection entries are eye+focus pairs, 0x18 bytes each, not quaternion poses. Target groups have three entries (0x48 bytes) per party ordinal.
 * 10. 001bcd40(action,NULL,NULL,0x100,0.0f): integer inputs a0–a3; floating fifth C argument in f12, not a4. Flags are u16 (already corrected in owner). No caller-local output. Global+10 bit4 returns immediately; otherwise traverses global+174 action nodes, requiring action+1A bit1 and its unit+9C bit8. With only flag0x100 set it calls 00194fc0(unit,2), writes unit+37=0xFF, and advances +450. Null vector arguments disable the geometric path. It cannot initialize the later pose through an absent pointer.
 * 11. 001bab00(a0=camera,a1=SP+7C): reads complete seven-float pose [SP+7C,SP+98). Resets camera u16 +0,+74,+76,+78 and u32 +7C,+80, copies position into first control point +4..+F and quaternion +10..+1F, updates counts; calls 003bb4a0(camera+98 pointer,index,position). The three first pose reads occur at 001BAB64/68/6C and four quaternion reads at 001BABBC/C0/C4/C8. It is not a provider of this input pose.
 * 12. 001bac20(a0=camera,a1=SP+60,a2=SP+7C,a3=1): reads BOTH complete 0x1C-byte input poses. Initializes camera spline/control-point state, constructs two interpolated poses using 001ba790 and appends start/intermediates/end. At flags1, model-position propagation branches are skipped. Writes four 0x1C-byte control points at camera+4 onward, u16 +0/+74/+76/+78 and u32 +7C/+80. Does not modify either input local. End pose is consumed during interpolation before the final direct endpoint copy.
 * 13. 001bbef0(a0=camera,f12=0.75f) -> void: writes duration expression 60*(2*f12)/2 to camera+84; 0.5f at +94; masks u16 flags +0 with 0xFFF5 then sets bit4. No local output.
 *
 * Local objects and initialization invariant
 * - The genuine aggregate is the existing local CameraPosePair shape:
 *   RwV3d first; RtQuat firstRotation; RwV3d second; RtQuat secondRotation.
 *   Logical size 0x38, alignment4; retail positions SP+60,+6C,+7C,+88 respectively. End at SP+98. Remaining frame space is ABI bookkeeping/alignment, NOT fields or padding objects to reproduce artificially.
 * - First pose is initialized by 001bd560 on every target branch. It is live only if the final path uses interpolation, although the copy itself is unconditional.
 * - Second pose is initialized completely by any table branch or the encounter0x215 override: quaternion writes +88..+97, explicit position writes +7C..+87.
 * - targetMask==1 && classification==0 calls 001c8cf0, sets global+C0C=1, and returns at 22494C. It consumes no second pose and is safe.
 * - targetMask==2 && (global+10 &0x400) && classification==0 calls the SAME provider and sets the SAME global flag, but branches to 224888, NOT the return. Unless encounter==0x215, second pose remains uninitialized and is nevertheless consumed by either 001bab00 or 001bac20.
 * - No incoming s-register value explains this: there is no target read of uninitialized saved-register state, and no callee receives the uninitialized second-pose address before the common consumer on this path.
 *
 * Concrete admitted path and why it is not excluded by actual setup
 * - Encounter 0x203 is not hypothetical flag manipulation: current 0022bd60 case0x203 explicitly sets global+10 bit0x10 AND bit0x400 and selects D_0062B490. Retail jumptable word at 00747920+3*4 is 0022BED4, whose stores 0022BEEC and 0022BF10 set those bits. Thus this encounter uses the override initializer while the tail's encounter0x215 repair does not run.
 * - A state0x22 packet with a live action whose target list contains one genus1 unit (001d8df0 returns2) and whose skill record byte8 is0 (001d7f10 returns0) is accepted by the audited real packet dispatcher and initializer. Neither actual state-request site forbids this combination. Choose previous state1 for immediate pose consumption, or previous state2/0x21/0x28/0x29 for interpolation consumption. Nonnull global+C68 and valid camera/action/target storage are ordinary prerequisites.
 * - Path: packet update 001BC8F8 -> dispatcher 001BC7C4 -> target 002245E0 -> 00224634 -> 00224654 -> 0022466C -> 00224888 -> 00224894 (taken for0x203) -> 002248E4 -> 00224910 or 00224930. The calls consume 28 bytes never assigned during this invocation.
 * - This proves an admitted machine-control-flow path and lack of a caller ABI precondition that would make ordinary C locals initialized. It is NOT a claim of a captured gameplay runtime trace or that a particular shipped skill table record was observed here; external runtime-loaded skill data was not fabricated. An exact C recovery under the task's no-undefined-input rule would require an independently proven game invariant excluding the zero-classification/genus1 combination for this encounter, or authorization to alter retail behavior. Neither follows from the actual audited callers/providers.
 *
 * Scope of preservation
 * - Do not zero the second pose, copy the first pose into it, invent a callback pose argument, enlarge 001bd560's extent, or insert an early return. Each changes the retail behavior or lies about the ABI.
 * - body.c intentionally has no definition. This is the requested genuine undefined-state blocker outcome, not an incomplete candidate offered for integration.
 *
 * func_00224450: terminal audit result = PROVEN UNINITIALIZED SECOND-POSE PATH
 * No ordinary-C body is supplied, as explicitly permitted by the assignment's blocker alternative. body.c is an explanatory comment, not a stub or compilable substitute. No repository files were changed.
 *
 * Complete retail control-flow ledger (all executable addresses covered)
 * 00224450–0022446C: allocate 0xA0 frame; save ra,s4,s3,s2,s1,s0; assign s2=a0.
 * 00224470–002244B4: reload battle global, clear u32+C0C, reload, read previous state u16+108; compare in order 0x29,0x28,0x21,2. Any match branches 2244B8; otherwise branch2244C4. Delay slots are nops.
 * 002244B8–002244C4: s0=0 for those four states, otherwise s0=1. This is immediate-vs-interpolated setup, not a filter that returns.
 * 002244C8–002244D8: initialize s3=0, s1=0; s4=global+180 roster head; branch to loop test224540.
 * 002244DC–00224504: if node+9C lacks bit8 or node+A64==NULL skip; else call00243d80. If false skip.
 * 00224508–00224520: reload node+A64; call00232710(unit,0x100000); if true s3=1.
 * 00224524–00224538: reload node+A64; call00243e30; if true s1=1.
 * 0022453C–00224544: advance node+A6C; repeat while nonnull.
 * 00224548–00224564: selected variant is2 if any 00243e30 succeeded; otherwise boolean(s3), explicitly zero-extended to u16. Therefore variant in{0,1,2}; highest-priority flag dominates regardless of roster order.
 * 00224568–00224584: call001ef9a0. Only encounter0x208 with variant0 enters fallback.
 * 00224588–00224594: s3=global+178; branch test2245D8.
 * 00224598–002245D0: node must have +9C bit8 and nonnull+A64. Call00232710(unit,0x100). First true result sets variant2 and breaks to2245E0; no00243d80/00243e30 here.
 * 002245D4–002245DC: advance+A6C and loop. Exhaustion preserves variant0.
 * 002245E0–002245F4: load action=camera+E0, skillId=u16(action+6E), call001d8df0(action+98), retain low16 targetMask.
 * 002245F8–00224610: reload action; call001d7f10(action,NULL,skillId,0); retain low16 classification (provider actually returns u8).
 * 00224614–00224620: snapshot current camera pose via001bd560(SP+60,camera+9C), exactly28 bytes.
 * 00224624–00224630: targetMask==2 selects224634; otherwise224734.
 * 00224634–00224650: load global flags; if no0x400 OR classification!=0, select normal table224674. Otherwise fall through224654.
 * 00224654–00224670: call001c8cf0(camera), reload global, set+C0C=1, branch224888. This is the defective/uninitialized-pose edge. Decisive retail word at22466C is0x10000086; PC+4+(0x86<<2)=224888, not22494C.
 * 00224674–00224690: actor=(*(camera+E0))+30. If actor+A2!=0, ordinal=0 and jump2246C8.
 * 00224694–002246C4: ordinal=0; walk global+17C by+A68 until matching actor or list exhaustion. Increment wraps to u16 each iteration. A missing actor produces wrapped list length, not a guard/failure. Mask ordinal on exit.
 * 002246C8–002246F4: entry=global+B98 + ordinal*0x48 + variant*0x18 +0x120. Products are performed using shift/add as unsigned byte offsets; no extra provider call or layout field.
 * 002246F8–00224710: call001bd780(SP+88,entry,entry+0xC,D_0060A0E0).
 * 00224714–00224730: copy entry's three floats into SP+7C,+80,+84; branch224888.
 * 00224734–00224748: targetMask==1 selects classification test. All other masks go224834. For mask1/classification0 go224814; nonzero classification falls through22474C.
 * 0022474C–00224768: actor=action+30; actor+A2!=0 gives ordinal0 and jump2247A4.
 * 0022476C–002247A0: separate equivalent wrapping party-ordinal loop from global+17C using+A68. It must not be omitted merely because it resembles the mask2 branch.
 * 002247A4–002247D4: entry=global+B98 + ordinal*0x48 + variant*0x18 +0x240.
 * 002247D8–002247F0: call001bd780(SP+88,entry,entry+0xC,up).
 * 002247F4–00224810: copy three entry floats to SP+7C,+80,+84; branch224888.
 * 00224814–00224830: mask1/classification0 calls001c8cf0(camera), reloads global, sets+C0C=1, and branches DIRECTLY TO22494C. Decisive retail word at22482C is0x10000047; this is the safe early-return branch. It is deliberately not conflated with22466C.
 * 00224834–00224850: all other target masks choose global+B98 + variant*0x18 +0x360; no actor ordinal.
 * 00224854–0022486C: call001bd780(SP+88,entry,entry+0xC,up).
 * 00224870–00224884: copy three entry floats into second pose; fall through common tail.
 * 00224888–00224898: call001ef9a0 again. If not0x215 branch2248E4. This call occurs even after the mask2 fallback; it does not occur after the mask1 early-return fallback.
 * 0022489C–002248BC: encounter0x215 overwrites second quaternion via001bd780(SP+88,D_00634890,D_0063489C,up).
 * 002248C0–002248E0: overwrite second position with three floats at00634890/94/98. Together these operations repair/replace the entire second pose, irrespective of previous table selection.
 * 002248E4–002248E8: s0==0 ->224920, else immediate branch2248EC.
 * 002248EC–00224904: set f12=0.0, load camera+E0 as a0; a1=a2=NULL, a3=0x100; call001bcd40. Flags remain u16 and floating value is the fifth C argument.
 * 00224908–0022491C: call001bab00(camera,SP+7C), branch epilogue. This consumes the entire second pose, not just xyz.
 * 00224920–00224934: call001bac20(camera,SP+60,SP+7C,1), consuming both complete poses.
 * 00224938–00224948: materialize0.75f in f12; call001bbef0(camera,0.75f).
 * 0022494C–0022496C: restore all saved registers, deallocate frame, jr ra with nop delay slot. There is no result materialization and no hidden executable tail beyond0x520.
 *
 * Shaping decisions if an independent exclusion invariant is ever established
 * - Reuse owner u8* byte-offset conventions, RwV3d/RtQuat, and the exact local CameraPosePair {first,firstRotation,second,secondRotation}; do not construct fourteen unrelated scalars or filler arrays.
 * - Keep roster booleans separate until priority reduction, variant as u16, target mask separate from classification, and separate wrapping party ordinals for the two branch-local walks.
 * - The 0x18-byte table row is eye/focus RwV3d pair; never reinterpret it as a28-byte pose or use typed pointer+0xC arithmetic (the archive erroneously does the latter on f32*).
 * - Preserve calls before decisions and the unequal fallback continuations. In particular a shared fallback return would silently fix retail behavior and is forbidden.
 * - No source pragmas proposed or matching metrics claimed: no compiler/build/probe/validation was run.
 *
 * Candidate/archive audit
 * src/generated/code1_0022.c:1618–1810 was read only after current target ASM. It identifies the same suspect fallback but offers no proof of initialized locals. Its single-float sp60/sp88 addresses underdeclare the28/16-byte provider outputs; its f32* +0xC target offset scales incorrectly; its (f32)(s32) load artifacts are not real integer conversions. These are rejected, not copied into a candidate.
 *
 * Concrete blocker summary
 * Retail encounter0x203 explicitly sets the0x400 flag while enabling these camera override tables. An admitted state0x22 callback action with targetMask2 and skill-classification0 takes224654->224888. The target's only local provider beforehand wrote SP+60..+7B; the fallback provider writes camera+100..+107 only. Encounter0x203 skips the0x215 overwrite. The final API reads SP+7C..+97 as a pose. All28 bytes lack a defining write on this invocation. This is an undefined C input dependency, not an unexplained saved register. Exact gameplay reachability for a particular shipped skill record is not claimed without a runtime-loaded skill dataset; actual dispatcher/registration and encounter flag setup do not provide an exclusion invariant. A clean C implementation cannot be published honestly under the no-undefined-input/no-fake-guard constraints.
 *
 * Artifacts
 * - contracts.txt: actual ABI, callback chain, real encounter flags, every provider contract and local lifetime.
 * - declarations.h: exact additional and existing declarations; audit-only, no repository changes requested.
 * - body.c: intentionally no function definition, with the explicit blocker reference.
 * - notes.txt: this complete instruction/control-flow ledger and candidate audit.
 */
