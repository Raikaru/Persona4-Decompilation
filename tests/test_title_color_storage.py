"""Actual title-controller color declarations, clear/copy blocks and providers."""
from pathlib import Path
import re
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import measure_guarded
import probe_variants
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

OWNER = ROOT / "src/promoted/code1_0012.c"
FIXTURE = Path(__file__).with_name("title_color_storage_fixture.c.in")
COLORS = ("layerColor", "layerColorSource", "firstOverlayColor", "firstOverlaySource")


def source_parts():
    source = OWNER.read_text()
    body = measure_guarded.extract_guarded_body(source, "FUN_001265A0", "func_001265a0")
    declarations = {}
    for name in (*COLORS, "layerClearByte", "overlayClearByte", "layerClearCount", "overlayClearCount",
                 "sp4A0", "sp4B0", "sp4C0"):
        declarations[name] = re.search(r"^\s+(\w+ \*?" + name + r";)", body, re.M).group(1)
    layer = body[body.index("layerClearByte ="):body.index("            func_00126090(0xFF, temp_20, 0, 0, 0);")]
    overlay_start = body.index("overlayClearByte =")
    overlay_end = body.index(";", body.index("titleRectangle(", overlay_start)) + 1
    overlay = body[overlay_start:overlay_end]
    helpers = source[source.index("typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;"):source.index("static inline f32 titleBlend")]
    provider_source = (ROOT / "src/Main/titleVisual.c").read_text()
    start, end = probe_variants.region_for(provider_source, "FUN_002AAF20", "func_002aaf20")
    provider = provider_source[start:end]
    copies = "\n".join(re.findall(r"titleCopyValue\([^;]+;", layer + overlay))
    if len(re.findall(r"titleCopyValue\(", copies)) != 2:
        raise AssertionError("Expected exactly the two actual color value copies")
    # Guard each extracted color declaration independently. Macros redirect its
    # name to that exact typed member; the tested statements are not rewritten.
    guards = "\n".join("struct { u8 before[16]; " + declarations[name] + " u8 after[16]; } guard_" + name + ";" for name in COLORS)
    aliases = "\n".join(f"#define {name} guard_{name}.{name}" for name in COLORS)
    unalias = "\n".join(f"#undef {name}" for name in COLORS)
    locals_ = "\n".join(value for name, value in declarations.items() if name not in COLORS)
    setup = "\n".join(f"memset(&guard_{name}, 0xA5, sizeof(guard_{name})); memcpy(&{name}, &word, 4); colors[{i}] = (u8 *)&{name}; CHECK(sizeof({name}) == 4);" for i, name in enumerate(COLORS))
    checks = "\n".join(f"for (u32 i = 0; i < 16; ++i) {{ CHECK(guard_{name}.before[i] == 0xA5); CHECK(guard_{name}.after[i] == 0xA5); }}" for name in COLORS)
    result = FIXTURE.read_text()
    for key, value in {"HELPERS": helpers, "PROVIDER": provider, "GUARDS": guards, "ALIASES": aliases,
                       "UNALIAS": unalias, "LOCALS": locals_, "SETUP": setup, "GUARD_CHECKS": checks,
                       "COPIES": copies, "LAYER": layer, "OVERLAY": overlay}.items():
        result = result.replace("@" + key + "@", value)
    return result


class TitleColorStorage(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, optimization, mutation=None):
        text = source_parts()
        if mutation:
            for old, new in mutation:
                self.assertIn(old, text)
                text = text.replace(old, new)
        with tempfile.TemporaryDirectory(prefix="p4_title_color_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + text + ENTRY_C)
            binary = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(binary)

    def test_actual_color_storage_and_copy_lifetimes(self):
        for optimization in ("-O0", "-O2"):
            with self.subTest(optimization=optimization):
                result = self.execute(optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "title_color_cases=4128\n")
                print(optimization, result.stdout.strip())

    def test_layer_declaration_matches_actual_provider(self):
        text = source_parts()
        provider = (ROOT / "src/promoted/code1_0045.c").read_text()
        declaration = re.search(r"extern void func_0045d6e0\(([^;]+)\);", text).group(1)
        definition = re.search(r"void func_0045d6e0\(([^)]+)\)", provider).group(1)
        def types(params):
            return [re.sub(r"(?<=[\s*])[A-Za-z_]\w*$", "", p.strip()).replace(" ", "") for p in params.split(",")]
        self.assertEqual(types(declaration), types(definition))
        self.assertNotIn("func_00126090(", text)

    def test_rejects_wide_clear_wrong_byte_and_copy_regressions(self):
        mutations = {
            "old-layer-wide-clear": (("u8 *layerClearByte;", "s32 *layerClearByte;"),
                                     ("layerClearByte = layerColorSource.bytes;", "layerClearByte = (s32 *)layerColorSource.bytes;")),
            "old-overlay-wide-clear": (("u8 *overlayClearByte;", "f32 *overlayClearByte;"),
                                       ("overlayClearByte = firstOverlaySource.bytes;", "overlayClearByte = (f32 *)firstOverlaySource.bytes;")),
            "wrong-layer-depth": (("(f32 *)&sp4C0, 0.0f, 1)", "(f32 *)&sp4C0, 1.0f, 1)"),),
            "wrong-layer-state-flag": (("(f32 *)&sp4C0, 0.0f, 1)", "(f32 *)&sp4C0, 0.0f, 0)"),),
            "wrong-alpha-byte": (("layerColorSource.bytes[3] = 0xFF;", "layerColorSource.bytes[0] = 0xFF;"),),
            "short-clear": (("overlayClearCount = 4;", "overlayClearCount = 3;"),),
            "numeric-copy": (("*(TitleDrawColor *)destination = *(const TitleDrawColor *)source;",
                              "((TitleDrawColor *)destination)->value = (f32)*(const s32 *)source;"),),
            "short-copy": (("*(TitleDrawColor *)destination = *(const TitleDrawColor *)source;",
                            "for (s32 i = 0; i < 3; ++i) destination[i] = source[i];"),),
            "aliased-layer-source": (("func_0045d6e0((u8 *)&layerColor, (f32 *)&sp4C0, 0.0f, 1);", "func_0045d6e0((u8 *)&layerColorSource, (f32 *)&sp4C0, 0.0f, 1);"),),
            "recopy-after-opaque-call": (("sp4A0 = D_005E55A0.bits;", "titleCopyValue((u8 *)&layerColor, (const u8 *)&layerColorSource); sp4A0 = D_005E55A0.bits;"),),
            "wrong-overlay-source": (("titleCopyValue((u8 *)&firstOverlayColor, (const u8 *)&firstOverlaySource);",
                                      "titleCopyValue((u8 *)&firstOverlayColor, (const u8 *)&layerColorSource);"),),
        }
        for name, mutation in mutations.items():
            for optimization in ("-O0", "-O2"):
                with self.subTest(mutation=name, optimization=optimization):
                    result = self.execute(optimization, mutation)
                    self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)


if __name__ == "__main__":
    unittest.main()
