/* Fresh panel geometry recovery: func_00204690.
 * Owner src/promoted/code1_0020.c. Production ASM replaced with ordinary C.
 * Measured:916/928 bytes,nd0,15 independently resolved relocations and12 zero
 * alignment bytes. Directly resolving the15 GP/HI/LO/call relocations reproduces
 * all928 retail bytes. Same pre-existing public signature, no C caller migration.
 * 
 * Initial complete source:1016/928,nd761. Reverse byte-channel capture, a separate
 * depth result and scoped opt_loop_invariants on give916/nd109. Separate vertex
 * initialization counter and point/output views give916/nd88. Unsigned index ties.
 * Four separate quadrant cursor lifetimes close916/nd0; no source padding, inline
 * assembly, register bindings or uninitialized-value tricks are added.
 * 
 * The array is81 actual64-byte vertex records: the retail initialization loop
 * writes all81, independently supporting its capacity. Geometry supplies77 records
 * in four sweeps:table0..19,18..0,1..19,18..0. The final dispatch explicitly passes
 * primitive5,buffer,count77. D_00887310 is the existing three-argument immediate
 * render boundary; rwcore_grouped binds it to0040C0F0 and mode5 table0070C2E0+20
 * selects0040BDE0. Existing C caller00204A30 disables texture before this draw.
 * Only position,depth,reciprocal andRGBA fields are assigned; texture fields are
 * not invented or initialized. The20 two-float points are retail00626890.
 * 
 * Integrated production source passes65,536 native finite/color/callback cases
 * under GCC and Clang AddressSanitizer+UndefinedBehaviorSanitizer. The independent
 * oracle maps each of77 outputs directly to a table point and quadrant, checking
 * bit-identical geometry/depth/reciprocal and all four color channels. All65,536
 * low-halfword colors are paired with an XOR-transformed high halfword; scales
 * cover negative/zero/positive values, varied factors,depth and camera near planes.
 * 9,363 accessor-mutation cases alter globals and table values and replace the
 * draw callback: pre-call scale/depth snapshots and late point/callback reads must
 * remain correct. Unused input and camera canaries remain intact. These are
 * headless geometry/boundary checks, not PS2 graphics or non-finite FP claims.
 * 
 * Declarations below supplement the existing owner. Scoped pragmas must close
 * before the existing00204A30 opt_propagation bracket.
 */

extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern u8 *func_00457120(void);
extern void (*D_00887310[])(s32, void *, s32);

// FUN_00204690
#pragma push
#pragma opt_loop_invariants on
void func_00204690(u8 *unused, f32 scaleX, f32 scaleY, s32 color, f32 depth)
{
    f32 vertices[81][16];
    u32 alpha = ((u8 *)&color)[3];
    u32 blue = ((u8 *)&color)[2];
    u32 green = ((u8 *)&color)[1];
    u32 red = ((u8 *)&color)[0];
    f32 reciprocal;
    f32 transformedDepth;
    u32 vertex;
    u32 initialize;
    scaleX *= fGpffff82e0;
    scaleY *= fGpffff82e4;
    transformedDepth = D_008872F8[0] - depth;
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    for (initialize = 0; initialize < 81; initialize++) {
        f32 *out = vertices[initialize];
        out[2] = transformedDepth;
        out[6] = reciprocal;
        out[8] = (f32)red;
        out[9] = (f32)green;
        out[10] = (f32)blue;
        out[11] = (f32)alpha;
    }
    vertex = 0;
    vertices[0][0] = 320.0f;
    vertices[0][1] = 211.0f;
    {
        s32 i;
        for (i = 0; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 1; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    D_00887310[0](5, vertices, vertex);
}
#pragma pop
