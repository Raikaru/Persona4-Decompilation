"""An archived function must not be scheduled as an untouched reconstruction."""

import contextlib
import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import recon_pool  # noqa: E402


class ArchiveDiscoveryTests(unittest.TestCase):
    def test_fresh_pool_resolves_archive_addresses_without_consuming_prefixes(self):
        archives = {
            "UnC001d7c60au_001d7c60_body.c": "001d7c60",
            "W001d7f10.c": "001d7f10",
            "legacyC001d8000au.c": "001d8000",
            "20260904_001d81a0_body.c": "001d81a0",
            "WT_001D83B0_body.c.txt": "001d83b0",
        }
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            archive_dir = root / "docs" / "probe_archive"
            archive_dir.mkdir(parents=True)
            for name, addr in archives.items():
                (archive_dir / name).write_text(
                    f"void func_{addr}(void) {{ return; }}\n", encoding="utf-8"
                )
            # A partial body still proves an attempt when its name is unambiguous.
            (archive_dir / "WT_001d8480.c").write_text("{ return; }\n", encoding="utf-8")
            # An oversized hex run must not become a truncated function address.
            (archive_dir / "bad_001d820000.c").write_text(
                "void helper(void) { return; }\n", encoding="utf-8"
            )
            addresses = [*archives.values(), "001d8480", "001d8200", "001d8500"]
            report = root / "report.json"
            report.write_text(json.dumps({"results": [
                {"file": "src/promoted/code1_001d.c", "addr": addr,
                 "name": f"func_{addr}", "status": "ASM", "window": 688}
                for addr in addresses
            ]}), encoding="utf-8")
            output = root / "pool.json"
            argv = ["recon_pool.py", "--report", str(report), "--pool", "fresh",
                    "--max-window", "800", "--json", str(output)]
            with mock.patch.object(recon_pool, "REPO", str(root)), \
                    mock.patch.object(sys, "argv", argv), \
                    contextlib.redirect_stdout(io.StringIO()):
                recon_pool.main()
            fresh = {row["addr"] for row in json.loads(output.read_text(encoding="utf-8"))}
            self.assertEqual(fresh, {"001d8200", "001d8500"})


if __name__ == "__main__":
    unittest.main()
