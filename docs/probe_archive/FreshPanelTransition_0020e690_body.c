/* Fresh panel transition recovery: func_0020e690.
 * Owner: src/promoted/code1_0020.c. First reconstruction is exact: 964/976
 * bytes, three call relocations, twelve zero alignment bytes. Independently
 * resolving all three calls reproduces all 976 retail bytes. No pragma,
 * register binding, padding object, invented input or undefined local is used.
 * 
 * Five integer-bank inputs are task, transition, panel, color and output;
 * two FP-bank inputs are x and y. The work getter's return is unused but its
 * callback must occur before loading transition frame/flags. Preserve the
 * frame snapshot across drawing and reload the flags afterward. The exit
 * path changes only alpha/slide. The entering path may draw, update output
 * state or activate the panel using the saved frame and current flags.
 * 
 * The zero-duration ramp has two identical frame<0 tests. Its division by
 * zero is unreachable. This is the same source convention as existing
 * func_0020e5c0 and adjacent func_0020f4d0, not an executed exceptional path.
 * A model using an explicit step function gives the same observed behavior.
 * 
 * The real drawing provider func_003657d0 now takes canonical Vec2f by value,
 * not an integer reinterpreted through float pointers. Its 752-byte body and
 * 14 relocations remain exact. include/shd_misc_internal.h owns the complete
 * prototype. Removed stale cursor/persona declarations and consolidated the
 * persona owner's duplicate Vec2f definition. Existing assembly callers retain
 * the identical eight-byte integer-bank argument layout. No compatibility shim.
 * 
 * Integrated transition AND real drawing-provider source pass 335,872 native
 * cases with GCC and Clang. Clang uses ASan, UBSan, float-divide-by-zero and
 * float-cast-overflow sanitizers. GCC ASan could not link because both shared
 * and static libasan are absent; GCC's successful run is unsanitized.
 * 262,144 cases cover all signed-halfword frames with all four relevant flag
 * combinations; 65,536 cover all halfword flag values with boundary frames;
 * 8,192 add full-width integer frames. Getter/camera/draw callbacks mutate
 * frames, flags, output and projection data. Compare full fixture state and
 * canaries, phase-dependent writes and calls, all four vertices' geometry,
 * depth, reciprocal and RGBA, and temporary render-flag visibility. Camera
 * parameters, colors and coordinates vary over finite representable values.
 * The quarter-turn constant is checked against retail data. Native sine/cosine
 * backends exercise provider arithmetic, not PS2 graphical presentation or
 * bit-level equivalence of the retail trigonometric implementation.
 * 
 * Full make all lint-errors passes: 172 objects linked, both retail SHA-1
 * hashes exact, all 12,720 functions scanned, zero findings in 338 first-party
 * files. Totals: 7,794 MATCH / 4,926 ASM overall; 6,164 MATCH / 696 ASM first-party.
 * The overall all-matching objective remains incomplete.
 */

#include "shd_misc_internal.h"
extern u8 *func_00452560(s32);
extern void func_0021b310(u8 *, s32);
// FUN_0020E690
void func_0020e690(u8 *task, u8 *transition, u8 *panel,
                   f32 x, f32 y, s32 color, u8 *output)
{
    Vec2f position;
    s32 frame;
    f32 fade;
    f32 slide;
    func_00452560(*(s32 *)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (*(u16 *)(transition + 0x14) & 2) {
        if (frame < 3) fade = 0.0f;
        else if (frame < 9) fade = (f32)(frame - 3) / 6.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * (1.0f - fade));
        if (frame < 0) slide = 0.0f;
        else if (frame < 6) slide = (f32)frame / 6.0f;
        else slide = 1.0f;
        *(f32 *)output = -30.0f * slide;
    } else {
        if (frame < 0) slide = 0.0f;
        else if (frame < 0) slide = (f32)frame / 0.0f;
        else slide = 1.0f;
        if (!(slide <= 0.0f)) {
            position.x = 89.0f + x;
            position.y = 86.0f + y;
            func_003657d0(position, 0.0f, color, 22.0f * slide, 0.0f, 1);
        }
        if (frame < 0) fade = 0.0f;
        else if (frame < 3) fade = (f32)frame / 3.0f;
        else fade = 1.0f;
        output[4] = (u8)(255.0f * fade);
        *(f32 *)output = 10.0f * (1.0f - fade);
        if (*(u16 *)(transition + 0x14) & 4) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        } else if (frame == 3) {
            func_0021b310(panel, 1);
        } else if (frame > 3) {
            *(f32 *)(output + 0xC) = 55.0f;
            *(f32 *)(output + 0x10) = 89.0f;
            *(s32 *)(output + 8) = 1;
        }
    }
}
