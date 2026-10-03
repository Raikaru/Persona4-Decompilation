"""Exercise the largest title controller's actual overlay calls and provider."""
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
PROVIDER = ROOT / "src/Main/titleVisual.c"
FIXTURE = Path(__file__).with_name("title_overlay_fixture.c.in")


def source_parts():
    text = OWNER.read_text()
    guarded = measure_guarded.extract_guarded_body(text, "FUN_001265A0", "func_001265a0")
    calls = re.findall(r"\btitleRectangle\([^;]+\);", guarded)
    if len(calls) != 14:
        raise AssertionError(f"Expected all 14 retail overlay calls, found {len(calls)}")
    # Preserve each real color object's declared storage type and the complete
    # actual call expression. Only the surrounding controller is not executed.
    sites = []
    for call in calls:
        color = re.search(r"&(?P<name>[A-Za-z_]\w*)", call).group("name")
        declaration = re.search(r"^\s+(\w+) " + color + r";", guarded, re.M).group(0).strip()
        sites.append((declaration, color, call))
    sibling_start, sibling_end = probe_variants.region_for(text, "FUN_00126090", "func_00126090")
    sibling = text[sibling_start:sibling_end]
    sibling_call = re.findall(r"\btitleRectangle\([^;]+\);", sibling)
    if len(sibling_call) != 1:
        raise AssertionError("Expected the one matching ring-controller overlay call")
    sites.append(("TitleColor fillColor;", "fillColor", sibling_call[0]))
    helper = re.search(r"static inline void titleRectangle\([^\n]+\)\n\{.*?\n\}", text, re.S).group(0)
    color_type = re.search(r"typedef union \{ f32 value; u8 bytes\[4\]; \} TitleDrawColor;", text).group(0)
    helper = color_type + "\n" + helper
    provider_text = PROVIDER.read_text()
    start, end = probe_variants.region_for(provider_text, "FUN_002AAF20", "func_002aaf20")
    provider = provider_text[start:end]
    dispatch = []
    for index, (declaration, color, call) in enumerate(sites):
        dispatch.append(f"case {index}: {{ {declaration} prepare_color(&{color}, word); {call} break; }}")
    return helper, provider, "\n".join(dispatch)


class TitleOverlayContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, optimization, mutation=None):
        helper, provider, dispatch = source_parts()
        text = FIXTURE.read_text().replace("@PROVIDER@", provider).replace("@HELPER@", helper).replace("@CALLS@", dispatch)
        if mutation:
            old, new = mutation
            self.assertIn(old, dispatch)
            text = text.replace(old, new)
        with tempfile.TemporaryDirectory(prefix="p4_title_overlay_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + text + ENTRY_C)
            executable = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(executable)

    def test_all_actual_calls_and_actual_packet_provider(self):
        for optimization in ("-O0", "-O2"):
            with self.subTest(optimization=optimization):
                result = self.execute(optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "title_overlay_cases=30720\n")
                print(optimization, result.stdout.strip())

    def test_fixture_rejects_transport_regressions(self):
        for name, old, new in (
            ("depth", "(f32) 0xFFFF", "0.0f"),
            ("width-as-integer-bits", "640.0f", "0x44200000"),
            ("height", "448.0f", "480.0f"),
            ("flags", "0x12, NULL", "0, NULL"),
            ("deferred-parent", "0x12, NULL", "0x12, parentStorage"),
        ):
            with self.subTest(mutation=name):
                result = self.execute("-O2", (old, new))
                self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                self.assertIn("scenario", result.stdout)

    def test_provider_and_adapter_declarations_agree(self):
        helper, provider, _ = source_parts()
        declaration = re.search(r"extern void func_002aaf20\(([^;]+)\);", helper).group(1)
        definition = re.search(r"void func_002aaf20\(([^)]+)\)", provider).group(1)
        def types(params):
            return [re.sub(r"(?<=[\s*])[A-Za-z_]\w*$", "", p.strip()).replace(" ", "") for p in params.split(",")]
        self.assertEqual(types(declaration), types(definition))
        self.assertNotIn("extern void func_002aaf20();", OWNER.read_text())


if __name__ == "__main__":
    unittest.main()
