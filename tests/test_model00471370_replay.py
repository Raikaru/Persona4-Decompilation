"""Public synthetic tests; no game bytes or proprietary inputs."""
from pathlib import Path
import struct
import sys
from types import SimpleNamespace
import unittest

sys.dont_write_bytecode = True
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import model_replay_elf as A
import replay_model00471370 as R


class ReplayTests(unittest.TestCase):
    def test_only_target_guard_changes(self):
        source = (b"// FUN_00471370 NONMATCHING\n#ifdef NON_MATCHING\n"
                  b"candidate\n#else\nfallback\n#endif\n"
                  b"// FUN_0047b0c0 NONMATCHING\n#ifdef NON_MATCHING\n")
        expected = source.replace(b"#ifdef NON_MATCHING", b"#if 1", 1)
        self.assertEqual(R.enable_target(source), expected)
        self.assertEqual(R.enable_target(source.replace(b"\n", b"\r\n")), expected.replace(b"\n", b"\r\n"))

    def test_missing_duplicate_and_already_enabled_guard_fail(self):
        guard = b"// FUN_00471370 NONMATCHING\n#ifdef NON_MATCHING\n"
        for source in (b"", guard * 2, guard.replace(b"#ifdef NON_MATCHING", b"#if 1")):
            with self.subTest(source=source), self.assertRaises(RuntimeError):
                R.enable_target(source)

    def test_word_metrics_include_insert_delete_substitute(self):
        pack = lambda values: struct.pack("<%dI" % len(values), *values)
        for a, b, cost in [([], [], 0), ([1, 2], [1, 2], 0),
                           ([1, 2], [1, 3], 1), ([1], [1, 2], 1),
                           ([1, 2], [2], 1), ([1, 2, 3], [3, 1, 2], 2)]:
            with self.subTest(a=a, b=b):
                self.assertEqual(R.metrics(pack(a), pack(b))["unit_word_levenshtein"], cost)

    def setUp(self):
        A.V = SimpleNamespace(resolve_symbol=lambda name, gp, values: values.get(name))
        A.gp, A.values = 0x10000, {"test": 0x10004}
        self.obj = SimpleNamespace(symbols=[])

    def resolve(self, words, kinds, values=None):
        if values is not None:
            A.values = values
        refs = [dict(offset=i * 4, r_type=k, symbol="test") for i, k in enumerate(kinds)]
        return A.resolve(self.obj, struct.pack("<%dI" % len(words), *words), refs, {})

    def test_absolute_jump_gp_and_hi_lo_resolution(self):
        for words, kinds, expected in [([8], [2], [0x1000c]),
                                       ([0x0c000000], [4], [0x0c004001]),
                                       ([0x8f820000], [7], [0x8f820004]),
                                       ([0xc7820000], [8], [0xc7820004]),
                                       ([0x3c020000, 0x24420000], [5, 6], [0x3c020001, 0x24420004])]:
            result, rows = self.resolve(words, kinds)
            self.assertEqual(result, struct.pack("<%dI" % len(expected), *expected))
            self.assertFalse(any("error" in row for row in rows))

    def test_unresolved_unpaired_and_range_errors(self):
        for words, kinds, values, error in [([0], [2], {}, "unresolved"),
                                            ([0], [5], {"test": 4}, "unpaired HI16"),
                                            ([0], [6], {"test": 4}, "unpaired LO16"),
                                            ([0], [7], {"test": 0}, "GP out of range"),
                                            ([0], [4], {"test": 3}, "J26 out of range")]:
            _, rows = self.resolve(words, kinds, values)
            self.assertEqual(rows[0]["error"], error)


if __name__ == "__main__":
    unittest.main()
