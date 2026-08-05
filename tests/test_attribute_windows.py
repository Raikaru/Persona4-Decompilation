from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_attr",
                                              REPO / "tools" / "attribute_windows.py")
assert SPEC is not None and SPEC.loader is not None
attr = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(attr)

#        0x100  0x200  0x300  0x400  0x500
# third    F      F      T      T      F
ADDRS = [0x100, 0x200, 0x300, 0x400, 0x500]
THIRD = [False, False, True, True, False]


class BucketTests(unittest.TestCase):
    """Only a window with third-party on BOTH sides may be called middleware.

    The whole point of the tool is to stop overstating first-party work without
    reclassifying real game code the other way, so a one-sided neighbour has to land
    in `mixed` rather than being guessed.
    """

    def test_between_two_third_party_neighbours(self) -> None:
        out = attr.bucket([0x380], ADDRS, THIRD)
        self.assertEqual(out["third_party_flanked"], [0x380])
        self.assertEqual(out["mixed"], [])

    def test_between_two_first_party_neighbours(self) -> None:
        out = attr.bucket([0x180], ADDRS, THIRD)
        self.assertEqual(out["first_party_flanked"], [0x180])

    def test_a_boundary_window_is_mixed_not_guessed(self) -> None:
        out = attr.bucket([0x280, 0x480], ADDRS, THIRD)
        self.assertEqual(sorted(out["mixed"]), [0x280, 0x480])
        self.assertEqual(out["third_party_flanked"], [])
        self.assertEqual(out["first_party_flanked"], [])

    def test_before_the_first_and_after_the_last_are_mixed(self) -> None:
        """One side has no neighbour at all, so there is nothing to conclude."""
        out = attr.bucket([0x10, 0x900], ADDRS, THIRD)
        self.assertEqual(sorted(out["mixed"]), [0x10, 0x900])

    def test_every_window_lands_in_exactly_one_bucket(self) -> None:
        windows = [0x10, 0x180, 0x280, 0x380, 0x480, 0x900]
        out = attr.bucket(windows, ADDRS, THIRD)
        total = sum(len(v) for v in out.values())
        self.assertEqual(total, len(windows))
        flat = [a for v in out.values() for a in v]
        self.assertEqual(sorted(flat), sorted(windows))

    def test_a_span_test_would_disagree_and_that_is_the_point(self) -> None:
        """0x180 sits inside the 0x100-0x400 span of the third-party run, but its
        immediate neighbours are both first-party. A whole-file span test calls it
        middleware; this must not."""
        out = attr.bucket([0x180], ADDRS, THIRD)
        self.assertEqual(out["third_party_flanked"], [])


if __name__ == "__main__":
    unittest.main()
