"""Independent native32 cursor-controller oracle with actual pure providers.

The unchanged controller and its arrow helper are extracted from the owner.
Eight real constructors/getters run unchanged; opaque state/draw boundaries
are traced and mutate valid backing objects. The model uses retail offsets
and its own grouped control flow, and compares every observable event/state.
"""
from pathlib import Path
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants

OWNER = ROOT / "src/Event/Fcl/y_fclCombineDraw.c"
FIXTURE = ROOT / "tests/fcl_cursor_fixture.c.in"
PROVIDERS = {'002B2970': 'src/promoted/code1_002b.c',
 '002B2A60': 'src/promoted/code1_002b.c',
 '002B2CB0': 'src/promoted/code1_002b.c',
 '002B2D00': 'src/promoted/code1_002b.c',
 '0034AE50': 'src/promoted/y_fclCmbBall.c',
 '002E4870': 'src/Yajima/y_list.c',
 '002E48A0': 'src/Yajima/y_list.c',
 '0010B5B0': 'src/Main/Battle/Data/datPersona.c'}


def target_body():
    source = OWNER.read_text(encoding="utf-8")
    start, end = probe_variants.region_for(source, "FUN_00321E60", "func_00321e60")
    return source[start:end]


def helper_body():
    source = OWNER.read_text(encoding="utf-8")
    start = source.index("static inline void fclShowCombineCursorArrows(")
    brace = source.index("{", start)
    depth = 1
    end = brace + 1
    while depth:
        depth += (source[end] == "{") - (source[end] == "}")
        end += 1
    return source[start:end]


def provider_bodies():
    bodies = []
    for address, relative in PROVIDERS.items():
        source = (ROOT / relative).read_text(encoding="utf-8")
        start, end = probe_variants.region_for(source, "FUN_" + address,
                                               "func_" + address.lower())
        bodies.append(source[start:end])
    return bodies


def fixture_source(body=None):
    fixture = FIXTURE.read_text(encoding="utf-8")
    fixture = fixture.replace("/* @ACTUAL_PROVIDERS@ */", "\n".join(provider_bodies()))
    fixture = fixture.replace("/* @CURSOR_BODY@ */",
                              helper_body() + "\n" + (target_body() if body is None else body))
    return RUNTIME_C + fixture + ENTRY_C


MUTATIONS = {'reset_first': ('*(s8 *)(t + 0x128) = -1;', '*(s8 *)(t + 0x128) = 0;', 1),
 'reset_second': ('*(s8 *)(t + 0x129) = -1;', '*(s8 *)(t + 0x129) = 0;', 1),
 'wide_mode_transport': ('*(s8 *)(t + 0x129), arg1);', '*(s8 *)(t + 0x129), (s8)arg1);', 1),
 'up_key': ('if (D_008C027A[0] & 0x1000)', 'if (D_008C027A[0] & 0x2000)', 1),
 'down_key': ('if (D_008C027A[0] & 0x4000)', 'if (D_008C027A[0] & 0x2000)', 1),
 'up_wrap': ('func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, (u16)func_0010b5b0() - 1, 2)',
             'func_002b2d00(*(s16 *)(t + 0x11E), 1, 0, (u16)func_0010b5b0() - 1, 1)',
             1),
 'down_wrap': ('func_002b2cb0(*(s16 *)(t + 0x11E), 1, (u16)func_0010b5b0() - 1, 0, 2)',
               'func_002b2cb0(*(s16 *)(t + 0x11E), 1, (u16)func_0010b5b0() - 1, 0, 1)',
               1),
 'confirm_guard': ('if (*(s16 *)(t + 0x11E) < *(s32 *)(func_002e4870(0) + 8))',
                   'if (*(s16 *)(t + 0x11E) <= *(s32 *)(func_002e4870(0) + 8))',
                   2),
 'choose_guard': ('} else if (D_008C024C[0] & 0x40) {\n'
                  '        if (*(s16 *)(t + 0x11E) < *(s32 *)(func_002e4870(0) + 8))',
                  '} else if (D_008C024C[0] & 0x40) {\n'
                  '        if (*(s16 *)(t + 0x11E) <= *(s32 *)(func_002e4870(0) + 8))',
                  1),
 'confirm_mode_zero_state': ('*(u8 *)(t + 1) = 0x28;', '*(u8 *)(t + 1) = 0x29;', 1),
 'confirm_mode_one_state': ('*(u8 *)(t + 1) = 0x3E;', '*(u8 *)(t + 1) = 0x3F;', 1),
 'confirm_return_state': ('*(u8 *)(t + 1) = arg2;', '*(u8 *)(t + 1) = arg3;', 1),
 'cancel_return_state': ('*(u8 *)(t + 1) = arg3;', '*(u8 *)(t + 1) = arg2;', 1),
 'cursor_arrows': ('            fclShowCombineCursorArrows(t);',
                   '            /* omitted arrows */',
                   1),
 'selection_store': ('*(s8 *)(t + 0x128) = *(s16 *)(t + 0x11E);', '*(s8 *)(t + 0x128) = 0;', 1),
 'selection_origin': ('func_002b2970(-380.0f, v->y)', 'func_002b2970(-379.0f, v->y)', 1),
 'confirm_row_id_signedness': ('*(u16 *)(func_002e48a0(0, ia) + 2)',
                               '*(s16 *)(func_002e48a0(0, ia) + 2)',
                               1),
 'cancel_row_id_signedness': ('*(u16 *)(func_002e48a0(0, jc) + 2)',
                              '*(s16 *)(func_002e48a0(0, jc) + 2)',
                              1),
 'confirm_grid_row_spacing': ('ma = ja * 23;', 'ma = ja * 22;', 1),
 'confirm_grid_column_spacing': ('ka * 23 + 0x149', 'ka * 22 + 0x149', 1),
 'first_mode_grid_row_spacing': ('mb1 = jb1 * 23;', 'mb1 = jb1 * 22;', 1),
 'first_mode_matrix_predicate': ('*(s8 *)(func_002e4870(0) + c * 12 + (u32)normalizedRow + 0x14) > '
                                 '0',
                                 '*(s8 *)(func_002e4870(0) + c * 12 + (u32)normalizedRow + 0x14) '
                                 '!= 0',
                                 1),
 'second_mode_matrix_stride': ('m = cur * 12;', 'm = cur * 11;', 1),
 'second_mode_matrix_predicate': ('if (*(s8 *)((u8 *)addOff(m, (u32)func_002e4870(0)) + kb2 + '
                                  '0x14) == 0)',
                                  'if (*(s8 *)((u8 *)addOff(m, (u32)func_002e4870(0)) + kb2 + '
                                  '0x14) <= 0)',
                                  1),
 'second_mode_selected_color': ('c21C = func_002b2a60(0x2D, 0x2D, 0x2D, 0xFF);',
                                'c21C = func_002b2a60(0x2E, 0x2D, 0x2D, 0xFF);',
                                2),
 'second_mode_zero_alpha': ('c21C = func_002b2a60(0, 0, 0x99, 0xA5);',
                            'c21C = func_002b2a60(0, 0, 0x99, 0xA4);',
                            1),
 'second_mode_nonzero_alpha': ('c21C = func_002b2a60(0x49, 0x72, 0xFF, 0xCC);',
                               'c21C = func_002b2a60(0x49, 0x72, 0xFF, 0xCD);',
                               1),
 'second_mode_alpha_component': ('alpha = c21C.c3;', 'alpha = c21C.c2;', 2),
 'second_mode_special_reset': ('*(u8 *)(func_002b6150(0x7E) + 0x47) = 0;',
                               '*(u8 *)(func_002b6150(0x7E) + 0x47) = 1;',
                               1),
 'second_mode_position': ('*(FclVec2 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 0x28)',
                          '*(FclVec2 *)(func_0034ae50(*(u8 **)(rowb2 + 0x154), (s8)kb2) + 0x2C)',
                          2),
 'cancel_position': ('*(FclVec2 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x28)',
                     'func_002b2970(0, 0)',
                     1),
 'cancel_alpha_field': ('*(u8 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x5E)',
                        '*(u8 *)(func_0034ae50(*(u8 **)(rowc + 0x154), (s8)kc) + 0x78)',
                        2),
 'cancel_reset_mode_gate': ('if ((s8)arg1 == 1)', 'if ((s8)arg1 != 0)', 1),
 'confirm_height': ('110.0f + func_0046b2f0(ha) / 2.0f', '110.0f + func_0046b2f0(ha) / 4.0f', 1),
 'cancel_height': ('110.0f + func_0046b2f0(hc) / 2.0f', '110.0f + func_0046b2f0(hc) / 4.0f', 1),
 'confirm_grid_live_alpha': ('*(u8 *)(func_0034ae50(*(u8 **)(rowa + 0x154), (s8)ka) + 0x5E)',
                             '0xFF',
                             2),
 'cached_party_capacity': ('    s32 rowCount;', '    s32 rowCount;\n    u16 capturedCapacity;', 1),
 'cached_selected_row': ('    u8 *rowb2;', '    u8 *rowb2;\n    s16 capturedSelected;', 1),
 'live_task_work_reload': ('rowb2 = t + cur * 4;', 'rowb2 = *(u8 **)(arg0 + 0x38) + cur * 4;', 1)}


def mutated_body(name, old, new, expected_count):
    body = target_body()
    count = body.count(old)
    if count != expected_count:
        raise AssertionError((name, count, expected_count))
    body = body.replace(old, new)
    if name == "cached_party_capacity":
        body = body.replace("    i = 0;",
                            "    capturedCapacity = (u16)func_0010b5b0();\n    i = 0;", 1)
        start = body.index("    i = 0;")
        body = body[:start] + body[start:].replace("(u16)func_0010b5b0()", "capturedCapacity")
    if name == "cached_selected_row":
        body = body.replace("                jb2 = 0;",
                            "                capturedSelected = *(s16 *)(t + 0x11E);\n                jb2 = 0;", 1)
        body = body.replace("if (*(s16 *)(t + 0x11E) == cur)", "if (capturedSelected == cur)")
    return body


class FclCursorSourceContracts(unittest.TestCase):
    def test_counter_snapshot_and_sound_contract(self):
        body = target_body()
        self.assertIn("cur = (s16)(u32)jb2;", body)
        self.assertIn("// FUN_00321E60\n#pragma push\n#pragma opt_lifetimes on\n"
                      "void func_00321e60(", OWNER.read_text(encoding="utf-8"))
        self.assertIn("extern s32 func_0045af60(s16, s16, s16, s16);", body)
        self.assertNotIn("INCLUDE_ASM", body)
        self.assertNotIn("volatile", body)
        self.assertEqual(len(provider_bodies()), 8)

    def test_all_negative_controls_target_active_code(self):
        self.assertEqual(len(MUTATIONS), 39)
        for name, (old, new, count) in MUTATIONS.items():
            with self.subTest(name=name):
                self.assertNotEqual(mutated_body(name, old, new, count), target_body())


class FclCursorNativeContracts(unittest.TestCase):
    def runtime(self):
        try:
            return native32_runtime()
        except Native32Unavailable as error:
            self.skipTest(str(error))

    def test_complete_observable_trace_and_state(self):
        runtime = self.runtime()
        outputs = []
        with tempfile.TemporaryDirectory(prefix="p4_fcl_cursor_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            for optimization in ("-O0", "-O2"):
                binary = runtime.compile(source, directory / optimization[1:], optimization,
                                         (ROOT / "include",))
                result = runtime.run(binary)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn("PASS scenarios=865", result.stdout)
                outputs.append(result.stdout)
        self.assertEqual(outputs[0], outputs[1])

    def test_semantic_negative_controls(self):
        runtime = self.runtime()
        with tempfile.TemporaryDirectory(prefix="p4_fcl_cursor_negative_") as directory:
            directory = Path(directory)
            for name, (old, new, count) in MUTATIONS.items():
                with self.subTest(name=name):
                    source = directory / (name + ".c")
                    source.write_text(fixture_source(mutated_body(name, old, new, count)), encoding="utf-8")
                    binary = runtime.compile(source, directory / name, "-O2", (ROOT / "include",))
                    result = runtime.run(binary)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)


if __name__ == "__main__":
    unittest.main()
