from __future__ import annotations

import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "apply_symbol_names.py"
SPEC = importlib.util.spec_from_file_location("p4_apply_names", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
apply_names = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(apply_names)

RECONCILE_PATH = REPO / "tools" / "reconcile_function_boundaries.py"
RECON_SPEC = importlib.util.spec_from_file_location("p4_reconcile_test", RECONCILE_PATH)
assert RECON_SPEC is not None and RECON_SPEC.loader is not None
reconcile = importlib.util.module_from_spec(RECON_SPEC)
RECON_SPEC.loader.exec_module(reconcile)


def names_file(text: str) -> Path:
    """Write a curated-names file into a scratch directory and return it."""
    scratch = Path(tempfile.mkdtemp(prefix="p4names_"))
    path = scratch / "symbol_names.test.txt"
    path.write_text(text, encoding="utf-8")
    return path


def make_root(base: Path) -> Path:
    """A minimal repo-shaped root: canonical windows + empty config/src."""
    root = base / "root"
    (root / "tools").mkdir(parents=True)
    (root / "config").mkdir()
    (root / "src").mkdir()
    windows = {
        "001059e0": 0x60,
        "0028f960": 0x40,
        "002e2080": 0x20,
        "0043f9c8": 0x20,
    }
    (root / "tools" / "slus21782_functions.json").write_text(
        json.dumps({"windows": windows}), encoding="utf-8"
    )
    return root


def write_curated(root: Path, lines: str) -> None:
    (root / "config" / "symbol_names.txt").write_text(lines, encoding="utf-8")


CANONICAL = {0x001059E0, 0x0028F960, 0x002E2080, 0x0043F9C8}


class LoadNamesTests(unittest.TestCase):
    def test_accepts_valid_curated_set(self) -> None:
        path = names_file(
            "btlLevelFromExp = 0x001059E0; // type:func  evidence: p3:Foo@0x16d280\n"
            "fclLerp = 0x0028F960; // type:func  evidence: file:mt_evtLoadSave.c\n"
        )
        self.assertEqual(
            apply_names.load_names([path], CANONICAL),
            {0x001059E0: "btlLevelFromExp", 0x0028F960: "fclLerp"},
        )

    def test_comments_and_blank_lines_ignored(self) -> None:
        path = names_file(
            "// evidence-backed Persona 4 names\n"
            "\n"
            "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n"
        )
        self.assertEqual(apply_names.load_names([path], CANONICAL), {0x001059E0: "btlLevelFromExp"})

    def test_rejects_malformed_line(self) -> None:
        path = names_file("btlLevelFromExp = 0x001059E0\n")  # no `; // type:func`
        with self.assertRaisesRegex(RuntimeError, "expected `name = 0xADDR"):
            apply_names.load_names([path], CANONICAL)

    def test_rejects_missing_evidence(self) -> None:
        path = names_file("btlLevelFromExp = 0x001059E0; // type:func  looks plausible\n")
        with self.assertRaisesRegex(RuntimeError, "no `evidence:` note"):
            apply_names.load_names([path], CANONICAL)

    def test_rejects_placeholder_name(self) -> None:
        for bad in ("func_001059e0", "FUN_001059E0"):
            with self.subTest(name=bad):
                path = names_file(
                    f"{bad} = 0x001059E0; // type:func  evidence: file:g_data.c\n"
                )
                with self.assertRaisesRegex(RuntimeError, "is a placeholder"):
                    apply_names.load_names([path], CANONICAL)

    def test_rejects_non_canonical_address(self) -> None:
        path = names_file("mystery = 0x00DEAD00; // type:func  evidence: file:g_data.c\n")
        with self.assertRaisesRegex(RuntimeError, "not a canonical boundary"):
            apply_names.load_names([path], CANONICAL)

    def test_rejects_duplicate_address(self) -> None:
        path = names_file(
            "first = 0x001059E0; // type:func  evidence: file:g_data.c\n"
            "second = 0x001059E0; // type:func  evidence: file:g_data.c\n"
        )
        with self.assertRaisesRegex(RuntimeError, "duplicate address"):
            apply_names.load_names([path], CANONICAL)

    def test_rejects_duplicate_name(self) -> None:
        path = names_file(
            "shared = 0x001059E0; // type:func  evidence: file:g_data.c\n"
            "shared = 0x0028F960; // type:func  evidence: file:mt_evtLoadSave.c\n"
        )
        with self.assertRaisesRegex(RuntimeError, "already used for"):
            apply_names.load_names([path], CANONICAL)

    def test_contract_patterns_lockstep_with_reconcile(self) -> None:
        self.assertEqual(apply_names.NAME_LINE.pattern, reconcile.NAME_LINE.pattern)
        self.assertEqual(apply_names.PLACEHOLDER.pattern, reconcile.PLACEHOLDER.pattern)

    def test_agrees_with_reconcile_curated_names(self) -> None:
        """Both parsers must accept exactly the same curated set."""
        with tempfile.TemporaryDirectory() as temporary:
            config = Path(temporary) / "config"
            config.mkdir()
            curated = config / "symbol_names.txt"
            curated.write_text(
                "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n"
                "fclLerp = 0x0028F960; // type:func  evidence: p3:Foo@0x1234\n",
                encoding="utf-8",
            )
            reconcile.CURATED_NAMES = curated
            expected = reconcile.curated_names(CANONICAL)
            self.assertEqual(
                apply_names.load_names([curated], CANONICAL), expected
            )


def sample_source() -> str:
    return (
        "/* Source unit: src/g_data_001059e0.c */\n"
        "\n"
        "#include \"type.h\"\n"
        "\n"
        "// FUN_001059E0\n"
        "u8 func_001059e0(s32 exp)  // func_001059e0 trailing comment\n"
        "{\n"
        "    const char* note = \"func_001059e0 string\";\n"
        "    return func_001059e0 ? (u8)func_001059e0(exp) : 0;\n"
        "}\n"
    )


class PlanAndRewriteTests(unittest.TestCase):
    def setUp(self) -> None:
        self.names = {0x001059E0: "btlLevelFromExp"}

    def test_marker_line_survives_byte_for_byte(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "g_data.c"
            original = sample_source().encode("utf-8")
            path.write_bytes(original)
            changes = apply_names.plan_file(path, self.names)
            self.assertEqual(apply_names.rewrite(path, changes), 3)
            lines = path.read_bytes().decode("utf-8").split("\n")
            # marker line untouched, definition renamed
            self.assertEqual(lines[4], "// FUN_001059E0")
            self.assertTrue(lines[5].startswith("u8 btlLevelFromExp(s32 exp)"))
            # trailing comment on the definition line untouched
            self.assertTrue(lines[5].endswith("// func_001059e0 trailing comment"))
            # string literal untouched, code occurrences renamed
            self.assertIn('"func_001059e0 string"', "\n".join(lines))
            self.assertIn("return btlLevelFromExp ? (u8)btlLevelFromExp(exp) : 0;", "\n".join(lines))
            # marker line remains address-form, no guard wrapper remains
            self.assertNotIn("#if defined", "\n".join(lines))

    def test_marker_line_with_nonmatching_suffix_survives(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "mt_evtLoadSave.c"
            path.write_text(
                "// FUN_0028F960 NONMATCHING\n"
                "float func_0028f960(float a)\n"
                "{\n"
                "    return func_0028f960(a) + 1.0f;\n"
                "}\n",
                encoding="utf-8",
            )
            changes = apply_names.plan_file(path, {0x0028F960: "fclLerp"})
            apply_names.rewrite(path, changes)
            self.assertEqual(
                path.read_text(encoding="utf-8"),
                "// FUN_0028F960 NONMATCHING\n"
                "float fclLerp(float a)\n"
                "{\n"
                "    return fclLerp(a) + 1.0f;\n"
                "}\n",
            )

    def test_no_substring_renames(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "boundaries.c"
            path.write_text(
                "u8 func_001059e0(s32 exp);\n"
                "u8 func_001059e01(s32 exp);\n"
                "u8 xfunc_001059e0(s32 exp);\n"
                "u8 func_001059e0_2(s32 exp);\n"
                "u8 func_001059e0x(s32 exp);\n",
                encoding="utf-8",
            )
            changes = apply_names.plan_file(path, self.names)
            self.assertEqual(len(changes), 1)
            apply_names.rewrite(path, changes)
            self.assertEqual(
                path.read_text(encoding="utf-8"),
                "u8 btlLevelFromExp(s32 exp);\n"
                "u8 func_001059e01(s32 exp);\n"
                "u8 xfunc_001059e0(s32 exp);\n"
                "u8 func_001059e0_2(s32 exp);\n"
                "u8 func_001059e0x(s32 exp);\n",
            )

    def test_uppercase_hex_placeholder_renamed_but_uppercase_FUN_not(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "mixed.c"
            path.write_text(
                "extern u8 func_001059E0(s32 exp);\n"
                "extern void FUN_0043f9c8(u32 dest, int value, u32 size);\n"
                "u8 call(void) { return func_001059E0(1); }\n",
                encoding="utf-8",
            )
            changes = apply_names.plan_file(path, self.names)
            self.assertEqual(len(changes), 2)
            apply_names.rewrite(path, changes)
            self.assertEqual(
                path.read_text(encoding="utf-8"),
                "extern u8 btlLevelFromExp(s32 exp);\n"
                "extern void FUN_0043f9c8(u32 dest, int value, u32 size);\n"
                "u8 call(void) { return btlLevelFromExp(1); }\n",
            )

    def test_crlf_line_endings_preserved(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "crlf.c"
            original = (
                "// FUN_001059E0\r\n"
                "u8 func_001059e0(s32 exp)\r\n"
                "{\r\n"
                "    return 0;\r\n"
                "}\r\n"
            ).encode("utf-8")
            path.write_bytes(original)
            changes = apply_names.plan_file(path, self.names)
            apply_names.rewrite(path, changes)
            self.assertEqual(
                path.read_bytes(),
                (
                    "// FUN_001059E0\r\n"
                    "u8 btlLevelFromExp(s32 exp)\r\n"
                    "{\r\n"
                    "    return 0;\r\n"
                    "}\r\n"
                ).encode("utf-8"),
            )

    def test_idempotent(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "g_data.c"
            path.write_bytes(sample_source().encode("utf-8"))
            first = apply_names.plan_file(path, self.names)
            apply_names.rewrite(path, first)
            applied = path.read_bytes()
            self.assertEqual(apply_names.plan_file(path, self.names), [])
            self.assertEqual(path.read_bytes(), applied)

    def test_unmapped_placeholder_untouched(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "other.c"
            path.write_text("u8 func_002e2080(int* a);\n", encoding="utf-8")
            self.assertEqual(apply_names.plan_file(path, self.names), [])
            self.assertEqual(path.read_text(encoding="utf-8"), "u8 func_002e2080(int* a);\n")


class RunTests(unittest.TestCase):
    def test_check_exits_nonzero_when_unapplied_then_zero_when_applied(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = make_root(Path(temporary))
            write_curated(
                root,
                "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n",
            )
            target = root / "src" / "g_data.c"
            target.write_text(
                "// FUN_001059E0\n"
                "u8 func_001059e0(s32 exp)\n"
                "{\n"
                "    return 0;\n"
                "}\n",
                encoding="utf-8",
            )
            # unapplied tree: --check must report and exit non-zero
            self.assertEqual(apply_names.run(root, [str(target)], check=True), 1)
            # applying succeeds
            self.assertEqual(apply_names.run(root, [str(target)], check=False), 0)
            self.assertIn(
                "u8 btlLevelFromExp(s32 exp)",
                target.read_text(encoding="utf-8"),
            )
            # applied tree: --check exits zero
            self.assertEqual(apply_names.run(root, [str(target)], check=True), 0)

    def test_never_touches_generated(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = make_root(Path(temporary))
            write_curated(
                root,
                "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n",
            )
            generated = root / "src" / "generated" / "code1_0010.c"
            generated.parent.mkdir()
            generated.write_text("u8 func_001059e0(s32 exp) { return 0; }\n", encoding="utf-8")
            self.assertEqual(apply_names.run(root, [str(generated)], check=False), 0)
            self.assertEqual(
                generated.read_text(encoding="utf-8"),
                "u8 func_001059e0(s32 exp) { return 0; }\n",
            )

    def test_whole_tree_scan_finds_pending_renames(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = make_root(Path(temporary))
            write_curated(
                root,
                "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n",
            )
            target = root / "src" / "g_data.c"
            target.write_text("u8 func_001059e0(s32 exp) { return 0; }\n", encoding="utf-8")
            self.assertEqual(apply_names.run(root, [], check=True), 1)
            self.assertEqual(apply_names.run(root, [], check=False), 0)
            self.assertEqual(apply_names.run(root, [], check=True), 0)

    def test_main_returns_exit_codes(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = make_root(Path(temporary))
            write_curated(
                root,
                "btlLevelFromExp = 0x001059E0; // type:func  evidence: file:g_data.c\n",
            )
            target = root / "src" / "g_data.c"
            target.write_text(
                "u8 func_001059e0(s32 exp) { return 0; }\n", encoding="utf-8"
            )
            original_repo = apply_names.REPO
            apply_names.REPO = root
            try:
                self.assertEqual(apply_names.main(["--check", str(target)]), 1)
                self.assertEqual(apply_names.main([str(target)]), 0)
                self.assertEqual(apply_names.main(["--check", str(target)]), 0)
            finally:
                apply_names.REPO = original_repo


if __name__ == "__main__":
    unittest.main()
