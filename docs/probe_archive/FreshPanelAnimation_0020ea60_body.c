/* Fresh staged panel animation recovery: func_0020ea60.
 * Owner src/promoted/code1_0020.c. Exact ordinary C: 1192/1200 bytes, eight
 * independently resolved call relocations, eight zero alignment bytes.
 * Resolving the calls directly reproduces all 1200 retail bytes.
 * 
 * Initial single-expression slide arithmetic had 37 differing bytes.
 * Reusing fade for each arithmetic assignment left four operand-order bytes.
 * Alternating fade and y assignments closes them without pragmas, padding,
 * register binding or invented inputs. Distinct named intermediates fold back
 * to the initial expression; propagation-off regresses to 1200 bytes/nd840.
 * The emitted source preserves the exact floating operation boundaries.
 * 
 * The four inputs are task, transition, panel and output. Read the frame
 * only after the work getter, retain it across sprite callbacks, and reload
 * flags for the final output/activation choice. The initial two-sprite stretch
 * is reset to unit scale before the second two-sprite group. Save its alpha
 * and Y coordinate across callbacks. Recompute the final fade from the saved
 * frame rather than reloading the transition frame or retaining callback-
 * clobbered FP state. Active flag4 takes precedence over frame6 activation.
 * Only the specified output fields are overwritten.
 * 
 * The integrated target plus actual func_002019d0, func_00201650,
 * func_00201410 and p4_002091f0_add pass 335,872 Wasm32 cases with no imports.
 * This exercises real32-bit pointer addition, scale/coordinate setup,
 * color/alpha forwarding and post-callback descriptor resets. The final
 * sprite submission callback records the descriptor, then mutates frame,
 * flags, coordinates, scales, resource selection, UV scales and output.
 * An independent staged model compares the complete state/guard regions and
 * all queued descriptor bytes, including transient RGBA, position and scale.
 * 
 * 262,144 cases cover every signed-halfword frame with four flag combinations;
 * 65,536 cover all halfword flags at boundary frames; 8,192 add full-width
 * integer frames. The work getter also mutates state before the frame load.
 * Scale/crop values stay within the provider's defined integer-conversion
 * ranges. No PS2 graphical-presentation or arbitrary corrupt-work-state
 * claim is made. Existing providers and callers are unchanged.
 */

#include "type.h"
extern u8 *func_00452560(s32);
extern void func_002019d0(u8 *, f32, f32);
extern void func_00201650(u8 *, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_0021b310(u8 *, s32);

// FUN_0020EA60
void func_0020ea60(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 stretch;
    f32 fade;
    f32 y;
    work = func_00452560(*(s32 *)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    stretch = 2.0f * first - second;
    if (!(stretch <= 0.0f)) {
        func_002019d0(work, 1.0f, stretch);
        func_00201650(work, 10, 21, 54.0f, 25.0f, 150, 255, 2, 255);
        func_00201650(work, 10, 22, 54.0f, 70.0f, 150, 255, 2, 255);
        func_002019d0(work, 1.0f, 1.0f);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 71.0f + y;
        y = fade - 16.0f;
        func_00201650(work, 10, 14, 28.0f, y, 150, 255, 2, (u8)alpha);
        func_00201650(work, 10, 13, 28.0f, y, 35, 55, 0, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    output[4] = (u8)(255.0f * fade);
    *(f32 *)output = 20.0f * (1.0f - fade);
    if (*(u16 *)(transition + 0x14) & 4) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    } else if (frame == 6) {
        func_0021b310(panel, 1);
    } else if (frame > 6) {
        *(f32 *)(output + 0xC) = 54.0f;
        *(f32 *)(output + 0x10) = 89.0f;
        *(s32 *)(output + 8) = 1;
    }
}
