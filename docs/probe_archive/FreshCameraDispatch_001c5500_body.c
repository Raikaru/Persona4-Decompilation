/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Preferred current-owner replay: 1664/1664 bytes, nd219, 27 object relocations.
 * nd counts relocation-masked differing bytes, not differing instructions.
 * No native behavioral verification or fully resolved equivalence is claimed.
 * Production and its provider declarations remain unchanged ASM.
 * 
 * The first delivered packed frame was rejected before compilation: its unused
 * fourth vector elements and byte holes had no provider-supported extent.
 * This replacement uses real RwV3d/RtQuat objects and existing camera pose/2D
 * geometry conventions. The compiler supplies alignment gaps; C adds none.
 * 
 * Measured source explanations, not a declaration/layout sweep:
 * - Independent-object reconstruction: 1664/1664, nd231, 27 relocations.
 * - Move offsetFactor=0.0f after the dot product: 1664/1664, nd219 (retained).
 *   Retail materializes zero between its dot-product accumulator operations.
 * - Compute radius as 1.5f*(actorRadius*actorScale), then assign radiusScale:
 *   1668/1664, nd833, including four overrun bytes (rejected).
 * - Stage the actor product before radiusScale=1.5f, then multiply the named
 *   values: 1668/1664, nd835, including four overrun bytes (rejected).
 * - Existing camera opt_scalarize off profile: identical preferred bytes and
 *   relocations, 1664/1664, nd219; unnecessary pragma omitted.
 * The remaining first-phase constant scheduling and FP register lifetimes are
 * not exact. The later sign-branch topology was checked and already agrees.
 * 
 * The unary callee ignores the existing caller's second argument. No caller
 * migration is included or counted while this target remains unpromoted.
 * Negated comparisons retain unordered behavior; ordered >= or > prose below
 * is shorthand only for non-NaN operands. All six quoted GP float constants
 * (including the field radian-to-degree constant) were checked in retail data.
 * 
 * Agent reconstruction/provider evidence follows. Stack offsets describe
 * retail and the measured local-object layout, not source padding requirements.
 * ================================================================================
 * RECOVERY EVIDENCE: func_001c5500 (FUN_001C5500)
 * Target: src/promoted/code1_001c.c (around line 422)
 * Retail Window: asm/nonmatchings/code1_001c/func_001c5500.s (1664 bytes, 0x680)
 * ================================================================================
 * 
 * 1. ROUTINE IDENTITY & CALL CONTRACT
 * --------------------------------------------------------------------------------
 * Function Symbol: func_001c5500
 * Canonical Marker: // FUN_001C5500
 * Binary Address: 0x001C5500 - 0x001C5B80 (0x680 bytes = 1664 bytes, 416 instructions)
 * Owner Source: src/promoted/code1_001c.c:422
 * Callers:
 *   - src/Battle/btlCamera.c:486 (func_001c6560 camera mode switch case 2)
 *   - src/Battle/btlCamera.c:492 (func_001c6560 camera mode switch case 4)
 * Signature: void func_001c5500(u8 *arg0)
 *   - Parameter $4 (arg0): Pointer to battle camera work structure.
 *   - Parameter $5: Retail asm never reads incoming $5; it immediately overwrites
 *     $5 at line 24 (addiu $5, $29, 0x150) for func_00195850. The prototype is
 *     strictly unary: void func_001c5500(u8 *arg0). While btlCamera.c calls it as
 *     func_001c5500(camera, 1), the second argument is dead at the ABI boundary.
 *   - Return: void (jr $31 at line 433, no return value in $2 or $f0).
 * 
 * 2. PARAMETERS & INPUT FIELD ACCESS
 * --------------------------------------------------------------------------------
 * From arg0 (Camera Work):
 *   - arg0 + 0x9C: Camera horizontal eye position X (f32)
 *   - arg0 + 0xA4: Camera horizontal eye position Z (f32)
 *   - arg0 + 0xB8: Camera FOV angle parameter (f32)
 *   - arg0 + 0xE0: Pointer to Action Work (u8 **)
 * From action (*(u8 **)(arg0 + 0xE0)):
 *   - action + 0x30: Actor Unit Work pointer (u8 **)
 *   - action + 0x38: Target Action Work pointer (u8 **)
 *     - targetAction + 0x30: Target Unit Work pointer (u8 **)
 *   - action + 0x88: State flag (s32). If 0, triggers func_004b3110(8).
 * From unit work (Actor and Target):
 *   - unit + 0x2C: Unit scale factor (f32)
 *   - unit + 0x8C: Unit height / vertical dimension (f32)
 *   - unit + 0x90: Unit radius / horizontal dimension (f32)
 *   - unit + 0xA2: Unit mode flag byte (u8). Evaluated on target unit.
 * 
 * 3. REAL INDEPENDENT OBJECTS & PROVIDER-PROVEN EXTENTS
 * --------------------------------------------------------------------------------
 * All local storage is declared as real, independent objects of provider-proven
 * types matching the established RenderWare and battle camera subsystem conventions
 * (src/Battle/btlCamera.c:5-30 and src/promoted/code1_0022.c:815-836):
 * 
 * A. Pose and Orientation Objects:
 *    - struct CameraPosePair poses; (56 bytes, 0x80 to 0xB7)
 *      Matching the exact declaration from code1_0022.c:831-836:
 *      - poses.first (RwV3d, 12 bytes, at 0x80):
 *        Unpacked by func_001bd560((f32 *)&poses.first, (f32 *)(arg0 + 0x9C)).
 *        Y coordinate (poses.first.y at 0x84) clamped to >= 25.0f.
 *      - poses.firstRotation (RtQuat, 16 bytes, at 0x8C):
 *        Populated by func_001bd560. Evaluated by func_001ec2b0 against
 *        poses.secondRotation. Used by func_003dcb40 for vector re-rotation.
 *      - poses.second (RwV3d, 12 bytes, at 0x9C):
 *        Calculated camera target position: eye + direction.
 *        Y coordinate (poses.second.y at 0xA0) clamped to >= 25.0f.
 *        Passed to func_001bcd40, func_001bac20, func_001bd5e0.
 *      - poses.secondRotation (RtQuat, 16 bytes, at 0xA8):
 *        Populated by func_001bd780(&poses.secondRotation, &eye, &focus, D_0060A0E0).
 *        Used to rotate reference vector D_0060A100 via func_003dcb40.
 * 
 * B. 2D Ground-Plane Vectors (f32[2]):
 *    - struct { f32 perpendicular[2]; f32 horizontal[2]; f32 focusXZ[2]; f32 eyeXZ[2]; } geometry;
 *      Matching the exact 2D projection struct from code1_0022.c:824-830:
 *      - geometry.perpendicular[2] (8 bytes, at 0xC0):
 *        2D difference vector in XZ plane (direction.x, direction.z), and later
 *        swapped perpendicular vector (direction.z, -direction.x).
 *      - geometry.horizontal[2] (8 bytes, at 0xC8):
 *        Normalized horizontal direction from actor to camera eye:
 *        horizontal[0] = (arg0 + 0x9C) - actorPosition.x;
 *        horizontal[1] = (arg0 + 0xA4) - actorPosition.z;
 *        func_003e41e0(geometry.horizontal, geometry.horizontal);
 *        Identical to code1_0022.c:862-864.
 *      - geometry.focusXZ[2] (8 bytes, at 0xD0):
 *        XZ components of interpolated focus point (focus.x, focus.z).
 *      - geometry.eyeXZ[2] (8 bytes, at 0xD8):
 *        XZ components of perpendicular eye position (eye.x, eye.z).
 *    - f32 projectionXZ[2] (8 bytes, at 0xE0):
 *      Output 2D projection point populated by func_001ec3d0.
 *      Copied to eye.x and eye.z matching code1_0022.c:941-943.
 *    - f32 baseXZ[2] (8 bytes, at 0xE8):
 *      XZ components of base unit position (basePosition.x, basePosition.z).
 * 
 * C. 3D Spatial Vectors (RwV3d, 12 bytes each, 16-byte stack spacing):
 *    - RwV3d savedDirection (at 0xF0):
 *      Direction vector preserved prior to rotation/scale updates.
 *      Copied via standard struct copy: savedDirection = direction;
 *    - RwV3d eye (at 0x100):
 *      Camera eye point, initially offset perpendicularly from basePosition.
 *    - RwV3d direction (at 0x110):
 *      Relative vector between units: actorPosition - targetPosition.
 *      Normalized via func_003e40b0; rotated via func_003dcb40; scaled by distScale.
 *    - RwV3d focus (at 0x120):
 *      Interpolated focal position between targetPosition and actorPosition.
 *    - RwV3d basePosition (at 0x130):
 *      Active unit position selected by dotProduct sign.
 *      Copied via standard struct copy: basePosition = actorPosition; (or targetPosition;).
 *      Y component clamped to >= 125.0f when actor is selected.
 *    - RwV3d targetPosition (at 0x140):
 *      Target unit center position from func_00195850(target, (f32 *)&targetPosition).
 *    - RwV3d actorPosition (at 0x150):
 *      Actor unit center position from func_00195850(actor, (f32 *)&actorPosition).
 * 
 * 4. COPY CONVENTIONS & 64-BIT INSTRUCTION PROOF
 * --------------------------------------------------------------------------------
 * Retail asm emits paired 64-bit load/store instructions for vector copies:
 *   Lines 92-95:   ld $2, 0x150($29) / lwc1 $f2, 0x158($29) -> sd $2, 0x130($29) / swc1 $f2, 0x138($29)
 *   Lines 117-120: ld $2, 0x140($29) / lwc1 $f2, 0x148($29) -> sd $2, 0x130($29) / swc1 $f2, 0x138($29)
 *   Lines 189-192: ld $2, 0x110($29) / lwc1 $f0, 0x118($29) -> sd $2, 0xF0($29) / swc1 $f0, 0xF8($29)
 * 
 * Proof of Natural Origin:
 * In the PS2 compiler (mwccps2), copying a 12-byte struct with 4-byte/8-byte alignment
 * (such as RwV3d) generates:
 *   - 1 x ld (64-bit load of x and y)
 *   - 1 x lwc1 (32-bit float load of z)
 *   - 1 x sd (64-bit store of x and y)
 *   - 1 x swc1 (32-bit float store of z)
 * This exact pattern is verified in func_002250a0 (code1_0022.c:904, asm lines 334239-334242):
 *   `basePosition = targetPosition;`
 * emits:
 *   ld $2, 0x150($29); lwc1 $f1, 0x158($29); sd $2, 0x140($29); swc1 $f1, 0x148($29)
 * No helper function, manual unrolling, or padding fields exist in the original source;
 * it is standard struct assignment between RwV3d instances.
 * 
 * 5. STACK LAYOUT & COMPILER ALIGNMENT EXPLANATION
 * --------------------------------------------------------------------------------
 * Total Frame Size: 0x160 bytes (352 bytes) via `addiu $29, $29, -0x160`.
 * Saved Registers Area:
 *   0x00..0x17: $f20..$f25 (24B)
 *   0x20..0x6F: $16..$20 (80B)
 *   0x70..0x77: $31 (8B)
 *   0x78..0x7F: 8 bytes alignment padding to 16-byte boundary.
 * 
 * Local Variable Stack Placement (allocated top-down from high to low addresses):
 *   0x150: actorPosition     (RwV3d, 12B, 16B aligned at 0x150)
 *   0x140: targetPosition    (RwV3d, 12B, 16B aligned at 0x140)
 *   0x130: basePosition      (RwV3d, 12B, 16B aligned at 0x130)
 *   0x120: focus             (RwV3d, 12B, 16B aligned at 0x120)
 *   0x110: direction         (RwV3d, 12B, 16B aligned at 0x110)
 *   0x100: eye               (RwV3d, 12B, 16B aligned at 0x100)
 *   0xF0:  savedDirection    (RwV3d, 12B, 16B aligned at 0xF0)
 *   0xE8:  baseXZ            (f32[2], 8B, at 0xE8)
 *   0xE0:  projectionXZ      (f32[2], 8B, at 0xE0)
 *   0xC0..0xDF: geometry struct (32B: perpendicular, horizontal, focusXZ, eyeXZ)
 *   0x80..0xB7: poses struct (CameraPosePair, 56B, 16B aligned at 0x80)
 *   0xB8..0xBF: 8 bytes alignment gap naturally occurring between the 56-byte
 *               poses structure (0x80..0xB7) and 8-byte aligned geometry (0xC0).
 * Every stack slot corresponds to an independent, legitimate local variable.
 * 
 * 6. PROVIDER EXTENTS & INTERFACES
 * --------------------------------------------------------------------------------
 * 1. func_00195850:
 *    - Provider: src/promoted/code1_0019.c
 *    - Prototype: void func_00195850(u8 *unit, f32 *posOut)
 *    - Extent: Writes 3 floats (x, y, z) into target vector.
 * 2. func_003e40b0 (RwV3dNormalize):
 *    - Provider: RenderWare vector math
 *    - Prototype: f32 func_003e40b0(f32 *out, f32 *in)
 *    - Extent: Reads and writes 3 floats; returns magnitude (f32).
 * 3. func_003e41e0:
 *    - Provider: 2D vector normalization
 *    - Prototype: f32 func_003e41e0(f32 *out, f32 *in)
 *    - Extent: Reads and writes 2 floats (XZ); returns length (f32).
 * 4. func_001bd780:
 *    - Provider: Battle camera orientation generator
 *    - Prototype: void func_001bd780(void *quatOut, const void *eye, const void *focus, const void *config)
 *    - Extent: Reads 3-float eye and focus; writes 4-float quaternion (RtQuat) into quatOut.
 * 5. func_003dcb40 (RtQuatTransformVectors):
 *    - Provider: RenderWare quaternion transformation
 *    - Prototype: void func_003dcb40(s64 *vectorsOut, const s64 *vectorsIn, s32 numPoints, const u8 *quat)
 *    - Extent: Transforms 3-float vector D_0060A100 by given 4-float quaternion into direction.
 * 6. func_001ec3d0:
 *    - Provider: Ground-plane camera extent solver
 *    - Prototype: f32 func_001ec3d0(u8 *focusXZ, u8 *eyeXZ, u8 *baseXZ, u8 *projectionXZ)
 *    - Extent: Reads three 2-float points; writes 2-float projected point into projectionXZ; returns extent (f32).
 * 7. func_0044b868:
 *    - Provider: Trigonometric tangent function
 *    - Prototype: f32 func_0044b868(f32 angle)
 *    - Extent: Computes tan(angle); input is fGpffff8110 * (0.5f * FOV).
 * 8. func_001bd560:
 *    - Provider: Camera pose unpacker
 *    - Prototype: void func_001bd560(f32 *poseOut, f32 *cameraPos)
 *    - Extent: Reads camera position from arg0+0x9C; writes 3-float position and 4-float rotation into poses.first.
 * 9. func_001ec2b0:
 *    - Provider: Quaternion divergence calculator
 *    - Prototype: f32 func_001ec2b0(void *quat1, void *quat2)
 *    - Extent: Reads two 4-float quaternions; returns angular divergence in radians.
 * 10. func_001bd5e0:
 *     - Provider: Camera pose re-orienter
 *     - Prototype: void func_001bd5e0(f32 *pose, f32 *targetPos)
 *     - Extent: Re-calculates pose orientation from target position.
 * 11. func_004b3110:
 *     - Provider: Battle sound/event dispatcher
 *     - Prototype: void func_004b3110(s32 eventId)
 *     - Extent: Fires event 8 when action->0x88 == 0.
 * 12. func_001bcd40:
 *     - Provider: Battle camera action dispatcher
 *     - Prototype: void func_001bcd40(u8 *action, u8 *unitParam, u8 *targetPos, f32 distance, u16 command)
 *     - Extent: Sets up camera tracking on targetPos with distance 50.0f.
 * 13. func_001bac20:
 *     - Provider: Battle camera transform applicator
 *     - Prototype: void func_001bac20(u8 *camera, f32 *first, f32 *second, s32 mode)
 *     - Extent: Applies dual-pose transform in mode 1.
 * 14. func_001bbef0:
 *     - Provider: Battle camera zoom updater
 *     - Prototype: void func_001bbef0(u8 *camera, f32 zoomScalar)
 *     - Extent: Applies zoom/timing scalar var_f20.
 * 
 * 7. EVERY BRANCH AND DECISION PATH
 * --------------------------------------------------------------------------------
 * Branch 1: Dot Product Test (lines 87-88 / line 109)
 *   - Instruction: c.lt.s $f24, $f5; bc1t .L001C56B4
 *   - Expression: if (!(dotProduct < 0.0f)) [dotProduct >= 0.0f]
 *   - TRUE Path (dotProduct >= 0.0f):
 *     - primaryUnit = actor ($20), secondaryUnit = target ($19).
 *     - basePosition = actorPosition.
 *     - radiusScale = 1.5f (0x3FC00000).
 *     - radius = 1.5f * (actor->0x90 * actor->0x2C).
 *     - heightFactor = fGpffff8118 (-0x7EE8(gp) = 0.15f).
 *     - Sub-branch (line 108-109): if (basePosition.y < 125.0f) basePosition.y = 125.0f;
 *     - offsetFactor remains 0.0f ($f5 unwritten).
 *     - Jumps to .L001C5738.
 *   - FALSE Path (.L001C56B4, dotProduct < 0.0f):
 *     - primaryUnit = target ($19), secondaryUnit = actor ($20).
 *     - basePosition = targetPosition.
 *     - Sub-branch (line 122): if (*(u8 *)(target + 0xA2) == 0):
 *       - radius = 1.5f * (target->0x90 * target->0x2C).
 *       - radiusScale = 3.5f (0x40600000).
 *     - Sub-branch ELSE (.L001C5704, target->0xA2 != 0):
 *       - radius = 1.25f * (target->0x90 * target->0x2C).
 *       - radiusScale = 1.75f (0x3FE00000).
 *     - heightFactor = 0.25f (0x3E800000).
 *     - offsetFactor = heightFactor = 0.25f ($f5 updated at line 149).
 * 
 * Branch 2: Cross Product Test (lines 166-167)
 *   - Instruction: c.lt.s $f25, $f4; bc1t .L001C57A8
 *   - Expression: if (!(crossProduct < 0.0f)) [crossProduct >= 0.0f]
 *   - TRUE Path (crossProduct >= 0.0f):
 *     - eye.x = basePosition.x + direction.z * radius;
 *     - eye.z = basePosition.z - direction.x * radius;
 *     - Jumps to .L001C57C8.
 *   - FALSE Path (.L001C57A8, crossProduct < 0.0f):
 *     - eye.x = basePosition.x - direction.z * radius;
 *     - eye.z = basePosition.z + direction.x * radius;
 * 
 * Branch 3: Distance Scale Clamp (lines 250-251)
 *   - Instruction: c.lt.s $f1, $f0; bc1f .L001C58CC
 *   - Expression: if (distScale < 500.0f) distScale = 500.0f;
 *   - Clamps accumDist / tanFov to a minimum distance scale of 500.0f.
 * 
 * Branch 4: Secondary Perpendicular Offset (lines 266-270 and 288-289)
 *   - Nested tests on dotProduct ($f24) and crossProduct ($f25):
 *   - Case A (dotProduct >= 0.0f && crossProduct < 0.0f):
 *     - eye.x += savedDirection.z * (primaryUnit->0x90 * primaryUnit->0x2C);
 *     - eye.z -= savedDirection.x * (primaryUnit->0x90 * primaryUnit->0x2C);
 *   - Case B (dotProduct < 0.0f && crossProduct >= 0.0f):
 *     - eye.x -= savedDirection.z * (primaryUnit->0x90 * primaryUnit->0x2C);
 *     - eye.z += savedDirection.x * (primaryUnit->0x90 * primaryUnit->0x2C);
 *   - Case C (all other combinations):
 *     - No adjustment applied to eye.x and eye.z.
 * 
 * Branch 5: Pose Angle Check (lines 333-334)
 *   - Instruction: c.le.s $f0, $f1; bc1t .L001C5AB4
 *   - Expression: if (!(angle <= fGpffff8158)) [angle > 60 degrees]
 *   - Constant: fGpffff8158 = -0x7EA8(gp) = 1.04719758f (pi/3 radians = 60.0 deg).
 *   - Angle Exceeded Path (angle > 60 deg, falls through):
 *     - Calls func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second).
 *     - Calls func_003dcb40((s64 *)&direction, (s64 *)D_0060A100, 1, (u8 *)&poses.firstRotation).
 *     - Scales direction by 150.0f and adds to poses.second.
 *     - command = 3.
 *     - Sub-branch (line 370): if (*(s32 *)(action + 0x88) == 0) func_004b3110(8);
 *     - var_f20 = 1.5f (0x3FC00000).
 *     - Jumps to .L001C5ABC.
 *   - Angle Within Limit Path (.L001C5AB4, angle <= 60 deg):
 *     - command = 0xC3.
 *     - var_f20 = fGpffff814c (-0x7EB4(gp) = 0.725f).
 * 
 * Branch 6: Camera Pose Y Floor Clamp (lines 388-389)
 *   - Instruction: c.lt.s $f1, $f0; bc1f .L001C5ADC
 *   - Expression: if (poses.first.y < 25.0f) poses.first.y = 25.0f;
 * 
 * Branch 7: Camera Result Y Floor Clamp (lines 397-398)
 *   - Instruction: c.lt.s $f1, $f0; bc1f .L001C5AFC
 *   - Expression: if (poses.second.y < 25.0f) poses.second.y = 25.0f;
 * 
 * 8. GROUNDED CONSTANTS & VERIFIED ADDRESSES
 * --------------------------------------------------------------------------------
 * GP-Relative Floating Point Constants (gp = 0x007690f0):
 *   - fGpffff8128 (-0x7ED8 = 0x00761218): 0.35f (0x3EB33333)
 *   - fGpffff8118 (-0x7EE8 = 0x00761208): 0.15f (0x3E19999A)
 *   - fGpffff8110 (-0x7EF0 = 0x00761200): 1.20f (0x3F99999A)
 *   - fGpffff8158 (-0x7EA8 = 0x00761248): 1.04719758f = pi/3 (0x3F860A92)
 *   - fGpffff814c (-0x7EB4 = 0x0076123C): 0.725f (0x3F39999A)
 * 
 * Global Data Symbols:
 *   - D_0060A0E0: Basis configuration matrix for camera orientation (func_001bd780).
 *   - D_0060A100: Standard reference direction vector (func_003dcb40).
 * 
 * Immediate Floats Encoded in MIPS Instructions:
 *   - 1.5f   (0x3FC00000): lines 99, 127, 376
 *   - 125.0f (0x42FA0000): line 105
 *   - 3.5f   (0x40600000): line 131
 *   - 1.25f  (0x3FA00000): line 139
 *   - 1.75f  (0x3FE00000): line 143
 *   - 0.25f  (0x3E800000): line 146
 *   - 0.5f   (0x3F000000): line 236
 *   - 500.0f (0x43FA0000): line 247
 *   - 150.0f (0x43160000): line 347
 *   - 25.0f  (0x41C80000): lines 385, 394
 *   - 50.0f  (0x42480000): line 402
 * ================================================================================
 *
 */

/*
 * Minimal integration requirements for func_001c5500 (FUN_001C5500)
 * Owner: src/promoted/code1_001c.c
 */

/*
 * Proven data structures from RenderWare and battle camera subsystem
 * (matching src/Battle/btlCamera.c:5-30 and src/promoted/code1_0022.c:29-39):
 */
#ifndef _RWV3D_DEFINED
#define _RWV3D_DEFINED
typedef struct RwV3d RwV3d;
struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
};
#endif

#ifndef _RTQUAT_DEFINED
#define _RTQUAT_DEFINED
typedef struct RtQuat RtQuat;
struct RtQuat {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
#endif

/*
 * Symbols required by func_001c5500 that are NOT currently declared at the
 * top level of src/promoted/code1_001c.c:
 */

/* GP-relative float constants (gp = 0x007690f0) */
extern f32 fGpffff8128; /* gp - 0x7ED8 = 0x00761218 (float 0.35f, 0x3EB33333) */
extern f32 fGpffff8118; /* gp - 0x7EE8 = 0x00761208 (float 0.15f, 0x3E19999A) */
extern f32 fGpffff8158; /* gp - 0x7EA8 = 0x00761248 (float 1.04719758f = pi/3, 0x3F860A92) */
extern f32 fGpffff814c; /* gp - 0x7EB4 = 0x0076123C (float 0.725f, 0x3F39999A) */

/* Global reference vector */
extern u8 D_0060A100[]; /* 0x0060A100 (unit direction vector / rotation reference) */

/* External function prototypes */
extern f32 func_003e41e0(f32 *out, f32 *in);
extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
extern f32 func_001ec2b0(void *first, void *second);
extern void func_001bd5e0(f32 *out, f32 *in);

/*
 * Symbols required by func_001c5500 that are ALREADY declared in src/promoted/code1_001c.c:
 *
 * typedef struct BtlUnitStateWork BtlUnitStateWork;            (line 3)
 * extern void func_004b3110(s32 arg0);                         (line 9)
 * extern f32 fGpffff8110;                                      (line 15)
 * extern f32 func_003e40b0(f32 *arg0, f32 *arg1);             (line 17)
 * extern void func_001bd560();                                 (line 19)
 * extern f32 func_0044b868(f32 arg0);                          (line 25)
 * extern void func_001bcd40(u8 *arg0, u8 *arg1, u8 *arg2,
 *                           f32 arg3, u16 arg4);               (line 31)
 * extern void func_001bac20(u8 *arg0, f32 *arg1, f32 *arg2,
 *                           s32 arg3);                         (line 46)
 * extern void func_001bbef0(u8 *arg0, f32 arg1);               (line 47)
 * extern void func_00195850(u8 *arg0, f32 *arg1);              (line 67)
 * extern void func_001bd780(void *arg0, void *arg1,
 *                           void *arg2, void *arg3);           (line 70)
 * extern u8 D_0060A0E0[];                                      (line 72)
 * extern void func_003dcb40(s64 *arg0, s64 *arg1,
 *                           s32 arg2, u8 *arg3);               (line 96)
 */

// FUN_001C5500
void func_001c5500(u8 *arg0)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
    } geometry;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *primaryUnit;
    u8 *secondaryUnit;
    f32 length;
    f32 scale;
    f32 dotProduct;
    f32 crossProduct;
    f32 radius;
    f32 radiusScale;
    f32 heightFactor;
    f32 offsetFactor;
    f32 unitY;
    f32 projDist;
    f32 accumDist;
    f32 tanFov;
    f32 distScale;
    f32 var_f20;
    u16 command;

    action = *(u8 **)(arg0 + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_00195850(actor, (f32 *)&actorPosition);
    func_00195850(target, (f32 *)&targetPosition);

    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    length = func_003e40b0((f32 *)&direction, (f32 *)&direction);

    geometry.horizontal[0] = *(f32 *)(arg0 + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(arg0 + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    scale = fGpffff8128 * length;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetPosition.x;
    focus.y += targetPosition.y;
    focus.z += targetPosition.z;

    geometry.perpendicular[0] = direction.x;
    geometry.perpendicular[1] = direction.z;
    dotProduct = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];

    offsetFactor = 0.0f;
    if (!(dotProduct < 0.0f)) {
        primaryUnit = actor;
        secondaryUnit = target;
        basePosition = actorPosition;
        radiusScale = 1.5f;
        radius = radiusScale * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        heightFactor = fGpffff8118;
        if (basePosition.y < 125.0f) {
            basePosition.y = 125.0f;
        }
    } else {
        primaryUnit = target;
        secondaryUnit = actor;
        basePosition = targetPosition;
        if (*(u8 *)(target + 0xA2) == 0) {
            radius = 1.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 3.5f;
        } else {
            radius = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 1.75f;
        }
        heightFactor = 0.25f;
        offsetFactor = heightFactor;
    }

    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    crossProduct = geometry.perpendicular[1] * geometry.horizontal[1] + geometry.perpendicular[0] * geometry.horizontal[0];
    unitY = basePosition.y;
    eye.y = unitY + offsetFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));

    if (!(crossProduct < 0.0f)) {
        eye.x = basePosition.x + direction.z * radius;
        eye.z = basePosition.z - direction.x * radius;
    } else {
        eye.x = basePosition.x - direction.z * radius;
        eye.z = basePosition.z + direction.x * radius;
    }

    savedDirection = direction;
    func_001bd780(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    func_003dcb40((s64 *)&direction, (s64 *)D_0060A100, 1, (u8 *)&poses.secondRotation);

    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = basePosition.z;
    projDist = func_001ec3d0((u8 *)geometry.focusXZ,
                             (u8 *)geometry.eyeXZ,
                             (u8 *)baseXZ,
                             (u8 *)projectionXZ);
    accumDist = projDist + radiusScale * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = unitY;
    eye.z = projectionXZ[1];

    tanFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    distScale = accumDist / tanFov;
    if (distScale < 500.0f) {
        distScale = 500.0f;
    }
    direction.x *= distScale;
    direction.y *= distScale;
    direction.z *= distScale;

    if (!(dotProduct < 0.0f)) {
        if (crossProduct < 0.0f) {
            eye.x += savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z -= savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    } else {
        if (!(crossProduct < 0.0f)) {
            eye.x -= savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z += savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    }

    eye.y = unitY + heightFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;

    func_001bd560((f32 *)&poses.first, (f32 *)(arg0 + 0x9C));
    if (!(func_001ec2b0(&poses.firstRotation, &poses.secondRotation) <= fGpffff8158)) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        func_003dcb40((s64 *)&direction, (s64 *)D_0060A100, 1, (u8 *)&poses.firstRotation);
        direction.x *= 150.0f;
        direction.y *= 150.0f;
        direction.z *= 150.0f;
        poses.second.x += direction.x;
        poses.second.y += direction.y;
        poses.second.z += direction.z;
        command = 3;
        if (*(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x88) == 0) {
            func_004b3110(8);
        }
        var_f20 = 1.5f;
    } else {
        command = 0xC3;
        var_f20 = fGpffff814c;
    }

    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }

    func_001bcd40(*(u8 **)(arg0 + 0xE0), secondaryUnit + 4, (u8 *)&poses.second, 50.0f, command);
    func_001bac20(arg0, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    func_001bbef0(arg0, var_f20);
}
