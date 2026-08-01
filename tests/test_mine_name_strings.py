from __future__ import annotations

import importlib.util
import json
import re
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "mine_name_strings.py"
SPEC = importlib.util.spec_from_file_location("p4_mine_strings", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
mine = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(mine)

RECONCILE_PATH = REPO / "tools" / "reconcile_function_boundaries.py"
RECONCILE_SPEC = importlib.util.spec_from_file_location("p4_reconcile", RECONCILE_PATH)
assert RECONCILE_SPEC is not None and RECONCILE_SPEC.loader is not None
reconcile = importlib.util.module_from_spec(RECONCILE_SPEC)
RECONCILE_SPEC.loader.exec_module(reconcile)


def lui(rt: int, imm: int) -> int:
    return (0x0F << 26) | (rt << 16) | (imm & 0xFFFF)


def addiu(rt: int, rs: int, imm: int) -> int:
    return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def ori(rt: int, rs: int, imm: int) -> int:
    return (0x0D << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def lw(rt: int, rs: int, imm: int) -> int:
    return (0x23 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


class IdentifierTransformTests(unittest.TestCase):
    def test_keeps_retail_identifiers_verbatim(self) -> None:
        # The documented transform is identity for already-valid identifiers.
        self.assertEqual(mine.to_identifier("ENBAD_ALL"), "ENBAD_ALL")
        self.assertEqual(mine.to_identifier("Y_FclCombineTitleProc"), "Y_FclCombineTitleProc")
        self.assertEqual(mine.to_identifier(b"battle_shuffle_arcana_card"), "battle_shuffle_arcana_card")

    def test_rejects_non_identifiers(self) -> None:
        self.assertIsNone(mine.to_identifier("CHANGE FORM"))
        self.assertIsNone(mine.to_identifier("ENEMY DEAD"))
        self.assertIsNone(mine.to_identifier("2FAST"))
        self.assertIsNone(mine.to_identifier("file.c"))
        self.assertIsNone(mine.to_identifier(""))
        self.assertIsNone(mine.to_identifier("a-b"))

    def test_rejects_keywords_and_placeholders(self) -> None:
        self.assertIsNone(mine.to_identifier("auto"))
        self.assertIsNone(mine.to_identifier("void"))
        self.assertIsNone(mine.to_identifier("func_00123456"))
        self.assertIsNone(mine.to_identifier("FUN_00123456"))

    def test_role_prefix_is_prepended_not_invented(self) -> None:
        # The retail keyword stays intact; the prefix is presentation only.
        self.assertEqual(mine.to_identifier("MYHP", "btlCond_"), "btlCond_MYHP")
        self.assertEqual(mine.to_identifier(b"TARGET", "btlAct_"), "btlAct_TARGET")
        self.assertIsNone(mine.to_identifier("MYHP", "1bad_"))
        self.assertIsNone(mine.to_identifier("CHANGE FORM", "btlAct_"))

    def test_role_prefix_region_table(self) -> None:
        self.assertEqual(mine.role_prefix(0x005F74E4), "btlAct_")    # action table
        self.assertEqual(mine.role_prefix(0x00609860), "btlCond_")   # condition table
        self.assertEqual(mine.role_prefix(0x005F7188), "tbl_")       # unknown region


class StringExtractionTests(unittest.TestCase):
    def test_finds_printable_runs(self) -> None:
        blob = b"\x00" + b"HELLO" + b"\x00\x01" + b"AB" + b"\x00" + b"TOOLONG" + b"\x00\xff"
        strings = mine.extract_strings(blob, 0x1000, 0x1000 + len(blob), 0x1000, min_len=3)
        self.assertEqual(strings, {0x1001: b"HELLO", 0x100B: b"TOOLONG"})

    def test_run_ending_at_segment_end(self) -> None:
        blob = b"TAIL"  # printable run reaches the very end of the buffer
        strings = mine.extract_strings(blob, 0x2000, 0x2004, 0x2000, min_len=3)
        self.assertEqual(strings, {0x2000: b"TAIL"})


class ReferenceResolutionTests(unittest.TestCase):
    def test_resolves_lui_addiu_and_lui_ori_pairs(self) -> None:
        words = [
            lui(5, 0x0065), addiu(5, 5, 0xEA60),  # 0x0065EA60 sign-extended -> 0x0064EA60
            lui(6, 0x0040), ori(6, 6, 0x1234),    # 0x00401234
            lui(7, 0x00AA), lw(7, 7, 0),          # rt written by lw: no pair
            lui(8, 0x00BB),                       # dangling lui: nothing
            0x00000000,
        ]
        self.assertEqual(mine.absolute_references(words), {0x0064EA60, 0x00401234})

    def test_intervening_write_ends_pair(self) -> None:
        words = [lui(5, 0x0065), addiu(5, 0, 0x0001), addiu(5, 5, 0xEA60)]
        self.assertEqual(mine.absolute_references(words), set())


class RecordAdjacencyTests(unittest.TestCase):
    """Class A: {name, fn} records in the retail data segments."""

    F1, F2, F3 = 0x4000, 0x5000, 0x6000
    FN_WORDS = {F1, F2, F3}

    def setUp(self) -> None:
        self.strings = {
            0x1000: b"ALPHA",
            0x2000: b"BETA",
            0x3000: b"GAMMA",
            0x4000: b"NOT_A_NAME",  # shadows nothing: not used as a string site
        }
        self.sites = {
            0x1000: [0x8000, 0x8030],  # ALPHA: beside F1 (8000) and F3 (8030)
            0x2000: [0x8010],          # BETA: flanked by F2 (-4) and F3 (+4)
            0x3000: [0x8020],          # GAMMA: beside F1 only
        }

    def word_at(self, address: int) -> int:
        table = {
            0x7FFC: 0, 0x8000: 0x1000, 0x8004: self.F1, 0x8008: 0,
            0x800C: self.F2, 0x8010: 0x2000, 0x8014: self.F3, 0x8018: 0,
            0x801C: 0, 0x8020: 0x3000, 0x8024: self.F1, 0x8028: 0,
            0x802C: 0, 0x8030: 0x1000, 0x8034: self.F3, 0x8038: 0,
        }
        return table.get(address, 0)

    def is_fn_word(self, value: int) -> bool:
        return value in self.FN_WORDS

    def test_string_adjacent_to_two_functions_names_none(self) -> None:
        """A name string flanked by two handler pointers binds neither."""
        records, ambiguous = mine.record_candidates(
            self.sites, self.strings, self.word_at, self.is_fn_word
        )
        betas = [r for r in records if r[0] == 0x2000]
        self.assertEqual(betas, [])
        self.assertTrue(any(s == 0x2000 for s, _fns, _site in ambiguous))

    def test_string_in_records_of_two_functions_names_none(self) -> None:
        """The same name string in records of two different functions is shared."""
        records, _ambiguous = mine.record_candidates(
            self.sites, self.strings, self.word_at, self.is_fn_word
        )
        named = mine.single_function_records(records)
        self.assertNotIn(0x1000, named)  # ALPHA -> {F1, F3}: dropped
        self.assertEqual(named, {0x3000: self.F1})

    def test_single_adjacent_function_is_accepted(self) -> None:
        records, _ambiguous = mine.record_candidates(
            self.sites, self.strings, self.word_at, self.is_fn_word
        )
        self.assertIn((0x3000, self.F1, 0x8020), records)

    def test_record_with_two_functions_on_one_side_is_ambiguous(self) -> None:
        """{name, fnA, fnB}: the second canonical fn makes the field ambiguous."""
        sites = {0x5000: [0x9000]}
        strings = {0x5000: b"ORDER"}
        table = {0x8FFC: 0, 0x9000: 0x5000, 0x9004: self.F1, 0x9008: self.F2, 0x900C: 0}

        def word_at(address: int) -> int:
            return table.get(address, 0)

        records, _ambiguous = mine.record_candidates(sites, strings, word_at, self.is_fn_word)
        self.assertEqual(records, [])


class UniqueReferenceTests(unittest.TestCase):
    def test_string_referenced_from_two_functions_names_none(self) -> None:
        """Class B/C rule: two referencers -> the string names neither."""
        ref_users = {
            0x1000: {0x4000},
            0x2000: {0x4000, 0x5000},  # referenced from TWO functions
        }
        strings = {0x1000: b"ALPHA", 0x2000: b"BETA"}
        names = mine.unique_reference_names(ref_users, strings, {0x4000, 0x5000})
        self.assertEqual(names, {0x1000: 0x4000})
        self.assertNotIn(0x2000, names)


class CommittedOutputTests(unittest.TestCase):
    def test_output_file_is_contract_clean(self) -> None:
        path = REPO / "config" / "symbol_names.strings.txt"
        self.assertTrue(path.is_file(), "run `python tools/mine_name_strings.py` first")
        windows = json.loads(
            (REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8")
        )["windows"]
        canonical = {int(address, 16) for address in windows}
        names: dict[str, int] = {}
        addresses: set[int] = set()
        for number, line in enumerate(
            path.read_text(encoding="utf-8").splitlines(), 1
        ):
            stripped = line.strip()
            if not stripped or stripped.startswith("//"):
                continue
            match = reconcile.NAME_LINE.match(line)
            self.assertIsNotNone(
                match, f"{path.name}:{number}: malformed line {line!r}"
            )
            assert match is not None
            name, address = match["name"], int(match["addr"], 16)
            self.assertIn(address, canonical, f"{path.name}:{number}")
            self.assertIn('evidence: string:"', match["rest"])
            self.assertIsNone(reconcile.PLACEHOLDER.match(name))
            # The role prefix is presentation; the evidence note must carry
            # the raw retail keyword (the name minus its prefix) verbatim.
            prefix = next((p for p in ("btlAct_", "btlCond_", "tbl_") if name.startswith(p)), None)
            self.assertIsNotNone(prefix, f"{path.name}:{number}: unknown prefix in {name!r}")
            evidence = re.search(r'evidence: string:"([^"]*)"', match["rest"])
            assert evidence is not None
            self.assertEqual(
                evidence.group(1), name[len(prefix):],
                f"{path.name}:{number}: evidence keyword must equal the unprefixed name",
            )
            self.assertNotIn(name, names, f"{path.name}:{number}: duplicate name")
            self.assertNotIn(address, addresses, f"{path.name}:{number}: duplicate address")
            names[name] = address
            addresses.add(address)
        self.assertGreaterEqual(len(names), 1)


if __name__ == "__main__":
    unittest.main()
