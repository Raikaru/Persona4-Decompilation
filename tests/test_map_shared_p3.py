from __future__ import annotations

import importlib.util
import json
import struct
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "map_shared_p3.py"
SPEC = importlib.util.spec_from_file_location("p4_map_shared_p3", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
mapper = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(mapper)


def pack(*words: int) -> bytes:
    return struct.pack("<" + "I" * len(words), *words)


class NormalizationTests(unittest.TestCase):
    def test_masks_only_address_bearing_fields(self) -> None:
        first = pack(
            0x0C123456,  # jal target
            0x3C020012,  # lui v0, high address
            0x24423456,  # addiu v0, v0, low address
            0x8F838000,  # lw v1, negative gp-relative offset
        )
        relocated = pack(
            0x0C654321,
            0x3C020045,
            0x24426789,
            0x8F839000,
        )
        self.assertEqual(mapper.normalize_mips(first), mapper.normalize_mips(relocated))

    def test_preserves_registers_constants_and_branches(self) -> None:
        baseline = pack(0x24020001, 0x10400003)  # addiu v0, zero, 1; beq v0, zero, +3
        changed_constant = pack(0x24020002, 0x10400003)
        changed_register = pack(0x24030001, 0x10400003)
        changed_branch = pack(0x24020001, 0x10400004)
        self.assertNotEqual(mapper.normalize_mips(baseline), mapper.normalize_mips(changed_constant))
        self.assertNotEqual(mapper.normalize_mips(baseline), mapper.normalize_mips(changed_register))
        self.assertNotEqual(mapper.normalize_mips(baseline), mapper.normalize_mips(changed_branch))


class ComparisonTests(unittest.TestCase):
    def test_reports_exact_normalized_and_ambiguous_matches(self) -> None:
        p3_image = pack(
            0x3C020010,
            0x24420001,
            0x3C020020,
            0x24420001,
            0x03E00008,
        )
        p4_image = pack(
            0x3C020030,
            0x24420001,
            0x03E00008,
        )
        summary, matches = mapper.compare_functions(
            p3_image,
            {0x1000: 8, 0x1008: 8, 0x1010: 4},
            p4_image,
            {0x1000: 8, 0x1008: 4},
            p3_base=0x1000,
            p4_base=0x1000,
            p3_verified={0x1010},
        )
        self.assertEqual(summary["exact"]["functions"], 1)
        self.assertEqual(summary["address_normalized"]["functions"], 2)
        self.assertEqual(summary["address_normalized"]["unique_functions"], 1)
        self.assertEqual(summary["p3_verifier_matched_unique"]["functions"], 1)
        self.assertFalse(matches[0]["unique"])
        self.assertEqual(matches[0]["p3_addresses"], ["00001000", "00001008"])
        self.assertEqual(matches[1]["match_type"], "exact")

    def test_decodes_calls_and_lui_address_pairs(self) -> None:
        p3_body = pack(0x3C050010, 0x24A51200, 0x0C040480, 0)
        p4_body = pack(0x3C050010, 0x24A52200, 0x0C040880, 0)
        references = mapper.relocated_references(
            p3_body,
            p4_body,
            0x00101000,
            0x00102000,
            0x00100000,
            0x00100000,
            bytes(0x3000),
            bytes(0x3000),
            {0x00101200},
            {0x00102200},
            None,
            None,
        )
        self.assertEqual(
            [(item["kind"], item["p3_address"], item["p4_address"]) for item in references],
            [
                ("hi_lo", "00101200", "00102200"),
                ("jal", "00101200", "00102200"),
            ],
        )


class SourceEvidenceTests(unittest.TestCase):
    def test_reads_verifier_addresses_and_source_markers(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "progress").mkdir()
            (root / "src").mkdir()
            metrics = {"matching": {"addresses": ["00123450"]}}
            (root / "progress" / "metrics.json").write_text(
                json.dumps(metrics), encoding="utf-8"
            )
            (root / "src" / "example.c").write_text(
                "// FUN_00123450\nvoid example(void) {}\n", encoding="utf-8"
            )
            matched, sources, metrics_sha1 = mapper.load_source_evidence(root)
            self.assertEqual(matched, {0x00123450})
            self.assertEqual(sources, {0x00123450: ["src/example.c"]})
            self.assertEqual(len(metrics_sha1), 40)


if __name__ == "__main__":
    unittest.main()
