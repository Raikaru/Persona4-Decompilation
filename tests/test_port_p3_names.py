"""Contract tests for tools/port_p3_names.py.

The tool ports real Persona 3 FES function names onto Persona 4 addresses
through the unique P4<->P3 compiled-function mapping, rejecting junk with
per-class counts. These tests pin the rejection rules (especially the
address-suffixed pseudo-name rule), the evidence-tier notes, and the output
contract that config/symbol_names*.txt producers must satisfy.
"""

from __future__ import annotations

import importlib.util
import re
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "port_p3_names.py"
SPEC = importlib.util.spec_from_file_location("p4_port_p3_names", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
port = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(port)

RECONCILE_PATH = REPO / "tools" / "reconcile_function_boundaries.py"
RECONCILE_SPEC = importlib.util.spec_from_file_location("p4_reconcile", RECONCILE_PATH)
assert RECONCILE_SPEC is not None and RECONCILE_SPEC.loader is not None
reconcile = importlib.util.module_from_spec(RECONCILE_SPEC)
RECONCILE_SPEC.loader.exec_module(reconcile)

CANONICAL = {0x00100008, 0x00100218, 0x00100570, 0x00100740}
P3_NAMES = {
    0x00100008: "func_00100008",  # placeholder
    0x00100218: "H_Cursor_DestroyTask",  # clean name
    0x00100570: "datPersona00173340",  # address-suffixed pseudo-name
    0x00100740: "btlUnitUpdate00285d30Packet",  # embedded-address pseudo-name
}
RECOVERED = {0x00100218}


def match(
    p4_address: int,
    p3_address: int,
    unique: bool = True,
    verified: bool = False,
    sources: list[str] | None = None,
) -> dict:
    return {
        "p4_address": f"{p4_address:08x}",
        "size": 4,
        "match_type": "address_normalized",
        "unique": unique,
        "p3_addresses": [f"{p3_address:08x}"],
        "exact_p3_addresses": [],
        "p3_evidence": [
            {
                "address": f"{p3_address:08x}",
                "verifier_match": verified,
                "sources": sources or [],
            }
        ],
        "references": [],
    }


def classify(
    matches: list[dict],
    p3_names: dict[int, str] | None = None,
    recovered: set[int] | None = None,
    canonical: set[int] | None = None,
    owners: dict[int, str] | None = None,
) -> tuple[list[dict], dict[str, int]]:
    return port.classify(
        matches,
        p3_names if p3_names is not None else P3_NAMES,
        recovered if recovered is not None else RECOVERED,
        canonical if canonical is not None else CANONICAL,
        owners if owners is not None else {0x00100218: "src/Battle/btlMain.c"},
    )


class JunkNameTests(unittest.TestCase):

    def test_rejects_placeholder(self) -> None:
        for name in ("func_00100008", "FUN_00100008", "func_0", "FUN_ABCDEF00"):
            self.assertEqual(port.name_junk(name), "placeholder")

    def test_rejects_address_suffixed_pseudo_name(self) -> None:
        """A placeholder wearing a prefix must not be ported as a real name."""
        for name in ("datPersona00173340", "kwln00197fb0", "H_Cdvd_001007f0", "H_Snd_FUN_00109ae0", "kwln197fb0"):
            self.assertEqual(port.name_junk(name), "address_suffixed")

    def test_rejects_embedded_address_pseudo_name(self) -> None:
        """A full 32-bit address embedded mid-identifier is junk too."""
        self.assertEqual(port.name_junk("btlUnitUpdate00285d30Packet"), "address_suffixed")

    def test_keeps_real_words_that_merely_look_hex(self) -> None:
        """Legit hex-ish tails measured in P3 top out at 5 trailing / 6 embedded."""
        self.assertIsNone(port.name_junk("btlActionUpdateStateDead"))  # trailing run of 5
        self.assertIsNone(port.name_junk("H_Pad_UpdateFaceButtonRepeat"))  # 6-run mid-name
        self.assertIsNone(port.name_junk("datUnitEcAddEnemy"))  # 6-run mid-name
        self.assertIsNone(port.name_junk("UpdateDead"))  # trailing run of 4
        self.assertIsNone(port.name_junk("H_Cursor_DestroyTask"))


class RejectionClassTests(unittest.TestCase):
    def test_rejects_address_suffixed_pseudo_name_in_classify(self) -> None:
        accepted, counts = classify(
            [match(0x00100570, 0x00100570), match(0x00100740, 0x00100740)]
        )
        self.assertEqual(accepted, [])
        self.assertEqual(counts["address_suffixed"], 2)
        self.assertEqual(counts["placeholder"], 0)

    def test_rejects_placeholder(self) -> None:
        accepted, counts = classify([match(0x00100008, 0x00100008)])
        self.assertEqual(accepted, [])
        self.assertEqual(counts["placeholder"], 1)

    def test_skips_non_unique_mapping_without_guessing(self) -> None:
        mapping = match(0x00100218, 0x00100218)
        mapping["unique"] = False
        mapping["p3_addresses"] = ["00100218", "00100570"]
        accepted, counts = classify([mapping])
        self.assertEqual(accepted, [])
        self.assertEqual(counts["non_unique"], 1)

    def test_rejects_third_party_target(self) -> None:
        accepted, counts = classify(
            [match(0x00100218, 0x00100218)],
            owners={0x00100218: "src/rw/rwcore_grouped.c"},
        )
        self.assertEqual(accepted, [])
        self.assertEqual(counts["third_party"], 1)

    def test_accepts_asm_owned_target_when_no_source_owner_exists(self) -> None:
        """No owning source file means is_third_party never classifies it."""
        accepted, counts = classify(
            [match(0x00100218, 0x00100218)], owners={}
        )
        self.assertEqual(len(accepted), 1)
        self.assertEqual(counts["third_party"], 0)

    def test_rejects_non_canonical_p4_address(self) -> None:
        accepted, counts = classify([match(0x00999999, 0x00100218)])
        self.assertEqual(accepted, [])
        self.assertEqual(counts["not_canonical"], 1)

    def test_skips_unique_match_without_p3_name_entry(self) -> None:
        accepted, counts = classify([match(0x00100740, 0x00550000)])
        self.assertEqual(accepted, [])
        self.assertEqual(counts["p3_name_missing"], 1)

    def test_skips_duplicate_name_after_first_acceptance(self) -> None:
        """Two addresses sharing one symbol would break the link; emit only one."""
        second = match(0x00100570, 0x00100218)  # same P3 name, different P4 target
        accepted, counts = classify([match(0x00100218, 0x00100218), second])
        self.assertEqual([entry["p4_address"] for entry in accepted], [0x00100218])
        self.assertEqual(counts["duplicate_name"], 1)


class EvidenceTierTests(unittest.TestCase):
    def test_tier_one_for_verifier_matched_p3_function(self) -> None:
        accepted, _counts = classify(
            [match(0x00100218, 0x00100218, verified=True, sources=["src/g_data.c"])]
        )
        self.assertEqual(accepted[0]["tier"], 1)
        note = port.evidence_note(accepted[0])
        self.assertIn("tier:1", note)
        self.assertIn("p3:H_Cursor_DestroyTask@0x00100218", note)
        self.assertIn("file:src/g_data.c", note)

    def test_tier_two_for_recovered_but_unmatched_address(self) -> None:
        accepted, _counts = classify(
            [match(0x00100218, 0x00100218, verified=False)]
        )
        self.assertEqual(accepted[0]["tier"], 2)
        self.assertIn("tier:2", port.evidence_note(accepted[0]))

    def test_tier_three_for_source_present_but_unverified(self) -> None:
        accepted, _counts = classify(
            [match(0x00100218, 0x00100218, verified=False, sources=["src/kwln.c"])],
            recovered=set(),
        )
        self.assertEqual(accepted[0]["tier"], 3)
        self.assertIn("tier:3", port.evidence_note(accepted[0]))

    def test_tier_four_names_the_ghidra_guess(self) -> None:
        """No verifier, recovered, or source evidence: say it is a guess."""
        accepted, _counts = classify(
            [match(0x00100218, 0x00100218, verified=False)],
            recovered=set(),
        )
        self.assertEqual(accepted[0]["tier"], 4)
        note = port.evidence_note(accepted[0])
        self.assertIn("tier:4", note)
        self.assertIn("Ghidra-exported guess", note)


class OutputContractTests(unittest.TestCase):
    def test_rendered_lines_satisfy_the_reconcile_contract(self) -> None:
        accepted, _counts = classify(
            [
                match(0x00100218, 0x00100218, verified=True),
                match(0x00100740, 0x00100008),  # placeholder source: rejected
            ],
            p3_names={0x00100218: "H_Cursor_DestroyTask", 0x00100008: "func_00100008"},
        )
        lines = port.build_lines(accepted, total=2)
        entries = [line for line in lines if not line.startswith("//") and line.strip()]
        self.assertEqual(len(entries), 1)
        parsed = reconcile.NAME_LINE.match(entries[0])
        self.assertIsNotNone(parsed)
        self.assertEqual(parsed["name"], "H_Cursor_DestroyTask")
        self.assertEqual(int(parsed["addr"], 16), 0x00100218)
        self.assertIn("evidence:", parsed["rest"])
        self.assertIsNone(reconcile.PLACEHOLDER.match(parsed["name"]))

    def test_output_is_deterministic_and_wholesale(self) -> None:
        matches = [
            match(0x00100740, 0x00100570, verified=True),
            match(0x00100218, 0x00100218, verified=True),
        ]
        options = dict(
            p3_names={
                0x00100218: "H_Cursor_DestroyTask",
                0x00100570: "datGetFlag",
            },
            owners={
                0x00100218: "src/Battle/btlMain.c",
                0x00100740: "src/Battle/btlMain.c",
            },
        )
        accepted, _counts = classify(matches, **options)
        reversed_accepted, _counts = classify(list(reversed(matches)), **options)
        first = port.build_lines(accepted, total=2)
        second = port.build_lines(reversed_accepted, total=2)
        self.assertEqual(first, second)
        entries = [line for line in first if reconcile.NAME_LINE.match(line)]
        self.assertEqual(len(entries), 2)
        # entries are sorted by address, not by input order
        addresses = [
            int(reconcile.NAME_LINE.match(line)["addr"], 16)
            for line in first
            if reconcile.NAME_LINE.match(line)
        ]
        self.assertEqual(addresses, [0x00100218, 0x00100740])

    def test_write_output_is_atomic_binary_and_repeatable(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "symbol_names.p3.txt"
            path.write_bytes(b"stale contents that must be replaced entirely\n")
            lines = ["// caf\u00e9", "Name = 0x00100008;"]
            expected = b"// caf\xc3\xa9\nName = 0x00100008;\n"
            port.write_output(path, lines)
            self.assertEqual(path.read_bytes(), expected)
            port.write_output(path, lines)
            self.assertEqual(path.read_bytes(), expected)
            from unittest.mock import patch
            def fail_publish(staged, destination):
                self.assertEqual(Path(destination).read_bytes(), expected)
                self.assertEqual(staged.read_bytes(), b"replacement\n")
                raise OSError("injected publication failure")
            with patch.object(Path, "replace", fail_publish):
                with self.assertRaises(OSError):
                    port.write_output(path, ["replacement"])
            self.assertEqual(path.read_bytes(), expected)
            port.write_output(path, lines)
            self.assertFalse(path.with_name(path.name + ".tmp").exists())

    def test_parse_recovered_collects_function_addresses_only(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "symbols_recovered.txt"
            path.write_bytes(
                b"// Recovered symbol addresses\n"
                b"_gp = 0x007d2cf0; // type:gp\n"
                b"FUN_00100570 = 0x00100570; // type:func\n"
                b"H_Cdvd_Init = 0x00100800; // type:func\n"
            )
            self.assertEqual(port.parse_recovered(path), {0x00100570, 0x00100800})

    def test_parse_p3_symbols_reads_func_entries_and_skips_gp(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "symbol_addrs.txt"
            path.write_bytes(
                b"// Format: name = 0xADDR; // type:func\n"
                b"func_00100008 = 0x00100008; // type:func\n"
                b"H_Cdvd_Init = 0x00100800; // type:func\n"
                b"_gp = 0x007d2cf0; // type:gp\n"
            )
            self.assertEqual(
                port.parse_p3_symbols(path),
                {0x00100008: "func_00100008", 0x00100800: "H_Cdvd_Init"},
            )


if __name__ == "__main__":
    unittest.main()
