/* Fresh reconstruction; NOT MATCHED, NOT PROMOTED.
 * Main current-owner replay: 1080/1104 bytes, nd580, thirteen object relocations.
 * Twenty-four retail-window bytes lie beyond the candidate. nd counts
 * relocation-masked differing bytes, not differing instructions.
 * One initial compiler replay; no native behavioral verification.
 * The agent's unsupported 100-percent-match statement is discarded.
 * The retail wrap uses !(result <= 360.0f), so exactly 360.0f is retained.
 * Production remains ASM; no supporting declaration changes were promoted.
 * The owner still has a legacy old-style normalizer declaration; this archive
 * records its measured context, not a completed provider-contract migration.
 * 
 * Agent reconstruction notes (not a compiler-equivalence proof):
 * EVIDENCE REPORT: func_0016f8b0 (FreshFieldMotion Recovery)
 * ============================================================
 * 
 * 1. TARGET IDENTIFICATION
 * ------------------------
 * Symbol: func_0016f8b0
 * Canonical marker: // FUN_0016F8B0
 * Retail Address: 0x0016f8b0
 * Window Size: 1104 bytes (0x450, 276 instructions)
 * Owner File: src/promoted/code1_0016.c (line 2240)
 * Retail Assembly: asm/nonmatchings/code1_0016/func_0016f8b0.s
 * 
 * 2. FUNCTION PURPOSE & BEHAVIOR
 * ------------------------------
 * Translates analog stick and/or directional pad input from PlayStation 2 controller
 * buffers into a normalized heading angle in degrees [0.0f, 360.0f].
 * - If arg1 == 0: Handles Left Stick analog coordinates (D_008C025C, D_008C025D) with
 *   D-Pad digital override/deadzone filtering (D_008C024C).
 * - If arg1 != 0: Handles Right Stick analog coordinates (D_008C025E, D_008C025F) with
 *   standard deadzone filtering.
 * - Deadzone: If input vector falls within [-48.0f, 48.0f] on both axes, returns 0.0f.
 * - Vector Angle: Normalizes (x, z) using func_003e40b0, computes acosf(z / length) * rad2deg,
 *   adjusts quadrant based on sign of x, offsets by 180 degrees, and wraps to [0.0f, 360.0f].
 * 
 * 3. PARAMETERS & RETURN VALUE
 * ----------------------------
 * - arg0 ($4, s32): Controller/Pad index (typically 0 for pad 1, 1 for pad 2).
 *   Used to compute pad struct byte offset: offset = arg0 * 0x4A (74 bytes per pad).
 * - arg1 ($5, s32): Stick mode selector.
 *   0 = Left Stick + D-pad override; non-zero = Right Stick only.
 * - Return ($f0, f32): Floating-point angle in degrees [0.0f, 360.0f]. Default return is 0.0f.
 * 
 * 4. ACTUAL STORAGE & STACK LAYOUT
 * --------------------------------
 * Total frame size: 0x30 (48 bytes) allocated at 6F8B0 (`addiu $29, $29, -0x30`).
 * - 0x00($29) - 0x07($29): Saved Return Address ($31) saved with `sd $31, 0x0($29)`,
 *                          restored with `ld $31, 0x0($29)`.
 * - 0x08($29) - 0x0F($29): Alignment padding / compiler shadow space.
 * - 0x10($29) - 0x1B($29): Local `RwV3d input` (12 bytes, initialized to 0 in prologue):
 *     0x10($29): input.x (f32)
 *     0x14($29): input.y (f32, stays 0.0f)
 *     0x18($29): input.z (f32)
 * - 0x20($29) - 0x2B($29): Local `RwV3d normalized` (12 bytes, output of func_003e40b0):
 *     0x20($29): normalized.x (f32)
 *     0x24($29): normalized.y (f32)
 *     0x28($29): normalized.z (f32)
 * 
 * 5. DETAILED CONTROL FLOW & EVERY BRANCH
 * ---------------------------------------
 * Prologue Zeroing Loop:
 * - 6F8C0: `beqz $3, .L0016F8E4` -> Null check on `clear = (u8 *)&input`.
 * - 6F8DC: `bnez $2, .L0016F8C8` -> 12-iteration loop zeroing 12 bytes at 0x10($29).
 * 
 * Stick Mode Branch:
 * - 6F8E8: `bnez $5, .L0016FAC8` -> Branches to Right Stick path if arg1 != 0.
 * 
 * Path A: Left Stick + D-Pad (arg1 == 0, 6F8F0 - 6FAC4):
 * - 6F8F0-6F900: Multiplies arg0 by 74 (0x4A) using strength reduction (sll 3, addu, sll 2, addu, sll 1) -> $5.
 * - 6F904-6F910: Loads analog Y byte from `D_008C025D[offset]` using `lbu $2`.
 * - 6F914: `bltz $2, .L0016F930` -> Standard mwcc unsigned 32-bit to float conversion sequence for `(f32)(u32)D_008C025D[offset]`.
 * - 6F928: `b .L0016F94C` -> Jumps past negative-integer float adjustment.
 * - 6F958-6F95C: Subtracts 128.0f (0x43000000) and stores to input.z (0x18($29)).
 * - 6F960-6F96C: Loads button mask from `*(u16 *)((u8 *)D_008C024C + offset)` into $5.
 * - 6F970-6F974: `andi $2, $5, 0x1000`; `beqz $2, .L0016F98C` -> If D-Pad UP pressed, stores -128.0f (0xC3000000) into input.z.
 * - 6F984: `b .L0016F99C` -> Jumps over DOWN check.
 * - 6F98C-6F990: `andi $2, $5, 0x4000`; `beqz $2, .L0016F99C` -> If D-Pad DOWN pressed, stores +128.0f into input.z.
 * - 6F99C-6F9A0: `andi $2, $5, 0xA000`; `beqz $2, .L0016F9E0` -> If neither LEFT (0x8000) nor RIGHT (0x2000) pressed, skip cross-deadzone zeroing.
 * - 6F9A8-6F9DC: Compares input.z with [-48.0f, 48.0f].
 *   - 6F9B8-6F9BC: `c.lt.s $f2, $f1` (-48.0f); `bc1t .L0016F9E0` -> If input.z < -48.0f, skip zeroing.
 *   - 6F9D0-6F9D4: `c.le.s $f2, $f1` (48.0f); `bc1f .L0016F9E0` -> If !(input.z <= 48.0f), skip zeroing.
 *   - 6F9DC: `sw $0, 0x18($29)` -> Sets input.z = 0.0f.
 * - 6F9E0-6F9F0: Recomputes offset = (u32)arg0 * 0x4A into $3 (because $5 was clobbered by buttons).
 * - 6F9F4-6FA00: Loads analog X byte from `D_008C025C[offset]`.
 * - 6FA04: `bltz $2, .L0016FA20` -> Unsigned-to-float conversion for `(f32)(u32)D_008C025C[(u32)arg0 * 0x4A]`.
 * - 6FA18: `b .L0016FA3C` -> Jumps past negative-integer float adjustment.
 * - 6FA48-6FA4C: Subtracts 128.0f and stores to input.x (0x10($29)).
 * - 6FA50-6FA54: `andi $2, $5, 0x8000`; `beqz $2, .L0016FA6C` -> If D-Pad LEFT pressed, stores -128.0f into input.x.
 * - 6FA64: `b .L0016FA7C` -> Jumps over RIGHT check.
 * - 6FA6C-6FA70: `andi $2, $5, 0x2000`; `beqz $2, .L0016FA7C` -> If D-Pad RIGHT pressed, stores +128.0f into input.x.
 * - 6FA7C-6FA80: `andi $2, $5, 0x5000`; `beqz $2, .L0016FBFC` -> If neither UP (0x1000) nor DOWN (0x4000) pressed, skip cross-deadzone zeroing.
 * - 6FA88-6FABC: Compares input.x with [-48.0f, 48.0f].
 *   - 6FA98-6FA9C: `c.lt.s $f2, $f1` (-48.0f); `bc1t .L0016FBFC` -> If input.x < -48.0f, skip zeroing.
 *   - 6FAB0-6FAB4: `c.le.s $f2, $f1` (48.0f); `bc1f .L0016FBFC` -> If !(input.x <= 48.0f), skip zeroing.
 *   - 6FABC: `sw $0, 0x10($29)` -> Sets input.x = 0.0f.
 * - 6FAC0: `b .L0016FBFC` -> Jumps to deadzone decision.
 * 
 * Path B: Right Stick (arg1 != 0, 6FAC8 - 6FBF8):
 * - 6FAC8-6FAD8: Multiplies arg0 by 74 (0x4A) into $4. $4 remains valid for both X and Y.
 * - 6FADC-6FAE8: Loads analog Y byte from `D_008C025F[offset]`.
 * - 6FAEC: `bltz $2, .L0016FB08` -> Unsigned-to-float conversion.
 * - 6FB00: `b .L0016FB24` -> Jumps past negative adjustment.
 * - 6FB30-6FB34: Subtracts 128.0f and stores to input.z (0x18($29)).
 * - 6FB38-6FB68: Clamps input.z in deadzone [-48.0f, 48.0f]:
 *   - 6FB44-6FB48: `c.lt.s $f2, $f1`; `bc1t .L0016FB6C` -> Skip zeroing if < -48.0f.
 *   - 6FB5C-6FB60: `c.le.s $f2, $f1`; `bc1f .L0016FB6C` -> Skip zeroing if > 48.0f.
 *   - 6FB68: `sw $0, 0x18($29)` -> input.z = 0.0f.
 * - 6FB6C-6FB78: Loads analog X byte from `D_008C025E[offset]`.
 * - 6FB7C: `bltz $2, .L0016FB98` -> Unsigned-to-float conversion.
 * - 6FB90: `b .L0016FBB4` -> Jumps past negative adjustment.
 * - 6FBC0-6FBC4: Subtracts 128.0f and stores to input.x (0x10($29)).
 * - 6FBC8-6FBF8: Clamps input.x in deadzone [-48.0f, 48.0f]:
 *   - 6FBD4-6FBD8: `c.lt.s $f2, $f1`; `bc1t .L0016FBFC` -> Skip zeroing if < -48.0f.
 *   - 6FBEC-6FBF0: `c.le.s $f2, $f1`; `bc1f .L0016FBFC` -> Skip zeroing if > 48.0f.
 *   - 6FBF8: `sw $0, 0x10($29)` -> input.x = 0.0f.
 * 
 * Deadzone Decision & Vector Processing (.L0016FBFC - .L0016FCEC):
 * - 6FC0C-6FC10: `c.lt.s $f1, $f3` (-48.0f); `bc1t .L0016FC4C` -> If input.z < -48.0f, enter math block.
 * - 6FC24-6FC28: `c.le.s $f1, $f2` (48.0f); `bc1f .L0016FC4C` -> If !(input.z <= 48.0f), enter math block.
 * - 6FC34-6FC38: `c.lt.s $f1, $f3` (-48.0f); `bc1t .L0016FC4C` -> If input.x < -48.0f, enter math block.
 * - 6FC40-6FC44: `c.le.s $f1, $f2` (48.0f); `bc1t .L0016FCEC` -> If input.x <= 48.0f, inside deadzone: exit and return 0.0f.
 * - 6FC4C-6FC58: Calls `func_003e40b0(&normalized, &input)` (RwV3dNormalize).
 * - 6FC5C-6FC60: Post-callback reload: loads `normalized.z` (0x28($29)) into $f1 and `normalized.x` (0x20($29)) into $f0.
 * - 6FC64: `mula.s $f1, $f1` -> ACC = normalized.z * normalized.z.
 * - 6FC68: `madd.s $f0, $f0, $f0` -> $f0 = ACC + normalized.x * normalized.x.
 * - 6FC6C: `c1 0x4` -> COP1 instruction `sqrt.s $f0, $f0` (sqrtf intrinsic).
 * - 6FC78: `div.s $f12, $f1, $f0` -> $f12 = normalized.z / sqrt(lengthSquared).
 * - 6FC88: Calls `func_0044b920($f12)` (acosf implementation), result in $f0.
 * - 6FC90-6FC94: Multiplies result by `fGpffff8300` (loaded from -0x7D00($gp), 180.0f / M_PI).
 * - 6FC98: Post-callback reload: reloads `normalized.x` from 0x20($29) into $f2 (since $f0-$f19 are volatile across jal).
 * - 6FC9C-6FCA4: `c.lt.s $f2, $f1` (0.0f); `bc1f .L0016FCC0` -> If !(normalized.x < 0.0f), skip quadrant correction.
 * - 6FCB0-6FCBC: `result = 360.0f - result` ($f1 = 0x43B40000).
 * - 6FCC0-6FCCC: `result = result + 180.0f` ($f1 = 0x43340000).
 * - 6FCD0-6FCE0: `c.le.s $f0, $f1` (360.0f); `bc1t .L0016FCEC` -> If result <= 360.0f, skip wraparound.
 * - 6FCE8: `result = result - 360.0f`.
 * - 6FCEC: Function exit: restores $31, adds 0x30 to $29, returns $f0 via `jr $31`.
 * 
 * 6. CALLBACK MUTATIONS & POST-CALLBACK RELOADS
 * ---------------------------------------------
 * 1. `func_003e40b0(&normalized, &input)` at 6FC54:
 *    - Output destination `&normalized` is stack address 0x20($29).
 *    - Writes `normalized.x` at 0x20($29), `normalized.y` at 0x24($29), `normalized.z` at 0x28($29).
 *    - Immediate reload: `normalized.z` (0x28($29)) -> $f1, `normalized.x` (0x20($29)) -> $f0.
 * 2. `func_0044b920(...)` at 6FC88:
 *    - Clobbers all volatile floating-point registers ($f0-$f19).
 *    - Return value delivered in $f0.
 *    - Post-callback reload: `normalized.x` is reloaded from 0x20($29) into $f2 at 6FC98 because
 *      the register holding normalized.x prior to the call is volatile and cannot survive across `jal`.
 * 
 * 
 * Remaining uncertainty: generated instructions do not match retail. Complete
 * source is retained for a future explanation, not another blind layout sweep.
 *
 */

/* Minimal integration declarations for func_0016f8b0 in src/promoted/code1_0016.c */

#include "type.h"
#include "Kosaka/k_fldFrame_internal.h"

/*
 * Note on existing declarations in src/promoted/code1_0016.c:
 * - RwV3d is already provided by "Kosaka/k_fldFrame_internal.h" (line 3).
 * - func_003e40b0 is already declared at line 60: extern void func_003e40b0();
 *
 * Below are the minimal additional declarations required for integration:
 */

/* Controller / Pad input buffers */
extern u16 D_008C024C[]; /* Button mask bitfield (offset 0x0C in pad struct) */
extern u8  D_008C025C[]; /* Left stick X analog byte (offset 0x1C in pad struct) */
extern u8  D_008C025D[]; /* Left stick Y analog byte (offset 0x1D in pad struct) */
extern u8  D_008C025E[]; /* Right stick X analog byte (offset 0x1E in pad struct) */
extern u8  D_008C025F[]; /* Right stick Y analog byte (offset 0x1F in pad struct) */

/* Global GP-relative float constant: rad-to-deg factor (180.0f / M_PI ~= 57.29578f) */
extern f32 fGpffff8300;

/* Math library functions */
extern f32 func_0044b920(f32 arg0); /* acosf wrapper / implementation */
extern f32 sqrtf(f32 arg0);         /* Single-precision square root (mwcc COP1 intrinsic) */

/* Function prototype replacing INCLUDE_ASM("asm/nonmatchings/code1_0016", func_0016f8b0) */
f32 func_0016f8b0(s32 arg0, s32 arg1);

// FUN_0016F8B0
f32 func_0016f8b0(s32 arg0, s32 arg1)
{
    RwV3d input;
    RwV3d normalized;
    u8 *clear;
    s32 remaining;
    u32 offset;
    u16 buttons;
    f32 result;
    f32 lengthSquared;

    clear = (u8 *)&input;
    remaining = sizeof(input);
    if (clear != NULL) {
        do {
            *clear = 0;
            clear += 1;
            remaining -= 1;
        } while (remaining != 0);
    }
    result = 0.0f;
    if (arg1 == 0) {
        offset = (u32)arg0 * 0x4A;
        input.z = (f32)(u32)D_008C025D[offset] - 128.0f;
        buttons = *(u16 *)((u8 *)D_008C024C + offset);
        if (buttons & 0x1000) {
            input.z = -128.0f;
        } else if (buttons & 0x4000) {
            input.z = 128.0f;
        }
        if ((buttons & 0xA000) && !(input.z < -48.0f) &&
            (input.z <= 48.0f)) {
            input.z = 0.0f;
        }

        input.x = (f32)(u32)D_008C025C[(u32)arg0 * 0x4A] - 128.0f;
        if (buttons & 0x8000) {
            input.x = -128.0f;
        } else if (buttons & 0x2000) {
            input.x = 128.0f;
        }
        if ((buttons & 0x5000) && !(input.x < -48.0f) &&
            (input.x <= 48.0f)) {
            input.x = 0.0f;
        }
    } else {
        offset = (u32)arg0 * 0x4A;
        input.z = (f32)(u32)D_008C025F[offset] - 128.0f;
        if (!(input.z < -48.0f) && (input.z <= 48.0f)) {
            input.z = 0.0f;
        }
        input.x = (f32)(u32)D_008C025E[offset] - 128.0f;
        if (!(input.x < -48.0f) && (input.x <= 48.0f)) {
            input.x = 0.0f;
        }
    }

    if ((input.z < -48.0f) || !(input.z <= 48.0f) ||
        (input.x < -48.0f) || !(input.x <= 48.0f)) {
        func_003e40b0(&normalized, &input);
        lengthSquared = normalized.z * normalized.z;
        lengthSquared += normalized.x * normalized.x;
        result = func_0044b920(normalized.z / sqrtf(lengthSquared)) *
                 fGpffff8300;
        if (normalized.x < 0.0f) {
            result = 360.0f - result;
        }
        result += 180.0f;
        if (!(result <= 360.0f)) {
            result -= 360.0f;
        }
    }
    return result;
}
