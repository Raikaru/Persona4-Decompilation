/*
Exact ordinary-C recovery, integrated in src/promoted/code1_0022.c.
object_size=2444; window=2448; normalized_diff=0; fully_resolved_code_relocations=56; resolved_differing_bytes=0; zero_tail_bytes=4.
The previous unprobed COP1-accumulator triage is superseded: ordinary C emits the retail accumulator chains.
The geometry workspace contains four real two-float vectors and one complete 56-byte pose pair, with no padding members. Scoped opt_scalarize off retains their real stores.
Case-label order, a shared cut-allowed path, explicit ordinal/address views, mode declaration order, height evaluation order and staged floating products close the measured source differences.
Both camera poses have all seven floats produced before use. The real live-action callback chain and the preserved null-action caveat are recorded below.
Verification is actual owner compilation and complete relocation resolution, not camera/game execution.

func_00229020 input ABI and reachability
=======================================
Target retail 0x00229020..0x002299B0, 0x990 bytes, complete 650-line ASM read. Incoming a0 is the sole live parameter, u8 *camera. No incoming floating argument, a1/a2/a3 or caller-stack argument is consumed. Frame 0x1C0 saves ra, s0..s5, f20..f23. Void callback, no result construction.

The actual retail ELF PT_LOAD has file offset 0x80, VA 0x100000 and size 0x838A00; file offset for mapped VA is VA-0x100000+0x80. Aligned callback-pointer data read directly from orig/SLUS_217.82:
  0x634A68, 0x634A7C: D_006348B0 entries 0x16 and 0x17.
  0x634E68, 0x634E7C: D_00634CB0 entries 0x16 and 0x17.
  0x635268, 0x63527C: D_006350B0 entries 0x16 and 0x17.
Each complete 20-byte entry is [0x229020,0,1,1,0]. No target-internal switch table exists: the entire target consists of direct conditional/unconditional branches and direct calls.

Current func_0022cdb0 (src/promoted/code1_0022.c) uses those three tables when root+0x10 bit 0x10 is set: default D_006348B0, encounter 0x20B with root+0xC40 zero D_00634CB0, otherwise that encounter and 0x215 D_006350B0. Table entry offset is (u16)state*0x14.
Current func_001bc660 (src/Battle/btlCamera.c) writes the transition's BtlAction * to root+0x104 immediately before invoking entry[0] with root+0x24. Therefore camera+0xE0 is that exact action slot. Entry+8=1 permits reinvocation for unchanged state; entry+4=0 means no update callback in these entries. The callback result is unused.
Concrete scheduling producer: full asm/nonmatchings/code1_001a/func_001a4c80.s was read. Its entry preserves incoming action a0 in s4 at 0x1A4CB4 and immediately consumes action+0x6E at 0x1A4CB8. s4 is never reassigned in its body. It reads action+0x30 and target action at +0x38 on the paths that build movement packets. At 0x1A54E8 it skips the camera schedule if movement packet is null, and 0x1A54F0 skips if s7!=0. Otherwise s6==0 schedules func_001bc920(action,0x16) at 0x1A5508; s6!=0 schedules func_001bc920(action,0x17) at 0x1A5538. Both a0 values are s4, the real already-consumed live action, not a fabricated input. Calls are queued by func_00194590 after setting packet+0x60 to action UID. func_001bc920 is btlCameraCreateSetStatePacket at 0x1BC920, which writes work->action and work->state. btlCameraUpdateSetStatePacket at 0x1BC8E0 forwards these to func_001bc660(state,action,1).

NULL ACTION CAVEAT (preserved, not repaired)
The slot genuinely supports null in the camera subsystem: func_001bc800 clears root+0x104 when an action UID matches, and func_001bc660 accepts nullable actions for other camera states. Target itself branches over rotation for a null action at 0x229058 and sets allowCut=1 at 0x2290D4, then unconditionally executes lw s2,0x30(a0) at 0x22915C with a0 still zero on that branch. This is not an overlooked alternate producer or permission to add an early return. Candidate retains the null conditional and the later unconditional action dereference. It is defined for the real live-action scheduling chain above; this is not a null-safe API and no claim is made that invoking this target with null has defined C behavior. No real null-action schedule for states 0x16/0x17 was established, so this is not asserted as a reachable local undefined-state blocker.

Input object fields
===================
action+0x30 is actor BtlUnit*, +0x38 begins target-action pointer array, +0x6A is u16 count. Each target action+0x30 is target unit. Unit+0xA2 is u8 genus; +4 is position; +0x2C is scale; +0x8C and +0x90 are the scalar bounds used by retail. Target loop captures actor before calls, reloads action from camera+0xE0 at every condition, narrows index to u16 for test and address, and assigns index=(u16)(index+1). Only genus-1 targets rotate toward a genus-0 actor.
func_00195590(BtlUnit*, const RwV3d*) current src/Battle/btlUnit.c computes rotation through func_001ec1c0(unit position,target), conditionally stores all four quaternion floats unless NOROT, marks DIRTY, and calls func_0019dea0. It consumes actor+4 three-float vector and writes target unit, not local output.

Global and literal sources
==========================
GP=0x7690F0. root/iGpffffb3ac is lw -0x4C54(gp), runtime pointer slot VA 0x76449C, not its initial ELF zero. root+0x108 is previous u16 camera state, produced by func_001bc660 copying root+0xF4 before installing the new state. root+0xB98 is the active camera-record table pointer. Current func_0022bd60 selects actual static tables D_00629750 through D_00631AF0 by encounter, with further encounter-specific updates elsewhere in the owner. It is not stack storage or uninitialized scalar input.
D_0060A0E0: ELF words 00000000 3F800000 00000000, exactly RwV3d(0,1,0).
D_0060A100: ELF words 00000000 00000000 BF800000, exactly RwV3d(0,0,-1).
All four GP float slots were read directly from ELF:
  -0x7EE8(gp), VA 0x761208, fGpffff8118: 0x3E19999A = 0.15000000596046448f.
  -0x7FD0(gp), VA 0x761120, fGpffff8030: 0x3DCCCCCD = 0.10000000149011612f.
  -0x7EF0(gp), VA 0x761200, fGpffff8110: 0x3F99999A = 1.2000000476837158f.
  -0x7F1C(gp), VA 0x7611D4, fGpffff80e4: 0x3E860A92 = 0.2617993950843811f.
Immediate float words: 00000000=0; 3F000000=0.5; 41F00000=30; 3FC00000=1.5; 40200000=2.5; 40600000=3.5; 3E600000=0.21875; 3FA00000=1.25; 41C80000=25; 43480000=200.
Camera+0x9C..0xB7 is the incoming complete seven-float pose (position+quaternion). Camera+0xB8 is its FOV scalar. No extra incoming scalar is inferred.

Same-genus record branches
==========================
Both participants genus zero selects root->B98 + 0x64C + (u16)func_00231d70(2)*0x34; equal nonzero genus selects +0x5B0 instead. They remain separate branches and separate 56-byte pair objects.
func_00231d70(u32) (src/Main/Battle/Data/datCalc.c) returns RpRandom()%arg0, so a0=2 produces 0 or 1 in v0. Target explicitly narrows v0 to u16.
Each record consumes u16 duration at +0, position A at +4,+8,+0xC, look-at A at +0x10,+0x14,+0x18, position B at +0x1C,+0x20,+0x24 and look-at B at +0x28,+0x2C,+0x30. Extent exactly 0x34 bytes; record+2..3 unused. Two variants consume [base+0x64C,base+0x6B4) or [base+0x5B0,base+0x618).
Duration is u32 frames loaded from u16 record then converted (f32)frames/30.0f. This preserves the compiler's unsigned conversion paths at 0x229274 and 0x229394, not Ghidra's eliminated branch view.

Pose/quaternion output proof
============================
A real CameraPosePair is 56 bytes: first RwV3d at +0 (12), first RtQuat at +0xC (16), second RwV3d at +0x1C (12), second RtQuat at +0x28 (16). No invented padding, fourth vector component, dummy initialization or spill-binding object is needed.
func_001bd560 at 0x1BD560 was read completely. It copies seven floats from input offsets 0,4,8,0xC,0x10,0x14,0x18 to matching output offsets. Target call 0x229400 produces the COMPLETE first pose at sp+0x120..0x13B, including firstRotation sp+0x12C..0x13B. This defeats the plausible but false uninitialized-first-quaternion blocker at 0x229860.
func_001bd780(out,first,second,up), current src/Battle/btlCamera.c, builds a 64-byte matrix through func_001bd620(matrix,second,first,up), then RtQuatConvertFromMatrix(out,matrix). Matrix provider fills all three 3-float basis vectors read by conversion; matrix padding/flags are not read by conversion. All input vectors are exactly 12 bytes.
Complete 0x3DC610 retail and helpers 0x3DC490,0x3DC510,0x3DC590 were read. Nonnull out/matrix (both actual local addresses here) write exactly four floats in every branch. Positive-trace stores at 0x3DC6E0(+12), 0x3DC70C(+0), 0x3DC718(+4), delay-slot 0x3DC720(+8). X helper writes +0,+12,+4,+8 (last in return delay slot); Y helper +4,+12,+8,+0; Z helper +8,+12,+0,+4. Null arguments are the only provider no-write case, absent here.
Same-genus player pair: sp+C0..F7; quaternions produced at 0x229200 (sp+CC) and 0x229234 (sp+E8); positions stored 0x229214..21C and 0x229248..250; consumption at 0x2292B4.
Same-genus other pair: sp+80..B7; quaternions at 0x229320(sp+8C) and 0x229354(sp+A8); positions 0x229334..33C and 0x229368..370; consumption at 0x2293D4.
Mixed-genus pair: sp+120..157. First pose fully copied at 0x229400. Second rotation written to sp+148..157 by 0x229694; second position sp+13C..147 written 0x229818,828,838 then y possibly clamped at 0x229854. Comparison at 0x229860 reads two fully produced 16-byte quaternions. Cut branch copies second quaternion to first at 0x2298A4..8B0 and replaces first position at 0x229904,910,91C, with optional y clamp 0x229938. Non-cut path deliberately retains all seven incoming-pose floats.
func_001bac20 (src/Battle/btlMain.c) consumes precisely seven floats from EACH input pose. Mode a3=1 bypasses alternate non-pose conversion. It copies positions and all four quaternion components, calls func_001ba790 twice for intermediates, and fills four 0x1C-byte camera entries. Local pose inputs are complete along every consumer path. Same-genus destination is root+0x24; mixed-genus destination is the incoming camera itself, deliberately not replaced with root+0x24.
func_001bbef0(camera,duration), a0 pointer/f12 float, writes camera+0x84 duration conversion, +0x94=0.5, and mode bits; no target stack pointer consumed. Same-genus duration from frames; mixed-genus duration exactly 1.5f.

Other local producers and consumed extents
=========================================
func_001958f0(BtlUnit*,RwV3d*) current src/Battle/btlUnit.c scales unit sphere center, applies unit quaternion with count=1, writes dst x and z from signed grid coordinates*25-0x6D6 plus rotated center, and y from unit position plus rotated center. Always produces exactly 12 bytes. Target firstCenter sp+1B0..1BB and secondCenter sp+1A0..1AB are fully produced by calls 0x229410/0x229420 before any scalar use.
RwV3dNormalize/retail 0x3E40B0: complete ASM read; reads three floats, ALWAYS writes all three output floats, including zero-length/error-notification path; returns length in f0. direction sp+170..17B is firstCenter-secondCenter before its in-place call 0x2294A0. Output length times fGpffff8118 yields the scalar used for lookAt sp+190..19B, each component then adds secondCenter.
func_003e41e0: complete ASM read; two-float normalizer, always writes offsets 0 and 4, including zero-length/error path, returns original length in f0 (ignored by this target). cameraSide sp+118..11F produced from camera x/z minus lookAt x/z before 0x229518. perpendicular sp+110..117 is direction.z,-direction.x. side is (-direction.x)*cameraSide[1]+direction.z*cameraSide[0], matching ACC order.
anchor sp+180..18B: x/z both branches produced by signed perpendicular offset from firstCenter with radius*(reverseSide?2.5:1.5). Every height branch writes y: actor genus zero uses firstHeight if smaller than secondHeight, otherwise firstCenter.y-0.1*firstHeight; actor nonzero always uses firstHeight. lookAt y is adjusted on every branch. distance base is radius*(reverseSide?3.5:2.5).
RtQuatTransformVectors/retail 0x3DCB40: complete ASM read, a0 out,a1 vector,a2 count,a3 quaternion. Reads all four quaternion floats, and for count=1 reads the 12-byte D_0060A100 vector and writes exactly 12 output bytes. No hidden float argument. Both target calls 0x2296B0 and 0x2298C0 have count=1 and use the fully produced secondRotation. The second call's a2=1 and a3=&secondRotation originate before the conditional quaternion-copy stores; these live values are preserved in the candidate arguments.
func_001ec3d0: full retail and current source read, a0/a1 are two-float line points, a2 two-float test point, a3 optional two-float projection out. Returns absolute perpendicular distance in f0. At 0x2296F8 all three inputs are written: lookAtXZ sp+100..107, anchorXZ sp+108..10F, firstXZ sp+168..16F. Output address sp+160 is nonnull, so stores at 0x1EC464 and 0x1EC47C produce BOTH output floats. Both are consumed at 0x229704/70C and replace anchor x/z. The scalar return is added to distance before division by tanf.
tanf/retail 0x44B868 is named in config/symbol_addrs.txt and already declared/used by current owner. f12=fGpffff8110*(0.5f*camera FOV); f0 return is the actual distance divisor, called AGAIN for the negative-side offset (not cached or algebraically canceled).
sideXZ sp+158..15F exists only on side<0 branch, initialized from scaled direction x/z and in-place normalized at 0x2297D4 before both values adjust anchor x/z. Side shift magnitude is ((distance*tanf(...))*0.21875f)*1.25f; multiplication order retained.
func_001ec2b0: complete ASM and current provider read. a0/a1 two 16-byte quaternions; read-only; f0=2*acos(abs(dot)), with retail negative-dot recomputation. No output argument. Initial firstRotation is NOT uninitialized because of the 28-byte func_001bd560 copy. Current provider has a private holder type; camera callers already use void* prototype; declarations.h records the existing discrepancy.
func_004b3110(s16), current src/Graphics/Effect/effCrossfade.c: a0=5 here; finds crossfade task, returns 0 if absent or active, otherwise sets task work state=1, work+2 duration=5 and returns 1. Return ignored. No target local output. The candidate does not mistake this for an RNG or camera-pose provider.

*/
extern f32 fGpffff80e4;
extern f32 func_001ec2b0(void *first, void *second);
extern s32 func_004b3110(s16 frames);

/* Existing cross-owner declaration discrepancy, not changed here:
 * src/promoted/code1_001e.c defines func_001ec2b0 with two pointers to its
 * private P4Vec4Holder_001EC2B0, whose sole member is a four-float quaternion.
 * src/Battle/btlCamera.c already declares that same provider as
 * f32 func_001ec2b0(void *, void *). The declaration above reuses the current
 * camera-caller convention. Retail reads exactly four floats from each
 * pointer (offsets 0,4,8,12), writes neither, and returns float in f0.
 * The provider-private holder is not an extra field or an extra argument.
 * Main may normalize that existing cross-owner type contract separately;
 * this task does not modify production/shared declarations.
 */

// FUN_00229020
#pragma opt_scalarize off
void func_00229020(u8 *camera)
{
    RwV3d firstCenter;
    RwV3d secondCenter;
    RwV3d lookAt;
    RwV3d anchor;
    RwV3d direction;
    f32 firstXZ[2];
    f32 projectedXZ[2];
    f32 sideXZ[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    };
    struct {
        f32 lookAtXZ[2];
        f32 anchorXZ[2];
        f32 perpendicular[2];
        f32 cameraSide[2];
        struct CameraPosePair poses;
    } geometry;
    struct CameraPosePair player, other;
    f32 side;
    f32 radius;
    f32 firstHeight;
    f32 secondHeight;
    f32 distance;
    f32 scale;
    f32 angle;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *first;
    u8 *second;
    u8 *target;
    u8 *record;
    u32 index;
    u32 frames;
    u16 variant;
    s32 reverseSide;
    s32 allowCut;
    s32 forceActorSide;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL) {
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (index & 0xFFFF) * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    func_00195590((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
    }
    if (action == NULL) {
        allowCut = 1;
    } else if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x21:
        case 0x22:
            allowCut = 0;
            break;
        default:
            goto allow_cut;
        }
    } else {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x16:
        case 0x24:
            allowCut = 0;
            break;
        default:
allow_cut:
            allowCut = 1;
            break;
        }
    }
    second = *(u8 **)(action + 0x30);
    if (*(u8 *)(second + 0xA2) == 0) {
        target = (u8 *)*(u32 *)(camera + 0xE0);
        first = second;
        target = *(u8 **)(target + 0x38);
        second = *(u8 **)(target + 0x30);
        reverseSide = 0;
        forceActorSide = 1;
    } else {
        target = *(u8 **)((u8 *)*(u32 *)(camera + 0xE0) + 0x38);
        first = *(u8 **)(target + 0x30);
        reverseSide = 1;
        forceActorSide = 0;
    }
    if (*(u8 *)(first + 0xA2) == *(u8 *)(second + 0xA2)) {
        if (*(u8 *)(first + 0xA2) == 0) {
            variant = func_00231d70(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
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
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
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
        return;
    }

    func_001bd560((f32 *)&geometry.poses.first, (f32 *)(camera + 0x9C));
    func_001958f0((BtlUnit *)first, &firstCenter);
    func_001958f0((BtlUnit *)second, &secondCenter);
    radius = *(f32 *)(first + 0x90) * *(f32 *)(first + 0x2C);
    firstHeight = (0.0f + firstCenter.y) + 0.5f *
        (*(f32 *)(first + 0x8C) * *(f32 *)(first + 0x2C));
    secondHeight = (0.0f + secondCenter.y) + 0.5f *
        (*(f32 *)(second + 0x8C) * *(f32 *)(second + 0x2C));
    direction.x = firstCenter.x - secondCenter.x;
    direction.y = firstCenter.y - secondCenter.y;
    direction.z = firstCenter.z - secondCenter.z;
    scale = fGpffff8118 * RwV3dNormalize(&direction, &direction);
    lookAt.x = direction.x * scale;
    lookAt.y = direction.y * scale;
    lookAt.z = direction.z * scale;
    lookAt.x += secondCenter.x;
    lookAt.y += secondCenter.y;
    lookAt.z += secondCenter.z;
    geometry.cameraSide[0] = *(f32 *)(camera + 0x9C) - lookAt.x;
    geometry.cameraSide[1] = *(f32 *)(camera + 0xA4) - lookAt.z;
    func_003e41e0(geometry.cameraSide, geometry.cameraSide);
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.cameraSide[0] + geometry.perpendicular[1] * geometry.cameraSide[1];
    if (reverseSide == 0) {
        scale = 1.5f * radius;
    } else {
        scale = 2.5f * radius;
    }
    if (!(side < 0.0f)) {
        anchor.x = (0.0f + firstCenter.x) + direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) - direction.x * scale;
    } else {
        anchor.x = (0.0f + firstCenter.x) - direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) + direction.x * scale;
    }
    if (reverseSide == 0) {
        if (firstHeight < secondHeight) {
            anchor.y = firstHeight;
            lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        } else {
            anchor.y = (0.0f + firstCenter.y) - fGpffff8030 * firstHeight;
            lookAt.y = (0.0f + lookAt.y) + fGpffff8030 * secondHeight;
        }
        distance = 2.5f * radius;
    } else {
        anchor.y = firstHeight;
        lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        distance = 3.5f * radius;
    }
    func_001bd780(&geometry.poses.secondRotation, &anchor, &lookAt, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
    geometry.lookAtXZ[0] = lookAt.x;
    geometry.lookAtXZ[1] = lookAt.z;
    geometry.anchorXZ[0] = anchor.x;
    geometry.anchorXZ[1] = anchor.z;
    firstXZ[0] = firstCenter.x;
    firstXZ[1] = firstCenter.z;
    scale = func_001ec3d0((u8 *)geometry.lookAtXZ, (u8 *)geometry.anchorXZ, (u8 *)firstXZ, (u8 *)projectedXZ);
    scale += distance;
    distance = scale;
    anchor.x = projectedXZ[0];
    anchor.z = projectedXZ[1];
    distance /= tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    if (side < 0.0f) {
        scale = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        scale *= 0.21875f;
        firstHeight = scale;
        firstHeight *= 1.25f;
        sideXZ[0] = direction.x;
        sideXZ[1] = direction.z;
        func_003e41e0(sideXZ, sideXZ);
        anchor.x = (0.0f + anchor.x) + sideXZ[1] * firstHeight;
        anchor.z = (0.0f + anchor.z) - sideXZ[0] * firstHeight;
    }
    geometry.poses.second.x = anchor.x + direction.x;
    geometry.poses.second.y = anchor.y + direction.y;
    geometry.poses.second.z = anchor.z + direction.z;
    if (geometry.poses.second.y < 25.0f) {
        geometry.poses.second.y = 25.0f;
    }
    angle = func_001ec2b0(&geometry.poses.firstRotation, &geometry.poses.secondRotation);
    if (forceActorSide == 1 || !(angle <= fGpffff80e4)) {
        if (allowCut == 1) {
            geometry.poses.firstRotation = geometry.poses.secondRotation;
            RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
            scale = 200.0f + distance;
            direction.x *= scale;
            direction.y *= scale;
            direction.z *= scale;
            geometry.poses.first.x = anchor.x + direction.x;
            geometry.poses.first.y = anchor.y + direction.y;
            geometry.poses.first.z = anchor.z + direction.z;
            if (geometry.poses.first.y < 25.0f) {
                geometry.poses.first.y = 25.0f;
            }
            func_004b3110(5);
        }
    }
    func_001bac20((u16 *)camera, (f32 *)&geometry.poses.first, (f32 *)&geometry.poses.second, 1);
    func_001bbef0(camera, 1.5f);
}

#pragma opt_scalarize on
