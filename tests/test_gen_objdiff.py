from __future__ import annotations

import importlib.util
import json
import os
import struct
import sys
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "gen_objdiff.py"
SPEC = importlib.util.spec_from_file_location("p4_gen_objdiff", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
gen = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(gen)

sys.path.insert(0, str(REPO / "tools"))
from verify import ObjectFile  # noqa: E402  (REPO-relative import, no config needed)


def _write_object(tmpdir: Path, name: str, code: bytes,
                  relocations: list[dict], e_flags: int = 0x20924001) -> Path:
    path = tmpdir / f"{name}.o"
    path.write_bytes(gen.build_elf_object(code, relocations, name, e_flags))
    return path


class ElfObjectBuilderTests(unittest.TestCase):
    def test_roundtrip_preserves_bytes_relocations_and_flags(self) -> None:
        code = bytes(range(16)) * 4  # 64 bytes, 4-aligned
        relocations = [
            {"offset": 0, "r_type": 7, "symbol": "iGpffffa090"},
            {"offset": 8, "r_type": 4, "symbol": "func_00123456"},
            {"offset": 12, "r_type": 5, "symbol": "D_00711708"},
        ]
        import verify
        with tempfile.TemporaryDirectory() as directory:
            path = _write_object(Path(directory), "myFunc", code, relocations)
            obj = ObjectFile(path)
            body, parsed = obj.function("myFunc")
            flags = gen._elf_flags(obj.data)
        self.assertEqual(body, code)
        self.assertEqual(len(parsed), len(relocations))
        for expect, actual in zip(relocations, parsed):
            self.assertEqual(actual["offset"], expect["offset"])
            self.assertEqual(actual["r_type"], expect["r_type"])
            self.assertEqual(actual["symbol"], expect["symbol"])
        self.assertEqual(flags, 0x20924001)

    def test_sections_and_symbol_layout(self) -> None:
        import verify
        with tempfile.TemporaryDirectory() as directory:
            path = _write_object(Path(directory), "f", b"\0" * 8, [], e_flags=0x00920000)
            data = path.read_bytes()
            endian, sections = verify.elf_sections(data)
            obj = ObjectFile(path)
        self.assertEqual(endian, "<")
        names = [section["name"] for section in sections]
        self.assertEqual(names, ["", ".text", ".rel.text", ".symtab", ".strtab", ".shstrtab"])
        text = next(section for section in sections if section["name"] == ".text")
        self.assertEqual(text["type"], 1)          # SHT_PROGBITS
        self.assertEqual(text["flags"], 6)         # SHF_ALLOC | SHF_EXECINSTR
        self.assertEqual(text["size"], 8)
        symtab = next(section for section in sections if section["name"] == ".symtab")
        self.assertEqual(symtab["info"], 1)        # first non-local symbol
        symbol = next(symbol for symbol in obj.symbols if symbol["name"] == "f")
        self.assertEqual(symbol["info"], 0x12)     # STB_GLOBAL | STT_FUNC
        self.assertEqual(symbol["size"], 8)
        self.assertEqual(symbol["shndx"], 1)

    def test_reloc_self_reference_uses_function_symbol(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            path = _write_object(Path(directory), "rec", b"\0" * 8,
                                 [{"offset": 0, "r_type": 4, "symbol": "rec"}])
            obj = ObjectFile(path)
            _, parsed = obj.function("rec")
        self.assertEqual([reloc["symbol"] for reloc in parsed], ["rec"])

    def test_undefined_refs_are_preserved(self) -> None:
        code = b"\0" * 4
        with tempfile.TemporaryDirectory() as directory:
            path = _write_object(Path(directory), "caller", code,
                                 [{"offset": 0, "r_type": 4, "symbol": "callee"}])
            obj = ObjectFile(path)
            body, parsed = obj.function("caller")
            symbols = [symbol["name"] for symbol in obj.symbols if symbol["size"] == 0]
        self.assertEqual(body, code)
        self.assertEqual(parsed[0]["symbol"], "callee")
        self.assertIn("callee", symbols)


class SliceTests(unittest.TestCase):
    def test_slice_keeps_only_the_function(self) -> None:
        # A compiled TU object: two functions, each in its own .text with relocs.
        code_a = b"\x11" * 16
        code_b = b"\x22" * 8
        with tempfile.TemporaryDirectory() as directory:
            tmp = Path(directory)
            tu_path = _write_object(tmp, "funcA", code_a,
                                    [{"offset": 0, "r_type": 4, "symbol": "funcB"}],
                                    e_flags=0x20924001)
            # Append funcB into the same object is not supported by the single-
            # function builder, so slice from the single-function object and
            # verify the slice still resolves funcB as an undefined reference.
            obj = ObjectFile(tu_path)
            sliced = gen.slice_function_object(obj, "funcA")
            slice_path = tmp / "slice.o"
            slice_path.write_bytes(sliced)
            parsed = ObjectFile(slice_path)
            body, relocations = parsed.function("funcA")
        self.assertEqual(body, code_a)
        self.assertEqual([reloc["symbol"] for reloc in relocations], ["funcB"])
        self.assertEqual(gen._elf_flags(sliced), 0x20924001)
        self.assertEqual(len(parsed.symbols), 3)  # null, funcA, undefined funcB


class UnitBuildingTests(unittest.TestCase):
    def test_plain_file_unit_naming(self) -> None:
        # Any src file with a FUN marker works: every file is a whole
        # translation unit, so each function gets a per-function slice object.
        import verify
        candidate = None
        for path in sorted((REPO / "src").rglob("*.c")):
            if path.name.endswith(".match.c") or path.name.startswith(".permute_"):
                continue
            if "generated" in path.parts:
                continue
            if verify.scan_markers(path):
                candidate = path
                break
        self.assertIsNotNone(candidate, "test requires a src file with a FUN marker")
        markers = verify.scan_markers(candidate)
        self.assertTrue(markers, f"test requires a FUN marker in {candidate}")
        marker = markers[0]
        relative = candidate.relative_to(REPO).as_posix()
        stem = relative[len("src/"):-2]  # strip src/ and .c
        units = gen.build_units([dict(
            file=relative, addr=f"{marker['addr']:08x}", line=marker["line"],
            status="MATCH", name=marker["name"])])
        unit = units[0]
        self.assertEqual(unit["name"], f"{stem}:{marker['addr']:08X}")
        self.assertEqual(unit["base_path"],
                         f"build/objdiff/base/{stem}/{marker['addr']:08x}.o")
        self.assertEqual(unit["target_path"],
                         f"build/objdiff/target/{stem}/{marker['addr']:08x}.o")

    def test_config_units_have_exactly_the_schema_keys(self) -> None:
        units = gen.build_units([dict(
            file="src/Battle/battle.c", addr="00192560", line=10,
            status="NONMATCHING", name="func_00192560")])
        unit = units[0]
        self.assertEqual(sorted(unit.keys()),
                         sorted(("name", "target_path", "base_path", "metadata",
                                 "file", "addr", "symbol", "window",
                                 "status")))
        config_unit = {key: unit[key] for key in gen.CONFIG_UNIT_KEYS}
        self.assertEqual(sorted(config_unit.keys()),
                         sorted(("name", "target_path", "base_path", "metadata")))
        self.assertFalse(config_unit["metadata"]["complete"])

    def test_sourceless_function_still_gets_a_unit(self) -> None:
        # A canonical function with no C source must still appear in the config:
        # base_path null (nothing to build), complete false (never matched), and
        # a target_path so objdiff counts its code in the denominator.
        windows = {"00100008": 528, "00100218": 512, "00100220": 48}
        units = gen.build_canonical_units(windows, covered=set())
        self.assertEqual(len(units), 3)
        unit = units[0]
        self.assertEqual(unit["name"], "nonmatchings:00100008")
        self.assertEqual(unit["target_path"],
                         "build/objdiff/target/nonmatchings/00100008.o")
        self.assertIsNone(unit["base_path"])
        self.assertFalse(unit["metadata"]["complete"])
        self.assertEqual(unit["window"], 528)
        self.assertIsNone(unit["file"])
        self.assertIsNone(unit["symbol"])

    def test_canonical_units_complete_the_coverage(self) -> None:
        # Merging report units with canonical units must yield exactly one unit
        # per canonical function, with source-less ones base_path null.
        windows = {"00100008": 528, "00100218": 512}
        reported = gen.build_units([dict(
            file="src/Battle/battle.c", addr="00100218", line=10,
            status="MATCH", name="func_00100218")])
        covered = {unit["addr"] for unit in reported}
        merged = reported + gen.build_canonical_units(windows, covered)
        self.assertEqual(len(merged), len(windows))
        by_addr = {unit["addr"]: unit for unit in merged}
        self.assertIsNone(by_addr[0x00100008]["base_path"])
        self.assertEqual(by_addr[0x00100218]["base_path"],
                         "build/objdiff/base/Battle/battle/00100218.o")

    def test_asm_function_is_not_counted_as_matched(self) -> None:
        # An INCLUDE_ASM fallback is byte-correct by construction; if it were
        # marked complete, objdiff would score it 100% matched and progress
        # would be inflated by assembly that is not decompiled C.
        units = gen.build_units([dict(
            file="src/Kosaka/k_vpad.c", addr="004b5800", line=164,
            status="ASM", name="func_004b5800")])
        unit = units[0]
        self.assertFalse(unit["metadata"]["complete"])
        self.assertEqual(unit["status"], "ASM")
        matched = gen.build_units([dict(
            file="src/Kosaka/k_vpad.c", addr="004b5c20", line=10,
            status="MATCH", name="func_004b5c20")])
        self.assertTrue(matched[0]["metadata"]["complete"])

    def test_progress_categories_split_first_and_third_party(self) -> None:
        """The three attribution categories partition every unit exactly once.

        They are mutually exclusive by construction -- a unit is first-party,
        middleware, or not yet attributed -- so a badge over one of them has a
        meaningful denominator. `linked` is deliberately NOT one of them: it is
        additive, carried alongside whichever attribution category a unit has,
        because being linked into the byte-exact image is orthogonal to which
        source owns the function.
        """
        ids = [c["id"] for c in gen.PROGRESS_CATEGORIES]
        self.assertEqual(ids[:3], ["main", "third_party", "unclassified"])
        self.assertIn("linked", ids)
        self.assertEqual(gen.progress_category("src/Battle/btlTarget.c"), "main")
        self.assertEqual(gen.progress_category("src/rw/rwcore.c"), "third_party")
        self.assertEqual(gen.progress_category("src/cri/cri_adx.c"), "third_party")
        self.assertEqual(gen.progress_category("src/sce/libcdvd.c"), "third_party")
        # A source-less unit cannot be attributed to either side. Folding it
        # into "main" would inflate the first-party denominator with ~11,000
        # untouched middleware functions AND leave "third_party" containing
        # only the middleware already finished, reading 100% complete. Both
        # published numbers stay meaningful only if these get their own bucket.
        self.assertEqual(gen.progress_category(None), "unclassified")
        # The config carries the categories and every unit is tagged.
        units = gen.build_units([dict(
            file="src/rw/rwcore.c", addr="0038fb10", line=10,
            status="NONMATCHING", name="func_0038fb10")])
        units.extend(gen.build_canonical_units({"00100008": 528}, set()))
        for unit in units:
            unit["metadata"]["progress_categories"] = [gen.progress_category(unit["file"])]
        self.assertEqual(units[0]["metadata"]["progress_categories"], ["third_party"])
        # build_canonical_units emits the source-less remainder, which is
        # exactly the population that must not be silently counted as either.
        self.assertEqual(units[1]["metadata"]["progress_categories"], ["unclassified"])

    def test_linked_addresses_falls_back_to_the_committed_endpoint(self) -> None:
        """A missing build artifact must not silently publish an empty category.

        CI regenerates objdiff.json in a job that never runs the linker, so
        build/linked_report.json is absent there. When the category was declared
        but tagged zero units, decomp.dev rendered the badge as "0 / 0", which
        reads as a real measurement rather than as missing data. The committed
        progress/metrics.json endpoint is therefore the fallback, and it is
        present in every checkout.
        """
        from_metrics = gen.linked_addresses(None)
        self.assertTrue(from_metrics, "committed progress/metrics.json yielded no linked addresses")
        # A named-but-absent artifact must degrade to the same fallback, never to
        # an empty set, and never raise.
        self.assertEqual(gen.linked_addresses("build/does-not-exist.json"), from_metrics)
        # Every address is a real canonical function address, not a stray token.
        self.assertTrue(all(isinstance(a, int) and 0 < a < 0x8000000 for a in from_metrics))


class TrimWindowPaddingTests(unittest.TestCase):
    def test_all_zero_tail_is_trimmed_for_complete_units(self) -> None:
        # 12 bytes of code followed by 8 zero padding bytes: verify.py's
        # `not any(tail)` MATCH criterion says the padding is not the function.
        window = b"\x08\x00\xe0\x03" * 3 + b"\0" * 8
        self.assertEqual(gen.trim_window_padding(window, 12, True), window[:12])

    def test_nonzero_tail_is_kept_for_complete_units(self) -> None:
        # A non-zero byte past our function's end is real content (owned data
        # or an unmarked sibling function); never trim it away.
        window = b"\x08\x00\xe0\x03" * 3 + b"\x00\x00\x00\x00\x21\x00\x00\x00"
        self.assertEqual(gen.trim_window_padding(window, 12, True), window)

    def test_noncomplete_units_keep_the_full_window(self) -> None:
        # Units the verifier does not report MATCH (ASM, NONMATCHING, ...)
        # keep current behaviour: the full window, differences visible.
        window = b"\x08\x00\xe0\x03" * 3 + b"\0" * 8
        self.assertEqual(gen.trim_window_padding(window, 12, False), window)

    def test_window_at_or_below_body_length_is_untouched(self) -> None:
        body = b"\x08\x00\xe0\x03" * 4
        self.assertEqual(gen.trim_window_padding(body, 16, True), body)
        self.assertEqual(gen.trim_window_padding(body[:12], 16, True), body[:12])
        self.assertEqual(gen.trim_window_padding(body, 0, True), body)

    def test_trimmed_window_roundtrips_through_object_builder(self) -> None:
        window = b"\x08\x00\xe0\x03" * 3 + b"\0" * 8
        trimmed = gen.trim_window_padding(window, 12, True)
        with tempfile.TemporaryDirectory() as directory:
            path = _write_object(Path(directory), "f", trimmed, [])
            obj = ObjectFile(path)
            body, _ = obj.function("f")
        self.assertEqual(body, window[:12])


class EmitHelpersTests(unittest.TestCase):
    def test_select_units_matches_name_and_paths(self) -> None:
        units = [
            dict(name="Battle/btlTarget:001EC630",
                 base_path="build/objdiff/base/Battle/btlTarget_unit_001ec630.o",
                 target_path="build/objdiff/target/Battle/btlTarget_unit_001ec630.o"),
            dict(name="Battle/battle:00192560",
                 base_path="build/objdiff/base/Battle/battle_unit_00192560.o",
                 target_path="build/objdiff/target/Battle/battle_unit_00192560.o"),
        ]
        self.assertEqual(len(gen.select_units(units, "btlTarget")), 1)
        self.assertEqual(len(gen.select_units(units, "battle_unit_00192560")), 1)
        self.assertEqual(len(gen.select_units(units, "Battle/")), 2)
        self.assertEqual(gen.select_units(units, "nope"), [])

    def test_current_checks_mtime_and_size(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "out.o"
            dep = Path(directory) / "dep.c"
            dep.write_text("x")
            dep_mtime = dep.stat().st_mtime
            self.assertFalse(gen._current(path, dep_mtime))  # missing
            path.write_bytes(b"data")
            self.assertTrue(gen._current(path, dep_mtime))
            # Future dependency makes it stale.
            future = dep_mtime + 1000
            self.assertFalse(gen._current(path, future))
            path.write_bytes(b"")
            self.assertFalse(gen._current(path, dep_mtime))  # empty

    def test_install_bytes_is_atomic_and_creates_parents(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "nested" / "dir" / "out.o"
            gen._install_bytes(b"\x7fELF", path)
            self.assertEqual(path.read_bytes(), b"\x7fELF")
            leftover = list(Path(directory).rglob(".objdiff-*"))
            self.assertEqual(leftover, [])


if __name__ == "__main__":
    unittest.main()


class TranslationUnitCategoryTests(unittest.TestCase):
    """A source-less function can still be categorised from its __FILE__ TU.

    The compiler left an assert-macro filename in the image naming the original
    translation unit. That attribution exists for functions nobody has
    decompiled yet, which is exactly the population that would otherwise sit in
    `unclassified` and make both published percentages meaningless.
    """

    def test_name_matching_a_first_party_file_resolves_to_main(self) -> None:
        self.assertEqual(gen.progress_category(None, "btlTarget.c"), "main")

    def test_name_matching_a_middleware_file_resolves_to_third_party(self) -> None:
        self.assertEqual(gen.progress_category(None, "rwcore.c"), "third_party")

    def test_path_escaping_the_repository_is_middleware(self) -> None:
        """`../../rofs_mai.c` came from an SDK include outside the game sources."""
        self.assertEqual(gen.progress_category(None, "../../rofs_mai.c"), "third_party")

    def test_unresolvable_name_stays_unclassified(self) -> None:
        """Guessing from the look of a name is what this category prevents."""
        self.assertIsNone(gen.resolve_tu_name("definitelyNotAFileInEitherTree.c"))
        self.assertEqual(
            gen.progress_category(None, "definitelyNotAFileInEitherTree.c"), "unclassified")

    def test_no_tu_name_stays_unclassified(self) -> None:
        self.assertEqual(gen.progress_category(None, None), "unclassified")

    def test_own_source_file_wins_over_the_tu_name(self) -> None:
        """A unit with real source is classified by that source, not the span."""
        self.assertEqual(gen.progress_category("src/rw/rwcore.c", "btlTarget.c"),
                         "third_party")
