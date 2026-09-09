/* Fresh panel expansion recovery: func_0020ef10
 * Owner: src/promoted/code1_0020.c; retail window 0020EF10..0020F4D0.
 * Exact source: 1460 executable bytes, seven independently resolved R_MIPS_26
 * calls, twelve zero alignment bytes. All 1472 retail bytes compare equal.
 * 
 * Measured source progression (differing-byte counts, not instruction counts):
 * - explicit byte alpha branch: 1456/1472 bytes, nd846, seven calls;
 * - promoted conditional alpha: 1460/1472 bytes, nd77;
 * - separate initial expansion / saved fade: 1460/1472 bytes, nd84;
 * - positive-condition alternatives tie nd84;
 * - expansion > 1.0f saturation: 1460/1472 bytes, nd13;
 * - separate first-phase remaining and second-phase fade: nd0.
 * No extra pragma, inline assembly, fixed registers or artificial padding.
 * 
 * The saved integer frame is captured after the work getter and survives all
 * sprite callbacks. First phase is 3*ramp(frame,0,4)-2*ramp(frame,4,8), with
 * saturating alpha and three offset sprites. Separate remaining/fade lifetimes
 * match volatile f2 and retained f20. The integer ramps are bounded and finite;
 * all guarded subtraction and target byte-conversion inputs are in range.
 * Second phase retains alpha/Y across its two sprites. Final opacity/slide uses
 * the saved frame but reloads halfword flags after callbacks. Flag4 precedes
 * frame6 activation. Work scales are not reset by this target.
 * 
 * 335872 Wasm32 smoke cases passed through the actual pointer-add helper,
 * sprite setup and color wrapper. The submission sink captures all 44 bytes
 * of up to five queued descriptors before mutating frame, flags, coordinates,
 * resource IDs, scales, UV fields and output. An independent model compares
 * whole fixtures including guards, transient descriptor data and reset effects.
 * 262144 cases cover all signed-halfword frames with four flag combinations;
 * 65536 cover every halfword flag over sixteen boundary frames and 32 mutation
 * modes; 8192 sample full-width frame bit patterns. Both unit-scale fast paths
 * and scaled/cropped geometry paths are exercised with bounded conversion
 * inputs. This is not a PS2 graphical presentation check or a claim about
 * arbitrary corrupt-work-state behavior. The throwaway harness was compiled
 * with clang --target=wasm32 -O2 -ffp-contract=off -fno-strict-aliasing
 * -fno-builtin -nostdlib and executed as a no-import WebAssembly module.
 *
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
extern u8 *func_00452560(s32 task);
extern void func_00201650(u8 *work, s32 mode, s32 tile, f32 x, f32 y,
                          s32 red, s32 green, s32 blue, s32 alpha);
extern void func_0021b310(u8 *panel, s32 enabled);

// FUN_0020EF10
void func_0020ef10(u8 *task, u8 *transition, u8 *panel, u8 *output)
{
    u8 *work;
    s32 frame;
    u8 alpha;
    f32 first;
    f32 second;
    f32 expansion;
    f32 remaining;
    f32 fade;
    f32 offset;
    f32 y;
    work = func_00452560(*(s32 *)(task + 4));
    frame = *(s32 *)(transition + 0x10);
    if (frame < 0) first = 0.0f;
    else if (frame < 4) first = (f32)frame / 4.0f;
    else first = 1.0f;
    if (frame < 4) second = 0.0f;
    else if (frame < 8) second = (f32)(frame - 4) / 4.0f;
    else second = 1.0f;
    expansion = 3.0f * first - 2.0f * second;
    if (!(expansion <= 0.0f)) {
        alpha = (expansion > 1.0f) ? 255 : (u8)(255.0f * expansion);
        remaining = 1.0f - expansion;
        func_00201650(work, 10, 18, 61.0f,
                      (0.0f + 46.0f - 20.0f * remaining) - 16.0f,
                      244, 255, 14, (u8)alpha);
        offset = 10.0f * remaining;
        remaining = 87.0f + offset;
        y = remaining - 16.0f;
        func_00201650(work, 10, 19, 37.0f - offset, y, 244, 255, 14, (u8)alpha);
        func_00201650(work, 10, 20, 84.0f + offset, y, 244, 255, 14, (u8)alpha);
    }
    if (frame < 2) fade = 0.0f;
    else if (frame < 5) fade = (f32)(frame - 2) / 3.0f;
    else fade = 1.0f;
    if (!(fade <= 0.0f)) {
        alpha = (u8)(255.0f * fade);
        fade = 1.0f - fade;
        y = 20.0f * fade;
        fade = 73.0f + y;
        y = fade - 16.0f;
        func_00201650(work, 10, 12, 47.0f, y, 244, 255, 14, (u8)alpha);
        func_00201650(work, 10, 11, 47.0f, y, 54, 46, 0, (u8)alpha);
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
