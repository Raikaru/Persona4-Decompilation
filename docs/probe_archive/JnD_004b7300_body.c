/*
 * Probe archive for func_004b7300.
 * object_size=348; retail_window=352; normalized_diff=46.
 * differing_offsets (verify first_diffs): 284,285,286,287,289,290,291,292,
 *   295,296,297,298,299,300,302,303.
 * This near miss reproduced the retail COP1 accumulator chain from plain C
 * (adda.s/madd.s); COP1 syntax was not a floor.  The residual was tail
 * register colouring/orientation and the extra base term.
 * ruled_out: COP1 inline asm/intrinsics, volatile, treating adda.s as a floor.
 */
// FUN_004B7300
f32 func_004b7300(const RuntimeDistanceWork* work, s32 index)
{
    extern f32 func_003e4180(RuntimeVec3* vector);
    s32 firstIndex;
    s32 nextIndex;
    RuntimeVec3 delta;
    f32 total;
    f32 length;
    f32 result;

    firstIndex = func_004b7800((const RuntimeWork*)work, index);
    nextIndex = func_004b7800((const RuntimeWork*)work, index + 1);
    total = 0.0f;

    delta.x = work->firstVectors[nextIndex].x - work->firstVectors[firstIndex].x;
    delta.y = work->firstVectors[nextIndex].y - work->firstVectors[firstIndex].y;
    delta.z = work->firstVectors[nextIndex].z - work->firstVectors[firstIndex].z;
    total += func_003e4180(&delta);

    delta.x = work->secondVectors[nextIndex].x - work->secondVectors[firstIndex].x;
    delta.y = work->secondVectors[nextIndex].y - work->secondVectors[firstIndex].y;
    delta.z = work->secondVectors[nextIndex].z - work->secondVectors[firstIndex].z;
    length = func_003e4180(&delta);

    result = *(f32*)((u8*)work->config[0] + 0x2C);
    return result + (total + length) * result;
}
