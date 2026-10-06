"""Exercise choice-window callback ordering and signed counter boundaries.

The fixture compiles the actual guarded controller with 32-bit pointers. It
checks readiness, complete work clearing and counter changes made by callees;
it does not claim complete-controller or PS2 floating-point equivalence.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from measure_guarded import extract_guarded_body

OWNER = ROOT / "src/promoted/itfMsgProcedure_Window.c"
FIXTURE = ROOT / "tests/message_choice_fixture.c.in"


def fixture_source(mutation=None):
    source = OWNER.read_text(encoding="utf-8")
    body = extract_guarded_body(source, "FUN_00282250", "func_00282250")
    prefix = source[:source.index("// FUN_0027CAE0")]
    prefix = prefix.replace("extern s32 memset(void *a0, s32 a1, s32 a2);", "")
    start = source.index("static inline s32 msgWinReady(void)")
    helper = source[start:source.index("\n}\n", start) + 3]
    if mutation == "stale_counter":
        start = body.index("    case 13:")
        stop = body.index("    case 16:", start)
        closing = body[start:stop]
        assert closing.count("        s32 tmp;") == 1
        closing = closing.replace("        s32 tmp;", "        s32 tmp;\n        s32 staleCounter;")
        assert closing.count("D_00882066[0]++;") == 1
        closing = closing.replace("D_00882066[0]++;", "D_00882066[0]++; staleCounter = D_00882066[0];")
        assert closing.count("if (D_00882066[0] <= total)") == 1
        closing = closing.replace("if (D_00882066[0] <= total)", "if (staleCounter <= total)")
        body = body[:start] + closing + body[stop:]
    elif mutation == "partial_ready":
        before = "iGpffffb4d8 != 0 && iGpffffb4dc != 0"
        assert helper.count(before) == 1
        helper = helper.replace(before, "iGpffffb4d8 != 0 || iGpffffb4dc != 0")
    elif mutation == "partial_clear":
        before = "memset(D_00882060, 0, 0x18);"
        assert body.count(before) == 1
        body = body.replace(before, "memset(D_00882060, 0, 0x10);")
    elif mutation is not None:
        raise ValueError(mutation)
    signatures = {
        m.group(2): m.group(0).strip().removeprefix("extern ").removesuffix(";")
        for m in re.finditer(
            r"^(?:extern )?([A-Za-z0-9_ *]+)\b(func_[0-9a-f]+|sinf|cosf)\(([^;{}]*)\);",
            prefix, re.M)
    }
    mocked = {"func_00282250", "func_00278110", "func_00278170", "func_0027bec0",
              "func_00277070", "func_00279010", "func_00278fb0", "func_00278ff0",
              "func_00366380", "func_0025ec90", "func_0025ecd0", "sinf"}
    referenced = set(re.findall(r"\b(func_[0-9a-f]+|sinf|cosf)\b", body))
    stubs = "\n".join(
        declaration + ' { native32_failure(__LINE__, 0, "unexpected ' + name + '"); }'
        for name, declaration in signatures.items() if name in referenced and name not in mocked
    )
    fixture = FIXTURE.read_text(encoding="utf-8")
    before, after = fixture.split("/* INSERT_CONTROLLER */")
    return RUNTIME_C + prefix + before + helper + "\n" + body + "\n" + stubs + after + ENTRY_C


class MessageChoiceRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_message_choice_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(mutation), encoding="utf-8")
            for level in ("-O0", "-O2"):
                executable = self.runtime.compile(source, directory / ("fixture" + level), level, (ROOT / "include",))
                result = self.runtime.run(executable)
                if mutation is None:
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "message-choice contracts passed\n")
                else:
                    self.assertNotEqual(result.returncode, 0, "Negative control was not rejected")

    def test_actual_choice_controller_boundaries(self):
        self.run_fixture()

    def test_getter_counter_change_is_observed(self):
        self.run_fixture("stale_counter")

    def test_both_resources_are_required(self):
        self.run_fixture("partial_ready")

    def test_entire_work_object_is_cleared(self):
        self.run_fixture("partial_clear")


if __name__ == "__main__":
    unittest.main()
