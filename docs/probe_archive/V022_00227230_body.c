/*
 * MATCH: func_00227230, actual src/promoted/code1_0022.c owner, configured
 * MWCCPS2 b210 -O2 without a function-local pragma. 1336/1344 bytes,
 * 0 normalized differences, all 48 code relocations fully resolved and
 * 0 differing code bytes. All seven R_MIPS_32 switch-table relocations at
 * 0x00747890 match retail; the final eight code-window bytes are zero alignment.
 *
 * Supersedes the old archive's 1248/1344-byte, 839-difference candidate.
 * The replacement uses actual 16-byte quaternions and complete 28-byte poses,
 * three real 56-byte pose pairs and u32 frames before float conversion. The
 * case-1, case-2, case-4 and case-3/5 fallthrough paths remain distinct.
 * No invented padding, undefined output, incoming argument, inline assembly
 * or pinned register. This snapshot is for the current owner context, not a
 * standalone translation unit. Full-byte comparisons verify compiled output,
 * not game execution.
 *
 * The following reconstruction-stage evidence predates compilation; its
 * no-validation statements apply only to that investigation phase. Source
 * line references identify investigation-time snapshots; symbols and retail
 * addresses are authoritative. The matching measurements above are later
 * checks of the actual integrated owner.
 *
 * TARGET AND INPUT ABI
 * func_00227230: retail 0x00227230..0x00227770, 0x540-byte window.
 * Single live input is a0 = u8 *camera. No incoming float or additional integer argument is read. Frame is 0x100; s0, s1, f20 and ra are saved. Return is void: 0x22774C..0x227764 restores and returns without constructing a result, and the real caller uses a void callback.
 * Direct camera accesses: read pointer +0xE0; write u16 +0x110 from func_001c0e50 and read it for dispatch; zero u32 +0x12C. action = *(u8 **)(camera+0xE0) must be live. action+0x1A is a u16 flag word; action+0x30 is the unit pointer; action+0x38 begins its embedded BtlTarget. Unit+0xA2 is its genus byte, +0xA0C is the subordinate-state pointer, and +0xA64 is its unit-data pointer. Null guards are not invented at these loads.
 *
 * REAL CALLER REACHABILITY
 * Retail ELF contains aligned pointers to this function at 0x634AB8 and 0x634EB8. Each complete 20-byte entry is [0x227230, 0x227770, 1, 1, 0]. They are entry 0x1A of D_006348B0 and D_00634CB0, respectively (offset 0x208 = 26*0x14).
 * src/promoted/code1_0022.c:2631-2664, func_0022cdb0, selects these tables when the battle global+0x10 has bit 0x10: the default encounter branch selects D_006348B0; encounter 0x20B with global+0xC40 == 0 selects D_00634CB0. Its other branches use D_006350B0 instead.
 * src/Battle/btlCamera.c:297-346, func_001bc660, gets that entry, writes the caller's BtlAction * to global+0x104, and invokes *(void (**)(u8 *))entry with global+0x24. Therefore camera+0xE0 is exactly that same global+0x104 action slot. Entry+8 is 1, so this callback is permitted even when the selected state is unchanged. The callback does not consume a return value. Input action is the real BtlAction * supplied to the state transition, not a fabricated or hidden argument.
 *
 * COMPLETE AUTHORITATIVE JUMP TABLE
 * Read directly from orig/SLUS_217.82's PT_LOAD mapping: file offset = virtual address - 0x100000 + 0x80.
 * jtbl_00747890, seven little-endian words:
 *   0 -> 0x0022774C (epilogue)
 *   1 -> 0x002272C0 (flag-0x10 special camera)
 *   2 -> 0x002272E8 (first target-mask test)
 *   3 -> 0x002273B0 (selected-target pose test)
 *   4 -> 0x00227324 (unit/action predicates and alternative camera)
 *   5 -> 0x002273B0 (same selected-target pose test)
 *   6 -> 0x002274FC (action-flag-1 pose branch)
 * Unsigned dispatch >=7 goes directly to 0x22774C. Case 0 is also a no-op after the common preamble.
 * Case 1 calls func_001c5110 and exits if reloaded action flags contain 0x10; otherwise falls into case 2. Case 2 calls func_002266b0 and exits if target bit 2 is clear; otherwise falls into case 4. Case 4 independently repeats that mask test. If clear, short-circuit func_00243ce0(unit-data) && func_0019fc70(action) chooses func_002250a0; failure chooses func_002266b0. If set, it falls into cases 3/5. Cases 3/5 with bit 2 set use selected poses; if clear, fall into case 6. Case 6 exits unless action flags have bit 1, then chooses player or other poses from genus == 0 versus nonzero. Both subpaths converge at 0x227730 for func_001bcd40.
 *
 * GLOBALS AND LITERALS
 * GP = 0x7690F0. The ONLY target-body GP-relative slot is lw -0x4C54(gp), address 0x76449C, owner spelling iGpffffb3ac (DAT_0076449c is an existing alternate owner spelling). It is a runtime pointer, not the literal zero initially present in the ELF. Its +0xB98 is a pointer to camera-record data; its +0x24 is the real camera work area.
 * D_0060A0E0 is the three-float up vector at VA 0x60A0E0. ELF words are [0x00000000,0x3F800000,0x00000000] = (0,1,0). Do not substitute an invented fourth component.
 * Immediate floating constants: 0.0f = 0x00000000; 3.0f = 0x40400000; 2.0f = 0x40000000; 0.75f = 0x3F400000; 30.0f = 0x41F00000. There are no target-body floating GP loads.
 *
 * RECORD INPUT EXTENTS
 * Every camera record is 0x34 bytes: duration u16 at +0; bytes +2..+3 are not consumed here; position A is three floats at +4,+8,+0xC; look-at A is three floats at +0x10,+0x14,+0x18; position B is +0x1C,+0x20,+0x24; look-at B is +0x28,+0x2C,+0x30.
 * Selected branch record = *(global+0xB98) + 0x5B0 + (u16)func_00231d70(2)*0x34.
 * Player branch record = *(global+0xB98) + 0x618.
 * Other branch record = *(global+0xB98) + 0x64C + (u16)func_00231d70(2)*0x34.
 * func_00231d70 (src/Main/Battle/Data/datCalc.c:111-117) returns RpRandom()%arg0, so these real calls return 0 or 1. It consumes a0=2; v0 is narrowed to u16 before indexing. Frames are read with lhu but widened to u32 before conversion to float and division by 30.0f; preserve that u32 expression type.
 *
 * POSE PROVIDER OUTPUT PROOF
 * func_001bd780(out, first, second, up): a0/a1/a2/a3 are four pointers. src/Battle/btlCamera.c:435-470 builds a local matrix by calling func_001bd620(matrix, second, first, up), then calls RtQuatConvertFromMatrix(out,matrix). Each source vector read is exactly three floats. The retail 0x1BD780 wrapper's two calls are 0x1BD7A0->0x1BD620 and 0x1BD7B0->0x3DC610, with a0 restored to the requested output for the second call.
 * RtQuatConvertFromMatrix at 0x3DC610 was read completely. Its only no-write path is a null output or matrix; neither is null for this caller, where they are addresses of actual automatic objects. Its matrix reads are the 3x3 elements at offsets 0,4,8,0x10,0x14,0x18,0x20,0x24,0x28; it does not consume the matrix's uninitialized stride/flag words.
 * Every nonnull conversion path writes precisely four floats, output bytes 0..15:
 *   Positive-trace branch: swc1 at 0x3DC6E0 (+0xC), 0x3DC70C (+0), 0x3DC718 (+4), 0x3DC720 (+8).
 *   X-dominant helper 0x3DC490: stores 0x3DC4E0 (+0), 0x3DC4E8 (+0xC), 0x3DC4F0 (+4), 0x3DC508 (+8).
 *   Y-dominant helper 0x3DC510: stores 0x3DC560 (+4), 0x3DC568 (+0xC), 0x3DC570 (+8), 0x3DC588 (+0).
 *   Z-dominant helper 0x3DC590: stores 0x3DC5E0 (+8), 0x3DC5E8 (+0xC), 0x3DC5F0 (+0), 0x3DC608 (+4).
 * Thus RwV3d is 12 bytes, RtQuat is 16 bytes, and each legitimate CameraPosePair is 56 bytes: first position at +0, first rotation +0xC, second position +0x1C, second rotation +0x28. No padding or invented aggregate extent is needed.
 * Actual target stack producers/consumers:
 *   selected: first at sp+0xC0, quaternion at +0xCC; second at +0xDC, quaternion at +0xE8. Quaternion calls 0x227408/0x22743C; position stores 0x22741C..424/0x227450..458; consumer 0x2274BC.
 *   player: first at sp+0x80, quaternion at +0x8C; second at +0x9C, quaternion at +0xA8. Quaternion calls 0x227540/0x227574; position stores 0x227554..55C/0x227588..590; consumer 0x2275F4.
 *   other: first at sp+0x40, quaternion at +0x4C; second at +0x5C, quaternion at +0x68. Quaternion calls 0x227660/0x227694; position stores 0x227674..67C/0x2276A8..6B0; consumer 0x227714.
 * Each consumer is dominated by both 16-byte quaternion writes and both 12-byte position writes on that same branch. Unused pairs need no initialization and are never passed anywhere.
 *
 * OTHER PROVIDER CONTRACTS
 * func_001bac20(cameraWork, firstPose, secondPose, 1): a0=u16* destination, a1/a2 point to separate seven-float poses, a3=1; return ignored. Complete current source is src/Battle/btlMain.c:924-1091. It reads each pose's three position and four quaternion floats, interpolates two additional poses through func_001ba790, and fills four 0x1C-byte destination entries beginning at work+4. It also writes mode u16 at +0, u16 fields +0x74/+0x76/+0x78, and zero words +0x7C/+0x80. For mode 1 it skips the alternate func_003bb4a0 path. func_001ba790 source at src/promoted/code1_001b.c:1737-1817 consumes only the same two seven-float input poses and produces a full seven-float intermediate. No target-owned output beyond 56 contiguous bytes is consumed.
 * func_001bbef0(cameraWork,duration): a0=global+0x24, f12=(float)(u32)frames/30.0f; src/Battle/btlMain.c:1381-1387 writes work+0x84 with (duration*2*60)/2, +0x94 with 0x3F000000, and updates u16 flags at +0 to (flags & 0xFFF5)|4. It reads no target stack pointer.
 * func_001bcd40(action,NULL,NULL,0x100,0.0f): a0=live action, a1=a2=0, a3=0x100, f12=0; return ignored. Retail 0x1BCD94..1BCDD0 explicitly takes the null-input path and zeroes f20 rather than reading either optional pose pointer. With mask 0x100, each active list action (global+0x174, next +0x450) whose unit+0x9C has bit 8 goes through 0x1BCF10..1BCF50: func_00194fc0(unit,2), unit+0x37=0xFF, then next node. Global+0x10 bit 4 skips the whole operation. No local pose is consumed by this call.
 * func_001c0e50(camera): a0 camera, s32 state in v0 narrowed to u16. src/promoted/code1_001c.c:134-189 reads the live action/skill/target/unit data and computes states 1..6. Cases 0/default are nevertheless preserved because the retail table explicitly has them. Initial state is stored before the target-mask provider and subordinate update.
 * func_001eb440((BtlTarget *)(action+0x38)): a0 target; u16 result in v0. src/Battle/btlTarget.c:87-98 ORs 1<<targeted-action-unit genus across targetedCount. It has no output pointer. targetFlags is captured once, before the subordinate callback, as in retail.
 * func_0019de70(subordinate,1): a0=*(BtlUnitStateWork **)(unit+0xA0C), a1=1. src/Battle/btlUnit.c:1281-1287 only writes its u8 value when work is nonnull and its state is 2. Retail caller performs no extra null test.
 * func_00243ce0(unitData): a0=unit+0xA64 pointer; s32 predicate in v0. src/Main/Battle/Data/datCalc.c:2705-2717 consumes u16 flags/id at +0/+2 and the corresponding global unit table entry. No target output pointer.
 * func_0019fc70(action): a0 live action; s32 predicate in v0. Complete src/promoted/code1_0019.c:3909-3983 consumes action skill at +0x6E, unit pointer +0x30, unit-data id, genus, and existing skill/unit tables. Called only if the preceding predicate succeeds. No target-owned stack output is passed.
 * func_002250a0(camera,0.0f,0.75f): a0 camera, f12=0, f13=0.75; existing owner prototype retained, return ignored. No invented additional floats or output arguments.
 * func_002266b0(camera,0.0f,3.0f,0.0f,2.0f): a0 camera; f12/f13/f14/f15 are 0/3/0/2 respectively, return ignored. Current exact source src/promoted/code1_0022.c:877-1015 constructs its own fully initialized poses, sets unit visibility via func_001bcd40, commits through func_001bac20, and sets duration through func_001bbef0. Caller exposes no local output pointer.
 * func_001c5110(camera): a0 camera; void. Current src/promoted/code1_001c.c:302-351 recomputes camera+0x110 and writes camera+0x114 subordinate-match state before its own dispatcher. This is why the case-1 action flag is reloaded rather than assumed unchanged from the preamble. It consumes no caller-owned pose memory.
 *
 * EVIDENCE STATUS
 * Entire target ASM and seven ELF table words were read; provider extents and callback reachability were established from current source and retail instructions. Graph/CSP discovery was used, with coverage checks confirming stale source metadata and partial ASM indexing; current direct reads are authoritative. No compiler, build, formatter, lint, test, runtime probe or matching validation was run, as assigned. There is no identified retail undefined-state blocker in this target's local pose paths.
 */

extern s32 func_0019fc70(u8 *action);

void func_00227230(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *record;
    u16 targetFlags;
    u16 variant;
    u32 frames;

    *(u16 *)(camera + 0x110) = func_001c0e50(camera);
    targetFlags = func_001eb440((BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38));
    *(u32 *)(camera + 0x12C) = 0;
    action = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
        func_0019de70(*(BtlUnitStateWork **)(*(u8 **)(action + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
        break;
    case 1:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
            func_001c5110(camera);
            break;
        }
    case 2:
        if (((u16)targetFlags & 2) == 0) {
            func_002266b0(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 4:
        if (((u16)targetFlags & 2) == 0) {
            if (func_00243ce0(*(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x30) + 0xA64)) != 0 &&
                func_0019fc70(*(u8 **)(camera + 0xE0)) != 0) {
                func_002250a0(camera, 0.0f, 0.75f);
                break;
            }
            func_002266b0(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 3:
    case 5:
        if (((u16)targetFlags & 2) != 0) {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
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
        }
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
