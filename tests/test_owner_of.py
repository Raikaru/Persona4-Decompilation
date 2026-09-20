from __future__ import annotations

import subprocess
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def run(*args: str) -> subprocess.CompletedProcess[str]:
    return subprocess.run([sys.executable, "-E", "-s", "tools/owner_of.py", *args],
                          cwd=REPO, capture_output=True, text=True, timeout=600)


class OwnerOfTests(unittest.TestCase):
    """Two agents editing one file clobber each other even when they own
    different functions in it.  Three dispatches went out wrong in one session
    for exactly this reason, so the collision check has to be reliable."""

    def test_two_functions_in_one_file_are_a_collision(self) -> None:
        done = run("func_004a3640", "func_004a2310")
        self.assertIn("effPolygonWind.c", done.stdout)
        self.assertIn("COLLISION", done.stdout)
        self.assertEqual(done.returncode, 1)

    def test_functions_in_different_files_are_not_a_collision(self) -> None:
        done = run("func_004a3640", "func_00131a00")
        self.assertNotIn("COLLISION", done.stdout)
        self.assertEqual(done.returncode, 0)
        self.assertIn("effPolygonWind.c", done.stdout)
        self.assertIn("cmpEquip.c", done.stdout)

    def test_an_unknown_function_is_reported_and_fails(self) -> None:
        """Silently dropping a name would let a dispatch proceed on a typo."""
        done = run("func_00131a00", "func_deadbeef")
        self.assertIn("UNKNOWN: func_deadbeef", done.stdout)
        self.assertEqual(done.returncode, 1)

    def test_every_requested_file_is_listed_once_with_all_its_functions(self) -> None:
        done = run("func_004a3640", "func_004a2310", "func_00131a00")
        lines = [line for line in done.stdout.split("\n") if line.startswith("src/")]
        self.assertEqual(len(lines), 2)
        wind = next(line for line in lines if "effPolygonWind.c" in line)
        self.assertIn("func_004a2310", wind)
        self.assertIn("func_004a3640", wind)


if __name__ == "__main__":
    unittest.main()
