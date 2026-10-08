"""Guard/source contracts and bounded host witnesses for the unmatched controller.

The host programs model individual operations; none executes the PS2 owner or
establishes whole-function equivalence. Proprietary byte gates are separate.
"""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
OWNER = ROOT / "src/Graphics/Model/mdlManager.c"
FIXTURES = ROOT / "tests/fixtures/model_controller"
sys.path.insert(0, str(ROOT / 'tools'))
import probe_variants


def controller_region(source):
    start, end = probe_variants.region_for(source, 'FUN_00471370', 'func_00471370')
    return source[start:end]


class ModelControllerSourceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        source = OWNER.read_text()
        cls.body = controller_region(source)

    def test_production_fallback_retained(self):
        self.assertTrue(self.body.lstrip().startswith("#ifdef NON_MATCHING"))
        self.assertIn('#else\nINCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);\n#endif', self.body)

    def test_internal_pragma_pop_does_not_truncate_fallback(self):
        source = """#pragma push
// FUN_00471370 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_00471370(void) { return 1; }
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);
#endif
#pragma pop
void following(void) {}
"""
        region = controller_region(source)
        self.assertTrue(region.startswith('#ifdef NON_MATCHING'))
        self.assertIn('#pragma pop\n#else\nINCLUDE_ASM("asm/nonmatchings/mdlManager", func_00471370);\n#endif', region)
        self.assertTrue(region.rstrip().endswith('#endif'))
        self.assertNotIn('following', region)

    def test_mode_snapshots_precede_node_loop(self):
        loop = self.body.index("for (iStack_420 = 0;")
        for name, mask in (("updateFrameMatrices", "0x1000"), ("concatenateParentMatrix", "0x4000")):
            declaration = f"s32 {name} = temp_v10 & {mask};"
            self.assertLess(self.body.index(declaration), loop)
            self.assertEqual(self.body.count(declaration), 1)
            self.assertIn(f"if ({name}", self.body[loop:])
        self.assertIn("temp_v10 = *puVar12;", self.body[:loop])

    def test_storage_and_callback_contracts(self):
        for contract in (
            "sizeof(RwMatrix) == 64", "offsetof(RwMatrix, flags) == 12",
            "sizeof(ControllerQuat) == 16", "sizeof(ControllerSlerpCache) == 40",
            "offsetof(ControllerSlerpCache, omega) == 32",
            "void (*pcVar2)(void *matrix, void *keyFrame);",
            "unsigned int temp_v27 [31];",
            "*(RwMatrix *)(temp_v7 + 0x10) = frameMatrix;",
            "*(RwMatrix *)(temp_v7 + 0x50) = *(const RwMatrix *)pfVar8;",
        ):
            self.assertIn(contract, self.body)

    def test_float_predicates_and_halfword_views(self):
        for contract in (
            "u16 *modelState = (u16 *)param_2;", "u16 *controller = (u16 *)param_3;",
            "const f32 x = *(f32 *)(temp_v11 + 8);",
            "const f32 w = *(f32 *)(temp_v11 + 0x14);",
            "!(temp_v20 <= 360.0f)", "!(temp_v21 <= 360.0f)",
        ):
            self.assertIn(contract, self.body)

    def test_duration_uses_float_field_and_parent_dispatch(self):
        self.assertIn("1.0f / ((float *)puVar3)[0xd]", self.body)
        self.assertIn("switch (*(unsigned int *)(uStack_430 + 8) & 3)", self.body)
        self.assertIn("case 3:\n        break;", self.body)


@unittest.skipUnless(shutil.which("cc"), "host C compiler unavailable")
class ModelControllerHostWitnessTests(unittest.TestCase):
    def test_bounded_host_witnesses(self):
        expected = {
            "value_transfer_native": {"samples": 8192, "mismatches": 0, "guards_preserved": True},
            "parent_stack_native": {"mismatches": 0, "all_16bit_flags": True},
            "angle_semantics_native": {"finite_samples": 8192, "finite_predicate_disagreements": 0,
                                       "quiet_nan_predicate_distinctions": 2},
            "animation_semantics_native": {"nonzero_tick_values": 65535, "progress_update_cases": 262140,
                                           "ordered_predicate_disagreements": 0},
            "mode_snapshot_native": {"entry_flag_values": 131072, "node_action_cases": 524288,
                                     "mismatches": 0, "simulated_external_mutation_distinctions": 262144},
        }
        with tempfile.TemporaryDirectory() as directory:
            for name, fields in expected.items():
                with self.subTest(witness=name):
                    executable = Path(directory) / name
                    subprocess.run(["cc", "-std=c99", "-O2", "-ffp-contract=off", "-fno-fast-math",
                                    str(FIXTURES / (name + ".c")), "-lm", "-o", str(executable)],
                                   check=True, capture_output=True, text=True, timeout=60)
                    result = json.loads(subprocess.check_output([str(executable)], text=True, timeout=30))
                    for key, value in fields.items():
                        self.assertEqual(result[key], value, key)
                    self.assertIn("scope", result)


if __name__ == "__main__":
    unittest.main()
