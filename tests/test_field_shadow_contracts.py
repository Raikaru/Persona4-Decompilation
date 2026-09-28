"""Check the shadow providers against their shared callback ABI and real records.

The runtime fixture includes the production owner unchanged and executes its
world, atomic, bounds, and iterator callbacks with real 32-bit pointers. Separate
signature checks require every complete definition to agree with the shared ABI.
"""
from __future__ import annotations

from pathlib import Path
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q  # noqa: E402
import verify as V  # noqa: E402

OWNER = ROOT / "src/Kosaka/k_spipe.c"
INTERFACES = {
    "func_00179130": "void *(*)(void *, void *)",
    "func_00179f70": "void *(*)(void *, void *)",
    "func_001791d0": "RwWorldTriangleCallback",
    "func_00179860": "RwAtomicTriangleCallback",
}


def signature_fixture(owner: Path | None = None) -> str:
    owner = owner or OWNER
    source = RUNTIME_C + '''
#include "field_shadow_internal.h"
#include "rw_collision_internal.h"
#pragma clang diagnostic error "-Wstrict-prototypes"
'''
    markers = {marker["name"]: marker for marker in V.scan_markers(owner)}
    bodies = Q.function_bodies(owner)
    for name, expected in INTERFACES.items():
        if markers[name].get("asm") or name not in bodies:
            raise AssertionError(f"{name}: requires an active complete provider definition")
        body = bodies[name][1]
        code = "\n".join(V.sanitize_c_lines(body.splitlines()))
        opening = code.find("{")
        if opening < 0:
            raise AssertionError(f"{name}: production definition has no opening brace")
        signature = body[:opening].strip()
        source += (
            f'_Static_assert(__builtin_types_compatible_p(__typeof__(&{name}), {expected}),\n'
            f'               "{name}: incompatible shared declaration");\n'
            f"#define {name} definition_{name}\n{signature};\n#undef {name}\n"
            f'_Static_assert(__builtin_types_compatible_p(__typeof__(&definition_{name}), {expected}),\n'
            f'               "{name}: incompatible production definition");\n'
        )
    return source + "int main(void) { return 0; }\n" + ENTRY_C


RUNTIME_FIXTURE = r'''
struct RpAtomic { u32 identity; void *frame; };
struct RpIntersection { f32 payload[6]; s32 type; };
struct RpWorldSector { u32 identity; };
struct RpCollisionTriangle {
    RwV3d normal;
    RwV3d point;
    s32 index;
    RwV3d *vertices[3];
};
typedef struct ShadowVertex {
    RwV3d position;
    u8 color[4];
    u8 normal[12];
    f32 u, v;
} ShadowVertex;
struct FldShadowProjectionWork {
    ShadowVertex vertices[600];
    u32 count, triangles;
    u8 reserved[8];
    RwV3d direction;
    u32 padding;
    f32 matrix[16];
    u8 alpha, alphaPadding[3];
    s32 attenuation, flushCount;
};
_Static_assert(sizeof(ShadowVertex) == 0x24, "shadow vertex stride");
_Static_assert(__builtin_offsetof(struct RpCollisionTriangle, vertices) == 0x1c, "triangle vertices");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, count) == 0x5460, "vertex count");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, direction) == 0x5470, "projection direction");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, matrix) == 0x5480, "projection matrix");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, alpha) == 0x54c0, "projection alpha");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, attenuation) == 0x54c4, "attenuation switch");
_Static_assert(__builtin_offsetof(FldShadowProjectionWork, flushCount) == 0x54c8, "flushed batches");
_Static_assert(sizeof(FldShadowBoundsAccum) == 0x18, "caller-owned bounds record");
_Static_assert(__builtin_offsetof(FldShadowAtomicContext, work) == 4, "atomic work pointer");
_Static_assert(__builtin_offsetof(FldShadowAtomicContext, atomic) == 8, "current atomic pointer");

static unsigned scenario, totalCases, transformCalls, flushCalls, renderCalls, endCalls;
static unsigned sphereCalls, atomicCalls, useAtomic, skinCalls, frameCalls;
static f32 skinMatrix[16];
static u32 frameToken;
static s32 flushSucceeds;
static FldShadowProjectionWork work, workBefore;
static RwV3d projected[3];
static RwV3d vertices[3] = {{10.0f, 20.0f, 30.0f}, {11.0f, 21.0f, 31.0f}, {12.0f, 22.0f, 32.0f}};
static struct RpCollisionTriangle triangle;
static struct RpIntersection intersection;
static struct RpWorldSector sector;
static struct RpAtomic atomics[4] = {{1}, {2}, {3}, {4}};
static struct RpAtomic *expectedAtomic;
static FldShadowAtomicContext atomicContext;
static RwSphere sphere;
#define CHECK(expression) do { if (!(expression)) native32_failure(__LINE__, scenario, #expression); } while (0)

RwSphere *func_003bfae0(void *atomic) {
    CHECK(atomic == expectedAtomic);
    ++sphereCalls;
    return &sphere;
}
struct RwMatrixTag *func_003e9700(RwFrame *frame) {
    CHECK((void *)frame == &frameToken);
    ++frameCalls;
    return (struct RwMatrixTag *)skinMatrix;
}
RwV3d *func_003e42e0(RwV3d *destination, const RwV3d *source,
                    s32 count, const struct RwMatrixTag *matrix) {
    const RwV3d *input = source;
    if (count == 1) {
        CHECK((const void *)matrix == skinMatrix);
        CHECK(memcmp(input, &vertices[skinCalls % 3], sizeof(RwV3d)) == 0);
        memcpy(destination, input, sizeof(RwV3d));
        ++skinCalls;
        return destination;
    }
    CHECK(count == 3 && (const void *)matrix == work.matrix);
    for (unsigned i = 0; i < 3; ++i)
        CHECK(memcmp(&input[i], &vertices[i], sizeof(RwV3d)) == 0);
    memcpy(destination, projected, sizeof(projected));
    ++transformCalls;
    return destination;
}
void *func_00410420(struct _RxObjSpace3DVertex *data, u32 count,
                   struct RwMatrixTag *matrix, u32 flags) {
    CHECK((void *)data == &work && count == workBefore.count);
    CHECK(matrix == 0 && flags == 0x19);
    ++flushCalls;
    return flushSucceeds ? data : NULL;
}
s32 func_004106a0(enum RwPrimitiveType primitive) {
    CHECK(primitive == rwPRIMTYPETRILIST);
    ++renderCalls;
    return 1;
}
s32 func_004104d0(void) { ++endCalls; return 1; }
void *func_003efd20(RwCamera *camera, RwFrame *frame) { (void)frame; return camera; }
void *func_003e9390(void *frame) { return frame; }
void *func_003ec330(void *raster) { return raster; }
void *func_003e8440(void *camera) { return camera; }

struct RpAtomic *func_00394e70(struct RpAtomic *atomic, struct RpIntersection *query,
        RwAtomicTriangleCallback callback, void *data) {
    CHECK(atomic == expectedAtomic && query == &intersection);
    CHECK(callback == func_00179860 && data == &atomicContext);
    ++atomicCalls;
    CHECK(callback(query, &triangle, 37.75f, data) == &triangle);
    atomicContext.atomic = &atomics[3];
    return NULL;
}

static void world_case(unsigned kind) {
    unsigned startCount = kind == 9 ? 597 : kind == 10 ? 600 : kind == 11 ? 598 : 0;
    unsigned accepted = kind >= 6;
    unsigned flushed = kind >= 10;
    unsigned outputIndex = flushed ? 0 : startCount;
    scenario = kind;
    memset(&work, 0xa5, sizeof(work));
    memset(&triangle, 0, sizeof(triangle));
    work.count = startCount;
    work.flushCount = 7;
    work.attenuation = kind == 8;
    work.alpha = kind == 8 ? 200 : 225;
    work.direction = (RwV3d){0.0f, 0.0f, 1.0f};
    triangle.normal = (RwV3d){0.0f, 0.0f, kind == 0 ? 1.0f : -1.0f};
    for (unsigned i = 0; i < 3; ++i) {
        triangle.vertices[i] = &vertices[i];
        projected[i] = (RwV3d){0.25f * (i + 1), 0.5f, 0.5f};
        if (kind == 1) projected[i].z = -0.5f;
        if (kind == 2) projected[i].x = -0.5f;
        if (kind == 3) projected[i].x = 1.5f;
        if (kind == 4) projected[i].y = -0.5f;
        if (kind == 5) projected[i].y = 1.5f;
        if (kind == 7) projected[i] = (RwV3d){0.0f, 1.0f, 0.0f};
    }
    if (kind == 8) { projected[1].z = 2.0f; projected[2].z = 0.0f; }
    flushSucceeds = kind != 11;
    transformCalls = flushCalls = renderCalls = endCalls = skinCalls = frameCalls = 0;
    workBefore = work;
    if (useAtomic) {
        RwAtomicTriangleCallback callback = func_00179860;
        atomicContext.work = &work;
        atomicContext.atomic = &atomics[0];
        atomics[0].frame = &frameToken;
        CHECK(callback(&intersection, &triangle, 19.25f, &atomicContext) == &triangle);
    } else {
        RwWorldTriangleCallback callback = func_001791d0;
        CHECK(callback(&intersection, &sector, &triangle, 19.25f, &work) == &triangle);
    }
    CHECK(skinCalls == (useAtomic ? 3u : 0u) && frameCalls == skinCalls);
    CHECK(transformCalls == (kind != 0));
    CHECK(flushCalls == flushed);
    CHECK(renderCalls == (flushed && flushSucceeds));
    CHECK(endCalls == renderCalls);
    if (!accepted) {
        CHECK(memcmp(&work, &workBefore, sizeof(work)) == 0);
    } else {
        CHECK(work.count == outputIndex + 3 && work.flushCount == 7 + (s32)flushed);
        CHECK(work.triangles == workBefore.triangles);
        for (unsigned i = 0; i < 600; ++i) {
            if (i < outputIndex || i >= outputIndex + 3)
                CHECK(memcmp(&work.vertices[i], &workBefore.vertices[i], sizeof(ShadowVertex)) == 0);
        }
        for (unsigned i = 0; i < 3; ++i) {
            ShadowVertex *vertex = &work.vertices[outputIndex + i];
            unsigned alpha = kind == 8 ? (i == 0 ? 150 : i == 1 ? 0 : 200) : 225;
            CHECK(vertex->position.x == vertices[i].x && vertex->position.y == vertices[i].y);
            CHECK(vertex->position.z == vertices[i].z - 1.5f);
            CHECK(vertex->u == projected[i].x && vertex->v == projected[i].y);
            for (unsigned channel = 0; channel < 4; ++channel) CHECK(vertex->color[channel] == alpha);
            for (unsigned byte = 0; byte < 12; ++byte) CHECK(vertex->normal[byte] == 0xa5);
        }
    }
    ++totalCases;
}

static void bounds_cases(void) {
    const f32 radii[4] = {3.0f, 1.0f, 4.0f, 10.0f};
    const f32 sums[4] = {3.0f, 4.0f, 8.0f, 18.0f};
    FldShadowBoundsAccum accum = {{0.0f, 0.0f, 0.0f}, 0.0f, 0, NULL};
    void *(*callback)(void *, void *) = func_00179130;
    for (unsigned i = 0; i < 4; ++i) {
        scenario = 20 + i;
        expectedAtomic = &atomics[i];
        sphere.center = (RwV3d){(f32)i, (f32)i + 1.0f, (f32)i + 2.0f};
        sphere.radius = radii[i];
        sphereCalls = 0;
        CHECK(callback(expectedAtomic, &accum) == expectedAtomic);
        CHECK(accum.radius == sums[i] && accum.count == (s32)i + 1);
        CHECK(accum.largestAtomic == &atomics[i == 3 ? 3 : 0]);
        CHECK(accum.center.x == (i == 3 ? 3.0f : 0.0f));
        CHECK(sphereCalls == (i == 0 || i == 3 ? 3 : 2));
        ++totalCases;
    }
}

static void atomic_cases(void) {
    void *(*callback)(void *, void *) = func_00179f70;
    atomicContext.intersection = &intersection;
    atomicContext.work = &work;
    work.triangles = 0;
    work.count = 0;
    work.flushCount = 0;
    work.attenuation = 0;
    work.alpha = 200;
    triangle.normal = (RwV3d){0.0f, 0.0f, -1.0f};
    for (unsigned i = 0; i < 2; ++i) {
        scenario = 30 + i;
        expectedAtomic = &atomics[i];
        expectedAtomic->frame = &frameToken;
        CHECK(callback(expectedAtomic, &atomicContext) == expectedAtomic);
        CHECK(atomicContext.atomic == &atomics[3]);
        CHECK(work.count == (i + 1) * 3 && atomicCalls == i + 1);
        CHECK(work.triangles == 0 && work.flushCount == 0);
        ++totalCases;
    }
}

int main(void) {
    for (unsigned kind = 0; kind < 12; ++kind) world_case(kind);
    useAtomic = 1;
    for (unsigned kind = 0; kind < 12; ++kind) world_case(kind);
    bounds_cases();
    atomic_cases();
    CHECK(totalCases == 30);
    native32_text("field_shadow_cases=30 world=12 atomic_projection=12 bounds=4 transport=2\n");
    return 0;
}
'''


def runtime_fixture(owner: Path | None = None) -> str:
    owner = owner or OWNER
    return RUNTIME_C + f'\n#include "{owner.as_posix()}"\n' + RUNTIME_FIXTURE + ENTRY_C


class FieldShadowContractTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_shared_headers_agree_with_all_provider_definitions(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_shadow_signatures_") as temporary:
            directory = Path(temporary)
            source = directory / "signatures.c"
            source.write_text(signature_fixture(), encoding="utf-8")
            executable = self.runtime.compile(source, directory / "signatures", "-O0", (ROOT / "include",))
            result = self.runtime.run(executable)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    def test_projection_bounds_and_typed_callback_transport(self) -> None:
        markers = {row["name"]: row for row in V.scan_markers(OWNER)}
        for name in ("func_00179130", "func_001791d0", "func_00179860", "func_00179f70"):
            self.assertFalse(markers[name].get("asm"), f"{name}: runtime test requires the active C body")
        with tempfile.TemporaryDirectory(prefix="p4_shadow_runtime_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(runtime_fixture(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("fixture" + level),
                                                      level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "field_shadow_cases=30 world=12 atomic_projection=12 bounds=4 transport=2\n")
                    print(level, "field-shadow", result.stdout.strip())


if __name__ == "__main__":
    unittest.main()
