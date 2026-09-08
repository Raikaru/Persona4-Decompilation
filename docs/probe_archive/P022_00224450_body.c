/* Complete retail branch reconstruction; no honest ordinary-C definition.
 * Production retains INCLUDE_ASM. No C object or normalized-difference score
 * exists for this blocker; the old zero score described ASM, not a C probe.
 * Source/retail evidence follows. No game execution is claimed.
 *
 * func_00224450: complete retail reconstruction notes
 * 
 * Disposition
 * The complete retail window has a path that cannot satisfy the no-undefined-locals/no-invented-inputs requirement. No function definition is emitted here. This is an evidence-backed blocker, not a measured compiler floor. The target remains ASM; no C probe or target execution was performed.
 * 
 * Retail extent and actual local data
 * - Function 0x00224450 through 0x0022496F inclusive: 0x520=1312 bytes, 364 assembly lines. Every instruction/delay slot was read. No target jump table.
 * - Frame is 0xA0 bytes, but it is NOT a matrix or padded C payload.
 * - sp+0x00..0x4F saves s0..s4 as five quadwords. sp+0x50..0x57 saves ra. sp+0x58..0x5F is not a proven application datum.
 * - Source pose sp+0x60..0x7B: exactly f32[7], position xyz at +0,+4,+8 followed by quaternion xyzw at +0xC,+0x10,+0x14,+0x18.
 * - Destination pose sp+0x7C..0x97: same exact 28-byte layout. Quaternion starts sp+0x88. The independently assigned coordinates are sp+0x7C,0x80,0x84. Do not combine this with source as a 64-byte matrix, use one float per pose, or invent trailing data at sp+0x98..0x9F.
 * - Initial func_001bd560 writes source only, never destination. The matrix is internal to func_001bd780, not the caller's 160-byte frame.
 * 
 * Complete control/data map
 * 00224450-002244C8
 *   Save camera a0. Clear u32 at iGpffffb3ac+0xC0C. Reload global. Read unsigned halfword+0x108 (previous camera state); directSetup=0 for 0x29,0x28,0x21,2; directSetup=1 otherwise. Do not read current state+0xF4 here.
 * 002244C8-00224548
 *   anyBad=0; anySpecial=0. First linked-list head is the earlier global snapshot's u32 pointer+0x180. Traverse every node via pointer+0xA6C. A node qualifies only if u32+0x9C bit8 and pointer+0xA64 nonnull and func_00243d80(pointer)!=0. Then independently set sticky anyBad if datCalcChkBadStatus(reloaded node+0xA64,0x100000)!=0 and sticky anySpecial if func_00243e30(reloaded node+0xA64)!=0. Do NOT stop after either flag becomes true. Reload +0xA64 between all calls; reload the next link after calls.
 * 00224548-00224568
 *   status=(u16)(anySpecial ? 2 : anyBad!=0). Special flag takes precedence over bad-status flag.
 * 00224568-002245E0
 *   Call current battle id getter. If id==0x208 AND status==0, reload global, traverse head+0x178 via node+0xA6C. Qualify with node u32+0x9C bit8 and nonnull data+0xA64 only (do not call func_00243d80 on this list). If datCalcChkBadStatus(data,0x100)!=0, set status=2 and break immediately. Otherwise continue. No other status transitions.
 * 002245E0-00224624
 *   Load action=*(camera+0xE0). Read unsigned halfword effectId=*(action+0x6E) BEFORE calling func_001d8df0((s32)(action+0x98)). Save its low16 as targetMask. Reload action from camera+0xE0, call func_001d7f10(action,NULL,earlierEffectId,0), save low16 as effectClass. Copy exactly camera+0x9C..0xB7 to sourcePose with func_001bd560.
 * 00224624-00224734: targetMask==2
 *   Reload global. If global u32+0x10 bit0x400 and effectClass==0: call func_001c8cf0(camera), reload global, set u32+0xC0C=1, then jump to COMMON at00224888. No destination pose initialized. This is NOT the same early-return behavior as targetMask==1/effectClass==0 below.
 *   Otherwise reload camera+0xE0; unit=*(action+0x30). If unit byte+0xA2!=0, index=0. Else start index=0 and traverse the current global snapshot's head+0x17C via node+0xA68, stopping on pointer equality with unit; increment index with (u16)(index+1) for every skipped node. Null exhaustion uses final count, not an error or guard. Read pose bank pointer global+0xB98 from the same saved global snapshot. entry=bank+0x120+index*0x48+status*0x18. Call func_001bd780(destinationPose+3,entry,entry+0xC,D_0060A0E0). THEN load entry floats+0,+4,+8 and write destinationPose xyz independently. Jump COMMON.
 * 00224734-00224834: targetMask==1
 *   If effectClass==0: call func_001c8cf0(camera), reload global, set u32+0xC0C=1, and EXIT immediately at0022494C. No final event getter, visibility setup, direct pose call, interpolation, or timing call.
 *   Otherwise reload action and unit. Nonzero unit byte+0xA2 => index0. For zero byte, reload global for list head+0x17C, traverse via+0xA68 using equality and u16 wrapping count as above. Reload global AGAIN at002247A4 even after the no-list/nonzero-genus path; load bank+0xB98. entry=bank+0x240+index*0x48+status*0x18. Compute destination quaternion and subsequently assign xyz from entry in three distinct floats. Jump COMMON.
 * 00224834-00224888: all other targetMask values (including0 and3)
 *   Reload global; bank=*(global+0xB98); entry=bank+0x360+status*0x18. No linked-list index. Compute destination quaternion and independently assign xyz as above.
 * COMMON 00224888-002248E4
 *   Call func_001ef9a0 AGAIN. If result==0x215, overwrite destination quaternion from D_00634890 (eye), D_0063489C (lookAt), D_0060A0E0 (up); then separately load xyz from D_00634890/94/98 and overwrite all three destination coordinates. This override is the only destination initializer reachable after the type2/flag400/effect0 setup path.
 * 002248E4-00224920: directSetup!=0
 *   Reload action from camera+0xE0; func_001bcd40(action,NULL,NULL,0x100,0.0f); func_001bab00((u16*)camera,destinationPose). Exit, no timing call.
 * 00224920-0022494C: directSetup==0
 *   func_001bac20((u16*)camera,sourcePose,destinationPose,1); func_001bbef0(camera,0.75f). Exit.
 * 0022494C-00224970
 *   Restore callee-save registers and return. No defined result.
 * 
 * Data addressing and widths
 * - Global symbol is iGpffffb3ac (gp-0x4C54), a live pointer, not the global object itself. Existing DAT_0076449c is a spelling used elsewhere in the owner; new reconstruction should reuse the declared real global consistently. Do not hoist loads across calls or stores.
 * - Target's u16 fields: global+0x108; action+0x6E; return masks/status/index. Unit genus is u8+0xA2. Node flags and global+0xC0C are u32. Pointers loaded by lw are 32-bit target pointers.
 * - Runtime bank records are 24 bytes = two f32[3] vectors, NOT a seven-float pose. Per unit-index row is72 bytes = three status records. Regions selected are +0x120, +0x240, +0x360. Common four-position grouping is suggested by the0x120 spacing, but target has no index bound and no candidate may add one or assert exact bank extent from those constants.
 * - Known constants needed directly: D_0060A0E0 at0x0060A0E0 (up xyz; 12-byte consumed extent); D_00634890 at0x00634890 (eye xyz;12 bytes); D_0063489C at0x0063489C (lookAt xyz;12 bytes). D_00634894 and D_00634898 are labels for eye.y/eye.z, not additional independent arrays. Consumed range of eye+lookAt is [0x00634890,0x006348A8). Do not infer padding floats to0x006348B0 or make either vector16 bytes merely from adjacent symbol alignment.
 * - Immediate 0.75f is0x3F400000. Immediate visibility margin0.0f is0x00000000.
 * 
 * Blocker proof and boundary
 * The missing state is destinationPose[0..6], originally the28 stack bytes sp+0x7C..0x97, when targetMask==2, global+0x10&0x400, effectClass==0, and the second battle-id query !=0x215. Every other pose-consuming branch initializes all seven floats. The type1/effect0 branch returns before consuming anything.
 * func_001c8cf0 only writes camera+0x100/+0x104/+0x106. The actual call has no destination address; no extra a1/a2/f12 input belongs to target's contract. Neither the real invoker's callback signature nor target's entry establishes stack data there. The observed destination bits on the blocked path are inherited stack contents, not representable initialized C inputs.
 * Do not repair this by setting destination equal to source, zeros, constants, reading uninitialized f32 locals, adding guards, turning type2 setup into a return, or adding an incoming pose argument. Those would change the requested behavior.
 * A broad invariant flag0x400=>battle0x215 is contradicted by current src/promoted/code1_0022.c:1617-1624: func_0022bd60 explicitly sets that flag for battle0x203. Retail producer at0x0022BF10..14 independently proves the write; mapping the dispatcher slot requires jtbl_00747920 data. Even proving one subset of battle203 actions avoids effectClass0 would not make the original signature's whole input space initialized.
 * An acceptable unblock requires a proven reachability precondition for every actual callback invocation that excludes this conjunction, or explicit permission to repair the retail defect rather than reconstruct all branches. No such precondition is currently evidenced. The safe integration choice is retain INCLUDE_ASM and archive this blocker, not pretend a complete C body exists.
 * 
 * Ancillary caller issue
 * func_001bc660's original no-argument func_0022cdb0 declaration/call dropped its state input. The live caller now forwards the full s32 state; the real provider masks low16 and selects the per-state table. The corrected caller is byte-exact and exercised in the camera smoke. That repair does not initialize this target's missing pose.
 * 
 * Exact retail data supplied by Main's read-only mapped-image extraction
 * Source evidence: /tmp/P4FreshDispatcherData.txt:11-29 and /tmp/P4FreshDispatcherMoreData.txt:1-2. These are byte reads, not target execution or behavioral validation.
 * - Eye D_00634890, consumed bytes0x0C:
 *   xyz float bits: C1883D71 4402D7AE 44978F0A.
 *   Exact decoded binary32 values: -17.030000686645508, 523.3699951171875, 1212.469970703125.
 *   Conventional source literals: -17.03f, 523.37f, 1212.47f.
 * - LookAt D_0063489C, consumed bytes0x0C:
 *   xyz float bits: C19547AE 440C20A4 448BF47B.
 *   Exact decoded binary32 values: -18.65999984741211, 560.510009765625, 1119.6400146484375.
 *   Conventional source literals: -18.66f, 560.51f, 1119.64f.
 * - Up D_0060A0E0, consumed bytes0x0C:
 *   xyz bits:00000000 3F800000 00000000, values0.0f,1.0f,0.0f.
 *   The next word at0x0060A0EC is also00000000, but is NOT consumed and does not justify expanding the vector extent.
 * - Target initializer callbacks occur at0x00634B58,0x00634F58,0x00635358.
 *   These are D_006348B0,D_00634CB0,D_006350B0 respectively plus0x2A8 =34*0x14.
 *   Each complete20-byte record has words:
 *   00224450 00224970 00000000 00000001 00000000.
 *   Thus state34/0x22 dispatches target as init callback, update callback00224970, reentry0, flag-control1, last word0. Each preceding20-byte record is:
 *   002240E0 00000000 00000000 00000001 00000000.
 *   A preceding table entry is not an earlier call and supplies no target destination pose.
 * - func_0022cdb0 selects D_006348B0 for default special battles, D_00634CB0 for0x20B with global+0xC40==0, D_006350B0 for0x20B with nonzero+C40 and for0x215. It returns NULL if global+0x10 lacks bit0x10 or both first callback words are zero. The complete retail block was read. Its resulting target-containing record is consumed by the real func_001bc660 invoker described above.
 * - jtbl_00747920[3] at0x0074792C is0022BED4. This proves the retail flag0x400 write at0022BF10 belongs to battle0x203, not just the headstart claim. Combined with default override-table selection, it does not exclude target invocation in that battle and does not initialize missing stack data.
 */
