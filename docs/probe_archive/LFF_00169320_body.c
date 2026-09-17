/* Floor for func_00169320 (retail 0x00169320).
 * Owner src/Kosaka/Field/k_fldFrame.c marker // FUN_00169320. PRODUCTION REMAINS ASM.
 *
 * Target: src/Kosaka/Field/k_fldFrame.c, func_00169320, retail 0x00169320, window 1120B.
 * Candidate: docs/probe_archive/LFF_00169320_body.c (this file).
 * Compiler: MWCCPS2 3.0.1 b210, -O2, no extra scoped pragma for this candidate
 *   (scoped opt_propagation off tested, no change; opt_common_subs off regresses 155 -> 261).
 * Commands run:
 *   python3 tools/probe_variants.py src/Kosaka/Field/k_fldFrame.c func_00169320 --candidate NAME=PATH
 *   python3 tools/fnalign.py src/Kosaka/Field/k_fldFrame.c func_00169320 --candidate PATH
 *   python3 tools/verify.py src/Kosaka/Field/k_fldFrame.c
 * Instruction result: obj 1112B, window 1120B (8B retail zero tail), differing words (reloc-masked) 155.
 *   Prior LFF archive scored 268; this body scores 155 with 278/278 instructions.
 *   Three jal sites (func_00168ec0, func_00169200, func_003e4180) resolve; frame 0x90 exact.
 * Semantic review: point/triangle/context ABI is (RwV3d* point, void* unused, RwV3d* triangle, u8* context)
 *   matching retail moves $s3=$a0, $s2=$a2, $s1=$a3 with $a1 unused. Triangle is vector at +0x0
 *   with vertex pointers at +0x1C and normal via *(+0x1C); projection is dot(normal,vec)-dot(point,vec)
 *   with projected = vec*projection + point. Inside (func_00168ec0 != 0) stores projected with
 *   distance = fabsf(projection) (needs extern f32 fabsf(f32); undeclared fabsf emits a call).
 *   Outside loops 3 edges via func_00169200(&edgePoint,&projected,...) with delta = point-edgePoint
 *   and edgedist = func_003e4180(&delta) kept as a separate live range (merging regresses to 160).
 *   Retail store asymmetry reproduced: new entries store projected (0x80), existing store edgePoint
 *   (0x70); prior archive stored edgePoint for both and left second-path distance stale (fabs reuse).
 *   Context is count at +0xB04, fractions at +0x600+4*i, records at 12*i with triangle id at +0x300.
 *   Residual: index in $v0 vs $a0 (count $a0 vs $v1), distance $f2 vs $f3, batched vs interleaved
 *   12B record lwc1/swc1. Tried: single-distance merge (160), decl index/count swap (155, neutral),
 *   nested-if search (228), for-loop search (155, neutral), aggregate projected stores (154, kept scalar
 *   for consistency), prop/common pragmas (no gain). Next hypothesis: integer temp allocation and
 *   FPR coloring for the search loop as a small declaration-order family, not broader sweeps.
 *   Consumer tests: not run (host cannot execute EE MAC/abs.s semantics); EE/VU behavior uncovered.
 *   TU link eligibility and retail image identity: unverified (no link run; production stays ASM).
 */

void* func_00169320(RwV3d* point, void* unused, RwV3d* triangle, u8* context)
{
    extern f32 fabsf(f32 x);
    extern s32 func_00168ec0(void *arg0, void *arg1, void *arg2);
    extern f32 func_003e4180(f32 *vec);
    typedef struct FldFrameTriangle
    {
        RwV3d vector;
        u8 gap[0x10];
        RwV3d* normal;
    } FldFrameTriangle;
    FldFrameTriangle* triangleData;
    RwV3d projected;
    RwV3d edgePoint;
    RwV3d delta;
    RwV3d* normal;
    f32 projection;
    f32 distance;
    f32 edgedist;
    f32* record;
    s32 count;
    s32 index;
    f32* fraction;
    s32 i;
    f32 tx;
    f32 ty;
    f32 tz;
    triangleData = (FldFrameTriangle*)triangle;
    ty = triangleData->vector.y;
    tx = triangleData->vector.x;
    tz = triangleData->vector.z;
    normal = triangleData->normal;
    projection = normal->x * tx + normal->y * ty + normal->z * tz - (point->x * tx + point->y * ty + point->z * tz);
    projected.x = tx * projection;
    projected.y = ty * projection;
    projected.z = tz * projection;
    projected.x += point->x;
    projected.y += point->y;
    projected.z += point->z;
    if (func_00168ec0(&projected, (u8*)triangle + 0x1c, triangle) != 0)
    {
        distance = fabsf(projection);
        index = 0;
        count = *(s32*)(context + 0xb04);
        while (index < count)
        {
            record = (f32*)(context + 12 * index);
            if (record[192] == triangle->x && record[193] == triangle->y && record[194] == triangle->z)
                break;
            index++;
        }
        if (index == count)
            index = -1;
        if (index < 0)
        {
            fraction = (f32*)(context + 4 * count + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * count);
                record[0] = projected.x;
                record[1] = projected.y;
                record[2] = projected.z;
                record = (f32*)(context + 12 * *(s32*)(context + 0xb04));
                record[192] = triangle->x;
                record[193] = triangle->y;
                record[194] = triangle->z;
                fraction = (f32*)(context + 4 * *(s32*)(context + 0xb04) + 0x600);
                *fraction = distance;
                (*(s32*)(context + 0xb04))++;
            }
        }
        else
        {
            fraction = (f32*)(context + 4 * index + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * index);
                record[0] = projected.x;
                record[1] = projected.y;
                record[2] = projected.z;
                record[192] = triangle->x;
                record[193] = triangle->y;
                record[194] = triangle->z;
                *fraction = distance;
            }
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            func_00169200(&edgePoint, &projected, *(RwV3d**)((u8*)triangle + 0x1c + 4 * i), *(RwV3d**)((u8*)triangle + 0x1c + 4 * ((i + 1) % 3)));
            delta.x = point->x - edgePoint.x;
            delta.y = point->y - edgePoint.y;
            delta.z = point->z - edgePoint.z;
            edgedist = func_003e4180((f32*)&delta);
            index = 0;
            count = *(s32*)(context + 0xb04);
            while (index < count)
            {
                record = (f32*)(context + 12 * index);
                if (record[192] == triangle->x && record[193] == triangle->y && record[194] == triangle->z)
                    break;
                index++;
            }
            if (index == count)
                index = -1;
            if (index < 0)
            {
                fraction = (f32*)(context + 4 * count + 0x600);
                if (edgedist < *fraction)
                {
                    record = (f32*)(context + 12 * count);
                    record[0] = projected.x;
                    record[1] = projected.y;
                    record[2] = projected.z;
                    record = (f32*)(context + 12 * *(s32*)(context + 0xb04));
                    record[192] = triangle->x;
                    record[193] = triangle->y;
                    record[194] = triangle->z;
                    fraction = (f32*)(context + 4 * *(s32*)(context + 0xb04) + 0x600);
                    *fraction = edgedist;
                    (*(s32*)(context + 0xb04))++;
                }
            }
            else
            {
                fraction = (f32*)(context + 4 * index + 0x600);
                if (edgedist < *fraction)
                {
                    record = (f32*)(context + 12 * index);
                    record[0] = edgePoint.x;
                    record[1] = edgePoint.y;
                    record[2] = edgePoint.z;
                    record[192] = triangle->x;
                    record[193] = triangle->y;
                    record[194] = triangle->z;
                    *fraction = edgedist;
                }
            }
        }
    }
    return triangle;
}
