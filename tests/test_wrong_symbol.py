"""tools/verify.py's data-symbol cross-check.

Relocation immediates are masked out of the byte comparison, so a MATCH can
name a data symbol whose address cannot produce the immediate retail encodes.
The full link catches that only for link-eligible units; this check must catch
it everywhere, using the candidate's addend, without crying wolf on ordinary
base-plus-offset access.
"""
from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("p4_verify", REPO / "tools" / "verify.py")
assert SPEC is not None and SPEC.loader is not None
verify = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = verify
SPEC.loader.exec_module(verify)

GP = 0x007690F0
TABLE = {"D_008872E0": 0x008872E0, "fGpffff8200": 0x007612F0}


def match(*relocations: dict) -> dict:
    return {"status": "MATCH", "relocations": list(relocations)}


def gprel(offset: int, symbol: str, retail: int, addend: int = 0) -> dict:
    return dict(offset=offset, r_type=7, symbol=symbol, retail_imm=f"{retail:#06x}", addend=f"{addend & 0xffff:#06x}")


def hi(offset: int, symbol: str, retail: int, addend: int = 0) -> dict:
    return dict(offset=offset, r_type=5, symbol=symbol, retail_imm=f"{retail:#06x}", addend=f"{addend & 0xffff:#06x}")


def lo(offset: int, symbol: str, retail: int, addend: int = 0) -> dict:
    return dict(offset=offset, r_type=6, symbol=symbol, retail_imm=f"{retail:#06x}", addend=f"{addend & 0xffff:#06x}")


class ResolveSymbolTests(unittest.TestCase):
    def test_table_entry_wins_over_name_encoding(self) -> None:
        self.assertEqual(verify.resolve_symbol("fGpffff8200", GP, {"fGpffff8200": 0x00761300}), 0x00761300)

    def test_gp_name_encodes_signed_displacement(self) -> None:
        self.assertEqual(verify.resolve_symbol("iGpffffb2e4", GP, {}), 0x007643D4)

    def test_address_named_symbols_resolve_without_table(self) -> None:
        self.assertEqual(verify.resolve_symbol("func_00165fb0", GP, {}), 0x00165FB0)
        self.assertEqual(verify.resolve_symbol("DAT_0088737c_abs", GP, {}), 0x0088737C)
        self.assertEqual(verify.resolve_symbol("jtbl_008873E8", GP, {}), 0x008873E8)

    def test_unknown_symbol_is_skipped_not_guessed(self) -> None:
        self.assertIsNone(verify.resolve_symbol("sceneState", GP, {}))


class WrongSymbolTests(unittest.TestCase):
    def test_correct_gp_relative_symbol_is_clean(self) -> None:
        result = match(gprel(12, "iGpffffaa7c", 0xAA7C))
        self.assertEqual(verify.wrong_symbol_relocations(result, GP, TABLE), [])

    def test_sibling_gp_symbol_is_flagged(self) -> None:
        # func_003b6da0 named iGpffffb680 where retail stores at -0x5584(gp).
        result = match(gprel(12, "iGpffffb680", 0xAA7C))
        problems = verify.wrong_symbol_relocations(result, GP, TABLE)
        self.assertEqual(len(problems), 1)
        self.assertIn("iGpffffb680", problems[0])
        self.assertIn("0xaa7c", problems[0])

    def test_addend_is_honoured_for_gp_relative(self) -> None:
        # `array[2]` on a gp-relative base: the immediate is base + 8.
        result = match(gprel(20, "iGpffffb2e4", 0xB2EC, addend=8))
        self.assertEqual(verify.wrong_symbol_relocations(result, GP, TABLE), [])

    def test_symbol_beyond_gp_reach_is_flagged_even_when_low_half_agrees(self) -> None:
        # D_008872F8 - gp = 0x11E208: low half 0xE208 agrees with a float at
        # 0x7672F8, but no symbol that far from gp can be the one retail used.
        result = match(gprel(72, "D_008872F8", 0xE208))
        problems = verify.wrong_symbol_relocations(result, GP, TABLE)
        self.assertEqual(len(problems), 1)
        self.assertIn("out of reach", problems[0])

    def test_hi_lo_pair_with_offset_is_clean(self) -> None:
        # D_008872E0[0x2CA4 / 4] = 0x00889F84: %lo is 0x9F84 (negative as s16),
        # so the linker carries and %hi is 0x0089, not 0x0088.
        result = match(hi(0, "D_008872E0", 0x0089), lo(8, "D_008872E0", 0x9F84, addend=0x2CA4))
        self.assertEqual(verify.wrong_symbol_relocations(result, GP, TABLE), [])

    def test_hi_lo_pair_carries_into_high_half(self) -> None:
        # base 0x0088F000 + 0x1000 = 0x00890000: %hi must be 0x0089, %lo 0x0000.
        table = {"D_0088F000": 0x0088F000}
        result = match(hi(0, "D_0088F000", 0x0089), lo(4, "D_0088F000", 0x0000, addend=0x1000))
        self.assertEqual(verify.wrong_symbol_relocations(result, GP, table), [])
        wrong = match(hi(0, "D_0088F000", 0x0088), lo(4, "D_0088F000", 0x0000, addend=0x1000))
        self.assertEqual(len(verify.wrong_symbol_relocations(wrong, GP, table)), 1)

    def test_wrong_table_index_is_flagged(self) -> None:
        # func_003c9940 read D_008873F8[0x46] where retail reads D_008873F8[0].
        result = match(hi(44, "D_008873F8", 0x0088), lo(48, "D_008873F8", 0x73F8, addend=0x118))
        problems = verify.wrong_symbol_relocations(result, GP, TABLE)
        self.assertEqual(len(problems), 1)
        self.assertIn("%lo(D_008873F8+0x118)", problems[0])

    def test_unresolvable_symbol_is_skipped(self) -> None:
        result = match(gprel(0, "sceneState", 0x1234), lo(8, "sceneTable", 0x5678))
        self.assertEqual(verify.wrong_symbol_relocations(result, GP, TABLE), [])

    def test_only_match_rows_are_considered_by_main_contract(self) -> None:
        import contextlib
        import io
        import tempfile
        from unittest.mock import patch

        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            target = {"elf": {"sha1": "fixture"}}
            windows = {"program": "SLUS_217.82", "sha1": "fixture", "windows": {}}
            for status in ("MATCH", "MISMATCH", "NONMATCHING", "ASM", "STUB"):
                with self.subTest(status=status):
                    result = dict(status=status, file="src/example.c", name="example",
                                  addr="00100000", relocations=[gprel(0, "iGpffffb680", 0xAA7C)])
                    output = io.StringIO()
                    with contextlib.ExitStack() as stack:
                        stack.enter_context(patch.object(verify, "REPO", root))
                        stack.enter_context(patch.object(sys, "argv", ["verify.py", str(root / "example.c")]))
                        stack.enter_context(patch.object(verify, "load_config", return_value={"retail_elf": "fixture"}))
                        stack.enter_context(patch.object(verify, "_read_json", side_effect=[target, windows]))
                        stack.enter_context(patch.object(verify, "RetailElf"))
                        stack.enter_context(patch.object(verify, "verify_file", return_value=[result]))
                        stack.enter_context(patch.object(verify, "symbol_addresses", return_value=(GP, TABLE)))
                        stack.enter_context(contextlib.redirect_stdout(output))
                        with self.assertRaises(SystemExit) as exit:
                            verify.main()
                    self.assertEqual(exit.exception.code, int(status in {"MATCH", "MISMATCH"}))
                    self.assertEqual("WRONG SYMBOL:" in output.getvalue(), status == "MATCH")


if __name__ == "__main__":
    unittest.main()
