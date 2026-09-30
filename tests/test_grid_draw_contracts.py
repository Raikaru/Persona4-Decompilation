"""Native32 oracle for the grid/ring initializer and draw-queue callback.

The active body, complete vertex/work types and raster provider are extracted
unchanged. An independent raw-offset model checks all geometry, queue nodes,
opaque-call trace and state, including defined callback mutations.
"""
from pathlib import Path
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants
OWNER = ROOT / "src/promoted/code1_0018.c"
FIXTURE = ROOT / "tests/grid_draw_fixture.c.in"
RASTER_OWNER = ROOT / "src/rw/basky.c"

def target_body():
    source = OWNER.read_text(encoding="utf-8")
    start, end = probe_variants.region_for(source, "FUN_00185850", "func_00185850")
    return source[start:end]

def helper_types():
    source = OWNER.read_text(encoding="utf-8")
    start = source.index("typedef struct {", source.index("/* Sky2's complete"))
    end = source.index("} GridDrawWork;", start) + len("} GridDrawWork;")
    return source[start:end]

def raster_body():
    source = RASTER_OWNER.read_text(encoding="utf-8")
    start, end = probe_variants.region_for(source, "FUN_00401B80", "func_00401b80")
    return source[start:end]

def fixture_source(body=None):
    source = FIXTURE.read_text(encoding="utf-8")
    source = source.replace("/* @ACTUAL_RASTER_PROVIDER@ */", raster_body())
    source = source.replace("/* @ACTUAL_TYPES@ */", helper_types())
    source = source.replace("/* @ACTUAL_BODY@ */", target_body() if body is None else body)
    return RUNTIME_C + source + ENTRY_C

MUTATIONS = {'blocked_guard': ['if (work->blocked != 0)', 'if (work->blocked == 0)', 1, 0],
 'initial_state_dispatch': ['case 0:', 'case 3:', 1, 0],
 'draw_state_dispatch': ['case 1:', 'case 2:', 1, 0],
 'outer_texture': ['(const char *)D_005F1DC0', '(const char *)D_005F1DE0', 1, 0],
 'texture_destination': ['work->textures[0] =', 'work->textures[1] =', 1, 0],
 'grid_row_count': ['index < 7', 'index < 6', 2, 1],
 'grid_column_count': ['while (column < 10)', 'while (column < 9)', 1, 0],
 'grid_right_edge': ['(column + 1) * 0x40', '(column + 2) * 0x40', 1, 0],
 'reciprocal_depth': ['0.001f', '0.002f', 22, 0],
 'vertex_depth': ['work->grid[index][column][0].z = 1000.0f;',
                  'work->grid[index][column][0].z = 999.0f;',
                  1,
                  0],
 'grid_opacity': ['work->grid[index][column][0].alpha = 64.0f;',
                  'work->grid[index][column][0].alpha = 63.0f;',
                  1,
                  0],
 'random_corner_mask': ['randomValue & 3', 'randomValue & 1', 1, 0],
 'strip_count': ['index < 0xe', 'index < 0xd', 2, 0],
 'strip_uv': ['work->bands[index][column][1].u = 1.0f;',
              'work->bands[index][column][1].u = 0.75f;',
              1,
              0],
 'ring_vertex_count': ['index < 0x42', 'index < 0x40', 3, 0],
 'outer_ring_radius': ['cosf(value2) * 850.0f', 'cosf(value2) * 851.0f', 3, 0],
 'inner_ring_radius': ['450.0f * cosf(value2)', '451.0f * cosf(value2)', 2, 0],
 'middle_ring_radius': ['500.0f * cosf(value2)', '501.0f * cosf(value2)', 1, 0],
 'ring_center_y': ['0.5f + 224.0f', '0.5f + 225.0f', 6, 0],
 'angle_direction': ['value2 = value2 + fGpffff84d4;', 'value2 = value2 - fGpffff84d4;', 3, 0],
 'ring_restart_angle': ['value2 = 0.0f;', 'value2 = 0.125f;', 3, 1],
 'overlay_opacity': ['work->overlay[0].alpha = 96.0f;', 'work->overlay[0].alpha = 95.0f;', 1, 0],
 'raster_half_pixel': ['0.5f / (float)*(int *)', '0.25f / (float)*(int *)', 2, 0],
 'overlay_inset_sign': ['work->uvValues[2] + work->uvValues[1]',
                        'work->uvValues[2] - work->uvValues[1]',
                        2,
                        1],
 'advance_state': ['work->state = work->state + 1;', 'work->state = work->state + 2;', 1, 0],
 'primitive_kind': ['func_00461390(D_00794930,4,work->cover,4)',
                    'func_00461390(D_00794930,3,work->cover,4)',
                    2,
                    1],
 'ring_draw_count': ['func_00461390(D_00794930,4,work->rings[2],0x42)',
                     'func_00461390(D_00794930,4,work->rings[2],0x40)',
                     1,
                     0],
 'before_callback': ['*(void (**)(void))(node + 8) = func_00185730;',
                     '*(void (**)(void))(node + 8) = func_00185830;',
                     4,
                     1],
 'after_callback_slot': ['*(void (**)(void))(node + 0xc) = func_00185830;',
                         '*(void (**)(void))(node + 8) = func_00185830;',
                         3,
                         1],
 'live_userdata_reload': ['*(GridDrawWork **)(node + 0x10) = work;',
                          '*(GridDrawWork **)(node + 0x10) = *(GridDrawWork **)(task + 0x38);',
                          5,
                          0],
 'live_grid_reload': ['func_00461390(D_00794930,4,work->grid[index][column],4)',
                      'func_00461390(D_00794930,4,(*(GridDrawWork **)(task + '
                      '0x38))->grid[index][column],4)',
                      1,
                      0],
 'toggle_normalization': ['uGpffffb314 = uGpffffb314 != 0 ^ 1;',
                          'uGpffffb314 = uGpffffb314 ^ 1;',
                          1,
                          0],
 'phase_toggle_guard': ['if (uGpffffb314 != 0)', 'if (uGpffffb314 == 0)', 1, 0],
 'corner_wrap': ['corner = 0;', 'corner = 1;', 1, 0],
 'phase_wrap': ['*phaseSlot = 0;', '*phaseSlot = 1;', 1, 0],
 'uv_table_stride': ['D_005F1DA0 + corner * 8', 'D_005F1DA0 + corner * 4', 2, 0],
 'uv_component': ['work->grid[index][column][vertex].u =',
                  'work->grid[index][column][vertex].v =',
                  1,
                  0],
 'cached_toggle': ['s32 column;', 's32 column;\n    s32 capturedToggle;', 1, 0],
 'cached_uv_table': ['s32 column;', 's32 column;\n    f32 capturedUv[8];', 1, 0],
 'outer_lookup_miss_guard': ['work->textures[0] = func_003ef650(func_003ef6d0(), (const char '
                             '*)D_005F1DC0);',
                             'work->textures[0] = func_003ef650(func_003ef6d0(), (const char '
                             '*)D_005F1DC0);\n'
                             '        if (work->textures[0] == 0) return 0;',
                             1,
                             0],
 'inner_lookup_miss_guard': ['work->textures[1] = func_003ef650(func_003ef6d0(), (const char '
                             '*)D_005F1DE0);',
                             'work->textures[1] = func_003ef650(func_003ef6d0(), (const char '
                             '*)D_005F1DE0);\n'
                             '        if (work->textures[1] == 0) return 0;',
                             1,
                             0]}

def mutated_body(name, row):
    old, new, count, limit = row
    body = target_body()
    if body.count(old) != count:
        raise AssertionError((name, body.count(old), count))
    body = body.replace(old, new, limit or -1)
    if name in ("cached_toggle", "cached_uv_table"):
        start = body.rindex("for (index = 0; index < 7; index = index + 1)")
        if name == "cached_toggle":
            body = (body[:start] + "capturedToggle = uGpffffb314;\n        "
                    + body[start:].replace("if (uGpffffb314 != 0)", "if (capturedToggle != 0)"))
        else:
            body = (body[:start] + "memcpy(capturedUv, D_005F1DA0, sizeof(capturedUv));\n        "
                    + body[start:].replace("D_005F1DA0 + corner * 8", "(u8 *)capturedUv + corner * 8"))
    return body

class GridDrawSourceContracts(unittest.TestCase):
    def test_active_layout_and_provider_contracts(self):
        source = OWNER.read_text(encoding="utf-8")
        body = target_body()
        self.assertNotIn("INCLUDE_ASM", body)
        self.assertNotIn("volatile", body)
        self.assertNotIn("__int128", body)
        self.assertIn("// FUN_00185850\n#pragma push\n#pragma opt_loop_invariants on\n"
                      "#pragma opt_lifetimes on", source)
        self.assertIn("GridDrawVertex grid[7][10][4]", helper_types())
        self.assertIn("GridDrawVertex rings[3][66]", helper_types())
        self.assertIn("extern RwTexDictionary *func_003ef6d0(void);", source)
        self.assertIn("extern RwTexture *func_003ef650(RwTexDictionary *, const char *);", source)
        self.assertNotRegex(source, r"extern\s+s32\s+func_003ef6(?:50|d0)")
        self.assertIn("extern s32 func_00401b80(void);", body)
        self.assertIn("return iGpffffb900;", raster_body())

    def test_negative_controls_target_active_source(self):
        self.assertEqual(len(MUTATIONS), 41)
        for name, row in MUTATIONS.items():
            with self.subTest(name=name):
                self.assertNotEqual(mutated_body(name, row), target_body())

class GridDrawNativeContracts(unittest.TestCase):
    def runtime(self):
        try:
            return native32_runtime()
        except Native32Unavailable as error:
            self.skipTest(str(error))

    def test_complete_geometry_queue_trace_and_state(self):
        runtime = self.runtime()
        outputs = []
        with tempfile.TemporaryDirectory(prefix="p4_grid_draw_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            for optimization in ("-O0", "-O2"):
                binary = runtime.compile(source, directory / optimization[1:], optimization,
                                         (ROOT / "include",))
                result = runtime.run(binary)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn("PASS scenarios=610", result.stdout)
                outputs.append(result.stdout)
        self.assertEqual(outputs[0], outputs[1])

    def test_semantic_negative_controls(self):
        runtime = self.runtime()
        with tempfile.TemporaryDirectory(prefix="p4_grid_draw_negative_") as directory:
            directory = Path(directory)
            for name, row in MUTATIONS.items():
                with self.subTest(name=name):
                    source = directory / (name + ".c")
                    source.write_text(fixture_source(mutated_body(name, row)), encoding="utf-8")
                    binary = runtime.compile(source, directory / name, "-O2", (ROOT / "include",))
                    result = runtime.run(binary)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)

if __name__ == "__main__":
    unittest.main()
