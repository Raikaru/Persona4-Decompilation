/* Radial provider continuation: func_00365f00
 * Owner src/shdMisc.c; retail window 00365F00..00366380.
 * Banked guarded floor (// FUN_00365F00 NONMATCHING): compiles to 1148/1152
 * bytes, 17 independently resolved relocations, normalized diff 25.
 * Reproduce: `python3 tools/probe_variants.py src/shdMisc.c func_00365f00
 * --candidate base=<this body>` scores 25; `python3 tools/measure_guarded.py
 * src/shdMisc.c func_00365f00` replays 25 from the banked source.
 * opclass on the banked floor reports no opcode-class surplus: the residual
 * is register coloring only, not width/signedness/call shape.
 * All 25 differing words are one five-register color/count rotation:
 * generated edge_a=$s3 edge_b=$s2 edge_g=$s6 edge_r=$s7 count=$fp against
 * retail edge_a=$s2 edge_b=$s6 edge_g=$s7 edge_r=$fp count=$s3. Frame,
 * spills, FP schedule and relocations are otherwise identical.
 * Ten further declaration/type spellings tie at 25 (edge swap, count-first,
 * count-after-edge, reversed edges, edge_a-last, i-last, u16 count,
 * edge/center interleave, init-at-declaration, u32 count mask), closing the
 * floor verdict: saved-register coloring floor, not an ordering oversight.
 * Earlier path, retained: byte-snapshot 1216/nd794; promoted color snapshots
 * and deferred center-red 1180/nd789; typed row cursor 1164/nd758; direct
 * unsigned-byte views 1148/nd55; float declaration order nd44; position.y
 * subobject read nd31->25 with the integer rotation isolated as the sole
 * remainder. Positive assertion form +1; early count snapshot and
 * propagation-off regress. No padding or binding.
 *
 * ABI is shared Vec2f position, depth, packed32 center/edge colors, radius,
 * angle, full u32 segments, xscale, yscale, mode. The loop and assertion use
 * low16 count; the angle divisor uses all32 segment bits. Preserve 102 rows
 * of 16 floats (0x1980 bytes), the previous-row reciprocal store, and late
 * callback/global reloads. Only fields written by retail are initialized.
 * Unsupported counts and unwritten vertex fields are not silently normalized
 * or filled. GP -7E20 is 2*pi (40C90FDB); GP -5418 is the 64-bit render flag
 * word. Compiler/relocation evidence only; no radial geometry runtime or PS2
 * graphical presentation claim is made.
 *
 */

#include "type.h"
#include "shd_misc_internal.h"

/* External GP data and tables referenced by retail binary */
extern s64 iGpffffabe8;
extern f32 D_008872F8[];
extern f32 iGpffff81e0;
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887310[])(s32, void *, s32);
extern char D_0064E2F8[];

/* External functions */
u8 *func_00457120(void);
f32 func_0044b610(f32 fparg0);
f32 func_0044b7b0(f32 fparg0);
void func_0046d730(char *, s32);


// FUN_00365F00
void func_00365f00(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
                   f32 radius, f32 angle, u32 segments, f32 xscale, f32 yscale,
                   s32 mode) {
    f32 vertices[102][16];
    f32 (*vertex)[16];
    f32 sine;
    f32 cosine;
    f32 reciprocal;
    f32 origin_x;
    f32 origin_y;
    f32 far_depth;
    f32 current_angle;
    s32 i;
    s32 edge_a;
    s32 edge_b;
    s32 edge_g;
    s32 edge_r;
    s32 center_a;
    s32 center_b;
    s32 center_g;
    s32 num_segments;


    edge_a = ((u8 *)&edgeColor)[3];
    edge_b = ((u8 *)&edgeColor)[2];
    edge_g = ((u8 *)&edgeColor)[1];
    edge_r = ((u8 *)&edgeColor)[0];

    center_a = ((u8 *)&centerColor)[3];
    center_b = ((u8 *)&centerColor)[2];
    center_g = ((u8 *)&centerColor)[1];

    origin_y = *(f32 *)((u8 *)&position + 4);
    origin_x = position.x;

    far_depth = D_008872F8[0];
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);

    num_segments = (s32)(segments & 0xFFFF);
    if (num_segments <= 0 || num_segments > 100) {
        func_0046d730(D_0064E2F8, 571);
    }

    vertices[0][0] = position.x;
    vertices[0][1] = origin_y;
    far_depth -= depth;
    vertices[0][2] = far_depth;

    vertices[0][8] = (f32)(u32)((u8 *)&centerColor)[0];
    vertices[0][9] = (f32)(u32)center_g;
    vertices[0][10] = (f32)(u32)center_b;
    vertices[0][11] = (f32)(u32)center_a;

    for (i = 0; i <= num_segments; i++) {
        current_angle = angle + (iGpffff81e0 * (f32)i) / (f32)segments;
        vertex = &vertices[i];

        sine = func_0044b7b0(current_angle);
        vertex[1][0] = (0.0f + origin_x) + xscale * (radius * sine);

        cosine = func_0044b610(current_angle);
        vertex[1][1] = (0.0f + origin_y) + yscale * (radius * cosine);

        vertex[1][2] = far_depth;

        vertex[1][8] = (f32)(u32)edge_r;
        vertex[1][9] = (f32)(u32)edge_g;
        vertex[1][10] = (f32)(u32)edge_b;
        vertex[1][11] = (f32)(u32)edge_a;

        vertex[0][6] = reciprocal;
    }

    D_00887300[0](1, 0);

    if (mode != 0) {
        iGpffffabe8 |= 0x80;
    }

    D_00887310[0](5, vertices, num_segments + 2);

    if (mode != 0) {
        iGpffffabe8 &= ~0x80;
    }
}
