"""Exercise the exact map-test and menu provider C with native 32-bit pointers.

The runtime fixture checks menus, every grid row and column, RGBA transport,
callback-visible mutations, and the recovered page-capacity forwarding. Provider
definitions are independently checked against shared headers and caller declarations.
P4_MAP_TEST_ROOT and P4_MAP_TEST_OVERLAY select an uninstalled scratch proposal.
"""
from __future__ import annotations

from contextlib import contextmanager
import os
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(os.environ.get("P4_MAP_TEST_ROOT", Path(__file__).resolve().parents[1])).resolve()
OVERLAY = Path(os.environ.get("P4_MAP_TEST_OVERLAY", ROOT)).resolve()
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q  # noqa: E402
import verify as V  # noqa: E402


def input_path(relative: str) -> Path:
    staged = OVERLAY / relative
    return staged if staged.is_file() else ROOT / relative


OWNER = input_path("src/promoted/code1_0018.c")
PROVIDERS = {
    "func_0014def0": input_path("src/promoted/code1_0014.c"),
    "func_0017d1f0": input_path("src/promoted/code1_0017.c"),
    "func_00155280": input_path("src/promoted/code1_0015.c"),
    "func_001582f0": input_path("src/promoted/code1_0015.c"),
    "func_00450340": input_path("src/sdkDbprt.c"),
    "func_00470250": input_path("src/Kosaka/Field/k_sceneDraw.c"),
    "func_00470280": input_path("src/Kernel/sdkLbox.c"),
    "func_00470810": input_path("src/Kosaka/Field/k_sceneDraw.c"),
    "func_00470bd0": input_path("src/Kosaka/k_view.c"),
    "func_004703c0": input_path("src/Kernel/sdkLbox.c"),
    "func_004703d0": input_path("src/Kernel/sdkLbox.c"),
    "func_00470430": input_path("src/Kernel/sdkLbox.c"),
    "func_00470e20": input_path("src/promoted/code1_0047.c"),
    "func_00452080": input_path("src/Kernel/sdkTask.c"),
    "func_00453fa0": input_path("src/promoted/sdkListState.c"),
    "func_00453e60": input_path("src/promoted/sdkListState.c"),
    "func_004704d0": input_path("src/Kernel/sdkLbox.c"),
}
INTERFACES = {
    "func_0014def0": "void (*)(u8 *, u8 *, f32, f32, f32, f32, f32, u8 *, s32, f32, f32, f32, s32, f32)",
    "func_0017d1f0": "void (*)(u8 *, u8 *, s32, s32, f32, f32, f32, s32)",
    "func_00155280": "s32 *(*)(void)",
    "func_001582f0": "void (*)(s32, s32, s32)",
    "func_00450340": "void (*)(s64, const char *, ...)",
    "func_00470250": "KwlnTask *(*)(KwlnTask *, u32, u32)",
    "func_00470280": "s32 (*)(u8 *, s32, s32, s32)",
    "func_00470810": "void (*)(KwlnTask *, const KWindowEntryDescriptor *, u32)",
    "func_00470bd0": "s32 *(*)(KwlnTask *, u32)",
    "func_004703c0": "void (*)(u8 *, s32)",
    "func_004703d0": "void (*)(u8 *, s32)",
    "func_00470430": "void (*)(u8 *, s32)",
    "func_00470e20": "s32 (*)(u8 *)",
    "func_00452080": "s32 (*)(KwlnTask *)",
    "func_00453fa0": "void (*)(u8 *, s32)",
    "func_00453e60": "s32 (*)(u8 *)",
    "func_004704d0": "void (*)(u8 *)",
}
SHARED_MENU = {
    "func_00470250", "func_00470280", "func_00470810", "func_00470bd0",
    "func_004703c0", "func_004703d0", "func_00470430", "func_00470e20",
}
CALLERS = (OWNER, input_path("src/Kosaka/k_viewer.c"), input_path("src/Kosaka/k_testMenu.c"))
DECLARATION_OWNERS = {
    name: input_path("src/Kernel/sdkLbox.c")
    for name in ("func_00453fa0", "func_00453e60", "func_004704d0")
}
INCLUDES = (OVERLAY / "include", ROOT / "include")


@contextmanager
def fixture_directory(kind: str):
    retained = os.environ.get("P4_MAP_TEST_ARTIFACTS")
    if retained:
        directory = Path(retained).resolve() / kind
        directory.mkdir(parents=True, exist_ok=True)
        yield directory
    else:
        with tempfile.TemporaryDirectory(prefix="p4_map_" + kind + "_") as temporary:
            yield Path(temporary)


def target_parts(owner: Path = OWNER) -> tuple[str, str]:
    text = owner.read_text(encoding="utf-8")
    body = Q.function_bodies(owner)["func_0018e810"][1]
    types = []
    for name in ("PadStatus", "PanelColor", "MapTestCell", "MapTestGrid"):
        found = re.findall(r"\btypedef\s+struct\s*\{[^{}]*\}\s*" + name + r"\s*;", text)
        if len(found) != 1:
            raise AssertionError(f"Expected exactly one local {name} definition")
        types.append(found[0])
    return "\n".join(types), body


def menu_provider_bodies() -> list[str]:
    return [Q.function_bodies(PROVIDERS[name])[name][1]
            for name in ("func_00470250", "func_00470430")]


def map_fixture(owner: Path = OWNER) -> str:
    types, body = target_parts(owner)
    providers = menu_provider_bodies()
    template = Path(__file__).with_name("map_test_fixture.c.in").read_text(encoding="utf-8")
    source = (template.replace("@@TYPES@@", types).replace("@@TARGET@@", body)
              .replace("@@MENU_PROVIDERS@@", "\n\n".join(providers)))
    if "@@" in source:
        raise AssertionError("The map fixture has an unfilled source placeholder")
    for exact in [body, *providers]:
        if source.count(exact) != 1:
            raise AssertionError("Every exact recovered body must occur once without rewriting")
    return RUNTIME_C + source + ENTRY_C


def declarations(text: str, name: str) -> list[str]:
    return re.findall(r"\bextern\s+[^;{}]*\b" + name + r"\s*\([^;{}]*\)\s*;", text)


def type_check(name: str, expected: str, description: str) -> str:
    return (f'_Static_assert(__builtin_types_compatible_p(__typeof__(&{name}), {expected}),\n'
            f'               "{description}");\n')


def signature_fixture(providers: dict[str, Path] = PROVIDERS, owner: Path = OWNER) -> str:
    source = RUNTIME_C + '''
#include "type.h"
#include "sdk_dbprt.h"
#include "sdk_lbox_internal.h"
#pragma clang diagnostic error "-Wstrict-prototypes"
'''
    # Shared declarations replace both the former file-scope and target-local
    # selector declarations, as well as the other direct menu caller copies.
    for caller in CALLERS:
        text = caller.read_text(encoding="utf-8")
        if '#include "sdk_lbox_internal.h"' not in text:
            raise AssertionError(f"{caller}: shared menu header missing")
        for name in SHARED_MENU:
            if declarations(text, name):
                raise AssertionError(f"{caller}: local {name} declaration overrides shared contract")
    for name, provider in providers.items():
        expected = INTERFACES[name]
        if name not in SHARED_MENU and name != "func_00450340":
            declaration_owner = DECLARATION_OWNERS.get(name, owner)
            found = declarations(declaration_owner.read_text(encoding="utf-8"), name)
            count = 2 if name == "func_001582f0" else 1
            if len(found) != count:
                raise AssertionError(f"{name}: expected {count} caller declarations")
            for index, declaration in enumerate(found):
                alias = f"declaration_{name}_{index}"
                source += re.sub(r"\b" + name + r"\b", alias, declaration) + "\n"
                source += type_check(alias, expected, f"{name}: incompatible caller declaration {index}")
            source += found[0] + "\n"
        source += type_check(name, expected, f"{name}: incompatible caller/header declaration")
        body = Q.function_bodies(provider)[name][1]
        code = "\n".join(V.sanitize_c_lines(body.splitlines()))
        opening = code.find("{")
        if opening < 0:
            raise AssertionError(f"{name}: provider definition has no opening brace")
        signature = body[:opening].strip()
        source += f"#define {name} definition_{name}\n{signature};\n#undef {name}\n"
        source += type_check("definition_" + name, expected, f"{name}: incompatible provider definition")
    return source + "int main(void) { return 0; }\n" + ENTRY_C


class MapTestContractTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_map_menus_grid_and_callback_mutations(self) -> None:
        for name, path in (("func_0018e810", OWNER),
                           ("func_00470250", PROVIDERS["func_00470250"]),
                           ("func_00470430", PROVIDERS["func_00470430"])):
            marker = next(row for row in V.scan_markers(path) if row["name"] == name)
            self.assertFalse(marker.get("asm"), f"{name} must be the active C definition")
        with fixture_directory("runtime") as directory:
            fixture = directory / "fixture.c"
            fixture.write_text(map_fixture(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(fixture, directory / ("fixture" + level), level, INCLUDES)
                    ran = self.runtime.run(executable)
                    self.assertEqual(ran.returncode, 0, ran.stdout + ran.stderr)
                    self.assertEqual(ran.stdout, "map_test_cases=164 menus=45 draws=1922 menu_provider_cases=6\n")
                    print(level, "map-test", ran.stdout.strip())

    def test_map_menu_render_and_provider_contracts(self) -> None:
        with fixture_directory("signatures") as directory:
            fixture = directory / "signatures.c"
            fixture.write_text(signature_fixture(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(fixture, directory / ("signatures" + level), level, INCLUDES)
                    ran = self.runtime.run(executable)
                    self.assertEqual(ran.returncode, 0, ran.stdout + ran.stderr)


if __name__ == "__main__":
    unittest.main()
