/* Radial provider continuation: func_00365f00
 * Owner src/shdMisc.c; retail window00365F00..00366380.
 * Complete preferred C:1148/1152 bytes,17 independently resolved relocations,
 * 4 zero tail bytes,31 differing bytes. All executable instructions are covered.
 * Production remains ASM: this is a measured register-allocation floor, not
 * an impossibility claim and not a new matching recovery.
 * 
 * Initial eager byte-snapshot candidate1216/1152,nd794. Promoted color snapshots
 * and deferred center-red read reach1180/nd789. A typed row cursor reaches1164/
 * nd758. Direct unsigned-byte views fold stack addresses and reach1148/nd55.
 * Float declaration order reachesnd44; reading the actual position.y subobject
 * at its source point reachesnd31. All remaining differences are this cycle:
 *  generated edgeA=s3,edgeB=s2,edgeG=s6,edgeR=s7,count=fp;
 *  retail edgeA=s2,edgeB=s6,edgeG=s7,edgeR=fp,count=s3.
 * Signed/unsigned promoted colors, cast/halfword loop count, declaration moves
 * and while-loop spelling tie. Positive assertion form adds one difference;
 * early count snapshot and propagation-off regress. No padding or binding.
 * 
 * ABI is shared Vec2f position,depth,packed32 center/edge colors,radius,angle,
 * full u32 segments,xscale,yscale,mode. The loop and assertion use low16 count;
 * the angle divisor uses all32 segment bits. Preserve102 rows of16 floats
 * (0x1980 bytes),the previous-row reciprocal store,and late callback/global
 * reloads. Only fields written by retail are initialized. Unsupported counts
 * and unwritten vertex fields are not silently normalized or filled.
 * GP -7E20 is2*pi (40C90FDB); GP -5418 is the64-bit render flag word.
 * The reconstruction has compiler/relocation evidence only; no radial geometry
 * runtime or PS2 graphical presentation claim is made.
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
