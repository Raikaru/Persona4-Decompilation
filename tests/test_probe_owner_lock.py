"""Exercise probe exclusion using real independent processes."""
from __future__ import annotations

import subprocess
import sys
import tempfile
import time
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / "tools"
sys.path.insert(0, str(TOOLS))
import probe_variants as probe


CHILD = """
import sys
from pathlib import Path
sys.path.insert(0, sys.argv[1])
import probe_variants as probe
owner, ready, entered = map(Path, sys.argv[2:])
ready.touch()
with probe._owner_lock(owner):
    entered.touch()
"""


class OwnerLockTests(unittest.TestCase):
    def start_child(self, root: Path, owner: Path, name: str):
        ready, entered = root / (name + ".ready"), root / (name + ".entered")
        process = subprocess.Popen(
            [sys.executable, "-X", "utf8", "-c", CHILD, str(TOOLS),
             str(owner), str(ready), str(entered)],
            stdout=subprocess.PIPE, stderr=subprocess.PIPE,
        )

        def cleanup():
            if process.poll() is None:
                process.kill()
            process.communicate(timeout=10)

        self.addCleanup(cleanup)
        deadline = time.monotonic() + 10
        while not ready.exists() and process.poll() is None and time.monotonic() < deadline:
            time.sleep(0.01)
        self.assertTrue(ready.exists(), "child did not reach the lock")
        return process, entered

    def finish_child(self, process, entered):
        output, errors = process.communicate(timeout=10)
        self.assertEqual(process.returncode, 0, (output + errors).decode(errors="replace"))
        self.assertTrue(entered.exists())

    def test_same_owner_blocks_but_different_owner_compiles(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            owner = root / "owner.c"
            with probe._owner_lock(owner):
                same, same_entered = self.start_child(root, owner, "same")
                other, other_entered = self.start_child(root, root / "other.c", "other")
                self.finish_child(other, other_entered)
                self.assertIsNone(same.poll())
                self.assertFalse(same_entered.exists())
            self.finish_child(same, same_entered)

    def test_exception_releases_lock_for_next_process(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            owner = root / "owner.c"
            with self.assertRaisesRegex(RuntimeError, "compile interrupted"):
                with probe._owner_lock(owner):
                    raise RuntimeError("compile interrupted")
            process, entered = self.start_child(root, owner, "after-error")
            self.finish_child(process, entered)


if __name__ == "__main__":
    unittest.main()
