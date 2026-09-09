/* Fresh primitive builder candidate: func_0045d370.
 * Owner: src/promoted/code1_0045.c. PRODUCTION REMAINS ASM.
 * Preferred source owner replay:852/880 bytes,nd455,six object relocations.
 * The retail880-byte body ends in the restore/addiu/jr/nop sequence at0045D6D0..
 * 0045D6DC;28 executable bytes remain uncovered. No exact-match claim is made.
 * Explicit zero-accumulator additions and scoped opt_propagation off both tie
 * 852/nd455. The unmodified first source below remains the preferred archive.
 * 
 * Retail inputs: output buffer,color bytes,mutable signed-word rectangle,depth,
 * signed-halfword X/Y origins,angle,X/Y scales. Rectangle width/height are scaled
 * and truncated in place. Four64-byte vertex records are written (256-byte output
 * extent), with coordinates at0/4/8,scalar at24 and RGBA floats at32..44. This
 * candidate introduces no padded aggregate, register binding or inline assembly.
 * The source is a structural reconstruction, not a behavioral or byte-match proof.
 * No native/Wasm behavior smoke was run; compiled C callers are intentionally
 * unchanged while the production target remains ASM.
 */

/* Scratch integration contract, NOT an extra production translation unit.
 * body.c replaces only the func_0045d370 INCLUDE_ASM at line 1321 of src/promoted/code1_0045.c.
 * The declarations below document the provider and caller contracts.
 */
#include "type.h"

extern f32 D_008872F8_abs[];
extern f32 fGpffff8200;
extern s32 func_00457120(void);
extern f32 func_0044b7b0(f32 angle);
extern f32 func_0044b610(f32 angle);

void func_0045d370(f32 *out, u8 *colors, s32 *pos, f32 z, s16 ox, s16 oy, f32 angle, f32 scale_x, f32 scale_y);

/* src/promoted/code1_0045.c integration:
 * - Line 1321: replace `INCLUDE_ASM("asm/nonmatchings/code1_0045", func_0045d370);`
 *   with the reconstructed body.c.
 * - Sibling primitive provider func_0045ce40 (lines 1276-1319) already matches and
 *   uses identical types (f32 *out, u8 *colors, s32 *pos, f32 z), symbols
 *   (D_008872F8_abs, func_00457120), and 64-byte vertex strides (16 floats per vertex).
 * - Sibling caller func_0045d6e0 (lines 1323-1356) allocates work.out (0x100 = 256 bytes)
 *   and calls func_0045ce40, passing (s32 *)&work.pos and drawing with D_00887310[0](4, &work.out, 4).
 *
 * Caller integration in src/sdkPrimitive.c:
 * - Line 15 currently declares:
 *     extern void func_0045d370(void *out, void *a1, void *a2, f32 f0, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3);
 * - Line 80 callsite in func_0045db40:
 *     func_0045d370(&work.out, arg0, &work.pos, fparg0, arg3, arg4, fparg1, fparg2, fparg3);
 *   passes:
 *     $a0 = &work.out   (f32 *out: 256-byte quad buffer for 4 vertices)
 *     $a1 = arg0        (u8 *colors: 4 bytes RGBA)
 *     $a2 = &work.pos   (s32 *pos: x, y, width, height)
 *     $f12 = fparg0     (f32 z: depth value)
 *     $a3 = arg3        (s16 ox: origin X offset relative to rect)
 *     $t0 = arg4        (s16 oy: origin Y offset relative to rect)
 *     $f13 = fparg1     (f32 angle: rotation angle in degrees)
 *     $f14 = fparg2     (f32 scale_x: width scaling factor)
 *     $f15 = fparg3     (f32 scale_y: height scaling factor)
 * - Upgrading the prototype in src/sdkPrimitive.c to typed (f32*, u8*, s32*, f32, s16, s16, f32, f32, f32)
 *   matches retail parameter widths and registers without changing callers.
 */

// FUN_0045D370
void func_0045d370(f32 *out, u8 *colors, s32 *pos, f32 z, s16 ox, s16 oy, f32 angle, f32 scale_x, f32 scale_y)
{
    f32 coords[8];
    f32 inv;
    f32 sine;
    f32 cosine;
    f32 neg_ox;
    f32 neg_oy;
    f32 cx;
    f32 cy;
    f32 y_sin;
    f32 y_cos;
    f32 neg_sine;
    f32 w_rel;
    f32 h_rel;
    f32 h_sin;
    f32 h_cos;
    f32 *v;
    u32 i;

    inv = 1.0f / *(f32 *)((u8 *)func_00457120() + 0x80);
    z = D_008872F8_abs[0] - z;
    pos[2] = (s32)((f32)pos[2] * scale_x);
    pos[3] = (s32)((f32)pos[3] * scale_y);

    angle *= fGpffff8200;
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);

    neg_ox = (f32)-ox;
    neg_oy = (f32)-oy;

    cx = (f32)(pos[0] + ox);
    y_sin = neg_oy * sine;
    coords[0] = cx + (neg_ox * cosine + y_sin);

    neg_sine = -sine;
    cy = (f32)(pos[1] + oy);
    y_cos = neg_oy * cosine;
    coords[1] = cy + (neg_ox * neg_sine + y_cos);

    w_rel = (f32)(pos[2] - ox);
    coords[2] = cx + (w_rel * cosine + y_sin);
    coords[3] = cy + (w_rel * neg_sine + y_cos);

    h_rel = (f32)(pos[3] - oy);
    h_sin = h_rel * sine;
    coords[4] = cx + (neg_ox * cosine + h_sin);
    h_cos = h_rel * cosine;
    coords[5] = cy + (neg_ox * neg_sine + h_cos);

    coords[6] = cx + (w_rel * cosine + h_sin);
    coords[7] = cy + (w_rel * neg_sine + h_cos);

    for (i = 0; i < 4; i++) {
        v = &out[i * 16];
        v[0] = coords[i * 2 + 0];
        v[1] = coords[i * 2 + 1];
        v[2] = z;
        v[8] = (f32)colors[0];
        v[9] = (f32)colors[1];
        v[10] = (f32)colors[2];
        v[11] = (f32)colors[3];
        v[6] = inv;
    }
}
