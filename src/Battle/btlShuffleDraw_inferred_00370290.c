/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Battle/btlShuffleDraw.c); members 00370290-00371160 */

#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_motion_internal.h"
extern void *func_003e0f80(void);
extern void RwMatrixRotate(void *, void *, f32 fparg0, s32);
extern void func_003e42a0(void *, void *, void *);
extern void func_003e0f40(void *);
extern void RwV3dNormalize(f32 *, f32 *);
extern u32 RpRandom(void);
extern void btlShuffleCalcBuildBezierTangents(u8 *points, f32 *displacement, f32 fparg0);
extern void func_003dc740(void *, void *, f32 fparg0, s32);
/* Construct the inner Bezier control points from an endpoint displacement and perpendicular tangent. */
// FUN_00370290
void btlShuffleCalcBuildBezierTangents(u8 *points, f32 *displacement, f32 tangentLength) {
    f32 first[3];
    f32 second[3];
    s8 buf[0xC];
    s8 *p;
    s32 count;
    f32 cross[3];
    f32 result[3];

    BtlShuffleBezierPoints *curve = (BtlShuffleBezierPoints *)points;

    p = buf;
    count = 0xC;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            count -= 1;
        } while (count != 0);
    }
    curve->controlA.x = curve->start.x + displacement[0];
    curve->controlA.y = curve->start.y + displacement[1];
    curve->controlA.z = curve->start.z + displacement[2];

    /* measured: typed endpoint reads reverse each endpoint/zero-buffer load pair (six instructions). */
    first[0] = ((f32 *)buf)[0] - *(f32 *)(points + 0x24);
    first[1] = ((f32 *)buf)[1] - ((f32 *)(points + 0x24))[1];
    first[2] = ((f32 *)buf)[2] - ((f32 *)(points + 0x24))[2];
    second[0] = curve->end.x - curve->start.x;
    second[1] = curve->end.y - curve->start.y;
    second[2] = curve->end.z - curve->start.z;
    RwV3dNormalize(&first[0], &first[0]);
    RwV3dNormalize(&second[0], &second[0]);

    cross[0] = second[1] * first[2] - second[2] * first[1];
    cross[1] = second[2] * first[0] - second[0] * first[2];
    cross[2] = second[0] * first[1] - second[1] * first[0];
    result[0] = cross[1] * first[2] - cross[2] * first[1];
    result[1] = cross[2] * first[0] - cross[0] * first[2];
    result[2] = cross[0] * first[1] - cross[1] * first[0];

    result[0] *= tangentLength;
    result[1] *= tangentLength;
    result[2] *= tangentLength;

    curve->controlB.x = curve->end.x + result[0];
    curve->controlB.y = curve->end.y + result[1];
    curve->controlB.z = curve->end.z + result[2];
}

/* Seed a 180-frame wandering position curve around the current output; preserve the asymmetric random scaling. */
// FUN_00370410
void btlShuffleCalcInitMotion(u8 *state) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        f32 params[3];
        u32 pad;
        f32 random[3];
    } work;
    u32 value;
    f32 randomValue;
    f32 scale;

    BtlShuffleBezierMotion *curve = (BtlShuffleBezierMotion *)state;

    *(s32 *)&curve->duration = 0x43340000;
    *(struct Vec3 *)&curve->origin = *(struct Vec3 *)&curve->output;
    curve->spread = 10.0f;
    curve->tangentLength = 10.0f;
    *(s32 *)&curve->scale = 0x3F800000;
    work.random[0] = 0.0f;
    work.random[1] = 0.0f;
    work.random[2] = 0.0f;
    *(struct Vec3 *)&curve->points.start = *(struct Vec3 *)work.random;

    scale = curve->spread;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[0] = (scale / 2.0f + 0.0f) -
                     scale * (randomValue / 4096.0f);

    scale = curve->spread;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[1] = (scale / 2.0f + 0.0f) -
                     (scale * (randomValue / 4096.0f)) / 4096.0f;

    scale = curve->spread;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[2] = (scale / 2.0f + 0.0f) -
                     (scale * (randomValue / 4096.0f)) / 4096.0f;

    *(struct Vec3 *)&curve->points.end = *(struct Vec3 *)work.random;
    work.params[0] = 0.0f;
    work.params[1] = 0.0f;
    work.params[2] = curve->tangentLength;
    btlShuffleCalcBuildBezierTangents(state + 0x24, work.params, work.params[2]);
}

/* Advance the wandering cubic position curve, extending its tangent when a segment ends. */
// FUN_00370640
void btlShuffleCalcStepWanderMotion(u8 *state) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        f32 params[3];
        u32 pad;
        f32 random[3];
    } work;
    u32 value;
    f32 randomValue;
    f32 scale;
    f32 t;
    f32 inverseT;

    BtlShuffleBezierMotion *curve = (BtlShuffleBezierMotion *)state;

    t = (f32)(curve->frame += 1) /
        curve->duration;
    if ((f32)curve->frame >= curve->duration) {
        work.random[0] = curve->points.controlB.x - curve->points.end.x;
        work.random[1] = curve->points.controlB.y - curve->points.end.y;
        work.random[2] = curve->points.controlB.z - curve->points.end.z;
        work.params[0] = -work.random[0];
        work.params[1] = -work.random[1];
        work.params[2] = -work.random[2];
        *(struct Vec3 *)&curve->points.start = *(struct Vec3 *)&curve->points.end;

        scale = curve->spread;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        work.random[0] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        scale = curve->spread;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        work.random[1] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        scale = curve->spread;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        work.random[2] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        *(struct Vec3 *)&curve->points.end = *(struct Vec3 *)work.random;
        btlShuffleCalcBuildBezierTangents(state + 0x24, work.params, curve->tangentLength);
        curve->frame = 0;
        t = 0.0f;
    }
    inverseT = 1.0f - t;
    curve->output.x =
        inverseT * (inverseT *
                       (curve->points.start.x * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.x * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.x * t)) +
        t * (t * (curve->points.end.x * t));
    curve->output.y =
        inverseT * (inverseT *
                       (curve->points.start.y * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.y * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.y * t)) +
        t * (t * (curve->points.end.y * t));
    curve->output.z =
        inverseT * (inverseT *
                       (curve->points.start.z * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.z * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.z * t)) +
        t * (t * (curve->points.end.z * t));
    curve->output.x *= curve->scale;
    curve->output.y *= curve->scale;
    curve->output.z *= curve->scale;
    curve->output.x += curve->origin.x;
    curve->output.y += curve->origin.y;
    curve->output.z += curve->origin.z;
}

/* Seed a 180-frame wandering Euler curve around the current quaternion. */
// FUN_00370A80
void btlShuffleCalcInitRotation(u8 *state) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct {
        f32 params[3];
        u32 pad;
        f32 random[3];
    } work;
    u32 value;
    f32 randomValue;
    f32 scale;

    BtlShuffleBezierRotation *curve = (BtlShuffleBezierRotation *)state;

    curve->duration = 0xB4;
    *(struct Vec4 *)&curve->origin = *(struct Vec4 *)&curve->output;
    curve->spread.x = 5.0f;
    curve->spread.y = 15.0f;
    curve->spread.z = 15.0f;
    *(s32 *)&curve->tangentLength = 0x3F800000;
    *(s32 *)&curve->scale = 0x3F800000;
    work.random[0] = 0.0f;
    work.random[1] = 0.0f;
    work.random[2] = 0.0f;
    *(struct Vec3 *)&curve->points.start = *(struct Vec3 *)work.random;

    scale = curve->spread.x;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[0] = (scale / 2.0f + 0.0f) -
                     scale * (randomValue / 4096.0f);

    scale = curve->spread.y;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[1] = (scale / 2.0f + 0.0f) -
                     scale * (randomValue / 4096.0f);

    scale = curve->spread.z;
    value = RpRandom() & 0xFFF;
    if (value >= 0) {
        randomValue = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        randomValue = (f32)(s32)value;
        randomValue += randomValue;
    }
    work.random[2] = (scale / 2.0f + 0.0f) -
                     scale * (randomValue / 4096.0f);

    *(struct Vec3 *)&curve->points.end = *(struct Vec3 *)work.random;
    work.params[0] = 0.0f;
    work.params[1] = 0.0f;
    work.params[2] = curve->tangentLength;
    btlShuffleCalcBuildBezierTangents(state + 0x28, work.params, work.params[2]);
}

/* Advance the wandering Euler curve and compose X, Y, then Z rotations onto the saved quaternion. */
// FUN_00370CD0
void btlShuffleCalcStepWanderRotation(u8 *state) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct {
        f32 rotation[4];
        s32 axis[3];
        u32 axisPad;
        struct {
            f32 params[3];
            u32 pad;
            f32 random[3];
        } work;
    } locals;
    f32 *rotation;
    f32 duration;
    f32 t;
    f32 inverseT;
    f32 x;
    f32 y;
    f32 z;

    BtlShuffleBezierRotation *curve = (BtlShuffleBezierRotation *)state;

    duration = (f32)curve->duration;
    t = (f32)(curve->frame += 1) / duration;
    if (curve->frame >= curve->duration) {
        f32 scale;
        u32 value;
        f32 randomValue;
        locals.work.random[0] = curve->points.controlB.x - curve->points.end.x;
        locals.work.random[1] = curve->points.controlB.y - curve->points.end.y;
        locals.work.random[2] = curve->points.controlB.z - curve->points.end.z;
        locals.work.params[0] = -locals.work.random[0];
        locals.work.params[1] = -locals.work.random[1];
        locals.work.params[2] = -locals.work.random[2];
        *(struct Vec3 *)&curve->points.start = *(struct Vec3 *)&curve->points.end;

        scale = curve->spread.x;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        locals.work.random[0] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        scale = curve->spread.y;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        locals.work.random[1] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        scale = curve->spread.z;
        value = RpRandom() & 0xFFF;
        if (value >= 0) {
            randomValue = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            randomValue = (f32)(s32)value;
            randomValue += randomValue;
        }
        locals.work.random[2] = (scale / 2.0f + 0.0f) -
                         scale * (randomValue / 4096.0f);

        *(struct Vec3 *)&curve->points.end = *(struct Vec3 *)locals.work.random;
        btlShuffleCalcBuildBezierTangents(state + 0x28, locals.work.params, curve->tangentLength);
        curve->frame = 0;
        t = 0.0f;
    }

    inverseT = 1.0f - t;
    x = inverseT * (inverseT *
                       (curve->points.start.x * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.x * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.x * t)) +
        t * (t * (curve->points.end.x * t));
    y = inverseT * (inverseT *
                       (curve->points.start.y * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.y * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.y * t)) +
        t * (t * (curve->points.end.y * t));
    z = inverseT * (inverseT *
                       (curve->points.start.z * inverseT)) +
        inverseT * (inverseT *
                       (3.0f * curve->points.controlA.z * t)) +
        inverseT * (t * (3.0f * curve->points.controlB.z * t)) +
        t * (t * (curve->points.end.z * t));

    x *= curve->scale;
    y *= curve->scale;
    z *= curve->scale;
    rotation = locals.rotation;
    *(struct Vec4 *)rotation = *(struct Vec4 *)&curve->origin;
    locals.axis[0] = 0x3F800000;
    locals.axis[1] = 0;
    locals.axis[2] = 0;
    func_003dc740(rotation, locals.axis, x, 2);
    locals.axis[0] = 0;
    locals.axis[1] = 0x3F800000;
    locals.axis[2] = 0;
    func_003dc740(rotation, locals.axis, y, 2);
    locals.axis[0] = 0;
    locals.axis[1] = 0;
    locals.axis[2] = 0x3F800000;
    func_003dc740(rotation, locals.axis, z, 2);
    *(struct Vec4 *)&curve->output = *(struct Vec4 *)locals.rotation;
}

/* Rotate a point about a center using an axis-angle matrix, then restore the center translation. */
// FUN_00371160
void btlShuffleCalcRotatePointAroundAxis(u8 *center, u8 *axis, u8 *point, f32 angle, u8 *output) {
    f32 relativePoint[3];
    void *matrix;

    RwV3d *centerVector = (RwV3d *)center;
    RwV3d *pointVector = (RwV3d *)point;
    RwV3d *outputVector = (RwV3d *)output;

    matrix = func_003e0f80();
    relativePoint[0] = pointVector->x - centerVector->x;
    relativePoint[1] = pointVector->y - centerVector->y;
    relativePoint[2] = pointVector->z - centerVector->z;
    RwMatrixRotate(matrix, axis, angle, 0);
    func_003e42a0(output, relativePoint, matrix);
    outputVector->x += centerVector->x;
    outputVector->y += centerVector->y;
    outputVector->z += centerVector->z;
    func_003e0f40(matrix);
}
