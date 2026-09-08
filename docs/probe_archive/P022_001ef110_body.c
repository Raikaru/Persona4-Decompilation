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
