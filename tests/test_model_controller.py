"""Guard-region parsing and bounded host witnesses for the unmatched controller.

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
FIXTURES = ROOT / "tests/fixtures/model_controller"
sys.path.insert(0, str(ROOT / 'tools'))
import probe_variants


def controller_region(source):
    start, end = probe_variants.region_for(source, 'FUN_00471370', 'func_00471370')
    return source[start:end]


class ControllerRegionTests(unittest.TestCase):
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
