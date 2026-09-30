"""Retail-derived native-32 contract checks for the community-menu renderer.

The production body and three actual scalar/vector/forwarding providers are
included unchanged. A separate raw-offset model checks every rendering pass,
ordered call payload, live reload, captured value, and context/palette mutation.
This is C semantic coverage, not EE/GPU emulation or an instruction-match claim.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q

MENU = ROOT / "src/promoted/code1_0035.c"
NUMBER = ROOT / "src/promoted/code1_002b.c"
FIXTURE = ROOT / "tests/community_menu_renderer_fixture.c.in"


def replace_once(source: str, old: str, new: str) -> str:
    if source.count(old) != 1:
        raise AssertionError(f"Expected one mutation site for {old!r}")
    return source.replace(old, new)


def fixture_source(target: str | None = None, providers: str | None = None) -> str:
    source = MENU.read_text(encoding="utf-8")
    bodies = Q.function_bodies(MENU)
    body = bodies["func_00356a10"][1] if target is None else target
    if "INCLUDE_ASM" in body or "NON_MATCHING" in body:
        raise AssertionError("The contract fixture requires active renderer C")
    support = providers if providers is not None else "\n".join(
        [bodies[name][1] for name in ("func_00355410", "func_0035c670")]
        + [Q.function_bodies(NUMBER)["func_002bc0b0"][1]])
    address_helper = re.search(r"static inline u32 add_offset_first\([^}]+\}", source)
    if address_helper is None:
        raise AssertionError("The target-width address helper is missing")
    number_decl = re.search(r"extern s32 func_002bc0e0\([^;]+;", NUMBER.read_text(encoding="utf-8"))
    if number_decl is None:
        raise AssertionError("The actual number-provider declaration is missing")
    return (RUNTIME_C + '\n#include "shd_misc_internal.h"\n'
            + '_Static_assert(sizeof(Vec2f) == 8, "two-coordinate output");\n'
            + address_helper.group(0) + "\n" + number_decl.group(0) + "\n"
            + support + "\n" + body + "\n" + FIXTURE.read_text(encoding="utf-8") + ENTRY_C)


class CommunityMenuSourceContracts(unittest.TestCase):
    def test_byte_opacity_and_vector_contracts_are_coherent(self):
        source = MENU.read_text(encoding="utf-8")
        self.assertIn("// FUN_00356A10\n", source)
        self.assertNotIn("// FUN_00356A10 NONMATCHING", source)
        for name in ("func_00355410", "func_0035aff0", "func_0035c040"):
            self.assertRegex(source, r"(?:void|f32) " + name + r"\(u8 \*arg0, u8 arg1\)")
        for owner in (ROOT / "src/Camp/cmpPersona.c", ROOT / "src/promoted/code1_0014.c"):
            self.assertRegex(owner.read_text(encoding="utf-8"),
                             r"extern\s+void\s+func_00355410\(u8\s*\*\s*\w+,\s*u8\s+\w+\);")
        self.assertIn("void func_0035c670(u8 *arg0, Vec2f *position)", source)
        self.assertIn("Entries are initialized by func_00356250 with display modes 0 through 3", source)
        self.assertIn("// FUN_0035AFF0 NONMATCHING", source)


class CommunityMenuNativeContracts(unittest.TestCase):
    def runtime(self):
        try:
            return native32_runtime()
        except Native32Unavailable as exc:
            self.skipTest(str(exc))

    def test_full_call_timeline_and_actual_tiny_providers(self):
        runtime = self.runtime()
        text = fixture_source()
        outputs = []
        with tempfile.TemporaryDirectory(prefix="p4_community_menu_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(text, encoding="utf-8")
            for optimization in ("-O0", "-O2"):
                binary = runtime.compile(source, directory / optimization[1:], optimization,
                                         (ROOT / "include",))
                result = runtime.run(binary)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn("PASS scenarios=3360", result.stdout)
                outputs.append(result.stdout)
        self.assertEqual(outputs[0], outputs[1])

    def test_model_rejects_semantic_regressions(self):
        runtime = self.runtime()
        body = Q.function_bodies(MENU)["func_00356a10"][1]
        support = "\n".join([Q.function_bodies(MENU)[name][1]
                               for name in ("func_00355410", "func_0035c670")]
                              + [Q.function_bodies(NUMBER)["func_002bc0b0"][1]])
        mutants = {
            "opacity": fixture_source(replace_once(body, "globalOpacity = globalAlphaFloat / 255.0f;",
                                                   "globalOpacity = globalAlphaFloat / 256.0f;")),
            "rectangle": fixture_source(replace_once(body, "rectangle.integer[3] = 3;",
                                                     "rectangle.integer[3] = 2;")),
            "live_name": fixture_source(replace_once(body, "func_00246830(*nameId)",
                                                     "func_00246830((s16)*nameId)")),
            "retained_texture": fixture_source(replace_once(body, "func_0034f2e0(tileTexture, cellX, cellY",
                                                            "func_0034f2e0(menu->resource11D4, cellX, cellY")),
            "vector_y": fixture_source(providers=replace_once(support,
                "*position = *(Vec2f *)(*(u8 **)(arg0 + 0x38));",
                "position->x = (*(Vec2f *)(*(u8 **)(arg0 + 0x38))).x;\n    position->y = position->x;")),
            "float_forwarding": fixture_source(providers=replace_once(support,
                "func_002bc0e0(x, y, depth, color, font, mode, 1, table, item);",
                "func_002bc0e0(x, x, depth, color, font, mode, 1, table, item);")),
        }
        with tempfile.TemporaryDirectory(prefix="p4_community_menu_negative_") as directory:
            directory = Path(directory)
            for name, text in mutants.items():
                with self.subTest(name=name):
                    source = directory / (name + ".c")
                    source.write_text(text, encoding="utf-8")
                    binary = runtime.compile(source, directory / name, "-O2", (ROOT / "include",))
                    result = runtime.run(binary)
                    self.assertNotEqual(result.returncode, 0, name + ": regression was not observed")


if __name__ == "__main__":
    unittest.main()
