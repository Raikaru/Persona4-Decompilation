/*
 * MATCH: func_00226c40, actual src/promoted/code1_0022.c owner, configured
 * MWCCPS2 b210 -O2 with scoped opt_common_subs off. 1516/1520 bytes,
 * 0 normalized differences, all 48 code relocations fully resolved and
 * 0 differing code bytes. All seven R_MIPS_32 switch-table relocations at
 * 0x00747870 match retail; the final four code-window bytes are zero alignment.
 *
 * Supersedes the old archive's 1412/1520-byte, 989-difference candidate.
 * The replacement uses actual 16-byte quaternions and complete 28-byte poses,
 * three real 56-byte pose pairs, packed RwRGBA by value, separate wrapping
 * ordinals, and u32 frames before float conversion. No invented padding,
 * undefined output, incoming argument, inline assembly or pinned register.
 * This snapshot is for the current owner context, not a standalone translation
 * unit. Full-byte comparisons verify compiled output, not game execution.
 *
 * The following reconstruction-stage evidence predates compilation; its
 * no-validation statements apply only to that investigation phase. Source
 * line references identify investigation-time snapshots; symbols and retail
 * addresses are authoritative. The matching measurements above are later
 * checks of the actual integrated owner.
 *
 * func_00226c40 contract and retail evidence
 * ========================================
 * Scope: 0x00226C40 through 0x00227230, 0x5F0/1520 bytes. Complete authoritative retail body read from asm/nonmatchings/code1_0022/func_00226c40.s. Companion provider assembly was read from asm/code1.s because already-promoted provider ASM files are absent. No compiler, build, formatter, linter, test, or smoke validation was run.
 *
 * ABI and real caller
 * -------------------
 * void func_00226c40(u8 *camera). Only a0 is a semantic input. There are no incoming float arguments, additional register arguments, or incoming stack arguments. The retail return path does not establish an application result; caller ignores v0/f0. Stack frame is 0x120, preserving s0-s3, ra and f20.
 *
 * GP=0x7690F0. lw -0x4C54(gp) reads the battle-root pointer at absolute 0x76449C (iGpffffb3ac; the current owner also has the address-named DAT_0076449c declaration). Camera is root+0x24. func_001bc660 writes its real action input to root+0x104 at 0x001BC764, then loads callback from dispatch-entry+0 at 0x001BC7B0, forms a0=root+0x24 at 0x001BC7C0 and jalr at 0x001BC7C4. Hence camera+0xE0 is exactly root+0x104 and is the action established by the caller. No f12 or extra input should be invented.
 *
 * Authoritative image.bin data (VRAM=file offset+0x100000, config/slus21782.yaml):
 *   0x634AA4 = D_006348B0 + 0x19*0x14: [0x226C40,0,1,1,0].
 *   0x634D8C = D_00634CB0 + 0x0B*0x14: [0x226C40,0,1,1,0].
 *   0x634DF0 = D_00634CB0 + 0x10*0x14: [0x226C40,0,1,1,0].
 *   0x634EA4 = D_00634CB0 + 0x19*0x14: [0x226C40,0,1,1,0].
 * All are non-null initializer callbacks with forced reentry (entry+8=1). func_0022cdb0 returns these 20-byte entries when root+0x10 bit 0x10 is set: general table D_006348B0 except battle 0x20B with root+0xC40==0 selects D_00634CB0. Battle 0x215 and alternate 0x20B select D_006350B0, not one of these target entries. func_001bd7d0 calls entry+4 instead; all four above have zero there, so this target is an initializer, not that updater. Graph inbound search returning zero for the target is incomplete indirect-call metadata, not absence of reachability.
 *
 * Memory inputs and direct outputs
 * --------------------------------
 * Preconditions are the real initialized battle-camera/action/unit records, not fabricated NULL-tolerant behavior. Retail loads action+0x30 at 0x226C64 and unit+0xA0C at 0x226C68 BEFORE checking action at 0x226C6C. Keep this order; a NULL action is not a supported input. Unit and target-unit pointers are likewise actual initialized actor records. Subordinate alone is allowed to be NULL.
 *   camera+0xE0: action pointer, reloaded at every retail use across calls.
 *   action+0x30: actor unit pointer.
 *   action+0x38+4*(u16)index: target action pointers, each +0x30 gives target unit.
 *   action+0x6A: u16 target count, reloaded in initial loop condition.
 *   action+0x1A: u16 flags, bit 1 gates state 6.
 *   unit+0xA2: u8 genus (actor=0, rotated targets=1).
 *   unit+4: 12-byte position; rotation provider actually uses x and z.
 *   unit+0xA0C: subordinate pointer, captured before any provider call.
 *   subordinate+0x30,+0x31,+0x32: RGB, read AFTER func_0019d0c0; alpha is explicitly zero.
 *   root+0x17C: actor-party linked-list head; each node+0xA68 is next.
 *   root+0xB98: current camera-data base.
 *   camera+0x110: u16 mode written from low 16 bits of func_001c0e50 result and subsequently reloaded. func_001c5110 can recompute this mode; no stale cached value is used after it.
 * Only direct non-stack target store is camera+0x110. Other state changes occur through the real providers below.
 *
 * Counters are u32 temporaries with explicit u16 masks on condition, indexing and update. Both index=(u16)(index+1) and ordinal=(u16)(ordinal+1) wrap. The party walk returns the wrapped number traversed if no equal actor is found; it must NOT fabricate a found-only guard or clamp. Nonzero actor genus selects partyIndex=0 without walking. Random variant is called before this genus test, always in states 3/5.
 *
 * Full switch table and instruction-region accounting
 * --------------------------------------------------
 * jtbl_00747870, 7 little-endian words read directly from image.bin:
 *   state 0 -> 0x226D98
 *   state 1 -> 0x226D98
 *   state 2 -> 0x226D98
 *   state 3 -> 0x226E04
 *   state 4 -> 0x226D98
 *   state 5 -> 0x226E04
 *   state 6 -> 0x226FB8
 * Unsigned modes >=7 go directly to 0x227208. Retain state 0 even though the current classifier normally returns 1..6.
 *   226C40-226C68: frame/save and camera/action/unit/subordinate capture.
 *   226C6C-226CD8: conditional wrapping target loop; genus-1 target rotates toward actor.
 *   226CDC-226CE8: classifier call and low-halfword mode store.
 *   226CEC-226D08: materialized non-null subordinate && matching predicate.
 *   226D0C-226D58: when predicate true and mode!=1, hide subordinate and preserve its RGB while alpha becomes 0.
 *   226D5C-226D68: unconditional nullable subordinate state/value reset call.
 *   226D6C-226D94: unsigned seven-entry switch dispatch.
 *   226D98-226E00: states 0/1/2/4 call func_001c5110, then require count==1, actor genus==0, target action != action, target genus==0; only then visibility mode 8. Every failed condition exits the switch. Unlike func_002277e0, 2/4 do NOT test before generic dispatch and do NOT fall into selected poses.
 *   226E04-226E6C: states 3/5 get variant, select wrapped actor-party ordinal.
 *   226E6C-226EB0: record=base+0x3A8+(u16)partyIndex*0x68+(u16)variant*0x34.
 *   226EB0-226F14: two orientation outputs and two 12-byte position copies.
 *   226F18-226F60: unsigned frames-to-float conversion then divide by 30.0f. Retail emits general unsigned conversion branch though lhu makes its negative arm dynamically unreachable; u32 frames preserves the ordinary-C unsigned conversion shape.
 *   226F64-226FAC: consume both poses, start duration, apply visibility mode 0x100.
 *   226FB0-226FB4: exit selected path.
 *   226FB8-226FD8: state-6 action flag and actor-genus split.
 *   226FDC-2270C8: genus0 fixed record base+0x618, two poses, unsigned frames/30 and pose/duration calls.
 *   2270CC-2270D0: join visibility call at 2271EC.
 *   2270D4-227104: nonzero genus gets fresh variant; record=base+0x64C+(u16)variant*0x34.
 *   227108-2271E8: two poses, unsigned frames/30 and pose/duration calls.
 *   2271EC-227204: shared state-6 visibility mode 0x100.
 *   227208-227228: restore and void return. 22722C is one zero tail-alignment word, not source behavior.
 * All branch delay slots in this target are nops. No instruction region is dropped.
 *
 * Pose object and provider extents (defined-producer proof)
 * -------------------------------------------------------
 * CameraPosePair is the existing owner's local layout: RwV3d first (12), RtQuat firstRotation (16), RwV3d second (12), RtQuat secondRotation (16). Offsets 0,0xC,0x1C,0x28; size 56, no padding fields. Separate selected/player/other objects preserve three retail stack lifetimes. The caller passes each 28-byte pose to func_001bac20, so representing the real contiguous poses is necessary, not an artificial aggregate.
 *   selected retail stack: first E0-E8; firstRotation EC-F8; second FC-104; secondRotation 108-114.
 *   player: first A0-A8; firstRotation AC-B8; second BC-C4; secondRotation C8-D4.
 *   other: first 60-68; firstRotation 6C-78; second 7C-84; secondRotation 88-94.
 *   color: 11C-11F, all four bytes explicitly produced.
 * Unwritten stack gaps 98-9F, D8-DF, 118-11B are NOT represented as fields or consumed.
 *
 * Every selected 0x34-byte camera-data record supplies u16 frames at +0, 12-byte first position at +4, 12-byte first look-at at +0x10, 12-byte second position at +0x1C, and 12-byte second look-at at +0x28 (last read ends +0x33). Record bytes +2,+3 are unused. No fourth vector component is read from any 12-byte source vector.
 *
 * func_001bd780(out, first, second, up), six calls at 226EC4,226EF8,226FFC,227030,22711C,227150:
 *   a0 points to one full 16-byte RtQuat, a1/a2/a3 each to 12 initialized bytes. It calls func_001bd620(localMatrix, second, first, up), then RtQuatConvertFromMatrix(out,localMatrix). func_001bd620 reads xyz only from its three vectors and writes xyz at matrix offsets 0/0x10/0x20/0x30, each exactly 12 bytes. Matrix lane/flag words +0xC,+0x1C,+0x2C,+0x3C remain unproduced but are not read by the quaternion converter.
 *   RtQuatConvertFromMatrix at 3DC610 reads only the nine initialized upper-3x3 floats. Positive-trace path stores out+0xC at 3DC6E0, +0 at 3DC70C, +4 at 3DC718, +8 at 3DC720. Nonpositive-trace helpers also write all four: 3DC490 stores at 3DC4E0/4E8/4F0/508; 3DC510 at 3DC560/568/570/588; 3DC590 at 3DC5E0/5E8/5F0/608. Neither NULL branch can occur with the target's real stack addresses. Thus exact output extent is out[0..15] on every target-reachable path; never 12 or 28 bytes.
 *   Each adjacent RwV3d in body.c is assigned from its three source floats AFTER the associated provider call. All seven floats of each pose are therefore produced before any consumer reads them.
 *
 * func_001bac20(work, firstPose, secondPose, 1), calls 226F78,2270B0,2271D0:
 *   a0=root+0x24, a1/a2 point to fully produced 28-byte poses, a3=1. Reads each pose's position +0,+4,+8 and quaternion +C,+10,+14,+18; last quaternion reads are retail 1BACF0 / 1BAF90. Source extent is exactly 28 bytes each, not RwV3d alone and not a matrix.
 *   Writes u16 work+0,+74,+76,+78; u32 work+7C,+80; and four seven-float queue slots work+4 through +73 (stride 1C). Slots are first pose, two func_001ba790 intermediates and second pose. No caller stack/output mutation. Interpolation weights are GP -7F40 at 0x7611B0 = 0x3EAAAAAB (1/3 rounded), GP -7F38 at 0x7611B8 = 0x3F2AAAAB (2/3 rounded). Mode bit1 suppresses the work+98 external path provider, so those handle reads/calls are not target-reachable. Internal func_001ba790 writes all 7 floats: xyz before quaternion precompute, then either endpoint quaternion or computed four components. This is a consumer of initialized full poses, not an output-extent ambiguity in the target.
 *
 * func_001bbef0(work,duration), calls 226F8C,2270C4,2271E4:
 *   a0=root+24, f12=frames/30.0f. Writes float +84=(duration*2*60)/2 and +94=0.5f; reads/modifies u16 +0 with &FFF5 then |4. No pose input and no caller-stack output.
 *
 * Other provider contracts
 * ------------------------
 * func_00195590 at 226CB4: a0=genus1 target unit, a1=actor+4. func_001ec1c0 reads source/target x,z (+0,+8), produces the 16-byte yaw quaternion via func_003dc740 mode0. func_00195590 copies all four quaternion floats to unit+1C..2B unless unit+9C bit2000 is set, then ORs unit+98 with4; always invokes func_0019dea0(unit). No write to actor position. Target consumes no provider output buffer here.
 * func_001c0e50 at 226CE0: a0=camera; s32 classification in v0, low16 stored. Reads action/target records, action+6E signed skill, actor+ A2/A0C/A64 and the existing query providers; current source returns 1..6. No target-side invented return value.
 * func_0022f950 at 226D00: a0=current action, a1=subordinate, called only if subordinate!=NULL; s32 v0 converted to bool. Provider's current source reads battle root+0C, subordinate+A4, corresponding iGpffffb3e0+id*58 flags and action+6E through real predicates. No output buffer consumed.
 * func_0019d0c0 at 226D28: a0=subordinate. Reads/modifies +9C (sets1000 then clears2), calls func_0019d990(unit,5), reads u16 +9FE and calls func_0014b0c0(value,0) if nonzero. RGB is loaded only after it returns.
 * func_00194f60 at 226D54 is the renamed btlUnitSetColor, NOT a new extern. a0=subordinate; a1 is all four RwRGBA bytes by value. Copies to unit+30..33 and ORs unit+98 with4. Target color alpha has an explicit zero producer.
 * func_0019de70 at 226D64: a0=subordinate (nullable), a1=0. NULL returns immediately; otherwise reads u8 +A2 and writes u8 +AC only if genus==2. Unconditional call in target is intentional and safe for NULL.
 * func_001c5110 at 226D9C: a0=camera; void. Recomputes/stores camera+110, updates +114 from subordinate predicate and calls the real generic pose routines selected by state. State1/2/3/4/5/6 call 1C17A0/1C21D0/1C2EE0/(1C3F70 or1C21D0)/1C2EE0/1C1040. No target stack output consumed. Reload action after it returns.
 * func_00231d70 at 226E10 and 2270D8: a0=2, returns RpRandom()%2 as u32. Low16 retained as variant; no output buffer. Exactly one call on states3/5 and on nonzero-genus state6, none on genus0 state6.
 * func_001bcd40 at 226DF4,226FA8,227200: a0=action, a1=NULL,a2=NULL,a3=8 or100,f12=0.0f. The owner declaration's mode-before-float argument order is preserved. Both nullable vector arguments are gated at 1BCD94/1BCD9C and 1BD188/1BD190, so no absent vector is dereferenced and no unproduced rectangle state is consumed. Global root+10 bit4 can disable all behavior. Otherwise provider walks action list root+174 via node+450, filtering action+1A bit1 and actor+9C bit8. Mode100 clears unit flag2 and writes unit+37=FF for eligible actors; mode8 clears flag2/writes FF for same-genus actors, otherwise sets flag2/writes +37=0. All actions are through existing real providers; no output buffer or return is consumed by target.
 *
 * Authoritative literals and dynamic record providers
 * --------------------------------------------------
 * Target has only one GP-relative global: root pointer at 76449C. No GP floating literal occurs in the target. Immediate 0x41F00000 is 30.0f; float zero arguments are positive 0.0f from mtc1 zero. D_0060A0E0 contains raw words [00000000,3F800000,00000000,00000000], interpreted as up=(0,1,0); the last word is not consumed.
 *
 * Current owner func_0022bd60 populates root+B98 with static camera data for battles 200..20B,20D,214,215, and func_0022db90 switches it for enemy identities 102/10D/103/110/111. Read source sections 2244-2375 and 2977-3004. Actual bases are:
 * 629750,629EA0,62A5F0,62AD40,62B490,62BBE0,62C330,62CA80,62D1D0,62D920,62E7C0,62EF10,62F660,62FDB0,630500,630C50,6313A0,631AF0.
 * Target uses selected records at base+3A8+ordinal*68+variant*34; genus0 state6 at base+618; other state6 at base+64C+variant*34. These are real immutable image vectors/durations, not synthesized pose output. The stored five ordinal groups occupy +3A8..+5AF; the C intentionally preserves retail's unchecked wrapped ordinal rather than adding a clamp or absent-actor special case.
 * Read authoritative frame halfwords in all 18 bases: selected indices0..9 usually [90,90,90,90,90,90,90,90,60,60]; 630500 has ten90s; 630C50 has [120,90,90,90,90,90,90,110,60,110]. State6 three records usually [150,150,150]; 62D920 is [120,120,120]; 630500 is [150,120,120]. The C keeps the runtime u16 loads and conversion rather than baking these observations into behavior.
 *
 * No genuine undefined-output blocker was found in this target. All locally consumed pose bytes and all color bytes have concrete preceding producers. Existing external-object initialization and valid-record preconditions remain retail's, including its pre-check action dereference and unchecked party indexing; the candidate neither strengthens nor masks them.
 */

#pragma opt_common_subs off
void func_00226c40(u8 *camera)
{
    RwRGBA color;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *subordinate;
    u8 *target;
    u8 *node;
    u8 *record;
    u32 index;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u32 frames;
    s32 matchesSubordinate;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    subordinate = *(u8 **)(unit + 0xA0C);
    if (action != NULL && *(u8 *)(unit + 0xA2) == 0) {
        index = 0;
        while ((action = *(u8 **)(camera + 0xE0)),
               (u16)index < *(u16 *)(action + 0x6A)) {
            target = *(u8 **)(action + 0x38 + (u16)index * 4);
            target = *(u8 **)(target + 0x30);
            if (*(u8 *)(target + 0xA2) == 1) {
                func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
            }
            index = (u16)(index + 1);
        }
    }
    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    matchesSubordinate = subordinate != NULL &&
        func_0022f950(*(u8 **)(camera + 0xE0), subordinate) != 0;
    if (matchesSubordinate && *(u16 *)(camera + 0x110) != 1) {
        func_0019d0c0(subordinate);
        color.red = *(u8 *)(subordinate + 0x30);
        color.green = *(u8 *)(subordinate + 0x31);
        color.blue = *(u8 *)(subordinate + 0x32);
        color.alpha = 0;
        btlUnitSetColor((BtlUnit *)subordinate, color);
    }
    func_0019de70((BtlUnitStateWork *)subordinate, 0);
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
    case 1:
    case 2:
    case 4:
        func_001c5110(camera);
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) != 1) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) != 0) {
            break;
        }
        target = *(u8 **)(action + 0x38);
        if (action == target) {
            break;
        }
        if (*(u8 *)(*(u8 **)(target + 0x30) + 0xA2) != 0) {
            break;
        }
        func_001bcd40(action, NULL, NULL, 8, 0.0f);
        break;
    case 3:
    case 5:
        action = *(u8 **)(camera + 0xE0);
        unit = *(u8 **)(action + 0x30);
        variant = func_00231d70(2);
        if (*(u8 *)(unit + 0xA2) != 0) {
            partyIndex = 0;
        } else {
            ordinal = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node) {
                    break;
                }
                ordinal = (u16)(ordinal + 1);
                node = *(u8 **)(node + 0xA68);
            }
            partyIndex = (u16)ordinal;
        }
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x68 + (u16)variant * 0x34 + 0x3A8;
        func_001bd780(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
        selected.first = *(RwV3d *)(record + 4);
        func_001bd780(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
        selected.second = *(RwV3d *)(record + 0x1C);
        frames = *(u16 *)record;
        duration = (f32)frames / 30.0f;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                      (f32 *)&selected.first, (f32 *)&selected.second, 1);
        func_001bbef0(iGpffffb3ac + 0x24, duration);
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            func_001bd780(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            func_001bd780(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        } else {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            func_001bd780(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            func_001bd780(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            func_001bac20((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            func_001bbef0(iGpffffb3ac + 0x24, duration);
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0x100, 0.0f);
        break;
    default:
        break;
    }
}
#pragma opt_common_subs on
