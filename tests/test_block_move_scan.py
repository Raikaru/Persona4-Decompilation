import importlib.util
import os
import unittest

_SPEC = importlib.util.spec_from_file_location(
    'block_move_scan', os.path.join(os.path.dirname(__file__), '..', 'tools',
                                    'block_move_scan.py'))
bms = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(bms)


class AsymmetricPairs(unittest.TestCase):
    """Only a long run against an almost-empty one is a candidate block."""

    def test_finds_a_long_retail_run(self) -> None:
        script = [("replace", 100, 160, 100, 101)]
        self.assertEqual(bms.asymmetric_pairs(script),
                         [("retail", 60, 100, 160, 100, 101)])

    def test_finds_a_long_object_run(self) -> None:
        script = [("replace", 100, 101, 100, 180)]
        self.assertEqual(bms.asymmetric_pairs(script),
                         [("object", 80, 100, 101, 100, 180)])

    def test_balanced_replace_is_not_a_block(self) -> None:
        # A 60-for-60 replacement is a recolouring in place, not a candidate
        # move: both sides are present at the same position.
        self.assertEqual(bms.asymmetric_pairs([("replace", 0, 60, 0, 60)]), [])

    def test_short_runs_are_noise(self) -> None:
        self.assertEqual(bms.asymmetric_pairs([("replace", 0, 5, 0, 1)]), [])

    def test_longest_first(self) -> None:
        script = [("replace", 0, 20, 0, 1), ("replace", 50, 130, 50, 51)]
        self.assertEqual([p[1] for p in bms.asymmetric_pairs(script)], [80, 20])


class Verdict(unittest.TestCase):
    """The three verdicts drive opposite fixes, so the boundaries matter."""

    def test_identical_opcode_sequence_is_a_move(self) -> None:
        self.assertTrue(bms.verdict(1.0).startswith("MOVE"))

    def test_high_but_imperfect_is_a_recolour(self) -> None:
        self.assertTrue(bms.verdict(0.90).startswith("RECOLOUR"))

    def test_low_agreement_is_neither(self) -> None:
        # func_001400f0's 609-against-673 pair scores 0.677 and is genuinely
        # different code; calling that a move sends the next pass at the
        # wrong fix.
        self.assertTrue(bms.verdict(0.677).startswith("MIXED"))

    def test_boundaries_are_inclusive(self) -> None:
        self.assertTrue(bms.verdict(bms.MOVE_RATIO).startswith("MOVE"))
        self.assertTrue(bms.verdict(bms.RECOLOUR_RATIO).startswith("RECOLOUR"))

    def test_a_pair_at_the_same_offset_is_not_a_move(self) -> None:
        """func_002d8a60 scores 0.971 on a 208-against-210 pair, but the two
        ranges start at 958 and 945 - the region diverges where it stands.
        Reordering blocks there would be the wrong fix."""
        self.assertTrue(bms.verdict(0.971, displacement=13, length=208)
                        .startswith("IN-PLACE"))

    def test_a_displaced_pair_is_still_a_move(self) -> None:
        self.assertTrue(bms.verdict(0.971, displacement=600, length=208)
                        .startswith("MOVE"))

    def test_displacement_scales_with_block_length(self) -> None:
        # A 40-instruction shift is real for a 60-instruction block and noise
        # for a 600-instruction one.
        self.assertTrue(bms.verdict(1.0, displacement=40, length=60).startswith("MOVE"))
        self.assertTrue(bms.verdict(1.0, displacement=40, length=600).startswith("IN-PLACE"))



class Opcodes(unittest.TestCase):
    def test_keeps_only_the_mnemonic(self) -> None:
        self.assertEqual(bms.opcodes(["addiu $sp, $sp, -0x80", "nop"]),
                         ["addiu", "nop"])


if __name__ == '__main__':
    unittest.main()
