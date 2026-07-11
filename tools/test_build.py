#!/usr/bin/env python3

import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build


class LinkResponseFileTests(unittest.TestCase):
    def test_link_uses_response_file_for_object_list(self):
        entries = [
            (0x2000, Path("second object.o"), ".text"),
            (0x1000, Path("first.o"), ".text"),
            (0x3000, Path("first.o"), ".text"),
        ]
        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary)
            with mock.patch.object(build, "BUILD", output), mock.patch.object(build, "sh") as sh:
                build.link({"ld_exe": "mwldps2.exe"}, entries)
            entry_symbol = build.ELF_TARGET.get(
                "entry_symbol", f"func_{build.parse_int(build.ELF_TARGET['entry']):08x}"
            )
            args = [
                "-nostdlib", "-nodeadstrip", "-m", entry_symbol,
                "-o", str(output / "slus21782.elf"), str(output / "slus21782.lcf"),
                "first.o", "second object.o",
            ]
            self.assertEqual(
                (output / "slus21782.rsp").read_text(encoding="utf-8"),
                subprocess.list2cmdline(args),
            )
            sh.assert_called_once_with(["mwldps2.exe", f"@{output / 'slus21782.rsp'}"])


if __name__ == "__main__":
    unittest.main()
