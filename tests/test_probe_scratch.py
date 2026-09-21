from __future__ import annotations

import importlib.util
import os
import sys
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_probe_variants",
                                              REPO / "tools" / "probe_variants.py")
assert SPEC is not None and SPEC.loader is not None
probe = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(probe)


class ScratchSweepTests(unittest.TestCase):
    """`scratch_source` removes its own file in a `finally`, which only runs
    when the process survives.  A cancelled probe, a timeout or a killed
    agent leaks one into `src/`, and 44 had accumulated before one of them
    broke a compile inside another agent's harness.  They are invisible to
    git and to `gate_audit` because the name starts with a dot, so nothing
    was going to report them."""

    def setUp(self) -> None:
        self.dir = Path(tempfile.mkdtemp())
        self.source = self.dir / "unit.c"
        self.source.write_text("int x;\n")

    def test_a_stale_leftover_is_swept(self) -> None:
        stale = self.dir / ".unit.probe_abcdefgh.c"
        stale.write_text("leaked")
        os.utime(stale, (0, 0))
        with probe.scratch_source(self.source):
            self.assertFalse(stale.exists())

    def test_a_concurrent_probe_is_left_alone(self) -> None:
        """Sweeping on age is what makes this safe to run while other probes
        are in flight - eight agents share this tree."""
        fresh = self.dir / ".unit.probe_ijklmnop.c"
        fresh.write_text("in use by another probe")
        with probe.scratch_source(self.source):
            self.assertTrue(fresh.exists())

    def test_an_unrelated_file_is_never_touched(self) -> None:
        for name in ("unit.c", ".unit.c.swp", "other.c", ".other.probe_x.c"):
            (self.dir / name).write_text("keep")
            os.utime(self.dir / name, (0, 0))
        with probe.scratch_source(self.source):
            pass
        for name in ("unit.c", ".unit.c.swp", "other.c", ".other.probe_x.c"):
            self.assertTrue((self.dir / name).exists(), name)

    def test_the_scratch_file_still_cleans_up_normally(self) -> None:
        with probe.scratch_source(self.source) as path:
            self.assertTrue(path.exists())
        self.assertFalse(path.exists())


if __name__ == "__main__":
    unittest.main()
