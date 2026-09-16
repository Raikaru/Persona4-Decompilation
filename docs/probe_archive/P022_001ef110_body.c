/* P022: exact route interpolation recovery, 2026-09-04.
 * Owner: src/promoted/code1_001e.c; retail 001EF110..001EF49F.
 * Integrated gate: 904/912 bytes, normalized_diff 0, all 18 relocations
 * resolved. The remaining eight bytes are retail zero tail padding.
 *
 * Keep the cache/quaternion and three-vector declaration order. Swapping
 * the long-lived blend and length-delta declarations closes the FPR pair.
 * Stage BOTH terminal coordinates before either route store. With direct
 * stores, endXZ == route+0x34 loses the original endXZ[1]. With staging but
 * propagation enabled, the two loads are safe but reversed (four differing
 * bytes). Scoped opt_propagation off reproduces retail's load order.
 *
 * Contract: three initialized two-float XZ inputs and writable route storage
 * through +0x404. Seven interpolated samples use t=0,.125,...,.75; the eighth
 * point reloads endXZ after the loop. Count +0x400 becomes 8, mode +0x404
 * becomes 2, and cursor +0x402 and unused points are untouched. Return is 1.
 * The actual caller passes unit+0xEC into a real 0xA70-byte unit allocation.
 *
 * Real local extents: each quaternion 16 bytes, interpolation cache 40,
 * each direction/endpoint/center vector 12. The look-at matrix provider
 * initializes the 3x3 entries read by every quaternion-conversion branch;
 * even zero direction yields a fully written quaternion, not an unwritten
 * fourth vector lane or an invented identity fallback. The cache provider
 * initializes all 40 bytes, and vector rotation reads/writes only XYZ.
 *
 * Upstream caveat: caller 00196D00 ignores an empty-centroid return from
 * 00196040. Without an earlier scratch write that path does not establish
 * initialized center inputs. All identified direct move constructors have
 * arc flag 0x80 clear; no concrete production chain selecting that empty
 * arc path was found. This is not a target-local initialization defect and
 * not a proof of a reachable game bug. No guard/default was introduced.
 *
 * Native evidence: 3073 scenarios pass Clang ASan/UBSan: 2857 nonlinear and
 * 216 linear cache cases, coincident points, seven samples plus the explicit
 * endpoint, unchanged cursor and guard bytes, and endpoint overlap. Native
 * mathematical models implement the four external SDK boundaries; this is
 * NOT PS2 SDK/game execution. An unstaged terminal-copy variant fails the
 * overlap assertion. The oracle preserves float dot-sign decisions at the
 * antipodal boundary and uses double sine interpolation for its values.
 *
 * Required recovered data mapping: D_00761430 = 0x00761430; retail word
 * 0x2F2EC9D3. The other five polynomial coefficient mappings already exist.
 */
#include "type.h"
typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void func_001bd780(void *out, const void *first,
                          const void *second, const void *up);
extern f32 func_003e4180(f32 *vector);
extern void func_003dcc70(const void *first, const void *second, void *result);
extern void *func_003dcb40(void *out, const void *in, s32 count, const void *rotation);
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;

/* 904/912 bytes; all eighteen relocations resolve exactly.
   Stage both endpoint loads before either store to preserve overlap. */
#pragma push
#pragma opt_propagation off
s32 func_001ef110(u8 *route, const f32 *startXZ,
                  const f32 *endXZ, const f32 *centerXZ)
{
    P4RouteSlerp_001EF110 interpolation;
    P4Vec4_001EC2B0 rotation;
    P4Vec4_001EC2B0 startRotation;
    P4Vec4_001EC2B0 endRotation;
    f32 center[3];
    f32 endpoint[3];
    f32 direction[3];
    f32 startLength;
    f32 blend;
    f32 lengthDelta;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 square;
    f32 polynomial;
    f32 finalPolynomial;
    f32 length;
    s32 index;

    *(u16 *)(route + 0x400) = 0;
    endpoint[1] = 0.0f;
    center[0] = centerXZ[0];
    center[1] = 0.0f;
    center[2] = centerXZ[1];
    endpoint[0] = startXZ[0];
    endpoint[2] = startXZ[1];
    func_001bd780(&startRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    startLength = func_003e4180(direction);

    endpoint[0] = endXZ[0];
    endpoint[2] = endXZ[1];
    func_001bd780(&endRotation, center, endpoint, D_0060A0E0);
    direction[0] = center[0] - endpoint[0];
    direction[1] = center[1] - endpoint[1];
    direction[2] = center[2] - endpoint[2];
    lengthDelta = func_003e4180(direction);
    blend = 0.0f;
    func_003dcc70(&startRotation, &endRotation, &interpolation);
    index = 0;
    lengthDelta = lengthDelta - startLength;
    while (index < 7)
    {
        if (blend <= 0.0f)
        {
            rotation = startRotation;
        }
        else if (1.0f <= blend)
        {
            rotation = endRotation;
        }
        else
        {
            firstWeight = 1.0f - blend;
            secondWeight = blend;
            if (interpolation.mode == 0)
            {
                angle = firstWeight * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                firstWeight = polynomial * finalPolynomial + angle;

                angle = blend * interpolation.angle;
                square = angle * angle;
                polynomial = D_00761430 * square + fGpffff8054;
                polynomial = square * polynomial + fGpffff8058;
                polynomial = square * polynomial + fGpffff8344;
                polynomial = square * polynomial + fGpffff8060;
                finalPolynomial = square * polynomial + D_00761438;
                polynomial = square * angle;
                secondWeight = polynomial * finalPolynomial + angle;
            }
            rotation.x = interpolation.first.x * firstWeight;
            rotation.y = interpolation.first.y * firstWeight;
            rotation.z = interpolation.first.z * firstWeight;
            rotation.x = interpolation.second.x * secondWeight +
                         (0.0f + rotation.x);
            rotation.y = interpolation.second.y * secondWeight +
                         (0.0f + rotation.y);
            rotation.z = interpolation.second.z * secondWeight +
                         (0.0f + rotation.z);
            rotation.w = interpolation.first.w * firstWeight +
                         interpolation.second.w * secondWeight;
        }
        func_003dcb40(direction, D_0060A0F0, 1, &rotation);
        length = blend * lengthDelta + (0.0f + startLength);
        direction[0] = direction[0] * length;
        direction[1] = direction[1] * length;
        direction[2] = direction[2] * length;
        *(f32 *)(route + index * 8) = center[0] + direction[0];
        *(f32 *)(route + index * 8 + 4) = center[2] + direction[2];
        blend = blend + 0.125f;
        index = index + 1;
    }
    {
        f32 endX = endXZ[0];
        f32 endZ = endXZ[1];
        *(f32 *)(route + 0x38) = endX;
        *(f32 *)(route + 0x3C) = endZ;
    }
    *(u16 *)(route + 0x400) = 8;
    *(u8 *)(route + 0x404) = 2;
    return 1;
}

#pragma pop

/*
 * Detailed provider/caller evidence from the pre-probe investigation.
 * The measured source and status above supersede its candidate status.
 *
 * 
 * $a0 route: aligned writable opaque object, sparse accesses through byte +0x404 inclusive (minimum addressable object extent 0x405).
 * $a1 startXZ: exactly two initialized f32 at +0 and +4, read in the prefix only.
 * $a2 endXZ: exactly two initialized f32 at +0 and +4; preserved in s1 and read again after all loop writes for the final endpoint. Do not cache its final read away or introduce restrict.
 * $a3 centerXZ: exactly two initialized f32 at +0 and +4, read in the prefix only.
 * These are pointers in a0/a1/a2/a3; there is no incoming floating parameter, hidden fifth input, incoming accumulator requirement, or incoming vector W.
 * $v0 is set with addiu v0,zero,1 at 001EF46C on the sole return path. The candidate uses s32; the actual caller discards this value.
 * 
 * WRITABLE OUTPUT EXTENT / SEMANTICS
 * At entry: sh zero,route+0x400.
 * The loop executes index 0..6 inclusive, blend = +0, .125, .25, .375, .5, .625, .75. It writes seven packed XZ pairs at route+[0x00..0x37]. It does NOT generate .875 or 1.0 samples. Then it copies endXZ to route+0x38/+0x3C (eighth point), stores u16 8 at +0x400, and u8 2 at +0x404. It never writes +0x402, the traversal cursor, and never clears unused points.
 * The apparent 0x400 point region can contain 128 packed pairs; this function only writes 8. This is not a license to enlarge a caller's allocation.
 * The real caller 00196D00 passes unit+0xEC (001971A0). Unit construction func_0019d210 requests and zeroes 0xA70 bytes at 0019D238..0019D260, corroborated by current src/promoted/code1_0019.c func_0019d210. Thus route+0x404 is unit+0x4F0, well within the real allocation; remaining capacity from route is 0x984 bytes. The C BtlUnit view in btlUnit.c ends at movementFlags and is only a prefix view, not the allocator's size.
 * Before this call, 00196D00 calls func_001eec50(unit+0xEC), which initializes +0x400 and +0x402 to zero (001EEC50..001EEC5C). No assumed target write to the cursor is needed.
 * 
 * TARGET LOCAL INITIALIZATION AND EXACT PROVIDER EXTENTS
 * Retail stack slots:
 *   +0x50 end quaternion: 16 real bytes.
 *   +0x60 start quaternion: 16 real bytes.
 *   +0x70 selected quaternion: 16 real bytes.
 *   +0x80 interpolation preparation: exactly 40 real bytes, consisting of two four-float quaternions at +0/+0x10, float angle +0x20, s32 mode +0x24. The following eight stack bytes are not extra provider output and are not required by the C type.
 *   +0xB0 direction: exactly three floats (+0,+4,+8), not a four-float vector.
 *   +0xC0 endpoint: exactly three floats; Y set to +0 before its first provider call and retained when X/Z change to endXZ.
 *   +0xD0 center: exactly three floats; Y set to +0.
 * The saved sq/lq registers are ordinary callee-save spills, not 128-bit C scalar requirements. Quaternion copies are 16-byte struct assignments; no uninitialized fourth float is copied from a three-component vector.
 * func_001bd780(out,first,second,up), current src/Battle/btlCamera.c and retail 001BD780..001BD7CC: allocates a 64-byte matrix, calls func_001bd620(matrix,second,first,up), then RtQuatConvertFromMatrix(out,matrix).
 * func_001bd620, fully read 001BD620..001BD77C: reads exactly 3 floats from each input vector/up, initializes matrix right XYZ +0/+4/+8, up XYZ +0x10/+0x14/+0x18, at XYZ +0x20/+0x24/+0x28, position XYZ +0x30/+0x34/+0x38. The four row-tail words are not written. They are not read by any quaternion conversion branch.
 * RwV3dNormalize / 003E40B0, fully read: reads/writes only XYZ. Zero length does NOT leave output uninitialized: scale becomes that zero length, then all three outputs are multiplied/stored before reporting the zero-vector error. Unordered length follows the reciprocal branch. Here both normalizations operate in place on initialized vectors.
 * RtQuatConvertFromMatrix / 003DC610, fully read, and all three selected leaves 003DC490/003DC510/003DC590, fully read: consume only the nine initialized 3x3 entries. Non-null out/matrix are guaranteed by local addresses. Every trace-positive/unordered or max-diagonal branch writes all four output floats. No matrix flags, fourth columns, or position entries are read. Its integer success result is ignored by 001BD780.
 * func_003e4180, full 0x30-byte ASM: loads only offsets 4,0,8, accumulates y*y+x*x+z*z, sqrt.s into f0. It has no output buffer stores and returns f32 in f0. No fourth component exists in its contract.
 * func_003dcc70, full 413-line/0x620-byte ASM: copies first quaternion into output+0..0xC, copies or negates all four second components into output+0x10..0x1C, computes/stores angle at +0x20 on every branch, stores mode at +0x24. If mode==0 it scales ALL EIGHT stored quaternion components by reciprocal of its sine polynomial. If mode!=0 those initial copies remain. No branch returns with a target-consumed field unwritten; it does not write beyond +0x27. Negative dot handling and unordered clamp behavior belong to that provider, not a target simplification.
 * func_003dcb40, full 83-line/0x130-byte ASM: reads 4 quaternion floats, then count XYZ vectors at stride 12 and writes XYZ outputs at stride 12. Here count is exactly 1, so direction gets exactly 12 initialized bytes. Returns original output pointer in v0, ignored by this target. It neither requires nor writes a fourth direction float.
 * 
 * MATH / COMPARISONS
 * Look-at gives orientation from center toward endpoint. The measured length is from center-endpoint, not a presumed pre-normalized component or 2D provider.
 * After two lengths, lengthDelta=endLength-startLength. Each sample rotates D_0060A0F0=(+0,+0,1), multiplies all three direction components by startLength+blend*lengthDelta, and writes center.X/Z plus direction.X/Z. D_0060A0E0=(+0,1,+0).
 * Keep blend<=+0 and 1<=blend as written. The latter branch is dynamically unreachable with this fixed local sequence, but is present in retail. Do not use negated comparisons or rewrite the entire loop into a generic spline/lerp helper. The endpoint copies occur before any selected-quaternion use; the interior branch writes all four fields.
 * The sine polynomial is explicitly expanded in retail. Preserve multiplication/addition association, the third/fourth-component distinction in the blend, and the +0 accumulator adds where a computed quantity may carry a signed zero. The candidate explicitly preserves +0+rotation.{x,y,z} and +0+startLength. Do not replace center[1]-endpoint[1] with an invented vector component or simplify the selected vector into a 2D-only transform.
 * Degenerate coincident endpoint/center does not cause an unwritten target-local read. Normalization stores zero XYZ, conversion still stores a four-float quaternion (a zero 3x3 matrix selects the Z leaf and writes q.z=.5, the other fields zero up to signed-zero behavior); it does NOT silently return an identity quaternion. Slerp and vector rotation still execute. No guard/default has been added.
 * 
 * ACTUAL CALLER INPUTS AND CONSUMERS
 * 00196D00, full current 462-line ASM:
 *   route branch requires packet flags bit8 clear and state 0 falling through to state1, or state1 directly. Bit0x80 selects this target at 00197140..001971B0. Otherwise func001EED10 is used.
 *   startXZ stack+0x48/+0x4C comes from moving unit+4/+0xC at 0019711C..00197128.
 *   endXZ stack+0x40/+0x44 comes from packet+4/+0xC at 0019712C..00197138.
 *   centerXZ stack+0x38/+0x3C comes from center-provider scratch+0x50/+0x58 at 00197190..0019719C, after func00196040(3,1,scratch,0,0,1).
 *   after the target, count is loaded at unit+0x4EC (route+0x400). Zero count uses packet destination; nonzero count selects the second-to-last route pair to approach the final destination with packet+0x1C offset (001971E4..001972B0). With count8 the read is route pair6, exactly initialized here.
 *   next state checks unit+0x4F0 (route+0x404); value2 enables movement flags and advances state (001972C0..00197300).
 * Current src/Battle/btlUnit.c func00196610 consumes count/cursor from +0x4EC/+0x4EE, walks the packed XZ pairs while index<count-1, uses pair7 as terminal target, and stores cursor at route+0x402. It retains the unit's Y coordinate. The target's eight initialized points cover all reads in this normal cursor-zero path.
 * 
 * UPSTREAM CENTROID PRECONDITION, NOT A TARGET-LOCAL BLOCKER
 * func00196040 is fully read in current src/Battle/btlUnit.c and all 407 ASM lines. For arguments (3,1,...,1), it visits group0 and group1 lists, accepts units with unit+0x9C bit8 set and bit1 clear, and uses grid XZ = 25*s16(unit+0x94/0x96)-1750. If no units pass, 001962E4..001962F4 returns +0 before ANY center store. For nonzero count, every XYZ center output is initialized; one unit uses sum directly, multiple use sum/count. Stores occur at 00196598..001965A0.
 * The caller ignores the provider's f0 return. Thus a hypothetical arc-selected invocation with no accepted units needs scratch+0x50/+0x58 to have been initialized earlier or would forward uninitialized inputs. A state0 invocation with packet flag0x10 calls func00194FF0 into that same scratch before the centroid attempt, so even the empty-centroid case is not uniformly uninitialized. A state1 invocation or a state0 invocation without flag0x10 has no such preceding scratch write.
 * Do not claim this proves a reachable retail bug. All statically identified direct move constructors currently supply flags with bit0x80 CLEAR (details in notes.txt); a concrete production path setting the arc selector was not found. This caveat therefore limits a route-wide unconditional safety claim, not the complete explicit-input contract or local correctness of body.c. No fake centroid default, count guard, extra ABI argument, or target-local initializer was introduced.
 *
 * POLYNOMIAL CONSTANTS FROM ELF
 * _gp=0x7690F0 (.reginfo), data read from orig/SLUS_217.82 PT_LOAD.
 *  retail GP displacement  address     bits       candidate symbol        exact float value
 *  -0x7CC0                 00761430    2F2EC9D3   D_00761430              1.5896910177115586e-10
 *  -0x7FAC                 00761144    B2D72F34   fGpffff8054             -2.5050759688838298e-08
 *  -0x7FA8                 00761148    3638EF1B   fGpffff8058              2.7557314297155244e-06
 *  -0x7CBC                 00761434    B9500D01   fGpffff8344             -0.00019841270113829523
 *  -0x7FA0                 00761150    3C088889   fGpffff8060              0.008333333767950535
 *  -0x7CB8                 00761438    BE2AAAAB   D_00761438              -0.1666666716337204
 * These six loads are the inline sine polynomial's coefficients, not pointers or the prepared angle. The angle is interpolation+0x20. Matrix/up data at 0060A0E0 is (0,1,0); forward data 0060A0F0 is (0,0,1). Their fourth words happen to be zero in the ELF but target providers only consume XYZ; no fourth-word dependency was invented.
 * 
 *
 * ACTUAL FLAG-0x80 REACHABILITY AUDIT
 * A fresh direct JAL decode over the ELF code1 text (virtual 00100000..0052D9FF), corroborated by full asm/code1.s reference scans, found:
 *   001EF110 direct caller: only 001971B0 in 00196D00.
 *   00196D00 direct caller: only 0019799C in 001974F0.
 *   00196D00 callback address materialization: 00197434/00197438 in btlUnitCreateMovePacket.
 * No explicit target address materialization or aligned absolute data pointer to 001EF110 was found. This is a bounded static-reference result, not a proof that computed runtime calls are impossible.
 * 
 * The 13 direct btlUnitCreateMovePacket (001973F0) call sites and actual a2 flags are:
 *   001A10A8  func001A0F40  0
 *   001A1264  func001A1190  0x18
 *   001A5808  func001A5650  0
 *   001AD958  func001AD550  0
 *   001ADA14  func001AD550  4
 *   001B0214  func001B0020  0
 *   001B2A04  func001B2380  8
 *   001B2D14  func001B2380  8
 *   001B2F64  func001B2380  8
 *   001B50F4  func001B4880  0x18
 *   0022A248  func00229DA0  8
 *   0022A5D8  func00229DA0  0x18
 *   0022AB28  func0022A730  0x18
 * Every value has bit0x80 clear. Post-constructor code through submission was inspected; stores are packet scheduling metadata (+0,+8,+0x48,+0x60), not movement workData+0x10. The first branch at 001AD958 joins the same metadata/submission block at 001ADA20 as 001ADA14.
 * 
 * The two direct btlUnitCreateMoveToUnitPacket (001979E0) sites are:
 *   001A3A3C in func001A3840: flags 0xA.
 *   001A54C4 in func001A4C80: flags in s2 are reset to zero at 001A528C, optionally OR8 at 001A5470, optionally OR0x40 at 001A54A8. Result is 0,8,0x40,0x48, never 0x80.
 * Both submit normally without rewriting movement flags. The derived callback func001974F0 computes initialized targetPos XYZ and calls func00196D00 on the same work block; it does not set bit0x80. Its current full source was read at src/Battle/btlUnit.c 640..792. The actual constructors allocate/zero work via func00194470 (current source 1067..1105), install the relevant init/update/destroy callbacks, copy unit/target/flags/speed, and leave state/timer initially zero.
 * A bounded scan of immediate OR0x80 followed by offset0x10 writes in the battle/action regions found only global battle state mutations in func0022BD60, not these movement work objects.
 * Conclusion: no concrete retail construction chain selecting this arc function was found. It is not sound to call the no-centroid case a reachable game bug, and equally not sound to claim a global invariant guarantees a center without a runtime flag producer. The target remains a well-defined four-pointer API for initialized input pairs. Its sole caller's centroid precondition is explicitly documented rather than patched inside this target.
 * 
 * DEGENERATE INPUT DISTINCTION
 * Equal start/center, equal end/center, equal endpoints, and collinear directions are not rejected by the target. For a nonempty centroid, coincident positions are structurally possible (grid-center average can equal a unit/target's XZ); no noncoincidence guard exists in the actual caller. The math providers still fully initialize outputs for zero vectors. For empty group0/group1 selection, the provider does not initialize the caller's center; this is a different upstream input-definedness issue, not the same as zero geometric distance.
 * 
 * DISCOVERY / AUTHORITY
 * Used CSP search, graph search, inbound trace, then per-path coverage checks. The graph only represented func001EF110 through a historical Ghidra body and pointed to func00196D00. Active source metadata is changed since indexing, assembly coverage is partial, aggregate asm/code1.s is excluded, and orig is excluded. Therefore conclusions above are based on current source and complete current ASM/ELF reads, not stale graph signatures/generated code or archived reconstruction bodies. Scoped direct scans supplemented graph gaps. No generated/archived C was used as provider authority.
 */
